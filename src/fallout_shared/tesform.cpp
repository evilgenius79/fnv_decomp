// fallout_shared/tesform.cpp: TESForm, TESValueForm, TESFile, BGSSaveLoadChangesMap and more (128 functions)

#include "tesform_calls.h"
#include "tesform_TESFile.h"

// Walks the source-file list, returning the last non-null TESFile, or the one at fileIndex when fileIndex is not -1.
// @fnv 0x00484e60
TESFile* TESForm::GetFile(int fileIndex)
{
    TESFile* sourceFile;
    int index;
    BSSimpleList<TESFile*>* fileList;
    TESFile* selected;
    fileList = GetSourceFiles();
    index = 0;
    sourceFile = 0;
    selected = 0;
    while (fileList)
    {
        sourceFile = fileList->GetItem();
        fileList = fileList->GetNext();
        if (sourceFile)
        {
            selected = sourceFile;
            if (fileIndex != -1)
            {
                ++index;
                if (index > fileIndex)
                {
                    break;
                }
            }
        }
    }
    return selected;
}

// Covered functions reconstructed from the supplied disassembly.
// @fnv 0x00401170
ENUM_FORM_ID TESForm::GetFormType() const
{
    return static_cast<ENUM_FORM_ID>(m_ucFormType);
}
// @fnv 0x00440da0
bool TESForm::GetDisabled() const
{
    return (m_uiFormFlags & 0x800);
}
// @fnv 0x00483710
void TESForm::ClearData()
{}
// @fnv 0x00484490
void TESForm::NotifySaveLoadGameOfFormChange()
{
    UpdateFormChangeFlags();
    if (g_TESSaveLoadGame)
        g_TESSaveLoadGame->HasFormChanges(this, false);
    if (g_BGSSaveLoadGame)
        g_BGSSaveLoadGame->HasFormChanges(this);
    m_uiFormFlags |= 0x4000;
}

// @fnv 0x004844f0
void TESForm::SetMasterFile(bool set)
{
    if (set)
        m_uiFormFlags |= 0x1;
    else
        m_uiFormFlags &= ~0x1;
}

// @fnv 0x00484530
void TESForm::MarkForDeletion(bool set)
{
    if (set)
        m_uiFormFlags |= 0x20;
    else
        m_uiFormFlags &= ~0x20;
    MarkAsModified(1);
}

// @fnv 0x00484650
void TESForm::SetDestroyed(bool abDestroyed)
{
    if (abDestroyed)
        m_uiFormFlags |= 0x800000;
    else
        m_uiFormFlags &= ~0x800000;
    MarkAsModified(1);
}

// @fnv 0x004846a0
void TESForm::SetDestructible(bool set)
{
    if (set)
        m_uiFormFlags |= 0x1000000;
    else
        m_uiFormFlags &= ~0x1000000;
}

// @fnv 0x004848b0
void TESForm::SetFormFlag40(bool set)
{
    if (set)
        m_uiFormFlags |= 0x40;
    else
        m_uiFormFlags &= ~0x40;
    MarkAsModified(1);
}

// @fnv 0x00484900
void TESForm::SetHavokDeath(bool set)
{
    if (set)
        m_uiFormFlags |= 0x10000;
    else
        m_uiFormFlags &= ~0x10000;
    MarkAsModified(1);
}

// @fnv 0x00484950
void TESForm::SetNeedToChangeProcess(bool set)
{
    if (set)
        m_uiFormFlags |= 0x20000;
    else
        m_uiFormFlags &= ~0x20000;
}

// @fnv 0x00484990
void TESForm::SetIgnoreFriendlyHits(bool set)
{
    if (set)
        m_uiFormFlags |= 0x100000;
    else
        m_uiFormFlags &= ~0x100000;
}

// @fnv 0x00484ab0
void TESForm::SetInitializationState(bool set)
{
    if (set)
        m_uiFormFlags |= 0x8;
    else
        m_uiFormFlags &= ~0x8;
}

// @fnv 0x00484b40
bool TESForm::IsReservedFormID(unsigned int formID)
{
    if (formID != 0 && formID <= 0x7ff)
        return true;
    else
        return false;
}
// @fnv 0x00484e40
bool TESForm::IsReservedFormID()
{
    return IsReservedFormID(GetFormID());
}
// @fnv 0x00484b60
void TESForm::MarkAsModified(unsigned int flags)
{
    g_BGSSaveLoadGame->NotifyFormIDChanged(this, flags, false);
}
// Forwards this form and the given flags to g_BGSSaveLoadGame's handler with the third argument set to true.
// @fnv 0x00484b90
void TESForm::SetFormFlags(int flags)
{
    g_BGSSaveLoadGame->NotifyFormIDChanged(this, flags, true);
}
// @fnv 0x00484bc0
void TESForm::MarkAsUnmodified(unsigned int flags)
{
    g_BGSSaveLoadGame->ClearFormChangeFlags(this, flags);
}
// Reads 4 bytes of change flags from the load buffer when flag 1 is set and merges the masked bits into the form's flags field.
// @fnv 0x00484da0
void TESForm::LoadGame(void* apLoadBuffer)
{
    if (static_cast<BGSLoadFormBuffer*>(apLoadBuffer)->GetChangeFlags(1))
    {
        unsigned int flags = 0;
        static_cast<BGSLoadFormBuffer*>(apLoadBuffer)->ReadTypedData(&flags, 4);
        if (GetIsReference())
            m_uiFormFlags = (m_uiFormFlags & 0xff6ed79f) | (flags & 0x00912860);
        else
            m_uiFormFlags = (m_uiFormFlags & 0xbffff3df) | (flags & 0x40000c20);
    }
}
// Stores value in uiValue and, if this is a TESForm, marks it as modified with flag 2.
// @fnv 0x0048e960
void TESValueForm::SetFormValue(unsigned int value)
{
    uiValue = value;
    TESForm* form = dynamic_cast<TESForm*>(this);
    if (form)
        form->MarkAsModified(2);
}
// Stores item into m_item when item is non-null; returns early otherwise.
// @fnv 0x00726c60
template <> void BSSimpleList<TESFile*>::SetItem(TESFile* const& apFile)
{
    if (!apFile)
        return;
    m_item = apFile;
}
// @fnv 0x00484ee0
TESFile* TESForm::GetOwnerMaster()
{
    BSSimpleList<TESFile*>* pFileNode = GetSourceFiles();
    TESFile* pOwnerMaster = 0;
    while (pFileNode && !pFileNode->IsEmpty())
    {
        TESFile* file = pFileNode->GetItem();
        pFileNode = pFileNode->GetNext();
        if (file->IsMasterFile())
            pOwnerMaster = file;
    }
    return pOwnerMaster;
}

// Looks up editorID in the form table and returns the matching TESForm, or null if editorID is empty or not found.
// @fnv 0x00483a00
TESForm* TESForm::LookupFormByEditorID(const char* editorID)
{
    TESForm* form = 0;
    if (editorID && *editorID && ms_pEditorIDMap && ms_pEditorIDMap->GetAt(editorID, form))
    {
        return form;
    }
    else
    {
        return 0;
    }
}

// Lazily allocates the three global form lookup containers (pointer map, case-insensitive string map, large primitive array) if they are null.
// @fnv 0x00483a50
void TESForm::InitializeFormIDMap()
{
    if (!ms_pFormIDMap)
    {
        ms_pFormIDMap = new NiTPointerMap<unsigned int, TESForm*>(0x2008D);
    }
    if (!ms_pEditorIDMap)
    {
        ms_pEditorIDMap = new BSTCaseInsensitiveStringMap<TESForm*>(0xFA1, true);
    }
    if (!ms_pAllForms)
    {
        ms_pAllForms = new NiTLargePrimitiveArray<TESForm*>(32, 1);
    }
}

// @fnv 0x00484f50
void TESForm::SetFile(TESFile* file)
{
    TESFile* parentFile = file ? file->GetThreadSafeRootFile() : 0;
    if (parentFile)
    {
        file = parentFile;
    }
    if (!file)
    {
        BSSimpleList<TESFile*>* source = GetSourceFiles();
        BSSimpleList<TESFile*>* lastSource = 0;
        while (source)
        {
            if (source->GetItem())
            {
                lastSource = source;
            }
            source = source->GetNext();
        }
        if (lastSource)
        {
            lastSource->RemoveHead();
        }
        else
        {
            GetSourceFiles()->RemoveHead();
        }
    }
    else if (file->IsMasterFile())
    {
        BSSimpleList<TESFile*>* source = GetSourceFiles();
        BSSimpleList<TESFile*>* lastMaster = 0;
        while (source && !source->IsEmpty())
        {
            TESFile* sourceFile = source->GetItem();
            if (sourceFile->IsMasterFile())
            {
                lastMaster = source;
                source = source->GetNext();
            }
            else
            {
                if (lastMaster)
                {
                    lastMaster->Remove(sourceFile);
                    source = lastMaster->GetNext();
                }
                else
                {
                    source->RemoveHead();
                }
            }
        }
        GetSourceFiles()->AddTail(file);
    }
    else
    {
        BSSimpleList<TESFile*>* source = GetSourceFiles();
        BSSimpleList<TESFile*>* lastSource = 0;
        while (source)
        {
            TESFile* sourceFile = source->GetItem();
            if (sourceFile)
            {
                lastSource = source;
                if (sourceFile == file)
                {
                    return;
                }
            }
            source = source->GetNext();
        }
        if (lastSource)
        {
            lastSource->AddTail(file);
        }
        else
        {
            GetSourceFiles()->AddHead(file);
        }
    }
}

// @fnv 0x00467bb0
unsigned int TESFile::GetOffset()
{
    return m_uiRecordSize;
}

extern int DAT_01014210;

// @fnv 0x0040ecb0
void __fastcall FUN_0040ecb0(int* p)
{
    *p = (int)&DAT_01014210;
}

struct FUN_00471d60_shell : public TESFile
{
    bool IsFlag8Set();
};

