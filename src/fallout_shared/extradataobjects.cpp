// fallout_shared/extradataobjects.cpp: DelStandIn, ExtraFactionChanges, BSExtraData, ExtraLeveledItem and more (293 functions)

#include "extradataobjects_private_packet.h"

// Packet additions verified with /Od /Oy- /GS /EHsc /Gy.
// Shared code addresses use the canonical decorated names, even when the
// original instantiation serves a different record type in this unit.

// @fnv 0x00414010
ReferenceFloatEntry::ReferenceFloatEntry()
{
    m_pWorldReferenceInfo = 0;
    m_fDelay = 0.0f;
}

// @fnv 0x00430a90
void LockExtraData::SetLocked(bool aLocked)
{
    if (aLocked)
        cFlags |= 1;
    else
    {
        cFlags &= ~1;
        m_uiLockDifficulty = 0;
    }
}

// Sets or clears the bit for aMarker in the used-markers mask when aMarker is below 0x1E.
// @fnv 0x00432fc0
void ExtraUsedMarkers::SetUsedMarker(unsigned int aMarker, bool aUsed)
{
    if (aMarker < 0x1E)
    {
        unsigned int uiBit = 1 << aMarker;
        if (aUsed)
            m_uiUsedMarkerFlags |= uiBit;
        else
            m_uiUsedMarkerFlags &= ~uiBit;
    }
}

// @fnv 0x00431780
ExtraAction::ExtraAction() : BSExtraData(0x0E)
{
    eAction = 1;
    m_pActionReference = 0;
}

// Constructs an ExtraGlobal extra-data object with type 0x21 and stores the given TESGlobal pointer.
// @fnv 0x00431a40
ExtraGlobal::ExtraGlobal(TESGlobal* aGlobal) : BSExtraData(0x21)
{
    pGlobalForm = aGlobal;
}

// Constructs an ExtraCount extra-data object with type 0x24 and stores the given count in iCount.
// @fnv 0x00431c20
ExtraCount::ExtraCount(short aCount) : BSExtraData(0x24)
{
    iCount = aCount;
}

// Constructs an ExtraScript extra-data object storing the given Script pointer and initializing its field to 0.
// @fnv 0x00432000
ExtraScript::ExtraScript(Script* aScript) : BSExtraData(0x0D)
{
    pScript = aScript;
    m_pLocals = 0;
}

// Constructs an ExtraLeveledItem extra-data object with type 0x2F, storing the given index and setting a flag to true.
// @fnv 0x00432be0
ExtraLeveledItem::ExtraLeveledItem(int aIndex) : BSExtraData(0x2F)
{
    iIndex = aIndex;
    m_bIsLeveledItem = true;
}

// Constructs an ExtraPersistentCell with type 0x0C, storing aCell or null in the cell pointer field.
// @fnv 0x00432c20
ExtraPersistentCell::ExtraPersistentCell(TESObjectCELL* aCell) : BSExtraData(0x0C)
{
    if (aCell)
        m_pCell = aCell;
    else
        m_pCell = 0;
}

// @fnv 0x00432cb0
ExtraRagDollData::ExtraRagDollData() : BSExtraData(0x14)
{
    m_pRagDollData = 0;
}

// @fnv 0x00432f50
ExtraReservedMarkers::ExtraReservedMarkers() : BSExtraData(0x82)
{
    m_uiReservedMarkers = 0;
}

// @fnv 0x004308c0
ExtraStartingWorldOrCell::ExtraStartingWorldOrCell() : BSExtraData(0x49)
{
    m_pStartingWorldOrCell = 0;
}

// Initializes the extra data with type 0x62 and sets pBound to null.
// @fnv 0x00435590
ExtraMultiBoundData::ExtraMultiBoundData() : BSExtraData(0x62)
{
    pBound = 0;
}

// @fnv 0x0042ce00
char* ExtraSecuritronFace::GetPersonality()
{
    return DAT_011c6444;
}
// @fnv 0x00517360
void ExtraLock::Unlock()
{
    lock->SetLocked(false);
}
// @fnv 0x00569280
void ExtraLock::Lock()
{
    lock->SetLocked(true);
}
// @fnv 0x00877a30
template <> TESObjectREFR*& NiTArray<TESObjectREFR*, NiTNewInterface<TESObjectREFR*> >::GetAt(unsigned int index)
{
    return data[index];
}
// @fnv 0x008d03c0
void BaseProcess::SetPackageInfoState(int aiCastingType)
{
    procedure.SetCastingType((MagicSystem__CastingType)aiCastingType);
}

// @fnv 0x004309e0
int LockExtraData::GetLockLevel(TESObjectREFR* ref)
{
    int level = GetLevel(ref);
    return ConvertLockLevel(level);
}
// @fnv 0x004310d0
void ExtraGuardedRefData::AddGuardingActor(Actor* actor)
{
    NavMeshInfo* guard = reinterpret_cast<NavMeshInfo*>(actor->GetFormID());
    if (guards.Find(guard, 0, FUN_009a3830) == (unsigned int)-1)
        guards.Add(guard);
}

// Casts extra to ExtraLeveledItem and returns true if the cast fails or BSExtraData::Compare(extra) succeeds, otherwise false.
// @fnv 0x00431cc0
bool ExtraLeveledItem::Compare(BSExtraData* extra)
{
    ExtraLeveledItem* item = static_cast<ExtraLeveledItem*>(__RTDynamicCast(extra, 0, &DAT_01183b2c, &DAT_01184680, 0));
    if (!item)
        return true;
    if (BSExtraData::Compare(extra))
        return true;
    return false;
}
// Walks the quest info list and returns true if any perk entry's faction matches the given faction.
// @fnv 0x0047ebf0
bool ExtraFactionChanges::HasFactionEntry(TESFaction* faction)
{
    BSSimpleList<BGSPerkEntry*>* node =
        reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(reinterpret_cast<TESTopic*>(this)->GetQuestInfoList());
    while (node)
    {
        BGSPerkEntry* entry = node->GetItem();
        if (entry && entry->faction == faction)
            return true;
        node = node->GetNext();
    }
    return false;
}
// @fnv 0x00430ae0
bool LockExtraData::MeetsMinimumLockLevel()
{
    float modifier = 0.0f;
    ApplyPerkModifiers(0x20, reinterpret_cast<Actor*>(g_thePlayer), &modifier);
    return m_uiLockDifficulty >= (modifier != 0.0 ? 2U : 1U);
}

#include "extradataobjects_additions.h"

// Maps a lock level value to a difficulty index 0-5 by comparing it against the GameSettingCollection lock level maximums.
// @fnv 0x00430b40
int LockExtraData::ConvertLockLevel(int aiLockLevel)
{
    if (aiLockLevel <= GameSettingCollection::iLockLevelMaxVeryEasy.Int()->i)
        return 0;
    if (aiLockLevel <= GameSettingCollection::iLockLevelMaxEasy.Int()->i)
        return 1;
    if (aiLockLevel <= GameSettingCollection::iLockLevelMaxAverage.Int()->i)
        return 2;
    if (aiLockLevel <= GameSettingCollection::iLockLevelMaxHard.Int()->i)
        return 3;
    if (aiLockLevel <= GameSettingCollection::iLockLevelMaxVeryHard.Int()->i)
        return 4;
    return 5;
}

// Casts extra to ExtraHealth, returns true if the cast fails, the base compare matches, or the stored value differs; otherwise false.
// @fnv 0x00431d40
bool ExtraHealth::Compare(BSExtraData* extra)
{
    ExtraHealth* health = dynamic_cast<ExtraHealth*>(extra);
    if (!health)
        return true;
    if (BSExtraData::Compare(extra))
        return true;
    if (fHealthPercent != health->fHealthPercent)
        return true;
    return false;
}

// Searches the decal reference list for a record whose reference matches the given TESObjectREFR and returns it, or null if none matches.
// @fnv 0x00434410
ReferenceIntersectionData* ExtraDecalRefs::FindDecalReference(TESObjectREFR* reference)
{
    ReferenceIntersectionData* result = 0;
    BSSimpleList<ReferenceIntersectionData*>* node = &m_kDecalReferences;
    while (node && !node->IsEmpty())
    {
        ReferenceIntersectionData* record = node->GetItem();
        node = node->GetNext();
        if (record->m_pHitReference == reference)
        {
            result = record;
            break;
        }
    }
    return result;
}

// Returns the base level, adding the scaled actor or player level when the leveled-lock flag is set, capped at 99.
// @fnv 0x00430a10
int LockExtraData::GetLevel(TESObjectREFR* reference)
{
    int level = m_uiLockState;
    if (cFlags & 4)
    {
        int actorLevel = reference ? reference->GetReferenceLevel(false) : g_thePlayer->GetLevel();
        level += (int)GameSettingCollection::fLeveledLockMult.Float()->f * actorLevel;
        if (level > 99)
            level = 99;
    }
    return level;
}

// Whole-body identity: static lock enum -> named lock thresholds, not
// Valid unmarked WIP: original-byte parser supplies167/168 bytes, truncating
// the final local jump-table relocation. No instruction differences observed.
int LockExtraData::EnumToNumericValue(LOCK_LEVEL level)
{
    int value = 0;
    switch (level)
    {
    case LOCK_LEVEL_LL_VERYEASY:
        value = GameSettingCollection::iLockLevelMaxVeryEasy.Int()->i;
        break;
    case LOCK_LEVEL_LL_EASY:
        value = GameSettingCollection::iLockLevelMaxEasy.Int()->i;
        break;
    case LOCK_LEVEL_LL_AVERAGE:
        value = GameSettingCollection::iLockLevelMaxAverage.Int()->i;
        break;
    case LOCK_LEVEL_LL_HARD:
        value = GameSettingCollection::iLockLevelMaxHard.Int()->i;
        break;
    case LOCK_LEVEL_LL_VERYHARD:
        value = GameSettingCollection::iLockLevelMaxVeryHard.Int()->i;
        break;
    case LOCK_LEVEL_LL_IMPOSSIBLE:
        value = GameSettingCollection::iLockLevelMaxImpossible.Int()->i;
        break;
    }
    return value;
}

// Whole-body mapping to the declared single-faction expulsion method.
// Clears the rank of the matching faction entry, or adds a new entry for the faction with rank -1.
// @fnv 0x00436e10
void ExtraFactionChanges::RemoveFaction(TESFaction* faction)
{
    BSSimpleList<FactionReaction*>* node = m_pFactionChanges;
    while (node && node->GetItem())
    {
        FactionReaction* rank = node->GetItem();
        if (faction == rank->pFaction)
        {
            rank->m_ucRank = -1;
            return;
        }
        node = node->GetNext();
    }
    if (!m_pFactionChanges)
        m_pFactionChanges = new BSSimpleList<FactionReaction*>;
    FactionReaction* rank = new FactionReaction;
    rank->pFaction = faction;
    rank->m_ucRank = -1;
    m_pFactionChanges->AddHead(rank);
}

// Updates the rank of an existing faction entry in the list, or allocates a new entry with the given faction and rank and adds it to the head of the list.
// @fnv 0x00436f80
void ExtraFactionChanges::SetFactionRank(TESFaction* faction, int value)
{
    BSSimpleList<FactionReaction*>* node = m_pFactionChanges;
    while (node && node->GetItem())
    {
        FactionReaction* rank = node->GetItem();
        if (faction == rank->pFaction)
        {
            rank->m_ucRank = value;
            return;
        }
        node = node->GetNext();
    }
    FactionReaction* rank = new FactionReaction;
    rank->m_ucRank = value;
    rank->pFaction = faction;
    m_pFactionChanges->AddHead(rank);
}

// Exact public address declaration identifies this folded setter.
// @fnv 0x00437730
void BGSQuestObjective::SetOwner(TESQuest* owner)
{
    m_pOwnerQuest = owner;
}

// Complete body reconstructed from supplied00438470 disassembly.
// Copies the source string into this string, resizing the internal buffer when needed, and returns whether the result is non-empty.
// @fnv 0x00438470
template <> bool BSStringT<char>::Set(const BSStringT<char>& source)
{
    unsigned int length = source.GetLength();
    if (length <= GetMaxLength())
    {
        if (length)
            memcpy(pString, source.GetString(), length + 1);
        else
        {
            if (pString)
                delete[] pString;
            pString = 0;
            length = 0;
            SetMaxLength(length);
        }
    }
    else
    {
        char* old = pString;
        pString = new char[length + 1];
        memcpy(pString, source.GetString(), length + 1);
        if (old)
            delete[] old;
        SetMaxLength(length);
    }
    SetLength(length);
    return length != 0;
}

// Derived destruction and supplied0040ecb0 body establish genuine base lifetime.
// @fnv 0x00432c90
ExtraPersistentCell::~ExtraPersistentCell()
{}

// @fnv 0x00437a90
ExtraPatrolRefInUseData::~ExtraPatrolRefInUseData()
{}

// Constructs an ExtraWorn extra-data object, initializing its BSExtraData base with type 0x16.
// @fnv 0x004322f0
ExtraWorn::ExtraWorn() : BSExtraData(0x16)
{}

// @fnv 0x00432f30
void FUN_00432f30_D::FUN_00432f30()
{
    this->BSExtraData::~BSExtraData();
}

struct BGSLoadGameBuffer;
struct BGSSaveGameBuffer;
struct CombatTargetTimestamp
{
    float ElapsedTime();
    float DisplayElapsedTime();
    void SaveGame(BGSSaveGameBuffer*);
    void LoadGame(BGSLoadGameBuffer*);
    float fTimeStamp;
};
typedef char _sizecheck_CombatTimeStamp[sizeof(CombatTargetTimestamp) == 4 ? 1 : -1];
struct FUN_004300a0_shell : public CombatTargetTimestamp
{
    void FUN_004300a0(float);
};

// @fnv 0x004300a0
CombatTargetTimestamp* __fastcall FUN_004300a0(CombatTargetTimestamp* this_ptr)
{
    this_ptr->fTimeStamp = 0.0f;
    return this_ptr;
}

struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BSAnimGroupSequence;
struct FindData;
struct KFModel;
struct NiAVObject;
struct NiControllerManager;
struct NiControllerSequence;
struct NiNode;
struct TESAnimGroup;
struct TESIdleForm;
struct Animation
{
    void SetField(unsigned char, unsigned char, unsigned char);
    unsigned char GetField(unsigned char, unsigned char);
    void SetBit(bool, unsigned char);
    bool GetBit(unsigned char);
    NiNode* GetAnimNode();
    NiNode* GetAccumRoot();
    void* GetAnimSequenceMap();
    float GetSmallestHavokBlendValue(NiNode*);
    NiControllerManager* GetControllerManager();
    void RemoveObject(NiAVObject*);
    float GetTime();
    float GetTime(NiControllerSequence*);
    void SetTime(float);
    static void SetLipTime(float, NiControllerManager*, NiControllerSequence*);
    void SetLipTime(float);
    bool Init(void*, NiNode*, TESObjectREFR*, bool);
    void SetAnimationName(void*, char*);
    void SetAnimationOwner(void*);
    void QueueReloadAnim(unsigned short);
    bool ReloadAnimQueued();
    bool AddAnimation(KFModel*, bool);
    bool IsAnimationLoaded();
    void SetReloadState(bool);
    void BlendOut(int, bool);
    static float GetDuration(NiControllerSequence*);
    static float GetDuration(NiNode*, float*, float*);
    float GetDuration();
    void SetLookingDir(float);
    void SkipUpdate(int);
    void Update(TESObjectREFR*, float, float);
    void UpdateMovement(TESObjectREFR*);
    void UpdateActorAnimation(TESObjectREFR*);
    bool UpdateQueuedScenegraph();
    bool GetMovementDelta(NiPoint3*, TESObjectREFR*, bool, bool);
    void ClearDelta();
    bool IsGroupQueued(unsigned short);
    void ClearGroup(int, float);
    unsigned short GetQueuedGroup(int);
    void ClearBlendInterps();
    static void ClearBlendInterpsCallback(NiAVObject*);
    void SetAnimationGroup(TESAnimGroup*);
    short GetGroupSection(unsigned short);
    void UpdateBipOnly(float, NiPoint3*, bool);
    void RefreshAnimation();
    void SetMoveSpeed(float);
    float GetMoveSpeed();
    void SetAttackSpeed(float);
    float GetAttackSpeedModifier();
    void AddGroup(TESAnimGroup*);
    BSAnimGroupSequence* PlayGroup(BSAnimGroupSequence*, int, int, int);
    BSAnimGroupSequence* PlayGroup(unsigned short, int, int, int);
    BSAnimGroupSequence* SyncSequences(BSAnimGroupSequence*, unsigned short);
    unsigned short PickBestAnimation(unsigned short, bool);
    bool ShouldBeMoving();
    BSAnimGroupSequence* GetCurrentSequence(int);
    unsigned short GetGroup(int);
    int GetGroupAction(int);
    BSAnimGroupSequence* GetFirstActiveSequence();
    BSAnimGroupSequence* GetNextActiveSequence(BSAnimGroupSequence*);
    void SetCurrentSequence(int, BSAnimGroupSequence*);
    void VerifyUniqueControllerPriorities(NiNode*);
    static bool StripAllBSKeyframeControllers(NiAVObject*);
    bool SwapSequences(int);
    char GetNextNoteKey(float*);
    int FindNoteKey(int, char*, float*);
    char FindNextNoteKey(int, char*, float*);
    void ForceSection(int, unsigned short, int, float, char);
    void ClearForcedSection();
    TESAnimGroup* GetAnimGroupByID(unsigned short);
    bool AreAnimationsLoaded();
    unsigned int GetAnimsLoadingCount();
    void QueueReplacementAnimation(KFModel*);
    void SetLoopCount(int, int);
    void SpecialIdleQueue(TESIdleForm*, int);
    void PlaySpecialIdle(TESIdleForm*, Actor*, int, int);
    bool SpecialIdleReplace();
    void SpecialIdleReplace(TESIdleForm*, Actor*, int);
    bool CanReplaceSpecialIdle();
    bool CanReplaceSpecialIdle(Actor*);
    bool IsSpecialIdlePlaying();
    bool IsSpecialIdlePlaying(TESIdleForm*);
    bool IsSpecialIdlePlaying(BSAnimGroupSequence*);
    bool SpecialIdleLoaded();
    bool IsSpecialIdleReady();
    bool IsSequenceActive();
    void SpecialIdleFree(bool, bool);
    BSAnimGroupSequence* GetPlayingSequence();
    void ShutdownAllAnimIdles();
    static NiNode* FindKeyframeNode(NiNode*);
    static bool RemoveKeyframeControllers(NiAVObject*);
    char GetSkipNextBlend();
    void SkipNextBlend();
    void SetHavokChaseBone(NiAVObject*);
    TESIdleForm* GetSpecialIdleForm();
    BSAnimGroupSequence* GetSpecialIdleSequence();
    unsigned short GetSaveSize(TESObjectREFR*);
    void SaveGame(BGSSaveFormBuffer*);
    void SaveGame(TESObjectREFR*);
    void LoadGame(BGSLoadFormBuffer*);
    void LoadGame(TESObjectREFR*);
    void Revert(BGSLoadFormBuffer*);
    void Revert(TESObjectREFR*);
    static unsigned short GetAnimationID(TESObjectREFR*, Animation*);
    static void SaveAnimation(TESObjectREFR*, Animation*);
    static void RestoreAnimation(TESObjectREFR*, Animation*);
    static void ResetCloneCount();
    void ClearAccumRootTranslate();
    void SetGlobalTimeMultiplier(float);
    float GetGlobalTimeMultiplier();
    void SetReloadModifier(float);
    void SetEquipModifier(float);
    float GetReloadModifier();
    float GetEquipModifier();
    BSAnimGroupSequence* GetAnimationSequence(BSAnimGroupSequence*, unsigned short, int);
    BSAnimGroupSequence* GetAnimationSequence(unsigned short, int);
    void AssignControllerManager(void*);
    static void FindHighestPriorityCallback(NiAVObject*, FindData*);
    BSAnimGroupSequence* GetHighestPriority(NiAVObject*);
    bool GetMoved();
    void SetMoved(bool);
    bool GetDelayUpdateScenegraph();
    void SetDelayUpdateScenegraph(bool);
    void* __vecDelDtor(unsigned int);
    unsigned char m_uiObjectFlags;
    char _pad_1[3];
    TESObjectREFR* m_pAttachedReference;
    char m_acHeaderData[4];
    NiNode* m_pObjectNode;
    NiPoint3 m_kNodeTranslation;
    NiPoint3 m_kRootTranslation;
    char m_acNodeName[32];
    float m_fAnimationAmount;
    char group[16];
    char action[32];
    char m_acTargetName[32];
    char usReloadGroup[16];
    char m_acAnimationName[32];
    char m_cState;
    bool m_bIsPlaying;
    char _pad_ce[2];
    float time;
    float m_fTimeOffset;
    char m_acReservedBytes[4];
    void* m_pOwnerReference;
    char m_pChildTile[32];
    BSAnimGroupSequence* m_pCurrentSequence;
    char kfModelList[8];
    float m_fMovementRate;
    float m_fCombatAnimationRate;
    float m_fEquipAnimationRate;
    float m_fReloadAnimationRate;
    float m_fAnimationTimeScale;
    char m_cSkipNextBlend;
    char _pad_121[1];
    unsigned short m_usQueuedGroup;
    char LocalInput[4];
    char LocalStateValue[4];
    char LocalOutput[8];
    char m_acTrailingData[8];
};
typedef char _sizecheck_Animation[sizeof(Animation) == 316 ? 1 : -1];
struct FUN_004301b0_shell : public Animation
{
    unsigned short FUN_004301b0(int);
};

// Maps section 0x15 to 4 and 0x14 to 1, then returns the group entry at that index.
// @fnv 0x004301b0
unsigned short FUN_004301b0_shell::FUN_004301b0(int aeSection)
{
    int iIndex = aeSection;
    switch (aeSection)
    {
    case 0x15:
        iIndex = 4;
        break;
    case 0x14:
        iIndex = 1;
        break;
    }
    return ((unsigned short*)group)[iIndex];
}

extern int DAT_01015b58;
struct FUN_004308f0_stub
{
    void* ConstructExtraDataWithPointer(void* p);
};
// Constructs a BSExtraData with type 0x29, installs the vtable at DAT_01015b58, stores p at offset 0xc and returns this.
// @fnv 0x004308f0
void* FUN_004308f0_stub::ConstructExtraDataWithPointer(void* p)
{
    reinterpret_cast<BSExtraData*>(this)->BSExtraData::BSExtraData(0x29);
    *reinterpret_cast<int**>(this) = &DAT_01015b58;
    *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0xc) = p;
    return this;
}

// Returns the iLockLevelMax game setting value for the given difficulty index (0-5), or 0 if out of range.
// @fnv 0x00430bc0
int __cdecl GetLockLevelMax(int aiDifficulty)
{
    int result = 0;
    switch (aiDifficulty)
    {
    case 0:
        result = GameSettingCollection::iLockLevelMaxVeryEasy.Int()->i;
        break;
    case 1:
        result = GameSettingCollection::iLockLevelMaxEasy.Int()->i;
        break;
    case 2:
        result = GameSettingCollection::iLockLevelMaxAverage.Int()->i;
        break;
    case 3:
        result = GameSettingCollection::iLockLevelMaxHard.Int()->i;
        break;
    case 4:
        result = GameSettingCollection::iLockLevelMaxVeryHard.Int()->i;
        break;
    case 5:
        result = GameSettingCollection::iLockLevelMaxImpossible.Int()->i;
        break;
    }
    return result;
}

extern int DAT_0101589c;
struct FUN_00430c70_stub
{
    void* InitExtraDataWithPointer(void* p);
};
// Constructs a BSExtraData with type 0x2a, installs the vtable at DAT_0101589c and stores p at offset 0xc.
// @fnv 0x00430c70
void* FUN_00430c70_stub::InitExtraDataWithPointer(void* p)
{
    reinterpret_cast<BSExtraData*>(this)->BSExtraData::BSExtraData(0x2a);
    *reinterpret_cast<int**>(this) = &DAT_0101589c;
    *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0xc) = p;
    return this;
}

