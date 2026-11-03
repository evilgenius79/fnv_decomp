
// src/staging/blk_00560000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

struct FUN_00560cf0_Class
{
    void FUN_00560cf0(float value);
};

// @fnv 0x00560cf0
void FUN_00560cf0_Class::FUN_00560cf0(float value)
{
    *(float*)((char*)this + 8) = value;
}

struct BSFlags
{
    void Clear(unsigned int);
};

struct FormChangeRecord
{
    void FUN_005621f0(unsigned int);
};

// @fnv 0x005621f0
void FormChangeRecord::FUN_005621f0(unsigned int flags)
{
    ((BSFlags*)((char*)this + 0x17))->Clear(flags);
}

struct GlobalObject_00559cc0
{
    bool RemoveAt(unsigned int);
};
extern GlobalObject_00559cc0 g_011ca0e0;

// @fnv 0x00565670
void FUN_00565670(unsigned int index)
{
    g_011ca0e0.RemoveAt(index);
}

struct FUN_00566910_Class
{
    unsigned char FUN_00566910();
};

// @fnv 0x00566910
unsigned char FUN_00566910_Class::FUN_00566910()
{
    return ((unsigned char*)this)[0x68];
}

struct TaskQueueInterface
{
    void SetTaskFlagWord(bool, unsigned short);
    void FUN_00566930(bool flag);
};

// @fnv 0x00566930
void TaskQueueInterface::FUN_00566930(bool abSet)
{
    SetTaskFlagWord(abSet, 0x40);
}

struct ExtraDataList
{
    void* __thiscall FUN_0041db50(unsigned char);
};
struct XActor
{
    ExtraDataList* __thiscall GetExtra() const;
};
struct FUN_0056aa90
{
    void* __thiscall GetExtraData(unsigned char type);
};
// Returns the extra data of the given type by forwarding to the actor's extra data list lookup.
// @fnv 0x0056aa90
void* __thiscall FUN_0056aa90::GetExtraData(unsigned char type)
{
    return ((XActor*)this)->GetExtra()->FUN_0041db50(type);
}

struct ABD_005f92d0
{
    bool GetFlag(unsigned int) const;
    bool GetFlag8();
};

// @fnv 0x0056af00
bool ABD_005f92d0::GetFlag8()
{
    return GetFlag(8);
}

struct FUN_0056af20_Class
{
    bool __thiscall IsFlag2Set();
};

// @fnv 0x0056af20
bool __thiscall FUN_0056af20_Class::IsFlag2Set()
{
    return (signed char)((char*)this)[0x98] & 2;
}

struct FUN_0056d360_Class
{
    void FUN_0056d360(int a);
};

struct FUN_005407b0_Class
{
    void FUN_005407b0(int a);
};

// @fnv 0x0056d360
void FUN_0056d360_Class::FUN_0056d360(int aiValue)
{
    ((FUN_005407b0_Class*)((char*)this + 0xd4))->FUN_005407b0(aiValue);
}

extern "C" void* DAT_01030534;

struct FUN_0056d610_base
{
    virtual ~FUN_0056d610_base();
};

struct FUN_0056d5f0_class : FUN_0056d610_base
{
    void FUN_0056d610();
    void* FUN_0056d5f0();
};

// @fnv 0x0056d5f0
void* FUN_0056d5f0_class::FUN_0056d5f0()
{
    FUN_0056d610();
    *reinterpret_cast<void**>(this) = &DAT_01030534;
    return this;
}

extern int DAT_01030570;

struct FUN_0056d610Class
{
    void __thiscall FUN_0056d640(int);
    FUN_0056d610Class* __thiscall FUN_0056d610();
};

// Calls FUN_0056d640 with 0x1d, stores the address of DAT_01030570 at the start of this, and returns this.
// @fnv 0x0056d610
FUN_0056d610Class* __thiscall FUN_0056d610Class::FUN_0056d610()
{
    FUN_0056d640(0x1d);
    *reinterpret_cast<int**>(this) = &DAT_01030570;
    return this;
}

struct FUN_0056d6c0_class
{
    void __thiscall FUN_0056d6c0();
};

struct FUN_0056d710_class : public FUN_0056d6c0_class
{
    void __thiscall FUN_0056d710();
};

// @fnv 0x0056d710
void __thiscall FUN_0056d710_class::FUN_0056d710()
{
    FUN_0056d6c0();
}

struct FUN_0056d780_class
{
    void FUN_0056d7a0();
    void FUN_0056d780();
};
// @fnv 0x0056d780
void FUN_0056d780_class::FUN_0056d780()
{
    FUN_0056d7a0();
}

struct FUN_0057c530Class
{
    void FUN_0057c530();
};

struct FUN_0056d7a0Class
{
    void FUN_0056d7a0();
};

// @fnv 0x0056d7a0
void FUN_0056d7a0Class::FUN_0056d7a0()
{
    ((FUN_0057c530Class*)((char*)this + 0xc))->FUN_0057c530();
}

struct FUN_0056d7c0_cls
{
    void FUN_0056d710();
    void FUN_0056d7c0();
};

// @fnv 0x0056d7c0
void FUN_0056d7c0_cls::FUN_0056d7c0()
{
    FUN_0056d710();
}

struct hkRotation
{
    hkRotation();
};

struct B006815c0
{
    B006815c0();
};

struct FUN_0056ded0 : hkRotation
{
    char m_auiShapeKeys[0x30];
    B006815c0 m_kPointB;
    FUN_0056ded0();
};

// Constructs the object by running the base hkRotation constructor and default-constructing its embedded member.
// @fnv 0x0056ded0
FUN_0056ded0::FUN_0056ded0()
{}

struct FUN_0056df00_class
{
    void __thiscall FUN_00621990();
    FUN_0056df00_class* __thiscall FUN_0056df00();
};

// @fnv 0x0056df00
FUN_0056df00_class* __thiscall FUN_0056df00_class::FUN_0056df00()
{
    FUN_00621990();
    return this;
}

extern int DAT_01030dc0;
struct FUN_0056d610
{
    void __thiscall Init();
};
struct FUN_0056f690
{
    FUN_0056f690();
};
// @fnv 0x0056f690
FUN_0056f690::FUN_0056f690()
{
    ((FUN_0056d610*)this)->Init();
    *(int*)this = (int)&DAT_01030dc0;
}

struct FUN_00456630_helper
{
    bool FUN_00456630(unsigned int);
    bool FUN_00570ea0();
};

// @fnv 0x00570ea0
bool FUN_00456630_helper::FUN_00570ea0()
{
    return FUN_00456630(0x20000);
}

int __fastcall GetByteAtOffset38(void*);
struct FUN_00570ec0
{
    int __thiscall Get();
};
// @fnv 0x00570ec0
int __thiscall FUN_00570ec0::Get()
{
    return !(GetByteAtOffset38(this) - 1);
}

struct FUN_00570ee0_class
{
    void FUN_00570ea0();
    void FUN_00570ee0();
};

// @fnv 0x00570ee0
void FUN_00570ee0_class::FUN_00570ee0()
{
    FUN_00570ea0();
}

struct FUN_00570f40_Class
{
    bool FUN_00570f40() const;
};

// @fnv 0x00570f40
bool FUN_00570f40_Class::FUN_00570f40() const
{
    return (((*reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(this) + 0x244)) & 1) == 0) ? true
                                                                                                              : false;
}

struct BSOcclusionPlane;
struct FUN_006205e0_shell
{
    void __thiscall RemoveNode(void*);
};
struct FUN_00576830_shell
{
    void* FUN_00576830(BSOcclusionPlane*);
    void FUN_00576800(BSOcclusionPlane* p);
};
// Calls FUN_00576830 on the occlusion plane, then passes the result to RemoveNode on this object.
// @fnv 0x00576800
void FUN_00576830_shell::FUN_00576800(BSOcclusionPlane* apPlane)
{
    ((FUN_006205e0_shell*)this)->RemoveNode(FUN_00576830(apPlane));
}

struct V4_538f40
{
    void FUN_00538f40();
};
struct FUN_00577070_class
{
    void FUN_00577090();
    void FUN_00577070();
};
// @fnv 0x00577070
void FUN_00577070_class::FUN_00577070()
{
    FUN_00577090();
    ((V4_538f40*)((char*)this + 0x30))->FUN_00538f40();
}

struct FUN_004b4cf0_shell
{
    void* FUN_004b4cf0(unsigned int);
};
struct bhkCharacterController
{
    float& GetVectorElement(int);
};
struct FUN_005770e0_shell : FUN_004b4cf0_shell
{
    float& GetCharacterControllerValue(unsigned int a, unsigned int b);
};
// @fnv 0x005770e0
float& FUN_005770e0_shell::GetCharacterControllerValue(unsigned int a, unsigned int b)
{
    return ((bhkCharacterController*)FUN_004b4cf0(b))->GetVectorElement(a);
}

extern int DAT_01030f6c;
struct FUN_0057c470Class
{
    int m;
    void __thiscall InitArray(int);
    int* __thiscall FUN_0057c470(int);
};
// Calls InitArray with a, stores the address of DAT_01030f6c in m, and returns &m.
// @fnv 0x0057c470
int* __thiscall FUN_0057c470Class::FUN_0057c470(int a)
{
    InitArray(a);
    m = (int)&DAT_01030f6c;
    return &m;
}

struct WaterShaderSettings
{
    void Initialize();
};

