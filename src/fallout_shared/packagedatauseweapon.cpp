// fallout_shared/packagedatauseweapon.cpp: TESUseWeaponPackageData, UseWeaponActorPackageData, DelStandIn, UseWeaponLoader and more (16 functions)

#include "packagedatauseweapon_decls.h"

// @fnv 0x0067d1c0
void TESUseWeaponPackageData::InitItem(TESForm* item)
{
    LocationDescriptor* package = reinterpret_cast<LocationDescriptor*>(item);
    bool initializeTarget;
    {
        LocationDescriptor* location = reinterpret_cast<LocationDescriptor*>(package->SetLocRef());
        initializeTarget = true;
        if (!m_pUseTarget && location && reinterpret_cast<TESObjectREFR*>(location)->GetBoundingRadius() == 0)
        {
            TESObjectREFR* reference = location->GetLocationReference();
            if (reference)
            {
                TESBoundObject* object = reference->GetObjectReference();
                if (object == DAT_011ca244 || object == DAT_011ca248)
                {
                    ExtraDataList* extra = reference->GetExtraData();
                    if (extra)
                    {
                        TESObjectREFR* target = extra->GetTargetObjectReference();
                        if (target)
                        {
                            m_pUseTarget = new PackageTargetRecord;
                            m_pUseTarget->SetTargetKind(PACK_TARG_REFERENCE);
                            m_pUseTarget->SetTargetObjectReference(target);
                            initializeTarget = false;
                        }
                    }
                }
            }
        }
        if (m_pUseTarget && initializeTarget)
            m_pUseTarget->InitItem(item);
        unsigned int weaponID = reinterpret_cast<unsigned int>(pWeapon);
        pWeapon = dynamic_cast<TESObjectWEAP*>(TESForm::GetFormByID(weaponID));
    }
}

// Clears the stored reference if it equals the passed reference.
// @fnv 0x0067d9e0
void UseWeaponActorPackageData::SetReferenceTarget(TESObjectREFR* reference)
{
    m_pUseTarget = m_pUseTarget == reference ? 0 : m_pUseTarget;
}

void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* DestroyIfFlagged(unsigned int flags);
};
// Runs the destructor on this, then frees this via Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0067cb40
void* DelStandIn::DestroyIfFlagged(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}

struct FUN_00670b30
{
    void* __vecDelDtor(unsigned int);
};

struct Date
{
    void* __vecDelDtor(unsigned int);
};

struct FUN_0067ad70_cls
{
    virtual ~FUN_0067ad70_cls();
};

struct FUN_0067ccd0_cls : FUN_0067ad70_cls
{
    Date* date;
    FUN_00670b30* data;
    virtual ~FUN_0067ccd0_cls();
};

// Destructor that deletes the date and data members via their vector deleting destructors and nulls both pointers.
// @fnv 0x0067ccd0
FUN_0067ccd0_cls::~FUN_0067ccd0_cls()
{
    Date* b = date;
    Date* a = b;
    a ? a->__vecDelDtor(1) : 0;
    date = 0;
    FUN_00670b30* d = data;
    FUN_00670b30* c = d;
    c ? c->__vecDelDtor(1) : 0;
    data = 0;
}

struct BGSLoadFormBuffer;

struct FUN_00680830_impl
{
    void __thiscall FUN_00680830(BGSLoadFormBuffer*);
};
struct FUN_0067fc50_impl
{
    void __thiscall ResolveObject(BGSLoadFormBuffer*);
};

struct FUN_0067d8b0_shell
{
    void* m00;
    void* m04;
    void* m08;
    void LoadForm(BGSLoadFormBuffer*);
};

// Calls the load routine on m04 and then on m08, each with the load game buffer, when the pointer is non-null.
// @fnv 0x0067d8b0
void FUN_0067d8b0_shell::LoadForm(BGSLoadFormBuffer* apLoadGameBuffer)
{
    if (m04)
        ((FUN_00680830_impl*)m04)->FUN_00680830(apLoadGameBuffer);
    if (m08)
        ((FUN_0067fc50_impl*)m08)->ResolveObject(apLoadGameBuffer);
}

struct FUN_0067da20_shell
{
    void ResetValue(int arg);
};

// @fnv 0x0067da20
void FUN_0067da20_shell::ResetValue(int arg)
{
    *(int*)((char*)this + 4) = 0;
}

