
// src/fallout/ai/combat/combatproceduremove.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/combatproceduremove.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct CombatProcedureMove
{
    void FUN_009d6ba0();
    void* DestroyIfFlagged(unsigned int flags);
};

// @fnv 0x009d6b70
void* CombatProcedureMove::DestroyIfFlagged(unsigned int flags)
{
    FUN_009d6ba0();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_009d7bd0_shell
{
    bool IsFlagSet(unsigned int flags);
};

// Tests whether the bit selected by flags is set in the 32-bit mask at offset 0x90 of this object.
// @fnv 0x009d7bd0
bool FUN_009d7bd0_shell::IsFlagSet(unsigned int flags)
{
    return ((1 << flags) & *(unsigned int*)((char*)this + 0x90)) ? true : false;
}

struct CombatTargetTimestamp
{
    int v;
    CombatTargetTimestamp(float);
};
struct Holder
{
    void SetValue(float);
};
// @fnv 0x009d8410
void Holder::SetValue(float afValue)
{
    CombatTargetTimestamp t(afValue);
    *(int*)((char*)this + 0xC0) = t.v;
}

extern float DAT_010162c0;
struct S009d8440
{
    float FUN_009d8440();
};
// @fnv 0x009d8440
float S009d8440::FUN_009d8440()
{
    switch (*(int*)((char*)this + 0x3C))
    {
    case 6:
    case 7:
        return DAT_010162c0;
    case 8:
        return 0.5f;
    default:
        return 1.0f;
    }
}

struct TESObjectREFR;
struct CombatProcedureAttackRanged
{
    void FUN_009caac0(char const*);
};
struct MoveHolder
{
    void ClearTargetRef(TESObjectREFR*);
};
// If the reference stored at offset 0x38 matches apRef, clears it to null and logs that the targeted reference pointer was cleared.
// @fnv 0x009d8480
void MoveHolder::ClearTargetRef(TESObjectREFR* apRef)
{
    if (*(TESObjectREFR**)((char*)this + 0x38) == apRef)
    {
        *(TESObjectREFR**)((char*)this + 0x38) = 0;
        ((CombatProcedureAttackRanged*)this)->FUN_009caac0("Targeted reference pointer was cleared");
    }
}

struct FUN_009d6c80_shell
{
    void FUN_009d6c80();
};
struct IMH
{
    FUN_009d6c80_shell* FUN_00586150();
};
struct FUN_009d84b0_shell
{
    void FUN_009d84b0();
};
// If the bool at offset 0x54 is set, calls FUN_009d6c80 through the object at offset 4 and clears the flag.
// @fnv 0x009d84b0
void FUN_009d84b0_shell::FUN_009d84b0()
{
    if (*(bool*)((char*)this + 0x54))
    {
        ((IMH*)*(IMH**)((char*)this + 4))->FUN_00586150()->FUN_009d6c80();
        *(bool*)((char*)this + 0x54) = 0;
    }
}

namespace fnv_009d84e0 {
struct Tile;
struct IMH
{
    Tile* FUN_00586150();
};
struct FUN_009d7c20_shell
{
    void FUN_009d7c20();
};
struct FUN_009d84e0_shell
{
    void FUN_009d84e0();
};
// @fnv 0x009d84e0
void FUN_009d84e0_shell::FUN_009d84e0()
{
    if (reinterpret_cast<int*>(this)[4] == 2 || reinterpret_cast<int*>(this)[4] == 3)
    {
        reinterpret_cast<FUN_009d7c20_shell*>(reinterpret_cast<IMH*>(reinterpret_cast<int*>(this)[1])->FUN_00586150())
            ->FUN_009d7c20();
        *reinterpret_cast<char*>(this + 0x54) = 1;
    }
}
}  // namespace fnv_009d84e0

struct Actor
{
    void StopMoving();
};
struct TESAmmoInitCalls
{
    Actor* GetFieldBC();
};
struct FUN_00666f00_shell
{
    bool FUN_00666f00();
};
struct CombatProcedure
{
    void RunProcedure();
};
struct CombatProcedureEngageTarget
{
    void FUN_00996e40();
};
struct FUN_009d6c00_shell : CombatProcedureEngageTarget
{
    Actor* GetFieldBC();
    bool FUN_00666f00();
    void UpdateCombatMovement();
};
// @fnv 0x009d6c00
void FUN_009d6c00_shell::UpdateCombatMovement()
{
    Actor* attacker = ((TESAmmoInitCalls*)*(void**)((char*)this + 4))->GetFieldBC();
    if (*(int*)((char*)this + 0x10) == 1 || *(int*)((char*)this + 0x10) == 2)
    {
        if (!FUN_00666f00())
            attacker->StopMoving();
    }
    else if (*(int*)((char*)this + 0x10) == 3)
        ((CombatProcedure*)this)->RunProcedure();
    FUN_00996e40();
    if (*(bool*)((char*)this + 0x54))
        ((IMH*)*(void**)((char*)this + 4))->FUN_00586150()->FUN_009d6c80();
}

struct BGSSaveFormBuffer;
struct BGSSaveFormBufferSaveGameHelper;

struct SaveFormIDHelper
{
    void SerializeFormData(void* formID, int flag);
};

struct BGSSaveFormBuffer : SaveFormIDHelper
{
    void SaveData(void* data, unsigned short size, unsigned short value);
};

struct CombatProcedureSaveGameHelper
{
    void SaveGame(BGSSaveFormBuffer* buffer);
};

struct CoordinateTriple
{
    void FUN_00527b70(void* buffer);
};

struct GO
{
    operator unsigned int() const;
};

struct FUN_009a5eb0_shell
{
    void FUN_009a5eb0(BGSSaveFormBuffer* buffer);
};

struct FUN_009d8880_shell
{
    void FUN_009d8880(BGSSaveFormBuffer* buffer);
};

// @fnv 0x009d8880
void FUN_009d8880_shell::FUN_009d8880(BGSSaveFormBuffer* buffer)
{
    reinterpret_cast<CombatProcedureSaveGameHelper*>(this)->SaveGame(buffer);

    buffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x10), 4, 0);

    reinterpret_cast<CoordinateTriple*>(reinterpret_cast<char*>(this) + 0x14)->FUN_00527b70(buffer);
    reinterpret_cast<CoordinateTriple*>(reinterpret_cast<char*>(this) + 0x24)->FUN_00527b70(buffer);

    buffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x34), 4, 0);

    buffer->SerializeFormData(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x38), 0);

    buffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x3C), 4, 0);

    buffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x60), 4, 0);

    reinterpret_cast<FUN_009a5eb0_shell*>(reinterpret_cast<char*>(this) + 0x64)->FUN_009a5eb0(buffer);
    reinterpret_cast<FUN_009a5eb0_shell*>(reinterpret_cast<char*>(this) + 0x40)->FUN_009a5eb0(buffer);
    reinterpret_cast<FUN_009a5eb0_shell*>(reinterpret_cast<char*>(this) + 0x6C)->FUN_009a5eb0(buffer);
    reinterpret_cast<FUN_009a5eb0_shell*>(reinterpret_cast<char*>(this) + 0x74)->FUN_009a5eb0(buffer);

    buffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x48), 0x0C, 0);

    buffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x54), 1, 0);

    *reinterpret_cast<bool*>(reinterpret_cast<char*>(this) + 0x5C) =
        reinterpret_cast<const GO*>(reinterpret_cast<char*>(this) + 0x58)->operator unsigned int();

    buffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x5C), 1, 0);
}

