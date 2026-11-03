// fallout_shared/bgsdehydration.cpp: BGSDehydrationStage, BGSHungerStage, WaitableObject, TESForm and more (45 functions)

#include "bgsdehydration_decls.h"
#include "bgsdehydration_types_BGSDehydrationStage.h"
#include "bgsdehydration_types_BGSHungerStage.h"
#define IsFormInitialized GetInitialized
#include <malloc.h>

class SpellItem : public TESForm
{
};
void FUN_004016a0(BGSDehydrationStage* stage);
extern "C" unsigned int DAT_011c3180;
extern "C" BGSDehydrationStage** DAT_011c3184;
void __cdecl operator delete(void* pointer);

class StageLoadVirtuals
{
  public:
    virtual void vfn_0000() = 0;
    virtual void vfn_0004() = 0;
    virtual void vfn_0008() = 0;
    virtual void vfn_000c() = 0;
    virtual void vfn_0010() = 0;
    virtual void vfn_0014() = 0;
    virtual void vfn_0018() = 0;
};

// @fnv 0x00401330
void BGSDehydrationStage::ClearData()
{
    ClearStageData(this);
}

// @fnv 0x00401b20
void BGSHungerStage::ResetFormData()
{
    FUN_00500940()->Reinitialize();
}

// Allocates a zero-initialized array of count BGSDehydrationStage pointers, returning null when count is zero.
// @fnv 0x004024e0
BGSDehydrationStage** BGSDehydrationStage::AllocateStageArray(unsigned int count)
{
    if (!count)
        return 0;

    BGSDehydrationStage** stages = new BGSDehydrationStage*[count];
    for (unsigned int index = 0; index < count; ++index)
        stages[index] = 0;
    return stages;
}

// Constructs a BGSDehydrationStage and sets its form type to 0x6e.
// @fnv 0x005a7160
BGSDehydrationStage::BGSDehydrationStage()
{
    SetFormType((ENUM_FORM_ID)0x6e);
}

// @fnv 0x00401350
void BGSDehydrationStage::InitItem()
{
    if (IsFormInitialized())
        return;

    unsigned int formID = FUN_00441110();
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        FUN_0050f9a0(dynamic_cast<SpellItem*>(TESForm::GetFormByID(formID)));
    }

    SetInitializationState(true);
    FUN_004016a0(this);
}

struct RemoveStageLocals
{
    BGSDehydrationStage** oldStages;
    unsigned int source;
    unsigned int destination;
    unsigned int index;
    unsigned char padding0;
    unsigned char padding1;
    unsigned char padding2;
    bool found;
    unsigned int newCount;
    BGSDehydrationStage** newStages;
};

// Removes stage from the global stage array by allocating a smaller array, copying all other entries, deleting the old array and updating the count and pointer.
// @fnv 0x004017a0
void BGSDehydrationStage::ClearStageData(BGSDehydrationStage* stage)
{
    RemoveStageLocals locals;

    if (!DAT_011c3180)
        return;

    locals.found = false;
    locals.index = 0;
    for (; !locals.found && locals.index < DAT_011c3180; ++locals.index)
    {
        if (DAT_011c3184[locals.index] == stage)
            locals.found = true;
    }

    if (!locals.found)
        return;

    locals.newCount = DAT_011c3180 - 1;
    locals.newStages = BGSDehydrationStage::AllocateStageArray(locals.newCount);
    if (locals.newStages)
    {
        locals.destination = 0;
        locals.source = 0;
        for (; locals.source < DAT_011c3180; ++locals.source)
        {
            if (DAT_011c3184[locals.source] != stage)
            {
                locals.newStages[locals.destination] = DAT_011c3184[locals.source];
                ++locals.destination;
            }
        }
    }

    locals.oldStages = DAT_011c3184;
    ::operator delete(locals.oldStages);
    DAT_011c3180 = locals.newCount;
    DAT_011c3184 = locals.newStages;
}

// Reads a TESFile record of type 0x76, dispatching EDID, OBND and DATA chunks until the chunk list ends, and returns true on success.
// @fnv 0x00401510
bool BGSDehydrationStage::Load(TESFile* file)
{
    unsigned char formType = file->GetTESForm();
    if (formType != 0x76)
        return false;

    reinterpret_cast<StageLoadVirtuals*>(this)->vfn_0018();
    LoadRecordHeader(file);
    SetInitializationState(false);

    unsigned int chunk;
    while ((chunk = file->GetChunkID()) != 0)
    {
        switch (chunk)
        {
        case 0x44494445: {
            char* buffer = static_cast<char*>(_alloca(file->GetChunkSize()));
            file->GetChunkData(buffer, 0x200);
            SetEditorID_AtRuntime(buffer);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x41544144:
            FUN_004861f0(file, FUN_00500940(8));
            break;
        }

        if (chunk == 0x41544144 && file->IsEndianConversionRequired())
            data.FUN_00462230();
        if (!file->NextChunk())
            break;
    }
    return true;
}

// Scans stages up to DAT_011c3180 and returns the first stage whose GetMaxLevel() is <= level, or null.
// @fnv 0x004018b0
BGSDehydrationStage* BGSDehydrationStage::FindStage(float level)
{
    BGSDehydrationStage* result = 0;
    for (unsigned int index = 0; index < DAT_011c3180 && !result; ++index)
    {
        BGSDehydrationStage* stage = GetStage(index);
        if (stage && level >= reinterpret_cast<BGSTerrainManager*>(stage)->GetMaxLevel())
            result = stage;
    }
    return result;
}
// @fnv 0x00401a10
BGSHungerStage::BGSHungerStage()
{
    SetFormType((ENUM_FORM_ID)0x77);
    ResetFormData();
}

// Returns the dehydration stage at index if index is below DAT_011c3180, otherwise returns null.
// @fnv 0x00401930
BGSDehydrationStage* BGSDehydrationStage::GetStage(unsigned int index)
{
    return index >= 0 && index < DAT_011c3180 ? DAT_011c3184[index] : 0;
}
// Waits on the references handle and calls vfn_0004 when the wait succeeds without timeout.
// @fnv 0x00401970
void WaitableObject::FUN_00401970()
{
    if (!WaitForSingleObjectEx(&references))
        vfn_0004();
}
// @fnv 0x004019d0
float ConvertDoubleResult(float value)
{
    return static_cast<float>(FUN_00ec6054(value));
}
// @fnv 0x004013e0
bool TESForm::GetInitialized() const
{
    return (m_uiFormFlags & 8) ? true : false;
}
// @fnv 0x004019f0
HungerStageData::HungerStageData()
{
    Reinitialize();
}
// @fnv 0x004019b0
float FUN_004019b0(float value)
{
    return ConvertDoubleResult(value);
}
// @fnv 0x004019a0
unsigned long WaitForSingleObjectEx(long* value)
{
    return InterlockedDecrement(value);
}

struct Base5a
{
    virtual ~Base5a();
};

class FUN_004012d0_shell : public BGSDehydrationStage
{
  public:
    ~FUN_004012d0_shell();
};

// @fnv 0x004012d0
FUN_004012d0_shell::~FUN_004012d0_shell()
{
    ClearData();
}

struct ActiveEffect;
struct Actor;
struct ActorCause;
struct ActorMover;
struct AlchemyItem;
struct Animation;
struct TwoIntegerValues;
struct MediaLocation;
struct BGSEncounterZone;
struct ExplosionForm;
struct BGSImpactDataSet;
struct BGSLoadFormBuffer;
struct BGSLoadGameBuffer;
struct BGSPerk;
struct BGSPerkEntry;
struct BGSSaveFormBuffer;
struct BGSSaveGameBuffer;
struct BGSTextureSet;
struct BSAnimGroupSequence;
struct BSAnimNote;
struct BSAnimNoteReceiver;
struct BSExtraData;
struct BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct BSMultiBound;
struct BSMultiBoundRoom;
struct SoundPlaybackHandle;
struct BaseProcess;
struct BipedAnim;
struct CombatGroupCollection;
struct CellMopp;
struct CombatController;
struct ActorCombatGroup;
struct ContinuousBeamProjectile;
struct Crime;
struct GameFormRecord;
struct DialogueResponse;
struct DetectionParameters;
struct TeleportableReference;
struct EffectItem;
struct ExtraDataList;
struct ExtraLock;
struct FormRecordHeader;
struct TESFileGroup;
struct FurnitureMark;
struct BooleanIntegerAccessor;
struct BooleanFloatQuery;
struct IDebugText;
struct InventoryChanges;
struct InventoryStackRecord;
struct CellDataNode;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct MapMarkerData;
struct MobileObject;
struct Point3Offset;
struct NiAVObject;
struct AnimationInterpolator;
struct NiControllerManager;
struct NiControllerSequence;
struct NiFixedString;
struct NiGeometry;
struct NiLight;
struct ThreeByThreeMatrix;
struct NiNode;
struct NiPoint3;
struct NiPointLight;
struct PlacedObjectInfo;
struct IndexedPointerCollection;
struct LocationDescriptor;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct PathingRequest;
struct Projectile;
struct QueuedFile;
struct ReferenceLightData;
struct LockExtraData;
struct ReferenceIntersectionData;
struct RagDollData;
struct Script;
struct ScriptLocals;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESClass;
struct TESCombatStyle;
struct TESContainer;
struct TESFaction;
struct TESGlobal;
struct TESIdleForm;
struct TESModel;
struct TESObject;
struct TESObjectARMO;
struct TESObjectBOOK;
struct TESObjectCELL;
struct TESObjectCLOT;
struct TESObjectLIGH;
struct TESObjectREFR;
struct TESObjectWEAP;
struct TESPackage;
struct TESRace;
struct TESSkill;
struct TESSound;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct TrespassPackage;
struct WaterZone;
struct WeaponObject;
struct bhkCharacterController;
struct bhkNiCollisionObject;
struct bhkRagdollController;
struct bhkRagdollPenetrationUtil;
struct bhkRigidBody;
struct hkpRigidBody;
struct blob4
{
    char b[4];
};
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
};
struct blob48
{
    char b[48];
};
struct TESChildCell
{
    virtual TESObjectCELL* GetSaveParentCell();
};
typedef char _sizecheck_TESChildCell[sizeof(TESChildCell) == 4 ? 1 : -1];
struct ActorValueOwner
{
    virtual int GetBaseActorValue(int);
    virtual float GetBaseActorValueFloat(int);
    virtual int GetActorValue(int);
    virtual float GetCurrentActorValue(int);
    virtual float GetPermanentActorValueFloat(int);
    virtual float GetTemporaryActorValue(int);
    virtual float GetDamageActorValue(int);
    virtual int GetPermanentActorValue(int);
    virtual float GetPermanentActorValueAdjustment(int);
    virtual TESForm* GetActorValueOwnerForm();
    virtual unsigned short GetActorValueOwnerType();
    int GetActorValueAsInteger(int);
    float GetActorValueFloatByIndex(int);
};
typedef char _sizecheck_ActorValueOwner[sizeof(ActorValueOwner) == 4 ? 1 : -1];
struct CachedValuesOwner
{
    virtual float GetFloatValue0();
    virtual float GetFloatValue1();
    virtual float GetFloatValue2();
    virtual float GetFloatValue3();
    virtual float GetFloatValue4();
    virtual float GetFloatValue5();
    virtual float GetFloatValue6();
    virtual float GetFloatValue7();
    virtual float GetFloatValue8();
    virtual float GetFloatValue9();
    virtual float GetFloatValue10();
    virtual float GetFloatValue11();
    virtual int GetIntegerValue12();
    virtual int GetIntegerValue13();
    virtual float GetFloatValue14();
    virtual float GetFloatValue15();
    virtual bool GetBooleanValue16();
    void PrecalculateCachedValues();
};
typedef char _sizecheck_CachedValuesOwner[sizeof(CachedValuesOwner) == 4 ? 1 : -1];
struct FUN_00401190_shell : public TESForm
{
    bool FUN_00401190();
};

// @fnv 0x00401190
bool FUN_00401190_shell::FUN_00401190()
{
    return (m_uiFormFlags & 0x400) ? true : false;
}

struct FUN_00401230_shell
{
    bool IsFlag40000000Set() const;
};

// @fnv 0x00401230
bool FUN_00401230_shell::IsFlag40000000Set() const
{
    return (((unsigned int*)this)[2] & 0x40000000) ? true : false;
}

struct FUN_009f87b0_shell
{
    void FUN_009f87b0();
    void FUN_006796c0();
};
// @fnv 0x009f87b0
void FUN_009f87b0_shell::FUN_009f87b0()
{
    FUN_006796c0();
}

