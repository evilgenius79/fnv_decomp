// fallout_shared/tescontainer.cpp: TESContainer, InventoryItemEntry, DelStandIn, ContainerOperation and more (31 functions)

#include "tescontainer_decls.h"
#include "BaseFormComponent.h"

class ContainerItemExtra
{
  public:
    void* m_pForm;
    union
    {
        void* m_pGlobal;
        int m_cRank;
        unsigned int bits;
    };
    float m_fHealth;
    ContainerItemExtra();
    void Copy(ContainerItemExtra* other);
    bool IsDefault();
};

class InventoryItemEntry
{
  public:
    int count;
    void* object;
    ContainerItemExtra* extra;
    void Copy(InventoryItemEntry* other);
    void InitItem(TESForm* form);
};

struct ContainerCountState
{
    int count;
    BSSimpleList<InventoryStackRecord*>* list;
};

class TESContainer;

struct CopyComponentState
{
    BSSimpleList<InventoryStackRecord*>* list;
    TESContainer* source;
};

// Copies object, count and, when the source extra is non-default, allocates a new ContainerItemExtra and copies it.
// @fnv 0x00481540
void InventoryItemEntry::Copy(InventoryItemEntry* other)
{
    if (other)
    {
        object = other->object;
        count = other->count;
        if (other->extra && !other->extra->IsDefault())
        {
            extra = new ContainerItemExtra();
            extra->Copy(other->extra);
        }
    }
}

class TESContainer : public BaseFormComponent
{
  public:
    BSSimpleList<InventoryStackRecord*> objectList;
    virtual void Init();
    BSSimpleList<InventoryStackRecord*>* GetObjectList();
    void AddObject(InventoryItemEntry* object);
    void ClearObjects();
    void InitItem(TESForm* form);
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    ~TESContainer();
    bool HasObjectOfType(TESObject* object);
    int GetObjectCount(TESObject* object);
    static bool IsValidContainerType(unsigned char type);
    TESContainer();
};

// Constructs a TESContainer, initializing its objectList and calling Init().
// @fnv 0x00481610
TESContainer::TESContainer() : objectList()
{
    Init();
}

// @fnv 0x004816e0
void TESContainer::Free()
{
    ClearObjects();
}

// @fnv 0x00481680
TESContainer::~TESContainer()
{
    Free();
}

// Copies the object list from the source TESContainer component into this container, adding each item.
// @fnv 0x00481c80
void TESContainer::CopyFromBase(BaseFormComponent* component)
{
    CopyComponentState state;
    state.source = dynamic_cast<TESContainer*>(component);
    if (state.source == 0)
        return;
    ClearObjects();
    state.list = state.source->GetObjectList();
    while (state.list != 0 && !state.list->IsEmpty())
    {
        InventoryItemEntry* item = reinterpret_cast<InventoryItemEntry*>(state.list->GetItem());
        AddObject(item);
        state.list = state.list->GetNext();
    }
}

// Searches the container's object list for an entry whose object pointer equals object and returns whether one is found.
// @fnv 0x00481eb0
bool TESContainer::HasObjectOfType(TESObject* object)
{
    BSSimpleList<InventoryStackRecord*>* list = GetObjectList();
    if (list->GetItem() == 0)
        list = 0;
    while (list != 0)
    {
        InventoryItemEntry* item = reinterpret_cast<InventoryItemEntry*>(list->GetItem());
        if (item->object == object)
            return true;
        list = list->GetNext();
    }
    return false;
}

// Counts how many items in the container's object list match the given object, summing their counts.
// @fnv 0x00482a90
int TESContainer::GetObjectCount(TESObject* object)
{
    ContainerCountState state;
    state.count = 0;
    state.list = GetObjectList();
    while (state.list != 0 && state.list->GetItem() != 0)
    {
        if (reinterpret_cast<InventoryItemEntry*>(state.list->GetItem())->object == object)
            state.count += reinterpret_cast<InventoryItemEntry*>(state.list->GetItem())->count;
        state.list = state.list->GetNext();
    }
    return state.count;
}

// @fnv 0x00481f30
bool TESContainer::IsValidContainerType(unsigned char type)
{
    switch (type)
    {
    case 0x18:
    case 0x19:
    case 0x1a:
    case 0x1d:
    case 0x1e:
    case 0x1f:
    case 0x28:
    case 0x29:
    case 0x2e:
    case 0x2f:
    case 0x31:
    case 0x32:
    case 0x34:
    case 0x67:
    case 0x6c:
    case 0x73:
    case 0x74:
        return true;
    default:
        return false;
    }
}

// @fnv 0x00481700
void TESContainer::ClearObjects()
{
    BSSimpleList<InventoryStackRecord*>* list = GetObjectList();
    InventoryItemEntry* item;
    while ((item = reinterpret_cast<InventoryItemEntry*>(list->GetItem())) != 0)
    {
        InventoryItemEntry* deletion = item;
        InventoryItemEntry* temporary = deletion;
        temporary ? reinterpret_cast<BGSPerkEntry*>(temporary)->Destroy(1) : 0;
        list->RemoveHead();
    }
}
// Initializes each entry in the object list with form, removing and deleting entries whose object becomes null.
// @fnv 0x00481bb0
void TESContainer::InitItem(TESForm* form)
{
    BSSimpleList<InventoryStackRecord*>* list = GetObjectList();
    BSSimpleList<InventoryStackRecord*>* previous = 0;
    while (list != 0 && !list->IsEmpty())
    {
        InventoryItemEntry* item = reinterpret_cast<InventoryItemEntry*>(list->GetItem());
        item->InitItem(form);
        if (item->object == 0)
        {
            if (previous != 0)
            {
                previous->Remove(reinterpret_cast<InventoryStackRecord* const&>(item));
                list = previous->GetNext();
            }
            else
            {
                list->RemoveHead();
            }
            InventoryItemEntry* deletion = item;
            InventoryItemEntry* temporary = deletion;
            temporary ? reinterpret_cast<BGSPerkEntry*>(temporary)->Destroy(1) : 0;
            item = 0;
        }
        else
        {
            previous = list;
            list = list->GetNext();
        }
    }
}

struct ContainerObjectNew : InventoryItemEntry
{
    ContainerObjectNew();
};

struct FUN_00481a90_shell : TESContainer
{
    void AddContainerCopy(InventoryItemEntry* object);
};

// If object is non-null, allocates a ContainerObjectNew, copies object into it, and adds it to the head of the object list.
// @fnv 0x00481a90
void FUN_00481a90_shell::AddContainerCopy(InventoryItemEntry* object)
{
    if (!object)
        return;
    InventoryItemEntry* newObj = new ContainerObjectNew;
    newObj->Copy(object);
    GetObjectList()->AddHead((InventoryStackRecord*&)newObj);
}

struct FUN_00481fd0_shell : public TESContainer
{
    void AddAllFromContainer(TESContainer*);
};

InventoryItemEntry** __fastcall _ref_006815c0(void*);
void* __fastcall _ref_00726070(void*);

struct TeleportableReference
{
    int& GetPosition();
};

class TESContainer_Add : public TESContainer
{
  public:
    void AddObject(TESForm* form, int count, ContainerItemExtra* extra);
};