void __cdecl _Deallocate(void*);
struct FUN_0067d990_shell
{
    void __thiscall InitVTableAndInit();
    void* __thiscall FUN_0067d990(unsigned int);
};
// Calls InitVTableAndInit, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0067d990
void* __thiscall FUN_0067d990_shell::FUN_0067d990(unsigned int flags)
{
    InitVTableAndInit();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_0067cfc0_shell : TESUseWeaponPackageData
{
    bool FUN_0067cfc0(TESPackageData* apCompare);
};

struct FUN_00680220_shell
{
    bool Compare(PackageTargetRecord* target);
};

struct FUN_0067f600_shell
{
    bool IsDifferentFrom(void* target);
};

void* FUN_00ec43fb(void* object, unsigned int flags, char* typeInfo1, char* typeInfo2, int reserved);
float __cdecl FUN_00408860(float value);

extern char DAT_0119bdec;
extern char DAT_0119bf00;

// Compares this use-weapon package data against apCompare field by field, returning true when any field differs or the cast fails.
// @fnv 0x0067cfc0
bool FUN_0067cfc0_shell::FUN_0067cfc0(TESPackageData* apCompare)
{
    TESUseWeaponPackageData* pOtherData =
        static_cast<TESUseWeaponPackageData*>(FUN_00ec43fb(apCompare, 0, &DAT_0119bdec, &DAT_0119bf00, 0));

    if (!pOtherData)
        return true;

    if (this->pWeapon != pOtherData->pWeapon)
        return true;

    if (this->m_pUseTarget)
    {
        if (reinterpret_cast<FUN_00680220_shell*>(this->m_pUseTarget)->Compare(pOtherData->m_pUseTarget))
            return true;
    }
    else if (pOtherData->m_pUseTarget)
    {
        return true;
    }

    if (this->m_pTargetLocation)
    {
        if (reinterpret_cast<FUN_0067f600_shell*>(this->m_pTargetLocation)
                ->IsDifferentFrom(static_cast<void*>(pOtherData->m_pTargetLocation)))
            return true;
    }
    else if (pOtherData->m_pTargetLocation)
    {
        return true;
    }

    if (this->m_bFlag1 != pOtherData->m_bFlag1)
        return true;

    if (this->m_bFlag2 != pOtherData->m_bFlag2)
        return true;

    if (this->m_bFlag3 != pOtherData->m_bFlag3)
        return true;

    if (this->m_bFlag4 != pOtherData->m_bFlag4)
        return true;

    if (this->m_bFlag5 != pOtherData->m_bFlag5)
        return true;

    if (this->m_bFlag6 != pOtherData->m_bFlag6)
        return true;

    if (this->m_usValue1 != pOtherData->m_usValue1)
        return true;

    if (this->m_usValue2 != pOtherData->m_usValue2)
        return true;

    if (this->m_usValue3 != pOtherData->m_usValue3)
        return true;

    if (FUN_00408860(this->m_fValue1 - pOtherData->m_fValue1) > 0.01)
        return true;

    if (FUN_00408860(this->m_fValue2 - pOtherData->m_fValue2) > 0.01)
        return true;

    return false;
}

void* memset(void*, int, unsigned int);
bool __cdecl FUN_00401500();
void __cdecl AppendChunk(unsigned int, void*, unsigned int);

struct FUN_006802f0_shell
{
    void FUN_006802f0(int);
};

struct PackageLocationSave
{
    void Save(int);
};

struct FlaggedValueData
{
    bool m_bFlag1;
    bool m_bFlag2;
    bool m_bFlag3;
    bool m_bFlag4;
    bool m_bFlag5;
    bool m_bFlag6;
    unsigned short m_usValue1;
    unsigned short m_usValue2;
    unsigned short m_usValue3;
    float m_fValue1;
    float m_fValue2;
    unsigned int m_uiIntegerValue;

    void FUN_0067ca10();
};

struct FUN_0067d350_shell
{
    unsigned int base;
    void* m_pUseTarget;
    LocationDescriptor* m_pTargetLocation;
    bool m_bFlag1;
    bool m_bFlag2;
    bool m_bFlag3;
    bool m_bFlag4;
    bool m_bFlag5;
    bool m_bFlag6;
    unsigned short m_usValue1;
    unsigned short m_usValue2;
    unsigned short m_usValue3;
    float m_fValue1;
    float m_fValue2;
    TESObjectWEAP* pWeapon;

    void FUN_0067d350();
};

// @fnv 0x0067d350
void FUN_0067d350_shell::FUN_0067d350()
{
    FlaggedValueData saveData;

    memset(&saveData, 0, 0x18);

    saveData.m_bFlag1 = this->m_bFlag1;
    saveData.m_bFlag2 = this->m_bFlag2;
    saveData.m_bFlag3 = this->m_bFlag3;
    saveData.m_bFlag4 = this->m_bFlag4;
    saveData.m_bFlag5 = this->m_bFlag5;
    saveData.m_bFlag6 = this->m_bFlag6;
    saveData.m_usValue1 = this->m_usValue1;
    saveData.m_usValue2 = this->m_usValue2;
    saveData.m_usValue3 = this->m_usValue3;
    saveData.m_fValue1 = this->m_fValue1;
    saveData.m_fValue2 = this->m_fValue2;

    saveData.m_uiIntegerValue = this->pWeapon ? this->pWeapon->GetFormID() : 0;

    if (FUN_00401500())
        saveData.FUN_0067ca10();

    AppendChunk(0x33574b50, &saveData, 0x18);

    if (FUN_00401500())
        saveData.FUN_0067ca10();

    if (this->m_pUseTarget)
        reinterpret_cast<FUN_006802f0_shell*>(this->m_pUseTarget)->FUN_006802f0(0x32445450);

    if (this->m_pTargetLocation)
        reinterpret_cast<PackageLocationSave*>(this->m_pTargetLocation)->Save(0x32444c50);
}

struct B67CC20Color
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
};