struct BGSLoadFormBuffer
{
    bool ReadFormIdentifier(void*);
    void ReadTypedData(void*, unsigned int);
    virtual unsigned char GetVersion();
};

struct FUN_00527ba0_Class
{
    void FUN_00527ba0(void*);
};

struct TimeoutTimer
{
    void LoadGame(BGSLoadFormBuffer*);
};

struct CombatProcedureLoadGameHelper
{
    void LoadGame(BGSLoadFormBuffer*);
};

struct FUN_009d89a0_shell : CombatProcedureMove
{
    void FUN_009d89a0(BGSLoadFormBuffer*);
};

// @fnv 0x009d89a0
void FUN_009d89a0_shell::FUN_009d89a0(BGSLoadFormBuffer* buffer)
{
    ((CombatProcedureLoadGameHelper*)this)->LoadGame(buffer);

    buffer->ReadTypedData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x10), 4);

    reinterpret_cast<FUN_00527ba0_Class*>(reinterpret_cast<char*>(this) + 0x14)->FUN_00527ba0(buffer);

    reinterpret_cast<FUN_00527ba0_Class*>(reinterpret_cast<char*>(this) + 0x24)->FUN_00527ba0(buffer);

    buffer->ReadTypedData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x34), 4);

    buffer->ReadFormIdentifier(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x38));

    buffer->ReadTypedData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x3c), 4);

    buffer->ReadTypedData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x60), 4);

    reinterpret_cast<TimeoutTimer*>(reinterpret_cast<char*>(this) + 0x64)->LoadGame(buffer);

    reinterpret_cast<TimeoutTimer*>(reinterpret_cast<char*>(this) + 0x40)->LoadGame(buffer);

    reinterpret_cast<TimeoutTimer*>(reinterpret_cast<char*>(this) + 0x6c)->LoadGame(buffer);

    if (buffer->GetVersion() >= 8)
    {
        reinterpret_cast<TimeoutTimer*>(reinterpret_cast<char*>(this) + 0x74)->LoadGame(buffer);
    }

    buffer->ReadTypedData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x48), 0xc);

    buffer->ReadTypedData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x54), 1);

    if (buffer->GetVersion() >= 0xc)
    {
        buffer->ReadTypedData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x5c), 1);
    }
}

struct FUN_009ca680
{
    virtual ~FUN_009ca680();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    FUN_009ca680();
};
struct FUN_0097ede0
{
    unsigned int x, y, z, w;
    FUN_0097ede0();
};
struct FUN_00906f60
{
    unsigned int x, y;
    FUN_00906f60();
};
struct FUN_006815c0
{
    unsigned int x, y, z;
    FUN_006815c0();
};
struct FUN_00633c90
{
    unsigned int value;
    FUN_00633c90(int);
    ~FUN_00633c90();
};
struct MoveInput
{
    FUN_0097ede0* FUN_006815c0();
    unsigned int FUN_0044edb0();
    bool FUN_0097be60(int);
};
struct FUN_009d69f0 : FUN_009ca680
{
    unsigned int unk10;
    FUN_0097ede0 startTransform;
    FUN_0097ede0 currentTransform;
    float rate;
    unsigned int target38;
    unsigned int mode;
    FUN_00906f60 pos40;
    FUN_006815c0 pos48;
    bool active54;
    FUN_00633c90 state58;
    bool active5C;
    int unk60;
    FUN_00906f60 state64;
    FUN_00906f60 state6C;
    FUN_00906f60 state74;
    FUN_009d69f0(MoveInput* input, float speed, unsigned int flags);
    virtual ~FUN_009d69f0();
};
// @fnv 0x009d69f0
FUN_009d69f0::FUN_009d69f0(MoveInput* input, float speed, unsigned int flags)
    : unk10(0), startTransform(), currentTransform(), rate(speed), target38(0), mode(flags), pos40(), pos48(),
      active54(false), state58(0), active5C(false), unk60(-1), state64(), state6C(), state74()
{
    if (input)
    {
        startTransform = *input->FUN_006815c0();
        currentTransform = startTransform;
        target38 = input->FUN_0044edb0();
        if (input->FUN_0097be60(2))
            rate = -rate;
    }
}

class C9D6BA0Ptr
{
  public:
    ~C9D6BA0Ptr();

    void* m_pObject;
};

class C9D6BA0Base
{
  public:
    virtual ~C9D6BA0Base();

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
};

class FUN_009d6ba0 : public C9D6BA0Base
{
  public:
    virtual ~FUN_009d6ba0();

    C9D6BA0Ptr m_spReferencedObject;
};

// @fnv 0x009d6ba0
FUN_009d6ba0::~FUN_009d6ba0()
{}