void __cdecl _Deallocate(void*);
struct FUN_004012a0_Holder
{
    void* FUN_004012a0(unsigned int);
};
// Runs the destructor on this object, frees it with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x004012a0
void* FUN_004012a0_Holder::FUN_004012a0(unsigned int flags)
{
    ((FUN_004012d0_shell*)this)->FUN_004012d0_shell::~FUN_004012d0_shell();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void* __memcpy(void*, const void*, unsigned int);
struct FUN_005e78f0_t
{
    void FUN_004851b0(TESForm*);
};
struct FUN_00401400_class
{
    void CopyFromDehydrationStage(TESForm* apCopy);
};
// @fnv 0x00401400
void FUN_00401400_class::CopyFromDehydrationStage(TESForm* apCopy)
{
    BGSDehydrationStage* pcopy;
    pcopy = dynamic_cast<BGSDehydrationStage*>(apCopy);
    if (!pcopy)
        return;
    ((FUN_005e78f0_t*)this)->FUN_004851b0(pcopy);
    __memcpy(((BGSHungerStage*)this)->FUN_00500940(), ((BGSHungerStage*)pcopy)->FUN_00500940(), 8);
}

struct TESObjectLIGH
{
    bool FUN_0046f070();
    bool InvokeAction(unsigned int, unsigned int, bool, unsigned int, unsigned int);
    bool FUN_0050e4b0(unsigned int, unsigned int, bool, unsigned int, unsigned int);
};
// Returns false if FUN_0046f070 fails, otherwise forwards the arguments to InvokeAction and returns its result.
// @fnv 0x0050e4b0
bool TESObjectLIGH::FUN_0050e4b0(unsigned int a1, unsigned int a2, bool bFlag, unsigned int a4, unsigned int a5)
{
    if (!FUN_0046f070())
        return false;
    return InvokeAction(a1, a2, bFlag, a4, a5);
}

struct Unk515010
{
    void InvokeAction(int, int, bool, int, int);
    void ForwardToF670(int, int, bool, int, int);
};
// Calls InvokeAction with the same five arguments, forwarding the call unchanged.
// @fnv 0x00515010
void Unk515010::ForwardToF670(int aiArg1, int aiArg2, bool abFlag, int aiArg4, int aiArg5)
{
    InvokeAction(aiArg1, aiArg2, abFlag, aiArg4, aiArg5);
}

struct TESObjectREFR
{
    virtual ~TESObjectREFR()
    {}
};
struct Actor : TESObjectREFR
{
};
struct Dummy25750
{
    void InvokeAction(int, TESObjectREFR*, bool, int, int);
    void CastToActorAndCall(int, TESObjectREFR*, bool, int, int);
};
// Casts b to Actor and forwards all arguments to InvokeAction; the cast result is unused.
// @fnv 0x00525750
void Dummy25750::CastToActorAndCall(int aiArg1, TESObjectREFR* apRefr, bool abFlag, int aiArg4, int aiArg5)
{
    Actor* actor = dynamic_cast<Actor*>(apRefr);
    InvokeAction(aiArg1, apRefr, abFlag, aiArg4, aiArg5);
}

namespace fnv_00551740 {
struct Actor;
struct BGSAcousticSpace;
struct BGSEncounterZone;
struct BGSLightingTemplate;
struct BGSLoadFormBuffer;
struct BGSMusicType;
struct BGSSaveFormBuffer;
struct BSFile;
struct BSMultiBoundNode;
struct BSPortalGraph;
struct CellMopp;
struct CellRecord;
struct ExteriorData;
struct ExtraDataList;
struct FormRecordHeader;
struct TESFileGroup;
struct InteriorData;
struct ImpactSwap;
struct IntSeenData;
struct InventoryChanges;
struct LoadedCellData;
struct NavMeshCollection;
struct NiAVObject;
struct NiCamera;
struct NiColor;
struct NiNode;
struct NiPick;
struct NiPoint3;
struct NiRenderedTexture;
struct SeenData;
struct TESActorBase;
struct TESClimate;
struct TESGlobal;
struct TESImageSpace;
struct TESObject;
struct TESObjectCELL;
struct TESObjectLAND;
struct TESObjectREFR;
struct TESRegionList;
struct TESRegionObjectBase;
struct RegionPoint;
struct TESWaterForm;
struct TESWorldSpace;
struct _D3DLOCKED_RECT;
struct BhkPickData;
struct bhkWorld;
struct bhkWorldM;
struct blob12
{
    char b[12];
};
struct TESFullName : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetFullNameLength(TESForm*);
    unsigned int GetFullNameLength();
    static char* GetFullName(TESForm*);
    char* GetFullName();
    void SetFullName(char*);
    static void LoadFullNameChunk(TESFullName*, TESFile*);
    void* GetFullNameString();
    void* __vecDelDtor(unsigned int);
    char m_kName[8];
};
typedef char _sizecheck_TESFullName[sizeof(TESFullName) == 12 ? 1 : -1];
struct FUN_00551740_shell : public TESForm
{
    char* GetCellName();
};

struct StartMenu
{
    char const* GetMenuTitle();
};
extern StartMenu g_011ca130;
struct TESObjectCELL
{
    bool IsInterior();
    char* FUN_00451cb0();
};
struct CellExtra28
{
    char* FUN_0041c7c0();
};
// @fnv 0x00551740
char* FUN_00551740_shell::GetCellName()
{
    if (reinterpret_cast<CellExtra28*>(reinterpret_cast<char*>(this) + 0x28)->FUN_0041c7c0())
        return reinterpret_cast<CellExtra28*>(reinterpret_cast<char*>(this) + 0x28)->FUN_0041c7c0();
    if (!reinterpret_cast<TESObjectCELL*>(this)->IsInterior())
        return (char*)g_011ca130.GetMenuTitle();
    return reinterpret_cast<TESObjectCELL*>(this)->FUN_00451cb0();
}
}  // namespace fnv_00551740

struct FUN_005f0060_shell : public TESForm
{
    char* FUN_005f0060();
};

struct Flt
{
    operator unsigned int() const;
};
// Returns the value at offset 0x1c as a string pointer if nonzero, otherwise an empty string.
// @fnv 0x005f0060
char* FUN_005f0060_shell::FUN_005f0060()
{
    return (unsigned int)(*(Flt*)((char*)this + 0x1c)) ? (char*)(unsigned int)(*(Flt*)((char*)this + 0x1c)) : "";
}

namespace fnv_005fe0f0 {
struct NiFormArray;
struct PerkEntryConditionSet;
struct TESIdleForm;
struct TESModel;
struct TESModelTextureSwap;
struct TESObjectREFR;
struct FileEntryList;
struct FUN_005fe0f0_shell : public TESForm
{
    char* FUN_005fe0f0();
};

struct Flt
{
    operator unsigned int() const;
};
// @fnv 0x005fe0f0
char* FUN_005fe0f0_shell::FUN_005fe0f0()
{
    return (unsigned int)(*(Flt*)((char*)this + 0x4c)) ? (char*)(unsigned int)(*(Flt*)((char*)this + 0x4c)) : (char*)"";
}
}  // namespace fnv_005fe0f0

namespace fnv_00618660 {
struct Actor;
struct DialogueTopicData;
struct DialogueItem;
struct FormRecordHeader;
struct QuestDialogueInfo;
struct TESObjectREFR;
struct TESQuest;
struct TESTopicInfo;
struct TopicInfoArray;
struct TESFullName : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetFullNameLength(TESForm*);
    unsigned int GetFullNameLength();
    static char* GetFullName(TESForm*);
    char* GetFullName();
    void SetFullName(char*);
    static void LoadFullNameChunk(TESFullName*, TESFile*);
    void* GetFullNameString();
    void* __vecDelDtor(unsigned int);
    char m_kName[8];
};
typedef char _sizecheck_TESFullName[sizeof(TESFullName) == 12 ? 1 : -1];
struct TESTopic : public TESForm, public TESFullName
{
    virtual void __vslot_10();
    static void BadQuestInfo(QuestDialogueInfo*);
    virtual bool Save(TESFile*);
    virtual void Save();
    virtual bool ReadTopicData(TESFile*);
    virtual bool Load(TESFile*);
    virtual void InitItem();
    virtual void ResetFormData();
    virtual bool CopyTopicData(FormRecordHeader*);
    virtual bool CopyTopicData(TESForm*);
    DialogueTopicData* GetData();
    int GetDialogueType();
    float GetPriority();
    void SetPriority(float);
    bool IsRemappedRumors();
    void SetRemappedRumors(bool);
    bool IsTopLevel();
    void SetTopLevel(bool);
    int GetDummyNodeState();
    void SetDummyNodeState(int);
    bool IsPersuasion();
    bool IsNonMenuTopic();
    void* GetQuestInfoList();
    TopicInfoArray* GetInfoArray(TESQuest*);
    TESTopicInfo* GetInfoByID(TESQuest*, unsigned int, bool);
    TESTopicInfo* GetInfoByID(unsigned int, bool);
    static TESTopicInfo* GetInfoByIndex(QuestDialogueInfo*, unsigned int);
    TESTopicInfo* GetInfoByIndex(TESQuest*, unsigned int);
    TESQuest* GetParentQuest(TESTopicInfo*);
    QuestDialogueInfo* GetQuestInfoForInfo(TESTopicInfo*);
    void* GetDummyPrompt();
    void SetDummyPrompt(char*);
    bool HasDummyPrompt();
    void RemoveQuestInfo(TESQuest*);
    static void RemoveQuestFromAllTopics(TESQuest*);
    bool HasQuest(void*, bool);
    bool HasQuest(TESQuest*, bool);
    static void CompactTopicInfos(TopicInfoArray*);
    void CompactTopicInfos(TESQuest*);
    bool InsertInfoAfter(TESQuest*, TESTopicInfo*, unsigned int);
    QuestDialogueInfo* GetQuestInfoForQuest(TESQuest*, bool);
    bool AddInfoToEnd(TESQuest*, TESTopicInfo*);
    TESTopicInfo* CreateInfoAtIndex(TESQuest*, int);
    static void AddDefaultTopics();
    static void RemoveDefaultTopics();
    static TESTopic* GetAudioBackendData(int, int);
    static TESTopic* GetTopicFromInfo(TESTopicInfo*);
    static void AlterOwner(TESTopicInfo*);
    static void UpdateTopic(TESTopic*, void*, bool);
    static bool CompareTopics(TESTopic*, TESTopic*, bool);
    static void ReorderTopics(bool, void*);
    bool SortQuests();
    static bool IsQuestValidForTopics(TESQuest*);
    virtual bool IsParentForm();
    virtual bool IsFormType(unsigned char);
    static bool IsFormTypeDialogueChild(unsigned char);
    static unsigned int GetDialogueTopicFlags(TESObjectREFR*, TESObjectREFR*, void*, TESTopic*);
    DialogueItem* CreateDialogueItem(TESObjectREFR*, TESObjectREFR*, TESTopic*, void*, bool);
    static TESTopicInfo* FindMatchingTopicInfo(void*, bool*, TESObjectREFR*, TESObjectREFR*, bool, TESTopic*, void*);
    TESTopicInfo* FindMatchingTopicInfo(bool*, TESObjectREFR*, TESObjectREFR*, bool, TESTopic*, void*);
    TESTopicInfo* FindMatchingTopicInfo(bool*, TESObjectREFR*, TESObjectREFR*);
    TESTopicInfo* FindMatchingTopicInfo(TESObjectREFR*, TESObjectREFR*);
    static TESTopicInfo* FindFollowupTopicInfo(TESTopicInfo*, bool*, TESObjectREFR*, TESObjectREFR*, bool, void*);
    static void ResetAllTopics();
    void ResetTopics();
    int GetJournalIndex();
    void SetJournalIndex(int);
    bool AddJournalEntry(int, Actor*);
    static void SetShowConversationStats(bool);
    static bool GetShowConversationStats();
    char m_Data[2];
    char _pad_26[2];
    float m_fTopicParamB;
    char m_kQuestInfoList[8];
    char m_kDummyPrompt[8];
    int m_iTopicFlags;
};
typedef char _sizecheck_TESTopic[sizeof(TESTopic) == 64 ? 1 : -1];
struct FUN_00618660_shell : public TESForm
{
    char* FUN_00618660();
};

struct Flt
{
    operator unsigned int() const;
};
extern char $SG5889[];
// @fnv 0x00618660
char* FUN_00618660_shell::FUN_00618660()
{
    return ((Flt*)((char*)this + 0x40))->operator unsigned int()
               ? (char*)((Flt*)((char*)this + 0x40))->operator unsigned int()
               : $SG5889;
}
}  // namespace fnv_00618660

struct FUN_004fcbd0_shell
{
    char pad0x000_0x79a[0x79a];
    unsigned char m_0x79a;
    void SetByteAt79a(unsigned char value);
};

// @fnv 0x004fcbd0
void FUN_004fcbd0_shell::SetByteAt79a(unsigned char value)
{
    m_0x79a = value;
}

struct FUN_0067fb20_target
{
    void UpdateStoredValue();
};

struct FUN_006806e0_target
{
    void ResolveTargetForm();
};

struct FUN_006796c0_shell
{
    char padding_00_2c[0x2c];
    FUN_0067fb20_target* m_2c;
    FUN_006806e0_target* m_30;
    void FUN_006796c0();
};

// Calls UpdateStoredValue on m_2c and ResolveTargetForm on m_30 when each pointer is non-null.
// @fnv 0x006796c0
void FUN_006796c0_shell::FUN_006796c0()
{
    if (m_2c)
        m_2c->UpdateStoredValue();
    if (m_30)
        m_30->ResolveTargetForm();
}

extern const char $SG3295[];

struct DH
{
    bool FUN_004226e0();
};

DH* g_dataHandler;

struct BGSCameraPath
{
    int HasNameForWarning();
};

struct XActor
{
    void* GetExtra() const;
};

struct FUN_00401280_shell
{
    const char* FUN_00401280();
};

TESActorBase* __fastcall FUN_004216f0(ExtraDataList* extraDataList);

