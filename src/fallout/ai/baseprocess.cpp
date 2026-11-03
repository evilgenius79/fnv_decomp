// fallout/ai/baseprocess.cpp: BaseProcess, SavedProcess, Target8d (46 functions)

#include "baseprocess_worker.h"

static const int kCalculateMoveModeValue1 = 257;

// @fnv 0x008d0540
int BaseProcess::GetAttackChance(Actor* apActor, float afValue1, float afValue2, float afValue3, bool abFlag1,
                                 bool abFlag2)
{
    return kCalculateMoveModeValue1;
}

// @fnv 0x008d1050
void BaseProcess::ApplyLoadBuffer(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<ActorPackageCall*>(&m_kProcessData)->ApplyLoadBuffer(buffer);
}

// @fnv 0x008d1000
void BaseProcess::InitLoadGame(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<ActorPackageCall*>(&m_kProcessData)->FUN_008c6970(buffer);
    if (m_pCachedValues)
        reinterpret_cast<CachedValuesCall*>(m_pCachedValues)->ClearField44();
}

// @fnv 0x008d08b0
void BaseProcess::SetCurrentPackageAndTarget(TESPackage* package, MobileObject* reference)
{
    TESObjectREFR* target = reinterpret_cast<TESPackage*>(package)->GetResolvedTargetReference(reference);
    reinterpret_cast<ActorPackageCall*>(&m_kProcessData)->SetPackageAndTarget(package, target);
}

// @fnv 0x008d0870
void BaseProcess::SetReferenceTarget(TESObjectREFR* reference)
{
    reinterpret_cast<GuardActorPackageDataCall*>(&m_kProcessData)->SetReferenceTarget(reference);
    ActorPackageData* data =
        reinterpret_cast<ActorPackageData*>(reinterpret_cast<LowProcess*>(this)->GetCurrentPackageData());
    if (data)
        reinterpret_cast<ActorPackageDataVirtualCall*>(data)->SetReferenceTarget(reference);
}

// @fnv 0x008d1070
void BaseProcess::Revert(BGSLoadFormBuffer* buffer)
{
    m_fValue1 = -1.0F;
    m_uiStateFlags = 0;
    reinterpret_cast<ActorPackageCall*>(&m_kProcessData)->FUN_008c6c80(buffer);
    if (m_pCachedValues)
        reinterpret_cast<CachedValuesCall*>(m_pCachedValues)->ClearField44();
}

// @fnv 0x008d0f90
void BaseProcess::LoadGame(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<BGSLoadFormBuffer*>(buffer)->ReadTypedData(&m_fValue2, 4);
    if (reinterpret_cast<BGSLoadFormBufferVirtual*>(buffer)->GetVersion() >= 6)
    {
        reinterpret_cast<BGSLoadFormBuffer*>(buffer)->ReadTypedData(&m_fValue1, 4);
        reinterpret_cast<BGSLoadFormBuffer*>(buffer)->ReadTypedData(&m_uiStateFlags, 4);
    }
    reinterpret_cast<ActorPackageCall*>(&m_kProcessData)->LoadGame(buffer);
}

// @fnv 0x008d0660
void BaseProcess::Copy(BaseProcess* source)
{
    if (!source)
        return;
    void* thisMiddleHigh;
    void* sourceSecond;
    void* sourceMiddleHigh;
    void* thisSecond;
    void* thisThird;
    void* sourceThird;
    void* sourceLow;
    void* thisLow;
    thisThird = __RTDynamicCast(source, 0, &DAT_0118a6b8, &DAT_0118a6d4, 0);
    sourceLow = __RTDynamicCast(source, 0, &DAT_0118a6b8, &DAT_0118c64c, 0);
    thisMiddleHigh = __RTDynamicCast(source, 0, &DAT_0118a6b8, &DAT_011a3668, 0);
    sourceMiddleHigh = __RTDynamicCast(source, 0, &DAT_0118a6b8, &DAT_011a364c, 0);
    thisSecond = __RTDynamicCast(this, 0, &DAT_0118a6b8, &DAT_0118a6d4, 0);
    sourceSecond = __RTDynamicCast(this, 0, &DAT_0118a6b8, &DAT_0118c64c, 0);
    sourceThird = __RTDynamicCast(this, 0, &DAT_0118a6b8, &DAT_011a3668, 0);
    thisLow = __RTDynamicCast(this, 0, &DAT_0118a6b8, &DAT_011a364c, 0);
    if (thisThird)
    {
        if (reinterpret_cast<BaseProcessCopyVirtual*>(thisThird)->vfn_1e0() > 0.0)
        {
            reinterpret_cast<BaseProcessCopyVirtual*>(thisThird)->vfn_214();
            reinterpret_cast<BaseProcessCopyVirtual*>(thisThird)->vfn_12c(0);
        }
    }
    if (thisSecond)
    {
        if (reinterpret_cast<BaseProcessCopyVirtual*>(thisSecond)->vfn_1e0() > 0.0)
        {
            reinterpret_cast<BaseProcessCopyVirtual*>(thisSecond)->vfn_214();
            reinterpret_cast<BaseProcessCopyVirtual*>(thisSecond)->vfn_12c(0);
        }
    }
    if (thisSecond && thisThird)
        reinterpret_cast<MiddleHighProcessCall*>(thisSecond)
            ->CopyProcessDataFrom(reinterpret_cast<MiddleHighProcessCall*>(thisThird));
    if (sourceSecond && sourceLow)
        reinterpret_cast<CopyCall00914c60*>(sourceSecond)->FUN_00914c60(reinterpret_cast<CopyCall00914c60*>(sourceLow));
    if (sourceThird && thisMiddleHigh)
        reinterpret_cast<CachedValuesCopyCall*>(sourceThird)
            ->Copy(reinterpret_cast<CachedValuesCopyCall*>(thisMiddleHigh));
    if (thisLow && sourceMiddleHigh)
        reinterpret_cast<LowProcessCopyCall*>(thisLow)->HandlePackageChange(
            reinterpret_cast<LowProcessCopyCall*>(sourceMiddleHigh));
    if (m_pCachedValues && source->m_pCachedValues)
        reinterpret_cast<LowProcessCachedCopyCall*>(m_pCachedValues)
            ->HandlePackageChange(reinterpret_cast<LowProcessCachedCopyCall*>(source->m_pCachedValues));
}

struct FUN_0049bb50_shell : public ActorPackageContext
{
    void AddToOffset(int);
};

// @fnv 0x0049bb50
void FUN_0049bb50_shell::AddToOffset(int aiOffset)
{
    *(int*)((char*)this + 0xc) += aiOffset;
}

struct Dummy_00527770
{
    void FUN_00527770(int arg);
};

