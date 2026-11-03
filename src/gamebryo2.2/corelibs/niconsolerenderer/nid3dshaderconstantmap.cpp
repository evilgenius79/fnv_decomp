
#include "nid3dshaderconstantmap_decls.h"
// @fnv 0x00e87200
void NiD3DShaderConstantMap::ResetShaderConstantMap()
{
    ClearShaderConstantEntries(&entries);
    ClearShaderConstantEntries(&defined);
}
// @fnv 0x00b71a40
void BuildTransformMatrix(float* afOutMatrix, const ThreeByThreeMatrix& r, const NiPoint3& atTranslation, float afScale)
{
    afOutMatrix[0] = r.m[0][0] * afScale;
    afOutMatrix[1] = r.m[1][0] * afScale;
    afOutMatrix[2] = r.m[2][0] * afScale;
    afOutMatrix[3] = 0;
    afOutMatrix[4] = r.m[0][1] * afScale;
    afOutMatrix[5] = r.m[1][1] * afScale;
    afOutMatrix[6] = r.m[2][1] * afScale;
    afOutMatrix[7] = 0;
    afOutMatrix[8] = r.m[0][2] * afScale;
    afOutMatrix[9] = r.m[1][2] * afScale;
    afOutMatrix[10] = r.m[2][2] * afScale;
    afOutMatrix[11] = 0;
    afOutMatrix[12] = atTranslation.x - DAT_011f474c.x;
    afOutMatrix[13] = atTranslation.y - DAT_011f474c.y;
    afOutMatrix[14] = atTranslation.z - DAT_011f474c.z;
    afOutMatrix[15] = 1;
}

// @fnv 0x00e826d0
unsigned int NiD3DShaderConstantMap::ConfigureShaderConstantMap(
    NiD3DShaderProgram* program, NiGeometry* geometry, const NiSkinInstance* skin,
    const NiSkinPartition::Partition* partition, NiGeometryBufferData* buffer, const NiPropertyState* property,
    const NiDynamicEffectState* effects, const NiTransform& transform, const NiBound& bound, unsigned int pass,
    bool global)
{
    last = program;
    bool success = true;
    unsigned int n = defined.size;
    for (unsigned int i = 0; i < n;)
    {
        NiShaderConstantMapEntry* e = defined.GetAt(i++);
        if (!e || !e->enabled || (e->index == ~0u && !e->extra))
            continue;
        if ((e->flags & 0xf0000000) == 0x20000000 &&
            vfn_8c(program, e, geometry, skin, partition, buffer, property, effects, transform, bound, pass))
            success = false;
    }
    unsigned int uiEntryCount = entries.size;
    for (unsigned int i = 0; i < uiEntryCount;)
    {
        NiShaderConstantMapEntry* e = entries.GetAt(i++);
        if (!e || !e->enabled)
            continue;
        unsigned int index = e->index;
        if (index == ~0u && !e->extra)
            continue;
        unsigned int kind = e->flags & 0xf0000000;
        if (kind == 0x20000000)
            continue;
        unsigned int result;
        if (kind == 0x10000000)
        {
            if (e->type == 1)
            {
                unsigned int count = e->registers;
                const float* data = e->data;
                result = device->UploadVertex(index, data, count);
            }
            else if (e->type == 2)
            {
                unsigned int count = e->registers;
                const float* data = e->data;
                result = device->UploadPixel(index, data, count);
            }
            else
                result = vfn_90(program, e, pass);
        }
        else if (kind == 0x30000000)
            result = vfn_94(program, e, geometry, skin, partition, buffer, property, effects, transform, bound, pass,
                            global, 0);
        else if (kind == 0x40000000)
            result = vfn_98(program, e, pass);
        else if (kind == 0x50000000)
            result = vfn_9c(program, e, geometry, skin, property, effects, transform, bound, pass);
        else if (kind == 0x60000000)
            result = vfn_a4(program, e, geometry, skin, partition, buffer, property, effects, transform, bound, pass);
        else
        {
            success = false;
            continue;
        }
        if (result)
            success = false;
    }
    return success ? 0 : 1;
}

struct NiShaderConstantMap
{
    static bool __cdecl FindConstantMapping(char const*, unsigned int&, unsigned int&);
};
unsigned int __cdecl FUN_00a9bbf0(unsigned int, unsigned int);
// @fnv 0x00a9c0a0
unsigned int __cdecl FUN_00a9c0a0(const char* name)
{
    unsigned int a, b;
    if (NiShaderConstantMap::FindConstantMapping(name, a, b) && a)
        return FUN_00a9bbf0(a, b);
    return 0;
}

struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_0126f7c4;
// @fnv 0x00b7e400
GlobalObjectO2_00a7b610* __cdecl FUN_00b7e400()
{
    return &g_0126f7c4;
}

void __fastcall UpdateMatrix(void*);
// @fnv 0x00bc5c20
char* __fastcall FUN_00bc5c20(char* self)
{
    if (self[0x1c])
        UpdateMatrix(self);
    return self + 0x20;
}

// @fnv 0x00e826c0
void* __fastcall FUN_00e826c0(char* self, int unused, unsigned int i)
{
    return (*(void***)(self + 0x10))[i];
}

struct FUN_00e82ac0_e
{
    char pad[0xc];
    unsigned int key;
    void* p10;
    unsigned int flags;
    char pad2[8];
    unsigned int v20;
};
extern unsigned char DAT_011f5fb4[];
bool __cdecl LookupShaderConstantMapping(unsigned int, void*&);
unsigned int __cdecl GetAttributeTypeForMapping(void*, unsigned int*, unsigned int*);
// Looks up the entry's key, stores a byte from DAT_011f5fb4 indexed by the result into flags, and on success stores the pointer and y into p10 and v20.
// @fnv 0x00e82ac0
unsigned int __stdcall UpdateEntryFromKey(FUN_00e82ac0_e* pEntry)
{
    void* x;
    unsigned int uiKey = pEntry->key;
    unsigned int y = 0;
    unsigned int z;
    if (LookupShaderConstantMapping(uiKey, x))
    {
        unsigned int idx = GetAttributeTypeForMapping(x, &y, &z);
        pEntry->flags = (pEntry->flags & 0xffffff00) | DAT_011f5fb4[idx];
        if (x)
        {
            pEntry->p10 = x;
            pEntry->v20 = y;
            return 0;
        }
    }
    return 0x40;
}

void __fastcall FUN_00e81c00(void*);
void __cdecl __Dummy_00b6fef0(void*, unsigned int);
// @fnv 0x00e83630
void* __fastcall FUN_00e83630(void* self, int unused, unsigned int flags)
{
    FUN_00e81c00(self);
    if (flags & 1)
        __Dummy_00b6fef0(self, 0x38);
    return self;
}

struct FUN_00e84b60_prog
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual bool SetConstant(void* entry, const void* data, unsigned int n);
};
const void* __stdcall GetConstantData(void*);
// Looks up data for entry via GetConstantData and, if found, calls prog->SetConstant with it, returning 0 on success, 1 if no data, or 0x50 on failure.
// @fnv 0x00e84b60
unsigned int __stdcall FUN_00e84b60(FUN_00e84b60_prog* prog, void* entry, unsigned int pass)
{
    const void* pvData = GetConstantData(entry);
    if (!pvData)
        return 1;
    return prog->SetConstant(entry, pvData, 0) ? 0 : 0x50;
}

extern char* EmptyFS;
struct RMapEntry
{
    char pad[0xc];
    char* key;
    unsigned int pad3;
    unsigned int flags;
};
struct RMap
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual unsigned int LookupSequenceByKey(const char*);
    char pad[0xc];
    RMapEntry** entries;
    char pad2[0x20];
    volatile unsigned int status;
};
void __cdecl RemoveGlobalConstant(char**);
struct RArr
{
    void FUN_00e86f40(unsigned int, void*);
};
// @fnv 0x00e87010
unsigned int __fastcall LookupAndReleaseEntry(RMap* self, int unused, const char* name)
{
    unsigned int idx = self->LookupSequenceByKey(name);
    if (idx != 0xFFFFFFFF)
    {
        char* pKey;
        RMapEntry* e = self->entries[idx];
        if (e && (e->flags & 0xf0000000) == 0x40000000)
        {
            if (e->key != EmptyFS)
                InterlockedIncrement((long*)(e->key - 8));
            pKey = e->key;
            RemoveGlobalConstant(&pKey);
            if (pKey != EmptyFS)
                InterlockedDecrement((long*)(pKey - 8));
        }
        pKey = 0;
        ((RArr*)((char*)self + 0xc))->FUN_00e86f40(idx, &pKey);
        return self->status;
    }
    self->status = 0x10;
    return self->status;
}

// @fnv 0x00a9bbf0
unsigned int __cdecl FUN_00a9bbf0(unsigned int aiCode, unsigned int b)
{
    switch (aiCode)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 0xb:
    case 0xc:
    case 0xd:
    case 0xe:
    case 0xf:
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x13:
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x17:
    case 0x18:
    case 0x25:
    case 0x26:
    case 0x27:
    case 0x28:
    case 0x29:
    case 0x2a:
    case 0x2b:
    case 0x2c:
    case 0x2d:
    case 0x2e:
    case 0x2f:
    case 0x30:
    case 0x31:
    case 0x32:
    case 0x33:
    case 0x34:
    case 0x35:
    case 0x36:
    case 0x37:
    case 0x38:
    case 0x39:
    case 0x3a:
    case 0x3b:
    case 0x3c:
    case 0x3d:
    case 0x3e:
    case 0x3f:
    case 0x40:
    case 0x41:
    case 0x42:
    case 0x43:
    case 0x44:
    case 0x58:
    case 0x59:
    case 0x5a:
    case 0x5b:
    case 0x5c:
    case 0x5d:
    case 0x5e:
    case 0x5f:
        return (b != 3) + 8;
    case 0x19:
    case 0x1a:
    case 0x1b:
    case 0x1c:
    case 0x1d:
    case 0x1e:
    case 0x1f:
    case 0x20:
    case 0x22:
    case 0x24:
    case 0x60:
    case 0x61:
    case 0x62:
    case 99:
        return 9;
    case 0x21:
    case 0x23:
        return 8;
    case 0x45:
    case 0x46:
    case 0x47:
    case 0x48:
    case 0x49:
    case 0x4a:
    case 0x4b:
    case 0x4c:
    case 0x4d:
    case 0x4e:
    case 0x4f:
    case 0x50:
    case 0x51:
    case 0x52:
    case 0x53:
    case 0x54:
    case 0x55:
    case 0x56:
    case 0x57:
    case 100:
    case 0x65:
    case 0x66:
    case 0x67:
        return 7;
    case 0x69:
        return 4;
    case 0x68:
    case 0x6a:
    case 0x6b:
    case 0x6c:
    case 0x6d:
    case 0x6e:
    case 0x6f:
    case 0x70:
    case 0x71:
    case 0x72:
    case 0x73:
        return 5;
    default:
        return 0;
    }
}

extern long DAT_011f4400;
struct FUN_00a9beb0
{
    unsigned int a, b;
    virtual ~FUN_00a9beb0();
    static void operator delete(void* p, unsigned int n);
};
// @fnv 0x00a9beb0
FUN_00a9beb0::~FUN_00a9beb0()
{
    InterlockedDecrement(&DAT_011f4400);
}

extern "C" char DAT_010f003c;
struct ShaderMapBase
{
    virtual void BaseVirtual();
    unsigned int unk04, unk08;
    ShaderMapBase(unsigned int);
    ~ShaderMapBase();
};
struct ShaderMapArray
{
    void* vtable;
    void* entries;
    unsigned short capacity, size, count, grow;
    __forceinline ShaderMapArray() : grow(1), capacity(0)
    {
        size = 0;
        count = 0;
        entries = 0;
        vtable = &DAT_010f003c;
    }
    ~ShaderMapArray();
    void FUN_00b799c0();
};
struct FUN_00b7e330 : ShaderMapBase
{
    ShaderMapArray activeEntries, definedEntries;
    unsigned char enabled, unk2d, unk2e, unk2f;
    unsigned int unk30, unk34, unk38, unk3c, unk40;
    FUN_00b7e330(unsigned int, unsigned int);
    void FUN_00e81d00(unsigned int);
    virtual void MapVirtual();
};
// Constructs a shader map by initializing base state, calling FUN_00e81d00 with mapId, and preparing activeEntries.
// @fnv 0x00b7e330
FUN_00b7e330::FUN_00b7e330(unsigned int mapId, unsigned int initMode)
    : ShaderMapBase(initMode), activeEntries(), definedEntries(), unk30(0), unk34(0), unk38(0), unk3c(0), unk40(0)
{
    enabled = 1;
    FUN_00e81d00(mapId);
    activeEntries.FUN_00b799c0();
}

extern unsigned int DAT_011f5f90[];
struct EntrySI
{
    char _p[0x18];
    unsigned int m_uiValue2;
};
struct FUN_00e81d70_t
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual unsigned int AddDefinedEntry(const char*, unsigned int, unsigned int, unsigned int, unsigned int,
                                         const char*, unsigned int, unsigned int, const void*, bool);
    virtual unsigned int AddDynamicEntry(const char*, unsigned int, unsigned int, unsigned int, unsigned int,
                                         const char*, unsigned int, unsigned int, const void*, bool);
    virtual unsigned int AddUserDefinedEntry(const char*, unsigned int, unsigned int, unsigned int, unsigned int,
                                             const char*, unsigned int, unsigned int, const void*, bool);
    virtual unsigned int AddRegisterEntry(const char*, unsigned int, unsigned int, unsigned int, unsigned int,
                                          const char*);
    virtual unsigned int AddNamedRegisterEntry(const char*, unsigned int, const char*, unsigned int, unsigned int);
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual unsigned int AddShaderEntry(const char*, unsigned int, unsigned int, const char*, unsigned int,
                                        unsigned int, unsigned int, unsigned int);
    virtual void v27();
    virtual EntrySI* GetEntry(const char*);
    char _p[0x30];
    unsigned int m_uiErrorCode;
    unsigned int FUN_00e81d70(const char* pszKey, unsigned int uiFlags, unsigned int uiExtra,
                              unsigned int uiShaderRegister, unsigned int uiRegisterCount, const char* pszVariableName,
                              unsigned int uiConstantDataSize, unsigned int uiDataStride, const void* pvDataSource,
                              bool bCopyData);
};

// @fnv 0x00e81d70
unsigned int FUN_00e81d70_t::FUN_00e81d70(const char* pszKey, unsigned int uiFlags, unsigned int uiExtra,
                                          unsigned int uiShaderRegister, unsigned int uiRegisterCount,
                                          const char* pszVariableName, unsigned int uiConstantDataSize,
                                          unsigned int uiDataStride, const void* pvDataSource, bool bCopyData)
{
    m_uiErrorCode = 0;
    EntrySI* pkEntry = GetEntry(pszKey);
    if (pkEntry && pkEntry->m_uiValue2 == uiExtra)
    {
        m_uiErrorCode = 0x20;
        return 0x20;
    }
    unsigned int uiType = uiFlags & 0xf0000000;
    if (uiType == 0x30000000)
        m_uiErrorCode = AddDefinedEntry(pszKey, uiFlags, uiExtra, uiShaderRegister, uiRegisterCount, pszVariableName,
                                        uiConstantDataSize, uiDataStride, pvDataSource, bCopyData);
    else if (uiType == 0x10000000)
        m_uiErrorCode = AddDynamicEntry(pszKey, uiFlags, uiExtra, uiShaderRegister, uiRegisterCount, pszVariableName,
                                        uiConstantDataSize, uiDataStride, pvDataSource, bCopyData);
    else if (uiType == 0x20000000)
        m_uiErrorCode = AddShaderEntry(pszKey, uiExtra, uiShaderRegister, pszVariableName, 0, 0, 0, 0);
    else if (uiType == 0x40000000)
        m_uiErrorCode = AddUserDefinedEntry(pszKey, uiFlags, uiExtra, uiShaderRegister, uiRegisterCount,
                                            pszVariableName, uiConstantDataSize, uiDataStride, pvDataSource, bCopyData);
    else if (uiType == 0x50000000)
        m_uiErrorCode = AddRegisterEntry(pszKey, uiFlags, uiExtra, uiShaderRegister, uiRegisterCount, pszVariableName);
    else if (uiType == 0x60000000)
    {
        unsigned int eObjectType = DAT_011f5f90[(uiFlags >> 8) & 0xff];
        m_uiErrorCode = AddNamedRegisterEntry(pszKey, uiShaderRegister, pszVariableName, uiExtra, eObjectType);
    }
    else
        m_uiErrorCode = 0x40;
    return m_uiErrorCode;
}

struct FUN_00e81f10_shell : public NiD3DShaderConstantMap
{
    unsigned int FUN_00e81f10(char*, unsigned int, unsigned int, char*, unsigned int, unsigned int, void*, bool);
};

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};
struct CtorShim
{
    NiShaderConstantMapEntry* FormHeap_Allocate();
};
struct NiGlobalStringTable
{
    static char* __cdecl AddString(char const*);
};
void* __cdecl _NiMalloc(unsigned int);
void __cdecl _NiFree(void*);
void* __cdecl _memmove(void*, const void*, unsigned int);

struct FixStr
{
    char* h;
    FixStr(const char* s)
    {
        if (s == 0)
            h = EmptyFS;
        else
            h = NiGlobalStringTable::AddString(s);
    }
    ~FixStr()
    {
        if (h != EmptyFS)
            InterlockedDecrement((long*)(h - 8));
    }
    FixStr& operator=(const FixStr& o)
    {
        if (h != o.h)
        {
            if (o.h != EmptyFS)
                InterlockedIncrement((long*)(o.h - 8));
            if (h != EmptyFS)
                InterlockedDecrement((long*)(h - 8));
            h = o.h;
        }
        return *this;
    }
};

struct EntryLayout
{
    void* vt;
    unsigned int refs;
    unsigned int pad8;
    FixStr m_kControlPoint;  // 0c
    unsigned int pad10;
    unsigned int m_uiValue1;  // 14
    unsigned int m_uiValue2;  // 18
    unsigned int m_uiValue3;  // 1c
    unsigned int pad20;
    FixStr m_kSecondaryString;  // 24
    unsigned int m_uiValue5;    // 28
    unsigned int m_uiValue6;    // 2c
    void* m_pConstantData;      // 30
    bool m_bFlag0;              // 34
};

// Allocates and fills an entry, copies or references constant data, then passes it to a virtual call and conditionally another.
// @fnv 0x00e81f10
unsigned int FUN_00e81f10_shell::FUN_00e81f10(char* pszKey, unsigned int uiExtra, unsigned int uiShaderRegister,
                                              char* pszVariableName, unsigned int uiConstantDataSize,
                                              unsigned int uiDataStride, void* pvDataSource, bool bCopyData)
{
    void* mem = BSFadeNode::operator new(0x38);
    NiShaderConstantMapEntry* pkEntry = mem ? ((CtorShim*)mem)->FormHeap_Allocate() : 0;
    EntryLayout* e = (EntryLayout*)pkEntry;
    e->m_kControlPoint = pszKey;
    e->m_uiValue2 = uiExtra;
    e->m_uiValue3 = uiShaderRegister;
    e->m_kSecondaryString = pszVariableName;
    e->m_uiValue5 = uiConstantDataSize;
    e->m_uiValue6 = uiDataStride;
    if (bCopyData)
    {
        e->m_bFlag0 = true;
        _NiFree(e->m_pConstantData);
        e->m_pConstantData = _NiMalloc(uiConstantDataSize);
        _memmove(e->m_pConstantData, pvDataSource, uiConstantDataSize);
    }
    else
    {
        e->m_bFlag0 = false;
        e->m_pConstantData = pvDataSource;
    }
    e->m_uiValue1 = 0x20000000;
    typedef unsigned int(__thiscall * Fn)(void*, NiShaderConstantMapEntry*);
    unsigned int* self = (unsigned int*)this;
    self[0x34 / 4] = ((Fn)(*(void***)this)[0x88 / 4])(this, pkEntry);
    if (self[0x34 / 4] == 0)
    {
        self[0x34 / 4] = ((Fn)(*(void***)this)[0x84 / 4])(this, pkEntry);
        return self[0x34 / 4];
    }
    typedef void(__thiscall * Del)(void*, unsigned int);
    ((Del)(*(void***)pkEntry)[0])(pkEntry, 1);
    return self[0x34 / 4];
}

struct FUN_00e82090_shell : public NiD3DShaderConstantMap
{
    unsigned int FUN_00e82090(char*, unsigned int, unsigned int, unsigned int, unsigned int, char*, unsigned int,
                              unsigned int, void*, bool);
};

