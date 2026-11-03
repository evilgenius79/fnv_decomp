
// src/fallout/ai/combat/explosion.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/explosion.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct ActorCause
{
};
struct NiPointer
{
    NiPointer& operator=(ActorCause*);
};
struct FUN_009ac170_shell
{
    char m_auiShapeKeys[0xd0];
    NiPointer m_actorCause;
    void __thiscall FUN_009ac170(ActorCause* apActorCause);
};

// @fnv 0x009ac170
void __thiscall FUN_009ac170_shell::FUN_009ac170(ActorCause* apActorCause)
{
    m_actorCause = apActorCause;
}

struct Explosion
{
    virtual ~Explosion();
    void* Destroy(unsigned int flags);
};

void __cdecl _Deallocate(void*);

// Runs the Explosion destructor and, when flags has bit 0 set, deallocates this; returns this.
// @fnv 0x009ac1d0
void* Explosion::Destroy(unsigned int flags)
{
    Explosion::~Explosion();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct NiRTTI;
struct bhkLiquidAction
{
    const NiRTTI* __thiscall GetRTTI() const;
};

extern NiRTTI g_01268420;

// @fnv 0x009ae240
const NiRTTI* __thiscall bhkLiquidAction::GetRTTI() const
{
    return &g_01268420;
}

struct NavMesh;

struct NavMeshPtr
{
    NavMesh* FUN_00458b50();
};

NavMesh* NavMeshPtr::FUN_00458b50()
{
    return 0;
}

struct FUN_009afc30_shell
{
    NavMeshPtr m_navMeshPtr;
    NavMesh* FUN_009afc30();
};

// @fnv 0x009afc30
NavMesh* FUN_009afc30_shell::FUN_009afc30()
{
    return ((NavMeshPtr*)((char*)this + 8))->FUN_00458b50();
}

namespace fnv_009b2770 {
struct BGSLoadFormBuffer;

struct MobileObject
{
    void ApplyLoadBuffer(BGSLoadFormBuffer* apLoadGameBuffer);
};

struct Explosion : MobileObject
{
    void FUN_009b2770(BGSLoadFormBuffer* apLoadGameBuffer);
};

// @fnv 0x009b2770
void Explosion::FUN_009b2770(BGSLoadFormBuffer* apLoadGameBuffer)
{
    MobileObject::ApplyLoadBuffer(apLoadGameBuffer);
}
}  // namespace fnv_009b2770

struct BSOcclusionPlane
{
    int __thiscall GetCullResult() const;
    int __thiscall IsNotCulled();
};

// @fnv 0x009ad5f0
int BSOcclusionPlane::IsNotCulled()
{
    return !GetCullResult();
}

struct FUN_009afbb0_shell
{
    virtual ~FUN_009afbb0_shell();
    void* FUN_009afbb0(unsigned int flags);
    void FUN_009afc10();
};

extern "C" void __cdecl FUN_009afbe0(void*);

// Calls FUN_009afc10, then if bit 0 of flags is set calls FUN_009afbe0 on this, and returns this.
// @fnv 0x009afbb0
void* FUN_009afbb0_shell::FUN_009afbb0(unsigned int flags)
{
    FUN_009afc10();
    if (flags & 1)
        FUN_009afbe0(this);
    return this;
}

struct FUN_00621100_shell
{
    void __thiscall SetVtable(void);
};

struct FUN_009afc10_shell
{
    void __thiscall FUN_009afc10();
};

// @fnv 0x009afc10
void __thiscall FUN_009afc10_shell::FUN_009afc10()
{
    ((FUN_00621100_shell*)this)->SetVtable();
}

struct FUN_009afc50_shell
{
    char m_auiShapeKeys[0x14];
    NavMeshPtr m_navMeshPtr;
    NavMesh* FUN_009afc30();
};

// @fnv 0x009afc50
NavMesh* FUN_009afc50_shell::FUN_009afc30()
{
    return m_navMeshPtr.FUN_00458b50();
}

void __cdecl FUN_009ac940(void*);
struct FUN_009ac910_shell
{
    void __thiscall FUN_009ac940();
    void* __thiscall FUN_009ac910(unsigned int flags);
};
// Calls FUN_009ac940, then frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x009ac910
void* __thiscall FUN_009ac910_shell::FUN_009ac910(unsigned int flags)
{
    FUN_009ac940();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void __cdecl _delete(void*, unsigned int);
struct FUN_00cbc920_shell
{
    void __thiscall FUN_00cbc920();
};
struct StandIn
{
    void* __thiscall FUN_009ae250(unsigned int);
};
// Calls FUN_00cbc920 on this, then frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x009ae250
void* StandIn::FUN_009ae250(unsigned int flags)
{
    ((FUN_00cbc920_shell*)this)->FUN_00cbc920();
    if (flags & 1)
        _delete(this, 0x40);
    return this;
}

struct Twin_0084d030
{
    float GetStoredFloatValue();
};
struct GameTimerRecord : Twin_0084d030
{
};
extern GameTimerRecord g_timeGlobal;
struct VCall190
{
    virtual void f0(float);
    virtual void f1(float);
    virtual void f2(float);
    virtual void f3(float);
    virtual void f4(float);
    virtual void f5(float);
    virtual void f6(float);
    virtual void f7(float);
    virtual void f8(float);
    virtual void f9(float);
    virtual void f10(float);
    virtual void f11(float);
    virtual void f12(float);
    virtual void f13(float);
    virtual void f14(float);
    virtual void f15(float);
    virtual void f16(float);
    virtual void f17(float);
    virtual void f18(float);
    virtual void f19(float);
    virtual void f20(float);
    virtual void f21(float);
    virtual void f22(float);
    virtual void f23(float);
    virtual void f24(float);
    virtual void f25(float);
    virtual void f26(float);
    virtual void f27(float);
    virtual void f28(float);
    virtual void f29(float);
    virtual void f30(float);
    virtual void f31(float);
    virtual void f32(float);
    virtual void f33(float);
    virtual void f34(float);
    virtual void f35(float);
    virtual void f36(float);
    virtual void f37(float);
    virtual void f38(float);
    virtual void f39(float);
    virtual void f40(float);
    virtual void f41(float);
    virtual void f42(float);
    virtual void f43(float);
    virtual void f44(float);
    virtual void f45(float);
    virtual void f46(float);
    virtual void f47(float);
    virtual void f48(float);
    virtual void f49(float);
    virtual void f50(float);
    virtual void f51(float);
    virtual void f52(float);
    virtual void f53(float);
    virtual void f54(float);
    virtual void f55(float);
    virtual void f56(float);
    virtual void f57(float);
    virtual void f58(float);
    virtual void f59(float);
    virtual void f60(float);
    virtual void f61(float);
    virtual void f62(float);
    virtual void f63(float);
    virtual void f64(float);
    virtual void f65(float);
    virtual void f66(float);
    virtual void f67(float);
    virtual void f68(float);
    virtual void f69(float);
    virtual void f70(float);
    virtual void f71(float);
    virtual void f72(float);
    virtual void f73(float);
    virtual void f74(float);
    virtual void f75(float);
    virtual void f76(float);
    virtual void f77(float);
    virtual void f78(float);
    virtual void f79(float);
    virtual void f80(float);
    virtual void f81(float);
    virtual void f82(float);
    virtual void f83(float);
    virtual void f84(float);
    virtual void f85(float);
    virtual void f86(float);
    virtual void f87(float);
    virtual void f88(float);
    virtual void f89(float);
    virtual void f90(float);
    virtual void f91(float);
    virtual void f92(float);
    virtual void f93(float);
    virtual void f94(float);
    virtual void f95(float);
    virtual void f96(float);
    virtual void f97(float);
    virtual void f98(float);
    virtual void f99(float);
    virtual void f100(float);
    virtual void f101(float);
    virtual void f102(float);
    virtual void f103(float);
    virtual void f104(float);
    virtual void f105(float);
    virtual void f106(float);
    virtual void f107(float);
    virtual void f108(float);
    virtual void f109(float);
    virtual void f110(float);
    virtual void f111(float);
    virtual void f112(float);
    virtual void f113(float);
    virtual void f114(float);
    virtual void f115(float);
    virtual void f116(float);
    virtual void f117(float);
    virtual void f118(float);
    virtual void f119(float);
    virtual void f120(float);
    virtual void f121(float);
    virtual void f122(float);
    virtual void f123(float);
    virtual void f124(float);
    virtual void f125(float);
    virtual void f126(float);
    virtual void f127(float);
    virtual void f128(float);
    virtual void f129(float);
    virtual void f130(float);
    virtual void f131(float);
    virtual void f132(float);
    virtual void f133(float);
    virtual void f134(float);
    virtual void f135(float);
    virtual void f136(float);
    virtual void f137(float);
    virtual void f138(float);
    virtual void f139(float);
    virtual void f140(float);
    virtual void f141(float);
    virtual void f142(float);
    virtual void f143(float);
    virtual void f144(float);
    virtual void f145(float);
    virtual void f146(float);
    virtual void f147(float);
    virtual void f148(float);
    virtual void f149(float);
    virtual void f150(float);
    virtual void f151(float);
    virtual void f152(float);
    virtual void f153(float);
    virtual void f154(float);
    virtual void f155(float);
    virtual void f156(float);
    virtual void f157(float);
    virtual void f158(float);
    virtual void f159(float);
    virtual void f160(float);
    virtual void f161(float);
    virtual void f162(float);
    virtual void f163(float);
    virtual void f164(float);
    virtual void f165(float);
    virtual void f166(float);
    virtual void f167(float);
    virtual void f168(float);
    virtual void f169(float);
    virtual void f170(float);
    virtual void f171(float);
    virtual void f172(float);
    virtual void f173(float);
    virtual void f174(float);
    virtual void f175(float);
    virtual void f176(float);
    virtual void f177(float);
    virtual void f178(float);
    virtual void f179(float);
    virtual void f180(float);
    virtual void f181(float);
    virtual void f182(float);
    virtual void f183(float);
    virtual void f184(float);
    virtual void f185(float);
    virtual void f186(float);
    virtual void f187(float);
    virtual void f188(float);
    virtual void f189(float);
    virtual void f190(float);
};
struct FUN_009ae580_shell : VCall190
{
    char m_auiShapeKeys[0x84];
    float m_fFirstFloatValue;
    void FUN_009ae580(float afDelta);
};
// @fnv 0x009ae580
void FUN_009ae580_shell::FUN_009ae580(float afDelta)
{
    float fdelta = g_timeGlobal.GetStoredFloatValue();
    f190(fdelta);
    m_fFirstFloatValue += fdelta;
}

struct BSAudio
{
    void* GetAudioBackendData();
};
BSAudio* __cdecl _FUN_00c85750();
struct UnkObj
{
    virtual void f0();
    virtual void f1();
    virtual void f2(void*, int);
};
// @fnv 0x009afbe0
void __cdecl FUN_009afbe0(void* a1)
{
    if (a1 != 0)
    {
        UnkObj* v = (UnkObj*)_FUN_00c85750()->GetAudioBackendData();
        v->f2(a1, 0x18);
    }
}

struct H00622570
{
    void __thiscall FUN_00622570(bool);
};
struct S009afc70
{
    char m_auiShapeKeys[0x14];
    NavMeshPtr m_navMeshPtr;
    void* __thiscall FUN_009afc70(void*);
};
// Calls FUN_00622570 on a1 with true when m_navMeshPtr.FUN_00458b50() returns a value greater than 0, then returns a1.
// @fnv 0x009afc70
void* __thiscall S009afc70::FUN_009afc70(void* apTarget)
{
    ((H00622570*)apTarget)->FUN_00622570((int)m_navMeshPtr.FUN_00458b50() > 0);
    return apTarget;
}

class BGSRagdoll;
template <typename T> class BSSimpleList
{
  public:
    virtual void F00()
    {}
    virtual void F01()
    {}
    virtual void F02()
    {}
    virtual void F03()
    {}
    virtual void F04()
    {}
    virtual void F05()
    {}
    virtual void F06()
    {}
    virtual void F07()
    {}
    virtual void F08()
    {}
    virtual void F09()
    {}
    virtual void F10()
    {}
    virtual void F11()
    {}
    virtual void F12()
    {}
    virtual void F13()
    {}
    virtual void F14()
    {}
    virtual void F15()
    {}
    virtual void F16()
    {}
    virtual void F17()
    {}
    virtual void F18()
    {}
    virtual void F19()
    {}
    virtual void F20()
    {}
    virtual void F21(int)
    {}
};
struct TESDataHandler
{
    BSSimpleList<BGSRagdoll*>* __thiscall GetBGSRagdollList();
};
struct FUN_009b0d30_shell
{
    void __thiscall FUN_00c9c1d0();
    void __thiscall FUN_009b0d30(int);
};
// @fnv 0x009b0d30
void __thiscall FUN_009b0d30_shell::FUN_009b0d30(int a1)
{
    this->FUN_00c9c1d0();
    reinterpret_cast<TESDataHandler*>(this)->GetBGSRagdollList()->F21(a1);
}

struct RetObj
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
    virtual bool vf37();
};
struct Actor
{
    RetObj* _FNV_GetObjectReference();
    bool FUN_00565690();
};
// Returns true if _FNV_GetObjectReference() is non-null and its vf37() call returns true, otherwise false.
// @fnv 0x00565690
bool Actor::FUN_00565690()
{
    return _FNV_GetObjectReference() ? _FNV_GetObjectReference()->vf37() : false;
}

struct Standin77900
{
    bool __thiscall HasAnyFlags(int);
};
struct Setting_S
{
    float* __thiscall Float();
};
extern Setting_S originalRuntimeFloatSetting818;
struct BGSExplosion : Standin77900
{
    char _pad[0xA0];
    float m_fSphereRadius;
    float __thiscall GetScaledValue();
};
// @fnv 0x009ad5a0
float __thiscall BGSExplosion::GetScaledValue()
{
    return (float)(HasAnyFlags(1) ? (double)m_fSphereRadius
                                  : (double)(m_fSphereRadius * *originalRuntimeFloatSetting818.Float()));
}

extern const float runtimeFloatSettingDefault247;
struct FUN_009ae0f0
{
    char _pad[8];
    float m8;
    float mC;
    float m10;
    float m14;
    void __thiscall FUN_00537bb0();
    FUN_009ae0f0();
};
// Calls FUN_00537bb0, then sets m8 to runtimeFloatSettingDefault247 and mC, m10, m14 to 15.0f, 64.0f, 15.0f.
// @fnv 0x009ae0f0
FUN_009ae0f0::FUN_009ae0f0()
{
    FUN_00537bb0();
    m8 = runtimeFloatSettingDefault247;
    mC = 15.0f;
    m10 = 64.0f;
    m14 = 15.0f;
}

void* __cdecl operator new(unsigned int);
struct BGSLoadFormBuffer
{
    virtual unsigned char GetVersion();
    void ReadTypedData(void* apData, unsigned int auiSize);
    bool ReadFormIdentifier(void* apFormID);
};
struct BGSLoadGameBuffer
{
    unsigned int ReadFormIdentifier();
};
class TESForm
{
  public:
    virtual ~TESForm();
};
class TESObjectWEAP : public TESForm
{
};
TESForm* GetFormByID(unsigned int);
ActorCause* FindStateByValue(int);
struct FUN_00825ad0
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int uiFormID18;
    unsigned int uiFormID1C;
    unsigned int uiFormID20;
    FUN_00825ad0(void* apOwner);
};
struct MobileObject_9b22c0
{
    virtual ~MobileObject_9b22c0();
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
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    void FUN_00932a00(BGSLoadFormBuffer* apLoadGameBuffer);
};
struct FUN_009b22c0_shell : MobileObject_9b22c0
{
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    ActorCause* m_pActorCause;
    bool unkD4;
    bool m_bFlagD5;
    bool m_bFlagD6;
    bool m_bFlagD7;
    bool unkD8;
    bool unkD9;
    unsigned short unkDA;
    FUN_00825ad0* m_pEffectInstance;
    TESObjectWEAP* m_pFiringWeapon;
    int m_iValueE4;
    float unkE8[3];
    float unkF4[3];
    int unk100;
    void FUN_009b22c0(BGSLoadFormBuffer* apLoadGameBuffer);
};
// @fnv 0x009b22c0
void FUN_009b22c0_shell::FUN_009b22c0(BGSLoadFormBuffer* apLoadGameBuffer)
{
    FUN_00932a00(apLoadGameBuffer);
    apLoadGameBuffer->ReadTypedData(&unk88, 4);
    apLoadGameBuffer->ReadTypedData(&unk8C, 4);
    apLoadGameBuffer->ReadTypedData(&unk94, 4);
    apLoadGameBuffer->ReadTypedData(&unk98, 4);
    apLoadGameBuffer->ReadTypedData(&unkD4, 1);
    apLoadGameBuffer->ReadTypedData(&m_iValueE4, 4);
    apLoadGameBuffer->ReadTypedData(&unk90, 4);
    if (apLoadGameBuffer->GetVersion() >= 0xe)
    {
        apLoadGameBuffer->ReadTypedData(&unk9C, 4);
        apLoadGameBuffer->ReadTypedData(&unkD8, 1);
        apLoadGameBuffer->ReadTypedData(&unkD9, 1);
        apLoadGameBuffer->ReadTypedData(unkE8, 0xc);
        apLoadGameBuffer->ReadTypedData(unkF4, 0xc);
    }
    if (apLoadGameBuffer->GetVersion() >= 0x14)
        apLoadGameBuffer->ReadTypedData(&unk100, 4);
    apLoadGameBuffer->ReadFormIdentifier(&unkC8);
    apLoadGameBuffer->ReadFormIdentifier(&unkCC);
    m_pFiringWeapon =
        dynamic_cast<TESObjectWEAP*>(GetFormByID(((BGSLoadGameBuffer*)apLoadGameBuffer)->ReadFormIdentifier()));
    int iactorCauseID = -1;
    apLoadGameBuffer->ReadTypedData(&iactorCauseID, 4);
    reinterpret_cast<NiPointer&>(m_pActorCause) = FindStateByValue(iactorCauseID);
    bool bhasCaster = true;
    if (apLoadGameBuffer->GetVersion() >= 7)
        apLoadGameBuffer->ReadTypedData(&bhasCaster, 1);
    if (bhasCaster)
    {
        if (!m_pEffectInstance)
            m_pEffectInstance = new FUN_00825ad0(this);
        apLoadGameBuffer->ReadFormIdentifier(&m_pEffectInstance->uiFormID18);
        apLoadGameBuffer->ReadFormIdentifier(&m_pEffectInstance->uiFormID1C);
        apLoadGameBuffer->ReadFormIdentifier(&m_pEffectInstance->uiFormID20);
    }
    if (m_iValueE4 > 0)
    {
        m_bFlagD5 = true;
        m_bFlagD6 = true;
        m_bFlagD7 = true;
    }
}

