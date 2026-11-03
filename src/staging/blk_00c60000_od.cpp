
// src/staging/blk_00c60000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

extern "C" void* g_01204388;

struct FUN_00c600f0_Class
{
    void* __thiscall FUN_00c600f0();
};

// @fnv 0x00c600f0
void* __thiscall FUN_00c600f0_Class::FUN_00c600f0()
{
    return &g_01204388;
}

struct NiStream;

struct NiPSysModifier
{
    virtual void LinkObject(NiStream&);
};

struct BSPSysSimpleColorModifier : public NiPSysModifier
{
    void FUN_00c60910(NiStream& stream);
};

// @fnv 0x00c60910
void BSPSysSimpleColorModifier::FUN_00c60910(NiStream& stream)
{
    NiPSysModifier::LinkObject(stream);
}

struct FUN_00c60930_class
{
    void FUN_00c31670(void*);
    void FUN_00c60930(void* a);
};

// @fnv 0x00c60930
void FUN_00c60930_class::FUN_00c60930(void* a)
{
    FUN_00c31670(a);
}

extern "C" void* g_01204390;

struct FUN_00c60d40_Class
{
    void* __thiscall FUN_00c60d40();
};

// @fnv 0x00c60d40
void* __thiscall FUN_00c60d40_Class::FUN_00c60d40()
{
    return &g_01204390;
}

struct FUN_00c61420_Class
{
    void* __thiscall FUN_00c61420(void* p);
};

// @fnv 0x00c61420
void* __thiscall FUN_00c61420_Class::FUN_00c61420(void* apUnused)
{
    return this;
}

struct FUN_00a99870_Class
{
    void __thiscall FUN_00a99870(int, int);
};

void __thiscall FUN_00a99870_Class::FUN_00a99870(int, int)
{}

struct FUN_00c61430_Class
{
    void __thiscall FUN_00c61430(int, int);
};

// @fnv 0x00c61430
void __thiscall FUN_00c61430_Class::FUN_00c61430(int a, int b)
{
    ((FUN_00a99870_Class*)this)->FUN_00a99870(a, b);
}

struct FUN_00c61450_Class
{
    void FUN_00a99a90(int);
    void FUN_00c61450(int a);
};

// @fnv 0x00c61450
void FUN_00c61450_Class::FUN_00c61450(int aiValue)
{
    FUN_00a99a90(aiValue);
}

struct FUN_00a9af00_class
{
    void FUN_00a9af00(int a);
};

struct FUN_00c61470_class : FUN_00a9af00_class
{
    void CallBaseWithArg(int a);
};

// @fnv 0x00c61470
void FUN_00c61470_class::CallBaseWithArg(int aiValue)
{
    FUN_00a9af00(aiValue);
}

struct FUN_00c61490_Class
{
    bool FUN_00a89ae0(const void* arg);
    bool IsNot(const void* arg);
};

// Returns the logical negation of FUN_00a89ae0(arg).
// @fnv 0x00c61490
bool FUN_00c61490_Class::IsNot(const void* arg)
{
    return !FUN_00a89ae0(arg);
}

struct FUN_00c614c0_Class
{
    void __thiscall FUN_00a89210(void*);
    void __thiscall FUN_00c614c0(void* ap);
};

// @fnv 0x00c614c0
void __thiscall FUN_00c614c0_Class::FUN_00c614c0(void* ap)
{
    FUN_00a89210(ap);
}

struct FUN_00c614e0_Class
{
    char FUN_00a998e0(int arg);
    char FUN_00c614e0(int arg);
};
// Calls FUN_00a998e0 with arg and returns its result.
// @fnv 0x00c614e0
char FUN_00c614e0_Class::FUN_00c614e0(int arg)
{
    char result = FUN_00a998e0(arg);
    return result;
}

struct NiFixedString;
struct NiAVObject
{
    void SetName(NiFixedString const&);
    void FUN_00c61610();
};
extern NiFixedString* DAT_012043a0;

// @fnv 0x00c61610
void NiAVObject::FUN_00c61610()
{
    SetName(*DAT_012043a0);
}

extern "C" void* g_012043a4;

struct FUN_00c61810_class
{
    void* FUN_00c61810();
};

// @fnv 0x00c61810
void* FUN_00c61810_class::FUN_00c61810()
{
    return &g_012043a4;
}

struct FUN_00c61820_class
{
    void* FUN_00c61820(int);
};

// @fnv 0x00c61820
void* FUN_00c61820_class::FUN_00c61820(int)
{
    return this;
}

struct NiStream;

struct NiPSysVolumeEmitter
{
    void LoadBinary(NiStream&);
    void LoadBinaryFromStream(NiStream* stream);
};

// @fnv 0x00c61ef0
void NiPSysVolumeEmitter::LoadBinaryFromStream(NiStream* stream)
{
    LoadBinary(*stream);
}

namespace fnv_00c61f10 {
struct NiStream;
struct NiPSysVolumeEmitter
{
    void LinkObject(NiStream&);
    void FUN_00c61f10(NiStream& stream);
};

// @fnv 0x00c61f10
void NiPSysVolumeEmitter::FUN_00c61f10(NiStream& stream)
{
    LinkObject(stream);
}
}  // namespace fnv_00c61f10

struct NiStream;
struct NiObject
{
    void FUN_00c62140();
    void LinkObject(NiStream&);
    void FUN_00c61f30(NiStream& stream);
};
// @fnv 0x00c61f30
void NiObject::FUN_00c61f30(NiStream& stream)
{
    FUN_00c62140();
    LinkObject(stream);
}

struct FUN_00c61f60_class
{
    void __thiscall FUN_00c2f4f0(int);
    void __thiscall FUN_00c61f60(int);
};

// @fnv 0x00c61f60
void __thiscall FUN_00c61f60_class::FUN_00c61f60(int arg)
{
    FUN_00c2f4f0(arg);
}

struct FUN_00c61f80_cls
{
    void FUN_00c31b60(void* apParam);
    void FUN_00c61f80(void* apParam);
};

// @fnv 0x00c61f80
void FUN_00c61f80_cls::FUN_00c61f80(void* apParam)
{
    FUN_00c31b60(apParam);
}

struct NiAVObject;
struct NiPSysCylinderEmitter
{
    bool FUN_00c31b80(NiAVObject*);
    bool FUN_00c61fa0(NiAVObject*);
};

// @fnv 0x00c61fa0
bool NiPSysCylinderEmitter::FUN_00c61fa0(NiAVObject* ap)
{
    return FUN_00c31b80(ap);
}

struct FUN_00c627e0_Class
{
    void __thiscall FUN_00c62140();
    void __thiscall FUN_00c627e0(void* p);
};

// @fnv 0x00c627e0
void __thiscall FUN_00c627e0_Class::FUN_00c627e0(void* pValue)
{
    *(void**)((char*)this + 0x54) = pValue;
    FUN_00c62140();
}

extern "C" void* g_012043b8;

struct FUN_00c632e0_Class
{
    void* __thiscall FUN_00c632e0();
};

// @fnv 0x00c632e0
void* __thiscall FUN_00c632e0_Class::FUN_00c632e0()
{
    return &g_012043b8;
}

namespace fnv_00c63930 {
struct NiStream;
struct NiPSysModifier
{
    virtual void LinkObject(NiStream&);
};
struct FUN_00c63930_Class : public NiPSysModifier
{
    void FUN_00c63930(NiStream&);
};
// @fnv 0x00c63930
void FUN_00c63930_Class::FUN_00c63930(NiStream& stream)
{
    NiPSysModifier::LinkObject(stream);
}
}  // namespace fnv_00c63930

struct FUN_00c31670_class
{
    void __thiscall FUN_00c31670(int a);
};

struct FUN_00c63950_class
{
    void __thiscall ForwardToOther(int a);
};

// @fnv 0x00c63950
void __thiscall FUN_00c63950_class::ForwardToOther(int aiValue)
{
    ((FUN_00c31670_class*)this)->FUN_00c31670(aiValue);
}

struct GlobalObject_00a7b610;
extern GlobalObject_00a7b610 g_012043c8;

struct FUN_00c63aa0_class
{
    GlobalObject_00a7b610* FUN_00c63aa0();
};

// @fnv 0x00c63aa0
GlobalObject_00a7b610* FUN_00c63aa0_class::FUN_00c63aa0()
{
    return &g_012043c8;
}

void __cdecl FUN_00c63c30(int, int);

// @fnv 0x00c63c10
void __cdecl CallWithSameArgumentTwice(int aiValue)
{
    FUN_00c63c30(aiValue, aiValue);
}

struct NiBinaryExtraData
{
    void LinkObject(void*);
};

struct BSDecalPlacementVectorExtraData : NiBinaryExtraData
{
    void LinkToObject(void*);
};

// @fnv 0x00c644b0
void BSDecalPlacementVectorExtraData::LinkToObject(void* apObject)
{
    LinkObject(apObject);
}

struct FUN_00c644d0_Class
{
    unsigned char Equals(const char*);
    unsigned char FUN_00c644d0(const char*);
};
// Calls Equals with arg and returns its result.
// @fnv 0x00c644d0
unsigned char FUN_00c644d0_Class::FUN_00c644d0(const char* arg)
{
    unsigned char result = Equals(arg);
    return result;
}

extern "C" void* g_012043d4;

struct FUN_00c64600_Class
{
    void* __thiscall GetGlobalPointer();
};