// @fnv 0x00471d60
bool FUN_00471d60_shell::IsFlag8Set()
{
    if (*(unsigned int*)((char*)this + 0x3e8) & 8)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// @fnv 0x004835e0
unsigned int __fastcall GetField20C(char* pThis)
{
    return *(unsigned int*)(pThis + 0x20c);
}

struct T00485110
{
    void InitializeForm(void*);
};
struct S00485110
{
    void CallWithThis(T00485110* f);
};
// @fnv 0x00485110
void S00485110::CallWithThis(T00485110* apTarget)
{
    apTarget->InitializeForm(this);
}

// Returns the smaller of two unsigned short values.
// @fnv 0x004865f0
unsigned short __cdecl MinUnsignedShort(unsigned short ausValue1, unsigned short ausValue2)
{
    return ausValue1 < ausValue2 ? ausValue1 : ausValue2;
}

struct FormEnumEntry
{
    unsigned int m_uiFormID;
    int unk4;
    int unk8;
};

extern FormEnumEntry DAT_01187008[];
extern int DAT_011c54f0;
extern unsigned int DAT_011c54f4;

// @fnv 0x00486890
int __cdecl FindFormEnumIndex(unsigned int aiFormString)
{
    if (aiFormString == DAT_011c54f4)
    {
        return DAT_011c54f0;
    }
    for (int i = 0; i < 0x79; ++i)
    {
        if (DAT_01187008[i].m_uiFormID == aiFormString)
        {
            DAT_011c54f0 = i;
            DAT_011c54f4 = aiFormString;
            return DAT_011c54f0;
        }
    }
    return 0;
}

extern int DAT_01031fac;

struct FUN_00486930_arg
{
    unsigned int val;
};

void __fastcall FUN_005890c0(int* self, FUN_00486930_arg a);

// Calls FUN_005890c0 on self, then stores the address of DAT_01031fac into *self and returns self.
// @fnv 0x00486930
int* __fastcall FUN_00486930(int* self, FUN_00486930_arg aArg)
{
    FUN_005890c0(self, aArg);
    *self = (int)&DAT_01031fac;
    return self;
}

struct S00486ab0
{
    const char* p;
    void FUN_00486ee0(unsigned int, bool);
    S00486ab0* Construct(unsigned int n, bool b);
};
// Calls FUN_00486ee0 with n and b, sets p to "0lH", and returns this.
// @fnv 0x00486ab0
S00486ab0* S00486ab0::Construct(unsigned int auiValue, bool b)
{
    FUN_00486ee0(auiValue, b);
    p = "0lH";
    return this;
}

// @fnv 0x0048ce80
void __fastcall ClearString(char* this_ptr)
{
    ((BSStringT<char>*)(this_ptr + 4))->Set(0, 0);
}

struct S00551440
{
    char pad[0x24];
    unsigned char flags;
    void FUN_00551440(bool v);
};
// Sets or clears bit 0x10 in the flags byte according to v.
// @fnv 0x00551440
void S00551440::FUN_00551440(bool v)
{
    if (v)
        flags |= 0x10;
    else
        flags &= ~0x10;
}

struct FUN_00576d30_shell : public TESForm
{
    bool FUN_00576d30();
};

// @fnv 0x00576d30
bool FUN_00576d30_shell::FUN_00576d30()
{
    return (m_uiFormFlags & 0x200000) ? true : false;
}

struct ListX
{
    ~ListX();
    char d[8];
};
struct List_009e03e0
{
    void RemoveAll();
};
struct FUN_00483630_slg
{
    void FinalizeForm(TESForm*);
};
extern int DAT_011c54bc;
void __cdecl FUN_00483b80();
struct FUN_00483630_holder
{
    char pad[0xc];
    ListX l;
    virtual ~FUN_00483630_holder();
};
// @fnv 0x00483630
FUN_00483630_holder::~FUN_00483630_holder()
{
    ((TESForm*)this)->UpdateFormChangeFlags();
    ((List_009e03e0*)&l)->RemoveAll();
    if (!((TESForm*)this)->IsTemporary() && g_TESSaveLoadGame)
    {
        g_TESSaveLoadGame->HasFormChanges((TESForm*)this, false);
        ((FUN_00483630_slg*)g_TESSaveLoadGame)->FinalizeForm((TESForm*)this);
    }
    if (!((TESForm*)this)->IsTemporary() && g_BGSSaveLoadGame)
        g_BGSSaveLoadGame->HasFormChanges((TESForm*)this);
    if (--DAT_011c54bc == 0)
        FUN_00483b80();
}

struct FUN_00483c70_shell : public TESForm
{
    void FUN_00483c70();
};

struct TESTopicInfo;
struct Arr
{
    unsigned int* GetAt(int);
};
struct DH
{
    void FUN_004696f0(unsigned int);
};
extern DH* g_dataHandler;
// @fnv 0x00483c70
void FUN_00483c70_shell::FUN_00483c70()
{
    if (IsTemporary())
        return;
    if (ms_pFormIDMap)
        ((NiTPointerMap<unsigned int, void*>*)ms_pFormIDMap)->RemoveAt(*(unsigned int*)((char*)this + 0xc));
    for (unsigned int iIndex = 0; ms_pAllForms && iIndex < ((TESForm*)ms_pAllForms)->GetFormID(); iIndex++)
    {
        if (*((Arr*)ms_pAllForms)->GetAt(iIndex) == (unsigned int)this)
        {
            ((NiTLargeArray<TESTopicInfo*, NiTMallocInterface<TESTopicInfo*> >*)ms_pAllForms)->RemoveAt(iIndex);
            break;
        }
    }
    if (g_dataHandler)
        g_dataHandler->FUN_004696f0(*(unsigned int*)((char*)this + 0xc));
}

struct FUN_00485d50_slg
{
    bool GetLoading();
    unsigned int FUN_00857bf0(unsigned int);
};
struct FUN_00485d50_file
{
    TESFile* GetMasterFile(unsigned int);
    unsigned char GetFileCompileIndex();
};
// @fnv 0x00485d50
void ResolveFormID(unsigned int* aiID, TESFile* apFile)
{
    if (((FUN_00485d50_slg*)g_TESSaveLoadGame)->GetLoading())
    {
        *aiID = ((FUN_00485d50_slg*)g_TESSaveLoadGame)->FUN_00857bf0(*aiID);
    }
    else if (!TESForm::IsReservedFormID(*aiID))
    {
        if (apFile)
        {
            TESFile* pMasterFile = ((FUN_00485d50_file*)apFile)->GetMasterFile((*aiID >> 24) + 1);
            if (pMasterFile)
            {
                *aiID = (((FUN_00485d50_file*)pMasterFile)->GetFileCompileIndex() << 24) | (*aiID & 0xffffff);
            }
            else
            {
                *aiID = (((FUN_00485d50_file*)apFile)->GetFileCompileIndex() << 24) | (*aiID & 0xffffff);
            }
        }
    }
}

struct NiFormArray;
struct PerkEntryConditionSet;
struct TESIdleForm;
struct TESModel;
struct TESModelTextureSwap;
struct TESObject;
struct TESObjectREFR;
struct FileEntryList;
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
struct FUN_005ffbf0_shell : public IdleAnimationManager
{
    void AddIdleToArray(TESIdleForm*);
};

struct NiTPrimitiveArray_unsigned_int_
{
    unsigned int AddFirstEmpty(const unsigned int&);
};
// @fnv 0x005ffbf0
void FUN_005ffbf0_shell::AddIdleToArray(TESIdleForm* apIdle)
{
    if (apIdle)
        ((NiTPrimitiveArray_unsigned_int_*)m_acIdleName)->AddFirstEmpty((const unsigned int&)apIdle);
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
struct SpellItem;
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
struct FUN_004011d0_shell : public TESForm
{
    bool FUN_004011d0();
};

// @fnv 0x004011d0
bool FUN_004011d0_shell::FUN_004011d0()
{
    return (m_uiFormFlags & 0x20000) ? true : false;
}

namespace fnv_004011f0 {
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
struct SpellItem;
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
struct FUN_004011f0_shell : public TESForm
{
    bool FUN_004011f0();
};

// @fnv 0x004011f0
bool FUN_004011f0_shell::FUN_004011f0()
{
    return (m_uiFormFlags & 0x80000) ? true : false;
}
}  // namespace fnv_004011f0

struct S3c60
{
    int GetArchetype(void);
    int FUN_00408a40(void);
};

extern "C" int __cdecl GetEntryByIndex(int);

// @fnv 0x00408a40
int S3c60::FUN_00408a40()
{
    return GetEntryByIndex(GetArchetype());
}

extern unsigned char DAT_011c3c0d;

// @fnv 0x00456c70
unsigned char FUN_00456c70()
{
    return DAT_011c3c0d;
}

struct Base5a
{
    virtual ~Base5a();
};

void Deallocate(void* memory);

struct FUN_00483600_holder : Base5a
{
    void* DestroyHolder(unsigned int flags);
};

// Runs the base destructor, frees this via Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00483600
void* FUN_00483600_holder::DestroyHolder(unsigned int flags)
{
    Base5a::~Base5a();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_00484610_shell
{
    int _pad0;
    int _pad1;
    unsigned int m_uiFormFlags;
    void SetFlag2000(bool value);
};

// @fnv 0x00484610
void FUN_00484610_shell::SetFlag2000(bool abSet)
{
    if (abSet)
        m_uiFormFlags |= 0x2000;
    else
        m_uiFormFlags &= ~0x2000;
}

struct FUN_004849d0_shell
{
    unsigned int m0;
    unsigned int m1;
    unsigned int m_uiFormFlags;
    void SetFlag200(bool abVal);
};

// @fnv 0x004849d0
void FUN_004849d0_shell::SetFlag200(bool abVal)
{
    if (abVal)
        m_uiFormFlags |= 0x200;
    else
        m_uiFormFlags &= ~0x200;
}

struct FUN_00484bf0_shell
{
    unsigned short __thiscall FUN_00484bf0(unsigned int aiFlags);
};

// Returns 4 when bit 0 of aiFlags is set, otherwise 0.
// @fnv 0x00484bf0
unsigned short __thiscall FUN_00484bf0_shell::FUN_00484bf0(unsigned int aiFlags)
{
    unsigned short isize = 0;
    if (aiFlags & 1)
        isize += 4;
    return isize;
}

extern unsigned int kGroupFormType;

struct FUN_004854e0_shell : TESForm
{
    bool IsGroupFormOfType(FormRecordHeader* apGroupFORM, bool abAllowParentGroups, bool abCurrentOnly);
};

// Returns true if apGroupFORM is a group form with form ID 0 whose flags match the value indexed by this form's type.
// @fnv 0x004854e0
bool FUN_004854e0_shell::IsGroupFormOfType(FormRecordHeader* apGroupFORM, bool abAllowParentGroups, bool abCurrentOnly)
{
    bool bretval = false;
    if (apGroupFORM && apGroupFORM->form == kGroupFormType && apGroupFORM->iFormID == 0)
    {
        if (apGroupFORM->flags == *(unsigned int*)(this->GetFormType() * 0xc + 0x1187008))
            bretval = true;
    }
    return bretval;
}

extern "C" void __cdecl AppendChunk(int, int, int);

// @fnv 0x004856d0
void __cdecl FUN_004856d0(int arg)
{
    AppendChunk(arg, 0, 0);
}

void __cdecl AppendChunk(void* a1, void* a2, void* a3);

// @fnv 0x004856f0
void __cdecl FUN_004856f0(void* apArg1, void* apArg2, void* apArg3)
{
    AppendChunk(apArg1, apArg2, apArg3);
}

void __cdecl FUN_00485750(void* arg0, void* arg1, void* arg2);

// @fnv 0x00485710
void __cdecl FUN_00485710(void* arg0, void* arg1, void* arg2)
{
    FUN_00485750(arg0, arg1, arg2);
}

extern void __cdecl FUN_00485820(void*, void*, void*);

// @fnv 0x00485730
void __cdecl FUN_00485730(void* apArg1, void* apArg2, void* apArg3)
{
    FUN_00485820(apArg1, apArg2, apArg3);
}

extern void* DAT_011c54cc;
void __cdecl Deallocate(void*);

struct FUN_00485b30_shell
{
    void ResetGlobalPointer();
};

// Frees the pointer stored in DAT_011c54cc and sets it to null.
// @fnv 0x00485b30
void FUN_00485b30_shell::ResetGlobalPointer()
{
    Deallocate(DAT_011c54cc);
    DAT_011c54cc = 0;
}

struct FUN_00485e00_shell
{
    void __thiscall FUN_00485e20(int, int);
    void __thiscall FUN_00485e00();
};

// @fnv 0x00485e00
void __thiscall FUN_00485e00_shell::FUN_00485e00()
{
    FUN_00485e20(0, 0);
}

struct NodePoolView
{
    void* AddHead();
};

struct BGSSaveLoadChangesMap
{
    int m_auiShapeKeys[3];
    NodePoolView m_NodePoolView;
    void* FUN_00486a90();
};

// @fnv 0x00486a90
void* BGSSaveLoadChangesMap::FUN_00486a90()
{
    return m_NodePoolView.AddHead();
}

extern int DAT_0118a870[];

struct FUN_0051dab0_shell
{
    int __thiscall GetIndexedValue();
};

// @fnv 0x0051dab0
int __thiscall FUN_0051dab0_shell::GetIndexedValue()
{
    return DAT_0118a870[*(char*)(((char*)this) + 0xf4)];
}

struct ArrSI
{
    unsigned int GetFlags(void);
};

struct FUN_005516c0
{
    bool IsCellPersistent();
};

// Returns true if GetFlags() has bit 0x400 set, otherwise false.
// @fnv 0x005516c0
bool FUN_005516c0::IsCellPersistent()
{
    if (((ArrSI*)this)->GetFlags() & 0x400)
    {
        return true;
    }
    else
    {
        return false;
    }
}

extern "C" void __cdecl FUN_005548a0(int);

struct FUN_00554880_shell
{
    void __thiscall FUN_00554880(unsigned char arg);
};

// @fnv 0x00554880
void __thiscall FUN_00554880_shell::FUN_00554880(unsigned char arg)
{
    FUN_005548a0(arg);
}

extern unsigned char __cdecl FUN_00588a60(unsigned char);

struct FUN_00588a40_shell
{
    unsigned char __thiscall FUN_00588a40(unsigned char arg);
};

// @fnv 0x00588a40
unsigned char __thiscall FUN_00588a40_shell::FUN_00588a40(unsigned char arg)
{
    return FUN_00588a60(arg);
}

namespace fnv_005e9690 {
extern "C" void __cdecl FUN_004856d0(int);

struct FUN_005e9690_shell
{
    void __thiscall FUN_005e9690();
};

// @fnv 0x005e9690
void __thiscall FUN_005e9690_shell::FUN_005e9690()
{
    FUN_004856d0(0x464b5250);
}
}  // namespace fnv_005e9690

struct FUN_0061bbd0_shell
{
    unsigned char __thiscall FUN_0061bbd0(unsigned char param);
};

extern unsigned char __cdecl FUN_0061bbf0(unsigned char);

// @fnv 0x0061bbd0
unsigned char __thiscall FUN_0061bbd0_shell::FUN_0061bbd0(unsigned char param)
{
    return FUN_0061bbf0(param);
}

struct FUN_00621b00_shell
{
    float __thiscall FUN_00621b00();
};

// @fnv 0x00621b00
float __thiscall FUN_00621b00_shell::FUN_00621b00()
{
    return *(float*)((char*)this + 0x10);
}

struct FUN_008df040_shell
{
    unsigned char __thiscall FUN_008df040();
};

// @fnv 0x008df040
unsigned char __thiscall FUN_008df040_shell::FUN_008df040()
{
    return ((unsigned char*)this)[0x80];
}

struct FUN_004011b0_shell
{
    unsigned int m_BaseFormComponent;  // +0x00
    unsigned int m_Padding;            // +0x04
    unsigned int m_uiFormFlags;        // +0x08
    bool IsFlagSet() const;
};

// @fnv 0x004011b0
bool FUN_004011b0_shell::IsFlagSet() const
{
    return (m_uiFormFlags & 0x10000) ? true : false;
}

struct FUN_00401210_shell
{
    int _pad0;
    int _pad1;
    unsigned int m_uiFormFlags;
    bool HasFlag() const;
};

// @fnv 0x00401210
bool FUN_00401210_shell::HasFlag() const
{
    return (m_uiFormFlags & 0x2000000) ? true : false;
}

struct FUN_00401250_shell
{
    unsigned int m_BaseFormComponent[2];
    unsigned int m_uiFormFlags;
    bool IsFlag200Set();
};

// @fnv 0x00401250
bool FUN_00401250_shell::IsFlag200Set()
{
    return (m_uiFormFlags & 0x200) ? true : false;
}

struct FUN_00484a70_shell
{
    int m_00;
    int m_04;
    int m_08;
    void FUN_00484a70(bool value);
};

// Sets or clears bit 0x80 in m_08 according to value.
// @fnv 0x00484a70
void FUN_00484a70_shell::FUN_00484a70(bool abSet)
{
    if (abSet)
        m_08 |= 0x80;
    else
        m_08 &= ~0x80;
}

struct BSExtraData
{
    virtual ~BSExtraData();
    int _a;
    int _b;
};
struct FUN_004362a0 : BSExtraData
{
    int _c;
    ~FUN_004362a0();
};
// Destructor that calls TESForm::ClearData on the _c member.
// @fnv 0x004362a0
FUN_004362a0::~FUN_004362a0()
{
    ((TESForm*)&_c)->TESForm::ClearData();
}

namespace fnv_004363c0 {
struct BSExtraData
{
    virtual ~BSExtraData();
};
struct FUN_004363c0
{
    BSExtraData data;
    int _4;
    int _8;
    int _c;
    ~FUN_004363c0();
};
// @fnv 0x004363c0
FUN_004363c0::~FUN_004363c0()
{
    ((TESForm*)((char*)this + 12))->TESForm::ClearData();
}
}  // namespace fnv_004363c0

namespace fnv_004364e0 {
struct BSExtraData
{
    virtual ~BSExtraData();
    int _04;
    int _08;
};
struct SoundPlaybackHandle
{
    ~SoundPlaybackHandle();
};
struct FUN_004364e0 : BSExtraData
{
    SoundPlaybackHandle m;
    virtual ~FUN_004364e0();
};
// Destructor for a BSExtraData-derived object; destroys its member and the base class.
// @fnv 0x004364e0
FUN_004364e0::~FUN_004364e0()
{}
}  // namespace fnv_004364e0

namespace fnv_00436600 {
struct BSExtraData
{
    virtual ~BSExtraData();
};
struct FUN_00436600 : BSExtraData
{
    ~FUN_00436600();
};
// @fnv 0x00436600
FUN_00436600::~FUN_00436600()
{
    ((TESForm*)((char*)this + 12))->TESForm::ClearData();
}
}  // namespace fnv_00436600

namespace fnv_00436720 {
struct BSExtraData
{
    virtual ~BSExtraData();
    int _a;
    int _b;
};
struct FUN_00436720 : BSExtraData
{
    int _f0c;
    ~FUN_00436720();
};
// @fnv 0x00436720
FUN_00436720::~FUN_00436720()
{
    ((TESForm*)&_f0c)->TESForm::ClearData();
}
}  // namespace fnv_00436720

extern int DAT_00ffffff;
struct FUN_004696f0_shell
{
    void FUN_004696f0(unsigned int value);
};
// @fnv 0x004696f0
void FUN_004696f0_shell::FUN_004696f0(unsigned int value)
{
    unsigned int desired;
    desired = *(unsigned int*)((char*)this + 0x218);
    desired = 0xff;
    if (value && (value >> 0x18) == desired && !((unsigned char*)this)[0x621] &&
        value < *(unsigned int*)((char*)this + 0x208) && (value & (unsigned int)&DAT_00ffffff) > 0x7ff)
        *(unsigned int*)((char*)this + 0x208) = value;
}

template <int N> struct EndianSizeTag
{
};
void __cdecl BSEndian(unsigned char*, EndianSizeTag<1>);
void __cdecl BSEndian(unsigned short*, EndianSizeTag<2>);
void __cdecl BSEndian(int*, EndianSizeTag<4>);
struct FUN_00470650_shell
{
    void __thiscall FUN_00470650();
};
// @fnv 0x00470650
void __thiscall FUN_00470650_shell::FUN_00470650()
{
    BSEndian((unsigned char*)this, EndianSizeTag<1>());
    BSEndian((unsigned char*)((char*)this + 4), EndianSizeTag<1>());
    BSEndian((unsigned char*)((char*)this + 8), EndianSizeTag<1>());
    BSEndian((unsigned char*)((char*)this + 12), EndianSizeTag<1>());
    BSEndian((unsigned char*)((char*)this + 16), EndianSizeTag<1>());
    BSEndian((unsigned short*)((char*)this + 20), EndianSizeTag<2>());
    BSEndian((unsigned short*)((char*)this + 22), EndianSizeTag<2>());
}

struct DummyPointerMap
{
    bool GetAt(unsigned int, unsigned int&) const;
};
// Looks up aiSearchID in the form map and returns the stored TESForm pointer, or 0 if the map is null or has no entry.
// @fnv 0x004839c0
TESForm* LookupFormByID(unsigned int aiSearchID)
{
    TESForm* pTempForm = 0;
    if (TESForm::ms_pFormIDMap &&
        ((DummyPointerMap*)TESForm::ms_pFormIDMap)->GetAt(aiSearchID, (unsigned int&)pTempForm))
        return pTempForm;
    else
        return 0;
}

struct TESFile_Proxy
{
    TES_RETURN_CODE RunProbe(TESForm* pForm);
};
struct FUN_00483d20_shell : TESForm
{
    unsigned char SaveIfNotTemporary(TESFile* apFile);
};
// @fnv 0x00483d20
unsigned char FUN_00483d20_shell::SaveIfNotTemporary(TESFile* apFile)
{
    TES_RETURN_CODE eRetVal;
    if (IsTemporary())
        return 0;
    SaveForm();
    eRetVal = ((TESFile_Proxy*)apFile)->RunProbe(this);
    return eRetVal == 0;
}

struct TESFileShell
{
    void FUN_00472e60(TESForm* p);
    void FUN_00473090();
};
struct FUN_00483fc0_shell : TESForm
{
    bool WriteToFile(TESFile* apFile);
};
// @fnv 0x00483fc0
bool FUN_00483fc0_shell::WriteToFile(TESFile* apFile)
{
    if (IsTemporary())
        return false;
    if (IsDeleted())
    {
        ((TESFileShell*)apFile)->FUN_00472e60(this);
        ((TESFileShell*)apFile)->FUN_00473090();
        return true;
    }
    return AppendForm(apFile);
}

struct Fake84860
{
    int _pad;
    unsigned int _flags;
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
    virtual void v17()
    {}
    virtual void v18(int)
    {}
    void FUN_00484860(bool);
};
// Sets or clears bit 0x400 in _flags according to abQuest, then calls v18(1).
// @fnv 0x00484860
void Fake84860::FUN_00484860(bool abQuest)
{
    if (abQuest)
    {
        _flags |= 0x400;
    }
    else
    {
        _flags &= ~0x400;
    }
    v18(1);
}

struct PC7d
{
    void FUN_00484ce0(unsigned int, int);
    void FUN_00484c20(unsigned int);
};
// If bit 0 of aiFlags is set, calls FUN_00484ce0 on the object at this+8 with 4.
// @fnv 0x00484c20
void PC7d::FUN_00484c20(unsigned int aiFlags)
{
    if (aiFlags & 1)
        FUN_00484ce0((unsigned int)((char*)this + 8), 4);
}

struct SGL_Stub
{
    void __thiscall FUN_00857aa0(unsigned int*, int);
};
struct FUN_00484d40_Host
{
    void __thiscall FUN_00484d40(unsigned int* apNumericID, int aiSize);
};
// Forwards the numeric ID buffer and its size to the save/load game object's handler.
// @fnv 0x00484d40
void __thiscall FUN_00484d40_Host::FUN_00484d40(unsigned int* apNumericID, int aiSize)
{
    ((SGL_Stub*)g_TESSaveLoadGame)->FUN_00857aa0(apNumericID, aiSize);
}

struct BGSSaveFormBuffer
{
    void SaveData(void*, int, int);
};
struct FakeForm
{
    char _pad[8];
    int _v08;
    void SaveIfChanged(BGSSaveFormBuffer*);
};
// If the form buffer reports change flags for bit 1, saves the 4-byte value at _v08 into the buffer.
// @fnv 0x00484d60
void FakeForm::SaveIfChanged(BGSSaveFormBuffer* buffer)
{
    if (((BGSLoadFormBuffer*)buffer)->GetChangeFlags(1))
        buffer->SaveData(&_v08, 4, 0);
}

struct FUN_00485130_shell
{
    void WarnCopyUnsupported(TESForm* apCopy);
};
struct TESForm_Proxy40e30
{
    char const* FUN_00440e30();
};
int _FNV_Warning(char const*, char const*, char const*);
// Logs a warning that copying the given form is unsupported, printing its name and type name.
// @fnv 0x00485130
void FUN_00485130_shell::WarnCopyUnsupported(TESForm* apCopy)
{
    _FNV_Warning("FORMS: Trying to copy form \"%s\".\r\nNo copy function for %s form types.\r\n", apCopy->GetName(),
                 ((TESForm_Proxy40e30*)apCopy)->FUN_00440e30());
}

void _FNV_Warning(const char*, ...);
struct Fake440e30
{
    const char* FUN_00440e30();
};
struct Mid485170
{
    bool FUN_00485170(TESForm*);
};
// Warns that no compare function exists for the form types and returns false.
// @fnv 0x00485170
bool Mid485170::FUN_00485170(TESForm* apCopy)
{
    _FNV_Warning("FORMS: Trying to compare form \"%s\".\r\nNo compare function for %s form types.\r\n",
                 apCopy->GetName(), ((Fake440e30*)apCopy)->FUN_00440e30());
    return false;
}

extern void* DAT_011c54cc;
extern int DAT_011c54d0;
bool FUN_00401500();
struct MyForm
{
    int _00;
    int length;
    void FUN_00470650();
};
struct Holder : public TESForm
{
    void FUN_00485680();
};
// @fnv 0x00485680
void Holder::FUN_00485680()
{
    MyForm* pForm;
    if (IsTemporary())
        return;
    pForm = (MyForm*)DAT_011c54cc;
    pForm->length = DAT_011c54d0 - 0x18;
    if (FUN_00401500())
        pForm->FUN_00470650();
}

struct FUN_00485b60
{
    unsigned int FUN_00485bc0();
    bool FUN_00485be0(unsigned int);
};
// Returns true when the low 24 bits of aiID equal the value returned by FUN_00485bc0, otherwise false.
// @fnv 0x00485be0
bool FUN_00485b60::FUN_00485be0(unsigned int aiID)
{
    if ((aiID & 0x00FFFFFF) != FUN_00485bc0())
        return false;
    return true;
}

void _Deallocate(void*);
struct Unnamed00486960
{
    void FUN_00486a00();
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_00486a00, then deallocates this if flags has bit 1 set, and returns this.
// @fnv 0x00486960
void* Unnamed00486960::DestroyIfFlagged(unsigned int flags)
{
    FUN_00486a00();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

extern int DAT_0101ca98;
void _NiFreeAlias(void*);
struct MyMap
{
    void RemoveAll();
};
struct S_486a60
{
    void* vfptr;
    int unk4;
    void* entries;
    void FUN_00486a60();
};
// @fnv 0x00486a60
void S_486a60::FUN_00486a60()
{
    vfptr = (void*)&DAT_0101ca98;
    ((MyMap*)this)->RemoveAll();
    _NiFreeAlias(entries);
}

struct TESModel
{
    unsigned int GetModelLength() const;
};
struct FNStub
{
    char const* GetFullName();
};
void __cdecl FUN_004856f0(unsigned int, void*, unsigned int);
struct FUN_00487010_shell
{
    void FUN_00487010();
};
// @fnv 0x00487010
void FUN_00487010_shell::FUN_00487010()
{
    if (((TESModel*)this)->GetModelLength())
        FUN_004856f0(0x4C4C5546, (void*)((FNStub*)this)->GetFullName(), ((TESModel*)this)->GetModelLength() + 1);
}

struct FUN_00549580_shell
{
    bool FUN_00549580() const;
};

// @fnv 0x00549580
bool FUN_00549580_shell::FUN_00549580() const
{
    return (((const TESForm*)this)->m_uiFormFlags & 64) ? true : false;
}

struct FUN_009f87b0_shell
{
    void FUN_006796c0();
    void FUN_009f9720();
    unsigned int m_0x88;
    unsigned int m_0x8c;
};

TESForm* __cdecl GetFormByID(unsigned int);

// @fnv 0x009f9720
void FUN_009f87b0_shell::FUN_009f9720()
{
    FUN_006796c0();
    unsigned int v3 = *(unsigned int*)((char*)this + 0x88);
    if (v3)
        *(unsigned int*)((char*)this + 0x88) = (unsigned int)GetFormByID(v3);
    unsigned int v8c = *(unsigned int*)((char*)this + 0x8c);
    if (v8c)
        *(unsigned int*)((char*)this + 0x8c) = (unsigned int)GetFormByID(v8c);
}

struct FUN_004846e0_shell
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
    virtual void v18(int);
    unsigned int _4;
    unsigned int _8;
    void FUN_004846e0(bool);
};
// @fnv 0x004846e0
void FUN_004846e0_shell::FUN_004846e0(bool abSet)
{
    if (abSet)
        _8 |= 0x4000000;
    else
        _8 &= 0xFBFFFFFF;
    v18(1);
}

namespace fnv_00483720 {
struct Actor;
struct BGSAcousticSpace;
struct BGSEncounterZone;
struct BGSLightingTemplate;
struct BGSMusicType;
struct BGSSaveFormBuffer;
struct BSFile;
struct BSMultiBoundNode;
struct BSPortalGraph;
struct CellMopp;
struct CellRecord;
struct ExteriorData;
struct ExtraDataList;
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
struct FormComponentArray
{
    void InitializeFromForm(TESForm*);
    void ClearFormComponentArray();
    void InitializeDataAllComponents();
    void ClearDataAllComponents();
    void CopyComponentData(FormComponentArray*);
    bool AreComponentsEqual(FormComponentArray*);
    void* __vecDelDtor(unsigned int);
    char m_pComponents[152];
};
typedef char _sizecheck_FormComponentCollection[sizeof(FormComponentArray) == 152 ? 1 : -1];
struct FUN_00483720_shell : public TESForm
{
    void ClearFormData();
};

void __fastcall ClearString(char*);
struct FUN_0047c050
{
    void* m_pComponents[38];
    FUN_0047c050();
    ~FUN_0047c050();
    void InitializeFromForm(TESForm*);
    void CallElements();
};

// @fnv 0x00483720
void FUN_00483720_shell::ClearFormData()
{
    switch (GetFormType())
    {
    case 0x39: {
        TESObjectCELL* pthiscell = (TESObjectCELL*)this;
        ClearString((char*)pthiscell + 0x18);
        ((TESForm*)pthiscell)->TESForm::ClearData();
        break;
    }
    case 0x11:
    case 0x3a:
    case 0x3b:
    case 0x3c:
    case 0x3d:
    case 0x3e:
    case 0x3f:
    case 0x40:
    case 0x42:
    case 0x43:
    case 0x49:
    case 0x69:
        TESForm::ClearData();
        break;
    default: {
        FUN_0047c050 components;
        components.InitializeFromForm(this);
        components.CallElements();
        break;
    }
    }
}
}  // namespace fnv_00483720

namespace fnv_00483870 {
struct Actor;
struct BGSAcousticSpace;
struct BGSEncounterZone;
struct BGSLightingTemplate;
struct BGSMusicType;
struct BGSSaveFormBuffer;
struct BSFile;
struct BSMultiBoundNode;
struct BSPortalGraph;
struct CellMopp;
struct CellRecord;
struct ExteriorData;
struct ExtraDataList;
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
struct FormComponentArray
{
    void InitializeFromForm(TESForm*);
    void ClearFormComponentArray();
    void InitializeDataAllComponents();
    void ClearDataAllComponents();
    void CopyComponentData(FormComponentArray*);
    bool AreComponentsEqual(FormComponentArray*);
    void* __vecDelDtor(unsigned int);
    char m_pComponents[152];
};
typedef char _sizecheck_FormComponentCollection[sizeof(FormComponentArray) == 152 ? 1 : -1];
struct FUN_00483870_shell : public TESForm
{
    void FUN_00483870();
};

struct Holder_47c5b0
{
    void FUN_0047c5b0();
};
struct FUN_0047c050
{
    int m_pComponents[38];
    FUN_0047c050();
    ~FUN_0047c050();
};

// @fnv 0x00483870
void FUN_00483870_shell::FUN_00483870()
{
    switch (GetFormType())
    {
    case 0x39: {
        TESObjectCELL* pthiscell = (TESObjectCELL*)this;
        ((TESForm*)((char*)pthiscell + 0x18))->TESForm::ClearData();
        ((TESForm*)pthiscell)->TESForm::ClearData();
        break;
    }
    case 0x11:
    case 0x3a:
    case 0x3b:
    case 0x3c:
    case 0x3d:
    case 0x3e:
    case 0x3f:
    case 0x40:
    case 0x42:
    case 0x43:
    case 0x49:
    case 0x69:
        TESForm::ClearData();
        break;
    default: {
        FUN_0047c050 components;
        ((FormComponentArray*)&components)->InitializeFromForm(this);
        ((Holder_47c5b0*)&components)->FUN_0047c5b0();
        break;
    }
    }
}
}  // namespace fnv_00483870

namespace fnv_00484730 {
struct TESObjectREFR;
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
struct TESDescription : public BaseFormComponent
{
    virtual char* GetDescription(TESForm*, int);
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    static void LoadDescriptionAtOffset(TESDescription*, int);
    static void ReadDescriptionFromFile(TESDescription*, TESFile*);
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetDescriptionLength(TESForm*);
    unsigned int GetDescriptionLength();
    static char* GetDescription(TESForm*);
    unsigned long GetDescriptionFileOffset();
    void SetDescriptionFileOffset(unsigned long);
    void LoadDescriptionForForm(TESForm*, int);
    void UnLoadDescription();
    void SetDescription(char*);
    unsigned long m_uiDescriptionFileOffset;
};
typedef char _sizecheck_TESDescription[sizeof(TESDescription) == 8 ? 1 : -1];
struct TESTexture : public BaseFormComponent
{
    virtual unsigned int GetTexturePathLength();
    virtual char* NormalizeTextureFilePath(void*);
    virtual char* GetRegularTextureFilePath(void*);
    virtual char* GetTextureResourcePath();
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save(int);
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetTextureNameLength(TESForm*);
    unsigned int GetTextureNameLength();
    static char* GetTextureResourceName(TESForm*, TESObjectREFR*);
    char* GetTextureResourceName();
    void AssignTextureName(char*);
    static void NormalizeTextureFilePath(char*, char*);
    static char* NormalizeTextureFilePath(void*, char*);
    static char* NormalFileToRegularFile(void*, char*);
    static void GetRegularTextureFilePath(char*, char*);
    static char* GetRegularTextureFilePath(void*, char*);
    static void ConvertTexturePath(char*, char*);
    static bool IsTextureChunk(int);
    static void ReadTextureData(TESTexture*, TESFile*);
    static char* GetMessageIconName(TESForm*, TESObjectREFR*);
    void* __vecDelDtor(unsigned int);
    char FullNameComponent[8];
};
typedef char _sizecheck_TESTexture[sizeof(TESTexture) == 12 ? 1 : -1];
struct TESIcon : public TESTexture
{
    virtual char* GetTextureResourcePath();
    void* __vecDelDtor(unsigned int);
};
typedef char _sizecheck_TESIcon[sizeof(TESIcon) == 12 ? 1 : -1];
struct ActorValueInfo : public TESForm, public TESFullName, public TESDescription, public TESIcon
{
    virtual void __vslot_10();
    void SetEnumerated(int, ...);
    char* GetEnumeratedName(int);
    virtual void Save();
    virtual void InitItem();
    virtual bool Load(TESFile*);
    virtual void Copy(TESForm*);
    virtual bool Compare(TESForm*);
    virtual char* GetTextureResourcePath();
    static unsigned int GetActorValueFormID(int);
    static int GetAffectedActorValue(unsigned int);
    char* m_pName;
    char m_cAbbreviation[8];
    unsigned int uFlags;
    int m_iSection;
    int* m_pDerivedValueFunction;
    int* m_pActorValueMapping;
    int* m_pActorValueChangedCallback;
    int m_iEnumeratedValueCount;
    char m_aiEnumeratedValues[60];
    int m_iEnumeratedNameCount;
    char m_apEnumeratedNames[40];
};
typedef char _sizecheck_ActorValueInfo[sizeof(ActorValueInfo) == 196 ? 1 : -1];
struct FUN_00484730_shell : public TESForm
{
    void FUN_00484730(bool);
};

struct Pathing
{
    bool FUN_00460340();
};
struct FormArray
{
    unsigned int AddElement(void* const&);
};
struct Arr
{
    unsigned int* GetAt(int);
};
struct TESTopicInfo;
struct NiTLargeArray_TESTopicInfo
{
    TESTopicInfo* RemoveAt(unsigned int);
};

// @fnv 0x00484730
void FUN_00484730_shell::FUN_00484730(bool abAltered)
{
    if (abAltered)
    {
        if (!((Pathing*)this)->FUN_00460340() && !IsTemporary() && ms_pAllForms)
        {
            bool bAddToList = true;
            for (unsigned int iIndex = 0; iIndex < ((TESForm*)ms_pAllForms)->GetFormID(); iIndex++)
            {
                if (*((Arr*)ms_pAllForms)->GetAt(iIndex) == (unsigned int)this)
                {
                    bAddToList = false;
                    break;
                }
            }
            if (bAddToList)
            {
                ((FormArray*)ms_pAllForms)->AddElement((void*)this);
            }
        }
        *(unsigned int*)((char*)this + 8) |= 2;
    }
    else
    {
        if (((Pathing*)this)->FUN_00460340() && ms_pAllForms)
        {
            for (unsigned int iIndex = 0; iIndex < ((TESForm*)ms_pAllForms)->GetFormID(); iIndex++)
            {
                if (*((Arr*)ms_pAllForms)->GetAt(iIndex) == (unsigned int)this)
                {
                    ((NiTLargeArray_TESTopicInfo*)ms_pAllForms)->RemoveAt(iIndex);
                    break;
                }
            }
        }
        *(unsigned int*)((char*)this + 8) &= ~2u;
    }
}
}  // namespace fnv_00484730

struct BGSSaveFormBuffer;
struct TESAttributes : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    unsigned int Save(void*);
    unsigned int Load(void*);
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    unsigned int GetAttributeDataSize();
    unsigned char GetAttributeValue(int);
    void SetAttributeValue(int, unsigned char, bool);
    unsigned char GetAttributeStrength();
    unsigned char GetPerception();
    unsigned char GetEndurance();
    unsigned char GetCharisma();
    unsigned char GetIntelligence();
    unsigned char GetAgility();
    unsigned char GetLuck();
    void SetStrength(unsigned char);
    void SetPerception(unsigned char);
    void SetEndurance(unsigned char);
    void SetCharisma(unsigned char);
    void SetIntelligence(unsigned char);
    void SetAgility(unsigned char);
    void SetLuck(unsigned char);
    unsigned short GetSaveSize(unsigned int);
    void SaveGame(BGSSaveFormBuffer*);
    void SaveGame(unsigned int);
    void LoadGame(BGSLoadFormBuffer*);
    void LoadGame(unsigned int, unsigned int);
    void* __vecDelDtor(unsigned int);
    char cAttribute[7];
    char _pad_b[1];
};
typedef char _sizecheck_TESAttributes[sizeof(TESAttributes) == 12 ? 1 : -1];
struct BGSClipRoundsForm : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static int GetClipRounds(TESForm*);
    int GetClipRounds();
    void SetFormClipRounds(int);
    void* __vecDelDtor(unsigned int);
    unsigned char m_ucClipRounds;
    char _pad_5[3];
};
typedef char _sizecheck_BGSClipRoundsForm[sizeof(BGSClipRoundsForm) == 8 ? 1 : -1];
struct TESUsesForm : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static int GetFormUses(TESForm*);
    int GetFormUses();
    void SetFormUses(int);
    void* __vecDelDtor(unsigned int);
    unsigned char m_ucUses;
    char _pad_5[3];
};
typedef char _sizecheck_TESUsesForm[sizeof(TESUsesForm) == 8 ? 1 : -1];
struct TESQualityForm : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned char GetFormQuality(TESForm*);
    unsigned char GetFormQuality();
    void SetFormQuality(unsigned char);
    void* __vecDelDtor(unsigned int);
    unsigned char m_ucFormQuality;
    char _pad_5[3];
};
typedef char _sizecheck_TESQualityForm[sizeof(TESQualityForm) == 8 ? 1 : -1];
struct TESWeightForm : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static float GetWeightForForm(TESForm*, bool);
    float GetWeightForForm();
    void SetFormWeight(float);
    void* __vecDelDtor(unsigned int);
    float fWeight;
};
typedef char _sizecheck_TESWeightForm[sizeof(TESWeightForm) == 8 ? 1 : -1];
struct FUN_00486620_shell : public TESForm
{
    unsigned int FUN_00486620();
};

