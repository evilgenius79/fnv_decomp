// fallout_shared/tescreature.cpp: TESCreature, DelStandIn, ActorValue, StandIn and more (45 functions)

#include "tescreature_decls.h"

// @fnv 0x005F7900
TESCreature::~TESCreature()
{
    ClearData();
}

// @fnv 0x005F7B80
void TESCreature::ClearData()
{
    if (((TESActorBaseData*)((char*)this + 0x30))->GetFlag(0x100))
    {
        delete m_pCreatureSounds;
        m_pCreatureSounds = 0;
    }
    m_cCreatureDataFlag = 0xff;
}

// @fnv 0x005F7A40
void TESCreature::ResetFormData()
{
    dataPadding = 0;
    m_ucField00 = 50;
    m_ucField01 = 50;
    m_ucField02 = 50;
    m_ucCreatureType = 32;
    m_pImpactDataSet = 0;
    m_pCreatureListForm = 0;
    m_fFirstCreatureStat = 0.0f;
    m_fSecondCreatureStat = gCreatureFootWeight;
    m_fThirdCreatureStatCur = 1.0f;
    m_pCreatureSounds = 0;
    m_pCombatStyle = 0;
    m_pBodyPartDataCur = 0;
    m_bHasImpactDataSet = false;
    m_eSoundLevel = 1;
    m_eImpactMaterial = 6;
    m_cCreatureDataFlag = 0xff;
    ((TESActorBaseData*)((char*)this + 0x30))->UpdateFlagBit(0x40, true, false);
    ((TESActorBaseData*)((char*)this + 0x30))->UpdateFlagBit(false, false);
    ((CombatProcedure*)((char*)this + 0xb0))->Initialize((CombatController*)0x32);
}

// @fnv 0x005F9210
CreatureSoundCollection* TESCreature::GetMutableCreatureSounds()
{
    if (!((TESActorBaseData*)((char*)this + 0x30))->GetFlag(0x100) || !m_pCreatureSounds)
    {
        ((TESActorBaseData*)((char*)this + 0x30))->UpdateFlagBit(0x100, true, true);
        m_pCreatureSounds = new CreatureSoundCollection;
    }
    return m_pCreatureSounds;
}

// @fnv 0x005FB3B0
void TESCreature::LoadGame(BGSLoadFormBuffer* buffer)
{
    ((TESActorBase*)this)->LoadGame(buffer);
    if (buffer->GetChangeFlags(0x200))
    {
        buffer->ReadTypedData(&m_ucField00, 1);
        buffer->ReadTypedData(&m_ucField01, 1);
        buffer->ReadTypedData(&m_ucField02, 1);
    }
}

// @fnv 0x005F9140
void TESCreature::SetCreatureSoundsFrom(TESCreature* soundCreature)
{
    if (((TESActorBaseData*)((char*)this + 0x30))->GetFlag(0x100))
    {
        if (soundCreature)
        {
            delete m_pCreatureSounds;
            ((TESActorBaseData*)((char*)this + 0x30))->UpdateFlagBit(0x100, false, true);
            m_pCreature = soundCreature;
        }
    }
    else
    {
        m_pCreature = soundCreature;
    }
}

// @fnv 0x005FA2E0
BGSBodyPartData* TESCreature::GetBodyPartData()
{
    if (m_pBodyPartDataCur)
        return m_pBodyPartDataCur;
    return BGSBodyPartData::ms_pBodyPartData;
}

// @fnv 0x005FA310
void TESCreature::SetBodyPartData(BGSBodyPartData* bodyPartData)
{
    m_pBodyPartDataCur = bodyPartData;
}

// @fnv 0x005FB430
void TESCreature::Revert(BGSLoadFormBuffer* buffer)
{
    ((TESNPC*)this)->Revert(buffer);
}

// @fnv 0x005F7230
TESCreature::TESCreature()
{
    ((TESForm*)this)->SetFormType(kCreature);
    ResetFormData();
    ((TESAIForm*)((char*)this + 0x90))->SetResponsibility(50, false);
    ((TESAIForm*)((char*)this + 0x90))->SetAggression(1, false);
    ((TESAIForm*)((char*)this + 0x90))->SetConfidence(2, false);
    ((TESAIForm*)((char*)this + 0x90))->SetEnergy(2, false);
    if (!g_dataHandler->FUN_004516b0())
        ((TESActorBaseData*)((char*)this + 0x30))->SetFactionRank(DAT_011cb550, 0);
}

struct BGSImpactDataSet;
struct QueuedFile;
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct BGSPreloadable : public BaseFormComponent
{
    virtual void QueueResourceLoad(int, QueuedFile*);
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BGSPreloadable[sizeof(BGSPreloadable) == 4 ? 1 : -1];
struct FUN_005f8bb0_shell : public TESCreature
{
    void SetImpactDataSet(BGSImpactDataSet*);
};

// @fnv 0x005f8bb0
void FUN_005f8bb0_shell::SetImpactDataSet(BGSImpactDataSet* apSet)
{
    m_pImpactDataSet = apSet;
}

struct FUN_005f9100_shell : public TESCreature
{
    TESCreature* FUN_005f9100();
};

// Returns the TESCreature at offset 0x128 unless the actor base data has flag 0x100 set, in which case it returns 0.
// @fnv 0x005f9100
TESCreature* FUN_005f9100_shell::FUN_005f9100()
{
    if (((TESActorBaseData*)((char*)this + 0x30))->GetFlag(0x100))
    {
        return 0;
    }
    else
    {
        return *(TESCreature**)((char*)this + 0x128);
    }
}

struct FUN_005f91d0_shell : public TESCreature
{
    CreatureSoundCollection* FUN_005f91d0();
};

// @fnv 0x005f91d0
CreatureSoundCollection* FUN_005f91d0_shell::FUN_005f91d0()
{
    if (((TESActorBaseData*)((char*)this + 0x30))->GetFlag(0x100))
        return *(CreatureSoundCollection**)((char*)this + 0x128);
    else
        return 0;
}

struct FUN_005f9ad0_shell : public TESCreature
{
    unsigned char FUN_005f9ad0();
};

// @fnv 0x005f9ad0
unsigned char FUN_005f9ad0_shell::FUN_005f9ad0()
{
    return m_ucCreatureType;
}

struct FUN_005f9af0_shell : public TESCreature
{
    void SetCreatureType(unsigned char);
};

// @fnv 0x005f9af0
void FUN_005f9af0_shell::SetCreatureType(unsigned char acVal)
{
    m_ucCreatureType = acVal;
}

struct BGSImpactDataSet;
struct FUN_005f9b30_shell : public TESCreature
{
    BGSImpactDataSet* GetImpactDataSet();
};

// @fnv 0x005f9b30
BGSImpactDataSet* FUN_005f9b30_shell::GetImpactDataSet()
{
    return m_pImpactDataSet;
}

struct FUN_005fa2c0_shell : public TESCreature
{
    void SetByteAt12D(unsigned char);
};

// @fnv 0x005fa2c0
void FUN_005fa2c0_shell::SetByteAt12D(unsigned char aiVal)
{
    *((unsigned char*)this + 0x12d) = aiVal;
}

struct FUN_005fbdb0_shell : public TESCreature
{
    void FUN_005fbdb0(char);
};

// @fnv 0x005fbdb0
void FUN_005fbdb0_shell::FUN_005fbdb0(char aeType)
{
    *((char*)this + 0x12c) = aeType;
}

struct FUN_00821660_shell : public TESCreature
{
    float FUN_00821660();
};

// @fnv 0x00821660
float FUN_00821660_shell::FUN_00821660()
{
    return m_fSecondCreatureStat;
}

struct NiFormArray;
struct TESIdleForm;
struct TESObject;
struct TESObjectREFR;
struct IdleAnimationManager
{
    void RemoveIdleForm(TESIdleForm*);
    void InitializeIdleAnimations();
    void ResetIdleAnimations();
    void LoadIdleAnimations();
    NiFormArray* AddRootIdleArray(TESForm*);
    NiFormArray* AddRootIdleArray(char*, void*, bool);
    NiFormArray* GetRootIdleArray(TESForm*);
    NiFormArray* GetRootIdleArray(char*);
    NiFormArray* GetIdleArray(TESForm*);
    NiFormArray* GetIdleArray(char*);
    static void BuildIdlePath(char*, char*);
    void* FindIdleArrayEntry(char*, int);
    void ClearIdleData();
    static TESObject* GetCurrentUsedItem();
    static void SetUsedItem(TESObject*);
    static void SetUsedItemLevel(int);
    static int GetUsedItemLevel();
    static void SetUsedItemActivate(bool);
    static bool GetUsedItemActivate();
    bool GetInitialized();
    TESIdleForm* FindIdleFormForObject(TESObjectREFR*, TESObjectREFR*);
    void* __vecDelDtor(unsigned int);
    char m_acIdlePath[20];
    bool bInitialized;
    char _pad_15[3];
    char m_acIdleName[16];
};
typedef char _sizecheck_TESIdleManager[sizeof(IdleAnimationManager) == 40 ? 1 : -1];
struct FUN_00843150_shell : public IdleAnimationManager
{
    bool FUN_00843150();
};

// @fnv 0x00843150
bool FUN_00843150_shell::FUN_00843150()
{
    return bInitialized;
}

void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_005f75b0(unsigned int flags);
};
// Runs the destructor on this object, then frees it with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x005f75b0
void* DelStandIn::FUN_005f75b0(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}

struct FUN_0050f760_shell
{
    int FUN_0050f600(int);
    int FUN_0050f760(int);
};
// @fnv 0x0050f760
int FUN_0050f760_shell::FUN_0050f760(int a)
{
    return FUN_0050f600(a);
}

struct FUN_0051f4b0_shell
{
    void FUN_0051f4b0(int value);
};