struct B67CC20Info
{
    unsigned char m_ucType;
    unsigned char m_ucPad;
    unsigned short m_usElementCount;
};

struct B67CC20Range
{
    unsigned short m_usMin;
    unsigned short m_usMax;
};

class B67CC20Base
{
  public:
    B67CC20Base();
    virtual ~B67CC20Base();
};

class FUN_0067cc20 : public B67CC20Base
{
  public:
    int m_iA;
    int m_iB;
    unsigned char m_ucR;
    unsigned char m_ucG;
    unsigned char m_ucB;
    unsigned char m_ucA;
    unsigned char m_ucType;
    bool m_bUnknownFlag;
    unsigned short m_usElementCount;
    unsigned short m_usMin;
    unsigned short m_usMax;
    float m_fStartValue;
    float m_fEnd;
    int m_iC;

    FUN_0067cc20(B67CC20Color kColor, B67CC20Info kInfo, B67CC20Range kRange, float fStart, float m_fEndValue);
    virtual ~FUN_0067cc20();
};

// Initializes the color, type, range and start/end fields from the constructor arguments and zeroes the three int counters.
// @fnv 0x0067cc20
FUN_0067cc20::FUN_0067cc20(B67CC20Color kColor, B67CC20Info kInfo, B67CC20Range kRange, float fStart, float m_fEndValue)
{
    m_iA = 0;
    m_iB = 0;
    m_iC = 0;
    m_ucR = kColor.r;
    m_ucG = kColor.g;
    m_ucB = kColor.b;
    m_ucA = kColor.a;
    m_ucType = kInfo.m_ucType;
    m_bUnknownFlag = kInfo.m_usElementCount <= 0;
    m_usElementCount = kInfo.m_usElementCount;
    m_usMin = kRange.m_usMin;
    m_usMax = kRange.m_usMax;
    m_fStartValue = fStart;
    m_fEnd = m_fEndValue;
}

// Copy the optional extra data from another object: create ours on demand, or drop it when the source is null.

void* __cdecl operator new(unsigned int uiSize);

class D470Source;

class D470ExtraData
{
  public:
    D470ExtraData();
    ~D470ExtraData();
    void CopyFrom(D470Source* pkSource);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

class D470Owner
{
  public:
    int unk00;
    D470ExtraData* m_pExtraData;

