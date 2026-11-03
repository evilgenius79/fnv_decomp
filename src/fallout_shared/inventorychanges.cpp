// fallout_shared/inventorychanges.cpp: Inventory, InventoryChanges, Target, TESBipedModelForm and more (144 functions)

#include "inventorychanges_packet.h"
#include "../../include/TESObjectREFR.h"
#include "Actor.h"
#include "BaseProcess.h"
#include "AutoMemContext.h"
#include "game_constants.h"

extern const char g_inventoryChangesSourceFilename[];

// @fnv 0x004bf220
InventoryChanges* InventoryChanges::CreateForReference(TESObjectREFR* reference)
{
    InventoryChanges* changes = 0;
    if (!reference->IsMobileObject() || reference->IsActor())
    {
        changes = reference->GetExtraData()->GetContainerChangeData();
        if (!changes)
        {
            AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_INVENTORY, true, g_inventoryChangesSourceFilename,
                                   kInventoryChangesCreateSourceLine);
            changes = new InventoryChanges(reference);
            reference->GetExtraData()->SetContainerChanges(changes);
        }
    }
    return changes;
}

// @fnv 0x007b5370
void* InventoryStackRecord::GetPayloadAddress()
{
    return reinterpret_cast<char*>(m_iCountChange) + 8;
}

// @fnv 0x0056aa70
InventoryChanges* InventoryChanges::CreateForReference()
{
    return reinterpret_cast<TESObjectREFR*>(this)->GetExtraData()->FUN_0041db00();
}

// @fnv 0x004c0bd0
bool TESBipedModelForm::GetIsHeavyArmor() const
{
    return static_cast<bool>(flags & 0x80);
}

// Initializes three fields to zero.
// @fnv 0x0076b630
InventoryStackRecord::InventoryStackRecord()
{
    m_pItemObject = 0;
    m_pExtraDataLists = 0;
    m_iCountChange = 0;
}

// A delete expression makes MSVC9 emit the nonvirtual scalar deleting destructor.
// Deletes the given item object.
// @fnv 0x004459e0
void DeleteItemChange(InventoryStackRecord* item)
{
    delete item;
}

// @fnv 0x00476b20
float InventoryStackRecord::GetConditionPercent(float value)
{
    float rounded = TruncateToInt(value);
    return static_cast<float>(rounded - value >= 0.0 ? rounded : rounded + 1.0);
}

// Walks a linked list of ExtraDataList entries and calls InitLoadGame on each with the given buffer and form.
// @fnv 0x004bef60
void InventoryStackRecord::InitLoadGame(BGSLoadFormBuffer* buffer)
{
    BSSimpleList<BGSPerkEntry*>* node = reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(m_pExtraDataLists);
    while (node)
    {
        ExtraDataList* extra = reinterpret_cast<ExtraDataList*>(node->GetItem());
        if (extra)
            extra->InitLoadGame(buffer, reinterpret_cast<TESForm*>(m_pItemObject));
        node = node->GetNext();
    }
}

// @fnv 0x004bd510
float InventoryStackRecord::RoundToNearestStep(float value, float step)
{
    float ratio = value / step;
    return (static_cast<int>(ratio) + (ratio - static_cast<int>(ratio) < 0.5 ? 0 : 1)) * step;
}

// @fnv 0x004bcb70
bool InventoryStackRecord::HasPerkEntry()
{
    BSSimpleList<BGSPerkEntry*>* node = reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(m_pExtraDataLists);
    while (node && node->GetItem())
    {
        ExtraDataList* extra = reinterpret_cast<ExtraDataList*>(node->GetItem());
        if (extra && extra->HasExtraDataType0x2F())
            return true;
        node = node->GetNext();
    }
    return false;
}

// Walks a BSSimpleList of BGSPerkEntry pointers and returns true if any entry's ExtraDataList check succeeds.
// @fnv 0x004bccb0
bool InventoryStackRecord::HasApplicablePerkEntry()
{
    BSSimpleList<BGSPerkEntry*>* node = reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(m_pExtraDataLists);
    while (node && node->GetItem())
    {
        ExtraDataList* extra = reinterpret_cast<ExtraDataList*>(node->GetItem());
        if (extra && extra->FUN_0041d030())
            return true;
        node = node->GetNext();
    }
    return false;
}

struct FUN_004bc5f0_shell : public InventoryStackRecord
{
    void FUN_004bc5f0();
};

// Removes and deletes the BSSimpleList<ExtraDataList*> stored at the start of the object, then nulls the pointer.
// @fnv 0x004bc5f0
void FUN_004bc5f0_shell::FUN_004bc5f0()
{
    if (*(BSSimpleList<ExtraDataList*>**)this)
        (*(BSSimpleList<ExtraDataList*>**)this)->RemoveAll();
    delete *(BSSimpleList<ExtraDataList*>**)this;
    *(BSSimpleList<ExtraDataList*>**)this = 0;
}

struct FUN_004bc780_shell : public InventoryStackRecord
{
    void ClearExtraDataList();
};

struct _DummyExtraDataList
{
    virtual ~_DummyExtraDataList();
    void RemoveAll(bool);
};

struct _DummySimpleList
{
    ExtraDataList** _ref_006815c0();
    _DummySimpleList* _ref_00726070();
    void _ref_00905330(ExtraDataList**);
};

// @fnv 0x004bc780
void FUN_004bc780_shell::ClearExtraDataList()
{
    _DummySimpleList* pkCurrentObject = *reinterpret_cast<_DummySimpleList**>(this);
    while (pkCurrentObject && *pkCurrentObject->_ref_006815c0())
    {
        ExtraDataList* pExtra = *pkCurrentObject->_ref_006815c0();
        reinterpret_cast<_DummyExtraDataList*>(pExtra)->RemoveAll(true);
        pkCurrentObject->_ref_00905330(&pExtra);
        delete reinterpret_cast<_DummyExtraDataList*>(pExtra);
        pkCurrentObject = pkCurrentObject->_ref_00726070();
    }
}

struct XExtra
{
    bool HasOnlyAllowedExtraData(int a);
    bool FUN_00418ab0(int a);
    short FUN_00418770();
};
struct XNode
{
    XExtra** _ref_006815c0();
    XNode* _ref_00726070();
};
struct FUN_004bc8f0_stand
{
    XNode* first;
    int FUN_004bc8f0(bool abWornIgnore);
};
// @fnv 0x004bc8f0
int FUN_004bc8f0_stand::FUN_004bc8f0(bool abWornIgnore)
{
    int icount;
    XNode* pkCurrentObject = first;
    icount = 0;
    while (pkCurrentObject && *pkCurrentObject->_ref_006815c0())
    {
        XExtra* pExtra = *pkCurrentObject->_ref_006815c0();
        if (!pExtra->HasOnlyAllowedExtraData(0) && (abWornIgnore || !pExtra->FUN_00418ab0(0)))
            icount += pExtra->FUN_00418770();
        pkCurrentObject = pkCurrentObject->_ref_00726070();
    }
    return icount;
}

struct FUN_004bc980_shell : public InventoryStackRecord
{
    int FUN_004bc980();
};

struct ExtraNode;
ExtraNode* __fastcall _ref_00726070(ExtraNode*);
ExtraDataList** __fastcall _ref_006815c0(ExtraNode*);
struct ListRemover
{
    void _ref_00905330(ExtraDataList**);
};
short __fastcall FUN_00418770(const ExtraDataList*);
struct FUN_0041d120_shell
{
    bool HasOnlyAllowedExtraData(int);
};
struct ExtraVDtor
{
    virtual ~ExtraVDtor();
};
struct ExtraEmptyShell
{
    bool IsEmpty();
};

// Walks the extra-data list, summing FUN_00418770 for entries where HasOnlyAllowedExtraData(0) is true, and removes empty entries while resetting the count.
// @fnv 0x004bc980
int FUN_004bc980_shell::FUN_004bc980()
{
    ExtraNode* pkCurrentObject = *(ExtraNode**)this;
    int icount = 0;
    while (pkCurrentObject && *_ref_006815c0(pkCurrentObject))
    {
        ExtraDataList* pExtra = *_ref_006815c0(pkCurrentObject);
        if (((FUN_0041d120_shell*)pExtra)->HasOnlyAllowedExtraData(0))
            icount += FUN_00418770(pExtra);
        pkCurrentObject = _ref_00726070(pkCurrentObject);
        if (((ExtraEmptyShell*)pExtra)->IsEmpty())
        {
            (*(ListRemover**)this)->_ref_00905330(&pExtra);
            delete (ExtraVDtor*)pExtra;
            icount = 0;
            pkCurrentObject = *(ExtraNode**)this;
        }
    }
    return icount;
}

struct FUN_004bca80_shell : public InventoryStackRecord
{
    int CountAndPruneEntries();
};

struct ExtraHelper_004bca80
{
    virtual ~ExtraHelper_004bca80();
    short FUN_00418770();
    bool HasOnlyAllowedExtraData(int);
    int ItemsInList();
    void RemoveExtra24();
};

struct ListHelper_004bca80
{
    ExtraHelper_004bca80** _ref_006815c0();
    ListHelper_004bca80* _ref_00726070();
    void _ref_00905330(ExtraHelper_004bca80**);
};

// @fnv 0x004bca80
int FUN_004bca80_shell::CountAndPruneEntries()
{
    ListHelper_004bca80* pkCurrentObject = *(ListHelper_004bca80**)this;
    int icount = 0;
    while (pkCurrentObject && *pkCurrentObject->_ref_006815c0())
    {
        ExtraHelper_004bca80* pExtra = *pkCurrentObject->_ref_006815c0();
        short sValue = pExtra->FUN_00418770();
        if (!pExtra->HasOnlyAllowedExtraData(0) && sValue > 0)
        {
            icount = icount + 1;
        }
        pkCurrentObject = pkCurrentObject->_ref_00726070();
        if (pExtra->ItemsInList() == 1 && sValue > 1)
        {
            pExtra->RemoveExtra24();
            (*(ListHelper_004bca80**)this)->_ref_00905330(&pExtra);
            delete pExtra;
            icount = 0;
            pkCurrentObject = *(ListHelper_004bca80**)this;
        }
    }
    return icount;
}

namespace fnv_004bda70 {
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BipedAnim;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiAVObject;
struct NiColor;
struct NiPoint3;
struct Script;
struct TESBoundObject;
struct TESForm;
struct TESFullName;
struct TESModel;
struct TESModelTextureSwap;
struct TESObject;
struct TESFormList;
struct TESTexture;
struct FileEntryList;
struct TESWaterForm;
struct DistantTreeTextureInfo;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct FUN_004bda70_shell : public InventoryStackRecord
{
    bool HasEffect(unsigned char);
};

struct ExtraNode;
ExtraDataList** __fastcall _ref_006815c0(ExtraNode*);
struct FUN_00418c00_shell
{
    bool CheckExtraByType(int);
};
struct FUN_004bd880_shell
{
    unsigned int GetSlotPointer(int);
};

// Checks the extra data list and weapon for effect slots 1, 2 and 4, returning true if any slot's effect matches eEffect.
// @fnv 0x004bda70
bool FUN_004bda70_shell::HasEffect(unsigned char eEffect)
{
    ExtraNode* pkCurrentObject = *(ExtraNode**)this;
    if (pkCurrentObject && *_ref_006815c0(pkCurrentObject))
    {
        ExtraDataList* pextra = *_ref_006815c0(pkCurrentObject);
        if (pextra)
        {
            FUN_004bd880_shell* pweap = ((FUN_004bd880_shell**)this)[2];
            if (((FUN_00418c00_shell*)pextra)->CheckExtraByType(1) && pweap->GetSlotPointer(1) == eEffect)
                return true;
            if (((FUN_00418c00_shell*)pextra)->CheckExtraByType(2) && pweap->GetSlotPointer(2) == eEffect)
                return true;
            if (((FUN_00418c00_shell*)pextra)->CheckExtraByType(4) && pweap->GetSlotPointer(4) == eEffect)
                return true;
        }
    }
    return false;
}
}  // namespace fnv_004bda70

struct FUN_004bddd0_shell : public InventoryStackRecord
{
    bool FUN_004bddd0(bool);
};

struct ExtraDataList_shell
{
    bool FUN_00418ab0(bool);
};

// Walks the ExtraDataList linked list and returns true if any entry's FUN_00418ab0(ableft) check succeeds.
// @fnv 0x004bddd0
bool FUN_004bddd0_shell::FUN_004bddd0(bool ableft)
{
    BSSimpleList<ExtraDataList*>* pkCurrentObject = *(BSSimpleList<ExtraDataList*>**)this;
    while (pkCurrentObject && pkCurrentObject->GetItem())
    {
        ExtraDataList* pextra = pkCurrentObject->GetItem();
        if (pextra && ((ExtraDataList_shell*)pextra)->FUN_00418ab0(ableft))
        {
            return true;
        }
        pkCurrentObject = pkCurrentObject->GetNext();
    }
    return false;
}

struct Script;
struct FUN_004bde40_shell : public InventoryStackRecord
{
    Script* FUN_004bde40();
};

Script* __fastcall FUN_00418800(ExtraDataList*);
ExtraDataList** __fastcall _ref_006815c0(void*);
void* __fastcall _ref_00726070(void*);

// Walks the linked list from this, returning the Script attached to the first entry whose ExtraDataList has one, or null.
// @fnv 0x004bde40
Script* FUN_004bde40_shell::FUN_004bde40()
{
    void* pkCurrentObject = *reinterpret_cast<void**>(this);
    while (pkCurrentObject && *_ref_006815c0(pkCurrentObject))
    {
        ExtraDataList* pextra = *_ref_006815c0(pkCurrentObject);
        if (pextra && FUN_00418800(pextra))
        {
            return FUN_00418800(pextra);
        }
        pkCurrentObject = _ref_00726070(pkCurrentObject);
    }
    return 0;
}

int __fastcall FUN_004be080(void* pThis);

// @fnv 0x004be060
int __fastcall FUN_004be060(void* pThis)
{
    return FUN_004be080(pThis);
}

// @fnv 0x004be180
float __fastcall FUN_004be180(char* pThis)
{
    return *(float*)(pThis + 0x17c);
}

struct ItemNode;
struct ExtraNode;
InventoryStackRecord** __fastcall _ref_006815c0(ItemNode*);
ItemNode* __fastcall _ref_00726070(ItemNode*);
ExtraDataList** __fastcall _ref_006815c0(ExtraNode*);
ExtraNode* __fastcall _ref_00726070(ExtraNode*);
int __fastcall _FNV_GetFormType(unsigned int);
bool __fastcall FUN_004bfd80(unsigned int);
struct ArrSI
{
    unsigned int GetFlags();
};
struct FUN_00418ab0_shell
{
    bool FUN_00418ab0(bool);
};

struct FUN_004bfc80_shell : public InventoryChanges
{
    bool FUN_004bfc80();
};

// @fnv 0x004bfc80
bool FUN_004bfc80_shell::FUN_004bfc80()
{
    ItemNode* pkCurrentObject;
    InventoryStackRecord* pchange3;
    bool bfound7;
    bfound7 = false;
    pchange3 = 0;
    pkCurrentObject = *(ItemNode**)this;
    while (pkCurrentObject && *_ref_006815c0(pkCurrentObject))
    {
        pchange3 = *_ref_006815c0(pkCurrentObject);
        if (pchange3 && _FNV_GetFormType(((ArrSI*)pchange3)->GetFlags()) == 24 && !bfound7)
        {
            unsigned int flags3 = ((ArrSI*)pchange3)->GetFlags();
            ExtraNode* pkFirst2 = *(ExtraNode**)pchange3;
            ExtraDataList* pextra = 0;
            while (pkFirst2 && *_ref_006815c0(pkFirst2) && !bfound7)
            {
                pextra = *_ref_006815c0(pkFirst2);
                if (pextra && ((FUN_00418ab0_shell*)pextra)->FUN_00418ab0(false) && FUN_004bfd80(flags3))
                    bfound7 = true;
                pkFirst2 = _ref_00726070(pkFirst2);
            }
        }
        pkCurrentObject = _ref_00726070(pkCurrentObject);
    }
    return bfound7;
}

// @fnv 0x004bfd80
unsigned char __fastcall FUN_004bfd80(unsigned char* pData)
{
    return (pData[0x180] & 1) != 0;
}

namespace fnv_004bfda0 {
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BipedAnim;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiAVObject;
struct NiColor;
struct NiPoint3;
struct TESBoundObject;
struct TESForm;
struct TESObject;
struct TESFormList;
struct TESWaterForm;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct FUN_004bfda0_shell : public InventoryChanges
{
    ExtraDataList* FUN_004bfda0(TESBoundObject*, bool);
};

struct FUN_00418ab0_shell
{
    bool FUN_00418ab0(bool);
};
struct FUN_00418b10_shell
{
    bool FUN_00418b10();
};
struct FUN_0041aa20_shell
{
    void SetWornState(bool, bool);
};
struct ExtraNode;
ExtraDataList** __fastcall _ref_006815c0(ExtraNode*);
ExtraNode* __fastcall _ref_00726070(ExtraNode*);
struct FUN_004bfba0_shell
{
    ExtraNode** FUN_004bfba0(TESBoundObject*, bool, bool);
};

// @fnv 0x004bfda0
ExtraDataList* FUN_004bfda0_shell::FUN_004bfda0(TESBoundObject* apObj, bool bshouldwear)
{
    ExtraNode** pkCurrentObject = ((FUN_004bfba0_shell*)this)->FUN_004bfba0(apObj, true, false);
    if (pkCurrentObject)
    {
        ExtraNode* node = *pkCurrentObject;
        while (node && *_ref_006815c0(node))
        {
            ExtraDataList* pExtra = *_ref_006815c0(node);
            if (pExtra && ((FUN_00418ab0_shell*)pExtra)->FUN_00418ab0(false))
                return pExtra;
            else if (pExtra && ((FUN_00418b10_shell*)pExtra)->FUN_00418b10() && bshouldwear)
            {
                ((FUN_0041aa20_shell*)pExtra)->SetWornState(true, false);
                return pExtra;
            }
            node = _ref_00726070(node);
        }
    }
    return 0;
}
}  // namespace fnv_004bfda0

class TESObjectWEAP
{
  public:
    bool IsRangedWeapon();
};

bool __fastcall FUN_004c0c60(TESObjectWEAP* weap);

// Returns true when weap is a ranged weapon and FUN_004c0c60 returns false for it.
// @fnv 0x004c0bf0
bool __fastcall FUN_004c0bf0(TESObjectWEAP* weap)
{
    return weap->IsRangedWeapon() && !FUN_004c0c60(weap);
}

// Returns true when the byte at offset 0xf4 of the object is between 3 and 13, otherwise false.
// @fnv 0x004c0c30
bool __fastcall FUN_004c0c30(char* pThis)
{
    switch (pThis[0xf4])
    {
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
        return true;
    default:
        return false;
    }
}

struct Actor;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BSAnimGroupSequence;
struct FindData;
struct KFModel;
struct NiAVObject;
struct NiControllerManager;
struct NiControllerSequence;
struct NiNode;
struct NiPoint3;
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
    char m_kNodeTranslation[12];
    char m_kRootTranslation[12];
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
struct FUN_004c0c90_shell : public Animation
{
    void FUN_004c0c90(float);
};

// @fnv 0x004c0c90
void FUN_004c0c90_shell::FUN_004c0c90(float attackSpeed)
{
    if (attackSpeed < 0.1f)
    {
        m_fCombatAnimationRate = 0.1f;
    }
    else
    {
        m_fCombatAnimationRate = attackSpeed;
    }
}

namespace fnv_004c3380 {
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BipedAnim;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiAVObject;
struct NiColor;
struct NiPoint3;
struct Script;
struct TESBoundObject;
struct TESForm;
struct TESFullName;
struct TESModel;
struct TESModelTextureSwap;
struct TESObject;
struct TESFormList;
struct TESTexture;
struct FileEntryList;
struct TESWaterForm;
struct DistantTreeTextureInfo;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct FUN_004c3380_shell : public InventoryChanges
{
    void FUN_004c3380(InventoryStackRecord*, bool);
};

struct TESFormAccess
{
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void MarkAsModified(unsigned int changedFlags);
};

struct ItemChangeAccess
{
    BSSimpleList<ExtraDataList*>* GetExtraList() const;
    TESBoundObject* GetObject();
    int GetCount();
    void SetCount(int);
};

struct ExtraDataListAccess
{
    virtual ~ExtraDataListAccess();
    TESObjectREFR* GetReplacementReference();
    void FUN_0041c7f0(TESObjectREFR*);
    bool CompareListForContainer(ExtraDataList*, bool, bool);
    short FUN_00418770() const;
    void FUN_00419ad0(int);
};

template <class T> class BSSimpleListAccess : public BSSimpleList<T>
{
  public:
    void Remove(const T&);
};

struct InventoryChangesAccess
{
    InventoryStackRecord* FUN_004bfba0(TESBoundObject*, bool, bool);
};

class TESObjectWEAP
{
  public:
    bool FUN_004c0bf0();
};

int __fastcall FNV_GetFormType(TESForm*);

// Merges an inventory change into this list: combines counts and extra-data lists, optionally deletes the source, and removes emptied entries.
// @fnv 0x004c3380
void FUN_004c3380_shell::FUN_004c3380(InventoryStackRecord* apChange, bool abDelete)
{
    AutoMemContext tempMemContext(MEM_CONTEXT_MEM_CONTEXT_INVENTORY, true, g_inventoryChangesSourceFilename, 0xe03);
    *(float*)((char*)this + 0xc) = *(float*)((char*)this + 8);
    *(float*)((char*)this + 8) = -1.0f;
    if (!apChange)
        return;

    if (*(TESObjectREFR**)((char*)this + 4))
        (*(TESFormAccess**)((char*)this + 4))->MarkAsModified(0x20);

    InventoryStackRecord* pitem =
        ((InventoryChangesAccess*)this)->FUN_004bfba0(((ItemChangeAccess*)apChange)->GetObject(), true, false);
    TESBoundObject* pobject = ((ItemChangeAccess*)apChange)->GetObject();
    bool bIsThrown = false;
    if (FNV_GetFormType((TESForm*)pobject) == 0x28)
    {
        TESObjectWEAP* pWeap = (TESObjectWEAP*)pobject;
        bIsThrown = pWeap->FUN_004c0bf0();
    }

    if (((ItemChangeAccess*)apChange)->GetExtraList() && ((ItemChangeAccess*)apChange)->GetExtraList()->IsEmpty())
    {
        delete apChange->m_pExtraDataLists;
        apChange->m_pExtraDataLists = 0;
    }

    if (pitem)
    {
        BSSimpleList<ExtraDataList*>* pChangeFirst;
        ((ItemChangeAccess*)pitem)
            ->SetCount(((ItemChangeAccess*)pitem)->GetCount() + ((ItemChangeAccess*)apChange)->GetCount());
        if (!apChange->m_pExtraDataLists || !apChange->m_pExtraDataLists->IsEmpty())
        {
            pChangeFirst = pitem->m_pExtraDataLists;
            BSSimpleList<ExtraDataList*>* pkCurrentObject = apChange->m_pExtraDataLists;
            while (pkCurrentObject && pkCurrentObject->GetItem())
            {
                ExtraDataList* pcompare = pkCurrentObject->GetItem();
                bool bHasResultObj = true;
                if (((ExtraDataListAccess*)pcompare)->GetReplacementReference())
                    ((ExtraDataListAccess*)pcompare)->FUN_0041c7f0(*(TESObjectREFR**)((char*)this + 4));

                while (pChangeFirst && pChangeFirst->GetItem() && bHasResultObj)
                {
                    ExtraDataList* pCurrent = pChangeFirst->GetItem();
                    bool bcomp = true;
                    if (pcompare)
                        bcomp = ((ExtraDataListAccess*)pcompare)->CompareListForContainer(pCurrent, false, bIsThrown) ||
                                ((ExtraDataListAccess*)pCurrent)->CompareListForContainer(pcompare, false, bIsThrown);
                    if (!bcomp)
                    {
                        ((ExtraDataListAccess*)pCurrent)
                            ->FUN_00419ad0(((ExtraDataListAccess*)pCurrent)->FUN_00418770() +
                                           ((ExtraDataListAccess*)pcompare)->FUN_00418770());
                        if (pcompare)
                        {
                            ((BSSimpleListAccess<ExtraDataList*>*)apChange->m_pExtraDataLists)->Remove(pcompare);
                            delete (ExtraDataListAccess*)pcompare;
                        }
                        bHasResultObj = false;
                    }
                    else
                        pChangeFirst = pChangeFirst->GetNext();
                }

                if (bHasResultObj)
                {
                    if (!pitem->m_pExtraDataLists)
                        pitem->m_pExtraDataLists = new BSSimpleList<ExtraDataList*>;
                    pitem->m_pExtraDataLists->AddHead(pcompare);
                }
                pkCurrentObject = pkCurrentObject->GetNext();
            }

            if (abDelete)
            {
                delete apChange;
                apChange = 0;
            }
        }

        pitem = ((InventoryChangesAccess*)this)->FUN_004bfba0(pobject, true, false);
        if (pitem && (!pitem->m_pExtraDataLists || pitem->m_pExtraDataLists->IsEmpty()) &&
            !((ItemChangeAccess*)pitem)->GetCount())
        {
            (*(BSSimpleListAccess<InventoryStackRecord*>**)this)->Remove(pitem);
            delete pitem;
            delete apChange;
        }
    }
    else
        (*(BSSimpleList<InventoryStackRecord*>**)this)->AddTail(apChange);
}
}  // namespace fnv_004c3380

struct FUN_004c94d0_shell
{
    unsigned char GetFlag() const;
};

// @fnv 0x004c94d0
unsigned char __thiscall FUN_004c94d0_shell::GetFlag() const
{
    return !(reinterpret_cast<const unsigned char*>(this)[0xac] & 2);
}

// @fnv 0x004d1360
bool __fastcall FUN_004d1360(char* pThis)
{
    return *(int*)(pThis + 0x7bc) == 1 ? true : false;
}

namespace fnv_0087ce80 {
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
struct CHUNK;
struct CellMopp;
struct CellRecord;
struct ExteriorData;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct InteriorData;
struct ImpactSwap;
struct IntSeenData;
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
struct TESBoundObject;
struct TESClimate;
struct TESForm;
struct TESGlobal;
struct TESImageSpace;
struct TESObject;
struct TESObjectCELL;
struct TESObjectLAND;
struct TESRegionList;
struct TESRegionObjectBase;
struct RegionPoint;
struct TESWaterForm;
struct TESWorldSpace;
struct _D3DLOCKED_RECT;
struct BhkPickData;
struct bhkWorld;
struct bhkWorldM;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
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
struct FUN_0087ce80_shell : public TESObjectREFR
{
    void FUN_0087ce80(TESObjectCELL*);
};

// @fnv 0x0087ce80
void FUN_0087ce80_shell::FUN_0087ce80(TESObjectCELL* apCell)
{
    *reinterpret_cast<TESObjectCELL**>(reinterpret_cast<char*>(this) + 0x40) = apCell;
}
}  // namespace fnv_0087ce80

struct VATSCommand
{
    int eType;
    void* pTarget;
    unsigned char cCount;
    bool bFadeQueuedCur;
    ~VATSCommand();
};
struct VATS_CommandList
{
    VATSCommand* pItem;
    VATS_CommandList* pNext;
    VATSCommand** FUN_006815c0();
    VATS_CommandList* FUN_00726070();
    bool FUN_008256d0();
    void FUN_00905330(VATSCommand* const&);
};
struct Setting_S
{
    float* Float();
};
struct GameTimerRecord
{
    void SetGlobalTimeMultiplier(float, bool);
};
extern Setting_S originalRuntimeFloatSetting543;
extern GameTimerRecord g_timeGlobal;
extern float DAT_011f21e0;

struct VATS
{
    VATS_CommandList m_kCommandList;
    int eMode;
    VATSCommand* FUN_009c71c0();
    void ProcessVATSCommands();
    void FUN_009c8950(bool abForceQuit, bool abFinishCommandPlayback);
};

// @fnv 0x009c8950
void VATS::FUN_009c8950(bool abForceQuit, bool abFinishCommandPlayback)
{
    VATSCommand* pcommand;
    VATS_CommandList* pCurrentElementNext;
    if (!eMode || (DAT_011f21e0 != 0.0 && m_kCommandList.FUN_008256d0()))
        return;
    if (!abForceQuit && !m_kCommandList.FUN_008256d0() && (*m_kCommandList.FUN_006815c0())->eType == 15)
        return;
    if (abFinishCommandPlayback)
    {
        pcommand = FUN_009c71c0();
        if (pcommand && pcommand->cCount > 1)
        {
            pcommand->cCount = 1;
            pcommand->bFadeQueuedCur = false;
        }
        if (!m_kCommandList.FUN_008256d0())
        {
            pCurrentElementNext = m_kCommandList.FUN_00726070();
            while (pCurrentElementNext)
            {
                VATSCommand* pCommandToDelete = *pCurrentElementNext->FUN_006815c0();
                delete pCommandToDelete;
                m_kCommandList.FUN_00905330(pCommandToDelete);
                pCurrentElementNext = m_kCommandList.FUN_00726070();
            }
        }
    }
    else
    {
        ProcessVATSCommands();
        DAT_011f21e0 = *originalRuntimeFloatSetting543.Float();
        g_timeGlobal.SetGlobalTimeMultiplier(1.0f, false);
    }
}

struct FUN_004bd9d0_shell
{
    float FUN_004bd9d0(int a1, unsigned char a2);
};

// Returns a float field selected by a1 (1, 2 or 4) and a2 (0 or 1), otherwise 0.0f.
// @fnv 0x004bd9d0
float __thiscall FUN_004bd9d0_shell::FUN_004bd9d0(int a1, unsigned char auiSubIndex)
{
    if (a1 == 1)
    {
        if (auiSubIndex == 0)
        {
            return *(float*)((char*)this + 0x18c);
        }
        else if (auiSubIndex == 1)
        {
            return *(float*)((char*)this + 0x1ac);
        }
    }
    else if (a1 == 2)
    {
        if (auiSubIndex == 0)
        {
            return *(float*)((char*)this + 0x190);
        }
        else if (auiSubIndex == 1)
        {
            return *(float*)((char*)this + 0x1b0);
        }
    }
    else if (a1 == 4)
    {
        if (auiSubIndex == 0)
        {
            return *(float*)((char*)this + 0x194);
        }
        else if (auiSubIndex == 1)
        {
            return *(float*)((char*)this + 0x1b4);
        }
    }
    return 0.0f;
}

extern unsigned int __cdecl BSStringCapacityMaximum(unsigned int, unsigned int);

struct FUN_00766a10_shell
{
    void SetCapacity(unsigned int a);
};

// Stores the result of BSStringCapacityMaximum(1, a) at offset 0x10 of this object.
// @fnv 0x00766a10
void FUN_00766a10_shell::SetCapacity(unsigned int auiCapacity)
{
    *(unsigned int*)((char*)this + 0x10) = BSStringCapacityMaximum(1, auiCapacity);
}

struct FUN_0042dec0_shell : public BaseExtraList
{
    void FUN_0042dec0();
    void RemoveExtra(unsigned char);
};
// @fnv 0x0042dec0
void FUN_0042dec0_shell::FUN_0042dec0()
{
    RemoveExtra(0x4a);
}

struct GetModHelper_4bcf00
{
    float GetModdedWeaponValue(int, int);
};
struct FUN_004bcf00_stand
{
    int GetModdedValue(bool);
};
// @fnv 0x004bcf00
int FUN_004bcf00_stand::GetModdedValue(bool abAddMod)
{
    if (abAddMod)
    {
        return (int)((double)((GetModHelper_4bcf00*)this)->GetModdedWeaponValue(10, 0) +
                     (double)(unsigned int)((_DummySimpleList*)((char*)this + 0x94))->_ref_00726070());
    }
    else
    {
        return (int)((_DummySimpleList*)((char*)this + 0x94))->_ref_00726070();
    }
}

struct FUN_004bcf60_shell
{
    float GetEffectValue(int effect, unsigned char value);
};

// Looks up one of three effect IDs and returns the float stored for value 0 or 1, otherwise 0.0f.
// @fnv 0x004bcf60
float FUN_004bcf60_shell::GetEffectValue(int effect, unsigned char value)
{
    if (*(int*)((char*)this + 0x180) == effect)
    {
        if (!value)
            return *(float*)((char*)this + 0x18c);
        else if (value == 1)
            return *(float*)((char*)this + 0x1ac);
    }
    else if (*(int*)((char*)this + 0x184) == effect)
    {
        if (!value)
            return *(float*)((char*)this + 0x190);
        else if (value == 1)
            return *(float*)((char*)this + 0x1b0);
    }
    else if (*(int*)((char*)this + 0x188) == effect)
    {
        if (!value)
            return *(float*)((char*)this + 0x194);
        else if (value == 1)
            return *(float*)((char*)this + 0x1b4);
    }
    else
        return 0.0f;
    return 0.0f;
}

struct FUN_004bd570_this
{
    int FUN_004bd570(unsigned int);
};
// Returns the int stored at offset 0x350, 0x354 or 0x358 for slot 1, 2 or 4, otherwise 0.
// @fnv 0x004bd570
int FUN_004bd570_this::FUN_004bd570(unsigned int slot)
{
    if (slot == 1)
    {
        return *(int*)((char*)this + 0x350);
    }
    else if (slot == 2)
    {
        return *(int*)((char*)this + 0x354);
    }
    else if (slot == 4)
    {
        return *(int*)((char*)this + 0x358);
    }
    else
    {
        return 0;
    }
}

struct FUN_00418660_shell
{
    TESForm* FUN_00418660();
};
struct FUN_004bd740_stand
{
    TESForm* GetExtraForm();
};
// Returns the form from the extra data list's first entry if the list and entry exist, otherwise returns null.
// @fnv 0x004bd740
TESForm* FUN_004bd740_stand::GetExtraForm()
{
    BSSimpleList<ExtraDataList*>* pkCurrentObject = *(BSSimpleList<ExtraDataList*>**)this;
    ExtraDataList* pextra;
    if (pkCurrentObject && *((_DummySimpleList*)pkCurrentObject)->_ref_006815c0())
    {
        pextra = *((_DummySimpleList*)pkCurrentObject)->_ref_006815c0();
        if (pextra && ((FUN_00418660_shell*)pextra)->FUN_00418660())
            return ((FUN_00418660_shell*)pextra)->FUN_00418660();
    }
    return 0;
}

struct FUN_00418ba0_shell
{
    bool FUN_00418ba0();
};
struct FUN_0042e560_shell
{
    unsigned char FUN_0042e560();
};
struct FUN_004bd820_stand
{
    unsigned char FUN_004bd820();
};
// Checks the list stored at this; if it and its first ExtraDataList exist and pass FUN_00418ba0, returns FUN_0042e560's result, else 0.
// @fnv 0x004bd820
unsigned char FUN_004bd820_stand::FUN_004bd820()
{
    BSSimpleList<ExtraDataList*>* pkCurrentObject;
    ExtraDataList* pextra;
    pkCurrentObject = *(BSSimpleList<ExtraDataList*>**)this;
    if (pkCurrentObject && *((_DummySimpleList*)pkCurrentObject)->_ref_006815c0())
    {
        pextra = *((_DummySimpleList*)pkCurrentObject)->_ref_006815c0();
        if (pextra && ((FUN_00418ba0_shell*)pextra)->FUN_00418ba0())
            return ((FUN_0042e560_shell*)pextra)->FUN_0042e560();
    }
    return 0;
}

struct Caller_42
{
    void FUN_0042e6f0();
};
struct Holder_70
{
    _DummySimpleList* first;
    void FUN_004bdc70();
};
// If the list has a first node whose referenced object is non-null, calls FUN_0042e6f0 on it.
// @fnv 0x004bdc70
void Holder_70::FUN_004bdc70()
{
    _DummySimpleList* pNode = first;
    if (pNode)
    {
        if (*pNode->_ref_006815c0())
        {
            Caller_42* pItem = (Caller_42*)*pNode->_ref_006815c0();
            if (pItem)
                pItem->FUN_0042e6f0();
        }
    }
}

struct FUN_004187d0_Class
{
    BSExtraData* FUN_004187d0();
};
struct FUN_004bdcc0_Class
{
    _DummySimpleList* first;
    BSExtraData* FUN_004bdcc0();
};
// Returns the BSExtraData from the first list entry's ExtraDataList if both the list and its extra data are non-null, otherwise null.
// @fnv 0x004bdcc0
BSExtraData* FUN_004bdcc0_Class::FUN_004bdcc0()
{
    BSExtraData* result = 0;
    _DummySimpleList* iter = first;
    if (iter && *iter->_ref_006815c0())
    {
        ExtraDataList* extra = *iter->_ref_006815c0();
        if (extra && ((FUN_004187d0_Class*)extra)->FUN_004187d0())
            result = ((FUN_004187d0_Class*)extra)->FUN_004187d0();
    }
    return result;
}

namespace fnv_004bdd80 {
struct FUN_004187d0_Class
{
    BSExtraData* FUN_004187d0();
};
struct FUN_0041af30_Class
{
    void FUN_0041af30();
};
struct FUN_004bdd80_stand
{
    _DummySimpleList* m_pHeadNode;
    void FUN_004bdd80();
};
// @fnv 0x004bdd80
void FUN_004bdd80_stand::FUN_004bdd80()
{
    _DummySimpleList* pNode = m_pHeadNode;
    if (pNode && *pNode->_ref_006815c0())
    {
        ExtraDataList* pExtra = *pNode->_ref_006815c0();
        if (pExtra && ((FUN_004187d0_Class*)pExtra)->FUN_004187d0())
            ((FUN_0041af30_Class*)pExtra)->FUN_0041af30();
    }
}
}  // namespace fnv_004bdd80

struct ScriptLocals;
struct ItemChangeShell : public InventoryStackRecord
{
    ScriptLocals* FUN_004bdea0();
};
struct ExtraDataList_shell2 : public ExtraDataList
{
    ScriptLocals* GetScriptLocalData();
};
// Walks the extra data list and returns the script locals from the first entry that has them, or 0 if none do.
// @fnv 0x004bdea0
ScriptLocals* ItemChangeShell::FUN_004bdea0()
{
    BSSimpleList<ExtraDataList*>* pkCurrentObject = m_pExtraDataLists;
    ExtraDataList* pextra;
    while (pkCurrentObject && pkCurrentObject->GetItem())
    {
        pextra = pkCurrentObject->GetItem();
        if (pextra && ((ExtraDataList_shell2*)pextra)->GetScriptLocalData())
            return ((ExtraDataList_shell2*)pextra)->GetScriptLocalData();
        pkCurrentObject = pkCurrentObject->GetNext();
    }
    return 0;
}

struct StartMenu
{
    const char* GetMenuTitle();
};
struct GlobalObject_0040c150 : public StartMenu
{
};
extern GlobalObject_0040c150 g_011d35b8;
struct TESModel
{
    unsigned int GetModelLength() const;
};
struct TESFullName : public BaseFormComponent
{
    unsigned int GetModelLength() const;
    const char* GetFullName();
};
struct TESBoundObject : public BaseFormComponent
{
};
struct ActorPackage_004be2d0
{
    TESBoundObject* GetTarget();
};
struct FUN_004be2d0_shell
{
    const char* GetTargetFullName();
};
// @fnv 0x004be2d0
const char* FUN_004be2d0_shell::GetTargetFullName()
{
    TESFullName* fullname = dynamic_cast<TESFullName*>(reinterpret_cast<ActorPackage_004be2d0*>(this)->GetTarget());
    if (fullname && fullname->GetModelLength())
        return fullname->GetFullName();
    return g_011d35b8.GetMenuTitle();
}

struct IsEmptyNode
{
    bool _ref_008256d0();
};
struct CallerNode
{
    void FUN_00426020(int, int, int, int);
};
struct FUN_004bed00_host
{
    _DummySimpleList* first;
    int unk04;
    int unk08;
    void FUN_004bed00();
};
// Walks the linked list from first, and for each non-empty node whose extra data is non-null, calls FUN_00426020 with unk08.
// @fnv 0x004bed00
void FUN_004bed00_host::FUN_004bed00()
{
    _DummySimpleList* pNode = first;
    ExtraDataList* pExtra;
    while (pNode && !((IsEmptyNode*)pNode)->_ref_008256d0())
    {
        pExtra = *pNode->_ref_006815c0();
        if (pExtra)
        {
            ((CallerNode*)pExtra)->FUN_00426020(0, 0, 0, unk08);
        }
        pNode = pNode->_ref_00726070();
    }
}

struct IndexedPointerCollection
{
    void DestroyList();
    void* FUN_004bf630(unsigned int);
};
void _Deallocate(void*);
// Calls DestroyList, then deallocates this if flags has bit 1 set, and returns this.
// @fnv 0x004bf630
void* IndexedPointerCollection::FUN_004bf630(unsigned int flags)
{
    DestroyList();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_004bfb30_shell
{
    unsigned int GetAtIfValid(int);
};
// Returns the element at idx from the array at offset 0xE3C when idx is between 0 and 8, otherwise 0.
// @fnv 0x004bfb30
unsigned int FUN_004bfb30_shell::GetAtIfValid(int aiIndex)
{
    return (aiIndex >= 0 && aiIndex <= 8) ? ((BSSimpleArray<unsigned int, 400>*)((char*)this + 0xE3C))->GetAt(aiIndex)
                                          : 0;
}

struct DAT_011c6444_type
{
    virtual void F0();
    virtual void F1();
    virtual void F2();
    virtual void F3();
    virtual ~DAT_011c6444_type();
};
extern DAT_011c6444_type* DAT_011c6444;
// Deletes the global DAT_011c6444 object if it is non-null, then sets the pointer to null.
// @fnv 0x004c1c40
void FUN_004c1c40()
{
    if (DAT_011c6444)
        delete DAT_011c6444;
    DAT_011c6444 = 0;
}

struct ScriptS
{
    void* _ref_006815c0();
    void* _ref_00726070();
    void* GetHeader();
    TESObject* GetNext();
};
struct FUN_00474a40
{
    ScriptS* GetScript();
};
struct FUN_00474a00
{
    TESForm* GetForm();
};
struct FUN_004c7300_shell : public InventoryChanges
{
    int GetObjectCount(TESForm*);
    InventoryStackRecord* FindInventoryItem(TESObjectREFR* pRef, bool* pFound);
};
// @fnv 0x004c7300
InventoryStackRecord* FUN_004c7300_shell::FindInventoryItem(TESObjectREFR* pRef, bool* pFound)
{
    *pFound = false;
    if (!pRef)
        return 0;
    ScriptS* script3 = ((FUN_00474a40*)((char*)pRef + 0xa4))->GetScript();
    InventoryStackRecord* result2 = 0;
    if (script3)
    {
        unsigned int index = 0;
        TESObject* next = script3->GetNext();
        ScriptS* current2 = (ScriptS*)script3->GetHeader();
        while (current2 && ((char**)current2->_ref_006815c0())[0])
        {
            InventoryStackRecord* item = (InventoryStackRecord*)((char**)current2->_ref_006815c0())[0];
            *pFound = true;
            if (this->GetObjectCount((TESForm*)item) > 0)
            {
                if (index < (unsigned int)next)
                    result2 = item;
                else
                    return item;
            }
            current2 = (ScriptS*)current2->_ref_00726070();
            index++;
        }
    }
    if (result2)
        return result2;
    TESForm* form4 = ((FUN_00474a00*)((char*)pRef + 0xa4))->GetForm();
    if (form4)
    {
        *pFound = true;
        if (this->GetObjectCount(form4) > 0)
            return (InventoryStackRecord*)form4;
    }
    return 0;
}

struct List_009e03e0
{
    ~List_009e03e0();
    void RemoveAll();
};
struct Unk_004ca1a0
{
    List_009e03e0* pList;
    void DestroyList();
};
// If pList is set, removes all its elements, deletes it and clears the pointer.
// @fnv 0x004ca1a0
void Unk_004ca1a0::DestroyList()
{
    if (pList)
    {
        pList->RemoveAll();
        delete pList;
        pList = 0;
    }
}

struct TESRaceForm
{
    void Initialize(unsigned int);
};
struct TESScriptableForm : public TESForm
{
    virtual ~TESScriptableForm();
};
// @fnv 0x004ce300
void FUN_004ce300(TESForm* apForm, unsigned int uiValue)
{
    TESScriptableForm* c = dynamic_cast<TESScriptableForm*>(apForm);
    if (c)
        ((TESRaceForm*)c)->Initialize(uiValue);
}

struct FUN_004ce340_stand
{
    void FUN_004ce340(int a0, int a1, bool a2, bool a3, bool a4, bool a5, int a6, int a7);
    void FUN_004ce380(int a0, int a1, bool a2, bool a3, bool a4, bool a5, int a6, int a7);
};
// Forwards all arguments unchanged to FUN_004ce380.
// @fnv 0x004ce340
void FUN_004ce340_stand::FUN_004ce340(int a0, int a1, bool a2, bool a3, bool a4, bool a5, int a6, int a7)
{
    FUN_004ce380(a0, a1, a2, a3, a4, a5, a6, a7);
}

struct C008256d0
{
    bool _ref_008256d0();
};
struct C004bed00
{
    void FUN_004bed00();
};
struct S_004d4030
{
    ItemNode* head;
    void FUN_004d4030();
};
// @fnv 0x004d4030
void S_004d4030::FUN_004d4030()
{
    ItemNode* cur = head;
    InventoryStackRecord* item;
    while (cur && !((C008256d0*)cur)->_ref_008256d0())
    {
        item = *_ref_006815c0(cur);
        if (item)
            ((C004bed00*)item)->FUN_004bed00();
        cur = _ref_00726070(cur);
    }
}

struct FUN_004bd880_stand
{
    char _pad[0x180];
    void* f180;
    void* f184;
    void* f188;
    void* GetSlotPointer(int);
};
// Returns the pointer stored at f180, f184 or f188 for slot 1, 2 or 4, otherwise returns 0.
// @fnv 0x004bd880
void* FUN_004bd880_stand::GetSlotPointer(int slot)
{
    if (slot == 1)
    {
        return f180;
    }
    else if (slot == 2)
    {
        return f184;
    }
    else if (slot == 4)
    {
        return f188;
    }
    else
    {
        return 0;
    }
}

struct VTableHelper
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
    virtual bool v064();
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
    virtual void v195(float);
};

// @fnv 0x004bf0e0
void __fastcall FUN_004bf0e0(InventoryChanges* pThis)
{
    pThis->m_fArmorWeight = pThis->m_fTotalWeight;
    pThis->m_fTotalWeight = -1.0f;
    if (pThis->pRef && ((VTableHelper*)pThis->pRef)->v064())
    {
        VTableHelper* pact = (VTableHelper*)pThis->pRef;
        pact->v195(-1.0f);
    }
}

namespace fnv_004bf150 {
struct ExtraNode;
ExtraNode* __fastcall _ref_00726070(ExtraNode*);
InventoryStackRecord** __fastcall _ref_006815c0(ExtraNode*);
struct FUN_004bc780_shell
{
    void ClearExtraDataList();
};

struct RefVtable
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
    virtual void MarkAsUnmodified(unsigned int);
};

struct FUN_004bf150_shell : public InventoryChanges
{
    void ClearInventoryChanges();
};

// Walks the extra-node list, calls ClearExtraDataList and deletes each item, then clears the list, marks the ref unmodified and frees the list.
// @fnv 0x004bf150
void FUN_004bf150_shell::ClearInventoryChanges()
{
    ExtraNode* node = (ExtraNode*)this->m_pEntryList;
    while (node && *_ref_006815c0(node))
    {
        InventoryStackRecord* item = *_ref_006815c0(node);
        node = _ref_00726070(node);
        ((FUN_004bc780_shell*)item)->ClearExtraDataList();
        delete item;
    }
    this->m_pEntryList->RemoveAll();
    if (this->pRef)
        ((RefVtable*)this->pRef)->MarkAsUnmodified(0x8000020);
    delete (BSSimpleList<const char*>*)this->m_pEntryList;
}
}  // namespace fnv_004bf150

struct XIdle;
struct XArr
{
    void SetAt(unsigned int i, XIdle*& v);
};
struct FUN_004bfb70_stand
{
    char pad[0xe3c];
    XArr arr;
    void SetIdleAt(unsigned int i, XIdle* v);
};
// Stores an XIdle pointer into the array at the given index.
// @fnv 0x004bfb70
void FUN_004bfb70_stand::SetIdleAt(unsigned int uiIndex, XIdle* v)
{
    arr.SetAt(uiIndex, v);
}

struct FUN_004c0c60_Helper
{
    char pad[0xf4];
    signed char type;
    bool IsGunWeapon()
    {
        switch (type)
        {
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            return true;
        default:
            return false;
        }
    }
};

// Returns true when the helper's type field is one of 3 through 9, otherwise false.
// @fnv 0x004c0c60
bool __fastcall FUN_004c0c60(FUN_004c0c60_Helper* pThis)
{
    switch (pThis->type)
    {
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        return true;
    default:
        return false;
    }
}

struct FUN_004c0cd0_This
{
    char pad[0x1f0];
    int field_1f0;
};

struct FUN_004c0cd0_Arg
{
    int val;
};

// @fnv 0x004c0cd0
void __fastcall SetField1F0(FUN_004c0cd0_This* pThis, FUN_004c0cd0_Arg aValue)
{
    pThis->field_1f0 = aValue.val;
}

void* __cdecl operator new(unsigned int);
void __fastcall FUN_004bf0e0(InventoryChanges*);
struct SL
{
    SL();
    void* a;
    void* b;
};
struct FUN_004befb0
{
    SL* m_pEntryList;
    TESObjectREFR* pRef;
    float m_fTotalWeight;
    float m_fArmorWeight;
    bool m_bChanged;
    FUN_004befb0(TESObjectREFR* apRef);
};
// @fnv 0x004befb0
FUN_004befb0::FUN_004befb0(TESObjectREFR* apRef)
{
    AutoMemContext tempMemContext((MEM_CONTEXT)0x36, true, g_inventoryChangesSourceFilename, 0x6de);
    pRef = apRef;
    m_pEntryList = new SL;
    if (DAT_011c6444 == 0)
    {
        DAT_011c6444 = (DAT_011c6444_type*)new TESObjectREFR;
        ((TESForm*)DAT_011c6444)->NotifySaveLoadGameOfFormChange();
    }
    m_fTotalWeight = -1.0f;
    m_fArmorWeight = m_fTotalWeight;
    FUN_004bf0e0((InventoryChanges*)this);
    m_bChanged = false;
}

struct TESContainer;
struct FUN_004bfba0_shell
{
    InventoryStackRecord* FUN_004bfba0(TESBoundObject*, int, int);
};
struct FUN_004bffb0_shell
{
    TESContainer* FUN_004bffb0();
};
struct QEntry1
{
    int count;
    TESBoundObject* form;
};
struct QEntry2
{
    int pad;
    int count;
    TESBoundObject* form;
};
struct QNode1
{
    QEntry1** _ref_006815c0();
    QNode1* _ref_00726070();
};
struct QNode2
{
    QEntry2** _ref_006815c0();
    QNode2* _ref_00726070();
    bool _ref_008256d0();
};
struct FUN_004d0360_shell
{
    QNode2* list;
    bool FUN_004d0360();
};
// Scans the process container and the list for a quest item whose count does not cancel out, returning whether one is found.
// @fnv 0x004d0360
bool FUN_004d0360_shell::FUN_004d0360()
{
    bool found = false;
    QNode1* it =
        (QNode1*)((BaseProcess*)((FUN_004bffb0_shell*)this)->FUN_004bffb0())->BaseProcess::GetCurrentProcessData();
    while (it && *it->_ref_006815c0() && !found)
    {
        QEntry1* entry = *it->_ref_006815c0();
        if (((TESForm*)entry->form)->IsQuestItem())
        {
            found = true;
            QEntry2* change = (QEntry2*)((FUN_004bfba0_shell*)this)->FUN_004bfba0(entry->form, 1, 0);
            if (change && change->count + entry->count == 0)
                found = false;
        }
        it = it->_ref_00726070();
    }
    if (!found)
    {
        QNode2* node = list;
        while (node && !node->_ref_008256d0() && !found)
        {
            QEntry2* item = *node->_ref_006815c0();
            if (item && item->form && ((TESForm*)item->form)->IsQuestItem() && item->count > 0)
                found = true;
            node = node->_ref_00726070();
        }
    }
    return found;
}

namespace fnv_004d0490 {
struct TESContainer;
struct Script;
struct FUN_004bfba0_shell
{
    InventoryStackRecord* FUN_004bfba0(TESBoundObject*, int, int);
};
struct FUN_004bffb0_shell
{
    TESContainer* FUN_004bffb0();
};
struct FUN_0057c850_cls
{
    bool FUN_0057c850(TESBoundObject*, bool*);
};
struct FUN_0056aac0_map
{
    void SetAt(TESBoundObject*, bool);
};
struct FUN_004d4de0
{
    int a, b, c, d;
    FUN_004d4de0(int);
    ~FUN_004d4de0();
};
Script* __cdecl FUN_004826d0(TESBoundObject*);
struct SEntry1
{
    int count;
    TESBoundObject* form;
};
struct SEntry2
{
    int pad;
    int count;
    TESBoundObject* form;
};
struct SNode1
{
    SEntry1** _ref_006815c0();
    SNode1* _ref_00726070();
    bool _ref_008256d0();
};
struct SNode2
{
    SEntry2** _ref_006815c0();
    SNode2* _ref_00726070();
    bool _ref_008256d0();
};
struct FUN_004d0490_shell
{
    SNode2* list;
    bool FUN_004d0490();
};
// @fnv 0x004d0490
bool FUN_004d0490_shell::FUN_004d0490()
{
    bool bfound9 = false;
    FUN_004d4de0 kMapA(0x25);
    SNode1* pIterVal =
        (SNode1*)((BaseProcess*)((FUN_004bffb0_shell*)this)->FUN_004bffb0())->BaseProcess::GetCurrentProcessData();
    while (pIterVal && !pIterVal->_ref_008256d0() && !bfound9)
    {
        bool seen5;
        SEntry1* entry7 = *pIterVal->_ref_006815c0();
        seen5 = false;
        if (!((FUN_0057c850_cls*)&kMapA)->FUN_0057c850(entry7->form, &seen5))
        {
            ((FUN_0056aac0_map*)&kMapA)->SetAt(entry7->form, true);
            if (FUN_004826d0(entry7->form))
            {
                bfound9 = true;
                SEntry2* change = (SEntry2*)((FUN_004bfba0_shell*)this)->FUN_004bfba0(entry7->form, 1, 0);
                if (change && change->count + entry7->count == 0)
                    bfound9 = false;
            }
        }
        pIterVal = pIterVal->_ref_00726070();
    }
    if (!bfound9)
    {
        SNode2* node5 = list;
        while (node5 && !node5->_ref_008256d0() && !bfound9)
        {
            SEntry2* item = *node5->_ref_006815c0();
            bool seen8 = false;
            if (item->count && !((FUN_0057c850_cls*)&kMapA)->FUN_0057c850(item->form, &seen8))
            {
                if (FUN_004826d0(item->form))
                    bfound9 = true;
            }
            node5 = node5->_ref_00726070();
        }
    }
    return bfound9;
}
}  // namespace fnv_004d0490

struct ContainerItemExtra;
struct TESBoundObject;
struct TESForm;
struct InventoryItemEntry
{
    void Save();
    void InitItem(TESForm*);
    bool Compare(InventoryItemEntry*);
    void Copy(InventoryItemEntry*);
    void* __vecDelDtor(unsigned int);
    int m_iCountDelta;
    TESBoundObject* pObj;
    ContainerItemExtra* m_pExtraData;
};
typedef char _sizecheck_ContainerObject[sizeof(InventoryItemEntry) == 12 ? 1 : -1];
struct FUN_004d1610_shell : public InventoryChanges
{
    void FUN_004d1610();
};

struct ContNode;
struct FUN_004bffb0_S
{
    void* FUN_004bffb0();
};
ContNode* __fastcall FUN_00717e50(void*);
bool __fastcall FUN_008256d0(ContNode*);
InventoryItemEntry** __fastcall FUN_006815c0(ContNode*);
ContNode* __fastcall FUN_00726070(ContNode*);
struct FUN_00410360
{
    FUN_00410360();
    char pad[0x20];
};
struct FUN_004bc550
{
    FUN_004bc550(TESBoundObject*, int);
    char pad[0xc];
};
struct FUN_00419ad0_S
{
    void FUN_00419ad0(unsigned short);
};
void* __cdecl GetHealthForm(TESBoundObject*);
struct FUN_0040ea20_S
{
    void FUN_0040ea20(ExtraDataList*, void*);
};
struct FUN_005ae3d0_S
{
    void FUN_005ae3d0(ExtraDataList**);
};
struct FUN_004c3380_S
{
    void FUN_004c3380(InventoryStackRecord*, bool);
};

// @fnv 0x004d1610
void FUN_004d1610_shell::FUN_004d1610()
{
    ContNode* pCurrentElementNext = FUN_00717e50(((FUN_004bffb0_S*)this)->FUN_004bffb0());
    while (pCurrentElementNext && !FUN_008256d0(pCurrentElementNext))
    {
        InventoryItemEntry* pItem = *FUN_006815c0(pCurrentElementNext);
        pCurrentElementNext = FUN_00726070(pCurrentElementNext);
        if (pItem->pObj && _FNV_GetFormType((unsigned int)pItem->pObj) != 0x34 && pItem->m_pExtraData)
        {
            ExtraDataList* pextra = (ExtraDataList*)new FUN_00410360;
            ((FUN_00419ad0_S*)pextra)->FUN_00419ad0(*(unsigned short*)&pItem->m_iCountDelta);
            ((FUN_0040ea20_S*)pItem->m_pExtraData)->FUN_0040ea20(pextra, GetHealthForm(pItem->pObj));
            InventoryStackRecord* pchange = (InventoryStackRecord*)new FUN_004bc550(pItem->pObj, 0);
            (*(FUN_005ae3d0_S**)pchange)->FUN_005ae3d0(&pextra);
            ((FUN_004c3380_S*)this)->FUN_004c3380(pchange, true);
        }
    }
}

struct RefV_004d17a0
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
    virtual void MarkAsModified(unsigned int);
};
struct Extra_004d17a0
{
    virtual ~Extra_004d17a0();
    void* GetExtraLeveledItem();
    void FUN_0041d000();
    short FUN_00418770();
};
struct ExtraNode_004d17a0
{
    Extra_004d17a0** _ref_006815c0();
    ExtraNode_004d17a0* _ref_00726070();
    bool _ref_008256d0();
    void _ref_00905330(Extra_004d17a0**);
};
struct ItemNode_004d17a0
{
    InventoryStackRecord** _ref_006815c0();
    ItemNode_004d17a0* _ref_00726070();
    bool _ref_008256d0();
    void _ref_00905330(InventoryStackRecord**);
};
struct ItemCount_004d17a0
{
    int _ref_00726070();
    void FUN_006ecd40(int);
};
struct FUN_004d17a0_t
{
    ItemNode_004d17a0* m_pEntryList;
    RefV_004d17a0* pRef;
    void FUN_004d17a0();
};

// Marks pRef as modified, then walks the item list removing extra entries whose GetExtraLeveledItem is true and deleting items left with no count.
// @fnv 0x004d17a0
void FUN_004d17a0_t::FUN_004d17a0()
{
    pRef->MarkAsModified(0x8000000);
    ItemNode_004d17a0* pkNode = m_pEntryList;
    while (pkNode && !pkNode->_ref_008256d0() && *pkNode->_ref_006815c0())
    {
        InventoryStackRecord* pItem = *pkNode->_ref_006815c0();
        ExtraNode_004d17a0* pkExtraNode = (ExtraNode_004d17a0*)pItem->m_pExtraDataLists;
        while (pkExtraNode && *pkExtraNode->_ref_006815c0())
        {
            Extra_004d17a0* pExtra = *pkExtraNode->_ref_006815c0();
            if (pExtra)
            {
                if (pExtra->GetExtraLeveledItem())
                {
                    pExtra->FUN_0041d000();
                    ((ItemCount_004d17a0*)pItem)
                        ->FUN_006ecd40(((ItemCount_004d17a0*)pItem)->_ref_00726070() - pExtra->FUN_00418770());
                    pkExtraNode->_ref_00905330(&pExtra);
                    delete pExtra;
                    pkExtraNode = (ExtraNode_004d17a0*)pItem->m_pExtraDataLists;
                }
                else
                    pkExtraNode = pkExtraNode->_ref_00726070();
            }
            else
                pkExtraNode = pkExtraNode->_ref_00726070();
        }
        if (pItem && pItem->m_pExtraDataLists && ((ExtraNode_004d17a0*)pItem->m_pExtraDataLists)->_ref_008256d0() &&
            !((ItemCount_004d17a0*)pItem)->_ref_00726070())
        {
            m_pEntryList->_ref_00905330(&pItem);
            delete pItem;
            pItem = 0;
            pkNode = m_pEntryList;
        }
        else
            pkNode = pkNode->_ref_00726070();
    }
}

struct FUN_00418c00_shell
{
    bool CheckExtraByType(int);
};
struct FUN_004bd8d0_shell : public InventoryStackRecord
{
    bool FUN_004bd8d0(unsigned char, float*);
};

// Checks the item's extra data list for slot flags 1, 2 or 4 matching type, writes the slot value to result and returns true, else false.
// @fnv 0x004bd8d0
bool FUN_004bd8d0_shell::FUN_004bd8d0(unsigned char type, float* pfResult)
{
    InventoryStackRecord* item = *(InventoryStackRecord**)this;
    if (item && *(ExtraDataList**)_ref_006815c0(item))
    {
        InventoryStackRecord* extra = (InventoryStackRecord*)*_ref_006815c0(item);
        if (extra)
        {
            InventoryStackRecord* slot = *(InventoryStackRecord**)((char*)this + 8);
            if (((FUN_00418c00_shell*)extra)->CheckExtraByType(1) &&
                (int)((FUN_004bd880_stand*)slot)->GetSlotPointer(1) == type)
            {
                *pfResult = ((FUN_004bd9d0_shell*)slot)->FUN_004bd9d0(1, 0);
                return true;
            }
            if (((FUN_00418c00_shell*)extra)->CheckExtraByType(2) &&
                (int)((FUN_004bd880_stand*)slot)->GetSlotPointer(2) == type)
            {
                *pfResult = ((FUN_004bd9d0_shell*)slot)->FUN_004bd9d0(2, 0);
                return true;
            }
            if (((FUN_00418c00_shell*)extra)->CheckExtraByType(4) &&
                (int)((FUN_004bd880_stand*)slot)->GetSlotPointer(4) == type)
            {
                *pfResult = ((FUN_004bd9d0_shell*)slot)->FUN_004bd9d0(4, 0);
                return true;
            }
        }
    }
    return false;
}

struct TESNPC
{
    int GetSex();
};
struct FUN_00481230_stand
{
    const char* FUN_00481230(int);
};
struct TESTextureLoader
{
    static const char* __cdecl GetTextureResourceName(TESForm*, TESObjectREFR*);
};
extern GlobalObject_0040c150 g_011d33f0;
struct ItemChange_004be200 : public FUN_004bd740_stand
{
    const char* GetIconFilename(TESObjectREFR* apRef);
};
// Returns the biped model icon for the owner NPC's sex, falling back to the texture loader icon or a default.
// @fnv 0x004be200
const char* ItemChange_004be200::GetIconFilename(TESObjectREFR* apRef)
{
    const char* piconFilename = 0;
    TESForm* powner = GetExtraForm();
    TESBipedModelForm* pbipedModel = dynamic_cast<TESBipedModelForm*>((TESBoundObject*)*(void**)((char*)this + 8));
    if (powner && pbipedModel)
    {
        TESNPC* pownerNPC = dynamic_cast<TESNPC*>(powner);
        if (pownerNPC)
            piconFilename = ((FUN_00481230_stand*)pbipedModel)->FUN_00481230(pownerNPC->GetSex());
    }
    if (!piconFilename || !piconFilename[0])
        piconFilename =
            TESTextureLoader::GetTextureResourceName((TESForm*)(TESBoundObject*)*(void**)((char*)this + 8), apRef);
    if (!piconFilename || !piconFilename[0])
        return g_011d33f0.GetMenuTitle();
    return piconFilename;
}

namespace fnv_004bee00 {
struct Actor;
struct SaveLoadFile;
struct ThreeByThreeMatrix;
struct NiPoint3;
struct NiQuaternion;
struct TESForm;
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
struct FUN_004bee00_shell : public InventoryStackRecord
{
    void FUN_004bee00(BGSLoadFormBuffer*);
};

TESForm* GetFormByID(unsigned int);
struct SoundListView
{
    void AddTail(char* const&);
};
struct FUN_00428150_stand
{
    void FUN_00428150(BGSLoadFormBuffer*);
};

// @fnv 0x004bee00
void FUN_004bee00_shell::FUN_004bee00(BGSLoadFormBuffer* apLoadGameBuffer)
{
    unsigned int iExtraDataCount;
    *(TESBoundObject**)((char*)this + 8) =
        dynamic_cast<TESBoundObject*>((::TESForm*)GetFormByID(apLoadGameBuffer->ReadFormIdentifier()));
    apLoadGameBuffer->ReadTypedData((void*)((char*)this + 4), 4);
    ((FUN_004bc780_shell*)this)->ClearExtraDataList();
    iExtraDataCount = apLoadGameBuffer->ReadElementCount();
    if (iExtraDataCount)
    {
        if (!*(SL**)this)
            *(SL**)this = new SL;
        for (unsigned int iIndex = 0; iIndex < iExtraDataCount; iIndex++)
        {
            ExtraDataList* pextraDataList = (ExtraDataList*)new FUN_00410360;
            ((FUN_00428150_stand*)pextraDataList)->FUN_00428150(apLoadGameBuffer);
            (*(SoundListView**)this)->AddTail(reinterpret_cast<char* const&>(pextraDataList));
        }
    }
}
}  // namespace fnv_004bee00

struct MagicTargetDispel : MagicTarget
{
    void Dispel(TESBoundObject*, bool);
};
struct ActorDispelView : MobileObject, MagicCaster, MagicTargetDispel
{
};
struct FUN_004bfe50_inode
{
    InventoryStackRecord** FUN_006815c0();
    FUN_004bfe50_inode* FUN_00726070();
};
struct FUN_004bfe50_enode
{
    ExtraDataList** FUN_006815c0();
    FUN_004bfe50_enode* FUN_00726070();
};
struct FUN_004bddd0_t
{
    bool FUN_004bddd0(bool);
};
struct FUN_004c0cf0_t
{
    void FUN_004c0cf0(bool*, unsigned int, int, Actor*, ExtraDataList*, int, bool, InventoryStackRecord*, int);
};
struct FUN_004bfe50_t : InventoryChanges
{
    void RemoveWornItems(bool abSkipCanNotWear, TESObjectREFR* apRef);
};

// Iterates the inventory list, dispels worn items from the actor and removes them, restarting the walk when an entry is removed.
// @fnv 0x004bfe50
void FUN_004bfe50_t::RemoveWornItems(bool abSkipCanNotWear, TESObjectREFR* apRef)
{
    FUN_004bfe50_inode* pInvNode;
    pInvNode = (FUN_004bfe50_inode*)m_pEntryList;
    while (pInvNode)
    {
        InventoryStackRecord* pitem = *pInvNode->FUN_006815c0();
        if (pitem)
        {
            bool bremoved = false;
            ActorDispelView* pact = (ActorDispelView*)apRef;
            if (((FUN_004bddd0_t*)pitem)->FUN_004bddd0(false))
            {
                int iwornCount = 1;
                ExtraDataList* pextra = 0;
                for (FUN_004bfe50_enode* pExtraNode = (FUN_004bfe50_enode*)pitem->m_pExtraDataLists;
                     pExtraNode && *pExtraNode->FUN_006815c0(); pExtraNode = pExtraNode->FUN_00726070())
                {
                    if (((FUN_00418ab0_shell*)*pExtraNode->FUN_006815c0())->FUN_00418ab0(false))
                    {
                        iwornCount = FUN_00418770(*pExtraNode->FUN_006815c0());
                        pextra = *pExtraNode->FUN_006815c0();
                        break;
                    }
                }
                if (pact)
                    pact->Dispel((TESBoundObject*)((ArrSI*)pitem)->GetFlags(), true);
                ((FUN_004c0cf0_t*)this)
                    ->FUN_004c0cf0(&bremoved, ((ArrSI*)pitem)->GetFlags(), iwornCount, (Actor*)pact, pextra, 0, true,
                                   pitem, 0);
                if (bremoved)
                    pInvNode = (FUN_004bfe50_inode*)m_pEntryList;
                else
                    pInvNode = pInvNode->FUN_00726070();
            }
            else
            {
                pInvNode = pInvNode->FUN_00726070();
            }
        }
        else
        {
            pInvNode = pInvNode->FUN_00726070();
        }
    }
}

int __fastcall FNV_GetFormType(TESForm*);
bool __fastcall FUN_004c94d0(TESForm*);
bool __fastcall IsFlag80Clear(TESForm*);

struct TESContainer
{
    bool HasObjectOfType(TESObject*);
    int GetObjectCount(TESObject*);
};
struct FUN_00480d90_shell : public TESBipedModelForm
{
    bool FUN_00480d90();
};
struct FUN_004bc8f0_shell : public InventoryStackRecord
{
    int FUN_004bc8f0(bool);
};
struct FUN_00726070_shell : public InventoryStackRecord
{
    int FUN_00726070();
};
struct Flt
{
    operator unsigned int() const;
};
struct TESBipedModelFormEx
{
    static TESBipedModelForm* __cdecl GetFormAsBipedModel(TESForm*);
};
struct TESLevItem : public TESBoundObject
{
};

struct FUN_004c8fd0_t : public InventoryChanges
{
    int FUN_004c8fd0(bool);
};

// Counts inventory items, optionally skipping non-playable forms, and removes entries whose count is negative.
// @fnv 0x004c8fd0
int FUN_004c8fd0_t::FUN_004c8fd0(bool abcountplayable)
{
    int icount = 0;
    bool bHasResultObj;
    BSSimpleList<InventoryStackRecord*>* pkCurrentObject;
    int itempcount;
    if (((FUN_004bffb0_shell*)this)->FUN_004bffb0())
    {
        BSSimpleList<InventoryItemEntry*>* pCurrentElementNext =
            (BSSimpleList<InventoryItemEntry*>*)FUN_00717e50(((FUN_004bffb0_shell*)this)->FUN_004bffb0());
        while (pCurrentElementNext && pCurrentElementNext->GetItem())
        {
            InventoryItemEntry* pobject = pCurrentElementNext->GetItem();
            TESLevItem* pObj = dynamic_cast<TESLevItem*>(pobject->pObj);
            TESBipedModelForm* pbipedForm = 0;
            int ioriginalcount = ((FUN_004bffb0_shell*)this)->FUN_004bffb0()->GetObjectCount((TESObject*)pobject->pObj);
            if (!abcountplayable)
            {
                switch (FNV_GetFormType((TESForm*)pobject->pObj))
                {
                case 41:
                    if (!FUN_004c94d0((TESForm*)pobject->pObj))
                        pobject = 0;
                    break;
                case 40:
                    if (!IsFlag80Clear((TESForm*)pobject->pObj))
                        pobject = 0;
                    break;
                default:
                    pbipedForm = TESBipedModelFormEx::GetFormAsBipedModel((TESForm*)pobject->pObj);
                    if (pbipedForm && !((FUN_00480d90_shell*)pbipedForm)->FUN_00480d90())
                        pobject = 0;
                    break;
                }
            }
            if (pobject && !pObj)
            {
                InventoryStackRecord* pitem = ((FUN_004bfba0_shell*)this)->FUN_004bfba0(pobject->pObj, true, false);
                int iAbsCount = ioriginalcount;
                if (iAbsCount < 0)
                    iAbsCount *= -1;
                if (pitem && pitem->m_iCountChange + iAbsCount > 0 &&
                    (ioriginalcount >= 0 || !pitem || ((FUN_00726070_shell*)pitem)->FUN_00726070() > ioriginalcount))
                {
                    if (pitem->m_pExtraDataLists && pitem->m_pExtraDataLists->GetItem())
                    {
                        icount += ((FUN_004bca80_shell*)pitem)->CountAndPruneEntries();
                        if (pitem->HasApplicablePerkEntry())
                            icount++;
                        if (((FUN_004bc8f0_shell*)pitem)->FUN_004bc8f0(false) <
                                ioriginalcount + pitem->m_iCountChange &&
                            pitem->m_pExtraDataLists->GetItem() && !((FUN_004bddd0_shell*)pitem)->FUN_004bddd0(false) &&
                            !pitem->m_pExtraDataLists->GetItem()->HasExtraDataType0x2F())
                            icount++;
                    }
                    else
                    {
                        icount++;
                    }
                }
                else if (!pitem)
                {
                    icount++;
                }
            }
            pCurrentElementNext = pCurrentElementNext->GetNext();
        }
    }
    pkCurrentObject = *(BSSimpleList<InventoryStackRecord*>**)this;
    itempcount = icount;
    bHasResultObj = true;
    while (pkCurrentObject && pkCurrentObject->GetItem())
    {
        InventoryStackRecord* pitem = pkCurrentObject->GetItem();
        bHasResultObj = true;
        bool bcontinue = true;
        if (pitem)
        {
            if ((unsigned int)*(const Flt*)pitem &&
                ((BSSimpleList<ExtraDataList*>*)(unsigned int)*(const Flt*)pitem)->GetItem() &&
                ((BSSimpleList<ExtraDataList*>*)(unsigned int)*(const Flt*)pitem)->GetItem()->HasExtraDataType0x2F())
                bcontinue = true;
            else if (((FUN_004bffb0_shell*)this)->FUN_004bffb0() &&
                     ((FUN_004bffb0_shell*)this)->FUN_004bffb0()->HasObjectOfType((TESObject*)pitem->m_pItemObject))
                bcontinue = false;
            TESBipedModelForm* pbipedForm = 0;
            if (!abcountplayable)
            {
                switch (FNV_GetFormType((TESForm*)((ArrSI*)pitem)->GetFlags()))
                {
                case 41:
                    if (!FUN_004c94d0((TESForm*)((ArrSI*)pitem)->GetFlags()))
                        bcontinue = false;
                    break;
                case 40:
                    if (!IsFlag80Clear((TESForm*)((ArrSI*)pitem)->GetFlags()))
                        bcontinue = false;
                    break;
                default:
                    pbipedForm = TESBipedModelFormEx::GetFormAsBipedModel((TESForm*)((ArrSI*)pitem)->GetFlags());
                    if (pbipedForm)
                        bcontinue = ((FUN_00480d90_shell*)pbipedForm)->FUN_00480d90();
                    break;
                }
            }
        }
        if (pitem && pitem->m_iCountChange > 0 && bcontinue)
        {
            icount += ((FUN_004bca80_shell*)pitem)->CountAndPruneEntries();
            if (pitem->HasApplicablePerkEntry())
                icount++;
            if (((FUN_004bc8f0_shell*)pitem)->FUN_004bc8f0(false) < pitem->m_iCountChange)
                icount++;
            if (((FUN_00726070_shell*)pitem)->FUN_00726070() < 0 &&
                !((unsigned int)*(const Flt*)pitem &&
                  ((BSSimpleList<ExtraDataList*>*)(unsigned int)*(const Flt*)pitem)->GetItem() &&
                  ((BSSimpleList<ExtraDataList*>*)(unsigned int)*(const Flt*)pitem)->GetItem()->HasExtraDataType0x2F()))
            {
                (*(BSSimpleList<InventoryStackRecord*>**)this)->Remove(pitem);
                ((FUN_004bc780_shell*)pitem)->ClearExtraDataList();
                delete pitem;
                icount = itempcount;
                pkCurrentObject = *(BSSimpleList<InventoryStackRecord*>**)this;
                if (pkCurrentObject && pkCurrentObject->GetItem())
                    pitem = pkCurrentObject->GetItem();
                else
                    pitem = 0;
                bHasResultObj = false;
            }
        }
        if (bHasResultObj)
            pkCurrentObject = pkCurrentObject->GetNext();
    }
    return icount + 1;
}

struct ContEntry4cfe20
{
    int count;
    ::TESBoundObject* pObj;
};
struct ContNode4cfe20
{
    bool _ref_008256d0();
    ContEntry4cfe20** _ref_006815c0();
    ContNode4cfe20* _ref_00726070();
};
struct Container4cfe20
{
    ContNode4cfe20* FUN_00717e50();
};
struct ChangeCount4cfe20
{
    int _ref_00726070();
};
struct ExtraNode4cfe20
{
    ::ExtraDataList** _ref_006815c0();
    ExtraNode4cfe20* _ref_00726070();
};
struct ChangeNode4cfe20
{
    bool _ref_008256d0();
    ::InventoryStackRecord** _ref_006815c0();
    ChangeNode4cfe20* _ref_00726070();
};
struct ExtraRef4cfe20
{
    ::TESObjectREFR* FUN_0041c8d0();
};

struct FUN_004cfe20_t : public ::InventoryChanges
{
    Container4cfe20* FUN_004bffb0();
    ::InventoryStackRecord* FUN_004bfba0(::TESBoundObject*, int, int);
    bool HasItem(unsigned int aId);
};

// @fnv 0x004cfe20
bool FUN_004cfe20_t::HasItem(unsigned int aId)
{
    ::TESBoundObject* pObj;
    ::InventoryStackRecord* pitem = 0;
    pObj = 0;
    int iProcessIndex = 0;
    ContNode4cfe20* pList = FUN_004bffb0()->FUN_00717e50();
    while (pList && !pList->_ref_008256d0())
    {
        pObj = (*pList->_ref_006815c0())->pObj;
        if (pObj && ((::TESForm*)pObj)->GetFormID() == aId)
        {
            ::InventoryStackRecord* pchange = FUN_004bfba0(pObj, 1, 0);
            if ((*pList->_ref_006815c0())->count < 0)
            {
                return true;
            }
            else
            {
                if (pchange && ((ChangeCount4cfe20*)pchange)->_ref_00726070() + (*pList->_ref_006815c0())->count)
                    iProcessIndex += ((ChangeCount4cfe20*)pchange)->_ref_00726070() + (*pList->_ref_006815c0())->count;
                else
                    iProcessIndex += (*pList->_ref_006815c0())->count;
            }
            if (iProcessIndex > 0)
                return true;
        }
        pList = pList->_ref_00726070();
    }
    ChangeNode4cfe20* pListInv = (ChangeNode4cfe20*)m_pEntryList;
    while (pListInv && !pListInv->_ref_008256d0())
    {
        pitem = *pListInv->_ref_006815c0();
        ExtraNode4cfe20* pkCurrentObject = *(ExtraNode4cfe20**)pitem;
        while (pkCurrentObject && *pkCurrentObject->_ref_006815c0())
        {
            ::ExtraDataList* pextra = *pkCurrentObject->_ref_006815c0();
            if (pextra && ((ExtraRef4cfe20*)pextra)->FUN_0041c8d0() &&
                ((ExtraRef4cfe20*)pextra)->FUN_0041c8d0()->GetFormID() == aId)
                return true;
            pkCurrentObject = pkCurrentObject->_ref_00726070();
        }
        pListInv = pListInv->_ref_00726070();
    }
    return false;
}

struct FUN_00419d10
{
    void SetExtra(void*);
};

struct FUN_004bdd20_Stand
{
    void SetPerkExtra(void* apExtra);
};

// If the perk list's first perk exists and its check returns false, calls SetExtra on that perk with apExtra.
// @fnv 0x004bdd20
void FUN_004bdd20_Stand::SetPerkExtra(void* apExtra)
{
    BSSimpleList<BGSPerk*>* pk = reinterpret_cast<BSSimpleList<BGSPerk*>*>(*reinterpret_cast<void**>(this));
    if (pk && pk->GetItem())
    {
        BGSPerk* item = pk->GetItem();
        if (item)
        {
            if (!reinterpret_cast<FUN_004187d0_Class*>(item)->FUN_004187d0())
                reinterpret_cast<FUN_00419d10*>(item)->SetExtra(apExtra);
        }
    }
}

struct SaveFormIDHelper
{
    void SerializeFormData(void*, int);
};
struct BGSSaveFormBuffer
{
    void SaveData(void*, int, int);
    unsigned int FUN_00865f20();
    void FUN_00865ff0(int, unsigned int);
};
struct FUN_00426a30_shell
{
    void WriteNodeList(BGSSaveFormBuffer*);
};
struct FUN_004bed60_shell
{
    BSSimpleList<BGSPerk*>* list;
    int pad0;
    int pad1;
    void SavePerkList(BGSSaveFormBuffer* buffer);
};

// @fnv 0x004bed60
void FUN_004bed60_shell::SavePerkList(BGSSaveFormBuffer* buffer)
{
    ((SaveFormIDHelper*)buffer)->SerializeFormData((void*)pad1, 0);
    buffer->SaveData((char*)this + 4, 4, 0);
    unsigned int count = 0;
    unsigned int total = buffer->FUN_00865f20();
    BSSimpleList<BGSPerk*>* node = list;
    while (node)
    {
        BGSPerk* perk = node->GetItem();
        if (perk)
        {
            ((FUN_00426a30_shell*)perk)->WriteNodeList(buffer);
            ++count;
        }
        node = node->GetNext();
    }
    buffer->FUN_00865ff0((int)count, total);
}

struct SpawnedEntry
{
    unsigned int unk00;
    unsigned int unk04;
    SpawnedEntry();
};

struct FUN_004bc810_cls
{
    SpawnedEntry* m_afEntries;
    unsigned int unk04;
    unsigned int m_08;
    unsigned int unk0C;
    ContNode* FUN_00559450();
    void FUN_004bc810(FUN_004bc810_cls* src);
};

// @fnv 0x004bc810
void FUN_004bc810_cls::FUN_004bc810(FUN_004bc810_cls* apSource)
{
    if (apSource != 0)
    {
        this->m_08 = apSource->m_08;
        this->m_afEntries = new SpawnedEntry();
        SpawnedEntry* head7;
        ContNode* cur;
        head7 = apSource->m_afEntries;
        cur = apSource->FUN_00559450();
        goto check;
    advance:
        cur = FUN_00726070(cur);
    check:
        if (cur != 0)
        {
            if (*FUN_006815c0(cur) != 0)
            {
                reinterpret_cast<FUN_005ae3d0_S*>(this->FUN_00559450())
                    ->FUN_005ae3d0(reinterpret_cast<ExtraDataList**>(FUN_006815c0(cur)));
                goto advance;
            }
        }
    end:;
    }
}

struct FUN_004bd7a0_stand
{
    ExtraNode* FUN_00559450();
    int FindFirstNonNegativeValue();
};

struct FUN_0042de90_obj
{
    signed char GetExtraByteValue();
};

// Walks a node list, returning the first non-negative value from GetExtraByteValue, or -1 if none is found.
// @fnv 0x004bd7a0
int FUN_004bd7a0_stand::FindFirstNonNegativeValue()
{
    int result = -1;
    for (ExtraNode* cur = FUN_00559450(); result < 0 && cur != 0 && *_ref_006815c0(cur) != 0; cur = _ref_00726070(cur))
    {
        if (((FUN_0042de90_obj*)*_ref_006815c0(cur))->GetExtraByteValue() >= 0)
        {
            result = ((FUN_0042de90_obj*)*_ref_006815c0(cur))->GetExtraByteValue();
        }
    }
    return result;
}

class B4BDF00Form
{
  public:
    int GetFormType();
};

unsigned int __cdecl FUN_004873d0(B4BDF00Form* pkWeapon);

class B4BDF00Data;

float __cdecl FUN_00644ce0(void* pvActor, B4BDF00Form* pkWeapon, float fScale, float fValue, int iUnused, int iFlag,
                           B4BDF00Data* pkData, int iMode);

class B4BDF00Data
{
  public:
    float FUN_004bcdb0(int iIndex);
    float GetScaledValue(void* pvActor, float fValue, bool bFlag);

    int unk00;
    int unk04;
    B4BDF00Form* m_pkForm;
};

// If m_pkForm is form type 0x28, computes a scale from two values and forwards it to FUN_00644ce0; otherwise returns 0.0f.
// @fnv 0x004bdf00
float B4BDF00Data::GetScaledValue(void* pvActor, float fValue, bool bFlag)
{
    if (m_pkForm->GetFormType() == 0x28)
    {
        B4BDF00Form* pkWeapon = m_pkForm;
        float fScale = FUN_004bcdb0(0) / FUN_004873d0(pkWeapon);
        return FUN_00644ce0(pvActor, pkWeapon, fScale, fValue, 0, bFlag, this, 1);
    }
    else
    {
        m_pkForm->GetFormType();
    }
    return 0.0f;
}

extern float DAT_01012054;
extern double DAT_01012060;
struct BookForm
{
    unsigned int FUN_00401170();
    float FUN_004be060();
};
unsigned int __cdecl FUN_004873d0(BookForm*);
float __cdecl FUN_00646360(unsigned short, float);
void __cdecl FUN_00476b20(float);
struct ItemChangeCalc
{
    int unknown00;
    int unknown04;
    BookForm* item;
    float FUN_004bcdb0(int);
    void UpdateItemChange(int unused);
};
// Computes a value from the item's form type and count, then passes the result to FUN_00476b20.
// @fnv 0x004bdf90
void ItemChangeCalc::UpdateItemChange(int unused)
{
    float result = DAT_01012054;
    if (item->FUN_00401170() == 0x18)
    {
        BookForm* current = item;
        float count = (float)FUN_004873d0(current);
        float multiplier = (float)(count == DAT_01012060 ? 0.0 : FUN_004bcdb0(0) / count);
        result = FUN_00646360((unsigned short)current->FUN_004be060(), multiplier);
    }
    FUN_00476b20(result);
}

struct NewExtraList
{
    virtual ~NewExtraList();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    NewExtraList();
};
struct ExtraListFlagger
{
    void SetFlagBits(bool, bool);
};
struct ExtraListDeleter
{
    virtual ~ExtraListDeleter();
};

struct ItemChange_004be3d0 : public InventoryStackRecord
{
    void SetExtraListFlag(bool abNew, bool abFlag, bool abDelete);
};

// Adds a new extra data list with flag bits set, or removes the matching list entry and optionally deletes it.
// @fnv 0x004be3d0
void ItemChange_004be3d0::SetExtraListFlag(bool abNew, bool abFlag, bool abDelete)
{
    if (abNew)
    {
        ExtraDataList* pNewList = (ExtraDataList*)new NewExtraList;
        ((ExtraListFlagger*)pNewList)->SetFlagBits(1, abFlag);
        if (!m_pExtraDataLists)
        {
            m_pExtraDataLists = new BSSimpleList<ExtraDataList*>;
        }
        m_pExtraDataLists->AddHead(pNewList);
    }
    else if (((FUN_004bddd0_shell*)this)->FUN_004bddd0(abFlag))
    {
        BSSimpleList<ExtraDataList*>* pIter = m_pExtraDataLists;
        while (pIter && pIter->GetItem())
        {
            ExtraDataList* pExtra = pIter->GetItem();
            if (pExtra && ((ExtraDataList_shell*)pExtra)->FUN_00418ab0(abFlag))
            {
                pIter->Remove(pExtra);
                if (abDelete)
                {
                    delete (ExtraListDeleter*)pExtra;
                }
                break;
            }
            pIter = pIter->GetNext();
        }
    }
}

struct RefBase_4bf330
{
    TESBoundObject* GetBaseObj_44ddc0();
};

struct Extra_4bf330
{
    char GetSlot_42de90();
    void Clear_42dec0();
    bool IsEmpty();
    short GetCount_418770();
    int GetVal_40fe20();
};

struct ExtraList_4bf330
{
    Extra_4bf330* item;
    ExtraList_4bf330* next;
    ~ExtraList_4bf330();
    Extra_4bf330*& GetItem();
    ExtraList_4bf330* GetNext();
    bool IsEmpty();
    void Remove(Extra_4bf330* const& item);
};

struct Change_4bf330
{
    ExtraList_4bf330* m_pExtraDataLists;
    int m_iCountChange;
    TESBoundObject* m_pItemObject;
    ~Change_4bf330();
    int GetCount_726070();
};

struct ChangeList_4bf330
{
    void Remove(Change_4bf330* const& item);
};

struct Inv_4bf330
{
    ChangeList_4bf330* m_pEntryList;
    TESObjectREFR* pRef;
    float m_fTotalWeight;
    float m_fArmorWeight;
    bool m_bChanged;
    Change_4bf330* FUN_004bfba0(TESBoundObject*, int, int);
    void ClearExtraForSlot(RefBase_4bf330* apRef, int aiSlot);
};

// @fnv 0x004bf330
void Inv_4bf330::ClearExtraForSlot(RefBase_4bf330* apRef, int aiSlot)
{
    Change_4bf330* pChange = FUN_004bfba0(apRef->GetBaseObj_44ddc0(), 1, 0);
    if (pChange)
    {
        ExtraList_4bf330* pNode = pChange->m_pExtraDataLists;
        while (pNode)
        {
            Extra_4bf330* pExtra = pNode->GetItem();
            if (pExtra && ((aiSlot != -1 && pExtra->GetSlot_42de90() == aiSlot) ||
                           (aiSlot == -1 && pExtra->GetSlot_42de90() >= 0)))
            {
                pExtra->Clear_42dec0();
                if (pExtra->IsEmpty() || (pExtra->GetCount_418770() > 1 && pExtra->GetVal_40fe20() == 1))
                {
                    pChange->m_pExtraDataLists->Remove(pExtra);
                    pNode = pChange->m_pExtraDataLists;
                }
                else
                {
                    pNode = pNode->GetNext();
                }
            }
            else
            {
                pNode = pNode->GetNext();
            }
        }
        if (pChange->m_pExtraDataLists && pChange->m_pExtraDataLists->IsEmpty())
        {
            delete pChange->m_pExtraDataLists;
            pChange->m_pExtraDataLists = 0;
            if (!pChange->GetCount_726070())
            {
                m_pEntryList->Remove(pChange);
                delete pChange;
            }
        }
    }
}

extern const char g_inventoryChangesSourceFilename[];

struct InventoryIterator
{
    ~InventoryIterator();
};

struct ExtraListTyped
{
    char GetListType();
};

struct ExtraListNode
{
    ExtraListTyped** GetItem();
    ExtraListNode* GetNext();
};

struct ItemChangeLists : public InventoryStackRecord
{
    ExtraListNode* GetExtraLists();
};

struct InventoryChangesIter : public InventoryChanges
{
    InventoryIterator* CreateIterator();
    InventoryStackRecord* NextItem(InventoryIterator* apIter);
    InventoryStackRecord* FindEntryWithExtraListType(int aiType);
};

// Iterates inventory changes and returns the first entry whose extra list has the given list type, deleting skipped entries.
// @fnv 0x004bf4b0
InventoryStackRecord* InventoryChangesIter::FindEntryWithExtraListType(int aiType)
{
    AutoMemContext memContext2((MEM_CONTEXT)0x36, true, g_inventoryChangesSourceFilename, 0x76a);
    InventoryIterator* pIter6 = CreateIterator();
    InventoryStackRecord* pEntry = 0;
    do
    {
        pEntry = NextItem(pIter6);
        if (pEntry)
        {
            for (ExtraListNode* pNode = static_cast<ItemChangeLists*>(pEntry)->GetExtraLists();
                 pNode && *pNode->GetItem(); pNode = pNode->GetNext())
            {
                char cType = (*pNode->GetItem())->GetListType();
                if (cType == aiType)
                {
                    delete pIter6;
                    return pEntry;
                }
            }
            delete pEntry;
        }
    } while (pEntry);
    delete pIter6;
    return 0;
}

struct TESForm;
struct TESBoundObject;
int __fastcall FNV_GetFormType(TESForm*);

struct ContEntry4c6ba0
{
    int count;
    TESBoundObject* pObj;
};
struct ContNode4c6ba0
{
    ContEntry4c6ba0** FUN_006815c0();
    ContNode4c6ba0* FUN_00726070();
};
struct Container4c6ba0
{
    ContNode4c6ba0* FUN_00717e50();
    bool FUN_00481eb0(TESBoundObject*);
};
struct Change4c6ba0
{
    void* m_pExtraDataLists;
    int m_iCountChange;
    TESBoundObject* m_pItemObject;
    int FUN_00726070();
};
struct ChangeNode4c6ba0
{
    Change4c6ba0** FUN_006815c0();
    ChangeNode4c6ba0* FUN_00726070();
};
struct Inv4c6ba0
{
    ChangeNode4c6ba0* m_pEntryList;
    Container4c6ba0* FUN_004bffb0();
    Change4c6ba0* FUN_004bfba0(TESBoundObject*, int, int);
    TESBoundObject* FindFirstItemOfType(int aType, int* apCount);
};

// @fnv 0x004c6ba0
TESBoundObject* Inv4c6ba0::FindFirstItemOfType(int aType, int* apCount)
{
    ContNode4c6ba0* pNode = FUN_004bffb0()->FUN_00717e50();
    Change4c6ba0* pChange;
    TESBoundObject* pForm = 0;
    ChangeNode4c6ba0* pChangeNode4;

    while (pNode && !pForm && *pNode->FUN_006815c0())
    {
        pForm = (*pNode->FUN_006815c0())->pObj;
        if (pForm && FNV_GetFormType((TESForm*)pForm) == aType)
        {
            pChange = FUN_004bfba0(pForm, 1, 0);
            if (!pChange || (pChange && pChange->FUN_00726070() + (*pNode->FUN_006815c0())->count))
            {
                if (pChange)
                    *apCount = pChange->FUN_00726070() + (*pNode->FUN_006815c0())->count;
                else
                    *apCount = (*pNode->FUN_006815c0())->count;
            }
        }
        else
        {
            pForm = 0;
        }
        pNode = pNode->FUN_00726070();
    }

    pChangeNode4 = m_pEntryList;
    while (pChangeNode4 && !pForm && *pChangeNode4->FUN_006815c0())
    {
        pForm = (*pChangeNode4->FUN_006815c0())->m_pItemObject;
        if (pForm && FNV_GetFormType((TESForm*)pForm) == aType)
        {
            if (!FUN_004bffb0()->FUN_00481eb0(pForm))
            {
                if ((*pChangeNode4->FUN_006815c0())->FUN_00726070() > 0)
                    *apCount = (*pChangeNode4->FUN_006815c0())->FUN_00726070();
            }
        }
        else
        {
            pForm = 0;
        }
        pChangeNode4 = pChangeNode4->FUN_00726070();
    }
    return pForm;
}

extern float g_fResetValue;

class FUN_004c6d40_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    float m_08;
    float m_0c;

    int CallA(int a1, int* pCount);
    void CallB(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12);
    void ResetAndProcess(int a1, unsigned char a2, int a3);
};

// @fnv 0x004c6d40
void FUN_004c6d40_cls::ResetAndProcess(int aiArg, unsigned char a2, int aiCount)
{
    int ptr;
    int cnt;
    m_0c = m_08;
    m_08 = g_fResetValue;
    ptr = 0;
    cnt = 0;
    while (aiCount > 0)
    {
        ptr = CallA(aiArg, &cnt);
        if (cnt > aiCount)
        {
            cnt = aiCount;
        }
        CallB(0, ptr, a2, cnt, 0, 0, 0, 0, 0, 1, 0, 0);
        aiCount -= cnt;
    }
}

struct NiPoint3_ext : NiPoint3
{
    NiPoint3_ext();
    NiPoint3_ext& _ref_0063c8a0(const NiPoint3&);
};
struct NiPoint3b : NiPoint3
{
    NiPoint3b(float, float, float);
};
struct NiMatrix3Helper
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
    void _ref_006815c0();
    void FUN_00a59540(float, float, float);
    NiPoint3 _ref_004b4500(const NiPoint3&);
};
struct PlacedRef : TESObjectREFR
{
    void* _ref_00575d70(int, bool, bool);
    ExtraDataList* _ref_005d43c0();
};
struct PlacedExtra
{
    void _ref_00419ad0(unsigned short);
};
struct DataHandler
{
    PlacedRef* _ref_004698a0(void*, const NiPoint3&, const NiPoint3&, TESObjectCELL*, void*);
};
extern DataHandler* g_dataHandler;
struct Placement
{
    PlacedRef* PlaceObject(PlacedRef*, void*, int, int, NiPoint3*, NiPoint3*);
};
// @fnv 0x004c6dd0
PlacedRef* Placement::PlaceObject(PlacedRef* ref, void* object, int count, int flags, NiPoint3* location,
                                  NiPoint3* rotation)
{
    NiPoint3_ext position;
    if (location)
    {
        position.x = location->x;
        position.y = location->y;
        position.z = location->z;
    }
    else
    {
        static_cast<NiPoint3&>(position) = *ref->GetPos();
        NiPoint3 angle = ref->GetAngleOnReference();
        NiMatrix3Helper matrix2;
        matrix2._ref_006815c0();
        matrix2.FUN_00a59540(angle.x, angle.y, angle.z);
        NiPoint3b offset(0.0f, 50.0f, 30.0f);
        position._ref_0063c8a0(matrix2._ref_004b4500(offset));
    }
    NiPoint3 orient3 = rotation ? *rotation : (ref ? ref->GetAngleOnReference() : NiPoint3::ZERO);
    PlacedRef* result3 = g_dataHandler->_ref_004698a0(object, position, orient3, ref->GetParentCell(),
                                                      ref->_ref_00575d70(flags, false, false));
    if (count > 1)
        reinterpret_cast<PlacedExtra*>(result3->_ref_005d43c0())->_ref_00419ad0((unsigned short)count);
    result3->MarkAsModified(0x400);
    return result3;
}

void* __cdecl operator new(unsigned int);
struct Weapon;
struct Extra;
struct Item;
struct ItemList;
struct BaseNode;
struct ActorStand;
struct Stats
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual float vc(int);
    float FUN_0066ef50(int);
    int FUN_0066ef20(int);
};
struct ProcessStand
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
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
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
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
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
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
    virtual bool v388();
};
struct ActorStand
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
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
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual bool v100();
    int unk4;
    int unk8;
    int unkc;
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
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    Stats stats;
    ProcessStand* FUN_008d8520();
    float GetFatigueRatio();
    bool FUN_008bc9d0(Weapon*, bool);
};
struct Form
{
    int FUN_00401170();
};
struct ValueComp
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual unsigned short v10();
};
struct AmmoComp
{
    virtual void v0();
    virtual void v4();
    virtual float v8(int);
};
struct Ammo
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    AmmoComp damage;
};
struct AmmoLink
{
    int unk00, unk04;
    Ammo* FUN_00726070();
};
struct Weapon : Form
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
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
    AmmoLink ammo;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    ValueComp value;
    int FUN_00522c80();
    int GetUnk15C();
    int FUN_00446390();
};
struct Extra
{
    void* GetExtraData(int);
    float FUN_004186f0();
    bool FUN_00418b10();
};
struct FUN_0096a2d0
{
    Extra* item;
    FUN_0096a2d0* next;
    FUN_0096a2d0();
    Extra*& FUN_006815c0();
    FUN_0096a2d0* FUN_00726070();
    void FUN_005ae3d0(Extra**);
};
struct FUN_004459e0
{
    ~FUN_004459e0();
};
struct FUN_0076b630 : FUN_004459e0
{
    FUN_0096a2d0* extras;
    int count;
    Weapon* weapon;
    FUN_0076b630();
    FUN_0096a2d0* FUN_00559450();
    float FUN_004bd350();
    bool FUN_004bcb70();
    ItemList* FUN_00726070();
    Weapon* FUN_0044ddc0();
    void FUN_006ecd40(int);
};
struct ItemList
{
    FUN_0076b630* item;
    ItemList* next;
    FUN_0076b630*& FUN_006815c0();
    ItemList* FUN_00726070();
    bool FUN_008256d0();
};
struct BaseItem
{
    int count;
    Weapon* form;
};
struct BaseNode
{
    BaseItem* item;
    BaseNode* next;
    BaseItem*& FUN_006815c0();
    BaseNode* FUN_00726070();
};
struct Container
{
    BaseNode* FUN_00717e50();
    bool FUN_00481eb0(Weapon*);
};
struct Target
{
    ItemList* changes;
    ActorStand* owner;
    Container* FUN_004bffb0();
    FUN_0076b630* FUN_004c8c10(int, int);
    FUN_0076b630* FUN_004bfba0(Weapon*, bool, int);
    FUN_0076b630* FindInventoryItem(Weapon*, bool*);
    int FUN_004c8f30(Weapon*);
    FUN_0076b630* SelectBestWeapon(ActorStand*, float*, int, bool);
};
unsigned int __cdecl FUN_004873d0(Weapon*);
float __cdecl ComputeWeaponDamage(ActorStand*, Weapon*, float, int, FUN_0076b630*, FUN_0076b630*);
float __cdecl ScaleByGameSetting(float, int, int);
// Scans the container and inventory changes for a usable weapon matching kind, scores candidates, and returns the best change with its score written to output.
// @fnv 0x004c7400
FUN_0076b630* Target::SelectBestWeapon(ActorStand* subject, float* apfScore, int kind, bool worn)
{
    ActorStand* a;
    {
        float b;
        {
            float c;
            {
                BaseNode* d;
                {
                    ItemList* e;
                    {
                        FUN_0076b630* f;
                        {
                            AutoMemContext g((MEM_CONTEXT)54, true, g_inventoryChangesSourceFilename, 0x1444);
                            {
                                float h;
                                {
                                    int i;
                                    {
                                        float j;
                                        {
                                            Weapon* k;
                                            {
                                                float l;
                                                {
                                                    float m;
                                                    {
                                                        ActorStand* pScoringActor;
                                                        {

                                                            l = 0.0f;
                                                            k = 0;
                                                            f = 0;
                                                            pScoringActor = subject;
                                                            a = 0;
                                                            if (owner && owner->v100())
                                                            {
                                                                a = owner;
                                                                pScoringActor = a;
                                                                if (a->FUN_008d8520() && a->FUN_008d8520()->v388())
                                                                    return f;
                                                            }
                                                            if (worn)
                                                            {
                                                                FUN_0076b630* wornItem = FUN_004c8c10(5, 0);
                                                                if (wornItem && wornItem->FUN_00559450()
                                                                                    ->FUN_006815c0()
                                                                                    ->FUN_00418b10())
                                                                    return wornItem;
                                                                else
                                                                    delete (FUN_004459e0*)wornItem;
                                                            }
                                                            d = FUN_004bffb0()->FUN_00717e50();
                                                            c = 0.0f;
                                                            m = subject->stats.FUN_0066ef50(11);
                                                            b = (float)subject->stats.FUN_0066ef20(5);
                                                            h = 0.0f;
                                                            if (a)
                                                                h = a->GetFatigueRatio();
                                                            else
                                                                h = 1.0f;
                                                            i = 1;
                                                            j = 1.0f;
                                                            while (d)
                                                            {
                                                                BaseItem* entry;
                                                                {
                                                                    Weapon* weapon;
                                                                    {
                                                                        FUN_0076b630* change;
                                                                        {
                                                                            bool found;
                                                                            {
                                                                                float score;
                                                                                {
                                                                                    FUN_0076b630* ammoItem;
                                                                                    {
                                                                                        bool usable;
                                                                                        {
                                                                                            ActorStand* ownerActor;
                                                                                            {
                                                                                                AmmoLink* pAmmoLink;
                                                                                                {
                                                                                                    Ammo* ammo;
                                                                                                    {
                                                                                                        FUN_0096a2d0*
                                                                                                            extraNode;
                                                                                                        {
                                                                                                            Extra*
                                                                                                                extra;
                                                                                                            {
                                                                                                                void*
                                                                                                                    health;
                                                                                                                {
                                                                                                                    float
                                                                                                                        itemHealth;
                                                                                                                    {
                                                                                                                        entry =
                                                                                                                            d->FUN_006815c0();
                                                                                                                        weapon =
                                                                                                                            0;
                                                                                                                        if (entry &&
                                                                                                                            entry->form
                                                                                                                                    ->FUN_00401170() ==
                                                                                                                                40)
                                                                                                                            weapon =
                                                                                                                                entry
                                                                                                                                    ->form;
                                                                                                                        if (weapon)
                                                                                                                        {
                                                                                                                            change = FUN_004bfba0(
                                                                                                                                weapon,
                                                                                                                                true,
                                                                                                                                0);
                                                                                                                            if ((!change ||
                                                                                                                                 (change &&
                                                                                                                                  change->count +
                                                                                                                                          d->FUN_006815c0()
                                                                                                                                              ->count >
                                                                                                                                      0) ||
                                                                                                                                 d->FUN_006815c0()
                                                                                                                                         ->count <
                                                                                                                                     0) &&
                                                                                                                                weapon &&
                                                                                                                                (kind ==
                                                                                                                                     6 ||
                                                                                                                                 kind ==
                                                                                                                                     weapon
                                                                                                                                         ->FUN_00522c80()))
                                                                                                                            {
                                                                                                                                score =
                                                                                                                                    -1.0f;
                                                                                                                                usable =
                                                                                                                                    true;
                                                                                                                                found =
                                                                                                                                    false;
                                                                                                                                ownerActor =
                                                                                                                                    owner->v100()
                                                                                                                                        ? owner
                                                                                                                                        : 0;
                                                                                                                                ammoItem = FindInventoryItem(
                                                                                                                                    weapon,
                                                                                                                                    &found);
                                                                                                                                if (found &&
                                                                                                                                    !ammoItem)
                                                                                                                                    usable =
                                                                                                                                        false;
                                                                                                                                if (a &&
                                                                                                                                    (!a->FUN_008bc9d0(
                                                                                                                                         weapon,
                                                                                                                                         true) ||
                                                                                                                                     !usable))
                                                                                                                                {
                                                                                                                                    score =
                                                                                                                                        -1000.0f;
                                                                                                                                }
                                                                                                                                else
                                                                                                                                {
                                                                                                                                    i = weapon
                                                                                                                                            ->value
                                                                                                                                            .v10();
                                                                                                                                    pAmmoLink =
                                                                                                                                        weapon
                                                                                                                                            ? &weapon
                                                                                                                                                   ->ammo
                                                                                                                                            : 0;
                                                                                                                                    ammo =
                                                                                                                                        pAmmoLink
                                                                                                                                            ? pAmmoLink
                                                                                                                                                  ->FUN_00726070()
                                                                                                                                            : 0;
                                                                                                                                    c = subject
                                                                                                                                            ->stats
                                                                                                                                            .vc(weapon
                                                                                                                                                    ->GetUnk15C());
                                                                                                                                    if (change &&
                                                                                                                                        change
                                                                                                                                            ->extras &&
                                                                                                                                        change
                                                                                                                                            ->extras
                                                                                                                                            ->FUN_006815c0())
                                                                                                                                    {
                                                                                                                                        if (ammo &&
                                                                                                                                            change->FUN_004bd350() <
                                                                                                                                                ammo->damage
                                                                                                                                                    .v8(0))
                                                                                                                                            ammo =
                                                                                                                                                0;
                                                                                                                                        extraNode =
                                                                                                                                            change
                                                                                                                                                ->extras;
                                                                                                                                        while (
                                                                                                                                            extraNode)
                                                                                                                                        {
                                                                                                                                            extra =
                                                                                                                                                extraNode
                                                                                                                                                    ->FUN_006815c0();
                                                                                                                                            if (extra)
                                                                                                                                            {
                                                                                                                                                health =
                                                                                                                                                    extra
                                                                                                                                                        ->GetExtraData(
                                                                                                                                                            37);
                                                                                                                                                itemHealth =
                                                                                                                                                    0.0f;
                                                                                                                                                if (health)
                                                                                                                                                    itemHealth =
                                                                                                                                                        extra
                                                                                                                                                            ->FUN_004186f0();
                                                                                                                                                else
                                                                                                                                                    itemHealth =
                                                                                                                                                        (float)FUN_004873d0(
                                                                                                                                                            weapon);
                                                                                                                                                if (itemHealth >
                                                                                                                                                    0.0)
                                                                                                                                                {
                                                                                                                                                    j = itemHealth /
                                                                                                                                                        FUN_004873d0(
                                                                                                                                                            weapon);
                                                                                                                                                    score = ComputeWeaponDamage(
                                                                                                                                                        pScoringActor,
                                                                                                                                                        weapon,
                                                                                                                                                        j,
                                                                                                                                                        0,
                                                                                                                                                        change,
                                                                                                                                                        ammoItem);
                                                                                                                                                    if (score >
                                                                                                                                                        l)
                                                                                                                                                    {
                                                                                                                                                        l = score;
                                                                                                                                                        k = weapon;
                                                                                                                                                        delete (
                                                                                                                                                            FUN_004459e0*)
                                                                                                                                                            f;
                                                                                                                                                        f = new FUN_0076b630;
                                                                                                                                                        f->weapon =
                                                                                                                                                            weapon;
                                                                                                                                                        f->extras =
                                                                                                                                                            new FUN_0096a2d0;
                                                                                                                                                        f->extras
                                                                                                                                                            ->FUN_005ae3d0(
                                                                                                                                                                &extra);
                                                                                                                                                    }
                                                                                                                                                }
                                                                                                                                            }
                                                                                                                                            extraNode =
                                                                                                                                                extraNode
                                                                                                                                                    ->FUN_00726070();
                                                                                                                                        }
                                                                                                                                    }
                                                                                                                                    else
                                                                                                                                    {
                                                                                                                                        score = ComputeWeaponDamage(
                                                                                                                                            pScoringActor,
                                                                                                                                            weapon,
                                                                                                                                            j,
                                                                                                                                            0,
                                                                                                                                            change,
                                                                                                                                            ammoItem);
                                                                                                                                        if (score >
                                                                                                                                            l)
                                                                                                                                        {
                                                                                                                                            l = score;
                                                                                                                                            k = weapon;
                                                                                                                                            delete (
                                                                                                                                                FUN_004459e0*)
                                                                                                                                                f;
                                                                                                                                            f = new FUN_0076b630;
                                                                                                                                            f->weapon =
                                                                                                                                                weapon;
                                                                                                                                        }
                                                                                                                                    }
                                                                                                                                }
                                                                                                                            }
                                                                                                                        }
                                                                                                                    }
                                                                                                                }
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                                d = d->FUN_00726070();
                                                            }
                                                            e = changes;
                                                            while (e && !e->FUN_008256d0())
                                                            {
                                                                FUN_0076b630* change;
                                                                {
                                                                    Weapon* weapon;
                                                                    {
                                                                        bool found;
                                                                        {
                                                                            FUN_0076b630* ammoItem;
                                                                            {
                                                                                bool usable;
                                                                                {
                                                                                    ActorStand* ownerActor;
                                                                                    {
                                                                                        float score;
                                                                                        {
                                                                                            FUN_0096a2d0* extraNode;
                                                                                            {
                                                                                                void* health;
                                                                                                {
                                                                                                    Extra* extra;
                                                                                                    {
                                                                                                        float
                                                                                                            itemHealth;
                                                                                                        {
                                                                                                            AmmoLink*
                                                                                                                pAmmoLink;
                                                                                                            {
                                                                                                                Ammo*
                                                                                                                    ammo;
                                                                                                                {
                                                                                                                    weapon =
                                                                                                                        0;
                                                                                                                    change =
                                                                                                                        e->FUN_006815c0();
                                                                                                                    if (change
                                                                                                                            ->weapon
                                                                                                                            ->FUN_00401170() ==
                                                                                                                        40)
                                                                                                                        weapon =
                                                                                                                            change
                                                                                                                                ->weapon;
                                                                                                                    if (weapon)
                                                                                                                    {
                                                                                                                        usable =
                                                                                                                            true;
                                                                                                                        found =
                                                                                                                            false;
                                                                                                                        ownerActor =
                                                                                                                            owner->v100()
                                                                                                                                ? owner
                                                                                                                                : 0;
                                                                                                                        ammoItem = FindInventoryItem(
                                                                                                                            weapon,
                                                                                                                            &found);
                                                                                                                        if (found &&
                                                                                                                            !ammoItem)
                                                                                                                            usable =
                                                                                                                                false;
                                                                                                                        if ((kind ==
                                                                                                                                 6 ||
                                                                                                                             kind ==
                                                                                                                                 weapon
                                                                                                                                     ->FUN_00522c80()) &&
                                                                                                                            change
                                                                                                                                ->FUN_00726070() &&
                                                                                                                            !FUN_004bffb0()
                                                                                                                                 ->FUN_00481eb0(
                                                                                                                                     weapon) &&
                                                                                                                            a->FUN_008bc9d0(
                                                                                                                                weapon,
                                                                                                                                true) &&
                                                                                                                            (!change
                                                                                                                                  ->FUN_004bcb70() ||
                                                                                                                             change->count >=
                                                                                                                                 0) &&
                                                                                                                            usable)
                                                                                                                        {
                                                                                                                            score =
                                                                                                                                -1.0f;
                                                                                                                            if (score >=
                                                                                                                                -1.0)
                                                                                                                            {
                                                                                                                                c = subject
                                                                                                                                        ->stats
                                                                                                                                        .vc(weapon
                                                                                                                                                ->GetUnk15C());
                                                                                                                                i = weapon
                                                                                                                                        ->value
                                                                                                                                        .v10();
                                                                                                                                if (change &&
                                                                                                                                    change
                                                                                                                                        ->extras &&
                                                                                                                                    change
                                                                                                                                        ->extras
                                                                                                                                        ->FUN_006815c0())
                                                                                                                                {
                                                                                                                                    extraNode =
                                                                                                                                        change
                                                                                                                                            ->extras;
                                                                                                                                    while (
                                                                                                                                        extraNode &&
                                                                                                                                        extraNode
                                                                                                                                            ->FUN_006815c0())
                                                                                                                                    {
                                                                                                                                        extra =
                                                                                                                                            extraNode
                                                                                                                                                ->FUN_006815c0();
                                                                                                                                        health =
                                                                                                                                            extra
                                                                                                                                                ->GetExtraData(
                                                                                                                                                    37);
                                                                                                                                        itemHealth =
                                                                                                                                            0.0f;
                                                                                                                                        if (health)
                                                                                                                                            itemHealth =
                                                                                                                                                extra
                                                                                                                                                    ->FUN_004186f0();
                                                                                                                                        else
                                                                                                                                            itemHealth =
                                                                                                                                                (float)FUN_004873d0(
                                                                                                                                                    weapon);
                                                                                                                                        if (itemHealth >
                                                                                                                                            0.0)
                                                                                                                                        {
                                                                                                                                            pAmmoLink =
                                                                                                                                                weapon
                                                                                                                                                    ? &weapon
                                                                                                                                                           ->ammo
                                                                                                                                                    : 0;
                                                                                                                                            ammo =
                                                                                                                                                pAmmoLink
                                                                                                                                                    ? pAmmoLink
                                                                                                                                                          ->FUN_00726070()
                                                                                                                                                    : 0;
                                                                                                                                            j = itemHealth /
                                                                                                                                                FUN_004873d0(
                                                                                                                                                    weapon);
                                                                                                                                            score = ComputeWeaponDamage(
                                                                                                                                                pScoringActor,
                                                                                                                                                weapon,
                                                                                                                                                j,
                                                                                                                                                0,
                                                                                                                                                change,
                                                                                                                                                ammoItem);
                                                                                                                                            if (score >
                                                                                                                                                l)
                                                                                                                                            {
                                                                                                                                                l = score;
                                                                                                                                                k = weapon;
                                                                                                                                                delete (
                                                                                                                                                    FUN_004459e0*)
                                                                                                                                                    f;
                                                                                                                                                f = new FUN_0076b630;
                                                                                                                                                f->weapon =
                                                                                                                                                    weapon;
                                                                                                                                                f->extras =
                                                                                                                                                    new FUN_0096a2d0;
                                                                                                                                                f->extras
                                                                                                                                                    ->FUN_005ae3d0(
                                                                                                                                                        &extra);
                                                                                                                                            }
                                                                                                                                        }
                                                                                                                                        extraNode =
                                                                                                                                            extraNode
                                                                                                                                                ->FUN_00726070();
                                                                                                                                    }
                                                                                                                                }
                                                                                                                                else
                                                                                                                                {
                                                                                                                                    score = ComputeWeaponDamage(
                                                                                                                                        pScoringActor,
                                                                                                                                        weapon,
                                                                                                                                        j,
                                                                                                                                        0,
                                                                                                                                        change,
                                                                                                                                        ammoItem);
                                                                                                                                    if (score >
                                                                                                                                        l)
                                                                                                                                    {
                                                                                                                                        l = score;
                                                                                                                                        k = weapon;
                                                                                                                                        delete (
                                                                                                                                            FUN_004459e0*)
                                                                                                                                            f;
                                                                                                                                        f = new FUN_0076b630;
                                                                                                                                        f->weapon =
                                                                                                                                            weapon;
                                                                                                                                    }
                                                                                                                                }
                                                                                                                            }
                                                                                                                        }
                                                                                                                    }
                                                                                                                }
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                                e = e->FUN_00726070();
                                                            }
                                                            *apfScore = ScaleByGameSetting(l, 0, 0);
                                                            if (f)
                                                            {
                                                                Weapon* weapon = f->FUN_0044ddc0();
                                                                if (weapon->FUN_00446390() == 10 ||
                                                                    weapon->FUN_00446390() == 11 ||
                                                                    weapon->FUN_00446390() == 13)
                                                                    f->FUN_006ecd40(FUN_004c8f30(f->FUN_0044ddc0()));
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            return f;
                        }
                    }
                }
            }
        }
    }
}

void* __cdecl operator new(unsigned int);
struct ContainerView
{
    unsigned int CopyUniqueObjects();
};
struct Product
{
    unsigned int unk00, unk04, unk08, unk0c;
    ContainerView* container;
    unsigned int unk14, unk18, unk1c, unk20, unk24;
    Product();
};
extern const char DAT_01020778[];
struct OwnerProduct
{
    ContainerView* FUN_004bffb0();
    Product* FUN_004ca200();
};
// @fnv 0x004ca200
Product* OwnerProduct::FUN_004ca200()
{
    AutoMemContext result((MEM_CONTEXT)0x36, true, DAT_01020778, 0x19b2);
    Product* context = new Product;
    context->unk00 = 0;
    context->unk04 = 0;
    if (FUN_004bffb0())
        context->unk00 = FUN_004bffb0()->CopyUniqueObjects();
    context->unk08 = 0;
    context->unk0c = 0;
    context->container = FUN_004bffb0();
    context->unk04 = context->unk00;
    context->unk18 = 0;
    context->unk1c = 0;
    context->unk24 = 0;
    context->unk20 = 0;
    return context;
}

namespace fnv_004cba70 {
struct ContainerEntry
{
    int count;
    TESBoundObject* object;
};
struct ContainerNode
{
    bool _ref_008256d0();
    ContainerEntry** _ref_006815c0();
    ContainerNode* _ref_00726070();
};
struct Container
{
    ContainerNode* FUN_00717e50();
};
struct Extra
{
    int FUN_0041d360();
};
struct ExtraNode
{
    Extra** _ref_006815c0();
    ExtraNode* _ref_00726070();
};
struct Change
{
    ExtraNode* extras;
    int FUN_0044ddc0();
};
struct ChangeNode
{
    bool _ref_008256d0();
    Change** _ref_006815c0();
    ChangeNode* _ref_00726070();
};
struct Changes
{
    ChangeNode* list;
    Container* FUN_004bffb0();
    int FUN_004cba70(TESLevItem* object);
};
// @fnv 0x004cba70
int Changes::FUN_004cba70(TESLevItem* pLeveledItem)
{
    int result = 0;
    if (pLeveledItem)
    {
        ContainerNode* node = FUN_004bffb0()->FUN_00717e50();
        int index = 0;
        while (node && !node->_ref_008256d0())
        {
            TESLevItem* leveled = dynamic_cast<TESLevItem*>((*node->_ref_006815c0())->object);
            if (leveled && leveled == pLeveledItem)
            {
                break;
            }
            else if (leveled)
            {
                index++;
            }
            node = node->_ref_00726070();
        }
        ChangeNode* changeNode = list;
        while (changeNode && !changeNode->_ref_008256d0() && *changeNode->_ref_006815c0())
        {
            Change* change = *changeNode->_ref_006815c0();
            if (change)
            {
                ExtraNode* extraNode = change->extras;
                while (extraNode && *extraNode->_ref_006815c0())
                {
                    Extra* extra = *extraNode->_ref_006815c0();
                    if (extra && extra->FUN_0041d360() == index)
                    {
                        result = change->FUN_0044ddc0();
                        break;
                    }
                    extraNode = extraNode->_ref_00726070();
                }
            }
            changeNode = changeNode->_ref_00726070();
        }
    }
    return result;
}
}  // namespace fnv_004cba70

extern const double DAT_01020758;
extern char* DAT_011dea3c;
extern char DAT_01183128[];
extern char DAT_01183a34[];

bool __fastcall FUN_004d1360(char*);
float __cdecl FUN_0048ebc0(void*, bool);
void __cdecl FUN_005e58f0(int, char*, float*);
int __cdecl FUN_00ec43fb(void*, int, const char*, const char*, int);

struct ObjectForm
{
    int FUN_00401170();
    float FUN_004be380(unsigned char);
};
struct InventoryEntry
{
    void* m_pExtraDataLists;
    int m_iCountChange;
    ObjectForm* m_pItemObject;
    bool FUN_004bddd0(bool);
    unsigned char HasEffect(int);
    int FUN_0044ddc0();
};
struct InventoryNode
{
    InventoryEntry** FUN_006815c0();
    InventoryNode* FUN_00726070();
    bool FUN_008256d0();
};
struct ActorProcessView
{
    BaseProcess* FUN_008d8520();
};
struct InventoryListView
{
    InventoryNode* first;
    int FUN_004c8f30(int);
    float GetInventoryWeight(ActorProcessView*);
};

// Sums count times weight for each inventory node's entry, using form type 0x28/0x18 special cases and the actor's equipped ammo, skipping type 0x29.
// @fnv 0x004d1180
float InventoryListView::GetInventoryWeight(ActorProcessView* actor)
{
    float total = 0.0f;
    float weightModifier = 0.0f;
    InventoryNode* node = first;
    while (node && !node->FUN_008256d0() && *node->FUN_006815c0())
    {
        InventoryEntry* item = *node->FUN_006815c0();
        ObjectForm* form = item->m_pItemObject;
        if (item->FUN_004bddd0(false) && form->FUN_00401170() != 0x29)
        {
            if (form->FUN_00401170() == 0x28)
            {
                weightModifier = form->FUN_004be380(item->HasEffect(4));
                if (weightModifier >= DAT_01020758)
                {
                    float factor = 1.0f;
                    FUN_005e58f0(0x49, DAT_011dea3c, &factor);
                    weightModifier *= factor;
                }
            }
            else
            {
                weightModifier = FUN_0048ebc0(form, FUN_004d1360(DAT_011dea3c));
            }
            int count = FUN_004c8f30(item->FUN_0044ddc0());
            if (form->FUN_00401170() == 0x18)
            {
                int evaluated = FUN_00ec43fb(form, 0, DAT_01183128, DAT_01183a34, 0);
            }
            else if (form->FUN_00401170() == 0x28)
            {
                BaseProcess* process = actor->FUN_008d8520();
                if (process)
                {
                    InventoryStackRecord* weapon = process->GetActiveWeapon();
                    InventoryStackRecord* pSecondAmmo = process->GetCurrentAmmo();
                    if (weapon && pSecondAmmo &&
                        reinterpret_cast<InventoryEntry*>(weapon)->FUN_0044ddc0() ==
                            reinterpret_cast<InventoryEntry*>(pSecondAmmo)->FUN_0044ddc0())
                    {
                        count = 1;
                    }
                }
            }
            total += static_cast<float>(count) * weightModifier;
        }
        node = node->FUN_00726070();
    }
    return total;
}

namespace fnv_004d42f0 {
struct FUN_008c71b0
{
    int bits;
    FUN_008c71b0(int value);
};
struct InventoryStream
{
    virtual void v0();
    virtual int getInitialSetting();
    void FUN_00428110(int*);
    void FUN_0042ce30(int*);
    void FUN_007037c0(int);
    void SetValue(FUN_008c71b0);
    void FUN_0086cf00(FUN_008c71b0);
};
struct InventoryItem
{
    void FUN_004bef60(InventoryStream*);
};
struct InventoryNode
{
    InventoryItem** FUN_006815c0();
    InventoryNode* FUN_00726070();
};
struct InventoryItemManager
{
    InventoryNode* entries;
    void __thiscall FUN_004d42f0(InventoryStream*);
};
// @fnv 0x004d42f0
void __thiscall InventoryItemManager::FUN_004d42f0(InventoryStream* stream)
{
    int savedInitial = stream->getInitialSetting();
    int savedFlags;
    {
        int savedExtra;
        stream->FUN_00428110(&savedFlags);
        stream->FUN_0042ce30(&savedExtra);
        stream->FUN_007037c0(0);
        stream->SetValue(0x400);
        stream->FUN_0086cf00(0);
        InventoryNode* node = entries;
        while (node)
        {
            InventoryItem* item = *node->FUN_006815c0();
            if (item)
                item->FUN_004bef60(stream);
            node = node->FUN_00726070();
        }
        stream->FUN_007037c0(savedInitial);
        stream->SetValue(*reinterpret_cast<FUN_008c71b0*>(&savedFlags));
        stream->FUN_0086cf00(*reinterpret_cast<FUN_008c71b0*>(&savedExtra));
    }
}
}  // namespace fnv_004d42f0

struct FUN_004d43c0_cls
{
    ContNode* m_pFirstNode;
    int FindItemIndex(int a1, InventoryItemEntry* a2);
};

int __fastcall FUN_0044ddc0(InventoryItemEntry* item);
ContNode* __fastcall FUN_00559450(InventoryItemEntry* item);

// Searches the list for an item whose FUN_0044ddc0 value equals a1, then returns the position of a2 in that item's sublist, or -1.
// @fnv 0x004d43c0
int FUN_004d43c0_cls::FindItemIndex(int a1, InventoryItemEntry* pTargetItem)
{
    if (a1 == 0 || pTargetItem == 0)
    {
        return -1;
    }
    ContNode* node7 = m_pFirstNode;
    while (node7 != 0)
    {
        InventoryItemEntry* itemTmp = *FUN_006815c0(node7);
        node7 = FUN_00726070(node7);
        if (itemTmp != 0 && FUN_0044ddc0(itemTmp) == a1)
        {
            ContNode* inner6;
            int count2 = 0;
            inner6 = FUN_00559450(itemTmp);
            while (inner6 != 0)
            {
                InventoryItemEntry* cur = *FUN_006815c0(inner6);
                if (cur != 0 && cur == pTargetItem)
                {
                    return count2;
                }
                count2 = count2 + 1;
                inner6 = FUN_00726070(inner6);
            }
            break;
        }
    }
    return -1;
}

struct ItemExtraNode;
struct ChangeEntry
{
    int FUN_0044ddc0();
    ItemExtraNode* FUN_00559450();
};
struct ItemChangeNode
{
    ChangeEntry** _ref_006815c0();
    ItemChangeNode* _ref_00726070();
};
struct ItemExtraNode
{
    int* _ref_006815c0();
    ItemExtraNode* _ref_00726070();
};
struct ItemChangeList
{
    ItemChangeNode* first;
    int GetExtraValueAtPosition(int form, int position);
};
// Walks the change list for the entry matching form, then returns the extra value at position, or 0 if not found.
// @fnv 0x004d4480
int ItemChangeList::GetExtraValueAtPosition(int form, int position)
{
    if (form == 0 || position == -1)
        return 0;
    ItemChangeNode* node = first;
    while (node != 0)
    {
        ChangeEntry* entry = *node->_ref_006815c0();
        node = node->_ref_00726070();
        if (entry != 0 && entry->FUN_0044ddc0() == form)
        {
            int index = 0;
            ItemExtraNode* extra = entry->FUN_00559450();
            while (extra != 0)
            {
                int result = *extra->_ref_006815c0();
                if (index == position)
                    return result;
                ++index;
                extra = extra->_ref_00726070();
            }
            break;
        }
    }
    return 0;
}

struct Entry_004d4b00
{
    ~Entry_004d4b00();
    int FUN_0044ddc0();
};
struct Iterator_004d4b00
{
    ~Iterator_004d4b00();
};
struct Output_004d4b00
{
    void FUN_005ae3d0(Entry_004d4b00**);
};
struct Host_004d4b00
{
    Iterator_004d4b00* FUN_004ca200();
    Entry_004d4b00* GetNextInventoryEntry(Iterator_004d4b00*);
    void FindEntriesByType(int type, Output_004d4b00* output);
};
// @fnv 0x004d4b00
void Host_004d4b00::FindEntriesByType(int type, Output_004d4b00* output)
{
    if (type == 0 || output == 0)
        return;
    Iterator_004d4b00* iterator = FUN_004ca200();
    Entry_004d4b00* entry = 0;
    bool found5 = false;
    do
    {
        entry = GetNextInventoryEntry(iterator);
        if (entry != 0)
        {
            if (entry->FUN_0044ddc0() == type)
            {
                found5 = true;
                output->FUN_005ae3d0(&entry);
            }
            else
            {
                delete entry;
                if (found5)
                    break;
            }
        }
    } while (entry != 0);
    delete iterator;
}

namespace fnv_004d4bd0 {
struct ChangeItem
{
    void* FUN_0044ddc0();
    ~ChangeItem();
};
struct InventoryIterator
{
    ~InventoryIterator();
};
struct MatchedChanges
{
    void FUN_005ae3d0(ChangeItem** item);
};
bool __cdecl IsItemEquivalent(void* itemForm, void* requestedForm);
struct InventoryChangeFilterHost
{
    InventoryIterator* FUN_004ca200();
    ChangeItem* GetNextInventoryEntry(InventoryIterator* iterator);
    void FilterInventoryChanges(void* requestedForm, MatchedChanges* matchedChanges);
};
// Iterates inventory changes, keeps those matching requestedForm in matchedChanges, deletes the rest, then deletes the iterator.
// @fnv 0x004d4bd0
void InventoryChangeFilterHost::FilterInventoryChanges(void* requestedForm, MatchedChanges* matchedChanges)
{
    if (!requestedForm || !matchedChanges)
        return;

    InventoryIterator* iterator = FUN_004ca200();
    ChangeItem* itemChange = 0;
    do
    {
        itemChange = GetNextInventoryEntry(iterator);
        if (itemChange)
        {
            if (IsItemEquivalent(itemChange->FUN_0044ddc0(), requestedForm))
                matchedChanges->FUN_005ae3d0(&itemChange);
            else
                delete itemChange;
        }
    } while (itemChange);
    delete iterator;
}
}  // namespace fnv_004d4bd0

struct Record90
{
    unsigned int id;
    unsigned char type;
    unsigned char flags0, flags1, flags2, flags3;
    unsigned char version;
};
struct Load90
{
    bool FUN_00862110();
    void FUN_008579e0(void*, unsigned int);
    Record90* FUN_004fd3c0();
    unsigned int FUN_00825c00();
    unsigned char FUN_008df040();
    void FUN_00857bd0(unsigned int);
};
extern Load90* g_TESSaveLoadGame;
TESForm* FUN_004839c0(unsigned int);
void FNV_Warning(const char*, ...);
unsigned short FUN_004efaa0();
struct Seq90
{
    void FUN_004efbc0(float);
    float FUN_00508100();
};
struct Idle90
{
    unsigned int FUN_0044ddc0();
};
struct Ptr90
{
    Idle90* p;
    void FUN_0066b0d0(Idle90*);
    operator Idle90*() const;
};
struct Found90
{
    void FUN_0081c470(bool, float);
    void FUN_00621b20(float);
};
struct Caster90
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
    virtual int v13();
    Found90* FUN_00726070();
};
struct Actor90 : MobileObject
{
    Caster90 caster;
};
struct Obj90
{
    virtual void v0();
    void* GetControllers() const;
};
struct Node90
{
    Obj90* FUN_0045bc00(unsigned int);
};
struct Named90
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Node90* v3();
};
struct Manager90
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
    virtual Named90* v35(void*);
    Manager90* GetStringAtOffset();
    Seq90* FUN_0047a520(void*);
    void FUN_0048fef0(float);
    void FUN_0047aab0(Seq90*, int, int, float, float, int);
    void FUN_0047aa40(bool);
};
void* FUN_00499b70();
void* FUN_00499b80();
extern int DAT_011f36ac;
Manager90* FUN_00653270(const int*, void*);
struct Animation90 : Animation
{
    void LoadFromSave(TESObjectREFR*);
    void FUN_004974a0();
    void FUN_004955c0(int, unsigned short, int, float, char);
    void FUN_00496080(int, float);
    void FUN_0049bca0(float, void*, bool);
    Manager90* FUN_00496940();
};
Idle90* LoadIdleAnimation(Actor90*, Animation90*, float);
// @fnv 0x0049a1c0
void Animation90::LoadFromSave(TESObjectREFR* ref)
{
    char i;
    bool k;
    char j;
    {
        unsigned short size = 0;
        unsigned int start = 0;
        if (g_TESSaveLoadGame->FUN_00862110())
        {
            unsigned int uiBlockHeader;
            g_TESSaveLoadGame->FUN_008579e0(&uiBlockHeader, 4);
            if (uiBlockHeader != 0x424c4f4b)
            {
                Record90* record = g_TESSaveLoadGame->FUN_004fd3c0();
                if (record)
                {
                    TESForm* form = FUN_004839c0(record->id);
                    FNV_Warning(
                        "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Animation.cpp", 0x1630, record->id,
                        form->GetName(), record->version, *(unsigned int*)&record->flags0);
                }
                else
                    FNV_Warning(
                        "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Current version is %i",
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Animation.cpp", 0x1630,
                        g_TESSaveLoadGame->FUN_008df040());
            }
            start = g_TESSaveLoadGame->FUN_00825c00();
            g_TESSaveLoadGame->FUN_008579e0(&size, 2);
        }
        Actor90* actor = 0;
        if (ref && ref->IsActor())
            actor = (Actor90*)ref;
        g_TESSaveLoadGame->FUN_008579e0(&m_fMovementRate, 4);
        g_TESSaveLoadGame->FUN_008579e0(&m_fCombatAnimationRate, 4);
        g_TESSaveLoadGame->FUN_008579e0(m_kNodeTranslation, 12);
        g_TESSaveLoadGame->FUN_008579e0(&m_fAnimationAmount, 4);
        g_TESSaveLoadGame->FUN_008579e0(&m_cState, 1);
        g_TESSaveLoadGame->FUN_008579e0(&j, 1);
        for (i = 0; i < 8; i++)
            if (j & (1 << i))
            {
                g_TESSaveLoadGame->FUN_008579e0(&((unsigned short*)group)[i], 2);
                g_TESSaveLoadGame->FUN_008579e0(&((int*)action)[i], 4);
                g_TESSaveLoadGame->FUN_008579e0(&((int*)m_acTargetName)[i], 4);
                g_TESSaveLoadGame->FUN_008579e0(&((unsigned short*)usReloadGroup)[i], 2);
                g_TESSaveLoadGame->FUN_008579e0(&((int*)m_acAnimationName)[i], 4);
                char state;
                g_TESSaveLoadGame->FUN_008579e0(&state, 1);
                ((Seq90**)m_pChildTile)[i] = 0;
                if (state != -2)
                {
                    FUN_004974a0();
                    FUN_004955c0(i, ((unsigned short*)group)[i], ((int*)action)[i], time, state);
                    if (((Seq90**)m_pChildTile)[i])
                        ((Seq90**)m_pChildTile)[i]->FUN_004efbc0(time);
                    else
                    {
                        g_TESSaveLoadGame->FUN_00857bd0(FUN_004efaa0());
                        FUN_00496080(i, 0.0f);
                    }
                }
            }
        ((Ptr90*)LocalInput)->FUN_0066b0d0(LoadIdleAnimation(actor, this, time));
        if (g_TESSaveLoadGame->FUN_008df040() < 76)
            ((Ptr90*)LocalStateValue)->FUN_0066b0d0(LoadIdleAnimation(actor, this, time));
        if ((Idle90*)*(Ptr90*)LocalInput && ((Idle90*)*(Ptr90*)LocalInput)->FUN_0044ddc0() == 1)
            ((Seq90**)m_pChildTile)[7] = 0;
        g_TESSaveLoadGame->FUN_008579e0(&m_cSkipNextBlend, 1);
        k = true;
        if (g_TESSaveLoadGame->FUN_008df040() >= 64)
            g_TESSaveLoadGame->FUN_008579e0(&k, 1);
        if (k)
        {
            bool restored = false;
            if (actor->caster.v13())
            {
                Named90* named = FUN_00496940()->GetStringAtOffset()->v35(FUN_00499b70());
                if (named)
                {
                    Node90* node = named->v3();
                    if (node)
                    {
                        Obj90* object = node->FUN_0045bc00(0);
                        if (object)
                        {
                            void* aControllers = object->GetControllers();
                            {
                                Manager90* manager = FUN_00653270(&DAT_011f36ac, aControllers);
                                if (manager)
                                {
                                    Seq90* sequence = manager->FUN_0047a520(FUN_00499b80());
                                    if (sequence)
                                    {
                                        manager->FUN_0048fef0(0.0f);
                                        manager->FUN_0047aab0(sequence, 0, 0, 1.0f, 0.0f, 0);
                                        manager->FUN_0047aa40(true);
                                        sequence->FUN_004efbc0(time);
                                        float aSavedTime;
                                        g_TESSaveLoadGame->FUN_008579e0(&aSavedTime, 4);
                                        {
                                            Found90* found = actor->caster.FUN_00726070();
                                            if (found)
                                            {
                                                found->FUN_0081c470(true, sequence->FUN_00508100() * 0.75);
                                                found->FUN_00621b20(aSavedTime);
                                            }
                                        }
                                        restored = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (g_TESSaveLoadGame->FUN_008df040() >= 64 && !restored)
                g_TESSaveLoadGame->FUN_00857bd0(FUN_004efaa0() + 4);
        }
        FUN_0049bca0(time, m_kRootTranslation, true);
        if (g_TESSaveLoadGame->FUN_00862110())
        {
            unsigned int end = g_TESSaveLoadGame->FUN_00825c00();
            Record90* record = g_TESSaveLoadGame->FUN_004fd3c0();
            if (record)
            {
                TESForm* form = FUN_004839c0(record->id);
                if (end > start + size)
                    FNV_Warning(
                        "SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                        end - (start + size), "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Animation.cpp",
                        0x16ac, record->id, form->GetName(), record->version, *(unsigned int*)&record->flags0);
                else if (end < start + size)
                    FNV_Warning(
                        "SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                        start + size - end, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Animation.cpp",
                        0x16ac, record->id, form->GetName(), record->version, *(unsigned int*)&record->flags0);
            }
            else
            {
                if (end > start + size)
                    FNV_Warning(
                        "SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Current version is %i",
                        end - (start + size), "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Animation.cpp",
                        0x16ac, g_TESSaveLoadGame->FUN_008df040());
                else if (end < start + size)
                    FNV_Warning(
                        "SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Current version is %i",
                        start + size - end, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Animation.cpp",
                        0x16ac, g_TESSaveLoadGame->FUN_008df040());
            }
        }
    }
}

struct ExtraDataListCopy : public ExtraDataList
{
    ExtraDataListCopy();
    void CopyFrom(ExtraDataList* source);
};

struct FUN_004bc650_shell : public InventoryStackRecord
{
    InventoryStackRecord* FUN_004bc650(InventoryStackRecord* other);
};

// @fnv 0x004bc650
InventoryStackRecord* FUN_004bc650_shell::FUN_004bc650(InventoryStackRecord* other)
{
    m_pItemObject = other->m_pItemObject;
    m_pExtraDataLists = new BSSimpleList<ExtraDataList*>;
    ExtraDataList* copy;
    BSSimpleList<ExtraDataList*>* node2 = other->m_pExtraDataLists;
    copy = 0;
    while (node2 && node2->GetItem())
    {
        copy = new ExtraDataListCopy;
        ((ExtraDataListCopy*)copy)->CopyFrom(node2->GetItem());
        m_pExtraDataLists->AddTail(copy);
        node2 = node2->GetNext();
    }
    m_iCountChange = other->m_iCountChange;
    return this;
}

struct ExtraList_4bd5c0
{
    ExtraList_4bd5c0();
    virtual ~ExtraList_4bd5c0();
    void CopyFrom(void* src);
    void* pHead;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

struct ExtraListList_4bd5c0
{
    ExtraList_4bd5c0* m_item;
    ExtraListList_4bd5c0* m_pkNext;
    ExtraListList_4bd5c0();
    ExtraList_4bd5c0** GetItem();
    void AddHead(ExtraList_4bd5c0*& item);
    void Remove(ExtraList_4bd5c0* const& item);
};

struct ItemChange_4bd5c0
{
    ExtraListList_4bd5c0* m_pExtraDataLists;
    int m_iCountChange;
    void* m_pItemObject;
    void FUN_004bd5c0(void* extra);
};

// Copies extra data into the first ExtraList, creating the list if needed, or removes and deletes the first entry when extra is null.
// @fnv 0x004bd5c0
void ItemChange_4bd5c0::FUN_004bd5c0(void* extra)
{
    if (extra)
    {
        if (m_pExtraDataLists && *m_pExtraDataLists->GetItem())
        {
            (*m_pExtraDataLists->GetItem())->CopyFrom(extra);
        }
        else
        {
            ExtraList_4bd5c0* list = new ExtraList_4bd5c0;
            list->CopyFrom(extra);
            if (!m_pExtraDataLists)
                m_pExtraDataLists = new ExtraListList_4bd5c0;
            m_pExtraDataLists->AddHead(list);
        }
    }
    else if (m_pExtraDataLists)
    {
        ExtraList_4bd5c0* first = *m_pExtraDataLists->GetItem();
        if (first)
        {
            m_pExtraDataLists->Remove(first);
            delete first;
        }
    }
}

namespace fnv_004be5a0 {
extern const char g_inventoryChangesSourceFilename[];

struct SaveSizeItem
{
    unsigned short FUN_00422c40(int a, int b);
};
struct SaveSizeNode
{
    bool _ref_008256d0();
    SaveSizeItem** _ref_006815c0();
    SaveSizeNode* _ref_00726070();
};
struct SaveSizeForm
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
    virtual const char* GetEditorName();
};
SaveSizeForm* __cdecl _ref_004839c0(unsigned int formID);

struct SaveChangeRecord
{
    unsigned int formID;
    unsigned char unk04;
    unsigned char changeFlagsStart;
};
struct SaveLoadGameStub
{
    bool FUN_00862110();
    SaveChangeRecord* GetCurrentChangeRecord();
};
extern SaveLoadGameStub* g_TESSaveLoadGame;

struct DebugSettingStub
{
    unsigned char* Bool();
};
extern DebugSettingStub g_011de4e8;

void __cdecl FUN_0040fbe0(const char* fmt, ...);

struct InventoryChangesSaveSize : public InventoryChanges
{
    unsigned short FUN_004be5a0();
};

// Computes the save size of the inventory changes: adds fixed header bytes, sums each item's size, and optionally logs the total with the current form.
// @fnv 0x004be5a0
unsigned short InventoryChangesSaveSize::FUN_004be5a0()
{
    unsigned short size3 = 0;
    unsigned short start = size3;
    if (g_TESSaveLoadGame->FUN_00862110())
    {
        size3 += 4;
        size3 += 2;
    }
    size3 += 8;
    size3 += 4;
    SaveSizeNode* node5 = (SaveSizeNode*)m_pEntryList;
    while (node5 && !node5->_ref_008256d0())
    {
        SaveSizeItem* itemB = *node5->_ref_006815c0();
        size3 += itemB->FUN_00422c40(0, 0);
        node5 = node5->_ref_00726070();
    }
    if (*g_011de4e8.Bool())
    {
        SaveChangeRecord* pChangeRecord = g_TESSaveLoadGame->GetCurrentChangeRecord();
        if (pChangeRecord)
        {
            SaveSizeForm* form = _ref_004839c0(pChangeRecord->formID);
            FUN_0040fbe0("GetSaveSize(): %-5i for form %08X %s with flags %08X ending at line %i in file %s",
                         size3 - start, pChangeRecord->formID, form->GetEditorName(),
                         *(unsigned int*)&pChangeRecord->changeFlagsStart, 1570, g_inventoryChangesSourceFilename);
        }
        else
        {
            FUN_0040fbe0("GetSaveSize(): %-5i ending at line %i in file %s", size3 - start, 1570,
                         g_inventoryChangesSourceFilename);
        }
    }
    return size3;
}
}  // namespace fnv_004be5a0

namespace fnv_004be930 {
void FNV_Warning(const char* pFormat, ...);

struct FUN_004fd3c0_info
{
    unsigned int uiID;
    unsigned char aucData[6];
    unsigned int GetValue5()
    {
        return *(unsigned int*)&aucData[1];
    }
};

struct FUN_004be930_form
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
    virtual const char* v076();
};
FUN_004be930_form* __cdecl FUN_004839c0(unsigned int auiFormID);

struct FUN_008df040_shell
{
    bool FUN_00862110();
    void FUN_008579e0(void* apBuffer, unsigned int auiSize);
    void FUN_00857aa0(unsigned int* apBuffer, int aiSize);
    FUN_004fd3c0_info* FUN_004fd3c0();
    unsigned char FUN_008df040();
    unsigned int FUN_00825c00();
};
extern FUN_008df040_shell* g_TESSaveLoadGame;

struct FUN_00424960_extra
{
    void FUN_00424960(int a1, int a2, int a3);
};

struct FUN_004be930_shell
{
    BSSimpleList<ExtraDataList*>* pExtraLists;
    int iCountDelta;
    TESBoundObject* pObject;
    void FUN_004be930();
};

// Reads a save-load block header, form ID, count delta and extra-data list, then warns on block header or buffer size mismatches.
// @fnv 0x004be930
void FUN_004be930_shell::FUN_004be930()
{
    int i;
    unsigned int uiFormIDX;
    unsigned short usSize = 0;
    unsigned int uiStart = 0;
    int iCount;
    if (g_TESSaveLoadGame->FUN_00862110())
    {
        unsigned int uiMarker;
        g_TESSaveLoadGame->FUN_008579e0(&uiMarker, 4);
        if (uiMarker != 0x424c4f4b)
        {
            FUN_004fd3c0_info* pInfo = g_TESSaveLoadGame->FUN_004fd3c0();
            if (pInfo)
            {
                FUN_004be930_form* pForm = FUN_004839c0(pInfo->uiID);
                FNV_Warning(
                    "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                    g_inventoryChangesSourceFilename, 0x647, pInfo->uiID, pForm->v076(), pInfo->aucData[5],
                    *(unsigned int*)&pInfo->aucData[1]);
            }
            else
                FNV_Warning(
                    "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Current version is %i",
                    g_inventoryChangesSourceFilename, 0x647, g_TESSaveLoadGame->FUN_008df040());
        }
        uiStart = g_TESSaveLoadGame->FUN_00825c00();
        g_TESSaveLoadGame->FUN_008579e0(&usSize, 2);
    }

    g_TESSaveLoadGame->FUN_00857aa0(&uiFormIDX, 4);
    g_TESSaveLoadGame->FUN_008579e0(&iCountDelta, 4);
    pObject = dynamic_cast<TESBoundObject*>((TESForm*)FUN_004839c0(uiFormIDX));
    pExtraLists = 0;
    g_TESSaveLoadGame->FUN_008579e0(&iCount, 4);
    if (iCount)
    {
        pExtraLists = new BSSimpleList<ExtraDataList*>;
        for (i = 0; i < iCount; i++)
        {
            ExtraDataList* pExtra = (ExtraDataList*)new FUN_00410360;
            ((FUN_00424960_extra*)pExtra)->FUN_00424960(0, 0, 0);
            pExtraLists->AddTail(pExtra);
        }
    }

    if (g_TESSaveLoadGame->FUN_00862110())
    {
        FUN_004fd3c0_info* pInfoCur;
        unsigned int uiEnd = g_TESSaveLoadGame->FUN_00825c00();
        pInfoCur = g_TESSaveLoadGame->FUN_004fd3c0();
        if (pInfoCur)
        {
            FUN_004be930_form* pFormCur = FUN_004839c0(pInfoCur->uiID);
            if (uiEnd > usSize + uiStart)
                FNV_Warning(
                    "SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                    uiEnd - (usSize + uiStart), g_inventoryChangesSourceFilename, 0x66b, pInfoCur->uiID,
                    pFormCur->v076(), pInfoCur->aucData[5], *(unsigned int*)&pInfoCur->aucData[1]);
            else if (uiEnd < usSize + uiStart)
                FNV_Warning(
                    "SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                    usSize + uiStart - uiEnd, g_inventoryChangesSourceFilename, 0x66b, pInfoCur->uiID, pFormCur->v076(),
                    pInfoCur->aucData[5], *(unsigned int*)&pInfoCur->aucData[1]);
        }
        else
        {
            if (uiEnd > usSize + uiStart)
                FNV_Warning(
                    "SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Current version is %i",
                    uiEnd - (usSize + uiStart), g_inventoryChangesSourceFilename, 0x66b,
                    g_TESSaveLoadGame->FUN_008df040());
            else if (uiEnd < usSize + uiStart)
                FNV_Warning(
                    "SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Current version is %i",
                    usSize + uiStart - uiEnd, g_inventoryChangesSourceFilename, 0x66b,
                    g_TESSaveLoadGame->FUN_008df040());
        }
    }
}
}  // namespace fnv_004be930

namespace fnv_004bf660 {
struct InventoryExtra
{
    signed char GetExtraByteValue();
};
struct InventoryExtraNode
{
    InventoryExtra** FUN_006815c0();
    InventoryExtraNode* FUN_00726070();
};
struct InventoryEntry
{
    ~InventoryEntry();
    InventoryExtraNode* FUN_00559450();
};
struct InventoryIterator
{
    ~InventoryIterator();
};
void FUN_00403d30(void*, int, unsigned int);
struct InventoryOwner
{
    InventoryIterator* FUN_004ca200();
    InventoryEntry* GetNextInventoryEntry(InventoryIterator*);
    InventoryEntry** CollectEntriesByRank(int, int);
};
// @fnv 0x004bf660
InventoryEntry** InventoryOwner::CollectEntriesByRank(int aiMinRank, int aiMaxRank)
{
    if (aiMinRank > aiMaxRank)
        return 0;
    unsigned int iterator = aiMaxRank - aiMinRank + 1;
    InventoryEntry** entries = new InventoryEntry*[iterator];
    FUN_00403d30(entries, 0, iterator * sizeof(InventoryEntry*));
    InventoryIterator* count = FUN_004ca200();
    InventoryEntry* entry = 0;
    do
    {
        entry = GetNextInventoryEntry(count);
        if (entry)
        {
            bool found = false;
            for (InventoryExtraNode* node = entry->FUN_00559450(); node && *node->FUN_006815c0();
                 node = node->FUN_00726070())
            {
                signed char rank = (*node->FUN_006815c0())->GetExtraByteValue();
                if (rank >= aiMinRank && rank <= aiMaxRank)
                {
                    int index = rank - aiMinRank;
                    delete entries[index];
                    entries[index] = entry;
                    found = true;
                }
            }
            if (!found)
                delete entry;
        }
    } while (entry);
    delete count;
    return entries;
}
}  // namespace fnv_004bf660

struct RefSlot
{
    TESBoundObject* FUN_0044ddc0();
    int FUN_00726070();
};
struct PlayerSlot
{
    unsigned int GetAtIfValid(int);
    void SetIdleAt(int, void*);
};
struct ExtraSlot
{
    bool HasOnlyAllowedExtraData(int);
    void SetHotKey(unsigned char);
    void FUN_00419ad0(int);
};
struct ChangeSlot : InventoryStackRecord
{
    int FUN_00726070();
    int FUN_004bc8f0(bool);
    bool FUN_004bddd0(bool);
};
struct InventorySlot : InventoryChanges
{
    void ClearExtraForSlot(RefSlot*, int);
    ChangeSlot* FUN_004bfba0(TESBoundObject*, int, int);
    void SetInventorySlotExtraData(RefSlot*, ExtraDataList*, int);
};
// Ensures the inventory change for ref has an ExtraDataList tagged with slot, creating the change and list entries when missing.
// @fnv 0x004bf800
void InventorySlot::SetInventorySlotExtraData(RefSlot* ref, ExtraDataList* extra, int slot)
{
    AutoMemContext change(MEM_CONTEXT_MEM_CONTEXT_INVENTORY, true, g_inventoryChangesSourceFilename, 1974);
    if (!ref || slot < 0 || slot > 7)
        return;
    if (((PlayerSlot*)DAT_011dea3c)->GetAtIfValid(slot))
        ((PlayerSlot*)DAT_011dea3c)->SetIdleAt(slot, 0);
    ClearExtraForSlot(ref, -1);
    ChangeSlot* context = FUN_004bfba0(ref->FUN_0044ddc0(), 1, 0);
    if (context)
    {
        ExtraDataList* selected = 0;
        if (!context->m_pExtraDataLists)
            context->m_pExtraDataLists = new BSSimpleList<ExtraDataList*>;
        for (BSSimpleList<ExtraDataList*>* node = context->m_pExtraDataLists; node && node->GetItem();
             node = node->GetNext())
        {
            if (!selected && ((ExtraSlot*)node->GetItem())->HasOnlyAllowedExtraData(0))
                selected = node->GetItem();
            if (node->GetItem() == extra)
                selected = extra;
        }
        if (!selected)
        {
            ExtraDataList* created = (ExtraDataList*)new FUN_00410360;
            ((ExtraSlot*)created)->SetHotKey((unsigned char)slot);
            ((ExtraSlot*)created)
                ->FUN_00419ad0(context->FUN_00726070() - context->FUN_004bc8f0(false) -
                               (context->FUN_004bddd0(false) ? 1 : 0));
            context->m_pExtraDataLists->AddHead(created);
        }
        else
        {
            ((ExtraSlot*)selected)->SetHotKey((unsigned char)slot);
        }
    }
    else
    {
        InventoryStackRecord* pNewChange = (InventoryStackRecord*)new FUN_004bc550(ref->FUN_0044ddc0(), ref->FUN_00726070());
        ExtraDataList* pNewExtra = (ExtraDataList*)new FUN_00410360;
        pNewChange->m_pExtraDataLists = new BSSimpleList<ExtraDataList*>;
        ((ExtraSlot*)pNewExtra)->SetHotKey((unsigned char)slot);
        pNewChange->m_pExtraDataLists->AddHead(pNewExtra);
        m_pEntryList->AddHead(pNewChange);
    }
}

struct EquipForm;
struct EquipExtra;
struct EquipEntry;
struct EquipActor;
struct EquipAnim;
struct EquipList
{
    EquipExtra* item;
    EquipList* next;
    EquipList();
    EquipExtra** FUN_006815c0();
    EquipList* FUN_00726070();
    bool FUN_005f65d0(EquipExtra*&);
    void FUN_005ae3d0(EquipExtra*&);
    void FUN_00470470();
};
struct EquipExtra
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    EquipExtra();
    bool FUN_00418750();
    bool CompareList(EquipExtra*);
    short FUN_00418770();
    void CopyList(EquipExtra*);
    void FUN_00419ad0(unsigned short);
    signed char GetExtraByteValue();
    void FUN_0042dec0();
    void SetWornState(bool, bool);
    bool FUN_00418b10();
    void FUN_0041ab70(bool);
};
struct EquipEntry
{
    EquipList* extras;
    int count;
    EquipForm* form;
    EquipEntry(EquipForm*, int);
    ~EquipEntry();
    int FUN_004bc8f0(bool);
    int FUN_004bc980();
    bool FUN_004bddd0(bool);
    int FUN_00726070();
    EquipForm* FUN_0044ddc0();
};
struct EquipBiped
{
    bool FUN_00480d10();
    bool FUN_004c0bd0();
    bool FUN_00480d30();
};
struct EquipForm
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
    EquipBiped biped;
    int FUN_00401170();
    bool FUN_004c0bf0();
    float FUN_004e4620();
};
EquipBiped* __cdecl GetFormAsBipedModel(EquipForm*);
struct EquipContainer
{
    int FUN_00482a90(EquipForm*);
};
struct EquipChangeList
{
    void FUN_00905820(EquipEntry*&);
};
struct EquipProcess
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
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
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
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
    virtual EquipEntry* v148();
    virtual EquipEntry* v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual bool v160(EquipEntry*, int, int);
    virtual void v164();
    virtual bool v168(EquipEntry*);
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
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
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
    virtual void v468(int);
    virtual void v46c();
    virtual void v470();
    virtual bool v474(int);
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
    virtual void v4bc();
    virtual void v4c0();
    virtual void v4c4();
    virtual void v4c8();
    virtual void v4cc();
    virtual void v4d0();
    virtual void v4d4();
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
    virtual void v52c();
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
    virtual void v5a0();
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
    virtual void v610();
    virtual void v614();
    virtual void v618();
    virtual void v61c();
    virtual void v620();
    virtual void v624();
    virtual void v628();
    virtual void v62c();
    virtual void v630();
    virtual void v634();
    virtual void v638();
    virtual void v63c();
    virtual void v640();
    virtual void v644();
    virtual void v648();
    virtual void v64c();
    virtual void v650();
    virtual void v654();
    virtual void v658();
    virtual void v65c();
    virtual void v660();
    virtual void v664();
    virtual void v668();
    virtual void v66c();
    virtual void v670();
    virtual void v674();
    virtual void v678();
    virtual void v67c();
    virtual void v680();
    virtual void v684();
    virtual void v688();
    virtual void v68c();
    virtual void v690();
    virtual void v694();
    virtual void v698();
    virtual void v69c();
    virtual void v6a0();
    virtual void v6a4();
    virtual void v6a8();
    virtual void v6ac();
    virtual void v6b0();
    virtual void v6b4();
    virtual void v6b8();
    virtual void v6bc();
    virtual void v6c0();
    virtual void v6c4();
    virtual void v6c8();
    virtual void v6cc();
    virtual void v6d0();
    virtual void v6d4();
    virtual void v6d8();
    virtual void v6dc();
    virtual void v6e0();
    virtual void v6e4(EquipActor*);
};
struct EquipAnim
{
    void FUN_004c0c90(float);
};
struct EquipActor
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
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
    virtual void v48(int);
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
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
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
    virtual int v1d0();
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
    EquipProcess* process;
    EquipProcess* FUN_008d8520();
    void FUN_008b0b00(int);
    EquipAnim* FUN_008b70d0();
    void SetField1F0(EquipForm*);
    void FUN_00571760(EquipForm*);
    void FUN_004534f0(EquipForm*);
    void* FUN_0043fcd0();
    void FUN_008b0bd0(void*);
};

bool __cdecl FUN_008c7aa0();
EquipActor* __cdecl FUN_0047b200();
struct EquipQueue
{
    void FUN_0087b360(EquipActor*, EquipForm*);
};
EquipQueue* __cdecl FUN_004537b0();
void __cdecl ApplyPerkModifiers(int, EquipActor*, ...);
struct EquipInv
{
    EquipChangeList* changes;
    EquipActor* owner;
    void FUN_004bf0e0();
    EquipEntry* FUN_004bfba0(EquipForm*, int, int);
    EquipContainer* FUN_004bffb0();
    void AddItemToInventory(EquipForm*, int, EquipActor*, EquipExtra*, bool, bool);
};
// Adds count of form to the inventory entry, creating or splitting extras as needed, then equips or applies it to the actor's process based on form type.
// @fnv 0x004bffe0
void EquipInv::AddItemToInventory(EquipForm* form, int count, EquipActor* actor, EquipExtra* extra, bool left,
                                  bool flag)
{
    AutoMemContext context4_2((MEM_CONTEXT)0x36, true, g_inventoryChangesSourceFilename, 0x960);
    FUN_004bf0e0();
    EquipBiped* unusedBiped5;
    if (owner)
    {
        owner->v48(0x20);
        if (form->FUN_00401170() == 0x1a || form->FUN_00401170() == 0x18)
            unusedBiped5 = GetFormAsBipedModel(form);
    }
    EquipEntry* entry36 = FUN_004bfba0(form, 1, 0);
    int baseCountX = FUN_004bffb0()->FUN_00482a90(form);
    int total5 = baseCountX;
    if (entry36)
        total5 += entry36->count;
    int wornCount3 = 0;
    if (entry36 && entry36->extras)
        wornCount3 = entry36->FUN_004bc8f0(false) + entry36->FUN_004bc980();
    int availableVal = total5 - wornCount3;
    if (entry36 && entry36->extras)
    {
        if (*entry36->extras->FUN_006815c0() && (*entry36->extras->FUN_006815c0())->FUN_00418750())
            availableVal = baseCountX - wornCount3;
        bool found = false;
        if (extra && !entry36->extras->FUN_005f65d0(extra))
        {
            EquipList* scan = entry36->extras;
            while (scan && *scan->FUN_006815c0())
            {
                EquipExtra* candidate = *scan->FUN_006815c0();
                if (candidate && !candidate->CompareList(extra))
                {
                    extra = candidate;
                    found = true;
                    break;
                }
                else
                    scan = scan->FUN_00726070();
            }
            if (!found)
                extra = 0;
        }
    }
    bool created3 = true;
    EquipExtra* selected9 = 0;
    if ((!extra && availableVal > 0) || !entry36)
    {
        if (!entry36)
        {
            entry36 = new EquipEntry(form, 0);
            created3 = true;
            changes->FUN_00905820(entry36);
            extra = 0;
        }
    }
    else
    {
        if (entry36->FUN_004bddd0(false))
            return;
        EquipList* scan = entry36->extras;
        while (scan && created3)
        {
            selected9 = *scan->FUN_006815c0();
            if (extra && extra == selected9)
            {
                bool special = form->FUN_00401170() == 0x28 && form->FUN_004c0bf0();
                if (selected9->FUN_00418770() > 1 && form->FUN_00401170() != 0x29 && !special)
                {
                    extra = new EquipExtra;
                    extra->CopyList(selected9);
                    extra->FUN_00419ad0(1);
                    selected9->FUN_00419ad0(selected9->FUN_00418770() - 1);
                    if (selected9->GetExtraByteValue() >= 0)
                        selected9->FUN_0042dec0();
                }
                else
                {
                    selected9->SetWornState(true, left);
                    selected9->FUN_00419ad0(entry36->FUN_00726070());
                }
                created3 = false;
            }
            else if (selected9 && !extra)
            {
                if ((int)selected9->FUN_00418770() == 1)
                    extra = selected9;
                else
                {
                    bool special = form->FUN_00401170() == 0x28 && form->FUN_004c0bf0();
                    if (selected9->FUN_00418770() > 1 && form->FUN_00401170() != 0x29 && !special)
                    {
                        extra = new EquipExtra;
                        extra->CopyList(selected9);
                        extra->FUN_00419ad0(1);
                        selected9->FUN_00419ad0(selected9->FUN_00418770() - 1);
                        if (selected9->GetExtraByteValue() >= 0)
                            selected9->FUN_0042dec0();
                    }
                    else
                        extra = selected9;
                }
                created3 = false;
            }
            else
                scan = scan->FUN_00726070();
        }
    }
    if (extra && !extra->FUN_00418b10())
    {
        extra->SetWornState(true, left);
        extra->FUN_00419ad0((unsigned short)count);
        created3 = false;
        if (!entry36->extras)
            entry36->extras = new EquipList;
        if (!entry36->extras->FUN_005f65d0(extra))
            entry36->extras->FUN_005ae3d0(extra);
        selected9 = extra;
    }
    if (created3)
    {
        selected9 = new EquipExtra;
        selected9->SetWornState(true, left);
        if (count > 1)
            selected9->FUN_00419ad0((unsigned short)count);
        if (!entry36->extras)
            entry36->extras = new EquipList;
        if (!entry36->extras->FUN_005f65d0(selected9))
            entry36->extras->FUN_005ae3d0(selected9);
    }
    if (selected9)
        selected9->FUN_0041ab70(flag);
    if (actor->process)
    {
        EquipEntry* equipped = 0;
        EquipBiped* biped = GetFormAsBipedModel(form);
        switch (form->FUN_00401170())
        {
        case 0x1a:
            actor->process->v468(1);
            break;
        case 0x28:
            equipped = actor->FUN_008d8520()->v148();
            if (equipped)
            {
                equipped->extras->FUN_00470470();
                equipped->extras->FUN_005ae3d0(selected9);
                equipped->form = form;
                actor->FUN_008b0b00(0);
            }
            else
            {
                equipped = new EquipEntry(form, count);
                equipped->extras->FUN_005ae3d0(selected9);
                if (!actor->FUN_008d8520()->v160(equipped, actor->v1d0(), 0))
                {
                    delete equipped;
                    equipped = 0;
                }
                else
                {
                    EquipAnim* anim7 = actor->FUN_008b70d0();
                    float speed6 = equipped->FUN_0044ddc0()->FUN_004e4620();
                    ApplyPerkModifiers(0x2b, actor, equipped->FUN_0044ddc0(), &speed6);
                    if (anim7)
                        anim7->FUN_004c0c90(speed6);
                }
            }
            if (actor == ((EquipActor*)DAT_011dea3c) || !actor->process->v474(1))
            {
                if (equipped)
                {
                    if (actor == ((EquipActor*)DAT_011dea3c))
                        ((EquipActor*)DAT_011dea3c)->SetField1F0(equipped->form);
                    else if (FUN_008c7aa0() && actor != FUN_0047b200())
                        FUN_004537b0()->FUN_0087b360(actor, equipped->form);
                    else
                        actor->FUN_00571760(equipped->form);
                }
            }
            break;
            break;
        case 0x18:
            if (form->biped.FUN_00480d10() || form->biped.FUN_004c0bd0() || form->biped.FUN_00480d30())
            {
                if (actor->FUN_008d8520())
                    actor->FUN_008d8520()->v6e4(actor);
            }
            actor->process->v468(1);
            break;
        case 0x29:
            equipped = actor->FUN_008d8520()->v14c();
            if (equipped)
            {
                equipped->extras->FUN_00470470();
                equipped->extras->FUN_005ae3d0(selected9);
                equipped->form = form;
            }
            else
            {
                equipped = new EquipEntry(form, 0);
                equipped->extras->FUN_005ae3d0(selected9);
                if (!actor->FUN_008d8520()->v168(equipped))
                {
                    delete equipped;
                    equipped = 0;
                }
            }
            if (!actor->process->v474(1) && equipped)
                actor->FUN_004534f0(equipped->form);
            break;
        }
        actor->FUN_008b0bd0(actor->FUN_0043fcd0());
    }
}

extern const char g_inventoryChangesSourceFilename[];

struct BoundShell : TESBoundObject
{

    int FUN_00401170();

    bool FUN_004c0bf0();

    int FUN_00482a90();
};

struct ExtraShell : ExtraDataList
{

    ExtraShell();

    bool FUN_00418750();

    short FUN_00418770();

    bool CompareList(ExtraShell*);

    void FUN_00419ad0(int);

    void CopyList(ExtraShell*);

    signed char GetExtraByteValue();

    void FUN_0042dec0();
};

struct ExtraNodeShell : BSSimpleList<ExtraDataList*>
{

    ExtraNodeShell();

    ExtraShell** _ref_006815c0();

    ExtraNodeShell* _ref_00726070();

    bool FUN_005f65d0(ExtraShell**);

    void FUN_005ae3d0(ExtraShell**);
};

struct ItemShell : InventoryStackRecord
{

    ItemShell(BoundShell*, int);

    int FUN_004bc8f0(bool);

    int FUN_004bc980();

    bool FUN_004bddd0(bool);
};

struct ItemListShell : BSSimpleList<InventoryStackRecord*>
{

    void _ref_00905820(InventoryStackRecord**);
};

struct RefShell : TESObjectREFR
{

    void Invalidate(unsigned mask)
    {

        typedef void(__thiscall * Callback)(TESObjectREFR*, unsigned);

        ((Callback)(*(void***)this)[18])(this, mask);
    }
};

struct ChangesShell : InventoryChanges
{

    ItemShell* FUN_004bfba0(BoundShell*, int, int);

    BoundShell* FUN_004bffb0(BoundShell*);

    void AddItemExtraData(BoundShell*, int, int, ExtraShell*, ExtraNodeShell**);
};

// @fnv 0x004c1520
void ChangesShell::AddItemExtraData(BoundShell* item, int number, int unknown, ExtraShell* selection,
                                    ExtraNodeShell** apResultList)

{

    AutoMemContext contextGuard((MEM_CONTEXT)0x36, true, g_inventoryChangesSourceFilename, 0xb83);

    if (pRef)
        pRef->MarkAsModified(0x20);

    ItemShell* itemCount = FUN_004bfba0(item, 1, 0);

    int wornCount = FUN_004bffb0(item)->FUN_00482a90();

    int itemChange = wornCount;

    if (itemCount)

        itemChange += itemCount->m_iCountChange;

    int oldCount = 0;

    if (itemCount && itemCount->m_pExtraDataLists)
    {

        oldCount = itemCount->FUN_004bc8f0(false) + itemCount->FUN_004bc980();
    }

    int needExtra = itemChange - oldCount;

    if (itemCount && itemCount->m_pExtraDataLists)
    {

        if (*((ExtraNodeShell*)itemCount->m_pExtraDataLists)->_ref_006815c0() &&

            (*((ExtraNodeShell*)itemCount->m_pExtraDataLists)->_ref_006815c0())->FUN_00418750())

            needExtra = wornCount - oldCount;

        bool found = false;

        if (selection && !((ExtraNodeShell*)itemCount->m_pExtraDataLists)->FUN_005f65d0(&selection))
        {

            ExtraNodeShell* cursor = (ExtraNodeShell*)itemCount->m_pExtraDataLists;

            while (cursor && *cursor->_ref_006815c0())
            {

                ExtraShell* possible = *cursor->_ref_006815c0();

                if (possible && !possible->CompareList(selection))
                {
                    selection = possible;
                    found = true;
                    break;
                }
                else
                {
                    cursor = cursor->_ref_00726070();
                }
            }

            if (!found)
                selection = 0;
        }
    }

    bool remaining = true;

    ExtraShell* chosen = 0;

    if ((!selection && needExtra > 0) || !itemCount)
    {

        if (!itemCount)
        {

            itemCount = new ItemShell(item, 0);

            remaining = true;

            ((ItemListShell*)m_pEntryList)->_ref_00905820((InventoryStackRecord**)&itemCount);

            selection = 0;
        }
    }
    else
    {

        if (itemCount->FUN_004bddd0(false))

            return;

        ExtraNodeShell* cursor = (ExtraNodeShell*)itemCount->m_pExtraDataLists;

        while (cursor && remaining)
        {

            chosen = *cursor->_ref_006815c0();

            if (selection && selection == chosen)
            {

                bool isWeapon = item->FUN_00401170() == 0x28 && item->FUN_004c0bf0();

                if (chosen->FUN_00418770() > 1 && item->FUN_00401170() != 0x29 && !isWeapon)
                {

                    selection = new ExtraShell();

                    selection->CopyList(chosen);

                    selection->FUN_00419ad0(1);

                    chosen->FUN_00419ad0(chosen->FUN_00418770() - 1);

                    if (chosen->GetExtraByteValue() >= 0)

                        chosen->FUN_0042dec0();
                }
                else
                {

                    chosen->FUN_00419ad0((int)((ExtraNodeShell*)itemCount)->_ref_00726070());
                }

                remaining = false;
            }
            else if (chosen && !selection)
            {

                if (chosen->FUN_00418770() == 1)
                {

                    selection = chosen;
                }
                else
                {

                    bool isWeapon = item->FUN_00401170() == 0x28 && item->FUN_004c0bf0();

                    if (chosen->FUN_00418770() > 1 && item->FUN_00401170() != 0x29 && !isWeapon)
                    {

                        selection = new ExtraShell();

                        selection->CopyList(chosen);

                        selection->FUN_00419ad0(1);

                        chosen->FUN_00419ad0(chosen->FUN_00418770() - 1);

                        if (chosen->GetExtraByteValue() >= 0)

                            chosen->FUN_0042dec0();
                    }
                    else
                        selection = chosen;
                }

                remaining = false;
            }
            else
            {

                cursor = cursor->_ref_00726070();
            }
        }
    }

    if (selection)
    {

        selection->FUN_00419ad0((unsigned short)number);

        remaining = false;

        if (!itemCount->m_pExtraDataLists)

            itemCount->m_pExtraDataLists = new ExtraNodeShell();

        if (!((ExtraNodeShell*)itemCount->m_pExtraDataLists)->FUN_005f65d0(&selection))

            ((ExtraNodeShell*)itemCount->m_pExtraDataLists)->FUN_005ae3d0(&selection);

        if (apResultList && !(*apResultList)->FUN_005f65d0(&selection))

            (*apResultList)->FUN_005ae3d0(&selection);

        chosen = selection;
    }

    if (remaining)
    {

        chosen = new ExtraShell();

        if (number > 1)

            chosen->FUN_00419ad0((unsigned short)number);

        if (!itemCount->m_pExtraDataLists)

            itemCount->m_pExtraDataLists = new ExtraNodeShell();

        if (!((ExtraNodeShell*)itemCount->m_pExtraDataLists)->FUN_005f65d0(&chosen))

            ((ExtraNodeShell*)itemCount->m_pExtraDataLists)->FUN_005ae3d0(&chosen);

        if (apResultList)
        {

            if (!*apResultList)

                *apResultList = new ExtraNodeShell();

            if (!(*apResultList)->FUN_005f65d0(&chosen))

                (*apResultList)->FUN_005ae3d0(&chosen);
        }
    }
}

struct TESHealthForm
{
    virtual void h0();
    virtual void h1();
    virtual void h2();
    virtual void h3();
    virtual unsigned int GetHealth();
};
struct W20Form;
struct W20Ref;
struct W20AmmoExtra
{
    unsigned int unk00, unk04, unk08, unk0c;
    int count;
};
struct W20Extra
{
    virtual ~W20Extra();
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    W20Extra();
    float FUN_004186f0();
    bool FUN_00418ba0();
    bool IsEmpty();
    short FUN_00418770();
    void FUN_00419ad0(short);
    void FUN_00419fb0(float);
    void CopyListForContainer(W20Extra*, bool);
    bool CompareListForContainer(W20Extra*, bool, bool);
    W20Form* GetOwner();
    void FUN_0041aed0();
    void RemoveExtra24();
    void SetWornState(bool, bool);
    void FUN_0041c7f0(W20Ref*);
    W20AmmoExtra* GetExtraAmmo();
    void SetOwnership(int, int);
};
struct W20ExtraList
{
    W20Extra* data;
    W20ExtraList* next;
    W20ExtraList();
    ~W20ExtraList();
    W20Extra** _ref_006815c0();
    W20ExtraList* _ref_00726070();
    void Remove(W20Extra**);
    void AddHead(W20Extra**);
    bool IsEmpty();
};
struct W20Entry
{
    W20ExtraList* extras;
    int count;
    W20Form* form;
    W20Entry(W20Form*, int);
    ~W20Entry();
    static void* operator new(unsigned int);
    static void operator delete(void*);
    W20Entry* _ref_00726070();
};
struct W20EntryList
{
    void Remove(W20Entry**);
    void AddTail(W20Entry**);
};
struct W20Form : TESBoundObject
{
    int FNV_GetFormType();
    int GetWeaponType();
    bool FUN_004c0bf0();
    float GetEffectValue(int, unsigned char);
    W20Form* GetCurrentAmmo(W20Ref*);
};
struct W20Ref
{
    virtual void r0();
    virtual void r1();
    virtual void r2();
    virtual void r3();
    virtual void r4();
    virtual void r5();
    virtual void r6();
    virtual void r7();
    virtual void r8();
    virtual void r9();
    virtual void r10();
    virtual void r11();
    virtual void r12();
    virtual void r13();
    virtual void r14();
    virtual void r15();
    virtual void r16();
    virtual void r17();
    virtual void v48(int);
    virtual void r19();
    virtual void r20();
    virtual void r21();
    virtual void r22();
    virtual void r23();
    virtual void r24();
    virtual void r25();
    virtual void r26();
    virtual void r27();
    virtual void r28();
    virtual void r29();
    virtual void r30();
    virtual void r31();
    virtual void r32();
    virtual void r33();
    virtual void r34();
    virtual void r35();
    virtual void r36();
    virtual void r37();
    virtual void r38();
    virtual void r39();
    virtual void r40();
    virtual void r41();
    virtual void r42();
    virtual void r43();
    virtual void r44();
    virtual void r45();
    virtual void r46();
    virtual void r47();
    virtual void r48();
    virtual void r49();
    virtual void r50();
    virtual void r51();
    virtual void r52();
    virtual void r53();
    virtual void r54();
    virtual void r55();
    virtual void r56();
    virtual void r57();
    virtual void r58();
    virtual void r59();
    virtual void r60();
    virtual void r61();
    virtual void r62();
    virtual void r63();
    virtual bool v100();
    virtual void r65();
    virtual void r66();
    virtual void r67();
    virtual void r68();
    virtual void r69();
    virtual void r70();
    virtual void r71();
    virtual void r72();
    virtual void r73();
    virtual void r74();
    virtual void r75();
    virtual const char* v130();
    W20Form* FUN_007af430();
    W20Extra* GetExtra();
    unsigned int GetFormID();
    void FUN_00568bd0(float);
    float GetScale();
    bool FUN_005653d0();
};
extern W20Ref* g_thePlayer;
struct W20Inventory
{
    W20EntryList* entries;
    W20Ref* owner;
    float weight;
    float previous;
    bool dirty;
    W20Entry* FUN_004bfba0(W20Form*, bool, int);
    void FUN_004c29a0(W20Form*, int, int);
    void FUN_004c1c90(W20Ref*, int, int, bool);
};
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
void FNV_Warning(const char*, ...);
int FUN_004873d0(W20Form*);
unsigned int FUN_0042f5a0(unsigned int, unsigned int);

// Adds a reference's item to the inventory, fixing weapon/armor health, merging extras, and updating ammo counts.
// @fnv 0x004c1c90
void W20Inventory::FUN_004c1c90(W20Ref* ref, int count, int unused, bool mark)
{
    AutoMemContext k((MEM_CONTEXT)54, true, g_inventoryChangesSourceFilename, 3131);
    dirty = true;
    previous = weight;
    weight = -1.0f;
    if (ref->FUN_007af430()->FNV_GetFormType() == 40)
    {
        if (FUN_004873d0(ref->FUN_007af430()) && ref->GetExtra()->FUN_004186f0() == -1.0)
        {
            if (ref->FUN_007af430()->GetWeaponType() < 10)
            {
                FNV_Warning("Adding full health weapon ref '%s' (%08X) to ref '%s' (%08X).", ref->v130(),
                            ref->GetFormID(), owner->v130(), owner->GetFormID());
                TESHealthForm* p = dynamic_cast<TESHealthForm*>((TESBoundObject*)ref->FUN_007af430());
                unsigned int uiHealth = p->GetHealth();
                if (ref->GetExtra()->FUN_00418ba0())
                    uiHealth += ref->FUN_007af430()->GetEffectValue(10, 0);
                uiHealth = FUN_0042f5a0((unsigned int)(uiHealth * 0.99), uiHealth - 1);
                ref->FUN_00568bd0((float)uiHealth);
            }
        }
        else if (ref->FUN_007af430()->FUN_004c0bf0() && ref->GetExtra()->FUN_004186f0() != -1.0)
        {
            FNV_Warning("Adding damaged throwing weapon ref '%s' (%08X) to ref '%s' (%08X).", ref->v130(),
                        ref->GetFormID(), owner->v130(), owner->GetFormID());
            TESHealthForm* p = dynamic_cast<TESHealthForm*>((TESBoundObject*)ref->FUN_007af430());
            ref->FUN_00568bd0((float)p->GetHealth());
        }
    }
    if ((ref->FUN_007af430()->FNV_GetFormType() == 24 || ref->FUN_007af430()->FNV_GetFormType() == 26) &&
        FUN_004873d0(ref->FUN_007af430()) && ref->GetExtra()->FUN_004186f0() == -1.0)
    {
        FNV_Warning("Adding full health armor ref '%s' (%08X) to ref '%s' (%08X).", ref->v130(), ref->GetFormID(),
                    owner->v130(), owner->GetFormID());
        TESHealthForm* p = dynamic_cast<TESHealthForm*>((TESBoundObject*)ref->FUN_007af430());
        unsigned int uiHealth = p->GetHealth();
        uiHealth = FUN_0042f5a0((unsigned int)(uiHealth / 0.99), uiHealth - 1);
        ref->FUN_00568bd0((float)uiHealth);
    }
    int iAmmoCount = 0;
    W20AmmoExtra* l = ref->GetExtra()->GetExtraAmmo();
    if (l)
    {
        iAmmoCount = l->count;
        ref->GetExtra()->SetOwnership(0, 0);
        ref->v48(0x800);
    }
    iAmmoCount *= count;
    if (owner)
        owner->v48(0x20);
    W20Entry* j = FUN_004bfba0(ref->FUN_007af430(), true, 0);
    ref->GetExtra()->RemoveExtra24();
    W20Extra* e = new W20Extra;
    bool c = false;
    if (!ref->GetExtra()->IsEmpty())
    {
        W20Form* weapon = 0;
        if (ref->FUN_007af430()->FNV_GetFormType() == 40)
        {
            weapon = ref->FUN_007af430();
            c = weapon->FUN_004c0bf0();
        }
        e->CopyListForContainer(ref->GetExtra(), false);
        if (ref->FUN_007af430()->FNV_GetFormType() != 41 && (!weapon || !weapon->FUN_004c0bf0()))
            e->FUN_00419fb0(ref->GetScale());
        if (e->GetOwner() == (W20Form*)g_thePlayer && owner == (W20Ref*)g_thePlayer)
            e->FUN_0041aed0();
    }
    if (mark)
        e->SetWornState(true, false);
    if (j)
    {
        j->count += count;
        if (ref->FUN_005653d0())
        {
            e->FUN_0041c7f0(ref);
            if (count > 1)
                e->FUN_00419ad0((short)count);
            if (!j->extras)
                j->extras = new W20ExtraList;
            j->extras->AddHead(&e);
        }
        else
        {
            W20ExtraList* p = j->extras;
            bool h = true;
            while (p && *p->_ref_006815c0() && h)
            {
                W20Extra* pExistingExtra = *p->_ref_006815c0();
                W20Extra* i = e;
                bool a = true;
                if (i)
                    a = i->CompareListForContainer(pExistingExtra, false, c) || pExistingExtra->CompareListForContainer(i, false, c);
                if (a)
                    p = p->_ref_00726070();
                else
                {
                    pExistingExtra->FUN_00419ad0((short)(pExistingExtra->FUN_00418770() + count));
                    if (pExistingExtra->IsEmpty())
                    {
                        j->extras->Remove(&pExistingExtra);
                        delete pExistingExtra;
                    }
                    h = false;
                }
            }
            if (h)
            {
                if (e && e->IsEmpty())
                {
                    delete e;
                    e = 0;
                }
                else
                {
                    if (!j->extras)
                        j->extras = new W20ExtraList;
                    j->extras->AddHead(&e);
                }
            }
            else
            {
                delete e;
                e = 0;
            }
        }
        if (j->extras && j->extras->IsEmpty() && !j->_ref_00726070())
        {
            entries->Remove(&j);
            if (e)
                delete e;
            e = 0;
            delete j;
        }
    }
    else
    {
        W20Entry* added = new W20Entry(ref->FUN_007af430(), count);
        if (count > 1)
            e->FUN_00419ad0((short)count);
        if (ref->FUN_005653d0())
        {
            e->FUN_0041c7f0(ref);
            if (!added->extras)
                added->extras = new W20ExtraList;
            added->extras->AddHead(&e);
        }
        else if (e)
        {
            if (e->IsEmpty())
            {
                delete e;
                e = 0;
            }
            else
            {
                if (!added->extras)
                    added->extras = new W20ExtraList;
                added->extras->AddHead(&e);
            }
        }
        entries->AddTail(&added);
    }
    if (e && e->IsEmpty())
        delete e;
    if (iAmmoCount > 0)
    {
        W20Form* p = ref->FUN_007af430();
        W20Ref* a = owner->v100() ? owner : 0;
        W20Form* h = p->GetCurrentAmmo(0);
        if (h)
            FUN_004c29a0(h, 0, iAmmoCount);
    }
}

struct AddForm;
struct AddRef;
struct AddProcess;
struct AddExtra;
struct AddEntry;
struct AddAmmoExtra
{
    int unk00, unk04, unk08, unk0c;
    int count;
};
struct AddExtra
{
    virtual ~AddExtra();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    AddExtra();
    AddAmmoExtra* GetExtraAmmo();
    AddRef* FUN_00418660();
    void FUN_0041aed0();
    void SetWornState(bool, bool);
    AddRef* FUN_0041c8d0();
    void FUN_0041c7f0(AddRef*);
    bool IsEmpty();
    void* FUN_00418800();
    bool FUN_00418750();
    short FUN_00418770();
    void FUN_00419ad0(short);
    bool CompareListForContainer(AddExtra*, bool, bool);
};
struct AddNode
{
    AddExtra* data;
    AddNode* next;
    AddNode();
    AddExtra*& FUN_006815c0();
    AddNode* FUN_00726070();
    void _ref_005ae3d0(AddExtra*&);
    void _ref_00905330(AddExtra* const&);
    int _ref_005ae380();
    bool _ref_008256d0();
};
struct AddEntry
{
    AddNode* extras;
    int count;
    AddForm* form;
    AddEntry(AddForm*, int);
    ~AddEntry();
    int FUN_00726070();
    void FUN_006ecd40(int);
    bool FUN_004bddd0(bool);
    AddForm* FUN_0044ddc0();
};
struct AddProcess
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
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
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
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
    virtual AddEntry* ammoA();
    virtual AddEntry* p();
};
struct AddRef
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
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
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual bool isActor();
    AddProcess* FUN_008d8520();
    AddExtra* FUN_005d43c0();
};
struct AddForm
{
    int FUN_00401170();
    bool FUN_004c0bf0();
    AddForm* _ref_00525980(AddRef*);
};
struct AddContainer
{
    int _ref_00482a90(AddForm*);
};
struct AddChanges
{
    void _ref_00905330(AddEntry* const&);
};
struct AddInventory
{
    AddChanges* changes;
    AddRef* owner;
    float weight, previousWeight;
    bool dirty;
    AddEntry* FUN_004bfba0(AddForm*, int, int);
    void FUN_004c3380(AddEntry*, bool);
    AddContainer* FUN_004bffb0();
    void FUN_004c29a0(AddForm*, AddExtra*, int);
};
extern AddRef* addPlayer;
extern float DAT_01012054;
bool __cdecl FUN_00705020();
bool __cdecl FUN_00705000();
// Adds count of form with extra to the inventory, merging extras, updating equipped weapon ammo counts, and recursively adding loaded ammo.
// @fnv 0x004c29a0
void AddInventory::FUN_004c29a0(AddForm* form, AddExtra* extra, int count)
{
    AutoMemContext context4((MEM_CONTEXT)0x36, true, g_inventoryChangesSourceFilename, 0xd28);
    dirty = true;
    previousWeight = weight;
    weight = DAT_01012054;
    int loadedAmmoTmp = 0;
    if (!extra)
        extra = new AddExtra;
    if (extra)
    {
        AddAmmoExtra* ammoExtra = extra->GetExtraAmmo();
        if (ammoExtra)
            loadedAmmoTmp = ammoExtra->count;
    }
    loadedAmmoTmp *= count;
    if (!count)
        count = 1;
    AddEntry* entry2 = FUN_004bfba0(form, 1, 0);
    bool result5 = true;
    bool equipped = false;
    if (extra && extra->FUN_00418660() == addPlayer && owner == addPlayer)
        extra->FUN_0041aed0();
    AddRef* actor11 = 0;
    if (owner && owner->isActor())
        actor11 = owner;
    if (form->FUN_00401170() == 0x28 && actor11 && actor11->FUN_008d8520())
    {
        AddForm* weapon = form;
        AddProcess* process = actor11->FUN_008d8520();
        if (weapon->FUN_004c0bf0() && process->p() && weapon == process->p()->FUN_0044ddc0())
        {
            equipped = true;
            if (process->ammoA())
                process->ammoA()->FUN_006ecd40(process->ammoA()->FUN_00726070() + count);
            if (process->p())
                process->p()->FUN_006ecd40(process->p()->FUN_00726070() + count);
            if (!entry2 || !entry2->FUN_004bddd0(false))
            {
                if (!extra)
                    extra = new AddExtra;
                extra->SetWornState(true, false);
            }
        }
    }
    if (extra && extra->FUN_0041c8d0())
    {
        AddRef* reference = extra->FUN_0041c8d0();
        if (reference)
            reference->FUN_005d43c0()->FUN_0041c7f0(owner);
    }
    if (!entry2)
    {
        if (extra && extra->IsEmpty())
        {
            delete extra;
            extra = 0;
        }
        entry2 = new AddEntry(form, count);
        if (!entry2->extras)
            entry2->extras = new AddNode;
        entry2->extras->_ref_005ae3d0(extra);
        FUN_004c3380(entry2, true);
    }
    else
    {
        if (entry2->FUN_00726070() <= 0 && extra && !extra->FUN_00418660() && !extra->FUN_00418800() &&
            entry2->extras && entry2->extras->_ref_005ae380() && entry2->extras->FUN_006815c0()->FUN_00418750())
        {
            entry2->extras->FUN_006815c0()->FUN_00419ad0(entry2->extras->FUN_006815c0()->FUN_00418770() + count);
            delete extra;
            extra = 0;
        }
        if (extra && entry2->extras)
        {
            AddNode* node7 = entry2->extras;
            bool searching8 = true;
            while (node7 && node7->FUN_006815c0() && searching8)
            {
                AddExtra* existing7 = node7->FUN_006815c0();
                AddExtra* incomingVal = extra;
                bool different2 = true;
                if (incomingVal)
                    different2 = incomingVal->CompareListForContainer(existing7, false, equipped) ||
                                 existing7->CompareListForContainer(incomingVal, false, equipped);
                if (different2)
                    node7 = node7->FUN_00726070();
                else
                {
                    existing7->FUN_00419ad0(existing7->FUN_00418770() + count);
                    if (existing7->IsEmpty())
                    {
                        entry2->extras->_ref_00905330(existing7);
                        delete existing7;
                    }
                    searching8 = false;
                }
            }
            if (searching8)
            {
                if (extra && extra->IsEmpty())
                {
                    delete extra;
                    extra = 0;
                }
                else
                {
                    if (!entry2->extras)
                        entry2->extras = new AddNode;
                    entry2->extras->_ref_005ae3d0(extra);
                }
            }
            else if (!FUN_00705020() && !FUN_00705000())
            {
                delete extra;
                extra = 0;
            }
        }
        else if (extra && !extra->IsEmpty())
        {
            if (!entry2->extras)
                entry2->extras = new AddNode;
            entry2->extras->_ref_005ae3d0(extra);
        }
        AddContainer* base = FUN_004bffb0();
        int baseCount = base ? base->_ref_00482a90(form) : 0;
        if (entry2->FUN_00726070() < 0 && baseCount <= 0)
            entry2->FUN_006ecd40(count);
        else
            entry2->FUN_006ecd40(entry2->FUN_00726070() + count);
        if (entry2->extras && entry2->extras->_ref_008256d0() && !entry2->FUN_00726070())
        {
            changes->_ref_00905330(entry2);
            delete entry2;
        }
    }
    if (loadedAmmoTmp > 0)
    {
        AddRef* ammoActor2 = owner->isActor() ? owner : 0;
        AddForm* p = form;
        AddForm* ammoA = p->_ref_00525980(ammoActor2);
        if (ammoA)
            FUN_004c29a0(ammoA, 0, loadedAmmoTmp);
    }
}

int __cdecl FUN_00679ba0(void*);
struct Inv4c6a10
{
    ChangeNode4c6ba0* m_pEntryList;
    Container4c6ba0* FUN_004bffb0();
    Change4c6ba0* FUN_004bfba0(TESBoundObject*, int, int);
    TESBoundObject* FindInventoryItemByType(int aType, int* apCount);
};

// @fnv 0x004c6a10
TESBoundObject* Inv4c6a10::FindInventoryItemByType(int aType, int* apCount)
{
    ContNode4c6ba0* pNode = FUN_004bffb0()->FUN_00717e50();
    TESBoundObject* pFound5 = 0;
    while (pNode && !pFound5)
    {
        pFound5 = (*pNode->FUN_006815c0())->pObj;
        if (pFound5 && FUN_00679ba0(pFound5) == aType)
        {
            Change4c6ba0* pChange = FUN_004bfba0(pFound5, 1, 0);
            if (!pChange || (pChange && pChange->FUN_00726070() + (*pNode->FUN_006815c0())->count))
            {
                if (pChange)
                    *apCount = pChange->FUN_00726070() + (*pNode->FUN_006815c0())->count;
                else
                    *apCount = (*pNode->FUN_006815c0())->count;
            }
        }
        else
        {
            pFound5 = 0;
        }
        pNode = pNode->FUN_00726070();
    }
    ChangeNode4c6ba0* pIter_ = m_pEntryList;
    while (pIter_ && !pFound5)
    {
        pFound5 = (*pIter_->FUN_006815c0())->m_pItemObject;
        if (pFound5 && FUN_00679ba0(pFound5) == aType)
        {
            if (!FUN_004bffb0()->FUN_00481eb0(pFound5) && (*pIter_->FUN_006815c0())->FUN_00726070() > 0)
                *apCount = (*pIter_->FUN_006815c0())->FUN_00726070();
        }
        else
        {
            pFound5 = 0;
        }
        pIter_ = pIter_->FUN_00726070();
    }
    return pFound5;
}

class TESAmmo : public TESBoundObject
{
};
extern float DAT_01015f5c;
struct AmmoScorer
{
    float FUN_005f0d60(TESAmmo*);
};
struct AmmoContainerEntry
{
    int count;
    TESBoundObject* object;
};
struct AmmoContainerNode
{
    AmmoContainerEntry** FUN_006815c0();
    AmmoContainerNode* FUN_00726070();
};
struct AmmoContainer
{
    AmmoContainerNode* FUN_00717e50();
    bool FUN_00481eb0(TESAmmo*);
    int FUN_00482a90(TESAmmo*);
};
struct AmmoInventory
{
    ItemList* changes;
    AmmoContainer* FUN_004bffb0();
    FUN_0076b630* FUN_004bfba0(TESAmmo*, int, int);
    FUN_0076b630* FindBestAmmoChange(AmmoScorer*, int);
};
// @fnv 0x004c6f60
FUN_0076b630* AmmoInventory::FindBestAmmoChange(AmmoScorer* scorer, int unused)
{
    // Local names preserve the original MSVC9 stack allocation.
    AutoMemContext bestChange((MEM_CONTEXT)0x36, true, g_inventoryChangesSourceFilename, 0x13b5);
    float context = DAT_01015f5c;
    TESAmmo* memory = 0;
    TESAmmo* bestBase = 0;
    AmmoContainerNode* memContext = FUN_004bffb0()->FUN_00717e50();
    while (memContext)
    {
        AmmoContainerEntry* entry = *memContext->FUN_006815c0();
        TESAmmo* ammo = 0;
        if (entry)
            ammo = dynamic_cast<TESAmmo*>(entry->object);
        if (ammo)
        {
            FUN_0076b630* change = FUN_004bfba0(ammo, 1, 0);
            if (!change || ((change && change->count + (*memContext->FUN_006815c0())->count > 0) ||
                            (*memContext->FUN_006815c0())->count < 0))
            {
                float score = scorer->FUN_005f0d60(ammo);
                if (score > context)
                {
                    context = score;
                    memory = ammo;
                }
            }
        }
        memContext = memContext->FUN_00726070();
    }
    ItemList* bestScore = changes;
    while (bestScore)
    {
        FUN_0076b630* ammo = bestScore->FUN_006815c0();
        TESAmmo* entry = 0;
        if (ammo)
            entry = dynamic_cast<TESAmmo*>((TESBoundObject*)ammo->weapon);
        if (entry && (!ammo->FUN_004bcb70() || ammo->count >= 0) && ammo->FUN_00726070() &&
            !FUN_004bffb0()->FUN_00481eb0(entry))
        {
            float score = scorer->FUN_005f0d60(entry);
            if (score > context)
            {
                context = score;
                bestBase = entry;
            }
        }
        bestScore = bestScore->FUN_00726070();
    }
    if (bestBase && bestBase != memory && scorer->FUN_005f0d60(bestBase) > scorer->FUN_005f0d60(memory))
        memory = bestBase;
    FUN_0076b630* change = FUN_004bfba0(memory, 1, 0);
    FUN_0076b630* changeNode = 0;
    if (memory)
        changeNode = new FUN_0076b630;
    if (change)
    {
        changeNode->weapon = change->FUN_0044ddc0();
        if (change->FUN_00559450() && change->extras->FUN_006815c0())
        {
            changeNode->extras = new FUN_0096a2d0;
            changeNode->extras->FUN_005ae3d0(&change->extras->FUN_006815c0());
            changeNode->FUN_006ecd40((int)change->FUN_00726070());
        }
    }
    else if (memory)
    {
        changeNode->weapon = (Weapon*)memory;
        int count = FUN_004bffb0()->FUN_00482a90(memory);
        if (count < 0)
            count *= -1;
        changeNode->FUN_006ecd40(count);
    }
    return changeNode;
}

struct Scope64
{
    int value;
    Scope64(int, int, const char*, int);
    ~Scope64();
};
struct Form64
{
    int FUN_00401170();
    int FUN_00446390();
};
struct Extra64
{
    bool FUN_00418750();
    bool HasOnlyAllowedExtraData(int);
    short FUN_00418770();
    void FUN_00419ad0(int);
    bool FUN_00418ab0(int);
};
struct ExtraNode64
{
    Extra64* data;
    ExtraNode64* next;
    ExtraNode64();
    Extra64** FUN_006815c0();
    ExtraNode64* FUN_00726070();
    unsigned int FUN_005ae380();
    void FUN_005ae3d0(Extra64* const&);
    void FUN_00905820(Extra64* const&);
};
struct Change64
{
    ExtraNode64* extras;
    int count;
    Form64* form;
    Change64();
    Change64(Form64*, int);
    int FUN_00726070();
    ExtraNode64* FUN_00559450();
    int CountAndPruneEntries();
    int FUN_004bc8f0(int);
    void FUN_00403550(Form64*);
    void* FUN_004bde40();
    int FindFirstNonNegativeValue();
    void* GetExtraForm();
    Form64* FUN_0044ddc0();
    bool FUN_004bddd0(int);
    bool FUN_004bcb70();
};
struct BaseItem64
{
    int count;
    Form64* form;
};
struct BaseNode64
{
    ~BaseNode64();
    BaseItem64** FUN_006815c0();
    BaseNode64* FUN_00726070();
    void FUN_00470470();
};
struct BaseContainer64
{
    BaseNode64* CopyUniqueObjects();
    int FUN_00482a90(Form64*);
    bool FUN_00481eb0(Form64*);
};
struct ChangeNode64
{
    Change64** FUN_006815c0();
    ChangeNode64* FUN_00726070();
};
struct Inventory64
{
    ChangeNode64* changes;
    BaseContainer64* FUN_004bffb0();
    Change64* FUN_004bfba0(Form64*, int, int);
    void* FUN_00726070();
    Change64* FUN_004c94f0(int);
};
// Walks the base container and change list, counting entries and variants, and returns a new Change for the entry at the requested index, or null.
// @fnv 0x004c94f0
Change64* Inventory64::FUN_004c94f0(int requested)
{
    Scope64 scope3(0x36, 1, g_inventoryChangesSourceFilename, 0x187f);
    BaseNode64* head1 = 0;
    BaseNode64* node48 = 0;
    if (FUN_004bffb0())
        head1 = FUN_004bffb0()->CopyUniqueObjects();
    int index14 = 0;
    Change64* result1 = 0;
    BaseContainer64* baseContainer43 = FUN_004bffb0();
    node48 = head1;
    while (node48 && *node48->FUN_006815c0() && !result1)
    {
        BaseItem64* base14 = *node48->FUN_006815c0();
        Form64* leveled3 = 0;
        if (base14->form->FUN_00401170() == 0x34)
            leveled3 = base14->form;
        if (base14 && !leveled3)
        {
            Change64* change32 = FUN_004bfba0(base14->form, 1, 0);
            int count9 = baseContainer43->FUN_00482a90(base14->form);
            if (base14 && change32 && count9 <= 0)
                result1 = 0;
            else if ((count9 < 0 && change32) || (change32 && count9 + change32->FUN_00726070() <= 0) ||
                     (change32 && change32->FUN_00559450() && *change32->FUN_00559450()->FUN_006815c0() &&
                      (*change32->FUN_00559450()->FUN_006815c0())->FUN_00418750()))
                result1 = 0;
            else if (base14 && index14 == requested && (!change32 || (change32 && !change32->CountAndPruneEntries())))
            {
                result1 = new Change64;
                if (change32)
                {
                    if (count9 < 0)
                        result1->count = count9 + change32->count;
                    else
                        result1->count = count9 + change32->count - change32->FUN_004bc8f0(0);
                }
                else
                {
                    if (count9 < 0)
                        result1->count = count9 * -1;
                    else
                        result1->count = count9;
                }
                result1->FUN_00403550(base14->form);
                if (change32 &&
                    (change32->FUN_004bde40() || change32->FindFirstNonNegativeValue() >= 0 ||
                     change32->GetExtraForm() != FUN_00726070()) &&
                    change32->FUN_00559450() && change32->FUN_00559450()->FUN_005ae380())
                {
                    if (!result1->extras)
                        result1->extras = new ExtraNode64;
                    ExtraNode64* copyNode = change32->FUN_00559450();
                    while (copyNode && *copyNode->FUN_006815c0())
                    {
                        result1->extras->FUN_005ae3d0(*copyNode->FUN_006815c0());
                        copyNode = copyNode->FUN_00726070();
                    }
                }
            }
            else if (change32)
            {
                int variants = 0;
                if (change32->extras)
                    variants = change32->CountAndPruneEntries();
                if (requested < variants + index14)
                {
                    ExtraNode64* variantNode = change32->extras;
                    while (variantNode && *variantNode->FUN_006815c0() && !result1)
                    {
                        Extra64* extra = *variantNode->FUN_006815c0();
                        if (!extra->HasOnlyAllowedExtraData(0))
                        {
                            if (index14 == requested)
                            {
                                int extraCount = extra->FUN_00418770();
                                if (extraCount > count9 + change32->FUN_00726070())
                                    extraCount = count9 + change32->FUN_00726070();
                                result1 = new Change64(change32->form, extraCount);
                                result1->extras->FUN_005ae3d0(extra);
                            }
                            index14++;
                        }
                        variantNode = variantNode->FUN_00726070();
                    }
                }
                else
                {
                    index14 += change32->CountAndPruneEntries();
                    bool skip5 = false;
                    Form64* weapon109 = 0;
                    if (change32->FUN_0044ddc0()->FUN_00401170() == 0x28)
                        weapon109 = change32->FUN_0044ddc0();
                    if (!change32->FUN_004bc8f0(0) && change32->FUN_004bddd0(0) &&
                        (change32->count <= 0 || change32->FUN_0044ddc0()->FUN_00401170() == 0x29 ||
                         (weapon109 && (weapon109->FUN_00446390() == 10 || weapon109->FUN_00446390() == 11 ||
                                        weapon109->FUN_00446390() == 13))))
                        skip5 = true;
                    if (!skip5 && change32->FUN_004bc8f0(1) < count9 + change32->count &&
                        (!change32->FUN_004bcb70() || change32->FUN_00726070() <= count9))
                    {
                        if (index14 == requested)
                        {
                            result1 = new Change64;
                            if (change32)
                                result1->count = count9 + change32->count - change32->FUN_004bc8f0(0);
                            else
                                result1->count = count9;
                            result1->FUN_00403550(base14->form);
                            if (change32 && change32->FUN_004bde40() && change32->FUN_00559450() &&
                                change32->FUN_00559450()->FUN_005ae380())
                            {
                                if (!result1->extras)
                                    result1->extras = new ExtraNode64;
                                ExtraNode64* scriptNode = change32->FUN_00559450();
                                while (scriptNode && *scriptNode->FUN_006815c0())
                                {
                                    result1->extras->FUN_005ae3d0(*scriptNode->FUN_006815c0());
                                    scriptNode = scriptNode->FUN_00726070();
                                }
                            }
                        }
                        else
                            index14++;
                    }
                }
            }
            else
                index14++;
        }
        node48 = node48->FUN_00726070();
    }
    if (head1)
    {
        head1->FUN_00470470();
        delete head1;
    }
    if (!result1)
    {
        ChangeNode64* changeNode = changes;
        while (changeNode && *changeNode->FUN_006815c0() && !result1)
        {
            Change64* entry20 = *changeNode->FUN_006815c0();
            int baseCount13 = 0;
            if (FUN_004bffb0() && entry20)
                baseCount13 = FUN_004bffb0()->FUN_00482a90(entry20->form);
            if (baseCount13 < 0 && entry20->FUN_004bddd0(0))
                (*entry20->FUN_00559450()->FUN_006815c0())->FUN_00419ad0(baseCount13 * -1);
            if (entry20 && (entry20->count > 0 || baseCount13 < 0) &&
                ((entry20->FUN_00559450() && *entry20->FUN_00559450()->FUN_006815c0() &&
                  (*entry20->FUN_00559450()->FUN_006815c0())->FUN_00418750()) ||
                 baseCount13 < 0 || !FUN_004bffb0() || !FUN_004bffb0()->FUN_00481eb0(entry20->form)))
            {
                int sum34 = 0;
                ExtraNode64* sumNode15 = entry20->FUN_00559450();
                while (sumNode15 && *sumNode15->FUN_006815c0())
                {
                    Extra64* sumExtra = *sumNode15->FUN_006815c0();
                    if (!sumExtra->HasOnlyAllowedExtraData(0))
                    {
                        short sumCount = sumExtra->FUN_00418770();
                        if (sumCount > 0)
                            sum34 += sumCount;
                    }
                    sumNode15 = sumNode15->FUN_00726070();
                }
                if (entry20->FUN_00559450() && *entry20->FUN_00559450()->FUN_006815c0() &&
                    requested < index14 + entry20->CountAndPruneEntries())
                {
                    ExtraNode64* entryNode = entry20->extras;
                    while (entryNode && *entryNode->FUN_006815c0() && !result1)
                    {
                        Extra64* entryExtra = *entryNode->FUN_006815c0();
                        if (index14 == requested)
                        {
                            if (!entryExtra->HasOnlyAllowedExtraData(0))
                            {
                                short selectedCount = entryExtra->FUN_00418770();
                                if (selectedCount > 0)
                                {
                                    result1 = new Change64(entry20->form, selectedCount);
                                    result1->extras->FUN_005ae3d0(entryExtra);
                                }
                            }
                        }
                        else if (!entryExtra->HasOnlyAllowedExtraData(0) && entryExtra->FUN_00418770() > 0)
                            index14++;
                        entryNode = entryNode->FUN_00726070();
                    }
                }
                else if (entry20->FUN_00726070() == sum34)
                    index14 += entry20->CountAndPruneEntries();
                else
                {
                    int unused = 0;
                    if (entry20->FUN_00726070() > sum34)
                    {
                        int remainingVariants = entry20->CountAndPruneEntries();
                        if (remainingVariants > 0)
                            index14 += remainingVariants;
                    }
                    if (index14 == requested && !result1 && entry20->count - sum34 > 0)
                    {
                        Extra64* worn = 0;
                        result1 = new Change64(entry20->form, 0);
                        result1->count = entry20->count - sum34;
                        if (entry20->extras)
                        {
                            ExtraNode64* wornNode = entry20->extras;
                            while (wornNode && *wornNode->FUN_006815c0())
                            {
                                worn = *wornNode->FUN_006815c0();
                                if (!worn->FUN_00418ab0(0) && worn->HasOnlyAllowedExtraData(1))
                                    result1->extras->FUN_00905820(worn);
                                wornNode = wornNode->FUN_00726070();
                            }
                        }
                    }
                    else
                        index14++;
                }
            }
            changeNode = changeNode->FUN_00726070();
        }
    }
    return result1;
}

extern const char DAT_01020778[];

struct InventoryTrace4ca330
{
    unsigned int m_slot;
    InventoryTrace4ca330(int category, int enabled, const char* file, int line);
    ~InventoryTrace4ca330();
};

struct InventoryForm4ca330
{
    int FUN_00401170();
    int FUN_00446390();
};

struct InventoryExtra4ca330
{
    bool HasOnlyAllowedExtraData(int flag);
    bool FUN_00418ab0(int flag);
    short FUN_00418770();
    unsigned char FUN_00418750();
    void FUN_00419ad0(int count);
};

struct InventoryNode4ca330
{
    InventoryExtra4ca330** FUN_006815c0();
    InventoryNode4ca330* FUN_00726070();
    int FUN_005ae380();
};

struct InventoryRecord4ca330
{
    InventoryNode4ca330* m_extraList;
    InventoryForm4ca330* m_form;
    unsigned int m_flags;
};

struct InventoryChange4ca330
{
    InventoryNode4ca330* m_extraList;
    int m_quantity;
    InventoryForm4ca330* m_form;

    int CountAndPruneEntries();
    int FUN_004bc8f0(int ignoreEquipped);
    int FindFirstNonNegativeValue();
    int GetExtraForm();
    int FUN_004bde40();
    bool FUN_004bddd0(int flag);
    bool FUN_004bcb70();
    InventoryNode4ca330* FUN_00559450();
    InventoryForm4ca330* FUN_0044ddc0();
    int FUN_00726070();
};

struct InventoryContainer4ca330
{
    int FUN_00482a90(InventoryForm4ca330* form);
    bool FUN_00481eb0(InventoryForm4ca330* form);
};

struct InventoryList4ca330
{
    InventoryRecord4ca330** FUN_006815c0();
    InventoryList4ca330* FUN_00726070();
};

struct InventoryChangeNode4ca330
{
    InventoryChange4ca330** FUN_006815c0();
    InventoryChangeNode4ca330* FUN_00726070();
};

struct InventoryBaseHost4ca330
{
    InventoryChangeNode4ca330* first;
    InventoryChange4ca330* FUN_004bfba0(InventoryForm4ca330* form, int create, int unused);
    InventoryContainer4ca330* FUN_004bffb0();
    InventoryList4ca330* FUN_00726070();
};

struct InventoryOutputExtras4ca330
{
    void* m_pFirstNode;
    void* m_pTail;
    InventoryOutputExtras4ca330();
    void FUN_005ae3d0(InventoryExtra4ca330** extra);
    void FUN_00905820(InventoryExtra4ca330** extra);
};

struct InventoryOutput4ca330
{
    InventoryOutputExtras4ca330* m_extraList;
    int m_uiItemCount;
    InventoryForm4ca330* m_form;
    InventoryOutput4ca330();
    void FUN_00403550(InventoryForm4ca330* form);
};

struct InventoryOutputFromForm4ca330
{
    InventoryOutputExtras4ca330* m_extraList;
    int m_uiItemCount;
    InventoryForm4ca330* m_form;
    InventoryOutputFromForm4ca330(InventoryForm4ca330* form, int count);
};

struct InventoryCursor4ca330
{
    unsigned int m_uiContentCount;
    InventoryList4ca330* m_firstNode;
    unsigned int m_unknown08;
    InventoryOutput4ca330* m_pTileTemplate;
    InventoryContainer4ca330* m_sourceContainer;
    InventoryChangeNode4ca330* m_secondPhase;
    int m_phase;
    InventoryNode4ca330* m_activeExtras;
    InventoryNode4ca330* m_extrasToCount;
    InventoryNode4ca330* m_extrasToCopy;
};

// Advances the inventory cursor through its two phases and returns the next InventoryOutput4ca330 entry, or null when exhausted.
// @fnv 0x004ca330
Entry_004d4b00* Host_004d4b00::GetNextInventoryEntry(Iterator_004d4b00* apCursor)
{
    InventoryTrace4ca330 scope(0x36, 1, DAT_01020778, 0x19c9);
    ((InventoryCursor4ca330*)apCursor)->m_pTileTemplate = 0;
    if (((InventoryCursor4ca330*)apCursor)->m_phase == 0)
    {
        while (((InventoryCursor4ca330*)apCursor)->m_firstNode &&
               *((InventoryCursor4ca330*)apCursor)->m_firstNode->FUN_006815c0() &&
               !((InventoryCursor4ca330*)apCursor)->m_pTileTemplate)
        {
            InventoryRecord4ca330* pRecord = *((InventoryCursor4ca330*)apCursor)->m_firstNode->FUN_006815c0();
            InventoryForm4ca330* record = 0;
            bool advance = true;
            if (pRecord->m_form->FUN_00401170() == 0x34)
                record = pRecord->m_form;

            if (pRecord && !record)
            {
                InventoryChange4ca330* pChange = ((InventoryBaseHost4ca330*)this)->FUN_004bfba0(pRecord->m_form, 1, 0);
                int change = ((InventoryCursor4ca330*)apCursor)->m_sourceContainer->FUN_00482a90(pRecord->m_form);

                if (pRecord && pChange && change <= 0)
                {
                    ((InventoryCursor4ca330*)apCursor)->m_pTileTemplate = 0;
                }
                else
                {
                    if ((change < 0 && pChange) || (pChange && pChange->FUN_00726070() + change <= 0) ||
                        (pChange && pChange->FUN_00559450() && *pChange->FUN_00559450()->FUN_006815c0() &&
                         (*pChange->FUN_00559450()->FUN_006815c0())->FUN_00418750()))
                    {
                        ((InventoryCursor4ca330*)apCursor)->m_pTileTemplate = 0;
                    }
                    else if (pRecord && (!pChange || (pChange && !pChange->CountAndPruneEntries())))
                    {
                        ((InventoryCursor4ca330*)apCursor)->m_pTileTemplate = new InventoryOutput4ca330;
                        if (pChange)
                        {
                            if (change < 0)
                                ((InventoryCursor4ca330*)apCursor)->m_pTileTemplate->m_uiItemCount =
                                    change + pChange->m_quantity;
                            else
                                ((InventoryCursor4ca330*)apCursor)->m_pTileTemplate->m_uiItemCount =
                                    change + pChange->m_quantity - pChange->FUN_004bc8f0(0);
                        }
                        else if (change < 0)
                        {
                            ((InventoryCursor4ca330*)apCursor)->m_pTileTemplate->m_uiItemCount = change * -1;
                        }
                        else
                        {
                            ((InventoryCursor4ca330*)apCursor)->m_pTileTemplate->m_uiItemCount = change;
                        }
                        ((InventoryCursor4ca330*)apCursor)->m_pTileTemplate->FUN_00403550(pRecord->m_form);

                        if (pChange &&
                            (pChange->FUN_004bde40() || pChange->FindFirstNonNegativeValue() >= 0 ||
                             pChange->GetExtraForm() != (int)((InventoryBaseHost4ca330*)this)->FUN_00726070()))
                        {
                            if (pChange->FUN_00559450() && pChange->FUN_00559450()->FUN_005ae380())
                            {
                                if (!((InventoryCursor4ca330*)apCursor)->m_pTileTemplate->m_extraList)
                                    ((InventoryCursor4ca330*)apCursor)->m_pTileTemplate->m_extraList =
                                        new InventoryOutputExtras4ca330;
                                InventoryNode4ca330* pExtraNode = pChange->FUN_00559450();
                                while (pExtraNode && *pExtraNode->FUN_006815c0())
                                {
                                    ((InventoryCursor4ca330*)apCursor)
                                        ->m_pTileTemplate->m_extraList->FUN_005ae3d0(pExtraNode->FUN_006815c0());
                                    pExtraNode = pExtraNode->FUN_00726070();
                                }
                            }
                        }
                    }
                    else if (pChange)
                    {
                        int count = 0;
                        if (pChange->m_extraList)
                            count = pChange->CountAndPruneEntries();
                        if (!((InventoryCursor4ca330*)apCursor)->m_activeExtras)
                            ((InventoryCursor4ca330*)apCursor)->m_activeExtras = pChange->m_extraList;
                        while (((InventoryCursor4ca330*)apCursor)->m_activeExtras &&
                               *((InventoryCursor4ca330*)apCursor)->m_activeExtras->FUN_006815c0() &&
                               !((InventoryCursor4ca330*)apCursor)->m_pTileTemplate)
                        {
                            InventoryExtra4ca330* extra =
                                *((InventoryCursor4ca330*)apCursor)->m_activeExtras->FUN_006815c0();
                            if (!extra->HasOnlyAllowedExtraData(0))
                            {
                                int quantity = extra->FUN_00418770();
                                if (quantity > pChange->FUN_00726070() + change)
                                    quantity = pChange->FUN_00726070() + change;
                                ((InventoryCursor4ca330*)apCursor)->m_pTileTemplate =
                                    (InventoryOutput4ca330*)new InventoryOutputFromForm4ca330(pChange->m_form,
                                                                                              quantity);
                                ((InventoryOutputExtras4ca330*)((InventoryCursor4ca330*)apCursor)
                                     ->m_pTileTemplate->m_extraList)
                                    ->FUN_005ae3d0(&extra);
                            }
                            ((InventoryCursor4ca330*)apCursor)->m_activeExtras =
                                ((InventoryCursor4ca330*)apCursor)->m_activeExtras->FUN_00726070();
                        }
                        advance = !((InventoryCursor4ca330*)apCursor)->m_activeExtras ||
                                  !*((InventoryCursor4ca330*)apCursor)->m_activeExtras->FUN_006815c0();
                    }
                    else
                    {
                        pChange->CountAndPruneEntries();
                        bool skipItem = false;
                        InventoryForm4ca330* form = 0;
                        if (pChange->FUN_0044ddc0()->FUN_00401170() == 0x28)
                            form = pChange->FUN_0044ddc0();
                        if (!pChange->FUN_004bc8f0(0) && pChange->FUN_004bddd0(0))
                        {
                            if ((pChange->m_quantity <= 0 || pChange->FUN_0044ddc0()->FUN_00401170() == 0x29) ||
                                (form && (form->FUN_00446390() == 0xa || form->FUN_00446390() == 0xb ||
                                          form->FUN_00446390() == 0xd)))
                                skipItem = true;
                        }
                        if (!skipItem && pChange->FUN_004bc8f0(1) < (change + pChange->m_quantity) &&
                            (!pChange->FUN_004bcb70() || (int)pChange->FUN_00726070() <= change))
                        {
                            ((InventoryCursor4ca330*)apCursor)->m_pTileTemplate = new InventoryOutput4ca330;
                            if (pChange)
                                ((InventoryCursor4ca330*)apCursor)->m_pTileTemplate->m_uiItemCount =
                                    change + pChange->m_quantity - pChange->FUN_004bc8f0(0);
                            else
                                ((InventoryCursor4ca330*)apCursor)->m_pTileTemplate->m_uiItemCount = change;
                            ((InventoryCursor4ca330*)apCursor)->m_pTileTemplate->FUN_00403550(pRecord->m_form);
                            if (pChange && pChange->FUN_004bde40() && pChange->FUN_00559450() &&
                                pChange->FUN_00559450()->FUN_005ae380())
                            {
                                if (!((InventoryCursor4ca330*)apCursor)->m_pTileTemplate->m_extraList)
                                    ((InventoryCursor4ca330*)apCursor)->m_pTileTemplate->m_extraList =
                                        new InventoryOutputExtras4ca330;
                                InventoryNode4ca330* extraNode = pChange->FUN_00559450();
                                while (extraNode && *extraNode->FUN_006815c0())
                                {
                                    ((InventoryCursor4ca330*)apCursor)
                                        ->m_pTileTemplate->m_extraList->FUN_005ae3d0(extraNode->FUN_006815c0());
                                    extraNode = extraNode->FUN_00726070();
                                }
                            }
                        }
                    }
                }
            }
            if (advance)
                ((InventoryCursor4ca330*)apCursor)->m_firstNode =
                    ((InventoryCursor4ca330*)apCursor)->m_firstNode->FUN_00726070();
        }
        if (!((InventoryCursor4ca330*)apCursor)->m_pTileTemplate)
        {
            ((InventoryCursor4ca330*)apCursor)->m_phase = 1;
            ((InventoryCursor4ca330*)apCursor)->m_secondPhase = ((InventoryBaseHost4ca330*)this)->first;
        }
    }
    if (((InventoryCursor4ca330*)apCursor)->m_phase == 1 && !((InventoryCursor4ca330*)apCursor)->m_pTileTemplate)
    {
        while (((InventoryCursor4ca330*)apCursor)->m_secondPhase &&
               *((InventoryCursor4ca330*)apCursor)->m_secondPhase->FUN_006815c0() &&
               !((InventoryCursor4ca330*)apCursor)->m_pTileTemplate)
        {
            bool count = true;
            InventoryChange4ca330* pChange = *((InventoryCursor4ca330*)apCursor)->m_secondPhase->FUN_006815c0();
            int advance = 0;
            if (((InventoryBaseHost4ca330*)this)->FUN_004bffb0() && pChange)
                advance = ((InventoryBaseHost4ca330*)this)->FUN_004bffb0()->FUN_00482a90(pChange->m_form);
            if (advance < 0 && pChange->FUN_004bddd0(0))
                (*pChange->FUN_00559450()->FUN_006815c0())->FUN_00419ad0(advance * -1);
            if (pChange && (pChange->m_quantity > 0 || advance < 0))
            {
                if ((pChange->FUN_00559450() && *pChange->FUN_00559450()->FUN_006815c0() &&
                     (*pChange->FUN_00559450()->FUN_006815c0())->FUN_00418750()) ||
                    advance < 0 || !((InventoryBaseHost4ca330*)this)->FUN_004bffb0() ||
                    !((InventoryBaseHost4ca330*)this)->FUN_004bffb0()->FUN_00481eb0(pChange->m_form))
                {
                    int total = 0;
                    if (!((InventoryCursor4ca330*)apCursor)->m_extrasToCount)
                        ((InventoryCursor4ca330*)apCursor)->m_extrasToCount = pChange->FUN_00559450();
                    while (((InventoryCursor4ca330*)apCursor)->m_extrasToCount &&
                           *((InventoryCursor4ca330*)apCursor)->m_extrasToCount->FUN_006815c0())
                    {
                        InventoryExtra4ca330* extra =
                            *((InventoryCursor4ca330*)apCursor)->m_extrasToCount->FUN_006815c0();
                        if (!extra->HasOnlyAllowedExtraData(0))
                        {
                            short extraCount = extra->FUN_00418770();
                            if (extraCount > 0)
                                total += extraCount;
                        }
                        ((InventoryCursor4ca330*)apCursor)->m_extrasToCount =
                            ((InventoryCursor4ca330*)apCursor)->m_extrasToCount->FUN_00726070();
                    }
                    ((InventoryCursor4ca330*)apCursor)->m_extrasToCount = 0;
                    if (pChange->FUN_00559450() && *pChange->FUN_00559450()->FUN_006815c0() &&
                        (!pChange->CountAndPruneEntries() || true))
                    {
                        if (!((InventoryCursor4ca330*)apCursor)->m_extrasToCopy)
                            ((InventoryCursor4ca330*)apCursor)->m_extrasToCopy = pChange->m_extraList;
                        while (((InventoryCursor4ca330*)apCursor)->m_extrasToCopy &&
                               *((InventoryCursor4ca330*)apCursor)->m_extrasToCopy->FUN_006815c0() &&
                               !((InventoryCursor4ca330*)apCursor)->m_pTileTemplate)
                        {
                            InventoryExtra4ca330* extra =
                                *((InventoryCursor4ca330*)apCursor)->m_extrasToCopy->FUN_006815c0();
                            if (!extra->HasOnlyAllowedExtraData(0))
                            {
                                short quantity = extra->FUN_00418770();
                                if (quantity > 0)
                                {
                                    ((InventoryCursor4ca330*)apCursor)->m_pTileTemplate =
                                        (InventoryOutput4ca330*)new InventoryOutputFromForm4ca330(pChange->m_form,
                                                                                                  quantity);
                                    ((InventoryCursor4ca330*)apCursor)
                                        ->m_pTileTemplate->m_extraList->FUN_005ae3d0(&extra);
                                }
                            }
                            ((InventoryCursor4ca330*)apCursor)->m_extrasToCopy =
                                ((InventoryCursor4ca330*)apCursor)->m_extrasToCopy->FUN_00726070();
                        }
                        count = !((InventoryCursor4ca330*)apCursor)->m_extrasToCopy ||
                                !*((InventoryCursor4ca330*)apCursor)->m_extrasToCopy->FUN_006815c0();
                    }
                    else if ((int)pChange->FUN_00726070() == total)
                    {
                        pChange->CountAndPruneEntries();
                    }
                    if (!((InventoryCursor4ca330*)apCursor)->m_pTileTemplate)
                    {
                        int unusedCount = 0;
                        if (pChange->FUN_00726070() > total)
                        {
                            int extraCount = pChange->CountAndPruneEntries();
                        }
                        if (!((InventoryCursor4ca330*)apCursor)->m_pTileTemplate && (pChange->m_quantity - total) > 0)
                        {
                            InventoryExtra4ca330* residualExtra = 0;
                            ((InventoryCursor4ca330*)apCursor)->m_pTileTemplate =
                                (InventoryOutput4ca330*)new InventoryOutputFromForm4ca330(pChange->m_form, 0);
                            ((InventoryCursor4ca330*)apCursor)->m_pTileTemplate->m_uiItemCount =
                                pChange->m_quantity - total;
                            if (pChange->m_extraList)
                            {
                                InventoryNode4ca330* extraNode = pChange->m_extraList;
                                while (extraNode && *extraNode->FUN_006815c0())
                                {
                                    residualExtra = *extraNode->FUN_006815c0();
                                    if (!residualExtra->FUN_00418ab0(0) && residualExtra->HasOnlyAllowedExtraData(1))
                                        ((InventoryCursor4ca330*)apCursor)
                                            ->m_pTileTemplate->m_extraList->FUN_00905820(&residualExtra);
                                    extraNode = extraNode->FUN_00726070();
                                }
                            }
                        }
                    }
                }
            }
            if (count)
                ((InventoryCursor4ca330*)apCursor)->m_secondPhase =
                    ((InventoryCursor4ca330*)apCursor)->m_secondPhase->FUN_00726070();
        }
    }
    return (Entry_004d4b00*)((InventoryCursor4ca330*)apCursor)->m_pTileTemplate;
}

struct Obj4cb320;
bool __cdecl IsCountable4cb320(Obj4cb320* apObj);
struct ContEntry4cb320
{
    int count;
    Obj4cb320* pObj;
};
struct ContNode4cb320
{
    bool IsEmpty();
    ContEntry4cb320** GetItem();
    ContNode4cb320* GetNext();
};
struct Cont4cb320
{
    ContNode4cb320* GetHead();
    bool HasObjectOfType(Obj4cb320*);
};
struct Change4cb320
{
    void* pExtraLists;
    int m_iCountChange;
    Obj4cb320* pObj;
    int GetCount();
};
struct ChangeNode4cb320
{
    bool IsEmpty();
    Change4cb320** GetItem();
    ChangeNode4cb320* GetNext();
};
struct Inv4cb320
{
    ChangeNode4cb320* m_pEntryList;
    Cont4cb320* GetContainer();
    Change4cb320* FindChange(Obj4cb320*, int, int);
    int GetCountableItemCount();
};

// @fnv 0x004cb320
int Inv4cb320::GetCountableItemCount()
{
    Obj4cb320* pObj7 = 0;
    int iTotal = 0;
    Cont4cb320* pCont3 = GetContainer();
    ContNode4cb320* pNode = pCont3 ? pCont3->GetHead() : 0;
    while (pNode && !pNode->IsEmpty())
    {
        pObj7 = (*pNode->GetItem())->pObj;
        if (pObj7 && IsCountable4cb320(pObj7))
        {
            Change4cb320* pChange = FindChange(pObj7, 1, 0);
            if (pChange)
            {
                iTotal += pChange->GetCount() + (*pNode->GetItem())->count;
            }
            else
            {
                if ((iTotal += (*pNode->GetItem())->count) < 0)
                    iTotal = iTotal * -1;
            }
        }
        pNode = pNode->GetNext();
    }
    ChangeNode4cb320* pChangeNode4 = m_pEntryList;
    while (pChangeNode4 && !pChangeNode4->IsEmpty())
    {
        pObj7 = (*pChangeNode4->GetItem())->pObj;
        if (pObj7 && IsCountable4cb320(pObj7))
        {
            if (!pCont3 || (!pCont3->HasObjectOfType(pObj7) && (*pChangeNode4->GetItem())->GetCount() > 0))
                iTotal += (*pChangeNode4->GetItem())->GetCount();
        }
        pChangeNode4 = pChangeNode4->GetNext();
    }
    return iTotal;
}

struct CO4cb4b0
{
    int count;
    TESObject* pObj;
};
struct CN4cb4b0
{
    bool _ref_008256d0();
    CO4cb4b0** _ref_006815c0();
    CN4cb4b0* _ref_00726070();
};
struct Cont4cb4b0
{
    CN4cb4b0* _ref_00717e50();
};
struct IC4cb4b0
{
    int unk00;
    int count;
    TESObject* pObj;
};
struct IN4cb4b0
{
    bool _ref_008256d0();
    IC4cb4b0** _ref_006815c0();
    IN4cb4b0* _ref_00726070();
};
bool __cdecl FUN_00481f10(TESObject*);
struct Inv4cb4b0
{
    IN4cb4b0* m_pEntryList;
    Cont4cb4b0* _ref_004bffb0();
    void _ref_004c37d0(int, TESObject*, int, int, int, int, int, int, int, int, int, int);
    void FUN_004cb4b0(int a1, int a2, int a3);
};

// @fnv 0x004cb4b0
void Inv4cb4b0::FUN_004cb4b0(int a1, int a2, int a3)
{
    TESObject* pObj = 0;
    Cont4cb4b0* pCont3 = _ref_004bffb0();
    CN4cb4b0* pNode2 = pCont3 ? pCont3->_ref_00717e50() : 0;
    while (pNode2 && !pNode2->_ref_008256d0())
    {
        pObj = (*pNode2->_ref_006815c0())->pObj;
        if (pObj && FUN_00481f10(pObj))
        {
            _ref_004c37d0(a1, pObj, 0, a2, 0, 0, a3, 0, 0, 1, 0, 0);
            return;
        }
        pNode2 = pNode2->_ref_00726070();
    }
    IN4cb4b0* pItem = m_pEntryList;
    while (pItem && !pItem->_ref_008256d0())
    {
        pObj = (*pItem->_ref_006815c0())->pObj;
        if (pObj && FUN_00481f10(pObj))
        {
            _ref_004c37d0(a1, pObj, 0, a2, 0, 0, a3, 0, 0, 1, 0, 0);
            return;
        }
        pItem = pItem->_ref_00726070();
    }
}

namespace InventoryCopy {
struct FUN_004bc550;
typedef FUN_004bc550 Item;
struct FUN_00410360;
typedef FUN_00410360 Extra;
struct ExtraNode;
struct BaseNode;
struct ItemNode;
struct Container;
struct Inventory;
struct FormView
{
    int FUN_00401170();
};
struct CopiedForm
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
    virtual void v100();
    virtual void v104();
    virtual void v108(TESBoundObject*);
};
struct FUN_00410360
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    FUN_00410360();
    static void* operator new(unsigned int);
    static void operator delete(void*);
    void* GetExtraData(int);
    void RemoveExtra(void*, int);
    void CopyListForContainer(FUN_00410360*, int);
    void AddExtra(void*);
};
typedef FUN_00410360 Extra;
struct ExtraNode
{
    Extra** FUN_006815c0();
    ExtraNode* FUN_00726070();
    int FUN_005ae380();
    void FUN_00905820(Extra**);
};
struct FUN_004bc550
{
    ExtraNode* list;
    int count;
    TESBoundObject* form;
    FUN_004bc550(TESBoundObject*, int);
    static void* operator new(unsigned int);
    static void operator delete(void*);
    int FUN_00726070();
    ExtraNode* FUN_00559450();
    TESBoundObject* FUN_0044ddc0();
    void FUN_004bcd10();
    void* FUN_004bde40();
};
typedef FUN_004bc550 Item;
struct BaseEntry
{
    int count;
    TESBoundObject* form;
};
struct BaseNode
{
    BaseEntry** FUN_006815c0();
    bool FUN_008256d0();
    BaseNode* FUN_00726070();
};
struct ItemNode
{
    Item** FUN_006815c0();
    bool FUN_008256d0();
    ItemNode* FUN_00726070();
};
struct Container
{
    BaseNode* FUN_00717e50();
    int FUN_00482a90(TESBoundObject*);
};
struct Registry
{
    void FUN_004603b0(CopiedForm*);
    void FUN_00861780(CopiedForm*);
};
extern Registry* DAT_011c3f2c;
extern Registry* DAT_011de45c;
Inventory* __cdecl FUN_004bf220(void*);
void* __cdecl FUN_004826d0(TESBoundObject*);
CopiedForm* __cdecl FUN_00465110(int);
void __cdecl FUN_004ce300(CopiedForm*, int);
struct Inventory
{
    ItemNode* head;
    Container* FUN_004bffb0();
    Item* FUN_004bfba0(TESBoundObject*, int, int);
    void FUN_004c3380(Item*, int);
    void FUN_004cd9c0(void*, void*);
};
// @fnv 0x004cd9c0
void Inventory::FUN_004cd9c0(void* source, void* destination)
{
    if (!destination || !source)
        return;
    TESBoundObject* formSlot11 = 0;
    Item* copySlot14 = 0;
    Inventory* targetSlot4 = 0;
    targetSlot4 = FUN_004bf220(destination);
    if (!targetSlot4)
        return;
    BaseNode* baseSlot45 = FUN_004bffb0()->FUN_00717e50();
    TESLevItem* leveledSlot24 = 0;
    while (baseSlot45 && !baseSlot45->FUN_008256d0())
    {
        formSlot11 = (*baseSlot45->FUN_006815c0())->form;
        leveledSlot24 = dynamic_cast<TESLevItem*>((*baseSlot45->FUN_006815c0())->form);
        if (formSlot11)
        {
            int baseCountSlot31 = FUN_004bffb0()->FUN_00482a90(formSlot11);
            Item* itemSlot25 = FUN_004bfba0(formSlot11, 1, 0);
            int totalSlot2 = 0;
            int magnitudeSlot60 = baseCountSlot31;
            if (magnitudeSlot60 < 0)
                magnitudeSlot60 *= -1;
            if (itemSlot25)
                totalSlot2 += magnitudeSlot60 + itemSlot25->FUN_00726070();
            else
                totalSlot2 += magnitudeSlot60;
            if (totalSlot2 > 0)
            {
                CopiedForm* clone = 0;
                if (FUN_004826d0(formSlot11))
                {
                    clone = FUN_00465110(((FormView*)formSlot11)->FUN_00401170());
                    clone->v108(formSlot11);
                    FUN_004ce300(clone, 0);
                    DAT_011c3f2c->FUN_004603b0(clone);
                    DAT_011de45c->FUN_00861780(clone);
                    int quantity = baseCountSlot31;
                    if (itemSlot25)
                        quantity += itemSlot25->FUN_00726070();
                    copySlot14 = new Item((TESBoundObject*)clone, quantity);

                    if (itemSlot25 && itemSlot25->FUN_00559450() && itemSlot25->FUN_00559450()->FUN_005ae380())
                    {
                        ExtraNode* nodeA = itemSlot25->FUN_00559450();
                        if (nodeA && *nodeA->FUN_006815c0())
                        {
                            while (nodeA && *nodeA->FUN_006815c0())
                            {
                                Extra* extraASlot11 = new Extra;
                                void* removedASlot21 = (*nodeA->FUN_006815c0())->GetExtraData(0xd);
                                if (removedASlot21)
                                    (*nodeA->FUN_006815c0())->RemoveExtra(removedASlot21, 0);
                                extraASlot11->CopyListForContainer(*nodeA->FUN_006815c0(), 1);
                                copySlot14->FUN_00559450()->FUN_00905820(&extraASlot11);
                                if (removedASlot21)
                                    (*nodeA->FUN_006815c0())->AddExtra(removedASlot21);
                                nodeA = nodeA->FUN_00726070();
                            }
                        }
                    }
                }
                else
                {
                    copySlot14 = new Item(formSlot11, totalSlot2);
                    if (itemSlot25 && itemSlot25->FUN_00559450() && itemSlot25->FUN_00559450()->FUN_005ae380())
                    {
                        ExtraNode* nodeB = itemSlot25->FUN_00559450();
                        if (nodeB && *nodeB->FUN_006815c0())
                        {
                            while (nodeB && *nodeB->FUN_006815c0())
                            {
                                Extra* extraB = new Extra;
                                extraB->CopyListForContainer(*nodeB->FUN_006815c0(), 1);
                                copySlot14->FUN_00559450()->FUN_00905820(&extraB);
                                nodeB = nodeB->FUN_00726070();
                            }
                        }
                    }
                }
                targetSlot4->FUN_004c3380(copySlot14, 1);
            }
        }
        baseSlot45 = baseSlot45->FUN_00726070();
    }
    Item* changedSlot20 = 0;
    ItemNode* nodeSlot26 = head;
    while (nodeSlot26 && !nodeSlot26->FUN_008256d0())
    {
        changedSlot20 = *nodeSlot26->FUN_006815c0();
        if (changedSlot20 && changedSlot20->FUN_00726070() > 0)
        {
            formSlot11 = changedSlot20->FUN_0044ddc0();
            changedSlot20->FUN_004bcd10();
            CopiedForm* clone2 = 0;
            if (changedSlot20->FUN_004bde40())
            {
                clone2 = FUN_00465110(((FormView*)changedSlot20->FUN_0044ddc0())->FUN_00401170());
                clone2->v108(changedSlot20->FUN_0044ddc0());
                FUN_004ce300(clone2, 0);
                DAT_011c3f2c->FUN_004603b0(clone2);
                DAT_011de45c->FUN_00861780(clone2);
                copySlot14 = new Item((TESBoundObject*)clone2, changedSlot20->FUN_00726070());
                if (changedSlot20 && changedSlot20->FUN_00559450() && changedSlot20->FUN_00559450()->FUN_005ae380())
                {
                    ExtraNode* nodeC = changedSlot20->FUN_00559450();
                    if (nodeC && *nodeC->FUN_006815c0())
                    {
                        while (nodeC && *nodeC->FUN_006815c0())
                        {
                            Extra* extraCSlot22 = new Extra;
                            void* removedCSlot8 = (*nodeC->FUN_006815c0())->GetExtraData(0xd);
                            if (removedCSlot8)
                                (*nodeC->FUN_006815c0())->RemoveExtra(removedCSlot8, 0);
                            extraCSlot22->CopyListForContainer(*nodeC->FUN_006815c0(), 1);
                            copySlot14->FUN_00559450()->FUN_00905820(&extraCSlot22);
                            if (removedCSlot8)
                                (*nodeC->FUN_006815c0())->AddExtra(removedCSlot8);
                            nodeC = nodeC->FUN_00726070();
                        }
                    }
                }
            }
            else
            {
                copySlot14 = new Item(changedSlot20->FUN_0044ddc0(), changedSlot20->FUN_00726070());
                if (changedSlot20 && changedSlot20->FUN_00559450() && changedSlot20->FUN_00559450()->FUN_005ae380())
                {
                    ExtraNode* nodeD = changedSlot20->FUN_00559450();
                    if (nodeD && *nodeD->FUN_006815c0())
                    {
                        while (nodeD && *nodeD->FUN_006815c0())
                        {
                            Extra* extraD = new Extra;
                            extraD->CopyListForContainer(*nodeD->FUN_006815c0(), 1);
                            copySlot14->FUN_00559450()->FUN_00905820(&extraD);
                            nodeD = nodeD->FUN_00726070();
                        }
                    }
                }
            }
            targetSlot4->FUN_004c3380(copySlot14, 1);
            copySlot14 = 0;
        }
        nodeSlot26 = nodeSlot26->FUN_00726070();
    }
}
}

extern float DAT_010162c0;
struct MoveForm
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual bool IsQuestItem();
    int FUN_00401170();
};
struct MoveOwner;
struct MoveOwnershipProxy
{
    void* FUN_004216f0();
};
struct MoveExtra
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    MoveExtra();
    static void* operator new(unsigned int);
    static void operator delete(void*);
    unsigned int ItemsInList();
    void* FUN_00418660();
    short FUN_00418770();
    void FUN_00419700(void*);
    void FUN_0041aed0();
    void FUN_00419ad0(unsigned short);
};
struct MoveExtraNode
{
    MoveExtra** FUN_006815c0();
    MoveExtraNode* FUN_00726070();
    bool FUN_008256d0();
    void FUN_0063f7b0();
    void FUN_00470470();
    unsigned int FUN_005ae380();
    ~MoveExtraNode();
    static void operator delete(void*);
};
struct MoveItem
{
    MoveExtraNode* head;
    int count;
    TESBoundObject* form;
    MoveItem(TESBoundObject*, int);
    static void* operator new(unsigned int);
    static void operator delete(void*);
    bool FUN_004bddd0(bool);
    bool FUN_004bcb70();
    int FUN_00726070();
    MoveExtraNode* FUN_00559450();
    TESBoundObject* FUN_0044ddc0();
    void FUN_004bd5c0(void*);
};
struct MoveItemNode
{
    bool FUN_008256d0();
    MoveItem** FUN_006815c0();
    MoveItemNode* FUN_00726070();
};
struct MoveBaseEntry
{
    int count;
    TESBoundObject* form;
};
struct MoveBaseNode
{
    bool FUN_008256d0();
    MoveBaseEntry** FUN_006815c0();
    MoveBaseNode* FUN_00726070();
};
struct MoveContainer
{
    MoveBaseNode* FUN_00717e50();
    int FUN_00482a90(TESBoundObject*);
    bool FUN_00481eb0(TESBoundObject*);
};
struct MoveOwner
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9c();
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    virtual void slotc0();
    virtual void slotc4();
    virtual void slotc8();
    virtual void slotcc();
    virtual void slotd0();
    virtual void slotd4();
    virtual void slotd8();
    virtual void slotdc();
    virtual void slote0();
    virtual void slote4();
    virtual void slote8();
    virtual void slotec();
    virtual void slotf0();
    virtual void slotf4();
    virtual void slotf8();
    virtual void slotfc();
    virtual bool IsActor();
    MoveOwnershipProxy* FUN_005d43c0();
    void* FUN_007af430();
    void* FUN_00567790();
    unsigned int FUN_008adcf0(TESBoundObject*, bool, bool);
};
extern MoveOwner* inventoryPlayer;
struct MoveFilterResult
{
    bool FUN_005f65d0();
};
struct MoveFilter
{
    MoveFilterResult* FUN_00500940(TESForm* const&);
};
struct MoveFormInfo
{
    bool FUN_00480d90();
};
MoveFormInfo* FUN_00480db0(TESBoundObject*);
bool FUN_00481f10(TESBoundObject*);
int FUN_0048e8a0(TESBoundObject*);
struct MoveString
{
    char* text;
    unsigned short length, capacity;
    MoveString();
    ~MoveString();
    const char* FUN_00559450();
};
struct MoveSetting
{
    const char* FUN_00403df0();
};
extern MoveSetting movePlural, moveVerb;
const char* FUN_00482720(TESBoundObject*);
void FUN_00406f60(MoveString*, const char*, ...);
void DispatchMessageToSink(const char*, int, const char*, unsigned int, float, int);
void FUN_00704af0();
struct InventoryMove
{
    MoveItemNode* head;
    MoveContainer* FUN_004bffb0();
    MoveItem* FUN_004bfba0(TESBoundObject*, int, int);
    void FUN_004c0cf0(bool*, TESBoundObject*, int, MoveOwner*, MoveExtra*, bool, bool, MoveItem*, bool*);
    void FUN_004c37d0(MoveOwner*, TESBoundObject*, bool, int, MoveExtra*, int, MoveOwner*, int, int, bool, int,
                      MoveItem*);
    float FUN_004ce380(MoveOwner*, MoveOwner*, bool, bool, bool, bool, int, MoveFilter*);
};
// Iterates the container's base entries and item list, moving matching items to the destination owner and returning the accumulated weight.
// @fnv 0x004ce380
float InventoryMove::FUN_004ce380(MoveOwner* owner, MoveOwner* destination, bool retainOwner, bool SetOwnerPointer,
                                  bool clearOwner, bool silent, int type, MoveFilter* filter)
{
    TESBoundObject* form3 = 0;
    float weight7 = 0.0f;
    bool skipQuest3 = false;
    bool filtered8 = false;
    if (filter)
        filtered8 = true;
    MoveBaseNode* base5 = FUN_004bffb0()->FUN_00717e50();
    TESLevItem* leveled5 = 0;
    while (base5 && !base5->FUN_008256d0())
    {
        form3 = (*base5->FUN_006815c0())->form;
        leveled5 = dynamic_cast<TESLevItem*>((*base5->FUN_006815c0())->form);
        MoveFormInfo* infoScope1 = FUN_00480db0(form3);
        if ((filtered8 && filter->FUN_00500940(reinterpret_cast<TESForm*>(form3))->FUN_005f65d0()) ||
            (type > -1 && form3 && reinterpret_cast<MoveForm*>(form3)->FUN_00401170() != type))
        {
            base5 = base5->FUN_00726070();
            continue;
        }
        if (reinterpret_cast<MoveForm*>(form3)->IsQuestItem() && owner == inventoryPlayer)
        {
            MoveItem* quest = FUN_004bfba0(form3, 1, 0);
            if (quest && quest->FUN_004bddd0(false))
            {
                int baseCountScope1 = FUN_004bffb0()->FUN_00482a90((*base5->FUN_006815c0())->form);
                int countScope9 = quest->FUN_00726070() + baseCountScope1;
                bool removedScope4 = false;
                FUN_004c0cf0(&removedScope4, form3, countScope9, owner, 0, false, false, 0, 0);
            }
        }
        else if (form3 && !leveled5 && (!infoScope1 || infoScope1->FUN_00480d90()))
        {
            MoveItem* itemScope1 = FUN_004bfba0(form3, 1, 0);
            if (!itemScope1 || !itemScope1->FUN_004bcb70())
            {
                int countScope2 = 0;
                int baseCountScope2 = FUN_004bffb0()->FUN_00482a90((*base5->FUN_006815c0())->form);
                if (baseCountScope2 < 0)
                    baseCountScope2 *= -1;
                if (itemScope1)
                    countScope2 += itemScope1->FUN_00726070() + baseCountScope2;
                else
                    countScope2 += baseCountScope2;
                if (countScope2 > 0)
                {
                    weight7 += static_cast<float>(FUN_0048e8a0(form3) * countScope2);
                    bool changed2 = false;
                    if (itemScope1 && itemScope1->FUN_00559450() && itemScope1->FUN_00559450()->FUN_005ae380())
                    {
                        MoveExtraNode* nodeScope1 = itemScope1->FUN_00559450();
                        if (nodeScope1 && *nodeScope1->FUN_006815c0())
                        {
                            bool lastScope1 = false;
                            while (nodeScope1 && *nodeScope1->FUN_006815c0() && !lastScope1)
                            {
                                MoveExtra* extraScope1 = *nodeScope1->FUN_006815c0();
                                if (extraScope1->ItemsInList() < 1)
                                {
                                    nodeScope1->FUN_0063f7b0();
                                    if (nodeScope1->FUN_008256d0())
                                    {
                                        nodeScope1->FUN_00470470();
                                        delete nodeScope1;
                                        nodeScope1 = 0;
                                        itemScope1->head = 0;
                                    }
                                    else
                                        nodeScope1 = itemScope1->FUN_00559450();
                                }
                                else
                                {
                                    bool restartScope1 = false;
                                    if (itemScope1->FUN_00559450()->FUN_005ae380() <= 1)
                                        lastScope1 = true;
                                    else
                                        restartScope1 = true;
                                    void* ownershipScope5 = 0;
                                    if (owner->IsActor())
                                    {
                                        void* actorOwnerScope1 = 0;
                                        actorOwnerScope1 = owner->FUN_005d43c0()->FUN_004216f0();
                                        if (!actorOwnerScope1)
                                            actorOwnerScope1 = owner->FUN_007af430();
                                        ownershipScope5 = actorOwnerScope1;
                                    }
                                    else
                                        ownershipScope5 = owner->FUN_00567790();
                                    if ((retainOwner || SetOwnerPointer) && !FUN_00481f10(form3))
                                    {
                                        if (!extraScope1->FUN_00418660())
                                            extraScope1->FUN_00419700(ownershipScope5);
                                    }
                                    else if (clearOwner)
                                    {
                                        int sizeScope1 = extraScope1->ItemsInList();
                                        if (extraScope1->FUN_00418660() &&
                                            ((extraScope1->FUN_00418770() > 1 && sizeScope1 <= 2) || sizeScope1 <= 1))
                                        {
                                            extraScope1->FUN_0041aed0();
                                            extraScope1 = 0;
                                        }
                                        else
                                            extraScope1->FUN_0041aed0();
                                    }
                                    countScope2 -= extraScope1->FUN_00418770();
                                    if (!itemScope1->FUN_004bddd0(false))
                                        FUN_004c37d0(owner, form3, retainOwner, extraScope1->FUN_00418770(),
                                                     extraScope1, 0, destination, 0, 0, true, 0, itemScope1);
                                    else
                                    {
                                        bool removedScope2 = false;
                                        bool handled5 = false;
                                        FUN_004c0cf0(&removedScope2, form3, itemScope1->FUN_00726070(),
                                                     owner->IsActor() ? owner : 0, extraScope1, false, false,
                                                     itemScope1, &handled5);
                                        if (!handled5)
                                            FUN_004c37d0(owner, form3, retainOwner, extraScope1->FUN_00418770(),
                                                         extraScope1, 0, destination, 0, 0, true, 0, itemScope1);
                                    }
                                    changed2 = true;
                                    if (lastScope1)
                                    {
                                        itemScope1 = 0;
                                        nodeScope1 = 0;
                                    }
                                    else if (restartScope1)
                                        nodeScope1 = itemScope1->FUN_00559450();
                                    else
                                        nodeScope1 = nodeScope1->FUN_00726070();
                                }
                            }
                        }
                    }
                    if (countScope2 > 0)
                    {
                        if (retainOwner || SetOwnerPointer)
                        {
                            itemScope1 = new MoveItem(form3, countScope2);
                            void* ownershipScope5 = 0;
                            ownershipScope5 = owner->FUN_005d43c0()->FUN_004216f0();
                            if (!ownershipScope5)
                                ownershipScope5 = owner->FUN_007af430();
                            itemScope1->FUN_004bd5c0(ownershipScope5);
                            MoveExtra* extraScope2 = *itemScope1->FUN_00559450()->FUN_006815c0();
                            extraScope2->FUN_00419ad0(static_cast<unsigned short>(countScope2));
                            FUN_004c37d0(owner, form3, retainOwner, extraScope2->FUN_00418770(), extraScope2, 0,
                                         destination, 0, 0, true, 0, 0);
                        }
                        else
                            FUN_004c37d0(owner, form3, retainOwner, countScope2, 0, 0, destination, 0, 0, true, 0, 0);
                        if (destination == inventoryPlayer)
                        {
                            if (form3 && !silent)
                            {
                                MoveString messageScope1;
                                if (countScope2 > 1)
                                    FUN_00406f60(&messageScope1, "%i %s%s %s", countScope2, FUN_00482720(form3),
                                                 movePlural.FUN_00403df0(), moveVerb.FUN_00403df0());
                                else
                                    FUN_00406f60(&messageScope1, "%s %s", FUN_00482720(form3), moveVerb.FUN_00403df0());
                                switch (reinterpret_cast<MoveForm*>(form3)->FUN_00401170())
                                {
                                case 25:
                                case 30:
                                case 31:
                                case 40:
                                case 41:
                                case 46:
                                case 47:
                                case 50:
                                case 103:
                                case 108:
                                case 115:
                                case 116:
                                    DispatchMessageToSink(
                                        messageScope1.FUN_00559450(), 0,
                                        "Interface\\Icons\\Message Icons\\glow_message_vaultboy_neutral.dds",
                                        false ? 0 : inventoryPlayer->FUN_008adcf0(form3, true, false), DAT_010162c0, 0);
                                    break;
                                case 24:
                                    DispatchMessageToSink(
                                        messageScope1.FUN_00559450(), 0,
                                        "Interface\\Icons\\Message Icons\\glow_message_vaultboy_neutral.dds",
                                        false ? 0 : inventoryPlayer->FUN_008adcf0(form3, true, false), DAT_010162c0, 0);
                                    break;
                                }
                            }
                            FUN_00704af0();
                        }
                    }
                }
            }
        }
        base5 = base5->FUN_00726070();
    }
    MoveItem* itemScope6 = 0;
    MoveItemNode* change = head;
    while (change && !change->FUN_008256d0())
    {
        bool removedItem5 = false;
        itemScope6 = *change->FUN_006815c0();
        if ((filtered8 &&
             filter->FUN_00500940(reinterpret_cast<TESForm*>(itemScope6->FUN_0044ddc0()))->FUN_005f65d0()) ||
            (type > -1 && itemScope6 &&
             reinterpret_cast<MoveForm*>(itemScope6->FUN_0044ddc0())->FUN_00401170() != type))
        {
            change = change->FUN_00726070();
            continue;
        }
        if (itemScope6)
        {
            MoveFormInfo* infoScope2 = FUN_00480db0(itemScope6->FUN_0044ddc0());
            if ((!infoScope2 || infoScope2->FUN_00480d90()) &&
                (itemScope6->FUN_004bcb70() || !FUN_004bffb0() || !FUN_004bffb0()->FUN_00481eb0(itemScope6->form)))
            {
                if (reinterpret_cast<MoveForm*>(itemScope6->FUN_0044ddc0())->IsQuestItem() && owner == inventoryPlayer)
                {
                    if (itemScope6 && itemScope6->FUN_004bddd0(false))
                    {
                        int countScope3 = itemScope6->FUN_00726070();
                        bool removedScope6 = false;
                        bool equipped7 = false;
                        equipped7 = itemScope6->FUN_004bddd0(true);
                        FUN_004c0cf0(&removedScope6, itemScope6->FUN_0044ddc0(), countScope3, owner, 0, equipped7,
                                     itemScope6 != 0, 0, 0);
                    }
                    change = change->FUN_00726070();
                }
                else if (itemScope6 && itemScope6->FUN_00726070() > 0 &&
                         (!skipQuest3 || !reinterpret_cast<MoveForm*>(itemScope6->FUN_0044ddc0())->IsQuestItem()))
                {
                    form3 = itemScope6->FUN_0044ddc0();
                    weight7 += static_cast<float>(FUN_0048e8a0(form3) * itemScope6->FUN_00726070());
                    bool lastScope2 = false;
                    int baseCountScope4 = 0;
                    if (FUN_004bffb0() && itemScope6)
                        baseCountScope4 = FUN_004bffb0()->FUN_00482a90(itemScope6->form);
                    int countScope4 = baseCountScope4 + itemScope6->count;
                    MoveExtraNode* nodeScope2 = itemScope6->FUN_00559450();
                    if (nodeScope2 && *nodeScope2->FUN_006815c0())
                    {
                        while (nodeScope2 && *nodeScope2->FUN_006815c0() && !lastScope2)
                        {
                            MoveExtra* extraScope3 = *nodeScope2->FUN_006815c0();
                            bool restartScope2 = false;
                            if (extraScope3->FUN_00418770() < 1)
                            {
                                nodeScope2 = nodeScope2->FUN_00726070();
                                if (!nodeScope2)
                                {
                                    FUN_004c37d0(owner, form3, retainOwner, itemScope6->count, 0, 0, destination, 0, 0,
                                                 true, 0, itemScope6);
                                    removedItem5 = true;
                                    if (destination == inventoryPlayer)
                                    {
                                        if (form3 && !silent)
                                        {
                                            MoveString messageScope2;
                                            if (countScope4 > 1)
                                                FUN_00406f60(&messageScope2, "%i %s%s %s", itemScope6->count,
                                                             FUN_00482720(form3), movePlural.FUN_00403df0(),
                                                             moveVerb.FUN_00403df0());
                                            else
                                                FUN_00406f60(&messageScope2, "%s %s", FUN_00482720(form3),
                                                             moveVerb.FUN_00403df0());
                                            switch (reinterpret_cast<MoveForm*>(form3)->FUN_00401170())
                                            {
                                            case 25:
                                            case 30:
                                            case 31:
                                            case 40:
                                            case 41:
                                            case 46:
                                            case 47:
                                            case 50:
                                            case 103:
                                            case 108:
                                            case 115:
                                            case 116:
                                                DispatchMessageToSink(
                                                    messageScope2.FUN_00559450(), 0,
                                                    "Interface\\Icons\\Message Icons\\glow_message_vaultboy_neutral.dds",
                                                    false ? 0 : inventoryPlayer->FUN_008adcf0(form3, true, false),
                                                    DAT_010162c0, 0);
                                                break;
                                            case 24:
                                                DispatchMessageToSink(
                                                    messageScope2.FUN_00559450(), 0,
                                                    "Interface\\Icons\\Message Icons\\glow_message_vaultboy_neutral.dds",
                                                    false ? 0 : inventoryPlayer->FUN_008adcf0(form3, true, false),
                                                    DAT_010162c0, 0);
                                                break;
                                            }
                                        }
                                        FUN_00704af0();
                                    }
                                    countScope4 = 0;
                                    change = head;
                                    break;
                                }
                            }
                            else if (extraScope3->ItemsInList() < 1)
                            {
                                nodeScope2->FUN_0063f7b0();
                                if (nodeScope2->FUN_008256d0())
                                {
                                    nodeScope2->FUN_00470470();
                                    delete nodeScope2;
                                    nodeScope2 = 0;
                                    itemScope6->head = 0;
                                }
                                else
                                    nodeScope2 = itemScope6->FUN_00559450();
                            }
                            else
                            {
                                if (nodeScope2->FUN_005ae380() <= 1)
                                    lastScope2 = true;
                                else
                                    restartScope2 = true;
                                void* ownershipScope3 = 0;
                                if (owner->IsActor())
                                {
                                    void* actorOwnerScope2 = 0;
                                    actorOwnerScope2 = owner->FUN_005d43c0()->FUN_004216f0();
                                    if (!actorOwnerScope2)
                                        actorOwnerScope2 = owner->FUN_007af430();
                                    ownershipScope3 = actorOwnerScope2;
                                }
                                else
                                    ownershipScope3 = owner->FUN_00567790();
                                if ((retainOwner || SetOwnerPointer) && !FUN_00481f10(form3))
                                {
                                    if (!extraScope3->FUN_00418660())
                                        extraScope3->FUN_00419700(ownershipScope3);
                                }
                                else if (clearOwner)
                                {
                                    int sizeScope2 = extraScope3->ItemsInList();
                                    if (extraScope3->FUN_00418660() &&
                                        ((extraScope3->FUN_00418770() > 1 && sizeScope2 <= 2) || sizeScope2 <= 1))
                                    {
                                        extraScope3->FUN_0041aed0();
                                        extraScope3 = 0;
                                    }
                                    else
                                        extraScope3->FUN_0041aed0();
                                }
                                if (extraScope3)
                                {
                                    countScope4 -= extraScope3->FUN_00418770();
                                    FUN_004c37d0(owner, form3, retainOwner, extraScope3->FUN_00418770(), extraScope3, 0,
                                                 destination, 0, 0, true, 0, itemScope6);
                                    removedItem5 = true;
                                    if (destination == inventoryPlayer)
                                    {
                                        if (form3 && !silent)
                                        {
                                            MoveString messageScope3;
                                            if (countScope4 > 1)
                                                FUN_00406f60(&messageScope3, "%i %s%s %s", extraScope3->FUN_00418770(),
                                                             FUN_00482720(form3), movePlural.FUN_00403df0(),
                                                             moveVerb.FUN_00403df0());
                                            else
                                                FUN_00406f60(&messageScope3, "%s %s", FUN_00482720(form3),
                                                             moveVerb.FUN_00403df0());
                                            switch (reinterpret_cast<MoveForm*>(form3)->FUN_00401170())
                                            {
                                            case 25:
                                            case 30:
                                            case 31:
                                            case 40:
                                            case 41:
                                            case 46:
                                            case 47:
                                            case 50:
                                            case 103:
                                            case 108:
                                            case 115:
                                            case 116:
                                                DispatchMessageToSink(
                                                    messageScope3.FUN_00559450(), 0,
                                                    "Interface\\Icons\\Message Icons\\glow_message_vaultboy_neutral.dds",
                                                    false ? 0 : inventoryPlayer->FUN_008adcf0(form3, true, false),
                                                    DAT_010162c0, 0);
                                                break;
                                            case 24:
                                                DispatchMessageToSink(
                                                    messageScope3.FUN_00559450(), 0,
                                                    "Interface\\Icons\\Message Icons\\glow_message_vaultboy_neutral.dds",
                                                    false ? 0 : inventoryPlayer->FUN_008adcf0(form3, true, false),
                                                    DAT_010162c0, 0);
                                                break;
                                            }
                                        }
                                        FUN_00704af0();
                                    }
                                }
                                itemScope6 = FUN_004bfba0(form3, 1, 0);
                                if (countScope4 <= 0 && !itemScope6)
                                    change = head;
                                else if (countScope4 <= 0 && itemScope6)
                                    change = change->FUN_00726070();
                                if (itemScope6 && countScope4 > 0)
                                    nodeScope2 = itemScope6->FUN_00559450();
                                else
                                    nodeScope2 = 0;
                            }
                        }
                        if (countScope4 > 0)
                        {
                            FUN_004c37d0(owner, form3, retainOwner, countScope4, 0, 0, destination, 0, 0, true, 0,
                                         removedItem5 ? 0 : itemScope6);
                            change = head;
                            if (destination == inventoryPlayer)
                            {
                                if (form3 && !silent)
                                {
                                    MoveString messageScope4;
                                    if (countScope4 > 1)
                                        FUN_00406f60(&messageScope4, "%i %s%s %s", countScope4, FUN_00482720(form3),
                                                     movePlural.FUN_00403df0(), moveVerb.FUN_00403df0());
                                    else
                                        FUN_00406f60(&messageScope4, "%s %s", FUN_00482720(form3),
                                                     moveVerb.FUN_00403df0());
                                    switch (reinterpret_cast<MoveForm*>(form3)->FUN_00401170())
                                    {
                                    case 25:
                                    case 30:
                                    case 31:
                                    case 40:
                                    case 41:
                                    case 46:
                                    case 47:
                                    case 50:
                                    case 103:
                                    case 108:
                                    case 115:
                                    case 116:
                                        DispatchMessageToSink(
                                            messageScope4.FUN_00559450(), 0,
                                            "Interface\\Icons\\Message Icons\\glow_message_vaultboy_neutral.dds",
                                            false ? 0 : inventoryPlayer->FUN_008adcf0(form3, true, false), DAT_010162c0,
                                            0);
                                        break;
                                    case 24:
                                        DispatchMessageToSink(
                                            messageScope4.FUN_00559450(), 0,
                                            "Interface\\Icons\\Message Icons\\glow_message_vaultboy_neutral.dds",
                                            false ? 0 : inventoryPlayer->FUN_008adcf0(form3, true, false), DAT_010162c0,
                                            0);
                                        break;
                                    }
                                }
                                FUN_00704af0();
                            }
                        }
                    }
                    else
                    {
                        MoveExtra* extraScope8 = 0;
                        void* ownershipScope5 = 0;
                        if (owner->IsActor())
                        {
                            void* actorOwnerScope3 = 0;
                            actorOwnerScope3 = owner->FUN_005d43c0()->FUN_004216f0();
                            if (!actorOwnerScope3)
                                actorOwnerScope3 = owner->FUN_007af430();
                            ownershipScope5 = actorOwnerScope3;
                        }
                        else
                            ownershipScope5 = owner->FUN_00567790();
                        if ((retainOwner || SetOwnerPointer) && !FUN_00481f10(form3))
                        {
                            extraScope8 = new MoveExtra;
                            extraScope8->FUN_00419700(ownershipScope5);
                        }
                        int countScope5 = itemScope6->FUN_00726070();
                        FUN_004c37d0(owner, form3, retainOwner, itemScope6->FUN_00726070(), extraScope8, 0, destination,
                                     0, 0, true, 0, removedItem5 ? 0 : itemScope6);
                        if (destination == inventoryPlayer)
                        {
                            if (form3 && !silent)
                            {
                                MoveString messageScope5;
                                if (countScope5 > 1)
                                    FUN_00406f60(&messageScope5, "%i %s%s %s", countScope5, FUN_00482720(form3),
                                                 movePlural.FUN_00403df0(), moveVerb.FUN_00403df0());
                                else
                                    FUN_00406f60(&messageScope5, "%s %s", FUN_00482720(form3), moveVerb.FUN_00403df0());
                                switch (reinterpret_cast<MoveForm*>(form3)->FUN_00401170())
                                {
                                case 25:
                                case 30:
                                case 31:
                                case 40:
                                case 41:
                                case 46:
                                case 47:
                                case 50:
                                case 103:
                                case 108:
                                case 115:
                                case 116:
                                    DispatchMessageToSink(
                                        messageScope5.FUN_00559450(), 0,
                                        "Interface\\Icons\\Message Icons\\glow_message_vaultboy_neutral.dds",
                                        false ? 0 : inventoryPlayer->FUN_008adcf0(form3, true, false), DAT_010162c0, 0);
                                    break;
                                case 24:
                                    DispatchMessageToSink(
                                        messageScope5.FUN_00559450(), 0,
                                        "Interface\\Icons\\Message Icons\\glow_message_vaultboy_neutral.dds",
                                        false ? 0 : inventoryPlayer->FUN_008adcf0(form3, true, false), DAT_010162c0, 0);
                                    break;
                                }
                            }
                            FUN_00704af0();
                        }
                        change = head;
                    }
                }
                else
                    change = change->FUN_00726070();
            }
            else
                change = change->FUN_00726070();
        }
        else
            change = change->FUN_00726070();
    }
    return weight7;
}

union SETTING_VALUE
{
    float f;
};
template <> class SettingT<GameSettingCollection>
{
  public:
    SETTING_VALUE* Float();
};
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting31;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting32;
void __cdecl FUN_008ba2f0(ActorValueOwner*, int, float, float, int);
struct WeightExtra
{
    bool FUN_00418ba0();
    bool CheckExtraByType(int);
    short FUN_00418770();
};
struct WeightExtraNode
{
    WeightExtra** FUN_006815c0();
    WeightExtraNode* FUN_00726070();
};
struct WeightWeapon
{
    int GetSlotPointer(int);
};
struct WeightEntry : InventoryStackRecord
{
    unsigned char HasEffect(int);
    int FUN_00726070();
    WeightExtraNode* FUN_00559450();
    WeightWeapon* FUN_0044ddc0();
    int FUN_004bc8f0(bool);
    bool FUN_004bddd0(bool);
};
struct WeightChangeNode
{
    bool FUN_008256d0();
    WeightEntry** FUN_006815c0();
    WeightChangeNode* FUN_00726070();
};
struct WeightBaseEntry
{
    int count_2;
    TESBoundObject* form4;
};
struct WeightBaseNode
{
    bool FUN_008256d0();
    WeightBaseEntry** FUN_006815c0();
    WeightBaseNode* FUN_00726070();
};
struct WeightContainer
{
    WeightBaseNode* FUN_00717e50();
    bool FUN_00481eb0(TESBoundObject*);
};
struct WeightInventory : InventoryChanges
{
    WeightContainer* FUN_004bffb0();
    WeightEntry* FUN_004bfba0(TESBoundObject*, int, int);
    float FUN_004d0900(bool useAmmoWeight);
};
// @fnv 0x004d0900
float WeightInventory::FUN_004d0900(bool useAmmoWeight)
{
    Actor* actorTmp = 0;
    if (pRef->IsActor())
        actorTmp = (Actor*)pRef;
    bool value4 = false;
    float value3 = 0.0f;
    FUN_005e58f0(0x37, (char*)actorTmp, &value3);
    float scaleA = originalRuntimeFloatSetting32.Float()->f;
    float valueTmp = originalRuntimeFloatSetting31.Float()->f;
    if (value3 > 0.0)
        value4 = true;
    if (m_fTotalWeight == -1.0)
    {
        float result5 = 0.0f;
        float valueA = 0.0f;
        float resultB = 0.0f;
        WeightBaseNode* nodeX = FUN_004bffb0()->FUN_00717e50();
        while (nodeX && !nodeX->FUN_008256d0())
        {
            TESBoundObject* form4 = (*nodeX->FUN_006815c0())->form4;
            WeightEntry* item9 = FUN_004bfba0(form4, 1, 0);
            if (!((TESForm*)form4)->IsQuestItem())
            {
                if (((ObjectForm*)form4)->FUN_00401170() == 0x28 && item9)
                {
                    ObjectForm* weaponTmp = (ObjectForm*)form4;
                    valueA = weaponTmp->FUN_004be380(item9->HasEffect(4));
                    if (valueA >= 10.0)
                    {
                        float multiplier = 1.0f;
                        FUN_005e58f0(0x49, DAT_011dea3c, &multiplier);
                        valueA *= multiplier;
                    }
                }
                else
                {
                    valueA = FUN_0048ebc0(form4, useAmmoWeight);
                }
                if (valueA == -1.0)
                    valueA = 0.0f;
                if (value4 && valueA <= valueTmp)
                    valueA *= scaleA;
                if (!item9)
                {
                    result5 += (*nodeX->FUN_006815c0())->count_2 * valueA;
                }
                else if (item9 && item9->FUN_00726070() + (*nodeX->FUN_006815c0())->count_2)
                {
                    result5 += (item9->FUN_00726070() + (*nodeX->FUN_006815c0())->count_2) * valueA;
                }
            }
            nodeX = nodeX->FUN_00726070();
        }
        WeightChangeNode* nodeA = (WeightChangeNode*)m_pEntryList;
        while (nodeA && !nodeA->FUN_008256d0() && *nodeA->FUN_006815c0())
        {
            bool current = false;
            WeightEntry* item7 = *nodeA->FUN_006815c0();
            TESBoundObject* form4 = item7->m_pItemObject;
            if (form4 && (!FUN_004bffb0() || !FUN_004bffb0()->FUN_00481eb0(form4)) && !((TESForm*)form4)->IsQuestItem())
            {
                if (((ObjectForm*)form4)->FUN_00401170() == 0x28)
                {
                    current = true;
                    resultB = ((ObjectForm*)form4)->FUN_004be380(item7->HasEffect(4));
                    valueA = FUN_0048ebc0(form4, useAmmoWeight);
                    if (valueA >= 10.0)
                    {
                        float multiplier = 1.0f;
                        FUN_005e58f0(0x49, DAT_011dea3c, &multiplier);
                        valueA *= multiplier;
                    }
                    if (resultB >= 10.0)
                    {
                        float multiplier = 1.0f;
                        FUN_005e58f0(0x49, DAT_011dea3c, &multiplier);
                        resultB *= multiplier;
                    }
                }
                else
                {
                    valueA = FUN_0048ebc0(form4, useAmmoWeight);
                }
                if (valueA > 0.0)
                {
                    if (value4 && valueA <= valueTmp)
                        valueA *= scaleA;
                    if (value4 && resultB <= valueTmp)
                        resultB *= scaleA;
                    TESBoundObject* formX = 0;
                    if (form4 && ((ObjectForm*)form4)->FUN_00401170() == 0x18)
                        formX = form4;
                    int count_2 = item7->FUN_00726070();
                    if (item7->FUN_00559450() && current && item7->FUN_004bc8f0(true) > 0)
                    {
                        WeightWeapon* weaponTmp = item7->FUN_0044ddc0();
                        int countTmp = 0;
                        WeightExtraNode* extra2 = item7->FUN_00559450();
                        while (extra2)
                        {
                            WeightExtra* extra = *extra2->FUN_006815c0();
                            if (extra && extra->FUN_00418ba0())
                            {
                                if (extra->CheckExtraByType(1) && weaponTmp->GetSlotPointer(1) == 4)
                                    countTmp += extra->FUN_00418770();
                                if (extra->CheckExtraByType(2) && weaponTmp->GetSlotPointer(2) == 4)
                                    countTmp += extra->FUN_00418770();
                                if (extra->CheckExtraByType(4) && weaponTmp->GetSlotPointer(4) == 4)
                                    countTmp += extra->FUN_00418770();
                            }
                            extra2 = extra2->FUN_00726070();
                        }
                        int normal9 = count_2 - countTmp;
                        valueA = normal9 * valueA + countTmp * resultB;
                    }
                    else if (current)
                    {
                        valueA = count_2 * valueA;
                    }
                    if (actorTmp && formX && item7->FUN_004bddd0(false))
                    {
                        float wornWeight = valueA;
                        if (count_2 > 0)
                        {
                            result5 += wornWeight;
                            count_2 = count_2 - 1;
                        }
                    }
                    if (count_2 > 0 && !current)
                        result5 += count_2 * valueA;
                    else if (count_2)
                        result5 += valueA;
                }
            }
            nodeA = nodeA->FUN_00726070();
        }
        m_fTotalWeight = result5;
        if (actorTmp)
            FUN_008ba2f0(actorTmp, 0x2e, m_fArmorWeight, m_fTotalWeight - m_fArmorWeight, 0);
    }
    return m_fTotalWeight;
}

struct ValueForm : TESForm
{
    int FUN_0084e3a0();
};
struct ValueBaseEntry
{
    int count;
    ValueForm* object;
};
struct ValueBaseNode
{
    ValueBaseEntry** FUN_006815c0();
    ValueBaseNode* FUN_00726070();
    bool FUN_008256d0();
};
struct ValueChange : InventoryStackRecord
{
    int FUN_00726070();
};
struct ValueChangeNode
{
    ValueChange** FUN_006815c0();
    ValueChangeNode* FUN_00726070();
    bool FUN_008256d0();
};
struct ValueContainer
{
    ValueBaseNode* FUN_00717e50();
    bool FUN_00481eb0(ValueForm*);
};
struct ValueInventory : InventoryChanges
{
    ValueContainer* FUN_004bffb0();
    ValueChange* FUN_004bfba0(ValueForm*, int, int);
    int FUN_004d0f40(bool includeQuestItems, bool includeType15);
};
int __cdecl FUN_0048e8a0(ValueForm*);

// @fnv 0x004d0f40
int ValueInventory::FUN_004d0f40(bool includeQuestItems, bool includeType15)
{
    int changeNode = 0;
    ValueBaseNode* baseNode = FUN_004bffb0()->FUN_00717e50();
    while (baseNode && !baseNode->FUN_008256d0())
    {
        ValueForm* object = (*baseNode->FUN_006815c0())->object;
        if ((includeQuestItems || !object->IsQuestItem()) && (includeType15 || object->FUN_0084e3a0() != 15))
        {
            int value = FUN_0048e8a0(object);
            if (value == -1)
                value = 0;
            if (value)
            {
                ValueChange* change = FUN_004bfba0(object, 1, 0);
                if (!change)
                    changeNode += value * (*baseNode->FUN_006815c0())->count;
                else if (change && change->FUN_00726070() + (*baseNode->FUN_006815c0())->count)
                    changeNode += (change->FUN_00726070() + (*baseNode->FUN_006815c0())->count) * value;
            }
        }
        baseNode = baseNode->FUN_00726070();
    }
    ValueChangeNode* total = (ValueChangeNode*)m_pEntryList;
    while (total && !total->FUN_008256d0() && *total->FUN_006815c0())
    {
        ValueChange* object = *total->FUN_006815c0();
        ValueForm* change = (ValueForm*)object->m_pItemObject;
        if (change && (!FUN_004bffb0() || !FUN_004bffb0()->FUN_00481eb0(change)) &&
            (includeQuestItems || !change->IsQuestItem()) && (includeType15 || change->FUN_0084e3a0() != 15))
        {
            int value = FUN_0048e8a0(change);
            if (value == -1)
                value = 0;
            if (value && object->FUN_00726070())
                changeNode += object->FUN_00726070() * value;
        }
        total = total->FUN_00726070();
    }
    return changeNode;
}

struct Extra4d1440
{
    float FUN_00488d50();
};
struct Entry4d1440
{
    int count;
    TESForm* pObj;
    Extra4d1440* m_pExtraData;
};
struct Node4d1440
{
    bool _ref_008256d0();
    Entry4d1440** _ref_006815c0();
    Node4d1440* _ref_00726070();
};
struct Cont4d1440
{
    Node4d1440* FUN_00717e50();
};
struct List4d1440
{
    int unk00;
    int unk04;
    int unk08;
    List4d1440();
    ~List4d1440();
    void FUN_00482090(float);
    void AddLeveledItemsToChanges(int, InventoryChanges*);
};
struct LevList4d1440
{
    void FUN_00487f70(unsigned short, int, List4d1440*, int);
};
struct LevItem4d1440
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
    LevList4d1440 leveledList;
};
struct Ref4d1440
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
    virtual void v3f();
    virtual bool IsActor();
    unsigned short FUN_0087f9f0();
    int FUN_00567e10(bool);
};
int __cdecl FUN_00ec7d40(int);
struct Inv4d1440 : public InventoryChanges
{
    Cont4d1440* FUN_004bffb0();
    Ref4d1440* FUN_00726070();
    bool HasExtraDataWithValue(int);
    void FUN_004d1440();
};

// @fnv 0x004d1440
void Inv4d1440::FUN_004d1440()
{
    Node4d1440* node = FUN_004bffb0()->FUN_00717e50();
    int index = 0;
    int level = 0;
    if (FUN_00726070()->IsActor())
    {
        level = FUN_00726070()->FUN_0087f9f0();
    }
    else
    {
        level = FUN_00726070()->FUN_00567e10(true);
    }
    while (node && !node->_ref_008256d0())
    {
        Entry4d1440* pEntry = *node->_ref_006815c0();
        LevItem4d1440* levItem = 0;
        if (pEntry->pObj && FNV_GetFormType(pEntry->pObj) == 0x34)
        {
            levItem = (LevItem4d1440*)pEntry->pObj;
        }
        if (levItem)
        {
            if (!HasExtraDataWithValue(index))
            {
                List4d1440 list;
                levItem->leveledList.FUN_00487f70(level, FUN_00ec7d40(pEntry->count), &list, 0);
                if (pEntry && pEntry->m_pExtraData && pEntry->m_pExtraData->FUN_00488d50() != 1.0)
                {
                    list.FUN_00482090(pEntry->m_pExtraData->FUN_00488d50());
                }
                list.AddLeveledItemsToChanges(index, this);
            }
            index++;
        }
        node = node->_ref_00726070();
    }
}

namespace InventoryTransfer {
struct Extra;
struct ExtraNode;
struct Item;
struct Inventory;
struct AutoMemContext
{
    int context;
    AutoMemContext(int, bool, const char*, int);
    ~AutoMemContext();
};
extern const char DAT_01020778[];
struct Form
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
    virtual bool v094();
};
struct Extra
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    Extra();
    static void* operator new(unsigned int);
    static void operator delete(void*);
    void* GetExtraData(int);
    void SetOriginalReference(void*);
    void FUN_00418600();
    short FUN_00418770();
    void FUN_00419ad0(int);
    void RemoveExtra24();
    bool HasOnlyAllowedExtraData(int);
};
struct ExtraNode
{
    Extra* value;
    ExtraNode* next;
    ExtraNode();
    static void* operator new(unsigned int);
    static void operator delete(void*);
    Extra** FUN_006815c0();
    ExtraNode* FUN_00726070();
    void FUN_00905820(Extra**);
    void FUN_005ae3d0(Extra**);
};
struct Item
{
    ExtraNode* list;
    int count;
    TESBoundObject* form;
    Item();
    ~Item();
    static void* operator new(unsigned int);
    static void operator delete(void*);
    int FUN_00726070();
    ExtraNode* FUN_00559450();
    Form* FUN_0044ddc0();
    void* FUN_004bde40();
    void FUN_00403550(TESBoundObject*);
    void FUN_00403550(Form*);
    void FUN_006ecd40(int);
    void ProcessNodes();
    bool FUN_004bcb70();
    int FUN_004bcc30();
    bool FUN_004bddd0(int);
    int FUN_004bc8f0(int);
    int GetFormTypeCategory();
};
struct BaseEntry
{
    int count;
    TESBoundObject* form;
};
struct BaseNode
{
    BaseEntry** FUN_006815c0();
    BaseNode* FUN_00726070();
};
struct ItemNode
{
    Item** FUN_006815c0();
    ItemNode* FUN_00726070();
};
struct Container
{
    BaseNode* FUN_00717e50();
    int FUN_00482a90(TESBoundObject*);
    bool FUN_00481eb0(TESBoundObject*);
};
struct Inventory
{
    ItemNode* head;
    Container* FUN_004bffb0();
    Item* FUN_004bfba0(TESBoundObject*, int, int);
    void FUN_004c3380(Item*, int);
    void FUN_004d26d0(Inventory*, void*, bool);
};
// Moves items from the base container and the inventory list into target, rebuilding extra lists and counts and skipping leveled or excluded items.
// @fnv 0x004d26d0
void Inventory::FUN_004d26d0(Inventory* target, void* owner, bool exclude)
{
    AutoMemContext contextSlot2(0x36, true, DAT_01020778, 0x26b7);
    BaseNode* baseSlot2 = FUN_004bffb0()->FUN_00717e50();
    Item* transferSlot3 = 0;
    while (baseSlot2 && *baseSlot2->FUN_006815c0())
    {
        BaseEntry* entrySlot7 = *baseSlot2->FUN_006815c0();
        TESLevItem* leveledSlot21 = dynamic_cast<TESLevItem*>(entrySlot7->form);
        transferSlot3 = new Item;
        int baseCountSlot38 = FUN_004bffb0()->FUN_00482a90(entrySlot7->form);
        if (!transferSlot3->list)
            transferSlot3->list = new ExtraNode;
        if (entrySlot7 && !leveledSlot21)
        {
            Item* current = FUN_004bfba0(entrySlot7->form, 1, 0);
            if (current)
                current->ProcessNodes();
            if (entrySlot7 && current &&
                (((!current->FUN_004bcb70() || current->FUN_004bcc30() < 1) && current->count + baseCountSlot38 == 0) ||
                 (current->FUN_0044ddc0()->v094() && exclude) || current->FUN_004bddd0(0)))
            {
                delete transferSlot3;
                transferSlot3 = 0;
            }
            else if (entrySlot7 && (!current || (current && !current->FUN_004bc8f0(0))))
            {
                int magnitude = baseCountSlot38;
                if (magnitude < 0)
                    magnitude *= -1;
                if (current)
                    transferSlot3->count = magnitude + current->count - current->FUN_004bc8f0(0);
                else
                    transferSlot3->count = magnitude;
                transferSlot3->FUN_00403550(entrySlot7->form);
                if (current && current->FUN_004bde40())
                {
                    ExtraNode* scripted = current->FUN_00559450();
                    while (scripted && *scripted->FUN_006815c0())
                    {
                        (*scripted->FUN_006815c0())->SetOriginalReference(owner);
                        transferSlot3->list->FUN_00905820(scripted->FUN_006815c0());
                        scripted = scripted->FUN_00726070();
                    }
                    target->FUN_004c3380(transferSlot3, 1);
                }
                else
                {
                    if (!transferSlot3->FUN_004bddd0(0))
                    {
                        Extra* extraA = new Extra;
                        extraA->SetOriginalReference(owner);
                        extraA->FUN_00419ad0(transferSlot3->FUN_00726070());
                        transferSlot3->list->FUN_005ae3d0(&extraA);
                        target->FUN_004c3380(transferSlot3, 1);
                    }
                    else
                    {
                        delete transferSlot3;
                        transferSlot3 = 0;
                    }
                }
            }
            else if (current)
            {
                int extraCountSlot33 = 0;
                if (current->list)
                    extraCountSlot33 = current->FUN_004bc8f0(0);
                ExtraNode* extrasSlot23 = current->list;
                while (extrasSlot23 && *extrasSlot23->FUN_006815c0() && !transferSlot3)
                {
                    Extra* extraB = *extrasSlot23->FUN_006815c0();
                    transferSlot3->FUN_00403550(current->form);
                    transferSlot3->FUN_006ecd40(extraB->FUN_00418770());
                    if (!transferSlot3->list)
                        transferSlot3->list = new ExtraNode;
                    extraB->SetOriginalReference(owner);
                    transferSlot3->list->FUN_005ae3d0(&extraB);
                    if (!transferSlot3->FUN_004bddd0(0))
                        target->FUN_004c3380(transferSlot3, 1);
                    extrasSlot23 = extrasSlot23->FUN_00726070();
                }
                if (current->FUN_004bc8f0(0) < baseCountSlot38 + current->count)
                {
                    if (!transferSlot3->list)
                        transferSlot3->list = new ExtraNode;
                    if (current)
                        transferSlot3->count = baseCountSlot38 + current->count - current->FUN_004bc8f0(0);
                    else
                        transferSlot3->count = baseCountSlot38;
                    transferSlot3->FUN_00403550(entrySlot7->form);
                    if (!transferSlot3->FUN_004bddd0(0))
                    {
                        Extra* extraC = new Extra;
                        extraC->SetOriginalReference(owner);
                        extraC->FUN_00419ad0(transferSlot3->FUN_00726070());
                        transferSlot3->list->FUN_005ae3d0(&extraC);
                        target->FUN_004c3380(transferSlot3, 1);
                    }
                    else
                    {
                        delete transferSlot3;
                        transferSlot3 = 0;
                    }
                }
            }
            else
            {
                delete transferSlot3;
                transferSlot3 = 0;
            }
        }
        else
        {
            delete transferSlot3;
            transferSlot3 = 0;
        }
        baseSlot2 = baseSlot2->FUN_00726070();
    }
    ItemNode* nodeSlot1 = head;
    while (nodeSlot1 && *nodeSlot1->FUN_006815c0())
    {
        transferSlot3 = new Item;
        if (!transferSlot3->list)
            transferSlot3->list = new ExtraNode;
        Item* changed = *nodeSlot1->FUN_006815c0();
        if (changed && changed->FUN_00726070() > 0 && (!FUN_004bffb0() || !FUN_004bffb0()->FUN_00481eb0(changed->form)))
        {
            if (changed->FUN_004bc8f0(0) || changed->FUN_004bde40())
            {
                ExtraNode* walkSlot1 = changed->list;
                int countSlot56 = 0;
                bool hasSpecialSlot4 = false;
                while (walkSlot1 && *walkSlot1->FUN_006815c0())
                {
                    if ((*walkSlot1->FUN_006815c0())->GetExtraData(0x2f))
                        hasSpecialSlot4 = true;
                    walkSlot1 = walkSlot1->FUN_00726070();
                }
                walkSlot1 = changed->list;
                if (!hasSpecialSlot4 || changed->GetFormTypeCategory() != 4)
                {
                    while (walkSlot1 && *walkSlot1->FUN_006815c0())
                    {
                        Extra* extraD = *walkSlot1->FUN_006815c0();
                        extraD->SetOriginalReference(owner);
                        transferSlot3->list->FUN_005ae3d0(&extraD);
                        walkSlot1 = walkSlot1->FUN_00726070();
                        countSlot56 += extraD->FUN_00418770();
                    }
                }
                else
                {
                    if (changed->GetFormTypeCategory() == 4 && changed->FUN_004bde40())
                        changed->FUN_006ecd40(1);
                    while (walkSlot1 && *walkSlot1->FUN_006815c0())
                    {
                        Extra* extraE = *walkSlot1->FUN_006815c0();
                        extraE->RemoveExtra24();
                        extraE->SetOriginalReference(owner);
                        transferSlot3->list->FUN_005ae3d0(&extraE);
                        walkSlot1 = walkSlot1->FUN_00726070();
                        countSlot56 = 1;
                    }
                }
                transferSlot3->FUN_00403550(changed->form);
                transferSlot3->FUN_006ecd40(changed->FUN_00726070());
                if (!transferSlot3->FUN_004bddd0(0) && countSlot56 < changed->FUN_00726070())
                {
                    Extra* extraF = new Extra;
                    extraF->SetOriginalReference(owner);
                    extraF->FUN_00419ad0(changed->FUN_00726070() - countSlot56);
                    transferSlot3->list->FUN_005ae3d0(&extraF);
                }
                if (!transferSlot3->FUN_004bddd0(0))
                    target->FUN_004c3380(transferSlot3, 1);
                else
                {
                    if (*transferSlot3->list->FUN_006815c0())
                        (*transferSlot3->list->FUN_006815c0())->FUN_00418600();
                    delete transferSlot3;
                    transferSlot3 = 0;
                }
            }
            else
            {
                Extra* chosen = 0;
                if (changed->list)
                {
                    ExtraNode* walk2Slot3 = changed->list;
                    int count2Slot41 = 0;
                    while (walk2Slot3 && *walk2Slot3->FUN_006815c0() && !chosen)
                    {
                        chosen = *walk2Slot3->FUN_006815c0();
                        count2Slot41 += chosen->FUN_00418770();
                        if (chosen->HasOnlyAllowedExtraData(0))
                            chosen = 0;
                        walk2Slot3 = walk2Slot3->FUN_00726070();
                    }
                    if (chosen)
                    {
                        if (!transferSlot3->list)
                            transferSlot3->list = new ExtraNode;
                        chosen->SetOriginalReference(owner);
                        transferSlot3->list->FUN_005ae3d0(&chosen);
                        if (!transferSlot3->FUN_004bddd0(0) && count2Slot41 < changed->FUN_00726070())
                        {
                            Extra* extraG = new Extra;
                            extraG->SetOriginalReference(owner);
                            extraG->FUN_00419ad0(changed->FUN_00726070() - count2Slot41);
                            transferSlot3->list->FUN_005ae3d0(&extraG);
                        }
                    }
                    else
                    {
                        Extra* extraH = new Extra;
                        extraH->SetOriginalReference(owner);
                        extraH->FUN_00419ad0(changed->FUN_00726070());
                        transferSlot3->list->FUN_005ae3d0(&extraH);
                    }
                    transferSlot3->FUN_00403550(changed->form);
                    transferSlot3->FUN_006ecd40(changed->FUN_00726070());
                    if (!transferSlot3->FUN_004bddd0(0))
                    {
                        transferSlot3->FUN_006ecd40(changed->FUN_00726070());
                        target->FUN_004c3380(transferSlot3, 1);
                    }
                    else
                    {
                        if (*transferSlot3->list->FUN_006815c0())
                            (*transferSlot3->list->FUN_006815c0())->FUN_00418600();
                        delete transferSlot3;
                        transferSlot3 = 0;
                    }
                }
                else
                {
                    transferSlot3->FUN_00403550(changed->FUN_0044ddc0());
                    transferSlot3->FUN_006ecd40(changed->FUN_00726070());
                    chosen = new Extra;
                    chosen->SetOriginalReference(owner);
                    chosen->FUN_00419ad0(transferSlot3->FUN_00726070());
                    transferSlot3->list->FUN_005ae3d0(&chosen);
                    target->FUN_004c3380(transferSlot3, 1);
                }
            }
        }
        else
        {
            delete transferSlot3;
            transferSlot3 = 0;
        }
        nodeSlot1 = nodeSlot1->FUN_00726070();
    }
}
}

struct CleanupReference;
struct CleanupExtra
{
    virtual ~CleanupExtra();
    CleanupReference* FUN_00418630();
    void FUN_00418600();
    unsigned int ItemsInList();
    short FUN_00418770();
    void RemoveExtra24();
    void* FUN_00418800();
};
struct CleanupExtraNode
{
    CleanupExtra** FUN_006815c0();
    CleanupExtraNode* FUN_00726070();
    void FUN_0063f7b0();
    void FUN_00905330(CleanupExtra* const&);
};
struct CleanupItem : InventoryStackRecord
{
    CleanupExtraNode* FUN_00559450();
    TESBoundObject* FUN_0044ddc0();
};
struct CleanupItemNode
{
    CleanupItem** FUN_006815c0();
    void FUN_00905330(CleanupItem* const&);
};
struct CleanupInventory;
struct CleanupReferenceExtra
{
    CleanupInventory* FUN_00418520();
};
struct CleanupReference
{
    void* FUN_0055d310();
    CleanupReferenceExtra* FUN_005d43c0();
};
struct CleanupInventory
{
    CleanupItemNode* first;
    CleanupItem* FUN_004bfba0(TESBoundObject*, int, int);
    void RemoveAllItems();
};
// @fnv 0x004d3660
void CleanupInventory::RemoveAllItems()
{
    CleanupItemNode* start = first;
    CleanupItemNode* itemList = first;
    CleanupItem* node = 0;
    while (start && *start->FUN_006815c0())
    {
        node = *start->FUN_006815c0();
        CleanupExtra* extra = 0;
        while (node->m_pExtraDataLists && *reinterpret_cast<CleanupExtraNode*>(node->m_pExtraDataLists)->FUN_006815c0())
        {
            extra = *reinterpret_cast<CleanupExtraNode*>(node->m_pExtraDataLists)->FUN_006815c0();
            reinterpret_cast<CleanupExtraNode*>(node->m_pExtraDataLists)->FUN_0063f7b0();
            CleanupReference* ref = 0;
            if (extra)
                ref = extra->FUN_00418630();
            if (ref)
            {
                if (ref->FUN_0055d310())
                {
                    extra->FUN_00418600();
                    if (extra->ItemsInList() < 2 && extra->FUN_00418770() != 0)
                        extra->RemoveExtra24();
                    node->FUN_00559450()->FUN_00905330(extra);
                    CleanupInventory* inventory = ref->FUN_005d43c0()->FUN_00418520();
                    bool destroy = true;
                    if (inventory)
                    {
                        CleanupItem* entry = inventory->FUN_004bfba0(node->FUN_0044ddc0(), 1, 0);
                        if (entry && entry->FUN_00559450())
                        {
                            CleanupExtraNode* scan = entry->FUN_00559450();
                            while (scan && *scan->FUN_006815c0() && destroy)
                            {
                                if (*scan->FUN_006815c0() == extra)
                                    destroy = false;
                                else
                                    scan = scan->FUN_00726070();
                            }
                        }
                    }
                    inventory = reinterpret_cast<CleanupReference*>(DAT_011dea3c)->FUN_005d43c0()->FUN_00418520();
                    if (inventory)
                    {
                        CleanupItem* playerEntry = inventory->FUN_004bfba0(node->FUN_0044ddc0(), 1, 0);
                        if (playerEntry && playerEntry->FUN_00559450())
                        {
                            CleanupExtraNode* playerScan = playerEntry->FUN_00559450();
                            while (playerScan && *playerScan->FUN_006815c0() && destroy)
                            {
                                if (*playerScan->FUN_006815c0() == extra)
                                    destroy = false;
                                else
                                    playerScan = playerScan->FUN_00726070();
                            }
                        }
                    }
                    if (destroy)
                        delete extra;
                    else
                        extra = 0;
                }
                else
                {
                    extra->FUN_00418600();
                    if (!extra->FUN_00418800())
                        delete extra;
                    extra = 0;
                }
            }
            else
                extra = 0;
        }
        start->FUN_00905330(node);
        delete node;
        node = 0;
        start = itemList;
    }
}

namespace fnv_004d3960 {
extern const char g_inventoryChangesSourceFilename[];

struct SaveItemChange
{
    unsigned short GetSaveSize();
};
struct SaveItemNode
{
    bool IsEmpty();
    SaveItemChange** Item();
    SaveItemNode* Next();
};
struct SaveFormRecord
{
    unsigned int formID;
    unsigned char unk04;
    unsigned char flags05;
};
struct SaveLoadGame
{
    bool IsSaving();
    SaveFormRecord* GetCurrentRecord();
};
extern SaveLoadGame* g_TESSaveLoadGame;
struct DebugSetting
{
    unsigned char* Bool();
};
extern DebugSetting g_011de4e8;
void __cdecl DebugPrintf(const char* fmt, ...);

struct InventorySaveList
{
    SaveItemNode* first;
    unsigned short FUN_004d3960();
};

// @fnv 0x004d3960
unsigned short InventorySaveList::FUN_004d3960()
{
    unsigned short size3 = 0;
    unsigned short startSize = size3;
    if (g_TESSaveLoadGame->IsSaving())
    {
        size3 += 4;
        size3 += 2;
    }
    size3 += 2;
    SaveItemNode* node5 = first;
    while (node5 && !node5->IsEmpty())
    {
        SaveItemChange* itemB = *node5->Item();
        if (itemB)
            size3 += itemB->GetSaveSize();
        node5 = node5->Next();
    }
    if (*g_011de4e8.Bool())
    {
        SaveFormRecord* pRecord = g_TESSaveLoadGame->GetCurrentRecord();
        if (pRecord)
        {
            TESForm* form = TESForm::GetFormByID(pRecord->formID);
            DebugPrintf("GetSaveSize(): %-5i for form %08X %s with flags %08X ending at line %i in file %s",
                        size3 - startSize, pRecord->formID, form->GetName(), *(unsigned int*)&pRecord->flags05, 10318,
                        g_inventoryChangesSourceFilename);
        }
        else
        {
            DebugPrintf("GetSaveSize(): %-5i ending at line %i in file %s", size3 - startSize, 10318,
                        g_inventoryChangesSourceFilename);
        }
    }
    return size3;
}
}  // namespace fnv_004d3960

namespace fnv_004d3ab0 {
class SForm
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();
    virtual void vfB4();
    virtual void vfB8();
    virtual void vfBC();
    virtual void vfC0();
    virtual void vfC4();
    virtual void vfC8();
    virtual void vfCC();
    virtual void vfD0();
    virtual void vfD4();
    virtual void vfD8();
    virtual void vfDC();
    virtual void vfE0();
    virtual void vfE4();
    virtual void vfE8();
    virtual void vfEC();
    virtual void vfF0();
    virtual void vfF4();
    virtual void vfF8();
    virtual void vfFC();
    virtual bool vf100();
    virtual void vf104();
    virtual void vf108();
    virtual void vf10C();
    virtual void vf110();
    virtual void vf114();
    virtual void vf118();
    virtual void vf11C();
    virtual void vf120();
    virtual void vf124();
    virtual void vf128();
    virtual void vf12C();
    virtual const char* vf130();
    virtual void vf134();
    virtual void vf138();
    virtual void vf13C();
    virtual void vf140();
    virtual void vf144();
    virtual void vf148();
    virtual void vf14C();
    virtual void vf150();
    unsigned int FUN_0084e3a0();
};

struct FormIDEntry
{
    unsigned int formID;
    char flags[5];
};

struct SSaveGame
{
    unsigned int FUN_00825c00();
    bool FUN_00862110();
    void FUN_008579b0(void* data, int size);
    void FUN_00857a10(void* data, int size);
    unsigned char FUN_008df040();
    FormIDEntry* FUN_004fd3e0();
};

struct DebugFlag
{
    bool* FUN_00408d60();
};

struct ItemNode
{
    bool FUN_008256d0();
    void** FUN_006815c0();
    ItemNode* FUN_00726070();
};

struct ItemChangeStub
{
    void FUN_004be6f0();
};

extern SSaveGame* DAT_011de45c;
extern DebugFlag DAT_011de4e8;

SForm* __cdecl FUN_004839c0(unsigned int id);
void __cdecl FUN_0040fbe0(const char* fmt, ...);
void __cdecl FUN_005b5e40(const char* fmt, ...);

struct FUN_004d3ab0_cls
{
    void* m_pEntryList;
    void FUN_004d3ab0();
};

// Writes a BLOCK-tagged inventory-change list to the save game, counting changed items and patching the block size and count fields.
// @fnv 0x004d3ab0
void FUN_004d3ab0_cls::FUN_004d3ab0()
{
    SForm* f1;
    unsigned int endPos;
    FormIDEntry* hdr;
    ItemChangeStub* item2;
    int kTag;
    short count_;
    ItemNode* aNode;
    unsigned int kPosB;
    short zero;
    unsigned int cnt;
    unsigned int blk;

    zero = 0;
    blk = 0;
    kPosB = DAT_011de45c->FUN_00825c00();
    if (*DAT_011de4e8.FUN_00408d60())
    {
        kPosB = DAT_011de45c->FUN_00825c00();
    }
    if (DAT_011de45c->FUN_00862110())
    {
        kTag = 0x424c4f4b;
        DAT_011de45c->FUN_008579b0(&kTag, 4);
        blk = DAT_011de45c->FUN_00825c00();
        DAT_011de45c->FUN_008579b0(&zero, 2);
    }
    count_ = 0;
    cnt = DAT_011de45c->FUN_00825c00();
    DAT_011de45c->FUN_008579b0(&count_, 2);
    aNode = (ItemNode*)m_pEntryList;
    while (aNode && !aNode->FUN_008256d0())
    {
        item2 = (ItemChangeStub*)*aNode->FUN_006815c0();
        if (item2)
        {
            item2->FUN_004be6f0();
            count_++;
        }
        aNode = aNode->FUN_00726070();
    }
    *(short*)cnt = count_;
    if (*DAT_011de4e8.FUN_00408d60())
    {
        endPos = DAT_011de45c->FUN_00825c00();
        hdr = DAT_011de45c->FUN_004fd3e0();
        if (hdr)
        {
            f1 = FUN_004839c0(hdr->formID);
            FUN_0040fbe0("SaveGame(): %-5i for form %08X %s with flags %08X ending at line %i in file %s",
                         endPos - kPosB, hdr->formID, f1->vf130(), *(int*)((char*)hdr + 5), 0x286a,
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\InventoryChanges.cpp");
        }
        else
        {
            FUN_0040fbe0("SaveGame(): %-5i ending at line %i in file %s", endPos - kPosB, 0x286a,
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\InventoryChanges.cpp");
        }
    }
    if (DAT_011de45c->FUN_00862110())
    {
        unsigned int _end = DAT_011de45c->FUN_00825c00();
        unsigned int tmp = blk;
        if (_end > tmp + 0xffff)
        {
            FUN_005b5e40("SAVELOAD: Save Game Block in file %s on line %i is greater than maximum short size",
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\InventoryChanges.cpp", 0x286a);
        }
        *(short*)blk = (short)(_end - tmp);
    }
}
}  // namespace fnv_004d3ab0

// Save-game block loader (FUN_004d3cc0): block header checks, item list rebuild, size validation logs.

class TESForm;

struct LoadingFormInfo
{
    unsigned int formID;
    unsigned char formType;
    unsigned char flags0;
    unsigned char flags1;
    unsigned char flags2;
    unsigned char flags3;
    unsigned char version;
};

class SaveLoadGame
{
  public:
    bool IsLoading();                             // 0x862110
    void ReadData(void* dst, unsigned int size);  // 0x8579e0
    LoadingFormInfo* GetLoadingForm();            // 0x4fd3c0
    unsigned char GetVersion();                   // 0x8df040
    unsigned int GetOffset();                     // 0x825c00
};

extern SaveLoadGame* DAT_011de45c;

TESForm* LookupFormByID(unsigned int formID);  // 0x4839c0
void LogSaveError(const char* fmt, ...);       // 0x5b5e40

class LoadItem
{
  public:
    void* unk00;
    int unk04;
    void* unk08;
    LoadItem();             // 0x76b630
    void Prepare();         // 0x4be930
    LoadItem* GetLoadedForm();  // 0x44ddc0
    void Finish();          // 0x4bc780
    ~LoadItem();
};

class LoadItemList
{
  public:
    void AddHead(LoadItem** item);  // 0x5ae3d0
};

class FUN_004d3cc0_cls
{
  public:
    LoadItemList* pItems;
    void FinishLoad();  // 0x4cbbc0
    void FUN_004d3cc0();
};

// @fnv 0x004d3cc0
void FUN_004d3cc0_cls::FUN_004d3cc0()
{
    int i;
    unsigned short fSizeB = 0;
    unsigned int start2 = 0;
    unsigned short cnt_2;
    unsigned int marker9;
    LoadingFormInfo* info8;
    TESForm* _form;
    LoadItem* itemB;
    LoadingFormInfo* _info;
    unsigned int offset2;
    TESForm* form;
    if (DAT_011de45c->IsLoading())
    {
        DAT_011de45c->ReadData(&marker9, 4);
        if (marker9 != 0x424c4f4b)
        {
            info8 = DAT_011de45c->GetLoadingForm();
            if (info8 != 0)
            {
                _form = LookupFormByID(info8->formID);
                LogSaveError(
                    "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\InventoryChanges.cpp", 0x2871,
                    info8->formID, _form->GetName(), info8->version, *(unsigned int*)&info8->flags0);
            }
            else
            {
                LogSaveError(
                    "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Current version is %i",
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\InventoryChanges.cpp", 0x2871,
                    DAT_011de45c->GetVersion());
            }
        }
        start2 = DAT_011de45c->GetOffset();
        DAT_011de45c->ReadData(&fSizeB, 2);
    }
    DAT_011de45c->ReadData(&cnt_2, 2);
    for (i = 0; i < cnt_2; i++)
    {
        itemB = new LoadItem();
        itemB->Prepare();
        if (itemB->GetLoadedForm() != 0)
        {
            pItems->AddHead(&itemB);
        }
        else
        {
            itemB->Finish();
            delete itemB;
        }
    }
    FinishLoad();
    if (DAT_011de45c->IsLoading())
    {
        offset2 = DAT_011de45c->GetOffset();
        _info = DAT_011de45c->GetLoadingForm();
        if (_info != 0)
        {
            form = LookupFormByID(_info->formID);
            if (offset2 > start2 + fSizeB)
            {
                LogSaveError(
                    "SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                    offset2 - (start2 + fSizeB),
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\InventoryChanges.cpp", 0x2884,
                    _info->formID, form->GetName(), _info->version, *(unsigned int*)&_info->flags0);
            }
            else if (offset2 < start2 + fSizeB)
            {
                LogSaveError(
                    "SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                    start2 + fSizeB - offset2,
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\InventoryChanges.cpp", 0x2884,
                    _info->formID, form->GetName(), _info->version, *(unsigned int*)&_info->flags0);
            }
        }
        else
        {
            if (offset2 > start2 + fSizeB)
            {
                LogSaveError(
                    "SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Current version is %i",
                    offset2 - (start2 + fSizeB),
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\InventoryChanges.cpp", 0x2884,
                    DAT_011de45c->GetVersion());
            }
            else if (offset2 < start2 + fSizeB)
            {
                LogSaveError(
                    "SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Current version is %i",
                    start2 + fSizeB - offset2,
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\InventoryChanges.cpp", 0x2884,
                    DAT_011de45c->GetVersion());
            }
        }
    }
}

struct Blob4_4d4090
{
    int m_data;
    Blob4_4d4090(int v);
};

struct SaveBuffer_4d4090
{
    virtual TESIdleForm* GetSpeakerIdle();
    Blob4_4d4090 GetChangeFlags();
    void SetChangeFlags(Blob4_4d4090 flags);
    void SetSpeakerIdle(TESIdleForm* idle);
    unsigned int FUN_00865f20();
    void FUN_00865ff0(int, unsigned int);
};

struct ItemSave_4d4090
{
    void SavePerkList(SaveBuffer_4d4090* buffer);
};

struct InvChangesSave : InventoryChanges
{
    void FUN_004d4090(SaveBuffer_4d4090* buffer);
};

// Saves each non-null item change in the list to the buffer, then writes the count and restores the speaker idle and change flags.
// @fnv 0x004d4090
void InvChangesSave::FUN_004d4090(SaveBuffer_4d4090* buffer)
{
    TESIdleForm* savedIdle3 = buffer->GetSpeakerIdle();
    Blob4_4d4090 oldFlags = buffer->GetChangeFlags();
    buffer->SetSpeakerIdle(0);
    buffer->SetChangeFlags(0x400);
    int count7 = 0;
    unsigned int pos3 = buffer->FUN_00865f20();
    BSSimpleList<InventoryStackRecord*>* nodeTmp = m_pEntryList;
    while (nodeTmp != 0)
    {
        InventoryStackRecord* change5 = nodeTmp->GetItem();
        if (change5 != 0)
        {
            ((ItemSave_4d4090*)change5)->SavePerkList(buffer);
            count7++;
        }
        nodeTmp = nodeTmp->GetNext();
    }
    buffer->FUN_00865ff0(count7, pos3);
    buffer->SetSpeakerIdle(savedIdle3);
    buffer->SetChangeFlags(oldFlags);
}

struct WalkForm
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
    virtual bool excluded();
    int FUN_00401170();
    bool FUN_0046e8c0();
};
struct WalkBiped
{
    bool FUN_00480d90();
};
WalkBiped* GetFormAsBipedModel(WalkForm*);
struct WalkBaseEntry
{
    int count;
    WalkForm* form;
};
struct WalkBaseNode
{
    WalkBaseEntry** FUN_006815c0();
    WalkBaseNode* FUN_00726070();
};
struct WalkContainer
{
    WalkBaseNode* FUN_00717e50();
    int GetObjectCount(WalkForm*);
};
struct WalkChange
{
    WalkForm* FUN_0044ddc0();
    int FUN_00726070();
    void* FUN_00559450();
};
struct WalkNode
{
    WalkChange** FUN_006815c0();
    WalkNode* FUN_00726070();
};
struct WalkTemp
{
    void* extra;
    int count;
    WalkForm* form;
    WalkTemp();
    ~WalkTemp();
    void FUN_006ecd40(int);
    void FUN_00403550(WalkForm*);
};
struct WalkInventory
{
    WalkNode* first;
    WalkContainer* FUN_004bffb0();
    void* FUN_004bfba0(WalkForm*, int, int);
    int ForEachInventoryItem(bool(__cdecl* callback)(WalkTemp*, void*), void* context, int flags);
};
// Iterates base entries and change nodes, filters by flags, builds a WalkTemp per item and calls callback, returning the count processed.
// @fnv 0x004d4530
int WalkInventory::ForEachInventoryItem(bool(__cdecl* callback)(WalkTemp*, void*), void* context, int flags)
{
    int total_2 = 0;
    WalkBaseNode* base = FUN_004bffb0()->FUN_00717e50();
    while (base)
    {
        WalkBaseEntry* entryB = *base->FUN_006815c0();
        base = base->FUN_00726070();
        if (entryB)
        {
            if (FUN_004bfba0(entryB->form, 1, 0))
                continue;
            if (flags & 1)
            {
                if (entryB->form->excluded())
                    continue;
                WalkBiped* biped3 = GetFormAsBipedModel(entryB->form);
                if (biped3 && !biped3->FUN_00480d90())
                    continue;
                if (entryB->form->FUN_00401170() == 40)
                {
                    WalkForm* aWeapon = entryB->form;
                    if (aWeapon->FUN_0046e8c0())
                        continue;
                }
            }
            WalkTemp temp;
            temp.FUN_006ecd40(entryB->count);
            temp.FUN_00403550(entryB->form);
            total_2++;
            if (callback(&temp, context))
                return total_2;
        }
    }
    WalkNode* node7 = first;
    while (node7)
    {
        WalkChange* change3 = *node7->FUN_006815c0();
        node7 = node7->FUN_00726070();
        if (change3)
        {
            WalkForm* form5 = change3->FUN_0044ddc0();
            if (flags & 1)
            {
                if (form5->excluded())
                    continue;
                WalkBiped* biped4 = GetFormAsBipedModel(form5);
                if (biped4 && !biped4->FUN_00480d90())
                    continue;
                if (form5->FUN_00401170() == 40)
                {
                    WalkForm* weapon6 = form5;
                    if (weapon6->FUN_0046e8c0())
                        continue;
                }
            }
            int countB = change3->FUN_00726070() + FUN_004bffb0()->GetObjectCount(form5);
            if (!countB)
                continue;
            WalkTemp temp6;
            temp6.extra = change3->FUN_00559450();
            temp6.FUN_006ecd40(countB);
            temp6.FUN_00403550(form5);
            total_2++;
            if (callback(&temp6, context))
            {
                temp6.extra = 0;
                return total_2;
            }
            temp6.extra = 0;
        }
    }
    return total_2;
}

struct IterForm
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
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
    virtual bool IsFiltered();
    int FUN_00401170();
    bool FUN_0046e8c0();
};

struct BipedIter
{
    bool FUN_00480d90();
};
BipedIter* __cdecl GetFormAsBipedModel(IterForm*);
struct BaseEntryIter
{
    int count;
    IterForm* form;
};
struct BaseNodeIter
{
    BaseEntryIter** FUN_006815c0();
    BaseNodeIter* FUN_00726070();
};
struct ChangeIter
{
    IterForm* FUN_0044ddc0();
    int FUN_00726070();
    void* FUN_00559450();
};
struct ChangeNodeIter
{
    ChangeIter** FUN_006815c0();
    ChangeNodeIter* FUN_00726070();
};
struct IterContainer
{
    BaseNodeIter* FUN_00717e50();
    int GetObjectCount(IterForm*);
};
struct IterState
{
    void* extra;
    int unk04;
    int unk08;
    BaseNodeIter* base;
    ChangeNodeIter* change;
    bool done;
    void FUN_006ecd40(int);
    void FUN_00403550(IterForm*);
};
struct InventoryIterOwner
{
    ChangeNodeIter* changes;
    IterContainer* FUN_004bffb0();
    int FUN_004bfba0(IterForm*, int, int);
    bool AdvanceInventoryIterator(IterState*, void**, int);
};
// Advances the inventory iterator over base and change entries, applying flag-based filters, and fills state and out with the next matching entry.
// @fnv 0x004d4830
bool InventoryIterOwner::AdvanceInventoryIterator(IterState* state, void** out, int flags)
{
    if (state->done)
        return false;
    if (!state->base && !state->change)
        state->base = FUN_004bffb0()->FUN_00717e50();
    if (state->base)
    {
        while (state->base)
        {
            BaseEntryIter* entry7 = *state->base->FUN_006815c0();
            state->base = state->base->FUN_00726070();
            if (!state->base)
            {
                if (changes)
                    state->change = changes;
                else
                    state->done = true;
            }
            if (entry7)
            {
                if (FUN_004bfba0(entry7->form, 1, 0))
                    continue;
                if (flags & 1)
                {
                    if (entry7->form->IsFiltered())
                        continue;
                    BipedIter* biped3 = GetFormAsBipedModel(entry7->form);
                    if (biped3 && !biped3->FUN_00480d90())
                        continue;
                    if (entry7->form->FUN_00401170() == 40)
                    {
                        IterForm* aWeapon = entry7->form;
                        if (aWeapon->FUN_0046e8c0())
                            continue;
                    }
                }
                state->extra = 0;
                state->FUN_006ecd40(entry7->count);
                state->FUN_00403550(entry7->form);
                *out = state;
                return true;
            }
        }
    }
    if (state->change)
    {
        while (state->change)
        {
            ChangeIter* entry2 = *state->change->FUN_006815c0();
            state->change = state->change->FUN_00726070();
            if (!state->change)
                state->done = true;
            if (entry2)
            {
                IterForm* form2 = entry2->FUN_0044ddc0();
                if (flags & 1)
                {
                    if (form2->IsFiltered())
                        continue;
                    BipedIter* pChangeBipedModel = GetFormAsBipedModel(form2);
                    if (pChangeBipedModel && !pChangeBipedModel->FUN_00480d90())
                        continue;
                    if (form2->FUN_00401170() == 40)
                    {
                        IterForm* weapon6 = form2;
                        if (weapon6->FUN_0046e8c0())
                            continue;
                    }
                }
                int iChangeCount = entry2->FUN_00726070() + FUN_004bffb0()->GetObjectCount(form2);
                if (iChangeCount <= 0)
                    continue;
                *out = entry2;
                state->extra = entry2->FUN_00559450();
                state->FUN_006ecd40(iChangeCount);
                state->FUN_00403550(form2);
                *out = state;
                return true;
            }
        }
    }
    return false;
}

int __fastcall FNV_GetFormType(TESForm* pForm);

struct TopicEntry4d4 : FUN_004459e0
{
    TESForm* FUN_0044ddc0();
};

struct FUN_004bf630
{
    ~FUN_004bf630();
};

struct TopicForm4d4
{
    int FUN_004bd570(unsigned int uiIndex);
};

struct TopicList4d4
{
    void FUN_005ae3d0(FUN_004459e0*& pkItem);
};

struct FUN_004d4ca0_shell
{
    FUN_004bf630* FUN_004ca200();
    FUN_004459e0* GetNextInventoryEntry(FUN_004bf630* pkIter);
    void CollectTopicEntries(TESForm* pkForm, TopicList4d4* pkList);
};

// @fnv 0x004d4ca0
void FUN_004d4ca0_shell::CollectTopicEntries(TESForm* pkForm, TopicList4d4* pkList)
{
    if (!pkForm || !pkList)
        return;
    if (FNV_GetFormType(pkForm) != 0x28)
        return;
    FUN_004bf630* pkIter = FUN_004ca200();
    FUN_004459e0* pkItem = 0;
    TopicForm4d4* pNewkTopic = (TopicForm4d4*)pkForm;
    unsigned int uiFlagsCur = 0;
    do
    {
        pkItem = GetNextInventoryEntry(pkIter);
        if (pkItem)
        {
            if (FNV_GetFormType(((TopicEntry4d4*)pkItem)->FUN_0044ddc0()) == 0x67)
            {
                uiFlagsCur = (unsigned int)((TopicEntry4d4*)pkItem)->FUN_0044ddc0();
                if (uiFlagsCur == pNewkTopic->FUN_004bd570(1))
                    pkList->FUN_005ae3d0(pkItem);
                else if (uiFlagsCur == pNewkTopic->FUN_004bd570(2))
                    pkList->FUN_005ae3d0(pkItem);
                else if (uiFlagsCur == pNewkTopic->FUN_004bd570(4))
                    pkList->FUN_005ae3d0(pkItem);
            }
            else
            {
                delete pkItem;
            }
        }
    } while (pkItem);
    delete pkIter;
}

struct InvExtra
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    InvExtra();
    bool HasOnlyAllowedExtraData(int);
    bool CompareListForContainer(InvExtra*, int, int);
    short FUN_00418770();
    void FUN_00419ad0(unsigned short);
    void DuplicateExtraListForContainer(InvExtra*);
};
struct InvNode
{
    InvExtra* data;
    InvNode* next;
    InvNode();
    InvExtra** FUN_006815c0();
    InvNode* FUN_00726070();
    void FUN_005ae3d0(InvExtra*&);
};
struct InvEntry
{
    InvNode* list;
    int count;
    void* object;
    InvEntry(void*, int);
    InvNode* FUN_00559450();
    void* FUN_0044ddc0();
    int FUN_00726070();
    void FUN_006ecd40(int);
};
struct InvArray
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned FUN_0044ddc0();
    InvEntry*& FUN_00877a30(unsigned);
    unsigned FUN_007cb2e0(InvEntry*&);
};
float __cdecl FUN_0048ebc0(void*, bool);
struct InvHost
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000c;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001c;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002c;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003c;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004c;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005c;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006c;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007c;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008c;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009c;
    int unk00a0;
    int unk00a4;
    int unk00a8;
    int unk00ac;
    int unk00b0;
    int unk00b4;
    int unk00b8;
    int unk00bc;
    int unk00c0;
    int unk00c4;
    int unk00c8;
    int unk00cc;
    int unk00d0;
    int unk00d4;
    int unk00d8;
    int unk00dc;
    int unk00e0;
    int unk00e4;
    int unk00e8;
    int unk00ec;
    int unk00f0;
    int unk00f4;
    int unk00f8;
    int unk00fc;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010c;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011c;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012c;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013c;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014c;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015c;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016c;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017c;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018c;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019c;
    int unk01a0;
    int unk01a4;
    int unk01a8;
    int unk01ac;
    int unk01b0;
    int unk01b4;
    int unk01b8;
    int unk01bc;
    int unk01c0;
    int unk01c4;
    int unk01c8;
    int unk01cc;
    int unk01d0;
    int unk01d4;
    int unk01d8;
    int unk01dc;
    int unk01e0;
    int unk01e4;
    int unk01e8;
    int unk01ec;
    int unk01f0;
    int unk01f4;
    int unk01f8;
    int unk01fc;
    int unk0200;
    int unk0204;
    int unk0208;
    int unk020c;
    int unk0210;
    int unk0214;
    int unk0218;
    int unk021c;
    int unk0220;
    int unk0224;
    int unk0228;
    int unk022c;
    int unk0230;
    int unk0234;
    int unk0238;
    int unk023c;
    int unk0240;
    int unk0244;
    int unk0248;
    int unk024c;
    int unk0250;
    int unk0254;
    int unk0258;
    int unk025c;
    int unk0260;
    int unk0264;
    int unk0268;
    int unk026c;
    int unk0270;
    int unk0274;
    int unk0278;
    int unk027c;
    int unk0280;
    int unk0284;
    int unk0288;
    int unk028c;
    int unk0290;
    int unk0294;
    int unk0298;
    int unk029c;
    int unk02a0;
    int unk02a4;
    int unk02a8;
    int unk02ac;
    int unk02b0;
    int unk02b4;
    int unk02b8;
    int unk02bc;
    int unk02c0;
    int unk02c4;
    int unk02c8;
    int unk02cc;
    int unk02d0;
    int unk02d4;
    int unk02d8;
    int unk02dc;
    int unk02e0;
    int unk02e4;
    int unk02e8;
    int unk02ec;
    int unk02f0;
    int unk02f4;
    int unk02f8;
    int unk02fc;
    int unk0300;
    int unk0304;
    int unk0308;
    int unk030c;
    int unk0310;
    int unk0314;
    int unk0318;
    int unk031c;
    int unk0320;
    int unk0324;
    int unk0328;
    int unk032c;
    int unk0330;
    int unk0334;
    int unk0338;
    int unk033c;
    int unk0340;
    int unk0344;
    int unk0348;
    int unk034c;
    int unk0350;
    int unk0354;
    int unk0358;
    int unk035c;
    int unk0360;
    int unk0364;
    int unk0368;
    int unk036c;
    int unk0370;
    int unk0374;
    int unk0378;
    int unk037c;
    int unk0380;
    int unk0384;
    int unk0388;
    int unk038c;
    int unk0390;
    int unk0394;
    int unk0398;
    int unk039c;
    int unk03a0;
    int unk03a4;
    int unk03a8;
    int unk03ac;
    int unk03b0;
    int unk03b4;
    int unk03b8;
    int unk03bc;
    int unk03c0;
    int unk03c4;
    int unk03c8;
    int unk03cc;
    int unk03d0;
    int unk03d4;
    int unk03d8;
    int unk03dc;
    int unk03e0;
    int unk03e4;
    int unk03e8;
    int unk03ec;
    int unk03f0;
    int unk03f4;
    int unk03f8;
    int unk03fc;
    int unk0400;
    int unk0404;
    int unk0408;
    int unk040c;
    int unk0410;
    int unk0414;
    int unk0418;
    int unk041c;
    int unk0420;
    int unk0424;
    int unk0428;
    int unk042c;
    int unk0430;
    int unk0434;
    int unk0438;
    int unk043c;
    int unk0440;
    int unk0444;
    int unk0448;
    int unk044c;
    int unk0450;
    int unk0454;
    int unk0458;
    int unk045c;
    int unk0460;
    int unk0464;
    int unk0468;
    int unk046c;
    int unk0470;
    int unk0474;
    int unk0478;
    int unk047c;
    int unk0480;
    int unk0484;
    int unk0488;
    int unk048c;
    int unk0490;
    int unk0494;
    int unk0498;
    int unk049c;
    int unk04a0;
    int unk04a4;
    int unk04a8;
    int unk04ac;
    int unk04b0;
    int unk04b4;
    int unk04b8;
    int unk04bc;
    int unk04c0;
    int unk04c4;
    int unk04c8;
    int unk04cc;
    int unk04d0;
    int unk04d4;
    int unk04d8;
    int unk04dc;
    int unk04e0;
    int unk04e4;
    int unk04e8;
    int unk04ec;
    int unk04f0;
    int unk04f4;
    int unk04f8;
    int unk04fc;
    int unk0500;
    int unk0504;
    int unk0508;
    int unk050c;
    int unk0510;
    int unk0514;
    int unk0518;
    int unk051c;
    int unk0520;
    int unk0524;
    int unk0528;
    int unk052c;
    int unk0530;
    int unk0534;
    int unk0538;
    int unk053c;
    int unk0540;
    int unk0544;
    int unk0548;
    int unk054c;
    int unk0550;
    int unk0554;
    int unk0558;
    int unk055c;
    int unk0560;
    int unk0564;
    int unk0568;
    int unk056c;
    int unk0570;
    int unk0574;
    int unk0578;
    int unk057c;
    int unk0580;
    int unk0584;
    int unk0588;
    int unk058c;
    int unk0590;
    int unk0594;
    int unk0598;
    int unk059c;
    int unk05a0;
    int unk05a4;
    int unk05a8;
    int unk05ac;
    int unk05b0;
    int unk05b4;
    int unk05b8;
    int unk05bc;
    int unk05c0;
    int unk05c4;
    int unk05c8;
    int unk05cc;
    int unk05d0;
    int unk05d4;
    int unk05d8;
    int unk05dc;
    int unk05e0;
    int unk05e4;
    int unk05e8;
    int unk05ec;
    int unk05f0;
    int unk05f4;
    int unk05f8;
    int unk05fc;
    int unk0600;
    int unk0604;
    int unk0608;
    int unk060c;
    int unk0610;
    int unk0614;
    int unk0618;
    int unk061c;
    int unk0620;
    int unk0624;
    int unk0628;
    int unk062c;
    int unk0630;
    int unk0634;
    int unk0638;
    int unk063c;
    int unk0640;
    int unk0644;
    int unk0648;
    int unk064c;
    int unk0650;
    int unk0654;
    int unk0658;
    int unk065c;
    int unk0660;
    int unk0664;
    int unk0668;
    int unk066c;
    int unk0670;
    int unk0674;
    int unk0678;
    int unk067c;
    int unk0680;
    int unk0684;
    int unk0688;
    int unk068c;
    int unk0690;
    int unk0694;
    int unk0698;
    int unk069c;
    int unk06a0;
    int unk06a4;
    int unk06a8;
    int unk06ac;
    int unk06b0;
    int unk06b4;
    int unk06b8;
    int unk06bc;
    int unk06c0;
    int unk06c4;
    int unk06c8;
    int unk06cc;
    int unk06d0;
    int unk06d4;
    int unk06d8;
    int unk06dc;
    int unk06e0;
    int unk06e4;
    int unk06e8;
    int unk06ec;
    int unk06f0;
    int unk06f4;
    int unk06f8;
    int unk06fc;
    int unk0700;
    int unk0704;
    int unk0708;
    int unk070c;
    int unk0710;
    int unk0714;
    int unk0718;
    int unk071c;
    int unk0720;
    int unk0724;
    int unk0728;
    int unk072c;
    int unk0730;
    int unk0734;
    int unk0738;
    int unk073c;
    int unk0740;
    int unk0744;
    int unk0748;
    int unk074c;
    int unk0750;
    int unk0754;
    int unk0758;
    int unk075c;
    int unk0760;
    int unk0764;
    int unk0768;
    int unk076c;
    int unk0770;
    int unk0774;
    int unk0778;
    int unk077c;
    int unk0780;
    int unk0784;
    int unk0788;
    int unk078c;
    int unk0790;
    int unk0794;
    int unk0798;
    int unk079c;
    int unk07a0;
    int unk07a4;
    int unk07a8;
    int unk07ac;
    int unk07b0;
    int unk07b4;
    int unk07b8;
    int unk07bc;
    int unk07c0;
    int unk07c4;
    int unk07c8;
    int unk07cc;
    int unk07d0;
    int unk07d4;
    int unk07d8;
    int unk07dc;
    int unk07e0;
    int unk07e4;
    int unk07e8;
    int unk07ec;
    int unk07f0;
    int unk07f4;
    int unk07f8;
    int unk07fc;
    int unk0800;
    int unk0804;
    int unk0808;
    int unk080c;
    int unk0810;
    int unk0814;
    int unk0818;
    int unk081c;
    int unk0820;
    int unk0824;
    int unk0828;
    int unk082c;
    int unk0830;
    int unk0834;
    int unk0838;
    int unk083c;
    int unk0840;
    int unk0844;
    int unk0848;
    int unk084c;
    int unk0850;
    int unk0854;
    int unk0858;
    int unk085c;
    int unk0860;
    int unk0864;
    int unk0868;
    int unk086c;
    int unk0870;
    int unk0874;
    int unk0878;
    int unk087c;
    int unk0880;
    int unk0884;
    int unk0888;
    int unk088c;
    int unk0890;
    int unk0894;
    int unk0898;
    int unk089c;
    int unk08a0;
    int unk08a4;
    int unk08a8;
    int unk08ac;
    int unk08b0;
    int unk08b4;
    int unk08b8;
    int unk08bc;
    int unk08c0;
    int unk08c4;
    int unk08c8;
    int unk08cc;
    int unk08d0;
    int unk08d4;
    int unk08d8;
    int unk08dc;
    int unk08e0;
    int unk08e4;
    int unk08e8;
    int unk08ec;
    int unk08f0;
    int unk08f4;
    int unk08f8;
    int unk08fc;
    int unk0900;
    int unk0904;
    int unk0908;
    int unk090c;
    int unk0910;
    int unk0914;
    int unk0918;
    int unk091c;
    int unk0920;
    int unk0924;
    int unk0928;
    int unk092c;
    int unk0930;
    int unk0934;
    int unk0938;
    int unk093c;
    int unk0940;
    int unk0944;
    int unk0948;
    int unk094c;
    int unk0950;
    int unk0954;
    int unk0958;
    int unk095c;
    int unk0960;
    int unk0964;
    int unk0968;
    int unk096c;
    int unk0970;
    int unk0974;
    int unk0978;
    int unk097c;
    int unk0980;
    int unk0984;
    int unk0988;
    int unk098c;
    int unk0990;
    int unk0994;
    int unk0998;
    int unk099c;
    int unk09a0;
    int unk09a4;
    int unk09a8;
    int unk09ac;
    int unk09b0;
    int unk09b4;
    int unk09b8;
    int unk09bc;
    int unk09c0;
    int unk09c4;
    int unk09c8;
    int unk09cc;
    int unk09d0;
    int unk09d4;
    int unk09d8;
    int unk09dc;
    int unk09e0;
    int unk09e4;
    int unk09e8;
    int unk09ec;
    int unk09f0;
    int unk09f4;
    int unk09f8;
    int unk09fc;
    int unk0a00;
    int unk0a04;
    int unk0a08;
    int unk0a0c;
    int unk0a10;
    int unk0a14;
    int unk0a18;
    int unk0a1c;
    int unk0a20;
    int unk0a24;
    int unk0a28;
    int unk0a2c;
    int unk0a30;
    int unk0a34;
    int unk0a38;
    int unk0a3c;
    int unk0a40;
    int unk0a44;
    int unk0a48;
    int unk0a4c;
    int unk0a50;
    int unk0a54;
    int unk0a58;
    int unk0a5c;
    int unk0a60;
    int unk0a64;
    int unk0a68;
    int unk0a6c;
    int unk0a70;
    int unk0a74;
    int unk0a78;
    int unk0a7c;
    int unk0a80;
    int unk0a84;
    int unk0a88;
    int unk0a8c;
    int unk0a90;
    int unk0a94;
    int unk0a98;
    int unk0a9c;
    int unk0aa0;
    int unk0aa4;
    int unk0aa8;
    int unk0aac;
    int unk0ab0;
    int unk0ab4;
    int unk0ab8;
    int unk0abc;
    int unk0ac0;
    int unk0ac4;
    int unk0ac8;
    int unk0acc;
    int unk0ad0;
    int unk0ad4;
    int unk0ad8;
    int unk0adc;
    int unk0ae0;
    int unk0ae4;
    int unk0ae8;
    int unk0aec;
    int unk0af0;
    int unk0af4;
    int unk0af8;
    int unk0afc;
    int unk0b00;
    int unk0b04;
    int unk0b08;
    int unk0b0c;
    int unk0b10;
    int unk0b14;
    int unk0b18;
    int unk0b1c;
    int unk0b20;
    int unk0b24;
    int unk0b28;
    int unk0b2c;
    int unk0b30;
    int unk0b34;
    int unk0b38;
    int unk0b3c;
    int unk0b40;
    int unk0b44;
    int unk0b48;
    int unk0b4c;
    int unk0b50;
    int unk0b54;
    int unk0b58;
    int unk0b5c;
    int unk0b60;
    int unk0b64;
    int unk0b68;
    int unk0b6c;
    int unk0b70;
    int unk0b74;
    int unk0b78;
    int unk0b7c;
    int unk0b80;
    int unk0b84;
    int unk0b88;
    int unk0b8c;
    int unk0b90;
    int unk0b94;
    int unk0b98;
    int unk0b9c;
    int unk0ba0;
    int unk0ba4;
    int unk0ba8;
    int unk0bac;
    int unk0bb0;
    int unk0bb4;
    int unk0bb8;
    int unk0bbc;
    int unk0bc0;
    int unk0bc4;
    int unk0bc8;
    int unk0bcc;
    int unk0bd0;
    int unk0bd4;
    int unk0bd8;
    int unk0bdc;
    int unk0be0;
    int unk0be4;
    int unk0be8;
    int unk0bec;
    int unk0bf0;
    int unk0bf4;
    int unk0bf8;
    int unk0bfc;
    int unk0c00;
    int unk0c04;
    int unk0c08;
    int unk0c0c;
    int unk0c10;
    int unk0c14;
    int unk0c18;
    int unk0c1c;
    int unk0c20;
    int unk0c24;
    int unk0c28;
    int unk0c2c;
    int unk0c30;
    int unk0c34;
    int unk0c38;
    int unk0c3c;
    int unk0c40;
    int unk0c44;
    int unk0c48;
    int unk0c4c;
    int unk0c50;
    int unk0c54;
    int unk0c58;
    int unk0c5c;
    int unk0c60;
    int unk0c64;
    int unk0c68;
    int unk0c6c;
    int unk0c70;
    int unk0c74;
    int unk0c78;
    int unk0c7c;
    int unk0c80;
    int unk0c84;
    int unk0c88;
    int unk0c8c;
    int unk0c90;
    int unk0c94;
    int unk0c98;
    int unk0c9c;
    int unk0ca0;
    int unk0ca4;
    int unk0ca8;
    int unk0cac;
    int unk0cb0;
    int unk0cb4;
    int unk0cb8;
    int unk0cbc;
    int unk0cc0;
    int unk0cc4;
    int unk0cc8;
    int unk0ccc;
    int unk0cd0;
    int unk0cd4;
    int unk0cd8;
    int unk0cdc;
    int unk0ce0;
    int unk0ce4;
    int unk0ce8;
    int unk0cec;
    int unk0cf0;
    int unk0cf4;
    int unk0cf8;
    int unk0cfc;
    int unk0d00;
    int unk0d04;
    int unk0d08;
    int unk0d0c;
    int unk0d10;
    int unk0d14;
    int unk0d18;
    int unk0d1c;
    int unk0d20;
    int unk0d24;
    int unk0d28;
    int unk0d2c;
    int unk0d30;
    int unk0d34;
    int unk0d38;
    int unk0d3c;
    int unk0d40;
    int unk0d44;
    int unk0d48;
    int unk0d4c;
    int unk0d50;
    int unk0d54;
    int unk0d58;
    int unk0d5c;
    int unk0d60;
    int unk0d64;
    int unk0d68;
    int unk0d6c;
    int unk0d70;
    int unk0d74;
    int unk0d78;
    int unk0d7c;
    int unk0d80;
    int unk0d84;
    int unk0d88;
    int unk0d8c;
    int unk0d90;
    int unk0d94;
    int unk0d98;
    int unk0d9c;
    int unk0da0;
    int unk0da4;
    int unk0da8;
    int unk0dac;
    int unk0db0;
    int unk0db4;
    int unk0db8;
    int unk0dbc;
    int unk0dc0;
    int unk0dc4;
    int unk0dc8;
    int unk0dcc;
    int unk0dd0;
    int unk0dd4;
    int unk0dd8;
    int unk0ddc;
    int unk0de0;
    int unk0de4;
    int unk0de8;
    int unk0dec;
    int unk0df0;
    InvArray entries;
    float weight;
    bool FUN_004d1360();
    void FUN_009687b0(void* object, InvExtra* extra, int amount);
};
// Adds amount of object to a matching entry (merging into extra nodes when given), creating a new entry if none matches, then updates weight.
// @fnv 0x009687b0
void InvHost::FUN_009687b0(void* object, InvExtra* extra, int amount)
{
    bool found = false;
    for (unsigned index = 0; !found && index < entries.FUN_0044ddc0(); ++index)
    {
        InvEntry* entry = entries.FUN_00877a30(index);
        if (entries.FUN_00877a30(index)->FUN_0044ddc0() == object)
        {
            bool empty = !entry->FUN_00559450() || !*entry->FUN_00559450()->FUN_006815c0() ||
                         (*entry->FUN_00559450()->FUN_006815c0())->HasOnlyAllowedExtraData(0);
            if (!extra)
            {
                if (empty)
                {
                    entry->FUN_006ecd40(entries.FUN_00877a30(index)->FUN_00726070() + amount);
                    found = true;
                }
            }
            else
            {
                for (InvNode* node = entry->FUN_00559450(); !found && node && *node->FUN_006815c0();
                     node = node->FUN_00726070())
                {
                    if (!(*node->FUN_006815c0())->CompareListForContainer(extra, 1, 0) &&
                        !extra->CompareListForContainer(*node->FUN_006815c0(), 1, 0))
                    {
                        entry->FUN_006ecd40(entries.FUN_00877a30(index)->FUN_00726070() + amount);
                        (*node->FUN_006815c0())->FUN_00419ad0((*node->FUN_006815c0())->FUN_00418770() + amount);
                        found = true;
                    }
                }
                if (!found && extra->HasOnlyAllowedExtraData(0) && empty)
                {
                    InvExtra* copy = new InvExtra;
                    copy->DuplicateExtraListForContainer(extra);
                    copy->FUN_00419ad0((unsigned short)amount);
                    if (!entry->FUN_00559450())
                        entry->list = new InvNode;
                    entry->FUN_00559450()->FUN_005ae3d0(copy);
                    entry->FUN_006ecd40(entries.FUN_00877a30(index)->FUN_00726070() + amount);
                    found = true;
                }
            }
        }
    }
    if (!found)
    {
        InvEntry* added = new InvEntry(object, amount);
        if (extra)
        {
            InvExtra* pExtraCopy2 = new InvExtra;
            pExtraCopy2->DuplicateExtraListForContainer(extra);
            pExtraCopy2->FUN_00419ad0((unsigned short)amount);
            added->FUN_00559450()->FUN_005ae3d0(pExtraCopy2);
        }
        entries.FUN_007cb2e0(added);
    }
    weight += FUN_0048ebc0(object, FUN_004d1360()) * amount;
}

extern const char g_inventoryChangesSourceFilename[];
void* operator new(unsigned int);
struct Transfer4c37C37Form
{
    virtual void Pad48_0();
    virtual void Pad48_1();
    virtual void Pad48_2();
    virtual void Pad48_3();
    virtual void Pad48_4();
    virtual void Pad48_5();
    virtual void Pad48_6();
    virtual void Pad48_7();
    virtual void Pad48_8();
    virtual void Pad48_9();
    virtual void Pad48_10();
    virtual void Pad48_11();
    virtual void Pad48_12();
    virtual void Pad48_13();
    virtual void Pad48_14();
    virtual void Pad48_15();
    virtual void Pad48_16();
    virtual void Pad48_17();
    virtual void Vcall48(int arg);
    virtual void Pad190_19();
    virtual void Pad190_20();
    virtual void Pad190_21();
    virtual void Pad190_22();
    virtual void Pad190_23();
    virtual void Pad190_24();
    virtual void Pad190_25();
    virtual void Pad190_26();
    virtual void Pad190_27();
    virtual void Pad190_28();
    virtual void Pad190_29();
    virtual void Pad190_30();
    virtual void Pad190_31();
    virtual void Pad190_32();
    virtual void Pad190_33();
    virtual void Pad190_34();
    virtual void Pad190_35();
    virtual void Pad190_36();
    virtual void Pad190_37();
    virtual void Pad190_38();
    virtual void Pad190_39();
    virtual void Pad190_40();
    virtual void Pad190_41();
    virtual void Pad190_42();
    virtual void Pad190_43();
    virtual void Pad190_44();
    virtual void Pad190_45();
    virtual void Pad190_46();
    virtual void Pad190_47();
    virtual void Pad190_48();
    virtual void Pad190_49();
    virtual void Pad190_50();
    virtual void Pad190_51();
    virtual void Pad190_52();
    virtual void Pad190_53();
    virtual void Pad190_54();
    virtual void Pad190_55();
    virtual void Pad190_56();
    virtual void Pad190_57();
    virtual void Pad190_58();
    virtual void Pad190_59();
    virtual void Pad190_60();
    virtual void Pad190_61();
    virtual void Pad190_62();
    virtual void Pad190_63();
    virtual void Pad190_64();
    virtual void Pad190_65();
    virtual void Pad190_66();
    virtual void Pad190_67();
    virtual void Pad190_68();
    virtual void Pad190_69();
    virtual void Pad190_70();
    virtual void Pad190_71();
    virtual void Pad190_72();
    virtual void Pad190_73();
    virtual void Pad190_74();
    virtual void Pad190_75();
    virtual void Pad190_76();
    virtual void Pad190_77();
    virtual void Pad190_78();
    virtual void Pad190_79();
    virtual void Pad190_80();
    virtual void Pad190_81();
    virtual void Pad190_82();
    virtual void Pad190_83();
    virtual void Pad190_84();
    virtual void Pad190_85();
    virtual void Pad190_86();
    virtual void Pad190_87();
    virtual void Pad190_88();
    virtual void Pad190_89();
    virtual void Pad190_90();
    virtual void Pad190_91();
    virtual void Pad190_92();
    virtual void Pad190_93();
    virtual void Pad190_94();
    virtual void Pad190_95();
    virtual void Pad190_96();
    virtual void Pad190_97();
    virtual void Pad190_98();
    virtual void Pad190_99();
    virtual void Vcall190(int a, void* b, int c);
};
struct Transfer4c37Obj44
{
    int FUN_0044ddc0();
};
struct Transfer4c37Cont14c
{
    virtual void Pad14c_0();
    virtual void Pad14c_1();
    virtual void Pad14c_2();
    virtual void Pad14c_3();
    virtual void Pad14c_4();
    virtual void Pad14c_5();
    virtual void Pad14c_6();
    virtual void Pad14c_7();
    virtual void Pad14c_8();
    virtual void Pad14c_9();
    virtual void Pad14c_10();
    virtual void Pad14c_11();
    virtual void Pad14c_12();
    virtual void Pad14c_13();
    virtual void Pad14c_14();
    virtual void Pad14c_15();
    virtual void Pad14c_16();
    virtual void Pad14c_17();
    virtual void Pad14c_18();
    virtual void Pad14c_19();
    virtual void Pad14c_20();
    virtual void Pad14c_21();
    virtual void Pad14c_22();
    virtual void Pad14c_23();
    virtual void Pad14c_24();
    virtual void Pad14c_25();
    virtual void Pad14c_26();
    virtual void Pad14c_27();
    virtual void Pad14c_28();
    virtual void Pad14c_29();
    virtual void Pad14c_30();
    virtual void Pad14c_31();
    virtual void Pad14c_32();
    virtual void Pad14c_33();
    virtual void Pad14c_34();
    virtual void Pad14c_35();
    virtual void Pad14c_36();
    virtual void Pad14c_37();
    virtual void Pad14c_38();
    virtual void Pad14c_39();
    virtual void Pad14c_40();
    virtual void Pad14c_41();
    virtual void Pad14c_42();
    virtual void Pad14c_43();
    virtual void Pad14c_44();
    virtual void Pad14c_45();
    virtual void Pad14c_46();
    virtual void Pad14c_47();
    virtual void Pad14c_48();
    virtual void Pad14c_49();
    virtual void Pad14c_50();
    virtual void Pad14c_51();
    virtual void Pad14c_52();
    virtual void Pad14c_53();
    virtual void Pad14c_54();
    virtual void Pad14c_55();
    virtual void Pad14c_56();
    virtual void Pad14c_57();
    virtual void Pad14c_58();
    virtual void Pad14c_59();
    virtual void Pad14c_60();
    virtual void Pad14c_61();
    virtual void Pad14c_62();
    virtual void Pad14c_63();
    virtual void Pad14c_64();
    virtual void Pad14c_65();
    virtual void Pad14c_66();
    virtual void Pad14c_67();
    virtual void Pad14c_68();
    virtual void Pad14c_69();
    virtual void Pad14c_70();
    virtual void Pad14c_71();
    virtual void Pad14c_72();
    virtual void Pad14c_73();
    virtual void Pad14c_74();
    virtual void Pad14c_75();
    virtual void Pad14c_76();
    virtual void Pad14c_77();
    virtual void Pad14c_78();
    virtual void Pad14c_79();
    virtual void Pad14c_80();
    virtual void Pad14c_81();
    virtual void Pad14c_82();
    virtual Transfer4c37Obj44* Vcall14c();
};
struct Transfer4c37MidObj;
struct Transfer4c37C37Obj
{
    virtual void Pad100_0();
    virtual void Pad100_1();
    virtual void Pad100_2();
    virtual void Pad100_3();
    virtual void Pad100_4();
    virtual void Pad100_5();
    virtual void Pad100_6();
    virtual void Pad100_7();
    virtual void Pad100_8();
    virtual void Pad100_9();
    virtual void Pad100_10();
    virtual void Pad100_11();
    virtual void Pad100_12();
    virtual void Pad100_13();
    virtual void Pad100_14();
    virtual void Pad100_15();
    virtual void Pad100_16();
    virtual void Pad100_17();
    virtual void Pad100_18();
    virtual void Pad100_19();
    virtual void Pad100_20();
    virtual void Pad100_21();
    virtual void Pad100_22();
    virtual void Pad100_23();
    virtual void Pad100_24();
    virtual void Pad100_25();
    virtual void Pad100_26();
    virtual void Pad100_27();
    virtual void Pad100_28();
    virtual void Pad100_29();
    virtual void Pad100_30();
    virtual void Pad100_31();
    virtual void Pad100_32();
    virtual void Pad100_33();
    virtual void Pad100_34();
    virtual void Pad100_35();
    virtual void Pad100_36();
    virtual void Pad100_37();
    virtual void Pad100_38();
    virtual void Pad100_39();
    virtual void Pad100_40();
    virtual void Pad100_41();
    virtual void Pad100_42();
    virtual void Pad100_43();
    virtual void Pad100_44();
    virtual void Pad100_45();
    virtual void Pad100_46();
    virtual void Pad100_47();
    virtual void Pad100_48();
    virtual void Pad100_49();
    virtual void Pad100_50();
    virtual void Pad100_51();
    virtual void Pad100_52();
    virtual void Pad100_53();
    virtual void Pad100_54();
    virtual void Pad100_55();
    virtual void Pad100_56();
    virtual void Pad100_57();
    virtual void Pad100_58();
    virtual void Pad100_59();
    virtual void Pad100_60();
    virtual void Pad100_61();
    virtual void Pad100_62();
    virtual void Pad100_63();
    virtual bool Vcall100();
    virtual void Pad188_65();
    virtual void Pad188_66();
    virtual void Pad188_67();
    virtual void Pad188_68();
    virtual void Pad188_69();
    virtual void Pad188_70();
    virtual void Pad188_71();
    virtual void Pad188_72();
    virtual void Pad188_73();
    virtual void Pad188_74();
    virtual void Pad188_75();
    virtual void Pad188_76();
    virtual void Pad188_77();
    virtual void Pad188_78();
    virtual void Pad188_79();
    virtual void Pad188_80();
    virtual void Pad188_81();
    virtual void Pad188_82();
    virtual void Pad188_83();
    virtual void Pad188_84();
    virtual void Pad188_85();
    virtual void Pad188_86();
    virtual void Pad188_87();
    virtual void Pad188_88();
    virtual void Pad188_89();
    virtual void Pad188_90();
    virtual void Pad188_91();
    virtual void Pad188_92();
    virtual void Pad188_93();
    virtual void Pad188_94();
    virtual void Pad188_95();
    virtual void Pad188_96();
    virtual void Pad188_97();
    virtual bool Vcall188(int a, int b, void* c);
    virtual void Pad3ec_99();
    virtual void Pad3ec_100();
    virtual void Pad3ec_101();
    virtual void Pad3ec_102();
    virtual void Pad3ec_103();
    virtual void Pad3ec_104();
    virtual void Pad3ec_105();
    virtual void Pad3ec_106();
    virtual void Pad3ec_107();
    virtual void Pad3ec_108();
    virtual void Pad3ec_109();
    virtual void Pad3ec_110();
    virtual void Pad3ec_111();
    virtual void Pad3ec_112();
    virtual void Pad3ec_113();
    virtual void Pad3ec_114();
    virtual void Pad3ec_115();
    virtual void Pad3ec_116();
    virtual void Pad3ec_117();
    virtual void Pad3ec_118();
    virtual void Pad3ec_119();
    virtual void Pad3ec_120();
    virtual void Pad3ec_121();
    virtual void Pad3ec_122();
    virtual void Pad3ec_123();
    virtual void Pad3ec_124();
    virtual void Pad3ec_125();
    virtual void Pad3ec_126();
    virtual void Pad3ec_127();
    virtual void Pad3ec_128();
    virtual void Pad3ec_129();
    virtual void Pad3ec_130();
    virtual void Pad3ec_131();
    virtual void Pad3ec_132();
    virtual void Pad3ec_133();
    virtual void Pad3ec_134();
    virtual void Pad3ec_135();
    virtual void Pad3ec_136();
    virtual void Pad3ec_137();
    virtual void Pad3ec_138();
    virtual void Pad3ec_139();
    virtual void Pad3ec_140();
    virtual void Pad3ec_141();
    virtual void Pad3ec_142();
    virtual void Pad3ec_143();
    virtual void Pad3ec_144();
    virtual void Pad3ec_145();
    virtual void Pad3ec_146();
    virtual void Pad3ec_147();
    virtual void Pad3ec_148();
    virtual void Pad3ec_149();
    virtual void Pad3ec_150();
    virtual void Pad3ec_151();
    virtual void Pad3ec_152();
    virtual void Pad3ec_153();
    virtual void Pad3ec_154();
    virtual void Pad3ec_155();
    virtual void Pad3ec_156();
    virtual void Pad3ec_157();
    virtual void Pad3ec_158();
    virtual void Pad3ec_159();
    virtual void Pad3ec_160();
    virtual void Pad3ec_161();
    virtual void Pad3ec_162();
    virtual void Pad3ec_163();
    virtual void Pad3ec_164();
    virtual void Pad3ec_165();
    virtual void Pad3ec_166();
    virtual void Pad3ec_167();
    virtual void Pad3ec_168();
    virtual void Pad3ec_169();
    virtual void Pad3ec_170();
    virtual void Pad3ec_171();
    virtual void Pad3ec_172();
    virtual void Pad3ec_173();
    virtual void Pad3ec_174();
    virtual void Pad3ec_175();
    virtual void Pad3ec_176();
    virtual void Pad3ec_177();
    virtual void Pad3ec_178();
    virtual void Pad3ec_179();
    virtual void Pad3ec_180();
    virtual void Pad3ec_181();
    virtual void Pad3ec_182();
    virtual void Pad3ec_183();
    virtual void Pad3ec_184();
    virtual void Pad3ec_185();
    virtual void Pad3ec_186();
    virtual void Pad3ec_187();
    virtual void Pad3ec_188();
    virtual void Pad3ec_189();
    virtual void Pad3ec_190();
    virtual void Pad3ec_191();
    virtual void Pad3ec_192();
    virtual void Pad3ec_193();
    virtual void Pad3ec_194();
    virtual void Pad3ec_195();
    virtual void Pad3ec_196();
    virtual void Pad3ec_197();
    virtual void Pad3ec_198();
    virtual void Pad3ec_199();
    virtual void Pad3ec_200();
    virtual void Pad3ec_201();
    virtual void Pad3ec_202();
    virtual void Pad3ec_203();
    virtual void Pad3ec_204();
    virtual void Pad3ec_205();
    virtual void Pad3ec_206();
    virtual void Pad3ec_207();
    virtual void Pad3ec_208();
    virtual void Pad3ec_209();
    virtual void Pad3ec_210();
    virtual void Pad3ec_211();
    virtual void Pad3ec_212();
    virtual void Pad3ec_213();
    virtual void Pad3ec_214();
    virtual void Pad3ec_215();
    virtual void Pad3ec_216();
    virtual void Pad3ec_217();
    virtual void Pad3ec_218();
    virtual void Pad3ec_219();
    virtual void Pad3ec_220();
    virtual void Pad3ec_221();
    virtual void Pad3ec_222();
    virtual void Pad3ec_223();
    virtual void Pad3ec_224();
    virtual void Pad3ec_225();
    virtual void Pad3ec_226();
    virtual void Pad3ec_227();
    virtual void Pad3ec_228();
    virtual void Pad3ec_229();
    virtual void Pad3ec_230();
    virtual void Pad3ec_231();
    virtual void Pad3ec_232();
    virtual void Pad3ec_233();
    virtual void Pad3ec_234();
    virtual void Pad3ec_235();
    virtual void Pad3ec_236();
    virtual void Pad3ec_237();
    virtual void Pad3ec_238();
    virtual void Pad3ec_239();
    virtual void Pad3ec_240();
    virtual void Pad3ec_241();
    virtual void Pad3ec_242();
    virtual void Pad3ec_243();
    virtual void Pad3ec_244();
    virtual void Pad3ec_245();
    virtual void Pad3ec_246();
    virtual void Pad3ec_247();
    virtual void Pad3ec_248();
    virtual void Pad3ec_249();
    virtual void Pad3ec_250();
    virtual void Vcall3ec(int a, int b, int c, int d);
    Transfer4c37Cont14c* FUN_008d8520();
    int FUN_008d6f30();
    void* FUN_007af430();
    bool FUN_00440da0();
    bool FUN_0088d7d0(int a, int b, void* c, int d, int e, int f);
    Transfer4c37MidObj* FUN_005d43c0();
    int FUN_00567790();
    int FUN_00966a70(int a, int b);
    void FUN_0094fd30(int a);
    int FUN_008a1710();
};

struct Transfer4c37Form4
{
    virtual ~Transfer4c37Form4();
    int ItemsInList();
    int GetExtraData(int a);
    short FUN_00418770();
    void FUN_0042dec0();
};
struct Transfer4c37FirstObj
{
    void _ref_00905330(Transfer4c37Form4** pp);
};
struct Transfer4c37NewObj
{
    void* m00;
    int m04;
    int m08;
    int FUN_004459e0(int a);
    Transfer4c37NewObj();
    ~Transfer4c37NewObj();
    int _ref_00726070();
    void FUN_006ecd40(int a);
    int FUN_00559450();
    int FUN_0044ddc0();
    void ClearExtraDataList();
};
struct Transfer4c37Ret720
{
    int m00;
    int m04;
    int m08;
    int m0c;
};
struct Transfer4c37Obj20
{
    virtual ~Transfer4c37Obj20();
    Transfer4c37Obj20();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    void SetLeveledItemIndex(int a);
    int FUN_0041d000();
    void CopyListForReference(void* a, int b);
    void FUN_00419700(void* a);
    void FUN_00419ad0(int a);
    int ItemsInList();
    short FUN_00418770();
    void FUN_0041aed0();
    void* FUN_00418660();
    bool FUN_004bca60();
};
struct Transfer4c37ItemObj;
struct Transfer4c37EntryHeadS
{
    void _ref_00905330(Transfer4c37ItemObj** pp);
    void FUN_005ae3d0(Transfer4c37Obj20** pp);
};
struct Transfer4c37Node84
{
    Transfer4c37ItemObj** FUN_006815c0();
    Transfer4c37Node84* FUN_00726070();
};
unsigned char __cdecl FUN_00481f10(int a);
unsigned char __cdecl FUN_00702680(int a, int b);
int __fastcall FUN_00401170(int a);
void* __cdecl FUN_00401000(int a);
struct Transfer4c37Obj96
{
    void* item;
    void* next;
    Transfer4c37Obj96();
};
struct Transfer4c37CurHead
{
    void FUN_005ae3d0(void* pp);
};
struct Transfer4c37MidObj
{
    void CopyListForReference(void* a, int b);
    void RemoveExtraData30();
    void FUN_0041c900();
    int FUN_0041b320();
    void FUN_0041b2a0(void* a);
    int FUN_004216f0();
};
struct Transfer4c37AuxObj
{
    int FUN_005f0cc0();
};
struct Transfer4c37ResObj
{
    virtual void RPad_0();
    virtual void RPad_1();
    virtual void RPad_2();
    virtual void RPad_3();
    virtual void RPad_4();
    virtual void RPad_5();
    virtual void RPad_6();
    virtual void RPad_7();
    virtual void RPad_8();
    virtual void RPad_9();
    virtual void RPad_10();
    virtual void RPad_11();
    virtual void RPad_12();
    virtual void RPad_13();
    virtual void RPad_14();
    virtual void RPad_15();
    virtual void RPad_16();
    virtual void RPad_17();
    virtual void Vcall48(int a);
    virtual void RPadC4_19();
    virtual void RPadC4_20();
    virtual void RPadC4_21();
    virtual void RPadC4_22();
    virtual void RPadC4_23();
    virtual void RPadC4_24();
    virtual void RPadC4_25();
    virtual void RPadC4_26();
    virtual void RPadC4_27();
    virtual void RPadC4_28();
    virtual void RPadC4_29();
    virtual void RPadC4_30();
    virtual void RPadC4_31();
    virtual void RPadC4_32();
    virtual void RPadC4_33();
    virtual void RPadC4_34();
    virtual void RPadC4_35();
    virtual void RPadC4_36();
    virtual void RPadC4_37();
    virtual void RPadC4_38();
    virtual void RPadC4_39();
    virtual void RPadC4_40();
    virtual void RPadC4_41();
    virtual void RPadC4_42();
    virtual void RPadC4_43();
    virtual void RPadC4_44();
    virtual void RPadC4_45();
    virtual void RPadC4_46();
    virtual void RPadC4_47();
    virtual void RPadC4_48();
    virtual void VcallC4(int a);
    void FUN_00567490(float f);
    Transfer4c37MidObj* FUN_005d43c0();
    int FUN_00567770();
    void FUN_00567ad0(void* a);
    void* FUN_007af430();
};
struct Transfer4c37M68Obj
{
    int FUN_00546a40();
    unsigned char FUN_00546ca0(void* a);
};
struct Transfer4c37M00Obj
{
    bool FUN_008256d0();
};
struct Transfer4c37LogObj
{
    const char* FUN_004c69f0();
};
extern Transfer4c37LogObj DAT_011d31f8;
int __cdecl DispatchMessageToSink(const char*, int, const char*, int, float, int);
struct Transfer4c37T70Obj
{
    int GetWorldModel(int a);
};

void __cdecl FUN_005ac750(void* a, void* b, int c);
struct Transfer4c37ItemObj
{
    int ItemsInList();
    short FUN_00418770();
    bool FUN_00418ab0(int a);
    void* FUN_00418660();
    int FUN_0041c8d0();
    float FUN_00418860();
    bool FUN_00418750();
    Transfer4c37Ret720* GetExtraLeveledItem();
    void* FUN_00418800();
    void FUN_00419ad0(int a);
    int FUN_0041d000();
    signed char GetExtraByteValue();
    virtual ~Transfer4c37ItemObj();
    bool FUN_004bca60();
    int FUN_0041b010(int a);
    void FUN_0041c900();
    void FUN_00419700(void* a);
};
struct Transfer4c37EntryFirst
{
    Transfer4c37ItemObj** _ref_006815c0();
    Transfer4c37EntryFirst* FUN_00726070();
};
struct Transfer4c37Tail470
{
    void FUN_00470470();
};
struct Transfer4c37Entry
{
    ~Transfer4c37Entry();
    void* m00;
    int m04;
    bool FUN_004bddd0(int a);
    int FUN_004bc980();
    int FUN_004bc8f0(int a);
    void* FUN_004bde40();
    int FUN_0044ddc0();
    int FUN_00726070();
    bool FUN_004bcb70();
    void ClearExtraDataList();
    int m08;
    void* FUN_00559450();
};
struct Transfer4c37Cont
{
    int FUN_00482a90(int a);
};
struct Transfer4c37EntryNew
{
    void* extras;
    int count;
    void* form;
    Transfer4c37EntryNew(int a, int b);
};
struct Transfer4c37ThisHead
{
    void FUN_00905820(Transfer4c37Entry** pp);
    void _ref_00905330(Transfer4c37Entry** pp);
};
struct Transfer4c37D7Obj
{
    bool FUN_0047d7c0();
};
struct Transfer4c37Sub100
{
    virtual void SPad_0();
    virtual void SPad_1();
    virtual void SPad_2();
    virtual float Vcall3(int a);
};
struct Transfer4c37ActorValueView
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
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    Transfer4c37Sub100 values;
};
struct Transfer4c37Glob20
{
    float* FUN_00403e20();
};
extern Transfer4c37Glob20 DAT_011cde20;
int __cdecl FUN_0047e040(float a);
int __cdecl FUN_00ec62c0(float a);
struct Transfer4c37FormFull
{
    virtual void PadF_0();
    virtual void PadF_1();
    virtual void PadF_2();
    virtual void PadF_3();
    virtual void PadF_4();
    virtual void PadF_5();
    virtual void PadF_6();
    virtual void PadF_7();
    virtual void PadF_8();
    virtual void PadF_9();
    virtual void PadF_10();
    virtual void PadF_11();
    virtual void PadF_12();
    virtual void PadF_13();
    virtual void PadF_14();
    virtual void PadF_15();
    virtual void PadF_16();
    virtual void PadF_17();
    virtual void Vcall48(int arg);
    virtual void PadF_19();
    virtual void PadF_20();
    virtual void PadF_21();
    virtual void PadF_22();
    virtual void PadF_23();
    virtual void PadF_24();
    virtual void PadF_25();
    virtual void PadF_26();
    virtual void PadF_27();
    virtual void PadF_28();
    virtual void PadF_29();
    virtual void PadF_30();
    virtual void PadF_31();
    virtual void PadF_32();
    virtual void PadF_33();
    virtual void PadF_34();
    virtual void PadF_35();
    virtual void PadF_36();
    virtual void PadF_37();
    virtual void PadF_38();
    virtual void PadF_39();
    virtual void PadF_40();
    virtual void PadF_41();
    virtual void PadF_42();
    virtual void PadF_43();
    virtual void PadF_44();
    virtual void PadF_45();
    virtual void PadF_46();
    virtual void PadF_47();
    virtual void PadF_48();
    virtual void PadF_49();
    virtual void PadF_50();
    virtual void PadF_51();
    virtual void PadF_52();
    virtual void PadF_53();
    virtual void PadF_54();
    virtual void PadF_55();
    virtual void PadF_56();
    virtual void PadF_57();
    virtual void PadF_58();
    virtual void PadF_59();
    virtual void PadF_60();
    virtual void PadF_61();
    virtual void PadF_62();
    virtual void PadF_63();
    virtual bool Vcall100();
    int FUN_0088c830(int a, int b, void* c, int d, int e, int f);
};
struct Transfer4c37C37This
{
    int m00;
    Transfer4c37FormFull* m04;
    float m08;
    float m0c;
    unsigned char m10;
    Transfer4c37Cont* FUN_004bffb0();
    Transfer4c37Entry* FUN_004bfba0(int a, int b, int c);
    void SetInventorySlotExtraData(Transfer4c37Entry* e, void* f, int v);
    Transfer4c37ResObj* PlaceObject(void* a, int b, int c, int d, int e, int f);
    int FUN_004c37d0(Transfer4c37C37Obj* p0, int p1, unsigned char p2, int p3, Transfer4c37Form4* p4, unsigned char p5,
                     Transfer4c37C37Form* p6, int p7, int p8, unsigned char p9, unsigned char p10,
                     Transfer4c37Entry* p11);
};
// @fnv 0x004c37d0
int Transfer4c37C37This::FUN_004c37d0(Transfer4c37C37Obj* apSource, int p1, unsigned char p2, int aiCount,
                                      Transfer4c37Form4* apExtra, unsigned char abCreateRef,
                                      Transfer4c37C37Form* apTarget, int p7, int p8, unsigned char p9,
                                      unsigned char abRecurse, Transfer4c37Entry* apEntry)
{
    AutoMemContext memoryContext72((MEM_CONTEXT)54, true, g_inventoryChangesSourceFilename, 3700);
    this->m10 = 1;
    this->m0c = this->m08;
    this->m08 = DAT_01012054;
    int resultRef6 = 0;
    if (this->m04 != 0)
        this->m04->Vcall48(0x20);
    if (apTarget != 0)
        apTarget->Vcall48(0x20);
    Transfer4c37Cont* container11 = (Transfer4c37Cont*)((FUN_004bffb0_shell*)this)->FUN_004bffb0();
    Transfer4c37Entry* itemChange7 = !apEntry ? this->FUN_004bfba0(p1, 1, 0) : apEntry;
    Transfer4c37NewObj* transferEntry7 = 0;
    bool updateWeapon9 = 0;
    Transfer4c37C37Obj* playerSource2 = 0;
    if (apSource->Vcall100() && apSource == (Transfer4c37C37Obj*)DAT_011dea3c)
        playerSource2 = apSource;
    if (playerSource2 != 0)
    {
        if (abCreateRef != 0 || apTarget != 0)
        {
            if (playerSource2->FUN_008d8520()->Vcall14c())
            {
                if (playerSource2->FUN_008d8520()->Vcall14c()->FUN_0044ddc0() == p1)
                    updateWeapon9 = 1;
            }
        }
    }
    if (abCreateRef != 0 || 0 != apTarget)
    {
        if (apExtra != 0)
        {
            if (apExtra->GetExtraData(0x4a))
            {
                if (aiCount == (int)apExtra->FUN_00418770())
                    apExtra->FUN_0042dec0();
            }
        }
    }
    if (apExtra != 0)
    {
        if (!apExtra->ItemsInList())
        {
            if (itemChange7 != 0 && itemChange7->m00 != 0)
                ((Transfer4c37FirstObj*)itemChange7->m00)->_ref_00905330(&apExtra);
            delete apExtra;
            apExtra = 0;
        }
    }
    long baseCount48 = 0;
    if (apSource != 0)
    {
        baseCount48 = container11 ? container11->FUN_00482a90(p1) : 0;
        if (itemChange7 != 0)
        {
            if (!itemChange7->FUN_004bddd0(0))
            {
                if (baseCount48 + itemChange7->m04 > itemChange7->FUN_004bc980() + itemChange7->FUN_004bc8f0(0))
                {
                    if (itemChange7->FUN_004bde40() != 0)
                        baseCount48 = 0;
                }
            }
        }
    }
    int negativeBaseCount13 = 0;
    if (baseCount48 < 0)
    {
        negativeBaseCount13 = baseCount48;
        baseCount48 = -1 * baseCount48;
    }
    (void)negativeBaseCount13;
    if (baseCount48 < 0)
    {
        if (apTarget != (Transfer4c37C37Form*)DAT_011dea3c)
            return 0;
    }
    if ((itemChange7 != 0 && itemChange7->m04 != 0 && itemChange7->m04 + baseCount48 == 0) ||
        (itemChange7 == 0 && baseCount48 == 0))
        return resultRef6;
    int leveledItem0 = 0;
    bool hasRemainder15 = 0;
    long unusedChange80 = 0;
    (void)leveledItem0;
    (void)hasRemainder15;
    (void)unusedChange80;
    while (itemChange7 != 0 && aiCount > 0 && itemChange7->FUN_00726070() + baseCount48 > 0)
    {
        if (transferEntry7 != 0)
        {
            delete transferEntry7;
        }
        transferEntry7 = new Transfer4c37NewObj;
        transferEntry7->m08 = itemChange7->FUN_0044ddc0();
        void* extraNode6 = itemChange7->m00;
        bool searchExtra78 = 1;

        if (((apExtra != 0 && apExtra->ItemsInList()) || abRecurse != 0) && extraNode6 != 0 &&
            *((Transfer4c37EntryFirst*)extraNode6)->_ref_006815c0() != 0)
        {
            while (extraNode6 != 0 && *((Transfer4c37EntryFirst*)extraNode6)->_ref_006815c0() != 0 && searchExtra78)
            {
                Transfer4c37ItemObj* sourceExtra3 = *((Transfer4c37EntryFirst*)extraNode6)->_ref_006815c0();
                Transfer4c37Obj20* transferExtra18 = 0;
                (void)transferExtra18;
                if (apExtra != (Transfer4c37Form4*)sourceExtra3 &&
                    !(apExtra == 0 && abRecurse != 0 && sourceExtra3->FUN_00418660()))
                {
                    extraNode6 = (void*)((Transfer4c37EntryFirst*)extraNode6)->FUN_00726070();
                    goto block4c2d;
                }
                apExtra = 0;
                searchExtra78 = 0;
                int stackCount10 = (int)sourceExtra3->FUN_00418770();

                if (sourceExtra3->FUN_00418ab0(0) && (int)sourceExtra3->FUN_00418770() <= aiCount)
                {
                    bool onlyWorn39;
                    bool didUnequip10;
                    onlyWorn39 = 0;
                    if ((unsigned int)sourceExtra3->ItemsInList() <= 1 ||
                        (sourceExtra3->ItemsInList() == 2 && (int)sourceExtra3->FUN_00418770() > 1) ||
                        (sourceExtra3->FUN_00418750() && sourceExtra3->ItemsInList() == 2))
                        onlyWorn39 = 1;
                    didUnequip10 = 0;
                    if (apSource->Vcall100())
                    {
                        if (!apSource->FUN_00440da0())
                        {
                            Transfer4c37C37Obj* saved58 = apSource;
                            if (saved58->FUN_008d8520() != 0)
                            {
                                didUnequip10 =
                                    saved58->FUN_0088d7d0(itemChange7->FUN_0044ddc0(),
                                                          (int)sourceExtra3->FUN_00418770(), sourceExtra3, 0, 0, 1);
                            }
                            goto flag52_done;
                        }
                    }
                    didUnequip10 = apSource->Vcall188(itemChange7->FUN_0044ddc0(), (int)sourceExtra3->FUN_00418770(),
                                                      sourceExtra3);
                flag52_done:
                    if (!didUnequip10 || onlyWorn39)
                        sourceExtra3 = 0;
                    itemChange7 = this->FUN_004bfba0(p1, 1, 0);
                    if (itemChange7 == 0 || !itemChange7->FUN_004bddd0(0))
                    {
                        resultRef6 = this->FUN_004c37d0(apSource, p1, p2, aiCount, (Transfer4c37Form4*)sourceExtra3,
                                                        abCreateRef, apTarget, p7, p8, 1, 0, 0);
                    }
                    if (itemChange7 != 0)
                    {
                        if (1 < stackCount10)
                        {
                            if (stackCount10 - aiCount > 0)
                            {
                                if (this->m04->Vcall100())
                                {
                                    this->m04->FUN_0088c830(itemChange7->FUN_0044ddc0(), stackCount10 - aiCount,
                                                            sourceExtra3, 1, 0, 0);
                                }
                            }
                        }
                    }
                    {
                        delete transferEntry7;
                    }
                    transferEntry7 = 0;
                    return resultRef6;
                }

                else
                {
                    if (stackCount10 > aiCount || sourceExtra3->GetExtraLeveledItem() != 0)
                    {
                        int flag_ed;
                        leveledItem0 = (int)sourceExtra3->GetExtraLeveledItem();
                        flag_ed = FUN_00401170(itemChange7->FUN_0044ddc0());
                        if (sourceExtra3->GetExtraLeveledItem() != 0 && sourceExtra3->FUN_00418800() != 0 &&
                            flag_ed != 0x18 && flag_ed != 0x1a)
                        {
                            if (flag_ed == 0x73 || flag_ed == 0x18 || flag_ed == 0x1a)
                                sourceExtra3->FUN_00419ad0(1);
                            transferExtra18 = (Transfer4c37Obj20*)sourceExtra3;
                            ((Transfer4c37EntryHeadS*)itemChange7->m00)->_ref_00905330(&sourceExtra3);
                            Transfer4c37Obj20* a60 = new Transfer4c37Obj20;
                            a60->SetLeveledItemIndex(sourceExtra3->GetExtraLeveledItem()->m0c);
                            ((Transfer4c37EntryHeadS*)itemChange7->m00)->FUN_005ae3d0(&a60);
                            transferExtra18->FUN_0041d000();
                            itemChange7->m04 = -1 * (int)sourceExtra3->FUN_00418770();
                        }
                        else
                        {
                            if (sourceExtra3->FUN_00418750())
                            {
                                if (aiCount == stackCount10)
                                {
                                    itemChange7->m04 -= stackCount10;
                                    sourceExtra3->FUN_00419ad0(-1 * stackCount10);
                                }
                                else
                                {
                                    itemChange7->m04 -= aiCount;
                                    sourceExtra3->FUN_00419ad0(stackCount10 - aiCount);
                                }
                            }
                            else
                            {
                                itemChange7->m04 -= aiCount;
                                sourceExtra3->FUN_00419ad0(stackCount10 - aiCount);
                            }
                            {
                                transferExtra18 = new Transfer4c37Obj20;
                            }
                            transferExtra18->CopyListForReference(sourceExtra3, 0);
                            transferExtra18->FUN_0041d000();
                            transferExtra18->FUN_00419ad0((unsigned short)aiCount);
                            if ((transferExtra18->ItemsInList() == 1 && (int)transferExtra18->FUN_00418770() > 1) ||
                                transferExtra18->ItemsInList() == 0)
                            {
                                delete transferExtra18;
                                transferExtra18 = 0;
                            }
                        }
                        FUN_005ac750(apSource, transferExtra18, 4);
                        stackCount10 = aiCount;
                        aiCount = aiCount - aiCount;
                    }
                    else
                    {

                        itemChange7->m04 -= stackCount10;
                        transferEntry7->FUN_006ecd40(transferEntry7->_ref_00726070() + stackCount10);
                        transferExtra18 = (Transfer4c37Obj20*)sourceExtra3;
                        aiCount = aiCount - stackCount10;
                        ((Transfer4c37EntryHeadS*)itemChange7->m00)->_ref_00905330(&sourceExtra3);

                        if (0 != sourceExtra3)
                        {
                            if ((int)sourceExtra3->GetExtraByteValue() >= 0)
                            {
                                if (itemChange7->FUN_00726070() > 0)
                                {
                                    this->SetInventorySlotExtraData(
                                        itemChange7,
                                        itemChange7->m00 ? *((Transfer4c37EntryFirst*)itemChange7->m00)->_ref_006815c0()
                                                         : 0,
                                        (int)sourceExtra3->GetExtraByteValue());
                                }
                            }
                        }
                        sourceExtra3 = 0;
                        FUN_005ac750(apSource, (void*)transferExtra18, 4);
                        if (((Transfer4c37ItemObj*)transferExtra18)->FUN_004bca60())
                        {
                            delete (Transfer4c37ItemObj*)transferExtra18;
                            transferExtra18 = 0;
                        }
                        if (itemChange7->m04 == 0)
                            unusedChange80 = (int)itemChange7;
                    }
                }
            block4323:
                if (transferExtra18 != 0)
                {
                    if (((Transfer4c37ItemObj*)transferExtra18)->FUN_00418ab0(0))
                    {
                        ((Transfer4c37ItemObj*)transferExtra18)->FUN_0041b010(0);
                        if (((Transfer4c37ItemObj*)transferExtra18)->FUN_004bca60())
                        {
                            delete (Transfer4c37ItemObj*)transferExtra18;
                            transferExtra18 = 0;
                        }
                    }
                }
                if (transferExtra18 != 0)
                {
                    if (((Transfer4c37ItemObj*)transferExtra18)->ItemsInList())
                    {
                        if (!transferEntry7->FUN_00559450())
                        {
                            transferEntry7->m00 = new Transfer4c37Obj96;
                        }
                        ((Transfer4c37CurHead*)transferEntry7->m00)->FUN_005ae3d0(&transferExtra18);
                    }
                }
                goto block441f;
            block441f:

                if (abCreateRef != 0)
                {
                    if (transferExtra18 == 0 || ((Transfer4c37ItemObj*)transferExtra18)->FUN_0041c8d0() == 0)
                    {
                        resultRef6 = (int)this->PlaceObject(apSource, itemChange7->m08, stackCount10, 0, p7, p8);
                        ((Transfer4c37ResObj*)resultRef6)->Vcall48(0x400);
                        if (transferExtra18 != 0)
                        {
                            if (((Transfer4c37ItemObj*)transferExtra18)->ItemsInList())
                            {
                                bool flag69 = 1;
                                if (sourceExtra3 != 0)
                                    flag69 = 0;
                                (void)flag69;
                                ((Transfer4c37ResObj*)resultRef6)
                                    ->FUN_00567490(((Transfer4c37ItemObj*)transferExtra18)->FUN_00418860());
                                ((Transfer4c37ResObj*)resultRef6)
                                    ->FUN_005d43c0()
                                    ->CopyListForReference((void*)transferExtra18, 1);
                                ((Transfer4c37ResObj*)resultRef6)->FUN_005d43c0()->RemoveExtraData30();
                            }
                        }
                        bool copyModel0 = 0;
                        Transfer4c37M68Obj* sourceCell30 = (Transfer4c37M68Obj*)apSource->FUN_008d6f30();
                        if (!((Transfer4c37ResObj*)resultRef6)->FUN_00567770())
                        {
                            if (sourceCell30 != 0)
                            {
                                if (sourceCell30->FUN_00546a40())
                                {
                                    if (!sourceCell30->FUN_00546ca0(apSource))
                                        copyModel0 = 1;
                                }
                            }
                        }
                        if (!copyModel0)
                        {
                            if (FUN_00401170((int)apSource->FUN_007af430()) == 0x2a)
                            {
                                if (((Transfer4c37AuxObj*)apSource->FUN_007af430())->FUN_005f0cc0() == 1)
                                {
                                    Transfer4c37T70Obj* t70 = (Transfer4c37T70Obj*)dynamic_cast<TESBipedModelForm*>(
                                        (TESBoundObject*)((Transfer4c37ResObj*)resultRef6)->FUN_007af430());
                                    if (t70 != 0)
                                    {
                                        if (t70->GetWorldModel(1) != t70->GetWorldModel(0))
                                            copyModel0 = 1;
                                    }
                                }
                            }
                        }
                        if (copyModel0)
                            ((Transfer4c37ResObj*)resultRef6)->FUN_00567ad0(apSource->FUN_007af430());
                        {
                            delete transferEntry7;
                            transferEntry7 = 0;
                        }
                        {
                            delete (Transfer4c37ItemObj*)transferExtra18;
                            transferExtra18 = 0;
                        }
                    }
                    else
                    {

                        if (transferExtra18 != 0)
                        {
                            resultRef6 = ((Transfer4c37ItemObj*)transferExtra18)->FUN_0041c8d0();
                        }
                        else if (sourceExtra3 != 0)
                        {
                            resultRef6 = sourceExtra3->FUN_0041c8d0();
                        }
                        if (resultRef6 != 0)
                        {
                            ((Transfer4c37ResObj*)resultRef6)->VcallC4(0);
                            ((Transfer4c37ItemObj*)transferExtra18)->FUN_0041c900();
                            bool copyExtra1 = 1;
                            if (sourceExtra3 != 0)
                                copyExtra1 = 0;
                            ((Transfer4c37ResObj*)resultRef6)
                                ->FUN_00567490(((Transfer4c37ItemObj*)transferExtra18)->FUN_00418860());
                            ((Transfer4c37ResObj*)resultRef6)
                                ->FUN_005d43c0()
                                ->CopyListForReference((void*)transferExtra18, (int)copyExtra1);
                            ((Transfer4c37ResObj*)resultRef6)->FUN_005d43c0()->RemoveExtraData30();
                            ((Transfer4c37ResObj*)resultRef6)->FUN_005d43c0()->FUN_0041c900();
                            if (((Transfer4c37ResObj*)resultRef6)->FUN_005d43c0()->FUN_0041b320() == 0)
                            {
                                ((Transfer4c37ResObj*)resultRef6)->FUN_005d43c0()->FUN_0041b2a0((void*)resultRef6);
                                ((Transfer4c37ResObj*)resultRef6)->Vcall48(0x400);
                            }
                            (void)this->PlaceObject(apSource, itemChange7->m08, stackCount10, resultRef6, p7, p8);
                            {
                                delete transferEntry7;
                                transferEntry7 = 0;
                            }
                            {
                                delete (Transfer4c37ItemObj*)transferExtra18;
                                transferExtra18 = 0;
                            }
                            bool copyReferenceModel20 = 0;
                            Transfer4c37M68Obj* referenceCell8 = (Transfer4c37M68Obj*)apSource->FUN_008d6f30();
                            if (!((Transfer4c37ResObj*)resultRef6)->FUN_00567770())
                            {
                                if (referenceCell8 != 0)
                                {
                                    if (referenceCell8->FUN_00546a40())
                                    {
                                        if (!referenceCell8->FUN_00546ca0(apSource))
                                            copyReferenceModel20 = 1;
                                    }
                                }
                            }
                            if (!copyReferenceModel20)
                            {
                                if (FUN_00401170((int)apSource->FUN_007af430()) == 0x2a)
                                {
                                    if (((Transfer4c37AuxObj*)apSource->FUN_007af430())->FUN_005f0cc0() == 1)
                                    {
                                        Transfer4c37T70Obj* t70b =
                                            (Transfer4c37T70Obj*)dynamic_cast<TESBipedModelForm*>(
                                                (TESBoundObject*)((Transfer4c37ResObj*)resultRef6)->FUN_007af430());
                                        if (t70b != 0)
                                        {
                                            if (t70b->GetWorldModel(1) != t70b->GetWorldModel(0))
                                                copyReferenceModel20 = 1;
                                        }
                                    }
                                }
                            }
                            if (copyReferenceModel20)
                                ((Transfer4c37ResObj*)resultRef6)->FUN_00567ad0(apSource->FUN_007af430());
                        }
                    }
                }
                else
                {
                    if (apTarget != 0)
                    {
                        Transfer4c37Obj20* raw1ec = 0;
                        if (transferEntry7->m00 != 0)
                        {
                            Transfer4c37Node84* node84 = (Transfer4c37Node84*)transferEntry7->m00;
                            while (node84 != 0 && *node84->FUN_006815c0() != 0)
                            {
                                int item88 = 0;
                                raw1ec = (Transfer4c37Obj20*)*node84->FUN_006815c0();
                                if (!raw1ec->FUN_00418660())
                                {
                                    if (apSource->Vcall100())
                                    {
                                        int item8c = 0;
                                        item8c = (int)apSource->FUN_005d43c0()->FUN_004216f0();
                                        if (item8c == 0)
                                            item8c = (int)apSource->FUN_007af430();
                                        item88 = item8c;
                                    }
                                    else
                                    {
                                        item88 = apSource->FUN_00567790();
                                    }
                                    if ((unsigned char)p2 != 0)
                                    {
                                        if (!FUN_00481f10(transferEntry7->FUN_0044ddc0()))
                                            raw1ec->FUN_00419700((void*)item88);
                                    }
                                }
                                apTarget->Vcall190(transferEntry7->FUN_0044ddc0(), raw1ec, stackCount10);
                                node84 = node84->FUN_00726070();
                            }
                            {
                                delete transferEntry7;
                                transferEntry7 = 0;
                            }
                        }
                        else
                        {
                            {
                                long item90 = 0;
                                if (apSource->Vcall100())
                                {
                                    int item94 = 0;
                                    item94 = (int)apSource->FUN_005d43c0()->FUN_004216f0();
                                    if (item94 == 0)
                                        item94 = (int)apSource->FUN_007af430();
                                    item90 = item94;
                                }
                                else
                                {
                                    item90 = apSource->FUN_00567790();
                                }
                                if ((unsigned char)p2 != 0)
                                {
                                    if (!FUN_00481f10(transferEntry7->FUN_0044ddc0()))
                                    {
                                        raw1ec = new Transfer4c37Obj20;
                                        raw1ec->FUN_00419700((void*)item90);
                                        raw1ec->FUN_00419ad0((unsigned short)aiCount);
                                    }
                                }
                                apTarget->Vcall190(transferEntry7->FUN_0044ddc0(), raw1ec, stackCount10);
                            }
                            {
                                delete transferEntry7;
                                transferEntry7 = 0;
                            }
                        }
                        searchExtra78 = 0;
                    }
                    else
                    {
                        if (!FUN_00705020() && !FUN_00705000() && !FUN_00702680(0x40b, 0) && !FUN_00702680(0x422, 0))
                            transferEntry7->ClearExtraDataList();
                        {
                            delete transferEntry7;
                            transferEntry7 = 0;
                        }
                    }
                }
            block4c2d:

                if (aiCount > 0)
                {
                    if (abRecurse != 0)
                    {
                        return this->FUN_004c37d0(apSource, p1, p2, aiCount, 0, abCreateRef, apTarget, p7, p8, 1, 0, 0);
                    }
                }
                if (aiCount > 0 && resultRef6 != 0)
                {
                    return resultRef6;
                }
                else if (aiCount > 0 && extraNode6 == 0)
                {
                    apExtra = 0;
                    break;
                }
            }
        }
        else
        {
            int transferCount2 = 0;
            if (baseCount48 < 0)
            {
                transferCount2 = -1 * baseCount48 + itemChange7->m04;
            }
            else
            {
                transferCount2 = baseCount48 + itemChange7->m04;
            }
            if (transferCount2 < 0)
            {
                if (baseCount48 >= 0)
                    return resultRef6;
            }
            int wornCount11;
            wornCount11 = 0;
            if (itemChange7->m00 != 0)
            {
                wornCount11 = itemChange7->FUN_004bc8f0(0) + (itemChange7->FUN_004bddd0(0) ? 1 : 0);
            }
            int plainCount1 = 0;
            plainCount1 = transferCount2 - wornCount11;
            if (plainCount1 < 0)
                plainCount1 = 0;
            Transfer4c37ItemObj* sourceList32 = 0;
            int destinationList14 = 0;
            Transfer4c37Node84* remainingNode23 = (Transfer4c37Node84*)itemChange7->m00;
            if (plainCount1 > 0)
            {
                if (itemChange7->FUN_004bddd0(0))
                {
                    Transfer4c37ItemObj* cont = 0;
                    long cnt_b4 = 0;
                    Transfer4c37Node84* node_b0;
                    node_b0 = (Transfer4c37Node84*)itemChange7->m00;
                    while (node_b0 != 0 && *node_b0->FUN_006815c0() != 0)
                    {
                        cont = *node_b0->FUN_006815c0();
                        short sh_bc = cont->FUN_00418770();
                        if (cont->FUN_00418ab0(0))
                        {
                            if ((int)sh_bc > 1)
                                cont->FUN_00419ad0((int)sh_bc - aiCount);
                        }
                        (void)cnt_b4;
                        node_b0 = node_b0->FUN_00726070();
                    }
                }
                else if (itemChange7->FUN_004bcb70())
                {
                    Transfer4c37ItemObj* hotkeyExtra37 = 0;
                    int hotkeyCount26 = 0;
                    Transfer4c37Node84* hotkeyNode5 = (Transfer4c37Node84*)itemChange7->m00;
                    while (hotkeyNode5 != 0 && *hotkeyNode5->FUN_006815c0() != 0)
                    {
                        hotkeyExtra37 = *hotkeyNode5->FUN_006815c0();
                        short sh_cc = hotkeyExtra37->FUN_00418770();
                        if (hotkeyExtra37->FUN_00418750())
                        {
                            if ((int)sh_cc > 1)
                                hotkeyExtra37->FUN_00419ad0((int)sh_cc - aiCount);
                        }
                        (void)hotkeyCount26;
                        hotkeyNode5 = hotkeyNode5->FUN_00726070();
                    }
                }
                if (plainCount1 >= aiCount)
                {
                    if (negativeBaseCount13 == 0)
                    {
                        itemChange7->m04 = itemChange7->m04 - aiCount;
                    }
                    transferCount2 = aiCount;
                    aiCount = 0;
                }
                else
                {
                    if (container11 != 0)
                    {
                        if (container11->FUN_00482a90(p1) > 0)
                        {
                            itemChange7->m04 -= plainCount1;
                        }
                    }
                    transferCount2 = plainCount1;
                    aiCount = aiCount - plainCount1;
                    if (itemChange7->m04 + baseCount48 < 0)
                    {
                        if (baseCount48 != 0)
                        {
                            itemChange7->m04 = -1 * baseCount48;
                        }
                        else
                        {
                            itemChange7->m04 = 0;
                        }
                    }
                    else
                    {
                        itemChange7->m04 -= transferCount2;
                    }
                }
                if (abCreateRef != 0)
                {
                    resultRef6 = (int)this->PlaceObject(apSource, p1, transferCount2, 0, p7, p8);
                    {
                        Transfer4c37M68Obj* plainCell18 = (Transfer4c37M68Obj*)apSource->FUN_008d6f30();
                        bool copyPlainModel42 = 0;
                        if (!((Transfer4c37ResObj*)resultRef6)->FUN_00567770())
                        {
                            if (plainCell18 != 0)
                            {
                                if (plainCell18->FUN_00546a40())
                                {
                                    if (!plainCell18->FUN_00546ca0(apSource))
                                        copyPlainModel42 = 1;
                                }
                            }
                        }
                        if (!copyPlainModel42)
                        {
                            if (FUN_00401170((int)apSource->FUN_007af430()) == 0x2a)
                            {
                                if (((Transfer4c37AuxObj*)apSource->FUN_007af430())->FUN_005f0cc0() == 1)
                                {
                                    Transfer4c37T70Obj* loopTail =
                                        (Transfer4c37T70Obj*)dynamic_cast<TESBipedModelForm*>(
                                            (TESBoundObject*)((Transfer4c37ResObj*)resultRef6)->FUN_007af430());
                                    if (loopTail != 0)
                                    {
                                        if (loopTail->GetWorldModel(1) != loopTail->GetWorldModel(0))
                                            copyPlainModel42 = 1;
                                    }
                                }
                            }
                        }
                        if (copyPlainModel42)
                            ((Transfer4c37ResObj*)resultRef6)->FUN_00567ad0(apSource->FUN_007af430());
                    }
                    {
                        delete transferEntry7;
                        transferEntry7 = 0;
                    }
                    if (destinationList14 != 0)
                    {
                        delete (Transfer4c37ItemObj*)destinationList14;
                    }
                    destinationList14 = 0;
                }
                else if (apTarget != 0)
                {
                    void* dc_dc = 0;
                    if (apSource->Vcall100())
                    {
                        void* dc_e0 = 0;
                        dc_e0 = (void*)apSource->FUN_005d43c0()->FUN_004216f0();
                        if (dc_e0 == 0)
                            dc_e0 = apSource->FUN_007af430();
                        dc_dc = dc_e0;
                    }
                    else
                    {
                        dc_dc = (void*)apSource->FUN_00567790();
                    }
                    if (p2 != 0 && !FUN_00481f10(p1) &&
                        (FUN_00401170(p1) != 0x29 || apTarget != (Transfer4c37C37Form*)DAT_011dea3c))
                    {
                        if (apExtra == 0)
                        {
                            apExtra = (Transfer4c37Form4*)new Transfer4c37Obj20;
                        }
                        ((Transfer4c37Obj20*)apExtra)->FUN_00419700(dc_dc);
                        ((Transfer4c37Obj20*)apExtra)->FUN_00419ad0((unsigned short)transferCount2);
                    }
                    if (apExtra != 0)
                    {
                        if (apTarget == (Transfer4c37C37Form*)DAT_011dea3c)
                        {
                            if (FUN_00401170(p1) == 0x29)
                                ((Transfer4c37Obj20*)apExtra)->FUN_0041aed0();
                        }
                    }
                    apTarget->Vcall190(p1, apExtra, transferCount2);
                    {
                        delete transferEntry7;
                        transferEntry7 = 0;
                    }
                }
                {
                    delete transferEntry7;
                    transferEntry7 = 0;
                }
            }

            if (aiCount > 0 && itemChange7 != 0 && itemChange7->m00 != 0 &&
                !((Transfer4c37M00Obj*)itemChange7->m00)->FUN_008256d0())
            {
                remainingNode23 = (Transfer4c37Node84*)itemChange7->m00;
                while (remainingNode23 != 0 && *remainingNode23->FUN_006815c0() != 0 && aiCount > 0)
                {
                    bool validStack1 = 1;
                    sourceList32 = *remainingNode23->FUN_006815c0();
                    if (transferEntry7 != 0)
                    {
                        delete transferEntry7;
                    }
                    {
                        transferEntry7 = new Transfer4c37NewObj;
                    }
                    if (itemChange7 != 0)
                        transferEntry7->m08 = itemChange7->FUN_0044ddc0();
                    if ((int)sourceList32->FUN_00418770() < 0)
                    {
                        validStack1 = 0;
                        remainingNode23 = remainingNode23->FUN_00726070();
                    }
                    else if (sourceList32->FUN_00418ab0(0) && (int)sourceList32->FUN_00418770() <= 1)
                    {
                        bool onlyWornFlag14 = 0;
                        if ((unsigned int)sourceList32->ItemsInList() <= 1 ||
                            (sourceList32->ItemsInList() == 2 && (int)sourceList32->FUN_00418770() > 1))
                        {
                            apExtra = 0;
                            onlyWornFlag14 = 1;
                        }
                        (void)onlyWornFlag14;
                        bool unequipped41 = apSource->Vcall188(itemChange7->FUN_0044ddc0(),
                                                               (int)sourceList32->FUN_00418770(), sourceList32);
                        if (unequipped41)
                        {
                            resultRef6 = this->FUN_004c37d0(apSource, p1, p2, aiCount, apExtra, abCreateRef, apTarget,
                                                            p7, p8, 1, 0, 0);
                        }
                        else
                        {
                            DispatchMessageToSink(DAT_011d31f8.FUN_004c69f0(), 0,
                                                  "Interface\\Icons\\Message Icons\\glow_message_vaultboy_sad.dds", 0,
                                                  DAT_010162c0, 0);
                        }
                        {
                            delete transferEntry7;
                            transferEntry7 = 0;
                        }
                        return resultRef6;
                    }
                    else
                    {
                        transferCount2 = (int)sourceList32->FUN_00418770();
                        if (transferCount2 > aiCount || sourceList32->GetExtraLeveledItem() != 0)
                        {
                            leveledItem0 = (int)sourceList32->GetExtraLeveledItem();
                            if (leveledItem0)
                            {
                                if (aiCount == transferCount2 || aiCount > transferCount2)
                                {
                                    itemChange7->m04 += -1 * transferCount2;
                                    sourceList32->FUN_00419ad0(-1 * transferCount2);
                                }
                                else
                                {
                                    itemChange7->m04 += -1 * aiCount;
                                    sourceList32->FUN_00419ad0(transferCount2 - aiCount);
                                }
                            }
                            else
                            {
                                itemChange7->m04 -= aiCount;
                                sourceList32->FUN_00419ad0(transferCount2 - aiCount);
                            }
                            {
                                destinationList14 = (int)new Transfer4c37Obj20;
                            }
                            ((Transfer4c37Obj20*)destinationList14)->CopyListForReference(sourceList32, 0);
                            ((Transfer4c37Obj20*)destinationList14)->FUN_0041d000();
                            if (transferCount2 < aiCount)
                                ((Transfer4c37Obj20*)destinationList14)->FUN_00419ad0((unsigned short)transferCount2);
                            else
                                ((Transfer4c37Obj20*)destinationList14)->FUN_00419ad0((unsigned short)aiCount);
                            if (aiCount < transferCount2)
                                transferCount2 = aiCount;
                            aiCount = aiCount - transferCount2;
                            if (((Transfer4c37Obj20*)destinationList14)->FUN_004bca60())
                            {
                                delete (Transfer4c37Obj20*)destinationList14;
                                destinationList14 = 0;
                            }
                            else
                            {
                                if (!transferEntry7->FUN_00559450())
                                {
                                    transferEntry7->m00 = new Transfer4c37Obj96;
                                }
                                ((Transfer4c37CurHead*)transferEntry7->m00)->FUN_005ae3d0(&destinationList14);
                            }
                        }
                        else
                        {
                            itemChange7->m04 -= transferCount2;
                            transferEntry7->FUN_006ecd40(transferEntry7->_ref_00726070() + transferCount2);
                            destinationList14 = (int)sourceList32;
                            aiCount = aiCount - transferCount2;
                            ((Transfer4c37EntryHeadS*)itemChange7->m00)
                                ->_ref_00905330((Transfer4c37ItemObj**)&destinationList14);
                            sourceList32 = 0;
                            if (((Transfer4c37ItemObj*)destinationList14)->FUN_004bca60())
                            {
                                delete (Transfer4c37ItemObj*)destinationList14;
                                destinationList14 = 0;
                            }
                            else
                            {
                                if (!transferEntry7->FUN_00559450())
                                {
                                    transferEntry7->m00 = new Transfer4c37Obj96;
                                }
                                ((Transfer4c37CurHead*)transferEntry7->m00)->FUN_005ae3d0(&destinationList14);
                            }
                        }
                    }
                t70d:
                    if (itemChange7 != 0 && validStack1)
                    {
                        if (abCreateRef != 0)
                        {
                            if (destinationList14 == 0 ||
                                ((Transfer4c37ItemObj*)destinationList14)->FUN_0041c8d0() == 0)
                            {

                                resultRef6 =
                                    (int)this->PlaceObject(apSource, itemChange7->m08, transferCount2, 0, p7, p8);
                                {
                                    Transfer4c37M68Obj* stackCell3 = (Transfer4c37M68Obj*)apSource->FUN_008d6f30();
                                    bool copyStackModel11 = 0;
                                    if (!((Transfer4c37ResObj*)resultRef6)->FUN_00567770())
                                    {
                                        if (stackCell3 != 0)
                                        {
                                            if (stackCell3->FUN_00546a40())
                                            {
                                                if (!stackCell3->FUN_00546ca0(apSource))
                                                    copyStackModel11 = 1;
                                            }
                                        }
                                    }
                                    if (!copyStackModel11)
                                    {
                                        if (FUN_00401170((int)apSource->FUN_007af430()) == 0x2a)
                                        {
                                            if (((Transfer4c37AuxObj*)apSource->FUN_007af430())->FUN_005f0cc0() == 1)
                                            {
                                                Transfer4c37T70Obj* t70e =
                                                    (Transfer4c37T70Obj*)dynamic_cast<TESBipedModelForm*>(
                                                        (TESBoundObject*)((Transfer4c37ResObj*)resultRef6)
                                                            ->FUN_007af430());
                                                if (t70e != 0)
                                                {
                                                    if (t70e->GetWorldModel(1) != t70e->GetWorldModel(0))
                                                        copyStackModel11 = 1;
                                                }
                                            }
                                        }
                                    }
                                    if (copyStackModel11)
                                        ((Transfer4c37ResObj*)resultRef6)->FUN_00567ad0(apSource->FUN_007af430());
                                }
                                if (destinationList14 != 0)
                                {
                                    if (((Transfer4c37ItemObj*)destinationList14)->ItemsInList())
                                    {
                                        ((Transfer4c37ResObj*)resultRef6)
                                            ->FUN_00567490(((Transfer4c37ItemObj*)destinationList14)->FUN_00418860());
                                        ((Transfer4c37ResObj*)resultRef6)
                                            ->FUN_005d43c0()
                                            ->CopyListForReference((void*)destinationList14, 1);
                                        ((Transfer4c37ResObj*)resultRef6)->FUN_005d43c0()->RemoveExtraData30();
                                    }
                                }
                                {
                                    delete transferEntry7;
                                    transferEntry7 = 0;
                                }
                                {
                                    delete (Transfer4c37ItemObj*)destinationList14;
                                    destinationList14 = 0;
                                }
                            }
                            else
                            {

                                if (destinationList14 != 0)
                                {
                                    resultRef6 = ((Transfer4c37ItemObj*)destinationList14)->FUN_0041c8d0();
                                }
                                else if (sourceList32 != 0)
                                {
                                    resultRef6 = ((Transfer4c37ItemObj*)sourceList32)->FUN_0041c8d0();
                                }
                                if (resultRef6 != 0)
                                {
                                    ((Transfer4c37ResObj*)resultRef6)->VcallC4(0);
                                    ((Transfer4c37ItemObj*)destinationList14)->FUN_0041c900();
                                    {
                                        bool flag41 = 1;
                                        if (sourceList32 != 0)
                                            flag41 = 0;
                                        ((Transfer4c37ResObj*)resultRef6)
                                            ->FUN_00567490(((Transfer4c37ItemObj*)destinationList14)->FUN_00418860());
                                        ((Transfer4c37ResObj*)resultRef6)
                                            ->FUN_005d43c0()
                                            ->CopyListForReference((void*)destinationList14, (int)flag41);
                                    }
                                    ((Transfer4c37ResObj*)resultRef6)->FUN_005d43c0()->RemoveExtraData30();
                                    ((Transfer4c37ResObj*)resultRef6)->FUN_005d43c0()->FUN_0041c900();
                                    if (((Transfer4c37ResObj*)resultRef6)->FUN_005d43c0()->FUN_0041b320() == 0)
                                    {
                                        ((Transfer4c37ResObj*)resultRef6)
                                            ->FUN_005d43c0()
                                            ->FUN_0041b2a0((void*)resultRef6);
                                        ((Transfer4c37ResObj*)resultRef6)->Vcall48(0x400);
                                    }
                                    resultRef6 = (int)this->PlaceObject(apSource, itemChange7->m08, transferCount2,
                                                                        resultRef6, p7, p8);
                                    {
                                        delete transferEntry7;
                                        transferEntry7 = 0;
                                    }
                                    {
                                        delete (Transfer4c37ItemObj*)destinationList14;
                                        destinationList14 = 0;
                                    }
                                    {
                                        bool copyStackReferenceModel26 = 0;
                                        Transfer4c37M68Obj* stackReferenceCell32 =
                                            (Transfer4c37M68Obj*)apSource->FUN_008d6f30();
                                        if (!((Transfer4c37ResObj*)resultRef6)->FUN_00567770())
                                        {
                                            if (stackReferenceCell32 != 0)
                                            {
                                                if (stackReferenceCell32->FUN_00546a40())
                                                {
                                                    if (!stackReferenceCell32->FUN_00546ca0(apSource))
                                                        copyStackReferenceModel26 = 1;
                                                }
                                            }
                                        }
                                        if (!copyStackReferenceModel26)
                                        {
                                            if (FUN_00401170((int)apSource->FUN_007af430()) == 0x2a)
                                            {
                                                if (((Transfer4c37AuxObj*)apSource->FUN_007af430())->FUN_005f0cc0() ==
                                                    1)
                                                {
                                                    Transfer4c37T70Obj* t70f;
                                                    t70f = (Transfer4c37T70Obj*)dynamic_cast<TESBipedModelForm*>(
                                                        (TESBoundObject*)((Transfer4c37ResObj*)resultRef6)
                                                            ->FUN_007af430());
                                                    if (t70f != 0)
                                                    {
                                                        if (t70f->GetWorldModel(1) != t70f->GetWorldModel(0))
                                                            copyStackReferenceModel26 = 1;
                                                    }
                                                }
                                            }
                                        }
                                        if (copyStackReferenceModel26)
                                            ((Transfer4c37ResObj*)resultRef6)->FUN_00567ad0(apSource->FUN_007af430());
                                    }
                                }
                            }

                            {
                                delete transferEntry7;
                                transferEntry7 = 0;
                            }
                        }
                        else if (apTarget != 0)
                        {

                            Transfer4c37Obj20* item_fc = 0;
                            if (transferEntry7->m00 != 0)
                            {
                                item_fc =
                                    (Transfer4c37Obj20*)*((Transfer4c37Node84*)transferEntry7->m00)->FUN_006815c0();
                            }
                            else
                            {
                                item_fc = new Transfer4c37Obj20;
                                transferEntry7->m00 = new Transfer4c37Obj96;
                                ((Transfer4c37CurHead*)transferEntry7->m00)->FUN_005ae3d0((int*)&item_fc);
                            }
                            int item_100 = 0;
                            if (apSource->Vcall100())
                            {
                                int t104 = 0;
                                t104 = (int)apSource->FUN_005d43c0()->FUN_004216f0();
                                if (t104 == 0)
                                    t104 = (int)apSource->FUN_007af430();
                                item_100 = t104;
                            }
                            else
                            {
                                item_100 = apSource->FUN_00567790();
                            }
                            if (p2 != 0 && !FUN_00481f10(transferEntry7->FUN_0044ddc0()))
                            {
                                item_fc->FUN_00419700((void*)item_100);
                                item_fc->FUN_00419ad0((unsigned short)transferCount2);
                            }
                            else
                            {
                                item_fc->FUN_0041aed0();
                            }
                            apTarget->Vcall190(transferEntry7->FUN_0044ddc0(), item_fc, transferCount2);

                            {
                                delete transferEntry7;
                                transferEntry7 = 0;
                            }
                        }
                        else
                        {

                            if ((unsigned char)p9 != 0)
                                transferEntry7->ClearExtraDataList();
                            {
                                delete transferEntry7;
                                transferEntry7 = 0;
                            }
                        }

                        if (sourceList32 != 0)
                            remainingNode23 = remainingNode23->FUN_00726070();
                        if (aiCount != 0)
                            hasRemainder15 = 1;
                    }
                    else
                    {

                        {
                            delete transferEntry7;
                            transferEntry7 = 0;
                        }
                        {
                            delete (Transfer4c37ItemObj*)destinationList14;
                            destinationList14 = 0;
                        }
                    }
                }
            }
        }
    block62e7:
        itemChange7 = this->FUN_004bfba0(p1, 1, 0);
    }

    if ((unsigned char)abRecurse != 0 && aiCount > 0)
        return this->FUN_004c37d0(apSource, p1, p2, aiCount, apExtra, abCreateRef, apTarget, p7, p8, 1, 0, 0);
    if ((itemChange7 == 0 || hasRemainder15) && baseCount48 != 0)
    {
        if (itemChange7 != 0)
            baseCount48 += itemChange7->m04;
        if (!baseCount48)
        {
            ((Transfer4c37Tail470*)itemChange7->FUN_00559450())->FUN_00470470();
            return resultRef6;
        }
        if (abCreateRef != 0)
        {
            resultRef6 = (int)this->PlaceObject(apSource, p1, aiCount, 0, p7, p8);
            {
                Transfer4c37M68Obj* remainderCell3 = (Transfer4c37M68Obj*)apSource->FUN_008d6f30();
                bool copyRemainderModel32 = 0;
                if (!((Transfer4c37ResObj*)resultRef6)->FUN_00567770())
                {
                    if (remainderCell3 != 0)
                    {
                        if (remainderCell3->FUN_00546a40())
                        {
                            if (!remainderCell3->FUN_00546ca0(apSource))
                                copyRemainderModel32 = 1;
                        }
                    }
                }
                if (!copyRemainderModel32)
                {
                    if (FUN_00401170((int)apSource->FUN_007af430()) == 0x2a)
                    {
                        if (((Transfer4c37AuxObj*)apSource->FUN_007af430())->FUN_005f0cc0() == 1)
                        {
                            Transfer4c37T70Obj* t70_110 = (Transfer4c37T70Obj*)dynamic_cast<TESBipedModelForm*>(
                                (TESBoundObject*)((Transfer4c37ResObj*)resultRef6)->FUN_007af430());
                            if (t70_110 != 0)
                            {
                                if (t70_110->GetWorldModel(1) != t70_110->GetWorldModel(0))
                                    copyRemainderModel32 = 1;
                            }
                        }
                    }
                }
                if (copyRemainderModel32)
                    ((Transfer4c37ResObj*)resultRef6)->FUN_00567ad0(apSource->FUN_007af430());
            }
        }
        else if (apTarget != 0)
        {
            unsigned int item_114 = 0;
            if (apSource->Vcall100())
            {
                int a = 0;
                a = (int)apSource->FUN_005d43c0()->FUN_004216f0();
                if (!a)
                    a = (int)apSource->FUN_007af430();
                item_114 = a;
            }
            else
            {
                item_114 = apSource->FUN_00567790();
            }
            if ((unsigned char)0 != p2 && !FUN_00481f10(p1))
            {
                if (apExtra == 0)
                {
                    apExtra = (Transfer4c37Form4*)new Transfer4c37Obj20;
                }
                ((Transfer4c37Obj20*)apExtra)->FUN_00419700((void*)item_114);
                ((Transfer4c37Obj20*)apExtra)->FUN_00419ad0((unsigned short)aiCount);
            }
            else if (apExtra != 0)
            {
                ((Transfer4c37Obj20*)apExtra)->FUN_0041aed0();
            }
            if (0 < aiCount)
            {
                if (FUN_00401170(p1) == 0x31 && apTarget == (Transfer4c37C37Form*)DAT_011dea3c)
                {
                    bool flag_11d = 0;
                    if ((unsigned char)p2 != 0 && item_114 != 0)
                    {
                        if (FUN_00401170(item_114) == 8)
                        {
                            int pObj = item_114;
                            if (!((Transfer4c37D7Obj*)pObj)->FUN_0047d7c0())
                                flag_11d = 1;
                        }
                        else
                        {
                            int tmp_128 = item_114;
                            if (tmp_128 != 0)
                            {
                                int res_12c = FUN_0047e040(((Transfer4c37ActorValueView*)tmp_128)->values.Vcall3(0x17));
                                if (res_12c != 2 && res_12c != 4)
                                    flag_11d = 1;
                            }
                        }
                    }
                    if (flag_11d)
                    {
                        ((Transfer4c37C37Obj*)DAT_011dea3c)->FUN_0094fd30((int)*DAT_011cde20.FUN_00403e20());
                    }
                    int weapon = p1;
                    ((Transfer4c37C37Obj*)DAT_011dea3c)->FUN_00966a70(weapon, 1);
                }
                else
                {
                    apTarget->Vcall190(p1, apExtra, aiCount);
                }
            }
        }
        {
            delete transferEntry7;
            transferEntry7 = 0;
        }
        if (itemChange7 == 0)
        {
            itemChange7 = (Transfer4c37Entry*)new Transfer4c37EntryNew(p1, -1 * aiCount);
            ((Transfer4c37ThisHead*)this->m00)->FUN_00905820(&itemChange7);
        }
        else
        {
            itemChange7->m04 -= aiCount;
        }
    }
    itemChange7 = this->FUN_004bfba0(p1, 1, 0);
    if (itemChange7 != 0 && (leveledItem0 == 0 || apSource->Vcall100()) &&
        ((itemChange7->m04 == 0 && baseCount48 == 0) ||
         (itemChange7->m00 != 0 && ((Transfer4c37M00Obj*)itemChange7->m00)->FUN_008256d0() && itemChange7->m04 == 0)))
    {
        if (!FUN_00705020() && !FUN_00705000() && !FUN_00702680(0x40b, 0) && !FUN_00702680(0x40b, 0))
            itemChange7->ClearExtraDataList();
        ((Transfer4c37ThisHead*)this->m00)->_ref_00905330(&itemChange7);
        {
            delete itemChange7;
        }
    }
    else
    {

        if (itemChange7 != 0)
        {
            if (itemChange7->FUN_00726070() + baseCount48 < 0)
            {
                if (!itemChange7->FUN_004bddd0(0))
                {
                    if (itemChange7->FUN_00559450() != 0)
                    {
                        if (leveledItem0 == 0)
                            ((Transfer4c37Tail470*)itemChange7->FUN_00559450())->FUN_00470470();
                    }
                }
            }
        }
    }
    if (updateWeapon9)
    {
        if (playerSource2->FUN_008a1710() != 0)
            playerSource2->Vcall3ec(playerSource2->FUN_008a1710(), 0, 0, 0);
    }
    return resultRef6;
}

struct FUN_008c71b0
{
    unsigned int value;
    FUN_008c71b0(unsigned int v);
    FUN_008c71b0(const FUN_008c71b0& other);
};

struct LoadBuffer4160
{
    virtual void Slot0();
    virtual int GetVersion();
    void FUN_00428110(unsigned int* out);
    void FUN_0042ce30(unsigned int* out);
    void FUN_007037c0(int version);
    void SetValue(FUN_008c71b0 flags);
    void SetValue(unsigned int flags);
    void FUN_0086cf00(FUN_008c71b0 flags);
    void FUN_0086cf00(unsigned int flags);
    unsigned int FUN_00864a60();
};

struct Item4160 : FUN_0076b630
{
    void FUN_004bee00(LoadBuffer4160* buffer);
    void ClearExtraDataList();
};

struct ChangeList4160
{
    void FUN_005ae3d0(FUN_004459e0** item);
};

struct Inventory4160
{
    ChangeList4160* changes;
    void FUN_004d4160(LoadBuffer4160* buffer);
};

// @fnv 0x004d4160
void Inventory4160::FUN_004d4160(LoadBuffer4160* buffer)
{
    int tag = buffer->GetVersion();
    unsigned int oldFlags;
    buffer->FUN_00428110(&oldFlags);
    unsigned int savedMode;
    buffer->FUN_0042ce30(&savedMode);
    buffer->FUN_007037c0(0);
    buffer->SetValue(FUN_008c71b0(0x400));
    buffer->FUN_0086cf00(FUN_008c71b0(0));
    unsigned int itemCount = buffer->FUN_00864a60();
    for (unsigned int i = 0; i < itemCount; i++)
    {
        FUN_004459e0* item = new FUN_0076b630;
        static_cast<Item4160*>(item)->FUN_004bee00(buffer);
        if (!static_cast<Item4160*>(item)->FUN_0044ddc0())
        {
            static_cast<Item4160*>(item)->ClearExtraDataList();
            delete item;
            item = 0;
        }
        changes->FUN_005ae3d0(&item);
    }
    buffer->FUN_007037c0(tag);
    buffer->SetValue(oldFlags);
    buffer->FUN_0086cf00(savedMode);
}

extern const char g_inventoryChangesSourceFilename[];

struct FUN_0076b630_ex : public FUN_0076b630
{
    void SetExtraListFlag(int, int, int);
};

struct MoveFormInfo_ex : public MoveFormInfo
{
    bool FUN_00480af0(int, int, void*);
};

void* __cdecl FUN_00475020(Weapon*);

// Scans the changes list for an entry with an extra matching the given slot, optionally requiring armor, and returns a new entry holding that item and extra.
// @fnv 0x004c8c10
FUN_0076b630* Target::FUN_004c8c10(int slot, int bOnlyArmor)
{
    AutoMemContext memContext2((MEM_CONTEXT)54, true, g_inventoryChangesSourceFilename, 5978);
    ItemList* node7 = this->changes;
    FUN_0076b630* result5 = 0;

    while (node7 && node7->FUN_006815c0())
    {
        FUN_0076b630_ex* entry7 = (FUN_0076b630_ex*)node7->FUN_006815c0();
        if (entry7)
        {
            FUN_0096a2d0* extraNode = entry7->extras;
            XExtra* foundExtra6 = 0;
            bool equipped2 = false;

            if (entry7->FUN_004bcb70() && entry7->count < 0)
            {
                entry7->SetExtraListFlag(0, 0, 1);
            }

            while (extraNode && extraNode->FUN_006815c0() && !equipped2)
            {
                foundExtra6 = (XExtra*)extraNode->FUN_006815c0();
                if (foundExtra6->FUN_00418ab0(0))
                {
                    switch (slot)
                    {
                    case 5:
                        if (entry7->FUN_0044ddc0()->FUN_00401170() == 0x28)
                        {
                            equipped2 = true;
                        }
                        break;
                    default: {
                        MoveFormInfo_ex* biped6 =
                            (MoveFormInfo_ex*)FUN_00480db0((TESBoundObject*)entry7->FUN_0044ddc0());
                        switch (slot)
                        {
                        case 0:
                        case 1:
                        case 10: {
                            void* armor = FUN_00475020(entry7->FUN_0044ddc0());
                            if (biped6 && biped6->FUN_00480af0(slot, 0, armor))
                            {
                                equipped2 = true;
                            }
                            break;
                        }
                        default: {
                            if (biped6 && biped6->FUN_00480af0(slot, 0, 0))
                            {
                                equipped2 = true;
                            }
                            break;
                        }
                        }
                        break;
                    }
                    }
                }
                extraNode = extraNode->FUN_00726070();
            }

            if (equipped2)
            {
                if (*(bool*)&bOnlyArmor && entry7->FUN_0044ddc0()->FUN_00401170() != 0x18)
                {
                    return result5;
                }

                result5 = new FUN_0076b630();
                result5->weapon = entry7->FUN_0044ddc0();
                if (!result5->extras)
                {
                    result5->extras = new FUN_0096a2d0();
                }
                result5->extras->FUN_005ae3d0((Extra**)&foundExtra6);
                result5->FUN_006ecd40(foundExtra6->FUN_00418770());
                equipped2 = false;
                return result5;
            }
        }

        node7 = node7->FUN_00726070();
    }

    return result5;
}

extern const char DAT_01020778[];

class VSubC5
{
  public:
    virtual void v0();
    virtual bool v4();
};

class IngredientItem : public TESBoundObject
{
  public:
    char padC5[0x38];
    VSubC5 sub;
};

class AlchemyItem : public TESBoundObject
{
  public:
    char padC5[0x38];
    VSubC5 sub;
};

struct E4C5
{
    int count;
    TESBoundObject* p4;
    TESBoundObject* p8;
    int FUN_00726070();
};

struct ENodeC5
{
    E4C5** FUN_006815c0();
    bool FUN_008256d0();
    ENodeC5* FUN_00726070();
};

struct MemHelperC5
{
    void* m_p;
    MemHelperC5(int, bool, const char*, int);
    ~MemHelperC5();
};

struct CItemC5
{
    TESBoundObject* p0;
    int i4;
    int i8;
    CItemC5(TESBoundObject*, int);
    int FUN_00726070();
};

struct CContainerC5
{
    ENodeC5* FUN_00717e50();
    bool FUN_00481eb0(TESBoundObject*);
};

struct CTargetC5
{
    ENodeC5* m_pFirstNode;
    CContainerC5* FUN_004bffb0();
    CItemC5* FUN_004bfba0(TESBoundObject*, int, int);
    void* FUN_004cafe0();
};

// @fnv 0x004cafe0
void* CTargetC5::FUN_004cafe0()
{
    MemHelperC5 kMem(0x36, 1, DAT_01020778, 0x1afa);
    ENodeC5* pList = this->FUN_004bffb0()->FUN_00717e50();
    IngredientItem* pA7 = 0;
    TESBoundObject* pObj7 = 0;
    CItemC5* pItem = 0;
    AlchemyItem* pB = 0;

    while (pList && !pList->FUN_008256d0())
    {
        pA7 = dynamic_cast<IngredientItem*>((*pList->FUN_006815c0())->p4);
        if (!pA7)
        {
            pB = dynamic_cast<AlchemyItem*>((*pList->FUN_006815c0())->p4);
            pObj7 = pB;
        }
        else
            pObj7 = pA7;

        if ((pB && pB->sub.v4()) || (pA7 && pA7->sub.v4()))
        {
            CItemC5* pNew = this->FUN_004bfba0(pObj7, 1, 0);
            if (!pNew || (pNew && pNew->FUN_00726070() + (*pList->FUN_006815c0())->count != 0))
            {
                if (!pNew)
                    pItem = new CItemC5(pObj7, 0);
                else
                    pItem = pNew;
                return pItem;
            }
        }
        pList = pList->FUN_00726070();
    }

    ENodeC5* pInv8 = this->m_pFirstNode;
    while (pInv8 && !pInv8->FUN_008256d0())
    {
        pA7 = dynamic_cast<IngredientItem*>((*pInv8->FUN_006815c0())->p8);
        if (!pA7)
        {
            pB = dynamic_cast<AlchemyItem*>((*pInv8->FUN_006815c0())->p8);
            pObj7 = pB;
        }
        else
            pObj7 = pA7;

        if ((pA7 && pA7->sub.v4()) || (pB && pB->sub.v4()))
        {
            if (!this->FUN_004bffb0()->FUN_00481eb0(pObj7))
            {
                if ((*pInv8->FUN_006815c0())->FUN_00726070() > 0)
                    return *pInv8->FUN_006815c0();
            }
        }
        pInv8 = pInv8->FUN_00726070();
    }
    return pItem;
}

struct ProcV6;

struct Actor6
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
    virtual bool v100();
    ProcV6* FUN_008d8520();
};

struct ProcV6
{
    virtual void p000();
    virtual void p001();
    virtual void p002();
    virtual void p003();
    virtual void p004();
    virtual void p005();
    virtual void p006();
    virtual void p007();
    virtual void p008();
    virtual void p009();
    virtual void p010();
    virtual void p011();
    virtual void p012();
    virtual void p013();
    virtual void p014();
    virtual void p015();
    virtual void p016();
    virtual void p017();
    virtual void p018();
    virtual void p019();
    virtual void p020();
    virtual void p021();
    virtual void p022();
    virtual void p023();
    virtual void p024();
    virtual void p025();
    virtual void p026();
    virtual void p027();
    virtual void p028();
    virtual void p029();
    virtual void p030();
    virtual void p031();
    virtual void p032();
    virtual void p033();
    virtual void p034();
    virtual void p035();
    virtual void p036();
    virtual void p037();
    virtual void p038();
    virtual void p039();
    virtual void p040();
    virtual void p041();
    virtual void p042();
    virtual void p043();
    virtual void p044();
    virtual void p045();
    virtual void p046();
    virtual void p047();
    virtual void p048();
    virtual void p049();
    virtual void p050();
    virtual void p051();
    virtual void p052();
    virtual void p053();
    virtual void p054();
    virtual void p055();
    virtual void p056();
    virtual void p057();
    virtual void p058();
    virtual void p059();
    virtual void p060();
    virtual void p061();
    virtual void p062();
    virtual void p063();
    virtual void p064();
    virtual void p065();
    virtual void p066();
    virtual void p067();
    virtual void p068();
    virtual void p069();
    virtual void p070();
    virtual void p071();
    virtual void p072();
    virtual void p073();
    virtual void p074();
    virtual void p075();
    virtual void p076();
    virtual void p077();
    virtual void p078();
    virtual void p079();
    virtual void p080();
    virtual void p081();
    virtual void p082();
    virtual void p083();
    virtual void p084();
    virtual void p085();
    virtual void p086();
    virtual void p087();
    virtual void p088();
    virtual void p089();
    virtual void p090();
    virtual void p091();
    virtual void p092();
    virtual void p093();
    virtual void p094();
    virtual void p095();
    virtual void p096();
    virtual void p097();
    virtual void p098();
    virtual void p099();
    virtual void p100();
    virtual void p101();
    virtual void p102();
    virtual void p103();
    virtual void p104();
    virtual void p105();
    virtual void p106();
    virtual void p107();
    virtual void p108();
    virtual void p109();
    virtual void p110();
    virtual void p111();
    virtual void p112();
    virtual void p113();
    virtual void p114();
    virtual void p115();
    virtual void v1d0(void* p);
};

struct ContObj6
{
    int count;
    void* pObj;
    void* pExtra;
};

struct Node1_6;

struct Cont6
{
    Node1_6* FUN_00717e50();
};

struct Node1_6
{
    ContObj6** FUN_006815c0();
    Node1_6* FUN_00726070();
    bool FUN_008256d0();
};

struct ItemCh6
{
    void* pExtraList;
    int m_iCountChange;
    void* m_pItemObject;
    int FUN_00726070();
};

struct Node2_6
{
    ItemCh6** FUN_006815c0();
    Node2_6* FUN_00726070();
    bool FUN_008256d0();
};

struct Item2_6
{
    int FUN_00726070();
    int FUN_0044ddc0();
};

bool __cdecl MatchesObjectType(void* a, void* b);
int __cdecl FUN_00679ba0(void* a);
int __fastcall FUN_0044ddc0(ItemCh6* p);

struct FUN_004cffe0_t
{
    void* m_pEntryList;
    bool HasItem(void* pRef);
    void* FUN_004bffb0();
    Item2_6* FUN_004bfba0(void* pForm, int a, int b);
    bool CheckItemRequirement(void* a1, void* a2, int a3, int* a4, void* a5, Actor6* a6);
};

// @fnv 0x004cffe0
bool FUN_004cffe0_t::CheckItemRequirement(void* a1, void* a2, int iRequiredCount, int* a4, void* a5, Actor6* pActor)
{
    int total = 0;
    if (a5 != 0)
        return this->HasItem(a5);

    Actor6* pOwner = 0;
    if (pActor != 0 && pActor->v100() != 0)
        pOwner = pActor;

    Node1_6* pNode = ((Cont6*)this->FUN_004bffb0())->FUN_00717e50();

    while (pNode != 0 && !pNode->FUN_008256d0())
    {
        void* pObj = (*pNode->FUN_006815c0())->pObj;
        if (pObj != 0 && ((a1 != 0 && pObj == a1) || (a1 == 0 && a2 != 0 && MatchesObjectType(pObj, a2))))
        {
            Item2_6* pItem = this->FUN_004bfba0(pObj, 1, 0);
            if (pItem != 0)
            {
                if ((*pNode->FUN_006815c0())->count < 0)
                {
                    return true;
                }
                else
                {
                    if (pItem != 0)
                        total += pItem->FUN_00726070() + (*pNode->FUN_006815c0())->count;
                    else
                        total += (*pNode->FUN_006815c0())->count;
                }
                if (pOwner != 0 && pOwner->FUN_008d8520() != 0)
                    pOwner->FUN_008d8520()->v1d0((void*)pItem->FUN_0044ddc0());
                *a4 = FUN_00679ba0((void*)pItem->FUN_0044ddc0());
            }
            else
            {
                if (pOwner != 0 && pOwner->FUN_008d8520() != 0)
                    pOwner->FUN_008d8520()->v1d0(pObj);
                *a4 = FUN_00679ba0(pObj);
                return true;
            }
        }
        pNode = pNode->FUN_00726070();
    }

    if (total >= iRequiredCount)
    {
        return true;
    }
    else
    {
        if (a1 != 0)
        {
            Item2_6* pItem2 = this->FUN_004bfba0(a1, 1, 0);
            if (pItem2 != 0 && pItem2->FUN_00726070() >= iRequiredCount)
            {
                if (pOwner != 0 && pOwner->FUN_008d8520() != 0)
                    pOwner->FUN_008d8520()->v1d0((void*)pItem2->FUN_0044ddc0());
                *a4 = FUN_00679ba0((void*)pItem2->FUN_0044ddc0());
                return true;
            }
        }
        else
        {
            Node2_6* pNode2 = (Node2_6*)this->m_pEntryList;
            while (pNode2 != 0 && !pNode2->FUN_008256d0() && *pNode2->FUN_006815c0() != 0)
            {
                void* pObj2 = (*pNode2->FUN_006815c0())->m_pItemObject;
                if (pObj2 != 0 && a2 != 0 && MatchesObjectType(pObj2, a2) &&
                    (*pNode2->FUN_006815c0())->FUN_00726070() >= iRequiredCount)
                {
                    if (pOwner != 0 && pOwner->FUN_008d8520() != 0)
                        pOwner->FUN_008d8520()->v1d0((void*)FUN_0044ddc0(*pNode2->FUN_006815c0()));
                    *a4 = FUN_00679ba0((void*)FUN_0044ddc0(*pNode2->FUN_006815c0()));
                    return true;
                }
                pNode2 = pNode2->FUN_00726070();
            }
        }
    }
    return false;
}

namespace Rebuild004d0650 {
struct Object
{
};
struct Extra
{
    bool HasOnlyAllowedExtraData(int);
};
struct FUN_0096a2d0
{
    char data[8];
    FUN_0096a2d0();
    ~FUN_0096a2d0();
    static void* operator new(unsigned int);
    static void operator delete(void*);
    unsigned FUN_005ae380();
    Extra** FUN_006815c0();
    FUN_0096a2d0* FUN_00726070();
    void FUN_00905820(Extra* const&);
    void FUN_005ae3d0(Extra**);
    void* FUN_004702f0(unsigned);
};
struct FUN_004bc550
{
    FUN_0096a2d0* list;
    int count;
    Object* form;
    FUN_004bc550(Object*, int);
    static void* operator new(unsigned int);
    static void operator delete(void*);
    int FUN_00726070();
    FUN_0096a2d0* FUN_00559450();
};
struct Entry
{
    int count;
    Object* form;
};
struct Node
{
    Entry** FUN_006815c0();
    Node* FUN_00726070();
    bool FUN_008256d0();
};
struct Container
{
    int FUN_00482a90(Object*);
    Node* FUN_00717e50();
};
struct Inventory
{
    FUN_004bc550* FUN_004bfba0(Object*, int, int);
    Container* FUN_004bffb0();
    FUN_004bc550* FUN_004d0650(Object*, int);
};
// @fnv 0x004d0650
FUN_004bc550* Inventory::FUN_004d0650(Object* object, int arg)
{
    FUN_004bc550* source3 = FUN_004bfba0(object, 1, arg);
    FUN_004bc550* result2 = 0;
    if (source3)
    {
        int count2 = FUN_004bffb0()->FUN_00482a90(object);
        result2 = new FUN_004bc550(object, count2 + source3->FUN_00726070());
        if (source3->FUN_00559450() && source3->FUN_00559450()->FUN_005ae380())
        {
            if (!result2->FUN_00559450())
                result2->list = new FUN_0096a2d0;
            Extra* extra7 = *source3->FUN_00559450()->FUN_006815c0();
            if (extra7->HasOnlyAllowedExtraData(0))
            {
                FUN_0096a2d0* node5 = source3->FUN_00559450();
                while (node5 && *node5->FUN_006815c0())
                {
                    extra7 = *node5->FUN_006815c0();
                    result2->list->FUN_00905820(extra7);
                    node5 = node5->FUN_00726070();
                }
            }
            else
            {
                result2->list->FUN_005ae3d0(&extra7);
            }
        }
        else
        {
            if (result2->FUN_00559450())
            {
                delete result2->list;
                result2->list = 0;
            }
        }
    }
    else
    {
        Node* base6 = FUN_004bffb0()->FUN_00717e50();
        Object* form2 = 0;
        while (base6 && !base6->FUN_008256d0())
        {
            form2 = (*base6->FUN_006815c0())->form;
            if (form2 == object)
            {
                result2 = new FUN_004bc550(object, (*base6->FUN_006815c0())->count);
                break;
            }
            base6 = base6->FUN_00726070();
        }
    }
    return result2;
}
}

struct InventoryScanNode
{
    InventoryStackRecord** FUN_006815c0();
    InventoryScanNode* FUN_00726070();
    bool FUN_008256d0();
};
struct InventoryScanExtra : ExtraDataList
{
    int FUN_0041d360();
};

// Walks the node list, scanning each item's extra-data list for an entry whose FUN_0041d360 equals value, and returns whether one was found.
// @fnv 0x004d1380
bool Inv4d1440::HasExtraDataWithValue(int value)
{
    InventoryScanNode* node;
    {
        bool found = false;
        node = (InventoryScanNode*)m_pEntryList;
        while (node && !node->FUN_008256d0() && *node->FUN_006815c0() && !found)
        {
            InventoryStackRecord* item = *node->FUN_006815c0();
            if (item)
            {
                BSSimpleList<ExtraDataList*>* extras = item->m_pExtraDataLists;
                while (extras && extras->GetItem())
                {
                    ExtraDataList* extra = extras->GetItem();
                    if (extra && ((InventoryScanExtra*)extra)->FUN_0041d360() == value)
                        found = true;
                    extras = extras->GetNext();
                }
            }
            node = node->FUN_00726070();
        }
        return found;
    }
}

// 0x004d2480  /MT /Od /Oy- /GS /EHsc /Gy
// thiscall, 1 stack arg (ret 4) -> bool.  SEH from AutoMemHelper local.

struct AutoMemHelper
{
    int m_iOldMemContext;
    AutoMemHelper(int context, bool track, const char* file, int line);
    ~AutoMemHelper();
};

struct GlobalObject_0096a2d0
{
    void Lock(const char* name);
};
struct BSSpinLockUnlock
{
    void Unlock();
};
extern GlobalObject_0096a2d0 g_011c64e0;

extern const char g_inventoryChangesSourceFilename[];

struct Sh00568bb0
{
    void FUN_00568bb0(void* p);
};
struct Sh00575690
{
    void FUN_00575690(void* p);
};
struct Sh005d43c0
{
    void* FUN_005d43c0();
};
struct Sh00419f80
{
    void FUN_00419f80(void* p);
};
struct Sh00411fd0
{
    void RemoveAllCopyableExtra(void* p);
};
struct Sh00418830
{
    void* FUN_00418830();
};
struct Sh00418800
{
    void* FUN_00418800();
};
struct Sh005ac1e0
{
    bool FUN_005ac1e0(void* a, void* b, void* c, bool d);
};
struct Sh0087ce80
{
    void FUN_0087ce80(void* p);
};
struct Sh00436aa0
{
    void* FUN_00436aa0();
};
struct Sh0049eea0
{
    void FUN_0049eea0(const void* p);
};
struct Sh004013e0
{
    bool GetInitialized() const;
};

struct C004d2480
{
    BSSimpleList<InventoryStackRecord*>* m_pEntryList;
    int unk04;
    int unk08;
    int unk0c;
    bool m_bChanged;

    bool FUN_004d2480(TESObjectREFR* apRef);
};

// Locks g_011c64e0, iterates the change list's items and extra-data lists, runs scripts on initialized forms of type 0x11, and returns whether any ran.
// @fnv 0x004d2480
bool C004d2480::FUN_004d2480(TESObjectREFR* apRef)
{
    m_bChanged = 0;
    if (apRef == 0)
        return false;
    TESObjectCELL* pCell = apRef->GetParentCell();
    if (pCell == 0)
        return false;

    g_011c64e0.Lock(0);
    BSSimpleList<InventoryStackRecord*>* pChange = m_pEntryList;
    bool bRan = false;
    {
        AutoMemHelper memCtx(0x15, true, g_inventoryChangesSourceFilename, 0x264b);
        ((Sh0087ce80*)DAT_011c6444)->FUN_0087ce80(pCell);
        ((Sh0049eea0*)DAT_011c6444)->FUN_0049eea0(((Sh00436aa0*)apRef)->FUN_00436aa0());

        while (pChange != 0 && *(void**)&pChange->GetItem() != 0)
        {
            InventoryStackRecord* pItem = pChange->GetItem();
            BSSimpleList<ExtraDataList*>* pExtraList = pItem->m_pExtraDataLists;
            while (pExtraList != 0 && *(void**)&pExtraList->GetItem() != 0)
            {
                ExtraDataList* pExtra = pExtraList->GetItem();
                if (pExtra != 0)
                {
                    void* pScript = ((Sh00418800*)pExtra)->FUN_00418800();
                    if (pScript != 0 && ((Sh004013e0*)pScript)->GetInitialized())
                    {
                        if (FNV_GetFormType((TESForm*)pScript) == 0x11)
                        {
                            ((Sh00568bb0*)DAT_011c6444)->FUN_00568bb0(pExtra);
                            ((Sh00575690*)DAT_011c6444)->FUN_00575690((void*)FUN_0044ddc0((InventoryItemEntry*)pItem));
                            if (((Sh005ac1e0*)pScript)
                                    ->FUN_005ac1e0(DAT_011c6444, ((Sh00418830*)pExtra)->FUN_00418830(), apRef, false))
                                bRan = true;
                            ((Sh00419f80*)((Sh005d43c0*)DAT_011c6444)->FUN_005d43c0())->FUN_00419f80((void*)0);
                            ((Sh00411fd0*)((Sh005d43c0*)DAT_011c6444)->FUN_005d43c0())->RemoveAllCopyableExtra((void*)1);
                        }
                        if (m_bChanged)
                            break;
                    }
                }
                pExtraList = pExtraList->GetNext();
            }
            if (m_bChanged)
            {
                pChange = m_pEntryList;
                m_bChanged = 0;
            }
            pChange = pChange->GetNext();
        }
        ((Sh0087ce80*)DAT_011c6444)->FUN_0087ce80(0);
        ((Sh00575690*)DAT_011c6444)->FUN_00575690(0);
    }
    ((BSSpinLockUnlock*)&g_011c64e0)->Unlock();
    return bRan;
}

class FUN_008515f0
{
  public:
    int a;
    ~FUN_008515f0();
};
class ListZ
{
  public:
    void FUN_00905330(FUN_008515f0**);
    int FUN_005ae380();
};
class Holder
{
  public:
    ListZ* m0;
    int m4;
    void RemoveAndDelete(FUN_008515f0* p);
};
// @fnv 0x00851620
void Holder::RemoveAndDelete(FUN_008515f0* p)
{
    if (!m0)
        return;
    m0->FUN_00905330(&p);
    delete p;
    m4 = m0->FUN_005ae380();
}

class TESEnchantableForm
{
  public:
    virtual void v00();
    unsigned short FUN_004a8ae0();
};
namespace charge4bd {
struct C4Enchant
{
    float GetValue();
};
struct C4Node
{
    C4Enchant* pItem;
    C4Node* pNext;
    C4Enchant** FUN_006815c0();
};
struct C4Entry
{
    C4Node* pList;
    int unk04;
    TESBoundObject* pForm;
    float FUN_004bd350();
};
}
using namespace charge4bd;

// Returns the first valid enchant value from pList, falling back to the form's base value, or -1.0f if the form is not enchantable.
// @fnv 0x004bd350
float C4Entry::FUN_004bd350()
{
    TESEnchantableForm* pEnchantableForm = dynamic_cast<TESEnchantableForm*>(pForm);
    if (pEnchantableForm)
    {
        C4Node* pNode = pList;
        if (pNode && *pNode->FUN_006815c0())
        {
            C4Enchant* pEnchant = *pNode->FUN_006815c0();
            if (pEnchant && pEnchant->GetValue() != -1.0f)
            {
                return pEnchant->GetValue();
            }
            else
            {
                return (float)pEnchantableForm->FUN_004a8ae0();
            }
        }
        else
        {
            return (float)pEnchantableForm->FUN_004a8ae0();
        }
    }
    return -1.0f;
}

struct XActor17;
struct XProcess17;
struct XExtra17;
struct XExtra17;
struct XNodeE17
{
    XExtra17** _ref_006815c0();
    XNodeE17* _ref_00726070();
    bool _ref_008256d0();
    void _ref_00905330(XExtra17**);
};
struct XNodeC17
{
    void _ref_00905330(InventoryStackRecord**);
};
struct XDism17Part17
{
    unsigned char b0;
    unsigned char b1;
};
struct XDism17Arr17
{
    void* a;
    void* b;
    unsigned int FUN_0044ddc0();
};
struct XDism17
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    XDism17Arr17 arr;
    XDism17Part17* GetInfoAt(unsigned int);
};
struct XExtra17
{
    virtual ~XExtra17();
    bool FUN_00418b10();
    bool FUN_00418ab0(bool);
    void SetWornState(bool, bool);
    int ItemsInList();
    char GetExtraByteValue();
    void FUN_00419ad0(short);
    bool FUN_004bca60();
    bool CompareListForContainer(XExtra17*, int, bool);
    short FUN_00418770();
    void SetHotKey(unsigned char);
    XDism17* FUN_0042e8c0();
};
struct XChange17
{
    int _ref_00726070();
    int FUN_004bc8f0(bool);
    void* FUN_00559450();
    ~XChange17();
};
struct XBiped17
{
    bool FUN_00418b10();
};
struct XBiped17Sub17
{
    bool FUN_00480d10();
    bool FUN_004c0bd0();
};
struct XArmor17
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c,
        unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    XBiped17Sub17 biped;
};
struct XFound17
{
    int FUN_0044ddc0();
};
struct XTQ17
{
    void SendCommand22(XActor17*, int);
};
struct XRefr17
{
    void FUN_00571b50();
    void* FUN_0043fcd0();
    void FUN_008b0bd0(void*);
};
struct XForm17
{
    bool FUN_00483710();
};
struct XNPC17
{
    void SetField1F0(void*);
};
struct XListObj17
{
    void FUN_00470470();
};
struct XInv17
{
    XNodeC17* pList;
    XActor17* pRef;
    InventoryStackRecord* FUN_004bfba0(unsigned int, int, int);
    TESContainer* FUN_004bffb0();
};
void __fastcall FUN_004bf0e0(InventoryChanges*);
int __fastcall FUN_00401170(unsigned int);
XBiped17* __cdecl FUN_00480db0(unsigned int);
bool __fastcall FUN_004c0bf0(TESObjectWEAP*);
bool __cdecl FUN_008c7aa0();

extern XExtra17* DAT_011c6448;

struct XProcess17
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
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
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
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
    virtual InventoryStackRecord* CurrentWeapon();
    virtual InventoryStackRecord* CurrentAmmo();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void SetWeapon(int, int, bool);
    virtual void v164();
    virtual void SetAmmo(int);
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
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
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
    virtual void SetUpdate(int);
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
    virtual void v4bc();
    virtual void v4c0();
    virtual void v4c4();
    virtual void v4c8();
    virtual void v4cc();
    virtual void v4d0();
    virtual void v4d4();
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
    virtual void v52c();
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
    virtual void v5a0();
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
    virtual void v610();
    virtual void v614();
    virtual void v618();
    virtual void v61c();
    virtual void v620();
    virtual void v624();
    virtual void v628();
    virtual void v62c();
    virtual void v630();
    virtual void v634();
    virtual void v638();
    virtual void v63c();
    virtual void v640();
    virtual void v644();
    virtual void v648();
    virtual void v64c();
    virtual void v650();
    virtual void v654();
    virtual void v658();
    virtual void v65c();
    virtual void v660();
    virtual void v664();
    virtual void v668();
    virtual void v66c();
    virtual void v670();
    virtual void v674();
    virtual void v678();
    virtual void v67c();
    virtual void v680();
    virtual void v684();
    virtual void v688();
    virtual void v68c();
    virtual void v690();
    virtual void v694();
    virtual void v698();
    virtual void v69c();
    virtual void v6a0();
    virtual void v6a4();
    virtual void v6a8();
    virtual void v6ac();
    virtual void v6b0();
    virtual void v6b4();
    virtual void v6b8();
    virtual void v6bc();
    virtual void v6c0();
    virtual void v6c4();
    virtual void v6c8();
    virtual void v6cc();
    virtual void v6d0();
    virtual void v6d4();
    virtual void v6d8();
    virtual void v6dc();
    virtual void v6e0();
    virtual void UpdateArmor(XActor17*);
};
struct XActor17
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
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
    virtual void MarkAsModified(int);
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
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
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
    virtual bool CanRemove(bool);
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40,
        unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64;
    XProcess17* process;
    XProcess17* FUN_008d8520();
    XExtra17* FUN_005d43c0();
    void FUN_00571b50();
    void FUN_00483710();
    void* FUN_0043fcd0();
    void FUN_008b0bd0(void*);
    void SetField1F0(void*);
};
struct XHost17
{
    bool FUN_004c0cf0(bool*, unsigned int, int, XActor17*, ExtraDataList*, bool, bool, InventoryStackRecord*, bool*);
};
// Processes matching extra data, updates equipment state and counts, and may remove or merge extra lists.
// @fnv 0x004c0cf0
bool XHost17::FUN_004c0cf0(bool* a0, unsigned int a1, int iCount, XActor17* apActor, ExtraDataList* apExtraList,
                           bool abWorn, bool a6, InventoryStackRecord* apEntry, bool* abRemoved)
{
    DAT_011c6448 = 0;
    FUN_004bf0e0((InventoryChanges*)this);
    InventoryStackRecord* entry0 = apEntry != 0 ? apEntry : ((XInv17*)this)->FUN_004bfba0(a1, 1, 0);
    if (entry0 == 0)
        return true;
    *a0 = 1;
    XNodeE17* node1 = (XNodeE17*)entry0->m_pExtraDataLists;
    bool result3 = true;
    int count;
    bool armors2 = false;
    bool weapon3 = false;
    while (node1 != 0 && *node1->_ref_006815c0() != 0)
    {
        XExtra17* extra = *node1->_ref_006815c0();
        if (extra->FUN_00418ab0(abWorn) && (apExtraList == 0 || apExtraList == (ExtraDataList*)extra))
        {
            InventoryStackRecord* found = 0;
            XBiped17* biped = FUN_00480db0(a1);
            if (extra->FUN_00418b10() && !apActor->CanRemove(false))
            {
                *a0 = 0;
                return result3;
            }
            if (apActor != 0 && apActor->FUN_008d8520() != 0)
            {
                bool can = true;
                switch (FUN_00401170(a1))
                {
                case 26: {
                    XDism17* dism = apActor->FUN_005d43c0()->FUN_0042e8c0();
                    if (dism != 0 && dism->arr.FUN_0044ddc0() != 0 && dism->GetInfoAt(0) != 0)
                    {
                        for (unsigned int i = 0; i < dism->arr.FUN_0044ddc0(); i++)
                        {
                            XDism17Part17* part = dism->GetInfoAt(i);
                            if (part->b0 == 0 && part->b1 != 0)
                                can = false;
                        }
                    }
                    if (can)
                        apActor->process->SetUpdate(1);
                    break;
                }
                case 40: {
                    found = apActor->FUN_008d8520()->CurrentWeapon();
                    if (found != 0)
                    {
                        if (*((XNodeE17*)found->m_pExtraDataLists)->_ref_006815c0() == extra || apExtraList == 0)
                        {
                            if (apActor == (XActor17*)g_thePlayer)
                                ((XNPC17*)g_thePlayer)->SetField1F0(0);
                            TESObjectWEAP* weap = (TESObjectWEAP*)a1;
                            if (FUN_004c0bf0(weap))
                                weapon3 = true;
                            if (FUN_008c7aa0())
                            {
                                ((XTQ17*)FUN_004537b0())->SendCommand22(apActor, ((XFound17*)found)->FUN_0044ddc0());
                            }
                            else
                            {
                                ((XRefr17*)apActor)->FUN_00571b50();
                                apActor->FUN_008d8520()->SetWeapon(0, 0, false);
                                apActor->FUN_008d8520()->SetAmmo(0);
                            }
                        }
                    }
                    break;
                }
                break;
                case 24: {
                    if (((XArmor17*)a1)->biped.FUN_00480d10() || ((XArmor17*)a1)->biped.FUN_004c0bd0())
                        armors2 = true;
                    XDism17* dism2 = apActor->FUN_005d43c0()->FUN_0042e8c0();
                    if (dism2 != 0 && dism2->arr.FUN_0044ddc0() != 0 && dism2->GetInfoAt(0) != 0)
                    {
                        for (unsigned int i2 = 0; i2 < dism2->arr.FUN_0044ddc0(); i2++)
                        {
                            XDism17Part17* part2 = dism2->GetInfoAt(i2);
                            if (part2->b0 == 0 && part2->b1 != 0)
                                can = false;
                        }
                    }
                    if (can)
                        apActor->process->SetUpdate(1);
                    break;
                }
                case 41: {
                    found = apActor->FUN_008d8520()->CurrentAmmo();
                    if (found != 0)
                    {
                        if (*((XNodeE17*)found->m_pExtraDataLists)->_ref_006815c0() == extra)
                        {
                            ((XForm17*)apActor)->FUN_00483710();
                            apActor->FUN_008d8520()->SetAmmo(0);
                        }
                    }
                    break;
                }
                }
            }
            extra->SetWornState(false, abWorn);
            if ((unsigned int)extra->ItemsInList() <= 1)
            {
                if ((char)extra->GetExtraByteValue() >= 0)
                {
                    extra->FUN_00419ad0(
                        (short)(((XChange17*)entry0)->_ref_00726070() - ((XChange17*)entry0)->FUN_004bc8f0(false)));
                }
                else
                {
                    extra->FUN_00419ad0((short)0);
                }
            }
            if (extra->FUN_004bca60())
            {
                ((XNodeE17*)entry0->m_pExtraDataLists)->_ref_00905330(&extra);
                delete extra;
                if ((ExtraDataList*)extra == apExtraList && abRemoved != 0)
                    *abRemoved = true;
                extra = 0;
                result3 = false;
                break;
            }
            else
            {
                XNodeE17* node2 = (XNodeE17*)entry0->m_pExtraDataLists;
                while (node2 != 0 && *node2->_ref_006815c0() != 0 && result3)
                {
                    XExtra17* extra1 = *node2->_ref_006815c0();
                    XExtra17* savedState3 = extra;
                    bool different2 = true;
                    if (savedState3 != 0)
                    {
                        different2 = savedState3->CompareListForContainer(extra1, 0, weapon3) ||
                                     extra1->CompareListForContainer(savedState3, 0, weapon3);
                    }
                    if (different2 || extra == extra1)
                    {
                        node2 = node2->_ref_00726070();
                    }
                    else
                    {
                        extra1->FUN_00419ad0((short)(extra1->FUN_00418770() + iCount));
                        DAT_011c6448 = extra1;
                        if (extra != 0 && (char)extra->GetExtraByteValue() >= 0)
                        {
                            extra1->SetHotKey((unsigned char)extra->GetExtraByteValue());
                        }
                        if (extra1->FUN_004bca60())
                        {
                            ((XNodeE17*)entry0->m_pExtraDataLists)->_ref_00905330(&extra1);
                            delete extra1;
                        }
                        else
                        {
                            ((XNodeE17*)entry0->m_pExtraDataLists)->_ref_00905330(&extra);
                        }
                        delete extra;
                        extra = 0;
                        result3 = false;
                    }
                }
            }
            node1 = 0;
        }
        else
            node1 = node1->_ref_00726070();
    }
    if (armors2)
    {
        if (apActor != 0)
        {
            if (apActor->FUN_008d8520() != 0)
            {
                apActor->FUN_008d8520()->UpdateArmor(apActor);
            }
        }
    }
    if (((XInv17*)this)->pRef != 0)
        ((XInv17*)this)->pRef->MarkAsModified(0x20);
    count = ((XInv17*)this)->FUN_004bffb0()->GetObjectCount((TESObject*)a1);
    if (entry0 != 0 && entry0->m_pExtraDataLists != 0 && ((XNodeE17*)entry0->m_pExtraDataLists)->_ref_008256d0() &&
        (((XChange17*)entry0)->_ref_00726070() == 0 || count == ((XChange17*)entry0)->_ref_00726070()))
    {
        ((XNodeC17*)((InventoryChanges*)this)->m_pEntryList)->_ref_00905330(&entry0);
        delete (XChange17*)entry0;
        return false;
    }
    else if (((XChange17*)entry0)->_ref_00726070() < 0 && ((XChange17*)entry0)->FUN_00559450() != 0)
    {
        ((XListObj17*)((XChange17*)entry0)->FUN_00559450())->FUN_00470470();
    }
    if (apActor != 0)
        ((XRefr17*)apActor)->FUN_008b0bd0(((XRefr17*)apActor)->FUN_0043fcd0());
    return result3;
}

namespace fnv_004d1960 {
struct InvExtra;
struct InvScript;
struct InvTemporary;
struct InvForm;
struct FUN_0055a2f0
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual ~FUN_0055a2f0();
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
    void FUN_00484490();
};
struct InvScript
{
    void* FUN_005abf60();
    void FUN_005ac1e0(FUN_0055a2f0*, void*, int, int);
};
struct FUN_00410360_Inventory
{
    void* table;
    void* data;
    int unk08, unk0c, unk10, unk14, unk18, unk1c;
    FUN_00410360_Inventory();
    InvScript* FUN_00418800();
    void FUN_00419ed0(InvScript*);
    void FUN_00419f80(void*);
    void* FUN_00418830();
    void FUN_00419ad0(int);
};
struct FUN_0096a2d0
{
    FUN_00410360_Inventory* data;
    void* next;
    FUN_0096a2d0();
    FUN_00410360_Inventory** FUN_006815c0();
    FUN_0096a2d0* FUN_00726070();
    void FUN_005ae3d0(FUN_00410360_Inventory* const&);
};
struct FUN_004bc550_Inventory
{
    FUN_0096a2d0* extras;
    int count;
    InvForm* form;
    FUN_004bc550_Inventory(InvForm*, int);
    InvScript* FUN_004bde40();
    InvForm* FUN_0044ddc0();
    int FUN_00726070();
};
struct InvBaseItem
{
    int count;
    InvForm* form;
};
struct InvBaseNode
{
    bool FUN_008256d0();
    InvBaseItem** FUN_006815c0();
    InvBaseNode* FUN_00726070();
};
struct InvBaseList
{
    InvBaseNode* FUN_00717e50();
};
struct InvChangesNode
{
    FUN_004bc550_Inventory** FUN_006815c0();
    InvChangesNode* FUN_00726070();
};
struct InvInventory
{
    InvChangesNode* changes;
    InvBaseList* FUN_004bffb0();
    FUN_004bc550_Inventory* FUN_004bfba0(InvForm*, int, int);
    void FUN_004c3380(FUN_004bc550_Inventory*, int);
    void FUN_004d1960();
};
InvScript* FUN_004826d0(InvForm*);
int FUN_00ec7d40(int);
// Iterates base and changed inventory items, attaching scripts to their extra data and creating new extras as needed.
// @fnv 0x004d1960
void InvInventory::FUN_004d1960()
{
    InvBaseNode* node = FUN_004bffb0()->FUN_00717e50();
    while (node && !node->FUN_008256d0())
    {
        InvBaseItem* base26 = *node->FUN_006815c0();
        InvScript* script1 = FUN_004826d0(base26->form);
        int number73 = base26->count;
        int count17 = FUN_00ec7d40(number73);
        if (script1 && count17 > 0)
        {
            FUN_004bc550_Inventory* item = FUN_004bfba0(base26->form, 1, 0);
            if (!item || !item->FUN_004bde40())
            {
                bool created = false;
                if (!item)
                {
                    created = true;
                    item = new FUN_004bc550_Inventory(base26->form, 0);
                }
                if (!item->extras)
                    item->extras = new FUN_0096a2d0;
                else
                {
                    FUN_0096a2d0* cursorA = item->extras;
                    while (cursorA && *cursorA->FUN_006815c0())
                    {
                        FUN_00410360_Inventory* extraA = *cursorA->FUN_006815c0();
                        if (extraA && !extraA->FUN_00418800())
                        {
                            extraA->FUN_00419ed0(script1);
                            extraA->FUN_00419f80(extraA->FUN_00418800()->FUN_005abf60());
                            FUN_0055a2f0* temporaryA = new FUN_0055a2f0;
                            temporaryA->FUN_00484490();
                            script1->FUN_005ac1e0(temporaryA, extraA->FUN_00418830(), 0, 0);
                            delete temporaryA;
                            --count17;
                        }
                        cursorA = cursorA->FUN_00726070();
                    }
                }
                if (count17 > 0)
                {
                    for (int iB = 0; iB < count17; ++iB)
                    {
                        FUN_00410360_Inventory* extraB = 0;
                        extraB = new FUN_00410360_Inventory;
                        item->extras->FUN_005ae3d0(extraB);
                        extraB->FUN_00419ad0(1);
                        if (extraB && !extraB->FUN_00418800())
                        {
                            extraB->FUN_00419ed0(script1);
                            extraB->FUN_00419f80(extraB->FUN_00418800()->FUN_005abf60());
                            FUN_0055a2f0* temporaryB = new FUN_0055a2f0;
                            temporaryB->FUN_00484490();
                            script1->FUN_005ac1e0(temporaryB, extraB->FUN_00418830(), 0, 0);
                            delete temporaryB;
                        }
                    }
                }
                if (created)
                    FUN_004c3380(item, 1);
            }
            else if (item)
            {
                FUN_0096a2d0* cursorC = item->extras;
                while (cursorC && *cursorC->FUN_006815c0())
                {
                    FUN_00410360_Inventory* extraC = *cursorC->FUN_006815c0();
                    if (extraC)
                    {
                        FUN_0055a2f0* temporaryC = new FUN_0055a2f0;
                        temporaryC->FUN_00484490();
                        script1->FUN_005ac1e0(temporaryC, extraC->FUN_00418830(), 0, 0);
                        delete temporaryC;
                        --count17;
                    }
                    cursorC = cursorC->FUN_00726070();
                }
            }
        }
        node = node->FUN_00726070();
    }
    InvChangesNode* change = changes;
    while (change && *change->FUN_006815c0())
    {
        FUN_004bc550_Inventory* itemB5 = *change->FUN_006815c0();
        InvForm* formB22 = itemB5->FUN_0044ddc0();
        InvScript* scriptB46 = FUN_004826d0(formB22);
        int numberB11 = itemB5->FUN_00726070();
        int countB11 = FUN_00ec7d40(numberB11);
        if (scriptB46 && countB11 > 0)
        {
            if (itemB5 && !itemB5->FUN_004bde40())
            {
                if (!itemB5->extras)
                    itemB5->extras = new FUN_0096a2d0;
                else
                {
                    FUN_0096a2d0* cursorD = itemB5->extras;
                    while (cursorD && *cursorD->FUN_006815c0())
                    {
                        FUN_00410360_Inventory* extraD = *cursorD->FUN_006815c0();
                        if (extraD && !extraD->FUN_00418800())
                        {
                            extraD->FUN_00419ed0(scriptB46);
                            extraD->FUN_00419f80(extraD->FUN_00418800()->FUN_005abf60());
                            FUN_0055a2f0* temporaryD = new FUN_0055a2f0;
                            temporaryD->FUN_00484490();
                            scriptB46->FUN_005ac1e0(temporaryD, extraD->FUN_00418830(), 0, 0);
                            delete temporaryD;
                            --countB11;
                        }
                        cursorD = cursorD->FUN_00726070();
                    }
                }
                for (int iE = 0; iE < countB11; ++iE)
                {
                    FUN_00410360_Inventory* extraE = 0;
                    extraE = new FUN_00410360_Inventory;
                    itemB5->extras->FUN_005ae3d0(extraE);
                    extraE->FUN_00419ad0(1);
                    if (extraE && !extraE->FUN_00418800())
                    {
                        extraE->FUN_00419ed0(scriptB46);
                        extraE->FUN_00419f80(extraE->FUN_00418800()->FUN_005abf60());
                        FUN_0055a2f0* temporaryE = new FUN_0055a2f0;
                        temporaryE->FUN_00484490();
                        scriptB46->FUN_005ac1e0(temporaryE, extraE->FUN_00418830(), 0, 0);
                        delete temporaryE;
                    }
                }
            }
            else if (itemB5)
            {
                FUN_0096a2d0* cursorF = itemB5->extras;
                while (cursorF && *cursorF->FUN_006815c0())
                {
                    FUN_00410360_Inventory* extraF = *cursorF->FUN_006815c0();
                    if (extraF)
                    {
                        FUN_0055a2f0* temporaryF = new FUN_0055a2f0;
                        temporaryF->FUN_00484490();
                        scriptB46->FUN_005ac1e0(temporaryF, extraF->FUN_00418830(), 0, 0);
                        delete temporaryF;
                        --countB11;
                    }
                    cursorF = cursorF->FUN_00726070();
                }
            }
        }
        change = change->FUN_00726070();
    }
}

}  // namespace fnv_004d1960

struct HealthExtra : public ExtraDataList
{
    HealthExtra();
    void FUN_00419c60(float);
    void SetExtraHealth(float);
    void FUN_0041aef0();
    bool IsEmpty();
};
struct HealthInventory : public InventoryChanges
{
    TESObjectREFR* FUN_00726070();
    InventoryStackRecord* FUN_004bfba0(TESBoundObject*, int, int);
};
struct HealthItem : public InventoryStackRecord
{
    float FUN_004bcdb0(int);
    TESBoundObject* FUN_0044ddc0();
    BSSimpleList<ExtraDataList*>* FUN_00559450();
    void FUN_004bd030(float health, HealthInventory* inventory, ExtraDataList* selected, bool removeEmpty);
};
int __cdecl FUN_004873d0(TESBoundObject*);
// Updates the health extra data on the item, creating or removing HealthExtra entries based on the health value and removeEmpty flag.
// @fnv 0x004bd030
void HealthItem::FUN_004bd030(float health, HealthInventory* inventory, ExtraDataList* selected, bool removeEmpty)
{
    TESHealthForm* baseHealth = dynamic_cast<TESHealthForm*>(m_pItemObject);
    int healthForm = FUN_004873d0(m_pItemObject);
    int currentHealth = (int)FUN_004bcdb0(0);
    if (inventory->FUN_00726070())
        inventory->FUN_00726070()->MarkAsModified(0x20);
    if (baseHealth)
    {
        if (health < healthForm || currentHealth > healthForm)
        {
            BSSimpleList<ExtraDataList*>* list = m_pExtraDataLists;
            if (!list)
            {
                HealthExtra* extra = new HealthExtra;
                list = new BSSimpleList<ExtraDataList*>;
                extra->FUN_00419c60(health);
                list->AddHead((ExtraDataList*&)extra);
                m_pExtraDataLists = list;
            }
            else
            {
                ExtraDataList* extra = 0;
                while (list && list->GetItem())
                {
                    extra = list->GetItem();
                    if (extra && extra == selected)
                    {
                        if (extra)
                        {
                            ((HealthExtra*)extra)->SetExtraHealth(health);
                            return;
                        }
                    }
                    list = list->GetNext();
                }
                extra = new HealthExtra;
                ((HealthExtra*)extra)->SetExtraHealth(health);
                m_pExtraDataLists->AddHead(extra);
            }
        }
        else
        {
            BSSimpleList<ExtraDataList*>* list = m_pExtraDataLists;
            while (list && list->GetItem())
            {
                ExtraDataList* extra = list->GetItem();
                if (extra && extra == selected)
                {
                    ((HealthExtra*)extra)->FUN_0041aef0();
                    if (((HealthExtra*)extra)->IsEmpty() && removeEmpty)
                    {
                        HealthItem* item = (HealthItem*)inventory->FUN_004bfba0(FUN_0044ddc0(), 1, 0);
                        BSSimpleList<ExtraDataList*>* extras = item->FUN_00559450();
                        extras->Remove(extra);
                        delete (ExtraVDtor*)extra;
                    }
                    break;
                }
                else
                {
                    list = list->GetNext();
                }
            }
        }
    }
}

struct CleanRef;
struct CleanEvent;
struct CleanScript
{
    CleanEvent* FUN_005abf60();
    void FUN_005ac1e0(CleanRef*, CleanEvent*, int, int);
};
struct CleanRef
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual ~CleanRef();
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38,
        unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64;
    CleanRef();
    static void* operator new(unsigned int);
    static void operator delete(void*);
    void FUN_00484490();
};
struct CleanDatum
{
    unsigned char FUN_004f1540();
};
struct CleanExtra
{
    virtual ~CleanExtra();
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    CleanExtra();
    static void* operator new(unsigned int);
    static void operator delete(void*);
    double FUN_004186f0();
    void FUN_0041aef0();
    short FUN_00418770();
    void RemoveExtra24();
    bool FUN_004bca60();
    void FUN_00419ad0(unsigned short);
    CleanScript* FUN_00418800();
    void FUN_00419ed0(CleanScript*);
    void FUN_00419f80(CleanEvent*);
    CleanEvent* FUN_00418830();
    void FUN_0041aed0();
    bool FUN_00418ab0(bool);
    void RemoveAll(bool);
    void DuplicateExtraListForContainer(CleanExtra*);
    void SetWornState(bool, bool);
    unsigned int ItemsInList();
    CleanDatum* FUN_00726070();
    void* GetExtraData(unsigned char);
    void RemoveExtra(CleanDatum*, bool);
    void AddExtra(CleanDatum*);
};
struct CleanNode
{
    CleanExtra** FUN_006815c0();
    CleanNode* FUN_00726070();
    bool FUN_008256d0();
    void FUN_0063f7b0();
    void FUN_00905330(CleanExtra**);
    void FUN_00905820(CleanExtra**);
    void FUN_005ae3d0(CleanExtra**);
    unsigned int FUN_005ae380();
    void FUN_00470470();
    ~CleanNode();
    static void operator delete(void*);
};
struct CleanItem
{
    CleanNode* head;
    int count;
    TESBoundObject* form;
    TESBoundObject* FUN_0044ddc0();
    int FUN_00726070();
    CleanNode* FUN_00559450();
    CleanScript* FUN_004bde40();
    bool FUN_004bddd0(bool);
    bool FUN_004bcb70();
    int FUN_004bc8f0(bool);
    int CountAndPruneEntries();
    void SetExtraListFlag(int, int, bool);
};
struct CleanItemNode
{
    bool FUN_008256d0();
    CleanItem** FUN_006815c0();
    CleanItemNode* FUN_00726070();
};
struct CleanBaseEntry
{
    int count;
    TESBoundObject* form;
};
struct CleanBaseNode
{
    bool FUN_008256d0();
    CleanBaseEntry** FUN_006815c0();
    CleanBaseNode* FUN_00726070();
};
struct CleanContainer
{
    CleanBaseNode* FUN_00717e50();
    int FUN_00482a90(TESBoundObject*);
};
struct CleanFormView
{
    int FUN_00401170();
};
bool FUN_00481f10(TESBoundObject*);
CleanScript* FUN_004826d0(TESBoundObject*);
struct InventoryClean
{
    CleanItemNode* head;
    void* owner;
    CleanContainer* FUN_004bffb0();
    CleanItem* FUN_004bfba0(TESBoundObject*, int, int);
    void FUN_004d1960();
    void FUN_004cbbc0();
};
// Updates extra lists and counts while traversing container and inventory entries, removing or freeing entries under several conditions.
// @fnv 0x004cbbc0
void InventoryClean::FUN_004cbbc0()
{
    TESBoundObject* formScope7 = 0;
    CleanBaseNode* baseScope8 = FUN_004bffb0()->FUN_00717e50();
    TESLevItem* leveledScope2 = 0;
    while (baseScope8 && !baseScope8->FUN_008256d0())
    {
        formScope7 = (*baseScope8->FUN_006815c0())->form;
        leveledScope2 = dynamic_cast<TESLevItem*>((*baseScope8->FUN_006815c0())->form);
        MoveFormInfo* infoScope3 = FUN_00480db0(formScope7);
        if (formScope7 && !leveledScope2 && (!infoScope3 || infoScope3->FUN_00480d90()))
        {
            CleanItem* itemScope4Local28 = FUN_004bfba0(formScope7, 1, 0);

            if (itemScope4Local28)
            {
                TESHealthForm* healthScope5 = dynamic_cast<TESHealthForm*>(itemScope4Local28->FUN_0044ddc0());
                if (healthScope5 && itemScope4Local28->head)
                {
                    CleanNode* nodeScope6 = itemScope4Local28->head;
                    while (nodeScope6 && *nodeScope6->FUN_006815c0())
                    {
                        CleanExtra* extraScope7 = *nodeScope6->FUN_006815c0();
                        if (extraScope7->FUN_004186f0() > -1.0 &&
                            extraScope7->FUN_004186f0() == healthScope5->GetHealth())
                        {
                            extraScope7->FUN_0041aef0();
                            int countScope8 = extraScope7->FUN_00418770();
                            extraScope7->RemoveExtra24();
                            if (extraScope7->FUN_004bca60())
                            {
                                nodeScope6->FUN_00905330(&extraScope7);
                                delete extraScope7;
                                nodeScope6 = itemScope4Local28->head;
                            }
                            else
                            {
                                extraScope7->FUN_00419ad0((unsigned short)countScope8);
                                nodeScope6 = nodeScope6->FUN_00726070();
                            }
                        }
                        else
                            nodeScope6 = nodeScope6->FUN_00726070();
                    }
                }
            }

            if (itemScope4Local28 && FUN_00481f10(formScope7) && owner == inventoryPlayer && itemScope4Local28->head)
            {
                CleanNode* nodeScope9 = itemScope4Local28->head;
                while (nodeScope9 && *nodeScope9->FUN_006815c0())
                {
                    CleanExtra* extraScope10 = *nodeScope9->FUN_006815c0();
                    nodeScope9->FUN_0063f7b0();
                    delete extraScope10;
                }
            }

            if (itemScope4Local28 && itemScope4Local28->FUN_004bde40())
            {
                CleanNode* nodeScope11 = itemScope4Local28->head;
                while (nodeScope11 && *nodeScope11->FUN_006815c0())
                {
                    CleanExtra* extraScope12 = *nodeScope11->FUN_006815c0();
                    if (extraScope12 && extraScope12->FUN_00418800())
                    {
                        CleanNode* nextScope13 = nodeScope11->FUN_00726070();
                        while (nextScope13 && *nextScope13->FUN_006815c0())
                        {
                            CleanExtra* otherScope14 = *nextScope13->FUN_006815c0();
                            if (extraScope12 == otherScope14)
                            {
                                nextScope13->FUN_0063f7b0();
                                CleanExtra* copyScope15 = new CleanExtra;
                                copyScope15->FUN_00419ed0(extraScope12->FUN_00418800());
                                copyScope15->FUN_00419f80(copyScope15->FUN_00418800()->FUN_005abf60());
                                CleanRef* refScope3 = new CleanRef;
                                refScope3->FUN_00484490();
                                extraScope12->FUN_00418800()->FUN_005ac1e0(refScope3, copyScope15->FUN_00418830(), 0,
                                                                           0);
                                nextScope13->FUN_00905820(&copyScope15);
                                nextScope13 = nodeScope11->FUN_00726070();
                            }
                            else
                                nextScope13 = nextScope13->FUN_00726070();
                        }
                    }
                    nodeScope11 = nodeScope11->FUN_00726070();
                }
            }

            CleanScript* scriptScope17 = FUN_004826d0(formScope7);
            if (!itemScope4Local28 && scriptScope17)
                FUN_004d1960();
            else if (itemScope4Local28 && itemScope4Local28->count >= 0 && scriptScope17)
            {

                CleanNode* nodeScope18 = itemScope4Local28->head;
                if (!nodeScope18 || nodeScope18->FUN_008256d0())
                    FUN_004d1960();
                else
                {
                    int missingScope19 = itemScope4Local28->FUN_00726070() - nodeScope18->FUN_005ae380();
                    while (nodeScope18 && *nodeScope18->FUN_006815c0())
                    {
                        CleanExtra* extraScope20 = *nodeScope18->FUN_006815c0();
                        if (extraScope20 && !extraScope20->FUN_00418800())
                        {
                            extraScope20->FUN_00419ed0(scriptScope17);
                            extraScope20->FUN_00419f80(extraScope20->FUN_00418800()->FUN_005abf60());
                            CleanRef* refScope21 = new CleanRef;
                            refScope21->FUN_00484490();
                            itemScope4Local28->FUN_004bde40()->FUN_005ac1e0(refScope21, extraScope20->FUN_00418830(), 0,
                                                                            0);
                            delete refScope21;
                        }
                        nodeScope18 = nodeScope18->FUN_00726070();
                    }
                    nodeScope18 = itemScope4Local28->head;
                    for (int iScope22 = 0; iScope22 < missingScope19; ++iScope22)
                    {
                        CleanExtra* extraScope23 = new CleanExtra;
                        extraScope23->FUN_00419ed0(itemScope4Local28->FUN_004bde40());
                        extraScope23->FUN_00419f80(extraScope23->FUN_00418800()->FUN_005abf60());
                        CleanRef* refScope3 = new CleanRef;
                        refScope3->FUN_00484490();
                        scriptScope17->FUN_005ac1e0(refScope3, extraScope23->FUN_00418830(), 0, 0);
                        delete refScope3;
                        nodeScope18->FUN_005ae3d0(&extraScope23);
                    }
                }
            }
            if (itemScope4Local28 && reinterpret_cast<CleanFormView*>(formScope7)->FUN_00401170() == 41)
            {
                CleanExtra* wornScope25 = 0;

                if (owner == inventoryPlayer)
                {
                    CleanNode* nodeScope26 = itemScope4Local28->FUN_00559450();
                    while (nodeScope26 && *nodeScope26->FUN_006815c0())
                    {
                        wornScope25 = *nodeScope26->FUN_006815c0();
                        nodeScope26 = nodeScope26->FUN_00726070();
                        wornScope25->FUN_0041aed0();
                    }
                }

                if (itemScope4Local28->FUN_004bddd0(false) && !itemScope4Local28->FUN_004bcb70())
                {
                    if (itemScope4Local28->count > 0 &&
                        itemScope4Local28->count >= (*baseScope8->FUN_006815c0())->count)
                        itemScope4Local28->count = 0;
                }
                else if (itemScope4Local28->FUN_004bddd0(false) && itemScope4Local28->FUN_004bcb70())
                {
                    if (itemScope4Local28->count < 0)
                        itemScope4Local28->SetExtraListFlag(0, 0, true);
                    int countScope27 = itemScope4Local28->CountAndPruneEntries();
                    if (countScope27 > 1)
                    {
                        CleanNode* nodeScope28 = itemScope4Local28->FUN_00559450();
                        while (nodeScope28 && *nodeScope28->FUN_006815c0())
                        {
                            CleanExtra* extraScope29 = *nodeScope28->FUN_006815c0();
                            nodeScope28 = nodeScope28->FUN_00726070();
                            if (extraScope29 && extraScope29->FUN_00418ab0(false) && !wornScope25)
                                wornScope25 = extraScope29;
                            else if (wornScope25)
                            {
                                wornScope25->RemoveAll(true);
                                wornScope25->DuplicateExtraListForContainer(extraScope29);
                                wornScope25->SetWornState(true, false);
                                itemScope4Local28->FUN_00559450()->FUN_00470470();
                                itemScope4Local28->FUN_00559450()->FUN_005ae3d0(&wornScope25);
                            }
                        }
                    }
                    if (itemScope4Local28->count < itemScope4Local28->FUN_004bc8f0(false))
                        itemScope4Local28->count = itemScope4Local28->FUN_004bc8f0(false);
                }
                else if (itemScope4Local28->FUN_004bddd0(false))
                {
                    if (itemScope4Local28->count < itemScope4Local28->FUN_004bc8f0(false))
                        itemScope4Local28->count = itemScope4Local28->FUN_004bc8f0(false);
                    else if (itemScope4Local28->count > itemScope4Local28->FUN_004bc8f0(false))
                    {
                        CleanNode* nodeScope30 = itemScope4Local28->FUN_00559450();
                        while (nodeScope30 && *nodeScope30->FUN_006815c0())
                        {
                            CleanExtra* extraScope31 = *nodeScope30->FUN_006815c0();
                            nodeScope30 = nodeScope30->FUN_00726070();
                            if (extraScope31 && extraScope31->FUN_00418ab0(false))
                                extraScope31->FUN_00419ad0((unsigned short)itemScope4Local28->count);
                        }
                    }
                }
            }
            int totalScope32 = 0;
            int baseCountScope33 = (*baseScope8->FUN_006815c0())->count;
            if (baseCountScope33 < 0)
                baseCountScope33 *= -1;
            if (itemScope4Local28)
                totalScope32 += itemScope4Local28->FUN_00726070() + baseCountScope33;
            else
                totalScope32 += baseCountScope33;
            if (totalScope32 > 0 && itemScope4Local28 && itemScope4Local28->FUN_00559450() &&
                itemScope4Local28->FUN_00559450()->FUN_005ae380())
            {
                CleanNode* nodeScope34 = itemScope4Local28->FUN_00559450();

                while (totalScope32 < nodeScope34->FUN_005ae380())
                {
                    CleanExtra* extraScope35 = *nodeScope34->FUN_006815c0();
                    nodeScope34->FUN_0063f7b0();
                    if (extraScope35)
                    {
                        CleanExtra* destinationScope36 = *nodeScope34->FUN_006815c0();
                        if (destinationScope36)
                        {
                            CleanDatum* dataScope37 = extraScope35->FUN_00726070();
                            while (dataScope37)
                            {
                                if (destinationScope36->GetExtraData(dataScope37->FUN_004f1540()))
                                {
                                    extraScope35->RemoveExtra(dataScope37, true);
                                    dataScope37 = extraScope35->FUN_00726070();
                                }
                                else
                                {
                                    extraScope35->RemoveExtra(dataScope37, false);
                                    destinationScope36->AddExtra(dataScope37);
                                    dataScope37 = extraScope35->FUN_00726070();
                                }
                            }
                        }
                        delete extraScope35;
                    }
                }
                if (nodeScope34->FUN_008256d0())
                {
                    delete itemScope4Local28->head;
                    itemScope4Local28->head = 0;
                }
                else
                    nodeScope34 = itemScope4Local28->FUN_00559450();

                if (nodeScope34 && *nodeScope34->FUN_006815c0())
                {

                    while (nodeScope34 && *nodeScope34->FUN_006815c0())
                    {
                        CleanExtra* extraScope38 = *nodeScope34->FUN_006815c0();
                        if (extraScope38->ItemsInList() < 1)
                        {
                            nodeScope34->FUN_0063f7b0();
                            extraScope38 = 0;
                            if (itemScope4Local28->head->FUN_008256d0())
                            {
                                nodeScope34->FUN_00470470();
                                delete nodeScope34;
                                nodeScope34 = 0;
                                itemScope4Local28->head = 0;
                            }
                            else
                                nodeScope34 = itemScope4Local28->FUN_00559450();
                        }
                        else
                            nodeScope34 = nodeScope34->FUN_00726070();
                    }
                }
            }
        }
        baseScope8 = baseScope8->FUN_00726070();
    }
    CleanItem* itemScope39 = 0;
    CleanItemNode* changeScope4 = head;
    while (changeScope4 && !changeScope4->FUN_008256d0())
    {
        itemScope39 = *changeScope4->FUN_006815c0();
        int baseCountScope41 = 0;
        if (FUN_004bffb0() && itemScope39)
            baseCountScope41 = FUN_004bffb0()->FUN_00482a90(itemScope39->form);
        int totalScope8 = itemScope39->FUN_00726070() + baseCountScope41;

        if (itemScope39)
        {
            TESHealthForm* healthScope43 = dynamic_cast<TESHealthForm*>(itemScope39->FUN_0044ddc0());
            if (healthScope43 && itemScope39->head)
            {
                CleanNode* nodeScope44 = itemScope39->head;
                while (nodeScope44 && *nodeScope44->FUN_006815c0())
                {
                    CleanExtra* extraScope45 = *nodeScope44->FUN_006815c0();
                    if (extraScope45->FUN_004186f0() > -1.0 &&
                        extraScope45->FUN_004186f0() == healthScope43->GetHealth())
                    {
                        extraScope45->FUN_0041aef0();
                        int countScope46 = extraScope45->FUN_00418770();
                        extraScope45->RemoveExtra24();
                        if (extraScope45->FUN_004bca60())
                        {
                            nodeScope44->FUN_00905330(&extraScope45);
                            delete extraScope45;
                            nodeScope44 = itemScope39->head;
                        }
                        else
                        {
                            extraScope45->FUN_00419ad0((unsigned short)countScope46);
                            nodeScope44 = nodeScope44->FUN_00726070();
                        }
                    }
                    else
                        nodeScope44 = nodeScope44->FUN_00726070();
                }
            }
        }

        int equippedCountScope2 = itemScope39->FUN_004bc8f0(false);
        formScope7 = itemScope39->FUN_0044ddc0();

        if (itemScope39 && itemScope39->FUN_004bde40())
        {
            CleanNode* nodeScope48 = itemScope39->head;
            while (nodeScope48 && *nodeScope48->FUN_006815c0())
            {
                CleanExtra* extraScope49 = *nodeScope48->FUN_006815c0();
                if (extraScope49 && extraScope49->FUN_00418800())
                {
                    CleanNode* nextScope50 = nodeScope48->FUN_00726070();
                    while (nextScope50 && *nextScope50->FUN_006815c0())
                    {
                        CleanExtra* otherScope51 = *nextScope50->FUN_006815c0();
                        if (extraScope49 == otherScope51)
                        {
                            nextScope50->FUN_0063f7b0();
                            CleanExtra* copyScope52 = new CleanExtra;
                            copyScope52->FUN_00419ed0(extraScope49->FUN_00418800());
                            copyScope52->FUN_00419f80(copyScope52->FUN_00418800()->FUN_005abf60());
                            CleanRef* refScope6 = new CleanRef;
                            refScope6->FUN_00484490();
                            extraScope49->FUN_00418800()->FUN_005ac1e0(refScope6, copyScope52->FUN_00418830(), 0, 0);
                            nextScope50->FUN_00905820(&copyScope52);
                            nextScope50 = nodeScope48->FUN_00726070();
                        }
                        else
                            nextScope50 = nextScope50->FUN_00726070();
                    }
                }
                nodeScope48 = nodeScope48->FUN_00726070();
            }
        }

        if (itemScope39 && itemScope39->count >= 0)
        {
            CleanScript* scriptScope54 = FUN_004826d0(itemScope39->FUN_0044ddc0());
            if (scriptScope54)
            {

                CleanNode* nodeScope55 = itemScope39->head;
                if (!nodeScope55 || nodeScope55->FUN_008256d0())
                    FUN_004d1960();
                else
                {
                    int missingScope56 = itemScope39->FUN_00726070() - nodeScope55->FUN_005ae380();
                    while (nodeScope55 && *nodeScope55->FUN_006815c0())
                    {
                        CleanExtra* extraScope57 = *nodeScope55->FUN_006815c0();
                        if (extraScope57 && !extraScope57->FUN_00418800())
                        {
                            extraScope57->FUN_00419ed0(scriptScope54);
                            extraScope57->FUN_00419f80(extraScope57->FUN_00418800()->FUN_005abf60());
                            CleanRef* refScope58 = new CleanRef;
                            refScope58->FUN_00484490();
                            itemScope39->FUN_004bde40()->FUN_005ac1e0(refScope58, extraScope57->FUN_00418830(), 0, 0);
                        }
                        nodeScope55 = nodeScope55->FUN_00726070();
                    }
                    nodeScope55 = itemScope39->head;
                    for (int iScope59 = 0; iScope59 < missingScope56; ++iScope59)
                    {
                        CleanExtra* extraScope60 = new CleanExtra;
                        extraScope60->FUN_00419ed0(itemScope39->FUN_004bde40());
                        extraScope60->FUN_00419f80(extraScope60->FUN_00418800()->FUN_005abf60());
                        CleanRef* refScope61 = new CleanRef;
                        refScope61->FUN_00484490();
                        scriptScope54->FUN_005ac1e0(refScope61, extraScope60->FUN_00418830(), 0, 0);
                        delete refScope61;
                        nodeScope55->FUN_005ae3d0(&extraScope60);
                    }
                }
            }
        }
        if (itemScope39 && reinterpret_cast<CleanFormView*>(formScope7)->FUN_00401170() == 41)
        {
            int baseCountScope62 = 0;
            if (FUN_004bffb0() && itemScope39)
                baseCountScope62 = FUN_004bffb0()->FUN_00482a90(itemScope39->form);
            CleanExtra* wornScope5 = 0;

            if (owner == inventoryPlayer)
            {
                CleanNode* nodeScope64 = itemScope39->FUN_00559450();
                while (nodeScope64 && *nodeScope64->FUN_006815c0())
                {
                    wornScope5 = *nodeScope64->FUN_006815c0();
                    nodeScope64 = nodeScope64->FUN_00726070();
                    wornScope5->FUN_0041aed0();
                }
            }

            if (itemScope39->FUN_004bddd0(false))
            {
                CleanNode* nodeScope65 = itemScope39->FUN_00559450();
                int sumScope66 = 0;
                while (nodeScope65 && *nodeScope65->FUN_006815c0())
                {
                    CleanExtra* extraScope67 = *nodeScope65->FUN_006815c0();
                    sumScope66 += extraScope67->FUN_00418770();
                    nodeScope65 = nodeScope65->FUN_00726070();
                }
                if (itemScope39->count + baseCountScope62 < sumScope66)
                    itemScope39->count = sumScope66 - (itemScope39->count + baseCountScope62);
                else if (itemScope39->count + baseCountScope62 > sumScope66)
                {
                    CleanNode* nodeScope68 = itemScope39->FUN_00559450();
                    while (nodeScope68 && *nodeScope68->FUN_006815c0())
                    {
                        CleanExtra* extraScope69 = *nodeScope68->FUN_006815c0();
                        nodeScope68 = nodeScope68->FUN_00726070();
                        if (extraScope69 && extraScope69->FUN_00418ab0(false))
                            extraScope69->FUN_00419ad0((unsigned short)itemScope39->count);
                    }
                }
            }
        }
        if (itemScope39 && itemScope39->head)
        {
            CleanNode* nodeScope70 = itemScope39->head;
            while (nodeScope70 && *nodeScope70->FUN_006815c0())
            {
                CleanExtra* extraScope71 = *nodeScope70->FUN_006815c0();
                if (extraScope71 && extraScope71->FUN_00418800())
                    extraScope71->RemoveExtra24();
                nodeScope70 = nodeScope70->FUN_00726070();
            }
        }

        if (itemScope39 && FUN_00481f10(formScope7) && owner == inventoryPlayer && itemScope39->head)
        {
            CleanNode* nodeScope72 = itemScope39->head;
            while (nodeScope72 && *nodeScope72->FUN_006815c0())
            {
                CleanExtra* extraScope73 = *nodeScope72->FUN_006815c0();
                nodeScope72->FUN_0063f7b0();
                delete extraScope73;
            }
        }

        if (itemScope39 && totalScope8 < equippedCountScope2 && itemScope39->head)
        {
            int sumScope74 = 0;
            CleanNode* nodeScope75 = itemScope39->head;
            while (nodeScope75 && *nodeScope75->FUN_006815c0())
            {
                CleanExtra* extraScope76 = *nodeScope75->FUN_006815c0();
                sumScope74 += extraScope76->FUN_00418770();
                nodeScope75 = nodeScope75->FUN_00726070();
            }
            itemScope39->count = sumScope74;
        }
        if (itemScope39 && totalScope8 > 0)
        {
            CleanNode* nodeScope77 = itemScope39->FUN_00559450();
            if (nodeScope77 && *nodeScope77->FUN_006815c0())
            {

                while (totalScope8 < nodeScope77->FUN_005ae380())
                {
                    CleanExtra* extraScope78 = *nodeScope77->FUN_006815c0();
                    nodeScope77->FUN_0063f7b0();
                    if (extraScope78)
                    {
                        CleanExtra* destinationScope79 = *nodeScope77->FUN_006815c0();
                        if (destinationScope79)
                        {
                            CleanDatum* dataScope80 = extraScope78->FUN_00726070();
                            while (dataScope80)
                            {
                                if (destinationScope79->GetExtraData(dataScope80->FUN_004f1540()))
                                {
                                    extraScope78->RemoveExtra(dataScope80, true);
                                    dataScope80 = extraScope78->FUN_00726070();
                                }
                                else
                                {
                                    extraScope78->RemoveExtra(dataScope80, false);
                                    destinationScope79->AddExtra(dataScope80);
                                    dataScope80 = extraScope78->FUN_00726070();
                                }
                            }
                        }
                        delete extraScope78;
                    }
                }
                if (nodeScope77->FUN_008256d0())
                {
                    delete itemScope39->head;
                    itemScope39->head = 0;
                }
                else
                    nodeScope77 = itemScope39->FUN_00559450();

                while (nodeScope77 && *nodeScope77->FUN_006815c0())
                {
                    CleanExtra* extraScope81 = *nodeScope77->FUN_006815c0();
                    if (extraScope81->ItemsInList() < 1)
                    {
                        nodeScope77->FUN_0063f7b0();
                        extraScope81 = 0;
                        if (itemScope39->head->FUN_008256d0())
                        {
                            nodeScope77->FUN_00470470();
                            delete nodeScope77;
                            nodeScope77 = 0;
                            itemScope39->head = 0;
                        }
                        else
                            nodeScope77 = itemScope39->FUN_00559450();
                    }
                    else
                        nodeScope77 = nodeScope77->FUN_00726070();
                }
            }
        }
        changeScope4 = changeScope4->FUN_00726070();
    }
}

struct ExtraHealth;

struct SimpleListNode
{
    void*& FUN_006815c0();
    SimpleListNode* FUN_00726070();
    bool FUN_008256d0();
};

struct TESObjectARMO : public TESBoundObject
{
    float GetArmorRating();
    float GetDamageThreshold();
};

struct ArmorContainerList004c8220
{
    SimpleListNode* FUN_00717e50();
};

struct FUN_00480af0_shell
{
    bool FUN_00480af0(int, bool, void*);
};
struct FUN_004186f0_shell
{
    float FUN_004186f0();
};
struct FUN_00418b10_shell
{
    bool FUN_00418b10();
};
struct FUN_00559450_shell
{
    SimpleListNode* FUN_00559450();
};
struct FUN_004c8c10_shell
{
    InventoryStackRecord* FUN_004c8c10(int, bool);
};
struct G2
{
    void AddHead(ExtraDataList*&);
};

unsigned int __cdecl FUN_004873d0(TESObjectARMO*);

struct FUN_004c8220_shell : public InventoryChanges
{
    InventoryStackRecord* FUN_004c8220(TESActorBase*, int, bool);
};

// Finds the armor piece with the highest effective rating for a body slot, considering extra health and inventory changes.
// @fnv 0x004c8220
InventoryStackRecord* FUN_004c8220_shell::FUN_004c8220(TESActorBase* apActorBase, int aeBodySlot, bool abUseCanNotWear)
{
    float fHighDesire;
    TESObjectARMO* volatile pBest;
    AutoMemContext tempMemContext((MEM_CONTEXT)54, true, g_inventoryChangesSourceFilename, 5694);
    InventoryStackRecord* pchange;
    SimpleListNode* pListInv;
    SimpleListNode* pList;

    fHighDesire = DAT_01015f5c;
    pBest = 0;
    pchange = 0;
    if (abUseCanNotWear)
    {
        InventoryStackRecord* pitem = ((FUN_004c8c10_shell*)this)->FUN_004c8c10(aeBodySlot, false);
        if (pitem &&
            ((FUN_00418b10_shell*)((FUN_00559450_shell*)pitem)->FUN_00559450()->FUN_006815c0())->FUN_00418b10())
            return pitem;
        else
            delete pitem;
    }

    pList = ((ArmorContainerList004c8220*)((FUN_004bffb0_shell*)this)->FUN_004bffb0())->FUN_00717e50();
    while (pList && !pList->FUN_008256d0())
    {
        TESObjectARMO* pObj = dynamic_cast<TESObjectARMO*>(((InventoryItemEntry*)pList->FUN_006815c0())->pObj);
        InventoryStackRecord* pitem = ((FUN_004bfba0_shell*)this)->FUN_004bfba0(pObj, true, false);
        if ((!pitem ||
             (pitem && pitem->m_iCountChange + ((InventoryItemEntry*)pList->FUN_006815c0())->m_iCountDelta > 0) ||
             ((InventoryItemEntry*)pList->FUN_006815c0())->m_iCountDelta < 0) &&
            pObj && aeBodySlot != -1 && ((FUN_00480af0_shell*)((char*)pObj + 0x70))->FUN_00480af0(aeBodySlot, false, 0))
        {
            float fDesire = -1.0f;
            if (pitem && pitem->m_pExtraDataLists && ((SimpleListNode*)pitem->m_pExtraDataLists)->FUN_006815c0())
            {
                SimpleListNode* pextralist = (SimpleListNode*)pitem->m_pExtraDataLists;
                while (pextralist && pextralist->FUN_006815c0())
                {
                    ExtraDataList* pcurextra = (ExtraDataList*)pextralist->FUN_006815c0();
                    ExtraHealth* pHealth = (ExtraHealth*)pcurextra->GetExtraData(0x25);
                    float fhealth = 0.0f;
                    if (pHealth)
                        fhealth = ((FUN_004186f0_shell*)pcurextra)->FUN_004186f0();
                    else
                        fhealth = FUN_004873d0(pObj);
                    if (fhealth > 0.0)
                    {
                        float frating = FUN_00646360(pObj->GetArmorRating(), fhealth);
                        fDesire = pObj->GetDamageThreshold() + frating;
                        if (fDesire > fHighDesire)
                        {
                            fHighDesire = fDesire;
                            pBest = pObj;
                            delete pchange;
                            pchange = new InventoryStackRecord;
                            pchange->m_pItemObject = pObj;
                            pchange->m_pExtraDataLists = (BSSimpleList<ExtraDataList*>*)new SL;
                            ((G2*)pchange->m_pExtraDataLists)->AddHead(pcurextra);
                        }
                    }
                    pextralist = pextralist->FUN_00726070();
                }
            }
            else
            {
                float fhealth = FUN_004873d0(pObj);
                float frating = FUN_00646360(pObj->GetArmorRating(), fhealth);
                fDesire = pObj->GetDamageThreshold() + frating;
                if (fDesire > fHighDesire)
                {
                    fHighDesire = fDesire;
                    pBest = pObj;
                    delete pchange;
                    pchange = new InventoryStackRecord;
                    pchange->m_pItemObject = pObj;
                }
            }
        }
        pList = pList->FUN_00726070();
    }

    pListInv = (SimpleListNode*)((InventoryChanges*)this)->m_pEntryList;
    while (pListInv && !pListInv->FUN_008256d0())
    {
        TESObjectARMO* pObj = dynamic_cast<TESObjectARMO*>(((InventoryStackRecord*)pListInv->FUN_006815c0())->m_pItemObject);
        InventoryStackRecord* pitem = (InventoryStackRecord*)pListInv->FUN_006815c0();
        if (pObj && ((FUN_00726070_shell*)pitem)->FUN_00726070() &&
            !((FUN_004bffb0_shell*)this)->FUN_004bffb0()->HasObjectOfType((TESObject*)pObj) && aeBodySlot != -1 &&
            ((FUN_00480af0_shell*)((char*)pObj + 0x70))->FUN_00480af0(aeBodySlot, false, 0) &&
            pitem->m_iCountChange >= 0)
        {
            float fDesire = -1.0f;
            if (pitem && pitem->m_pExtraDataLists && ((SimpleListNode*)pitem->m_pExtraDataLists)->FUN_006815c0())
            {
                SimpleListNode* pextralist = (SimpleListNode*)pitem->m_pExtraDataLists;
                while (pextralist && pextralist->FUN_006815c0())
                {
                    ExtraDataList* pcurextra = (ExtraDataList*)pextralist->FUN_006815c0();
                    ExtraHealth* pHealth = (ExtraHealth*)pcurextra->GetExtraData(0x25);
                    float fhealth = 0.0f;
                    if (pHealth)
                        fhealth = ((FUN_004186f0_shell*)pcurextra)->FUN_004186f0();
                    else
                        fhealth = FUN_004873d0(pObj);
                    if (fhealth > 0.0)
                    {
                        float frating = FUN_00646360(pObj->GetArmorRating(), fhealth);
                        fDesire = pObj->GetDamageThreshold() + frating;
                        if (fDesire > fHighDesire)
                        {
                            fHighDesire = fDesire;
                            pBest = pObj;
                            delete pchange;
                            pchange = new InventoryStackRecord;
                            pchange->m_pItemObject = pObj;
                            pchange->m_pExtraDataLists = (BSSimpleList<ExtraDataList*>*)new SL;
                            ((G2*)pchange->m_pExtraDataLists)->AddHead(pcurextra);
                        }
                    }
                    pextralist = pextralist->FUN_00726070();
                }
            }
            else
            {
                float fhealth = FUN_004873d0(pObj);
                float frating = FUN_00646360(pObj->GetArmorRating(), fhealth);
                fDesire = pObj->GetDamageThreshold() + frating;
                if (fDesire > fHighDesire)
                {
                    fHighDesire = fDesire;
                    pBest = pObj;
                    delete pchange;
                    pchange = new InventoryStackRecord;
                    pchange->m_pItemObject = pObj;
                }
            }
        }
        pListInv = pListInv->FUN_00726070();
    }
    return pchange;
}

class ScriptLocals;

class Script
{
  public:
    static bool HandleScriptLocals(TESObjectREFR*, void*, void*, double&);
};

const char* FUN_00482720(TESForm*);
int __fastcall FNV_GetFormType(TESForm*);
void FUN_00704af0();

bool ExtractArgs(const ScriptParameter*, const char*, unsigned int*, TESObjectREFR*, TESObjectREFR*, Script*,
                 ScriptLocals*, ...);

bool QueueUIMessage(const char*, int, const char*, const char*, float, bool);

struct W20Ref;
extern W20Ref* g_thePlayer;
extern const char DAT_01012058[];
extern const char g_011cba4c_arg1[];
extern StartMenu g_011d3114;
extern StartMenu g_011d3db4;

struct BSString
{
    char* pString;
    unsigned short sLen;
    unsigned short sMaxLen;

    BSString();
    ~BSString();
    int PrintfString(const char*, ...);
    operator const char*() const;
};

template <class T> struct SimpleList
{
    T m_item;
    SimpleList<T>* m_pkNext;

    SimpleList();
    ~SimpleList();
    T& GetItem();
    SimpleList<T>* GetNext();
    bool IsEmpty();
    void AddHead(const T& item);
    void RemoveHead();
};

struct ListForm_5b4e90
{
    SimpleList<TESForm*>* FUN_00500940();
};

struct EquippedActor_5b4e90 : public ::Actor
{
    bool FUN_00575400(TESBoundObject*);
};

struct Target_5b4e90 : public ::MagicTarget
{
    void FUN_008248e0(TESBoundObject*, bool);
};

struct Player_5b4e90
{
    const char* FUN_008adcf0(TESBoundObject*, int, int);
};

struct InventoryLeveled_5b4e90 : public ::InventoryChanges
{
    ::TESBoundObject* FUN_004cba70(::TESLevItem*);
};

struct InventoryExtra_5b4e90 : public ::InventoryChanges
{
    ::ExtraDataList* FUN_004bfda0(::TESBoundObject*, int);
};

struct ExtraFlag_5b4e90 : public ::ExtraDataList
{
    void FUN_0041ab70(bool);
};

// Processes pRemoveForm or eligible list entries, removing up to iCount per item and handling equipment and player messages.
// @fnv 0x005b4e90
bool FUN_005b4e90(ScriptParameter* paramInfo, char* scriptData, TESObjectREFR* thisObj, TESObjectREFR* containingObj,
                  Script* scriptObj, ScriptLocals* eventList, double* result, unsigned int* opcodeOffsetPtr)
{
    TESForm* pRemoveForm = 0;
    TESBoundObject* pObject = 0;
    int iCount = 0;
    int iNoMessage = 0;

    if (!ExtractArgs(paramInfo, scriptData, opcodeOffsetPtr, thisObj, containingObj, scriptObj, eventList, &pRemoveForm,
                     &iCount, &iNoMessage))
        return false;

    if (thisObj && pRemoveForm)
    {
        SimpleList<TESForm*> itemList;
        if (pRemoveForm->IsActor_InEditor())
            pObject = (TESBoundObject*)pRemoveForm;
        if (::FNV_GetFormType(pRemoveForm) == 0x34)
        {
            TESLevItem* pLevItem = (TESLevItem*)pRemoveForm;
            if (pLevItem)
            {
                InventoryChanges* pInventoryChanges = thisObj->GetExtraData()->GetContainerChangeData();
                if (pInventoryChanges)
                    pObject = static_cast<InventoryLeveled_5b4e90*>(pInventoryChanges)->FUN_004cba70(pLevItem);
            }
        }
        if (pObject)
        {
            itemList.AddHead((TESForm*)pObject);
        }
        else if (::FNV_GetFormType(pRemoveForm) == 0x55)
        {
            ListForm_5b4e90* pListForm = (ListForm_5b4e90*)pRemoveForm;
            SimpleList<TESForm*>* pNode = pListForm->FUN_00500940();
            while (pNode && !pNode->IsEmpty())
            {
                TESForm* pListItem = pNode->GetItem();
                pNode = pNode->GetNext();
                if (pListItem->IsActor_InEditor())
                    itemList.AddHead(pListItem);
            }
        }

        while (!itemList.IsEmpty())
        {
            pObject = (TESBoundObject*)itemList.GetItem();
            itemList.RemoveHead();
            int iRemove = iCount;
            ::Actor* pActor = dynamic_cast< ::Actor*>(thisObj);
            if (pActor)
            {
                {
                    double dCount = iRemove;
                    Script::HandleScriptLocals(thisObj, pObject, 0, dCount);
                    if (iRemove > dCount)
                        iRemove = (int)dCount;
                }
                ExtraDataList* pExtra = 0;
                if (static_cast<EquippedActor_5b4e90*>(pActor)->FUN_00575400(pObject))
                {
                    InventoryChanges* m_pInventoryChangesValue = InventoryChanges::CreateForReference(thisObj);
                    if (m_pInventoryChangesValue)
                    {
                        pExtra =
                            static_cast<InventoryExtra_5b4e90*>(m_pInventoryChangesValue)->FUN_004bfda0(pObject, 0);
                        if (pExtra)
                            static_cast<ExtraFlag_5b4e90*>(pExtra)->FUN_0041ab70(false);
                    }
                }
                if (iRemove > 0)
                {
                    bool bEquipped = static_cast<EquippedActor_5b4e90*>(pActor)->FUN_00575400(pObject);
                    if (bEquipped)
                        reinterpret_cast<Target_5b4e90*>(reinterpret_cast<char*>(pActor) + 0x94)
                            ->FUN_008248e0(pObject, true);
                    pActor->RemoveItem((TESForm*)pObject, pExtra, iRemove, 0, 0, 0, 0, 0, 1, 0);
                    if (pActor == reinterpret_cast< ::Actor*>(::g_thePlayer))
                    {
                        if (!iNoMessage)
                        {
                            BSString sMessage;
                            if (iRemove > 1)
                                sMessage.PrintfString("%i %s%s %s", iRemove, ::FUN_00482720((TESForm*)pObject),
                                                 g_011d3114.GetMenuTitle(), g_011d3db4.GetMenuTitle());
                            else
                                sMessage.PrintfString(DAT_01012058, ::FUN_00482720((TESForm*)pObject),
                                                 g_011d3db4.GetMenuTitle());
                            switch (::FNV_GetFormType((TESForm*)pObject))
                            {
                            case 0x19:
                            case 0x1e:
                            case 0x1f:
                            case 0x28:
                            case 0x29:
                            case 0x2e:
                            case 0x2f:
                            case 0x32:
                            case 0x67:
                            case 0x6c:
                            case 0x73:
                            case 0x74:
                                QueueUIMessage(
                                    sMessage, 0, g_011cba4c_arg1,
                                    iNoMessage
                                        ? 0
                                        : reinterpret_cast<Player_5b4e90*>(::g_thePlayer)->FUN_008adcf0(pObject, 0, 0),
                                    2.0f, false);
                                break;
                            case 0x18:
                                QueueUIMessage(
                                    sMessage, 0, g_011cba4c_arg1,
                                    iNoMessage
                                        ? 0
                                        : reinterpret_cast<Player_5b4e90*>(::g_thePlayer)->FUN_008adcf0(pObject, 0, 0),
                                    2.0f, false);
                                break;
                            }
                        }
                        ::FUN_00704af0();
                    }
                    else if (bEquipped && pActor->GetProcess() && pActor->GetNiNode())
                    {
                        pActor->GetProcess()->SelectPackage(pActor, false);
                    }
                }
            }
            else
            {
                thisObj->RemoveItem((TESForm*)pObject, 0, iRemove, 0, 0, 0, 0, 0, 1, 0);
            }
        }
    }
    return true;
}

namespace fnv_004be6f0 {
struct SaveRecord
{
    unsigned int formID;
    char kind;
    char flags;
};
struct SaveStream
{
    unsigned int Position();
    bool IsBlock();
    void Write(void*, int);
    void WriteID(void*, int);
    SaveRecord* CurrentRecord();
};
extern SaveStream* g_TESSaveLoadGame;
struct DebugSetting
{
    bool* Bool();
};
extern DebugSetting g_011de4e8;
struct SavedItem
{
    void Save(int, int);
};
struct SavedNode
{
    bool Empty();
    SavedItem** Item();
    SavedNode* Next();
};
struct SavedOwner
{
    unsigned int ID();
};
struct SavedForm
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
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
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
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
    virtual const char* Name();
};
SavedForm* __cdecl LookupSavedForm(unsigned int);
void __cdecl SaveLog(const char*, ...);
void __cdecl SaveWarning(const char*, ...);
extern const char g_inventoryChangesSourceFilename[];
struct SaveInventory
{
    SavedNode* changes;
    unsigned int owner;
    SavedOwner* container;
    void FUN_004be6f0();
};
// Writes the inventory owner, container, and item changes to the save stream, patching the block size and count fields.
// @fnv 0x004be6f0
void SaveInventory::FUN_004be6f0()
{
    unsigned short blockSize_ = 0;
    unsigned int blockStart6 = 0;
    unsigned int start2 = g_TESSaveLoadGame->Position();
    if (*g_011de4e8.Bool())
        start2 = g_TESSaveLoadGame->Position();
    if (g_TESSaveLoadGame->IsBlock())
    {
        unsigned int tag5 = 0x424c4f4b;
        g_TESSaveLoadGame->Write(&tag5, 4);
        blockStart6 = g_TESSaveLoadGame->Position();
        g_TESSaveLoadGame->Write(&blockSize_, 2);
    }
    unsigned int ownerID5 = container->ID();
    g_TESSaveLoadGame->WriteID(&ownerID5, 4);
    g_TESSaveLoadGame->Write(&owner, 4);
    unsigned int count4 = 0;
    unsigned int* countPos_ = (unsigned int*)g_TESSaveLoadGame->Position();
    g_TESSaveLoadGame->Write(&count4, 4);
    SavedNode* nodeB = changes;
    while (nodeB && !nodeB->Empty())
    {
        SavedItem* itemB = *nodeB->Item();
        itemB->Save(0, 0);
        count4++;
        nodeB = nodeB->Next();
    }
    *countPos_ = count4;
    if (*g_011de4e8.Bool())
    {
        unsigned int end_2 = g_TESSaveLoadGame->Position();
        SaveRecord* record_ = g_TESSaveLoadGame->CurrentRecord();
        if (record_)
        {
            SavedForm* kForm = LookupSavedForm(record_->formID);
            SaveLog("SaveGame(): %-5i for form %08X %s with flags %08X ending at line %i in file %s", end_2 - start2,
                    record_->formID, kForm->Name(), *(unsigned int*)&record_->flags, 0x641,
                    g_inventoryChangesSourceFilename);
        }
        else
        {
            SaveLog("SaveGame(): %-5i ending at line %i in file %s", end_2 - start2, 0x641,
                    g_inventoryChangesSourceFilename);
        }
    }
    if (g_TESSaveLoadGame->IsBlock())
    {
        unsigned int endBlock5 = g_TESSaveLoadGame->Position();
        unsigned int beginBlock6 = blockStart6;
        if (endBlock5 > beginBlock6 + 0xffff)
            SaveWarning("SAVELOAD: Save Game Block in file %s on line %i is greater than maximum short size",
                        g_inventoryChangesSourceFilename, 0x641);
        *(unsigned short*)blockStart6 = (unsigned short)(endBlock5 - beginBlock6);
    }
}
}  // namespace fnv_004be6f0

void* __cdecl operator new(unsigned int);
struct ExtraSetter_bdb40
{
    void FUN_0042e5a0(int);
};
struct ExtraList_bdb40
{
    FUN_00410360* item;
    ExtraList_bdb40* next;
    ExtraList_bdb40();
    FUN_00410360** FUN_006815c0();
    void FUN_00905330(FUN_00410360**);
};
struct InvEntry_bdb40
{
    ExtraList_bdb40* list;
    void FUN_004bdb40();
};
// Ensures the InvEntry has an ExtraList, then sets flag 1 on its first extra item, creating one if the list is empty.
// @fnv 0x004bdb40
void InvEntry_bdb40::FUN_004bdb40()
{
    ExtraList_bdb40* pExtraList = list;
    if (!pExtraList)
    {
        pExtraList = new ExtraList_bdb40;
        list = pExtraList;
    }
    if (!*pExtraList->FUN_006815c0())
    {
        FUN_00410360* extra = new FUN_00410360;
        reinterpret_cast<ExtraSetter_bdb40*>(extra)->FUN_0042e5a0(1);
        list->FUN_00905330(&extra);
    }
    else if (pExtraList && *pExtraList->FUN_006815c0())
    {
        FUN_00410360* result = *pExtraList->FUN_006815c0();
        if (result)
            reinterpret_cast<ExtraSetter_bdb40*>(result)->FUN_0042e5a0(1);
    }
}

struct ItemChangeValueShell : public InventoryStackRecord
{
    float FUN_004bd400();
};

struct ItemHealthCall
{
    float GetConditionPercent(bool);
};
float __cdecl ComputeItemValue(float, float);

// Combines FUN_0048e8a0's result with condition percent, adds values for selected weapon slots, then rounds to 0.1.
// @fnv 0x004bd400
float ItemChangeValueShell::FUN_004bd400()
{
    TESObjectWEAP* pWeap;
    float fConditionValue;
    fConditionValue =
        ComputeItemValue((float)FUN_0048e8a0(m_pItemObject), ((ItemHealthCall*)this)->GetConditionPercent(true));
    pWeap = dynamic_cast<TESObjectWEAP*>((TESBoundObject*)((ArrSI*)this)->GetFlags());
    if (pWeap)
    {
        int iSlotFlags = ((FUN_004bd820_stand*)this)->FUN_004bd820();
        if (iSlotFlags)
        {
            if (iSlotFlags & 1)
                fConditionValue +=
                    ((FUN_00726070_shell*)(((FUN_004bd570_this*)pWeap)->FUN_004bd570(1) + 0x7c))->FUN_00726070();
            if (iSlotFlags & 2)
                fConditionValue +=
                    ((FUN_00726070_shell*)(((FUN_004bd570_this*)pWeap)->FUN_004bd570(2) + 0x7c))->FUN_00726070();
            if (iSlotFlags & 4)
                fConditionValue +=
                    ((FUN_00726070_shell*)(((FUN_004bd570_this*)pWeap)->FUN_004bd570(4) + 0x7c))->FUN_00726070();
        }
    }
    return InventoryStackRecord::RoundToNearestStep(fConditionValue, 0.1f);
}

struct RefIdShell
{
    unsigned int GetFormID();
};
struct FUN_0041c8d0_shell
{
    RefIdShell* GetReplacementReference();
};

// Searches the linked list of changes for an entry matching apObj, optionally filtered by aId via the replacement reference form ID.
// @fnv 0x004bfba0
InventoryStackRecord* FUN_004bfba0_shell::FUN_004bfba0(TESBoundObject* apObj, int ableveled, int aId)
{
    ItemNode* pkCurrentObject = *(ItemNode**)this;
    bool bHasResultObj = true;
    while (pkCurrentObject && bHasResultObj)
    {
        InventoryStackRecord* pchange = *_ref_006815c0(pkCurrentObject);
        if (pchange && pchange->m_pItemObject == apObj)
        {
            bHasResultObj = false;
        }
        else
        {
            pkCurrentObject = _ref_00726070(pkCurrentObject);
        }
    }
    if (pkCurrentObject)
    {
        InventoryStackRecord* pchange = *_ref_006815c0(pkCurrentObject);
        if (pchange && aId)
        {
            ExtraNode* pkCurrentObject = (ExtraNode*)pchange->m_pExtraDataLists;
            while (pkCurrentObject)
            {
                ExtraDataList* pextra = *_ref_006815c0(pkCurrentObject);
                if (pextra && ((FUN_0041c8d0_shell*)pextra)->GetReplacementReference() &&
                    ((FUN_0041c8d0_shell*)pextra)->GetReplacementReference()->GetFormID() == aId)
                    return pchange;
                pkCurrentObject = _ref_00726070(pkCurrentObject);
            }
            return 0;
        }
        else
        {
            return pchange;
        }
    }
    else
    {
        return 0;
    }
}