struct TargetActor;
struct ActorVTable
{
    void* unk000;
    void* unk004;
    void* unk008;
    void* unk00c;
    void* unk010;
    void* unk014;
    void* unk018;
    void* unk01c;
    void* unk020;
    void* unk024;
    void* unk028;
    void* unk02c;
    void* unk030;
    void* unk034;
    void* unk038;
    void* unk03c;
    void* unk040;
    void* unk044;
    void* unk048;
    void* unk04c;
    void* unk050;
    void* unk054;
    void* unk058;
    void* unk05c;
    void* unk060;
    void* unk064;
    void* unk068;
    void* unk06c;
    void* unk070;
    void* unk074;
    void* unk078;
    void* unk07c;
    void* unk080;
    void* unk084;
    void* unk088;
    void* unk08c;
    void* unk090;
    void* unk094;
    void* unk098;
    void* unk09c;
    void* unk0a0;
    void* unk0a4;
    void* unk0a8;
    void* unk0ac;
    void* unk0b0;
    void* unk0b4;
    void* unk0b8;
    void* unk0bc;
    void* unk0c0;
    void* unk0c4;
    void* unk0c8;
    void* unk0cc;
    void* unk0d0;
    void* unk0d4;
    void* unk0d8;
    void* unk0dc;
    void* unk0e0;
    void* unk0e4;
    void* unk0e8;
    void* unk0ec;
    void* unk0f0;
    void* unk0f4;
    void* unk0f8;
    void* unk0fc;
    void* unk100;
    void* unk104;
    void* unk108;
    void* unk10c;
    void* unk110;
    void* unk114;
    void* unk118;
    void* unk11c;
    void* unk120;
    void* unk124;
    void* unk128;
    void* unk12c;
    void* unk130;
    void* unk134;
    void* unk138;
    void* unk13c;
    void* unk140;
    void* unk144;
    void* unk148;
    void* unk14c;
    void* unk150;
    void* unk154;
    void* unk158;
    void* unk15c;
    void* unk160;
    void* unk164;
    void* unk168;
    void* unk16c;
    void* unk170;
    void* unk174;
    void* unk178;
    void* unk17c;
    void* unk180;
    void* unk184;
    void* unk188;
    void* unk18c;
    void* unk190;
    void* unk194;
    void* unk198;
    void* unk19c;
    void* unk1a0;
    void* unk1a4;
    void* unk1a8;
    void* unk1ac;
    void* unk1b0;
    void* unk1b4;
    void* unk1b8;
    void* unk1bc;
    void* unk1c0;
    void* unk1c4;
    void* unk1c8;
    void* unk1cc;
    void* unk1d0;
    void* unk1d4;
    void* unk1d8;
    void* unk1dc;
    void* unk1e0;
    void* unk1e4;
    void* unk1e8;
    void* unk1ec;
    void* unk1f0;
    void*(__thiscall* get)(TargetActor*, TargetActor*, float);
};
struct TargetActor
{
    ActorVTable* vtable;
};
struct ResultValue
{
    void* BuildAvoidanceNodes();
    void* FUN_00989490();
    void* FUN_009892a0(void*);
};
struct ManagerValue
{
    ResultValue* FUN_00825c00(void*);
};
extern ManagerValue* DAT_011f1958;
extern const float DAT_01012054;
extern float FUN_00435dd0();
struct OutputValue
{
    void Assign(void*);
    void* FUN_00559450();
};
struct MemberValue
{
    void* FUN_006815c0(float, void*);
};
struct IMValue
{
    Holder* FUN_00586150();
    ResultValue* FUN_004fb070(TargetActor*, void*);
};
struct ModeValue
{
    char unk00;
    char unk01;
    char unk02;
    unsigned char enabled;
    int unk04;
};
extern ModeValue DAT_011a5650[];
struct ProcedureValue
{
    int unk00;
    IMValue* unk04;
    int unk08;
    int unk0c;
    int unk10;
    MemberValue unk14;
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
    TargetActor* FUN_00996de0();
    void* FUN_00996e00();
    void UpdateOutput(OutputValue* output);
};
// Calls the vtable getter on the holder, updates the target, and writes values to output depending on unk3c and DAT_011a5650[unk3c].enabled.
// @fnv 0x009d82e0
void ProcedureValue::UpdateOutput(OutputValue* output)
{
    TargetActor* holder = FUN_00996de0();
    Holder* target = unk04->FUN_00586150();
    output->Assign(
        DAT_011f1958->FUN_00825c00(holder->vtable->get(holder, holder, DAT_01012054))->BuildAvoidanceNodes());
    target->SetValue(FUN_00435dd0());
    void* actor = 0;
    switch (unk3c)
    {
    case 4:
        output->Assign(unk04->FUN_004fb070(holder, unk14.FUN_006815c0(0.0f, output->FUN_00559450()))->FUN_00989490());
        break;
    case 0:
    case 1:
        actor = FUN_00996e00();
        break;
    }
    if (DAT_011a5650[unk3c].enabled)
    {
        output->Assign(
            unk04->FUN_004fb070(holder, unk14.FUN_006815c0(0.0f, output->FUN_00559450()))->FUN_009892a0(actor));
    }
}

struct MoveVec
{
    float x, y, z;
    MoveVec();
    MoveVec operator-(const MoveVec&) const;
    MoveVec operator+(const MoveVec&) const;
    MoveVec& operator*=(float);
    float Length();
    bool operator==(const MoveVec&);
};
struct MoveLoc
{
    int x, y, z, w;
    MoveVec* Point();
    float Distance(const MoveLoc&);
    MoveVec Position();
    void Set(const MoveVec&, int);
};
struct MoveTimer
{
    int x, y;
    void Set(float);
    bool Expired();
    float Time();
};
struct MoveSetting
{
    float* Float();
};
extern MoveSetting originalRuntimeFloatSetting461, originalRuntimeFloatSetting390, originalRuntimeFloatSetting389,
    originalRuntimeFloatSetting391, originalRuntimeFloatSetting460, g_011cfad4;
