
// src/staging/blk_004c0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

struct FUN_004dfdd0_StandIn
{
    float m_f0;
    float m_f4;
    float m_f8;
    float m_fC;
    float m_f10;
    float m_f14;
    float m_f18;
    float m_f1C;
    float m_f20;
    void InitIdentity();
};

// Sets the nine floats to an identity matrix: 1.0 on the diagonal, 0.0 elsewhere.
// @fnv 0x004dfdd0
void FUN_004dfdd0_StandIn::InitIdentity()
{
    m_f0 = 1.0f;
    m_f4 = 0.0f;
    m_f8 = 0.0f;
    m_fC = 0.0f;
    m_f10 = 1.0f;
    m_f14 = 0.0f;
    m_f18 = 0.0f;
    m_f1C = 0.0f;
    m_f20 = 1.0f;
}

struct FUN_004d4e10_StandIn
{
    void FUN_004d4eb0();
    void* DestroyIfFlagged(unsigned int flags);
};

// Calls FUN_004d4eb0, then deletes this object if bit 0 of flags is set, and returns this.
// @fnv 0x004d4e10
void* FUN_004d4e10_StandIn::DestroyIfFlagged(unsigned int flags)
{
    FUN_004d4eb0();
    if (flags & 1)
        operator delete(this);
    return this;
}

void __cdecl ClearGlobalArray();

struct FUN_004d5d40_Class
{
    void __thiscall FUN_004d5d40();
};

// @fnv 0x004d5d40
void __thiscall FUN_004d5d40_Class::FUN_004d5d40()
{
    ClearGlobalArray();
}

extern void(__stdcall* DAT_00fdf28c)(void*, int, int, int);

struct FUN_004d7490_Class
{
    void FUN_004d7490();
};

// @fnv 0x004d7490
void FUN_004d7490_Class::FUN_004d7490()
{
    DAT_00fdf28c(*(void**)((char*)this + 0xC), 0x1101, 0, 0xffff0000);
}

struct ArrSI
{
    unsigned int GetFlags();
};
struct FUN_004d7d50_StandIn
{
    unsigned int __thiscall FUN_004d7d50();
};
// @fnv 0x004d7d50
unsigned int __thiscall FUN_004d7d50_StandIn::FUN_004d7d50()
{
    return ((ArrSI*)((char*)this + 0xC8))->GetFlags();
}

struct FUN_004d8510_StandIn
{
    void GetResultValue(int);
    void FUN_004d8510();
};

// @fnv 0x004d8510
void FUN_004d8510_StandIn::FUN_004d8510()
{
    GetResultValue(0x42);
}

struct TESObjectREFR;
struct bhkShape;
bhkShape* __cdecl FUN_004a3a40(void*);
void* GetLocalSubValue(TESObjectREFR* p, int a);
struct FUN_004d85a0_Class
{
    void* GetLocalSubValue(int a);
    void* FUN_004d85a0(int a);
};
// @fnv 0x004d85a0
void* FUN_004d85a0_Class::FUN_004d85a0(int a)
{
    return FUN_004a3a40(GetLocalSubValue(a));
}

struct FUN_004d8670_Class
{
    BSSimpleList<int>* GetListNext();
};

// @fnv 0x004d8670
BSSimpleList<int>* FUN_004d8670_Class::GetListNext()
{
    return ((BSSimpleList<int>*)((char*)this + 0x10))->GetNext();
}

struct FUN_004d8a00_Class
{
    unsigned short GetField3C();
};

// @fnv 0x004d8a00
unsigned short FUN_004d8a00_Class::GetField3C()
{
    return *(unsigned short*)((char*)this + 0x3c);
}

struct FUN_004d8a20_Class
{
    int m_f0;
    int m_f4;
    int m_f8;
    int m_fC;
    int m_f10;
    int m_f14;
    int m_f18;
    int m_f1C;
    int m_f20;
    int m_f24;
    int m_f28;
    int m_f2C;
    int m_f30;
    int m_f34;
    int* m_p38;
    int GetEntry(unsigned short index);
};

// @fnv 0x004d8a20
int FUN_004d8a20_Class::GetEntry(unsigned short index)
{
    return m_p38[index];
}

extern int DAT_01020fe4;
struct FUN_004d8fa0_StandIn
{
    int m_p;
    void FUN_004d9000(int a);
    FUN_004d8fa0_StandIn* FUN_004d8fa0(int a);
};
// Calls FUN_004d9000 with a, stores the address of DAT_01020fe4 in m_p, and returns this.
// @fnv 0x004d8fa0
FUN_004d8fa0_StandIn* __thiscall FUN_004d8fa0_StandIn::FUN_004d8fa0(int a)
{
    FUN_004d9000(a);
    m_p = (int)&DAT_01020fe4;
    return this;
}

struct FUN_004d9190_Class
{
    void __thiscall FUN_004d91b0();
    void __thiscall FUN_004d9190();
};

// @fnv 0x004d9190
void __thiscall FUN_004d9190_Class::FUN_004d9190()
{
    FUN_004d91b0();
}

struct FUN_004dc020_Class
{
    unsigned int m_p288;
    unsigned int FUN_004dc020();
};
// @fnv 0x004dc020
unsigned int FUN_004dc020_Class::FUN_004dc020()
{
    return *(unsigned int*)((char*)this + 0x288);
}

struct FUN_004dc1c0_Class
{
    int m_i0;
    int m_i4;
    char HasNonZeroValue();
};

// @fnv 0x004dc1c0
char FUN_004dc1c0_Class::HasNonZeroValue()
{
    return m_i4 != 0;
}

extern char DAT_011c6fc8;
void __cdecl ___insecure_strcpy(char* dst, const char* src);

// @fnv 0x004dc330
void __cdecl CopyStringToGlobal(const char* pcSource)
{
    DAT_011c6fc8 = 0;
    if (pcSource)
        ___insecure_strcpy(&DAT_011c6fc8, pcSource);
}

struct Arr
{
    unsigned int GetSize();
};
struct FUN_004dcce0_Class
{
    void FUN_004dcce0();
};
// @fnv 0x004dcce0
void FUN_004dcce0_Class::FUN_004dcce0()
{
    ((Arr*)((char*)this + 0x450))->GetSize();
}

namespace fnv_004dcd00 {
struct Arr
{
    unsigned int* GetAt(int);
};
struct FUN_004dcd00_Class
{
    unsigned int m_450;
    unsigned int GetElementAt(int idx);
};
// Returns the unsigned int stored at the given index in the Arr object located at offset 0x450 of this instance.
// @fnv 0x004dcd00
unsigned int FUN_004dcd00_Class::GetElementAt(int aiIndex)
{
    return *(reinterpret_cast<Arr*>(reinterpret_cast<unsigned char*>(this) + 0x450))->GetAt(aiIndex);
}
}  // namespace fnv_004dcd00

struct FUN_004dcd60_Class
{
    unsigned char GetByteAt140();
};

// @fnv 0x004dcd60
unsigned char FUN_004dcd60_Class::GetByteAt140()
{
    return ((unsigned char*)this)[0x140];
}

struct FUN_004dd220_Class
{
    unsigned int GetField5C8();
};

// @fnv 0x004dd220
unsigned int FUN_004dd220_Class::GetField5C8()
{
    return *(unsigned int*)((char*)this + 0x5c8);
}

// Allocates size bytes with operator new and returns the resulting pointer.
// @fnv 0x004dd240
void* __stdcall FUN_004dd240(unsigned int size)
{
    void* p = operator new(size);
    void* RunFourthVirtual;
    RunFourthVirtual = p;
    return RunFourthVirtual;
}

void __stdcall ClearAndFreePointer(void*);

// @fnv 0x004dd2a0
int __cdecl FUN_004dd2a0(void* p)
{
    ClearAndFreePointer(p);
    return 1;
}

struct FUN_004de290_StandIn
{
    float m_f0;
    float m_f4;
    FUN_004de290_StandIn* SetValue(float);
};

// @fnv 0x004de290
FUN_004de290_StandIn* FUN_004de290_StandIn::SetValue(float value)
{
    if (this)
        m_f4 = value;
    return this;
}

struct FUN_004de2b0_StandIn
{
    FUN_004de2b0_StandIn* __thiscall SetCharAtOffset4(char c);
};

// @fnv 0x004de2b0
FUN_004de2b0_StandIn* __thiscall FUN_004de2b0_StandIn::SetCharAtOffset4(char acValue)
{
    if (this)
        ((char*)this)[4] = acValue;
    return this;
}

extern unsigned char DAT_011c77e9;
extern float DAT_011c77ec;

// @fnv 0x004def00
char FUN_004def00(float afValue, char acValue)
{
    DAT_011c77ec = afValue;
    DAT_011c77e9 = acValue;
    return 1;
}

struct GlobalObject_004aff00
{
    void RemoveAll();
};

struct FUN_004def90_Class
{
    void FUN_004def90();
};

// @fnv 0x004def90
void FUN_004def90_Class::FUN_004def90()
{
    ((GlobalObject_004aff00*)((char*)this + 0x9c))->RemoveAll();
}

struct GO
{
    GO& operator=(void*);
};

struct FUN_004dfe80_Class
{
    GO m_p[12];
    void SetSlotValue(int index, void* value);
};

// Stores value into the slot at index within the array starting at offset 0x60 of this object.
// @fnv 0x004dfe80
void FUN_004dfe80_Class::SetSlotValue(int index, void* value)
{
    *(GO*)((char*)this + index * 4 + 0x60) = value;
}

struct MersenneTwister
{
    static MersenneTwister* GetRandomGenerator();
};

struct FUN_004dfec0_StandIn
{
    void FUN_004dfec0();
};

// @fnv 0x004dfea0
void FUN_004dfea0()
{
    reinterpret_cast<FUN_004dfec0_StandIn*>(MersenneTwister::GetRandomGenerator())->FUN_004dfec0();
}

void _NiFreeAlias(void*);
struct FUN_004d4f10_StandIn : public NiTPointerMap<int, int>
{
    void FUN_004d4f10();
};
// @fnv 0x004d4f10
void FUN_004d4f10_StandIn::FUN_004d4f10()
{
    *(const char**)this = "@OM";
    RemoveAll();
    _NiFreeAlias(*(void**)((char*)this + 8));
}

extern "C" void NiFreeAlias(void*);

extern int DAT_01021004;

struct FUN_004d90d0_Class
{
    void* m_p0;
    void* m_p4;
    void* m_p8;
    void FUN_004d90d0();
};

// Points m_p0 at DAT_01021004, clears the map via RemoveAll, and frees m_p8 with NiFreeAlias.
// @fnv 0x004d90d0
void FUN_004d90d0_Class::FUN_004d90d0()
{
    m_p0 = (void*)&DAT_01021004;
    ((NiTPointerMap<int, int>*)this)->RemoveAll();
    NiFreeAlias(m_p8);
}