// @fnv 0x0051f4b0
void FUN_0051f4b0_shell::FUN_0051f4b0(int value)
{
    *(int*)((char*)this + 0x118) = value;
}

struct FUN_0047ded0_shell
{
    unsigned short FUN_0047ded0(void);
};

struct FUN_005f7460_shell
{
    void FUN_005f7460();
};

// @fnv 0x005f7460
void FUN_005f7460_shell::FUN_005f7460()
{
    ((FUN_0047ded0_shell*)((char*)this - 0xd0))->FUN_0047ded0();
}

struct FUN_005f7570_shell
{
    void* FUN_005f7570();
};
// @fnv 0x005f7570
void* FUN_005f7570_shell::FUN_005f7570()
{
    return (char*)this - 0x100;
}

struct FUN_005f9040_shell : public TESActorBaseData
{
    bool FUN_005f9040();
};
// @fnv 0x005f9040
bool FUN_005f9040_shell::FUN_005f9040()
{
    return GetFlag(0x20000);
}

struct FUN_005f9060_shell : public TESActorBaseData
{
    bool FUN_005f9060();
};
// @fnv 0x005f9060
bool FUN_005f9060_shell::FUN_005f9060()
{
    return GetFlag(0x10000);
}

struct FUN_005f9080_shell : public TESActorBaseData
{
    bool FUN_005f9080();
};
// @fnv 0x005f9080
bool FUN_005f9080_shell::FUN_005f9080()
{
    return GetFlag(0x8000);
}

struct FUN_005f90a0_shell : public TESActorBaseData
{
    bool FUN_005f90a0();
};
// @fnv 0x005f90a0
bool FUN_005f90a0_shell::FUN_005f90a0()
{
    return GetFlag(0x80000);
}

extern int DAT_01000000;

struct FUN_005f90c0_shell : TESActorBaseData
{
    bool FUN_005f90c0();
};

// @fnv 0x005f90c0
bool FUN_005f90c0_shell::FUN_005f90c0()
{
    return ((TESActorBaseData*)((char*)this + 0x30))->GetFlag((unsigned int)&DAT_01000000);
}

struct FUN_005f90e0_shell : TESActorBaseData
{
    bool FUN_005f90e0();
};

// @fnv 0x005f90e0
bool FUN_005f90e0_shell::FUN_005f90e0()
{
    return ((TESActorBaseData*)((char*)this + 0x30))->GetFlag(0x2000000);
}

struct FUN_005f9b10_class
{
    void SetBoltSmallWidth(float afBoltSmallWidth);
};

// @fnv 0x005f9b10
void FUN_005f9b10_class::SetBoltSmallWidth(float afBoltSmallWidth)
{
    *(float*)((char*)this + 0x138) = afBoltSmallWidth;
}

struct FUN_005f9b70_shell
{
    void* GetOffset12C();
};
// @fnv 0x005f9b70
void* FUN_005f9b70_shell::GetOffset12C()
{
    return (char*)this + 0x12c;
}

struct ActorValue
{
    enum Index
    {
        kNone
    };
    static bool IsSkill(Index);
    static unsigned char ToArrayIndex(int, Index);
};
struct FUN_006078e0_s
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
    virtual void SetFlags(int);
    void ApplyCommand(ActorValue::Index, int);
    void FUN_006078e0(ActorValue::Index aiWhich, int aiValue);
};
// Stores a skill actor value as a byte at offset 0x114 and sets flag 0x200, otherwise forwards to ApplyCommand.
// @fnv 0x006078e0
void FUN_006078e0_s::FUN_006078e0(ActorValue::Index aiWhich, int aiValue)
{
    if (ActorValue::IsSkill(aiWhich))
    {
        reinterpret_cast<unsigned char*>(this)[0x114 + (char)ActorValue::ToArrayIndex(2, aiWhich)] =
            (unsigned char)aiValue;
        SetFlags(0x200);
    }
    else
    {
        ApplyCommand(aiWhich, aiValue);
    }
}

struct FUN_008126e0_shell
{
    void SetWhich(int aiWhich);
};

// @fnv 0x008126e0
void FUN_008126e0_shell::SetWhich(int aiWhich)
{
    *(int*)((char*)this + 0x140) = aiWhich;
}

struct FUN_005f8f10_shell : TESActorBaseData
{
    unsigned short GetFatigue();
    bool GetMatchesPCLevel();
    unsigned short FUN_0047ded0();
    unsigned short GetScaledFatigue();
};

// Returns fatigue, multiplied by FUN_0047ded0 (clamped to at least 1) when GetMatchesPCLevel is true.
// @fnv 0x005f8f10
unsigned short FUN_005f8f10_shell::GetScaledFatigue()
{
    unsigned short fatigue = GetFatigue();
    if (GetMatchesPCLevel())
    {
        short value = FUN_0047ded0();
        if (value < 1)
            value = 1;
        fatigue = (unsigned short)(value * (unsigned short)fatigue);
    }
    return fatigue;
}

struct FUN_005f7420_shell
{
    virtual void _v0();
    virtual double _v1(int);
    virtual void _v2();
    virtual void _v3();
    virtual void _v4();
    virtual void _v5();
    virtual double _v6(int);
    float GetSumOfVirtualValues(int);
};
// Returns the sum of the two virtual calls _v1 and _v6 for the given index, cast to float.
// @fnv 0x005f7420
float FUN_005f7420_shell::GetSumOfVirtualValues(int aiWhich)
{
    return (float)(_v1(aiWhich) + _v6(aiWhich));
}

struct FUN_005f78b0_shell
{
    void* DestroyActorBase(unsigned int);
};
// Destructs the TESActorBase and, if flags has bit 0 set, frees the object with operator delete; returns this.
// @fnv 0x005f78b0
void* FUN_005f78b0_shell::DestroyActorBase(unsigned int flags)
{
    ((TESActorBase*)this)->TESActorBase::~TESActorBase();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_005f8e90_shell : public TESActorBaseData
{
    int FUN_005f8e90();
    int _ref_00726070();
    bool GetMatchesPCLevel();
    short FUN_0047ded0();
};

// @fnv 0x005f8e90
int FUN_005f8e90_shell::FUN_005f8e90()
{
    unsigned short result = 0;
    if (reinterpret_cast<FUN_005f8e90_shell*>(reinterpret_cast<char*>(this) - 0x80)->GetMatchesPCLevel())
    {
        short factor = reinterpret_cast<FUN_005f8e90_shell*>(reinterpret_cast<char*>(this) - 0x80)->FUN_0047ded0();
        if (factor < 1)
            factor = 1;
        result = factor * _ref_00726070();
    }
    else
    {
        result = _ref_00726070();
    }
    return result;
}

struct FUN_005f16f0_shell
{
    unsigned short FUN_005f16f0(unsigned int);
};
struct FUN_005fb180_shell : FUN_005f16f0_shell
{
    unsigned short FUN_005fb180(unsigned int);
};
// @fnv 0x005fb180
unsigned short FUN_005fb180_shell::FUN_005fb180(unsigned int aiFlags)
{
    unsigned short isize = 0;
    isize += FUN_005f16f0(aiFlags);
    if (aiFlags & 0x200)
        isize += 3;
    if (aiFlags & 0)
        isize += 4;
    return isize;
}

struct BGSSaveFormBuffer
{
    void SaveData(void* p, int a, int b);
};
struct FUN_005f1f30_shell
{
    void __thiscall FUN_005f1f30(BGSSaveFormBuffer*);
};
struct FUN_005fb330_shell
{
    void FUN_005fb330(BGSSaveFormBuffer* buffer);
};
// Calls FUN_005f1f30, then if change flag 0x200 is set saves three bytes at offsets 0x12d, 0x12e and 0x12f into the buffer.
// @fnv 0x005fb330
void FUN_005fb330_shell::FUN_005fb330(BGSSaveFormBuffer* buffer)
{
    ((FUN_005f1f30_shell*)this)->FUN_005f1f30(buffer);
    if (((BGSLoadFormBuffer*)buffer)->GetChangeFlags(0x200))
    {
        buffer->SaveData((char*)this + 0x12d, 1, 0);
        buffer->SaveData((char*)this + 0x12e, 1, 0);
        buffer->SaveData((char*)this + 0x12f, 1, 0);
    }
}

float __cdecl FUN_00406ce0(float);
struct FUN_005f73f0_Holder
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual float v8(int);
    int ConvertVirtualResultToInt(int);
};
// Calls the virtual v8 with a and converts the returned float to int via FUN_00406ce0.
// @fnv 0x005f73f0
int FUN_005f73f0_Holder::ConvertVirtualResultToInt(int a)
{
    return (int)FUN_00406ce0(v8(a));
}