struct MoveRef;
struct MoveRef
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00c();
    virtual int Type();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01c();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02c();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03c();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04c();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05c();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06c();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07c();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08c();
    virtual void slot090();
    virtual void slot094();
    virtual void slot098();
    virtual void slot09c();
    virtual void slot0a0();
    virtual void slot0a4();
    virtual void slot0a8();
    virtual void slot0ac();
    virtual void slot0b0();
    virtual void slot0b4();
    virtual void slot0b8();
    virtual void slot0bc();
    virtual void slot0c0();
    virtual void slot0c4();
    virtual void slot0c8();
    virtual void slot0cc();
    virtual void slot0d0();
    virtual void slot0d4();
    virtual void slot0d8();
    virtual void slot0dc();
    virtual void slot0e0();
    virtual void slot0e4();
    virtual void slot0e8();
    virtual void slot0ec();
    virtual void slot0f0();
    virtual void slot0f4();
    virtual void slot0f8();
    virtual void slot0fc();
    virtual bool IsActor();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14c();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15c();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual void slot16c();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17c();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void slot18c();
    virtual void slot190();
    virtual void slot194();
    virtual void slot198();
    virtual void slot19c();
    virtual void slot1a0();
    virtual void slot1a4();
    virtual void slot1a8();
    virtual void slot1ac();
    virtual void slot1b0();
    virtual void slot1b4();
    virtual void slot1b8();
    virtual void slot1bc();
    virtual void slot1c0();
    virtual void slot1c4();
    virtual void slot1c8();
    virtual void slot1cc();
    virtual void slot1d0();
    virtual void slot1d4();
    virtual void slot1d8();
    virtual void slot1dc();
    virtual void slot1e0();
    virtual void slot1e4();
    virtual void slot1e8();
    virtual void slot1ec();
    virtual void slot1f0();
    virtual MoveVec* Position();

    void* Status();
    bool Busy();
    bool Failed();
    bool BuildingFailed();
    bool Disabled();
    bool Deleted();
    bool HasStopped();
    void Stop();
    int PathIndex();
    bool PathPoint(int, MoveVec*);
    MoveLoc Location();
    int Cell();
};
struct MoveRequest
{
    int value;
    MoveRequest(int);
    ~MoveRequest();
    void* Get();
};
struct MoveQuery
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
    MoveQuery();
    ~MoveQuery();
};
struct MovePath
{
    int unk00, mode, unk08, unk0c, unk10;
    MoveLoc location;
    int unk24, unk28, unk2c, unk30, unk34, unk38;
    MoveVec start, end;
    int unk54, unk58, unk5c, unk60, unk64;
    int handle;
};
struct MoveTarget : MoveRef
{
    bool Ready();
    int Handle();
    MoveVec* Point();
    void Clear(int);
    MoveVec* LocationPoint();
};
struct MoveSmart
{
    MoveTarget* value;
    MoveTarget* Get();
    MoveSmart& operator=(int);
};
struct MoveStamp
{
    int value;
    float Time();
};
struct MoveManager
{
    void SetHandle(int);
    void SetPoint(MoveVec*);
    bool Start();
    MovePath* Path();
    MovePath* OtherPath();
    void Cancel(int);
    void ClearPath(int);
    void ClearOther(int);
    void Modes(unsigned);
    void ResetMode();
    void Destination(const MoveLoc&);
    void Update();
    bool Active();
    bool PathFailed();
    bool Allowed(unsigned);
    void Refresh();
    bool Check(MoveLoc*, MoveVec*, MoveRef*, int);
    bool Query(MoveQuery*, MoveVec*, int, float, void*);
    void Complete();
    void Finish(const MoveLoc&, int);
    MoveStamp Stamp();
};
struct MoveOwner
{
    MoveManager* Manager();
};
struct MoveProbe
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
    MoveProbe(const MoveLoc&);
    ~MoveProbe();
};
bool Probe(MoveProbe*, MoveVec*, int, int);
bool InRange(const MoveVec&, const MoveVec&, const MoveVec&, const MoveVec&);
void UpdateMove(MoveOwner*, MovePath*, MoveVec*, MoveVec*);
float MoveAmount(MoveRef*, int, int);
struct ByteAndFlagState
{
    char x, y;
    bool enabled;
    char z;
    int flags;
};
extern ByteAndFlagState MoveModes[];
extern bool DAT_011a5bfc;
struct MoveProcedure
{
    int unk00;
    MoveOwner* owner;
    int unk08, unk0c;
    unsigned state;
    MoveLoc destination, current;
    float rate;
    MoveRef* target;
    unsigned mode;
    MoveTimer timer;
    MoveVec position;
    bool active;
    MoveSmart pending;
    bool active5c;
    int index;
    MoveTimer retry, check, probe;
    MoveRef* Actor();
    MoveRef* Target();
    bool Begin();
    void Fail(const char*);
    void Clear();
    float Duration();
    void Look(const MoveVec&, unsigned char);
    void SetState(int);
    void Reset();
    void Avoid(MoveRequest*);
    void FUN_009d6ca0();
};
// @fnv 0x009d6ca0
void MoveProcedure::FUN_009d6ca0()
{
    bool changed3;
    bool stop5;
    MoveRef* actorsB = Actor();
    void* actorStatus5 = actorsB->Status();
    MoveRef* other7 = Target();
    MoveManager* manager2 = owner->Manager();
    switch (state)
    {
    case 0:
        current = destination;
        state = 1;
        if (!Begin())
            return;
        if (mode == 15)
            probe.Set(*originalRuntimeFloatSetting461.Float());
        break;
    case 1:
    case 2:
        if (pending.Get() && !actorsB->Busy())
        {
            MoveRef* ref = pending.Get();
            if (ref->Type() == 8)
            {
                MoveTarget* node = (MoveTarget*)ref;
                if (node->Ready())
                {
                    manager2->SetHandle(node->Handle());
                    MoveVec* point = node->Point();
                    manager2->SetPoint(point);
                    node->Clear(0);
                    if (point)
                    {
                        current.Set(*node->LocationPoint(), actorsB->Cell());
                        if (manager2->Start())
                        {
                            state = 2;
                            active = true;
                            MoveVec pos;
                            UpdateMove(owner, manager2->Path(), &pos, &position);
                            position.z += MoveAmount(actorsB, 2, 0);
                            check.Set(0.5f);
                        }
                        else
                        {
                            pending = 0;
                            current = destination;
                            state = 1;
                            Begin();
                            return;
                        }
                    }
                    else
                        current = destination;
                }
            }
            pending = 0;
        }
        if (actorsB->Failed())
        {
            if (!actorsB->BuildingFailed())
            {
                if (state == 2)
                {
                    MovePath* path = manager2->Path();
                    if (path)
                    {
                        manager2->Cancel(path->handle);
                        manager2->ClearPath(0);
                    }
                }
                else
                {
                    switch (mode)
                    {
                    case 0:
                    case 1:
                    case 7:
                    case 8:
                        manager2->Modes(1 << mode);
                        break;
                    case 3:
                        manager2->ResetMode();
                        break;
                    }
                    MovePath* path = manager2->OtherPath();
                    if (path && path->mode == mode)
                    {
                        manager2->Cancel(path->handle);
                        manager2->ClearOther(0);
                    }
                }
                manager2->Destination(current);
                manager2->Update();
                switch (mode)
                {
                case 1:
                    if (state != 2 && *current.Point() == *destination.Point())
                        manager2->Destination(destination);
                    break;
                }
            }
            Fail(actorsB->BuildingFailed() ? "Pathing failed while moving to destination"
                                           : "Path Building failed to destination");
            return;
        }
        if (target && (target->Disabled() || target->Deleted()))
        {
            static const char disabledReason[] = "Target ref is now disabled or deleted";
            Fail(disabledReason);
            return;
        }
        changed3 = false;
        if (target)
        {
            void* targetStatus8 = 0;
            if (target->IsActor())
            {
                MoveRef* ref = target;
                targetStatus8 = ref->Status();
            }
            MoveLoc locationB = target->Location();
            float distance8 = 0.0f;
            if (!actorStatus5 && !targetStatus8)
                distance8 = state == 2
                                ? *originalRuntimeFloatSetting390.Float() * *originalRuntimeFloatSetting390.Float()
                                : *originalRuntimeFloatSetting389.Float() * *originalRuntimeFloatSetting389.Float();
            else
                distance8 = *originalRuntimeFloatSetting391.Float() * *originalRuntimeFloatSetting391.Float();
            if (distance8 < locationB.Distance(destination))
            {
                destination = locationB;
                changed3 = true;
            }
        }
        if (state == 2 && check.Expired())
        {
            if (!changed3 && other7 && manager2->Active())
            {
                MovePath* path = manager2->Path();
                if (!path)
                    changed3 = true;
                else
                {
                    MoveLoc targetLoc = other7->Location();
                    MoveLoc actorLoc = actorsB->Location();
                    if (actorLoc.Distance(targetLoc) < 16777216.0)
                    {
                        if (!InRange(path->location.Position(), *other7->Position(), path->start, path->end))
                            changed3 = true;
                        else if (!manager2->Check(&path->location, current.Point(), other7, 0))
                            changed3 = true;
                    }
                }
            }
            check.Set(0.5f);
        }
        if (changed3)
        {
            if (state == 2)
            {
                manager2->Complete();
                manager2->ClearPath(0);
                active = false;
            }
            current = destination;
            state = 1;
            if (!Begin())
                return;
            return;
        }
        if (!DAT_011a5bfc && state == 1 && !actorsB->Busy() && !actorStatus5 && MoveModes[mode].enabled &&
            manager2->Allowed(1))
        {
            float radius5 = 256.0f;
            int pathIndex9 = actorsB->PathIndex();
            if (index == -1)
                radius5 = 512.0f;
            if (pathIndex9 != index || retry.Expired())
            {
                index = pathIndex9;
                retry.Set(2.0f);
                MoveRequest avoid7(0);
                bool initialized16 = false;
                MoveVec previous6_2 = *actorsB->Position();
                MoveVec point35;
                float lengthVal = 0.0f;
                bool done7 = false;
                while (!done7 && actorsB->PathPoint(pathIndex9 + 1, &point35))
                {
                    pathIndex9 = pathIndex9 + 1;
                    MoveVec delta8 = point35 - previous6_2;
                    float segment5 = delta8.Length();
                    if (lengthVal + segment5 > 1536.0)
                    {
                        delta8 *= float(1536.0 - lengthVal);
                        point35 = previous6_2 + delta8;
                        done7 = true;
                    }
                    lengthVal = lengthVal + segment5;
                    previous6_2 = point35;
                    if (!initialized16)
                        Avoid(&avoid7);
                    initialized16 = true;
                    MoveQuery query_2;
                    if (manager2->Query(&query_2, &point35, mode, radius5, avoid7.Get()))
                    {
                        active = true;
                        manager2->Refresh();
                        MoveVec pos;
                        UpdateMove(owner, manager2->Path(), &pos, &position);
                        position.z += MoveAmount(actorsB, 2, 0);
                        state = 2;
                        current.Set(pos, actorsB->Cell());
                        if (!Begin())
                            return;
                        check.Set(0.5f);
                        break;
                    }
                }
            }
        }
        stop5 = false;
        if (mode == 15 && probe.Expired())
        {
            MoveLoc loc = actorsB->Location();
            if (loc.Distance(destination) <
                *originalRuntimeFloatSetting460.Float() * *originalRuntimeFloatSetting460.Float())
            {
                MoveProbe request(destination);
                if (Probe(&request, loc.Point(), 0, 0))
                    stop5 = true;
            }
            probe.Set(*g_011cfad4.Float());
        }
        if (stop5)
            actorsB->Stop();
        if (stop5 || actorsB->HasStopped())
        {
            if (state == 2)
            {
                state = 3;
                timer.Set(Duration());
                check.Set(0.25f);
                Look(position, 3);
                SetState(2);
            }
            else
            {
                manager2->Finish(destination, mode);
                Clear();
            }
            return;
        }
        break;
    case 3: {
        bool finished6 = false;
        MovePath* path2 = manager2->Path();
        if (timer.Expired() || !path2)
            finished6 = true;
        else if (other7)
        {
            float deadline = float(timer.Time() + 1.0);
            if (deadline < FUN_00435dd0())
            {
                if (manager2->PathFailed())
                    finished6 = true;
                else if (deadline < manager2->Stamp().Time())
                    finished6 = true;
            }
            if (!finished6 && manager2->Active() && check.Expired())
            {
                if (!manager2->Check(&path2->location, current.Point(), other7, 1))
                    finished6 = true;
                check.Set(0.25f);
            }
        }
        if (finished6)
        {
            state = 0;
            manager2->Complete();
            active = false;
            manager2->ClearPath(0);
            Reset();
        }
    }
    break;
    default:;
    }
}

