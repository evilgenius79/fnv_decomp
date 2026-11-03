
// src/staging/blk_00980000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

struct FUN_00993d60
{
    FUN_00993d60* Init(int arg);
};

// @fnv 0x00993d60
FUN_00993d60* FUN_00993d60::Init(int arg)
{
    *((int*)this + 0x00) = 0;
    *((int*)this + 0x01) = 0;
    *((int*)this + 0x02) = 0;
    *((int*)this + 0x03) = 0;
    *((int*)this + 0x04) = 0xffffffff;
    *((int*)this + 0x05) = arg;
    return this;
}

struct GlobalObject_00869f00
{
    void Clear(bool);
};
extern void* DAT_0108cff4;

struct FUN_00982460
{
    void* m_p;
    void Init();
};

// @fnv 0x00982460
void FUN_00982460::Init()
{
    m_p = &DAT_0108cff4;
    ((GlobalObject_00869f00*)this)->Clear(true);
}

// Returns the smaller of the two unsigned byte arguments.
// @fnv 0x00982b20
unsigned char MinByte(unsigned char a, unsigned char b)
{
    unsigned char result;
    if (a < b)
        result = a;
    else
        result = b;
    return result;
}

struct FUN_00982b90_class
{
    int __thiscall ComputeBitMask();
};

// Builds a mask from the byte at offset 2 (bit count) shifted by the byte at offset 3.
// @fnv 0x00982b90
int __thiscall FUN_00982b90_class::ComputeBitMask()
{
    return ((2 << ((*reinterpret_cast<unsigned char*>(this + 2)) - 1)) - 1)
           << *reinterpret_cast<unsigned char*>(this + 3);
}

struct FUN_00982bc0_Class
{
    char m_000;
    char m_001;
    char m_002;
    char m_003;
    char m_004;
    char m_005;
    char m_006;
    char m_007;
    char m_008;
    char m_009;
    char m_00a;
    char m_00b;
    char m_00c;
    char m_00d;
    char m_00e;
    char m_00f;
    char m_010;
    char m_011;
    char m_012;
    char m_013;
    char m_014;
    char m_015;
    char GetByte15();
};

// @fnv 0x00982bc0
char FUN_00982bc0_Class::GetByte15()
{
    return m_015;
}

struct FUN_00982f10
{
    void Set(const char* src);
};

// Copies the first two characters of src into the bytes at offsets 0x14 and 0x15 of this object.
// @fnv 0x00982f10
void FUN_00982f10::Set(const char* src)
{
    *(char*)((char*)this + 0x14) = src[0];
    *(char*)((char*)this + 0x15) = src[1];
}

extern int DAT_0108d104;

struct FUN_00983670
{
    void* m_p;
    void __thiscall FUN_009837b0(int);
    void* __thiscall Init(int arg);
};

// Calls FUN_009837b0 with arg, sets m_p to the address of DAT_0108d104, and returns this.
// @fnv 0x00983670
void* __thiscall FUN_00983670::Init(int arg)
{
    this->FUN_009837b0(arg);
    m_p = &DAT_0108d104;
    return this;
}

extern int DAT_0108d124;

struct FUN_006dc440_class
{
    void FUN_006dc440(int, int);
};

struct FUN_009836d0_class
{
    int* vtable;
    FUN_009836d0_class* FUN_009836d0();
};

// Sets the vtable pointer to DAT_0108d124, calls FUN_006dc440 with 0 and 0, and returns this.
// @fnv 0x009836d0
FUN_009836d0_class* FUN_009836d0_class::FUN_009836d0()
{
    vtable = &DAT_0108d124;
    reinterpret_cast<FUN_006dc440_class*>(this)->FUN_006dc440(0, 0);
    return this;
}

namespace fnv_00983700 {
extern int DAT_0108d124;
struct GlobalObject_00869f00
{
    void Clear(bool);
    void __thiscall FUN_00983700();
};
// @fnv 0x00983700
void __thiscall GlobalObject_00869f00::FUN_00983700()
{
    *reinterpret_cast<int**>(this) = &DAT_0108d124;
    this->Clear(true);
}
}  // namespace fnv_00983700

void* __cdecl operator new(unsigned int);
extern void* DAT_011f1708;

// If DAT_011f1708 is null, allocates one byte with operator new and stores the pointer in DAT_011f1708.
// @fnv 0x00983910
void __fastcall EnsureGlobalAllocated(void)
{
    if (DAT_011f1708)
        return;
    void* p = operator new(1);
    DAT_011f1708 = p;
}

extern "C" void __cdecl Deallocate(void*);
extern void* DAT_011f1708;

// Deallocates the pointer stored in DAT_011f1708 and sets it to null.
// @fnv 0x00983940
void __cdecl FreeGlobalPointer()
{
    void* ptr = DAT_011f1708;
    Deallocate(ptr);
    DAT_011f1708 = 0;
}

struct FUN_00984270_Class
{
    unsigned char GetByteAt608();
};

// @fnv 0x00984270
unsigned char FUN_00984270_Class::GetByteAt608()
{
    return reinterpret_cast<unsigned char*>(this)[0x608];
}

typedef unsigned int(__cdecl* FUN_009a3830_t)(const int*, const int*);
extern unsigned int FUN_009a3830(const int*, const int*);
struct LS3de0
{
    unsigned int Find(unsigned int*&, unsigned int, FUN_009a3830_t);
};
struct FUN_0098de30_class
{
    unsigned int FUN_0098de30(unsigned int*);
};
// Calls Find on the LS3de0 sub-object at offset 0x138 with out, 0 and FUN_009a3830, returning its result.
// @fnv 0x0098de30
unsigned int FUN_0098de30_class::FUN_0098de30(unsigned int* out)
{
    return ((LS3de0*)((char*)this + 0x138))->Find(out, 0, FUN_009a3830);
}

void* __cdecl Reallocate(void* p, int n);

struct FUN_0098f280_Class
{
    void* __thiscall FUN_0098f280(void* a, int b);
};

// @fnv 0x0098f280
void* __thiscall FUN_0098f280_Class::FUN_0098f280(void* a, int b)
{
    return Reallocate(a, b * 20);
}

extern "C" void DAT_0108d71c();
struct FUN_0098f2a0
{
    void* vtbl;
    void FUN_0098fd10(int, int);
    FUN_0098f2a0* Init();
};
// Sets the object's vtbl to DAT_0108d71c, calls FUN_0098fd10 with 0 and 0, and returns this.
// @fnv 0x0098f2a0
FUN_0098f2a0* FUN_0098f2a0::Init()
{
    vtbl = &DAT_0108d71c;
    FUN_0098fd10(0, 0);
    return this;
}

namespace fnv_0098f2d0 {
extern int DAT_0108d71c;
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct FUN_0098f2d0 : GlobalObject_00869f00
{
    void Init();
};
// @fnv 0x0098f2d0
void FUN_0098f2d0::Init()
{
    *(int*)this = (int)&DAT_0108d71c;
    Clear(true);
}
}  // namespace fnv_0098f2d0

extern "C" void* DAT_0108d730;

struct Dummy_0061bf20
{
    void FUN_006b3f40(int, int);
};

struct FUN_0098f4c0 : Dummy_0061bf20
{
    FUN_0098f4c0* Init();
};

// @fnv 0x0098f4c0
FUN_0098f4c0* FUN_0098f4c0::Init()
{
    *(void**)this = &DAT_0108d730;
    FUN_006b3f40(0, 0);
    return this;
}

namespace fnv_0098f4f0 {
extern int DAT_0108d730;
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct FUN_0098f4f0_class
{
    void FUN_0098f4f0();
};
// @fnv 0x0098f4f0
void FUN_0098f4f0_class::FUN_0098f4f0()
{
    *(int*)this = (int)&DAT_0108d730;
    ((GlobalObject_00869f00*)this)->Clear(true);
}
}  // namespace fnv_0098f4f0

extern int DAT_0108d744;

struct AX
{
    void FUN_006b3eb0(unsigned int a, unsigned int b);
};

struct FUN_0098f510 : AX
{
    AX* Set();
};

// @fnv 0x0098f510
AX* FUN_0098f510::Set()
{
    *reinterpret_cast<int*>(this) = reinterpret_cast<int>(&DAT_0108d744);
    this->FUN_006b3eb0(0, 0);
    return this;
}

namespace fnv_0098f540 {
extern int DAT_0108d744;

struct GlobalObject_00869f00
{
    void Clear(bool clear);
};

void GlobalObject_00869f00::Clear(bool clear)
{}

struct FUN_0098f540
{
    void Init();
};

// @fnv 0x0098f540
void FUN_0098f540::Init()
{
    *(int*)this = (int)&DAT_0108d744;
    ((GlobalObject_00869f00*)this)->Clear(true);
}
}  // namespace fnv_0098f540

namespace fnv_0098f560 {
extern int DAT_0108d758;

struct GlobalObject_00869f00
{
    void Clear(bool);
};

struct FUN_0098f560_Class
{
    int* p;
    void FUN_0098f560();
};

// @fnv 0x0098f560
void FUN_0098f560_Class::FUN_0098f560()
{
    p = &DAT_0108d758;
    reinterpret_cast<GlobalObject_00869f00*>(this)->Clear(true);
}
}  // namespace fnv_0098f560

struct Inner097
{
    void FUN_0097ede0();
};
struct CombatTargetTimestamp;
CombatTargetTimestamp* __fastcall FUN_004300a0(CombatTargetTimestamp*);
struct FUN_0098fda0_Class
{
    Inner097* __thiscall FUN_0098fda0();
};
// Calls FUN_0097ede0 on this, then FUN_004300a0 on the object at this+0x10, and returns this.
// @fnv 0x0098fda0
Inner097* __thiscall FUN_0098fda0_Class::FUN_0098fda0()
{
    ((Inner097*)this)->FUN_0097ede0();
    FUN_004300a0((CombatTargetTimestamp*)((char*)this + 0x10));
    return (Inner097*)this;
}

extern int DAT_0108d93c;
void __cdecl FUN_0098ffb0(void* self, int arg);
struct FUN_0098ff80_class
{
    int* vfn;
    void __thiscall FUN_0098ffb0(int arg);
    int* __thiscall FUN_0098ff80(int arg);
};
// @fnv 0x0098ff80
int* __thiscall FUN_0098ff80_class::FUN_0098ff80(int arg)
{
    FUN_0098ffb0(arg);
    *reinterpret_cast<int**>(this) = &DAT_0108d93c;
    return reinterpret_cast<int*>(this);
}

extern "C" void* DAT_0108d94c;

struct FUN_0098ffb0
{
    void* mVtbl;
    int mFlag;
    FUN_0098ffb0(int flag);
};

// Sets the vtable pointer to DAT_0108d94c and stores flag in mFlag.
// @fnv 0x0098ffb0
FUN_0098ffb0::FUN_0098ffb0(int flag)
{
    mVtbl = &DAT_0108d94c;
    mFlag = flag;
}

extern int DAT_0108d95c;
struct FUN_0098ffe0_class
{
    int* m_p;
    void FUN_0098ffb0(int arg);
    FUN_0098ffe0_class* FUN_0098ffe0(int arg);
};
// Calls FUN_0098ffb0 with arg, sets m_p to the address of DAT_0108d95c, and returns this.
// @fnv 0x0098ffe0
FUN_0098ffe0_class* FUN_0098ffe0_class::FUN_0098ffe0(int arg)
{
    FUN_0098ffb0(arg);
    m_p = &DAT_0108d95c;
    return this;
}

extern int DAT_0108d96c;

struct FUN_00990010_class
{
    int* vfn;
    void __thiscall FUN_0098ffb0(int arg);
    FUN_00990010_class(int arg);
};

// Calls FUN_0098ffb0 with arg, then sets the vfn field to point at DAT_0108d96c.
// @fnv 0x00990010
FUN_00990010_class::FUN_00990010_class(int arg)
{
    FUN_0098ffb0(arg);
    vfn = &DAT_0108d96c;
}

struct FUN_009905a0_shell
{
    void UpdateMinProgress();
};

struct FUN_00990540_shell
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int __thiscall FUN_00990540();
};

// @fnv 0x00990540
int __thiscall FUN_00990540_shell::FUN_00990540()
{
    if (m_0c == 0x7fffffff)
        reinterpret_cast<FUN_009905a0_shell*>(this)->UpdateMinProgress();
    return m_0c;
}

namespace fnv_00990ef0 {
extern int DAT_0108d758;

struct FUN_006dc440_class
{
    void FUN_006dc440(int a, int b);
};

struct FUN_00990ef0_class
{
    void* vtable;
    FUN_00990ef0_class* InitializeVtable();
};

// Sets the vtable pointer to DAT_0108d758, calls FUN_006dc440 with 0, 0, and returns this.
// @fnv 0x00990ef0
FUN_00990ef0_class* FUN_00990ef0_class::InitializeVtable()
{
    vtable = &DAT_0108d758;
    reinterpret_cast<FUN_006dc440_class*>(this)->FUN_006dc440(0, 0);
    return this;
}
}  // namespace fnv_00990ef0

struct FUN_00991130_class
{
    void __thiscall FUN_00993880();
    void __thiscall FUN_00991130();
};

// @fnv 0x00991130
void __thiscall FUN_00991130_class::FUN_00991130()
{
    FUN_00993880();
}

extern float DAT_011f1bf0;

// @fnv 0x009915e0
void FUN_009915e0(float afDelta)
{
    DAT_011f1bf0 += afDelta;
}

struct CombatThreatMap
{
    void __thiscall InitThreatObjects();
    void __thiscall ClearAndDestroy(int);
    void __thiscall FUN_00993800(int);
};

// @fnv 0x00993800
void __thiscall CombatThreatMap::FUN_00993800(int)
{
    ClearAndDestroy(1);
    InitThreatObjects();
}

extern int DAT_0108db2c;

struct FUN_00993820_class
{
    int m_vfn;
    void FUN_00993990(int arg);
    FUN_00993820_class* FUN_00993820(int arg);
};

// Calls FUN_00993990 with arg, sets m_vfn to the address of DAT_0108db2c, and returns this.
// @fnv 0x00993820
FUN_00993820_class* FUN_00993820_class::FUN_00993820(int arg)
{
    FUN_00993990(arg);
    m_vfn = (int)&DAT_0108db2c;
    return this;
}

extern int DAT_0108db54;
struct FUN_00993960
{
    int* vtbl;
    void __thiscall FUN_00993cf0(int, int);
    FUN_00993960* __thiscall Init(int a, int b);
};
// Calls FUN_00993cf0 with the two arguments, sets vtbl to DAT_0108db54, and returns this.
// @fnv 0x00993960
FUN_00993960* __thiscall FUN_00993960::Init(int a, int b)
{
    FUN_00993cf0(a, b);
    vtbl = &DAT_0108db54;
    return this;
}

struct FUN_00993bf0_class
{
    void __thiscall FUN_00993cd0();
    void __thiscall FUN_00993bf0();
};

// @fnv 0x00993bf0
void __thiscall FUN_00993bf0_class::FUN_00993bf0()
{
    reinterpret_cast<FUN_00993bf0_class*>(reinterpret_cast<char*>(this) + 0xc)->FUN_00993cd0();
}

void* __cdecl operator new(unsigned int);

struct FUN_00993cd0
{
    void* GetPtr();
};

// @fnv 0x00993cd0
void* FUN_00993cd0::GetPtr()
{
    void* p = operator new(0x10);
    return p;
}

struct FUN_009948b0
{
    int** m_p;
    int GetItem(int index);
};

// @fnv 0x009948b0
int FUN_009948b0::GetItem(int index)
{
    return *m_p[index];
}

struct FUN_00aa62e0_shell
{
    void FUN_00aa62e0();
};

struct FUN_00995890_shell
{
    void FUN_00995890();
};

// @fnv 0x00995890
void FUN_00995890_shell::FUN_00995890()
{
    ((FUN_00aa62e0_shell*)((char*)this + 0x14))->FUN_00aa62e0();
}

struct QuantityData
{
    void SetQuantity(unsigned int);
};
struct FUN_009959c0Class
{
    void FUN_009959c0(int a, int b);
};
// Stores b into the int array at offset 0x60 indexed by a, then calls SetQuantity(a) on the object pointed to by the second pointer field.
// @fnv 0x009959c0
void FUN_009959c0Class::FUN_009959c0(int iIndex, int iValue)
{
    reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x60)[iIndex] = iValue;
    reinterpret_cast<QuantityData*>(*(reinterpret_cast<int**>(this) + 1))->SetQuantity(iIndex);
}

struct FUN_00995db0_Class
{
    void* GetOffset205C();
};

// @fnv 0x00995db0
void* FUN_00995db0_Class::GetOffset205C()
{
    return reinterpret_cast<char*>(this) + 0x205C;
}

struct FUN_009962d0_class
{
    unsigned int* GetFieldAt2050();
};

// @fnv 0x009962d0
unsigned int* FUN_009962d0_class::GetFieldAt2050()
{
    return *reinterpret_cast<unsigned int**>(reinterpret_cast<unsigned char*>(this) + 0x2050);
}

namespace fnv_00996540 {
struct GlobalObject_00869f00
{
    void Clear(bool);
};

extern int DAT_0108dc80;

struct FUN_00996540
{
    void Init();
};

// @fnv 0x00996540
void FUN_00996540::Init()
{
    *reinterpret_cast<int**>(this) = &DAT_0108dc80;
    reinterpret_cast<GlobalObject_00869f00*>(this)->Clear(true);
}
}  // namespace fnv_00996540

namespace fnv_00996640 {
struct GlobalObject_00869f00
{
    void Clear(bool);
};
extern int DAT_0108dca8;
struct FUN_00996640
{
    void* p;
    void Init();
};
// @fnv 0x00996640
void FUN_00996640::Init()
{
    p = &DAT_0108dca8;
    ((GlobalObject_00869f00*)this)->Clear(true);
}
}  // namespace fnv_00996640

namespace fnv_009966c0 {
extern int DAT_0108dcbc;

struct AX
{
    void FUN_006b3eb0(unsigned int a, unsigned int b);
    AX* FUN_009966c0(unsigned int a, unsigned int b);
};

// @fnv 0x009966c0
AX* AX::FUN_009966c0(unsigned int a, unsigned int b)
{
    *reinterpret_cast<int**>(this) = &DAT_0108dcbc;
    FUN_006b3eb0(a, b);
    return this;
}
}  // namespace fnv_009966c0

namespace fnv_009966f0 {
extern int DAT_0108dcbc;

struct GlobalObject_00869f00
{
    void Clear(bool b);
};

struct FUN_009966f0_Class
{
    void* m_p;
    void FUN_009966f0();
};

// @fnv 0x009966f0
void FUN_009966f0_Class::FUN_009966f0()
{
    m_p = &DAT_0108dcbc;
    ((GlobalObject_00869f00*)this)->Clear(true);
}
}  // namespace fnv_009966f0

extern int DAT_0108dc80;

struct FUN_00996ba0
{
    int vtable;
    void __thiscall FUN_006b3eb0(unsigned int, unsigned int);
    FUN_00996ba0* __thiscall DeserializeFromFile();
};

// Sets the vtable to DAT_0108dc80, calls FUN_006b3eb0 with 0, 0, and returns this.
// @fnv 0x00996ba0
FUN_00996ba0* __thiscall FUN_00996ba0::DeserializeFromFile()
{
    vtable = (int)&DAT_0108dc80;
    FUN_006b3eb0(0, 0);
    return this;
}

namespace fnv_00996bd0 {
extern "C" void* DAT_0108dca8;
struct AX
{
    void FUN_006b3eb0(unsigned int, unsigned int);
};
struct FUN_00996bd0_class : public AX
{
    AX* FUN_00996bd0();
};
// Sets the object's vtable pointer to DAT_0108dca8, calls FUN_006b3eb0 with 0 and 0, and returns this.
// @fnv 0x00996bd0
AX* FUN_00996bd0_class::FUN_00996bd0()
{
    *reinterpret_cast<void**>(this) = &DAT_0108dca8;
    this->FUN_006b3eb0(0, 0);
    return this;
}
}  // namespace fnv_00996bd0

namespace fnv_00996db0 {
extern int DAT_0108dcbc;

struct AX
{
    void FUN_006b3eb0(unsigned int, unsigned int);
};

struct FUN_00996db0 : public AX
{
    FUN_00996db0* Init();
};

// Sets the object's vtable pointer to DAT_0108dcbc, calls FUN_006b3eb0 with 0, 0, and returns this.
// @fnv 0x00996db0
FUN_00996db0* FUN_00996db0::Init()
{
    *reinterpret_cast<int**>(this) = &DAT_0108dcbc;
    FUN_006b3eb0(0, 0);
    return this;
}
}  // namespace fnv_00996db0

struct NiPoint3
{
    float x, y, z;
};
struct FUN_0099e010_Class
{
    void FUN_0099e010(const NiPoint3& akPoint);
};
// Stores akPoint into the NiPoint3 located at offset 0xe0 of this object.
// @fnv 0x0099e010
void FUN_0099e010_Class::FUN_0099e010(const NiPoint3& akPoint)
{
    *reinterpret_cast<NiPoint3*>(reinterpret_cast<char*>(this) + 0xe0) = akPoint;
}

extern "C" void __cdecl NiFreeAlias(void*);
extern int DAT_0108d138;
struct NiTPointerMap_00983880
{
    int* vtbl;
    int m_04;
    void* m_08;
    void __thiscall FUN_00983880();
};
// Sets the vtable pointer, removes all entries from the map, and frees the m_08 buffer.
// @fnv 0x00983880
void __thiscall NiTPointerMap_00983880::FUN_00983880()
{
    *(int**)this = &DAT_0108d138;
    ((NiTPointerMap<int, int>*)this)->RemoveAll();
    NiFreeAlias(m_08);
}

struct CombatSearchDoor;
struct FUN_0098c590_shell
{
    CombatSearchDoor* FindParentSpaceNode(int);
};
struct FUN_0098c6e0_class
{
    void FUN_0098c6e0(int);
};
// @fnv 0x0098c6e0
void FUN_0098c6e0_class::FUN_0098c6e0(int arg)
{
    CombatSearchDoor* result = ((FUN_0098c590_shell*)this)->FindParentSpaceNode(arg);
    if (result)
        ((char*)result)[9] = 1;
}

namespace fnv_0098c750 {
struct CombatSearchDoor;
struct FUN_0098c590_shell
{
    CombatSearchDoor* FindParentSpaceNode(int);
};
struct FUN_0098c750_class
{
    void FUN_0098c750(int arg);
};
// @fnv 0x0098c750
void __thiscall FUN_0098c750_class::FUN_0098c750(int arg)
{
    CombatSearchDoor* p = ((FUN_0098c590_shell*)this)->FindParentSpaceNode(arg);
    if (p)
        ((char*)p)[0xa] = 1;
}
}  // namespace fnv_0098c750