struct FUN_0057e9a0
{
    FUN_0057e9a0();
};

// @fnv 0x0057e9a0
FUN_0057e9a0::FUN_0057e9a0()
{
    ((WaterShaderSettings*)this)->Initialize();
}

extern void* DAT_01030fd4;
void _NiFreeAlias(void*);

struct FUN_0057ca30_Class
{
    void NiTPointerMap_RemoveAll();
    void FUN_0057ca30();
};

// Sets the vtable pointer, clears the pointer map, and frees the object at offset 8.
// @fnv 0x0057ca30
void FUN_0057ca30_Class::FUN_0057ca30()
{
    *(void**)this = &DAT_01030fd4;
    NiTPointerMap_RemoveAll();
    _NiFreeAlias(*(void**)((char*)this + 8));
}

void __cdecl FUN_00538eb0(void*);

struct FUN_0056d6e0_Class
{
    void* FUN_0056d6e0(unsigned int flags);
};

// @fnv 0x0056d6e0
void* FUN_0056d6e0_Class::FUN_0056d6e0(unsigned int flags)
{
    reinterpret_cast<FUN_0056d7c0_cls*>(this)->FUN_0056d710();
    if (flags & 1)
        FUN_00538eb0(this);
    return this;
}

void __cdecl Deallocate(void*);
struct FUN_0057c370_Class
{
    void __thiscall FUN_0057c3a0();
    void* __thiscall FUN_0057c370(unsigned int flags);
};
// Calls FUN_0057c3a0, frees this when flags has bit 0 set, and returns this.
// @fnv 0x0057c370
void* __thiscall FUN_0057c370_Class::FUN_0057c370(unsigned int flags)
{
    FUN_0057c3a0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_0057c4a0_Class
{
    void __thiscall FUN_0057c780();
    void* __thiscall FUN_0057c4a0(unsigned int flags);
};
// Calls FUN_0057c780, then deletes this if flags has bit 0 set, and returns this.
// @fnv 0x0057c4a0
void* FUN_0057c4a0_Class::FUN_0057c4a0(unsigned int flags)
{
    FUN_0057c780();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_0057c500_Class
{
    void FUN_0057c9d0();
    void* __thiscall FUN_0057c500(unsigned int flags);
};
// @fnv 0x0057c500
void* FUN_0057c500_Class::FUN_0057c500(unsigned int flags)
{
    FUN_0057c9d0();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_0057ca60_Class
{
    void FUN_004b05b0();
    void* FUN_0057ca60(unsigned int flags);
};
// Calls FUN_004b05b0, deletes this when flags has bit 0 set, and returns this.
// @fnv 0x0057ca60
void* FUN_0057ca60_Class::FUN_0057ca60(unsigned int flags)
{
    FUN_004b05b0();
    if (flags & 1)
        operator delete(this);
    return this;
}

extern "C" void _Deallocate(void*);
struct FUN_0057c930_class
{
    void __thiscall FUN_0057c930();
};
struct FUN_0057ca90_Class
{
    void* __thiscall FUN_0057ca90(unsigned int flags);
};
// @fnv 0x0057ca90
void* FUN_0057ca90_Class::FUN_0057ca90(unsigned int flags)
{
    reinterpret_cast<FUN_0057c930_class*>(this)->FUN_0057c930();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_00560d10_shell
{
    float& __thiscall FUN_00560d10(unsigned int);
};
struct Modifier
{
    void SetValue(float);
};
struct PackageTargetRecord
{
    void SetTargAcquireRadius(float);
};
struct AlphaColor
{
    void FUN_0052ce20(float);
};
// Copies four float values from b into a via SetValue, FUN_00560cf0, SetTargAcquireRadius and FUN_0052ce20, then returns a.
// @fnv 0x00560c80
Modifier* CopyModifierSettings(Modifier* apModifier, FUN_00560d10_shell* apSource)
{
    apModifier->SetValue(apSource->FUN_00560d10(0));
    ((FUN_00560cf0_Class*)apModifier)->FUN_00560cf0(apSource->FUN_00560d10(1));
    ((PackageTargetRecord*)apModifier)->SetTargAcquireRadius(apSource->FUN_00560d10(2));
    ((AlphaColor*)apModifier)->FUN_0052ce20(apSource->FUN_00560d10(3));
    return apModifier;
}

struct hkVector4;
void __cdecl SetNiPoint3FromHkVector4(hkVector4 const&, void*);
struct FUN_00560d50_Struct
{
    void* __thiscall FUN_00560d80();
    void __thiscall FUN_00560d50(hkVector4 const&);
};
// @fnv 0x00560d50
void __thiscall FUN_00560d50_Struct::FUN_00560d50(hkVector4 const& aVector)
{
    SetNiPoint3FromHkVector4(aVector, FUN_00560d80());
}

struct TESObjectREFR
{
    void SetFlags(unsigned int);
};
struct ArrSI
{
    unsigned int GetFlags();
};
struct FUN_00564d20_Class
{
    void __thiscall SetFlag100000(unsigned char flag);
};
// @fnv 0x00564d20
void __thiscall FUN_00564d20_Class::SetFlag100000(unsigned char abSet)
{
    if (!((bool(__thiscall*)(void*))(*reinterpret_cast<void***>(this))[0x40])(this))
    {
        unsigned int flags = reinterpret_cast<ArrSI*>(this)->GetFlags();
        if (abSet)
            flags |= 0x100000;
        else
            flags &= 0xffefffff;
        reinterpret_cast<TESObjectREFR*>(this)->SetFlags(flags);
    }
}

namespace fnv_00564d80 {
struct ArrSI
{
    unsigned int GetFlags();
    bool FUN_00564d80();
};
// @fnv 0x00564d80
bool ArrSI::FUN_00564d80()
{
    unsigned int flags = GetFlags();
    if (flags & 0x40000)
        return true;
    else
        return false;
}
}  // namespace fnv_00564d80

struct BGSEncounterZone;
struct TESWorldSpace
{
    BGSEncounterZone* __thiscall FindEncounterZone() const;
};
struct FUN_00458400_cls
{
    unsigned int __thiscall GetFieldD0();
};
struct ActorS
{
    TESWorldSpace* __thiscall GetParentWorldSpace();
    BGSEncounterZone* __thiscall FUN_00567d90();
};
// @fnv 0x00567d90
BGSEncounterZone* __thiscall ActorS::FUN_00567d90()
{
    if (*(TESWorldSpace**)((char*)this + 0x40) != 0)
        return (*(TESWorldSpace**)((char*)this + 0x40))->FindEncounterZone();
    TESWorldSpace* ws = GetParentWorldSpace();
    if (ws != 0)
        return (BGSEncounterZone*)((FUN_00458400_cls*)ws)->GetFieldD0();
    return 0;
}

struct Data12_569620
{
    int a;
    int b;
    int c;
};
struct Param_569620
{
    virtual void d0() = 0;
    virtual void d1() = 0;
    virtual void d2() = 0;
    virtual void d3() = 0;
    virtual void d4() = 0;
    virtual void d5() = 0;
    virtual void d6() = 0;
    virtual void d7() = 0;
    virtual void d8() = 0;
    virtual void d9() = 0;
    virtual void d10() = 0;
    virtual void d11() = 0;
    virtual void d12() = 0;
    virtual void d13() = 0;
    virtual void d14() = 0;
    virtual void d15() = 0;
    virtual void d16() = 0;
    virtual void d17() = 0;
    virtual void d18() = 0;
    virtual void d19() = 0;
    virtual void d20() = 0;
    virtual void d21() = 0;
    virtual void d22() = 0;
    virtual void d23() = 0;
    virtual void d24() = 0;
    virtual void d25() = 0;
    virtual void d26() = 0;
    virtual void d27() = 0;
    virtual void d28() = 0;
    virtual void d29() = 0;
    virtual void d30() = 0;
    virtual void d31() = 0;
    virtual void d32() = 0;
    virtual void d33() = 0;
    virtual void d34() = 0;
    virtual void Use_8c(Data12_569620*) = 0;
};
struct S_00569620
{
    virtual void d0() = 0;
    virtual void d1() = 0;
    virtual void d2() = 0;
    virtual void d3() = 0;
    virtual void d4() = 0;
    virtual void d5() = 0;
    virtual void d6() = 0;
    virtual void d7() = 0;
    virtual void d8() = 0;
    virtual void d9() = 0;
    virtual void d10() = 0;
    virtual void d11() = 0;
    virtual void d12() = 0;
    virtual void d13() = 0;
    virtual void d14() = 0;
    virtual void d15() = 0;
    virtual void d16() = 0;
    virtual void d17() = 0;
    virtual void d18() = 0;
    virtual void d19() = 0;
    virtual void d20() = 0;
    virtual void d21() = 0;
    virtual void d22() = 0;
    virtual void d23() = 0;
    virtual void d24() = 0;
    virtual void d25() = 0;
    virtual void d26() = 0;
    virtual void d27() = 0;
    virtual void d28() = 0;
    virtual void d29() = 0;
    virtual void d30() = 0;
    virtual void d31() = 0;
    virtual void d32() = 0;
    virtual void d33() = 0;
    virtual void d34() = 0;
    virtual void d35() = 0;
    virtual void d36() = 0;
    virtual void d37() = 0;
    virtual void d38() = 0;
    virtual void d39() = 0;
    virtual void d40() = 0;
    virtual void d41() = 0;
    virtual void d42() = 0;
    virtual void d43() = 0;
    virtual void d44() = 0;
    virtual void d45() = 0;
    virtual void d46() = 0;
    virtual void d47() = 0;
    virtual void d48() = 0;
    virtual void d49() = 0;
    virtual void d50() = 0;
    virtual void d51() = 0;
    virtual void d52() = 0;
    virtual void d53() = 0;
    virtual void d54() = 0;
    virtual void d55() = 0;
    virtual void d56() = 0;
    virtual void d57() = 0;
    virtual void d58() = 0;
    virtual void d59() = 0;
    virtual void d60() = 0;
    virtual void d61() = 0;
    virtual void d62() = 0;
    virtual void d63() = 0;
    virtual void d64() = 0;
    virtual void d65() = 0;
    virtual void d66() = 0;
    virtual void d67() = 0;
    virtual void d68() = 0;
    virtual void d69() = 0;
    virtual void d70() = 0;
    virtual void d71() = 0;
    virtual void d72() = 0;
    virtual void d73() = 0;
    virtual void d74() = 0;
    virtual void d75() = 0;
    virtual void d76() = 0;
    virtual void d77() = 0;
    virtual void d78() = 0;
    virtual void d79() = 0;
    virtual void d80() = 0;
    virtual void d81() = 0;
    virtual void d82() = 0;
    virtual void d83() = 0;
    virtual void d84() = 0;
    virtual void d85() = 0;
    virtual void d86() = 0;
    virtual void d87() = 0;
    virtual void d88() = 0;
    virtual void d89() = 0;
    virtual void d90() = 0;
    virtual void d91() = 0;
    virtual void d92() = 0;
    virtual void d93() = 0;
    virtual void d94() = 0;
    virtual void d95() = 0;
    virtual void d96() = 0;
    virtual void d97() = 0;
    virtual void d98() = 0;
    virtual void d99() = 0;
    virtual void d100() = 0;
    virtual void d101() = 0;
    virtual void d102() = 0;
    virtual void d103() = 0;
    virtual void d104() = 0;
    virtual void d105() = 0;
    virtual void d106() = 0;
    virtual void d107() = 0;
    virtual void d108() = 0;
    virtual void d109() = 0;
    virtual void d110() = 0;
    virtual void d111() = 0;
    virtual void d112() = 0;
    virtual void d113() = 0;
    virtual void d114() = 0;
    virtual void d115() = 0;
    virtual void d116() = 0;
    virtual void d117() = 0;
    virtual void d118() = 0;
    virtual void d119() = 0;
    virtual void d120() = 0;
    virtual void d121() = 0;
    virtual void d122() = 0;
    virtual void d123() = 0;
    virtual void d124() = 0;
    virtual Data12_569620* Get1f4() = 0;
    void CopyDataAndUse(Param_569620* p);
};
// Copies the object returned by Get1f4() into a local and passes its address to p->Use_8c.
// @fnv 0x00569620
void S_00569620::CopyDataAndUse(Param_569620* apParam)
{
    Data12_569620 tmp = *Get1f4();
    apParam->Use_8c(&tmp);
}

extern "C" void* DAT_010302bc;
extern "C" int DAT_012681fc;
struct FUN_0056d410_Class
{
    void __thiscall FUN_0056d440();
    void* __thiscall FUN_0056d410();
};
// @fnv 0x0056d410
void* __thiscall FUN_0056d410_Class::FUN_0056d410()
{
    FUN_0056d440();
    *(void**)(this) = &DAT_010302bc;
    DAT_012681fc = DAT_012681fc + 1;
    return this;
}

struct FUN_004b5120
{
    unsigned char pad[0x10];
    FUN_004b5120();
};
extern int DAT_01030394;
extern int DAT_0126810c;
struct FUN_0056d440 : FUN_004b5120
{
    int m_10;
    FUN_0056d440();
};
// @fnv 0x0056d440
FUN_0056d440::FUN_0056d440()
{
    *(void**)this = (void*)&DAT_01030394;
    m_10 = 0;
    DAT_0126810c++;
}

struct FUN_0066d410_shell
{
    void FUN_0066d410();
};
void __cdecl operator delete(void* p, unsigned int flags);
struct FUN_0056d5c0_Class
{
    void* __thiscall FUN_0056d5c0(unsigned int flags);
};
// @fnv 0x0056d5c0
void* __thiscall FUN_0056d5c0_Class::FUN_0056d5c0(unsigned int flags)
{
    ((FUN_0066d410_shell*)this)->FUN_0066d410();
    if (flags & 1)
        operator delete(this, 0x14);
    return this;
}

struct FUN_0056d750_holder
{
    void* __thiscall FUN_0056d750(unsigned int);
};
// Calls FUN_0056d7c0 on this, then if bit 0 of flags is set calls FUN_00538eb0(this), and returns this.
// @fnv 0x0056d750
void* __thiscall FUN_0056d750_holder::FUN_0056d750(unsigned int flags)
{
    ((FUN_0056d7c0_cls*)this)->FUN_0056d7c0();
    if (flags & 1)
        FUN_00538eb0(this);
    return this;
}

struct ScriptLocalsX
{
    void* __thiscall GetLocalData();
};
struct ScriptX
{
    void __thiscall GetLocalData();
};
struct FUN_00c9e910_Class
{
    void __thiscall FUN_00c9e910(int a);
};
struct FUN_0056e050_Class
{
    void __thiscall FUN_0056e050(int a);
};
// @fnv 0x0056e050
void __thiscall FUN_0056e050_Class::FUN_0056e050(int a)
{
    void* p = ((ScriptLocalsX*)this)->GetLocalData();
    if (p)
    {
        ((ScriptX*)this)->GetLocalData();
        ((FUN_00c9e910_Class*)p)->FUN_00c9e910(a);
        ((ScriptX*)this)->GetLocalData();
    }
}

extern unsigned char DAT_011dcfa7;

// @fnv 0x00572220
void FUN_00572220(unsigned char value)
{
    DAT_011dcfa7 = value;
}

struct NiPoint3
{
    float x, y, z;
};
struct SetLoc_S
{
    void SetLocationOnReference(const NiPoint3&);
    void SetZ(float scale);
};
// Copies the NiPoint3 at offset 0x30, replaces its z with scale, and calls SetLocationOnReference with it.
// @fnv 0x00575b70
void __thiscall SetLoc_S::SetZ(float afZ)
{
    NiPoint3 p = *(const NiPoint3*)((const char*)this + 0x30);
    p.z = afZ;
    SetLocationOnReference(p);
}

struct FUN_00577110_shell
{
    void FUN_00577110();
};
struct FUN_00577090_shell : FUN_005770e0_shell
{
    void FUN_00577090();
};
// Calls FUN_00577110 on this, then sets the base-class elements at indices 0, 1 and 2 to 1.0f.
// @fnv 0x00577090
void FUN_00577090_shell::FUN_00577090()
{
    ((FUN_00577110_shell*)this)->FUN_00577110();
    float f = 1.0f;
    FUN_005770e0_shell::GetCharacterControllerValue(0, 0) = f;
    FUN_005770e0_shell::GetCharacterControllerValue(1, 1) = f;
    FUN_005770e0_shell::GetCharacterControllerValue(2, 2) = f;
}

struct TESSound
{
    unsigned int __thiscall Deallocate();
};
struct Holder0057c400
{
    void* __thiscall FUN_0057c400(unsigned int);
};
// Walks the list starting at this, calling Deallocate on each node, and returns the first node whose result equals id, or null.
// @fnv 0x0057c400
void* __thiscall Holder0057c400::FUN_0057c400(unsigned int id)
{
    TESSound* cur = (TESSound*)this;
    while (cur)
    {
        if (cur->Deallocate() == id)
            break;
        cur = (TESSound*)((BSSimpleList<void*>*)cur)->GetNext();
    }
    return cur;
}

struct FUN_00559b40
{
    FUN_00559b40(int);
};
extern int DAT_01030f4c;
struct FUN_0057c440 : FUN_00559b40
{
    FUN_0057c440(int);
};
// @fnv 0x0057c440
FUN_0057c440::FUN_0057c440(int aiValue) : FUN_00559b40(aiValue)
{
    *(int*)this = (int)&DAT_01030f4c;
}

struct Node
{
    int a;
    int b;
};
struct ScriptPool
{
    Node* __thiscall FUN_0049fa80();
};
struct Helper62d0
{
    void* operator=(const void*);
};
struct FUN_004ed8c0_shell
{
    void FUN_00559a70(Node*);
};
struct FUN_0057c590_Class : public FUN_004ed8c0_shell
{
    void __thiscall FUN_0057c590(Node* p);
};
// Gets a node from the script pool, stores p into the node's field at offset 8, then passes the node to FUN_00559a70.
// @fnv 0x0057c590
void __thiscall FUN_0057c590_Class::FUN_0057c590(Node* apNode)
{
    Node* pNode = ((ScriptPool*)this)->FUN_0049fa80();
    ((Helper62d0*)((char*)pNode + 8))->operator=(apNode);
    FUN_00559a70(pNode);
}

struct NiPointerListStandIn
{
    void* FUN_0057cbe0(void*&);
};
struct NiPointerStandIn
{
    bool operator==(void*) const;
};
struct FUN_0057c6a0Class
{
    void* FUN_00559450();
    void* FUN_0057c6a0(void* a, void* b);
};
// Walks the list starting at b (or the default from FUN_00559450) and returns the first element equal to a, or 0 if none matches.
// @fnv 0x0057c6a0
void* FUN_0057c6a0Class::FUN_0057c6a0(void* apTarget, void* apStart)
{
    if (!apStart)
        apStart = FUN_00559450();
    while (apStart)
    {
        void* c = apStart;
        if (((NiPointerStandIn*)apTarget)->operator==(((NiPointerListStandIn*)this)->FUN_0057cbe0(apStart)))
            return c;
    }
    return 0;
}

extern int DAT_01030fac;
struct Base5700
{
    void __thiscall FUN_0057cb70(unsigned int, unsigned int);
};
struct FUN_0057c700
{
    FUN_0057c700(unsigned int, unsigned int);
};
// @fnv 0x0057c700
FUN_0057c700::FUN_0057c700(unsigned int a, unsigned int b)
{
    ((Base5700*)this)->FUN_0057cb70(a, b);
    *(void**)this = (void*)&DAT_01030fac;
}

void* __cdecl _NiMalloc(unsigned int size);
void* __cdecl _memset(void* dst, unsigned int value, unsigned int count);
extern int DAT_01030fb4;
struct FUN_0057c7e0_Class
{
    int* __thiscall InitArray(int count);
};
// @fnv 0x0057c7e0
int* FUN_0057c7e0_Class::InitArray(int count)
{
    unsigned int uiByteCount;
    *(int**)((char*)this + 0) = &DAT_01030fb4;
    *(int*)((char*)this + 4) = count;
    *(int*)((char*)this + 0xc) = 0;
    uiByteCount = *(unsigned int*)((char*)this + 4) << 2;
    *(int*)((char*)this + 8) = (int)_NiMalloc(uiByteCount);
    _memset(*(void**)((char*)this + 8), 0, *(unsigned int*)((char*)this + 4) << 2);
    return (int*)this;
}

extern int DAT_01030fb4;
void _NiFree(void*);
// @fnv 0x0057c930
void __thiscall FUN_0057c930_class::FUN_0057c930()
{
    *(int*)this = (int)&DAT_01030fb4;
    ((FUN_0057ca30_Class*)this)->NiTPointerMap_RemoveAll();
    _NiFree(((void**)this)[2]);
}

void* __cdecl NiMalloc(unsigned int);
void* __cdecl memset(void*, int, unsigned int);
struct FUN_0057c960
{
    void* vtable;
    int count;
    void* data;
    int pad;
    FUN_0057c960(int c);
};
// Sets the vtable, stores the count, allocates count*4 bytes with NiMalloc and zeroes them with memset.
// @fnv 0x0057c960
FUN_0057c960::FUN_0057c960(int aiCount)
{
    vtable = &DAT_01030fd4;
    count = aiCount;
    pad = 0;
    unsigned int size = count * 4;
    data = NiMalloc(size);
    memset(data, 0, count * 4);
}

struct FUN_0057cac0_Holder : FUN_0057ca30_Class
{
    void* __thiscall DestroyIfFlagged(unsigned int);
};
// Calls the base constructor, then deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x0057cac0
void* __thiscall FUN_0057cac0_Holder::DestroyIfFlagged(unsigned int flags)
{
    FUN_0057ca30();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct H_A100
{
    void* GetSizeMasked();
};
void __fastcall FUN_00626870(void*);
struct FUN_0057cc10_Class
{
    void __thiscall FUN_0057cc10(void* a, void* b);
};
struct FUN_0057cb20_Class
{
    void* m_iWordAt00;
    int m_iWordAt04;
    unsigned int m_8;
    void __thiscall FUN_0057cb20(int a);
};
// @fnv 0x0057cb20
void __thiscall FUN_0057cb20_Class::FUN_0057cb20(int pTarget)
{
    FUN_00626870(this);
    if (!(m_8 & 0x80000000))
    {
        ((FUN_0057cc10_Class*)pTarget)->FUN_0057cc10(m_iWordAt00, ((H_A100*)this)->GetSizeMasked());
    }
    m_iWordAt00 = 0;
    m_8 = 0x80000000;
}

struct FUN_0057cc10_Cls
{
    virtual void F0()
    {}
    virtual void F1()
    {}
    virtual void F2()
    {}
    virtual void F3()
    {}
    virtual void F4(int, int)
    {}
    void __thiscall FUN_0057cc10(int, int);
};
// Calls F4 with a and b shifted left by 3, using a local x initialized to 8.
// @fnv 0x0057cc10
void __thiscall FUN_0057cc10_Cls::FUN_0057cc10(int a, int b)
{
    int x = 8;
    F4(a, b << 3);
}

extern float runtimeInitializationFloat2400;
extern float DAT_011f4ae0[];
// Maps an input float to a 512-entry table index using 512.0 divided by runtimeInitializationFloat2400, then returns the table value.
// @fnv 0x0057e960
float __cdecl FUN_0057e960(float a)
{
    int v = (int)((512.0 / runtimeInitializationFloat2400) * a) & 0x1ff;
    return DAT_011f4ae0[v];
    return 0.0f;
}

struct FUN_0042dec0_shell
{
    void RemoveExtraType43();
    void FUN_0042e730();
};
struct FUN_0042e2a0_shell
{
    void* GetExtraNavMeshPortal();
};
struct FUN_004534f0_shell
{
    void FUN_004534f0(unsigned int);
};
struct FUN_00568f30_shell
{
    void FUN_00568f30();
};
// @fnv 0x00568f30
void FUN_00568f30_shell::FUN_00568f30()
{
    ((FUN_0042dec0_shell*)((XActor*)this)->GetExtra())->RemoveExtraType43();
    void* portal = ((FUN_0042e2a0_shell*)((XActor*)this)->GetExtra())->GetExtraNavMeshPortal();
    if (portal)
    {
        FUN_004534f0_shell* form = *(FUN_004534f0_shell**)((char*)portal + 0xc);
        if (form)
            form->FUN_004534f0((unsigned int)this);
        ((FUN_0042dec0_shell*)((XActor*)this)->GetExtra())->FUN_0042e730();
    }
    (*(void(__thiscall**)(void*, unsigned int))(*(void***)this + 0x13))(this, 0x20000);
}

int DAT_0101fc8c;
struct ActorCombatGroup;
struct NiTMallocInterface_CombatGroup
{
    static ActorCombatGroup** __cdecl Allocate(unsigned short size);
};
struct FUN_0057cb70_Class
{
    int* vtable;
    ActorCombatGroup** data;
    unsigned short m_iElementCount;
    unsigned short m_auiShapeKeys;
    unsigned short m_uiItemCount;
    unsigned short m_maxSize;
    FUN_0057cb70_Class(unsigned short size, unsigned short maxSize);
};
// @fnv 0x0057cb70
FUN_0057cb70_Class::FUN_0057cb70_Class(unsigned short size, unsigned short maxSize)
{
    vtable = &DAT_0101fc8c;
    m_iElementCount = size;
    m_maxSize = maxSize;
    m_auiShapeKeys = 0;
    m_uiItemCount = 0;
    if (m_iElementCount > 0)
        data = NiTMallocInterface_CombatGroup::Allocate(m_iElementCount);
    else
        data = 0;
}

struct RefH
{
    bool GetDisabled();
    void FUN_00484af0(bool);
};
struct InventoryChanges
{
    bool CreateForReference();
};
struct Fn56ac90
{
    BSSimpleList<BGSPerk*>* FUN_0056ac90();
};
struct FUN_0056ac00Class : RefH
{
    void FUN_0056ac00();
};

// @fnv 0x0056ac00
void FUN_0056ac00Class::FUN_0056ac00()
{
    BSSimpleList<BGSPerk*>* list = ((Fn56ac90*)this)->FUN_0056ac90();
    while (list)
    {
        RefH* item = (RefH*)list->GetItem();
        if (item)
        {
            bool disabled = GetDisabled();
            if (((InventoryChanges*)item)->CreateForReference())
                disabled = !disabled;
            if (item->GetDisabled() != disabled)
            {
                item->FUN_00484af0(disabled);
                ((FUN_0056ac00Class*)item)->FUN_0056ac00();
            }
        }
        list = list->GetNext();
    }
}

struct NiRTTI_S
{
    int unk00;
};
extern NiRTTI_S DAT_012681c0;

struct WorldObj_S
{
    int unk00;
};

struct RigidBody_S
{
    bool FUN_005609b0();
    int FUN_00517630();
    bool IsNonZero(int flags);
};

RigidBody_S* NiDynCast_S(const NiRTTI_S* rtti, WorldObj_S* obj);

struct Counters_S
{
    unsigned char flags;
    int count04;
    int count08;
    int count0C;
    int unk10;
    int unk14;
    void* target;
};

struct Arg2_S
{
    int unk00;
    int unk04;
    int unk08;
    Counters_S* counters;
};

struct CollObj_S
{
    WorldObj_S* FUN_006fa820();
};

// Casts the object's world object to a rigid body and updates the counters' flags and counts based on its state.
// @fnv 0x00563120
void FUN_00563120(CollObj_S* pCollObj, Arg2_S* arg)
{
    Counters_S* counters3 = arg->counters;
    WorldObj_S* world = pCollObj->FUN_006fa820();
    if (world)
    {
        RigidBody_S* body = NiDynCast_S(&DAT_012681c0, world);
        if (body)
        {
            if (pCollObj == counters3->target)
                counters3->flags |= 2;
            if (body->FUN_005609b0())
                counters3->count04++;
            else
                counters3->count08++;
            if (body->FUN_00517630() == 4)
            {
                if (!body->IsNonZero(0x200))
                    counters3->count0C++;
            }
        }
    }
}

namespace fnv_00563220 {
struct Pt_S
{
    float x, y, z;
    Pt_S();
};
struct hkVector4
{
    float x, y, z, w;
    hkVector4();
};
struct bhkWorldObject;
struct NiRTTI;
extern NiRTTI DAT_012681c0;
struct bhkRigidBody
{
    void FUN_00560bc0(NiPoint3&);
    void FUN_00560c20(hkVector4&);
    bool FUN_005609b0();
    int FUN_00517630();
    bool IsNonZero(int);
    void FUN_00560d50(NiPoint3&);
    void FUN_00560de0(NiPoint3&);
};
struct bhkCollisionObject
{
    bhkWorldObject* FUN_006fa820();
};
bhkRigidBody* FUN_00653270(const NiRTTI*, bhkWorldObject*);
struct BGSSaveFormBuffer
{
    void SaveData(void*, unsigned int, int);
};
struct SaveState
{
    unsigned char moving;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    bhkCollisionObject* object;
    BGSSaveFormBuffer* world;
};
struct SaveRequest
{
    int unk00;
    int unk04;
    int unk08;
    SaveState* buffer;
};
// @fnv 0x00563220
void FUN_00563220(bhkCollisionObject* apCollisionObject, SaveRequest* request)
{
    SaveState* buffer = request->buffer;
    BGSSaveFormBuffer* world = buffer->world;
    bhkWorldObject* state = apCollisionObject->FUN_006fa820();
    if (state)
    {
        bhkRigidBody* body = FUN_00653270(&DAT_012681c0, state);
        if (body)
        {
            if (apCollisionObject == buffer->object)
            {
            }
            else
            {
                Pt_S position;
                hkVector4 rotation;
                body->FUN_00560bc0(reinterpret_cast<NiPoint3&>(position));
                body->FUN_00560c20(rotation);
                world->SaveData(&position, 12, 0);
                world->SaveData(&rotation, 16, 0);
            }
            unsigned char moving = 0;
            bool flags = body->FUN_005609b0();
            if (buffer->moving & 4)
            {
                if (flags)
                    moving |= 1;
                if (body->FUN_00517630() == 4 && !body->IsNonZero(0x200))
                    moving |= 2;
                world->SaveData(&moving, 1, 0);
            }
            if (flags)
            {
                Pt_S angular;
                Pt_S linear;
                body->FUN_00560d50(reinterpret_cast<NiPoint3&>(angular));
                body->FUN_00560de0(reinterpret_cast<NiPoint3&>(linear));
                world->SaveData(&angular, 12, 0);
                world->SaveData(&linear, 12, 0);
            }
        }
    }
}
}  // namespace fnv_00563220

struct Vec3_563380
{
    float x, y, z;
    Vec3_563380()
    {}
};
struct Mat3_563380
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
};
struct Quat_563380
{
    float w, x, y, z;
    Quat_563380()
    {}
    void FromRotationMatrix(const Mat3_563380& m);
};
struct RTTI_563380
{
    int unk00;
};
extern RTTI_563380 g_rtti_bhkRigidBody_563380;

struct bhkWorldObject_563380
{
    int unk00;
};
struct bhkRigidBody_563380
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
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void SetMotionType(int);
    void SetRotation(const Quat_563380& q);
    void SetPosition(const Vec3_563380& p);
    void SetLinearVelocity(const Vec3_563380& v);
    void SetAngularVelocity(const Vec3_563380& v);
    void Activate(bool b);
};
bhkRigidBody_563380* NiDynamicCast_563380(const RTTI_563380* rtti, bhkWorldObject_563380* obj);

struct bhkCollisionObject_563380
{
    bhkWorldObject_563380* GetWorldObject();
    void SetFlag(bool b);
};
struct LoadBuffer_563380
{
    void Read(void* dst, unsigned int size);
};
struct RefObj_563380
{
    virtual void r00();
    virtual void r04();
    virtual void r08();
    virtual void r0c();
    virtual void r10();
    virtual void r14();
    virtual void r18();
    virtual void r1c();
    virtual void r20();
    virtual void r24();
    virtual void r28();
    virtual void r2c();
    virtual void r30();
    virtual void r34();
    virtual void r38();
    virtual void r3c();
    virtual void r40();
    virtual void r44();
    virtual void r48();
    virtual void r4c();
    virtual void r50();
    virtual void r54();
    virtual void r58();
    virtual void r5c();
    virtual void r60();
    virtual void r64();
    virtual void r68();
    virtual void r6c();
    virtual void r70();
    virtual void r74();
    virtual void r78();
    virtual void r7c();
    virtual void r80();
    virtual void r84();
    virtual void r88();
    virtual void r8c();
    virtual void r90();
    virtual void r94();
    virtual void r98();
    virtual void r9c();
    virtual void ra0();
    virtual void ra4();
    virtual void ra8();
    virtual void rac();
    virtual void rb0();
    virtual void rb4();
    virtual void rb8();
    virtual void rbc();
    virtual void rc0();
    virtual void rc4();
    virtual void rc8();
    virtual void rcc();
    virtual void rd0();
    virtual void rd4();
    virtual void rd8();
    virtual void rdc();
    virtual void re0();
    virtual void re4();
    virtual void re8();
    virtual void rec();
    virtual void rf0();
    virtual void rf4();
    virtual void rf8();
    virtual void rfc();
    virtual void r100();
    virtual void r104();
    virtual void r108();
    virtual void r10c();
    virtual void r110();
    virtual void r114();
    virtual void r118();
    virtual void r11c();
    virtual void r120();
    virtual void r124();
    virtual void r128();
    virtual void r12c();
    virtual void r130();
    virtual void r134();
    virtual void r138();
    virtual void r13c();
    virtual void r140();
    virtual void r144();
    virtual void r148();
    virtual void r14c();
    virtual void r150();
    virtual void r154();
    virtual void r158();
    virtual void r15c();
    virtual void r160();
    virtual void r164();
    virtual void r168();
    virtual void r16c();
    virtual void r170();
    virtual void r174();
    virtual void r178();
    virtual void r17c();
    virtual void r180();
    virtual void r184();
    virtual void r188();
    virtual void r18c();
    virtual void r190();
    virtual void r194();
    virtual void r198();
    virtual void r19c();
    virtual void r1a0();
    virtual void r1a4();
    virtual void r1a8();
    virtual void r1ac();
    virtual void r1b0();
    virtual void r1b4();
    virtual void r1b8();
    virtual void r1bc();
    virtual void r1c0();
    virtual void r1c4();
    virtual void r1c8();
    virtual void r1cc();
    virtual void r1d0();
    virtual void r1d4();
    virtual void r1d8();
    virtual void r1dc();
    virtual void r1e0();
    virtual void r1e4();
    virtual void r1e8();
    virtual void r1ec();
    virtual void r1f0();
    virtual Vec3_563380* GetPos();
    Mat3_563380 GetRotationMatrix();
};
struct Data_563380
{
    unsigned char flags;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    int unk04;
    int unk08;
    int unk0c;
    RefObj_563380* ref;
    int unk14;
    int unk18;
    LoadBuffer_563380* buffer;
};
struct Param_563380
{
    int unk00;
    int unk04;
    int unk08;
    Data_563380* data;
};

// @fnv 0x00563380
void __cdecl FUN_00563380(bhkCollisionObject_563380* collObj, Param_563380* param)
{
    Data_563380* data7 = param->data;
    LoadBuffer_563380* buffer2 = data7->buffer;
    bhkWorldObject_563380* worldObj2 = collObj->GetWorldObject();
    collObj->SetFlag(false);
    if (worldObj2)
    {
        bhkRigidBody_563380* aBody = NiDynamicCast_563380(&g_rtti_bhkRigidBody_563380, worldObj2);
        if (aBody)
        {
            Vec3_563380 pos4;
            Quat_563380 rot2;
            if (data7->flags & 2)
            {
                data7->flags &= ~2;
                pos4 = *data7->ref->GetPos();
                rot2.FromRotationMatrix(data7->ref->GetRotationMatrix());
            }
            else
            {
                buffer2->Read(&pos4, 0xc);
                buffer2->Read(&rot2, 0x10);
            }
            aBody->SetRotation(rot2);
            aBody->SetPosition(pos4);
            bool setVel4 = false;
            if (data7->flags & 1)
                setVel4 = true;
            if (data7->flags & 4)
            {
                unsigned char extra5 = 0;
                buffer2->Read(&extra5, 1);
                if (extra5 & 1)
                    setVel4 = true;
                if (extra5 & 2)
                    aBody->SetMotionType(4);
            }
            if (setVel4)
            {
                Vec3_563380 linVel;
                Vec3_563380 angularVelocity;
                buffer2->Read(&linVel, 0xc);
                buffer2->Read(&angularVelocity, 0xc);
                aBody->SetLinearVelocity(linVel);
                aBody->SetAngularVelocity(angularVelocity);
                aBody->Activate(true);
            }
        }
    }
}

struct NiRTTI
{
};
struct NiObject
{
};
struct NiFixedString
{
    operator const char*() const;
};
struct NiControllerSequence
{
    int GetState();
    NiFixedString& GetName();
};
struct NiControllerManager : NiObject
{
    bool FUN_004f05a0();
    unsigned int GetSequenceCount();
    NiControllerSequence* GetSequenceAt(unsigned int idx);
};
struct LoadedModel
{
    NiObject* GetObject3D();
};
struct ModelHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    NiPointer<LoadedModel> m_pRenderedNodeEntry;
};
struct HandleData
{
    char* FUN_004228f0();
};
extern NiRTTI DAT_011f36ac;
extern const char* DAT_011977d8;
extern const char* DAT_01197820;
NiObject* NiDynamicCast(const NiRTTI* rtti, NiObject* obj);
int __cdecl _stricmp(const char*, const char*);

struct Ref563530
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
    ModelHolder* m_kModelObjectsItem;
    HandleData* FUN_005d43c0();
    bool FUN_00563530();
};

// @fnv 0x00563530
bool Ref563530::FUN_00563530()
{
    if (FUN_005d43c0()->FUN_004228f0())
        return true;
    if (!m_kModelObjectsItem)
        return false;
    if (!(LoadedModel*)m_kModelObjectsItem->m_pRenderedNodeEntry)
        return false;
    NiControllerManager* pManager =
        (NiControllerManager*)NiDynamicCast(&DAT_011f36ac, ((LoadedModel*)m_kModelObjectsItem->m_pRenderedNodeEntry)->GetObject3D());
    if (!pManager || !pManager->FUN_004f05a0())
        return false;
    unsigned int ItemUpdateArray = pManager->GetSequenceCount();
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
    {
        NiControllerSequence* pForwardSequence = pManager->GetSequenceAt(i);
        if (pForwardSequence->GetState())
        {
            if (_stricmp(pForwardSequence->GetName(), DAT_011977d8) && _stricmp(pForwardSequence->GetName(), DAT_01197820))
                return true;
        }
    }
    return false;
}

struct SceneObject : FUN_0056af20_Class
{
    int FUN_00401170();
};
struct FUN_0056ae60_Class
{
    bool FUN_0056ae60();
    bool FUN_0056af40();
    SceneObject* FUN_007af430();
};
// Returns false if FUN_0056af40 is true; otherwise switches on the type from FUN_007af430 and calls GetFlag8 or IsFlag2Set on the object.
// @fnv 0x0056ae60
bool FUN_0056ae60_Class::FUN_0056ae60()
{
    bool result = false;
    if (!FUN_0056af40())
    {
        if (FUN_007af430())
        {
            switch (FUN_007af430()->FUN_00401170())
            {
            case 0x2a:
            case 0x2b: {
                SceneObject* object = FUN_007af430();
                if (object)
                {
                    result = reinterpret_cast<ABD_005f92d0*>(reinterpret_cast<char*>(object) + 0x30)->GetFlag8();
                }
            }
            break;
            case 0x1b: {
                SceneObject* object = FUN_007af430();
                if (object)
                {
                    result = object->IsFlag2Set();
                }
            }
            break;
            }
        }
    }
    return result;
}

struct Obj8
{
    void Init();
    unsigned int m_u00;
    unsigned int m_u04;
};

struct VisitorB
{
    void Visit(unsigned int index, Obj8* obj);
};

struct FetcherC
{
    void* Fetch(unsigned int index);
};

void FUN_00553fc0_sink(void* value, Obj8* obj);

// Initializes an Obj8, then for indices 0..2 calls Visit on the visitor and passes Fetch's result with the object to a sink; returns the fetcher.
// @fnv 0x0056dff0
void* VisitAndFetchThree(FetcherC* pFetcher, VisitorB* pVisitor)
{
    char guard[4];
    Obj8 obj;
    obj.Init();
    for (unsigned int i = 0; i < 3; i++)
    {
        pVisitor->Visit(i, &obj);
        FUN_00553fc0_sink(pFetcher->Fetch(i), &obj);
    }
    return pFetcher;
}

class B572270Object
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual void vfunc0E();
    virtual void vfunc0F();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    virtual void vfunc19();
    virtual void vfunc1A();
    virtual void vfunc1B();
    virtual void vfunc1C();
    virtual void vfunc1D();
    virtual void vfunc1E();
    virtual void vfunc1F();
    virtual void vfunc20();
    virtual void vfunc21();
    virtual void vfunc22();
    virtual void vfunc23();
    virtual void vfunc24();
    virtual void vfunc25();
    virtual void vfunc26();
    virtual void vfunc27();
    virtual void vfunc28();
    virtual void vfunc29();
    virtual void vfunc2A();
    virtual void vfunc2B();
    virtual void vfunc2C();
    virtual void vfunc2D();
    virtual void vfunc2E();
    virtual void vfunc2F();
    virtual void vfunc30();
    virtual void SetFlagA(int iValue);
    virtual void SetFlagB(int iValue);
    virtual void vfunc33();
    virtual void vfunc34();
    virtual void vfunc35();
    virtual void vfunc36();
    virtual void vfunc37();
    virtual void vfunc38();
    virtual void vfunc39();
    virtual void vfunc3A();
    virtual void vfunc3B();
    virtual void vfunc3C();
    virtual void vfunc3D();
    virtual void vfunc3E();
    virtual void vfunc3F();
    virtual void vfunc40();
    virtual void vfunc41();
    virtual void vfunc42();
    virtual void vfunc43();
    virtual void vfunc44();
    virtual void vfunc45();
    virtual void vfunc46();
    virtual void vfunc47();
    virtual void vfunc48();
    virtual void vfunc49();
    virtual void vfunc4A();
    virtual void vfunc4B();
    virtual void vfunc4C();
    virtual void vfunc4D();
    virtual void vfunc4E();
    virtual void vfunc4F();
    virtual void vfunc50();
    virtual void vfunc51();
    virtual void vfunc52();
    virtual void vfunc53();
    virtual void vfunc54();
    virtual void vfunc55();
    virtual void vfunc56();
    virtual void vfunc57();
    virtual void vfunc58();
    virtual void vfunc59();
    virtual void vfunc5A();
    virtual void vfunc5B();
    virtual void vfunc5C();
    virtual void vfunc5D();
    virtual void vfunc5E();
    virtual void vfunc5F();
    virtual void vfunc60();
    virtual void vfunc61();
    virtual void vfunc62();
    virtual void vfunc63();
    virtual void vfunc64();
    virtual void vfunc65();
    virtual void vfunc66();
    virtual void vfunc67();
    virtual void vfunc68();
    virtual void vfunc69();
    virtual void vfunc6A();
    virtual void vfunc6B();
    virtual void vfunc6C();
    virtual void vfunc6D();
    virtual void vfunc6E();
    virtual void vfunc6F();
    virtual void vfunc70();
    virtual void vfunc71();
    virtual void vfunc72();
    virtual void Reset(int iA, int iB);

    void FUN_00572270();
};

