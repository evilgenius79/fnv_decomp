// gamebryo2.2/corelibs/niconsolerenderer/nid3dshaderprogramfactory.cpp: NiD3DShaderProgramFactory, ProgFactoryDirs, ShaderEntryOwner (26 functions)

#include "nid3dshaderprogramfactory_packet.h"
// @fnv 0x00e93000
const char* NiD3DShaderProgramFactory::GetNextName(void*& apPosition)
{
    DirectoryEntry* entry = static_cast<DirectoryEntry*>(apPosition);
    if (entry)
    {
        apPosition = entry->next;
        return entry->value;
    }
    return 0;
}
// @fnv 0x00e93e70
bool NiD3DShaderProgramFactory::RegisterCreator(const char* pcName, NiD3DShaderProgramCreator* creator)
{
    char lower[256];
    if (!pcName || strchr(pcName, '.'))
        return false;
    for (unsigned int i = 0; i < 256; ++i)
    {
        lower[i] = (char)tolower(pcName[i]);
        if (!pcName[i])
            break;
    }
    if (!DAT_0126fa14)
        CreateFactoryInstance();
    DAT_0126fa14->SetAt(lower, reinterpret_cast<NiShader*>(creator));
    return true;
}

struct Program;
extern Program* DAT_0126fa10;
// @fnv 0x00e92eb0
Program* FUN_00e92eb0()
{
    return DAT_0126fa10;
}

struct Program
{
    virtual void Destroy(int);
};
extern Program* DAT_0126fa10;
// @fnv 0x00e92ec0
void DestroyProgram()
{
    if (DAT_0126fa10)
        DAT_0126fa10->Destroy(1);
    DAT_0126fa10 = 0;
}

struct Nd
{
    Nd* next;
    int b;
    int data;
};
struct Lst
{
    int a;
    int b;
    Nd* head;
};
// @fnv 0x00e92fe0
int __fastcall FUN_00e92fe0(Lst* l, int, Nd** apNext)
{
    Nd* n = l->head;
    *apNext = n;
    if (n)
    {
        *apNext = n->next;
        return n->data;
    }
    return 0;
}

// @fnv 0x00e93df0
void FUN_00e93df0()
{
    if (DAT_0126fa14 == 0)
        NiD3DShaderProgramFactory::CreateFactoryInstance();
}

extern "C" void __cdecl __Dummy_00b6fef0(void*, unsigned int);
void __cdecl FUN_00e93e00();

struct FUN_00e93f30_shell
{
    void* __thiscall DestroyShaderProgramFactory(unsigned int flags);
};

// @fnv 0x00e93f30
void* __thiscall FUN_00e93f30_shell::DestroyShaderProgramFactory(unsigned int flags)
{
    NiD3DShaderProgramFactory* self = (NiD3DShaderProgramFactory*)this;
    FUN_00e93e00();
    if (flags & 1)
    {
        __Dummy_00b6fef0(self, 0x1c);
    }
    return self;
}

struct ShaderBufferRecord;

struct NiTStringPointerMap_00e93060
{
    bool __thiscall GetAt(const char* key, ShaderBufferRecord*& out);
};

struct NiD3DShaderProgramFactory_00e93060
{
    int m_auiShapeKeys[6];
    NiTStringPointerMap_00e93060* m_pShaderBufferMap;
    ShaderBufferRecord* __thiscall FUN_00e93060(const char* pcShaderName);
};

// @fnv 0x00e93060
ShaderBufferRecord* NiD3DShaderProgramFactory_00e93060::FUN_00e93060(const char* pcShaderName)
{
    NiTStringPointerMap_00e93060* map = m_pShaderBufferMap;
    if (!map)
        return 0;
    ShaderBufferRecord* pkVertexShader = 0;
    if (map->GetAt(pcShaderName, pkVertexShader))
        return pkVertexShader;
    return 0;
}

