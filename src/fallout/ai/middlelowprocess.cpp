// fallout/ai/middlelowprocess.cpp: MiddleLowProcess, StandIn, Holder, ProcStandIn (24 functions)

#include "../../../include/layout_support.h"
#include "../../../include/Actor.h"
#include "MiddleLowProcess.h"

// @fnv 0x008d80e0
int MiddleLowProcess::GetProcessInteger()
{
    return m_iValueB4;
}
// @fnv 0x00502c90
void MiddleLowProcess::SetProcessInteger(int argument0)
{
    m_iValueB4 = argument0;
}

struct Base_0092c950
{
    char pad[0xb4];
    Base_0092c950();
    virtual ~Base_0092c950();
};
struct Mem_0092c950
{
    char pad[0x10];
    Mem_0092c950();
    ~Mem_0092c950();
};
struct FUN_0092c950 : Base_0092c950
{
    Mem_0092c950 m;
    FUN_0092c950();
    void SetSkillLevel(int);
    virtual ~FUN_0092c950();
};
// Constructs the object and initializes its skill level to 2 via SetSkillLevel.
// @fnv 0x0092c950
FUN_0092c950::FUN_0092c950()
{
    SetSkillLevel(2);
}

struct Actor;
struct ActorPackageData;
struct Animation;
struct ArrowProjectile;
struct BGSBodyPartData;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BGSVoiceType;
struct BSAnimGroupSequence;
struct BSBound;
struct BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct BSShaderPPLightingProperty;
struct BaseFormComponent;
struct BipedAnim;
struct CHUNK;
struct ContainerChanges;
struct ActorCombatGroup;
struct ContainerItemExtra;
struct InventoryItemEntry;
struct ExtraDataList;
struct FormRecordHeader;
struct TESFileGroup;
struct FurnitureMark;
struct HWND__;
struct BooleanFloatQuery;
struct InventoryChanges;
struct InventoryStackRecord;
struct LipSyncAnimation;
struct MagicCaster;
struct MagicItem;
struct MagicItemForm;
struct MagicTarget;
struct MiddleHighProcess;
struct MobileObject;
struct NiAVObject;
struct NiColor;
struct NiControllerManager;
struct NiNode;
struct NiPoint3;
struct TargetDoorController;
struct PackageTargetRecord;
struct PatrolActorPackageData;
struct SpellItem;
struct TESActorBase;
struct TESActorBaseData;
struct TESAmmo;
struct TESBoundObject;
struct TESContainer;
struct TESEffectShader;
struct TESFaction;
struct TESFile;
struct TESForm;
struct TESIdleForm;
struct TESLevItem;
struct TESLevSpell;
struct TESObject;
struct TESObjectARMO;
struct TESObjectCLOT;
struct TESFormList;
struct TESObjectREFR;
struct TESObjectWEAP;
struct TESPackage;
struct TESWaterForm;
struct TESWorldSpace;
struct bhkCharacterController;
struct blob4
{
    char b[4];
};
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct FUN_0092ce00_shell : public MiddleLowProcess
{
    float GetActorValueWithModifiers(TESActorBase*, int, Actor*);
};

namespace ActorValue {
bool GetFlag(int, unsigned int);
}
struct ML_0092ce00
{
    float GetActorValueModifierAmount(char);
};
struct LP_0092ce00
{
    char pad[0xb8];
    ML_0092ce00 mods;
    float GetCurrentActorValue(TESActorBase*, int, Actor*);
};
// @fnv 0x0092ce00
float FUN_0092ce00_shell::GetActorValueWithModifiers(TESActorBase* apActorBase, int aiWhich, Actor* apActor)
{
    if (ActorValue::GetFlag(aiWhich, 0x100))
        return ((LP_0092ce00*)this)->GetCurrentActorValue(apActorBase, aiWhich, apActor);
    return ((LP_0092ce00*)this)->GetCurrentActorValue(apActorBase, aiWhich, apActor) +
           ((LP_0092ce00*)this)->mods.GetActorValueModifierAmount((char)aiWhich);
}

namespace fnv_0092eaa0 {
struct Actor;
struct SaveLoadFile;
struct ThreeByThreeMatrix;
struct NiPoint3;
struct NiQuaternion;
struct TESForm;
struct TESObjectREFR;
struct hkVector4;
struct blob4
{
    char b[4];
};
struct BGSLoadGameBuffer
{
    virtual unsigned char GetVersion();
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int Load(SaveLoadFile*, unsigned int);
    int Load(SaveLoadFile*);
    void ResetReadPosition();
    void SetBuffer(char*, unsigned int, unsigned int);
    char* GetCurrentBufferPointer();
    bool ReadFormIdentifier(unsigned int*);
    unsigned int ReadFormIdentifier();
    void ReadTypedData(NiQuaternion*, unsigned int);
    void ReadTypedData(hkVector4*, unsigned int);
    void ReadTypedData(double*, unsigned int);
    void ReadTypedData(NiPoint3*, unsigned int);
    void ReadTypedData(float*, unsigned int);
    void ReadTypedData(unsigned long*, unsigned int);
    void ReadTypedData(long*, unsigned int);
    void ReadTypedData(unsigned int*, unsigned int);
    void ReadTypedData(int*, unsigned int);
    void ReadTypedData(unsigned short*, unsigned int);
    void ReadTypedData(short*, unsigned int);
    void ReadTypedData(ThreeByThreeMatrix*, unsigned int);
    void ReadTypedData(void*, unsigned int);
    char* LoadString(char*);
    int ReadElementCount();
    void AdvanceBuffer(unsigned int);
    void ReadElementData(void*, unsigned int, unsigned int);
    void ReadDataBlock(void*, unsigned int);
    void* __vecDelDtor(unsigned int);
    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
};
typedef char _sizecheck_BGSLoadGameBuffer[sizeof(BGSLoadGameBuffer) == 16 ? 1 : -1];
struct BGSLoadFormBuffer : public BGSLoadGameBuffer
{
    int LoadHeader(SaveLoadFile*);
    int ReadFormData(SaveLoadFile*);
    void SkipData(SaveLoadFile*, unsigned int);
    unsigned int GetFormID();
    void SetForm(TESForm*);
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int GetFormType();
    struct blob4 GetChangeFlags();
    void SetChangeFlags(struct blob4);
    struct blob4 GetOldChangeFlags();
    void SetOldChangeFlags(struct blob4);
    void SetVersion(unsigned char);
    virtual unsigned char GetVersion();
    void SetSkipForm(bool);
    bool GetSkipForm();
    void SetFormPending(bool);
    bool GetFormPending();
    void SetRevertOnly(bool);
    bool GetRevertOnly();
    void SetReconstructedForm(bool);
    bool GetReconstructedForm();
    void SetCellChanged(bool);
    bool GetCellChanged();
    void* __vecDelDtor(unsigned int);
    unsigned int iFormID;
    char Header[9];
    char _pad_1d[3];
    unsigned int iSize;
    TESForm* pForm;
    unsigned int iFlags;
    char m_cReservedBytes[4];
};
typedef char _sizecheck_BGSLoadFormBuffer[sizeof(BGSLoadFormBuffer) == 48 ? 1 : -1];
struct FUN_0092eaa0_shell : public MiddleLowProcess
{
    void FUN_0092eaa0(BGSLoadFormBuffer*);
};

struct BGSChangeFlagsCall
{
    char b[4];
    bool CheckFlag(unsigned int) const;
};

struct BGSLoadFormBufferCall
{
    BGSChangeFlagsCall GetChangeFlags();
};

struct LowProcessCall
{
    void LoadGame(BGSLoadFormBuffer*);
};

struct ModifierListCall
{
    void LoadGame(BGSLoadFormBuffer*);
};

// @fnv 0x0092eaa0
void FUN_0092eaa0_shell::FUN_0092eaa0(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<LowProcessCall*>(this)->LoadGame(apLoadGameBuffer);
    apLoadGameBuffer->ReadTypedData(reinterpret_cast<void*>(&m_iValueB4), 4);
    if (reinterpret_cast<BGSLoadFormBufferCall*>(apLoadGameBuffer)->GetChangeFlags().CheckFlag(0x100000))
    {
        reinterpret_cast<ModifierListCall*>(&m_kProcessModifierList)->LoadGame(apLoadGameBuffer);
    }
}
}  // namespace fnv_0092eaa0

