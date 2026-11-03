
// src/fallout_shared/tes_ob1_variant.cpp - flag-variant unit created 2026-10-25 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/fallout_shared/tes.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout_shared/tes.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/tes.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct GlobalObject_00a7b610
{
};
extern GlobalObject_00a7b610 g_01202df8;
struct NiRTTI
{
};
struct FUN_00450620_shell
{
    const NiRTTI* GetNiRTTI() const;
};
struct BSTempNodeManager
{
    virtual ~BSTempNodeManager();
    void* FUN_00450630(unsigned int flags);
};
extern "C" void __cdecl FUN_00c44e20(BSTempNodeManager*);
extern void __cdecl __Dummy_00b6fef0(void*, unsigned int);
struct FUN_004512a0_shell
{
    unsigned char m_ucState;
    void SetState(unsigned char ucState);
};
extern char DAT_01189184;
void FUN_00451520(unsigned char value);
struct NP
{
    NP& operator=(void*);
};
extern NP DAT_011f95e8;
void FUN_00451570(void* arg);
extern unsigned char DAT_011ad86c;
void FUN_00451590(unsigned char value);
struct AlchemyItem;
struct BGSAddonNode;
struct BGSDebris;
struct BGSExplosion;
struct BGSMessage;
struct BGSPerk;
struct BGSPrimitive;
struct BGSProjectile;
struct BGSVoiceType;
struct FormRecordHeader;
struct InventoryChanges;
struct InventoryStackRecord;
struct NiAVObject;
struct NiPoint3;
struct NiTriBasedGeom;
struct Script;
struct TESAmmoEffect;
struct TESBoundObject;
struct TESCaravanDeck;
struct TESCasino;
struct TESChallenge;
struct TESClass;
struct TESCombatStyle;
struct TESEffectShader;
struct TESFaction;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESIdleForm;
struct TESLandTexture;
struct TESLoadScreenType;
struct TESObject;
struct TESObjectANIO;
struct TESObjectCELL;
struct TESFormList;
struct TESObjectREFR;
struct TESQuest;
struct TESRace;
struct TESRecipe;
struct TESRecipeCategory;
struct TESRegionDataManager;
struct TESRegionList;
struct TESReputation;
struct TESSound;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct blob12
{
    char b[12];
};
struct TESDataHandler
{
    static bool LoadForm(TESForm*, TESFile*);
    bool SaveForm(TESForm*, bool);
    char* GetFormName(unsigned char);
    void OutputFormList();
    void SetModelSizeOutputEnabled(bool);
    void OutputModelSizeList();
    void CheckTexturesRecurse(NiAVObject*, char*);
    static bool CheckDismemberSkinInstanceRecurse(NiAVObject*, char*);
    void PrintTextureInfo(void*, NiTriBasedGeom*, char*, char*, bool);
    void OutputTextureInfo();
    void CheckTexturePath(char*);
    bool AddFormToDataHandler(TESForm*);
    void ReleaseForm(TESForm*);
    unsigned char NotUniqueID(char*);
    void GetObjectCounts();
    void GetReferenceCounts();
    void GetRegions();
    void InitializeMagicSystem();
    void GetReferencesInArea(TESObjectCELL*, void*, float, void*, float, int*, long);
    void GetReferencesInArea(void*, float, void*, float, int*, long);
    void EnumReferencesCloseToRef(TESObjectREFR*, float, void*, float, int*, long);
    static bool ReferenceBaseSearchEnumFunc(TESObjectREFR*, long);
    bool FindTeleportPathBetweenSmallSpaces(TESForm*, TESForm*, void*);
    bool FindTeleportPathBetweenWorlds(TESWorldSpace*, TESWorldSpace*, void*);
    bool FindTeleportPathFromSmallSpaceToWorld(TESForm*, TESWorldSpace*, void*, bool);
    TESObjectREFR* FindFirstReference(TESObject*);
    TESObjectREFR* FindFirstReference(char*);
    bool FindConnectedWorld(TESWorldSpace*, TESWorldSpace*, void*);
    bool FindConnectedSmallSpace(TESForm*, TESForm*, void*, void*);
    TESWorldSpace* BuildPathNodeLocation(TESForm*, NiPoint3*, void*);
    TESObjectREFR* FindClosestReference(TESBoundObject*, void*, TESObjectCELL*);
    TESObjectREFR* FindClosestReference(char*, void*, TESObjectCELL*);
    TESObjectREFR* GetReference(char*);
    TESObjectREFR* GetReference(unsigned int);
    TESLandTexture* GetLandTexture(char*);
    TESLandTexture* GetLandTexture(unsigned int);
    TESRace* GetRace(char*);
    TESRace* GetRace(unsigned int);
    TESClass* GetClass(char*);
    TESClass* GetClass(unsigned int);
    Script* GetScript(char*);
    Script* GetScript(unsigned int);
    TESSound* GetSoundByEditorID(char*);
    TESSound* GetSoundByEditorID(unsigned int);
    TESGlobal* GetGlobal(char*);
    TESGlobal* GetGlobal(unsigned int);
    BGSVoiceType* GetVoiceType(unsigned int);
    TESFaction* GetFactionByFormID(char*);
    TESFaction* GetFactionByFormID(unsigned int);
    TESReputation* GetReputation(char*);
    TESReputation* GetReputation(unsigned int);
    TESRecipe* GetRecipe(char*);
    TESRecipe* GetRecipe(unsigned int);
    TESRecipeCategory* GetRecipeCategory(char*);
    TESRecipeCategory* GetRecipeCategory(unsigned int);
    TESCasino* GetCasino(char*);
    TESCasino* GetCasino(unsigned int);
    TESCaravanDeck* GetCaravanDeck(char*);
    TESCaravanDeck* GetCaravanDeck(unsigned int);
    TESTopic* GetAudioBackendData(int, int);
    TESTopic* GetAudioBackendData(char*);
    TESTopic* GetAudioBackendData(unsigned int);
    TESChallenge* GetChallenge(char*);
    TESAmmoEffect* GetAmmoEffect(char*);
    TESQuest* GetQuest(char*);
    TESCombatStyle* GetCombatStyle(char*);
    TESEffectShader* GetEffectShader(char*);
    BGSProjectile* GetProjectileData(char*);
    BGSExplosion* GetExplosion(char*);
    BGSDebris* GetDebris(char*);
    BGSPerk* GetPerk(char*);
    BGSMessage* GetMessage(char*);
    TESLoadScreenType* GetLoadScreenType(char*);
    TESLoadScreenType* GetLoadScreenType(unsigned int);
    TESFormList* GetObjectList();
    void* GetFileList();
    void* GetPartDataList();
    void* GetPerks();
    void* GetDebrisList();
    void* GetExplosionList();
    void* GetProjectileList();
    void* GetRadiationStageList();
    void* GetDehydrationStageList();
    void* GetHungerStageList();
    void* GetSleepDeprevationStageList();
    void* GetEffectShaderList();
    void* GetWaterList();
    void* GetLoadScreenList();
    void* GetAnimObjectList();
    TESObjectANIO* GetAnimObject(TESIdleForm*, int);
    void* GetCombatStyleList();
    void* GetPackageList();
    void* GetWorldSpaceList();
    void* GetClimateList();
    void* GetImageSpaceList();
    void* GetImageSpaceModifierList();
    void* GetWeatherList();
    void* GetEnchantmentItemList();
    void* GetSpellItemList();
    void* GetLandTextList();
    void* GetCameraShotList();
    void* GetHeadPartList();
    void* GetHairList();
    void* GetEyesList();
    void* GetRaceList();
    void* GetZoneList();
    void* GetClassList();
    void* GetFactionList();
    void* GetReputationList();
    void* GetChallengeList();
    void* GetRecipeList();
    void* GetRecipeCategoryList();
    void* GetAmmoEffectList();
    void* GetCasinoList();
    void* GetCaravanDeckList();
    void* GetSoundList();
    void* GetAcousticSpaceList();
    void* GetRagdollList();
    void* GetGlobalList();
    void* GetVoiceTypeList();
    void* GetImpactDataList();
    void* GetImpactDataSetList();
    void* GetBadFormList();
    TESRegionList* GetRegionList();
    void* GetTopicList();
    void* GetTopicInfoList();
    void* GetNoteList();
    void* GetMenuIconList();
    void* GetListFormList();
    void* GetMessageList();
    void* GetLightingTemplateList();
    void* GetMusicTypeList();
    void* GetLoadScreenTypeList();
    void* GetMediaSetList();
    void* GetMediaLocationControllerList();
    void AddTopic(TESTopic*);
    void RemoveTopic(TESTopic*);
    void AddTopicInfo(TESTopicInfo*);
    void RemoveTopicInfo(TESTopicInfo*);
    void* GetScriptList();
    void SortScriptList();
    void* GetQuestList();
    void AddQuest(TESQuest*);
    void RemoveQuest(TESQuest*);
    unsigned int GetAddonNodeCount();
    BGSAddonNode* GetAddonNodeByIndex(unsigned int);
    void RegisterAddonNode(BGSAddonNode*);
    void RemoveAddonNode(BGSAddonNode*);
    TESObjectCELL* GetCellByNameAndGrid(char*);
    TESObjectCELL* GetCellByNameAndGrid(char*, int, int, TESWorldSpace*);
    unsigned int GetInteriorCellCount();
    TESObjectCELL* GetCellByInteriorIndex(unsigned int);
    void RefreshCellList();
    unsigned int GetCellCount();
    TESObjectCELL* GetCellByIndex(unsigned int);
    TESObjectCELL* GetCellByNumericID(unsigned int);
    TESObjectCELL* LookupCellByEditorID(char*);
    TESWorldSpace* GetWorldSpaceByEditorID(char*, int*, int*);
    TESObjectCELL* GetCellByWorldPosition(float, float, TESWorldSpace*, bool);
    TESObjectCELL* GetCellAtGridPosition(int, int, TESWorldSpace*, bool);
    TESWorldSpace* GetWorldSpaceForCell(TESObjectCELL*);
    void RemoveCell(TESObjectCELL*);
    void RemoveCell(int, int, TESWorldSpace*);
    void RemoveCell(char*);
    TESObjectREFR* CreateReferenceInLoadedArea(TESBoundObject*, void*, void*, bool, BGSPrimitive*, void*);
    TESObjectREFR* PlaceReferenceAtLocation(TESBoundObject*, void*, void*, TESObjectCELL*, TESWorldSpace*,
                                            TESObjectREFR*, BGSPrimitive*, void*);
    TESObjectCELL* SelectCell(struct blob12, bool*, TESWorldSpace*);
    bool AssignToCell(TESObjectCELL*, TESObjectREFR*);
    bool PlaceInExterior(TESObjectREFR*, TESWorldSpace*);
    void RemoveDuplicateReferences();
    TESObjectREFR* CreateProjectileAtLocation(TESBoundObject*, void*, void*, TESObjectCELL*, TESWorldSpace*);
    TESObjectREFR* PlaceObjectAtLocation(TESBoundObject*, void*, void*, TESObjectCELL*, TESWorldSpace*);
    TESFile* LookupTESFile(unsigned int);
    TESFile* LookupTESFile(char*);
    bool RemoveListFile(TESFile*);
    static void FileCacheCompleteCallback(char*);
    char* GetActiveFileName();
    void SetActiveFile(TESFile*);
    TESFile* GetActiveFile();
    void RemoveIDFromDataHandler(unsigned int);
    unsigned int GetNextID();
    void AddCompiledFile(TESFile*);
    void ClearFileList();
    bool UpdateLoadingStatusCallback(char*);
    void BuildCompiledFileList();
    int CountCheckedFiles(int);
    unsigned int CountFiles();
    unsigned int CountCompiled();
    bool LoadPluginFiles(bool);
    bool ClearData();
    bool SaveActiveData(char*, bool);
    void CloseAllTES();
    bool LoadTESFile(TESFile*, bool);
    void ClearLoadedFormCount();
    unsigned int AddDownloadedContentToFileList();
    void RunAllPersistentRefScripts();
    bool ConstructObject(TESFile*, bool, TESForm*, bool);
    bool FormGroupLoadsInGame(TESFile*, FormRecordHeader*);
    static TESForm* CreateFormForType(unsigned char);
    bool ResetOffsetData(TESFile*);
    void FixAllScriptIDs();
    void SetSaveLoadGameState(int);
    bool GetMasterSave();
    void SetMasterSave(bool);
    bool GetSaveLoadGame();
    void SetSaveLoadGame(bool);
    bool GetSaveLoad();
    void SetSaveLoad(bool);
    bool GetAutoSaving();
    void SetAutoSaving(bool);
    bool GetClearingData();
    void SetClearingData(bool);
    bool GetHasDesiredFiles();
    void SetHasDesiredFiles(bool);
    bool IsSavingLoading();
    void SetCheckingModels(bool);
    bool GetCheckingModels();
    void SetLoadingFiles(bool);
    bool GetLoadingFiles();
    bool GetGameSettingsLoaded();
    void MarkGameSettingsLoaded();
    void FlushSoundBuffers();
    void SetBarterContainer(TESObjectREFR*);
    void AddBarterItem(InventoryStackRecord*, int, TESObjectREFR*);
    void ClearBarterContainer();
    InventoryChanges* GetBarterContainer();
    void CreateRecipeContainer(TESObjectREFR*);
    void RemoveItemRecipeContainer(InventoryStackRecord*, int, TESObjectREFR*);
    void ClearRecipeContainer();
    InventoryChanges* GetRecipeContainer();
    TESRegionDataManager* GetRegionDataManager();
    TESFile* GetCompiledFileByIndex(int);
    unsigned int GetNextFormID();
    void SetNextFormID(unsigned int);
    bool FormIDExists(unsigned int);
    AlchemyItem* DoesPotionMatch(AlchemyItem*);
    void SetDontRemoveIDs(bool);
    bool GetDontRemoveIDs();
    void* QArrayInteriorCells();
    TESEffectShader* GetSpotterShader();
    TESEffectShader* GetItemDetectedShader();
    TESEffectShader* GetCateyeShader();
    void SetSpotterShader(TESEffectShader*);
    void SetItemDetectedShader(TESEffectShader*);
    void SetCateyeShader(TESEffectShader*);
    void ClearDLCFlags();
    int GetNumDLCInstalled();
    void DataError(int);
    bool IsFormIDRemapped(unsigned int);
    void AdvanceNextID();
    char* GetDLCFlags();
    bool IsDLCFlagSet(char);
    void SetDLCFlag(char, bool);
    int GetDLCIndex(char*);
    unsigned int LoadFilesInDirectory(char*, void*);
    void* __vecDelDtor(unsigned int);
    char m_cDLCFlagCount;
    char _pad_1[3];
    TESFormList* m_pBoundObjectList;
    char m_kPackages[8];
    char m_kWorldSpaceList[8];
    char m_kClimateList[8];
    char m_kImageSpaceList[8];
    char m_kImageSpaceModifierList[8];
    char m_kWeatherList[8];
    char m_kEnchantmentItemList[8];
    char m_kSpellList[8];
    char m_kHeadPartList[8];
    char m_kHairList[8];
    char m_kEyeList[8];
    char m_kRaceList[8];
    char m_kEncounterZoneList[8];
    char m_kLandTextureList[8];
    char m_kCameraShotList[8];
    char m_kClassList[8];
    char m_pVoiceType[8];
    char m_kReputationList[8];
    char m_kChallengeList[8];
    char m_kCraftingRecipeList[8];
    char m_kRecipeCategoryList[8];
    char m_kAmmoEffectList[8];
    char m_kCasinoList[8];
    char m_kCaravanDeckList[8];
    char m_kScriptList[8];
    char m_kSoundList[8];
    char m_kAcousticSpaceList[8];
    char m_kRagdollList[8];
    char m_kGlobalList[8];
    char m_kVoiceTypeList[8];
    char m_kImpactEffectList[8];
    char m_kImpactDataSetList[8];
    char m_kTopicList[8];
    char m_kTopicInfoList[8];
    char m_kQuestList[8];
    char m_kCombatStyleList[8];
    char m_kLoadScreenList[8];
    char m_kWaterFormList[8];
    char m_kEffectShaderList[8];
    char m_kProjectileList[8];
    char m_kExplosionList[8];
    char m_kRadiationStageList[8];
    char m_kDehydrationStageList[8];
    char m_kHungerStageList[8];
    char m_kSleepDeprivationStageList[8];
    char m_kDebrisList[8];
    char m_kPerkList[8];
    char m_kBodyPartDataList[8];
    char m_kNoteList[8];
    char m_kListFormList[8];
    char m_kMenuIconList[8];
    char m_kFourthDataList[8];
    char m_kMessageList[8];
    char m_kLightingTemplateList[8];
    char m_kMusicTypeList[8];
    char m_kLoadScreenTypeList[8];
    char m_kMediaSetList[8];
    char m_kMediaLocationControllerList[8];
    TESRegionList* m_pRegions;
    char m_kFirstArrayStorage[16];
    char m_kSecondArrayStorage[16];
    char m_kThirdArrayStorage[12];
    unsigned int m_uiFormCount;
    TESFile* m_pActiveFile;
    char m_kModInfoList[8];
    unsigned int m_iLoadedModCount;
    char m_ppLoadedMods[1020];
    bool m_bLoadingFiles;
    bool m_bGameSettingsLoaded;
    bool m_bMasterSave;
    bool m_bSaveLoadGame;
    bool m_bFirstStateField;
    bool m_bSecondStateField;
    bool m_bThirdStateField;
    bool m_bFourthStateFlag;
    bool m_bFifthStateFlag;
    bool m_bSixthStateFlag;
    unsigned char m_ucInternalStateByte;
    char _pad_623[1];
    TESRegionDataManager* m_pRegionDataManager;
    InventoryChanges* m_pFirstInventoryChanges;
    InventoryChanges* m_pSecondInventoryChanges;
    TESEffectShader* m_pFirstEffectShader;
    TESEffectShader* m_pSecondEffectShader;
    TESEffectShader* m_pThirdEffectShader;
};
typedef char _sizecheck_TESDataHandler[sizeof(TESDataHandler) == 1596 ? 1 : -1];
struct FUN_004516b0_shell : public TESDataHandler
{
    bool FUN_004516b0();
};
struct Actor;
struct BGSLoadFormBuffer;
struct BGSReconstructFormsInAllFilesMap;
struct BGSSaveLoadChangesMap;
struct SaveLoadFile;
struct FormIDConverter;
struct SaveLoadChangeHistory;
struct LoadGameSubBufferQueue;
struct BGSSaveLoadReferencesMap;
struct IDebugText;
struct TESForm;
struct TESObjectCELL;
struct TESObjectREFR;
struct blob4
{
    char b[4];
};
struct BGSSaveLoadGame
{
    static void Create();
    static void Destroy();
    void ApplyFormChanges(BGSSaveLoadChangesMap*, FormIDConverter*);
    void LoadCellChanges(bool);
    void LoadForm(TESForm*);
    void SetFormLoaded(TESForm*, bool);
    bool ShouldUnloadForm(TESForm*);
    void FormReconstructionMap(TESObjectCELL*);
    bool ContainsReference(unsigned int);
    bool ShouldSaveForm(TESForm*, bool);
    void NotifyFormIDChanged(TESForm*, struct blob4, bool);
    bool HasFormChangeFlags(TESForm*, struct blob4);
    bool GetOldChange(TESForm*, struct blob4);
    bool IsFormChanged(TESForm*);
    void ClearFormChangeFlags(TESForm*, struct blob4);
    void HasFormChanges(TESForm*);
    void ClearAllForms();
    void CleanupExpiredData();
    void ProcessSubBuffer(int, BGSLoadFormBuffer*, TESForm*);
    void ClearForm(TESForm*);
    void ClearFormID(unsigned int);
    void DeleteForm(TESForm*);
    void ChangeFormID(unsigned int, unsigned int);
    unsigned int GetNewFormID(unsigned int);
    bool IsFormIDRemapped(unsigned int);
    void AreStringsEqual(char*, char*);
    void DisplayReferenceDebugText(TESObjectREFR*, IDebugText*);
    void DisplayCellDebugText(TESObjectREFR*, IDebugText*);
    FormIDConverter* GetFormIDMap();
    FormIDConverter* GetWorldspaceFormIDMap();
    SaveLoadChangeHistory* GetHistory();
    BGSReconstructFormsInAllFilesMap* GetReconstructFormsMap();
    unsigned char GetConvertedFileIndex(unsigned char);
    unsigned char GetReverseConvertedFileIndex(unsigned char);
    unsigned char GetLoadState();
    bool SetGlobalAllowChanges(bool);
    bool GetGlobalAllowChanges();
    void SetDeferInitForms(bool);
    bool GetDeferInitForms();
    void SetSaveGameLoading(bool);
    bool GetSaveGameLoading();
    void SetSaveGameSaving(bool);
    bool GetSaveGameSaving();
    void SetInitingForms(bool);
    bool GetInitingForms();
    void SetPositioningPlayerCharacter(bool);
    bool GetPositioningPlayerCharacter();
    void SetPlayerLocationInvalid(bool);
    bool GetPlayerLocationInvalid();
    void SetSaveLoadFailed(bool);
    bool GetSaveLoadFailed();
    bool SetThreadAllowChanges(bool);
    bool GetThreadAllowChanges();
    void SetLoadingMovedRefs(bool);
    bool GetLoadingMovedRefs();
    void SetReconstructingForms(bool);
    bool GetReconstructingForms();
    bool GetAllowChanges();
    void SaveGame(SaveLoadFile*);
    bool LoadGame(SaveLoadFile*, bool);
    void PrepareLoadGame(SaveLoadFile*);
    bool IsValidSaveGame(SaveLoadFile*);
    unsigned int LoadFormRecord(SaveLoadFile*, BGSLoadFormBuffer*, FormIDConverter*);
    bool FindFormByID(TESForm**, struct blob4, bool);
    void InitializePackageLocations(Actor*);
    void CancelInitPackageLocations(Actor*);
    void ClearFormChanges();
    BGSSaveLoadChangesMap* GetChangesMap();
    void* __vecDelDtor(unsigned int);
    BGSSaveLoadChangesMap* m_pFormChangesMap;
    BGSSaveLoadChangesMap* m_pSecondChangesMap;
    FormIDConverter* m_pSecondSaveLoadData;
    FormIDConverter* m_pSaveLoadData;
    BGSSaveLoadReferencesMap* m_pReferencesMap;
    LoadGameSubBufferQueue* m_pSaveLoadMap;
    void* m_pAuxiliaryData;
    SaveLoadChangeHistory* m_pNoteHandler;
    BGSReconstructFormsInAllFilesMap* m_pFormReconstructionMap;
    char LoadFormBufferArray[16];
    char m_acTextBuffer[16];
    char m_acFirstTextBuffer[255];
    char m_acSecondTextBuffer[255];
    char _pad_242[2];
    unsigned int m_uiInitializationFlags;
    unsigned char m_ucSaveLoadState;
    char _pad_249[3];
};
typedef char _sizecheck_BGSSaveLoadGame[sizeof(BGSSaveLoadGame) == 588 ? 1 : -1];
struct FUN_004523c0_shell : public BGSSaveLoadGame
{
    bool FUN_004523c0();
};
int __fastcall GetByteAtOffset38(void*);
struct FUN_00452420_shell
{
    unsigned int pad0;   // +0x00
    unsigned int pad1;   // +0x04
    unsigned int pad2;   // +0x08
    unsigned int pad3;   // +0x0C
    unsigned int flags;  // +0x10
    bool GetFlag(unsigned int aiFlags) const;
};
struct FUN_00452440_shell
{
    bool __thiscall FUN_00452440();
};
struct FUN_004e32c0_shell
{
    bool __thiscall HasFlags(int arg);
};
struct PlaceableWaterData
{
    unsigned int flags;
};
struct BGSPlaceableWater
{
    PlaceableWaterData* FUN_00624700();
    bool __thiscall HasFlags(unsigned int flags);
};
extern unsigned char DAT_0119b8c8;
unsigned char FUN_00452480();
int __fastcall FUN_009938b0(void*);
struct FUN_00453470_shell
{
    int __thiscall FUN_00453470(void);
};
struct FUN_004534f0_shell
{
    void __thiscall FUN_004534f0(unsigned int);
};
struct FUN_00453500_shell
{
    void FUN_00453500(bool set);
};
struct BSAudio;
BSAudio* DAT_011f6d98;
BSAudio* FUN_00453a70();
extern unsigned char DAT_011f9427;
void FUN_00454440(unsigned char value);
struct FNStub
{
    char const* GetFullName() const;
};
char const* FNStub::GetFullName() const
{
    return 0;
}
struct FUN_00454b50_shell
{
    char const* FUN_00454b50() const;
};
struct TESFaction_RankDataView
{
    unsigned char* GetRankDataList(void);
    bool FUN_00455620(void);
};
extern int DAT_011c56e8;
void FUN_00455680();
struct FUN_004565f0_shell
{
    float m_f;
    float GetFloat();
};
extern const void* const g_01202e00;
struct FUN_00458f20_shell
{
    const void* const* FUN_00458f20() const;
};
extern "C" void __fastcall FUN_00a5e930(void*);
extern int DAT_01017d24;
struct FUN_00458f70_shell
{
    void __thiscall FUN_00458f70();
};
struct AnimIdle;
struct Animation;
struct AttachDistant3DTask;
struct BSFile;
struct BSFileEntry;
struct BackgroundCloneThread;
struct BipedAnim;
struct EffectSetting;
struct KFModel;
struct LoadedFile;
struct MagicItem;
struct Model;
struct NiAVObject;
struct NiControllerSequence;
struct NiNode;
struct QueuedFile;
struct QueuedReference;
struct QueuedTexture;
struct TESAnimGroup;
struct TESBoundObject;
struct TESModel;
struct TESNPC;
struct TESObjectCELL;
struct TESObjectREFR;
struct TESObjectTREE;
struct FileEntryList;
struct FileEntryListCollection;
struct ModelLoadData;
struct ModelLoader
{
    void LoadModelFileList(BSFile*, bool);
    bool QueueModelFilePath(BSFileEntry*, int, QueuedFile*);
    bool QueueModelFilePath(char*, int, QueuedFile*);
    void ProcessModelRequest(char*, FileEntryList*, void*, int, QueuedFile*, int, bool, bool, bool);
    void ProcessModelRequest(char*, void*, int, QueuedFile*, int, bool, bool, bool);
    void ProcessModelRequest(TESModel*, void*, int, QueuedFile*, int, bool, bool, bool, float);
    void ProcessModelRequest(char*, FileEntryList*, int, QueuedFile*, int, bool, bool, bool);
    void ProcessModelRequest(char*, int, QueuedFile*, int, bool, bool, bool);
    void ProcessModelRequest(TESModel*, int, QueuedFile*, int, bool, bool, bool);
    void QueueTree(TESObjectREFR*, TESObjectTREE*, void*, int, QueuedFile*, int);
    void QueueTree(TESObjectREFR*, TESObjectTREE*, int, QueuedFile*, int);
    bool EnqueueFile(char*, int, QueuedFile*);
    void QueueMagicEffectModel(MagicItem*, EffectSetting*, int);
    void QueueReference(TESObjectREFR*, int, bool);
    void QueueBoundObjectModel(TESBoundObject*, void*, int, QueuedFile*, TESObjectREFR*);
    void QueueBoundObjectModel(TESBoundObject*, int, QueuedFile*, TESObjectREFR*);
    void QueueTESModel(TESModel*, int, QueuedFile*, TESObjectREFR*);
    void QueueModelWithOptions(TESModel*, int, QueuedFile*, TESObjectREFR*, bool, bool);
    void QueueModelList(void*, FileEntryListCollection*, int, QueuedFile*, char*);
    void QueueFileList(void*, int, QueuedFile*, char*);
    void QueueReplacementKFList(void*, Animation*, int, QueuedFile*, char*);
    void QueueHead(TESNPC*, void*, int, QueuedFile*);
    void QueueBipedAnimation(BipedAnim*, void*, int, QueuedFile*, int);
    KFModel* FindIdleKFModel(char*, AnimIdle*, int, TESObjectREFR*);
    void QueueTreeBillboard(char*, ModelLoadData*);
    void QueueFileLoad(char*, int, QueuedFile*, int);
    void EnqueueModelFile(char*, int, QueuedFile*, int);
    void QueueModelFile(TESModel*, int, QueuedFile*, int);
    void QueueAlternateModel(TESModel*, int, QueuedFile*, int);
    bool QueueFileFromArchive(BSFileEntry*, int, QueuedFile*);
    void QueueModelLoad(char*, bool, unsigned int);
    void ReleaseKF(char*, bool);
    void CancelReplacementKFList(Animation*);
    void CancelAnimIdle(AnimIdle*);
    void CancelReferenceFiles(TESObjectREFR*);
    void CancelReferencesForCell(TESObjectCELL*);
    bool IsReferenceQueued(TESObjectREFR*);
    TESModel* GetModelForBoundObject(TESBoundObject*, TESObjectREFR*);
    bool BoundObjectOrModelAlreadyQueued(TESObjectREFR*, TESModel*, int, bool);
    void UpdateQueuedReferencePriorities(TESObjectCELL*);
    void PauseBackgroundCloning();
    void ResumeBackgroundCloning();
    void QueueDistant3DTask(AttachDistant3DTask*);
    bool IsBackgroundCloningPaused();
    bool UpdateReferencesToQueue();
    bool SetLoadTexturesDegraded(bool);
    bool GetLoadTexturesDegraded();
    void UpgradeTextures(NiAVObject*);
    bool AddLoadedFileToMap(char*, LoadedFile*);
    void RemoveLoadedFileFromMap(char*);
    LoadedFile* GetLoadedFileFromMap(char*);
    void DebugMessage(char*, ...);
    void DisplayBackgroundLoadDebugText(int, int*, int*, bool);
    void DisplayDebugLoadingText();
    static void UpdateQueueCallback();
    static bool UpdateSecondaryQueueCallback();
    static void LoadQueuedPriorityCallback(float);
    static unsigned int GetExternalCountCallback();
    static void PauseCallback();
    static void ResumeCallback();
    void SetExiting();
    void AddBackgroundCloneReference(QueuedReference*);
    void RemoveReferenceFromMap(TESObjectREFR*);
    void RemoveAnimIdleFromMap(AnimIdle*);
    void RemoveReplacementKFListFromMap(Animation*);
    void RemoveHelmetFromMap(TESObjectREFR*);
    bool RegisterQueuedTexture(BSFileEntry*, QueuedTexture*);
    void RemoveQueuedTextureFromMap(BSFileEntry*);
    QueuedTexture* GetQueuedTextureFromMap(BSFileEntry*);
    bool HasQueuedTextures();
    unsigned int GetBackgroundCloningCount();
    unsigned int GetQueuedReferenceCount();
    unsigned int GetQueuedHelmetCount();
    bool AddModel(char*, Model*);
    bool AddKF(char*, KFModel*);
    NiNode* LoadFile(char*, int, bool, bool, bool, bool);
    KFModel* LoadKF(char*);
    void LoadPSA(char*, void*);
    bool FindModel(char*, void*);
    void* UpdateLoadingStatusCallback(char*, char*, void*);
    void* BuildNIFFileList(char*);
    void* GetModelFileList(char*, bool, bool, int);
    void* FindNIFFileListEntry(void*, void*);
    bool ProcessQueuedFile(TESObjectCELL*);
    KFModel* FindKFModel(char*);
    KFModel* FindKFModel(NiControllerSequence*);
    KFModel* FindKFModel(TESAnimGroup*);
    void CancelAllFiles();
    void SetLoadingEnabled(bool);
    void ReleaseFile(char*);
    void ReleaseKFFile(char*);
    void UpdateReferenceNode(TESObjectREFR*, NiNode*);
    void UpdateModelNode(NiNode*);
    bool QHasDelayedFree();
    static int GetArchiveTypeIndexForIOFileIndex(int);
    static int GetIOFileIndexForArchiveTypeIndex(int);
    void AddModelToMap(Model*, char*);
    void* __vecDelDtor(unsigned int);
    void* m_pLoadedModelMap;
    void* m_pLoadedKFModelMap;
    void* m_pQueuedReferenceMap;
    void* m_pQueuedReferenceUpdateMap;
    void* m_pQueuedAnimIdleMap;
    void* m_pQueuedReplacementKFListMap;
    void* m_pQueuedHelmetMap;
    void* m_pDistant3DTaskQueue;
    void* m_pQueuedTextureMap;
    void* m_pLoadedFileMap;
    BackgroundCloneThread* m_pBackgroundCloneThread;
    bool m_bLoadTexturesDegraded;
    char _pad_2d[3];
};
typedef char _sizecheck_ModelLoader[sizeof(ModelLoader) == 48 ? 1 : -1];
struct FUN_0045a5e0_shell : public ModelLoader
{
    void FUN_0045a5e0(char*);
};
void __cdecl CreateCSDFadeNode(void);
void __cdecl CreateSpdFadeNode(void);
void __cdecl FUN_004f92e0(void);
void __cdecl FUN_00649e40(void);
void __cdecl FUN_0065c570(void);
void __cdecl FUN_00662760(void);
void __cdecl FUN_0045b020(void);
struct FUN_0045c650_shell
{
    void* FUN_0045c650();
};
struct Flt
{
    operator unsigned int(void) const;
};
extern Flt g_011deb7c;
unsigned int FUN_0045c670();
struct TESObjectREFR;
void FUN_00578060(TESObjectREFR* self);
void FUN_00578170(TESObjectREFR* self);
void FUN_0045c680(TESObjectREFR* arg, bool flag);
extern "C" double _gModifierZero;
struct NiPoint3
{
    float x;
    float y;
    float z;
};
struct NiCamera
{
    float x;
    float y;
    float z;
    float w;
    int __thiscall ClassifyPoint(const NiPoint3* other);
};
struct FUN_00451cd0_shell
{
    unsigned char FUN_00451cd0();
};
struct TESObjectCELL
{
    bool IsInterior(void);
};
struct TESObjectCELL_AddToInteriorBuffer
{
    void AddCellToInteriorBuffer(TESObjectCELL* cell);
};
struct TESObjectCELL_AddToExteriorBuffer
{
    void AddCellToExteriorBuffer(TESObjectCELL* cell);
};
struct FUN_00454b90_shell
{
    void AddCellToBuffer(TESObjectCELL* cell);
};
struct FUN_00458f30_shell
{
    void FUN_00458f70();
    void* DestroyIfFlagged(unsigned int flags);
};
void _delete(void* obj, unsigned int size);
struct FUN_00459840_shell
{
    void FUN_00458f90();
    void FUN_00459840(unsigned int a);
};
struct FUN_0045a730_shell
{
    char* FUN_0045a730();
};
extern "C" void __cdecl _Deallocate(void*);
struct FUN_0045ae20_shell
{
    void FUN_0045ae50();
    void* FUN_0045ae20(unsigned int flags);
};
struct FUN_00451250_shell
{
    unsigned char bFlags;
    void SetFlag2(bool value);
};
struct FUN_00401280_shell
{
    void FUN_00401280();
};
struct FUN_00451cb0_shell
{
    void FUN_00451cb0();
};
struct RefH
{
    bool IsDeleted() const;
    bool GetDisabled();
};
struct FNVHelper
{
    FNVHelper* _FNV_GetObjectReference();
    unsigned char _FNV_GetFormType();
};
struct TES
{
    bool IsRefUsable(TESObjectREFR* apRef);
};
extern int DAT_01000000;
struct FUN_00452370_shell
{
    bool FUN_00452370() const;
};
struct GlobalObject_0045cfe0
{
    int* Int();
};
extern GlobalObject_0045cfe0 DAT_011c3c90;
struct FUN_00453980_shell
{
    int GetGlobalInt();
};
struct BSSimpleListTESRaceSize
{
    int GetSize();
};
struct FUN_00454400_shell
{
    int GetRaceListSize();
};
void __cdecl FUN_00455680(void);
struct FUN_004baba0_shell
{
    void FUN_004baba0();
};
struct FUN_00553820_shell
{
    void FUN_00553820();
};
struct CP_008c48d0
{
    void* GetPrevPath();
};
struct FUN_00455640_shell
{
    void* m0;
    void* m4;
    void* m8;
    void FUN_00455640();
};
struct NiNode
{
    NiAVObject* GetAt(unsigned int);
};
struct TESObjectCELLHelper
{
    NiAVObject* GetCellChildAt(int);
};
struct FUN_0045c9a0_shell : public TESObjectCELL
{
    NiAVObject* GetCellNodeAt(unsigned int index);
};
struct FUN_00557090_shell
{
    void FUN_00557090();
};
struct FUN_005570b0_shell
{
    void __thiscall IsSet();
};
struct Unk_C44EA0
{
    void FUN_00c44ed0(float);
    void FUN_00a5e1f0(float*, unsigned int);
    void FUN_00c44ea0(float*, unsigned int);
};
struct FUN_00452390_shell
{
    char _pad[0xaa];
    unsigned short _0xaa;
    void FUN_00452390();
};
struct Holder4523e0
{
    char _pad[0x64];
    FUN_00452420_shell* pLoaded;
    bool FUN_004523e0(unsigned int aiFlag);
};
struct FUN_0045aee0_shell
{
    char pad_0045aee0[0xb5];
    char m_0045aee0_b5;  // at offset 0xb5
    void SetByteB5(char v);
};
struct FUN_00454fc0_cls
{
    void CompactQueuedCells();
};
struct FUN_004ba5a0_cell_helper
{
    bool IsOutdoorCell();
};
struct FUN_00452e50_class
{
    void FUN_00452e50();
};
struct CellStand
{
    int GetCellStandValue();
};
struct DH
{
    void DeleteObject(TESObjectCELL*);
};
extern DH* g_dataHandler;
extern GlobalObject_0045cfe0 g_011c63cc;
struct FUN_00454e70_shell
{
    char _pad[0x3c];
    TESObjectCELL** m_ppCellBufferB;
    void MoveCellToFront(TESObjectCELL* apCell);
};
struct TESObjectLAND;
struct NiNode;
struct NiPoint2
{
    float x;
    float y;
};
struct L_GetHitSound
{
    TESWorldSpace* GetHitSound();
};
struct W_00585b30
{
    TESObjectCELL* FUN_00585b30(int, int);
};
struct W_00588150
{
    void AddCellReferences(TESObjectCELL*);
};
struct FUN_00461c20_Holder
{
    TESObjectCELL* GetOrCreateCell(int, int, TESWorldSpace*, bool);
};
struct S00551440
{
    void FUN_00551440(bool);
};
struct FUN_004ba5a0_shell
{
    bool IsOutdoorCell(unsigned int, unsigned int);
};
struct GridCellArrayStandin
{
    void SetCellAt(unsigned int, unsigned int, TESObjectCELL*);
};
struct GridCellArray_Target
{
    void FUN_004ba960(NiNode*, unsigned int, unsigned int);
};
struct S454b90
{
    void AddCellToBuffer(TESObjectCELL*);
};
struct C_0084e3a0
{
    unsigned int _ref_0084e3a0();
};
struct CellH
{
    int GetCellGridX();
    int GetCellGridY();
};
struct S451cb0
{
    const char* FUN_00451cb0();
};
struct FakeCell
{
    TESObjectLAND* GetLandscape();
};
struct LAND_x
{
    bool FUN_00535b90(bool);
    void FUN_0053a090(int, int);
    void FUN_0053f440(NiPoint2*);
    void FUN_0053fa40(bool);
};
float __fastcall FUN_005471e0(void*);
struct S451250
{
    void SetFlag2(bool);
};
struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
extern GlobalObject_0045cf30 g_011c7adc;
struct MobileObjectCellAccess
{
    bool FUN_004518e0() const;
};
struct S451cd0
{
    unsigned char FUN_00451cd0();
};
void __cdecl FUN_0049c860(TESObjectCELL*);
int _sprintf(char*, const char*, ...);
struct TES_00451a50
{
    unsigned int unk00;
    unsigned int unk04;
    void* m_pGridCells;
    NiNode* m_pLandRootNode;
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
    bool m_bHasCurrentRegion;
    void FUN_00451a50(int aiGridX, int aiGridY, int aiCellX, int aiCellY);
};
struct Setting_S
{
    float* Float();
};
struct Sky
{
    float GetFieldCC();
    void Update(float);
};
struct Animation
{
    float FUN_00453700();
};
struct TaskQueueInterface
{
    static TaskQueueInterface* __cdecl GetInstance();
};
struct FUN_0087aa90_shell
{
    void FUN_0087aa90();
};
struct DialogH
{
    static bool __cdecl IsInDialog();
};
struct Twin_0084d030
{
    float GetStoredFloatValue();
};
struct Zt5Cell
{
    void FUN_00551890(float, bool);
};
struct Zt5Grid
{
    void UpdateCellGrid(float);
};
struct Zt5Listener
{
    void ProcessRequests();
};
Zt5Listener* FUN_00453720();
void __cdecl FUN_00c468c0(float, float);
void __cdecl FUN_00c74550(float, float);
void __fastcall FUN_00975080(char*);
extern float DAT_011c3c08;
extern GlobalObject_0045cfe0 g_011c3ea4;
extern Setting_S g_011c5724;
extern int DAT_011e0e80;
extern Twin_0084d030 g_timeGlobal;
struct Zt5TES
{
    void* pVtbl;
    void* m_pGridDistantArray;
    Zt5Grid* m_pGridCells;
    void* m_pLandRootNode;
    void* m_pWaterRootNode;
    void* m_pDistantLandRootNode;
    void* m_pObjectRootNode;
    void* m_pDirectionalLight;
    void* m_pFogProperty;
    int iFirstValue;
    int iSecondValue;
    int m_iGridWidth;
    int m_iGridHeight;
    void* m_pReferenceCell;
    void* m_ppCellBufferA;
    void* m_ppCellBufferB;
    unsigned int m_uiGridCellCountX;
    unsigned int m_uiGridCellCountY;
    int m_iCurrentGridX;
    int m_iCurrentGridY;
    bool m_bFirstCellGridFlag;
    bool m_bSecondCellGridFlag;
    bool m_bThirdCellGridFlag;
    bool m_bFourthCellGridFlag;
    void* m_pfnCellCallback;
    void* m_pCellCallbackContext;
    void* m_pCurrentRegion;
    bool m_bHasCurrentRegion;
    void* m_pCurrentClimate;
    Sky* pWeatherSky;
    void FUN_00453860(bool);
    void FUN_004537c0();
    void FUN_00453550(float afTime);
};
struct TESForm_0045c6b0
{
    unsigned int FUN_0045c6b0();
};
int FUN_0045c6b0(TESForm_0045c6b0* apObj);
struct FUN_00453490_shell
{
    bool ContainsCell(TESObjectCELL*);
    bool FUN_00454e20(TESObjectCELL*);
    bool FUN_00453490(TESObjectCELL* cell);
};
struct FUN_00455400_sky : Sky
{
    int FUN_00476c90();
    void SetMode(int mode);
};
struct FUN_00455400_cell : TESObjectCELL
{
    bool FUN_00454b10();
};
struct FUN_00455400_tes
{
    FUN_00455400_sky* GetLogDate();
    void UpdateSkyModeForCell(TESObjectCELL* apCell);
};
struct GO
{
    int mObject;
    int mObject2;
    int mObject3;
    GO(int);
    ~GO();
    void operator=(void*);
};
struct FUN_0045ab30_shell : GO
{
    FUN_0045ab30_shell();
};
struct GridCellArray
{
    void* Get(unsigned int, unsigned int);
};
struct NiAdditionalGeometryData
{
    static void* __cdecl GetShadowSceneNodeForIndex(int);
};
struct FUN_00b5ddb0_self
{
    void FUN_00b5ddb0(bool, bool);
};
struct CellExt
{
    bool IsOutdoorCell();
    void FUN_0054ba80(bool);
};
struct FUN_00451cf0_shell
{
    char pad[8];
    GridCellArray* cells;
    void FUN_00451cf0();
};
struct LLD_Cell;
struct LLD_DataHandler
{
    LLD_Cell* GetOrCreateCell(int, int, TESWorldSpace*, bool);
};
struct TESSaveLoadGame
{
    void* GetHitSound();
};
struct FUN_00451900_shell
{
    TESObjectCELL* FUN_00451900(int aiCellX, int aiCellY);
};
void* __cdecl _FUN_00ec7230(void*, void*, unsigned int);
struct FUN_00454fc0_shell
{
    void* vftable;
    void* m_pGridDistantArray;
    unsigned char padding[0x1c];
    int iFirstValue;
    int unknown_28;
    int m_iGridWidth;
    int m_iGridHeight;
    int unknown_34;
    int unknown_38;
    TESObjectCELL** m_ppCellBufferB;

