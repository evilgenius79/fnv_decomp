
// src/staging/blk_00420000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

struct BaseExtraList
{
    bool HasExtraData(unsigned char);
};

struct FUN_004216d0_shell
{
    bool FUN_004216d0();
};

// @fnv 0x004216d0
bool FUN_004216d0_shell::FUN_004216d0()
{
    return ((BaseExtraList*)this)->HasExtraData(0x2e);
}

struct FUN_0042ce90_class
{
    bool FUN_0042ce90() const;
};

// @fnv 0x0042ce90
bool FUN_0042ce90_class::FUN_0042ce90() const
{
    return (*(const int*)((const char*)this + 0x28) & 8) ? true : false;
}

namespace fnv_0042e040 {
struct BaseExtraList
{
    void RemoveExtra(unsigned char);
};

void BaseExtraList::RemoveExtra(unsigned char)
{}

struct FUN_0042e040_shell
{
    void FUN_0042e040();
};

// @fnv 0x0042e040
void FUN_0042e040_shell::FUN_0042e040()
{
    ((BaseExtraList*)this)->RemoveExtra(0x4d);
}
}  // namespace fnv_0042e040

namespace fnv_0042e110 {
struct BSExtraData;
struct BaseExtraList
{
    BSExtraData* GetExtraData(unsigned char type);
};
struct FUN_0042e110 : BaseExtraList
{
    BSExtraData* GetExtraData();
};
// @fnv 0x0042e110
BSExtraData* FUN_0042e110::GetExtraData()
{
    BSExtraData* result = BaseExtraList::GetExtraData(0x55);
    return result;
}
}  // namespace fnv_0042e110

extern "C" void* __cdecl DAT_010159e8;

struct FUN_0042f4e0_class
{
    void* m_vtbl;
    void __thiscall FUN_0042fe10(void* arg);
    void* __thiscall FUN_0042f4e0(void* arg);
};

// Calls FUN_0042fe10 on arg, sets m_vtbl to &DAT_010159e8, and returns this.
// @fnv 0x0042f4e0
void* __thiscall FUN_0042f4e0_class::FUN_0042f4e0(void* arg)
{
    FUN_0042fe10(arg);
    m_vtbl = &DAT_010159e8;
    return this;
}

struct FUN_0042ff10_cls
{
    void FUN_0042ff30(int);
};

// @fnv 0x0042ff10
void FUN_0042ff10(FUN_0042ff10_cls* pTarget, int b)
{
    pTarget->FUN_0042ff30(b);
}

extern int DAT_01015a08;
struct GlobalObject_00869f00
{
    void Clear(bool);
    void FUN_0042ff80();
};
// @fnv 0x0042ff80
void GlobalObject_00869f00::FUN_0042ff80()
{
    *(int*)this = (int)&DAT_01015a08;
    Clear(true);
}

extern void* DAT_01015968;

struct BSExtraData
{
    virtual ~BSExtraData();
};

struct FUN_00435ef0 : public BSExtraData
{
    void* vtbl;
    int a;
    int b;
    int c;
    int d;
    void FUN_00435ef0_init();
};

// Sets the vtable pointer, zeroes the field at offset 0xc, then calls the BSExtraData destructor.
// @fnv 0x00435ef0
void FUN_00435ef0::FUN_00435ef0_init()
{
    *reinterpret_cast<void**>(this) = &DAT_01015968;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0xc) = 0;
    this->BSExtraData::~BSExtraData();
}

struct FUN_006815c0
{
    void* __thiscall _ref_006815c0();
};

struct FUN_00437dd0_Class
{
    void* FUN_00437dd0();
};

// @fnv 0x00437dd0
void* FUN_00437dd0_Class::FUN_00437dd0()
{
    return *(void**)(((FUN_006815c0*)((char*)this + 0x20))->_ref_006815c0());
}

extern int DAT_01015fbc;
struct FUN_004383b0_Class
{
    void* p;
    void FUN_004386b0(void*);
    void* FUN_004383b0(void* a);
};
// Calls FUN_004386b0 with a, sets p to the address of DAT_01015fbc, and returns this.
// @fnv 0x004383b0
void* FUN_004383b0_Class::FUN_004383b0(void* apArg)
{
    FUN_004386b0(apArg);
    p = &DAT_01015fbc;
    return this;
}

extern "C" void __cdecl FUN_00438820(void*);
extern char DAT_01015fdc;

struct FUN_004383e0_class
{
    void* p;
    void* __thiscall FUN_004383e0(void* a);
};

// Calls FUN_00438820 with this and a, sets p to the address of DAT_01015fdc, and returns this.
// @fnv 0x004383e0
void* __thiscall FUN_004383e0_class::FUN_004383e0(void* apArg)
{
    ((void(__thiscall*)(void*, void*))FUN_00438820)(this, apArg);
    p = &DAT_01015fdc;
    return this;
}

extern int DAT_01015ffc;

struct AX
{
    void FUN_006b3eb0(unsigned int, unsigned int);
    AX* FUN_00438570();
};

// @fnv 0x00438570
AX* AX::FUN_00438570()
{
    *reinterpret_cast<int*>(this) = (int)&DAT_01015ffc;
    FUN_006b3eb0(0, 0);
    return this;
}

namespace fnv_004385a0 {
extern int DAT_01015ffc;
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct FUN_004385a0Class
{
    void FUN_004385a0();
};
// @fnv 0x004385a0
void FUN_004385a0Class::FUN_004385a0()
{
    *(int*)this = (int)&DAT_01015ffc;
    ((GlobalObject_00869f00*)this)->Clear(true);
}
}  // namespace fnv_004385a0

extern int DAT_01016010;
struct BSSimpleArrayShell
{
    void FUN_00438a60(unsigned int, unsigned int);
    BSSimpleArrayShell* FUN_004385c0();
};
// @fnv 0x004385c0
BSSimpleArrayShell* BSSimpleArrayShell::FUN_004385c0()
{
    *reinterpret_cast<int**>(this) = &DAT_01016010;
    FUN_00438a60(0, 0);
    return this;
}

namespace fnv_00438690 {
extern int DAT_01016024;

struct GlobalObject_00869f00
{
    int* p;
    void Clear(bool);
    void FUN_00438690();
};

// @fnv 0x00438690
void GlobalObject_00869f00::FUN_00438690()
{
    p = &DAT_01016024;
    Clear(true);
}
}  // namespace fnv_00438690

void __cdecl Deallocate(void*);

struct FUN_00438940_Class
{
    void __thiscall FUN_00438940(void* p);
};

// Sets byte 8 of p to 0, then passes p to Deallocate.
// @fnv 0x00438940
void __thiscall FUN_00438940_Class::FUN_00438940(void* p)
{
    ((char*)p)[8] = 0;
    void* tmp = p;
    Deallocate(tmp);
}

struct FUN_00438b90_class
{
    char FUN_00438b90();
};

// @fnv 0x00438b90
char FUN_00438b90_class::FUN_00438b90()
{
    if (*(int*)((char*)this + 8) == *(int*)((char*)this + 12))
        return 1;
    return 0;
}

struct FUN_00591300_shell
{
    void FUN_00591300();
};

struct FUN_00438bf0_shell : FUN_00591300_shell
{
    void FUN_00438bf0();
};

// @fnv 0x00438bf0
void FUN_00438bf0_shell::FUN_00438bf0()
{
    FUN_00591300();
}

struct FUN_00438f10_Class
{
    bool FUN_00438f10();
};

// @fnv 0x00438f10
bool FUN_00438f10_Class::FUN_00438f10()
{
    if (*(unsigned char*)((char*)this + 0xc) & 4)
        return true;
    else
        return false;
}

struct FUN_00438f30_Class
{
    unsigned int FUN_00438f30();
};

// @fnv 0x00438f30
unsigned int FUN_00438f30_Class::FUN_00438f30()
{
    return *(unsigned short*)(this + 0xe);
}

struct FUN_004392c0_shell
{
    void FUN_004392c0();
    void FUN_00439320();
};

// @fnv 0x00439320
void FUN_004392c0_shell::FUN_00439320()
{
    FUN_004392c0();
}

struct NiObjectNET
{
    void FUN_00439360(unsigned short a, unsigned int b, unsigned int c);
    void FUN_00439340(unsigned short a);
};

// @fnv 0x00439340
void NiObjectNET::FUN_00439340(unsigned short a)
{
    FUN_00439360(a, 0x1e, 1);
}

namespace fnv_00439390 {
struct NiObjectNET
{
    void FUN_00439360(unsigned short a, unsigned int b, unsigned int c);
    void FUN_00439390(unsigned short a);
};

// Calls FUN_00439360 with the given unsigned short and the constants 0x1e0 and 5.
// @fnv 0x00439390
void NiObjectNET::FUN_00439390(unsigned short ausValue)
{
    FUN_00439360(ausValue, 0x1e0, 5);
}
}  // namespace fnv_00439390

struct NiPoint3
{
    float x, y, z;
};

struct FUN_00439680_class
{
    void FUN_00439680(const NiPoint3& p);
};

// Stores the given NiPoint3 into the object at offset 0x18.
// @fnv 0x00439680
void FUN_00439680_class::FUN_00439680(const NiPoint3& aPoint)
{
    *(NiPoint3*)((char*)this + 0x18) = aPoint;
}

struct FUN_0043b260_Class
{
    unsigned short m_0018;
    bool __thiscall FUN_0043b260(unsigned short* pArg);
};

// Compares the 16-bit value at offset 0x18 of this object with the same field of pArg and returns whether they are equal.
// @fnv 0x0043b260
bool __thiscall FUN_0043b260_Class::FUN_0043b260(unsigned short* pOther)
{
    return *(unsigned short*)((char*)this + 0x18) == *(unsigned short*)((char*)pOther + 0x18);
}

struct TaskQueueInterface
{
    void SetTaskFlagDWord(bool, unsigned int);
    void FUN_0043b350(bool enabled);
};

// @fnv 0x0043b350
void TaskQueueInterface::FUN_0043b350(bool enabled)
{
    SetTaskFlagDWord(enabled, 0x80);
}

struct TESForm
{
    void Revert(unsigned int);
};

struct TESObjectTREE
{
    TESForm* GetData();
};

struct FUN_0043b5b0_shell
{
    void FUN_0043b5b0();
};

// @fnv 0x0043b5b0
void FUN_0043b5b0_shell::FUN_0043b5b0()
{
    ((TESObjectTREE*)this)->GetData()->Revert(1);
}

struct FUN_0043ba10_shell
{
    FUN_0043ba10_shell* FUN_0043ba10(FUN_0043ba10_shell*);
};

struct FUN_0043b9f0_shell
{
    void FUN_0043b9f0(FUN_0043ba10_shell* p);
};

// @fnv 0x0043b9f0
void FUN_0043b9f0_shell::FUN_0043b9f0(FUN_0043ba10_shell* p)
{
    ((FUN_0043ba10_shell*)((char*)this + 8))->FUN_0043ba10(p);
}

struct GO
{
    void* operator=(void*);
};

struct FUN_0043baa0_class
{
    void FUN_0043baa0(void* p);
};