// Calls FUN_00527770 with 0x25, sets the first pointer to "@kR", and zeroes the ints at offsets 16 and 20 before returning pThis.
// @fnv 0x00526b00
void* __fastcall FUN_00526b00(void* pThis)
{
    ((Dummy_00527770*)pThis)->FUN_00527770(0x25);
    *(const char**)pThis = "@kR";
    *((int*)pThis + 4) = 0;
    *((int*)pThis + 5) = 0;
    return pThis;
}

struct FUN_008d03e0_shell : public BaseProcess
{
    int DeallocateSound();
};

class TESSound
{
  public:
    unsigned int Deallocate(void);
};

// @fnv 0x008d03e0
int FUN_008d03e0_shell::DeallocateSound()
{
    return reinterpret_cast<TESSound*>(reinterpret_cast<char*>(this) + 4)->Deallocate();
}

struct FUN_008d0640_shell : public BaseProcess
{
    void InitProcess();
};

extern int DAT_01085e2c;
void __fastcall DeleteData(void* pThis);

// @fnv 0x008d0640
void FUN_008d0640_shell::InitProcess()
{
    *reinterpret_cast<int**>(this) = &DAT_01085e2c;
    DeleteData(reinterpret_cast<char*>(this) + 4);
}

// @fnv 0x008d1030
void __fastcall ClearField44(int param_1)
{
    *reinterpret_cast<int*>(param_1 + 0x44) = 0;
}

struct FUN_00524b60_shell
{
    unsigned char __thiscall GetByteAt102();
};

// @fnv 0x00524b60
unsigned char __thiscall FUN_00524b60_shell::GetByteAt102()
{
    return *(unsigned char*)((char*)this + 0x102);
}

extern float DAT_01085df0;

struct FUN_008d02d0_shell
{
    float GetNegativeGlobal(void* apActor, int abWhichList);
};

// @fnv 0x008d02d0
float FUN_008d02d0_shell::GetNegativeGlobal(void* apActor, int abWhichList)
{
    (void)apActor;
    (void)abWhichList;
    return -DAT_01085df0;
}

struct MobileObject;
struct TESIdleForm;

struct FUN_008d02f0_shell
{
    bool __thiscall FUN_008d02f0(MobileObject* apMobile, TESIdleForm* apIdle, int aeType, bool abForce3d,
                                 bool abChooseNewOne, bool abTestConditions);
};

// @fnv 0x008d02f0
bool __thiscall FUN_008d02f0_shell::FUN_008d02f0(MobileObject* apMobile, TESIdleForm* apIdle, int aeType,
                                                 bool abForce3d, bool abChooseNewOne, bool abTestConditions)
{
    return false;
}

struct FUN_008d0350_shell
{
    void __thiscall FUN_008d0350(int, int, int, int, int, int, int);
};

// @fnv 0x008d0350
void __thiscall FUN_008d0350_shell::FUN_008d0350(int, int, int, int, int, int, int)
{}

