
// src/staging/blk_00680000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

struct FUN_00692290_class
{
    virtual void v0();
    virtual int Write(unsigned int);
    void FUN_005ef650(int, unsigned int);
    void FUN_00692290(unsigned int requested, unsigned int savedSize);
    int iSize;
    int iPosition;
    int iDataLength;
};

// @fnv 0x00692290
void FUN_00692290_class::FUN_00692290(unsigned int requested, unsigned int savedSize)
{
    iSize = 0;
    iPosition = 0;
    iDataLength = 0;
    if (savedSize > requested)
    {
        requested = savedSize;
    }
    if (requested > 0)
    {
        iSize = Write(requested);
        iDataLength = requested;
    }
    if (savedSize > 0)
    {
        FUN_005ef650(iSize, savedSize);
        iPosition = savedSize;
    }
}

struct PackageTargetRecord
{
    int GetTargetKind();
    void FUN_00680170(void* reference);
};
// @fnv 0x00680170
void PackageTargetRecord::FUN_00680170(void* reference)
{
    if (GetTargetKind() == 2)
        *(int*)((char*)this + 4) = (int)reference;
}

struct TESConditionItem
{
    bool GetParamCount();
};

struct FUN_00681500_class
{
    void SetValueIfNoParams(float value);
};

// Stores value at offset 4 of this object when GetParamCount returns false.
// @fnv 0x00681500
void FUN_00681500_class::SetValueIfNoParams(float value)
{
    if (!((TESConditionItem*)this)->GetParamCount())
        *(float*)((char*)this + 4) = value;
}

struct FUN_00682530_class
{
    void InitWithValue(int);
};

struct FUN_00682510_class
{
    int FUN_00682510(int);
};

// @fnv 0x00682510
int FUN_00682510_class::FUN_00682510(int arg)
{
    ((FUN_00682530_class*)this)->InitWithValue(arg);
    return (int)this;
}

struct FUN_00682570_class
{
    void FUN_00682590(int);
    int __thiscall FUN_00682570(int a);
};

// @fnv 0x00682570
int __thiscall FUN_00682570_class::FUN_00682570(int a)
{
    FUN_00682590(a);
    return (int)this;
}

struct FUN_006825e0_class
{
    void FUN_00682600();
    void FUN_006825e0();
};

// @fnv 0x006825e0
void FUN_006825e0_class::FUN_006825e0()
{
    FUN_00682600();
}

struct FUN_00682680_class
{
    void FreeBuffer();
    void FUN_00682680();
};

// @fnv 0x00682680
void FUN_00682680_class::FUN_00682680()
{
    FreeBuffer();
}

extern int DAT_01069948;

struct FUN_006836f0_class
{
    virtual void v0();
    void FUN_00683760();
    FUN_006836f0_class* FUN_006836f0();
};

// @fnv 0x006836f0
FUN_006836f0_class* __thiscall FUN_006836f0_class::FUN_006836f0()
{
    FUN_00683760();
    *reinterpret_cast<int**>(this) = &DAT_01069948;
    return this;
}

struct FUN_00683740_class
{
    void FUN_006837f0();
    void FUN_00683740();
};

// @fnv 0x00683740
void FUN_00683740_class::FUN_00683740()
{
    FUN_006837f0();
}

extern int DAT_01069958;
struct FUN_00683760_class
{
    void Init();
    FUN_00683760_class();
};
// @fnv 0x00683760
FUN_00683760_class::FUN_00683760_class()
{
    Init();
    *reinterpret_cast<int**>(this) = &DAT_01069958;
}

struct FUN_0068a810_class
{
    int GetField4C();
};
// @fnv 0x0068a810
int FUN_0068a810_class::GetField4C()
{
    return *(int*)((char*)this + 0x4c);
}

extern int DAT_01069d7c;
struct ActorCombatGroup
{
    virtual ~ActorCombatGroup();
};
void NiTMallocInterface_Deallocate(ActorCombatGroup**);
struct FUN_0068ab80_class
{
    ActorCombatGroup** p;
    ActorCombatGroup** q;
    void FUN_0068ab80();
};
// Points p at DAT_01069d7c and frees the allocation held by q via NiTMallocInterface_Deallocate.
// @fnv 0x0068ab80
void FUN_0068ab80_class::FUN_0068ab80()
{
    p = (ActorCombatGroup**)&DAT_01069d7c;
    NiTMallocInterface_Deallocate(q);
}

extern "C" void __cdecl FUN_004a4650(void*);

struct FUN_0068e740_class
{
    void FUN_0068e740();
};

// @fnv 0x0068e740
void FUN_0068e740_class::FUN_0068e740()
{
    ((void(__thiscall*)(void*))FUN_004a4650)((char*)this + 0x24);
}

extern int DAT_0106a038;

struct GlobalObject_00869f00
{
    int pData;
    void Clear(bool);
};

struct FUN_0068eb30_class : GlobalObject_00869f00
{
    void InitializeGlobalObject();
};

// @fnv 0x0068eb30
void FUN_0068eb30_class::InitializeGlobalObject()
{
    pData = (int)&DAT_0106a038;
    Clear(true);
}

struct FUN_00691870_class
{
    void* AllocateDoubleSizedBuffer(int count);
};

// Allocates a char array of count * 2 bytes and returns a pointer to it.
// @fnv 0x00691870
void* FUN_00691870_class::AllocateDoubleSizedBuffer(int count)
{
    return new char[count * 2];
}

void* __cdecl Reallocate(void* p, unsigned int size);

struct FUN_006918a0_class
{
    void __thiscall FUN_006918a0(void* p, int n);
};

// @fnv 0x006918a0
void __thiscall FUN_006918a0_class::FUN_006918a0(void* p, int aiSize)
{
    Reallocate(p, aiSize << 1);
}

struct GO
{
    void operator=(void*);
};
struct FUN_00691a30_class
{
    GO m0;
    void FUN_00659080(int);
    void FUN_00691a30(int a);
};
// Clears the pointer at offset 8 of the passed object and forwards it to FUN_00659080 on this+0xc.
// @fnv 0x00691a30
void FUN_00691a30_class::FUN_00691a30(int pObject)
{
    ((GO*)((char*)pObject + 8))->operator=(0);
    ((FUN_00691a30_class*)((char*)this + 0xc))->FUN_00659080(pObject);
}

namespace fnv_00691bf0 {
extern void* DAT_0106ac40;

struct GlobalObject_00869f00
{
    void* p;
    void Clear(bool);
    void FUN_00691bf0();
};

void GlobalObject_00869f00::Clear(bool)
{}

// @fnv 0x00691bf0
void GlobalObject_00869f00::FUN_00691bf0()
{
    p = &DAT_0106ac40;
    Clear(true);
}
}  // namespace fnv_00691bf0

void* __cdecl Reallocate(void* base, unsigned int size);

struct FUN_00691d20_class
{
    void* __thiscall FUN_00691d20(void* a, int b);
};

// @fnv 0x00691d20
void* __thiscall FUN_00691d20_class::FUN_00691d20(void* apBase, int aiCount)
{
    return Reallocate(apBase, aiCount * 0xc);
}

namespace fnv_00691fe0 {
extern int DAT_0106acb0;

struct GlobalObject_00869f00
{
    void Clear(bool);
};

struct FUN_00691fe0_class
{
    void* p;
    void FUN_00691fe0();
};

// @fnv 0x00691fe0
void FUN_00691fe0_class::FUN_00691fe0()
{
    p = &DAT_0106acb0;
    ((GlobalObject_00869f00*)this)->Clear(true);
}
}  // namespace fnv_00691fe0

struct PositionRotation
{
    void* __fastcall FUN_00692710();
    unsigned short wFlags;
};
struct FUN_006926e0_class
{
    PositionRotation* __thiscall FUN_006926e0();
};
// Calls FUN_00692710 on this object, sets the unsigned short at offset 0x24 to 0xffff, and returns this.
// @fnv 0x006926e0
PositionRotation* __thiscall FUN_006926e0_class::FUN_006926e0()
{
    ((PositionRotation*)this)->FUN_00692710();
    *(unsigned short*)((char*)this + 0x24) = 0xffff;
    return (PositionRotation*)this;
}

struct FUN_00693bb0_class
{
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    void FUN_00693bb0();
};
// @fnv 0x00693bb0
void FUN_00693bb0_class::FUN_00693bb0()
{
    d ^= 0x10;
}

struct FUN_00693cf0_class
{
    int GetSix();
};

// Computes 4 + 2 and returns the result.
// @fnv 0x00693cf0
int FUN_00693cf0_class::GetSix()
{
    int i = 4;
    i = i + 2;
    return i;
}

struct FUN_00693d10_class
{
    int a;
    void GetSix();
    void FUN_00693d10();
};

// @fnv 0x00693d10
void FUN_00693d10_class::FUN_00693d10()
{
    ((FUN_00693d10_class*)((char*)this + 4))->GetSix();
}

struct ArrSI
{
    unsigned int GetFlags();
};
struct FUN_00695370_class
{
    int pad[0x48 / 4];
    ArrSI arr;
    unsigned int GetArrFlags();
};
// @fnv 0x00695370
unsigned int FUN_00695370_class::GetArrFlags()
{
    return arr.GetFlags();
}

extern "C" void* __cdecl memset(void* dst, int value, unsigned int count);

// @fnv 0x00695390
void* __cdecl MemsetWrapper(void* dst, int value, unsigned int count)
{
    return memset(dst, value, count);
}

extern int DAT_0106b184;

struct FUN_0069ad40_class
{
    void ConstructBuffer(int);
    int* InitializeWithGlobal(int);
};

// Calls ConstructBuffer with param, stores the address of DAT_0106b184 at the start of this, and returns this as an int pointer.
// @fnv 0x0069ad40
int* FUN_0069ad40_class::InitializeWithGlobal(int param)
{
    ConstructBuffer(param);
    *reinterpret_cast<int**>(this) = &DAT_0106b184;
    return reinterpret_cast<int*>(this);
}

void __cdecl FUN_00ec6f20(int, int, int, int);

struct FUN_0069aeb0_class
{
    void __thiscall FUN_0069aeb0(int a);
    int f0;
    int f4;
    int f8;
};

// Calls FUN_00ec6f20 with f4, f8, 2 and a.
// @fnv 0x0069aeb0
void __thiscall FUN_0069aeb0_class::FUN_0069aeb0(int a)
{
    FUN_00ec6f20(f4, f8, 2, a);
}

// @fnv 0x0069b1b0
bool AreWideCharsEqual(const unsigned short* a, const unsigned short* b)
{
    return *a == *b;
}

namespace fnv_0069b1d0 {
extern int DAT_0106b1cc;
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct FUN_0069b1d0_class
{
    int m_pData;
    void FUN_0069b1d0();
};
// @fnv 0x0069b1d0
void FUN_0069b1d0_class::FUN_0069b1d0()
{
    m_pData = (int)&DAT_0106b1cc;
    ((GlobalObject_00869f00*)this)->Clear(true);
}
}  // namespace fnv_0069b1d0

struct FUN_0069b1f0_class
{
    void* __thiscall AllocateBytes(unsigned int size);
};

// Allocates a new array of unsigned char of the given size and returns a pointer to it.
// @fnv 0x0069b1f0
void* __thiscall FUN_0069b1f0_class::AllocateBytes(unsigned int size)
{
    return new unsigned char[size];
}

namespace fnv_0069b220 {
extern "C" void* __cdecl Reallocate(void*, unsigned int);

struct FUN_0069b220_class
{
    void* __thiscall FUN_0069b220(void* arg, unsigned int size);
};

// @fnv 0x0069b220
void* __thiscall FUN_0069b220_class::FUN_0069b220(void* arg, unsigned int size)
{
    return Reallocate(arg, size);
}
}  // namespace fnv_0069b220

// @fnv 0x0069b2a0
int __cdecl FUN_0069b2a0(const unsigned short* ausLeft, const unsigned short* ausRight)
{
    return *ausLeft == *reinterpret_cast<const int*>(ausRight);
}

extern int DAT_0106b1e0;

struct Dummy_0069af30
{
    void ResetAndWrite(int, int);
    int* FUN_0069b2c0();
};

// @fnv 0x0069b2c0
int* Dummy_0069af30::FUN_0069b2c0()
{
    *(int*)this = (int)&DAT_0106b1e0;
    ResetAndWrite(0, 0);
    return (int*)this;
}

namespace fnv_0069b2f0 {
extern int DAT_0106b1e0;
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct FUN_0069b2f0_class
{
    void* p;
    void FUN_0069b2f0();
};
// @fnv 0x0069b2f0
void FUN_0069b2f0_class::FUN_0069b2f0()
{
    p = &DAT_0106b1e0;
    ((GlobalObject_00869f00*)this)->Clear(true);
}
}  // namespace fnv_0069b2f0

struct FUN_0069b8a0_class
{
    void CreateObj();
};

struct FUN_0069b760_class
{
    void FUN_0069b760();
};

// @fnv 0x0069b760
void FUN_0069b760_class::FUN_0069b760()
{
    ((FUN_0069b8a0_class*)((char*)this + 0xc))->CreateObj();
}

struct Unk6b
{
    void FreeMemory(void*);
};
struct FUN_0069b780_class
{
    int a;
    int b;
    int c;
    void FUN_0069b780(void* p);
};
// Clears the int at offset 0xc of p, then calls FreeMemory on this+0xc with p.
// @fnv 0x0069b780
void FUN_0069b780_class::FUN_0069b780(void* p)
{
    *(int*)((char*)p + 0xc) = 0;
    ((Unk6b*)((char*)this + 0xc))->FreeMemory(p);
}

struct FUN_006d5320_mem
{
    void __thiscall FUN_006d5320();
};
struct FUN_0069b920_class
{
    int __thiscall FUN_006d5320();
    int __thiscall FUN_0069b920();
};
// @fnv 0x0069b920
int __thiscall FUN_0069b920_class::FUN_0069b920()
{
    ((FUN_006d5320_mem*)this)->FUN_006d5320();
    return (int)this;
}

struct FUN_0069ccf0_class
{
    int m_00;
    int m_04;
    int FUN_0069ccf0(int a);
};
// @fnv 0x0069ccf0
int FUN_0069ccf0_class::FUN_0069ccf0(int aiValue)
{
    return aiValue * 6 + m_04;
}

namespace fnv_0069cd40 {
extern int DAT_0106b28c;
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct FUN_0069cd40_class
{
    void* p;
    void InitAndClear();
};
// @fnv 0x0069cd40
void FUN_0069cd40_class::InitAndClear()
{
    p = &DAT_0106b28c;
    ((GlobalObject_00869f00*)this)->Clear(true);
}
}  // namespace fnv_0069cd40

struct NiPoint3
{
    void Set(float, float, float);
};

struct FUN_0069d790_class
{
    int m_unused0;
    float m_f4;
    float m_f8;
    float m_fc;
    float m_f10;
    float m_f14;
    NiPoint3* FUN_0069d790(NiPoint3* result, unsigned int a, unsigned int b);
};

// @fnv 0x0069d790
NiPoint3* FUN_0069d790_class::FUN_0069d790(NiPoint3* result, unsigned int a, unsigned int b)
{
    result->Set((float)a * m_f4 + m_fc, (float)b * m_f8 + m_f10, m_f14);
    return result;
}

struct DA00694f80
{
    unsigned short& GetAt(int index);
};

struct FUN_0069dec0_class
{
    unsigned short& FUN_0069dec0(int index);
};

// @fnv 0x0069dec0
unsigned short& FUN_0069dec0_class::FUN_0069dec0(int index)
{
    return ((DA00694f80*)this)->GetAt(index);
}

bool __cdecl AreWideCharsEqual(const unsigned short& a, const unsigned short& b);
struct NavMeshTriList
{
    int FindMatchingIndex(const unsigned short&, unsigned int,
                          bool(__cdecl*)(const unsigned short&, const unsigned short&));
};
struct FUN_0069dee0_class
{
    bool Contains(const unsigned short& a);
};
// Searches the NavMeshTriList for the given unsigned short using AreWideCharsEqual and returns whether the index is not -1.
// @fnv 0x0069dee0
bool FUN_0069dee0_class::Contains(const unsigned short& ausValue)
{
    return reinterpret_cast<NavMeshTriList*>(this)->FindMatchingIndex(ausValue, 0, AreWideCharsEqual) != -1;
}

struct FUN_0069dfb0_class
{
    bool HasNonZeroAtOffset54() const;
};

// @fnv 0x0069dfb0
bool FUN_0069dfb0_class::HasNonZeroAtOffset54() const
{
    return *(const int*)((const char*)this + 0x54) != 0;
}

struct FUN_00691a00_class : public NiTPointerMap<int, int>
{
    void FUN_00691a00();
};
void NiFreeAlias(void*);
// @fnv 0x00691a00
void FUN_00691a00_class::FUN_00691a00()
{
    *reinterpret_cast<const char**>(this) = "P i";
    RemoveAll();
    NiFreeAlias(reinterpret_cast<char*>(*reinterpret_cast<void***>(reinterpret_cast<char*>(this) + 8)));
}

namespace fnv_0069b730 {
extern "C" void __cdecl NiFreeAlias(void*);
extern int DAT_0106b1f4;

struct FUN_0069b730_class
{
    void* pvt;
    void* unused;
    void* pMem;
    void FUN_0069b730();
};

// Resets the vtable pointer, clears the pointer map, and frees the allocated memory block.
// @fnv 0x0069b730
void FUN_0069b730_class::FUN_0069b730()
{
    pvt = &DAT_0106b1f4;
    ((NiTPointerMap<int, int>*)this)->RemoveAll();
    NiFreeAlias(pMem);
}
}  // namespace fnv_0069b730

struct RefObj
{
    void* __thiscall _ref_006815c0();
};
void* __cdecl __memcpy(void* dst, const void* src, unsigned int n);
struct S00681590
{
    void __thiscall CopyFromRefObj(RefObj* p, int d);
};
// Copies 0x1c bytes from the object returned by p->_ref_006815c0() into this.
// @fnv 0x00681590
void __thiscall S00681590::CopyFromRefObj(RefObj* apRefObj, int d)
{
    __memcpy(this, apRefObj->_ref_006815c0(), 0x1c);
}

struct S682530
{
    int __thiscall InitWithValue(int);
};
// Calls FUN_00682570(0), zeroes the field at offset 0xc, and stores a into the fields at offsets 0x10 and 0x14.
// @fnv 0x00682530
int __thiscall S682530::InitWithValue(int aiValue)
{
    ((FUN_00682570_class*)this)->FUN_00682570(0);
    *(int*)((char*)this + 0xc) = 0;
    *(int*)((char*)this + 0x10) = aiValue;
    *(int*)((char*)this + 0x14) = aiValue;
    return (int)this;
}