// @fnv 0x00c64600
void* __thiscall FUN_00c64600_Class::GetGlobalPointer()
{
    return &g_012043d4;
}

namespace fnv_00c64950 {
struct NiStream
{
    void FUN_00a64160(const char*);
};
struct NiObject
{
    void LinkObject(NiStream&);
    void FUN_00c64950(NiStream* stream);
};
// Links this object to the stream, then passes the string pointer at offset 8 to the stream's FUN_00a64160.
// @fnv 0x00c64950
void NiObject::FUN_00c64950(NiStream* stream)
{
    LinkObject(*stream);
    stream->FUN_00a64160(*(const char**)((char*)this + 8));
}
}  // namespace fnv_00c64950

namespace fnv_00c64aa0 {
struct NiStream
{
    unsigned int ReadUnsignedInteger();
};

struct NiObject
{
    void LoadBinary(NiStream& stream);
    void FUN_00c64aa0(NiStream& stream);
};

// @fnv 0x00c64aa0
void NiObject::FUN_00c64aa0(NiStream& stream)
{
    LoadBinary(stream);
    stream.ReadUnsignedInteger();
}
}  // namespace fnv_00c64aa0

struct NiStream;
struct NiObjectBase
{
    bool RegisterStreamables(NiStream&);
};
struct FUN_00c64b70 : NiObjectBase
{
    bool RegisterStreamables(NiStream& stream);
};
// @fnv 0x00c64b70
bool FUN_00c64b70::RegisterStreamables(NiStream& stream)
{
    return NiObjectBase::RegisterStreamables(stream);
}

struct FUN_00c64fc0_class
{
    int __thiscall GetThisAddress(int);
};

// @fnv 0x00c64fc0
int __thiscall FUN_00c64fc0_class::GetThisAddress(int)
{
    return (int)this;
}

struct NiStream;
struct NiExtraData
{
    void LinkObject(NiStream& stream);
    void FUN_00c65160(NiStream& stream);
};

// @fnv 0x00c65160
void NiExtraData::FUN_00c65160(NiStream& stream)
{
    LinkObject(stream);
}

struct C00c541e0
{
    bool FUN_00a7b3d0(int);
    bool FUN_00c65290(int a);
};

// Calls FUN_00a7b3d0 with the given int and returns its bool result.
// @fnv 0x00c65290
bool C00c541e0::FUN_00c65290(int aiValue)
{
    bool result = FUN_00a7b3d0(aiValue);
    return result;
}

extern "C" void* DAT_012043f0;

struct FUN_00c657e0_class
{
    void* GetGlobalDataPtr();
};

// @fnv 0x00c657e0
void* FUN_00c657e0_class::GetGlobalDataPtr()
{
    return &DAT_012043f0;
}

extern "C" void NiFreeAlias(void*);
extern int DAT_010c377c;

struct NiTPointerList_00c62890
{
    void* m_pObjectItem;
    void* m_pNext;
    void FUN_00c62890();
};

// @fnv 0x00c62890
void NiTPointerList_00c62890::FUN_00c62890()
{
    m_pObjectItem = &DAT_010c377c;
    void* result = m_pNext;
    NiFreeAlias(result);
}

extern "C" void NiFreeAlias(void*);
extern int DAT_010c3a08;
struct FUN_00c65680_Class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void __thiscall FUN_00c65680();
};
// @fnv 0x00c65680
void __thiscall FUN_00c65680_Class::FUN_00c65680()
{
    m_iWordAt00 = &DAT_010c3a08;
    void* p = m_iWordAt04;
    NiFreeAlias(p);
}

struct FUN_00c600c0_class
{
    void* __thiscall FUN_00c5fd50();
    void* __thiscall FUN_00c600c0(unsigned int flags);
    static void __cdecl operator delete(void* p, unsigned int size);
};

// Calls FUN_00c5fd50, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00c600c0
void* __thiscall FUN_00c600c0_class::FUN_00c600c0(unsigned int flags)
{
    FUN_00c5fd50();
    if (flags & 1)
        operator delete(this, 0x1c);
    return this;
}

struct FUN_00c613a0_Class
{
    void __thiscall FUN_00c613a0();
    void* __thiscall FUN_00c617e0(unsigned int flags);
    void operator delete(void* p, unsigned int size);
};
// @fnv 0x00c617e0
void* __thiscall FUN_00c613a0_Class::FUN_00c617e0(unsigned int flags)
{
    this->FUN_00c613a0();
    if (flags & 1)
        this->operator delete(this, 20);
    return this;
}

extern "C" void NiFree(void*);
struct MemoryManager
{
    void Deallocate(void*);
};
extern MemoryManager g_memoryManager;
struct FUN_00c63210_Class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* __thiscall FUN_00c63210(int flag);
};
// Sets the first field to a global, frees the second field with NiFree, and deallocates this if flag bit 0 is set.
// @fnv 0x00c63210
void* __thiscall FUN_00c63210_Class::FUN_00c63210(int flag)
{
    m_iWordAt00 = &DAT_010c377c;
    void* p = m_iWordAt04;
    NiFree(p);
    if (flag & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

struct FUN_00a7b300_shell
{
    void __thiscall FUN_00a7b300();
};
struct FUN_00c632f0_class
{
    void* __thiscall FUN_00c632f0(unsigned int flags);
};
void __cdecl operator delete(void*, int);
// @fnv 0x00c632f0
void* __thiscall FUN_00c632f0_class::FUN_00c632f0(unsigned int flags)
{
    reinterpret_cast<FUN_00a7b300_shell*>(this)->FUN_00a7b300();
    if (flags & 1)
        operator delete(this, 12);
    return this;
}

struct CloningProcess;
struct NiPSysModifierCopy : NiPSysModifier
{
    void CopyMemberData(NiPSysModifier* dst, CloningProcess& proc);
};
struct FUN_00c63840_Class : NiPSysModifier
{
    void __thiscall CopyModifierWithValue(NiPSysModifier* dst, CloningProcess* proc);
};
// @fnv 0x00c63840
void __thiscall FUN_00c63840_Class::CopyModifierWithValue(NiPSysModifier* dst, CloningProcess* proc)
{
    ((NiPSysModifierCopy*)this)->CopyMemberData(dst, *proc);
    float value = *(float*)((char*)this + 0x20);
    *(float*)((char*)dst + 0x20) = value;
}

struct SStream;
struct SObj;
void __cdecl CallAnimCallback(SStream*, SObj*);
struct NiPSysModifier_00c31950
{
    void __thiscall FUN_00c31950(void*);
};
struct FUN_00c63970_class : NiPSysModifier_00c31950
{
    void __thiscall FUN_00c63970(void* stream);
};
// @fnv 0x00c63970
void __thiscall FUN_00c63970_class::FUN_00c63970(void* stream)
{
    FUN_00c31950(stream);
    CallAnimCallback(reinterpret_cast<SStream*>(stream), reinterpret_cast<SObj*>(this + 0x20));
}

void __cdecl FUN_00c63b40(void* p);
void __cdecl operator delete(void* p, unsigned int size);
struct FUN_00c64610_Class
{
    void __thiscall FUN_00c63b40();
    void* __thiscall FUN_00c64610(unsigned int flags);
};
// Calls FUN_00c63b40, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00c64610
void* __thiscall FUN_00c64610_Class::FUN_00c64610(unsigned int flags)
{
    FUN_00c63b40();
    if (flags & 1)
        operator delete(this, 0x40);
    return this;
}

namespace fnv_00c64710 {
struct MemoryManager
{
    void Deallocate(void*);
};
extern MemoryManager g_memoryManager;
struct FUN_00c64710_Class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void FUN_00c64710();
};
// @fnv 0x00c64710
void FUN_00c64710_Class::FUN_00c64710()
{
    void* p = m_iWordAt00;
    while (p)
    {
        void* next = p;
        p = *reinterpret_cast<void**>(p);
        *reinterpret_cast<void**>(reinterpret_cast<char*>(next) + 8) = 0;
        void* pFreed = next;
        g_memoryManager.Deallocate(pFreed);
    }
    m_8 = 0;
    m_iWordAt00 = 0;
    m_iWordAt04 = 0;
}
}  // namespace fnv_00c64710

struct FUN_00c64930_Class
{
    void FUN_00c64930(int a);
};

// @fnv 0x00c64930
void FUN_00c64930_Class::FUN_00c64930(int a)
{}

struct FUN_00c64940_Class
{
    bool FUN_00c64940(int a);
};
// @fnv 0x00c64940
bool FUN_00c64940_Class::FUN_00c64940(int a)
{
    return true;
}

struct FUN_00c64c30_Class
{
    bool __thiscall FUN_00c64c30(int a);
};

// @fnv 0x00c64c30
bool __thiscall FUN_00c64c30_Class::FUN_00c64c30(int a)
{
    return false;
}

extern int DAT_010c3384;
struct NiPSysPositionModifier
{
    NiPSysPositionModifier();
    ~NiPSysPositionModifier();
};
struct FUN_00c60240 : NiPSysPositionModifier
{
    int m_vt;
    float m_f[4];
    float m_v[4];
    float m_w[4];
    FUN_00c60240();
};
// Constructor: sets the vtable pointer and zeroes the four-float arrays at offsets 0x18, 0x28 and 0x38.
// @fnv 0x00c60240
FUN_00c60240::FUN_00c60240()
{
    m_vt = (int)&DAT_010c3384;
    {
        float* p = (float*)((char*)this + 0x18);
        p[0] = 0.0f;
        p[1] = 0.0f;
        p[2] = 0.0f;
        p[3] = 0.0f;
    }
    {
        float* q = (float*)((char*)this + 0x28);
        q[0] = 0.0f;
        q[1] = 0.0f;
        q[2] = 0.0f;
        q[3] = 0.0f;
    }
    {
        float* r = (float*)((char*)this + 0x38);
        r[0] = 0.0f;
        r[1] = 0.0f;
        r[2] = 0.0f;
        r[3] = 0.0f;
    }
}

struct NiStream;
struct RgbaColor
{
    void SaveBinary(NiStream&);
};
struct FUN_00c60950_class : NiPSysModifier_00c31950
{
    void FUN_00c60950(NiStream* stream);
};
// @fnv 0x00c60950
void FUN_00c60950_class::FUN_00c60950(NiStream* stream)
{
    FUN_00c31950(stream);
    CallAnimCallback((SStream*)stream, (SObj*)((char*)this + 0x48));
    CallAnimCallback((SStream*)stream, (SObj*)((char*)this + 0x4c));
    CallAnimCallback((SStream*)stream, (SObj*)((char*)this + 0x50));
    CallAnimCallback((SStream*)stream, (SObj*)((char*)this + 0x54));
    CallAnimCallback((SStream*)stream, (SObj*)((char*)this + 0x58));
    CallAnimCallback((SStream*)stream, (SObj*)((char*)this + 0x5c));
    ((RgbaColor*)((char*)this + 0x18))->SaveBinary(*stream);
    ((RgbaColor*)((char*)this + 0x28))->SaveBinary(*stream);
    ((RgbaColor*)((char*)this + 0x38))->SaveBinary(*stream);
}

int _sprintf_s(char*, unsigned int, const char*, ...);
size_t _strlen(const char*);
struct P03MM
{
    void* __thiscall Allocate(unsigned int);
};
struct FUN_00c62090_Class
{
    char* __thiscall BuildAttachTypeString(const char* name, int type);
};
// Allocates strlen(name)+0x10 bytes and formats name with an AT_* attach-type suffix chosen by type (0 vertices, 1 specific objs, 2 nodes).
// @fnv 0x00c62090
char* __thiscall FUN_00c62090_Class::BuildAttachTypeString(const char* name, int type)
{
    unsigned int size = _strlen(name) + 0x10;
    char* buffer = (char*)((P03MM*)&g_memoryManager)->Allocate(size);
    char* result = buffer;
    switch (type)
    {
    case 0:
        _sprintf_s(result, size, "%s = AT_VERTICES", name);
        break;
    case 1:
        _sprintf_s(result, size, "%s = AT_SPECIFICOBJS", name);
        break;
    case 2:
        _sprintf_s(result, size, "%s = AT_NODES", name);
        break;
    }
    return result;
}

extern GlobalObject_00a7b610 g_012043b0;

struct FUN_00c63320_Class
{
    GlobalObject_00a7b610* __thiscall FUN_00c63320();
};

// @fnv 0x00c63320
GlobalObject_00a7b610* FUN_00c63320_Class::FUN_00c63320()
{
    return &g_012043b0;
}

struct NiStream
{
    void SerializeString(const char* s);
};
struct NiExtraDataSaveHelper
{
    void SaveBinary(NiStream& s);
};
struct FUN_00c65210_class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* m_iThirdValue;
    void* m_10;
    void* m_14;
    unsigned short m_18;
    void __thiscall FUN_00c65210(NiStream& stream);
};
void __cdecl FUN_0044adf0(NiStream& stream, const unsigned int& count);
// @fnv 0x00c65210
void __thiscall FUN_00c65210_class::FUN_00c65210(NiStream& stream)
{
    ((NiExtraDataSaveHelper*)this)->SaveBinary(stream);
    unsigned int count = m_18;
    FUN_0044adf0(stream, count);
    for (unsigned int i = 0; i < count; i++)
    {
        const char* pcString = ((const char**)m_10)[i];
        stream.SerializeString(pcString);
        stream.SerializeString(pcString + 4);
    }
}