struct Point052
{
    float x, y, z;
    Point052();
    Point052 operator-(const Point052&) const;
    float FUN_004a7290();
};
extern Point052 DAT_011f426c;
extern const float DAT_0103a1c4;
extern bool DAT_011a5bfc;
extern const double DAT_01012060;
struct Actor052;
struct Table052
{
    void* unk000;
    void* unk004;
    void* unk008;
    void* unk00c;
    void* unk010;
    void* unk014;
    void* unk018;
    void* unk01c;
    void* unk020;
    void* unk024;
    void* unk028;
    void* unk02c;
    void* unk030;
    void* unk034;
    void* unk038;
    void* unk03c;
    void* unk040;
    void* unk044;
    void* unk048;
    void* unk04c;
    void* unk050;
    void* unk054;
    void* unk058;
    void* unk05c;
    void* unk060;
    void* unk064;
    void* unk068;
    void* unk06c;
    void* unk070;
    void* unk074;
    void* unk078;
    void* unk07c;
    void* unk080;
    void* unk084;
    void* unk088;
    void* unk08c;
    void* unk090;
    void* unk094;
    void* unk098;
    void* unk09c;
    void* unk0a0;
    void* unk0a4;
    void* unk0a8;
    void* unk0ac;
    void* unk0b0;
    void* unk0b4;
    void* unk0b8;
    void* unk0bc;
    void* unk0c0;
    void* unk0c4;
    void* unk0c8;
    void* unk0cc;
    void* unk0d0;
    void* unk0d4;
    void* unk0d8;
    void* unk0dc;
    void* unk0e0;
    void* unk0e4;
    void* unk0e8;
    void* unk0ec;
    void* unk0f0;
    void* unk0f4;
    void* unk0f8;
    void* unk0fc;
    void* unk100;
    void* unk104;
    void* unk108;
    void* unk10c;
    void* unk110;
    void* unk114;
    void* unk118;
    void* unk11c;
    void* unk120;
    void* unk124;
    void* unk128;
    void* unk12c;
    void* unk130;
    void* unk134;
    void* unk138;
    void* unk13c;
    void* unk140;
    void* unk144;
    void* unk148;
    void* unk14c;
    void* unk150;
    void* unk154;
    void* unk158;
    void* unk15c;
    void* unk160;
    void* unk164;
    void* unk168;
    void* unk16c;
    void* unk170;
    void* unk174;
    void* unk178;
    void* unk17c;
    void* unk180;
    void* unk184;
    void* unk188;
    void* unk18c;
    void* unk190;
    void* unk194;
    void* unk198;
    void* unk19c;
    void* unk1a0;
    void* unk1a4;
    void* unk1a8;
    void* unk1ac;
    void* unk1b0;
    void* unk1b4;
    void* unk1b8;
    void* unk1bc;
    void* unk1c0;
    void* unk1c4;
    void* unk1c8;
    void* unk1cc;
    void* unk1d0;
    void* unk1d4;
    void* unk1d8;
    void* unk1dc;
    void* unk1e0;
    void* unk1e4;
    void* unk1e8;
    void* unk1ec;
    void* unk1f0;
    Point052&(__thiscall* position)(Actor052*);
};
struct Request052
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
    Request052();
    ~Request052();
    void FUN_006e2980(Point052&, float);
    void SetUseSoft(int);
};
struct SpecialRequest052
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
    SpecialRequest052();
    ~SpecialRequest052();
    void FUN_00705b10(int);
};
struct Actor052
{
    virtual void unused000();
    virtual void unused004();
    virtual void unused008();
    virtual void unused00c();
    virtual void unused010();
    virtual void unused014();
    virtual void unused018();
    virtual void unused01c();
    virtual void unused020();
    virtual void unused024();
    virtual void unused028();
    virtual void unused02c();
    virtual void unused030();
    virtual void unused034();
    virtual void unused038();
    virtual void unused03c();
    virtual void unused040();
    virtual void unused044();
    virtual void unused048();
    virtual void unused04c();
    virtual void unused050();
    virtual void unused054();
    virtual void unused058();
    virtual void unused05c();
    virtual void unused060();
    virtual void unused064();
    virtual void unused068();
    virtual void unused06c();
    virtual void unused070();
    virtual void unused074();
    virtual void unused078();
    virtual void unused07c();
    virtual void unused080();
    virtual void unused084();
    virtual void unused088();
    virtual void unused08c();
    virtual void unused090();
    virtual void unused094();
    virtual void unused098();
    virtual void unused09c();
    virtual void unused0a0();
    virtual void unused0a4();
    virtual void unused0a8();
    virtual void unused0ac();
    virtual void unused0b0();
    virtual void unused0b4();
    virtual void unused0b8();
    virtual void unused0bc();
    virtual void unused0c0();
    virtual void unused0c4();
    virtual void unused0c8();
    virtual void unused0cc();
    virtual void unused0d0();
    virtual void unused0d4();
    virtual void unused0d8();
    virtual void unused0dc();
    virtual void unused0e0();
    virtual void unused0e4();
    virtual void unused0e8();
    virtual void unused0ec();
    virtual void unused0f0();
    virtual void unused0f4();
    virtual void unused0f8();
    virtual void unused0fc();
    virtual void unused100();
    virtual void unused104();
    virtual void unused108();
    virtual void unused10c();
    virtual void unused110();
    virtual void unused114();
    virtual void unused118();
    virtual void unused11c();
    virtual void unused120();
    virtual void unused124();
    virtual void unused128();
    virtual void unused12c();
    virtual void unused130();
    virtual void unused134();
    virtual void unused138();
    virtual void unused13c();
    virtual void unused140();
    virtual void unused144();
    virtual void unused148();
    virtual void unused14c();
    virtual void unused150();
    virtual void unused154();
    virtual void unused158();
    virtual void unused15c();
    virtual void unused160();
    virtual void unused164();
    virtual void unused168();
    virtual void unused16c();
    virtual void unused170();
    virtual void unused174();
    virtual void unused178();
    virtual void unused17c();
    virtual void unused180();
    virtual void unused184();
    virtual void unused188();
    virtual void unused18c();
    virtual void unused190();
    virtual void unused194();
    virtual void unused198();
    virtual void unused19c();
    virtual void unused1a0();
    virtual void unused1a4();
    virtual void unused1a8();
    virtual void unused1ac();
    virtual void unused1b0();
    virtual void unused1b4();
    virtual void unused1b8();
    virtual void unused1bc();
    virtual void unused1c0();
    virtual void unused1c4();
    virtual void unused1c8();
    virtual void unused1cc();
    virtual void unused1d0();
    virtual void unused1d4();
    virtual void unused1d8();
    virtual void unused1dc();
    virtual void unused1e0();
    virtual void unused1e4();
    virtual void unused1e8();
    virtual void unused1ec();
    virtual void unused1f0();
    virtual Point052& position();
    void* FUN_00575ca0();
    float FUN_008be1b0();
    void* FUN_00931850();
    void BuildPathingRequest(void*, Point052*, void*, float, void*);
    bool SetPathingRequestAvoidNodes(void*);
    void* FUN_008b3820();
};
struct LocationMember052
{
    Point052* FUN_006815c0();
    void* FUN_0084e3a0();
    void FUN_0098ddd0(Point052*);
    int unk00, unk04, unk08, unk0c;
};
struct State052
{
    unsigned char type;
    unsigned char unk01, unk02, unk03;
    int unk04;
    LocationMember052 location;
};
struct Holder052
{
    State052* FUN_007058c0();
    bool FUN_00461580(int);
    float FUN_009a0b00();
    bool IsFlagSet(int);
    void FUN_0099d310(SpecialRequest052*);
};
struct Manager052
{
    Holder052* FUN_00586150();
    bool FUN_00981940(int);
};
struct Location052
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
    Location052(const Point052&, Actor052*);
    ~Location052();
    bool FUN_006ded70(float);
};
struct Bound052;
struct Avoid052
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    static void* operator new(unsigned int);
    Avoid052();
    void AppendNode(const Bound052&);
};
struct Bound052
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    Bound052(const Point052&, float, float);
};
struct Output052
{
    Avoid052* FUN_00559450();
    void Assign(Avoid052*);
};
struct Setting052
{
    float* FUN_00403e20();
};
extern Setting052 DAT_011cf120, DAT_011cf4e0;
struct Ref052
{
    int value;
    void FUN_0066b0d0(void*);
};
struct Procedure052
{
    int unk00;
    Manager052* manager;
    int unk08, unk0c;
    int mode;
    LocationMember052 source;
    LocationMember052 destination;
    float rate;
    Actor052* target;
    int state;
    int unk40, unk44, unk48, unk4c, unk50, unk54;
    Ref052 request;
    int unk5c;
    int unk60;
    Actor052* FUN_00996de0();
    void* FUN_00996e00();
    void FUN_00996e20(int);
    void FUN_009caac0(const char*);
    bool UpdateMovementRequest(Output052*);
};
Point052 __cdecl FUN_009a68b0(Actor052*, Actor052*, Point052*, float);
bool __cdecl FUN_009a7940(Actor052*, Actor052*, Point052*, Point052*, int, int);
extern const char DAT_01091c80[];
// @fnv 0x009d7d00
bool Procedure052::UpdateMovementRequest(Output052* output)
{
    float request;
    bool d;
    float g;
    Actor052* a = FUN_00996de0();
    void* c = FUN_00996e00();
    Holder052* k = manager->FUN_00586150();
    int b = 3;
    Point052 h = DAT_011f426c;
    g = 0.0f;
    switch (state)
    {
    case 3:
        h = a->position();
        g = DAT_0103a1c4;
        break;
    case 0:
        if (manager->FUN_00981940(24))
            b = 4;
        break;
    }
    State052* i = k->FUN_007058c0();
    if (i && i->type == 1 && !k->FUN_00461580(256) && state != 8 && i->location.FUN_0084e3a0() == a->FUN_00575ca0())
    {
        h = *i->location.FUN_006815c0();
        g = k->FUN_009a0b00();
        Point052 delta = h - a->position();
        if (delta.FUN_004a7290() > g * g)
            g = 0.0f;
    }
    request = 0.0f;
    if (mode == 1)
        request = rate;
    if (state == 1 && mode == 1 && target)
    {
        Point052 position = FUN_009a68b0(a, target, source.FUN_006815c0(), DAT_01012054);
        Location052 location(position, a);
        if (location.FUN_006ded70(a->FUN_008be1b0()) &&
            FUN_009a7940(a, target, &position, source.FUN_006815c0(), 0, -1))
        {
            destination.FUN_0098ddd0(&position);
            if (!output->FUN_00559450())
                output->Assign(new Avoid052);
            output->FUN_00559450()->AppendNode(
                Bound052(target->position(), *DAT_011cf4e0.FUN_00403e20(), *DAT_011cf120.FUN_00403e20()));
        }
    }
    void* e = 0;
    Request052 j;
    SpecialRequest052 f;
    if (DAT_011a5bfc && (unsigned char)DAT_011a5650[state].unk02 && k->IsFlagSet(1) && !a->FUN_00931850())
    {
        k->FUN_0099d310(&f);
        f.FUN_00705b10(state);
        e = &f;
    }
    else
        e = &j;
    d = false;
    if (request < 0.0)
    {
        request = -request;
        d = true;
    }
    a->BuildPathingRequest(e, destination.FUN_006815c0(), destination.FUN_0084e3a0(), request, output->FUN_00559450());
    ((Request052*)e)->FUN_006e2980(h, g);
    if (d)
        ((Request052*)e)->SetUseSoft(0);
    if (!a->SetPathingRequestAvoidNodes(e))
    {
        FUN_009caac0(DAT_01091c80);
        return false;
    }
    unk60 = -1;
    this->request.FUN_0066b0d0(a->FUN_008b3820());
    FUN_00996e20(b);
    return true;
}