struct TESAttackDamageForm : public BaseFormComponent
{
    virtual void InitializeComponent();
};
struct TESHealthForm : public BaseFormComponent
{
    virtual void InitializeComponent();
};
struct FUN_009d2510_shell
{
    unsigned int FUN_009d2510();
};

// Sums the save sizes contributed by the form's Uses, Value, Health, Weight, Quality, AttackDamage, Attributes and ClipRounds components.
// @fnv 0x00486620
unsigned int FUN_00486620_shell::FUN_00486620()
{
    TESAttributes* pAttributes;
    BGSClipRoundsForm* pClipRounds;
    TESUsesForm* pUses;
    TESQualityForm* pQuality;
    TESWeightForm* pWeight;
    TESAttackDamageForm* pAttack;
    TESValueForm* pValue;
    unsigned int uiSaveSize;
    TESHealthForm* pHealth;
    pUses = dynamic_cast<TESUsesForm*>((TESForm*)this);
    pValue = dynamic_cast<TESValueForm*>((TESForm*)this);
    pHealth = dynamic_cast<TESHealthForm*>((TESForm*)this);
    pWeight = dynamic_cast<TESWeightForm*>((TESForm*)this);
    pQuality = dynamic_cast<TESQualityForm*>((TESForm*)this);
    pAttack = dynamic_cast<TESAttackDamageForm*>((TESForm*)this);
    pAttributes = dynamic_cast<TESAttributes*>((TESForm*)this);
    pClipRounds = dynamic_cast<BGSClipRoundsForm*>((TESForm*)this);
    uiSaveSize = 0;
    if (pUses)
        uiSaveSize += 1;
    if (pValue)
        uiSaveSize += 4;
    if (pHealth)
        uiSaveSize += 4;
    if (pWeight)
        uiSaveSize += 4;
    if (pQuality)
        uiSaveSize += 4;
    if (pAttack)
        uiSaveSize += 2;
    if (pAttributes)
        uiSaveSize += ((FUN_009d2510_shell*)pAttributes)->FUN_009d2510();
    if (pClipRounds)
        uiSaveSize += 1;
    return uiSaveSize;
}