struct P03MM
{
    void* __thiscall Allocate(unsigned int size);
};
extern P03MM g_memoryManager;
extern "C" void* __cdecl _NiMalloc(unsigned int size);
extern "C" void* __cdecl _fnv_zlib_memset(void* dst, int value, unsigned int size);
extern int DAT_010f0eb0;
extern int DAT_010f0f50;

// @fnv 0x00e93d80
void CreateCreatorMap()
{
    int* p = (int*)g_memoryManager.Allocate(0x14);
    if (p)
    {
        p[0] = (int)&DAT_010f0eb0;
        p[1] = 0x25;
        p[3] = 0;
        int* data = (int*)_NiMalloc(0x94);
        p[2] = (int)data;
        _fnv_zlib_memset((void*)data, 0, 4 * p[1]);
        *(char*)(p + 4) = 1;
        p[0] = (int)&DAT_010f0f50;
        DAT_0126fa14 = (CreatorMap*)p;
    }
    else
    {
        DAT_0126fa14 = 0;
    }
}

namespace fnv_00e92ee0 {
struct NiD3DVertexShader;
struct NiD3DShaderProgramCreator
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual bool Recreate(NiD3DVertexShader* pkVertexShader);
};
struct NiD3DVertexShader
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual NiD3DShaderProgramCreator* GetCreator();
    virtual void g28();
    virtual void g29();
    virtual void g30();
    virtual void g31();
    virtual void g32();
    virtual int IsRecreated();
};
// If a global flag is set and pkVertexShader is non-null, returns true when already recreated, otherwise asks its creator to recreate it.
// @fnv 0x00e92ee0
bool __cdecl FUN_00e92ee0(NiD3DVertexShader* pkVertexShader)
{
    NiD3DShaderProgramCreator* pkCreator;
    if (DAT_0126fa10 && pkVertexShader)
    {
        if (pkVertexShader->IsRecreated())
            return true;
        pkCreator = pkVertexShader->GetCreator();
        if (pkCreator)
            return pkCreator->Recreate(pkVertexShader);
    }
    return false;
}
}  // namespace fnv_00e92ee0

struct ShaderBufferRecord;
struct NiTStringPointerMap_00e93020
{
    bool __thiscall GetAt(const char* key, ShaderBufferRecord*& out);
};
struct NiD3DShaderProgramFactory_00e93020
{
    int m_auiShapeKeys[5];
    NiTStringPointerMap_00e93020* m_pShaderBufferMap;
    ShaderBufferRecord* __thiscall FUN_00e93020(const char* pcShaderName);
};
// @fnv 0x00e93020
ShaderBufferRecord* NiD3DShaderProgramFactory_00e93020::FUN_00e93020(const char* pcShaderName)
{
    if (!m_pShaderBufferMap)
        return 0;
    ShaderBufferRecord* pkPixelShader = 0;
    return m_pShaderBufferMap->GetAt(pcShaderName, pkPixelShader) ? pkPixelShader : 0;
}

struct FakeShader_00e93820
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual const char* GetName();
};
struct FUN_00e93820_shell
{
    int m_auiShapeKeys[6];
    NiTStringTemplateMap<NiTPointerMap<char const*, NiShader*>, NiShader*>* m_map;
    void RegisterShader(FakeShader_00e93820* p);
};
// If p and m_map are non-null, inserts p into m_map keyed by p->GetName().
// @fnv 0x00e93820
void FUN_00e93820_shell::RegisterShader(FakeShader_00e93820* apShader)
{
    if (apShader && m_map)
        m_map->SetAt(apShader->GetName(), (NiShader*)apShader);
}

struct Dealloc_00e93ab0
{
    void __thiscall _DeallocateAlias(void* p);
};
struct Owner_00e93ab0
{
    void __thiscall FUN_00e93540();
    void* __thiscall DestroyIfFlagged(unsigned int);
};
// @fnv 0x00e93ab0
void* __thiscall Owner_00e93ab0::DestroyIfFlagged(unsigned int flags)
{
    FUN_00e93540();
    if (flags & 1)
        ((Dealloc_00e93ab0*)&g_memoryManager)->_DeallocateAlias(this);
    return this;
}