extern "C" void* __cdecl NiMalloc(unsigned int size);
struct FUN_00c65760_Class
{
    int* m_pVtbl;
    void* m_pData;
    unsigned short m_iArrayLength;
    unsigned short m_iFlags;
    unsigned short m_iPad;
    unsigned short m_iType;
    void* __thiscall InitArray(unsigned short count, unsigned short type);
};
// Sets the vtable, stores count and type, clears flags, and allocates count ints into m_pData (or null when count is 0).
// @fnv 0x00c65760
void* __thiscall FUN_00c65760_Class::InitArray(unsigned short count, unsigned short type)
{
    m_pVtbl = (int*)&DAT_010c3a08;
    m_iArrayLength = count;
    m_iType = type;
    m_iFlags = 0;
    m_iPad = 0;
    if (m_iArrayLength > 0)
    {
        unsigned int n = m_iArrayLength;
        m_pData = NiMalloc(n * sizeof(int));
    }
    else
        m_pData = 0;
    return this;
}

struct FUN_00c61b10
{
    char m_iWordAt00[0x6c];
    FUN_00c61b10();
    ~FUN_00c61b10();
    static void* operator new(unsigned int size);
};
// Allocates and constructs a new FUN_00c61b10 object, returning the pointer.
// @fnv 0x00c61e70
FUN_00c61b10* FUN_00c61e70()
{
    return new FUN_00c61b10;
}

extern "C" void* __cdecl NiMalloc(unsigned int);

struct FUN_00c63260_class
{
    int* m_ppVirtualMethodTable;
    void* m_data;
    unsigned short m_uiX;
    unsigned short m_iElementCount;
    unsigned short m_uiItemCount;
    unsigned short m_uiY;
    FUN_00c63260_class(unsigned short x, unsigned short y);
};

// @fnv 0x00c63260
FUN_00c63260_class::FUN_00c63260_class(unsigned short x, unsigned short y)
{
    m_ppVirtualMethodTable = &DAT_010c377c;
    m_uiX = x;
    m_uiY = y;
    m_iElementCount = 0;
    m_uiItemCount = 0;
    if (m_uiX > 0)
    {
        int i = m_uiX;
        m_data = NiMalloc(i << 2);
    }
    else
        m_data = 0;
}

struct NiPoint3_ZERO
{
    int x;
    int y;
    int z;
};
extern NiPoint3_ZERO _NiPoint3_ZERO;
extern int _DAT_011f4270;
extern int _DAT_011f4274;
extern int DAT_010c37fc;
struct FUN_00c63330 : NiPSysPositionModifier
{
    FUN_00c63330();
};
// Initializes the object's vtable pointer, sets field 3 to 0xbb8, zeroes two NiPoint3 members at offsets 0x24 and 0x30, and clears floats at indices 6 and 8.
// @fnv 0x00c63330
FUN_00c63330::FUN_00c63330()
{
    ((int*)this)[0] = (int)&DAT_010c37fc;
    ((int*)this)[3] = 0xbb8;
    *(NiPoint3_ZERO*)((char*)this + 0x24) = _NiPoint3_ZERO;
    *(NiPoint3_ZERO*)((char*)this + 0x30) = _NiPoint3_ZERO;
    ((float*)this)[8] = 0.0f;
    ((float*)this)[6] = 0.0f;
}

int strcpy_s(char* dst, unsigned int size, const char* src);
size_t strlen(const char*);
struct MemoryManagerAllocHelper
{
    void* Allocate(unsigned int);
};
struct FUN_00c64780_Class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void FUN_00c64780(const char* apName);
};
// Frees the stored string, then allocates a copy of apName (if non-null) and stores it in m_8.
// @fnv 0x00c64780
void FUN_00c64780_Class::FUN_00c64780(const char* apName)
{
    unsigned int uiSize;
    void* pOld7 = m_8;
    g_memoryManager.Deallocate(pOld7);
    m_8 = 0;
    if (apName)
    {
        uiSize = strlen(apName) + 1;
        void* pNew = ((MemoryManagerAllocHelper*)&g_memoryManager)->Allocate(uiSize);
        m_8 = pNew;
        if (m_8)
        {
            char* pBuffer2 = (char*)m_8;
            strcpy_s(pBuffer2, uiSize, apName);
        }
    }
}

