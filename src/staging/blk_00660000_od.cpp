
// src/staging/blk_00660000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

void __cdecl CopyConstructEntry(int a, int b);

struct FUN_006601f0_Class
{
    void __thiscall FUN_006601f0(int a, int b);
};

// @fnv 0x006601f0
void __thiscall FUN_006601f0_Class::FUN_006601f0(int aiArg1, int aiArg2)
{
    CopyConstructEntry(aiArg1, aiArg2);
}

extern "C" void __cdecl FUN_00660340(void*, void*, void*, void*);

// @fnv 0x00660210
void __cdecl FUN_00660210(void* a1, void* a2, void* a3, void* a4)
{
    FUN_00660340(a1, a2, a3, a4);
}

extern "C" void __cdecl FUN_006603a0(void* a, void* b, void* c, void* d);

// @fnv 0x00660230
void __cdecl FUN_00660230(void* apArg1, void* apArg2, void* apArg3, void* apArg4)
{
    FUN_006603a0(apArg1, apArg2, apArg3, apArg4);
}

extern "C" int __cdecl ConstructInPlace(int, int);

struct FUN_00660300_Class
{
    int __thiscall FUN_00660300(int a, int b);
};

// @fnv 0x00660300
int __thiscall FUN_00660300_Class::FUN_00660300(int aiArg1, int aiArg2)
{
    return ConstructInPlace(aiArg1, aiArg2);
}

extern "C" void __cdecl CopyConstructElement(int, int);

struct FUN_00660320_Class
{
    void __thiscall FUN_00660320(int a, int b);
};

// @fnv 0x00660320
void __thiscall FUN_00660320_Class::FUN_00660320(int aiFirst, int aiSecond)
{
    CopyConstructElement(aiFirst, aiSecond);
}

extern const char* const g_011d5ba8_arg1;

struct FUN_00661d30_cls
{
    const char* const* GetArg1Ptr();
};

// @fnv 0x00661d30
const char* const* FUN_00661d30_cls::GetArg1Ptr()
{
    return &g_011d5ba8_arg1;
}

extern "C" void* __cdecl FUN_00665f50(void*);
extern int DAT_01066434;

struct FUN_00665c50
{
    void* __thiscall FUN_00665f50(int a);
    void* __thiscall Set(int a);
};

// Calls FUN_00665f50 with a, stores the address of DAT_01066434 into this, and returns this.
// @fnv 0x00665c50
void* __thiscall FUN_00665c50::Set(int a)
{
    FUN_00665f50(a);
    *reinterpret_cast<void**>(this) = &DAT_01066434;
    return this;
}

struct FUN_00665f10_class
{
    int __thiscall Identity(int a);
};

// @fnv 0x00665f10
int __thiscall FUN_00665f10_class::Identity(int aiValue)
{
    return aiValue;
}

struct BGSSaveLoadChangesMap
{
    void Deallocate(void* p);
    void FUN_00666050(void* p);
};

// Clears the third word of the block and returns it to the allocator at offset 0xc.
// @fnv 0x00666050
void BGSSaveLoadChangesMap::FUN_00666050(void* apBlock)
{
    ((unsigned int*)apBlock)[2] = 0;
    ((NiTPointerAllocator<unsigned int>*)((char*)this + 0xc))->Deallocate(apBlock);
}

struct Setting_S
{
    float* Float();
};
extern Setting_S originalRuntimeFloatSetting1297;

// @fnv 0x0066b0b0
float FUN_0066b0b0()
{
    return *originalRuntimeFloatSetting1297.Float();
}

extern "C" void* __cdecl FUN_00664840(int);
struct Flt
{
    operator unsigned int();
};
// @fnv 0x0066b660
unsigned int __cdecl GetFltValueAtOffset16()
{
    return ((Flt*)((char*)FUN_00664840(1) + 0x10))->operator unsigned int();
}

struct FUN_0066dd80_Class
{
    bool IsFlag8Set() const;
};

// @fnv 0x0066dd80
bool FUN_0066dd80_Class::IsFlag8Set() const
{
    return (*(const unsigned int*)((const char*)this + 0x12c) & 8) ? true : false;
}

// Returns true when type is 7 or 8, false otherwise.
// @fnv 0x0066de80
bool FUN_0066de80(int type)
{
    switch (type)
    {
    case 7:
    case 8:
        return true;
    default:
        return false;
    }
}

extern int DAT_01068884;

struct FUN_0067ad20_Class
{
    int* vtbl;
    FUN_0067ad20_Class();
};

// @fnv 0x0067ad20
FUN_0067ad20_Class::FUN_0067ad20_Class()
{
    vtbl = &DAT_01068884;
}

extern int DAT_01068884;

struct FUN_0067ad70_Class
{
    void FUN_0067ad70();
};

// @fnv 0x0067ad70
void FUN_0067ad70_Class::FUN_0067ad70()
{
    *reinterpret_cast<int*>(this) = reinterpret_cast<int>(&DAT_01068884);
}

extern int DAT_01068aa4;

struct ActorPackageData
{
    ActorPackageData();
    ActorPackageData* FUN_0067d920();
};

ActorPackageData::ActorPackageData()
{}

// @fnv 0x0067d920
ActorPackageData* ActorPackageData::FUN_0067d920()
{
    *(int**)this = &DAT_01068aa4;
    return this;
}

extern "C" int DAT_01068aa4;

struct FUN_0067d970_Class
{
    int m;
    void __thiscall FUN_0067d970();
};

// @fnv 0x0067d970
void __thiscall FUN_0067d970_Class::FUN_0067d970()
{
    m = (int)&DAT_01068aa4;
}

struct FUN_0067f4b0_class
{
    unsigned char b;
    int a;
    int c;
    void FUN_0067f4b0(int d);
};

// @fnv 0x0067f4b0
void FUN_0067f4b0_class::FUN_0067f4b0(int aiValue)
{
    b = 5;
    c = aiValue;
}

struct FUN_00666020
{
    void* vtbl;
    int a;
    void* b;
    void RemoveAll();
    void Init();
};
extern "C" void _NiFreeAlias(void*);
// @fnv 0x00666020
void FUN_00666020::Init()
{
    *(const char**)this = "pbf";
    RemoveAll();
    _NiFreeAlias(b);
}

struct S6
{
    short a;
    short b;
    short c;
};
// Copies each S6 element from the range [a1, a2) into consecutive elements starting at a3, returning the advanced destination pointer.
// @fnv 0x00660030
S6* __cdecl CopyTripleShorts(S6* apBegin, S6* apEnd, S6* apDest)
{
    for (; apBegin != apEnd; ++apDest, ++apBegin)
        *apDest = *apBegin;
    return apDest;
}

struct FUN_00661d40_shell
{
    void __thiscall SetVTableAndDestroy();
    void* __thiscall FUN_00661d60(unsigned int);
};
void __cdecl _delete(void*, unsigned int);
// @fnv 0x00661d60
void* __thiscall FUN_00661d40_shell::FUN_00661d60(unsigned int flags)
{
    this->SetVTableAndDestroy();
    if (flags & 1)
        _delete(this, 8);
    return this;
}