    void CompactQueuedCells();
};
struct A51BF0Base
{
    static void* operator new(unsigned int size)
    {
        return ::operator new(size);
    }
};
struct NiAVObject : A51BF0Base
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

    virtual void SetDebugObject(NiAVObject*, int);

    void UpdateSceneObject();
};
void NiAVObject::SetDebugObject(NiAVObject*, int)
{}
void NiAVObject::UpdateSceneObject()
{}
struct Calendar : NiAVObject
{
    Calendar* GetDaysPassed();
};
Calendar* Calendar::GetDaysPassed()
{
    return this;
}
struct FUN_00458ef0 : NiAVObject
{
    unsigned char padding[172];

    FUN_00458ef0(float);
};
FUN_00458ef0::FUN_00458ef0(float)
{}
typedef FUN_00458ef0 BSTempNode;
struct FUN_00458e20_shell : Calendar
{
    void FUN_00458e20(NiAVObject*, float);
};
void* __cdecl operator new(unsigned int);
struct G2
{
    int** _ref_006815c0();
    void* _ref_00726070();
    void AddHead(int*);
};
struct FUN_00459060_item
{
    unsigned int key;
    short value;
};
struct FUN_00459060_shell
{
    void AddOrAccumulateItem(unsigned int key, short value);
};
struct FUN_0045c780_sound
{
    unsigned int _ref_0084e3a0();
};
struct FUN_0045c780_shell
{
    unsigned char unknown_0045c780[8];
    FUN_0045c780_sound* sound;