// Sets flag A and flag B to 1, then calls Reset with 0, 0.
// @fnv 0x00572270
void B572270Object::FUN_00572270()
{
    SetFlagA(1);
    SetFlagB(1);
    Reset(0, 0);
}

// Stand-in base with a trivial destructor, 0x14 bytes.
struct FUN_0057c3a0_BaseA
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

// Stand-in base with a non-trivial destructor, 4 bytes.
struct FUN_0057c3a0_BaseB
{
    int unk00;
    ~FUN_0057c3a0_BaseB();
};

struct FUN_0057c3a0_cls : FUN_0057c3a0_BaseA, FUN_0057c3a0_BaseB
{
    FUN_0057c3a0_BaseB m_kMemberDescriptor;
    ~FUN_0057c3a0_cls();
};

// Destructor for the class; destroys its base subobjects and the embedded base member.
// @fnv 0x0057c3a0
FUN_0057c3a0_cls::~FUN_0057c3a0_cls()
{}

struct DtorBase_57c930 : FUN_0057c930_class
{
    virtual __forceinline ~DtorBase_57c930()
    {
        FUN_0057c930();
    }
};
struct FUN_0057c8d0 : DtorBase_57c930
{
    virtual ~FUN_0057c8d0();
    void __thiscall FUN_00438af0();
};
// Destructor that calls FUN_00438af0 before the base destructor runs.
// @fnv 0x0057c8d0
FUN_0057c8d0::~FUN_0057c8d0()
{
    FUN_00438af0();
}