struct FUN_00c65710_Class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* __thiscall FUN_00c65710(unsigned int flags);
};
// @fnv 0x00c65710
void* __thiscall FUN_00c65710_Class::FUN_00c65710(unsigned int flags)
{
    void* p;
    m_iWordAt00 = &DAT_010c3a08;
    p = m_iWordAt04;
    NiFree(p);
    if (flags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

struct IsEqualHelper
{
    bool __thiscall IsEqual(NiObject* arg);
};

struct FUN_00c60000_Class
{
    bool __thiscall IsEqualWithFloat(void* arg);
};

// Calls IsEqual on arg, then returns whether the float at offset 24 of arg equals the one at offset 24 of this.
// @fnv 0x00c60000
bool __thiscall FUN_00c60000_Class::IsEqualWithFloat(void* apObject)
{
    if (!((IsEqualHelper*)this)->IsEqual((NiObject*)apObject))
        return false;
    void* p = apObject;
    if (((float*)p)[6] == ((float*)this)[6])
        return true;
    return false;
}

struct FUN_00c60700_Group
{
    unsigned int value00;
    unsigned int value04;
    unsigned int value08;
    unsigned int value0c;
};

struct FUN_00c60700_Data
{
    unsigned char padding[0x18];
    FUN_00c60700_Group group00;
    FUN_00c60700_Group group10;
    FUN_00c60700_Group group20;
    float value30;
    float value34;
    float value38;
    float value3c;
    float value40;
    float value44;
};

struct FUN_00c60700_Class : NiPSysModifierCopy
{
    void FUN_00c60700(NiPSysModifier* dst, CloningProcess& proc);
};

// @fnv 0x00c60700
void FUN_00c60700_Class::FUN_00c60700(NiPSysModifier* dst, CloningProcess& proc)
{
    this->CopyMemberData(dst, proc);

    ((FUN_00c60700_Data*)dst)->group00 = ((FUN_00c60700_Data*)this)->group00;
    ((FUN_00c60700_Data*)dst)->group10 = ((FUN_00c60700_Data*)this)->group10;
    ((FUN_00c60700_Data*)dst)->group20 = ((FUN_00c60700_Data*)this)->group20;

    ((FUN_00c60700_Data*)dst)->value30 = ((FUN_00c60700_Data*)this)->value30;
    ((FUN_00c60700_Data*)dst)->value34 = ((FUN_00c60700_Data*)this)->value34;
    ((FUN_00c60700_Data*)dst)->value38 = ((FUN_00c60700_Data*)this)->value38;
    ((FUN_00c60700_Data*)dst)->value3c = ((FUN_00c60700_Data*)this)->value3c;
    ((FUN_00c60700_Data*)dst)->value40 = ((FUN_00c60700_Data*)this)->value40;
    ((FUN_00c60700_Data*)dst)->value44 = ((FUN_00c60700_Data*)this)->value44;
}

template <class T> void __cdecl ReadBinaryValue(NiStream& stream, T& value);

struct NiPSysModifierLoadBinary_StandIn
{
    void LoadBinary(NiStream& stream);
};

struct NiColorALoadBinary_StandIn
{
    void LoadBinary(NiStream& stream);
};

struct FUN_00c60850_Class : public NiPSysModifier
{
    void FUN_00c60850(NiStream& stream);
};

// @fnv 0x00c60850
void FUN_00c60850_Class::FUN_00c60850(NiStream& stream)
{
    reinterpret_cast<NiPSysModifierLoadBinary_StandIn*>(this)->LoadBinary(stream);

    ReadBinaryValue<unsigned int>(stream, *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x48));
    ReadBinaryValue<unsigned int>(stream, *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x4c));
    ReadBinaryValue<unsigned int>(stream, *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x50));
    ReadBinaryValue<unsigned int>(stream, *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x54));
    ReadBinaryValue<unsigned int>(stream, *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x58));
    ReadBinaryValue<unsigned int>(stream, *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x5c));

    reinterpret_cast<NiColorALoadBinary_StandIn*>(reinterpret_cast<char*>(this) + 0x18)->LoadBinary(stream);
    reinterpret_cast<NiColorALoadBinary_StandIn*>(reinterpret_cast<char*>(this) + 0x28)->LoadBinary(stream);
    reinterpret_cast<NiColorALoadBinary_StandIn*>(reinterpret_cast<char*>(this) + 0x38)->LoadBinary(stream);
}

struct MyIsEqual
{
    bool __thiscall FUN_00c31830(NiObject*);
};

struct FUN_004a4cc0_shell
{
    bool __thiscall FUN_004a4cc0(void*);
};

struct FUN_00c60a10_Class
{
    unsigned char m_00[0x48];
    float m_48;
    float m_4c;
    float m_50;
    float m_54;
    float m_58;
    float m_5c;

    bool __thiscall FUN_00c60a10(NiObject*);
};

// @fnv 0x00c60a10
bool FUN_00c60a10_Class::FUN_00c60a10(NiObject* pObject)
{
    if (!reinterpret_cast<MyIsEqual*>(this)->FUN_00c31830(pObject))
        return false;

    FUN_00c60a10_Class* pOther = reinterpret_cast<FUN_00c60a10_Class*>(pObject);

    if (pOther->m_48 == m_48 && pOther->m_4c == m_4c && pOther->m_50 == m_50 && pOther->m_54 == m_54 &&
        pOther->m_58 == m_58 && pOther->m_5c == m_5c &&
        reinterpret_cast<FUN_004a4cc0_shell*>(reinterpret_cast<char*>(pOther) + 0x18)
            ->FUN_004a4cc0(reinterpret_cast<char*>(this) + 0x18) &&
        reinterpret_cast<FUN_004a4cc0_shell*>(reinterpret_cast<char*>(pOther) + 0x28)
            ->FUN_004a4cc0(reinterpret_cast<char*>(this) + 0x28) &&
        reinterpret_cast<FUN_004a4cc0_shell*>(reinterpret_cast<char*>(pOther) + 0x38)
            ->FUN_004a4cc0(reinterpret_cast<char*>(this) + 0x38))
        return true;

    return false;
}

void __cdecl FUN_00c31750(void);
void __cdecl operator delete(void* p, unsigned int size);

struct FUN_00c60d10_Class
{
    void FUN_00c31750();
    void* __thiscall FUN_00c60d10(unsigned int flags);
};

// @fnv 0x00c60d10
void* FUN_00c60d10_Class::FUN_00c60d10(unsigned int flags)
{
    FUN_00c31750();
    if (flags & 1)
        operator delete(this, 0x60);
    return this;
}

struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int size);
};

struct FUN_00c612b0_Class : NiAVObject, A51BF0Base
{
    unsigned char m_data[19];

    FUN_00c612b0_Class();
};

extern NiFixedString DAT_011f49e0;

// Allocates a FUN_00c612b0_Class object, sets its name to DAT_011f49e0, and returns it as an NiAVObject.
// @fnv 0x00c61510
NiAVObject* __cdecl FUN_00c61510()
{
    NiAVObject* object = new FUN_00c612b0_Class;
    object->SetName(DAT_011f49e0);
    return object;
}

struct FUN_00a7b330_shell
{
    void FUN_00a7b330(void* a, void* b);
};
struct FUN_00c61830_class
{
    void FUN_00c61830(void* a, void* b);
};
// @fnv 0x00c61830
void FUN_00c61830_class::FUN_00c61830(void* a, void* b)
{
    ((FUN_00a7b330_shell*)this)->FUN_00a7b330(a, b);
}

struct FUN_00c62390_class
{
    void FUN_00c62390(void*, void*);
};
struct FUN_00c61ba0_class : FUN_00c62390_class
{
    void ForwardToBase(void* a, void* b, void* c);
};
// @fnv 0x00c61ba0
void FUN_00c61ba0_class::ForwardToBase(void* apUnused, void* apArg1, void* apArg2)
{
    FUN_00c62390(apArg1, apArg2);
}

namespace fnv_00c61bc0 {
extern unsigned int _data_011c16bc;

struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int size);
};

struct FUN_00c61bc0_class
{
    void __thiscall FUN_00c61c50(FUN_00c61b10* object, int arg);
    FUN_00c61b10* __thiscall CreateObject(int arg);
};

// Allocates a new FUN_00c61b10, initialises it via FUN_00c61c50 with arg, and returns the object.
// @fnv 0x00c61bc0
FUN_00c61b10* __thiscall FUN_00c61bc0_class::CreateObject(int arg)
{
    FUN_00c61b10* object = new FUN_00c61b10;
    FUN_00c61c50(object, arg);
    return object;
}
}  // namespace fnv_00c61bc0

template <class T> void ReadBinaryValue(NiStream&, T&);
struct NiPSysModifierStub
{
    virtual void LoadBinary(NiStream&);
};
struct FUN_00c63900_class : NiPSysModifierStub
{
    void LoadModifierData(NiStream& stream);
};
// @fnv 0x00c63900
void FUN_00c63900_class::LoadModifierData(NiStream& stream)
{
    NiPSysModifierStub::LoadBinary(stream);
    ReadBinaryValue<unsigned int>(stream, *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x20));
}

void __cdecl operator delete(void* p, unsigned int size);

struct FUN_00c31750_Class
{
    void __thiscall FUN_00c31750();
};

struct FUN_00c63a70_Class
{
    void* __thiscall FUN_00c63a70(unsigned int flags);
};

// Calls FUN_00c31750 on this, deletes this with size 0x3c when flags has bit 1 set, and returns this.
// @fnv 0x00c63a70
void* __thiscall FUN_00c63a70_Class::FUN_00c63a70(unsigned int flags)
{
    ((FUN_00c31750_Class*)this)->FUN_00c31750();
    if (flags & 1)
        operator delete(this, 0x3c);
    return this;
}

namespace fnv_00c64060 {
extern unsigned int _data_011c16bc;

struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int size);
};

struct FUN_00c63ab0 : A51BF0Base
{
    void* m_pData;
    char m_auiShapeKeys[0x3c];

    FUN_00c63ab0(int value);
};

FUN_00c63ab0::FUN_00c63ab0(int value)
{
    m_pData = 0;
}

struct BSDecalPlacementVectorExtraData_StandIn
{
    void* __thiscall FUN_00c640f0(void* pObject, int value);
    void* __thiscall FUN_00c64060(int value);
};