namespace L {
struct NiShaderConstantMapEntry : BSFadeNode
{
    NiShaderConstantMapEntry() throw();
    virtual void DeleteThis(unsigned int);
    unsigned int m_uiRefCount;
    unsigned int unk08;
    char* m_kControlPoint;
    unsigned int unk10;
    unsigned int m_uiValue1;
    unsigned int m_uiValue2;
    unsigned int m_uiValue3;
    unsigned int m_uiValue4;
    char* m_kSecondaryString;
    unsigned int m_uiValue5;
    unsigned int m_uiValue6;
    void* m_pConstantData;
    bool m_bFlag0;
};
}
struct EntryArrayStand
{
    void* m_vtbl;
    void* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

struct MyCls
{
    void SetBuffer(unsigned int, unsigned int, void*, bool);
};
struct MapStub
{
    virtual void S0();
    virtual void S1();
    virtual void S2();
    virtual void S3();
    virtual void S4();
    virtual void S5();
    virtual void S6();
    virtual void S7();
    virtual void S8();
    virtual void S9();
    virtual void S10();
    virtual void S11();
    virtual void S12();
    virtual void S13();
    virtual void S14();
    virtual void S15();
    virtual void S16();
    virtual void S17();
    virtual void S18();
    virtual void S19();
    virtual void S20();
    virtual void S21();
    virtual void S22();
    virtual void S23();
    virtual void S24();
    virtual void S25();
    virtual void S26();
    virtual void S27();
    virtual void S28();
    virtual void S29();
    virtual void S30();
    virtual void S31();
    virtual unsigned int ReadEntryData(void*);
    unsigned int m_uiRefCount;
    unsigned int unk08;
    EntryArrayStand m_kEntries;
    EntryArrayStand m_kDefinedEntries;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int m_uiErrorCode;
};

struct TmpFixedStr
{
    char* h;
    TmpFixedStr(const char* s)
    {
        if (s == 0)
            h = EmptyFS;
        else
            h = NiGlobalStringTable::AddString(s);
    }
    ~TmpFixedStr()
    {
        if (h != EmptyFS)
            InterlockedDecrement((long*)(h - 8));
    }
};
static __forceinline void AssignFixedStr(char*& dst, const char* s)
{
    TmpFixedStr t(s);
    if (dst != t.h)
    {
        if (t.h != EmptyFS)
            InterlockedIncrement((long*)(t.h - 8));
        if (dst != EmptyFS)
            InterlockedDecrement((long*)(dst - 8));
        dst = t.h;
    }
}

// Creates and populates an entry, optionally sets its buffer, then passes it to ReadEntryData.
// @fnv 0x00e82090
unsigned int FUN_00e82090_shell::FUN_00e82090(char* pszKey, unsigned int uiFlags, unsigned int uiExtra,
                                              unsigned int uiShaderRegister, unsigned int uiRegisterCount,
                                              char* pszVariableName, unsigned int uiConstantDataSize,
                                              unsigned int uiDataStride, void* pvDataSource, bool bCopyData)
{
    L::NiShaderConstantMapEntry* pkEntry = new L::NiShaderConstantMapEntry;
    AssignFixedStr(pkEntry->m_kControlPoint, pszKey);
    pkEntry->m_uiValue1 = (uiFlags & 0x0fffffff) | 0x30000000;
    pkEntry->m_uiValue2 = uiExtra;
    pkEntry->m_uiValue3 = uiShaderRegister;
    pkEntry->m_uiValue4 = uiRegisterCount;
    AssignFixedStr(pkEntry->m_kSecondaryString, pszVariableName);
    if (pvDataSource)
        ((MyCls*)pkEntry)->SetBuffer(uiConstantDataSize, uiDataStride, pvDataSource, bCopyData);
    MapStub* self = (MapStub*)this;
    self->m_uiErrorCode = self->ReadEntryData(pkEntry);
    if (self->m_uiErrorCode)
        pkEntry->DeleteThis(1);
    return self->m_uiErrorCode;
}

#include <string.h>
struct FUN_00e821e0_shell : public NiD3DShaderConstantMap
{
    unsigned int FUN_00e821e0(char*, unsigned int, unsigned int, unsigned int, unsigned int, char*, unsigned int,
                              unsigned int, void*, bool);
};

struct FixedStrS
{
    char* m_kHandle;
    FixedStrS(const char* pc)
    {
        if (pc == 0)
            m_kHandle = EmptyFS;
        else
            m_kHandle = NiGlobalStringTable::AddString(pc);
    }
    ~FixedStrS()
    {
        if (m_kHandle != EmptyFS)
            InterlockedDecrement((long*)(m_kHandle - 8));
    }
    FixedStrS& operator=(const FixedStrS& o)
    {
        if (m_kHandle != o.m_kHandle)
        {
            if (o.m_kHandle != EmptyFS)
                InterlockedIncrement((long*)(o.m_kHandle - 8));
            if (m_kHandle != EmptyFS)
                InterlockedDecrement((long*)(m_kHandle - 8));
            m_kHandle = o.m_kHandle;
        }
        return *this;
    }
};

void* NiMalloc(unsigned int);
void NiFree(void*);
extern unsigned int DAT_011f5fc4[];
bool __cdecl AcquireGlobalConstantEntry(const FixedStrS&, unsigned int, unsigned int, const void*) throw();

struct ScmEntryS : BSFadeNode
{
    virtual ~ScmEntryS();
    unsigned int m_uiRefCount;
    unsigned int m_pad8;
    FixedStrS m_kControlPoint;
    unsigned int m_pad10;
    unsigned int m_uiValue1;
    unsigned int m_uiValue2;
    unsigned int m_uiValue3;
    unsigned int m_uiValue4;
    FixedStrS m_kSecondaryString;
    unsigned int m_uiValue5;
    unsigned int m_uiValue6;
    void* m_pConstantData;
    bool m_bFlag0;
    ScmEntryS() throw();
    void SetData(unsigned int uiSize, unsigned int uiStride, void* pvSource, bool bCopy)
    {
        m_uiValue5 = uiSize;
        m_uiValue6 = uiStride;
        if (bCopy)
        {
            m_bFlag0 = true;
            NiFree(m_pConstantData);
            m_pConstantData = NiMalloc(uiSize);
            memmove(m_pConstantData, pvSource, uiSize);
        }
        else
        {
            m_bFlag0 = false;
            m_pConstantData = pvSource;
        }
    }
};

struct ScmMapS
{
    virtual void s00();
    virtual void s01();
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void s07();
    virtual void s08();
    virtual void s09();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual unsigned int ReadEntryData(ScmEntryS* pkEntry);
};

// Creates a ScmEntryS from the given key, flags, register and data, reads its entry data, and on success acquires a global constant entry.
// @fnv 0x00e821e0
unsigned int FUN_00e821e0_shell::FUN_00e821e0(char* pszKey, unsigned int uiFlags, unsigned int uiExtra,
                                              unsigned int uiShaderRegister, unsigned int uiRegisterCount,
                                              char* pszVariableName, unsigned int uiConstantDataSize,
                                              unsigned int uiDataStride, void* pvDataSource, bool bCopyData)
{
    ScmEntryS* pkEntry = new ScmEntryS;
    pkEntry->m_kControlPoint = pszKey;
    unsigned int uiEntryFlags = (uiFlags & 0x0fffffff) | 0x40000000;
    pkEntry->m_uiValue1 = uiEntryFlags;
    pkEntry->m_uiValue2 = uiExtra;
    pkEntry->m_uiValue3 = uiShaderRegister;
    pkEntry->m_uiValue4 = uiRegisterCount;
    pkEntry->m_kSecondaryString = pszVariableName;
    pkEntry->SetData(uiConstantDataSize, uiDataStride, pvDataSource, bCopyData);
    unsigned int& m_eErrorCode = *(unsigned int*)((char*)this + 0x34);
    m_eErrorCode = ((ScmMapS*)this)->ReadEntryData(pkEntry);
    if (m_eErrorCode != 0)
    {
        delete pkEntry;
    }
    else
    {
        unsigned int uiConstantType = DAT_011f5fc4[uiEntryFlags & 0xff];
        AcquireGlobalConstantEntry(pszKey, uiConstantType, uiConstantDataSize, pvDataSource);
    }
    return m_eErrorCode;
}

struct FUN_00e823d0_shell : public NiD3DShaderConstantMap
{
    unsigned int FUN_00e823d0(char*, unsigned int, unsigned int, unsigned int, unsigned int, char*);
};

// Creates a ScmEntryS from the given parameters, passes it to ReadEntryData, and returns the resulting error code.
// @fnv 0x00e823d0
unsigned int FUN_00e823d0_shell::FUN_00e823d0(char* pszControlPoint, unsigned int uiFlags, unsigned int uiExtra,
                                              unsigned int uiShaderRegister, unsigned int uiRegisterCount,
                                              char* pszVariableName)
{
    ScmEntryS* pkEntry = new ScmEntryS;
    pkEntry->m_kControlPoint = pszControlPoint;
    pkEntry->m_uiValue1 = (uiFlags & 0x0fffffff) | 0x50000000;
    pkEntry->m_uiValue2 = uiExtra;
    pkEntry->m_uiValue3 = uiShaderRegister;
    pkEntry->m_uiValue4 = uiRegisterCount;
    pkEntry->m_kSecondaryString = pszVariableName;
    unsigned int& m_eErrorCode = *(unsigned int*)((char*)this + 0x34);
    m_eErrorCode = ((ScmMapS*)this)->ReadEntryData(pkEntry);
    if (m_eErrorCode != 0)
        delete pkEntry;
    return m_eErrorCode;
}

extern char* DAT_0109b220;
extern unsigned short DAT_011f5f7c[];

struct String311
{
    char* handle;
    __declspec(nothrow) String311(const char* value) throw()
    {
        if (!value)
            handle = DAT_0109b220;
        else
            handle = NiGlobalStringTable::AddString(value);
    }
    __declspec(nothrow) ~String311() throw()
    {
        if (handle != DAT_0109b220)
            InterlockedDecrement(reinterpret_cast<long*>(handle - 8));
    }
    __declspec(nothrow) String311& operator=(const String311& other) throw()
    {
        if (handle != other.handle)
        {
            if (other.handle != DAT_0109b220)
                InterlockedIncrement(reinterpret_cast<long*>(other.handle - 8));
            if (handle != DAT_0109b220)
                InterlockedDecrement(reinterpret_cast<long*>(handle - 8));
            handle = other.handle;
        }
        return *this;
    }
};
struct Entry311
{
    virtual ~Entry311();
    long refs;
    bool enabled;
    unsigned char unk09, unk0a, unk0b;
    String311 name;
    unsigned int unk10, flags, value, index, unk20;
    String311 alternative;
    unsigned int unk28, unk2c, unk30, unk34;
    __declspec(nothrow) Entry311() throw();
    __declspec(noalias) __declspec(nothrow) static void* operator new(unsigned int) throw();
};
struct Map311
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot0a();
    virtual void slot0b();
    virtual void slot0c();
    virtual void slot0d();
    virtual void slot0e();
    virtual void slot0f();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot1a();
    virtual void slot1b();
    virtual void slot1c();
    virtual void slot1d();
    virtual void slot1e();
    virtual void slot1f();
    virtual unsigned int Add(Entry311*);
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual unsigned int Find(Entry311*);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int error;
    unsigned int AddEntry(const char*, unsigned int, const char*, unsigned int, unsigned int);
};
// Creates and initializes an Entry311, calls Find, and calls Add only when Find returns zero.
// @fnv 0x00e82500
unsigned int Map311::AddEntry(const char* name, unsigned int index, const char* alternative, unsigned int value,
                              unsigned int type)
{
    Entry311* entry = new Entry311;
    entry->name = String311(name);
    entry->index = index;
    entry->alternative = String311(alternative);
    entry->value = value;
    entry->flags = DAT_011f5f7c[type] | 0x60000000;
    error = Find(entry);
    if (!error)
    {
        error = Add(entry);
        return error;
    }
    delete entry;
    return error;
}

struct FUN_00e82640_Entry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

int __cdecl FUN_00aa1360(unsigned int name, int value);

class FUN_00e82640_Obj
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    FUN_00e82640_Entry** unk10;
    unsigned short unk14;
    unsigned short unk16;
    int unk18;
    int unk1C;
    FUN_00e82640_Entry** unk20;
    unsigned short unk24;
    unsigned short unk26;

    FUN_00e82640_Entry* __thiscall FindEntry(unsigned int name);
};

// Searches two entry arrays by name using FUN_00aa1360 and returns the matching entry, or 0 if not found.
// @fnv 0x00e82640
FUN_00e82640_Entry* __thiscall FUN_00e82640_Obj::FindEntry(unsigned int name)
{
    unsigned int count;
    unsigned int index;
    FUN_00e82640_Entry* entry;
    int result;
    int value;

    count = unk26;
    index = 0;
    if (index < count)
    {
        do
        {
            entry = unk20[index];
            if (entry != 0)
            {
                value = entry->unk0C;
                result = FUN_00aa1360(name, value);
                if (result == 0)
                {
                    goto found;
                }
            }
            ++index;
        } while (index < count);
    }

    count = unk16;
    index = 0;
    if (index < count)
    {
        do
        {
            entry = unk10[index];
            if (entry != 0)
            {
                value = entry->unk0C;
                result = FUN_00aa1360(name, value);
                if (result == 0)
                {
                    goto found;
                }
            }
            ++index;
        } while (index < count);
    }

    return 0;
found:
    return entry;
}

struct FUN_00e82960_entry
{
    char unk00[0xc];
    const char* key;
};

unsigned int __cdecl FUN_00aa1360(const char* name, const char* key);

class FUN_00e82960_cls
{
  public:
    char unk00[0x10];
    FUN_00e82960_entry** entries;
    char unk14[2];
    unsigned short count;

    unsigned int FindEntryIndex(const char* name);
};

// @fnv 0x00e82960
unsigned int FUN_00e82960_cls::FindEntryIndex(const char* name)
{
    unsigned int n = count;
    unsigned int i = 0;
    for (i = 0; i < n; i++)
    {
        FUN_00e82960_entry* e = entries[i];
        if (e != 0)
        {
            const char* key = e->key;
            if (FUN_00aa1360(name, key) == 0)
            {
                return i;
            }
        }
    }
    return 0xffffffff;
}

namespace fnv_00e829b0 {
unsigned int __cdecl FUN_00a9bbf0(unsigned int, unsigned int);
extern unsigned char DAT_011f5fb4[];
bool __cdecl LookUpShaderConstantType(unsigned int key, unsigned int* type, unsigned int* count);
extern const unsigned int g_ShaderMatrixDesc0[];
extern const unsigned int g_ShaderMatrixDesc1[];

struct ShaderConstEntry
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int key;
    unsigned int type;
    unsigned int flags;
    unsigned short unk18;
    unsigned short unk1a;
    int unk1c;
    unsigned int dataSize;
    int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    const unsigned int* desc;
    bool unk34;
};

// Looks up the shader constant type for the entry key, sets flags, dataSize, type, and matrix descriptor fields, returning 0 on success or 0x40 on failure.
// @fnv 0x00e829b0
unsigned int __stdcall InitShaderConstantEntry(ShaderConstEntry* apEntry)
{
    unsigned int count = 4;
    unsigned int type;
    unsigned int key = apEntry->key;
    if (!LookUpShaderConstantType(key, &type, &count))
        return 0x40;
    apEntry->flags = (apEntry->flags & 0xffffff00) | DAT_011f5fb4[FUN_00a9bbf0(type, count)];
    if (type == 0)
        return 0x40;
    if (type < 0x45)
    {
        if (type == 0x21 || type == 0x23)
            apEntry->dataSize = apEntry->unk1a * 3;
        else if (type == 0x22 || type == 0x24)
            apEntry->dataSize = apEntry->unk1a * 4;
        else if (type == 0x19 || type == 0x1a || type == 0x1b || type == 0x1c || type == 0x1d || type == 0x1e ||
                 type == 0x1f || type == 0x20 || type == 0x60 || type == 0x61 || type == 0x62 || type == 0x63)
            apEntry->dataSize = 4;
        else
            apEntry->dataSize = count;
    }
    apEntry->type = type;
    switch (type)
    {
    case 0x50:
        apEntry->desc = g_ShaderMatrixDesc0;
        apEntry->unk28 = 0x10;
        apEntry->unk2c = 0x10;
        apEntry->unk34 = false;
        break;
    case 0x51:
        apEntry->desc = g_ShaderMatrixDesc1;
        apEntry->unk28 = 0x10;
        apEntry->unk2c = 0x10;
        apEntry->unk34 = false;
        break;
    }
    return 0;
}
}  // namespace fnv_00e829b0

struct Matrix
{
    float m0;
    float m1;
    float m2;
    float m3;
    float m4;
    float m5;
    float m6;
    float m7;
    float m8;
    float m9;
    float m10;
    float m11;
    float m12;
    float m13;
    float m14;
    float m15;
};
struct Vector
{
    float x, y, z, w;
};
extern Matrix DAT_0126f820, DAT_0126f860, DAT_0126f8c0;
extern Vector DAT_0126f8a0, DAT_0126f8b0, DAT_0126f900;
void __stdcall Multiply(Matrix*, Matrix*, Matrix*);
void __stdcall Invert(Matrix*, void*, Matrix*);
void __stdcall Transpose(Matrix*, Matrix*);
void __stdcall Transform(Vector*, Vector*, void*);
// Computes a matrix or vector constant based on type and mode, applies inverse or transpose in some matrix cases, and passes it to SetConstant.
// @fnv 0x00e82b40
unsigned int __stdcall FUN_00e82b40(FUN_00e84b60_prog* prog, void* entry, unsigned int type, unsigned int mode,
                                    bool inverse, bool transpose)
{
    switch (type)
    {
    case 9:
        switch (mode)
        {
        case 9:
            Multiply(&DAT_0126f8c0, &DAT_0126f820, &DAT_0126f860);
            if (inverse)
                Invert(&DAT_0126f8c0, 0, &DAT_0126f8c0);
            if (transpose)
                Transpose(&DAT_0126f8c0, &DAT_0126f8c0);
            return prog->SetConstant(entry, &DAT_0126f8c0, 0) ? 0 : 80;
        case 3:
        case 4: {
            Matrix temp;
            temp.m0 = DAT_0126f8b0.x * DAT_0126f820.m0;
            temp.m1 = DAT_0126f820.m1 * DAT_0126f8b0.x;
            temp.m2 = DAT_0126f820.m2 * DAT_0126f8b0.x;
            temp.m3 = DAT_0126f820.m3 * DAT_0126f8b0.x;
            temp.m4 = DAT_0126f820.m4 * DAT_0126f8b0.x;
            temp.m5 = DAT_0126f820.m5 * DAT_0126f8b0.x;
            temp.m6 = DAT_0126f820.m6 * DAT_0126f8b0.x;
            temp.m7 = DAT_0126f820.m7 * DAT_0126f8b0.x;
            temp.m8 = DAT_0126f820.m8 * DAT_0126f8b0.x;
            temp.m9 = DAT_0126f820.m9 * DAT_0126f8b0.x;
            temp.m10 = DAT_0126f820.m10 * DAT_0126f8b0.x;
            temp.m11 = DAT_0126f820.m11 * DAT_0126f8b0.x;
            temp.m12 = DAT_0126f820.m12 * DAT_0126f8b0.x;
            temp.m13 = DAT_0126f820.m13 * DAT_0126f8b0.x;
            temp.m14 = DAT_0126f820.m14 * DAT_0126f8b0.x;
            temp.m15 = DAT_0126f820.m15 * DAT_0126f8b0.x;
            DAT_0126f8c0 = temp;
            if (inverse)
                Invert(&DAT_0126f8c0, 0, &DAT_0126f8c0);
            if (transpose)
                Transpose(&DAT_0126f8c0, &DAT_0126f8c0);
            return prog->SetConstant(entry, &DAT_0126f8c0, 0) ? 0 : 80;
        }
        case 7:
        case 10:
            Transform(&DAT_0126f900, &DAT_0126f8b0, &DAT_0126f820);
            return prog->SetConstant(entry, &DAT_0126f900, 0) ? 0 : 80;
        }
        break;
    case 7:
    case 10:
        switch (mode)
        {
        case 9:
            Transform(&DAT_0126f900, &DAT_0126f8a0, &DAT_0126f860);
            return prog->SetConstant(entry, &DAT_0126f900, 0) ? 0 : 80;
        case 3:
        case 4:
            DAT_0126f900.x = DAT_0126f8a0.x * DAT_0126f8b0.x;
            DAT_0126f900.y = DAT_0126f8a0.y * DAT_0126f8b0.x;
            DAT_0126f900.z = DAT_0126f8a0.z * DAT_0126f8b0.x;
            DAT_0126f900.w = DAT_0126f8a0.w * DAT_0126f8b0.x;
            return prog->SetConstant(entry, &DAT_0126f900, 0) ? 0 : 80;
        case 7:
        case 10:
            DAT_0126f900.x = DAT_0126f8a0.x * DAT_0126f8b0.x;
            DAT_0126f900.y = DAT_0126f8a0.y * DAT_0126f8b0.y;
            DAT_0126f900.z = DAT_0126f8a0.z * DAT_0126f8b0.z;
            DAT_0126f900.w = DAT_0126f8a0.w * DAT_0126f8b0.w;
            return prog->SetConstant(entry, &DAT_0126f900, 0) ? 0 : 80;
        }
    }
    return 1;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long*);
void* __cdecl FUN_00aa13e0(unsigned int);
char* __cdecl FUN_00a5b690(const char*);
void __cdecl FUN_00aa10f0(void*);
void* __cdecl FUN_00aa1070(unsigned int);
void* __cdecl FUN_00ec44d0(void*, const void*, unsigned int);
extern char* EmptyFS;
extern unsigned int DAT_011f5fc4[];
inline void* operator new(unsigned int, void* location)
{
    return location;
}

struct FUN_00e81ba0
{
    virtual ~FUN_00e81ba0();
    unsigned int referenceCount;
    unsigned int unk08;
    char* shaderName;
    unsigned int unk10;
    unsigned int flags;
    unsigned int parameter;
    unsigned int additionalValue;
    unsigned int registerType;
    char* propertyName;
    unsigned int elementSize;
    int elementType;
    void* data;
    bool ownsData;
    FUN_00e81ba0();
};

template <class T> struct ShaderPointer
{
    T* p;
};
template <class T> struct ShaderArray
{
    void* owner;
    T* data;
    unsigned short capacity;
    unsigned short size;
    unsigned short count;
    unsigned short grow;
};
struct ShaderConstantMap_83650
{
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual int vfn_80(FUN_00e81ba0*);
    unsigned int unk04;
    int renderStage;
    ShaderArray<ShaderPointer<FUN_00e81ba0> > entries;
    ShaderArray<ShaderPointer<FUN_00e81ba0> > defined;
    bool modified;
    char pad2d[3];
    void* last;
    unsigned int error;
    unsigned int FUN_00e83650(const char* shader, unsigned int flags, unsigned int parameter,
                              unsigned int additionalValue, unsigned int registerType, const char* property,
                              unsigned int elementSize, int elementType, void* data, bool copied);
};

// Creates a shader constant entry, copies data if requested, passes it to vfn_80, and returns the error code.
// @fnv 0x00e83650
unsigned int ShaderConstantMap_83650::FUN_00e83650(const char* shader, unsigned int flags, unsigned int parameter,
                                                   unsigned int additionalValue, unsigned int registerType,
                                                   const char* property, unsigned int elementSize, int elementType,
                                                   void* data, bool copied)
{
    void* memory = FUN_00aa13e0(sizeof(FUN_00e81ba0));
    FUN_00e81ba0* entry = memory ? new (memory) FUN_00e81ba0() : 0;
    char* name;
    if (!shader)
        name = EmptyFS;
    else
        name = FUN_00a5b690(shader);
    if (entry->shaderName != name)
    {
        if (name != EmptyFS)
            InterlockedIncrement((long*)(name - 8));
        if (entry->shaderName != EmptyFS)
            InterlockedDecrement((long*)(entry->shaderName - 8));
        entry->shaderName = name;
    }
    if (name != EmptyFS)
        InterlockedDecrement((long*)(name - 8));

    flags = (flags & 0x0fffffff) | 0x10000000;
    if (elementSize == 8)
        flags |= 5;
    else if (elementSize == 12)
        flags |= 6;
    else if (elementSize == 16)
        flags |= 7;
    else if (elementSize == 32)
        flags |= 9;
    else if (elementSize == 36)
        flags |= 8;
    else if (elementSize == 48)
        flags |= 9;
    else if (elementSize == 64)
        flags |= 9;
    entry->flags = flags;

    if (!(elementSize & 3) && elementType == 4 && DAT_011f5fc4[flags & 255] != 1 && DAT_011f5fc4[flags & 255] != 3)
    {
        if (renderStage == 0)
            parameter = elementType - 3;
        else if (renderStage == 2)
            parameter = 2;
    }
    entry->parameter = parameter;
    entry->additionalValue = additionalValue;
    entry->registerType = registerType;

    char* prop;
    if (!property)
        prop = EmptyFS;
    else
        prop = FUN_00a5b690(property);
    if (entry->propertyName != prop)
    {
        if (prop != EmptyFS)
            InterlockedIncrement((long*)(prop - 8));
        if (entry->propertyName != EmptyFS)
            InterlockedDecrement((long*)(entry->propertyName - 8));
        entry->propertyName = prop;
    }
    if (prop != EmptyFS)
        InterlockedDecrement((long*)(prop - 8));

    entry->elementType = elementType;
    entry->elementSize = elementSize;
    if (copied)
    {
        entry->ownsData = true;
        FUN_00aa10f0(entry->data);
        entry->data = FUN_00aa1070(elementSize);
        FUN_00ec44d0(entry->data, data, elementSize);
    }
    else
    {
        entry->ownsData = false;
        entry->data = data;
    }
    error = vfn_80(entry);
    if (error)
        delete entry;
    return error;
}

class GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_011f5b60;
extern GlobalObjectO2_00a7b610 g_011f5b68;

bool __cdecl FUN_0045bad0(void*, void*);

struct ExtraDataStandIn
{
    void* vtbl;
    int refCount;
    int unk08;
    union
    {
        unsigned char bVal;
        int iVal;
        float fVal;
        float c0;
    };
    union
    {
        const float* pfVal;
        const void* pData;
        float c1;
    };
    float c2;
    float c3;
};

extern unsigned int DAT_0126f7b0;
extern unsigned int DAT_0126f7b4[];
extern float DAT_0126f7cc[];
extern float s_colorBuffer[];
extern float DAT_0126f7e0[];

// Converts extraData fields according to the mapped type, returning a static buffer, pData, or null.
// @fnv 0x00e83840
const void* __stdcall GetShaderConstantValue(NiShaderConstantMapEntry* entry, ExtraDataStandIn* extraData)
{
    int type = DAT_011f5fc4[entry->flags & 0xff];

    if (type == 1)
    {
        DAT_0126f7b0 = extraData->bVal;
        return &DAT_0126f7b0;
    }
    if (type != 2)
    {
        if (type == 3)
        {
            unsigned int val = extraData->iVal;
            DAT_0126f7b4[0] = val;
            DAT_0126f7b4[1] = val;
            DAT_0126f7b4[2] = val;
            DAT_0126f7b4[3] = val;
            return DAT_0126f7b4;
        }
        if (type == 4)
        {
            DAT_0126f7cc[0] = extraData->fVal;
            DAT_0126f7cc[1] = DAT_0126f7cc[0];
            DAT_0126f7cc[2] = DAT_0126f7cc[0];
            DAT_0126f7cc[3] = DAT_0126f7cc[0];
            return DAT_0126f7cc;
        }
        if (type == 5)
        {
            const float* pf = extraData->pfVal;
            DAT_0126f7cc[0] = pf[0];
            DAT_0126f7cc[1] = pf[1];
            DAT_0126f7cc[2] = pf[0];
            DAT_0126f7cc[3] = pf[1];
            return DAT_0126f7cc;
        }
        if (type == 6)
        {
            const float* pf = extraData->pfVal;
            DAT_0126f7cc[0] = pf[0];
            DAT_0126f7cc[1] = pf[1];
            DAT_0126f7cc[2] = pf[2];
            DAT_0126f7cc[3] = 1.0f;
            return DAT_0126f7cc;
        }
        if (type == 7)
        {
            if (FUN_0045bad0(&g_011f5b60, extraData))
            {
                const float* pf = extraData->pfVal;
                DAT_0126f7cc[0] = pf[0];
                DAT_0126f7cc[1] = pf[1];
                DAT_0126f7cc[2] = pf[2];
                DAT_0126f7cc[3] = pf[3];
                return DAT_0126f7cc;
            }
            if (FUN_0045bad0(&g_011f5b68, extraData))
            {
                DAT_0126f7cc[0] = extraData->c0;
                DAT_0126f7cc[1] = extraData->c1;
                DAT_0126f7cc[2] = extraData->c2;
                DAT_0126f7cc[3] = extraData->c3;
            }
            return s_colorBuffer;
        }
        if (type == 8)
        {
            const float* pf = extraData->pfVal;
            DAT_0126f7e0[0] = pf[0];
            DAT_0126f7e0[1] = pf[1];
            DAT_0126f7e0[2] = pf[2];
            DAT_0126f7e0[3] = 0.0f;
            DAT_0126f7e0[4] = pf[3];
            DAT_0126f7e0[5] = pf[4];
            DAT_0126f7e0[6] = pf[5];
            DAT_0126f7e0[7] = 0.0f;
            DAT_0126f7e0[8] = pf[6];
            DAT_0126f7e0[9] = pf[7];
            DAT_0126f7e0[10] = pf[8];
            DAT_0126f7e0[11] = 0.0f;
            return DAT_0126f7e0;
        }
        if (type == 9)
        {
            return extraData->pData;
        }
        if (type == 10)
        {
            DAT_0126f7cc[0] = extraData->c0;
            DAT_0126f7cc[1] = extraData->c1;
            DAT_0126f7cc[2] = extraData->c2;
            DAT_0126f7cc[3] = extraData->c3;
            return DAT_0126f7cc;
        }
    }
    return 0;
}

struct ConstantEntryView
{
    void* vtable;
    long refs;
    unsigned int enabled;
    const char* key;
    void* binding;
    unsigned int flags, type, index, registers, extra;
    unsigned int byteSize, elementSize;
    const void* data;
};
extern unsigned int DAT_0126f7b0;
extern unsigned int DAT_0126f7b4[4];
extern float DAT_0126f7cc[4];
extern float DAT_0126f7e0[16];

// Returns entry data directly for some counts, otherwise converts supported values into static buffers.
// @fnv 0x00e83a90
const void* __stdcall GetConstantData(void* apEntry)
{
    ConstantEntryView* entry = static_cast<ConstantEntryView*>(apEntry);
    unsigned int count = entry->byteSize / entry->elementSize;
    unsigned int type = reinterpret_cast<const unsigned int*>(DAT_011f5fb4 + 16)[entry->flags & 255];
    switch (count)
    {
    case 1:
        if (type == 1)
        {
            DAT_0126f7b0 = *static_cast<const unsigned char*>(entry->data);
            return &DAT_0126f7b0;
        }
        if (type == 3)
        {
            unsigned int value = *static_cast<const unsigned int*>(entry->data);
            DAT_0126f7b4[0] = value;
            DAT_0126f7b4[1] = value;
            DAT_0126f7b4[2] = value;
            DAT_0126f7b4[3] = value;
            return DAT_0126f7b4;
        }
        DAT_0126f7cc[0] = *static_cast<const float*>(entry->data);
        DAT_0126f7cc[1] = DAT_0126f7cc[0];
        DAT_0126f7cc[2] = DAT_0126f7cc[0];
        DAT_0126f7cc[3] = DAT_0126f7cc[0];
        return DAT_0126f7cc;
    case 2: {
        if (type == 3)
        {
            const unsigned int* values = static_cast<const unsigned int*>(entry->data);
            DAT_0126f7b4[0] = values[0];
            DAT_0126f7b4[1] = values[1];
            DAT_0126f7b4[2] = DAT_0126f7b4[0];
            DAT_0126f7b4[3] = DAT_0126f7b4[1];
            return DAT_0126f7b4;
        }
        const float* values = static_cast<const float*>(entry->data);
        DAT_0126f7cc[0] = values[0];
        DAT_0126f7cc[1] = values[1];
        DAT_0126f7cc[2] = DAT_0126f7cc[0];
        DAT_0126f7cc[3] = DAT_0126f7cc[1];
        return DAT_0126f7cc;
    }
    case 3: {
        const void* data = entry->data;
        if (type == 3)
        {
            const unsigned int* values = static_cast<const unsigned int*>(data);
            DAT_0126f7b4[0] = values[0];
            DAT_0126f7b4[1] = values[1];
            DAT_0126f7b4[2] = values[2];
            DAT_0126f7b4[3] = 1;
            return DAT_0126f7b4;
        }
        const float* values = static_cast<const float*>(entry->data);
        DAT_0126f7cc[0] = values[0];
        DAT_0126f7cc[1] = values[1];
        DAT_0126f7cc[2] = values[2];
        DAT_0126f7cc[3] = 1.0f;
        return DAT_0126f7cc;
    }
    case 4:
    case 16:
        return entry->data;
    case 8: {
        const float* values = static_cast<const float*>(entry->data);
        DAT_0126f7e0[0] = values[0];
        DAT_0126f7e0[1] = values[1];
        DAT_0126f7e0[2] = values[2];
        DAT_0126f7e0[3] = values[3];
        DAT_0126f7e0[4] = values[4];
        DAT_0126f7e0[5] = values[5];
        DAT_0126f7e0[6] = values[6];
        DAT_0126f7e0[7] = values[7];
        DAT_0126f7e0[8] = 0.0f;
        DAT_0126f7e0[9] = 0.0f;
        DAT_0126f7e0[10] = 0.0f;
        DAT_0126f7e0[11] = 0.0f;
        DAT_0126f7e0[12] = 0.0f;
        DAT_0126f7e0[13] = 0.0f;
        DAT_0126f7e0[14] = 0.0f;
        DAT_0126f7e0[15] = 0.0f;
        return DAT_0126f7e0;
    }
    case 9: {
        const float* values = static_cast<const float*>(entry->data);
        DAT_0126f7e0[0] = values[0];
        DAT_0126f7e0[1] = values[1];
        DAT_0126f7e0[2] = values[2];
        DAT_0126f7e0[3] = 0.0f;
        DAT_0126f7e0[4] = values[3];
        DAT_0126f7e0[5] = values[4];
        DAT_0126f7e0[6] = values[5];
        DAT_0126f7e0[7] = 0.0f;
        DAT_0126f7e0[8] = values[6];
        DAT_0126f7e0[9] = values[7];
        DAT_0126f7e0[10] = values[8];
        DAT_0126f7e0[11] = 0.0f;
        DAT_0126f7e0[12] = 0.0f;
        DAT_0126f7e0[13] = 0.0f;
        DAT_0126f7e0[14] = 0.0f;
        DAT_0126f7e0[15] = 0.0f;
        return DAT_0126f7e0;
    }
    case 12: {
        const float* values = static_cast<const float*>(entry->data);
        DAT_0126f7e0[0] = values[0];
        DAT_0126f7e0[1] = values[1];
        DAT_0126f7e0[2] = values[2];
        DAT_0126f7e0[3] = values[3];
        DAT_0126f7e0[4] = values[4];
        DAT_0126f7e0[5] = values[5];
        DAT_0126f7e0[6] = values[6];
        DAT_0126f7e0[7] = values[7];
        DAT_0126f7e0[8] = values[8];
        DAT_0126f7e0[9] = values[9];
        DAT_0126f7e0[10] = values[10];
        DAT_0126f7e0[11] = values[11];
        DAT_0126f7e0[12] = 0.0f;
        DAT_0126f7e0[13] = 0.0f;
        DAT_0126f7e0[14] = 0.0f;
        DAT_0126f7e0[15] = 0.0f;
        return DAT_0126f7e0;
    }
    default:
        if (entry->elementSize == 4 && (count & 3) == 0)
            return entry->data;
        return 0;
    }
}

class NiFixedString
{
  public:
    const char* m_handle;
    bool operator==(const NiFixedString& o) const
    {
        return m_handle == o.m_handle;
    }
    bool operator!=(const NiFixedString& o) const
    {
        return m_handle != o.m_handle;
    }
};

class NiTexture
{
  public:
    const NiFixedString& GetFilename();
};

class NiAVObject
{
  public:
    NiTexture* GetExtraData(const NiFixedString& name);
};

struct TexEntry
{
    int unk00;
    int unk04;
    int unk08;
    NiFixedString key;
    int unk10;
    unsigned int flags;
    int unk18;
    unsigned int unk1c;
};

struct TexProgram
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual bool SetConstant(TexEntry* entry, const void* data, unsigned int n);
};

struct TexCache
{
    NiTexture* Find(unsigned int id, unsigned int pass, int owner, bool global);
    void Add(unsigned int id, unsigned int pass, int owner, NiTexture* tex, bool global);
};

struct TexConstantMap
{
    int unk00;
    int unk04;
    int unk08;
    const void* LookupDefault(TexEntry* entry);
    const void* LookupTexture(TexEntry* entry, NiTexture* tex);
    unsigned int FUN_00e84ba0(TexProgram* prog, TexEntry* entry, NiAVObject* geom, void* a3, void* a4, void* a5,
                              void* a6, void* a7, void* a8, void* a9, unsigned int pass, bool global, TexCache* cache);
};

// Resolves a texture for a TexEntry via cache or geom, looks up its constant data, and calls prog->SetConstant with a size derived from entry->flags.
// @fnv 0x00e84ba0
unsigned int TexConstantMap::FUN_00e84ba0(TexProgram* prog, TexEntry* entry, NiAVObject* geom, void* apUnused3,
                                          void* apUnused4, void* apUnused5, void* apUnused6, void* apUnused7,
                                          void* apUnused8, void* apUnused9, unsigned int pass, bool global,
                                          TexCache* cache)
{
    if (!geom)
        return 1;

    NiTexture* tex;
    if (cache)
    {
        int owner = unk08;
        unsigned int id = entry->unk1c;
        tex = cache->Find(id, pass, owner, global);
        if (!tex || tex->GetFilename() != entry->key)
        {
            tex = geom->GetExtraData(entry->key);
            if (tex)
                cache->Add(entry->unk1c, pass, unk08, tex, global);
        }
    }
    else
    {
        tex = geom->GetExtraData(entry->key);
    }

    const void* data;
    if (!tex)
    {
        data = LookupDefault(entry);
        if (!data)
            return 0x10;
    }
    else
    {
        data = LookupTexture(entry, tex);
        if (!data)
            return 0x40;
    }

    int type = DAT_011f5fc4[entry->flags & 0xff];
    if (type == 9)
    {
        if (!prog->SetConstant(entry, data, 4))
            return 0x50;
    }
    else if (type == 6 || type == 7 || type == 5 || type == 4 || type == 10 || type == 3 || type == 1)
    {
        if (!prog->SetConstant(entry, data, 0))
            return 0x50;
    }
    else if (type == 8)
    {
        if (!prog->SetConstant(entry, data, 3))
            return 0x50;
    }
    return 0;
}

namespace fnv_00e84d00 {
extern unsigned int DAT_011f5fc4[];
extern unsigned int DAT_0126f7b0;
extern unsigned int DAT_0126f7b4[4];
extern float DAT_0126f7cc[4];
extern float DAT_0126f7e0[12];

// For supported uiType values, copies or passes pkEntry->data to SetConstant, returning 0x50 if that call fails.
// @fnv 0x00e84d00
unsigned int __stdcall FUN_00e84d00(FUN_00e84b60_prog* pkProgram, NiShaderConstantMapEntry* pkEntry,
                                    unsigned int uiPass)
{
    unsigned int uiResult = 0;
    unsigned int uiType = DAT_011f5fc4[pkEntry->flags & 0xff];

    if (uiType == 1)
    {
        DAT_0126f7b0 = *(const unsigned char*)pkEntry->data;
        if (!pkProgram->SetConstant(pkEntry, &DAT_0126f7b0, 0))
            uiResult = 0x50;
    }
    else if (uiType == 3)
    {
        unsigned int uiValue = *(const unsigned int*)pkEntry->data;
        DAT_0126f7b4[0] = uiValue;
        DAT_0126f7b4[1] = uiValue;
        DAT_0126f7b4[2] = uiValue;
        DAT_0126f7b4[3] = uiValue;
        if (!pkProgram->SetConstant(pkEntry, DAT_0126f7b4, 0))
            uiResult = 0x50;
    }
    else if (uiType == 4)
    {
        const float* pVector4 = pkEntry->data;
        DAT_0126f7cc[0] = pVector4[0];
        DAT_0126f7cc[1] = DAT_0126f7cc[0];
        DAT_0126f7cc[2] = DAT_0126f7cc[0];
        DAT_0126f7cc[3] = DAT_0126f7cc[0];
        if (!pkProgram->SetConstant(pkEntry, DAT_0126f7cc, 0))
            uiResult = 0x50;
    }
    else if (uiType == 5)
    {
        const float* pVector4 = pkEntry->data;
        DAT_0126f7cc[0] = pVector4[0];
        DAT_0126f7cc[1] = pVector4[1];
        DAT_0126f7cc[2] = DAT_0126f7cc[0];
        DAT_0126f7cc[3] = DAT_0126f7cc[1];
        if (!pkProgram->SetConstant(pkEntry, DAT_0126f7cc, 0))
            uiResult = 0x50;
    }
    else if (uiType == 6)
    {
        const float* pVector4 = pkEntry->data;
        DAT_0126f7cc[0] = pVector4[0];
        DAT_0126f7cc[1] = pVector4[1];
        DAT_0126f7cc[2] = pVector4[2];
        DAT_0126f7cc[3] = 1.0f;
        if (!pkProgram->SetConstant(pkEntry, DAT_0126f7cc, 0))
            uiResult = 0x50;
    }
    else if (uiType == 7 || uiType == 10)
    {
        const float* pVector4 = pkEntry->data;
        DAT_0126f7cc[0] = pVector4[0];
        DAT_0126f7cc[1] = pVector4[1];
        DAT_0126f7cc[2] = pVector4[2];
        DAT_0126f7cc[3] = pVector4[3];
        if (!pkProgram->SetConstant(pkEntry, DAT_0126f7cc, 0))
            uiResult = 0x50;
    }
    else if (uiType == 8)
    {
        const float* pVector4 = pkEntry->data;
        DAT_0126f7e0[0] = pVector4[0];
        DAT_0126f7e0[1] = pVector4[1];
        DAT_0126f7e0[2] = pVector4[2];
        DAT_0126f7e0[3] = 0.0f;
        DAT_0126f7e0[4] = pVector4[3];
        DAT_0126f7e0[5] = pVector4[4];
        DAT_0126f7e0[6] = pVector4[5];
        DAT_0126f7e0[7] = 0.0f;
        DAT_0126f7e0[8] = pVector4[6];
        DAT_0126f7e0[9] = pVector4[7];
        DAT_0126f7e0[10] = pVector4[8];
        DAT_0126f7e0[11] = 0.0f;
        if (!pkProgram->SetConstant(pkEntry, DAT_0126f7e0, 0))
            uiResult = 0x50;
    }
    else if (uiType == 9)
    {
        const float* pVector4 = pkEntry->data;
        if (!pkProgram->SetConstant(pkEntry, pVector4, 0))
            uiResult = 0x50;
    }
    return uiResult;
}
}  // namespace fnv_00e84d00

extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);
extern "C" double __cdecl cos(double);

class NiPoint3_ext : public NiPoint3
{
  public:
    NiPoint3_ext& operator*=(float);
    NiPoint3* FUN_00439ef0(NiPoint3*, const NiPoint3&) const;
    void FUN_004a0c10();
    float Dot(const NiPoint3&) const;
};

class NiMatrix3_ext : public ThreeByThreeMatrix
{
  public:
    NiMatrix3_ext* FUN_004768c0(NiMatrix3_ext*) const;
    ThreeByThreeMatrix* FUN_0043f8d0(ThreeByThreeMatrix*, const ThreeByThreeMatrix&) const;
    NiPoint3* FUN_004b4500(NiPoint3*, const NiPoint3&) const;
};

class NiTransform
{
  public:
    ThreeByThreeMatrix m_kOrientation;
    NiPoint3 m_kTranslation;
    float m_fScale;

    void FUN_004b4880(NiTransform& kDest) const;
    NiPoint3* FUN_00524c40(NiPoint3*, const NiPoint3& pt) const;
    NiTransform* FUN_0062c250(NiTransform*, const NiTransform& xform) const;
};

class NiBound
{
  public:
    NiPoint3 m_kCenter;
    float m_fBoundRadius;
};

struct NiRTTI;
extern const NiRTTI DAT_011f4a98;
bool __cdecl FUN_0043b300(const NiRTTI*, void*);
void __cdecl FUN_00b71a40(float* d, const ThreeByThreeMatrix& r, const NiPoint3& t, float s);
void __cdecl FUN_00b799a0(float* d, const char* t);
extern const NiPoint3 DAT_011f426c;

struct StandinLight
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    NiTransform m_kWorldSpaceTransform;
    char unk9c;
    unsigned char m_ucLightType;
    char unk9e;
    char unk9f;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    float m_fDimmer;
    NiPoint3 m_kAmbient;
    NiPoint3 m_kDiffuse;
    NiPoint3 m_kSpecular;
    int unkec;
    union
    {
        struct
        {
            NiPoint3 m_kWorldLocation;
            NiPoint3 m_kSpotDirection;
            float m_fOuterAngle;
            float m_fInnerAngle;
            float m_fSpotExponent;
            int unk114;
        };
        struct
        {
            int unkF0;
            ThreeByThreeMatrix m_kLightRotate;
        };
    };
    NiPoint3 m_kWorldDirection;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    unsigned int m_uiSubtype;
    unsigned char m_bAtten;
    char unk139;
    char unk13a;
    char unk13b;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    union
    {
        struct
        {
            float m_fConstantAtten;
            float m_fLinearAtten;
            float m_fQuadAtten;
            float m_fDistanceLimit;
        };
        struct
        {
            NiPoint3 m_kPlaneNormal;
            float m_fPlaneDistance;
        };
    };
};

struct NiD3DMatrix4
{
    float m[4][4];
};

struct LightPlane
{
    NiPoint3 normal;
    float distance;
};
struct LightMappingWorkspace
{
    volatile float scalar;
    LightPlane plane;
    NiD3DMatrix4 matrix;
    NiPoint3 scaledAtten;
    NiD3DMatrix4 identity;
    NiTransform inverse;
    NiTransform lightWorld;
    NiPoint3 modelWorldDirection;
    NiPoint3 modelDirection;
    NiPoint3 modelPosition;
    NiPoint3 distantModelPosition;
    NiPoint3 pointLightDirection;
    NiPoint3 modelLightDirection;
    NiPoint3 pointLightModelDirection;
    ThreeByThreeMatrix modelWorldRotation;
    NiMatrix3_ext inverseEffectRotation;
    ThreeByThreeMatrix modelEffectRotation;
    NiMatrix3_ext inverseWorldRotation;
    NiMatrix3_ext inverseLightRotation;
    NiTransform modelLightWorld;
};