struct Base_57c9d0
{
    virtual void v00();
    int unk04;
    int unk08;
    int unk0C;

    ~Base_57c9d0();
};

class FUN_0057c9d0_cls : public Base_57c9d0
{
  public:
    virtual ~FUN_0057c9d0_cls();
    void Body();
};

// @fnv 0x0057c9d0
FUN_0057c9d0_cls::~FUN_0057c9d0_cls()
{
    Body();
}

struct FlagCls
{
    bool m_kPointB;
    int Get(void* owner);
};
struct SinkCls
{
    void Put(int v);
};
struct FUN_0057caf0_cls
{
    void FUN_0057caf0();
};
// @fnv 0x0057caf0
void FUN_0057caf0_cls::FUN_0057caf0()
{
    FlagCls flag = {};
    reinterpret_cast<SinkCls*>(this)->Put(flag.Get(this));
}

struct PSPoint3
{
    float x;
    float y;
    float z;

    PSPoint3();
};

struct PSVector4
{
    float x;
    float y;
    float z;
    float w;

    PSVector4();
};

struct PSFixedString
{
    operator const char*() const;
};

struct PSRTTI
{
    int unk00;
};

struct PSAVObject
{
    PSFixedString& GetName();
};

struct PSRigidBody
{
    bool IsActive();
    void GetPosition(PSPoint3& arPos);
    void GetRotation(PSVector4& arRot);
    void GetLinearVelocityVector(PSPoint3& arVel);
    void GetAngularVelocity(PSPoint3& arVel);
};