struct Vec3f
{
    float x;
    float y;
    float z;
};
extern const float g_fConst010162c0;
void* __fastcall Callee00439e90(void* p);
void* __fastcall Callee0053d280(void* p);
struct FUN_005762b0_cls
{
    virtual void vf0()
    {}
    virtual void vf1()
    {}
    virtual void vf2()
    {}
    virtual void vf3()
    {}
    virtual void vf4()
    {}
    virtual void vf5()
    {}
    virtual void vf6()
    {}
    virtual void vf7()
    {}
    virtual void vf8()
    {}
    virtual void vf9()
    {}
    virtual void vf10()
    {}
    virtual void vf11()
    {}
    virtual void vf12()
    {}
    virtual void vf13()
    {}
    virtual void vf14()
    {}
    virtual void vf15()
    {}
    virtual void vf16()
    {}
    virtual void vf17()
    {}
    virtual void vf18()
    {}
    virtual void vf19()
    {}
    virtual void vf20()
    {}
    virtual void vf21()
    {}
    virtual void vf22()
    {}
    virtual void vf23()
    {}
    virtual void vf24()
    {}
    virtual void vf25()
    {}
    virtual void vf26()
    {}
    virtual void vf27()
    {}
    virtual void vf28()
    {}
    virtual void vf29()
    {}
    virtual void vf30()
    {}
    virtual void vf31()
    {}
    virtual void vf32()
    {}
    virtual void vf33()
    {}
    virtual void vf34()
    {}
    virtual void vf35()
    {}
    virtual void vf36()
    {}
    virtual void vf37()
    {}
    virtual void vf38()
    {}
    virtual void vf39()
    {}
    virtual void vf40()
    {}
    virtual void vf41()
    {}
    virtual void vf42()
    {}
    virtual void vf43()
    {}
    virtual void vf44()
    {}
    virtual void vf45()
    {}
    virtual void vf46()
    {}
    virtual void vf47()
    {}
    virtual void vf48()
    {}
    virtual void vf49()
    {}
    virtual void vf50()
    {}
    virtual void vf51()
    {}
    virtual void vf52()
    {}
    virtual void vf53()
    {}
    virtual void vf54()
    {}
    virtual void vf55()
    {}
    virtual void vf56()
    {}
    virtual void vf57()
    {}
    virtual void vf58()
    {}
    virtual void vf59()
    {}
    virtual void vf60()
    {}
    virtual void vf61()
    {}
    virtual void vf62()
    {}
    virtual void vf63()
    {}
    virtual void vf64()
    {}
    virtual void vf65()
    {}
    virtual void vf66()
    {}
    virtual void vf67()
    {}
    virtual void vf68()
    {}
    virtual void vf69()
    {}
    virtual void vf70()
    {}
    virtual void vf71()
    {}
    virtual void vf72()
    {}
    virtual void vf73()
    {}
    virtual void vf74()
    {}
    virtual void vf75()
    {}
    virtual void vf76()
    {}
    virtual void vf77()
    {}
    virtual void vf78()
    {}
    virtual void vf79()
    {}
    virtual void vf80()
    {}
    virtual void vf81()
    {}
    virtual void vf82()
    {}
    virtual void vf83()
    {}
    virtual void vf84()
    {}
    virtual void vf85()
    {}
    virtual void vf86()
    {}
    virtual void vf87()
    {}
    virtual void vf88()
    {}
    virtual void vf89()
    {}
    virtual void vf90()
    {}
    virtual void vf91()
    {}
    virtual void vf92()
    {}
    virtual void vf93()
    {}
    virtual void vf94()
    {}
    virtual void vf95()
    {}
    virtual void vf96()
    {}
    virtual void vf97()
    {}
    virtual void vf98()
    {}
    virtual void vf99()
    {}
    virtual void vf100()
    {}
    virtual void vf101()
    {}
    virtual void vf102()
    {}
    virtual void vf103()
    {}
    virtual void vf104()
    {}
    virtual void vf105()
    {}
    virtual void vf106()
    {}
    virtual void vf107()
    {}
    virtual void vf108()
    {}
    virtual void vf109()
    {}
    virtual void vf110()
    {}
    virtual void vf111()
    {}
    virtual void vf112()
    {}
    virtual void vf113()
    {}
    virtual void vf114()
    {}
    virtual void vf115()
    {}
    virtual void vf116()
    {}
    virtual void vf117()
    {}
    virtual void* vf118(unsigned int* p, Vec3f* q, void* r)
    {
        return 0;
    }
    virtual void* vf119(Vec3f* p, Vec3f* q, float f)
    {
        return 0;
    }
    virtual void vf120()
    {}
    virtual void vf121()
    {}
    virtual void vf122()
    {}
    virtual void vf123()
    {}
    virtual void vf124()
    {}
    virtual void* vf125(int a, void* p)
    {
        return 0;
    }
    int FUN_005762b0(int a1);
};
// Calls vf125 with a1 and the result of a chain of vf118/vf119 calls on local Vec3f values, then passes that to Callee00439e90, and returns a1.
// @fnv 0x005762b0
int FUN_005762b0_cls::FUN_005762b0(int a1)
{
    Vec3f a2;
    Vec3f bTmp;
    Vec3f c;
    Vec3f d;
    Callee00439e90(
        vf125(a1, Callee0053d280(Callee00439e90(vf118((unsigned int*)&d, &bTmp, vf119(&c, &a2, g_fConst010162c0))))));
    return a1;
}