union PointBits
{
    NiPoint3 point;
    struct
    {
        unsigned int x, y, z;
    } words;
};
__forceinline void CopyPoint24(NiPoint3& dst, const NiPoint3& src)
{
    unsigned int x = ((const PointBits&)src).words.x;
    unsigned int y = ((const PointBits&)src).words.y;
    unsigned int z = ((const PointBits&)src).words.z;
    ((PointBits&)dst).words.z = z;
    ((PointBits&)dst).words.x = x;
    ((PointBits&)dst).words.y = y;
}
__forceinline void CopyPointValue(NiPoint3& dst, const NiPoint3& src)
{
    volatile PointBits& destination = (volatile PointBits&)dst;
    const volatile PointBits& source = (const volatile PointBits&)src;
    unsigned int x = source.words.x;
    unsigned int y = source.words.y;
    unsigned int z = source.words.z;
    destination.words.x = x;
    destination.words.y = y;
    destination.words.z = z;
}

static __declspec(noinline) void CopyMatrix(void* dst, const void* src)
{
    const float* s = (const float*)src;
    float* d = (float*)dst;
    d[0] = s[0];
    d[1] = s[1];
    d[2] = s[2];
    d[3] = s[3];
    d[4] = s[4];
    d[5] = s[5];
    d[6] = s[6];
    d[7] = s[7];
    d[8] = s[8];
    d[9] = s[9];
    d[10] = s[10];
    d[11] = s[11];
    d[12] = s[12];
    d[13] = s[13];
    d[14] = s[14];
    d[15] = s[15];
}

// Fills pvData with light constant values selected by uiMapping from the StandinLight in pSource, transforming positions and directions with kWorld when needed.
// @fnv 0x00e84ed0
bool __cdecl FillLightConstantData(void* apConstantData, unsigned int uiConstantDataSize, unsigned int uiMapping,
                                   void* pSource, NiGeometry* m_pShaderGeometry, const NiSkinInstance* pSkinInstance,
                                   const NiSkinPartition::Partition* pPartition, NiGeometryBufferData* pBuffData,
                                   const NiPropertyState* pState, const NiDynamicEffectState* apDynamicEffectState,
                                   const NiTransform& kWorld, const NiBound& kWorldBound, unsigned int uiPass)
{
    NiPoint3 point;
    LightMappingWorkspace work;
    fnv_zlib_memset(&work.identity, 0, sizeof(work.identity));
    work.identity.m[3][3] = 1.0f;
    work.identity.m[2][2] = 1.0f;
    work.identity.m[1][1] = 1.0f;
    work.identity.m[0][0] = 1.0f;

    StandinLight* apTargetLight = (StandinLight*)pSource;

    switch (uiMapping)
    {
    case 1: {
        float* fData = (float*)apConstantData;
        if (!apTargetLight)
        {
            fData[0] = 0.0f;
            fData[1] = 0.0f;
            fData[2] = 0.0f;
            fData[3] = 0.0f;
            return false;
        }
        fData[0] = apTargetLight->m_fDimmer;
        fData[1] = 0.0f;
        fData[2] = 0.0f;
        fData[3] = 0.0f;
        return true;
    }
    case 2: {
        float* fData = (float*)apConstantData;
        if (apTargetLight)
        {
            fData[0] = apTargetLight->m_kAmbient.x;
            fData[1] = apTargetLight->m_kAmbient.y;
            fData[2] = apTargetLight->m_kAmbient.z;
            fData[3] = 1.0f;
            return true;
        }
        fData[0] = 0.0f;
        fData[1] = 0.0f;
        fData[2] = 0.0f;
        fData[3] = 1.0f;
        return false;
    }
    case 3: {
        float* fData = (float*)apConstantData;
        if (apTargetLight)
        {
            fData[0] = apTargetLight->m_kDiffuse.x;
            fData[1] = apTargetLight->m_kDiffuse.y;
            fData[2] = apTargetLight->m_kDiffuse.z;
            fData[3] = 1.0f;
            return true;
        }
        fData[0] = 0.0f;
        fData[1] = 0.0f;
        fData[2] = 0.0f;
        fData[3] = 1.0f;
        return false;
    }
    case 4: {
        float* fData = (float*)apConstantData;
        if (apTargetLight)
        {
            fData[0] = apTargetLight->m_kSpecular.x;
            fData[1] = apTargetLight->m_kSpecular.y;
            fData[2] = apTargetLight->m_kSpecular.z;
            fData[3] = 1.0f;
            return true;
        }
        fData[0] = 0.0f;
        fData[1] = 0.0f;
        fData[2] = 0.0f;
        fData[3] = 1.0f;
        return false;
    }
    case 5: {
        float* fData = (float*)apConstantData;
        if (apTargetLight)
        {
            point = apTargetLight->m_kAmbient;
            *((NiPoint3_ext*)&point) *= apTargetLight->m_fDimmer;
            fData[0] = point.x;
            fData[1] = point.y;
            fData[2] = point.z;
            fData[3] = 1.0f;
            return true;
        }
        fData[0] = 0.0f;
        fData[1] = 0.0f;
        fData[2] = 0.0f;
        fData[3] = 1.0f;
        return false;
    }
    case 6: {
        float* fData = (float*)apConstantData;
        if (apTargetLight)
        {
            point = apTargetLight->m_kDiffuse;
            *((NiPoint3_ext*)&point) *= apTargetLight->m_fDimmer;
            fData[0] = point.x;
            fData[1] = point.y;
            fData[2] = point.z;
            fData[3] = 1.0f;
            return true;
        }
        fData[0] = 0.0f;
        fData[1] = 0.0f;
        fData[2] = 0.0f;
        fData[3] = 1.0f;
        return false;
    }
    case 7: {
        float* fData = (float*)apConstantData;
        if (apTargetLight)
        {
            point = apTargetLight->m_kSpecular;
            *((NiPoint3_ext*)&point) *= apTargetLight->m_fDimmer;
            fData[0] = point.x;
            fData[1] = point.y;
            fData[2] = point.z;
            fData[3] = 1.0f;
            return true;
        }
        fData[0] = 0.0f;
        fData[1] = 0.0f;
        fData[2] = 0.0f;
        fData[3] = 1.0f;
        return false;
    }
    case 8: {
        float* fData = (float*)apConstantData;
        if (apTargetLight)
        {
            if (apTargetLight->m_ucLightType == 3)
            {
                point.x = (float)(apTargetLight->m_kWorldLocation.x * -1048576.0);
                point.y = (float)(apTargetLight->m_kWorldLocation.y * -1048576.0);
                point.z = (float)(apTargetLight->m_kWorldLocation.z * -1048576.0);
                fData[0] = point.x;
                fData[1] = point.y;
                fData[2] = point.z;
                fData[3] = 1.0f;
            }
            else
            {
                fData[0] = apTargetLight->m_kWorldSpaceTransform.m_kTranslation.x;
                fData[1] = apTargetLight->m_kWorldSpaceTransform.m_kTranslation.y;
                fData[2] = apTargetLight->m_kWorldSpaceTransform.m_kTranslation.z;
                fData[3] = 1.0f;
            }
            return true;
        }
        fData[0] = 0.0f;
        fData[1] = 0.0f;
        fData[2] = 0.0f;
        fData[3] = 1.0f;
        return false;
    }
    case 9: {
        float* fData = (float*)apConstantData;
        if (apTargetLight)
        {
            kWorld.FUN_004b4880(work.lightWorld);
            if (apTargetLight->m_ucLightType == 3)
            {
                point.x = (float)(apTargetLight->m_kWorldLocation.x * -1048576.0);
                point.y = (float)(apTargetLight->m_kWorldLocation.y * -1048576.0);
                point.z = (float)(apTargetLight->m_kWorldLocation.z * -1048576.0);
                {
                    NiPoint3* __restrict r = work.lightWorld.FUN_00524c40(&work.distantModelPosition, point);
                    point = *r;
                }
            }
            else
            {
                CopyPointValue(point,
                               *work.lightWorld.FUN_00524c40(&work.modelPosition, apTargetLight->m_kWorldSpaceTransform.m_kTranslation));
            }
            fData[0] = point.x;
            fData[1] = point.y;
            fData[2] = point.z;
            fData[3] = 1.0f;
            return true;
        }
        fData[0] = 0.0f;
        fData[1] = 0.0f;
        fData[2] = 0.0f;
        fData[3] = 1.0f;
        return false;
    }
    case 10: {
        float* fData = (float*)apConstantData;
        if (apTargetLight)
        {
            if (apTargetLight->m_ucLightType == 2)
            {
                {
                    NiPoint3* __restrict r =
                        ((NiPoint3_ext*)&kWorldBound.m_kCenter)
                            ->FUN_00439ef0(&work.pointLightDirection, apTargetLight->m_kWorldSpaceTransform.m_kTranslation);
                    point = *r;
                }
                ((NiPoint3_ext*)&point)->FUN_004a0c10();
            }
            else if (apTargetLight->m_ucLightType == 3)
            {
                point = apTargetLight->m_kWorldLocation;
            }
            else
            {
                point = apTargetLight->m_kSpotDirection;
            }
            fData[0] = point.x;
            fData[1] = point.y;
            fData[2] = point.z;
            fData[3] = 1.0f;
            return true;
        }
        fData[0] = 1.0f;
        fData[1] = 0.0f;
        fData[2] = 0.0f;
        fData[3] = 1.0f;
        return false;
    }
    case 11: {
        float* fData = (float*)apConstantData;
        if (apTargetLight)
        {
            if (apTargetLight->m_ucLightType == 2)
            {
                {
                    NiPoint3* __restrict r =
                        ((NiPoint3_ext*)&kWorldBound.m_kCenter)
                            ->FUN_00439ef0(&work.pointLightModelDirection, apTargetLight->m_kWorldSpaceTransform.m_kTranslation);
                    point = *r;
                }
                ((NiPoint3_ext*)&point)->FUN_004a0c10();
            }
            else if (apTargetLight->m_ucLightType == 3)
            {
                point = apTargetLight->m_kWorldLocation;
            }
            else
            {
                point = apTargetLight->m_kSpotDirection;
            }
            CopyPointValue(point, *((NiMatrix3_ext*)&kWorld.m_kOrientation)
                                       ->FUN_004768c0(&work.inverseLightRotation)
                                       ->FUN_004b4500(&work.modelLightDirection, point));
            fData[0] = point.x;
            fData[1] = point.y;
            fData[2] = point.z;
            fData[3] = 1.0f;
            return true;
        }
        fData[0] = 1.0f;
        fData[1] = 0.0f;
        fData[2] = 0.0f;
        fData[3] = 1.0f;
        return false;
    }
    case 12: {
        if (apTargetLight)
        {
            work.identity.m[0][3] = work.identity.m[1][3] = work.identity.m[2][3] = 0.0f;
            work.identity.m[3][3] = 1.0f;
            if (apTargetLight->m_ucLightType == 3)
            {
                point.x = (float)(apTargetLight->m_kWorldLocation.x * -1048576.0);
                point.y = (float)(apTargetLight->m_kWorldLocation.y * -1048576.0);
                point.z = (float)(apTargetLight->m_kWorldLocation.z * -1048576.0);
                FUN_00b71a40((float*)&work.identity, apTargetLight->m_kWorldSpaceTransform.m_kOrientation, point, apTargetLight->m_kWorldSpaceTransform.m_fScale);
            }
            else
            {
                FUN_00b799a0((float*)&work.identity, (const char*)&apTargetLight->m_kWorldSpaceTransform);
            }
            CopyMatrix(apConstantData, &work.identity);
            return true;
        }
        CopyMatrix(apConstantData, &work.identity);
        return false;
    }
    case 13: {
        if (apTargetLight)
        {
            kWorld.FUN_004b4880(work.inverse);
            work.matrix.m[0][3] = work.matrix.m[1][3] = work.matrix.m[2][3] = 0.0f;
            work.matrix.m[3][3] = 1.0f;
            if (apTargetLight->m_ucLightType == 3)
            {
                work.lightWorld = apTargetLight->m_kWorldSpaceTransform;
                point.x = (float)(-1048576.0 * apTargetLight->m_kWorldLocation.x);
                point.y = (float)(-1048576.0 * apTargetLight->m_kWorldLocation.y);
                point.z = (float)(-1048576.0 * apTargetLight->m_kWorldLocation.z);
                work.lightWorld.m_kTranslation = point;
                FUN_00b799a0((float*)&work.matrix,
                             (const char*)work.inverse.FUN_0062c250(&work.modelLightWorld, work.lightWorld));
            }
            else
            {
                FUN_00b799a0((float*)&work.matrix,
                             (const char*)work.inverse.FUN_0062c250((NiTransform*)&work.identity, apTargetLight->m_kWorldSpaceTransform));
            }
            CopyMatrix(apConstantData, &work.matrix);
            return true;
        }
        CopyMatrix(apConstantData, &work.identity);
        return false;
    }
    case 14: {
        float* fData = (float*)apConstantData;
        if (apTargetLight)
        {
            if (apTargetLight->m_ucLightType == 4)
            {
                work.scalar = (float)(apTargetLight->m_fInnerAngle * 3.1415927410125732 / 180.0);
                work.scalar = (float)cos(work.scalar);
                fData[0] = work.scalar;
                work.scalar = (float)(apTargetLight->m_fOuterAngle * 3.1415927410125732 / 180.0);
                work.scalar = (float)cos(work.scalar);
                fData[1] = work.scalar;
                fData[2] = apTargetLight->m_fSpotExponent;
                fData[3] = 0.0f;
            }
            else
            {
                fData[0] = -1.0f;
                fData[1] = -1.0f;
                fData[2] = 0.0f;
                fData[3] = 0.0f;
            }
            return true;
        }
        fData[0] = -1.0f;
        fData[1] = -1.0f;
        fData[2] = 0.0f;
        fData[3] = 0.0f;
        return false;
    }
    case 15: {
        float* fData = (float*)apConstantData;
        if (apTargetLight)
        {
            if (FUN_0043b300(&DAT_011f4a98, apTargetLight))
            {
                fData[0] = apTargetLight->m_kWorldLocation.x;
                fData[1] = apTargetLight->m_kWorldLocation.y;
                fData[2] = apTargetLight->m_kWorldLocation.z;
                fData[3] = 0.0f;
            }
            else
            {
                fData[0] = 1.0f;
                fData[1] = 0.0f;
                fData[2] = 0.0f;
                fData[3] = 0.0f;
            }
            return true;
        }
        fData[0] = 1.0f;
        fData[1] = 0.0f;
        fData[2] = 0.0f;
        fData[3] = 0.0f;
        return false;
    }
    case 16: {
        if (apTargetLight)
        {
            work.matrix.m[0][3] = work.matrix.m[1][3] = work.matrix.m[2][3] = 0.0f;
            work.matrix.m[3][3] = 1.0f;
            FUN_00b71a40((float*)&work.matrix, apTargetLight->m_kLightRotate, DAT_011f426c, 1.0f);
            CopyMatrix(apConstantData, &work.matrix);
            return true;
        }
        CopyMatrix(apConstantData, &work.identity);
        return false;
    }
    case 17: {
        if (apTargetLight)
        {
            work.matrix.m[0][3] = work.matrix.m[1][3] = work.matrix.m[2][3] = 0.0f;
            work.matrix.m[3][3] = 1.0f;
            FUN_00b71a40((float*)&work.matrix,
                         *((NiMatrix3_ext*)&kWorld.m_kOrientation)
                              ->FUN_004768c0(&work.inverseEffectRotation)
                              ->FUN_0043f8d0(&work.modelEffectRotation, apTargetLight->m_kLightRotate),
                         DAT_011f426c, 1.0f);
            CopyMatrix(apConstantData, &work.matrix);
            return true;
        }
        CopyMatrix(apConstantData, &work.identity);
        return false;
    }
    case 18: {
        float* fData = (float*)apConstantData;
        if (!apTargetLight)
        {
            fData[0] = 0.0f;
            fData[1] = 0.0f;
            fData[2] = 0.0f;
            fData[3] = 1.0f;
            return false;
        }
        fData[0] = apTargetLight->m_kWorldDirection.x;
        fData[1] = apTargetLight->m_kWorldDirection.y;
        fData[2] = apTargetLight->m_kWorldDirection.z;
        fData[3] = 1.0f;
        return true;
    }
    case 19: {
        float* fData = (float*)apConstantData;
        if (apTargetLight)
        {
            kWorld.FUN_004b4880(work.inverse);
            point = apTargetLight->m_kWorldDirection;
            {
                NiPoint3* __restrict r = work.inverse.FUN_00524c40(&work.modelDirection, point);
                point = *r;
            }
            fData[0] = point.x;
            fData[1] = point.y;
            fData[2] = point.z;
            fData[3] = 1.0f;
            return true;
        }
        fData[0] = 0.0f;
        fData[1] = 0.0f;
        fData[2] = 0.0f;
        fData[3] = 1.0f;
        return false;
    }
    case 20: {
        float* fData = (float*)apConstantData;
        if (apTargetLight)
        {
            if (apTargetLight->m_bAtten)
            {
                fData[0] = apTargetLight->m_fConstantAtten;
                fData[1] = apTargetLight->m_fLinearAtten;
                fData[2] = apTargetLight->m_fQuadAtten;
                fData[3] = apTargetLight->m_fDistanceLimit;
                return true;
            }
            fData[0] = 0.0f;
            fData[1] = 0.0f;
            fData[2] = 0.0f;
            fData[3] = 0.0f;
            return true;
        }
        fData[0] = 1.0f;
        fData[1] = 0.0f;
        fData[2] = 0.0f;
        fData[3] = 0.0f;
        return false;
    }
    case 21: {
        float* fData = (float*)apConstantData;
        if (apTargetLight)
        {
            if (apTargetLight->m_bAtten)
            {
                kWorld.FUN_004b4880(work.inverse);

                work.plane = *(LightPlane*)&apTargetLight->m_kPlaneNormal;
                ((NiMatrix3_ext*)&work.inverse.m_kOrientation)->FUN_004b4500(&point, work.plane.normal);
                work.scaledAtten.x = work.plane.normal.x * work.plane.distance;
                work.scaledAtten.y = work.plane.normal.y * work.plane.distance;
                work.scaledAtten.z = work.plane.normal.z * work.plane.distance;
                work.inverse.FUN_00524c40(&work.plane.normal, work.scaledAtten);
                fData[0] = point.x;
                fData[1] = point.y;
                fData[2] = point.z;
                fData[3] = ((NiPoint3_ext*)&point)->Dot(work.plane.normal);
                return true;
            }
            fData[0] = 0.0f;
            fData[1] = 0.0f;
            fData[2] = 0.0f;
            fData[3] = 0.0f;
            return true;
        }
        fData[0] = 1.0f;
        fData[1] = 0.0f;
        fData[2] = 0.0f;
        fData[3] = 0.0f;
        return false;
    }
    case 22: {
        float* fData = (float*)apConstantData;
        if (apTargetLight)
        {
            work.scalar = 0.0f;
            switch (apTargetLight->m_uiSubtype)
            {
            case 0:
            case 1:
                work.scalar = 2.0f;
                break;
            case 2:
            case 3:
                work.scalar = 3.0f;
                break;
            case 4:
                work.scalar = 1.0f;
                break;
            }
            fData[0] = work.scalar;
            fData[1] = 0.0f;
            fData[2] = 0.0f;
            fData[3] = 0.0f;
            return true;
        }
        fData[0] = 0.0f;
        fData[1] = 0.0f;
        fData[2] = 0.0f;
        fData[3] = 0.0f;
        return false;
    }
    case 23: {
        if (apTargetLight)
        {
            work.matrix.m[0][3] = work.matrix.m[1][3] = work.matrix.m[2][3] = 0.0f;
            work.matrix.m[3][3] = 1.0f;
            FUN_00b71a40((float*)&work.matrix, apTargetLight->m_kLightRotate, apTargetLight->m_kWorldDirection, 1.0f);
            CopyMatrix(apConstantData, &work.matrix);
            return true;
        }
        CopyMatrix(apConstantData, &work.identity);
        return false;
    }
    case 24: {
        if (apTargetLight)
        {
            work.matrix.m[0][3] = work.matrix.m[1][3] = work.matrix.m[2][3] = 0.0f;
            work.matrix.m[3][3] = 1.0f;
            kWorld.FUN_004b4880(work.inverse);
            point = apTargetLight->m_kWorldDirection;
            CopyPoint24(point, *work.inverse.FUN_00524c40(&work.modelWorldDirection, point));
            FUN_00b71a40((float*)&work.matrix,
                         *((NiMatrix3_ext*)&kWorld.m_kOrientation)
                              ->FUN_004768c0(&work.inverseWorldRotation)
                              ->FUN_0043f8d0(&work.modelWorldRotation, apTargetLight->m_kLightRotate),
                         point, 1.0f);
            CopyMatrix(apConstantData, &work.matrix);
            return true;
        }
        CopyMatrix(apConstantData, &work.identity);
        return false;
    }
    default:
        fnv_zlib_memset(apConstantData, 0, uiConstantDataSize);
        return false;
    }
}

struct S00e85c40_Tex
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    void* m_10;
    unsigned char unk14;
    unsigned char m_15;
    unsigned char unk16;
    unsigned char unk17;
    unsigned int m_18;
};

struct S00e85c40_Obj
{
    virtual void s00();
    virtual void s01();
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void s07();
    virtual void s08();
    virtual void s09();
    virtual void s0a();
    virtual void s0b();
    virtual void s0c();
    virtual void s0d();
    virtual void s0e();
    virtual void s0f();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s1a();
    virtual void s1b();
    virtual void s1c();
    virtual bool s1d(S00e85c40_Tex* t, void* data, int flag);
};

extern unsigned int DAT_011f5f90[];
extern char DAT_0126f770;
unsigned int __cdecl GetLightByType(unsigned int a, unsigned int b, unsigned int c);
bool __cdecl FillLightConstantData(void* data, unsigned int pitch, void* src, unsigned int fmt, int p3, int p4, int p5,
                                   int p6, int p7, unsigned int p8, int p9, int p10, int p11);

static unsigned int Dbl(unsigned int x)
{
    return x + x;
}

