
// src/fallout/magic/telekinesiseffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/telekinesiseffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_0082a510_shell
{
    void FUN_0082a540();
    void* DestroyIfFlagged(unsigned int flags);
};

void __cdecl _Deallocate(void*);

// Calls FUN_0082a540, then deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x0082a510
void* FUN_0082a510_shell::DestroyIfFlagged(unsigned int flags)
{
    FUN_0082a540();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_0082aab0_shell
{
    void SetField644(float value);
};

// @fnv 0x0082aab0
void FUN_0082aab0_shell::SetField644(float value)
{
    *(float*)((char*)this + 0x644) = value;
}

struct FUN_0082af40_shell
{
    float fTelekinesisStrength;  // +0x644
    float GetTelekinesisStrength();
};

// @fnv 0x0082af40
float FUN_0082af40_shell::GetTelekinesisStrength()
{
    return *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x644);
}

struct Actor
{
};
struct ValueModifierEffect
{
    unsigned short __thiscall FUN_00802d90(Actor* apActor);
};
struct TelekinesisEffect : ValueModifierEffect
{
    unsigned short __thiscall FUN_0082b190(Actor* apActor);
};
struct FUN_008df040_shell
{
    unsigned char __thiscall FUN_008df040();
};
extern FUN_008df040_shell* g_TESSaveLoadGame;

// Returns the effect's save size: base size from FUN_00802d90 plus 4, plus 8 more when the save version is at least 0x40.
// @fnv 0x0082b190
unsigned short __thiscall TelekinesisEffect::FUN_0082b190(Actor* apActor)
{
    unsigned short uiSaveSize = 0;
    uiSaveSize += FUN_00802d90(apActor);
    uiSaveSize += 4;
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x40)
    {
        uiSaveSize += 4;
        uiSaveSize += 4;
    }
    return uiSaveSize;
}

namespace fnv_0082b290 {
struct Actor;
struct TESSaveLoadGame;

struct ValueModifierEffect
{
    void FUN_00802dd0(Actor* apActor);
};

struct TESSaveLoadGame_shell
{
    void FUN_00857aa0(unsigned int* pOut, unsigned int size);
    void FUN_008579e0(void* pOut, unsigned int size);
    unsigned char FUN_008df040();
};

extern TESSaveLoadGame* g_TESSaveLoadGame;

struct TelekinesisEffect : ValueModifierEffect
{
    void LoadFromSave(Actor* apActor);
};

// @fnv 0x0082b290
void TelekinesisEffect::LoadFromSave(Actor* apActor)
{
    ValueModifierEffect::FUN_00802dd0(apActor);
    unsigned int irefID;
    ((TESSaveLoadGame_shell*)g_TESSaveLoadGame)->FUN_00857aa0(&irefID, 4);
    *(unsigned int*)((char*)this + 0x58) = irefID;
    if (((TESSaveLoadGame_shell*)g_TESSaveLoadGame)->FUN_008df040() >= 0x40)
    {
        ((TESSaveLoadGame_shell*)g_TESSaveLoadGame)->FUN_008579e0((void*)((char*)this + 0x50), 4);
        ((TESSaveLoadGame_shell*)g_TESSaveLoadGame)->FUN_008579e0((void*)((char*)this + 0x54), 4);
    }
}
}  // namespace fnv_0082b290

struct FUN_0082a670_shell
{
    void __thiscall FUN_0082a670();
    void __thiscall FUN_0082c000();
    void __thiscall StartTelekinesisEffect();
};

void* __cdecl FUN_00703390();

// Calls FUN_0082c000, stores the result of FUN_00703390 at offset 0x58, calls StartTelekinesisEffect, and clears the byte at offset 0x5d.
// @fnv 0x0082a670
void __thiscall FUN_0082a670_shell::FUN_0082a670()
{
    FUN_0082c000();
    *(void**)((char*)this + 0x58) = FUN_00703390();
    StartTelekinesisEffect();
    *(char*)((char*)this + 0x5d) = 0;
}

struct Flt
{
    operator unsigned int();
};

struct FUN_0082aa90_shell
{
    unsigned int GetFloatAsUInt();
};

// @fnv 0x0082aa90
unsigned int __thiscall FUN_0082aa90_shell::GetFloatAsUInt()
{
    return ((Flt*)((char*)this + 0x634))->operator unsigned int();
}

void* __cdecl FUN_004b5a80(void const*);