struct BE430
{
    char d[8];
    BE430(unsigned char);
    ~BE430();
    virtual void v0();
};
struct PSM3
{
    int a;
    PSM3();
};
struct FUN_00430f30 : BE430
{
    PSM3 m;
    FUN_00430f30();
};
// Constructs the object, initializing its BE430 base with 0x7c and default-constructing the PSM3 member.
// @fnv 0x00430f30
FUN_00430f30::FUN_00430f30() : BE430(0x7c)
{}

struct TESActorBase;
struct ExtraLeveledCreature : public BSExtraData
{
    virtual void __vslot_0();
    void __local_vftable_ctor_closure();
    TESActorBase* m_pCreatureBase;
    TESActorBase* pTemplate;
};
typedef char _sizecheck_ExtraLeveledCreature[sizeof(ExtraLeveledCreature) == 20 ? 1 : -1];

extern int DAT_01015b7c;

// @fnv 0x004311f0
ExtraLeveledCreature* __fastcall FUN_004311f0(ExtraLeveledCreature* pThis)
{
    ((BSExtraData*)pThis)->BSExtraData::BSExtraData(0x2e);
    *(void**)pThis = &DAT_01015b7c;
    pThis->m_pCreatureBase = 0;
    pThis->pTemplate = 0;
    return pThis;
}

struct BE431
{
    char d[8];
    BE431(unsigned char);
    virtual void v0();
};
struct FUN_00431230 : BE431
{
    void* m_pTeleportData;
    FUN_00431230(void* p);
};
// Constructs the object with base value 0x2b and stores the given pointer in its field.
// @fnv 0x00431230
FUN_00431230::FUN_00431230(void* p) : BE431(0x2b)
{
    m_pTeleportData = p;
}

struct MapMarkerData;
struct ExtraMapMarker : public BSExtraData
{
    virtual void __vslot_0();
    virtual bool Compare(BSExtraData*);
    void __local_vftable_ctor_closure();
    MapMarkerData* m_pMapMarkerData;
};
typedef char _sizecheck_ExtraMapMarker[sizeof(ExtraMapMarker) == 16 ? 1 : -1];

extern int DAT_01015b88;

struct FUN_00431360
{
    int pad[3];
    MapMarkerData* m_pMapMarkerData;
    FUN_00431360(MapMarkerData* pData);
};

// Constructs an ExtraMapMarker: initializes the BSExtraData base with type 0x2c, sets its vtable, and stores the MapMarkerData pointer.
// @fnv 0x00431360
FUN_00431360::FUN_00431360(MapMarkerData* pMapMarkerData)
{
    reinterpret_cast<BSExtraData*>(this)->BSExtraData::BSExtraData(0x2c);
    *reinterpret_cast<int**>(this) = &DAT_01015b88;
    m_pMapMarkerData = pMapMarkerData;
}

struct MediaLocation;
struct ExtraAudioMarker : public BSExtraData
{
    virtual void __vslot_0();
    virtual bool Compare(BSExtraData*);
    void __local_vftable_ctor_closure();
    MediaLocation* pAudioData;
};
typedef char _sizecheck_ExtraAudioMarker[sizeof(ExtraAudioMarker) == 16 ? 1 : -1];

extern int DAT_01015b94;

struct PtrWrap
{
    MediaLocation* p;
};

// Initializes an ExtraAudioMarker: constructs the BSExtraData base with type 0x90, sets its vtable, and stores the given audio data pointer.
// @fnv 0x004314c0
ExtraAudioMarker* __fastcall FUN_004314c0(ExtraAudioMarker* pThis, PtrWrap aData)
{
    pThis->BSExtraData::BSExtraData(0x90);
    *(int*)pThis = (int)&DAT_01015b94;
    pThis->pAudioData = aData.p;
    return pThis;
}

struct BGSListForm;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct ExtraDataList;
struct InventoryChanges;
struct InventoryIterator;
struct InventoryStackRecord;
struct IndexedPointerCollection;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESContainer;
struct TESLevItem;
struct TESObject;
struct TESObjectWEAP;
struct ExtraContainerChanges : public BSExtraData
{
    virtual void __vslot_0();
    InventoryChanges* pChanges;
};
typedef char _sizecheck_ExtraContainerChanges[sizeof(ExtraContainerChanges) == 16 ? 1 : -1];
struct FUN_00431830_shell : public ExtraContainerChanges
{
    void InitExtraContainerChanges(void*);
};

extern int DAT_01015bb8;

namespace n {
struct FUN_00431830_shell : public ::ExtraContainerChanges
{
    FUN_00431830_shell* InitExtraContainerChanges(void* apChanges);
};

// Initializes an ExtraContainerChanges extra-data object with type 0x15, sets its vtable, and stores the given InventoryChanges pointer.
// @fnv 0x00431830
FUN_00431830_shell* FUN_00431830_shell::InitExtraContainerChanges(void* apChanges)
{
    this->BSExtraData::BSExtraData(0x15);
    *reinterpret_cast<int**>(this) = &DAT_01015bb8;
    pChanges = static_cast<InventoryChanges*>(apChanges);
    return this;
}
}

extern int DAT_010158e4;
struct FUN_00431d10_stub
{
    void* FUN_00431d10(float p);
};
// Constructs a BSExtraData of type 0x25, sets its vtable to DAT_010158e4 and stores the float p at offset 0xc, returning this.
// @fnv 0x00431d10
void* FUN_00431d10_stub::FUN_00431d10(float afValue)
{
    reinterpret_cast<BSExtraData*>(this)->BSExtraData::BSExtraData(0x25);
    *reinterpret_cast<int**>(this) = &DAT_010158e4;
    *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xc) = afValue;
    return this;
}

extern int DAT_01015c54;

struct FUN_00432e60_helper
{
    BSExtraData base;
    int m_pEncounterZone;
    FUN_00432e60_helper();
};

// Constructs the BSExtraData base with type 0x74, installs the vtable from DAT_01015c54 and zeroes the extra field.
// @fnv 0x00432e60
FUN_00432e60_helper* __fastcall FUN_00432e60(FUN_00432e60_helper* _this)
{
    _this->base.BSExtraData::BSExtraData(0x74);
    *(int**)_this = &DAT_01015c54;
    _this->m_pEncounterZone = 0;
    return _this;
}

extern int DAT_01015c60;

// Constructs a BSExtraData with type 0x12, installs the vtable at DAT_01015c60, zeroes the field at offset 0xc, and returns pThis.
// @fnv 0x00432f00
BSExtraData* __fastcall FUN_00432f00(BSExtraData* pThis)
{
    pThis->BSExtraData::BSExtraData(0x12);
    *(int**)pThis = &DAT_01015c60;
    *(int*)((char*)pThis + 0xc) = 0;
    return pThis;
}

struct BE
{
    char d[8];
    BE(unsigned char);
    ~BE();
    virtual void v0();
};
struct SL
{
    int a;
    int b;
    SL();
};
struct FUN_004333a0 : BE
{
    SL m;
    FUN_004333a0();
};
// Constructs the object, initializing its BE base with the value 0x38.
// @fnv 0x004333a0
FUN_004333a0::FUN_004333a0() : BE(0x38)
{}

namespace fnv_00433530 {
struct BE
{
    char d[8];
    BE(unsigned char);
    ~BE();
    virtual void v0();
};
struct SL
{
    int a;
    int b;
    SL();
};
struct FUN_00433530 : BE
{
    SL m;
    FUN_00433530();
};
// Constructs the object, initializing its BE base with the value 0x52 and default-constructing the SL member m.
// @fnv 0x00433530
FUN_00433530::FUN_00433530() : BE(0x52)
{}
}  // namespace fnv_00433530

namespace fnv_00433790 {
struct BE
{
    char d[8];
    BE(unsigned char);
    ~BE();
    virtual void v0();
};
struct SL
{
    int a;
    int b;
    SL();
};
struct FUN_00433790 : BE
{
    SL m;
    float f;
    FUN_00433790();
};
// Initializes the base with 0x54 and sets the float member f to 0.0f.
// @fnv 0x00433790
FUN_00433790::FUN_00433790() : BE(0x54)
{
    f = 0.0f;
}
}  // namespace fnv_00433790

struct ReflectedReferenceRecord;
struct ExtraReflectedRefs : public BSExtraData
{
    virtual void __vslot_0();
    void InitItem(TESForm*);
    virtual bool Compare(BSExtraData*);
    void Copy(BSExtraData*);
    void ClearReferenceData();
    ReflectedReferenceRecord* GetRefData(TESObjectREFR*);
    void RemoveReference(TESObjectREFR*);
    void AssignReferencedObject(TESObjectREFR*, unsigned int);
    void __local_vftable_ctor_closure();
    char RefList[8];
};
typedef char _sizecheck_ExtraReflectedRefs[sizeof(ExtraReflectedRefs) == 20 ? 1 : -1];
struct FUN_004348a0_shell : public ExtraReflectedRefs
{
    void AddReflectedRef(TESObjectREFR*, unsigned int);
};

class RecursiveSpinLock
{
  public:
    unsigned int m_uiOwningThreadID;
    unsigned int m_uiRecursionCount;
    RecursiveSpinLock();
};

// Finds or creates the reflected-ref entry for apRef, adds it to RefList, and stores aiEffectFlags in the entry.
// @fnv 0x004348a0
void FUN_004348a0_shell::AddReflectedRef(TESObjectREFR* apRef, unsigned int aiEffectFlags)
{
    ReferenceIntersectionData* pEntry = ((ExtraDecalRefs*)this)->FindDecalReference(apRef);
    if (!pEntry)
    {
        pEntry = (ReferenceIntersectionData*)(new RecursiveSpinLock);
        pEntry->m_pHitReference = apRef;
        ((BSSimpleList<const char*>&)RefList).AddHead((const char*&)pEntry);
    }
    ((unsigned int*)pEntry)[1] = aiEffectFlags;
}

struct ExtraMerchantContainer : public BSExtraData
{
    virtual void __vslot_0();
    virtual bool Compare(BSExtraData*);
    void __local_vftable_ctor_closure();
    TESObjectREFR* pContainer;
};
typedef char _sizecheck_ExtraMerchantContainer[sizeof(ExtraMerchantContainer) == 16 ? 1 : -1];

extern int DAT_01015e04;

// Constructs an ExtraMerchantContainer: initializes the BSExtraData base with type 0x3c, sets the vtable, and clears pContainer.
// @fnv 0x00434fc0
ExtraMerchantContainer* __fastcall ExtraMerchantContainerCtor(ExtraMerchantContainer* pThis)
{
    pThis->BSExtraData::BSExtraData(0x3c);
    *(int**)pThis = &DAT_01015e04;
    pThis->pContainer = 0;
    return pThis;
}

struct ExtraLevCreaModifier : public BSExtraData
{
    virtual void __vslot_0();
    virtual bool Compare(BSExtraData*);
    float GetMultiplier();
    int GetAllBelowForce();
    void __local_vftable_ctor_closure();
    int m_iModifier;
};
typedef char _sizecheck_ExtraLevCreaModifier[sizeof(ExtraLevCreaModifier) == 16 ? 1 : -1];

extern int DAT_01015e10;

// @fnv 0x00435040
ExtraLevCreaModifier* __fastcall ExtraLevCreaModifierCtor(ExtraLevCreaModifier* _this)
{
    _this->BSExtraData::BSExtraData(0x1E);
    *(int**)_this = &DAT_01015e10;
    _this->m_iModifier = 4;
    return _this;
}

namespace fnv_004350c0 {
struct ExtraLevCreaModifier : public BSExtraData
{
    virtual void __vslot_0();
    virtual bool Compare(BSExtraData*);
    float GetMultiplier();
    int GetAllBelowForce();
    void __local_vftable_ctor_closure();
    int m_iModifier;
};
typedef char _sizecheck_ExtraLevCreaModifier[sizeof(ExtraLevCreaModifier) == 16 ? 1 : -1];
struct FUN_004350c0_shell : public ExtraLevCreaModifier
{
    float FUN_004350c0();
};

extern SettingT_GameSettingCollection_* DAT_01184ab0[];

// @fnv 0x004350c0
float FUN_004350c0_shell::FUN_004350c0()
{
    float fretval = 1.0f;
    if (m_iModifier != 4)
        fretval = DAT_01184ab0[m_iModifier]->Float()->f;
    return fretval;
}
}  // namespace fnv_004350c0

namespace fnv_00435100 {
struct ExtraLevCreaModifier : public BSExtraData
{
    virtual void __vslot_0();
    virtual bool Compare(BSExtraData*);
    float GetMultiplier();
    int GetAllBelowForce();
    void __local_vftable_ctor_closure();
    int m_iModifier;
};
typedef char _sizecheck_ExtraLevCreaModifier[sizeof(ExtraLevCreaModifier) == 16 ? 1 : -1];
struct FUN_00435100_shell : public ExtraLevCreaModifier
{
    int FUN_00435100();
};

// @fnv 0x00435100
int FUN_00435100_shell::FUN_00435100()
{
    int iretval = 0;
    switch (m_iModifier)
    {
    case 4:
        iretval = 0;
        break;
    case 0:
        iretval = 1;
        break;
    default:
        iretval = -1;
        break;
    }
    return iretval;
}
}  // namespace fnv_00435100

struct FUN_004352a0_cls : public BSExtraData
{
    virtual ~FUN_004352a0_cls();
    char* p;
};
// @fnv 0x004352a0
FUN_004352a0_cls::~FUN_004352a0_cls()
{
    operator delete(p);
}

struct ExtraXTarget : public BSExtraData
{
    virtual void __vslot_0();
    virtual bool Compare(BSExtraData*);
    void __local_vftable_ctor_closure();
    TESObjectREFR* pTarget;
};
typedef char _sizecheck_ExtraXTarget[sizeof(ExtraXTarget) == 16 ? 1 : -1];

extern int DAT_01015e28;

// Initializes an ExtraXTarget: constructs the BSExtraData base with type 0x44, sets its vtable, and clears pTarget.
// @fnv 0x00435370
ExtraXTarget* __fastcall ConstructExtraXTarget(ExtraXTarget* pThis)
{
    pThis->BSExtraData::BSExtraData(0x44);
    *(int**)pThis = &DAT_01015e28;
    pThis->pTarget = 0;
    return pThis;
}

struct ExtraEmittanceSource : public BSExtraData
{
    virtual void __vslot_0();
    virtual bool Compare(BSExtraData*);
    void __local_vftable_ctor_closure();
    TESForm* pSource;
};
typedef char _sizecheck_ExtraEmittanceSource[sizeof(ExtraEmittanceSource) == 16 ? 1 : -1];

// @fnv 0x00435440
ExtraEmittanceSource* __fastcall InitExtraEmittanceSource(ExtraEmittanceSource* this_ptr)
{
    this_ptr->BSExtraData::BSExtraData(0x67);
    *(const char**)this_ptr = "pTC";
    this_ptr->pSource = 0;
    return this_ptr;
}

struct BGSLoadFormBuffer;
struct BGSLoadGameBuffer;
struct BGSSaveFormBuffer;
struct BGSSaveGameBuffer;
struct BGSLoadGameSubBuffer
{
    void SetBuffer(char*);
    void ResetReadPosition();
    void RestoreAnimation(TESForm*);
    void ReadAnimationState(TESForm*);
    void LoadHavokData(TESForm*);
    void SaveAnimation(TESForm*);
    void SaveFormState(TESForm*);
    void SaveGame(BGSSaveGameBuffer*);
    void LoadGame(BGSLoadGameBuffer*);
    BGSLoadFormBuffer* CreateFormBuffer(TESForm*);
    void RenderCopyData(BGSSaveFormBuffer*);
    char* pBuffer;
};
typedef char _sizecheck_BGSLoadGameSubBuffer[sizeof(BGSLoadGameSubBuffer) == 4 ? 1 : -1];
struct FUN_00435b20_shell : public BGSLoadGameSubBuffer
{
    void FUN_00435b20();
};

// Deletes the buffer pointed to by pBuffer and sets pBuffer to null.
// @fnv 0x00435b20
void FUN_00435b20_shell::FUN_00435b20()
{
    delete pBuffer;
    pBuffer = 0;
}

struct FUN_00435de0_ctor : public CombatTargetTimestamp
{
    void* FUN_00435de0(float afValue);
};

// @fnv 0x00435de0
void* FUN_00435de0_ctor::FUN_00435de0(float afValue)
{
    fTimeStamp = afValue;
    return this;
}

namespace fnv_00436cb0 {
class RecursiveSpinLock
{
  public:
    RecursiveSpinLock();
    int a;
    int b;
};

struct FUN_00436cb0_cls : public BSExtraData
{
    FUN_00436cb0_cls();
    virtual ~FUN_00436cb0_cls();
    RecursiveSpinLock* pLock;
};

// @fnv 0x00436cb0
FUN_00436cb0_cls::FUN_00436cb0_cls() : BSExtraData(0x5E)
{
    pLock = new RecursiveSpinLock();
}
}  // namespace fnv_00436cb0

struct FUN_00437010_item
{
    int* p;
    char c;
};
struct FUN_00437010_node
{
    FUN_00437010_item** _ref_006815c0();
    FUN_00437010_node* _ref_00726070();
};
struct FUN_00437010_stub
{
    int pad[3];
    FUN_00437010_node* list;
    bool ContainsKey(int* key);
};
// Walks the linked list from list, returning true when an item's p equals key and its c is non-negative, otherwise false.
// @fnv 0x00437010
bool FUN_00437010_stub::ContainsKey(int* key)
{
    FUN_00437010_node* n = list;
    while (n != 0 && *n->_ref_006815c0() != 0)
    {
        FUN_00437010_item* pItem = *n->_ref_006815c0();
        if (key == reinterpret_cast<int*>(pItem->p) && pItem->c > -1)
            return true;
        n = n->_ref_00726070();
    }
    return false;
}

struct FUN_00437240_Struct
{
    float f0;
    int i4;
    float f8;
    int iC;

    void FUN_00437240(FUN_00437240_Struct* other);
};

// Copies the four fields of other into this struct when other is non-null.
// @fnv 0x00437240
void FUN_00437240_Struct::FUN_00437240(FUN_00437240_Struct* pSource)
{
    if (pSource)
    {
        f0 = pSource->f0;
        i4 = pSource->i4;
        f8 = pSource->f8;
        iC = pSource->iC;
    }
}

struct TESTopicInfo;
struct ExtraSayToTopicInfo : public BSExtraData
{
    virtual void __vslot_0();
    void SetTopic(TESTopic*);
    void SetVoiceDone(bool);
    void __local_vftable_ctor_closure();
    TESTopicInfo* pInfo;
    TESTopic* pTopic;
    unsigned int m_uiTopicInfoValue;
    bool m_bTopicInfoFlag;
    char _pad_19[3];
};
typedef char _sizecheck_ExtraSayToTopicInfo[sizeof(ExtraSayToTopicInfo) == 28 ? 1 : -1];

extern int DAT_01015f48;

// @fnv 0x00437690
ExtraSayToTopicInfo* __fastcall ExtraSayToTopicInfoConstructor(ExtraSayToTopicInfo* pThis)
{
    pThis->BSExtraData::BSExtraData(0x75);
    *(void**)pThis = &DAT_01015f48;
    pThis->pInfo = 0;
    pThis->pTopic = 0;
    pThis->m_uiTopicInfoValue = 0;
    pThis->m_bTopicInfoFlag = false;
    return pThis;
}

struct ExtraIgnoredBySandbox : public BSExtraData
{
    virtual void __vslot_0();
    void __local_vftable_ctor_closure();
};
typedef char _sizecheck_ExtraIgnoredBySandbox[sizeof(ExtraIgnoredBySandbox) == 12 ? 1 : -1];

extern int DAT_01015f64;

struct FUN_00437970_shell : public ExtraIgnoredBySandbox
{
    FUN_00437970_shell* FUN_00437970();
};

// Initializes a BSExtraData-derived object with type 0x80 and installs its vtable pointer.
// @fnv 0x00437970
FUN_00437970_shell* FUN_00437970_shell::FUN_00437970()
{
    this->BSExtraData::BSExtraData(0x80);
    *(int**)this = &DAT_01015f64;
    return this;
}

struct FUN_00437b90_shell : public TESForm
{
    bool FUN_00437b90();
};

// @fnv 0x00437b90
bool FUN_00437b90_shell::FUN_00437b90()
{
    return (*(unsigned int*)((char*)this + 8) & 0x820) ? true : false;
}

struct FUN_00437bb0_Class
{
    char pad[0x87];
    bool val;
    bool GetRunsInLow();
};

// @fnv 0x00437bb0
bool __fastcall FUN_00437bb0(FUN_00437bb0_Class* pThis)
{
    return pThis->val;
}

struct FUN_00437bd0_stub
{
    int FUN_004f8960();
    char FUN_00437bd0();
};
// @fnv 0x00437bd0
char FUN_00437bd0_stub::FUN_00437bd0()
{
    return FUN_004f8960() == 3;
}

struct FUN_00437bf0_shell : public Actor
{
    bool FUN_00437bf0();
};

int __fastcall FUN_004f8960(void*);

// @fnv 0x00437bf0
bool FUN_00437bf0_shell::FUN_00437bf0()
{
    return FUN_004f8960(this) == 5 ? true : false;
}

struct NiFixedString
{
    bool Exists();
    unsigned int GetLength();
    unsigned int GetRefCount();
    bool Equals(char*);
    bool EqualsNoCase(char*);
    bool Contains(char*);
    bool HasSuffix(char*);
    unsigned int QHandle();
    void Init();
    void* __vecDelDtor(unsigned int);
    char* m_kHandle;
};
typedef char _sizecheck_NiFixedString[sizeof(NiFixedString) == 4 ? 1 : -1];
struct FUN_004381b0_shell : public NiFixedString
{
    void FUN_004381b0();
};

void __cdecl FUN_004381d0(void*);

// @fnv 0x004381b0
void FUN_004381b0_shell::FUN_004381b0()
{
    FUN_004381d0(this);
}

class NiNode;
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer<T>& operator=(T* pObject);
};

struct FUN_00438230_Class
{
    char pad0[0x38];
    int field_38;
    char pad1[0x60 - 0x3C];
    NiPointer<NiNode> field_60;

    void FUN_00438230(NiNode* pNode);
};

// Stores pNode in field_60 and resets field_38 to 0.
// @fnv 0x00438230
void FUN_00438230_Class::FUN_00438230(NiNode* pNode)
{
    field_60 = pNode;
    field_38 = 0;
}

struct PositionRotation
{
    void Endian();
    NiPoint3 pos;
    NiPoint3 rot;
};
typedef char _sizecheck_FILE_POS_ROT[sizeof(PositionRotation) == 24 ? 1 : -1];
struct FUN_00692710_shell : public PositionRotation
{
    void FUN_00692710();
};

void __fastcall _ref_006815c0(void*);

// @fnv 0x00692710
void* __fastcall FUN_00692710(PositionRotation* pThis)
{
    _ref_006815c0(&pThis->pos);
    _ref_006815c0(&pThis->rot);
    return pThis;
}

struct ScriptLocals
{
    ~ScriptLocals();
};
struct FUN_00432040_holder : public BSExtraData
{
    void* pScript;
    ScriptLocals* pLocals;
    ~FUN_00432040_holder();
};
// Destructor that deletes the ScriptLocals object pointed to by pLocals and clears the pointer.
// @fnv 0x00432040
FUN_00432040_holder::~FUN_00432040_holder()
{
    delete pLocals;
    pLocals = 0;
}

struct FUN_00432650_mem
{
    FUN_00432650_mem();
};
struct FUN_00432650_holder : public BE
{
    FUN_00432650_mem m;
    FUN_00432650_holder();
    virtual void v0();
};
// Constructs the holder, initializing its base BE with size 0x18 and default-constructing member m.
// @fnv 0x00432650
FUN_00432650_holder::FUN_00432650_holder() : BE(0x18)
{}