struct ActiveEffect;
struct Actor;
struct ActorCause;
struct ActorMover;
struct ActorValueOwner;
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
struct BSFile;
struct BSMultiBound;
struct BSMultiBoundRoom;
struct SoundPlaybackHandle;
struct BipedAnim;
struct CHUNK;
struct CombatGroupCollection;
struct CellMopp;
struct ChangeData;
struct ChangesMap;
struct CombatController;
struct ActorCombatGroup;
struct ContinuousBeamProjectile;
struct CellReferenceChangeData;
struct Crime;
struct GameFormRecord;
struct DialogueResponse;
struct DetectionParameters;
struct TeleportableReference;
struct EffectItem;
struct ExteriorCellNewReferencesMap;
struct ExtraDataList;
struct ExtraLock;
struct FormRecordHeader;
struct TESFileGroup;
struct CellChangesMap;
struct FurnitureMark;
struct HWND__;
struct BooleanIntegerAccessor;
struct BooleanFloatQuery;
struct IDebugText;
struct InteriorCellNewReferencesMap;
struct InventoryChanges;
struct InventoryStackRecord;
struct CellDataNode;
struct FormRecordMetadata;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct MapMarkerData;
struct MobileObject;
struct WorldReferenceObject;
struct Point3Offset;
struct NiAVObject;
struct AnimationInterpolator;
struct NiColor;
struct NiControllerManager;
struct NiControllerSequence;
struct NiFixedString;
struct NiGeometry;
struct NiLight;
struct ThreeByThreeMatrix;
struct NiNode;
struct NiPoint3;
struct NiPointLight;
struct NiTexture;
struct NumericIDBufferMap;
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
struct SaveGameRecord;
struct FormIDEntry;
struct SaveGameFile;
struct EmptyClass;
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
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESIdleForm;
struct TESModel;
struct TESObject;
struct TESObjectARMO;
struct TESObjectBOOK;
struct TESObjectCLOT;
struct TESObjectLIGH;
struct TESObjectREFR;
struct TESObjectWEAP;
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
struct _FILETIME;
struct _SYSTEMTIME;
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
struct blob8
{
    char b[8];
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
struct TESSaveLoadGame
{
    void NotifyFormIDChanged(TESForm*, unsigned int);
    void SetFormFlags(TESForm*, unsigned int);
    void ClearFormChangeFlags(TESForm*, unsigned int);
    void HasFormChanges(TESForm*, bool);
    unsigned int GetChangeFlags(TESForm*, bool);
    void AllowChanges(bool);
    bool GetAllowChanges();
    unsigned int GetFileSize();
    bool SaveGame(BSFile*, char*, bool);
    bool LoadGame(BSFile*, char*, bool);
    void SaveGameHeader(BSFile*);
    void SaveGameHeader(BSFile*, char*);
    void ConvertArrayByteOrder(double*, unsigned int);
    void ConvertArrayByteOrder(NiPoint3*, unsigned int);
    void ConvertArrayByteOrder(float*, unsigned int);
    void ConvertArrayByteOrder(unsigned long*, unsigned int);
    void ConvertArrayByteOrder(long*, unsigned int);
    void ConvertArrayByteOrder(unsigned int*, unsigned int);
    void ConvertArrayByteOrder(int*, unsigned int);
    void ConvertArrayByteOrder(unsigned short*, unsigned int);
    void ConvertArrayByteOrder(short*, unsigned int);
    void ConvertArrayByteOrder(void*, unsigned int);
    void ConvertTypedArrayByteOrder(double*, unsigned int);
    void ConvertTypedArrayByteOrder(NiPoint3*, unsigned int);
    void ConvertTypedArrayByteOrder(float*, unsigned int);
    void ConvertTypedArrayByteOrder(unsigned long*, unsigned int);
    void ConvertTypedArrayByteOrder(long*, unsigned int);
    void ConvertTypedArrayByteOrder(unsigned int*, unsigned int);
    void ConvertTypedArrayByteOrder(int*, unsigned int);
    void ConvertTypedArrayByteOrder(unsigned short*, unsigned int);
    void ConvertTypedArrayByteOrder(short*, unsigned int);
    void ConvertTypedArrayByteOrder(void*, unsigned int);
    void SwapUnsignedIntByteOrder(unsigned int*, unsigned int);
    bool ValidateFormIDArray(unsigned int*, unsigned int);
    unsigned short GetFileNameSaveSize(char*);
    void SaveFileName(char*);
    char* ReadFileName(char*);
    unsigned int EndianConvert(unsigned int);
    int EndianConvert(int);
    unsigned short EndianConvert(unsigned short);
    short EndianConvert(short);
    unsigned char EndianConvert(unsigned char);
    char EndianConvert(char);
    void LoadDataBlock(void*, unsigned int, unsigned int);
    void SaveDataBlock(void*, unsigned int, unsigned int);
    void WriteFile(BSFile*, NiPoint3*, unsigned int);
    void WriteFile(BSFile*, float*, unsigned int);
    void WriteFile(BSFile*, unsigned long*, unsigned int);
    void WriteFile(BSFile*, long*, unsigned int);
    void WriteFile(BSFile*, unsigned int*, unsigned int);
    void WriteFile(BSFile*, int*, unsigned int);
    void WriteFile(BSFile*, unsigned short*, unsigned int);
    void WriteFile(BSFile*, short*, unsigned int);
    unsigned int WriteFile(BSFile*, void*, unsigned int);
    void ReadFile(BSFile*, NiPoint3*, unsigned int);
    void ReadFile(BSFile*, float*, unsigned int);
    void ReadFile(BSFile*, unsigned long*, unsigned int);
    void ReadFile(BSFile*, long*, unsigned int);
    void ReadFile(BSFile*, unsigned int*, unsigned int);
    void ReadFile(BSFile*, int*, unsigned int);
    void ReadFile(BSFile*, unsigned short*, unsigned int);
    void ReadFile(BSFile*, short*, unsigned int);
    unsigned int ReadFile(BSFile*, void*, unsigned int);
    void WriteFileEndian(BSFile*, void*, unsigned int, unsigned int);
    void ReadFileEndian(BSFile*, void*, unsigned int, unsigned int);
    void AdvanceBuffer(unsigned int);
    bool GetLoading();
    bool GetIniting();
    bool GetConstructingObject();
    bool GetInitObject();
    bool GetPositioning();
    bool GetTemporarilyMovingRef();
    bool GetRevertingCurrentChanges();
    bool GetLoadingTempRefs();
    bool GetDeferInitForms();
    bool GetSimulatedMode();
    bool GetSkyLoading();
    bool GetSaveGameLoading();
    bool GetReconstructingObjects();
    bool GetFadingInFromSaveGame();
    bool GetLoadingGlobalData();
    bool GetAutosaveWhenFadedIn();
    bool GetBusy();
    bool GetLoadingCreatedBaseObjects();
    bool GetPositioningPlayerCharacter();
    void SetLoading(bool);
    void SetIniting(bool);
    void SetConstructingObject(bool);
    void SetInitObject(bool);
    void SetPositioning(bool);
    void SetTemporarilyMovingRef(bool);
    void SetRevertingCurrentChanges(bool);
    void SetLoadingTempRefs(bool);
    void SetDeferInitForms(bool);
    void SetSimulatedMode(bool);
    void SetSkyLoading(bool);
    void SetSaveGameLoading(bool);
    void SetReconstructingObjects(bool);
    void SetFadingInFromSaveGame(bool);
    void SetLoadingGlobalData(bool);
    void SetAutosaveWhenFadedIn(bool);
    void SetBusy(bool);
    void SetLoadingCreatedBaseObjects(bool);
    void SetPositioningPlayerCharacter(bool);
    void* GetBufferPointer();
    void SetBufferPointer(void*);
    bool LoadForm(TESForm*);
    bool SetFormLoaded(TESForm*);
    bool FormReconstructionMap(TESObjectCELL*);
    void LoadCellChanges(void*, CellChangesMap*, bool);
    TESPackage* CreatePackageForType(unsigned int, unsigned char);
    void ClearFormID(unsigned int);
    bool HasReferenceMoved(TESObjectCELL*, TESObjectREFR*, unsigned int);
    bool GetRevertBefore();
    bool GetRevertAfter();
    unsigned int ComputeArmorHash(Actor*);
    unsigned int ConvertNumericID(unsigned int);
    unsigned int ReverseConvertNumericID(unsigned int);
    void SerializeFormToBuffer(char*, TESForm*, unsigned int, unsigned char, bool);
    static void DrawDebugText(TESObjectREFR*, int, int*, int*);
    void QueueRemoveChange(unsigned int);
    void QueueRemoveReferenceChange(TESObjectREFR*, unsigned short);
    void QueueAttachedAnimationLoad(TESObjectREFR*, unsigned short);
    void QueueCharControllerLoad(TESObjectREFR*, unsigned short);
    void QueueHavokDataLoad(TESObjectREFR*, unsigned short);
    void Autosave();
    void Autoload();
    void Quicksave();
    bool Quickload();
    void GetSaveGameDisplayData(BSFile*, unsigned int*, char*, char*, char*);
    NiTexture* GetSaveGameDataOLD(BSFile*, unsigned int*, char*, char*, char*, char*, char*, char*, int*, bool);
    NiTexture* GetSaveGameData(BSFile*, unsigned int, unsigned int*, char*, unsigned short*, char*, float*,
                               _SYSTEMTIME*, unsigned int*, int*);
    void ReadSaveGameMetadata(BSFile*, unsigned int*, char*, char*, _FILETIME*, char*);
    void GenerateSaveGameDataOLD(char*, char*, char*);
    void* GetSaveGameList();
    void BuildSaveGameList();
    void DeleteSaveGameList();
    void LoadQueuedData(bool);
    bool IsFormIDInChangesMap(unsigned int);
    unsigned int GetMappedFormID(unsigned int, int, int);
    bool HasQueuedChanges();
    void RegisterCreatedBaseObject(TESForm*);
    void RemoveCreatedBaseObject(unsigned int);
    void RemoveCreatedBaseObject(TESForm*);
    unsigned int GetFormIDFromArray(unsigned int);
    unsigned int GetNumericIDFromArray(unsigned int);
    unsigned short AddWorldSpaceIDToArray(unsigned int);
    unsigned int GetWorldSpaceIDFromArray(unsigned short);
    void UpdateLoadingSequence();
    unsigned int PurgeSavedDataForCell(TESObjectCELL*);
    unsigned int PurgeSavedDataForWorld(TESWorldSpace*);
    unsigned int PurgeSavedDataForLocation(unsigned int, bool);
    bool GetInitArrayExists();
    unsigned char GetCurrentVersion();
    void SetCurrentVersion(unsigned char);
    void ResetVersions();
    void ResetCurrentVersion();
    void TestAllCells(unsigned int);
    void SaveQueuedHavokData(TESObjectREFR*);
    void SaveQueuedAttachedAnimation(TESObjectREFR*);
    void ApplyFormChanges(bool);
    void RevertForm(TESForm*, ChangeData*);
    void PerformDeferredDeletions();
    void PerformDeferredInitActorPackages();
    void RevertGlobalData();
    void SetUseNumericIDArray(bool);
    bool GetUseNumericIDArray();
    bool DynamicCastByRTTI();
    void QueueFormForFinalization(TESForm*);
    void FinalizeQueuedForms();
    void FinalizeForm(TESForm*);
    FormRecordMetadata* GetCurrentlyLoadingFormHeader();
    FormIDEntry* GetCurrentlySavingFormHeader();
    void* CreateQueuedBuffer(unsigned short);
    void SafetyCheckReferencePositionAndAngle(TESObjectREFR*);
    bool IsInvalidPoint(NiPoint3*);
    _FILETIME* GetMostRecentSaveGame();
    void DeleteForm(TESForm*);
    void AddFormToInitFormArray(TESForm*);
    unsigned int GetNeedToConvertPCSaveGames();
    bool ConvertPCSaveGames();
    void RemoveFormFromInitFormArray(TESForm*);
    void CleanUpExpiredData();
    void TestSaveCreatedBaseObjects();
    void ClearNextSaveNumber();
    void AddInitItem(TESForm*);
    bool GetReconstructedAllObjects();
    void CleanupMaps();
    ChangeData* GetChanges(TESForm*);
    unsigned int ContainsAnyFlags(TESForm*, unsigned int);
    void LoadAnimationForReference(TESObjectREFR*, unsigned int, void*);
    void LoadAttachedAnimationForReference(TESObjectREFR*, void*);
    void LoadHavokDataForReference(TESObjectREFR*, void*);
    unsigned short GetQueuedBufferSaveSize(void*);
    BSFile* PrepForLoadSave(BSFile*, char*, int);
    void CleanupLoadSave(BSFile*, int);
    unsigned int LoadHeader(BSFile*, bool);
    void SaveHeader(BSFile*, char*);
    void SaveGlobalData(BSFile*);
    void LoadGlobalData(BSFile*);
    void SerializeChangeData(BSFile*);
    void LoadChangeData(BSFile*);
    void FreeChangeData(void*);
    void WriteCreatedBaseObjects(BSFile*);
    void LoadCreatedBaseObjects(BSFile*);
    void DeleteCreatedBaseObjects();
    void PrepareLoadGame(BSFile*);
    bool IsValidSaveGame(BSFile*);
    void LoadChangeFormData(BSFile*);
    void LoadNumericIDArrays(BSFile*);
    void LoadFormRecords(BSFile*);
    void LoadFinalData(BSFile*);
    void LoadAnimations();
    void LoadAttachedAnimations();
    void LoadCharControllers();
    void LoadHavokData();
    void QueueBufferLoad(NumericIDBufferMap*, unsigned int, unsigned short);
    void CleanupCurrentGameState();
    void StartLoadingSequence();
    void EndLoadingSequence();
    unsigned int GetOrCreateFormID(TESForm*, unsigned int);
    void CreateChangedReference(unsigned int);
    TESForm* CreateReference(unsigned int, CellReferenceChangeData*);
    TESForm* CreateReferenceFromFile(unsigned int, WorldReferenceObject*);
    unsigned short AddFormIDToArray(TESForm*, unsigned int);
    void LoadInitialDataForForm(TESForm*, unsigned int);
    void AddFormToChangesMap(TESForm*, unsigned int);
    void* CreateBuffer(unsigned int);
    void SaveBuffer(BSFile*, void*, unsigned int);
    void LoadBuffer(BSFile*, void*, unsigned int);
    void DisposeBuffer(void*);
    void FinishLoad();
    bool ResetReferencePosition(TESObjectREFR*, bool);
    int ResetObject(TESForm*, unsigned int, unsigned int);
    bool InitObject(TESForm*, unsigned int, bool);
    void SetRevertState(int);
    static int SaveGameCompare(SaveGameFile*, SaveGameFile*);
    void GenerateSaveGameFileName(char*);
    void StripIllegalCharacters(char*);
    SaveGameRecord* GetRevertStateInfo(TESForm*);
    void ProcessRevertStateInfo(TESForm*, SaveGameRecord*);
    void SetCurrentlyLoadingFormHeader(FormRecordMetadata*);
    void SetCurrentlySavingFormHeader(FormIDEntry*);
    void ReInitForcedChanges(TESForm*, unsigned int);
    void SaveMostRecentSaveGame(BSFile*);
    void LoadMostRecentSaveGame();
    unsigned int CalculateNextSaveNumber();
    unsigned int GetNextSaveNumber();
    void SetReconstructedAllObjects(bool);
    void ReconstructAllObjects();
    bool CheckShouldReconstructAllObjects(struct blob12, TESObjectCELL*, TESWorldSpace*);
    void DisplayCorruptSaveGameMessage(BSFile*);
    void* __vecDelDtor(unsigned int);
    ChangesMap* m_pChangesMap;
    ChangesMap* m_pAlternateChangesMap;
    InteriorCellNewReferencesMap* m_pInteriorCellNewReferencesMap;
    ExteriorCellNewReferencesMap* m_pExteriorCellNewReferencesMap1;
    ExteriorCellNewReferencesMap* m_pExteriorCellNewReferencesMap2;
    void* m_pBuffer;
    unsigned int m_uiBufferSize;
    bool m_bLoading;
    char _pad_1d[3];
    void* m_pSaveGameFile;
    char m_acBuffer1[8];
    char m_acBuffer2[8];
    char m_acBuffer3[8];
    char m_acBuffer4[8];
    EmptyClass* m_pSaveGameEntry;
    int m_iEntryCount;
    unsigned char m_ucSaveVersion;
    char _pad_4d[3];
    unsigned char* m_pNumericIDBuffer;
    unsigned int m_uiDataBufferSize;
    NumericIDBufferMap* m_pNumericIDBufferMap1;
    NumericIDBufferMap* m_pNumericIDBufferMap2;
    NumericIDBufferMap* m_pNumericIDBufferMap3;
    NumericIDBufferMap* m_pNumericIDBufferMap4;
    char m_acNumericIDData[8];
    void* m_pNumericIDBufferData;
    unsigned char m_ucSaveFlags;
    unsigned char m_ucLoadFlags;
    char _pad_76[2];
    void* m_pLoadingFormRecordHeader;
    void* m_pSavingFormIDEntry;
    unsigned char m_ucCurrentFormRecordType;
    bool m_bCurrentFormHeaderActive;
    char _pad_82[2];
    FormRecordMetadata* m_pCurrentLoadingFormHeader;
    FormIDEntry* m_pCurrentSavingFormHeader;
    unsigned int m_uiNextFormID;
    unsigned int m_uiSaveNumber;
    unsigned int m_uiFormRecordCount;
    char m_acSaveGameSignature[16];
    unsigned int m_uiCurrentFormRecordCount;
    bool m_bSaveGameLoaded;
    bool m_bSaveGameCorrupt;
    bool m_bHasPendingChanges;
    bool m_bNeedsReferenceReconstruction;
    void* m_pSaveGameListData;
    char m_acSaveGamePath[272];
    _FILETIME* m_pMostRecentSaveTime;
};
typedef char _sizecheck_TESSaveLoadGame[sizeof(TESSaveLoadGame) == 456 ? 1 : -1];
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct TESChildCell
{
    virtual TESObjectCELL* GetSaveParentCell();
};
typedef char _sizecheck_TESChildCell[sizeof(TESChildCell) == 4 ? 1 : -1];
struct FUN_008d0370_shell : public TESSaveLoadGame
{
    bool FUN_008d0370(TESForm*);
};

// @fnv 0x008d0370
bool FUN_008d0370_shell::FUN_008d0370(TESForm* apForm)
{
    return 0;
}

struct FUN_008d0390_shell
{
    float GetDistanceBetweenActors(void* apActor, void* apTarget);
};

// @fnv 0x008d0390
float __thiscall FUN_008d0390_shell::GetDistanceBetweenActors(void* apActor, void* apTarget)
{
    return 0.0f;
}

struct FUN_008d05f0_shell
{
    float FUN_008d05f0(int aiWhich);
};

// @fnv 0x008d05f0
float __thiscall FUN_008d05f0_shell::FUN_008d05f0(int aiWhich)
{
    return 0.0f;
}

extern const NiPoint3 _NiPoint3_ZERO;

// @fnv 0x008d08f0
const NiPoint3* __fastcall FUN_008d08f0(BaseProcess* this_)
{
    return &_NiPoint3_ZERO;
}

struct FUN_008d10c0_shell
{
    float UpdateProcessTiming();
};
// @fnv 0x008d10c0
float FUN_008d10c0_shell::UpdateProcessTiming()
{
    return 20.0f;
}

struct FUN_00acb7e0_shell : public BaseProcess
{
    int FUN_00acb7e0();
};

// @fnv 0x00acb7e0
int FUN_00acb7e0_shell::FUN_00acb7e0()
{
    return -1;
}

struct FUN_008cc730_s
{
    void FUN_008cc730(MobileObject*, float, float, float);
};
// @fnv 0x008cc730
void FUN_008cc730_s::FUN_008cc730(MobileObject* apRef, float x, float y, float z)
{}

namespace fnv_008d02a0 {
struct NiPoint3
{
    float x, y, z;
};
extern const NiPoint3 _NiPoint3_ZERO;
struct Actor;
struct FUN_008d02a0_shell
{
    NiPoint3 FUN_008d02a0(Actor* apActor);
};
// @fnv 0x008d02a0
NiPoint3 FUN_008d02a0_shell::FUN_008d02a0(Actor* apActor)
{
    return _NiPoint3_ZERO;
}
}  // namespace fnv_008d02a0

namespace fnv_008d0310 {
struct NiPoint3
{
    float x, y, z;
};
extern const NiPoint3 _NiPoint3_ZERO;
struct Actor;
struct FUN_008d0310_shell
{
    NiPoint3 FUN_008d0310(Actor* apActor, int abWhichList);
};
// @fnv 0x008d0310
NiPoint3 FUN_008d0310_shell::FUN_008d0310(Actor* apActor, int abWhichList)
{
    return _NiPoint3_ZERO;
}
}  // namespace fnv_008d0310

struct DetectionViewData;
struct FUN_008d0340_s
{
    DetectionViewData* FUN_008d0340(Actor*, int, bool, int, int, bool, bool);
};
// @fnv 0x008d0340
DetectionViewData* FUN_008d0340_s::FUN_008d0340(Actor* apactor, int aedetect, bool abLineSight, int aiLevel,
                                                int abWhichList, bool ab360view, bool abcombat)
{
    return 0;
}

struct FUN_008d0380_s
{
    void FUN_008d0380(Actor*, bool, TESBoundObject*, int, ExtraDataList*, bool, bool, bool, bool, bool, bool);
};
// @fnv 0x008d0380
void FUN_008d0380_s::FUN_008d0380(Actor* apActor, bool abEquip, TESBoundObject* apObject, int aiNumber,
                                  ExtraDataList* apExtra, bool abNow, bool abForceEquip, bool abFromMenus,
                                  bool abForceUnequip, bool abEquipCalling, bool abPlayPickUpSounds)
{}

struct GO
{
    ~GO();
    void* p;
};
struct FUN_008d04d0_s
{
    void FUN_008d04d0(GO apCon);
};
// @fnv 0x008d04d0
void FUN_008d04d0_s::FUN_008d04d0(GO apCon)
{}

struct FUN_008d04f0_s
{
    void FUN_008d04f0(Actor*, TESTopic*, bool, bool, bool, bool);
};
// @fnv 0x008d04f0
void FUN_008d04f0_s::FUN_008d04f0(Actor* apActor, TESTopic* aptopic, bool abForceSub, bool abStop, bool abQue,
                                  bool abSayCallBack)
{}

struct FUN_008d0500_s
{
    void FUN_008d0500(Actor*, bool, bool, int, bool);
};
// @fnv 0x008d0500
void FUN_008d0500_s::FUN_008d0500(Actor* apActor, bool abNewpackage, bool abInterateIndex, int emovemode,
                                  bool abSecondLoc)
{}

struct ActorCombatGroup;
struct FUN_008d0530_s
{
    bool FUN_008d0530(Actor*, Actor*, bool, bool, ActorCombatGroup*, bool, bool, bool, char, bool, bool, bool, TESPackage*);
};
// @fnv 0x008d0530
bool FUN_008d0530_s::FUN_008d0530(Actor* apActor, Actor* apTarget, bool abCheckForAmbush, bool absendalarm,
                                  ActorCombatGroup* apGroup, bool abfleeing, bool abForceFlee, bool abAggressor, char acTeam,
                                  bool bforcecombat, bool abForceAttack, bool abCastSpell, TESPackage* apPackage)
{
    return false;
}

struct FUN_008d0570_s
{
    int FUN_008d0570(TESActorBase*, int, Actor*);
};
// @fnv 0x008d0570
int FUN_008d0570_s::FUN_008d0570(TESActorBase* apActorBase, int aiWhich, Actor* apActor)
{
    return -1;
}

struct FUN_008d0580_s
{
    float FUN_008d0580(TESActorBase*, int, Actor*);
};
// @fnv 0x008d0580
float FUN_008d0580_s::FUN_008d0580(TESActorBase* apActorBase, int aiWhich, Actor* apActor)
{
    return 0.0f;
}

struct SoundPlaybackHandle
{
    SoundPlaybackHandle();
    ~SoundPlaybackHandle();
    int a;
};
struct FUN_008d0590_shell
{
    SoundPlaybackHandle CreateDefaultInstance(int aeType);
};
// Constructs and returns a default-constructed instance of the local struct type, ignoring the passed type argument.
// @fnv 0x008d0590
SoundPlaybackHandle FUN_008d0590_shell::CreateDefaultInstance(int aeType)
{
    return SoundPlaybackHandle();
}

struct Date
{
    ~Date();
    int a;
    int b;
    int c;
};
struct FUN_008d05c0_s
{
    void FUN_008d05c0(int, Date);
};
// @fnv 0x008d05c0
void FUN_008d05c0_s::FUN_008d05c0(int a, Date d)
{}

struct FUN_008d0600_s
{
    void FUN_008d0600(int, int);
};
// @fnv 0x008d0600
void FUN_008d0600_s::FUN_008d0600(int a, int b)
{}

struct FUN_008c64d0_target
{
    void FUN_008c64d0(unsigned int, unsigned int);
};
struct FUN_008d0e60_shell
{
    void FUN_008d0e60(unsigned int aiFlags, unsigned int aiOldFlags, MobileObject* pmob);
};

// Forwards the new and old flag values to the object at offset 4 of this shell.
// @fnv 0x008d0e60
void FUN_008d0e60_shell::FUN_008d0e60(unsigned int aiFlags, unsigned int aiOldFlags, MobileObject* pmob)
{
    ((FUN_008c64d0_target*)((char*)this + 4))->FUN_008c64d0(aiFlags, aiOldFlags);
}

struct BGSSaveFormBuffer
{
    void SaveData(void*, int, int);
};
struct FUN_008c65d0_target
{
    void SavePackage(BGSSaveFormBuffer*);
};
struct FUN_008d0f30_shell
{
    char* GetBase();
    void FUN_008d0f30(BGSSaveFormBuffer* apSaveGameBuffer);
};
// @fnv 0x008d0f30
void FUN_008d0f30_shell::FUN_008d0f30(BGSSaveFormBuffer* apSaveGameBuffer)
{
    apSaveGameBuffer->SaveData((char*)this + 0x1c, 4, 0);
    apSaveGameBuffer->SaveData((char*)this + 0x20, 4, 0);
    apSaveGameBuffer->SaveData((char*)this + 0x24, 4, 0);
    ((FUN_008c65d0_target*)((char*)this + 4))->SavePackage(apSaveGameBuffer);
}

struct FUN_008c65a0_shell
{
    void FUN_008c65a0(int);
};
struct FUN_008d0f10_s
{
    int pad0;
    FUN_008c65a0_shell sub;
    void FUN_008d0f10(unsigned int aiFlags, MobileObject* pmob);
};
// @fnv 0x008d0f10
void FUN_008d0f10_s::FUN_008d0f10(unsigned int aiFlags, MobileObject* pmob)
{
    sub.FUN_008c65a0(aiFlags);
}

namespace fnv_008d0900 {
struct MobileObject
{
};

struct FormIDEntry
{
    unsigned int iFormID;
    unsigned char pad;
    unsigned char iFlags[4];
};

struct TESForm
{
    virtual void v0()
    {}
    virtual void v1()
    {}
    virtual void v2()
    {}
    virtual void v3()
    {}
    virtual void v4()
    {}
    virtual void v5()
    {}
    virtual void v6()
    {}
    virtual void v7()
    {}
    virtual void v8()
    {}
    virtual void v9()
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
    virtual void v18()
    {}
    virtual void v19()
    {}
    virtual void v20()
    {}
    virtual void v21()
    {}
    virtual void v22()
    {}
    virtual void v23()
    {}
    virtual void v24()
    {}
    virtual void v25()
    {}
    virtual void v26()
    {}
    virtual void v27()
    {}
    virtual void v28()
    {}
    virtual void v29()
    {}
    virtual void v30()
    {}
    virtual void v31()
    {}
    virtual void v32()
    {}
    virtual void v33()
    {}
    virtual void v34()
    {}
    virtual void v35()
    {}
    virtual void v36()
    {}
    virtual void v37()
    {}
    virtual void v38()
    {}
    virtual void v39()
    {}
    virtual void v40()
    {}
    virtual void v41()
    {}
    virtual void v42()
    {}
    virtual void v43()
    {}
    virtual void v44()
    {}
    virtual void v45()
    {}
    virtual void v46()
    {}
    virtual void v47()
    {}
    virtual void v48()
    {}
    virtual void v49()
    {}
    virtual void v50()
    {}
    virtual void v51()
    {}
    virtual void v52()
    {}
    virtual void v53()
    {}
    virtual void v54()
    {}
    virtual void v55()
    {}
    virtual void v56()
    {}
    virtual void v57()
    {}
    virtual void v58()
    {}
    virtual void v59()
    {}
    virtual void v60()
    {}
    virtual void v61()
    {}
    virtual void v62()
    {}
    virtual void v63()
    {}
    virtual void v64()
    {}
    virtual void v65()
    {}
    virtual void v66()
    {}
    virtual void v67()
    {}
    virtual void v68()
    {}
    virtual void v69()
    {}
    virtual void v70()
    {}
    virtual void v71()
    {}
    virtual void v72()
    {}
    virtual void v73()
    {}
    virtual void v74()
    {}
    virtual void v75()
    {}