// Gets a format and dimensions, calls FillLightConstantData with the source and derived pitch, then passes the buffer to obj->s1d.
// @fnv 0x00e85c40
int __stdcall FUN_00e85c40(S00e85c40_Obj* obj, S00e85c40_Tex* tex, int p3, int p4, int p5, int p6, int p7,
                           unsigned int auiLightType, int p9, int p10, int p11)
{
    int result = 0;
    unsigned int m18 = tex->m_18;
    unsigned int idx = tex->m_15;
    unsigned int uiTableEntry = DAT_011f5f90[idx];
    unsigned int fmt = GetLightByType(auiLightType, uiTableEntry, m18);
    void* src = tex->m_10;
    unsigned int w, h;
    if (!GetAttributeTypeForMapping(src, &w, &h))
        return 0x10;
    unsigned int pitch = Dbl(Dbl(Dbl(Dbl(w))));
    if (!FillLightConstantData(&DAT_0126f770, pitch, src, fmt, p3, p4, p5, p6, p7, auiLightType, p9, p10, p11))
        result = 0x60;
    if (!obj->s1d(tex, &DAT_0126f770, 0))
        result = 0x50;
    return result;
}

struct GlobalObjectO2_00a7b610
{
    char pad_000[0x5c];
    float large[16];
    char pad_09c[0x40];
    float small[4];
};

struct FUN_00e86a50_object
{
    char pad_00[0x14];
    unsigned int type;
    char pad_18[0x18];
    float* data;
};

// Copies the float data from object into the matching slot of g_0126f7c4 based on the type code and returns that code.
// @fnv 0x00e86a50
unsigned int __stdcall FUN_00e86a50(unsigned int index, FUN_00e86a50_object* object, unsigned int unused)
{
    float* source = object->data;
    unsigned int type = DAT_011f5fc4[object->type & 0xff];

    if (type == 3)
    {
        g_0126f7c4.small[index * 4] = source[0];
        return type;
    }

    if (type == 4)
    {
        g_0126f7c4.small[index * 4] = source[0];
        return 4;
    }

    if (type == 5)
    {
        g_0126f7c4.small[index * 4] = source[0];
        g_0126f7c4.small[index * 4 + 1] = source[1];
        return 5;
    }

    if (type == 6)
    {
        g_0126f7c4.small[index * 4] = source[0];
        g_0126f7c4.small[index * 4 + 1] = source[1];
        g_0126f7c4.small[index * 4 + 2] = source[2];
        return 6;
    }

    if (type == 7)
    {
        g_0126f7c4.small[index * 4] = source[0];
        g_0126f7c4.small[index * 4 + 1] = source[1];
        g_0126f7c4.small[index * 4 + 2] = source[2];
        g_0126f7c4.small[index * 4 + 3] = source[3];
        return 7;
    }

    if (type == 8)
    {
        float zero = 0.0f;
        g_0126f7c4.large[index * 16] = source[0];
        g_0126f7c4.large[index * 16 + 1] = source[1];
        g_0126f7c4.large[index * 16 + 2] = source[2];
        g_0126f7c4.large[index * 16 + 3] = zero;
        g_0126f7c4.large[index * 16 + 4] = source[3];
        g_0126f7c4.large[index * 16 + 5] = source[4];
        g_0126f7c4.large[index * 16 + 6] = source[5];
        g_0126f7c4.large[index * 16 + 7] = zero;
        g_0126f7c4.large[index * 16 + 8] = source[6];
        g_0126f7c4.large[index * 16 + 9] = source[7];
        g_0126f7c4.large[index * 16 + 10] = source[8];
        g_0126f7c4.large[index * 16 + 11] = zero;
        g_0126f7c4.large[index * 16 + 12] = zero;
        g_0126f7c4.large[index * 16 + 13] = zero;
        g_0126f7c4.large[index * 16 + 14] = zero;
        g_0126f7c4.large[index * 16 + 15] = 1.0f;
        return 8;
    }

    if (type == 9)
    {
        g_0126f7c4.large[index * 16] = source[0];
        g_0126f7c4.large[index * 16 + 1] = source[1];
        g_0126f7c4.large[index * 16 + 2] = source[2];
        g_0126f7c4.large[index * 16 + 3] = source[3];
        g_0126f7c4.large[index * 16 + 4] = source[4];
        g_0126f7c4.large[index * 16 + 5] = source[5];
        g_0126f7c4.large[index * 16 + 6] = source[6];
        g_0126f7c4.large[index * 16 + 7] = source[7];
        g_0126f7c4.large[index * 16 + 8] = source[8];
        g_0126f7c4.large[index * 16 + 9] = source[9];
        g_0126f7c4.large[index * 16 + 10] = source[10];
        g_0126f7c4.large[index * 16 + 11] = source[11];
        g_0126f7c4.large[index * 16 + 12] = source[12];
        g_0126f7c4.large[index * 16 + 13] = source[13];
        g_0126f7c4.large[index * 16 + 14] = source[14];
        g_0126f7c4.large[index * 16 + 15] = source[15];
        return 9;
    }

    if (type == 10)
    {
        g_0126f7c4.small[index * 4] = source[0];
        g_0126f7c4.small[index * 4 + 1] = source[1];
        g_0126f7c4.small[index * 4 + 2] = source[2];
        g_0126f7c4.small[index * 4 + 3] = source[3];
        return 10;
    }

    return 0;
}

struct SCFixedString
{
    const char* m_kHandle;
};

struct SCExtraData;

struct SCGeometry
{
    SCExtraData* GetExtraData(const SCFixedString& arKey);
};

struct SCMapEntry
{
    int unk00;
    int unk04;
    int unk08;
    SCFixedString m_kControlPoint;
    int unk10;
    unsigned int m_uiValue1;
};

extern unsigned int g_auiSCAttributeTypes[256];
extern float g_afSCVectorConstants[][4];
extern float g_afSCMatrixConstants[][16];

struct SCConstantMap
{
    void* GetExtraDataPtr(SCMapEntry* apEntry, SCExtraData* apExtra);
    int LoadConstant(unsigned int auiRegister, SCMapEntry* apEntry, SCGeometry* apGeometry, void* apSkin,
                     void* apPartition, void* apBuffData, unsigned int auiPass, void* apState);
};

// @fnv 0x00e86ca0
int SCConstantMap::LoadConstant(unsigned int auiRegister, SCMapEntry* apEntry, SCGeometry* apGeometry, void* apSkin,
                                void* apPartition, void* apBuffData, unsigned int auiPass, void* apState)
{
    if (!apGeometry)
        return 1;

    SCExtraData* pExtraData = apGeometry->GetExtraData(apEntry->m_kControlPoint);
    if (!pExtraData)
        return 0x10;

    void* pData = GetExtraDataPtr(apEntry, pExtraData);
    unsigned int uiType = g_auiSCAttributeTypes[apEntry->m_uiValue1 & 0xff];
    if (uiType == 3)
    {
        g_afSCVectorConstants[auiRegister][0] = (float)*(unsigned int*)pData;
        return 3;
    }
    else if (uiType == 4)
    {
        g_afSCVectorConstants[auiRegister][0] = *(float*)pData;
        return 4;
    }
    else if (uiType == 5)
    {
        float* pf = (float*)pData;
        g_afSCVectorConstants[auiRegister][0] = pf[0];
        g_afSCVectorConstants[auiRegister][1] = pf[1];
        return 5;
    }
    else if (uiType == 6)
    {
        float* pf = (float*)pData;
        g_afSCVectorConstants[auiRegister][0] = pf[0];
        g_afSCVectorConstants[auiRegister][1] = pf[1];
        g_afSCVectorConstants[auiRegister][2] = pf[2];
        return 6;
    }
    else if (uiType == 7)
    {
        float* pf = (float*)pData;
        g_afSCVectorConstants[auiRegister][0] = pf[0];
        g_afSCVectorConstants[auiRegister][1] = pf[1];
        g_afSCVectorConstants[auiRegister][2] = pf[2];
        g_afSCVectorConstants[auiRegister][3] = pf[3];
        return 7;
    }
    else if (uiType == 8)
    {
        float* pf = (float*)pData;
        g_afSCMatrixConstants[auiRegister][0] = pf[0];
        g_afSCMatrixConstants[auiRegister][1] = pf[1];
        g_afSCMatrixConstants[auiRegister][2] = pf[2];
        g_afSCMatrixConstants[auiRegister][3] = 0.0f;
        g_afSCMatrixConstants[auiRegister][4] = pf[3];
        g_afSCMatrixConstants[auiRegister][5] = pf[4];
        g_afSCMatrixConstants[auiRegister][6] = pf[5];
        g_afSCMatrixConstants[auiRegister][7] = 0.0f;
        g_afSCMatrixConstants[auiRegister][8] = pf[6];
        g_afSCMatrixConstants[auiRegister][9] = pf[7];
        g_afSCMatrixConstants[auiRegister][10] = pf[8];
        g_afSCMatrixConstants[auiRegister][11] = 0.0f;
        g_afSCMatrixConstants[auiRegister][12] = 0.0f;
        g_afSCMatrixConstants[auiRegister][13] = 0.0f;
        g_afSCMatrixConstants[auiRegister][14] = 0.0f;
        g_afSCMatrixConstants[auiRegister][15] = 1.0f;
        return 8;
    }
    else if (uiType == 9)
    {
        float* pf = (float*)pData;
        g_afSCMatrixConstants[auiRegister][0] = pf[0];
        g_afSCMatrixConstants[auiRegister][1] = pf[1];
        g_afSCMatrixConstants[auiRegister][2] = pf[2];
        g_afSCMatrixConstants[auiRegister][3] = pf[3];
        g_afSCMatrixConstants[auiRegister][4] = pf[4];
        g_afSCMatrixConstants[auiRegister][5] = pf[5];
        g_afSCMatrixConstants[auiRegister][6] = pf[6];
        g_afSCMatrixConstants[auiRegister][7] = pf[7];
        g_afSCMatrixConstants[auiRegister][8] = pf[8];
        g_afSCMatrixConstants[auiRegister][9] = pf[9];
        g_afSCMatrixConstants[auiRegister][10] = pf[10];
        g_afSCMatrixConstants[auiRegister][11] = pf[11];
        g_afSCMatrixConstants[auiRegister][12] = pf[12];
        g_afSCMatrixConstants[auiRegister][13] = pf[13];
        g_afSCMatrixConstants[auiRegister][14] = pf[14];
        g_afSCMatrixConstants[auiRegister][15] = pf[15];
        return 9;
    }
    else if (uiType == 10)
    {
        float* pf = (float*)pData;
        g_afSCVectorConstants[auiRegister][0] = pf[0];
        g_afSCVectorConstants[auiRegister][1] = pf[1];
        g_afSCVectorConstants[auiRegister][2] = pf[2];
        g_afSCVectorConstants[auiRegister][3] = pf[3];
        return 10;
    }
    return 0;
}

typedef NiPointer<NiShaderConstantMapEntry> S_00e86f40_Ptr;
struct S_00e86f40_Arr
{
    void* unk00;
    S_00e86f40_Ptr* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usESize;
    unsigned short m_usElementCount;
    unsigned short m_usGrowBy;
    void FUN_00e86f40(unsigned int i, const S_00e86f40_Ptr& e);
};

// @fnv 0x00e86f40
void S_00e86f40_Arr::FUN_00e86f40(unsigned int uiIndex, const S_00e86f40_Ptr& e)
{
    static const S_00e86f40_Ptr kEmpty;
    if (uiIndex >= m_usESize)
    {
        m_usESize = (unsigned short)(uiIndex + 1);
        if (e.p != kEmpty.p)
        {
            m_usElementCount++;
        }
    }
    else if (e.p != kEmpty.p)
    {
        if (m_pBase[uiIndex].p == kEmpty.p)
        {
            m_usElementCount++;
        }
    }
    else
    {
        if (m_pBase[uiIndex].p != kEmpty.p)
        {
            m_usElementCount--;
        }
    }
    m_pBase[uiIndex] = e;
}

typedef NiPointer<NiShaderConstantMapEntry> NiShaderConstantMapEntryPtr;

struct ShaderEntryArray : NiTObjectArray<NiShaderConstantMapEntryPtr>
{
    __declspec(nothrow) void FUN_00e86f40(unsigned int uiIndex, const NiShaderConstantMapEntryPtr& element) throw();
};

void ShaderEntryArray::FUN_00e86f40(unsigned int uiIndex, const NiShaderConstantMapEntryPtr& element) throw()
{
    static NiShaderConstantMapEntryPtr s_spNull;
    if (uiIndex >= size)
    {
        size = (unsigned short)(uiIndex + 1);
        if (element != s_spNull)
            ++count;
    }
    else if (element != s_spNull)
    {
        if (data[uiIndex] == s_spNull)
            ++count;
    }
    else if (data[uiIndex] != s_spNull)
    {
        --count;
    }
    data[uiIndex] = element;
}

// Moves enabled shader constant map entries to the front of the array, leaving disabled entries at the end.
// @fnv 0x00e870c0
void __stdcall CompactEnabledEntries(ShaderEntryArray* pkArray)
{
    NiShaderConstantMapEntryPtr spEntry;
    unsigned int uiSize = pkArray->size;
    unsigned int uiFirstDisabled = ~0u;
    if (uiSize <= 1)
        return;
    for (unsigned int uiIndex = 0; uiIndex < uiSize; ++uiIndex)
    {
        spEntry = pkArray->GetAt(uiIndex);
        if (!spEntry)
            continue;
        if (spEntry.p->enabled == true)
        {
            if (uiFirstDisabled < uiIndex)
            {
                pkArray->FUN_00e86f40(uiIndex, pkArray->GetAt(uiFirstDisabled));
                pkArray->FUN_00e86f40(uiFirstDisabled, spEntry);
                ++uiFirstDisabled;
                while (uiFirstDisabled < uiSize)
                {
                    spEntry = pkArray->GetAt(uiFirstDisabled);
                    if (!spEntry.p->enabled)
                        break;
                    ++uiFirstDisabled;
                }
                if (uiFirstDisabled >= uiSize)
                    return;
            }
        }
        else if (uiFirstDisabled > uiIndex)
        {
            uiFirstDisabled = uiIndex;
        }
    }
}

struct OpCFixedString
{
    const char* m_handle;
    operator const char*() const
    {
        return m_handle;
    }
};

struct OpCEntry
{
    virtual ~OpCEntry();
    unsigned int m_uiRefCount;
    unsigned int unk08;
    OpCFixedString m_kControlPoint;
    unsigned int unk10;
    unsigned int m_uiValue1;
    unsigned int m_uiValue2;
    const OpCFixedString& GetKey() const
    {
        return m_kControlPoint;
    }
};

extern unsigned int DAT_011f5fc4[];
int __cdecl FUN_00aa0020(int, int, const char*, ...);

struct FUN_00e87220_shell
{
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual OpCEntry* GetOperationEntry(unsigned int uiIndex);

    unsigned int FUN_00e82b40(void* pkShaderProgram, OpCEntry* pkEntry, unsigned int eType1, unsigned int eType2,
                              bool bTranspose, bool bInverse);
    unsigned int FUN_00e82e70(void* pkShaderProgram, OpCEntry* pkEntry, unsigned int eType1, unsigned int eType2,
                              bool bTranspose, bool bInverse);
    unsigned int SetConstantSum(void* pkShaderProgram, OpCEntry* pkEntry, unsigned int eType1, unsigned int eType2,
                                bool bTranspose, bool bInverse);
    unsigned int FUN_00e83320(void* pkShaderProgram, OpCEntry* pkEntry, unsigned int eType1, unsigned int eType2,
                              bool bTranspose, bool bInverse);
    unsigned int FUN_00e85d10(bool bSecond, OpCEntry* pkEntry, void* pkGeometry, const void* pkSkin,
                              const void* pkState, const void* pkEffects, const void* kWorld, const void* kWorldBound);
    unsigned int FUN_00e86a50(bool bSecond, OpCEntry* pkEntry, unsigned int uiPass);
    unsigned int LoadConstant(bool bSecond, OpCEntry* pkEntry, void* pkGeometry, const void* pkSkin,
                              const void* pkState, const void* kWorld, const void* kWorldBound, unsigned int uiPass);

    unsigned int FUN_00e87220(void* pkShaderProgram, OpCEntry* pkEntry, void* pkGeometry, const void* pkSkin,
                              const void* pkState, const void* pkEffects, const void* kWorld, const void* kWorldBound,
                              unsigned int uiPass);
};

// Resolves two operand entries, dispatches their evaluation by type, then applies the operator to the shader program and returns the result.
// @fnv 0x00e87220
unsigned int FUN_00e87220_shell::FUN_00e87220(void* pkShaderProgram, OpCEntry* pkEntry, void* pkGeometry,
                                              const void* pkSkin, const void* pkState, const void* pkEffects,
                                              const void* kWorld, const void* kWorldBound, unsigned int uiPass)
{
    unsigned int uiExtra = pkEntry->m_uiValue2;
    bool bInverse = (uiExtra & 0x02000000) != 0;
    unsigned int uiOperator = uiExtra & 0xf0000000;
    bool bTranspose = (uiExtra & 0x01000000) != 0;
    unsigned int uiOperand1Index = uiExtra & 0xfff;
    unsigned int uiOperand2Index = (uiExtra >> 12) & 0xfff;

    OpCEntry* pkEntry1 = GetOperationEntry(uiOperand1Index);
    OpCEntry* pkEntry2 = GetOperationEntry(uiOperand2Index);
    if (!pkEntry1 || !pkEntry2)
    {
        FUN_00aa0020(1, 0, "Invalid entries in OperatorConstant\n");
        return 1;
    }

    unsigned int eType1 = DAT_011f5fc4[pkEntry1->m_uiValue1 & 0xff];
    unsigned int eType2 = DAT_011f5fc4[pkEntry2->m_uiValue1 & 0xff];

    if ((pkEntry1->m_uiValue1 & 0xf0000000) == 0x20000000)
    {
        eType1 = FUN_00a9c0a0(pkEntry1->GetKey());
        FUN_00e85d10(false, pkEntry1, pkGeometry, pkSkin, pkState, pkEffects, kWorld, kWorldBound);
    }
    else
    {
        unsigned int uiOperand1Type = pkEntry1->m_uiValue1 & 0xf0000000;
        if (uiOperand1Type == 0x40000000)
        {
            FUN_00e86a50(false, pkEntry1, uiPass);
        }
        else if (uiOperand1Type == 0x30000000)
        {
            LoadConstant(false, pkEntry1, pkGeometry, pkSkin, pkState, kWorld, kWorldBound, uiPass);
        }
        else if (uiOperand1Type == 0x10000000)
        {
            LoadConstant(false, pkEntry1, pkGeometry, pkSkin, pkState, kWorld, kWorldBound, uiPass);
        }
    }

    unsigned int uiOperand2Type = pkEntry2->m_uiValue1 & 0xf0000000;
    if (uiOperand2Type == 0x20000000)
    {
        eType2 = FUN_00a9c0a0(pkEntry2->GetKey());
        FUN_00e85d10(true, pkEntry2, pkGeometry, pkSkin, pkState, pkEffects, kWorld, kWorldBound);
    }
    else if (uiOperand2Type == 0x30000000)
    {
        LoadConstant(true, pkEntry2, pkGeometry, pkSkin, pkState, kWorld, kWorldBound, uiPass);
    }
    else if (uiOperand2Type == 0x40000000)
    {
        FUN_00e86a50(true, pkEntry2, uiPass);
    }
    else if (uiOperand2Type == 0x10000000)
    {
        FUN_00e86a50(true, pkEntry2, uiPass);
    }

    if (!eType1 || !eType2)
    {
        FUN_00aa0020(1, 0, "Invalid operands in OperatorConstant\n");
        return 1;
    }

    switch (uiOperator)
    {
    case 0x10000000:
        return FUN_00e82b40(pkShaderProgram, pkEntry, eType1, eType2, bTranspose, bInverse);
    case 0x20000000:
        return FUN_00e82e70(pkShaderProgram, pkEntry, eType1, eType2, bTranspose, bInverse);
    case 0x30000000:
        return SetConstantSum(pkShaderProgram, pkEntry, eType1, eType2, bTranspose, bInverse);
    case 0x40000000:
        return FUN_00e83320(pkShaderProgram, pkEntry, eType1, eType2, bTranspose, bInverse);
    }
    return 1;
}

#include <math.h>
struct __declspec(align(16)) S83_Matrix
{
    float m[4][4];
};
struct Vec2
{
    float x, y;
};
union PairScratch
{
    Vec2 pair;
    float time;
    bool inverse;
};
union ScalarScratch
{
    Vec2 rgb;
    float scalar;
    bool transpose;
    unsigned int integer;
};
struct __declspec(align(16)) Vec4
{
    float x, y, z, w;
};
S83_Matrix* __stdcall FUN_00ee6dda(S83_Matrix*, float*, const S83_Matrix*);
S83_Matrix* __stdcall FUN_00ee6dd4(S83_Matrix*, const S83_Matrix*);
S83_Matrix* __stdcall FUN_00ee6de0(S83_Matrix*, const S83_Matrix*, const S83_Matrix*);
S83_Matrix* __stdcall FUN_00ee6dfe(S83_Matrix*, const S83_Matrix*, const S83_Matrix*);
void __cdecl SetAffineMatrix(S83_Matrix*, const char*, bool, bool, unsigned int);
extern float DAT_01099378;
extern "C" double __cdecl sin(double);
extern "C" double __cdecl cos(double);
extern "C" double __cdecl tan(double);