extern Setting_S originalRuntimeFloatSetting818;

struct FUN_009ac550_cls : Standin77900
{
    char _pad[0x8b];
    float m_8C;
    float GetEffectiveValue();
};

// Returns m_8C, or m_8C multiplied by the float setting when HasAnyFlags(1) is zero.
// @fnv 0x009ac550
float FUN_009ac550_cls::GetEffectiveValue()
{
    return (float)((HasAnyFlags(1) != 0) ? (double)m_8C : (double)(m_8C * *originalRuntimeFloatSetting818.Float()));
}

extern int g_ae140Count;

struct Ae140Vec
{
    int unk00;
    int unk04;
    int unk08;
    Ae140Vec();
};

extern Ae140Vec g_ae140Default;

struct Ae140Base
{
    virtual ~Ae140Base();
    int unk04;
    int unk08;
    int unk0c;
    Ae140Base();
};

struct FUN_009ae140_cls : Ae140Base
{
    virtual ~FUN_009ae140_cls();
    int m_10;
    float m_14;
    float m_18;
    float m_1c;
    float m_20;
    Ae140Vec m_24;
    Ae140Vec m_30;
    unsigned char m_3c;

    void Setup(unsigned int aArg);
    FUN_009ae140_cls(unsigned int aArg);
};