namespace fnv_0092eb00 {
struct Actor;
struct SaveLoadFile;
struct ThreeByThreeMatrix;
struct NiPoint3;
struct NiQuaternion;
struct TESForm;
struct TESObjectREFR;
struct hkVector4;
struct blob4
{
    char b[4];
};
struct BGSLoadGameBuffer
{
    virtual unsigned char GetVersion();
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int Load(SaveLoadFile*, unsigned int);
    int Load(SaveLoadFile*);
    void ResetReadPosition();
    void SetBuffer(char*, unsigned int, unsigned int);
    char* GetCurrentBufferPointer();
    bool ReadFormIdentifier(unsigned int*);
    unsigned int ReadFormIdentifier();
    void ReadTypedData(NiQuaternion*, unsigned int);
    void ReadTypedData(hkVector4*, unsigned int);
    void ReadTypedData(double*, unsigned int);
    void ReadTypedData(NiPoint3*, unsigned int);
    void ReadTypedData(float*, unsigned int);
    void ReadTypedData(unsigned long*, unsigned int);
    void ReadTypedData(long*, unsigned int);
    void ReadTypedData(unsigned int*, unsigned int);
    void ReadTypedData(int*, unsigned int);
    void ReadTypedData(unsigned short*, unsigned int);
    void ReadTypedData(short*, unsigned int);
    void ReadTypedData(ThreeByThreeMatrix*, unsigned int);
    void ReadTypedData(void*, unsigned int);
    char* LoadString(char*);
    int ReadElementCount();
    void AdvanceBuffer(unsigned int);
    void ReadElementData(void*, unsigned int, unsigned int);
    void ReadDataBlock(void*, unsigned int);
    void* __vecDelDtor(unsigned int);
    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
};
typedef char _sizecheck_BGSLoadGameBuffer[sizeof(BGSLoadGameBuffer) == 16 ? 1 : -1];
struct BGSLoadFormBuffer : public BGSLoadGameBuffer
{
    int LoadHeader(SaveLoadFile*);
    int ReadFormData(SaveLoadFile*);
    void SkipData(SaveLoadFile*, unsigned int);
    unsigned int GetFormID();
    void SetForm(TESForm*);
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int GetFormType();
    struct blob4 GetChangeFlags();
    void SetChangeFlags(struct blob4);
    struct blob4 GetOldChangeFlags();
    void SetOldChangeFlags(struct blob4);
    void SetVersion(unsigned char);
    virtual unsigned char GetVersion();
    void SetSkipForm(bool);
    bool GetSkipForm();
    void SetFormPending(bool);
    bool GetFormPending();
    void SetRevertOnly(bool);
    bool GetRevertOnly();
    void SetReconstructedForm(bool);
    bool GetReconstructedForm();
    void SetCellChanged(bool);
    bool GetCellChanged();
    void* __vecDelDtor(unsigned int);
    unsigned int iFormID;
    char Header[9];
    char _pad_1d[3];
    unsigned int iSize;
    TESForm* pForm;
    unsigned int iFlags;
    char m_cReservedBytes[4];
};
typedef char _sizecheck_BGSLoadFormBuffer[sizeof(BGSLoadFormBuffer) == 48 ? 1 : -1];
struct FUN_0092eb00_shell : public MiddleLowProcess
{
    void FUN_0092eb00(BGSLoadFormBuffer*);
};

struct BGSChangeFlags_helper
{
    int flags;
    operator bool() const;
};

struct BGSLoadFormBuffer_helper
{
    BGSChangeFlags_helper GetOldChangeFlags(unsigned int);
};

struct LowProcess_helper
{
    void Revert(BGSLoadFormBuffer*);
};

struct ModifierList_helper
{
    void FUN_00937d50(BGSLoadFormBuffer*);
};

// @fnv 0x0092eb00
void FUN_0092eb00_shell::FUN_0092eb00(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<LowProcess_helper*>(this)->Revert(apLoadGameBuffer);
    if (reinterpret_cast<BGSLoadFormBuffer_helper*>(apLoadGameBuffer)->GetOldChangeFlags(0x100000))
        reinterpret_cast<ModifierList_helper*>(reinterpret_cast<char*>(this) + 0xb8)->FUN_00937d50(apLoadGameBuffer);
}
}  // namespace fnv_0092eb00

template <int N> struct Lvl;
template <> struct Lvl<0>
{
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
};
template <int N> struct Lvl : Lvl<N - 1>
{
    virtual void v0(char (&)[N * 10 + 0]) = 0;
    virtual void v1(char (&)[N * 10 + 1]) = 0;
    virtual void v2(char (&)[N * 10 + 2]) = 0;
    virtual void v3(char (&)[N * 10 + 3]) = 0;
    virtual void v4(char (&)[N * 10 + 4]) = 0;
    virtual void v5(char (&)[N * 10 + 5]) = 0;
    virtual void v6(char (&)[N * 10 + 6]) = 0;
    virtual void v7(char (&)[N * 10 + 7]) = 0;
    virtual void v8(char (&)[N * 10 + 8]) = 0;
    virtual void v9(char (&)[N * 10 + 9]) = 0;
};
struct StandIn : Lvl<23>
{
    virtual void Target(int, int, float) = 0;
    void CallTargetWithFloat(int, int, int);
};
// Converts the third integer argument to float and forwards all three arguments to Target.
// @fnv 0x00907430
void StandIn::CallTargetWithFloat(int aiArg1, int aiArg2, int aiArg3)
{
    Target(aiArg1, aiArg2, (float)aiArg3);
}

struct S0092ca00
{
    void FUN_0092ca00();
};
void __cdecl _Deallocate(void*);
struct FUN_0092c9d0_shell
{
    void* FUN_0092c9d0(unsigned int);
};
// Calls FUN_0092ca00 on this, frees this when bit 0 of flags is set, and returns this.
// @fnv 0x0092c9d0
void* FUN_0092c9d0_shell::FUN_0092c9d0(unsigned int flags)
{
    ((S0092ca00*)this)->FUN_0092ca00();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct P09AV
{
    static bool __cdecl GetFlag(int, unsigned int);
};
struct ModHack
{
    void __thiscall ModifyModifier(char, float, int);
};
struct FUN_0092ce70_shell
{
    void ApplyModifierIfNotFlagged(void* a1, int a2, int a3);
};
// Returns early if P09AV::GetFlag(a2, 0x100) is set; otherwise calls ModifyModifier on the ModHack at this+0xB8 with a2, a3 and 2.
// @fnv 0x0092ce70
void FUN_0092ce70_shell::ApplyModifierIfNotFlagged(void* apUnused, int aiArg, int afValue)
{
    if (P09AV::GetFlag(aiArg, 0x100))
        return;
    ((ModHack*)((char*)this + 0xB8))->ModifyModifier((char)aiArg, (float)afValue, 2);
}

namespace fnv_0092cf10 {
struct ML_0092ce00
{
    float GetActorValueModifierAmount(char);
};
struct FUN_0092cf10_shell
{
    char _pad[0xB8];
    ML_0092ce00 _m;
    float FUN_0092cf10(char);
};
// @fnv 0x0092cf10
float FUN_0092cf10_shell::FUN_0092cf10(char aWhich)
{
    return _m.GetActorValueModifierAmount(aWhich);
}
}  // namespace fnv_0092cf10

struct LowHolder
{
    void FUN_0090c360(void*, float);
};
struct Holder
{
    void FUN_0092e400(void*, float);
};
// @fnv 0x0092e400
void Holder::FUN_0092e400(void* a, float afValue)
{
    ((LowHolder*)this)->FUN_0090c360(a, afValue);
}

struct FUN_00910310_shell
{
    void ResetAndClear(unsigned int, class MobileObject*);
};
struct FUN_00937b30_shell
{
    void FUN_00937b30();
};
struct FUN_0092e9f0_shell
{
    void FUN_0092e9f0(unsigned int, class MobileObject*);
};
// @fnv 0x0092e9f0
void FUN_0092e9f0_shell::FUN_0092e9f0(unsigned int aiFlags, class MobileObject* pmob)
{
    ((FUN_00910310_shell*)this)->ResetAndClear(aiFlags, pmob);
    if (aiFlags & 0x100000)
        ((FUN_00937b30_shell*)((char*)this + 0xB8))->FUN_00937b30();
}

struct Inner096a970
{
    void InsertAt(MobileObject*, int);
};
struct Host096d450
{
    int pad;
    Inner096a970 inner;
    void FUN_0096d450(MobileObject*, int, bool, bool, MobileObject*);
};
// @fnv 0x0096d450
void Host096d450::FUN_0096d450(MobileObject* apActor, int aWhichList, bool aiWhere, bool abinsert,
                               MobileObject* apInsertActor)
{
    inner.InsertAt(apActor, aWhichList);
}

namespace fnv_0092cd90 {
struct ML_0092ce00
{
    float GetActorValueModifierAmount(char);
};
struct P09AV
{
    static bool GetFlag(int, unsigned int);
};
struct FUN_0092cd90_shell : LowProcess
{
    int GetActorValue(TESActorBase*, ActorValue__Index, Actor*);
};
// @fnv 0x0092cd90
int FUN_0092cd90_shell::GetActorValue(TESActorBase* apActorBase, ActorValue__Index index, Actor* actorPtr)
{
    if (P09AV::GetFlag((int)index, 0x100))
        return BaseProcess::GetActorValue(apActorBase, index, actorPtr);
    return BaseProcess::GetActorValue(apActorBase, index, actorPtr) +
           (int)(float)((ML_0092ce00*)((char*)this + 0xB8))->GetActorValueModifierAmount((char)index);
}
}  // namespace fnv_0092cd90

struct Setting_S
{
    float* Float();
};

extern Setting_S originalRuntimeFloatSetting236;

struct FUN_0092cc90_shell
{
    bool FUN_0092cc90(Actor* apActor, float afTimeDelta);
};

// @fnv 0x0092cc90
bool FUN_0092cc90_shell::FUN_0092cc90(Actor* apActor, float afTimeDelta)
{
    int iCount = (int)(*originalRuntimeFloatSetting236.Float() * 4.0);
    Actor* ptarget = 0;

    while (iCount)
    {
        if (apActor->Unk_8B(false))
            break;

        apActor->Unk_10E();

        ptarget = dynamic_cast<Actor*>(*(TESObjectREFR**)((char*)this + 0x40));
        if (ptarget && !ptarget->Unk_8B(false))
            ptarget->Unk_10E();

        --iCount;
    }

    if (ptarget && !ptarget->Unk_8B(false))
        ptarget->GetProcess()->ResetPackageState();

    return false;
}

namespace fnv_0092cf30 {
struct P09AV
{
    static bool __cdecl GetFlag(int, unsigned int);
};

float __cdecl FUN_0066eea0(void*, int, float);

struct ModHack
{
    void ModifyModifier(char, float, int);
};

struct FUN_0092cf30_shell
{
    void FUN_0092cf30(Actor* apActor, int aiWhich, float afValue);
};

// @fnv 0x0092cf30
void FUN_0092cf30_shell::FUN_0092cf30(Actor* apActor, int aiWhich, float afValue)
{
    if (P09AV::GetFlag(aiWhich, 0x100))
        return;

    float fclamped = FUN_0066eea0(apActor ? (char*)apActor + 0xa4 : 0, aiWhich, afValue);
    int eclampStyle = P09AV::GetFlag(aiWhich, 0x200) ? 1 : 0;

    ((ModHack*)((char*)this + 0x94))->ModifyModifier((char)aiWhich, fclamped, eclampStyle);
}
}  // namespace fnv_0092cf30

struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};