// Iterates the object list of apAddCont and adds each entry's object, count and extra to this container.
// @fnv 0x00481fd0
void FUN_00481fd0_shell::AddAllFromContainer(TESContainer* apAddCont)
{
    if (apAddCont)
    {
        void* pListEntry = apAddCont->GetObjectList();
        while (pListEntry)
        {
            InventoryItemEntry* pcont = *_ref_006815c0(pListEntry);
            if (pcont)
            {
                reinterpret_cast<TESContainer_Add*>(this)->AddObject(static_cast<TESForm*>(pcont->object), pcont->count,
                                                                     pcont->extra);
            }
            pListEntry = _ref_00726070(pListEntry);
        }
    }
}

struct FUN_00482040_shell : public TESContainer
{
    void ScaleEntryCounts(int);
};

InventoryItemEntry** __fastcall _ref_006815c0(void*);
void* __fastcall _ref_00726070(void*);

// Walks the object list and multiplies each contained entry's count by aiMult.
// @fnv 0x00482040
void FUN_00482040_shell::ScaleEntryCounts(int aiMult)
{
    void* pCurrentElementNext = (void*)GetObjectList();
    while (pCurrentElementNext)
    {
        InventoryItemEntry* pcont = *_ref_006815c0(pCurrentElementNext);
        if (pcont)
        {
            pcont->count *= aiMult;
        }
        pCurrentElementNext = _ref_00726070(pCurrentElementNext);
    }
}

namespace fnv_00482090 {
struct FUN_00482090_shell : public TESContainer
{
    void FUN_00482090(float);
};

class NiPoint3;
class TeleportableReference
{
  public:
    NiPoint3 const& GetPosition(void);
};
bool __fastcall _ref_008256d0(void* pThis);
InventoryItemEntry** __fastcall _ref_006815c0(void* pThis);
void* __fastcall _ref_00726070(void* pThis);

struct ContainerItemExtra_helper
{
    void FUN_0040eb90(float);
};

// Walks the container's item list, creating each item's extra data if missing, applies afHealthPerc to it, and deletes extras that become default.
// @fnv 0x00482090
void FUN_00482090_shell::FUN_00482090(float afHealthPerc)
{
    void* pCurrentElementNext = (void*)&((TeleportableReference*)this)->GetPosition();
    while (pCurrentElementNext && !_ref_008256d0(pCurrentElementNext))
    {
        InventoryItemEntry* pcont = *_ref_006815c0(pCurrentElementNext);
        if (!pcont->extra)
            pcont->extra = new ContainerItemExtra;
        ((ContainerItemExtra_helper*)pcont->extra)->FUN_0040eb90(afHealthPerc);
        if (pcont->extra->IsDefault())
        {
            delete pcont->extra;
            pcont->extra = 0;
        }
        pCurrentElementNext = _ref_00726070(pCurrentElementNext);
    }
}
}  // namespace fnv_00482090

struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BipedAnim;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct LeveledObject;
struct NiAVObject;
struct NiColor;
struct NiPoint3;
struct TESActorBase;
struct TESBoundObject;
struct TESForm;
struct TESGlobal;
struct TESModel;
struct TESModelTextureSwap;
struct TESObject;
struct TESFormList;
struct TESObjectREFR;
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
struct TESLeveledList : public BaseFormComponent
{
    virtual unsigned char GetChanceNone();
    virtual bool UsesAllEntries();
    virtual int GetMaxLevelDifference();
    virtual void ErrorCheckList();
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void SetChanceNone(unsigned char);
    bool GetCalcAllBelow();
    void SetCalcAllBelow(bool);
    void SetMultCalc(bool);
    bool GetUseAll();
    void SetUseAll(bool);
    TESGlobal* GetChanceGlobal();
    void SetChanceGlobal(TESGlobal*);
    void InitializeLeveledList();
    void SortLeveledList();
    LeveledObject* CreateLeveledObject(unsigned short, unsigned short, TESForm*, ContainerItemExtra*);
    void DeleteLeveledObject(LeveledObject*);
    void SelectLeveledObject(unsigned short, TESForm**, unsigned short*, ContainerItemExtra**, bool, int);
    void PopulateContainerWithLeveledItems(unsigned short, unsigned short, TESContainer*, int);
    void PopulateContainerFromReference(TESObjectREFR*, TESContainer*);
    void ClearScriptAddedLeveledObjects();
    void AddScriptAddedLeveledObject(TESForm*, unsigned short, unsigned short, TESForm*, ContainerItemExtra*);
    void SaveGame(BGSSaveFormBuffer*);
    void LoadGame(BGSLoadFormBuffer*);
    void Revert(BGSLoadFormBuffer*);
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    void InitItem(TESForm*);
    static TESLeveledList* GetFormAsLeveledList(TESForm*);
    void* GetLeveledList();
    void* __vecDelDtor(unsigned int);
    char leveledList[8];
    unsigned char m_pChanceGlobal;
    unsigned char m_ucChanceNone;
    char _pad_e[2];
    TESGlobal* m_pLevelGlobal;
    char m_kLeveledObjects[8];
};
typedef char _sizecheck_TESLeveledList[sizeof(TESLeveledList) == 28 ? 1 : -1];

int __fastcall FNV_GetFormType(TESForm*);

struct TESLevPad
{
    virtual void Dummy();
    char pad[0x2C];
};

struct TESLevFormStub : public TESLevPad, public TESLeveledList
{
};

// Returns apForm cast to TESLeveledList when its form type is 0x34, 0x2C, 0x2D or 0x4C, otherwise null.
// @fnv 0x00487be0
TESLeveledList* __cdecl FUN_00487be0(TESForm* apForm)
{
    TESLeveledList* pLeveledList = 0;
    if (apForm)
    {
        switch (FNV_GetFormType(apForm))
        {
        case 0x34: {
            TESLevFormStub* pLevStub = (TESLevFormStub*)apForm;
            pLeveledList = pLevStub;
            break;
        }
        case 0x2C: {
            TESLevFormStub* pLevStub = (TESLevFormStub*)apForm;
            pLeveledList = pLevStub;
            break;
        }
        case 0x2D: {
            TESLevFormStub* pLevStub = (TESLevFormStub*)apForm;
            pLeveledList = pLevStub;
            break;
        }
        case 0x4C: {
            TESLevFormStub* pLevStub = (TESLevFormStub*)apForm;
            pLeveledList = pLevStub;
            break;
        }
        }
    }
    return pLeveledList;
}

void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* Destroy(unsigned int flags);
};
// Runs the destructor on this object, frees it with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00481760
void* DelStandIn::Destroy(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}

namespace fnv_004817f0 {
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BipedAnim;
struct CHUNK;
struct ContainerChanges;
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
struct TESObjectREFR;
struct TESWaterForm;
struct blob8
{
    char b[8];
};
struct FUN_004817f0_shell : public TESContainer
{
    InventoryItemEntry* AddContainerObject(ContainerChanges*);
};

struct ContainerObjectNew : public InventoryItemEntry
{
    ContainerObjectNew();
};
// If apObj is non-null, allocates a ContainerObjectNew copying its object and count, adds it to the head of the object list, and returns it.
// @fnv 0x004817f0
InventoryItemEntry* FUN_004817f0_shell::AddContainerObject(ContainerChanges* apObj)
{
    if (!apObj)
        return 0;
    InventoryItemEntry* pcobj;
    BSSimpleList<InventoryStackRecord*>* pList = GetObjectList();
    pcobj = new ContainerObjectNew;
    pcobj->object = *(void**)apObj;
    pcobj->count = ((int*)apObj)[1];
    GetObjectList()->AddHead(reinterpret_cast<InventoryStackRecord*&>(pcobj));
    return pcobj;
}
}  // namespace fnv_004817f0