// Initialises the object's fields to defaults, calls Setup with aArg, and increments g_ae140Count.
// @fnv 0x009ae140
FUN_009ae140_cls::FUN_009ae140_cls(unsigned int aArg)
{
    m_10 = 0;
    m_14 = 0.0f;
    m_18 = 0.0f;
    m_1c = 0.0f;
    m_20 = 0.0f;
    m_24 = g_ae140Default;
    m_30 = g_ae140Default;
    m_3c = 1;
    Setup(aArg);
    ++g_ae140Count;
}

struct VectorHolder
{
    unsigned int handle;
    void __thiscall FUN_006815c0();
    void __thiscall FUN_00537e90(unsigned int);
    VectorHolder()
    {
        FUN_006815c0();
    }
};
struct BaseObject
{
    virtual ~BaseObject();
    unsigned int unk04;
    void __thiscall FUN_00621060();
    BaseObject()
    {
        FUN_00621060();
    }
};
struct FUN_009afaf0 : BaseObject
{
    VectorHolder first;
    VectorHolder second;
    VectorHolder third;
    VectorHolder fourth;
    FUN_009afaf0(unsigned int firstValue, unsigned int secondValue);
    virtual ~FUN_009afaf0();
};
// Constructs the object and initialises its four VectorHolder members with firstValue, firstValue, secondValue and 0.
// @fnv 0x009afaf0
FUN_009afaf0::FUN_009afaf0(unsigned int firstValue, unsigned int secondValue)
{
    first.FUN_00537e90(firstValue);
    second.FUN_00537e90(firstValue);
    third.FUN_00537e90(secondValue);
    fourth.FUN_00537e90(0);
}

struct FUN_009afca0_holder
{
    void __thiscall InvokeCallback(void* param);
};

extern void(__cdecl* g_01268430)(void* param, void* thisptr);

// @fnv 0x009afca0
void __thiscall FUN_009afca0_holder::InvokeCallback(void* param)
{
    g_01268430(param, this);
}

struct EntryRecord
{
    int category;
    int unk04;
    int result;
};
struct SearchNode
{
    EntryRecord** FUN_006815c0();
    SearchNode* FUN_00726070();
    bool FUN_008256d0();
};
struct MobileObjectBase
{
    virtual ~MobileObjectBase();
    unsigned int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    unsigned int unk80, unk84;
};
struct SearchOwner : MobileObjectBase
{
    unsigned int unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0;
    SearchNode entries;
    int* FindEntryResultByCategory(int category);
};
// Walks the entries node chain until a matching category is found, returning a pointer to that entry's result or null.
// @fnv 0x009b1720
int* SearchOwner::FindEntryResultByCategory(int category)
{
    int* pResult = 0;
    SearchNode* node = &entries;
    while (pResult == 0 && node != 0 && !node->FUN_008256d0())
    {
        EntryRecord* entry = *node->FUN_006815c0();
        if (entry != 0 && entry->category == category)
            pResult = &entry->result;
        node = node->FUN_00726070();
    }
    return pResult;
}

class TESForm;
class TESObjectREFR : public TESForm
{
};
TESForm* GetFormByID(unsigned int);
void* LookupThing18(void*);
void* LookupThing1C(void*);
struct CasterData
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    void* pUnk18;
    void* pUnk1C;
    TESObjectREFR* pRef20;
};
struct ExplosionBase
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
    virtual void OnLinksResolved();
    void BaseFinishLoad(void* apBuffer);
    bool IsReadyCheck();
};
struct Explosion_9b25b0 : ExplosionBase
{
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
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    TESObjectREFR* pRefC8;
    TESObjectREFR* pRefCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    CasterData* m_pEffectInstance;
    void FUN_009b25b0(void* apBuffer);
};

// @fnv 0x009b25b0
void Explosion_9b25b0::FUN_009b25b0(void* apBuffer)
{
    BaseFinishLoad(apBuffer);
    pRefC8 = pRefC8 ? dynamic_cast<TESObjectREFR*>(GetFormByID((unsigned int)pRefC8)) : 0;
    pRefCC = pRefCC ? dynamic_cast<TESObjectREFR*>(GetFormByID((unsigned int)pRefCC)) : 0;
    if (m_pEffectInstance)
    {
        m_pEffectInstance->pUnk18 = m_pEffectInstance->pUnk18 ? LookupThing18(m_pEffectInstance->pUnk18) : 0;
        m_pEffectInstance->pUnk1C = m_pEffectInstance->pUnk1C ? LookupThing1C(m_pEffectInstance->pUnk1C) : 0;
        m_pEffectInstance->pRef20 =
            m_pEffectInstance->pRef20 ? dynamic_cast<TESObjectREFR*>(GetFormByID((unsigned int)m_pEffectInstance->pRef20)) : 0;
    }
    if (IsReadyCheck())
        OnLinksResolved();
}

struct GlobalObject_00633c90
{
    GlobalObject_00633c90(int v);
    ~GlobalObject_00633c90();
    int m_ptr;
    GlobalObject_00633c90& operator=(void* p);
};
struct GlobalObject_0096a2d0
{
    GlobalObject_0096a2d0();
    ~GlobalObject_0096a2d0();
    int m_item;
    int m_next;
};
struct GlobalObject_0041a250
{
    GlobalObject_0041a250();
    ~GlobalObject_0041a250();
    int m_00;
    int m_04;
    int m_08;
};
struct GlobalObject_0042f730
{
    GlobalObject_0042f730(void* p);
    ~GlobalObject_0042f730();
    int m_ptr;
    void FUN_0042f780(void* p);
};
struct GlobalObject_006815c0
{
    GlobalObject_006815c0();
    float x;
    float y;
    float z;
};
extern "C" Vec3f NiPoint3_ZERO;

struct Base1_9abf30
{
    virtual ~Base1_9abf30();
    virtual void bvtbl00();
    int bf04;
    int bf08;
    int bf0c;
    int bf10;
    int bf14;
};
struct Base2_9abf30
{
    virtual void wvtbl00();
};