namespace fnv_00e92f30 {
struct NiD3DPixelShader;
struct NiD3DShaderProgramCreator
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual bool Recreate(NiD3DPixelShader* pkPixelShader);
};
struct NiD3DPixelShader
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual NiD3DShaderProgramCreator* GetCreator();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual int CanRecreate();
};
// Returns true if the pixel shader can be recreated or its creator successfully recreates it, otherwise false.
// @fnv 0x00e92f30
bool FUN_00e92f30(NiD3DPixelShader* pkPixelShader)
{
    NiD3DShaderProgramCreator* pkCreator;
    if (DAT_0126fa10 && pkPixelShader)
    {
        if (pkPixelShader->CanRecreate())
            return true;
        pkCreator = pkPixelShader->GetCreator();
        if (pkCreator)
            return pkCreator->Recreate(pkPixelShader);
    }
    return false;
}
}  // namespace fnv_00e92f30

struct ShaderArg
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual const char* GetKey();
};
struct FUN_00e937f0_shell
{
    int m_auiShapeKeys[5];
    NiTStringTemplateMap<NiTPointerMap<char const*, NiShader*>, NiShader*>* m_pTaskMap;
    void __thiscall AddShader(ShaderArg* pkShader);
};
// If pkShader and the map are non-null, inserts pkShader into the map keyed by pkShader->GetKey().
// @fnv 0x00e937f0
void __thiscall FUN_00e937f0_shell::AddShader(ShaderArg* pkShader)
{
    if (pkShader && m_pTaskMap)
        m_pTaskMap->SetAt(pkShader->GetKey(), (NiShader*)pkShader);
}

extern int DAT_0126fa18;
extern int DAT_0126fa1c;
extern int DAT_0126fa20;

// @fnv 0x00e92f70
void FUN_00e92f70(int param_1)
{
    DAT_0126fa1c = param_1;
    if (param_1 != 0)
    {
        int* piVar1 = *(int**)(param_1 + 0x288);
        if (DAT_0126fa18 != 0)
        {
            (**(void(__stdcall**)(int))(*(int*)DAT_0126fa18 + 8))(DAT_0126fa18);
        }
        DAT_0126fa18 = (int)piVar1;
        if (piVar1 != 0)
        {
            (**(void(__stdcall**)(int*))(*(int*)piVar1 + 4))(piVar1);
        }
        DAT_0126fa20 = *(int*)(DAT_0126fa1c + 0x8b8);
        return;
    }
    DAT_0126fa20 = 0;
    if (DAT_0126fa18 != 0)
    {
        (**(void(__stdcall**)(int))(*(int*)DAT_0126fa18 + 8))(DAT_0126fa18);
    }
    DAT_0126fa18 = 0;
}

extern "C" int __cdecl strcmp(const char*, const char*);
extern "C" unsigned int __cdecl strlen(const char*);
int strcpy_s(char* dst, unsigned int size, const char* src);
void* NiMalloc(unsigned int size);
extern "C" int __cdecl FUN_00aa1360(const char* a, const char* b);
struct DirNode
{
    DirNode* m_pkNext;
    DirNode* m_pkPrev;
    char* m_element;
};
struct NodePoolView
{
    unsigned int m_uiCount;
    void* AddHead();
};
struct DirList
{
    void* vtbl;
    DirNode* m_pkHead;
    DirNode* m_pkTail;
    NodePoolView m_kItemCount;
    char*& GetNext(DirNode*& pos)
    {
        char*& e = pos->m_element;
        pos = pos->m_pkNext;
        return e;
    }
    void AddHead(char* e)
    {
        DirNode* n = (DirNode*)m_kItemCount.AddHead();
        n->m_element = e;
        n->m_pkPrev = 0;
        n->m_pkNext = m_pkHead;
        if (m_pkHead)
            m_pkHead->m_pkPrev = n;
        else
            m_pkTail = n;
        m_kItemCount.m_uiCount++;
        m_pkHead = n;
    }
};
struct ProgFactoryDirs
{
    void* vtbl;
    DirList m_kDirs;
    void AddDirectory(const char* pcDir);
};
// Normalizes '/' to '\\' in pcDir, returns if it already exists in m_kDirs, otherwise allocates a copy and adds it to the head of the list.
// @fnv 0x00e93960
void ProgFactoryDirs::AddDirectory(const char* pcDir)
{
    if (!pcDir || strcmp(pcDir, "") == 0)
        return;
    char acDir[260];
    strcpy_s(acDir, 260, pcDir);
    for (unsigned int i = 0; i < strlen(acDir); i++)
    {
        if (acDir[i] == '/')
            acDir[i] = '\\';
    }
    DirNode* pos = m_kDirs.m_pkHead;
    while (pos)
    {
        char* e = m_kDirs.GetNext(pos);
        if (e && FUN_00aa1360(e, acDir) == 0)
            return;
    }
    unsigned int len = strlen(acDir) + 1;
    char* p = (char*)NiMalloc(len);
    strcpy_s(p, len, acDir);
    m_kDirs.AddHead(p);
}