struct FUN_0055d480_name_object
{
    virtual void f000() = 0;
    virtual void f001() = 0;
    virtual void f002() = 0;
    virtual void f003() = 0;
    virtual void f004() = 0;
    virtual void f005() = 0;
    virtual void f006() = 0;
    virtual void f007() = 0;
    virtual void f008() = 0;
    virtual void f009() = 0;
    virtual void f010() = 0;
    virtual void f011() = 0;
    virtual void f012() = 0;
    virtual void f013() = 0;
    virtual void f014() = 0;
    virtual void f015() = 0;
    virtual void f016() = 0;
    virtual void f017() = 0;
    virtual void f018() = 0;
    virtual void f019() = 0;
    virtual void f020() = 0;
    virtual void f021() = 0;
    virtual void f022() = 0;
    virtual void f023() = 0;
    virtual void f024() = 0;
    virtual void f025() = 0;
    virtual void f026() = 0;
    virtual void f027() = 0;
    virtual void f028() = 0;
    virtual void f029() = 0;
    virtual void f030() = 0;
    virtual void f031() = 0;
    virtual void f032() = 0;
    virtual void f033() = 0;
    virtual void f034() = 0;
    virtual void f035() = 0;
    virtual void f036() = 0;
    virtual void f037() = 0;
    virtual void f038() = 0;
    virtual void f039() = 0;
    virtual void f040() = 0;
    virtual void f041() = 0;
    virtual void f042() = 0;
    virtual void f043() = 0;
    virtual void f044() = 0;
    virtual void f045() = 0;
    virtual void f046() = 0;
    virtual void f047() = 0;
    virtual void f048() = 0;
    virtual void f049() = 0;
    virtual void f050() = 0;
    virtual void f051() = 0;
    virtual void f052() = 0;
    virtual void f053() = 0;
    virtual void f054() = 0;
    virtual void f055() = 0;
    virtual void f056() = 0;
    virtual void f057() = 0;
    virtual void f058() = 0;
    virtual void f059() = 0;
    virtual void f060() = 0;
    virtual void f061() = 0;
    virtual void f062() = 0;
    virtual void f063() = 0;
    virtual void f064() = 0;
    virtual void f065() = 0;
    virtual void f066() = 0;
    virtual void f067() = 0;
    virtual void f068() = 0;
    virtual void f069() = 0;
    virtual void f070() = 0;
    virtual void f071() = 0;
    virtual void f072() = 0;
    virtual void f073() = 0;
    virtual void f074() = 0;
    virtual void f075() = 0;
    virtual const char* GetName() = 0;
};

struct FUN_0055d480_shell
{
    const char* FUN_0055d480();
};

// @fnv 0x0055d480
const char* FUN_0055d480_shell::FUN_0055d480()
{
    const char* name;

    if (((BGSCameraPath*)this)->HasNameForWarning())
        return ((FUN_00401280_shell*)this)->FUN_00401280();

    if (!*(FUN_0055d480_name_object**)((char*)this + 0x20) || g_dataHandler->FUN_004226e0())
        return $SG3295;

    name = ((FUN_0055d480_name_object*)*(FUN_0055d480_name_object**)((char*)this + 0x20))->GetName();

    if (!name || !*name)
    {
        TESActorBase* actor = FUN_004216f0((ExtraDataList*)((XActor*)this)->GetExtra());
        if (actor)
            name = ((FUN_0055d480_name_object*)actor)->GetName();
    }

    return name;
}

class FUN_00401130_cls
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08(int aiArg);
    void CallUnk08(int aiArg);
};

// @fnv 0x00401130
void FUN_00401130_cls::CallUnk08(int aiArg)
{
    Unk_08(aiArg);
}

class FUN_00401150_cls
{
  public:
    void FUN_00401170();
    void FUN_00401150();
};

// @fnv 0x00401150
void FUN_00401150_cls::FUN_00401150()
{
    this->FUN_00401170();
}

extern "C" void* __cdecl FUN_00ec43fb(unsigned int, int, const void*, const void*, int);
extern const char DAT_011841cc;
extern const char DAT_011846d4;
extern const char DAT_01189dbc;
struct LightQuery
{
    unsigned char __thiscall FUN_004fdf20();
    unsigned char __thiscall FUN_004fdf40();
};
struct ResolvedLight
{
    virtual void slot_00();
    virtual void slot_01();
    virtual void slot_02();
    virtual void slot_03();
    virtual void slot_04();
    virtual void slot_05();
    virtual void slot_06();
    virtual void slot_07();
    virtual void slot_08();
    virtual void slot_09();
    virtual void slot_0a();
    virtual void slot_0b();
    virtual void slot_0c();
    virtual void slot_0d();
    virtual void slot_0e();
    virtual void slot_0f();
    virtual void slot_10();
    virtual void slot_11();
    virtual void slot_12();
    virtual void slot_13();
    virtual void slot_14();
    virtual void slot_15();
    virtual void slot_16();
    virtual void slot_17();
    virtual void slot_18();
    virtual void slot_19();
    virtual void slot_1a();
    virtual void slot_1b();
    virtual void slot_1c();
    virtual void slot_1d();
    virtual void slot_1e();
    virtual void slot_1f();
    virtual void slot_20();
    virtual void slot_21();
    virtual void slot_22();
    virtual void slot_23();
    virtual void slot_24();
    virtual void slot_25();
    virtual void slot_26();
    virtual void slot_27();
    virtual void slot_28();
    virtual void slot_29();
    virtual void slot_2a();
    virtual void slot_2b();
    virtual void slot_2c();
    virtual void slot_2d();
    virtual void slot_2e();
    virtual void slot_2f();
    virtual void slot_30();
    virtual void slot_31();
    virtual void slot_32();
    virtual void slot_33();
    virtual void slot_34();
    virtual void slot_35();
    virtual void slot_36();
    virtual void slot_37();
    virtual void slot_38();
    virtual void slot_39();
    virtual void slot_3a();
    virtual void slot_3b();
    virtual void slot_3c();
    virtual void slot_3d();
    virtual void slot_3e();
    virtual void slot_3f();
    virtual void slot_40();
    virtual void slot_41();
    virtual void slot_42();
    virtual void slot_43();
    virtual void slot_44();
    virtual void slot_45();
    virtual void slot_46();
    virtual void slot_47();
    virtual void slot_48();
    virtual void slot_49();
    virtual void slot_4a();
    virtual void slot_4b();
    virtual void slot_4c();
    virtual void slot_4d();
    virtual void slot_4e();
    virtual void slot_4f();
    virtual void slot_50();
    virtual void slot_51();
    virtual void slot_52();
    virtual void slot_53();
    virtual void slot_54();
    virtual void slot_55();
    virtual void slot_56();
    virtual void slot_57();
    virtual void slot_58();
    virtual void slot_59();
    virtual void slot_5a();
    virtual void slot_5b();
    virtual void slot_5c();
    virtual void slot_5d();
    virtual void slot_5e();
    virtual void slot_5f();
    virtual void slot_60();
    virtual void slot_61();
    virtual void slot_62();
    virtual void slot_63();
    virtual void slot_64();
    virtual void slot_65();
    virtual void slot_66();
    virtual void slot_67();
    virtual void slot_68();
    virtual void slot_69();
    virtual void slot_6a();
    virtual void slot_6b();
    virtual void slot_6c();
    virtual void slot_6d();
    virtual void slot_6e();
    virtual void slot_6f();
    virtual void slot_70();
    virtual void slot_71();
    virtual void slot_72();
    virtual void slot_73();
    virtual void slot_74();
    virtual void slot_75();
    virtual void slot_76();
    virtual void slot_77();
    virtual void slot_78();
    virtual void slot_79();
    virtual void slot_7a();
    virtual void slot_7b();
    virtual void slot_7c();
    virtual void slot_7d();
    virtual void slot_7e();
    virtual void slot_7f();
    virtual void slot_80();
    virtual void slot_81();
    virtual void slot_82();
    virtual void slot_83();
    virtual void slot_84();
    virtual void slot_85();
    virtual void slot_86();
    virtual void slot_87();
    virtual void slot_88();
    virtual void slot_89();
    virtual void slot_8a();
    virtual void slot_8b();
    virtual void slot_8c();
    virtual void slot_8d();
    virtual void slot_8e();
    virtual void slot_8f();
    virtual void slot_90();
    virtual void slot_91();
    virtual void slot_92();
    virtual void slot_93();
    virtual void slot_94();
    virtual void slot_95();
    virtual void slot_96();
    virtual void slot_97();
    virtual void slot_98();
    virtual void slot_99();
    virtual void slot_9a();
    virtual void slot_9b();
    virtual void slot_9c();
    virtual void slot_9d();
    virtual void slot_9e();
    virtual void slot_9f();
    virtual void slot_a0();
    virtual void slot_a1();
    virtual void slot_a2();
    virtual void slot_a3();
    virtual void slot_a4();
    virtual void slot_a5();
    virtual void slot_a6();
    virtual void slot_a7();
    virtual void slot_a8();
    virtual void slot_a9();
    virtual void slot_aa();
    virtual void slot_ab();
    virtual void slot_ac();
    virtual void slot_ad();
    virtual void slot_ae();
    virtual void slot_af();
    virtual void slot_b0();
    virtual void slot_b1();
    virtual void slot_b2();
    virtual void slot_b3();
    virtual void slot_b4();
    virtual void slot_b5();
    virtual void slot_b6();
    virtual void slot_b7();
    virtual void slot_b8();
    virtual void slot_b9();
    virtual void slot_ba();
    virtual void slot_bb();
    virtual void slot_bc();
    virtual void slot_bd();
    virtual void slot_be();
    virtual void slot_bf();
    virtual void slot_c0();
    virtual void slot_c1();
    virtual void slot_c2();
    virtual void slot_c3();
    virtual void slot_c4();
    virtual void slot_c5();
    virtual void slot_c6();
    virtual void slot_c7();
    virtual unsigned char CanActOn(void*, unsigned int);
    LightQuery* FUN_004181e0();
    unsigned char FUN_00444d00(unsigned int);
};
struct LightController : TESObjectLIGH
{
    unsigned char __thiscall FUN_004fde40(unsigned int first, unsigned int second, bool allow, unsigned int param4,
                                          unsigned int param5);
};
// @fnv 0x004fde40
unsigned char LightController::FUN_004fde40(unsigned int first, unsigned int second, bool allow, unsigned int param4,
                                            unsigned int param5)
{
    void* lightSource = FUN_00ec43fb(second, 0, &DAT_011841cc, &DAT_011846d4, 0);
    ResolvedLight* linkedLight = static_cast<ResolvedLight*>(FUN_00ec43fb(first, 0, &DAT_011841cc, &DAT_01189dbc, 0));
    if (lightSource && linkedLight)
    {
        if (linkedLight->FUN_004181e0()->FUN_004fdf20() && !linkedLight->FUN_00444d00(0x200) &&
            linkedLight->CanActOn(lightSource, 0))
            return 1;
        if (linkedLight->FUN_004181e0()->FUN_004fdf40())
            return InvokeAction(first, second, allow, param4, param5);
    }
    return 0;
}

struct FormTypeAccess : public TESForm
{
    int GetFormTypeID();
};

class TESFaction : public TESForm
{
  public:
    bool IsHiddenFlagSet();
};

class TESNPC : public TESForm
{
  public:
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
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    ActorValueOwner avOwner;
};

struct RefrAccess : public TESObjectREFR
{
    TESForm* GetOwner();
    bool CanBeUsed(Actor* apActor, bool abCheck);
    void Disable();
};

struct PlayerCharacter : public Actor
{
    void ModifyKarmaForTheft(int aiAmount);
    void ModifyKarmaForStolenItem(TESForm* apObject, int aiCount);
};

extern PlayerCharacter* _g_thePlayer;

class GameSettingCollection;
template <class T> class SettingT
{
  public:
    float* Float();
};
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting282;

unsigned int GetKarmaLevelFor(float afKarma);

class TESActivatableItem : public TESForm
{
  public:
    bool FUN_005e9360(RefrAccess* apRef, TESObjectREFR* apActivator, bool abUnk, TESForm* apUnk, int aiCount);
};

// @fnv 0x005e9360
bool TESActivatableItem::FUN_005e9360(RefrAccess* apRef, TESObjectREFR* apActivator, bool abUnk, TESForm* apUnk,
                                      int aiCount)
{
    Actor* pActor = dynamic_cast<Actor*>(apActivator);
    bool bResult = false;
    bool bStolen = false;
    if (apActivator == _g_thePlayer)
    {
        TESForm* pOwner = apRef->GetOwner();
        if (pOwner && !apRef->CanBeUsed(_g_thePlayer, true))
        {
            if (((FormTypeAccess*)pOwner)->GetFormTypeID() == 8)
            {
                TESFaction* pFaction = (TESFaction*)pOwner;
                if (!pFaction->IsHiddenFlagSet())
                    bStolen = true;
            }
            else
            {
                TESNPC* pNPC = (TESNPC*)pOwner;
                if (pNPC)
                {
                    unsigned int uiKarmaLevel = GetKarmaLevelFor(pNPC->avOwner.GetCurrentActorValue(0x17));
                    if (uiKarmaLevel != 2 && uiKarmaLevel != 4)
                        bStolen = true;
                }
            }
        }
        if (bStolen)
            _g_thePlayer->ModifyKarmaForTheft((int)*originalRuntimeFloatSetting282.Float());
        _g_thePlayer->ModifyKarmaForStolenItem(this, 1);
        apRef->Disable();
        return true;
    }
    return false;
}