extern "C" void __cdecl Deallocate(void*);
struct FUN_006826a0_class
{
    void __thiscall FUN_006826f0();
    void* __thiscall FUN_006826a0(unsigned int flags);
};
// Calls FUN_006826f0, then frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x006826a0
void* __thiscall FUN_006826a0_class::FUN_006826a0(unsigned int flags)
{
    FUN_006826f0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct MemoryBlockHeader
{
    void* m_pPreviousBlock;
    void* pNext;
};
struct AbstractHeap
{
    int pad0;
    MemoryBlockHeader* m_pLastBlock;
    MemoryBlockHeader* m_pFirstBlock;
    int m_iFreeBlockCount;
    void AppendBlock(MemoryBlockHeader* block);
};
// Links block at the tail of the list, updating head/tail pointers and incrementing the count.
// @fnv 0x00683610
void AbstractHeap::AppendBlock(MemoryBlockHeader* block)
{
    block->pNext = 0;
    block->m_pPreviousBlock = m_pLastBlock;
    if (m_pLastBlock)
        m_pLastBlock->pNext = block;
    else
        m_pFirstBlock = block;
    m_pLastBlock = block;
    ++m_iFreeBlockCount;
}

struct Fake683760
{
    const char* m0;
    int m1;
    int m2;
    int m3;
    Fake683760* Init();
};
// Sets m0 to "p8h" and clears m1, m2 and m3, then returns this.
// @fnv 0x006837b0
Fake683760* Fake683760::Init()
{
    m0 = "p8h";
    m3 = 0;
    m1 = 0;
    m2 = 0;
    return this;
}

struct FUN_0062e290_shell
{
    void ClearList();
    void FUN_00683850();
    virtual ~FUN_0062e290_shell();
};
struct FUN_006837f0_t : public FUN_0062e290_shell
{
    ~FUN_006837f0_t();
};
// @fnv 0x006837f0
FUN_006837f0_t::~FUN_006837f0_t()
{
    ClearList();
}

void __cdecl _Deallocate(void*);
struct FUN_00683870_class
{
    void FUN_00683850();
    void* __thiscall FUN_00683870(unsigned int);
};
// @fnv 0x00683870
void* __thiscall FUN_00683870_class::FUN_00683870(unsigned int flags)
{
    FUN_00683850();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct SoundPlaybackHandle
{
    bool SetPosition(float, float, float);
    bool SetPositionFromArray(float* pos);
};
// Sets the position from the first three elements of the given float array and returns the result.
// @fnv 0x0068a7d0
bool SoundPlaybackHandle::SetPositionFromArray(float* afPosition)
{
    return SetPosition(afPosition[0], afPosition[1], afPosition[2]);
}

struct BaseForAbb0
{
    void __thiscall FUN_0068ac40(int a, int b);
};
extern int DAT_01069d84;
struct FUN_0068abb0 : BaseForAbb0
{
    FUN_0068abb0(int a, int b);
};
// Calls the base constructor with a and b, then stores the address of DAT_01069d84 into this object's vtable slot.
// @fnv 0x0068abb0
FUN_0068abb0::FUN_0068abb0(int a, int b)
{
    FUN_0068ac40(a, b);
    *(int*)this = (int)&DAT_01069d84;
}

struct FUN_0068ab60_shell
{
    void FUN_0068ab80();
    void* __thiscall FUN_0068abe0(unsigned int flags);
};
// Calls FUN_0068ab80, then deletes this if flags has bit 0 set, and returns this.
// @fnv 0x0068abe0
void* __thiscall FUN_0068ab60_shell::FUN_0068abe0(unsigned int flags)
{
    FUN_0068ab80();
    if (flags & 1)
        operator delete(this);
    return this;
}

namespace fnv_0068ac10 {
struct FUN_0068ab60_shell
{
    void FUN_0068ab60();
    void* FUN_0068ac10(unsigned int flags);
};
// @fnv 0x0068ac10
void* FUN_0068ab60_shell::FUN_0068ac10(unsigned int flags)
{
    FUN_0068ab60();
    if (flags & 1)
        operator delete(this);
    return this;
}
}  // namespace fnv_0068ac10

struct AX
{
    int* vtable;
    void FUN_006b3eb0(unsigned int, unsigned int);
    AX* FUN_0068eb00();
};
// @fnv 0x0068eb00
AX* AX::FUN_0068eb00()
{
    vtable = &DAT_0106a038;
    FUN_006b3eb0(0, 0);
    return this;
}

void __cdecl _Deallocate(void*);
struct Holder_0068eb50 : FUN_0068eb30_class
{
    void* FUN_0068eb50(unsigned int);
};
// @fnv 0x0068eb50
void* Holder_0068eb50::FUN_0068eb50(unsigned int flags)
{
    InitializeGlobalObject();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

extern "C" void __cdecl Deallocate(void*);
void __cdecl FUN_006919a0();
struct FUN_00691770_class
{
    void __thiscall FUN_006919a0();
    void* __thiscall FUN_00691770(unsigned int flags);
};
// Calls FUN_006919a0, then frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00691770
void* __thiscall FUN_00691770_class::FUN_00691770(unsigned int flags)
{
    FUN_006919a0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void __cdecl Deallocate(void*);
struct FUN_00691ea0_class
{
    void FUN_00691ea0();
    void* FUN_006917a0(unsigned int flags);
};
// @fnv 0x006917a0
void* FUN_00691ea0_class::FUN_006917a0(unsigned int flags)
{
    FUN_00691ea0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern "C" void* __cdecl _NiMalloc(unsigned int size);
extern "C" void* __cdecl memset(void* dst, int value, unsigned int count);
extern int SG6701;
struct FUN_006918c0_class
{
    int* pvTable;
    unsigned int m_usPassCountLocal;
    void* pBase;
    unsigned int usSize;
    FUN_006918c0_class(unsigned int count);
};
// @fnv 0x006918c0
FUN_006918c0_class::FUN_006918c0_class(unsigned int count)
{
    pvTable = &SG6701;
    m_usPassCountLocal = count;
    usSize = 0;
    unsigned int uiBytes = m_usPassCountLocal * 4;
    pBase = _NiMalloc(uiBytes);
    memset(pBase, 0, m_usPassCountLocal * 4);
}

struct TwoIntRecord
{
    TwoIntRecord& operator=(TwoIntRecord const&);
};
struct S00691c60
{
    int m0;
    TwoIntRecord m4;
    S00691c60& __thiscall Assign(S00691c60 const&);
};
// Copies m0 and m4 from source into this object and returns a reference to this object.
// @fnv 0x00691c60
S00691c60& __thiscall S00691c60::Assign(S00691c60 const& source)
{
    m0 = source.m0;
    m4 = source.m4;
    return *this;
}

void _Deallocate(void* p);
struct S00692050 : FUN_00691a00_class
{
    void* __thiscall FUN_00692050(unsigned int flags);
};
// @fnv 0x00692050
void* __thiscall S00692050::FUN_00692050(unsigned int flags)
{
    FUN_00691a00();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_00692080 {
extern "C" void __cdecl _Deallocate(void*);

struct FUN_00691a90_class
{
    void __thiscall FUN_00691a90();
};

void __thiscall FUN_00691a90_class::FUN_00691a90()
{}

struct FUN_00692080_class
{
    void* __thiscall FUN_00692080(unsigned int flags);
};

// Calls FUN_00691a90 on this, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00692080
void* __thiscall FUN_00692080_class::FUN_00692080(unsigned int flags)
{
    ((FUN_00691a90_class*)this)->FUN_00691a90();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_00692080

void __cdecl operator delete(void*);
struct FUN_00691b40_class
{
    void __thiscall FUN_00691b40();
    void* __thiscall FUN_006920b0(unsigned int flags);
};
// Calls FUN_00691b40, frees this when flags has bit 0 set, and returns this.
// @fnv 0x006920b0
void* FUN_00691b40_class::FUN_006920b0(unsigned int flags)
{
    FUN_00691b40();
    if (flags & 1)
        operator delete(this);
    return this;
}

void __cdecl operator delete(void*);
void FUN_00691bf0();
struct FUN_006920e0_class
{
    void FUN_00691bf0();
    void* __thiscall FUN_006920e0(unsigned int flags);
};
// Calls FUN_00691bf0, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x006920e0
void* __thiscall FUN_006920e0_class::FUN_006920e0(unsigned int flags)
{
    FUN_00691bf0();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_00691d70_class
{
    void FUN_00691d70();
    void* FUN_00692110(unsigned int flags);
};

// Calls FUN_00691d70, deletes this when flags has bit 0 set, and returns this.
// @fnv 0x00692110
void* FUN_00691d70_class::FUN_00692110(unsigned int flags)
{
    FUN_00691d70();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_00691dc0_class
{
    void FUN_00691dc0();
    void* FUN_00692140(unsigned int flags);
};
// @fnv 0x00692140
void* FUN_00691dc0_class::FUN_00692140(unsigned int flags)
{
    FUN_00691dc0();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_00691f00_shell
{
    void FUN_00691f00();
    void* FUN_00692170(unsigned int flags);
};

// @fnv 0x00692170
void* FUN_00691f00_shell::FUN_00692170(unsigned int flags)
{
    FUN_00691f00();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct Arr3520
{
    void FUN_00691f90();
    void* FUN_006921a0(unsigned int flags);
};
// @fnv 0x006921a0
void* Arr3520::FUN_006921a0(unsigned int flags)
{
    FUN_00691f90();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_00691fe0_class
{
    void FUN_00691fe0();
    void* FUN_006921d0(unsigned int flags);
};

// @fnv 0x006921d0
void* FUN_00691fe0_class::FUN_006921d0(unsigned int flags)
{
    FUN_00691fe0();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_00692320_class
{
    void ConstructEntries(int, int);
};
struct FUN_006923f0_class
{
    virtual void v0();
    virtual int Write(unsigned int);
    void FUN_006923f0(unsigned int requested, unsigned int savedSize);
    int iSize;
    int iPosition;
    int iDataLength;
};
// @fnv 0x006923f0
void FUN_006923f0_class::FUN_006923f0(unsigned int uiRequestedSize, unsigned int savedSize)
{
    iSize = 0;
    iPosition = 0;
    iDataLength = 0;
    if (savedSize > uiRequestedSize)
        uiRequestedSize = savedSize;
    if (uiRequestedSize > 0)
    {
        iSize = Write(uiRequestedSize);
        iDataLength = uiRequestedSize;
    }
    if (savedSize > 0)
    {
        ((FUN_00692320_class*)this)->ConstructEntries(iSize, savedSize);
        iPosition = savedSize;
    }
}

struct FUN_00692740_class
{
    virtual void v0();
    virtual int Write(unsigned int);
    void ConstructItems(int, unsigned int);
    void FUN_00692740(unsigned int requested, unsigned int savedSize);
    int iSize;
    int iPosition;
    int iDataLength;
};
// @fnv 0x00692740
void FUN_00692740_class::FUN_00692740(unsigned int requested, unsigned int savedSize)
{
    iSize = 0;
    iPosition = 0;
    iDataLength = 0;
    if (savedSize > requested)
    {
        requested = savedSize;
    }
    if (requested > 0)
    {
        iSize = Write(requested);
        iDataLength = requested;
    }
    if (savedSize > 0)
    {
        ConstructItems(iSize, savedSize);
        iPosition = savedSize;
    }
}

void __cdecl ClampUnsignedShort(unsigned short* p, unsigned short a, unsigned short b);
struct FUN_00693bd0_class
{
    int a;
    int b;
    int c;
    int d;
    int e;
    void FUN_00693bd0(unsigned short v);
};
// Calls ClampUnsignedShort on a local copy of v with 0 and 7, then stores bits 13-15 of the result into d.
// @fnv 0x00693bd0
void FUN_00693bd0_class::FUN_00693bd0(unsigned short ausValue)
{
    ClampUnsignedShort(&ausValue, 0, 7);
    d = (d & 0xffff1fff) | (ausValue << 0xd);
}

extern int DAT_0106abe4;
struct FUN_0069ada0_class : FUN_00692290_class
{
    FUN_0069ada0_class* FUN_0069ada0(unsigned int a, unsigned int b);
};
// Sets the vtable pointer to DAT_0106abe4, calls the base constructor with a and b, and returns this.
// @fnv 0x0069ada0
FUN_0069ada0_class* FUN_0069ada0_class::FUN_0069ada0(unsigned int a, unsigned int b)
{
    *(void**)this = (void*)&DAT_0106abe4;
    FUN_00692290(a, b);
    return this;
}

struct FUN_0069b640_class
{
    long long __thiscall GetPackedValue();
    int i0;
    unsigned short w4;
};
// Combines i0 and w4 into a 64-bit value by shifting i0 left 32 bits and w4 left 16 bits, then adding them.
// @fnv 0x0069b640
long long __thiscall FUN_0069b640_class::GetPackedValue()
{
    return ((long long)i0 << 32) + (w4 << 16);
}

namespace fnv_0069b6a0 {
struct TwoIntRecord
{
    int m;
    TwoIntRecord(const TwoIntRecord&);
    TwoIntRecord& operator=(const TwoIntRecord&);
};
struct Entry0069b6a0
{
    int f0;
    TwoIntRecord f4;
    int f8;
    int fc;
};
struct FUN_0069b6a0_class
{
    void __thiscall SetEntryValues(Entry0069b6a0* a, TwoIntRecord b, int c, int d);
};
// Copies b into a->f4 and stores d into a->fc; c is unused.
// @fnv 0x0069b6a0
void __thiscall FUN_0069b6a0_class::SetEntryValues(Entry0069b6a0* apEntry, TwoIntRecord aValue, int c, int aiValue)
{
    apEntry->f4 = aValue;
    apEntry->fc = aiValue;
}
}  // namespace fnv_0069b6a0

void __fastcall FUN_0069af60(struct GlobalObject_00869f00*);
void __cdecl _Deallocate(void*);
struct H69
{
    void* __thiscall FUN_0069b7e0(unsigned int);
};
// Calls FUN_0069af60 on this, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0069b7e0
void* __thiscall H69::FUN_0069b7e0(unsigned int flags)
{
    FUN_0069af60((struct GlobalObject_00869f00*)this);
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_0069b1d0_class
{
    void FUN_0069b1d0();
    void* FUN_0069b810(unsigned int flags);
};
// Calls FUN_0069b1d0, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x0069b810
void* FUN_0069b1d0_class::FUN_0069b810(unsigned int flags)
{
    FUN_0069b1d0();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_0069b730_class
{
    void FUN_0069b730();
    void* FUN_0069b870(unsigned int flags);
};
// @fnv 0x0069b870
void* FUN_0069b730_class::FUN_0069b870(unsigned int flags)
{
    FUN_0069b730();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_0042f830_struct
{
    void FUN_0042f9c0(unsigned char);
};
struct NavMeshPtr
{
    NavMeshPtr* p;
};
struct NavMeshTriangleReference
{
    int pad;
};
struct NavMeshTriangleEdgeReference
{
    int pad;
};
struct AStarConnectionArray
{
    NavMeshTriangleReference* nodes;
    NavMeshTriangleEdgeReference* links;
};
void AddNavMeshToGarbageCollector(NavMeshPtr&);
struct FUN_0069bca0_class : public FUN_0042f830_struct
{
    void FUN_0069bca0();
    AStarConnectionArray* FUN_0069b2c0(int);
    unsigned int GetFlags();
};
// @fnv 0x0069bca0
void FUN_0069bca0_class::FUN_0069bca0()
{
    unsigned int i = 0;
    for (; i < GetFlags(); ++i)
        AddNavMeshToGarbageCollector(*(NavMeshPtr*)FUN_0069b2c0(i));
    FUN_0042f9c0(1);
}

extern int DAT_0106b28c;
struct FUN_0069cd10_class
{
    int m_iWordAt00;
    void __thiscall InitializeBuffer(int a, int b);
    FUN_0069cd10_class* __thiscall FUN_0069cd10();
};
// @fnv 0x0069cd10
FUN_0069cd10_class* __thiscall FUN_0069cd10_class::FUN_0069cd10()
{
    m_iWordAt00 = (int)&DAT_0106b28c;
    InitializeBuffer(0, 0);
    return this;
}

void __cdecl operator delete(void*);

struct FUN_0069d0c0_class
{
    void InitAndClear();
    void* FUN_0069d0c0(unsigned int flags);
};

// Calls InitAndClear, then deletes this when flags has bit 0 set, and returns this.
// @fnv 0x0069d0c0
void* FUN_0069d0c0_class::FUN_0069d0c0(unsigned int flags)
{
    InitAndClear();
    if (flags & 1)
        operator delete(this);
    return this;
}

void* __cdecl operator new(unsigned int, void*);
struct Unk69d0f0
{
    void __thiscall FUN_0069d0f0(void* p, unsigned int n);
};
// @fnv 0x0069d0f0
void __thiscall Unk69d0f0::FUN_0069d0f0(void* apBuffer, unsigned int auiCount)
{
    int i;
    void* q;
    for (i = 0; (unsigned int)i < auiCount; ++i)
    {
        q = operator new(6, (void*)((char*)apBuffer + i * 6));
    }
}

struct BaseS
{
    BaseS();
    float f0;
    int f4;
    int f8;
};
struct FUN_0069d280
{
    int m0;
    int pad4;
    int pad8;
    BaseS a;
    BaseS b;
    int m24;
    FUN_0069d280();
};
// Initializes m0 and m24 to 0 and sets a.f0 to the maximum float value.
// @fnv 0x0069d280
FUN_0069d280::FUN_0069d280() : m0(0)
{
    m24 = 0;
    a.f0 = 3.4028234663852886e+38F;
}

struct FUN_0069da10_C
{
    int _pad[9];
    char* _p;
    bool __thiscall FUN_0069da10(unsigned short v, int idx);
};
// Indexes into the array at _p by idx and forwards v to the element's Contains, returning its result.
// @fnv 0x0069da10
bool __thiscall FUN_0069da10_C::FUN_0069da10(unsigned short ausValue, int aiIndex)
{
    FUN_0069dee0_class* e = (FUN_0069dee0_class*)(_p + (aiIndex << 4));
    return e->Contains(ausValue);
}

struct Dummy006815c0
{
    void __thiscall _ref_006815c0();
};
struct NavMesh
{
    void* FUN_0068efb0();
};
struct FUN_0069df10_Param
{
    NavMesh* p0;
    unsigned short w4;
    unsigned short pad6;
    int d8;
};
struct FUN_0069df10
{
    void* m0;
    unsigned short m4;
    int m8;
    FUN_0069df10(FUN_0069df10_Param* a);
};
// @fnv 0x0069df10
FUN_0069df10::FUN_0069df10(FUN_0069df10_Param* pParam)
{
    ((Dummy006815c0*)this)->_ref_006815c0();
    m0 = pParam->p0->FUN_0068efb0();
    m4 = pParam->w4;
    m8 = pParam->d8;
}

struct SDF10
{
    void __thiscall FUN_0069df10(const SDF10&);
};
struct SDFC0
{
    void __thiscall _ref_006815c0();
    int a;
    int b;
    int c;
};
struct FUN_0069df60
{
    char pad[24];
    FUN_0069df60(const FUN_0069df60&);
};
// @fnv 0x0069df60
FUN_0069df60::FUN_0069df60(const FUN_0069df60& o)
{
    ((SDF10*)this)->FUN_0069df10(*(SDF10*)&o);
    ((SDFC0*)((char*)this + 12))->_ref_006815c0();
    *((SDFC0*)((char*)this + 12)) = *((SDFC0*)((char*)&o + 12));
}

struct FUN_0069e090_class
{
    int f0;
    unsigned short f4;
    bool FUN_0069e090();
};
// Returns false when f0 is zero or f4 equals 0xffff, otherwise returns true.
// @fnv 0x0069e090
bool FUN_0069e090_class::FUN_0069e090()
{
    if (!f0)
        return false;
    if (f4 == 0xffff)
        return false;
    return true;
}

struct FUN_0069efa0_class
{
    void CallVirtualMethod();
    void* __thiscall FUN_0069efa0(unsigned int flags);
};
// Calls CallVirtualMethod, then deletes this when flags has bit 0 set, and returns this.
// @fnv 0x0069efa0
void* __thiscall FUN_0069efa0_class::FUN_0069efa0(unsigned int flags)
{
    CallVirtualMethod();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct VT_0069efd0
{
    virtual int f(int);
};
struct CLS_0069efd0
{
    char _pad[0x30];
    VT_0069efd0* p;
    void CallVirtualMethod();
};
// Calls the virtual method f(1) on the stored pointer p if it is non-null.
// @fnv 0x0069efd0
void CLS_0069efd0::CallVirtualMethod()
{
    VT_0069efd0* p1 = p;
    VT_0069efd0* p2 = p1;
    (p2 ? p2->f(1) : 0);
}

void* __cdecl FUN_00ec7230(char*, const char*, unsigned int);

struct FUN_00692480
{
    void Method(char* dst, char* src, unsigned int count);
};

// @fnv 0x00692480
void FUN_00692480::Method(char* dst, char* src, unsigned int count)
{
    if (count <= 0)
        return;
    if (dst < src)
    {
        for (unsigned int i = 0; i < count; ++i)
            FUN_00ec7230(dst + i * 8, src + i * 8, 8);
    }
    else if (dst > src)
    {
        for (int i = (int)count - 1; i >= 0; --i)
            FUN_00ec7230(dst + i * 8, src + i * 8, 8);
    }
}

struct FUN_006925b0_class
{
    virtual void v0();
    virtual void* v1(int);
    void* p;
    int iCount;
    int iSize;
    bool FUN_00438b90();
    unsigned int FUN_009a3910();
    void FUN_005efa80(unsigned int, int);
    int AppendSlot();
};

// Grows the buffer when needed, then increments iCount and returns the index of the newly added slot.
// @fnv 0x006925b0
int FUN_006925b0_class::AppendSlot()
{
    if (FUN_00438b90())
    {
        if (iSize == 0)
        {
            int n = 4;
            p = v1(n);
            iSize = n;
        }
        else
        {
            unsigned int n = FUN_009a3910();
            FUN_005efa80(n, iCount);
            iSize = n;
        }
    }
    ++iCount;
    return iCount - 1;
}

void* __cdecl FUN_00ec7230(char* dst, const char* src, unsigned int size);
struct FUN_006928a0_class
{
    void FUN_006928a0(char* a, char* b, unsigned int c);
};
// Copies c elements of 0x28 bytes from src to dst, iterating forward when dst < src and backward otherwise.
// @fnv 0x006928a0
void FUN_006928a0_class::FUN_006928a0(char* pDst, char* pSrc, unsigned int c)
{
    if (c <= 0)
        return;
    if (pDst < pSrc)
    {
        for (unsigned int i = 0; i < c; ++i)
            FUN_00ec7230(pDst + i * 0x28, pSrc + i * 0x28, 0x28);
    }
    else if (pDst > pSrc)
    {
        for (int i = c - 1; i >= 0; --i)
            FUN_00ec7230(pDst + i * 0x28, pSrc + i * 0x28, 0x28);
    }
}

// Compares the two unsigned shorts pointed to by a and b, returning 1 if the first is greater, -1 if smaller, else 0.
// @fnv 0x0069ae60
int FUN_0069ae60(const unsigned short* a, const unsigned short* b)
{
    const unsigned short* pLeft = a;
    const unsigned short* pRight = b;
    if (*pLeft > *pRight)
        return 1;
    else if (*pRight > *pLeft)
        return -1;
    else
        return 0;
}

struct FUN_006e1280_Class
{
    void FUN_006e1280(char*, unsigned int);
};

struct FUN_0069b940_class
{
    virtual void v0();
    virtual int Write(unsigned int);
    void FUN_0069b940(unsigned int requested, unsigned int savedSize);
    int iSize;
    int iPosition;
    int iDataLength;
};

// @fnv 0x0069b940
void FUN_0069b940_class::FUN_0069b940(unsigned int auiRequestedSize, unsigned int savedSize)
{
    iSize = 0;
    iPosition = 0;
    iDataLength = 0;
    if (savedSize > auiRequestedSize)
        auiRequestedSize = savedSize;
    if (auiRequestedSize > 0)
    {
        iSize = Write(auiRequestedSize);
        iDataLength = auiRequestedSize;
    }
    if (savedSize > 0)
    {
        ((FUN_006e1280_Class*)this)->FUN_006e1280((char*)iSize, savedSize);
        iPosition = savedSize;
    }
}

struct EH
{
    int x;
};
struct FUN_0069b310_S
{
    virtual int v0();
    virtual int Write(unsigned int);
    void ConstructBounds(int, int);
    int iSize;
    int iPosition;
    int iDataLength;
    void ResetAndWrite(unsigned int requested, unsigned int savedSize);
};
// @fnv 0x0069ba70
void FUN_0069b310_S::ResetAndWrite(unsigned int requested, unsigned int savedSize)
{
    iSize = 0;
    iPosition = 0;
    iDataLength = 0;
    if (savedSize > requested)
        requested = savedSize;
    if (requested > 0)
    {
        iSize = Write(requested);
        iDataLength = requested;
    }
    if (savedSize > 0)
    {
        ConstructBounds(iSize, savedSize);
        iPosition = savedSize;
    }
}

struct FUN_0069d140_class
{
    virtual void v0();
    virtual int Write(unsigned int);
    void InitializeBuffer(unsigned int requested, unsigned int savedSize);
    int iSize;
    int iPosition;
    int iDataLength;
};
// @fnv 0x0069d140
void FUN_0069d140_class::InitializeBuffer(unsigned int requested, unsigned int savedSize)
{
    iSize = 0;
    iPosition = 0;
    iDataLength = 0;
    if (savedSize > requested)
    {
        requested = savedSize;
    }
    if (requested > 0)
    {
        iSize = Write(requested);
        iDataLength = requested;
    }
    if (savedSize > 0)
    {
        ((Unk69d0f0*)this)->FUN_0069d0f0((void*)iSize, savedSize);
        iPosition = savedSize;
    }
}

struct NiTMallocInterface_0096afc0
{
    static ActorCombatGroup** __cdecl Allocate(unsigned int);
};

struct FUN_00682590_class
{
    void* p;
    int iSize;
    int iPosition;
    FUN_00682590_class* __thiscall FUN_00682590(unsigned int requested);
};

// Allocates requested bytes into p (or null when requested is 0), sets iSize to requested and iPosition to 0, then returns this.
// @fnv 0x00682590
FUN_00682590_class* __thiscall FUN_00682590_class::FUN_00682590(unsigned int requested)
{
    if (requested > 0)
        p = NiTMallocInterface_0096afc0::Allocate(requested);
    else
        p = 0;
    iSize = requested;
    iPosition = 0;
    return this;
}

namespace fnv_0068ac40 {
struct NiTMallocInterface_0096afc0
{
    static ActorCombatGroup** __cdecl Allocate(unsigned short);
};

struct FUN_0068ac40_class
{
    void* m_pData;
    void* m_pAllocationContext;
    unsigned short m_usSize;
    unsigned short m_usElementCount;
    unsigned short m_usUnknown2;
    unsigned short m_usUnknown;
    void* FUN_0068ac40(unsigned short usSize, unsigned short m_usPassCountLocal);
};

// @fnv 0x0068ac40
void* FUN_0068ac40_class::FUN_0068ac40(unsigned short usSize, unsigned short ausUnknown)
{
    m_pData = &DAT_01069d7c;
    m_usSize = usSize;
    m_usUnknown = ausUnknown;
    m_usElementCount = 0;
    m_usUnknown2 = 0;
    if (m_usSize > 0)
        m_pAllocationContext = NiTMallocInterface_0096afc0::Allocate(m_usSize);
    else
        m_pAllocationContext = 0;
    return this;
}
}  // namespace fnv_0068ac40

struct S5460
{
    virtual void v0();
    virtual void* v1(int);
    bool FUN_00438b90();
    unsigned int FUN_009a3910();
    void SetOrReplace(unsigned int, int);
    void* pData;
    int iPosition;
    int iDataLength;
    int GetNextPosition();
};
// @fnv 0x00692200
int S5460::GetNextPosition()
{
    if (FUN_00438b90())
    {
        if (iDataLength == 0)
        {
            int size = 4;
            pData = v1(size);
            iDataLength = size;
        }
        else
        {
            unsigned int newSize = FUN_009a3910();
            SetOrReplace(newSize, iPosition);
            iDataLength = newSize;
        }
    }
    ++iPosition;
    return iPosition - 1;
}

struct BSIntToType0
{
};
struct BSIntToType1
{
};
struct BSIntToTypeA
{
};
void BSEndian(unsigned char*, BSIntToType0);
void BSEndian(unsigned char*, BSIntToType1);
void BSEndian(unsigned char*, BSIntToTypeA);
struct TESFile
{
    bool GetChunkData();
};
struct TES
{
    void* GetActiveCell(void*, void*);
};
struct PortalHolder
{
    void LoadFormRef(void*);
};
extern int g_TES;
struct FUN_0069d1d0_class
{
    void ReadFromFile(TESFile* file, unsigned int* p);
};
// @fnv 0x0069d1d0
void FUN_0069d1d0_class::ReadFromFile(TESFile* file, unsigned int* puiValue)
{
    *(unsigned int*)this = *puiValue;
    if (file->GetChunkData())
        BSEndian((unsigned char*)this, BSIntToType0());
    puiValue++;
    ((PortalHolder*)((char*)this + 4))->LoadFormRef(((TES*)g_TES)->GetActiveCell(file, puiValue));
}

struct NiTMallocInterface_006826d0
{
    static void __cdecl Deallocate(void**);
};

struct FUN_006826d0_shell
{
    void** p;
    void FreeBuffer();
};

// @fnv 0x006826d0
void FUN_006826d0_shell::FreeBuffer()
{
    NiTMallocInterface_006826d0::Deallocate(p);
}

extern int $SG6833;
struct FUN_00683850_class
{
    void FUN_00683850();
};
// @fnv 0x00683850
void FUN_00683850_class::FUN_00683850()
{
    *reinterpret_cast<int*>(this) = (int)&$SG6833;
}

struct FUN_00693cd0_class
{
    int a;
    FUN_00693cf0_class b;
    int FUN_00693cd0();
};
// @fnv 0x00693cd0
int FUN_00693cd0_class::FUN_00693cd0()
{
    return b.GetSix() + 4;
}

struct FUN_00693dc0_class
{
    void SwapEndian();
};

// @fnv 0x00693dc0
void FUN_00693dc0_class::SwapEndian()
{
    BSEndian(reinterpret_cast<unsigned char*>(this), BSIntToType0());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 4, BSIntToType0());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 8, BSIntToType0());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 0xC, BSIntToType0());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 0x10, BSIntToType0());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 0x14, BSIntToType0());
}

struct FUN_005efdd0_class
{
    virtual void v0();
    char* pData;
    unsigned int iCount;
    void FUN_005efdd0(char*, char*, unsigned int);
};

struct FUN_0072ba80_shell : public FUN_005efdd0_class
{
    void FUN_0072ba80(char*, unsigned int);
};

struct FUN_0069add0_class : public FUN_0072ba80_shell
{
    void __thiscall FUN_0069add0(unsigned int, unsigned int);
};

unsigned int FUN_0042f5a0(unsigned int, unsigned int);

// @fnv 0x0069add0
void FUN_0069add0_class::FUN_0069add0(unsigned int uiStartIndex, unsigned int second)
{
    unsigned int result = FUN_0042f5a0(this->iCount - uiStartIndex - second, second);

    this->FUN_0072ba80(this->pData + uiStartIndex * 2, second);

    this->FUN_005efdd0(this->pData + uiStartIndex * 2, this->pData + this->iCount * 2 - result * 2, result);

    this->iCount = this->iCount - second;
}

namespace fnv_0069cd60 {
struct BSSimpleArrayActor
{
    virtual void v0();
    virtual void* v1(unsigned int size);

    char* pData;
    unsigned int mCount;
    unsigned int mCapacity;

    void Clear(bool shrink);
    void __thiscall FUN_005efc90(unsigned int size, unsigned int count);
    void __thiscall Resize(unsigned int size, bool shrink);
};

struct FUN_0072ba80_shell
{
    void __thiscall FUN_0072ba80(char* data, unsigned int count);
};

// @fnv 0x0069cd60
void BSSimpleArrayActor::Resize(unsigned int size, bool shrink)
{
    if (size == 0)
    {
        Clear(shrink);
    }
    else if (size > mCapacity)
    {
        if (mCapacity == 0)
        {
            pData = static_cast<char*>(v1(size));
            mCapacity = size;
        }
        else
        {
            FUN_005efc90(size, mCount);
            mCapacity = size;
        }

        reinterpret_cast<Unk69d0f0*>(this)->FUN_0069d0f0(pData + mCount * 6, size - mCount);
        mCount = size;
    }
    else if (size < mCount)
    {
        reinterpret_cast<FUN_0072ba80_shell*>(this)->FUN_0072ba80(pData + size * 6, mCount - size);
        mCount = size;

        if (shrink && size <= mCapacity / 4)
        {
            FUN_005efc90(size, size);
            mCapacity = size;
        }
    }
    else
    {
        reinterpret_cast<Unk69d0f0*>(this)->FUN_0069d0f0(pData + mCount * 6, size - mCount);
        mCount = size;
    }
}
}  // namespace fnv_0069cd60

struct P3
{
    float x;
    float y;
    float z;

    P3 operator-(const P3& rhs) const;
};

struct std
{
    static float __cdecl abs(float value);
};

struct FUN_004941c0_shell
{
    void __thiscall ScaleByInverse(float value);
};

template <> class BSSimpleArray<unsigned short, 1024>
{
  public:
    BSSimpleArray();
    ~BSSimpleArray();

  private:
    void* m_data;
    unsigned int m_iElementCount;
    unsigned int m_pRayCursor;
    unsigned int m_auiShapeKeys;
};

void __cdecl ClampUInt(unsigned int* value, unsigned int a, unsigned int b);

struct FUN_0069d800_class
{
    unsigned int m_unused0;
    float m_f4;
    float m_f8;
    P3 m_fc;
    P3 m_f18;
    BSSimpleArray<unsigned short, 1024>* m_p24;

    void InitFromPoints(const P3* a, const P3* b, unsigned int count);
};

// @fnv 0x0069d800
void FUN_0069d800_class::InitFromPoints(const P3* apPointA, const P3* apPointB, unsigned int count)
{
    m_fc = *apPointA;
    m_f18 = *apPointB;

    P3 delta = m_f18 - m_fc;

    if (count <= 0x10)
    {
        m_unused0 = 1;
    }
    else
    {
        m_unused0 = count / 50 + 2;
        ClampUInt(&m_unused0, 2, 12);
    }

    reinterpret_cast<FUN_004941c0_shell*>(&delta)->ScaleByInverse(static_cast<float>(m_unused0));

    m_f4 = std::abs(delta.x);
    m_f8 = std::abs(delta.y);

    unsigned int arraySize = m_unused0 * m_unused0;
    m_p24 = new BSSimpleArray<unsigned short, 1024>[arraySize];
}

// Reset the three header fields through the tag-dispatched clear helpers.

struct C81110ScalarTag
{
};

void __cdecl C81110ClearShort(short* psValue, C81110ScalarTag kTag);
void __cdecl C81110ClearInt(int* piValue, C81110ScalarTag kTag);

class C81110Header
{
  public:
    short m_sVersion;
    int m_iArrayLength;
    int m_iFlags;

    void ClearFields();
};

// @fnv 0x00681110
void C81110Header::ClearFields()
{
    C81110ClearShort(&m_sVersion, C81110ScalarTag());
    C81110ClearInt(&m_iArrayLength, C81110ScalarTag());
    C81110ClearInt(&m_iFlags, C81110ScalarTag());
}

struct Foo
{
    char m0;
    void FUN_00681530(int value);
};

// @fnv 0x00681530
void Foo::FUN_00681530(int value)
{
    int temp = value;
    if (value < 0 || value >= 6)
    {
        temp = 0;
    }
    temp <<= 5;
    m0 &= 0xffffff1f;
    m0 |= (char)temp;
}

struct B82380Param
{
    const char* m_pcName;
    unsigned int m_eRequestType;
    unsigned int m_bOptional;
};

struct B82380Command
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
    B82380Param* m_pkParams;
};

extern B82380Command DAT_01190900[];

unsigned int __cdecl FUN_00682270(unsigned short* pusCommand);

// @fnv 0x00682380
bool __cdecl FUN_00682380(unsigned short* pusCommand, unsigned int uiParam)
{
    bool bResult = false;
    if (pusCommand && uiParam < FUN_00682270(pusCommand))
    {
        switch (DAT_01190900[*pusCommand].m_pkParams[uiParam].m_eRequestType)
        {
        case 0x16:
            bResult = true;
        }
    }
    return bResult;
}

void __cdecl ReleaseSpawnedObject(void* data);

struct FUN_006826f0
{
    void* payload;
    unsigned int unknown04;
    FUN_006826f0* next;
    ~FUN_006826f0();
};

// @fnv 0x006826f0
FUN_006826f0::~FUN_006826f0()
{
    ReleaseSpawnedObject(payload);
    delete next;
}

class SpawnedObject
{
  public:
    virtual int vDel(int flags);
};

void __cdecl FormHeap_Free(void* p);

// @fnv 0x00682740
void __cdecl ReleaseSpawnedObject(SpawnedObject* apObject)
{
    SpawnedObject* a = apObject;
    SpawnedObject* p = a;
    SpawnedObject* kObj = p;
    int iResult;
    int iResult2;
    if (kObj != 0)
    {
        if (((int*)kObj)[-1] != 0)
        {
            iResult = p->vDel(3);
        }
        else
        {
            FormHeap_Free((char*)kObj - 4);
            iResult = 0;
        }
        iResult2 = iResult;
    }
    else
    {
        iResult2 = 0;
    }
}

struct B683670Node
{
    B683670Node* m_pkPrev;
    B683670Node* m_pkNext;
    void* m_pvElement;
};

class B683670List
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void FreeNode(B683670Node* pkNode);

    B683670Node* m_pkTail;
    B683670Node* m_pkHead;
    unsigned int m_uiCount;

    void* RemoveHead();
};

// Removes the head node from the list, unlinks it, frees it, decrements the count and returns its element.
// @fnv 0x00683670
void* B683670List::RemoveHead()
{
    B683670Node* pkNode = m_pkHead;
    m_pkHead = m_pkHead->m_pkNext;
    if (m_pkHead)
        m_pkHead->m_pkPrev = 0;
    else
        m_pkTail = 0;
    void* pvElement = pkNode->m_pvElement;
    FreeNode(pkNode);
    m_uiCount--;
    return pvElement;
}

// Raises base to exponent by binary exponentiation, returning the reciprocal when exponent is negative.
// @fnv 0x00688f10
float __cdecl PowFloat(float base, int exponent)
{
    unsigned int power;
    if (exponent >= 0)
        power = exponent;
    else
        power = -exponent;

    float result = 1.0f;
    for (;; base = base * base)
    {
        if (power & 1)
            result = result * base;
        power >>= 1;
        if (power == 0)
            return exponent < 0 ? 1.0 / result : result;
    }
}

struct SoundObject
{
    float* FUN_0045bb80();
};
struct SoundObjectRef
{
    SoundObject* object;
    SoundObject* FUN_00559450();
};
struct SoundRecord
{
    unsigned int FUN_0084e3a0();
};
struct SoundPair
{
    SoundRecord* GetField4C();
    SoundRecord* GetGrass();
};
struct ManagedSound
{
    unsigned int id;
    unsigned int state;
    unsigned int flags;
    ~ManagedSound();
    ManagedSound& operator=(const ManagedSound&);
    bool SetPositionFromArray(float*);
    bool SetNiNode(SoundObject*);
    bool Play(bool);
};
struct AudioManager
{
    ManagedSound FUN_00ad73b0(unsigned int, unsigned int);
};
AudioManager* FUN_00453a70();
struct LoopSoundState
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    SoundObjectRef object;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    SoundPair* sounds;
    ManagedSound first;
    ManagedSound second;
    void StopSounds();
    void InitLoopSounds();
};
// @fnv 0x0068a600
void LoopSoundState::InitLoopSounds()
{
    StopSounds();
    if (object.FUN_00559450() && sounds)
    {
        if (sounds->GetField4C())
        {
            unsigned int firstId = sounds->GetField4C()->FUN_0084e3a0();
            first = FUN_00453a70()->FUN_00ad73b0(firstId, 0x102);
            first.SetPositionFromArray(object.FUN_00559450()->FUN_0045bb80());
            first.SetNiNode(object.FUN_00559450());
            first.Play(false);
        }
        if (sounds->GetGrass())
        {
            unsigned int secondId = sounds->GetGrass()->FUN_0084e3a0();
            second = FUN_00453a70()->FUN_00ad73b0(secondId, 0x102);
            second.SetPositionFromArray(object.FUN_00559450()->FUN_0045bb80());
            second.SetNiNode(object.FUN_00559450());
            second.Play(false);
        }
    }
}

struct NiMatrix3_0068aa50
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    void FUN_006815c0();
    void FUN_0043f850(float scale);
    NiMatrix3_0068aa50* FUN_0043f8d0(NiMatrix3_0068aa50*, const NiMatrix3_0068aa50*);
};
struct NavMeshChain_0068aa50
{
    NavMeshChain_0068aa50* FUN_00461130();
    void FUN_004b45b0();
};
struct NavMeshNode_0068aa50
{
    NavMeshChain_0068aa50* FUN_009611e0(NiMatrix3_0068aa50*);
    void FUN_0043fa80(NiMatrix3_0068aa50*);
};
struct NavMeshSearchList_0068aa50
{
    NavMeshNode_0068aa50** entries;
    unsigned int count;
    unsigned int capacity;
    unsigned int growStep;
    NavMeshSearchList_0068aa50(int initial, int growth);
    ~NavMeshSearchList_0068aa50();
    unsigned int GetShortAtOffsetA();
    NavMeshNode_0068aa50** FUN_00877a30(unsigned int);
};
extern float DAT_0102b3c8;
struct FUN_0068aa50_shell
{
    void CollectUniqueChildValues(void*, NavMeshSearchList_0068aa50*, unsigned int*);
    void FUN_0068aa50(void*);
};
// @fnv 0x0068aa50
void FUN_0068aa50_shell::FUN_0068aa50(void* searchArg)
{
    NavMeshSearchList_0068aa50 items(10, 1);
    {
        unsigned int found = 0;
        CollectUniqueChildValues(searchArg, &items, &found);
        for (unsigned int i = 0; i < items.GetShortAtOffsetA(); ++i)
        {
            NavMeshNode_0068aa50* node = *items.FUN_00877a30(i);
            if (node)
            {
                NiMatrix3_0068aa50 a;
                node->FUN_009611e0(&a)->FUN_00461130()->FUN_004b45b0();
                NiMatrix3_0068aa50 b;
                b.FUN_006815c0();
                b.FUN_0043f850(DAT_0102b3c8);
                NiMatrix3_0068aa50 c;
                node->FUN_0043fa80(a.FUN_0043f8d0(&c, &b));
            }
        }
    }
}

struct DecompScopedRef
{
    unsigned int m_04;
    DecompScopedRef(void* source);
    ~DecompScopedRef();
};

struct DecompRefOwner
{
    unsigned int m_00;
    void ProcessScoped(DecompScopedRef& ref);
};

// Creates a DecompScopedRef from source, passes it to owner->ProcessScoped, then destroys it.
// @fnv 0x00690890
void ProcessWithScopedRef(DecompRefOwner* owner, void* source)
{
    DecompScopedRef ref(source);
    owner->ProcessScoped(ref);
}

struct CleanupMap : FUN_00691a00_class
{
    virtual ~CleanupMap()
    {
        FUN_00691a00();
    }
};
struct FUN_006919a0 : CleanupMap
{
    virtual ~FUN_006919a0();
    void __thiscall FUN_00438af0();
};
// @fnv 0x006919a0
FUN_006919a0::~FUN_006919a0()
{
    FUN_00438af0();
}

struct FUN_00691c10_class
{
    virtual void v0();
    void* m4;

    int FUN_00978bc0();
    void ConstructEntries(int, int);
    int FUN_00691c10(S00691c60 const&);
};

// @fnv 0x00691c10
int __thiscall FUN_00691c10_class::FUN_00691c10(S00691c60 const& aEntry)
{
    int count = FUN_00978bc0();

    ConstructEntries(count * 12 + reinterpret_cast<int>(m4), 1);

    reinterpret_cast<S00691c60*>(reinterpret_cast<int>(m4) + count * 12)->Assign(aEntry);

    return count;
}

struct FUN_00692000_data
{
    int values[10];
};

struct FUN_00692000_class
{
    void* unk00;
    void* pBase;

    int __thiscall AppendSlot();
    void __thiscall ConstructItems(void* data, int value);
    int __thiscall AddData(FUN_00692000_data* source);
};

// @fnv 0x00692000
int __thiscall FUN_00692000_class::AddData(FUN_00692000_data* source)
{
    int index = AppendSlot();

    ConstructItems((char*)pBase + index * 0x28, 1);

    *((FUN_00692000_data*)((char*)pBase + index * 0x28)) = *source;

    return index;
}

void* __cdecl operator new(unsigned int uiSize, void* pvMem);
void __cdecl operator delete(void* pvObject, void* pvMem);

struct B692320Entry
{
    int unk00;
    int unk04;
    int unk08;

    B692320Entry();
};

class B692320Allocator
{
  public:
    void ConstructEntries(B692320Entry* pkArray, unsigned int ItemUpdateArray);
};

// Default-constructs each of the given number of B692320Entry elements in place in the array.
// @fnv 0x00692320
void B692320Allocator::ConstructEntries(B692320Entry* pkArray, unsigned int ItemUpdateArray)
{
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
        new (&pkArray[i]) B692320Entry;
}

void* __cdecl operator new(unsigned int, void*);
inline void __cdecl operator delete(void*, void*)
{}

struct PathLocItem
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
    PathLocItem();
};

struct PathLocItemArray
{
    void ConstructItems(PathLocItem* items, unsigned int count);
};

// Constructs count PathLocItem objects in place in the items array via placement new.
// @fnv 0x00692640
void PathLocItemArray::ConstructItems(PathLocItem* items, unsigned int count)
{
    for (unsigned int i = 0; i < count; i++)
    {
        new (&items[i]) PathLocItem;
    }
}

void* operator new(unsigned int size, void* place);
void operator delete(void* object, void* place);

struct PairCell
{
    int m_unk00;
    int m_unk04;
    PairCell();
};

struct FUN_006927d0_cls
{
    void ConstructPairCells(PairCell* cells, unsigned int count);
};

// Default-constructs each of count PairCell objects in place in the cells array.
// @fnv 0x006927d0
void FUN_006927d0_cls::ConstructPairCells(PairCell* cells, unsigned int count)
{
    unsigned int i;
    for (i = 0; i < count; i++)
    {
        new (&cells[i]) PairCell();
    }
}

void FUN_00401080(void* p, bool flag);
void FUN_00407a90(void* p, bool flag);

struct SpawnedFlag
{
    bool m_bValue;
};

class FUN_00693c10_cls
{
  public:
    void FUN_00693c10();
};

// @fnv 0x00693c10
void FUN_00693c10_cls::FUN_00693c10()
{
    SpawnedFlag f0 = {};
    FUN_00401080((char*)this + 0xc, f0.m_bValue);
    SpawnedFlag f8 = {};
    FUN_00407a90((char*)this + 0, f8.m_bValue);
    SpawnedFlag f2 = {};
    FUN_00407a90((char*)this + 2, f2.m_bValue);
    SpawnedFlag fX = {};
    FUN_00407a90((char*)this + 4, fX.m_bValue);
    SpawnedFlag f9 = {};
    FUN_00407a90((char*)this + 6, f9.m_bValue);
    SpawnedFlag f5 = {};
    FUN_00407a90((char*)this + 8, f5.m_bValue);
    SpawnedFlag f7 = {};
    FUN_00407a90((char*)this + 0xa, f7.m_bValue);
}

// @fnv 0x00693db0
int __cdecl FUN_00693db0()
{
    return (int)46u;
}

unsigned int __cdecl FUN_0042f5a0(unsigned int a, unsigned int b);

struct Elem4
{
    int m_iValue;
};

class B120Array
{
  public:
    int unk00;
    Elem4* m_pData;
    int m_uiLogicalSize;

    void Destruct(Elem4* pkElems, unsigned int ItemUpdateArray);
    void Copy(void* pvDst, void* pvSrc, unsigned int ItemUpdateArray);
    void FUN_0069b120(int iIndex, int iCount);
};

// @fnv 0x0069b120
void B120Array::FUN_0069b120(int iIndex, int iCount)
{
    unsigned int uiTailCount = FUN_0042f5a0(m_uiLogicalSize - iIndex - iCount, iCount);
    Destruct(m_pData + iIndex, iCount);
    Copy(m_pData + iIndex, m_pData + m_uiLogicalSize - uiTailCount, uiTailCount);
    m_uiLogicalSize -= iCount;
}

// GetModuloOfValue: thiscall member, 2 int stack params, /Od.
// Calls the pack's FUN_0069b640_class member on the ADDRESS of the first
// stack parameter, then returns the low 32 bits of that result modulo
// the unsigned dword stored at this+4.

struct FUN_0069b620_cls
{
    int m_00;
    unsigned int m_04;

    unsigned int GetModuloOfValue(int a, int b);
};

// @fnv 0x0069b620
unsigned int FUN_0069b620_cls::GetModuloOfValue(int iValue, int iUnused)
{
    return (unsigned int)((FUN_0069b640_class*)&iValue)->GetPackedValue() % m_04;
}

struct KeyStruct
{
    int iValue;
    unsigned short usSub;
    unsigned char __thiscall Equals(KeyStruct const* other);
};

struct FUN_0069b680_cls
{
    void FUN_0069b680(KeyStruct k1, KeyStruct k2);
};

// @fnv 0x0069b680
void FUN_0069b680_cls::FUN_0069b680(KeyStruct aKey1, KeyStruct aKey2)
{
    aKey1.Equals(&aKey2);
}

struct FUN_0069b730_base
{
    virtual ~FUN_0069b730_base();
};

struct FUN_0069b6d0_cls : public FUN_0069b730_base
{
    void FUN_00438af0();
    virtual ~FUN_0069b6d0_cls();
};

// @fnv 0x0069b6d0
FUN_0069b6d0_cls::~FUN_0069b6d0_cls()
{
    FUN_00438af0();
}

void* __cdecl FormHeap_Allocate(unsigned int size);

struct Obj_b9971
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    Obj_b9971();
    static void* operator new(unsigned int size) throw()
    {
        return FormHeap_Allocate(size);
    }
    static void operator delete(void*, unsigned int);
};

struct FUN_0069b8a0_cls
{
    Obj_b9971* CreateObj();
};

// Allocates and constructs a new Obj_b9971 via its operator new and returns the pointer.
// @fnv 0x0069b8a0
Obj_b9971* FUN_0069b8a0_cls::CreateObj()
{
    return new Obj_b9971();
}

void __cdecl operator delete(void*, void*);
struct NiBound
{
    unsigned int unk00, unk04, unk08;
    NiBound();
};
struct PlacementRange
{
    void ConstructBounds(NiBound* begin, unsigned int count);
};
// Placement-constructs count NiBound objects in the buffer starting at begin.
// @fnv 0x0069b9d0
void PlacementRange::ConstructBounds(NiBound* apBounds, unsigned int count)
{
    for (unsigned int i = 0; i < count; ++i)
    {
        new (apBounds + i) NiBound;
    }
}

class B69BB90Handle
{
  public:
    ~B69BB90Handle();

    void* m_pvObject;
};

class B69BB90Entry
{
  public:
    bool IsEqual(B69BB90Handle& kHandle);
};

class B69BB90List
{
  public:
    unsigned int GetSize();
    B69BB90Entry* GetAt(unsigned int uiIndex);
    unsigned int FindIndex(B69BB90Handle kHandle);
};

// @fnv 0x0069bb90
unsigned int B69BB90List::FindIndex(B69BB90Handle kHandle)
{
    for (unsigned int i = 0; i < GetSize(); i++)
    {
        if (GetAt(i)->IsEqual(kHandle))
            return i;
    }
    return 0xffffffff;
}

struct FUN_0069bda0_sub18
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    ~FUN_0069bda0_sub18();
};

struct FUN_0069bda0_sub28
{
    int unk00;
    ~FUN_0069bda0_sub28();
};

struct FUN_0069bda0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    FUN_0069bda0_sub18 m_18;
    FUN_0069bda0_sub28 m_28;
    ~FUN_0069bda0_cls();
};

// @fnv 0x0069bda0
FUN_0069bda0_cls::~FUN_0069bda0_cls()
{}

struct FUN_0069cd60_class
{
    void Resize(unsigned int count, int flag);
};

struct FUN_0069d050_rec
{
    unsigned short m_00;
    unsigned short m_02;
    unsigned short m_04;
};

struct FUN_0069d050_cls
{
    int unk00;
    char* m_04;
    unsigned int m_08;
    void CopyRecordsTo(int a1);
};

// Calls Resize with m_08 and 1, then copies each 6-byte record from m_04 into the destination obtained via FUN_0069ccf0.
// @fnv 0x0069d050
void FUN_0069d050_cls::CopyRecordsTo(int apTarget)
{
    ((FUN_0069cd60_class*)apTarget)->Resize(m_08, 1);
    for (unsigned int i = 0; i < m_08; i++)
    {
        *(FUN_0069d050_rec*)((FUN_0069ccf0_class*)apTarget)->FUN_0069ccf0(i) = *(FUN_0069d050_rec*)(m_04 + i * 6);
    }
}

namespace fnv_0069d9a0 {
struct S_0069d9a0_cls
{
    void FUN_00691800();
    void* FUN_0069d9a0(unsigned int flags);
};

extern "C" void __stdcall FUN_00ec5fce(void* object, int elementSize, int count, void (S_0069d9a0_cls::*callback)());

extern "C" void __cdecl FormHeap_Free(void* apMemory);

// @fnv 0x0069d9a0
void* S_0069d9a0_cls::FUN_0069d9a0(unsigned int flags)
{
    if (flags & 2)
    {
        FUN_00ec5fce(this, 0x10, reinterpret_cast<int*>(this)[-1], &S_0069d9a0_cls::FUN_00691800);

        if (flags & 1)
        {
            FormHeap_Free(reinterpret_cast<char*>(this) - 4);
        }

        return reinterpret_cast<char*>(this) - 4;
    }

    FUN_00691800();

    if (flags & 1)
    {
        FormHeap_Free(this);
    }

    return this;
}
}  // namespace fnv_0069d9a0

struct S682680_Base
{
    void* m0;
    ~S682680_Base();
};

struct S528820_Caller
{
    void ClearField();
};

struct S006826a0_member
{
    ~S006826a0_member();
    void* m0;
    void* m8;
};

struct FUN_00682600 : S682680_Base
{
    int unk04;
    int unk08;
    S006826a0_member* unk0c;
    ~FUN_00682600();
};

// Calls ClearField on this object, then deletes the unk0c member.
// @fnv 0x00682600
FUN_00682600::~FUN_00682600()
{
    reinterpret_cast<S528820_Caller*>(this)->ClearField();
    delete unk0c;
}

struct P03MMHeap
{
    void FUN_00aa5610(void*);
};
struct P03MM
{
    P03MMHeap* FUN_00aa42e0();
};
P03MM* FUN_00401020();
void* FUN_00aa1070(unsigned int);
struct B006815c0
{
    float x, y, z;
    B006815c0();
};
struct NiPoint2
{
    float x, y;
    NiPoint2();
};
struct FUN_004a7800
{
    float x, y, z, w;
    FUN_004a7800();
};
struct Triangle6
{
    unsigned short a, b, c;
};
struct ResizeMesh
{
    unsigned int unk00;
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
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int vertexCount;
    unsigned int triangleCount;
    B006815c0* oldPositions;
    B006815c0* positions;
    B006815c0* oldNormals;
    B006815c0* normals;
    NiPoint2* oldCoordinates;
    NiPoint2* coordinates;
    FUN_004a7800* oldColors;
    FUN_004a7800* colors;
    Triangle6* oldTriangles;
    Triangle6* triangles;
    void ResizeMeshBuffers();
};
// Allocates new position, normal, coordinate, color and triangle buffers, copies the old data into them and frees the old buffers via the heap.
// @fnv 0x0068e760
void ResizeMesh::ResizeMeshBuffers()
{
    P03MMHeap* heap = FUN_00401020()->FUN_00aa42e0();
    positions = new B006815c0[vertexCount];
    __memcpy(positions, oldPositions, vertexCount * sizeof(B006815c0));
    heap->FUN_00aa5610(oldPositions);
    oldPositions = 0;
    normals = new B006815c0[vertexCount];
    __memcpy(normals, oldNormals, vertexCount * sizeof(B006815c0));
    heap->FUN_00aa5610(oldNormals);
    oldNormals = 0;
    coordinates = new NiPoint2[vertexCount];
    __memcpy(coordinates, oldCoordinates, vertexCount * sizeof(NiPoint2));
    heap->FUN_00aa5610(oldCoordinates);
    oldCoordinates = 0;
    colors = new FUN_004a7800[vertexCount];
    __memcpy(colors, oldColors, vertexCount * sizeof(FUN_004a7800));
    heap->FUN_00aa5610(oldColors);
    oldColors = 0;
    triangles = (Triangle6*)FUN_00aa1070((triangleCount * 3) * sizeof(unsigned short));
    __memcpy(triangles, oldTriangles, triangleCount * sizeof(Triangle6));
    heap->FUN_00aa5610(oldTriangles);
    oldTriangles = 0;
}

class B691930Ptr
{
  public:
    B691930Ptr(const B691930Ptr& kOther);
    ~B691930Ptr();
    B691930Ptr& operator=(const B691930Ptr& kOther);

    void* m_pObject;
};

struct B691930Item
{
    void* m_pkNext;
    unsigned short m_usKey;
    short unk06;
    B691930Ptr m_spValue;
};

class B691930Map
{
  public:
    virtual void VFunc00();

    void SetItemKeyAndValue(B691930Item* pkItem, unsigned short usKey, B691930Ptr spValue);
};

// Assigns usKey to pkItem->m_usKey and copies spValue into pkItem->m_spValue.
// @fnv 0x00691930
void B691930Map::SetItemKeyAndValue(B691930Item* pkItem, unsigned short usKey, B691930Ptr spValue)
{
    pkItem->m_usKey = usKey;
    pkItem->m_spValue = spValue;
}

static const float NI_INFINITY_69B = 3.402823466e+38f;
static const float NEG_INFINITY_69B = -NI_INFINITY_69B;

class NiPoint369B
{
  public:
    NiPoint369B(float fX, float fY, float fZ);

    float x;
    float y;
    float z;
};

class PathInfos69B
{
  public:
    void Clear(bool bFree);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

class PathBounds69B
{
  public:
    void FUN_0069be00();

    NiPoint369B m_kMax;
    NiPoint369B m_kMin;
    PathInfos69B m_kFirst;
    PathInfos69B m_kSecond;
};

// Initialises the max point to negative infinity, the min point to positive infinity, and clears both path info blocks.
// @fnv 0x0069be00
void PathBounds69B::FUN_0069be00()
{
    m_kMax = NiPoint369B(NEG_INFINITY_69B, NEG_INFINITY_69B, NEG_INFINITY_69B);
    m_kMin = NiPoint369B(NI_INFINITY_69B, NI_INFINITY_69B, NI_INFINITY_69B);
    m_kSecond.Clear(true);
    m_kFirst.Clear(true);
}

namespace bounds_detail {
class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3();
    NiPoint3(float, float, float);
    NiPoint3 operator-(const NiPoint3&) const;
    float FUN_004a7290() const;
};
struct BoundsTriangle
{
    unsigned short a, b, c;
};
struct BoundsTriangleArray
{
    void* allocator;
    BoundsTriangle* data;
    unsigned int size, capacity;
    unsigned int FUN_0044ddc0();
    BoundsTriangle& FUN_0069ccf0(unsigned int);
};
struct BoundsVertices
{
    void* allocator;
    NiPoint3* data;
    unsigned int size, capacity;
    bool FUN_0076b610() const;
    NiPoint3& FUN_006a1440(unsigned short);
};
class NavMeshBounds
{
  public:
    NiPoint3 minimum, maximum;
    BoundsTriangleArray triangles;
    BoundsVertices vertices;
    NiPoint3 FUN_0069c070(const NiPoint3& point);
};
extern const NiPoint3 pathingrequestZero;
bool __cdecl FUN_006b9cf0(const NiPoint3&, const NiPoint3&, const NiPoint3&, const NiPoint3&, float&, float, float);
NiPoint3 __cdecl GetClosestPointOnSegment(const NiPoint3&, const NiPoint3&, const NiPoint3&);

// @fnv 0x0069c070
NiPoint3 NavMeshBounds::FUN_0069c070(const NiPoint3& point)
{
    if (!vertices.FUN_0076b610())
    {
        float fPointHeight = 3.402823466e38f;
        NiPoint3 kClosest;
        for (unsigned int i = 0; i < triangles.FUN_0044ddc0(); i++)
        {
            float m_fGlyphExtent;
            float fZ;
            {
                NiPoint3 kTriangle[3];
                kTriangle[0] = vertices.FUN_006a1440(triangles.FUN_0069ccf0(i).a);
                kTriangle[1] = vertices.FUN_006a1440(triangles.FUN_0069ccf0(i).b);
                kTriangle[2] = vertices.FUN_006a1440(triangles.FUN_0069ccf0(i).c);
                m_fGlyphExtent = maximum.z - minimum.z;
                if (FUN_006b9cf0(kTriangle[0], kTriangle[1], kTriangle[2], point, fZ, m_fGlyphExtent, m_fGlyphExtent))
                    return NiPoint3(0.0f, 0.0f, fZ);
                for (int j = 0; j < 3; j++)
                {
                    float fDistance;
                    int next = j + 1;
                    if (next == 3)
                        next = 0;
                    {
                        NiPoint3 kPoint = GetClosestPointOnSegment(point, kTriangle[j], kTriangle[next]);
                        fDistance = (point - kPoint).FUN_004a7290();
                        if (fDistance < fPointHeight)
                        {
                            kClosest = kPoint;
                            fPointHeight = fDistance;
                        }
                    }
                }
            }
        }
        return kClosest - point;
    }
    else
    {
        if (point.x >= minimum.x && point.x <= maximum.x && point.y >= minimum.y && point.y <= maximum.y &&
            point.z >= minimum.z && point.z <= maximum.z)
        {
            return pathingrequestZero;
        }
        else
        {
            NiPoint3 kIntersectionOffset = pathingrequestZero;
            if (point.x > maximum.x)
                kIntersectionOffset.x = point.x - maximum.x;
            else if (point.x < minimum.x)
                kIntersectionOffset.x = point.x - minimum.x;
            else
                kIntersectionOffset.x = 0.0f;
            if (point.y > maximum.y)
                kIntersectionOffset.y = point.y - maximum.y;
            else if (point.y < minimum.y)
                kIntersectionOffset.y = point.y - minimum.y;
            else
                kIntersectionOffset.y = 0.0f;
            if (point.z > maximum.z)
                kIntersectionOffset.z = point.z - maximum.z;
            else if (point.z < minimum.z)
                kIntersectionOffset.z = point.z - minimum.z;
            else
                kIntersectionOffset.z = 0.0f;
            return kIntersectionOffset;
        }
    }
}

}

struct LDEndianTag
{
    bool bUnused;
};

void __cdecl LDSwap32(int* apValue, LDEndianTag aTag);
void __cdecl LDSwap16(short* apValue, LDEndianTag aTag);
extern "C" int __cdecl memcpy_s(void* apDest, unsigned int auiDestSize, const void* apSrc, unsigned int auiCount);

struct LDFile
{
    bool IsBigEndian();
};

struct LDPoint3
{
    float x;
    float y;
    float z;
};

struct LDTriangle
{
    short a;
    short b;
    short c;
};

struct LDVertexArray
{
    LDPoint3* pData;
    int unk04;
    int unk08;
    int unk0C;

    void SetSize(unsigned int auiSize, bool abExact);
    bool IsEmpty() const;
    unsigned int Size();
    LDPoint3* GetAt(unsigned int auiIndex);
};

struct LDTriangleArray
{
    LDTriangle* pData;
    int unk04;
    int unk08;
    int unk0C;

    void SetSize(unsigned int auiSize, bool abExact);
    unsigned int Size();
    LDTriangle* GetAt(unsigned int auiIndex);
};

struct LDMesh
{
    LDPoint3 kMinBoundsCur;
    LDPoint3 kMaxPoint;
    LDTriangleArray kTriangles;
    LDVertexArray kVertices;

    void Reset();
    void ReadFromBuffer(char* apData, LDFile* apFile, int aiUnused);
};

// Resets the mesh, reads two points, vertex and triangle counts and their arrays from apData, byte-swapping when the file is big-endian.
// @fnv 0x0069c8f0
void LDMesh::ReadFromBuffer(char* apData, LDFile* apFile, int aiUnused)
{
    unsigned short usVertexCountA;
    unsigned short usTriangleCount4;

    Reset();
    kMinBoundsCur = *(LDPoint3*)apData;
    if (apFile->IsBigEndian())
    {
        LDSwap32((int*)&kMinBoundsCur.x, LDEndianTag());
        LDSwap32((int*)&kMinBoundsCur.y, LDEndianTag());
        LDSwap32((int*)&kMinBoundsCur.z, LDEndianTag());
    }
    apData += sizeof(LDPoint3);

    kMaxPoint = *(LDPoint3*)apData;
    if (apFile->IsBigEndian())
    {
        LDSwap32((int*)&kMaxPoint.x, LDEndianTag());
        LDSwap32((int*)&kMaxPoint.y, LDEndianTag());
        LDSwap32((int*)&kMaxPoint.z, LDEndianTag());
    }
    apData += sizeof(LDPoint3);

    usVertexCountA = *(unsigned short*)apData;
    if (apFile->IsBigEndian())
        LDSwap16((short*)&usVertexCountA, LDEndianTag());
    kVertices.SetSize(usVertexCountA, true);
    apData += sizeof(unsigned short);

    usTriangleCount4 = *(unsigned short*)apData;
    if (apFile->IsBigEndian())
        LDSwap16((short*)&usTriangleCount4, LDEndianTag());
    kTriangles.SetSize(usTriangleCount4, true);
    apData += sizeof(unsigned short);

    if (!kVertices.IsEmpty())
    {
        memcpy_s(kVertices.GetAt(0), kVertices.Size() * sizeof(LDPoint3), apData, kVertices.Size() * sizeof(LDPoint3));
        if (apFile->IsBigEndian())
        {
            for (unsigned int i = 0; i < usVertexCountA; i++)
            {
                LDSwap32((int*)&kVertices.GetAt(i)->x, LDEndianTag());
                LDSwap32((int*)&kVertices.GetAt(i)->y, LDEndianTag());
                LDSwap32((int*)&kVertices.GetAt(i)->z, LDEndianTag());
            }
        }
        apData += kVertices.Size() * sizeof(LDPoint3);

        memcpy_s(kTriangles.GetAt(0), kTriangles.Size() * sizeof(LDTriangle), apData,
                 kTriangles.Size() * sizeof(LDTriangle));
        if (apFile->IsBigEndian())
        {
            for (unsigned int j = 0; j < usTriangleCount4; j++)
            {
                LDSwap16(&kTriangles.GetAt(j)->a, LDEndianTag());
                LDSwap16(&kTriangles.GetAt(j)->b, LDEndianTag());
                LDSwap16(&kTriangles.GetAt(j)->c, LDEndianTag());
            }
        }
        apData += kTriangles.Size() * sizeof(LDTriangle);
    }
}

float FUN_00406ce0(float);
void ClampInt(int* value, int lo, int hi);
struct Pt_0069d4b0
{
    float x;
    float y;
};
struct Tris_0069d4b0
{
    unsigned int FUN_0044ddc0();
    unsigned short& FUN_0069dec0(int index);
};
struct Out_0069d4b0
{
    unsigned int FUN_0044ddc0();
    unsigned short& FUN_0069dec0(int index);
    unsigned int Append(const unsigned short* tri);
    bool FUN_0076b610();
    void FUN_0069aeb0(int (*cmp)(const unsigned short*, const unsigned short*));
    void FUN_0069add0(unsigned int index, unsigned int count);
};
struct Dups_0069d4b0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Dups_0069d4b0();
    ~Dups_0069d4b0();
    bool FUN_0076b610();
    unsigned int FUN_0044ddc0();
    unsigned int FUN_007cb2e0(const unsigned int& index);
    unsigned int& FUN_00877a30(unsigned int index);
};
struct Sub0069d4b0
{
    int m_uiItemCount;
    float m_cellW;
    float m_cellH;
    float m_originX;
    float m_originY;
    Tris_0069d4b0* FUN_006967c0(int x, int y);
    void FUN_0069d4b0(Pt_0069d4b0* a1, Pt_0069d4b0* a2, Out_0069d4b0* a3);
};
// @fnv 0x0069d4b0
void Sub0069d4b0::FUN_0069d4b0(Pt_0069d4b0* a1, Pt_0069d4b0* a2, Out_0069d4b0* apOut)
{
    float dx9 = a1->x - m_originX;
    float dy2 = a1->y - m_originY;
    float fx = dx9 / m_cellW;
    float fy4 = dy2 / m_cellH;
    int x9 = (int)FUN_00406ce0(fx);
    int y0 = (int)FUN_00406ce0(fy4);
    ClampInt(&y0, 0, m_uiItemCount - 1);
    ClampInt(&x9, 0, m_uiItemCount - 1);
    dx9 = a1->x - m_originX;
    dy2 = a1->y - m_originY;
    fx = dx9 / m_cellW;
    fy4 = dy2 / m_cellH;
    int x5 = (int)FUN_00406ce0(fx);
    int y8 = (int)FUN_00406ce0(fy4);
    ClampInt(&y8, 0, m_uiItemCount - 1);
    ClampInt(&x5, 0, m_uiItemCount - 1);
    for (int y7 = y0; y7 <= y8; y7++)
    {
        for (int x7 = x9; x7 <= x5; x7++)
        {
            Tris_0069d4b0* tris = FUN_006967c0(x7, y7);
            for (unsigned int i = 0; i < tris->FUN_0044ddc0(); i++)
            {
                apOut->Append(&tris->FUN_0069dec0(i));
            }
        }
    }
    if (apOut->FUN_0076b610())
        return;
    apOut->FUN_0069aeb0(FUN_0069ae60);
    Dups_0069d4b0 dups_;
    for (unsigned int i = 0; i < apOut->FUN_0044ddc0() - 1; i++)
    {
        if (apOut->FUN_0069dec0(i + 1) == apOut->FUN_0069dec0(i))
        {
            dups_.FUN_007cb2e0(i + 1);
        }
    }
    if (dups_.FUN_0076b610())
        return;
    for (int j = dups_.FUN_0044ddc0() - 1; j >= 0; j--)
    {
        apOut->FUN_0069add0(dups_.FUN_00877a30(j), 1);
    }
}

struct NavMesh_bc50
{
    void FUN_007037c0(unsigned int value);
};

struct NavMeshHandle_bc50
{
    NavMesh_bc50* FUN_00559450() const;
};

void AddNavMeshToGarbageCollector(NavMeshHandle_bc50& handle);

struct NavMeshArray_bc50
{
    NavMeshHandle_bc50& FUN_00877a30(unsigned int index);
    void RemoveAt(unsigned int index, bool compact);
    void RemoveAndCollect(unsigned int index);
};

// Calls FUN_007037c0(0) on the nav mesh at index, passes its handle to AddNavMeshToGarbageCollector, then calls RemoveAt(index, true).
// @fnv 0x0069bc50
void NavMeshArray_bc50::RemoveAndCollect(unsigned int index)
{
    FUN_00877a30(index).FUN_00559450()->FUN_007037c0(0);
    AddNavMeshToGarbageCollector(FUN_00877a30(index));
    RemoveAt(index, true);
}

struct GlobalObject_006836f0
{
    ~GlobalObject_006836f0();
};
struct FUN_00683710 : GlobalObject_006836f0
{
    virtual ~FUN_00683710();
};
// @fnv 0x00683710
FUN_00683710::~FUN_00683710()
{}

struct NavMeshVertexMap
{
    ~NavMeshVertexMap();
};
void _Deallocate(void*);
struct FUN_0069ad70 : NavMeshVertexMap
{
    virtual ~FUN_0069ad70();
};
// Destructor with an empty body; the NavMeshVertexMap base destructor runs implicitly.
// @fnv 0x0069ad70
FUN_0069ad70::~FUN_0069ad70()
{}

struct NavMeshInfo;
void __cdecl _Deallocate(void*);
struct FUN_0069b7b0 : BSSimpleArray<NavMeshInfo*, 1024>
{
    virtual ~FUN_0069b7b0();
};
// Destructor with an empty body; the BSSimpleArray<NavMeshInfo*, 1024> base is destroyed implicitly.
// @fnv 0x0069b7b0
FUN_0069b7b0::~FUN_0069b7b0()
{}

struct FUN_0069b2f0
{
    virtual ~FUN_0069b2f0();
};
struct FUN_0069b840 : FUN_0069b2f0
{
    virtual ~FUN_0069b840();
};
// @fnv 0x0069b840
FUN_0069b840::~FUN_0069b840()
{}

namespace fnv_0069f010 {
extern unsigned char DAT_011d6dcc;
extern float DAT_01030ff4;
extern double DAT_0101de30;
extern int DAT_011f426c;

void* operator new(unsigned int n);
void* __cdecl FUN_00aa13e0(unsigned int n);
void* __cdecl FormHeap_Allocate(unsigned int n);
void* __stdcall GetPathManager(void* p, int a);
void* __cdecl FUN_00c56680(float f, int a, int b, void* p);
void __cdecl AttachLightingPropertyRecursive(void* p);
void __cdecl FUN_00b57e30(void* p, int a, int b);

struct ObjX
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000c;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001c;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002c;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003c;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004c;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005c;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006c;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007c;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008c;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009c;
    int unk00a0;
    int unk00a4;
    int unk00a8;
    ObjX(int a);
    static void* operator new(unsigned int n);
    static void operator delete(void*, unsigned int);
};
struct ObjY
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000c;
    int unk0010;
    int unk0014;
    int unk0018;
    ObjY();
    static void* operator new(unsigned int n);
    static void operator delete(void*, unsigned int);
    ObjY* FUN_004391c0();
};
struct GRes2
{
    bool ForwardToHost();
};
struct LinkT;
struct ArrObj
{
    int d0;
    int d1;
    int d2;
    int d3;
    unsigned int FUN_0044ddc0();
    void* FUN_00558dd0(unsigned int i);
    void** FUN_00877a30(unsigned int i);
    LinkT* GetFirst();
};
struct Obj2088
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000c;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001c;
    int unk0020;
    int unk0024;
    void FUN_006dcce0(void* p);
    void FUN_006dd6f0(int a);
    bool FUN_006dd6a0();
};
struct Obj20d8
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000c;
    bool ProcessSearchNode(void* p, int a);
};
struct ElemE
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    void* m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    void* m_28;
    int m_2c;
    int m_30;
    int m_34;
};
struct ArrE
{
    int d0;
    int d1;
    int d2;
    int d3;
    unsigned int FUN_0044ddc0();
    ElemE* GetBufferElementAddress(unsigned int i);
};
struct Vec3
{
    float x;
    float y;
    float z;
    Vec3 FUN_00439ef0(const Vec3& other);
    float FUN_00457990();
};
struct Node
{
    int m_00;
    Vec3 m_v4;
    float m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    unsigned short m_34;
    unsigned short m_36;
    Node();
};
struct LinkT
{
    void FUN_007cb2e0(Node** pp);
};
struct Vec3Obj
{
    Vec3 FUN_005c3420();
};
struct ResObj
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
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
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vtarget(void* p, int a);
    void FUN_00440460(void* p);
    void FUN_00439410(void* p);
    void FUN_00a5a040();
    void FUN_00a59c60(void* p);
};
struct AuxObj
{
    void FUN_0049ed90(int a);
};
struct ObjB
{
    int m_00;
    ObjB(void* p);
    ~ObjB();
    ResObj* FUN_00559450();
};
struct ObjA
{
    float m_00;
    float m_04;
    float m_08;
    float m_0c;
    ObjA(float a, float b, float c, float d);
};
struct StrObj
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000c;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001c;
    int unk0020;
    int unk0024;
    StrObj(void* a, void* b);
    ~StrObj();
};
struct VecObj
{
    float m_00;
    int m_04;
    int m_08;
    VecObj(float f, int a, int b);
};
struct DelObj
{
    ~DelObj();
};
struct NavLike
{
    void* FUN_0068efb0();
};