    void InitSoundGrid();
    void FUN_0045c8d0(unsigned int index1, unsigned int index2, unsigned char value);
};
extern bool DAT_011c3c0c;
extern const unsigned char DAT_01017830[5][5];
struct FUN_0045c840_shell
{
    void* field_00;
    void* field_04;
    void* field_08;

    void FUN_0045c9e0(unsigned int index1, unsigned int index2, unsigned char value);
    void InitFromMatrix();
};
extern unsigned char DAT_0101784c[];
unsigned int __fastcall _ref_0084e3a0(void* object);
struct TESObjectLAND
{
    bool GetLandHeightAtPosition(const NiPoint3& coord, float& height);
};
struct FUN_004572e0_shell : public TES
{
    TESObjectCELL* FUN_00451900(int cellX, int cellY);
    bool GetLandHeightAt(const NiPoint3& coord, float& height);
};
struct TESCallHelper
{
    bool IsCellBuffered(TESObjectCELL* cell, bool force);
};
int _TruncateFloatToInt(float value);
extern float DAT_01017824;
extern int g_TES;
bool TESCallHelper::IsCellBuffered(TESObjectCELL* cell, bool force)
{
    return false;
}
struct FUN_00451020_cls
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
    int m_24;
    int m_28;
    void FUN_00451020(int* out, float f);
};
int __fastcall GetByteAtOffset38(void*);
struct FUN_004511e0_cls
{
    bool FUN_004511e0(void* pObj, unsigned char bFlag);
};
// Clear an actor's pending state: if it is flagged, has a current process target and is active,
// notify the target's owner, then reset two state flags.
class ProcessTarget;
class TargetOwner
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
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void Unk_30();
    virtual void Unk_31();
    virtual void Unk_32();
    virtual void Unk_33();
    virtual void Unk_34();
    virtual void Unk_35();
    virtual void Unk_36();
    virtual void Unk_37();
    virtual void Unk_38();
    virtual void Unk_39();
    virtual void OnTargetCleared(ProcessTarget* pTarget);
};
class ProcessTarget
{
  public:
    TargetOwner* GetOwner();
};
class ActorLike
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
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void Unk_30();
    virtual void Unk_31();
    virtual void Unk_32();
    virtual void Unk_33();
    virtual void Unk_34();
    virtual void Unk_35();
    virtual void Unk_36();
    virtual void Unk_37();
    virtual void Unk_38();
    virtual void Unk_39();
    virtual void Unk_3A();
    virtual void Unk_3B();
    virtual void Unk_3C();
    virtual void Unk_3D();
    virtual void Unk_3E();
    virtual void Unk_3F();
    virtual void Unk_40();
    virtual void Unk_41();
    virtual void Unk_42();
    virtual void Unk_43();
    virtual void Unk_44();
    virtual void Unk_45();
    virtual void Unk_46();
    virtual void Unk_47();
    virtual void Unk_48();
    virtual void Unk_49();
    virtual void Unk_4A();
    virtual void Unk_4B();
    virtual void Unk_4C();
    virtual void Unk_4D();
    virtual void Unk_4E();
    virtual void Unk_4F();
    virtual void Unk_50();
    virtual void Unk_51();
    virtual void Unk_52();
    virtual void Unk_53();
    virtual void Unk_54();
    virtual void Unk_55();
    virtual void Unk_56();
    virtual void Unk_57();
    virtual void Unk_58();
    virtual void Unk_59();
    virtual void Unk_5A();
    virtual void Unk_5B();
    virtual void Unk_5C();
    virtual void Unk_5D();
    virtual void Unk_5E();
    virtual void Unk_5F();
    virtual void Unk_60();
    virtual void Unk_61();
    virtual void Unk_62();
    virtual void Unk_63();
    virtual void Unk_64();
    virtual void Unk_65();
    virtual void Unk_66();
    virtual void Unk_67();
    virtual void Unk_68();
    virtual void Unk_69();
    virtual void Unk_6A();
    virtual void Unk_6B();
    virtual void Unk_6C();
    virtual void Unk_6D();
    virtual void Unk_6E();
    virtual void Unk_6F();
    virtual void Unk_70();
    virtual void Unk_71();
    virtual void Unk_72();
    virtual void Unk_73();
    virtual ProcessTarget* GetProcessTarget();

    bool IsFlagged();
    bool IsActive();
    void SetPending(int iValue);
    void SetActive(bool bActive);
};
class ActorStateHandler
{
  public:
    void FUN_00451da0(ActorLike* pActor);
};
extern "C" int __fastcall FUN_004503f0(void*);
extern "C" unsigned char __fastcall FUN_00450ff0(void*);
struct TESBuffer45130 : Zt5TES
{
    void FUN_00455130(TESObjectCELL* apCell);
};
struct ExtCell : TESObjectCELL
{
    bool GetCellStandValue();
    TESWorldSpace* GetParentWorldSpace();
};
struct BufferSizeSetting
{
    unsigned int GetUInt();
};
struct ResettableState
{
    void Reset();
};
struct WorldSpaceView
{
    ResettableState* GetMapData();
};
struct TES_ExteriorBuffer
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
    ExtCell** m_ppCellBufferB;

    bool IsCellBuffered(ExtCell* apCell, bool abCheck);
    WorldSpaceView* GetParentWorldSpace();
    unsigned int FUN_00455200(bool abSkipLoaded, TESWorldSpace* apWorld);
};
struct FUN_0043d4d0_cls
{
    unsigned int* FUN_0043d4d0();
};
extern FUN_0043d4d0_cls DAT_011c3e38;
extern DH* DAT_011c3f2c;
struct FUN_00455330_cls
{
    unsigned int unk00;
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
    unsigned int* m_38;