void __cdecl Deallocate(void*);
struct FUN_00982530_class
{
    void __thiscall FUN_00982530();
};
struct FUN_009825e0_class
{
    void __thiscall FUN_00982530();
    FUN_009825e0_class* __thiscall FUN_009825e0(unsigned int flags);
};
// Calls FUN_00982530, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x009825e0
FUN_009825e0_class* FUN_009825e0_class::FUN_009825e0(unsigned int flags)
{
    FUN_00982530();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern double DAT_01016ff0;
struct InventoryStackRecord
{
    static float __cdecl GetConditionPercent(float);
};
struct FUN_00982750_Class
{
    unsigned char FUN_00982750(float a);
};
// @fnv 0x00982750
unsigned char FUN_00982750_Class::FUN_00982750(float afValue)
{
    afValue *= DAT_01016ff0;
    if (*reinterpret_cast<unsigned char*>(this) > afValue)
        return 1;
    unsigned char r =
        (unsigned char)(int)InventoryStackRecord::GetConditionPercent(afValue / (float)*reinterpret_cast<unsigned char*>(this));
    return r;
}

struct BGSSaveFormBuffer
{
    void __thiscall SaveData(void* p, int a, int b);
};
struct FUN_00982c20
{
    void Save(BGSSaveFormBuffer* buffer);
};
// @fnv 0x00982c20
void __thiscall FUN_00982c20::Save(BGSSaveFormBuffer* buffer)
{
    buffer->SaveData(this, 1, 0);
    buffer->SaveData(this + 1, 1, 0);
    buffer->SaveData(this + 2, 1, 0);
    buffer->SaveData(this + 3, 1, 0);
    buffer->SaveData(this + 4, 1, 0);
    buffer->SaveData(this + 5, 1, 0);
}

extern "C" void __cdecl Deallocate(void*);
struct FUN_00983820_class
{
    void __thiscall FUN_00983820();
};
struct FUN_009836a0_Class
{
    void* __thiscall FUN_009836a0(unsigned int flags);
};
// Calls FUN_00983820 on this, frees this when flags has bit 0 set, and returns this.
// @fnv 0x009836a0
void* __thiscall FUN_009836a0_Class::FUN_009836a0(unsigned int flags)
{
    ((FUN_00983820_class*)this)->FUN_00983820();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void* __cdecl NiMalloc(unsigned int);
void* __cdecl memset(void* dst, int val, unsigned int len);
struct FUN_00983670_v
{
    void* m_p;
    void* __thiscall FUN_009837b0(int arg);
};
// Sets m_p to DAT_0108d138, stores arg and zero, allocates arg*4 bytes, zeroes them, and returns this.
// @fnv 0x009837b0
void* FUN_00983670_v::FUN_009837b0(int arg)
{
    m_p = &DAT_0108d138;
    ((int*)this)[1] = arg;
    ((int*)this)[3] = 0;
    int size = ((int*)this)[1] << 2;
    ((int*)this)[2] = (int)NiMalloc(size);
    memset((void*)((int*)this)[2], 0, ((int*)this)[1] << 2);
    return this;
}

struct FUN_00983670;
struct FUN_009838b0_class : FUN_00983670
{
    void __thiscall FUN_00983700();
    FUN_009838b0_class* FUN_009838b0(unsigned int flags);
};

// Calls FUN_00983700, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x009838b0
FUN_009838b0_class* FUN_009838b0_class::FUN_009838b0(unsigned int flags)
{
    FUN_00983700();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_0098ad70_Class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    char FUN_0098ad70();
};

// Returns 1 when either m_10 or m_14 is non-zero, otherwise 0.
// @fnv 0x0098ad70
char FUN_0098ad70_Class::FUN_0098ad70()
{
    return m_10 == 0 && m_14 == 0 ? 0 : 1;
}

struct ParentSpaceNode
{
    int a;
    int b;
};
struct BSSimpleArray_ParentSpaceNode
{
    ParentSpaceNode& GetAt(int index);
    unsigned int GetFlags();
};
struct CombatSearchDoor
{
    int formID;
    int refID;
};

// Scans the array at offset 0x120 for a node whose a or b equals formID and returns it, otherwise returns 0.
// @fnv 0x0098c590
CombatSearchDoor* FUN_0098c590_shell::FindParentSpaceNode(int formID)
{
    for (unsigned int i = 0; i < ((BSSimpleArray_ParentSpaceNode*)((char*)this + 0x120))->GetFlags(); ++i)
    {
        ParentSpaceNode* node = &((BSSimpleArray_ParentSpaceNode*)((char*)this + 0x120))->GetAt(i);
        if (node->a == formID || node->b == formID)
            return (CombatSearchDoor*)node;
    }
    return 0;
}

struct FUN_009865f0_shell
{
    void* __thiscall FUN_009865f0(int arg);
};
struct FUN_0098de00_class
{
    int __thiscall GetFieldAtOffset16(int arg);
};
// Calls FUN_009865f0 with arg and returns the int at offset 16 of the result, or 0 if the result is null.
// @fnv 0x0098de00
int __thiscall FUN_0098de00_class::GetFieldAtOffset16(int arg)
{
    void* result = reinterpret_cast<FUN_009865f0_shell*>(this)->FUN_009865f0(arg);
    if (result)
        return reinterpret_cast<int*>(result)[4];
    return 0;
}

struct FUN_0098ed60_shell
{
    void FUN_0098ed60();
    void* __thiscall FUN_0098f690(unsigned int flags);
};

// Calls FUN_0098ed60, then deletes this if flags has bit 0 set, and returns this.
// @fnv 0x0098f690
void* __thiscall FUN_0098ed60_shell::FUN_0098f690(unsigned int flags)
{
    FUN_0098ed60();
    if (flags & 1)
        operator delete(this);
    return this;
}

extern "C" void Deallocate(void*);
struct FUN_0098f020_shell
{
    void __thiscall ResetGlobalObject();
};
struct FUN_0098f6c0_class
{
    void* __thiscall FUN_0098f6c0(unsigned int flags);
};
// @fnv 0x0098f6c0
void* __thiscall FUN_0098f6c0_class::FUN_0098f6c0(unsigned int flags)
{
    ((FUN_0098f020_shell*)this)->ResetGlobalObject();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void __cdecl Deallocate(void*);
struct FUN_0098f2d0_class
{
    void __thiscall FUN_0098f2d0();
};
struct FUN_0098f6f0_class
{
    void* __thiscall FUN_0098f6f0(unsigned int flags);
};
// @fnv 0x0098f6f0
void* __thiscall FUN_0098f6f0_class::FUN_0098f6f0(unsigned int flags)
{
    ((FUN_0098f2d0_class*)this)->FUN_0098f2d0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern "C" void __cdecl Deallocate(void*);
struct FUN_0098f4f0_class
{
    void __thiscall FUN_0098f4f0();
};
struct FUN_0098f720_class
{
    void* __thiscall FUN_0098f720(unsigned int flags);
};
// Calls FUN_0098f4f0 on this, frees this when flags has bit 0 set, and returns this.
// @fnv 0x0098f720
void* __thiscall FUN_0098f720_class::FUN_0098f720(unsigned int flags)
{
    ((FUN_0098f4f0_class*)this)->FUN_0098f4f0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void __cdecl Deallocate(void*);
struct FUN_0098f510_class
{
    void __thiscall FUN_0098f540();
    void* __thiscall FUN_0098f750(unsigned int flags);
};
// Calls FUN_0098f540, then frees this via Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0098f750
void* __thiscall FUN_0098f510_class::FUN_0098f750(unsigned int flags)
{
    FUN_0098f540();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct S5460
{
    bool __thiscall FUN_00438b90();
    unsigned int __thiscall FUN_009a3910();
};
struct FUN_0098fa00_shell
{
    void __thiscall FUN_0098fa00(unsigned int a, unsigned int b);
};
struct FUN_0098f7b0_Class
{
    void* vtbl;
    int m_04;
    int m_08;
    int m_0c;
    unsigned int FUN_0098f7b0();
};
// @fnv 0x0098f7b0
unsigned int FUN_0098f7b0_Class::FUN_0098f7b0()
{
    if (((S5460*)this)->FUN_00438b90())
    {
        if (m_0c == 0)
        {
            int v = 4;
            m_04 = ((int(__thiscall*)(void*, int))((int*)vtbl)[1])(this, v);
            m_0c = v;
        }
        else
        {
            unsigned int id = ((S5460*)this)->FUN_009a3910();
            ((FUN_0098fa00_shell*)this)->FUN_0098fa00(id, m_08);
            m_0c = id;
        }
    }
    m_08 += 1;
    return m_08 - 1;
}

extern "C" int __cdecl CreateCombatGroupStrategy(int a);
extern int DAT_011f18b4[4];
// Calls CreateCombatGroupStrategy for each index 0..3 and stores the results into DAT_011f18b4.
// @fnv 0x00990070
void __cdecl FUN_00990070()
{
    for (unsigned int i = 0; i < 4; ++i)
    {
        int v = CreateCombatGroupStrategy(i);
        DAT_011f18b4[i] = v;
    }
}

struct FUN_00991150_class
{
    void __thiscall FUN_00991150();
};
struct FUN_00991050_class
{
    void* __thiscall FUN_00991050(unsigned int flags);
};
// @fnv 0x00991050
void* __thiscall FUN_00991050_class::FUN_00991050(unsigned int flags)
{
    ((FUN_00991150_class*)this)->FUN_00991150();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern "C" void __cdecl Deallocate(void*);

struct FUN_00985f90_Class
{
    void __thiscall FUN_00985f90();
};

struct FUN_009914d0_Class
{
    void* __thiscall FUN_009914d0(unsigned int flags);
};

// Calls FUN_00985f90 on this, then frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x009914d0
void* __thiscall FUN_009914d0_Class::FUN_009914d0(unsigned int flags)
{
    ((FUN_00985f90_Class*)this)->FUN_00985f90();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_00993b60_class
{
    void __thiscall FUN_00993b60();
};
extern "C" void __cdecl Deallocate(void*);
struct FUN_00993850_class
{
    void __thiscall FUN_00993b60();
    void* __thiscall FUN_00993850(unsigned int flags);
};
// @fnv 0x00993850
void* __thiscall FUN_00993850_class::FUN_00993850(unsigned int flags)
{
    ((FUN_00993b60_class*)this)->FUN_00993b60();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_00993bc0
{
    virtual ~FUN_00993bc0();
};
struct FUN_00993b60 : FUN_00993bc0
{
    void __thiscall RemoveAll();
    ~FUN_00993b60();
};
// @fnv 0x00993b60
FUN_00993b60::~FUN_00993b60()
{
    RemoveAll();
}

void Deallocate(void*);
struct FUN_00993ca0_class
{
    void __thiscall FUN_00993bc0();
    void* __thiscall FUN_00993ca0(unsigned int flags);
};
// Calls FUN_00993bc0, then frees this via Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00993ca0
void* __thiscall FUN_00993ca0_class::FUN_00993ca0(unsigned int flags)
{
    FUN_00993bc0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_00993f70
{
    void** m_p;
    unsigned int m_uiItemCount;
    void Clear();
};
// @fnv 0x00993f70
void FUN_00993f70::Clear()
{
    for (unsigned int i = 0; i < m_uiItemCount; ++i)
    {
        void* p = m_p[i];
        Deallocate(p);
    }
    {
        void* base = m_p;
        Deallocate(base);
    }
}

void __cdecl FNV_Warning(const char* message, unsigned int value);
struct FUN_00994270
{
    int* m_items;
    int m_uiItemCount;
    unsigned int __thiscall FindIndex(unsigned int key);
};
// Searches m_items for key and returns its index, warning via FNV_Warning and returning 0 if not found.
// @fnv 0x00994270
unsigned int FUN_00994270::FindIndex(unsigned int key)
{
    for (unsigned int i = 0; i < (unsigned int)m_uiItemCount; ++i)
    {
        if ((unsigned int)m_items[i] == key)
            return i;
    }
    FNV_Warning("COMBAT: Could not find plan step %08X in CombatPlan::GetIndexForStep()", key);
    return 0;
}

struct CombatGoal;
extern CombatGoal* DAT_011f17a0[];
// @fnv 0x00994a80
CombatGoal* FUN_00994a80(int index)
{
    return DAT_011f17a0[index];
}

struct CombatStateArray
{
    CombatStateArray* FUN_009aa490(CombatStateArray*);
};
struct FUN_00994e60_class
{
    int m_dc;
    int m_e0;
    CombatStateArray* __thiscall ResetState(CombatStateArray* a);
};
// @fnv 0x00994e60
CombatStateArray* FUN_00994e60_class::ResetState(CombatStateArray* a)
{
    ((CombatStateArray*)this)->FUN_009aa490(a);
    ((int*)((char*)this + 0xdc))[0] = 0;
    ((int*)((char*)this + 0xe0))[0] = -1;
    return (CombatStateArray*)this;
}

struct FUN_00994ea0_class
{
    void __thiscall AppendPair(int a, int b);
};
// Stores a and b into the two int slots at this+0x5c/0x60 indexed by the counter at this+0xdc, then increments that counter.
// @fnv 0x00994ea0
void __thiscall FUN_00994ea0_class::AppendPair(int aiFirst, int aiSecond)
{
    *(int*)((char*)this + 0x5c + *(unsigned int*)((char*)this + 0xdc) * 8) = aiFirst;
    *(int*)((char*)this + 0x60 + *(unsigned int*)((char*)this + 0xdc) * 8) = aiSecond;
    *(unsigned int*)((char*)this + 0xdc) += 1;
}

void* __cdecl memset(void* dst, int value, unsigned int count);

struct FUN_009958b0_Class
{
    int m_00;
    char m_04[4];
    char m_08[0x58];
    char m_60[0x58];
    char m_b8[0x58];
    FUN_009958b0_Class* FUN_009958b0();
};

// Zeroes m_00 and clears the three 0x58-byte blocks at m_08, m_60 and m_b8, then returns this.
// @fnv 0x009958b0
FUN_009958b0_Class* FUN_009958b0_Class::FUN_009958b0()
{
    m_00 = 0;
    memset(m_08, 0, 0x58);
    memset(m_60, 0, 0x58);
    memset(m_b8, 0, 0x58);
    return this;
}

struct FUN_00995980_class
{
    int m_00;
    int m_04;
    void __thiscall SetEntry(int index, int value, float amount);
};

// Stores value and amount into the arrays at offsets 8 and 0xb8 for index, then calls SetQuantity on the object at this+4.
// @fnv 0x00995980
void __thiscall FUN_00995980_class::SetEntry(int index, int value, float amount)
{
    *(int*)((char*)this + index * 4 + 8) = value;
    *(float*)((char*)this + index * 4 + 0xb8) = amount;
    ((QuantityData*)*(void***)((char*)this + 4))->SetQuantity((unsigned int)index);
}

struct FUN_00996320_Class
{
    unsigned int m_aiIndexedValues[2039];
    unsigned int __thiscall FindFirstNonZero();
};
// @fnv 0x00996320
unsigned int FUN_00996320_Class::FindFirstNonZero()
{
    for (unsigned int i = 0; i < 2039; ++i)
        if (m_aiIndexedValues[i] != 0)
            return m_aiIndexedValues[i];
    return 0;
}

unsigned int __cdecl gm_GetCurrentThreadId();
struct BSWin32TaskletManager
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int __thiscall SetThreadTasklet(int a);
};
BSWin32TaskletManager& __cdecl GetTaskletManager();
struct FUN_00996860_shell
{
    int __thiscall FindPath();
};
struct FUN_00996ae0_shell
{
    int __thiscall ExtractNodeValues(int a, int b, int c);
};
struct FUN_00996420_class
{
    unsigned char m_2054;
    int __thiscall FindPath();
    int __thiscall ExtractNodeValues(int a, int b, int c);
    unsigned char __thiscall SetThreadTasklet(int a, int b, int c);
};
// @fnv 0x00996420
unsigned char __thiscall FUN_00996420_class::SetThreadTasklet(int a, int b, int abUseStored)
{
    ((unsigned char*)this)[0x2054] = (unsigned char)GetTaskletManager().SetThreadTasklet((int)gm_GetCurrentThreadId());
    int d = FindPath();
    int e;
    unsigned char f;
    if (d)
    {
        f = 1;
        e = d;
    }
    else if ((unsigned char)abUseStored)
    {
        f = 0;
        e = *(int*)((char*)this + 0x2048);
    }
    else
    {
        f = 0;
        e = 0;
    }
    if (e)
        ExtractNodeValues(e, a, b);
    return f;
}

extern int DAT_0108dc6c;
struct FUN_00996540
{
    virtual ~FUN_00996540();
};
struct FUN_00996560 : public FUN_00996540
{
    ~FUN_00996560();
};
// Destructor that calls Clear(true) on the object.
// @fnv 0x00996560
FUN_00996560::~FUN_00996560()
{
    ((GlobalObject_00869f00*)this)->Clear(true);
}

struct FUN_00996540_shell
{
    void FUN_00996540();
};
extern "C" void __cdecl Deallocate(void*);

struct FUN_00996710_class : FUN_00996540_shell
{
    void* __thiscall FUN_00996710(unsigned int flags);
};

// @fnv 0x00996710
void* __thiscall FUN_00996710_class::FUN_00996710(unsigned int flags)
{
    FUN_00996540();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void __cdecl Deallocate(void*);

struct FUN_00996560_class
{
    void __thiscall FUN_00996560();
};

struct FUN_00996740_class
{
    void* __thiscall FUN_00996740(unsigned int flags);
};

// @fnv 0x00996740
void* __thiscall FUN_00996740_class::FUN_00996740(unsigned int flags)
{
    ((FUN_00996560_class*)this)->FUN_00996560();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern "C" void __cdecl Deallocate(void*);
struct FUN_00996640_shell
{
    void FUN_00996640();
};
struct FUN_00996770_class : FUN_00996640_shell
{
    void* __thiscall FUN_00996770(unsigned int flags);
};
// Calls FUN_00996640, then frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00996770
void* __thiscall FUN_00996770_class::FUN_00996770(unsigned int flags)
{
    FUN_00996640();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern "C" void __cdecl Deallocate(void*);
struct FUN_009967a0_class
{
    void* __thiscall FUN_00996660();
    void* __thiscall FUN_009967a0(unsigned int flags);
};
// Calls FUN_00996660, then frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x009967a0
void* __thiscall FUN_009967a0_class::FUN_009967a0(unsigned int flags)
{
    FUN_00996660();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern "C" void __cdecl Deallocate(void*);
struct FUN_009966f0_class
{
    void __thiscall FUN_009966f0();
    FUN_009966f0_class* __thiscall FUN_009967d0(unsigned int flags);
};
// Calls FUN_009966f0, frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x009967d0
FUN_009966f0_class* __thiscall FUN_009966f0_class::FUN_009967d0(unsigned int flags)
{
    FUN_009966f0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_009966f0
{
    virtual ~FUN_009966f0();
};
struct FUN_00996c80 : FUN_009966f0
{
    ~FUN_00996c80();
};
// Destructor that calls Clear(true) on the object at this address.
// @fnv 0x00996c80
FUN_00996c80::~FUN_00996c80()
{
    reinterpret_cast<GlobalObject_00869f00*>(this)->Clear(true);
}

void __cdecl Deallocate(void*);
struct FUN_00996d80_Class
{
    void __thiscall FUN_00996c80();
    void* __thiscall FUN_00996d80(unsigned int flags);
};
// @fnv 0x00996d80
void* __thiscall FUN_00996d80_Class::FUN_00996d80(unsigned int flags)
{
    FUN_00996c80();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct BGSLoadFormBuffer
{
    void __thiscall ReadTypedData(void*, unsigned int);
};
struct FUN_00982ca0_Class
{
    char m_000;
    char m_001;
    char m_002;
    char m_003;
    char m_004;
    char m_005;
    void __thiscall FUN_00982ca0(BGSLoadFormBuffer* buffer);
};
// Reads six single bytes from the load buffer into this object's fields m_000 through m_005.
// @fnv 0x00982ca0
void __thiscall FUN_00982ca0_Class::FUN_00982ca0(BGSLoadFormBuffer* buffer)
{
    buffer->ReadTypedData(this, 1);
    buffer->ReadTypedData(&m_001, 1);
    buffer->ReadTypedData(&m_002, 1);
    buffer->ReadTypedData(&m_003, 1);
    buffer->ReadTypedData(&m_004, 1);
    buffer->ReadTypedData(&m_005, 1);
}

struct ScrapHeapBuffer;
struct MemoryManager
{
    ScrapHeapBuffer* GetGeneralAllocator();
};
MemoryManager* __cdecl FUN_00401020();
struct FUN_006cf180
{
    FUN_006cf180();
    ~FUN_006cf180();
    void ResizeAndConstruct(int, int);
};
struct FUN_0098f5f0 : FUN_006cf180
{
    const char* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    FUN_0098f5f0(int a, int b, void* c);
};
// Sets m_04 to "P0o", stores c (or a MemoryManager-provided pointer) in m_14, then calls ResizeAndConstruct with a and b.
// @fnv 0x0098f5f0
FUN_0098f5f0::FUN_0098f5f0(int a, int b, void* c)
{
    m_04 = "P0o";
    m_14 = c ? c : FUN_00401020()->GetGeneralAllocator();
    ResizeAndConstruct(a, b);
}

struct FUN_0098f8e0_Class : FUN_0098fda0_Class
{
    FUN_0098f8e0_Class* __thiscall FUN_0098f8e0();
};
// Calls FUN_0097ede0 on four embedded Inner097 members and FUN_004300a0 on six members at offsets 0x4c-0x60, then returns this.
// @fnv 0x0098f8e0
FUN_0098f8e0_Class* __thiscall FUN_0098f8e0_Class::FUN_0098f8e0()
{
    ((Inner097*)((char*)this + 8))->FUN_0097ede0();
    ((Inner097*)((char*)this + 0x18))->FUN_0097ede0();
    ((Inner097*)((char*)this + 0x28))->FUN_0097ede0();
    ((Inner097*)((char*)this + 0x38))->FUN_0097ede0();
    FUN_004300a0((CombatTargetTimestamp*)((char*)this + 0x4c));
    FUN_004300a0((CombatTargetTimestamp*)((char*)this + 0x50));
    FUN_004300a0((CombatTargetTimestamp*)((char*)this + 0x54));
    FUN_004300a0((CombatTargetTimestamp*)((char*)this + 0x58));
    FUN_004300a0((CombatTargetTimestamp*)((char*)this + 0x5c));
    FUN_004300a0((CombatTargetTimestamp*)((char*)this + 0x60));
    return this;
}

extern "C" void* __cdecl FUN_00ec7230(char* dst, const char* src, unsigned int size);
struct FUN_0098f960_class
{
    void __thiscall FUN_0098f960(char* dst, char* src, unsigned int count);
};
// @fnv 0x0098f960
void __thiscall FUN_0098f960_class::FUN_0098f960(char* dst, char* src, unsigned int count)
{
    if (count <= 0)
        return;
    if (dst < src)
    {
        for (unsigned int i = 0; i < count; ++i)
            FUN_00ec7230(dst + i * 0x68, src + i * 0x68, 0x68);
    }
    else if (dst > src)
    {
        for (int i = (int)count - 1; i >= 0; --i)
            FUN_00ec7230(dst + i * 0x68, src + i * 0x68, 0x68);
    }
}

struct FUN_00996840_shell
{
    unsigned int FUN_00996840(unsigned int);
};

struct FUN_00996370_class
{
    unsigned char __thiscall AdvanceToNextEntry(unsigned int* ai, unsigned int* ai2, unsigned int* ai3);
};

// @fnv 0x00996370
unsigned char FUN_00996370_class::AdvanceToNextEntry(unsigned int* puiCurrent, unsigned int* puiValue,
                                                     unsigned int* puiNode)
{
    unsigned int p = *puiCurrent;
    if (!p)
        return 0;
    *puiValue = *(unsigned int*)((char*)p + 0x1c);
    *puiNode = p;
    if (*(unsigned int*)((char*)p + 0x20))
    {
        *puiCurrent = *(unsigned int*)((char*)p + 0x20);
        return 1;
    }
    else
    {
        unsigned int i = ((FUN_00996840_shell*)this)->FUN_00996840(*(unsigned int*)((char*)p + 0x1c));
        unsigned int uiNextIndex = i + 1;
        for (; uiNextIndex < 0x7f7; uiNextIndex++)
        {
            if (*(unsigned int*)((char*)this + uiNextIndex * 4))
            {
                *puiCurrent = *(unsigned int*)((char*)this + uiNextIndex * 4);
                return 1;
            }
        }
    }
    *puiCurrent = 0;
    return 0;
}

namespace fnv_009965c0 {
struct ScrapHeapBuffer;
struct MemoryManager
{
    ScrapHeapBuffer* GetGeneralAllocator();
};
MemoryManager* __cdecl FUN_00401020();
extern void* DAT_0108dc94;
struct FUN_00996bd0
{
    FUN_00996bd0();
    ~FUN_00996bd0();
};
struct FUN_009965c0 : public FUN_00996bd0
{
    void* m_vtbl;
    int m_04;
    int m_08;
    int m_0c;
    void* m_10;
    FUN_009965c0();
};
// @fnv 0x009965c0
FUN_009965c0::FUN_009965c0()
{
    m_vtbl = &DAT_0108dc94;
    m_10 = FUN_00401020()->GetGeneralAllocator();
    ((AX*)this)->FUN_006b3eb0(0, 0);
}
}  // namespace fnv_009965c0

struct ArrSI
{
    unsigned int GetFlags();
};
struct FUN_00844160_shell
{
    unsigned int FUN_00844160(unsigned int);
};
struct EffectSetting
{
    EffectSetting* GetCastSound() const;
};
struct TESAmmoInitCalls
{
    unsigned int GetFieldBC();
};
struct Actor;
struct ActorCombatGroup
{
    bool ContainsActor(Actor*);
};

struct FUN_00982df0_class
{
    bool FUN_00982df0(unsigned int arg);
};

// @fnv 0x00982df0
bool FUN_00982df0_class::FUN_00982df0(unsigned int arg)
{
    if (arg)
    {
        for (unsigned int i = 0; i < ((ArrSI*)this)->GetFlags(); ++i)
        {
            unsigned int e = ((FUN_00844160_shell*)this)->FUN_00844160(i);
            if (*(unsigned int*)e == arg)
                return false;
            if (((ActorCombatGroup*)((EffectSetting*)arg)->GetCastSound())
                    ->ContainsActor((Actor*)((TESAmmoInitCalls*)*(void**)e)->GetFieldBC()))
                return false;
        }
    }
    return true;
}

unsigned int __cdecl FUN_0042f5a0(unsigned int, unsigned int);
struct FUN_006c0010_Class
{
    void FUN_006c0010(void*, void*, unsigned int);
};
struct FUN_0072ba80_shell
{
    void FUN_0072ba80(void*, unsigned int);
};
struct FUN_0098f430_Class
{
    int m_00;
    void* m_04;
    unsigned int m_08;
    void FUN_0098f430(unsigned int a, unsigned int b);
};
// Removes b elements starting at index a from the array at m_04, shifting the tail down and decreasing m_08 by b.
// @fnv 0x0098f430
void FUN_0098f430_Class::FUN_0098f430(unsigned int uiStartIndex, unsigned int b)
{
    unsigned int c = FUN_0042f5a0(m_08 - uiStartIndex - b, b);
    ((FUN_0072ba80_shell*)this)->FUN_0072ba80((char*)m_04 + uiStartIndex * 0x1c, b);
    ((FUN_006c0010_Class*)this)
        ->FUN_006c0010((char*)m_04 + uiStartIndex * 0x1c, (char*)m_04 + m_08 * 0x1c - c * 0x1c, c);
    m_08 -= b;
}

void __cdecl DestroyCombatActionTables();
void __cdecl FUN_00984a90();
void __cdecl DeallocateAll();
void __cdecl FreeGlobalPointer();
extern void* BGSSaveLoadGlobalDataWorldspacePtr;
// @fnv 0x00990ff0
void __cdecl FUN_00990ff0()
{
    DestroyCombatActionTables();
    FUN_00984a90();
    DeallocateAll();
    FreeGlobalPointer();
    FUN_00991050_class* tmp = (FUN_00991050_class*)BGSSaveLoadGlobalDataWorldspacePtr;
    FUN_00991050_class* ptr = tmp;
    ptr ? ptr->FUN_00991050(1) : 0;
    BGSSaveLoadGlobalDataWorldspacePtr = 0;
}

extern int DAT_0108db5c;
void* __cdecl _NiMalloc(unsigned int);
void* __cdecl memset(void* dst, int val, unsigned int len);
struct FUN_00993990
{
    int* vtbl;
    int m_04;
    void* m_08;
    int m_0c;
    FUN_00993990(int a);
};
// Sets the vtable, stores the count, allocates count*4 bytes, and zeroes the allocated buffer.
// @fnv 0x00993990
FUN_00993990::FUN_00993990(int aiCount)
{
    vtbl = &DAT_0108db5c;
    m_04 = aiCount;
    m_0c = 0;
    int n = m_04 * 4;
    m_08 = _NiMalloc(n);
    memset(m_08, 0, m_04 * 4);
}

struct FUN_00996ce0_Node
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
};
struct FUN_00996ce0_Slot
{
    FUN_00996ce0_Node* pNode;
};
struct FUN_00996ce0_Class
{
    int m_00;
    FUN_00996ce0_Slot m_slots[20];
    FUN_00996ce0_Node* __thiscall PopNode();
};
// Scans the 20 slots for the first occupied one, unlinks its node (advancing to m_18 or clearing the slot) and returns it with m_14 and m_18 reset.
// @fnv 0x00996ce0
FUN_00996ce0_Node* FUN_00996ce0_Class::PopNode()
{
    FUN_00996ce0_Node* result = 0;
    for (unsigned int i = 0; i < 20; i++)
    {
        FUN_00996ce0_Slot* slot = &m_slots[i];
        if (slot->pNode)
        {
            result = slot->pNode;
            if (slot->pNode->m_18)
            {
                ((FUN_00996ce0_Node*)slot->pNode->m_18)->m_14 = (int)slot;
                slot->pNode = (FUN_00996ce0_Node*)slot->pNode->m_18;
            }
            else
            {
                slot->pNode = 0;
            }
            result->m_14 = 0;
            result->m_18 = 0;
            break;
        }
    }
    return result;
}

extern NiPoint3 _NiPoint3_ZERO;
extern float _DAT_011f4270;
extern float _DAT_011f4274;
struct FUN_00980090_t
{
    unsigned char FUN_009800e0(const void*, const NiPoint3&);
    float GetPointY(const void*);
};
// Builds a fixed NiPoint3 and, if FUN_009800e0 succeeds for ap, returns that point's y; otherwise returns 0.0f.
// @fnv 0x00980090
float FUN_00980090_t::GetPointY(const void* ap)
{
    NiPoint3 p2;
    float f = 0.0f;
    *(int*)&p2 = *(int*)&_NiPoint3_ZERO;
    *(int*)&p2.y = *(int*)&_DAT_011f4270;
    *(int*)&p2.z = *(int*)&_DAT_011f4274;
    if (FUN_009800e0(ap, p2))
        f = p2.y;
    return f;
}

struct TESPackage
{
    unsigned int GetRefCount();
};
struct FUN_00981920_Class
{
    unsigned int GetPackageRefCount();
};
// @fnv 0x00981920
unsigned int FUN_00981920_Class::GetPackageRefCount()
{
    return ((TESPackage*)*(unsigned int**)((char*)this + 0x9c))->GetRefCount();
}

struct FUN_00982430 : public AX
{
    FUN_00982430* DeserializeFromFile();
};

// Sets the object's vtable to DAT_0108cff4, calls FUN_006b3eb0 with 0, 0, and returns this.
// @fnv 0x00982430
FUN_00982430* FUN_00982430::DeserializeFromFile()
{
    *reinterpret_cast<void**>(this) = &DAT_0108cff4;
    FUN_006b3eb0(0, 0);
    return this;
}

void __cdecl Deallocate(void*);
struct FUN_009825b0_shell : FUN_00982460
{
    void* FUN_009825b0(unsigned int flags);
};
// Calls Init, then if the low bit of flags is set calls Deallocate on this, and returns this.
// @fnv 0x009825b0
void* FUN_009825b0_shell::FUN_009825b0(unsigned int flags)
{
    Init();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct ScrapHeapBuffer
{
    ~ScrapHeapBuffer();
    void FUN_00982610();
};

// @fnv 0x00982610
void ScrapHeapBuffer::FUN_00982610()
{
    this->ScrapHeapBuffer::~ScrapHeapBuffer();
}

struct Pt
{
    float x;
    float y;
    float z;

    float Length() const;
};

struct P3
{
    float x;
    float y;
    float z;

    Pt operator-(const P3&) const;
};

float __cdecl FUN_00404040(float);
extern double DAT_010231d8;

struct FUN_00982630_arg
{
    char pad_000[0x28];
    P3 a;
    P3 b;
};

struct FUN_00982630_class
{
    unsigned char m_00;
    unsigned char m_01;

    void __thiscall FUN_00982630(FUN_00982630_arg* arg);
};

// @fnv 0x00982630
void FUN_00982630_class::FUN_00982630(FUN_00982630_arg* arg)
{
    Pt distanceVector = arg->a - arg->b;
    float distance = distanceVector.Length();

    if (distance <= DAT_010231d8)
    {
        this->m_01 = static_cast<unsigned char>(FUN_00404040(distance / 8.0));
        this->m_00 = static_cast<unsigned char>(FUN_00404040(distance / this->m_01));
    }
    else
    {
        float scaledDistance = distance / 32.0;

        if (scaledDistance > 255.0)
        {
            this->m_00 = 255;
        }
        else
        {
            this->m_00 = static_cast<unsigned char>(FUN_00404040(scaledDistance));
        }

        this->m_01 = 0x20;
    }
}

struct FUN_00982b50_t
{
    char m0, m1, m2, m3, m4, m5;
    void FUN_00982b50();
};
// Sets all six byte fields of the object to zero.
// @fnv 0x00982b50
void FUN_00982b50_t::FUN_00982b50()
{
    m2 = 0;
    m3 = 0;
    m0 = 0;
    m1 = 0;
    m4 = 0;
    m5 = 0;
}

struct FUN_009838e0_Class : NiTPointerMap_00983880
{
    void* __thiscall FUN_009838e0(unsigned int flags);
};

// @fnv 0x009838e0
void* __thiscall FUN_009838e0_Class::FUN_009838e0(unsigned int flags)
{
    FUN_00983880();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_00984210_Class
{
    char m_000[0x58];
    void* m_058[16];
    void* GetSlotPtr(int a);
};
// @fnv 0x00984210
void* FUN_00984210_Class::GetSlotPtr(int aiIndex)
{
    return (void*)((char*)this + 0x58 + aiIndex * 8);
}

struct S006bfd40
{
    unsigned int FUN_006bfd40();
};

struct FUN_006bf670_Class
{
    int* FUN_006bf670(int);
};

struct CombatTargetTimestamp
{
    int m_uiFilterValue;
    CombatTargetTimestamp(float value);
};

float __cdecl GetActorScale(void);

struct FUN_0098bfb0_Header
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
};

struct FUN_0098bfb0_Record
{
    FUN_0098bfb0_Header m_kHeader;
    int m_timestamp;
    int m_uiFilterValue;
    float m_float;
};

struct FUN_0098bfb0_Class
{
    void __thiscall StoreRecord(void* header, float value, int extra);
};

// @fnv 0x0098bfb0
void __thiscall FUN_0098bfb0_Class::StoreRecord(void* header, float value, int extra)
{
    unsigned int index = reinterpret_cast<S006bfd40*>(reinterpret_cast<char*>(this) + 0x110)->FUN_006bfd40();

    reinterpret_cast<FUN_0098bfb0_Record*>(
        reinterpret_cast<FUN_006bf670_Class*>(reinterpret_cast<char*>(this) + 0x110)->FUN_006bf670(index))
        ->m_kHeader = *reinterpret_cast<const FUN_0098bfb0_Header*>(header);

    {
        CombatTargetTimestamp timestamp(GetActorScale());

        reinterpret_cast<FUN_0098bfb0_Record*>(
            reinterpret_cast<FUN_006bf670_Class*>(reinterpret_cast<char*>(this) + 0x110)->FUN_006bf670(index))
            ->m_timestamp = timestamp.m_uiFilterValue;

        reinterpret_cast<FUN_0098bfb0_Record*>(
            reinterpret_cast<FUN_006bf670_Class*>(reinterpret_cast<char*>(this) + 0x110)->FUN_006bf670(index))
            ->m_uiFilterValue = extra;

        reinterpret_cast<FUN_0098bfb0_Record*>(
            reinterpret_cast<FUN_006bf670_Class*>(reinterpret_cast<char*>(this) + 0x110)->FUN_006bf670(index))
            ->m_float = value;
    }
}

struct GO
{
    operator unsigned int(void) const;
};

struct ExtraRadioData : GO
{
};

struct TESObjectREFR
{
    ExtraRadioData* GetExtraRadioData(void);
};

struct EdgeRecord
{
    int m_0000;
    int m_0004;
    unsigned char m_0008;
    unsigned char m_0009;
    unsigned char m_000a;
};

struct EdgeArr
{
    unsigned short& FUN_006a1440(unsigned int);
};

struct S5460_helper
{
    unsigned int FUN_00978bc0(void);
};

struct FUN_0098c600_class
{
    void __thiscall AddRadioReference(TESObjectREFR* arg);
};

// @fnv 0x0098c600
void __thiscall FUN_0098c600_class::AddRadioReference(TESObjectREFR* pRef)
{
    if (reinterpret_cast<FUN_0098c590_shell*>(this)->FindParentSpaceNode(reinterpret_cast<int>(pRef)) != 0)
    {
        return;
    }

    ExtraRadioData* radioData = pRef->GetExtraRadioData();
    if (!radioData || !radioData->operator unsigned int())
    {
        return;
    }

    unsigned int index =
        reinterpret_cast<S5460_helper*>(reinterpret_cast<unsigned char*>(this) + 0x120)->FUN_00978bc0();

    reinterpret_cast<EdgeRecord*>(
        &reinterpret_cast<EdgeArr*>(reinterpret_cast<unsigned char*>(this) + 0x120)->FUN_006a1440(index))
        ->m_0000 = reinterpret_cast<int>(pRef);

    reinterpret_cast<EdgeRecord*>(
        &reinterpret_cast<EdgeArr*>(reinterpret_cast<unsigned char*>(this) + 0x120)->FUN_006a1440(index))
        ->m_0004 = radioData->operator unsigned int();

    reinterpret_cast<EdgeRecord*>(
        &reinterpret_cast<EdgeArr*>(reinterpret_cast<unsigned char*>(this) + 0x120)->FUN_006a1440(index))
        ->m_0008 = 0;

    reinterpret_cast<EdgeRecord*>(
        &reinterpret_cast<EdgeArr*>(reinterpret_cast<unsigned char*>(this) + 0x120)->FUN_006a1440(index))
        ->m_000a = 0;

    reinterpret_cast<EdgeRecord*>(
        &reinterpret_cast<EdgeArr*>(reinterpret_cast<unsigned char*>(this) + 0x120)->FUN_006a1440(index))
        ->m_0009 = 0;
}

struct FUN_0098dc20 : Inner097
{
    int pad;
    FUN_0098dc20* Method();
};

// @fnv 0x0098dc20
FUN_0098dc20* FUN_0098dc20::Method()
{
    ((Inner097*)((char*)this + 4))->FUN_0097ede0();
    return this;
}

struct CombatThreatEntry
{
    unsigned char data[0x14];
};

struct FUN_009a3b20_Class
{
    void CopyCombatThreatEntries(CombatThreatEntry*, CombatThreatEntry*, unsigned int);
};

struct FUN_0098f1f0_Class
{
    void* vtbl;
    unsigned char* m_p;
    unsigned int m_uiItemCount;

    void RemoveEntries(unsigned int, unsigned int);
};

// Removes count entries at index from the array, shifts the tail down, and decrements the stored count.
// @fnv 0x0098f1f0
void FUN_0098f1f0_Class::RemoveEntries(unsigned int index, unsigned int count)
{
    unsigned int result = FUN_0042f5a0(m_uiItemCount - index - count, count);

    reinterpret_cast<FUN_0072ba80_shell*>(this)->FUN_0072ba80(m_p + index * 0x14, count);

    reinterpret_cast<FUN_009a3b20_Class*>(this)->CopyCombatThreatEntries(
        reinterpret_cast<CombatThreatEntry*>(m_p + index * 0x14),
        reinterpret_cast<CombatThreatEntry*>(m_p + m_uiItemCount * 0x14 - result * 0x14), result);

    m_uiItemCount -= count;
}

struct FUN_006bff60_Class
{
    void __thiscall FUN_006bff60(unsigned int newSize, unsigned int oldSize);
};

struct FUN_0098fc70_Class
{
    void __thiscall FUN_0098fc70(void* data, unsigned int count);
};

struct BSSimpleArrayActor
{
    virtual void* Virtual0();
    virtual void* Allocate(unsigned int size);

    void Clear(bool clear);

    void* m_data;
    unsigned int m_iElementCount;
    unsigned int m_pRayCursor;

    void __thiscall FUN_0098f2f0(unsigned int count, bool clear);
};

// @fnv 0x0098f2f0
void BSSimpleArrayActor::FUN_0098f2f0(unsigned int count, bool clear)
{
    if (count == 0)
    {
        Clear(clear);
    }
    else if (count > m_pRayCursor)
    {
        if (m_pRayCursor == 0)
        {
            m_data = Allocate(count);
            m_pRayCursor = count;
        }
        else
        {
            reinterpret_cast<FUN_006bff60_Class*>(this)->FUN_006bff60(count, m_iElementCount);
            m_pRayCursor = count;
        }

        reinterpret_cast<FUN_0098fc70_Class*>(this)->FUN_0098fc70(static_cast<char*>(m_data) + m_iElementCount * 0x1c,
                                                                  count - m_iElementCount);
        m_iElementCount = count;
    }
    else if (count < m_iElementCount)
    {
        reinterpret_cast<FUN_0072ba80_shell*>(this)->FUN_0072ba80(static_cast<char*>(m_data) + count * 0x1c,
                                                                  m_iElementCount - count);
        m_iElementCount = count;

        if (clear && count <= m_pRayCursor / 4)
        {
            reinterpret_cast<FUN_006bff60_Class*>(this)->FUN_006bff60(count, count);
            m_pRayCursor = count;
        }
    }
    else
    {
        reinterpret_cast<FUN_0098fc70_Class*>(this)->FUN_0098fc70(static_cast<char*>(m_data) + m_iElementCount * 0x1c,
                                                                  count - m_iElementCount);
        m_iElementCount = count;
    }
}

void __cdecl Deallocate(void*);
struct FUN_0098f560
{
    ~FUN_0098f560();
    FUN_0098f560* FUN_0098f780(unsigned int flags);
};
// Runs the destructor and, if bit 0 of flags is set, deallocates this, then returns this.
// @fnv 0x0098f780
FUN_0098f560* FUN_0098f560::FUN_0098f780(unsigned int flags)
{
    this->FUN_0098f560::~FUN_0098f560();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct CombatTarget;

struct BSSimpleArray_CombatTarget_1024
{
    virtual void FUN_0098fabc_dummy() = 0;
    virtual CombatTarget* FUN_0098fabc(unsigned int) = 0;

    CombatTarget* m_p;
    unsigned int m_0008;
    unsigned int m_000c;

    void __thiscall FUN_0098f840(CombatTarget*, unsigned int);
    void __thiscall FUN_0098fab0(unsigned int, unsigned int);
};

// Resets the array, allocates capacity for max(requested, savedSize) elements, then copies savedSize elements into it.
// @fnv 0x0098fab0
void __thiscall BSSimpleArray_CombatTarget_1024::FUN_0098fab0(unsigned int requested, unsigned int savedSize)
{
    m_p = 0;
    m_0008 = 0;
    m_000c = 0;

    if (savedSize > requested)
    {
        requested = savedSize;
    }

    if (requested > 0)
    {
        m_p = this->FUN_0098fabc(requested);
        m_000c = requested;
    }

    if (savedSize > 0)
    {
        this->FUN_0098f840(m_p, savedSize);
        m_0008 = savedSize;
    }
}

struct CombatClusterMember;

struct BSSimpleArray_CombatMember_1024
{
    void** vtable;
    CombatClusterMember* m_04;
    unsigned int m_08;
    unsigned int m_0c;

    unsigned int FUN_0098fb40(CombatClusterMember*, unsigned int);
    void FUN_0098fbe0(unsigned int, unsigned int);
};

typedef CombatClusterMember*(__thiscall* BSSimpleArray_CombatMember_1024_VirtualAlloc)(BSSimpleArray_CombatMember_1024*,
                                                                                       unsigned int);

// @fnv 0x0098fbe0
void BSSimpleArray_CombatMember_1024::FUN_0098fbe0(unsigned int aiCapacity, unsigned int aiCount)
{
    m_04 = 0;
    m_08 = 0;
    m_0c = 0;

    if (aiCount > aiCapacity)
    {
        aiCapacity = aiCount;
    }

    if (aiCapacity > 0)
    {
        m_04 = ((BSSimpleArray_CombatMember_1024_VirtualAlloc)this->vtable[1])(this, aiCapacity);
        m_0c = aiCapacity;
    }

    if (aiCount > 0)
    {
        FUN_0098fb40(m_04, aiCount);
        m_08 = aiCount;
    }
}

extern int DAT_011a4ed0[];

struct FUN_0098fdd0_class : BSSimpleList<int>
{
    int __thiscall FUN_0098fdd0();
};

// @fnv 0x0098fdd0
int __thiscall FUN_0098fdd0_class::FUN_0098fdd0()
{
    return DAT_011a4ed0[reinterpret_cast<unsigned int>(GetNext())];
}

extern int DAT_0108d97c;
struct FUN_00990040 : public FUN_0098ffb0
{
    FUN_00990040(int arg);
};
// Constructs the object by forwarding arg to the base constructor and setting mVtbl to DAT_0108d97c.
// @fnv 0x00990040
FUN_00990040::FUN_00990040(int arg) : FUN_0098ffb0(arg)
{
    mVtbl = &DAT_0108d97c;
}

extern int DAT_011f18b4[4];
void __cdecl Deallocate(void*);

// Iterates over the four entries of DAT_011f18b4 and calls Deallocate on each one.
// @fnv 0x009900b0
void DeallocateAll()
{
    for (unsigned int i = 0; i < 4; i++)
    {
        void* p = (void*)DAT_011f18b4[i];
        Deallocate(p);
    }
}

struct Actor;

struct CombatGroup_GetCount
{
    unsigned int GetCount();
};

struct FUN_00986b70_helper
{
    Actor* GetIntAt(int);
};

struct TESChallenge
{
    int GetProgressValue();
};

struct CombatState : TESChallenge
{
};

struct IMH
{
    CombatState* FUN_00586150();
};

struct FUN_009905a0_fields
{
    void* m_000;
    int m_004;
    int m_008;
    int m_00c;
    int m_010;
};

template <int N> struct ActorVTableTag
{
};

template <int N> struct ActorVTableLevel;

template <> struct ActorVTableLevel<0>
{
    virtual void v(ActorVTableTag<0>*) = 0;
};

template <int N> struct ActorVTableLevel : ActorVTableLevel<N - 1>
{
    virtual void v(ActorVTableTag<N>*) = 0;
};

struct ActorVTableHelper : ActorVTableLevel<265>
{
    virtual IMH* GetIMH() = 0;
};

// Iterates the combat group's actors, reads each one's challenge progress and keeps the smallest value in m_00c and m_010.
// @fnv 0x009905a0
void FUN_009905a0_shell::UpdateMinProgress()
{
    unsigned int count =
        reinterpret_cast<CombatGroup_GetCount*>(reinterpret_cast<FUN_009905a0_fields*>(this)->m_000)->GetCount();

    for (unsigned int index = 0; index < count; ++index)
    {
        Actor* pActor = reinterpret_cast<FUN_00986b70_helper*>(reinterpret_cast<FUN_009905a0_fields*>(this)->m_000)
                            ->GetIntAt(index);

        IMH* actor = reinterpret_cast<ActorVTableHelper*>(pActor)->GetIMH();

        if (actor)
        {
            int progress = actor->FUN_00586150()->GetProgressValue();

            if (progress < reinterpret_cast<FUN_009905a0_fields*>(this)->m_00c)
                reinterpret_cast<FUN_009905a0_fields*>(this)->m_00c = progress;

            if (progress < reinterpret_cast<FUN_009905a0_fields*>(this)->m_010)
                reinterpret_cast<FUN_009905a0_fields*>(this)->m_010 = progress;
        }
    }
}

void __cdecl NiFree(void*);
struct FUN_00993bc0_class
{
    int m_vtbl;
    int m_04;
    void* m_08;
    void FUN_00993cd0();
    void __thiscall FUN_00993bc0();
};
// Sets the vtable pointer, calls FUN_00993cd0, then frees m_08 with NiFree.
// @fnv 0x00993bc0
void __thiscall FUN_00993bc0_class::FUN_00993bc0()
{
    m_vtbl = (int)&DAT_0108db5c;
    FUN_00993cd0();
    NiFree(m_08);
}

void __cdecl Deallocate(void*);
struct FUN_00993c40_shell
{
    void* FUN_00993c40(unsigned int flags);
};
// @fnv 0x00993c40
void* FUN_00993c40_shell::FUN_00993c40(unsigned int flags)
{
    ((FUN_00991130_class*)this)->FUN_00993880();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void __cdecl Deallocate(void*);
struct FUN_00993c70 : FUN_00991130_class
{
    void* __thiscall DeleteThis(unsigned int flags);
};
// @fnv 0x00993c70
void* __thiscall FUN_00993c70::DeleteThis(unsigned int flags)
{
    FUN_00991130();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct NiTMallocInterface_0096afc0
{
    static void* __cdecl Allocate(unsigned short);
};
extern int DAT_0108db4c;

struct FUN_00993cf0_class
{
    int* vtbl;
    void* m_data;
    unsigned short m_uiItemCount;
    unsigned short m_00a;
    unsigned short m_00c;
    unsigned short m_00e;
    FUN_00993cf0_class* FUN_00993cf0(unsigned short a, unsigned short b);
};

// @fnv 0x00993cf0
FUN_00993cf0_class* __thiscall FUN_00993cf0_class::FUN_00993cf0(unsigned short a, unsigned short b)
{
    vtbl = &DAT_0108db4c;
    m_uiItemCount = a;
    m_00e = b;
    m_00a = 0;
    m_00c = 0;
    if (m_uiItemCount > 0)
        m_data = NiTMallocInterface_0096afc0::Allocate(m_uiItemCount);
    else
        m_data = 0;
    return this;
}

struct FUN_00993fd0_item
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
};

struct FUN_00993fd0_class
{
    void** m_p;
    int m_uiItemCount;
    void __thiscall AllocateItemArray(int arg);
};

// Stores arg as the count, allocates an array of that many pointers, and fills each with a new item.
// @fnv 0x00993fd0
void __thiscall FUN_00993fd0_class::AllocateItemArray(int aiCount)
{
    m_uiItemCount = aiCount;
    m_p = new void*[m_uiItemCount];
    for (unsigned int i = 0; i < m_uiItemCount; ++i)
    {
        m_p[i] = new FUN_00993fd0_item;
    }
}

struct FUN_00994250_shell
{
    char m_00;
    char m_01;
    char m_02;
    char m_03;
    char m_04;
    char m_05;
    char m_06;
    char m_07;
    char m_08;
    char m_09;
    char m_0a;
    char m_0b;
    char m_0c;
    char m_0d;
    char m_0e;
    char m_0f;
    char m_10;
    char m_11;
    char m_12;
    char m_13;
    char m_14;
    char m_15;
    char m_16;
    char m_17;
    char m_18;
    char m_19;
    char m_1a;
    char m_1b;
    char m_1c;
    char m_1d;
    char m_1e;
    char m_1f;
    char m_20;
    char m_21;
    char m_22;
    char m_23;
    char m_24;
    char m_25;
    char m_26;
    char m_27;
    unsigned int m_28;
    bool HasFlags(unsigned int flags);
};

// @fnv 0x00994250
bool FUN_00994250_shell::HasFlags(unsigned int flags)
{
    return (m_28 & flags) ? true : false;
}

struct FUN_009948d0_class
{
    int GetEntryField3(int index);
};

// @fnv 0x009948d0
int FUN_009948d0_class::GetEntryField3(int index)
{
    return ((int**)*((int**)this))[index][3];
}

struct FUN_00995760
{
    int m_00;
    FUN_00995760();
};

// @fnv 0x00995760
FUN_00995760::FUN_00995760()
{
    m_00 = 0xffffffff;
}

namespace fnv_009957c0 {
struct GO
{
    operator unsigned int();
};
struct FUN_009aa3b0_Class
{
    bool HasMatchingEntry(unsigned int, unsigned int);
};
struct FUN_009957c0_Class
{
    bool __thiscall FUN_009957c0(BSSimpleList<int>* arg);
};
// Calls HasMatchingEntry on the list's first value and its next value, returning the result.
// @fnv 0x009957c0
bool FUN_009957c0_Class::FUN_009957c0(BSSimpleList<int>* pList)
{
    return ((FUN_009aa3b0_Class*)((char*)this + 0x14))
        ->HasMatchingEntry((unsigned int)*(GO*)pList, (unsigned int)pList->GetNext());
}
}  // namespace fnv_009957c0

struct FUN_00aa6330_shell
{
    void IsCurrentThread();
};
struct FUN_00995870_shell
{
    char m_00[0x14];
    FUN_00aa6330_shell m_14;
    void FUN_00995870();
};
// @fnv 0x00995870
void FUN_00995870_shell::FUN_00995870()
{
    m_14.IsCurrentThread();
}

struct _Mem_20a4
{
    void __thiscall SetSize(unsigned int size, bool grow);
};

struct Arr : _Mem_20a4
{
    unsigned int* __thiscall GetAt(int index);
};

struct FUN_00996ae0_node
{
    int m_00;
    int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    FUN_00996ae0_node* m_10;
};

struct FUN_00996ae0_class
{
    bool __thiscall ExtractNodeValues(FUN_00996ae0_node* node, Arr* array1, Arr* array2);
};

// Walks the linked list from node, sizes array1 to the node count and array2 to count-1, then fills them with each node's m_08 and m_0c values.
// @fnv 0x00996ae0
bool FUN_00996ae0_class::ExtractNodeValues(FUN_00996ae0_node* node, Arr* pValues, Arr* array2)
{
    if (node == 0)
    {
        return false;
    }

    int index = 0;
    FUN_00996ae0_node* current = node;
    int count;

    while (current != 0)
    {
        ++index;
        current = current->m_10;
    }

    pValues->SetSize(index, true);
    array2->SetSize(index - 1, true);

    current = node;
    count = index - 1;

    while (current != 0)
    {
        *pValues->GetAt(count) = current->m_08;

        if (count > 0)
        {
            *array2->GetAt(count - 1) = current->m_0c;
        }

        current = current->m_10;
        --count;
    }

    return true;
}

void __cdecl GetActorSlotExtent(unsigned int, unsigned int, unsigned int);

struct FUN_009800e0_cls
{
    int m_00;
    unsigned int GetFieldBC();
    void FUN_009800e0(unsigned int a1, unsigned int a2);
};

// Calls GetActorSlotExtent with the result of GetFieldBC() and the two arguments.
// @fnv 0x009800e0
void FUN_009800e0_cls::FUN_009800e0(unsigned int a1, unsigned int a2)
{
    GetActorSlotExtent(this->GetFieldBC(), a1, a2);
}

class FUN_00982480_A
{
  public:
    FUN_00982480_A();
    ~FUN_00982480_A();
    unsigned int unk00, unk04, unk08, unk0C;
};

class FUN_00982480_B
{
  public:
    FUN_00982480_B();
    ~FUN_00982480_B();
    unsigned int unk0000, unk0004, unk0008, unk000C, unk0010, unk0014, unk0018, unk001C, unk0020, unk0024, unk0028,
        unk002C, unk0030, unk0034, unk0038, unk003C;
    unsigned int unk0040, unk0044, unk0048, unk004C, unk0050, unk0054, unk0058, unk005C, unk0060, unk0064, unk0068,
        unk006C, unk0070, unk0074, unk0078, unk007C;
    unsigned int unk0080, unk0084, unk0088, unk008C, unk0090, unk0094, unk0098, unk009C, unk00A0, unk00A4, unk00A8,
        unk00AC, unk00B0, unk00B4, unk00B8, unk00BC;
    unsigned int unk00C0, unk00C4, unk00C8, unk00CC, unk00D0, unk00D4, unk00D8, unk00DC, unk00E0, unk00E4, unk00E8,
        unk00EC, unk00F0, unk00F4, unk00F8, unk00FC;
    unsigned int unk0100, unk0104, unk0108, unk010C, unk0110, unk0114, unk0118, unk011C, unk0120, unk0124, unk0128,
        unk012C, unk0130, unk0134, unk0138, unk013C;
    unsigned int unk0140, unk0144, unk0148, unk014C, unk0150, unk0154, unk0158, unk015C, unk0160, unk0164, unk0168,
        unk016C, unk0170, unk0174, unk0178, unk017C;
    unsigned int unk0180, unk0184, unk0188, unk018C, unk0190, unk0194, unk0198, unk019C, unk01A0, unk01A4, unk01A8,
        unk01AC, unk01B0, unk01B4, unk01B8, unk01BC;
    unsigned int unk01C0, unk01C4, unk01C8, unk01CC, unk01D0, unk01D4, unk01D8, unk01DC, unk01E0, unk01E4, unk01E8,
        unk01EC, unk01F0, unk01F4, unk01F8, unk01FC;
    unsigned int unk0200, unk0204, unk0208, unk020C, unk0210, unk0214, unk0218, unk021C, unk0220, unk0224, unk0228,
        unk022C, unk0230, unk0234, unk0238, unk023C;
    unsigned int unk0240, unk0244, unk0248, unk024C, unk0250, unk0254, unk0258, unk025C, unk0260, unk0264, unk0268,
        unk026C, unk0270, unk0274, unk0278, unk027C;
    unsigned int unk0280, unk0284, unk0288, unk028C, unk0290, unk0294, unk0298, unk029C, unk02A0, unk02A4, unk02A8,
        unk02AC, unk02B0, unk02B4, unk02B8, unk02BC;
    unsigned int unk02C0, unk02C4, unk02C8, unk02CC, unk02D0, unk02D4, unk02D8, unk02DC, unk02E0, unk02E4, unk02E8,
        unk02EC, unk02F0, unk02F4, unk02F8, unk02FC;
    unsigned int unk0300, unk0304, unk0308, unk030C, unk0310, unk0314, unk0318, unk031C, unk0320, unk0324, unk0328,
        unk032C, unk0330, unk0334, unk0338, unk033C;
    unsigned int unk0340, unk0344, unk0348, unk034C, unk0350, unk0354, unk0358, unk035C, unk0360, unk0364, unk0368,
        unk036C, unk0370, unk0374, unk0378, unk037C;
    unsigned int unk0380, unk0384, unk0388, unk038C, unk0390, unk0394, unk0398, unk039C, unk03A0, unk03A4, unk03A8,
        unk03AC, unk03B0, unk03B4, unk03B8, unk03BC;
    unsigned int unk03C0, unk03C4, unk03C8, unk03CC, unk03D0, unk03D4, unk03D8, unk03DC, unk03E0, unk03E4, unk03E8,
        unk03EC, unk03F0, unk03F4, unk03F8, unk03FC;
    unsigned int unk0400, unk0404, unk0408, unk040C, unk0410, unk0414, unk0418, unk041C, unk0420, unk0424, unk0428,
        unk042C, unk0430, unk0434, unk0438, unk043C;
    unsigned int unk0440, unk0444, unk0448, unk044C, unk0450, unk0454, unk0458, unk045C, unk0460, unk0464, unk0468,
        unk046C, unk0470, unk0474, unk0478, unk047C;
    unsigned int unk0480, unk0484, unk0488, unk048C, unk0490, unk0494, unk0498, unk049C, unk04A0, unk04A4, unk04A8,
        unk04AC, unk04B0, unk04B4, unk04B8, unk04BC;
    unsigned int unk04C0, unk04C4, unk04C8, unk04CC, unk04D0, unk04D4, unk04D8, unk04DC, unk04E0, unk04E4, unk04E8,
        unk04EC, unk04F0, unk04F4, unk04F8, unk04FC;
    unsigned int unk0500, unk0504, unk0508, unk050C, unk0510, unk0514, unk0518, unk051C, unk0520, unk0524, unk0528,
        unk052C, unk0530, unk0534, unk0538, unk053C;
    unsigned int unk0540, unk0544, unk0548, unk054C, unk0550, unk0554, unk0558, unk055C, unk0560, unk0564, unk0568,
        unk056C, unk0570, unk0574, unk0578, unk057C;
    unsigned int unk0580, unk0584, unk0588, unk058C, unk0590, unk0594, unk0598, unk059C, unk05A0, unk05A4, unk05A8,
        unk05AC, unk05B0, unk05B4, unk05B8, unk05BC;
    unsigned int unk05C0, unk05C4, unk05C8, unk05CC, unk05D0, unk05D4, unk05D8, unk05DC, unk05E0, unk05E4, unk05E8,
        unk05EC, unk05F0, unk05F4, unk05F8, unk05FC;
    unsigned int unk0600, unk0604, unk0608, unk060C, unk0610, unk0614, unk0618, unk061C, unk0620, unk0624, unk0628,
        unk062C, unk0630, unk0634, unk0638, unk063C;
    unsigned int unk0640, unk0644, unk0648, unk064C, unk0650, unk0654, unk0658, unk065C, unk0660, unk0664, unk0668,
        unk066C, unk0670, unk0674, unk0678, unk067C;
    unsigned int unk0680, unk0684, unk0688, unk068C, unk0690, unk0694, unk0698, unk069C, unk06A0, unk06A4, unk06A8,
        unk06AC, unk06B0, unk06B4, unk06B8, unk06BC;
    unsigned int unk06C0, unk06C4, unk06C8, unk06CC, unk06D0, unk06D4, unk06D8, unk06DC, unk06E0, unk06E4, unk06E8,
        unk06EC, unk06F0, unk06F4, unk06F8, unk06FC;
    unsigned int unk0700, unk0704, unk0708, unk070C, unk0710, unk0714, unk0718, unk071C, unk0720, unk0724, unk0728,
        unk072C, unk0730, unk0734, unk0738, unk073C;
    unsigned int unk0740, unk0744, unk0748, unk074C, unk0750, unk0754, unk0758, unk075C, unk0760, unk0764, unk0768,
        unk076C, unk0770, unk0774, unk0778, unk077C;
    unsigned int unk0780, unk0784, unk0788, unk078C, unk0790, unk0794, unk0798, unk079C, unk07A0, unk07A4, unk07A8,
        unk07AC, unk07B0, unk07B4, unk07B8, unk07BC;
    unsigned int unk07C0, unk07C4, unk07C8, unk07CC, unk07D0, unk07D4, unk07D8, unk07DC, unk07E0, unk07E4, unk07E8,
        unk07EC, unk07F0, unk07F4, unk07F8, unk07FC;
    unsigned int unk0800, unk0804, unk0808, unk080C, unk0810, unk0814, unk0818, unk081C, unk0820, unk0824, unk0828,
        unk082C, unk0830, unk0834, unk0838, unk083C;
    unsigned int unk0840, unk0844, unk0848, unk084C, unk0850, unk0854, unk0858, unk085C, unk0860, unk0864, unk0868,
        unk086C, unk0870, unk0874, unk0878, unk087C;
    unsigned int unk0880, unk0884, unk0888, unk088C, unk0890, unk0894, unk0898, unk089C, unk08A0, unk08A4, unk08A8,
        unk08AC, unk08B0, unk08B4, unk08B8, unk08BC;
    unsigned int unk08C0, unk08C4, unk08C8, unk08CC, unk08D0, unk08D4, unk08D8, unk08DC, unk08E0, unk08E4, unk08E8,
        unk08EC, unk08F0, unk08F4, unk08F8, unk08FC;
    unsigned int unk0900, unk0904, unk0908, unk090C, unk0910, unk0914, unk0918, unk091C, unk0920, unk0924, unk0928,
        unk092C, unk0930, unk0934, unk0938, unk093C;
    unsigned int unk0940, unk0944, unk0948, unk094C, unk0950, unk0954, unk0958, unk095C, unk0960, unk0964, unk0968,
        unk096C, unk0970, unk0974, unk0978, unk097C;
    unsigned int unk0980, unk0984, unk0988, unk098C, unk0990, unk0994, unk0998, unk099C, unk09A0, unk09A4, unk09A8,
        unk09AC, unk09B0, unk09B4, unk09B8, unk09BC;
    unsigned int unk09C0, unk09C4, unk09C8, unk09CC, unk09D0, unk09D4, unk09D8, unk09DC, unk09E0, unk09E4, unk09E8,
        unk09EC, unk09F0, unk09F4, unk09F8, unk09FC;
    unsigned int unk0A00, unk0A04, unk0A08, unk0A0C, unk0A10, unk0A14, unk0A18, unk0A1C, unk0A20, unk0A24, unk0A28,
        unk0A2C, unk0A30, unk0A34, unk0A38, unk0A3C;
    unsigned int unk0A40, unk0A44, unk0A48, unk0A4C, unk0A50, unk0A54, unk0A58, unk0A5C, unk0A60, unk0A64, unk0A68,
        unk0A6C, unk0A70, unk0A74, unk0A78, unk0A7C;
    unsigned int unk0A80, unk0A84, unk0A88, unk0A8C, unk0A90, unk0A94, unk0A98, unk0A9C, unk0AA0, unk0AA4, unk0AA8,
        unk0AAC, unk0AB0, unk0AB4, unk0AB8, unk0ABC;
    unsigned int unk0AC0, unk0AC4, unk0AC8, unk0ACC, unk0AD0, unk0AD4, unk0AD8, unk0ADC, unk0AE0, unk0AE4, unk0AE8,
        unk0AEC, unk0AF0, unk0AF4, unk0AF8, unk0AFC;
    unsigned int unk0B00, unk0B04, unk0B08, unk0B0C, unk0B10, unk0B14, unk0B18, unk0B1C, unk0B20, unk0B24, unk0B28,
        unk0B2C, unk0B30, unk0B34, unk0B38, unk0B3C;
    unsigned int unk0B40, unk0B44, unk0B48, unk0B4C, unk0B50, unk0B54, unk0B58, unk0B5C, unk0B60, unk0B64, unk0B68,
        unk0B6C, unk0B70, unk0B74, unk0B78, unk0B7C;
    unsigned int unk0B80, unk0B84, unk0B88, unk0B8C, unk0B90, unk0B94, unk0B98, unk0B9C, unk0BA0, unk0BA4, unk0BA8,
        unk0BAC, unk0BB0, unk0BB4, unk0BB8, unk0BBC;
    unsigned int unk0BC0, unk0BC4, unk0BC8, unk0BCC, unk0BD0, unk0BD4, unk0BD8, unk0BDC, unk0BE0, unk0BE4, unk0BE8,
        unk0BEC, unk0BF0, unk0BF4, unk0BF8, unk0BFC;
    unsigned int unk0C00, unk0C04, unk0C08, unk0C0C, unk0C10, unk0C14, unk0C18, unk0C1C, unk0C20, unk0C24, unk0C28,
        unk0C2C, unk0C30, unk0C34, unk0C38, unk0C3C;
    unsigned int unk0C40, unk0C44, unk0C48, unk0C4C, unk0C50, unk0C54, unk0C58, unk0C5C, unk0C60, unk0C64, unk0C68,
        unk0C6C, unk0C70, unk0C74, unk0C78, unk0C7C;
    unsigned int unk0C80, unk0C84, unk0C88, unk0C8C, unk0C90, unk0C94, unk0C98, unk0C9C, unk0CA0, unk0CA4, unk0CA8,
        unk0CAC, unk0CB0, unk0CB4, unk0CB8, unk0CBC;
    unsigned int unk0CC0, unk0CC4, unk0CC8, unk0CCC, unk0CD0, unk0CD4, unk0CD8, unk0CDC, unk0CE0, unk0CE4, unk0CE8,
        unk0CEC, unk0CF0, unk0CF4, unk0CF8, unk0CFC;
    unsigned int unk0D00, unk0D04, unk0D08, unk0D0C, unk0D10, unk0D14, unk0D18, unk0D1C, unk0D20, unk0D24, unk0D28,
        unk0D2C, unk0D30, unk0D34, unk0D38, unk0D3C;
    unsigned int unk0D40, unk0D44, unk0D48, unk0D4C, unk0D50, unk0D54, unk0D58, unk0D5C, unk0D60, unk0D64, unk0D68,
        unk0D6C, unk0D70, unk0D74, unk0D78, unk0D7C;
    unsigned int unk0D80, unk0D84, unk0D88, unk0D8C, unk0D90, unk0D94, unk0D98, unk0D9C, unk0DA0, unk0DA4, unk0DA8,
        unk0DAC, unk0DB0, unk0DB4, unk0DB8, unk0DBC;
    unsigned int unk0DC0, unk0DC4, unk0DC8, unk0DCC, unk0DD0, unk0DD4, unk0DD8, unk0DDC, unk0DE0, unk0DE4, unk0DE8,
        unk0DEC, unk0DF0, unk0DF4, unk0DF8, unk0DFC;
    unsigned int unk0E00, unk0E04, unk0E08, unk0E0C, unk0E10, unk0E14, unk0E18, unk0E1C, unk0E20, unk0E24, unk0E28,
        unk0E2C, unk0E30, unk0E34, unk0E38, unk0E3C;
    unsigned int unk0E40, unk0E44, unk0E48, unk0E4C, unk0E50, unk0E54, unk0E58, unk0E5C, unk0E60, unk0E64, unk0E68,
        unk0E6C, unk0E70, unk0E74, unk0E78, unk0E7C;
    unsigned int unk0E80, unk0E84, unk0E88, unk0E8C, unk0E90, unk0E94, unk0E98, unk0E9C, unk0EA0, unk0EA4, unk0EA8,
        unk0EAC, unk0EB0, unk0EB4, unk0EB8, unk0EBC;
    unsigned int unk0EC0, unk0EC4, unk0EC8, unk0ECC, unk0ED0, unk0ED4, unk0ED8, unk0EDC, unk0EE0, unk0EE4, unk0EE8,
        unk0EEC, unk0EF0, unk0EF4, unk0EF8, unk0EFC;
    unsigned int unk0F00, unk0F04, unk0F08, unk0F0C, unk0F10, unk0F14, unk0F18, unk0F1C, unk0F20, unk0F24, unk0F28,
        unk0F2C, unk0F30, unk0F34, unk0F38, unk0F3C;
    unsigned int unk0F40, unk0F44, unk0F48, unk0F4C, unk0F50, unk0F54, unk0F58, unk0F5C, unk0F60, unk0F64, unk0F68,
        unk0F6C, unk0F70, unk0F74, unk0F78, unk0F7C;
    unsigned int unk0F80, unk0F84, unk0F88, unk0F8C, unk0F90, unk0F94, unk0F98, unk0F9C, unk0FA0, unk0FA4, unk0FA8,
        unk0FAC, unk0FB0, unk0FB4, unk0FB8, unk0FBC;
    unsigned int unk0FC0, unk0FC4, unk0FC8, unk0FCC, unk0FD0, unk0FD4, unk0FD8, unk0FDC, unk0FE0, unk0FE4, unk0FE8,
        unk0FEC, unk0FF0, unk0FF4, unk0FF8, unk0FFC;
    unsigned int unk1000, unk1004, unk1008, unk100C, unk1010, unk1014, unk1018, unk101C, unk1020, unk1024, unk1028,
        unk102C, unk1030, unk1034, unk1038, unk103C;
    unsigned int unk1040, unk1044, unk1048, unk104C, unk1050, unk1054, unk1058, unk105C, unk1060, unk1064, unk1068,
        unk106C, unk1070, unk1074, unk1078, unk107C;
    unsigned int unk1080, unk1084, unk1088, unk108C, unk1090, unk1094, unk1098, unk109C, unk10A0, unk10A4, unk10A8,
        unk10AC, unk10B0, unk10B4, unk10B8, unk10BC;
    unsigned int unk10C0, unk10C4, unk10C8, unk10CC, unk10D0, unk10D4, unk10D8, unk10DC, unk10E0, unk10E4, unk10E8,
        unk10EC, unk10F0, unk10F4, unk10F8, unk10FC;
    unsigned int unk1100, unk1104, unk1108, unk110C, unk1110, unk1114, unk1118, unk111C, unk1120, unk1124, unk1128,
        unk112C, unk1130, unk1134, unk1138, unk113C;
    unsigned int unk1140, unk1144, unk1148, unk114C, unk1150, unk1154, unk1158, unk115C, unk1160, unk1164, unk1168,
        unk116C, unk1170, unk1174, unk1178, unk117C;
    unsigned int unk1180, unk1184, unk1188, unk118C, unk1190, unk1194, unk1198, unk119C, unk11A0, unk11A4, unk11A8,
        unk11AC, unk11B0, unk11B4, unk11B8, unk11BC;
    unsigned int unk11C0, unk11C4, unk11C8, unk11CC, unk11D0, unk11D4, unk11D8, unk11DC, unk11E0, unk11E4, unk11E8,
        unk11EC, unk11F0, unk11F4, unk11F8, unk11FC;
    unsigned int unk1200, unk1204, unk1208, unk120C, unk1210, unk1214, unk1218, unk121C, unk1220, unk1224, unk1228,
        unk122C, unk1230, unk1234, unk1238, unk123C;
    unsigned int unk1240, unk1244, unk1248, unk124C, unk1250, unk1254, unk1258, unk125C, unk1260, unk1264, unk1268,
        unk126C, unk1270, unk1274, unk1278, unk127C;
    unsigned int unk1280, unk1284, unk1288, unk128C, unk1290, unk1294, unk1298, unk129C, unk12A0, unk12A4, unk12A8,
        unk12AC, unk12B0, unk12B4, unk12B8, unk12BC;
    unsigned int unk12C0, unk12C4, unk12C8, unk12CC, unk12D0, unk12D4, unk12D8, unk12DC, unk12E0, unk12E4, unk12E8,
        unk12EC, unk12F0, unk12F4, unk12F8, unk12FC;
    unsigned int unk1300, unk1304, unk1308, unk130C, unk1310, unk1314, unk1318, unk131C, unk1320, unk1324, unk1328,
        unk132C, unk1330, unk1334, unk1338, unk133C;
    unsigned int unk1340, unk1344, unk1348, unk134C, unk1350, unk1354, unk1358, unk135C, unk1360, unk1364, unk1368,
        unk136C, unk1370, unk1374, unk1378, unk137C;
    unsigned int unk1380, unk1384, unk1388, unk138C, unk1390, unk1394, unk1398, unk139C, unk13A0, unk13A4, unk13A8,
        unk13AC, unk13B0, unk13B4, unk13B8, unk13BC;
    unsigned int unk13C0, unk13C4, unk13C8, unk13CC, unk13D0, unk13D4, unk13D8, unk13DC, unk13E0, unk13E4, unk13E8,
        unk13EC, unk13F0, unk13F4, unk13F8, unk13FC;
    unsigned int unk1400, unk1404, unk1408, unk140C, unk1410, unk1414, unk1418, unk141C, unk1420, unk1424, unk1428,
        unk142C, unk1430, unk1434, unk1438, unk143C;
    unsigned int unk1440, unk1444, unk1448, unk144C, unk1450, unk1454, unk1458, unk145C, unk1460, unk1464, unk1468,
        unk146C, unk1470, unk1474, unk1478, unk147C;
    unsigned int unk1480, unk1484, unk1488, unk148C, unk1490, unk1494, unk1498, unk149C, unk14A0, unk14A4, unk14A8,
        unk14AC, unk14B0, unk14B4, unk14B8, unk14BC;
    unsigned int unk14C0, unk14C4, unk14C8, unk14CC, unk14D0, unk14D4, unk14D8, unk14DC, unk14E0, unk14E4, unk14E8,
        unk14EC, unk14F0, unk14F4, unk14F8, unk14FC;
    unsigned int unk1500, unk1504, unk1508, unk150C, unk1510, unk1514, unk1518, unk151C, unk1520, unk1524, unk1528,
        unk152C, unk1530, unk1534, unk1538, unk153C;
    unsigned int unk1540, unk1544, unk1548, unk154C, unk1550, unk1554, unk1558, unk155C, unk1560, unk1564, unk1568,
        unk156C, unk1570, unk1574, unk1578, unk157C;
    unsigned int unk1580, unk1584, unk1588, unk158C, unk1590, unk1594, unk1598, unk159C, unk15A0, unk15A4, unk15A8,
        unk15AC, unk15B0, unk15B4, unk15B8, unk15BC;
    unsigned int unk15C0, unk15C4, unk15C8, unk15CC, unk15D0, unk15D4, unk15D8, unk15DC, unk15E0, unk15E4, unk15E8,
        unk15EC, unk15F0, unk15F4, unk15F8, unk15FC;
    unsigned int unk1600, unk1604, unk1608, unk160C, unk1610, unk1614, unk1618, unk161C, unk1620, unk1624, unk1628,
        unk162C, unk1630, unk1634, unk1638, unk163C;
    unsigned int unk1640, unk1644, unk1648, unk164C, unk1650, unk1654, unk1658, unk165C, unk1660, unk1664, unk1668,
        unk166C, unk1670, unk1674, unk1678, unk167C;
    unsigned int unk1680, unk1684, unk1688, unk168C, unk1690, unk1694, unk1698, unk169C, unk16A0, unk16A4, unk16A8,
        unk16AC, unk16B0, unk16B4, unk16B8, unk16BC;
    unsigned int unk16C0, unk16C4, unk16C8, unk16CC, unk16D0, unk16D4, unk16D8, unk16DC, unk16E0, unk16E4, unk16E8,
        unk16EC, unk16F0, unk16F4, unk16F8, unk16FC;
    unsigned int unk1700, unk1704, unk1708, unk170C, unk1710, unk1714, unk1718, unk171C, unk1720, unk1724, unk1728,
        unk172C, unk1730, unk1734, unk1738, unk173C;
    unsigned int unk1740, unk1744, unk1748, unk174C, unk1750, unk1754, unk1758, unk175C, unk1760, unk1764, unk1768,
        unk176C, unk1770, unk1774, unk1778, unk177C;
    unsigned int unk1780, unk1784, unk1788, unk178C, unk1790, unk1794, unk1798, unk179C, unk17A0, unk17A4, unk17A8,
        unk17AC, unk17B0, unk17B4, unk17B8, unk17BC;
    unsigned int unk17C0, unk17C4, unk17C8, unk17CC, unk17D0, unk17D4, unk17D8, unk17DC, unk17E0, unk17E4, unk17E8,
        unk17EC, unk17F0, unk17F4, unk17F8, unk17FC;
    unsigned int unk1800, unk1804, unk1808, unk180C, unk1810, unk1814, unk1818, unk181C, unk1820, unk1824, unk1828,
        unk182C, unk1830, unk1834, unk1838, unk183C;
    unsigned int unk1840, unk1844, unk1848, unk184C, unk1850, unk1854, unk1858, unk185C, unk1860, unk1864, unk1868,
        unk186C, unk1870, unk1874, unk1878, unk187C;
    unsigned int unk1880, unk1884, unk1888, unk188C, unk1890, unk1894, unk1898, unk189C, unk18A0, unk18A4, unk18A8,
        unk18AC, unk18B0, unk18B4, unk18B8, unk18BC;
    unsigned int unk18C0, unk18C4, unk18C8, unk18CC, unk18D0, unk18D4, unk18D8, unk18DC, unk18E0, unk18E4, unk18E8,
        unk18EC, unk18F0, unk18F4, unk18F8, unk18FC;
    unsigned int unk1900, unk1904, unk1908, unk190C, unk1910, unk1914, unk1918, unk191C, unk1920, unk1924, unk1928,
        unk192C, unk1930, unk1934, unk1938, unk193C;
    unsigned int unk1940, unk1944, unk1948, unk194C, unk1950, unk1954, unk1958, unk195C, unk1960, unk1964, unk1968,
        unk196C, unk1970, unk1974, unk1978, unk197C;
    unsigned int unk1980, unk1984, unk1988, unk198C, unk1990, unk1994, unk1998, unk199C, unk19A0, unk19A4, unk19A8,
        unk19AC, unk19B0, unk19B4, unk19B8, unk19BC;
    unsigned int unk19C0, unk19C4, unk19C8, unk19CC, unk19D0, unk19D4, unk19D8, unk19DC, unk19E0, unk19E4, unk19E8,
        unk19EC, unk19F0, unk19F4, unk19F8, unk19FC;
    unsigned int unk1A00, unk1A04, unk1A08, unk1A0C, unk1A10, unk1A14, unk1A18, unk1A1C, unk1A20, unk1A24, unk1A28,
        unk1A2C, unk1A30, unk1A34, unk1A38, unk1A3C;
    unsigned int unk1A40, unk1A44, unk1A48, unk1A4C, unk1A50, unk1A54, unk1A58, unk1A5C, unk1A60, unk1A64, unk1A68,
        unk1A6C, unk1A70, unk1A74, unk1A78, unk1A7C;
    unsigned int unk1A80, unk1A84, unk1A88, unk1A8C, unk1A90, unk1A94, unk1A98, unk1A9C, unk1AA0, unk1AA4, unk1AA8,
        unk1AAC, unk1AB0, unk1AB4, unk1AB8, unk1ABC;
    unsigned int unk1AC0, unk1AC4, unk1AC8, unk1ACC, unk1AD0, unk1AD4, unk1AD8, unk1ADC, unk1AE0, unk1AE4, unk1AE8,
        unk1AEC, unk1AF0, unk1AF4, unk1AF8, unk1AFC;
    unsigned int unk1B00, unk1B04, unk1B08, unk1B0C, unk1B10, unk1B14, unk1B18, unk1B1C, unk1B20, unk1B24, unk1B28,
        unk1B2C, unk1B30, unk1B34, unk1B38, unk1B3C;
    unsigned int unk1B40, unk1B44, unk1B48, unk1B4C, unk1B50, unk1B54, unk1B58, unk1B5C, unk1B60, unk1B64, unk1B68,
        unk1B6C, unk1B70, unk1B74, unk1B78, unk1B7C;
    unsigned int unk1B80, unk1B84, unk1B88, unk1B8C, unk1B90, unk1B94, unk1B98, unk1B9C, unk1BA0, unk1BA4, unk1BA8,
        unk1BAC, unk1BB0, unk1BB4, unk1BB8, unk1BBC;
    unsigned int unk1BC0, unk1BC4, unk1BC8, unk1BCC, unk1BD0, unk1BD4, unk1BD8, unk1BDC, unk1BE0, unk1BE4, unk1BE8,
        unk1BEC, unk1BF0, unk1BF4, unk1BF8, unk1BFC;
    unsigned int unk1C00, unk1C04, unk1C08, unk1C0C, unk1C10, unk1C14, unk1C18, unk1C1C, unk1C20, unk1C24, unk1C28,
        unk1C2C, unk1C30, unk1C34, unk1C38, unk1C3C;
    unsigned int unk1C40, unk1C44, unk1C48, unk1C4C, unk1C50, unk1C54, unk1C58, unk1C5C, unk1C60, unk1C64, unk1C68,
        unk1C6C, unk1C70, unk1C74, unk1C78, unk1C7C;
    unsigned int unk1C80, unk1C84, unk1C88, unk1C8C, unk1C90, unk1C94, unk1C98, unk1C9C, unk1CA0, unk1CA4, unk1CA8,
        unk1CAC, unk1CB0, unk1CB4, unk1CB8, unk1CBC;
    unsigned int unk1CC0, unk1CC4, unk1CC8, unk1CCC, unk1CD0, unk1CD4, unk1CD8, unk1CDC, unk1CE0, unk1CE4, unk1CE8,
        unk1CEC, unk1CF0, unk1CF4, unk1CF8, unk1CFC;
    unsigned int unk1D00, unk1D04, unk1D08, unk1D0C, unk1D10, unk1D14, unk1D18, unk1D1C, unk1D20, unk1D24, unk1D28,
        unk1D2C, unk1D30, unk1D34, unk1D38, unk1D3C;
    unsigned int unk1D40, unk1D44, unk1D48, unk1D4C, unk1D50, unk1D54, unk1D58, unk1D5C, unk1D60, unk1D64, unk1D68,
        unk1D6C, unk1D70, unk1D74, unk1D78, unk1D7C;
    unsigned int unk1D80, unk1D84, unk1D88, unk1D8C, unk1D90, unk1D94, unk1D98, unk1D9C, unk1DA0, unk1DA4, unk1DA8,
        unk1DAC, unk1DB0, unk1DB4, unk1DB8, unk1DBC;
    unsigned int unk1DC0, unk1DC4, unk1DC8, unk1DCC, unk1DD0, unk1DD4, unk1DD8, unk1DDC, unk1DE0, unk1DE4, unk1DE8,
        unk1DEC, unk1DF0, unk1DF4, unk1DF8, unk1DFC;
    unsigned int unk1E00, unk1E04, unk1E08, unk1E0C, unk1E10, unk1E14, unk1E18, unk1E1C, unk1E20, unk1E24, unk1E28,
        unk1E2C, unk1E30, unk1E34, unk1E38, unk1E3C;
    unsigned int unk1E40, unk1E44, unk1E48, unk1E4C, unk1E50, unk1E54, unk1E58, unk1E5C, unk1E60, unk1E64, unk1E68,
        unk1E6C, unk1E70, unk1E74, unk1E78, unk1E7C;
    unsigned int unk1E80, unk1E84, unk1E88, unk1E8C, unk1E90, unk1E94, unk1E98, unk1E9C, unk1EA0, unk1EA4, unk1EA8,
        unk1EAC, unk1EB0, unk1EB4, unk1EB8, unk1EBC;
    unsigned int unk1EC0, unk1EC4, unk1EC8, unk1ECC, unk1ED0, unk1ED4, unk1ED8, unk1EDC, unk1EE0, unk1EE4, unk1EE8,
        unk1EEC, unk1EF0, unk1EF4, unk1EF8, unk1EFC;
    unsigned int unk1F00, unk1F04, unk1F08, unk1F0C, unk1F10, unk1F14, unk1F18, unk1F1C, unk1F20, unk1F24, unk1F28,
        unk1F2C, unk1F30, unk1F34, unk1F38, unk1F3C;
    unsigned int unk1F40, unk1F44, unk1F48, unk1F4C, unk1F50, unk1F54, unk1F58, unk1F5C, unk1F60, unk1F64, unk1F68,
        unk1F6C, unk1F70, unk1F74, unk1F78, unk1F7C;
    unsigned int unk1F80, unk1F84, unk1F88, unk1F8C, unk1F90, unk1F94, unk1F98, unk1F9C, unk1FA0, unk1FA4, unk1FA8,
        unk1FAC, unk1FB0, unk1FB4, unk1FB8, unk1FBC;
    unsigned int unk1FC0, unk1FC4, unk1FC8, unk1FCC, unk1FD0, unk1FD4, unk1FD8, unk1FDC;
};

class FUN_00982480_C
{
  public:
    FUN_00982480_C();
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14;
    unsigned int unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned int unk40, unk44, unk48, unk4C, unk50;
};

class FUN_00982480_cls
{
  public:
    virtual void v00();
    FUN_00982480_A m_04;
    FUN_00982480_B m_14;
    FUN_00982480_C m_1ff4;
    unsigned int m_2048;
    unsigned int m_204c;
    unsigned int m_2050;
    unsigned char m_2054;

    FUN_00982480_cls();
};

// Initializes m_2048, m_204c, m_2050 and m_2054 to zero.
// @fnv 0x00982480
FUN_00982480_cls::FUN_00982480_cls()
{
    m_2048 = 0;
    m_204c = 0;
    m_2050 = 0;
    m_2054 = 0;
}

// 64-byte padding block with named dwords.
struct FUN_00982530_pad64
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
};

// Non-trivial member type (dtor only), 4 bytes.
struct FUN_00982530_item
{
    int unk00;
    ~FUN_00982530_item();
};

// Non-trivial base, 0x10 bytes, placed at +4 after the vptr.
struct FUN_00982530_base
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    ~FUN_00982530_base();
};

class FUN_00982530_cls : public FUN_00982530_base
{
  public:
    FUN_00982530_item m_14;
    FUN_00982530_pad64 unk18;
    FUN_00982530_pad64 unk58;
    FUN_00982530_pad64 unk98;
    FUN_00982530_pad64 unkD8;
    FUN_00982530_pad64 unk118;
    FUN_00982530_pad64 unk158;
    FUN_00982530_pad64 unk198;
    FUN_00982530_pad64 unk1D8;
    FUN_00982530_pad64 unk218;
    FUN_00982530_pad64 unk258;
    FUN_00982530_pad64 unk298;
    FUN_00982530_pad64 unk2D8;
    FUN_00982530_pad64 unk318;
    FUN_00982530_pad64 unk358;
    FUN_00982530_pad64 unk398;
    FUN_00982530_pad64 unk3D8;
    FUN_00982530_pad64 unk418;
    FUN_00982530_pad64 unk458;
    FUN_00982530_pad64 unk498;
    FUN_00982530_pad64 unk4D8;
    FUN_00982530_pad64 unk518;
    FUN_00982530_pad64 unk558;
    FUN_00982530_pad64 unk598;
    FUN_00982530_pad64 unk5D8;
    FUN_00982530_pad64 unk618;
    FUN_00982530_pad64 unk658;
    FUN_00982530_pad64 unk698;
    FUN_00982530_pad64 unk6D8;
    FUN_00982530_pad64 unk718;
    FUN_00982530_pad64 unk758;
    FUN_00982530_pad64 unk798;
    FUN_00982530_pad64 unk7D8;
    FUN_00982530_pad64 unk818;
    FUN_00982530_pad64 unk858;
    FUN_00982530_pad64 unk898;
    FUN_00982530_pad64 unk8D8;
    FUN_00982530_pad64 unk918;
    FUN_00982530_pad64 unk958;
    FUN_00982530_pad64 unk998;
    FUN_00982530_pad64 unk9D8;
    FUN_00982530_pad64 unkA18;
    FUN_00982530_pad64 unkA58;
    FUN_00982530_pad64 unkA98;
    FUN_00982530_pad64 unkAD8;
    FUN_00982530_pad64 unkB18;
    FUN_00982530_pad64 unkB58;
    FUN_00982530_pad64 unkB98;
    FUN_00982530_pad64 unkBD8;
    FUN_00982530_pad64 unkC18;
    FUN_00982530_pad64 unkC58;
    FUN_00982530_pad64 unkC98;
    FUN_00982530_pad64 unkCD8;
    FUN_00982530_pad64 unkD18;
    FUN_00982530_pad64 unkD58;
    FUN_00982530_pad64 unkD98;
    FUN_00982530_pad64 unkDD8;
    FUN_00982530_pad64 unkE18;
    FUN_00982530_pad64 unkE58;
    FUN_00982530_pad64 unkE98;
    FUN_00982530_pad64 unkED8;
    FUN_00982530_pad64 unkF18;
    FUN_00982530_pad64 unkF58;
    FUN_00982530_pad64 unkF98;
    FUN_00982530_pad64 unkFD8;
    FUN_00982530_pad64 unk1018;
    FUN_00982530_pad64 unk1058;
    FUN_00982530_pad64 unk1098;
    FUN_00982530_pad64 unk10D8;
    FUN_00982530_pad64 unk1118;
    FUN_00982530_pad64 unk1158;
    FUN_00982530_pad64 unk1198;
    FUN_00982530_pad64 unk11D8;
    FUN_00982530_pad64 unk1218;
    FUN_00982530_pad64 unk1258;
    FUN_00982530_pad64 unk1298;
    FUN_00982530_pad64 unk12D8;
    FUN_00982530_pad64 unk1318;
    FUN_00982530_pad64 unk1358;
    FUN_00982530_pad64 unk1398;
    FUN_00982530_pad64 unk13D8;
    FUN_00982530_pad64 unk1418;
    FUN_00982530_pad64 unk1458;
    FUN_00982530_pad64 unk1498;
    FUN_00982530_pad64 unk14D8;
    FUN_00982530_pad64 unk1518;
    FUN_00982530_pad64 unk1558;
    FUN_00982530_pad64 unk1598;
    FUN_00982530_pad64 unk15D8;
    FUN_00982530_pad64 unk1618;
    FUN_00982530_pad64 unk1658;
    FUN_00982530_pad64 unk1698;
    FUN_00982530_pad64 unk16D8;
    FUN_00982530_pad64 unk1718;
    FUN_00982530_pad64 unk1758;
    FUN_00982530_pad64 unk1798;
    FUN_00982530_pad64 unk17D8;
    FUN_00982530_pad64 unk1818;
    FUN_00982530_pad64 unk1858;
    FUN_00982530_pad64 unk1898;
    FUN_00982530_pad64 unk18D8;
    FUN_00982530_pad64 unk1918;
    FUN_00982530_pad64 unk1958;
    FUN_00982530_pad64 unk1998;
    FUN_00982530_pad64 unk19D8;
    FUN_00982530_pad64 unk1A18;
    FUN_00982530_pad64 unk1A58;
    FUN_00982530_pad64 unk1A98;
    FUN_00982530_pad64 unk1AD8;
    FUN_00982530_pad64 unk1B18;
    FUN_00982530_pad64 unk1B58;
    FUN_00982530_pad64 unk1B98;
    FUN_00982530_pad64 unk1BD8;
    FUN_00982530_pad64 unk1C18;
    FUN_00982530_pad64 unk1C58;
    FUN_00982530_pad64 unk1C98;
    FUN_00982530_pad64 unk1CD8;
    FUN_00982530_pad64 unk1D18;
    FUN_00982530_pad64 unk1D58;
    FUN_00982530_pad64 unk1D98;
    FUN_00982530_pad64 unk1DD8;
    FUN_00982530_pad64 unk1E18;
    FUN_00982530_pad64 unk1E58;
    FUN_00982530_pad64 unk1E98;
    FUN_00982530_pad64 unk1ED8;
    FUN_00982530_pad64 unk1F18;
    FUN_00982530_pad64 unk1F58;
    FUN_00982530_pad64 unk1F98;
    int unk1FD8;
    int unk1FDC;
    int unk1FE0;
    int unk1FE4;
    int unk1FE8;
    int unk1FEC;
    int unk1FF0;
    FUN_00982530_item m_1ff4;
    virtual ~FUN_00982530_cls();
};

// Destructor for the class; the body is empty and member destructors run implicitly.
// @fnv 0x00982530
FUN_00982530_cls::~FUN_00982530_cls()
{}

struct FUN_00982be0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
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
    unsigned short unk4C;
    unsigned char m_4E;
    unsigned char FUN_006e4820();
    unsigned char FUN_00982be0();
};

// Returns 1 when m_4E is non-zero and FUN_006e4820 returns 0, otherwise 0.
// @fnv 0x00982be0
unsigned char FUN_00982be0_cls::FUN_00982be0()
{
    return (this->m_4E != 0 && FUN_006e4820() == 0) ? 1 : 0;
}

struct FUN_0044ddc0_Class
{
    unsigned int FUN_0044ddc0();
};
struct FUN_00982e70_Temporary
{
    int item;
    void* context;
    FUN_00982e70_Temporary* FUN_004b0680(int item, void* context);
};
struct FUN_00982e70_Class
{
    void InsertAtEnd(FUN_00982e70_Temporary* value);
    void AddItem(int item, void* context);
};
// @fnv 0x00982e70
void FUN_00982e70_Class::AddItem(int item, void* context)
{
    for (unsigned int index = 0; index < ((FUN_0044ddc0_Class*)this)->FUN_0044ddc0(); ++index)
    {
        int* entry = (int*)((FUN_00844160_shell*)this)->FUN_00844160(index);
        if (*entry == item)
        {
            return;
        }
    }
    if (!*((unsigned char*)this + 0x15))
    {
        ((FUN_00982f10*)this)->Set((const char*)context + 0x70);
    }
    unsigned int flags = ((FUN_00982b90_class*)((char*)context + 0x70))->ComputeBitMask();
    *((unsigned int*)((char*)this + 0x10)) |= flags;
    {
        FUN_00982e70_Temporary temporary;
        InsertAtEnd(temporary.FUN_004b0680(item, context));
    }
}

struct SlotRecord
{
    int key;
};

struct EventToken
{
    unsigned int ComputeBitMask();
};

struct EventData
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
    EventToken token;
};

struct ChangePacket
{
    int sourceKey;
    int eventKind;
    ChangePacket* FUN_004b0680(int key, EventData* event);
};

struct EventRegistry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned int usedFlags;
    unsigned char unk14;
    unsigned char initialized;
    unsigned int FUN_0044ddc0();
    SlotRecord* FUN_00844160(unsigned int index);
    void FUN_00982f10(EventToken* token);
    void InsertAtEnd(ChangePacket* packet);
    bool RegisterEvent(int key, EventData* event);
};

// @fnv 0x00982f40
bool EventRegistry::RegisterEvent(int key, EventData* event)
{
    for (unsigned int index = 0; index < FUN_0044ddc0(); ++index)
    {
        SlotRecord* item = FUN_00844160(index);
        if (item->key == key)
            return false;
    }

    if (!initialized)
        FUN_00982f10(&event->token);

    unsigned int flags = event->token.ComputeBitMask();
    if (usedFlags & flags)
        return false;

    usedFlags |= flags;
    {
        ChangePacket packet;
        InsertAtEnd(packet.FUN_004b0680(key, event));
    }
    return true;
}

struct FUN_00982ff0_Item
{
    unsigned int m_000;
};

class FUN_00982ff0_cls
{
  public:
    unsigned int m_000;
    unsigned int m_004;
    unsigned int m_008;
    unsigned int m_00c;
    unsigned int m_010;

    unsigned int GetCount();
    FUN_00982ff0_Item* GetItem(unsigned int index);
    void FUN_00983720(unsigned int index, int flag);

    bool FUN_00982ff0(unsigned int id, void* arg);
};

// @fnv 0x00982ff0
bool FUN_00982ff0_cls::FUN_00982ff0(unsigned int id, void* arg)
{
    unsigned int count = GetCount();
    for (unsigned int i = 0; i < count; i++)
    {
        FUN_00982ff0_Item* item = GetItem(i);
        if (item->m_000 == id)
        {
            if (count == 1)
            {
                return true;
            }
            else
            {
                m_010 &= ~reinterpret_cast<FUN_00982b90_class*>((char*)arg + 0x70)->ComputeBitMask();
                FUN_00983720(i, 1);
            }
            return false;
        }
    }
    return false;
}

class B83080Base
{
  public:
    B83080Base(int iType);
    virtual ~B83080Base();
    int unk04;
    int unk08;
    int unk0C;
};

class S4ee810
{
  public:
    S4ee810(int iValue);
    ~S4ee810();
    int unk00;
};

class PMX
{
  public:
    PMX();
    int unk00;
};

class FUN_00983080 : public B83080Base
{
  public:
    FUN_00983080();
    virtual ~FUN_00983080();

    S4ee810 m_kHandle;
    PMX m_kData;
};

// Constructs the object: initializes the B83080Base base with type 0x25 and the m_kHandle member with 0.
// @fnv 0x00983080
FUN_00983080::FUN_00983080() : B83080Base(0x25), m_kHandle(0)
{}

struct GroupStamp
{
    unsigned int value;
    GroupStamp(float value);
    float FUN_006a7f50();
};
struct GroupTimer
{
    unsigned int unk00, unk04;
    void FUN_008d7f40(float value);
};
struct GroupSetting
{
    float* FUN_00403e20();
};
extern GroupSetting g_011cf870, g_011ce35c, g_011cf24c;
extern float DAT_01016248, DAT_0108d540;
float FUN_00435dd0();
float RandomFloat(float low, float high);
struct GroupMember
{
    void* actor;
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
    unsigned short flags, unk4a;
    unsigned int unk4c;
    GroupStamp first;
    unsigned int unk54;
    GroupStamp second;
};
struct GroupReset
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
    GroupTimer timer58, timer60;
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
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int state, unkd4;
    GroupTimer timerd8, timere0;
    GroupStamp stamp;
    unsigned int FUN_005a4320();
    void UpdateExpiringPositions();
    void UpdateCenter();
    void CollectNearbyRefs();
    GroupMember* FUN_009871c0(unsigned int index);
    void FUN_0098add0();
};
// @fnv 0x0098add0
void GroupReset::FUN_0098add0()
{
    unsigned int memberCount16 = FUN_005a4320();
    UpdateExpiringPositions();
    UpdateCenter();
    CollectNearbyRefs();
    state = 1;
    timerd8.FUN_008d7f40(DAT_01016248);
    timere0.FUN_008d7f40(*g_011cf870.FUN_00403e20());
    stamp = FUN_00435dd0();
    GroupStamp primaryScoreT = -DAT_0108d540;
    GroupStamp fallback = -DAT_0108d540;
    void* primaryActorS = 0;
    void* secondaryActorU = 0;
    for (unsigned int index = 0; index < memberCount16; ++index)
    {
        GroupMember* member = FUN_009871c0(index);
        member->flags = 0;
        if (member->first.FUN_006a7f50() > primaryScoreT.FUN_006a7f50())
        {
            primaryScoreT = member->first;
            primaryActorS = member->actor;
        }
        else if (member->second.FUN_006a7f50() > fallback.FUN_006a7f50())
        {
            fallback = member->second;
            secondaryActorU = member->actor;
        }
    }
    timer58.FUN_008d7f40(RandomFloat(*g_011cf24c.FUN_00403e20(), *g_011ce35c.FUN_00403e20()));
    timer60.FUN_008d7f40(RandomFloat(*g_011cf24c.FUN_00403e20(), *g_011ce35c.FUN_00403e20()));
}

struct FNVSettingValue
{
    float* GetValue();
};

struct FNVParamTarget
{
    int GetKind();
};

struct FNVParamOwner
{
    FNVParamTarget* GetTarget();
};

struct FNVHost_b9027
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
    int unkC4;
    int unkC8;
    int unkCC;
    unsigned int m_d0;
    void GetParamValues(FNVParamOwner* owner, float* outA, float* outB);
};

extern FNVSettingValue* DAT_011a4d38[][3];

// Selects a setting row from DAT_011a4d38 based on the owner's target kind and m_d0, then writes two setting values to outA and outB.
// @fnv 0x0098b070
void FNVHost_b9027::GetParamValues(FNVParamOwner* owner, float* outA, float* outB)
{
    int idx = (owner->GetTarget() != 0 && owner->GetTarget()->GetKind() == 0x39) ? 0 : 1;
    int col = (m_d0 >= 2) ? 1 : 0;
    *outA = *DAT_011a4d38[idx][col]->GetValue();
    *outB = *DAT_011a4d38[idx][col + 1]->GetValue();
}

extern float _DAT_0108d540;

struct FUN_0098bae0_Sub_d4
{
    int unk00;
    void FUN_0066b0d0(int a);
};
struct FUN_0098bae0_Sub_d8
{
    int unk00;
    void FUN_00910b10();
};
struct FUN_0098bae0_Sub_f0
{
    int unk00;
    void FUN_0098bbc0();
};
struct FUN_0098bae0_Sub_110
{
    int unk00;
    void FUN_008454f0(int a);
};
struct FUN_0098bae0_Tmp4
{
    int value;
    FUN_0098bae0_Tmp4(float f);
};

struct FUN_0098bae0_cls
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
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int m_d0;
    FUN_0098bae0_Sub_d4 m_d4;
    FUN_0098bae0_Sub_d8 m_d8;
    int unkdc;
    FUN_0098bae0_Sub_d8 m_e0;
    int unke4;
    int m_e8;
    int unkec;
    FUN_0098bae0_Sub_f0 m_f0;
    int unkf4;
    int unkf8;
    int unkfc;
    NiPoint3 m_100;
    float m_10c;
    FUN_0098bae0_Sub_110 m_110;
    int unk114;
    int unk118;
    int unk11c;
    FUN_0098bae0_Sub_110 m_120;
    int unk124;
    int unk128;
    int unk12c;
    FUN_0098bae0_Sub_d4 m_130;
    unsigned char m_134;
    int unk135;
    void FUN_0098bae0();
};

// @fnv 0x0098bae0
void FUN_0098bae0_cls::FUN_0098bae0()
{
    m_d4.FUN_0066b0d0(0);
    m_130.FUN_0066b0d0(0);
    m_134 = 0;
    m_d8.FUN_00910b10();
    m_e0.FUN_00910b10();
    FUN_0098bae0_Tmp4 t(-_DAT_0108d540);
    m_e8 = t.value;
    m_d0 = 0;
    m_10c = 0.0f;
    m_f0.FUN_0098bbc0();
    m_100 = _NiPoint3_ZERO;
    m_110.FUN_008454f0(1);
    m_120.FUN_008454f0(1);
}

extern NiPoint3 DAT_011f426c;

struct FUN_0098bbc0_Class
{
    NiPoint3 m_00;
    int m_0c;
    void FUN_0098bbc0();
};

// Initializes m_00 to DAT_011f426c and m_0c to 0.
// @fnv 0x0098bbc0
void FUN_0098bbc0_Class::FUN_0098bbc0()
{
    m_00 = DAT_011f426c;
    m_0c = 0;
}

struct FnvStubSub
{
    float GetScale();
};
struct FnvStubPtr
{
    float* GetPtr();
};
extern double DAT_01073568;
extern double DAT_0101db88;
extern int DAT_011ce528;
struct FUN_0098c060_cls
{
    void FUN_0098c060(char* p, float* a, float* b, float* c);
};
// @fnv 0x0098c060
void FUN_0098c060_cls::FUN_0098c060(char* pObject, float* pfOutA, float* pfOutB, float* pfOutC)
{
    *pfOutA =
        (float)((DAT_01073568 - ((FnvStubSub*)(pObject + 0x50))->GetScale()) + *((FnvStubPtr*)&DAT_011ce528)->GetPtr());
    *pfOutB = (float)(DAT_0101db88 - ((FnvStubSub*)(pObject + 0x58))->GetScale());
    *pfOutC = (float)(DAT_01073568 - ((FnvStubSub*)(pObject + 0x60))->GetScale());
}

struct DoorExtraFields
{
    int formID;
    int refID;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0a;
};

struct CombatSearchMgr : FUN_0098c590_shell
{
    void FUN_0098c710(int arg);
};

// @fnv 0x0098c710
void CombatSearchMgr::FUN_0098c710(int arg)
{
    DoorExtraFields* door = (DoorExtraFields*)FindParentSpaceNode(arg);
    if (door != 0)
    {
        door->unk0a = 0;
        door->unk08++;
    }
}

struct Point3
{
    float x;
    float y;
    float z;
    void FUN_00439ef0();
    float FUN_004a7290();
};
template <int N> struct VirtualTag
{
};
template <int N, class T> struct VirtualLevel : VirtualLevel<N - 1, T>
{
    virtual void v(VirtualTag<N>*) = 0;
};
template <class T> struct VirtualLevel<0, T>
{
    virtual void v(VirtualTag<0>*) = 0;
};
struct InputActor;
struct OutputActor;
template <> struct VirtualLevel<125, InputActor> : VirtualLevel<124, InputActor>
{
    virtual Point3* GetPosition() = 0;
};
template <> struct VirtualLevel<125, OutputActor> : VirtualLevel<124, OutputActor>
{
    virtual Point3* ComputePosition(Point3*, Point3*) = 0;
};
struct InputActor : VirtualLevel<125, InputActor>
{
};
struct OutputActor : VirtualLevel<265, OutputActor>
{
    virtual IMH* GetIMH() = 0;
};
struct RelevantTarget
{
    void* handle;
    InputActor* originalActor;
};
struct CombatStateView
{
    RelevantTarget* FUN_007058c0();
};
extern double DAT_0108d6e8;

struct SearchGroup : CombatGroup_GetCount
{
    OutputActor* FindNearestActor(InputActor* source, OutputActor* priority, float radius);
};

// @fnv 0x0098cd50
OutputActor* SearchGroup::FindNearestActor(InputActor* source, OutputActor* priority, float radius)
{
    float bestDistance = radius * radius;
    OutputActor* bestActor = 0;
    Point3 center2 = *source->GetPosition();
    unsigned int numberOfActors3 = GetCount();
    for (unsigned int index = 0; index < numberOfActors3; ++index)
    {
        OutputActor* actor4 =
            reinterpret_cast<OutputActor*>(reinterpret_cast<FUN_00986b70_helper*>(this)->GetIntAt(index));
        if (actor4 == reinterpret_cast<OutputActor*>(source))
            continue;
        Point3 delta;
        actor4->ComputePosition(&delta, &center2)->FUN_00439ef0();
        float squaredDistance = delta.FUN_004a7290();
        if (actor4 == priority)
            squaredDistance = (float)(squaredDistance / DAT_0108d6e8);
        if (squaredDistance < bestDistance)
        {
            bestDistance = squaredDistance;
            bestActor = actor4;
        }
    }
    if (bestActor)
    {
        IMH* handle = bestActor->GetIMH();
        if (handle)
        {
            RelevantTarget* target = reinterpret_cast<CombatStateView*>(handle->FUN_00586150())->FUN_007058c0();
            if (target && target->originalActor == source)
                bestActor = 0;
        }
    }
    return bestActor;
}

struct Timer_98d1a0
{
    int unk00;
    int unk04;
    bool FUN_008d7f80();
    void FUN_008d7f40(float);
};
struct FUN_0098d1a0_shell;
struct Choice_98d1a0
{
    virtual void v0();
    virtual void v4();
    virtual bool Validate(FUN_0098d1a0_shell*);
    int FUN_00726070();
};
float __cdecl FUN_00435dd0();
struct FUN_00435de0
{
    int value;
    FUN_00435de0(float);
};
Choice_98d1a0* __cdecl SelectCombatStyleHandler(FUN_0098d1a0_shell*);
struct FUN_0098d1a0_shell
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
    Choice_98d1a0* choice;
    bool flag;
    Timer_98d1a0 selectTimer;
    Timer_98d1a0 validateTimer;
    int unk40;
    FUN_00435de0 stamp;
    unsigned int FUN_00990890();
    void UpdateChoiceSelection();
};
// When more than one entry exists, picks a choice on the select timer, validates it on the validate timer, and clears it otherwise.
// @fnv 0x0098d1a0
void FUN_0098d1a0_shell::UpdateChoiceSelection()
{
    if (FUN_00990890() > 1)
    {
        if (!flag && selectTimer.FUN_008d7f80())
        {
            choice = SelectCombatStyleHandler(this);
            selectTimer.FUN_008d7f40(5.0f);
            if (choice)
            {
                unk40 = choice->FUN_00726070();
                FUN_00435de0 currentStamp(FUN_00435dd0());
                stamp = currentStamp;
            }
        }
        if (choice && validateTimer.FUN_008d7f80())
        {
            if (!choice->Validate(this))
            {
                choice = 0;
                flag = false;
            }
            validateTimer.FUN_008d7f40(1.0f);
        }
    }
    else
    {
        choice = 0;
        flag = false;
        selectTimer.FUN_008d7f40(0.0f);
    }
}

struct ClusterVec
{
    float x, y, z;
    ClusterVec operator+(const ClusterVec&) const;
    void ScaleByInverse(float);
};
struct ClusterPosition
{
    ClusterVec vector;
    unsigned cell;
    ClusterVec& FUN_006815c0();
    unsigned FUN_0084e3a0();
    float FUN_00527a40(const ClusterPosition&);
};
struct ClusterRef
{
    ClusterPosition FUN_00575650();
};
struct FUN_0098dc00 : ClusterPosition
{
    unsigned count;
    FUN_0098dc00();
    void SetTripleAndValue(ClusterVec*, unsigned);
};
struct ClusterMember
{
    ClusterRef* ref;
    unsigned unk04, unk08, unk0c;
    FUN_0098dc00* group;
};
struct ClusterRecord
{
    ClusterMember* member;
    ClusterPosition position;
    signed char nearest;
    ClusterRecord();
};
struct ClusterTimer
{
    unsigned value;
    bool FUN_008d7f80();
    void FUN_008d7f40(float);
};
struct ObjectPointerList
{
    unsigned count;
    unsigned FUN_0044ddc0();
    FUN_0098dc00*& FUN_006a7ad0(unsigned);
    unsigned FUN_007cb2e0(FUN_0098dc00*&);
    void FUN_009a4320(unsigned, unsigned);
};
extern float DAT_0108d540;
extern bool DAT_011a4d34;
extern float DAT_011a4d30, DAT_011a4d2c;
int MinInt(int, int);
struct ClusterWork
{
    unsigned unk0;
    unsigned unk4;
    unsigned unk8;
    unsigned unkc;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned unk60;
    unsigned unk64;
    unsigned unk68;
    unsigned unk6c;
    unsigned unk70;
    unsigned unk74;
    unsigned unk78;
    unsigned unk7c;
    unsigned unk80;
    unsigned unk84;
    unsigned unk88;
    unsigned unk8c;
    unsigned unk90;
    unsigned unk94;
    unsigned unk98;
    unsigned unk9c;
    unsigned unka0;
    unsigned unka4;
    unsigned unka8;
    unsigned unkac;
    ClusterTimer timer;
    unsigned unkb4;
    unsigned unkb8;
    unsigned unkbc;
    unsigned unkc0;
    unsigned unkc4;
    unsigned unkc8;
    unsigned unkcc;
    unsigned unkd0;
    unsigned unkd4;
    unsigned unkd8;
    unsigned unkdc;
    unsigned unke0;
    unsigned unke4;
    unsigned unke8;
    unsigned unkec;
    unsigned unkf0;
    unsigned unkf4;
    unsigned unkf8;
    unsigned unkfc;
    unsigned unk100;
    unsigned unk104;
    unsigned unk108;
    unsigned unk10c;
    unsigned unk110;
    unsigned unk114;
    unsigned unk118;
    unsigned unk11c;
    unsigned unk120;
    unsigned unk124;
    unsigned unk128;
    unsigned unk12c;
    unsigned unk130;
    unsigned unk134;
    ObjectPointerList groups;
    unsigned FUN_00990890();
    ClusterMember* FUN_00988790(unsigned);
    void RecenterClusters();
    void UpdateGroups();
};
// Rebuilds spatial groups: drops members whose group is too far, merges mutual nearest neighbours, then merges overlapping groups.
// @fnv 0x0098d2c0
void ClusterWork::UpdateGroups()
{
    if (DAT_011a4d34)
        return;
    RecenterClusters();
    if (!timer.FUN_008d7f80())
        return;
    timer.FUN_008d7f40(DAT_011a4d30);
    float e = DAT_011a4d2c * DAT_011a4d2c * 4.0;
    unsigned j = FUN_00990890();
    j = MinInt(j, 63);
    ClusterRecord c[64];
    float aDistances[64][64];
    memset(c, 0, sizeof(c));
    memset(aDistances, 0, sizeof(aDistances));
    for (unsigned i = 0; i < j; ++i)
    {
        c[i].member = FUN_00988790(i);
        c[i].position = c[i].member->ref->FUN_00575650();
        c[i].nearest = -1;
        if (c[i].member->group)
        {
            if (c[i].member->group->FUN_00527a40(c[i].position) > DAT_011a4d2c * DAT_011a4d2c * 4.0)
            {
                --c[i].member->group->count;
                c[i].member->group = 0;
            }
        }
    }
    for (unsigned j = 0; j < groups.FUN_0044ddc0(); ++j)
    {
        FUN_0098dc00* group = groups.FUN_006a7ad0(j);
        if (group->count == 0)
        {
            groups.FUN_009a4320(j, 1);
            delete group;
            --j;
        }
    }
    for (unsigned k = 0; k < j; ++k)
    {
        if (c[k].member->group)
            continue;
        float best = DAT_0108d540;
        signed char nearest = 0;
        for (unsigned iIndex = 0; iIndex < j; ++iIndex)
        {
            if (k == iIndex)
                continue;
            if (aDistances[k][iIndex] == 0.0)
            {
                float distance = c[k].position.FUN_00527a40(c[iIndex].position);
                aDistances[k][iIndex] = distance;
                aDistances[iIndex][k] = distance;
            }
            if (aDistances[k][iIndex] < best)
            {
                nearest = (signed char)iIndex;
                best = aDistances[k][iIndex];
            }
        }
        c[k].nearest = nearest;
    }
    for (unsigned n = 0; n < j; ++n)
    {
        if (c[n].member->group)
            continue;
        if (c[c[n].nearest].nearest == (signed char)n)
        {
            FUN_0098dc00* pMergedGroup = new FUN_0098dc00;
            groups.FUN_007cb2e0(pMergedGroup);
            c[n].member->group = pMergedGroup;
            c[c[n].nearest].member->group = pMergedGroup;
            ClusterVec center = c[n].position.FUN_006815c0() + c[c[n].nearest].position.FUN_006815c0();
            center.ScaleByInverse(2.0f);
            pMergedGroup->SetTripleAndValue(&center, c[n].position.FUN_0084e3a0());
        }
    }
    for (unsigned p = 0; p < groups.FUN_0044ddc0(); ++p)
    {
        FUN_0098dc00* first = groups.FUN_006a7ad0(p);
        for (unsigned q = p + 1; q < groups.FUN_0044ddc0(); ++q)
        {
            FUN_0098dc00* second = groups.FUN_006a7ad0(q);
            if (first->FUN_00527a40(*second) < DAT_011a4d2c * DAT_011a4d2c)
            {
                for (unsigned r = 0; r < j; ++r)
                {
                    if (c[r].member->group == second)
                        c[r].member->group = first;
                }
                delete second;
                groups.FUN_009a4320(q, 1);
                --q;
            }
        }
    }
    for (unsigned t = 0; t < j; ++t)
    {
        if (c[t].member->group)
            continue;
        FUN_0098dc00* j = 0;
        unsigned e = c[t].nearest;
        while (!j)
        {
            j = c[e].member->group;
            e = c[e].nearest;
        }
        if (c[t].position.FUN_00527a40(*j) < DAT_011a4d2c * DAT_011a4d2c)
        {
            c[t].member->group = j;
            e = c[t].nearest;
            while (!c[e].member->group)
            {
                c[e].member->group = j;
                e = c[e].nearest;
            }
        }
    }
    RecenterClusters();
}

struct FUN_0098dc00_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_10;

    void Reset();
    FUN_0098dc00_cls* FUN_0098dc00();
};

// Calls Reset(), sets m_10 to 0, and returns this.
// @fnv 0x0098dc00
FUN_0098dc00_cls* FUN_0098dc00_cls::FUN_0098dc00()
{
    Reset();
    m_10 = 0;
    return this;
}

struct Vec3
{
    float x, y, z;
    Vec3& operator+=(const Vec3& o);
    Vec3& operator/=(float f);
};
extern Vec3 Vec3_ZERO;

struct CombatActorStub
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v04a();
    virtual void v04b();
    virtual void v04c();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v05a();
    virtual void v05b();
    virtual void v05c();
    virtual void v05d();
    virtual void v05e();
    virtual void v05f();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v06a();
    virtual void v06b();
    virtual void v06c();
    virtual void v06d();
    virtual void v06e();
    virtual void v06f();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v07a();
    virtual void v07b();
    virtual void v07c();
    virtual Vec3* GetSourceVelocity();
};

struct CombatClusterStub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned int memberCount;
    Vec3* GetNavMeshData();
    void SetGridPosition(const Vec3& p);
};

struct CombatMemberStub
{
    CombatActorStub* actor;
    int unk04;
    int unk08;
    int unk0C;
    CombatClusterStub* cluster;
};

struct ClusterArrayStub
{
    unsigned int GetSize();
    CombatClusterStub*& GetAt(unsigned int i);
};

struct CombatGroupStub
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    ClusterArrayStub clusters;

    unsigned int GetMemberCount();
    CombatMemberStub* GetMember(unsigned int i);
    void RecenterClusters();
};

// @fnv 0x0098dc40
void CombatGroupStub::RecenterClusters()
{
    for (unsigned int i = 0; i < clusters.GetSize(); i++)
    {
        CombatClusterStub* cluster = clusters.GetAt(i);
        cluster->SetGridPosition(Vec3_ZERO);
        cluster->memberCount = 0;
    }
    unsigned int count = GetMemberCount();
    for (unsigned int j = 0; j < count; j++)
    {
        CombatMemberStub* member = GetMember(j);
        if (member->cluster)
        {
            Vec3 pos = *member->cluster->GetNavMeshData();
            pos += *member->actor->GetSourceVelocity();
            member->cluster->SetGridPosition(pos);
            member->cluster->memberCount++;
        }
    }
    for (unsigned int k = 0; k < clusters.GetSize(); k++)
    {
        CombatClusterStub* c = clusters.GetAt(k);
        Vec3 center = *c->GetNavMeshData();
        center /= (float)c->memberCount;
        c->SetGridPosition(center);
    }
}

struct FUN_0098f580_Item
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
};

struct FUN_0096a330_class
{
    void __thiscall FUN_0098ed80(unsigned int, int);
    FUN_0098f580_Item* __thiscall GetEntryAt(int);
};

struct FUN_0098f580_class
{
    void* m_00;
    FUN_0098f580_Item* m_items;
    unsigned int m_uiItemCount;

    void __thiscall CopyItemsTo(FUN_0096a330_class* destination);
};

// @fnv 0x0098f580
void __thiscall FUN_0098f580_class::CopyItemsTo(FUN_0096a330_class* destination)
{
    destination->FUN_0098ed80(m_uiItemCount, 1);

    for (unsigned int index = 0; index < m_uiItemCount; ++index)
        *destination->GetEntryAt(index) = m_items[index];
}

struct FUN_0098fa00_cls
{
    int m_04;
    int unk08;
    int m_0c;
    virtual int v0();
    virtual int v1(int a);
    virtual int v2();
    virtual int v3(int a, int b);
    void Helper0(int a, int b, int c);
    void Helper1();
    void FUN_0098fa00(int a1, int a2);
};

// @fnv 0x0098fa00
void FUN_0098fa00_cls::FUN_0098fa00(int a1, int a2)
{
    if (m_04 != 0)
    {
        if (a2 == m_0c)
        {
            m_04 = v3(m_04, a1);
        }
        else
        {
            int t = v1(a1);
            Helper0(t, m_04, a2);
            Helper1();
            m_04 = t;
        }
    }
    else
    {
        m_04 = v1(a1);
        m_0c = a1;
    }
}

void* operator new(unsigned int size, void* place);
void operator delete(void* object, void* place);

struct FUN_0098fc70_Elem
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    FUN_0098fc70_Elem();
};

struct FUN_0098fc70_cls
{
    int m_00;
    void __thiscall FUN_0098fc70(void* data, unsigned int count);
};

// Constructs count FUN_0098fc70_Elem objects in place at data, each 0x1c bytes apart.
// @fnv 0x0098fc70
void FUN_0098fc70_cls::FUN_0098fc70(void* data, unsigned int count)
{
    unsigned int i;
    for (i = 0; i < count; i++)
    {
        new ((char*)data + i * 0x1c) FUN_0098fc70_Elem();
    }
}

class FUN_0098fd10_cls
{
  public:
    virtual void v00();
    virtual int v01(int a);
    int m_04;
    int m_08;
    int m_0c;
    void FUN_0098fc70(int a, int b);
};

// @fnv 0x0098fd10
void FUN_0098f2a0::FUN_0098fd10(int a, int b)
{
    ((FUN_0098fd10_cls*)this)->m_04 = 0;
    ((FUN_0098fd10_cls*)this)->m_08 = 0;
    ((FUN_0098fd10_cls*)this)->m_0c = 0;
    if ((unsigned int)b > (unsigned int)a)
    {
        a = b;
    }
    if ((unsigned int)a > 0)
    {
        ((FUN_0098fd10_cls*)this)->m_04 = ((FUN_0098fd10_cls*)this)->v01(a);
        ((FUN_0098fd10_cls*)this)->m_0c = a;
    }
    if ((unsigned int)b > 0)
    {
        ((FUN_0098fd10_cls*)this)->FUN_0098fc70(((FUN_0098fd10_cls*)this)->m_04, b);
        ((FUN_0098fd10_cls*)this)->m_08 = b;
    }
}

void FNV_Warning(const char* fmt, ...);

struct CombatGroupStrategy
{
    int unk00;
    int unk04;
};

struct CombatGroupStrategy0 : CombatGroupStrategy
{
    CombatGroupStrategy0(int type);
};
struct CombatGroupStrategy2 : CombatGroupStrategy
{
    CombatGroupStrategy2(int type);
};
struct CombatGroupStrategy3 : CombatGroupStrategy
{
    CombatGroupStrategy3(int type);
};
struct CombatGroupStrategy1 : CombatGroupStrategy
{
    CombatGroupStrategy1(int type);
};

// Creates and returns a combat group strategy object for the given type, warning and returning 0 for unknown types.
// @fnv 0x0098fdf0
int __cdecl CreateCombatGroupStrategy(unsigned int type)
{
    switch (type)
    {
    case 0:
        return (int)new CombatGroupStrategy0(type);
    case 2:
        return (int)new CombatGroupStrategy2(type);
    case 3:
        return (int)new CombatGroupStrategy3(type);
    case 1:
        return (int)new CombatGroupStrategy1(type);
    default:
        FNV_Warning("COMBAT: Could not create combat group strategy of type %i", type);
        return 0;
    }
}

struct GlobalSetting_011f18d8
{
    unsigned char* Bool();
};
extern GlobalSetting_011f18d8 g_011f18d8;

struct CombatActor;

struct CombatContext
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
    CombatContext(CombatActor* actor);
    ~CombatContext();
    int GetCount();
};

struct CombatStyleHandler
{
    virtual bool Check(CombatActor* actor, CombatContext* ctx);
    virtual void Apply(CombatActor* actor, CombatContext* ctx);
};

struct CombatActor
{
    CombatStyleHandler* GetCurrentHandler();
    void ResetHandler();
};

CombatStyleHandler* __cdecl FUN_0098e980(unsigned int index);

// @fnv 0x009900f0
CombatStyleHandler* __cdecl SelectCombatStyleHandler(CombatActor* actor)
{
    if (*g_011f18d8.Bool())
        return 0;
    CombatContext ctx(actor);
    CombatStyleHandler* pCurrentHandler = actor->GetCurrentHandler();
    if (ctx.GetCount() < 2)
        return 0;
    for (unsigned int uiIndex = 0; uiIndex < 4; uiIndex++)
    {
        CombatStyleHandler* pHandler = FUN_0098e980(uiIndex);
        if (pHandler)
        {
            if (pHandler == pCurrentHandler)
                return pCurrentHandler;
            if (pHandler->Check(actor, &ctx))
            {
                actor->ResetHandler();
                pHandler->Apply(actor, &ctx);
                return pHandler;
            }
        }
    }
    return 0;
}

// CombatThreatMap destructor: clear all threats; the threat list and the base map are destroyed afterwards.

class B1150ThreatMapBase
{
  public:
    ~B1150ThreatMapBase();
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
};

class B1150ThreatList
{
  public:
    ~B1150ThreatList();
    int unk00;
    int unk04;
    int unk08;
};

class FUN_00991150 : public B1150ThreatMapBase
{
  public:
    ~FUN_00991150();
    void Clear(int iFlags);

    B1150ThreatList m_kThreats;
};

// Destructor that calls Clear(0) to reset the threat map.
// @fnv 0x00991150
FUN_00991150::~FUN_00991150()
{
    Clear(0);
}

extern int DAT_0108db4c;

void __cdecl FUN_004ede70(void*);

// @fnv 0x00993880
void FUN_00991130_class::FUN_00993880()
{
    *(int*)this = (int)&DAT_0108db4c;
    FUN_004ede70(*(void**)((char*)this + 4));
}

struct TargetData
{
    int unk00;
    int unk04;
    unsigned __int64 unk08;
};

struct TargetMember
{
    void FreeMemory(TargetData* data);
};

struct TargetOwner
{
    int unk00;
    int unk04;
    int unk08;
    TargetMember member0c;
    void FUN_00993c10(TargetData* data);
};

// Clears data->unk08 to zero, then passes data to member0c.FreeMemory.
// @fnv 0x00993c10
void TargetOwner::FUN_00993c10(TargetData* data)
{
    data->unk08 = 0;
    member0c.FreeMemory(data);
}

struct Context;
struct Action
{
    virtual void Slot0();
    virtual void Start(Context*, unsigned int);
    virtual bool Continue(Context*, unsigned int);
    bool __thiscall HasFlags(unsigned int);
};
struct Context
{
    Action* __thiscall FUN_008cdd90();
    unsigned int __thiscall FUN_009ee040();
    bool __thiscall FUN_00980470();
    bool __thiscall FUN_009804d0();
    void __thiscall FUN_00980250();
    void __thiscall FUN_009db930(Action*);
    void __thiscall FUN_005468d0(unsigned int);
};
struct Entry
{
    Action* m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
};
struct Target
{
    Entry** m_00;
    unsigned int m_04;
    unsigned int m_08;
    bool __thiscall FUN_0097e490();
    bool __thiscall AdvanceActions(Context* context);
};
// @fnv 0x00994050
bool Target::AdvanceActions(Context* context)
{
    while (!FUN_0097e490() && m_00[m_08]->m_00->HasFlags(2))
    {
        m_00[m_08]->m_00->Start(context, m_00[m_08]->m_0c);
        m_08++;
    }
    if (!FUN_0097e490())
    {
        bool changed = true;
        if (m_00[m_08]->m_00 == context->FUN_008cdd90() && m_00[m_08]->m_0c == context->FUN_009ee040() &&
            m_00[m_08]->m_00->Continue(context, m_00[m_08]->m_0c) && !context->FUN_00980470() &&
            !context->FUN_009804d0())
        {
            changed = false;
        }
        if (changed)
        {
            context->FUN_00980250();
            m_00[m_08]->m_00->Start(context, m_00[m_08]->m_0c);
            context->FUN_009db930(m_00[m_08]->m_00);
            context->FUN_005468d0(m_00[m_08]->m_0c);
            m_08++;
        }
        else
        {
            m_08++;
        }
    }
    if (FUN_0097e490())
        return true;
    return false;
}

struct C9942D0Item
{
    void* m_pvOwner;
    int unk04;
    int unk08;
    void* m_pvTarget;
};

class C9942D0List
{
  public:
    C9942D0Item** m_ppGeometries;
    unsigned int m_uiCount;

    bool UpdateItem(unsigned int uiIndex, void* pvOwner, void* pvTarget, int iArg);
    void UpdateAllItems(int iArg);
};

// Iterates over the list, calling UpdateItem for each entry and re-checking the same index when UpdateItem returns false.
// @fnv 0x009942d0
void C9942D0List::UpdateAllItems(int iArg)
{
    for (unsigned int i = 0; i < m_uiCount; i++)
    {
        void* pvOwner = m_ppGeometries[i]->m_pvOwner;
        void* pvTarget = m_ppGeometries[i]->m_pvTarget;
        if (!UpdateItem(i, pvOwner, pvTarget, iArg))
            i--;
    }
}

struct Elem;
struct ItemObj
{
    int FUN_00559450();
    int FUN_00726070(int a);
};
struct ListObj
{
    ItemObj** FUN_006815c0();
    ListObj* FUN_0062d990();
};
struct KeyObj
{
    ListObj* FUN_007d6bb0();
    ListObj* GetOffsetC();
    bool HasFlags(unsigned int a);
};
struct CtxObj
{
    int FUN_009947f0(int a);
};
struct Elem
{
    KeyObj* m_00;
    Elem* m_04;
    int m_08;
    int m_0c;
};
void* __cdecl FormHeap_Allocate(unsigned int n);
void __cdecl FormHeap_Free(void* p);
void* __cdecl memcpy(void* dst, const void* src, unsigned int n);
struct Arr994350
{
    Elem** m_items;
    int m_uiItemCount;
    unsigned int FUN_00994270(unsigned int key);
    bool InsertSortedEntry(int p0, KeyObj* p1, int p2, CtxObj* p3);
};
// @fnv 0x00994350
bool Arr994350::InsertSortedEntry(int aiStartIndex, KeyObj* apKey, int aiValue, CtxObj* apCtx)
{
    unsigned int i;
    for (i = aiStartIndex + 1; i < (unsigned int)m_uiItemCount; i++)
    {
        ListObj* lstA;
        KeyObj* v0 = m_items[i]->m_00;
        int vc = m_items[i]->m_0c;
        bool ok = 1;
        if (v0 != apKey)
        {
            ListObj* lst = apKey->FUN_007d6bb0();
            while (lst && *lst->FUN_006815c0() != 0)
            {
                bool innerOk = 0;
                ItemObj* itemX = *lst->FUN_006815c0();
                ListObj* list2 = v0->FUN_007d6bb0();
                while (list2 && *list2->FUN_006815c0() != 0)
                {
                    ItemObj* item2 = *list2->FUN_006815c0();
                    if (itemX->FUN_00559450() == item2->FUN_00559450())
                    {
                        innerOk = 1;
                        break;
                    }
                    list2 = list2->FUN_0062d990();
                }
                if (!innerOk)
                {
                    ok = 0;
                    break;
                }
                lst = lst->FUN_0062d990();
            }
        }
        if (ok)
        {
            if (m_items[aiStartIndex]->m_04 == 0)
                return 1;
            unsigned int idx = FUN_00994270((unsigned int)m_items[aiStartIndex]->m_04);
            if (idx < i)
                return 1;
            Elem* saved = m_items[aiStartIndex];
            memcpy(&m_items[aiStartIndex], &m_items[aiStartIndex + 1], (idx - 1 - aiStartIndex) * 4);
            m_items[idx - 1] = saved;
            return 0;
        }
        {
            lstA = apKey->FUN_007d6bb0();
            while (lstA && *lstA->FUN_006815c0() != 0)
            {
                ItemObj* head1 = *lstA->FUN_006815c0();
                int res1 = apCtx->FUN_009947f0(head1->FUN_00726070(aiValue));
                ListObj* obj34 = v0->GetOffsetC();
                while (obj34 && *obj34->FUN_006815c0() != 0)
                {
                    ItemObj* item34 = *obj34->FUN_006815c0();
                    if (head1->FUN_00559450() == item34->FUN_00559450())
                    {
                        int resC = apCtx->FUN_009947f0(item34->FUN_00726070(vc));
                        if (resC != -1 && res1 != resC)
                        {
                            bool found = 0;
                            Elem* ptrS;
                            Elem* prevN;
                            unsigned int markI;
                            int spanP;
                            Elem** cntO;
                            if (v0->HasFlags(1))
                            {
                                found = 1;
                            }
                            else
                            {
                                ptrS = m_items[aiStartIndex]->m_04;
                                while (ptrS)
                                {
                                    if (ptrS == m_items[i])
                                    {
                                        found = 1;
                                        break;
                                    }
                                    ptrS = ptrS->m_04;
                                }
                            }
                            if (!found)
                            {
                                prevN = m_items[aiStartIndex];
                                markI = i;
                                if (m_items[aiStartIndex]->m_04 != 0)
                                    markI = FUN_00994270((unsigned int)m_items[aiStartIndex]->m_04) - 1;
                                if (markI > (unsigned int)aiStartIndex)
                                {
                                    memcpy(&m_items[aiStartIndex], &m_items[aiStartIndex + 1],
                                           (markI - aiStartIndex) * 4);
                                    m_items[markI] = prevN;
                                }
                                else
                                {
                                    found = 1;
                                }
                            }
                            if (found)
                            {
                                spanP = m_uiItemCount;
                                cntO = m_items;
                                m_uiItemCount = m_uiItemCount + 1;
                                m_items = new Elem*[m_uiItemCount];
                                memcpy(m_items, cntO, i * 4);
                                memcpy(&m_items[i + 1], &cntO[i], (spanP - i) * 4);
                                m_items[i] = new Elem;
                                m_items[i]->m_00 = apKey;
                                m_items[i]->m_0c = resC;
                                m_items[i]->m_08 = 0;
                                m_items[i]->m_04 = m_items[i + 1];
                                delete[] cntO;
                            }
                            return 0;
                        }
                    }
                    obj34 = obj34->FUN_0062d990();
                }
                lstA = lstA->FUN_0062d990();
            }
        }
    }
    return 1;
}

// FUN_009947f0 - 62 bytes at 0x009947f0
//
// A /Od __thiscall member of the goal-table class:
//
//   int FUN_009947f0(int a, int b)
//   {
//       if (a == -1) a = b;                 // [ebp+8] is the incoming slot
//       if (IsValidCode(a))                 // free cdecl helper, bool result
//           a = (int)this->GetCombatGoal(a);  // __thiscall member, one stack arg
//       return a;
//   }

struct FUN_00984470_Class
{
    CombatGoal* __thiscall GetCombatGoal(int index);
};

extern bool __cdecl IsValidCode(int value);

struct FUN_009947f0_Class : public FUN_00984470_Class
{
    int __thiscall FUN_009947f0(int a, int b);
};

// If a is -1 it falls back to b, then if IsValidCode accepts a it converts a via GetCombatGoal and returns the result.
// @fnv 0x009947f0
int __thiscall FUN_009947f0_Class::FUN_009947f0(int iIndex, int iFallbackIndex)
{
    if (iIndex == -1)
        iIndex = iFallbackIndex;
    if (IsValidCode(iIndex))
        iIndex = (int)this->GetCombatGoal(iIndex);
    return iIndex;
}

// @fnv 0x00994830
bool __cdecl IsValidCode(int code)
{
    return code >= -65514 && code < -65511;
}

struct ListItem
{
    int FUN_0059bb30();
};
struct ListSlot
{
    ListItem* item;
};
struct SearchList
{
    ListSlot** entries;
    unsigned int entryCount;
    bool ContainsValue(int searchValue);
};
// Scans entries and returns true if any entry's item FUN_0059bb30() equals searchValue, otherwise false.
// @fnv 0x00994860
bool SearchList::ContainsValue(int searchValue)
{
    for (unsigned int index = 0; index < entryCount; ++index)
    {
        if (entries[index]->item->FUN_0059bb30() == searchValue)
        {
            return true;
        }
    }
    return false;
}

unsigned int FUN_00994bb0(unsigned int value, unsigned int hash);
struct CombatStateObject
{
    unsigned int FUN_00559450();
    unsigned int FUN_00726070();
};
struct CombatStateEntry
{
    CombatStateObject* object;
    unsigned int value;
};
struct CombatStateHash
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58;
    CombatStateEntry entries[16];
    unsigned int count;
    unsigned int hash;
    unsigned int FUN_005bd5c0(unsigned int index);
    unsigned int ComputeHash();
};
// If hash is unset, computes an FNV-style hash over 20 slots, the count, and each entry's object values, caching it in hash.
// @fnv 0x00994a90
unsigned int CombatStateHash::ComputeHash()
{
    if (hash != -1)
        return hash;
    hash = 0x811c9dc5;
    for (unsigned int i = 0; i < 20; ++i)
        hash = FUN_00994bb0(FUN_005bd5c0(i), hash);
    hash = FUN_00994bb0(count, hash);
    for (unsigned int j = 0; j < count; ++j)
    {
        CombatStateObject* object = entries[j].object;
        hash = FUN_00994bb0(object->FUN_00559450(), hash);
        hash = FUN_00994bb0(object->FUN_00726070(), hash);
    }
    return hash;
}