struct PSCollisionObject
{
    int unk00;
};

struct PSRef
{
    PSAVObject* Get3D();
    PSCollisionObject* GetCollisionObject();
};

struct PSForm
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
    virtual bool IsActorBase();
};

struct PSSaveInfo
{
    unsigned char m_ucEntryType;
    unsigned char pad01[3];
    int unk04;
    PSForm* pBaseForm;
    int unk0C;
    PSRef* pRef;
};

struct PSSaveContext
{
    int unk00;
    int unk04;
    int unk08;
    PSSaveInfo* pInfo;
};

struct PSSaveLoadGame
{
    void Write(void* apData, int aiSize);
};

extern PSSaveLoadGame* g_pPSSaveLoadGame;
extern PSRTTI g_kPSRTTI_Excluded;
extern PSRTTI g_kPSRTTI_RigidBody;

int __cdecl PSStricmp(const char* apString1, const char* apString2);
bool __cdecl PSIsKindOf(const PSRTTI* apRTTI, PSAVObject* apObject);
PSRigidBody* __cdecl PSDynamicCast(const PSRTTI* apRTTI, PSCollisionObject* apObject);

// @fnv 0x00560a10
void __cdecl FUN_00560a10(PSRef* apRef, PSSaveContext* apContext)
{
    PSSaveInfo* pInfo = apContext->pInfo;
    PSAVObject* p3D = apRef->Get3D();
    if (apRef != pInfo->pRef && p3D && (const char*)p3D->GetName() && !PSStricmp(p3D->GetName(), "Arrow"))
        return;
    if (pInfo->pBaseForm->IsActorBase() && PSIsKindOf(&g_kPSRTTI_Excluded, p3D))
        return;

    PSCollisionObject* pCollision_ = apRef->GetCollisionObject();
    if (pCollision_)
    {
        PSRigidBody* pBody6 = PSDynamicCast(&g_kPSRTTI_RigidBody, pCollision_);
        if (pBody6)
        {

            if (apRef == pInfo->pRef)
            {
            }
            else
            {
                PSPoint3 kPosition3;
                PSVector4 kRotationBasis;
                pBody6->GetPosition(kPosition3);
                pBody6->GetRotation(kRotationBasis);
                g_pPSSaveLoadGame->Write(&kPosition3, 0xc);
                g_pPSSaveLoadGame->Write(&kRotationBasis, 0x10);
            }

            bool bActive2 = pBody6->IsActive();
            if (pInfo->m_ucEntryType & 4)
                g_pPSSaveLoadGame->Write(&bActive2, 1);
            if (bActive2)
            {
                PSPoint3 kLinearVelocity5;
                PSPoint3 kAngularVelocity4;
                pBody6->GetLinearVelocityVector(kLinearVelocity5);
                pBody6->GetAngularVelocity(kAngularVelocity4);
                g_pPSSaveLoadGame->Write(&kLinearVelocity5, 0xc);
                g_pPSSaveLoadGame->Write(&kAngularVelocity4, 0xc);
            }
        }
    }
}

