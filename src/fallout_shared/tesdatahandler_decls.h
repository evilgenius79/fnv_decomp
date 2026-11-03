// fallout_shared/tesdatahandler_decls.h: declares AutoMemContext, TESDataHandler
#ifndef FNV_TESDATAHANDLER_DECLS_H
#define FNV_TESDATAHANDLER_DECLS_H

#include "tesdatahandler_forms.h"
#include "tesdatahandler_defaults.h"
#include "tesdatahandler_files.h"
enum MEM_CONTEXT
{
    MEM_CONTEXT_COMPILE = 22,
    MEM_CONTEXT_ARCHIVES = 19,
    MEM_CONTEXT_DEFAULT_OBJECTS = 47,
    MEM_CONTEXT_FORMS = 48
};
class AutoMemContext
{
    unsigned int previous;

  public:
    AutoMemContext(MEM_CONTEXT, bool, const char*, int);
    ~AutoMemContext();
};
class TESDataHandler
{
  public:
    unsigned int flags;
    TESFormList* objectList;
    unsigned char data_008[8];
    BSSimpleList<TESWorldSpace*> worldSpaces;
    unsigned char data_018[0x1c4];
    NiTArray<TESObjectCELL*, NiTMallocInterface<TESObjectCELL*> > interiorCells;
    NiTArray<BGSAddonNode*, NiTMallocInterface<BGSAddonNode*> > addonNodes;
    NiTPointerList<TESForm*> pendingReferences;
    unsigned int nextID;
    TESFile* activeFile;
    BSSimpleList<TESFile*> files;
    unsigned int loadedCount;
    TESFile* loadedFiles[255];
    bool allowPlugin, specialFile, compiling, flag61b, flag61c, flag61d, flag61e, flag61f, flag620, flag621;
    unsigned char loadingGroup;
    TESObjectCELL* GetCellByWorldPosition(float, float, TESWorldSpace*, bool);
    TESRegionList* GetRegionList();
    void RegisterAddonNode(BGSAddonNode*);
    int GetDLCIndex(const char*);
    void GetReferencesInArea(TESObjectCELL*, const NiPoint3&, float, const NiPoint3&, float,
                             bool(__cdecl*)(TESObjectREFR*, long), long);
    void GetRegions();
    TESFormList* GetObjectList();
    TESFile* LookupTESFile(const char*);
    unsigned int GetNextID();
    bool IsIDUsed(unsigned int);
    void IncrementID();
    void BuildCompiledFileList();
    TESSound* GetSoundByEditorID(const char*);
    BGSAddonNode* GetAddonNodeByIndex(unsigned int);
    TESReputation* GetReputation(unsigned int);
    TESLoadScreenType* GetLoadScreenType(unsigned int);
    TESFaction* GetFactionByFormID(unsigned int);
    TESFile* GetCompiledFileByIndex(int);
    unsigned int GetCompiledFileCount();
    bool AddFormToDataHandler(TESForm*);
    BSSimpleList<TESReputation*>* GetTESReputationList();
    BSSimpleList<TESChallenge*>* GetTESChallengeList();
    BSSimpleList<BGSRecipe*>* GetBGSRecipeList();
    BSSimpleList<BGSRecipeCategory*>* GetBGSRecipeCategoryList();
    BSSimpleList<TESAmmoEffect*>* GetTESAmmoEffectList();
    BSSimpleList<TESCasino*>* GetTESCasinoList();
    BSSimpleList<TESCaravanDeck*>* GetTESCaravanDeckList();
    BSSimpleList<TESClass*>* GetTESClassList();
    BSSimpleList<BGSNote*>* GetBGSNoteList();
    BSSimpleList<BGSHeadPart*>* GetBGSHeadPartList();
    BSSimpleList<TESHair*>* GetTESHairList();
    BSSimpleList<TESRace*>* GetTESRaceList();
    BSSimpleList<BGSEncounterZone*>* GetBGSEncounterZoneList();
    BSSimpleList<TESQuest*>* GetTESQuestList();
    BSSimpleList<TESSound*>* GetTESSoundList();
    BSSimpleList<BGSAcousticSpace*>* GetBGSAcousticSpaceList();
    BSSimpleList<TESLandTexture*>* GetTESLandTextureList();
    BSSimpleList<BGSCameraShot*>* GetBGSCameraShotList();
    BSSimpleList<Script*>* GetScriptList();
    BSSimpleList<TESPackage*>* GetTESPackageList();
    BSSimpleList<BGSImpactData*>* GetBGSImpactDataList();
    BSSimpleList<BGSImpactDataSet*>* GetBGSImpactDataSetList();
    BSSimpleList<BGSMenuIcon*>* GetBGSMenuIconList();
    BSSimpleList<SpellItem*>* GetSpellItemList();
    BSSimpleList<EnchantmentItem*>* GetEnchantmentItemList();
    BSSimpleList<TESLoadScreen*>* GetTESLoadScreenList();
    BSSimpleList<TESObjectANIO*>* GetTESObjectANIOList();
    BSSimpleList<TESEffectShader*>* GetTESEffectShaderList();
    BSSimpleList<BGSProjectile*>* GetBGSProjectileList();
    BSSimpleList<BGSDebris*>* GetBGSDebrisList();
    BSSimpleList<BGSPerk*>* GetBGSPerkList();
    BSSimpleList<BGSBodyPartData*>* GetBGSBodyPartDataList();
    BSSimpleList<BGSRadiationStage*>* GetBGSRadiationStageList();
    BSSimpleList<BGSDehydrationStage*>* GetBGSDehydrationStageList();
    BSSimpleList<BGSHungerStage*>* GetBGSHungerStageList();
    BSSimpleList<BGSSleepDeprivationStage*>* GetBGSSleepDeprivationStageList();
    BSSimpleList<BGSRagdoll*>* GetBGSRagdollList();
    BSSimpleList<BGSLightingTemplate*>* GetBGSLightingTemplateList();
    BSSimpleList<BGSMusicType*>* GetBGSMusicTypeList();
    BSSimpleList<TESLoadScreenType*>* GetTESLoadScreenTypeList();
    BSSimpleList<MediaSet*>* GetMediaSetList();
    BSSimpleList<MediaLocationController*>* GetMediaLocationControllerList();
    BSSimpleList<TESSkill*>* GetTESSkillList();
    BSSimpleList<TESTopic*>* GetTESTopicList();
    BSSimpleList<TESIdleForm*>* GetTESIdleFormList();
    BSSimpleList<TESFile*>* GetFileList();
    void SetSaveLoadGameState(int);
    bool LoadPluginFiles(bool);
    void MarkGameSettingsLoaded();
    void ReportDataHandlerError(int);
    void DisableAssignFormIDs(bool);
    bool FUN_00467780(TESFile*, bool);
    void FUN_00464d50(TESForm*);
    void FUN_00464d70(TESForm*);
    void SetField638(TESForm*);
    BSSimpleList<TESForm*>* FUN_00436aa0();
    BSSimpleList<TESForm*>* FUN_00624700();
    BSSimpleList<TESForm*>* FUN_004612e0();
    BSSimpleList<TESForm*>* FUN_004077e0();
    BSSimpleList<TESForm*>* FUN_0041d8a0();
    BSSimpleList<TESForm*>* FUN_0087eaa0();
    BSSimpleList<TESForm*>* FUN_00413f40();
    BSSimpleList<TESForm*>* FUN_00461110();
    BSSimpleList<TESForm*>* FUN_004ea950();
    BSSimpleList<TESForm*>* GetOffsetPtr();
    BSSimpleList<TESForm*>* FUN_0045a330();
    BSSimpleList<TESForm*>* FUN_004a0d10();
    bool ConstructObject(TESFile*, bool, TESForm*, bool);
    static bool LoadForm(TESForm*, TESFile*);
    void AddTopic(TESTopic*);
    void AddTopicInfo(TESTopicInfo*);
    void InitializeMagicSystem();
    BSSimpleList<BGSExplosion*>* GetBGSExplosionList();
    BSSimpleList<TESEyes*>* GetTESEyesList();
    BSSimpleList<BGSVoiceType*>* GetBGSVoiceTypeList();
    BSSimpleList<TESWaterForm*>* GetTESWaterFormList();
    BSSimpleList<TESWorldSpace*>* GetTESWorldSpaceList();
    BSSimpleList<TESFaction*>* GetTESFactionList();
    BSSimpleList<TESGlobal*>* GetTESGlobalList();
    BSSimpleList<TESWeather*>* GetTESWeatherList();
    BSSimpleList<TESClimate*>* GetTESClimateList();
    BSSimpleList<BGSListForm*>* GetBGSListFormList();
    BSSimpleList<BGSMessage*>* GetBGSMessageList();
    BSSimpleList<TESImageSpace*>* GetTESImageSpaceList();
    BSSimpleList<TESImageSpaceModifier*>* GetTESImageSpaceModifierList();
    BSSimpleList<TESCombatStyle*>* GetTESCombatStyleList();
    static TESForm* CreateFormForType(unsigned char);
};
#endif