struct FakeAVOwner
{
    virtual void b0() = 0;
    virtual void b1() = 0;
    virtual void b2() = 0;
    virtual float GetAV(int) = 0;
};
struct FakePrimary
{
    virtual void a0() = 0;
    virtual void a1() = 0;
    virtual void a2() = 0;
    virtual void a3() = 0;
    virtual void a4() = 0;
    virtual void a5() = 0;
    virtual void a6() = 0;
    virtual void a7() = 0;
    virtual void a8() = 0;
    virtual void a9() = 0;
    virtual void a10() = 0;
    virtual void a11() = 0;
    virtual void a12() = 0;
    virtual void a13() = 0;
    virtual void a14() = 0;
    virtual void a15() = 0;
    virtual void a16() = 0;
    virtual void a17() = 0;
    virtual void a18() = 0;
    virtual void a19() = 0;
    virtual void a20() = 0;
    virtual void a21() = 0;
    virtual void a22() = 0;
    virtual void a23() = 0;
    virtual void a24() = 0;
    virtual void a25() = 0;
    virtual void a26() = 0;
    virtual void a27() = 0;
    virtual void a28() = 0;
    virtual void a29() = 0;
    virtual void a30() = 0;
    virtual void a31() = 0;
    virtual void a32() = 0;
    virtual void a33() = 0;
    virtual void a34() = 0;
    virtual void a35() = 0;
    virtual void a36() = 0;
    virtual void a37() = 0;
    virtual void a38() = 0;
    virtual void a39() = 0;
    virtual void a40() = 0;
    virtual void a41() = 0;
    virtual void a42() = 0;
    virtual void a43() = 0;
    virtual void a44() = 0;
    virtual void a45() = 0;
    virtual void a46() = 0;
    virtual void a47() = 0;
    virtual void a48() = 0;
    virtual void a49() = 0;
    virtual void a50() = 0;
    virtual void a51() = 0;
    virtual void a52() = 0;
    virtual void a53() = 0;
    virtual void a54() = 0;
    virtual void a55() = 0;
    virtual void a56() = 0;
    virtual void a57() = 0;
    virtual void a58() = 0;
    virtual void a59() = 0;
    virtual void a60() = 0;
    virtual void a61() = 0;
    virtual void a62() = 0;
    virtual void a63() = 0;
    virtual void a64() = 0;
    virtual void a65() = 0;
    virtual void a66() = 0;
    virtual void a67() = 0;
    virtual void a68() = 0;
    virtual void a69() = 0;
    virtual void a70() = 0;
    virtual void a71() = 0;
    virtual void a72() = 0;
    virtual void a73() = 0;
    virtual void a74() = 0;
    virtual void a75() = 0;
    virtual void a76() = 0;
    virtual void a77() = 0;
    virtual void a78() = 0;
    virtual void a79() = 0;
    virtual void a80() = 0;
    virtual void a81() = 0;
    virtual void a82() = 0;
    virtual void a83() = 0;
    virtual void a84() = 0;
    virtual void a85() = 0;
    virtual void a86() = 0;
    virtual void a87() = 0;
    virtual void a88() = 0;
    virtual void a89() = 0;
    virtual void a90() = 0;
    virtual void a91() = 0;
    virtual void a92() = 0;
    virtual void a93() = 0;
    virtual void a94() = 0;
    virtual void a95() = 0;
    virtual void a96() = 0;
    virtual void a97() = 0;
    virtual void a98() = 0;
    virtual void a99() = 0;
    virtual void SetAV(int, float) = 0;
    char _pad[252];
};
struct StandIn : FakePrimary, FakeAVOwner
{
    void FUN_005f7520(int, float);
};
// Adds aiValue to the actor value aiWhich by reading GetAV and writing the sum back with SetAV.
// @fnv 0x005f7520
void StandIn::FUN_005f7520(int aiWhich, float aiValue)
{
    SetAV(aiWhich, GetAV(aiWhich) + aiValue);
}

struct FUN_0050f6f0
{
    FUN_0050f6f0();
    ~FUN_0050f6f0();
    virtual void v0();
    int d[11];
};
struct FUN_0047c700
{
    FUN_0047c700();
    ~FUN_0047c700();
    virtual void v0();
    int d[12];
};
struct FUN_00481610
{
    FUN_00481610();
    ~FUN_00481610();
    virtual void v0();
    int d[2];
};
struct FUN_0047bd10
{
    FUN_0047bd10();
    virtual void v0();
    int d[2];
};
struct FUN_0048cfe0
{
    FUN_0048cfe0();
    ~FUN_0048cfe0();
    virtual void v0();
    int d[4];
};
struct FUN_0047ec40
{
    FUN_0047ec40();
    ~FUN_0047ec40();
    virtual void v0();
    int d[7];
};
struct FUN_004871d0
{
    FUN_004871d0();
    ~FUN_004871d0();
    virtual void v0();
    int d[1];
};
struct FUN_0047ff70
{
    FUN_0047ff70();
    ~FUN_0047ff70();
    virtual void v0();
    int d[2];
};
struct FUN_0047f9c0
{
    FUN_0047f9c0();
    ~FUN_0047f9c0();
    virtual void v0();
    int d[2];
};
struct FUN_00402d00
{
    FUN_00402d00();
    ~FUN_00402d00();
    virtual void v0();
    int d[2];
};
struct FUN_00488f50
{
    FUN_00488f50();
    ~FUN_00488f50();
    virtual void v0();
    int d[5];
};
struct FUN_0048cc50
{
    FUN_0048cc50();
    virtual void v0();
    int d[2];
};
struct FUN_005f78e0
{
    FUN_005f78e0();
    virtual void v0();
};
struct FUN_00475350
{
    FUN_00475350();
    virtual void v0();
    int d[1];
};

struct FUN_005f75e0 : public FUN_0050f6f0,
                      public FUN_0047c700,
                      public FUN_00481610,
                      public FUN_0047bd10,
                      public FUN_0048cfe0,
                      public FUN_0047ec40,
                      public FUN_004871d0,
                      public FUN_0047ff70,
                      public FUN_0047f9c0,
                      public FUN_00402d00,
                      public FUN_00488f50,
                      public FUN_0048cc50,
                      public FUN_005f78e0,
                      public FUN_00475350
{
    FUN_005f75e0();
};

// Empty constructor that initializes the object's base subobjects.
// @fnv 0x005f75e0
FUN_005f75e0::FUN_005f75e0()
{}

struct FUN_005f0b30_shell
{
    void FUN_005f0b30(int);
};

struct FUN_005f12d0_AIForm
{
    void SetAttribute5(unsigned char);
    void FUN_005f14d0(unsigned char);
    void FUN_005f14f0(unsigned char);
    void FUN_005f1510(unsigned char);
    void FUN_005f1530(unsigned char);
    void SetAttribute(unsigned char);
    void FUN_005f1570(unsigned char);
};

struct FUN_005f12d0_ActorBase
{
    void SetSpeedMult(unsigned short);
    void SetKarmaValue(float);
};

struct FUN_005f12d0_MoodForm
{
    void SetAIMood(unsigned char);
};

struct FUN_005f12d0_shell : public FUN_005f0b30_shell
{
    void ApplyCommand(int, int);
};

// Dispatches a command code to the matching setter on the AI form, mood form, actor base or base shell, passing value as the argument.
// @fnv 0x005f12d0
void FUN_005f12d0_shell::ApplyCommand(int command, int value)
{
    switch (command)
    {
    case 5:
        ((FUN_005f12d0_AIForm*)((char*)this + 0xb8))->SetAttribute5((unsigned char)value);
        break;
    case 6:
        ((FUN_005f12d0_AIForm*)((char*)this + 0xb8))->FUN_005f14d0((unsigned char)value);
        break;
    case 7:
        ((FUN_005f12d0_AIForm*)((char*)this + 0xb8))->FUN_005f14f0((unsigned char)value);
        break;
    case 8:
        ((FUN_005f12d0_AIForm*)((char*)this + 0xb8))->FUN_005f1510((unsigned char)value);
        break;
    case 9:
        ((FUN_005f12d0_AIForm*)((char*)this + 0xb8))->FUN_005f1530((unsigned char)value);
        break;
    case 10:
        ((FUN_005f12d0_AIForm*)((char*)this + 0xb8))->SetAttribute((unsigned char)value);
        break;
    case 11:
        ((FUN_005f12d0_AIForm*)((char*)this + 0xb8))->FUN_005f1570((unsigned char)value);
        break;
    case 16:
        this->FUN_005f0b30(value);
        break;
    case 0:
        ((TESAIForm*)((char*)this + 0x90))->SetAggression((unsigned char)value, true);
        break;
    case 1:
        ((TESAIForm*)((char*)this + 0x90))->SetConfidence((unsigned char)value, true);
        break;
    case 2:
        ((TESAIForm*)((char*)this + 0x90))->SetEnergy((unsigned char)value, true);
        break;
    case 3:
        ((TESAIForm*)((char*)this + 0x90))->SetResponsibility((unsigned char)value, true);
        break;
    case 4:
        ((FUN_005f12d0_MoodForm*)((char*)this + 0x90))->SetAIMood((unsigned char)value);
        break;
    case 21:
        ((FUN_005f12d0_ActorBase*)((char*)this + 0x30))->SetSpeedMult((unsigned short)value);
        break;
    case 23:
        ((FUN_005f12d0_ActorBase*)((char*)this + 0x30))->SetKarmaValue((float)value);
        break;
    default:
        break;
    }
}

namespace fnv_005fa200 {
struct ActorValue
{
    enum Index
    {
        index_0 = 0
    };
};

struct P09AV
{
    static bool __cdecl GetFlag(int flag, unsigned int value);
};

struct FUN_0047ff50_class
{
    void FUN_0047ff50(unsigned short value);
};

struct FUN_005fa2c0_shell
{
    void SetByteAt12D(unsigned char value);
};

struct FUN_006078e0_s
{
    void ApplyCommand(ActorValue::Index index, int value);
};

struct FUN_005fa200_shell
{
    virtual void vfn_00()
    {}
    virtual void vfn_01()
    {}
    virtual void vfn_02()
    {}
    virtual void vfn_03()
    {}
    virtual void vfn_04()
    {}
    virtual void vfn_05()
    {}
    virtual void vfn_06()
    {}
    virtual void vfn_07()
    {}
    virtual void vfn_08()
    {}
    virtual void vfn_09()
    {}
    virtual void vfn_10()
    {}
    virtual void vfn_11()
    {}
    virtual void vfn_12()
    {}
    virtual void vfn_13()
    {}
    virtual void vfn_14()
    {}
    virtual void vfn_15()
    {}
    virtual void vfn_16()
    {}
    virtual void vfn_17()
    {}
    virtual void vfn_18(int value)
    {}