// @fnv 0x0043baa0
void FUN_0043baa0_class::FUN_0043baa0(void* p)
{
    *(GO*)((char*)this + 0x74) = p;
}

bool __cdecl FUN_0044ae10(unsigned char);

struct FUN_0043fab0_class
{
    bool __thiscall FUN_0043fab0();
};

// @fnv 0x0043fab0
bool __thiscall FUN_0043fab0_class::FUN_0043fab0()
{
    return FUN_0044ae10(reinterpret_cast<unsigned char*>(this)[0x120]);
}

extern "C" void* __cdecl _NiFreeAlias(void*);
extern int DAT_01015a1c;

struct FUN_0042fee0_cls : NiTPointerMap<int, int>
{
    void FUN_0042fee0();
};

// Resets the vtable pointer, removes all entries from the map, and frees the pointer stored at offset 8.
// @fnv 0x0042fee0
void __thiscall FUN_0042fee0_cls::FUN_0042fee0()
{
    *(void**)this = &DAT_01015a1c;
    RemoveAll();
    _NiFreeAlias(*(void**)((char*)this + 8));
}

extern int DAT_01015f24;

struct BE
{
    BE(unsigned char);
};

struct FUN_00436ac0 : BE
{
    FUN_00436ac0();
};

// Initialises the base with tag 0x55, installs the vtable pointer from DAT_01015f24, and zeroes the field at offset 0xc.
// @fnv 0x00436ac0
FUN_00436ac0::FUN_00436ac0() : BE(0x55)
{
    *reinterpret_cast<int**>(this) = &DAT_01015f24;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0xc) = 0;
}

namespace fnv_00438780 {
extern "C" void __cdecl _NiFreeAlias(void*);
extern void* DAT_01016038;

struct NiTPointerMap_00438780
{
    void* m_pVTable;
    int m_nSize;
    void* m_pData;
    void RemoveAll();
    void FUN_00438780();
};

// Sets the vtable pointer, removes all entries, and frees the data buffer via _NiFreeAlias.
// @fnv 0x00438780
void NiTPointerMap_00438780::FUN_00438780()
{
    m_pVTable = &DAT_01016038;
    RemoveAll();
    _NiFreeAlias(m_pData);
}
}  // namespace fnv_00438780