// Allocates a FUN_00c63ab0 with value 0, passes it to FUN_00c640f0 with value, and returns the new object.
// @fnv 0x00c64060
void* __thiscall BSDecalPlacementVectorExtraData_StandIn::FUN_00c64060(int value)
{
    FUN_00c63ab0* pObject = new FUN_00c63ab0(0);
    this->FUN_00c640f0(pObject, value);
    return pObject;
}
}  // namespace fnv_00c64060

struct FUN_00c64500_Class : FUN_00c61490_Class
{
    bool FUN_00c64500(const void* arg);
};

// Returns the negation of FUN_00a89ae0(arg).
// @fnv 0x00c64500
bool FUN_00c64500_Class::FUN_00c64500(const void* arg)
{
    return !FUN_00a89ae0(arg);
}

namespace fnv_00c64530 {
struct A51BF0Base : public NiAVObject
{
    char m_ucUnknownByte[0x40];

    static void* __cdecl operator new(unsigned int size);
};

struct FUN_00c63ab0 : public A51BF0Base
{
    FUN_00c63ab0(int a);
};

extern NiFixedString DAT_011f49e0;

// Allocates a FUN_00c63ab0 with argument 0, sets its name to DAT_011f49e0, and returns it.
// @fnv 0x00c64530
void* CreateNamedNode()
{
    FUN_00c63ab0* result = new FUN_00c63ab0(0);
    result->SetName(DAT_011f49e0);
    return result;
}
}  // namespace fnv_00c64530

struct A46BB0Object
{
    bool IsEqual(A46BB0Object*);
};

int __cdecl __stricmp(const char*, const char*);

struct FUN_00c64980_Class : A46BB0Object
{
    bool FUN_00c64980(A46BB0Object* arg);
};

// Returns true when IsEqual(arg) holds and both objects' string pointers at offset 8 are non-null and __stricmp-equal.
// @fnv 0x00c64980
bool FUN_00c64980_Class::FUN_00c64980(A46BB0Object* apOther)
{
    if (this->IsEqual(apOther))
    {
        A46BB0Object* p = apOther;
        if (*(void**)((char*)this + 8) != 0)
        {
            void* a = *(void**)((char*)p + 8);
            if (a != 0)
            {
                void* b = *(void**)((char*)p + 8);
                void* c = *(void**)((char*)this + 8);
                return __stricmp((const char*)c, (const char*)b) == 0;
            }
        }
    }
    return false;
}

struct FUN_0043ba10_shell
{
    FUN_0043ba10_shell* FUN_0043ba10(unsigned int);
};
struct FUN_00c64dc0_Class
{
    char m_iWordAt00;
    char m_cByteAtOffset1;
    char m_cByteAtOffset2;
    char m_cByteAtOffset3;
    FUN_0043ba10_shell m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    FUN_0043ba10_shell* FUN_00c64dc0(unsigned int a);
};
// @fnv 0x00c64dc0
FUN_0043ba10_shell* FUN_00c64dc0_Class::FUN_00c64dc0(unsigned int a)
{
    int v0;
    int v1;
    int v2;
    return m_iWordAt04.FUN_0043ba10(a);
}

void __cdecl operator delete(void* p, unsigned int size);

struct FUN_00c64e70_Class
{
    void __thiscall FUN_00c64e70();
    void* __thiscall FUN_00c65650(unsigned int flags);
};

// Calls FUN_00c64e70, then frees this with operator delete when flags has bit 1 set, and returns this.
// @fnv 0x00c65650
void* __thiscall FUN_00c64e70_Class::FUN_00c65650(unsigned int flags)
{
    this->FUN_00c64e70();
    if (flags & 1)
        operator delete(this, 0x1c);
    return this;
}

void* __cdecl FUN_00aa13e0(unsigned int size);

struct SpawnedObject_b9118
{
    char m00[0x60];
    SpawnedObject_b9118();
    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
};

// Allocates and constructs a SpawnedObject_b9118 via its custom operator new and returns the pointer.
// @fnv 0x00c607d0
SpawnedObject_b9118* FUN_00c607d0()
{
    SpawnedObject_b9118* result = new SpawnedObject_b9118();
    return result;
}

class C61330Base
{
  public:
    C61330Base(int iA, int iB);
    virtual ~C61330Base();

    int unk04;
};

class FUN_00c61330 : public C61330Base
{
  public:
    void Initialize();

    FUN_00c61330(int iA, int iB);
    virtual ~FUN_00c61330();
};

// Constructs the object by forwarding iA and iB to the C61330Base constructor, then calls Initialize().
// @fnv 0x00c61330
FUN_00c61330::FUN_00c61330(int iA, int iB) : C61330Base(iA, iB)
{
    Initialize();
}

struct FUN_00c61c50_sub
{
    void FUN_00c628c0(unsigned int n);
    void FUN_00c62b90(unsigned int n, unsigned int* p);
};
struct FUN_00c61c50_cls
{
    unsigned int pad0[0x18];
    unsigned int* m_60;
    unsigned short pad1[1];
    unsigned short m_66;
    void FUN_00c31b10(unsigned int a, unsigned int b);
    void FUN_00c61c50(unsigned int x, unsigned int y);
};
// @fnv 0x00c61c50
void FUN_00c61c50_cls::FUN_00c61c50(unsigned int x, unsigned int y)
{
    unsigned int pad[0xf];
    FUN_00c31b10(x, y);
    unsigned int n = m_66;
    if (n != 0)
    {
        ((FUN_00c61c50_sub*)(x + 0x5c))->FUN_00c628c0(n);
        while (n-- != 0)
        {
            ((FUN_00c61c50_sub*)(x + 0x5c))->FUN_00c62b90(n, &m_60[n]);
        }
    }
}

struct FUN_00c62140_Elem;
struct FUN_00c62140_Item;

struct FUN_00c62140_Val
{
    float m_00;
    unsigned char m_04;
    unsigned char m_05;
    unsigned char m_06;
    unsigned char m_07;
    unsigned char m_08;
};

struct FUN_00c62140_Item
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    void FUN_00a59c60(FUN_00c62140_Val* pVal);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    FUN_00c62140_Elem** m_a0;
    unsigned short unkA4;
    unsigned short m_a6;
};

struct FUN_00c62140_Obj
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual FUN_00c62140_Item* v03();
};

struct FUN_00c62140_Pad
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
};

struct FUN_00c62140_Pad5
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
};

struct FUN_00c62140_Sub
{
    void FUN_00c62f40();
};

struct FUN_00c62140_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    FUN_00c62140_Obj* m_54;
    int unk58;
    FUN_00c62140_Sub m_5c;

    void FUN_00c62140();
    void FUN_00c62200(FUN_00c62140_Elem* pElem);
};

// @fnv 0x00c62140
void FUN_00c62140_cls::FUN_00c62140()
{
    m_5c.FUN_00c62f40();
    FUN_00c62140_Obj* pad;
    pad = m_54;
    FUN_00c62140_Item* pItem = (0 != pad) ? pad->v03() : 0;
    if (!!pItem)
    {
        FUN_00c62140_Val val;
        val.m_00 = 0.0f;
        val.m_04 = 0;
        val.m_05 = 0;
        val.m_06 = 0;
        val.m_07 = 0;
        val.m_08 = 0;
        pItem->FUN_00a59c60(&val);
        unsigned int slot = pItem->m_a6;
        while (slot-- != 0)
        {
            FUN_00c62140_Pad5 objTmp;
            FUN_00c62140_Elem** i;
            i = &pItem->m_a0[slot];
            FUN_00c62140_Elem* e = *i;
            FUN_00c62200(e);
        }
    }
}

struct S_00c62cc0_Class
{
    void* unk0;
    void* unk4;
    unsigned short m_8;
    unsigned short m_kPointA;
    unsigned short unk_c;
    unsigned short m_usTrailingValue;

    void FUN_00c628c0(unsigned int arg);
    void FUN_00c62b90(unsigned int arg1, unsigned int arg2);
    unsigned int FUN_00c62cc0(unsigned int arg);
};

struct S_00c62cc0_Locals
{
    unsigned int value;
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
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
};

// @fnv 0x00c62cc0
unsigned int S_00c62cc0_Class::FUN_00c62cc0(unsigned int uiValue)
{
    S_00c62cc0_Locals locals;
    locals.value = m_kPointA;

    if (locals.value >= m_8)
    {
        FUN_00c628c0(m_usTrailingValue + locals.value);
    }

    FUN_00c62b90(locals.value, uiValue);
    return locals.value;
}

// FUN_00c634b0: thiscall (this in ecx), 2 stack params (a1 pointer, unsigned short index).

class XVec12
{
  public:
    float m_00;
    float m_04;
    float m_08;
};

class XSub30
{
  public:
    unsigned int unk00;
    unsigned int Call0045bb20(XVec12* out);
};

class XItem12
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    void Call004578c0(unsigned int r, float f);
};

class XItem28
{
  public:
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    void Call0063c8a0(XSub30* arg);
};

class XObj70
{
  public:
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    XItem12* m_20;
    unsigned int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58,
        unk5c, unk60, unk64, unk68, unk6c;
    XItem28* m_70;
};

class FUN_00c634b0_cls
{
  public:
    unsigned int m_00, m_04, m_08, m_0c, m_10, m_14;
    float m_18;
    unsigned int m_1c;
    unsigned int m_20, m_24, m_28, m_2c;
    XSub30 m_30;
    void FUN_00c634b0(XObj70* a1, unsigned short idx);
};