struct Entry
{
    unsigned int u00, u04, u08, u0c, type, u14, index;
};
struct Program : FUN_00e84b60_prog
{
    virtual bool SetSkin(Entry*, void*, unsigned int, void*, void*);
};
struct Texture
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual unsigned int Width();
    virtual unsigned int Height();
};
struct Bump
{
    float x, y, z, w;
};
struct TextureLayer
{
    unsigned int u00, u04;
    Texture* texture;
    char* transform;
    float value;
    float angle;
    Bump bump;
};
struct TexArray
{
    TextureLayer* slots[8];
    TextureLayer* extra[1];
};
struct TexProperty
{
    unsigned int u00, u04, u08, u0c, u10, u14, u18, u1c;
    TexArray* textures;
    TextureLayer* GetElementAt(unsigned int);
};
struct Material
{
    unsigned int u00, u04, u08, u0c, u10, u14, u18;
    NiPoint3 diffuse, specular;
    NiPoint3* specularOverride;
    float gloss, alpha;
    __forceinline const NiPoint3& GetSpecular() const
    {
        return specularOverride ? *specularOverride : specular;
    }
};
struct Properties
{
    unsigned int u00, u04;
    Material* material;
    unsigned int u0c, u10;
    TexProperty* tex;
};
struct Skin
{
    unsigned int u00, u04, u08, u0c, u10, u14, u18, u1c;
    void* data;
    unsigned int u24;
    void* matrices;
};
struct Partition
{
    unsigned int u00;
    void* palette;
    unsigned int u08, u0c, u10, u14, u18, u1c;
    unsigned short count;
};
struct S83_FixedStr
{
    const char* str;
    __declspec(nothrow) S83_FixedStr(const char*) throw();
    __declspec(nothrow) ~S83_FixedStr() throw();
};
class NiExtraData
{
  public:
    unsigned int u00, u04, u08;
    float value;
};
struct Geometry
{
    __declspec(nothrow) NiExtraData* FUN_00a5bdd0(const S83_FixedStr&) throw();
};
extern const char* DAT_011bf65c;
extern NiPoint3 DAT_011f4998;
extern unsigned int DAT_011f5f6c;
struct Light
{
    void* FUN_00653290(const unsigned int*);
};
struct LightValue
{
    unsigned int u00;
    unsigned int u04;
    unsigned int u08;
    unsigned int u0c;
    unsigned int u10;
    unsigned int u14;
    unsigned int u18;
    unsigned int u1c;
    unsigned int u20;
    unsigned int u24;
    unsigned int u28;
    unsigned int u2c;
    unsigned int u30;
    unsigned int u34;
    unsigned int u38;
    unsigned int u3c;
    unsigned int u40;
    unsigned int u44;
    unsigned int u48;
    unsigned int u4c;
    unsigned int u50;
    unsigned int u54;
    unsigned int u58;
    unsigned int u5c;
    unsigned int u60;
    unsigned int u64;
    unsigned int u68;
    unsigned int u6c;
    unsigned int u70;
    unsigned int u74;
    unsigned int u78;
    unsigned int u7c;
    unsigned int u80;
    unsigned int u84;
    unsigned int u88;
    unsigned int u8c;
    unsigned int u90;
    unsigned int u94;
    unsigned int u98;
    unsigned int u9c;
    unsigned int ua0;
    unsigned int ua4;
    unsigned int ua8;
    unsigned int uac;
    unsigned int ub0;
    unsigned int ub4;
    unsigned int ub8;
    unsigned int ubc;
    unsigned int uc0;
    float brightness;
    NiPoint3 color;
};
struct PointOps
{
    float x, y, z;
    NiPoint3 ScaleTo(float);
};
struct LightLink
{
    LightLink* next;
    Light* light;
};
struct Effects
{
    unsigned int u00, u04, u08;
    LightLink* lights;
};
struct Renderer
{
    unsigned int u000;
    unsigned int u004;
    unsigned int u008;
    unsigned int u00c;
    unsigned int u010;
    unsigned int u014;
    unsigned int u018;
    unsigned int u01c;
    unsigned int u020;
    unsigned int u024;
    unsigned int u028;
    unsigned int u02c;
    unsigned int u030;
    unsigned int u034;
    unsigned int u038;
    unsigned int u03c;
    unsigned int u040;
    unsigned int u044;
    unsigned int u048;
    unsigned int u04c;
    unsigned int u050;
    unsigned int u054;
    unsigned int u058;
    unsigned int u05c;
    unsigned int u060;
    unsigned int u064;
    unsigned int u068;
    unsigned int u06c;
    unsigned int u070;
    unsigned int u074;
    unsigned int u078;
    unsigned int u07c;
    unsigned int u080;
    unsigned int u084;
    unsigned int u088;
    unsigned int u08c;
    unsigned int u090;
    unsigned int u094;
    unsigned int u098;
    unsigned int u09c;
    unsigned int u0a0;
    unsigned int u0a4;
    unsigned int u0a8;
    unsigned int u0ac;
    unsigned int u0b0;
    unsigned int u0b4;
    unsigned int u0b8;
    unsigned int u0bc;
    unsigned int u0c0;
    unsigned int u0c4;
    unsigned int u0c8;
    unsigned int u0cc;
    unsigned int u0d0;
    unsigned int u0d4;
    unsigned int u0d8;
    unsigned int u0dc;
    unsigned int u0e0;
    unsigned int u0e4;
    unsigned int u0e8;
    unsigned int u0ec;
    unsigned int u0f0;
    unsigned int u0f4;
    unsigned int u0f8;
    unsigned int u0fc;
    unsigned int u100;
    unsigned int u104;
    unsigned int u108;
    unsigned int u10c;
    unsigned int u110;
    unsigned int u114;
    unsigned int u118;
    unsigned int u11c;
    unsigned int u120;
    unsigned int u124;
    unsigned int u128;
    unsigned int u12c;
    unsigned int u130;
    unsigned int u134;
    unsigned int u138;
    unsigned int u13c;
    unsigned int u140;
    unsigned int u144;
    unsigned int u148;
    unsigned int u14c;
    unsigned int u150;
    unsigned int u154;
    unsigned int u158;
    unsigned int u15c;
    unsigned int u160;
    unsigned int u164;
    unsigned int u168;
    unsigned int u16c;
    unsigned int u170;
    unsigned int u174;
    unsigned int u178;
    unsigned int u17c;
    unsigned int u180;
    unsigned int u184;
    unsigned int u188;
    unsigned int u18c;
    unsigned int u190;
    unsigned int u194;
    unsigned int u198;
    unsigned int u19c;
    unsigned int u1a0;
    unsigned int u1a4;
    unsigned int u1a8;
    unsigned int u1ac;
    unsigned int u1b0;
    unsigned int u1b4;
    unsigned int u1b8;
    unsigned int u1bc;
    unsigned int u1c0;
    unsigned int u1c4;
    unsigned int u1c8;
    unsigned int u1cc;
    unsigned int u1d0;
    unsigned int u1d4;
    unsigned int u1d8;
    unsigned int u1dc;
    unsigned int u1e0;
    unsigned int u1e4;
    unsigned int u1e8;
    unsigned int u1ec;
    unsigned int u1f0;
    unsigned int u1f4;
    unsigned int u1f8;
    unsigned int u1fc;
    unsigned int u200;
    unsigned int u204;
    unsigned int u208;
    unsigned int u20c;
    unsigned int u210;
    unsigned int u214;
    unsigned int u218;
    unsigned int u21c;
    unsigned int u220;
    unsigned int u224;
    unsigned int u228;
    unsigned int u22c;
    unsigned int u230;
    unsigned int u234;
    unsigned int u238;
    unsigned int u23c;
    unsigned int u240;
    unsigned int u244;
    unsigned int u248;
    unsigned int u24c;
    unsigned int u250;
    unsigned int u254;
    unsigned int u258;
    unsigned int u25c;
    unsigned int u260;
    unsigned int u264;
    unsigned int u268;
    unsigned int u26c;
    unsigned int u270;
    unsigned int u274;
    unsigned int u278;
    unsigned int u27c;
    unsigned int u280;
    unsigned int u284;
    unsigned int u288;
    unsigned int u28c;
    unsigned int u290;
    unsigned int u294;
    unsigned int u298;
    unsigned int u29c;
    unsigned int u2a0;
    unsigned int u2a4;
    unsigned int u2a8;
    unsigned int u2ac;
    unsigned int u2b0;
    unsigned int u2b4;
    unsigned int u2b8;
    unsigned int u2bc;
    unsigned int u2c0;
    unsigned int u2c4;
    unsigned int u2c8;
    unsigned int u2cc;
    unsigned int u2d0;
    unsigned int u2d4;
    unsigned int u2d8;
    unsigned int u2dc;
    unsigned int u2e0;
    unsigned int u2e4;
    unsigned int u2e8;
    unsigned int u2ec;
    unsigned int u2f0;
    unsigned int u2f4;
    unsigned int u2f8;
    unsigned int u2fc;
    unsigned int u300;
    unsigned int u304;
    unsigned int u308;
    unsigned int u30c;
    unsigned int u310;
    unsigned int u314;
    unsigned int u318;
    unsigned int u31c;
    unsigned int u320;
    unsigned int u324;
    unsigned int u328;
    unsigned int u32c;
    unsigned int u330;
    unsigned int u334;
    unsigned int u338;
    unsigned int u33c;
    unsigned int u340;
    unsigned int u344;
    unsigned int u348;
    unsigned int u34c;
    unsigned int u350;
    unsigned int u354;
    unsigned int u358;
    unsigned int u35c;
    unsigned int u360;
    unsigned int u364;
    unsigned int u368;
    unsigned int u36c;
    unsigned int u370;
    unsigned int u374;
    unsigned int u378;
    unsigned int u37c;
    unsigned int u380;
    unsigned int u384;
    unsigned int u388;
    unsigned int u38c;
    unsigned int u390;
    unsigned int u394;
    unsigned int u398;
    unsigned int u39c;
    unsigned int u3a0;
    unsigned int u3a4;
    unsigned int u3a8;
    unsigned int u3ac;
    unsigned int u3b0;
    unsigned int u3b4;
    unsigned int u3b8;
    unsigned int u3bc;
    unsigned int u3c0;
    unsigned int u3c4;
    unsigned int u3c8;
    unsigned int u3cc;
    unsigned int u3d0;
    unsigned int u3d4;
    unsigned int u3d8;
    unsigned int u3dc;
    unsigned int u3e0;
    unsigned int u3e4;
    unsigned int u3e8;
    unsigned int u3ec;
    unsigned int u3f0;
    unsigned int u3f4;
    unsigned int u3f8;
    unsigned int u3fc;
    unsigned int u400;
    unsigned int u404;
    unsigned int u408;
    unsigned int u40c;
    unsigned int u410;
    unsigned int u414;
    unsigned int u418;
    unsigned int u41c;
    unsigned int u420;
    unsigned int u424;
    unsigned int u428;
    unsigned int u42c;
    unsigned int u430;
    unsigned int u434;
    unsigned int u438;
    unsigned int u43c;
    unsigned int u440;
    unsigned int u444;
    unsigned int u448;
    unsigned int u44c;
    unsigned int u450;
    unsigned int u454;
    unsigned int u458;
    unsigned int u45c;
    unsigned int u460;
    unsigned int u464;
    unsigned int u468;
    unsigned int u46c;
    unsigned int u470;
    unsigned int u474;
    unsigned int u478;
    unsigned int u47c;
    unsigned int u480;
    unsigned int u484;
    unsigned int u488;
    unsigned int u48c;
    unsigned int u490;
    unsigned int u494;
    unsigned int u498;
    unsigned int u49c;
    unsigned int u4a0;
    unsigned int u4a4;
    unsigned int u4a8;
    unsigned int u4ac;
    unsigned int u4b0;
    unsigned int u4b4;
    unsigned int u4b8;
    unsigned int u4bc;
    unsigned int u4c0;
    unsigned int u4c4;
    unsigned int u4c8;
    unsigned int u4cc;
    unsigned int u4d0;
    unsigned int u4d4;
    unsigned int u4d8;
    unsigned int u4dc;
    unsigned int u4e0;
    unsigned int u4e4;
    unsigned int u4e8;
    unsigned int u4ec;
    unsigned int u4f0;
    unsigned int u4f4;
    unsigned int u4f8;
    unsigned int u4fc;
    unsigned int u500;
    unsigned int u504;
    unsigned int u508;
    unsigned int u50c;
    unsigned int u510;
    unsigned int u514;
    unsigned int u518;
    unsigned int u51c;
    unsigned int u520;
    unsigned int u524;
    unsigned int u528;
    unsigned int u52c;
    unsigned int u530;
    unsigned int u534;
    unsigned int u538;
    unsigned int u53c;
    unsigned int u540;
    unsigned int u544;
    unsigned int u548;
    unsigned int u54c;
    unsigned int u550;
    unsigned int u554;
    unsigned int u558;
    unsigned int u55c;
    unsigned int u560;
    unsigned int u564;
    unsigned int u568;
    unsigned int u56c;
    unsigned int u570;
    unsigned int u574;
    unsigned int u578;
    unsigned int u57c;
    unsigned int u580;
    unsigned int u584;
    unsigned int u588;
    unsigned int u58c;
    unsigned int u590;
    unsigned int u594;
    unsigned int u598;
    unsigned int u59c;
    unsigned int u5a0;
    unsigned int u5a4;
    unsigned int u5a8;
    unsigned int u5ac;
    unsigned int u5b0;
    unsigned int u5b4;
    unsigned int u5b8;
    unsigned int u5bc;
    unsigned int u5c0;
    unsigned int u5c4;
    unsigned int u5c8;
    unsigned int u5cc;
    unsigned int u5d0;
    unsigned int u5d4;
    unsigned int u5d8;
    unsigned int u5dc;
    unsigned int u5e0;
    unsigned int u5e4;
    unsigned int u5e8;
    unsigned int u5ec;
    unsigned int u5f0;
    unsigned int u5f4;
    unsigned int u5f8;
    unsigned int u5fc;
    unsigned int u600;
    unsigned int u604;
    unsigned int u608;
    unsigned int u60c;
    unsigned int u610;
    unsigned int u614;
    unsigned int u618;
    unsigned int u61c;
    unsigned int u620;
    unsigned int u624;
    unsigned int u628;
    unsigned int u62c;
    unsigned int u630;
    unsigned int u634;
    unsigned int u638;
    unsigned int u63c;
    unsigned int u640;
    unsigned int u644;
    unsigned int u648;
    unsigned int u64c;
    unsigned int u650;
    unsigned int u654;
    unsigned int u658;
    unsigned int u65c;
    unsigned int u660;
    unsigned int u664;
    unsigned int u668;
    unsigned int u66c;
    unsigned int u670;
    unsigned int u674;
    unsigned int u678;
    unsigned int u67c;
    unsigned int u680;
    unsigned int u684;
    unsigned int u688;
    unsigned int u68c;
    unsigned int u690;
    unsigned int u694;
    unsigned int u698;
    unsigned int u69c;
    unsigned int u6a0;
    unsigned int u6a4;
    unsigned int u6a8;
    unsigned int u6ac;
    unsigned int u6b0;
    unsigned int u6b4;
    unsigned int u6b8;
    unsigned int u6bc;
    unsigned int u6c0;
    unsigned int u6c4;
    unsigned int u6c8;
    unsigned int u6cc;
    unsigned int u6d0;
    unsigned int u6d4;
    unsigned int u6d8;
    unsigned int u6dc;
    unsigned int u6e0;
    unsigned int u6e4;
    unsigned int u6e8;
    unsigned int u6ec;
    unsigned int u6f0;
    unsigned int u6f4;
    unsigned int u6f8;
    unsigned int u6fc;
    unsigned int u700;
    unsigned int u704;
    unsigned int u708;
    unsigned int u70c;
    unsigned int u710;
    unsigned int u714;
    unsigned int u718;
    unsigned int u71c;
    unsigned int u720;
    unsigned int u724;
    unsigned int u728;
    unsigned int u72c;
    unsigned int u730;
    unsigned int u734;
    unsigned int u738;
    unsigned int u73c;
    unsigned int u740;
    unsigned int u744;
    unsigned int u748;
    unsigned int u74c;
    unsigned int u750;
    unsigned int u754;
    unsigned int u758;
    unsigned int u75c;
    unsigned int u760;
    unsigned int u764;
    unsigned int u768;
    unsigned int u76c;
    unsigned int u770;
    unsigned int u774;
    unsigned int u778;
    unsigned int u77c;
    unsigned int u780;
    unsigned int u784;
    unsigned int u788;
    unsigned int u78c;
    unsigned int u790;
    unsigned int u794;
    unsigned int u798;
    unsigned int u79c;
    unsigned int u7a0;
    unsigned int u7a4;
    unsigned int u7a8;
    unsigned int u7ac;
    unsigned int u7b0;
    unsigned int u7b4;
    unsigned int u7b8;
    unsigned int u7bc;
    unsigned int u7c0;
    unsigned int u7c4;
    unsigned int u7c8;
    unsigned int u7cc;
    unsigned int u7d0;
    unsigned int u7d4;
    unsigned int u7d8;
    unsigned int u7dc;
    unsigned int u7e0;
    unsigned int u7e4;
    unsigned int u7e8;
    unsigned int u7ec;
    unsigned int u7f0;
    unsigned int u7f4;
    unsigned int u7f8;
    unsigned int u7fc;
    unsigned int u800;
    unsigned int u804;
    unsigned int u808;
    unsigned int u80c;
    unsigned int u810;
    unsigned int u814;
    unsigned int u818;
    unsigned int u81c;
    unsigned int u820;
    unsigned int u824;
    unsigned int u828;
    unsigned int u82c;
    unsigned int u830;
    unsigned int u834;
    unsigned int u838;
    unsigned int u83c;
    unsigned int u840;
    unsigned int u844;
    unsigned int u848;
    unsigned int u84c;
    unsigned int u850;
    unsigned int u854;
    unsigned int u858;
    unsigned int u85c;
    unsigned int u860;
    unsigned int u864;
    unsigned int u868;
    unsigned int u86c;
    unsigned int u870;
    unsigned int u874;
    unsigned int u878;
    unsigned int u87c;
    unsigned int u880;
    unsigned int u884;
    unsigned int u888;
    unsigned int u88c;
    unsigned int u890;
    unsigned int u894;
    unsigned int u898;
    unsigned int u89c;
    unsigned int u8a0;
    unsigned int u8a4;
    unsigned int u8a8;
    unsigned int u8ac;
    unsigned int u8b0;
    unsigned int u8b4;
    unsigned int u8b8;
    unsigned int u8bc;
    unsigned int u8c0;
    unsigned int u8c4;
    unsigned int u8c8;
    unsigned int u8cc;
    unsigned int u8d0;
    unsigned int u8d4;
    unsigned int u8d8;
    unsigned int u8dc;
    unsigned int u8e0;
    unsigned int u8e4;
    unsigned int u8e8;
    unsigned int u8ec;
    unsigned int u8f0;
    unsigned int u8f4;
    unsigned int u8f8;
    unsigned int u8fc;
    unsigned int u900;
    unsigned int u904;
    unsigned int u908;
    unsigned int u90c;
    unsigned int u910;
    unsigned int u914;
    unsigned int u918;
    unsigned int u91c;
    unsigned int u920;
    unsigned int u924;
    unsigned int u928;
    unsigned int u92c;
    unsigned int u930;
    unsigned int u934;
    unsigned int u938;
    unsigned int u93c;
    S83_Matrix view, projection, world, adjust, misc;
};
struct ConstantMap
{
    unsigned int u00;
    unsigned int u04;
    unsigned int u08;
    unsigned int u0c;
    unsigned int u10;
    unsigned int u14;
    unsigned int u18;
    unsigned int u1c;
    unsigned int u20;
    unsigned int u24;
    unsigned int u28;
    unsigned int u2c;
    unsigned int u30;
    unsigned int u34;
    unsigned int u38;
    Renderer* renderer;
    unsigned int FUN_00e83db0(Program*, Entry*, Geometry*, Skin*, Partition*, void*, Properties*, Effects*, const void*,
                              const void*, unsigned int);
};
// Writes a shader constant (matrix, vector, or scalar) to the program based on the entry type, applying optional inverse or transpose to renderer matrices.
// @fnv 0x00e83db0
unsigned int ConstantMap::FUN_00e83db0(Program* prog, Entry* entry, Geometry* geom, Skin* skin, Partition* partition,
                                       void* buffer, Properties* props, Effects* effects, const void* transform,
                                       const void* bound, unsigned int pass)
{
    S83_Matrix matA;
    S83_Matrix matB;

    S83_Matrix matResult;
    Vec4 vec4;
    PairScratch pairScratch;

    S83_Matrix* ptr;
    bool bInverse, bTranspose;
    unsigned int result = 0;
    unsigned int type = entry->type;
    switch (type)
    {
    case 1:
    case 2:
    case 13:
    case 14: {
        bInverse = false;
        bTranspose = false;
        if (type == 2 || type == 14)
            bInverse = true;
        if (type == 13 || type == 14)
            bTranspose = true;
        matResult = renderer->world;
        ptr = &matResult;
        if (bInverse)
            FUN_00ee6dda(ptr, 0, ptr);
        if (bTranspose)
            FUN_00ee6dd4(ptr, ptr);
        if (!prog->SetConstant(entry, &matResult, 0))
            result = 0x50;
        goto done;
    }
    case 3:
    case 4:
    case 15:
    case 16: {
        bInverse = false;
        bTranspose = false;
        if (type == 4 || type == 16)
            bInverse = true;
        if (type == 15 || type == 16)
            bTranspose = true;
        matResult = renderer->projection;
        ptr = &matResult;
        if (bInverse)
            FUN_00ee6dda(ptr, 0, ptr);
        if (bTranspose)
            FUN_00ee6dd4(ptr, ptr);
        if (!prog->SetConstant(entry, &matResult, 0))
            result = 0x50;
        goto done;
    }
    case 5:
    case 6:
    case 17:
    case 18: {
        bInverse = false;
        bTranspose = false;
        if (type == 6 || type == 18)
            bInverse = true;
        if (type == 17 || type == 18)
            bTranspose = true;
        matResult = renderer->view;
        ptr = &matResult;
        if (bInverse)
            FUN_00ee6dda(ptr, 0, ptr);
        if (bTranspose)
            FUN_00ee6dd4(ptr, ptr);
        if (!prog->SetConstant(entry, &matResult, 0))
            result = 0x50;
        goto done;
    }
    case 7:
    case 8:
    case 19:
    case 20: {
        bInverse = false;
        bTranspose = false;
        if (type == 8 || type == 20)
            bInverse = true;
        if (type == 19 || type == 20)
            bTranspose = true;
        const void* source = renderer;
        matA = ((const Renderer*)source)->view;
        source = &((const Renderer*)source)->projection;
        matB = *(const S83_Matrix*)source;
        FUN_00ee6de0(&matResult, &matA, &matB);
        ptr = &matResult;
        if (bInverse)
            FUN_00ee6dda(ptr, 0, ptr);
        if (bTranspose)
            FUN_00ee6dd4(ptr, ptr);
        if (!prog->SetConstant(entry, &matResult, 0))
            result = 0x50;
        goto done;
    }
    case 9:
    case 10:
    case 21:
    case 22: {
        bInverse = false;
        bTranspose = false;
        if (type == 10 || type == 22)
            bInverse = true;
        if (type == 21 || type == 22)
            bTranspose = true;
        matB = renderer->projection;
        matA = renderer->world;
        FUN_00ee6de0(&matResult, &matB, &matA);
        ptr = &matResult;
        if (bInverse)
            FUN_00ee6dda(ptr, 0, ptr);
        if (bTranspose)
            FUN_00ee6dd4(ptr, ptr);
        if (!prog->SetConstant(entry, &matResult, 0))
            result = 0x50;
        goto done;
    }
    case 11:
    case 12:
    case 23:
    case 24: {
        FUN_00ee6dfe(&matA, &renderer->view, &renderer->adjust);
        if (!prog->SetConstant(entry, &matA, 0))
            result = 0x50;
        goto done;
    }
    case 25:
    case 26:
    case 27:
    case 28: {
        if (!skin)
            goto done;
        bInverse = false;
        bTranspose = false;
        if (type == 26 || type == 28)
            bInverse = true;
        if (type == 27 || type == 28)
            bTranspose = true;
        matResult = renderer->projection;
        ptr = &matResult;
        if (bInverse)
            FUN_00ee6dda(ptr, 0, ptr);
        if (bTranspose)
            FUN_00ee6dd4(ptr, ptr);
        if (!prog->SetConstant(entry, &matResult, 0))
            result = 0x50;
        goto done;
    }
    case 29:
    case 30:
    case 31:
    case 32: {
        if (!skin)
            goto done;
        bInverse = false;
        bTranspose = false;
        if (type == 30 || type == 32)
            bInverse = true;
        if (type == 31 || type == 32)
            bTranspose = true;
        matB = renderer->projection;
        matA = renderer->world;
        FUN_00ee6de0(&matResult, &matB, &matA);
        ptr = &matResult;
        if (bInverse)
            FUN_00ee6dda(ptr, 0, ptr);
        if (bTranspose)
            FUN_00ee6dd4(ptr, ptr);
        if (!prog->SetConstant(entry, &matResult, 0))
            result = 0x50;
        goto done;
    }
    case 96:
    case 97:
    case 98:
    case 99: {
        if (!skin)
            goto done;
        matResult.m[0][1] = matResult.m[0][2] = matResult.m[0][3] = matResult.m[1][0] = matResult.m[1][2] =
            matResult.m[1][3] = matResult.m[2][0] = matResult.m[2][1] = matResult.m[2][3] = matResult.m[3][0] =
                matResult.m[3][1] = matResult.m[3][2] = 0.0f;
        matResult.m[0][0] = matResult.m[1][1] = matResult.m[2][2] = matResult.m[3][3] = 1.0f;
        bInverse = false;
        bTranspose = false;
        if (type == 97 || type == 99)
            bInverse = true;
        if (type == 98 || type == 99)
            bTranspose = true;
        ptr = &matResult;
        if (bInverse)
            FUN_00ee6dda(ptr, 0, ptr);
        if (bTranspose)
            FUN_00ee6dd4(ptr, ptr);
        if (!prog->SetConstant(entry, &matResult, 0))
            result = 0x50;
        goto done;
    }
    case 33:
    case 35: {
        if (!skin || !partition)
            goto done;
        void* matrices = skin->matrices;
        void* skindata = skin->data;
        if (!prog->SetSkin(entry, matrices, partition->count, skindata, partition->palette))
            result = 0x50;
        goto done;
    }
    case 34:
    case 36: {
        if (!skin)
            goto done;
        void* matrices = skin->matrices;
        void* skindata = skin->data;
        if (!prog->SetSkin(entry, matrices, partition->count, skindata, partition->palette))
            result = 0x50;
        goto done;
    }
        {
            ScalarScratch scalarTemp;
        case 37:
        case 38:
        case 39:
        case 40: {
            TexProperty* tex = props->tex;
            const char* texdata = 0;
            scalarTemp.transpose = false;
            pairScratch.inverse = false;
            if (tex)
            {
                TextureLayer* desc = props->tex->textures->slots[0];
                if (desc && desc->transform)
                {
                    texdata = FUN_00bc5c20(desc->transform);
                    if (type == 38 || type == 40)
                        scalarTemp.transpose = true;
                    if (type == 39 || type == 40)
                        pairScratch.inverse = true;
                }
            }
            SetAffineMatrix(&matA, texdata, scalarTemp.transpose, pairScratch.inverse, 4);
            if (!prog->SetConstant(entry, &matA, 0))
                result = 0x50;
            goto done;
        }
        case 41:
        case 42:
        case 43:
        case 44: {
            TexProperty* tex = props->tex;
            const char* texdata = 0;
            pairScratch.inverse = false;
            scalarTemp.transpose = false;
            if (tex)
            {
                TextureLayer* desc = props->tex->textures->slots[1];
                if (desc && desc->transform)
                {
                    texdata = FUN_00bc5c20(desc->transform);
                    if (type == 42 || type == 44)
                        pairScratch.inverse = true;
                    if (type == 43 || type == 44)
                        scalarTemp.transpose = true;
                }
            }
            SetAffineMatrix(&matA, texdata, pairScratch.inverse, scalarTemp.transpose, 4);
            if (!prog->SetConstant(entry, &matA, 0))
                result = 0x50;
            goto done;
        }
        case 45:
        case 46:
        case 47:
        case 48: {
            TexProperty* tex = props->tex;
            const char* texdata = 0;
            pairScratch.inverse = false;
            scalarTemp.transpose = false;
            if (tex)
            {
                TextureLayer* desc = props->tex->textures->slots[2];
                if (desc && desc->transform)
                {
                    texdata = FUN_00bc5c20(desc->transform);
                    if (type == 46 || type == 48)
                        pairScratch.inverse = true;
                    if (type == 47 || type == 48)
                        scalarTemp.transpose = true;
                }
            }
            SetAffineMatrix(&matA, texdata, pairScratch.inverse, scalarTemp.transpose, 4);
            if (!prog->SetConstant(entry, &matA, 0))
                result = 0x50;
            goto done;
        }
        case 49:
        case 50:
        case 51:
        case 52: {
            TexProperty* tex = props->tex;
            const char* texdata = 0;
            pairScratch.inverse = false;
            scalarTemp.transpose = false;
            if (tex)
            {
                TextureLayer* desc = props->tex->textures->slots[3];
                if (desc && desc->transform)
                {
                    texdata = FUN_00bc5c20(desc->transform);
                    if (type == 50 || type == 52)
                        pairScratch.inverse = true;
                    if (type == 51 || type == 52)
                        scalarTemp.transpose = true;
                }
            }
            SetAffineMatrix(&matA, texdata, pairScratch.inverse, scalarTemp.transpose, 4);
            if (!prog->SetConstant(entry, &matA, 0))
                result = 0x50;
            goto done;
        }
        case 53:
        case 54:
        case 55:
        case 56: {
            TexProperty* tex = props->tex;
            const char* texdata = 0;
            pairScratch.inverse = false;
            scalarTemp.transpose = false;
            if (tex)
            {
                TextureLayer* desc = props->tex->textures->slots[4];
                if (desc && desc->transform)
                {
                    texdata = FUN_00bc5c20(desc->transform);
                    if (type == 54 || type == 56)
                        pairScratch.inverse = true;
                    if (type == 55 || type == 56)
                        scalarTemp.transpose = true;
                }
            }
            SetAffineMatrix(&matA, texdata, pairScratch.inverse, scalarTemp.transpose, 4);
            if (!prog->SetConstant(entry, &matA, 0))
                result = 0x50;
            goto done;
        }
        case 57:
        case 58:
        case 59:
        case 60: {
            TexProperty* tex = props->tex;
            const char* texdata = 0;
            pairScratch.inverse = false;
            scalarTemp.transpose = false;
            if (tex)
            {
                TextureLayer* desc = props->tex->textures->slots[5];
                if (desc && desc->transform)
                {
                    texdata = FUN_00bc5c20(desc->transform);
                    if (type == 58 || type == 60)
                        pairScratch.inverse = true;
                    if (type == 59 || type == 60)
                        scalarTemp.transpose = true;
                }
            }
            SetAffineMatrix(&matA, texdata, pairScratch.inverse, scalarTemp.transpose, 4);
            if (!prog->SetConstant(entry, &matA, 0))
                result = 0x50;
            goto done;
        }
        case 88:
        case 89:
        case 90:
        case 91: {
            TexProperty* tex = props->tex;
            const char* texdata = 0;
            pairScratch.inverse = false;
            scalarTemp.transpose = false;
            if (tex)
            {
                TextureLayer* desc = props->tex->textures->slots[6];
                if (desc && desc->transform)
                {
                    texdata = FUN_00bc5c20(desc->transform);
                    if (type == 89 || type == 91)
                        pairScratch.inverse = true;
                    if (type == 90 || type == 91)
                        scalarTemp.transpose = true;
                }
            }
            SetAffineMatrix(&matA, texdata, pairScratch.inverse, scalarTemp.transpose, 4);
            if (!prog->SetConstant(entry, &matA, 0))
                result = 0x50;
            goto done;
        }
        case 92:
        case 93:
        case 94:
        case 95: {
            TexProperty* tex = props->tex;
            const char* texdata = 0;
            pairScratch.inverse = false;
            scalarTemp.transpose = false;
            if (tex)
            {
                TextureLayer* desc = props->tex->textures->slots[7];
                if (desc && desc->transform)
                {
                    texdata = FUN_00bc5c20(desc->transform);
                    if (type == 93 || type == 95)
                        pairScratch.inverse = true;
                    if (type == 94 || type == 95)
                        scalarTemp.transpose = true;
                }
            }
            SetAffineMatrix(&matA, texdata, pairScratch.inverse, scalarTemp.transpose, 4);
            if (!prog->SetConstant(entry, &matA, 0))
                result = 0x50;
            goto done;
        }
        case 61:
        case 62:
        case 63:
        case 64: {
            TexProperty* tex = props->tex;
            const char* texdata = 0;
            pairScratch.inverse = false;
            scalarTemp.transpose = false;
            if (tex)
            {
                TextureLayer* desc = props->tex->textures->extra[entry->index];
                if (desc && desc->transform)
                {
                    texdata = FUN_00bc5c20(desc->transform);
                    if (type == 62 || type == 64)
                        pairScratch.inverse = true;
                    if (type == 63 || type == 64)
                        scalarTemp.transpose = true;
                }
            }
            SetAffineMatrix(&matA, texdata, pairScratch.inverse, scalarTemp.transpose, 4);
            if (!prog->SetConstant(entry, &matA, 0))
                result = 0x50;
            goto done;
        }
        case 65:
        case 66:
        case 67:
        case 68: {
            TexProperty* tex = props->tex;
            const char* texdata = 0;
            pairScratch.inverse = false;
            scalarTemp.transpose = false;
            if (tex)
            {
                TextureLayer* desc = tex->GetElementAt(entry->index);
                if (desc && desc->transform)
                {
                    texdata = FUN_00bc5c20(desc->transform);
                    if (type == 66 || type == 68)
                        pairScratch.inverse = true;
                    if (type == 67 || type == 68)
                        scalarTemp.transpose = true;
                }
            }
            SetAffineMatrix(&matA, texdata, pairScratch.inverse, scalarTemp.transpose, 4);
            if (!prog->SetConstant(entry, &matA, 0))
                result = 0x50;
            goto done;
        }
        }
    case 73:
    case 74: {
        Material* __restrict m = props->material;
        if (!m)
            goto done;
        vec4.x = DAT_011f4998.x;
        vec4.y = DAT_011f4998.y;
        vec4.z = DAT_011f4998.z;
        vec4.w = m->alpha;
        if (!prog->SetConstant(entry, &vec4, 0))
            result = 0x50;
        goto done;
    }
    case 75: {
        Material* __restrict m = props->material;
        if (!m)
            goto done;
        vec4.x = m->diffuse.x;
        vec4.y = m->diffuse.y;
        vec4.z = m->diffuse.z;
        vec4.w = m->alpha;
        if (!prog->SetConstant(entry, &vec4, 0))
            result = 0x50;
        goto done;
    }
    case 76: {
        Material* __restrict m = props->material;
        if (!m)
            goto done;
        vec4.x = m->GetSpecular().x;
        vec4.y = m->GetSpecular().y;
        vec4.z = m->GetSpecular().z;
        vec4.w = m->alpha;
        if (!prog->SetConstant(entry, &vec4, 0))
            result = 0x50;
        goto done;
    }
    case 77: {
        Material* __restrict m = props->material;
        if (!m)
            goto done;
        vec4.x = m->gloss;
        vec4.y = m->gloss;
        vec4.z = m->gloss;
        vec4.w = m->gloss;
        if (!prog->SetConstant(entry, &vec4, 0))
            result = 0x50;
        goto done;
    }
    case 78: {
        matResult = renderer->misc;
        vec4.x = matResult.m[3][0];
        vec4.y = matResult.m[3][1];
        vec4.z = matResult.m[3][2];
        vec4.w = matResult.m[3][3];
        if (!prog->SetConstant(entry, &vec4, 0))
            result = 0x50;
        goto done;
    }
    case 79: {
        matResult = renderer->misc;
        vec4.x = matResult.m[2][0];
        vec4.y = matResult.m[2][1];
        vec4.z = matResult.m[2][2];
        vec4.w = matResult.m[2][3];
        if (!prog->SetConstant(entry, &vec4, 0))
            result = 0x50;
        goto done;
    }
    case 80:
    case 81:
        if (!prog->SetConstant(entry, 0, 0))
            result = 0x50;
        goto done;
    case 82:
    case 83:
    case 84:
    case 85:
    case 86: {
        NiExtraData* extra = geom->FUN_00a5bdd0(S83_FixedStr(DAT_011bf65c));
        if (!extra)
            result = 0x10;
        pairScratch.time = extra->value;
        switch (type)
        {
        case 82:
            vec4.w = vec4.z = vec4.y = vec4.x = pairScratch.time;
            break;
        case 83: {
            float trigValue;
            trigValue = sinf(pairScratch.time);
            vec4.x = trigValue;
            vec4.y = trigValue;
            vec4.z = trigValue;
            vec4.w = trigValue;
            break;
        }
        case 84: {
            float trigValue;
            trigValue = cosf(pairScratch.time);
            vec4.x = trigValue;
            vec4.y = trigValue;
            vec4.z = trigValue;
            vec4.w = trigValue;
            break;
        }
        case 85: {
            float trigValue;
            trigValue = tanf(pairScratch.time);
            vec4.x = trigValue;
            vec4.y = trigValue;
            vec4.z = trigValue;
            vec4.w = trigValue;
            break;
        }
        case 86:
            vec4.x = pairScratch.time;
            vec4.y = sinf(pairScratch.time);
            vec4.z = cosf(pairScratch.time);
            vec4.w = tanf(pairScratch.time);
            break;
        default:
            return 0x10;
        }
        if (!prog->SetConstant(entry, &vec4, 0))
            result = 0x50;
        goto done;
    }
    case 87: {
        vec4.z = vec4.y = vec4.x = 0.0f;
        vec4.w = 1.0f;
        if (effects)
        {
            LightLink* link = effects->lights;
            do
            {
                if (link)
                {
                    Light* light = link->light;
                    link = link->next;
                    if (light)
                    {
                        LightValue* lv = (LightValue*)light->FUN_00653290(&DAT_011f5f6c);
                        if (lv)
                        {
                            float brightness = lv->brightness;
                            const NiPoint3& lightColor = ((PointOps*)&lv->color)->ScaleTo(brightness);
                            vec4.x = vec4.x + lightColor.x;
                            vec4.y = vec4.y + lightColor.y;
                            vec4.z = vec4.z + lightColor.z;
                        }
                    }
                }
            } while (link);
        }
        if (!prog->SetConstant(entry, &vec4, 0))
            result = 0x50;
        goto done;
    }
        {
            ScalarScratch scalarTemp;
        case 105: {
            scalarTemp.scalar = 0;
            TexProperty* tex = props->tex;
            if (tex)
            {
                TextureLayer* d = tex->textures->slots[7];
                if (d)
                    scalarTemp.scalar = d->value;
            }
            if (!prog->SetConstant(entry, &scalarTemp.scalar, 0))
                result = 0x50;
            goto done;
        }
        case 103: {
            vec4.w = vec4.z = vec4.y = vec4.x = 1.0f;
            TexProperty* tex = props->tex;
            if (tex)
            {
                TextureLayer* d = tex->textures->slots[5];
                if (d)
                {
                    vec4.x = d->bump.x;
                    vec4.y = d->bump.y;
                    vec4.z = d->bump.z;
                    vec4.w = d->bump.w;
                }
            }
            if (!prog->SetConstant(entry, &vec4, 0))
                result = 0x50;
            goto done;
        }
        case 104: {
            scalarTemp.rgb.x = 0;
            scalarTemp.rgb.y = 1;
            TexProperty* tex = props->tex;
            if (tex)
            {
                TextureLayer* d = tex->textures->slots[5];
                if (d)
                {
                    scalarTemp.rgb.x = d->angle;
                    scalarTemp.rgb.y = d->value;
                }
            }
            if (!prog->SetConstant(entry, &scalarTemp.rgb, 0))
                result = 0x50;
            goto done;
        }
        }
        {
            ScalarScratch scalarTemp;
        case 106:
        case 107:
        case 108:
        case 109:
        case 110:
        case 111:
        case 112:
        case 113:
        case 114:
        case 115: {
            TexProperty* tex = props->tex;
            if (!tex)
                goto done;
            TextureLayer* d = 0;
            switch (type)
            {
            case 106:
                d = tex->textures->slots[0];
                break;
            case 107:
                d = tex->textures->slots[1];
                break;
            case 108:
                d = tex->textures->slots[2];
                break;
            case 109:
                d = tex->textures->slots[3];
                break;
            case 110:
                d = tex->textures->slots[4];
                break;
            case 111:
                d = tex->textures->slots[5];
                break;
            case 112:
                d = tex->textures->slots[6];
                break;
            case 113:
                d = tex->textures->slots[7];
                break;
            case 114:
                d = tex->textures->extra[entry->index];
                break;
            case 115:
                d = tex->GetElementAt(entry->index);
                break;
            }
            pairScratch.pair.x = 0;
            pairScratch.pair.y = 0;
            if (d)
            {
                Texture* t = d->texture;
                if (t)
                {
                    scalarTemp.integer = t->Width();
                    {
                        double dimension = (int)scalarTemp.integer;
                        if ((int)scalarTemp.integer < 0)
                            dimension += DAT_01099378;
                        pairScratch.pair.x = (float)dimension;
                    }
                    scalarTemp.integer = t->Height();
                    {
                        double dimension = (int)scalarTemp.integer;
                        if ((int)scalarTemp.integer < 0)
                            dimension += DAT_01099378;
                        pairScratch.pair.y = (float)dimension;
                    }
                }
            }
            if (!prog->SetConstant(entry, &pairScratch.pair, 0))
                result = 0x50;
            goto done;
        }
        }

    default:
        goto done;
    }
done:
    return result;
}