namespace fnv_00e93bb0 {
extern "C" int __cdecl strcmp(const char*, const char*);
extern "C" size_t __cdecl strlen(const char*);
extern "C" int __cdecl strcpy_s(char*, size_t, const char*);
extern "C" int __cdecl NiStricmp(const char*, const char*);

struct BSBatchRenderer__GeometryGroup;

struct DirectoryEntryNode
{
    DirectoryEntryNode* next;
    DirectoryEntryNode* prev;
    const char* value;
};

struct BSBatchRenderer__AlphaList
{
    DirectoryEntryNode* head;
    DirectoryEntryNode* tail;
    unsigned int count;

    inline BSBatchRenderer__GeometryGroup* const& GetNext(DirectoryEntryNode*& pos) const
    {
        const char* const& item = pos->value;
        pos = pos->next;
        return (BSBatchRenderer__GeometryGroup* const&)item;
    }

    BSBatchRenderer__GeometryGroup* __thiscall Remove(BSBatchRenderer__GeometryGroup*&);
};

struct NiD3DShaderProgramFactory_Shell
{
    int unk00;
    int unk04;
    BSBatchRenderer__AlphaList m_directories;

    void __thiscall RemoveDirectoryEntry(const char* pcDirectory);
};

// Copies pcDirectory into a path buffer, converts '/' to '\\', then removes the matching entry from m_directories if found.
// @fnv 0x00e93bb0
void __thiscall NiD3DShaderProgramFactory_Shell::RemoveDirectoryEntry(const char* pcDirectory)
{
    if (!pcDirectory || strcmp(pcDirectory, "") == 0)
        return;

    char acPath[260];
    strcpy_s(acPath, 260, pcDirectory);

    for (unsigned int i = 0; i < strlen(acPath); i++)
    {
        if (acPath[i] == '/')
            acPath[i] = '\\';
    }

    DirectoryEntryNode* kPos = m_directories.head;
    while (kPos)
    {
        BSBatchRenderer__GeometryGroup* pcSearchDir = m_directories.GetNext(kPos);
        if (pcSearchDir && NiStricmp((const char*)pcSearchDir, acPath) == 0)
        {
            m_directories.Remove(pcSearchDir);
            break;
        }
    }
}
}  // namespace fnv_00e93bb0

extern int DAT_010f0f70;
extern int DAT_0101dce4;
extern int DAT_011f4400;
extern int(__stdcall* DAT_00fdf1c4)(void*);

struct ShaderProgramStandIn_00e93e00
{
    virtual void __thiscall vf00(int);
    void __thiscall FUN_00b601a0();
};

struct FUN_00e93cc0_Obj
{
    virtual void vf00();
    void __thiscall FUN_00e93cc0();
};

struct FUN_00b71300_Obj
{
    virtual void vf00();
    int unk04;
    void __thiscall FUN_00b71300();
};