struct ListX
{
    ~ListX();
    char d[12];
};
struct BSS
{
    ~BSS();
    char d[8];
};
struct FUN_00433970_holder;
void __cdecl FUN_00433750(ListX*);
struct FUN_00433970_holder : public BSExtraData
{
    ListX l;
    BSS s;
    ~FUN_00433970_holder();
};
// @fnv 0x00433970
FUN_00433970_holder::~FUN_00433970_holder()
{
    FUN_00433750(&l);
}

unsigned int __cdecl BSStringLength(const char*);
int __cdecl strcpy_s(char*, unsigned int, const char*);
struct FUN_004351d0_holder : public BE
{
    char* pName;
    FUN_004351d0_holder(const char* s);
    virtual void v0();
};
// Copies the C string s into a newly allocated buffer sized to its length plus one.
// @fnv 0x004351d0
FUN_004351d0_holder::FUN_004351d0_holder(const char* apName) : BE(0x41)
{
    unsigned int n = BSStringLength(apName) + 1;
    pName = (char*)operator new(n);
    strcpy_s(pName, n, apName);
}

struct GO
{
    GO(int);
    ~GO();
};
struct NP_0081c630
{
    NP_0081c630& operator=(void*);
};
struct FUN_004357a0_holder : public BE
{
    GO m;
    FUN_004357a0_holder();
    virtual void v0();
};
// Constructs the holder: initializes base BE with 0x71, constructs m with 0, then assigns 0 to m via NP_0081c630.
// @fnv 0x004357a0
FUN_004357a0_holder::FUN_004357a0_holder() : BE(0x71), m(0)
{
    ((NP_0081c630*)&m)->operator=(0);
}

struct FUN_004379a0_holder : public BE
{
    unsigned int User;
    FUN_004379a0_holder(TESForm* p);
    virtual void v0();
};
// @fnv 0x004379a0
FUN_004379a0_holder::FUN_004379a0_holder(TESForm* apForm) : BE(0x88)
{
    User = apForm ? apForm->GetFormID() : 0;
}

void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_00431390(unsigned int flags);
};
// @fnv 0x00431390
void* DelStandIn::FUN_00431390(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}

namespace fnv_00431860 {
void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_00431860(unsigned int flags);
};
// @fnv 0x00431860
void* DelStandIn::FUN_00431860(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}
}  // namespace fnv_00431860

namespace fnv_00431920 {
void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_00431920(unsigned int flags);
};
// @fnv 0x00431920
void* DelStandIn::FUN_00431920(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}
}  // namespace fnv_00431920

namespace fnv_00432c60 {
void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_00432c60(unsigned int flags);
};
// @fnv 0x00432c60
void* DelStandIn::FUN_00432c60(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}
}  // namespace fnv_00432c60

namespace fnv_00433940 {
void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_00433940(unsigned int flags);
};
// @fnv 0x00433940
void* DelStandIn::FUN_00433940(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}
}  // namespace fnv_00433940

namespace fnv_00435270 {
void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_00435270(unsigned int flags);
};
// @fnv 0x00435270
void* DelStandIn::FUN_00435270(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}
}  // namespace fnv_00435270

namespace fnv_00437a60 {
void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_00437a60(unsigned int flags);
};
// Calls FUN_0083dec0 on this, frees this when flags has bit 0 set, and returns this.
// @fnv 0x00437a60
void* DelStandIn::FUN_00437a60(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}
}  // namespace fnv_00437a60

namespace fnv_00430780 {
struct P3
{
    float x, y, z;
};
struct BE
{
    void* vp;
    int pad[2];
    BE(unsigned char);
    ~BE();
};
struct RefStand
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
    virtual P3* GetPos();
};
struct TESRecipe
{
    P3* GetData();
};
struct FPR
{
    void FUN_00692710();
    P3 pos;
    P3 rot;
};
extern void* DAT_01015b40[];
struct FUN_00430780_obj : public BE
{
    FPR uiTimestamp;
    FUN_00430780_obj(RefStand* apRef);
};
// Initialises the base with 0xf, sets the vtable, calls FUN_00692710, then copies the ref's position and the recipe's data into the FPR.
// @fnv 0x00430780
FUN_00430780_obj::FUN_00430780_obj(RefStand* apRef) : BE(0xf)
{
    *(void***)this = DAT_01015b40;
    uiTimestamp.FUN_00692710();
    uiTimestamp.pos = *apRef->GetPos();
    uiTimestamp.rot = *((TESRecipe*)apRef)->GetData();
}
}  // namespace fnv_00430780

namespace fnv_00430dd0 {
struct BE
{
    BE(unsigned char);
    ~BE();
    virtual void vslot0();
    unsigned char t;
    unsigned char pad[3];
    BE* pNext;
};
struct SL
{
    SL();
    void* a;
    void* b;
};
extern unsigned int _data_011c16bc;

struct FUN_00430dd0 : public BE
{
    SL* m_pLinkedObject;
    FUN_00430dd0();
    virtual void vslot0();
};

// @fnv 0x00430dd0
FUN_00430dd0::FUN_00430dd0() : BE(0x1d)
{
    m_pLinkedObject = new SL;
}
}  // namespace fnv_00430dd0

struct TeleportableReference;
struct ExtraTeleport : public BSExtraData
{
    virtual void __vslot_0();
    virtual bool Compare(BSExtraData*);
    void __local_vftable_ctor_closure();
    TeleportableReference* m_pTeleportData;
};
typedef char _sizecheck_ExtraTeleport[sizeof(ExtraTeleport) == 16 ? 1 : -1];
struct FUN_00431260_shell : public ExtraTeleport
{
    void FUN_00431260();
};

struct Dummy_00419220
{
    void* DeleteIfFlagged(int);
};
struct FUN_00431260 : public BSExtraData
{
    TeleportableReference* pData;
    virtual ~FUN_00431260();
};
extern unsigned int _data_011c16bc;

// @fnv 0x00431260
FUN_00431260::~FUN_00431260()
{
    Dummy_00419220* pOld = (Dummy_00419220*)pData;
    Dummy_00419220* pTemp = pOld;
    pTemp ? pTemp->DeleteIfFlagged(1) : (void*)0;
}

struct FUN_00437ab0_shell : public ExtraPatrolRefInUseData
{
    bool FUN_00437ab0(void*);
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
    virtual bool IsX();
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void w6();
    virtual void w7();
    virtual void w8();
    virtual void w9();
    virtual void w10();
    virtual void w11();
    virtual void w12();
    virtual void w13();
    virtual void w14();
    virtual void w15();
    virtual void w16();
    virtual void w17();
    virtual void w18();
    virtual void w19();
    virtual void w20();
    virtual void w21();
    virtual void w22();
    virtual void w23();
    virtual void w24();
    virtual void w25();
    virtual void w26();
    virtual void w27();
    virtual void w28();
    virtual void w29();
    virtual void w30();
    virtual void w31();
    virtual void w32();
    virtual void w33();
    virtual void w34();
    virtual void w35();
    virtual void w36();
    virtual void w37();
    virtual void w38();
    virtual void w39();
    virtual void w40();
    virtual void w41();
    virtual void w42();
    virtual void w43();
    virtual void w44();
    virtual void w45();
    virtual void w46();
    virtual void w47();
    virtual void w48();
    virtual void w49();
    virtual void w50();
    virtual void w51();
    virtual void w52();
    virtual void w53();
    virtual void w54();
    virtual void w55();
    virtual void w56();
    virtual void w57();
    virtual void w58();
    virtual void w59();
    virtual void w60();
    virtual void w61();
    virtual void w62();
    virtual void w63();
    virtual void w64();
    virtual void w65();
    virtual void w66();
    virtual void w67();
    virtual void w68();
    virtual void w69();
    virtual void w70();
    virtual void w71();
    virtual void w72();
    virtual void w73();
    virtual bool Cb(int);
    bool FUN_00437b90();
};
struct MobileObject : public RefX
{
    unsigned int GetCurrentProcessLevel();
};
struct ActorX : public MobileObject
{
    bool FUN_00437bd0();
    bool FUN_00437bf0();
};
TESForm* GetFormByID(unsigned int);
bool __fastcall FUN_00437bb0(ActorX*);
// @fnv 0x00437ab0
bool FUN_00437ab0_shell::FUN_00437ab0(void* apPotentialUser)
{
    if (apPotentialUser && ((TESForm*)apPotentialUser)->GetFormID() == *(unsigned int*)((char*)this + 0xc))
        return true;
    RefX* pref = (RefX*)GetFormByID(*(unsigned int*)((char*)this + 0xc));
    if (!pref || pref->Cb(0) || pref->FUN_00437b90())
    {
        *(unsigned int*)((char*)this + 0xc) = 0;
        return true;
    }
    if (pref->IsX())
    {
        ActorX* pactor = (ActorX*)pref;
        if (pactor->FUN_00437bf0() || pactor->FUN_00437bd0() ||
            (pactor->GetCurrentProcessLevel() && !FUN_00437bb0(pactor)))
        {
            *(unsigned int*)((char*)this + 0xc) = 0;
            return true;
        }
    }
    return false;
}

struct FUN_0041ca90
{
    int get();
};
// @fnv 0x0041ca90
int FUN_0041ca90::get()
{
    return *(signed char*)((char*)this + 0x20);
}

struct FUN_0042ff80_s
{
    void FUN_0042ff80();
};
struct FUN_004303c0
{
    void run();
};
// @fnv 0x004303c0
void FUN_004303c0::run()
{
    ((FUN_0042ff80_s*)((char*)this + 4))->FUN_0042ff80();
}

struct MapMarkerData
{
    ~MapMarkerData();
};
struct FUN_004313c0 : public BSExtraData
{
    MapMarkerData* m_pMapMarkerData;
    virtual ~FUN_004313c0();
};
// Destructor that deletes the owned MapMarkerData pointer.
// @fnv 0x004313c0
FUN_004313c0::~FUN_004313c0()
{
    delete m_pMapMarkerData;
}

struct FUN_004319b0 : public BSExtraData
{
    virtual ~FUN_004319b0();
};
// @fnv 0x004319b0
FUN_004319b0::~FUN_004319b0()
{}

struct List_009e03e0
{
    void RemoveAll();
};
struct FUN_00434fa0
{
    void run();
};
// @fnv 0x00434fa0
void FUN_00434fa0::run()
{
    ((List_009e03e0*)((char*)this + 0xc))->RemoveAll();
}

struct FUN_004353d0 : public BSExtraData
{
    virtual ~FUN_004353d0();
};
// @fnv 0x004353d0
FUN_004353d0::~FUN_004353d0()
{}

struct FUN_004354a0 : public BSExtraData
{
    virtual ~FUN_004354a0();
};
// @fnv 0x004354a0
FUN_004354a0::~FUN_004354a0()
{}

struct B006815c0
{
    B006815c0();
};
struct FUN_006d5320
{
    int a;
    B006815c0 b;
    FUN_006d5320();
};
// @fnv 0x006d5320
FUN_006d5320::FUN_006d5320()
{}

struct GarbageCollectorDeleteA
{
    ~GarbageCollectorDeleteA();
};
struct FUN_00430120 : public BSExtraData
{
    GarbageCollectorDeleteA* pData;
    virtual ~FUN_00430120();
};
// @fnv 0x00430120
FUN_00430120::~FUN_00430120()
{
    delete pData;
}