struct FUN_0092eb50 : Base1_9abf30, Base2_9abf30
{
    FUN_0092eb50();
    virtual ~FUN_0092eb50();
};

struct FUN_009abf30 : FUN_0092eb50
{
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
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    float m_88;
    float m_8c;
    float m_90;
    float m_94;
    float m_98;
    float m_9c;
    GlobalObject_00633c90 m_a0;
    GlobalObject_0096a2d0 m_a4;
    GlobalObject_0041a250 m_ac;
    GlobalObject_0041a250 m_b8;
    GlobalObject_00633c90 m_c4;
    int m_c8;
    int m_cc;
    GlobalObject_0042f730 m_d0;
    unsigned char m_d4;
    unsigned char m_d5;
    unsigned char m_d6;
    unsigned char m_d7;
    unsigned char m_d8;
    unsigned char m_d9;
    unsigned char m_da;
    unsigned char m_db;
    int m_dc;
    int m_e0;
    int m_e4;
    GlobalObject_006815c0 m_e8;
    GlobalObject_006815c0 m_f4;
    float m_100;
    FUN_009abf30();
    virtual ~FUN_009abf30();
};

// @fnv 0x009abf30
FUN_009abf30::FUN_009abf30() : m_a0(0), m_c4(0), m_d0(0)
{
    m_68 = 0;
    m_e4 = 0;
    m_88 = 0.0f;
    m_8c = 0.0f;
    m_90 = 0.0f;
    m_94 = 0.0f;
    m_98 = 0.0f;
    m_9c = 1.0f;
    m_a0 = 0;
    m_c4 = 0;
    m_d0.FUN_0042f780(0);
    m_c8 = 0;
    m_cc = 0;
    m_e0 = 0;
    m_d4 = 0;
    m_d5 = 0;
    m_d6 = 0;
    m_d7 = 0;
    m_d8 = 0;
    m_d9 = 0;
    m_dc = 0;
    m_e8 = *(GlobalObject_006815c0*)&NiPoint3_ZERO;
    m_f4 = *(GlobalObject_006815c0*)&NiPoint3_ZERO;
    m_100 = -1.0f;
}

namespace fnv_009ac200 {
struct PrimaryC
{
    virtual ~PrimaryC();
    int u04, u08, u0c, u10, u14;
};
struct SecondaryC
{
    virtual ~SecondaryC();
    int u1c;
    int u20;
    int u24;
    int u28;
    int u2c;
    int u30;
    int u34;
    int u38;
    int u3c;
    int u40;
    int u44;
    int u48;
    int u4c;
    int u50;
    int u54;
    int u58;
    int u5c;
    int u60;
    int u64;
    int u68;
    int u6c;
    int u70;
    int u74;
    int u78;
    int u7c;
    int u80;
    int u84;
};
struct MobileC : PrimaryC, SecondaryC
{
    MobileC();
    virtual ~MobileC();
    void SetParent(void*);
    void SetLocation(const Vec3f&);
    void SetRotation(struct MatrixC);
    void SetForm(void*);
    struct ExplosionFormC* GetActorBase();
};
struct MatrixC
{
    float a, b, c, d, e, f, g, h, i;
};
struct ExplosionFormC
{
    float Radius();
    float Force();
    bool HasFlag(int);
};
struct SmartC
{
    void* ptr;
    SmartC(void*);
    ~SmartC();
    SmartC& operator=(void*);
};
struct ListC
{
    void* head;
    void* next;
    ListC();
    ~ListC();
};
struct TripleC
{
    int a, b, c;
    TripleC();
    ~TripleC();
};
struct CauseC
{
    void* ptr;
    CauseC(void*);
    ~CauseC();
    CauseC& operator=(void*);
};
struct PointC
{
    float x, y, z;
    PointC();
};
struct OwnerC
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
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual bool IsSpecial();
};
extern MatrixC DAT_011a9448;
extern PointC NiPoint3_ZERO;
extern const float DAT_01017718;
extern const float DAT_01012054;
struct FUN_009ac200 : MobileC
{
    float age, lifetime, timer, radius, force, scale;
    SmartC object;
    ListC list;
    TripleC first, second;
    SmartC another;
    OwnerC* owner;
    int unkCC;
    CauseC cause;
    bool flagD4, flagD5, flagD6, flagD7, flagD8, flagD9;
    short unkDA;
    FUN_00825ad0* caster;
    void* weapon;
    int frames;
    PointC position, velocity;
    float finalValue;
    virtual ~FUN_009ac200();
    FUN_009ac200(void*, OwnerC*, void*, Vec3f, MatrixC);
};
// @fnv 0x009ac200
FUN_009ac200::FUN_009ac200(void* form, OwnerC* source, void* parent, Vec3f location, MatrixC rotation)
    : object(0), another(0), cause(0)
{
    u68 = 0;
    owner = source;
    SetParent(parent);
    SetLocation(location);
    SetRotation(rotation);
    flagD8 = false;
    if (form)
    {
        SetForm(form);
        radius = GetActorBase()->Radius();
        force = GetActorBase()->Force();
        flagD8 = GetActorBase()->HasFlag(64);
        if (GetActorBase()->HasFlag(2))
            SetRotation(DAT_011a9448);
    }
    frames = 0;
    lifetime = DAT_01017718;
    timer = 0.0f;
    age = 0.0f;
    scale = 1.0f;
    object = 0;
    another = 0;
    cause = 0;
    weapon = 0;
    flagD4 = false;
    flagD5 = false;
    flagD6 = false;
    flagD7 = false;
    flagD9 = false;
    caster = source && source->IsSpecial() ? 0 : new FUN_00825ad0(this);
    position = NiPoint3_ZERO;
    velocity = NiPoint3_ZERO;
    finalValue = DAT_01012054;
}
}  // namespace fnv_009ac200

// When the reference's 3D is loaded, run a world update on its root node with the current time.

extern float g_fB17A0CurrentTime;

class B17A0UpdateData
{
  public:
    B17A0UpdateData(float fTime, bool m_bUpdateEnabled, bool bIsMultiThreaded);

    float m_fTime;
    bool m_bUpdate;
    bool m_bIsMultiThreaded;
    unsigned char unk06;
    unsigned char unk07;
    int unk08;
};

class B17A0Node
{
  public:
    void Update(const B17A0UpdateData& kData);
};