struct FUN_0082aeb0_shell
{
    void* __thiscall FUN_0082aee0();
    void* __thiscall FUN_0082aeb0();
};

// Calls FUN_0082aee0 and passes its result to FUN_004b5a80, returning that value.
// @fnv 0x0082aeb0
void* __thiscall FUN_0082aeb0_shell::FUN_0082aeb0()
{
    void* result = FUN_0082aee0();
    return FUN_004b5a80(result);
}

struct GO
{
    ~GO();
};
struct FUN_0080d930
{
    ~FUN_0080d930();
};
struct FUN_0082a540 : FUN_0080d930
{
    char _pad[0x4C];
    GO _go;
    ~FUN_0082a540();
};
// Destructor for FUN_0082a540; destroys its GO member and the FUN_0080d930 base.
// @fnv 0x0082a540
FUN_0082a540::~FUN_0082a540()
{}

struct ScriptLocalsX
{
    void* __thiscall GetLocalData();
};
struct Calendar
{
    unsigned int __thiscall GetDaysPassed();
};
struct FUN_0082aee0_shell
{
    unsigned int __thiscall FUN_0082aee0();
};
// @fnv 0x0082aee0
unsigned int FUN_0082aee0_shell::FUN_0082aee0()
{
    Calendar* calendar = reinterpret_cast<Calendar*>((reinterpret_cast<ScriptLocalsX*>(this))->GetLocalData());
    return calendar ? calendar->GetDaysPassed() : 0;
}

struct FUN_0082af20_shell
{
    unsigned int __thiscall GetField63C();
};
// @fnv 0x0082af20
unsigned int __thiscall FUN_0082af20_shell::GetField63C()
{
    return *(unsigned int*)((char*)this + 0x63c);
}

struct TESChallenge
{
    void* GetFormTwo();
};
struct ActiveEffect
{
    TESChallenge* __thiscall GetEffectSetting();
};
struct FUN_0082afa0_shell
{
    void __thiscall FUN_0082afa0();
};
struct FUN_0082c810_shell
{
    void __thiscall ApplyEffect();
};
struct FUN_00974a50_shell
{
    void __thiscall FUN_00974a50(void* a, void* b);
};
extern int DAT_011e0e80;
struct FUN_0082af60_shell
{
    void __thiscall FUN_0082af60();
};
// @fnv 0x0082af60
void __thiscall FUN_0082af60_shell::FUN_0082af60()
{
    ((FUN_0082afa0_shell*)this)->FUN_0082afa0();
    ((FUN_00974a50_shell*)(&DAT_011e0e80))
        ->FUN_00974a50(*(void**)((char*)this + 0x58), ((ActiveEffect*)this)->GetEffectSetting()->GetFormTwo());
    ((FUN_0082c810_shell*)this)->ApplyEffect();
}

struct FUN_0082a460
{
    char buf[0x60];
    FUN_0082a460(int, int, int);
};
// Allocates and constructs a FUN_0082a460 object from x, y and z, returning the new instance.
// @fnv 0x0082b110
FUN_0082a460* __cdecl CreateFUN_0082a460(int x, int y, int z)
{
    return new FUN_0082a460(x, y, z);
}

struct FUN_0080dfd0_shell
{
    void FUN_00802db0(Actor* apActor);
};
struct TESSaveLoadGame
{
    void FUN_00857a10(int, int);
    unsigned char FUN_008df040();
    void FUN_008579b0(void*, int);
};
struct ref_0084e3a0_shell
{
    unsigned int ref_0084e3a0();
};
struct FUN_0082b200_shell : FUN_0080dfd0_shell
{
    void SaveLoad(Actor* apActor);
};
// @fnv 0x0082b200
void FUN_0082b200_shell::SaveLoad(Actor* apActor)
{
    unsigned int irefID;
    FUN_00802db0(apActor);
    irefID = 0;
    if (*(unsigned int*)((char*)this + 0x58))
        irefID = ((ref_0084e3a0_shell*)*(unsigned int*)((char*)this + 0x58))->ref_0084e3a0();
    ((TESSaveLoadGame*)g_TESSaveLoadGame)->FUN_00857a10((int)&irefID, 4);
    if (((TESSaveLoadGame*)g_TESSaveLoadGame)->FUN_008df040() >= 0x40)
    {
        ((TESSaveLoadGame*)g_TESSaveLoadGame)->FUN_008579b0((char*)this + 0x50, 4);
        ((TESSaveLoadGame*)g_TESSaveLoadGame)->FUN_008579b0((char*)this + 0x54, 4);
    }
}