    void FUN_005fa200(ActorValue::Index index, int value);
};

// @fnv 0x005fa200
void FUN_005fa200_shell::FUN_005fa200(ActorValue::Index index, int value)
{
    if (P09AV::GetFlag(index, 0x400))
    {
        reinterpret_cast<FUN_005fa2c0_shell*>(this)->SetByteAt12D(static_cast<unsigned char>(value));
        vfn_18(0x200);
    }
    else
    {
        switch (index)
        {
        case static_cast<ActorValue::Index>(0x38):
            if (value < 0)
            {
                reinterpret_cast<FUN_0047ff50_class*>(reinterpret_cast<char*>(this) + 0x10c)->FUN_0047ff50(0);
            }
            else if (value > 0xffff)
            {
                reinterpret_cast<FUN_0047ff50_class*>(reinterpret_cast<char*>(this) + 0x10c)->FUN_0047ff50(0xffff);
            }
            else
            {
                reinterpret_cast<FUN_0047ff50_class*>(reinterpret_cast<char*>(this) + 0x10c)
                    ->FUN_0047ff50(static_cast<unsigned short>(value));
            }
            break;

        default:
            reinterpret_cast<FUN_006078e0_s*>(this)->ApplyCommand(index, value);
            break;
        }
    }
}
}  // namespace fnv_005fa200

struct FUN_00608e00_shell
{
    void FUN_005f18c0(unsigned int);
};

struct PC7d
{
    void FUN_00484ce0(unsigned int, int);
};

struct FUN_00484d20_Class
{
    void ForwardToSaveLoadGame(int, int);
};

unsigned int __fastcall _ref_0084e3a0(unsigned int);

struct FUN_005fb1e0_shell
{
    void FUN_005fb1e0(unsigned int);
};

// @fnv 0x005fb1e0
void FUN_005fb1e0_shell::FUN_005fb1e0(unsigned int flags)
{
    reinterpret_cast<FUN_00608e00_shell*>(this)->FUN_005f18c0(flags);

    if (flags & 0x200)
    {
        reinterpret_cast<PC7d*>(this)->FUN_00484ce0(
            reinterpret_cast<unsigned int>(reinterpret_cast<unsigned char*>(this) + 0x12d), 1);
        reinterpret_cast<PC7d*>(this)->FUN_00484ce0(
            reinterpret_cast<unsigned int>(reinterpret_cast<unsigned char*>(this) + 0x12e), 1);
        reinterpret_cast<PC7d*>(this)->FUN_00484ce0(
            reinterpret_cast<unsigned int>(reinterpret_cast<unsigned char*>(this) + 0x12f), 1);
    }

    if (flags & 0)
    {
        unsigned int result =
            _ref_0084e3a0(*reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(this) + 0x140));
        reinterpret_cast<FUN_00484d20_Class*>(this)->ForwardToSaveLoadGame(reinterpret_cast<int>(&result), 4);
    }
}

class CreatureBaseSub_b3926
{
  public:
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
    ~CreatureBaseSub_b3926();
};

class CreatureMemberA_b3926
{
  public:
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
    ~CreatureMemberA_b3926();
};

class CreatureMemberB_b3926
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    ~CreatureMemberB_b3926();
};

class CreatureMemberC_b3926
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    ~CreatureMemberC_b3926();
};

class CreatureMemberD_b3926
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    ~CreatureMemberD_b3926();
};

class CreatureMemberE_b3926
{
  public:
    int unk00;
    int unk04;
    ~CreatureMemberE_b3926();
};

class CreatureMemberF_b3926
{
  public:
    int unk00;
    int unk04;
    int unk08;
    ~CreatureMemberF_b3926();
};

class CreatureMemberG_b3926
{
  public:
    int unk00;
    int unk04;
    int unk08;
    ~CreatureMemberG_b3926();
};

class CreatureMemberH_b3926
{
  public:
    int unk00;
    int unk04;
    int unk08;
    ~CreatureMemberH_b3926();
};

class CreatureMemberI_b3926
{
  public:
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
    ~CreatureMemberI_b3926();
};

class CreatureMemberJ_b3926
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    ~CreatureMemberJ_b3926();
};

class FUN_005f77b0 : public CreatureBaseSub_b3926
{
  public:
    CreatureMemberA_b3926 m_30;
    CreatureMemberB_b3926 m_64;
    CreatureMemberC_b3926 m_7c;
    CreatureMemberD_b3926 m_90;
    CreatureMemberE_b3926 m_b0;
    CreatureMemberF_b3926 m_b8;
    CreatureMemberG_b3926 m_c4;
    CreatureMemberH_b3926 m_d0;
    CreatureMemberI_b3926 m_dc;
    CreatureMemberJ_b3926 m_104;
    ~FUN_005f77b0();
};

// @fnv 0x005f77b0
FUN_005f77b0::~FUN_005f77b0()
{}

struct FormObj_5f7c20
{
    unsigned int FUN_0084e3a0();
};

struct SoundsObj_5f7c20
{
    void FUN_005f03a0();
};

struct Sub30_5f7c20
{
    int u00, u04, u08, u0c, u10, u14, u18, u1c, u20, u24, u28, u2c, u30;
    void DestroySoundHandles();
    bool FUN_00461580(unsigned int) const;
};

struct Sub64_5f7c20
{
    int u00, u04, u08;
};

struct Sub70_5f7c20
{
    int u00, u04, u08;
    void FUN_0047bd70();
};

struct Sub7c_5f7c20
{
    int u00, u04, u08, u0c, u10;
    void FUN_0048d330();
};

struct Sub90_5f7c20
{
    int u00, u04, u08, u0c, u10, u14, u18, u1c;
    int u20, u24;
    int u28, u2c, u30;
    int u34, u38, u3c;
};

struct Subd0_5f7c20
{
    int u00, u04, u08;
    void FUN_00487010();
};

struct Subdc_5f7c20
{
    int u00, u04, u08, u0c, u10, u14;
    int u18, u1c, u20;
    int u24;
    void WriteToBuffer(unsigned int, unsigned int);
};

struct Sub104_5f7c20
{
    int u00, u04;
    int u08, u0c;
    void FUN_00477f20();
};

struct Sub114_5f7c20
{
    int u00, u04, u08, u0c, u10;
    void CopyModelListToBuffer(unsigned int, unsigned int);
};

struct Sub12c_5f7c20
{
    int u00;
    void FUN_00483710();
};

bool __cdecl FUN_00401500();
void __cdecl FUN_004858f0(unsigned int, unsigned char);
void __cdecl FUN_00485910(unsigned int, unsigned int);
void __cdecl FUN_00485910(unsigned int, float);
void __cdecl FUN_00485910(unsigned int, int);

struct Host_5f7c20
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
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
    virtual FormObj_5f7c20* v96();
    virtual void v97();
    virtual FormObj_5f7c20* v98();

    int u04, u08, u0c, u10, u14, u18, u1c, u20, u24, u28, u2c;
    Sub30_5f7c20 m_30;
    Sub64_5f7c20 m_64;
    Sub70_5f7c20 m_70;
    Sub7c_5f7c20 m_7c;
    Sub90_5f7c20 m_90;
    Subd0_5f7c20 m_d0;
    Subdc_5f7c20 m_dc;
    Sub104_5f7c20 m_104;
    Sub114_5f7c20 m_114;
    int m_128;
    Sub12c_5f7c20 m_12c;
    unsigned char m_130;
    unsigned char m_131;
    unsigned char m_132;
    unsigned char m_133;
    float m_134;
    float m_138;
    float m_13c;
    int m_140;
    int m_144;
    int m_148;
    FormObj_5f7c20* m_14c;
    int m_150;
    int m_154;
    FormObj_5f7c20* m_158;

    void FUN_004855a0();
    void FUN_00485e20(void*, int);
    SoundsObj_5f7c20* FUN_005f91d0();
    FormObj_5f7c20* FUN_005f9100();
    void FUN_00485680();
    void Init();
};

// @fnv 0x005f7c20
void Host_5f7c20::Init()
{
    FUN_004855a0();
    m_d0.FUN_00487010();
    m_dc.WriteToBuffer(0x4c444f4d, 0x54444f4d);
    m_7c.FUN_0048d330();
    m_70.FUN_0047bd70();
    m_114.CopyModelListToBuffer(0x5a46494e, 0x5446494e);
    m_30.DestroySoundHandles();
    m_104.FUN_00477f20();
    if (FUN_00401500())
    {
        m_12c.FUN_00483710();
    }
    FUN_00485e20(&m_12c, 4);
    if (FUN_00401500())
    {
        m_12c.FUN_00483710();
    }
    FUN_004858f0(0x4d414e52, m_130);
    if (v98())
    {
        FUN_00485910(0x4d414e5a, v98()->FUN_0084e3a0());
    }
    if (v96())
    {
        FUN_00485910(0x4d414e50, v96()->FUN_0084e3a0());
    }
    FUN_00485910(0x4d414e54, m_134);
    FUN_00485910(0x4d414e42, m_13c);
    FUN_00485910(0x4d414e57, m_138);
    FUN_00485910(0x344d414e, m_148);
    FUN_00485910(0x354d414e, m_154);
    if (m_30.FUN_00461580(0x100))
    {
        SoundsObj_5f7c20* sounds = FUN_005f91d0();
        if (sounds)
        {
            sounds->FUN_005f03a0();
        }
    }
    else
    {
        FormObj_5f7c20* soundCreature = FUN_005f9100();
        if (soundCreature)
        {
            unsigned int soundId = soundCreature->FUN_0084e3a0();
            FUN_00485910(0x52435343, soundId);
        }
    }
    if (m_14c)
    {
        unsigned int impactId = m_14c->FUN_0084e3a0();
        FUN_00485910(0x4d414e43, impactId);
    }
    if (m_158)
    {
        unsigned int weaponId = m_158->FUN_0084e3a0();
        FUN_00485910(0x4d414e4c, weaponId);
    }
    FUN_00485680();
}