struct FUN_00e93e00_Obj : public FUN_00e93cc0_Obj
{
    int unk04;
    FUN_00b71300_Obj unk08;
    int unk10;
    ShaderProgramStandIn_00e93e00* unk14;
    ShaderProgramStandIn_00e93e00* unk18;

    void __thiscall FUN_00e93e00();
};

// @fnv 0x00e93e00
void FUN_00e93e00_Obj::FUN_00e93e00()
{
    *reinterpret_cast<int*>(this) = reinterpret_cast<int>(&DAT_010f0f70);

    if (unk14 != 0)
        unk14->FUN_00b601a0();

    if (unk14 != 0)
        unk14->vf00(1);

    if (unk18 != 0)
        unk18->FUN_00b601a0();

    if (unk18 != 0)
        unk18->vf00(1);

    FUN_00e93cc0();
    unk08.FUN_00b71300();

    *reinterpret_cast<int*>(this) = reinterpret_cast<int>(&DAT_0101dce4);
    DAT_00fdf1c4(&DAT_011f4400);
}

class NiTMapBase
{
  public:
    void* m_pvVtbl;
    unsigned int m_uiHashSize;
    void** m_ppkHashTable;

    void* GetFirstPos() const
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            if (m_ppkHashTable[i])
                return m_ppkHashTable[i];
        }
        return 0;
    }

    void AdvanceToNextEntry(void*& pvPos, const char*& pcKey, NiD3DShaderProgramCreator*& pkVal) const;
    bool RemoveAt(const char* pcKey);
};

// Removes pkCreator from the global NiTMapBase at DAT_0126fa14 if found, iterating entries and calling RemoveAt on a matching key.
// @fnv 0x00e93260
void __cdecl FUN_00e93260(NiD3DShaderProgramCreator* pkCreator)
{
    if (DAT_0126fa14 == 0)
        return;

    void* pvIter = ((NiTMapBase*)DAT_0126fa14)->GetFirstPos();
    while (pvIter)
    {
        const char* pcExt = 0;
        NiD3DShaderProgramCreator* pkTestCreator = 0;
        ((NiTMapBase*)DAT_0126fa14)->AdvanceToNextEntry(pvIter, pcExt, pkTestCreator);
        if (pkCreator == pkTestCreator)
            ((NiTMapBase*)DAT_0126fa14)->RemoveAt(pcExt);
    }
}

class NiShaderLibraryE93
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual FakeShader_00e93820* CreateShader(void* pkDesc, void* pkRenderer, const char* pcName, void* pvArg4,
                                              void* pvArg5, void* pvArg6);
};

NiShaderLibraryE93* __cdecl FUN_00e932f0(const char* pcLibName);

// Returns the cached entry for pcName, or creates a shader with pkLibrary, registers it, and returns it.
// @fnv 0x00e938e0
void* __cdecl FUN_00e938e0(void* pkDesc, void* pkRenderer, const char* pcLibName, const char* pcName, void* pvArg4,
                           void* pvArg5, void* pvArg6)
{
    if (!DAT_0126fa10)
        return 0;
    if (!pkDesc || !pkRenderer)
        return 0;
    ShaderBufferRecord* pkEntry =
        reinterpret_cast<NiD3DShaderProgramFactory_00e93060*>(DAT_0126fa10)->FUN_00e93060(pcName);
    if (pkEntry)
        return pkEntry;
    NiShaderLibraryE93* pkLibrary = FUN_00e932f0(pcLibName);
    if (!pkLibrary)
        return 0;
    FakeShader_00e93820* pkShader = pkLibrary->CreateShader(pkDesc, pkRenderer, pcName, pvArg4, pvArg5, pvArg6);
    reinterpret_cast<FUN_00e93820_shell*>(DAT_0126fa10)->RegisterShader(pkShader);
    return pkShader;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* p);
extern "C" void* __cdecl MemSet_00e93ad0(void* dst, int value, unsigned int size);

class NiRefObject
{
  public:
    NiRefObject() throw()
    {
        m_uiRefCount = 0;
        InterlockedIncrement((long volatile*)&DAT_011f4400);
    }
    virtual ~NiRefObject();
    virtual void DeleteThis();