struct TESObjectREFR
{
    virtual ~TESObjectREFR();
};
struct TESForm
{
    virtual ~TESForm();
};
TESForm* __cdecl GetFormByID(unsigned int id);
struct InvisibilityEffect
{
    void FUN_0082cd10(Actor*);
};
struct FUN_0082b300_shell : InvisibilityEffect
{
    void StartTelekinesisEffect();
    void FUN_0082b300(Actor* apActor);
};
// @fnv 0x0082b300
void FUN_0082b300_shell::FUN_0082b300(Actor* apActor)
{
    FUN_0082cd10(apActor);
    TESObjectREFR* pRef = *reinterpret_cast<TESObjectREFR**>(reinterpret_cast<unsigned char*>(this) + 0x58);
    if (pRef)
        *reinterpret_cast<TESObjectREFR**>(reinterpret_cast<unsigned char*>(this) + 0x58) =
            dynamic_cast<TESObjectREFR*>(GetFormByID(reinterpret_cast<unsigned int>(pRef)));
    if (*reinterpret_cast<TESObjectREFR**>(reinterpret_cast<unsigned char*>(this) + 0x58))
        StartTelekinesisEffect();
    *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(this) + 0x5d) = 1;
}

void* __cdecl operator new(unsigned int);

struct FUN_0082a5a0_shell
{
    virtual void v00()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03()
    {}
    virtual void v04()
    {}
    virtual void v05()
    {}
    virtual void v06()
    {}
    virtual void v07()
    {}
    virtual void v08()
    {}
    virtual void v09()
    {}
    virtual void v10()
    {}
    virtual void v11()
    {}
    virtual void v12()
    {}
    virtual void v13()
    {}
    virtual void v14()
    {}
    virtual void v15()
    {}
    virtual void v16()
    {}
    virtual void CopyFrom(ActiveEffect* copy)
    {}
    ActiveEffect* CreateCopy();
};

// @fnv 0x0082a5a0
ActiveEffect* FUN_0082a5a0_shell::CreateCopy()
{
    ActiveEffect* copy = reinterpret_cast<ActiveEffect*>(
        new FUN_0082a460(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x28),
                         *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x08),
                         *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x0C)));

    CopyFrom(copy);
    return copy;
}

struct NiPoint3
{
    float x, y, z;
    NiPoint3();
    NiPoint3 operator-(const NiPoint3&) const;
    float Dot(const NiPoint3&) const;
    NiPoint3& operator*=(float);
};
struct bhkFilter
{
    unsigned int value;
    int FUN_0043b4d0();
};
struct bhkWorldObject
{
    bhkFilter FUN_0043b4f0();
    void* FUN_004ae750();
};
struct bhkCollisionObject
{
    bhkWorldObject* FUN_006fa820();
};
struct SceneObject
{
};
bhkCollisionObject* __cdecl FUN_004b5260(SceneObject*);
void __cdecl FUN_00807ac0(bhkWorldObject*);
struct ReferenceForm
{
    int FUN_00401170();
};
struct TelekinesisReference
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
    virtual SceneObject* GetSceneObject();
    ReferenceForm* GetObjectReference();
};
struct MagicCaster
{
};
struct ShaderDefinition
{
};
struct EffectSettingX
{
    ShaderDefinition* GetEffectShader();
};
struct TelekinesisStartEffect
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
    float magnitude;
    unsigned int unk54;
    TelekinesisReference* target;
    MagicCaster* FUN_0045cd60();
    void Dispel(bool);
    EffectSettingX* GetEffectSetting();
    void StartTelekinesisEffect();
};
struct TelekinesisConstraint
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    TelekinesisConstraint(TelekinesisReference*, bhkWorldObject*, unsigned int);
};
struct NiRTTI
{
};
struct NiObject
{
    void FUN_00b4dec0(int);
};
extern NiRTTI DAT_011f9140;
NiObject* __cdecl FUN_00653270(const NiRTTI*, SceneObject*);
struct PlayerCharacter
{
    MagicCaster* GetFloatAsUInt();
    void FUN_00961280();
    void FUN_0095f930(TelekinesisReference*, int, float);
    void GetCameraPosAndDir(NiPoint3*, NiPoint3*, bool);
    void SetField644(float);
};
struct CasterPosition
{
    void ApplyTurnUndeadEffect(NiPoint3*);
};
extern PlayerCharacter* g_thePlayer;
struct LoadingState
{
    bool FUN_0047c850();
};
extern float DAT_01022958;
extern const float DAT_01012054;
struct ShaderEffect
{
    virtual ~ShaderEffect();
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
    virtual bool Start();
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
    static void* operator new(unsigned int);
    static void operator delete(void*);
    ShaderEffect(TelekinesisReference*, ShaderDefinition*, float);
};
struct EffectManager
{
    void FUN_00973fd0(ShaderEffect*);
};