// @fnv 0x00994bb0
unsigned int __cdecl FUN_00994bb0(unsigned int auiValue, unsigned int auiHash)
{
    auiHash *= 0x01000193;
    auiHash ^= auiValue;
    return auiHash;
}

// FUN_00995780 : thiscall, 3 stack args, returns this.
//
//  mov eax,[ebp-4]      ; this
//  mov ecx,[ebp+8]      ; arg1
//  mov [eax],ecx        ; m_00 = arg1
//  mov edx,[ebp-4]
//  mov eax,[ebp+0x10]   ; arg3
//  mov [edx+4],eax      ; m_04 = arg3
//  mov ecx,[ebp-4]
//  mov edx,[ebp+0xc]    ; arg2
//  mov [ecx+8],edx      ; m_08 = arg2
//  mov ecx,[ebp-4]
//  add ecx,0xc
//  call FUN_00995760    ; member sub-object at +0xc

struct FUN_00995760_cls
{
    void FUN_00995760();
};

struct FUN_00995780_cls
{
    int m_00;
    int m_04;
    int m_08;
    FUN_00995760_cls m_0c;

    FUN_00995780_cls* FUN_00995780(int a, int b, int c);
};

// Stores a, c and b into m_00, m_04 and m_08, calls FUN_00995760 on m_0c, and returns this.
// @fnv 0x00995780
FUN_00995780_cls* FUN_00995780_cls::FUN_00995780(int a, int b, int c)
{
    m_00 = a;
    m_04 = c;
    m_08 = b;
    m_0c.FUN_00995760();
    return this;
}