struct ActivationRef;
struct ActivationPosition
{
    float x;
    float y;
    float z;
};
struct ActivationAction
{
    void FUN_00496080(float);
};
struct ActivationProcess
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
    virtual bool CanActivate(ActivationRef*, int, int, int, int, int);
};
struct ActivationRef
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
    virtual bool IsActor();
    virtual void Slot65();
    virtual void Slot66();
    virtual void Slot67();
    virtual void Slot68();
    virtual void Slot69();
    virtual void Slot70();
    virtual void Slot71();
    virtual void Slot72();
    virtual bool Activate(ActivationRef*, ActivationRef*, bool, int, int);
    virtual void Slot74();
    virtual void Slot75();
    virtual void Slot76();
    virtual void Slot77();
    virtual void Slot78();
    virtual void Slot79();
    virtual ActivationRef* GetActivationForm();
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
    virtual const ActivationPosition& Position();
    virtual void Slot126();
    virtual void Slot127();
    virtual void Slot128();
    virtual void Slot129();
    virtual void Slot130();
    virtual void Slot131();
    virtual void Slot132();
    virtual void Slot133();
    virtual bool IsForced();
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
    virtual float GroundOffset();
    float FUN_008be940();
    ActivationProcess* FUN_008d8520();
    void SetByteAt79a(bool);
    ActivationAction* FUN_00950a60(int, int);
    bool ActivateWithActorCheck(ActivationRef*, ActivationRef*, bool, int, int);
};
extern ActivationRef* DAT_011dea3c;
extern ActivationRef* DAT_011e0788;
void FUN_00600900(ActivationRef*);
void FUN_00600940(int);
void FUN_00600920(int);
// Gets the activation form, runs an actor activation check with height/mode setup, and if allowed calls Activate on the form.
// @fnv 0x004fc9e0
bool ActivationRef::ActivateWithActorCheck(ActivationRef* source, ActivationRef* target, bool allow, int aiArgA,
                                           int aiArgB)
{
    ActivationRef* form_ = GetActivationForm();
    if (!form_)
        return false;
    if (target && target->IsActor())
    {
        ActivationRef* actor = target;
        FUN_00600900(this);
        FUN_00600940(1);
        float height2 = actor->FUN_008be940() + actor->Position().z - actor->GroundOffset();
        float sourceHeight = source->Position().z;
        int mode = 0;
        if (!source->IsForced())
        {
            if (sourceHeight > height2)
                mode = 1;
        }
        else
        {
            mode = 1;
        }
        FUN_00600920(mode);
        bool permitted6 = actor->FUN_008d8520()->CanActivate(actor, 0, 3, 1, 0, 1);
        FUN_00600900(0);
        FUN_00600940(0);
        FUN_00600920(-1);
        if (!permitted6)
            return false;
        if (target == DAT_011dea3c && permitted6)
        {
            DAT_011e0788 = form_;
            DAT_011dea3c->SetByteAt79a(true);
            DAT_011dea3c->FUN_00950a60(1, 1)->FUN_00496080(0.0f);
            DAT_011dea3c->FUN_00950a60(0, 1)->FUN_00496080(0.0f);
        }
    }
    return form_->Activate(source, target, allow, aiArgA, aiArgB);
}

struct ContainerLike;
struct PackageLike
{
    int GetPackType();
};
int __fastcall FUN_009ee040(PackageLike* apPackage);

struct ExtraHolder
{
    int unk00;
    int unk04;
    int unk08;
    struct ActorLike* unk0C;
};

struct ExtraListLike
{
    ExtraHolder* GetHolder();
    void Attach(void* apOwner, struct RefLike* apRef);
};

struct RefLike
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void SetFlag(unsigned int auiFlag);
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
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
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual bool IsActor();
    virtual bool IsBaseForm();
    ExtraListLike* GetExtraList();
    RefLike* GetBaseForm();
};

struct ActorLike : RefLike
{
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
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
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
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
    virtual void v6a();
    virtual void v6b();
    virtual void v6c();
    virtual void v6d();
    virtual void v6e();
    virtual void v6f();
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
    virtual void v7a();
    virtual void v7b();
    virtual void v7c();
    virtual void v7d();
    virtual void v7e();
    virtual void v7f();
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
    virtual void v8a();
    virtual void v8b();
    virtual void v8c();
    virtual void v8d();
    virtual void v8e();
    virtual void v8f();
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
    virtual void v9a();
    virtual void v9b();
    virtual void v9c();
    virtual void v9d();
    virtual void v9e();
    virtual void v9f();
    virtual void StartConversation(RefLike* apTarget, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9);
    PackageLike* GetCurrentPackage();
};

struct GameSettingLike
{
    const char* String();
};
extern GameSettingLike g_011d4810;
extern float DAT_010162c0;

struct VATSLike
{
    void Reset(bool a1, bool a2);
};
extern VATSLike DAT_011f2250;

bool QueueUIMessage(const char* apText, int aiIcon, const char* apSound, const char* apUnk, float afTime, bool abUnk);
void FUN_00709470(int a1, int a2, int a3, int a4, int a5, int a6);

struct DialogueStarter
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
    bool FUN_004feeb0(RefLike* apRef, RefLike* apTarget, int a3, int a4, int a5);
};

// Checks the player extra holder, resolves the actor and base form, then starts a conversation or resets VATS and calls FUN_00709470 for the player.
// @fnv 0x004feeb0
bool DialogueStarter::FUN_004feeb0(RefLike* apRef, RefLike* apTarget, int aiUnused1, int aiUnused2, int aiUnused3)
{
    if ((void*)apTarget == (void*)_g_thePlayer)
    {
        ExtraHolder* kPHolder = apRef->GetExtraList()->GetHolder();
        if (kPHolder && kPHolder->unk0C)
        {
            QueueUIMessage(g_011d4810.String(), 0, 0, 0, DAT_010162c0, 0);
            return false;
        }
    }
    ActorLike* pSpeakerActor = 0;
    if (apRef->IsActor())
    {
        pSpeakerActor = (ActorLike*)apRef;
    }
    else
    {
        apRef->GetExtraList()->Attach(this, apRef);
        apRef->SetFlag(0x80000000);
        ExtraHolder* pNewHolder = apRef->GetExtraList()->GetHolder();
        pSpeakerActor = pNewHolder->unk0C;
    }
    RefLike* pTargetForm = 0;
    if (!apTarget->IsBaseForm())
    {
        pTargetForm = apTarget->GetBaseForm();
    }
    else
    {
        pTargetForm = apTarget;
    }
    if (pSpeakerActor)
    {
        if ((void*)apTarget == (void*)_g_thePlayer)
        {
            DAT_011f2250.Reset(0, 0);
            FUN_00709470(4, (int)pSpeakerActor, 0, unk90, 1, 0);
        }
        else
        {
            PackageLike* pCurrentPackage = 0;
            if (pSpeakerActor->GetCurrentPackage() && pSpeakerActor->GetCurrentPackage()->GetPackType() == 0x1c)
            {
                pCurrentPackage = pSpeakerActor->GetCurrentPackage();
            }
            if (pCurrentPackage && FUN_009ee040(pCurrentPackage) == (int)pTargetForm)
            {
                return true;
            }
            else
            {
                pSpeakerActor->StartConversation(pTargetForm, 0, 0, 1, 0, 0, 0, 0, 0);
            }
        }
    }
    return true;
}

namespace fnv_00508a40 {
class Script
{
  public:
    ScriptLocals* CreateEventList();
    bool Execute(TESObjectREFR*, ScriptLocals*, TESObjectREFR*, bool);
};
struct ExtraDataList
{
    int head;
    int tail;
    int flags;
    int presence;
    int data10;
    int data14;
    int data18;
    int data1c;
    ExtraDataList();
    void FUN_00419ad0(unsigned short);
    Script* FUN_00418800();
    void FUN_00419ed0(Script*);
    void FUN_00419f80(ScriptLocals*);
    ScriptLocals* FUN_00418830();
};
struct FUN_0055a2f0 : TESObjectREFR
{
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
    FUN_0055a2f0();
};
struct NameComponent
{
    const char* FUN_00408da0();
};
struct Topic : TESForm
{
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    NameComponent name;
};
struct TopicInfo
{
    bool FUN_00508d70();
    void FUN_00484580(bool);
};
struct Script* FUN_004826d0(Topic*);
unsigned int DialogueRandom();
struct CalendarView
{
    int FUN_00867ca0();
};
extern "C" CalendarView DAT_011de7b8;
struct SettingView
{
    const char* FUN_00403df0();
};
extern "C" SettingView DAT_011c856c;
extern "C" SettingView DAT_011c8590;
extern "C" Actor* DAT_011dea3c;
struct ActorActions : Actor
{
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot0a();
    virtual void slot0b();
    virtual void slot0c();
    virtual void slot0d();
    virtual void slot0e();
    virtual void slot0f();
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
    virtual void slot1a();
    virtual void slot1b();
    virtual void slot1c();
    virtual void slot1d();
    virtual void slot1e();
    virtual void slot1f();
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
    virtual void slot2a();
    virtual void slot2b();
    virtual void slot2c();
    virtual void slot2d();
    virtual void slot2e();
    virtual void slot2f();
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
    virtual void slot3a();
    virtual void slot3b();
    virtual void slot3c();
    virtual void slot3d();
    virtual void slot3e();
    virtual void slot3f();
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
    virtual void slot4a();
    virtual void slot4b();
    virtual void slot4c();
    virtual void slot4d();
    virtual void slot4e();
    virtual void slot4f();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot5a();
    virtual void slot5b();
    virtual void slot5c();
    virtual void slot5d();
    virtual void slot5e();
    virtual void slot5f();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void AddTopic(Topic*, ExtraDataList*, bool);
    void FUN_00574fa0(Topic*, int, bool);
};
struct GlobalObject_0041a250
{
    unsigned int id;
    unsigned int state;
    unsigned int message;
    GlobalObject_0041a250();
    ~GlobalObject_0041a250();
    void FUN_00418900(const GlobalObject_0041a250&);
    bool Play(bool);
};
struct BSAudio
{
    static BSAudio* FUN_00453a70();
    GlobalObject_0041a250 FUN_00ad7550(const char*, unsigned int);
};
int FUN_00406f60(BSStringT<char>*, const char*, ...);
bool QueueUIMessage(const char*, int, const char*, const char*, float, bool);
void FUN_00706f30(int);
struct Action
{
    int state;
    bool TryAddTopic(TopicInfo*, TESObjectREFR*, int, int, int);
};
struct Prefix
{
    int unk00;
    int unk04;
    int unk08;
};
struct TopicAction : Prefix
{
    Action action;
    Topic* FUN_00726070();
    unsigned char FUN_00508d90(int);
};
// Checks the TopicInfo and actor, rolls a dialogue chance, adds the topic to the actor and queues a message when the actor is the player.
// @fnv 0x00508a40
bool Action::TryAddTopic(TopicInfo* pTopicInfo, TESObjectREFR* reference, int arg3, int arg4, int arg5)
{
    Actor* actor = dynamic_cast<Actor*>(reference);
    if (pTopicInfo && actor)
    {
        bool success = false;
        if (!pTopicInfo->FUN_00508d70() &&
            reinterpret_cast<TopicAction*>(reinterpret_cast<char*>(this) - offsetof(TopicAction, action))
                ->FUN_00726070())
        {
            unsigned char chance =
                reinterpret_cast<TopicAction*>(reinterpret_cast<char*>(this) - offsetof(TopicAction, action))
                    ->FUN_00508d90(DAT_011de7b8.FUN_00867ca0());
            if (chance > 0 && DialogueRandom() % 100 < chance)
                success = true;
        }
        if (success)
        {
            Topic* script =
                reinterpret_cast<TopicAction*>(reinterpret_cast<char*>(this) - offsetof(TopicAction, action))
                    ->FUN_00726070();
            Script* pScript = FUN_004826d0(script);
            if (pScript)
            {
                ExtraDataList* extra = 0;
                extra = new ExtraDataList;
                extra->FUN_00419ad0(1);
                if (extra && !extra->FUN_00418800())
                {
                    extra->FUN_00419ed0(pScript);
                    extra->FUN_00419f80(extra->FUN_00418800()->CreateEventList());
                    TESObjectREFR* temporary = new FUN_0055a2f0;
                    pScript->Execute(temporary, extra->FUN_00418830(), 0, false);
                }
                reinterpret_cast<ActorActions*>(actor)->AddTopic(script, extra, true);
            }
            else
            {
                reinterpret_cast<ActorActions*>(actor)->FUN_00574fa0(script, 0, true);
            }
            if (actor == DAT_011dea3c)
            {
                BSStringT<char> sound;
                FUN_00406f60(&sound, DAT_011c856c.FUN_00403df0(), script->name.FUN_00408da0());
                QueueUIMessage(sound.String(), 0, 0, 0, 2.0f, false);
                GlobalObject_0041a250 message;
                message.FUN_00418900(BSAudio::FUN_00453a70()->FUN_00ad7550("ITMPickupOrganic", 0x120));
                message.Play(false);
            }
        }
        else if (actor == DAT_011dea3c)
        {
            QueueUIMessage(DAT_011c8590.FUN_00403df0(), 0, 0, 0, 2.0f, false);
            FUN_00706f30(29);
        }
        pTopicInfo->FUN_00484580(true);
    }
    return true;
}
}  // namespace fnv_00508a40