#include <math.h>
namespace fnv_00e85d10 {
extern "C" void _ReadWriteBarrier();
struct __declspec(align(16)) MapMatrix
{
    float m[4][4];
    __forceinline void Identity()
    {
        m[0][1] = m[0][2] = m[0][3] = m[1][0] = m[1][2] = m[1][3] = m[2][0] = m[2][1] = m[2][3] = m[3][0] = m[3][1] =
            m[3][2] = 0.0f;
        m[0][0] = m[1][1] = m[2][2] = m[3][3] = 1.0f;
    }
};

extern "C" void __stdcall FUN_00ee6de0(MapMatrix*, const MapMatrix*, const MapMatrix*);
extern "C" void __stdcall FUN_00ee6dda(MapMatrix*, float*, const MapMatrix*);
extern "C" void __stdcall FUN_00ee6dd4(MapMatrix*, const MapMatrix*);
void __cdecl SetAffineMatrix(MapMatrix*, const char*, bool, bool, unsigned int);
struct Renderer
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45c;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47c;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    unsigned int unk4a0;
    unsigned int unk4a4;
    unsigned int unk4a8;
    unsigned int unk4ac;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    unsigned int unk4d4;
    unsigned int unk4d8;
    unsigned int unk4dc;
    unsigned int unk4e0;
    unsigned int unk4e4;
    unsigned int unk4e8;
    unsigned int unk4ec;
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51c;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52c;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53c;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54c;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55c;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56c;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57c;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58c;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59c;
    unsigned int unk5a0;
    unsigned int unk5a4;
    unsigned int unk5a8;
    unsigned int unk5ac;
    unsigned int unk5b0;
    unsigned int unk5b4;
    unsigned int unk5b8;
    unsigned int unk5bc;
    unsigned int unk5c0;
    unsigned int unk5c4;
    unsigned int unk5c8;
    unsigned int unk5cc;
    unsigned int unk5d0;
    unsigned int unk5d4;
    unsigned int unk5d8;
    unsigned int unk5dc;
    unsigned int unk5e0;
    unsigned int unk5e4;
    unsigned int unk5e8;
    unsigned int unk5ec;
    unsigned int unk5f0;
    unsigned int unk5f4;
    unsigned int unk5f8;
    unsigned int unk5fc;
    unsigned int unk600;
    unsigned int unk604;
    unsigned int unk608;
    unsigned int unk60c;
    unsigned int unk610;
    unsigned int unk614;
    unsigned int unk618;
    unsigned int unk61c;
    unsigned int unk620;
    unsigned int unk624;
    unsigned int unk628;
    unsigned int unk62c;
    unsigned int unk630;
    unsigned int unk634;
    unsigned int unk638;
    unsigned int unk63c;
    unsigned int unk640;
    unsigned int unk644;
    unsigned int unk648;
    unsigned int unk64c;
    unsigned int unk650;
    unsigned int unk654;
    unsigned int unk658;
    unsigned int unk65c;
    unsigned int unk660;
    unsigned int unk664;
    unsigned int unk668;
    unsigned int unk66c;
    unsigned int unk670;
    unsigned int unk674;
    unsigned int unk678;
    unsigned int unk67c;
    unsigned int unk680;
    unsigned int unk684;
    unsigned int unk688;
    unsigned int unk68c;
    unsigned int unk690;
    unsigned int unk694;
    unsigned int unk698;
    unsigned int unk69c;
    unsigned int unk6a0;
    unsigned int unk6a4;
    unsigned int unk6a8;
    unsigned int unk6ac;
    unsigned int unk6b0;
    unsigned int unk6b4;
    unsigned int unk6b8;
    unsigned int unk6bc;
    unsigned int unk6c0;
    unsigned int unk6c4;
    unsigned int unk6c8;
    unsigned int unk6cc;
    unsigned int unk6d0;
    unsigned int unk6d4;
    unsigned int unk6d8;
    unsigned int unk6dc;
    unsigned int unk6e0;
    unsigned int unk6e4;
    unsigned int unk6e8;
    unsigned int unk6ec;
    unsigned int unk6f0;
    unsigned int unk6f4;
    unsigned int unk6f8;
    unsigned int unk6fc;
    unsigned int unk700;
    unsigned int unk704;
    unsigned int unk708;
    unsigned int unk70c;
    unsigned int unk710;
    unsigned int unk714;
    unsigned int unk718;
    unsigned int unk71c;
    unsigned int unk720;
    unsigned int unk724;
    unsigned int unk728;
    unsigned int unk72c;
    unsigned int unk730;
    unsigned int unk734;
    unsigned int unk738;
    unsigned int unk73c;
    unsigned int unk740;
    unsigned int unk744;
    unsigned int unk748;
    unsigned int unk74c;
    unsigned int unk750;
    unsigned int unk754;
    unsigned int unk758;
    unsigned int unk75c;
    unsigned int unk760;
    unsigned int unk764;
    unsigned int unk768;
    unsigned int unk76c;
    unsigned int unk770;
    unsigned int unk774;
    unsigned int unk778;
    unsigned int unk77c;
    unsigned int unk780;
    unsigned int unk784;
    unsigned int unk788;
    unsigned int unk78c;
    unsigned int unk790;
    unsigned int unk794;
    unsigned int unk798;
    unsigned int unk79c;
    unsigned int unk7a0;
    unsigned int unk7a4;
    unsigned int unk7a8;
    unsigned int unk7ac;
    unsigned int unk7b0;
    unsigned int unk7b4;
    unsigned int unk7b8;
    unsigned int unk7bc;
    unsigned int unk7c0;
    unsigned int unk7c4;
    unsigned int unk7c8;
    unsigned int unk7cc;
    unsigned int unk7d0;
    unsigned int unk7d4;
    unsigned int unk7d8;
    unsigned int unk7dc;
    unsigned int unk7e0;
    unsigned int unk7e4;
    unsigned int unk7e8;
    unsigned int unk7ec;
    unsigned int unk7f0;
    unsigned int unk7f4;
    unsigned int unk7f8;
    unsigned int unk7fc;
    unsigned int unk800;
    unsigned int unk804;
    unsigned int unk808;
    unsigned int unk80c;
    unsigned int unk810;
    unsigned int unk814;
    unsigned int unk818;
    unsigned int unk81c;
    unsigned int unk820;
    unsigned int unk824;
    unsigned int unk828;
    unsigned int unk82c;
    unsigned int unk830;
    unsigned int unk834;
    unsigned int unk838;
    unsigned int unk83c;
    unsigned int unk840;
    unsigned int unk844;
    unsigned int unk848;
    unsigned int unk84c;
    unsigned int unk850;
    unsigned int unk854;
    unsigned int unk858;
    unsigned int unk85c;
    unsigned int unk860;
    unsigned int unk864;
    unsigned int unk868;
    unsigned int unk86c;
    unsigned int unk870;
    unsigned int unk874;
    unsigned int unk878;
    unsigned int unk87c;
    unsigned int unk880;
    unsigned int unk884;
    unsigned int unk888;
    unsigned int unk88c;
    unsigned int unk890;
    unsigned int unk894;
    unsigned int unk898;
    unsigned int unk89c;
    unsigned int unk8a0;
    unsigned int unk8a4;
    unsigned int unk8a8;
    unsigned int unk8ac;
    unsigned int unk8b0;
    unsigned int unk8b4;
    unsigned int unk8b8;
    unsigned int unk8bc;
    unsigned int unk8c0;
    unsigned int unk8c4;
    unsigned int unk8c8;
    unsigned int unk8cc;
    unsigned int unk8d0;
    unsigned int unk8d4;
    unsigned int unk8d8;
    unsigned int unk8dc;
    unsigned int unk8e0;
    unsigned int unk8e4;
    unsigned int unk8e8;
    unsigned int unk8ec;
    unsigned int unk8f0;
    unsigned int unk8f4;
    unsigned int unk8f8;
    unsigned int unk8fc;
    unsigned int unk900;
    unsigned int unk904;
    unsigned int unk908;
    unsigned int unk90c;
    unsigned int unk910;
    unsigned int unk914;
    unsigned int unk918;
    unsigned int unk91c;
    unsigned int unk920;
    unsigned int unk924;
    unsigned int unk928;
    unsigned int unk92c;
    unsigned int unk930;
    unsigned int unk934;
    unsigned int unk938;
    unsigned int unk93c;
    MapMatrix world, view, projection, unkA00, inverseView;
};
struct Mapping
{
    unsigned int unk00, unk04, unk08, unk0c, mapping, unk14, index;
};
struct Texture
{
    unsigned int unk00, unk04, unk08;
    char* name;
};
struct TextureSlots
{
    Texture* base;
    Texture* dark;
    Texture* detail;
    Texture* gloss;
    Texture* glow;
    Texture* bump;
    Texture* unk18;
    Texture* unk1c;
    Texture* shader[1];
};
struct Texturing
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    TextureSlots* slots;
    Texture* GetElementAt(unsigned int);
};
struct Material
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    NiPoint3 diffuse;
    NiPoint3 specular;
    NiPoint3* specularOverride;
    float gloss;
    float alpha;
    const NiPoint3& Specular() const
    {
        return specularOverride ? *specularOverride : specular;
    }
};
struct Properties
{
    unsigned int unk00, unk04;
    Material* material;
    unsigned int unk0c, unk10;
    Texturing* textures;
};
struct NiColor
{
    float r, g, b;
};
extern NiColor DAT_011f4998;
class TimeString
{
    const char* value;