struct FUN_006d3370_s
{
    void* FUN_006d3370(unsigned int);
};

struct FUN_00995910_shell
{
    int unk00;
    int unk04;
    void* array1[22];
    FUN_006d3370_s* array2[22];
    void FUN_00995910();
};

// Frees each of the 22 array1 pointers and releases each array2 item via FUN_006d3370(1).
// @fnv 0x00995910
void FUN_00995910_shell::FUN_00995910()
{
    for (unsigned int i = 0; i < 22; i++)
    {
        void* p = array1[i];
        Deallocate(p);
        FUN_006d3370_s* pItem = array2[i];
        FUN_006d3370_s* pItemCopy = pItem;
        pItemCopy ? pItemCopy->FUN_006d3370(1) : 0;
    }
}

struct SearchItem
{
    int __thiscall FUN_0044edb0();
};
struct SearchDestination
{
    void __thiscall FUN_007cb2e0(SearchItem** item);
};
struct SearchIterator
{
    unsigned int __thiscall FindFirstNonZero();
    unsigned char __thiscall AdvanceToNextEntry(unsigned int* cursor, unsigned int* metadata, SearchItem** item);
};
struct SearchContainer
{
    SearchIterator* __thiscall FUN_007d6bb0();
};
struct SearchOwner
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    unsigned int unk18, unk1c, unk20, unk24, unk28, unk2c;
    SearchContainer* container;
    void __thiscall FindAndDispatchById(int id, SearchDestination* destination);
};
// Iterates the container's entries and passes each entry whose FUN_0044edb0 equals id to destination->FUN_007cb2e0.
// @fnv 0x00995dd0
void SearchOwner::FindAndDispatchById(int id, SearchDestination* destination)
{
    SearchIterator* cursor = container->FUN_007d6bb0();
    unsigned int currentIndex = cursor->FindFirstNonZero();
    unsigned int auxiliary;
    SearchItem* entry;
    while (currentIndex != 0)
    {
        cursor->AdvanceToNextEntry(&currentIndex, &auxiliary, &entry);
        if (entry->FUN_0044edb0() == id)
        {
            destination->FUN_007cb2e0(&entry);
        }
    }
}