struct CompareHelper
{
    bool Compare(ContainerItemExtra* other);
};

struct FUN_00481470_shell
{
    int count;
    void* object;
    ContainerItemExtra* extra;
    bool IsNotEqual(InventoryItemEntry* apCompare);
};

// Returns true when apCompare is null or its count, object or extra differ from this shell's, comparing extras via CompareHelper::Compare.
// @fnv 0x00481470
bool FUN_00481470_shell::IsNotEqual(InventoryItemEntry* apCompare)
{
    if (!apCompare)
        return true;
    if (count != apCompare->count)
        return true;
    if (object != apCompare->object)
        return true;
    if (extra && !extra->IsDefault() && !apCompare->extra)
        return true;
    if (!extra && apCompare->extra && !apCompare->extra->IsDefault())
        return true;
    if (extra && apCompare->extra && ((CompareHelper*)extra)->Compare(apCompare->extra))
        return true;
    return false;
}

struct FUN_0084e3a0_shell
{
    int __thiscall FUN_0084e3a0();
};

// @fnv 0x00481f10
bool __cdecl FUN_00481f10(TESObject* pObj)
{
    if (pObj && ((FUN_0084e3a0_shell*)pObj)->FUN_0084e3a0() == 0xF)
        return true;
    return false;
}

namespace fnv_004818e0 {
void* __cdecl operator new(unsigned int);
namespace N {
struct BSSimpleList
{
    bool _ref_008256d0();
    InventoryItemEntry** _ref_006815c0();
    BSSimpleList* GetNext();
};
struct ContainerItemExtra
{
    bool Compare(::ContainerItemExtra*);
};
}
struct TgtOps
{
    void* GetPosition();
};
struct G2
{
    void AddHead(int*);
};
struct ContainerObjectNew
{
    int a, b, c;
    ContainerObjectNew();
};
struct FUN_004818e0_t : public TESContainer
{
    InventoryItemEntry* FUN_004818e0(TESObject* apObj, int aiCount, ContainerItemExtra* apExtra);
};
// Finds a container entry matching apObj and apExtra, adds aiCount to its count, or creates a new entry and prepends it to the list.
// @fnv 0x004818e0
InventoryItemEntry* FUN_004818e0_t::FUN_004818e0(TESObject* apObj, int aiCount, ContainerItemExtra* apExtra)
{
    if (!apObj || !aiCount)
        return 0;
    N::BSSimpleList* pCurrentElementNext;
    InventoryItemEntry* pcobj;
    pcobj = 0;
    pCurrentElementNext = (N::BSSimpleList*)((TgtOps*)this)->GetPosition();
    while (pCurrentElementNext && !pCurrentElementNext->_ref_008256d0())
    {
        pcobj = *pCurrentElementNext->_ref_006815c0();
        if (pcobj->object == apObj)
        {
            if (pcobj->extra)
            {
                if (apExtra && !((N::ContainerItemExtra*)pcobj->extra)->Compare(apExtra))
                    break;
            }
            else if (!apExtra)
                break;
        }
        pcobj = 0;
        pCurrentElementNext = pCurrentElementNext->GetNext();
    }
    if (pcobj)
    {
        pcobj->count += aiCount;
    }
    else
    {
        pcobj = (InventoryItemEntry*)new ContainerObjectNew;
        pcobj->count = aiCount;
        pcobj->object = apObj;
        if (apExtra)
        {
            pcobj->extra = new ContainerItemExtra;
            pcobj->extra->Copy(apExtra);
        }
        ((G2*)((TgtOps*)this)->GetPosition())->AddHead((int*)&pcobj);
    }
    return pcobj;
}
}  // namespace fnv_004818e0