struct VRes
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
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
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vtarget(void* p, int a);
    void FUN_00a5a040();
    void FUN_00a59c60(void* p);
};
struct GObj
{
    bool FUN_0052aa80(int a);
    void FUN_0066b0d0(void* p);
    ResObj* FUN_00559450();
};
extern GObj DAT_011d6ddc;
struct A4Obj
{
    void FUN_0069f920(StrObj* s, void* p);
};
struct HdrS
{
    Node* p;
    int a;
    int b;
};

struct ThisCls
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000c;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001c;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002c;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003c;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004c;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005c;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006c;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007c;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008c;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009c;
    int unk00a0;
    int unk00a4;
    int unk00a8;
    int unk00ac;
    int unk00b0;
    int unk00b4;
    int unk00b8;
    int unk00bc;
    int unk00c0;
    int unk00c4;
    int unk00c8;
    int unk00cc;
    int unk00d0;
    int unk00d4;
    int unk00d8;
    int unk00dc;
    int unk00e0;
    int unk00e4;
    int unk00e8;
    int unk00ec;
    int unk00f0;
    int unk00f4;
    int unk00f8;
    int unk00fc;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010c;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011c;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012c;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013c;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014c;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015c;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016c;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017c;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018c;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019c;
    int unk01a0;
    int unk01a4;
    int unk01a8;
    int unk01ac;
    int unk01b0;
    int unk01b4;
    int unk01b8;
    int unk01bc;
    int unk01c0;
    int unk01c4;
    int unk01c8;
    int unk01cc;
    int unk01d0;
    int unk01d4;
    int unk01d8;
    int unk01dc;
    int unk01e0;
    int unk01e4;
    int unk01e8;
    int unk01ec;
    int unk01f0;
    int unk01f4;
    int unk01f8;
    int unk01fc;
    int unk0200;
    int unk0204;
    int unk0208;
    int unk020c;
    int unk0210;
    int unk0214;
    int unk0218;
    int unk021c;
    int unk0220;
    int unk0224;
    int unk0228;
    int unk022c;
    int unk0230;
    int unk0234;
    int unk0238;
    int unk023c;
    int unk0240;
    int unk0244;
    int unk0248;
    int unk024c;
    int unk0250;
    int unk0254;
    int unk0258;
    int unk025c;
    int unk0260;
    int unk0264;
    int unk0268;
    int unk026c;
    int unk0270;
    int unk0274;
    int unk0278;
    int unk027c;
    int unk0280;
    int unk0284;
    int unk0288;
    int unk028c;
    int unk0290;
    int unk0294;
    int unk0298;
    int unk029c;
    int unk02a0;
    int unk02a4;
    int unk02a8;
    int unk02ac;
    int unk02b0;
    int unk02b4;
    int unk02b8;
    int unk02bc;
    int unk02c0;
    int unk02c4;
    int unk02c8;
    int unk02cc;
    int unk02d0;
    int unk02d4;
    int unk02d8;
    int unk02dc;
    int unk02e0;
    int unk02e4;
    int unk02e8;
    int unk02ec;
    int unk02f0;
    int unk02f4;
    int unk02f8;
    int unk02fc;
    int unk0300;
    int unk0304;
    int unk0308;
    int unk030c;
    int unk0310;
    int unk0314;
    int unk0318;
    int unk031c;
    int unk0320;
    int unk0324;
    int unk0328;
    int unk032c;
    int unk0330;
    int unk0334;
    int unk0338;
    int unk033c;
    int unk0340;
    int unk0344;
    int unk0348;
    int unk034c;
    int unk0350;
    int unk0354;
    int unk0358;
    int unk035c;
    int unk0360;
    int unk0364;
    int unk0368;
    int unk036c;
    int unk0370;
    int unk0374;
    int unk0378;
    int unk037c;
    int unk0380;
    int unk0384;
    int unk0388;
    int unk038c;
    int unk0390;
    int unk0394;
    int unk0398;
    int unk039c;
    int unk03a0;
    int unk03a4;
    int unk03a8;
    int unk03ac;
    int unk03b0;
    int unk03b4;
    int unk03b8;
    int unk03bc;
    int unk03c0;
    int unk03c4;
    int unk03c8;
    int unk03cc;
    int unk03d0;
    int unk03d4;
    int unk03d8;
    int unk03dc;
    int unk03e0;
    int unk03e4;
    int unk03e8;
    int unk03ec;
    int unk03f0;
    int unk03f4;
    int unk03f8;
    int unk03fc;
    int unk0400;
    int unk0404;
    int unk0408;
    int unk040c;
    int unk0410;
    int unk0414;
    int unk0418;
    int unk041c;
    int unk0420;
    int unk0424;
    int unk0428;
    int unk042c;
    int unk0430;
    int unk0434;
    int unk0438;
    int unk043c;
    int unk0440;
    int unk0444;
    int unk0448;
    int unk044c;
    int unk0450;
    int unk0454;
    int unk0458;
    int unk045c;
    int unk0460;
    int unk0464;
    int unk0468;
    int unk046c;
    int unk0470;
    int unk0474;
    int unk0478;
    int unk047c;
    int unk0480;
    int unk0484;
    int unk0488;
    int unk048c;
    int unk0490;
    int unk0494;
    int unk0498;
    int unk049c;
    int unk04a0;
    int unk04a4;
    int unk04a8;
    int unk04ac;
    int unk04b0;
    int unk04b4;
    int unk04b8;
    int unk04bc;
    int unk04c0;
    int unk04c4;
    int unk04c8;
    int unk04cc;
    int unk04d0;
    int unk04d4;
    int unk04d8;
    int unk04dc;
    int unk04e0;
    int unk04e4;
    int unk04e8;
    int unk04ec;
    int unk04f0;
    int unk04f4;
    int unk04f8;
    int unk04fc;
    int unk0500;
    int unk0504;
    int unk0508;
    int unk050c;
    int unk0510;
    int unk0514;
    int unk0518;
    int unk051c;
    int unk0520;
    int unk0524;
    int unk0528;
    int unk052c;
    int unk0530;
    int unk0534;
    int unk0538;
    int unk053c;
    int unk0540;
    int unk0544;
    int unk0548;
    int unk054c;
    int unk0550;
    int unk0554;
    int unk0558;
    int unk055c;
    int unk0560;
    int unk0564;
    int unk0568;
    int unk056c;
    int unk0570;
    int unk0574;
    int unk0578;
    int unk057c;
    int unk0580;
    int unk0584;
    int unk0588;
    int unk058c;
    int unk0590;
    int unk0594;
    int unk0598;
    int unk059c;
    int unk05a0;
    int unk05a4;
    int unk05a8;
    int unk05ac;
    int unk05b0;
    int unk05b4;
    int unk05b8;
    int unk05bc;
    int unk05c0;
    int unk05c4;
    int unk05c8;
    int unk05cc;
    int unk05d0;
    int unk05d4;
    int unk05d8;
    int unk05dc;
    int unk05e0;
    int unk05e4;
    int unk05e8;
    int unk05ec;
    int unk05f0;
    int unk05f4;
    int unk05f8;
    int unk05fc;
    int unk0600;
    int unk0604;
    int unk0608;
    int unk060c;
    int unk0610;
    int unk0614;
    int unk0618;
    int unk061c;
    int unk0620;
    int unk0624;
    int unk0628;
    int unk062c;
    int unk0630;
    int unk0634;
    int unk0638;
    int unk063c;
    int unk0640;
    int unk0644;
    int unk0648;
    int unk064c;
    int unk0650;
    int unk0654;
    int unk0658;
    int unk065c;
    int unk0660;
    int unk0664;
    int unk0668;
    int unk066c;
    int unk0670;
    int unk0674;
    int unk0678;
    int unk067c;
    int unk0680;
    int unk0684;
    int unk0688;
    int unk068c;
    int unk0690;
    int unk0694;
    int unk0698;
    int unk069c;
    int unk06a0;
    int unk06a4;
    int unk06a8;
    int unk06ac;
    int unk06b0;
    int unk06b4;
    int unk06b8;
    int unk06bc;
    int unk06c0;
    int unk06c4;
    int unk06c8;
    int unk06cc;
    int unk06d0;
    int unk06d4;
    int unk06d8;
    int unk06dc;
    int unk06e0;
    int unk06e4;
    int unk06e8;
    int unk06ec;
    int unk06f0;
    int unk06f4;
    int unk06f8;
    int unk06fc;
    int unk0700;
    int unk0704;
    int unk0708;
    int unk070c;
    int unk0710;
    int unk0714;
    int unk0718;
    int unk071c;
    int unk0720;
    int unk0724;
    int unk0728;
    int unk072c;
    int unk0730;
    int unk0734;
    int unk0738;
    int unk073c;
    int unk0740;
    int unk0744;
    int unk0748;
    int unk074c;
    int unk0750;
    int unk0754;
    int unk0758;
    int unk075c;
    int unk0760;
    int unk0764;
    int unk0768;
    int unk076c;
    int unk0770;
    int unk0774;
    int unk0778;
    int unk077c;
    int unk0780;
    int unk0784;
    int unk0788;
    int unk078c;
    int unk0790;
    int unk0794;
    int unk0798;
    int unk079c;
    int unk07a0;
    int unk07a4;
    int unk07a8;
    int unk07ac;
    int unk07b0;
    int unk07b4;
    int unk07b8;
    int unk07bc;
    int unk07c0;
    int unk07c4;
    int unk07c8;
    int unk07cc;
    int unk07d0;
    int unk07d4;
    int unk07d8;
    int unk07dc;
    int unk07e0;
    int unk07e4;
    int unk07e8;
    int unk07ec;
    int unk07f0;
    int unk07f4;
    int unk07f8;
    int unk07fc;
    int unk0800;
    int unk0804;
    int unk0808;
    int unk080c;
    int unk0810;
    int unk0814;
    int unk0818;
    int unk081c;
    int unk0820;
    int unk0824;
    int unk0828;
    int unk082c;
    int unk0830;
    int unk0834;
    int unk0838;
    int unk083c;
    int unk0840;
    int unk0844;
    int unk0848;
    int unk084c;
    int unk0850;
    int unk0854;
    int unk0858;
    int unk085c;
    int unk0860;
    int unk0864;
    int unk0868;
    int unk086c;
    int unk0870;
    int unk0874;
    int unk0878;
    int unk087c;
    int unk0880;
    int unk0884;
    int unk0888;
    int unk088c;
    int unk0890;
    int unk0894;
    int unk0898;
    int unk089c;
    int unk08a0;
    int unk08a4;
    int unk08a8;
    int unk08ac;
    int unk08b0;
    int unk08b4;
    int unk08b8;
    int unk08bc;
    int unk08c0;
    int unk08c4;
    int unk08c8;
    int unk08cc;
    int unk08d0;
    int unk08d4;
    int unk08d8;
    int unk08dc;
    int unk08e0;
    int unk08e4;
    int unk08e8;
    int unk08ec;
    int unk08f0;
    int unk08f4;
    int unk08f8;
    int unk08fc;
    int unk0900;
    int unk0904;
    int unk0908;
    int unk090c;
    int unk0910;
    int unk0914;
    int unk0918;
    int unk091c;
    int unk0920;
    int unk0924;
    int unk0928;
    int unk092c;
    int unk0930;
    int unk0934;
    int unk0938;
    int unk093c;
    int unk0940;
    int unk0944;
    int unk0948;
    int unk094c;
    int unk0950;
    int unk0954;
    int unk0958;
    int unk095c;
    int unk0960;
    int unk0964;
    int unk0968;
    int unk096c;
    int unk0970;
    int unk0974;
    int unk0978;
    int unk097c;
    int unk0980;
    int unk0984;
    int unk0988;
    int unk098c;
    int unk0990;
    int unk0994;
    int unk0998;
    int unk099c;
    int unk09a0;
    int unk09a4;
    int unk09a8;
    int unk09ac;
    int unk09b0;
    int unk09b4;
    int unk09b8;
    int unk09bc;
    int unk09c0;
    int unk09c4;
    int unk09c8;
    int unk09cc;
    int unk09d0;
    int unk09d4;
    int unk09d8;
    int unk09dc;
    int unk09e0;
    int unk09e4;
    int unk09e8;
    int unk09ec;
    int unk09f0;
    int unk09f4;
    int unk09f8;
    int unk09fc;
    int unk0a00;
    int unk0a04;
    int unk0a08;
    int unk0a0c;
    int unk0a10;
    int unk0a14;
    int unk0a18;
    int unk0a1c;
    int unk0a20;
    int unk0a24;
    int unk0a28;
    int unk0a2c;
    int unk0a30;
    int unk0a34;
    int unk0a38;
    int unk0a3c;
    int unk0a40;
    int unk0a44;
    int unk0a48;
    int unk0a4c;
    int unk0a50;
    int unk0a54;
    int unk0a58;
    int unk0a5c;
    int unk0a60;
    int unk0a64;
    int unk0a68;
    int unk0a6c;
    int unk0a70;
    int unk0a74;
    int unk0a78;
    int unk0a7c;
    int unk0a80;
    int unk0a84;
    int unk0a88;
    int unk0a8c;
    int unk0a90;
    int unk0a94;
    int unk0a98;
    int unk0a9c;
    int unk0aa0;
    int unk0aa4;
    int unk0aa8;
    int unk0aac;
    int unk0ab0;
    int unk0ab4;
    int unk0ab8;
    int unk0abc;
    int unk0ac0;
    int unk0ac4;
    int unk0ac8;
    int unk0acc;
    int unk0ad0;
    int unk0ad4;
    int unk0ad8;
    int unk0adc;
    int unk0ae0;
    int unk0ae4;
    int unk0ae8;
    int unk0aec;
    int unk0af0;
    int unk0af4;
    int unk0af8;
    int unk0afc;
    int unk0b00;
    int unk0b04;
    int unk0b08;
    int unk0b0c;
    int unk0b10;
    int unk0b14;
    int unk0b18;
    int unk0b1c;
    int unk0b20;
    int unk0b24;
    int unk0b28;
    int unk0b2c;
    int unk0b30;
    int unk0b34;
    int unk0b38;
    int unk0b3c;
    int unk0b40;
    int unk0b44;
    int unk0b48;
    int unk0b4c;
    int unk0b50;
    int unk0b54;
    int unk0b58;
    int unk0b5c;
    int unk0b60;
    int unk0b64;
    int unk0b68;
    int unk0b6c;
    int unk0b70;
    int unk0b74;
    int unk0b78;
    int unk0b7c;
    int unk0b80;
    int unk0b84;
    int unk0b88;
    int unk0b8c;
    int unk0b90;
    int unk0b94;
    int unk0b98;
    int unk0b9c;
    int unk0ba0;
    int unk0ba4;
    int unk0ba8;
    int unk0bac;
    int unk0bb0;
    int unk0bb4;
    int unk0bb8;
    int unk0bbc;
    int unk0bc0;
    int unk0bc4;
    int unk0bc8;
    int unk0bcc;
    int unk0bd0;
    int unk0bd4;
    int unk0bd8;
    int unk0bdc;
    int unk0be0;
    int unk0be4;
    int unk0be8;
    int unk0bec;
    int unk0bf0;
    int unk0bf4;
    int unk0bf8;
    int unk0bfc;
    int unk0c00;
    int unk0c04;
    int unk0c08;
    int unk0c0c;
    int unk0c10;
    int unk0c14;
    int unk0c18;
    int unk0c1c;
    int unk0c20;
    int unk0c24;
    int unk0c28;
    int unk0c2c;
    int unk0c30;
    int unk0c34;
    int unk0c38;
    int unk0c3c;
    int unk0c40;
    int unk0c44;
    int unk0c48;
    int unk0c4c;
    int unk0c50;
    int unk0c54;
    int unk0c58;
    int unk0c5c;
    int unk0c60;
    int unk0c64;
    int unk0c68;
    int unk0c6c;
    int unk0c70;
    int unk0c74;
    int unk0c78;
    int unk0c7c;
    int unk0c80;
    int unk0c84;
    int unk0c88;
    int unk0c8c;
    int unk0c90;
    int unk0c94;
    int unk0c98;
    int unk0c9c;
    int unk0ca0;
    int unk0ca4;
    int unk0ca8;
    int unk0cac;
    int unk0cb0;
    int unk0cb4;
    int unk0cb8;
    int unk0cbc;
    int unk0cc0;
    int unk0cc4;
    int unk0cc8;
    int unk0ccc;
    int unk0cd0;
    int unk0cd4;
    int unk0cd8;
    int unk0cdc;
    int unk0ce0;
    int unk0ce4;
    int unk0ce8;
    int unk0cec;
    int unk0cf0;
    int unk0cf4;
    int unk0cf8;
    int unk0cfc;
    int unk0d00;
    int unk0d04;
    int unk0d08;
    int unk0d0c;
    int unk0d10;
    int unk0d14;
    int unk0d18;
    int unk0d1c;
    int unk0d20;
    int unk0d24;
    int unk0d28;
    int unk0d2c;
    int unk0d30;
    int unk0d34;
    int unk0d38;
    int unk0d3c;
    int unk0d40;
    int unk0d44;
    int unk0d48;
    int unk0d4c;
    int unk0d50;
    int unk0d54;
    int unk0d58;
    int unk0d5c;
    int unk0d60;
    int unk0d64;
    int unk0d68;
    int unk0d6c;
    int unk0d70;
    int unk0d74;
    int unk0d78;
    int unk0d7c;
    int unk0d80;
    int unk0d84;
    int unk0d88;
    int unk0d8c;
    int unk0d90;
    int unk0d94;
    int unk0d98;
    int unk0d9c;
    int unk0da0;
    int unk0da4;
    int unk0da8;
    int unk0dac;
    int unk0db0;
    int unk0db4;
    int unk0db8;
    int unk0dbc;
    int unk0dc0;
    int unk0dc4;
    int unk0dc8;
    int unk0dcc;
    int unk0dd0;
    int unk0dd4;
    int unk0dd8;
    int unk0ddc;
    int unk0de0;
    int unk0de4;
    int unk0de8;
    int unk0dec;
    int unk0df0;
    int unk0df4;
    int unk0df8;
    int unk0dfc;
    int unk0e00;
    int unk0e04;
    int unk0e08;
    int unk0e0c;
    int unk0e10;
    int unk0e14;
    int unk0e18;
    int unk0e1c;
    int unk0e20;
    int unk0e24;
    int unk0e28;
    int unk0e2c;
    int unk0e30;
    int unk0e34;
    int unk0e38;
    int unk0e3c;
    int unk0e40;
    int unk0e44;
    int unk0e48;
    int unk0e4c;
    int unk0e50;
    int unk0e54;
    int unk0e58;
    int unk0e5c;
    int unk0e60;
    int unk0e64;
    int unk0e68;
    int unk0e6c;
    int unk0e70;
    int unk0e74;
    int unk0e78;
    int unk0e7c;
    int unk0e80;
    int unk0e84;
    int unk0e88;
    int unk0e8c;
    int unk0e90;
    int unk0e94;
    int unk0e98;
    int unk0e9c;
    int unk0ea0;
    int unk0ea4;
    int unk0ea8;
    int unk0eac;
    int unk0eb0;
    int unk0eb4;
    int unk0eb8;
    int unk0ebc;
    int unk0ec0;
    int unk0ec4;
    int unk0ec8;
    int unk0ecc;
    int unk0ed0;
    int unk0ed4;
    int unk0ed8;
    int unk0edc;
    int unk0ee0;
    int unk0ee4;
    int unk0ee8;
    int unk0eec;
    int unk0ef0;
    int unk0ef4;
    int unk0ef8;
    int unk0efc;
    int unk0f00;
    int unk0f04;
    int unk0f08;
    int unk0f0c;
    int unk0f10;
    int unk0f14;
    int unk0f18;
    int unk0f1c;
    int unk0f20;
    int unk0f24;
    int unk0f28;
    int unk0f2c;
    int unk0f30;
    int unk0f34;
    int unk0f38;
    int unk0f3c;
    int unk0f40;
    int unk0f44;
    int unk0f48;
    int unk0f4c;
    int unk0f50;
    int unk0f54;
    int unk0f58;
    int unk0f5c;
    int unk0f60;
    int unk0f64;
    int unk0f68;
    int unk0f6c;
    int unk0f70;
    int unk0f74;
    int unk0f78;
    int unk0f7c;
    int unk0f80;
    int unk0f84;
    int unk0f88;
    int unk0f8c;
    int unk0f90;
    int unk0f94;
    int unk0f98;
    int unk0f9c;
    int unk0fa0;
    int unk0fa4;
    int unk0fa8;
    int unk0fac;
    int unk0fb0;
    int unk0fb4;
    int unk0fb8;
    int unk0fbc;
    int unk0fc0;
    int unk0fc4;
    int unk0fc8;
    int unk0fcc;
    int unk0fd0;
    int unk0fd4;
    int unk0fd8;
    int unk0fdc;
    int unk0fe0;
    int unk0fe4;
    int unk0fe8;
    int unk0fec;
    int unk0ff0;
    int unk0ff4;
    int unk0ff8;
    int unk0ffc;
    int unk1000;
    int unk1004;
    int unk1008;
    int unk100c;
    int unk1010;
    int unk1014;
    int unk1018;
    int unk101c;
    int unk1020;
    int unk1024;
    int unk1028;
    int unk102c;
    int unk1030;
    int unk1034;
    int unk1038;
    int unk103c;
    int unk1040;
    int unk1044;
    int unk1048;
    int unk104c;
    int unk1050;
    int unk1054;
    int unk1058;
    int unk105c;
    int unk1060;
    int unk1064;
    int unk1068;
    int unk106c;
    int unk1070;
    int unk1074;
    int unk1078;
    int unk107c;
    int unk1080;
    int unk1084;
    int unk1088;
    int unk108c;
    int unk1090;
    int unk1094;
    int unk1098;
    int unk109c;
    int unk10a0;
    int unk10a4;
    int unk10a8;
    int unk10ac;
    int unk10b0;
    int unk10b4;
    int unk10b8;
    int unk10bc;
    int unk10c0;
    int unk10c4;
    int unk10c8;
    int unk10cc;
    int unk10d0;
    int unk10d4;
    int unk10d8;
    int unk10dc;
    int unk10e0;
    int unk10e4;
    int unk10e8;
    int unk10ec;
    int unk10f0;
    int unk10f4;
    int unk10f8;
    int unk10fc;
    int unk1100;
    int unk1104;
    int unk1108;
    int unk110c;
    int unk1110;
    int unk1114;
    int unk1118;
    int unk111c;
    int unk1120;
    int unk1124;
    int unk1128;
    int unk112c;
    int unk1130;
    int unk1134;
    int unk1138;
    int unk113c;
    int unk1140;
    int unk1144;
    int unk1148;
    int unk114c;
    int unk1150;
    int unk1154;
    int unk1158;
    int unk115c;
    int unk1160;
    int unk1164;
    int unk1168;
    int unk116c;
    int unk1170;
    int unk1174;
    int unk1178;
    int unk117c;
    int unk1180;
    int unk1184;
    int unk1188;
    int unk118c;
    int unk1190;
    int unk1194;
    int unk1198;
    int unk119c;
    int unk11a0;
    int unk11a4;
    int unk11a8;
    int unk11ac;
    int unk11b0;
    int unk11b4;
    int unk11b8;
    int unk11bc;
    int unk11c0;
    int unk11c4;
    int unk11c8;
    int unk11cc;
    int unk11d0;
    int unk11d4;
    int unk11d8;
    int unk11dc;
    int unk11e0;
    int unk11e4;
    int unk11e8;
    int unk11ec;
    int unk11f0;
    int unk11f4;
    int unk11f8;
    int unk11fc;
    int unk1200;
    int unk1204;
    int unk1208;
    int unk120c;
    int unk1210;
    int unk1214;
    int unk1218;
    int unk121c;
    int unk1220;
    int unk1224;
    int unk1228;
    int unk122c;
    int unk1230;
    int unk1234;
    int unk1238;
    int unk123c;
    int unk1240;
    int unk1244;
    int unk1248;
    int unk124c;
    int unk1250;
    int unk1254;
    int unk1258;
    int unk125c;
    int unk1260;
    int unk1264;
    int unk1268;
    int unk126c;
    int unk1270;
    int unk1274;
    int unk1278;
    int unk127c;
    int unk1280;
    int unk1284;
    int unk1288;
    int unk128c;
    int unk1290;
    int unk1294;
    int unk1298;
    int unk129c;
    int unk12a0;
    int unk12a4;
    int unk12a8;
    int unk12ac;
    int unk12b0;
    int unk12b4;
    int unk12b8;
    int unk12bc;
    int unk12c0;
    int unk12c4;
    int unk12c8;
    int unk12cc;
    int unk12d0;
    int unk12d4;
    int unk12d8;
    int unk12dc;
    int unk12e0;
    int unk12e4;
    int unk12e8;
    int unk12ec;
    int unk12f0;
    int unk12f4;
    int unk12f8;
    int unk12fc;
    int unk1300;
    int unk1304;
    int unk1308;
    int unk130c;
    int unk1310;
    int unk1314;
    int unk1318;
    int unk131c;
    int unk1320;
    int unk1324;
    int unk1328;
    int unk132c;
    int unk1330;
    int unk1334;
    int unk1338;
    int unk133c;
    int unk1340;
    int unk1344;
    int unk1348;
    int unk134c;
    int unk1350;
    int unk1354;
    int unk1358;
    int unk135c;
    int unk1360;
    int unk1364;
    int unk1368;
    int unk136c;
    int unk1370;
    int unk1374;
    int unk1378;
    int unk137c;
    int unk1380;
    int unk1384;
    int unk1388;
    int unk138c;
    int unk1390;
    int unk1394;
    int unk1398;
    int unk139c;
    int unk13a0;
    int unk13a4;
    int unk13a8;
    int unk13ac;
    int unk13b0;
    int unk13b4;
    int unk13b8;
    int unk13bc;
    int unk13c0;
    int unk13c4;
    int unk13c8;
    int unk13cc;
    int unk13d0;
    int unk13d4;
    int unk13d8;
    int unk13dc;
    int unk13e0;
    int unk13e4;
    int unk13e8;
    int unk13ec;
    int unk13f0;
    int unk13f4;
    int unk13f8;
    int unk13fc;
    int unk1400;
    int unk1404;
    int unk1408;
    int unk140c;
    int unk1410;
    int unk1414;
    int unk1418;
    int unk141c;
    int unk1420;
    int unk1424;
    int unk1428;
    int unk142c;
    int unk1430;
    int unk1434;
    int unk1438;
    int unk143c;
    int unk1440;
    int unk1444;
    int unk1448;
    int unk144c;
    int unk1450;
    int unk1454;
    int unk1458;
    int unk145c;
    int unk1460;
    int unk1464;
    int unk1468;
    int unk146c;
    int unk1470;
    int unk1474;
    int unk1478;
    int unk147c;
    int unk1480;
    int unk1484;
    int unk1488;
    int unk148c;
    int unk1490;
    int unk1494;
    int unk1498;
    int unk149c;
    int unk14a0;
    int unk14a4;
    int unk14a8;
    int unk14ac;
    int unk14b0;
    int unk14b4;
    int unk14b8;
    int unk14bc;
    int unk14c0;
    int unk14c4;
    int unk14c8;
    int unk14cc;
    int unk14d0;
    int unk14d4;
    int unk14d8;
    int unk14dc;
    int unk14e0;
    int unk14e4;
    int unk14e8;
    int unk14ec;
    int unk14f0;
    int unk14f4;
    int unk14f8;
    int unk14fc;
    int unk1500;
    int unk1504;
    int unk1508;
    int unk150c;
    int unk1510;
    int unk1514;
    int unk1518;
    int unk151c;
    int unk1520;
    int unk1524;
    int unk1528;
    int unk152c;
    int unk1530;
    int unk1534;
    int unk1538;
    int unk153c;
    int unk1540;
    int unk1544;
    int unk1548;
    int unk154c;
    int unk1550;
    int unk1554;
    int unk1558;
    int unk155c;
    int unk1560;
    int unk1564;
    int unk1568;
    int unk156c;
    int unk1570;
    int unk1574;
    int unk1578;
    int unk157c;
    int unk1580;
    int unk1584;
    int unk1588;
    int unk158c;
    int unk1590;
    int unk1594;
    int unk1598;
    int unk159c;
    int unk15a0;
    int unk15a4;
    int unk15a8;
    int unk15ac;
    int unk15b0;
    int unk15b4;
    int unk15b8;
    int unk15bc;
    int unk15c0;
    int unk15c4;
    int unk15c8;
    int unk15cc;
    int unk15d0;
    int unk15d4;
    int unk15d8;
    int unk15dc;
    int unk15e0;
    int unk15e4;
    int unk15e8;
    int unk15ec;
    int unk15f0;
    int unk15f4;
    int unk15f8;
    int unk15fc;
    int unk1600;
    int unk1604;
    int unk1608;
    int unk160c;
    int unk1610;
    int unk1614;
    int unk1618;
    int unk161c;
    int unk1620;
    int unk1624;
    int unk1628;
    int unk162c;
    int unk1630;
    int unk1634;
    int unk1638;
    int unk163c;
    int unk1640;
    int unk1644;
    int unk1648;
    int unk164c;
    int unk1650;
    int unk1654;
    int unk1658;
    int unk165c;
    int unk1660;
    int unk1664;
    int unk1668;
    int unk166c;
    int unk1670;
    int unk1674;
    int unk1678;
    int unk167c;
    int unk1680;
    int unk1684;
    int unk1688;
    int unk168c;
    int unk1690;
    int unk1694;
    int unk1698;
    int unk169c;
    int unk16a0;
    int unk16a4;
    int unk16a8;
    int unk16ac;
    int unk16b0;
    int unk16b4;
    int unk16b8;
    int unk16bc;
    int unk16c0;
    int unk16c4;
    int unk16c8;
    int unk16cc;
    int unk16d0;
    int unk16d4;
    int unk16d8;
    int unk16dc;
    int unk16e0;
    int unk16e4;
    int unk16e8;
    int unk16ec;
    int unk16f0;
    int unk16f4;
    int unk16f8;
    int unk16fc;
    int unk1700;
    int unk1704;
    int unk1708;
    int unk170c;
    int unk1710;
    int unk1714;
    int unk1718;
    int unk171c;
    int unk1720;
    int unk1724;
    int unk1728;
    int unk172c;
    int unk1730;
    int unk1734;
    int unk1738;
    int unk173c;
    int unk1740;
    int unk1744;
    int unk1748;
    int unk174c;
    int unk1750;
    int unk1754;
    int unk1758;
    int unk175c;
    int unk1760;
    int unk1764;
    int unk1768;
    int unk176c;
    int unk1770;
    int unk1774;
    int unk1778;
    int unk177c;
    int unk1780;
    int unk1784;
    int unk1788;
    int unk178c;
    int unk1790;
    int unk1794;
    int unk1798;
    int unk179c;
    int unk17a0;
    int unk17a4;
    int unk17a8;
    int unk17ac;
    int unk17b0;
    int unk17b4;
    int unk17b8;
    int unk17bc;
    int unk17c0;
    int unk17c4;
    int unk17c8;
    int unk17cc;
    int unk17d0;
    int unk17d4;
    int unk17d8;
    int unk17dc;
    int unk17e0;
    int unk17e4;
    int unk17e8;
    int unk17ec;
    int unk17f0;
    int unk17f4;
    int unk17f8;
    int unk17fc;
    int unk1800;
    int unk1804;
    int unk1808;
    int unk180c;
    int unk1810;
    int unk1814;
    int unk1818;
    int unk181c;
    int unk1820;
    int unk1824;
    int unk1828;
    int unk182c;
    int unk1830;
    int unk1834;
    int unk1838;
    int unk183c;
    int unk1840;
    int unk1844;
    int unk1848;
    int unk184c;
    int unk1850;
    int unk1854;
    int unk1858;
    int unk185c;
    int unk1860;
    int unk1864;
    int unk1868;
    int unk186c;
    int unk1870;
    int unk1874;
    int unk1878;
    int unk187c;
    int unk1880;
    int unk1884;
    int unk1888;
    int unk188c;
    int unk1890;
    int unk1894;
    int unk1898;
    int unk189c;
    int unk18a0;
    int unk18a4;
    int unk18a8;
    int unk18ac;
    int unk18b0;
    int unk18b4;
    int unk18b8;
    int unk18bc;
    int unk18c0;
    int unk18c4;
    int unk18c8;
    int unk18cc;
    int unk18d0;
    int unk18d4;
    int unk18d8;
    int unk18dc;
    int unk18e0;
    int unk18e4;
    int unk18e8;
    int unk18ec;
    int unk18f0;
    int unk18f4;
    int unk18f8;
    int unk18fc;
    int unk1900;
    int unk1904;
    int unk1908;
    int unk190c;
    int unk1910;
    int unk1914;
    int unk1918;
    int unk191c;
    int unk1920;
    int unk1924;
    int unk1928;
    int unk192c;
    int unk1930;
    int unk1934;
    int unk1938;
    int unk193c;
    int unk1940;
    int unk1944;
    int unk1948;
    int unk194c;
    int unk1950;
    int unk1954;
    int unk1958;
    int unk195c;
    int unk1960;
    int unk1964;
    int unk1968;
    int unk196c;
    int unk1970;
    int unk1974;
    int unk1978;
    int unk197c;
    int unk1980;
    int unk1984;
    int unk1988;
    int unk198c;
    int unk1990;
    int unk1994;
    int unk1998;
    int unk199c;
    int unk19a0;
    int unk19a4;
    int unk19a8;
    int unk19ac;
    int unk19b0;
    int unk19b4;
    int unk19b8;
    int unk19bc;
    int unk19c0;
    int unk19c4;
    int unk19c8;
    int unk19cc;
    int unk19d0;
    int unk19d4;
    int unk19d8;
    int unk19dc;
    int unk19e0;
    int unk19e4;
    int unk19e8;
    int unk19ec;
    int unk19f0;
    int unk19f4;
    int unk19f8;
    int unk19fc;
    int unk1a00;
    int unk1a04;
    int unk1a08;
    int unk1a0c;
    int unk1a10;
    int unk1a14;
    int unk1a18;
    int unk1a1c;
    int unk1a20;
    int unk1a24;
    int unk1a28;
    int unk1a2c;
    int unk1a30;
    int unk1a34;
    int unk1a38;
    int unk1a3c;
    int unk1a40;
    int unk1a44;
    int unk1a48;
    int unk1a4c;
    int unk1a50;
    int unk1a54;
    int unk1a58;
    int unk1a5c;
    int unk1a60;
    int unk1a64;
    int unk1a68;
    int unk1a6c;
    int unk1a70;
    int unk1a74;
    int unk1a78;
    int unk1a7c;
    int unk1a80;
    int unk1a84;
    int unk1a88;
    int unk1a8c;
    int unk1a90;
    int unk1a94;
    int unk1a98;
    int unk1a9c;
    int unk1aa0;
    int unk1aa4;
    int unk1aa8;
    int unk1aac;
    int unk1ab0;
    int unk1ab4;
    int unk1ab8;
    int unk1abc;
    int unk1ac0;
    int unk1ac4;
    int unk1ac8;
    int unk1acc;
    int unk1ad0;
    int unk1ad4;
    int unk1ad8;
    int unk1adc;
    int unk1ae0;
    int unk1ae4;
    int unk1ae8;
    int unk1aec;
    int unk1af0;
    int unk1af4;
    int unk1af8;
    int unk1afc;
    int unk1b00;
    int unk1b04;
    int unk1b08;
    int unk1b0c;
    int unk1b10;
    int unk1b14;
    int unk1b18;
    int unk1b1c;
    int unk1b20;
    int unk1b24;
    int unk1b28;
    int unk1b2c;
    int unk1b30;
    int unk1b34;
    int unk1b38;
    int unk1b3c;
    int unk1b40;
    int unk1b44;
    int unk1b48;
    int unk1b4c;
    int unk1b50;
    int unk1b54;
    int unk1b58;
    int unk1b5c;
    int unk1b60;
    int unk1b64;
    int unk1b68;
    int unk1b6c;
    int unk1b70;
    int unk1b74;
    int unk1b78;
    int unk1b7c;
    int unk1b80;
    int unk1b84;
    int unk1b88;
    int unk1b8c;
    int unk1b90;
    int unk1b94;
    int unk1b98;
    int unk1b9c;
    int unk1ba0;
    int unk1ba4;
    int unk1ba8;
    int unk1bac;
    int unk1bb0;
    int unk1bb4;
    int unk1bb8;
    int unk1bbc;
    int unk1bc0;
    int unk1bc4;
    int unk1bc8;
    int unk1bcc;
    int unk1bd0;
    int unk1bd4;
    int unk1bd8;
    int unk1bdc;
    int unk1be0;
    int unk1be4;
    int unk1be8;
    int unk1bec;
    int unk1bf0;
    int unk1bf4;
    int unk1bf8;
    int unk1bfc;
    int unk1c00;
    int unk1c04;
    int unk1c08;
    int unk1c0c;
    int unk1c10;
    int unk1c14;
    int unk1c18;
    int unk1c1c;
    int unk1c20;
    int unk1c24;
    int unk1c28;
    int unk1c2c;
    int unk1c30;
    int unk1c34;
    int unk1c38;
    int unk1c3c;
    int unk1c40;
    int unk1c44;
    int unk1c48;
    int unk1c4c;
    int unk1c50;
    int unk1c54;
    int unk1c58;
    int unk1c5c;
    int unk1c60;
    int unk1c64;
    int unk1c68;
    int unk1c6c;
    int unk1c70;
    int unk1c74;
    int unk1c78;
    int unk1c7c;
    int unk1c80;
    int unk1c84;
    int unk1c88;
    int unk1c8c;
    int unk1c90;
    int unk1c94;
    int unk1c98;
    int unk1c9c;
    int unk1ca0;
    int unk1ca4;
    int unk1ca8;
    int unk1cac;
    int unk1cb0;
    int unk1cb4;
    int unk1cb8;
    int unk1cbc;
    int unk1cc0;
    int unk1cc4;
    int unk1cc8;
    int unk1ccc;
    int unk1cd0;
    int unk1cd4;
    int unk1cd8;
    int unk1cdc;
    int unk1ce0;
    int unk1ce4;
    int unk1ce8;
    int unk1cec;
    int unk1cf0;
    int unk1cf4;
    int unk1cf8;
    int unk1cfc;
    int unk1d00;
    int unk1d04;
    int unk1d08;
    int unk1d0c;
    int unk1d10;
    int unk1d14;
    int unk1d18;
    int unk1d1c;
    int unk1d20;
    int unk1d24;
    int unk1d28;
    int unk1d2c;
    int unk1d30;
    int unk1d34;
    int unk1d38;
    int unk1d3c;
    int unk1d40;
    int unk1d44;
    int unk1d48;
    int unk1d4c;
    int unk1d50;
    int unk1d54;
    int unk1d58;
    int unk1d5c;
    int unk1d60;
    int unk1d64;
    int unk1d68;
    int unk1d6c;
    int unk1d70;
    int unk1d74;
    int unk1d78;
    int unk1d7c;
    int unk1d80;
    int unk1d84;
    int unk1d88;
    int unk1d8c;
    int unk1d90;
    int unk1d94;
    int unk1d98;
    int unk1d9c;
    int unk1da0;
    int unk1da4;
    int unk1da8;
    int unk1dac;
    int unk1db0;
    int unk1db4;
    int unk1db8;
    int unk1dbc;
    int unk1dc0;
    int unk1dc4;
    int unk1dc8;
    int unk1dcc;
    int unk1dd0;
    int unk1dd4;
    int unk1dd8;
    int unk1ddc;
    int unk1de0;
    int unk1de4;
    int unk1de8;
    int unk1dec;
    int unk1df0;
    int unk1df4;
    int unk1df8;
    int unk1dfc;
    int unk1e00;
    int unk1e04;
    int unk1e08;
    int unk1e0c;
    int unk1e10;
    int unk1e14;
    int unk1e18;
    int unk1e1c;
    int unk1e20;
    int unk1e24;
    int unk1e28;
    int unk1e2c;
    int unk1e30;
    int unk1e34;
    int unk1e38;
    int unk1e3c;
    int unk1e40;
    int unk1e44;
    int unk1e48;
    int unk1e4c;
    int unk1e50;
    int unk1e54;
    int unk1e58;
    int unk1e5c;
    int unk1e60;
    int unk1e64;
    int unk1e68;
    int unk1e6c;
    int unk1e70;
    int unk1e74;
    int unk1e78;
    int unk1e7c;
    int unk1e80;
    int unk1e84;
    int unk1e88;
    int unk1e8c;
    int unk1e90;
    int unk1e94;
    int unk1e98;
    int unk1e9c;
    int unk1ea0;
    int unk1ea4;
    int unk1ea8;
    int unk1eac;
    int unk1eb0;
    int unk1eb4;
    int unk1eb8;
    int unk1ebc;
    int unk1ec0;
    int unk1ec4;
    int unk1ec8;
    int unk1ecc;
    int unk1ed0;
    int unk1ed4;
    int unk1ed8;
    int unk1edc;
    int unk1ee0;
    int unk1ee4;
    int unk1ee8;
    int unk1eec;
    int unk1ef0;
    int unk1ef4;
    int unk1ef8;
    int unk1efc;
    int unk1f00;
    int unk1f04;
    int unk1f08;
    int unk1f0c;
    int unk1f10;
    int unk1f14;
    int unk1f18;
    int unk1f1c;
    int unk1f20;
    int unk1f24;
    int unk1f28;
    int unk1f2c;
    int unk1f30;
    int unk1f34;
    int unk1f38;
    int unk1f3c;
    int unk1f40;
    int unk1f44;
    int unk1f48;
    int unk1f4c;
    int unk1f50;
    int unk1f54;
    int unk1f58;
    int unk1f5c;
    int unk1f60;
    int unk1f64;
    int unk1f68;
    int unk1f6c;
    int unk1f70;
    int unk1f74;
    int unk1f78;
    int unk1f7c;
    int unk1f80;
    int unk1f84;
    int unk1f88;
    int unk1f8c;
    int unk1f90;
    int unk1f94;
    int unk1f98;
    int unk1f9c;
    int unk1fa0;
    int unk1fa4;
    int unk1fa8;
    int unk1fac;
    int unk1fb0;
    int unk1fb4;
    int unk1fb8;
    int unk1fbc;
    int unk1fc0;
    int unk1fc4;
    int unk1fc8;
    int unk1fcc;
    int unk1fd0;
    int unk1fd4;
    int unk1fd8;
    int unk1fdc;
    int unk1fe0;
    int unk1fe4;
    int unk1fe8;
    int unk1fec;
    int unk1ff0;
    int unk1ff4;
    int unk1ff8;
    int unk1ffc;
    int unk2000;
    int unk2004;
    int unk2008;
    int unk200c;
    int unk2010;
    int unk2014;
    int unk2018;
    int unk201c;
    int unk2020;
    int unk2024;
    int unk2028;
    int unk202c;
    int unk2030;
    int unk2034;
    int unk2038;
    int unk203c;
    int unk2040;
    int unk2044;
    int unk2048;
    int unk204c;
    int unk2050;
    int unk2054;
    ArrObj m_2058;
    ArrObj m_2068;
    Node* m_2078;
    Node* m_207c;
    int m_2080;
    int m_2084;
    Obj2088 m_2088;
    Obj2088 m_20b0;
    Obj20d8 m_20d8;
    ArrE m_20e8;
    void BuildGroups(void* a, void* p);
    void* FUN_0069f900(Node* n, int a, void* hdr, float f);
    void InsertNode(void* p);
    bool ProcessSearchNode(Obj20d8* a, ArrE* b, int flags);
    bool FUN_0069f010(Vec3Obj* a0, Vec3Obj* a1, void* a2, int a3, A4Obj* a4);
};