struct ActionData
{
    unsigned int flags;
    unsigned int value;
    unsigned int object;
    unsigned short count;
    unsigned char type;
    void* FUN_00509890(unsigned char);
    unsigned int FUN_005094b0();
};
bool FUN_005094f0(unsigned int);
struct ActorState
{
    bool FUN_00822e00();
};
struct ActionCell
{
    bool FUN_005444c0();
};
struct ActionActor
{
    virtual void actionSlot000();
    virtual void actionSlot001();
    virtual void actionSlot002();
    virtual void actionSlot003();
    virtual void actionSlot004();
    virtual void actionSlot005();
    virtual void actionSlot006();
    virtual void actionSlot007();
    virtual void actionSlot008();
    virtual void actionSlot009();
    virtual void actionSlot00a();
    virtual void actionSlot00b();
    virtual void actionSlot00c();
    virtual void actionSlot00d();
    virtual void actionSlot00e();
    virtual void actionSlot00f();
    virtual void actionSlot010();
    virtual void actionSlot011();
    virtual void actionSlot012();
    virtual void actionSlot013();
    virtual void actionSlot014();
    virtual void actionSlot015();
    virtual void actionSlot016();
    virtual void actionSlot017();
    virtual void actionSlot018();
    virtual void actionSlot019();
    virtual void actionSlot01a();
    virtual void actionSlot01b();
    virtual void actionSlot01c();
    virtual void actionSlot01d();
    virtual void actionSlot01e();
    virtual void actionSlot01f();
    virtual void actionSlot020();
    virtual void actionSlot021();
    virtual void actionSlot022();
    virtual void actionSlot023();
    virtual void actionSlot024();
    virtual void actionSlot025();
    virtual void actionSlot026();
    virtual void actionSlot027();
    virtual void actionSlot028();
    virtual void actionSlot029();
    virtual void actionSlot02a();
    virtual void actionSlot02b();
    virtual void actionSlot02c();
    virtual void actionSlot02d();
    virtual void actionSlot02e();
    virtual void actionSlot02f();
    virtual void actionSlot030();
    virtual void actionSlot031();
    virtual void actionSlot032();
    virtual void actionSlot033();
    virtual void actionSlot034();
    virtual void actionSlot035();
    virtual void actionSlot036();
    virtual void actionSlot037();
    virtual void actionSlot038();
    virtual void actionSlot039();
    virtual void actionSlot03a();
    virtual void actionSlot03b();
    virtual void actionSlot03c();
    virtual void actionSlot03d();
    virtual void actionSlot03e();
    virtual void actionSlot03f();
    virtual void actionSlot040();
    virtual void actionSlot041();
    virtual void actionSlot042();
    virtual void actionSlot043();
    virtual void actionSlot044();
    virtual void actionSlot045();
    virtual void actionSlot046();
    virtual void actionSlot047();
    virtual void actionSlot048();
    virtual void actionSlot049();
    virtual void actionSlot04a();
    virtual void actionSlot04b();
    virtual void actionSlot04c();
    virtual void actionSlot04d();
    virtual void actionSlot04e();
    virtual void actionSlot04f();
    virtual void actionSlot050();
    virtual void actionSlot051();
    virtual void actionSlot052();
    virtual void actionSlot053();
    virtual void actionSlot054();
    virtual void actionSlot055();
    virtual void actionSlot056();
    virtual void actionSlot057();
    virtual void actionSlot058();
    virtual void actionSlot059();
    virtual void actionSlot05a();
    virtual void actionSlot05b();
    virtual void actionSlot05c();
    virtual void actionSlot05d();
    virtual void actionSlot05e();
    virtual void actionSlot05f();
    virtual void actionSlot060();
    virtual void actionSlot061();
    virtual void actionSlot062();
    virtual void actionSlot063();
    virtual void actionSlot064();
    virtual void actionSlot065();
    virtual void actionSlot066();
    virtual void actionSlot067();
    virtual void actionSlot068();
    virtual void actionSlot069();
    virtual void actionSlot06a();
    virtual void actionSlot06b();
    virtual void actionSlot06c();
    virtual void actionSlot06d();
    virtual void actionSlot06e();
    virtual void actionSlot06f();
    virtual void actionSlot070();
    virtual void actionSlot071();
    virtual void actionSlot072();
    virtual void actionSlot073();
    virtual void actionSlot074();
    virtual void actionSlot075();
    virtual void actionSlot076();
    virtual void actionSlot077();
    virtual void actionSlot078();
    virtual void actionSlot079();
    virtual void actionSlot07a();
    virtual void actionSlot07b();
    virtual void actionSlot07c();
    virtual unsigned int GetActionEntry();
    virtual void actionSlot07e();
    virtual void actionSlot07f();
    virtual void actionSlot080();
    virtual void actionSlot081();
    virtual void actionSlot082();
    virtual void actionSlot083();
    virtual void actionSlot084();
    virtual int GetActionState();
    virtual void actionSlot086();
    virtual void actionSlot087();
    virtual void actionSlot088();
    virtual void actionSlot089();
    virtual void actionSlot08a();
    virtual void actionSlot08b();
    virtual void actionSlot08c();
    virtual void actionSlot08d();
    virtual void actionSlot08e();
    virtual void actionSlot08f();
    virtual void actionSlot090();
    virtual void actionSlot091();
    virtual void actionSlot092();
    virtual void actionSlot093();
    virtual void actionSlot094();
    virtual void actionSlot095();
    virtual void actionSlot096();
    virtual void actionSlot097();
    virtual void actionSlot098();
    virtual void actionSlot099();
    virtual void actionSlot09a();
    virtual void actionSlot09b();
    virtual void actionSlot09c();
    virtual void actionSlot09d();
    virtual void actionSlot09e();
    virtual void actionSlot09f();
    virtual void actionSlot0a0();
    virtual void actionSlot0a1();
    virtual void actionSlot0a2();
    virtual void actionSlot0a3();
    virtual void actionSlot0a4();
    virtual void actionSlot0a5();
    virtual void actionSlot0a6();
    virtual void actionSlot0a7();
    virtual void actionSlot0a8();
    virtual void actionSlot0a9();
    virtual void actionSlot0aa();
    virtual void actionSlot0ab();
    virtual void actionSlot0ac();
    virtual void actionSlot0ad();
    virtual void actionSlot0ae();
    virtual void actionSlot0af();
    virtual void actionSlot0b0();
    virtual void actionSlot0b1();
    virtual void actionSlot0b2();
    virtual void actionSlot0b3();
    virtual void actionSlot0b4();
    virtual void actionSlot0b5();
    virtual void actionSlot0b6();
    virtual void actionSlot0b7();
    virtual void actionSlot0b8();
    virtual void actionSlot0b9();
    virtual void actionSlot0ba();
    virtual void actionSlot0bb();
    virtual void actionSlot0bc();
    virtual void actionSlot0bd();
    virtual void actionSlot0be();
    virtual void actionSlot0bf();
    virtual void actionSlot0c0();
    virtual void actionSlot0c1();
    virtual void actionSlot0c2();
    virtual void actionSlot0c3();
    virtual void actionSlot0c4();
    virtual void actionSlot0c5();
    virtual void actionSlot0c6();
    virtual void actionSlot0c7();
    virtual void actionSlot0c8();
    virtual void actionSlot0c9();
    virtual void actionSlot0ca();
    virtual void actionSlot0cb();
    virtual void actionSlot0cc();
    virtual void actionSlot0cd();
    virtual void actionSlot0ce();
    virtual void actionSlot0cf();
    virtual void actionSlot0d0();
    virtual void actionSlot0d1();
    virtual void actionSlot0d2();
    virtual void actionSlot0d3();
    virtual void actionSlot0d4();
    virtual void actionSlot0d5();
    virtual void actionSlot0d6();
    virtual void actionSlot0d7();
    virtual void actionSlot0d8();
    virtual void actionSlot0d9();
    virtual void actionSlot0da();
    virtual void actionSlot0db();
    virtual void actionSlot0dc();
    virtual void actionSlot0dd();
    virtual void actionSlot0de();
    virtual void actionSlot0df();
    virtual void actionSlot0e0();
    virtual void actionSlot0e1();
    virtual void actionSlot0e2();
    virtual void actionSlot0e3();
    virtual void actionSlot0e4();
    virtual void actionSlot0e5();
    virtual void actionSlot0e6();
    virtual void actionSlot0e7();
    virtual void actionSlot0e8();
    virtual void actionSlot0e9();
    virtual void actionSlot0ea();
    virtual void actionSlot0eb();
    virtual void actionSlot0ec();
    virtual void actionSlot0ed();
    virtual void actionSlot0ee();
    virtual void actionSlot0ef();
    virtual void actionSlot0f0();
    virtual void actionSlot0f1();
    virtual void actionSlot0f2();
    virtual void actionSlot0f3();
    virtual void actionSlot0f4();
    virtual void actionSlot0f5();
    virtual void actionSlot0f6();
    virtual void actionSlot0f7();
    virtual void actionSlot0f8();
    virtual void actionSlot0f9();
    virtual void actionSlot0fa();
    virtual void actionSlot0fb();
    virtual void actionSlot0fc();
    virtual void actionSlot0fd();
    virtual void actionSlot0fe();
    virtual void actionSlot0ff();
    virtual void actionSlot100();
    virtual void actionSlot101();
    virtual void actionSlot102();
    virtual void actionSlot103();
    virtual void actionSlot104();
    virtual void actionSlot105();
    virtual void FinishAction();
    virtual void actionSlot107();
    virtual void actionSlot108();
    virtual void actionSlot109();
    virtual void actionSlot10a();
    virtual void actionSlot10b();
    virtual void actionSlot10c();
    virtual void actionSlot10d();
    virtual void actionSlot10e();
    virtual void actionSlot10f();
    virtual void actionSlot110();
    virtual void actionSlot111();
    virtual bool IsActionBlocked();
    unsigned int unknown04;
    unsigned int unknown08;
    unsigned int unknown0c;
    unsigned int unknown10;
    unsigned int unknown14;
    unsigned int unknown18;
    unsigned int unknown1c;
    unsigned int unknown20;
    unsigned int unknown24;
    unsigned int unknown28;
    unsigned int unknown2c;
    unsigned int unknown30;
    unsigned int unknown34;
    unsigned int unknown38;
    unsigned int unknown3c;
    unsigned int unknown40;
    unsigned int unknown44;
    unsigned int unknown48;
    unsigned int unknown4c;
    unsigned int unknown50;
    unsigned int unknown54;
    unsigned int unknown58;
    unsigned int unknown5c;
    unsigned int unknown60;
    unsigned int unknown64;
    unsigned int unknown68;
    unsigned int unknown6c;
    unsigned int unknown70;
    unsigned int unknown74;
    unsigned int unknown78;
    unsigned int unknown7c;
    unsigned int unknown80;
    unsigned int unknown84;
    unsigned int unknown88;
    unsigned int unknown8c;
    unsigned int unknown90;
    ActorState state;
    ActionCell* FUN_008d6f30();
    bool FUN_00575d10();
    void FUN_00950340(int);
    void FUN_005098c0();
    void GoToLocation(RefrAccess*);
};
struct ActionReference : RefrAccess
{
    bool FUN_005686b0(unsigned int, int, int, ActionData*, unsigned int*, int);
};
struct ActionManager
{
    bool HasNearbyDetectedActor(int);
    bool IsFlagged();
};
extern ActionManager DAT_011e0e80;
struct GlobalObject_0040c150
{
    const char* FUN_00403df0();
};
extern GlobalObject_0040c150 g_011d2898, g_011d20ac, g_011d421c, g_011d384c, g_011d252c, g_011d1e0c;
extern const char g_011cba18_arg1[];
extern const char DAT_0118a23c;
bool QueueUIMessage(const char*, int, const char*, const char*, float, bool);
void FUN_007054f0(int);
struct ActionHandler
{
    bool FUN_005095b0(ActionReference*, ActionActor*, bool, unsigned int, unsigned int);
};
// @fnv 0x005095b0
bool ActionHandler::FUN_005095b0(ActionReference* reference, ActionActor* activator, bool allow, unsigned int arg4,
                                 unsigned int arg5)
{
    ActionActor* actor =
        static_cast<ActionActor*>(FUN_00ec43fb((unsigned int)activator, 0, &DAT_011841cc, &DAT_0118a23c, 0));
    if (!actor)
        return false;
    if (!actor->GetActionState())
    {
        unsigned int result = 0;
        ActionData data;
        data.FUN_00509890(255);
        if (!reference->FUN_005686b0((unsigned int)activator->GetActionEntry(), 1, 1, &data, &result, 1))
            return false;
        if (FUN_005094f0(data.FUN_005094b0()))
        {
            bool handled = false;
            if (reference->GetOwner() && !reference->CanBeUsed((Actor*)actor, true))
            {
                if (actor == (ActionActor*)_g_thePlayer)
                {
                    QueueUIMessage(g_011d2898.FUN_00403df0(), 0, g_011cba18_arg1, 0, 2.0f, false);
                    return false;
                }
            }
            else if (actor == (ActionActor*)_g_thePlayer &&
                     ((ActionActor*)_g_thePlayer)->FUN_008d6f30()->FUN_005444c0())
            {
                QueueUIMessage(g_011d20ac.FUN_00403df0(), 0, g_011cba18_arg1, 0, 2.0f, false);
                return false;
            }
            else if (((ActionActor*)_g_thePlayer)->IsActionBlocked())
            {
                QueueUIMessage(g_011d421c.FUN_00403df0(), 0, g_011cba18_arg1, 0, 2.0f, false);
            }
            else if (DAT_011e0e80.HasNearbyDetectedActor(((ActionActor*)_g_thePlayer)->FUN_00575d10()))
            {
                QueueUIMessage(g_011d384c.FUN_00403df0(), 0, g_011cba18_arg1, 0, 2.0f, false);
            }
            else if (DAT_011e0e80.IsFlagged())
            {
                QueueUIMessage(g_011d252c.FUN_00403df0(), 0, g_011cba18_arg1, 0, 2.0f, false);
            }
            else if (((ActionActor*)_g_thePlayer)->state.FUN_00822e00())
            {
                QueueUIMessage(g_011d1e0c.FUN_00403df0(), 0, g_011cba18_arg1, 0, 2.0f, false);
            }
            else
            {
                FUN_007054f0(1);
            }
        }
        else
        {
            actor->FUN_00950340(1);
            actor->FUN_005098c0();
            actor->GoToLocation(reference);
        }
    }
    else
    {
        actor->FUN_00950340(1);
        actor->FUN_005098c0();
        actor->FinishAction();
    }
    return true;
}