namespace fnv_00482770 {
struct Actor;
struct ActorCause;
struct ActorPackageData;
struct AlchemyItem;
struct Animation;
struct TwoIntegerValues;
struct MediaLocation;
struct BGSAcousticSpace;
struct BGSEncounterZone;
struct BGSListForm;
struct BGSLoadFormBuffer;
struct BGSMusicType;
struct BGSPrimitive;
struct BGSSaveFormBuffer;
struct BGSTalkingActivator;
struct BSExtraData;
struct BSMultiBound;
struct BSMultiBoundRoom;
struct BSOcclusionPlane;
struct BSPortal;
struct SoundPlaybackHandle;
struct BaseExtraList;
struct BipedAnim;
struct CellMopp;
struct CollisionData;
struct Crime;
struct TeleportableReference;
struct ExtraAction;
struct ExtraActorCause;
struct ExtraAmmo;
struct ExtraAnim;
struct ExtraAshPileReference;
struct ExtraAudioBuoyMarker;
struct ExtraAudioMarker;
struct ExtraCannotWearData;
struct ExtraDataList;
struct ExtraDismemberedLimbs;
struct ExtraFactionChanges;
struct ExtraFollower;
struct ExtraFollowerSwimBreadcrumbs;
struct ExtraLeveledItem;
struct ExtraLight;
struct ExtraLock;
struct ExtraMapMarker;
struct ExtraNavMeshPortal;
struct ExtraRefractionProperty;
struct ExtraSayToTopicInfo;
struct ExtraSayTopicInfoOnceADay;
struct ExtraStartingPosition;
struct ExtraTalkingActor;
struct ExtraTeleport;
struct PositionRotation;
struct ImpactSwap;
struct InventoryIterator;
struct InventoryStackRecord;
struct MapMarkerData;
struct MenuTopic;
struct Point3Offset;
struct NiNode;
struct NiPoint3;
struct NiRenderedTexture;
struct IndexedPointerCollection;
struct PatrolReferenceData;
struct PatrolRefData;
struct LinkedReferencePair;
struct RadioReferenceData;
struct ReferenceLightData;
struct LockExtraData;
struct ReferenceFloatEntry;
struct RagDollData;
struct PointerFlagNode;
struct TopicInfoVisitRecord;
struct Script;
struct ScriptLocals;
struct SeenData;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESClimate;
struct TESCombatStyle;
struct TESFaction;
struct TESForm;
struct TESGlobal;
struct TESImageSpace;
struct TESLevItem;
struct TESModel;
struct TESNPC;
struct TESObject;
struct TESObjectCELL;
struct TESObjectLAND;
struct TESObjectREFR;
struct TESObjectWEAP;
struct TESPackage;
struct TESRegionList;
struct TESTopic;
struct TESTopicInfo;
struct TESWaterForm;
struct TESWorldSpace;
struct TrespassPackage;
struct WorldLocation;
struct WaterZone;
struct _D3DLOCKED_RECT;
struct bhkWorld;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct InventoryChanges
{
    void ForceWeightRecalculation();
    static void KillTempRef();
    void AddItemToEntry(TESBoundObject*, int, Actor*, ExtraDataList*, InventoryStackRecord*);
    bool IsEmpty();
    void AddItem(TESBoundObject*, ExtraDataList*, int);
    void AddItem(TESObjectREFR*, int, bool, bool);
    void AddChangeEntry(InventoryStackRecord*, bool);
    void RemoveChangeItem(TESBoundObject*);
    TESObjectREFR* RemoveItem(TESObjectREFR*, TESBoundObject*, bool, int, ExtraDataList*, bool, TESObjectREFR*, void*,
                              void*, bool, bool, InventoryStackRecord*);
    void UpdateItemCount(int, bool, int);
    TESObjectREFR* DropItem(TESObjectREFR*, TESBoundObject*, int, TESObjectREFR*, void*, void*);
    void PutItemIntoContainer(TESBoundObject*, int, TESObjectREFR*, ExtraDataList*);
    void DamageItem(TESBoundObject*, float);
    void RepairBatch(TESBoundObject*, float);
    void AddOwnership(TESBoundObject*, TESForm*);
    void RemoveOwnership(TESBoundObject*);
    TESContainer* GetOriginalContainer();
    void RemoveBoundItem(TESBoundObject*, int, Actor*, ExtraDataList*, bool, bool);
    bool RemoveInventoryItem(bool*, TESBoundObject*, int, Actor*, ExtraDataList*, bool, bool, InventoryStackRecord*, bool*);
    void ResetInventoryChanges();
    bool RunScripts(TESObjectREFR*);
    void ResetInventoryState();
    void CleanUpBoundItems(Actor*);
    TESBoundObject* GetLeveledCalculatedBaseObject(TESLevItem*);
    void ModifyCharge(float);
    InventoryStackRecord* GetOrCreateInventoryEntry(TESBoundObject*, bool, unsigned int);
    static InventoryChanges* CreateForReference(TESObjectREFR*);
    ExtraDataList* GetExtraDataListForObject(TESBoundObject*, bool);
    bool WearingWeapon(TESBoundObject**);
    bool WearingAmmo(TESBoundObject**);
    bool WearingTorch(TESBoundObject**);
    InventoryStackRecord* WearingRing(bool);
    bool WearingVoiceModulateItem();
    bool HasItemOfType(unsigned int);
    bool FindItemInInventory(TESBoundObject*, int, int, int*, unsigned int, TESObjectREFR*);
    bool HasQuestObject();
    bool HasScript();
    TESBoundObject* GetObjectAtIndex(int, int*);
    TESBoundObject* GetBoundObjectByIndex(int, int*);
    InventoryStackRecord* GetPotion(void*);
    InventoryStackRecord* GetBestAmmoForActor(TESActorBase*, bool);
    TESAmmo* GetBestAmmoForWeapon(TESObjectWEAP*, bool*);
    InventoryStackRecord* GetBestWeapon(TESActorBase*, float*, int, bool);
    InventoryStackRecord* FindBestArmor(TESActorBase*, int, bool);
    void* GetListBestArmor(TESActorBase*);
    InventoryStackRecord* GetBestClothing(TESActorBase*, int, bool);
    InventoryStackRecord* GetBestLight(TESActorBase*, bool);
    InventoryStackRecord* GetInventoryEntryData(int, bool);
    InventoryStackRecord* GetEquippedItemForSlot(int);
    InventoryStackRecord** GetEntryPointerByIndices(int, int);
    void SetHotKeyItem(InventoryStackRecord*, ExtraDataList*, int);
    void SetInventoryEntryCount(InventoryStackRecord*, int);
    void RemoveAllObjectsWorn(bool, TESObjectREFR*);
    bool RechargeAll();
    void RemoveAllHealth();
    int GetCount(bool);
    InventoryStackRecord* GetInventoryEntryAtIndex(int);
    IndexedPointerCollection* GetFirstItem();
    InventoryStackRecord* GetEntryForListNode(IndexedPointerCollection*);
    void RemoveItemChangeEntry(TESBoundObject*, void*);
    void RefreshItemChange(TESBoundObject*, void*);
    void UpdateItemChangeEntry(TESBoundObject*, void*);
    int GetObjectCount(int);
    int GetObjectCount(TESBoundObject*);
    InventoryStackRecord* GetFirstInventoryEntry();
    int GetInventoryEntryCount();
    void TransferItemToReference(TESObjectREFR*, int, TESObjectREFR*);
    float RemoveAllTypedItems(TESObjectREFR*, TESObjectREFR*, bool, bool, bool, bool, int, BGSListForm*);
    float RemoveAllItems(TESObjectREFR*, TESObjectREFR*, bool, bool, bool, bool, int, BGSListForm*);
    void DuplicateAllItems(TESObjectREFR*, TESObjectREFR*);
    void MoveItemsOfType(TESObjectREFR*, TESObjectREFR*, TESForm*);
    void RemoveNonStolenItems(TESObjectREFR*, TESObjectREFR*);
    float GetInventoryWeight(bool);
    unsigned int GetTotalItemCount(bool, bool);
    void AddAmountToItemChange(TESBoundObject*, int);
    float GetArmorValueForActor(Actor*);
    void UpdateArmorWeight();
    void UpdateWeight();
    void RemoveDefaultLeveledItems();
    bool IsLevelItemInited(int);
    InventoryStackRecord* FindEntryForObject(TESBoundObject*, unsigned int);
    void SetItemsBacktoDefaultState();
    void CopyInventoryChanges(InventoryChanges*, TESObjectREFR*, bool);
    void ResetEntryList();
    void ResetCachedWeights();
    unsigned short GetSaveSize();
    void SaveGame(BGSSaveFormBuffer*);
    void SaveGame();
    void LoadGame(BGSLoadFormBuffer*);
    void LoadGame();
    void InitLoadGame(BGSLoadFormBuffer*);
    void InitLoadGame();
    int GetExtraDataListIndexForItem(TESBoundObject*, ExtraDataList*);
    ExtraDataList* GetExtraDataListFromIndexForItem(TESBoundObject*, int);
    unsigned int FindItemEntryData(int*, void*, unsigned int);
    bool GetNextItem(InventoryIterator*, InventoryStackRecord**, unsigned int);
    TESObjectREFR* GetRef();
    static TESObjectREFR* GetTempRef();
    void RemoveExtraFromObject(TESObject*, ExtraDataList*);
    void DeleteExtraData(TESBoundObject*, ExtraDataList*);
    void* __vecDelDtor(unsigned int);
    void* m_pEntryList;
    TESObjectREFR* pRef;
    float m_fTotalWeight;
    float m_fArmorWeight;
    bool m_bChanged;
    char _pad_11[3];
};
typedef char _sizecheck_InventoryChanges[sizeof(InventoryChanges) == 20 ? 1 : -1];
struct FUN_00482770_shell : public TESContainer
{
    void AddLeveledItemsToChanges(int, InventoryChanges*);
};

struct ExtraDataList
{
    char pad[0x20];
    ExtraDataList();
    void SetLeveledItemIndex(int);
};
struct FUN_00419ad0_shell
{
    void FUN_00419ad0(unsigned short);
};
struct TESHealthForm
{
    static TESHealthForm* __cdecl GetFormAsHealthForm(TESForm*);
};
struct Fn40ea20
{
    void FUN_0040ea20(ExtraDataList*, TESHealthForm*);
};
struct TESForm
{
    void SetFormFlags(int);
};
struct FUN_004c29a0_t
{
    void FUN_004c29a0(void*, ExtraDataList*, int);
};
struct PatrolActorPackageData
{
    bool IsPatrolling();
};
struct BGSSaveLoadGame
{
    bool FUN_0042ce10();
    bool IsFlag20Set();
};
struct GridArray
{
    TESForm* GetCenterX();
};
struct TgtOps
{
    void* GetPosition();
};
struct ContList
{
    bool _ref_008256d0();
    InventoryItemEntry** _ref_006815c0();
    ContList* GetNext();
};
extern PatrolActorPackageData* g_osGlobals;
extern BGSSaveLoadGame* g_BGSSaveLoadGame;

// @fnv 0x00482770
void FUN_00482770_shell::AddLeveledItemsToChanges(int aiLevItemIndex, InventoryChanges* apChanges)
{
    bool bhadChanges = false;
    if (apChanges)
    {
        ContList* pCurrentElementNext = (ContList*)((TgtOps*)this)->GetPosition();
        while (pCurrentElementNext && !pCurrentElementNext->_ref_008256d0())
        {
            InventoryItemEntry* pcont = *pCurrentElementNext->_ref_006815c0();
            if (pcont)
            {
                bhadChanges = true;
                ExtraDataList* pextra = new ExtraDataList();
                pextra->SetLeveledItemIndex(aiLevItemIndex);
                ((FUN_00419ad0_shell*)pextra)->FUN_00419ad0(pcont->count);
                if (pcont->extra)
                    ((Fn40ea20*)pcont->extra)
                        ->FUN_0040ea20(pextra, TESHealthForm::GetFormAsHealthForm((TESForm*)pcont->object));
                ((FUN_004c29a0_t*)apChanges)->FUN_004c29a0(pcont->object, pextra, pcont->count);
            }
            pCurrentElementNext = pCurrentElementNext->GetNext();
        }
        if (bhadChanges && ((GridArray*)apChanges)->GetCenterX() && g_osGlobals->IsPatrolling())
        {
            if (!g_BGSSaveLoadGame->FUN_0042ce10() || g_BGSSaveLoadGame->IsFlag20Set())
                ((GridArray*)apChanges)->GetCenterX()->SetFormFlags(0x8000000);
        }
    }
}
}  // namespace fnv_00482770