// @fnv 0x00c634b0
void FUN_00c634b0_cls::FUN_00c634b0(XObj70* pObj, unsigned short usIndex)
{
    XItem28* p = pObj->m_70;
    p = p + usIndex;
    p->Call0063c8a0(&m_30);
    XVec12 qq;
    XItem12* mm = pObj->m_20;
    XVec12 xx;
    mm[usIndex].Call004578c0(m_30.Call0045bb20(&xx), m_18);
}

struct NiPoint3_c
{
    unsigned int x;
    unsigned int y;
    unsigned int z;
};
extern NiPoint3_c NiPoint3_ZERO;

struct FUN_00c63780_c
{
    int pad[9];
    NiPoint3_c v;
    void ResetVector();
};

// Sets the vector member v to NiPoint3_ZERO.
// @fnv 0x00c63780
void FUN_00c63780_c::ResetVector()
{
    v = NiPoint3_ZERO;
}

namespace fnv_00c637b0 {
extern "C" void* __cdecl FUN_00aa13e0(unsigned int size);
struct ParticleVector3
{
    float x, y, z;
};
struct ParticlePositionClone : FUN_00c63330
{
    unsigned int referenceCount;
    const char* name;
    unsigned int order;
    void* targetSystem;
    bool active;
    ParticleVector3 position;
    ParticleVector3 velocity;
    ParticleVector3 previousPosition;
    float lastUpdateTime;

    static __forceinline void* __cdecl operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
};
struct FUN_00c637b0_Class : FUN_00c63840_Class
{
    ParticlePositionClone* CreateParticlePositionClone(CloningProcess* process);
};
// Allocates a ParticlePositionClone, initialises it via CopyModifierWithValue with the given process, and returns it.
// @fnv 0x00c637b0
ParticlePositionClone* FUN_00c637b0_Class::CreateParticlePositionClone(CloningProcess* process)
{
    ParticlePositionClone* clone = new ParticlePositionClone();
    CopyModifierWithValue(reinterpret_cast<NiPSysModifier*>(clone), process);
    return clone;
}
}  // namespace fnv_00c637b0

void* __cdecl FUN_00aa13e0(unsigned int size);
struct PositionModifierObject_b9439
{
    char m00[0x3c];
    PositionModifierObject_b9439();
    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
};
// Allocates and constructs a PositionModifierObject_b9439 via its custom operator new and returns the pointer.
// @fnv 0x00c63880
PositionModifierObject_b9439* CreatePositionModifierObject()
{
    return new PositionModifierObject_b9439();
}

struct Pad32
{
    unsigned int a0, a1, a2, a3, a4, a5, a6, a7;
};

struct ArgObj
{
    void FUN_0096a610(void* p);
};

struct FUN_00c63a00_cls
{
    void FUN_00c319e0(void* a);
    void FUN_00c63a00(ArgObj* a1);
};

unsigned int __cdecl FUN_00a7d330(unsigned int v);
unsigned int __cdecl FUN_00a7d550(const char* name, float f);

// @fnv 0x00c63a00
void FUN_00c63a00_cls::FUN_00c63a00(ArgObj* a1)
{
    unsigned int r1;
    unsigned int r2;
    unsigned int g;
    Pad32 pad;
    FUN_00c319e0(a1);
    g = *(unsigned int*)&g_012043c8;
    r1 = FUN_00a7d330(g);
    a1->FUN_0096a610(&r1);
    r2 = FUN_00a7d550("Damping", *(float*)((char*)this + 0x20));
    a1->FUN_0096a610(&r2);
}

struct S_00c643d0_Foo
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    unsigned short m_uiItemCount;
    void* m_entries[16];

    void __thiscall FUN_00a9a4e0(int arg);
    void __thiscall FUN_00c643d0(int arg);
};

extern "C" void __cdecl FUN_00a303a0(int arg, void* object);
extern "C" void __cdecl FUN_00a417b0(int arg, void* data, int count);

// @fnv 0x00c643d0
void __thiscall S_00c643d0_Foo::FUN_00c643d0(int arg)
{
    this->FUN_00a9a4e0(arg);

    FUN_00a303a0(arg, &this->m_uiItemCount);

    for (int i = 0; i < this->m_uiItemCount; ++i)
    {
        FUN_00a303a0(arg, this->m_entries[i]);

        int count2 = *reinterpret_cast<unsigned short*>(this->m_entries[i]);
        void* count = reinterpret_cast<char*>(this->m_entries[i]) + 4;

        FUN_00a417b0(arg, count, count2 * 3);

        int data = *reinterpret_cast<unsigned short*>(this->m_entries[i]);
        void* pDataB = reinterpret_cast<char*>(this->m_entries[i]) + 0x64;

        FUN_00a417b0(arg, pDataB, data * 3);
    }
}

class FUN_00c64b90_target;

class FUN_00c64b90_item
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned int m_18;
};

class FUN_00c64b90_target
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30(unsigned int value);
};

class FUN_00c64b90_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    FUN_00c64b90_item** m_0c;
    int unk10;
    unsigned short m_14;
    void FUN_00c64b90(FUN_00c64b90_target* a1);
    void FUN_00a89af0(FUN_00c64b90_target* a1);
};

void __cdecl FUN_0044adf0(FUN_00c64b90_target* a1, unsigned int* p);

// @fnv 0x00c64b90
void FUN_00c64b90_cls::FUN_00c64b90(FUN_00c64b90_target* apTarget)
{
    unsigned int count;
    unsigned int i;
    FUN_00c64b90_item* item3;
    unsigned int v2;
    unsigned int bytes;
    FUN_00a89af0(apTarget);
    count = m_14;
    bytes = count * 2;
    FUN_0044adf0(apTarget, &bytes);
    for (i = 0; i < count; i++)
    {
        item3 = m_0c[i];
        if (item3 != 0)
        {
            v2 = item3->m_18;
            apTarget->v30(v2);
            apTarget->v30((unsigned int)item3);
        }
    }
}

struct FUN_00c64da0_cls
{
    int unk00;
    void Callee0043ba10(int a);
    void FUN_00c64da0(int a);
};

// @fnv 0x00c64da0
void FUN_00c64da0_cls::FUN_00c64da0(int a)
{
    int unkLoc0;
    int unkLoc1;
    int unkLoc2;
    this->Callee0043ba10(a);
}

struct DispatchStub_c64
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void** m10;
    int unk14;
    unsigned short m18;
    void DispatchToItems(int a8, int cc);
};
struct ItemCallee_c64
{
    void FUN_00c65490(int a1, int a2);
};

// Calls FUN_00a7b330 with a8 and cc, then for each of m18 entries in m10 calls FUN_00c65490 on the item and item+4.
// @fnv 0x00c64fd0
void DispatchStub_c64::DispatchToItems(int pTarget, int cc)
{
    reinterpret_cast<FUN_00a7b330_shell*>(this)->FUN_00a7b330((void*)pTarget, (void*)cc);
    unsigned int count = m18;
    for (unsigned int i = 0; i < count; i++)
    {
        int item = (int)m10[i];
        reinterpret_cast<ItemCallee_c64*>(pTarget)->FUN_00c65490(item, item + 4);
    }
}

struct FUN_00c65180_VTable
{
    virtual void FUN_00c65180_v0();
    virtual void FUN_00c65180_v1();
    virtual void FUN_00c65180_v2();
    virtual void FUN_00c65180_v3();
    virtual void FUN_00c65180_v4();
    virtual void FUN_00c65180_v5();
    virtual void FUN_00c65180_v6();
    virtual void FUN_00c65180_v7();
    virtual void FUN_00c65180_v8(void* p);
};

struct FUN_00c65180_Class
{
    unsigned char __thiscall FUN_00a7b290(FUN_00c65180_VTable* p);

    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* m_iThirdValue;
    void** m_10;
    int m_14;
    unsigned short m_18;

    unsigned char __thiscall VisitEntries(FUN_00c65180_VTable* p);
};

// Calls FUN_00a7b290; if it succeeds, iterates m_10 up to m_18 times, passing each item and item+4 to the vtable's FUN_00c65180_v8, and returns the result.
// @fnv 0x00c65180
unsigned char __thiscall FUN_00c65180_Class::VisitEntries(FUN_00c65180_VTable* p)
{
    unsigned char result = FUN_00a7b290(p);

    if (result)
    {
        unsigned int count = m_18;

        for (unsigned int i = 0; i < count; ++i)
        {
            void* item = m_10[i];

            p->FUN_00c65180_v8(item);
            p->FUN_00c65180_v8(static_cast<char*>(item) + 4);
        }
    }

    return result;
}

struct MyColorA
{
    float r;
    float g;
    float b;
    float a;
};

struct Point3ParameterData
{
    float unk00;
    float unk04;
    float unk08;
    float m_fXValue;
    float m_fYValue;
    float unk14;
    float unk18;
};

struct NiPSysData
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
    MyColorA* m_pkParticleColors;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    unsigned short m_usNumParticles;
    short pad52;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    Point3ParameterData* m_pkParticleInfo;
};

struct BSPSysSimpleColorModifierCand
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    MyColorA m_kColor1;
    MyColorA m_kColor2;
    MyColorA m_kColor3;
    float m_fFadeInPercent;
    float m_fFadeOutPercent;
    float m_fColor1End;
    float m_fColor2Start;
    float m_fColor2End;
    float m_fColor3Start;

    void UpdateParticleColors(float fTime, NiPSysData* pkData);
};