class B5695A0Bound;

class B5695A0AVObject
{
  public:
    int IsVisualObject();
    const B5695A0Bound& GetBoundingVolume() const;
};

class B5695A0Culler
{
  public:
    virtual void VFunc00();
    virtual void VFunc04();
    virtual void VFunc08();
    virtual void VFunc0C();
    virtual void VFunc10();
    virtual void VFunc14();
    virtual void VFunc18();
    virtual void VFunc1C();
    virtual void VFunc20();
    virtual void VFunc24();
    virtual void VFunc28();
    virtual void VFunc2C();
    virtual void VFunc30();
    virtual void VFunc34();
    virtual void VFunc38();
    virtual void VFunc3C();
    virtual void VFunc40();
    virtual void VFunc44();
    virtual void VFunc48();
    virtual void VFunc4C();
    virtual void VFunc50();
    virtual void VFunc54();
    virtual void VFunc58();
    virtual void VFunc5C();
    virtual void VFunc60();
    virtual void VFunc64();
    virtual void VFunc68();
    virtual void VFunc6C();
    virtual void VFunc70();
    virtual void VFunc74();
    virtual void VFunc78();
    virtual void VFunc7C();
    virtual void VFunc80();
    virtual void VFunc84();
    virtual void VFunc88();
    virtual void VFunc8C();
    virtual void VFunc90();
    virtual void VFunc94();
    virtual int TestBound(const B5695A0Bound& kBound);
};