class B17A0Ref
{
  public:
    virtual void Unk000();
    virtual void Unk004();
    virtual void Unk008();
    virtual void Unk00C();
    virtual void Unk010();
    virtual void Unk014();
    virtual void Unk018();
    virtual void Unk01C();
    virtual void Unk020();
    virtual void Unk024();
    virtual void Unk028();
    virtual void Unk02C();
    virtual void Unk030();
    virtual void Unk034();
    virtual void Unk038();
    virtual void Unk03C();
    virtual void Unk040();
    virtual void Unk044();
    virtual void Unk048();
    virtual void Unk04C();
    virtual void Unk050();
    virtual void Unk054();
    virtual void Unk058();
    virtual void Unk05C();
    virtual void Unk060();
    virtual void Unk064();
    virtual void Unk068();
    virtual void Unk06C();
    virtual void Unk070();
    virtual void Unk074();
    virtual void Unk078();
    virtual void Unk07C();
    virtual void Unk080();
    virtual void Unk084();
    virtual void Unk088();
    virtual void Unk08C();
    virtual void Unk090();
    virtual void Unk094();
    virtual void Unk098();
    virtual void Unk09C();
    virtual void Unk0A0();
    virtual void Unk0A4();
    virtual void Unk0A8();
    virtual void Unk0AC();
    virtual void Unk0B0();
    virtual void Unk0B4();
    virtual void Unk0B8();
    virtual void Unk0BC();
    virtual void Unk0C0();
    virtual void Unk0C4();
    virtual void Unk0C8();
    virtual void Unk0CC();
    virtual void Unk0D0();
    virtual void Unk0D4();
    virtual void Unk0D8();
    virtual void Unk0DC();
    virtual void Unk0E0();
    virtual void Unk0E4();
    virtual void Unk0E8();
    virtual void Unk0EC();
    virtual void Unk0F0();
    virtual void Unk0F4();
    virtual void Unk0F8();
    virtual void Unk0FC();
    virtual void Unk100();
    virtual void Unk104();
    virtual void Unk108();
    virtual void Unk10C();
    virtual void Unk110();
    virtual void Unk114();
    virtual void Unk118();
    virtual void Unk11C();
    virtual void Unk120();
    virtual void Unk124();
    virtual void Unk128();
    virtual void Unk12C();
    virtual void Unk130();
    virtual void Unk134();
    virtual void Unk138();
    virtual void Unk13C();
    virtual void Unk140();
    virtual void Unk144();
    virtual void Unk148();
    virtual void Unk14C();
    virtual void Unk150();
    virtual void Unk154();
    virtual void Unk158();
    virtual void Unk15C();
    virtual void Unk160();
    virtual void Unk164();
    virtual void Unk168();
    virtual void Unk16C();
    virtual void Unk170();
    virtual void Unk174();
    virtual void Unk178();
    virtual void Unk17C();
    virtual void Unk180();
    virtual void Unk184();
    virtual void Unk188();
    virtual void Unk18C();
    virtual void Unk190();
    virtual void Unk194();
    virtual void Unk198();
    virtual void Unk19C();
    virtual void Unk1A0();
    virtual void Unk1A4();
    virtual void Unk1A8();
    virtual void Unk1AC();
    virtual void Unk1B0();
    virtual void Unk1B4();
    virtual void Unk1B8();
    virtual void Unk1BC();
    virtual void Unk1C0();
    virtual void Unk1C4();
    virtual void Unk1C8();
    virtual void Unk1CC();
    virtual B17A0Node* Get3D();

    bool Is3DLoaded();
    void Update3D(int iUnused);
};

// If the 3D is loaded and present, builds update data from the current time and updates the 3D node.
// @fnv 0x009b17a0
void B17A0Ref::Update3D(int iUnused)
{
    if (Is3DLoaded() && Get3D())
    {
        B17A0UpdateData kData(g_fB17A0CurrentTime, true, false);
        Get3D()->Update(kData);
    }
}

// FUN_009b2790 v01 - worker7 data round
struct BGSLoadFormBuffer;

struct MobileObject
{
    virtual void Revert(BGSLoadFormBuffer* apBuffer);
};

struct AC_0042f730;
struct Holder0042f780
{
    int m_00;
    Holder0042f780* FUN_0042f780(AC_0042f730* p);
};

struct HeadW7
{
    void* FUN_009ac910(unsigned int flags);
};

struct ListW7
{
    int m_00;
    bool _ref_008256d0();
    HeadW7** _ref_006815c0();
    void _ref_0063f7b0();
};

struct Vec3W7
{
    float x;
    float y;
    float z;
};
extern Vec3W7 __NiPoint3_ZERO;

struct OwnerW7 : MobileObject
{
    int f04;
    int f08;
    int f0C;
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
    int f24;
    int f28;
    int f2C;
    int f30;
    int f34;
    int f38;
    int f3C;
    int f40;
    int f44;
    int f48;
    int f4C;
    int f50;
    int f54;
    int f58;
    int f5C;
    int f60;
    int f64;
    int f68;
    int f6C;
    int f70;
    int f74;
    int f78;
    int f7C;
    int f80;
    int f84;
    int f88;
    int f8C;
    int f90;
    int f94;
    int f98;
    float m_9c;
    int fA0;
    ListW7 m_kNode;
    int fA8;
    int fAC;
    int fB0;
    int fB4;
    int fB8;
    int fBC;
    int fC0;
    int fC4;
    int fC8;
    int fCC;
    Holder0042f780 m_cause;
    char m_d4;
    char m_d5;
    char m_d6;
    char m_d7;
    char m_d8;
    char m_d9;
    char fDA;
    char fDB;
    int fDC;
    int fE0;
    int fE4;
    Vec3W7 m_e8;
    Vec3W7 m_f4;

    void FUN_009b2790(BGSLoadFormBuffer* apBuffer);
};

// @fnv 0x009b2790
void OwnerW7::FUN_009b2790(BGSLoadFormBuffer* apBuffer)
{
    MobileObject::Revert(apBuffer);
    m_d4 = 0;
    m_d5 = 0;
    m_d6 = 0;
    m_d7 = 0;
    m_cause.FUN_0042f780(0);
    m_9c = 1.0f;
    m_d8 = 0;
    m_d9 = 0;
    m_e8 = __NiPoint3_ZERO;
    m_f4 = __NiPoint3_ZERO;
    while (!m_kNode._ref_008256d0())
    {
        HeadW7* head = *m_kNode._ref_006815c0();
        HeadW7* toFree = head;
        toFree ? toFree->FUN_009ac910(1) : 0;
        m_kNode._ref_0063f7b0();
    }
}