// For each particle, lerps RGB between m_kColor1/2/3 by normalized age and sets alpha from the fade-in/out percentages.
// @fnv 0x00c602e0
void BSPSysSimpleColorModifierCand::UpdateParticleColors(float fTime, NiPSysData* pkData)
{
    unsigned short usNumParticlesTmp;
    MyColorA* pkColors8;
    float fRangeVal;
    float fRange4;
    unsigned short us4;
    float fNormAge3;
    Point3ParameterData* pkInfo3;
    float kFLerp1;
    float fLerp4;
    float fFadeOutLerpA;
    float fFadeInLerp3;
    Point3ParameterData* pkParticleInfo3;

    pkColors8 = pkData->m_pkParticleColors;
    if (!pkColors8)
        return;

    fRange4 = m_fColor2Start - m_fColor1End;
    fRangeVal = m_fColor3Start - m_fColor2End;

    usNumParticlesTmp = pkData->m_usNumParticles;
    for (us4 = 0; us4 < usNumParticlesTmp; us4++)
    {
        pkParticleInfo3 = pkData->m_pkParticleInfo;
        pkInfo3 = &pkParticleInfo3[us4];
        fNormAge3 = pkInfo3->m_fXValue / pkInfo3->m_fYValue;

        if (fRange4 != 0.0 && fNormAge3 < m_fColor2Start)
        {
            if (fNormAge3 < m_fColor1End)
            {
                pkColors8[us4].r = m_kColor1.r;
                pkColors8[us4].g = m_kColor1.g;
                pkColors8[us4].b = m_kColor1.b;
            }
            else
            {
                kFLerp1 = (fNormAge3 - m_fColor1End) / fRange4;
                pkColors8[us4].r = m_kColor1.r + (m_kColor2.r - m_kColor1.r) * kFLerp1;
                pkColors8[us4].g = m_kColor1.g + (m_kColor2.g - m_kColor1.g) * kFLerp1;
                pkColors8[us4].b = m_kColor1.b + (m_kColor2.b - m_kColor1.b) * kFLerp1;
            }
        }
        else if (fRangeVal != 0.0 && fNormAge3 > m_fColor2End)
        {
            if (fNormAge3 > m_fColor3Start)
            {
                pkColors8[us4].r = m_kColor3.r;
                pkColors8[us4].g = m_kColor3.g;
                pkColors8[us4].b = m_kColor3.b;
            }
            else
            {
                fLerp4 = (fNormAge3 - m_fColor2End) / fRangeVal;
                pkColors8[us4].r = m_kColor2.r + (m_kColor3.r - m_kColor2.r) * fLerp4;
                pkColors8[us4].g = m_kColor2.g + (m_kColor3.g - m_kColor2.g) * fLerp4;
                pkColors8[us4].b = m_kColor2.b + (m_kColor3.b - m_kColor2.b) * fLerp4;
            }
        }
        else
        {
            pkColors8[us4].r = m_kColor2.r;
            pkColors8[us4].g = m_kColor2.g;
            pkColors8[us4].b = m_kColor2.b;
        }

        if (m_fFadeOutPercent != 0.0 && fNormAge3 > m_fFadeOutPercent)
        {
            fFadeOutLerpA = (fNormAge3 - m_fFadeOutPercent) / (1.0f - m_fFadeOutPercent);
            pkColors8[us4].a = m_kColor2.a + (m_kColor3.a - m_kColor2.a) * fFadeOutLerpA;
        }
        else if (m_fFadeInPercent != 0.0 && fNormAge3 < m_fFadeInPercent)
        {
            fFadeInLerp3 = fNormAge3 / (float)(m_fFadeInPercent);
            pkColors8[us4].a = m_kColor1.a + (m_kColor2.a - m_kColor1.a) * fFadeInLerp3;
        }
        else
        {
            pkColors8[us4].a = m_kColor2.a;
        }
    }
}

class NiObjectC60
{
  public:
    NiObjectC60();
    virtual ~NiObjectC60();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
};

class NiCloningProcessC60;

class NiOwnerC60
{
  public:
    void CopyMemberData(NiObjectC60* pkDest, NiCloningProcessC60& kCloning);
    NiObjectC60* CloneObject(NiCloningProcessC60& kCloning);
};

// @fnv 0x00c60670
NiObjectC60* NiOwnerC60::CloneObject(NiCloningProcessC60& kCloning)
{
    NiObjectC60* pkClone = new NiObjectC60;
    CopyMemberData(pkClone, kCloning);
    return pkClone;
}

struct NiTPrimitiveArray_unsigned_int_
{
    unsigned int AddFirstEmpty(const unsigned int& value);
};
struct FUN_00c615a0_class
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int unk0c;
    void FUN_00a99b20(NiTPrimitiveArray_unsigned_int_* values);
    void AppendGlobalAndFormatValues(NiTPrimitiveArray_unsigned_int_* values);
};
extern "C" void* g_012043a4;
extern const char str_0109df4c[];
struct GlobalObject_00a7b610;
char* __cdecl FUN_00a7d330(GlobalObject_00a7b610* value);
char* __cdecl FUN_00a7d510(const char* format, unsigned int value);

struct Unused20
{
    int a, b, c, d, e, f, g, h;
};
// Calls FUN_00a99b20, then appends the result of FUN_00a7d330 on g_012043a4 and of FUN_00a7d510(str_0109df4c, unk0c) to the values array.
// @fnv 0x00c615a0
void FUN_00c615a0_class::AppendGlobalAndFormatValues(NiTPrimitiveArray_unsigned_int_* values)
{
    FUN_00a99b20(values);
    void* global_ptr = g_012043a4;
    unsigned int first = (unsigned int)FUN_00a7d330((GlobalObject_00a7b610*)global_ptr);
    values->AddFirstEmpty(first);
    unsigned int second = (unsigned int)FUN_00a7d510(str_0109df4c, unk0c);
    values->AddFirstEmpty(second);
    Unused20 tmp;
}

struct C639a0Cls : MyIsEqual
{
    char pad[0x20];
    float m_20;
    bool __thiscall FUN_00c639a0(NiObject* pObject);
};
// Compares this object with pObject: first via FUN_00c31830, then checks that m_20 matches.
// @fnv 0x00c639a0
bool C639a0Cls::FUN_00c639a0(NiObject* pObject)
{
    bool bEqual = FUN_00c31830(pObject);
    if (bEqual)
    {
        C639a0Cls* pOther = (C639a0Cls*)pObject;
        bEqual = pOther->m_20 == m_20;
    }
    return bEqual;
}

struct FUN_00c61fc0_Item
{
    int unk00;
    int unk04;
    int unk08;
};

struct FUN_0096a610_Target
{
    void FUN_0096a610(void* a1);
};

struct FUN_00c61fc0_Pad
{
    int a, b, c, d;
};

struct FUN_00c61fc0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    FUN_00c61fc0_Item** m_ppItems;
    unsigned short unk64;
    unsigned short m_iArrayLength;
    void FUN_00c31db0(void* a1);
    char* BuildAttachTypeString(const char* name, int type);
    void Serialize(void* a1);
};

void* __cdecl FUN_00a7d330(int value);
int __cdecl FUN_00a7d5e0(int* dat, int value);
extern int DAT_01063e84;

// After FUN_00c31db0, passes FUN_00a7d330's value, an "ArrayType" string for unk58, and each item's unk08 (last to first) to a1->FUN_0096a610.
// @fnv 0x00c61fc0
void FUN_00c61fc0_cls::Serialize(void* apTarget)
{
    char* ib;
    FUN_00c61fc0_Item** b;
    int mid;
    int r;
    unsigned long ptr2;
    unsigned int ra;
    int oa;
    int v1;
    long cur;
    FUN_00c61fc0_Item* x;
    long qa;
    int ta;
    void* mb;
    int xa;
    long gb;
    FUN_00c31db0(apTarget);
    v1 = *(int*)&g_012043b0;
    mb = FUN_00a7d330(v1);
    ((FUN_0096a610_Target*)apTarget)->FUN_0096a610(&mb);
    xa = unk58;
    ib = BuildAttachTypeString("ArrayType", xa);
    ((FUN_0096a610_Target*)apTarget)->FUN_0096a610(&ib);
    mid = m_iArrayLength;
    while (0 != mid--)
    {
        b = &m_ppItems[mid];
        x = *b;
        if (!!x)
        {
            ra = x->unk08;
            cur = FUN_00a7d5e0(&DAT_01063e84, ra);
            ((FUN_0096a610_Target*)apTarget)->FUN_0096a610(&cur);
        }
    }
}

struct StrArr;

extern "C" void* g_01204388;

class Base00c319e0
{
  public:
    virtual ~Base00c319e0();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();

    void FUN_00c319e0(StrArr* pkStrings);
};

class Mod600 : public Base00c319e0
{
  public:
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    float m_fValue;

    void FUN_00c60050(StrArr* pkStrings);
    virtual ~Mod600();
};

struct LocalStackSpace
{
    int field0;
    int field1;
    int field2;
    int field3;
    int field4;
    int field5;
    int field6;
    int field7;
};