    unsigned int m_uiRefCount;
};

class NiMemObject_00e93ad0
{
  public:
    static void* operator new(unsigned int uiSize) throw()
    {
        return g_memoryManager.Allocate(uiSize);
    }
    static void operator delete(void*, unsigned int);
};

template <class TVAL> class ShaderMapBase : public NiMemObject_00e93ad0
{
  public:
    ShaderMapBase(unsigned int uiHashSize) throw()
    {
        m_uiHashSize = uiHashSize;
        m_uiCount = 0;
        unsigned int uiSize = sizeof(void*) * m_uiHashSize;
        m_ppkHashTable = (void**)NiMalloc(uiSize);
        MemSet_00e93ad0(m_ppkHashTable, 0, m_uiHashSize * sizeof(void*));
    }
    virtual ~ShaderMapBase();

    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
};

template <class TVAL> class ShaderStringTemplateMap : public ShaderMapBase<TVAL>
{
  public:
    ShaderStringTemplateMap(unsigned int uiHashSize, bool bCopy) throw() : ShaderMapBase<TVAL>(uiHashSize)
    {
        m_bCopy = bCopy;
    }
    virtual ~ShaderStringTemplateMap();

    bool m_bCopy;
};

template <class TVAL> class ShaderStringMap : public ShaderStringTemplateMap<TVAL>
{
  public:
    ShaderStringMap(unsigned int uiHashSize, bool bCopy) throw() : ShaderStringTemplateMap<TVAL>(uiHashSize, bCopy)
    {}
    virtual ~ShaderStringMap();
};

struct DirAllocator_00e93ad0
{
    unsigned int m_uiCount;
};

struct DirListItem_00e93ad0;

class DirList_00e93ad0
{
  public:
    DirList_00e93ad0() throw()
    {
        m_kItemCount.m_uiCount = 0;
        m_pkHead = 0;
        m_pkTail = 0;
    }

    DirListItem_00e93ad0* m_pkHead;
    DirListItem_00e93ad0* m_pkTail;
    DirAllocator_00e93ad0 m_kItemCount;
};

class NiD3DVertexShaderEntry;
class NiD3DPixelShaderEntry;

class FUN_00e93ad0 : public NiRefObject
{
  public:
    FUN_00e93ad0() throw();
    virtual ~FUN_00e93ad0();

    DirList_00e93ad0 m_kDirectoryList;
    ShaderStringMap<NiD3DVertexShaderEntry*>* m_pVertexShaderMap;
    ShaderStringMap<NiD3DPixelShaderEntry*>* m_pShaderBufferMap;
};

// Allocates string maps for NiD3DVertexShaderEntry and NiD3DPixelShaderEntry pointers, each with hash size 59 and copying disabled.
// @fnv 0x00e93ad0
FUN_00e93ad0::FUN_00e93ad0() throw()
{
    m_pVertexShaderMap = new ShaderStringMap<NiD3DVertexShaderEntry*>(59, false);
    m_pShaderBufferMap = new ShaderStringMap<NiD3DPixelShaderEntry*>(59, false);
}