    void RemoveEntry(unsigned int value);
};
struct LookupEntry
{
    unsigned int FUN_00726070();
};
struct LookupResult
{
    LookupEntry* entry;
    LookupResult(int initialState);
    ~LookupResult();
    LookupEntry* FUN_00559450();
};
void __cdecl FindTextureByPath(void* object, LookupResult* result);
void __cdecl FUN_00a61f30(LookupEntry* entry);
struct LookupHandler
{
    bool FUN_00456800(void* object, unsigned int limit);
};
struct FUN_004570d0_node;
struct FUN_004570d0_mgr
{
    FUN_004570d0_node* FUN_005f36f0();
};
struct FUN_004570d0_lst
{
    unsigned int* FUN_0043d4d0();
};
struct FUN_004570d0_node
{
    bool FUN_00553bf0(void* a1, int a2, int a3, float f);
};
extern FUN_004570d0_mgr* DAT_011dea10;
extern FUN_004570d0_lst DAT_011c63cc;
struct FUN_004570d0_cls
{
    FUN_004570d0_node** FUN_00457050(unsigned int i, unsigned int j);
    bool FUN_004570d0(void* a1, int a2, int a3, float f);
};
struct FUN_00458f90_shell
{
    void FUN_00458f90();
};
struct G2List : G2
{
    void FUN_00470470();
};
struct SaveFormRecord
{
    unsigned int formId;
    unsigned char formType;
    unsigned char flags[4];
};
struct SaveState
{
    bool FUN_00862110();
    unsigned char FUN_008df040();
    SaveFormRecord* FUN_004fd3e0();
};
extern SaveState* DAT_011de45c;
struct SaveLogSetting
{
    bool* FUN_00408d60();
};
extern SaveLogSetting DAT_011de4e8;
struct SaveForm
{
    virtual void Reserved0();
    virtual void Reserved1();
    virtual void Reserved2();
    virtual void Reserved3();
    virtual void Reserved4();
    virtual void Reserved5();
    virtual void Reserved6();
    virtual void Reserved7();
    virtual void Reserved8();
    virtual void Reserved9();
    virtual void Reserved10();
    virtual void Reserved11();
    virtual void Reserved12();
    virtual void Reserved13();
    virtual void Reserved14();
    virtual void Reserved15();
    virtual void Reserved16();
    virtual void Reserved17();
    virtual void Reserved18();
    virtual void Reserved19();
    virtual void Reserved20();
    virtual void Reserved21();
    virtual void Reserved22();
    virtual void Reserved23();
    virtual void Reserved24();
    virtual void Reserved25();
    virtual void Reserved26();
    virtual void Reserved27();
    virtual void Reserved28();
    virtual void Reserved29();
    virtual void Reserved30();
    virtual void Reserved31();
    virtual void Reserved32();
    virtual void Reserved33();
    virtual void Reserved34();
    virtual void Reserved35();
    virtual void Reserved36();
    virtual void Reserved37();
    virtual void Reserved38();
    virtual void Reserved39();
    virtual void Reserved40();
    virtual void Reserved41();
    virtual void Reserved42();
    virtual void Reserved43();
    virtual void Reserved44();
    virtual void Reserved45();
    virtual void Reserved46();
    virtual void Reserved47();
    virtual void Reserved48();
    virtual void Reserved49();
    virtual void Reserved50();
    virtual void Reserved51();
    virtual void Reserved52();
    virtual void Reserved53();
    virtual void Reserved54();
    virtual void Reserved55();
    virtual void Reserved56();
    virtual void Reserved57();
    virtual void Reserved58();
    virtual void Reserved59();
    virtual void Reserved60();
    virtual void Reserved61();
    virtual void Reserved62();
    virtual void Reserved63();
    virtual void Reserved64();
    virtual void Reserved65();
    virtual void Reserved66();
    virtual void Reserved67();
    virtual void Reserved68();
    virtual void Reserved69();
    virtual void Reserved70();
    virtual void Reserved71();
    virtual void Reserved72();
    virtual void Reserved73();
    virtual void Reserved74();
    virtual void Reserved75();
    virtual const char* GetDebugName();
};
SaveForm* LookupSaveForm(unsigned int);
void FUN_0040fbe0(const char*, ...);
extern const char DAT_01017874[];
extern const char DAT_01012cb0[];
extern const char DAT_01012c78[];
struct SaveItemList
{
    unsigned int FUN_005ae380();
};
struct SaveSizeOwner
{
    SaveItemList* FUN_0050d100();
    unsigned short FUN_00459100();
};
struct FUN_00459920_reference
{
    bool FUN_00450ff0();
    void FUN_005571a0(int changeFlag);
};
struct FUN_00459920_grid
{
    FUN_00459920_reference** FUN_004ba490(unsigned int column, unsigned int row);
};
struct FUN_00459920_shell
{
    void* unk00;
    void* unk04;
    FUN_00459920_grid* referenceGrid;
    FUN_00459920_reference* FUN_005f36f0();
    void FUN_00459920();
};
struct AutoMemContext
{
    int iPrevContext;
    AutoMemContext(int aeContext, bool abPush, const char* apFile, int aiLine);
    ~AutoMemContext();
};
unsigned int __fastcall FUN_0070ec90(char* apName);
extern GlobalObject_0045cf30 g_011c7b98;
struct NiSourceTexture;
template <class T> struct NiPointer
{
    T* m_pObject;
    NiPointer(T* apObject);
    ~NiPointer();
    operator T*() const;
};
struct TESWaterForm
{
    unsigned int HasTexture();
    const char* GetTexturePath() const;
    void SetTexture(NiSourceTexture* apTexture);
};
struct WaterFormNode
{
    bool IsEmpty();
    TESWaterForm** GetItem();
    WaterFormNode* GetNext();
};
struct WaterDataHandler
{
    WaterFormNode* GetTESWaterFormList();
};
struct WaterTES
{
    void CreateTextureImage(const char* apPath, NiPointer<NiSourceTexture>& arTexture, bool abA, bool abB);
};
struct WaterTextureLoader
{
    void LoadWaterTextures();
};
struct NiObject
{
    NiObject* Clone();
};
struct ModelPtr
{
    NiObject* m_pObject;
    ModelPtr();
    ~ModelPtr();
    ModelPtr& operator=(NiObject* pObject);
    bool operator==(NiObject* pObject) const;
};
struct ModelCloneNode
{
    ModelPtr m_pRenderedNodeEntry;
    ModelPtr* pClones;
    ModelCloneNode* pNext;
    ModelCloneNode();
    ModelCloneNode* GetNext();
    void SetNext(ModelCloneNode* pNode);
};
struct ModelCloneOwner
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
    ModelCloneNode* pCloneList;
    void AddCloneEntry(NiObject* m_kModelObjectsItem);
};
struct ListNodeB;
struct SlotB;
struct ObjC;
struct ObjD;
struct ListNodeB
{
    bool Matches(void* key);
    ListNodeB* NextNode();
    unsigned int unk00;
    SlotB* m_slots;
};
struct SlotB
{
    unsigned int unk00;
    ObjD* Resolve();
};
struct ObjD
{
    int Check();
};
struct ObjC
{
    void Release(SlotB* slot);
    void Attach(SlotB* slot);
};
struct FUN_0045aba0_cls
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
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    ListNodeB* m_b0;
    int FindMatchingNode(void* a1, ObjC* a2);
};
struct NavMeshHolder
{
    virtual void unkV0();
    virtual void unkV1();
    virtual void unkV2();
    virtual void unkV3();
    virtual void* unkV4(unsigned int flags);
};
extern "C" void __cdecl FUN_005b5e40(const char*);
struct FUN_0045afb0_cls
{
    unsigned int unk00;
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
    NavMeshHolder* m_pNavMeshMaps;