struct FUN_00995e30_item_cls;

struct FUN_00995e30_arr_cls
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0C;
    FUN_00995e30_arr_cls(unsigned int capacity, unsigned int growBy);
    ~FUN_00995e30_arr_cls();
    unsigned int FUN_0044ddc0();
    FUN_00995e30_item_cls** FUN_006a7ad0(unsigned int index);
};

struct FUN_00995e30_cls
{
    void FindAndDispatchById(int a1, FUN_00995e30_arr_cls* out);
    int FUN_00995e30(FUN_00995e30_item_cls* node);
};

// @fnv 0x00995e30
int FUN_00995e30_cls::FUN_00995e30(FUN_00995e30_item_cls* node)
{
    FUN_00995e30_arr_cls list(0x10, 0);
    FindAndDispatchById((int)node, &list);
    int total = (int)list.FUN_0044ddc0();

    for (unsigned int i = 0; i < list.FUN_0044ddc0(); i++)
    {
        total += FUN_00995e30(*list.FUN_006a7ad0(i));
    }

    return total;
}

class FUN_00996660_base
{
  public:
    virtual ~FUN_00996660_base();
    int unk04;
};

class FUN_00996660_cls : public FUN_00996660_base
{
  public:
    virtual ~FUN_00996660_cls();
    void Cleanup(int flag);
};

// @fnv 0x00996660
FUN_00996660_cls::~FUN_00996660_cls()
{
    this->Cleanup(1);
}

struct PathNode
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    PathNode* m_parent;
    float GetHeuristic();
};

struct PathNodeArray
{
    PathNodeArray();
    virtual ~PathNodeArray();
    void Clear(bool abFree);
    unsigned int GetSize();
    PathNode*& GetAt(unsigned int index);

    PathNode** m_data;
    unsigned int m_iElementCount;
    unsigned int m_pRayCursor;
    unsigned int m_10;
};

struct PathOpenList
{
    int m_uiItemCount;
    PathNode* m_slots[20];
    PathNode* Pop();
    void Remove(PathNode* node);
    void Push(PathNode* node);
};

struct PathSearch
{
    virtual void v0();
    virtual void GetNeighbors(PathNode* node, PathNodeArray* neighbors);
    virtual bool IsGoal(PathNode* node);

    PathNode* m_kNodeCollection[2044];
    PathOpenList m_openList;
    PathNode* m_best;
    PathNode* m_pTileTemplate;
    int m_2050;
    unsigned char m_2054;

    PathNode* FindPath();
};

void __cdecl FUN_0040fca0(unsigned long);

// Pops nodes from the open list, expands neighbors via GetNeighbors, updates parents and the best node, and returns the goal node or null.
// @fnv 0x00996860
PathNode* PathSearch::FindPath()
{
    PathNodeArray neighbors;
    PathNode* previous = m_pTileTemplate;
    m_pTileTemplate = m_openList.Pop();
    if (m_pTileTemplate == 0)
        return 0;
    m_best = m_pTileTemplate;
    int iterations = 0;
    while (m_pTileTemplate != 0)
    {
        if (IsGoal(m_pTileTemplate))
        {
            m_best = m_pTileTemplate;
            return m_pTileTemplate;
        }
        neighbors.Clear(false);
        GetNeighbors(m_pTileTemplate, &neighbors);
        for (unsigned int i = 0; i < neighbors.GetSize(); i++)
        {
            PathNode* node = neighbors.GetAt(i);
            m_openList.Remove(node);
            if (m_pTileTemplate->m_parent == node)
                return 0;
            node->m_parent = m_pTileTemplate;
            m_openList.Push(node);
            if (node->GetHeuristic() < m_best->GetHeuristic())
                m_best = node;
        }
        if (m_2054)
        {
            iterations++;
            if (iterations == 50)
            {
                iterations = 0;
                FUN_0040fca0(0);
            }
        }
        previous = m_pTileTemplate;
        m_pTileTemplate = m_openList.Pop();
    }
    m_pTileTemplate = previous;
    return 0;
}

struct Inner009973a0
{
    int a;
    int b;
    int c;
    int d;
};

struct FUN_009973a0_class
{
    Inner009973a0 m_00;
    int m_10;
    int m_14;
    float m_18;
    int m_1c;

    void __thiscall FUN_009973a0(const FUN_009973a0_class* src);
};

// Copies the four-word block and the four scalar members from src into this object.
// @fnv 0x009973a0
void __thiscall FUN_009973a0_class::FUN_009973a0(const FUN_009973a0_class* src)
{
    m_00 = src->m_00;
    m_10 = src->m_10;
    m_14 = src->m_14;
    m_18 = src->m_18;
    m_1c = src->m_1c;
}

struct P029Actor;
struct P029Timer
{
    bool FUN_008d7f80();
    void FUN_008d7f40(float);
};
struct P029Combat
{
    P029Timer* FUN_00503650();
    P029Timer* FUN_00984230();
    P029Timer* FUN_00984250();
};
struct P029Group
{
    P029Timer* FUN_00624700();
    P029Timer* GetSlotPtr(int);
    unsigned FUN_00990890();
    P029Actor* GetIntAt(unsigned);
};
struct P029Input
{
    P029Combat* FUN_00586150();
    P029Group* FUN_004fb070();
};
struct P029Action
{
    int FUN_0041ca90();
};
struct P029Position
{
    float x, y, z;
    unsigned cell;
    float FUN_00527a40(const P029Position&);
};
struct P029Sound
{
    unsigned id, state, flags;
    ~P029Sound();
    void FUN_00ad8e60(void*, void*);
};
struct P029Ref
{
    void* FUN_006815c0();
    unsigned FUN_0084e3a0();
    unsigned FUN_0044ddc0();
    void* FUN_00460140();
};
struct P029Item
{
    bool FUN_0083c7b0();
    P029Ref* FUN_0083c820();
    void FUN_0083c850(int);
    ~P029Item();
};
struct P029Topic
{
    P029Item* FUN_0061b320(P029Actor*, void*, P029Topic*, void*, bool);
};
template <int N> struct P029Tag
{
};
template <int N> struct P029Slots : P029Slots<N - 1>
{
    virtual void slot(P029Tag<N>*) = 0;
};
template <> struct P029Slots<0>
{
    virtual void slot(P029Tag<0>*) = 0;
};
template <> struct P029Slots<64> : P029Slots<63>
{
    virtual bool IsActor() = 0;
};
template <> struct P029Slots<131> : P029Slots<130>
{
    virtual P029Action* GetAction() = 0;
};
template <> struct P029Slots<133> : P029Slots<132>
{
    virtual int IsBusy() = 0;
};
template <> struct P029Slots<139> : P029Slots<138>
{
    virtual P029Action* GetPrimaryAction() = 0;
};
template <> struct P029Slots<160> : P029Slots<159>
{
    virtual bool Speak(P029Actor*, int, int, int, int, int, P029Topic*, int, int) = 0;
};
template <> struct P029Slots<161> : P029Slots<160>
{
    virtual float Play(void*, P029Sound*, unsigned, unsigned, unsigned, int, int, int, int, int, int, int, int) = 0;
};
template <> struct P029Slots<169> : P029Slots<168>
{
    virtual void Say(P029Actor*, P029Topic*, int, int, int, int) = 0;
};
template <> struct P029Slots<195> : P029Slots<194>
{
    virtual bool IsBlocked() = 0;
};
template <> struct P029Slots<266> : P029Slots<265>
{
    virtual P029Input* GetInput() = 0;
};
template <> struct P029Slots<291> : P029Slots<290>
{
    virtual P029Sound GetSoundByEditorID(int) = 0;
};
struct P029Actor : P029Slots<291>
{
    bool FUN_00437bd0();
    int FUN_00931850();
    P029Actor* FUN_008d8520();
    bool GetByteAt608();
    void FUN_00967ac0(int);
    P029Position FUN_00575650();
};
struct P029BoolSetting
{
    bool* FUN_00408d60();
};
struct P029FloatSetting
{
    float* FUN_00403e20();
};
extern P029BoolSetting DAT_011f1764;
extern P029FloatSetting DAT_011ce4c8, DAT_011cfb20, DAT_011cfcbc, DAT_011ced40, DAT_011cf898, DAT_011cf858,
    DAT_011ce248, DAT_011ceba4, DAT_011ce35c, DAT_011cf24c, DAT_011cfa4c, DAT_011cf0b0;
extern unsigned DAT_011f170c;
extern P029Actor* DAT_011dea3c;
extern float DAT_0108d24c;
extern const char DAT_0108d250[];
unsigned gm_GetTickCount();
void FNV_Warning(const char*, ...);
float __cdecl RandomFloat(float, float);
P029Topic* GetTopicSubTypeName(int, int);
unsigned __fastcall FUN_004048e0(void*);
void* __fastcall FUN_00559450(void*);
void FUN_00967aa0();
struct P029Manager
{
    bool TryStartDialogue(P029Actor*, void*, int, int, bool, P029Input*);
};
// Checks cooldown and actor state, picks a nearby actor and topic, then either plays a sound or makes the actor speak or say the topic.
// @fnv 0x009839b0
bool P029Manager::TryStartDialogue(P029Actor* apSpeaker, void* other, int type, int subtype, bool force,
                                   P029Input* context)
{
    if (*DAT_011f1764.FUN_00408d60())
        return false;
    if (!apSpeaker->IsActor())
        return false;
    unsigned e = gm_GetTickCount();
    if (e - DAT_011f170c < 1500)
        return false;
    DAT_011f170c = e;
    P029Actor* a = apSpeaker;
    if (!context)
        context = a->GetInput();
    P029Timer* b = 0;
    if (context)
    {
        P029Combat* group = context->FUN_00586150();
        P029Group* combat = context->FUN_004fb070();
        if (type == 2)
        {
            switch (subtype)
            {
            case 0:
            case 1:
                b = group->FUN_00503650();
                break;
            case 4:
                b = group->FUN_00984230();
                break;
            case 5:
                b = combat->FUN_00624700();
                break;
            case 3:
                b = group->FUN_00984250();
                break;
            }
        }
        else if (type == 4)
            b = combat->GetSlotPtr(subtype);
        else
            FNV_Warning(DAT_0108d250, type);
    }
    if (b && !b->FUN_008d7f80())
        return false;
    if (a->FUN_00437bd0() || a->FUN_00931850())
        return false;
    bool c = true;
    if (!force)
    {
        if (a->FUN_008d8520()->IsBlocked() || a->FUN_008d8520()->GetAction())
            return false;
        P029Action* action = a->FUN_008d8520()->GetPrimaryAction();
        if (action && action->FUN_0041ca90() == 28)
            return false;
        action = a->FUN_008d8520()->GetAction();
        if (action && (action->FUN_0041ca90() == 28 || action->FUN_0041ca90() == 26))
            return false;
        if (a == DAT_011dea3c && DAT_011dea3c->GetByteAt608())
            return false;
    }
    else
    {
        if (a->IsBusy())
            c = false;
        else
        {
            P029Action* action = a->FUN_008d8520()->GetAction();
            if (action && action->FUN_0041ca90() == 26)
                c = false;
        }
    }
    if (b)
    {
        float delay = 0.0f;
        if (type == 2)
        {
            switch (subtype)
            {
            case 0:
            case 1:
                delay = RandomFloat(*DAT_011cfb20.FUN_00403e20(), *DAT_011ce4c8.FUN_00403e20());
                break;
            case 4:
                delay = RandomFloat(*DAT_011ced40.FUN_00403e20(), *DAT_011cfcbc.FUN_00403e20());
                break;
            case 5:
                delay = RandomFloat(*DAT_011cf858.FUN_00403e20(), *DAT_011cf898.FUN_00403e20());
                break;
            case 3:
                delay = RandomFloat(*DAT_011ceba4.FUN_00403e20(), *DAT_011ce248.FUN_00403e20());
                break;
            }
        }
        else if (type == 4)
        {
            switch (subtype)
            {
            case 0:
            case 1:
                delay = RandomFloat(*DAT_011cf24c.FUN_00403e20(), *DAT_011ce35c.FUN_00403e20());
                break;
            default:
                delay = RandomFloat(*DAT_011cf0b0.FUN_00403e20(), *DAT_011cfa4c.FUN_00403e20());
                break;
            }
        }
        else
            FNV_Warning(DAT_0108d250, type);
        b->FUN_008d7f40(delay);
    }
    P029Actor* f = 0;
    if (c && context)
    {
        P029Group* combat = context->FUN_004fb070();
        float count = DAT_0108d24c;
        unsigned nearest = combat->FUN_00990890();
        P029Position position = a->FUN_00575650();
        for (unsigned i = 0; i < nearest; i++)
        {
            P029Actor* candidate = combat->GetIntAt(i);
            if (candidate == a || candidate == DAT_011dea3c)
                continue;
            if (candidate->FUN_008d8520()->IsBlocked())
                continue;
            P029Action* candidatePosition = candidate->FUN_008d8520()->GetPrimaryAction();
            if (candidatePosition && candidatePosition->FUN_0041ca90() == 28)
                continue;
            candidatePosition = candidate->FUN_008d8520()->GetAction();
            if (candidatePosition && candidatePosition->FUN_0041ca90() == 28)
                continue;
            P029Position action = candidate->FUN_00575650();
            float distance = action.FUN_00527a40(position);
            if (distance < count)
            {
                f = candidate;
                count = distance;
            }
        }
    }
    if (!f)
        f = a;
    P029Topic* d = GetTopicSubTypeName(type, subtype);
    if (!d)
        return false;
    if (a == DAT_011dea3c)
    {
        P029Item* item = d->FUN_0061b320(apSpeaker, other, d, 0, true);
        if (item)
        {
            if (item->FUN_0083c7b0())
            {
                P029Ref* ref = item->FUN_0083c820();
                if (ref)
                {
                    DAT_011dea3c->FUN_00967ac0(1);
                    P029Sound sound = a->FUN_008d8520()->GetSoundByEditorID(0);
                    a->Play(FUN_00559450(ref->FUN_00460140()), &sound, ref->FUN_0044ddc0(), ref->FUN_0084e3a0(),
                            FUN_004048e0(ref->FUN_006815c0()), 0, 0, 0, 0, 0, 0, 0, 1);
                    sound.FUN_00ad8e60((void*)FUN_00967aa0, 0);
                    item->FUN_0083c850(0);
                }
            }
            delete item;
        }
    }
    else
    {
        if (c)
        {
            if (a->Speak(f, 0, 0, 0, 1, 1, d, 1, 0))
                return true;
        }
        else
        {
            a->FUN_008d8520()->Say(a, d, 0, 0, 0, 0);
            return true;
        }
    }
    return false;
}

struct FUN_00984290
{
    BSSimpleList<void*> first;
    BSSimpleList<void*> second;

    virtual ~FUN_00984290();
};

// Destructor that deletes every item in the first and second BSSimpleList and removes each head until both lists are empty.
// @fnv 0x00984290
FUN_00984290::~FUN_00984290()
{
    BSSimpleList<void*>* list3;
    void* firstCurrent;
    void* firstItem4;
    void* secondCurrent;
    void* secondItem;

    list3 = &first;
    while (list3 != 0 && list3->GetItem() != 0)
    {
        firstCurrent = list3->GetItem();
        firstItem4 = firstCurrent;
        ::operator delete(firstItem4);
        list3->RemoveHead();
    }

    list3 = &second;
    while (list3 != 0 && list3->GetItem() != 0)
    {
        secondCurrent = list3->GetItem();
        secondItem = secondCurrent;
        ::operator delete(secondItem);
        list3->RemoveHead();
    }
}