struct RefH
{
    bool IsDeleted() const;
};
struct ItemNode
{
    int pad;
    RefH* ref;
};
struct FUN_00481310_shell
{
    void FUN_00481310();
};
struct TgtOps
{
    void* GetPosition();
};
struct FUN_00481b40_shell
{
    void FUN_00481b40();
};
// Iterates the list returned by GetPosition and calls FUN_00481310 on each item whose ref is not deleted.
// @fnv 0x00481b40
void FUN_00481b40_shell::FUN_00481b40()
{
    BSSimpleList<ItemNode*>* node = (BSSimpleList<ItemNode*>*)((TgtOps*)this)->GetPosition();
    if (!node->GetItem())
        node = 0;
    while (node)
    {
        ItemNode* item = node->GetItem();
        if (!item->ref->IsDeleted())
            ((FUN_00481310_shell*)item)->FUN_00481310();
        node = (BSSimpleList<ItemNode*>*)node->GetNext();
    }
}

struct ObjectReference
{
    bool __thiscall FUN_00440d80();
};
struct ContainerNode
{
    InventoryItemEntry** __thiscall FUN_006815c0();
    ContainerNode* __thiscall FUN_00726070();
};
int __cdecl FUN_00ec7d40(int);
double __cdecl FUN_0048ebc0(void*, unsigned char);
struct FUN_00481e10_shell
{
    ContainerNode* __thiscall FUN_00717e50();
    float __thiscall FUN_00481e10(unsigned char);
};
// @fnv 0x00481e10
float __thiscall FUN_00481e10_shell::FUN_00481e10(unsigned char flag)
{
    ContainerNode* node;
    float sum = 0.0f;
    node = FUN_00717e50();
    if (*node->FUN_006815c0() == 0)
        node = 0;
    while (node != 0)
    {
        InventoryItemEntry* entry = *node->FUN_006815c0();
        node = node->FUN_00726070();
        if (reinterpret_cast<ObjectReference*>(entry->object)->FUN_00440d80())
            continue;
        sum = static_cast<float>((double)FUN_00ec7d40(entry->count) * FUN_0048ebc0(entry->object, flag) + sum);
    }
    return sum;
}