    void SetNavMeshMaps(NavMeshHolder* arg);
};
struct S_0045c8d0_Obj;
struct S_0045c8d0_Tgt
{
    void FUN_00441130(unsigned int a, unsigned char b);
};
struct S_0045c8d0_Obj
{
    S_0045c8d0_Tgt* FUN_00a59d30(int a);
};
struct S_0045c8d0_Virt
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual S_0045c8d0_Obj* v6();
};
struct S_0045c8d0_Child
{
    int FUN_0045bc00(int a);
    S_0045c8d0_Virt* FUN_0043b4a0(int a);
};
struct S_0045c8d0_Cell
{
    S_0045c8d0_Child* GetCellNodeAt(int a);
};
struct S_0045c8d0_R
{
    S_0045c8d0_Cell* unk0;
};
struct S_0045c8d0_A
{
    S_0045c8d0_R* FUN_004ba490(unsigned int a, unsigned int b);
};
int FUN_00438220();
struct S_0045c8d0
{
    int unk0;
    int unk4;
    S_0045c8d0_A* unk8;
    void FUN_0045c8d0(unsigned int a, unsigned int b, unsigned char c);
};
struct FUN_0045cb90_inner
{
    unsigned int m_00;
    unsigned int m_04;
};
struct FUN_0045cb90_cls
{
    char unk00[0x28];
    FUN_0045cb90_inner* m_28;

    bool FUN_0045cb90();
};
class B45CDA0Cell
{
  public:
    void FUN_00558c90();
};
struct B45CDA0GridCell
{
    B45CDA0Cell* m_pkCell;
};
class B45CDA0GridCellArray
{
  public:
    B45CDA0GridCell* Get(unsigned int uiX, unsigned int uiY);
};
class B45CDA0TES
{
  public:
    int unk00;
    int unk04;
    B45CDA0GridCellArray* m_pkGridCells;
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
    B45CDA0Cell* m_pkInteriorCell;