struct GroupReset_98afb0 : public GroupReset
{
    unsigned int unkec;
    ClusterPosition kPos;
    unsigned int unk;
    unsigned int unkCur;
    unsigned int unkValue;
    float fValue;

    bool UpdateAndCheckChanged();
};

// @fnv 0x0098afb0
bool GroupReset_98afb0::UpdateAndCheckChanged()
{
    UpdateExpiringPositions();
    ClusterPosition kOldPosVal = kPos;
    float fOldValue = fValue;
    UpdateCenter();
    bool bChanged = false;
    if (fValue + 128.0 < fOldValue || fValue - 128.0 > fOldValue)
        bChanged = true;
    else if (kOldPosVal.FUN_00527a40(kPos) > 4096.0)
        bChanged = true;
    if (bChanged)
        CollectNearbyRefs();
    return bChanged;
}

namespace CombatCenter {
struct Vec
{
    float x, y, z;
    Vec ApplyScaled(float);
    Vec& FUN_0063c8a0(const Vec&);
    Vec& ScaleByInverse(float);
};
struct Position
{
    Vec position;
    void* cell;
    Vec& FUN_006815c0();
    void* FUN_0084e3a0();
    float FUN_00527a40(const Position&);
    void SetTripleAndValue(const Vec&, void*);
};
struct Threat : Position
{
    float FUN_00985bb0();
};
struct Actor
{
    int FUN_00931850();
    Position FUN_00575650();
};
struct Setting
{
    float* FUN_00403e20();
};
extern Setting DAT_011ce7b0;
extern Vec DAT_011f426c;
extern float DAT_0108d540;
double FUN_004579e0(float);
float FUN_0040ebd0(float, float);
float FUN_00404010(float, float);
struct Center
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
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
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    Position center;
    Vec origin;
    float radius;
    unsigned int FUN_00988750();
    Threat* ForwardToMember(unsigned int);
    void GetParamValues(Position*, float&, float&);
    unsigned int FUN_00990890();
    Actor* GetIntAt(unsigned int);
    void UpdateCenter();
};
// Recomputes the center from the highest-priority threat or lowest-rank actor, averaging positions within range and setting radius from the farthest distance.
// @fnv 0x0098b100
void Center::UpdateCenter()
{
    float minimum = 0.0f;
    float maximumSlot1 = 0.0f;
    unsigned int countSlot11 = FUN_00988750();
    if (countSlot11)
    {
        float priority = -DAT_0108d540;
        if (countSlot11 > 1)
        {
            unsigned int best = 0;
            for (unsigned int i = 0; i < countSlot11; i++)
            {
                Threat* itemSlot14 = ForwardToMember(i);
                float weight = itemSlot14->FUN_00985bb0();
                if (weight > priority)
                {
                    priority = weight;
                    best = i;
                }
            }
            Threat* strongestSlot10 = ForwardToMember(best);
            Vec weightedSlot17 = DAT_011f426c;
            float total = 0.0f;
            GetParamValues(strongestSlot10, minimum, maximumSlot1);
            for (unsigned int j = 0; j < countSlot11; j++)
            {
                Threat* nearbySlot9 = ForwardToMember(j);
                if (strongestSlot10->FUN_00527a40(*nearbySlot9) > maximumSlot1 * maximumSlot1)
                    continue;
                float value = nearbySlot9->FUN_00985bb0();
                weightedSlot17.FUN_0063c8a0(nearbySlot9->FUN_006815c0().ApplyScaled(value));
                total += value;
            }
            weightedSlot17.ScaleByInverse(total);
            center.SetTripleAndValue(weightedSlot17, strongestSlot10->FUN_0084e3a0());
            origin = strongestSlot10->FUN_006815c0();
            float farthestSlot1 = 0.0f;
            for (unsigned int k = 0; k < countSlot11; k++)
            {
                Threat* other = ForwardToMember(k);
                if (other->FUN_0084e3a0() != center.FUN_0084e3a0())
                    continue;
                float distance = center.FUN_00527a40(*other);
                if (distance > farthestSlot1)
                {
                    farthestSlot1 = distance;
                    if (farthestSlot1 > maximumSlot1 * maximumSlot1)
                        break;
                }
            }
            if (farthestSlot1 > maximumSlot1 * maximumSlot1)
                radius = maximumSlot1;
            else
            {
                radius = FUN_004579e0(farthestSlot1) + *DAT_011ce7b0.FUN_00403e20();
                radius = FUN_0040ebd0(radius, maximumSlot1);
                radius = FUN_00404010(radius, minimum);
            }
        }
        else
        {
            Threat* only = ForwardToMember(0);
            priority = only->FUN_00985bb0();
            center = *only;
            origin = only->FUN_006815c0();
            GetParamValues(only, minimum, maximumSlot1);
            radius = minimum;
        }
    }
    else
    {
        if (center.FUN_0084e3a0())
            return;
        unsigned int actors = FUN_00990890();
        if (actors > 1)
        {
            int lowestSlot13 = 4;
            Actor* selectedSlot46 = 0;
            for (unsigned int a = 0; a < actors; a++)
            {
                Actor* subjectSlot0 = GetIntAt(a);
                int rankSlot1 = subjectSlot0->FUN_00931850();
                if (rankSlot1 < lowestSlot13)
                {
                    lowestSlot13 = rankSlot1;
                    selectedSlot46 = subjectSlot0;
                }
            }
            Position seedSlot0 = selectedSlot46->FUN_00575650();
            Vec sumSlot20 = DAT_011f426c;
            unsigned int includedSlot1 = 0;
            GetParamValues(&seedSlot0, minimum, maximumSlot1);
            for (unsigned int b = 0; b < actors; b++)
            {
                Actor* subjectBSlot11 = GetIntAt(b);
                Position positionB = subjectBSlot11->FUN_00575650();
                if (seedSlot0.FUN_00527a40(positionB) > maximumSlot1 * maximumSlot1)
                    continue;
                sumSlot20.FUN_0063c8a0(positionB.FUN_006815c0());
                includedSlot1++;
            }
            sumSlot20.ScaleByInverse((float)includedSlot1);
            center.SetTripleAndValue(sumSlot20, seedSlot0.FUN_0084e3a0());
            origin = seedSlot0.FUN_006815c0();
            float extentSlot1 = 0.0f;
            for (unsigned int c = 0; c < actors; c++)
            {
                Actor* subjectCSlot0 = GetIntAt(c);
                Position positionCSlot0 = subjectCSlot0->FUN_00575650();
                if (positionCSlot0.FUN_0084e3a0() != center.FUN_0084e3a0())
                    continue;
                float distanceCSlot0 = center.FUN_00527a40(positionCSlot0);
                if (distanceCSlot0 > extentSlot1)
                {
                    extentSlot1 = distanceCSlot0;
                    if (extentSlot1 > maximumSlot1 * maximumSlot1)
                        break;
                }
            }
            if (extentSlot1 > maximumSlot1 * maximumSlot1)
                radius = maximumSlot1;
            else
            {
                radius = FUN_004579e0(extentSlot1) + *DAT_011ce7b0.FUN_00403e20();
                radius = FUN_0040ebd0(radius, maximumSlot1);
                radius = FUN_00404010(radius, minimum);
            }
        }
        else
        {
            Actor* lone = GetIntAt(0);
            center = lone->FUN_00575650();
            origin = center.FUN_006815c0();
            GetParamValues(&center, minimum, maximumSlot1);
            radius = minimum;
        }
    }
}
}

struct NearbyPosition : ClusterPosition
{
    float DistanceTo(const NearbyPosition& other);
};
struct NearbyActor
{
    NearbyPosition FUN_00575650();
};
struct NearbyArray
{
    void* vtable;
    TESObjectREFR** data;
    unsigned int size;
    unsigned int capacity;
    NearbyArray();
    ~NearbyArray();
    unsigned int FUN_0044ddc0();
    TESObjectREFR*& FUN_006a7ad0(unsigned int index);
    void FUN_00729970(int(__cdecl* compare)(const void*, const void*));
    void FUN_0098ebe0(unsigned int first, unsigned int count, bool release);
};
int __cdecl FUN_006bfb30(const void*, const void*);
bool __cdecl FUN_006d9350(unsigned int cell, const ClusterVec& position, float radius, NearbyArray* out);
struct NearbyGroup : GroupReset
{
    unsigned int unkec;
    NearbyPosition position;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    float radius;
    void GetParamValues(NearbyPosition*, float*, float*);
    unsigned int FUN_00990890();
    NearbyActor* GetIntAt(unsigned int index);
    void AddRadioReference(TESObjectREFR* ref);
    void CollectNearbyRefs();
};
// Computes a search radius and member radius from position, gathers refs around the group and each member, sorts and dedups them, then adds each to the group.
// @fnv 0x0098b8c0
void NearbyGroup::CollectNearbyRefs()
{
    float memberRadius;
    {
        unsigned int count;
        {
            float searchRadius;
            {
                NearbyArray entries;
                searchRadius = 0.0f;
                memberRadius = 0.0f;
                GetParamValues(&position, &searchRadius, &memberRadius);
                FUN_006d9350(position.FUN_0084e3a0(), position.FUN_006815c0(), radius, &entries);
                count = FUN_00990890();
                for (unsigned int i = 0; i < count; ++i)
                {
                    NearbyActor* actor = GetIntAt(i);
                    NearbyPosition point = actor->FUN_00575650();
                    if (position.DistanceTo(point) < memberRadius * memberRadius)
                        continue;
                    FUN_006d9350(point.FUN_0084e3a0(), point.FUN_006815c0(), searchRadius, &entries);
                }
                entries.FUN_00729970(FUN_006bfb30);
                for (unsigned int j = 0; j < entries.FUN_0044ddc0(); ++j)
                {
                    unsigned int duplicates;
                    {
                        TESObjectREFR* ref = entries.FUN_006a7ad0(j);
                        duplicates = 0;
                        for (unsigned int k = j + 1; k < entries.FUN_0044ddc0(); ++k)
                        {
                            TESObjectREFR* next = entries.FUN_006a7ad0(k);
                            if (ref != next)
                                break;
                            ++duplicates;
                        }
                        if (duplicates != 0)
                            entries.FUN_0098ebe0(j + 1, duplicates, false);
                    }
                }
                for (unsigned int n = 0; n < entries.FUN_0044ddc0(); ++n)
                    AddRadioReference(entries.FUN_006a7ad0(n));
            }
        }
    }
}

struct ProximityPoint
{
    float x, y, z;
    ProximityPoint(float, float, float);
};
struct ProximityPosition
{
    float Distance(void*, ProximityPoint*);
};
struct ProximityStamp
{
    unsigned value;
    ProximityStamp(float);
    float Seconds();
};
struct ProximityEntry : ProximityPosition
{
    int unk00, unk04, unk08, unk0c, unk10;
    void* key;
    float timer;
    float Age();
};
struct ProximityTarget
{
    int unk00, unk04;
    ProximityPosition pos08;
    int unk0c, unk10, unk14;
    ProximityPosition pos18;
    int unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
    ProximityPosition pos38;
    int unk3c, unk40, unk44, unk48, unk4c;
    ProximityStamp stamp50;
    int unk54;
    ProximityStamp stamp58;
    int unk5c;
    ProximityStamp stamp60;
};
struct ProximitySetting
{
    float* Value();
};
extern ProximitySetting proximitySetting;
struct ProximityGroup
{
    unsigned Count();
    ProximityEntry* Entry(unsigned);
    ProximityTarget* Target(void*);
    void Times(ProximityTarget*, float*, float*, float*);
    void UpdateProximityTimers(void*);
};
// @fnv 0x0098bd70
void ProximityGroup::UpdateProximityTimers(void* position)
{
    float radius5 = *proximitySetting.Value() * *proximitySetting.Value();
    ProximityPoint scale2(1.0f, 1.0f, 0.25f);
    unsigned count2 = Count();
    for (unsigned index3 = 0; index3 < count2; ++index3)
    {
        ProximityEntry* entryB = Entry(index3);
        if (entryB->Distance(position, &scale2) < radius5)
        {
            float age = entryB->Age();
            if (age > 30.0)
                entryB->timer -= age - 30.0;
            if (entryB->key)
            {
                ProximityTarget* targetVal = Target(entryB->key);
                if (targetVal)
                {
                    float first2, second3, third6;
                    Times(targetVal, &first2, &second3, &third6);
                    if (first2 > 30.0 && targetVal->pos18.Distance(position, &scale2) < radius5)
                    {
                        ProximityStamp stamp3(targetVal->stamp50.Seconds() - (first2 - 30.0));
                        targetVal->stamp50.value = stamp3.value;
                    }
                    if (second3 > 30.0 && targetVal->pos08.Distance(position, &scale2) < radius5)
                    {
                        ProximityStamp stampA(targetVal->stamp58.Seconds() - (second3 - 30.0));
                        targetVal->stamp58.value = stampA.value;
                    }
                    if (third6 > 30.0 && targetVal->pos38.Distance(position, &scale2) < radius5)
                    {
                        ProximityStamp stamp5(targetVal->stamp60.Seconds() - (third6 - 30.0));
                        targetVal->stamp60.value = stamp5.value;
                    }
                }
            }
        }
    }
}

struct WeightedVector
{
    float x, y, z;
    WeightedVector ApplyScaled(float closest);
    WeightedVector& FUN_0063c8a0(const WeightedVector& other);
    WeightedVector& ScaleByInverse(float divisor);
};
struct WeightedPosition
{
    WeightedVector vector;
    unsigned cell;
    void FUN_0097ede0();
    void FUN_0043a3c0(const WeightedVector& vector, unsigned cell);
    WeightedVector& FUN_006815c0();
    unsigned FUN_0084e3a0();
};
struct WeightedMember
{
    WeightedPosition* actor;
    unsigned unk04;
    WeightedPosition current;
    WeightedPosition first;
    unsigned unk28, unk2c, unk30, unk34;
    WeightedPosition second;
};
struct ExpiringPosition
{
    WeightedPosition position;
    unsigned unk10, active;
    float FUN_00985bb0();
};
struct ExpiringPositions : FUN_0098f430_Class
{
    unsigned FUN_0044ddc0();
    ExpiringPosition* GetElementAt(unsigned index);
};
struct PositionGroup : GroupReset
{
    unsigned unkec, unkf0, unkf4, unkf8, unkfc;
    NiPoint3 unk100;
    unsigned unk10c;
    ExpiringPositions positions;
    void FUN_0098c060(WeightedMember*, float*, float*, float*);
    void StoreRecord(WeightedPosition*, float, unsigned);
    void UpdateExpiringPositions();
};
float __cdecl FUN_00404010(float, float);

// Removes expired or active entries from positions, then recomputes and stores weighted positions for each member based on its weights.
// @fnv 0x0098c0d0
void PositionGroup::UpdateExpiringPositions()
{
    for (unsigned i = 0; i < positions.FUN_0044ddc0(); ++i)
    {
        ExpiringPosition* entry = positions.GetElementAt(i);
        float age = entry->FUN_00985bb0();
        if (age < 0.0 || entry->active != 0)
        {
            positions.FUN_0098f430(i, 1);
            --i;
        }
    }
    unsigned count = FUN_005a4320();
    for (unsigned j = 0; j < count; ++j)
    {
        WeightedMember* currentWeight = reinterpret_cast<WeightedMember*>(FUN_009871c0(j));
        float member, firstWeight, secondWeight;
        FUN_0098c060(currentWeight, &member, &firstWeight, &secondWeight);
        if (member > 0.0 || firstWeight > 0.0 || secondWeight > 0.0)
        {
            if (member > firstWeight || secondWeight > firstWeight)
            {
                if (member >= secondWeight)
                    StoreRecord(&currentWeight->first, member, currentWeight->actor->FUN_0084e3a0());
                else
                    StoreRecord(&currentWeight->second, secondWeight, currentWeight->actor->FUN_0084e3a0());
            }
            else if (firstWeight > 0.0)
            {
                WeightedPosition weight;
                weight.FUN_0097ede0();
                float closest = FUN_00404010(member, secondWeight);
                if (closest > 0.0)
                {
                    if (member > secondWeight)
                        weight = currentWeight->first;
                    else
                        weight = currentWeight->second;
                }
                if (closest > 0.0 && weight.FUN_0084e3a0() == currentWeight->current.FUN_0084e3a0())
                {
                    WeightedVector combinedVector = weight.FUN_006815c0().ApplyScaled(closest);
                    combinedVector.FUN_0063c8a0(currentWeight->current.FUN_006815c0().ApplyScaled(firstWeight));
                    combinedVector.ScaleByInverse(closest + firstWeight);
                    WeightedPosition position;
                    position.FUN_0043a3c0(combinedVector, currentWeight->current.FUN_0084e3a0());
                    StoreRecord(&position, firstWeight, currentWeight->actor->FUN_0084e3a0());
                }
                else
                {
                    StoreRecord(&currentWeight->current, firstWeight, currentWeight->actor->FUN_0084e3a0());
                }
            }
        }
    }
}

struct GroupScoreSource
{
    float GetFirstLightParameter();
};
struct GroupController
{
    GroupScoreSource* FUN_00586150();
    bool FUN_00981990();
};
struct GroupActor
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
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Slot45();
    virtual void Slot46();
    virtual void Slot47();
    virtual void Slot48();
    virtual void Slot49();
    virtual void Slot50();
    virtual void Slot51();
    virtual void Slot52();
    virtual void Slot53();
    virtual void Slot54();
    virtual void Slot55();
    virtual void Slot56();
    virtual void Slot57();
    virtual void Slot58();
    virtual void Slot59();
    virtual void Slot60();
    virtual void Slot61();
    virtual void Slot62();
    virtual void Slot63();
    virtual void Slot64();
    virtual void Slot65();
    virtual void Slot66();
    virtual void Slot67();
    virtual void Slot68();
    virtual void Slot69();
    virtual void Slot70();
    virtual void Slot71();
    virtual void Slot72();
    virtual void Slot73();
    virtual void Slot74();
    virtual void Slot75();
    virtual void Slot76();
    virtual void Slot77();
    virtual void Slot78();
    virtual void Slot79();
    virtual void Slot80();
    virtual void Slot81();
    virtual void Slot82();
    virtual void Slot83();
    virtual void Slot84();
    virtual void Slot85();
    virtual void Slot86();
    virtual void Slot87();
    virtual void Slot88();
    virtual void Slot89();
    virtual void Slot90();
    virtual void Slot91();
    virtual void Slot92();
    virtual void Slot93();
    virtual void Slot94();
    virtual void Slot95();
    virtual void Slot96();
    virtual void Slot97();
    virtual void Slot98();
    virtual void Slot99();
    virtual void Slot100();
    virtual void Slot101();
    virtual void Slot102();
    virtual void Slot103();
    virtual void Slot104();
    virtual void Slot105();
    virtual void Slot106();
    virtual void Slot107();
    virtual void Slot108();
    virtual void Slot109();
    virtual void Slot110();
    virtual void Slot111();
    virtual void Slot112();
    virtual void Slot113();
    virtual void Slot114();
    virtual void Slot115();
    virtual void Slot116();
    virtual void Slot117();
    virtual void Slot118();
    virtual void Slot119();
    virtual void Slot120();
    virtual void Slot121();
    virtual void Slot122();
    virtual void Slot123();
    virtual void Slot124();
    virtual void Slot125();
    virtual void Slot126();
    virtual void Slot127();
    virtual void Slot128();
    virtual void Slot129();
    virtual void Slot130();
    virtual void Slot131();
    virtual void Slot132();
    virtual void Slot133();
    virtual void Slot134();
    virtual void Slot135();
    virtual void Slot136();
    virtual void Slot137();
    virtual void Slot138();
    virtual void Slot139();
    virtual void Slot140();
    virtual void Slot141();
    virtual void Slot142();
    virtual void Slot143();
    virtual void Slot144();
    virtual void Slot145();
    virtual void Slot146();
    virtual void Slot147();
    virtual void Slot148();
    virtual void Slot149();
    virtual void Slot150();
    virtual void Slot151();
    virtual void Slot152();
    virtual void Slot153();
    virtual void Slot154();
    virtual void Slot155();
    virtual void Slot156();
    virtual void Slot157();
    virtual void Slot158();
    virtual void Slot159();
    virtual void Slot160();
    virtual void Slot161();
    virtual void Slot162();
    virtual void Slot163();
    virtual void Slot164();
    virtual void Slot165();
    virtual void Slot166();
    virtual void Slot167();
    virtual void Slot168();
    virtual void Slot169();
    virtual void Slot170();
    virtual void Slot171();
    virtual void Slot172();
    virtual void Slot173();
    virtual void Slot174();
    virtual void Slot175();
    virtual void Slot176();
    virtual void Slot177();
    virtual void Slot178();
    virtual void Slot179();
    virtual void Slot180();
    virtual void Slot181();
    virtual void Slot182();
    virtual void Slot183();
    virtual void Slot184();
    virtual void Slot185();
    virtual void Slot186();
    virtual void Slot187();
    virtual void Slot188();
    virtual void Slot189();
    virtual void Slot190();
    virtual void Slot191();
    virtual void Slot192();
    virtual void Slot193();
    virtual void Slot194();
    virtual void Slot195();
    virtual void Slot196();
    virtual void Slot197();
    virtual void Slot198();
    virtual void Slot199();
    virtual void Slot200();
    virtual void Slot201();
    virtual void Slot202();
    virtual void Slot203();
    virtual void Slot204();
    virtual void Slot205();
    virtual void Slot206();
    virtual void Slot207();
    virtual void Slot208();
    virtual void Slot209();
    virtual void Slot210();
    virtual void Slot211();
    virtual void Slot212();
    virtual void Slot213();
    virtual void Slot214();
    virtual void Slot215();
    virtual void Slot216();
    virtual void Slot217();
    virtual void Slot218();
    virtual void Slot219();
    virtual void Slot220();
    virtual void Slot221();
    virtual void Slot222();
    virtual void Slot223();
    virtual void Slot224();
    virtual void Slot225();
    virtual void Slot226();
    virtual void Slot227();
    virtual void Slot228();
    virtual void Slot229();
    virtual void Slot230();
    virtual void Slot231();
    virtual void Slot232();
    virtual void Slot233();
    virtual void Slot234();
    virtual void Slot235();
    virtual void Slot236();
    virtual void Slot237();
    virtual void Slot238();
    virtual void Slot239();
    virtual void Slot240();
    virtual void Slot241();
    virtual void Slot242();
    virtual void Slot243();
    virtual void Slot244();
    virtual void Slot245();
    virtual void Slot246();
    virtual void Slot247();
    virtual void Slot248();
    virtual void Slot249();
    virtual void Slot250();
    virtual void Slot251();
    virtual void Slot252();
    virtual void Slot253();
    virtual void Slot254();
    virtual void Slot255();
    virtual void Slot256();
    virtual void Slot257();
    virtual void Slot258();
    virtual void Slot259();
    virtual void Slot260();
    virtual void Slot261();
    virtual void Slot262();
    virtual void Slot263();
    virtual void Slot264();
    virtual void Slot265();
    virtual GroupController* Controller();
};
struct GroupScoreRecord
{
    GroupActor* actor;
    int unk04;
    float score;
    float time;
};
struct GroupScore
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
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    float cached;
    unsigned int FUN_00990890();
    GroupScoreRecord* FUN_00988790(unsigned int);
    float GetAverageScore(GroupActor*);
};
// @fnv 0x0098cc20
float GroupScore::GetAverageScore(GroupActor* requested)
{
    if (!requested)
        return cached;
    float total = 0.0f;
    unsigned int size = FUN_00990890();
    unsigned int count7 = 0;
    for (unsigned int indexX = 0; indexX < size; indexX++)
    {
        GroupScoreRecord* memberX = FUN_00988790(indexX);
        GroupController* controller = memberX->actor->Controller();
        if (requested == memberX->actor && controller)
        {
            float score2 = controller->FUN_00586150()->GetFirstLightParameter();
            if (score2 > 0.0)
            {
                total += score2;
                count7++;
            }
        }
        else
        {
            if ((!controller || !controller->FUN_00981990()) && memberX->time >= 0.0)
            {
                total += memberX->score;
                count7++;
            }
        }
    }
    if (count7)
        total /= count7;
    return total;
}

struct CombatActor_98d030 : VirtualLevel<138, CombatActor_98d030>
{
    virtual bool IsUnavailable(int) = 0;
};
struct Member_98d030
{
    CombatActor_98d030* actor;
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c;
    GroupStamp stamp;
};
struct Target_98d030;
struct Manager_98d030
{
    void Notify(Target_98d030* target, CombatActor_98d030* actor, int a, int b, int c, int d);
};
extern CombatActor_98d030* g_thePlayer;
extern float DAT_0108cb00;
struct Group_98d030
{
    unsigned int FUN_005a4320();
    Member_98d030* GetMember(unsigned int index);
    bool ShouldRemove(Member_98d030* member);
    Target_98d030* FindTarget(CombatActor_98d030* actor, float radius);
    void RemoveMemberAt(unsigned int index);
    void FUN_0098d030();
};

// Iterates members, removes those ShouldRemove; for a sole member finds a target and notifies the manager with code 4 before removal.
// @fnv 0x0098d030
void Group_98d030::FUN_0098d030()
{
    unsigned int count = FUN_005a4320();
    if (count != 0)
    {
        int unused4 = 0;
        FUN_00435de0 stamp_2(-DAT_0108d540);
        for (unsigned int i = 0; i < count; i++)
        {
            Member_98d030* member2 = GetMember(i);
            if (ShouldRemove(member2))
            {
                if (count == 1)
                {
                    Target_98d030* target = FindTarget(member2->actor, DAT_0108cb00);
                    if (target == 0)
                        target = FindTarget(g_thePlayer, DAT_0108cb00);
                    if (target != 0 && !member2->actor->IsUnavailable(0))
                    {
                        if (member2->stamp.FUN_006a7f50() != -DAT_0108d540)
                            ((Manager_98d030*)DAT_011f1708)->Notify(target, member2->actor, 4, 8, 1, 0);
                        else
                            ((Manager_98d030*)DAT_011f1708)->Notify(target, member2->actor, 4, 5, 1, 0);
                    }
                }
                RemoveMemberAt(i);
                i--;
                count--;
            }
        }
    }
}

struct SavedCombatState;
struct CombatWriter
{
    void FUN_00865f60(unsigned int);
    void FUN_00865e50(const void*, unsigned int, int);
    void FUN_00865df0(void*, int);
    void FUN_00865db0(void*, int);
};
struct CombatPair
{
    unsigned int first, second;
    void FUN_009a5eb0(CombatWriter*);
};
struct CombatValue
{
    unsigned int value;
    void SaveTimeStamp(CombatWriter*);
};
struct CombatRecord
{
    int unk00, unk04, unk08, unk0c;
    void FUN_00527b70(CombatWriter*);
};
struct CombatReferenceEntry
{
    CombatRecord record;
    CombatValue value;
    void* form;
    unsigned int flags;
    void FUN_00527b70(CombatWriter*);
};
struct CombatEdge
{
    void* first;
    void* second;
    unsigned char a, b, c, d;
};
struct CombatTask
{
    void FUN_00985ae0(CombatWriter*, SavedCombatState*);
};
struct CombatTarget
{
    void FUN_009856e0(CombatWriter*, SavedCombatState*);
};
struct CombatAction
{
    void FUN_009859c0(CombatWriter*, SavedCombatState*);
};
struct CombatArray
{
    void* table;
    void* data;
    unsigned int count, capacity;
    unsigned int FUN_0044ddc0();
    CombatTask** FUN_006a7ad0(unsigned int);
    CombatTarget* FUN_0096a2b0(unsigned int);
    CombatAction* FUN_006dad90(unsigned int);
    CombatReferenceEntry* GetElementAt(unsigned int);
    CombatEdge* FUN_006a7af0(unsigned int);
};
struct CombatMode
{
    int FUN_00726070();
};
struct CombatPath
{
    void SaveGame(CombatWriter*);
};
struct CombatPathRef
{
    CombatPath* ptr;
    CombatPath* FUN_00559450();
};
struct SavedCombatState
{
    int unk00, unk04;
    CombatArray targets, actions;
    CombatMode* mode;
    unsigned int flags2c;
    CombatPair pair30, pair38;
    int flags40;
    CombatValue value44;
    CombatPair pair48, pair50;
    CombatPair values[10];
    CombatPair paira8, pairb0, pairb8;
    unsigned int fieldc0, fieldc4, fieldc8, fieldcc, fieldd0;
    CombatPathRef path;
    CombatPair paird8, paire0;
    CombatValue valuee8;
    void* formec;
    CombatRecord record;
    float x, y, z;
    unsigned int field10c;
    CombatArray items, edges;
    int unk130, unk134;
    CombatArray tasks;
    int unk148, unk14c, unk150;
    unsigned char flags154;
    void WriteToStream(CombatWriter*);
};
// Serializes the combat state to the writer: task, target and action arrays, mode, flags, pairs, values, and optional path/items/edges when fieldd0 > 0.
// @fnv 0x0098de90
void SavedCombatState::WriteToStream(CombatWriter* writer)
{
    {
        unsigned int count = &tasks ? tasks.FUN_0044ddc0() : 0;
        writer->FUN_00865f60(count);
        for (unsigned int i = 0; i < count; ++i)
        {
            CombatTask** item = tasks.FUN_006a7ad0(i);
            (*item)->FUN_00985ae0(writer, this);
        }
    }
    {
        unsigned int count = &targets ? targets.FUN_0044ddc0() : 0;
        writer->FUN_00865f60(count);
        for (unsigned int i = 0; i < count; ++i)
        {
            CombatTarget* item = targets.FUN_0096a2b0(i);
            item->FUN_009856e0(writer, this);
        }
    }
    {
        unsigned int count = &actions ? actions.FUN_0044ddc0() : 0;
        writer->FUN_00865f60(count);
        for (unsigned int i = 0; i < count; ++i)
        {
            CombatAction* item = actions.FUN_006dad90(i);
            item->FUN_009859c0(writer, this);
        }
    }
    unsigned char type = mode ? mode->FUN_00726070() : -1;
    writer->FUN_00865e50(&type, 1, 0);
    writer->FUN_00865e50(&flags2c, 1, 0);
    pair30.FUN_009a5eb0(writer);
    pair38.FUN_009a5eb0(writer);
    writer->FUN_00865e50(&flags40, 4, 0);
    value44.SaveTimeStamp(writer);
    pair48.FUN_009a5eb0(writer);
    pairb0.FUN_009a5eb0(writer);
    paira8.FUN_009a5eb0(writer);
    for (unsigned int i = 0; i < 10; ++i)
        values[i].FUN_009a5eb0(writer);
    writer->FUN_00865e50(&fieldd0, 4, 0);
    if (fieldd0 > 0)
    {
        writer->FUN_00865df0(formec, 0);
        writer->FUN_00865e50(&x, 12, 0);
        paird8.FUN_009a5eb0(writer);
        paire0.FUN_009a5eb0(writer);
        valuee8.SaveTimeStamp(writer);
        record.FUN_00527b70(writer);
        writer->FUN_00865e50(&field10c, 4, 0);
        {
            unsigned int count = &items ? items.FUN_0044ddc0() : 0;
            writer->FUN_00865f60(count);
            for (unsigned int i = 0; i < count; ++i)
            {
                CombatReferenceEntry* item = items.GetElementAt(i);
                item->FUN_00527b70(writer);
                writer->FUN_00865e50(&item->flags, 4, 0);
                writer->FUN_00865db0(item->form, 0);
                item->value.SaveTimeStamp(writer);
            }
        }
        {
            unsigned int count = &edges ? edges.FUN_0044ddc0() : 0;
            writer->FUN_00865f60(count);
            for (unsigned int i = 0; i < count; ++i)
            {
                CombatEdge* item = edges.FUN_006a7af0(i);
                writer->FUN_00865df0(item->first, 0);
                writer->FUN_00865df0(item->second, 0);
                writer->FUN_00865e50(&item->a, 1, 0);
                writer->FUN_00865e50(&item->b, 1, 0);
                writer->FUN_00865e50(&item->c, 1, 0);
            }
        }
        bool hasPath = bool(path.FUN_00559450());
        writer->FUN_00865e50(&hasPath, 1, 0);
        if (hasPath)
            path.FUN_00559450()->SaveGame(writer);
    }
    pair50.FUN_009a5eb0(writer);
    writer->FUN_00865e50(&fieldc0, 4, 0);
    writer->FUN_00865e50(&fieldc4, 4, 0);
    writer->FUN_00865e50(&fieldc8, 4, 0);
    writer->FUN_00865e50(&fieldcc, 4, 0);
    pairb8.FUN_009a5eb0(writer);
    writer->FUN_00865e50(&flags154, 1, 0);
}

struct ThreatObjA
{
    ThreatObjA();
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};
struct ThreatObjB
{
    ThreatObjB();
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};
struct ThreatObjC
{
    ThreatObjC();
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};
struct ThreatObjD
{
    ThreatObjD(int arg);
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

struct ThreatMapInit
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    ThreatObjD* unk10;
    ThreatObjB* unk14;
    ThreatObjA* unk18;
    ThreatObjC* unk1C;
    void InitThreatObjects();
};

// Allocates and stores a ThreatObjA, ThreatObjB, ThreatObjC and a ThreatObjD constructed with 0x25 into the map's fields.
// @fnv 0x009911c0
void ThreatMapInit::InitThreatObjects()
{
    unk18 = new ThreatObjA();
    unk14 = new ThreatObjB();
    unk1C = new ThreatObjC();
    unk10 = new ThreatObjD(0x25);
}

struct FUN_009914d0
{
    ~FUN_009914d0();
    void FUN_00986b70();
};

struct ThreatOwned991
{
    virtual ~ThreatOwned991();
};

struct ThreatNode991
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void ReleaseByName(const char* pcName);
};

struct ThreatName991
{
    ThreatNode991* FUN_009611e0();
};

struct ThreatString991
{
    void* m_pcData;

    const char* FUN_00559450() const;
    ThreatString991& FUN_0066b0d0(const char* pcValue);
};

struct ThreatArray991
{
    void* m_pvVtbl;
    FUN_009914d0** m_ppData;
    unsigned int m_uiCapacity;
    unsigned int m_uiCount;

    unsigned int GetShortAtOffsetA() const;
    FUN_009914d0*& FUN_00877a30(unsigned int uiIndex);
};

void __fastcall FUN_005e03d0(ThreatArray991* pArray);
void __fastcall FUN_00438af0(void* pvObject);

struct FUN_00991310_shell : ThreatArray991
{
    ThreatOwned991* m_p10;
    ThreatOwned991* m_p14;
    ThreatOwned991* m_p18;
    ThreatOwned991* m_p1c;
    char pad20[0x18];
    ThreatString991 m_kName;

    void ClearAndDestroy(bool bReset);
};

// Deletes each array entry (optionally resetting it first), clears the array, deletes the owned pointers, and releases the name string.
// @fnv 0x00991310
void FUN_00991310_shell::ClearAndDestroy(bool bReset)
{
    for (unsigned int i = 0; i < GetShortAtOffsetA(); i++)
    {
        FUN_009914d0* pkEntry = FUN_00877a30(i);
        if (pkEntry)
        {
            if (bReset)
                pkEntry->FUN_00986b70();
            delete pkEntry;
        }
    }
    FUN_005e03d0(this);
    delete m_p18;
    delete m_p14;
    delete m_p1c;
    FUN_00438af0(m_p10);
    delete m_p10;
    if (m_kName.FUN_00559450() && ((ThreatName991*)m_kName.FUN_00559450())->FUN_009611e0())
        ((ThreatName991*)m_kName.FUN_00559450())->FUN_009611e0()->ReleaseByName(m_kName.FUN_00559450());
    m_kName.FUN_0066b0d0(0);
}