// Validates the target's collision object, creates a TelekinesisConstraint, applies the telekinesis effect to the player, and starts the effect shader.
// @fnv 0x0082a6a0
void TelekinesisStartEffect::StartTelekinesisEffect()
{
    if (!target || !FUN_0045cd60())
    {
        Dispel(false);
        return;
    }
    switch (target->GetObjectReference()->FUN_00401170())
    {
    case 27:
        Dispel(false);
        return;
    }
    SceneObject* h = target->GetSceneObject();
    bhkCollisionObject* a = h ? FUN_004b5260(h) : 0;
    bhkWorldObject* i = a ? a->FUN_006fa820() : 0;
    if (i)
        FUN_00807ac0(i);
    if (!i || (i->FUN_0043b4f0().FUN_0043b4d0() != 4 && i->FUN_0043b4f0().FUN_0043b4d0() != 5))
    {
        Dispel(false);
        return;
    }
    void* p = i->FUN_004ae750();
    new TelekinesisConstraint(target, i, i->FUN_0043b4f0().value);
    NiObject* eb = FUN_00653270(&DAT_011f9140, h);
    if (eb)
        eb->FUN_00b4dec0(6);
    if (g_thePlayer->GetFloatAsUInt())
        g_thePlayer->FUN_00961280();
    if (!((LoadingState*)g_TESSaveLoadGame)->FUN_0047c850())
        magnitude = DAT_01022958;
    g_thePlayer->FUN_0095f930(target, 3, magnitude);
    NiPoint3 s;
    NiPoint3 f;
    g_thePlayer->GetCameraPosAndDir(&s, &f, true);
    if (!((LoadingState*)g_TESSaveLoadGame)->FUN_0047c850())
    {
        NiPoint3 casterPosition;
        ((CasterPosition*)g_thePlayer->GetFloatAsUInt())->ApplyTurnUndeadEffect(&casterPosition);
        NiPoint3 p = casterPosition - s;
        magnitude = f.Dot(p);
        g_thePlayer->SetField644(magnitude);
        f *= magnitude;
    }
    if (GetEffectSetting()->GetEffectShader())
    {
        ShaderEffect* shader = new ShaderEffect(target, GetEffectSetting()->GetEffectShader(), DAT_01012054);
        if (shader->Start())
            ((EffectManager*)&DAT_011e0e80)->FUN_00973fd0(shader);
        else
            delete shader;
    }
}