void Deallocate(void*);
struct FUN_004d8fd0_Class
{
    void __thiscall FUN_004d9070();
    void* __thiscall Destroy(unsigned int flags);
};
// Calls FUN_004d9070, frees this when flags has bit 0 set, and returns this.
// @fnv 0x004d8fd0
void* __thiscall FUN_004d8fd0_Class::Destroy(unsigned int flags)
{
    FUN_004d9070();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void __cdecl Deallocate(void* p);
struct FUN_004d9160_Class : public FUN_004d9190_Class
{
    void* FUN_004d9160(unsigned int flags);
};
// @fnv 0x004d9160
void* FUN_004d9160_Class::FUN_004d9160(unsigned int flags)
{
    FUN_004d9190();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern int DAT_01020924;
struct FUN_004d4e40_Holder
{
    void __thiscall FUN_004d4e40(unsigned int);
};
struct FUN_004d4de0_Class
{
    void* __thiscall FUN_004d4de0(unsigned int);
};
// Calls FUN_004d4e40 on this, then stores the address of DAT_01020924 into the object's first field and returns this.
// @fnv 0x004d4de0
void* __thiscall FUN_004d4de0_Class::FUN_004d4de0(unsigned int a)
{
    ((FUN_004d4e40_Holder*)this)->FUN_004d4e40(a);
    *(void**)this = (void*)&DAT_01020924;
    return (void*)this;
}

extern "C" void* __cdecl NiMalloc(unsigned int size);
extern "C" void* __cdecl memset(void* dest, int value, unsigned int count);
extern int DAT_01020944;
struct FUN_004d4e40_Class
{
    void* m_pVT;
    unsigned int m_uiSize;
    void* m_pData;
    unsigned int m_uiCount;
    FUN_004d4e40_Class(unsigned int size);
};
// Sets the vtable, stores size, allocates size*4 bytes zeroed into m_pData and resets m_uiCount to 0.
// @fnv 0x004d4e40
FUN_004d4e40_Class::FUN_004d4e40_Class(unsigned int size)
{
    m_pVT = &DAT_01020944;
    m_uiSize = size;
    m_uiCount = 0;
    unsigned int uiBytes = m_uiSize << 2;
    m_pData = NiMalloc(uiBytes);
    memset(m_pData, 0, m_uiSize << 2);
}

void __cdecl _Deallocate(void*);
struct FUN_004d4f40_StandIn
{
    void* __thiscall FUN_004d4f40(unsigned int flags);
};
// Calls FUN_004d4f10 on this, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x004d4f40
void* __thiscall FUN_004d4f40_StandIn::FUN_004d4f40(unsigned int flags)
{
    ((FUN_004d4f10_StandIn*)this)->FUN_004d4f10();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_004d5c20_Base
{
    virtual int __thiscall FUN_000(int);
};
struct FUN_004d5c20_StandIn
{
    FUN_004d5c20_Base* m_p0;
    void __thiscall FUN_004d5c20();
};
// Calls FUN_000(1) on m_p0 when m_p0 is non-null.
// @fnv 0x004d5c20
void __thiscall FUN_004d5c20_StandIn::FUN_004d5c20()
{
    FUN_004d5c20_Base* p1 = m_p0;
    FUN_004d5c20_Base* p2 = p1;
    p2 ? p2->FUN_000(1) : 0;
}

void __cdecl _Deallocate(void*);
struct FUN_004d5dd0_Class
{
    void __thiscall FUN_004d5c20();
    void* __thiscall FUN_004d5dd0(unsigned int);
};
// Calls FUN_004d5c20, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x004d5dd0
void* __thiscall FUN_004d5dd0_Class::FUN_004d5dd0(unsigned int flags)
{
    FUN_004d5c20();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

extern void* DAT_011c6d50[43];

// Iterates over the 43 pointers in DAT_011c6d50 and, for each non-null one, sets its second int element to 0.
// @fnv 0x004d60c0
void __cdecl FUN_004d60c0(void)
{
    for (unsigned int i = 0; i < 43; ++i)
        if (DAT_011c6d50[i])
            ((int*)DAT_011c6d50[i])[1] = 0;
}

extern void*(__stdcall* DAT_00fdf020)(void*, int, int, int, int, int, int);
struct FUN_004d6490_Class
{
    void* m_p0;
    void* m_p4;
    void* m_p8;
    void* m_pC;
    void* m_p10;
    void* m_p14;
    void __thiscall FUN_004d6490();
};
// @fnv 0x004d6490
void __thiscall FUN_004d6490_Class::FUN_004d6490()
{
    m_p14 = DAT_00fdf020(m_p0, 180, 16, 1, 0xff000000, 0, 0);
}

extern void(__stdcall* DAT_00fdf290)(void*);
struct FUN_004d7440_Class
{
    char _0[8];
    void* p8;
    void* pC;
    void __thiscall FUN_004d7440();
};
// @fnv 0x004d7440
void __thiscall FUN_004d7440_Class::FUN_004d7440()
{
    DAT_00fdf290(pC);
    DAT_00fdf290(p8);
}

extern int(__cdecl* DAT_011c6f18)(int, int, int, int);
// Forwards the four arguments to the function pointer DAT_011c6f18 if it is set, otherwise returns 0.
// @fnv 0x004d7890
int __cdecl FUN_004d7890(int aiArg1, int aiArg2, int aiArg3, int aiArg4)
{
    if (DAT_011c6f18)
        return DAT_011c6f18(aiArg1, aiArg2, aiArg3, aiArg4);
    return 0;
}

void* __cdecl FUN_004b5a80(void const*);
struct FUN_004d8530_Class
{
    virtual void const* f00();
    virtual void const* f01();
    virtual void const* f02();
    virtual void const* f03();
    virtual void const* f04();
    virtual void const* f05();
    virtual void const* f06();
    virtual void const* f07();
    virtual void const* f08();
    virtual void const* f09();
    virtual void const* f10();
    virtual void const* f11();
    virtual void const* f12();
    virtual void const* f13();
    virtual void const* f14();
    virtual void const* f15();
    virtual void const* f16();
    virtual void const* f17();
    virtual void const* f18();
    virtual void const* f19();
    virtual void const* f20();
    virtual void const* f21();
    virtual void const* f22();
    virtual void const* f23();
    virtual void const* f24();
    virtual void const* f25();
    virtual void const* f26();
    virtual void const* f27();
    virtual void const* f28();
    virtual void const* f29();
    virtual void const* f30();
    virtual void const* f31();
    virtual void const* f32();
    virtual void const* f33();
    virtual void const* f34();
    virtual void const* f35();
    virtual void const* f36();
    virtual void const* f37();
    virtual void const* f38();
    virtual void const* f39();
    virtual void const* f40();
    virtual void const* f41();
    virtual void const* f42();
    virtual void const* f43();
    virtual void const* f44();
    virtual void const* f45();
    virtual void const* f46();
    virtual void const* f47();
    virtual void const* f48();
    virtual void const* f49();
    virtual void const* f50();
    virtual void const* f51();
    virtual void const* f52();
    void* __thiscall FUN_004d8530();
};
// Returns the result of FUN_004b5a80 called on the object returned by virtual slot f52.
// @fnv 0x004d8530
void* __thiscall FUN_004d8530_Class::FUN_004d8530()
{
    return FUN_004b5a80(f52());
}

struct FUN_004d8560_Inner
{
    virtual void f0();
    virtual void* f1();
};
struct FUN_004d8560_Outer
{
    char _0[0x10];
    FUN_004d8560_Inner _10;
};
struct ScriptLocalsX
{
    FUN_004d8560_Outer* GetLocalData();
};
struct FUN_004d8560_StandIn
{
    void* __thiscall GetInnerVirtualResult();
};
// @fnv 0x004d8560
void* __thiscall FUN_004d8560_StandIn::GetInnerVirtualResult()
{
    FUN_004d8560_Outer* result = ((ScriptLocalsX*)this)->GetLocalData();
    return result ? result->_10.f1() : 0;
}

namespace fnv_004d8630 {
struct ScriptLocalsX
{
    void* __thiscall GetLocalData();
};
struct FUN_004d8630_Class
{
    bhkShape* __thiscall GetShape();
};
// @fnv 0x004d8630
bhkShape* __thiscall FUN_004d8630_Class::GetShape()
{
    void* p = ((ScriptLocalsX*)this)->GetLocalData();
    return FUN_004a3a40(p ? ((FUN_004d8670_Class*)p)->GetListNext() : 0);
}
}  // namespace fnv_004d8630

void* __cdecl NiMalloc(unsigned int size);
void* __cdecl memset(void* dest, int value, unsigned int count);

struct FUN_004d8fa0_Class
{
    int* m_p0;
    unsigned int m_i4;
    void* m_p8;
    unsigned int m_iC;
    FUN_004d8fa0_Class* FUN_004d9000(unsigned int size);
};

// Sets m_p0 to DAT_01021004, stores size in m_i4, allocates m_i4*4 bytes into m_p8, zeroes them, and returns this.
// @fnv 0x004d9000
FUN_004d8fa0_Class* FUN_004d8fa0_Class::FUN_004d9000(unsigned int size)
{
    m_p0 = &DAT_01021004;
    m_i4 = size;
    m_iC = 0;
    unsigned int a = m_i4 * 4;
    m_p8 = NiMalloc(a);
    memset(m_p8, 0, m_i4 * 4);
    return this;
}

void __cdecl _Deallocate(void*);
struct FUN_004d9130_Class
{
    void* __thiscall FUN_004d9130(unsigned int flags);
};
// @fnv 0x004d9130
void* __thiscall FUN_004d9130_Class::FUN_004d9130(unsigned int flags)
{
    ((FUN_004d90d0_Class*)this)->FUN_004d90d0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void __cdecl _Deallocate(void*);
struct FUN_004d91e0_Class : public FUN_004d9190_Class
{
    void* __thiscall FUN_004d91e0(unsigned int flags);
};
// Calls FUN_004d91b0, then frees this with _Deallocate if flags has bit 1 set, and returns this.
// @fnv 0x004d91e0
void* __thiscall FUN_004d91e0_Class::FUN_004d91e0(unsigned int flags)
{
    FUN_004d91b0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void Deallocate(void* p);

struct FUN_004d9380_Class
{
    char m_p0;
    void* m_p4;
    void __thiscall FreeAndClear();
};
// Deallocates the pointer stored in m_p4, then clears m_p0 and m_p4.
// @fnv 0x004d9380
void __thiscall FUN_004d9380_Class::FreeAndClear()
{
    void* p = m_p4;
    Deallocate(p);
    m_p0 = 0;
    m_p4 = 0;
}

extern unsigned char DAT_011f4508;
// @fnv 0x004dc010
void FUN_004dc010(unsigned char value)
{
    DAT_011f4508 = value;
}

extern bool DAT_011a9594;
// @fnv 0x004dc050
void FUN_004dc050(bool value)
{
    DAT_011a9594 = value;
}

extern unsigned char DAT_011f9180;

// @fnv 0x004dc090
void FUN_004dc090(unsigned char value)
{
    DAT_011f9180 = value;
}

extern int DAT_011f91c0;
extern int DAT_011f948c;
unsigned int __cdecl BSStringCapacityMaximum(unsigned int a, unsigned int b);
unsigned int __cdecl FUN_0042f5a0(unsigned int a, unsigned int b);
// Stores into DAT_011f948c the BSStringCapacityMaximum of 0 and FUN_0042f5a0 of a mask derived from DAT_011f91c0 and a.
// @fnv 0x004dc0c0
void __cdecl SetBSStringCapacity(unsigned int a)
{
    DAT_011f948c = BSStringCapacityMaximum(0, FUN_0042f5a0((DAT_011f91c0 < 5) - 1 & 2, a));
}

extern int DAT_011f916c;

// @fnv 0x004dc100
void __cdecl FUN_004dc100(int value)
{
    DAT_011f916c = value;
}

struct TgtOps
{
    void* GetPosition();
};
struct FUN_004dc120_StandIn
{
    TgtOps* __thiscall FUN_004dc160(int a);
    void* __thiscall FUN_004dc120(int a);
};
// @fnv 0x004dc120
void* __thiscall FUN_004dc120_StandIn::FUN_004dc120(int a)
{
    TgtOps* p = FUN_004dc160(a);
    if (p)
    {
        return p->GetPosition();
    }
    else
    {
        return 0;
    }
}

struct FUN_004dc160_StandIn
{
    unsigned int FUN_004dc160(int a);
};
// Returns the object stored at offset 0x460 when a equals 1, otherwise the object at 0x464, if its HasNonZeroValue check passes; else returns 0.
// @fnv 0x004dc160
unsigned int FUN_004dc160_StandIn::FUN_004dc160(int a)
{
    if (a == 1)
    {
        if ((unsigned char)((FUN_004dc1c0_Class*)*(unsigned int*)((char*)this + 0x460))->HasNonZeroValue())
            return *(unsigned int*)((char*)this + 0x460);
        else
            return 0;
    }
    else
    {
        if ((unsigned char)((FUN_004dc1c0_Class*)*(unsigned int*)((char*)this + 0x464))->HasNonZeroValue())
            return *(unsigned int*)((char*)this + 0x464);
        else
            return 0;
    }
}

struct GlobalObject_004a4a40
{
    int GetCellStandValue();
};
extern GlobalObject_004a4a40 g_011c738c;
// @fnv 0x004dc210
int __cdecl FUN_004dc210()
{
    return g_011c738c.GetCellStandValue();
}

struct CellStand
{
    int GetCellStandValue();
};
struct GlobalObject_0045cfe0
{
    CellStand m_cell;
};
extern GlobalObject_0045cfe0 g_011c7100;

// @fnv 0x004dc2b0
void __cdecl FUN_004dc2b0()
{
    g_011c7100.m_cell.GetCellStandValue();
}

extern float DAT_0118945c;
extern float DAT_011ad83c;
extern char DAT_011c6fb8;
extern double _gModifierZero;
// Stores value into DAT_0118945c and DAT_011ad83c and sets DAT_011c6fb8 to 1 when value differs from DAT_0118945c and is greater than _gModifierZero.
// @fnv 0x004dc2d0
void __cdecl FUN_004dc2d0(float value)
{
    if (DAT_0118945c != value && value > _gModifierZero)
    {
        DAT_0118945c = value;
        DAT_011c6fb8 = 1;
        DAT_011ad83c = value;
    }
}

struct Flt
{
    operator unsigned int();
};
struct Date
{
    ~Date();
};
struct NiNode;
extern NiPointer<NiNode> g_011dee84;
// @fnv 0x004dc560
void FUN_004dc560()
{
    ((Date*)((Flt*)&g_011dee84)->Flt::operator unsigned int())->Date::~Date();
    ((GO*)&g_011dee84)->GO::operator=((void*)0);
}

namespace fnv_004dc590 {
struct Flt
{
    operator unsigned int();
};
struct Date
{
    ~Date();
};
struct GlobalObject_00633c90
{
    char _pad;
};
extern GlobalObject_00633c90 g_011deca4;
// Destroys the Date object held by g_011deca4 and then assigns null to it.
// @fnv 0x004dc590
void __cdecl FUN_004dc590()
{
    ((Date*)((Flt*)&g_011deca4)->operator unsigned int())->Date::~Date();
    ((GO*)&g_011deca4)->operator=((void*)0);
}
}  // namespace fnv_004dc590

extern "C" unsigned char __cdecl FUN_00446e10(void);
struct S0042fa20
{
    S0042fa20* FUN_0045ce80(int);
};
extern S0042fa20 g_011c75d4;
extern S0042fa20 g_011c7654;

// If FUN_00446e10 returns false, calls FUN_0045ce80 on g_011c75d4 with a and on g_011c7654 with b.
// @fnv 0x004dc6e0
void __cdecl FUN_004dc6e0(int aiFirst, int aiSecond)
{
    if (!FUN_00446e10())
    {
        g_011c75d4.FUN_0045ce80(aiFirst);
        g_011c7654.FUN_0045ce80(aiSecond);
    }
}

struct FUN_004dcd30_Class
{
    FUN_004dcd60_Class* __thiscall FUN_004dc160(int p);
    unsigned char __thiscall FUN_004dcd30(int p);
};
// @fnv 0x004dcd30
unsigned char __thiscall FUN_004dcd30_Class::FUN_004dcd30(int p)
{
    FUN_004dcd60_Class* ptr = FUN_004dc160(p);
    if (!ptr)
        return 0;
    return ptr->GetByteAt140();
}

struct G7d1
{
    bool GetBoolValue();
};
G7d1 g_011c726c;
// @fnv 0x004dcda0
void FUN_004dcda0()
{
    g_011c726c.GetBoolValue();
}

struct MyArr_GetAt
{
    unsigned int* GetAt(int);
};
struct FUN_004dcdf0_Class
{
    int _0;
    union
    {
        Arr a;
        MyArr_GetAt m;
    } _4;
    unsigned int __thiscall FUN_004dcdf0(unsigned int index);
};
__pragma(comment(linker, "/alternatename:?GetAt@MyArr_GetAt@@QAEPAIH@Z=?GetAt@Arr@@QAEPAIH@Z"))
    // Returns the element at index from the array if index is within bounds, otherwise returns 0.
// @fnv 0x004dcdf0
    unsigned int __thiscall FUN_004dcdf0_Class::FUN_004dcdf0(unsigned int index)
{
    if (index < _4.a.GetSize())
        return *(_4.m.GetAt((int)index));
    return 0;
}

// If the pointer stored at p is non-null, deallocates it and sets the stored pointer to null.
// @fnv 0x004dd270
void __stdcall ClearAndFreePointer(void* apPointer)
{
    if (*(void***)apPointer)
    {
        void* old = *(void***)apPointer;
        Deallocate(old);
        *(void***)apPointer = 0;
    }
}

void __cdecl _Deallocate(void*);
struct FUN_004de550_StandIn
{
    void __thiscall FUN_0045d240();
    void* __thiscall FUN_004de550(unsigned int);
};
// @fnv 0x004de550
void* __thiscall FUN_004de550_StandIn::FUN_004de550(unsigned int flags)
{
    FUN_0045d240();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct NiTexture;
struct SkyTextureManager
{
    static void __cdecl LoadTextureFromPath(NiPointer<NiTexture>*, char const*);
};
extern NiPointer<NiTexture> DAT_011c7804[];
// @fnv 0x004deed0
bool __cdecl FUN_004deed0(char const* a, unsigned char aucIndex)
{
    if (aucIndex > 2)
        return false;
    else
        SkyTextureManager::LoadTextureFromPath(&DAT_011c7804[aucIndex], a);
    return true;
}

struct FUN_004d4f70
{
    unsigned int m_uiCount;
    int m_iParam;
    float** m_ppfA;
    float** m_ppfB;

    FUN_004d4f70(unsigned int ItemUpdateArray, int iParam);
};

// Stores the count and param, allocates two pointer arrays and a zeroed float block, then splits the block into per-index A and B slices.
// @fnv 0x004d4f70
FUN_004d4f70::FUN_004d4f70(unsigned int auiCount, int iParam)
{
    m_uiCount = auiCount;
    m_iParam = iParam;
    m_ppfA = new float*[m_uiCount];
    m_ppfB = new float*[m_uiCount];
    float* pfBlock = new float[m_uiCount * 0x110];
    memset(pfBlock, 0, m_uiCount * 0x440);
    for (unsigned int i = 0; i < m_uiCount; i++)
    {
        m_ppfA[i] = pfBlock;
        pfBlock += 16;
        m_ppfB[i] = pfBlock;
        pfBlock += 17;
    }
}

extern "C" void __cdecl FormHeap_Free(void*);

struct FUN_004d5080_Class
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;

    void __thiscall FUN_004d5080();
};

// @fnv 0x004d5080
void __thiscall FUN_004d5080_Class::FUN_004d5080()
{
    void* fourthValue = *(void**)this->unk08;
    void* secondValue = fourthValue;
    FormHeap_Free(secondValue);

    void* thirdValue = this->unk08;
    FormHeap_Free(thirdValue);

    void* firstValue = this->unk0C;
    FormHeap_Free(firstValue);
}

struct GlobalObject_0044f440
{
    float* Float();
};
extern GlobalObject_0044f440 g_011c6528;
extern GlobalObject_0044f440 g_011c6534;
extern GlobalObject_0044f440 g_011c651c;

struct Buf
{
    unsigned int m0;
    unsigned int m4;
    float** p8;
    float** pC;
    Buf(unsigned int a, unsigned int b);
    ~Buf();
};

// Reads a count and type from a buffer, allocates a Buf, fills its float arrays from the buffer, scales three entries by globals, and returns it or 0 on failure.
// @fnv 0x004d5570
void* ReadBufFromMemory(char* pData, unsigned int uiSize)
{
    if (pData == 0 || uiSize == 0)
        return 0;

    unsigned int pos5 = 0;
    unsigned int count8;
    Buf* result2 = 0;

    if (pos5 + 4 > uiSize)
    {
        delete result2;
        return 0;
    }
    count8 = *(unsigned int*)(pData + pos5);
    pos5 += 4;
    if (count8 > 1000000)
        return 0;
    if (pos5 + 4 > uiSize)
    {
        delete result2;
        return 0;
    }
    unsigned int type = *(unsigned int*)(pData + pos5);
    pos5 += 4;
    result2 = new Buf(count8, type);
    for (unsigned int i5 = 0; i5 < count8; i5++)
    {
        for (unsigned int j2 = 0; j2 < 16; j2++)
        {
            if (pos5 + 4 > uiSize)
            {
                delete result2;
                return 0;
            }
            result2->p8[i5][j2] = *(float*)(pData + pos5);
            pos5 += 4;
        }
        for (unsigned int k = 0; k < 17; k++)
        {
            if (pos5 + 4 > uiSize)
            {
                delete result2;
                return 0;
            }
            result2->pC[i5][k] = *(float*)(pData + pos5);
            pos5 += 4;
        }
        result2->pC[i5][14] = result2->pC[i5][14] * *g_011c6528.Float();
        result2->pC[i5][15] = result2->pC[i5][15] * *g_011c6534.Float();
        result2->pC[i5][16] = result2->pC[i5][16] * *g_011c651c.Float();
    }
    return result2;
}

extern double DAT_010209a8;

struct FUN_004d5a90_Class
{
    int m_i0;
    int m_i4;
    float GetNegativeMagnitude();
};

// Returns the absolute value of m_i4 scaled by DAT_010209a8 when m_i4 is negative, otherwise 0.0.
// @fnv 0x004d5a90
float FUN_004d5a90_Class::GetNegativeMagnitude()
{
    return (float)(m_i4 < 0 ? (double)(m_i4 * -1) * DAT_010209a8 : 0.0);
}

extern "C" int __cdecl sprintf_s(char* destination, unsigned int size, const char* format, ...);
extern const char DAT_01020d58[];

struct FUN_0040c150
{
    int value0;
    int value4;
    int value8;
    FUN_0040c150(char* text, int index);
};

struct FUN_004d5b60
{
    FUN_0040c150* object;
    int value;
    FUN_004d5b60(int index, int number, int extra);
};

// Formats number into a 13-byte buffer, stores extra in value, and constructs a FUN_0040c150 from the text and index.
// @fnv 0x004d5b60
FUN_004d5b60::FUN_004d5b60(int index, int number, int extra)
{
    value = extra;
    char* text = new char[13];
    sprintf_s(text, 13, DAT_01020d58, number);
    object = new FUN_0040c150(text, index);
}

namespace fnv_004d5c80 {
struct FUN_004d5b60
{
    char* m_p0;
    unsigned short m_w4;
    unsigned short m_w6;
    FUN_004d5b60(const char* name, unsigned int index, unsigned short flags);
};
extern void* DAT_011c6d50[43];
extern const char* DAT_01189280[43];

// @fnv 0x004d5c80
void* __fastcall InitNameTable(void* pThis)
{
    if (!DAT_011c6d50[0])
    {
        for (unsigned int i = 0; i < 43; i++)
        {
            DAT_011c6d50[i] = new FUN_004d5b60(DAT_01189280[i], i, 0);
        }
    }
    return pThis;
}
}  // namespace fnv_004d5c80

extern void* DAT_011c6d50[43];

extern "C" void* __cdecl memset(void* dest, int value, unsigned int count);

// Iterates DAT_011c6d50, calls FUN_004d5dd0(1) on each non-null entry, then zeroes the 43-entry array with memset.
// @fnv 0x004d5d50
void __cdecl ClearGlobalArray(void)
{
    for (int i = 0; i < 43; i++)
    {
        if (DAT_011c6d50[i] != 0)
        {
            void* v = DAT_011c6d50[i];
            void* w = v;
            void* r;
            if (w != 0)
            {
                r = ((FUN_004d5dd0_Class*)w)->FUN_004d5dd0(1);
            }
            else
            {
                r = 0;
            }
        }
    }
    memset(DAT_011c6d50, 0, 172);
}

// @fnv 0x004d5e00
int __cdecl FUN_004d5e00()
{
    return (int)1003u;
}

extern int DAT_011f36f4;
extern int DAT_011f36f8;
void __cdecl _Deallocate(void* p);

struct FUN_004d9070
{
    ~FUN_004d9070();
};

struct FUN_004d62a0_Class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    FUN_004d9070 m_18;
    int m_1C;
    int m_20;
    int m_24;
    int m_28;
    void* m_p2C;

    void __thiscall FUN_004d7490();
    void __thiscall FUN_004d7470();
    void __thiscall FUN_004d7440();
    ~FUN_004d62a0_Class();
};

// Frees m_p2C, calls the three cleanup methods, then resets DAT_011f36f8 and DAT_011f36f4 to zero.
// @fnv 0x004d62a0
FUN_004d62a0_Class::~FUN_004d62a0_Class()
{
    void* p = m_p2C;
    _Deallocate(p);
    FUN_004d7490();
    FUN_004d7470();
    FUN_004d7440();
    DAT_011f36f8 = 0;
    DAT_011f36f4 = DAT_011f36f8;
}

struct InitCommonControls4d63
{
    unsigned long m_ulSize;
    unsigned long m_ulICC;
};
struct Rect4d63
{
    long left;
    long top;
    long right;
    long bottom;
};
struct WndClass4d63
{
    unsigned int style;
    long(__stdcall* lpfnWndProc)(void*, unsigned int, unsigned int, long);
    int cbClsExtra;
    int cbWndExtra;
    void* hInstance;
    void* hIcon;
    void* hCursor;
    void* hbrBackground;
    const char* lpszMenuName;
    const char* lpszClassName;
};

extern int(__stdcall* DAT_00fdf024)(InitCommonControls4d63*);
extern void*(__stdcall* DAT_00fdf280)(void*, const char*);
extern void*(__stdcall* DAT_00fdf2a0)(void*, const char*);
extern void*(__stdcall* DAT_00fdf03c)(int);
extern unsigned short(__stdcall* DAT_00fdf2b4)(const WndClass4d63*);
extern void*(__stdcall* DAT_00fdf2b8)(unsigned long, const char*, const char*, unsigned long, int, int, int, int, void*,
                                      void*, void*, void*);
extern int(__stdcall* DAT_00fdf2bc)(void*, Rect4d63*);
const char* PrepareScriptMessage(const char* pcText, bool bFlag);
extern char DAT_01189338[];
long __stdcall FUN_004d75b0(void* hWnd, unsigned int auiMessage, unsigned int wParam, long lParam);

struct TreeCtrl4d63
{
    void* m_hInstance;
    int unk04;
    void* m_hWnd;
    void* m_hTreeWnd;
    int unk10[7];
    const char* m_pcTitle;
    void CreateTreeWindows(int iX, int iY, int iWidth, int iHeight);
};

// @fnv 0x004d6340
void TreeCtrl4d63::CreateTreeWindows(int iX, int iY, int iWidth, int iHeight)
{
    InitCommonControls4d63 kInitData;
    kInitData.m_ulSize = 8;
    kInitData.m_ulICC = 2;
    DAT_00fdf024(&kInitData);

    WndClass4d63 kClass;
    kClass.style = 3;
    kClass.lpfnWndProc = FUN_004d75b0;
    kClass.cbClsExtra = 0;
    kClass.cbWndExtra = 0;
    kClass.hInstance = m_hInstance;
    kClass.hIcon = DAT_00fdf280(0, (const char*)0x7F00);
    kClass.hCursor = DAT_00fdf2a0(0, (const char*)0x7F00);
    kClass.hbrBackground = DAT_00fdf03c(0);
    kClass.lpszClassName = PrepareScriptMessage(DAT_01189338, false);
    kClass.lpszMenuName = 0;
    DAT_00fdf2b4(&kClass);

    unsigned long ulStyle = 0xCE0200;
    m_hWnd = DAT_00fdf2b8(0, PrepareScriptMessage(DAT_01189338, false), m_pcTitle, ulStyle, iX, iY, iWidth, iHeight, 0,
                          0, m_hInstance, 0);

    ulStyle = 0x50010007;
    Rect4d63 pDataToSerialize;
    DAT_00fdf2bc(m_hWnd, &pDataToSerialize);
    m_hTreeWnd = DAT_00fdf2b8(0, "SysTreeView32", "", ulStyle, 0, 0, pDataToSerialize.right - pDataToSerialize.left + 1,
                              pDataToSerialize.bottom - pDataToSerialize.top + 1, m_hWnd, 0, m_hInstance, 0);
}

struct ClearMap64
{
    int unk00;
    void __thiscall FUN_00438af0();
};
const char* __cdecl FUN_00464f30(const char* value, bool format);
typedef int(__stdcall* SendMessageResult64)(void*, int, int, int);
extern void(__stdcall* DAT_00fdf288)(void*, int);
extern void(__stdcall* DAT_00fdf284)(void*);
struct Header64
{
    int primary, secondary, tertiary, unused0c, unused10, unused14;
};
struct Params64
{
    const char* message;
    int unused04;
    int flags;
    int flagsCopy;
    int unused10;
    int number;
    int status18;
    int context1c;
    int callback20;
    int source24;
};
struct Owner64
{
    void* unk00;
    void* unk04;
    void* window;
    void* dialog;
    int result;
    int hwndContext;
    ClearMap64 messageMap;
    int unk1c, unk20, unk24, unk28;
    const char* defaultText;
    void __thiscall FUN_004d66d0(int a, int b);
    void __thiscall FUN_004d64c0(int value, const char* text);
};
// @fnv 0x004d64c0
void Owner64::FUN_004d64c0(int value, const char* text)
{
    messageMap.FUN_00438af0();
    DAT_00fdf28c(dialog, 0x1109, 0, hwndContext);
    Header64 header;
    header.secondary = 0xffff0002;
    header.tertiary = 0x27;
    header.primary = 0xffff0000;
    Params64 params;
    params.message = text ? FUN_00464f30(text, false) : defaultText;
    params.flags = 0;
    params.flagsCopy = params.flags;
    params.number = value;
    result = ((SendMessageResult64)DAT_00fdf28c)(dialog, 0x1100, 0, (int)&header);
    FUN_004d66d0(result, value);
    DAT_00fdf288(window, 10);
    DAT_00fdf284(window);
}

extern void(__stdcall* DAT_00fdf01c)(void*);
struct FUN_004d7470_StandIn
{
    char _0[20];
    void* p14;
    void __thiscall FUN_004d7470();
};
// @fnv 0x004d7470
void __thiscall FUN_004d7470_StandIn::FUN_004d7470()
{
    DAT_00fdf01c(p14);
}

extern char DAT_011c6e10;
void __cdecl FUN_00403d30(void* destination, int pNodeValue, unsigned int size);
typedef int(__stdcall* SendTreeMessage)(void*, int, int, int);

struct FUN_004d74c0_Value
{
    int FUN_00453470();
};
struct FUN_004d74c0_Node
{
    virtual void f00();
    virtual void f04();
    virtual void f08();
    virtual FUN_004d74c0_Value* getValue();
};
struct FUN_004d74c0_Item
{
    unsigned int mask;
    int handle;
    int state;
    int stateMask;
    char* text;
    int textCapacity;
    int image;
    int selectedImage;
    int children;
    FUN_004d74c0_Node* itemData;
    int integral;
    int stateEx;
    void* hwnd;
    int expandedImage;
};

// Walks the tree items from startingItem, and for each item whose node value passes FUN_00453470, expands it with expandFlags and recurses into its children.
// @fnv 0x004d74c0
void __cdecl ExpandTreeItemsRecursively(void* tree, int startingItem, int expandFlags)
{
    FUN_004d74c0_Node* node;
    FUN_004d74c0_Value* pNodeValue;
    FUN_004d74c0_Item item;

    FUN_00403d30(&item, 0, sizeof(item));
    item.mask = 13;
    item.text = &DAT_011c6e10;
    item.textCapacity = 260;

    item.handle = ((SendTreeMessage)DAT_00fdf28c)(tree, 0x110a, 4, startingItem);
    while (item.handle != 0)
    {
        if (((SendTreeMessage)DAT_00fdf28c)(tree, 0x110c, 0, (int)&item) != 0)
        {
            node = item.itemData;
            pNodeValue = 0;
            if (node != 0)
            {
                pNodeValue = node->getValue();
            }
            if (pNodeValue != 0)
            {
                if (pNodeValue->FUN_00453470() != 0)
                {
                    ((SendTreeMessage)DAT_00fdf28c)(tree, 0x1102, expandFlags, item.handle);
                    ExpandTreeItemsRecursively(tree, item.handle, expandFlags);
                }
            }
        }
        item.handle = ((SendTreeMessage)DAT_00fdf28c)(tree, 0x110a, 1, item.handle);
    }
}

int FUN_00406d30(char* pcDest, unsigned int uiSize, const char* pcSrc);
int FUN_00406d50(char* pcDest, unsigned int uiSize, const char* pcSrc);

class NiObject
{
  public:
    int m_aiObject[2];
};

class NiFixedString
{
  public:
    operator const char*() const;
    const char* m_kHandle;
};

struct NiUpdateData
{
    float m_fTime;
    bool m_bUpdate;
    bool m_bIsMultiThreaded;
    int m_pkUpdateProcess;
    NiUpdateData(float fTime, bool m_bUpdateEnabled, bool bIsMultiThreaded);
};

class NiAVObject : public NiObject
{
  public:
    void FUN_00450f90(bool bCulled);
    void FUN_00a5a040();
    void Update(NiUpdateData& kUpdateData);
    NiFixedString& GetName();
};

class NiStream
{
  public:
    NiStream();
    ~NiStream();
    void InsertObject(NiObject* pkObject);
    bool FUN_00a640b0(const char* pcFileName);
    int m_kNextStreamField[0x172];
};

// @fnv 0x004d78c0
int FUN_004d78c0(NiObject* pkObject, int iType, int iCommand)
{
    int iResult = 0;
    switch (iType)
    {
    case 0:
        iResult = 1;
        break;
    case 1:
        iResult = 1;
        break;
    case 2:
        break;
    case 3:
        if (pkObject)
        {
            NiAVObject* pkNode = (NiAVObject*)pkObject;
            if (iCommand == 0x70)
            {
                pkNode->FUN_00450f90(true);
                iResult = 1;
            }
            else if (iCommand == 0x71)
            {
                pkNode->FUN_00450f90(false);
                iResult = 1;
            }
            else if (iCommand == 0x72)
            {
                pkNode->FUN_00a5a040();
                NiUpdateData kUpdateData(0.0f, false, false);
                pkNode->Update(kUpdateData);
                iResult = 1;
            }
            else if (iCommand == 0x73)
            {
            }
            else if (iCommand == 0x7A)
            {
                const char* pcNodeName;
                NiStream kNiStream;
                kNiStream.InsertObject(pkNode);
                pcNodeName = pkNode->GetName();
                if (!pcNodeName)
                    pcNodeName = "NullObject";
                char acPath[0x104];
                FUN_00406d30(acPath, 0x104, "c:\\");
                FUN_00406d50(acPath, 0x104, pcNodeName);
                FUN_00406d50(acPath, 0x104, ".nif");
                kNiStream.FUN_00a640b0(acPath);
                iResult = 1;
            }
        }
        break;
    }
    return iResult;
}

struct NiObject;
struct NiRTTI
{
    const char* m_pcName;
    const NiRTTI* m_pBaseRTTI;
};
extern const NiRTTI DAT_012024e0;
NiObject* __cdecl FUN_00653270(const NiRTTI*, NiObject*);

const char* __cdecl PrepareScriptMessage(const char* msg, bool flag);

class BGSAddonNode;
struct Holder_004d9100 : public NiTArray<BGSAddonNode*, NiTMallocInterface<BGSAddonNode*> >
{
    Holder_004d9100(int a, int b);
};

struct NiTArray_Layout;
void __fastcall FUN_005e03d0(NiTArray_Layout*);

class ActorPathingMessageQueue;

struct Name
{
    const char* FUN_00559450() const;
};
struct ItemClass
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual Name& GetName();
    virtual void vfn_0c();
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
    virtual void FillHolders(Holder_004d9100* holder);
};

struct MsgStruct
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    const char* unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    void* unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
};

void __cdecl FUN_004add50(char* dst, const char* src, unsigned int count);

struct ObjClass : public FUN_004d7d50_StandIn
{
    ItemClass* __thiscall GetByIndex(unsigned int);
};

typedef int(__stdcall* DAT_00fdf28c_fn)(void*, int, int, void*);

struct HostClass
{
    int unk00;
    int unk04;
    int unk08;
    void* unk0C;
    void __thiscall SendModifierMessages(int a1, NiObject* a2);
};

// Resolves a2 to an ObjClass, then sends script messages for each item's name and each of its holders via DAT_00fdf28c.
// @fnv 0x004d7ab0
void __thiscall HostClass::SendModifierMessages(int a1, NiObject* apObject)
{
    MsgStruct n3;
    char i4[64];
    ItemClass* qB;
    unsigned int cnt2;
    unsigned int val;
    ObjClass* res;
    Holder_004d9100* b2;
    int bo;
    res = (ObjClass*)FUN_00653270(&DAT_012024e0, apObject);
    if (res)
    {
        b2 = new Holder_004d9100(0x80, 0x80);

        n3.unk04 = (int)0xffff0002;
        n3.unk08 = 0x27;
        n3.unk2C = apObject;
        n3.unk18 = PrepareScriptMessage("Modifiers", false);
        n3.unk20 = 5;
        n3.unk24 = n3.unk20;
        n3.unk00 = a1;

        bo = ((DAT_00fdf28c_fn)DAT_00fdf28c)(this->unk0C, 0x1100, 0, &n3);

        for (cnt2 = 0; cnt2 < res->FUN_004d7d50(); ++cnt2)
        {
            qB = res->GetByIndex(cnt2);
            if (qB)
            {
                FUN_004add50(i4, qB->GetName().FUN_00559450(), 0x3f);
                i4[63] = 0;

                n3.unk18 = PrepareScriptMessage(i4, false);
                n3.unk20 = 0;
                n3.unk24 = n3.unk20;
                n3.unk00 = bo;

                a1 = n3.unk00 = ((DAT_00fdf28c_fn)DAT_00fdf28c)(this->unk0C, 0x1100, 0, &n3);

                qB->FillHolders(b2);

                for (val = 0; val < b2->GetSize(); ++val)
                {
                    n3.unk18 = PrepareScriptMessage((const char*)b2->GetAt(val), false);
                    n3.unk20 = 6;
                    n3.unk24 = n3.unk20;
                    ((DAT_00fdf28c_fn)DAT_00fdf28c)(this->unk0C, 0x1100, 0, &n3);
                }

                FUN_005e03d0((NiTArray_Layout*)b2);
            }
        }

        delete b2;
    }
}

extern "C" char DAT_01267b70;
extern "C" char DAT_01020ebc;
struct Node7
{
    virtual void v0();
    virtual void v1();
    virtual void* v2();
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
    virtual void v24(void*);
    void* FUN_006fa820();
};
struct FUN_004d9100
{
    FUN_004d9100(int, int);
    virtual ~FUN_004d9100();
    char pad[12];
    unsigned GetShortAtOffsetA();
    char** FUN_00877a30(unsigned);
    void FUN_005e03d0();
};
Node7* __cdecl FUN_00653270(void*, Node7*);
const char* __cdecl FUN_00464f30(const char*, bool);
const char* __fastcall FUN_00559450(void*);
void __cdecl FUN_004add50(char*, const char*, unsigned);
struct Insert7
{
    void* parent;
    unsigned after, mask;
    unsigned item, state, stateMask;
    const char* text;
    int max, image, selected, children;
    Node7* param;
    int extra[4];
};
struct C7
{
    char pad[12];
    void* hwnd;
    void BuildTreeItems(void*, void*);
    void AddChildTreeItem(void* parent, Node7* node);
};
// @fnv 0x004d7df0
void C7::AddChildTreeItem(void* parent, Node7* node)
{
    Node7* casted7 = FUN_00653270(&DAT_01267b70, node);
    if (casted7)
    {
        FUN_004d9100* arr = new FUN_004d9100(128, 128);
        Insert7 ins;
        ins.after = 0xffff0002;
        ins.mask = 0x27;
        ins.param = node;
        ins.text = FUN_00464f30(&DAT_01020ebc, false);
        ins.image = 5;
        ins.selected = ins.image;
        ins.parent = parent;
        void* handle4 = ((void*(__stdcall*)(void*, unsigned, unsigned, Insert7*))DAT_00fdf28c)(hwnd, 0x1100, 0, &ins);
        char buffer[64];
        FUN_004add50(buffer, FUN_00559450(casted7->v2()), 63);
        buffer[63] = 0;
        ins.text = FUN_00464f30(buffer, false);
        ins.image = 0;
        ins.selected = ins.image;
        ins.parent = handle4;
        ins.parent = ((void*(__stdcall*)(void*, unsigned, unsigned, Insert7*))DAT_00fdf28c)(hwnd, 0x1100, 0, &ins);
        parent = ins.parent;
        node->v24(arr);
        unsigned index4;
        for (index4 = 0; index4 < arr->GetShortAtOffsetA(); index4++)
        {
            ins.text = FUN_00464f30(*arr->FUN_00877a30(index4), false);
            ins.image = 6;
            ins.selected = ins.image;
            ((void*(__stdcall*)(void*, unsigned, unsigned, Insert7*))DAT_00fdf28c)(hwnd, 0x1100, 0, &ins);
        }
        arr->FUN_005e03d0();
        void* obj2 = casted7->FUN_006fa820();
        BuildTreeItems(parent, obj2);
        delete arr;
    }
}

namespace fnv_004d80b0 {
struct FUN_004d9100
{
    virtual ~FUN_004d9100();
    unsigned int length;
    unsigned int capacity;
    void* elements;
    FUN_004d9100(unsigned int initialCapacity, unsigned int growthCapacity);
    unsigned int GetShortAtOffsetA();
    void** FUN_00877a30(unsigned int index);
    void FUN_005e03d0();
};
struct FNVObjectName
{
    void* FUN_00559450();
};
struct FNVTreeNode
{
    virtual void* f0();
    virtual void* f1();
    virtual FNVObjectName* GetName();
    virtual void* f3();
    virtual void* f4();
    virtual void* f5();
    virtual void* f6();
    virtual void* f7();
    virtual void* f8();
    virtual void* f9();
    virtual void* f10();
    virtual void* f11();
    virtual void* f12();
    virtual void* f13();
    virtual void* f14();
    virtual void* f15();
    virtual void* f16();
    virtual void* f17();
    virtual void* f18();
    virtual void* f19();
    virtual void* f20();
    virtual void* f21();
    virtual void* f22();
    virtual void* f23();
    virtual void CollectChildren(FUN_004d9100* result);
};
struct FNVTreeItem
{
    unsigned int mask;
    void* itemHandle;
    unsigned int state;
    unsigned int stateMask;
    char* text;
    int textCapacity;
    int image;
    int selectedImage;
    int nodeArray;
    FNVTreeNode* node;
    int integralHeight;
    unsigned int extendedState;
    void* ownerWindow;
    int expandedImage;
};
struct FNVTreeInsert
{
    void* parent;
    void* insertAfter;
    FNVTreeItem item;
};
struct FNVChildLink
{
    FNVObjectName* FUN_006815c0();
    FNVChildLink* FUN_00726070();
};
struct FNVTypeA
{
    FNVObjectName* FUN_004ae6a0();
};
struct FNVTypeB
{
    int GetNodeCount();
    FNVChildLink* FUN_007d6bb0();
};
struct FNVTypeC
{
    FNVTreeNode* GetShape();
};
struct FNVTypeD
{
    unsigned int GetInnerVirtualResult();
    FNVTreeNode* FUN_004d85a0(unsigned int index);
};
struct FNVTypeE
{
    FNVTreeNode* FUN_004d8510();
};
struct FNVTypeF
{
    FNVTreeNode* FUN_004d8530();
};
extern unsigned char DAT_01268110;
extern unsigned char DAT_012681c0;
extern unsigned char DAT_01268100;
extern unsigned char DAT_012681b4;
extern unsigned char DAT_012681a8;
extern unsigned char DAT_01268198;
extern unsigned char DAT_0126818c;
extern void* __cdecl FUN_00653270(const void*, void*);
extern char* __cdecl FUN_00464f30(const void*, int);
extern void __cdecl FUN_004add50(char*, const char*, unsigned int);
struct FUN_004d80b0_Class
{
    void* m_object;
    void* m_pOwnerObject;
    void* m_pTreeNode;
    void* m_treeWindow;
    void __thiscall BuildTreeItems(void* parent, FNVTreeNode* node);
};
// Inserts a tree item for node and its children into m_treeWindow, then recurses into related nodes found via several type lookups.
// @fnv 0x004d80b0
void FUN_004d80b0_Class::BuildTreeItems(void* parent, FNVTreeNode* node)
{
    unsigned int childIndex;
    FUN_004d9100* nodeArray;
    FNVTypeA* partA;
    if (node)
    {
        nodeArray = new FUN_004d9100(128, 128);
        char displayName[64];
        {
            FNVTreeInsert insertInfo;
            insertInfo.insertAfter = (void*)0xffff0002;
            insertInfo.item.mask = 0x27;
            insertInfo.item.node = node;
            FUN_004add50(displayName, (const char*)node->GetName()->FUN_00559450(), 63);
            displayName[63] = 0;
            insertInfo.item.text = FUN_00464f30(displayName, 0);
            insertInfo.item.image = 0;
            insertInfo.item.selectedImage = insertInfo.item.image;
            insertInfo.parent = parent;
            insertInfo.parent =
                ((void*(__stdcall*)(void*, int, int, int))DAT_00fdf28c)(m_treeWindow, 0x1100, 0, (int)&insertInfo);
            parent = insertInfo.parent;
            node->CollectChildren(nodeArray);
            for (childIndex = 0; childIndex < nodeArray->GetShortAtOffsetA(); ++childIndex)
            {
                insertInfo.item.text = FUN_00464f30(*nodeArray->FUN_00877a30(childIndex), 0);
                insertInfo.item.image = 6;
                insertInfo.item.selectedImage = insertInfo.item.image;
                DAT_00fdf28c(m_treeWindow, 0x1100, 0, (int)&insertInfo);
            }
            nodeArray->FUN_005e03d0();
        }
        partA = (FNVTypeA*)FUN_00653270(&DAT_01268110, node);
        if (partA)
        {
            FNVTreeNode* childNode = (FNVTreeNode*)partA->FUN_004ae6a0();
            BuildTreeItems(parent, childNode);
            FNVTypeB* partB = (FNVTypeB*)FUN_00653270(&DAT_012681c0, node);
            if (partB && partB->GetNodeCount())
            {
                FNVChildLink* link = partB->FUN_007d6bb0();
                while (link && link->FUN_006815c0()->FUN_00559450())
                {
                    BuildTreeItems(parent, (FNVTreeNode*)link->FUN_006815c0()->FUN_00559450());
                    link = link->FUN_00726070();
                }
            }
        }
        else
        {
            FNVTypeD* partD = (FNVTypeD*)FUN_00653270(&DAT_01268100, node);
            if (partD)
            {
                FNVTypeC* partC = (FNVTypeC*)FUN_00653270(&DAT_012681b4, partD);
                if (partC)
                {
                    BuildTreeItems(parent, partC->GetShape());
                }
                else
                {
                    FNVTypeD* partE = (FNVTypeD*)FUN_00653270(&DAT_012681a8, partD);
                    if (partE)
                    {
                        unsigned int count = partE->GetInnerVirtualResult();
                        if (count)
                        {
                            for (unsigned int index = 0; index < count; ++index)
                            {
                                BuildTreeItems(parent, partE->FUN_004d85a0(index));
                            }
                        }
                    }
                }
            }
            else
            {
                FNVTypeE* partE = (FNVTypeE*)FUN_00653270(&DAT_01268198, node);
                if (partE)
                {
                    BuildTreeItems(parent, partE->FUN_004d8510());
                }
                else
                {
                    FNVTypeF* partF = (FNVTypeF*)FUN_00653270(&DAT_0126818c, node);
                    if (partF)
                    {
                        BuildTreeItems(parent, partF->FUN_004d8530());
                    }
                }
            }
        }
        delete nodeArray;
    }
}
}  // namespace fnv_004d80b0

struct FUN_0062e150_Obj
{
    int* FUN_0062e150(int a1);
};
struct FUN_004d8610_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    FUN_0062e150_Obj sub18;
    int GetSubValue(int arg);
};
// @fnv 0x004d8610
int FUN_004d8610_cls::GetSubValue(int arg)
{
    return *sub18.FUN_0062e150(arg);
}

struct TreeItem4d86
{
    unsigned int mask;
    void* hItem;
    unsigned int state;
    unsigned int stateMask;
    const char* pszText;
    int cchTextMax;
    int iImage;
    int iSelectedImage;
    int cChildren;
    long lParam;
    int iIntegral;
    unsigned int uStateEx;
    void* hwnd;
    int iExpandedImage;
};

struct TreeInsert4d86
{
    void* hParent;
    void* hInsertAfter;
    TreeItem4d86 item;
};

typedef void*(__stdcall* SendMessage4d86)(void*, int, int, int);

const char* PrepareScriptMessage(const char* pcText, bool bFlag);

struct MediaSet4d86
{
    int FUN_008041a0();
};

struct Palette4d86;

struct Object4d86
{
    Palette4d86* GetStringAtOffset();
    unsigned int FUN_00495d00();
    MediaSet4d86* FUN_00495d20(unsigned int uiIndex);
};

struct TreeCtrl4d86
{
    void* m_hInstance;
    int unk04;
    void* m_hWnd;
    void* m_hTreeWnd;
    void AddNameItems(void* hParent, Palette4d86* pkPalette);
    void FUN_004d8b90(void* hParent, MediaSet4d86* pkSet);
    void PopulateObjectTree(void* hParent, Object4d86* pkObject);
};

// Adds tree items for the object's palette, active sequences and inactive sequences, recursing into each palette and media set.
// @fnv 0x004d8690
void TreeCtrl4d86::PopulateObjectTree(void* hParentItem, Object4d86* pkObject)
{
    if (pkObject)
    {
        TreeInsert4d86 kInsert;
        void* hItem;
        kInsert.hInsertAfter = (void*)0xFFFF0002;
        kInsert.item.mask = 0x27;
        kInsert.item.lParam = (long)pkObject;
        if (pkObject->GetStringAtOffset())
        {
            kInsert.item.pszText = PrepareScriptMessage("Object Palette", false);
            kInsert.item.iImage = 5;
            kInsert.item.iSelectedImage = kInsert.item.iImage;
            kInsert.hParent = hParentItem;
            void* hPaletteItem = ((SendMessage4d86)DAT_00fdf28c)(m_hTreeWnd, 0x1100, 0, (int)&kInsert);
            AddNameItems(hPaletteItem, pkObject->GetStringAtOffset());
        }
        kInsert.item.pszText = PrepareScriptMessage("Active Sequences", false);
        kInsert.item.iImage = 5;
        kInsert.item.iSelectedImage = kInsert.item.iImage;
        kInsert.hParent = hParentItem;
        hItem = ((SendMessage4d86)DAT_00fdf28c)(m_hTreeWnd, 0x1100, 0, (int)&kInsert);
        for (unsigned int i = 0; i < pkObject->FUN_00495d00(); i++)
        {
            MediaSet4d86* pkSet = pkObject->FUN_00495d20(i);
            if (pkSet && pkSet->FUN_008041a0())
                FUN_004d8b90(hItem, pkSet);
        }
        kInsert.item.pszText = PrepareScriptMessage("Inactive Sequences", false);
        hItem = ((SendMessage4d86)DAT_00fdf28c)(m_hTreeWnd, 0x1100, 0, (int)&kInsert);
        for (unsigned int uiIndex2 = 0; uiIndex2 < pkObject->FUN_00495d00(); uiIndex2++)
        {
            MediaSet4d86* pkSet = pkObject->FUN_00495d20(uiIndex2);
            if (pkSet && !pkSet->FUN_008041a0())
                FUN_004d8b90(hItem, pkSet);
        }
    }
}

struct TreeItem4d88
{
    unsigned int mask;
    void* hItem;
    unsigned int state;
    unsigned int stateMask;
    const char* pszText;
    int cchTextMax;
    int iImage;
    int iSelectedImage;
    int cChildren;
    long lParam;
    int iIntegral;
    unsigned int uStateEx;
    void* hwnd;
    int iExpandedImage;
};

struct TreeInsert4d88
{
    void* hParent;
    void* hInsertAfter;
    TreeItem4d88 item;
};

typedef void*(__stdcall* SendMessage4d88)(void*, int, int, int);

extern const char DAT_01020f14[];
const char* PrepareScriptMessage(const char* pcText, bool bFlag);

struct Target4d88
{
    const char** FUN_00413f40();
};

struct Interp4d88;

struct BlendInterp4d88
{
    unsigned short GetField3C();
    Target4d88* GetEntry(unsigned short usIndex);
    Interp4d88* GetExtraDataAt(unsigned short usIndex);
};

struct TreeCtrl4d88
{
    void* m_hInstance;
    int unk04;
    void* m_hWnd;
    void* m_hTreeWnd;
    void AddNameItems(void* hParent, Interp4d88* pkInterp);
    void AddBlendInterpTreeItems(void* hParent, BlendInterp4d88* pkBlend);
};

// Inserts a tree item for pkBlend and, for each of its targets with an interp, inserts a child item labelled with the index and target name.
// @fnv 0x004d8830
void TreeCtrl4d88::AddBlendInterpTreeItems(void* hParentItem, BlendInterp4d88* pkBlend)
{
    if (pkBlend)
    {
        TreeInsert4d88 kInsert;
        void* hBlendItem;
        char acBuffer[256];
        kInsert.hInsertAfter = (void*)0xFFFF0002;
        kInsert.item.mask = 0x27;
        kInsert.item.lParam = (long)pkBlend;
        kInsert.item.pszText = PrepareScriptMessage(DAT_01020f14, false);
        kInsert.item.iImage = 5;
        kInsert.item.iSelectedImage = kInsert.item.iImage;
        kInsert.hParent = hParentItem;
        hBlendItem = ((SendMessage4d88)DAT_00fdf28c)(m_hTreeWnd, 0x1100, 0, (int)&kInsert);
        kInsert.hParent = hBlendItem;
        for (unsigned short us = 0; us < pkBlend->GetField3C(); us++)
        {
            Target4d88* pkTarget = pkBlend->GetEntry(us);
            if (pkTarget)
            {
                Interp4d88* pkInterp = pkBlend->GetExtraDataAt(us);
                if (pkInterp)
                {
                    kInsert.item.lParam = (long)pkInterp;
                    sprintf_s(acBuffer, 0x100, "Interp: %d, Target:%s", us, *pkTarget->FUN_00413f40());
                    kInsert.item.pszText = PrepareScriptMessage(acBuffer, false);
                    void* hItem = ((SendMessage4d88)DAT_00fdf28c)(m_hTreeWnd, 0x1100, 0, (int)&kInsert);
                    AddNameItems(hItem, pkInterp);
                }
            }
        }
    }
}

namespace fnv_004d8a40 {
struct TreeItem4d8a
{
    unsigned int mask;
    void* hItem;
    unsigned int state;
    unsigned int stateMask;
    const char* pszText;
    int cchTextMax;
    int iImage;
    int iSelectedImage;
    int cChildren;
    long lParam;
    int iIntegral;
    unsigned int uStateEx;
    void* hwnd;
    int iExpandedImage;
};

struct TreeInsert4d8a
{
    void* hParent;
    void* hInsertAfter;
    TreeItem4d8a item;
};

const char* PrepareScriptMessage(const char* pcText, bool bFlag);

struct FUN_004d9100
{
    FUN_004d9100(int aiInitialSize, int iGrowBy);
    virtual ~FUN_004d9100();
    unsigned int GetShortAtOffsetA();
    const char** FUN_00877a30(unsigned int uiIndex);
    void FUN_005e03d0();
    int unk04[3];
};

struct NameSource4d8a
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
    virtual void GetNames(FUN_004d9100* pkNames);
};

struct TreeCtrl4d8a
{
    void* m_hInstance;
    int unk04;
    void* m_hWnd;
    void* m_hTreeWnd;
    void AddNameItems(void* hParent, NameSource4d8a* pkSource);
};

// @fnv 0x004d8a40
void TreeCtrl4d8a::AddNameItems(void* hParent, NameSource4d8a* pkSource)
{
    if (pkSource)
    {
        FUN_004d9100* pkNames = new FUN_004d9100(0x80, 0x80);
        TreeInsert4d8a kInsert;
        unsigned int i;
        kInsert.hInsertAfter = (void*)0xFFFF0002;
        kInsert.item.mask = 0x27;
        kInsert.item.lParam = (long)pkSource;
        kInsert.hParent = hParent;
        pkSource->GetNames(pkNames);
        for (i = 0; i < pkNames->GetShortAtOffsetA(); i++)
        {
            kInsert.item.pszText = PrepareScriptMessage(*pkNames->FUN_00877a30(i), false);
            kInsert.item.iImage = 6;
            kInsert.item.iSelectedImage = kInsert.item.iImage;
            DAT_00fdf28c(m_hTreeWnd, 0x1100, 0, (int)&kInsert);
        }
        pkNames->FUN_005e03d0();
        delete pkNames;
    }
}
}  // namespace fnv_004d8a40

void* __cdecl FUN_0096afc0(unsigned int size);

struct FUN_004d9210
{
    virtual ~FUN_004d9210();
    void* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    FUN_004d9210(unsigned short capacity, unsigned short growBy);
};

// Initialises the buffer: stores capacity and grow-by, zeroes size fields, and allocates m_usMaxSize bytes into m_pBase (or null when capacity is 0).
// @fnv 0x004d9210
FUN_004d9210::FUN_004d9210(unsigned short capacity, unsigned short growBy)
{
    m_usMaxSize = capacity;
    m_usGrowBy = growBy;
    m_usSize = 0;
    m_usESize = 0;
    if (m_usMaxSize > 0)
        m_pBase = FUN_0096afc0(m_usMaxSize);
    else
        m_pBase = 0;
}

class DepthDevice;

extern DepthDevice* DAT_0126f0d8;

// @fnv 0x004dc040
unsigned int __cdecl FUN_004dc040()
{
    return reinterpret_cast<unsigned int>(DAT_0126f0d8);
}

// @fnv 0x004dc0a0
unsigned char __cdecl FUN_004dc0a0()
{
    return DAT_011f9180;
}

extern int DAT_011f94b8;
// @fnv 0x004dc0b0
int __cdecl FUN_004dc0b0()
{
    return DAT_011f94b8;
}

char* DAT_01202fa0;
// @fnv 0x004dc110
char** FUN_004dc110()
{
    return &DAT_01202fa0;
}

extern int DAT_011c6fbc;

// @fnv 0x004dc1e0
int __cdecl FUN_004dc1e0()
{
    return DAT_011c6fbc;
}

extern unsigned int DAT_0118947c;

// @fnv 0x004dc1f0
unsigned int __cdecl FUN_004dc1f0()
{
    return DAT_0118947c;
}

extern int DAT_01189480;

// @fnv 0x004dc200
int __cdecl FUN_004dc200()
{
    return DAT_01189480;
}

extern unsigned int DAT_01189478;
// @fnv 0x004dc220
unsigned int __cdecl FUN_004dc220()
{
    return DAT_01189478;
}

extern int DAT_011c70d4;

// @fnv 0x004dc230
int FUN_004dc230()
{
    return DAT_011c70d4;
}

extern int DAT_011c70d8;

// @fnv 0x004dc240
int __cdecl FUN_004dc240()
{
    return DAT_011c70d8;
}

extern int DAT_01189464;

// @fnv 0x004dc250
int __cdecl FUN_004dc250()
{
    return DAT_01189464;
}

extern int DAT_011c70d0;

// @fnv 0x004dc260
int FUN_004dc260()
{
    return DAT_011c70d0;
}

extern int DAT_01189470;

// @fnv 0x004dc270
int __cdecl FUN_004dc270()
{
    return DAT_01189470;
}

extern int DAT_01189474;
// @fnv 0x004dc280
int __cdecl FUN_004dc280()
{
    return DAT_01189474;
}

extern int DAT_011c70cc;
// @fnv 0x004dc290
int __cdecl FUN_004dc290()
{
    return DAT_011c70cc;
}

extern int DAT_011c6fb0;

// @fnv 0x004dc2a0
int __cdecl FUN_004dc2a0()
{
    return DAT_011c6fb0;
}

extern "C" void* DAT_011c74b8;
// @fnv 0x004dc2c0
void* __cdecl FUN_004dc2c0()
{
    return &DAT_011c74b8;
}

// Maps an input index 0-18 to a corresponding constant value via a switch, returning 0 for index 0 and any out-of-range value.
// @fnv 0x004dcbe0
unsigned int __cdecl MapIndexToValue(unsigned int uiIndex)
{
    switch (uiIndex)
    {
    case 0:
        return 0;
    case 1:
        return 0x14;
    case 2:
        return 0x15;
    case 3:
        return 0x16;
    case 4:
        return 0x17;
    case 5:
        return 0x18;
    case 6:
        return 0x19;
    case 7:
        return 0x1A;
    case 8:
        return 0x1B;
    case 9:
        return 0x1C;
    case 10:
        return 0x1D;
    case 11:
        return 0x1E;
    case 12:
        return 0x6F;
    case 13:
        return 0x70;
    case 14:
        return 0x24;
    case 15:
        return 0x71;
    case 16:
        return 0x72;
    case 17:
        return 0x73;
    case 18:
        return 0x74;
    default:
        return 0;
    }
}

extern int DAT_01189468;
// @fnv 0x004dcd80
int __cdecl FUN_004dcd80()
{
    return DAT_01189468;
}

extern int DAT_0118946c;

// @fnv 0x004dcd90
int __cdecl FUN_004dcd90()
{
    return DAT_0118946c;
}

namespace fnv_004dd180 {
struct FUN_00559450_Object
{
    void* FUN_00559450();
};
extern FUN_00559450_Object DAT_011c73b4;
struct FUN_004b9930_Object
{
    unsigned char FUN_004b9930(int id, int enabled);
};
extern FUN_004b9930_Object DAT_011c77b4;
int __cdecl FUN_004dc270();
int __cdecl MapIndexToValue(int value);
int __stdcall FUN_004dc210(int value);
struct FUN_004dd220_Object
{
    int GetField5C8();
};
struct DispatchInterface;
struct DispatchVTable
{
    void* method00;
    void* method01;
    void* method02;
    void* method03;
    void* method04;
    void* method05;
    void* method06;
    void* method07;
    void* method08;
    void* method09;
    void* method10;
    long(__stdcall* dispatch)(DispatchInterface*, int, int, int);
};
struct DispatchInterface
{
    DispatchVTable* vtable;
};
DispatchInterface* __cdecl FUN_004dc040();
// @fnv 0x004dd180
bool __cdecl DispatchFormValue(int formId, int requestedValue)
{
    int result;
    DispatchInterface* selectedValue;
    long dispatcher;
    if (DAT_011c73b4.FUN_00559450())
    {
        if (requestedValue)
            result = requestedValue;
        else
            result = MapIndexToValue(FUN_004dc270());

        DAT_011c73b4.FUN_00559450();
        selectedValue = FUN_004dc040();
        dispatcher = selectedValue->vtable->dispatch(
            selectedValue, FUN_004dc210(((FUN_004dd220_Object*)DAT_011c73b4.FUN_00559450())->GetField5C8()), result,
            DAT_011c77b4.FUN_004b9930(formId, 0));
        if (dispatcher >= 0)
            return true;
    }
    return false;
}
}  // namespace fnv_004dd180

extern float DAT_01189490;
// @fnv 0x004de0d0
float FUN_004de0d0()
{
    return DAT_01189490;
}

struct DisplayDevice4de1
{
    unsigned long cb;
    char DeviceName[32];
    char DeviceString[128];
    unsigned long StateFlags;
    char DeviceID[128];
    char DeviceKey[128];
};

struct EyefinityInfo4de1
{
    int iSLSActive;
    int iSLSGridWidth;
    int iSLSGridHeight;
    int iSLSWidth;
    int iSLSHeight;
    int iPadding;
};

struct DisplayInfo4de1
{
    int iGridXCoord;
    int iGridYCoord;
    int iRectLeft;
    int iRectTop;
    int iRectRight;
    int iRectBottom;
};

extern int(__stdcall* DAT_00fdf2f0)(const char*, unsigned long, DisplayDevice4de1*, unsigned long);
int __cdecl FUN_004dd2c0(int iPrimaryDisplay, EyefinityInfo4de1* pkInfo, int* piNumTargets,
                         DisplayInfo4de1** ppkTargets);
int __cdecl FUN_00ec9d4a(const char* pcFormat, ...);
extern bool DAT_01189484;
extern float DAT_01189488;
extern float DAT_0118948c;
extern float DAT_01189490;
extern "C" float DAT_01189494;
extern float DAT_01189498;
extern bool DAT_011c70ed;
extern bool DAT_011c70ee;
extern bool DAT_011c70ef;
extern float DAT_011c70f0;

// Finds the primary display, queries its Eyefinity configuration, and stores SLS width, height, aspect ratio and grid flags when active.
// @fnv 0x004de100
void InitEyefinityDisplayInfo()
{
    int iEntryIndex;
    int iPrimaryDisplay = -1;
    EyefinityInfo4de1 kInfo = {0};
    DisplayInfo4de1* pkTargets = 0;
    int iTargetCount;
    if (iPrimaryDisplay == -1)
    {
        iEntryIndex = 0;
        DisplayDevice4de1 kDevice;
        kDevice.cb = sizeof(kDevice);
        while (DAT_00fdf2f0(0, iEntryIndex, &kDevice, 0))
        {
            if (kDevice.StateFlags & 4)
            {
                iPrimaryDisplay = iEntryIndex;
                break;
            }
            iEntryIndex++;
        }
    }
    if (FUN_004dd2c0(iPrimaryDisplay, &kInfo, &iTargetCount, &pkTargets) == 1)
    {
        if (kInfo.iSLSActive == 1 && DAT_01189484)
        {
            DAT_0118948c = (float)kInfo.iSLSWidth;
            DAT_01189490 = (float)kInfo.iSLSHeight;
            DAT_01189494 = DAT_0118948c;
            DAT_01189498 = DAT_01189490;
            DAT_01189488 = DAT_0118948c / DAT_01189490;
            DAT_011c70ed = true;
            if (pkTargets->iRectBottom > pkTargets->iRectRight)
                DAT_011c70ef = true;
            else
                DAT_011c70ee = true;
            if (DAT_011c70ee && kInfo.iSLSGridWidth == 3 && kInfo.iSLSGridHeight == 1)
            {
                DAT_01189494 = DAT_0118948c / 3.0;
                DAT_01189498 = DAT_01189490;
                DAT_011c70f0 = DAT_01189494;
            }
        }
        FUN_004dd2a0(&pkTargets);
    }
    else
    {
        FUN_00ec9d4a("Eyefinity configuration query failed for display index %i.\n", iPrimaryDisplay);
    }
}

struct FUN_004de2d0_StandIn : FUN_004de2b0_StandIn
{
    FUN_004de2b0_StandIn* __thiscall FUN_004de2d0(char c);
};

// @fnv 0x004de2d0
FUN_004de2b0_StandIn* FUN_004de2d0_StandIn::FUN_004de2d0(char c)
{
    SetCharAtOffset4(c);
    return this;
}

extern "C" void __cdecl FormHeap_Free(void*);

struct FUN_004de3f0_Class
{
    void __thiscall FUN_004de420();
    void* __thiscall FUN_004de3f0(int flags);
};

// @fnv 0x004de3f0
void* __thiscall FUN_004de3f0_Class::FUN_004de3f0(int flags)
{
    this->FUN_004de420();

    if ((flags & 1) != 0)
    {
        FormHeap_Free(this);
    }

    return this;
}

struct INISettingCollection
{
    INISettingCollection();
    virtual void v0();
};
struct FUN_004de530 : public INISettingCollection
{
    FUN_004de530();
};
// @fnv 0x004de530
FUN_004de530::FUN_004de530()
{}

extern char DAT_011c77e8;
extern void* DAT_011c7810;
extern void* DAT_011c781c;
struct FUN_00559450_Helper
{
    void* FUN_00559450();
};
struct FUN_0066b0d0_Helper
{
    void FUN_004def90();
    void FUN_0066b0d0(int);
};

// @fnv 0x004def20
void FUN_004def20()
{
    if ((unsigned char)DAT_011c77e8)
    {
        ((FUN_0066b0d0_Helper*)((FUN_00559450_Helper*)&DAT_011c7810)->FUN_00559450())->FUN_004def90();
        ((FUN_0066b0d0_Helper*)&DAT_011c7810)->FUN_0066b0d0(0);
        ((FUN_0066b0d0_Helper*)&DAT_011c781c)->FUN_0066b0d0(0);
    }
    DAT_011c77e8 = 0;
    for (int i = 0; i < 3; i++)
        ((FUN_0066b0d0_Helper*)&DAT_011c7804[i])->FUN_0066b0d0(0);
}

void* __cdecl operator new(unsigned int uiSize);
void __cdecl operator delete(void* pvMem);

class C4DF040Object
{
  public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem, unsigned int);
};