extern "C" void* _alloca(unsigned int);
void* operator new(unsigned int);
void operator delete(void*);
void* FUN_00403d30(void*, int, unsigned int);
struct CreatureRecordFile
{
    unsigned char FUN_00472660();
    int FUN_004726b0();
    bool FUN_004726f0();
    unsigned int GetField25C();
    bool FUN_00401680();
    unsigned short FUN_00403570();
    void GetChunkData(void*, unsigned int);
    void ReadChunkInt(void*);
    void ReadChunkData(void*);
};
struct CreatureContainerEntry
{
    unsigned int form;
    int count;
    void FUN_00462230();
};
struct CreatureFactionEntry
{
    unsigned int faction;
    unsigned char rank;
    unsigned char unk05;
    unsigned short unk06;
    void FUN_00503210();
};
struct CreatureAIData
{
    unsigned char aggression, confidence, energy, responsibility;
    unsigned int services;
    unsigned char trainingSkill, trainingLevel;
    unsigned short unk0A;
    unsigned char unk0C, unk0D, mood, unk0F;
    unsigned int unk10;
    void SwapEndianFields();
};
struct CreatureBaseData
{
    unsigned int flags;
    unsigned short fatigue, level;
    unsigned short minLevel, maxLevel;
    unsigned short speed, karma;
    unsigned int disposition;
    unsigned short unknown, templateFlags;
    void SwapEndianness();
};
struct FUN_0040e690
{
    unsigned int owner, global, condition;
    FUN_0040e690();
    void FUN_0040e780(CreatureRecordFile*);
};
struct LastContainerItem
{
    unsigned int object;
    unsigned int count;
    FUN_0040e690* extra;
};
extern LastContainerItem* DAT_011cb5f8;
struct CreatureSoundsLoad
{
    bool FUN_005f0480(CreatureRecordFile*, int, void*);
};
struct CreaturePrimary
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void LoadBounds(CreatureRecordFile*);
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual const char* GetName();
    virtual void SetEditorID(const char*);
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void SetCombatStyle(unsigned int);
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
};
struct CreatureActorComponent
{
    virtual void slot0();
    void FUN_0047d800(unsigned int, unsigned char);
    unsigned short GetShortAtOffset12();
    CreatureBaseData data;
    unsigned int deathItem;
    unsigned int voice;
    unsigned int templateForm;
    unsigned int unk28, unk2C, unk30;
};
struct CreatureContainerComponent
{
    virtual void slot0();
    LastContainerItem* AddContainerObject(CreatureContainerEntry*);
    unsigned int unk04;
    unsigned int unk08;
};
struct CreatureTouchComponent
{
    virtual void slot0();
    void FUN_006ecd40(unsigned int);
    void FUN_00483170(unsigned short);
    unsigned int unk04;
    unsigned int unk08;
};
struct CreatureSpellComponent
{
    virtual void slot0();
    void FUN_0048d290(unsigned int);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
};
struct CreatureAIComponent
{
    virtual void slot0();
    void FUN_0047f0b0(CreatureAIData*);
    void FUN_0047f500(unsigned int);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
};
struct CreatureHealthComponent
{
    virtual void slot0();

    unsigned int unk04;
};
struct CreatureAttributesComponent
{
    virtual void slot0();

    unsigned int unk04;
    unsigned int unk08;
};
struct CreatureAnimationComponent
{
    virtual void slot0();
    void FUN_0047faa0(CreatureAnimationComponent*, CreatureRecordFile*);
    unsigned int unk04;
    unsigned int unk08;
};
struct CreatureNameComponent
{
    virtual void slot0();

    unsigned int unk04;
    unsigned int unk08;
};
struct CreatureModelComponent
{
    virtual void slot0();

    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
};
struct CreatureScriptComponent
{
    virtual void slot0();
    void FUN_006ecd40(unsigned int);
    void FUN_0048cd90(void*);
    unsigned int unk04;
    unsigned int unk08;
};
struct CreatureAVComponent
{
    virtual void slot0();
};
struct CreatureDestructionComponent
{
    virtual void slot0();

    unsigned int unk04;
};
struct CreatureAttackComponent
{
    virtual void slot0();

    unsigned int unk04;
};
struct CreatureModelsComponent
{
    virtual void slot0();
    void LoadStringChunk(CreatureModelsComponent*, CreatureRecordFile*);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
};
void ReadFullName(CreatureNameComponent*, CreatureRecordFile*);
void FUN_004892d0(CreatureModelComponent*, CreatureRecordFile*);
void FUN_004781e0(CreatureDestructionComponent*, CreatureRecordFile*);
extern const char DAT_0104947c[];
void FUN_005b5e40(const char*, ...);
struct CreatureRecord : CreaturePrimary,
                        CreatureActorComponent,
                        CreatureContainerComponent,
                        CreatureTouchComponent,
                        CreatureSpellComponent,
                        CreatureAIComponent,
                        CreatureHealthComponent,
                        CreatureAttributesComponent,
                        CreatureAnimationComponent,
                        CreatureNameComponent,
                        CreatureModelComponent,
                        CreatureScriptComponent,
                        CreatureAVComponent,
                        CreatureDestructionComponent,
                        CreatureAttackComponent,
                        CreatureModelsComponent
{
    unsigned int sounds;
    unsigned char type, aggression, confidence, energy;
    unsigned char reach, unk131;
    unsigned short unk132;
    float turnSpeed, footWeight, scale;
    unsigned int combatStyle, bodyParts;
    unsigned int bloodMaterial, impactData, unk150, soundLevel, weaponList;
    void CallWithThis(CreatureRecordFile*);
    void FUN_00484ab0(bool);
    void FUN_004861f0(CreatureRecordFile*, void*, unsigned int);
    void FUN_005f9140(unsigned int);
    CreatureSoundsLoad* FUN_005f9210();
    void SetImpactDataSet(unsigned int);
    void FUN_005f8bd0(unsigned int);
    unsigned int FUN_0084e3a0();
    bool FUN_005f7ec0(CreatureRecordFile*);
};
// Reads a creature record from the file, dispatching each chunk to the matching component loader, and returns true when the record type is 43.
// @fnv 0x005f7ec0
bool CreatureRecord::FUN_005f7ec0(CreatureRecordFile* file)
{
    unsigned char formType = file->FUN_00472660();
    if (formType != 43)
        return false;
    CallWithThis(file);
    FUN_00484ab0(false);
    int soundType = -1;
    int chunk;
    bool consumed5;
    bool valid4;
    while ((chunk = file->FUN_004726b0()) != 0)
    {
        consumed5 = false;
        valid4 = true;
        switch (chunk)
        {
        case 0x44494445: {  // EDID
            char* editorID = (char*)_alloca(file->GetField25C());
            file->GetChunkData(editorID, 512);
            SetEditorID(editorID);
            break;
        }
        case 0x444e424f:
            LoadBounds(file);
            break;
        case 0x4c4c5546:
            ReadFullName(this, file);
            break;
        case 0x4c444f4d:
        case 0x54444f4d:
            FUN_004892d0(this, file);
            break;
        case 0x49524353: {
            unsigned int scriptID = 0;
            file->ReadChunkInt(&scriptID);
            CreatureScriptComponent::FUN_006ecd40(scriptID);
            CreatureScriptComponent::FUN_0048cd90(this);
            break;
        }
        case 0x4f544e43:
        case 0x44454f43:
            switch (file->FUN_004726b0())
            {
            case 0x4f544e43: {
                CreatureContainerEntry item;
                FUN_00403d30(&item, 0, 8);
                file->GetChunkData(&item, 8);
                if (file->FUN_00401680())
                    item.FUN_00462230();
                DAT_011cb5f8 = CreatureContainerComponent::AddContainerObject(&item);
                break;
            }
            case 0x44454f43:
                if (DAT_011cb5f8)
                {
                    DAT_011cb5f8->extra = new FUN_0040e690;
                    DAT_011cb5f8->extra->FUN_0040e780(file);
                    DAT_011cb5f8 = 0;
                }
                break;
            }
            break;
        case 0x4f4c5053: {
            unsigned int spellID = 0;
            file->ReadChunkInt(&spellID);
            CreatureSpellComponent::FUN_0048d290(spellID);
            break;
        }
        case 0x4d544945: {
            unsigned int touchID = 0;
            file->ReadChunkInt(&touchID);
            CreatureTouchComponent::FUN_006ecd40(touchID);
            break;
        }
        case 0x544d4145: {
            unsigned short touchAmount = 0;
            file->ReadChunkData(&touchAmount);
            CreatureTouchComponent::FUN_00483170(touchAmount);
            break;
        }
        case 0x54444941: {
            CreatureAIData ai;
            FUN_00403d30(&ai, 0, 20);
            file->GetChunkData(&ai, 20);
            if (file->FUN_00401680())
                ai.SwapEndianFields();
            if (file->FUN_00403570() < 4 && ai.aggression > 1)
                ++ai.aggression;
            if (file->FUN_00403570() < 6)
            {
                switch (ai.aggression)
                {
                case 0:
                    ai.mood = 0;
                    break;
                case 1:
                    ai.aggression = 0;
                    ai.mood = 1;
                    break;
                case 2:
                    ai.aggression = 1;
                    ai.mood = 1;
                    break;
                case 3:
                    ai.aggression = 1;
                    ai.mood = 2;
                    break;
                case 4:
                    ai.aggression = 2;
                    ai.mood = 2;
                    break;
                case 5:
                    ai.aggression = 3;
                    ai.mood = 0;
                    break;
                }
            }
            if (file->FUN_00403570() < 7)
                ai.confidence = 4 - ai.confidence;
            CreatureAIComponent::FUN_0047f0b0(&ai);
            break;
        }
        case 0x44494b50: {
            unsigned int packageID = 0;
            file->ReadChunkInt(&packageID);
            CreatureAIComponent::FUN_0047f500(packageID);
            break;
        }
        case 0x4d414e53: {
            CreatureFactionEntry faction;
            FUN_00403d30(&faction, 0, 8);
            file->GetChunkData(&faction, 8);
            if (file->FUN_00401680())
                faction.FUN_00503210();
            CreatureActorComponent::FUN_0047d800(faction.faction, faction.rank);
            break;
        }
        case 0x4d414e49: {
            unsigned int deathID = 0;
            file->ReadChunkInt(&deathID);
            deathItem = deathID;
            break;
        }
        case 0x4b435456: {
            unsigned int voiceID;
            file->ReadChunkInt(&voiceID);
            voice = voiceID;
            break;
        }
        case 0x544c5054: {
            unsigned int templateID;
            file->ReadChunkInt(&templateID);
            templateForm = templateID;
            break;
        }
        case 0x53424341:
            file->GetChunkData(&data, 24);
            if (file->FUN_00401680())
                data.SwapEndianness();
            if (file->FUN_00403570() < 8)
                data.templateFlags = 0;
            data.level = 0;
            break;
        case 0x5a46464b:
            CreatureAnimationComponent::FUN_0047faa0(this, file);
            break;
        case 0x5a46494e:
        case 0x5446494e:
            CreatureModelsComponent::LoadStringChunk(this, file);
            break;
        case 0x54534544:
        case 0x44545344:
            FUN_004781e0(this, file);
            break;
        case 0x41544144:
            FUN_004861f0(file, &type, 4);
            break;
        case 0x304d414e: {
            if (file->GetField25C())
            {
                char* model = (char*)_alloca(file->GetField25C());
                file->GetChunkData(model, 0);
            }
            break;
        }
        case 0x314d414e: {
            if (file->GetField25C())
            {
                char* model2 = (char*)_alloca(file->GetField25C());
                file->GetChunkData(model2, 0);
            }
            break;
        }
        case 0x4d414e42:
            file->ReadChunkInt(&scale);
            break;
        case 0x4d414e57:
            file->ReadChunkInt(&footWeight);
            break;
        case 0x4d414e54:
            file->ReadChunkInt(&turnSpeed);
            break;
        case 0x344d414e: {
            unsigned int material;
            file->ReadChunkInt(&material);
            bloodMaterial = material;
            break;
        }
        case 0x354d414e: {
            unsigned int level;
            file->ReadChunkInt(&level);
            if (level > 3)
                soundLevel = 1;
            else
                soundLevel = level;
            break;
        }
        case 0x4d414e52: {
            if (file->GetField25C() == 4)
            {
                unsigned int oldReach = 0;
                file->ReadChunkInt(&oldReach);
                reach = (unsigned char)oldReach;
            }
            else
                file->GetChunkData(&reach, 1);
            break;
        }
        case 0x52435343: {
            unsigned int soundCreature = 0;
            file->ReadChunkInt(&soundCreature);
            FUN_005f9140(soundCreature);
            break;
        }
        case 0x54445343: {
            int newSoundType;
            file->ReadChunkInt(&newSoundType);
            soundType = newSoundType;
            break;
        }
        case 0x49445343:
        case 0x46445343: {
            CreatureSoundsLoad* loadedSounds = FUN_005f9210();
            if (!loadedSounds->FUN_005f0480(file, soundType, this))
                consumed5 = true;
            break;
        }
        case 0x4d414e5a: {
            unsigned int combat;
            file->ReadChunkInt(&combat);
            SetCombatStyle(combat);
            break;
        }
        case 0x4d414e50: {
            unsigned int parts;
            file->ReadChunkInt(&parts);
            bodyParts = parts;
            break;
        }
        case 0x4d414e43: {
            unsigned int impact = 0;
            file->ReadChunkInt(&impact);
            SetImpactDataSet(impact);
            break;
        }
        case 0x4d414e4c: {
            unsigned int weapons = 0;
            file->ReadChunkInt(&weapons);
            FUN_005f8bd0(weapons);
            break;
        }
        }
        if (!valid4)
            break;
        if (!consumed5 && !file->FUN_004726f0())
            break;
    }
    if (!CreatureActorComponent::GetShortAtOffset12())
        FUN_005b5e40(DAT_0104947c, GetName(), FUN_0084e3a0());
    return true;
}