struct NiPoint3
{
    float x, y, z;
    NiPoint3 operator-(const NiPoint3&) const;
    float Length() const;
};
struct MatrixWater
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
    MatrixWater();
    void FUN_004a0c90(float);
};
struct AutoMemContext
{
    int context;
    AutoMemContext(int, bool, const char*, int);
    ~AutoMemContext();
};
struct SaveX
{
    bool FUN_0042ce10();
};
extern SaveX* g_BGSSaveLoadGame;
struct HighProcess
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
    HighProcess();
};
struct SceneX
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual SceneX* AsNode();
    virtual SceneX* AsFade();
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
    virtual void Attach(SceneX*, bool);
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    void FUN_00450f90(bool);
    void FUN_00476ab0();
    void FUN_00440460(const NiPoint3&);
    void FUN_00a5a040();
};
struct IdFlagState
{
    int id, flags, state;
    IdFlagState();
    ~IdFlagState();
    void operator=(const IdFlagState&);
    bool FUN_00ad8ce0();
    bool SetPos(float, float, float);
    bool Play(bool);
};
struct AudioX
{
    IdFlagState FUN_00ad7550(const char*, unsigned);
};
AudioX* FUN_00453a70();
struct SettingX
{
    float* FUN_00403e20();
    int* FUN_0043d4d0();
    unsigned char* FUN_00408d60();
    const char* FUN_00403df0();
};
extern SettingX DAT_011d0520, DAT_011d0280, DAT_011d0da4, DAT_011d0ce4, DAT_011d0a78, DAT_011c7ae8;
struct RefX;
struct BaseX
{
    void* FUN_004fd380();
    float GetScaledValue();
    float FUN_008d01e0();
    int* FUN_004fb810();
};
struct CellX
{
    void RemoveReference(RefX*);
    void AddReference(RefX*, bool);
    SceneX* FUN_005497a0();
    float FUN_005471e0();
};
struct ActorProcX
{
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual void p13();
    virtual void p14();
    virtual void p15();
    virtual void p16();
    virtual void p17();
    virtual void p18();
    virtual void p19();
    virtual void p20();
    virtual void p21();
    virtual void p22();
    virtual void p23();
    virtual void p24();
    virtual void p25();
    virtual void p26();
    virtual void p27();
    virtual void p28();
    virtual void p29();
    virtual void p30();
    virtual void p31();
    virtual void p32();
    virtual void p33();
    virtual void p34();
    virtual void p35();
    virtual void p36();
    virtual void p37();
    virtual void p38();
    virtual void p39();
    virtual void p40();
    virtual void p41();
    virtual void p42();
    virtual void p43();
    virtual void p44();
    virtual void p45();
    virtual void p46();
    virtual void p47();
    virtual void p48();
    virtual void p49();
    virtual void p50();
    virtual void p51();
    virtual void p52();
    virtual void p53();
    virtual void p54();
    virtual void p55();
    virtual void p56();
    virtual void p57();
    virtual void p58();
    virtual void p59();
    virtual void p60();
    virtual void p61();
    virtual void p62();
    virtual void React(RefX*, NiPoint3, int*, int, unsigned);
};
struct ActorX
{
    ActorProcX* FUN_008d8520();
};
struct ActorPtrX
{
    ActorX* FUN_00559450();
};
struct RefX
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
    virtual void SetFlags(unsigned);
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
    virtual ActorPtrX* GetActor();
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
    virtual void Initialize();
    virtual void v114();
    virtual void v115();
    virtual SceneX* GetScene();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual const NiPoint3& GetPosition();
    int unk4;
    int unk8;
    int unkC;
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
    HighProcess* process;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    float animationTime;
    float radius;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    IdFlagState soundAC;
    IdFlagState soundB8;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    bool disabled;

    BaseX* FUN_004181e0();
    float FUN_00644930();
    void FUN_009b2940();
    void FUN_009ad670();
    bool IsNotCulled();
    void FUN_009acd00();
    void* FUN_00575d70();
    CellX* FUN_008d6f30();
    const NiPoint3& FUN_00430830();
    void FUN_009b13a0();
    struct ExtraX* FUN_005d43c0();
    void UpdateCastSound();
    unsigned FUN_009ad610();
    void FUN_009b1090();
    unsigned char GetByteAtOffsetD9();
    void UpdateExplosion();
};
extern RefX* DAT_011dea3c;
struct ExtraX
{
    void FUN_00422220(float);
};
struct HandlerX
{
    void PlaceObjectReference(void*, const NiPoint3&, const NiPoint3&, CellX*, void*, int, int, int);
};
extern HandlerX* DAT_011c3f2c;
struct ProcessListsX
{
    void FUN_0096d450(RefX*, int, bool, int, bool);
};
extern ProcessListsX DAT_011e0e80;
struct ListX
{
    void FUN_0076b660(RefX* const&);
};
extern ListX DAT_011c7b8c;
struct TesX
{
    void FUN_00458e20(SceneX*, float);
};
extern TesX* DAT_011dea10;
struct ImageSpaceEffectParam
{
    float r, g, b, a;
    ImageSpaceEffectParam(float, float, float, float);
};
SceneX* CreateOctahedron(float, const ImageSpaceEffectParam*, int);
void* FUN_009ad630();
void FUN_005299a0(void*, float, SceneX*);
float ComputeSquaredRatioComplement(float, float);
float GetAnimValueByPrefix(SceneX*, const char*, const char*);
void UpdateDistanceFade(float, const NiPoint3&);
float FUN_004a4240();
void FUN_00689210(CellX*, float, const char*, MatrixWater, NiPoint3, float, int, int);
// Updates an explosion reference: scales by distance, spawns effects, updates cell membership, reacts actors, plays splash sounds and applies image-space effects.
// @fnv 0x009acd60
void RefX::UpdateExplosion()
{
    AutoMemContext memory3(49, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\AI\\Combat\\Explosion.cpp", 376);
    bool loading4 = g_BGSSaveLoadGame->FUN_0042ce10();
    bool newProcess2 = (bool)(unsigned char)(process == 0);
    if (newProcess2)
        process = new HighProcess;
    float distance = (DAT_011dea3c->GetPosition() - GetPosition()).Length();
    float scaled = ComputeSquaredRatioComplement(FUN_00644930(), distance);
    if (scaled > *DAT_011d0520.FUN_00403e20() && !disabled)
        FUN_005299a0(FUN_009ad630(), 1.0f, 0);
    FUN_009b2940();
    FUN_009ad670();
    if (IsNotCulled())
        FUN_009acd00();
    else
    {
        if (!loading4 && FUN_004181e0()->FUN_004fd380())
            DAT_011c3f2c->PlaceObjectReference(FUN_004181e0()->FUN_004fd380(), GetPosition(), FUN_00430830(),
                                               FUN_008d6f30(), FUN_00575d70(), 0, 0, 0);
        if (!loading4 && FUN_004181e0()->GetScaledValue() > 0.0 && FUN_004181e0()->FUN_008d01e0() > 0.0)
        {
            FUN_009b13a0();
            FUN_005d43c0()->FUN_00422220(FUN_004181e0()->GetScaledValue());
            SetFlags(0x40000000);
        }
        UpdateCastSound();
        Initialize();
        CellX* cell = FUN_008d6f30();
        if (cell)
        {
            if (!loading4)
                cell->RemoveReference(this);
            cell->AddReference(this, false);
        }
        SceneX* sceneB = GetScene();
        if (sceneB)
            sceneB->FUN_00450f90(scaled > *DAT_011d0520.FUN_00403e20() && !disabled);
        if (sceneB && cell->FUN_005497a0())
            cell->FUN_005497a0()->Attach(sceneB, true);
        SceneX* node7 = sceneB ? sceneB->AsNode() : 0;
        SceneX* fade9 = node7 ? node7->AsFade() : 0;
        if (fade9)
            fade9->FUN_00476ab0();
        animationTime = GetAnimValueByPrefix(sceneB, "SpecialIdle_AreaEffect", "Hit");
    }
    if (!loading4)
    {
        ActorPtrX* actorPointer = GetActor();
        if (actorPointer && actorPointer->FUN_00559450() && actorPointer->FUN_00559450()->FUN_008d8520())
        {
            ActorX* actor = actorPointer->FUN_00559450();
            actor->FUN_008d8520()->React((RefX*)actor, GetPosition(), FUN_004181e0()->FUN_004fb810(), 2,
                                         FUN_009ad610());
        }
        FUN_009b1090();
        if (soundAC.FUN_00ad8ce0() || soundB8.FUN_00ad8ce0())
            UpdateDistanceFade(radius * *DAT_011d0280.FUN_00403e20(), GetPosition());
        if (FUN_008d6f30() && GetByteAtOffsetD9())
        {
            NiPoint3 position8 = GetPosition();
            position8.z = FUN_008d6f30()->FUN_005471e0();
            float size_2 = FUN_00644930() / *DAT_011d0da4.FUN_00403e20();
            MatrixWater rotationA;
            rotationA.FUN_004a0c90(FUN_004a4240());
            FUN_00689210(DAT_011dea3c->FUN_008d6f30(), 1.0f, DAT_011d0ce4.FUN_00403df0(), rotationA, position8, size_2,
                         7, 0);
            IdFlagState sound;
            sound = FUN_00453a70()->FUN_00ad7550("CWaterExplosionSplash", 0x102);
            if (sound.FUN_00ad8ce0())
            {
                sound.SetPos(position8.x, position8.y, position8.z);
                sound.Play(false);
            }
        }
    }
    if (*DAT_011d0a78.FUN_0043d4d0() > 0)
    {
        ImageSpaceEffectParam params(1.0f, 1.0f, 1.0f, 0.65f);
        SceneX* effect2 = CreateOctahedron(2.5f, &params, 1);
        effect2->FUN_00a5a040();
        effect2->FUN_00440460(GetPosition());
        DAT_011dea10->FUN_00458e20(effect2, 10.0f);
    }
    if (newProcess2)
        DAT_011e0e80.FUN_0096d450(this, 0, false, 0, false);
    if (*DAT_011c7ae8.FUN_00408d60())
    {
        DAT_011c7b8c.FUN_0076b660(this);
    }
}

struct DRNode;

struct DRObject3D
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual DRNode* GetAsNode();
};

struct DRController
{
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
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void Stop();
};

template <class T> struct DRPointer
{
    T* m_pObject;

    ~DRPointer();
    operator T*() const;
    T* operator->() const;
    DRPointer& operator=(T* apObject);
};

struct DRItem
{
    ~DRItem();
};

struct DRItemList
{
    DRItem* pItem;
    DRItemList* pNext2;

    ~DRItemList();
    bool IsEmpty();
    DRItem** GetItem();
    void RemoveHead();
};