namespace fnv_00516dc0 {
struct ActivateActor;
struct ActivateReference;
struct LockScript
{
    int FUN_004309e0(ActivateReference*);
    bool FUN_00430ae0();
};
struct ActivateExtra
{
    int unk00, unk04, unk08;
    LockScript* script;
    void FUN_00517360();
};
struct KeyName
{
    const char* FUN_00408da0();
};
struct ActivateKey
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

    KeyName name;
};
struct ActivateLock
{
    int unk00;
    ActivateKey* key;
    bool FUN_005021a0();
};
struct ActivateAnimation
{
    void FUN_00498910(int, int);
};
struct ActivatePoint
{
    float x, y, z;
};
struct ActivateReference
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
    virtual void slot56();
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
    virtual void slot76();
    virtual void slot77();
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
    virtual void Activate(int, int, int, int, int, ActivateActor*, int, int, int, int);
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
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
    virtual void* GetScene();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual ActivatePoint* GetPosition();
    bool FUN_005785e0(ActivateActor*, bool);
    ActivateLock* FUN_00569160();
    ActivateExtra* FUN_005691f0();
    void FUN_005789b0();
    void Activate(ActivateActor*, int, int, int);
    void* FUN_00567790();
};
struct ActivateActorAction
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
    virtual void Action(ActivateActor*, int, int, int, int, int);
};
struct ActivateActor
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
    virtual void slot56();
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
    virtual void slot76();
    virtual void slot77();
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
    virtual void slot99();
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
    virtual ActivateAnimation* GetAnimation();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual void slot125();
    virtual void slot126();
    virtual void slot127();
    virtual void slot128();
    virtual void slot129();
    virtual void slot130();
    virtual void slot131();
    virtual void slot132();
    virtual void slot133();
    virtual bool IsActor();
    bool FUN_00891db0(ActivateKey*, int, int, int, int*);
    ActivateActorAction* FUN_008d8520();
    void FUN_008bfa40(ActivateReference*, int, int, int, int);
};
struct ActivateSound
{
    unsigned int FUN_0084e3a0();
};
struct ActivateComponent
{
    virtual void Activate(ActivateReference*, ActivateActor*);
};
struct ActivateObject
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

    ActivateComponent activation;
    ActivateSound* FUN_008ce390();
    bool FUN_00516dc0(ActivateReference*, TESObjectREFR*, int, int, int);
};
struct BSSoundHandleEx
{
    int unk00, unk04, unk08;
    ~BSSoundHandleEx();
    bool Play(bool);
    bool SetPos(float, float, float);
};
struct BSAudio
{
    BSSoundHandleEx GetSoundHandleByEditorID(const char*, unsigned int);
    BSSoundHandleEx FUN_00ad73b0(unsigned int, unsigned int);
};
BSAudio* FUN_00453a70();
struct ActivateMessage
{
    const char* FUN_00403df0();
};
extern ActivateMessage DAT_011d5110, DAT_011d276c;
extern ActivateActor* DAT_011dea3c;
extern ActivateReference* DAT_011c92d0;
extern ActivateKey* DAT_011ca268;
extern char DAT_0102b13c[], DAT_0102b108[], DAT_0102b0d0[];
extern float DAT_010162c0;
int FUN_00406d00(char*, unsigned int, const char*, ...);
void DispatchMessageToSink(const char*, int, const char*, int, float, int);
void FUN_005e58f0(int, ActivateActor*, float*);
void FUN_00705830(ActivateReference*, int, int);
void FUN_00600900(ActivateKey*);
void FUN_00600940(int);
void FUN_00600920(int);
int FUN_0047b250(ActivateReference*);
void FUN_0047a560(ActivateReference*, ActivateActor*, int);

// @fnv 0x00516dc0
bool ActivateObject::FUN_00516dc0(ActivateReference* apTarget, TESObjectREFR* activator, int unused, int a4, int a5)
{
    ActivateActor* actor2 = (ActivateActor*)dynamic_cast<Actor*>(activator);
    int extra = 0;
    int found8 = 0;
    if (actor2)
    {
        bool allowed3 = false;
        if (activator != (TESObjectREFR*)DAT_011dea3c)
            allowed3 = apTarget->FUN_005785e0(actor2, true);
        ActivateLock* lock = apTarget->FUN_00569160();
        if (lock && lock->FUN_005021a0() && !allowed3)
        {
            bool hasSkeletonKey = actor2->FUN_00891db0(DAT_011ca268, 0, 1, 0, &found8);
            if (lock->key && actor2->FUN_00891db0(lock->key, 0, 1, 0, &found8))
            {
                if (!DAT_011c92d0 && actor2 == DAT_011dea3c)
                {
                    DAT_011c92d0 = apTarget;
                    ActivateExtra* unlocked = apTarget->FUN_005691f0();
                    if (unlocked)
                    {
                        unlocked->FUN_00517360();
                        apTarget->FUN_005789b0();
                    }
                    FUN_00453a70()->GetSoundHandleByEditorID(DAT_0102b13c, 0x121).Play(false);
                    {
                        char message[256];
                        FUN_00406d00(message, 255, DAT_011d5110.FUN_00403df0(), lock->key->name.FUN_00408da0());
                        DispatchMessageToSink(message, 0, DAT_0102b108, 0, DAT_010162c0, 0);
                        DAT_011c92d0->Activate(DAT_011dea3c, 0, 0, 1);
                        DAT_011c92d0 = 0;
                        return true;
                    }
                }
            }
            else if (!DAT_011c92d0)
            {
                if (actor2 == DAT_011dea3c)
                {
                    ActivateExtra* locked = apTarget->FUN_005691f0();
                    float level2 = 0;
                    FUN_005e58f0(32, DAT_011dea3c, &level2);
                    if (locked && (locked->script->FUN_004309e0(apTarget) == 5 || locked->script->FUN_00430ae0()))
                    {
                        DispatchMessageToSink(DAT_011d276c.FUN_00403df0(), 0, DAT_0102b0d0, 0, DAT_010162c0, 0);
                    }
                    else
                        FUN_00705830(apTarget, 0, 0);
                }
                else
                {
                    ActivateAnimation* animation = actor2->GetAnimation();
                    if (animation)
                        animation->FUN_00498910(1, 0);
                    FUN_00600900(DAT_011ca268);
                    FUN_00600940(1);
                    FUN_00600920(1);
                    actor2->FUN_008d8520()->Action(actor2, 0, 2, 1, 0, 1);
                    FUN_00600900(0);
                    FUN_00600940(0);
                    FUN_00600920(-1);
                    ActivateExtra* npcLock2 = apTarget->FUN_005691f0();
                    if (npcLock2)
                    {
                        npcLock2->FUN_00517360();
                        apTarget->FUN_005789b0();
                    }
                }
            }
            return false;
        }
        if (actor2 != DAT_011dea3c && FUN_008ce390() && apTarget && apTarget->GetScene())
        {
            BSSoundHandleEx sound = FUN_00453a70()->FUN_00ad73b0(FUN_008ce390()->FUN_0084e3a0(), 0x102);
            ActivatePoint position = *apTarget->GetPosition();
            sound.SetPos(position.x, position.y, position.z);
            sound.Play(false);
        }
        if (actor2 == DAT_011dea3c)
        {
            if (FUN_0047b250(apTarget) == 1)
                activation.Activate(apTarget, actor2);
            else
                FUN_0047a560(apTarget, actor2, 0);
            return true;
        }
        else
        {
            if (a4)
                apTarget->Activate(a4, 0, a5, 0, 0, actor2, 0, 0, 1, 0);
            if (actor2->IsActor() && !apTarget->FUN_005785e0(actor2, true) && apTarget->FUN_00567790())
                actor2->FUN_008bfa40(apTarget, a4, a5, 1, extra);
        }
        return true;
    }
    return false;
}
}  // namespace fnv_00516dc0

struct ResolveBase
{
    void FUN_006796c0();
};
TESForm* LookupFormByID(unsigned int formID);
struct FUN_009f2220_obj : ResolveBase
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
    BSSimpleList<TESObjectREFR*> refList;
    TESObjectREFR* refA0;
    Actor* actorA4;
    void ResolveReferences();
};
// Resolves each stored form ID in refList, refA0 and actorA4 via LookupFormByID, removing list entries whose reference no longer resolves.
// @fnv 0x009f2220
void FUN_009f2220_obj::ResolveReferences()
{
    FUN_006796c0();
    BSSimpleList<TESObjectREFR*>* iter5 = &refList;
    BSSimpleList<TESObjectREFR*>* aPrev = 0;
    while (iter5 && !iter5->IsEmpty())
    {
        TESObjectREFR* ref = iter5->GetItem();
        unsigned int formID3 = (unsigned int)ref;
        if (formID3)
            ref = dynamic_cast<TESObjectREFR*>(LookupFormByID(formID3));
        if (!ref)
        {
            if (!aPrev)
            {
                iter5->RemoveHead();
            }
            else
            {
                TESObjectREFR* stale = (TESObjectREFR*)formID3;
                aPrev->Remove(stale);
                iter5 = aPrev->GetNext();
            }
        }
        else
        {
            iter5->SetItem(ref);
            aPrev = iter5;
            iter5 = iter5->GetNext();
        }
    }
    unsigned int actorID2 = (unsigned int)actorA4;
    if (actorID2)
        actorA4 = dynamic_cast<Actor*>(LookupFormByID(actorID2));
    unsigned int refID9 = (unsigned int)refA0;
    if (refID9)
        refA0 = dynamic_cast<TESObjectREFR*>(LookupFormByID(refID9));
}

template <int N> struct SlotTag
{
};
template <int N> struct VSlots : VSlots<N - 1>
{
    virtual void unused(SlotTag<N>*);
};
template <> struct VSlots<0>
{
};
struct FixedName;
struct PositionOwner
{
    const ActivationPosition* FUN_0045bb80();
};
struct SceneView : VSlots<39>
{
    virtual PositionOwner* Find(const FixedName&);
};
struct NodeView : VSlots<116>
{
    virtual SceneView* Node();
};
const FixedName& FUN_004ef990();
struct SoundRecord
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
};
struct SoundView
{
    SoundRecord CopyBig();
    const char* FUN_00511840();
};
struct AudioPlaybackHandle
{
    int unk00;
    int unk04;
    int unk08;
    ~AudioPlaybackHandle();
    bool SetPos(float, float, float);
    void SetNiNode(SceneView*);
    bool Play(bool);
};
struct AudioView
{
    static AudioView* FUN_00453a70();
    AudioPlaybackHandle FUN_00ad7480(const char*, unsigned int, SoundView*);
};
struct ExtraView
{
    void FUN_0041a6a0(AudioPlaybackHandle*);
};
struct AnimationView
{
    void FUN_00496080(bool, float);
};
struct PlayerView
{
    void SetByteAt79a(bool);
    AnimationView* FUN_00950a60(bool);
    ExtraView* FUN_005d43c0();
};
struct ActorView
{
    void UpdateTargetUnits(ActivationRef*, void*, int);
};
struct RefView
{
    bool FUN_005785e0(ActivationRef*, bool);
    void* FUN_00567790();
};
int GetFlagMask(int);
void FUN_0047a560(ActivationRef*, ActivationRef*, int);
int FUN_0047b250(ActivationRef*);
void FUN_008325b0(ActivationRef*, bool);
struct FUN_005113f0_shell
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
    ActivationRef* unk80;
    SoundView* FUN_00407820();
    void* FUN_004fd3c0();
    bool FUN_005113f0(ActivationRef*, ActivationRef*, bool, int, int);
};
// Checks the activator, may update actor state and play a sound, then calls Activate on the stored pointer when present.
// @fnv 0x005113f0
bool FUN_005113f0_shell::FUN_005113f0(ActivationRef* ref, ActivationRef* activator, bool arg3, int arg4, int arg5)
{
    ActivationRef* h = 0;
    bool p = false;
    if (activator && activator->IsActor())
        h = activator;
    if (h)
    {
        FUN_00600900((ActivationRef*)this);
        FUN_00600940(1);
        float a = h->FUN_008be940() + h->Position().z - h->GroundOffset();
        float f = ref->Position().z;
        int AB = 0;
        if (!ref->IsForced())
        {
            if (f > a)
                AB = 1;
        }
        else
            AB = 1;
        FUN_00600920(AB);
        bool i = h->FUN_008d8520()->CanActivate(h, 0, 3, 1, 0, 1);
        FUN_00600900(0);
        FUN_00600940(0);
        FUN_00600920(-1);
        if (!i && unk80)
            return false;
        if (activator == DAT_011dea3c && i)
        {
            DAT_011e0788 = unk80;
            ((PlayerView*)DAT_011dea3c)->SetByteAt79a(true);
            p = true;
            ((PlayerView*)DAT_011dea3c)->FUN_00950a60(true)->FUN_00496080(true, 0.0f);
            ((PlayerView*)DAT_011dea3c)->FUN_00950a60(false)->FUN_00496080(true, 0.0f);
        }
        if (!((RefView*)ref)->FUN_005785e0(h, true))
            ((ActorView*)h)->UpdateTargetUnits(ref, ((RefView*)ref)->FUN_00567790(), -1);
    }
    if (FUN_00407820())
    {
        PositionOwner* a = 0;
        if (ref && ((NodeView*)ref)->Node())
            a = ((NodeView*)ref)->Node()->Find(FUN_004ef990());
        ActivationPosition h = a ? *a->FUN_0045bb80() : ref->Position();
        int i = 0;
        if (p)
            i = GetFlagMask(FUN_00407820()->CopyBig().unk04);
        AudioPlaybackHandle AB =
            AudioView::FUN_00453a70()->FUN_00ad7480(FUN_00407820()->FUN_00511840(), i | 0x40000102, FUN_00407820());
        if (p)
            ((PlayerView*)DAT_011dea3c)->FUN_005d43c0()->FUN_0041a6a0(&AB);
        AB.SetPos(h.x, h.y, h.z);
        AB.SetNiNode(((NodeView*)ref)->Node());
        AB.Play(false);
    }
    if (unk80)
        unk80->Activate(ref, activator, arg3, arg4, arg5);
    FUN_0047a560(ref, activator, 0);
    if (FUN_004fd3c0())
    {
        bool h = false;
        int p = FUN_0047b250(ref);
        if (p == 1 || p == 2)
            h = true;
        FUN_008325b0(ref, h);
    }
    return true;
}