struct NiTPointerMapRemoveAll
{
    void RemoveAll();
};
struct BSTCaseInsensitiveStringMapRemoveAll
{
    void RemoveAll();
};
struct FUN_00863db0_class
{
    void ClearItems();
};

// @fnv 0x00483b80
void FUN_00483b80()
{
    if (TESForm::ms_pFormIDMap)
    {
        ((NiTPointerMapRemoveAll*)TESForm::ms_pFormIDMap)->RemoveAll();
        delete TESForm::ms_pFormIDMap;
        TESForm::ms_pFormIDMap = 0;
    }
    if (TESForm::ms_pEditorIDMap)
    {
        ((BSTCaseInsensitiveStringMapRemoveAll*)TESForm::ms_pEditorIDMap)->RemoveAll();
        delete TESForm::ms_pEditorIDMap;
        TESForm::ms_pEditorIDMap = 0;
    }
    if (TESForm::ms_pAllForms)
    {
        ((FUN_00863db0_class*)TESForm::ms_pAllForms)->ClearItems();
        delete TESForm::ms_pAllForms;
        TESForm::ms_pAllForms = 0;
    }
}

namespace fnv_00485340 {
struct ArrSI
{
    unsigned int GetFlags();
};
struct Pathing
{
    bool FUN_00460340();
};
struct FUN_00485340_shell : public TESForm
{
    void FUN_00485340(BaseFormComponent* apCopyFC);
};
// Copies the form type, flags and a pathing state from apCopyFC into this form, marking it altered when the pathing state differs.
// @fnv 0x00485340
void FUN_00485340_shell::FUN_00485340(BaseFormComponent* apCopyFC)
{
    TESForm* pCopy = dynamic_cast<TESForm*>(apCopyFC);
    if (!pCopy)
        return;
    if (((Pathing*)this)->FUN_00460340() != ((Pathing*)pCopy)->FUN_00460340())
        SetAltered(((Pathing*)pCopy)->FUN_00460340());
    *((unsigned char*)this + 4) = pCopy->GetFormType();
    m_uiFormFlags = ((ArrSI*)pCopy)->GetFlags() & 0xffffbfff | (m_uiFormFlags & 0x4000);
}
}  // namespace fnv_00485340