struct DRSoundHandle
{
    int unk00;
    int unk04;
    int unk08;

    ~DRSoundHandle();
};

struct DRCause;

struct DRCauseHolder
{
    DRCause* pCause;

    ~DRCauseHolder();
    DRCauseHolder& operator=(DRCause* apCause);
};

struct DRDeletable
{
    virtual ~DRDeletable();
};

struct DRPortalGraph
{
    void RemoveObject(DRObject3D* apObject);
};

struct DRWorld
{
    static void __cdecl RemoveObject(DRObject3D* apObject, bool abRecurse, bool abUnk);
};

struct DRCell
{
    DRWorld* GetOwningWorld();
    DRPortalGraph* GetPortalGraph();
};

struct DRDataHandler
{
    bool IsShuttingDown();
};

struct DRSetting
{
    unsigned char* Bool();
};

struct DRRefList
{
    void* GetHeadPos();
    void* GetNextPos(void* apPos);
    struct DRRef*& GetAt(void* apPos);
    struct DRRef* RemovePos(void*& arpPos);
};

void __cdecl DRDetachNode(DRNode* apNode);
bool __cdecl DRIsAttached(DRNode* apNode);

extern DRDataHandler* g_pDRDataHandler;
extern DRSetting g_kDRSetting;
extern DRRefList g_kDRRefList;

struct DRRefPrimary
{
    virtual ~DRRefPrimary();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct DRRefSecondary
{
    virtual void v00();
};

struct DRRef : DRRefPrimary, DRRefSecondary
{
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
    ~DRRef();
    DRObject3D* Get3DSimple();
    DRCell* GetParentCell();
    void FUN_009b12d0();
    void FUN_0092ed60(bool abFlag);
    void FUN_009b11c0();
};

struct FUN_009ac5a0 : DRRef
{
    DRPointer<DRController> spController;
    DRItemList kItems;
    DRSoundHandle kSound1;
    DRSoundHandle kSound2;
    DRPointer<DRController> m_pController;
    int unkC8;
    int unkCC;
    DRCauseHolder kCause;
    int unkD4;
    int unkD8;
    DRDeletable* pOwned;

    virtual ~FUN_009ac5a0();
};

// @fnv 0x009ac5a0
FUN_009ac5a0::~FUN_009ac5a0()
{
    if (Get3DSimple() && Get3DSimple()->GetAsNode() && DRIsAttached(Get3DSimple()->GetAsNode()))
        DRDetachNode(Get3DSimple()->GetAsNode());
    if (GetParentCell() && GetParentCell()->GetOwningWorld() && GetParentCell())
        GetParentCell()->GetOwningWorld()->RemoveObject(Get3DSimple(), true, false);
    if (0)
    {
    }
    FUN_009b12d0();
    if (spController)
        spController->Stop();
    spController = 0;
    while (!kItems.IsEmpty())
    {
        delete *kItems.GetItem();
        kItems.RemoveHead();
    }
    if (!g_pDRDataHandler->IsShuttingDown())
        FUN_0092ed60(false);
    FUN_009b11c0();
    kCause = 0;
    if (pOwned)
        delete pOwned;
    if (*g_kDRSetting.Bool())
    {
        void* pPos7 = g_kDRRefList.GetHeadPos();
        void* pNext2 = 0;
        void* pFound = 0;
        bool bFound = false;
        while (pPos7 && !bFound)
        {
            pNext2 = g_kDRRefList.GetNextPos(pPos7);
            if (pPos7)
            {
                DRRef* pRef = g_kDRRefList.GetAt(pPos7);
                if (pRef == this)
                {
                    bFound = true;
                    pFound = pPos7;
                }
                pPos7 = pNext2;
            }
        }
        g_kDRRefList.RemovePos(pFound);
    }
    DRObject3D* p3D = Get3DSimple();
    DRCell* pCell4 = GetParentCell();
    if (pCell4)
    {
        DRPortalGraph* pGraph = pCell4->GetPortalGraph();
        if (pGraph)
            pGraph->RemoveObject(p3D);
    }
}

class BGSSaveFormBuffer
{
  public:
    void FUN_00865e50(void*, unsigned int, int);
    void FUN_00865df0(void*, int);
    void FUN_00865db0(unsigned int, int);
};
class SavedActorCause
{
  public:
    unsigned int FUN_00825c00();
};
class SavedActorCausePointer
{
  public:
    SavedActorCause* object;
    SavedActorCause* FUN_00559450();
};
class CasterReference
{
  public:
    unsigned int FUN_0040a1e0();
};
class CasterSource
{
  public:
    unsigned int RefreshItem();
};
class ExplosionCasterData
{
  public:
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14;
    CasterReference* reference;
    CasterSource* source;
    void* weapon;
};
class ExplosionSave
{
  public:
    virtual ~ExplosionSave();
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
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    int unk88, unk8C, unk90, unk94, unk98, unk9C;
    unsigned int unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC, unkC0, unkC4;
    void* unkC8;
    void* unkCC;
    SavedActorCausePointer actorCause;
    bool unkD4, unkD5, unkD6, unkD7, unkD8, unkD9;
    unsigned short unkDA;
    ExplosionCasterData* caster;
    void* weapon;
    int frameCount;
    Vec3f pointE8, pointF4;
    int unk100;
    void FUN_00932880(BGSSaveFormBuffer*);
    void WriteToSaveBuffer(BGSSaveFormBuffer*);
};
// Writes explosion save fields, actor cause ID, and optional caster data to the save buffer.
// @fnv 0x009b2040
void ExplosionSave::WriteToSaveBuffer(BGSSaveFormBuffer* buffer)
{
    FUN_00932880(buffer);
    buffer->FUN_00865e50(&unk88, 4, 0);
    buffer->FUN_00865e50(&unk8C, 4, 0);
    buffer->FUN_00865e50(&unk94, 4, 0);
    buffer->FUN_00865e50(&unk98, 4, 0);
    buffer->FUN_00865e50(&unkD4, 1, 0);
    buffer->FUN_00865e50(&frameCount, 4, 0);
    buffer->FUN_00865e50(&unk90, 4, 0);
    buffer->FUN_00865e50(&unk9C, 4, 0);
    buffer->FUN_00865e50(&unkD8, 1, 0);
    buffer->FUN_00865e50(&unkD9, 1, 0);
    buffer->FUN_00865e50(&pointE8, 12, 0);
    buffer->FUN_00865e50(&pointF4, 12, 0);
    buffer->FUN_00865e50(&unk100, 4, 0);
    buffer->FUN_00865df0(unkC8, 0);
    buffer->FUN_00865df0(unkCC, 0);
    buffer->FUN_00865df0(weapon, 0);
    unsigned int causeID = actorCause.FUN_00559450() ? actorCause.FUN_00559450()->FUN_00825c00() : -1;
    buffer->FUN_00865e50(&causeID, 4, 0);
    bool casterPresent = caster;
    buffer->FUN_00865e50(&casterPresent, 1, 0);
    if (casterPresent)
    {
        buffer->FUN_00865db0(caster->reference ? caster->reference->FUN_0040a1e0() : 0, 0);
        buffer->FUN_00865db0(caster->source ? caster->source->RefreshItem() : 0, 0);
        buffer->FUN_00865df0(caster->weapon, 0);
    }
}

struct Base1
{
    int unk00;
};
struct Base2
{
    int unk04;
};
struct FUN_0057c400_shell
{
    Base2* FUN_0057c400(int a);
};
struct FUN_00576870_cls
{
    int unk00;
    FUN_0057c400_shell m_sub;
    Base1* FUN_00576870(int a);
};
struct Derived : Base1, Base2
{
};

// Calls m_sub.FUN_0057c400(a) and returns the result cast to Derived*.
// @fnv 0x00576870
Base1* FUN_00576870_cls::FUN_00576870(int a)
{
    return static_cast<Derived*>(m_sub.FUN_0057c400(a));
}