// Sets up start and end nodes from a0 and a1, runs ProcessSearchNode, passes each result entry's strings to a4->FUN_0069f920, and returns the search result.
// @fnv 0x0069f010
bool ThisCls::FUN_0069f010(Vec3Obj* apStart, Vec3Obj* apEnd, void* a2, int a3, A4Obj* apResult)
{
    HdrS raw2;
    {
        bool ok;
        m_2080 = a3;
        m_2084 = (int)apResult;
        if (DAT_011d6dcc)
        {
            if (DAT_011d6ddc.FUN_0052aa80(0))
            {
                ((GRes2*)GetPathManager(&DAT_011d6ddc, 0))->ForwardToHost();
            }
            DAT_011d6ddc.FUN_0066b0d0(new ObjX(0));
        }
        BuildGroups(a2, &m_2068);
        if (DAT_011d6dcc)
        {
            unsigned int i;
            for (i = 0; i < m_2068.FUN_0044ddc0(); i++)
            {
                unsigned int j;
                for (j = 0; j < ((ArrObj*)m_2068.FUN_00558dd0(i))->FUN_0044ddc0(); j++)
                {
                    AuxObj* auxPtr;
                    ObjA objA(0.0f, (float)(1.0 - (double)i / (double)m_2068.FUN_0044ddc0()),
                              (float)((double)i / (double)m_2068.FUN_0044ddc0()), DAT_01030ff4);
                    {
                        ObjB objB2(
                            FUN_00c56680(*(float*)((char*)*(((ArrObj*)m_2068.FUN_00558dd0(i))->FUN_00877a30(j)) + 0x10),
                                         10, 10, &objA));
                        objB2.FUN_00559450()->FUN_00440460(
                            (char*)*(((ArrObj*)m_2068.FUN_00558dd0(i))->FUN_00877a30(j)) + 4);
                        auxPtr = (AuxObj*)new ObjY();
                        auxPtr->FUN_0049ed90(1);
                        objB2.FUN_00559450()->FUN_00439410(auxPtr);
                        AttachLightingPropertyRecursive(objB2.FUN_00559450());
                        FUN_00b57e30(objB2.FUN_00559450(), 0, 0);
                        objB2.FUN_00559450()->FUN_00a5a040();
                        VecObj vobjL(0.0f, 0, 0);
                        objB2.FUN_00559450()->FUN_00a59c60(&vobjL);
                        DAT_011d6ddc.FUN_00559450()->vtarget(objB2.FUN_00559450(), 1);
                    }
                }
            }
        }
        m_2088.FUN_006dcce0(apStart);
        m_20b0.FUN_006dcce0(apEnd);
        m_2088.FUN_006dd6f0(0);
        if (!m_2088.FUN_006dd6a0())
            return false;
        {
            m_2078 = new Node();
            m_2078->m_00 = 3;
            m_2078->m_v4 = apStart->FUN_005c3420();
            m_2078->m_10 = 0.0f;
            m_2078->m_34 = 0xffff;
            m_2068.GetFirst()->FUN_007cb2e0(&m_2078);
        }
        {
            m_207c = new Node();
            m_207c->m_00 = 4;
            m_207c->m_v4 = apEnd->FUN_005c3420();
            m_207c->m_10 = 0.0f;
            m_207c->m_34 = 0xffff;
            ((LinkT*)m_2068.FUN_00558dd0(m_2068.FUN_0044ddc0() - 2))->FUN_007cb2e0(&m_207c);
        }
        {
            raw2.p = m_2078;
            raw2.a = 0;
            raw2.b = 0;
            InsertNode(FUN_0069f900(m_2078, 0, &raw2,
                                    (float)(((Vec3Obj*)&m_20b0)
                                                ->FUN_005c3420()
                                                .FUN_00439ef0(((Vec3Obj*)&m_2088)->FUN_005c3420())
                                                .FUN_00457990() *
                                            DAT_0101de30)));
            ok = ProcessSearchNode(&m_20d8, &m_20e8, 1);
        }
        {
            unsigned int k;
            for (k = 0; k < m_20e8.FUN_0044ddc0(); k++)
            {
                StrObj str1((char*)m_20e8.GetBufferElementAddress(k) + 0x1c,
                            ((NavLike*)m_20e8.GetBufferElementAddress(k)->m_10)->FUN_0068efb0());
                apResult->FUN_0069f920(&str1, &DAT_011f426c);
                StrObj str2((char*)m_20e8.GetBufferElementAddress(k) + 0x34,
                            ((NavLike*)m_20e8.GetBufferElementAddress(k)->m_28)->FUN_0068efb0());
                apResult->FUN_0069f920(&str2, &DAT_011f426c);
            }
        }
        if (DAT_011d6dcc)
        {
            DAT_011d6ddc.FUN_00559450()->FUN_00a5a040();
            VecObj vobj(0.0f, 0, 0);
            DAT_011d6ddc.FUN_00559450()->FUN_00a59c60(&vobj);
            ((GRes2*)GetPathManager(&DAT_011d6ddc, 1))->ForwardToHost();
        }
        {
            unsigned int m;
            for (m = 0; m < m_2058.FUN_0044ddc0(); m++)
            {
                delete (DelObj*)*m_2058.FUN_00877a30(m);
            }
        }
        return ok;
    }
}
}  // namespace fnv_0069f010