struct Interface
{
    static void __cdecl PrintDebugMessage(const char*, ...);
};

struct TESSaveLoadGame
{
    bool FUN_00862110();
    void* GetHitSound();
};

struct HitSoundData_0092e420
{
    unsigned int formID;
    unsigned char pad;
};

extern GlobalObject_0045cf30 g_011de4e8;
extern TESSaveLoadGame* DAT_011de45c;

TESForm* _GetFormByNumericID(unsigned int);

struct FUN_0092e420_shell
{
    unsigned short FUN_0090f8b0(unsigned int, int);

    struct SaveSizePart
    {
        unsigned short FUN_00937ab0();
    };

    unsigned char pad[0xb8];
    SaveSizePart saveSizePart;

    unsigned short FUN_0092e420(unsigned int, int);
};

// @fnv 0x0092e420
unsigned short FUN_0092e420_shell::FUN_0092e420(unsigned int flags, int value)
{
    unsigned short usSize = 0;
    unsigned short usInitialSize;
    HitSoundData_0092e420* hitSound;
    TESForm* form;

    usSize += this->FUN_0090f8b0(flags, value);
    usInitialSize = usSize;

    if (DAT_011de45c->FUN_00862110())
    {
        usSize += 4;
        usSize += 2;
    }

    usSize += 4;

    if (flags & 0x100000)
    {
        usSize += this->saveSizePart.FUN_00937ab0();
    }

    if (*g_011de4e8.Bool())
    {
        hitSound = static_cast<HitSoundData_0092e420*>(DAT_011de45c->GetHitSound());

        if (hitSound)
        {
            form = _GetFormByNumericID(hitSound->formID);

            Interface::PrintDebugMessage(
                "GetSaveSize(): %-5i for form %08X %s with flags %08X ending at line %i in file %s",
                usSize - usInitialSize, hitSound->formID, form->GetName(),
                *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(hitSound) + 5), 0x263,
                "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\ai\\MiddleLowProcess.cpp");
        }
        else
        {
            Interface::PrintDebugMessage("GetSaveSize(): %-5i ending at line %i in file %s", usSize - usInitialSize,
                                         0x263,
                                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\ai\\MiddleLowProcess.cpp");
        }
    }

    return usSize;
}

// Fluent wrapper: forwards the argument to the helper member on this and
// hands back the object itself so calls can be chained.
class FUN_00501c10_cls
{
  public:
    void FUN_00438470(int arg);
    FUN_00501c10_cls* CallAndReturnSelf(int arg);
};

// @fnv 0x00501c10
FUN_00501c10_cls* FUN_00501c10_cls::CallAndReturnSelf(int arg)
{
    FUN_00438470(arg);
    return this;
}

struct FNVTimeClock
{
    float GetTime();
};
extern FNVTimeClock g_GameClock;

struct FUN_0092cfd0_shell : MiddleLowProcess
{
    bool FUN_0090a1a0(int packageType, bool forced);
    bool FUN_0092cfd0(int packageType, bool forced);
};

// Re-evaluates the current package via FUN_0090a1a0 when forced, no package is active, or the clock's integer second changed, caching that second.
// @fnv 0x0092cfd0
bool FUN_0092cfd0_shell::FUN_0092cfd0(int packageType, bool forced)
{
    bool result;
    {
        float currentTime = g_GameClock.GetTime();
        result = false;
        if (forced || !GetCurrentPackage() || m_iValueB4 != static_cast<int>(currentTime))
        {
            result = FUN_0090a1a0(packageType, forced);
            m_iValueB4 = static_cast<int>(currentTime);
        }
    }
    return result;
}

struct TESForm_92e560
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
    virtual const char* GetEditorID();
};

struct FormFlags_92e560
{
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
};

struct SaveFormData_92e560
{
    unsigned int formID;
    unsigned char unk04;
    FormFlags_92e560 flags;
};

struct SaveLoadGame_92e560
{
    bool IsDebugBlocks();
    unsigned int GetOffset();
    SaveFormData_92e560* GetCurrentForm();
    void WriteData(void* apData, int aiSize);
};

struct SettingBool_92e560
{
    unsigned char* Bool();
};

struct SaveSizePart_92e560
{
    void SaveGame();
};

struct LowProcessBase_92e560
{
    void SaveGame(unsigned int auiFlags, int aiArg);
};

struct MiddleLowProcess_92e560 : LowProcessBase_92e560
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
    SaveSizePart_92e560 unkB8;

    void FUN_0092e560(unsigned int auiFlags, int aiArg);
};

extern SaveLoadGame_92e560* g_TESSaveLoadGame;
extern SettingBool_92e560 g_bSaveDebug_92e560;
TESForm_92e560* __cdecl LookupFormByID_92e560(unsigned int auiFormID);
void __cdecl DebugPrintf_92e560(const char* apFmt, ...);
void __cdecl SaveWarning_92e560(const char* apFmt, ...);

// @fnv 0x0092e560
void MiddleLowProcess_92e560::FUN_0092e560(unsigned int auiFlags, int aiArg)
{
    LowProcessBase_92e560::SaveGame(auiFlags, aiArg);
    unsigned short usBlockSize = 0;
    unsigned short* pBlockSize3 = 0;
    unsigned int _uiStart = g_TESSaveLoadGame->GetOffset();
    if (*g_bSaveDebug_92e560.Bool())
        _uiStart = g_TESSaveLoadGame->GetOffset();
    if (g_TESSaveLoadGame->IsDebugBlocks())
    {
        unsigned int uiMarker6 = 0x424c4f4b;
        g_TESSaveLoadGame->WriteData(&uiMarker6, 4);
        pBlockSize3 = (unsigned short*)g_TESSaveLoadGame->GetOffset();
        g_TESSaveLoadGame->WriteData(&usBlockSize, 2);
    }
    g_TESSaveLoadGame->WriteData(&unkB4, 4);
    if (auiFlags & 0x100000)
        unkB8.SaveGame();
    if (*g_bSaveDebug_92e560.Bool())
    {
        unsigned int uiEnd4 = g_TESSaveLoadGame->GetOffset();
        SaveFormData_92e560* pFormData3 = g_TESSaveLoadGame->GetCurrentForm();
        if (pFormData3)
        {
            TESForm_92e560* pForm = LookupFormByID_92e560(pFormData3->formID);
            DebugPrintf_92e560("SaveGame(): %-5i for form %08X %s with flags %08X ending at line %i in file %s",
                               uiEnd4 - _uiStart, pFormData3->formID, pForm->GetEditorID(), pFormData3->flags, 634,
                               "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\ai\\MiddleLowProcess.cpp");
        }
        else
        {
            DebugPrintf_92e560("SaveGame(): %-5i ending at line %i in file %s", uiEnd4 - _uiStart, 634,
                               "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\ai\\MiddleLowProcess.cpp");
        }
    }
    if (g_TESSaveLoadGame->IsDebugBlocks())
    {
        unsigned int uiCur2 = g_TESSaveLoadGame->GetOffset();
        unsigned int uiBase2 = (unsigned int)pBlockSize3;
        if (uiCur2 > uiBase2 + 0xffff)
            SaveWarning_92e560("SAVELOAD: Save Game Block in file %s on line %i is greater than maximum short size",
                               "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\ai\\MiddleLowProcess.cpp", 634);
        *pBlockSize3 = (unsigned short)(uiCur2 - uiBase2);
    }
}

struct BGSChangeFlags_s
{
    bool Test(unsigned int mask);
};
struct FUN_00865e50_shell
{
    BGSChangeFlags_s* FUN_00428110(unsigned int* out);
    void FUN_00865e50(void* buf, unsigned int size, int flags);
};
struct TemporaryModifiers_shell
{
    void FUN_00937b50(FUN_00865e50_shell* a);
};
struct FUN_0092ea30_shell : public LowProcess
{
    int m_iValueB4;
    TemporaryModifiers_shell m_kProcessModifierList;
    void FUN_00910450(FUN_00865e50_shell* a);
    void LoadFromStream(FUN_00865e50_shell* a);
};
// @fnv 0x0092ea30
void FUN_0092ea30_shell::LoadFromStream(FUN_00865e50_shell* a)
{
    unsigned int flags;
    FUN_00910450(a);
    a->FUN_00865e50(&m_iValueB4, 4, 0);
    if (a->FUN_00428110(&flags)->Test(0x100000))
    {
        m_kProcessModifierList.FUN_00937b50(a);
    }
}