    virtual const char* GetName()
    {
        return 0;
    }
};

struct TESSaveLoadGame
{
    bool FUN_00862110();
    void* GetHitSound();
};

typedef TESSaveLoadGame SaveManager;

extern SaveManager* DAT_011de45c;

struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};

extern GlobalObject_0045cf30 g_011de4e8;

struct Interface
{
    static void __cdecl PrintDebugMessage(const char* format, ...);
};

struct FUN_008c61a0_Class
{
    unsigned short ComputeTotal(unsigned int aiFlags);
};

TESForm* _ref_004839c0(unsigned int iFormID);

struct FUN_008d0900_shell
{
    unsigned short FUN_008d0900(unsigned int aiFlags, MobileObject* pmob);
};

// Accumulates a save-size value from the save manager, a virtual call on this+4, and a constant, logging the delta when the debug flag is set.
// @fnv 0x008d0900
unsigned short FUN_008d0900_shell::FUN_008d0900(unsigned int aiFlags, MobileObject* pmob)
{
    unsigned short pform;
    unsigned short pheader;
    FormIDEntry* isize;
    TESForm* itempStartSize;

    pform = 0;
    pheader = pform;

    if (DAT_011de45c->FUN_00862110())
    {
        pform += 4;
        pform += 2;
    }

    pform += reinterpret_cast<FUN_008c61a0_Class*>(reinterpret_cast<unsigned char*>(this) + 4)->ComputeTotal(aiFlags);
    pform += 4;

    if (*g_011de4e8.Bool())
    {
        isize = static_cast<FormIDEntry*>(DAT_011de45c->GetHitSound());
        if (isize)
        {
            itempStartSize = _ref_004839c0(isize->iFormID);
            Interface::PrintDebugMessage(
                "GetSaveSize(): %-5i for form %08X %s with flags %08X ending at line %i in file %s",
                static_cast<unsigned int>(pform) - pheader, isize->iFormID, itempStartSize->GetName(),
                *reinterpret_cast<unsigned int*>(isize->iFlags), 0xE8,
                "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\AI\\BaseProcess.cpp");
        }
        else
        {
            Interface::PrintDebugMessage("GetSaveSize(): %-5i ending at line %i in file %s",
                                         static_cast<unsigned int>(pform) - pheader, 0xE8,
                                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\AI\\BaseProcess.cpp");
        }
    }

    return pform;
}
}  // namespace fnv_008d0900

struct FUN_008d04a0_base
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
};