    void FUN_0045cda0();
};
struct Grid4512
{
    virtual void v0();
    virtual void v1();
    virtual void Reset();
    virtual void v3();
    virtual void SetGridPosition(int x, int y);
};
struct Terrain4512
{
    void FUN_006fce00();
    void FUN_006fca90(void* position);
};
struct World4512
{
    Terrain4512* FUN_00586170();
};
struct Player4512
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
    virtual void* GetPosition(int which);
};
extern Player4512* g_thePlayer;
struct FUN_00c3dfa0_Class
{
    void FUN_00c3dfa0(int);
};
extern FUN_00c3dfa0_Class* DAT_01202d98;
struct NiPoint3Ex : NiPoint3
{
    NiPoint3Ex(float, float, float);
};
extern NiPoint3Ex DAT_011a9478;
void FUN_0057d0a0(NiPoint3Ex position, NiPoint3Ex direction, float scale);
struct Setting4512
{
    float* FUN_00403e20();
};
extern Setting4512 originalRuntimeFloatSetting16;
struct Interface
{
    void FUN_00700960(int, float, bool);
};
extern Interface* DAT_011d8804;
struct Process4512
{
    void FUN_00972d30();
    void FUN_00972bb0();
};
struct NiUpdateData
{
    float time;
    bool updateControllers;
    bool isMultiThreaded;
    bool flag6;
    bool flag7;
    bool flag8;
    NiUpdateData(float, bool, bool);
};
struct Node4512
{
    void FUN_00a59c60(NiUpdateData&);
};
struct Data4512
{
    void ProcessAllFiles();
};
extern bool DAT_011c3ed0;
struct TES4512
{
    int unk00;
    int unk04;
    Grid4512* grid;
    int unk0c;
    Node4512* root;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int gridX;
    int gridY;
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
    World4512* world;
    TESObjectCELL* FUN_005f36f0();
    void FUN_00455200(bool, TESWorldSpace*);
    void FUN_00452490(bool);
    void FUN_00457be0(bool);
    void RefreshGrid();
    bool GetLandHeightAt(const NiPoint3&, float&);
    bool FUN_00451530();
    void ProcessItemNodes();
    void FUN_00455490();
    void FUN_004512c0(const NiPoint3* position, bool reload);
};
struct FUN_004516d0_shell
{
    unsigned int unk00;
    unsigned int unk04;
    GridCellArray* cells;
    MobileObjectCellAccess** FUN_004516d0();
};
class TESBoundObject
{
  public:
    virtual void Reserved();
    unsigned int FUN_00401170();
    bool FUN_00452440();
    void FUN_004534f0(void*);
};
extern const double DAT_010179e0;
struct TreeDimensions
{
    float x;
    float y;
};
class TESObjectTREE : public TESBoundObject
{
  public:
    TreeDimensions* FUN_0045bb80();
    virtual void Reserved1();
    virtual void Reserved2();
    virtual void Reserved3();
    virtual void Reserved4();
    virtual void Reserved5();
    virtual void Reserved6();
    virtual void Reserved7();
    virtual void Reserved8();
    virtual void Reserved9();
    virtual void Reserved10();
    virtual void Reserved11();
    virtual void Reserved12();
    virtual void Reserved13();
    virtual void Reserved14();
    virtual void Reserved15();
    virtual void FinalizeAttach();
    virtual void Reserved17();
    virtual void Reserved18();
    virtual void Reserved19();
    virtual void Reserved20();
    virtual void Reserved21();
    virtual void Reserved22();
    virtual void Reserved23();
    virtual void Reserved24();
    virtual void Reserved25();
    virtual void Reserved26();
    virtual void Reserved27();
    virtual void Reserved28();
    virtual void Reserved29();
    virtual void Reserved30();
    virtual void Reserved31();
    virtual void Reserved32();
    virtual void Reserved33();
    virtual void Reserved34();
    virtual void Reserved35();
    virtual void Reserved36();
    virtual void Reserved37();
    virtual void Reserved38();
    virtual void Reserved39();
    virtual void Reserved40();
    virtual void Reserved41();
    virtual void Reserved42();
    virtual void Reserved43();
    virtual void Reserved44();
    virtual void Reserved45();
    virtual void Reserved46();
    virtual void Reserved47();
    virtual void Reserved48();
    virtual void Reserved49();
    virtual void Reserved50();
    virtual void Reserved51();
    virtual void Reserved52();
    virtual void Reserved53();
    virtual void Reserved54();
    virtual void Reserved55();
    virtual void Reserved56();
    virtual void Reserved57();
    virtual void Reserved58();
    virtual void Reserved59();
    virtual void Reserved60();
    virtual void Reserved61();
    virtual void Reserved62();
    virtual void Reserved63();
    virtual void Reserved64();
    virtual void Reserved65();
    virtual void Reserved66();
    virtual void Reserved67();
    virtual void Reserved68();
    virtual void Reserved69();
    virtual void Reserved70();
    virtual void Reserved71();
    virtual void Reserved72();
    virtual void Reserved73();
    virtual void Reserved74();
    virtual void Reserved75();
    virtual void Reserved76();
    virtual void Reserved77();
    virtual void Reserved78();
    virtual void Reserved79();
    virtual void Reserved80();
    virtual void Reserved81();
    virtual void Reserved82();
    virtual void Reserved83();
    virtual void Reserved84();
    virtual void Reserved85();
    virtual void Reserved86();
    virtual void Reserved87();
    virtual void Reserved88();
    virtual void Reserved89();
    virtual void Reserved90();
    virtual void Reserved91();
    virtual void Reserved92();
    virtual void Reserved93();
    virtual void Reserved94();
    virtual void Reserved95();
    virtual void Reserved96();
    virtual void Reserved97();
    virtual void Reserved98();
    virtual void Reserved99();
    virtual void Reserved100();
    virtual void Reserved101();
    virtual void Reserved102();
    virtual void Reserved103();
    virtual void Reserved104();
    virtual void Reserved105();
    virtual void Reserved106();
    virtual void Reserved107();
    virtual void Reserved108();
    virtual void Reserved109();
    virtual void Reserved110();
    virtual double GetTreeScale(float);
};
struct AttachNode;
struct AttachRoot
{
    void FUN_00b5eeb0(AttachNode*);
    void FUN_00b5cbd0(AttachNode*);
    void FUN_00b5d9f0(AttachNode*, int);
};
AttachRoot* __cdecl FUN_00450b80(int);
struct AttachNode
{
    struct NodeOwner* FUN_009611e0();
};
struct NodeOwner
{
    virtual void Reserved0();
    virtual void Reserved1();
    virtual void Reserved2();
    virtual void Reserved3();
    virtual void Reserved4();
    virtual void Reserved5();
    virtual void Reserved6();
    virtual void Reserved7();
    virtual void Reserved8();
    virtual void Reserved9();
    virtual void Reserved10();
    virtual void Reserved11();
    virtual void Reserved12();
    virtual void Reserved13();
    virtual void Reserved14();
    virtual void Reserved15();
    virtual void FinalizeAttach();
    virtual void Reserved17();
    virtual void Reserved18();
    virtual void Reserved19();
    virtual void Reserved20();
    virtual void Reserved21();
    virtual void Reserved22();
    virtual void Reserved23();
    virtual void Reserved24();
    virtual void Reserved25();
    virtual void Reserved26();
    virtual void Reserved27();
    virtual void Reserved28();
    virtual void Reserved29();
    virtual void Reserved30();
    virtual void Reserved31();
    virtual void Reserved32();
    virtual void Reserved33();
    virtual void Reserved34();
    virtual void Reserved35();
    virtual void Reserved36();
    virtual void Reserved37();
    virtual void Reserved38();
    virtual void Reserved39();
    virtual void Reserved40();
    virtual void Reserved41();
    virtual void Reserved42();
    virtual void Reserved43();
    virtual void Reserved44();
    virtual void Reserved45();
    virtual void Reserved46();
    virtual void Reserved47();
    virtual void Reserved48();
    virtual void Reserved49();
    virtual void Reserved50();
    virtual void Reserved51();
    virtual void Reserved52();
    virtual void Reserved53();
    virtual void Reserved54();
    virtual void Reserved55();
    virtual void Reserved56();
    virtual void Reserved57();
    virtual void Release(AttachNode*);
};
struct AttachRef
{
    virtual void Reserved0();
    virtual void Reserved1();
    virtual void Reserved2();
    virtual void Reserved3();
    virtual void Reserved4();
    virtual void Reserved5();
    virtual void Reserved6();
    virtual void Reserved7();
    virtual void Reserved8();
    virtual void Reserved9();
    virtual void Reserved10();
    virtual void Reserved11();
    virtual void Reserved12();
    virtual void Reserved13();
    virtual void Reserved14();
    virtual void Reserved15();
    virtual void FinalizeAttach();
    virtual void Reserved17();
    virtual void Reserved18();
    virtual void Reserved19();
    virtual void Reserved20();
    virtual void Reserved21();
    virtual void Reserved22();
    virtual void Reserved23();
    virtual void Reserved24();
    virtual void Reserved25();
    virtual void Reserved26();
    virtual void Reserved27();
    virtual void Reserved28();
    virtual void Reserved29();
    virtual void Reserved30();
    virtual void Reserved31();
    virtual void Reserved32();
    virtual void Reserved33();
    virtual void Reserved34();
    virtual void Reserved35();
    virtual void Reserved36();
    virtual void Reserved37();
    virtual void Reserved38();
    virtual void Reserved39();
    virtual void Reserved40();
    virtual void Reserved41();
    virtual void Reserved42();
    virtual void Reserved43();
    virtual void Reserved44();
    virtual void Reserved45();
    virtual void Reserved46();
    virtual void Reserved47();
    virtual void Reserved48();
    virtual void Reserved49();
    virtual void Reserved50();
    virtual void Reserved51();
    virtual void Reserved52();
    virtual void Reserved53();
    virtual void Reserved54();
    virtual void Reserved55();
    virtual void Reserved56();
    virtual void Reserved57();
    virtual void Reserved58();
    virtual void Reserved59();
    virtual void Reserved60();
    virtual void Reserved61();
    virtual void Reserved62();
    virtual void Reserved63();
    virtual bool IsActor();
    virtual void Reserved65();
    virtual void Reserved66();
    virtual void Reserved67();
    virtual void Reserved68();
    virtual void Reserved69();
    virtual void Reserved70();
    virtual void Reserved71();
    virtual void Reserved72();
    virtual void Reserved73();
    virtual void Reserved74();
    virtual void Reserved75();
    virtual void Reserved76();
    virtual void Reserved77();
    virtual void Reserved78();
    virtual void Reserved79();
    virtual void Reserved80();
    virtual void Reserved81();
    virtual void Reserved82();
    virtual void Reserved83();
    virtual void Reserved84();
    virtual void Reserved85();
    virtual void Reserved86();
    virtual void Reserved87();
    virtual void Reserved88();
    virtual void Reserved89();
    virtual void Reserved90();
    virtual void Reserved91();
    virtual void Reserved92();
    virtual void Reserved93();
    virtual void Reserved94();
    virtual void Reserved95();
    virtual void Reserved96();
    virtual void Reserved97();
    virtual void Reserved98();
    virtual void Reserved99();
    virtual void Reserved100();
    virtual void Reserved101();
    virtual void Reserved102();
    virtual void Reserved103();
    virtual void Reserved104();
    virtual void Reserved105();
    virtual void Reserved106();
    virtual void Reserved107();
    virtual void Reserved108();
    virtual void Reserved109();
    virtual void Reserved110();
    virtual void Reserved111();
    virtual void Reserved112();
    virtual void Reserved113();
    virtual AttachNode* GetNode(int);
    virtual void Reserved115();
    virtual void Reserved116();
    virtual void Reserved117();
    virtual void Reserved118();
    virtual void Reserved119();
    virtual void Reserved120();
    virtual void Reserved121();
    virtual void Reserved122();
    virtual void Reserved123();
    virtual void Reserved124();
    virtual NiPoint3* GetPoint(unsigned int);
    virtual void Reserved126();
    virtual void Reserved127();
    virtual void Reserved128();
    virtual void Reserved129();
    virtual void Reserved130();
    virtual void Reserved131();
    virtual void Reserved132();
    virtual void Reserved133();
    virtual void Reserved134();
    virtual void Reserved135();
    virtual bool IsSpecialA();
    virtual bool IsSpecialB();
    virtual void Reserved138();
    virtual void Reserved139();
    virtual void Reserved140();
    virtual void Reserved141();
    virtual void Reserved142();
    virtual void Reserved143();
    virtual void Reserved144();
    virtual void Reserved145();
    virtual void Reserved146();
    virtual void Reserved147();
    virtual void Reserved148();
    virtual void Reserved149();
    virtual void Reserved150();
    virtual void Reserved151();
    virtual void Reserved152();
    virtual void Reserved153();
    virtual void Reserved154();
    virtual void Reserved155();
    virtual void Reserved156();
    virtual void Reserved157();
    virtual void Reserved158();
    virtual void Reserved159();
    virtual void Reserved160();
    virtual void Reserved161();
    virtual void Reserved162();
    virtual void Reserved163();
    virtual void Reserved164();
    virtual void Reserved165();
    virtual void Reserved166();
    virtual void Reserved167();
    virtual void Reserved168();
    virtual void Reserved169();
    virtual void Reserved170();
    virtual void Reserved171();
    virtual void Reserved172();
    virtual void Reserved173();
    virtual void Reserved174();
    virtual void Reserved175();
    virtual void Reserved176();
    virtual void Reserved177();
    virtual void Reserved178();
    virtual void Reserved179();
    virtual void Reserved180();
    virtual void Reserved181();
    virtual void Reserved182();
    virtual void Reserved183();
    virtual void Reserved184();
    virtual void Reserved185();
    virtual void Reserved186();
    virtual void Reserved187();
    virtual void Reserved188();
    virtual void Reserved189();
    virtual void Reserved190();
    virtual void Reserved191();
    virtual void Reserved192();
    virtual void HandleA();
    virtual void HandleB();
    AttachNode* FUN_005d8710();
    TESBoundObject* FUN_007af430();
    void* FUN_0043fcd0();
    void FUN_00570f70(AttachNode*);
    bool FUN_00564e60();
    void FUN_0056f700();
    bool FUN_00452370();
    bool FUN_0057b200();
    bool FUN_004523e0(int);
    void FUN_00483710();
    void* FUN_00430830();
    void FUN_00565730();
    void* FUN_005d43c0();
    double FUN_00567400();
    void FUN_008c4640();
    unsigned int FUN_0084e3a0();
};
struct AttachCell
{
    void GetOrCreateWidget();
    void FUN_00452390();
    void FUN_00548880(AttachRef*, int);
    bool FUN_00450ff0();
    bool FUN_004523c0();
    void FUN_00547ad0(NiPoint3);
};
struct AttachContext
{
    bool FUN_0042ce10();
};
extern AttachContext* DAT_011ddf38;
extern AttachRef* DAT_011dea3c;
void __cdecl FUN_005ac190(AttachRef*, void*);
void __cdecl FUN_005ac750(AttachRef*, void*, unsigned int);
void __cdecl FUN_004b6dc0(void*, unsigned int);
struct AttachmentHandler
{
    void FUN_00451da0(AttachRef*);
    bool IsRefUsable(AttachRef*);
    void FUN_00451ea0(AttachRef*);
    void FUN_00451ef0(AttachRef*, AttachCell*, AttachRef*, bool);
};
namespace GridRefresh {
struct Profile
{
    int unk00;
    Profile(int, int, const char*, int);
    ~Profile();
};
extern const char DAT_01017874[];
struct Setting
{
    const unsigned int* FUN_0043d4d0();
};
extern Setting DAT_011c63cc;
struct Update
{
    float time;
    int flags, unk08;
    Update(float, int, int);
};
struct Node
{
    void FUN_00a5a040();
    int FUN_00453470();
    void FUN_00a59c60(const Update&);
};
struct Cell
{
    int GetByteAtOffset38();
    void FUN_0054bcf0(bool);
    Node* GetOrCreateWidget();
};
struct Game
{
    void FUN_004534f0(bool);
    bool FUN_0047c850();
    void FUN_00861ea0();
    bool FUN_008727b0();
    void FUN_00858af0(int, int, int);
    void FUN_0085f850(int);
};
extern Game* DAT_011de45c;
struct Loader
{
    void FUN_00453500(bool);
    bool FUN_0042ce10();
    void ResetLoadBuffers(int);
};
extern Loader* DAT_011ddf38;
struct Main
{
    bool FUN_00453490(Cell*);
};
extern Main* DAT_011dea10;
struct World
{
};
struct Cells
{
    Cell* GetOrCreateCell(int, int, World*, int);
};
extern Cells* DAT_011c3f2c;
struct Queue
{
    void FUN_00c66300();
    void FUN_00c6b540(int);
};
Queue* FUN_00451010();
struct CellHandle
{
    void FUN_005ae3d0();
};
struct Grid
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
    int centerX, centerY;
    void FUN_00451a50(unsigned int, unsigned int, int, int);
    World* FUN_004fd3e0();
    void AddCellToBuffer(Cell*);
    CellHandle* FUN_0045bb80(Cell**);
    void RefreshGrid();
};
bool FUN_00705e80();
void FUN_00451570(void*);
void FUN_00451520(unsigned char);
extern const double DAT_01017a40;
// @fnv 0x00452ff0
void Grid::RefreshGrid()
{
    Profile profile3(26, 1, DAT_01017874, 2262);
    int originX = centerX - (*DAT_011c63cc.FUN_0043d4d0() >> 1);
    int originY = centerY - (*DAT_011c63cc.FUN_0043d4d0() >> 1);
    int count = 0;
    bool defer = false;
    if (FUN_00705e80())
        defer = true;
    bool loading4 = FUN_00705e80();
    DAT_011de45c->FUN_004534f0(true);
    DAT_011ddf38->FUN_00453500(true);
    if (FUN_00451010())
        FUN_00451010()->FUN_00c66300();
    for (unsigned int x = 0; x < *DAT_011c63cc.FUN_0043d4d0(); ++x)
    {
        for (unsigned int y = 0; y < *DAT_011c63cc.FUN_0043d4d0(); ++y)
        {
            FUN_00451a50(x, y, originX + x, originY + y);
            Cell* cell = DAT_011c3f2c->GetOrCreateCell(originX + x, originY + y, FUN_004fd3e0(), 0);
            if (DAT_011dea10->FUN_00453490(cell))
                AddCellToBuffer(cell);
            if (loading4 || (DAT_011de45c->FUN_0047c850() && DAT_011de45c->FUN_0047c850()))
            {
                ++count;
                float percent =
                    (double)count / (*DAT_011c63cc.FUN_0043d4d0() * *DAT_011c63cc.FUN_0043d4d0()) * DAT_01017a40;
                if (DAT_011de45c->FUN_0047c850() && DAT_011de45c->FUN_0047c850())
                    DAT_011de45c->FUN_00861ea0();
            }
        }
    }
    if (FUN_00451010())
        FUN_00451010()->FUN_00c6b540(0);
    DAT_011de45c->FUN_004534f0(false);
    if (DAT_011de45c->FUN_008727b0())
    {
        bool first = DAT_011de45c->FUN_0047c850();
        bool second6 = DAT_011de45c->FUN_0047c850();
        DAT_011de45c->FUN_004534f0(true);
        DAT_011de45c->FUN_004534f0(true);
        DAT_011de45c->FUN_00858af0(0, 0, 0);
        DAT_011de45c->FUN_0085f850(0);
        DAT_011de45c->FUN_004534f0(second6);
        DAT_011de45c->FUN_004534f0(first);
    }
    DAT_011ddf38->FUN_00453500(false);
    if (!DAT_011ddf38->FUN_0042ce10())
        DAT_011ddf38->ResetLoadBuffers(0);
    if (FUN_00451010())
        FUN_00451010()->FUN_00c66300();
    for (unsigned int x2 = 0; x2 < *DAT_011c63cc.FUN_0043d4d0(); ++x2)
    {
        for (unsigned int y2 = 0; y2 < *DAT_011c63cc.FUN_0043d4d0(); ++y2)
        {
            if (FUN_004fd3e0())
            {
                Cell* cell2 = DAT_011c3f2c->GetOrCreateCell(originX + x2, originY + y2, FUN_004fd3e0(), 0);
                if (cell2)
                {
                    if (cell2->GetByteAtOffset38() == 5)
                    {
                        cell2->FUN_0054bcf0(!defer);
                        AddCellToBuffer(cell2);
                        Node* node = cell2->GetOrCreateWidget();
                        node->FUN_00a5a040();
                        if (!node->FUN_00453470())
                        {
                            Update update(0.0f, 0, 0);
                            node->FUN_00a59c60(update);
                        }
                    }
                    FUN_0045bb80(&cell2)->FUN_005ae3d0();
                }
            }
        }
    }
    if (FUN_00451010())
        FUN_00451010()->FUN_00c6b540(0);
    FUN_00451570(0);
    FUN_00451520(1);
}
}