namespace fnv_0092e730 {
extern "C" char DAT_011de45c;
extern "C" char DAT_0108a3f0;
extern "C" char DAT_01015718;
extern "C" char DAT_010156a8;
extern "C" char DAT_01015588;
extern "C" char DAT_01015500;
extern "C" char DAT_010154a0;
extern "C" char DAT_01015440;
struct Record92
{
    unsigned id;
    char x;
    char value[4];
    unsigned char kind;
};
struct Virtual92
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
    virtual unsigned v76();
};
struct Save92
{
    bool FUN_00862110();
    void FUN_008579e0(void*, unsigned);
    Record92* FUN_004fd3c0();
    unsigned char FUN_008df040();
    unsigned FUN_00825c00();
};
struct Base92
{
    void FUN_0090fd80(unsigned, unsigned, unsigned);
};
struct Sub92
{
    void LoadModifiers();
};
Virtual92* __cdecl LookupFormByID(unsigned);
void __cdecl FUN_005b5e40(const char*, ...);
struct Target92
{
    char pad[0xb4];
    unsigned field;
    Sub92 sub;
    void FUN_0092e730(unsigned, unsigned, unsigned);
};
// Calls the base handler, reads a 4-byte field from the save stream, logs a mismatch record, and compares stream position against a stored offset.
// @fnv 0x0092e730
void Target92::FUN_0092e730(unsigned flags, unsigned arg2, unsigned arg3)
{
    ((Base92*)this)->FUN_0090fd80(flags, arg2, arg3);
    unsigned short a = 0;
    unsigned b = 0;
    if ((*(Save92**)&DAT_011de45c)->FUN_00862110())
    {
        unsigned uiMagic;
        (*(Save92**)&DAT_011de45c)->FUN_008579e0(&uiMagic, 4);
        if (uiMagic != 0x424c4f4b)
        {
            Record92* pRecord = (*(Save92**)&DAT_011de45c)->FUN_004fd3c0();
            if (pRecord)
            {
                Virtual92* pVirtual = LookupFormByID(pRecord->id);
                FUN_005b5e40(&DAT_01015718, &DAT_0108a3f0, 0x287, pRecord->id, pVirtual->v76(), pRecord->kind,
                             *(unsigned*)pRecord->value);
            }
            else
            {
                FUN_005b5e40(&DAT_010156a8, &DAT_0108a3f0, 0x287, (*(Save92**)&DAT_011de45c)->FUN_008df040());
            }
        }
        b = (*(Save92**)&DAT_011de45c)->FUN_00825c00();
        (*(Save92**)&DAT_011de45c)->FUN_008579e0(&a, 2);
    }
    (*(Save92**)&DAT_011de45c)->FUN_008579e0(&field, 4);
    if (flags & 0x100000)
        sub.LoadModifiers();
    if ((*(Save92**)&DAT_011de45c)->FUN_00862110())
    {
        unsigned uiNewPos = (*(Save92**)&DAT_011de45c)->FUN_00825c00();
        Record92* pRecord2 = (*(Save92**)&DAT_011de45c)->FUN_004fd3c0();
        if (pRecord2)
        {
            Virtual92* pVirtual2 = LookupFormByID(pRecord2->id);
            if (uiNewPos > b + a)
            {
                FUN_005b5e40(&DAT_01015588, uiNewPos - (b + a), &DAT_0108a3f0, 0x290, pRecord2->id, pVirtual2->v76(),
                             pRecord2->kind, *(unsigned*)pRecord2->value);
            }
            else if (uiNewPos < b + a)
            {
                FUN_005b5e40(&DAT_01015500, (b + a) - uiNewPos, &DAT_0108a3f0, 0x290, pRecord2->id, pVirtual2->v76(),
                             pRecord2->kind, *(unsigned*)pRecord2->value);
            }
        }
        else
        {
            if (uiNewPos > b + a)
            {
                FUN_005b5e40(&DAT_010154a0, uiNewPos - (b + a), &DAT_0108a3f0, 0x290,
                             (*(Save92**)&DAT_011de45c)->FUN_008df040());
            }
            else if (uiNewPos < b + a)
            {
                FUN_005b5e40(&DAT_01015440, (b + a) - uiNewPos, &DAT_0108a3f0, 0x290,
                             (*(Save92**)&DAT_011de45c)->FUN_008df040());
            }
        }
    }
}
}  // namespace fnv_0092e730

bool FUN_00406d70(int aiValue, int aiFlag);

struct Sub0092cec0
{
    void __thiscall FUN_00937480(unsigned char aucIndex, float afValue, int aiType);
};

struct Owner0092cec0
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
    Sub0092cec0 unkB8;

    void FUN_0092cec0(int aiUnused, int aiIndex, float afValue);
};

// Returns when FUN_00406d70(aiIndex, 0x100) is true; otherwise calls unkB8.FUN_00937480(aiIndex, afValue, 2).
// @fnv 0x0092cec0
void Owner0092cec0::FUN_0092cec0(int aiUnused, int aiIndex, float afValue)
{
    if (FUN_00406d70(aiIndex, 0x100))
        return;
    unkB8.FUN_00937480(aiIndex, afValue, 2);
}