struct TESBoundObject
{
    virtual void vfn00();
};
struct TESPackage
{
    virtual void vfn00();
};
struct DialoguePackage : TESPackage
{
    int unk04[34];
    int m_iTopic;  // +0x8c
};

struct AAPoint
{
    float x, y, z;
};
class AAActor;
struct AAFaction
{
    bool FUN_0097fa10(AAActor* pkActorVal);
};
struct AAIdle
{
    unsigned char unk00[14];
    unsigned char m_ucType;
};  // +0x0e
struct AAEntry
{
    int FUN_0041ca90();
    bool FUN_00670f90();
};
struct AAPackageNode
{
    void* FUN_00726070();
};
struct AAPackageData
{
    int FUN_0041ca90();
    AAPackageNode* FUN_0041d8a0();
};
struct AAInventory
{
    AAEntry* FUN_0041cb10();
    int FUN_0041cb70(int iA, int iB, int iC);
    void FUN_0041c930(AAEntry* pkEntryCur, int iA, int iCount);
};
struct AAPackage
{
    int FUN_0041ca90();
};

class AAProcess
{
  public:
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual bool IsArrested();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual AAPackageData* GetPackageData();
    virtual void v280();
    virtual void v284();
    virtual void SetConversationState(AAActor* pkActorVal, int iState);
    virtual void v28c();
    virtual void v290();
    virtual void StopIdle(AAActor* pkActorVal);
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void SetDialogueActor(AAActor* pkSpeaker, AAActor* pkTarget, int iA, int iB, int iC, int iD, int iE, int iF,
                                  int iG, int iH, int iI, int iJ, int iK);
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual bool CanTalkTo(AAActor* pkActorVal);
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42c();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43c();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44c();
    virtual void v450();
    virtual void v454();
    virtual void v458();
    virtual void v45c();
    virtual void v460();
    virtual void v464();
    virtual void v468();
    virtual void v46c();
    virtual void v470();
    virtual void v474();
    virtual void v478();
    virtual void v47c();
    virtual void v480();
    virtual void v484();
    virtual void v488();
    virtual void v48c();
    virtual void v490();
    virtual void v494();
    virtual void v498();
    virtual void v49c();
    virtual void v4a0();
    virtual void v4a4();
    virtual void v4a8();
    virtual void v4ac();
    virtual void v4b0();
    virtual void v4b4();
    virtual void v4b8();
    virtual int GetMovementState();
    virtual void v4c0();
    virtual void v4c4();
    virtual void v4c8();
    virtual void v4cc();
    virtual void v4d0();
    virtual AAIdle* GetCurrentIdle();
    virtual void v4d8();
    virtual void v4dc();
    virtual void v4e0();
    virtual void v4e4();
    virtual void v4e8();
    virtual void v4ec();
    virtual void v4f0();
    virtual void v4f4();
    virtual void v4f8();
    virtual void v4fc();
    virtual void v500();
    virtual void v504();
    virtual void v508();
    virtual void v50c();
    virtual void v510();
    virtual void v514();
    virtual void v518();
    virtual void v51c();
    virtual void v520();
    virtual void v524();
    virtual void v528();
    virtual int StopIdleAnimation();
    virtual void v530();
    virtual void v534();
    virtual void v538();
    virtual void v53c();
    virtual void v540();
    virtual void v544();
    virtual void v548();
    virtual void v54c();
    virtual void v550();
    virtual void v554();
    virtual void v558();
    virtual void v55c();
    virtual void v560();
    virtual void v564();
    virtual void v568();
    virtual void v56c();
    virtual void v570();
    virtual void v574();
    virtual void v578();
    virtual void v57c();
    virtual void v580();
    virtual void v584();
    virtual void v588();
    virtual void v58c();
    virtual void v590();
    virtual void v594();
    virtual void v598();
    virtual void v59c();
    virtual void GiveItem(AAActor* pkActorVal, AAEntry* pkEntryCur);
    virtual void v5a4();
    virtual void v5a8();
    virtual void v5ac();
    virtual void v5b0();
    virtual void v5b4();
    virtual void v5b8();
    virtual void v5bc();
    virtual void v5c0();
    virtual void v5c4();
    virtual void v5c8();
    virtual void v5cc();
    virtual void v5d0();
    virtual void v5d4();
    virtual void v5d8();
    virtual void v5dc();
    virtual void v5e0();
    virtual void v5e4();
    virtual void v5e8();
    virtual void v5ec();
    virtual void v5f0();
    virtual void v5f4();
    virtual void v5f8();
    virtual void v5fc();
    virtual void v600();
    virtual void v604();
    virtual void v608();
    virtual void v60c();
    virtual int GetQueuedFurniture();
};

struct AAAnimData
{
    void FUN_00815b00();
};
struct AAValueHolder
{
    int unk00[12];
    struct AAValues
    {
        virtual void v000();
        virtual void v004();
        virtual void v008();
        virtual void v00c();
        virtual void v010();
        virtual void v014();
        virtual void v018();
        virtual bool IsEssential();
    } m_kValues;
};  // +0x30

class AAActor
{
  public:
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void SetFlag(unsigned int uiFlag);
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void ActivateItem(TESBoundObject* pkObject, int iA, int iCount, int iB, int iC, AAActor* pkActivator,
                              int iD, int iE, int iF, int iG);
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual const AAPoint& GetPos();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual int GetSitSleepState();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual bool IsDead(int iFlag);
    virtual bool IsIncapacitated();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual bool StartConversation(AAActor* pkTarget, int iA, int iB, int iC, int iD, int iE, int iF, int iG, int iH);
    virtual void v284();
    virtual void v288();
    virtual void TakeItem(AAEntry* pkEntryCur, bool bFlag);
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual AAActor* GetCurrentTalkTarget();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual bool IsInCombat();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual AAFaction* GetCrimeFaction();
    int unk[33];
    AAAnimData m_kAnim;  // +0x88

    AAProcess* FUN_008d8520();
    AAInventory* FUN_005d43c0();
    bool FUN_00437bd0();
    int FUN_004f8960();
    const char* FUN_0055d520();
    bool FUN_008a6650(int iFlag);
    bool FUN_00894d60();
    bool IsHostileTo(AAActor* pkTarget, int iA, int* piTopic, int iB);
    bool FUN_0087f3d0();
    AAValueHolder* FUN_004181e0();
    bool FUN_00493bb0();
    bool FUN_004997b0();
    bool FUN_00566950();
    bool FUN_008ace90();
    bool FUN_00898ff0();
    void StartDialog(void* pkSceneVal, int iA, int iB);
    bool FUN_008b3bb0();
    void FUN_008a8e50();
    void FUN_008a7a90();
    TESPackage* FUN_009344a0();
    void FUN_008bb520(AAPoint kPos, int iFlag);
    bool FUN_009336c0();
};

struct AASceneNode
{
    bool FUN_00619df0();
};
struct AAScene
{
    AASceneNode* FUN_0084e3a0();
    bool FUN_0083c7b0();
    bool FUN_0083c7e0();
    ~AAScene();
};
struct AASceneList
{
    AAScene* FUN_0061b320(AAActor* pkActorVal, AAActor* pkPlayer, int iA, int iB, int iC);
};

struct AAString
{
    const char* FUN_00403df0();
};
struct AAMenuMode
{
    bool FUN_00867d60();
};
struct AAMusic
{
    void FUN_009c8950(int iA, int iB);
};
struct AASound
{
    void FUN_00ad8780(int iFlag);
};

extern AAString DAT_011d210c;
extern AAString DAT_011d2538;
extern AAString DAT_011d2394;
extern AAMenuMode DAT_011de7b8;

AASound* FUN_00453a70();
int FUN_00ec623a(char* pcBuffer, const char* pcFormat, ...);
void DispatchMessageToSink(const char* pcText, int iA, const char* pcIcon, const char* pcSound, float fTime, int iB);
void FUN_00709470(int iType, void* pkTarget, int iA, int iB, int iC, int iD);
bool FUN_00754d90(AAActor* pkActorVal);
AASceneList* GetTopicSubTypeName(int iA, int iB);
int FUN_00702640();

class AAHandler
{
  public:
    char FUN_0059f3a0();
    bool OnActivate(TESObjectREFR* pkRef, TESObjectREFR* pkActivatorRef, int iUnused, TESBoundObject* pkObject,
                    int iCount);
};

static const char s_szNameFormat[] = "%s %s";
static const char s_szSadIcon[] = "Interface\\Icons\\Message Icons\\glow_message_vaultboy_sad.dds";
static const char s_szSurprisedIcon[] = "Interface\\Icons\\Message Icons\\glow_message_vaultboy_surprised.dds";