struct CM993Key
{
    unsigned int ComputeHash();
};
struct CM993Name
{
    int FUN_00559450();
};
struct CM993Src
{
    int m_00;
    CM993Key* m_04;
    int m_08;
    CM993Name m_0c;
};
struct CM993SrcArray
{
    unsigned int FUN_0044ddc0();
    CM993Src*& FUN_006a7ad0(unsigned int index);
};
struct CM993DstArray
{
    CM993Key*& FUN_006a7ad0(unsigned int index);
};
struct CM993Item
{
    int m_00;
    CM993Item* m_04;
    unsigned int m_08;
    int m_0c;
};
struct CM993List
{
    CM993Item** m_items;
    unsigned int m_uiItemCount;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    void AllocateItemArray(int count);
    void UpdateAllItems(int arg);
    CM993List* InitFromSources(int a1, int a2, CM993DstArray* keys, CM993SrcArray* srcs, int a5);
};

// Initializes the list from srcs and keys, copies each source's fields and key value into items, links parents by key, then calls UpdateAllItems(a5).
// @fnv 0x00993db0
CM993List* CM993List::InitFromSources(int a1, int a2, CM993DstArray* keys, CM993SrcArray* srcs, int a5)
{
    m_08 = 0;
    m_0c = a2;
    m_10 = -1;
    m_14 = a1;
    AllocateItemArray(srcs->FUN_0044ddc0());
    for (unsigned int i = 0; i < m_uiItemCount; i++)
    {
        CM993Src* src = srcs->FUN_006a7ad0(m_uiItemCount - i - 1);
        CM993Key* key = keys->FUN_006a7ad0(m_uiItemCount - i);
        m_items[i]->m_00 = src->m_00;
        m_items[i]->m_0c = src->m_08;
        m_items[i]->m_08 = key->ComputeHash();
        m_items[i]->m_04 = 0;
        if (src->m_0c.FUN_00559450() != -1)
            m_10 = src->m_0c.FUN_00559450();
    }
    for (unsigned int j = 0; j < m_uiItemCount; j++)
    {
        CM993Src* entry = srcs->FUN_006a7ad0(m_uiItemCount - j - 1);
        unsigned int parentKey = entry->m_04->ComputeHash();
        for (unsigned int k = 0; k < m_uiItemCount; k++)
        {
            if (m_items[k]->m_08 == parentKey)
            {
                m_items[j]->m_04 = m_items[k];
                break;
            }
        }
    }
    UpdateAllItems(a5);
    return this;
}

struct BuildOwner;
struct BuildInput
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
    int valid;
};
struct BuildFirst
{
    int unk00, unk04, unk08, unk0c, unk10;
    BuildFirst();
    ~BuildFirst();
};
struct BuildSecond
{
    int unk00, unk04, unk08, unk0c, unk10;
    BuildSecond();
    ~BuildSecond();
    unsigned int FUN_0044ddc0();
};
struct BuildContext
{
    int unk00;
};
struct BuildResult
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    BuildResult(int, int, BuildFirst*, BuildSecond*, BuildContext*);
};
struct BuildMonitor
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
    BuildMonitor(BuildOwner*, BuildResult*, BuildFirst*);
};
struct BuildOwner
{
    int unk0000, unk0004, unk0008, unk000c;
    int unk0010, unk0014, unk0018, unk001c;
    int unk0020, unk0024, unk0028, unk002c;
    int unk0030, unk0034, unk0038, unk003c;
    int unk0040, unk0044, unk0048, unk004c;
    int unk0050, unk0054, unk0058, unk005c;
    int unk0060, unk0064, unk0068, unk006c;
    int unk0070, unk0074, unk0078, unk007c;
    int unk0080, unk0084, unk0088, unk008c;
    int unk0090, unk0094, unk0098, unk009c;
    int unk00a0, unk00a4, unk00a8, unk00ac;
    int unk00b0, unk00b4, unk00b8, unk00bc;
    int unk00c0, unk00c4, unk00c8, unk00cc;
    int unk00d0, unk00d4, unk00d8, unk00dc;
    int unk00e0, unk00e4, unk00e8, unk00ec;
    int unk00f0, unk00f4, unk00f8, unk00fc;
    int unk0100, unk0104, unk0108, unk010c;
    int unk0110, unk0114, unk0118, unk011c;
    int unk0120, unk0124, unk0128, unk012c;
    int unk0130, unk0134, unk0138, unk013c;
    int unk0140, unk0144, unk0148, unk014c;
    int unk0150, unk0154, unk0158, unk015c;
    int unk0160, unk0164, unk0168, unk016c;
    int unk0170, unk0174, unk0178, unk017c;
    int unk0180, unk0184, unk0188, unk018c;
    int unk0190, unk0194, unk0198, unk019c;
    int unk01a0, unk01a4, unk01a8, unk01ac;
    int unk01b0, unk01b4, unk01b8, unk01bc;
    int unk01c0, unk01c4, unk01c8, unk01cc;
    int unk01d0, unk01d4, unk01d8, unk01dc;
    int unk01e0, unk01e4, unk01e8, unk01ec;
    int unk01f0, unk01f4, unk01f8, unk01fc;
    int unk0200, unk0204, unk0208, unk020c;
    int unk0210, unk0214, unk0218, unk021c;
    int unk0220, unk0224, unk0228, unk022c;
    int unk0230, unk0234, unk0238, unk023c;
    int unk0240, unk0244, unk0248, unk024c;
    int unk0250, unk0254, unk0258, unk025c;
    int unk0260, unk0264, unk0268, unk026c;
    int unk0270, unk0274, unk0278, unk027c;
    int unk0280, unk0284, unk0288, unk028c;
    int unk0290, unk0294, unk0298, unk029c;
    int unk02a0, unk02a4, unk02a8, unk02ac;
    int unk02b0, unk02b4, unk02b8, unk02bc;
    int unk02c0, unk02c4, unk02c8, unk02cc;
    int unk02d0, unk02d4, unk02d8, unk02dc;
    int unk02e0, unk02e4, unk02e8, unk02ec;
    int unk02f0, unk02f4, unk02f8, unk02fc;
    int unk0300, unk0304, unk0308, unk030c;
    int unk0310, unk0314, unk0318, unk031c;
    int unk0320, unk0324, unk0328, unk032c;
    int unk0330, unk0334, unk0338, unk033c;
    int unk0340, unk0344, unk0348, unk034c;
    int unk0350, unk0354, unk0358, unk035c;
    int unk0360, unk0364, unk0368, unk036c;
    int unk0370, unk0374, unk0378, unk037c;
    int unk0380, unk0384, unk0388, unk038c;
    int unk0390, unk0394, unk0398, unk039c;
    int unk03a0, unk03a4, unk03a8, unk03ac;
    int unk03b0, unk03b4, unk03b8, unk03bc;
    int unk03c0, unk03c4, unk03c8, unk03cc;
    int unk03d0, unk03d4, unk03d8, unk03dc;
    int unk03e0, unk03e4, unk03e8, unk03ec;
    int unk03f0, unk03f4, unk03f8, unk03fc;
    int unk0400, unk0404, unk0408, unk040c;
    int unk0410, unk0414, unk0418, unk041c;
    int unk0420, unk0424, unk0428, unk042c;
    int unk0430, unk0434, unk0438, unk043c;
    int unk0440, unk0444, unk0448, unk044c;
    int unk0450, unk0454, unk0458, unk045c;
    int unk0460, unk0464, unk0468, unk046c;
    int unk0470, unk0474, unk0478, unk047c;
    int unk0480, unk0484, unk0488, unk048c;
    int unk0490, unk0494, unk0498, unk049c;
    int unk04a0, unk04a4, unk04a8, unk04ac;
    int unk04b0, unk04b4, unk04b8, unk04bc;
    int unk04c0, unk04c4, unk04c8, unk04cc;
    int unk04d0, unk04d4, unk04d8, unk04dc;
    int unk04e0, unk04e4, unk04e8, unk04ec;
    int unk04f0, unk04f4, unk04f8, unk04fc;
    int unk0500, unk0504, unk0508, unk050c;
    int unk0510, unk0514, unk0518, unk051c;
    int unk0520, unk0524, unk0528, unk052c;
    int unk0530, unk0534, unk0538, unk053c;
    int unk0540, unk0544, unk0548, unk054c;
    int unk0550, unk0554, unk0558, unk055c;
    int unk0560, unk0564, unk0568, unk056c;
    int unk0570, unk0574, unk0578, unk057c;
    int unk0580, unk0584, unk0588, unk058c;
    int unk0590, unk0594, unk0598, unk059c;
    int unk05a0, unk05a4, unk05a8, unk05ac;
    int unk05b0, unk05b4, unk05b8, unk05bc;
    int unk05c0, unk05c4, unk05c8, unk05cc;
    int unk05d0, unk05d4, unk05d8, unk05dc;
    int unk05e0, unk05e4, unk05e8, unk05ec;
    int unk05f0, unk05f4, unk05f8, unk05fc;
    int unk0600, unk0604, unk0608, unk060c;
    int unk0610, unk0614, unk0618, unk061c;
    int unk0620, unk0624, unk0628, unk062c;
    int unk0630, unk0634, unk0638, unk063c;
    int unk0640, unk0644, unk0648, unk064c;
    int unk0650, unk0654, unk0658, unk065c;
    int unk0660, unk0664, unk0668, unk066c;
    int unk0670, unk0674, unk0678, unk067c;
    int unk0680, unk0684, unk0688, unk068c;
    int unk0690, unk0694, unk0698, unk069c;
    int unk06a0, unk06a4, unk06a8, unk06ac;
    int unk06b0, unk06b4, unk06b8, unk06bc;
    int unk06c0, unk06c4, unk06c8, unk06cc;
    int unk06d0, unk06d4, unk06d8, unk06dc;
    int unk06e0, unk06e4, unk06e8, unk06ec;
    int unk06f0, unk06f4, unk06f8, unk06fc;
    int unk0700, unk0704, unk0708, unk070c;
    int unk0710, unk0714, unk0718, unk071c;
    int unk0720, unk0724, unk0728, unk072c;
    int unk0730, unk0734, unk0738, unk073c;
    int unk0740, unk0744, unk0748, unk074c;
    int unk0750, unk0754, unk0758, unk075c;
    int unk0760, unk0764, unk0768, unk076c;
    int unk0770, unk0774, unk0778, unk077c;
    int unk0780, unk0784, unk0788, unk078c;
    int unk0790, unk0794, unk0798, unk079c;
    int unk07a0, unk07a4, unk07a8, unk07ac;
    int unk07b0, unk07b4, unk07b8, unk07bc;
    int unk07c0, unk07c4, unk07c8, unk07cc;
    int unk07d0, unk07d4, unk07d8, unk07dc;
    int unk07e0, unk07e4, unk07e8, unk07ec;
    int unk07f0, unk07f4, unk07f8, unk07fc;
    int unk0800, unk0804, unk0808, unk080c;
    int unk0810, unk0814, unk0818, unk081c;
    int unk0820, unk0824, unk0828, unk082c;
    int unk0830, unk0834, unk0838, unk083c;
    int unk0840, unk0844, unk0848, unk084c;
    int unk0850, unk0854, unk0858, unk085c;
    int unk0860, unk0864, unk0868, unk086c;
    int unk0870, unk0874, unk0878, unk087c;
    int unk0880, unk0884, unk0888, unk088c;
    int unk0890, unk0894, unk0898, unk089c;
    int unk08a0, unk08a4, unk08a8, unk08ac;
    int unk08b0, unk08b4, unk08b8, unk08bc;
    int unk08c0, unk08c4, unk08c8, unk08cc;
    int unk08d0, unk08d4, unk08d8, unk08dc;
    int unk08e0, unk08e4, unk08e8, unk08ec;
    int unk08f0, unk08f4, unk08f8, unk08fc;
    int unk0900, unk0904, unk0908, unk090c;
    int unk0910, unk0914, unk0918, unk091c;
    int unk0920, unk0924, unk0928, unk092c;
    int unk0930, unk0934, unk0938, unk093c;
    int unk0940, unk0944, unk0948, unk094c;
    int unk0950, unk0954, unk0958, unk095c;
    int unk0960, unk0964, unk0968, unk096c;
    int unk0970, unk0974, unk0978, unk097c;
    int unk0980, unk0984, unk0988, unk098c;
    int unk0990, unk0994, unk0998, unk099c;
    int unk09a0, unk09a4, unk09a8, unk09ac;
    int unk09b0, unk09b4, unk09b8, unk09bc;
    int unk09c0, unk09c4, unk09c8, unk09cc;
    int unk09d0, unk09d4, unk09d8, unk09dc;
    int unk09e0, unk09e4, unk09e8, unk09ec;
    int unk09f0, unk09f4, unk09f8, unk09fc;
    int unk0a00, unk0a04, unk0a08, unk0a0c;
    int unk0a10, unk0a14, unk0a18, unk0a1c;
    int unk0a20, unk0a24, unk0a28, unk0a2c;
    int unk0a30, unk0a34, unk0a38, unk0a3c;
    int unk0a40, unk0a44, unk0a48, unk0a4c;
    int unk0a50, unk0a54, unk0a58, unk0a5c;
    int unk0a60, unk0a64, unk0a68, unk0a6c;
    int unk0a70, unk0a74, unk0a78, unk0a7c;
    int unk0a80, unk0a84, unk0a88, unk0a8c;
    int unk0a90, unk0a94, unk0a98, unk0a9c;
    int unk0aa0, unk0aa4, unk0aa8, unk0aac;
    int unk0ab0, unk0ab4, unk0ab8, unk0abc;
    int unk0ac0, unk0ac4, unk0ac8, unk0acc;
    int unk0ad0, unk0ad4, unk0ad8, unk0adc;
    int unk0ae0, unk0ae4, unk0ae8, unk0aec;
    int unk0af0, unk0af4, unk0af8, unk0afc;
    int unk0b00, unk0b04, unk0b08, unk0b0c;
    int unk0b10, unk0b14, unk0b18, unk0b1c;
    int unk0b20, unk0b24, unk0b28, unk0b2c;
    int unk0b30, unk0b34, unk0b38, unk0b3c;
    int unk0b40, unk0b44, unk0b48, unk0b4c;
    int unk0b50, unk0b54, unk0b58, unk0b5c;
    int unk0b60, unk0b64, unk0b68, unk0b6c;
    int unk0b70, unk0b74, unk0b78, unk0b7c;
    int unk0b80, unk0b84, unk0b88, unk0b8c;
    int unk0b90, unk0b94, unk0b98, unk0b9c;
    int unk0ba0, unk0ba4, unk0ba8, unk0bac;
    int unk0bb0, unk0bb4, unk0bb8, unk0bbc;
    int unk0bc0, unk0bc4, unk0bc8, unk0bcc;
    int unk0bd0, unk0bd4, unk0bd8, unk0bdc;
    int unk0be0, unk0be4, unk0be8, unk0bec;
    int unk0bf0, unk0bf4, unk0bf8, unk0bfc;
    int unk0c00, unk0c04, unk0c08, unk0c0c;
    int unk0c10, unk0c14, unk0c18, unk0c1c;
    int unk0c20, unk0c24, unk0c28, unk0c2c;
    int unk0c30, unk0c34, unk0c38, unk0c3c;
    int unk0c40, unk0c44, unk0c48, unk0c4c;
    int unk0c50, unk0c54, unk0c58, unk0c5c;
    int unk0c60, unk0c64, unk0c68, unk0c6c;
    int unk0c70, unk0c74, unk0c78, unk0c7c;
    int unk0c80, unk0c84, unk0c88, unk0c8c;
    int unk0c90, unk0c94, unk0c98, unk0c9c;
    int unk0ca0, unk0ca4, unk0ca8, unk0cac;
    int unk0cb0, unk0cb4, unk0cb8, unk0cbc;
    int unk0cc0, unk0cc4, unk0cc8, unk0ccc;
    int unk0cd0, unk0cd4, unk0cd8, unk0cdc;
    int unk0ce0, unk0ce4, unk0ce8, unk0cec;
    int unk0cf0, unk0cf4, unk0cf8, unk0cfc;
    int unk0d00, unk0d04, unk0d08, unk0d0c;
    int unk0d10, unk0d14, unk0d18, unk0d1c;
    int unk0d20, unk0d24, unk0d28, unk0d2c;
    int unk0d30, unk0d34, unk0d38, unk0d3c;
    int unk0d40, unk0d44, unk0d48, unk0d4c;
    int unk0d50, unk0d54, unk0d58, unk0d5c;
    int unk0d60, unk0d64, unk0d68, unk0d6c;
    int unk0d70, unk0d74, unk0d78, unk0d7c;
    int unk0d80, unk0d84, unk0d88, unk0d8c;
    int unk0d90, unk0d94, unk0d98, unk0d9c;
    int unk0da0, unk0da4, unk0da8, unk0dac;
    int unk0db0, unk0db4, unk0db8, unk0dbc;
    int unk0dc0, unk0dc4, unk0dc8, unk0dcc;
    int unk0dd0, unk0dd4, unk0dd8, unk0ddc;
    int unk0de0, unk0de4, unk0de8, unk0dec;
    int unk0df0, unk0df4, unk0df8, unk0dfc;
    int unk0e00, unk0e04, unk0e08, unk0e0c;
    int unk0e10, unk0e14, unk0e18, unk0e1c;
    int unk0e20, unk0e24, unk0e28, unk0e2c;
    int unk0e30, unk0e34, unk0e38, unk0e3c;
    int unk0e40, unk0e44, unk0e48, unk0e4c;
    int unk0e50, unk0e54, unk0e58, unk0e5c;
    int unk0e60, unk0e64, unk0e68, unk0e6c;
    int unk0e70, unk0e74, unk0e78, unk0e7c;
    int unk0e80, unk0e84, unk0e88, unk0e8c;
    int unk0e90, unk0e94, unk0e98, unk0e9c;
    int unk0ea0, unk0ea4, unk0ea8, unk0eac;
    int unk0eb0, unk0eb4, unk0eb8, unk0ebc;
    int unk0ec0, unk0ec4, unk0ec8, unk0ecc;
    int unk0ed0, unk0ed4, unk0ed8, unk0edc;
    int unk0ee0, unk0ee4, unk0ee8, unk0eec;
    int unk0ef0, unk0ef4, unk0ef8, unk0efc;
    int unk0f00, unk0f04, unk0f08, unk0f0c;
    int unk0f10, unk0f14, unk0f18, unk0f1c;
    int unk0f20, unk0f24, unk0f28, unk0f2c;
    int unk0f30, unk0f34, unk0f38, unk0f3c;
    int unk0f40, unk0f44, unk0f48, unk0f4c;
    int unk0f50, unk0f54, unk0f58, unk0f5c;
    int unk0f60, unk0f64, unk0f68, unk0f6c;
    int unk0f70, unk0f74, unk0f78, unk0f7c;
    int unk0f80, unk0f84, unk0f88, unk0f8c;
    int unk0f90, unk0f94, unk0f98, unk0f9c;
    int unk0fa0, unk0fa4, unk0fa8, unk0fac;
    int unk0fb0, unk0fb4, unk0fb8, unk0fbc;
    int unk0fc0, unk0fc4, unk0fc8, unk0fcc;
    int unk0fd0, unk0fd4, unk0fd8, unk0fdc;
    int unk0fe0, unk0fe4, unk0fe8, unk0fec;
    int unk0ff0, unk0ff4, unk0ff8, unk0ffc;
    int unk1000, unk1004, unk1008, unk100c;
    int unk1010, unk1014, unk1018, unk101c;
    int unk1020, unk1024, unk1028, unk102c;
    int unk1030, unk1034, unk1038, unk103c;
    int unk1040, unk1044, unk1048, unk104c;
    int unk1050, unk1054, unk1058, unk105c;
    int unk1060, unk1064, unk1068, unk106c;
    int unk1070, unk1074, unk1078, unk107c;
    int unk1080, unk1084, unk1088, unk108c;
    int unk1090, unk1094, unk1098, unk109c;
    int unk10a0, unk10a4, unk10a8, unk10ac;
    int unk10b0, unk10b4, unk10b8, unk10bc;
    int unk10c0, unk10c4, unk10c8, unk10cc;
    int unk10d0, unk10d4, unk10d8, unk10dc;
    int unk10e0, unk10e4, unk10e8, unk10ec;
    int unk10f0, unk10f4, unk10f8, unk10fc;
    int unk1100, unk1104, unk1108, unk110c;
    int unk1110, unk1114, unk1118, unk111c;
    int unk1120, unk1124, unk1128, unk112c;
    int unk1130, unk1134, unk1138, unk113c;
    int unk1140, unk1144, unk1148, unk114c;
    int unk1150, unk1154, unk1158, unk115c;
    int unk1160, unk1164, unk1168, unk116c;
    int unk1170, unk1174, unk1178, unk117c;
    int unk1180, unk1184, unk1188, unk118c;
    int unk1190, unk1194, unk1198, unk119c;
    int unk11a0, unk11a4, unk11a8, unk11ac;
    int unk11b0, unk11b4, unk11b8, unk11bc;
    int unk11c0, unk11c4, unk11c8, unk11cc;
    int unk11d0, unk11d4, unk11d8, unk11dc;
    int unk11e0, unk11e4, unk11e8, unk11ec;
    int unk11f0, unk11f4, unk11f8, unk11fc;
    int unk1200, unk1204, unk1208, unk120c;
    int unk1210, unk1214, unk1218, unk121c;
    int unk1220, unk1224, unk1228, unk122c;
    int unk1230, unk1234, unk1238, unk123c;
    int unk1240, unk1244, unk1248, unk124c;
    int unk1250, unk1254, unk1258, unk125c;
    int unk1260, unk1264, unk1268, unk126c;
    int unk1270, unk1274, unk1278, unk127c;
    int unk1280, unk1284, unk1288, unk128c;
    int unk1290, unk1294, unk1298, unk129c;
    int unk12a0, unk12a4, unk12a8, unk12ac;
    int unk12b0, unk12b4, unk12b8, unk12bc;
    int unk12c0, unk12c4, unk12c8, unk12cc;
    int unk12d0, unk12d4, unk12d8, unk12dc;
    int unk12e0, unk12e4, unk12e8, unk12ec;
    int unk12f0, unk12f4, unk12f8, unk12fc;
    int unk1300, unk1304, unk1308, unk130c;
    int unk1310, unk1314, unk1318, unk131c;
    int unk1320, unk1324, unk1328, unk132c;
    int unk1330, unk1334, unk1338, unk133c;
    int unk1340, unk1344, unk1348, unk134c;
    int unk1350, unk1354, unk1358, unk135c;
    int unk1360, unk1364, unk1368, unk136c;
    int unk1370, unk1374, unk1378, unk137c;
    int unk1380, unk1384, unk1388, unk138c;
    int unk1390, unk1394, unk1398, unk139c;
    int unk13a0, unk13a4, unk13a8, unk13ac;
    int unk13b0, unk13b4, unk13b8, unk13bc;
    int unk13c0, unk13c4, unk13c8, unk13cc;
    int unk13d0, unk13d4, unk13d8, unk13dc;
    int unk13e0, unk13e4, unk13e8, unk13ec;
    int unk13f0, unk13f4, unk13f8, unk13fc;
    int unk1400, unk1404, unk1408, unk140c;
    int unk1410, unk1414, unk1418, unk141c;
    int unk1420, unk1424, unk1428, unk142c;
    int unk1430, unk1434, unk1438, unk143c;
    int unk1440, unk1444, unk1448, unk144c;
    int unk1450, unk1454, unk1458, unk145c;
    int unk1460, unk1464, unk1468, unk146c;
    int unk1470, unk1474, unk1478, unk147c;
    int unk1480, unk1484, unk1488, unk148c;
    int unk1490, unk1494, unk1498, unk149c;
    int unk14a0, unk14a4, unk14a8, unk14ac;
    int unk14b0, unk14b4, unk14b8, unk14bc;
    int unk14c0, unk14c4, unk14c8, unk14cc;
    int unk14d0, unk14d4, unk14d8, unk14dc;
    int unk14e0, unk14e4, unk14e8, unk14ec;
    int unk14f0, unk14f4, unk14f8, unk14fc;
    int unk1500, unk1504, unk1508, unk150c;
    int unk1510, unk1514, unk1518, unk151c;
    int unk1520, unk1524, unk1528, unk152c;
    int unk1530, unk1534, unk1538, unk153c;
    int unk1540, unk1544, unk1548, unk154c;
    int unk1550, unk1554, unk1558, unk155c;
    int unk1560, unk1564, unk1568, unk156c;
    int unk1570, unk1574, unk1578, unk157c;
    int unk1580, unk1584, unk1588, unk158c;
    int unk1590, unk1594, unk1598, unk159c;
    int unk15a0, unk15a4, unk15a8, unk15ac;
    int unk15b0, unk15b4, unk15b8, unk15bc;
    int unk15c0, unk15c4, unk15c8, unk15cc;
    int unk15d0, unk15d4, unk15d8, unk15dc;
    int unk15e0, unk15e4, unk15e8, unk15ec;
    int unk15f0, unk15f4, unk15f8, unk15fc;
    int unk1600, unk1604, unk1608, unk160c;
    int unk1610, unk1614, unk1618, unk161c;
    int unk1620, unk1624, unk1628, unk162c;
    int unk1630, unk1634, unk1638, unk163c;
    int unk1640, unk1644, unk1648, unk164c;
    int unk1650, unk1654, unk1658, unk165c;
    int unk1660, unk1664, unk1668, unk166c;
    int unk1670, unk1674, unk1678, unk167c;
    int unk1680, unk1684, unk1688, unk168c;
    int unk1690, unk1694, unk1698, unk169c;
    int unk16a0, unk16a4, unk16a8, unk16ac;
    int unk16b0, unk16b4, unk16b8, unk16bc;
    int unk16c0, unk16c4, unk16c8, unk16cc;
    int unk16d0, unk16d4, unk16d8, unk16dc;
    int unk16e0, unk16e4, unk16e8, unk16ec;
    int unk16f0, unk16f4, unk16f8, unk16fc;
    int unk1700, unk1704, unk1708, unk170c;
    int unk1710, unk1714, unk1718, unk171c;
    int unk1720, unk1724, unk1728, unk172c;
    int unk1730, unk1734, unk1738, unk173c;
    int unk1740, unk1744, unk1748, unk174c;
    int unk1750, unk1754, unk1758, unk175c;
    int unk1760, unk1764, unk1768, unk176c;
    int unk1770, unk1774, unk1778, unk177c;
    int unk1780, unk1784, unk1788, unk178c;
    int unk1790, unk1794, unk1798, unk179c;
    int unk17a0, unk17a4, unk17a8, unk17ac;
    int unk17b0, unk17b4, unk17b8, unk17bc;
    int unk17c0, unk17c4, unk17c8, unk17cc;
    int unk17d0, unk17d4, unk17d8, unk17dc;
    int unk17e0, unk17e4, unk17e8, unk17ec;
    int unk17f0, unk17f4, unk17f8, unk17fc;
    int unk1800, unk1804, unk1808, unk180c;
    int unk1810, unk1814, unk1818, unk181c;
    int unk1820, unk1824, unk1828, unk182c;
    int unk1830, unk1834, unk1838, unk183c;
    int unk1840, unk1844, unk1848, unk184c;
    int unk1850, unk1854, unk1858, unk185c;
    int unk1860, unk1864, unk1868, unk186c;
    int unk1870, unk1874, unk1878, unk187c;
    int unk1880, unk1884, unk1888, unk188c;
    int unk1890, unk1894, unk1898, unk189c;
    int unk18a0, unk18a4, unk18a8, unk18ac;
    int unk18b0, unk18b4, unk18b8, unk18bc;
    int unk18c0, unk18c4, unk18c8, unk18cc;
    int unk18d0, unk18d4, unk18d8, unk18dc;
    int unk18e0, unk18e4, unk18e8, unk18ec;
    int unk18f0, unk18f4, unk18f8, unk18fc;
    int unk1900, unk1904, unk1908, unk190c;
    int unk1910, unk1914, unk1918, unk191c;
    int unk1920, unk1924, unk1928, unk192c;
    int unk1930, unk1934, unk1938, unk193c;
    int unk1940, unk1944, unk1948, unk194c;
    int unk1950, unk1954, unk1958, unk195c;
    int unk1960, unk1964, unk1968, unk196c;
    int unk1970, unk1974, unk1978, unk197c;
    int unk1980, unk1984, unk1988, unk198c;
    int unk1990, unk1994, unk1998, unk199c;
    int unk19a0, unk19a4, unk19a8, unk19ac;
    int unk19b0, unk19b4, unk19b8, unk19bc;
    int unk19c0, unk19c4, unk19c8, unk19cc;
    int unk19d0, unk19d4, unk19d8, unk19dc;
    int unk19e0, unk19e4, unk19e8, unk19ec;
    int unk19f0, unk19f4, unk19f8, unk19fc;
    int unk1a00, unk1a04, unk1a08, unk1a0c;
    int unk1a10, unk1a14, unk1a18, unk1a1c;
    int unk1a20, unk1a24, unk1a28, unk1a2c;
    int unk1a30, unk1a34, unk1a38, unk1a3c;
    int unk1a40, unk1a44, unk1a48, unk1a4c;
    int unk1a50, unk1a54, unk1a58, unk1a5c;
    int unk1a60, unk1a64, unk1a68, unk1a6c;
    int unk1a70, unk1a74, unk1a78, unk1a7c;
    int unk1a80, unk1a84, unk1a88, unk1a8c;
    int unk1a90, unk1a94, unk1a98, unk1a9c;
    int unk1aa0, unk1aa4, unk1aa8, unk1aac;
    int unk1ab0, unk1ab4, unk1ab8, unk1abc;
    int unk1ac0, unk1ac4, unk1ac8, unk1acc;
    int unk1ad0, unk1ad4, unk1ad8, unk1adc;
    int unk1ae0, unk1ae4, unk1ae8, unk1aec;
    int unk1af0, unk1af4, unk1af8, unk1afc;
    int unk1b00, unk1b04, unk1b08, unk1b0c;
    int unk1b10, unk1b14, unk1b18, unk1b1c;
    int unk1b20, unk1b24, unk1b28, unk1b2c;
    int unk1b30, unk1b34, unk1b38, unk1b3c;
    int unk1b40, unk1b44, unk1b48, unk1b4c;
    int unk1b50, unk1b54, unk1b58, unk1b5c;
    int unk1b60, unk1b64, unk1b68, unk1b6c;
    int unk1b70, unk1b74, unk1b78, unk1b7c;
    int unk1b80, unk1b84, unk1b88, unk1b8c;
    int unk1b90, unk1b94, unk1b98, unk1b9c;
    int unk1ba0, unk1ba4, unk1ba8, unk1bac;
    int unk1bb0, unk1bb4, unk1bb8, unk1bbc;
    int unk1bc0, unk1bc4, unk1bc8, unk1bcc;
    int unk1bd0, unk1bd4, unk1bd8, unk1bdc;
    int unk1be0, unk1be4, unk1be8, unk1bec;
    int unk1bf0, unk1bf4, unk1bf8, unk1bfc;
    int unk1c00, unk1c04, unk1c08, unk1c0c;
    int unk1c10, unk1c14, unk1c18, unk1c1c;
    int unk1c20, unk1c24, unk1c28, unk1c2c;
    int unk1c30, unk1c34, unk1c38, unk1c3c;
    int unk1c40, unk1c44, unk1c48, unk1c4c;
    int unk1c50, unk1c54, unk1c58, unk1c5c;
    int unk1c60, unk1c64, unk1c68, unk1c6c;
    int unk1c70, unk1c74, unk1c78, unk1c7c;
    int unk1c80, unk1c84, unk1c88, unk1c8c;
    int unk1c90, unk1c94, unk1c98, unk1c9c;
    int unk1ca0, unk1ca4, unk1ca8, unk1cac;
    int unk1cb0, unk1cb4, unk1cb8, unk1cbc;
    int unk1cc0, unk1cc4, unk1cc8, unk1ccc;
    int unk1cd0, unk1cd4, unk1cd8, unk1cdc;
    int unk1ce0, unk1ce4, unk1ce8, unk1cec;
    int unk1cf0, unk1cf4, unk1cf8, unk1cfc;
    int unk1d00, unk1d04, unk1d08, unk1d0c;
    int unk1d10, unk1d14, unk1d18, unk1d1c;
    int unk1d20, unk1d24, unk1d28, unk1d2c;
    int unk1d30, unk1d34, unk1d38, unk1d3c;
    int unk1d40, unk1d44, unk1d48, unk1d4c;
    int unk1d50, unk1d54, unk1d58, unk1d5c;
    int unk1d60, unk1d64, unk1d68, unk1d6c;
    int unk1d70, unk1d74, unk1d78, unk1d7c;
    int unk1d80, unk1d84, unk1d88, unk1d8c;
    int unk1d90, unk1d94, unk1d98, unk1d9c;
    int unk1da0, unk1da4, unk1da8, unk1dac;
    int unk1db0, unk1db4, unk1db8, unk1dbc;
    int unk1dc0, unk1dc4, unk1dc8, unk1dcc;
    int unk1dd0, unk1dd4, unk1dd8, unk1ddc;
    int unk1de0, unk1de4, unk1de8, unk1dec;
    int unk1df0, unk1df4, unk1df8, unk1dfc;
    int unk1e00, unk1e04, unk1e08, unk1e0c;
    int unk1e10, unk1e14, unk1e18, unk1e1c;
    int unk1e20, unk1e24, unk1e28, unk1e2c;
    int unk1e30, unk1e34, unk1e38, unk1e3c;
    int unk1e40, unk1e44, unk1e48, unk1e4c;
    int unk1e50, unk1e54, unk1e58, unk1e5c;
    int unk1e60, unk1e64, unk1e68, unk1e6c;
    int unk1e70, unk1e74, unk1e78, unk1e7c;
    int unk1e80, unk1e84, unk1e88, unk1e8c;
    int unk1e90, unk1e94, unk1e98, unk1e9c;
    int unk1ea0, unk1ea4, unk1ea8, unk1eac;
    int unk1eb0, unk1eb4, unk1eb8, unk1ebc;
    int unk1ec0, unk1ec4, unk1ec8, unk1ecc;
    int unk1ed0, unk1ed4, unk1ed8, unk1edc;
    int unk1ee0, unk1ee4, unk1ee8, unk1eec;
    int unk1ef0, unk1ef4, unk1ef8, unk1efc;
    int unk1f00, unk1f04, unk1f08, unk1f0c;
    int unk1f10, unk1f14, unk1f18, unk1f1c;
    int unk1f20, unk1f24, unk1f28, unk1f2c;
    int unk1f30, unk1f34, unk1f38, unk1f3c;
    int unk1f40, unk1f44, unk1f48, unk1f4c;
    int unk1f50, unk1f54, unk1f58, unk1f5c;
    int unk1f60, unk1f64, unk1f68, unk1f6c;
    int unk1f70, unk1f74, unk1f78, unk1f7c;
    int unk1f80, unk1f84, unk1f88, unk1f8c;
    int unk1f90, unk1f94, unk1f98, unk1f9c;
    int unk1fa0, unk1fa4, unk1fa8, unk1fac;
    int unk1fb0, unk1fb4, unk1fb8, unk1fbc;
    int unk1fc0, unk1fc4, unk1fc8, unk1fcc;
    int unk1fd0, unk1fd4, unk1fd8, unk1fdc;
    int unk1fe0, unk1fe4, unk1fe8, unk1fec;
    int unk1ff0, unk1ff4, unk1ff8, unk1ffc;
    int unk2000, unk2004, unk2008, unk200c;
    int unk2010, unk2014, unk2018, unk201c;
    int unk2020, unk2024, unk2028, unk202c;
    int unk2030, unk2034, unk2038, unk203c;
    int unk2040, unk2044, unk2048, unk204c;
    int unk2050, unk2054, unk2058;
    BuildContext context;
    void FUN_006a7c40();
    int FUN_009950a0(BuildInput**);
    void FUN_006b8ec0(int, BuildInput**, float);
    void SetThreadTasklet(BuildFirst*, BuildSecond*, int);
    BuildResult* BuildResultForInput(int, int, BuildInput*, bool);
};
void* __cdecl operator new(unsigned int);
// Validates input, builds entries and objects, creates a BuildResult when objects exist, and optionally a BuildMonitor, then returns the result.
// @fnv 0x00994f10
BuildResult* BuildOwner::BuildResultForInput(int first, int second, BuildInput* input, bool monitor)
{
    if (!input->valid)
        return 0;
    FUN_006a7c40();
    FUN_006b8ec0(FUN_009950a0(&input), &input, 0.0f);
    BuildFirst entries;
    BuildSecond objects4;
    SetThreadTasklet(&entries, &objects4, 0);
    BuildResult* result3 = 0;
    if (objects4.FUN_0044ddc0() > 0)
    {
        result3 = new BuildResult(first, second, &entries, &objects4, &context);
    }
    BuildMonitor* tracking3 = 0;
    if (monitor)
        tracking3 = new BuildMonitor(this, result3, &entries);
    FUN_006a7c40();
    return result3;
}