struct NavMeshPtr
{
    void __thiscall FUN_0042fa40();
    void* __thiscall FUN_0042ffa0(unsigned int flags);
};
void __cdecl Deallocate(void*);
// Calls FUN_0042fa40, then deallocates this if the flags bit 0 is set, and returns this.
// @fnv 0x0042ffa0
void* __thiscall NavMeshPtr::FUN_0042ffa0(unsigned int flags)
{
    this->FUN_0042fa40();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_0042ffd0_cls : public FUN_0042fee0_cls
{
    void* __thiscall FUN_0042ffd0(unsigned int flags);
};

// Calls the base cleanup, then frees this object when the flags bit 0 is set, and returns this.
// @fnv 0x0042ffd0
void* __thiscall FUN_0042ffd0_cls::FUN_0042ffd0(unsigned int flags)
{
    FUN_0042fee0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_00435ec0 : public BE
{
    void* vtbl;
    int a;
    int b;
    void* p;
    FUN_00435ec0(void* a);
};
// Initialises the object with base value 0x46, sets its vtable to DAT_01015968 and stores the passed pointer in p.
// @fnv 0x00435ec0
FUN_00435ec0::FUN_00435ec0(void* a) : BE(0x46)
{
    vtbl = &DAT_01015968;
    p = a;
}

struct FUN_00435f20_class : public BE
{
    const char* m_pName;
    int m_auiShapeKeys;
    int m_pAuxiliaryObject;
    float m_fValue;
    FUN_00435f20_class(float f);
};
// @fnv 0x00435f20
FUN_00435f20_class::FUN_00435f20_class(float f) : BE(0x48)
{
    m_pName = "P_C";
    m_fValue = f;
}

void __cdecl Deallocate(void*);
struct FUN_00435f80_shell
{
    void __thiscall FUN_00435f80();
};
struct FUN_00435f50_class : FUN_00435f80_shell
{
    void* __thiscall FUN_00435f50(unsigned int flags);
};
// Calls FUN_00435f80, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00435f50
void* __thiscall FUN_00435f50_class::FUN_00435f50(unsigned int flags)
{
    FUN_00435f80();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern "C" void* DAT_01015974;
struct FUN_00436090 : public BE
{
    void* vtbl;
    int a;
    int b;
    unsigned char c;
    FUN_00436090(unsigned char);
};
// @fnv 0x00436090
FUN_00436090::FUN_00436090(unsigned char x) : BE(0x4e)
{
    vtbl = &DAT_01015974;
    c = x;
}

void __cdecl Deallocate(void*);
struct FUN_00436150_Class
{
    void __thiscall FUN_00436180();
    void* __thiscall FUN_00436150(unsigned int flags);
};
// @fnv 0x00436150
void* __thiscall FUN_00436150_Class::FUN_00436150(unsigned int flags)
{
    FUN_00436180();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_00436390_Class
{
    void __thiscall FUN_004363c0();
    void* __thiscall FUN_00436390(unsigned int flags);
};

// @fnv 0x00436390
void* FUN_00436390_Class::FUN_00436390(unsigned int flags)
{
    FUN_004363c0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_004364b0_Class
{
    void __thiscall FUN_004364e0();
    void* __thiscall FUN_004364b0(unsigned int flags);
};
// Calls FUN_004364e0, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x004364b0
void* FUN_004364b0_Class::FUN_004364b0(unsigned int flags)
{
    FUN_004364e0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_004365d0_class
{
    void* __thiscall FUN_00436600();
    void* __thiscall FUN_004365d0(unsigned int flags);
};
// Calls FUN_00436600, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x004365d0
void* __thiscall FUN_004365d0_class::FUN_004365d0(unsigned int flags)
{
    FUN_00436600();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void FUN_00436720();
void __cdecl Deallocate(void*);

struct FUN_004366f0_class
{
    void __thiscall FUN_00436720();
    void* __thiscall FUN_004366f0(unsigned int flags);
};

// Calls FUN_00436720, frees this via Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x004366f0
void* __thiscall FUN_004366f0_class::FUN_004366f0(unsigned int flags)
{
    FUN_00436720();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void Deallocate(void*);
void FUN_00436bb0();
struct FUN_00436af0_Class
{
    void FUN_00436bb0();
    void* FUN_00436af0(unsigned int flags);
};
// @fnv 0x00436af0
void* FUN_00436af0_Class::FUN_00436af0(unsigned int flags)
{
    FUN_00436bb0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void __cdecl FUN_00438720(FUN_004383b0_Class*);
struct FUN_00438410_Class
{
    void* __thiscall FUN_00438720();
    void* __thiscall FUN_00438410(unsigned int flags);
};
// Calls FUN_00438720, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x00438410
void* __thiscall FUN_00438410_Class::FUN_00438410(unsigned int flags)
{
    FUN_00438720();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_004388a0_Class
{
    void* __thiscall FUN_004388a0();
};
struct FUN_00438440_Class
{
    void* __thiscall FUN_00438440(unsigned int flags);
};
// @fnv 0x00438440
void* __thiscall FUN_00438440_Class::FUN_00438440(unsigned int flags)
{
    ((FUN_004388a0_Class*)this)->FUN_004388a0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void Deallocate(void*);
void FUN_004385a0();
struct FUN_00438970_class
{
    void __thiscall FUN_004385a0();
    void* __thiscall FUN_00438970(unsigned int flags);
};
// @fnv 0x00438970
void* __thiscall FUN_00438970_class::FUN_00438970(unsigned int flags)
{
    FUN_004385a0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_004389a0_Class
{
    void* __thiscall FUN_004385f0();
    void* __thiscall FUN_004389a0(unsigned int flags);
};
// Calls FUN_004385f0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x004389a0
void* FUN_004389a0_Class::FUN_004389a0(unsigned int flags)
{
    FUN_004385f0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_00438780_Class
{
    void FUN_00438780();
    void* FUN_00438a00(unsigned int flags);
};
// @fnv 0x00438a00
void* FUN_00438780_Class::FUN_00438a00(unsigned int flags)
{
    FUN_00438780();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_00438900_class
{
    void __thiscall FUN_00438900();
};

struct FUN_00438a30_class
{
    void* __thiscall FUN_00438a30(unsigned int flags);
};

// Calls FUN_00438900 on this, frees this when flags has bit 0 set, and returns this.
// @fnv 0x00438a30
void* __thiscall FUN_00438a30_class::FUN_00438a30(unsigned int flags)
{
    ((FUN_00438900_class*)this)->FUN_00438900();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct PointerFlagNode
{
    void _ref_00905330(const unsigned int&);
};
struct FUN_004207e0Class
{
    PointerFlagNode* FUN_004207e0();
    void FUN_00420da0(unsigned int);
};
// @fnv 0x00420da0
void FUN_004207e0Class::FUN_00420da0(unsigned int a1)
{
    PointerFlagNode* p = FUN_004207e0();
    if (p)
        p->_ref_00905330(a1);
}

struct Flt
{
    operator unsigned int();
};
struct Holder00420dd0
{
    BSExtraData* __thiscall GetExtraData(unsigned char);
    unsigned int __thiscall FUN_00420dd0();
};
// @fnv 0x00420dd0
unsigned int __thiscall Holder00420dd0::FUN_00420dd0()
{
    BSExtraData* e = GetExtraData(0x78);
    if (e)
        return (unsigned int)(*(Flt*)((char*)e + 0xc));
    return 0;
}

extern int DAT_01015998;

struct FUN_0042cba0_class : public BE
{
    void* vtbl;
    int a;
    int b;
    int c;
    int d;
    FUN_0042cba0_class();
};

// Initialises the object with base value 0x6e, sets its vtbl to DAT_01015998, and zeroes fields c and d.
// @fnv 0x0042cba0
FUN_0042cba0_class::FUN_0042cba0_class() : BE(0x6e)
{
    vtbl = (void*)&DAT_01015998;
    c = 0;
    d = 0;
}

struct FHolder_42cbe0 : BE
{
    void* __thiscall FUN_0042cbe0();
};
extern int DAT_010151fc;
// Initialises the object with BE(0x70), installs the vtable pointer DAT_010151fc, zeroes the field at offset 0xc, and returns this.
// @fnv 0x0042cbe0
void* __thiscall FHolder_42cbe0::FUN_0042cbe0()
{
    this->BE::BE(0x70);
    *(void**)this = (void*)&DAT_010151fc;
    *(int*)((char*)this + 0xc) = 0;
    return this;
}

struct FUN_0042cc10_class
{
    int m0;
    int m4;
    float m8;
    FUN_0042cc10_class* __thiscall FUN_0042cc10();
};
// Initialises the object's fields to zero, -1 and -1.0f, then returns this.
// @fnv 0x0042cc10
FUN_0042cc10_class* __thiscall FUN_0042cc10_class::FUN_0042cc10()
{
    m0 = 0;
    m4 = -1;
    m8 = -1.0f;
    return this;
}

struct FUN_00432470 : public BSExtraData
{
    int x;
    int y;
    int z;
    FUN_00432470(int v);
    ~FUN_00432470();
};
struct ExtraListHelper
{
    BSExtraData* GetExtraData(unsigned char);
    BSExtraData* AddExtra(BSExtraData*);
};
struct FUN_0042dee0_shell
{
    void __thiscall FUN_0042dee0(int v);
};
// Looks up extra data of type 0x4d; if absent, creates a new FUN_00432470 with v and adds it, otherwise stores v at offset 0xc.
// @fnv 0x0042dee0
void __thiscall FUN_0042dee0_shell::FUN_0042dee0(int aiValue)
{
    BSExtraData* extra = ((ExtraListHelper*)this)->GetExtraData(0x4d);
    if (!extra)
    {
        extra = new FUN_00432470(aiValue);
        ((ExtraListHelper*)this)->AddExtra(extra);
    }
    else
    {
        *(int*)((char*)extra + 0xc) = aiValue;
    }
}

struct ExtraDataList
{
    BSExtraData* GetExtraData(unsigned char);
};
struct ExtraLock
{
    bool FUN_0042dff0();
    void FUN_0042e010(int);
    ~ExtraLock();
};
struct FUN_0042df90_shell
{
    ExtraLock* FUN_0042df90(int a);
};
// @fnv 0x0042df90
ExtraLock* FUN_0042df90_shell::FUN_0042df90(int a)
{
    ExtraLock* p = 0;
    ExtraDataList* e = (ExtraDataList*)((ExtraDataList*)this)->GetExtraData(0x4d);
    if (e && (p = (ExtraLock*)*(void**)((char*)e + 0xc)) && p->FUN_0042dff0())
        p->FUN_0042e010(a);
    return p;
}

extern int DAT_01015980;
struct FUN_0042e210_Class : public BE
{
    void* vtbl;
    int a;
    int b;
    int c;
    int d;
    FUN_0042e210_Class(int x, int y);
};
// Initializes the object with base BE(0x5b), sets vtbl to DAT_01015980, and stores x into c and y into d.
// @fnv 0x0042e210
FUN_0042e210_Class::FUN_0042e210_Class(int x, int y) : BE(0x5b)
{
    vtbl = &DAT_01015980;
    c = x;
    d = y;
}

extern void* DAT_010159bc;
struct FUN_0042e650_class : BE
{
    void* vtbl;
    int a;
    int b;
    unsigned char c;
    FUN_0042e650_class(unsigned char c);
};
// Initialises the object with base value 0x8e, sets its vtbl to DAT_010159bc and stores c in field c.
// @fnv 0x0042e650
FUN_0042e650_class::FUN_0042e650_class(unsigned char aucValue) : BE(0x8e)
{
    vtbl = &DAT_010159bc;
    this->c = aucValue;
}

struct NiAVObject
{
    void FUN_00401970();
};
struct G00559a40
{
    void FUN_0040f6e0();
};
struct FUN_0042fdc0_class
{
    NiAVObject* m_pObject;
    NiAVObject* __thiscall FUN_0042fdc0(NiAVObject** arg);
};
// @fnv 0x0042fdc0
NiAVObject* __thiscall FUN_0042fdc0_class::FUN_0042fdc0(NiAVObject** apObject)
{
    if (m_pObject != *apObject)
    {
        if (m_pObject)
            ((NiAVObject*)((char*)m_pObject + 0x1c))->FUN_00401970();
        m_pObject = *apObject;
        if (m_pObject)
            ((G00559a40*)((char*)m_pObject + 0x1c))->FUN_0040f6e0();
    }
    return (NiAVObject*)this;
}

void* __cdecl NiMalloc(unsigned int);
void* __cdecl memset(void* dest, int c, unsigned int count);

struct FUN_0042fe10_class
{
    void* m_pName;
    unsigned int m_uiCount;
    void* m_pData;
    unsigned int m_uiSize;
    void* __thiscall FUN_0042fe10(unsigned int count);
};

// @fnv 0x0042fe10
void* FUN_0042fe10_class::FUN_0042fe10(unsigned int count)
{
    m_pName = &DAT_01015a1c;
    m_uiCount = count;
    m_uiSize = 0;
    unsigned int size = m_uiCount * 4;
    m_pData = NiMalloc(size);
    memset(m_pData, 0, m_uiCount * 4);
    return this;
}

struct FUN_0042ff80_s
{
    void __thiscall FUN_0042ff80();
};
void __cdecl _Deallocate(void*);
struct FUN_0042ff50_host : FUN_0042ff80_s
{
    void* __thiscall FUN_0042ff50(unsigned int flags);
};
// Calls FUN_0042ff80, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0042ff50
void* __thiscall FUN_0042ff50_host::FUN_0042ff50(unsigned int flags)
{
    FUN_0042ff80();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

extern void* _EmptyFS;
void* __cdecl FUN_00438210(void*);
void __cdecl FinishScriptRunLock(void*);

// If the object at p is not _EmptyFS, obtains a value via FUN_00438210 and passes it to FinishScriptRunLock.
// @fnv 0x004381d0
void FUN_004381d0(void* p)
{
    if (*(void**)p == _EmptyFS)
        return;
    void* r = FUN_00438210(p);
    FinishScriptRunLock(r);
}

// @fnv 0x00438210
int __cdecl FUN_00438210(int* p)
{
    return *p - 8;
}

extern int DAT_01016024;
struct FUN_00438660_class
{
    void* vtable;
    FUN_00438660_class* FUN_00438660();
};
// Sets the vtable to DAT_01016024, calls FUN_006b3eb0 with 0, 0, and returns this.
// @fnv 0x00438660
FUN_00438660_class* FUN_00438660_class::FUN_00438660()
{
    vtable = &DAT_01016024;
    reinterpret_cast<AX*>(this)->FUN_006b3eb0(0, 0);
    return this;
}

extern void* DAT_01016058;
void __cdecl Deallocate(void*);

// @fnv 0x00438900
void __thiscall FUN_00438900_class::FUN_00438900()
{
    *reinterpret_cast<void**>(this) = &DAT_01016058;
    if (*(void**)((char*)this + 8))
    {
        void* p = *(void**)((char*)this + 8);
        Deallocate(p);
    }
}

struct FNStub
{
    const char* GetFullName();
};
struct TESModel
{
    unsigned int GetModelLength();
};
struct TESSound
{
    unsigned int Deallocate();
};
void __cdecl FUN_004856f0(unsigned int, void*, unsigned int);
void __cdecl FUN_004858f0(unsigned int, unsigned char);
void __cdecl FUN_00485910(unsigned int, unsigned int);
void __cdecl FUN_00485950(unsigned int, unsigned int);
struct FUN_00438c10_Class : public FNStub
{
    void __thiscall FUN_00438c10();
};
// @fnv 0x00438c10
void __thiscall FUN_00438c10_Class::FUN_00438c10()
{
    FUN_004858f0(0x4d414e46, *(unsigned char*)((char*)this + 0xc));
    FUN_004856f0(0x4c4c5546, (void*)GetFullName(), ((TESModel*)this)->GetModelLength() + 1);
    FUN_00485950(0x4d414e54, *(unsigned short*)((char*)this + 0xe));
    if (*(void**)((char*)this + 0x10))
    {
        unsigned int r = ((TESSound*)*(void**)((char*)this + 0x10))->Deallocate();
        FUN_00485910(0x31494d57, r);
    }
}

extern "C" void FUN_00485710(unsigned int, unsigned int*, unsigned int);
struct FUN_00438f90_Class
{
    bool FUN_00439150();
    void FUN_00438f90();
};
// @fnv 0x00438f90
void FUN_00438f90_Class::FUN_00438f90()
{
    if (FUN_00439150())
        return;
    FUN_00485710(0x4f424d58, (unsigned int*)this, 3);
}

struct Unk_00439120
{
    int m0;
    int m4;
    int m8;
    void FUN_00439120(Unk_00439120* p);
};
// Copies the contents of the object pointed to by p into this object when p is non-null.
// @fnv 0x00439120
void Unk_00439120::FUN_00439120(Unk_00439120* apSource)
{
    if (apSource)
        *this = *apSource;
}

struct S_00439150
{
    bool __thiscall _Call_439090(const NiPoint3&);
    bool __thiscall FUN_00439150();
};
extern int DAT_011c3ae4;
// @fnv 0x00439150
bool __thiscall S_00439150::FUN_00439150()
{
    if (_Call_439090(*(const NiPoint3*)&DAT_011c3ae4))
    {
        return false;
    }
    return true;
}

struct MyPoint439180
{
    float x;
    float y;
    float z;
    MyPoint439180* __thiscall FUN_00439180(float);
};
// Multiplies x, y and z by fScalar and returns this.
// @fnv 0x00439180
MyPoint439180* __thiscall MyPoint439180::FUN_00439180(float fScalar)
{
    x *= fScalar;
    y *= fScalar;
    z *= fScalar;
    return this;
}

struct Mat9
{
    int v[9];
};
struct FUN_004396b0_class
{
    char _pad[0x24];
    Mat9 m;
    void __thiscall FUN_004396b0(const Mat9& src);
};
// Copies the 9-element matrix src into the object's m field.
// @fnv 0x004396b0
void __thiscall FUN_004396b0_class::FUN_004396b0(const Mat9& aMatrix)
{
    m = aMatrix;
}

struct FUN_00439f50_class
{
    void FUN_00439f50(unsigned int col, NiPoint3* out);
};
// Reads three floats at offsets col*4, col*4+0xc and col*4+0x18 from this into out as x, y and z.
// @fnv 0x00439f50
void FUN_00439f50_class::FUN_00439f50(unsigned int uiColumn, NiPoint3* out)
{
    out->x = *(float*)((char*)this + uiColumn * 4);
    out->y = *(float*)((char*)this + uiColumn * 4 + 0xc);
    out->z = *(float*)((char*)this + uiColumn * 4 + 0x18);
}

struct Node
{
    void* p;
};
struct Helper62d0
{
    void* operator=(const void*);
};
struct ScriptPool
{
    Node* FUN_0049fa80();
    void FUN_0049fa20(Node* p);
    void FUN_00439fd0(const void* arg);
};
// Gets a node from the pool, assigns arg to the node's field at offset 8, then releases the node back to the pool.
// @fnv 0x00439fd0
void __thiscall ScriptPool::FUN_00439fd0(const void* arg)
{
    Node* p = FUN_0049fa80();
    ((Helper62d0*)((char*)p + 8))->operator=(arg);
    FUN_0049fa20(p);
}

struct TESSaveLoadGame
{
    void ReadTypedData(void* p, unsigned int size);
    void FUN_00857aa0(unsigned int* pOut, int size);
};
extern TESSaveLoadGame* g_TESSaveLoadGame;

struct FUN_0043a9a0_class
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
    unsigned int e;
    unsigned int f;
    unsigned int g;
    unsigned int h;
    unsigned int i;
    unsigned int j;
    unsigned int k;
    unsigned int l;
    unsigned int m;
    unsigned int n;
    unsigned int o;
    unsigned int p;
    unsigned int q;
    unsigned int r;
    unsigned int s;
    unsigned int t;
    unsigned int u;
    unsigned int v;
    unsigned int w;
    unsigned int x;
    unsigned int y;
    unsigned int z;
    void __thiscall FUN_0043a9a0();
};

// @fnv 0x0043a9a0
void __thiscall FUN_0043a9a0_class::FUN_0043a9a0()
{
    g_TESSaveLoadGame->ReadTypedData((char*)this + 4, 0xc);
    g_TESSaveLoadGame->ReadTypedData((char*)this + 0x10, 0xc);
    unsigned int v;
    g_TESSaveLoadGame->FUN_00857aa0(&v, 4);
    a = v;
}

namespace fnv_0043b250 {
struct Flt
{
    operator unsigned int();
};
extern Flt DAT_011f4438;
// @fnv 0x0043b250
unsigned int __cdecl FUN_0043b250()
{
    return DAT_011f4438;
}
}  // namespace fnv_0043b250

namespace fnv_0043b2a0 {
struct Flt
{
    operator unsigned int();
};
extern Flt DAT_011f4444;

// @fnv 0x0043b2a0
unsigned int __cdecl FUN_0043b2a0()
{
    return DAT_011f4444;
}
}  // namespace fnv_0043b2a0

struct S_0043b320
{
    char _pad0[0x38];
    TaskQueueInterface** arr;
    void __thiscall FUN_0043b320(unsigned short a, TaskQueueInterface* b);
};
// Stores b in arr[a] and, when b is non-null, calls b->FUN_0043b350(true).
// @fnv 0x0043b320
void __thiscall S_0043b320::FUN_0043b320(unsigned short usIndex, TaskQueueInterface* pTaskQueue)
{
    arr[usIndex] = pTaskQueue;
    if (pTaskQueue)
        pTaskQueue->FUN_0043b350(true);
}

namespace fnv_0043ba60 {
extern int _EmptyFS;
void* __cdecl FUN_00438210(void*);
int __cdecl InitScriptRunLock(void*);
// @fnv 0x0043ba60
void __cdecl FUN_0043ba60(int* p)
{
    void* v;
    if (*p == _EmptyFS)
    {
    }
    else
    {
        v = FUN_00438210(p);
        InitScriptRunLock(v);
    }
}
}  // namespace fnv_0043ba60

struct FUN_00435820 : public BSExtraData
{
    FUN_00435820();
    ~FUN_00435820();
    char m_data[0xc];
};
struct FUN_00420e00_cls : public BaseExtraList
{
    BSExtraData* GetExtraData(unsigned char);
    BSExtraData* AddExtra(BSExtraData*);
    void RemoveExtra(unsigned char);
    void FUN_00420e00(void* p);
};
// Stores p in the extra data of type 0x78, creating and adding it if absent, or removes that extra data when p is null.
// @fnv 0x00420e00
void FUN_00420e00_cls::FUN_00420e00(void* apData)
{
    if (apData)
    {
        FUN_00435820* e = (FUN_00435820*)GetExtraData(0x78);
        if (e)
        {
            ((GO*)((char*)e + 0xc))->operator=(apData);
        }
        else
        {
            e = new FUN_00435820;
            ((GO*)((char*)e + 0xc))->operator=(apData);
            AddExtra(e);
        }
    }
    else
    {
        RemoveExtra(0x78);
    }
}

struct FUN_00421600_Class
{
    BSExtraData* GetExtraData(unsigned char);
    BSExtraData* AddExtra(BSExtraData*);
    void FUN_00421600(unsigned char val);
};
// Stores val in the byte at offset 0xc of extra data 0x4e, creating a new FUN_00436090 extra if none exists.
// @fnv 0x00421600
void FUN_00421600_Class::FUN_00421600(unsigned char aucValue)
{
    BSExtraData* extra = GetExtraData(0x4e);
    if (extra)
        *(unsigned char*)((char*)extra + 0xc) = aucValue;
    else
    {
        extra = (BSExtraData*)new FUN_00436090(aucValue);
        AddExtra(extra);
    }
}

extern int DAT_01015cd8;
struct ListX
{
    void* m_pInventoryEntryData;
    void* m_pNext;
    void* m_pListObject;
    ~ListX();
};
struct FUN_00433830 : public BSExtraData
{
    void* m_pData;
    int m_iFlags;
    ListX m_kEntryList;
    ~FUN_00433830();
};
void __cdecl FUN_00433750(ListX*);
// @fnv 0x00433830
FUN_00433830::~FUN_00433830()
{
    FUN_00433750(&m_kEntryList);
}

extern "C" void _fnv_zlib_memset(void* p, int c, unsigned int n);
struct FUN_00438820_Class
{
    void* vtbl;
    int count;
    void* data;
    int pad;
    FUN_00438820_Class(int c);
};
// Sets the vtable, stores the count, and, when count is nonzero, allocates count*4 zeroed bytes into data.
// @fnv 0x00438820
FUN_00438820_Class::FUN_00438820_Class(int aiCount)
{
    vtbl = &DAT_01016058;
    count = aiCount;
    pad = 0;
    if (aiCount)
    {
        unsigned int size = count * 4;
        void* p3 = operator new(size);
        data = p3;
        _fnv_zlib_memset(data, 0, count * 4);
    }
}

struct BaseExtraList2
{
    BSExtraData* GetExtraData(unsigned char type);
    BSExtraData* AddExtra(BSExtraData* extra);
};
struct TESLeveledList
{
    void FUN_0042e680(unsigned char type);
};
struct FUN_0042e5a0_class
{
    void FUN_0042e5a0(unsigned char type);
};
// @fnv 0x0042e5a0
void FUN_0042e5a0_class::FUN_0042e5a0(unsigned char type)
{
    BSExtraData* extra = ((BaseExtraList2*)this)->GetExtraData(0x8e);
    if (!extra)
    {
        extra = (BSExtraData*)new FUN_0042e650_class(type);
        ((BaseExtraList2*)this)->AddExtra(extra);
    }
    else
    {
        ((TESLeveledList*)extra)->FUN_0042e680(type);
    }
}

extern int DAT_01016038;
void* __cdecl NiMalloc(unsigned int);
void* __cdecl memset(void* dest, int c, unsigned int count);
struct FUN_004386b0_Class
{
    void* p;
    void* __thiscall FUN_004386b0(void* a);
};
// Stores a pointer and a count, allocates count*4 bytes, zeroes them, and returns this.
// @fnv 0x004386b0
void* FUN_004386b0_Class::FUN_004386b0(void* auiCount)
{
    p = &DAT_01016038;
    *(void**)((char*)this + 4) = auiCount;
    *(int*)((char*)this + 0xc) = 0;
    unsigned int size = *(int*)((char*)this + 4) << 2;
    *(void**)((char*)this + 8) = NiMalloc(size);
    memset(*(void**)((char*)this + 8), 0, *(int*)((char*)this + 4) << 2);
    return this;
}

struct NiPoint3Set
{
    void Set(float x, float y, float z);
};
struct FUN_00439ef0_class : public NiPoint3
{
    NiPoint3* FUN_00439ef0(NiPoint3* a, const NiPoint3& b);
};
// Subtracts b from this NiPoint3, stores the result in a, and returns a.
// @fnv 0x00439ef0
NiPoint3* FUN_00439ef0_class::FUN_00439ef0(NiPoint3* apResult, const NiPoint3& arSubtrahend)
{
    ((NiPoint3Set*)apResult)->Set(x - arSubtrahend.x, y - arSubtrahend.y, z - arSubtrahend.z);
    return apResult;
}

struct NiInterpController
{
    static const unsigned short INVALID_INDEX;
};
struct FUN_0043b3b0_class
{
    unsigned short FUN_0043b3b0(unsigned int value);
};
// Scans the array at offset 0x38 up to the count at 0x3c and returns the index of the first element equal to value, or INVALID_INDEX if none matches.
// @fnv 0x0043b3b0
unsigned short FUN_0043b3b0_class::FUN_0043b3b0(unsigned int value)
{
    unsigned short i = 0;
    for (; i < *(unsigned short*)((char*)this + 0x3c); ++i)
    {
        if (*(unsigned int*)(*(unsigned int*)((char*)this + 0x38) + i * 4) == value)
            return i;
    }
    return NiInterpController::INVALID_INDEX;
}

struct G2
{
    void AddHead(int* pValue);
};

struct LH
{
    bool IsInList(int& value);
};

struct FUN_00420440_Class
{
    void FUN_00420440(void* pObject);
};

struct FUN_00416b80
{
    void* vtbl;
    int a;
    int b;
    int c;
    int d;

    FUN_00416b80();
};

struct FUN_00420c10_Class : public FUN_004207e0Class
{
    void FUN_00420c10(int value);
};

void* __cdecl operator new(unsigned int size);

// Ensures the object exists when value is nonzero, then adds value to the list at offset 8 if it is not already present.
// @fnv 0x00420c10
void FUN_00420c10_Class::FUN_00420c10(int value)
{
    if (!this->FUN_004207e0() && value)
    {
        ((FUN_00420440_Class*)this)->FUN_00420440(new FUN_00416b80());
    }

    void* m_pLinkedReference = this->FUN_004207e0();
    if (!((LH*)((char*)m_pLinkedReference + 8))->IsInList(value))
    {
        ((G2*)((char*)m_pLinkedReference + 8))->AddHead(&value);
    }
}

struct FUN_0042cca0 : public BSExtraData
{
    void* vtbl;
    int a;
    int b;
    int c;
    int d;
    virtual ~FUN_0042cca0();
};
// @fnv 0x0042cca0
FUN_0042cca0::~FUN_0042cca0()
{}

struct BSSimpleListTESRaceSize
{
    int GetSize();
};
struct FUN_0042dff0_shell
{
    int FUN_0042dff0();
};
// @fnv 0x0042dff0
int FUN_0042dff0_shell::FUN_0042dff0()
{
    return ((BSSimpleListTESRaceSize*)((char*)this + 0xc))->GetSize() == 0 ? 1 : 0;
}

struct FUN_0042e130_Base
{
    void RemoveExtra(unsigned char);
};

struct FUN_0042e130_shell : FUN_0042e130_Base
{
    void FUN_0042e130();
};

// @fnv 0x0042e130
void FUN_0042e130_shell::FUN_0042e130()
{
    FUN_0042e130_Base::RemoveExtra(0x55);
}

struct FUN_0042e6d0 : public BSExtraData
{
    virtual ~FUN_0042e6d0();
};
// @fnv 0x0042e6d0
FUN_0042e6d0::~FUN_0042e6d0()
{}

struct NavMeshArr
{
    ~NavMeshArr();
    void* __thiscall FUN_0042f510(unsigned int flags);
};

NavMeshArr::~NavMeshArr()
{}

// Runs the destructor and, when flags has bit 0 set, deallocates the object; returns this.
// @fnv 0x0042f510
void* NavMeshArr::FUN_0042f510(unsigned int flags)
{
    this->NavMeshArr::~NavMeshArr();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct BSSimpleArrayActor
{
    void* m_vtbl;
    int* m_data;
    unsigned int m_iElementCount;
    unsigned int m_pRayCursor;

    void Clear(bool);
    void FUN_0042f5f0(unsigned int count, bool clear);
};

struct FUN_0042fc00_shell
{
    void __thiscall FUN_0042fc00(void* count, unsigned int size);
};

struct BSSimpleArrayShell_FUN_00430000
{
    void __thiscall FUN_00430000(void* data, unsigned int count);
};

struct FUN_0072ba80_shell
{
    void __thiscall FUN_0072ba80(char* data, unsigned int count);
};

// @fnv 0x0042f5f0
void BSSimpleArrayActor::FUN_0042f5f0(unsigned int count, bool clear)
{
    if (count == 0)
    {
        Clear(clear);
    }
    else if (count > m_pRayCursor)
    {
        if (m_pRayCursor == 0)
        {
            typedef int*(__thiscall * GrowProc)(BSSimpleArrayActor*, unsigned int);
            m_data = reinterpret_cast<GrowProc*>(m_vtbl)[1](this, count);
            m_pRayCursor = count;
        }
        else
        {
            reinterpret_cast<FUN_0042fc00_shell*>(this)->FUN_0042fc00(reinterpret_cast<void*>(count), m_iElementCount);
            m_pRayCursor = count;
        }

        reinterpret_cast<BSSimpleArrayShell_FUN_00430000*>(this)->FUN_00430000(m_data + m_iElementCount, count - m_iElementCount);
        m_iElementCount = count;
    }
    else if (count < m_iElementCount)
    {
        reinterpret_cast<FUN_0072ba80_shell*>(this)->FUN_0072ba80(reinterpret_cast<char*>(m_data + count),
                                                                  m_iElementCount - count);
        m_iElementCount = count;

        if (clear && count <= m_pRayCursor / 4)
        {
            reinterpret_cast<FUN_0042fc00_shell*>(this)->FUN_0042fc00(reinterpret_cast<void*>(count), count);
            m_pRayCursor = count;
        }
    }
    else
    {
        reinterpret_cast<BSSimpleArrayShell_FUN_00430000*>(this)->FUN_00430000(m_data + m_iElementCount, count - m_iElementCount);
        m_iElementCount = count;
    }
}

struct AC_0042f730
{
    void* vtbl;
    void __fastcall FUN_0066e2b0();
    void __fastcall FUN_0042f760();
};

// @fnv 0x0042f760
void __fastcall AC_0042f730::FUN_0042f760()
{
    if (vtbl)
        ((AC_0042f730*)vtbl)->FUN_0066e2b0();
}

struct NiPointerStandIn
{
    bool operator==(int) const;
};
// @fnv 0x0042ff30
void FUN_0042ff10_cls::FUN_0042ff30(int aiValue)
{
    ((NiPointerStandIn*)this)->operator==(aiValue);
}

struct BSExtraDataHelper
{
    virtual ~BSExtraDataHelper();
};
struct FUN_00435f80 : public BSExtraDataHelper
{
    virtual ~FUN_00435f80();
};
// @fnv 0x00435f80
FUN_00435f80::~FUN_00435f80()
{}

struct FUN_004362a0
{
    ~FUN_004362a0();
    void* __thiscall FUN_00436270(unsigned int flags);
};

// Runs the destructor, frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00436270
void* FUN_004362a0::FUN_00436270(unsigned int flags)
{
    FUN_004362a0::~FUN_004362a0();

    if (flags & 1)
        _Deallocate(this);

    return this;
}

struct FUN_00436bb0 : public BSExtraData
{
    virtual ~FUN_00436bb0();
};
// @fnv 0x00436bb0
FUN_00436bb0::~FUN_00436bb0()
{}

namespace fnv_004385f0 {
struct BSSimpleArrayActor
{
    void* m_vtbl;
    void Clear(bool);
};
struct FUN_004385f0_Class
{
    void __thiscall FUN_004385f0();
};
// @fnv 0x004385f0
void __thiscall FUN_004385f0_Class::FUN_004385f0()
{
    *(void**)this = &DAT_01016010;
    ((BSSimpleArrayActor*)this)->Clear(true);
}
}  // namespace fnv_004385f0

struct FUN_0043a080_Node
{
    FUN_0043a080_Node* next;
    int field2;
    int field3;
};

extern int DAT_01188f7c;
extern void* DAT_011c5f54;
extern void* DAT_011c5f58;

// @fnv 0x0043a080
void FUN_0043a080()
{
    DAT_011c5f58 = new FUN_0043a080_Node[DAT_01188f7c];

    FUN_0043a080_Node* index = (FUN_0043a080_Node*)DAT_011c5f58 + DAT_01188f7c - 1;
    index->next = 0;

    unsigned int uiIndex = 1;
    do
    {
        index = (FUN_0043a080_Node*)DAT_011c5f58 + uiIndex;
        index->next = index + 1;
    } while (uiIndex++ < DAT_01188f7c - 2);

    if (DAT_011c5f54 != 0)
    {
        ((FUN_0043a080_Node*)DAT_011c5f58)->next = (FUN_0043a080_Node*)DAT_011c5f54;
        DAT_011c5f54 = DAT_011c5f58;
    }
    else
    {
        DAT_011c5f54 = DAT_011c5f58;
        ((FUN_0043a080_Node*)DAT_011c5f54)->next = 0;
    }

    DAT_011c5f58 = (char*)DAT_011c5f58 + 12;
}

struct Date
{
    ~Date();
};
struct FUN_0043b5f0_cls : TESObjectTREE
{
    void FUN_0043b5f0();
};
// @fnv 0x0043b5f0
void FUN_0043b5f0_cls::FUN_0043b5f0()
{
    ((Date*)GetData())->Date::~Date();
}

struct ExtraListShell
{
    void RemoveExtra(unsigned char type);
    void FUN_004216b0();
};
// @fnv 0x004216b0
void ExtraListShell::FUN_004216b0()
{
    RemoveExtra(0x4E);
}

extern "C" void* DAT_0101598c;

struct FUN_0040ecb0
{
    virtual ~FUN_0040ecb0();
    int unk04;
    int unk08;
};

struct FUN_0042f780
{
    int unk00;
    int unk04;
    int unk08;

    void Init(int value);
    ~FUN_0042f780();
};

struct FUN_0042cb30 : public FUN_0040ecb0
{
    FUN_0042f780 unk0c;

    virtual ~FUN_0042cb30();
};

// Destructor for FUN_0042cb30 that resets its unk0c member by calling Init(0).
// @fnv 0x0042cb30
FUN_0042cb30::~FUN_0042cb30()
{
    unk0c.Init(0);
}

class BSString42C
{
  public:
    BSString42C();
    ~BSString42C();

    char* m_pString;
    unsigned short m_usLen;
    unsigned short m_usMaxLen;
};

class BSExtraData42C
{
  public:
    BSExtraData42C(unsigned char ucType);
    virtual ~BSExtraData42C();

    unsigned char m_ucType;
    BSExtraData42C* m_pkNext;
};

class FUN_0042ccc0 : public BSExtraData42C
{
  public:
    FUN_0042ccc0();
    virtual ~FUN_0042ccc0();

    BSString42C m_kFirst;
    BSString42C m_kSecond;
};

// Constructs a BSExtraData42C-derived extra-data object of type 0x8f holding two BSString42C members.
// @fnv 0x0042ccc0
FUN_0042ccc0::FUN_0042ccc0() : BSExtraData42C(0x8f)
{}

struct FUN_00436b20
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FUN_00436b20(unsigned int a, unsigned int b);
};
struct FUN_0042e060_class
{
    void* __thiscall GetExtraData(unsigned char type);
    void __thiscall RemoveExtra(void* extra, bool remove);
    void __thiscall AddExtra(void* extra);
    void __thiscall FUN_0042e060(unsigned int a, unsigned int b);
};
// Removes the existing 0x55-type entry, allocates a new FUN_00436b20 from a and b, and installs it via AddExtra.
// @fnv 0x0042e060
void FUN_0042e060_class::FUN_0042e060(unsigned int a, unsigned int b)
{
    void* pEntry = GetExtraData(0x55);
    if (pEntry)
        RemoveExtra(pEntry, true);
    pEntry = new FUN_00436b20(a, b);
    AddExtra(pEntry);
}

void* __cdecl operator new(unsigned int uiSize, void* pvMem);
void __cdecl operator delete(void* pvObject, void* pvMem);

struct B42FA60Entry
{
    int unk00;

    B42FA60Entry();
};

class B42FA60Allocator
{
  public:
    void FUN_0042fa60(B42FA60Entry* pkArray, unsigned int ItemUpdateArray);
};

// Constructs each B42FA60Entry in the array in place using placement new.
// @fnv 0x0042fa60
void B42FA60Allocator::FUN_0042fa60(B42FA60Entry* pkArray, unsigned int ItemUpdateArray)
{
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
        new (&pkArray[i]) B42FA60Entry;
}

class B42FE80MapBase
{
  public:
    virtual ~B42FE80MapBase();
    int m_uiHashSize;
    void** m_ppkHashTable;
    int m_uiCount;
};

class FUN_0042fe80_Map : public B42FE80MapBase
{
  public:
    virtual ~FUN_0042fe80_Map();
    void RemoveAll();
};

// @fnv 0x0042fe80
FUN_0042fe80_Map::~FUN_0042fe80_Map()
{
    RemoveAll();
}

void* __cdecl operator new(unsigned int, void*);
void __cdecl operator delete(void*, void*);
struct FUN_004300a0
{
    void* m_uiFilterValue;
    FUN_004300a0();
};
// Default-constructs count FUN_004300a0 objects in place at data.
// @fnv 0x00430000
void BSSimpleArrayShell_FUN_00430000::FUN_00430000(void* data, unsigned int count)
{
    for (unsigned int index = 0; index < count; ++index)
    {
        new (&static_cast<FUN_004300a0*>(data)[index]) FUN_004300a0;
    }
}

struct SpawnedSub
{
    ~SpawnedSub();
};

struct SpawnedBase
{
    int unk00;
    int unk04;
    int unk08;
    ~SpawnedBase();
};

struct FUN_00435ce0_cls : public SpawnedBase
{
    SpawnedSub m_0c;
    ~FUN_00435ce0_cls();
};

// Destructor for FUN_00435ce0_cls that destroys its SpawnedSub member and base SpawnedBase.
// @fnv 0x00435ce0
FUN_00435ce0_cls::~FUN_00435ce0_cls()
{}

struct FloatSlot
{
    unsigned int m_bits;
    float FUN_00435e00();
};

struct FloatHolder
{
    float m_f;
    void FUN_00435de0(float v);
};

struct FloatList
{
    int unk00;
    int FUN_0044ddc0();
    unsigned int* FUN_006a7ad0(int idx);
    void FUN_00438610(FloatHolder* p);
};

struct FloatGlobal
{
    int unk00;
    float* FUN_00403e20();
};

extern FloatGlobal DAT_011cd78c;
float FUN_00435dd0();

class FUN_00435d40_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    FloatList m_0c;

    void Reset();
    void FUN_00435d40();
};

// @fnv 0x00435d40
void FUN_00435d40_cls::FUN_00435d40()
{
    Reset();
    int n = m_0c.FUN_0044ddc0();
    if (n > 0)
    {
        FloatSlot v;
        v.m_bits = *m_0c.FUN_006a7ad0(n - 1);
        if (v.FUN_00435e00() < *DAT_011cd78c.FUN_00403e20())
            return;
    }
    FloatHolder h;
    h.FUN_00435de0(FUN_00435dd0());
    m_0c.FUN_00438610(&h);
}

struct FUN_00435e40_key
{
    unsigned int m_v;
    double Eval();
};
struct FUN_00435e40_arr
{
    unsigned int Count();
    unsigned int* GetAt(unsigned int i);
    void RemoveAt(unsigned int i, unsigned int n);
};
struct FUN_00435e40_flt
{
    float* Get();
};
extern "C" char DAT_011cd580;
struct FUN_00435e40_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    FUN_00435e40_arr m_0c;
    void FUN_00435e40();
};
// Iterates m_0c, evaluates each entry's key and removes entries whose Eval() exceeds the float at DAT_011cd580.
// @fnv 0x00435e40
void FUN_00435e40_cls::FUN_00435e40()
{
    for (unsigned int i = 0; i < m_0c.Count(); i++)
    {
        FUN_00435e40_key key;
        key.m_v = *m_0c.GetAt(i);
        if (key.Eval() > *((FUN_00435e40_flt*)&DAT_011cd580)->Get())
        {
            m_0c.RemoveAt(i, 1);
            i--;
        }
    }
}

struct Vec3Sub
{
    unsigned int x;
    unsigned int y;
    unsigned int z;
    Vec3Sub();
};
struct SlottedSource
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
    virtual void v058();
    virtual void v059();
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
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
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
    virtual Vec3Sub* GetVariedData();
    Vec3Sub* GetFixedData();
};
struct RootCtorCls
{
    virtual void v0();
    RootCtorCls(unsigned int sizeInit);
    ~RootCtorCls();
};
struct FUN_00435fa0_cls : RootCtorCls
{
    virtual void v0();
    int unk04;
    int unk08;
    Vec3Sub m_kPointA;
    Vec3Sub m_kPointB;
    Vec3Sub m_iThirdValue;
    FUN_00435fa0_cls(SlottedSource* pSrc);
};

// @fnv 0x00435fa0
FUN_00435fa0_cls::FUN_00435fa0_cls(SlottedSource* apSource) : RootCtorCls(0x4c)
{
    if (apSource != 0)
    {
        m_kPointA = *apSource->GetFixedData();
        m_kPointB = *apSource->GetVariedData();
        m_iThirdValue = m_kPointB;
    }
}

struct Arg12
{
    int unk00;
    int unk04;
    int unk08;
    ~Arg12();
    void Release();
};

struct EhGuard
{
    ~EhGuard()
    {}
};

struct Base4f
{
    virtual void Tick();
    int unk04;
    int unk08;

    Base4f(int flags);
    ~Base4f();
};

struct Member12
{
    Member12();
    ~Member12();
    void Assign(const Arg12& value);
};

struct FUN_004360c0_cls : public Base4f
{
    virtual void Update();
    Member12 m_0c;

    FUN_004360c0_cls(Arg12 value);
};

// Initializes the base with flags 0x4f and assigns the given Arg12 value to m_0c.
// @fnv 0x004360c0
FUN_004360c0_cls::FUN_004360c0_cls(Arg12 value) : Base4f(0x4f), m_0c()
{
    m_0c.Assign(value);
}

struct Base_004361e0
{
    virtual void v00();
    int unk04;
    int unk08;

    Base_004361e0(int aValue);
    ~Base_004361e0();
};

struct Arg12_004361e0
{
    int unk00;
    int unk04;
    int unk08;

    ~Arg12_004361e0();
};

struct Member_004361e0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;

    Member_004361e0();
    ~Member_004361e0();
    void Add(Arg12_004361e0* pArg);
};

struct FUN_004361e0 : Base_004361e0
{
    Member_004361e0 m_0C;

    FUN_004361e0(Arg12_004361e0 aArg);
    virtual void v00();
};

// Initializes the base with 0x7d and adds the passed argument to the member at offset 0x0C.
// @fnv 0x004361e0
FUN_004361e0::FUN_004361e0(Arg12_004361e0 aArg) : Base_004361e0(0x7d)
{
    m_0C.Add(&aArg);
}

struct ParamBlock
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    void Release();
    ~ParamBlock();
};

class ChildMember
{
  public:
    ChildMember();
    ~ChildMember();
    void Attach(ParamBlock* p);
};

class NodeBase
{
  public:
    NodeBase(int kind);
    virtual void v00();
    ~NodeBase();
    unsigned int unk04;
    unsigned int unk08;
};

class FUN_00436660 : public NodeBase
{
  public:
    FUN_00436660(ParamBlock p);
    virtual void v00();
    ChildMember m_pChildAtom;
};

// Constructs a NodeBase of kind 0x87 and attaches the given ParamBlock to its ChildMember.
// @fnv 0x00436660
FUN_00436660::FUN_00436660(ParamBlock aParamBlock) : NodeBase(0x87)
{
    m_pChildAtom.Attach(&aParamBlock);
}

struct CloneCell;
struct CloneSound;

struct CloneChildCell
{
    virtual CloneCell* GetPersistentCell();
};

struct CloneCell
{
    bool FUN_00425fd0();
};

struct CloneExtraList
{
    void FUN_0041d390(CloneCell* pCell);
};

struct CloneSource
{
    char pad00[0x18];
    CloneChildCell kChildCell;

    bool FUN_005653d0();
    NiPoint3* FUN_00436aa0();
    const NiPoint3& FUN_00430830();
    CloneCell* FUN_008d6f30();
};

struct CloneProcess
{
    int FUN_0045cd60();
};

struct CloneRef
{
    virtual void vfunc000();
    virtual void vfunc004();
    virtual void vfunc008();
    virtual void vfunc00C();
    virtual void vfunc010();
    virtual void vfunc014();
    virtual void vfunc018();
    virtual void vfunc01C();
    virtual void vfunc020();
    virtual void vfunc024();
    virtual void vfunc028();
    virtual void vfunc02C();
    virtual void vfunc030();
    virtual void vfunc034();
    virtual void vfunc038();
    virtual void vfunc03C();
    virtual void vfunc040();
    virtual void vfunc044();
    virtual void vfunc048();
    virtual void vfunc04C();
    virtual void vfunc050();
    virtual void vfunc054();
    virtual void vfunc058();
    virtual void vfunc05C();
    virtual void vfunc060();
    virtual void vfunc064();
    virtual void vfunc068();
    virtual void vfunc06C();
    virtual void vfunc070();
    virtual void vfunc074();
    virtual void vfunc078();
    virtual void vfunc07C();
    virtual void vfunc080();
    virtual void vfunc084();
    virtual void vfunc088();
    virtual void vfunc08C();
    virtual void vfunc090();
    virtual void vfunc094();
    virtual void vfunc098();
    virtual void vfunc09C();
    virtual void vfunc0A0();
    virtual void vfunc0A4();
    virtual void vfunc0A8();
    virtual void vfunc0AC();
    virtual void vfunc0B0();
    virtual void vfunc0B4();
    virtual void vfunc0B8();
    virtual void vfunc0BC();
    virtual void vfunc0C0();
    virtual void vfunc0C4();
    virtual void vfunc0C8();
    virtual void vfunc0CC();
    virtual void vfunc0D0();
    virtual void vfunc0D4();
    virtual void vfunc0D8();
    virtual void vfunc0DC();
    virtual void vfunc0E0();
    virtual void vfunc0E4();
    virtual void vfunc0E8();
    virtual void vfunc0EC();
    virtual void vfunc0F0();
    virtual void vfunc0F4();
    virtual void vfunc0F8();
    virtual void vfunc0FC();
    virtual void vfunc100();
    virtual void vfunc104();
    virtual void vfunc108();
    virtual void vfunc10C();
    virtual void vfunc110();
    virtual void vfunc114();
    virtual void vfunc118();
    virtual void vfunc11C();
    virtual void vfunc120();
    virtual void vfunc124();
    virtual void vfunc128();
    virtual void vfunc12C();
    virtual void vfunc130();
    virtual void vfunc134();
    virtual void vfunc138();
    virtual void vfunc13C();
    virtual void vfunc140();
    virtual void vfunc144();
    virtual void vfunc148();
    virtual void vfunc14C();
    virtual void vfunc150();
    virtual void vfunc154();
    virtual void vfunc158();
    virtual void vfunc15C();
    virtual void vfunc160();
    virtual void vfunc164();
    virtual void vfunc168();
    virtual void vfunc16C();
    virtual void vfunc170();
    virtual void vfunc174();
    virtual void vfunc178();
    virtual void vfunc17C();
    virtual void vfunc180();
    virtual void vfunc184();
    virtual void vfunc188();
    virtual void vfunc18C();
    virtual void vfunc190();
    virtual void vfunc194();
    virtual void vfunc198();
    virtual void vfunc19C();
    virtual void vfunc1A0();
    virtual void vfunc1A4();
    virtual void vfunc1A8();
    virtual void vfunc1AC();
    virtual void vfunc1B0();
    virtual void vfunc1B4();
    virtual void vfunc1B8();
    virtual void vfunc1BC();
    virtual void vfunc1C0();
    virtual void vfunc1C4();
    virtual void vfunc1C8();
    virtual void vfunc1CC();
    virtual void vfunc1D0();
    virtual void vfunc1D4();
    virtual void vfunc1D8();
    virtual void vfunc1DC();
    virtual void vfunc1E0();
    virtual void vfunc1E4();
    virtual void vfunc1E8();
    virtual void vfunc1EC();
    virtual void vfunc1F0();
    virtual void vfunc1F4();
    virtual void vfunc1F8();
    virtual void vfunc1FC();
    virtual void vfunc200();
    virtual void vfunc204();
    virtual void vfunc208();
    virtual void vfunc20C();
    virtual void vfunc210();
    virtual void vfunc214();
    virtual void vfunc218();
    virtual void vfunc21C();
    virtual void vfunc220();
    virtual void vfunc224();
    virtual void SetParentCell(CloneCell* pCell);

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

    CloneRef();
    void FUN_00575690(void* pBase);
    void FUN_00565480(bool b);
    void FUN_00575830(const NiPoint3& kPos);
    void FUN_00575700(NiPoint3 kAngle);
    void FUN_004fbf00(CloneSource* pSource);
    void FUN_00898280(bool b);
    void FUN_00935ae0();
    CloneExtraList* FUN_005d43c0();
    CloneProcess* FUN_008d8520();
    void FUN_00407800(CloneProcess* pProcess);
};

struct CloneLowProcess : CloneProcess
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
    CloneLowProcess();
};
struct CloneMiddleLowProcess : CloneLowProcess
{
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    CloneMiddleLowProcess();
};
struct CloneMiddleHighProcess : CloneMiddleLowProcess
{
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
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    CloneMiddleHighProcess();
};
struct CloneHighProcess : CloneMiddleHighProcess
{
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
    int unk468;
    CloneHighProcess();
};

struct CloneProcessLists
{
    void FUN_0096d450(CloneRef* pRef, int iLevel, bool a, bool b, bool c);
};
extern CloneProcessLists DAT_011e0e80;
extern "C" CloneRef* g_thePlayer;

struct CloneFactory
{
    CloneRef* FUN_00436780(void* pBase, CloneSource* pSource);
};

// Allocates a CloneRef from pSource, copies its data, sets its parent cell, and attaches a process matching the player's process level.
// @fnv 0x00436780
CloneRef* CloneFactory::FUN_00436780(void* pBase, CloneSource* pSource)
{
    CloneRef* pRef = 0;
    if (pSource)
    {
        pRef = new CloneRef;
        pRef->FUN_00575690(pBase);
        pRef->FUN_00565480(pSource->FUN_005653d0());
        pRef->FUN_00575830(*pSource->FUN_00436aa0());
        pRef->FUN_00575700(pSource->FUN_00430830());
        pRef->FUN_004fbf00(pSource);
        pRef->FUN_00898280(true);
        pRef->FUN_00935ae0();
        if (pSource->FUN_008d6f30() && pSource->FUN_008d6f30()->FUN_00425fd0())
        {
            pRef->SetParentCell(pSource->FUN_008d6f30());
        }
        else
        {
            CloneCell* pCell = pSource->kChildCell.GetPersistentCell();
            if (pCell)
                pRef->FUN_005d43c0()->FUN_0041d390(pCell);
            else
                pRef->SetParentCell(pSource->FUN_008d6f30());
        }
        CloneProcess* pPlayerProcess = g_thePlayer->FUN_008d8520();
        if (pPlayerProcess)
        {
            CloneProcess* pProcess = 0;
            switch (pPlayerProcess->FUN_0045cd60())
            {
            case 3:
                pProcess = new CloneLowProcess;
                break;
            case 2:
                pProcess = new CloneMiddleLowProcess;
                break;
            case 1:
                pProcess = new CloneMiddleHighProcess;
                break;
            case 0:
                pProcess = new CloneHighProcess;
                break;
            }
            pRef->FUN_00407800(pProcess);
            DAT_011e0e80.FUN_0096d450(pRef, pProcess->FUN_0045cd60(), false, false, false);
        }
    }
    return pRef;
}

struct GcItem
{
    unsigned int Remove(unsigned int flag);
};

struct GcNode
{
    GcNode* Next();
    GcItem** GetItem();
    ~GcNode();
};

struct GcBase
{
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    virtual ~GcBase();
};

class FUN_00437d10 : public GcBase
{
  public:
    GcNode m_pChildAtom;
    virtual ~FUN_00437d10();
};

// @fnv 0x00437d10
FUN_00437d10::~FUN_00437d10()
{
    for (GcNode* pos = &m_pChildAtom; pos != 0; pos = pos->Next())
    {
        GcItem* val = *pos->GetItem();
        GcItem* cur = val;
        cur ? cur->Remove(1) : 0;
        *pos->GetItem() = 0;
    }
}

class FUN_00438610_cls
{
  public:
    unsigned int m_unk00;
    unsigned int* m_pData;
    unsigned int GetCount();
    void Reserve(unsigned int* slot, int count);
    int FUN_00438610(unsigned int* value);
};

// Appends the value to the end of the array, growing it by one, and returns the index where it was stored.
// @fnv 0x00438610
int FUN_00438610_cls::FUN_00438610(unsigned int* value)
{
    unsigned int index = GetCount();
    Reserve(m_pData + index, 1);
    m_pData[index] = *(volatile unsigned int*)value;
    return index;
}

class Base_438720
{
  public:
    virtual ~Base_438720();
    int unk04;
};

class FUN_00438720_cls : public Base_438720
{
  public:
    virtual ~FUN_00438720_cls();
    void FUN_00438af0();
};

// @fnv 0x00438720
FUN_00438720_cls::~FUN_00438720_cls()
{
    this->FUN_00438af0();
}

struct NiSpawnBase
{
    NiSpawnBase();
    ~NiSpawnBase()
    {}
    virtual void v00();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
};

NiSpawnBase::NiSpawnBase()
{}

class FUN_004391c0 : public NiSpawnBase
{
  public:
    FUN_004391c0();
    virtual void v00();
    void Init0(unsigned int a);
    void Init1(unsigned int a);
    void Init2(unsigned int a);
    void Init3(unsigned int a);
    void Init4(unsigned int a);
    void Init5(unsigned short a);
    void Init6(unsigned int a);
    unsigned short m_0018;
};

// @fnv 0x004391c0
FUN_004391c0::FUN_004391c0()
{
    m_0018 = 0;
    Init0(0);
    Init5(6);
    Init6(7);
    Init1(0);
    Init2(0);
    Init3(0);
}

// NiProperty's constructor: calls the primary base constructor, installs the
// class vtable pointer, then returns `this`.
struct NiPropertyBase
{
    NiPropertyBase();
    virtual void v00();
};

struct FUN_00439260 : public NiPropertyBase
{
    FUN_00439260();
};

// @fnv 0x00439260
FUN_00439260::FUN_00439260()
{}

namespace std {
double __cdecl abs(float);
}
struct Matrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
};
class TESObjectREFR
{
  public:
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
    virtual int v125();
    const NiPoint3& GetAngleOnReference() const;
    const NiPoint3& FUN_00569880();
    Matrix FUN_0056fa00();
};
class NiMemObject
{
  public:
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
struct Bound : NiMemObject
{
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual void b4();
    virtual void b5();
    virtual void b6();
    virtual void b7();
    virtual void b8();
    virtual void b9();
    virtual void b10();
    virtual void b11();
    virtual void b12();
    virtual void b13();
    virtual void b14();
    virtual void b15();
    virtual void b16();
    virtual void b17();
    virtual void b18();
    virtual void b19();
    virtual void b20();
    virtual void b21();
    virtual void b22();
    virtual void b23();
    virtual void b24();
    virtual void b25();
    virtual void b26();
    virtual void b27();
    virtual void b28();
    virtual void b29();
    virtual void b30();
    virtual void b31();
    virtual void b32();
    virtual void b33();
    virtual void b34();
    virtual void b35();
    virtual void b36();
    virtual void b37();
    virtual void b38();
    virtual void b39();
    virtual void b40();
    virtual void b41();
    virtual void b42();
    virtual void b43();
    virtual void b44();
    virtual void b45();
    virtual void SetScale(int);
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    void FUN_00439680(const NiPoint3&);
    void FUN_004396b0(const Matrix&);
};
struct FUN_00c37ec0 : Bound
{
    FUN_00c37ec0();
};
struct FUN_00c36310 : Bound
{
    int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44;
    FUN_00c36310();
};
class BSMultiBound : public NiMemObject
{
  public:
    int unk00, unk04, unk08, unk0c;
    BSMultiBound();
    void FUN_004addc0(Bound*);
};
// @fnv 0x00439490
BSMultiBound* __cdecl FUN_00439490(TESObjectREFR* reference)
{
    BSMultiBound* result = 0;
    if (reference)
    {
        Bound* pBound = 0;
        if (std::abs(reference->GetAngleOnReference().x) < 0.01f &&
            std::abs(reference->GetAngleOnReference().y) < 0.01f &&
            std::abs(reference->GetAngleOnReference().z) < 0.01f)
        {
            pBound = new FUN_00c37ec0;
            pBound->FUN_00439680(reference->FUN_00569880());
        }
        else
        {
            pBound = new FUN_00c36310;
            pBound->FUN_004396b0(reference->FUN_0056fa00());
            pBound->FUN_00439680(reference->FUN_00569880());
        }
        pBound->SetScale(reference->v125());
        result = new BSMultiBound;
        result->FUN_004addc0(pBound);
    }
    return result;
}

// @fnv 0x0043b290
int __cdecl FUN_0043b290()
{
    return (int)11u;
}

extern "C" long __stdcall InterlockedCompareExchange(long volatile* Destination, long Exchange, long Comparand);

typedef long(__stdcall* InterlockedCompareExchange_t)(long volatile*, long, long);

InterlockedCompareExchange_t DAT_00fdf1bc = InterlockedCompareExchange;

// @fnv 0x0043b460
void __cdecl FUN_0043b460(void* apDestination, void* pSrc, unsigned int n)
{
    DAT_00fdf1bc(static_cast<long volatile*>(apDestination), n, reinterpret_cast<long>(pSrc));
}

struct ObjB4037
{
    void* __thiscall FUN_007b3fa0(bool a);
};

struct Sub4037
{
    ObjB4037** __thiscall FUN_006815c0();
    void __thiscall FUN_00726c60(int* a);
    void __thiscall FUN_0063f7b0();
};

struct Host00437df0
{
    char m_auiShapeKeys[0x20];
    Sub4037 m_sub;
    void FUN_00437df0();
};

// Calls FUN_007b3fa0(true) on the object returned by m_sub.FUN_006815c0 if non-null, then FUN_00726c60(&d) and FUN_0063f7b0 on m_sub.
// @fnv 0x00437df0
void Host00437df0::FUN_00437df0()
{
    ObjB4037* a = *m_sub.FUN_006815c0();
    ObjB4037* b5;
    int d;
    b5 = a;
    (void)(b5 != 0 ? (void*)b5->FUN_007b3fa0(true) : 0);
    d = 0;
    m_sub.FUN_00726c60(&d);
    m_sub.FUN_0063f7b0();
}

class NiTMapBase438
{
  public:
    virtual ~NiTMapBase438();

    void RemoveAll();

    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
};

class FUN_004388a0 : public NiTMapBase438
{
  public:
    virtual ~FUN_004388a0();
};

// @fnv 0x004388a0
FUN_004388a0::~FUN_004388a0()
{
    RemoveAll();
}

struct AnimPoint3
{
    float x, y, z;
};
struct AnimMatrix3
{
    float m[9];
};

struct AnimMemObject
{
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem, unsigned int);
};

struct AnimSource
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void v0DC();
    virtual void v0E0();
    virtual void v0E4();
    virtual void v0E8();
    virtual void v0EC();
    virtual void v0F0();
    virtual void v0F4();
    virtual void v0F8();
    virtual void v0FC();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10C();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11C();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12C();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13C();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14C();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15C();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16C();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17C();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18C();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19C();
    virtual void v1A0();
    virtual void v1A4();
    virtual void v1A8();
    virtual void v1AC();
    virtual void v1B0();
    virtual void v1B4();
    virtual void v1B8();
    virtual void v1BC();
    virtual void v1C0();
    virtual void v1C4();
    virtual void v1C8();
    virtual void v1CC();
    virtual void v1D0();
    virtual void v1D4();
    virtual void v1D8();
    virtual void v1DC();
    virtual void v1E0();
    virtual void v1E4();
    virtual void v1E8();
    virtual void v1EC();
    virtual void v1F0();
    virtual void* GetSourceData();
    const AnimPoint3& GetAngleOnReference() const;
    const AnimPoint3& FUN_00569880();
    AnimMatrix3 FUN_0056fa00();
};

struct AnimInterpolator : AnimMemObject
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void SetSource(void* apData);
    void SetPosition(const AnimPoint3& kPos);
    void SetRotation(const AnimMatrix3& kRot);
};

struct AnimPointInterpolator : AnimInterpolator
{
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    AnimPointInterpolator();
};

struct AnimTransformInterpolator : AnimInterpolator
{
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    int unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40;
    int unk44;
    AnimTransformInterpolator();
};

struct AnimBlendData : AnimMemObject
{
    int unk00, unk04, unk08, unk0C;
    AnimBlendData();
    void SetInterpolator(AnimInterpolator* apInterp);
};

struct AnimController : AnimMemObject
{
    int unk00;
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    int unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40;
    int unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60;
    int unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80;
    int unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0;
    int unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC, unkC0;
    int unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC, unkE0;
    int unkE4, unkE8;
    AnimController();
    void SetData(AnimBlendData* apData);
};

// @fnv 0x004396e0
AnimController* __cdecl FUN_004396e0(AnimSource* apSource)
{
    AnimController* pController = 0;
    if (apSource)
    {
        AnimBlendData* pData;
        AnimInterpolator* pInterp = 0;
        if (std::abs(apSource->GetAngleOnReference().x) < 0.01f &&
            std::abs(apSource->GetAngleOnReference().y) < 0.01f && std::abs(apSource->GetAngleOnReference().z) < 0.01f)
        {
            pInterp = new AnimPointInterpolator;
            pInterp->SetPosition(apSource->FUN_00569880());
        }
        else
        {
            pInterp = new AnimTransformInterpolator;
            pInterp->SetRotation(apSource->FUN_0056fa00());
            pInterp->SetPosition(apSource->FUN_00569880());
        }
        pInterp->SetSource(apSource->GetSourceData());
        pController = new AnimController;
        pData = new AnimBlendData;
        pData->SetInterpolator(pInterp);
        pController->SetData(pData);
    }
    return pController;
}

struct RefCountedObject
{
    void IncRefCount();
    void DecRefCount();
};

struct FUN_0043b750
{
    void* m_pBuffer;
    NiPointer<RefCountedObject> m_pHeadNode;
    NiPointer<RefCountedObject> m_iSecondInteger;
    int m_unk0c;
    int m_unk10;

    ~FUN_0043b750();
};

// Frees m_pBuffer and clears the two reference-counted pointers.
// @fnv 0x0043b750
FUN_0043b750::~FUN_0043b750()
{
    void* pBuffer = m_pBuffer;
    operator delete(pBuffer);
    m_pHeadNode = 0;
    m_iSecondInteger = 0;
}

class NiFixedString
{
  public:
    NiFixedString(const char* pcString);
    ~NiFixedString();
    const char* m_kHandle;
};

class NameSource
{
  public:
    const char* FUN_0043b1b0();
};
class NamedObject
{
  public:
    NameSource* FUN_00413f40();
    void FUN_0043b9f0(const NiFixedString& kName);
};
class AttachedNode
{
};
class AttachTarget
{
  public:
    void FUN_0043baa0(AttachedNode* pkNode);
};

class NamedObjectPtr
{
  public:
    NamedObject* m_pObject;
    NamedObject* FUN_00559450() const;  // NiPointer<T>::operator T*
};
class AttachedNodePtr
{
  public:
    AttachedNode* m_pObject;
    AttachedNode* FUN_00559450() const;                   // NiPointer<T>::operator T*
    AttachedNodePtr& FUN_0066b0d0(AttachedNode* pkNode);  // NiPointer<T>::operator=
};

extern int DAT_011c7d74;
const char* __cdecl FUN_0043b9d0(const char* pcString, int iChar);
char* __cdecl FUN_00401460(char* pcDest, const char* pcSrc, int iCount);
AttachedNode* __cdecl FUN_005f3a20(NamedObject* pkObject, const char* pcName);
bool __cdecl FUN_0043b300(const void* pvKey, NamedObject* pkObject);

class NamedObjectLoader
{
  public:
    int unk00;
    NamedObjectPtr m_pReferencedObject;  // +0x04
    AttachedNodePtr m_spNode;            // +0x08

    AttachTarget* FUN_007fa950();
    void FUN_0043b7e0(const char* pcName);
};

// @fnv 0x0043b7e0
void NamedObjectLoader::FUN_0043b7e0(const char* pcName)
{
    if (!m_pReferencedObject.FUN_00559450())
        return;
    const char* pcPath = m_pReferencedObject.FUN_00559450()->FUN_00413f40()->FUN_0043b1b0();
    if (pcPath)
    {
        const char* pcSep = FUN_0043b9d0(pcPath, '_');
        if (pcSep)
        {
            char acBuffer[260];
            FUN_00401460(acBuffer, pcPath, pcSep - pcPath);
            acBuffer[pcSep - pcPath] = 0;
            m_pReferencedObject.FUN_00559450()->FUN_0043b9f0(NiFixedString(acBuffer));
        }
    }
    m_spNode.FUN_0066b0d0(FUN_005f3a20(m_pReferencedObject.FUN_00559450(), pcName));
    if (FUN_0043b300(&DAT_011c7d74, m_pReferencedObject.FUN_00559450()))
        FUN_007fa950()->FUN_0043baa0(m_spNode.FUN_00559450());
    m_pReferencedObject.FUN_00559450()->FUN_0043b9f0(NiFixedString(pcName));
}

class MenuTopic;

class ExtraBase437510
{
  public:
    virtual ~ExtraBase437510();
    unsigned char m_ucType;
    void* m_pkNext;
    ExtraBase437510(unsigned char type);
};

class FUN_00437510 : public ExtraBase437510
{
  public:
    BSSimpleList<BSSimpleList<MenuTopic*>*>* m_pTopics;
    FUN_00437510(BSSimpleList<MenuTopic*>* topics);
    ~FUN_00437510();
};

// Constructs an extra of type 0x73 holding a new list and adds the given topics list to it.
// @fnv 0x00437510
FUN_00437510::FUN_00437510(BSSimpleList<MenuTopic*>* topics) : ExtraBase437510(0x73)
{
    m_pTopics = new BSSimpleList<BSSimpleList<MenuTopic*>*>;
    m_pTopics->AddHead(topics);
}

struct FUN_00438df0
{
    void* vtbl;
    int unk4;
    int unk8;
    void __thiscall FUN_00438df0_copy(FUN_00438df0* src);
};

// @fnv 0x00438df0
void __thiscall FUN_00438df0::FUN_00438df0_copy(FUN_00438df0* apSource)
{
    ((void(__thiscall*)(void*, FUN_00438df0*))(*((void***)this))[2])(this, apSource);
    *(char*)((char*)this + 0xc) = *(char*)((char*)apSource + 0xc);
    *(unsigned short*)((unsigned char*)this + 0xe) = *(unsigned short*)((unsigned char*)apSource + 0xe);
    *(int*)((char*)this + 0x10) = *(int*)((char*)apSource + 0x10);
}

struct ListArg436
{
    void* m_pFirstNode;
    void* m_pTail;
    int m_uiItemCount;
    ~ListArg436();
};

class ExtraBase436
{
  public:
    ExtraBase436(unsigned char ucType);
    virtual ~ExtraBase436();
    unsigned char m_ucType;
    ExtraBase436* m_pkNext;
};

struct ExtraList436
{
    ExtraList436();
    ~ExtraList436();
    void Copy(const void* pkSource);
    int m_data;
};

class FUN_00436300 : public ExtraBase436
{
  public:
    FUN_00436300(ListArg436 kList);
    virtual ~FUN_00436300();
    ExtraList436 m_kList;
};

// Constructs an ExtraBase436 with type 0x8a and copies the supplied ListArg436 into m_kList.
// @fnv 0x00436300
FUN_00436300::FUN_00436300(ListArg436 kList) : ExtraBase436(0x8a)
{
    m_kList.Copy(&kList);
}

struct ExtraDataBase436540
{
    virtual void Slot00();
    unsigned int unk04;
    void* unk08;
    ExtraDataBase436540(unsigned char type);
    ~ExtraDataBase436540();
};

struct Value436540
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    Value436540();
    ~Value436540();
    Value436540& operator=(const Value436540& other);
};

struct FUN_00436540 : ExtraDataBase436540
{
    Value436540 m_uiFilterValue;
    FUN_00436540(Value436540 value);
};

// @fnv 0x00436540
FUN_00436540::FUN_00436540(Value436540 value) : ExtraDataBase436540(0x86)
{
    m_uiFilterValue = value;
}

struct Val42CE30
{
    void* p;
    Val42CE30();
};

struct C42CE30
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
    Val42CE30 m_kValue;

    Val42CE30 FUN_0042ce30();
};

// @fnv 0x0042ce30
Val42CE30 C42CE30::FUN_0042ce30()
{
    return m_kValue;
}

struct Guard430
{
    ~Guard430();
};
Guard430::~Guard430()
{}
struct FUN_00436b20_Ref
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
    virtual void v058();
    virtual void v059();
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
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
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
    virtual NiPoint3* v125();
};
namespace FNV {
struct FUN_00436b20 : BE
{
    Guard430 m_guard;
    unsigned int unk04;
    unsigned int unk08;
    CloneRef* unk0c;
    FUN_00436b20(unsigned int first, unsigned int second);
};
// Sets the vtable pointer, stores the result of FUN_00436780(first, second) in unk0c, then calls FUN_00575830 on it with second's v125() point.
// @fnv 0x00436b20
FUN_00436b20::FUN_00436b20(unsigned int first, unsigned int second) : BE(0x55)
{
    *(void**)this = (void*)&DAT_01015f24;
    unk0c = ((CloneFactory*)this)->FUN_00436780((void*)first, (CloneSource*)second);
    unk0c->FUN_00575830(*((FUN_00436b20_Ref*)second)->v125());
}
}

struct FUN_00438690
{
    ~FUN_00438690();
};
struct FUN_004389d0 : FUN_00438690
{
    virtual ~FUN_004389d0();
};
// Empty destructor for FUN_004389d0, inheriting from FUN_00438690.
// @fnv 0x004389d0
FUN_004389d0::~FUN_004389d0()
{}

namespace fnv_00436420 {
struct Arg
{
    int a;
    ~Arg();
};
struct Member
{
    int x, y, z;
    Member();
    ~Member();
    void Assign(const Arg& a);
};
struct Base
{
    Base(int n);
    ~Base();
    virtual void v0();
    int p, q;
};
struct FUN_00436420 : Base
{
    Member m;
    FUN_00436420(Arg a, int b, int c);
    virtual void v0();
};
// Constructs the object by calling the Base constructor with 0x83 and assigning the Arg parameter to the Member field m.
// @fnv 0x00436420
FUN_00436420::FUN_00436420(Arg a, int aiUnused1, int aiUnused2) : Base(0x83)
{
    m.Assign(a);
}
}  // namespace fnv_00436420