struct FUN_008d04a0_shell : public FUN_008d04a0_base
{
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
    virtual void vfn_144(int);
    void ForwardToVfn144(int, int);
};

// Calls the virtual function vfn_144 with param_3.
// @fnv 0x008d04a0
void FUN_008d04a0_shell::ForwardToVfn144(int, int aiValue)
{
    vfn_144(aiValue);
}

extern char DAT_01184920[];
extern char DAT_011846d4[];
extern void* DAT_011dea3c;

void* __cdecl FUN_00ec43fb(void*, int, char*, char*, int);

struct FUN_008a6ce0_shell
{
    void FUN_008a6ce0(int, int);
};

struct FUN_008d0e80_class
{
  public:
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00c();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01c();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02c();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03c();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04c();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05c();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06c();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07c();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08c();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09c();
    virtual void vfn_0a0();
    virtual void vfn_0a4();
    virtual void vfn_0a8();
    virtual void vfn_0ac();
    virtual void vfn_0b0();
    virtual void vfn_0b4();
    virtual void vfn_0b8();
    virtual void vfn_0bc();
    virtual void vfn_0c0();
    virtual void vfn_0c4();
    virtual void vfn_0c8();
    virtual void vfn_0cc();
    virtual void vfn_0d0();
    virtual void vfn_0d4();
    virtual void vfn_0d8();
    virtual void vfn_0dc();
    virtual void vfn_0e0();
    virtual void vfn_0e4();
    virtual void vfn_0e8();
    virtual void vfn_0ec();
    virtual void vfn_0f0();
    virtual void vfn_0f4();
    virtual void vfn_0f8();
    virtual void vfn_0fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual void vfn_1d0();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual void vfn_1e4();
    virtual void vfn_1e8();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual void vfn_1f4();
    virtual void vfn_1f8();
    virtual void vfn_1fc();
    virtual void vfn_200();
    virtual void vfn_204();
    virtual void vfn_208();
    virtual void vfn_20c();
    virtual void vfn_210();
    virtual void vfn_214();
    virtual void vfn_218();
    virtual void vfn_21c();
    virtual void vfn_220();
    virtual void vfn_224();
    virtual void vfn_228();
    virtual int vfn_22c();
    virtual void vfn_230();
    virtual void vfn_234();
    virtual void vfn_238();
    virtual void vfn_23c();
    virtual void vfn_240();
    virtual void vfn_244();
    virtual void vfn_248();
    virtual void vfn_24c();
    virtual void vfn_250();
    virtual void vfn_254();
    virtual void vfn_258();
    virtual void vfn_25c();
    virtual void vfn_260();
    virtual void vfn_264();
    virtual void vfn_268();
    virtual void vfn_26c();
    virtual void vfn_270();
    virtual void vfn_274();
    virtual void vfn_278();
    virtual void vfn_27c();
    virtual int vfn_280();
    virtual void vfn_284(int);
    void FUN_008d0e80(int p1, int p2, void* p3);
};