struct TreeEntry
{
    int parent, after, mask, item, state, stateMask;
    const char* text;
    int textMax, image, selectedImage, children;
    void* parameter;
    int integral;
    int stateEx;
    void* window;
    int expandedImage;
};
const char* __cdecl PrepareScriptMessage(const char*, bool);
extern int(__stdcall* DAT_00fdf28c)(int, int, int, TreeEntry*);
extern void(__stdcall* DAT_00fdf288)(int, int);
extern void(__stdcall* DAT_00fdf284)(int);
struct Node995
{
    Node995* Parent();
};
struct State995
{
    void Describe(char*, int, unsigned);
};
struct Owner995
{
    Node995* Root();
    State995* State();
};
struct Action995
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Describe(char*, int, int);
};
struct Plan995
{
    unsigned Count();
    Action995* Item(unsigned);
    int Detail(unsigned);
};
struct View995
{
    int unk00, unk04, window, tree, selection, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    Owner995* owner;
    Plan995* plan;
    void Select(int, Node995*);
    void PopulateTree();
};
// @fnv 0x00995aa0
void View995::PopulateTree()
{
    TreeEntry entry7;
    entry7.after = -65534;
    entry7.mask = 39;
    Node995* selected3 = 0;
    Node995* node2 = owner->Root();
    while (node2)
    {
        if (!node2->Parent())
        {
            selected3 = node2;
            break;
        }
        else
            node2 = node2->Parent();
    }
    State995* state6 = owner->State();
    entry7.parent = -65536;
    entry7.text = PrepareScriptMessage("Initial World State", false);
    entry7.selectedImage = entry7.image = 0;
    entry7.parameter = 0;
    int stateRoot = DAT_00fdf28c(tree, 0x1100, 0, &entry7);
    unsigned index;
    unsigned detail5;
    for (detail5 = 0; detail5 < 20; ++detail5)
    {
        index = detail5;
        entry7.parent = stateRoot;
        char text[2600];
        state6->Describe(text, 2600, index);
        entry7.text = PrepareScriptMessage(text, false);
        DAT_00fdf28c(tree, 0x1100, 0, &entry7);
    }
    if (plan)
    {
        entry7.parent = -65536;
        entry7.text = PrepareScriptMessage("Combat Plan", false);
        entry7.selectedImage = entry7.image = 0;
        entry7.parameter = 0;
        int planRoot4 = DAT_00fdf28c(tree, 0x1100, 0, &entry7);
        for (unsigned planIndex_ = 0; planIndex_ < plan->Count(); ++planIndex_)
        {
            Action995* action = plan->Item(planIndex_);
            int actionDetail;
            if (action)
            {
                actionDetail = plan->Detail(planIndex_);
                entry7.parent = planRoot4;
                char text[260];
                action->Describe(text, 260, actionDetail);
                entry7.text = PrepareScriptMessage(text, false);
                DAT_00fdf28c(tree, 0x1100, 0, &entry7);
            }
        }
    }
    if (selected3)
    {
        entry7.parent = -65536;
        entry7.text = PrepareScriptMessage("Planner", false);
        entry7.selectedImage = entry7.image = 0;
        entry7.parameter = selected3;
        selection = DAT_00fdf28c(tree, 0x1100, 0, &entry7);
        Select(selection, selected3);
        DAT_00fdf288(window, 10);
        DAT_00fdf284(window);
    }
}

class C9964C0MemoryManager
{
  public:
    static C9964C0MemoryManager* GetSingleton();
    unsigned int GetThreadID();
};

class C9964C0Base
{
  public:
    C9964C0Base();
    virtual ~C9964C0Base();

    void Init(unsigned int uiArg1, unsigned int uiArg2);

    int unk04;
    int unk08;
    int unk0C;
    unsigned int m_uiThreadID;
};

class FUN_009964c0 : public C9964C0Base
{
  public:
    FUN_009964c0();
    virtual ~FUN_009964c0();
};

// Stores the memory manager's thread ID in m_uiThreadID, then calls Init(0, 0).
// @fnv 0x009964c0
FUN_009964c0::FUN_009964c0()
{
    m_uiThreadID = C9964C0MemoryManager::GetSingleton()->GetThreadID();
    Init(0, 0);
}

class B996C00Allocator;

class B996C00MemoryManager
{
  public:
    B996C00Allocator* GetDefaultAllocator();
};

B996C00MemoryManager* B996C00GetMemoryManager();

class B996C00Base
{
  public:
    B996C00Base();
    virtual ~B996C00Base();

    void Init(int iSize, int iGrowBy);

    int unk04;
    int unk08;
    int unk0C;
    B996C00Allocator* m_pHeapAllocator;
};

class FUN_00996c00_cls : public B996C00Base
{
  public:
    FUN_00996c00_cls();
    virtual ~FUN_00996c00_cls();
};

// Initializes the base by storing the memory manager's default allocator and calling Init with zero size and growth.
// @fnv 0x00996c00
FUN_00996c00_cls::FUN_00996c00_cls()
{
    m_pHeapAllocator = B996C00GetMemoryManager()->GetDefaultAllocator();
    Init(0, 0);
}

namespace CombatPosition {

struct Actor;
struct Context;
struct State;
struct Path;
struct Location;
struct List;
struct Node;
struct Search;
struct History;

struct Vec
{
    float x, y, z;
    Vec FUN_00439ef0(const Vec&);
    Vec FUN_00439e90(const Vec&);
    Vec ApplyScaled(float);
    float FUN_004a7290();
    float FUN_00457910();
    float FUN_00457990();
    Vec* FUN_006a6eb0();
};

struct Params
{
    unsigned short flagsLow, flagsHigh;
    unsigned char modeLow, modeHigh;
    Params();
};
struct Time
{
    unsigned int value;
    Time(float);
    Time(const Time&);
};
float FUN_00435dd0();

struct Location
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    Location(const Vec&, Actor*);
    ~Location();
    bool FUN_006ded70(float);
};

struct PathPoint
{
    Vec FUN_006a6eb0();
};
struct List
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    List();
    ~List();
    unsigned int FUN_0044ddc0();
    PathPoint* FUN_006dad90(unsigned int);
};

struct Nodes
{
    unsigned int unk0, unk4, unk8;
    void FUN_006dbde0(int);
    unsigned int FUN_0044ddc0();
    Node* FUN_009052c0(unsigned int);
};

struct State
{
    Vec target, origin;
    float radius;
    Time time;
    Nodes nodes;
};

struct Node
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
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
    unsigned short unk50;
    unsigned char status;
    unsigned char unk53;
    unsigned int FUN_006e4570();
    Vec FUN_005c3420();
};

struct Stored
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
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
    void FUN_006e4430(Node*);
    unsigned int FUN_006e4740();
    bool FUN_0099c1f0();
    bool FUN_006e4840(const Vec&);
};

struct Context
{
    unsigned short unk0;
    unsigned char flag, unk3;
    int mode;
    Vec target;
    Stored stored;
    unsigned int id, token;
    Params params;
    void FUN_005407b0(int);
};

struct Search
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
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
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    Search();
    ~Search();
    void AssignPathingLocation(const Location&);
    void FUN_0099e010(const Vec&);
    void FUN_006dad40(const Vec&);
    void FUN_006e4340(float);
    void FUN_006e4320(float);
    void SetSound(int);
    void FUN_0051b840(float);
    void FUN_005076c0(float);
    void FUN_008eeaa0(bool);
    void SetFlag(bool);
    void SetByteAtOffsetCD(bool);
};

struct History
{
    unsigned int FUN_0044ddc0();
    int FUN_00719b20(unsigned int*, int, void*);
};

struct Actor
{
    Actor* GetOffsetC();
    Actor* FUN_006a9540();
    Path* GetString();
    Context* FUN_0068efb0();
    State* FUN_004f8960();
    Vec FUN_005c3420();
    int FUN_007058c0();
    bool GetByteAtE0();
    Vec* FUN_00923000();
    float GetFieldB8Float();
    float FUN_0099e040();
    History* FUN_006e4f90();
    History* GetOffsetF4();
    float GetFloatAtOffset68();
    float GetFloatAtOffsetB0();
    float GetFieldB4Float();
    float FUN_006d6d90();
    void FUN_006d30b0(const Vec&);
};

struct Evaluator
{
    void LockCombatTargetMap();
    bool TryUseCoverItem(unsigned int, Node*, int, float, Params*, int, int);
    void FUN_00995890();
};
struct Danger
{
    float EvaluateThreats(Vec, int, float, float, Time, float);
};
struct Manager
{
    Evaluator* FUN_009611e0();
    Danger* FUN_00825c00();
};
extern Manager* DAT_011f1958;

extern float DAT_010236e0, DAT_01018bfc, DAT_01017718;
extern double DAT_01011590, DAT_0106b9e8, DAT_01012060, DAT_0106cd60;

bool FUN_006d5490(const void*, const void*, Path*, float*, List*);
int FindNearbyTriangles(Search*, Nodes*);
void FUN_009a3830();
void FUN_009a93e0(float, Node*, Params*, Vec*, int);
bool FUN_0099cb00(Location*, History*);
bool FUN_0099cc60(Location*, const Vec&, int);

// @fnv 0x0099d480
bool FindCombatPosition(Actor* owner, float range, bool quiet)
{

    float extentSlot0 = DAT_010236e0;
    float widthSlot19 = DAT_01018bfc;
    int limitSlot0 = 200;
    Actor* actorSlot12 = owner->GetOffsetC();
    Actor* target = owner->FUN_006a9540();
    Path* pathSlot25 = owner->GetString();
    Context* context = owner->FUN_0068efb0();
    State* stateSlot21 = owner->FUN_004f8960();
    Vec deltaSlot18 = target->FUN_005c3420().FUN_00439ef0(actorSlot12->FUN_005c3420());
    float squareSlot52 = deltaSlot18.FUN_004a7290();
    if (squareSlot52 < range * range)
        return false;

    float distance = 0;
    bool initialSlot2 = FUN_006d5490(actorSlot12, target, pathSlot25, &distance, 0);
    float scaleSlot13 = 1;
    if (owner->FUN_007058c0() == 6)
        scaleSlot13 = DAT_01017718;
    float minimumSlot14 = distance - range / 2.0f;
    float maximumSlot21 = distance + range * scaleSlot13;
    if (distance < widthSlot19)
        widthSlot19 = distance;
    float lengthSlot10 = deltaSlot18.FUN_00457910();
    float halfSlot31 = lengthSlot10 / DAT_01011590;
    if (halfSlot31 < widthSlot19)
        widthSlot19 = halfSlot31;

    Vec originSlot32 = actorSlot12->FUN_005c3420().FUN_00439e90(deltaSlot18.ApplyScaled(widthSlot19 * DAT_0106b9e8));
    Location locationSlot24(originSlot32, actorSlot12);
    Vec targetPositionSlot21 = target->FUN_005c3420();
    bool overridePositionSlot12 = false;
    if (owner->GetByteAtE0())
    {
        targetPositionSlot21 = *owner->FUN_00923000();
        overridePositionSlot12 = true;
    }

    Search searchSlot20;
    searchSlot20.AssignPathingLocation(locationSlot24);
    searchSlot20.FUN_0099e010(actorSlot12->FUN_005c3420());
    searchSlot20.FUN_006dad40(targetPositionSlot21);
    searchSlot20.FUN_006e4340(extentSlot0);
    searchSlot20.FUN_006e4320(widthSlot19);
    searchSlot20.SetSound(200);
    searchSlot20.FUN_0051b840(owner->GetFieldB8Float());
    searchSlot20.FUN_005076c0(owner->FUN_0099e040());
    searchSlot20.FUN_008eeaa0(owner->FUN_0099e040() != DAT_01012060);
    searchSlot20.SetFlag(true);
    if (overridePositionSlot12)
        searchSlot20.SetByteAtOffsetCD(true);

    context->mode = owner->FUN_007058c0();
    context->target = targetPositionSlot21;
    stateSlot21->time = FUN_00435dd0();
    stateSlot21->origin = originSlot32;
    stateSlot21->radius = widthSlot19;
    stateSlot21->target = context->target;
    stateSlot21->nodes.FUN_006dbde0(0);

    if (FindNearbyTriangles(&searchSlot20, &stateSlot21->nodes))
    {
        if (!quiet)
            DAT_011f1958->FUN_009611e0()->LockCombatTargetMap();
        for (unsigned int i = 0; i < stateSlot21->nodes.FUN_0044ddc0(); i++)
        {

            Node* node = stateSlot21->nodes.FUN_009052c0(i);
            unsigned int idSlot31 = node->FUN_006e4570();
            if (owner->FUN_006e4f90()->FUN_00719b20(&idSlot31, 0, (void*)FUN_009a3830) != -1)
            {
                node->status = 3;
                continue;
            }

            Params params;
            if (!DAT_011f1958->FUN_009611e0()->TryUseCoverItem(idSlot31, node, 0, owner->GetFloatAtOffset68(), &params,
                                                               1, 0))
            {
                node->status = 9;
                continue;
            }

            Vec positionSlot42 = node->FUN_005c3420();
            FUN_009a93e0(owner->GetFloatAtOffset68(), node, &params, &positionSlot42, 0);
            Location candidateSlot0(positionSlot42, (Actor*)node);
            if (!candidateSlot0.FUN_006ded70(owner->GetFloatAtOffsetB0()))
            {
                node->status = 4;
                continue;
            }

            Vec differenceSlot52 = positionSlot42.FUN_00439ef0(target->FUN_005c3420());
            if (differenceSlot52.FUN_004a7290() > minimumSlot14 * minimumSlot14)
            {
                node->status = 7;
                continue;
            }

            Vec fromActorSlot3 = actorSlot12->FUN_005c3420().FUN_00439ef0(positionSlot42);
            if (fromActorSlot3.FUN_004a7290() < range * range)
            {
                node->status = 8;
                continue;
            }

            if (overridePositionSlot12)
            {
                Vec fromOverride = positionSlot42.FUN_00439ef0(context->target);
                if (fromOverride.FUN_004a7290() < DAT_0106cd60)
                {
                    node->status = 10;
                    continue;
                }
            }

            float travelSlot13 = fromActorSlot3.FUN_00457990() / owner->GetFieldB4Float();
            if (DAT_011f1958->FUN_00825c00()->EvaluateThreats(positionSlot42, 0, travelSlot13, 0.0f, Time(0.0f),
                                                              owner->FUN_006d6d90()) > DAT_01012060)
            {
                node->status = 11;
                continue;
            }

            bool blockedSlot62 = false;
            if (owner->GetOffsetF4()->FUN_0044ddc0())
                blockedSlot62 = FUN_0099cb00(&candidateSlot0, owner->GetOffsetF4());
            else
                blockedSlot62 = FUN_0099cc60(&candidateSlot0, target->FUN_005c3420(), 0);
            if (blockedSlot62)
            {
                node->status = 13;
                continue;
            }

            float targetDistanceSlot0 = 0;
            List routeSlot16;
            bool success = FUN_006d5490(&candidateSlot0, target, pathSlot25, &targetDistanceSlot0, &routeSlot16);
            if ((initialSlot2 && !success) || targetDistanceSlot0 > minimumSlot14)
            {
                node->status = 17;
                continue;
            }

            float actorDistanceSlot1 = 0;
            success = FUN_006d5490(actorSlot12, &candidateSlot0, pathSlot25, &actorDistanceSlot1, 0);
            if ((initialSlot2 && !success) || maximumSlot21 < targetDistanceSlot0 + actorDistanceSlot1)
            {
                node->status = 18;
                continue;
            }

            node->status = 19;
            context->stored.FUN_006e4430(node);
            context->id = idSlot31;
            context->token = context->stored.FUN_006e4740();
            context->params = params;
            context->flag = context->stored.FUN_0099c1f0();
            context->FUN_005407b0(0);

            if (!overridePositionSlot12)
            {
                if (routeSlot16.FUN_0044ddc0() > 1)
                {
                    Vec point = routeSlot16.FUN_006dad90(1)->FUN_006a6eb0();
                    if (context->stored.FUN_006e4840(point))
                        context->params.modeHigh = 1;
                }
            }

            else
            {
                Vec point = targetPositionSlot21;
                List secondRouteSlot2;
                Location endpointSlot0(targetPositionSlot21, actorSlot12);
                if (FUN_006d5490(&candidateSlot0, &endpointSlot0, pathSlot25, 0, &secondRouteSlot2) &&
                    secondRouteSlot2.FUN_0044ddc0() > 1)
                {
                    point = secondRouteSlot2.FUN_006dad90(1)->FUN_006a6eb0();
                }
                if (context->stored.FUN_006e4840(point))
                    context->params.modeHigh = 1;
            }

            owner->FUN_006d30b0(positionSlot42);
            return true;
        }
        if (!quiet)
            DAT_011f1958->FUN_009611e0()->FUN_00995890();
    }

    return false;
}

}

struct Pos99
{
    float x, y, z;
    float FUN_00527a40(const Pos99&);
    Pos99 operator-(const Pos99&) const;
    float FUN_004a7290() const;
};
struct Loc99
{
    float x, y, z, w;
    float FUN_00527a40(const Loc99&);
};
struct Set99
{
    float* FUN_00403e20();
    unsigned char* FUN_00408d60();
};
extern Set99 originalRuntimeFloatSetting434, originalRuntimeFloatSetting433, originalRuntimeFloatSetting430,
    originalRuntimeFloatSetting445, originalRuntimeFloatSetting444, originalRuntimeFloatSetting435,
    originalRuntimeFloatSetting446;
extern Set99 g_011f1840;
struct BaseData99
{
    virtual bool v0();
    virtual bool v1();
    virtual bool v2();
    virtual bool v3();
    virtual bool v4();
    virtual bool v5();
    virtual bool v6();
    virtual bool v7();
    virtual bool v8();
    virtual bool v9();
    virtual bool v10();
    bool FUN_0055e200();
};
struct Base99
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
    BaseData99 data;
};
struct Link99;
struct Ref99
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
    virtual bool IsActor();
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
    virtual Pos99* Position();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual bool Special();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual bool Dead(int);
    bool FUN_00437b90();
    Loc99 FUN_00575650();
    bool FUN_008a6650(int);
    bool IsHostileTo(Ref99*, int, int*, int);
    float FUN_008be1b0();
    Base99* FUN_004181e0();
    unsigned int FUN_0084e3a0();
    Link99* FUN_00568e50();
    void* FUN_00567d20();
    void* Cell();
};
struct Link99
{
    Ref99* FUN_00559450();
    Loc99 FUN_0043a390();
    void* FUN_0043a320();
    void* FUN_0043a2b0();
    void* FUN_00717e50();
};
struct Map99
{
    void* FUN_004b9ba0();
    void FUN_006b7f20(void*&, unsigned int&, Ref99*&);
};
struct Collection99
{
    Map99* FUN_00461110();
};
extern Collection99* DAT_011c95c8;
struct World99
{
    bool FUN_00992530(Ref99*, Ref99*);
};
struct Array99
{
    int a, b, c, d;
    Array99();
    ~Array99();
    unsigned int FUN_0044ddc0();
    Ref99*& FUN_006a7ad0(unsigned int);
};
void* FUN_00546a90();
bool FUN_004dff00(float);
float FUN_00435dd0();
struct Stamp99
{
    int value;
    Stamp99(float);
    float FUN_00435e00();
};
struct Context99
{
    Ref99* GetFieldBC();
    Ref99* FUN_004030b0();
    void* FUN_004fb070();
};
struct Out99
{
    void FUN_00997400(Ref99*);
    void FUN_00819a50(float);
    void FUN_0099b8b0(void*, void*);
    void AssignV4(Pos99*);
    void SetFlags(unsigned int, bool);
};
int FUN_006d9350(void*, Pos99*, float, Array99*);
struct Actor99 : Ref99
{
    void* FUN_00575ca0();
};
struct Cast99
{
    int FindRefInRadius(Loc99*, float, int);
};
struct Fallback99
{
    unsigned char type;
    Ref99* ref;
    Pos99 point;
};
struct Self99
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
    Fallback99* fallback;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    bool active;
    unsigned int excluded;
    Stamp99 stamp;
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
    Context99* context;
    bool FUN_009a02a0(Loc99*, int, int);
    bool FUN_0099b8e0(int, int*, void*, Out99*, int);
    bool FUN_0099ebe0(void*, Out99*, int);
};
// @fnv 0x0099ebe0
bool Self99::FUN_0099ebe0(void* arg, Out99* output, int mode)
{
    Ref99* actor15 = context->GetFieldBC();
    Ref99* target0 = context->FUN_004030b0();
    Loc99 origin13 = actor15->FUN_00575650();
    if (target0)
    {
        Loc99 targetPos51 = target0->FUN_00575650();
        Ref99* best20 = 0;
        float bestDist18 =
            *originalRuntimeFloatSetting434.FUN_00403e20() * *originalRuntimeFloatSetting434.FUN_00403e20();
        Map99* map30 = DAT_011c95c8->FUN_00461110();
        void* iter11 = map30->FUN_004b9ba0();
        while (iter11)
        {
            unsigned int key25 = 0;
            Ref99* entry47 = 0;
            map30->FUN_006b7f20(iter11, key25, entry47);
            if (entry47->FUN_00437b90() || !entry47->IsActor() || entry47->Dead(0) || entry47 == actor15 ||
                entry47 == target0)
                continue;
            Ref99* candidate2 = entry47;
            Loc99 pos1 = candidate2->FUN_00575650();
            float distance11 = origin13.FUN_00527a40(pos1);
            if (distance11 <
                *originalRuntimeFloatSetting433.FUN_00403e20() * *originalRuntimeFloatSetting433.FUN_00403e20())
                continue;
            if (distance11 > bestDist18)
                continue;
            float targetDistance11 = targetPos51.FUN_00527a40(pos1);
            float originDistance22 = targetPos51.FUN_00527a40(origin13);
            if (originDistance22 > targetDistance11)
                continue;
            if (!FUN_009a02a0(&pos1, 1, 0))
                continue;
            if (candidate2->FUN_008a6650(0))
                continue;
            int relation1;
            if (!candidate2->IsHostileTo(target0, 0, &relation1, 0) &&
                !((World99*)BGSSaveLoadGlobalDataWorldspacePtr)->FUN_00992530(candidate2, actor15))
                continue;
            if (candidate2->IsHostileTo(actor15, 0, &relation1, 0))
                continue;
            best20 = candidate2;
            bestDist18 = distance11;
        }
        if (best20)
        {
            output->FUN_00997400(best20);
            output->FUN_00819a50(best20->FUN_008be1b0() + actor15->FUN_008be1b0() +
                                 *originalRuntimeFloatSetting430.FUN_00403e20());
            return true;
        }
    }
    Base99* base5 = actor15->FUN_004181e0();
    if (base5->data.FUN_0055e200() && (!actor15->Special() || !base5->data.v10()) && mode != 10)
    {
        if (!active && FUN_004dff00(*originalRuntimeFloatSetting445.FUN_00403e20()))
        {
            stamp = FUN_00435dd0();
        }
        if (stamp.FUN_00435e00() > *originalRuntimeFloatSetting444.FUN_00403e20())
        {
            Ref99* bestObject22 = 0;
            Pos99 actorPos3 = *actor15->Position();
            float range1 = *originalRuntimeFloatSetting435.FUN_00403e20();
            float bestDistance3 = range1 * range1;
            Array99 objects0;
            if (FUN_006d9350(((Actor99*)actor15)->FUN_00575ca0(), &actorPos3, range1, &objects0))
            {
                for (unsigned int index = 0; index < objects0.FUN_0044ddc0(); index++)
                {
                    Ref99* object21 = objects0.FUN_006a7ad0(index);
                    if (object21->FUN_00437b90())
                        continue;
                    if (object21->FUN_0084e3a0() == excluded)
                        continue;
                    Link99* link36 = object21->FUN_00568e50();
                    Ref99* linked0 = link36->FUN_00559450();
                    if (linked0->FUN_0084e3a0() == excluded || linked0->FUN_00437b90())
                        continue;
                    if (*g_011f1840.FUN_00408d60())
                    {
                        void* world0 = linked0->FUN_00567d20();
                        void* actorWorld5 = actor15->FUN_00567d20();
                        if (!world0)
                            world0 = FUN_00546a90();
                        if (!actorWorld5)
                            actorWorld5 = FUN_00546a90();
                        if (world0 != actorWorld5)
                            continue;
                    }
                    Loc99 objectLocation6 = object21->FUN_00575650();
                    if (!FUN_009a02a0(&objectLocation6, 1, 0))
                        continue;
                    if (!FUN_009a02a0(&link36->FUN_0043a390(), 1, 1))
                        continue;
                    if (((Cast99*)context->FUN_004fb070())
                            ->FindRefInRadius(&objectLocation6, *originalRuntimeFloatSetting446.FUN_00403e20(), 0))
                        continue;
                    Pos99 objectPos45 = *object21->Position();
                    Pos99 delta1 = objectPos45 - actorPos3;
                    float objectDistance3 = delta1.FUN_004a7290();
                    if (objectDistance3 < bestDistance3)
                    {
                        bestDistance3 = objectDistance3;
                        bestObject22 = object21;
                    }
                }
            }
            if (bestObject22)
            {
                Link99* bestLink6 = bestObject22->FUN_00568e50();
                void* handle2 = bestLink6->FUN_0043a320();
                if (!handle2)
                    handle2 = bestLink6->FUN_0043a2b0();
                output->FUN_0099b8b0(bestLink6->FUN_00717e50(), handle2);
                return true;
            }
        }
    }
    if (arg && FUN_0099b8e0(0, &unk0ec, arg, output, mode))
        return true;
    if (fallback && fallback->type == 1)
    {
        if (fallback->ref)
        {
            output->FUN_00997400(fallback->ref);
            if (fallback->ref->IsActor())
            {
                Ref99* other = fallback->ref;
                output->FUN_00819a50(other->FUN_008be1b0() + actor15->FUN_008be1b0() +
                                     *originalRuntimeFloatSetting430.FUN_00403e20());
            }
        }
        else
            output->AssignV4(&fallback->point);
        return true;
    }
    output->SetFlags(1, 1);
    return true;
}

struct Slot_009827c0_Arg
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
    unsigned short unk4c;
    unsigned char unk4e;
    unsigned char unk4f;
    unsigned char FUN_00982be0();
};
struct Slot_009827c0_Src
{
    char GetByte15();
    bool FUN_00843150();
    int FUN_0044edb0();
};
unsigned char MinByte(unsigned char a, unsigned char b);
extern double DAT_01016ff0;
struct Slot_009827c0_This
{
    unsigned char m_00;
    unsigned char m_01;
    unsigned char m_02;
    unsigned char m_03;
    unsigned char m_04;
    unsigned char m_05;
    void FUN_00982630(Slot_009827c0_Arg* a);
    unsigned char FUN_00982750(float a);
    int ComputeBitMask();
    void FUN_00982b50();
    bool FUN_009827c0(Slot_009827c0_Arg* arg, int unused, float time, Slot_009827c0_Src* src, unsigned char a5,
                      unsigned char a6);
};

// @fnv 0x009827c0
bool Slot_009827c0_This::FUN_009827c0(Slot_009827c0_Arg* arg, int unused, float time, Slot_009827c0_Src* src,
                                      unsigned char a5, unsigned char a6)
{
    int used2 = 0;
    if (src)
    {
        m_01 = src->GetByte15();
        m_00 = src->FUN_00843150();
        used2 = src->FUN_0044edb0();
    }
    else
    {
        FUN_00982630(arg);
    }
    if (!m_00 || !m_01)
        return false;
    if (!m_02)
        m_02 = FUN_00982750(time);
    unsigned char kNeed = (unsigned char)(m_02 / DAT_01016ff0);
    if (kNeed > m_01)
        return false;
    m_02 = MinByte(m_02, m_01);
    if (m_03)
    {
        m_04 = a5;
        if ((ComputeBitMask() & used2) == 0 && m_05 == a6)
            return true;
    }
    m_04 = a5;
    m_05 = a6;
    m_03 = 0;
    int mask5 = ComputeBitMask();
    if (arg->FUN_00982be0() && !m_04)
    {
        unsigned char shift2 = 0;
        if (m_05)
            shift2 = 0;
        else
            shift2 = m_01 - m_02;
        int bits = mask5 << shift2;
        if ((used2 & bits) == 0)
        {
            m_03 = shift2;
            return true;
        }
    }
    else
    {
        bool centered6 = true;
        if (m_01 / m_02 == 2)
            centered6 = false;
        if (centered6)
        {
            int step7 = 0;
            int mid4 = m_01 / 2 - m_02 / 2;
            int limitVal = m_01 - m_02;
            bool _done = false;
            while (!_done)
            {
                for (int side5 = 0; side5 < (step7 > 0) + 1; side5 += 1)
                {
                    int pos = side5 == 0 ? mid4 - step7 : mid4 + step7;
                    if (pos >= 0 && pos <= limitVal)
                    {
                        int bits = mask5 << pos;
                        if ((used2 & bits) == 0)
                        {
                            m_03 = (unsigned char)pos;
                            return true;
                        }
                    }
                    else
                    {
                        _done = true;
                    }
                }
                step7 += 1;
            }
        }
        else if (arg->unk4f)
        {
            for (int i = m_01 - m_02; i >= 0; i -= 1)
            {
                int bits = mask5 << i;
                if ((used2 & bits) == 0)
                {
                    m_03 = (unsigned char)i;
                    return true;
                }
            }
        }
        else
        {
            for (int i = 0; i <= m_01 - m_02; i += 1)
            {
                int bits = mask5 << i;
                if ((used2 & bits) == 0)
                {
                    m_03 = (unsigned char)i;
                    return true;
                }
            }
        }
    }
    FUN_00982b50();
    return false;
}

struct ObjQ;
struct SubQ
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
    virtual void Act(ObjQ* p);
};
struct ObjQ
{
    SubQ* FUN_009611e0();
};
struct MgrQ
{
    void FUN_0087ac60();
};
MgrQ* __stdcall FUN_004537b0(ObjQ* p);
bool FUN_008c7aa0();
struct FUN_0045cec0
{
    ObjQ* p;
    ~FUN_0045cec0();
    ObjQ* FUN_00559450();
};
struct FUN_00983700
{
    int pad[6];
    ~FUN_00983700();
};
struct FUN_00982d10 : FUN_00983700
{
    FUN_0045cec0 pSceneObject;
    ~FUN_00982d10();
};
// @fnv 0x00982d10
FUN_00982d10::~FUN_00982d10()
{
    if (pSceneObject.FUN_00559450() && pSceneObject.FUN_00559450()->FUN_009611e0())
    {
        if (!FUN_008c7aa0())
            pSceneObject.FUN_00559450()->FUN_009611e0()->Act(pSceneObject.FUN_00559450());
        else
            FUN_004537b0(pSceneObject.FUN_00559450())->FUN_0087ac60();
    }
}

struct PointerMapBase983820
{
    virtual void Slot00();
    ~PointerMapBase983820();
};

struct FUN_00983820 : PointerMapBase983820
{
    void FUN_00438af0();
    ~FUN_00983820();
};

// Destructor that calls FUN_00438af0.
// @fnv 0x00983820
FUN_00983820::~FUN_00983820()
{
    FUN_00438af0();
}

struct TESSound
{
    unsigned int Deallocate();
};

struct FUN_004d61b0
{
    unsigned char m_auiShapeKeys[0x30];

    FUN_004d61b0(unsigned int, unsigned int, unsigned int, const char*, unsigned int, unsigned int, unsigned int,
                 unsigned int);
    ~FUN_004d61b0();
};

struct FUN_009959f0_class : public FUN_004d61b0
{
    int m_30;
    int m_34;
    int m_38;

    FUN_009959f0_class(int, int, int);
    void PopulateTree();
};

extern BSAudio* g_osGlobals;
extern unsigned int _data_011c16bc;

// Constructs the base object with title "Combat Plan" and size 0x320 by 0x258, stores arg1, arg2, arg3 in m_30, m_34, m_38, then calls PopulateTree.
// @fnv 0x009959f0
FUN_009959f0_class::FUN_009959f0_class(int arg1, int arg2, int arg3)
    : FUN_004d61b0(reinterpret_cast<TESSound*>(g_osGlobals)->Deallocate(),
                   reinterpret_cast<ArrSI*>(g_osGlobals)->GetFlags(), 0, "Combat Plan", 0x80000000, 0x80000000, 0x320,
                   0x258),
      m_30(arg1), m_34(arg2), m_38(arg3)
{
    PopulateTree();
}

struct DebugLabel
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void Format(char*, unsigned int, int);
};
struct DebugName
{
    DebugLabel* label;
    int unk04;
    int detail;
};
struct DebugNode
{
    DebugNode* FUN_0044edb0();
    float FUN_006a7f50();
    DebugName** GetOffsetC();
    CombatStateHash** GetName();
};
struct DebugMembership
{
    bool FUN_009962f0(CombatStateHash**);
};
struct DebugTree
{
    int unk00, unk04, unk08;
    int tree;
    int unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
    DebugMembership* membership;
    int FUN_00995e30(DebugNode*);
    void FindAndDispatchById(DebugNode*, FUN_00995e30_arr_cls*);
    void FUN_00995ef0(int parent, DebugNode* node);
};
int __cdecl FUN_00406d00(char*, int, const char*, ...);
const char* __cdecl PrepareScriptMessage(const char*, bool);
struct DebugEntryLabel
{
    void FUN_009aa150(char*, unsigned int, int);
};
// Recursively inserts a debug tree node and its children into the tree, formatting labels with cost and membership details.
// @fnv 0x00995ef0
void DebugTree::FUN_00995ef0(int parent, DebugNode* node)
{
    int count;
    unsigned int index;
    CombatStateHash* object;
    {
        TreeEntry insert;
        char text[260];
        insert.after = -65534;
        insert.mask = 0x27;
        insert.parent = parent;
        insert.parameter = node;
        count = FUN_00995e30(node);
        if (node->FUN_0044edb0())
        {
            float cost = node->FUN_006a7f50() - node->FUN_0044edb0()->FUN_006a7f50();
            {
                char label[260];
                {
                    bool marked;
                    {
                        DebugName* name = *node->GetOffsetC();
                        name->label->Format(label, 260, name->detail);
                        marked = membership->FUN_009962f0(node->GetName());
                        FUN_00406d00(text, 260, "%s [ %i ] (%.2f) %s", label, count, cost, marked ? "***" : "");
                    }
                }
            }
        }
        else
        {
            FUN_00406d00(text, 260, "Start [ %i ]", count);
        }
        insert.text = (char*)PrepareScriptMessage(text, false);
        insert.image = 3;
        insert.selectedImage = insert.image;
        insert.parent = DAT_00fdf28c(tree, 0x1100, 0, &insert);
        insert.parameter = 0;
        FUN_00406d00(text, 260, "Node Cost: %.02f Key: %08X", node->FUN_006a7f50(), (*node->GetName())->ComputeHash());
        insert.text = (char*)PrepareScriptMessage(text, false);
        insert.image = 5;
        insert.selectedImage = insert.image;
        parent = insert.parent;
        insert.parent = DAT_00fdf28c(tree, 0x1100, 0, &insert);
        object = *node->GetName();
        index = object->count;
        for (unsigned int i = 0; i < index; i++)
        {
            DebugEntryLabel* entry = (DebugEntryLabel*)object->entries[i].object;
            if (entry)
            {
                entry->FUN_009aa150(text, 260, -1);
                insert.text = (char*)PrepareScriptMessage(text, false);
                insert.image = 6;
                insert.selectedImage = insert.image;
                DAT_00fdf28c(tree, 0x1100, 0, &insert);
            }
        }
        FUN_00995e30_arr_cls children(16, 0);
        FindAndDispatchById(node, &children);
        for (unsigned int j = 0; j < children.FUN_0044ddc0(); j++)
        {
            FUN_00995ef0(parent, (DebugNode*)*children.FUN_006a7ad0(j));
        }
    }
}