// Handles activation of pkRef by pkActivatorRef, starting conversations, giving items, or dispatching messages based on actor state.
// @fnv 0x005fa330
bool AAHandler::OnActivate(TESObjectREFR* pkRef, TESObjectREFR* pkActivatorRef, int iUnused, TESBoundObject* pkObject,
                           int iCount)
{
    char acMessage[300];
    AAActor* pkActivator = (AAActor*)dynamic_cast<Actor*>(pkActivatorRef);
    AAActor* pkActorVal = (AAActor*)dynamic_cast<Actor*>(pkRef);
    if (!pkActorVal || !pkActivator || pkActorVal->IsInCombat())
        return false;
    AAProcess* pkProcessRef = pkActorVal->FUN_008d8520();
    if (!pkProcessRef)
        return false;
    if (pkProcessRef && pkProcessRef->StopIdleAnimation() && !pkActorVal->IsDead(0))
        return false;
    if (pkProcessRef && pkProcessRef->GetQueuedFurniture())
        return false;
    AAPackageData* pkActivatorPackageTmp = pkActivator->FUN_008d8520()->GetPackageData();
    AAPackageData* pkPackageCur = pkProcessRef->GetPackageData();
    if (pkActivator && pkActivator != (AAActor*)DAT_011dea3c)
    {
        AAEntry* pkEntryCur = pkActivator->FUN_005d43c0()->FUN_0041cb10();
        if (pkEntryCur && pkEntryCur->FUN_0041ca90() == 0xf)
        {
            AAInventory* pkInventory = pkActorVal->FUN_005d43c0();
            pkActivator->FUN_005d43c0()->FUN_0041c930(pkEntryCur, 4, pkInventory->FUN_0041cb70(0, 0, 0));
            pkActorVal->FUN_008d8520()->GiveItem(pkActivator, pkEntryCur);
            if (pkEntryCur->FUN_00670f90())
                pkActivator->TakeItem(pkEntryCur, DAT_011de7b8.FUN_00867d60());
            pkActorVal->SetFlag(0x80000000);
        }
    }
    int iTopic = 0;
    if (pkActorVal->FUN_00437bd0() || pkActorVal->IsIncapacitated() || pkActorVal->FUN_004f8960() == 6)
    {
        if (FUN_0059f3a0() != 6)
        {
            FUN_00ec623a(acMessage, s_szNameFormat, pkActorVal->FUN_0055d520(), DAT_011d210c.FUN_00403df0());
            DispatchMessageToSink(acMessage, 0, s_szSurprisedIcon, 0, 2.0f, 0);
        }
        return false;
    }
    else if (pkActorVal->FUN_008a6650(0))
    {
        AAFaction* pkFaction = pkActorVal->GetCrimeFaction();
        if (!pkFaction || !pkFaction->FUN_0097fa10((AAActor*)DAT_011dea3c) || ((AAActor*)DAT_011dea3c)->FUN_00894d60())
        {
            FUN_00ec623a(acMessage, s_szNameFormat, pkActorVal->FUN_0055d520(), DAT_011d2538.FUN_00403df0());
            DispatchMessageToSink(acMessage, 0, s_szSadIcon, 0, 2.0f, 0);
            return false;
        }
    }
    else if (pkActorVal->IsDead(0))
    {
        if (pkActivator == (AAActor*)DAT_011dea3c)
            FUN_00709470(1, pkRef, 0, 0, 1, 0);
        else if (pkObject && !dynamic_cast<TESNPC*>(pkObject))
            ((AAActor*)pkRef)->ActivateItem(pkObject, 0, iCount, 0, 0, pkActivator, 0, 0, 1, 0);
    }
    else if (pkActivator != (AAActor*)DAT_011dea3c && pkActivator->IsHostileTo(pkActorVal, 0, &iTopic, 0))
    {
        pkActivator->FUN_008d8520()->SetDialogueActor(pkActivator, pkActorVal, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0);
    }
    else if (pkActivator == (AAActor*)DAT_011dea3c && pkActorVal->IsIncapacitated() && pkActorVal->FUN_0087f3d0())
    {
        return false;
    }
    else if (pkActorVal->FUN_004181e0()->m_kValues.IsEssential() && !pkActorVal->FUN_00493bb0() &&
             pkActivator == (AAActor*)DAT_011dea3c &&
             ((pkActorVal->IsIncapacitated() && !pkActorVal->FUN_0087f3d0()) ||
              (((AAActor*)DAT_011dea3c)->FUN_004997b0() && !pkActorVal->FUN_00566950())) &&
             !pkActorVal->FUN_008ace90())
    {
        if (!pkActorVal->IsIncapacitated() && pkActorVal->FUN_008d8520()->IsArrested())
        {
            FUN_00ec623a(acMessage, s_szNameFormat, pkActorVal->FUN_0055d520(), DAT_011d2394.FUN_00403df0());
            DispatchMessageToSink(acMessage, 0, s_szSadIcon, 0, 2.0f, 0);
            return false;
        }
        else
            FUN_00709470(1, pkRef, 0, 0, 2, 0);
    }
    else if (pkActorVal->FUN_00898ff0() || pkActivator != (AAActor*)DAT_011dea3c)
    {
        if (pkActorVal->FUN_00566950() && pkActivatorRef == (TESObjectREFR*)DAT_011dea3c)
        {
            if (FUN_00754d90(pkActorVal))
                FUN_00709470(8, pkRef, 0, 0, 0, 0);
            return false;
        }
        AASceneList* pkScenes = pkActivator == (AAActor*)DAT_011dea3c ? GetTopicSubTypeName(0, 0) : 0;
        AAScene* pkSceneVal = pkScenes ? pkScenes->FUN_0061b320(pkActorVal, (AAActor*)DAT_011dea3c, 0, 0, 0) : 0;
        if (pkSceneVal && pkSceneVal->FUN_0084e3a0()->FUN_00619df0() && pkSceneVal->FUN_0083c7b0() &&
            !pkSceneVal->FUN_0083c7e0())
            pkActorVal->StartDialog(pkScenes, 0, 0);
        else if (!pkSceneVal)
            return false;
        else if (pkActorVal->FUN_00493bb0() && pkActivator == (AAActor*)DAT_011dea3c && pkActorVal->FUN_00566950())
        {
            ((AAMusic*)&DAT_011f2250)->FUN_009c8950(0, 0);
            FUN_00709470(4, pkActorVal, 0, 0, 1, 0);
        }
        else if (pkActorVal && (!pkActorVal->FUN_00493bb0() || pkActorVal->IsIncapacitated()) &&
                 (pkActivator != (AAActor*)DAT_011dea3c || !pkActorVal->GetSitSleepState() ||
                  pkActorVal->GetSitSleepState() == 9 || pkActorVal->GetSitSleepState() == 4 ||
                  (pkActorVal->FUN_008d8520()->GetCurrentIdle() &&
                   pkActorVal->FUN_008d8520()->GetCurrentIdle()->m_ucType > 0x13)))
        {
            int iDialogueTopic = 0;
            TESObjectREFR* pkSpeaker = 0;
            if (pkActivator == (AAActor*)DAT_011dea3c)
            {
                if (!pkActorVal->FUN_008b3bb0())
                    pkActorVal->FUN_008d8520()->StopIdle(pkActorVal);
                pkActivator->FUN_008a8e50();
                pkActorVal->FUN_008a8e50();
                pkSpeaker = pkRef;
                if (pkActorVal->GetCurrentTalkTarget() == (AAActor*)DAT_011dea3c && pkPackageCur &&
                    !pkPackageCur->FUN_0041ca90())
                {
                    if (pkPackageCur->FUN_0041d8a0() && !pkPackageCur->FUN_0041d8a0()->FUN_00726070())
                        pkProcessRef->SetConversationState(pkActivator, 2);
                    else
                        pkProcessRef->SetConversationState(pkActorVal, 1);
                }
                FUN_00453a70()->FUN_00ad8780(4);
                pkActorVal->m_kAnim.FUN_00815b00();
                pkActorVal->FUN_008a7a90();
                pkActivator->FUN_008a7a90();
                if (pkProcessRef->GetMovementState() != 9)
                {
                    ((AAMusic*)&DAT_011f2250)->FUN_009c8950(0, 0);
                    AAActor* pkTarget = pkActivator;
                    if (pkTarget == (AAActor*)DAT_011dea3c)
                        pkTarget = pkActorVal;
                    FUN_00709470(4, pkTarget, iDialogueTopic, 0, 1, 0);
                }
                else
                    pkActorVal->StartConversation((AAActor*)DAT_011dea3c, 0, 0, 1, 0, 0, 0, 0, 0);
            }
            else if (FUN_00702640() != 0x3f1 && pkActorVal == (AAActor*)DAT_011dea3c)
            {
                if (!pkActorVal->FUN_008d8520()->CanTalkTo(pkActivator))
                    return false;
                FUN_00453a70()->FUN_00ad8780(4);
                pkActivator->FUN_008a8e50();
                pkActorVal->FUN_008a8e50();
                pkSpeaker = (TESObjectREFR*)pkActivator;
                DialoguePackage* pkDialogueOld = dynamic_cast<DialoguePackage*>(pkActivator->FUN_009344a0());
                if (pkDialogueOld)
                    iDialogueTopic = pkDialogueOld->m_iTopic;
                if (pkActivatorPackageTmp->FUN_0041d8a0() && !pkActivatorPackageTmp->FUN_0041d8a0()->FUN_00726070())
                    pkActivator->FUN_008d8520()->SetConversationState(pkActivator, 2);
                else
                    pkActivator->FUN_008d8520()->SetConversationState(pkActivator, 1);
                pkActorVal->m_kAnim.FUN_00815b00();
                pkActorVal->FUN_008a7a90();
                pkActivator->FUN_008a7a90();
                ((AAMusic*)&DAT_011f2250)->FUN_009c8950(0, 0);
                AAActor* pkTarget2 = pkActivator;
                if (pkTarget2 == (AAActor*)DAT_011dea3c)
                    pkTarget2 = pkActorVal;
                FUN_00709470(4, pkTarget2, iDialogueTopic, 0, 1, 0);
            }
            else
            {
                if (pkActorVal != pkActivator && pkActorVal->FUN_009344a0() &&
                    ((AAPackage*)pkActorVal->FUN_009344a0())->FUN_0041ca90() != 1 &&
                    ((AAPackage*)pkActorVal->FUN_009344a0())->FUN_0041ca90() != 2)
                    pkProcessRef->SetConversationState(pkActorVal, 1);
                if (pkActorVal != pkActivator && !pkActorVal->GetSitSleepState())
                    pkActorVal->FUN_008bb520(pkActivator->GetPos(), 0);
                if (!pkActivator->FUN_009336c0())
                {
                    if (pkActivatorPackageTmp->FUN_0041d8a0() && !pkActivatorPackageTmp->FUN_0041d8a0()->FUN_00726070())
                        pkActivator->FUN_008d8520()->SetConversationState(pkActivator, 2);
                    else
                        pkActivator->FUN_008d8520()->SetConversationState(pkActivator, 1);
                    if (pkActivator->StartConversation(pkActorVal, 0, 0, 1, 0, 0, 0, 0, 0))
                    {
                        pkActivator->FUN_008d8520()->SetConversationState(pkActivator, 2);
                        pkProcessRef->SetConversationState(pkActorVal, 2);
                    }
                }
                else
                    pkActivator->FUN_008d8520()->SetConversationState(pkActivator, 1);
            }
        }
        delete pkSceneVal;
    }
    else if (pkActorVal->FUN_00566950() && pkActivatorRef == (TESObjectREFR*)DAT_011dea3c)
    {
        if (FUN_00754d90(pkActorVal))
            FUN_00709470(8, pkRef, 0, 0, 0, 0);
        return false;
    }
    return true;
}

class StageRecord : public TESForm, public StageRecordData
{
};
struct S_005805c0_Object;

struct S_005805c0_Arg
{
    virtual void v000() = 0;
    virtual void v001() = 0;
    virtual void v002() = 0;
    virtual void v003() = 0;
    virtual void v004() = 0;
    virtual void v005() = 0;
    virtual void v006() = 0;
    virtual void v007() = 0;
    virtual void v008() = 0;
    virtual void v009() = 0;
    virtual void v010() = 0;
    virtual void v011() = 0;
    virtual void v012() = 0;
    virtual void v013() = 0;
    virtual void v014() = 0;
    virtual void v015() = 0;
    virtual void v016() = 0;
    virtual void v017() = 0;
    virtual void v018() = 0;
    virtual void v019() = 0;
    virtual void v020() = 0;
    virtual void v021() = 0;
    virtual void v022() = 0;
    virtual void v023() = 0;
    virtual void v024() = 0;
    virtual void v025() = 0;
    virtual void v026() = 0;
    virtual void v027() = 0;
    virtual void v028() = 0;
    virtual void v029() = 0;
    virtual void v030() = 0;
    virtual void v031() = 0;
    virtual void v032() = 0;
    virtual void v033() = 0;
    virtual void v034() = 0;
    virtual void v035() = 0;
    virtual void v036() = 0;
    virtual void v037() = 0;
    virtual void v038() = 0;
    virtual void v039() = 0;
    virtual void v040() = 0;
    virtual void v041() = 0;
    virtual void v042() = 0;
    virtual void v043() = 0;
    virtual void v044() = 0;
    virtual void v045() = 0;
    virtual void v046() = 0;
    virtual void v047() = 0;
    virtual void v048() = 0;
    virtual void v049() = 0;
    virtual void v050() = 0;
    virtual void v051() = 0;
    virtual void v052() = 0;
    virtual void v053() = 0;
    virtual void v054() = 0;
    virtual void v055() = 0;
    virtual void v056() = 0;
    virtual void v057() = 0;
    virtual void v058() = 0;
    virtual void v059() = 0;
    virtual void v060() = 0;
    virtual void v061() = 0;
    virtual void v062() = 0;
    virtual void v063() = 0;
    virtual bool v100() = 0;
    virtual void v101() = 0;
    virtual void v066() = 0;
    virtual void v067() = 0;
    virtual void v068() = 0;
    virtual void v069() = 0;
    virtual void v070() = 0;
    virtual void v071() = 0;
    virtual void v072() = 0;
    virtual void v073() = 0;
    virtual void v074() = 0;
    virtual void v075() = 0;
    virtual void v076() = 0;
    virtual void v077() = 0;
    virtual void v078() = 0;
    virtual void v079() = 0;
    virtual void v080() = 0;
    virtual void v081() = 0;
    virtual void v082() = 0;
    virtual void v083() = 0;
    virtual void v084() = 0;
    virtual void v085() = 0;
    virtual void v086() = 0;
    virtual void v087() = 0;
    virtual void v088() = 0;
    virtual void v089() = 0;
    virtual void v090() = 0;
    virtual void v091() = 0;
    virtual void v092() = 0;
    virtual void v093() = 0;
    virtual void v094() = 0;
    virtual void v095() = 0;
    virtual void v096() = 0;
    virtual void v097() = 0;
    virtual void v098() = 0;
    virtual void v099() = 0;
    virtual void v196() = 0;
    virtual void v197() = 0;
    virtual S_005805c0_Object* v198() = 0;
};

struct S_005805c0_Object
{
    virtual void v000() = 0;
    virtual void v001() = 0;
    virtual void v002() = 0;
    virtual void v003(StageRecordData* stageData, int value08, int value0c, float value10, int value14) = 0;
};

void __cdecl FUN_005e58f0(int value, S_005805c0_Arg* object, float* amount);

struct S_005805c0_Owner
{
    virtual void v000() = 0;
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
    StageRecord* unk178;

    bool FUN_005805c0(int value08, S_005805c0_Arg* object, int value0c, float value10, int value14);
};

// If both pointers and the returned object are non-null, calls v003 with the stored stage record and returns true.
// @fnv 0x005805c0
bool S_005805c0_Owner::FUN_005805c0(int value08, S_005805c0_Arg* object, int value0c, float value10, int value14)
{
    if (this->unk178 != 0 && object != 0)
    {
        S_005805c0_Object* target = object->v198();
        if (target != 0)
        {
            float amount = 1.0f;
            if (object->v100())
            {
                FUN_005e58f0(0x1a, object, &amount);
            }

            target->v003(static_cast<StageRecordData*>(this->unk178), 0, 0, amount, 1);
            return true;
        }
    }

    return false;
}