struct FUN_005f8d70_runtime : FUN_00843150_shell
{
    void* FUN_00600700(void*);
};
extern FUN_005f8d70_runtime* DAT_011cb6a0;
struct FUN_005f8d70_virtual
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void* v5(unsigned int);
};
struct FUN_005f8d70_record
{
    int* FUN_006815c0();
};
struct FUN_005f8d70_actor : FUN_0047ded0_shell
{
    bool FUN_00461560();
};
struct FUN_005f8d70_settings
{
    float* FUN_00403e20();
};
extern FUN_005f8d70_settings DAT_011cb58c;
struct FUN_005f8d70_shell
{
    unsigned short FUN_0047ff30();
    unsigned short FUN_005f8d70();
};
// @fnv 0x005f8d70
unsigned short FUN_005f8d70_shell::FUN_005f8d70()
{
    unsigned short result = 0;
    if (DAT_011cb6a0->FUN_00843150() && !g_dataHandler->FUN_004516b0() &&
        reinterpret_cast<signed char*>(this)[0x50] == -1)
    {
        FUN_005f8d70_record* record = static_cast<FUN_005f8d70_record*>(DAT_011cb6a0->FUN_00600700(
            reinterpret_cast<FUN_005f8d70_virtual*>(reinterpret_cast<char*>(this) - 0x30)->v5(1)));
        if (record == 0 || *record->FUN_006815c0() == 0)
            reinterpret_cast<signed char*>(this)[0x50] = 0;
        else
            reinterpret_cast<signed char*>(this)[0x50] = 1;
    }
    if (reinterpret_cast<signed char*>(this)[0x50] == 0)
        return 0;
    if (reinterpret_cast<FUN_005f8d70_actor*>(reinterpret_cast<char*>(this) - 0xdc)->FUN_00461560())
    {
        short level = reinterpret_cast<FUN_005f8d70_actor*>(reinterpret_cast<char*>(this) - 0xdc)->FUN_0047ded0();
        if (level < 1)
            level = 1;
        result = FUN_0047ff30();
        result += static_cast<int>(static_cast<double>(level) * *DAT_011cb58c.FUN_00403e20());
    }
    else
    {
        result = FUN_0047ff30();
    }
    return result;
}

class TESBoundObject;
class BaseProcess
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
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
    virtual void ClearEquipment(void*, void*, void*);
    virtual void ClearWeapon(void*);
    virtual void ClearAmmo(void*);
    virtual void ClearOther(void*);
};
class TESObjectREFR
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
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
    virtual void EquipItem(TESBoundObject*, int, void*, bool);
    void FUN_00571b50();
    bool FUN_00575400(TESBoundObject*);
    void UpdateSpells(bool);
};
class Actor : public TESObjectREFR
{
  public:
    BaseProcess* GetCurrentAIProcess() const;
};
struct ExtraDataList;
struct ExtraDataNode
{
    ExtraDataList*& FUN_006815c0();
};
struct InventoryEntryData
{
    TESBoundObject* FUN_0044ddc0();
    ExtraDataNode* FUN_00559450();
    int FUN_00726070();
    ~InventoryEntryData();
};
class InventoryChanges
{
  public:
    static InventoryChanges* GetOrAddInventoryChanges(TESObjectREFR*);
    void RemoveWornItems(bool, TESObjectREFR*);
    InventoryEntryData* SelectBestWeapon(TESCreature*, float*, int, bool);
};
struct BGSSaveLoadGame
{
    bool SetThreadAllowChanges(bool);
};
extern BGSSaveLoadGame* g_BGSSaveLoadGame;
struct CreatureEquipment : TESCreature
{
    bool FUN_005fa120(TESBoundObject*);
    void FUN_005f9e00(TESObjectREFR*, int, bool, bool);
};

// @fnv 0x005f9e00
void CreatureEquipment::FUN_005f9e00(TESObjectREFR* reference, int unused, bool equip, bool allowChanges)
{
    bool savedVal = true;
    if (!allowChanges)
        savedVal = g_BGSSaveLoadGame->SetThreadAllowChanges(false);
    if (reference->IsActor())
        reference->FUN_00571b50();
    InventoryChanges* entry = InventoryChanges::GetOrAddInventoryChanges(reference);
    entry->RemoveWornItems(true, reference);
    Actor* actor = dynamic_cast<Actor*>(reference);
    if (actor && actor->GetCurrentAIProcess())
    {
        actor->GetCurrentAIProcess()->ClearAmmo(0);
        actor->GetCurrentAIProcess()->ClearOther(0);
        actor->GetCurrentAIProcess()->ClearWeapon(0);
        actor->GetCurrentAIProcess()->ClearEquipment(0, 0, 0);
    }
    InventoryEntryData* weapon = 0;
    InventoryEntryData* aWeapon = 0;
    float value = 0.0f;
    if (equip && entry)
        weapon = entry->SelectBestWeapon(this, &value, 6, true);
    if (weapon && FUN_005fa120(weapon->FUN_0044ddc0()) && !reference->FUN_00575400(weapon->FUN_0044ddc0()))
    {
        reference->EquipItem(weapon->FUN_0044ddc0(), 1, 0, false);
        if (aWeapon && !reference->FUN_00575400(aWeapon->FUN_0044ddc0()))
        {
            ExtraDataList* extra = 0;
            if (aWeapon->FUN_00559450())
                extra = aWeapon->FUN_00559450()->FUN_006815c0();
            reference->EquipItem(aWeapon->FUN_0044ddc0(), aWeapon->FUN_00726070(), extra, false);
        }
    }
    delete weapon;
    delete aWeapon;
    if (!allowChanges)
        g_BGSSaveLoadGame->SetThreadAllowChanges(savedVal);
    if (actor && actor->GetCurrentAIProcess())
        actor->UpdateSpells(true);
}