namespace fnv_00436180 {
struct BSExtraData
{
    virtual ~BSExtraData();
};
struct FUN_00436180 : BSExtraData
{
    virtual ~FUN_00436180();
    void ClearData();
};
// Destructor that calls ClearData on the object at offset 0xc.
// @fnv 0x00436180
FUN_00436180::~FUN_00436180()
{
    ((FUN_00436180*)((char*)this + 0xc))->ClearData();
}
}  // namespace fnv_00436180

struct FUN_00484580_shell : TESForm
{
    void FUN_00484580(bool set);
};

struct TESSaveLoadGameLoader
{
    bool FUN_0047c850();
};

// @fnv 0x00484580
void FUN_00484580_shell::FUN_00484580(bool set)
{
    if (set)
    {
        if (!reinterpret_cast<TESSaveLoadGameLoader*>(g_TESSaveLoadGame)->FUN_0047c850())
            MarkAsModified(0x200000);
        ((unsigned int*)this)[2] |= 0x2000;
    }
    else
    {
        if (!reinterpret_cast<TESSaveLoadGameLoader*>(g_TESSaveLoadGame)->FUN_0047c850())
            MarkAsUnmodified(0x200000);
        ((unsigned int*)this)[2] &= ~0x2000;
    }
}

struct GroupEntry
{
    unsigned int form;
    unsigned int length;
    unsigned int flags;
    unsigned int iFormID;
    unsigned int m_uiVersionControlInfo;
    unsigned short m_usFormVersion;
    unsigned short m_usHeaderUnknown;
};
struct GroupData
{
    GroupEntry Data;
};
extern unsigned int kGroupFormType;
struct FUN_00485530_shell : TESForm
{
    void InitGroupForm(GroupEntry* apOutGroupFORM, GroupData* apParentGroup);
};
// @fnv 0x00485530
void FUN_00485530_shell::InitGroupForm(GroupEntry* apOutGroupFORM, GroupData* apParentGroup)
{
    if (apOutGroupFORM && !apParentGroup)
    {
        apOutGroupFORM->form = kGroupFormType;
        apOutGroupFORM->iFormID = 0;
        apOutGroupFORM->flags = *(unsigned int*)(0x1187008 + GetFormType() * 12);
        apOutGroupFORM->length = 0;
        apOutGroupFORM->m_uiVersionControlInfo = 0;
        apOutGroupFORM->m_usFormVersion = 0;
        apOutGroupFORM->m_usHeaderUnknown = 0;
    }
}

extern "C" void* __cdecl _NiMalloc(unsigned int size);
extern "C" void* __cdecl memset(void* dest, int value, unsigned int count);
int DAT_0101ca98;

struct FUN_00486990_shell
{
    int* pVT;
    int iCount;
    void* pBuffer;
    int iMax;
    FUN_00486990_shell(int iSize);
};

// Sets the vtable, stores iSize as the count, allocates iSize*4 bytes zeroed into pBuffer, and sets iMax to 0.
// @fnv 0x00486990
FUN_00486990_shell::FUN_00486990_shell(int iSize)
{
    pVT = &DAT_0101ca98;
    iCount = iSize;
    iMax = 0;
    int iByteCount = iCount << 2;
    pBuffer = _NiMalloc(iByteCount);
    memset(pBuffer, 0, iCount << 2);
}

namespace fnv_00486a00 {
struct S_486a60
{
    void FUN_00486a60();
    virtual ~S_486a60();
};
struct FUN_00486a00 : S_486a60
{
    void RemoveAll();
    ~FUN_00486a00();
};
// @fnv 0x00486a00
FUN_00486a00::~FUN_00486a00()
{
    RemoveAll();
}
}  // namespace fnv_00486a00

namespace fnv_004855a0 {
class ArrSI : public TESForm
{
  public:
    unsigned int GetFlags();
    void FUN_004855a0();
};

extern void* DAT_011c54cc;
extern int DAT_011c54d0;

struct FormEnumEntry
{
    unsigned int iFormString;
    unsigned char padding[8];
};

extern FormEnumEntry DAT_01187008[];

int __cdecl FUN_00470bb0();

// @fnv 0x004855a0
void ArrSI::FUN_004855a0()
{
    FormRecordHeader* pForm;

    if (IsTemporary())
        return;

    DAT_011c54d0 = sizeof(FormRecordHeader);
    DAT_011c54cc = ::operator new(DAT_011c54d0);
    pForm = static_cast<FormRecordHeader*>(DAT_011c54cc);
    pForm->flags = GetFlags();
    if (GetFormType() != 1)
        pForm->flags = pForm->flags & 0x30032FE0;
    pForm->form = DAT_01187008[GetFormType()].iFormString;
    pForm->iFormID = GetFormID();
    pForm->length = 0;
    pForm->m_usFormVersion = FUN_00470bb0();
    pForm->m_uiVersionControlInfo = 0;
    pForm->m_usHeaderUnknown = 0;
    Unk_37();
}
}  // namespace fnv_004855a0

void* DAT_011c54cc;
int DAT_011c54d0;

void* __memcpy(void* destination, const void* source, unsigned int count);
void* _Reallocate(void* buffer, unsigned int size);
void _FUN_00485910(int value, int size);
unsigned char _FUN_00401500();

struct FUN_004141e0_class
{
    unsigned int chunk;
    unsigned short length;
    void FUN_004141e0();
};

// @fnv 0x00485990
void AppendChunk(unsigned int chunk, const void* data, unsigned int size)
{
    unsigned int offset;
    {
        unsigned short length = static_cast<unsigned short>(size);
        if (size > 0xffff)
        {
            _FUN_00485910(0x58585858, size);
            length = 0;
        }

        {
            unsigned char* chunkData;
            {
                unsigned char* dataDestination;
                {
                    FUN_004141e0_class* newChunk;

                    offset = DAT_011c54d0;
                    DAT_011c54d0 = DAT_011c54d0 + size + 6;
                    DAT_011c54cc = _Reallocate(DAT_011c54cc, DAT_011c54d0);

                    newChunk =
                        reinterpret_cast<FUN_004141e0_class*>(static_cast<unsigned char*>(DAT_011c54cc) + offset);
                    chunkData = static_cast<unsigned char*>(DAT_011c54cc) + offset;

                    newChunk->chunk = chunk;
                    newChunk->length = length;

                    if (_FUN_00401500())
                        newChunk->FUN_004141e0();

                    __memcpy(chunkData, newChunk, 6);

                    dataDestination = static_cast<unsigned char*>(DAT_011c54cc) + offset + 6;
                    __memcpy(dataDestination, data, size);
                }
            }
        }
    }
}

namespace fnv_00485a70 {
struct FUN_004141e0_class
{
    unsigned char _padding[3];

    void FUN_004141e0();
};

struct CHUNK : public FUN_004141e0_class
{
    unsigned short length;
};

struct FUN_00485a70_class
{
    bool FUN_00485a70(CHUNK* apChunk, unsigned short asExpandSize);
};

bool _FUN_00401500();
void* __cdecl _Reallocate(void* buffer, unsigned int size);

void* DAT_011c54cc;
int DAT_011c54d0;

// @fnv 0x00485a70
bool FUN_00485a70_class::FUN_00485a70(CHUNK* apChunk, unsigned short asExpandSize)
{
    bool bendian = false;
    bendian = _FUN_00401500();

    if (bendian)
        apChunk->FUN_004141e0();

    if ((apChunk->length == 0 && asExpandSize == 0) || (apChunk->length + asExpandSize > 0xffff))
    {
        if (bendian)
            apChunk->FUN_004141e0();
        return false;
    }

    apChunk->length += asExpandSize;

    if (bendian)
        apChunk->FUN_004141e0();

    DAT_011c54d0 += asExpandSize;
    DAT_011c54cc = _Reallocate(DAT_011c54cc, DAT_011c54d0);
    return true;
}
}  // namespace fnv_00485a70

class FUN_00484a10_cls : public TESForm
{
  public:
    void SetFlag40(bool set);
};

// Sets or clears bit 0x40 in the form's flags field and marks the form as modified.
// @fnv 0x00484a10
void FUN_00484a10_cls::SetFlag40(bool set)
{
    set ? (m_uiFormFlags |= 0x40) : (m_uiFormFlags &= 0xffffffbf);
    MarkAsModified(1);
}

struct FUN_0047c050
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
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    FUN_0047c050();
    ~FUN_0047c050();
    void FUN_0047c070(void* value);
    void FUN_0047c600(FUN_0047c050* other);
};
struct FormCloneOperation
{
    void FUN_004851b0(void* targetForm);
};
// @fnv 0x004851b0
void FormCloneOperation::FUN_004851b0(void* targetForm)
{
    FUN_0047c050 z;
    FUN_0047c050 a;
    z.FUN_0047c070(this);
    a.FUN_0047c070(targetForm);
    z.FUN_0047c600(&a);
}