extern const char* DAT_0119b49c[];
// @fnv 0x00661da0
const char* FUN_00661da0(int i)
{
    return DAT_0119b49c[i];
}

struct StatisticalArray
{
    int _pad[3];
    int m_base;
    unsigned int __thiscall FUN_0065cc30();
    int __thiscall FUN_00662890(unsigned int);
};
unsigned int __cdecl FUN_00ec7c56();
// Bounds-checks index a against the array count, then returns m_base plus a times 0x38.
// @fnv 0x00662890
int __thiscall StatisticalArray::FUN_00662890(unsigned int uiIndex)
{
    if (uiIndex >= FUN_0065cc30())
        FUN_00ec7c56();
    do
    {
    } while (0);
    return uiIndex * 0x38 + m_base;
}

void __cdecl Deallocate(void* p);

struct FUN_00665c80_Class
{
    void __thiscall FUN_00665fc0();
    void* __thiscall FUN_00665c80(unsigned int flags);
};

// Calls FUN_00665fc0, then frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00665c80
void* __thiscall FUN_00665c80_Class::FUN_00665c80(unsigned int flags)
{
    FUN_00665fc0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct Inner0080
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual int Func(int a, int b);
};
struct FUN_00665f20_Holder
{
    Inner0080* p;
    void __thiscall AdvanceState(int a);
    void __thiscall CallInnerFuncAndForward(int a);
};
// Calls the inner object's Func with a twice, then passes the result to AdvanceState.
// @fnv 0x00665f20
void __thiscall FUN_00665f20_Holder::CallInnerFuncAndForward(int a)
{
    AdvanceState(p->Func(a, a));
}

void* __cdecl _NiMalloc(unsigned int);
void* __cdecl memset(void* dest, int value, unsigned int count);
extern int $SG6086;
struct FUN_00665f50_Class
{
    int* vtbl;
    int count;
    int* data;
    int zero;
    void* __thiscall FUN_00665f50(int a);
};
// @fnv 0x00665f50
void* __thiscall FUN_00665f50_Class::FUN_00665f50(int aiCount)
{
    vtbl = &$SG6086;
    count = aiCount;
    zero = 0;
    unsigned int size = count * 4;
    data = (int*)_NiMalloc(size);
    memset(data, 0, count * 4);
    return this;
}

struct FUN_006661b0_Class
{
    void __thiscall FUN_006661e0();
    void* __thiscall FUN_006661b0(unsigned int flags);
};

// @fnv 0x006661b0
void* __thiscall FUN_006661b0_Class::FUN_006661b0(unsigned int flags)
{
    FUN_006661e0();
    if (flags & 1)
        operator delete(this);
    return this;
}