namespace fnv_008b4d10 {
struct CreatureView
{
    bool FUN_005fbf20() const;
};
struct Part
{
    bool IsFlag40Set();
    bool FUN_008b4360();
    unsigned char GetByte65();
    signed char GetByte63();
    bool FUN_008b5190();
};
struct Body
{
    Part* GetValueByIndex(int);
};
struct BaseView
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
    virtual Body* GetBody();
};
struct Node
{
    bool FUN_00456610();
};
struct Process
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
    virtual void v241();
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
    virtual void v308();
    virtual void v309();
    virtual void v310();
    virtual void v311();
    virtual void v312();
    virtual void v313();
    virtual void v314();
    virtual void v315();
    virtual void v316();
    virtual void v317();
    virtual void v318();
    virtual void v319();
    virtual void v320();
    virtual void v321();
    virtual void v322();
    virtual void v323();
    virtual void v324();
    virtual void v325();
    virtual void v326();
    virtual void v327();
    virtual void v328();
    virtual void v329();
    virtual void v330();
    virtual void v331();
    virtual void v332();
    virtual void v333();
    virtual void v334();
    virtual void v335();
    virtual void v336();
    virtual void v337();
    virtual void v338();
    virtual void v339();
    virtual void v340();
    virtual void v341();
    virtual void v342();
    virtual void v343();
    virtual void v344();
    virtual void v345();
    virtual void v346();
    virtual void v347();
    virtual void v348();
    virtual void v349();
    virtual void v350();
    virtual void v351();
    virtual void v352();
    virtual void v353();
    virtual void v354();
    virtual void v355();
    virtual void v356();
    virtual void v357();
    virtual void v358();
    virtual void v359();
    virtual void v360();
    virtual void v361();
    virtual void v362();
    virtual void v363();
    virtual void v364();
    virtual void v365();
    virtual void v366();
    virtual void v367();
    virtual void v368();
    virtual void v369();
    virtual void v370();
    virtual void v371();
    virtual void v372();
    virtual void v373();
    virtual void v374();
    virtual void v375();
    virtual void v376();
    virtual void v377();
    virtual void v378();
    virtual void v379();
    virtual void v380();
    virtual void v381();
    virtual void v382();
    virtual void v383();
    virtual void v384();
    virtual void v385();
    virtual void v386();
    virtual void v387();
    virtual void v388();
    virtual void v389();
    virtual void v390();
    virtual void v391();
    virtual void v392();
    virtual void v393();
    virtual void v394();
    virtual void v395();
    virtual void v396();
    virtual void v397();
    virtual void v398();
    virtual void v399();
    virtual void v400();
    virtual void v401();
    virtual void v402();
    virtual void v403();
    virtual void v404();
    virtual void v405();
    virtual void v406();
    virtual void v407();
    virtual void v408();
    virtual void v409();
    virtual void v410();
    virtual void v411();
    virtual void v412();
    virtual void v413();
    virtual void v414();
    virtual void v415();
    virtual void v416();
    virtual void v417();
    virtual void v418();
    virtual void v419();
    virtual void v420();
    virtual void v421();
    virtual void v422();
    virtual void v423();
    virtual void v424();
    virtual void v425();
    virtual void v426();
    virtual void v427();
    virtual void v428();
    virtual void v429();
    virtual void v430();
    virtual void v431();
    virtual void v432();
    virtual void v433();
    virtual void v434();
    virtual void v435();
    virtual Node* GetNode(int);
};
struct Effect
{
    int unk00;
    int unk04;
    int unk08;
    int type;
    int part;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    void* weapon;
    bool FUN_0058cba0(unsigned int);
};
struct Weapon
{
    unsigned int FUN_00401170();
};
extern Weapon* DAT_011ca278;
struct GlobalObject_0045cf30
{
    bool* Bool();
};
extern GlobalObject_0045cf30 g_011df7f8, g_011df858;
struct LimbOwner
{
};
struct ActorPrefix
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
    virtual bool IsStateActive(int);
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
    virtual bool IsSpecial();
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
    Process* process;
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
};
struct Queue
{
    void FUN_0087b440(void*, int, int, bool, bool);
};
Queue* FUN_004537b0();
bool FUN_008c7aa0();
void RollChanceOutcome(LimbOwner*, Weapon*, int, int, int, bool, bool*, bool*);
struct Actor : ActorPrefix, LimbOwner
{
    TESActorBase* GetActorBase();
    bool FUN_00573090(int);
    bool FUN_0087f3d0();
    void FUN_00572fc0(int, void*, void*, int, bool);
    void FUN_008b52a0(int, int, bool, bool, bool, bool);
    void ApplyEffectToBodyParts(Effect*, int, int, void*, void*, int, int, bool);
};
// Checks the actor's creature/special state, then applies the effect to matching body parts, calling FUN_00572fc0 and FUN_008b52a0 or queueing via FUN_0087b440.
// @fnv 0x008b4d10
void Actor::ApplyEffectToBodyParts(Effect* effect, int type, int part, void* source, void* target, int intA, int intB,
                                   bool flag)
{
    TESCreature* eb = dynamic_cast<TESCreature*>(GetActorBase());
    if (((eb && reinterpret_cast<CreatureView*>(eb)->FUN_005fbf20()) || IsSpecial()) && *g_011df7f8.Bool())
        return;
    switch (type)
    {
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
        break;
    default:
        FUN_00572fc0(-1, source, target, effect ? effect->part : part, false);
        return;
    }
    if (FUN_00573090(part))
        return;
    if (FUN_0087f3d0() || IsStateActive(0))
        return;
    Part* q;
    Weapon* b;
    int ba;
    Node* k;
    Body* l;
    Part* c;
    int h = 0;
    bool f = false;
    bool cf = false;
    Body* i = reinterpret_cast<BaseView*>(GetActorBase())->GetBody();
    if (i)
    {
        q = i->GetValueByIndex(part);
        if (q)
        {
            cf = q->IsFlag40Set();
            if (q->FUN_008b4360())
                h = q->GetByte65();
            if (q && cf && h >= 100)
                f = true;
        }
    }
    bool s = (effect && effect->part != part) ? true : false;
    bool p = false;
    bool a = f;
    if (effect)
    {
        if (effect->FUN_0058cba0(64))
            a = true;
        else if (effect->FUN_0058cba0(32))
            p = true;
    }
    if (!p && !a)
    {
        b = s ? 0
              : (source && reinterpret_cast<Weapon*>(source)->FUN_00401170() == 40
                     ? reinterpret_cast<Weapon*>(source)
                     : (effect && effect->weapon ? reinterpret_cast<Weapon*>(effect->weapon)
                                                 : (effect && effect->type == 45 ? DAT_011ca278 : 0)));
        RollChanceOutcome(this, b, h, intA, intB, cf, &p, &a);
    }
    if (!p && !a)
        return;
    for (ba = 0; ba < 15; ba++)
    {
        if (*g_011df858.Bool() && ba != -1)
            ba = part;
        l = reinterpret_cast<BaseView*>(GetActorBase())->GetBody();
        c = l ? l->GetValueByIndex(ba) : 0;
        if (!c || c->GetByte63() != type)
            continue;
        k = process->GetNode(ba);
        if (!k || k->FUN_00456610())
            continue;
        if (a && !c->FUN_008b4360())
            a = false;
        if (!c->FUN_008b5190() && !c->FUN_008b4360())
            continue;
        FUN_00572fc0(ba, source, target, ba, a);
        if (!FUN_008c7aa0())
            FUN_008b52a0(type, ba, a, !flag, true, false);
        else
            FUN_004537b0()->FUN_0087b440(this, type, ba, a, !flag);
        if (*g_011df858.Bool() && ba != -1)
            break;
    }
}
}  // namespace fnv_008b4d10