class ScriptLocals;
class Script;
class ExtraDataList;
class TESForm
{
  public:
    unsigned FUN_00401170();
};
class TESObjectREFR
{
  public:
    virtual void Unk00();
    virtual void Unk01();
    virtual void Unk02();
    virtual void Unk03();
    virtual ~TESObjectREFR();
    unsigned unk04;
    unsigned unk08;
    unsigned unk0c;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned unk60;
    unsigned unk64;
    TESObjectREFR();
    void FUN_00484490();
    void FUN_00574fa0(TESForm*, ExtraDataList*, int);
};
class Actor : public TESObjectREFR
{
  public:
    virtual void Unk05();
    virtual void Unk06();
    virtual void Unk07();
    virtual void Unk08();
    virtual void Unk09();
    virtual void Unk0a();
    virtual void Unk0b();
    virtual void Unk0c();
    virtual void Unk0d();
    virtual void Unk0e();
    virtual void Unk0f();
    virtual void Unk10();
    virtual void Unk11();
    virtual void Unk12();
    virtual void Unk13();
    virtual void Unk14();
    virtual void Unk15();
    virtual void Unk16();
    virtual void Unk17();
    virtual void Unk18();
    virtual void Unk19();
    virtual void Unk1a();
    virtual void Unk1b();
    virtual void Unk1c();
    virtual void Unk1d();
    virtual void Unk1e();
    virtual void Unk1f();
    virtual void Unk20();
    virtual void Unk21();
    virtual void Unk22();
    virtual void Unk23();
    virtual void Unk24();
    virtual void Unk25();
    virtual void Unk26();
    virtual void Unk27();
    virtual void Unk28();
    virtual void Unk29();
    virtual void Unk2a();
    virtual void Unk2b();
    virtual void Unk2c();
    virtual void Unk2d();
    virtual void Unk2e();
    virtual void Unk2f();
    virtual void Unk30();
    virtual void Unk31();
    virtual void Unk32();
    virtual void Unk33();
    virtual void Unk34();
    virtual void Unk35();
    virtual void Unk36();
    virtual void Unk37();
    virtual void Unk38();
    virtual void Unk39();
    virtual void Unk3a();
    virtual void Unk3b();
    virtual void Unk3c();
    virtual void Unk3d();
    virtual void Unk3e();
    virtual void Unk3f();
    virtual void Unk40();
    virtual void Unk41();
    virtual void Unk42();
    virtual void Unk43();
    virtual void Unk44();
    virtual void Unk45();
    virtual void Unk46();
    virtual void Unk47();
    virtual void Unk48();
    virtual void Unk49();
    virtual void Unk4a();
    virtual void Unk4b();
    virtual void Unk4c();
    virtual void Unk4d();
    virtual void Unk4e();
    virtual void Unk4f();
    virtual void Unk50();
    virtual void Unk51();
    virtual void Unk52();
    virtual void Unk53();
    virtual void Unk54();
    virtual void Unk55();
    virtual void Unk56();
    virtual void Unk57();
    virtual void Unk58();
    virtual void Unk59();
    virtual void Unk5a();
    virtual void Unk5b();
    virtual void Unk5c();
    virtual void Unk5d();
    virtual void Unk5e();
    virtual void Unk5f();
    virtual void Unk60();
    virtual void Unk61();
    virtual void Unk62();
    virtual void Unk63();
    virtual void AddItem(TESForm*, ExtraDataList*, int);
    const char* FUN_008adcf0(TESForm*, int, int);
};
class ExtraDataList
{
  public:
    unsigned unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    ExtraDataList();
    void FUN_00419ad0(unsigned short);
    Script* FUN_00418800();
    void FUN_00419ed0(Script*);
    void FUN_00419f80(ScriptLocals*);
    ScriptLocals* FUN_00418830();
};
class Script
{
  public:
    ScriptLocals* CreateEventList();
    void Execute(TESObjectREFR*, ScriptLocals*, TESObjectREFR*, bool);
};
struct ItemExtra
{
    void FUN_0040ea20(ExtraDataList*, void*);
};
struct Item
{
    int count;
    TESForm* form;
    ItemExtra* extra;
};
struct Node
{
    Item** FUN_006815c0();
    Node* FUN_00726070();
};
struct SettingString
{
    const char* FUN_00403df0();
};
extern SettingString DAT_011d4e7c, DAT_011d3114;
extern Actor* DAT_011dea3c;
Script* FUN_004826d0(TESForm*);
void* GetHealthForm(TESForm*);
const char* FUN_00482720(TESForm*);
int FUN_00406f60(BSStringT<char>*, const char*, ...);
bool QueueUIMessage(const char*, int, const char*, const char*, float, bool);
struct ContainerOperation
{
    Node* FUN_00717e50();
    void FUN_004821a0(TESObjectREFR*, bool);
};
// @fnv 0x004821a0
void ContainerOperation::FUN_004821a0(TESObjectREFR* target, bool silent)
{
    if (target)
    {
        Actor* last = dynamic_cast<Actor*>(target);
        Item* actor = 0;
        Node* node = FUN_00717e50();
        while (node)
        {
            Item* item = *node->FUN_006815c0();
            if (item)
            {
                Script* script = FUN_004826d0(item->form);
                int count = item->count;
                actor = item;
                if (script)
                {
                    for (int index = 0; index < count; ++index)
                    {
                        ExtraDataList* extra = 0;
                        extra = new ExtraDataList;
                        extra->FUN_00419ad0(1);
                        if (extra && !extra->FUN_00418800())
                        {
                            extra->FUN_00419ed0(script);
                            extra->FUN_00419f80(script->CreateEventList());
                            TESObjectREFR* ref = new TESObjectREFR;
                            ref->FUN_00484490();
                            script->Execute(ref, extra->FUN_00418830(), 0, false);
                            delete ref;
                            if (item->extra)
                                item->extra->FUN_0040ea20(extra, GetHealthForm(item->form));
                        }
                        if (last)
                            last->AddItem(item->form, extra, 1);
                        else
                            target->FUN_00574fa0(item->form, extra, 1);
                    }
                }
                else
                {
                    ExtraDataList* data = 0;
                    if (item->extra)
                    {
                        data = new ExtraDataList;
                        data->FUN_00419ad0((unsigned short)item->count);
                        item->extra->FUN_0040ea20(data, GetHealthForm(item->form));
                    }
                    if (last)
                        last->AddItem(item->form, data, item->count);
                    else
                        target->FUN_00574fa0(item->form, data, item->count);
                }
            }
            node = node->FUN_00726070();
        }
        if (last == DAT_011dea3c && actor && !silent)
        {
            BSStringT<char> text;
            if (actor->count > 1)
                FUN_00406f60(&text, "%i %s%s %s", actor->count, FUN_00482720(actor->form), DAT_011d3114.FUN_00403df0(),
                             DAT_011d4e7c.FUN_00403df0());
            else
                FUN_00406f60(&text, "%s %s", FUN_00482720(actor->form), DAT_011d4e7c.FUN_00403df0());
            switch (actor->form->FUN_00401170())
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
                QueueUIMessage(text.String(), 0, "Interface\\Icons\\Message Icons\\glow_message_giftbox.dds",
                               silent ? 0 : DAT_011dea3c->FUN_008adcf0(actor->form, 1, 0), 2.0f, false);
                break;
            case 24:
                QueueUIMessage(text.String(), 0, "Interface\\Icons\\Message Icons\\glow_message_giftbox.dds",
                               silent ? 0 : DAT_011dea3c->FUN_008adcf0(actor->form, 1, 0), 2.0f, false);
                break;
            }
        }
    }
}

extern float DAT_01015f5c;
extern char DAT_01183108;
extern char DAT_01183998;

struct FUN_00482910_rec
{
    int unk00;
    int unk04;
};

struct FUN_00482910_node
{
    void* FUN_006815c0();
    FUN_00482910_node* FUN_00726070();
};

struct FUN_00482910_obj
{
    float FUN_005f0d60(FUN_00482910_rec* r);
};

int __cdecl FUN_00ec43fb(int a, int b, void* c, void* d, int e);

class FUN_00482910_cls
{
  public:
    FUN_00482910_node* FUN_00717e50();
    FUN_00482910_rec* FindBestRecord(FUN_00482910_obj* a1);
};

// Walks the node list, scores each record via a1->FUN_005f0d60, and returns the record with the highest score above DAT_01015f5c.
// @fnv 0x00482910
FUN_00482910_rec* FUN_00482910_cls::FindBestRecord(FUN_00482910_obj* pScorer)
{
    FUN_00482910_node* p = FUN_00717e50();
    float best = DAT_01015f5c;
    FUN_00482910_rec* result2 = 0;
    while (p != 0)
    {
        FUN_00482910_rec* t3 = *(FUN_00482910_rec**)p->FUN_006815c0();
        if (t3 != 0)
        {
            FUN_00482910_rec* r = (FUN_00482910_rec*)FUN_00ec43fb(t3->unk04, 0, &DAT_01183108, &DAT_01183998, 0);
            if (r != 0)
            {
                float f7 = pScorer->FUN_005f0d60(r);
                if (f7 > best)
                {
                    best = f7;
                    result2 = r;
                }
            }
        }
        p = p->FUN_00726070();
    }
    return result2;
}

struct FUN_00481d10_shell : TESContainer
{
    bool FUN_00481d10(BaseFormComponent* other);
};
void* __fastcall _ref_00717e50(void*);
int __fastcall _ref_005ae380(void*);
// Compares this container's entries against another TESContainer's entries, returning true when they differ or the counts do not match.
// @fnv 0x00481d10
bool FUN_00481d10_shell::FUN_00481d10(BaseFormComponent* other)
{
    TESContainer* otherContainer = dynamic_cast<TESContainer*>(other);
    if (otherContainer == 0)
        return true;
    int matchCount = 0;
    void* current = _ref_00717e50(this);
    void* otherCurrent = 0;
    InventoryItemEntry* itemBeingChecked;
    while (current != 0)
    {
        itemBeingChecked = *_ref_006815c0(current);
        if (itemBeingChecked != 0)
        {
            otherCurrent = _ref_00717e50(otherContainer);
            bool differenceFound = false;
            while (otherCurrent != 0)
            {
                InventoryItemEntry* compareItem = *_ref_006815c0(otherCurrent);
                if (compareItem != 0)
                {
                    if (!reinterpret_cast<FUN_00481470_shell*>(compareItem)->IsNotEqual(itemBeingChecked))
                    {
                        differenceFound = true;
                        break;
                    }
                }
                otherCurrent = _ref_00726070(otherCurrent);
            }
            if (!differenceFound)
                return true;
            ++matchCount;
        }
        current = _ref_00726070(current);
    }
    if (_ref_005ae380(_ref_00717e50(otherContainer)) != matchCount)
        return true;
    return false;
}

