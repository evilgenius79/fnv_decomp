
// src/staging/blk_00860000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

extern int DAT_01081fa0;
struct FUN_00863e00_cls
{
    virtual void vfn();
    void FUN_008641d0(int a, int b);
    int* FUN_00863e00(int a, int b);
};
// Calls FUN_008641d0 with the two arguments, stores the address of DAT_01081fa0 at offset 0 of this, and returns this.
// @fnv 0x00863e00
int* FUN_00863e00_cls::FUN_00863e00(int a, int b)
{
    FUN_008641d0(a, b);
    *(int**)((char*)this + 0) = &DAT_01081fa0;
    return (int*)this;
}

struct FUN_008640e0_class
{
    void __thiscall DestroyAndFreeBuffer();
    void __thiscall FUN_008640e0();
};
// @fnv 0x008640e0
void __thiscall FUN_008640e0_class::FUN_008640e0()
{
    DestroyAndFreeBuffer();
}

struct FUN_00865900_Class
{
    void __thiscall CreateInstance();
};

struct FUN_00865870_Class
{
    void __thiscall FUN_00865870();
};

// @fnv 0x00865870
void __thiscall FUN_00865870_Class::FUN_00865870()
{
    ((FUN_00865900_Class*)((char*)this + 0xc))->CreateInstance();
}

struct FUN_00865980_class
{
    void __thiscall FUN_008659a0();
    int __thiscall FUN_00865980();
};

// @fnv 0x00865980
int __thiscall FUN_00865980_class::FUN_00865980()
{
    FUN_008659a0();
    return (int)this;
}

struct CF_0081c630
{
    CF_0081c630();
};

struct FUN_008659a0_Class
{
    int a;
    int b;
    CF_0081c630 member;
    FUN_008659a0_Class();
};

// @fnv 0x008659a0
FUN_008659a0_Class::FUN_008659a0_Class()
{}

void __fastcall SignalAtOffset18(char*);

struct FUN_00866dc0_Class
{
    char** m_pArr;
    void FUN_00866dc0(int idx);
};

// @fnv 0x00866dc0
void FUN_00866dc0_Class::FUN_00866dc0(int aiIndex)
{
    SignalAtOffset18(*(*(char***)((char*)this + 0x50) + aiIndex));
}

extern int DAT_011de804;

// @fnv 0x00869180
bool __cdecl HasFlags(int flags)
{
    return (DAT_011de804 & flags) ? true : false;
}

struct FUN_008693f0_Class
{
    void __thiscall FUN_008693f0(int aiParam);
    void __thiscall FUN_00869680(unsigned short auParam, int aiParam);
};

// Calls FUN_00869680 with the unsigned short at offset 0xa of this object and the given int.
// @fnv 0x008693f0
void __thiscall FUN_008693f0_Class::FUN_008693f0(int aiParam)
{
    FUN_00869680(*(unsigned short*)((char*)this + 0xa), aiParam);
}

extern "C" void __cdecl Deallocate(void*);

// @fnv 0x008696c0
void __cdecl FUN_008696c0(void* apMemory)
{
    void* q = apMemory;
    Deallocate(q);
}

extern int DAT_010827f0;
void __cdecl FUN_008696c0(int);

struct FUN_00869a40_Class
{
    void* m_ppVirtualMethodTable;
    int m_field;
    void FUN_00869a40();
};

// @fnv 0x00869a40
void FUN_00869a40_Class::FUN_00869a40()
{
    m_ppVirtualMethodTable = &DAT_010827f0;
    FUN_008696c0(m_field);
}

extern int DAT_01082800;
void __cdecl FUN_008696c0(int);
struct FUN_00869b90_cls
{
    int vtbl;
    int next;
    void InitializeAndReleaseNext();
};
// Sets the object's vtbl to DAT_01082800 and passes next to FUN_008696c0.
// @fnv 0x00869b90
void FUN_00869b90_cls::InitializeAndReleaseNext()
{
    vtbl = (int)&DAT_01082800;
    FUN_008696c0(next);
}

extern void* DAT_01082808;
struct FUN_00869d40;
struct FUN_00869c60
{
    void* vfn;
    void FUN_00869d40(unsigned int a, unsigned int b);
    FUN_00869c60(unsigned int a, unsigned int b);
};

// Calls FUN_00869d40 with the two arguments, then sets vfn to point at DAT_01082808.
// @fnv 0x00869c60
FUN_00869c60::FUN_00869c60(unsigned int auiFirst, unsigned int auiSecond)
{
    FUN_00869d40(auiFirst, auiSecond);
    vfn = &DAT_01082808;
}

struct FUN_00869cc0_class
{
    void FUN_00869ce0();
    void FUN_00869cc0();
};

// @fnv 0x00869cc0
void FUN_00869cc0_class::FUN_00869cc0()
{
    FUN_00869ce0();
}

extern int DAT_01082810;
void __cdecl FUN_008696c0(int);
struct FUN_00869ce0_cls
{
    int vtbl;
    int field4;
    void FUN_00869ce0();
};
// Sets the vtable pointer to DAT_01082810 and calls FUN_008696c0 with field4.
// @fnv 0x00869ce0
void FUN_00869ce0_cls::FUN_00869ce0()
{
    vtbl = (int)&DAT_01082810;
    FUN_008696c0(field4);
}

extern int DAT_01082820;
void __cdecl FUN_004b0220(int);

struct FUN_00869e30_class
{
    void* p;
    int f;
    void FUN_00869e30();
};

// Sets p to point at DAT_01082820 and calls FUN_004b0220 with f.
// @fnv 0x00869e30
void FUN_00869e30_class::FUN_00869e30()
{
    p = &DAT_01082820;
    FUN_004b0220(f);
}

struct CountingSemaphore
{
    void Signal();
};
struct FUN_0086c600_shell
{
    void SignalAtOffset();
};
// @fnv 0x0086c600
void FUN_0086c600_shell::SignalAtOffset()
{
    ((CountingSemaphore*)((char*)this + 0x14))->Signal();
}

namespace fnv_0086cdd0 {
struct CountingSemaphore
{
    void Wait();
};
struct FUN_0086cdd0
{
    void Wait();
};

// @fnv 0x0086cdd0
void FUN_0086cdd0::Wait()
{
    ((CountingSemaphore*)((char*)this + 0x14))->Wait();
}
}  // namespace fnv_0086cdd0

struct ImageSpaceTexture
{
    void AddRenderedTexture();
};

struct FUN_00876a00_Class
{
    void FUN_00876a00();
};

// @fnv 0x00876a00
void FUN_00876a00_Class::FUN_00876a00()
{
    ((ImageSpaceTexture*)((char*)this + 0x7c))->AddRenderedTexture();
}

struct FUN_00877a10_Class
{
    void __thiscall FUN_0044f650();
    void __thiscall FUN_00877a10();
};

// @fnv 0x00877a10
void __thiscall FUN_00877a10_Class::FUN_00877a10()
{
    FUN_0044f650();
}

extern "C" void __cdecl DAT_01082f24();

struct FUN_00877b40
{
    void __thiscall SetVtable();
    void __thiscall Init();
};

// @fnv 0x00877b40
void __thiscall FUN_00877b40::Init()
{
    *(void**)this = &DAT_01082f24;
    SetVtable();
}

extern int DAT_01082f44;

struct FUN_00877b60_Class
{
    void __thiscall SetVtable();
};

// @fnv 0x00877b60
void __thiscall FUN_00877b60_Class::SetVtable()
{
    *reinterpret_cast<int*>(this) = (int)&DAT_01082f44;
}

struct FUN_00877d30_Class
{
    void FUN_00877d30();
};

// @fnv 0x00877d30
void FUN_00877d30_Class::FUN_00877d30()
{
    *(char*)((char*)this + 0x40) = 1;
}

namespace fnv_00877d80 {
extern int DAT_01082f24;
struct BSTCommonMessageQueue
{
    virtual ~BSTCommonMessageQueue();
    void* __thiscall FUN_00877df0();
    void* __thiscall Construct();
};
// Calls FUN_00877df0, installs the vtable pointer at offset 0 and clears the field at offset 4, then returns this.
// @fnv 0x00877d80
void* __thiscall BSTCommonMessageQueue::Construct()
{
    FUN_00877df0();
    *reinterpret_cast<void**>(this) = &DAT_01082f24;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 4) = 0;
    return this;
}
}  // namespace fnv_00877d80

extern int DAT_01082f44;

struct FUN_00877df0
{
    void* m_vft;
    FUN_00877df0();
};

// @fnv 0x00877df0
FUN_00877df0::FUN_00877df0()
{
    m_vft = &DAT_01082f44;
}

struct FUN_00878110_Class
{
    unsigned int __thiscall FUN_00878110();
};

// @fnv 0x00878110
unsigned int __thiscall FUN_00878110_Class::FUN_00878110()
{
    return *(unsigned int*)((char*)this + 0x134);
}

struct FUN_00878130_Class
{
    int m_0x134;
    int ResetAndGetValue();
};

// Sets the int at offset 0x134 of this object to 0 and returns that value.
// @fnv 0x00878130
int FUN_00878130_Class::ResetAndGetValue()
{
    *(int*)((char*)this + 0x134) = 0;
    return *(int*)((char*)this + 0x134);
}

namespace fnv_0087a6f0 {
struct FUN_0086c600_shell
{
    void* __thiscall SignalAtOffset();
};

struct FUN_0087a6f0_shell
{
    void* __thiscall FUN_0087a6f0();
};

// @fnv 0x0087a6f0
void* __thiscall FUN_0087a6f0_shell::FUN_0087a6f0()
{
    return reinterpret_cast<FUN_0086c600_shell*>(reinterpret_cast<void**>(this)[1])->SignalAtOffset();
}
}  // namespace fnv_0087a6f0

struct FUN_0086cdd0_shell
{
    void FUN_0086cdd0();
};
struct FUN_0087a710_shell
{
    int pad;
    FUN_0086cdd0_shell* p;
    void FUN_0087a710();
};
// @fnv 0x0087a710
void __thiscall FUN_0087a710_shell::FUN_0087a710()
{
    p->FUN_0086cdd0();
}

struct FUN_0087a770
{
    bool IsEmpty();
    void DoWork();
};

// @fnv 0x0087a770
void FUN_0087a770::DoWork()
{
    IsEmpty();
}

extern int DAT_010840d0;
struct FUN_0087d2c0_class
{
    void* vtable;
    void FUN_0087d340(int a, int b);
    FUN_0087d2c0_class* FUN_0087d2c0();
};
// @fnv 0x0087d2c0
FUN_0087d2c0_class* FUN_0087d2c0_class::FUN_0087d2c0()
{
    vtable = &DAT_010840d0;
    FUN_0087d340(0, 0);
    return this;
}

extern int DAT_010840d0;
struct GlobalObject_00869f00
{
    void Clear(bool);
    void FUN_0087d320();
};
// @fnv 0x0087d320
void GlobalObject_00869f00::FUN_0087d320()
{
    *reinterpret_cast<int*>(this) = (int)&DAT_010840d0;
    Clear(true);
}

extern int DAT_010840e4;

struct Caller00822860
{
    void FUN_00822860(unsigned int, bool);
    void* FUN_0087d420();
};

// @fnv 0x0087d420
void* Caller00822860::FUN_0087d420()
{
    *(void**)(this) = (void*)&DAT_010840e4;
    FUN_00822860(0, false);
    return this;
}

struct Arr3520
{
    void* p;
    void RemoveAll(bool);
    void FUN_0087d480();
};

extern int DAT_010840e4;

// @fnv 0x0087d480
void Arr3520::FUN_0087d480()
{
    p = &DAT_010840e4;
    RemoveAll(true);
}

struct TaskQueueInterface
{
    void SetTaskFlagDWord(bool, unsigned int);
    void FUN_0087e100(bool argument0);
};

// @fnv 0x0087e100
void TaskQueueInterface::FUN_0087e100(bool abFlag)
{
    SetTaskFlagDWord(abFlag == 0, 0x800000);
}

struct FUN_0087e920_class
{
    bool FUN_0087e920();
};

// @fnv 0x0087e920
bool FUN_0087e920_class::FUN_0087e920()
{
    return ((const unsigned char*)this)[0x60] & 4;
}

struct FUN_0087e940_cls
{
    bool FUN_0087e940();
};

// @fnv 0x0087e940
bool FUN_0087e940_cls::FUN_0087e940()
{
    return reinterpret_cast<unsigned char*>(this)[0x60] & 0x20;
}

struct FUN_0087e960_Class
{
    void SetByteAtOffset1B0(char value);
};

// @fnv 0x0087e960
void FUN_0087e960_Class::SetByteAtOffset1B0(char value)
{
    ((char*)this)[0x1b0] = value;
}

struct Flt
{
    operator unsigned int();
};

struct FUN_0087e980_class
{
    unsigned int FUN_0087e980();
};

// @fnv 0x0087e980
unsigned int FUN_0087e980_class::FUN_0087e980()
{
    return reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0x594)->operator unsigned int();
}

struct FUN_0087ea40_class
{
    void FUN_0087ea40(int value);
};

// @fnv 0x0087ea40
void FUN_0087ea40_class::FUN_0087ea40(int value)
{
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x5c) = value;
}

struct ABD_005f92d0
{
    bool GetFlag(unsigned int) const;
};

struct FUN_0087f480_Class
{
    bool FUN_0087f480();
};

// @fnv 0x0087f480
bool FUN_0087f480_Class::FUN_0087f480()
{
    return ((ABD_005f92d0*)this)->GetFlag(2);
}

extern "C" void __cdecl _NiFreeAlias(void*);
extern void* DAT_01081fa8;

struct FUN_00863f00 : public NiTPointerMap<int, int>
{
    void Init();
};

// Sets the vtable pointer, clears the map with RemoveAll, and frees the pointer stored at offset 8.
// @fnv 0x00863f00
void FUN_00863f00::Init()
{
    *(void**)this = &DAT_01081fa8;
    RemoveAll();
    _NiFreeAlias(*(void**)((char*)this + 8));
}

struct NiRenderer
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
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
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
};

NiRenderer* __cdecl FUN_0043c4b0();

// If FUN_0043c4b0 returns a renderer, calls its vfn_8c virtual method, then returns 0.
// @fnv 0x0086a020
int __cdecl FUN_0086a020()
{
    if (FUN_0043c4b0())
    {
        NiRenderer* renderer = FUN_0043c4b0();
        renderer->vfn_8c();
    }
    return 0;
}

struct FUN_00863db0_class
{
    void* vtbl;
    int* items;
    int pad;
    unsigned int count;
    unsigned int cap;
    void __thiscall ClearItems();
};
// Sets every element of items to 0, then resets count and cap to 0.
// @fnv 0x00863db0
void __thiscall FUN_00863db0_class::ClearItems()
{
    for (unsigned int i = 0; i < count; ++i)
        items[i] = 0;
    count = 0;
    cap = 0;
}

void* __cdecl _NiMalloc(unsigned int);
void* __cdecl memset(void*, int, unsigned int);
struct FUN_00863e30_struct
{
    void* m_pVTable;
    unsigned int m_uiCount;
    void** m_pData;
    int m_iPad;
    void* FUN_00863e30(unsigned int ItemUpdateArray);
};
// Sets the vtable, stores the count, allocates count*4 bytes for m_pData, zeroes them, and returns this.
// @fnv 0x00863e30
void* FUN_00863e30_struct::FUN_00863e30(unsigned int auiCount)
{
    m_pVTable = &DAT_01081fa8;
    m_uiCount = auiCount;
    m_iPad = 0;
    unsigned int uiSize = m_uiCount * 4;
    m_pData = static_cast<void**>(_NiMalloc(uiSize));
    memset(m_pData, 0, m_uiCount * 4);
    return this;
}