struct DebugPoint
{
    float x, y, z;
};
struct DebugReference
{
    virtual void slot000();
    virtual void slot001();
    virtual void slot002();
    virtual void slot003();
    virtual void slot004();
    virtual void slot005();
    virtual void slot006();
    virtual void slot007();
    virtual void slot008();
    virtual void slot009();
    virtual void slot010();
    virtual void slot011();
    virtual void slot012();
    virtual void slot013();
    virtual void slot014();
    virtual void slot015();
    virtual void slot016();
    virtual void slot017();
    virtual void slot018();
    virtual void slot019();
    virtual void slot020();
    virtual void slot021();
    virtual void slot022();
    virtual void slot023();
    virtual void slot024();
    virtual void slot025();
    virtual void slot026();
    virtual void slot027();
    virtual void slot028();
    virtual void slot029();
    virtual void slot030();
    virtual void slot031();
    virtual void slot032();
    virtual void slot033();
    virtual void slot034();
    virtual void slot035();
    virtual void slot036();
    virtual void slot037();
    virtual void slot038();
    virtual void slot039();
    virtual void slot040();
    virtual void slot041();
    virtual void slot042();
    virtual void slot043();
    virtual void slot044();
    virtual void slot045();
    virtual void slot046();
    virtual void slot047();
    virtual void slot048();
    virtual void slot049();
    virtual void slot050();
    virtual void slot051();
    virtual void slot052();
    virtual void slot053();
    virtual void slot054();
    virtual void slot055();
    virtual void slot056();
    virtual void slot057();
    virtual void slot058();
    virtual void slot059();
    virtual void slot060();
    virtual void slot061();
    virtual void slot062();
    virtual void slot063();
    virtual void slot064();
    virtual void slot065();
    virtual void slot066();
    virtual void slot067();
    virtual void slot068();
    virtual void slot069();
    virtual void slot070();
    virtual void slot071();
    virtual void slot072();
    virtual void slot073();
    virtual void slot074();
    virtual void slot075();
    virtual const char* GetDebugName();
    virtual void slot077();
    virtual void slot078();
    virtual void slot079();
    virtual void slot080();
    virtual void slot081();
    virtual void slot082();
    virtual void slot083();
    virtual void slot084();
    virtual void slot085();
    virtual void slot086();
    virtual void slot087();
    virtual void slot088();
    virtual void slot089();
    virtual void slot090();
    virtual void slot091();
    virtual void slot092();
    virtual void slot093();
    virtual void slot094();
    virtual void slot095();
    virtual void slot096();
    virtual void slot097();
    virtual void slot098();
    virtual void slot099();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual const DebugPoint& GetDebugPosition();
    DebugReference* FUN_00575ca0();
    unsigned int FUN_0084e3a0();
    int FUN_00474cb0();
    const char* FUN_0055d520();
};
struct DebugOwner
{
    DebugReference* GetFieldBC();
};
struct DebugLocation
{
    DebugPoint& FUN_006815c0();
    DebugReference* FUN_0084e3a0();
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
};
struct DebugTimer
{
    float FUN_00435e00();
    float FUN_006b9130();
    bool FUN_0097fa50();
    float start, duration;
};
struct DebugDisplay
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void __cdecl Print(int, int, const char*, ...);
};
struct MoveDebug
{
    int unk00;
    DebugOwner* owner;
    int unk08, unk0c;
    unsigned int state;
    DebugLocation destination;
    DebugReference* target;
    int unk3c;
    DebugTimer hidingTimer;
    int unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68;
    DebugTimer coverTimer;
    DebugTimer destinationTimer;
    void PrintDebugInfo(DebugDisplay* display, int x, int y);
};
// Prints the move state, destination cell and position, target info and destination timer to the debug display at the given coordinates.
// @fnv 0x009d8520
void MoveDebug::PrintDebugInfo(DebugDisplay* display, int x, int y)
{
    switch (state)
    {
    case 0:
        display->Print(x, y, "INITIALIZING");
        break;
    case 1:
        display->Print(x, y, "MOVING");
        break;
    case 2:
        display->Print(x, y, "MOVING_USING_COVER");
        display->Print(x, y, "Check Cover Timer: %.02f/%.02f", coverTimer.FUN_00435e00(), coverTimer.FUN_006b9130());
        break;
    case 3:
        display->Print(x, y, "HIDING_BEHIND_COVER");
        display->Print(x, y, "Hiding Timer: %.02f/%.02f", hidingTimer.FUN_00435e00(), hidingTimer.FUN_006b9130());
        display->Print(x, y, "Check Cover Timer: %.02f/%.02f", coverTimer.FUN_00435e00(), coverTimer.FUN_006b9130());
        break;
    }
    DebugPoint position = destination.FUN_006815c0();
    DebugReference* cell = destination.FUN_0084e3a0();
    if (cell && cell != owner->GetFieldBC()->FUN_00575ca0())
        display->Print(x, y, "Destination: %s (%.02f,%.02f,%.02f)", cell->GetDebugName(), position.x, position.y,
                       position.z);
    else
        display->Print(x, y, "Destination: (%.02f,%.02f,%.02f)", position.x, position.y, position.z);
    if (target)
    {
        DebugPoint targetPosition = target->GetDebugPosition();
        display->Print(x, y, "Target: '%s' (%08X) - Position: (%.02f,%.02f,%.02f)",
                       target->FUN_00474cb0() ? target->GetDebugName() : target->FUN_0055d520(), target->FUN_0084e3a0(),
                       targetPosition.x, targetPosition.y, targetPosition.z);
    }
    if (destinationTimer.FUN_0097fa50())
        display->Print(x, y, "Check Destination Timer: %.02f/%.02f", destinationTimer.FUN_00435e00(),
                       destinationTimer.FUN_006b9130());
}