class C4DF040Point3
{
  public:
    C4DF040Point3();
    C4DF040Point3(float fX, float fY, float fZ);

    C4DF040Point3 operator+(const C4DF040Point3& kPt) const;

    float x;
    float y;
    float z;
};

class C4DF040Point2
{
  public:
    C4DF040Point2();
    C4DF040Point2(float fX, float fY);

    C4DF040Point2 operator+(const C4DF040Point2& kPt) const;

    float x;
    float y;
};

class C4DF040Matrix3
{
  public:
    C4DF040Matrix3();

    void MakeRandomRotation();
    C4DF040Point3 operator*(const C4DF040Point3& kPt) const;

    float m_afEntries[3][3];
};

class C4DF040Texture;

class C4DF040TexturePtr
{
  public:
    C4DF040Texture* Get();

    C4DF040Texture* m_pPointer;
};

class C4DF040Property : public C4DF040Object
{
  public:
    C4DF040Property();

    void SetTexture(int iSlot, C4DF040Texture* pkTexture);

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
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
};

class C4DF040TriShape : public C4DF040Object
{
  public:
    C4DF040TriShape(unsigned short usVertices, C4DF040Point3* pkVertex, C4DF040Point3* pkNormal, void* pkColor,
                    C4DF040Point2* pkTexture, unsigned short usNumTextureSets, unsigned int eNBTMethod,
                    unsigned short usTriangles, unsigned short* pusTriList);