class B5695A0Camera
{
  public:
    B5695A0Culler* GetCuller();
};

class B5695A0Ref
{
  public:
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
    virtual void VFunc0DC();
    virtual void VFunc0E0();
    virtual void VFunc0E4();
    virtual void VFunc0E8();
    virtual void VFunc0EC();
    virtual void VFunc0F0();
    virtual void VFunc0F4();
    virtual void VFunc0F8();
    virtual void VFunc0FC();
    virtual void VFunc100();
    virtual void VFunc104();
    virtual void VFunc108();
    virtual void VFunc10C();
    virtual void VFunc110();
    virtual void VFunc114();
    virtual void VFunc118();
    virtual void VFunc11C();
    virtual void VFunc120();
    virtual void VFunc124();
    virtual void VFunc128();
    virtual void VFunc12C();
    virtual void VFunc130();
    virtual void VFunc134();
    virtual void VFunc138();
    virtual void VFunc13C();
    virtual void VFunc140();
    virtual void VFunc144();
    virtual void VFunc148();
    virtual void VFunc14C();
    virtual void VFunc150();
    virtual void VFunc154();
    virtual void VFunc158();
    virtual void VFunc15C();
    virtual void VFunc160();
    virtual void VFunc164();
    virtual void VFunc168();
    virtual void VFunc16C();
    virtual void VFunc170();
    virtual void VFunc174();
    virtual void VFunc178();
    virtual void VFunc17C();
    virtual void VFunc180();
    virtual void VFunc184();
    virtual void VFunc188();
    virtual void VFunc18C();
    virtual void VFunc190();
    virtual void VFunc194();
    virtual void VFunc198();
    virtual void VFunc19C();
    virtual void VFunc1A0();
    virtual void VFunc1A4();
    virtual void VFunc1A8();
    virtual void VFunc1AC();
    virtual void VFunc1B0();
    virtual void VFunc1B4();
    virtual void VFunc1B8();
    virtual void VFunc1BC();
    virtual void VFunc1C0();
    virtual void VFunc1C4();
    virtual void VFunc1C8();
    virtual void VFunc1CC();
    virtual B5695A0AVObject* Get3D();

    bool FUN_005695a0(B5695A0Camera* pkCamera);
};

// @fnv 0x005695a0
bool B5695A0Ref::FUN_005695a0(B5695A0Camera* pkCamera)
{
    B5695A0AVObject* pk3D = Get3D();
    if (!pk3D->IsVisualObject())
        return false;
    bool bVisible9 = pk3D ? pkCamera->GetCuller()->TestBound(pk3D->GetBoundingVolume()) == 2 : false;
    return bVisible9;
}

class NiAVObject;
struct SoundData57
{
    unsigned int frequency, flags, minDistance, maxDistance, staticAttenuation;
    unsigned int startTime, endTime, attenuation, priority;
};
struct Sound57
{
    SoundData57 CopyBig();
    unsigned int FUN_0084e3a0();
};
struct SoundRecord57
{
    Sound57* GetField54();
};
struct SoundLookup57
{
    SoundRecord57* FUN_004617e0(const char*);
};
extern SoundLookup57* g_dataHandler;
struct BSSoundHandleEx
{
    unsigned int id, state, flags;
    ~BSSoundHandleEx();
    void FUN_00418900(const BSSoundHandleEx&);
    void FUN_00ad88f0();
    void FUN_00ad8d10();
    void SetNiNode(NiAVObject*);
    bool SetPos(float, float, float);
    bool Play(bool);
};
struct Audio57
{
    BSSoundHandleEx FUN_00ad73b0(unsigned int, unsigned int);
};
Audio57* FUN_00453a70();
unsigned int GetFlagMask(unsigned int);
struct FUN_004f91b0
{
    unsigned int vtable, refCount, name;
    BSSoundHandleEx handle;
    FUN_004f91b0();
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    void IncRefCount();
    void DecRefCount();
};
class NiAVObject
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual NiNode* GetNode();
    bool FUN_00456610();
    const char* FUN_009ee040();
    FUN_004f91b0* FUN_00a5bdd0(const NiFixedString&);
    bool DeleteExtraDataByKey(const NiFixedString&);
    bool SetExtraDataName(FUN_004f91b0*);
    const NiPoint3& FUN_0045bb80();
};
class NiNode : public NiAVObject
{
  public:
    unsigned int FUN_0043b480();
    NiAVObject* FUN_0043b4a0(unsigned int);
};
extern NiRTTI g_01202de8;
bool FUN_0043b300(const NiRTTI*, NiAVObject*);
const NiFixedString& FUN_004f9230();
struct SceneSounds57
{
    void FUN_0057a410(NiAVObject*, bool);
};
// @fnv 0x0057a410
void SceneSounds57::FUN_0057a410(NiAVObject* object, bool stop)
{
    if (!object)
        return;
    if (object->FUN_00456610())
        stop = true;
    if (FUN_0043b300(&g_01202de8, object))
    {
        NiAVObject* soundObject = object;
        SoundRecord57* record = g_dataHandler->FUN_004617e0(soundObject->FUN_009ee040());
        if (record && record->GetField54())
        {
            NiPointer<FUN_004f91b0> extra(object->FUN_00a5bdd0(FUN_004f9230()));
            if (stop)
            {
                if (extra.operator->())
                {
                    object->DeleteExtraDataByKey(FUN_004f9230());
                    extra->handle.FUN_00ad88f0();
                    extra->handle.FUN_00ad8d10();
                }
            }
            else if (!extra.operator->())
            {
                extra = new FUN_004f91b0;
                NiPoint3 position;
                unsigned int flags = GetFlagMask(record->GetField54()->CopyBig().flags)
                                         ? (GetFlagMask(record->GetField54()->CopyBig().flags) | 2)
                                         : 0x102;
                extra->handle.FUN_00418900(FUN_00453a70()->FUN_00ad73b0(record->GetField54()->FUN_0084e3a0(), flags));
                extra->handle.SetNiNode(object);
                position = object->FUN_0045bb80();
                extra->handle.SetPos(position.x, position.y, position.z);
                extra->handle.Play(false);
                object->SetExtraDataName(extra.operator->());
            }
        }
    }
    NiNode* node = object->GetNode();
    if (node)
    {
        for (unsigned int i = 0; i < node->FUN_0043b480(); ++i)
        {
            NiAVObject* child = node->FUN_0043b4a0(i);
            if (child)
                FUN_0057a410(child, stop);
        }
    }
}