    void SetExtraData(D470Source* pkSource);
};

// @fnv 0x0067d470
void D470Owner::SetExtraData(D470Source* pkSource)
{
    if (pkSource)
    {
        if (!m_pExtraData)
            m_pExtraData = new D470ExtraData;
        m_pExtraData->CopyFrom(pkSource);
    }
    else
    {
        delete m_pExtraData;
        m_pExtraData = 0;
    }
}

struct BGSLoadFormBuffer
{
    void FUN_00864980(void* destination, unsigned int size);
    unsigned int FUN_008648a0();
};
TESForm* __cdecl LookupFormByID(unsigned int);
struct PackageTargetObj : PackageTargetRecord
{
    PackageTargetObj();
    void FUN_006807b0(BGSLoadFormBuffer*);
};
struct PackageLocationObj
{
    unsigned int type;
    unsigned int location;
    unsigned int radius;
    PackageLocationObj();
    void FUN_0067fbe0(BGSLoadFormBuffer*);
};
struct UseWeaponLoader : TESUseWeaponPackageData
{
    void LoadUseWeaponData(BGSLoadFormBuffer* buffer);
};
// Reads the use-weapon package data from the buffer: fixed-size fields, a weapon form, and optional target and location objects.
// @fnv 0x0067d6b0
void UseWeaponLoader::LoadUseWeaponData(BGSLoadFormBuffer* buffer)
{
    buffer->FUN_00864980(&m_bFlag1, 1);
    buffer->FUN_00864980(&m_bFlag2, 1);
    buffer->FUN_00864980(&m_bFlag3, 1);
    buffer->FUN_00864980(&m_bFlag4, 1);
    buffer->FUN_00864980(&m_bFlag5, 1);
    buffer->FUN_00864980(&m_bFlag6, 1);
    buffer->FUN_00864980(&m_usValue1, 2);
    buffer->FUN_00864980(&m_usValue2, 2);
    buffer->FUN_00864980(&m_usValue3, 2);
    buffer->FUN_00864980(&m_fValue1, 4);
    buffer->FUN_00864980(&m_fValue2, 4);
    pWeapon = dynamic_cast<TESObjectWEAP*>(LookupFormByID(buffer->FUN_008648a0()));
    bool hasTarget;
    bool hasLocation = false;
    buffer->FUN_00864980(&hasLocation, 1);
    if (hasLocation)
    {
        m_pUseTarget = new PackageTargetObj;
        static_cast<PackageTargetObj*>(m_pUseTarget)->FUN_006807b0(buffer);
    }
    hasTarget = false;
    buffer->FUN_00864980(&hasTarget, 1);
    if (hasTarget)
    {
        m_pTargetLocation = reinterpret_cast<LocationDescriptor*>(new PackageLocationObj);
        reinterpret_cast<PackageLocationObj*>(m_pTargetLocation)->FUN_0067fbe0(buffer);
    }
}

extern int DAT_01068a88;

struct FUN_0067d9c0_cls
{
    void* m_vptr;
    void Init();
    void InitVTableAndInit();
};

// @fnv 0x0067d9c0
void FUN_0067d9c0_cls::InitVTableAndInit()
{
    m_vptr = &DAT_01068a88;
    Init();
}

void* FUN_00ec43fb(void* object, unsigned int flags, char* typeInfo1, char* typeInfo2, int reserved);
extern char DAT_0119bdec;
extern char DAT_0119bf00;

struct Target_Stub : PackageTargetRecord
{
    Target_Stub();
    ~Target_Stub();
    void CopyFrom(PackageTargetRecord*);
};

struct TargetLocation_Stub
{
    int unk00;
    int unk04;
    int unk08;
    TargetLocation_Stub();
    ~TargetLocation_Stub();
    void CopyFrom(LocationDescriptor*, bool);
};

struct UseWeaponPackageData_Shell : TESUseWeaponPackageData
{
    void FUN_0067cd90(TESPackageData* apSource);
};

// Copies a TESUseWeaponPackageData obtained from apSource into this, deep-copying its two sub-objects and copying the remaining fields.
// @fnv 0x0067cd90
void UseWeaponPackageData_Shell::FUN_0067cd90(TESPackageData* apSource)
{
    TESUseWeaponPackageData* target =
        (TESUseWeaponPackageData*)FUN_00ec43fb(apSource, 0, &DAT_0119bdec, &DAT_0119bf00, 0);
    if (!target)
    {
        return;
    }

    delete (Target_Stub*)this->m_pUseTarget;
    this->m_pUseTarget = 0;

    if (target->m_pUseTarget)
    {
        this->m_pUseTarget = new Target_Stub();
        ((Target_Stub*)this->m_pUseTarget)->CopyFrom(target->m_pUseTarget);
    }

    this->pWeapon = target->pWeapon;

    delete (TargetLocation_Stub*)this->m_pTargetLocation;
    this->m_pTargetLocation = 0;

    if (target->m_pTargetLocation)
    {
        this->m_pTargetLocation = (LocationDescriptor*)new TargetLocation_Stub();
        ((TargetLocation_Stub*)this->m_pTargetLocation)->CopyFrom(target->m_pTargetLocation, false);
    }

    this->m_bFlag1 = target->m_bFlag1;
    this->m_bFlag2 = target->m_bFlag2;
    this->m_bFlag3 = target->m_bFlag3;
    this->m_bFlag4 = target->m_bFlag4;
    this->m_bFlag5 = target->m_bFlag5;
    this->m_bFlag6 = target->m_bFlag6;
    this->m_usValue1 = target->m_usValue1;
    this->m_usValue2 = target->m_usValue2;
    this->m_usValue3 = target->m_usValue3;
    this->m_fValue1 = target->m_fValue1;
    this->m_fValue2 = target->m_fValue2;
}

class BGSSaveFormBuffer
{
  public:
    void SaveData(void*, unsigned int, int);
    void FUN_00865df0(void*, int);
};
struct TargetSave
{
    void SaveToBuffer(BGSSaveFormBuffer*);
};
struct LocationSave
{
    void FUN_0067fb60(BGSSaveFormBuffer*);
};
struct WorkerWeapon : TESUseWeaponPackageData
{
    void FUN_0067d550(BGSSaveFormBuffer*);
};
// @fnv 0x0067d550
void WorkerWeapon::FUN_0067d550(BGSSaveFormBuffer* buffer)
{
    buffer->SaveData(&m_bFlag1, 1, 0);
    buffer->SaveData(&m_bFlag2, 1, 0);
    buffer->SaveData(&m_bFlag3, 1, 0);
    buffer->SaveData(&m_bFlag4, 1, 0);
    buffer->SaveData(&m_bFlag5, 1, 0);
    buffer->SaveData(&m_bFlag6, 1, 0);
    buffer->SaveData(&m_usValue1, 2, 0);
    buffer->SaveData(&m_usValue2, 2, 0);
    buffer->SaveData(&m_usValue3, 2, 0);
    buffer->SaveData(&m_fValue1, 4, 0);
    buffer->SaveData(&m_fValue2, 4, 0);
    buffer->FUN_00865df0(pWeapon, 0);
    bool p = m_pUseTarget;
    buffer->SaveData(&p, 1, 0);
    if (p)
        ((TargetSave*)m_pUseTarget)->SaveToBuffer(buffer);
    bool bHasLocation = m_pTargetLocation;
    buffer->SaveData(&bHasLocation, 1, 0);
    if (bHasLocation)
        ((LocationSave*)m_pTargetLocation)->FUN_0067fb60(buffer);
}

class FUN_0067ad20_Class
{
  public:
    FUN_0067ad20_Class();
    virtual ~FUN_0067ad20_Class();
};

struct Data67CB
{
    char m_c00;
    char m_c01;
    char m_c02;
    char m_c03;
    char m_c04;
    char m_c05;
    short m_s06;
    short m_s08;
    short m_s0A;
    float m_f0C;
    float m_f10;
};

class FUN_0067cb70 : public FUN_0067ad20_Class
{
  public:
    int m_unk04;
    int m_unk08;
    Data67CB m_kData;
    int m_unk20;

    FUN_0067cb70(Data67CB kData, int iParam);
    virtual ~FUN_0067cb70();
};

// Constructor that initializes m_unk04 and m_unk08 to zero, copies kData into m_kData, and stores iParam in m_unk20.
// @fnv 0x0067cb70
FUN_0067cb70::FUN_0067cb70(Data67CB kData, int iParam)
{
    m_unk04 = 0;
    m_unk08 = 0;
    m_unk20 = iParam;
    m_kData.m_c00 = kData.m_c00;
    m_kData.m_c01 = kData.m_c01;
    m_kData.m_c02 = kData.m_c02;
    m_kData.m_c03 = kData.m_c03;
    m_kData.m_c04 = kData.m_c04;
    m_kData.m_c05 = kData.m_c05;
    m_kData.m_s06 = kData.m_s06;
    m_kData.m_s08 = kData.m_s08;
    m_kData.m_s0A = kData.m_s0A;
    m_kData.m_f0C = kData.m_f0C;
    m_kData.m_f10 = kData.m_f10;
}