    void AttachProperty(C4DF040Property* pkProperty);

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
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
};

class C4DF040Node : public C4DF040Object
{
  public:
    C4DF040Node(unsigned int uiMode);

    virtual void VFunc000();
    virtual void VFunc004();
    virtual void VFunc008();
    virtual void VFunc00C();
    virtual void VFunc010();
    virtual void VFunc014();
    virtual void VFunc018();
    virtual void VFunc01C();
    virtual void VFunc020();
    virtual void VFunc024();
    virtual void VFunc028();
    virtual void VFunc02C();
    virtual void VFunc030();
    virtual void VFunc034();
    virtual void VFunc038();
    virtual void VFunc03C();
    virtual void VFunc040();
    virtual void VFunc044();
    virtual void VFunc048();
    virtual void VFunc04C();
    virtual void VFunc050();
    virtual void VFunc054();
    virtual void VFunc058();
    virtual void VFunc05C();
    virtual void VFunc060();
    virtual void VFunc064();
    virtual void VFunc068();
    virtual void VFunc06C();
    virtual void VFunc070();
    virtual void VFunc074();
    virtual void VFunc078();
    virtual void VFunc07C();
    virtual void VFunc080();
    virtual void VFunc084();
    virtual void VFunc088();
    virtual void VFunc08C();
    virtual void VFunc090();
    virtual void VFunc094();
    virtual void VFunc098();
    virtual void VFunc09C();
    virtual void VFunc0A0();
    virtual void VFunc0A4();
    virtual void VFunc0A8();
    virtual void VFunc0AC();
    virtual void VFunc0B0();
    virtual void VFunc0B4();
    virtual void VFunc0B8();
    virtual void VFunc0BC();
    virtual void VFunc0C0();
    virtual void VFunc0C4();
    virtual void VFunc0C8();
    virtual void VFunc0CC();
    virtual void VFunc0D0();
    virtual void VFunc0D4();
    virtual void VFunc0D8();
    virtual void AttachChildInAvailableSlot(C4DF040TriShape* pkChild, bool abFirstAvailableSlot);

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
    int unkA0;
    int unkA4;
    int unkA8;
};