struct SmartPointer
{
    void* object;
    SmartPointer(const SmartPointer&);
    ~SmartPointer();
};
struct PointerList : FUN_0057c6a0Class
{
    SmartPointer RemovePos(void*& position);
    SmartPointer FUN_0057c5d0(const SmartPointer& key);
};
// @fnv 0x0057c5d0
SmartPointer PointerList::FUN_0057c5d0(const SmartPointer& key)
{
    void* position = FUN_0057c6a0((void*)&key, 0);
    return position ? RemovePos(position) : key;
}

struct FUN_00483710
{
    ~FUN_00483710();
};
struct FUN_0057c530 : FUN_00483710
{
    void FUN_0057caf0();
    ~FUN_0057c530();
};
// @fnv 0x0057c530
FUN_0057c530::~FUN_0057c530()
{
    FUN_0057caf0();
}

class QueueValue
{
  public:
    QueueValue(const QueueValue& src);
    ~QueueValue();
    void* m_pObject;
};

class QueueItem
{
  public:
    QueueItem* m_pkNext;
    QueueItem* m_pkPrev;
    QueueValue m_element;
};

class FUN_0057cc40_cls
{
  public:
    QueueItem* m_pkHead;
    QueueItem* m_pkTail;
    unsigned int m_uiCount;
    void DeleteItem(QueueItem* item);
    QueueValue PopBack();
};

// Removes the tail item from the queue, copies its element, deletes the item, decrements the count and returns the copied element.
// @fnv 0x0057cc40
QueueValue FUN_0057cc40_cls::PopBack()
{
    QueueItem* item = m_pkTail;
    m_pkTail = m_pkTail->m_pkPrev;
    if (m_pkTail != 0)
    {
        m_pkTail->m_pkNext = 0;
    }
    else
    {
        m_pkHead = 0;
    }
    QueueValue element(item->m_element);
    DeleteItem(item);
    m_uiCount = m_uiCount - 1;
    return element;
}

class Extra56B0
{
  public:
    void FUN_00421750(int iA, int iB);
};

class TESForm56B0
{
  public:
    virtual void vf000();
    virtual void vf004();
    virtual void vf008();
    virtual void vf00C();
    virtual void vf010();
    virtual void vf014();
    virtual void vf018();
    virtual void vf01C();
    virtual void vf020();
    virtual void vf024();
    virtual void vf028();
    virtual void vf02C();
    virtual void vf030();
    virtual void vf034();
    virtual void vf038();
    virtual void vf03C();
    virtual void vf040();
    virtual void vf044();
    virtual void vf048();
    virtual void vf04C();
    virtual void vf050();
    virtual void vf054();
    virtual void vf058();
    virtual void vf05C();
    virtual void vf060();
    virtual void vf064();
    virtual void vf068();
    virtual void vf06C();
    virtual void vf070();
    virtual void vf074();
    virtual void vf078();
    virtual void vf07C();
    virtual void vf080();
    virtual void vf084();
    virtual void vf088();
    virtual void vf08C();
    virtual void vf090();
    virtual void vf094();
    virtual void vf098();
    virtual void vf09C();
    virtual void vf0A0();
    virtual void vf0A4();
    virtual void vf0A8();
    virtual void vf0AC();
    virtual void vf0B0();
    virtual void vf0B4();
    virtual void vf0B8();
    virtual void vf0BC();
    virtual void vf0C0();
    virtual void vf0C4();
    virtual void vf0C8();
    virtual void vf0CC();
    virtual void vf0D0();
    virtual void vf0D4();
    virtual void vf0D8();
    virtual void vf0DC();
    virtual void vf0E0();
    virtual void vf0E4();
    virtual void vf0E8();
    virtual void vf0EC();
    virtual void vf0F0();
    virtual void vf0F4();
    virtual bool vf0F8();
};

class RefObj
{
  public:
    void* _FNV_GetObjectReference();
};

class Ref56B0
{
  public:
    virtual void vf000();
    virtual void vf004();
    virtual void vf008();
    virtual void vf00C();
    virtual void vf010();
    virtual void vf014();
    virtual void vf018();
    virtual void vf01C();
    virtual void vf020();
    virtual void vf024();
    virtual void vf028();
    virtual void vf02C();
    virtual void vf030();
    virtual void vf034();
    virtual void vf038();
    virtual void vf03C();
    virtual void vf040();
    virtual void vf044();
    virtual void vf048();
    virtual void vf04C(unsigned int uiFlags);

    TESForm56B0* GetBase()
    {
        return static_cast<TESForm56B0*>(reinterpret_cast<RefObj*>(this)->_FNV_GetObjectReference());
    }
    void FUN_00484b90(unsigned int uiFlags);
    Extra56B0* FUN_005d43c0();
    void FUN_0056b020(int iA, int iB);
};

// @fnv 0x0056b020
void Ref56B0::FUN_0056b020(int iA, int iB)
{
    if (GetBase() && GetBase()->vf0F8())
    {
        if (iA && iB)
        {
            FUN_00484b90(0x40000);
        }
        else
        {
            vf04C(0x40000);
        }
        FUN_005d43c0()->FUN_00421750(iA, iB);
    }
}

struct PointerMapBase57c780
{
    virtual void Slot00();
    ~PointerMapBase57c780();
};

struct FUN_0057c780 : PointerMapBase57c780
{
    void FUN_00438af0();
    ~FUN_0057c780();
};

// Destructor that calls FUN_00438af0.
// @fnv 0x0057c780
FUN_0057c780::~FUN_0057c780()
{
    FUN_00438af0();
}

struct Scene
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
    virtual bool vf();
};

struct Sub
{
    bool FUN_004216d0();
};

struct Thing
{
    Scene* FUN_007af430();
    Sub* FUN_005d43c0();
    bool FUN_0056afc0();
};

// Returns true if the scene pointer is valid, its vf() check passes, and the Sub object's FUN_004216d0() returns true.
// @fnv 0x0056afc0
bool Thing::FUN_0056afc0()
{
    bool result = false;
    if (FUN_007af430() != 0 && FUN_007af430()->vf())
    {
        result = FUN_005d43c0()->FUN_004216d0();
    }
    return result;
}

#include <xmmintrin.h>
extern float DAT_010c71b0;

struct Base_56d250
{
    void* FUN_006815c0();
};
void* Base_56d250::FUN_006815c0()
{
    return this;
}

struct C_56d250 : Base_56d250
{
    __m128 m_vComponents;
    void FUN_0056d250();
};
// Copies the 16 bytes at DAT_010c71b0 to the address returned by FUN_006815c0().
// @fnv 0x0056d250
void C_56d250::FUN_0056d250()
{
    *(__m128*)FUN_006815c0() = *(const __m128*)&DAT_010c71b0;
}

// @fnv 0x00560d10
float& FUN_00560d10_shell::FUN_00560d10(unsigned int i)
{
    return reinterpret_cast<bhkCharacterController*>(this)->GetVectorElement(i);
}

struct FUN_00576870_class
{
    void* __thiscall FUN_00576870(void*);
};
// Calls FUN_00576870 on the object at offset 4 when that pointer is non-null, passing p, and returns the result or 0.
// @fnv 0x00576830
void* FUN_00576830_shell::FUN_00576830(BSOcclusionPlane* apOcclusionPlane)
{
    return *(FUN_00576870_class**)((char*)this + 4)
               ? (*(FUN_00576870_class**)((char*)this + 4))->FUN_00576870(apOcclusionPlane)
               : 0;
}

struct FUN_0057c4d0
{
    virtual ~FUN_0057c4d0();
};
typedef FUN_0057c4d0 FUN_0056aac0_map;
// @fnv 0x0057c4d0
FUN_0057c4d0::~FUN_0057c4d0()
{}