void* __cdecl operator new(unsigned int);
class InventoryStackRecord
{
  public:
    int count;
    void* object;
};
struct Source08
{
    int unk00;
    BSSimpleList<InventoryStackRecord*> objects;
    BSSimpleList<InventoryStackRecord*>* CopyUniqueObjects();
};
// Copies the objects list into a new list in reverse order, then removes duplicate entries that share the same object pointer.
// @fnv 0x00482b00
BSSimpleList<InventoryStackRecord*>* Source08::CopyUniqueObjects()
{
    BSSimpleList<InventoryStackRecord*>* pNewList = new BSSimpleList<InventoryStackRecord*>;
    BSSimpleList<InventoryStackRecord*>* pList = &objects;
    while (pList && pList->GetItem())
    {
        pNewList->AddHead(pList->GetItem());
        pList = pList->GetNext();
    }
    pList = pNewList;
    BSSimpleList<InventoryStackRecord*>* iter = 0;
    while (pList && pList->GetItem())
    {
        iter = pList->GetNext();
        while (iter && iter->GetItem())
        {
            if (pList->GetItem()->object == iter->GetItem()->object)
            {
                pList->Remove(iter->GetItem());
                iter = pList->GetNext();
            }
            else
                iter = iter->GetNext();
        }
        pList = pList->GetNext();
    }
    return pNewList;
}

struct VATSCommand;
struct ContNode;
struct VATS_CommandList
{
    void FUN_00905330(VATSCommand* const& apCommand);
};
ContNode* __fastcall FUN_00717e50(void* apList);
struct FUN_00481790_t
{
    void FUN_00481790(BGSPerkEntry* apEntry);
};
// @fnv 0x00481790
void FUN_00481790_t::FUN_00481790(BGSPerkEntry* apEntry)
{
    if (!apEntry)
        return;
    ((VATS_CommandList*)FUN_00717e50(this))->FUN_00905330((VATSCommand* const&)apEntry);
    BGSPerkEntry* pkEntry = apEntry;
    BGSPerkEntry* pkDeleteCur = pkEntry;
    pkDeleteCur ? pkDeleteCur->Destroy(1) : 0;
}

class TESBoundObject
{
  public:
    virtual ~TESBoundObject();
};
struct ArmorSlotMask
{
    bool FUN_00480af0(int slot, int a2, int a3);
};
class TESObjectARMO : public TESBoundObject
{
  public:
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c;
    ArmorSlotMask bipedSlots;
};
struct ArmorRater
{
    float FUN_005f0d60(TESObjectARMO* armor);
};
static const float kNegInfinity = -3.402823466e+38f;
struct ArmorContainer : TESContainer
{
    TESObjectARMO* FindBestArmorForSlot(ArmorRater* rater, int slot);
};
// Scans the container's object list for armor matching the given biped slot and returns the one with the highest rater score, or null.
// @fnv 0x004829c0
TESObjectARMO* ArmorContainer::FindBestArmorForSlot(ArmorRater* rater, int slot)
{
    BSSimpleList<InventoryStackRecord*>* iter = GetObjectList();
    float best = kNegInfinity;
    TESObjectARMO* pkResult = 0;
    while (iter)
    {
        InventoryItemEntry* pkObject = (InventoryItemEntry*)iter->GetItem();
        if (pkObject)
        {
            TESObjectARMO* armor = dynamic_cast<TESObjectARMO*>((TESBoundObject*)pkObject->object);
            if (armor && slot != -1 && armor->bipedSlots.FUN_00480af0(slot, 0, 0))
            {
                float fVal = rater->FUN_005f0d60(armor);
                if (fVal > best)
                {
                    best = fVal;
                    pkResult = armor;
                }
            }
        }
        iter = iter->GetNext();
    }
    return pkResult;
}

struct RecipeAmmoData
{
    void FUN_006ecd40(unsigned int count);
};

struct RecipeProcess
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
    virtual bool IsBoundObject();
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual bool IsActor();
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
    virtual RecipeAmmoData* GetAmmoData();
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
    virtual void RemoveItem(void* item, int extra, int count, int a4, int a5, int a6, int a7, int a8, int a9, int a10);
};

struct RecipeActorForm
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
    virtual bool IsBoundObject();
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual bool IsActor();
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
    virtual RecipeAmmoData* GetAmmoData();
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
    virtual void RemoveItem(void* item, int extra, int count, int a4, int a5, int a6, int a7, int a8, int a9, int a10);

    int FUN_00401170();
    void* FUN_008a1710();
    int FUN_00575610(void* item);
    void FUN_0088d7d0(void* item, int count, void* extra, bool a4, bool a5, bool a6);
    RecipeProcess* FUN_008d8520();
    bool FUN_004c0bf0();
    void FUN_00574fa0(void* item, int extra, int count);
};

struct RecipeListBox
{
    void* FindItemData(void* item);
};

struct RecipeMenuState
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
    RecipeActorForm* crafterRef;
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
    RecipeListBox* recipeList;
};

struct ActiveRecipe
{
    void* FUN_005a8080();
    void* FUN_005d43c0();
};

struct RecipeComponentItem
{
    void* FUN_00726070();
    int FUN_00559450();
};

struct RecipeComponentNode
{
    bool FUN_008256d0();
    RecipeComponentItem** FUN_006815c0();
    RecipeComponentNode* FUN_00726070();
};

struct FUN_004f2770_Class
{
    const char* FUN_008adcf0(void* item, int a2, int a3);
};

struct GameSettingStr
{
    const char* FUN_00403df0();
};

struct WeaponFormOps
{
    void* FUN_00525980(void* actor);
};

struct RecipeContainerOps : TESContainer
{
    void FUN_004818e0(TESForm* form, int count, ContainerItemExtra* extra);
    void FUN_00482090(float health);
    void FUN_004821a0(void* target, int a2);
};

struct RecipeStringOps : BSStringT<char>
{
    const char* FUN_00559450();
};

extern RecipeMenuState* DAT_011d8e90;
extern ActiveRecipe* DAT_011d8e94;
extern FUN_004f2770_Class* _g_thePlayer;
extern float DAT_01030ff0;
extern float DAT_010162c0;
extern const char str_0101c178[];
extern const char str_01012058[];
extern const char str_0101c140[];

int __cdecl FUN_005f5950(int a1, int a2, void* a3, int a4, int a5, int a6, int a7);
void __cdecl FUN_004d5e10(int statId, int delta);
const char* __cdecl FUN_00482720(void* form);
int __cdecl FUN_00406f60(BSStringT<char>* outStr, const char* fmt, ...);
bool __cdecl QueueUIMessage(const char* msg, int emotion, const char* iconPath, const char* soundName, float duration,
                            bool instant);
void __cdecl FUN_00727430();