class C4DF040FloatSetting
{
  public:
    float* Float();
};

extern C4DF040FloatSetting g_kDebrisMinWidth;
extern C4DF040FloatSetting g_kDebrisMaxWidth;
extern C4DF040FloatSetting g_kDebrisMinHeight;
extern C4DF040FloatSetting g_kDebrisMaxHeight;
extern C4DF040FloatSetting g_kDebrisMinAltHeight;
extern C4DF040FloatSetting g_kDebrisMaxAltHeight;
extern C4DF040FloatSetting g_kDebrisAltHeightChance;
extern C4DF040FloatSetting g_kDebrisShadowSize;
extern bool g_bDebrisShadows;
extern float g_fDebrisRangeX;
extern float g_fDebrisRangeY;
extern C4DF040TexturePtr g_spDebrisTexture;
extern C4DF040TexturePtr g_spDebrisNormalMap;
extern C4DF040TexturePtr g_spDebrisShadowTexture;

float __cdecl C4DF040Random();
float __cdecl C4DF040RandomFloat(float fMin, float fScaledValue);
bool __cdecl C4DF040RandomChance(float afChance);
void __cdecl C4DF040UpdateProperties(C4DF040TriShape* pkShape, int iArg1, int iArg2);

// Builds a node with a quad-tri shape of randomly placed, rotated and sized debris pieces, optionally adding a shadow shape, and returns the node.
// @fnv 0x004df040
C4DF040Node* __cdecl CreateDebrisNode(unsigned int uiPieceCount, float fWidthScale, float fHeightScale)
{
    C4DF040Point2* pkTexCoords;
    C4DF040Property* pkTexturing;
    C4DF040Point2* pkShadowTex;
    C4DF040Node* pkNodeRoot;
    C4DF040Point3* pkPositions;
    unsigned short* pusFaces;
    unsigned short* pusShadowIndices;
    unsigned int uiPiece;
    C4DF040TriShape* pkDebrisShape;
    C4DF040Point3* pkShadow;

    pkNodeRoot = new C4DF040Node(0);
    pkPositions = new C4DF040Point3[uiPieceCount * 4];
    pkTexCoords = new C4DF040Point2[uiPieceCount * 4];
    pusFaces = new unsigned short[uiPieceCount * 6];
    pkShadow = 0;
    pkShadowTex = 0;
    pusShadowIndices = 0;
    if (g_bDebrisShadows)
    {
        pkShadow = new C4DF040Point3[uiPieceCount * 4];
        pkShadowTex = new C4DF040Point2[uiPieceCount * 4];
        pusShadowIndices = new unsigned short[uiPieceCount * 6];
    }

    for (uiPiece = 0; uiPiece < uiPieceCount; uiPiece++)
    {
        float fAlternate;
        unsigned int uiVertex;
        float fY;
        float fHalfWidth;
        float fHeightChoice;
        float fUUOffset;
        float fRandX;
        float fShadowHalf;
        float fV;
        unsigned int uiIndex;

        fRandX = C4DF040Random() * g_fDebrisRangeX;
        fY = C4DF040Random() * g_fDebrisRangeY;
        C4DF040Point3 kTargetCenter(fRandX, fY, 0.0f);

        fHalfWidth = C4DF040RandomFloat(*g_kDebrisMinWidth.Float(), *g_kDebrisMaxWidth.Float());
        fHalfWidth *= fWidthScale;
        fHeightChoice = C4DF040RandomFloat(*g_kDebrisMinHeight.Float(), *g_kDebrisMaxHeight.Float());
        fAlternate = C4DF040RandomFloat(*g_kDebrisMinAltHeight.Float(), *g_kDebrisMaxAltHeight.Float());
        fHeightChoice *= fHeightScale;
        fAlternate *= fHeightScale;

        C4DF040Matrix3 kRotationBasis;
        kRotationBasis.MakeRandomRotation();
        if (C4DF040RandomChance(*g_kDebrisAltHeightChance.Float()))
            fHeightChoice = fAlternate;

        fUUOffset = C4DF040Random() > 0.0 ? 0.0 : 0.5;
        fV = C4DF040Random() > 0.0 ? 0.0 : 0.5;
        C4DF040Point2 kUVShift(fUUOffset, fV);
        fShadowHalf = *g_kDebrisShadowSize.Float();

        uiVertex = uiPiece * 4;
        pkPositions[uiVertex] = kRotationBasis * C4DF040Point3(-fHalfWidth, fHalfWidth, fHeightChoice) + kTargetCenter;
        pkPositions[uiVertex + 1] =
            kRotationBasis * C4DF040Point3(fHalfWidth, fHalfWidth, fHeightChoice) + kTargetCenter;
        pkPositions[uiVertex + 2] =
            kRotationBasis * C4DF040Point3(-fHalfWidth, -fHalfWidth, fHeightChoice) + kTargetCenter;
        pkPositions[uiVertex + 3] =
            kRotationBasis * C4DF040Point3(fHalfWidth, -fHalfWidth, fHeightChoice) + kTargetCenter;
        if (g_bDebrisShadows)
        {
            pkShadow[uiVertex] =
                kRotationBasis * C4DF040Point3(-fShadowHalf, fShadowHalf, fHeightChoice) + kTargetCenter;
            pkShadow[uiVertex + 1] =
                kRotationBasis * C4DF040Point3(fShadowHalf, fShadowHalf, fHeightChoice) + kTargetCenter;
            pkShadow[uiVertex + 2] =
                kRotationBasis * C4DF040Point3(-fShadowHalf, -fShadowHalf, fHeightChoice) + kTargetCenter;
            pkShadow[uiVertex + 3] =
                kRotationBasis * C4DF040Point3(fShadowHalf, -fShadowHalf, fHeightChoice) + kTargetCenter;
        }

        pkTexCoords[uiVertex] = C4DF040Point2(0.5f, 0.5f) + kUVShift;
        pkTexCoords[uiVertex + 1] = C4DF040Point2(0.0f, 0.5f) + kUVShift;
        pkTexCoords[uiVertex + 2] = C4DF040Point2(0.5f, 0.0f) + kUVShift;
        pkTexCoords[uiVertex + 3] = C4DF040Point2(0.0f, 0.0f) + kUVShift;
        if (g_bDebrisShadows)
        {
            pkShadowTex[uiVertex] = C4DF040Point2(1.0f, 1.0f);
            pkShadowTex[uiVertex + 1] = C4DF040Point2(0.0f, 1.0f);
            pkShadowTex[uiVertex + 2] = C4DF040Point2(1.0f, 0.0f);
            pkShadowTex[uiVertex + 3] = C4DF040Point2(0.0f, 0.0f);
        }

        uiIndex = uiPiece * 6;
        pusFaces[uiIndex] = (unsigned short)uiVertex;
        pusFaces[uiIndex + 1] = (unsigned short)(uiVertex + 2);
        pusFaces[uiIndex + 2] = (unsigned short)(uiVertex + 1);
        pusFaces[uiIndex + 3] = (unsigned short)(uiVertex + 1);
        pusFaces[uiIndex + 4] = (unsigned short)(uiVertex + 2);
        pusFaces[uiIndex + 5] = (unsigned short)(uiVertex + 3);
        if (g_bDebrisShadows)
        {
            pusShadowIndices[uiIndex] = (unsigned short)uiVertex;
            pusShadowIndices[uiIndex + 1] = (unsigned short)(uiVertex + 2);
            pusShadowIndices[uiIndex + 2] = (unsigned short)(uiVertex + 1);
            pusShadowIndices[uiIndex + 3] = (unsigned short)(uiVertex + 1);
            pusShadowIndices[uiIndex + 4] = (unsigned short)(uiVertex + 2);
            pusShadowIndices[uiIndex + 5] = (unsigned short)(uiVertex + 3);
        }
    }

    pkDebrisShape =
        new C4DF040TriShape(uiPieceCount * 4, pkPositions, 0, 0, pkTexCoords, 1, 0, uiPieceCount * 2, pusFaces);
    pkTexturing = new C4DF040Property;
    pkTexturing->SetTexture(0, g_spDebrisTexture.Get());
    pkTexturing->SetTexture(1, g_spDebrisNormalMap.Get());
    pkDebrisShape->AttachProperty(pkTexturing);
    C4DF040UpdateProperties(pkDebrisShape, 0, 0);
    pkNodeRoot->AttachChildInAvailableSlot(pkDebrisShape, true);

    if (g_bDebrisShadows)
    {
        pkDebrisShape = new C4DF040TriShape(uiPieceCount * 4, pkShadow, 0, 0, pkShadowTex, 1, 0, uiPieceCount * 2,
                                            pusShadowIndices);
        pkTexturing = new C4DF040Property;
        pkTexturing->SetTexture(0, g_spDebrisShadowTexture.Get());
        pkDebrisShape->AttachProperty(pkTexturing);
        C4DF040UpdateProperties(pkDebrisShape, 0, 0);
        pkNodeRoot->AttachChildInAvailableSlot(pkDebrisShape, true);
    }
    return pkNodeRoot;
}