extern "C" void __cdecl Deallocate(void*);
struct FUN_008636a0
{
    void __thiscall Init();
};
struct FUN_00863f60_cls
{
    void* __thiscall InitAndMaybeFree(unsigned int flags);
};
// Calls Init on this, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x00863f60
void* __thiscall FUN_00863f60_cls::InitAndMaybeFree(unsigned int flags)
{
    ((FUN_008636a0*)this)->Init();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_008637a0_class
{
    void __thiscall FUN_008637a0();
};
struct FUN_00863f90_class
{
    void __thiscall FUN_008637a0();
    void* __thiscall FUN_00863f90(unsigned int flags);
};
// @fnv 0x00863f90
void* __thiscall FUN_00863f90_class::FUN_00863f90(unsigned int flags)
{
    FUN_008637a0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern "C" void __cdecl Deallocate(void*);
struct FUN_008638c0_Class
{
    void __thiscall FUN_008638c0();
    void* __thiscall FUN_00863fc0(unsigned int flags);
};
// Calls FUN_008638c0, then frees this via Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00863fc0
void* __thiscall FUN_008638c0_Class::FUN_00863fc0(unsigned int flags)
{
    FUN_008638c0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern "C" void __cdecl Deallocate(void*);
struct FUN_00863ff0_class
{
    void __thiscall FUN_008639c0();
    void* __thiscall FUN_00863ff0(unsigned int flags);
};
// @fnv 0x00863ff0
void* __thiscall FUN_00863ff0_class::FUN_00863ff0(unsigned int flags)
{
    FUN_008639c0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct NiTPointerMap_Standin
{
    void __thiscall ClearAndFree();
};
struct FUN_00864020_Class
{
    void* __thiscall FUN_00864020(unsigned int flags);
};
// @fnv 0x00864020
void* __thiscall FUN_00864020_Class::FUN_00864020(unsigned int flags)
{
    reinterpret_cast<NiTPointerMap_Standin*>(this)->ClearAndFree();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_00863d60_obj
{
    void __thiscall FUN_00863d60();
};

struct FUN_00864050_class
{
    void* __thiscall FUN_00864050(unsigned int flags);
};

// @fnv 0x00864050
void* __thiscall FUN_00864050_class::FUN_00864050(unsigned int flags)
{
    reinterpret_cast<FUN_00863d60_obj*>(this)->FUN_00863d60();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_00857350_obj
{
    void FUN_00857350();
};
struct FUN_00864080_shell
{
    void* __thiscall FUN_00864080(unsigned int flags);
};
// @fnv 0x00864080
void* __thiscall FUN_00864080_shell::FUN_00864080(unsigned int flags)
{
    ((FUN_00857350_obj*)this)->FUN_00857350();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void __cdecl Deallocate(void*);
struct FUN_008640b0_Class
{
    void* __thiscall FUN_008640b0(unsigned int flags);
};
// Calls Init on this, frees this when flags has bit 0 set, and returns this.
// @fnv 0x008640b0
void* __thiscall FUN_008640b0_Class::FUN_008640b0(unsigned int flags)
{
    reinterpret_cast<FUN_00863f00*>(this)->Init();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_00864130_Class
{
    void* __thiscall FUN_00864130(unsigned int flags);
};
// @fnv 0x00864130
void* __thiscall FUN_00864130_Class::FUN_00864130(unsigned int flags)
{
    ((FUN_008640e0_class*)this)->DestroyAndFreeBuffer();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern void* DAT_0126fac4;

// If DAT_0126fac4 is set, calls its first virtual method with 1, then clears DAT_0126fac4.
// @fnv 0x00867090
void __cdecl FUN_00867090()
{
    void* p = DAT_0126fac4;
    void* RunFourthVirtual = p;
    void* result;
    if (RunFourthVirtual)
        result = ((void*(__thiscall*)(void*, int)) * ((void***)RunFourthVirtual)[0])(RunFourthVirtual, 1);
    else
        result = 0;
    DAT_0126fac4 = 0;
}

void __fastcall FUN_00867a20(void*);
void __fastcall ZeroSixInts(void*);
// @fnv 0x008677d0
void* __fastcall FUN_008677d0(void* p)
{
    *(int*)p = 0;
    *(int*)((char*)p + 4) = 0;
    *(int*)((char*)p + 8) = 0;
    *(int*)((char*)p + 12) = 0;
    *(int*)((char*)p + 16) = 0;
    *(int*)((char*)p + 20) = 0;
    *(int*)((char*)p + 24) = 0;
    FUN_00867a20(p);
    ZeroSixInts(p);
    return p;
}

// Writes zero to the six consecutive ints starting at p.
// @fnv 0x00867840
void __fastcall ZeroSixInts(int* piValues)
{
    piValues[0] = 0;
    piValues[1] = 0;
    piValues[2] = 0;
    piValues[3] = 0;
    piValues[4] = 0;
    piValues[5] = 0;
}

struct FUN_00869600_Class
{
    unsigned int __thiscall FUN_00869600();
};

// @fnv 0x00869600
unsigned int __thiscall FUN_00869600_Class::FUN_00869600()
{
    return *(unsigned int*)((char*)this + 0xc) > 0x800 ? *(unsigned int*)((char*)this + 0xc) - 0x400
                                                       : *(unsigned int*)((char*)this + 0xc) >> 1;
}

struct FUN_00869a20_class
{
    void FUN_00869a40();
    void* FUN_00869a70(unsigned int flags);
};
// @fnv 0x00869a70
void* FUN_00869a20_class::FUN_00869a70(unsigned int flags)
{
    FUN_00869a40();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct GlobalObject_00869b10
{
    void __thiscall FUN_00869b70();
    GlobalObject_00869b10* __thiscall FUN_00869b40(unsigned int flags);
    ~GlobalObject_00869b10();
};
// Calls FUN_00869b70, then deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x00869b40
GlobalObject_00869b10* __thiscall GlobalObject_00869b10::FUN_00869b40(unsigned int flags)
{
    FUN_00869b70();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern "C" void __cdecl Deallocate(void*);

struct GlobalObject_00869c60
{
    virtual void vfn();
    void __thiscall FUN_00869cc0();
    GlobalObject_00869c60* __thiscall FUN_00869c90(unsigned int flags);
};

// @fnv 0x00869c90
GlobalObject_00869c60* GlobalObject_00869c60::FUN_00869c90(unsigned int flags)
{
    FUN_00869cc0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void __cdecl FUN_008696c0(int);
void __cdecl FUN_008696c0(int);
void __cdecl FUN_008696c0(int);
void __cdecl FUN_008696c0(int);
void __cdecl FUN_008696c0(int);
struct FUN_00869d10_cls
{
    void __thiscall FUN_00869ce0();
    FUN_00869d10_cls* __thiscall FUN_00869d10(unsigned int flags);
};
// Calls FUN_00869ce0, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x00869d10
FUN_00869d10_cls* __thiscall FUN_00869d10_cls::FUN_00869d10(unsigned int flags)
{
    FUN_00869ce0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_00869e10_class
{
    void FUN_00869e30();
    void* FUN_00869e60(unsigned int flags);
};

// @fnv 0x00869e60
void* FUN_00869e10_class::FUN_00869e60(unsigned int flags)
{
    FUN_00869e30();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern float(__cdecl* DAT_011f91f0)(int);
// @fnv 0x0086bff0
void FUN_0086bff0(float(__cdecl* fn)(int))
{
    DAT_011f91f0 = fn;
}

extern bool DAT_011f94a7;

// @fnv 0x0086c000
void FUN_0086c000(bool abUseCache)
{
    DAT_011f94a7 = abUseCache;
}

struct GlobalObject_0044f440
{
    void FUN_00450410();
};
extern GlobalObject_0044f440 g_011c72a0;
// @fnv 0x0086c0c0
void FUN_0086c0c0()
{
    g_011c72a0.FUN_00450410();
}

namespace fnv_0086c0d0 {
struct GlobalObject_0044f440
{
    void FUN_00450410();
};
extern GlobalObject_0044f440 g_011c774c;

// @fnv 0x0086c0d0
void __cdecl FUN_0086c0d0()
{
    g_011c774c.FUN_00450410();
}
}  // namespace fnv_0086c0d0

namespace fnv_0086c0e0 {
struct GlobalObject_0044f440
{
    void FUN_00450410();
};
extern GlobalObject_0044f440 g_011c7314;

// @fnv 0x0086c0e0
void __cdecl FUN_0086c0e0()
{
    g_011c7314.FUN_00450410();
}
}  // namespace fnv_0086c0e0

namespace fnv_0086c0f0 {
struct GlobalObject_0044f440
{
    void FUN_00450410();
};
extern GlobalObject_0044f440 g_011c768c;
// @fnv 0x0086c0f0
void FUN_0086c0f0()
{
    g_011c768c.FUN_00450410();
}
}  // namespace fnv_0086c0f0

namespace fnv_0086c100 {
struct GlobalObject_0044f440
{
    void FUN_00450410();
};
extern GlobalObject_0044f440 g_011c7758;
// @fnv 0x0086c100
void FUN_0086c100()
{
    g_011c7758.FUN_00450410();
}
}  // namespace fnv_0086c100

namespace fnv_0086c110 {
struct GlobalObject_0044f440
{
    void FUN_00450410();
};
extern GlobalObject_0044f440 g_011c75bc;

// @fnv 0x0086c110
void __cdecl FUN_0086c110()
{
    g_011c75bc.FUN_00450410();
}
}  // namespace fnv_0086c110

namespace fnv_0086c120 {
struct GlobalObject_0044f440
{
    void FUN_00450410();
};
extern GlobalObject_0044f440 g_011c7458;

// @fnv 0x0086c120
void __cdecl FUN_0086c120()
{
    g_011c7458.FUN_00450410();
}
}  // namespace fnv_0086c120

namespace fnv_0086c130 {
struct GlobalObject_0044f440
{
    void FUN_00450410();
};
GlobalObject_0044f440 g_011c74a0;
// @fnv 0x0086c130
void FUN_0086c130()
{
    g_011c74a0.FUN_00450410();
}
}  // namespace fnv_0086c130

extern float DAT_011ff8ac;

// @fnv 0x0086c140
void FUN_0086c140(float value)
{
    DAT_011ff8ac = value;
}

extern float DAT_011ff8b0;
// @fnv 0x0086c150
void __cdecl FUN_0086c150(float value)
{
    DAT_011ff8b0 = value;
}

struct MessageHandler
{
    static MessageHandler* pHandler;
    virtual ~MessageHandler();
};
MessageHandler* MessageHandler::pHandler;

// Deletes the global MessageHandler instance if it exists and its byte at offset 4 is zero.
// @fnv 0x0086cd80
void __cdecl DestroyMessageHandler()
{
    if (MessageHandler::pHandler && !((unsigned char*)MessageHandler::pHandler)[4])
        delete MessageHandler::pHandler;
}

extern unsigned char DAT_011f9fc5;
// @fnv 0x00872df0
void FUN_00872df0(unsigned char value)
{
    DAT_011f9fc5 = value;
}

extern int DAT_01204368;
void __cdecl FUN_00877960();
// @fnv 0x00877950
int __cdecl FUN_00877950()
{
    FUN_00877960();
    return DAT_01204368;
}

extern "C" void __cdecl Deallocate(void*);
void __cdecl FUN_00877ac0();
struct FUN_00877d50_Class
{
    void __thiscall FUN_00877ac0();
    void* __thiscall FUN_00877d50(unsigned int flags);
};
// @fnv 0x00877d50
void* __thiscall FUN_00877d50_Class::FUN_00877d50(unsigned int flags)
{
    FUN_00877ac0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct StrArr
{
    void SetSize(unsigned int);
};
struct FUN_00877e10_Class
{
    void SetEntry(unsigned int, unsigned int);
    unsigned int FUN_00877e10(unsigned int a, unsigned int b);
};
// @fnv 0x00877e10
unsigned int FUN_00877e10_Class::FUN_00877e10(unsigned int a, unsigned int b)
{
    if (a >= reinterpret_cast<unsigned short*>(this)[4])
        reinterpret_cast<StrArr*>(this)->SetSize(reinterpret_cast<unsigned short*>(this)[7] + a);
    SetEntry(a, b);
    return a;
}

struct GlobalObject_00877f10
{
    ~GlobalObject_00877f10();
    void* FUN_00877f90(unsigned int flags);
};

// Runs the destructor, then frees this object with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00877f90
void* GlobalObject_00877f10::FUN_00877f90(unsigned int flags)
{
    GlobalObject_00877f10::~GlobalObject_00877f10();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern int DAT_011a95fc;

// @fnv 0x008781e0
void FUN_008781e0(int value)
{
    DAT_011a95fc = value;
}

struct TESSound
{
    unsigned int Deallocate();
};
struct FUN_00878f20_shell
{
    int pad[4];
    Flt f;
    unsigned __thiscall DeallocateSound();
};
// If the stored float converts to a nonzero pointer, calls TESSound::Deallocate on it and returns the result; otherwise returns 0.
// @fnv 0x00878f20
unsigned __thiscall FUN_00878f20_shell::DeallocateSound()
{
    if (f.operator unsigned int())
        return reinterpret_cast<TESSound*>(f.operator unsigned int())->Deallocate();
    else
        return 0;
}

struct FUN_00879860_Class
{
    void __thiscall FUN_00879860(float a, float b, float c, float d);
};
// Stores the four float arguments into the object's fields at offsets 0x308, 0x30c, 0x310 and 0x314.
// @fnv 0x00879860
void __thiscall FUN_00879860_Class::FUN_00879860(float a, float b, float c, float d)
{
    *(float*)((char*)this + 0x308) = a;
    *(float*)((char*)this + 0x30c) = b;
    *(float*)((char*)this + 0x310) = c;
    *(float*)((char*)this + 0x314) = d;
}

struct FUN_008798a0_Class
{
    void __thiscall FUN_008798a0();
};

// Sets four floats at offsets 0x308-0x314 of this object to 0.0, 1.0, 1.0, 0.0.
// @fnv 0x008798a0
void __thiscall FUN_008798a0_Class::FUN_008798a0()
{
    *(float*)((char*)this + 0x308) = 0.0f;
    *(float*)((char*)this + 0x30c) = 1.0f;
    *(float*)((char*)this + 0x310) = 1.0f;
    *(float*)((char*)this + 0x314) = 0.0f;
}

struct FUN_0087a670_shell
{
    int* __thiscall FUN_0087a670(int a, int b);
};

// Stores a at offset 0, b at offset 4, sets offset 12 to 0 and offset 8 to the value at offset 0, then returns this.
// @fnv 0x0087a670
int* __thiscall FUN_0087a670_shell::FUN_0087a670(int aiFirst, int aiSecond)
{
    *(int*)this = aiFirst;
    *(int*)((char*)this + 4) = aiSecond;
    *(int*)((char*)this + 12) = 0;
    *(int*)((char*)this + 8) = *(int*)this;
    return (int*)this;
}

struct GlobalObject_0087d420
{
    ~GlobalObject_0087d420();
    GlobalObject_0087d420* __thiscall FUN_0087d450(unsigned int flags);
};
// Runs the destructor, frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0087d450
GlobalObject_0087d420* __thiscall GlobalObject_0087d420::FUN_0087d450(unsigned int flags)
{
    GlobalObject_0087d420::~GlobalObject_0087d420();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* p);
struct BGSSaveLoadManager
{
    unsigned char FUN_00424940();
};
extern BGSSaveLoadManager* DAT_011de134;
void* __cdecl __memcpy(void* dest, const void* src, unsigned int count);
struct FUN_008660b0_shell
{
    int vtbl;
    int* data;
    unsigned int size;
    void GrowBuffer();
};
// @fnv 0x008660b0
void FUN_008660b0_shell::GrowBuffer()
{
    int* old = data;
    unsigned int oldSize = size;
    size += 0x10000;
    if (!DAT_011de134->FUN_00424940())
    {
        int* alloc3 = (int*)operator new(size);
        data = alloc3;
        if (old)
        {
            __memcpy(data, old, oldSize);
        }
        int* tmp = old;
        operator delete(tmp);
    }
}

int __cdecl AllocateUIntArray(unsigned int);

struct FUN_00869aa0
{
    void* vtbl;
    int data;
    unsigned short w0;
    unsigned short w1;
    unsigned short w2;
    unsigned short w3;
    unsigned short w4;
    FUN_00869aa0(unsigned short a, unsigned short b);
};

// @fnv 0x00869aa0
FUN_00869aa0::FUN_00869aa0(unsigned short a, unsigned short b)
{
    vtbl = &DAT_010827f0;
    w0 = a;
    w3 = b;
    w1 = 0;
    w2 = 0;
    if (w0 > 0)
        data = AllocateUIntArray(w0);
    else
        data = 0;
}

int __cdecl AllocateUIntArray(unsigned short a);
struct FUN_00869bf0
{
    int* vtbl;
    int data;
    unsigned short f8;
    unsigned short fa;
    unsigned short fc;
    unsigned short fe;
    FUN_00869bf0(unsigned short a, unsigned short b);
};
// @fnv 0x00869bf0
FUN_00869bf0::FUN_00869bf0(unsigned short a, unsigned short b)
{
    vtbl = &DAT_01082800;
    f8 = a;
    fe = b;
    fa = 0;
    fc = 0;
    if (f8 > 0)
        data = AllocateUIntArray(f8);
    else
        data = 0;
}

namespace fnv_00869d40 {
void* __cdecl AllocateUIntArray(unsigned int aiA);

struct FUN_00869d40
{
    void* vtbl;
    void* data;
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned short d;
    FUN_00869d40(unsigned int aiA, unsigned int aiB);
};
// @fnv 0x00869d40
FUN_00869d40::FUN_00869d40(unsigned int aiA, unsigned int aiB)
{
    vtbl = &DAT_01082810;
    a = aiA;
    d = aiB;
    b = 0;
    c = 0;
    if (a > 0)
        data = AllocateUIntArray(a);
    else
        data = 0;
}
}  // namespace fnv_00869d40

struct ActorCombatGroup
{
    int pad;
};
struct NiTMallocInterface_0096afc0
{
    static ActorCombatGroup** __cdecl Allocate(unsigned int);
};
extern int DAT_01081fc8;
struct FUN_00864160
{
    void* m_vtbl;
    ActorCombatGroup** m_pData;
    unsigned int m_uiCount;
    int m_uiPad;
    int m_uiAlloc;
    int m_iExtra;
    FUN_00864160(unsigned int ItemUpdateArray, int iExtra);
};
// Sets the vtable, stores the count and extra value, zeroes the pad and alloc fields, and allocates the data array when the count is positive.
// @fnv 0x00864160
FUN_00864160::FUN_00864160(unsigned int ItemUpdateArray, int iExtra)
{
    m_vtbl = (void*)&DAT_01081fc8;
    m_uiCount = ItemUpdateArray;
    m_iExtra = iExtra;
    m_uiPad = 0;
    m_uiAlloc = 0;
    if (m_uiCount > 0)
        m_pData = NiTMallocInterface_0096afc0::Allocate(m_uiCount);
    else
        m_pData = 0;
}

struct TESGlobal
{
    float GetValue();
    void SetValue(float);
};
struct TESForm;
TESForm* __cdecl _ref_004839c0(int id);
struct FUN_00867890_shell
{
    TESForm* f0;
    TESForm* f1;
    TESForm* f2;
    TESForm* f3;
    TESForm* f4;
    TESForm* f5;
    int f6;
    void FUN_00867890();
    void __fastcall FUN_00867a20();
};
// Looks up six forms by id, adds the f3 global's value divided by 24 to the f4 global, stores it, resets f6 and calls FUN_00867a20.
// @fnv 0x00867890
void FUN_00867890_shell::FUN_00867890()
{
    f0 = _ref_004839c0(0x35);
    f1 = _ref_004839c0(0x36);
    f2 = _ref_004839c0(0x37);
    f3 = _ref_004839c0(0x38);
    f4 = _ref_004839c0(0x39);
    f5 = _ref_004839c0(0x3a);
    float b = ((TESGlobal*)f3)->GetValue();
    float a = ((TESGlobal*)f4)->GetValue();
    a = b / 24.0 + a;
    ((TESGlobal*)f4)->SetValue(a);
    f6 = 0;
    FUN_00867a20();
}

struct GO
{
    unsigned int m_uiData;
    GO(unsigned int* p);
    ~GO();
    operator unsigned int() const;
};
struct Arr
{
    unsigned int GetSize();
    unsigned int* GetAt(int i);
};
// Iterates pArr, wraps each element in a GO, and passes it to pDest->FUN_008693f0 only when the GO converts to a non-zero value.
// @fnv 0x00869560
void FUN_00869560(Arr* pArr, FUN_008693f0_Class* pDest)
{
    for (unsigned int i = 0; i < pArr->GetSize(); i++)
    {
        GO sp(pArr->GetAt(i));
        if ((unsigned int)sp)
            pDest->FUN_008693f0((int)&sp);
    }
}

char** __cdecl FUN_005e0ba0(unsigned int);
struct FUN_00869e90_Class
{
    int* vtbl;
    char** p;
    unsigned short count;
    unsigned short pad;
    unsigned short w0;
    unsigned short w1;
    FUN_00869e90_Class(unsigned short, unsigned short);
};
// @fnv 0x00869e90
FUN_00869e90_Class::FUN_00869e90_Class(unsigned short ausCount, unsigned short b)
{
    vtbl = &DAT_01082820;
    count = ausCount;
    w1 = b;
    pad = 0;
    w0 = 0;
    if (count > 0)
        p = FUN_005e0ba0(count);
    else
        p = 0;
}

struct FUN_008779f0
{
    char data[0x114];
    FUN_008779f0();
};
extern int DAT_01204368;
// Allocates a FUN_008779f0 instance and stores it in DAT_01204368 if that global is currently null.
// @fnv 0x00877960
void FUN_00877960()
{
    if (!DAT_01204368)
        DAT_01204368 = (int)new FUN_008779f0;
}

extern int DAT_01082f04;
struct FUN_00877d80_Class
{
    void __thiscall Construct();
};
struct FUN_00877a80_Class : FUN_00877d80_Class
{
    int __thiscall InitWithValue(int a);
};
// Calls the base initializer, installs DAT_01082f04 as the vtable, stores a at offset 8, and sets offset 12 to 0 with offset 16 pointing to it.
// @fnv 0x00877a80
int FUN_00877a80_Class::InitWithValue(int aiValue)
{
    Construct();
    *(int*)this = (int)&DAT_01082f04;
    *(int*)((char*)this + 8) = aiValue;
    *(int*)((char*)this + 12) = 0;
    *(int*)((char*)this + 16) = (int)((char*)this + 12);
    return (int)this;
}

extern int DAT_01011d78;
struct FUN_00877e50_Class
{
    int m_pVTable;
    int* m_pData;
    unsigned short m_usPad;
    unsigned short m_usSize;
    unsigned short m_usElementCount;
    void __thiscall SetEntry(unsigned int index, int* value);
};
// @fnv 0x00877e50
void __thiscall FUN_00877e50_Class::SetEntry(unsigned int index, int* piValue)
{
    if (index >= m_usSize)
    {
        m_usSize = index + 1;
        if (*piValue != DAT_01011d78)
            m_usElementCount++;
    }
    else
    {
        if (*piValue != DAT_01011d78)
        {
            if (m_pData[index] == DAT_01011d78)
                m_usElementCount++;
        }
        else if (m_pData[index] != DAT_01011d78)
        {
            m_usElementCount--;
        }
    }
    m_pData[index] = *piValue;
}

struct TgtOps
{
    void* GetPosition();
};
struct FUN_005e0830
{
    bool Open(const char*, bool);
};
struct FUN_008798e0_shell : TgtOps
{
    bool OpenAtPosition();
};
// @fnv 0x008798e0
bool FUN_008798e0_shell::OpenAtPosition()
{
    bool result = false;
    void* position = GetPosition();
    if (position)
    {
        result = ((FUN_005e0830*)this)->Open((const char*)position, true);
        if (result)
        {
            result = ((bool(__thiscall*)(void*))(*(void***)this)[8])(this);
            ((void(__thiscall*)(void*))(*(void***)this)[7])(this);
        }
    }
    return result;
}

struct FUN_0087d340_Class
{
    virtual void vfn_00();
    virtual int vfn_04(unsigned int);
    void FUN_0087d3d0(int, unsigned int);
    void FUN_0087d340(unsigned int requested, unsigned int savedSize);
};

// @fnv 0x0087d340
void FUN_0087d340_Class::FUN_0087d340(unsigned int requested, unsigned int savedSize)
{
    *(int*)((char*)this + 4) = 0;
    *(int*)((char*)this + 8) = 0;
    *(int*)((char*)this + 12) = 0;
    if (savedSize > requested)
    {
        requested = savedSize;
    }
    if (requested > 0)
    {
        *(int*)((char*)this + 4) = vfn_04(requested);
        *(int*)((char*)this + 12) = requested;
    }
    if (savedSize > 0)
    {
        FUN_0087d3d0(*(int*)((char*)this + 4), savedSize);
        *(int*)((char*)this + 8) = savedSize;
    }
}

struct BSFadeNode
{
    unsigned int FUN_009ad610();
};

struct BSFadeNodeResult
{
    virtual bool vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
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
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual bool vfn_100();
};

struct BSFadeNodeResult2 : public BSFadeNodeResult
{
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual void vfn_1d0();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual void vfn_1e4();
    virtual void vfn_1e8();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual void vfn_1f4();
    virtual void vfn_1f8();
    virtual void vfn_1fc();
    virtual void vfn_200();
    virtual void vfn_204();
    virtual void vfn_208();
    virtual void vfn_20c();
    virtual void vfn_210();
    virtual void vfn_214();
    virtual void vfn_218();
    virtual void vfn_21c();
    virtual void vfn_220();
    virtual void vfn_224();
    virtual void vfn_228();
    virtual void vfn_22c();
    virtual void vfn_230();
    virtual void vfn_234();
    virtual void vfn_238();
    virtual void vfn_23c();
    virtual void vfn_240();
    virtual void vfn_244();
    virtual void vfn_248();
    virtual void vfn_24c();
    virtual void vfn_250();
    virtual void vfn_254();
    virtual void vfn_258();
    virtual void vfn_25c();
    virtual void vfn_260();
    virtual void vfn_264();
    virtual void vfn_268();
    virtual void vfn_26c();
    virtual void vfn_270();
    virtual void vfn_274();
    virtual void vfn_278();
    virtual void vfn_27c();
    virtual void vfn_280();
    virtual void vfn_284();
    virtual void vfn_288();
    virtual void vfn_28c();
    virtual void vfn_290();
    virtual void vfn_294();
    virtual void vfn_298();
    virtual void vfn_29c();
    virtual void vfn_2a0();
    virtual void vfn_2a4();
    virtual void vfn_2a8();
    virtual void vfn_2ac();
    virtual void vfn_2b0();
    virtual void vfn_2b4();
    virtual void vfn_2b8();
    virtual void vfn_2bc();
    virtual void vfn_2c0();
    virtual void vfn_2c4();
    virtual void vfn_2c8();
    virtual void vfn_2cc();
    virtual void vfn_2d0();
    virtual void vfn_2d4();
    virtual void vfn_2d8();
    virtual void vfn_2dc();
    virtual void vfn_2e0();
    virtual void vfn_2e4();
    virtual void vfn_2e8();
    virtual void vfn_2ec();
    virtual void vfn_2f0();
    virtual void vfn_2f4();
    virtual void vfn_2f8();
    virtual void vfn_2fc();
    virtual void vfn_300();
    virtual void vfn_304();
    virtual void vfn_308();
    virtual void vfn_30c();
    virtual void vfn_310();
    virtual void vfn_314();
    virtual void vfn_318();
    virtual void vfn_31c();
    virtual void vfn_320();
    virtual void vfn_324();
    virtual void vfn_328();
    virtual void vfn_32c();
    virtual void vfn_330();
    virtual void vfn_334();
    virtual void vfn_338();
    virtual void vfn_33c();
    virtual void vfn_340();
    virtual void vfn_344();
    virtual void vfn_348();
    virtual void vfn_34c();
    virtual void vfn_350();
    virtual void vfn_354();
    virtual void vfn_358();
    virtual void vfn_35c();
    virtual void vfn_360();
    virtual void vfn_364();
    virtual void vfn_368();
    virtual void vfn_36c();
    virtual void vfn_370();
    virtual void vfn_374();
    virtual void vfn_378();
    virtual void vfn_37c();
    virtual void vfn_380();
    virtual void vfn_384();
    virtual void vfn_388();
    virtual void vfn_38c();
    virtual void vfn_390();
    virtual void vfn_394();
    virtual void vfn_398();
    virtual void vfn_39c();
    virtual void vfn_3a0();
    virtual void vfn_3a4();
    virtual void vfn_3a8();
    virtual void vfn_3ac();
    virtual void vfn_3b0();
    virtual void vfn_3b4();
    virtual void vfn_3b8();
    virtual void vfn_3bc();
    virtual void vfn_3c0();
    virtual void vfn_3c4();
    virtual void vfn_3c8();
    virtual void vfn_3cc();
    virtual void vfn_3d0();
    virtual void vfn_3d4();
    virtual void vfn_3d8();
    virtual void vfn_3dc();
    virtual void vfn_3e0();
    virtual void vfn_3e4();
    virtual void vfn_3e8();
    virtual void vfn_3ec();
    virtual void vfn_3f0();
    virtual void vfn_3f4();
    virtual void vfn_3f8();
    virtual void vfn_3fc();
    virtual void vfn_400();
    virtual void vfn_404();
    virtual void vfn_408();
    virtual void vfn_40c();
    virtual void vfn_410();
    virtual void vfn_414();
    virtual void vfn_418();
    virtual void vfn_41c();
    virtual float vfn_420();
};

// @fnv 0x0086a050
float __cdecl FUN_0086a050(BSFadeNode* node)
{
    BSFadeNodeResult2* p = (BSFadeNodeResult2*)node->FUN_009ad610();
    if (p != 0 && p->vfn_100())
    {
        return p->vfn_420();
    }
    return 1.0f;
}

struct FUN_00863f30_shell
{
    void __thiscall FUN_008640e0();
    void* __thiscall FUN_00863f30(unsigned int flags);
};

// Calls FUN_008640e0, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x00863f30
void* __thiscall FUN_00863f30_shell::FUN_00863f30(unsigned int flags)
{
    FUN_008640e0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void __cdecl FUN_00864100_Deallocate(void** p);

// Sets the object's vtable pointer to DAT_01081fc8 and frees the buffer stored at offset 4 via FUN_00864100_Deallocate.
// @fnv 0x00864100
void __thiscall FUN_008640e0_class::DestroyAndFreeBuffer()
{
    *(int*)this = (int)&DAT_01081fc8;
    FUN_00864100_Deallocate(*(void***)((char*)this + 4));
}

void* __cdecl NiFree(void*);
extern int DAT_010822a8;
struct FUN_00865840_class : NiTPointerMap<int, int>
{
    void FUN_00865840();
};
// @fnv 0x00865840
void FUN_00865840_class::FUN_00865840()
{
    *(void**)this = (void*)&DAT_010822a8;
    RemoveAll();
    NiFree(*(void**)((char*)this + 8));
}

struct CF845
{
    int value;
    CF845(int);
};

struct FUN_006b8310_class
{
    void FreeMemory(void*);
};

struct FUN_00865890_Class
{
    char pad_0x00[0x0c];
    FUN_006b8310_class member_0x0c;

    void InitAndDispatch(int* param);
};

// Constructs a CF845 with value 0, stores its value into param[2], then calls member_0x0c.FreeMemory(param).
// @fnv 0x00865890
void FUN_00865890_Class::InitAndDispatch(int* piData)
{
    CF845 local(0);
    piData[2] = local.value;
    member_0x0c.FreeMemory(piData);
}

struct FUN_00865840_shell
{
    void FUN_00865840();
};
void Deallocate(void*);
struct FUN_008658d0 : FUN_00865840_shell
{
    void* DeleteThis(unsigned int flags);
};
// @fnv 0x008658d0
void* FUN_008658d0::DeleteThis(unsigned int flags)
{
    FUN_00865840();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern int DAT_01082324;
struct FUN_00865bd0
{
    void* m_vtbl;
    int a;
    int b;
    int c;
    int d;
    FUN_00865bd0();
};
// Sets the vtable pointer to DAT_01082324 and zeroes the four integer fields a, b, c and d.
// @fnv 0x00865bd0
FUN_00865bd0::FUN_00865bd0()
{
    m_vtbl = &DAT_01082324;
    a = 0;
    b = 0;
    c = 0;
    d = 0;
}

struct FUN_00865aa0_shell
{
    void SetFlags(unsigned int value);
};

struct FUN_00853670_shell
{
    void FUN_00853670(int value);
};

unsigned int __cdecl FUN_00845d40(unsigned int value);
unsigned int __cdecl FUN_00845d70(unsigned int value);
void __cdecl WriteTypedValue(void* destination, unsigned int source, unsigned int count);

struct FUN_008665d0_class
{
    void* m_pData;
    void __thiscall FUN_008665d0(void* source, unsigned int size, int value, unsigned char flag);
};

// Allocates a buffer sized from size, writes a flag and encoded size/value header, then copies size bytes from source into it.
// @fnv 0x008665d0
void FUN_008665d0_class::FUN_008665d0(void* source, unsigned int size, int value, unsigned char flag)
{
    unsigned int data4 = FUN_00845d40(size);
    unsigned int totalSize = FUN_00845d70(data4);
    unsigned int encodedSize = size + totalSize + 2;
    void* object = operator new(encodedSize);

    this->m_pData = object;

    char* headerSize = reinterpret_cast<char*>(this->m_pData);
    char* destination = headerSize;

    destination[1] = flag;

    reinterpret_cast<FUN_00865aa0_shell*>(destination)->SetFlags(data4);
    reinterpret_cast<FUN_00853670_shell*>(destination)->FUN_00853670(value);

    headerSize += 2;
    WriteTypedValue(headerSize, size, data4);
    headerSize += totalSize;

    __memcpy(headerSize, source, size);
}

struct FUN_00aa2230
{
    int m_uiFilterValue;
    FUN_00aa2230();
};

struct FUN_00aa21d0
{
    void* m_pValue1;
    void* m_pValue2;
    FUN_00aa21d0(FUN_00aa2230* value);
};

struct FUN_00866690_Class
{
    void InitializeGlobal();
};

extern void* DAT_011f6118;

void __cdecl _FUN_00aa2020();

namespace std {
struct StandardLibrarySingletonObject
{
    virtual void vfn_00() = 0;
    virtual void vfn_04(int, int, int) = 0;
};

template <class T> T& __cdecl _Immortalize();
}

// @fnv 0x00866690
void FUN_00866690_Class::InitializeGlobal()
{
    DAT_011f6118 = new FUN_00aa21d0(new FUN_00aa2230);

    _FUN_00aa2020();

    std::_Immortalize<std::StandardLibrarySingletonObject>().vfn_04(0, 0, 0);
}

__declspec(thread) bool g_tls_0298 = true;

// @fnv 0x00869190
void __cdecl SetTlsFlag(bool value)
{
    g_tls_0298 = value;
}

struct FUN_00869640_StrArr
{
    void Resize(int);
    void SetAt(unsigned int, char*&);
    unsigned int FUN_00869640(unsigned int index, char*& value);
};
// @fnv 0x00869640
unsigned int FUN_00869640_StrArr::FUN_00869640(unsigned int index, char*& value)
{
    if (index >= *(unsigned short*)((char*)this + 8))
        Resize(*(unsigned short*)((char*)this + 0xe) + index);
    SetAt(index, value);
    return index;
}

void __cdecl Deallocate(void*);
struct GlobalObject_008699c0
{
    virtual ~GlobalObject_008699c0();
};
struct FUN_008699f0_class : public GlobalObject_008699c0
{
    void* FUN_008699f0(unsigned int flags);
};
// Runs the base destructor, frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x008699f0
void* FUN_008699f0_class::FUN_008699f0(unsigned int flags)
{
    this->GlobalObject_008699c0::~GlobalObject_008699c0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_00869bc0_Class : FUN_00869b90_cls
{
    void* FUN_00869bc0(unsigned int flags);
};

// @fnv 0x00869bc0
void* FUN_00869bc0_Class::FUN_00869bc0(unsigned int flags)
{
    InitializeAndReleaseNext();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct GlobalObject_00869db0
{
    void __thiscall FUN_00869e10();
    ~GlobalObject_00869db0();
    void* __thiscall FUN_00869de0(unsigned int flags);
};
// Calls FUN_00869e10, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00869de0
void* __thiscall GlobalObject_00869db0::FUN_00869de0(unsigned int flags)
{
    FUN_00869e10();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void __cdecl ShutdownInput();
struct FUN_0086c850_shell
{
    void ShutdownInput();
    void* FUN_0086c850(unsigned int flags);
};
// Calls ShutdownInput, then frees this via Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x0086c850
void* FUN_0086c850_shell::FUN_0086c850(unsigned int flags)
{
    ShutdownInput();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct BSAudio;
struct RegionPointList;
struct SoundPlaybackManager;
struct TESRecipe;
struct BGSMessage;
struct BGSMenuIcon;
struct BGSCameraPath;
struct TES;
struct TESSound;

typedef void(__cdecl* AudioCallback)();

void __cdecl FUN_00aea020();
void __cdecl GetSoundPathAndFlags();
void __cdecl FindDialogueFile();
void __cdecl ApplySoundFormToGameSound();
void __cdecl FUN_00832c40();
void __cdecl FUN_0082f830();
bool __cdecl FUN_0082d740(TESSound*, int*, int*);

struct BSAudio
{
    virtual void vfn_00();
    virtual void vfn_04(unsigned int value);
    virtual void vfn_08();
    virtual void vfn_0c(AudioCallback callback);

    static BSAudio* __cdecl GetSingleton();
};

struct RegionPointList
{
    void __thiscall SetDistanceInsideAtMax(unsigned int value);
};

struct SoundPlaybackManager
{
    static bool __cdecl ResolveSoundFile(char const*, char*, unsigned int*, void**);
};

struct TESRecipe
{
    void __thiscall SetSkill(int value);
    void __thiscall SetSkillLevel(int value);
};

struct BGSMessage
{
    void __thiscall SetIcon(BGSMenuIcon* value);
};

struct BGSCameraPath
{
    void __thiscall AssignParentPath(BGSCameraPath* value);
};

struct TES
{
    void __thiscall SetDawnSound(TESSound* value);
};

struct FalloutRadio
{
    static void __cdecl RadioSynchUnPaused();
};

struct FUN_0086ce40_class
{
    int vfn_00;
    int padding_04;
    unsigned int value_08;

    void __thiscall InitAudioCallbacks();
};

// Registers audio callbacks and a value on the BSAudio singleton, then calls FUN_0082f830.
// @fnv 0x0086ce40
void FUN_0086ce40_class::InitAudioCallbacks()
{
    FUN_00aea020();

    reinterpret_cast<RegionPointList*>(BSAudio::GetSingleton())
        ->SetDistanceInsideAtMax(reinterpret_cast<unsigned int>(&GetSoundPathAndFlags));

    reinterpret_cast<TESRecipe*>(BSAudio::GetSingleton())
        ->SetSkill(reinterpret_cast<int>(&SoundPlaybackManager::ResolveSoundFile));

    reinterpret_cast<TESRecipe*>(BSAudio::GetSingleton())->SetSkillLevel(reinterpret_cast<int>(&FindDialogueFile));

    reinterpret_cast<BGSMessage*>(BSAudio::GetSingleton())
        ->SetIcon(reinterpret_cast<BGSMenuIcon*>(&ApplySoundFormToGameSound));

    reinterpret_cast<BGSCameraPath*>(BSAudio::GetSingleton())
        ->AssignParentPath(reinterpret_cast<BGSCameraPath*>(&FUN_00832c40));

    reinterpret_cast<TES*>(BSAudio::GetSingleton())
        ->SetDawnSound(reinterpret_cast<TESSound*>(&FalloutRadio::RadioSynchUnPaused));

    BSAudio::GetSingleton()->vfn_0c(reinterpret_cast<AudioCallback>(&FUN_0082d740));

    BSAudio::GetSingleton()->vfn_04(value_08);

    FUN_0082f830();
}

struct NiVisibleArray;
struct FUN_00a69400
{
    FUN_00a69400(NiVisibleArray*);
};
extern void* DAT_01082ccc;
struct FUN_00872ea0 : FUN_00a69400
{
    void* m_vft;
    FUN_00872ea0(NiVisibleArray*);
};
// Constructs the object by forwarding the NiVisibleArray pointer to the base constructor and setting the vtable pointer to DAT_01082ccc.
// @fnv 0x00872ea0
FUN_00872ea0::FUN_00872ea0(NiVisibleArray* apVisibleArray) : FUN_00a69400(apVisibleArray)
{
    m_vft = &DAT_01082ccc;
}

extern int DAT_01082ed8;
struct FUN_0044f600_class
{
    void FUN_0044f700();
};
struct FUN_008779f0_class : FUN_0044f600_class
{
    FUN_008779f0_class();
};
// @fnv 0x008779f0
FUN_008779f0_class::FUN_008779f0_class()
{
    FUN_0044f700();
    *reinterpret_cast<void**>(this) = &DAT_01082ed8;
}

struct FUN_00877b40_Delete : FUN_00877b40
{
    void* FUN_00877b80(unsigned int flags);
};
// Calls Init, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00877b80
void* FUN_00877b40_Delete::FUN_00877b80(unsigned int flags)
{
    Init();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void __cdecl Deallocate(void*);
struct FUN_00877bb0 : FUN_00877b40
{
    void __thiscall SetVtable();
    void* DeleteThis(unsigned int flags);
};
// Calls SetVtable, frees this via Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00877bb0
void* FUN_00877bb0::DeleteThis(unsigned int flags)
{
    SetVtable();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern char const* const g_011c5bbc_arg1;
struct FUN_00878360_Class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    unsigned int m_10;
    bool FUN_00878360();
};
// Returns true unless m_10 exceeds m_08 and the difference is greater than the address of g_011c5bbc_arg1.
// @fnv 0x00878360
bool FUN_00878360_Class::FUN_00878360()
{
    bool b = true;
    if (m_10 > m_08 && (char const* const)(m_10 - m_08) > (char const* const)&g_011c5bbc_arg1)
        b = false;
    return b;
}

unsigned int __cdecl gm_GetCurrentThreadId(void);

struct PackedTaskQueueProcessor
{
    void Process();
};

struct FUN_0087a790_class
{
    PackedTaskQueueProcessor* m_pPrimaryTaskProcessor;
    PackedTaskQueueProcessor* m_pSecondaryTaskProcessor;
    PackedTaskQueueProcessor* m_pTaskQueueProcessor;
    unsigned int m_uiTaskFlags;

    void __thiscall FUN_0087a790();
};

// @fnv 0x0087a790
void FUN_0087a790_class::FUN_0087a790()
{
    m_pTaskQueueProcessor = m_pSecondaryTaskProcessor;
    m_uiTaskFlags = gm_GetCurrentThreadId();
    m_pPrimaryTaskProcessor->Process();
    m_uiTaskFlags = 0;
}

struct BSScrapArray_NiPointer_NiAVObject_1024
{
    ~BSScrapArray_NiPointer_NiAVObject_1024();
    void* FUN_0087d290(unsigned int flags);
};
// Runs the destructor and, when bit 0 of flags is set, deallocates this object; returns this.
// @fnv 0x0087d290
void* BSScrapArray_NiPointer_NiAVObject_1024::FUN_0087d290(unsigned int flags)
{
    this->BSScrapArray_NiPointer_NiAVObject_1024::~BSScrapArray_NiPointer_NiAVObject_1024();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct GlobalObject_0087d2c0
{
    void* vtable;
    ~GlobalObject_0087d2c0();
    GlobalObject_0087d2c0* FUN_0087d2f0(unsigned int flags);
};
// Runs the destructor and, when bit 0 of flags is set, deallocates this, returning the pointer.
// @fnv 0x0087d2f0
GlobalObject_0087d2c0* GlobalObject_0087d2c0::FUN_0087d2f0(unsigned int flags)
{
    this->GlobalObject_0087d2c0::~GlobalObject_0087d2c0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern void* __cdecl operator new(unsigned int, void*);

struct FUN_0087d3d0_Class
{
    void FUN_0087d3d0(int a, unsigned int count);
};

// Calls operator new(8, ...) for each of count elements at successive 8-byte offsets from a.
// @fnv 0x0087d3d0
void FUN_0087d3d0_Class::FUN_0087d3d0(int aiBase, unsigned int count)
{
    unsigned int i;
    void* p2;
    for (i = 0; i < count; ++i)
    {
        p2 = operator new(8, (void*)(aiBase + i * 8));
    }
}

struct ScriptLocalsX
{
    unsigned int __thiscall GetLocalData();
};
struct FUN_0087ea80_shell
{
    void FUN_0087ea80(unsigned int a);
};
// @fnv 0x0087ea80
void FUN_0087ea80_shell::FUN_0087ea80(unsigned int a)
{
    *(unsigned int*)((char*)this + 0x90) = ((ScriptLocalsX*)a)->GetLocalData();
}

struct Actor_0087f4a0
{
    void* GetActorBase();
    bool FUN_0087f4a0();
};
struct FlagHelper
{
    bool GetFlag8();
};
// @fnv 0x0087f4a0
bool Actor_0087f4a0::FUN_0087f4a0()
{
    return reinterpret_cast<FlagHelper*>(reinterpret_cast<char*>(GetActorBase()) + 0x30)->GetFlag8();
}

class MapDtorWrap_b9629 : public NiTPointerMap<int, int>
{
  public:
    virtual void unk00();
    ~MapDtorWrap_b9629();
};

class FUN_008657e0_cls : public MapDtorWrap_b9629
{
  public:
    virtual ~FUN_008657e0_cls();
};

// Destructor that clears all entries from the underlying NiTPointerMap before destruction.
// @fnv 0x008657e0
FUN_008657e0_cls::~FUN_008657e0_cls()
{
    reinterpret_cast<NiTPointerMap<int, int>*>(this)->RemoveAll();
}

void __cdecl Emit4(int a, int b, int c, int d);

struct FUN_00866140_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    void Step();
    void FUN_00866140(int a1, int a2);
};

// Adds a2 to m_0c, calls Step while the total exceeds m_08, then emits four values unless DAT_011de134->FUN_00424940() is true, and stores the new total.
// @fnv 0x00866140
void FUN_00866140_cls::FUN_00866140(int aiOffset, int aiAmount)
{
    int iNewTotal = m_0c + aiAmount;
    if (iNewTotal <= 0)
    {
        return;
    }
    while (iNewTotal > m_08)
    {
        Step();
    }
    if (!DAT_011de134->FUN_00424940())
    {
        int lo_ = m_04 + aiOffset;
        int hi = m_04 + aiOffset + aiAmount;
        int rem3 = m_08 - (aiOffset + aiAmount);
        Emit4(hi, rem3, lo_, m_0c - aiOffset);
    }
    m_0c = iNewTotal;
}

struct FUN_00866570_Input
{
    unsigned char FUN_008a81c0();
    int FUN_008665b0();
    unsigned int FUN_0084e3a0();
    void* FUN_00726070();
};
struct FUN_00866570_Class : public FUN_008665d0_class
{
    void InitFromInput(FUN_00866570_Input* input);
};
// Calls the base initializer with four values obtained from the input object.
// @fnv 0x00866570
void FUN_00866570_Class::InitFromInput(FUN_00866570_Input* input)
{
    FUN_008665d0(input->FUN_00726070(), input->FUN_0084e3a0(), input->FUN_008665b0(), input->FUN_008a81c0());
}

// Stand-in for the object stored in the array held by FUN_00866de0_cls::m_pArr.
struct FUN_004424c0_Element
{
    void FUN_004424c0();
};

// Class owning the array at +0x50; CallElementAt forwards an indexed element
// to its own member routine.
struct FUN_00866de0_cls
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
    FUN_004424c0_Element** m_pArr;
    void CallElementAt(int idx);
};

// @fnv 0x00866de0
void FUN_00866de0_cls::CallElementAt(int aiIndex)
{
    m_pArr[aiIndex]->FUN_004424c0();
}

struct ScopeGuardCtx
{
    int m_unk00;
    ScopeGuardCtx(unsigned int size, int flag, const char* file, int line);
    ~ScopeGuardCtx();
};

struct FUN_00866ff0_cls
{
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_unk0C;
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_unk1C;
    int m_unk20;
    int m_unk24;
    int m_unk28;
    int m_unk2C;
    int m_unk30;
    int m_unk34;
    int m_unk38;
    int m_unk3C;
    int m_unk40;
    int m_unk44;
    int m_unk48;
    int m_unk4C;
    int m_unk50;
    FUN_00866ff0_cls();
};

void* operator new(unsigned int size) throw();

ScopeGuardCtx::~ScopeGuardCtx()
{}

// @fnv 0x00866ff0
void __cdecl FUN_00866ff0()
{
    ScopeGuardCtx ctx(0x14, 1, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Misc\\BGSMoviePlayer.cpp", 0x1c);
    DAT_0126fac4 = new FUN_00866ff0_cls();
}

extern float DAT_01012054;

struct S_00867510_Class
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    float unk10;
    float unk14;
    float unk18;
    float unk1c;
    float unk20;
    float unk24;
    float unk28;
    float unk2c;
    int unk30;
    int unk34;
    float unk38;
    float unk3c;
    bool unk40;
    int unk44;

    S_00867510_Class* __thiscall FUN_00867510();
};

// Initializes the object's fields: sets most floats to DAT_01012054, unk30/unk34 to -1, unk40 to false, unk38/unk3c to 0.0f, unk44 to 0, and returns this.
// @fnv 0x00867510
S_00867510_Class* __thiscall S_00867510_Class::FUN_00867510()
{
    unk00 = DAT_01012054;
    unk04 = DAT_01012054;
    unk08 = DAT_01012054;
    unk0c = DAT_01012054;
    unk10 = DAT_01012054;
    unk14 = DAT_01012054;
    unk1c = DAT_01012054;
    unk20 = DAT_01012054;
    unk24 = DAT_01012054;
    unk28 = DAT_01012054;
    unk2c = DAT_01012054;

    unk30 = -1;
    unk34 = -1;
    unk40 = false;
    unk38 = 0.0f;
    unk3c = 0.0f;
    unk44 = 0;

    return this;
}

struct FUN_008676d0_Class
{
    virtual float vfn_00();
    virtual float vfn_04();
    virtual float vfn_08();
    virtual float vfn_0c();
    virtual float vfn_10();
    virtual float vfn_14();
    virtual float vfn_18();
    virtual float vfn_1c();
    virtual float vfn_20();
    virtual float vfn_24();
    virtual float vfn_28();
    virtual float vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual float vfn_38();
    virtual float vfn_3c();
    virtual void vfn_40();

    void __thiscall FUN_008676d0();
};

// Calls the object's virtual functions vfn_00 through vfn_40 in order, skipping vfn_18.
// @fnv 0x008676d0
void __thiscall FUN_008676d0_Class::FUN_008676d0()
{
    vfn_00();
    vfn_04();
    vfn_08();
    vfn_0c();
    vfn_10();
    vfn_14();
    vfn_1c();
    vfn_20();
    vfn_24();
    vfn_28();
    vfn_2c();
    vfn_30();
    vfn_34();
    vfn_38();
    vfn_3c();
    vfn_40();
}

class FUN_008691d0_cls
{
  public:
    void** m_ppVirtualMethodTable;
    TESObjectREFR** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    TESObjectREFR* RemoveAt(unsigned int index);
};

// Removes the element at index by swapping in the last element, clearing the slot, and decrementing the size and element count if non-null.
// @fnv 0x008691d0
TESObjectREFR* FUN_008691d0_cls::RemoveAt(unsigned int index)
{
    if (index >= m_usSize)
    {
        return 0;
    }
    m_usSize--;
    TESObjectREFR* removed = m_pBase[index];
    m_pBase[index] = m_pBase[m_usSize];
    m_pBase[m_usSize] = 0;
    if (removed != 0)
    {
        m_usESize--;
    }
    return removed;
}

struct C869680Item;

class C869680Array
{
  public:
    virtual ~C869680Array();

    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, C869680Item* const& pkElement);
    unsigned int FUN_00869680(unsigned int uiIndex, C869680Item* const& pkElement);

    C869680Item** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

// SetAtGrow
// @fnv 0x00869680
unsigned int C869680Array::FUN_00869680(unsigned int uiIndex, C869680Item* const& pkElement)
{
    if (uiIndex >= m_usMaxSize)
        SetSize(uiIndex + m_usGrowBy);
    SetAt(uiIndex, pkElement);
    return uiIndex;
}

struct FNV_869F30_Renderer : NiRenderer
{
    void __thiscall FUN_00483710();
};

struct FNV_869F30_Manager
{
    void __thiscall FUN_00c3e310();
    void __thiscall FUN_00877d30();
    void __thiscall FUN_00c3e340();
};
extern FNV_869F30_Manager* DAT_01202d98;

struct FNV_869F30_World
{
    void __thiscall CallMemberFunction();
};
extern FNV_869F30_World* DAT_011c3b3c;

struct FNV_869F30_Service
{
    virtual void method0();
    virtual void method1();
    virtual void method2();
    void __thiscall FUN_00b01130();
};
FNV_869F30_Service* __cdecl FUN_00aff100();
FNV_869F30_Service* __cdecl FUN_00453a70();
FNV_869F30_Service* __cdecl FUN_00b00a00();
void __cdecl FUN_008304a0();
void __cdecl FUN_0082f9c0();
void __cdecl UpdateSystemUtility();
void __cdecl ResetSystemUtility();

// Switches on mode; for mode 2 it runs a fixed sequence of renderer, manager, world and service calls, with the manager call repeated at the end.
// @fnv 0x00869f30
void __cdecl RunModeSwitch(int mode)
{
    switch (mode)
    {
    default:
        break;
    case 0:
        break;
    case 1:
        break;
    case 2:
        if (FUN_0043c4b0())
        {
            static_cast<FNV_869F30_Renderer*>(FUN_0043c4b0())->FUN_00483710();
        }
        FUN_00867090();
        if (DAT_01202d98)
        {
            DAT_01202d98->FUN_00c3e310();
        }
        DAT_011c3b3c->CallMemberFunction();
        DAT_01202d98->FUN_00877d30();
        DAT_01202d98->FUN_00c3e340();
        FUN_00aff100()->FUN_00b01130();
        FUN_00aff100()->method2();
        FUN_008304a0();
        FUN_0082f9c0();
        FUN_00453a70()->method2();
        UpdateSystemUtility();
        ResetSystemUtility();
        FUN_00b00a00()->method2();
        if (DAT_01202d98)
        {
            DAT_01202d98->FUN_00c3e310();
        }
        break;
    }
}

struct FUN_0086a480_holder
{
    float FUN_0084d030();
    unsigned int FUN_00825c00();
};

struct FUN_0086a480_other
{
    double FUN_00867da0();
};

extern FUN_0086a480_holder DAT_011f6394;
extern FUN_0086a480_other DAT_011de7b8;
extern double DAT_01017b70;
extern double DAT_01012638;

bool FUN_00702360();

// @fnv 0x0086a480
float FUN_0086a480(int aiMode)
{
    if (aiMode == 3)
    {
        return DAT_011f6394.FUN_0084d030();
    }
    if (aiMode == 2)
    {
        if (!FUN_00702360())
        {
            struct Pair64
            {
                unsigned int lo;
                unsigned int hi;
            } value;
            value.lo = DAT_011f6394.FUN_00825c00();
            value.hi = 0;
            float r1 = (double)*(__int64*)&value / DAT_01017b70;
            return r1;
        }
        else
        {
            return 0.0f;
        }
    }
    if (aiMode == 1)
    {
        if (!FUN_00702360())
        {
            return DAT_011f6394.FUN_0084d030();
        }
        else
        {
            return 0.0f;
        }
    }
    else if (aiMode == 0)
    {
        float r2 = DAT_011de7b8.FUN_00867da0() * DAT_01012638 * DAT_01012638;
        return r2;
    }
    return 0.0f;
}

extern int DAT_011f638c;
// @fnv 0x0086a820
int __cdecl FUN_0086a820()
{
    return DAT_011f638c;
}

extern unsigned char g_011f941e;
extern float g_011adbcc;
extern float g_011adbd0;

struct SettingsRef_011cf8a4
{
    float* GetValuePtr();
};
extern SettingsRef_011cf8a4 g_011cf8a4;

struct ChainLeaf_005b9f80
{
    void Run();
};
struct ChainNode_004ebbc0
{
    ChainLeaf_005b9f80* Next();
};

float Sample_0086c0c0();
float Sample_0086c0d0();
float Sample_0086c0e0();
float Sample_0086c0f0();
float Sample_0086c100();
float Sample_0086c110();
float Sample_0086c120();
float Sample_0086c130();
void FUN_0086c140(float value);
void __cdecl FUN_0086c150(float value);
ChainNode_004ebbc0* __stdcall Factory_004e3270(int kind, float value);

// @fnv 0x0086c010
void FUN_0086c010()
{
    float value;
    if (g_011f941e != 0)
    {
        g_011adbcc = Sample_0086c120();
        g_011adbd0 = Sample_0086c130();
        FUN_0086c140(Sample_0086c100());
        FUN_0086c150(Sample_0086c110());
    }
    else
    {
        FUN_0086c140(Sample_0086c0c0());
        FUN_0086c150(Sample_0086c0d0());
        g_011adbcc = Sample_0086c0e0();
        g_011adbd0 = Sample_0086c0f0();
    }
    value = *g_011cf8a4.GetValuePtr();
    Factory_004e3270(12, value)->Next()->Run();
}

class B86C620Base
{
  public:
    B86C620Base(void* pvOwner);
    ~B86C620Base();

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

class B86C620Timer
{
  public:
    B86C620Timer(int iStart, int m_iPayloadInteger);

    int m_iStart;
    int m_iDuration;
    int m_iElapsed;
};

class FUN_0086c620_cls : public B86C620Base
{
  public:
    FUN_0086c620_cls(void* pvOwner, void* pvTarget);

    B86C620Timer m_kTimer;
    void* m_pvTarget;
    bool m_bDone;
};

// Constructs the object with the given owner and target, initializing the timer to start 0 with duration 100 and marking it not done.
// @fnv 0x0086c620
FUN_0086c620_cls::FUN_0086c620_cls(void* pvOwner, void* pvTarget)
    : B86C620Base(pvOwner), m_kTimer(0, 100), m_pvTarget(pvTarget), m_bDone(false)
{}

// Thiscall, 98 bytes /MT /Od /GS /EHsc: body call on this (state 1), member sub-object
// at +0x14 released (state 0), then base sub-object dtor on this (state -1).
class FUN_0086c6e0_base
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    ~FUN_0086c6e0_base();
};

class FUN_0086c6e0_child
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    ~FUN_0086c6e0_child();
};

class FUN_0086c6e0_cls : public FUN_0086c6e0_base
{
  public:
    FUN_0086c6e0_child m_14;
    void Tidy();
    ~FUN_0086c6e0_cls();
};

// @fnv 0x0086c6e0
FUN_0086c6e0_cls::~FUN_0086c6e0_cls()
{
    Tidy();
}

// Fade node helper: repeatedly asks the node to process a scratch buffer
// until it reports that it is done.
struct FadeNodeLocal_cls
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual bool vfn_10(char* pBuf);
    void FUN_0086c750();
};

// Repeatedly calls vfn_10 with a 32-byte scratch buffer until it returns false.
// @fnv 0x0086c750
void FadeNodeLocal_cls::FUN_0086c750()
{
    char buffer[0x20];
    while (this->vfn_10(buffer))
    {
    }
}

struct FUN_0086c850_cls
{
    int unk00;
    int FUN_0086c850(int flag);
};

struct FUN_0086cdf0_cls
{
    int unk00;
    FUN_0086c850_cls* m_04;
};

extern FUN_0086cdf0_cls* DAT_011f35cc;

// @fnv 0x0086cdf0
void FUN_0086cdf0()
{
    if (DAT_011f35cc != 0)
    {
        FUN_0086cdf0_cls* tmp = DAT_011f35cc;
        FUN_0086cdf0_cls* obj2 = tmp;
        int result;
        if (obj2 != 0)
        {
            result = reinterpret_cast<FUN_0086c850_cls*>(obj2)->FUN_0086c850(1);
        }
        else
        {
            result = 0;
        }
    }
    DAT_011f35cc = 0;
}

extern bool DAT_011a9604;
struct FUN_00876a20_out
{
    void FUN_00b65ec0();
};
struct FUN_00876a20_list
{
    FUN_00876a20_out* FUN_00559450();
};
struct FUN_00876a20_arg
{
    void SetFromCamera(int);
};
extern int __cdecl FUN_00874690();
struct FUN_00876a20_shell
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
    FUN_00876a20_list unk94;
    void FUN_00876a20(FUN_00876a20_arg* apArg);
};

// Clears DAT_011a9604, passes FUN_00874690() to apArg, calls FUN_00b65ec0 on unk94's element, then restores the flag.
// @fnv 0x00876a20
void FUN_00876a20_shell::FUN_00876a20(FUN_00876a20_arg* apArg)
{
    bool bOld = DAT_011a9604;
    DAT_011a9604 = false;
    apArg->SetFromCamera(FUN_00874690());
    unk94.FUN_00559450()->FUN_00b65ec0();
    DAT_011a9604 = bOld;
}

class FUN_00877ac0_iter
{
  public:
    char m_bytes[0x20];
};

class FUN_00877ac0_base
{
  public:
    virtual ~FUN_00877ac0_base();
};

class FUN_00877ac0_cls : public FUN_00877ac0_base
{
  public:
    virtual ~FUN_00877ac0_cls();
    bool FUN_00877ac0_step(FUN_00877ac0_iter& it);
};

// Destructor that repeatedly calls FUN_00877ac0_step with a local iterator until it returns false.
// @fnv 0x00877ac0
FUN_00877ac0_cls::~FUN_00877ac0_cls()
{
    FUN_00877ac0_iter it;
    while (FUN_00877ac0_step(it))
    {
    }
}

struct B877BE0Item
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

struct B877BE0Node
{
    static void* operator new(unsigned int uiSize, void* pvWhere);
    static void operator delete(void* pvMem, void* pvWhere);

    B877BE0Node();

    B877BE0Node* m_pkNext;
    B877BE0Item m_kItem;
};

class B877BE0Pool
{
  public:
    void* Allocate(unsigned int uiSize, unsigned int uiAlignment);
};

extern unsigned int g_uiB877BE0Alignment;

class B877BE0Queue
{
  public:
    int unk00;
    int unk04;
    B877BE0Pool* m_pkPool;
    B877BE0Node* m_pkHead;
    B877BE0Node** m_ppkTail;

    bool Push(const B877BE0Item& kItem);
};

// Allocates and constructs a node, copies kItem into it, appends the node to the tail of the queue, and returns true.
// @fnv 0x00877be0
bool B877BE0Queue::Push(const B877BE0Item& kItem)
{
    B877BE0Node* pkNode = (B877BE0Node*)m_pkPool->Allocate(sizeof(B877BE0Node), g_uiB877BE0Alignment);
    new (pkNode) B877BE0Node;
    pkNode->m_kItem = kItem;
    if (!m_pkHead)
        m_ppkTail = &m_pkHead;
    *m_ppkTail = pkNode;
    pkNode->m_pkNext = 0;
    m_ppkTail = &pkNode->m_pkNext;
    return true;
}

struct Node877
{
    Node877* next;
    int data[8];
    void __thiscall FUN_007b3fa0(int flags);
};

struct Holder877
{
    void __thiscall FUN_00aa5610(void* p);
};

struct Cls877
{
    int m_00;
    int m_04;
    Holder877* m_08;
    Node877* m_0c;
    unsigned char __thiscall PopNode(void* dest);
};

struct Block877
{
    int a, b, c, d, e, f, g, h;
};

// @fnv 0x00877cc0
unsigned char __thiscall Cls877::PopNode(void* dest)
{
    Node877* node = m_0c;
    unsigned char result;
    if (node != 0)
    {
        *(Block877*)dest = *(Block877*)((char*)node + 4);
        m_0c = node->next;
        node->FUN_007b3fa0(0);
        m_08->FUN_00aa5610(node);
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

struct FUN_00877db0_Embedded
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

struct FUN_00877db0_Class
{
    int unk00;
    FUN_00877db0_Embedded unk04;

    FUN_00877db0_Class();
};

// @fnv 0x00877db0
FUN_00877db0_Class::FUN_00877db0_Class() : unk00(0), unk04()
{}

class FUN_00877f10_base
{
  public:
    virtual ~FUN_00877f10_base();
    FUN_00877f10_base(int a, int b);

    int m_i04;
};

class FUN_00877f10_obj
{
  public:
    virtual void v0();
    virtual void v1(void* p);
};

class FUN_00877f10 : public FUN_00877f10_base
{
  public:
    FUN_00877f10(int a, int b);
    virtual ~FUN_00877f10();
};

// Constructs the base with a and b, then passes this to v1 on the object returned by FUN_00877950.
// @fnv 0x00877f10
FUN_00877f10::FUN_00877f10(int a, int b) : FUN_00877f10_base(a, b)
{
    reinterpret_cast<FUN_00877f10_obj*>(FUN_00877950())->v1(this);
}

class FUN_00877fc0_base
{
  public:
    virtual void v0();
    ~FUN_00877fc0_base();

    int m_i04;
};

class FUN_00877fc0_obj
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2(void* p);
};

class FUN_00877fc0 : public FUN_00877fc0_base
{
  public:
    virtual ~FUN_00877fc0();
};

// Calls v2 on the object returned by FUN_00877950, passing this, as part of destruction.
// @fnv 0x00877fc0
FUN_00877fc0::~FUN_00877fc0()
{
    reinterpret_cast<FUN_00877fc0_obj*>(FUN_00877950())->v2(this);
}

// FUN_00878030 : resets a game object and returns it.
extern char DAT_01400000;
extern char FUN_00a00000;

struct Member14_b3616
{
    void FUN_0044fae0();
};

struct FUN_00878030_cls
{
    void* m_pDatA;
    unsigned int m_uiFlags1;
    void* m_pDatB;
    unsigned int m_uiFlags2;
    unsigned int m_uiFlags3;
    Member14_b3616 m_Sub14;
    FUN_00878030_cls* FUN_00878030();
};

// @fnv 0x00878030
FUN_00878030_cls* FUN_00878030_cls::FUN_00878030()
{
    m_Sub14.FUN_0044fae0();
    m_pDatA = &DAT_01400000;
    m_uiFlags1 = 0xf00000;
    m_pDatB = &FUN_00a00000;
    m_uiFlags2 = 0x200000;
    m_uiFlags3 = 0xffffffff;
    return this;
}

struct StateControl
{
    bool __thiscall FUN_0044b130();
    void __thiscall FUN_0082f1f0();
};
struct ManagedEntry
{
    void __thiscall RunStep();
};
void* __cdecl FUN_00401020();
ManagedEntry* __stdcall FUN_00401020(int mode, unsigned int index, bool* enabled);
struct FUN_00878080_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    StateControl control;
    void __thiscall FUN_00878080(int unused);
};
// @fnv 0x00878080
void FUN_00878080_Class::FUN_00878080(int unused)
{
    if (!control.FUN_0044b130())
        return;
    if (reinterpret_cast<FUN_00878110_Class*>(FUN_00401020())->FUN_00878110() > 0)
    {
        bool enabled = true;
        {
            unsigned int index = 0;
            for (; index <= reinterpret_cast<FUN_00878110_Class*>(FUN_00401020())->FUN_00878110(); ++index)
            {
                FUN_00401020(0, index, &enabled)->RunStep();
            }
        }
        reinterpret_cast<FUN_00878130_Class*>(FUN_00401020())->ResetAndGetValue();
    }
    control.FUN_0082f1f0();
}

extern int DAT_011a95fc;

// @fnv 0x008781f0
int __cdecl FUN_008781f0()
{
    return DAT_011a95fc;
}

// Claim: CallSubCallee (22 bytes, /MT /Od /Oy- /GS /EHsc /Gy)
//
// Shape: a tiny __thiscall member that forwards to a member function of an
// embedded sub-object living at this+0x14.

struct Sub_0044fb00
{
    void Callee();
};

// Stand-in for the owning class: 0x14 bytes of leading members, then the
// embedded sub-object whose method is invoked.
struct Owner_008783a0
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    Sub_0044fb00 m_sub;

    void CallSubCallee();
};

// @fnv 0x008783a0
void Owner_008783a0::CallSubCallee()
{
    m_sub.Callee();
}

// Claim: clm_7b4ec1e887d84607aabf  FUN_0087a730
// 51 bytes, thiscall, /Od. Prologue stores `this` in the local slot, then the
// member pointer at +0 is used as the `this` of two byte-returning helpers.

struct FUN_0087a730_target
{
    bool FUN_0087a770();
    bool GetField24();
};

struct FUN_0087a730_cls
{
    FUN_0087a730_target* unk00;
    bool FUN_0087a730();
};

// Returns true when unk00's FUN_0087a770 and GetField24 both return false, otherwise false.
// @fnv 0x0087a730
bool FUN_0087a730_cls::FUN_0087a730()
{
    if (!this->unk00->FUN_0087a770() && !this->unk00->GetField24())
        return true;
    return false;
}

struct EventSource
{
    void __thiscall FUN_0040f6e0();
};
union PacketValue
{
    unsigned int bits;
    unsigned char byte;
};
struct EventMessage
{
    unsigned int code;
    EventSource* source;
    union
    {
        struct
        {
            PacketValue first;
            PacketValue second;
            PacketValue third;
        } arguments;
        unsigned char serializedArguments[24];
    } payload;
};
struct Receiver
{
    void __thiscall FUN_0087d160(EventMessage* message);
    void __thiscall SendEvent(EventSource* source, unsigned char first, unsigned char second, unsigned char third);
};
// @fnv 0x0087b300
void Receiver::SendEvent(EventSource* source, unsigned char first, unsigned char second, unsigned char third)
{
    EventMessage message;
    message.code = 49;
    message.source = source;
    message.payload.arguments.first.byte = first;
    message.payload.arguments.second.byte = second;
    message.payload.arguments.third.byte = third;
    source->FUN_0040f6e0();
    FUN_0087d160(&message);
}

struct S_0087e9d0_Base
{
    int unk000;
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
};

struct S_0087e9d0_Class : public S_0087e9d0_Base
{
    bool unk254;
    bool unk255;

    void __thiscall FUN_0087e9d0(bool value);
};

// Stores the logical AND of unk254 and value into unk255.
// @fnv 0x0087e9d0
void __thiscall S_0087e9d0_Class::FUN_0087e9d0(bool value)
{
    unk255 = unk254 && value;
}

// Buffer constructor: remember capacity and owner data, allocate the storage when the capacity is non-zero.

void* __cdecl C41D0Allocate(unsigned int uiSize);

class FUN_008641d0
{
  public:
    FUN_008641d0(unsigned int uiCapacity, void* pvUserData);
    virtual ~FUN_008641d0();

    void* pvContextData;
    unsigned int m_uiCapacity;
    unsigned int m_uiAllocatedCapacity;
    unsigned int m_uiPosition;
    void* m_pvUserData;
};

// @fnv 0x008641d0
FUN_008641d0::FUN_008641d0(unsigned int uiCapacity, void* pvUserData)
{
    m_uiCapacity = uiCapacity;
    m_pvUserData = pvUserData;
    m_uiAllocatedCapacity = 0;
    m_uiPosition = 0;
    if (m_uiCapacity > 0)
        pvContextData = C41D0Allocate(m_uiCapacity);
    else
        pvContextData = 0;
}

class BSAudio867
{
  public:
    static BSAudio867* GetSingleton();
    bool IsEnabled();
};

class Base867
{
  public:
    Base867();
    virtual ~Base867();

    void SetEnabled(bool bEnabled);
};

class FUN_008670e0 : public Base867
{
  public:
    FUN_008670e0();
    virtual ~FUN_008670e0();
};

// Constructs the object and sets its enabled state from BSAudio867::GetSingleton()->IsEnabled().
// @fnv 0x008670e0
FUN_008670e0::FUN_008670e0()
{
    SetEnabled(BSAudio867::GetSingleton()->IsEnabled());
}

struct Array08
{
    int unk00;
    char** data;
    unsigned short capacity, size, count, grow;
    void Resize(unsigned int newSize);
};
// Resizes the array to newSize: clears and counts down removed non-null entries, reallocates data, copies old entries and zero-fills the rest.
// @fnv 0x008696e0
void Array08::Resize(unsigned int newSize)
{
    if (newSize == capacity)
        return;
    unsigned short i;
    if (newSize < size)
    {
        for (i = (unsigned short)newSize; i < size; i++)
        {
            if (data[i])
            {
                data[i] = 0;
                count--;
            }
        }
        size = (unsigned short)newSize;
    }
    char** oldData = data;
    capacity = (unsigned short)newSize;
    if (newSize > 0)
    {
        data = (char**)AllocateUIntArray((unsigned int)capacity);
        for (i = 0; i < size; i++)
            data[i] = oldData[i];
        for (i = size; i < capacity; i++)
            data[i] = 0;
    }
    else
        data = 0;
    FUN_008696c0((void*)oldData);
}

struct FUN_00aa53f0
{
    int count;
    int capacity;
    void* data;
    int state;
    FUN_00aa53f0();
    ~FUN_00aa53f0();
};
void FUN_0087b990();
struct FUN_0086c620
{
    int owner;
    int state;
    int flags;
    int start;
    int duration;
    int elapsed;
    int value;
    int target;
    int done;
    int reserved;
    FUN_0086c620(void*, void (*)());
    ~FUN_0086c620();
    void SignalAtOffset();
};
class BSShaderAccumulator
{
  public:
    static void* operator new(unsigned int);
    BSShaderAccumulator(int, unsigned int, unsigned int);
    int unk000;
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
    void FUN_004a1040(unsigned int);
    void FUN_00936aa0(bool);
};
struct FUN_00633c90
{
    void* ptr;
    FUN_00633c90(int);
    ~FUN_00633c90();
    void FUN_0066b0d0(void*);
    BSShaderAccumulator* FUN_00559450();
};
extern FUN_00633c90 DAT_011dec64;
class FUN_00a712f0
{
  public:
    static void* operator new(unsigned int);
    FUN_00a712f0();
    int unk000;
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
};
struct Global_p161
{
    int* FUN_0043d4d0();
};
extern Global_p161 DAT_011c3ea4;
int FUN_0040fc90();
void FUN_0087b8d0(FUN_0086c620*, FUN_0086c620*);
extern const char DAT_0105c2b0[];
extern const char DAT_010829c4[];
void FUN_00aa2740(int, const char*);
class AutoMemContext
{
  public:
    int context;
    AutoMemContext(int, bool, const char*, int);
    ~AutoMemContext();
    void FUN_00404f00(int, bool, const char*, int);
    void Leave();
};
void CreateC790Manager(int);
struct Controls_p161
{
    void LoadControlsFromIni();
};
Controls_p161* FUN_007fdf30();
struct FUN_0086c160
{
    char unk00;
    bool b1, b2, b3, b4, b5, b6, b7;
    int arg1, arg2, thread, state;
    FUN_00aa53f0 list18;
    FUN_0086c620 timer28;
    FUN_00aa53f0 list50;
    FUN_0086c620 timer60;
    FUN_00633c90 acc88, acc8c, acc90, acc94, acc98;
    bool flag9c;
    FUN_00633c90 acca0;
    FUN_0086c160(int, int);
    void InitAudioCallbacks();
};
// @fnv 0x0086c160
FUN_0086c160::FUN_0086c160(int aiArg1, int aiArg2)
    : timer28(&list18, FUN_0087b990), timer60(&list50, FUN_0087b990), acc88(0), acc8c(0), acc90(0), acc94(0), acc98(0),
      acca0(0)
{
    b1 = false;
    b2 = false;
    b3 = false;
    b4 = false;
    b5 = false;
    b6 = false;
    b7 = false;
    DAT_011dec64.FUN_0066b0d0(0);
    acc88.FUN_0066b0d0(new BSShaderAccumulator(99, 1, 759));
    acc8c.FUN_0066b0d0(new BSShaderAccumulator(99, 1, 759));
    acc8c.FUN_00559450()->FUN_004a1040(12);
    acc8c.FUN_00559450()->FUN_00936aa0(true);
    acc90.FUN_0066b0d0(new BSShaderAccumulator(99, 1, 759));
    acc90.FUN_00559450()->FUN_004a1040(12);
    acc90.FUN_00559450()->FUN_00936aa0(true);
    acc94.FUN_0066b0d0(new BSShaderAccumulator(100, 1, 4));
    acc94.FUN_00559450()->FUN_004a1040(13);
    acc98.FUN_0066b0d0(new BSShaderAccumulator(99, 1, 759));
    flag9c = false;
    acca0.FUN_0066b0d0(new FUN_00a712f0);
    if (*DAT_011c3ea4.FUN_0043d4d0() > 1)
    {
        FUN_0087b8d0(&timer28, &timer60);
        timer28.SignalAtOffset();
        timer60.SignalAtOffset();
    }
    DAT_011c3ea4.FUN_0043d4d0();
    thread = FUN_0040fc90();
    arg1 = aiArg1;
    arg2 = aiArg2;
    state = 0;
    FUN_00aa2740(thread, DAT_0105c2b0);
    AutoMemContext context(13, true, DAT_010829c4, 3526);
    CreateC790Manager(aiArg2);
    FUN_007fdf30()->LoadControlsFromIni();
    context.Leave();
    context.FUN_00404f00(11, true, DAT_010829c4, 3541);
    InitAudioCallbacks();
    context.Leave();
}

// Recreate the global manager: delete the old instance and construct a new one for the given owner.

class C790Manager
{
  public:
    C790Manager(void* pvOwner);
    ~C790Manager();

    int unk0000;
    int unk0004;
    int unk0008;
    int unk000C;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001C;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002C;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003C;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004C;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005C;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006C;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007C;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008C;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009C;
    int unk00A0;
    int unk00A4;
    int unk00A8;
    int unk00AC;
    int unk00B0;
    int unk00B4;
    int unk00B8;
    int unk00BC;
    int unk00C0;
    int unk00C4;
    int unk00C8;
    int unk00CC;
    int unk00D0;
    int unk00D4;
    int unk00D8;
    int unk00DC;
    int unk00E0;
    int unk00E4;
    int unk00E8;
    int unk00EC;
    int unk00F0;
    int unk00F4;
    int unk00F8;
    int unk00FC;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010C;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011C;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012C;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013C;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014C;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015C;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016C;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017C;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018C;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019C;
    int unk01A0;
    int unk01A4;
    int unk01A8;
    int unk01AC;
    int unk01B0;
    int unk01B4;
    int unk01B8;
    int unk01BC;
    int unk01C0;
    int unk01C4;
    int unk01C8;
    int unk01CC;
    int unk01D0;
    int unk01D4;
    int unk01D8;
    int unk01DC;
    int unk01E0;
    int unk01E4;
    int unk01E8;
    int unk01EC;
    int unk01F0;
    int unk01F4;
    int unk01F8;
    int unk01FC;
    int unk0200;
    int unk0204;
    int unk0208;
    int unk020C;
    int unk0210;
    int unk0214;
    int unk0218;
    int unk021C;
    int unk0220;
    int unk0224;
    int unk0228;
    int unk022C;
    int unk0230;
    int unk0234;
    int unk0238;
    int unk023C;
    int unk0240;
    int unk0244;
    int unk0248;
    int unk024C;
    int unk0250;
    int unk0254;
    int unk0258;
    int unk025C;
    int unk0260;
    int unk0264;
    int unk0268;
    int unk026C;
    int unk0270;
    int unk0274;
    int unk0278;
    int unk027C;
    int unk0280;
    int unk0284;
    int unk0288;
    int unk028C;
    int unk0290;
    int unk0294;
    int unk0298;
    int unk029C;
    int unk02A0;
    int unk02A4;
    int unk02A8;
    int unk02AC;
    int unk02B0;
    int unk02B4;
    int unk02B8;
    int unk02BC;
    int unk02C0;
    int unk02C4;
    int unk02C8;
    int unk02CC;
    int unk02D0;
    int unk02D4;
    int unk02D8;
    int unk02DC;
    int unk02E0;
    int unk02E4;
    int unk02E8;
    int unk02EC;
    int unk02F0;
    int unk02F4;
    int unk02F8;
    int unk02FC;
    int unk0300;
    int unk0304;
    int unk0308;
    int unk030C;
    int unk0310;
    int unk0314;
    int unk0318;
    int unk031C;
    int unk0320;
    int unk0324;
    int unk0328;
    int unk032C;
    int unk0330;
    int unk0334;
    int unk0338;
    int unk033C;
    int unk0340;
    int unk0344;
    int unk0348;
    int unk034C;
    int unk0350;
    int unk0354;
    int unk0358;
    int unk035C;
    int unk0360;
    int unk0364;
    int unk0368;
    int unk036C;
    int unk0370;
    int unk0374;
    int unk0378;
    int unk037C;
    int unk0380;
    int unk0384;
    int unk0388;
    int unk038C;
    int unk0390;
    int unk0394;
    int unk0398;
    int unk039C;
    int unk03A0;
    int unk03A4;
    int unk03A8;
    int unk03AC;
    int unk03B0;
    int unk03B4;
    int unk03B8;
    int unk03BC;
    int unk03C0;
    int unk03C4;
    int unk03C8;
    int unk03CC;
    int unk03D0;
    int unk03D4;
    int unk03D8;
    int unk03DC;
    int unk03E0;
    int unk03E4;
    int unk03E8;
    int unk03EC;
    int unk03F0;
    int unk03F4;
    int unk03F8;
    int unk03FC;
    int unk0400;
    int unk0404;
    int unk0408;
    int unk040C;
    int unk0410;
    int unk0414;
    int unk0418;
    int unk041C;
    int unk0420;
    int unk0424;
    int unk0428;
    int unk042C;
    int unk0430;
    int unk0434;
    int unk0438;
    int unk043C;
    int unk0440;
    int unk0444;
    int unk0448;
    int unk044C;
    int unk0450;
    int unk0454;
    int unk0458;
    int unk045C;
    int unk0460;
    int unk0464;
    int unk0468;
    int unk046C;
    int unk0470;
    int unk0474;
    int unk0478;
    int unk047C;
    int unk0480;
    int unk0484;
    int unk0488;
    int unk048C;
    int unk0490;
    int unk0494;
    int unk0498;
    int unk049C;
    int unk04A0;
    int unk04A4;
    int unk04A8;
    int unk04AC;
    int unk04B0;
    int unk04B4;
    int unk04B8;
    int unk04BC;
    int unk04C0;
    int unk04C4;
    int unk04C8;
    int unk04CC;
    int unk04D0;
    int unk04D4;
    int unk04D8;
    int unk04DC;
    int unk04E0;
    int unk04E4;
    int unk04E8;
    int unk04EC;
    int unk04F0;
    int unk04F4;
    int unk04F8;
    int unk04FC;
    int unk0500;
    int unk0504;
    int unk0508;
    int unk050C;
    int unk0510;
    int unk0514;
    int unk0518;
    int unk051C;
    int unk0520;
    int unk0524;
    int unk0528;
    int unk052C;
    int unk0530;
    int unk0534;
    int unk0538;
    int unk053C;
    int unk0540;
    int unk0544;
    int unk0548;
    int unk054C;
    int unk0550;
    int unk0554;
    int unk0558;
    int unk055C;
    int unk0560;
    int unk0564;
    int unk0568;
    int unk056C;
    int unk0570;
    int unk0574;
    int unk0578;
    int unk057C;
    int unk0580;
    int unk0584;
    int unk0588;
    int unk058C;
    int unk0590;
    int unk0594;
    int unk0598;
    int unk059C;
    int unk05A0;
    int unk05A4;
    int unk05A8;
    int unk05AC;
    int unk05B0;
    int unk05B4;
    int unk05B8;
    int unk05BC;
    int unk05C0;
    int unk05C4;
    int unk05C8;
    int unk05CC;
    int unk05D0;
    int unk05D4;
    int unk05D8;
    int unk05DC;
    int unk05E0;
    int unk05E4;
    int unk05E8;
    int unk05EC;
    int unk05F0;
    int unk05F4;
    int unk05F8;
    int unk05FC;
    int unk0600;
    int unk0604;
    int unk0608;
    int unk060C;
    int unk0610;
    int unk0614;
    int unk0618;
    int unk061C;
    int unk0620;
    int unk0624;
    int unk0628;
    int unk062C;
    int unk0630;
    int unk0634;
    int unk0638;
    int unk063C;
    int unk0640;
    int unk0644;
    int unk0648;
    int unk064C;
    int unk0650;
    int unk0654;
    int unk0658;
    int unk065C;
    int unk0660;
    int unk0664;
    int unk0668;
    int unk066C;
    int unk0670;
    int unk0674;
    int unk0678;
    int unk067C;
    int unk0680;
    int unk0684;
    int unk0688;
    int unk068C;
    int unk0690;
    int unk0694;
    int unk0698;
    int unk069C;
    int unk06A0;
    int unk06A4;
    int unk06A8;
    int unk06AC;
    int unk06B0;
    int unk06B4;
    int unk06B8;
    int unk06BC;
    int unk06C0;
    int unk06C4;
    int unk06C8;
    int unk06CC;
    int unk06D0;
    int unk06D4;
    int unk06D8;
    int unk06DC;
    int unk06E0;
    int unk06E4;
    int unk06E8;
    int unk06EC;
    int unk06F0;
    int unk06F4;
    int unk06F8;
    int unk06FC;
    int unk0700;
    int unk0704;
    int unk0708;
    int unk070C;
    int unk0710;
    int unk0714;
    int unk0718;
    int unk071C;
    int unk0720;
    int unk0724;
    int unk0728;
    int unk072C;
    int unk0730;
    int unk0734;
    int unk0738;
    int unk073C;
    int unk0740;
    int unk0744;
    int unk0748;
    int unk074C;
    int unk0750;
    int unk0754;
    int unk0758;
    int unk075C;
    int unk0760;
    int unk0764;
    int unk0768;
    int unk076C;
    int unk0770;
    int unk0774;
    int unk0778;
    int unk077C;
    int unk0780;
    int unk0784;
    int unk0788;
    int unk078C;
    int unk0790;
    int unk0794;
    int unk0798;
    int unk079C;
    int unk07A0;
    int unk07A4;
    int unk07A8;
    int unk07AC;
    int unk07B0;
    int unk07B4;
    int unk07B8;
    int unk07BC;
    int unk07C0;
    int unk07C4;
    int unk07C8;
    int unk07CC;
    int unk07D0;
    int unk07D4;
    int unk07D8;
    int unk07DC;
    int unk07E0;
    int unk07E4;
    int unk07E8;
    int unk07EC;
    int unk07F0;
    int unk07F4;
    int unk07F8;
    int unk07FC;
    int unk0800;
    int unk0804;
    int unk0808;
    int unk080C;
    int unk0810;
    int unk0814;
    int unk0818;
    int unk081C;
    int unk0820;
    int unk0824;
    int unk0828;
    int unk082C;
    int unk0830;
    int unk0834;
    int unk0838;
    int unk083C;
    int unk0840;
    int unk0844;
    int unk0848;
    int unk084C;
    int unk0850;
    int unk0854;
    int unk0858;
    int unk085C;
    int unk0860;
    int unk0864;
    int unk0868;
    int unk086C;
    int unk0870;
    int unk0874;
    int unk0878;
    int unk087C;
    int unk0880;
    int unk0884;
    int unk0888;
    int unk088C;
    int unk0890;
    int unk0894;
    int unk0898;
    int unk089C;
    int unk08A0;
    int unk08A4;
    int unk08A8;
    int unk08AC;
    int unk08B0;
    int unk08B4;
    int unk08B8;
    int unk08BC;
    int unk08C0;
    int unk08C4;
    int unk08C8;
    int unk08CC;
    int unk08D0;
    int unk08D4;
    int unk08D8;
    int unk08DC;
    int unk08E0;
    int unk08E4;
    int unk08E8;
    int unk08EC;
    int unk08F0;
    int unk08F4;
    int unk08F8;
    int unk08FC;
    int unk0900;
    int unk0904;
    int unk0908;
    int unk090C;
    int unk0910;
    int unk0914;
    int unk0918;
    int unk091C;
    int unk0920;
    int unk0924;
    int unk0928;
    int unk092C;
    int unk0930;
    int unk0934;
    int unk0938;
    int unk093C;
    int unk0940;
    int unk0944;
    int unk0948;
    int unk094C;
    int unk0950;
    int unk0954;
    int unk0958;
    int unk095C;
    int unk0960;
    int unk0964;
    int unk0968;
    int unk096C;
    int unk0970;
    int unk0974;
    int unk0978;
    int unk097C;
    int unk0980;
    int unk0984;
    int unk0988;
    int unk098C;
    int unk0990;
    int unk0994;
    int unk0998;
    int unk099C;
    int unk09A0;
    int unk09A4;
    int unk09A8;
    int unk09AC;
    int unk09B0;
    int unk09B4;
    int unk09B8;
    int unk09BC;
    int unk09C0;
    int unk09C4;
    int unk09C8;
    int unk09CC;
    int unk09D0;
    int unk09D4;
    int unk09D8;
    int unk09DC;
    int unk09E0;
    int unk09E4;
    int unk09E8;
    int unk09EC;
    int unk09F0;
    int unk09F4;
    int unk09F8;
    int unk09FC;
    int unk0A00;
    int unk0A04;
    int unk0A08;
    int unk0A0C;
    int unk0A10;
    int unk0A14;
    int unk0A18;
    int unk0A1C;
    int unk0A20;
    int unk0A24;
    int unk0A28;
    int unk0A2C;
    int unk0A30;
    int unk0A34;
    int unk0A38;
    int unk0A3C;
    int unk0A40;
    int unk0A44;
    int unk0A48;
    int unk0A4C;
    int unk0A50;
    int unk0A54;
    int unk0A58;
    int unk0A5C;
    int unk0A60;
    int unk0A64;
    int unk0A68;
    int unk0A6C;
    int unk0A70;
    int unk0A74;
    int unk0A78;
    int unk0A7C;
    int unk0A80;
    int unk0A84;
    int unk0A88;
    int unk0A8C;
    int unk0A90;
    int unk0A94;
    int unk0A98;
    int unk0A9C;
    int unk0AA0;
    int unk0AA4;
    int unk0AA8;
    int unk0AAC;
    int unk0AB0;
    int unk0AB4;
    int unk0AB8;
    int unk0ABC;
    int unk0AC0;
    int unk0AC4;
    int unk0AC8;
    int unk0ACC;
    int unk0AD0;
    int unk0AD4;
    int unk0AD8;
    int unk0ADC;
    int unk0AE0;
    int unk0AE4;
    int unk0AE8;
    int unk0AEC;
    int unk0AF0;
    int unk0AF4;
    int unk0AF8;
    int unk0AFC;
    int unk0B00;
    int unk0B04;
    int unk0B08;
    int unk0B0C;
    int unk0B10;
    int unk0B14;
    int unk0B18;
    int unk0B1C;
    int unk0B20;
    int unk0B24;
    int unk0B28;
    int unk0B2C;
    int unk0B30;
    int unk0B34;
    int unk0B38;
    int unk0B3C;
    int unk0B40;
    int unk0B44;
    int unk0B48;
    int unk0B4C;
    int unk0B50;
    int unk0B54;
    int unk0B58;
    int unk0B5C;
    int unk0B60;
    int unk0B64;
    int unk0B68;
    int unk0B6C;
    int unk0B70;
    int unk0B74;
    int unk0B78;
    int unk0B7C;
    int unk0B80;
    int unk0B84;
    int unk0B88;
    int unk0B8C;
    int unk0B90;
    int unk0B94;
    int unk0B98;
    int unk0B9C;
    int unk0BA0;
    int unk0BA4;
    int unk0BA8;
    int unk0BAC;
    int unk0BB0;
    int unk0BB4;
    int unk0BB8;
    int unk0BBC;
    int unk0BC0;
    int unk0BC4;
    int unk0BC8;
    int unk0BCC;
    int unk0BD0;
    int unk0BD4;
    int unk0BD8;
    int unk0BDC;
    int unk0BE0;
    int unk0BE4;
    int unk0BE8;
    int unk0BEC;
    int unk0BF0;
    int unk0BF4;
    int unk0BF8;
    int unk0BFC;
    int unk0C00;
    int unk0C04;
    int unk0C08;
    int unk0C0C;
    int unk0C10;
    int unk0C14;
    int unk0C18;
    int unk0C1C;
    int unk0C20;
    int unk0C24;
    int unk0C28;
    int unk0C2C;
    int unk0C30;
    int unk0C34;
    int unk0C38;
    int unk0C3C;
    int unk0C40;
    int unk0C44;
    int unk0C48;
    int unk0C4C;
    int unk0C50;
    int unk0C54;
    int unk0C58;
    int unk0C5C;
    int unk0C60;
    int unk0C64;
    int unk0C68;
    int unk0C6C;
    int unk0C70;
    int unk0C74;
    int unk0C78;
    int unk0C7C;
    int unk0C80;
    int unk0C84;
    int unk0C88;
    int unk0C8C;
    int unk0C90;
    int unk0C94;
    int unk0C98;
    int unk0C9C;
    int unk0CA0;
    int unk0CA4;
    int unk0CA8;
    int unk0CAC;
    int unk0CB0;
    int unk0CB4;
    int unk0CB8;
    int unk0CBC;
    int unk0CC0;
    int unk0CC4;
    int unk0CC8;
    int unk0CCC;
    int unk0CD0;
    int unk0CD4;
    int unk0CD8;
    int unk0CDC;
    int unk0CE0;
    int unk0CE4;
    int unk0CE8;
    int unk0CEC;
    int unk0CF0;
    int unk0CF4;
    int unk0CF8;
    int unk0CFC;
    int unk0D00;
    int unk0D04;
    int unk0D08;
    int unk0D0C;
    int unk0D10;
    int unk0D14;
    int unk0D18;
    int unk0D1C;
    int unk0D20;
    int unk0D24;
    int unk0D28;
    int unk0D2C;
    int unk0D30;
    int unk0D34;
    int unk0D38;
    int unk0D3C;
    int unk0D40;
    int unk0D44;
    int unk0D48;
    int unk0D4C;
    int unk0D50;
    int unk0D54;
    int unk0D58;
    int unk0D5C;
    int unk0D60;
    int unk0D64;
    int unk0D68;
    int unk0D6C;
    int unk0D70;
    int unk0D74;
    int unk0D78;
    int unk0D7C;
    int unk0D80;
    int unk0D84;
    int unk0D88;
    int unk0D8C;
    int unk0D90;
    int unk0D94;
    int unk0D98;
    int unk0D9C;
    int unk0DA0;
    int unk0DA4;
    int unk0DA8;
    int unk0DAC;
    int unk0DB0;
    int unk0DB4;
    int unk0DB8;
    int unk0DBC;
    int unk0DC0;
    int unk0DC4;
    int unk0DC8;
    int unk0DCC;
    int unk0DD0;
    int unk0DD4;
    int unk0DD8;
    int unk0DDC;
    int unk0DE0;
    int unk0DE4;
    int unk0DE8;
    int unk0DEC;
    int unk0DF0;
    int unk0DF4;
    int unk0DF8;
    int unk0DFC;
    int unk0E00;
    int unk0E04;
    int unk0E08;
    int unk0E0C;
    int unk0E10;
    int unk0E14;
    int unk0E18;
    int unk0E1C;
    int unk0E20;
    int unk0E24;
    int unk0E28;
    int unk0E2C;
    int unk0E30;
    int unk0E34;
    int unk0E38;
    int unk0E3C;
    int unk0E40;
    int unk0E44;
    int unk0E48;
    int unk0E4C;
    int unk0E50;
    int unk0E54;
    int unk0E58;
    int unk0E5C;
    int unk0E60;
    int unk0E64;
    int unk0E68;
    int unk0E6C;
    int unk0E70;
    int unk0E74;
    int unk0E78;
    int unk0E7C;
    int unk0E80;
    int unk0E84;
    int unk0E88;
    int unk0E8C;
    int unk0E90;
    int unk0E94;
    int unk0E98;
    int unk0E9C;
    int unk0EA0;
    int unk0EA4;
    int unk0EA8;
    int unk0EAC;
    int unk0EB0;
    int unk0EB4;
    int unk0EB8;
    int unk0EBC;
    int unk0EC0;
    int unk0EC4;
    int unk0EC8;
    int unk0ECC;
    int unk0ED0;
    int unk0ED4;
    int unk0ED8;
    int unk0EDC;
    int unk0EE0;
    int unk0EE4;
    int unk0EE8;
    int unk0EEC;
    int unk0EF0;
    int unk0EF4;
    int unk0EF8;
    int unk0EFC;
    int unk0F00;
    int unk0F04;
    int unk0F08;
    int unk0F0C;
    int unk0F10;
    int unk0F14;
    int unk0F18;
    int unk0F1C;
    int unk0F20;
    int unk0F24;
    int unk0F28;
    int unk0F2C;
    int unk0F30;
    int unk0F34;
    int unk0F38;
    int unk0F3C;
    int unk0F40;
    int unk0F44;
    int unk0F48;
    int unk0F4C;
    int unk0F50;
    int unk0F54;
    int unk0F58;
    int unk0F5C;
    int unk0F60;
    int unk0F64;
    int unk0F68;
    int unk0F6C;
    int unk0F70;
    int unk0F74;
    int unk0F78;
    int unk0F7C;
    int unk0F80;
    int unk0F84;
    int unk0F88;
    int unk0F8C;
    int unk0F90;
    int unk0F94;
    int unk0F98;
    int unk0F9C;
    int unk0FA0;
    int unk0FA4;
    int unk0FA8;
    int unk0FAC;
    int unk0FB0;
    int unk0FB4;
    int unk0FB8;
    int unk0FBC;
    int unk0FC0;
    int unk0FC4;
    int unk0FC8;
    int unk0FCC;
    int unk0FD0;
    int unk0FD4;
    int unk0FD8;
    int unk0FDC;
    int unk0FE0;
    int unk0FE4;
    int unk0FE8;
    int unk0FEC;
    int unk0FF0;
    int unk0FF4;
    int unk0FF8;
    int unk0FFC;
    int unk1000;
    int unk1004;
    int unk1008;
    int unk100C;
    int unk1010;
    int unk1014;
    int unk1018;
    int unk101C;
    int unk1020;
    int unk1024;
    int unk1028;
    int unk102C;
    int unk1030;
    int unk1034;
    int unk1038;
    int unk103C;
    int unk1040;
    int unk1044;
    int unk1048;
    int unk104C;
    int unk1050;
    int unk1054;
    int unk1058;
    int unk105C;
    int unk1060;
    int unk1064;
    int unk1068;
    int unk106C;
    int unk1070;
    int unk1074;
    int unk1078;
    int unk107C;
    int unk1080;
    int unk1084;
    int unk1088;
    int unk108C;
    int unk1090;
    int unk1094;
    int unk1098;
    int unk109C;
    int unk10A0;
    int unk10A4;
    int unk10A8;
    int unk10AC;
    int unk10B0;
    int unk10B4;
    int unk10B8;
    int unk10BC;
    int unk10C0;
    int unk10C4;
    int unk10C8;
    int unk10CC;
    int unk10D0;
    int unk10D4;
    int unk10D8;
    int unk10DC;
    int unk10E0;
    int unk10E4;
    int unk10E8;
    int unk10EC;
    int unk10F0;
    int unk10F4;
    int unk10F8;
    int unk10FC;
    int unk1100;
    int unk1104;
    int unk1108;
    int unk110C;
    int unk1110;
    int unk1114;
    int unk1118;
    int unk111C;
    int unk1120;
    int unk1124;
    int unk1128;
    int unk112C;
    int unk1130;
    int unk1134;
    int unk1138;
    int unk113C;
    int unk1140;
    int unk1144;
    int unk1148;
    int unk114C;
    int unk1150;
    int unk1154;
    int unk1158;
    int unk115C;
    int unk1160;
    int unk1164;
    int unk1168;
    int unk116C;
    int unk1170;
    int unk1174;
    int unk1178;
    int unk117C;
    int unk1180;
    int unk1184;
    int unk1188;
    int unk118C;
    int unk1190;
    int unk1194;
    int unk1198;
    int unk119C;
    int unk11A0;
    int unk11A4;
    int unk11A8;
    int unk11AC;
    int unk11B0;
    int unk11B4;
    int unk11B8;
    int unk11BC;
    int unk11C0;
    int unk11C4;
    int unk11C8;
    int unk11CC;
    int unk11D0;
    int unk11D4;
    int unk11D8;
    int unk11DC;
    int unk11E0;
    int unk11E4;
    int unk11E8;
    int unk11EC;
    int unk11F0;
    int unk11F4;
    int unk11F8;
    int unk11FC;
    int unk1200;
    int unk1204;
    int unk1208;
    int unk120C;
    int unk1210;
    int unk1214;
    int unk1218;
    int unk121C;
    int unk1220;
    int unk1224;
    int unk1228;
    int unk122C;
    int unk1230;
    int unk1234;
    int unk1238;
    int unk123C;
    int unk1240;
    int unk1244;
    int unk1248;
    int unk124C;
    int unk1250;
    int unk1254;
    int unk1258;
    int unk125C;
    int unk1260;
    int unk1264;
    int unk1268;
    int unk126C;
    int unk1270;
    int unk1274;
    int unk1278;
    int unk127C;
    int unk1280;
    int unk1284;
    int unk1288;
    int unk128C;
    int unk1290;
    int unk1294;
    int unk1298;
    int unk129C;
    int unk12A0;
    int unk12A4;
    int unk12A8;
    int unk12AC;
    int unk12B0;
    int unk12B4;
    int unk12B8;
    int unk12BC;
    int unk12C0;
    int unk12C4;
    int unk12C8;
    int unk12CC;
    int unk12D0;
    int unk12D4;
    int unk12D8;
    int unk12DC;
    int unk12E0;
    int unk12E4;
    int unk12E8;
    int unk12EC;
    int unk12F0;
    int unk12F4;
    int unk12F8;
    int unk12FC;
    int unk1300;
    int unk1304;
    int unk1308;
    int unk130C;
    int unk1310;
    int unk1314;
    int unk1318;
    int unk131C;
    int unk1320;
    int unk1324;
    int unk1328;
    int unk132C;
    int unk1330;
    int unk1334;
    int unk1338;
    int unk133C;
    int unk1340;
    int unk1344;
    int unk1348;
    int unk134C;
    int unk1350;
    int unk1354;
    int unk1358;
    int unk135C;
    int unk1360;
    int unk1364;
    int unk1368;
    int unk136C;
    int unk1370;
    int unk1374;
    int unk1378;
    int unk137C;
    int unk1380;
    int unk1384;
    int unk1388;
    int unk138C;
    int unk1390;
    int unk1394;
    int unk1398;
    int unk139C;
    int unk13A0;
    int unk13A4;
    int unk13A8;
    int unk13AC;
    int unk13B0;
    int unk13B4;
    int unk13B8;
    int unk13BC;
    int unk13C0;
    int unk13C4;
    int unk13C8;
    int unk13CC;
    int unk13D0;
    int unk13D4;
    int unk13D8;
    int unk13DC;
    int unk13E0;
    int unk13E4;
    int unk13E8;
    int unk13EC;
    int unk13F0;
    int unk13F4;
    int unk13F8;
    int unk13FC;
    int unk1400;
    int unk1404;
    int unk1408;
    int unk140C;
    int unk1410;
    int unk1414;
    int unk1418;
    int unk141C;
    int unk1420;
    int unk1424;
    int unk1428;
    int unk142C;
    int unk1430;
    int unk1434;
    int unk1438;
    int unk143C;
    int unk1440;
    int unk1444;
    int unk1448;
    int unk144C;
    int unk1450;
    int unk1454;
    int unk1458;
    int unk145C;
    int unk1460;
    int unk1464;
    int unk1468;
    int unk146C;
    int unk1470;
    int unk1474;
    int unk1478;
    int unk147C;
    int unk1480;
    int unk1484;
    int unk1488;
    int unk148C;
    int unk1490;
    int unk1494;
    int unk1498;
    int unk149C;
    int unk14A0;
    int unk14A4;
    int unk14A8;
    int unk14AC;
    int unk14B0;
    int unk14B4;
    int unk14B8;
    int unk14BC;
    int unk14C0;
    int unk14C4;
    int unk14C8;
    int unk14CC;
    int unk14D0;
    int unk14D4;
    int unk14D8;
    int unk14DC;
    int unk14E0;
    int unk14E4;
    int unk14E8;
    int unk14EC;
    int unk14F0;
    int unk14F4;
    int unk14F8;
    int unk14FC;
    int unk1500;
    int unk1504;
    int unk1508;
    int unk150C;
    int unk1510;
    int unk1514;
    int unk1518;
    int unk151C;
    int unk1520;
    int unk1524;
    int unk1528;
    int unk152C;
    int unk1530;
    int unk1534;
    int unk1538;
    int unk153C;
    int unk1540;
    int unk1544;
    int unk1548;
    int unk154C;
    int unk1550;
    int unk1554;
    int unk1558;
    int unk155C;
    int unk1560;
    int unk1564;
    int unk1568;
    int unk156C;
    int unk1570;
    int unk1574;
    int unk1578;
    int unk157C;
    int unk1580;
    int unk1584;
    int unk1588;
    int unk158C;
    int unk1590;
    int unk1594;
    int unk1598;
    int unk159C;
    int unk15A0;
    int unk15A4;
    int unk15A8;
    int unk15AC;
    int unk15B0;
    int unk15B4;
    int unk15B8;
    int unk15BC;
    int unk15C0;
    int unk15C4;
    int unk15C8;
    int unk15CC;
    int unk15D0;
    int unk15D4;
    int unk15D8;
    int unk15DC;
    int unk15E0;
    int unk15E4;
    int unk15E8;
    int unk15EC;
    int unk15F0;
    int unk15F4;
    int unk15F8;
    int unk15FC;
    int unk1600;
    int unk1604;
    int unk1608;
    int unk160C;
    int unk1610;
    int unk1614;
    int unk1618;
    int unk161C;
    int unk1620;
    int unk1624;
    int unk1628;
    int unk162C;
    int unk1630;
    int unk1634;
    int unk1638;
    int unk163C;
    int unk1640;
    int unk1644;
    int unk1648;
    int unk164C;
    int unk1650;
    int unk1654;
    int unk1658;
    int unk165C;
    int unk1660;
    int unk1664;
    int unk1668;
    int unk166C;
    int unk1670;
    int unk1674;
    int unk1678;
    int unk167C;
    int unk1680;
    int unk1684;
    int unk1688;
    int unk168C;
    int unk1690;
    int unk1694;
    int unk1698;
    int unk169C;
    int unk16A0;
    int unk16A4;
    int unk16A8;
    int unk16AC;
    int unk16B0;
    int unk16B4;
    int unk16B8;
    int unk16BC;
    int unk16C0;
    int unk16C4;
    int unk16C8;
    int unk16CC;
    int unk16D0;
    int unk16D4;
    int unk16D8;
    int unk16DC;
    int unk16E0;
    int unk16E4;
    int unk16E8;
    int unk16EC;
    int unk16F0;
    int unk16F4;
    int unk16F8;
    int unk16FC;
    int unk1700;
    int unk1704;
    int unk1708;
    int unk170C;
    int unk1710;
    int unk1714;
    int unk1718;
    int unk171C;
    int unk1720;
    int unk1724;
    int unk1728;
    int unk172C;
    int unk1730;
    int unk1734;
    int unk1738;
    int unk173C;
    int unk1740;
    int unk1744;
    int unk1748;
    int unk174C;
    int unk1750;
    int unk1754;
    int unk1758;
    int unk175C;
    int unk1760;
    int unk1764;
    int unk1768;
    int unk176C;
    int unk1770;
    int unk1774;
    int unk1778;
    int unk177C;
    int unk1780;
    int unk1784;
    int unk1788;
    int unk178C;
    int unk1790;
    int unk1794;
    int unk1798;
    int unk179C;
    int unk17A0;
    int unk17A4;
    int unk17A8;
    int unk17AC;
    int unk17B0;
    int unk17B4;
    int unk17B8;
    int unk17BC;
    int unk17C0;
    int unk17C4;
    int unk17C8;
    int unk17CC;
    int unk17D0;
    int unk17D4;
    int unk17D8;
    int unk17DC;
    int unk17E0;
    int unk17E4;
    int unk17E8;
    int unk17EC;
    int unk17F0;
    int unk17F4;
    int unk17F8;
    int unk17FC;
    int unk1800;
    int unk1804;
    int unk1808;
    int unk180C;
    int unk1810;
    int unk1814;
    int unk1818;
    int unk181C;
    int unk1820;
    int unk1824;
    int unk1828;
    int unk182C;
    int unk1830;
    int unk1834;
    int unk1838;
    int unk183C;
    int unk1840;
    int unk1844;
    int unk1848;
    int unk184C;
    int unk1850;
    int unk1854;
    int unk1858;
    int unk185C;
    int unk1860;
    int unk1864;
    int unk1868;
    int unk186C;
    int unk1870;
    int unk1874;
    int unk1878;
    int unk187C;
    int unk1880;
    int unk1884;
    int unk1888;
    int unk188C;
    int unk1890;
    int unk1894;
    int unk1898;
    int unk189C;
    int unk18A0;
    int unk18A4;
    int unk18A8;
    int unk18AC;
    int unk18B0;
    int unk18B4;
    int unk18B8;
    int unk18BC;
    int unk18C0;
    int unk18C4;
    int unk18C8;
    int unk18CC;
    int unk18D0;
    int unk18D4;
    int unk18D8;
    int unk18DC;
    int unk18E0;
    int unk18E4;
    int unk18E8;
    int unk18EC;
    int unk18F0;
    int unk18F4;
    int unk18F8;
    int unk18FC;
    int unk1900;
    int unk1904;
    int unk1908;
    int unk190C;
    int unk1910;
    int unk1914;
    int unk1918;
    int unk191C;
    int unk1920;
    int unk1924;
    int unk1928;
    int unk192C;
    int unk1930;
    int unk1934;
    int unk1938;
    int unk193C;
    int unk1940;
    int unk1944;
    int unk1948;
    int unk194C;
    int unk1950;
    int unk1954;
    int unk1958;
    int unk195C;
    int unk1960;
    int unk1964;
    int unk1968;
    int unk196C;
    int unk1970;
    int unk1974;
    int unk1978;
    int unk197C;
    int unk1980;
    int unk1984;
    int unk1988;
    int unk198C;
    int unk1990;
    int unk1994;
    int unk1998;
    int unk199C;
    int unk19A0;
    int unk19A4;
    int unk19A8;
    int unk19AC;
    int unk19B0;
    int unk19B4;
    int unk19B8;
    int unk19BC;
    int unk19C0;
    int unk19C4;
    int unk19C8;
    int unk19CC;
    int unk19D0;
    int unk19D4;
    int unk19D8;
    int unk19DC;
    int unk19E0;
    int unk19E4;
    int unk19E8;
    int unk19EC;
    int unk19F0;
    int unk19F4;
    int unk19F8;
    int unk19FC;
    int unk1A00;
    int unk1A04;
    int unk1A08;
    int unk1A0C;
    int unk1A10;
    int unk1A14;
    int unk1A18;
    int unk1A1C;
    int unk1A20;
    int unk1A24;
    int unk1A28;
    int unk1A2C;
    int unk1A30;
    int unk1A34;
    int unk1A38;
    int unk1A3C;
    int unk1A40;
    int unk1A44;
    int unk1A48;
    int unk1A4C;
    int unk1A50;
    int unk1A54;
    int unk1A58;
    int unk1A5C;
    int unk1A60;
    int unk1A64;
    int unk1A68;
    int unk1A6C;
    int unk1A70;
    int unk1A74;
    int unk1A78;
    int unk1A7C;
    int unk1A80;
    int unk1A84;
    int unk1A88;
    int unk1A8C;
    int unk1A90;
    int unk1A94;
    int unk1A98;
    int unk1A9C;
    int unk1AA0;
    int unk1AA4;
    int unk1AA8;
    int unk1AAC;
    int unk1AB0;
    int unk1AB4;
    int unk1AB8;
    int unk1ABC;
    int unk1AC0;
    int unk1AC4;
    int unk1AC8;
    int unk1ACC;
    int unk1AD0;
    int unk1AD4;
    int unk1AD8;
    int unk1ADC;
    int unk1AE0;
    int unk1AE4;
    int unk1AE8;
    int unk1AEC;
    int unk1AF0;
    int unk1AF4;
    int unk1AF8;
    int unk1AFC;
    int unk1B00;
    int unk1B04;
    int unk1B08;
    int unk1B0C;
    int unk1B10;
    int unk1B14;
    int unk1B18;
    int unk1B1C;
    int unk1B20;
    int unk1B24;
    int unk1B28;
    int unk1B2C;
    int unk1B30;
    int unk1B34;
    int unk1B38;
    int unk1B3C;
    int unk1B40;
    int unk1B44;
    int unk1B48;
    int unk1B4C;
    int unk1B50;
    int unk1B54;
    int unk1B58;
    int unk1B5C;
    int unk1B60;
    int unk1B64;
    int unk1B68;
    int unk1B6C;
    int unk1B70;
    int unk1B74;
    int unk1B78;
    int unk1B7C;
    int unk1B80;
    int unk1B84;
    int unk1B88;
    int unk1B8C;
    int unk1B90;
    int unk1B94;
    int unk1B98;
    int unk1B9C;
    int unk1BA0;
    int unk1BA4;
    int unk1BA8;
    int unk1BAC;
    int unk1BB0;
    int unk1BB4;
    int unk1BB8;
    int unk1BBC;
    int unk1BC0;
    int unk1BC4;
    int unk1BC8;
    int unk1BCC;
    int unk1BD0;
    int unk1BD4;
    int unk1BD8;
    int unk1BDC;
    int unk1BE0;
    int unk1BE4;
    int unk1BE8;
    int unk1BEC;
    int unk1BF0;
    int unk1BF4;
    int unk1BF8;
    int unk1BFC;
    int unk1C00;
};

extern C790Manager* g_pkC790Manager;

// Deletes the existing g_pkC790Manager if present, then allocates a new C790Manager with pvOwner.
// @fnv 0x0086c790
void CreateC790Manager(void* pvOwner)
{
    if (g_pkC790Manager)
        delete g_pkC790Manager;
    g_pkC790Manager = new C790Manager(pvOwner);
}

namespace fnv_0086c880 {
struct FUN_0045cec0
{
    int value;
    ~FUN_0045cec0();
    void FUN_0066b0d0(int);
};
struct FUN_00aa5460
{
    int field00, field04, field08, field0c;
    ~FUN_00aa5460();
};
struct FUN_0086c6e0
{
    int field00, field04, field08, field0c, field10, field14, field18, field1c, field20, field24;
    ~FUN_0086c6e0();
    void FUN_0086cdd0();
};
struct Delete86
{
    virtual ~Delete86();
};
struct List86
{
    void FUN_0066b0d0(int);
    struct Entry86* FUN_00559450();
};
struct Entry86
{
    void FUN_00483710();
};
struct Manager86
{
    void FUN_00a22e10();
};
struct Setting86
{
    int* FUN_0043d4d0();
};
void ClearArchiveTables();
Manager86* FUN_007fdf30();
void ClearTaskQueue();
extern int DAT_011dea14, DAT_011dea18, DAT_011dea1c;
extern List86 DAT_011deb7c, DAT_011d6e5c, DAT_011deb34, DAT_011deda4, DAT_011ded58, DAT_011deb00, DAT_011ded3c,
    DAT_011dec94;
extern Delete86* DAT_011d5730[4];
extern Delete86* DAT_011d52f0[238];
extern Delete86* DAT_011d5240[9];
extern Delete86* DAT_011d51b0[8];
extern Delete86* DAT_011d51d0[28];
extern Delete86* DAT_011d5128[14];
extern Delete86* DAT_011d5160[20];
extern Delete86* DAT_011d5268[34];
extern Delete86* DAT_011d56a8[34];
extern Setting86 DAT_011c3ea4;
struct FUN_0086c880
{
    int field00, field04, field08, field0c, field10, field14;
    FUN_00aa5460 member18;
    FUN_0086c6e0 member28;
    FUN_00aa5460 member50;
    FUN_0086c6e0 member60;
    FUN_0045cec0 member88, member8c, member90, member94, member98;
    int field9c;
    FUN_0045cec0 membera0;
    ~FUN_0086c880();
};
// @fnv 0x0086c880
FUN_0086c880::~FUN_0086c880()
{
    ClearArchiveTables();
    FUN_007fdf30()->FUN_00a22e10();
    DAT_011dea14 = 0;
    DAT_011dea18 = 0;
    DAT_011dea1c = 0;
    FUN_0086cdf0();
    DAT_011deb7c.FUN_00559450()->FUN_00483710();
    DAT_011deb7c.FUN_0066b0d0(0);
    DAT_011d6e5c.FUN_0066b0d0(0);
    DAT_011deb34.FUN_0066b0d0(0);
    DAT_011deda4.FUN_0066b0d0(0);
    DAT_011ded58.FUN_0066b0d0(0);
    DAT_011deb00.FUN_0066b0d0(0);
    DAT_011ded3c.FUN_0066b0d0(0);
    DAT_011dec94.FUN_0066b0d0(0);
    DestroyMessageHandler();
    for (unsigned int i = 0; i < 4; i++)
        delete DAT_011d5730[i];
    for (unsigned int j = 0; j < 238; j++)
        delete DAT_011d52f0[j];
    for (unsigned int k = 0; k < 9; k++)
        delete DAT_011d5240[k];
    for (unsigned int l = 0; l < 8; l++)
        delete DAT_011d51b0[l];
    for (unsigned int m = 0; m < 28; m++)
        delete DAT_011d51d0[m];
    for (unsigned int n = 0; n < 14; n++)
        delete DAT_011d5128[n];
    for (unsigned int o = 0; o < 20; o++)
        delete DAT_011d5160[o];
    for (unsigned int p = 0; p < 34; p++)
        delete DAT_011d5268[p];
    for (unsigned int q = 0; q < 34; q++)
        delete DAT_011d56a8[q];
    if (*DAT_011c3ea4.FUN_0043d4d0() > 1)
    {
        member28.FUN_0086cdd0();
        member60.FUN_0086cdd0();
        ClearTaskQueue();
    }
    member88.FUN_0066b0d0(0);
    member8c.FUN_0066b0d0(0);
    member94.FUN_0066b0d0(0);
    member98.FUN_0066b0d0(0);
    membera0.FUN_0066b0d0(0);
}
}  // namespace fnv_0086c880

namespace fnv_00872e00 {
struct FUN_005d8b10
{
    virtual void vfn00();
    int unk04;
    FUN_005d8b10();
};
struct FUN_00872ea0
{
    virtual ~FUN_00872ea0();
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
    FUN_00872ea0(int a);
};
struct FUN_00633c90
{
    void* m_p;
    FUN_00633c90(int a);
    ~FUN_00633c90();
};
struct S_00872e00_Raw
{
    void* m_p;
    S_00872e00_Raw* FUN_00633c90(int a);
};
struct FUN_00872e00 : FUN_005d8b10
{
    FUN_00872ea0 m08;
    FUN_00633c90 m98;
    FUN_00633c90 m9c;
    S_00872e00_Raw ma0;
    FUN_00872e00();
    virtual ~FUN_00872e00();
};
// @fnv 0x00872e00
FUN_00872e00::FUN_00872e00() : m08(0), m98(0), m9c(0)
{
    ma0.FUN_00633c90(0);
}
}  // namespace fnv_00872e00

union Command
{
    struct
    {
        unsigned int operation;
        unsigned int first;
        unsigned int second;
    } fields;
    unsigned char payload[32];
};
struct H
{
    void __thiscall FUN_0087d160(Command*);
    void __thiscall SendCommand22(unsigned int, unsigned int);
};
// Builds a Command with operation 22 and the two arguments, then passes it to FUN_0087d160.
// @fnv 0x0087b3b0
void __thiscall H::SendCommand22(unsigned int uiFirst, unsigned int uiSecond)
{
    Command cmdRequest;
    cmdRequest.fields.operation = 22;
    cmdRequest.fields.first = uiFirst;
    cmdRequest.fields.second = uiSecond;
    FUN_0087d160(&cmdRequest);
}

namespace ActorInitialization {
struct Process
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
    Process();
};
struct Controller
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
    static void* operator new(unsigned int);
    static void operator delete(void*);
    Controller();
};
struct Package
{
    void FUN_00937090(int);
};
struct Vector
{
    float x, y, z;
};
extern Vector DAT_011f426c;
struct Setting
{
    const float* FUN_00403e20();
};
extern Setting DAT_011df810, DAT_011df828;
extern const float DAT_01012054, DAT_01017718;
float FUN_00476b70(float, float);
bool FUN_008c7aa0();
struct Actor;
struct Manager
{
    void FUN_0096e870(Actor*);
    void FUN_0096d450(Actor*, int, int, int, int);
};
extern Manager DAT_011e0e80;
struct Actor
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
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void Update();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual void v266();
    virtual void v267();
    virtual void v268();
    virtual void v269();
    virtual void v270();
    virtual void v271();
    virtual void v272();
    virtual void v273();
    virtual void v274();
    virtual void v275();
    virtual void v276();
    virtual void v277();
    virtual void v278();
    virtual void v279();
    virtual void v280();
    virtual void v281();
    virtual void v282();
    virtual void v283();
    virtual void v284();
    virtual void v285();
    virtual void v286();
    virtual void v287();
    virtual void v288();
    virtual void v289();
    virtual void v290();
    virtual void v291();
    virtual void v292();
    virtual void v293();
    virtual void v294();
    virtual void v295();
    virtual void v296();
    virtual void v297();
    virtual void v298();
    virtual void v299();
    virtual void v300();
    virtual void v301();
    virtual void v302();
    virtual void v303();
    virtual void v304();
    virtual void v305();
    virtual void v306();
    virtual void v307();
    virtual void ResetState();
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
    Process* process;
    int unk06c;
    int unk070;
    float value074;
    int unk078;
    unsigned char unk07c;
    unsigned char unk07d;
    unsigned char flag07e;
    unsigned char unk07f;
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
    Controller* controller;
    int unk0b4;
    float value0b8;
    unsigned char flag0bc;
    unsigned char unk0bd;
    unsigned char unk0be;
    unsigned char unk0bf;
    int unk0c0;
    unsigned char flag0c4;
    unsigned char unk0c5;
    unsigned char unk0c6;
    unsigned char unk0c7;
    float value0c8;
    float value0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    Package package;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    unsigned char flag0f0;
    unsigned char flag0f1;
    unsigned char unk0f2;
    unsigned char unk0f3;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    float value114;
    unsigned char flag118;
    unsigned char unk119;
    unsigned char unk11a;
    unsigned char unk11b;
    int unk11c;
    int unk120;
    unsigned char flag124;
    unsigned char flag125;
    unsigned char flag126;
    unsigned char flag127;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    unsigned char flag144;
    unsigned char flag145;
    unsigned char flag146;
    unsigned char unk147;
    int unk148;
    unsigned char flag14c;
    unsigned char flag14d;
    unsigned char unk14e;
    unsigned char unk14f;
    int unk150;
    float value154;
    float value158;
    unsigned char flag15c;
    unsigned char flag15d;
    unsigned char unk15e;
    unsigned char unk15f;
    Vector velocity;
    float value16c;
    int unk170;
    unsigned char flag174;
    unsigned char flag175;
    unsigned char unk176;
    unsigned char unk177;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    unsigned char flag18c;
    unsigned char flag18d;
    unsigned char flag18e;
    unsigned char unk18f;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    unsigned char flag1b0;
    unsigned char flag1b1;
    void FUN_0046a010(int);
    void FUN_008a08e0(int);
    void FUN_008bbdb0();
    void FUN_008bbe00();
    void FUN_008c4400();
    void FUN_0087d890(bool);
};
// Initializes the actor: allocates process and controller, optionally registers it, sets default field values, resets state and runs update/init calls.
// @fnv 0x0087d890
void Actor::FUN_0087d890(bool registerActor)
{
    FUN_0046a010(1);
    process = new Process;
    if (registerActor)
    {
        if (FUN_008c7aa0())
            DAT_011e0e80.FUN_0096e870(this);
        else
            DAT_011e0e80.FUN_0096d450(this, 3, 0, 0, 0);
    }
    value114 = DAT_01012054;
    unk120 = 0;
    unk108 = 0;
    unk10c = 0;
    flag118 = 0;
    unk0b4 = 8;
    flag0bc = 1;
    flag0c4 = 0;
    value0b8 = 0.0f;
    flag125 = 0;
    flag124 = 0;
    unk0c0 = 0;
    unk070 = 0;
    unk148 = 0;
    flag126 = 1;
    flag14c = 0;
    value158 = 0.0f;
    flag15c = 1;
    value074 = FUN_00476b70(*DAT_011df810.FUN_00403e20(), *DAT_011df828.FUN_00403e20());
    unk11c = 0;
    unk170 = 0;
    value16c = 0.0f;
    velocity = DAT_011f426c;
    value0c8 = 0.0f;
    value0cc = DAT_01017718;
    flag174 = 0;
    flag175 = 1;
    unk110 = 255;
    ResetState();
    FUN_008a08e0(0);
    flag14d = 0;
    unk0ac = 0;
    controller = new Controller;
    flag18c = 0;
    FUN_008bbdb0();
    FUN_008bbe00();
    Update();
    FUN_008c4400();
    unk150 = 0;
    value154 = 0.0f;
    flag0f1 = 0;
    package.FUN_00937090(1);
    flag145 = 0;
    flag146 = 0;
    flag07e = 0;
    flag0f0 = 0;
    unk1a4 = 0;
    unk1a8 = 0;
    flag18d = 0;
    flag127 = 0;
    unk128 = 0;
    unk12c = 0;
    unk130 = 0;
    unk1ac = 0;
    flag18e = 0;
    unk194 = 0;
    flag15d = 1;
    unk198 = 0;
    flag144 = 0;
    flag1b0 = 0;
    unk1a0 = 0;
    flag1b1 = 0;
    unk140 = 0;
    unk13c = 0;
}
}

// Allocates a new array of unsigned int with a elements and returns it as an int.
// @fnv 0x00869840
int __cdecl AllocateUIntArray(unsigned int auiCount)
{
    return (int)new unsigned int[auiCount];
}

struct SSSurfaceDesc
{
    unsigned int uiFormat;
    unsigned int uiType;
    unsigned int uiUsage;
    unsigned int uiPool;
    unsigned int uiMultiSampleType;
    unsigned int uiMultiSampleQuality;
    unsigned int uiWidth;
    unsigned int uiHeightRes;
};
struct SSLockedRect
{
    int m_cPitchAdjustment;
    unsigned char* pBits;
};

class SSSurface
{
  public:
    virtual void __stdcall v000();
    virtual void __stdcall v004();
    virtual unsigned long __stdcall Release();  // +0x08
    virtual void __stdcall v00c();
    virtual void __stdcall v010();
    virtual void __stdcall v014();
    virtual void __stdcall v018();
    virtual void __stdcall v01c();
    virtual void __stdcall v020();
    virtual void __stdcall v024();
    virtual void __stdcall v028();
    virtual void __stdcall v02c();
    virtual long __stdcall GetDesc(SSSurfaceDesc* pkDesc);  // +0x30
    virtual long __stdcall LockRect(SSLockedRect* pkRect, const void* pkArea, unsigned long uiFlags);
    virtual long __stdcall UnlockRect();  // +0x38
};

class SSDevice
{
  public:
    virtual void __stdcall v000();
    virtual void __stdcall v004();
    virtual void __stdcall v008();
    virtual void __stdcall v00c();
    virtual void __stdcall v010();
    virtual void __stdcall v014();
    virtual void __stdcall v018();
    virtual void __stdcall v01c();
    virtual void __stdcall v020();
    virtual void __stdcall v024();
    virtual void __stdcall v028();
    virtual void __stdcall v02c();
    virtual void __stdcall v030();
    virtual void __stdcall v034();
    virtual void __stdcall v038();
    virtual void __stdcall v03c();
    virtual void __stdcall v040();
    virtual void __stdcall v044();
    virtual long __stdcall GetBackBuffer(unsigned int uiSwapChain, unsigned int uiBackBuffer, int iType,
                                         SSSurface** ppkSurface);
};

struct SSFormat
{
    unsigned int unk00[17];
    SSFormat();
};

struct SSFormatSource
{
    const SSFormat& DeallocateSound();
};

class SSRenderer
{
  public:
    virtual void __stdcall v000();
    virtual void __stdcall v004();
    virtual void __stdcall v008();
    virtual void __stdcall v00c();
    virtual void __stdcall v010();
    virtual void __stdcall v014();
    virtual void __stdcall v018();
    virtual void __stdcall v01c();
    virtual void __stdcall v020();
    virtual void __stdcall v024();
    virtual void __stdcall v028();
    virtual void __stdcall v02c();
    virtual void __stdcall v030();
    virtual void __stdcall v034();
    virtual void __stdcall v038();
    virtual void __stdcall v03c();
    virtual void __stdcall v040();
    virtual void __stdcall v044();
    virtual void __stdcall v048();
    virtual void __stdcall v04c();
    virtual void __stdcall v050();
    virtual void __stdcall v054();
    virtual void __stdcall v058();
    virtual void __stdcall v05c();
    virtual void __stdcall v060();
    virtual void __stdcall v064();
    virtual void __stdcall v068();
    virtual void __stdcall v06c();
    virtual void __stdcall v070();
    virtual void __stdcall v074();
    virtual void __stdcall v078();
    virtual void __stdcall v07c();
    virtual void __stdcall v080();
    virtual void __stdcall v084();
    virtual void __stdcall v088();
    virtual void __stdcall v08c();
    virtual void __stdcall v090();
    virtual void __stdcall v094();
    virtual void __stdcall v098();
    virtual void __stdcall v09c();
    virtual void __stdcall v0a0();
    virtual void __stdcall v0a4();
    virtual void __stdcall v0a8();
    virtual void __stdcall v0ac();
    virtual void __stdcall v0b0();
    virtual void __stdcall v0b4();
    virtual void __stdcall v0b8();
    virtual void __stdcall v0bc();
    virtual void __stdcall v0c0();
    virtual void __stdcall v0c4();
    virtual void __stdcall v0c8();
    virtual void __stdcall v0cc();
    virtual void __stdcall v0d0();
    virtual SSFormatSource* GetFormatSource();  // +0xd4
    SSDevice* FUN_004dc020();
};

class SSImage
{
  public:
    SSImage(unsigned int uiWidth, unsigned int uiHeightRes, SSFormat* pkFormat, bool bA, bool bB);
    virtual ~SSImage();
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);
    unsigned int FUN_0064da80(int iA, int iB);
    unsigned int FUN_0070ec90();
    unsigned char* FUN_0064dac0(int iA, int iB);
    unsigned int unk04[28];
};

class SSFile
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    SSFile(const char* pcPath, int iMode, int iAccess, int iFlags);
    ~SSFile();
    int FUN_00559450();
    void SetAndReturnPointer(const void* pvData, unsigned __int64 uiSize, unsigned __int64* puiWritten);
};

// BITMAPFILEHEADER + BITMAPINFOHEADER as one 2-byte-aligned block; the 32-bit fields sit at odd word offsets.
struct SSBitmapHeader
{
    unsigned short usType;
    unsigned short ausFileSize[2];
    unsigned short usReserved1;
    unsigned short usReserved2;
    unsigned short ausOffBits[2];
    unsigned short ausSize[2];
    unsigned short ausWidth[2];
    unsigned short ausHeight[2];
    unsigned short usPlanes;
    unsigned short usBitCount;
    unsigned short ausCompression[2];
    unsigned short ausSizeImage[2];
    unsigned short ausXPelsPerMeter[2];
    unsigned short ausYPelsPerMeter[2];
    unsigned short ausClrUsed[2];
    unsigned short ausClrImportant[2];
};

struct SSCounter
{
    int* FUN_0043d4d0();
};
struct SSStringSetting
{
    const char* FUN_00403df0();
};
struct SSMenuState
{
    void OpenAtPosition();
};

extern SSCounter DAT_011df124;
extern SSStringSetting DAT_011df0f8;

SSRenderer* FUN_004bc3f0();
int FUN_00e7bd20(SSFormat* pkFormat);
void FUN_005b5e40(const char* pcFormat, ...);
bool FUN_004dc310();
unsigned int FUN_004dc1f0();
int FUN_004dc200();
void* FUN_00401460(void* pvDst, const void* pvSrc, unsigned int uiSize);
void* FormHeap_Allocate(unsigned int uiSize);
void FormHeap_Free(void* pvMem);
int FUN_00406d30(char* pcDst, unsigned int uiSize, const char* pcSrc);
int FUN_00406d00(char* pcBuffer, unsigned int uiSize, const char* pcFormat, ...);
int FUN_00ec623a(char* pcBuffer, const char* pcFormat, ...);
void DispatchMessageToSink(const char* pcText, int iA, const char* pcIcon, const char* pcSound, float fTime, int iB);
SSMenuState* FUN_004de490();

// Captures the back buffer, converts it to a 24-bit BMP, writes it to a file, and optionally notifies the user.
// @fnv 0x00878860
void SaveScreenshot(const char* pcPath)
{
    SSRenderer* pkRendererVal = FUN_004bc3f0();
    SSFormat kFormatRes;
    SSDevice* pkDevicePos = pkRendererVal->FUN_004dc020();
    kFormatRes = pkRendererVal->GetFormatSource()->DeallocateSound();
    int iFormatTotal = FUN_00e7bd20(&kFormatRes);
    SSSurface* pkSurfaceInfo;
    if (pkDevicePos->GetBackBuffer(0, 0, 0, &pkSurfaceInfo))
    {
        FUN_005b5e40("DEFAULT: (ScreenShot) Unable to get back buffer.");
        return;
    }
    SSSurfaceDesc kDescEntry;
    if (pkSurfaceInfo->GetDesc(&kDescEntry))
    {
        FUN_005b5e40("DEFAULT: (ScreenShot) Unable to acquire BackBuffer Description");
        pkSurfaceInfo->Release();
        return;
    }
    SSLockedRect kRectValue;
    if (pkSurfaceInfo->LockRect(&kRectValue, 0, 0x800))
    {
        if (FUN_004dc310())
            FUN_005b5e40("DEFAULT: (ScreenShot) Not enabled. Can't lock the backbuffer when multisampling is enabled.");
        else
            FUN_005b5e40(
                "DEFAULT: (ScreenShot) Not enabled. Add 'bAllowScreenShot = 1' to the [Display] section of Fallout.INI file.");
        pkSurfaceInfo->Release();
        return;
    }
    SSImage* pkImageNew = new SSImage(FUN_004dc1f0(), FUN_004dc200(), &kFormatRes, true, true);
    unsigned int uiRowSize = pkImageNew->FUN_0064da80(0, 0) * pkImageNew->FUN_0070ec90();
    unsigned char* pucDstPtr = pkImageNew->FUN_0064dac0(0, 0);
    unsigned char* pucSrc = kRectValue.pBits;
    for (int i = 0; i < FUN_004dc200(); i++)
    {
        FUN_00401460(pucDstPtr, pucSrc, uiRowSize);
        pucDstPtr += uiRowSize;
        pucSrc += kRectValue.m_cPitchAdjustment;
    }
    pkSurfaceInfo->UnlockRect();
    pkSurfaceInfo->Release();
    char acPathCur[260];
    if (pcPath)
        FUN_00406d30(acPathCur, 0x104, pcPath);
    else
        FUN_00406d00(acPathCur, 0x104, "%s%d.bmp", DAT_011df0f8.FUN_00403df0(), *DAT_011df124.FUN_0043d4d0());
    SSFile kFileLast(acPathCur, 2, 2, 0);
    if (!kFileLast.FUN_00559450())
    {
        unsigned int uiWidth = pkImageNew->FUN_0064da80(0, 0);
        unsigned int uiHeightRes = FUN_004dc200();
        unsigned int uiBytesPerPixelOld = pkImageNew->FUN_0070ec90();
        unsigned char* pucPixelsTmp = pkImageNew->FUN_0064dac0(0, 0);
        unsigned char* pucBuffer = (unsigned char*)FormHeap_Allocate(uiWidth * uiHeightRes * 3);
        unsigned int uiOutPos = 0;
        SSBitmapHeader kHeader;
        unsigned __int64 uiWritten;
        for (int y = uiHeightRes - 1; y >= 0; y--)
        {
            for (unsigned int x = 0; x < uiWidth; x++)
            {
                unsigned int uiElapsedMilliseconds = uiWidth * uiBytesPerPixelOld * y + x * uiBytesPerPixelOld;
                pucBuffer[uiOutPos] = pucPixelsTmp[uiElapsedMilliseconds];
                pucBuffer[uiOutPos + 1] = pucPixelsTmp[uiElapsedMilliseconds + 1];
                pucBuffer[uiOutPos + 2] = pucPixelsTmp[uiElapsedMilliseconds + 2];
                uiOutPos += 3;
            }
        }
        uiBytesPerPixelOld = 3;
        kHeader.usType = 0x4d42;
        *(unsigned int*)kHeader.ausFileSize = uiWidth * uiHeightRes * uiBytesPerPixelOld + 0x36;
        kHeader.usReserved1 = 0;
        kHeader.usReserved2 = 0;
        *(unsigned int*)kHeader.ausOffBits = 0x36;
        *(unsigned int*)kHeader.ausSize = 0x28;
        *(int*)kHeader.ausWidth = uiWidth;
        *(int*)kHeader.ausHeight = uiHeightRes;
        kHeader.usPlanes = 1;
        kHeader.usBitCount = uiBytesPerPixelOld * 8;
        *(unsigned int*)kHeader.ausCompression = 0;
        *(unsigned int*)kHeader.ausSizeImage = uiWidth * uiHeightRes * uiBytesPerPixelOld;
        *(int*)kHeader.ausXPelsPerMeter = 0;
        *(int*)kHeader.ausYPelsPerMeter = 0;
        *(unsigned int*)kHeader.ausClrUsed = 0;
        *(unsigned int*)kHeader.ausClrImportant = 0;
        kFileLast.SetAndReturnPointer(&kHeader, 0x36, &uiWritten);
        kFileLast.SetAndReturnPointer(pucBuffer, uiWidth * uiHeightRes * uiBytesPerPixelOld, &uiWritten);
        FormHeap_Free(pucBuffer);
        if (!pcPath)
        {
            char acMessage[260];
            FUN_00ec623a(acMessage, "ScreenShot: File '%s' created.", acPathCur);
            DispatchMessageToSink(acMessage, 0, 0, 0, 2.0f, 0);
            *DAT_011df124.FUN_0043d4d0() = *DAT_011df124.FUN_0043d4d0() + 1;
            FUN_004de490()->OpenAtPosition();
        }
    }
    else
    {
        FUN_005b5e40("DEFAULT: (ScreenShot) Unable to create file '%s'.", acPathCur);
    }
    delete pkImageNew;
}

struct FUN_00865980
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00865980();
};

struct Factory_00865900
{
    FUN_00865980* CreateInstance();
};

// Allocates and returns a new FUN_00865980 object.
// @fnv 0x00865900
FUN_00865980* Factory_00865900::CreateInstance()
{
    return new FUN_00865980;
}

struct ArraySmartRef
{
    void* pointer;
    ArraySmartRef(void*);
    ~ArraySmartRef();
    bool IsNotEqual(const ArraySmartRef&) const;
    bool FUN_004b0460(const ArraySmartRef&) const;
    ArraySmartRef& FUN_006e5cc0(const ArraySmartRef&);
};
struct RefArrayOwner
{
    int unk00;
    ArraySmartRef* entries;
    unsigned short capacity, size, used;
    void FUN_00869870(unsigned int, const ArraySmartRef&);
};
// Stores value at index, growing size if needed and adjusting used when the empty state of the slot changes.
// @fnv 0x00869870
void RefArrayOwner::FUN_00869870(unsigned int index, const ArraySmartRef& value)
{
    static ArraySmartRef empty(0);
    if (index >= size)
    {
        size = (unsigned short)(index + 1);
        if (value.IsNotEqual(empty))
            used++;
    }
    else
    {
        if (value.IsNotEqual(empty))
        {
            if (entries[index].FUN_004b0460(empty))
                used++;
        }
        else
        {
            if (entries[index].IsNotEqual(empty))
                used--;
        }
    }
    entries[index].FUN_006e5cc0(value);
}

namespace fnv_0086a0a0 {
#include <windows.h>

struct Inner
{
    void C();
};
struct Obj
{
    void A(int a);
    Inner* B(int a);
    Inner* B0();
    bool D();
    bool E();
    void F();
    int G(int a, int b);
    bool H(unsigned a, unsigned b);
};
struct Obj2
{
    int X();
};
extern Obj* DAT_011dea0c;
extern Obj2 DAT_011deb30;
extern char DAT_011deef4;
extern unsigned char DAT_011a3014;
bool FUN_0070ec00();
int __cdecl FUN_00a09030(int);
void __cdecl FUN_00709470(int, int, int, int, int, int);
int FUN_004bc3f0();
void __cdecl FUN_004dc6e0(int, int);
bool FUN_00446e10();
int FUN_004dc1e0();
void FUN_004b7210();
bool FUN_004b71d0();

// Handles window messages including activation, cursor visibility, and input by dispatching to DAT_011dea0c and returning DefWindowProcA results.
// @fnv 0x0086a0a0
LRESULT CALLBACK FUN_0086a0a0(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case 0x281:
        lParam = 0;
        return DefWindowProcA(hWnd, msg, wParam, lParam);
        break;
    case 6:
        switch ((WORD)(wParam & 0xffff))
        {
        case 1:
        case 2:
            if ((WORD)((wParam >> 16) & 0xffff) == 0)
            {
                if (DAT_011dea0c)
                {
                    DAT_011dea0c->A(1);
                    DAT_011dea0c->B(0)->C();
                }
            }
            break;
        case 0:
            if (DAT_011dea0c)
            {
                if (DAT_011dea0c->D())
                {
                    if (DAT_011dea0c->E())
                    {
                        if (!FUN_0070ec00())
                        {
                            if (!FUN_00a09030(0x3f5))
                            {
                                if (!FUN_00a09030(0x3ef))
                                {
                                    FUN_00709470(6, 0, 0, 0, 1, 0);
                                }
                            }
                        }
                    }
                    if (DAT_011dea0c)
                    {
                        if (!DAT_011deb30.X())
                        {
                            DAT_011dea0c->A(0);
                        }
                    }
                }
            }
            break;
        }
        return 0;
    case 0x86:
        if (wParam == 0)
            DAT_011deef4 = 1;
        break;
    case 0x84: {
        LRESULT r = DefWindowProcA(hWnd, msg, wParam, lParam);
        if (DAT_011dea0c)
        {
            if (DAT_011dea0c->B0())
            {
                if (r != 1)
                {
                    if (!DAT_011a3014)
                    {
                        ShowCursor(1);
                        DAT_011a3014 = 1;
                    }
                }
                else if (DAT_011a3014)
                {
                    while (ShowCursor(0) > 0)
                    {
                    }
                    DAT_011a3014 = 0;
                }
            }
        }
        return r;
        break;
    }
    case 0x200:
        if (DAT_011dea0c->H((WORD)(lParam & 0xffff), (WORD)(((unsigned)lParam >> 16) & 0xffff)))
            return 0;
        break;
    case 5:
        return 0;
        break;
    case 0x47:
        if (FUN_004bc3f0())
        {
            int* p = (int*)lParam;
            FUN_004dc6e0(p[2], p[3]);
        }
        else if (!FUN_00446e10())
        {
            return 0;
        }
        break;
    case 0x105:
        return 0;
    case 2:
        if (DAT_011dea0c)
            DAT_011dea0c->F();
        break;
    case 0x14:
        if (FUN_004dc1e0() == (int)hWnd)
            return 1;
        break;
    case 0x112:
        FUN_004b7210();
        if (FUN_004b71d0())
        {
            switch ((WORD)(wParam & 0xffff))
            {
            case 0xf140:
            case 0xf170:
                return 1;
            }
        }
        break;
    }
    return DefWindowProcA(hWnd, msg, wParam, lParam);
}
}  // namespace fnv_0086a0a0

namespace fnv_0087dcb0 {
extern void* DAT_011dea3c;
extern int DAT_011e0e80;
extern int DAT_011f11e0;
extern void* DAT_011c3f2c;

void __cdecl FUN_00835980(void*);
void __cdecl FUN_0066e100(void*);
void* __cdecl FUN_00b4f5c0();

struct H
{
    void FUN_0041a250();
    void* FUN_005d43c0(void*);
    void FUN_00418890();
    unsigned char FUN_00ad8ce0();
    void FUN_00ad8d10();
    unsigned char FUN_004077c0();
    void FUN_0093a660(void*);
    void FUN_00967350(void*);
    void RemoveActor(void*);
    void FUN_0087fd20();
    void FUN_00906050(void*);
    void FUN_00978660(void*);
    unsigned char FUN_004226e0();
    void FUN_00824970();
    void FUN_0092ed60(int);
    void FUN_00881680(int);
    void FUN_00976680(void*);
    void FUN_0096f600(void*, int);
    void FUN_00975320(void*);
    void FUN_0096f400(void*);
    void FUN_008a06c0(int);
    void DeleteAllItems();
    void FUN_009370b0();
    void FUN_008b3180();
    void Set3D(int, int);
    void FUN_00483710();
    void FUN_0046ffb0();
    void FUN_00937030();
    void FUN_00822a80();
    void FUN_008153b0();
    void FUN_0092ec40();
    void* FUN_0084e3a0();
    void RemoveEntry(void*);
    int FUN_0045cd60();
    void FUN_008c30a0();
    void DispelSummonEffects();
};

struct VObj
{
    virtual ~VObj();
};

struct Temp
{
    void* unk00;
    void* unk04;
    void* unk08;
    Temp();
    ~Temp();
};

struct A0
{
    virtual void a0();
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
};
struct A18
{
    virtual void a18();
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5C;
    void* unk60;
    void* unk64;
    void* m_68;
    void* unk6C;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7C;
    void* unk80;
    void* unk84;
};
struct Base0 : A0, A18
{
    ~Base0();
};
struct B88
{
    virtual void b88();
    void* unk04;
    void* unk08;
    ~B88();
};
struct X94
{
    virtual void x94();
    void* unk04;
    void* unk08;
    void* unk0C;
};
struct Y94
{
    virtual void y94();
};
struct Z94
{
    virtual void z94();
};
struct B94 : X94, Y94, Z94
{
    ~B94();
    void FUN_00824970();
};
struct M_d0
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    ~M_d0();
    void FUN_009370b0();
};
struct M_e0
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    ~M_e0();
    void FUN_009370b0();
};
struct M_f4
{
    void* unk00;
    void* unk04;
    ~M_f4();
};
struct M_fc
{
    void* unk00;
    void* unk04;
    ~M_fc();
};

struct FUN_0087dcb0 : Base0, B88, B94
{
    VObj* m_ac;
    VObj* m_b0;
    void* unkB4;
    void* unkB8;
    void* unkBC;
    void* unkC0;
    void* unkC4;
    void* unkC8;
    void* unkCC;
    M_d0 m_d0;
    M_e0 m_e0;
    M_f4 m_f4;
    M_fc m_fc;
    unsigned char m_104;
    unsigned char unk105;
    unsigned char unk106;
    unsigned char unk107;
    void* unk108;
    void* unk10C;
    void* unk110;
    void* unk114;
    void* unk118;
    void* unk11C;
    void* unk120;
    void* unk124;
    void* unk128;
    VObj* m_12c;
    VObj* m_130;

    ~FUN_0087dcb0();
};

// Deletes m_ac, m_b0, m_12c and m_130, then unless FUN_004077c0 is true runs a series of cleanup calls on this and global objects.
// @fnv 0x0087dcb0
FUN_0087dcb0::~FUN_0087dcb0()
{
    delete m_ac;
    if (m_b0)
        delete m_b0;

    {
        Temp temp;
        ((H*)((H*)this)->FUN_005d43c0(&temp))->FUN_00418890();
        if (((H*)&temp)->FUN_00ad8ce0())
        {
            ((H*)&temp)->FUN_00ad8d10();
        }
        FUN_00835980(this);

        delete m_12c;
        delete m_130;

        if (!((H*)this)->FUN_004077c0())
        {
            ((H*)DAT_011dea3c)->FUN_0093a660(this);
            ((H*)DAT_011dea3c)->FUN_00967350(this);
            ((H*)&DAT_011e0e80)->RemoveActor(this);
            ((H*)this)->FUN_0087fd20();
            ((H*)&DAT_011f11e0)->FUN_00906050(this);
            ((H*)&DAT_011e0e80)->FUN_00978660(this);
            if (!((H*)DAT_011c3f2c)->FUN_004226e0())
            {
                B94::FUN_00824970();
                FUN_0066e100(this);
                ((H*)this)->FUN_0092ed60(1);
                ((H*)this)->FUN_00881680(0);
                ((H*)&DAT_011e0e80)->FUN_00976680(this);
                ((H*)&DAT_011e0e80)->FUN_0096f600(this, 1);
                ((H*)&DAT_011e0e80)->FUN_00975320(this);
                if (m_68)
                {
                    if (((H*)m_68)->FUN_0045cd60() == 1 || ((H*)m_68)->FUN_0045cd60() == 0)
                    {
                        void* p = FUN_00b4f5c0();
                        if (p)
                        {
                            ((H*)p)->RemoveEntry(((H*)this)->FUN_0084e3a0());
                        }
                        ((H*)this)->FUN_008c30a0();
                    }
                    ((H*)this)->DispelSummonEffects();
                }
            }
            ((H*)&DAT_011e0e80)->FUN_0096f400(this);
            if (m_104)
            {
                ((H*)this)->FUN_008a06c0(0);
            }
            ((H*)this)->DeleteAllItems();
            m_d0.FUN_009370b0();
            m_e0.FUN_009370b0();
            ((H*)this)->FUN_008b3180();
            ((H*)this)->Set3D(0, 0);
        }
    }
}
}  // namespace fnv_0087dcb0

namespace InstalledPathDetail {
extern "C" __declspec(dllimport) long __stdcall RegOpenKeyExA(void* key, const char* subKey, unsigned long options,
                                                              unsigned long access, void** result);
extern "C" __declspec(dllimport) long __stdcall RegQueryValueExA(void* key, const char* value, unsigned long* reserved,
                                                                 unsigned long* type, unsigned char* data,
                                                                 unsigned long* size);
extern "C" __declspec(dllimport) long __stdcall RegCloseKey(void* key);
}

// Opens the FalloutNV registry key and queries the Installed Path value into pBuffer, closing the key afterwards.
// @fnv 0x00876a70
void FUN_00876a70(char* pBuffer, unsigned long cbBuffer)
{
    void* hKey;
    const char* subKey = "Software\\Bethesda Softworks\\FalloutNV";
    unsigned long cbData = cbBuffer;
    if (InstalledPathDetail::RegOpenKeyExA((void*)(long)0x80000002, subKey, 0, 1, &hKey) == 0)
    {
        InstalledPathDetail::RegQueryValueExA(hKey, "Installed Path", 0, 0, (unsigned char*)pBuffer, &cbData);
    }
    InstalledPathDetail::RegCloseKey(hKey);
}