// @fnv 0x008d0e80
void __thiscall FUN_008d0e80_class::FUN_008d0e80(int aiUnused1, int aiUnused2, void* p3)
{
    void* t = FUN_00ec43fb(p3, 0, DAT_01184920, DAT_011846d4, 0);
    if (t != 0 && t != DAT_011dea3c && this->vfn_22c() == 0 && this->vfn_280() == -1)
    {
        this->vfn_284(0);
        ((FUN_008a6ce0_shell*)t)->FUN_008a6ce0(1, 1);
    }
}

struct SaveHeaderView
{
    unsigned int id;
    unsigned char type;
    unsigned char flags;
};
struct TESSaveLoadGameHelper
{
    unsigned int GetTimeStamp();
    bool FUN_00862110();
    void FUN_008579b0(void*, int);
    SaveHeaderView* GetHitSound();
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
class TimeGlobal
{
  public:
    unsigned int GetTimeStamp();
};
class GlobalObject_0045cf30
{
  public:
    unsigned char* Bool();
};
extern GlobalObject_0045cf30 g_011de4e8;
extern const char DAT_010865e0[];
extern const char DAT_010153a0[];
extern const char DAT_0101536c[];
extern const char DAT_01015318[];
void __cdecl FUN_0040fbe0(const char*, ...);
void __cdecl FNV_Warning(const char*, ...);
TESForm* __cdecl LookupFormByID(unsigned int);
struct ProcessData
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    void FUN_008c6250(unsigned int);
};
struct SavedProcess
{
    int unk00;
    ProcessData data;
    unsigned int unk1c;
    void FUN_008d0a10(unsigned int, unsigned int);
};
struct FormView
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
    virtual const char* Describe();
};
// @fnv 0x008d0a10
void SavedProcess::FUN_008d0a10(unsigned int flags, unsigned int unused)
{
    unsigned short length = 0;
    unsigned int* begin = 0;
    unsigned int initial = ((TimeGlobal*)g_TESSaveLoadGame)->GetTimeStamp();
    if (*g_011de4e8.Bool())
        initial = ((TimeGlobal*)g_TESSaveLoadGame)->GetTimeStamp();
    if (((TESSaveLoadGameHelper*)g_TESSaveLoadGame)->FUN_00862110())
    {
        unsigned int tag = 0x424c4f4b;
        ((TESSaveLoadGameHelper*)g_TESSaveLoadGame)->FUN_008579b0(&tag, 4);
        begin = (unsigned int*)((TimeGlobal*)g_TESSaveLoadGame)->GetTimeStamp();
        ((TESSaveLoadGameHelper*)g_TESSaveLoadGame)->FUN_008579b0(&length, 2);
    }
    data.FUN_008c6250(flags);
    ((TESSaveLoadGameHelper*)g_TESSaveLoadGame)->FUN_008579b0(&unk1c, 4);
    if (*g_011de4e8.Bool())
    {
        unsigned int header = ((TimeGlobal*)g_TESSaveLoadGame)->GetTimeStamp();
        SaveHeaderView* end = ((TESSaveLoadGameHelper*)g_TESSaveLoadGame)->GetHitSound();
        if (end)
        {
            TESForm* form = LookupFormByID(end->id);
            FUN_0040fbe0(DAT_010153a0, header - initial, end->id, ((FormView*)form)->Describe(),
                         *(unsigned int*)&end->flags, 0xf9, DAT_010865e0);
        }
        else
            FUN_0040fbe0(DAT_0101536c, header - initial, 0xf9, DAT_010865e0);
    }
    if (((TESSaveLoadGameHelper*)g_TESSaveLoadGame)->FUN_00862110())
    {
        unsigned int uiTimestamp = ((TimeGlobal*)g_TESSaveLoadGame)->GetTimeStamp();
        unsigned int finalPosition = (unsigned int)begin;
        if (uiTimestamp > finalPosition + 65535)
            FNV_Warning(DAT_01015318, DAT_010865e0, 0xf9);
        *(unsigned short*)begin = (unsigned short)(uiTimestamp - finalPosition);
    }
}