extern double DAT_010229b8;
extern double DAT_01012070;
struct FUN_004dfec0_Class
{
    unsigned int FUN_00476be0();
    float FUN_004dfec0();
};
// @fnv 0x004dfec0
float FUN_004dfec0_Class::FUN_004dfec0()
{
    unsigned int randomValue = FUN_00476be0();
    return static_cast<float>(static_cast<double>(randomValue) * DAT_010229b8 - DAT_01012070);
}

class FUN_004d4f10
{
  public:
    virtual ~FUN_004d4f10();

    void FUN_00438af0();
};

class FUN_004d4eb0 : public FUN_004d4f10
{
  public:
    virtual ~FUN_004d4eb0();
};

// @fnv 0x004d4eb0
FUN_004d4eb0::~FUN_004d4eb0()
{
    FUN_00438af0();
}

struct BGSLoadGameBuffer
{
    virtual unsigned char GetVersion();
    void FUN_00864980(void*, unsigned int);
};
struct SavedSettingValue
{
    unsigned int unk00;
    unsigned int value;
};
// Reads a count (default 0x15, read from the buffer if version >= 11), then that many ints, storing each in DAT_011c6d50[i]'s value if i < 43 and non-null.
// @fnv 0x004d6020
void __cdecl ReadSavedSettings(BGSLoadGameBuffer* buffer)
{
    unsigned int count = 0x15;
    if (buffer->GetVersion() >= 11)
        buffer->FUN_00864980(&count, 4);
    if (count > 0x1000000)
        return;
    for (unsigned int i = 0; i < count; i++)
    {
        unsigned int value = 0;
        buffer->FUN_00864980(&value, 4);
        if (i < 43 && DAT_011c6d50[i])
            static_cast<SavedSettingValue*>(DAT_011c6d50[i])->value = value;
    }
}

class ListT
{
  public:
    unsigned int FUN_0044ddc0();
    void* FUN_00559450();
    ListT* FUN_0057cbe0(void**);
};
class Owner
{
  public:
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
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    ListT kList;
    void* GetByIndex(unsigned int idx);
};
// Returns the element at the given index from the list, or null if the index is out of range.
// @fnv 0x004d7d70
void* Owner::GetByIndex(unsigned int idx)
{
    if (idx >= kList.FUN_0044ddc0())
        return 0;
    unsigned int i = 0;
    void* n = kList.FUN_00559450();
    while (n)
    {
        void* d = kList.FUN_0057cbe0(&n)->FUN_00559450();
        if (i++ == idx)
            return d;
    }
    return 0;
}

namespace fnv_004d9070 {
void __fastcall DeleteAllEntries(void* pkMap);

class FUN_004d90d0
{
  public:
    virtual ~FUN_004d90d0();
};

class FUN_004d9070 : public FUN_004d90d0
{
  public:
    virtual ~FUN_004d9070();
};

// Destructor that calls DeleteAllEntries on the object to free all entries before base class cleanup.
// @fnv 0x004d9070
FUN_004d9070::~FUN_004d9070()
{
    DeleteAllEntries(this);
}
}  // namespace fnv_004d9070

struct NiTMallocInterface_004d91b0
{
    static void __cdecl Deallocate(void*);
};
struct FUN_004d91b0_Class
{
    virtual void v00();
    void* pData;
    ~FUN_004d91b0_Class();
};
// Frees the pData buffer by calling NiTMallocInterface_004d91b0::Deallocate.
// @fnv 0x004d91b0
FUN_004d91b0_Class::~FUN_004d91b0_Class()
{
    NiTMallocInterface_004d91b0::Deallocate(pData);
}

struct DoorTeleportLoadData
{
    unsigned int unk00;
    float positionX, positionY, positionZ;
    float rotationX, rotationY, rotationZ;
    DoorTeleportLoadData();
};
struct FUN_008579e0_shell
{
    void FUN_008579e0(void*, unsigned int);
};
extern FUN_008579e0_shell* g_TESSaveLoadGame;
struct DoorTeleportArray
{
    unsigned char count;
    DoorTeleportLoadData* entries;
    void FUN_004da3f0();
};
// Reads a door teleport array from the save game stream, allocating and populating the entries buffer.
// @fnv 0x004da3f0
void DoorTeleportArray::FUN_004da3f0()
{
    g_TESSaveLoadGame->FUN_008579e0(this, 1);
    entries = new DoorTeleportLoadData[count];
    g_TESSaveLoadGame->FUN_008579e0(entries, count * sizeof(DoorTeleportLoadData));
}

extern int DAT_011c70e0;
extern int DAT_011c70e4;
extern bool DAT_011c70eb;
extern int DAT_011c6fbc;

struct OutT
{
    int x;
    int y;
};
extern int(__stdcall* DAT_00fdf2ec)(int, int);
extern int(__stdcall* DAT_00fdf2e8)(unsigned int, int);
extern int(__stdcall* DAT_00fdf310)(OutT*, int, int);
extern int(__stdcall* DAT_00fdf2a4)(unsigned int, int, int);

unsigned int FUN_004bc3f0();

class NiAVObject;
struct FUN_004dc540_shell
{
    void FUN_004dc540(NiAVObject*);
};

class BGSMoviePlayer
{
  public:
    void FUN_00ec25e0();
};
extern BGSMoviePlayer* DAT_0126fac4;

class BSAudio
{
  public:
    unsigned int FUN_0044ddc0();
};
extern BSAudio* g_osGlobals;

struct FUN_00b7b930_Ctx
{
    void FUN_00b631d0();
};
FUN_00b7b930_Ctx* FUN_00b4f5c0();

struct GO45
{
    void FUN_0045ce80(int);
    int FUN_004503f0();
};
extern GlobalObject_004a4a40 g_011c73dc;
extern GlobalObject_004a4a40 g_011c718c;

struct S45a
{
    int FUN_004503f0(int, int, int);
};
struct S45b
{
    int FUN_004503f0(int);
};

class GlobalObject_00633c90
{
  public:
    FUN_004dc540_shell* FUN_00559450();
};
extern GlobalObject_00633c90 g_011c73b4;

struct FUN_00558310_node
{
    void FUN_00c52520();
};
FUN_00558310_node* FUN_0045c670();

class E73shell
{
  public:
    int FUN_00e73eb0(int, int);
};

class Interface
{
  public:
    static void Init(bool);
};

void FUN_00702330();
void FUN_004dc560();
void FUN_004dc590();
void FUN_00a62030();
void FUN_00b578a0();
void FUN_004dc5c0();
void FUN_004dc650();
void FUN_007022c0();
void FUN_007053f0();
void __cdecl CopyStringToGlobal(const char* src);

// Recreates the render at DAT_011c70e0 by DAT_011c70e4 (message on failure), updates the aspect flag and calls refresh helpers and Interface::Init(false).
// @fnv 0x004dc360
void RecreateRenderDevice()
{
    if (FUN_004bc3f0() && DAT_011c70e0 && DAT_011c70e4)
    {
        FUN_00b4f5c0()->FUN_00b631d0();
        ((GO45*)&g_011c73dc)->FUN_0045ce80(DAT_011c70e0);
        ((GO45*)&g_011c718c)->FUN_0045ce80(DAT_011c70e4);
        if (DAT_011c70e4 / (double)DAT_011c70e0 == 0.75)
            DAT_011c70eb = false;
        else
            DAT_011c70eb = true;
        DAT_0126fac4->FUN_00ec25e0();
        FUN_00702330();
        FUN_004dc560();
        FUN_004dc590();
        ((FUN_004dc540_shell*)FUN_004bc3f0())->FUN_004dc540(0);
        bool bSuccess = ((E73shell*)FUN_004bc3f0())->FUN_00e73eb0(DAT_011c70e0, DAT_011c70e4) != 0;
        if (bSuccess)
        {
            unsigned int uiFlags = g_osGlobals->FUN_0044ddc0();
            OutT outVal = {0, 0};
            int v1 = ((GO45*)&g_011c73dc)->FUN_004503f0();
            int v3 = ((GO45*)&g_011c718c)->FUN_004503f0();
            DAT_00fdf310(&outVal, DAT_00fdf2e8(uiFlags, -16), DAT_00fdf2ec(DAT_011c6fbc, -8));
            int iDeltaX = v1 - outVal.x;
            int iDeltaY = v3 - outVal.y;
            DAT_00fdf2a4(uiFlags, 0,
                         ((S45b*)&g_011c75d4)->FUN_004503f0(((S45a*)&g_011c7654)->FUN_004503f0(iDeltaX, iDeltaY, 64)));
        }
        else
        {
            CopyStringToGlobal("Failed to Recreate Gamebryo Render in desired dimensions.");
        }
        FUN_00a62030();
        FUN_00b578a0();
        g_011c73b4.FUN_00559450()->FUN_004dc540((NiAVObject*)FUN_00b4f5c0());
        FUN_0045c670()->FUN_00c52520();
        FUN_004dc5c0();
        FUN_004dc650();
        Interface::Init(false);
        FUN_007022c0();
        FUN_007053f0();
    }
}