struct S_004537c0_Sky : Sky
{
    void FUN_0063ac70(float f);
};
struct S_004537c0_Mgr
{
    void FUN_00a59c60(void* p);
};
struct S_004537c0_Tes : Zt5TES
{
    S_004537c0_Mgr* FUN_009611e0();
};
struct S_004537c0_Fade
{
    float unk00;
    unsigned char unk04;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0A;
    unsigned char unk0B;
    void FUN_0043d410(float f, unsigned char a, unsigned char b);
};
bool FUN_007050d0();
float FUN_00453850();
struct FUN_004539a0_cls
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
    unsigned char unkB4;
    FUN_004539a0_cls* FUN_0045bb80();
    TESObjectCELL* FUN_005f36f0();
    void FUN_00453940();
    void FUN_00455200(unsigned char a, int b);
    bool ContainsCell(TESObjectCELL* cell);
    void FUN_00454d50(unsigned char a);
    void FUN_008d7dc0(int b);
    void FUN_004539a0(unsigned char a1, unsigned char a2);
};
struct FUN_004539a0_helperA
{
    void FUN_00470470();
};
struct FUN_004539a0_helperB
{
    void FUN_00483710();
};
struct BufferedCell : TESObjectCELL
{
    bool FUN_00557090();
};
struct BufferMap
{
    void FUN_006fce00();
};
struct BufferWorld
{
    BufferMap* FUN_00586170();
};
struct CellBufferManager
{
    void* vtable;
    void* distantGrid;
    C_0084e3a0* grid;
    void* objectRoot;
    void* landRoot;
    void* waterRoot;
    void* tempNodeManager;
    void* light;
    void* fog;
    int currentGridX;
    int currentGridY;
    int queuedGridX;
    int queuedGridY;
    BufferedCell* interiorCell;
    BufferedCell** interiorBuffer;
    BufferedCell** exteriorBuffer;

    BufferedCell* FUN_005f36f0();
    void CompactQueuedCells();
    bool FUN_004511e0(BufferedCell*, bool);
    void FUN_00453940();
    BufferWorld* FUN_004fd3e0();
    bool FUN_00453a80();
};
struct ReloadPoint
{
    float x, y, z;
    ReloadPoint(float, int, int);
};
struct ReloadPair
{
    float x, y;
    ReloadPair(float, float);
};
struct ReloadGrid;
struct ReloadCell;
struct ReloadScene;
struct ReloadHandler
{
    void FUN_006fca90(ReloadPoint*, int);
    void FUN_006fcdb0(ReloadPoint*);
    bool FUN_00454b70();
};
struct ReloadWorld
{
    ReloadHandler* FUN_00586170();
};
struct ReloadGrid
{
    bool FUN_00447a00();
    void FUN_00450f90(int);
};
struct ReloadTexture
{
    void* FUN_0044edb0();
    void* FUN_00825c00();
    void FUN_0063ddb0(void*);
};
struct ReloadInterior;
struct ReloadRoot;
struct ReloadObject;
struct ReloadInterior
{
    ReloadGrid* FUN_009611e0();
    void FUN_00526270();
};
struct ReloadInterior;
struct ReloadRoot;
struct ReloadObject;
struct ReloadScene
{
    void* FUN_009d9f20();
    void FUN_00552bd0(bool);
    void FUN_0054af40(bool);
    bool FUN_00454b10();
    ReloadInterior* FUN_00546c20();
    void* GetImpactSwap();
    void FUN_00550340();
    int GetRaceListSize();
    bool FUN_00450fb0();
    void UpdateCellScene(ReloadObject*);
    ReloadRoot* FUN_004543c0();
    void FUN_0054bcf0(bool);
    ReloadObject* GetOrCreateWidget();
    void FUN_0054ba80(bool);
    const char* FUN_004543a0();
};
struct ReloadName
{
    void* FUN_006733e0();
    const char* FUN_00454b50();
};
struct ReloadRoot
{
    void FUN_00454380(int);
    void* FUN_00454b30();
    void FUN_00b5ddf0(int);
    void FUN_00b5d180();
    void FUN_00b5fd60();
    void FUN_00b5cbd0(void*);
    void SetProcessEnabled(bool);
    void FUN_00c66300();
    void FUN_00c6b540(int);
};
ReloadRoot* ReloadGetRoot();
ReloadRoot* ReloadGetRootCreate(int);
ReloadRoot* ReloadGetMain(int);
void ReloadDisableRendering(int);
void ReloadDropResources(int);
void ReloadAttachManager(void*);
void ReloadGlobalUpdate(int);
struct ReloadPlayer
{
    void* FUN_00950bb0(int);
};
struct ReloadData
{
    void DeleteObject(ReloadScene*);
    void ProcessAllFiles();
};
struct ReloadMode
{
    bool FUN_0042ce10();
};
struct ReloadState
{
    bool FUN_0047c850();
};
struct ReloadCells
{
    bool FUN_00447950(ReloadCell*);
};
struct ReloadAudio
{
    void FUN_00c3dfa0(int);
};
struct ReloadObject
{
    void FUN_00a5a040();
    int FUN_00453470();
    void FUN_00a59c60(ReloadPoint*);
};
struct ReloadShader
{
    void FUN_004ba7d0();
};
struct ReloadSetting
{
    float* FUN_00403e20(int);
};
struct ReloadFade
{
    void FUN_00700960(bool, float, int);
};
struct ReloadTerrain
{
    void ClearMobileObjectData();
    void FUN_00972d30();
    void FUN_00972bb0();
};
struct ReloadZone
{
    void SetColorData(void*);
};
struct ReloadNode
{
    unsigned object;
    ReloadNode(int);
    ~ReloadNode();
    void* FUN_00559450();
};
struct TileReloadContext
{
    void FUN_0045cda0();
    void FUN_004568c0(const char*, ReloadNode&, int, int);
    ReloadZone* FUN_0070ec90();
};
struct ReloadContext
{
    int old;
    ReloadContext(int, bool, const char*, int);
    ~ReloadContext();
};
struct ReloadPathing
{
    void ForceUpdate();
};
ReloadPathing* ReloadPathingGet();
extern ReloadPlayer* reloadPlayer;
extern ReloadData* reloadData;
extern ReloadMode* reloadMode;
extern ReloadState* reloadState;
extern ReloadCells* reloadCells;
extern ReloadAudio* reloadAudio;
extern ReloadSetting reloadSetting;
extern ReloadFade* reloadFade;
extern ReloadTerrain reloadTerrain;
extern TileReloadContext* reloadMenu;
extern bool reloadFinished, reloadFlagA, reloadFlagB, reloadHasWorld, reloadFlagC;
extern ReloadPoint reloadRotation;
extern ReloadPair reloadCurrent, reloadPrevious;
extern float reloadHeight;
float ReloadHeight(int);
void ReloadMovePoint(ReloadPoint, ReloadPoint, float);
bool ReloadDropFlag();
struct ReloadCamera
{
    void FUN_004baec0();
};
struct ReloadManager
{
    unsigned unk00;
    unsigned unk04;
    ReloadCamera* camera;
    ReloadObject* object;
    ReloadInterior* interior;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    int gridX;
    int gridY;
    int oldX;
    int oldY;
    unsigned unk34;
    unsigned unk38;
    int* loaded;
    unsigned unk40;
    unsigned unk44;
    int savedX;
    int savedY;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned unk60;
    unsigned unk64;
    ReloadTexture* texture;
    unsigned unk6c;
    unsigned unk70;
    unsigned unk74;
    unsigned unk78;
    unsigned unk7c;
    unsigned unk80;
    unsigned unk84;
    ReloadName* name;
    unsigned unk8c;
    unsigned unk90;
    unsigned unk94;
    unsigned unk98;
    unsigned unk9c;
    unsigned unka0;
    unsigned unka4;
    unsigned unka8;
    unsigned unkac;
    unsigned unkb0;
    unsigned unkb4;
    unsigned unkb8;
    unsigned unkbc;
    ReloadNode loadedNode;
    int FUN_00455200(int, int);
    void FUN_00453940();
    ReloadScene* GetEntry(int);
    void RemoveEntry(ReloadScene*);
    void FUN_008d7dc0(ReloadScene*);
    void Pause(int, int);
    void UpdateSkyModeForCell(ReloadScene*);
    void FUN_00454c20(ReloadScene*);
    void AttachScene(ReloadScene*, ReloadPoint*);
    ReloadWorld* FUN_004fd3e0();
    ReloadScene* FUN_005f36f0();
    bool ContainsCell(ReloadScene*);
    void FUN_008d7dc0(int);
    void Pause(int, ReloadPoint*);
    int FUN_00457620(ReloadPoint*);
    void FUN_00452580(ReloadPoint*, bool);
    ReloadCell* FUN_00451900(int, int);
    void FUN_00457d70(int, ReloadCell*, int);
    ReloadShader* FUN_0044ddc0();
    void InitFromMatrix();
    void InitSoundGrid();
    void FUN_0045cda0();
    void GetLandHeightAt(ReloadPoint*, float&);
    bool FUN_00451530();
    void ProcessItemNodes();
    void FUN_00451cf0();
    void UpdateSkyModeForCell(int);
    void FUN_00452490(int);
    void FUN_00454450(ReloadPoint*);
};
struct ReloadInterface
{
    void FUN_00b65570();
    void FUN_00b631d0();
};
ReloadInterface* ReloadGetInterface();
void ReloadInterfaceReset();
void ReloadInterfaceRefresh();
struct ReloadStreaming
{
    void FUN_00871dc0();
    void FUN_0086ff70();
};
extern ReloadStreaming* reloadStreaming;
struct ReloadBoolSetting
{
    bool* FUN_00408d60();
};
extern ReloadBoolSetting reloadBoolSetting;
struct ReloadRuntime
{
    bool FUN_00ec17c0();
};
extern ReloadRuntime* reloadRuntime;
bool ReloadMenuActive(int, int);
struct ReloadGridSetting
{
    int* FUN_0043d4d0();
};
extern ReloadGridSetting reloadGridSetting;
int ReloadRound(float);
struct ReloadLoaded
{
    void FUN_00628da0();
};
struct ReloadPlayerCheck
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
    virtual int CheckState();
};
extern ReloadPlayerCheck* reloadPlayerCheck;
struct NiSourceTexture;
struct NiTextureFormatPrefs
{
    int ePixelLayout;
    int eAlphaFmt;
    int eMipMapped;
};
extern NiTextureFormatPrefs g_kTexturePrefs;
template <class T> struct TexPtr
{
    T* m_pObject;
    TexPtr(T* apObject);
    ~TexPtr();
    TexPtr& operator=(T* apObject);
    operator T*() const;
};
struct FixedStr
{
    const char* m_kHandle;
    FixedStr(const char* apString);
    ~FixedStr();
};
struct FileFinderStub
{
    static int Exist(const char* apPath, char* apOut, unsigned int auiFlags, unsigned int auiMask);
};
struct SourceTextureStub
{
    static NiSourceTexture* Create(const FixedStr& arName, NiTextureFormatPrefs& arPrefs, bool abA, bool abB);
};
bool StreamGetTexture(const char* apPath, TexPtr<NiSourceTexture>* apTexture);
void TextureLoaded(NiSourceTexture* apTexture, int aiUnk);
void ModelWarning(const char* apFormat, ...);
struct TESTexLoader
{
    void FUN_004568c0(const char* apPath, TexPtr<NiSourceTexture>& arTexture, bool abNoWarning, bool abArchiveOnly);
};
struct FUN_00450f90_obj
{
    void FUN_00450f90(bool abFlag);
};
FUN_00450f90_obj* __cdecl FUN_004e7ff0();
void __cdecl FUN_00457000(int aiType, bool abFlag);
struct FUN_00456fc0_ref
{
    FUN_00450f90_obj* FUN_00456fc0(int aiType);
    void FUN_00557990(bool abFlag, int aiType);
};
struct FUN_00456d00_cnt
{
    int* FUN_0043d4d0();
};
struct FUN_00456d00_tes
{
    FUN_00456fc0_ref* FUN_005f36f0();
    FUN_00456fc0_ref** FUN_00457050(unsigned int i, unsigned int j);
};
struct FUN_00456d00_shell
{
    char pad[0x38];
    FUN_00456fc0_ref** ppRefs;
    FUN_00456fc0_ref** ppOthers;
    FUN_00456fc0_ref* FUN_005f36f0();
    void FUN_00456d00(int aiType, bool abShow, bool abGrid);
};
struct NiPoint3;
extern const NiPoint3 NiPoint3_ZERO;
struct FUN_004571c0_obj
{
    void SetFlag(void* p);
    void SetTransforms(const NiPoint3* a, const NiPoint3* b, int c);
};
struct FUN_004571c0_cell : FUN_004570d0_node
{
    bool Apply(FUN_004571c0_obj* obj, int a2, int a3, float f, unsigned char b);
};
struct FUN_004571c0_cls : FUN_004570d0_cls
{
    bool ApplyToObject(FUN_004571c0_obj* obj, int a2, int a3, float f, char b);
};
struct WS458200_Obj
{
    void FUN_00526270();
};
struct WS458200_Quest;
struct WS458200_World
{
    WS458200_Obj* GetFieldD0();
    WS458200_Quest* FUN_006733e0();
    const char* FUN_00454b50() const;
    bool IsFlag4C20Set();
};
struct WS458200_Sky
{
    void SetColorData(NiSourceTexture* apTexture);
};
struct WS458200_TES
{
    WS458200_Sky* GetSky();
    void CreateTextureImage(const char* apPath, NiPointer<NiSourceTexture>& arTexture, bool abA, bool abB);
};
extern WS458200_TES* g_pWS458200TES;
extern GlobalObject_0045cf30 g_011c3d40;
void __cdecl FUN_0058eeb0(WS458200_Quest*);
void __cdecl FUN_007043c0();
void __cdecl FUN_00709d20(WS458200_World*);
void __cdecl FUN_004583f0(bool);
struct WS458200_Shell
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
    WS458200_World* m_pContainingWorldspace;

    void* FUN_005f36f0();
    void FUN_00453940();
    int FUN_00455200(bool abSkipLoaded, WS458200_World* apWorld);
    int FUN_00454d50(bool abArg);
    void FUN_00452490(bool abArg);
    void FUN_00450d80();
    void FUN_00458200(WS458200_World* apWorld);
};
struct Point458
{
    float x, y, z;
};
class Ref458
{
  public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual void vfn0B4();
    virtual void vfn0B8();
    virtual void vfn0BC();
    virtual void vfn0C0();
    virtual void vfn0C4();
    virtual void vfn0C8();
    virtual void vfn0CC();
    virtual void vfn0D0();
    virtual void vfn0D4();
    virtual void vfn0D8();
    virtual void vfn0DC();
    virtual void vfn0E0();
    virtual void vfn0E4();
    virtual void vfn0E8();
    virtual void vfn0EC();
    virtual void vfn0F0();
    virtual void vfn0F4();
    virtual void vfn0F8();
    virtual void vfn0FC();
    virtual void vfn100();
    virtual void vfn104();
    virtual void vfn108();
    virtual void vfn10C();
    virtual void vfn110();
    virtual void vfn114();
    virtual void vfn118();
    virtual void vfn11C();
    virtual void vfn120();
    virtual void vfn124();
    virtual void vfn128();
    virtual void vfn12C();
    virtual void vfn130();
    virtual void vfn134();
    virtual bool PlaySound(int iSound, Point458 kPos);
};
class Manager458
{
  public:
    Ref458* GetDefaultRef();
    bool PlaySoundOnRef(int iSound, Point458 kPos, Ref458* pkRef);
};
struct SaveWriter : SaveState
{
    unsigned char* FUN_00825c00();
    void FUN_008579b0(void*, unsigned int);
    void FUN_00857a10(void*, unsigned int);
};
struct ValueReferencePair
{
    C_0084e3a0* form;
    unsigned short value;
};
struct SaveEntryNode
{
    ValueReferencePair** FUN_006815c0();
    SaveEntryNode* FUN_00726070();
};
struct SaveBlockOwner : SaveSizeOwner
{
    void WriteSaveBlock();
};
void FNV_Warning(const char*, ...);
extern const char DAT_01017e24[];
struct EmptyStructPlaceholder
{
};
struct TestWorldString
{
    const char* FUN_00408da0();
};
struct TestWorld
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
    virtual void Slot64();
    virtual void Slot65();
    virtual void Slot66();
    virtual void Slot67();
    virtual void Slot68();
    virtual void Slot69();
    virtual void Slot70();
    virtual void Slot71();
    virtual void Slot72();
    virtual void Slot73();
    virtual void Slot74();
    virtual void Slot75();
    virtual const char* DebugName();
    int unk04, unk08, unk0c, unk10, unk14;
    TestWorldString name;
    float FUN_004565f0();
    float GetUnka4();
    float FUN_009b88a0();
    float FUN_009b88c0();
    unsigned int FUN_0084e3a0();
    EmptyStructPlaceholder* FUN_005875a0(int, int);
    EmptyStructPlaceholder* FUN_00585b30(int, int);
};
struct TestWorldList
{
    bool FUN_008256d0();
    TestWorld** FUN_006815c0();
    TestWorldList* FUN_00726070();
};
struct TestDataHandler
{
    TestWorldList* FUN_00460140();
    void FUN_004619b0();
    unsigned int FUN_00461960();
    EmptyStructPlaceholder* GetCameraPathAt(unsigned int);
};
extern TestDataHandler* testDataHandler;
struct TestStep
{
    int* FUN_0043d4d0();
};
extern TestStep testStep;
void FUN_009526a0(bool);
void FUN_0040fbe0(const char*, ...);
void FUN_007037e0();
int FUN_00457fe0();
unsigned int FUN_0044a670(const char*);
struct CellTest
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
    unsigned char unk50;
    bool running, finished;
    void FUN_00458200(TestWorld*);
    void MoveToCell(EmptyStructPlaceholder*, unsigned int, int);
    void FUN_00459ae0(unsigned int);
};
struct QueuedFile
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    QueuedFile(int priority);
};
struct AddonQueuePointer
{
    QueuedFile* object;
    QueuedFile* FUN_00559450();
    AddonQueuePointer& FUN_006f74f0(QueuedFile* file);
};
struct AddonFormBase
{
    virtual void ReservedForm0();
    unsigned int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
};
struct TESModel
{
    virtual void Reserved0();
    virtual void Reserved1();
    virtual void Reserved2();
    virtual void Reserved3();
    virtual void Reserved4();
    virtual char* GetModelPath();
};
struct BGSAddonNode : AddonFormBase, TESModel
{
    bool FUN_00448bf0();
    unsigned int GetGrass();
    int FUN_0059e300();
    unsigned short GetShortAtOffset58();
};
struct AddonParticleNode : NiNode
{
    void SetSound(unsigned int index);
    void FUN_00705b10(int value);
    void SetShortAtOffsetBC(unsigned short value);
};
struct AddonParticleManager
{
    void FUN_0045a160(AddonParticleNode* node);
};
AddonParticleManager* FUN_0045a190();
extern ModelLoader* g_modelLoader;
struct AddonOwner
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    unsigned int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0;
    AddonQueuePointer queuedFile;
    void FUN_00459f10();
};
struct ModelSetting
{
    char* String();
};
extern bool DAT_011c3f08;
extern ModelLoader* g_modelLoader;
struct PreloadOwner : ModelCloneOwner
{
    void PreloadModelSettings();
};
extern ModelSetting g_011ce0c0;
extern ModelSetting g_011cfa28;
extern ModelSetting g_011d12c0;
extern ModelSetting g_011ce1a0;
extern ModelSetting g_011cfa64;
extern ModelSetting g_011cf3a4;
extern ModelSetting g_011cf54c;
extern ModelSetting g_011cebb0;
struct FUN_0045ae20
{
    ~FUN_0045ae20();
    FUN_0045ae20* FUN_0044ddc0();
};
struct InventoryMenuSetting
{
    const char* FUN_00403df0();
};
extern FUN_0045a5e0_shell* DAT_011c3b3c;
extern InventoryMenuSetting DAT_011cebb0;
extern InventoryMenuSetting DAT_011d12c0;
extern InventoryMenuSetting DAT_011ce1a0;
extern InventoryMenuSetting DAT_011cf3a4;
extern InventoryMenuSetting DAT_011cf54c;
extern InventoryMenuSetting DAT_011cfa64;
extern InventoryMenuSetting DAT_011ce0c0;
extern InventoryMenuSetting DAT_011cfa28;
struct Target
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
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    FUN_0045ae20* head;
    void FUN_0045ac80();
};
class NavMeshInfoMap45A
{
  public:
    NavMeshInfoMap45A();

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
};
class TESDataHandler45A
{
  public:
    bool IsLoading();
};
extern TESDataHandler45A* g_pkDataHandler45A;
class Owner45A
{
  public:
    NavMeshInfoMap45A* FUN_0045af00();

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
    NavMeshInfoMap45A* m_pkNavMeshInfoMap;
};
extern float DAT_01015f5c;
struct CellView : public TESObjectCELL
{
    bool CheckWaterHeight(const NiPoint3* apPos, float* apfHeight);
    int FUN_00544c30();
    int FUN_00544c60();
};
bool __fastcall FUN_00425fd0(TESObjectCELL* apCell);
struct FUN_0045cbc0_Grid
{
    CellView* FUN_00587550(const NiPoint3* apPos);
    float FUN_0045cd80();
    CellView* FUN_005875a0(int aiX, int aiY);
};
struct FUN_0045cbc0_TES
{
    FUN_0045cbc0_Grid* FUN_004fd3e0();
    int FUN_0059bb30();
    int FUN_0045cd60();
};
struct FUN_0045cbc0_shell
{
    CellView* FUN_005f36f0();
    float GetCellHeightAtPosition(const NiPoint3* apPos, CellView* apCell);
};
// Register this reference with its cell's world occlusion manager (planes, lists and bounds).
class C6760Base
{
  public:
    virtual ~C6760Base();
    int unk04;
};
class C6760ManagerBase
{
  public:
    virtual ~C6760ManagerBase();
};
class C6760Ref;
class C6760Manager : public C6760Base, public C6760ManagerBase
{
  public:
    void AddPlanes(C6760Ref* pkRef);
    void AddToLists(C6760Ref* pkRef);
    void UpdateBounds(C6760Ref* pkRef);
};
class C6760World
{
  public:
    C6760ManagerBase* GetOcclusionManager();
};
class C6760Cell
{
  public:
    C6760World* GetWorld();
};
class C6760Ref
{
  public:
    C6760Cell* GetParentCell();
    void FUN_00576760();
};
int __cdecl FUN_00406d90(float f);
namespace n451 {
struct Pt
{
    float iMinY, nX, z;
};
struct Grid
{
    char pad[0x24];
    int m_24;
    int m_28;
    void* FUN_005f36f0();
    bool ContainsPoint(const Pt& pt);
};
}
// @fnv 0x00451110
bool n451::Grid::ContainsPoint(const Pt& pt)
{
    if (FUN_005f36f0())
        return true;
    int iMinY = FUN_00406d90(pt.iMinY) >> 12;
    int nX = FUN_00406d90(pt.nX) >> 12;
    int ix = m_24 - (*DAT_011c63cc.FUN_0043d4d0() >> 1);
    int px = m_28 - (*DAT_011c63cc.FUN_0043d4d0() >> 1);
    if (iMinY < ix || iMinY >= ix + (int)*DAT_011c63cc.FUN_0043d4d0() || nX < px ||
        nX >= px + (int)*DAT_011c63cc.FUN_0043d4d0())
        return false;
    return true;
}