// Calls base FUN_00c319e0, then adds a name string and a string formatted from fUpdateDeltaTime and m_fValue to pkStrings.
// @fnv 0x00c60050
void __thiscall Mod600::FUN_00c60050(StrArr* pkStrings)
{
    Base00c319e0::FUN_00c319e0(pkStrings);

    GlobalObject_00a7b610* obj = (GlobalObject_00a7b610*)g_01204388;
    unsigned int uiName = (unsigned int)FUN_00a7d330(obj);
    ((NiTPrimitiveArray_unsigned_int_*)pkStrings)->AddFirstEmpty(uiName);

    unsigned int uiValue = FUN_00a7d550("fUpdateDeltaTime", m_fValue);
    ((NiTPrimitiveArray_unsigned_int_*)pkStrings)->AddFirstEmpty(uiValue);

    {
        LocalStackSpace localSpace;
        if (localSpace.field0)
        {
        }
    }
}

Base00c319e0::~Base00c319e0()
{}
void Base00c319e0::vf04()
{}
void Base00c319e0::vf08()
{}
void Base00c319e0::vf0C()
{}
void Base00c319e0::vf10()
{}
void Base00c319e0::vf14()
{}
void Base00c319e0::vf18()
{}

Mod600::~Mod600()
{}

struct SpawnHeap_cls
{
    void __thiscall FUN_00aa4060(void* pObject);
};

extern "C" void* DAT_0109b220;
extern "C" char DAT_011f6238;
extern "C" void(__stdcall* DAT_00fdf1c4)(void*);
extern NiFixedString* DAT_012043a0;

// If DAT_012043a0 is set, calls DAT_00fdf1c4 on its header unless it holds DAT_0109b220, frees it via FUN_00aa4060, then sets DAT_012043a0 to 0.
// @fnv 0x00c61760
void FUN_00c61760()
{
    NiFixedString* tmp = DAT_012043a0;
    NiFixedString* p = tmp;
    NiFixedString* result;
    unsigned int hdr;

    if (p != 0)
    {
        if (*(void**)p == DAT_0109b220)
        {
        }
        else
        {
            hdr = *(unsigned int*)p - 8;
            DAT_00fdf1c4((void*)hdr);
        }

        if ((1, 1) & 1)
        {
            reinterpret_cast<SpawnHeap_cls*>(&DAT_011f6238)->FUN_00aa4060(p);
        }

        result = p;
    }
    else
    {
        result = 0;
    }

    DAT_012043a0 = 0;
}

namespace fnv_00c61990 {
extern "C" void* DAT_012043ac;
extern "C" int DAT_0109b220;

struct S61990Obj
{
    int vt;
};

// Takes the global at DAT_012043ac, decrements the count at vt-8 unless vt equals DAT_0109b220, deallocates the object, and clears the global.
// @fnv 0x00c61990
void __cdecl FUN_00c61990()
{
    S61990Obj* ptr = (S61990Obj*)DAT_012043ac;
    S61990Obj* mgr = ptr;
    S61990Obj* beta;
    volatile long* temp;
    if (mgr != 0)
    {
        if (mgr->vt == DAT_0109b220)
        {
        }
        else
        {
            temp = (volatile long*)(mgr->vt - 8);
            InterlockedDecrement(temp);
        }
        if ((1, 1) & 1)
        {
            g_memoryManager.Deallocate(mgr);
        }
        beta = mgr;
    }
    else
    {
        beta = 0;
    }
    DAT_012043ac = 0;
}
}  // namespace fnv_00c61990

struct Pt3c64640
{
    float x;
    float y;
    float z;
    Pt3c64640()
    {}
};

extern Pt3c64640 DAT_011f426c;

struct Box0c64640
{
    unsigned short unk00;
    Pt3c64640 unk04[8];
    Pt3c64640 unk64[8];
    Box0c64640* FUN_00c64640();
};

// Sets unk00 to 0 and fills the unk04 and unk64 arrays with the global DAT_011f426c value, then returns this.
// @fnv 0x00c64640
Box0c64640* Box0c64640::FUN_00c64640()
{
    int i;
    {
        int n = 8;
        Pt3c64640* p = unk04;
        while (--n >= 0)
            p++;
    }
    {
        int m = 8;
        Pt3c64640* q = unk64;
        while (--m >= 0)
            q++;
    }
    unk00 = 0;
    for (i = 0; i < 8; i++)
    {
        unk04[i] = DAT_011f426c;
        unk64[i] = DAT_011f426c;
    }
    return this;
}

struct S_00c648a0_Map
{
    bool GetAt(unsigned int, void**);
};

struct S_00c648a0_Stream
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28(void* apObject);
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    S_00c648a0_Map* unk5c4;
    void FUN_00a64ce0(void** appString);
};

struct S_00c648a0_Base
{
    int unk00;
    int unk04;
    void* unk08;
    void ReadGroup(S_00c648a0_Stream* apStream);
};

struct S_00c648a0 : S_00c648a0_Base
{
    void FUN_00c648a0(S_00c648a0_Stream* apStream);
};

// Calls ReadGroup, reads unk08 from the stream, looks it up in the stream's map, and passes any found object to apStream->v28.
// @fnv 0x00c648a0
void S_00c648a0::FUN_00c648a0(S_00c648a0_Stream* apStream)
{
    ReadGroup(apStream);
    apStream->FUN_00a64ce0(&unk08);

    void* pObject;
    {
        S_00c648a0_Stream* pStream = apStream;
        unsigned int uiLinkID = (unsigned int)unk08;
        void* pFound = 0;
        if (pStream->unk5c4 && uiLinkID)
            pStream->unk5c4->GetAt(uiLinkID, &pFound);
        pObject = pFound;
    }
    if (pObject)
        apStream->v28(pObject);
    {
        int ReportDiagnostic;
        int unused1;
    }
}

class BSFaceGenMorphData
{
  public:
    static void* operator new(unsigned int size);
    static void operator delete(void* memory);
};

struct FUN_00c64de0 : NiAVObject, BSFaceGenMorphData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    FUN_00c64de0();
};

// Allocates a FUN_00c64de0 object, sets its name to DAT_011f49e0, and returns the new pointer.
// @fnv 0x00c652c0
FUN_00c64de0* __cdecl FUN_00c652c0()
{
    FUN_00c64de0* object = new FUN_00c64de0;
    object->SetName(DAT_011f49e0);
    return object;
}

int _sprintf_s(char*, unsigned int, const char*, ...);

class NiViewerStringsArray
{
  public:
    unsigned int Add(char* const& item);
};

char* __cdecl CreateDebugString(const char* pcText);

class AttachPointName
{
  public:
    const char* m_kHandle;
    operator const char*() const
    {
        return m_kHandle;
    }
};

class AttachPoint
{
  public:
    AttachPointName m_kParent;
    AttachPointName m_kNode;
};

class NiExtraDataBase
{
  public:
    void GetViewerStrings(NiViewerStringsArray* pkStrings);
};

class BSAttachPoints : public NiExtraDataBase
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AttachPoint** m_ppkPoints;
    int unk14;
    unsigned short m_usElementCount;
    void FUN_00c65350(NiViewerStringsArray* pkStrings);
};

struct FillPad3
{
    int unk00;
    int unk04;
    int unk08;
};

struct FillPad4
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

struct FillPad5
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};

// Appends the RTTI name and one formatted string per attach point (index, parent, node) to pkStrings.
// @fnv 0x00c65350
void BSAttachPoints::FUN_00c65350(NiViewerStringsArray* pkStrings)
{
    char acBuffer[260];
    unsigned int i;
    unsigned int kUiCount;
    AttachPoint* pkPoint;
    const char* pcParent;
    const char* pcNode2;
    NiExtraDataBase::GetViewerStrings(pkStrings);
    {
        unsigned int unk0;
        const char* pcRTTIName = (const char*)DAT_012043f0;
        char* unk2;
        char* pcViewerStr = CreateDebugString(pcRTTIName);
        pkStrings->Add(pcViewerStr);
        kUiCount = m_usElementCount;
        for (i = 0; i < kUiCount; i++)
        {
            {
                FillPad4 nc;
            }
            pkPoint = m_ppkPoints[i];
            const char* nb6 = pkPoint->m_kParent.m_kHandle;
            pcParent = nb6;
            const char* hNode = pkPoint->m_kNode.m_kHandle;
            pcNode2 = hNode;
            _sprintf_s(acBuffer, 260, "%d: %s - %s", i, pcParent, pcNode2);
            unk2 = acBuffer;
            pkStrings->Add(unk2);
        }
    }
}

extern "C" void* VTABLE_010a0d24;
extern "C" void* VTABLE_010c38ac;
struct Vector3i
{
    int x;
    int y;
    int z;
};
struct FUN_00c63ab0
{
    void* vtable;
    int field04;
    int field08;
    int parameter0c;
    unsigned short count10;
    unsigned short status12;
    unsigned int entries[8];
    Vector3i bounds;
    void __thiscall FUN_00a7b2e0();
    FUN_00c63ab0(int parameter);
};
// @fnv 0x00c63ab0
FUN_00c63ab0::FUN_00c63ab0(int parameter)
{
    FUN_00a7b2e0();
    vtable = &VTABLE_010a0d24;
    parameter0c = parameter;
    vtable = &VTABLE_010c38ac;
    int index;
    Vector3i* coordinate = &bounds;
    coordinate->z = 0;
    coordinate->x = 0;
    coordinate->y = 0;
    count10 = 0;
    for (index = 0; index < 8; ++index)
    {
        entries[index] = 0;
    }
}