// Removes recipe components from the crafter and adds the crafted item, queuing a UI message with the item name and quantity.
// @fnv 0x007284f0
void CraftRecipe(int count)
{
    bool playedSound;
    bool isCasinoChip;
    {
        int compQty;
        {
            void* compForm;
            {
                RecipeComponentNode* node;
                {
                    RecipeActorForm* itemForm;
                    {
                        void* recipeTile = DAT_011d8e90->recipeList->FindItemData(&DAT_011d8e94);
                        node = (RecipeComponentNode*)DAT_011d8e94->FUN_005a8080();
                        itemForm = 0;
                        compForm = 0;
                        compQty = 0;
                        if (count == 0)
                        {
                            return;
                        }
                        playedSound = 0;
                        isCasinoChip = 0;
                        for (; node != 0 && !node->FUN_008256d0();)
                        {
                            compForm = (*node->FUN_006815c0())->FUN_00726070();
                            if (!playedSound)
                            {
                                FUN_005f5950(12, 1, compForm, 0, 0, 0, 0);
                                if (((RecipeActorForm*)compForm)->FUN_00401170() == 0x6c)
                                {
                                    isCasinoChip = 1;
                                }
                            }
                            playedSound = 1;
                            compQty = (*node->FUN_006815c0())->FUN_00559450();
                            if (compForm != 0 && ((RecipeActorForm*)compForm)->IsBoundObject())
                            {
                                itemForm = (RecipeActorForm*)compForm;
                            }
                            if (itemForm != 0)
                            {
                                RecipeActorForm* actor;
                                {
                                    bool isCurrentAmmo = 0;
                                    actor = (DAT_011d8e90->crafterRef != 0 && DAT_011d8e90->crafterRef->IsActor())
                                                ? DAT_011d8e90->crafterRef
                                                : 0;
                                    if (actor != 0 && actor->FUN_008a1710() != 0)
                                    {
                                        isCurrentAmmo =
                                            (((WeaponFormOps*)actor->FUN_008a1710())->FUN_00525980(_g_thePlayer) ==
                                             (*node->FUN_006815c0())->FUN_00726070());
                                    }
                                    if (itemForm->FUN_00401170() == 0x28)
                                    {
                                        if (actor->FUN_00575610(itemForm) == 1 && itemForm == actor->FUN_008a1710())
                                        {
                                            actor->FUN_0088d7d0(itemForm, 1, 0, 0, 0, 1);
                                        }
                                    }
                                    DAT_011d8e90->crafterRef->RemoveItem(itemForm, 0, compQty * count, 0, 0, 0, 0, 0, 1,
                                                                         0);
                                    if (isCurrentAmmo)
                                    {
                                        actor->FUN_008d8520()->GetAmmoData()->FUN_006ecd40(0);
                                    }
                                }
                            }
                            node = node->FUN_00726070();
                        }
                        if (!isCasinoChip)
                        {
                            FUN_004d5e10(0x20, count);
                        }
                        node = (RecipeComponentNode*)DAT_011d8e94->FUN_005d43c0();
                        itemForm = 0;
                        compForm = 0;
                        compQty = 0;
                        for (; node != 0 && !node->FUN_008256d0();)
                        {
                            compForm = (*node->FUN_006815c0())->FUN_00726070();
                            compQty = (*node->FUN_006815c0())->FUN_00559450();
                            if (compForm != 0 && ((RecipeActorForm*)compForm)->IsBoundObject())
                            {
                                itemForm = (RecipeActorForm*)compForm;
                            }
                            if (itemForm != 0)
                            {
                                if (itemForm->FUN_00401170() == 0x28)
                                {
                                    RecipeActorForm* weapForm = itemForm;
                                    if (weapForm->FUN_004c0bf0())
                                    {
                                        DAT_011d8e90->crafterRef->FUN_00574fa0(itemForm, 0, compQty * count);
                                    }
                                    else
                                    {
                                        TESContainer tempCont1;
                                        if (itemForm != 0)
                                        {
                                            ((RecipeContainerOps*)&tempCont1)
                                                ->FUN_004818e0((TESForm*)itemForm, compQty * count, 0);
                                        }
                                        ((RecipeContainerOps*)&tempCont1)->FUN_00482090(DAT_01030ff0);
                                        ((RecipeContainerOps*)&tempCont1)->FUN_004821a0(DAT_011d8e90->crafterRef, 0);
                                    }
                                }
                                else if (itemForm->FUN_00401170() == 0x18 || itemForm->FUN_00401170() == 0x1a)
                                {
                                    TESContainer tempCont2;
                                    if (itemForm != 0)
                                    {
                                        ((RecipeContainerOps*)&tempCont2)
                                            ->FUN_004818e0((TESForm*)itemForm, compQty * count, 0);
                                    }
                                    ((RecipeContainerOps*)&tempCont2)->FUN_00482090(DAT_01030ff0);
                                    ((RecipeContainerOps*)&tempCont2)->FUN_004821a0(DAT_011d8e90->crafterRef, 0);
                                }
                                else
                                {
                                    DAT_011d8e90->crafterRef->FUN_00574fa0(itemForm, 0, compQty * count);
                                }
                                BSStringT<char> msgStr;
                                if (compQty * count > 1)
                                {
                                    FUN_00406f60(&msgStr, str_0101c178, compQty * count, FUN_00482720(itemForm),
                                                 DAT_011d3114.FUN_00403df0(), DAT_011d4e7c.FUN_00403df0());
                                }
                                else
                                {
                                    FUN_00406f60(&msgStr, str_01012058, FUN_00482720(itemForm),
                                                 DAT_011d4e7c.FUN_00403df0());
                                }
                                QueueUIMessage(((RecipeStringOps*)&msgStr)->FUN_00559450(), 0, str_0101c140,
                                               _g_thePlayer->FUN_008adcf0(itemForm, 1, 0), DAT_010162c0, 0);
                            }
                            node = node->FUN_00726070();
                        }
                        FUN_00727430();
                    }
                }
            }
        }
    }
}

namespace fnv_004826d0 {
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiColor;
struct NiPoint3;
struct Script;
struct TESBoundObject;
struct TESForm;
struct TESObjectREFR;
struct blob8
{
    char b[8];
};
struct TESScriptableForm : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    void InitItem(TESForm*);
    static Script* GetScriptForForm(TESForm*);
    Script* GetScriptForForm();
    static char* GetFormScriptEditorID(TESForm*);
    char* GetFormScriptEditorID();
    static void SetFormScript(TESForm*, Script*);
    void SetFormScript(Script*);
    Script* m_pFormScript;
    bool m_bHasScript;
    char _pad_9[3];
};
typedef char _sizecheck_TESScriptableForm[sizeof(TESScriptableForm) == 12 ? 1 : -1];

struct Script;

extern unsigned char DAT_01183028;
extern unsigned char DAT_01183254;
extern "C" void* __cdecl FNV_DynamicCast(void*, long, void*, void*, int);
// Dynamic-casts apForm to TESScriptableForm and returns its script, or null if the cast fails.
// @fnv 0x004826d0
Script* FUN_004826d0(TESForm* apForm)
{
    TESScriptableForm* pSF =
        static_cast<TESScriptableForm*>(FNV_DynamicCast(apForm, 0, &DAT_01183028, &DAT_01183254, 0));
    return pSF ? pSF->GetScriptForForm() : 0;
}
}  // namespace fnv_004826d0