struct World
{
};
struct Cell
{
    World* FUN_004543c0();
};
struct Ref
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
    virtual Ref* GetReference();
    Cell* FUN_008d6f30();
};
struct Target
{
    void* FUN_0082aeb0();
};
struct Player
{
    Target* GetFloatAsUInt();
    Ref* FUN_0089f4e0();
    unsigned int GetField63C();
    float GetTelekinesisStrength();
    void SetField644(float);
    void FUN_00960520(float);
};
extern Player* DAT_011dea3c;
struct Input
{
    int FUN_00a24660(int, int);
};
struct OS
{
    Input* FUN_00877720();
};
extern OS* DAT_011dea0c;
struct Setting
{
    float* FUN_00403e20();
};
extern Setting originalRuntimeFloatSetting1168;
extern Setting originalRuntimeFloatSetting1169;
extern Setting originalRuntimeFloatSetting1170;
extern Setting originalRuntimeFloatSetting1171;
extern Setting originalRuntimeFloatSetting1112;
extern Setting g_011d18fc;
struct Effect
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
    float strength;
    float velocity;
    Ref* target;
    bool released;
    bool skipCost;
    void FUN_0082c660(float);
    void Remove(bool);
    Ref* FUN_0045cd60();
    float GetFloatAtOffset1C();
    void UpdateGrabEffect(float delta);
};
// Advances the grab effect: checks the player's grab target and world, updates velocity/strength from input and settings, applies strength and charges cost.
// @fnv 0x0082aad0
void Effect::UpdateGrabEffect(float delta)
{
    FUN_0082c660(delta);
    Target* grab = DAT_011dea3c->GetFloatAsUInt();
    if (!grab->FUN_0082aeb0())
    {
        Remove(false);
        return;
    }
    World* casterWorld = FUN_0045cd60() && DAT_011dea3c->FUN_0089f4e0()->FUN_008d6f30()
                             ? FUN_0045cd60()->GetReference()->FUN_008d6f30()->FUN_004543c0()
                             : 0;
    World* playerWorld = DAT_011dea3c->FUN_0089f4e0() && DAT_011dea3c->FUN_0089f4e0()->FUN_008d6f30()
                             ? DAT_011dea3c->FUN_0089f4e0()->FUN_008d6f30()->FUN_004543c0()
                             : 0;
    if (!grab || target != DAT_011dea3c->FUN_0089f4e0() || DAT_011dea3c->GetField63C() != 3 ||
        casterWorld != playerWorld)
    {
        Remove(false);
        return;
    }
    if (DAT_011dea0c->FUN_00877720()->FUN_00a24660(6, 0) && DAT_011dea0c->FUN_00877720()->FUN_00a24660(4, 0))
    {
        if (velocity >
            *originalRuntimeFloatSetting1168.FUN_00403e20() + *originalRuntimeFloatSetting1169.FUN_00403e20() * 0.1f)
            released = true;
        Remove(false);
    }
    else if (DAT_011dea0c->FUN_00877720()->FUN_00a24660(4, 0))
    {
        if (velocity < *originalRuntimeFloatSetting1168.FUN_00403e20())
            velocity = *originalRuntimeFloatSetting1168.FUN_00403e20();
        velocity += *originalRuntimeFloatSetting1169.FUN_00403e20() * delta;
        if (velocity > *originalRuntimeFloatSetting1170.FUN_00403e20())
            velocity = *originalRuntimeFloatSetting1170.FUN_00403e20();
    }
    else if (DAT_011dea0c->FUN_00877720()->FUN_00a24660(6, 0))
    {
        if (velocity > -*originalRuntimeFloatSetting1168.FUN_00403e20())
            velocity = -*originalRuntimeFloatSetting1168.FUN_00403e20();
        velocity -= *originalRuntimeFloatSetting1169.FUN_00403e20() * delta;
        if (velocity < -*originalRuntimeFloatSetting1170.FUN_00403e20())
            velocity = -*originalRuntimeFloatSetting1170.FUN_00403e20();
    }
    else
        velocity = 0.0f;
    strength = DAT_011dea3c->GetTelekinesisStrength();
    strength += velocity * delta;
    if (strength < *originalRuntimeFloatSetting1171.FUN_00403e20())
        strength = *originalRuntimeFloatSetting1171.FUN_00403e20();
    if (strength > *originalRuntimeFloatSetting1112.FUN_00403e20() * GetFloatAtOffset1C() * *g_011d18fc.FUN_00403e20())
        strength = *originalRuntimeFloatSetting1112.FUN_00403e20() * GetFloatAtOffset1C() * *g_011d18fc.FUN_00403e20();
    DAT_011dea3c->SetField644(strength);
    if (!skipCost)
        DAT_011dea3c->FUN_00960520(delta);
    skipCost = false;
}

namespace fnv_b4214 {
class FUN_0082a460_base
{
  public:
    virtual ~FUN_0082a460_base();
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

    FUN_0082a460_base(int a, int b, int c);
};

class FUN_0082a460_member
{
  public:
    int m_iWordAt00;

    FUN_0082a460_member(bool flag);
    ~FUN_0082a460_member();
    void Apply(int value);
};

class FUN_0082a460 : public FUN_0082a460_base
{
  public:
    FUN_0082a460_member m_4c;
    float m_50;
    float m_54;
    int m_58;
    unsigned char m_5c;
    unsigned char m_5d;

    FUN_0082a460(int a, int b, int c);
    virtual ~FUN_0082a460();
};
}

// Initializes the base class, sets m_4c to false and applies 0, then zeroes m_50, m_54, m_58, m_5c, and m_5d.
// @fnv 0x0082a460
fnv_b4214::FUN_0082a460::FUN_0082a460(int aiParam1, int aiParam2, int aiParam3)
    : fnv_b4214::FUN_0082a460_base(aiParam1, aiParam2, aiParam3), m_4c(false)
{
    m_4c.Apply(0);
    m_50 = 0.0f;
    m_54 = 0.0f;
    m_58 = 0;
    m_5c = 0;
    m_5d = 0;
}