  public:
    TimeString* FUN_00438170(const char*) throw();
    void FUN_004381b0() throw();
    __forceinline ~TimeString() throw()
    {
        FUN_004381b0();
    }
};
struct ExtraValue
{
    unsigned int unk00, unk04, unk08;
    float value;
};
class NiAVObjectCall
{
  public:
    ExtraValue* FUN_00a5bdd0(const TimeString&) throw();
};
extern const char* DAT_011bf65c;
struct Light
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    bool enabled;
    unsigned char unk9d, unk9e, unk9f;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    float dimmer;
    NiPoint3 ambient;
};
class LightObject
{
  public:
    Light* FUN_00653290(const void*);
    static __forceinline Light* Cast(const void* type, LightObject* object)
    {
        if (!object)
            return 0;
        return object->FUN_00653290(type);
    }
};
extern const void* g_011f5f6c;
struct EffectLink
{
    EffectLink* next;
    LightObject* object;
};
struct Effects
{
    unsigned int unk00, unk04, unk08;
    EffectLink* lights;
    __forceinline EffectLink* Head() const
    {
        return lights;
    }
    __forceinline LightObject* Next(EffectLink*& iter) const
    {
        if (!iter)
            return 0;

        LightObject* result = iter->object;
        iter = iter->next;
        return result;
    }
};
class PointExt : public NiPoint3
{
  public:
    NiPoint3* ScaleTo(NiPoint3*, float);
};
struct MatrixWorkspace
{
    MapMatrix a, b, c, d, e, f, g;
};
struct ConstantMapView
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    Renderer* renderer;
    unsigned int FUN_00e85d10(unsigned int, Mapping*, NiAVObjectCall*, void*, Properties*, Effects*, void*,
                              unsigned int);
};
// Selects work by entry->mapping, writes to a slot-indexed output region, and returns a status value.
// @fnv 0x00e85d10
unsigned int ConstantMapView::FUN_00e85d10(unsigned int slot, Mapping* apMapping, NiAVObjectCall* geometry, void* skin,
                                           Properties* state, Effects* effects, void*, unsigned int)
{
    MatrixWorkspace work;
    unsigned int mapping = apMapping->mapping;
    switch (mapping)
    {
    case 1:
    case 2:
    case 13:
    case 14: {
        bool inverse = false;
        bool transpose = false;
        if (mapping == 2 || mapping == 14)
            inverse = true;
        if (mapping == 13 || mapping == 14)
            transpose = true;
        work.a = renderer->projection;
        reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot] = work.a;
        if (inverse)
            FUN_00ee6dda(&reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot], 0,
                         &reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot]);
        if (transpose)
            FUN_00ee6dd4(&reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot],
                         &reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot]);
        return 9;
    }
    case 3:
    case 4:
    case 15:
    case 16: {
        bool inverse = false;
        bool transpose = false;
        if (mapping == 4 || mapping == 16)
            inverse = true;
        if (mapping == 15 || mapping == 16)
            transpose = true;
        work.a = renderer->view;
        reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot] = work.a;
        if (inverse)
            FUN_00ee6dda(&reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot], 0,
                         &reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot]);
        if (transpose)
            FUN_00ee6dd4(&reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot],
                         &reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot]);
        return 9;
    }
    case 5:
    case 6:
    case 17:
    case 18: {
        bool inverse = false;
        bool transpose = false;
        if (mapping == 6 || mapping == 18)
            inverse = true;
        if (mapping == 17 || mapping == 18)
            transpose = true;
        reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot] = renderer->world;
        if (inverse)
            FUN_00ee6dda(&reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot], 0,
                         &reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot]);
        if (transpose)
            FUN_00ee6dd4(&reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot],
                         &reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot]);
        return 9;
    }
    case 7:
    case 8:
    case 19:
    case 20: {
        bool inverse = false;
        bool transpose = false;
        if (mapping == 8 || mapping == 20)
            inverse = true;
        if (mapping == 19 || mapping == 20)
            transpose = true;
        {
            Renderer* r = renderer;
            const MapMatrix* world = &r->world;
            const MapMatrix* view = &r->view;
            work.b = *world;
            work.a = *view;
        }
        FUN_00ee6de0(&work.f, &work.b, &work.a);
        reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot] = work.f;
        if (inverse)
            FUN_00ee6dda(&reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot], 0,
                         &reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot]);
        if (transpose)
            FUN_00ee6dd4(&reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot],
                         &reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot]);
        return 9;
    }
    case 9:
    case 10:
    case 21:
    case 22: {
        bool inverse = false;
        bool transpose = false;
        if (mapping == 10 || mapping == 22)
            inverse = true;
        if (mapping == 21 || mapping == 22)
            transpose = true;
        {
            Renderer* r = renderer;
            const MapMatrix* view = &r->view;
            const MapMatrix* projection = &r->projection;
            work.a = *view;
            work.b = *projection;
        }
        FUN_00ee6de0(&work.e, &work.a, &work.b);
        reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot] = work.e;
        if (inverse)
            FUN_00ee6dda(&reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot], 0,
                         &reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot]);
        if (transpose)
            FUN_00ee6dd4(&reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot],
                         &reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot]);
        return 9;
    }
    case 11:
    case 12:
    case 23:
    case 24: {
        bool inverse = false;
        bool transpose = false;
        if (mapping == 12 || mapping == 24)
            inverse = true;
        if (mapping == 23 || mapping == 24)
            transpose = true;
        {
            Renderer* r = renderer;
            work.a = r->world;
            const MapMatrix* view = &r->view;
            const MapMatrix* projection = &r->projection;
            work.b = *view;
            work.d = *projection;
        }
        FUN_00ee6de0(&work.c, &work.a, &work.b);
        FUN_00ee6de0(&work.g, &work.c, &work.d);
        reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot] = work.g;
        if (inverse)
            FUN_00ee6dda(&reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot], 0,
                         &reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot]);
        if (transpose)
            FUN_00ee6dd4(&reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot],
                         &reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot]);
        return 9;
    }
    case 25:
    case 26:
    case 27:
    case 28: {
        if (!skin)
            return 0;
        reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot].Identity();
        bool inverse = false;
        bool transpose = false;
        if (mapping == 26 || mapping == 28)
            inverse = true;
        if (mapping == 27 || mapping == 28)
            transpose = true;
        work.c = renderer->view;
        FUN_00ee6de0(&reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot],
                     &reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot], &work.c);
        if (inverse)
            FUN_00ee6dda(&reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot], 0,
                         &reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot]);
        if (transpose)
            FUN_00ee6dd4(&reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot],
                         &reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot]);
        return 9;
    }
    case 29:
    case 30:
    case 31:
    case 32: {
        if (!skin)
            return 0;
        reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot].Identity();
        bool inverse = false;
        bool transpose = false;
        if (mapping == 30 || mapping == 32)
            inverse = true;
        if (mapping == 31 || mapping == 32)
            transpose = true;
        work.c = renderer->view;
        work.d = renderer->projection;
        FUN_00ee6de0(&reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot],
                     &reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot], &work.c);
        FUN_00ee6de0(&reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot],
                     &reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot], &work.d);
        if (inverse)
            FUN_00ee6dda(&reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot], 0,
                         &reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot]);
        if (transpose)
            FUN_00ee6dd4(&reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot],
                         &reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot]);
        return 9;
    }
    case 33:
    case 34:
    case 35:
    case 36:
    case 69:
    case 70:
    case 71:
    case 72:
    case 80:
    case 81:
        return 0;
    case 96:
    case 97:
    case 98:
    case 99: {
        if (!skin)
            return 0;
        reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot].Identity();
        bool inverse = false;
        bool transpose = false;
        if (mapping == 97 || mapping == 99)
            inverse = true;
        if (mapping == 98 || mapping == 99)
            transpose = true;

        if (inverse)
            FUN_00ee6dda(&reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot], 0,
                         &reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot]);
        if (transpose)
            FUN_00ee6dd4(&reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot],
                         &reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot]);
        return 9;
    }
    case 37:
    case 38:
    case 39:
    case 40: {
        Texturing* textures = state->textures;
        char* name = 0;
        bool inverse = false, transpose = false;
        if (textures)
        {
            Texture* texture = textures->slots->base;
            if (texture && texture->name)
            {
                name = FUN_00bc5c20(texture->name);
                if (mapping == 38 || mapping == 40)
                    inverse = true;
                if (mapping == 39 || mapping == 40)
                    transpose = true;
            }
        }
        SetAffineMatrix(&reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot], name, inverse, transpose, 4);
        return 9;
    }
    case 41:
    case 42:
    case 43:
    case 44: {
        Texturing* textures = state->textures;
        char* name = 0;
        bool inverse = false, transpose = false;
        if (textures)
        {
            Texture* texture = textures->slots->bump;
            if (texture && texture->name)
            {
                name = FUN_00bc5c20(texture->name);
                if (mapping == 42 || mapping == 44)
                    inverse = true;
                if (mapping == 43 || mapping == 44)
                    transpose = true;
            }
        }
        SetAffineMatrix(&reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot], name, inverse, transpose, 4);
        return 9;
    }
    case 45:
    case 46:
    case 47:
    case 48: {
        Texturing* textures = state->textures;
        char* name = 0;
        bool inverse = false, transpose = false;
        if (textures)
        {
            Texture* texture = textures->slots->detail;
            if (texture && texture->name)
            {
                name = FUN_00bc5c20(texture->name);
                if (mapping == 46 || mapping == 48)
                    inverse = true;
                if (mapping == 47 || mapping == 48)
                    transpose = true;
            }
        }
        SetAffineMatrix(&reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot], name, inverse, transpose, 4);
        return 9;
    }
    case 49:
    case 50:
    case 51:
    case 52: {
        Texturing* textures = state->textures;
        char* name = 0;
        bool inverse = false, transpose = false;
        if (textures)
        {
            Texture* texture = textures->slots->gloss;
            if (texture && texture->name)
            {
                name = FUN_00bc5c20(texture->name);
                if (mapping == 50 || mapping == 52)
                    inverse = true;
                if (mapping == 51 || mapping == 52)
                    transpose = true;
            }
        }
        SetAffineMatrix(&reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot], name, inverse, transpose, 4);
        return 9;
    }
    case 53:
    case 54:
    case 55:
    case 56: {
        Texturing* textures = state->textures;
        char* name = 0;
        bool inverse = false, transpose = false;
        if (textures)
        {
            Texture* texture = textures->slots->glow;
            if (texture && texture->name)
            {
                name = FUN_00bc5c20(texture->name);
                if (mapping == 54 || mapping == 56)
                    inverse = true;
                if (mapping == 55 || mapping == 56)
                    transpose = true;
            }
        }
        SetAffineMatrix(&reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot], name, inverse, transpose, 4);
        return 9;
    }
    case 57:
    case 58:
    case 59:
    case 60: {
        Texturing* textures = state->textures;
        char* name = 0;
        bool inverse = false, transpose = false;
        if (textures)
        {
            Texture* texture = textures->slots->bump;
            if (texture && texture->name)
            {
                name = FUN_00bc5c20(texture->name);
                if (mapping == 58 || mapping == 60)
                    inverse = true;
                if (mapping == 59 || mapping == 60)
                    transpose = true;
            }
        }
        SetAffineMatrix(&reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot], name, inverse, transpose, 4);
        return 9;
    }
    case 61:
    case 62:
    case 63:
    case 64: {
        Texturing* textures = state->textures;
        char* name = 0;
        bool inverse = false, transpose = false;
        if (textures)
        {
            Texture* texture = textures->slots->shader[apMapping->index];
            if (texture && texture->name)
            {
                name = FUN_00bc5c20(texture->name);
                if (mapping == 62 || mapping == 64)
                    inverse = true;
                if (mapping == 63 || mapping == 64)
                    transpose = true;
            }
        }
        SetAffineMatrix(&reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot], name, inverse, transpose, 4);
        return 9;
    }
    case 65:
    case 66:
    case 67:
    case 68: {
        Texturing* textures = state->textures;
        char* name = 0;
        bool inverse = false, transpose = false;
        if (textures)
        {
            Texture* texture = textures->GetElementAt(apMapping->index);
            if (texture && texture->name)
            {
                name = FUN_00bc5c20(texture->name);
                if (mapping == 66 || mapping == 68)
                    inverse = true;
                if (mapping == 67 || mapping == 68)
                    transpose = true;
            }
        }
        SetAffineMatrix(&reinterpret_cast<MapMatrix*>(&DAT_0126f820)[slot], name, inverse, transpose, 4);
        return 9;
    }
    case 73: {
        Material* material = state->material;
        if (!material)
            return 0;
        (&DAT_0126f8a0)[slot].x = DAT_011f4998.r;
        (&DAT_0126f8a0)[slot].y = DAT_011f4998.g;
        (&DAT_0126f8a0)[slot].z = DAT_011f4998.b;
        (&DAT_0126f8a0)[slot].w = material->alpha;
        return 10;
    }
    case 74: {
        Material* material = state->material;
        if (!material)
            return 0;
        (&DAT_0126f8a0)[slot].x = DAT_011f4998.r;
        (&DAT_0126f8a0)[slot].y = DAT_011f4998.g;
        (&DAT_0126f8a0)[slot].z = DAT_011f4998.b;
        (&DAT_0126f8a0)[slot].w = material->alpha;
        return 10;
    }
    case 75: {
        Material* material = state->material;
        if (!material)
            return 0;
        (&DAT_0126f8a0)[slot].x = material->diffuse.x;
        (&DAT_0126f8a0)[slot].y = material->diffuse.y;
        (&DAT_0126f8a0)[slot].z = material->diffuse.z;
        (&DAT_0126f8a0)[slot].w = material->alpha;
        return 10;
    }
    case 76: {
        Material* material = state->material;
        if (!material)
            return 0;
        (&DAT_0126f8a0)[slot].x = material->Specular().x;
        (&DAT_0126f8a0)[slot].y = material->Specular().y;
        (&DAT_0126f8a0)[slot].z = material->Specular().z;
        (&DAT_0126f8a0)[slot].w = material->alpha;
        return 10;
    }
    case 77: {
        Material* material = state->material;
        if (!material)
            return 0;
        (&DAT_0126f8a0)[slot].x = material->gloss;
        (&DAT_0126f8a0)[slot].y = material->gloss;
        (&DAT_0126f8a0)[slot].z = material->gloss;
        (&DAT_0126f8a0)[slot].w = material->gloss;
        return 10;
    }
    case 78: {
        work.a = renderer->inverseView;
        (&DAT_0126f8a0)[slot].x = work.a.m[3][0];
        (&DAT_0126f8a0)[slot].y = work.a.m[3][1];
        (&DAT_0126f8a0)[slot].z = work.a.m[3][2];
        (&DAT_0126f8a0)[slot].w = work.a.m[3][3];
        return 7;
    }
    case 79: {
        work.a = renderer->inverseView;
        (&DAT_0126f8a0)[slot].x = work.a.m[2][0];
        (&DAT_0126f8a0)[slot].y = work.a.m[2][1];
        (&DAT_0126f8a0)[slot].z = work.a.m[2][2];
        (&DAT_0126f8a0)[slot].w = work.a.m[2][3];
        return 7;
    }
    case 82:
    case 83:
    case 84:
    case 85:
    case 86: {
        ExtraValue* extra = geometry->FUN_00a5bdd0(*TimeString().FUN_00438170(DAT_011bf65c));
        if (!extra)
            return 16;
        float value = extra->value;
        switch (mapping)
        {
        case 82:
            (&DAT_0126f8a0)[slot].x = value;
            (&DAT_0126f8a0)[slot].y = value;
            (&DAT_0126f8a0)[slot].z = value;
            (&DAT_0126f8a0)[slot].w = value;
            return 7;
        case 83: {
            float s = (float)sin(value);
            (&DAT_0126f8a0)[slot].x = s;
            (&DAT_0126f8a0)[slot].y = s;
            (&DAT_0126f8a0)[slot].z = s;
            (&DAT_0126f8a0)[slot].w = s;
            return 7;
        }
        case 84: {
            float s = (float)cos(value);
            (&DAT_0126f8a0)[slot].x = s;
            (&DAT_0126f8a0)[slot].y = s;
            (&DAT_0126f8a0)[slot].z = s;
            (&DAT_0126f8a0)[slot].w = s;
            return 7;
        }
        case 85: {
            float s = (float)tan(value);
            (&DAT_0126f8a0)[slot].x = s;
            (&DAT_0126f8a0)[slot].y = s;
            (&DAT_0126f8a0)[slot].z = s;
            (&DAT_0126f8a0)[slot].w = s;
            return 7;
        }
        case 86:
            (&DAT_0126f8a0)[slot].x = value;
            (&DAT_0126f8a0)[slot].y = (float)sin(value);
            (&DAT_0126f8a0)[slot].z = (float)cos(value);
            (&DAT_0126f8a0)[slot].w = (float)tan(value);
            return 7;
        }
        break;
    }
    case 87: {
        (&DAT_0126f8a0)[slot].x = 0.0f;
        (&DAT_0126f8a0)[slot].y = 0.0f;
        (&DAT_0126f8a0)[slot].z = 0.0f;
        (&DAT_0126f8a0)[slot].w = 1.0f;
        if (effects)
        {
            EffectLink* iter = effects->Head();
            while (iter)
            {
                Light* light = LightObject::Cast(&g_011f5f6c, effects->Next(iter));
                if (light && light->enabled)
                {
                    NiPoint3 point;
                    ((PointExt*)&light->ambient)->ScaleTo(&point, light->dimmer);
                    (&DAT_0126f8a0)[slot].x = (&DAT_0126f8a0)[slot].x + point.x;
                    (&DAT_0126f8a0)[slot].y = point.y + (&DAT_0126f8a0)[slot].y;
                    (&DAT_0126f8a0)[slot].z = (&DAT_0126f8a0)[slot].z + point.z;
                }
            }
        }
        _ReadWriteBarrier();
        return 7;
    }
    }
    return 0;
}
}  // namespace fnv_00e85d10