namespace fnv_00430390 {
void _Deallocate(void* p);

struct FUN_004303c0
{
    void run();
    void* FUN_00430390(unsigned int flags);
};

// Runs the object's run() method, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00430390
void* FUN_004303c0::FUN_00430390(unsigned int flags)
{
    run();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_00430390

struct ExtraLight
{
    virtual ~ExtraLight();
    void* FUN_00430920(unsigned int flags);
};

// Destroys the object and, if the flags bit 0 is set, frees its memory, then returns the pointer.
// @fnv 0x00430920
void* ExtraLight::FUN_00430920(unsigned int flags)
{
    ExtraLight::~ExtraLight();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_00418f10
{
    ~FUN_00418f10();
};
struct FUN_00430950 : public BSExtraData
{
    FUN_00418f10* pData;
    virtual ~FUN_00430950();
};
// @fnv 0x00430950
FUN_00430950::~FUN_00430950()
{
    delete pData;
}

extern "C" void __cdecl _Deallocate(void*);

struct ExtraFollower
{
    void __thiscall FUN_00430ea0();
    void* __thiscall FUN_00430e70(unsigned int flags);
};

void __thiscall ExtraFollower::FUN_00430ea0()
{}

// Calls FUN_00430ea0, then frees this when flags has bit 0 set, and returns this.
// @fnv 0x00430e70
void* __thiscall ExtraFollower::FUN_00430e70(unsigned int flags)
{
    FUN_00430ea0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_004314f0 {
struct ExtraAudioMarker
{
    void FUN_00431520();
    void* FUN_004314f0(unsigned int flags);
};
extern "C" void* __cdecl _Deallocate(void*);

// Calls FUN_00431520 on this, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x004314f0
void* ExtraAudioMarker::FUN_004314f0(unsigned int flags)
{
    this->FUN_00431520();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_004314f0

struct FUN_00419480
{
    ~FUN_00419480();
};
struct FUN_00431520 : public BSExtraData
{
    FUN_00419480* pData;
    virtual ~FUN_00431520();
};
// @fnv 0x00431520
FUN_00431520::~FUN_00431520()
{
    delete pData;
}

struct Date
{
    ~Date();
};
struct FUN_00431680 : public BSExtraData
{
    Date* pData;
    virtual ~FUN_00431680();
};
// @fnv 0x00431680
FUN_00431680::~FUN_00431680()
{
    delete pData;
}

namespace fnv_00431890 {
extern int DAT_01015bb8;
extern int _data_011c16bc;
struct InventoryChanges
{
    ~InventoryChanges();
};
struct FUN_00431890 : public BSExtraData
{
    InventoryChanges* pChanges;
    virtual ~FUN_00431890();
};
// Destructor for a BSExtraData subclass that deletes its InventoryChanges pointer.
// @fnv 0x00431890
FUN_00431890::~FUN_00431890()
{
    delete pChanges;
}
}  // namespace fnv_00431890

namespace fnv_00431950 {
struct BE
{
    BE(unsigned char);
};

struct FUN_00431950 : BE
{
    void* m_pWorldReferenceInfo;
    FUN_00431950(void* apRef);
};

extern const void* vftable_FUN_004319b0;

// Initialises the object's vtable pointer and stores apRef at offset 0xc after constructing the BE base with 0x20.
// @fnv 0x00431950
FUN_00431950::FUN_00431950(void* apRef) : BE(0x20)
{
    *reinterpret_cast<void**>(this) = &vftable_FUN_004319b0;
    *(void**)(reinterpret_cast<char*>(this) + 0xc) = apRef;
}
}  // namespace fnv_00431950

namespace fnv_004322c0 {
extern int DAT_01015bd0;
struct BE
{
    BE(unsigned char);
    virtual ~BE();
    void* pNext;
    unsigned char cType;
};
struct FUN_004322c0 : public BE
{
    FUN_004322c0();
    virtual ~FUN_004322c0();
};
// @fnv 0x004322c0
FUN_004322c0::FUN_004322c0() : BE(31)
{}
}  // namespace fnv_004322c0

namespace fnv_00432320 {
struct BE
{
    BE(unsigned char);
    virtual ~BE();
    void* pNext;
    unsigned char cType;
};
struct FUN_00432320 : public BE
{
    FUN_00432320();
    virtual ~FUN_00432320();
};
// Constructs a BE with type 23 by delegating to the BE(unsigned char) constructor.
// @fnv 0x00432320
FUN_00432320::FUN_00432320() : BE(23)
{}
}  // namespace fnv_00432320

namespace fnv_00432350 {
extern int DAT_01015bf4;

class BE
{
  public:
    BE(unsigned char);
};

struct FUN_00432350 : BE
{
    FUN_00432350();
};

// @fnv 0x00432350
FUN_00432350::FUN_00432350() : BE(0x3e)
{
    *reinterpret_cast<void**>(this) = reinterpret_cast<void*>(&DAT_01015bf4);
}
}  // namespace fnv_00432350

struct FUN_00425ff0
{
    ~FUN_00425ff0();
};
struct FUN_004323b0 : public BSExtraData
{
    FUN_00425ff0* pData;
    virtual ~FUN_004323b0();
};
// Clears the flag at offset 0x24 of pData and deletes pData.
// @fnv 0x004323b0
FUN_004323b0::~FUN_004323b0()
{
    *reinterpret_cast<bool*>(reinterpret_cast<char*>(pData) + 0x24) = false;
    delete pData;
}

namespace fnv_004326c0 {
extern int _data_011c16bc;
struct TESWorldSpace;
struct BE
{
    BE(unsigned char);
    virtual ~BE();
    void* pNext;
    unsigned char cType;
};
struct FUN_006d5320
{
    FUN_006d5320();
    void* m_pPathingCell;
    NiPoint3 kPos;
    float fRot;
};
struct FUN_004326c0 : public BE
{
    FUN_006d5320 m_kWorldPlacementData;
    FUN_004326c0(TESWorldSpace* apWorld, TESObjectCELL* apIntCell, const NiPoint3* aPt, float afzrotation);
    virtual ~FUN_004326c0();
};
// @fnv 0x004326c0
FUN_004326c0::FUN_004326c0(TESWorldSpace* apWorld, TESObjectCELL* apIntCell, const NiPoint3* aPt, float afzrotation)
    : BE(24)
{
    if (apWorld)
        m_kWorldPlacementData.m_pPathingCell = apWorld;
    else
        m_kWorldPlacementData.m_pPathingCell = apIntCell;
    m_kWorldPlacementData.kPos = *aPt;
    m_kWorldPlacementData.fRot = afzrotation;
}
}  // namespace fnv_004326c0

extern "C" int memcmp(const void*, const void*, unsigned int);

struct ExtraPackageStartLocation : BSExtraData
{
    ExtraPackageStartLocation(unsigned char aEtype);
    bool FUN_00432770(BSExtraData*);
};

// @fnv 0x00432770
bool ExtraPackageStartLocation::FUN_00432770(BSExtraData* apCompare)
{
    ExtraPackageStartLocation* pComp = dynamic_cast<ExtraPackageStartLocation*>(apCompare);
    if (pComp == 0)
        return true;
    if (BSExtraData::Compare(apCompare))
        return true;
    if (memcmp((void*)((char*)this + 0xc), (void*)((char*)pComp + 0xc), 0x14) != 0)
        return true;
    return false;
}

namespace fnv_004327e0 {
extern int DAT_01015938;

class BE
{
  public:
    BE(unsigned char);
};

class TESObjectREFR;

struct FUN_004327e0 : BE
{
    TESObjectREFR* pRef;
    FUN_004327e0(TESObjectREFR*);
};

// @fnv 0x004327e0
FUN_004327e0::FUN_004327e0(TESObjectREFR* a_refr) : BE(0x1c)
{
    *reinterpret_cast<void**>(this) = &DAT_01015938;
    *reinterpret_cast<TESObjectREFR**>(reinterpret_cast<char*>(this) + 0xc) = a_refr;
}
}  // namespace fnv_004327e0

struct ExtraPlayerCrimeList
{
    void FUN_00432b50();
    void* FUN_00432a70(unsigned int flags);
};

extern "C" void __cdecl _Deallocate(void*);

// Calls FUN_00432b50, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00432a70
void* __thiscall ExtraPlayerCrimeList::FUN_00432a70(unsigned int flags)
{
    this->FUN_00432b50();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_00432b50 {
struct List_009e03e0
{
    ~List_009e03e0();
};
struct FUN_00432b50 : public BSExtraData
{
    List_009e03e0* pData;
    virtual ~FUN_00432b50();
};
// Destructor for a BSExtraData subclass that deletes its owned pData list.
// @fnv 0x00432b50
FUN_00432b50::~FUN_00432b50()
{
    delete pData;
}
}  // namespace fnv_00432b50

struct FUN_00432da0
{
    ~FUN_00432da0();
};
struct FUN_00432d10 : public BSExtraData
{
    FUN_00432da0* pData;
    virtual ~FUN_00432d10();
};
// Destructor for an extra-data object that deletes its owned pData pointer.
// @fnv 0x00432d10
FUN_00432d10::~FUN_00432d10()
{
    delete pData;
}

struct RagDollDataShim
{
    bool FUN_004d9780(RagDollData* apOther);
};
struct FUN_00432dd0_shell : public ExtraRagDollData
{
    bool CompareRagDollData(BSExtraData* apCompare);
};
// @fnv 0x00432dd0
bool FUN_00432dd0_shell::CompareRagDollData(BSExtraData* apCompare)
{
    ExtraRagDollData* pcomp;

    pcomp = dynamic_cast<ExtraRagDollData*>(apCompare);
    if (!pcomp)
    {
        return true;
    }
    if (BSExtraData::Compare(apCompare))
    {
        return true;
    }
    if (!m_pRagDollData)
    {
        if (pcomp->m_pRagDollData)
        {
            return true;
        }
    }
    else if (reinterpret_cast<RagDollDataShim*>(m_pRagDollData)->FUN_004d9780(pcomp->m_pRagDollData))
    {
        return true;
    }
    return false;
}

struct ExtraRandomTeleportMarker : BSExtraData
{
    TESObjectREFR* pTeleportMarker;
    bool __thiscall FUN_004334e0(BSExtraData* apCompare);
};

// @fnv 0x004334e0
bool __thiscall ExtraRandomTeleportMarker::FUN_004334e0(BSExtraData* apCompare)
{
    ExtraRandomTeleportMarker* pcomp = dynamic_cast<ExtraRandomTeleportMarker*>(apCompare);
    if (!pcomp)
        return true;
    if (pcomp->pTeleportMarker != this->pTeleportMarker)
        return true;
    return false;
}

namespace fnv_004335a0 {
struct ExtraLinkedRefChildren
{
    void FUN_004335d0();
    void* __thiscall FUN_004335a0(unsigned int flags);
};

extern "C" void* __cdecl _Deallocate(void* p);

// Calls FUN_004335d0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x004335a0
void* __thiscall ExtraLinkedRefChildren::FUN_004335a0(unsigned int flags)
{
    FUN_004335d0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_004335a0

struct ExtraLinkedRef : BSExtraData
{
    TESObjectREFR* m_pLinkedReference;
    bool __thiscall FUN_00433670(BSExtraData* apCompare);
};

// @fnv 0x00433670
bool __thiscall ExtraLinkedRef::FUN_00433670(BSExtraData* apCompare)
{
    ExtraLinkedRef* pcomp = dynamic_cast<ExtraLinkedRef*>(apCompare);
    if (!pcomp)
        return true;
    if (pcomp->m_pLinkedReference != this->m_pLinkedReference)
        return true;
    return false;
}

void __cdecl _Deallocate(void*);

struct ExtraActivateRefChildren
{
    void __thiscall FUN_00433830();
    void* __thiscall FUN_00433800(unsigned int flags);
};

// Calls FUN_00433830, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x00433800
void* __thiscall ExtraActivateRefChildren::FUN_00433800(unsigned int flags)
{
    FUN_00433830();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_00433a00_list
{
    void* pHead;
};
void __cdecl FindContRecordByFormId(void* apArg, FUN_00433a00_list* apList);
struct FUN_00433a00_t : public BSExtraData
{
    FUN_00433a00_list kList;
    void FUN_00433a00(void* apArg);
};
// Calls FindContRecordByFormId with apArg and the extra data's kList.
// @fnv 0x00433a00
void FUN_00433a00_t::FUN_00433a00(void* apArg)
{
    FindContRecordByFormId(apArg, &kList);
}

extern char DAT_01183b2c;
extern char DAT_0118461c;

struct AlchemyItem;

struct ExtraPoison
{
    BSExtraData m_base;
    AlchemyItem* m_pPoisonItem;

    bool IsDifferent(BSExtraData* apCompare);
};

// Casts apCompare to ExtraPoison and returns true if the cast fails or the poison item pointers differ, otherwise false.
// @fnv 0x00435180
bool __thiscall ExtraPoison::IsDifferent(BSExtraData* apCompare)
{
    ExtraPoison* pcomp = dynamic_cast<ExtraPoison*>(apCompare);
    if (!pcomp)
        return true;
    if (pcomp->m_pPoisonItem != this->m_pPoisonItem)
        return true;
    return false;
}

struct ExtraMultiBoundRef : public BSExtraData
{
    TESObjectREFR* m_pReference;
    bool FUN_00435540(BSExtraData* apCompare);
};

// @fnv 0x00435540
bool ExtraMultiBoundRef::FUN_00435540(BSExtraData* apCompare)
{
    ExtraMultiBoundRef* pcomp = dynamic_cast<ExtraMultiBoundRef*>(apCompare);
    if (!pcomp)
        return true;
    if (m_pReference != pcomp->m_pReference)
        return true;
    return false;
}

extern "C" void __cdecl _Deallocate(void*);

struct ExtraDroppedItemList
{
    void FUN_004359f0();
    void* FUN_004359c0(unsigned int);
};

// Calls FUN_004359f0, then frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x004359c0
void* __thiscall ExtraDroppedItemList::FUN_004359c0(unsigned int flags)
{
    FUN_004359f0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct ArrSI
{
    unsigned int GetFlags();
};
struct ExtraFriendHits : public BSExtraData
{
    ArrSI kHits;
    void FUN_00435e40();
    int FUN_00435e20();
};
// @fnv 0x00435e20
int ExtraFriendHits::FUN_00435e20()
{
    FUN_00435e40();
    return kHits.GetFlags();
}

struct ExtraSayTopicInfoOnceADay
{
    void* __thiscall FUN_004374e0(unsigned int);
    void __thiscall FUN_004375c0();
};

void __cdecl _Deallocate(void*);

// Calls FUN_004375c0, then frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x004374e0
void* ExtraSayTopicInfoOnceADay::FUN_004374e0(unsigned int flags)
{
    FUN_004375c0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_00437c10 {
struct _ref_006815c0
{
    _ref_006815c0();
    float m_vComponents[4];
};
struct FUN_00437c10
{
    _ref_006815c0 m_kMinimumCorner;
    _ref_006815c0 m_kMaximumCorner;
    FUN_00437c10();
};
// Constructs the object, default-constructing its two _ref_006815c0 members.
// @fnv 0x00437c10
FUN_00437c10::FUN_00437c10()
{}
}  // namespace fnv_00437c10

extern "C" void __cdecl _Deallocate(void* ptr);

struct ExtraFollowerSwimBreadcrumbs
{
    void __thiscall FUN_00437d10();
    void* __thiscall FUN_00437ce0(unsigned int flags);
};

void __thiscall ExtraFollowerSwimBreadcrumbs::FUN_00437d10()
{}

// @fnv 0x00437ce0
void* __thiscall ExtraFollowerSwimBreadcrumbs::FUN_00437ce0(unsigned int flags)
{
    FUN_00437d10();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct Str6a70
{
    Str6a70& operator=(char const*);
};

struct FUN_00438280_class
{
    Str6a70 m_str;  // at offset 0x14
    void FUN_00438280(char const* s);
};

// @fnv 0x00438280
void FUN_00438280_class::FUN_00438280(char const* acString)
{
    *(Str6a70*)((char*)this + 0x14) = acString;
}

struct ExtraSpecialRenderFlags : public BSExtraData
{
    unsigned int uiFlags;
    float m_fRenderValue;
    bool FUN_004382a0(BSExtraData* apCompare);
};
// Compares against another ExtraSpecialRenderFlags: returns true if the cast fails, base compare matches, form IDs differ, or the float field differs.
// @fnv 0x004382a0
bool ExtraSpecialRenderFlags::FUN_004382a0(BSExtraData* apCompare)
{
    ExtraSpecialRenderFlags* pComp;

    pComp = dynamic_cast<ExtraSpecialRenderFlags*>(apCompare);
    if (!pComp)
    {
        return true;
    }
    if (BSExtraData::Compare(apCompare))
    {
        return true;
    }
    if (reinterpret_cast<TESForm*>(this)->GetFormID() != reinterpret_cast<TESForm*>(pComp)->GetFormID())
    {
        return true;
    }
    if (m_fRenderValue != pComp->m_fRenderValue)
    {
        return true;
    }
    return false;
}

struct BSSimpleArrayShell
{
    virtual ~BSSimpleArrayShell();
    virtual void* Allocate(unsigned int auiCount);
    void FUN_00430000(void* apBuffer, unsigned int auiCount);
    void FUN_00438a60(unsigned int auiAllocSize, unsigned int auiSize);

    void* pBuffer;
    unsigned int uiSize;
    unsigned int uiAllocSize;
};

// @fnv 0x00438a60
void BSSimpleArrayShell::FUN_00438a60(unsigned int auiAllocSize, unsigned int auiSize)
{
    pBuffer = 0;
    uiSize = 0;
    uiAllocSize = 0;
    if (auiSize > auiAllocSize)
    {
        auiAllocSize = auiSize;
    }
    if (auiAllocSize > 0)
    {
        pBuffer = Allocate(auiAllocSize);
        uiAllocSize = auiAllocSize;
    }
    if (auiSize > 0)
    {
        FUN_00430000(pBuffer, auiSize);
        uiSize = auiSize;
    }
}

namespace fnv_004300f0 {
class FUN_00430120
{
  public:
    virtual ~FUN_00430120();
};

extern "C" void __cdecl _Deallocate(void*);

struct ExtraAnim : FUN_00430120
{
    void* FUN_004300f0(unsigned int flags);
};

// Destructs the object, frees it with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x004300f0
void* ExtraAnim::FUN_004300f0(unsigned int flags)
{
    FUN_00430120::~FUN_00430120();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_004300f0

namespace fnv_004302a0 {
struct ExtraDismemberedLimbs
{
    void* __thiscall FUN_004302d0();
    void* __thiscall FUN_004302a0(unsigned int flags);
};

extern "C" void* __cdecl _Deallocate(void*);

// @fnv 0x004302a0
void* __thiscall ExtraDismemberedLimbs::FUN_004302a0(unsigned int flags)
{
    FUN_004302d0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_004302a0

class ExtraStartingPosition : public BSExtraData
{
  public:
    ExtraStartingPosition();
    bool FUN_00430850(BSExtraData*);
};

extern "C" int __cdecl _memcmp(const void*, const void*, unsigned int);

// Casts apCompare to ExtraStartingPosition, returns true if the cast fails, the base Compare succeeds, or the 0x18 bytes at offset 0xC differ; otherwise false.
// @fnv 0x00430850
bool __thiscall ExtraStartingPosition::FUN_00430850(BSExtraData* apCompare)
{
    ExtraStartingPosition* pComp = (ExtraStartingPosition*)dynamic_cast<ExtraStartingPosition*>(apCompare);
    if (!pComp)
        return true;
    if (BSExtraData::Compare(apCompare))
        return true;
    if (_memcmp((char*)this + 0xC, (char*)pComp + 0xC, 0x18) != 0)
        return true;
    return false;
}

extern "C" void* __cdecl _FNV_DynamicCast(void* p, int, void*, void*, int);
extern char DAT_01183b2c;
extern int DAT_011845b8;

struct ActorValueInfo
{
    bool SetScriptName(ActorValueInfo*);
};

struct ExtraAudioBuoyMarker : BSExtraData
{
    ActorValueInfo* m_pActorValueInfo;
    bool Compare(BSExtraData*);
    bool FUN_00431710(BSExtraData* apCompare);
};

// @fnv 0x00431710
bool ExtraAudioBuoyMarker::FUN_00431710(BSExtraData* apCompare)
{
    ExtraAudioBuoyMarker* pComp =
        (ExtraAudioBuoyMarker*)_FNV_DynamicCast(apCompare, 0, &DAT_01183b2c, &DAT_011845b8, 0);
    if (!pComp)
        return true;
    if (this->Compare(apCompare))
        return true;
    if (this->m_pActorValueInfo->SetScriptName(pComp->m_pActorValueInfo))
        return true;
    return false;
}

namespace fnv_00431b80 {
struct BE
{
    char m_auiShapeKeys[12];
    BE(unsigned char);
};

struct TeleportableReference;

struct FUN_00431b80 : BE
{
    TeleportableReference* m_pTeleportData;
    FUN_00431b80(TeleportableReference*);
};

extern void* DAT_010158cc;

// @fnv 0x00431b80
FUN_00431b80::FUN_00431b80(TeleportableReference* m_pTeleportData) : BE(0x23)
{
    *reinterpret_cast<void**>(this) = &DAT_010158cc;
    this->m_pTeleportData = m_pTeleportData;
}
}  // namespace fnv_00431b80

class ExtraHealthPerc : public BSExtraData
{
  public:
    float m_fHealthPercentage;
    ExtraHealthPerc();
    bool Compare(BSExtraData*);
    bool FUN_00431db0(BSExtraData*);
};

// @fnv 0x00431db0
bool __thiscall ExtraHealthPerc::FUN_00431db0(BSExtraData* apCompare)
{
    ExtraHealthPerc* pComp = dynamic_cast<ExtraHealthPerc*>(apCompare);
    if (!pComp)
        return true;
    if (this->Compare(apCompare))
        return true;
    if (this->m_fHealthPercentage != pComp->m_fHealthPercentage)
        return true;
    return false;
}

extern char DAT_01183b2c;
extern int DAT_01184810;

class ExtraTimeLeft : public BSExtraData
{
  public:
    float fTime;  // +0x0c
    bool FUN_00431ef0(BSExtraData*);
};

// @fnv 0x00431ef0
bool __thiscall ExtraTimeLeft::FUN_00431ef0(BSExtraData* apCompare)
{
    ExtraTimeLeft* pComp = dynamic_cast<ExtraTimeLeft*>(apCompare);
    if (!pComp)
        return true;
    if (BSExtraData::Compare(apCompare))
        return true;
    if (fTime != pComp->fTime)
        return true;
    return false;
}

extern "C" void __cdecl _Deallocate(void*);

struct FUN_00435710_Class
{
    void FUN_00435740();
    void* FUN_00435710(unsigned int flags);
};

// Calls FUN_00435740, then frees this object with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00435710
void* FUN_00435710_Class::FUN_00435710(unsigned int flags)
{
    FUN_00435740();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct ExtraRadius : BSExtraData
{
    float fRadius;
    ExtraRadius();
    virtual bool FUN_00436bd0(BSExtraData*);
};

// @fnv 0x00436bd0
bool __thiscall ExtraRadius::FUN_00436bd0(BSExtraData* apCompare)
{
    ExtraRadius* pComp;
    pComp = dynamic_cast<ExtraRadius*>(apCompare);
    if (!pComp)
        return true;
    if (Compare(apCompare))
        return true;
    if (!(fRadius == pComp->fRadius))
        return true;
    return false;
}

class ExtraRadioData;

extern char DAT_01183b2c;
extern int DAT_011841e8;
extern "C" int __cdecl _memcmp(const void*, const void*, unsigned int);

struct ExtraRadioData : BSExtraData
{
    ExtraRadioData();
    bool CompareRadioData(BSExtraData*);
};

// @fnv 0x00437290
bool __thiscall ExtraRadioData::CompareRadioData(BSExtraData* apCompare)
{
    ExtraRadioData* pComp = dynamic_cast<ExtraRadioData*>(apCompare);
    if (pComp == 0)
        return true;
    if (BSExtraData::Compare(apCompare))
        return true;
    if (_memcmp((char*)this + 0xc, (char*)pComp + 0xc, 0x10) != 0)
        return true;
    return false;
}

struct BGSPrimitive;
struct BSExtraData;

struct ExtraPrimitive : BSExtraData
{
    BGSPrimitive* m_pPrimitive;
    bool __thiscall FUN_00437370(BSExtraData* apCompare);
};

extern BGSPrimitive* DAT_011842b0;
extern char DAT_01183b2c;

// Casts apCompare to ExtraPrimitive and returns true if the cast fails or the primitive pointers differ, false otherwise.
// @fnv 0x00437370
bool __thiscall ExtraPrimitive::FUN_00437370(BSExtraData* apCompare)
{
    ExtraPrimitive* pcomp = dynamic_cast<ExtraPrimitive*>(apCompare);
    if (!pcomp)
        return true;
    if (pcomp->m_pPrimitive != this->m_pPrimitive)
        return true;
    return false;
}

struct FUN_004303e0_Class
{
    bool __thiscall IsBitSet(unsigned int);
};

// Tests whether bit n is set in the 16-bit flags word at offset 12 of this object and returns the result.
// @fnv 0x004303e0
bool __thiscall FUN_004303e0_Class::IsBitSet(unsigned int uiBitIndex)
{
    if (reinterpret_cast<unsigned short*>(this)[6] & (1 << uiBitIndex))
        return true;
    return false;
}

struct BSSimpleList_standin
{
    bool IsEmpty();
    void FUN_0063f7b0();
};

struct FUN_00434d90_standin
{
    char pad[0x0C];
    BSSimpleList_standin m_kNode;
    void FUN_00434d90();
};

// @fnv 0x00434d90
void FUN_00434d90_standin::FUN_00434d90()
{
    while (!m_kNode.IsEmpty())
        m_kNode.FUN_0063f7b0();
}

namespace fnv_00435510 {
extern "C" void* DAT_01015e40;

struct BE
{
    unsigned char m_uc;
    BE(unsigned char uc)
    {
        m_uc = uc;
    }
};

struct FUN_00435510 : BE
{
    int m_i;
    int m_i2;
    void* m_p;
    FUN_00435510();
};

// @fnv 0x00435510
FUN_00435510::FUN_00435510() : BE(0x63)
{
    *(void**)this = &DAT_01015e40;
    m_p = 0;
}
}  // namespace fnv_00435510

namespace fnv_00435920 {
extern int DAT_01015e88;
struct BE
{
    BE(unsigned char);
};
struct FUN_00435920 : BE
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    FUN_00435920();
};
// Initializes the base with 0x39, stores the address of DAT_01015e88 in m_00 and zeroes m_0c.
// @fnv 0x00435920
FUN_00435920::FUN_00435920() : BE(0x39)
{
    m_00 = (int)&DAT_01015e88;
    m_0c = 0;
}
}  // namespace fnv_00435920

namespace fnv_00435a60 {
struct BE
{
    unsigned char uc;
    BE(unsigned char v) : uc(v)
    {}
};
extern void* DAT_01015ea0;
struct FUN_00435a60 : BE
{
    void* p;
    char* m_pString;
    FUN_00435a60();
};
// @fnv 0x00435a60
FUN_00435a60::FUN_00435a60() : BE(0x42)
{
    *(void**)this = &DAT_01015ea0;
    *(char**)((char*)this + 0xc) = 0;
}
}  // namespace fnv_00435a60

namespace fnv_00435b50 {
struct BE
{
    int* vtbl;
    int a;
    int b;
    BE(unsigned char);
};
extern int DAT_01015eac;

struct FUN_00435b50 : BE
{
    int* m_pSavedHavokData;
    FUN_00435b50();
};

// @fnv 0x00435b50
FUN_00435b50::FUN_00435b50() : BE(0x3d)
{
    vtbl = &DAT_01015eac;
    m_pSavedHavokData = 0;
}
}  // namespace fnv_00435b50

float __cdecl GetActorScale();
struct FUN_00435e00_t
{
    float m_fStartTime;
    float FUN_00435e00();
};
// @fnv 0x00435e00
float FUN_00435e00_t::FUN_00435e00()
{
    return GetActorScale() - m_fStartTime;
}

struct FUN_00437a30_Class
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    bool FUN_00437a30(FUN_00437a30_Class* other);
};

// Returns true when m_0c differs from the other object's m_0c, otherwise false.
// @fnv 0x00437a30
bool FUN_00437a30_Class::FUN_00437a30(FUN_00437a30_Class* other)
{
    FUN_00437a30_Class* pOther = other;
    if (m_0c != pOther->m_0c)
        return true;
    return false;
}

namespace fnv_00438260 {
struct Str6a70
{
    Str6a70& operator=(const char*);
};

struct FUN_00438260
{
    int pad[3];
    Str6a70 m_str;
    void SetStr(const char* param);
};

// @fnv 0x00438260
void FUN_00438260::SetStr(const char* apStr)
{
    m_str = apStr;
}
}  // namespace fnv_00438260

namespace fnv_004334b0 {
struct BE
{
    void* _0;
    int _4;
    int _8;
    BE(unsigned char);
};
extern int DAT_01015ca8;
struct FUN_004334b0 : BE
{
    int _c;
    FUN_004334b0();
};
// Initializes the base with tag 0x3b, points _0 at DAT_01015ca8, and sets _c to 0.
// @fnv 0x004334b0
FUN_004334b0::FUN_004334b0() : BE(0x3b)
{
    _0 = (void*)&DAT_01015ca8;
    _c = 0;
}
}  // namespace fnv_004334b0

namespace fnv_00433640 {
struct BE
{
    int _00;
    int _04;
    int _08;
    BE(unsigned char);
};
extern int DAT_01015cc0;
struct FUN_00433640 : BE
{
    int unk0C;
    FUN_00433640();
};
// Initialises the base with tag 0x51, installs the vtable pointer DAT_01015cc0, and zeroes unk0C.
// @fnv 0x00433640
FUN_00433640::FUN_00433640() : BE(0x51)
{
    *(int*)this = (int)&DAT_01015cc0;
    unk0C = 0;
}
}  // namespace fnv_00433640

namespace fnv_00435c10 {
struct FUN_00435b20_shell
{
    int _u;
    void FUN_00435b20(void);
};
struct CF845 : public FUN_00435b20_shell
{
    CF845(int);
};
struct ExtraSavedAnimation
{
    char _pad[12];
    char* m_pString;
    void FUN_00435c10();
};
// Constructs a CF845 from the stored animation pointer and calls its FUN_00435b20 method.
// @fnv 0x00435c10
void ExtraSavedAnimation::FUN_00435c10()
{
    CF845((int)m_pString).FUN_00435b20();
}
}  // namespace fnv_00435c10

namespace fnv_004324a0 {
struct BE
{
    unsigned char m_iWordAt00;
    BE(unsigned char);
    virtual ~BE();
};
struct FUN_0083da50
{
    FUN_0083da50();
    virtual ~FUN_0083da50();
    char m_04[0x28];
};
struct FUN_004324a0 : public BE
{
    FUN_004324a0();
    virtual ~FUN_004324a0();
    int m_04;
    FUN_0083da50* m_0c;
};
// Constructs a BE with value 0x4d and allocates a FUN_0083da50 stored in m_0c.
// @fnv 0x004324a0
FUN_004324a0::FUN_004324a0() : BE(0x4d)
{
    m_0c = new FUN_0083da50;
}
}  // namespace fnv_004324a0

struct DoorTeleportLoadData
{
    TESObjectREFR* m_pHitReference;
    NiPoint3 Intersect;
    NiPoint3 Normal;
    DoorTeleportLoadData();
};
struct G2
{
    void AddHead(DoorTeleportLoadData**);
};
struct ExtraDecalRefsStandIn
{
    DoorTeleportLoadData* FindDecalReference(TESObjectREFR*);
    void SetDecalRefData(TESObjectREFR* ref, const NiPoint3& intersect, const NiPoint3& normal);
};
// Looks up the load data for ref, creating and registering a new entry if missing, then stores the intersect point and normal.
// @fnv 0x00434480
void ExtraDecalRefsStandIn::SetDecalRefData(TESObjectREFR* ref, const NiPoint3& intersect, const NiPoint3& normal)
{
    DoorTeleportLoadData* data = FindDecalReference(ref);
    if (!data)
    {
        data = new DoorTeleportLoadData;
        data->m_pHitReference = ref;
        ((G2*)((char*)this + 0xC))->AddHead(&data);
    }
    data->Intersect = intersect;
    data->Normal = normal;
}

namespace fnv_00434560 {
struct ListX
{
    virtual ~ListX();
    void RemoveAll();
    bool _ref_008256d0();
    void** _ref_006815c0();
    ListX* GetNext();
};
void __cdecl _Deallocate(void*);
struct FUN_00434560 : public BSExtraData
{
    ListX m_kNode;
    ~FUN_00434560();
};
// @fnv 0x00434560
FUN_00434560::~FUN_00434560()
{
    ListX* p = &m_kNode;
    while (p && !p->_ref_008256d0())
    {
        void* tmp = *p->_ref_006815c0();
        void* arg4 = tmp;
        _Deallocate(arg4);
        p = p->GetNext();
    }
    m_kNode.RemoveAll();
}
}  // namespace fnv_00434560

void __cdecl _Deallocate(void*);
struct ContNode
{
    void* item;
    ContNode* next;
    bool FUN_008256d0();
    void* FUN_006815c0();
    ContNode* GetNext();
    void FUN_0063f7b0();
    void FUN_00905330(void*);
};
struct FUN_00434800_shell
{
    void* p0;
    void* p1;
    void* p2;
    void FUN_00434800(void* target);
};
// @fnv 0x00434800
void FUN_00434800_shell::FUN_00434800(void* target)
{
    ContNode* node = (ContNode*)((char*)this + 0xc);
    ContNode* prev = 0;
    while (node && !node->FUN_008256d0())
    {
        void* item = *(void**)node->FUN_006815c0();
        if (*(void**)item == target)
        {
            if (prev)
                prev->FUN_00905330(&item);
            else
                node->FUN_0063f7b0();
            void* tmp = item;
            _Deallocate(tmp);
            item = 0;
            return;
        }
        prev = node;
        node = node->GetNext();
    }
}

namespace fnv_00430200 {
struct BE
{
    unsigned char a;
    BE(unsigned char);
    ~BE();
};
struct AX
{
    AX* FUN_00438570();
};
extern "C" void* _data_011c16bc;
extern void* DAT_01015b34;
struct FUN_00430200 : BE
{
    unsigned short f0c;
    int f10;
    int f14;
    int f18;
    unsigned char f1c;
    FUN_00430200();
    ~FUN_00430200();
};
// @fnv 0x00430200
FUN_00430200::FUN_00430200() : BE(0x5f)
{
    *reinterpret_cast<void**>(this) = &DAT_01015b34;
    reinterpret_cast<AX*>(reinterpret_cast<char*>(this) + 0x20)->FUN_00438570();
    *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(this) + 0xc) = 0;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x10) = -1;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x14) = 0;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x18) = -1;
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x1c) = 0;
}
}  // namespace fnv_00430200

namespace fnv_00430fd0 {
struct PSM3
{
    ~PSM3();
};
struct FUN_00430fd0 : public BSExtraData
{
    PSM3 psm3;
    ~FUN_00430fd0();
};
// Destructor for the extra data object; destroys its PSM3 member and the BSExtraData base.
// @fnv 0x00430fd0
FUN_00430fd0::~FUN_00430fd0()
{}
}  // namespace fnv_00430fd0

namespace fnv_00431030 {
struct ArrSI
{
    unsigned int GetFlags();
};
struct LS3de0
{
    unsigned int Find(unsigned int&, unsigned int, bool(__cdecl*)(int const*, int const*));
};
struct FUN_00431030_BSSimpleArray
{
    unsigned int& GetAt(int);
};
struct FUN_00431030_shell : BSExtraData
{
    bool FUN_00431030(BSExtraData* apCompare);
};
// @fnv 0x00431030
bool FUN_00431030_shell::FUN_00431030(BSExtraData* apCompare)
{
    if (!Compare(apCompare))
        return true;
    FUN_00431030_shell* pOtherData = static_cast<FUN_00431030_shell*>(apCompare);
    if (reinterpret_cast<ArrSI*>(pOtherData + 1)->GetFlags() != reinterpret_cast<ArrSI*>(this + 1)->GetFlags())
        return true;
    for (unsigned int i = 0; i < reinterpret_cast<ArrSI*>(this + 1)->GetFlags(); ++i)
    {
        if (reinterpret_cast<LS3de0*>(pOtherData + 1)
                ->Find(reinterpret_cast<FUN_00431030_BSSimpleArray*>(this + 1)->GetAt(i), 0,
                       (bool(__cdecl*)(int const*, int const*))FUN_009a3830) == (unsigned int)-1)
            return true;
    }
    return false;
}
}  // namespace fnv_00431030

struct ExtraOriginalReference : BSExtraData
{
    TESObjectREFR* m_pWorldReferenceInfo;
    bool FUN_004319d0(BSExtraData* apCompare);
};

// @fnv 0x004319d0
bool ExtraOriginalReference::FUN_004319d0(BSExtraData* apCompare)
{
    ExtraOriginalReference* pComp = dynamic_cast<ExtraOriginalReference*>(apCompare);
    if (!pComp)
        return true;
    if (Compare(apCompare))
        return true;
    if (m_pWorldReferenceInfo != pComp->m_pWorldReferenceInfo)
        return true;
    return false;
}

struct ExtraOwnership : BSExtraData
{
    char* pOwner;
    bool FUN_00431a70(BSExtraData* apCompare);
};

// @fnv 0x00431a70
bool ExtraOwnership::FUN_00431a70(BSExtraData* apCompare)
{
    ExtraOwnership* pComp = dynamic_cast<ExtraOwnership*>(apCompare);
    if (!pComp)
        return true;
    if (BSExtraData::Compare(apCompare))
        return true;
    if (pOwner != pComp->pOwner)
        return true;
    return false;
}

struct ExtraRank : public BSExtraData
{
    int m_iRank;
    bool FUN_00431bb0(BSExtraData* apCompare);
};

// @fnv 0x00431bb0
bool ExtraRank::FUN_00431bb0(BSExtraData* apCompare)
{
    ExtraRank* pComp;
    pComp = dynamic_cast<ExtraRank*>(apCompare);
    if (!pComp)
        return true;
    if (Compare(apCompare))
        return true;
    if (m_iRank != pComp->m_iRank)
        return true;
    return false;
}

struct ExtraUses : BSExtraData
{
    unsigned char m_ucUses;  // +0xc
    bool FUN_00431e50(BSExtraData* apCompare);
};
// @fnv 0x00431e50
bool ExtraUses::FUN_00431e50(BSExtraData* apCompare)
{
    ExtraUses* pComp = dynamic_cast<ExtraUses*>(apCompare);
    if (!pComp)
        return true;
    if (Compare(apCompare))
        return true;
    if (m_ucUses != pComp->m_ucUses)
        return true;
    return false;
}

struct ExtraCharge : BSExtraData
{
    float m_fCharge;
    bool FUN_00431f90(BSExtraData*);
};

// @fnv 0x00431f90
bool ExtraCharge::FUN_00431f90(BSExtraData* apCompare)
{
    ExtraCharge* pComp = dynamic_cast<ExtraCharge*>(apCompare);
    if (!pComp)
        return true;
    if (Compare(apCompare))
        return true;
    if (m_fCharge != pComp->m_fCharge)
        return true;
    return false;
}

struct ExtraWeaponModFlags : BSExtraData
{
    unsigned char m_ucWeaponModFlags;  // +0xc
    bool FUN_00432140(BSExtraData*);
};
// @fnv 0x00432140
bool ExtraWeaponModFlags::FUN_00432140(BSExtraData* apCompare)
{
    ExtraWeaponModFlags* pComp = dynamic_cast<ExtraWeaponModFlags*>(apCompare);
    if (!pComp)
        return true;
    if (Compare(apCompare))
        return true;
    if (m_ucWeaponModFlags != pComp->m_ucWeaponModFlags)
        return true;
    return false;
}

struct ExtraScale : BSExtraData
{
    float fScale;
    bool FUN_00432250(BSExtraData* apCompare);
};

// @fnv 0x00432250
bool ExtraScale::FUN_00432250(BSExtraData* apCompare)
{
    ExtraScale* pComp = dynamic_cast<ExtraScale*>(apCompare);
    if (!pComp)
        return true;
    if (Compare(apCompare))
        return true;
    if (fScale != pComp->fScale)
        return true;
    return false;
}

namespace fnv_00432870 {
struct BE
{
    void* pVTable;
    unsigned int iSize;
    BE(unsigned char);
};
extern "C" void* DAT_01015c24;
struct FUN_00432870 : BE
{
    unsigned int iActionIndex;
    unsigned int iData;
    unsigned int iFlags;
    unsigned int iFlags2;
    unsigned char cFlags;
    unsigned char cFlags2;
    unsigned char cFlags3;
    FUN_00432870(unsigned int aiData, unsigned int aiFlags, unsigned int aiFlags2, unsigned char acFlags,
                 unsigned char acFlags2, unsigned char acFlags3);
};
// Initializes the object's vtable and stores the data, two flag words and three flag bytes passed to the constructor.
// @fnv 0x00432870
FUN_00432870::FUN_00432870(unsigned int aiData, unsigned int aiFlags, unsigned int aiFlags2, unsigned char acFlags,
                           unsigned char acFlags2, unsigned char acFlags3)
    : BE(0x19)
{
    pVTable = &DAT_01015c24;
    iData = aiData;
    iFlags = aiFlags;
    iFlags2 = aiFlags2;
    cFlags = acFlags;
    cFlags2 = acFlags2;
    cFlags3 = acFlags3;
}
}  // namespace fnv_00432870

struct ExtraEncounterZone : BSExtraData
{
    bool FUN_00432e90(BSExtraData*);
};

// @fnv 0x00432e90
bool ExtraEncounterZone::FUN_00432e90(BSExtraData* apCompare)
{
    ExtraEncounterZone* pcomp = dynamic_cast<ExtraEncounterZone*>(apCompare);
    if (!pcomp)
        return true;
    if (BSExtraData::Compare(apCompare))
        return true;
    if (*(void**)((char*)this + 0xc) != *(void**)((char*)pcomp + 0xc))
        return true;
    return false;
}

namespace fnv_00433010 {
struct SL
{
    SL();
    ~SL();
    char p[8];
};
struct BE
{
    BE(unsigned char);
    ~BE();
    virtual void v0();
    char pad[8];
    SL* mSL;
};
struct FUN_00433010 : BE
{
    FUN_00433010();
};
// Calls the BE base constructor with 0x1b and allocates a new SL, storing its pointer in mSL.
// @fnv 0x00433010
FUN_00433010::FUN_00433010() : BE(0x1b)
{
    mSL = new SL;
}
}  // namespace fnv_00433010

namespace fnv_00433440 {
struct List_009e03e0
{
    void RemoveAll();
    ~List_009e03e0();
};
struct FUN_00433440 : public BSExtraData
{
    List_009e03e0 list;
    virtual ~FUN_00433440();
};
// Destructor for a BSExtraData subclass that clears the contained list via RemoveAll.
// @fnv 0x00433440
FUN_00433440::~FUN_00433440()
{
    list.RemoveAll();
}
}  // namespace fnv_00433440

namespace fnv_004335d0 {
struct ListX
{
    ~ListX();
    void RemoveAll();
};
struct FUN_004335d0 : public BSExtraData
{
    ListX items;
    virtual ~FUN_004335d0();
};
// Destructor that removes all entries from the items list.
// @fnv 0x004335d0
FUN_004335d0::~FUN_004335d0()
{
    items.RemoveAll();
}
}  // namespace fnv_004335d0

namespace fnv_00433d40 {
struct ListX
{
    int a;
    int b;
    int c;
    ~ListX();
};
struct FUN_00433d40 : BSExtraData
{
    ListX refs;
    ~FUN_00433d40();
    void DeleteAllEntries();
};
// @fnv 0x00433d40
FUN_00433d40::~FUN_00433d40()
{
    DeleteAllEntries();
}
}  // namespace fnv_00433d40

struct FUN_004343c0_standin
{
    char m00[0xc];
    BSSimpleList<BGSPerkEntry*> kList;
    void DeleteAllEntries();
};

// Removes each entry from kList, deleting every BGSPerkEntry until the list is empty.
// @fnv 0x004343c0
void FUN_004343c0_standin::DeleteAllEntries()
{
    void* pDelete;
    BGSPerkEntry* pItem;
    while (!kList.IsEmpty())
    {
        pItem = kList.GetItem();
        kList.RemoveHead();
        pDelete = pItem;
        operator delete(pDelete);
    }
}

namespace fnv_00434950 {
struct ListX
{
    ~ListX();
    void RemoveAll();
};
struct FUN_00434950 : public BSExtraData
{
    ListX list;
    virtual ~FUN_00434950();
};
// Destructor that removes all entries from the contained list before the base BSExtraData destructor runs.
// @fnv 0x00434950
FUN_00434950::~FUN_00434950()
{
    list.RemoveAll();
}
}  // namespace fnv_00434950

namespace fnv_00434dc0 {
struct ListX
{
    ~ListX();
};
struct List_009e03e0
{
    int dummy;
    void RemoveAll();
    ListX m_uiX;
};
struct FUN_00434dc0 : public BSExtraData
{
    List_009e03e0 m_kNode;
    ~FUN_00434dc0();
};
// Destructor that calls RemoveAll on the contained list to clear its entries.
// @fnv 0x00434dc0
FUN_00434dc0::~FUN_00434dc0()
{
    m_kNode.RemoveAll();
}
}  // namespace fnv_00434dc0

namespace fnv_004359f0 {
struct ListX
{
    int a, b, c;
    void RemoveAll();
    ~ListX();
};
struct FUN_004359f0 : public BSExtraData
{
    ListX list;
    ~FUN_004359f0();
};
// Destructor for a BSExtraData subclass that removes all entries from its embedded list.
// @fnv 0x004359f0
FUN_004359f0::~FUN_004359f0()
{
    list.RemoveAll();
}
}  // namespace fnv_004359f0

struct FUN_00435b50 : public BSExtraData
{
    void FUN_00435c10();
    virtual ~FUN_00435b50();
};
struct FUN_00435ac0 : public FUN_00435b50
{
    virtual ~FUN_00435ac0();
};
// Destructor that calls FUN_00435c10 before the base BSExtraData destructor runs.
// @fnv 0x00435ac0
FUN_00435ac0::~FUN_00435ac0()
{
    FUN_00435c10();
}

struct FUN_00435bb0 : public BSExtraData
{
    virtual ~FUN_00435bb0();
    void FUN_00435c10();
};
// @fnv 0x00435bb0
FUN_00435bb0::~FUN_00435bb0()
{
    FUN_00435c10();
}

struct ExtraRadiation : BSExtraData
{
    bool FUN_00436c40(BSExtraData* apCompare);
};
// Casts apCompare to ExtraRadiation, returns true if the cast fails, base compare passes, or the float at offset 0xc differs; otherwise false.
// @fnv 0x00436c40
bool ExtraRadiation::FUN_00436c40(BSExtraData* apCompare)
{
    ExtraRadiation* pComp = dynamic_cast<ExtraRadiation*>(apCompare);
    if (!pComp)
        return true;
    if (BSExtraData::Compare(apCompare))
        return true;
    if (*(float*)((char*)this + 0xc) != *(float*)((char*)pComp + 0xc))
        return true;
    return false;
}

namespace fnv_00436d80 {
struct List_009e03e0
{
    void RemoveAll();
    ~List_009e03e0();
};
struct FUN_00436d80 : public BSExtraData
{
    List_009e03e0* m_kNode;
    virtual ~FUN_00436d80();
};
// Destructor: clears the owned list via RemoveAll and then deletes it.
// @fnv 0x00436d80
FUN_00436d80::~FUN_00436d80()
{
    m_kNode->RemoveAll();
    delete m_kNode;
}
}  // namespace fnv_00436d80

extern char DAT_01183b2c;
struct ExtraCombatStyle : BSExtraData
{
    void* m_pCombatStyle;
    bool FUN_00437300(BSExtraData* apCompare);
};
// @fnv 0x00437300
bool ExtraCombatStyle::FUN_00437300(BSExtraData* apCompare)
{
    ExtraCombatStyle* pComp = dynamic_cast<ExtraCombatStyle*>(apCompare);
    if (!pComp)
        return true;
    if (Compare(apCompare))
        return true;
    if (m_pCombatStyle != pComp->m_pCombatStyle)
        return true;
    return false;
}

struct ExtraAmmo : BSExtraData
{
    bool FUN_004373c0(BSExtraData* apCompare);
};

// @fnv 0x004373c0
bool ExtraAmmo::FUN_004373c0(BSExtraData* apCompare)
{
    ExtraAmmo* pComp = dynamic_cast<ExtraAmmo*>(apCompare);
    if (!pComp)
        return true;
    if (Compare(apCompare))
        return true;
    if (*(int*)((char*)this + 0x10) != *(int*)((char*)pComp + 0x10))
        return true;
    if (*(int*)((char*)this + 0xc) != *(int*)((char*)pComp + 0xc))
        return true;
    return false;
}

namespace fnv_00437750 {
struct BE
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    unsigned char c;
    int pad;
    BE(unsigned char);
    ~BE();
};
struct FUN_004383b0_Class
{
    FUN_004383b0_Class(unsigned char);
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void w6();
    virtual void w7();
    int a;
    int b;
    int c2;
};
struct FUN_00437750 : public BE
{
    FUN_004383b0_Class m;
    int n;
    FUN_00437750();
};
// Constructs the object by initializing the BE base with 0x7e, the m member with 0x25, and n to 0.
// @fnv 0x00437750
FUN_00437750::FUN_00437750() : BE(0x7e), m(0x25), n(0)
{}
}  // namespace fnv_00437750

void _Deallocate(void* p);

struct FUN_00411e70
{
    void FUN_00411ea0();
    void* DeleteThis(unsigned int flags);
};

// Calls FUN_00411ea0, frees this via _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00411e70
void* FUN_00411e70::DeleteThis(unsigned int flags)
{
    FUN_00411ea0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void __cdecl FUN_0042cca0();
void __cdecl _Deallocate(void* p);

struct FUN_0042cc70_Class
{
    void FUN_0042cca0();
    void* FUN_0042cc70(unsigned int flags);
};

// Calls FUN_0042cca0, then deallocates this object if bit 0 of flags is set, and returns this.
// @fnv 0x0042cc70
void* FUN_0042cc70_Class::FUN_0042cc70(unsigned int flags)
{
    FUN_0042cca0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_004305f0 {
struct ArrSI
{
    unsigned int GetFlags(void);
};

struct BSSimpleArrayStandIn
{
    unsigned int& GetAt(int);
};

struct FUN_004305f0
{
    void Run(int arg1, char arg2);
};

// Iterates the array at this+0x20 and, for each non-null entry whose first byte equals arg1, writes arg2 to the entry's byte at offset 3.
// @fnv 0x004305f0
void FUN_004305f0::Run(int arg1, char arg2)
{
    unsigned int i;
    for (i = 0; i < ((ArrSI*)((char*)this + 0x20))->GetFlags(); ++i)
    {
        unsigned int v = ((BSSimpleArrayStandIn*)((char*)this + 0x20))->GetAt(i);
        if (v != 0)
        {
            if (*(unsigned char*)v == arg1)
            {
                *(unsigned char*)(v + 3) = arg2;
            }
        }
    }
}
}  // namespace fnv_004305f0

namespace fnv_00431ae0 {
extern int DAT_010158c0;

struct BE
{
    BE(unsigned char);
    void* vptr;
    unsigned char padding[8];
};

struct FUN_00431ae0 : BE
{
    FUN_00431ae0(unsigned int value);

    unsigned int field_000c;
};

// @fnv 0x00431ae0
FUN_00431ae0::FUN_00431ae0(unsigned int value) : BE(static_cast<unsigned char>(0x22))
{
    vptr = reinterpret_cast<void*>(&DAT_010158c0);
    field_000c = value;
}
}  // namespace fnv_00431ae0

namespace fnv_00431e20 {
struct BE
{
    BE(unsigned char);
};

extern int DAT_010158f0;

struct FUN_00431e20 : BE
{
    char pad[12];
    unsigned char field_0xc;
    FUN_00431e20(unsigned char c);
};

// Initialises the object with base 0x26, stores a vtable pointer at offset 0 and saves the byte argument at offset 0xc.
// @fnv 0x00431e20
FUN_00431e20::FUN_00431e20(unsigned char c) : BE(0x26)
{
    *reinterpret_cast<int*>(this) = (int)&DAT_010158f0;
    field_0xc = c;
}
}  // namespace fnv_00431e20

namespace fnv_00431ec0 {
struct BE
{
    BE(unsigned char);
};

extern int DAT_010158fc;

struct FUN_00431ec0 : BE
{
    char pad[12];
    float f;
    FUN_00431ec0(float value);
};

// @fnv 0x00431ec0
FUN_00431ec0::FUN_00431ec0(float value) : BE(0x27)
{
    *(int*)this = (int)&DAT_010158fc;
    f = value;
}
}  // namespace fnv_00431ec0

namespace fnv_00431f60 {
struct BE
{
    BE(unsigned char);
};

extern int DAT_01015908;

struct FUN_00431f60 : BE
{
    char pad[12];
    float f;
    FUN_00431f60(float value);
};

// @fnv 0x00431f60
FUN_00431f60::FUN_00431f60(float value) : BE(0x28)
{
    *(int*)this = (int)&DAT_01015908;
    f = value;
}
}  // namespace fnv_00431f60

namespace fnv_00432220 {
struct BE
{
    BE(unsigned char);
    int* m_ppVirtualMethodTable;
    unsigned char padding[8];
};

extern int DAT_01015920[];

struct FUN_00432220 : BE
{
    float fValue;

    FUN_00432220(float value);
};

// @fnv 0x00432220
FUN_00432220::FUN_00432220(float value) : BE(0x30)
{
    m_ppVirtualMethodTable = DAT_01015920;
    fValue = value;
}
}  // namespace fnv_00432220

namespace fnv_00432380 {
struct BE
{
    unsigned char padding[12];
    BE(unsigned char);
};

extern int DAT_0101592c;

struct FUN_00432380 : BE
{
    char m_cHotKey;
    FUN_00432380(char);
};

// @fnv 0x00432380
FUN_00432380::FUN_00432380(char acValue) : BE(0x4a)
{
    *reinterpret_cast<void**>(this) = &DAT_0101592c;
    this->m_cHotKey = acValue;
}
}  // namespace fnv_00432380

namespace fnv_00432440 {
struct FUN_004323b0
{
    virtual ~FUN_004323b0();
};

struct ExtraInfoGeneralTopic : FUN_004323b0
{
    void* FUN_00432440(unsigned int flags);
};

void* __cdecl _Deallocate(void* p);

// Runs the base destructor, frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00432440
void* ExtraInfoGeneralTopic::FUN_00432440(unsigned int flags)
{
    FUN_004323b0::~FUN_004323b0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_00432440

namespace fnv_00432810 {
extern int _DAT_01015c24;

struct BE
{
    BE(unsigned char);
};

struct FUN_00432810 : BE
{
    FUN_00432810();
};

// @fnv 0x00432810
FUN_00432810::FUN_00432810() : BE(0x19)
{
    *(int*)this = (int)&_DAT_01015c24;
    *(int*)((char*)this + 0xc) = 0;
    *(int*)((char*)this + 0x10) = -1;
    *(int*)((char*)this + 0x14) = 0;
    *(char*)((char*)this + 0x18) = 0;
    *(char*)((char*)this + 0x19) = 0;
    *(char*)((char*)this + 0x1a) = 0;
}
}  // namespace fnv_00432810

namespace fnv_004329d0 {
class BE
{
  public:
    BE(unsigned char);
    ~BE()
    {}
    const char* pC;
    int i1;
    int i2;
};

class SL
{
  public:
    SL();
    ~SL()
    {}
    int i1;
    int i2;
};

class FUN_004329d0 : public BE
{
  public:
    SL* pSL;

    FUN_004329d0();
};

// Initializes the base with 0x35, sets pC to "p*C", and allocates a new SL into pSL.
// @fnv 0x004329d0
FUN_004329d0::FUN_004329d0() : BE(0x35)
{
    pC = "p*C";
    pSL = new SL();
}
}  // namespace fnv_004329d0

struct ExtraRunOncePacks : BSExtraData
{
    void FUN_004330e0();
    void* FUN_004330b0(unsigned int flags);
};

void __cdecl _Deallocate(void* ptr);

// @fnv 0x004330b0
void* ExtraRunOncePacks::FUN_004330b0(unsigned int flags)
{
    FUN_004330e0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_00433300 {
struct BE
{
    unsigned char padding[0x0c];

    BE(unsigned char);
};

extern int DAT_01015c90;

struct FUN_00433300 : public BE
{
    unsigned int field;
    unsigned char flag;

    FUN_00433300();
};

// Initialises the base with tag 0x37, stores a pointer to DAT_01015c90, and zeroes field and flag.
// @fnv 0x00433300
FUN_00433300::FUN_00433300() : BE(0x37)
{
    *reinterpret_cast<unsigned int*>(this) = reinterpret_cast<unsigned int>(&DAT_01015c90);
    field = 0;
    flag = 0;
}
}  // namespace fnv_00433300

void _Deallocate(void*);

class ExtraEnableStateChildren
{
  public:
    void* FUN_00433410(unsigned int flags);
    void FUN_00433440();
};

// Calls FUN_00433440, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00433410
void* ExtraEnableStateChildren::FUN_00433410(unsigned int flags)
{
    FUN_00433440();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_004336c0 {
struct BE
{
    char padding[0x0c];
    BE(unsigned char);
};

extern int DAT_01015ccc;

struct FUN_004336c0 : BE
{
    unsigned int DroppedItemList;
    FUN_004336c0();
};

// @fnv 0x004336c0
FUN_004336c0::FUN_004336c0() : BE(0x89)
{
    *reinterpret_cast<void**>(this) = reinterpret_cast<void*>(&DAT_01015ccc);
    DroppedItemList = 0;
}
}  // namespace fnv_004336c0

namespace fnv_00434f60 {
struct G2
{
    void AddHead(int* value);
};

struct LH : public G2
{
    bool IsInList(int& value);
};

struct TargetClass
{
    int field1;
    int field2;
    int field3;
    LH list;

    void AddIfNotInList(int value);
};

// Checks whether value is already in list; if not, adds it to the head of the list.
// @fnv 0x00434f60
void TargetClass::AddIfNotInList(int value)
{
    if (!list.IsInList(value))
        list.AddHead(reinterpret_cast<int*>(&value));
}
}  // namespace fnv_00434f60

namespace fnv_00435150 {
struct BE
{
    BE(unsigned char);
};

extern char _DAT_0101595c;

struct FUN_00435150 : BE
{
    unsigned char padding[11];
    int value;

    FUN_00435150(int);
};

// @fnv 0x00435150
FUN_00435150::FUN_00435150(int aiValue) : BE(0x3f)
{
    *reinterpret_cast<void**>(this) = reinterpret_cast<void*>(&_DAT_0101595c);
    value = aiValue;
}
}  // namespace fnv_00435150

namespace fnv_004353a0 {
class FUN_004353d0
{
  public:
    virtual ~FUN_004353d0();
    void* DestroyAndDeallocate(unsigned int flags);
};

void _Deallocate(void* ptr);

// Runs the destructor, and if bit 0 of flags is set, deallocates this object; returns this.
// @fnv 0x004353a0
void* FUN_004353d0::DestroyAndDeallocate(unsigned int flags)
{
    FUN_004353d0::~FUN_004353d0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_004353a0

namespace fnv_00435a90 {
struct FUN_00435ac0
{
    virtual ~FUN_00435ac0();
    void* ScalarDeletingDestructor(unsigned int flags);
};

void _Deallocate(void*);

// Runs the destructor, frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00435a90
void* FUN_00435ac0::ScalarDeletingDestructor(unsigned int flags)
{
    this->FUN_00435ac0::~FUN_00435ac0();

    if (flags & 1)
        _Deallocate(this);

    return this;
}
}  // namespace fnv_00435a90

namespace fnv_00435b80 {
class FUN_00435bb0
{
  public:
    virtual ~FUN_00435bb0();
};

void __cdecl _Deallocate(void* p);

class ExtraSavedHavokData : public FUN_00435bb0
{
  public:
    void* __thiscall FUN_00435b80(unsigned int flags);
};

// Runs the base destructor and, when flags has bit 0 set, deallocates this object; returns this.
// @fnv 0x00435b80
void* __thiscall ExtraSavedHavokData::FUN_00435b80(unsigned int flags)
{
    FUN_00435bb0::~FUN_00435bb0();

    if (flags & 1)
        _Deallocate(this);

    return this;
}
}  // namespace fnv_00435b80

namespace fnv_00435cb0 {
struct ExtraFriendHits
{
    void FUN_00435ce0();
    void* FUN_00435cb0(unsigned int flags);
};

void __cdecl _Deallocate(void*);

// @fnv 0x00435cb0
void* ExtraFriendHits::FUN_00435cb0(unsigned int flags)
{
    FUN_00435ce0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_00435cb0

void __cdecl _Deallocate(void*);

struct ExtraFactionChangesStandIn : ExtraFactionChanges
{
    void* DestroyAndFree(unsigned int flags);
};

// Destructs the ExtraFactionChanges object and, when bit 0 of flags is set, deallocates its memory; returns this.
// @fnv 0x00436d50
void* ExtraFactionChangesStandIn::DestroyAndFree(unsigned int flags)
{
    this->ExtraFactionChanges::~ExtraFactionChanges();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_004376e0 {
struct BE
{
    BE(unsigned char);
};

extern int DAT_01015f48;

struct FUN_004376e0 : BE
{
    FUN_004376e0(int);
};

// @fnv 0x004376e0
FUN_004376e0::FUN_004376e0(int arg) : BE(0x75)
{
    *(int*)this = (int)&DAT_01015f48;
    *(int*)((char*)this + 0xc) = arg;
    *(int*)((char*)this + 0x10) = 0;
    *(int*)((char*)this + 0x14) = 0;
    *(char*)((char*)this + 0x18) = 0;
}
}  // namespace fnv_004376e0

struct ExtraWaterZoneMap
{
    void FUN_004377f0();
    void* FUN_004377c0(unsigned int flags);
};

extern void __cdecl _Deallocate(void*);

// @fnv 0x004377c0
void* ExtraWaterZoneMap::FUN_004377c0(unsigned int flags)
{
    FUN_004377f0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

int __cdecl FUN_0044a670(void* aPtr);

struct FUN_004048e0_cls
{
    void* m_00;
    unsigned short m_04;
    int FUN_004048e0();
};

// Returns m_04 unless it is 0xffff, in which case it returns the result of FUN_0044a670(m_00).
// @fnv 0x004048e0
int FUN_004048e0_cls::FUN_004048e0()
{
    return (m_04 == 0xffff) ? FUN_0044a670(m_00) : m_04;
}

struct TESQuest;
struct TESTopic;
struct TESTopicInfo;
struct MobileObject;

class MenuTopic
{
  public:
    void __thiscall FUN_0083df80(TESQuest*, TESTopic*, TESTopicInfo*, MobileObject*);
};

struct FUN_0042e010_ExtraLock : public BSExtraData
{
    void* unk0C;
    void* unk10;
    TESQuest* unk14;
    TESTopicInfo* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    TESTopic* unk28;
    void* unk2C;

    void __thiscall FUN_0042e010(int);
};

// Calls MenuTopic::FUN_0083df80 with the stored quest, topic and topic info, passing arg as the MobileObject.
// @fnv 0x0042e010
void FUN_0042e010_ExtraLock::FUN_0042e010(int pMobileObject)
{
    reinterpret_cast<MenuTopic*>(this)->FUN_0083df80(unk14, unk28, unk18,
                                                     reinterpret_cast<MobileObject*>(pMobileObject));
}

struct FUN_00430390
{
    ~FUN_00430390();
};
struct FUN_004385a0
{
    unsigned int FUN_0044ddc0();
    FUN_00430390*& FUN_006a7ad0(unsigned int index);
    ~FUN_004385a0();
};
struct FUN_0040ecb0
{
    virtual ~FUN_0040ecb0();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
};
struct FUN_004302d0 : FUN_0040ecb0
{
    FUN_004385a0 members;
    virtual ~FUN_004302d0();
};
// Destructor that iterates the members container and deletes each element returned by FUN_006a7ad0.
// @fnv 0x004302d0
FUN_004302d0::~FUN_004302d0()
{
    for (unsigned int index = 0; index < members.FUN_0044ddc0(); ++index)
    {
        delete members.FUN_006a7ad0(index);
    }
}

extern "C" void __cdecl FormHeap_Free(void* p);
struct FUN_00430ca0
{
    unsigned int unk04;
    unsigned int unk08;
    void* m_pData;
    void FUN_0040ecb0();
    virtual ~FUN_00430ca0();
};
// @fnv 0x00430ca0
FUN_00430ca0::~FUN_00430ca0()
{
    void* p = m_pData;
    FormHeap_Free(p);
    FUN_0040ecb0();
}

extern char DAT_01183b2c;
extern char DAT_011845fc;

struct FUN_00431450_callee;

struct FUN_00431450_cls
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00431450_callee* m_0c;

    bool Probe(int a1);
    bool FUN_00431450(int a1);
};

struct FUN_00431450_callee
{
    bool Check(FUN_00431450_callee* other);
};

void* __cdecl FUN_00ec43fb(int a1, int a2, void* a3, void* a4, int a5);

// @fnv 0x00431450
bool FUN_00431450_cls::FUN_00431450(int a1)
{
    FUN_00431450_cls* p = (FUN_00431450_cls*)FUN_00ec43fb(a1, 0, &DAT_01183b2c, &DAT_011845fc, 0);
    if (p == 0)
    {
        return true;
    }
    if (Probe(a1))
    {
        return true;
    }
    if (m_0c->Check(p->m_0c))
    {
        return true;
    }
    return false;
}

struct ExtraCountShim : public ExtraCount
{
    bool FUN_00431c50(BSExtraData* compare);
};
// @fnv 0x00431c50
bool ExtraCountShim::FUN_00431c50(BSExtraData* compare)
{
    ExtraCount* other = dynamic_cast<ExtraCount*>(compare);
    if (other == 0)
        return true;
    if (BSExtraData::Compare(compare))
        return true;
    if (iCount != other->iCount)
        return true;
    return false;
}

class ExtraModdingItem : public BSExtraData
{
  public:
    unsigned char unk0C;
};

class FUN_004321b0_cls
{
  public:
    bool __thiscall IsDifferentFrom(BSExtraData* a);
};

// Casts a to ExtraModdingItem; returns true if the cast fails, Compare(a) succeeds, or unk0C differs, otherwise false.
// @fnv 0x004321b0
bool __thiscall FUN_004321b0_cls::IsDifferentFrom(BSExtraData* apExtraData)
{
    ExtraModdingItem* pOtherItem = dynamic_cast<ExtraModdingItem*>(apExtraData);
    if (pOtherItem == 0)
    {
        return true;
    }
    if (reinterpret_cast<BSExtraData*>(this)->Compare(apExtraData))
    {
        return true;
    }
    if (((ExtraModdingItem*)reinterpret_cast<char*>(this))->unk0C != pOtherItem->unk0C)
    {
        return true;
    }
    return false;
}

struct ExtraDataBase
{
    virtual void v0();
    unsigned char type;
    ExtraDataBase* next;
    ExtraDataBase(unsigned char type);
};
struct FUN_00432470 : ExtraDataBase
{
    void* pData;
    FUN_00432470(void* data);
};
// Constructs an extra-data object of type 0x4D that stores the given data pointer.
// @fnv 0x00432470
FUN_00432470::FUN_00432470(void* data) : ExtraDataBase(0x4D)
{
    pData = data;
}

struct FUN_0040ec80
{
    virtual void unk_vfn();
    int unk04;
    int unk08;
    FUN_0040ec80(int value);
};

void FUN_0040ec80::unk_vfn()
{}
FUN_0040ec80::FUN_0040ec80(int value)
{}

struct FUN_004325b0 : FUN_0040ec80
{
    unsigned char unk0c;
    FUN_004325b0(unsigned char param);
};

// Constructs the object, initialising the base with 0x31 and storing param into unk0c.
// @fnv 0x004325b0
FUN_004325b0::FUN_004325b0(unsigned char aucValue) : FUN_0040ec80(0x31)
{
    unk0c = aucValue;
}

struct FNV_00432900_Data
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual ~FNV_00432900_Data();

    void SetFlag800(int flag);
};
struct FNV_00432900_Manager
{
    bool FUN_0047c850();
    void FUN_0085a2e0(FNV_00432900_Data* data);
};
extern FNV_00432900_Manager* DAT_011de45c;

struct FUN_00432900 : public BSExtraData
{
    FNV_00432900_Data* pData;
    virtual ~FUN_00432900();
};
// @fnv 0x00432900
FUN_00432900::~FUN_00432900()
{
    if (pData != 0)
    {
        pData->SetFlag800(1);
        if (DAT_011de45c->FUN_0047c850())
        {
            DAT_011de45c->FUN_0085a2e0(pData);
        }
        else
        {
            delete pData;
        }
    }
}

struct FUN_00432da0_object
{
    void FreeAndClear();
    void* FUN_00432da0(unsigned int flags);
};
void __cdecl operator delete(void*);
// Calls FreeAndClear, then deletes this object when flags has bit 0 set, and returns this.
// @fnv 0x00432da0
void* FUN_00432da0_object::FUN_00432da0(unsigned int flags)
{
    FreeAndClear();
    if (flags & 1)
    {
        operator delete(this);
    }
    return this;
}

class C432F80Form
{
  public:
    int unk00;
    int unk04;
    int unk08;
    unsigned int m_uiValue1;

    bool FUN_00432f80(unsigned int uiBit);
};

// @fnv 0x00432f80
bool C432F80Form::FUN_00432f80(unsigned int uiBitIndex)
{
    bool bSet = false;
    if (uiBitIndex < 30)
    {
        unsigned int uiMask = 1 << uiBitIndex;
        if (m_uiValue1 & uiMask)
            bSet = true;
    }
    return bSet;
}

struct B4330E0Effect
{
    int m_iType;
    int m_iValue;
};

template <class T> class B4330E0List
{
  public:
    ~B4330E0List();
    T* GetItemPtr();
    B4330E0List* GetNext();
    void RemoveAll();

    T m_item;
    B4330E0List* m_pkNext;
};

class B4330E0Base
{
  public:
    virtual ~B4330E0Base();

    int unk04;
    int unk08;
};

class FUN_004330e0_cls : public B4330E0Base
{
  public:
    virtual ~FUN_004330e0_cls();

    B4330E0List<B4330E0Effect*>* m_pkEffects;
};

// @fnv 0x004330e0
FUN_004330e0_cls::~FUN_004330e0_cls()
{
    B4330E0List<B4330E0Effect*>* pkNode = m_pkEffects;
    while (pkNode && *pkNode->GetItemPtr())
    {
        B4330E0Effect* pkEffect = *pkNode->GetItemPtr();
        delete pkEffect;
        pkNode = pkNode->GetNext();
    }
    m_pkEffects->RemoveAll();
    delete m_pkEffects;
}

struct FUN_00433ca0 : public BSExtraData
{
    BSSimpleList<void*> kList;
    FUN_00433ca0();
    virtual ~FUN_00433ca0();
};

// Initializes a BSExtraData of type 0x57 with an empty list.
// @fnv 0x00433ca0
FUN_00433ca0::FUN_00433ca0() : BSExtraData(0x57), kList()
{}

struct FUN_00433d10_shell
{
    void FUN_00433d40();
    void operator delete(void*);
    FUN_00433d10_shell* FUN_00433d10(unsigned int flags);
};

// Calls FUN_00433d40, then deletes this when flags has bit 0 set, and returns this.
// @fnv 0x00433d10
FUN_00433d10_shell* FUN_00433d10_shell::FUN_00433d10(unsigned int flags)
{
    FUN_00433d40();
    if (flags & 1)
        operator delete(this);
    return this;
}

extern char DAT_01183b2c;
extern char DAT_01184ea4;

void* FUN_00ec43fb(void* a, void* b, char* c, char* d, unsigned int e);
int FUN_00ec4835(void* a, void* b, unsigned int c);

class FUN_004341e0_cls;

struct FUN_004341e0_node
{
    void* item;
    FUN_004341e0_node* next;

    unsigned int FUN_005ae380();
    bool FUN_008256d0();
    void** FUN_006815c0();
    FUN_004341e0_node* FUN_00726070();
};

class FUN_004341e0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    FUN_004341e0_node m_0c;

    void* FUN_00434410(void* a);
    bool FUN_004341e0(void* a1);
};

// Compares this object's node list against a1's resolved list, returning true on any mismatch or missing item and false when all match.
// @fnv 0x004341e0
bool FUN_004341e0_cls::FUN_004341e0(void* a1)
{
    FUN_004341e0_cls* other;
    FUN_004341e0_node* node7;
    void* item8;
    void* res5;

    other = (FUN_004341e0_cls*)FUN_00ec43fb(a1, 0, &DAT_01183b2c, &DAT_01184ea4, 0);
    if (other == 0)
    {
        return true;
    }
    if (m_0c.FUN_005ae380() != other->m_0c.FUN_005ae380())
    {
        return true;
    }
    node7 = &other->m_0c;
    while (node7 != 0 && !node7->FUN_008256d0())
    {
        item8 = *node7->FUN_006815c0();
        res5 = FUN_00434410(*(void**)item8);
        if (res5 == 0)
        {
            return true;
        }
        if (FUN_00ec4835(res5, item8, 0x1c) != 0)
        {
            return true;
        }
        node7 = node7->FUN_00726070();
    }
    return false;
}

namespace fnv_004342b0 {
extern char DAT_01183b2c;
extern char DAT_01184ea4;
struct Item_004342b0
{
    unsigned int field00;
    unsigned int field04;
    unsigned int field08;
    unsigned int field0C;
    unsigned int field10;
    unsigned int field14;
    unsigned int field18;
    Item_004342b0();
};
struct Node_004342b0
{
    bool FUN_008256d0();
    void** FUN_006815c0();
    Node_004342b0* FUN_00726070();
};
struct Results_004342b0
{
    unsigned int signature;
    unsigned int itemCount;
    unsigned int flags;
    Node_004342b0 firstNode;
};
struct ItemList_004342b0
{
    void FUN_005ae3d0(Item_004342b0**);
};
struct FUN_004342b0_shell
{
    unsigned int field00;
    unsigned int field04;
    unsigned int field08;
    ItemList_004342b0 entries;
    void DeleteAllEntries();
    void LoadItemsFromArchive(void* archive);
};
Results_004342b0* __cdecl FUN_00ec43fb(void*, int, void*, void*, int);
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);

// @fnv 0x004342b0
void FUN_004342b0_shell::LoadItemsFromArchive(void* archive)
{
    Results_004342b0* result = FUN_00ec43fb(archive, 0, &DAT_01183b2c, &DAT_01184ea4, 0);
    if (result == 0)
    {
        return;
    }
    DeleteAllEntries();
    Node_004342b0* node = &result->firstNode;
    while (node != 0 && !node->FUN_008256d0())
    {
        void* pSource = *node->FUN_006815c0();
        Item_004342b0* item = new Item_004342b0();
        memcpy(item, pSource, sizeof(Item_004342b0));
        entries.FUN_005ae3d0(&item);
        node = node->FUN_00726070();
    }
}
}  // namespace fnv_004342b0

namespace fnv_00434620 {
extern char DAT_01183fec;

struct FUN_00434620_key
{
    unsigned int FUN_005ae380();
};

struct FUN_00434620_rec
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    FUN_00434620_key key;
};

struct FUN_00434620_node
{
    void* item;
    FUN_00434620_node* next;
    bool FUN_008256d0();
    void* FUN_006815c0();
    FUN_00434620_node* FUN_00726070();
};

struct FUN_00434620_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    FUN_00434620_key key;
    void* FUN_00434410(unsigned int a);
    bool FUN_00434620(unsigned int a1);
};

FUN_00434620_rec* __cdecl FUN_00ec43fb(unsigned int a1, unsigned int a2, void* a3, void* a4, unsigned int a5);
int __cdecl FUN_00ec4835(void* a1, void* a2, unsigned int a3);

// @fnv 0x00434620
bool FUN_00434620_cls::FUN_00434620(unsigned int uiKey)
{
    FUN_00434620_rec* rec = FUN_00ec43fb(uiKey, 0, &DAT_01183b2c, &DAT_01183fec, 0);
    if (rec == 0)
    {
        return true;
    }
    if (key.FUN_005ae380() != rec->key.FUN_005ae380())
    {
        return true;
    }
    FUN_00434620_node* cur = (FUN_00434620_node*)&rec->key;
    while (cur != 0 && !cur->FUN_008256d0())
    {
        void* x7 = *(void**)cur->FUN_006815c0();
        void* y4 = FUN_00434410(*(unsigned int*)x7);
        if (y4 == 0)
        {
            return true;
        }
        if (FUN_00ec4835(y4, x7, 8) != 0)
        {
            return true;
        }
        cur = cur->FUN_00726070();
    }
    return false;
}
}  // namespace fnv_00434620

int __cdecl FUN_00ec4835(const void* a, const void* b, unsigned int n);
struct S_00434bb0_Item
{
    unsigned int key;
    unsigned int val;
};
struct S_00434bb0_Node
{
    S_00434bb0_Item* item;
    S_00434bb0_Node* next;
    bool FUN_008256d0();
    S_00434bb0_Item** FUN_006815c0();
    S_00434bb0_Node* FUN_00726070();
    int FUN_005ae380();
};
class ExtraReflectorRefs : public BSExtraData
{
  public:
    S_00434bb0_Node list;
    S_00434bb0_Item* FUN_00434410(unsigned int key);
    bool FUN_00434bb0(BSExtraData* apCompare);
};
// Compares this ExtraReflectorRefs against apCompare: returns true if the cast fails, list sizes differ, or any item is missing or differs; false otherwise.
// @fnv 0x00434bb0
bool ExtraReflectorRefs::FUN_00434bb0(BSExtraData* apCompare)
{
    ExtraReflectorRefs* other = dynamic_cast<ExtraReflectorRefs*>(apCompare);
    if (!other)
        return true;
    if (list.FUN_005ae380() != other->list.FUN_005ae380())
        return true;
    S_00434bb0_Node* n = &other->list;
    while (n && !n->FUN_008256d0())
    {
        S_00434bb0_Item* item = *n->FUN_006815c0();
        S_00434bb0_Item* found5 = FUN_00434410(item->key);
        if (!found5)
            return true;
        if (FUN_00ec4835(found5, item, 8))
            return true;
        n = n->FUN_00726070();
    }
    return false;
}

extern char DAT_01183b2c;
extern char DAT_01184058;

struct LinkedNode;
struct ValueArg
{
    int value;
};
struct LinkedNode
{
    int* GetItem();
    bool IsEmpty();
    LinkedNode* GetNext();
};

struct ResultContainer
{
    void* pOwner;
    void* pFirst;
    void* pLast;
    LinkedNode entries;
};

extern "C" ResultContainer* __cdecl func_0x00ec43fb(int, int, void*, void*, int);
extern "C" void __fastcall FUN_00434fa0(void*);
extern "C" void __fastcall AddIfNotInList(void*, ValueArg);
extern "C" bool __fastcall FUN_008256d0(LinkedNode*);
extern "C" ValueArg* __fastcall FUN_006815c0(LinkedNode*);
extern "C" LinkedNode* __fastcall FUN_00726070(LinkedNode*);

struct FUN_00434ee0_Class
{
    void FUN_00434ee0(int);
};

// @fnv 0x00434ee0
void FUN_00434ee0_Class::FUN_00434ee0(int id)
{
    ResultContainer* container = func_0x00ec43fb(id, 0, &DAT_01183b2c, &DAT_01184058, 0);
    if (container == 0)
        return;

    FUN_00434fa0(this);
    LinkedNode* node = &container->entries;
    while (node != 0 && !FUN_008256d0(node))
    {
        AddIfNotInList(this, *FUN_006815c0(node));
        node = FUN_00726070(node);
    }
}

int __cdecl FUN_00408b20(char const* a, char const* b);
struct ExtraLastFinishedSequence : BSExtraData
{
    char* m_name;
    bool FUN_00435310(BSExtraData* arg);
};
// Casts arg to ExtraLastFinishedSequence and returns whether its m_name differs from this object's m_name, or true if the cast fails.
// @fnv 0x00435310
bool ExtraLastFinishedSequence::FUN_00435310(BSExtraData* apExtra)
{
    ExtraLastFinishedSequence* p = dynamic_cast<ExtraLastFinishedSequence*>(apExtra);
    if (p == 0)
        return true;
    if (FUN_00408b20(m_name, p->m_name) != 0)
        return true;
    return false;
}

void __cdecl FormHeap_Free(void*);

struct FUN_004355c0_cls
{
    void FUN_004355f0();
    FUN_004355c0_cls* FUN_004355c0(int flags);
};

// Calls FUN_004355f0, then if bit 0 of flags is set calls FormHeap_Free on this, and returns this.
// @fnv 0x004355c0
FUN_004355c0_cls* FUN_004355c0_cls::FUN_004355c0(int flags)
{
    FUN_004355f0();
    if (flags & 1)
    {
        FormHeap_Free(this);
    }
    return this;
}

extern int DAT_01015e4c;
extern "C" void __cdecl FormHeap_Free(void*);

struct EmittanceSourceCleanup : BSExtraData
{
    void* ownedSource;
    void __thiscall FUN_0040ecb0();
    void __thiscall FUN_004355f0();
};

// Sets the vtable pointer, frees ownedSource via FormHeap_Free, then calls FUN_0040ecb0.
// @fnv 0x004355f0
void __thiscall EmittanceSourceCleanup::FUN_004355f0()
{
    *reinterpret_cast<void**>(this) = &DAT_01015e4c;
    void* sourceToFree = ownedSource;
    FormHeap_Free(sourceToFree);
    FUN_0040ecb0();
}

class Point3Offset
{
  public:
    bool FUN_00439060(Point3Offset* other);
};

class FUN_00435630_shell : public ExtraMultiBoundData
{
  public:
    bool FUN_00435630(BSExtraData* apCompare);
};

// @fnv 0x00435630
bool FUN_00435630_shell::FUN_00435630(BSExtraData* apCompare)
{
    ExtraMultiBoundData* pOther = dynamic_cast<ExtraMultiBoundData*>(apCompare);
    if (pOther == 0)
        return true;
    if (pBound->FUN_00439060(pOther->pBound))
        return true;
    return false;
}

// Constructor: calls the base constructor with 0x61, installs this class's vtable,
// constructs a sub-object at +0xc, calls one method on it, and returns this.
struct NiObjectBase_cls
{
    NiObjectBase_cls(unsigned char aType);
    ~NiObjectBase_cls();
    virtual void v00();
    unsigned int unk04;
    unsigned int unk08;
};

struct SubObject_cls
{
    SubObject_cls(int aArg);
    ~SubObject_cls();
    void Do(int aArg);
    unsigned int unk00;
};

struct FUN_00435690 : public NiObjectBase_cls
{
    FUN_00435690();
    SubObject_cls m_sub;
};

// Constructs the object with base type 0x61, initialises m_sub with 0 and calls m_sub.Do(0).
// @fnv 0x00435690
FUN_00435690::FUN_00435690() : NiObjectBase_cls(0x61), m_sub(0)
{
    m_sub.Do(0);
}

class Base435
{
  public:
    ~Base435();

    int unk00;
    int unk04;
    int unk08;
};

class List435
{
  public:
    ~List435();

    int unk00;
    int unk04;
};

class FUN_00435740 : public Base435
{
  public:
    ~FUN_00435740();

    List435 m_kList;
};

// Destructor for the object; the body is empty and the base and list members are destroyed implicitly.
// @fnv 0x00435740
FUN_00435740::~FUN_00435740()
{}

struct ExtraMember
{
    ExtraMember(int initial);
    ~ExtraMember();
    void Reset(int value);
};

class FUN_004358a0 : public BSExtraData
{
  public:
    ExtraMember member;
    FUN_004358a0();
    virtual ~FUN_004358a0();
};

// Constructs a BSExtraData with type 0x79 and initializes member to 0 via Reset.
// @fnv 0x004358a0
FUN_004358a0::FUN_004358a0() : BSExtraData(0x79), member(0)
{
    member.Reset(0);
}

class B35950ExtraData
{
  public:
    B35950ExtraData(unsigned char ucType);
    virtual ~B35950ExtraData();

    unsigned char m_ucType;
    void* m_pkNext;
};

class StrList
{
  public:
    StrList();

    void* m_pkHead;
    void* m_pkTail;
};

class FUN_00435950 : public B35950ExtraData
{
  public:
    FUN_00435950();
    virtual ~FUN_00435950();

    StrList m_kList;
};

// @fnv 0x00435950
FUN_00435950::FUN_00435950() : B35950ExtraData(0x3a)
{}

struct PredicateValue
{
    unsigned int key;
    signed char flag;
};
struct PredicateNode
{
    PredicateValue** FUN_006815c0();
    PredicateNode* FUN_00726070();
};
struct PredicateOwner
{
    unsigned int unk00, unk04, unk08;
    PredicateNode* unk0c;
    bool HasMatchingValue(unsigned int key);
};
// Walks the node chain from unk0c and returns true if a value with the given key and flag -1 is found.
// @fnv 0x00437080
bool PredicateOwner::HasMatchingValue(unsigned int key)
{
    PredicateNode* node = unk0c;
    while (node && *node->FUN_006815c0())
    {
        PredicateValue* value = *node->FUN_006815c0();
        if (key == value->key && value->flag == -1)
            return true;
        node = node->FUN_00726070();
    }
    return false;
}

struct MergeItem
{
    int* key;
    unsigned char state;
};
struct MergeNode
{
    MergeItem** FUN_006815c0();
    MergeNode* FUN_00726070();
    void FUN_005ae3d0(MergeItem*&);
};
struct MergeSourceList
{
    MergeNode* FUN_005d8a70();
};
struct MergeSource
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    unsigned int unk18, unk1c, unk20, unk24, unk28, unk2c;
    MergeSourceList list;
};
struct MergeMap
{
    unsigned int unk00, unk04, unk08, unk0c;
    MergeMap(unsigned int);
    ~MergeMap();
    void FUN_005594e0(int*, bool);
    bool FUN_0057c850(int*, bool*);
};
struct MergeState
{
    unsigned int unk00, unk04, unk08;
    MergeNode* list;
    void FUN_004370f0(MergeSource* source);
};
// @fnv 0x004370f0
void MergeState::FUN_004370f0(MergeSource* source)
{
    MergeMap keyMap(37);
    MergeNode* node = list;
    while (node && *node->FUN_006815c0())
    {
        MergeItem* oldItem = *node->FUN_006815c0();
        node = node->FUN_00726070();
        oldItem->state = 255;
        keyMap.FUN_005594e0(oldItem->key, true);
    }
    if (source)
    {
        node = source->list.FUN_005d8a70();
        while (node && *node->FUN_006815c0())
        {
            MergeItem* p = *node->FUN_006815c0();
            node = node->FUN_00726070();
            bool j = false;
            if (!keyMap.FUN_0057c850(p->key, &j) || !j)
            {
                MergeItem* newItem = new MergeItem;
                newItem->key = p->key;
                newItem->state = 255;
                list->FUN_005ae3d0(newItem);
            }
        }
    }
}

struct TopicInfoList
{
    void* pItem;
    TopicInfoList* pNext;
    TopicInfoList();
};

struct FUN_00437440 : BSExtraData
{
    TopicInfoList* pTopics;
    FUN_00437440();
    virtual ~FUN_00437440();
};

// @fnv 0x00437440
FUN_00437440::FUN_00437440() : BSExtraData(0x73)
{
    pTopics = new TopicInfoList;
}

extern char DAT_01183b2c;
extern char DAT_01184078;

struct FUN_0084e3a0_Class
{
    void* FUN_0084e3a0();
};

struct FUN_0041fd00_Class
{
    void FUN_0041fd00(void* aPtr);
};

struct FUN_00438330_cls
{
    unsigned int m_i00;
    unsigned int m_i04;
    unsigned int m_i08;
    unsigned int m_i0C;
    float m_f10;
    void FUN_00438330(BSExtraData* a1);
};

extern "C" void* __cdecl FUN_00ec43fb(BSExtraData* a1, int a2, char* a3, char* a4, int a5);

// @fnv 0x00438330
void FUN_00438330_cls::FUN_00438330(BSExtraData* pExtraData)
{
    FUN_00438330_cls* pSource = (FUN_00438330_cls*)FUN_00ec43fb(pExtraData, 0, &DAT_01183b2c, &DAT_01184078, 0);
    if (pSource == 0)
    {
    }
    else
    {
        ((FUN_0041fd00_Class*)this)->FUN_0041fd00(((FUN_0084e3a0_Class*)pSource)->FUN_0084e3a0());
        this->m_f10 = pSource->m_f10;
    }
}

struct LimbArrayStub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    bool IsSame(LimbArrayStub* apOther);
    void Clear(bool abFree);
};
struct LimbEntry
{
    unsigned char m_bCrippled;
    unsigned char bExplode;
    unsigned char bPickResultFound;
    unsigned char unk03;
    LimbArrayStub kData;
    LimbEntry();
};
struct LimbRefStub;
struct LimbBaseStub
{
    void ApplyLimb(LimbRefStub* apActor, void* apData, LimbArrayStub* apOut);
};
struct LimbRefStub
{
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
    virtual bool IsActorV();
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
    virtual void* GetLimbDataV();
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
    virtual bool CanDismemberV();
    LimbBaseStub* GetActorBase();
};
struct LimbEntryArray
{
    unsigned int Add(LimbEntry*& arEntry);
    LimbEntry*& GetAt(int aiIndex);
};
struct LimbsStandIn
{
    int unk00;
    int unk04;
    int unk08;
    unsigned short usLimbBits;
    unsigned short unk0E;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    LimbEntryArray kEntries;
    bool IsDismembered(unsigned int auiLimb);
    void FUN_00430410(LimbRefStub* apRef, unsigned int auiLimb, bool abExplode);
};

// Marks the limb bit, appends a new LimbEntry, and for non-player actors with dismemberment applies limb data and flags duplicates.
// @fnv 0x00430410
void LimbsStandIn::FUN_00430410(LimbRefStub* apRef, unsigned int auiLimb, bool abExplode)
{
    if (IsDismembered(auiLimb))
        return;
    usLimbBits |= 1 << auiLimb;
    LimbEntry* pEntry = new LimbEntry;
    unsigned int uiEntryIndex = kEntries.Add(pEntry);
    pEntry->m_bCrippled = auiLimb;
    pEntry->bExplode = abExplode;
    pEntry->bPickResultFound = 0;
    if (abExplode)
    {
        pEntry->bPickResultFound = 1;
        return;
    }
    if (apRef->IsActorV() && (void*)apRef != (void*)g_thePlayer)
    {
        LimbRefStub* pActor = apRef;
        if (pActor->CanDismemberV())
        {
            LimbRefStub* pActor4 = pActor;
            LimbBaseStub* pBase9 = pActor4->GetActorBase();
            pBase9->ApplyLimb(pActor4, pActor4->GetLimbDataV(), &pEntry->kData);
            if (uiEntryIndex > 0)
            {
                for (int iIndex = uiEntryIndex - 1; iIndex >= 0; --iIndex)
                {
                    LimbEntry* pOther = kEntries.GetAt(iIndex);
                    if (pOther->bPickResultFound)
                        continue;
                    if (pOther->kData.IsSame(&pEntry->kData))
                    {
                        pEntry->bPickResultFound = 1;
                        pEntry->kData.Clear(true);
                    }
                    break;
                }
            }
        }
    }
}

struct EntryValue
{
    bool IsEqual(EntryValue* other);
};
struct ComparisonEntry
{
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    EntryValue sub;
};
struct EntryListNode
{
    unsigned int FUN_0044ddc0();
    ComparisonEntry*& FUN_006a7ad0(unsigned int index);
};
struct EntryCollection
{
    void* vtbl;
    int unk04;
    int unk08;
    unsigned short unk0C;
    unsigned short unk0E;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    EntryListNode entries;

    bool FUN_00430660(EntryCollection* other);
};

// Compares unk0C, entry counts and each entry's four bytes and sub-value against another EntryCollection, returning true only if all match.
// @fnv 0x00430660
bool EntryCollection::FUN_00430660(EntryCollection* other)
{
    if (other->unk0C != unk0C)
        return false;
    if (other->entries.FUN_0044ddc0() != entries.FUN_0044ddc0())
        return false;
    for (unsigned int i = 0; i < entries.FUN_0044ddc0(); i++)
    {
        ComparisonEntry* mine = entries.FUN_006a7ad0(i);
        ComparisonEntry* theirs = other->entries.FUN_006a7ad0(i);
        if (mine->b0 != theirs->b0)
            return false;
        if (mine->b1 != theirs->b1)
            return false;
        if (mine->b2 != theirs->b2)
            return false;
        if (mine->b3 != theirs->b3)
            return false;
        if (!mine->sub.IsEqual(&theirs->sub))
            return false;
    }
    return true;
}

// Constructor of a BSExtraData subclass (extra type 0x91) holding one pointer at +0xC.
// Uses the unit's BE431 stand-in base (BSExtraData ctor + vtable slot) like FUN_00431230.
struct ExtraRecordData;
struct FUN_00431620 : BE431
{
    ExtraRecordData* pData;
    FUN_00431620(ExtraRecordData* apData);
};

// Constructs a BE431 with tag 0x91 and stores the given ExtraRecordData pointer in pData.
// @fnv 0x00431620
FUN_00431620::FUN_00431620(ExtraRecordData* apData) : BE431(0x91), pData(apData)
{}

class ExtraGlobalCompare431 : public ExtraGlobal
{
  public:
    bool FUN_00431b10(BSExtraData* pkOther);
};

// @fnv 0x00431b10
bool ExtraGlobalCompare431::FUN_00431b10(BSExtraData* pkOther)
{
    ExtraGlobal* pkGlobal = dynamic_cast<ExtraGlobal*>(pkOther);
    if (!pkGlobal)
        return true;
    if (Compare(pkOther))
        return true;
    if (pGlobalForm != pkGlobal->pGlobalForm)
        return true;
    return false;
}

// Extra-data compare: differs when the other is not script extra data, the base data differs, or the scripts differ.

class C20D0ScriptExtra : public BSExtraData
{
  public:
    void* m_pkScript;

    bool BaseCompare(BSExtraData* pkOther);
    bool CompareScriptExtra(BSExtraData* pkOther);
};

// @fnv 0x004320d0
bool C20D0ScriptExtra::CompareScriptExtra(BSExtraData* pkOther)
{
    ExtraScript* pkScript = dynamic_cast<ExtraScript*>(pkOther);
    if (!pkScript)
        return true;
    if (BaseCompare(pkOther))
        return true;
    if (m_pkScript != pkScript->pScript)
        return true;
    return false;
}

class FUN_004328d0 : public BSExtraData
{
  public:
    unsigned int uiValue;
    FUN_004328d0(unsigned int auiValue);
    virtual ~FUN_004328d0();
};

// Constructs a BSExtraData of type 0x1a and stores the given value in uiValue.
// @fnv 0x004328d0
FUN_004328d0::FUN_004328d0(unsigned int auiValue) : BSExtraData(0x1a)
{
    uiValue = auiValue;
}

struct FUN_00432aa0 : BE430
{
    BSSimpleList<BSSimpleList<MenuTopic*>*>* m_pTopicLists;

    FUN_00432aa0(BSSimpleList<MenuTopic*>* apTopicList);
    virtual void v0();
};

// Constructs a BE430 with id 0x35, allocates a list of topic lists and adds apTopicList as its head.
// @fnv 0x00432aa0
FUN_00432aa0::FUN_00432aa0(BSSimpleList<MenuTopic*>* apTopicList) : BE430(0x35)
{
    m_pTopicLists = new BSSimpleList<BSSimpleList<MenuTopic*>*>;
    m_pTopicLists->AddHead(apTopicList);
}

struct FUN_004331c0_rec
{
    unsigned int key;
    unsigned char flag;
    static void* __cdecl operator new(unsigned int);
};

class FUN_005ae3d0_cls
{
  public:
    void FUN_005ae3d0(FUN_004331c0_rec** pp);
};

class FUN_00726070_cls
{
  public:
    ContNode* FUN_00726070();
};

class FUN_004331c0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    ContNode* m_0c;

    void FUN_004331c0(unsigned int a1, unsigned char a2);
};

// Searches the list at m_0c for a record whose key equals a1, creates and inserts one if missing, then sets its key and flag.
// @fnv 0x004331c0
void FUN_004331c0_cls::FUN_004331c0(unsigned int uiKey, unsigned char ucFlag)
{
    FUN_004331c0_rec* item = 0;
    FUN_004331c0_rec* found = 0;
    {
        ContNode* cur = m_0c;
        while (cur != 0)
        {
            found = (FUN_004331c0_rec*)*(void**)cur->FUN_006815c0();
            if (found != 0)
            {
                if (found->key == uiKey)
                {
                    item = found;
                    break;
                }
                cur = ((FUN_00726070_cls*)cur)->FUN_00726070();
            }
            else
            {
                cur = 0;
            }
        }
    }
    if (item == 0)
    {
        item = new FUN_004331c0_rec;
        ((FUN_005ae3d0_cls*)m_0c)->FUN_005ae3d0(&item);
    }
    item->key = uiKey;
    item->flag = ucFlag;
}

class B433260Point3
{
  public:
    B433260Point3();
    B433260Point3(float fX, float fY, float fZ);

    float x;
    float y;
    float z;
};

extern const float g_f433260DefaultZ;

class B433260Form
{
  public:
    B433260Form(unsigned char ucType);
    virtual ~B433260Form();

    int unk04;
    int unk08;
};

class FUN_00433260_cls : public B433260Form
{
  public:
    FUN_00433260_cls();
    virtual ~FUN_00433260_cls();

    B433260Point3 m_kOffset;
};

// Constructs a B433260Form with type 0x13 and initializes m_kOffset to (0, 0, g_f433260DefaultZ).
// @fnv 0x00433260
FUN_00433260_cls::FUN_00433260_cls() : B433260Form(0x13)
{
    m_kOffset = B433260Point3(0.0f, 0.0f, g_f433260DefaultZ);
}

// @fnv 0x004336f0
void* __cdecl FindContRecordByFormId(int wantedFormId, ContNode* first)
{
    void* result = 0;
    ContNode* node = first;
    while (node != 0 && !node->FUN_008256d0())
    {
        void* record = *(void**)node->FUN_006815c0();
        if (*(int*)record == wantedFormId)
        {
            result = record;
            break;
        }
        node = node->GetNext();
    }
    return result;
}

struct ActivateEntry334
{
    TESObjectREFR* reference;
    float delay;
};
struct ActivateList334
{
    ActivateEntry334* value;
    ActivateList334* next;
    unsigned int ItemsInList();
    bool IsEmpty();
    ActivateEntry334*& GetItem();
    ActivateList334* GetNext();
};
struct ActivateString334
{
    char* value;
    unsigned short length, capacity;
    unsigned int GetLength();
    operator const char*() const;
};
int __cdecl FUN_00408b20(const char*, const char*);
class ExtraActivateRef : public BSExtraData
{
  public:
    ActivateList334 references;
    unsigned char flags;
    unsigned char unk15, unk16, unk17;
    ActivateString334 text;
    ActivateEntry334* Find(TESObjectREFR*);
    bool FUN_00433a20(BSExtraData*);
};
// Compares this ExtraActivateRef with another: returns true if reference lists, flags or text differ, false if equal.
// @fnv 0x00433a20
bool ExtraActivateRef::FUN_00433a20(BSExtraData* pOther)
{
    ExtraActivateRef* node = dynamic_cast<ExtraActivateRef*>(pOther);
    if (!node)
        return true;
    if (references.ItemsInList() != node->references.ItemsInList())
        return true;
    ActivateList334* other = &references;
    while (other && !other->IsEmpty())
    {
        ActivateEntry334* entry = other->GetItem();
        ActivateEntry334* match = node->Find(entry->reference);
        if (!match || memcmp(match, entry, 8) != 0)
            return true;
        other = other->GetNext();
    }
    if (flags != node->flags)
        return true;
    if (!text.GetLength() && !node->text.GetLength())
    {
    }
    else if (!text.GetLength() || !node->text.GetLength())
    {
        return true;
    }
    else
    {
        if (FUN_00408b20(text, node->text))
            return true;
    }
    return false;
}

namespace fnv_004346f0 {
#include <string.h>

struct ReflectedReferenceRecord
{
    TESObjectREFR* m_pWorldReferenceInfo;
    unsigned int uiFlags;
    ReflectedReferenceRecord();
};
typedef BSSimpleList<ReflectedReferenceRecord*> RefReflectedList;
// ExtraReflectedRefs::Copy
struct FUN_004346f0_shell : public ExtraReflectedRefs
{
    void CopyReflectedRefs(BSExtraData* apSource);
};
// @fnv 0x004346f0
void FUN_004346f0_shell::CopyReflectedRefs(BSExtraData* apSource)
{
    ExtraReflectedRefs* pSource = dynamic_cast<ExtraReflectedRefs*>(apSource);
    if (!pSource)
        return;
    ClearReferenceData();
    RefReflectedList* pIter = (RefReflectedList*)pSource->RefList;
    while (pIter && !pIter->IsEmpty())
    {
        ReflectedReferenceRecord* pData = pIter->GetItem();
        ReflectedReferenceRecord* pCopy = new ReflectedReferenceRecord;
        memcpy(pCopy, pData, sizeof(ReflectedReferenceRecord));
        ((RefReflectedList*)RefList)->AddHead(pCopy);
        pIter = pIter->GetNext();
    }
}
}  // namespace fnv_004346f0

void* __cdecl FUN_00ec43fb(int, int, void*, void*, int);
extern char DAT_01184034;

struct FUN_00434a70_cls
{
    void Helper0();
    void Helper1(unsigned int v);
    void FUN_00434a70(int arg);
};

// @fnv 0x00434a70
void FUN_00434a70_cls::FUN_00434a70(int arg)
{
    void* ret = FUN_00ec43fb(arg, 0, &DAT_01183b2c, &DAT_01184034, 0);
    if (ret == 0)
    {
    }
    else
    {
        Helper0();
        ContNode* p = (ContNode*)((char*)ret + 0xc);
        while (p != 0 && p->FUN_008256d0() == 0)
        {
            Helper1(*(unsigned int*)p->FUN_006815c0());
            p = p->GetNext();
        }
    }
}

struct Entry434
{
    int m_iFirst;
    int m_iSecond;
};

class List434
{
  public:
    ~List434();

    bool IsEmpty();
    Entry434** GetItem();
    List434* GetNext();
    void RemoveAll();

    Entry434* m_pkItem;
    List434* m_pkNext;
};

class ExtraData434
{
  public:
    virtual ~ExtraData434();

    unsigned char m_ucType;
    ExtraData434* m_pkNext;
};

class FUN_00434af0 : public ExtraData434
{
  public:
    virtual ~FUN_00434af0();

    List434 m_kEntries;
};

// Deletes every entry in m_kEntries, walking the list nodes, then clears the list.
// @fnv 0x00434af0
FUN_00434af0::~FUN_00434af0()
{
    List434* pkNode = &m_kEntries;
    while (pkNode && !pkNode->IsEmpty())
    {
        Entry434* pkEntry = *pkNode->GetItem();
        delete pkEntry;
        pkNode = pkNode->GetNext();
    }
    m_kEntries.RemoveAll();
}

struct FNVLoadEntry
{
    unsigned int first;
    unsigned int second;
    FNVLoadEntry();
};
struct FNVLoadList
{
    void FUN_005ae3d0(FNVLoadEntry** item);
};
struct FNVLoadBlock
{
    void* value00;
    void* value04;
    void* value08;
    ContNode firstNode;
};
struct FNVLoadHost : FUN_00434d90_standin
{
    void LoadEntriesFromBlock(void* input);
};
extern unsigned char DAT_01184010;
extern FNVLoadBlock* __cdecl FUN_00ec43fb(void* input, int unused, const void* sourceA, const void* sourceB, int mode);

// @fnv 0x00434c80
void FNVLoadHost::LoadEntriesFromBlock(void* input)
{
    ContNode* node;
    FNVLoadBlock* block = FUN_00ec43fb(input, 0, &DAT_01183b2c, &DAT_01184010, 0);
    if (!block)
        return;
    FUN_00434d90();
    node = &block->firstNode;
    while (node && !node->FUN_008256d0())
    {
        void* contents = *(void**)node->FUN_006815c0();
        {
            FNVLoadEntry* entry = new FNVLoadEntry;
            memcpy(entry, contents, 8);
            ((FNVLoadList*)&m_kNode)->FUN_005ae3d0(&entry);
        }
        node = node->GetNext();
    }
}

struct FUN_00726070_shell
{
    ContNode* FUN_00726070();
};

struct FUN_00436f20_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    ContNode* m_0c;

    void SetValueByKey(unsigned int aKey, unsigned char aVal);
};

// Walks the node chain from m_0c and, when a node's item key equals aKey, writes aVal into byte 4 of that item.
// @fnv 0x00436f20
void FUN_00436f20_cls::SetValueByKey(unsigned int aKey, unsigned char aVal)
{
    ContNode* cur = m_0c;
    while (cur != 0 && *(void**)cur->FUN_006815c0() != 0)
    {
        unsigned int* item = *(unsigned int**)cur->FUN_006815c0();
        if (aKey == *item)
        {
            ((unsigned char*)item)[4] = aVal;
            break;
        }
        cur = ((FUN_00726070_shell*)cur)->FUN_00726070();
    }
}

struct FUN_004377f0
{
    BSExtraData base;
    BSSimpleArrayShell member;
    ~FUN_004377f0();
};

// @fnv 0x004377f0
FUN_004377f0::~FUN_004377f0()
{}

template <class TKEY, class TVAL> class NiTPointerMap
{
  public:
    bool GetAt(TKEY key, TVAL& val) const;
    void SetAt(TKEY key, TVAL val);
    bool RemoveKey(TKEY key);  // RemoveAt
    void* GetFirstPos();
    void FUN_006b7f20(void*& pos, TKEY& key, TVAL& val);  // GetNext
    void* m_pVtbl;
    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
};
extern float DAT_01015f5c;
struct FUN_00437850_Entry
{
    char pad00[0x18];
    float fPriority;
};
struct FUN_00437850_Class
{
    char pad00[0xc];
    NiTPointerMap<unsigned int, unsigned int> kRefCounts;
    FUN_00437850_Entry* pTop;
    void UpdatePriorityEntry(FUN_00437850_Entry* pEntry, bool bAdd);
};
// @fnv 0x00437850
void FUN_00437850_Class::UpdatePriorityEntry(FUN_00437850_Entry* pEntry, bool bAdd)
{
    float fTop = DAT_01015f5c;
    if (bAdd)
    {
        unsigned int ItemUpdateArray = 0;
        kRefCounts.GetAt((unsigned int)pEntry, ItemUpdateArray);
        kRefCounts.SetAt((unsigned int)pEntry, 1);
        if (pEntry->fPriority > fTop)
        {
            fTop = pEntry->fPriority;
            pTop = pEntry;
        }
    }
    else
    {
        unsigned int ItemUpdateArray = 0;
        kRefCounts.GetAt((unsigned int)pEntry, ItemUpdateArray);
        if ((int)ItemUpdateArray <= 1)
        {
            kRefCounts.RemoveKey((unsigned int)pEntry);
            void* pPos = kRefCounts.GetFirstPos();
            fTop = DAT_01015f5c;
            while (pPos)
            {
                unsigned int uiKey;
                unsigned int uiVal;
                kRefCounts.FUN_006b7f20(pPos, uiKey, uiVal);
                if (((FUN_00437850_Entry*)uiKey)->fPriority > fTop)
                {
                    fTop = ((FUN_00437850_Entry*)uiKey)->fPriority;
                    pTop = (FUN_00437850_Entry*)uiKey;
                }
            }
        }
        else
        {
            kRefCounts.SetAt((unsigned int)pEntry, ItemUpdateArray - 1);
        }
    }
}

class Point437
{
  public:
    float x, y, z;
    static const Point437 ZERO;
};

class ExtraData437
{
  public:
    ExtraData437(unsigned char ucType);
    virtual ~ExtraData437();

    unsigned char m_ucType;
    ExtraData437* m_pkNext;
};

class StrList437
{
  public:
    StrList437();

    void* m_pkHead;
    void* m_pkTail;
};

class FUN_00437c40 : public ExtraData437
{
  public:
    FUN_00437c40();
    virtual ~FUN_00437c40();

    int m_iValue;
    Point437 m_kPos;
    int m_iArrayLength;
    StrList437 m_kList;
};

// Initializes an ExtraData437-derived object with type 0x8b, zero value, zero position, and zero field.
// @fnv 0x00437c40
FUN_00437c40::FUN_00437c40() : ExtraData437(0x8b), m_iValue(0), m_kPos(Point437::ZERO), m_iArrayLength(0)
{}

class NiNode;
class NiTexture;
class NiSourceTexture;

template <> class NiPointer<NiSourceTexture>
{
  public:
    NiSourceTexture* m_pObject;
    NiPointer(NiSourceTexture* p = 0);
    ~NiPointer();
    operator NiSourceTexture*() const;
};

class NiProperty
{
  public:
    void FUN_00438230(NiTexture* pTexture);
};

struct MyFixedString : public NiFixedString
{
    MyFixedString(const char* s);
    ~MyFixedString();
};

struct NiAVObject
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
    virtual void v12();
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
    virtual NiAVObject* GetObjectByName(const MyFixedString& kName);
    NiProperty* GetProperty(unsigned int uiType);
};

class NiNode : public NiAVObject
{
};

class TES
{
  public:
    void CreateTextureImage(const char* pszPath, NiPointer<NiSourceTexture>& rspTexture, bool b1, bool b2);
};
extern TES* g_TES;

int __cdecl _sprintf_s(char* buffer, unsigned int sizeOfBuffer, const char* format, ...);
bool __cdecl FUN_004b7240(const char* src, char* dst, unsigned int maxLen);
unsigned int __cdecl FUN_00438220();

struct ExtraSecuritronFaceStandIn : public ExtraSecuritronFace
{
    BSStringT<char> GetStr1();
    BSStringT<char> GetStr2();
    void FUN_00437f90(NiNode* pNode);
};

// Builds a texture path from the face strings, creates the texture image, and assigns it to the Screen01:0 object's property.
// @fnv 0x00437f90
void ExtraSecuritronFaceStandIn::FUN_00437f90(NiNode* pNode)
{
    NiAVObject* aPScreen;
    NiProperty* pProperty4;
    if (pNode)
    {
        aPScreen = pNode->GetObjectByName(MyFixedString("Screen01:0"));
        if (aPScreen)
        {
            char destBufferA[260];
            NiPointer<NiSourceTexture> spTexture = 0;
            char buffer7[260];
            BSStringT<char> str6 = this->GetStr1();
            BSStringT<char> str2 = this->GetStr2();

            if (str6.GetLength() > 0 && str2.GetLength() > 0)
            {
                _sprintf_s(buffer7, 260, "Textures\\creatures\\Securitron\\%s_%s.dds", str6.GetString(),
                           str2.GetString());
                FUN_004b7240(buffer7, destBufferA, 260);
                g_TES->CreateTextureImage(destBufferA, spTexture, false, false);
            }

            pProperty4 = aPScreen->GetProperty(FUN_00438220());
            if (pProperty4)
            {
                pProperty4->FUN_00438230((NiTexture*)(NiSourceTexture*)spTexture);
            }
        }
    }
}

struct HighProcess
{
    HighProcess();
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
};

struct ProcStateObj
{
    void* GetCullResult();
};

struct OwnerForm
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
    virtual ProcStateObj* GetStateObj();
};

struct ProcessListsStub
{
    float GetCurrentTime();
};
extern ProcessListsStub g_processLists;

void* GetDefaultPackageData();

struct FormBase
{
    virtual ~FormBase();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct ChildCellBase
{
    virtual void* GetPersistentCell();
};

struct MobileObjectBase : FormBase, ChildCellBase
{
    MobileObjectBase();
    void SetLocationOnReference(const NiPoint3& pos);
    void SetReferencePosition(NiPoint3 rot);
    void SetStateValue(void* value);
    void SetPackageData(void* data);
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
    float unk88;
    float unk8C;
};

struct FUN_0081dd00 : MobileObjectBase
{
    FUN_0081dd00(OwnerForm* owner, int arg2, int arg3, int arg4, NiPoint3 pos, NiPoint3 rot);
    virtual ~FUN_0081dd00();
    float unk90;
    OwnerForm* owner;
    int unk98;
    int unk9C;
    int unkA0;
    float startTime;
};

// @fnv 0x0081dd00
FUN_0081dd00::FUN_0081dd00(OwnerForm* owner, int arg2, int arg3, int arg4, NiPoint3 pos, NiPoint3 rot)
{
    unk90 = 0.0f;
    this->owner = owner;
    unk98 = arg2;
    unk9C = arg3;
    unkA0 = arg4;
    startTime = g_processLists.GetCurrentTime();
    unk88 = 0.0f;
    unk8C = 0.0f;
    process = new HighProcess;
    SetLocationOnReference(pos);
    SetReferencePosition(rot);
    ProcStateObj* state = owner->GetStateObj();
    if (state)
    {
        SetStateValue(state->GetCullResult());
    }
    SetPackageData(GetDefaultPackageData());
}

struct ContNode;
bool __fastcall FUN_008256d0(ContNode*);
void* __fastcall FUN_006815c0(void*);
void __cdecl operator delete(void*);
struct ListNode
{
    void* m_item;
    ListNode* m_pkNext;
    void FUN_0063f7b0();
};
// @fnv 0x00433750
void __cdecl FUN_00433750(ListNode* pNode)
{
    if (pNode != 0)
    {
        while (!FUN_008256d0((ContNode*)pNode))
        {
            void* p = *(void**)FUN_006815c0(pNode);
            operator delete(p);
            pNode->FUN_0063f7b0();
        }
    }
}

class SHELL_MEMBER
{
  public:
    int unk00;
    SHELL_MEMBER();
};

class FUN_00435c40 : public BSExtraData
{
  public:
    SHELL_MEMBER array;
    FUN_00435c40();
    ~FUN_00435c40();
};

// Constructs a BSExtraData-derived object with type 0x45 and default-constructs its array member.
// @fnv 0x00435c40
FUN_00435c40::FUN_00435c40() : BSExtraData(0x45)
{}

class FUN_00430ce0_D : public BSExtraData
{
  public:
    LockExtraData* lock;
    bool FUN_00430ce0(BSExtraData* other);
};

// @fnv 0x00430ce0
bool FUN_00430ce0_D::FUN_00430ce0(BSExtraData* other)
{
    ExtraLock* otherLock = dynamic_cast<ExtraLock*>(other);
    if (otherLock == 0)
    {
        return true;
    }
    if (BSExtraData::Compare(other))
    {
        return true;
    }
    if (lock->cFlags != otherLock->lock->cFlags)
    {
        return true;
    }
    if (lock->pKey != otherLock->lock->pKey)
    {
        return true;
    }
    if (LockExtraData::ConvertLockLevel(lock->m_uiLockState) != LockExtraData::ConvertLockLevel(otherLock->lock->m_uiLockState))
    {
        return true;
    }
    if (lock->m_uiLockDifficulty != otherLock->lock->m_uiLockDifficulty)
    {
        return true;
    }
    if (lock->m_uiLockValue != otherLock->lock->m_uiLockValue)
    {
        return true;
    }
    return false;
}

extern char DAT_01015b28;
struct FUN_004300c0_cls
{
    void* vfptr;
    int unk04;
    int unk08;
    int unk0C;
    void FUN_0040ec80(int a);
    FUN_004300c0_cls* Initialize(int a);
};

// Calls FUN_0040ec80 with 0x10, sets the vtable pointer to DAT_01015b28, stores a in unk0C, and returns this.
// @fnv 0x004300c0
FUN_004300c0_cls* FUN_004300c0_cls::Initialize(int aiValue)
{
    FUN_0040ec80(0x10);
    vfptr = &DAT_01015b28;
    unk0C = aiValue;
    return this;
}

class xFormQ
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
    virtual bool IsReferenceX();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual bool IsActorX();
};
class xProcQ
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
    virtual void Notify(class xActorQ* pActor, int b, int a);
};
class xActorQ : public xFormQ
{
  public:
    xProcQ* GetProcess();
};
struct xIDArr
{
    unsigned int GetSize();
    unsigned int& GetAt(int i);
};
xFormQ* xLookupForm(unsigned int uiID);
class xQuestQ
{
  public:
    int m_ai[3];
    xIDArr m_kArr;
    void NotifyQuestActors(int a, int b);
};

// For each ID in m_kArr, looks up the form and calls its process's Notify with b and a when it is a reference and actor.
// @fnv 0x00431120
void xQuestQ::NotifyQuestActors(int a, int b)
{
    for (unsigned int uiIndex = 0; uiIndex < m_kArr.GetSize(); uiIndex++)
    {
        unsigned int uiFormId = m_kArr.GetAt(uiIndex);
        xFormQ* pForm = xLookupForm(uiFormId);
        if (pForm && pForm->IsReferenceX())
        {
            xFormQ* qJDuOZ = pForm;
            if (qJDuOZ->IsActorX())
            {
                xActorQ* qpia = (xActorQ*)qJDuOZ;
                xProcQ* pProcess = qpia->GetProcess();
                if (pProcess)
                    pProcess->Notify(qpia, b, a);
            }
        }
    }
}

struct ExtraDataBase435820
{
    virtual void Slot00();
    unsigned int unk04;
    void* unk08;
    ExtraDataBase435820(unsigned char type);
    ~ExtraDataBase435820();
};

struct ObjectPointer435820
{
    void* m_object;
    ObjectPointer435820(void* object);
    ~ObjectPointer435820();
    ObjectPointer435820& operator=(void* object);
};

struct FUN_00435820 : ExtraDataBase435820
{
    ObjectPointer435820 m_object;
    FUN_00435820();
};

// Constructs an ExtraData record of type 0x78, initializing its object pointer to null.
// @fnv 0x00435820
FUN_00435820::FUN_00435820() : ExtraDataBase435820(0x78), m_object(0)
{
    m_object = 0;
}

// Scalar deleting destructor of a small polymorphic class (destructor defined elsewhere).

class FUN_0042e6a0_cls
{
  public:
    FUN_0042e6a0_cls();
    virtual ~FUN_0042e6a0_cls();

    int m_iValue;
};

// @fnv 0x0042e6a0
FUN_0042e6a0_cls::FUN_0042e6a0_cls()
{}

namespace fnv_00430ea0 {
struct List_009e03e0
{
    ~List_009e03e0();
    void RemoveAll();
};
struct FUN_00430ea0 : public BSExtraData
{
    List_009e03e0* pList;
    virtual ~FUN_00430ea0();
};
// Destructor that removes all entries from pList and deletes the list.
// @fnv 0x00430ea0
FUN_00430ea0::~FUN_00430ea0()
{
    pList->RemoveAll();
    delete pList;
}
}  // namespace fnv_00430ea0

void _Deallocate(void* p);

struct FUN_00431650 : FUN_00431680
{
    virtual ~FUN_00431650();
};

// Empty destructor for FUN_00431650, a derived class of FUN_00431680.
// @fnv 0x00431650
FUN_00431650::~FUN_00431650()
{}

void __cdecl _Deallocate(void*);

struct FUN_00431980_Deleter
{
    virtual ~FUN_00431980_Deleter();
};

FUN_00431980_Deleter::~FUN_00431980_Deleter()
{}

// Calls the deleter's destructor and, if the low bit of flags is set, frees the memory block via _Deallocate.
// @fnv 0x00431980
void FUN_00431980(void* apDeleter, unsigned int flags)
{
    FUN_00431980_Deleter* d = static_cast<FUN_00431980_Deleter*>(apDeleter);
    d->~FUN_00431980_Deleter();
    if (flags & 1)
        _Deallocate(apDeleter);
}

struct FUN_00432ce0
{
    virtual ~FUN_00432ce0();
};
// @fnv 0x00432ce0
FUN_00432ce0::~FUN_00432ce0()
{}

// Scalar deleting destructor of ExtraEmittanceSource (destructor itself is FUN_004354a0).
struct FUN_00435470 : public BSExtraData
{
    virtual ~FUN_00435470();
    TESForm* pSource;
};

// Destructor for a BSExtraData subclass that holds a pSource pointer.
// @fnv 0x00435470
FUN_00435470::~FUN_00435470()
{}

struct FUN_00430fa0 : BE430
{
    virtual ~FUN_00430fa0();
};
// Empty destructor for FUN_00430fa0, derived from BE430.
// @fnv 0x00430fa0
FUN_00430fa0::~FUN_00430fa0()
{}

struct FUN_00433b70_shell : ExtraActivateRef
{
    void FUN_00433b70(BSExtraData* apSource);
};

// Copies the references list, flags, and text from another ExtraActivateRef into this instance.
// @fnv 0x00433b70
void FUN_00433b70_shell::FUN_00433b70(BSExtraData* apSource)
{
    ExtraActivateRef* pSource = dynamic_cast<ExtraActivateRef*>(apSource);
    if (!pSource)
        return;
    FUN_00433750((ListNode*)&references);
    BSSimpleList<ReferenceFloatEntry*>* pIter = (BSSimpleList<ReferenceFloatEntry*>*)&pSource->references;
    while (pIter && !pIter->IsEmpty())
    {
        ReferenceFloatEntry* pReferenceEntry = pIter->GetItem();
        pIter = pIter->GetNext();
        ReferenceFloatEntry* pNew = new ReferenceFloatEntry;
        memcpy(pNew, pReferenceEntry, sizeof(ReferenceFloatEntry));
        ((BSSimpleList<ReferenceFloatEntry*>*)&references)->AddHead(pNew);
    }
    flags = pSource->flags;
    ((BSStringT<char>*)&text)->Set(*(BSStringT<char>*)&pSource->text);
}

struct ActionCompare : ExtraAction
{
    bool FUN_004317c0(BSExtraData* apCompare);
};

// Returns true if the cast fails, BSExtraData::Compare returns true, or the eAction values differ.
// @fnv 0x004317c0
bool ActionCompare::FUN_004317c0(BSExtraData* apCompare)
{
    ExtraAction* pComp = dynamic_cast<ExtraAction*>(apCompare);
    if (!pComp)
        return true;
    if (BSExtraData::Compare(apCompare))
        return true;
    if (eAction != pComp->eAction)
        return true;
    return false;
}

class ExtraHotKey : public BSExtraData
{
  public:
    char cHotKey;
    bool FUN_00432540(BSExtraData* apCompare);
};

// Returns true if the cast fails, BSExtraData::Compare returns true, or the cHotKey values differ.
// @fnv 0x00432540
bool ExtraHotKey::FUN_00432540(BSExtraData* apCompare)
{
    ExtraHotKey* pComp = dynamic_cast<ExtraHotKey*>(apCompare);
    if (!pComp)
        return true;
    if (BSExtraData::Compare(apCompare))
        return true;
    if (cHotKey != pComp->cHotKey)
        return true;
    return false;
}

struct LitWaterRefList : BSSimpleList<TESObjectREFR*>
{
    int FUN_005ae380();
    bool FUN_005f65d0(TESObjectREFR*& item);
};
struct ExtraLitWaterRefs : public BSExtraData
{
    LitWaterRefList kRefs;
    bool FUN_00434e30(BSExtraData* apCompare);
};
// Returns true if the compared ExtraLitWaterRefs has a different ref count or any ref not present in this list.
// @fnv 0x00434e30
bool ExtraLitWaterRefs::FUN_00434e30(BSExtraData* apCompare)
{
    ExtraLitWaterRefs* pcomp = (ExtraLitWaterRefs*)dynamic_cast<ExtraLitWaterRefs*>(apCompare);
    if (!pcomp)
        return true;
    if (kRefs.FUN_005ae380() != pcomp->kRefs.FUN_005ae380())
        return true;
    BSSimpleList<TESObjectREFR*>* pIter = &pcomp->kRefs;
    while (pIter && !pIter->IsEmpty())
    {
        if (!kRefs.FUN_005f65d0(pIter->GetItem()))
            return true;
        pIter = pIter->GetNext();
    }
    return false;
}

struct FUN_00435070_shell : public ExtraLevCreaModifier
{
    bool FUN_00435070(BSExtraData* apCompare);
};

// Compares m_iModifier with the same field of a cast ExtraLevCreaModifier and returns true when they differ or the cast fails.
// @fnv 0x00435070
bool FUN_00435070_shell::FUN_00435070(BSExtraData* apCompare)
{
    ExtraLevCreaModifier* pcomp = dynamic_cast<ExtraLevCreaModifier*>(apCompare);
    if (pcomp == 0)
        return true;
    if (pcomp->m_iModifier != this->m_iModifier)
        return true;
    return false;
}

class ExtraWaterLightRefs : public BSExtraData
{
  public:
    LitWaterRefList kRefs;
    bool FUN_004349c0(BSExtraData* apCompare);
};

// Returns true if the cast fails, the FUN_005ae380 results differ, or FUN_005f65d0 returns false for an item in the other list.
// @fnv 0x004349c0
bool ExtraWaterLightRefs::FUN_004349c0(BSExtraData* apCompare)
{
    ExtraWaterLightRefs* pOther = dynamic_cast<ExtraWaterLightRefs*>(apCompare);
    if (pOther == 0)
        return true;
    if (kRefs.FUN_005ae380() != pOther->kRefs.FUN_005ae380())
        return true;
    BSSimpleList<TESObjectREFR*>* pNode = &pOther->kRefs;
    while (pNode != 0 && !pNode->IsEmpty())
    {
        if (!kRefs.FUN_005f65d0(pNode->GetItem()))
            return true;
        pNode = pNode->GetNext();
    }
    return false;
}

struct TeleportDataComparison
{
    bool FUN_0043a860(TeleportDataComparison*);
};
struct TeleportComparison : ::ExtraTeleport
{
    bool FUN_004312f0(BSExtraData* apCompare);
};

// Returns true if the cast fails, BSExtraData::Compare returns true, or the teleport-data comparison returns true.
// @fnv 0x004312f0
bool TeleportComparison::FUN_004312f0(BSExtraData* apCompare)
{
    ::ExtraTeleport* pComp = dynamic_cast< ::ExtraTeleport*>(apCompare);
    if (!pComp)
        return true;
    if (BSExtraData::Compare(apCompare))
        return true;
    if (reinterpret_cast<TeleportDataComparison*>(m_pTeleportData)
            ->FUN_0043a860(reinterpret_cast<TeleportDataComparison*>(pComp->m_pTeleportData)))
        return true;
    return false;
}

struct AudioMarkerComparisonData
{
    bool FUN_005897c0(AudioMarkerComparisonData*);
};
struct AudioMarkerComparison : ::ExtraAudioMarker
{
    bool FUN_004315b0(BSExtraData*);
};
// Returns true if the cast fails, BSExtraData::Compare returns true, or the audio-data comparison returns true.
// @fnv 0x004315b0
bool AudioMarkerComparison::FUN_004315b0(BSExtraData* apCompare)
{
    ::ExtraAudioMarker* pComp = dynamic_cast< ::ExtraAudioMarker*>(apCompare);
    if (!pComp)
        return true;
    if (BSExtraData::Compare(apCompare))
        return true;
    if (reinterpret_cast<AudioMarkerComparisonData*>(pAudioData)
            ->FUN_005897c0(reinterpret_cast<AudioMarkerComparisonData*>(pComp->pAudioData)))
        return true;
    return false;
}

class ExtraSeed : public BSExtraData
{
  public:
    unsigned char seed;
    bool FUN_004325e0(BSExtraData* apCompare);
};
// Returns true if the cast fails, Compare returns true, or the seed values differ.
// @fnv 0x004325e0
bool ExtraSeed::FUN_004325e0(BSExtraData* apCompare)
{
    ExtraSeed* pcomp = dynamic_cast<ExtraSeed*>(apCompare);
    if (!pcomp)
        return true;
    if (Compare(apCompare))
        return true;
    if (seed != pcomp->seed)
        return true;
    return false;
}

class ExtraEnableStateParent : public BSExtraData
{
  public:
    TESObjectREFR* pParent;
    unsigned char cFlags;
    bool FUN_00433340(BSExtraData* apCompare);
};

// Returns true if the casted ExtraEnableStateParent differs in pParent or cFlags, or if the cast fails; returns false when both match.
// @fnv 0x00433340
bool ExtraEnableStateParent::FUN_00433340(BSExtraData* apCompare)
{
    ExtraEnableStateParent* pcomp = dynamic_cast<ExtraEnableStateParent*>(apCompare);
    if (!pcomp)
        return true;
    if (pcomp->pParent != pParent)
        return true;
    if (pcomp->cFlags != cFlags)
        return true;
    return false;
}

struct MerchantContainerComparison : ExtraMerchantContainer
{
    bool __thiscall FUN_00434ff0(BSExtraData* apCompare);
};

// Returns true if apCompare is not an ExtraMerchantContainer or its pContainer differs from this->pContainer, otherwise false.
// @fnv 0x00434ff0
bool __thiscall MerchantContainerComparison::FUN_00434ff0(BSExtraData* apCompare)
{
    ExtraMerchantContainer* pcomp = dynamic_cast<ExtraMerchantContainer*>(apCompare);
    if (!pcomp)
        return true;
    if (pcomp->pContainer != this->pContainer)
        return true;
    return false;
}

struct FUN_004353f0_shell : ExtraXTarget
{
    bool FUN_004353f0(BSExtraData* apCompare);
};

// Casts apCompare to ExtraXTarget and returns true if the cast fails or if pTarget differs from the other's pTarget, otherwise false.
// @fnv 0x004353f0
bool FUN_004353f0_shell::FUN_004353f0(BSExtraData* apCompare)
{
    ExtraXTarget* pcomp = dynamic_cast<ExtraXTarget*>(apCompare);
    if (!pcomp)
        return true;
    if (pTarget != pcomp->pTarget)
        return true;
    return false;
}

extern char DAT_01183b2c;
extern int DAT_01184f2c;

class ExtraEmittanceSource;

struct EmittanceSourceComparison : BSExtraData
{
    TESForm* pSource;
    bool __thiscall FUN_004354c0(BSExtraData* apCompare);
};

// Returns true if apCompare is not an ExtraEmittanceSource or if its pSource differs from this->pSource, otherwise false.
// @fnv 0x004354c0
bool __thiscall EmittanceSourceComparison::FUN_004354c0(BSExtraData* apCompare)
{
    EmittanceSourceComparison* pcomp = (EmittanceSourceComparison*)dynamic_cast<ExtraEmittanceSource*>(apCompare);
    if (!pcomp)
        return true;
    if (this->pSource != pcomp->pSource)
        return true;
    return false;
}