namespace fnv_008d0bc0 {
extern "C" char DAT_011de45c;
extern "C" char DAT_010865e0;
extern "C" char DAT_01015718;
extern "C" char DAT_010156a8;
extern "C" char DAT_01015588;
extern "C" char DAT_01015500;
extern "C" char DAT_010154a0;
extern "C" char DAT_01015440;
struct Record8d
{
    unsigned id;
    char data[6];
};
struct Reader8d
{
    bool FUN_00862110();
    void FUN_008579e0(void*, unsigned);
    Record8d* FUN_004fd3c0();
    unsigned char FUN_008df040();
    unsigned FUN_00825c00();
};
struct Object8d
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
    virtual const char* name();
};
Object8d* __cdecl LookupFormByID(unsigned);
void __cdecl FUN_005b5e40(const char*, ...);
struct Base8d
{
    void FUN_008c6320(void*, void*);
};
struct Target8d
{
    char pad[4];
    Base8d base;
    char rest[23];
    unsigned field;
    void LoadAndValidate(void*, void*, void*);
};
// Reads a tag and count from the reader, calls base.FUN_008c6320, reads field, then logs size mismatches between the recorded and actual block length.
// @fnv 0x008d0bc0
void Target8d::LoadAndValidate(void* arg1, void* arg2, void* arg3)
{
    unsigned short count = 0;
    unsigned start = 0;
    if ((*(Reader8d**)&DAT_011de45c)->FUN_00862110())
    {
        unsigned tag;
        (*(Reader8d**)&DAT_011de45c)->FUN_008579e0(&tag, 4);
        if (tag != 0x424c4f4b)
        {
            Record8d* record = (*(Reader8d**)&DAT_011de45c)->FUN_004fd3c0();
            if (record)
            {
                Object8d* object = LookupFormByID(record->id);
                FUN_005b5e40(&DAT_01015718, &DAT_010865e0, 0x104, record->id, object->name(),
                             *(unsigned char*)((char*)record + 9), *(unsigned*)((char*)record + 5));
            }
            else
            {
                FUN_005b5e40(&DAT_010156a8, &DAT_010865e0, 0x104, (*(Reader8d**)&DAT_011de45c)->FUN_008df040());
            }
        }
        start = (*(Reader8d**)&DAT_011de45c)->FUN_00825c00();
        (*(Reader8d**)&DAT_011de45c)->FUN_008579e0(&count, 2);
    }
    base.FUN_008c6320(arg1, arg2);
    (*(Reader8d**)&DAT_011de45c)->FUN_008579e0(&field, 4);
    if ((*(Reader8d**)&DAT_011de45c)->FUN_00862110())
    {
        unsigned end = (*(Reader8d**)&DAT_011de45c)->FUN_00825c00();
        Record8d* record = (*(Reader8d**)&DAT_011de45c)->FUN_004fd3c0();
        if (record)
        {
            Object8d* object = LookupFormByID(record->id);
            if (end > start + count)
            {
                FUN_005b5e40(&DAT_01015588, end - (start + count), &DAT_010865e0, 0x109, record->id, object->name(),
                             *(unsigned char*)((char*)record + 9), *(unsigned*)((char*)record + 5));
            }
            else if (end < start + count)
            {
                FUN_005b5e40(&DAT_01015500, start + count - end, &DAT_010865e0, 0x109, record->id, object->name(),
                             *(unsigned char*)((char*)record + 9), *(unsigned*)((char*)record + 5));
            }
        }
        else
        {
            if (end > start + count)
            {
                FUN_005b5e40(&DAT_010154a0, end - (start + count), &DAT_010865e0, 0x109,
                             (*(Reader8d**)&DAT_011de45c)->FUN_008df040());
            }
            else if (end < start + count)
            {
                FUN_005b5e40(&DAT_01015440, start + count - end, &DAT_010865e0, 0x109,
                             (*(Reader8d**)&DAT_011de45c)->FUN_008df040());
            }
        }
    }
}
}  // namespace fnv_008d0bc0

struct FUN_008d0610 : BaseProcess
{
    virtual ~FUN_008d0610();
};
// Destructor for a BaseProcess-derived class; empty body.
// @fnv 0x008d0610
FUN_008d0610::~FUN_008d0610()
{}