namespace fnv_0092d050 {
struct Pt3
{
    float x;
    float y;
    float z;
};
struct Ref;
struct Pkg;
struct Ext;

struct Item
{
    int unk00;
    ~Item();
};

struct ItemList
{
    void* m_pHead;
    void* m_pTail;
    bool IsEmpty();
    Item** Head();
    void Remove(Item** ppItem);
};

struct TargetInfo
{
    int FUN_0067f390_dummy;
    Ext* GetTarget();
    int GetKind();
};

struct Ext
{
    int unk00;
    int GetRace();
    Pt3* GetPos();
};

struct ProcData
{
    int unk00;
    int GetInt();
};

struct DurInfo
{
    int unk00;
    int GetEnd();
};

struct BaseObj
{
    virtual void b_000();
    virtual void b_004();
    virtual void b_008();
    virtual void b_00c();
    virtual void b_010();
    virtual void b_014();
    virtual void b_018();
    virtual void b_01c();
    virtual void b_020();
    virtual void b_024();
    virtual void Update28();
    virtual void b_02c();
    virtual void b_030();
    virtual void b_034();
    virtual void b_038();
    virtual void b_03c();
    virtual void b_040();
    virtual void b_044();
    virtual void b_048();
    virtual void b_04c();
    virtual void b_050();
    virtual void b_054();
    virtual void b_058();
    virtual void b_05c();
    virtual void b_060();
    virtual void b_064();
    virtual void b_068();
    virtual void b_06c();
    virtual void b_070();
    virtual void b_074();
    virtual void b_078();
    virtual void b_07c();
    virtual void b_080();
    virtual void b_084();
    virtual void b_088();
    virtual void b_08c();
    virtual void b_090();
    virtual void b_094();
    virtual void b_098();
    virtual void b_09c();
    virtual void b_0a0();
    virtual void b_0a4();
    virtual void b_0a8();
    virtual void b_0ac();
    virtual void b_0b0();
    virtual void b_0b4();
    virtual void b_0b8();
    virtual void b_0bc();
    virtual void b_0c0();
    virtual void b_0c4();
    virtual void b_0c8();
    virtual void b_0cc();
    virtual void b_0d0();
    virtual void b_0d4();
    virtual void b_0d8();
    virtual void b_0dc();
    virtual void b_0e0();
    virtual void b_0e4();
    virtual void b_0e8();
    virtual void b_0ec();
    virtual void b_0f0();
    virtual void b_0f4();
    virtual void b_0f8();
    virtual void b_0fc();
    virtual void b_100();
    virtual void b_104();
    virtual void b_108();
    virtual void b_10c();
    virtual void b_110();
    virtual void b_114();
    virtual void b_118();
    virtual void b_11c();
    virtual void b_120();
    virtual void b_124();
    virtual void b_128();
    virtual void b_12c();
    virtual void b_130();
    virtual void b_134();
    virtual void b_138();
    virtual void b_13c();
    virtual void b_140();
    virtual void b_144();
    virtual void b_148();
    virtual void b_14c();
    virtual void b_150();
    virtual void b_154();
    virtual void b_158();
    virtual void b_15c();
    virtual void b_160();
    virtual void b_164();
    virtual void b_168();
    virtual void b_16c();
    virtual void b_170();
    virtual void b_174();
    virtual void b_178();
    virtual void b_17c();
    virtual void b_180();
    virtual void b_184();
    virtual void b_188();
    virtual void b_18c();
    virtual void b_190();
    virtual void b_194();
    virtual void b_198();
    virtual void b_19c();
    virtual void b_1a0();
    virtual void b_1a4();
    virtual void b_1a8();
    virtual void b_1ac();
    virtual void b_1b0();
    virtual void b_1b4();
    virtual void b_1b8();
    virtual void b_1bc();
    virtual void b_1c0();
    virtual void b_1c4();
    virtual void b_1c8();
    virtual void b_1cc();
    virtual void b_1d0();
    virtual void b_1d4();
    virtual void b_1d8();
    virtual void b_1dc();
    virtual void b_1e0();
    virtual void b_1e4();
    virtual void b_1e8();
    virtual void b_1ec();
    virtual void b_1f0();
    virtual void b_1f4();
    virtual void b_1f8();
    virtual void b_1fc();
    virtual void b_200();
    virtual void b_204();
    virtual void b_208();
    virtual void b_20c();
    virtual void b_210();
    virtual void b_214();
    virtual void b_218();
    virtual void b_21c();
    virtual void b_220();
    virtual void b_224();
    virtual void b_228();
    virtual void b_22c();
    virtual void b_230();
    virtual void b_234();
    virtual void b_238();
    virtual void b_23c();
    virtual void b_240();
    virtual void b_244();
    virtual void b_248();
    virtual void b_24c();
    virtual void b_250();
    virtual void b_254();
    virtual void b_258();
    virtual void b_25c();
    virtual void b_260();
    virtual void b_264();
    virtual void b_268();
    virtual void b_26c();
    virtual void b_270();
    virtual void b_274();
    virtual void b_278();
    virtual void b_27c();
    virtual void b_280();
    virtual void b_284();
    virtual void b_288();
    virtual void b_28c();
    virtual void b_290();
    virtual void b_294();
    virtual void b_298();
    virtual void b_29c();
    virtual void b_2a0();
    virtual void b_2a4();
    virtual void b_2a8();
    virtual void b_2ac();
    virtual void b_2b0();
    virtual void b_2b4();
    virtual void b_2b8();
    virtual void b_2bc();
    virtual void b_2c0();
    virtual void b_2c4();
    virtual void b_2c8();
    virtual void b_2cc();
    virtual void b_2d0();
    virtual void b_2d4();
    virtual void b_2d8();
    virtual void b_2dc();
    virtual void b_2e0();
    virtual void b_2e4();
    virtual void b_2e8();
    virtual void b_2ec();
    virtual void b_2f0();
    virtual void b_2f4();
    virtual void b_2f8();
    virtual void b_2fc();
    virtual void b_300();
    virtual void b_304();
    virtual void b_308();
    virtual void b_30c();
    virtual void b_310();
    virtual void b_314();
    virtual void b_318();
    virtual void b_31c();
    virtual void b_320();
    virtual void b_324();
    virtual void b_328();
    virtual void b_32c();
    virtual void b_330();
    virtual void b_334();
    virtual void b_338();
    virtual void b_33c();
    virtual void b_340();
    virtual void b_344();
    virtual void b_348();
    virtual void b_34c();
    virtual void b_350();
    virtual void b_354();
    virtual void b_358();
    virtual void b_35c();
    virtual void b_360();
    virtual void b_364();
    virtual void b_368();
    virtual void b_36c();
    virtual void b_370();
    virtual void b_374();
    virtual void b_378();
    virtual void b_37c();
    virtual void b_380();
    virtual void b_384();
    virtual void b_388();
    virtual void b_38c();
    virtual void b_390();
    virtual void b_394();
    virtual void b_398();
    virtual void b_39c();
    virtual void b_3a0();
    virtual void b_3a4();
    virtual void b_3a8();
    virtual void b_3ac();
    virtual void b_3b0();
    virtual void b_3b4();
    virtual void b_3b8();
    virtual void b_3bc();
    virtual void b_3c0();
    virtual void b_3c4();
    virtual void b_3c8();
    virtual void b_3cc();
    virtual void b_3d0();
    virtual void b_3d4();
    virtual void b_3d8();
    virtual void b_3dc();
    virtual void b_3e0();
    virtual void b_3e4();
    virtual void b_3e8();
    virtual void b_3ec();
    virtual void b_3f0();
    virtual void b_3f4();
    virtual void b_3f8();
    virtual void b_3fc();
    virtual void b_400();
    virtual void b_404();
    virtual void b_408();
    virtual void b_40c();
    virtual void b_410();
    virtual void b_414();
    virtual void b_418();
    virtual void b_41c();
    virtual void b_420();
    virtual void b_424();
    virtual void b_428();
    virtual void b_42c();
    virtual void b_430();
    virtual void b_434();
    virtual void b_438();
    virtual void b_43c();
    virtual void b_440();
    virtual void b_444();
    virtual void b_448();
    virtual void b_44c();
    virtual void b_450();
    virtual void b_454();
    virtual void b_458();
    virtual void b_45c();
    virtual void b_460();
    virtual void b_464();
    virtual void b_468();
    virtual void b_46c();
    virtual void b_470();
    virtual void b_474();
    virtual void b_478();
    virtual void b_47c();
    virtual void b_480();
    virtual void b_484();
    virtual void b_488();
    virtual void b_48c();
    virtual void b_490();
    virtual void b_494();
    virtual void b_498();
    virtual void b_49c();
    virtual void b_4a0();
    virtual void b_4a4();
    virtual void b_4a8();
    virtual void b_4ac();
    virtual void b_4b0();
    virtual void b_4b4();
    virtual void b_4b8();
    virtual void b_4bc();
    virtual void b_4c0();
    virtual void b_4c4();
    virtual void b_4c8();
    virtual void b_4cc();
    virtual void b_4d0();
    virtual void b_4d4();
    virtual void b_4d8();
    virtual void b_4dc();
    virtual void b_4e0();
    virtual void b_4e4();
    virtual void b_4e8();
    virtual void b_4ec();
    virtual void b_4f0();
    virtual void b_4f4();
    virtual void b_4f8();
    virtual void b_4fc();
    virtual void b_500();
    virtual void b_504();
    virtual void b_508();
    virtual void b_50c();
    virtual void b_510();
    virtual Ext* Get514();
    int GetLevel();
};

struct Spell
{
    int unk00;
    float GetDur();
};

struct Owner
{
    int unk00;
    bool IsSet();
};

struct Ref
{
    virtual void r_000();
    virtual void r_004();
    virtual void r_008();
    virtual void r_00c();
    virtual void r_010();
    virtual void r_014();
    virtual void r_018();
    virtual void r_01c();
    virtual void r_020();
    virtual void r_024();
    virtual void r_028();
    virtual void r_02c();
    virtual void r_030();
    virtual void r_034();
    virtual void r_038();
    virtual void r_03c();
    virtual void r_040();
    virtual void r_044();
    virtual void r_048();
    virtual void r_04c();
    virtual void r_050();
    virtual void r_054();
    virtual void r_058();
    virtual void r_05c();
    virtual void r_060();
    virtual void r_064();
    virtual void r_068();
    virtual void r_06c();
    virtual void r_070();
    virtual void r_074();
    virtual void r_078();
    virtual void r_07c();
    virtual void r_080();
    virtual void r_084();
    virtual void r_088();
    virtual void r_08c();
    virtual void r_090();
    virtual void r_094();
    virtual void r_098();
    virtual void r_09c();
    virtual void r_0a0();
    virtual void r_0a4();
    virtual void r_0a8();
    virtual void r_0ac();
    virtual void r_0b0();
    virtual void r_0b4();
    virtual void r_0b8();
    virtual void r_0bc();
    virtual void r_0c0();
    virtual void r_0c4();
    virtual void r_0c8();
    virtual void r_0cc();
    virtual void r_0d0();
    virtual void r_0d4();
    virtual void r_0d8();
    virtual void r_0dc();
    virtual void r_0e0();
    virtual void r_0e4();
    virtual void r_0e8();
    virtual void r_0ec();
    virtual void r_0f0();
    virtual void r_0f4();
    virtual void r_0f8();
    virtual void r_0fc();
    virtual bool IsActor();
    virtual void r_104();
    virtual void r_108();
    virtual void r_10c();
    virtual void r_110();
    virtual void r_114();
    virtual void r_118();
    virtual void r_11c();
    virtual void r_120();
    virtual void r_124();
    virtual void r_128();
    virtual void r_12c();
    virtual void r_130();
    virtual void r_134();
    virtual void r_138();
    virtual void r_13c();
    virtual void r_140();
    virtual void r_144();
    virtual void r_148();
    virtual void r_14c();
    virtual void r_150();
    virtual void r_154();
    virtual void r_158();
    virtual void r_15c();
    virtual void r_160();
    virtual void r_164();
    virtual void r_168();
    virtual Pt3 GetPos();
    virtual void r_170();
    virtual void r_174();
    virtual void r_178();
    virtual void r_17c();
    virtual void r_180();
    virtual void r_184();
    virtual void r_188();
    virtual void r_18c();
    virtual void r_190();
    virtual void r_194();
    virtual void r_198();
    virtual void r_19c();
    virtual void r_1a0();
    virtual void r_1a4();
    virtual void r_1a8();
    virtual void r_1ac();
    virtual void r_1b0();
    virtual void r_1b4();
    virtual void r_1b8();
    virtual void r_1bc();
    virtual void r_1c0();
    virtual void r_1c4();
    virtual void r_1c8();
    virtual void r_1cc();
    virtual void r_1d0();
    virtual void r_1d4();
    virtual void r_1d8();
    virtual void r_1dc();
    virtual void r_1e0();
    virtual void r_1e4();
    virtual void r_1e8();
    virtual void r_1ec();
    virtual void r_1f0();
    virtual int GetNear(float r);
    virtual void r_1f8();
    virtual void r_1fc();
    virtual void r_200();
    virtual void r_204();
    virtual void r_208();
    virtual void r_20c();
    virtual void r_210();
    virtual void r_214();
    virtual void r_218();
    virtual void r_21c();
    virtual void r_220();
    virtual void r_224();
    virtual void r_228();
    virtual void r_22c();
    virtual void r_230();
    virtual void r_234();
    virtual void r_238();
    virtual void r_23c();
    virtual void r_240();
    virtual void r_244();
    virtual void r_248();
    virtual void r_24c();
    virtual void r_250();
    virtual void r_254();
    virtual void r_258();
    virtual void r_25c();
    virtual void r_260();
    virtual void r_264();
    virtual void r_268();
    virtual void r_26c();
    virtual void r_270();
    virtual void r_274();
    virtual void r_278();
    virtual void r_27c();
    virtual void r_280();
    virtual void r_284();
    virtual void r_288();
    virtual void SetPkgState(Pkg* p, bool b);
    virtual void r_290();
    virtual void r_294();
    virtual void r_298();
    virtual void r_29c();
    virtual void r_2a0();
    virtual void r_2a4();
    virtual void r_2a8();
    virtual void r_2ac();
    virtual void r_2b0();
    virtual void r_2b4();
    virtual void r_2b8();
    virtual void r_2bc();
    virtual void r_2c0();
    virtual void SetAngle(float z);
    void ClearState();
    BaseObj* GetBase();
    bool IsBusy();
    void ApplyThing(const Pt3& p, int a, int b);
    Owner* GetOwner();
    void Reset(int a);
    const char* GetName();
    float GetDistance(Ref* r, int a, int b);
    int GetMode();
    int GetFlags();
    bool IsDone();
    bool IsBlocked();
    bool HasMember(Ref* r);
    int CountMembers();
};

struct Pkg
{
    virtual void k_000();
    virtual void k_004();
    virtual void k_008();
    virtual void k_00c();
    virtual void k_010();
    virtual void k_014();
    virtual void k_018();
    virtual void k_01c();
    virtual void k_020();
    virtual void k_024();
    virtual void k_028();
    virtual void k_02c();
    virtual void k_030();
    virtual void k_034();
    virtual void k_038();
    virtual void k_03c();
    virtual void k_040();
    virtual void k_044();
    virtual void k_048();
    virtual void k_04c();
    virtual void k_050();
    virtual void k_054();
    virtual void k_058();
    virtual void k_05c();
    virtual void k_060();
    virtual void k_064();
    virtual void k_068();
    virtual void k_06c();
    virtual void k_070();
    virtual void k_074();
    virtual void k_078();
    virtual void k_07c();
    virtual void k_080();
    virtual void k_084();
    virtual void k_088();
    virtual void k_08c();
    virtual void k_090();
    virtual void k_094();
    virtual void k_098();
    virtual void k_09c();
    virtual void k_0a0();
    virtual void k_0a4();
    virtual void k_0a8();
    virtual void k_0ac();
    virtual void k_0b0();
    virtual void k_0b4();
    virtual void k_0b8();
    virtual void k_0bc();
    virtual void k_0c0();
    virtual void k_0c4();
    virtual void k_0c8();
    virtual void k_0cc();
    virtual void k_0d0();
    virtual void k_0d4();
    virtual void k_0d8();
    virtual void k_0dc();
    virtual void k_0e0();
    virtual void k_0e4();
    virtual void k_0e8();
    virtual void k_0ec();
    virtual void k_0f0();
    virtual void k_0f4();
    virtual void k_0f8();
    virtual void k_0fc();
    virtual void k_100();
    virtual void k_104();
    virtual void k_108();
    virtual void k_10c();
    virtual void k_110();
    virtual void k_114();
    virtual void k_118();
    virtual void k_11c();
    virtual void k_120();
    virtual void k_124();
    virtual void k_128();
    virtual void k_12c();
    virtual void k_130();
    virtual void k_134();
    virtual void k_138();
    virtual bool CheckA(Ref* r, int a, float f, int b);
    virtual bool CheckB(Ref* t, Ref* r, int a, float f, int b);
    int GetType();
    bool IsDone();
    TargetInfo* GetTarget();
    float GetRange(Ref* r, int a);
    int GetProcType();
    int GetA(Ref* r, float f, int b);
    int GetB(Ref* r);
    Pt3 GetC(Ref* r);
    bool FlagA();
    bool FlagB();
    int GetLocationPointer();
    ProcData* GetData();
    void MarkDone(int a);
    bool FlagC();
    bool FlagD();
    DurInfo* GetDur();
};

struct GameTime
{
    float GetGameTime();
    bool IsSet();
};

struct Lock
{
    void Enter();
};

struct IntSetting
{
    int* Get();
};

struct FloatSetting
{
    float* Get();
};

struct Queue
{
    void Add(Owner* o, int b, int c, void (*fn)(), Ref* r);
};

extern Lock DAT_011e0528;
extern GameTime DAT_011de7b8;
extern int* DAT_011a3ff0[];
extern float DAT_01012054;
extern float DAT_01030020;
extern double DAT_010356d8;
extern double DAT_01012640;
extern double DAT_01012060;
extern double DAT_01011590;
extern Queue* DAT_011c3f2c;
extern int DAT_011ca248;
extern Ref* DAT_011dea3c;
extern IntSetting DAT_011cdad0;
extern FloatSetting DAT_011cdbac;
extern FloatSetting DAT_011cd82c;
extern int DAT_0119bcb0[];

Spell* LookupFormByID(int id);
void FUN_0090d480();
void FUN_0090d570();
Ref* FUN_00703180();
const char* FUN_00464f30(int a, int b);
int FUN_00ec623a(char* buf, const char* fmt, ...);
void FUN_00703c00(const char* s);
void FUN_005ac750(Pkg* p, int a, int b);

struct ProcStandIn
{
    virtual void p_000();
    virtual void p_004();
    virtual void p_008();
    virtual void p_00c();
    virtual void p_010();
    virtual void p_014();
    virtual void p_018();
    virtual void p_01c();
    virtual void p_020();
    virtual bool Eval(Ref* r, int b);
    virtual void p_028();
    virtual void p_02c();
    virtual void p_030();
    virtual void p_034();
    virtual void p_038();
    virtual void p_03c();
    virtual void p_040();
    virtual void p_044();
    virtual void p_048();
    virtual void p_04c();
    virtual void p_050();
    virtual void p_054();
    virtual void p_058();
    virtual void p_05c();
    virtual void p_060();
    virtual void p_064();
    virtual void p_068();
    virtual void p_06c();
    virtual void p_070();
    virtual void p_074();
    virtual void p_078();
    virtual void p_07c();
    virtual void p_080();
    virtual void p_084();
    virtual void p_088();
    virtual void Do08c(Ref* r);
    virtual void Do090(Ref* r, int a);
    virtual void p_094();
    virtual void p_098();
    virtual void p_09c();
    virtual void p_0a0();
    virtual void p_0a4();
    virtual void p_0a8();
    virtual void p_0ac();
    virtual void p_0b0();
    virtual void p_0b4();
    virtual void p_0b8();
    virtual void p_0bc();
    virtual void p_0c0();
    virtual void p_0c4();
    virtual void Do0c8(Ref* r, Pkg* p, int a);
    virtual void p_0cc();
    virtual void p_0d0();
    virtual void p_0d4();
    virtual void p_0d8();
    virtual void p_0dc();
    virtual void p_0e0();
    virtual void p_0e4();
    virtual void p_0e8();
    virtual void p_0ec();
    virtual void p_0f0();
    virtual void p_0f4();
    virtual void p_0f8();
    virtual void p_0fc();
    virtual void p_100();
    virtual void p_104();
    virtual void p_108();
    virtual void p_10c();
    virtual void p_110();
    virtual void p_114();
    virtual void p_118();
    virtual void p_11c();
    virtual void p_120();
    virtual void p_124();
    virtual void p_128();
    virtual void p_12c();
    virtual void p_130();
    virtual void p_134();
    virtual void p_138();
    virtual void p_13c();
    virtual void p_140();
    virtual void p_144();
    virtual void p_148();
    virtual void p_14c();
    virtual void p_150();
    virtual void p_154();
    virtual void p_158();
    virtual void p_15c();
    virtual void p_160();
    virtual void p_164();
    virtual void p_168();
    virtual void p_16c();
    virtual void p_170();
    virtual void p_174();
    virtual void p_178();
    virtual void p_17c();
    virtual void p_180();
    virtual void p_184();
    virtual void p_188();
    virtual void p_18c();
    virtual void p_190();
    virtual void p_194();
    virtual void p_198();
    virtual void p_19c();
    virtual void p_1a0();
    virtual void p_1a4();
    virtual void p_1a8();
    virtual void p_1ac();
    virtual void p_1b0();
    virtual void p_1b4();
    virtual void p_1b8();
    virtual bool Is1bc();
    virtual void Set1c0(int a);
    virtual void p_1c4();
    virtual void Set1c8(int a);
    virtual void p_1cc();
    virtual void p_1d0();
    virtual void p_1d4();
    virtual void p_1d8();
    virtual void p_1dc();
    virtual void p_1e0();
    virtual void p_1e4();
    virtual void p_1e8();
    virtual void p_1ec();
    virtual void p_1f0();
    virtual void p_1f4();
    virtual void p_1f8();
    virtual void p_1fc();
    virtual void p_200();
    virtual void p_204();
    virtual void p_208();
    virtual void p_20c();
    virtual void p_210();
    virtual void p_214();
    virtual void p_218();
    virtual void p_21c();
    virtual void p_220();
    virtual void p_224();
    virtual void p_228();
    virtual Pkg* GetAssignedPackage();
    virtual void p_230();
    virtual void p_234();
    virtual void p_238();
    virtual void p_23c();
    virtual void p_240();
    virtual void p_244();
    virtual void p_248();
    virtual void p_24c();
    virtual void p_250();
    virtual void p_254();
    virtual void p_258();
    virtual void p_25c();
    virtual void p_260();
    virtual void p_264();
    virtual void p_268();
    virtual void p_26c();
    virtual void p_270();
    virtual void p_274();
    virtual void p_278();
    virtual void p_27c();
    virtual int GetProcedureIndex();
    virtual void Set284(int a);
    virtual void Done(Ref* r, int a);
    virtual void p_28c();
    virtual void p_290();
    virtual void p_294();
    virtual void Do298(Ref* r, int a, int b, int c);
    virtual void Do29c(Ref* r, int a, int b, int c);
    virtual void Do2a0(Ref* r);
    virtual void p_2a4();
    virtual void p_2a8();
    virtual void p_2ac();
    virtual void p_2b0();
    virtual void p_2b4();
    virtual void p_2b8();
    virtual void p_2bc();
    virtual void p_2c0();
    virtual void p_2c4();
    virtual void p_2c8();
    virtual void p_2cc();
    virtual void p_2d0();
    virtual void p_2d4();
    virtual void p_2d8();
    virtual void p_2dc();
    virtual void p_2e0();
    virtual void p_2e4();
    virtual void p_2e8();
    virtual void p_2ec();
    virtual void p_2f0();
    virtual void p_2f4();
    virtual void p_2f8();
    virtual void p_2fc();
    virtual void p_300();
    virtual void p_304();
    virtual void p_308();
    virtual void p_30c();
    virtual void p_310();
    virtual void p_314();
    virtual void p_318();
    virtual void p_31c();
    virtual void p_320();
    virtual void p_324();
    virtual void p_328();
    virtual void p_32c();
    virtual void p_330();
    virtual void p_334();
    virtual void p_338();
    virtual void p_33c();
    virtual void p_340();
    virtual void p_344();
    virtual void p_348();
    virtual void p_34c();
    virtual void p_350();
    virtual void p_354();
    virtual void p_358();
    virtual void p_35c();
    virtual void p_360();
    virtual void p_364();
    virtual void p_368();
    virtual void p_36c();
    virtual void p_370();
    virtual void p_374();
    virtual void p_378();
    virtual void p_37c();
    virtual void p_380();
    virtual void p_384();
    virtual void p_388();
    virtual void p_38c();
    virtual void p_390();
    virtual void p_394();
    virtual void p_398();
    virtual void p_39c();
    virtual void p_3a0();
    virtual void p_3a4();
    virtual void p_3a8();
    virtual void p_3ac();
    virtual void p_3b0();
    virtual void p_3b4();
    virtual void p_3b8();
    virtual void p_3bc();
    virtual void p_3c0();
    virtual void p_3c4();
    virtual void p_3c8();
    virtual void p_3cc();
    virtual void p_3d0();
    virtual void p_3d4();
    virtual void p_3d8();
    virtual void p_3dc();
    virtual void p_3e0();
    virtual void p_3e4();
    virtual void p_3e8();
    virtual void p_3ec();
    virtual void p_3f0();
    virtual void p_3f4();
    virtual void p_3f8();
    virtual void p_3fc();
    virtual void p_400();
    virtual void p_404();
    virtual void p_408();
    virtual void p_40c();
    virtual void p_410();
    virtual void p_414();
    virtual void p_418();
    virtual void p_41c();
    virtual void p_420();
    virtual void p_424();
    virtual void p_428();
    virtual void p_42c();
    virtual void p_430();
    virtual void p_434();
    virtual void p_438();
    virtual void p_43c();
    virtual void p_440();
    virtual void p_444();
    virtual void p_448();
    virtual void p_44c();
    virtual void p_450();
    virtual void p_454();
    virtual void p_458();
    virtual void p_45c();
    virtual void p_460();
    virtual void p_464();
    virtual void p_468();
    virtual void p_46c();
    virtual void p_470();
    virtual void p_474();
    virtual void p_478();
    virtual void p_47c();
    virtual void p_480();
    virtual void p_484();
    virtual void p_488();
    virtual void p_48c();
    virtual void p_490();
    virtual void p_494();
    virtual void p_498();
    virtual void p_49c();
    virtual void p_4a0();
    virtual void p_4a4();
    virtual void p_4a8();
    virtual void p_4ac();
    virtual void p_4b0();
    virtual void p_4b4();
    virtual void p_4b8();
    virtual void p_4bc();
    virtual void p_4c0();
    virtual void p_4c4();
    virtual void p_4c8();
    virtual void p_4cc();
    virtual void p_4d0();
    virtual void p_4d4();
    virtual void p_4d8();
    virtual void p_4dc();
    virtual void p_4e0();
    virtual void p_4e4();
    virtual void p_4e8();
    virtual void p_4ec();
    virtual void p_4f0();
    virtual void p_4f4();
    virtual void p_4f8();
    virtual void p_4fc();
    virtual void p_500();
    virtual void p_504();
    virtual void p_508();
    virtual void p_50c();
    virtual void p_510();
    virtual void p_514();
    virtual void p_518();
    virtual void p_51c();
    virtual void p_520();
    virtual void Do524(Ref* r);
    virtual void p_528();
    virtual void p_52c();
    virtual void p_530();
    virtual void p_534();
    virtual void p_538();
    virtual void p_53c();
    virtual void p_540();
    virtual void p_544();
    virtual void p_548();
    virtual void p_54c();
    virtual void p_550();
    virtual void p_554();
    virtual void p_558();
    virtual void p_55c();
    virtual void p_560();
    virtual void p_564();
    virtual void p_568();
    virtual void p_56c();
    virtual void p_570();
    virtual void p_574();
    virtual void p_578();
    virtual void p_57c();
    virtual void p_580();
    virtual void p_584();
    virtual void p_588();
    virtual void p_58c();
    virtual void p_590();
    virtual void p_594();
    virtual void p_598();
    virtual void p_59c();
    virtual void Do5a0(Ref* r, Pkg* p);
    virtual bool Is5a4();
    virtual void Set5a8(int a);
    virtual void p_5ac();
    virtual void p_5b0();
    virtual void p_5b4();
    virtual void p_5b8();
    virtual void p_5bc();
    virtual void p_5c0();
    virtual void p_5c4();
    virtual void p_5c8();
    virtual void p_5cc();
    virtual void p_5d0();
    virtual void p_5d4();
    virtual void p_5d8();
    virtual void p_5dc();
    virtual void p_5e0();
    virtual void p_5e4();
    virtual void p_5e8();
    virtual void p_5ec();
    virtual void p_5f0();
    virtual void p_5f4();
    virtual void p_5f8();
    virtual void p_5fc();
    virtual void p_600();
    virtual void p_604();
    virtual void p_608();
    virtual void p_60c();
    virtual void p_610();
    virtual void p_614();
    virtual void p_618();
    virtual void p_61c();
    virtual void p_620();
    virtual void p_624();
    virtual void p_628();
    virtual void p_62c();
    virtual void p_630();
    virtual void p_634();
    virtual void p_638();
    virtual void p_63c();
    virtual void p_640();
    virtual void p_644();
    virtual void p_648();
    virtual void p_64c();
    virtual void p_650();
    virtual void p_654();
    virtual void p_658();
    virtual void p_65c();
    virtual void p_660();
    virtual void p_664();
    virtual void p_668();
    virtual void p_66c();
    virtual void p_670();
    virtual void p_674();
    virtual void p_678();
    virtual void p_67c();
    virtual void p_680();
    virtual void p_684();
    virtual void p_688();
    virtual void p_68c();
    virtual void p_690();
    virtual void p_694();
    virtual void p_698();
    virtual void p_69c();
    virtual void p_6a0();
    virtual void p_6a4();
    virtual void p_6a8();
    virtual void p_6ac();
    virtual void p_6b0();
    virtual void p_6b4();
    virtual void p_6b8();
    virtual void p_6bc();
    virtual void p_6c0();
    virtual void p_6c4();
    virtual void p_6c8();
    virtual void p_6cc();
    virtual void p_6d0();
    virtual void p_6d4();
    virtual void p_6d8();
    virtual void p_6dc();
    virtual void p_6e0();
    virtual void p_6e4();
    virtual void p_6e8();
    virtual void p_6ec();
    virtual void p_6f0();
    virtual void p_6f4();
    virtual void p_6f8();
    virtual void p_6fc();
    virtual void p_700();
    virtual void p_704();
    virtual void p_708();
    virtual void p_70c();
    virtual void p_710();
    virtual void p_714();
    virtual void p_718();
    virtual void p_71c();
    virtual void p_720();
    virtual void p_724();
    virtual void p_728();
    virtual void p_72c();
    virtual void p_730();
    virtual void p_734();
    virtual void p_738();
    virtual void p_73c();
    virtual void p_740();
    virtual void p_744();
    virtual void p_748();
    virtual void p_74c();
    virtual void p_750();
    virtual void p_754();
    virtual void p_758();
    virtual void p_75c();
    virtual void p_760();
    virtual void p_764();
    virtual void p_768();
    virtual void p_76c();
    virtual void p_770();
    virtual void p_774();
    virtual void p_778();
    virtual void p_77c();
    virtual void p_780();
    virtual void p_784();
    virtual void p_788();
    virtual void p_78c();
    virtual void p_790();
    virtual void p_794();
    virtual void p_798();
    virtual void p_79c();
    virtual void p_7a0();
    virtual void p_7a4();
    virtual void p_7a8();
    virtual void p_7ac();
    virtual void p_7b0();
    virtual void Proc7b4(Ref* r);
    virtual void Proc7b8(Ref* r);
    virtual void Proc7bc(Ref* r);
    virtual void Proc7c0(Ref* r);
    virtual void Proc7c4(Ref* r);
    virtual void Proc7c8(Ref* r, int a);
    virtual void Proc7cc(Ref* r);
    virtual void Proc7d0(Ref* r);
    virtual void Proc7d4(Ref* r);
    virtual void Proc7d8(Ref* r);
    virtual void Proc7dc(Ref* r);
    virtual void Proc7e0(Ref* r);
    virtual void Proc7e4(Ref* r);
    virtual void Proc7e8(Ref* r);
    virtual void Proc7ec(Ref* r);
    virtual void Proc7f0(Ref* r);
    virtual void Proc7f4(Ref* r);
    virtual void Proc7f8(Ref* r);
    virtual void Proc7fc(Ref* r);
    virtual void Proc800(Ref* r);
    virtual void Proc804(Ref* r);
    virtual void Proc808(Ref* r);
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
    Ref* m_pFlagTarget;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    ItemList m_kUnsortedGeometryList;
    Item* m_pInventoryEntryData;
    void Prepare();
    float GetTime();
    void FUN_0092d050(Ref* apRef);
};

// @fnv 0x0092d050
void ProcStandIn::FUN_0092d050(Ref* apRef)
{
    DAT_011e0528.Enter();
    if (apRef == 0)
    {
        return;
    }
    Ref* pActor = apRef->IsActor() ? apRef : 0;
    float fHour = DAT_011de7b8.GetGameTime();
    {
        Pkg* pPkg;
        TargetInfo* pInfoA;
        Ext* pExt;
        if (pActor != 0)
        {
            if (Eval(pActor, 0))
            {
                Do524(pActor);
                pActor->ClearState();
                Do090(pActor, 0);
            }
            pPkg = GetAssignedPackage();
            if (GetAssignedPackage() != 0 && GetAssignedPackage()->GetType() != -1 && !pPkg->IsDone())
            {
                Prepare();
                pInfoA = GetAssignedPackage()->GetTarget();
                pExt = 0;
                char acBuffer[304];
                switch (DAT_011a3ff0[GetAssignedPackage()->GetType()][GetProcedureIndex()])
                {
                case 0:
                    if (pInfoA != 0)
                    {
                        pExt = pInfoA->GetTarget();
                    }
                    if (pExt == 0)
                    {
                        BaseObj* pBase = pActor->GetBase();
                        pExt = pBase != 0 ? pBase->Get514() : 0;
                    }
                    if (!GetAssignedPackage()->CheckA(pActor, 0, DAT_01012054, 0) && pActor->IsBusy())
                    {
                        Spell* m_pEffectInstance = LookupFormByID(0x3a);
                        float fNowVal = DAT_011de7b8.GetGameTime();
                        if (fNowVal < GetTime())
                        {
                            fNowVal += DAT_010356d8;
                        }
                        float fElapsedX = fNowVal - GetTime();
                        fElapsedX = DAT_01012640 / m_pEffectInstance->GetDur() * fElapsedX;
                        float fImpulseRadiusSquared = GetAssignedPackage()->GetRange(pActor, 0);
                        if (GetAssignedPackage()->GetProcType() == 5)
                        {
                            fImpulseRadiusSquared = 0.0f;
                        }
                        pActor->ApplyThing(GetAssignedPackage()->GetC(pActor), GetAssignedPackage()->GetB(pActor),
                                           GetAssignedPackage()->GetA(pActor, fImpulseRadiusSquared, 0));
                    }
                    if (pActor->GetBase()->GetLevel() == 2 && GetAssignedPackage()->CheckA(pActor, 0, DAT_01012054, 0))
                    {
                        if (!Is1bc())
                        {
                            if (GetAssignedPackage()->FlagA())
                            {
                                DAT_011c3f2c->Add(pActor->GetOwner(), pActor->GetNear(DAT_01030020),
                                                  pActor->GetNear(DAT_01030020), FUN_0090d480, pActor);
                            }
                            Set1c0(1);
                        }
                        if (GetAssignedPackage()->FlagB())
                        {
                            DAT_011c3f2c->Add(pActor->GetOwner(), pActor->GetNear(DAT_01030020),
                                              pActor->GetNear(DAT_01030020), FUN_0090d570, pActor);
                        }
                        if ((pExt != 0 && pExt->GetRace() == DAT_011ca248) ||
                            (GetAssignedPackage()->GetTarget() != 0 && GetAssignedPackage()->GetTarget()->GetKind() == 3))
                        {
                            float fAngleDifference = 0.0f;
                            if (pExt != 0)
                            {
                                fAngleDifference = pExt->GetPos()->z;
                            }
                            else
                            {
                                fAngleDifference = pActor->GetPos().z;
                            }
                            pActor->SetAngle(fAngleDifference);
                        }
                        Done(pActor, 1);
                    }
                    break;
                case 28:
                    Proc7d8(pActor);
                    break;
                case 50:
                    Proc7dc(pActor);
                    break;
                case 33:
                    Proc7e0(pActor);
                    break;
                case 12:
                    pActor->Reset(0);
                    break;
                case 49: {
                    Ref* pTarget = 0;
                    if (m_pFlagTarget != 0 && m_pFlagTarget->IsActor())
                    {
                        pTarget = m_pFlagTarget;
                    }
                    if (pTarget != 0)
                    {
                        if (GetAssignedPackage()->GetLocationPointer() == 0 ||
                            GetAssignedPackage()->CheckB(pTarget, pActor, 0, DAT_01012054, 1))
                        {
                            Proc7c8(pActor, 1);
                        }
                    }
                    break;
                }
                case 39:
                    Proc7e8(pActor);
                    break;
                case 17:
                    if (m_pFlagTarget == 0)
                    {
                        Do08c(pActor);
                    }
                    if (m_pFlagTarget != 0 && m_pFlagTarget != DAT_011dea3c)
                    {
                        Do0c8(pActor, pPkg, 1);
                    }
                    Done(pActor, 1);
                    break;
                case 41:
                    Done(pActor, 2);
                    break;
                case 26:
                    Proc808(pActor);
                    break;
                case 10:
                    Do2a0(pActor);
                    break;
                case 38:
                    Proc800(pActor);
                    break;
                case 34:
                    Proc7e4(pActor);
                    break;
                case 27:
                    Proc7cc(pActor);
                    break;
                case 30:
                    Proc7d4(pActor);
                    break;
                    break;
                case 14:
                    Proc7c8(pActor, 0);
                    break;
                case 3:
                    Proc7d0(pActor);
                    break;
                case 8:
                    Proc7c4(pActor);
                    break;
                case 15:
                    Do29c(pActor, 0, 1, 0x101);
                    break;
                case 2:
                    Proc7c8(pActor, 1);
                    break;
                case 1:
                    if (GetAssignedPackage()->GetType() == 0x1a)
                    {
                        Done(pActor, -1);
                    }
                    break;
                case 4:
                    if (FUN_00703180() == pActor)
                    {
                        FUN_00ec623a(acBuffer, "%s is sleeping with %s", pActor->GetName(),
                                     FUN_00464f30(DAT_0119bcb0[GetAssignedPackage()->GetProcType()], 0));
                        FUN_00703c00(acBuffer);
                    }
                    break;
                case 5:
                    if (FUN_00703180() == pActor)
                    {
                        FUN_00ec623a(acBuffer, "%s is eating with %s", pActor->GetName(),
                                     FUN_00464f30(DAT_0119bcb0[GetAssignedPackage()->GetProcType()], 0));
                        FUN_00703c00(acBuffer);
                    }
                    break;
                case 6:
                    Do298(pActor, 1, 0x101, 0);
                    break;
                case 42:
                    Proc7ec(pActor);
                    break;
                case 51:
                    Proc7f0(pActor);
                    break;
                case 13:
                    if (m_pFlagTarget == 0)
                    {
                        Do08c(pActor);
                    }
                    if (m_pFlagTarget == 0 || m_pFlagTarget->IsBlocked())
                    {
                        Done(pActor, 1);
                    }
                    else if (pPkg->IsDone())
                    {
                        if (!DAT_011dea3c->HasMember(pActor) && DAT_011dea3c->CountMembers() < *DAT_011cdad0.Get())
                        {
                            pPkg->MarkDone(0);
                        }
                    }
                    else if (pPkg->GetProcType() != 0x1c && !pPkg->IsDone())
                    {
                        if (pPkg->GetProcType() == 1)
                        {
                            float fLimit = (float)pPkg->GetData()->GetInt();
                            if (fLimit >= pActor->GetDistance(m_pFlagTarget, 0, 0))
                            {
                                Done(pActor, 1);
                            }
                        }
                        else
                        {
                            float fDist = 0.0f;
                            int iMaxA = GetAssignedPackage()->GetData()->GetInt();
                            if (iMaxA <= 0)
                            {
                                iMaxA = 200;
                            }
                            if (fDist == DAT_01012060 && pActor->GetOwner() != 0 && pActor->GetOwner()->IsSet())
                            {
                                fDist = *DAT_011cdbac.Get();
                            }
                            else if (fDist == DAT_01012060)
                            {
                                fDist = *DAT_011cd82c.Get();
                            }
                            if (pActor->GetDistance(m_pFlagTarget, 0, 0) <= fDist / DAT_01011590)
                            {
                                Done(pActor, 1);
                            }
                        }
                    }
                    else
                    {
                        Done(pActor, 1);
                    }
                    break;
                case 7:
                    Proc7b4(pActor);
                    break;
                case 44:
                    Proc7fc(pActor);
                    break;
                case 47:
                    Proc7f4(pActor);
                    break;
                }
                if (pActor->GetMode() == 2 && GetAssignedPackage() != 0 &&
                    DAT_011a3ff0[GetAssignedPackage()->GetType()][GetProcedureIndex()] == 0x36)
                {
                    if (!Is5a4())
                    {
                        FUN_005ac750(GetAssignedPackage(), pActor->GetFlags(), 0x400);
                        Do5a0(pActor, GetAssignedPackage());
                        Set5a8(1);
                    }
                    Set1c8(0);
                    if (GetAssignedPackage() != 0 && GetAssignedPackage()->GetType() == 0 &&
                        !GetAssignedPackage()->CheckA(pActor, 0, DAT_01012054, 0))
                    {
                        Done(pActor, -1);
                        return;
                    }
                    if (GetAssignedPackage() != 0 && GetAssignedPackage()->FlagC())
                    {
                        pActor->SetPkgState(GetAssignedPackage(), DAT_011de7b8.IsSet());
                    }
                    if (GetAssignedPackage() != 0 && GetAssignedPackage()->FlagD())
                    {
                        pActor->Reset(0);
                    }
                    if (FUN_00703180() == pActor)
                    {
                        FUN_00ec623a(acBuffer, "%s is done with %s", pActor->GetName(),
                                     FUN_00464f30(DAT_0119bcb0[GetAssignedPackage()->GetProcType()], 0));
                        FUN_00703c00(acBuffer);
                    }
                    delete m_pInventoryEntryData;
                    m_pInventoryEntryData = 0;
                    while (!m_kUnsortedGeometryList.IsEmpty())
                    {
                        Item* pItem = *m_kUnsortedGeometryList.Head();
                        delete pItem;
                        m_kUnsortedGeometryList.Remove(&pItem);
                    }
                    if (GetAssignedPackage() != 0 && GetAssignedPackage()->GetDur()->GetEnd() == 0)
                    {
                        Pkg* pOld = GetAssignedPackage();
                        Eval(pActor, 1);
                        pPkg = GetAssignedPackage();
                        if (pOld != GetAssignedPackage())
                        {
                            Set284(0);
                        }
                    }
                }
            }
            if (!pActor->IsDone())
            {
                apRef->GetBase()->Update28();
            }
        }
        else
        {
            apRef->GetBase()->Update28();
        }
    }
}
}  // namespace fnv_0092d050