struct ShaderEntryNode
{
    ShaderEntryNode* next;
    ShaderEntryNode* previous;
    void* element;
};
struct ShaderEntryList
{
    ShaderEntryNode* head;
    ShaderEntryNode* tail;
    unsigned int count;
    void*& GetNext(ShaderEntryNode*& position)
    {
        void*& element = position->element;
        position = position->next;
        return element;
    }
    void __thiscall FUN_00b602d0();
    void __thiscall FUN_00e7d5b0();
};
struct ShaderEntryNodePool
{
    void* first;
    void __thiscall Lock(int count);
};
extern ShaderEntryNodePool DAT_011c5f80;
extern ShaderEntryNode* DAT_011c5f58;
extern unsigned int DAT_011c5f84;
extern "C" void __cdecl FUN_00aa10f0(void*);
struct ShaderEntryOwner
{
    int unknown00;
    int unknown04;
    ShaderEntryList entries;
    void FUN_00e93cc0();
};
// Iterates nonnull elements, searches for matching list nodes, removes matches, and passes each element to FUN_00aa10f0.
// @fnv 0x00e93cc0
void ShaderEntryOwner::FUN_00e93cc0()
{
    ShaderEntryList* pEntries = &entries;
    ShaderEntryNode* pNode = pEntries->head;
    if (pNode)
    {
        do
        {
            void* element = pEntries->GetNext(pNode);
            if (!element)
                continue;
            ShaderEntryNode* head = pEntries->head;
            ShaderEntryNode* candidate;
            ShaderEntryNode* position = pEntries->head;
            if (!position)
                goto release;
            do
            {
                candidate = position;
                if (element == pEntries->GetNext(position))
                    goto found;
            } while (position);
            goto release;
        found:
            if (candidate)
            {
                if (candidate == head)
                    pEntries->FUN_00b602d0();
                else if (candidate == pEntries->tail)
                    pEntries->FUN_00e7d5b0();
                else
                {
                    ShaderEntryNode* pPrev = candidate->previous;
                    ShaderEntryNode* pNext = candidate->next;
                    if (pPrev)
                        pPrev->next = pNext;
                    if (pNext)
                        pNext->previous = pPrev;
                    candidate->element = 0;
                    DAT_011c5f80.Lock(0);
                    candidate->previous = 0;
                    candidate->next = DAT_011c5f58;
                    --DAT_011c5f84;
                    DAT_011c5f58 = candidate;
                    if (!DAT_011c5f84)
                        DAT_011c5f80.first = 0;
                    --pEntries->count;
                }
            }
        release:
            FUN_00aa10f0(element);
        } while (pNode);
    }
}

namespace fnv_00e93850 {
class NiD3DShaderProgramCreator
{
  public:
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual ShaderArg* CreateShader(const char* p0, const char* p1, const char* p3, unsigned int p4, unsigned int p5,
                                    unsigned int p6, unsigned int p7, unsigned int p8, unsigned int p9);
};

NiD3DShaderProgramCreator* FUN_00e932f0(const char* p2);

// Returns a cached ShaderArg for p3, or creates one via the NiD3DShaderProgramCreator for p2 and registers it with the factory.
// @fnv 0x00e93850
ShaderArg* FUN_00e93850(const char* p0, const char* p1, const char* apCreatorName, const char* apShaderName,
                        unsigned int aiParam0, unsigned int aiParam1, unsigned int aiParam2, unsigned int aiParam3,
                        unsigned int aiParam4, unsigned int aiParam5)
{
    if (!DAT_0126fa10)
        return 0;

    if (!p0 || !p1)
        return 0;

    ShaderArg* pkShader = (ShaderArg*)((NiD3DShaderProgramFactory_00e93020*)DAT_0126fa10)->FUN_00e93020(apShaderName);
    if (pkShader)
        return pkShader;

    NiD3DShaderProgramCreator* pkCreator = FUN_00e932f0(apCreatorName);
    if (!pkCreator)
        return (ShaderArg*)pkCreator;

    ShaderArg* pkNewShader =
        pkCreator->CreateShader(p0, p1, apShaderName, aiParam0, aiParam1, aiParam2, aiParam3, aiParam4, aiParam5);
    ((FUN_00e937f0_shell*)DAT_0126fa10)->AddShader(pkNewShader);
    return pkNewShader;
}
}  // namespace fnv_00e93850