class TESForm;

struct FUN_00509540_obj
{
    FUN_00509540_obj();
    ~FUN_00509540_obj();
    void FUN_0047c070(void* apOther);
    bool CompareComponents(FUN_00509540_obj* apOther);
    bool FUN_00485270(TESForm* apArg);
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
};

// @fnv 0x00485270
bool FUN_00509540_obj::FUN_00485270(TESForm* apArg)
{
    if (apArg == 0)
        return true;
    FUN_00509540_obj p;
    FUN_00509540_obj a;
    p.FUN_0047c070(this);
    a.FUN_0047c070(apArg);
    return p.CompareComponents(&a);
}

struct CompareForm : TESForm
{
    bool FUN_004853e0(BaseFormComponent* rhs);
    int FUN_00474cb0();
    unsigned int FUN_0044ddc0();
};
extern "C" int __cdecl FUN_00404dc0(const char*, const char*);

// @fnv 0x004853e0
bool CompareForm::FUN_004853e0(BaseFormComponent* apOther)
{
    TESForm* otherForm = dynamic_cast<TESForm*>(apOther);
    if (!otherForm)
        return true;

    if (m_ucFormType != otherForm->GetFormType())
        return true;

    if (FUN_00474cb0() || reinterpret_cast<CompareForm*>(otherForm)->FUN_00474cb0())
    {
        if (FUN_00474cb0() != reinterpret_cast<CompareForm*>(otherForm)->FUN_00474cb0())
            return true;
        else
        {
            if (FUN_00404dc0(GetName(), otherForm->GetName()))
                return true;
        }
    }

    unsigned int flagsA = FUN_0044ddc0();
    unsigned int flagsB = reinterpret_cast<CompareForm*>(otherForm)->FUN_0044ddc0();
    flagsA &= 0xffffbff4;
    flagsB &= 0xffffbff4;
    if (flagsA != flagsB)
        return true;
    return false;
}

struct FUN_004867a0_vbase
{
    virtual void v00(void* a);
    virtual void v01(void* a);
    virtual void v02(void* a);
    virtual void v03(void* a);
    virtual void v04(void* a);
    virtual void v05(void* a);
    virtual void v06(void* a);
    virtual void v07(void* a);
    virtual void v08(void* a);
    virtual void v09(void* a);
    virtual void v0A(void* a);
    virtual void v0B(void* a);
    virtual void v0C(void* a);
    virtual void v0D(void* a);
    virtual void v0E(void* a);
    virtual void v0F(void* a);
    virtual void v10(void* a);
    virtual void v11(void* a);
    virtual void v12(void* a);
    virtual void v13(void* a);
    virtual void v14(void* a);
    virtual void v15(void* a);
    virtual void v16(void* a);
    virtual void v17(void* a);
    virtual void v18(void* a);
    virtual void v19(void* a);
    virtual void v1A(void* a);
    virtual void v1B(void* a);
    virtual void v1C(void* a);
    virtual void v1D(void* a);
    virtual void v1E(void* a);
    virtual void v1F(void* a);
    virtual void v20(void* a);
    virtual void v21(void* a);
    virtual void v22(void* a);
    virtual void v23(void* a);
    virtual void v24(void* a);
    virtual void v25(void* a);
    virtual void v26(void* a);
    virtual void v27(void* a);
    virtual void v28(void* a);
    virtual void v29(void* a);
    virtual void v2A(void* a);
    virtual void v2B(void* a);
    virtual void v2C(void* a);
    virtual void v2D(void* a);
    virtual void v2E(void* a);
    virtual void v2F(void* a);
    virtual void v30(void* a);
    virtual void v31(void* a);
    virtual void v32(void* a);
    virtual void v33(void* a);
    virtual void v34(void* a);
    virtual void v35(void* a);
    virtual void v36(void* a);
    virtual void v37(void* a);
    virtual void v38(void* a);
    virtual void v39(void* a);
    virtual void v3A(void* a);
    virtual void v3B(void* a);
    virtual void v3C(void* a);
    virtual void v3D(void* a);
    virtual void v3E(void* a);
    virtual void v3F(void* a);
    virtual void v40(void* a);
    virtual void v41(void* a);
    virtual void v42(void* a);
    virtual void v43(void* a);
    virtual void v44(void* a);
    virtual void v45(void* a);
    virtual void v46(void* a);
    virtual void v47(void* a);
    virtual void v48(void* a);
    virtual void v49(void* a);
    virtual void v4A(void* a);
    virtual void v4B(void* a);
    virtual void v4C(void* a);
    virtual void v4D(void* a);
    virtual void v4E(void* a);
    virtual void v4F(void* a);
};

struct FUN_004867a0_holder
{
    unsigned int unk00;
    unsigned int unk04;
    FUN_004867a0_holder(void* p);
    ~FUN_004867a0_holder();
    void* GetItem();
};

struct FUN_004867a0_cls : FUN_004867a0_vbase
{
    void* GetA();
    void* GetB();
    void* FUN_004867a0(void* unused, void* arg);
};

struct FUN_004867a0_arg
{
    void FUN_00844700(void* a, void* b);
};

void* FUN_00465110(void* p);

// @fnv 0x004867a0
void* FUN_004867a0_cls::FUN_004867a0(void* unused, void* arg)
{
    FUN_004867a0_vbase* obj = (FUN_004867a0_vbase*)FUN_00465110(GetA());
    if (obj != 0)
    {
        FUN_004867a0_holder holder(GetB());
        this->v4D("");
        obj->v42(this);
        if (holder.GetItem() != 0)
        {
            this->v4D(holder.GetItem());
        }
    }
    if (obj != 0 && arg != 0)
    {
        ((FUN_004867a0_arg*)arg)->FUN_00844700(this, obj);
    }
    return obj;
}

struct S4868f0_host
{
    unsigned int FUN_0084e3a0();
    unsigned int FUN_00401280();
    unsigned int FUN_00440e30();
    void FUN_004868f0(unsigned int a);
};

extern "C" int __cdecl FUN_00406f60(unsigned int, const char*, unsigned int, unsigned int, unsigned int);

// @fnv 0x004868f0
void S4868f0_host::FUN_004868f0(unsigned int a)
{
    FUN_00406f60(a, "%s Form '%s' (%08X)", FUN_00440e30(), FUN_00401280(), FUN_0084e3a0());
}

extern char DAT_011841cc;
extern char DAT_011846d4;
extern "C" void* __cdecl FUN_00ec43fb(void* key, int option, const void* source, const void* destination, int flags);

struct ActionObject
{
    void** methods;
};

typedef void(__thiscall* ActionHandler)(ActionObject* self, int target, void* data, unsigned char mode);

struct ActionCaller
{
    bool InvokeAction(int target, void* key, unsigned char mode, int unused, void* data);
};

// @fnv 0x0050f670
bool ActionCaller::InvokeAction(int target, void* key, unsigned char mode, int unused, void* data)
{
    ActionObject* object = (ActionObject*)FUN_00ec43fb(key, 0, &DAT_011841cc, &DAT_011846d4, 0);
    if (object != 0 && target != 0)
    {
        void* savedData = data;
        ((ActionHandler)object->methods[244])(object, target, savedData, mode);
        return true;
    }
    return false;
}

struct FUN_0050f780_Class
{
    void __thiscall ForwardTo008d0600(int arg1, unsigned char arg2);
    void __thiscall FUN_008d0600(int arg1, unsigned char arg2);
};

// @fnv 0x0050f780
void FUN_0050f780_Class::ForwardTo008d0600(int arg1, unsigned char arg2)
{
    FUN_008d0600(arg1, arg2);
}

bool __cdecl FUN_00401500();
void __cdecl AppendChunk(unsigned int record, const void* data, unsigned int bytes);
struct Record
{
    unsigned char field0;
    unsigned char field1;
    unsigned char field2;
    void __thiscall FUN_00483710();
};
struct FUN_005e9620_class
{
    unsigned int unk00;
    unsigned char unk04;
    unsigned char unk05;
    void __thiscall FUN_005e9620(unsigned char value);
};
// @fnv 0x005e9620
void __thiscall FUN_005e9620_class::FUN_005e9620(unsigned char value)
{
    Record data;
    data.field2 = unk05;
    data.field1 = unk04;
    data.field0 = value;
    if (FUN_00401500())
    {
        data.FUN_00483710();
    }
    AppendChunk(0x454b5250, &data, 3);
    if (FUN_00401500())
    {
        data.FUN_00483710();
    }
}

extern const char* g_packageTypeNames[];

struct C67ACD0Package
{
    int unk00;

    int GetType();
    const char* GetTypeName();
};

// @fnv 0x0067acd0
const char* C67ACD0Package::GetTypeName()
{
    return g_packageTypeNames[GetType()];
}

struct CompressionRecord
{
    unsigned int type;
    unsigned int size;
    unsigned int flags;
    unsigned int formID;
    unsigned int versionControl;
    unsigned int version;
};
struct CompressionStream
{
    unsigned char* m_pNextInputByte;
    unsigned int m_uiAvailableInputBytes;
    unsigned int m_ulTotalInputBytes;
    unsigned char* m_pNextOutputByte;
    unsigned int m_uiAvailableOutputBytes;
    unsigned int m_ulTotalOutputBytes;
    char* msg;
    void* state;
    void*(__cdecl* m_pAllocateCallback)(void*, unsigned int, unsigned int);
    void(__cdecl* m_pFreeCallback)(void*, void*);
    void* opaque;
    int data_type;
    unsigned int m_ulAdler32Checksum;
    unsigned int reserved;
};
extern "C" int __cdecl FUN_00b46360(CompressionStream*, int, const char*, int);
extern "C" int __cdecl deflate(CompressionStream*, int);
extern "C" int __cdecl FUN_00b47370(CompressionStream*);

// Local roles: j = write cursor, e = output buffer, c = record header,
// l = zlib status, k = new record size, ba = compressed buffer,
// b = stored original size, q = input size, cf = zlib stream,
// eb = compression capacity, f = compressed size.
// @fnv 0x00483d70
void CompressSaveLoadRecord()
{
    if (DAT_011c54cc && (unsigned int)DAT_011c54d0 > 24)
    {
        CompressionRecord* c = (CompressionRecord*)DAT_011c54cc;
        if (FUN_00401500())
            ((FUN_00470650_shell*)c)->FUN_00470650();
        if (c->flags & 0x40000)
        {
            if (FUN_00401500())
                ((FUN_00470650_shell*)c)->FUN_00470650();
            return;
        }
        unsigned int q = DAT_011c54d0 - 24;
        unsigned char* j = (unsigned char*)DAT_011c54cc;
        j += 24;
        CompressionStream cf;
        cf.m_pAllocateCallback = 0;
        cf.m_pFreeCallback = 0;
        cf.opaque = 0;
        cf.state = 0;
        int l = FUN_00b46360(&cf, -1, "1.2.1", 56);
        if (l != 0)
        {
            _FNV_Warning("SAVELOAD: Error initializing ZLib stream for deflate.");
            return;
        }
        unsigned int eb = q * 2;
        unsigned char* ba = new unsigned char[eb];
        cf.m_uiAvailableInputBytes = q;
        cf.m_pNextInputByte = j;
        cf.m_uiAvailableOutputBytes = eb;
        cf.m_pNextOutputByte = ba;
        l = deflate(&cf, 4);
        if (l == -2)
        {
            _FNV_Warning("SAVELOAD: Error deflating ZLib stream.");
            delete[] ba;
            return;
        }
        unsigned int f = eb - cf.m_uiAvailableOutputBytes;
        unsigned int k = f + 28;
        unsigned char* e = new unsigned char[k];
        j = e;
        c->flags |= 0x40000;
        c->size = k - 24;
        if (FUN_00401500())
            ((FUN_00470650_shell*)c)->FUN_00470650();
        __memcpy(j, c, 24);
        j += 24;
        unsigned int b = q;
        if (FUN_00401500())
            BSEndian((int*)&b, EndianSizeTag<4>());
        __memcpy(j, &b, 4);
        j += 4;
        __memcpy(j, ba, f);
        Deallocate(DAT_011c54cc);
        DAT_011c54cc = e;
        DAT_011c54d0 = k;
        FUN_00b47370(&cf);
        delete[] ba;
    }
}

struct TESFormSortProxy : public TESForm
{
    bool IsLessThan(TESForm* apOther);
};