extern bool DAT_011c70ed;

// @fnv 0x004de070
bool __cdecl FUN_004de070()
{
    return DAT_011c70ed;
}

extern float g_0118948c;

// @fnv 0x004de0c0
float FUN_004de0c0()
{
    return g_0118948c;
}

extern float DAT_01189498;
// @fnv 0x004de0f0
float __cdecl FUN_004de0f0()
{
    return DAT_01189498;
}

struct FUN_004dfe30_Class
{
    float x;
    float y;

    FUN_004dfe30_Class();
    FUN_004dfe30_Class __thiscall FUN_004dfe30(const FUN_004dfe30_Class& kPt) const;
};

// Returns a new point whose x and y are the sums of this point and kPt.
// @fnv 0x004dfe30
FUN_004dfe30_Class __thiscall FUN_004dfe30_Class::FUN_004dfe30(const FUN_004dfe30_Class& kPt) const
{
    FUN_004dfe30_Class res = *this;
    res.x += kPt.x;
    res.y += kPt.y;
    return res;
}

struct FUN_004d8610_StandIn
{
    void* GetSubValue(int);
};
// Retrieves the sub-value at index a from the local data of this ScriptLocalsX, returning null if no local data exists.
// @fnv 0x004d85d0
void* FUN_004d85a0_Class::GetLocalSubValue(int a)
{
    FUN_004d8610_StandIn* pLocalData = (FUN_004d8610_StandIn*)((ScriptLocalsX*)this)->GetLocalData();
    return pLocalData ? pLocalData->GetSubValue(a) : 0;
}

namespace fnv_004dc710 {
#include <windows.h>
#include <d3d9.h>
bool FUN_004dcda0_Result();
int __cdecl FUN_004dc2b0_Result();

namespace std {
float __cdecl abs(float value);
}
struct DisplayAdapter
{
    unsigned int FUN_004dcce0();
    D3DDISPLAYMODE* GetElementAt(unsigned int indexInfo);
    unsigned char FUN_004dcd30(int windowed);
    D3DCAPS9* FUN_004dc120(int indexInfo);
};
void* __cdecl FUN_004dce30();
DisplayAdapter* __cdecl GetFltValueAt(int indexInfo);
int __cdecl FUN_004dc270();
D3DFORMAT __cdecl MapIndexToValue(int format);
int __cdecl FUN_004dc1f0();
int __cdecl FUN_004dc200();
unsigned int __cdecl FUN_004dcd90();
unsigned int __cdecl FUN_004dcd80();
struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
extern GlobalObject_0045cf30 g_011c74e0;
void __cdecl DetectGpuVendor(unsigned int, unsigned int, unsigned char, int, int, int);
extern unsigned int DAT_0118947c;
extern unsigned int DAT_01189480;
extern unsigned int DAT_0118946c;
extern unsigned int DAT_01189468;
extern unsigned char DAT_011c70ec;
extern unsigned char DAT_011c6fba;

// Selects a D3D display mode and validates hardware T&L and shader support, storing chosen resolution and shader versions in DAT_0118947c and DAT_0118946c.
// @fnv 0x004dc710
unsigned char __cdecl FUN_004dc710()
{
    unsigned char success = 0;
    unsigned int screenWidth = GetSystemMetrics(0);
    unsigned int screenHeight = GetSystemMetrics(1);
    float screenAspect = (float)screenWidth / (float)screenHeight;
    if (FUN_004dce30())
    {
        DisplayAdapter* adapter = GetFltValueAt(FUN_004dc210());
        if (adapter)
        {
            success = FUN_00446e10();
            if (!success)
            {
                success = adapter->FUN_004dcd30(1);
                if (!success)
                    CopyStringToGlobal("Windowed mode not supported on this Adapter.");
            }
            if (success)
            {
                success = 0;
                unsigned int indexInfo = adapter->FUN_004dcce0();
                unsigned int selectedPos = indexInfo + 1;
                unsigned int selectedHeight = 0;
                while (indexInfo-- && !success)
                {
                    D3DDISPLAYMODE* mode = adapter->GetElementAt(indexInfo);
                    if (mode->RefreshRate >= 32 && mode->Format == MapIndexToValue(FUN_004dc270()))
                    {
                        if (!FUN_00446e10())
                        {
                            success = 1;
                            break;
                        }
                        float aspect = (float)mode->Width / (float)mode->Height;
                        if (std::abs(aspect - screenAspect) < (double)0.01f ||
                            (std::abs(screenAspect - 1.25) < (double)0.01f &&
                             std::abs(aspect - (double)(4.0f / 3.0f)) < (double)0.01f))
                        {
                            if (FUN_004dc1f0() == mode->Width && FUN_004dc200() == mode->Height)
                            {
                                success = 1;
                                break;
                            }
                            else if (FUN_00446e10() && FUN_004dc1f0() == mode->Width &&
                                     !(std::abs(aspect - 1.25) < (double)0.01f &&
                                       std::abs(aspect - (double)(4.0f / 3.0f)) < (double)0.01f) &&
                                     mode->Height > (unsigned int)FUN_004dc200() &&
                                     (selectedPos > adapter->FUN_004dcce0() || mode->Height > selectedHeight))
                            {
                                selectedPos = indexInfo;
                            }
                        }
                        else
                        {
                            if (FUN_004dc1f0() == mode->Width && FUN_004dc200() <= (int)mode->Height &&
                                selectedPos > adapter->FUN_004dcce0())
                                selectedPos = indexInfo;
                        }
                    }
                }
                if (!success && selectedPos > adapter->FUN_004dcce0())
                {
                    CopyStringToGlobal(
                        "Your display doesn't support the selected resolution.  Please set a different resolution in Fallout: New Vegas's Launcher under 'Display Settings'.");
                }
                else if (!success && selectedPos <= adapter->FUN_004dcce0())
                {
                    DAT_0118947c = adapter->GetElementAt(selectedPos)->Width;
                    DAT_01189480 = adapter->GetElementAt(selectedPos)->Height;
                    success = 1;
                    DAT_011c70ec = 1;
                }
            }
            if (success)
            {
                success = 0;
                D3DCAPS9* caps = adapter->FUN_004dc120(1);
                if (caps && FUN_004dcda0_Result())
                {
                    success = (caps->DevCaps & 0x10000) ? 1 : 0;
                    if (success)
                    {
                        success = ((caps->VertexShaderVersion & 0xffff) >= FUN_004dcd90() &&
                                   (caps->PixelShaderVersion & 0xffff) >= FUN_004dcd80())
                                      ? 1
                                      : 0;
                        if (!success)
                        {
                            CopyStringToGlobal(
                                "Pixel and Vertex Shader versions incorrect.  Requires a Geforce4 4400 or Radeon 8500 or better.");
                        }
                        else
                        {
                            DAT_0118946c = caps->VertexShaderVersion & 0xffff;
                            DAT_01189468 = caps->PixelShaderVersion & 0xffff;
                        }
                    }
                    else
                    {
                        CopyStringToGlobal("Hardware T&L required but not supported by Adapter.");
                    }
                    unsigned char separateAlpha = (caps->DevCaps & 0x1000000) ? 1 : 0;
                    DAT_011c6fba = separateAlpha & (FUN_004dc2b0_Result() > 1);
                }
                else
                {
                    DAT_0118946c = 0;
                    DAT_01189468 = 0;
                    DetectGpuVendor(DAT_01189468, DAT_0118946c, *g_011c74e0.Bool(), 0, 0, 0);
                    if (!FUN_004dcda0_Result())
                        success = 1;
                }
            }
        }
        else
        {
            CopyStringToGlobal("Bad Adapter Number or Adapter not found.");
        }
    }
    else
    {
        CopyStringToGlobal("No D3D Device description found.");
    }
    return success;
}
}  // namespace fnv_004dc710

class B004de530
{
  public:
    int unk[0x45];
    B004de530();
};
extern FUN_004de530* DAT_011f35a0;
// Allocates a B004de530 instance into DAT_011f35a0 if it is null.
// @fnv 0x004de4a0
void FUN_004de4a0()
{
    if (!DAT_011f35a0)
        DAT_011f35a0 = (FUN_004de530*)new B004de530;
}

extern "C" __declspec(dllimport) void* __stdcall LoadLibraryA(const char* pcFileName);
extern "C" __declspec(dllimport) void* __stdcall GetProcAddress(void* pvModule, const char* pcProcName);
extern int(__stdcall* DAT_00fdf0a8)(void* pvModule);

struct EFAdapterText
{
    unsigned int word00, word04, word08, word0c;
    unsigned int word10, word14, word18, word1c;
    unsigned int word20, word24, word28, word2c;
    unsigned int word30, word34, word38, word3c;
    unsigned int word40, word44, word48, word4c;
    unsigned int word50, word54, word58, word5c;
    unsigned int word60, word64, word68, word6c;
    unsigned int word70, word74, word78, word7c;
    unsigned int word80, word84, word88, word8c;
    unsigned int word90, word94, word98, word9c;
    unsigned int worda0, worda4, worda8, wordac;
    unsigned int wordb0, wordb4, wordb8, wordbc;
    unsigned int wordc0, wordc4, wordc8, wordcc;
    unsigned int wordd0, wordd4, wordd8, worddc;
    unsigned int worde0, worde4, worde8, wordec;
    unsigned int wordf0, wordf4, wordf8, wordfc;
};
struct EFAdapterInfo
{
    int iSize;
    int iAdapterIndex;
    EFAdapterText strUDID;
    int iBusNumber;
    int iDeviceNumber;
    int iFunctionNumber;
    int iVendorID;
    EFAdapterText strAdapterName;
    EFAdapterText strDisplayName;
    int iPresent;
    int iExist;
    EFAdapterText strDriverPath;
    EFAdapterText strDriverPathExt;
    EFAdapterText strPNPString;
    int iOSDisplayIndex;
};
struct EFDisplayTarget
{
    int iDisplayLogicalIndex;
    int iDisplayPhysicalIndex;
    int iDisplayLogicalAdapterIndex;
    int iDisplayPhysicalAdapterIndex;
    int iDisplayMapIndex;
    int iDisplayTargetMask;
    int iDisplayTargetValue;
};
struct EFMode
{
    int iAdapterIndex;
    int iDisplayLogicalIndex;
    int iDisplayPhysicalIndex;
    int iDisplayLogicalAdapterIndex;
    int iDisplayPhysicalAdapterIndex;
    int iXPos;
    int iYPos;
    int iXResTmp;
    int iYResData;
    int iColourDepth;
    float fRefreshRate;
    int iOrientation;
    int iModeFlag;
    int iModeMask;
    int iModeValue;
};
struct EFDisplayMap
{
    int iDisplayMapIndex;
    EFMode displayMode;
    int iNumDisplayTarget;
    int iFirstDisplayTargetArrayIndex;
    int iDisplayMapMask;
    int iDisplayMapValue;
};
struct EFSLSTarget
{
    int iAdapterIndex;
    int iSLSMapIndex;
    int iDisplayLogicalIndex;
    int iDisplayPhysicalIndex;
    int iDisplayLogicalAdapterIndex;
    int iDisplayPhysicalAdapterIndex;
    int iDisplayMapIndex;
    int iDisplayTargetMask;
    int iDisplayTargetValue;
    int iGridX;
    int iGridY;
    EFMode viewSize;
    int iSLSTargetMask;
    int iSLSTargetValue;
};
struct EFNativeMode
{
    int iAdapterIndex;
    int iSLSMapIndex;
    int iSLSModeIndex;
    int iModeAdapterIndex;
    int iDisplayLogicalIndex;
    int iDisplayPhysicalIndex;
    int iDisplayLogicalAdapterIndex;
    int iDisplayPhysicalAdapterIndex;
    int iXPos;
    int iYPos;
    int iXResTmp;
    int iYResData;
    int iColourDepth;
    float fRefreshRate;
    int iOrientation;
    int iModeFlag;
    int iModeMask;
    int iModeValue;
    int iSLSNativeModeMask;
    int iSLSNativeModeValue;
};
struct EFBezelMode
{
    int iAdapterIndex;
    int iSLSMapIndex;
    int iBezelModeIndex;
    int iModeAdapterIndex;
    int iDisplayLogicalIndex;
    int iDisplayPhysicalIndex;
    int iDisplayLogicalAdapterIndex;
    int iDisplayPhysicalAdapterIndex;
    int iXPos;
    int iYPos;
    int iXResTmp;
    int iYResData;
    int iColourDepth;
    float fRefreshRate;
    int iOrientation;
    int iModeFlag;
    int iModeMask;
    int iModeValue;
    int iNumBezelOffset;
    int iFirstBezelOffsetArrayIndex;
    int iSLSBezelTransientModeMask;
    int iSLSBezelTransientModeValue;
};
struct EFTransientMode
{
    int iAdapterIndex;
    int iSLSMapIndex;
    int iSLSModeIndex;
    EFMode displayMode;
    int iNumBezelOffset;
    int iFirstBezelOffsetArrayIndex;
    int iSLSBezelTransientModeMask;
    int iSLSBezelTransientModeValue;
};
struct EFSLSOffset
{
    int iAdapterIndex;
    int iSLSMapIndex;
    int iDisplayLogicalIndex;
    int iDisplayPhysicalIndex;
    int iDisplayLogicalAdapterIndex;
    int iDisplayPhysicalAdapterIndex;
    int iBezelModeIndex;
    int iLeft;
    int iTop;
    int iWidth;
    int iHeight;
    int iBezelOffsetMask;
    int iBezelOffsetValue;
};
struct EFSLSGrid
{
    int iAdapterIndex;
    int iSLSGridIndex;
    int iSLSGridRow;
    int iSLSGridColumn;
    int iSLSGridMask;
    int iSLSGridValue;
};
struct EFSLSMap
{
    int iAdapterIndex;
    int iSLSMapIndex;
    EFSLSGrid kGrid;
    int iSurfaceMapIndex;
    int iOrientation;
    int iNumSLSTarget;
    int iFirstSLSTargetArrayIndex;
    int iNumNativeMode;
    int iFirstNativeModeArrayIndex;
    int iNumBezelMode;
    int iFirstBezelModeArrayIndex;
    int iNumBezelOffset;
    int iFirstBezelOffsetArrayIndex;
    int iSLSMapMask;
    int iSLSMapValue;
};

struct EFRect
{
    int iLeft;
    int iTop;
    int iWidth;
    int iHeight;
};
struct EFDisplayInfo
{
    int iGridXCoord;
    int iGridYCoord;
    EFRect kDisplayRect;    // +0x08
    EFRect kVisibleRect;    // +0x18
    int iPreferredDisplay;  // +0x28
};
struct EFEyefinityInfo
{
    int iSLSActive;
    int iSLSGridWidth;
    int iSLSGridHeight;
    int iSLSWidth;
    int iSLSHeight;
    int iBezelCompensatedDisplay;
};

typedef int (*EFMainControlCreate)(void*(__stdcall* pfnAlloc)(unsigned int), int iEnumConnectedAdapters);
typedef int (*EFMainControlDestroy)();
typedef int (*EFNumberOfAdaptersGet)(int* piNumAdapters);
typedef int (*EFAdapterInfoGet)(EFAdapterInfo* pkInfo, int iInputSize);
typedef int (*EFSLSMapIndexGet)(int iAdapterIndex, int iTargetCount, EFDisplayTarget* pkTargets, int* piSLSMapIndex);
typedef int (*EFSLSMapConfigGet)(int iAdapterIndex, int iSLSMapIndex, EFSLSMap* pkMap, int* piNumTarget,
                                 EFSLSTarget** ppkTarget, int* piNumNative, EFNativeMode** ppkNative, int* piNumBezel,
                                 EFBezelMode** ppkBezel, int* piNumTransient, EFTransientMode** ppkTransient,
                                 int* piNumOffset, EFSLSOffset** ppkOffset, int iOption);
typedef int (*EFModesGet)(int iAdapterIndex, int iDisplayIndex, int* piNumModes, EFMode** ppkModes);
typedef int (*EFDisplayMapConfigGet)(int iAdapterIndex, int* piNumMap, EFDisplayMap** ppkMap, int* piNumTarget,
                                     EFDisplayTarget** ppkTarget, int iOptions);

void __stdcall ClearAndFreePointer(void* pointer);
void* FUN_00ec61c0(void* pvDst, int iValue, unsigned int uiSize);