struct ScalarDeleteOwner : FUN_00683740_class
{
    void* __thiscall FUN_00683780(unsigned int flags);
};

// Calls FUN_006837f0, deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x00683780
void* __thiscall ScalarDeleteOwner::FUN_00683780(unsigned int flags)
{
    FUN_006837f0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct SA00694f80 : DA00694f80
{
    void FUN_00694f80(DA00694f80*);
};

void SA00694f80::FUN_00694f80(DA00694f80*)
{}

BSSimpleArray<unsigned short, 1024>::BSSimpleArray()
{}

BSSimpleArray<unsigned short, 1024>::~BSSimpleArray()
{}

struct NavMeshGrid
{
    struct Block0C
    {
        int m_00;
        int m_04;
        int m_08;
    };

    struct Block18
    {
        int m_00;
        int m_04;
        int m_08;
    };

    int m_00;
    float m_04;
    float m_08;
    Block0C m_0c;
    Block18 m_18;
    BSSimpleArray<unsigned short, 1024>* m_24;

    void FUN_0069d2d0();
    void FUN_0069dd50(NavMeshGrid* apGrid) const;
};

void NavMeshGrid::FUN_0069d2d0()
{}

// Copies scalar and block fields from this NavMeshGrid into apGrid, allocates a matching BSSimpleArray, and copies each element via FUN_00694f80.
// @fnv 0x0069dd50
void NavMeshGrid::FUN_0069dd50(NavMeshGrid* apGrid) const
{
    apGrid->FUN_0069d2d0();

    apGrid->m_00 = m_00;
    apGrid->m_04 = m_04;
    apGrid->m_08 = m_08;
    apGrid->m_0c = m_0c;
    apGrid->m_18 = m_18;

    unsigned int itotal = apGrid->m_00 * apGrid->m_00;
    apGrid->m_24 = new BSSimpleArray<unsigned short, 1024>[itotal];

    for (unsigned int i = 0; i < itotal; ++i)
        reinterpret_cast<SA00694f80*>(&m_24[i])->FUN_00694f80(reinterpret_cast<DA00694f80*>(&apGrid->m_24[i]));
}

struct FunctionData;

bool __cdecl FUN_006822a0(FunctionData const* data, unsigned int index);

struct ScriptParamDataView
{
    unsigned short command;
    unsigned short flags;
    TESForm* parameters[2];
};

class TESForm
{
  public:
    virtual void v0();
};

class TESScriptableForm
{
  public:
    virtual void v0();
    Script* FUN_00726070();
};

class TESObjectREFR
{
  public:
    virtual void v0();
    TESForm* FUN_007af430();
};

Script* __cdecl FUN_004826d0(TESForm* formID);

// @fnv 0x006823d0
Script* FUN_006823d0(unsigned int index, FunctionData const* data)
{
    Script* result = 0;

    {
        TESForm* formID;

        if (FUN_006822a0(data, index))
        {
            formID = reinterpret_cast<const ScriptParamDataView*>(data)->parameters[index];

            TESScriptableForm* script = dynamic_cast<TESScriptableForm*>(formID);

            if (script)
            {
                result = script->FUN_00726070();
            }
            else
            {
                TESObjectREFR* object = dynamic_cast<TESObjectREFR*>(formID);

                if (object)
                {
                    formID = object->FUN_007af430();
                    result = FUN_004826d0(formID);
                }
            }
        }
    }

    return result;
}