// Compares this form's remapped form-type rank against another form's and returns true when this rank is lower.
// @fnv 0x00484020
bool TESFormSortProxy::IsLessThan(TESForm* apOther)
{
    unsigned int uiThisRank;
    unsigned int uiOtherRank;
    uiOtherRank = apOther->GetFormType();
    uiThisRank = GetFormType();
    switch (uiOtherRank)
    {
    case 0x67:
        uiOtherRank = 0x137;
        break;
    case 0x6C:
        uiOtherRank = 0x138;
        break;
    case 0x73:
        uiOtherRank = 0x139;
        break;
    case 0x74:
        uiOtherRank = 0x13A;
        break;
    default:
        uiOtherRank *= 10;
        break;
    }
    switch (uiThisRank)
    {
    case 0x67:
        uiThisRank = 0x137;
        break;
    case 0x6C:
        uiThisRank = 0x138;
        break;
    case 0x73:
        uiThisRank = 0x139;
        break;
    case 0x74:
        uiThisRank = 0x13A;
        break;
    default:
        uiThisRank *= 10;
        break;
    }
    if (uiThisRank < uiOtherRank)
        return true;
    return false;
}

struct FormMap
{
    void RemoveKey(unsigned int);
    void FUN_00844700(unsigned int, TESForm*);
};
struct DebugTarget
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
    virtual void GetDebugInfo(BSStringT<char>*);
};
extern const char DAT_0101c9c8[];
extern unsigned char DAT_011c54b9;
void __cdecl FUN_00461300();
struct FUN_00485c10_shell : public TESForm
{
    bool FUN_004077c0();
    const char* FUN_00440e30();
    void FUN_00485c10(unsigned int id, bool notify);
};
// @fnv 0x00485c10
void FUN_00485c10_shell::FUN_00485c10(unsigned int id, bool notify)
{
    if (id == iFormID)
        return;
    if (!FUN_004077c0())
    {
        DebugTarget* debug = 0;
        if (iFormID != 0)
        {
            reinterpret_cast<FormMap*>(TESForm::ms_pFormIDMap)->RemoveKey(iFormID);
        }
        debug = 0;
        if (debug != 0)
        {
            FUN_00461300();
            BSStringT<char> details;
            debug->GetDebugInfo(&details);
            _FNV_Warning(DAT_0101c9c8, id, FUN_00440e30(), details.String());
            DAT_011c54b9 = 1;
        }
        else if (notify && iFormID != 0)
        {
            g_dataHandler->FUN_004696f0(iFormID);
        }
        if (id != 0)
        {
            reinterpret_cast<FormMap*>(TESForm::ms_pFormIDMap)->FUN_00844700(id, this);
        }
    }
    iFormID = id;
}

struct SDEndianTag
{
};

bool __cdecl SDIsBigEndian();
void __cdecl SDSwapBytes(int* apValue, SDEndianTag);
void __cdecl SDSwapBytes(float* apValue, SDEndianTag);
void __cdecl SDSwapBytes(short* apValue, SDEndianTag);
void* __cdecl SDMemCpy(void* apDest, const void* apSrc, unsigned int auiSize);
void __cdecl SDWriteChunk(unsigned int auiChunk, const void* apData, unsigned int auiSize);
void __cdecl SDWarning(const char* apMessage);

struct SDIntComponent
{
    int GetValue();
};

struct SDDamageComponent
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual short GetAttackDamage();
};

struct SDSaveForm : TESForm
{
    int GetSaveOffset();
    char* GetSaveBuffer();
    bool ReserveSaveData(char* apStart, unsigned short ausSize);
    void FUN_00485e20(const void* apData, unsigned int auiSize);
};

// @fnv 0x00485e20
void SDSaveForm::FUN_00485e20(const void* apData, unsigned int auiSize)
{
    if (auiSize > 0xffff)
    {
        SDWarning("MASTERFILE: Trying to SaveData that's too large.");
        return;
    }

    unsigned short usSize9 = 0;
    int _iOffset = GetSaveOffset();
    SDWriteChunk('ATAD', apData, auiSize);
    char* pStart = GetSaveBuffer() + _iOffset;

    TESUsesForm* pUses7 = dynamic_cast<TESUsesForm*>(static_cast<TESForm*>(this));
    TESValueForm* pValueTmp = dynamic_cast<TESValueForm*>(static_cast<TESForm*>(this));
    TESHealthForm* pHealth5 = dynamic_cast<TESHealthForm*>(static_cast<TESForm*>(this));
    TESWeightForm* pWeight4 = dynamic_cast<TESWeightForm*>(static_cast<TESForm*>(this));
    TESQualityForm* pQuality2 = dynamic_cast<TESQualityForm*>(static_cast<TESForm*>(this));
    TESAttackDamageForm* pDamage2 = dynamic_cast<TESAttackDamageForm*>(static_cast<TESForm*>(this));
    TESAttributes* kPAttributes = dynamic_cast<TESAttributes*>(static_cast<TESForm*>(this));
    BGSClipRoundsForm* pClipRounds3 = dynamic_cast<BGSClipRoundsForm*>(static_cast<TESForm*>(this));

    if (pUses7)
        usSize9 += 1;
    if (pValueTmp)
        usSize9 += 4;
    if (pHealth5)
        usSize9 += 4;
    if (pWeight4)
        usSize9 += 4;
    if (pQuality2)
        usSize9 += 4;
    if (pDamage2)
        usSize9 += 2;
    if (kPAttributes)
        usSize9 += kPAttributes->GetAttributeDataSize();
    if (pClipRounds3)
        usSize9 += 1;

    if (!usSize9)
        return;

    _iOffset = GetSaveOffset();
    if (!ReserveSaveData(pStart, usSize9))
        return;

    char* pWrite2 = GetSaveBuffer() + _iOffset;
    if (pUses7)
    {
        *pWrite2 = pUses7->GetFormUses();
        pWrite2 += 1;
    }
    if (pValueTmp)
    {
        *(int*)pWrite2 = ((SDIntComponent*)pValueTmp)->GetValue();
        if (SDIsBigEndian())
            SDSwapBytes((int*)pWrite2, SDEndianTag());
        pWrite2 += 4;
    }
    if (pHealth5)
    {
        *(int*)pWrite2 = ((SDIntComponent*)pHealth5)->GetValue();
        if (SDIsBigEndian())
            SDSwapBytes((int*)pWrite2, SDEndianTag());
        pWrite2 += 4;
    }
    if (pWeight4)
    {
        float fWeight = pWeight4->GetWeightForForm();
        if (SDIsBigEndian())
            SDSwapBytes(&fWeight, SDEndianTag());
        SDMemCpy(pWrite2, &fWeight, 4);
        pWrite2 += 4;
    }
    if (pQuality2)
    {
        float fQuality4 = pQuality2->GetFormQuality();
        if (SDIsBigEndian())
            SDSwapBytes(&fQuality4, SDEndianTag());
        SDMemCpy(pWrite2, &fQuality4, 4);
        pWrite2 += 4;
    }
    if (pDamage2)
    {
        *(short*)pWrite2 = ((SDDamageComponent*)pDamage2)->GetAttackDamage();
        if (SDIsBigEndian())
            SDSwapBytes((short*)pWrite2, SDEndianTag());
        pWrite2 += 2;
    }
    if (kPAttributes)
        pWrite2 += kPAttributes->Save(pWrite2);
    if (pClipRounds3)
    {
        *pWrite2 = pClipRounds3->GetClipRounds();
        pWrite2 += 1;
    }
}

namespace fnv_00483370 {
extern NiTPointerMap<unsigned int, TESForm*>* DAT_011c54c0;
extern char DAT_0101c748, DAT_0101c6e0, DAT_0101c6a0;
extern int DAT_011c54bc;
extern bool DAT_011c54b8;
struct TypeInfo
{
    unsigned char unk00;
    const char* unk04;
    unsigned int unk08;
};
extern TypeInfo DAT_01187000[];
void __cdecl FUN_0043b2b0(bool);
void __cdecl FNV_Warning(const char*, ...);
void __cdecl FUN_0040fbe0(const char*);
void __cdecl FUN_00483a50();
struct TESDataHandler
{
    bool FUN_00482f20();
    unsigned int GetNextID();
};
extern TESDataHandler* DAT_011c3f2c;
TESFile* __fastcall GetField20C(char*);
struct BaseFC
{
    virtual void slot();
    BaseFC();
};
struct FUN_00483370 : BaseFC
{
    unsigned char m_ucFormType;
    unsigned int m_uiFormFlags;
    unsigned int iFormID;
    BSSimpleList<TESFile*> m_kSourceFiles;
    virtual void slot();
    FUN_00483370();
};
// @fnv 0x00483370
FUN_00483370::FUN_00483370()
{
    if (DAT_011c54bc == 0)
        FUN_00483a50();
    DAT_011c54bc++;
    if (!DAT_011c54b8)
    {
        bool bInvalid = false;
        FUN_0043b2b0(true);
        for (unsigned int i = 0; i < 121; ++i)
        {
            DAT_01187000[i].unk08 = DAT_01187000[i].unk04[0] | (DAT_01187000[i].unk04[1] << 8) |
                                    (DAT_01187000[i].unk04[2] << 16) | (DAT_01187000[i].unk04[3] << 24);
            if (DAT_01187000[i].unk00 != i)
            {
                FNV_Warning((const char*)&DAT_0101c748, i);
                bInvalid = true;
            }
            for (unsigned int j = 0; j < 121; ++j)
            {
                if (i != j && DAT_01187000[i].unk08 == DAT_01187000[j].unk08)
                {
                    FNV_Warning((const char*)&DAT_0101c6e0, i, j, DAT_01187000[i].unk04);
                    bInvalid = true;
                }
            }
        }
        FUN_0043b2b0(false);
        if (bInvalid)
            FUN_0040fbe0((const char*)&DAT_0101c6a0);
        DAT_011c54b8 = true;
    }
    m_ucFormType = 0;
    m_uiFormFlags = 8;
    iFormID = 0;
    if (DAT_011c3f2c && !DAT_011c3f2c->FUN_00482f20())
    {
        iFormID = DAT_011c3f2c->GetNextID();
        if (GetField20C((char*)DAT_011c3f2c))
            ((TESForm*)this)->SetFile(GetField20C((char*)DAT_011c3f2c));
        if (iFormID <= 0x7ff)
            ((TESForm*)this)->TESForm::SetRefID(0x800, true);
    }
    if (iFormID)
        DAT_011c54c0->SetAt(iFormID, (TESForm*)this);
}
}  // namespace fnv_00483370

bool __cdecl FUN_00401500();
void __cdecl AppendChunk(void*, void*, void*);
void* __cdecl FormHeap_Allocate(unsigned int size);
void __cdecl FormHeap_Free(void* p);
void* __cdecl FUN_00401460(void* dst, void* src, unsigned int size);
void __cdecl FUN_00401080(void* p, bool value);

struct BoolBox
{
    bool value;
};

struct Slot4
{
    unsigned int value;
    static void* operator new[](unsigned int size)
    {
        return FormHeap_Allocate(size);
    }
    static void operator delete[](void* p)
    {
        FormHeap_Free(p);
    }
};

// When FUN_00401500() is true, copies arg1 into a temporary array, calls FUN_00401080 on each element with false, then appends it.
// @fnv 0x00485750
void __cdecl FUN_00485750(void* apDestination, void* apSource, void* aiCount)
{
    Slot4* p4;
    unsigned int bytes7 = (unsigned int)aiCount * 4;

    if (FUN_00401500())
    {
        unsigned int i;
        p4 = new Slot4[(unsigned int)aiCount];
        FUN_00401460(p4, apSource, bytes7);
        for (i = 0; i < (unsigned int)aiCount; ++i)
        {

            FUN_00401080(&p4[i], BoolBox().value);
        }
        AppendChunk(apDestination, p4, (void*)bytes7);
        delete[] p4;
    }
    else
    {
        AppendChunk(apDestination, apSource, (void*)bytes7);
    }
}

namespace fnv_0069da40 {
void* __cdecl _memcpy(void*, const void*, unsigned int);

template <int N> struct EndianSizeTag
{
};
void __cdecl FUN_00401080(int*, EndianSizeTag<0>);
void __cdecl FUN_00407a90(unsigned short*, EndianSizeTag<0>);

class DA00694f80
{
  public:
    DA00694f80();
    virtual ~DA00694f80();
    void SetSize(unsigned int size, bool b);
    unsigned short& GetAt(int index);
    int unk04;
    int unk08;
    int unk0C;
};

class TESFileRecordLoader
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
    DA00694f80* unk24;

    bool LoadRecord(void* src, int unused, TESFile* file);
};