struct FUN_005400e0_obj : FUN_0045cb90_cls
{
    void FUN_005400e0();
};
struct FUN_00546fb0_cell : B45CDA0Cell
{
    FUN_005400e0_obj* FUN_00546fb0();
};
struct FUN_0045cac0_tes : B45CDA0TES
{
    void FUN_0045cac0();
};
struct CellHit
{
    bool FUN_0053d2e0();
};
struct CellProbe
{
    CellHit* FUN_00546fb0(const NiPoint3* pos, NiPoint3* normal, int flags);
};
struct TESCellLookup
{
    bool FUN_004511e0(void* cell, unsigned char flag);
};
struct FUN_004573f0_shell : public TES
{
    TESObjectCELL* FUN_00451900(int cellX, int cellY);
    bool FUN_004573f0(const NiPoint3* pos, NiPoint3* normal, int flags);
};

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern const double DAT_01012060;

struct StandRTTI
{
    const char* m_pcName;
    const StandRTTI* m_pBaseRTTI;
};
struct StandRef
{
    virtual ~StandRef();
    virtual void DeleteThis();
    virtual const StandRTTI* GetRTTI() const;
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
template <class T> struct StandPtr
{
    T* m_pObject;
    StandPtr(T* p = 0) : m_pObject(p)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~StandPtr()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
};
struct StandNode;
struct StandChildren
{
    virtual ~StandChildren();
    StandRef** data;
    unsigned short capacity;
    unsigned short firstFree;
    unsigned short size;
    unsigned short grow;
    StandRef* const& GetAt(unsigned int i) const
    {
        StandRef* const& item = data[i];
        return item;
    }
};
struct StandNode : StandRef
{
    virtual void Unk0c();
    virtual void Unk10();
    virtual void Unk14();
    virtual void Unk18();
    virtual void Unk1c();
    virtual void Unk20();
    virtual void Unk24();
    virtual void Unk28();
    virtual void Unk2c();
    virtual void Unk30();
    virtual void Unk34();
    virtual void Unk38();
    virtual void Unk3c();
    virtual void Unk40();
    virtual void Unk44();
    virtual void Unk48();
    virtual void Unk4c();
    virtual void Unk50();
    virtual void Unk54();
    virtual void Unk58();
    virtual void Unk5c();
    virtual void Unk60();
    virtual void Unk64();
    virtual void Unk68();
    virtual void Unk6c();
    virtual void Unk70();
    virtual void Unk74();
    virtual void Unk78();
    virtual void Unk7c();
    virtual void Unk80();
    virtual void Unk84();
    virtual void Unk88();
    virtual void Unk8c();
    virtual void Unk90();
    virtual void Unk94();
    virtual void Unk98();
    virtual void Unk9c();
    virtual void Unka0();
    virtual void Unka4();
    virtual void Unka8();
    virtual void Unkac();
    virtual void Unkb0();
    virtual void Unkb4();
    virtual void Unkb8();
    virtual void Unkbc();
    virtual void Unkc0();
    virtual void Unkc4();
    virtual void Unkc8();
    virtual void Unkcc();
    virtual void Unkd0();
    virtual void Unkd4();
    virtual void Unkd8();
    virtual void Unkdc();
    virtual void Unke0();
    virtual void Unke4();
    virtual void Unke8();
    virtual void RemoveAt(unsigned int i, StandPtr<StandRef>& removed);
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
    unsigned int unk98;
    StandChildren children;
    float time;
    float UpdateTime(float f)
    {
        float delta = time != DAT_01012060 ? f - time : time;
        time = f;
        return delta;
    }
    StandRef* GetChild(unsigned int i)
    {
        StandRef* const& entry = children.data[i];
        {
            StandRef* item = entry;
            return item;
        }
    }
    void SetTime(float f)
    {
        time = f;
        if (time < DAT_01012060)
            time = 0.0f;
    }
    bool Expired() const
    {
        return time == DAT_01012060;
    }
    void FUN_00c44ed0(float);
};
__forceinline bool IsKindOfType(const StandRTTI* target, const StandRef* object)
{
    const StandRTTI* rtti = object->GetRTTI();
    while (rtti)
    {
        if (rtti == target)
            return true;
        rtti = rtti->m_pBaseRTTI;
    }
    return false;
}
__forceinline StandNode* CastNode(StandRef* object)
{
    if (!object)
        return 0;
    return IsKindOfType(reinterpret_cast<const StandRTTI*>(&g_01202e00), object) ? static_cast<StandNode*>(object) : 0;
}
// @fnv 0x00c44ed0
void StandNode::FUN_00c44ed0(float f)
{
    StandPtr<StandRef> spRemoved;
    float delta = UpdateTime(f);
    {
        unsigned int i = children.firstFree;
        while (i--)
        {
            StandRef* object = GetChild(i);
            StandNode* child = CastNode(object);
            if (child)
            {
                child->SetTime(child->time - delta);
                if (child->Expired())
                    RemoveAt(i, spRemoved);
            }
        }
    }
}