bool __cdecl FUN_00aa1a30(const char* pcName, int eMode);
extern "C" int __cdecl FUN_00ec65a6(char* d, unsigned int n, const char* s);
int __cdecl FUN_00aa0020(int, bool, const char*, ...);
void __cdecl FUN_00e983f0(const char* pcPath, char* pcDrive, char* pcDir, char* pcFName, char* pcExt);
int __cdecl FUN_00a305b0(char* d, unsigned int n, const char* fmt, ...);
struct ShPF_Node
{
    ShPF_Node* m_pkNext;
    ShPF_Node* m_pkPrev;
    const char* m_element;
};
struct ShPF_Factory
{
    void* vt;
    int m4;
    ShPF_Node* m_pkHead;
    ShPF_Node* GetHeadPos() const
    {
        return m_pkHead;
    }
    const char*& GetNext(ShPF_Node*& kPos) const
    {
        const char*& element = kPos->m_element;
        kPos = kPos->m_pkNext;
        return element;
    }
    const char* GetFirstDir(ShPF_Node*& kIter) const
    {
        kIter = GetHeadPos();
        if (kIter)
            return GetNext(kIter);
        return 0;
    }
    const char* GetNextDir(ShPF_Node*& kIter) const
    {
        if (kIter)
            return GetNext(kIter);
        return 0;
    }
};
inline ShPF_Factory* ShPF_Get()
{
    return (ShPF_Factory*)DAT_0126fa10;
}
// Resolves a shader program file path by checking registered directories and returns true if the file exists.
// @fnv 0x00e930a0
bool FindShaderProgramFile(const char* pcShaderName, char* pcResolvedPath, unsigned int uiBufferLength)
{
    if (FUN_00aa1a30(pcShaderName, 0))
    {
        FUN_00ec65a6(pcResolvedPath, uiBufferLength, pcShaderName);
        return true;
    }
    if (!ShPF_Get())
    {
        FUN_00aa0020(1, false, "No valid shader program factory\n");
        return false;
    }
    char acDrive[4];
    char acDir[260];
    char acFileName[260];
    char acExt[256];
    FUN_00e983f0(pcShaderName, acDrive, acDir, acFileName, acExt);
    ShPF_Node* kIter;
    const char* pcDir = ShPF_Get()->GetFirstDir(kIter);
    while (pcDir)
    {
        char valid = pcDir[0];
        if (valid)
        {
            if (pcDir[strlen(pcDir) - 1] != '/' && pcDir[strlen(pcDir) - 1] != '\\')
                FUN_00a305b0(pcResolvedPath, uiBufferLength, "%s\\%s%s", pcDir, acFileName, acExt);
            else
                FUN_00a305b0(pcResolvedPath, uiBufferLength, "%s%s%s", pcDir, acFileName, acExt);
        }
        else
        {
            FUN_00aa0020(1, false, "Invalid or no shader program directory\n");
        }
        if (valid)
        {
            if (FUN_00aa1a30(pcResolvedPath, 0))
                return true;
            FUN_00aa0020(1, true, "Shader program file not found %s in directory %s\n", pcShaderName, pcDir);
        }
        pcDir = ShPF_Get()->GetNextDir(kIter);
    }
    return false;
}

namespace fnv_00e932f0 {
struct FUN_00a53c30_Map
{
    bool __thiscall FUN_00a53c30(const char* key, void*& value);
};

void __cdecl FUN_00e98430(const char* source, char* destination, unsigned int size);
char __cdecl FUN_00ec67aa(int c);

// Looks up a value in DAT_0126fa14 using the lowercased extension, or the filename when no extension is extracted.
// @fnv 0x00e932f0
void* __cdecl FUN_00e932f0(const char* pcFilename)
{
    char acFileExt[256];
    void* creator;
    const char* source;
    unsigned int index;

    if (DAT_0126fa14 == 0)
        return 0;

    if (pcFilename == 0 || *pcFilename == 0)
        return 0;

    FUN_00e98430(pcFilename, acFileExt, 0x100);
    source = acFileExt + 1;
    if (acFileExt[1] == 0)
        source = pcFilename;
    for (index = 0; index < 0x100; ++index)
    {
        char converted = FUN_00ec67aa(source[index]);
        acFileExt[index] = converted;

        if (converted == 0)
            break;
    }

    creator = 0;
    if (((FUN_00a53c30_Map*)DAT_0126fa14)->FUN_00a53c30(acFileExt, creator))
        return creator;

    return 0;
}
}  // namespace fnv_00e932f0