// Copies a 0x24-byte header from src, converts header values if needed, allocates unk24, then reads counts and unsigned-short values from src.
// @fnv 0x0069da40
bool TESFileRecordLoader::LoadRecord(void* src, int unused, TESFile* file)
{
    unsigned int totalCount;
    unsigned int headerSize7 = 0x24;
    unsigned short* dataPtr;
    unsigned int i4;
    unsigned short subCount2;
    unsigned short j;

    _memcpy(this, src, headerSize7);
    if (file->IsEndianConversionRequired())
    {
        FUN_00401080(&unk00, EndianSizeTag<0>());
        FUN_00401080(&unk04, EndianSizeTag<0>());
        FUN_00401080(&unk08, EndianSizeTag<0>());
        FUN_00401080(&unk0C, EndianSizeTag<0>());
        FUN_00401080(&unk10, EndianSizeTag<0>());
        FUN_00401080(&unk14, EndianSizeTag<0>());
        FUN_00401080(&unk18, EndianSizeTag<0>());
        FUN_00401080(&unk1C, EndianSizeTag<0>());
        FUN_00401080(&unk20, EndianSizeTag<0>());
    }
    if (unk00 == 0)
    {
        unk24 = 0;
        return false;
    }
    totalCount = unk00 * unk00;
    unk24 = new DA00694f80[totalCount];
    dataPtr = (unsigned short*)((char*)src + headerSize7);
    for (i4 = 0; i4 < totalCount; ++i4)
    {
        subCount2 = *dataPtr++;
        if (file->IsEndianConversionRequired())
        {
            FUN_00407a90(&subCount2, EndianSizeTag<0>());
        }
        unk24[i4].SetSize(subCount2, true);
        if (subCount2 > 0)
        {
            if (file->IsEndianConversionRequired())
            {
                for (j = 0; j < subCount2; ++j)
                {
                    FUN_00407a90(&dataPtr[j], EndianSizeTag<0>());
                }
            }
            _memcpy(&unk24[i4].GetAt(0), dataPtr, subCount2 * 2);
            dataPtr += subCount2;
        }
    }
    return true;
}
}  // namespace fnv_0069da40

extern unsigned int kGroupFormType;
int __cdecl FindFormEnumIndex(unsigned int);

struct FUN_00484150_shell : public TESForm
{
    bool IsFormTypeBelowThreshold(FormRecordHeader* apGroupForm);
};

// Checks if a group form's form type is below a threshold based on its iFormID, returning true if the type index is less than the threshold.
// @fnv 0x00484150
bool FUN_00484150_shell::IsFormTypeBelowThreshold(FormRecordHeader* apGroupForm)
{
    bool bResultTmp = false;
    unsigned int v1;
    unsigned int v2;
    unsigned int v9;
    unsigned int v8;
    unsigned int v7;

    if (apGroupForm && apGroupForm->form == kGroupFormType)
    {
        switch (apGroupForm->iFormID)
        {
        case 0:
            v2 = FindFormEnumIndex(apGroupForm->flags);
            v1 = GetFormType();
            switch (v2)
            {
            case ENUM_FORM_ID_IMOD_ID:
                v2 = 311;
                break;
            case ENUM_FORM_ID_CHIP_ID:
                v2 = 312;
                break;
            case ENUM_FORM_ID_CCRD_ID:
                v2 = 313;
                break;
            case ENUM_FORM_ID_CMNY_ID:
                v2 = 314;
                break;
            default:
                v2 *= 10;
                break;
            }
            switch (v1)
            {
            case ENUM_FORM_ID_IMOD_ID:
                v1 = 311;
                break;
            case ENUM_FORM_ID_CHIP_ID:
                v1 = 312;
                break;
            case ENUM_FORM_ID_CCRD_ID:
                v1 = 313;
                break;
            case ENUM_FORM_ID_CMNY_ID:
                v1 = 314;
                break;
            default:
                v1 *= 10;
                break;
            }
            if (v1 < v2)
            {
                bResultTmp = true;
            }
            break;
        case 2:
        case 3:
        case 6:
            v9 = GetFormType();
            switch (v9)
            {
            case ENUM_FORM_ID_IMOD_ID:
                v9 = 311;
                break;
            case ENUM_FORM_ID_CHIP_ID:
                v9 = 312;
                break;
            case ENUM_FORM_ID_CCRD_ID:
                v9 = 313;
                break;
            case ENUM_FORM_ID_CMNY_ID:
                v9 = 314;
                break;
            default:
                v9 *= 10;
                break;
            }
            if (v9 < 570)
            {
                bResultTmp = true;
            }
            break;
        case 1:
        case 4:
        case 5:
            v8 = GetFormType();
            switch (v8)
            {
            case ENUM_FORM_ID_IMOD_ID:
                v8 = 311;
                break;
            case ENUM_FORM_ID_CHIP_ID:
                v8 = 312;
                break;
            case ENUM_FORM_ID_CCRD_ID:
                v8 = 313;
                break;
            case ENUM_FORM_ID_CMNY_ID:
                v8 = 314;
                break;
            default:
                v8 *= 10;
                break;
            }
            if (v8 < 650)
            {
                bResultTmp = true;
            }
            break;
        case 7:
            v7 = GetFormType();
            switch (v7)
            {
            case ENUM_FORM_ID_IMOD_ID:
                v7 = 311;
                break;
            case ENUM_FORM_ID_CHIP_ID:
                v7 = 312;
                break;
            case ENUM_FORM_ID_CCRD_ID:
                v7 = 313;
                break;
            case ENUM_FORM_ID_CMNY_ID:
                v7 = 314;
                break;
            default:
                v7 *= 10;
                break;
            }
            if (v7 < 690)
            {
                bResultTmp = true;
            }
            break;
        }
    }
    return bResultTmp;
}

namespace fnv_004861f0 {
/* rework: avoid defining TESUsesForm/TESHealthForm/... which clash with tesform.cpp structs (C2011) */
extern "C" void* __cdecl FUN_00ec43fb(void* in, int vfDelta, void* srcType, void* targetType, int isReference);
extern char DAT_01183028[]; /* .?AVTESForm@@ */
extern char DAT_01186b88[]; /* .?AVTESUsesForm@@ */
extern char DAT_01186b6c[]; /* .?AVTESValueForm@@ */
extern char DAT_01186c3c[]; /* .?AVTESHealthForm@@ */
extern char DAT_01183274[]; /* .?AVTESWeightForm@@ */
extern char DAT_01186bdc[]; /* .?AVTESQualityForm@@ */
extern char DAT_01186c90[]; /* .?AVTESAttackDamageForm@@ */
extern char DAT_01186c74[]; /* .?AVTESAttributes@@ */
extern char DAT_011868d4[]; /* .?AVBGSClipRoundsForm@@ */

extern "C" void* __cdecl memcpy(void* dest, const void* src, size_t count);
unsigned short __cdecl MinUnsignedShort(unsigned short a, unsigned short b) throw();
struct Swap_004861f0
{
};
void __cdecl FUN_00401080(int* p, Swap_004861f0 b) throw();
void __cdecl FUN_00407a90(short* p, Swap_004861f0 b) throw();

/* neutral stand-ins for member calls only (names must not collide with tesform.cpp) */
class UsesFormX : public BaseFormComponent
{
  public:
    void FUN_004f15a0(unsigned int) throw();
};
class HealthFormX : public BaseFormComponent
{
  public:
    void FUN_006ecd40(unsigned int) throw();
};
class WeightFormX : public BaseFormComponent
{
  public:
    void FUN_004f5d90(float) throw();
};
class QualityFormX : public BaseFormComponent
{
  public:
    void FUN_004f15a0(unsigned int) throw();
};
class AttackDamageFormX : public BaseFormComponent
{
  public:
    void FUN_0047ff50(unsigned short) throw();
};
class AttributesX : public BaseFormComponent
{
  public:
    unsigned int FUN_00480130(void*) throw();
};
class ClipRoundsFormX : public BaseFormComponent
{
  public:
    void FUN_004f15a0(unsigned int) throw();
};

struct Form_004861f0 : TESForm
{
    void FUN_004861f0(TESFile* file, void* dest, unsigned short count);
};

// Reads a chunk from the file into a stack buffer, copies it to dest, and parses form fields into the component objects.
// @fnv 0x004861f0
void Form_004861f0::FUN_004861f0(TESFile* file, void* dest, unsigned short count)
{
    AttributesX* pAttr9;
    ClipRoundsFormX* pClip;
    UsesFormX* pUses;
    QualityFormX* pQuality;
    unsigned short pos4;
    WeightFormX* pWeightFormTmp;
    AttackDamageFormX* pDamage5;
    TESValueForm* pValue;
    unsigned short chunkSize3;
    int val3;
    char* buffer2;
    HealthFormX* pHealth4;
    short damage9;
    float fval;

    chunkSize3 = file->GetChunkSize();
    pos4 = count;
    buffer2 = (char*)_alloca(chunkSize3);
    file->GetChunkData(buffer2, chunkSize3);
    memcpy(dest, buffer2, MinUnsignedShort(chunkSize3, count));

    pUses = (UsesFormX*)FUN_00ec43fb((TESForm*)this, 0, &DAT_01183028, &DAT_01186b88, 0);
    pValue = (TESValueForm*)FUN_00ec43fb((TESForm*)this, 0, &DAT_01183028, &DAT_01186b6c, 0);
    pHealth4 = (HealthFormX*)FUN_00ec43fb((TESForm*)this, 0, &DAT_01183028, &DAT_01186c3c, 0);
    pWeightFormTmp = (WeightFormX*)FUN_00ec43fb((TESForm*)this, 0, &DAT_01183028, &DAT_01183274, 0);
    pQuality = (QualityFormX*)FUN_00ec43fb((TESForm*)this, 0, &DAT_01183028, &DAT_01186bdc, 0);
    pDamage5 = (AttackDamageFormX*)FUN_00ec43fb((TESForm*)this, 0, &DAT_01183028, &DAT_01186c90, 0);
    pAttr9 = (AttributesX*)FUN_00ec43fb((TESForm*)this, 0, &DAT_01183028, &DAT_01186c74, 0);
    pClip = (ClipRoundsFormX*)FUN_00ec43fb((TESForm*)this, 0, &DAT_01183028, &DAT_011868d4, 0);

    if (pUses && pos4 < chunkSize3)
    {
        pUses->FUN_004f15a0((unsigned char)buffer2[pos4]);
        pos4 += 1;
    }
    if (pValue && pos4 < chunkSize3)
    {
        val3 = *(int*)(buffer2 + pos4);
        pos4 += 4;
        if (file->IsEndianConversionRequired())
            FUN_00401080(&val3, Swap_004861f0());
        pValue->SetFormValue(val3);
    }
    if (pHealth4 && pos4 < chunkSize3)
    {
        val3 = *(int*)(buffer2 + pos4);
        pos4 += 4;
        if (file->IsEndianConversionRequired())
            FUN_00401080(&val3, Swap_004861f0());
        pHealth4->FUN_006ecd40(val3);
    }
    if (pWeightFormTmp && pos4 < chunkSize3)
    {
        float weight;
        memcpy(&weight, buffer2 + pos4, 4);
        fval = weight;
        pos4 += 4;
        if (file->IsEndianConversionRequired())
            FUN_00401080((int*)&fval, Swap_004861f0());
        pWeightFormTmp->FUN_004f5d90(fval);
    }
    if (pQuality && pos4 < chunkSize3)
    {
        float quality;
        memcpy(&quality, buffer2 + pos4, 4);
        fval = quality;
        pos4 += 4;
        if (file->IsEndianConversionRequired())
            FUN_00401080((int*)&fval, Swap_004861f0());
        pQuality->FUN_004f15a0((unsigned char)fval);
    }
    if (pDamage5 && pos4 < chunkSize3)
    {
        damage9 = *(short*)(buffer2 + pos4);
        pos4 += 2;
        if (file->IsEndianConversionRequired())
            FUN_00407a90(&damage9, Swap_004861f0());
        pDamage5->FUN_0047ff50(damage9);
    }
    if (pAttr9)
    {
        pos4 += pAttr9->FUN_00480130(buffer2 + pos4);
    }
    if (pClip && pos4 < chunkSize3)
    {
        pClip->FUN_004f15a0((unsigned char)buffer2[pos4]);
        pos4 += 1;
    }
}
}  // namespace fnv_004861f0

namespace form_load_legacy {

extern "C" void* __cdecl FUN_00ec43fb(void*, int, void*, void*, int);
extern char DAT_01183028[];
extern char DAT_011841cc[];

struct TESFormLoadProxy : public ::TESForm
{
    void FUN_00484d00(void*, unsigned int);
    void FUN_00484c50(unsigned int, unsigned int);
};

// When bit 0 of flags is set, reads a value into itempFormFlags and merges masked bits into m_uiFormFlags according to whether pref is nonnull.
// @fnv 0x00484c50
void TESFormLoadProxy::FUN_00484c50(unsigned int flags, unsigned int currentFlags)
{
    ::TESObjectREFR* pref;
    unsigned int itempFormFlags;

    if (flags & 1)
    {
        FUN_00484d00(&itempFormFlags, 4);
        pref = (::TESObjectREFR*)FUN_00ec43fb(this, 0, &DAT_01183028, &DAT_011841cc, 0);
        if (pref)
        {
            m_uiFormFlags = (m_uiFormFlags & 0xff6ed79f) | (itempFormFlags & 0x00912860);
        }
        else
        {
            m_uiFormFlags = (m_uiFormFlags & 0xbffff3df) | (itempFormFlags & 0x40000c20);
        }
    }
}

}