extern "C" char DAT_01183a00;
extern "C" char DAT_01183028;
extern "C" void* __cdecl FUN_00ec43fb(void*, int, void*, void*, int);
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
struct S47f190
{
    void FUN_0047f190(void*);
};
struct S48d630
{
    void FUN_0048d630(void*);
};
struct S47bdd0
{
    void FUN_0047bdd0(void*);
};
struct S47d220
{
    void CopyFromActorBaseData(void*);
};
struct S487240
{
    void CopyHealthForm(void*);
};
struct S480000
{
    void CopyAttributesFromComponent(void*);
};
struct S4870f0
{
    void CopyFullNameFrom(void*);
};
struct S489430
{
    void FUN_00489430(void*);
};
struct S489db0
{
    void CopyModelListFromComponent(void*);
};
struct S48cce0
{
    void CopyFromScriptableForm(void*);
};
struct S481c80
{
    void FUN_00481c80(void*);
};
struct S47fb50
{
    void FUN_0047fb50(void*);
};
struct S4786e0
{
    void FUN_004786e0(void*);
};
struct Sound
{
    void* FUN_005f7bf0(int);
    void CopyCreatureSoundLists(Sound*);
};
struct Spells
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
    virtual int v22();
    virtual void v23(int);
    int* FUN_00717e50();
};
struct C005f9820
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
    virtual int v96();
    virtual void v97(int);
    virtual int v98();
    virtual void v99(int);
    char pad[0x124];
    Sound* sounds;
    Sound* FUN_005f91d0();
    Sound* FUN_005f9210();
    void* GetOffset12C();
    unsigned char FUN_005f9ad0();
    void SetCreatureType(unsigned char);
    float FUN_00821640();
    void FUN_00507780(float);
    float FUN_00567470();
    void SetBoltGrowWidth(float);
    float FUN_00821660();
    void SetBoltSmallWidth(float);
    C005f9820* FUN_005f9100();
    void FUN_005f9140(C005f9820*);
    unsigned int FUN_009c0070();
    void* GetImpactDataSet();
    void SetImpactDataSet(void*);
    void* GetField158();
    void FUN_005f8bd0(void*);
    void CopyFrom(void*);
};
// @fnv 0x005f9820
void C005f9820::CopyFrom(void* apSource)
{
    Sound* ptr;
    C005f9820* src2 = (C005f9820*)FUN_00ec43fb(apSource, 0, &DAT_01183028, &DAT_01183a00, 0);
    if (!src2)
        return;
    if (FUN_005f91d0())
    {
        Sound* snd = sounds;
        Sound* del2 = snd;
        del2 ? del2->FUN_005f7bf0(1) : 0;
    }
    sounds = 0;
    ((S47f190*)((char*)this + 0x90))->FUN_0047f190(apSource);
    ((S48d630*)((char*)this + 0x7c))->FUN_0048d630(apSource);
    ((S47bdd0*)((char*)this + 0x70))->FUN_0047bdd0(apSource);
    ((S47d220*)((char*)this + 0x30))->CopyFromActorBaseData(apSource);
    ((S487240*)((char*)this + 0xb0))->CopyHealthForm(apSource);
    ((S480000*)((char*)this + 0xb8))->CopyAttributesFromComponent(apSource);
    ((S4870f0*)((char*)this + 0xd0))->CopyFullNameFrom(apSource);
    ((S489430*)((char*)this + 0xdc))->FUN_00489430(apSource);
    ((S489db0*)((char*)this + 0x114))->CopyModelListFromComponent(apSource);
    ((S48cce0*)((char*)this + 0xf4))->CopyFromScriptableForm(apSource);
    ((S481c80*)((char*)this + 0x64))->FUN_00481c80(apSource);
    ((S47fb50*)((char*)this + 0xc4))->FUN_0047fb50(apSource);
    ((S4786e0*)((char*)this + 0x104))->FUN_004786e0(apSource);
    memcpy((char*)this + 0x12c, src2->GetOffset12C(), 4);
    *(int*)((char*)this + 0x34) = *((Spells*)((char*)src2 + 0x30))->FUN_00717e50();
    SetCreatureType(src2->FUN_005f9ad0());
    FUN_00507780(src2->FUN_00821640());
    SetBoltGrowWidth(src2->FUN_00567470());
    SetBoltSmallWidth(src2->FUN_00821660());
    ((Spells*)((char*)this + 0x30))->v23(((Spells*)((char*)src2 + 0x30))->v22());
    if (src2->FUN_005f91d0())
    {
        ptr = FUN_005f9210();
        ptr->CopyCreatureSoundLists(src2->FUN_005f91d0());
    }
    else
    {
        FUN_005f9140(src2->FUN_005f9100());
    }
    *(unsigned int*)((char*)this + 0x154) = src2->FUN_009c0070();
    SetImpactDataSet(src2->GetImpactDataSet());
    FUN_005f8bd0(src2->GetField158());
    v99(src2->v98());
    v97(src2->v96());
}

class MobileObject : public TESObjectREFR
{
  public:
    BaseProcess* FUN_008d8520() const;
};
class MiddleHighProcess : public BaseProcess
{
  public:
    virtual void w092();
    virtual void w093();
    virtual void w094();
    virtual void w095();
    virtual void w096();
    virtual void w097();
    virtual void w098();
    virtual void w099();
    virtual void w100();
    virtual void w101();
    virtual void w102();
    virtual void w103();
    virtual void w104();
    virtual void w105();
    virtual void w106();
    virtual void w107();
    virtual void w108();
    virtual void w109();
    virtual void w110();
    virtual void w111();
    virtual void w112();
    virtual void w113();
    virtual void w114();
    virtual void w115();
    virtual void w116();
    virtual void w117();
    virtual void w118();
    virtual void w119();
    virtual void w120();
    virtual void w121();
    virtual void w122();
    virtual void w123();
    virtual void w124();
    virtual void w125();
    virtual void w126();
    virtual void w127();
    virtual void w128();
    virtual void w129();
    virtual void w130();
    virtual void w131();
    virtual void w132();
    virtual void w133();
    virtual void w134();
    virtual void w135();
    virtual void w136();
    virtual void w137();
    virtual void w138();
    virtual void w139();
    virtual void w140();
    virtual void w141();
    virtual void w142();
    virtual void w143();
    virtual void w144();
    virtual void w145();
    virtual void w146();
    virtual void w147();
    virtual void w148();
    virtual void w149();
    virtual void w150();
    virtual void w151();
    virtual void w152();
    virtual void w153();
    virtual void w154();
    virtual void w155();
    virtual void w156();
    virtual void w157();
    virtual void w158();
    virtual void w159();
    virtual void w160();
    virtual void w161();
    virtual void w162();
    virtual void w163();
    virtual void w164();
    virtual void w165();
    virtual void w166();
    virtual void w167();
    virtual void w168();
    virtual void w169();
    virtual void w170();
    virtual void w171();
    virtual void w172();
    virtual void w173();
    virtual void w174();
    virtual void w175();
    virtual void w176();
    virtual void w177();
    virtual void w178();
    virtual void w179();
    virtual void w180();
    virtual void w181();
    virtual void w182();
    virtual void w183();
    virtual void w184();
    virtual void w185();
    virtual void w186();
    virtual void w187();
    virtual void w188();
    virtual void w189();
    virtual void w190();
    virtual void w191();
    virtual void w192();
    virtual void w193();
    virtual void w194();
    virtual void w195();
    virtual void w196();
    virtual void w197();
    virtual void w198();
    virtual void w199();
    virtual void w200();
    virtual void w201();
    virtual void w202();
    virtual void w203();
    virtual void w204();
    virtual void w205();
    virtual void w206();
    virtual void w207();
    virtual void w208();
    virtual void w209();
    virtual void w210();
    virtual void w211();
    virtual void w212();
    virtual void w213();
    virtual void w214();
    virtual void w215();
    virtual void w216();
    virtual void w217();
    virtual void w218();
    virtual void w219();
    virtual void w220();
    virtual void w221();
    virtual void w222();
    virtual void w223();
    virtual void w224();
    virtual void w225();
    virtual void w226();
    virtual void w227();
    virtual void w228();
    virtual void w229();
    virtual void w230();
    virtual void w231();
    virtual void w232();
    virtual void w233();
    virtual void w234();
    virtual void w235();
    virtual void w236();
    virtual void w237();
    virtual void w238();
    virtual void w239();
    virtual void w240();
    virtual void w241();
    virtual void w242();
    virtual void w243();
    virtual void w244();
    virtual void w245();
    virtual void w246();
    virtual void w247();
    virtual void w248();
    virtual void w249();
    virtual void w250();
    virtual void w251();
    virtual void w252();
    virtual void w253();
    virtual void w254();
    virtual void w255();
    virtual void w256();
    virtual void w257();
    virtual void w258();
    virtual void w259();
    virtual void w260();
    virtual void w261();
    virtual void w262();
    virtual void w263();
    virtual void w264();
    virtual void w265();
    virtual void w266();
    virtual void w267();
    virtual void w268();
    virtual void w269();
    virtual void w270();
    virtual void w271();
    virtual void w272();
    virtual void w273();
    virtual void w274();
    virtual void w275();
    virtual void w276();
    virtual void w277();
    virtual void w278();
    virtual void w279();
    virtual void w280();
    virtual void w281();
    virtual void w282();
    virtual void w283();
    virtual void w284();
    virtual void w285();
    virtual void w286();
    virtual void w287();
    virtual void w288();
    virtual void w289();
    virtual void w290();
    virtual void w291();
    virtual void w292();
    virtual void w293();
    virtual void w294();
    virtual void w295();
    virtual void w296();
    virtual void w297();
    virtual void w298();
    virtual void w299();
    virtual void w300();
    virtual void w301();
    virtual void w302();
    virtual void w303();
    virtual void w304();
    virtual void w305();
    virtual void w306();
    virtual void w307();
    virtual void w308();
    virtual void w309();
    virtual void w310();
    virtual void w311();
    virtual void w312();
    virtual void w313();
    virtual void w314();
    virtual void w315();
    virtual void w316();
    virtual void w317();
    virtual void w318();
    virtual void w319();
    virtual void w320();
    virtual void w321();
    virtual void w322();
    virtual void w323();
    virtual void w324();
    virtual void w325();
    virtual void w326();
    virtual void w327();
    virtual void w328();
    virtual void w329();
    virtual void w330();
    virtual void w331();
    virtual void w332();
    virtual void w333();
    virtual void w334();
    virtual void w335();
    virtual void w336();
    virtual void Apply(MobileObject*);
};
struct CreatureHost_5fa0a0
{
    void FUN_005fa0a0(TESObjectREFR* ref);
};
// Casts ref to MobileObject, gets its BaseProcess, casts to MiddleHighProcess, and calls Apply on it.
// @fnv 0x005fa0a0
void CreatureHost_5fa0a0::FUN_005fa0a0(TESObjectREFR* ref)
{
    MobileObject* mobile = dynamic_cast<MobileObject*>(ref);
    if (mobile && mobile->FUN_008d8520())
    {
        MiddleHighProcess* process = dynamic_cast<MiddleHighProcess*>(mobile->FUN_008d8520());
        if (process)
        {
            process->Apply(mobile);
        }
    }
}