struct TESForm
{
    virtual ~TESForm();
};

struct TESObjectREFR : TESForm
{
};

namespace fnv_009d8ad0 {
using ::TESForm;
using ::TESObjectREFR;

extern "C" TESForm* __cdecl LookupFormByID(unsigned int formID);

struct MoveContext
{
    void* FUN_008b3820();
};

struct CommandTarget
{
    unsigned int unk00;
    void FUN_0066b0d0(void* target);
};

struct ProcedureController
{

    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34;

    unsigned int currentForm;

    unsigned int unk3C, unk40, unk44, unk48, unk4C, unk50, unk54;

    CommandTarget command;

    unsigned char refresh;

    MoveContext* FUN_00996de0();

    void FUN_004534f0(unsigned int);

    void FUN_009d8ad0(unsigned int);
};

// Calls FUN_004534f0, resolves currentForm through LookupFormByID and dynamic_cast, then refreshes the command target from context when refresh is set.
// @fnv 0x009d8ad0
void ProcedureController::FUN_009d8ad0(unsigned int value)

{

    MoveContext* context = FUN_00996de0();

    FUN_004534f0(value);

    currentForm = (unsigned int)(currentForm ? dynamic_cast<TESObjectREFR*>(LookupFormByID(currentForm)) : 0);

    if (refresh)

        command.FUN_0066b0d0(context->FUN_008b3820());
}
}