void __cdecl _Deallocate(void*);
struct FUN_00666270_Holder
{
    void* __thiscall InitAndMaybeDeallocate(unsigned int);
};
// Calls Init on this object, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x00666270
void* __thiscall FUN_00666270_Holder::InitAndMaybeDeallocate(unsigned int flags)
{
    ((FUN_00666020*)this)->Init();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void __cdecl FUN_006665c0();
void __cdecl Deallocate(void*);
struct FUN_00666570_Class
{
    void __thiscall FUN_006665c0();
    void* __thiscall FUN_00666570(unsigned int flags);
};
// Calls FUN_006665c0, then frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00666570
void* __thiscall FUN_00666570_Class::FUN_00666570(unsigned int flags)
{
    FUN_006665c0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct T_
{
    void FUN_004a3f10(void*);
};
struct bhkCharacterController
{
    float& GetVectorElement(int);
};
struct FUN_0066c9c0_Class
{
    T_ a;
    T_ b;
    void FUN_0066c9c0(T_& x, T_& y, float f);
};
// @fnv 0x0066c9c0
void FUN_0066c9c0_Class::FUN_0066c9c0(T_& x, T_& y, float afValue)
{
    a.FUN_004a3f10(&x);
    ((T_*)((char*)&a) + 16)->FUN_004a3f10(&y);
    ((bhkCharacterController*)((char*)&a) + 16)->GetVectorElement(3) = afValue;
}

struct Date
{
    ~Date();
};
struct FUN_0066da50 : Date
{
    ~FUN_0066da50();
    void FUN_0066dab0();
};
// @fnv 0x0066da50
FUN_0066da50::~FUN_0066da50()
{
    FUN_0066dab0();
}

struct H_A100
{
    void* GetSizeMasked();
};
struct H_6db70
{
    void FUN_0066db70(void* a, void* b);
};
struct FUN_0066dae0_Class
{
    void* p;
    unsigned int pad;
    unsigned int state;
    void __thiscall DestroyRange();
    void __thiscall FUN_0066dae0(void* a);
};
// @fnv 0x0066dae0
void __thiscall FUN_0066dae0_Class::FUN_0066dae0(void* pTarget)
{
    DestroyRange();
    if (!(state & 0x80000000))
        ((H_6db70*)pTarget)->FUN_0066db70(p, ((H_A100*)this)->GetSizeMasked());
    p = 0;
    state = 0x80000000;
}

namespace fnv_0066db30 {
struct T_
{
    void FUN_004a3f10(void* a);
};
// Calls FUN_004a3f10 with c on each of b 16-byte elements starting at a.
// @fnv 0x0066db30
void FUN_0066db30(void** apElements, int iCount, void* c)
{
    for (int i = 0; i < iCount; ++i)
        ((T_*)((char*)apElements + i * 16))->FUN_004a3f10(c);
}
}  // namespace fnv_0066db30

struct FUN_0066db70_Class
{
    virtual void v0()
    {}
    virtual void v1()
    {}
    virtual void v2()
    {}
    virtual void v3()
    {}
    virtual void v4(int, int)
    {}
    void __thiscall FUN_0066db70(int a, int b);
};
// Calls the virtual v4 with a and b shifted left by 4 bits; the local t is set to 0x10 and unused.
// @fnv 0x0066db70
void __thiscall FUN_0066db70_Class::FUN_0066db70(int a, int b)
{
    int t = 0x10;
    this->v4(a, b << 4);
}

void __cdecl Deallocate(void* p);
struct FUN_0066df40_Class
{
    void __thiscall FUN_0066df40();
    void* __thiscall FUN_0066e300(unsigned int flags);
};
// Calls FUN_0066df40, frees this with Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x0066e300
void* __thiscall FUN_0066df40_Class::FUN_0066e300(unsigned int flags)
{
    FUN_0066df40();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_00671a70_Class
{
    unsigned short flags;
    void FUN_00671a70(bool set);
};
// @fnv 0x00671a70
void FUN_00671a70_Class::FUN_00671a70(bool set)
{
    set ? *(unsigned short*)((char*)this + 0x24) |= 0x40 : *(unsigned short*)((char*)this + 0x24) &= ~0x40;
}

struct FUN_00671ad0_Class
{
    void __thiscall FUN_00671ad0(bool a);
};
// @fnv 0x00671ad0
void __thiscall FUN_00671ad0_Class::FUN_00671ad0(bool a)
{
    a ? *(unsigned short*)((char*)this + 0x24) &= ~1 : *(unsigned short*)((char*)this + 0x24) |= 1;
}

struct FUN_00671b30_Class
{
    unsigned short m_0024;
    void FUN_00671b30(bool a);
};

// Sets or clears bit 1 of the 16-bit field at offset 0x24 based on the boolean argument.
// @fnv 0x00671b30
void FUN_00671b30_Class::FUN_00671b30(bool a)
{
    a ? *(unsigned short*)((char*)this + 0x24) &= 0xfffffffd : *(unsigned short*)((char*)this + 0x24) |= 2;
}

struct FUN_00671b90_Class
{
    void __thiscall FUN_00671b90(bool b);
};
// @fnv 0x00671b90
void __thiscall FUN_00671b90_Class::FUN_00671b90(bool b)
{
    b ? *(unsigned short*)((char*)this + 0x24) &= ~4 : *(unsigned short*)((char*)this + 0x24) |= 4;
}

struct FUN_00671bf0_Class
{
    void __thiscall FUN_00671bf0(bool a);
};
// @fnv 0x00671bf0
void __thiscall FUN_00671bf0_Class::FUN_00671bf0(bool a)
{
    a ? *(unsigned short*)((char*)this + 0x24) &= ~8 : *(unsigned short*)((char*)this + 0x24) |= 8;
}

struct FUN_00671c50_Class
{
    void __thiscall FUN_00671c50(bool bSet);
};

// @fnv 0x00671c50
void __thiscall FUN_00671c50_Class::FUN_00671c50(bool bSet)
{
    bSet ? *(unsigned short*)((char*)this + 0x24) &= ~0x10 : *(unsigned short*)((char*)this + 0x24) |= 0x10;
}

struct FUN_00671cb0_Class
{
    void __thiscall SetFlag20(bool b);
};

// Sets or clears bit 0x20 in the 16-bit flags field at offset 0x24 based on b.
// @fnv 0x00671cb0
void __thiscall FUN_00671cb0_Class::SetFlag20(bool abSet)
{
    abSet ? *(unsigned short*)((char*)this + 0x24) &= ~0x20 : *(unsigned short*)((char*)this + 0x24) |= 0x20;
}

struct FUN_0067ac70_Class
{
    unsigned short wFlags;  // +0x22
    void __thiscall SetFlag100(bool bSet);
};

// @fnv 0x0067ac70
void __thiscall FUN_0067ac70_Class::SetFlag100(bool bSet)
{
    bSet ? ((unsigned short*)this)[17] |= 0x100 : ((unsigned short*)this)[17] &= ~0x100;
}

struct FUN_0067ad70_cls
{
    virtual ~FUN_0067ad70_cls();
    void* __thiscall DestroyAndFree(unsigned int);
};
void __cdecl _Deallocate(void*);
// Runs the destructor, then frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0067ad40
void* __thiscall FUN_0067ad70_cls::DestroyAndFree(unsigned int flags)
{
    this->FUN_0067ad70_cls::~FUN_0067ad70_cls();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct BGSSaveFormBuffer
{
    void __thiscall SaveData(void*, unsigned int, int);
};
struct FUNObj
{
    void __thiscall FUN_0067fb60(void*);
};
struct Holder
{
    int _0;
    FUNObj* q;
    void __thiscall SaveToBuffer(void*);
};
// @fnv 0x0067b000
void __thiscall Holder::SaveToBuffer(void* apBuffer)
{
    unsigned char b;
    b = q != 0;
    ((BGSSaveFormBuffer*)apBuffer)->SaveData(&b, 1, 0);
    if (b)
        q->FUN_0067fb60(apBuffer);
}

extern int DAT_010689e4;

struct FUN_0067c3f0_Class : public FUN_0067ad20_Class
{
    unsigned char b;
    unsigned char c;
    FUN_0067c3f0_Class();
};

// Sets the vtable pointer to DAT_010689e4 and initializes b to 1 and c to 0.
// @fnv 0x0067c3f0
FUN_0067c3f0_Class::FUN_0067c3f0_Class()
{
    vtbl = &DAT_010689e4;
    b = 1;
    c = 0;
}

namespace fnv_0067d940 {
extern "C" void __cdecl Deallocate(void*);

struct FUN_0067d940_Class
{
    void __thiscall FUN_0067d970();
    void* __thiscall FUN_0067d940(unsigned int flags);
};

// Calls FUN_0067d970, then frees this object with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0067d940
void* __thiscall FUN_0067d940_Class::FUN_0067d940(unsigned int flags)
{
    FUN_0067d970();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}  // namespace fnv_0067d940

template <int N> struct EndianSizeTag
{
};
void __cdecl BSEndian(unsigned char* p, EndianSizeTag<1>);
void __cdecl BSEndian(unsigned char* p, EndianSizeTag<2>);
struct FUN_0067eff0_Class
{
    void __thiscall FUN_0067eff0();
};
// @fnv 0x0067eff0
void __thiscall FUN_0067eff0_Class::FUN_0067eff0()
{
    BSEndian(reinterpret_cast<unsigned char*>(this) + 4, EndianSizeTag<1>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 8, EndianSizeTag<2>());
}

namespace fnv_0067ff10 {
template <int N> struct EndianSizeTag
{
};
void __cdecl BSEndian(unsigned char* p, EndianSizeTag<0>);
void __cdecl BSEndian(unsigned char* p, EndianSizeTag<1>);
void __cdecl BSEndian(unsigned char* p, EndianSizeTag<2>);

struct FUN_0067ff10_Class
{
    unsigned char d[4];
    void __thiscall FUN_0067ff10();
};

// @fnv 0x0067ff10
void __thiscall FUN_0067ff10_Class::FUN_0067ff10()
{
    BSEndian(&d[4], EndianSizeTag<1>());
    BSEndian(&d[8], EndianSizeTag<0>());
    BSEndian(&d[12], EndianSizeTag<2>());
}
}  // namespace fnv_0067ff10

struct FUN_0067b170
{
    int pad[4];
    unsigned char flag;
    int pad2[3];
    FUN_0067b170();
};
struct TESPackage
{
    int GetPackType();
    void* p;
    void* q;
    void* r;
    void* s;
    void* t;
    void* u;
    void* v;
    void* w;
    void* x;
    void* y;
    FUN_0067b170* e;
    void SetPackageFlag(bool b);
};
// If the package type is 15 or 28, lazily allocates the FUN_0067b170 object at e and stores b in its flag field.
// @fnv 0x00672b70
void TESPackage::SetPackageFlag(bool abFlag)
{
    if (GetPackType() == 15 || GetPackType() == 28)
    {
        FUN_0067b170* p = 0;
        if (!e)
        {
            p = new FUN_0067b170();
            e = p;
        }
        else
        {
            p = e;
        }
        p->flag = abFlag;
    }
}

void __cdecl BSEndian(unsigned char* p, EndianSizeTag<1>);

struct FUN_0067b100_Class
{
    unsigned char b0;
    unsigned char b4;
    unsigned char b0c;
    unsigned char b14;
    void __thiscall FUN_0067b100();
};

// @fnv 0x0067b100
void __thiscall FUN_0067b100_Class::FUN_0067b100()
{
    BSEndian((unsigned char*)this, EndianSizeTag<1>());
    BSEndian((unsigned char*)this + 4, EndianSizeTag<1>());
    BSEndian((unsigned char*)this + 0x14, EndianSizeTag<1>());
    BSEndian((unsigned char*)this + 0xc, EndianSizeTag<1>());
}

struct bhkConvexShape
{
    bhkConvexShape();
    ~bhkConvexShape();
    void FUN_00cab820(int a);
};
extern int DAT_01066e2c;
extern int DAT_01268324;
struct FUN_0066d6a0 : bhkConvexShape
{
    int* vtbl;
    FUN_0066d6a0(int a);
};
// @fnv 0x0066d6a0
FUN_0066d6a0::FUN_0066d6a0(int a)
{
    vtbl = &DAT_01066e2c;
    FUN_00cab820(a);
    ++DAT_01268324;
}

struct GlobalObject_0045cfe0
{
    int* Int();
};
struct Pair8
{
    GlobalObject_0045cfe0* a;
    GlobalObject_0045cfe0* b;
};
// @fnv 0x00670670
int FindPairValue(int aiThreshold, Pair8* apPairs, int aiCount)
{
    int i;
    int v = -1;
    int w8 = 0;
    for (i = 0; i < aiCount && v < 0; i++)
    {
        if (aiThreshold <= apPairs[i].a->Int()[0])
        {
            v = apPairs[i].b->Int()[0];
        }
        else
        {
            w8 = apPairs[i].b->Int()[0];
        }
    }
    return v < 0 ? w8 : v;
}

struct FUN_00672c40_Class
{
    int GetPackType();
    void SetExtraValue(float value);
};
// If GetPackType() is 15 or 28, lazily allocates the object at offset 0x28 and stores value at its offset 4.
// @fnv 0x00672c40
void FUN_00672c40_Class::SetExtraValue(float value)
{
    if (GetPackType() == 15 || GetPackType() == 28)
    {
        FUN_0067b170* extra = 0;
        if (!*(FUN_0067b170**)((char*)this + 0x28))
            *(FUN_0067b170**)((char*)this + 0x28) = extra = new FUN_0067b170;
        else
            extra = *(FUN_0067b170**)((char*)this + 0x28);
        *(float*)((char*)extra + 4) = value;
    }
}

struct ListX
{
    ~ListX();
};
struct PackageList : ListX
{
    void ClearPackageList();
    ~PackageList();
};
struct FUN_0067e3a0_Class : PackageList
{
    ~FUN_0067e3a0_Class();
};
// @fnv 0x0067e3a0
FUN_0067e3a0_Class::~FUN_0067e3a0_Class()
{
    ClearPackageList();
}

// @fnv 0x00660400
template <class T> struct BSSimpleList;
BSSimpleList<int>* FUN_00660400(BSSimpleList<int>* a)
{
    return a->GetNext();
}

void* __cdecl operator new(unsigned int);

struct AutoMemHelper
{
    int pad;
    AutoMemHelper(int context, bool flag, const char* file, int line);
    ~AutoMemHelper();
};

struct FUN_0044d000
{
    int pad[9];
    FUN_0044d000(int a, int b, int c, int d);
};

struct FUN_00665e30_Class
{
    int pad;
    int* data;
    FUN_0044d000* __thiscall FUN_00665e30(int index);
};

// @fnv 0x00665e30
FUN_0044d000* __thiscall FUN_00665e30_Class::FUN_00665e30(int index)
{
    AutoMemHelper helper(6, true, "..\\BSMain\\ThreadSafeStructures.h", 398);
    return new FUN_0044d000((int)this, (int)(data + index * 3), (int)(data + index * 3 + 1),
                            (int)(data + index * 3 + 2));
}

void* __cdecl operator new(unsigned int);

struct DetectionViewData;

struct List_009e03e0
{
    void* padding[2];

    void RemoveAll();
};

struct G2 : public List_009e03e0
{
    void AddHead(DetectionViewData** value);
};

struct SL : public G2
{
    SL();
};

struct BGSLoadFormBuffer
{
    void ReadTypedData(void* data, unsigned int size);
    bool ReadFormIdentifier(void* formId);
    int ReadElementCount();
};

struct BGSLoadGameBuffer : public BGSLoadFormBuffer
{
};

struct DetectionViewData
{
    void* formId;
    SL* list;
    unsigned char data[12];
    unsigned int value;
    int padding[3];

    DetectionViewData();
    void LoadGame(BGSLoadGameBuffer* buffer);
    void FUN_0066e440(BGSLoadGameBuffer* buffer);
};

// @fnv 0x0066e440
void DetectionViewData::FUN_0066e440(BGSLoadGameBuffer* buffer)
{
    buffer->ReadTypedData(data, 12);
    buffer->ReadTypedData(&value, 4);
    buffer->ReadFormIdentifier(this);

    unsigned int count = buffer->ReadElementCount();
    if (count)
    {
        if (list)
            list->RemoveAll();
        else
            list = new SL;

        for (int i = 0; i < count; ++i)
        {
            DetectionViewData* state = new DetectionViewData;
            state->LoadGame(buffer);
            list->AddHead(&state);
        }
    }
}

void* __cdecl operator new(unsigned int);
void __cdecl ReportAssertionViolation(char const*, int);

struct FUN_0067caa0
{
    int m_auiShapeKeys[9];

    FUN_0067caa0();
};

struct FUN_00672d10_Class
{
    unsigned char m_auiShapeKeys[0x28];
    FUN_0067caa0* m_pObject;

    FUN_0067caa0* __thiscall FUN_00672d10();
};

// @fnv 0x00672d10
FUN_0067caa0* __thiscall FUN_00672d10_Class::FUN_00672d10()
{
    if (((TESPackage*)this)->GetPackType() == 0x10)
    {
    }
    else
    {
        ReportAssertionViolation("D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Package.cpp", 0x607);
    }

    FUN_0067caa0* result = 0;
    if (!m_pObject)
    {
        result = new FUN_0067caa0;
        m_pObject = result;
    }
    else
    {
        result = m_pObject;
    }
    return result;
}

struct C0130Iterator
{
    void* m_pkContainer;
    char* m_pPtr;
};

struct C0130ScalarPtrTag
{
};

struct C0130RangeCheckedTag
{
};

C0130ScalarPtrTag __cdecl C0130PtrCat(C0130Iterator& first, C0130Iterator& dest);
char* __cdecl C0130CheckedBase(C0130Iterator& iter);
char* __cdecl C0130CopyOpt(char* first, char* last, C0130Iterator dest, C0130ScalarPtrTag ptrCat,
                           C0130RangeCheckedTag checked);

// Copies the range between the checked base pointers of first and last into dest, passing the pointer-category tag and a range-checked tag.
// @fnv 0x00660130
char* __cdecl FUN_00660130(C0130Iterator first, C0130Iterator last, C0130Iterator dest)
{
    return C0130CopyOpt(C0130CheckedBase(first), C0130CheckedBase(last), dest, C0130PtrCat(first, dest),
                        C0130RangeCheckedTag());
}

struct C0190Iterator
{
    void* m_pkContainer;
    char* m_pPtr;
};

struct C0190ScalarPtrTag
{
};

struct C0190RangeCheckedTag
{
};

C0190ScalarPtrTag __cdecl C0190PtrCat(C0190Iterator& first, C0190Iterator& dest);
char* __cdecl C0190CheckedBase(C0190Iterator& iter);
char* __cdecl C0190CopyOpt(char* first, char* last, C0190Iterator dest, C0190ScalarPtrTag ptrCat,
                           C0190RangeCheckedTag checked);

// @fnv 0x00660190
char* __cdecl FUN_00660190(C0190Iterator first, C0190Iterator last, C0190Iterator dest)
{
    return C0190CopyOpt(C0190CheckedBase(first), C0190CheckedBase(last), dest, C0190PtrCat(first, dest),
                        C0190RangeCheckedTag());
}

void __cdecl FUN_00660400(void* a1, unsigned char flag);

// @fnv 0x00660250
void __cdecl CallWithUninitializedFlag(void* a1)
{
    unsigned char flag;
    FUN_00660400(a1, flag);
}

void* operator new(unsigned int uiSize, void* pvWhere);

struct C6602B0Entry
{
    short m_sA;
    short m_sB;
    short m_sC;
};

// std::_Construct
// Copy-constructs a C6602B0Entry from kValue into the storage at pkDest using placement new.
// @fnv 0x006602b0
void CopyConstructEntry(C6602B0Entry* pkDest, const C6602B0Entry& kValue)
{
    void* pvDest = pkDest;
    ::new (pvDest) C6602B0Entry(kValue);
}

extern "C" bool __cdecl FUN_0065e750(void* a, void* b);
extern "C" void* __cdecl CallWithFlag(void* a);
extern "C" void __cdecl CopyConstructRange(void* a1, void* a2, void* a3, void* a4, bool a5, bool a6);
struct SpawnedFlagBox
{
    bool v;
};

// @fnv 0x006603a0
extern "C" void __cdecl FUN_006603a0(void* a, void* b, void* c, void* d)
{
    SpawnedFlagBox flagA3 = {};
    bool flagB;
    flagB = FUN_0065e750(&a, &c);
    CopyConstructRange(CallWithFlag(&a), CallWithFlag(&b), c, d, flagB, flagA3.v);
}

// std::_Construct for a 0x58-byte element: copy-construct in place.

void* __cdecl operator new(unsigned int uiSize, void* pvMem);
void __cdecl operator delete(void* pvObject, void* pvMem);

struct C60490Element
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

    C60490Element(const C60490Element& kOther);
};

// Copy-constructs a C60490Element from kVal into the memory pointed to by pkPtr.
// @fnv 0x00660490
void __cdecl CopyConstructElement(C60490Element* pkPtr, const C60490Element& kVal)
{
    void* pvVptr = pkPtr;
    ::new (pvVptr) C60490Element(kVal);
}

struct FUN_006665c0_Item
{
    int unk00;
    int unk04;
    int Dispose(int flags);
};

struct FUN_006665c0_Entry
{
    int unk00;
    FUN_006665c0_Item* m_item;
};

void __cdecl FormHeap_Free(void* p);
void __cdecl FUN_0044e360(void* p);

struct FUN_006665c0_cls
{
    int unk00;
    void* m_04;
    FUN_006665c0_Entry* m_08;

    unsigned int GetCount();
    void FUN_006665c0();
};

// @fnv 0x006665c0
void FUN_006665c0_cls::FUN_006665c0()
{
    unsigned int i;
    FUN_006665c0_Item* item;
    FUN_006665c0_Item* pItemCopy;
    {
        void* pEntries;
        for (i = 0; i < GetCount(); i++)
        {
            item = m_08[i].m_item;
            pItemCopy = item;
            (void)((pItemCopy != 0) ? pItemCopy->Dispose(1) : 0);
        }
        pEntries = m_08;
        FormHeap_Free(pEntries);
    }
    FUN_0044e360(m_04);
}

extern const double g_dblConst;
extern int g_timerA;
extern int g_timerB;
extern unsigned char g_counter;

float* __fastcall FUN_00403e20(void* obj);
int* __fastcall FUN_0043d4d0(void* obj);

struct FUN_0066ca50_cls
{
    int unk00;
    int unk01;
    int unk02;
    int unk03;
    int unk04;
    int unk05;
    int unk06;
    int unk07;
    int unk08;
    int unk09;
    int unk10;
    int unk11;
    int unk12;
    int unk13;
    int unk14;
    int unk15;
    int unk16;
    int unk17;
    int unk18;
    int unk19;
    int unk20;
    int unk21;
    int unk22;
    int unk23;
    int unk24;
    int unk25;
    int unk26;
    int unk27;
    int unk28;
    int unk29;
    int unk30;
    int unk31;
    int unk32;
    int unk33;
    int unk34;
    int unk35;
    int unk36;
    int unk37;
    int unk38;
    int unk39;
    int unk40;
    int unk41;
    int unk42;
    int unk43;
    int unk44;
    int unk45;
    int unk46;
    int unk47;
    int unk48;
    int unk49;
    int unk50;
    int unk51;
    int unk52;
    int unk53;
    int unk54;
    int unk55;
    int unk56;
    int unk57;
    int unk58;
    int unk59;
    int unk60;
    float m_f4;

    bool FUN_0066ca50(float dt);
};

// @fnv 0x0066ca50
bool FUN_0066ca50_cls::FUN_0066ca50(float dt)
{
    if (dt == g_dblConst)
    {
        return true;
    }
    else if (m_f4 == g_dblConst)
    {
        m_f4 = (float)((double)(dt + *FUN_00403e20(&g_timerA)) +
                       (*FUN_00403e20(&g_timerA) / *FUN_0043d4d0(&g_timerB)) * g_counter);
        g_counter++;
        g_counter %= *FUN_0043d4d0(&g_timerB);
        return true;
    }
    else
    {
        bool result = false;
        if (dt > m_f4)
        {
            m_f4 = dt + *FUN_00403e20(&g_timerA);
            result = true;
        }
        return result;
    }
}

struct SpawnedObject
{
    int GetRefPtr();
    bool IsReady() const;
    float GetValue();
};

extern int DAT_011ca278;
extern int DAT_011dea3c;

int __cdecl FUN_0066dba0(int a);
float __cdecl FUN_0066dc70(int a);
void __cdecl FUN_005e58f0(int a, int b, int c, float* d);

// Returns the object's value if it is ready, otherwise a value derived from its ref pointer, and passes it to FUN_005e58f0.
// @fnv 0x0066dce0
float __cdecl GetObjectValue(SpawnedObject* obj)
{
    int b = FUN_0066dba0(obj ? obj->GetRefPtr() : 0);
    float f = 0.0f;
    if (obj != 0 && obj->IsReady())
    {
        f = obj->GetValue();
    }
    else
    {
        f = FUN_0066dc70(b);
    }
    FUN_005e58f0(0x28, DAT_011dea3c, obj ? (int)obj : DAT_011ca278, &f);
    return f;
}

extern "C" int __cdecl FUN_004019a0(void*);

struct S_0066e2b0_Class : public FUN_0066df40_Class
{
    void __thiscall FUN_0066e2b0();
};

// Calls FUN_004019a0 on the object at offset 0x18; if it returns 0, calls FUN_0066e300(1) on this.
// @fnv 0x0066e2b0
void __thiscall S_0066e2b0_Class::FUN_0066e2b0()
{
    if (FUN_004019a0((void*)((char*)this + 0x18)) == 0)
    {
        FUN_0066df40_Class* object = this;
        FUN_0066df40_Class* first = object;

        first ? first->FUN_0066e300(1) : 0;
    }
}

struct G2;
extern G2 g_011d6124;

// Scans the list at g_011d6124 for an item whose value equals the given non-negative value and returns it, or null if not found.
// @fnv 0x0066e330
DetectionViewData* __cdecl FindStateByValue(int value)
{
    if (value < 0)
    {
        return 0;
    }
    BSSimpleList<DetectionViewData*>* node = (BSSimpleList<DetectionViewData*>*)&g_011d6124;
    while (node)
    {
        DetectionViewData* state = node->GetItem();
        if (state && state->value == (unsigned int)value)
        {
            return state;
        }
        node = node->GetNext();
    }
    return 0;
}

struct SaveBufCls
{
    void __thiscall FUN_00865e50(void* data, unsigned int size, int z);
    void __thiscall FUN_00865df0(void* data, unsigned int size);
    unsigned int __thiscall FUN_00865f20();
    void __thiscall FUN_00865ff0(unsigned int count, unsigned int pos);
};

struct SaveItemCls
{
    void __thiscall SaveDetectionState(SaveBufCls* buffer);
};

struct SaveNodeCls
{
    SaveItemCls** __thiscall FUN_006815c0();
    SaveNodeCls* __thiscall FUN_00726070();
};

struct DetClassCls
{
    void* m_00;
    SaveNodeCls* m_04;
    unsigned char m_08[12];
    unsigned int m_14;
    void __thiscall WriteToSaveBuffer(SaveBufCls* buffer);
};

// @fnv 0x0066e390
void __thiscall DetClassCls::WriteToSaveBuffer(SaveBufCls* buffer)
{
    buffer->FUN_00865e50(&this->m_08, 0xc, 0);
    buffer->FUN_00865e50(&this->m_14, 4, 0);
    buffer->FUN_00865df0(this->m_00, 0);
    unsigned int count = 0;
    unsigned int pos4 = buffer->FUN_00865f20();
    SaveNodeCls* node3 = this->m_04;
    while (node3 != 0)
    {
        SaveItemCls* item = *node3->FUN_006815c0();
        if (item != 0)
        {
            item->SaveDetectionState(buffer);
            count++;
        }
        node3 = node3->FUN_00726070();
    }
    buffer->FUN_00865ff0(count, pos4);
}

extern double DAT_01012060;
extern double DAT_01017a40;

class StatsGetterCls
{
  public:
    int* GetValuePtr();
};

extern StatsGetterCls DAT_011d6458;

// @fnv 0x00670700
bool __cdecl IsScaledValueAboveThreshold(float a, float b)
{
    int scaled;
    if (b > DAT_01012060)
    {
        scaled = (int)(a / b * DAT_01017a40);
    }
    else
    {
        scaled = 100;
    }
    int value = scaled;
    return value > *(&DAT_011d6458)->GetValuePtr();
}

void __cdecl FUN_00407a90(void* p, bool flag);
void __cdecl FUN_00401080(void* p, bool flag);
struct SpawnedFlag
{
    bool m_bValue;
};
struct FUN_0067ca10_cls
{
    void FUN_0067ca10();
};
// Calls FUN_00407a90 on this+6, +8 and +0xa, then FUN_00401080 on this+0xc and this+0x10, each with a zero-initialised bool.
// @fnv 0x0067ca10
void FUN_0067ca10_cls::FUN_0067ca10()
{
    SpawnedFlag a = {};
    FUN_00407a90((char*)this + 6, a.m_bValue);
    SpawnedFlag b = {};
    FUN_00407a90((char*)this + 8, b.m_bValue);
    SpawnedFlag c = {};
    FUN_00407a90((char*)this + 0xa, c.m_bValue);
    {
        SpawnedFlag d = {};
        FUN_00401080((char*)this + 0xc, d.m_bValue);
    }
    {
        SpawnedFlag e = {};
        FUN_00401080((char*)this + 0x10, e.m_bValue);
    }
}

// NiTMap destructor: remove all entries, then the base map destructor frees the hash table.

class F5FC0MapBase
{
  public:
    virtual ~F5FC0MapBase();
    void RemoveAll();

    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
};

class FUN_00665fc0 : public F5FC0MapBase
{
  public:
    virtual ~FUN_00665fc0();
};

// Destructor that calls RemoveAll to clear the hash table entries.
// @fnv 0x00665fc0
FUN_00665fc0::~FUN_00665fc0()
{
    RemoveAll();
}

// Forward the position for the given key (obtained through a stateless helper) to the erase routine.

class D9B0Container;

struct D9B0Locate
{
    void* Find(D9B0Container* pkContainer, int iKey);
};

class D9B0Container
{
  public:
    void EraseAt(void* pvPosition);
    void EraseByKey(int iKey);
};

// Finds the entry for iKey in this container and erases it at the located position.
// @fnv 0x0066d9b0
void D9B0Container::EraseByKey(int iKey)
{
    EraseAt(D9B0Locate().Find(this, iKey));
}

// Save: write the header value, every queued item, then patch the item count in at the reserved position.

class E6D0SaveBuffer;

class E6D0Item
{
  public:
    void Save(E6D0SaveBuffer* pkBuffer);
};

class E6D0Node
{
  public:
    E6D0Item** GetItem();
    E6D0Node* GetNext();
};

class E6D0SaveBuffer
{
  public:
    void SaveData(void* pvData, int iSize, int iFlags);
    unsigned int GetPosition();
    void WriteCountAt(int aiCountValue, unsigned int uiPosition);
};

extern int g_iE6D0Header;
extern E6D0Node g_kE6D0Items;

// Writes the E6D0 header, saves each non-null item from the g_kE6D0Items list, and patches the item count at the recorded position.
// @fnv 0x0066e6d0
void SaveE6D0Items(E6D0SaveBuffer* pkBuffer)
{
    pkBuffer->SaveData(&g_iE6D0Header, 4, 0);
    int aiCountValue = 0;
    unsigned int uiCountPos = pkBuffer->GetPosition();
    E6D0Node* pkNode = &g_kE6D0Items;
    while (pkNode)
    {
        E6D0Item* pkItem = *pkNode->GetItem();
        if (pkItem)
        {
            pkItem->Save(pkBuffer);
            aiCountValue++;
        }
        pkNode = pkNode->GetNext();
    }
    pkBuffer->WriteCountAt(aiCountValue, uiCountPos);
}

struct ComparisonEntry
{
    int FUN_00678ca0();
    int GetSecondByte();
    signed char FUN_00678ce0();
    signed char FUN_0086a460();
};
struct ComparisonOwner
{
    ComparisonEntry* FUN_0041d8a0();
    int CompareTo(ComparisonEntry* other);
};

// Compares this entry against other by four key getters in order, treating -1 as unset, and returns -1, 0 or 1.
// @fnv 0x00678a80
int ComparisonOwner::CompareTo(ComparisonEntry* other)
{
    ComparisonEntry* entry = FUN_0041d8a0();
    if ((entry->FUN_00678ca0() == -1 && other->FUN_00678ca0() == -1) || entry->FUN_00678ca0() == other->FUN_00678ca0())
    {
        if ((entry->FUN_00678ce0() == 0 && other->FUN_00678ce0() == -1) ||
            entry->FUN_00678ce0() == other->FUN_00678ce0())
        {
            if ((entry->GetSecondByte() == -1 && other->GetSecondByte() == -1) ||
                entry->GetSecondByte() == other->GetSecondByte())
            {
                if ((entry->FUN_0086a460() == -1 && other->FUN_0086a460() == -1) ||
                    entry->FUN_0086a460() == other->FUN_0086a460())
                {
                    return 0;
                }
                else
                {
                    if (entry->FUN_0086a460() != -1 &&
                        (other->FUN_0086a460() == -1 || entry->FUN_0086a460() < other->FUN_0086a460()))
                    {
                        return -1;
                    }
                    else
                    {
                        return 1;
                    }
                }
            }
            else
            {
                if (entry->GetSecondByte() != -1 &&
                    (other->GetSecondByte() == -1 || entry->GetSecondByte() < other->GetSecondByte()))
                {
                    return -1;
                }
                else
                {
                    return 1;
                }
            }
        }
        else
        {
            if (entry->FUN_00678ce0() != -1 &&
                (other->FUN_00678ce0() == -1 || entry->FUN_00678ce0() < other->FUN_00678ce0()))
            {
                return -1;
            }
            else
            {
                return 1;
            }
        }
    }
    else
    {
        if (entry->FUN_00678ca0() != -1 &&
            (other->FUN_00678ca0() == -1 || entry->FUN_00678ca0() < other->FUN_00678ca0()))
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }
}

class TESForm
{
  public:
    virtual ~TESForm();
};
class Actor : public TESForm
{
};
TESForm* __cdecl LookupFormByID(void* p);
struct E640Item
{
    void __thiscall ResolveActorFormId();
};
struct E640Cls : DetClassCls
{
    void __thiscall FUN_0066e640(SaveBufCls* buffer);
};
// Resolves m_00 to an Actor via dynamic_cast and calls ResolveActorFormId on each item found while walking the m_04 node list.
// @fnv 0x0066e640
void E640Cls::FUN_0066e640(SaveBufCls* buffer)
{
    m_00 = m_00 ? dynamic_cast<Actor*>(LookupFormByID(m_00)) : 0;
    SaveNodeCls* n = m_04;
    while (n)
    {
        SaveItemCls* it = *n->FUN_006815c0();
        if (it)
            ((E640Item*)it)->ResolveActorFormId();
        n = n->FUN_00726070();
    }
}

struct S_00660510_Context
{
    void __thiscall FUN_00660300(int dest, int src);
    void __thiscall FUN_0065ea40(int element);
};

// @fnv 0x00660510
int __cdecl FUN_00660510(int first, int last, int dest, S_00660510_Context* context)
{
    int start = dest;

    try
    {
        for (; first != last; dest += 0x1c, first += 0x1c)
        {
            context->FUN_00660300(dest, first);
        }
    }
    catch (...)
    {
        for (; start != dest; start += 0x1c)
        {
            context->FUN_0065ea40(start);
        }

        throw;
    }

    return dest;
}

struct Elem6605
{
    char m_data[0x58];
};
struct Alloc6605
{
    void FUN_00660320(Elem6605* pDest, const Elem6605& kSrc);
    void FUN_0065ea60(Elem6605* pElem);
};
struct NonscalarTag6605
{
};
struct CheckedTag6605
{
};

namespace std6605 {
// @fnv 0x006605d0
Elem6605* __cdecl CopyConstructRange(Elem6605* _First, Elem6605* _Last, Elem6605* _Dest, Alloc6605& _Al,
                                     NonscalarTag6605, CheckedTag6605)
{
    Elem6605* _Next = _Dest;
    try
    {
        for (; _First != _Last; ++_Dest, ++_First)
            _Al.FUN_00660320(_Dest, *_First);
    }
    catch (...)
    {
        for (; _Next != _Dest; ++_Next)
            _Al.FUN_0065ea60(_Next);
        throw;
    }
    return _Dest;
}
}

float __cdecl FUN_0066dc70(int value);
float* __fastcall FUN_00403e20(void* object);
extern unsigned char DAT_011d5f88;

// Returns FUN_0066dc70(value), multiplied by the value from FUN_00403e20(&DAT_011d5f88) unless unscaled is set.
// @fnv 0x0066dca0
float __cdecl FUN_0066dca0(int value, bool unscaled)
{
    float baseValue = FUN_0066dc70(value);
    if (!unscaled)
    {
        return baseValue * *FUN_00403e20(&DAT_011d5f88);
    }
    else
    {
        return baseValue;
    }
}

struct Vector3
{
    float x;
    float y;
    float z;
};
extern Vector3 DAT_011f426c;

struct SaveNodeExtended : SaveNodeCls
{
    bool FUN_008256d0();
    void FUN_0063f7b0();
    ~SaveNodeExtended();
};

struct DetClassExtended : DetClassCls
{
    void ClearAndReset();
};

// @fnv 0x0066e200
void DetClassExtended::ClearAndReset()
{
    m_00 = 0;
    while (m_04 && !reinterpret_cast<SaveNodeExtended*>(m_04)->FUN_008256d0())
    {
        SaveItemCls* item = *m_04->FUN_006815c0();
        FormHeap_Free(item);
        reinterpret_cast<SaveNodeExtended*>(m_04)->FUN_0063f7b0();
    }

    delete reinterpret_cast<SaveNodeExtended*>(m_04);
    m_04 = 0;
    *reinterpret_cast<Vector3*>(m_08) = DAT_011f426c;
}

extern "C" void __cdecl FUN_00660510(void* first, void* last, void* destCont, void* destPtr, bool ptrCat, bool checked);

// copy-style dispatch: unwrap both source iterators, classify the pointer pair, forward to the worker
// Computes a pointer-category flag from first and destCont, then forwards to FUN_00660510 with a zeroed SpawnedFlagBox.
// @fnv 0x00660340
extern "C" void __cdecl FUN_00660340(void* first, void* last, void* destCont, void* destPtr)
{
    SpawnedFlagBox checked = {};
    bool ptrCat = FUN_0065e750(&first, &destCont);
    FUN_00660510(CallWithFlag(&first), CallWithFlag(&last), destCont, destPtr, ptrCat, checked.v);
}

struct FUN_006e6da0
{
    int a;
};
void* __cdecl operator new(unsigned int uiSize, FUN_006e6da0* pPlace);
inline void __cdecl operator delete(void*, FUN_006e6da0*)
{}
class FUN_0065fa80
{
  public:
    FUN_0065fa80(int a);
    int unk[7];
};
// Places a FUN_0065fa80 object at pMem via placement new, passing a to its constructor.
// @fnv 0x00660410
void __cdecl ConstructInPlace(void* pMem, int a)
{
    FUN_006e6da0* pPlace = (FUN_006e6da0*)pMem;
    new (pPlace) FUN_0065fa80(a);
}

struct ElemD9E0
{
    int unk00[4];
};

struct TagD9E0
{
};

void __cdecl ResizeAudioStream(void* pAlloc, void* pArray, int iElemSize);
void __cdecl FUN_0066db30(ElemD9E0* pDest, int iCount, const ElemD9E0& kVal, TagD9E0 kTag);

class ArrD9E0
{
  public:
    ElemD9E0* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetSizeMasked();
    void PushBack(void* pAlloc, const ElemD9E0& kVal);
};

// Appends kVal to the array, resizing the backing buffer via ResizeAudioStream when the size reaches capacity.
// @fnv 0x0066d9e0
void ArrD9E0::PushBack(void* pAlloc, const ElemD9E0& kVal)
{
    if (m_iElementCount == GetSizeMasked())
        ResizeAudioStream(pAlloc, this, 0x10);
    FUN_0066db30(m_data + m_iElementCount, 1, kVal, TagD9E0());
    m_iElementCount++;
}

struct FUN_004a4840_class
{
    char pad;
    void* __thiscall FUN_004a4840(int);
};

// Calls FUN_0066dae0 on this with the result of FUN_004a4840, called on a zeroed local object with this cast to int.
// @fnv 0x0066dab0
void FUN_0066da50::FUN_0066dab0()
{
    FUN_004a4840_class obj = {};
    ((FUN_0066dae0_Class*)this)->FUN_0066dae0(obj.FUN_004a4840((int)this));
}

struct FUN_00660070_cls
{
    void FUN_0065e9a0(int a);
    void FUN_006601f0(int a, int b);
};

// Copies 6-byte elements in [a1, a2) to a3 via a4->FUN_006601f0; on exception calls a4->FUN_0065e9a0 on those already copied; returns the new dest end.
// @fnv 0x00660070
int __cdecl CopyRange(int apSrc, int apEnd, int apDst, FUN_00660070_cls* a4)
{
    int pRollback = apDst;
    try
    {
        for (; apSrc != apEnd; apDst += 6, apSrc += 6)
        {
            a4->FUN_006601f0(apDst, apSrc);
        }
    }
    catch (...)
    {
        for (; pRollback != apDst; pRollback += 6)
        {
            a4->FUN_0065e9a0(pRollback);
        }
        throw;
    }
    return apDst;
}

namespace fnv_0066df40 {
void __cdecl _Deallocate(void*);

class B6DF40Effect;

class B6DF40List
{
  public:
    ~B6DF40List();

    bool IsEmpty();
    B6DF40Effect** GetItem();
    void RemoveHead();
};

class BGSSaveLoadGame
{
  public:
    bool IsLoading();
};

extern BGSSaveLoadGame* g_BGSSaveLoadGame;

class B6DF40Owner;

class B6DF40Registry
{
  public:
    void Add(B6DF40Owner* const& pkOwner);
};

extern B6DF40Registry g_011d6124;

class B6DF40Owner
{
  public:
    void FUN_0066df40();

    int m_iArrayLength;
    B6DF40List* m_pkEffects;
    int unk08;
    int unk0C;
    int unk10;
    int m_iRefID;
};

// Frees all effects in m_pkEffects, then registers this owner with g_011d6124 unless loading a save with m_iRefID of -1.
// @fnv 0x0066df40
void B6DF40Owner::FUN_0066df40()
{
    m_iArrayLength = 0;
    while (m_pkEffects && !m_pkEffects->IsEmpty())
    {
        B6DF40Effect* pkEffect = *m_pkEffects->GetItem();
        _Deallocate(pkEffect);
        m_pkEffects->RemoveHead();
    }
    delete m_pkEffects;
    m_pkEffects = 0;
    bool bRegister = true;
    if (g_BGSSaveLoadGame->IsLoading() && m_iRefID == -1)
        bRegister = false;
    if (bRegister)
        g_011d6124.Add(this);
}
}  // namespace fnv_0066df40

extern int DAT_01068a64;
extern float DAT_010162c0;

struct S_0067caa0_Foo
{
    int* vtbl;
    int unk04;
    int unk08;
    unsigned char unk0c;
    unsigned char unk0d;
    unsigned char unk0e;
    unsigned char unk0f;
    unsigned char unk10;
    unsigned char unk11;
    unsigned short unk12;
    unsigned short unk14;
    unsigned short unk16;
    float unk18;
    float unk1c;
    int unk20;

    void __thiscall FUN_0067ad20();
    S_0067caa0_Foo* __thiscall FUN_0067caa0();
};

// Calls FUN_0067ad20, sets vtbl to DAT_01068a64, initializes the listed fields to constants (unk1c from DAT_010162c0), and returns this.
// @fnv 0x0067caa0
S_0067caa0_Foo* __thiscall S_0067caa0_Foo::FUN_0067caa0()
{
    FUN_0067ad20();

    vtbl = &DAT_01068a64;
    unk04 = 0;
    unk08 = 0;
    unk20 = 0;
    unk0c = 0;
    unk0d = 0;
    unk0e = 1;
    unk0f = 1;
    unk10 = 0;
    unk11 = 0;
    unk12 = 1;
    unk14 = 1;
    unk16 = 6;
    unk18 = 1.0f;
    unk1c = DAT_010162c0;

    return this;
}