// Loads the AMD Eyefinity DLL, queries the SLS map and display modes for the given adapter, and fills the output display and Eyefinity info arrays.
// @fnv 0x004dd2c0
int FUN_004dd2c0(int iDisplayIndex, EFEyefinityInfo* pkEyefinityInfo, int* piNumDisplaysInfo,
                 EFDisplayInfo** ppkDisplaysInfo)
{
    void* hDLL;
    EFMainControlCreate pfnCreateRef = 0;
    EFMainControlDestroy pfnDestroyPtr = 0;
    EFNumberOfAdaptersGet pfnNumAdaptersCount = 0;
    EFAdapterInfoGet pfnAdapterInfoNew = 0;
    EFSLSMapIndexGet pfnSLSMapIndexNew = 0;
    EFSLSMapConfigGet pfnSLSMapConfigRes = 0;
    EFModesGet pfnModesOut = 0;
    EFDisplayMapConfigGet pfnDisplayMapVal = 0;
    int iNumberAdapters = 0;
    int iIn = 0;
    EFAdapterInfo* pkAdapterInfoPos = 0;
    int iNumDisplayTargetRes = 0;
    EFDisplayTarget* pkDisplayTarget = 0;
    int iNumDisplayMap = 0;
    EFDisplayMap* pkDisplayMapPtr = 0;
    int iSLSMapIndex = 0;
    int iNumSLSTarget = 0;
    int tRef = 0;
    EFSLSTarget* pkSLSTargetPos = 0;
    int iNumNativeMode = 0;
    int kLocal = 0;
    EFNativeMode* pkNativeModeItem = 0;
    int iNumBezelMode = 0;
    int bVal = 0;
    EFBezelMode* pkBezelMode = 0;
    int iNumTransientMode = 0;
    EFTransientMode* pkTransientModeFinal = 0;
    int iNumSLSOffset = 0;
    int oPos = 0;
    EFSLSOffset* pkSLSOffsetIn = 0;
    int iNumModes = 0;
    EFMode* pkModesBase = 0;
    EFSLSMap kSLSMap;
    kSLSMap.iAdapterIndex = 0;
    FUN_00ec61c0(&kSLSMap.iSLSMapIndex, 0, sizeof(kSLSMap) - sizeof(kSLSMap.iAdapterIndex));
    EFDisplayInfo* pkCurrentOld = 0;
    int jTmp = 0;
    int iGoodMaskNext = 0;
    int iXResTmp = 0;
    int iYResData = 0;
    int bRotatedOld = 0;
    int iPrimaryColIn = 0;
    int iPrimaryRowLoc = 0;
    int bBezelInfo = 0;
    int iReturnValue = 1;
    int bFoundCount = 0;
    int iBadMaskNew = 0;

    if (!pkEyefinityInfo || !piNumDisplaysInfo || !ppkDisplaysInfo)
        return 0;
    hDLL = LoadLibraryA("atiadlxx.dll");
    if (!hDLL)
        hDLL = LoadLibraryA("atiadlxy.dll");
    if (!hDLL)
        return 0;
    pfnCreateRef = (EFMainControlCreate)GetProcAddress(hDLL, "ADL_Main_Control_Create");
    pfnDestroyPtr = (EFMainControlDestroy)GetProcAddress(hDLL, "ADL_Main_Control_Destroy");
    pfnNumAdaptersCount = (EFNumberOfAdaptersGet)GetProcAddress(hDLL, "ADL_Adapter_NumberOfAdapters_Get");
    pfnAdapterInfoNew = (EFAdapterInfoGet)GetProcAddress(hDLL, "ADL_Adapter_AdapterInfo_Get");
    pfnSLSMapIndexNew = (EFSLSMapIndexGet)GetProcAddress(hDLL, "ADL_Display_SLSMapIndex_Get");
    pfnSLSMapConfigRes = (EFSLSMapConfigGet)GetProcAddress(hDLL, "ADL_Display_SLSMapConfig_Get");
    pfnModesOut = (EFModesGet)GetProcAddress(hDLL, "ADL_Display_Modes_Get");
    pfnDisplayMapVal = (EFDisplayMapConfigGet)GetProcAddress(hDLL, "ADL_Display_DisplayMapConfig_Get");
    if (!pfnCreateRef || !pfnDestroyPtr || !pfnNumAdaptersCount || !pfnAdapterInfoNew || !pfnSLSMapIndexNew ||
        !pfnSLSMapConfigRes || !pfnModesOut || !pfnDisplayMapVal)
        return 0;
    if (pfnCreateRef(FUN_004dd240, 1))
        return 0;
    if (pfnNumAdaptersCount(&iNumberAdapters))
        return 0;
    if (iNumberAdapters)
    {
        pkAdapterInfoPos = (EFAdapterInfo*)FUN_004dd240(sizeof(EFAdapterInfo) * iNumberAdapters);
        if (!pkAdapterInfoPos)
            return 0;
        FUN_00403d30(pkAdapterInfoPos, 0, sizeof(EFAdapterInfo) * iNumberAdapters);
        if (pfnAdapterInfoNew(pkAdapterInfoPos, sizeof(EFAdapterInfo) * iNumberAdapters))
            return 0;
    }
    else
        return 0;
    for (iIn = 0; iIn < iNumberAdapters; iIn++)
    {
        if (pkAdapterInfoPos[iIn].iOSDisplayIndex != iDisplayIndex)
            continue;
        if (pfnDisplayMapVal(pkAdapterInfoPos[iIn].iAdapterIndex, &iNumDisplayMap, &pkDisplayMapPtr,
                             &iNumDisplayTargetRes, &pkDisplayTarget, 1))
        {
            iReturnValue = 0;
            break;
        }
        if (iNumDisplayTargetRes < 2)
            break;
        if (pfnSLSMapIndexNew(pkAdapterInfoPos[iIn].iAdapterIndex, iNumDisplayTargetRes, pkDisplayTarget,
                              &iSLSMapIndex))
            break;
        if (pfnSLSMapConfigRes(pkAdapterInfoPos[iIn].iAdapterIndex, iSLSMapIndex, &kSLSMap, &iNumSLSTarget,
                               &pkSLSTargetPos, &iNumNativeMode, &pkNativeModeItem, &iNumBezelMode, &pkBezelMode,
                               &iNumTransientMode, &pkTransientModeFinal, &iNumSLSOffset, &pkSLSOffsetIn, 2))
        {
            iReturnValue = 0;
            break;
        }
        if (iNumDisplayTargetRes != kSLSMap.kGrid.iSLSGridColumn * kSLSMap.kGrid.iSLSGridRow)
        {
            iReturnValue = 0;
            break;
        }
        switch (kSLSMap.kGrid.iSLSGridColumn)
        {
        default:
            iPrimaryColIn = 0;
            break;
        case 3:
        case 4:
            iPrimaryColIn = 1;
            break;
        case 5:
        case 6:
            iPrimaryColIn = 2;
        }
        iPrimaryRowLoc = kSLSMap.kGrid.iSLSGridRow - 1;
        for (jTmp = 0; jTmp < iNumDisplayTargetRes; jTmp++)
        {
            ClearAndFreePointer(&pkModesBase);
            if (pfnModesOut(pkAdapterInfoPos[iIn].iAdapterIndex, pkDisplayTarget[jTmp].iDisplayLogicalIndex, &iNumModes,
                            &pkModesBase))
            {
                iBadMaskNew |= 1 << jTmp;
                continue;
            }
            for (kLocal = 0; kLocal < iNumNativeMode; kLocal++)
            {
                if (pkModesBase->iXResTmp == pkNativeModeItem[kLocal].iXResTmp &&
                    pkModesBase->iYResData == pkNativeModeItem[kLocal].iYResData)
                {
                    iGoodMaskNext |= 1 << jTmp;
                    break;
                }
            }
            if (!(iGoodMaskNext & (1 << jTmp)))
            {
                for (bVal = 0; bVal < iNumBezelMode; bVal++)
                {
                    if (pkModesBase->iXResTmp == pkBezelMode[bVal].iXResTmp &&
                        pkModesBase->iYResData == pkBezelMode[bVal].iYResData)
                    {
                        iGoodMaskNext |= 1 << jTmp;
                        bBezelInfo = 1;
                        break;
                    }
                }
            }
            if (iGoodMaskNext & (1 << jTmp))
            {
                if (!*ppkDisplaysInfo)
                {
                    *ppkDisplaysInfo = (EFDisplayInfo*)FUN_004dd240(sizeof(EFDisplayInfo) * iNumDisplayTargetRes);
                    if (!*ppkDisplaysInfo)
                    {
                        iReturnValue = 0;
                        break;
                    }
                    FUN_00403d30(*ppkDisplaysInfo, 0, sizeof(EFDisplayInfo) * iNumDisplayTargetRes);
                }
                for (tRef = 0; tRef < iNumSLSTarget; tRef++)
                {
                    if (pkDisplayTarget[jTmp].iDisplayLogicalIndex == pkSLSTargetPos[tRef].iDisplayLogicalIndex)
                    {
                        bFoundCount = 1;
                        break;
                    }
                }
                if (!bFoundCount)
                {
                    iReturnValue = 0;
                    break;
                }
                iXResTmp = pkModesBase->iXResTmp;
                iYResData = pkModesBase->iYResData;
                if (pkModesBase->iOrientation != 0 && pkModesBase->iOrientation != 180)
                    bRotatedOld = 1;
                pkCurrentOld = &(*ppkDisplaysInfo)[jTmp];
                pkCurrentOld->iGridXCoord = pkSLSTargetPos[tRef].iGridX;
                pkCurrentOld->iGridYCoord = pkSLSTargetPos[tRef].iGridY;
                if (!bRotatedOld)
                {
                    pkCurrentOld->kDisplayRect.iWidth = pkModesBase->iXResTmp / kSLSMap.kGrid.iSLSGridColumn;
                    pkCurrentOld->kDisplayRect.iHeight = pkModesBase->iYResData / kSLSMap.kGrid.iSLSGridRow;
                }
                else
                {
                    pkCurrentOld->kDisplayRect.iWidth = pkModesBase->iYResData / kSLSMap.kGrid.iSLSGridColumn;
                    pkCurrentOld->kDisplayRect.iHeight = pkModesBase->iXResTmp / kSLSMap.kGrid.iSLSGridRow;
                }
                pkCurrentOld->kDisplayRect.iLeft = pkCurrentOld->kDisplayRect.iWidth * pkSLSTargetPos[tRef].iGridX;
                pkCurrentOld->kDisplayRect.iTop = pkCurrentOld->kDisplayRect.iHeight * pkSLSTargetPos[tRef].iGridY;
                if (bBezelInfo == 1)
                {
                    for (oPos = 0; oPos < iNumSLSOffset; oPos++)
                    {
                        if (pkBezelMode[bVal].iBezelModeIndex == pkSLSOffsetIn[oPos].iBezelModeIndex &&
                            pkDisplayTarget[jTmp].iDisplayLogicalIndex == pkSLSOffsetIn[oPos].iDisplayLogicalIndex)
                        {
                            bFoundCount = 1;
                            break;
                        }
                    }
                    if (!bFoundCount)
                    {
                        iReturnValue = 0;
                        break;
                    }
                    pkCurrentOld->kVisibleRect.iWidth = pkSLSOffsetIn[oPos].iWidth;
                    pkCurrentOld->kVisibleRect.iHeight = pkSLSOffsetIn[oPos].iHeight;
                    pkCurrentOld->kVisibleRect.iLeft = pkSLSOffsetIn[oPos].iLeft;
                    pkCurrentOld->kVisibleRect.iTop = pkSLSOffsetIn[oPos].iTop;
                }
                else
                    pkCurrentOld->kVisibleRect = pkCurrentOld->kDisplayRect;
                if (iPrimaryColIn == pkSLSTargetPos[tRef].iGridX && iPrimaryRowLoc == pkSLSTargetPos[tRef].iGridY)
                    pkCurrentOld->iPreferredDisplay = 1;
            }
        }
        if (iGoodMaskNext && iReturnValue == 1)
        {
            pkEyefinityInfo->iSLSActive = 1;
            pkEyefinityInfo->iSLSGridWidth = kSLSMap.kGrid.iSLSGridColumn;
            pkEyefinityInfo->iSLSGridHeight = kSLSMap.kGrid.iSLSGridRow;
            if (!bRotatedOld)
            {
                pkEyefinityInfo->iSLSWidth = iXResTmp;
                pkEyefinityInfo->iSLSHeight = iYResData;
            }
            else
            {
                pkEyefinityInfo->iSLSWidth = iYResData;
                pkEyefinityInfo->iSLSHeight = iXResTmp;
            }
            if (bBezelInfo == 1)
                pkEyefinityInfo->iBezelCompensatedDisplay = 1;
            *piNumDisplaysInfo = iNumDisplayTargetRes;
        }
        break;
    }
    if (iGoodMaskNext && iBadMaskNew)
    {
        EFDisplayInfo* pkReference = 0;
        for (jTmp = 0; jTmp < iNumDisplayTargetRes; jTmp++)
        {
            if (!(iBadMaskNew & (1 << jTmp)))
            {
                pkReference = &(*ppkDisplaysInfo)[jTmp];
                break;
            }
        }
        if (pkCurrentOld)
        {
            for (jTmp = 0; jTmp < iNumDisplayTargetRes; jTmp++)
            {
                if (iBadMaskNew & (1 << jTmp))
                {
                    for (tRef = 0; tRef < iNumSLSTarget; tRef++)
                    {
                        if (pkDisplayTarget[jTmp].iDisplayLogicalIndex == pkSLSTargetPos[tRef].iDisplayLogicalIndex)
                        {
                            bFoundCount = 1;
                            break;
                        }
                    }
                    if (!bFoundCount)
                    {
                        iReturnValue = 0;
                        break;
                    }
                    pkCurrentOld = &(*ppkDisplaysInfo)[jTmp];
                    pkCurrentOld->iGridXCoord = pkSLSTargetPos[tRef].iGridX;
                    pkCurrentOld->iGridYCoord = pkSLSTargetPos[tRef].iGridY;
                    pkCurrentOld->kDisplayRect.iWidth = pkReference->kDisplayRect.iWidth;
                    pkCurrentOld->kDisplayRect.iHeight = pkReference->kDisplayRect.iHeight;
                    pkCurrentOld->kDisplayRect.iLeft = pkReference->kDisplayRect.iWidth * pkSLSTargetPos[tRef].iGridX;
                    pkCurrentOld->kDisplayRect.iTop = pkReference->kDisplayRect.iHeight * pkSLSTargetPos[tRef].iGridY;
                    if (bBezelInfo == 1)
                    {
                        pkCurrentOld->kVisibleRect.iWidth = pkReference->kVisibleRect.iWidth;
                        pkCurrentOld->kVisibleRect.iHeight = pkReference->kVisibleRect.iHeight;
                        if (pkSLSTargetPos[tRef].iGridX == 0)
                            pkCurrentOld->kVisibleRect.iLeft = 0;
                        else if (pkSLSTargetPos[tRef].iGridX == kSLSMap.kGrid.iSLSGridColumn - 1)
                            pkCurrentOld->kVisibleRect.iLeft = iXResTmp - pkReference->kVisibleRect.iWidth;
                        else
                            pkCurrentOld->kVisibleRect.iLeft =
                                (pkReference->kDisplayRect.iWidth - pkReference->kVisibleRect.iWidth) / 2 +
                                pkCurrentOld->kDisplayRect.iLeft;
                        if (pkSLSTargetPos[tRef].iGridY == 0)
                            pkCurrentOld->kVisibleRect.iTop = 0;
                        else if (pkSLSTargetPos[tRef].iGridY == kSLSMap.kGrid.iSLSGridRow - 1)
                            pkCurrentOld->kVisibleRect.iTop = iYResData - pkReference->kVisibleRect.iHeight;
                        else
                            pkCurrentOld->kVisibleRect.iTop =
                                (pkReference->kDisplayRect.iHeight - pkReference->kVisibleRect.iHeight) / 2 +
                                pkCurrentOld->kDisplayRect.iTop;
                    }
                    else
                        pkCurrentOld->kVisibleRect = pkCurrentOld->kDisplayRect;
                    if (iPrimaryColIn == pkSLSTargetPos[tRef].iGridX && iPrimaryRowLoc == pkSLSTargetPos[tRef].iGridY)
                        pkCurrentOld->iPreferredDisplay = 1;
                }
            }
        }
        else
            iReturnValue = 0;
    }
    ClearAndFreePointer(&pkModesBase);
    ClearAndFreePointer(&pkSLSTargetPos);
    ClearAndFreePointer(&pkNativeModeItem);
    ClearAndFreePointer(&pkBezelMode);
    ClearAndFreePointer(&pkTransientModeFinal);
    ClearAndFreePointer(&pkSLSOffsetIn);
    ClearAndFreePointer(&pkDisplayMapPtr);
    ClearAndFreePointer(&pkDisplayTarget);
    ClearAndFreePointer(&pkAdapterInfoPos);
    pfnDestroyPtr = (EFMainControlDestroy)GetProcAddress(hDLL, "ADL_Main_Control_Destroy");
    if (pfnDestroyPtr)
        pfnDestroyPtr();
    DAT_00fdf0a8(hDLL);
    if (!iReturnValue)
    {
        FUN_004dd2a0(ppkDisplaysInfo);
        *piNumDisplaysInfo = 0;
        FUN_00403d30(pkEyefinityInfo, 0, sizeof(pkEyefinityInfo));
    }
    return iReturnValue;
}
