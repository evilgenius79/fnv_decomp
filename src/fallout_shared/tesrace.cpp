// fallout_shared/tesrace.cpp: TESRace, Obj, RaceCleanup, RaceReset and more (42 functions)

#include "tesrace_types.h"

// @fnv 0x00611e30
void TESRace::SetDefaultHairColor(SEX sex, unsigned char color)
{
    m_acDefaultHairColors[sex] = color;
}

// Assigns voice to the race's voice-type slot for sex, or falls back to the male/female default when voice is null.
// @fnv 0x00610c70
void TESRace::SetDefaultVoiceType(SEX sex, BGSVoiceType* voice)
{
    if (!voice)
    {
        if (sex == SEX_SEX_MALE)
            m_apDefaultVoiceTypes[sex] = g_pDefaultMaleVoiceType;
        if (sex == SEX_SEX_FEMALE)
            m_apDefaultVoiceTypes[sex] = g_pDefaultFemaleVoiceType;
    }
    else
    {
        m_apDefaultVoiceTypes[sex] = voice;
    }
}

// @fnv 0x006128c0
void TESRace::InitItem()
{
    if (GetInitialized())
        return;
    if (m_apDefaultVoiceTypes[0])
    {
        unsigned int maleVoiceID = reinterpret_cast<unsigned int>(m_apDefaultVoiceTypes[0]);
        RemapFormIDForFile(maleVoiceID, GetFile(-1));
        m_apDefaultVoiceTypes[0] = dynamic_cast<BGSVoiceType*>(GetFormByID(maleVoiceID));
        if (!m_apDefaultVoiceTypes[0])
            Warning("MASTERFILE: Could not find male voice type (%08X) for race '%s' (%08X).", maleVoiceID, GetName(),
                    GetFormID());
    }
    if (m_apDefaultVoiceTypes[1])
    {
        unsigned int femaleVoiceID = reinterpret_cast<unsigned int>(m_apDefaultVoiceTypes[1]);
        RemapFormIDForFile(femaleVoiceID, GetFile(-1));
        m_apDefaultVoiceTypes[1] = dynamic_cast<BGSVoiceType*>(GetFormByID(femaleVoiceID));
        if (!m_apDefaultVoiceTypes[1])
            Warning("MASTERFILE: Could not find female voice type (%08X) for race '%s' (%08X).", femaleVoiceID,
                    GetName(), GetFormID());
    }
    if (m_apDefaultHairStyles[0])
    {
        unsigned int maleHairID = reinterpret_cast<unsigned int>(m_apDefaultHairStyles[0]);
        RemapFormIDForFile(maleHairID, GetFile(-1));
        m_apDefaultHairStyles[0] = dynamic_cast<TESHair*>(GetFormByID(maleHairID));
        if (!m_apDefaultHairStyles[0])
            Warning("MASTERFILE: Could not find male default hair (%08X) for race '%s' (%08X).", maleHairID, GetName(),
                    GetFormID());
    }
    if (m_apDefaultHairStyles[1])
    {
        unsigned int femaleHairID = reinterpret_cast<unsigned int>(m_apDefaultHairStyles[1]);
        RemapFormIDForFile(femaleHairID, GetFile(-1));
        m_apDefaultHairStyles[1] = dynamic_cast<TESHair*>(GetFormByID(femaleHairID));
        if (!m_apDefaultHairStyles[1])
            Warning("MASTERFILE: Could not find female default hair (%08X) for race '%s' (%08X).", femaleHairID,
                    GetName(), GetFormID());
    }
    if (m_pOlderRace)
    {
        unsigned int olderRaceID = reinterpret_cast<unsigned int>(m_pOlderRace);
        RemapFormIDForFile(olderRaceID, GetFile(-1));
        m_pOlderRace = dynamic_cast<TESRace*>(GetFormByID(olderRaceID));
        if (!m_pOlderRace)
            Warning("MASTERFILE: Could not find older race (%08X) for race '%s' (%08X).", olderRaceID, GetName(),
                    GetFormID());
    }
    if (m_pYoungerRace)
    {
        unsigned int youngerRaceID = reinterpret_cast<unsigned int>(m_pYoungerRace);
        RemapFormIDForFile(youngerRaceID, GetFile(-1));
        m_pYoungerRace = dynamic_cast<TESRace*>(GetFormByID(youngerRaceID));
        if (!m_pYoungerRace)
            Warning("MASTERFILE: Could not find younger race (%08X) for race '%s' (%08X).", youngerRaceID, GetName(),
                    GetFormID());
    }
    TESSpellList::InitItem(this);
    TESReactionForm::InitItem(this);
    SetInitializationState(true);
}

// Builds a "<raceID>_<rootID>ModBody<Male|Female>" or "<rootID>ModBody<Male|Female>" string from the race and the deepest template NPC's form IDs.
// @fnv 0x006147e0
void TESRace::BuildBodyTexturePath(TESNPC* npc, char* out)
{
    TESNPC* npcID = npc;
    char acRacePath[16];
    if (npc->FUN_006044c0())
    {
        npcID = npc->FUN_006044c0();
        while (npcID && npcID->FUN_006044c0())
            npcID = npcID->FUN_006044c0();
    }
    if (npc->GetSex() == SEX_SEX_FEMALE)
        sprintf(acRacePath, "Female");
    else
        sprintf(acRacePath, "Male");
    unsigned int raceID = GetFormID() & 0xffffff;
    unsigned int root = npcID->GetFormID() & 0xffffff;
    if (npc->model.HasModel())
        sprintf_s(out, 260, "%08x_%08XModBody%s", raceID, root, acRacePath);
    else
        sprintf_s(out, 260, "%08XModBody%s", root, acRacePath);
}

// Returns the model for the given sex and biped part, falling back to the opposite sex's model if the requested one is empty.
// @fnv 0x006151f0
TESModel* TESRace::GetBipedObjectModel(SEX sex, BIPED_OBJECT part)
{
    int index = NormalizePartIndex(part);
    if (sex < 0 || sex >= 2 || index < 0 || index >= 3)
        return 0;
    if (GetBodyPartModel(sex, index) && GetBodyPartModel(sex, index)->GetModelLength())
        return GetBodyPartModel(sex, index);
    switch (sex)
    {
    case SEX_SEX_MALE:
        if (GetBodyPartModel(SEX_SEX_FEMALE, index) && GetBodyPartModel(SEX_SEX_FEMALE, index)->GetModelLength())
            return GetBodyPartModel(SEX_SEX_FEMALE, index);
        break;
    case SEX_SEX_FEMALE:
        if (GetBodyPartModel(SEX_SEX_MALE, index) && GetBodyPartModel(SEX_SEX_MALE, index)->GetModelLength())
            return GetBodyPartModel(SEX_SEX_MALE, index);
        break;
    }
    return 0;
}

// Builds a model path for the given BIPED_OBJECT and sex, appending a first-person suffix for the player, and returns false if no model exists.
// @fnv 0x00614640
bool TESRace::GetBipedObjectModelPath(TESNPC* npc, BIPED_OBJECT part, char* out)
{
    int sex = NormalizePartIndex(part);
    if (sex < 0 || sex >= 3)
        return false;
    SEX index = npc ? npc->GetSex() : SEX_SEX_MALE;
    if (!reinterpret_cast<TESModel*>(&m_kHeadPartTextures[index][sex])->GetModelLength() && sex == 2)
        sex = 1;
    if (!reinterpret_cast<TESModel*>(&m_kHeadPartTextures[index][sex])->GetModelLength())
        return false;
    TaskQueueInterface::CopyStringToBuffer(out, 260, "Textures\\");
    strcat_s(out, 260, reinterpret_cast<TESFullName*>(&m_kHeadPartTextures[index][sex])->GetFullName());
    if (npc && npc == reinterpret_cast<TESNPC*>(g_thePlayer->GetObjectReference()) && (sex == 1 || sex == 2))
    {
        const char* extension =
            strrchr(reinterpret_cast<TESFullName*>(&m_kHeadPartTextures[index][sex])->GetFullName(), '.');
        char* dot = FUN_0040ab30(out, '.');
        if (dot && extension)
        {
            *dot = 0;
            strcat_s(out, 260, "_1st");
            strcat_s(out, 260, extension);
        }
    }
    return true;
}

// @fnv 0x00610210
TESRace::TESRace() : m_kFaceGenUndoList(0, 1)
{
    SetFormType(ENUM_FORM_ID_RACE_ID);
    ResetFormData();
}

// @fnv 0x00613fd0
void TESRace::ClearFaceGenUndo()
{
    BSStringT<char> filename;
    char path[260];
    for (int i = 0; i < 8; i++)
    {
        TESModel* female = GetHeadPartModel(SEX_SEX_MALE, i);
        if (female && *female->GetModelFilePath())
        {
            TaskQueueInterface::CopyStringToBuffer(path, 260, "Meshes\\");
            strcat_s(path, 260, female->GetModelFilePath());
            BSFaceGenManager::BuildFaceGenModelPath(filename, path);
            BSFaceGenManager::GetModelMap()->HasFaceGenData(
                reinterpret_cast<const char*>(reinterpret_cast<GarbageCollectorObjectPtr*>(&filename)->operator->()));
        }
        TESModel* male = GetHeadPartModel(SEX_SEX_FEMALE, i);
        if (male && *male->GetModelFilePath() && male->CompareWithBase(female))
        {
            TaskQueueInterface::CopyStringToBuffer(path, 260, "Meshes\\");
            strcat_s(path, 260, male->GetModelFilePath());
            BSFaceGenManager::BuildFaceGenModelPath(filename, path);
            BSFaceGenManager::GetModelMap()->HasFaceGenData(
                reinterpret_cast<const char*>(reinterpret_cast<GarbageCollectorObjectPtr*>(&filename)->operator->()));
        }
    }
}

extern int DAT_0104b5f8;

// @fnv 0x006104a0
TESModel* __fastcall ConstructTESModel(TESModel* pThis)
{
    pThis->TESModel::TESModel();
    *(int**)pThis = &DAT_0104b5f8;
    return pThis;
}

struct FUN_00613970_shell : public TESRace
{
    TESModel* FUN_00613970(int, int);
};

// Returns the TESModel for the given sex and body part index, or null if the part index is out of range.
// @fnv 0x00613970
TESModel* FUN_00613970_shell::FUN_00613970(int aeSex, int aePart)
{
    if (aePart < 0 || aePart >= 8)
        return 0;
    return &m_kBodyPartModels[aeSex][aePart];
}

struct FUN_00613a20_shell : public TESRace
{
    TESModel* FUN_00613a20(int, int);
};

// Returns the TESModel for the given sex and body part index, or null if the part index is outside 0..2.
// @fnv 0x00613a20
TESModel* FUN_00613a20_shell::FUN_00613a20(int aeSex, int aePart)
{
    if (aePart < 0 || aePart >= 3)
        return 0;
    return &m_kHeadPartModels[aeSex][aePart];
}

struct FUN_00613b20_shell : public TESRace
{
    TESTexture* GetBodyPartTexture(int, int);
};

// Returns the TESTexture for the given sex and body part index, or null if the part index is out of range (0-7).
// @fnv 0x00613b20
TESTexture* FUN_00613b20_shell::GetBodyPartTexture(int aeSex, int aePart)
{
    if (aePart < 0 || aePart >= 8)
        return 0;
    return &m_kBodyPartTextures[aeSex][aePart];
}

struct FUN_00613fb0_C
{
    char _pad[0xe1];
    bool bIAmPlayerCharacter;
    void Set(bool abIAmPC);
};

// @fnv 0x00613fb0
void FUN_00613fb0_C::Set(bool abIAmPC)
{
    bIAmPlayerCharacter = abIAmPC;
}

namespace fnv_006148f0 {
struct BSFile;
struct FormRecordHeader;
struct TESFileGroup;
struct TESBitArrayFile;
struct TESObjectCELL;
struct _FILETIME;
struct _SYSTEMTIME;
struct _WIN32_FIND_DATAA;
struct TESFile
{
    bool CreateTES(char*, char*, int);
    bool CreateTES(int);
    bool OpenTESFile(char*, char*, int, bool);
    bool OpenTESFile(int, bool);
    bool CloseTESFile();
    bool DeleteTES();
    bool IsOpen();
    bool QDLC();
    void SetDLC(bool);
    int ReadTESInfo();
    int SaveTESInfo();
    int RewriteFormHeader();
    TESForm* BuildTESInfoForm();
    int GetFormCount();
    void ModFormCount(int);
    void SetFormCount(int);
    int GetFileLanguage();
    void SetFileLanguage(int);
    float GetFileVersion();
    void SetFileVersion(float);
    bool IsValidFileVersion();
    unsigned int GetFORMSize();
    char* GetPath();
    char* GetFilename();
    unsigned int GetFileSize();
    _WIN32_FIND_DATAA* GetFileData();
    void GetCreateTime(_SYSTEMTIME*);
    void GetLastWriteTime(_FILETIME*);
    void GetLastWriteTime(_SYSTEMTIME*);
    void* GetCreator();
    void* GetSummary();
    bool MastersChecked(void*);
    bool CheckMasterFiles(void*, bool);
    TESFile* GetMasterFile(unsigned int);
    char* GetMasterFileName(unsigned int);
    unsigned int GetMasterFileCount();
    unsigned int GetFileIndex(TESFile*);
    void ClearMasters();
    void AddMaster(char*);
    bool AddMasters(void*);
    void RemoveMaster(unsigned int);
    bool DependsOnMaster(char*);
    bool MastersChanged();
    bool CheckLODPlugins();
    void* GetMasterList();
    unsigned char GetFileCompileIndex();
    void SetCompileIndex(unsigned char);
    void AddToDataHandler();
    bool CurrentGroupMayContainForm(TESForm*);
    void GetAnimationSequence(FormRecordHeader*);
    void ClearGroupStack();
    void OpenGroup(FormRecordHeader*);
    void CloseGroup();
    bool IsFormInCurrentGroup(TESForm*);
    bool IsGroupOpen();
    void SetCurrentForm(TESForm*);
    void ResetCurrentForm();
    TESFileGroup* GetCurrentGroup();
    void* GetGroupList();
    void SetGroupMode(bool);
    void TESRewindChunk();
    bool NextForm(bool);
    bool HasNextForm();
    void RewindForm();
    int GetTESForm();
    unsigned int GetOffset();
    unsigned int GetOffsetChunk();
    bool SetOffset(unsigned int);
    bool SetOffsetChunk(unsigned int);
    int GetFormAtOffset(unsigned int);
    unsigned int CopyCurrentFormToBuffer(void*, unsigned int);
    int ReadCurrentForm();
    bool NextChunk();
    unsigned int GetChunkSize();
    bool GetChunkData(unsigned short*);
    bool GetChunkData(short*);
    bool GetChunkData(float*);
    bool GetChunkData(unsigned int*);
    bool GetChunkData(int*);
    bool GetChunkData(void*, unsigned int);
    void ClearCurrentChunk();
    bool HasMaster(char*);
    int WriteForm(TESForm*);
    int WriteFormContents(TESForm*);
    void LoadForm(TESForm*);
    int WriteChunkData(int, void*, unsigned int);
    unsigned int GetCurrentReadPosition();
    bool ForceSaveFormHeader(FormRecordHeader*, unsigned int);
    void SetMasterFile(bool);
    bool IsMasterFile();
    void SetOptimizedFile(bool);
    bool GetOptimizedFile();
    void SetChecked(bool);
    bool GetIsChecked();
    void SetAltered(bool);
    bool GetAltered();
    void SetActive(bool);
    bool GetActive();
    void SetLittleEndian(bool);
    bool GetLittleEndian();
    bool QEndian();
    void SetUnicode(bool);
    bool GetUnicode();
    bool GetHasGroups();
    void SetHasGroups(bool);
    float GetPercentage();
    void CopyToBackup();
    static void DeleteFileList(void*);
    TESFile* GetParentTESFile();
    TESFile* GetThreadSafeRootFile();
    void CopyThreadSafeParentAuxBuffer();
    void ClearAuxBuffer();
    void SetFile(BSFile*);
    BSFile* GetFile();
    int GetLastFileError();
    FormRecordHeader* GetFormData();
    unsigned int GetID();
    unsigned short GetFormVersion();
    bool TakeOwnership();
    static bool TakeFileOwnership(char*);
    static unsigned short GetFileFormVersion();
    void SetCached(bool);
    void SetCaching(bool);
    void ResetWithCachedFile();
    bool GetCached();
    bool GetCaching();
    unsigned int GetMasterCount();
    unsigned int GetFlags();
    unsigned int GetFNVVersionInfo();
    void InitEndian();
    bool IsCurrentFormCompressed();
    unsigned int GetDecompressedBufferSize();
    char* GetDecompressedBuffer();
    void ReleaseDecompressedBuffer();
    void ClearDecompressedBuffer();
    bool ReadFormHeader();
    bool ReadChunkHeader();
    void* GetMasterDataList();
    void ClearMasterLists();
    void ClearThreadSafeFiles();
    void SetThreadSafeParent(TESFile*);
    TESFile* GetFileForThread(unsigned int);
    int ReadFileBuffer(void*, unsigned int);
    void MoveToFilePosition(int);
    bool IsTempIDLoadable(unsigned int, unsigned int);
    void SetTempIDOwner(bool);
    bool GetTempIDOwner();
    static void SetTempIDOwnerForForm(unsigned int, TESFile*);
    static bool GetTempIDCanLoadFromFile(unsigned int, TESFile*);
    static TESFile* GetTempIDOwnerFile(unsigned int);
    void ClearTempIDOwner();
    void* __vecDelDtor(unsigned int);
    int m_eReturnCode;
    TESFile* m_pThreadSafeParent;
    void* m_pThreadSafeFileMap;
    BSFile* m_pSecondaryFile;
    BSFile* m_pFile;
    TESBitArrayFile* m_pBitArrayFile1;
    TESBitArrayFile* m_pBitArrayFile2;
    TESBitArrayFile* m_pBitArrayFile3;
    char m_acFilename[260];
    char m_acPath[260];
    char* m_pBuffer;
    unsigned int m_uiBufferAllocSize;
    unsigned int m_uiReadPosition;
    unsigned int m_uiBufferSize;
    TESObjectCELL* m_pCurrentCell;
    unsigned int m_uiFormCount;
    char m_kRecordInfo[24];
    int m_eChunkID;
    unsigned int m_uiChunkSize;
    unsigned int m_uiChunkOffset;
    unsigned int m_uiRecordSize;
    unsigned int m_uiRecordOffset;
    unsigned int m_uiCurrentOffset;
    char m_kChunkInfo[24];
    unsigned int m_uiChunkValue1;
    unsigned int m_uiChunkValue2;
    char m_kRecordList[8];
    bool m_bIsLoading;
    bool m_bIsSaving;
    bool m_bHasCurrentGroup;
    char _pad_29b[1];
    char m_kFindData[320];
    char m_kFileMetadata[12];
    unsigned int m_uiFileCount;
    char m_kFilenameList[8];
    char m_kFileSizeList[8];
    unsigned int m_uiTESFileCount;
    TESFile** m_ppTESFiles;
    char m_kLastWriteTime[8];
    unsigned char m_ucCompileIndex;
    char _pad_40d[3];
    char m_kCreator[8];
    char m_kSummary[8];
    char* m_pDecompressedFormBuffer;
    unsigned int m_uiAuxBufferSize;
    bool m_bIsMaster;
    bool m_bOptimizedFile;
    bool m_bIsDLC;
    char _pad_42b[1];
};
typedef char _sizecheck_TESFile[sizeof(TESFile) == 1068 ? 1 : -1];
struct FUN_006148f0_shell : public TESRace
{
    bool BuildBodyModTexturePath(TESNPC*, char*, char*);
};

int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);
int __cdecl __mbsnicmp(const char*, const char*, unsigned int);

struct TESForm_ext : public TESForm
{
    TESFile* GetOwnerMaster();
};

// @fnv 0x006148f0
bool FUN_006148f0_shell::BuildBodyModTexturePath(TESNPC* apNPC, char* apName, char* apFileName)
{
    TESNPC* pfacenpc = apNPC;
    bool bUpdate;
    if (apNPC->FUN_006044c0())
    {
        pfacenpc = apNPC->FUN_006044c0();
        while (pfacenpc && pfacenpc->FUN_006044c0())
        {
            pfacenpc = pfacenpc->FUN_006044c0();
        }
    }
    TESFile* pmaster = ((TESForm_ext*)pfacenpc)->GetOwnerMaster();
    if (!pmaster)
        return false;
    bUpdate = false;
    if (!__mbsnicmp(pmaster->GetFilename(), "update", 6))
        bUpdate = true;
    _sprintf_s(apFileName, 0x104, "data\\Textures\\Characters\\BodyMods\\%s\\%s.dds",
               !bUpdate ? pmaster->GetFilename() : "FalloutNV.ESM", apName);
    return true;
}
}  // namespace fnv_006148f0

class GlobalObject2_0040c150
{
  public:
    int* Int(void);
};

extern GlobalObject2_0040c150 g_011d5a50;

// @fnv 0x006151d0
int FUN_006151d0()
{
    return *g_011d5a50.Int();
}

// Subtracts 2 from aePart and returns the result if it is in [0,3), otherwise returns -1.
// @fnv 0x00615300
int __cdecl NormalizePartIndex(int aePart)
{
    int epart = aePart - 2;
    if (epart < 0 || epart >= 3)
        return -1;
    else
        return epart;
}

struct FUN_00610430_shell : public TESForm
{
    char* GetStringOrEmpty();
};

struct Flt_00610430
{
    char* GetStr() const;
};
// Returns the string from the Flt_00610430 object at offset 0x50c, or an empty string if it is null.
// @fnv 0x00610430
char* FUN_00610430_shell::GetStringOrEmpty()
{
    return ((Flt_00610430*)((char*)this + 0x50c))->GetStr() ? ((Flt_00610430*)((char*)this + 0x50c))->GetStr() : "";
}

struct FUN_00613100_shell
{
    char GetByteAtOffset(int offset);
};

// @fnv 0x00613100
char FUN_00613100_shell::GetByteAtOffset(int offset)
{
    return ((char*)this)[offset + 0x9c];
}

extern int DAT_0119b4e4;

// @fnv 0x00614630
int FUN_00614630()
{
    return DAT_0119b4e4;
}

extern "C" void* __cdecl _alloca(unsigned int);
extern "C" void __cdecl _security_check_cookie(unsigned int);
extern unsigned int __cdecl BSStringLength(char const*);

struct BSStr
{
    bool Set(char const*, unsigned int);
};

struct BSStringT_char
{
    int StrCmp(char const*, bool) const;
};

struct FUN_00615330_shell
{
    bool SetWeaponName(char const* aWeapon);
};

// Copies aWeapon into a stack buffer, compares it with the string at this+0x50c, and if different stores it there and returns true.
// @fnv 0x00615330
bool __thiscall FUN_00615330_shell::SetWeaponName(char const* aWeapon)
{
    unsigned int len = BSStringLength(aWeapon) + 1;
    char* buf = (char*)_alloca(len);
    TaskQueueInterface::CopyStringToBuffer(buf, len, aWeapon);
    if (((BSStringT_char*)((char*)this + 0x50c))->StrCmp(buf, true) == 0)
    {
        return false;
    }
    ((BSStr*)((char*)this + 0x50c))->Set(buf, 0);
    return true;
}

struct FUN_00610470_shell
{
    void FUN_006104c0();
    void* FUN_00610470(unsigned int);
};
void __cdecl _Deallocate(void*);
// Calls FUN_006104c0, then deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x00610470
void* FUN_00610470_shell::FUN_00610470(unsigned int flags)
{
    FUN_006104c0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct List_009e03e0
{
    void RemoveAll();
};
struct FUN_00613850_shell
{
    List_009e03e0* __thiscall FUN_0045bb80();
    void FUN_00613850();
};
// @fnv 0x00613850
void FUN_00613850_shell::FUN_00613850()
{
    FUN_0045bb80()->RemoveAll();
}

namespace fnv_00613950 {
struct List_009e03e0
{
    void RemoveAll();
};
struct FUN_00613950_shell : public TESDataHandler
{
    void* GetBGSRecipeCategoryList();
    void ClearRecipeCategoryList();
};
// @fnv 0x00613950
void FUN_00613950_shell::ClearRecipeCategoryList()
{
    ((List_009e03e0*)GetBGSRecipeCategoryList())->RemoveAll();
}
}  // namespace fnv_00613950

struct FullNameEx
{
    char _pad[12];
    void SetFullName(char const*);
};
struct Mid
{
    FullNameEx arr[8];
};
struct Obj
{
    char _pad[0x230];
    Mid m[3];
    void FUN_00613b60(int, int, char const*);
};
// Bounds-checks a (0-2) and b (0-7), then calls SetFullName on m[a].arr[b] with the given string.
// @fnv 0x00613b60
void Obj::FUN_00613b60(int a, int aiIndex, char const* apName)
{
    if (aiIndex < 0 || aiIndex >= 8 || a < 0 || a > 2)
        return;
    m[a].arr[aiIndex].SetFullName(apName);
}

namespace fnv_00613c00 {
struct FullNameEx
{
    void SetFullName(const char*);
};
struct FUN_00613c00_shell
{
    FullNameEx m[3];
    void FUN_00613c00(int a, int b, const char* c);
};
// @fnv 0x00613c00
void FUN_00613c00_shell::FUN_00613c00(int aiIndex, int aiSubIndex, const char* apName)
{
    if (aiIndex < 0 || aiIndex >= 2 || aiSubIndex < 0 || aiSubIndex >= 3)
        return;
    ((FullNameEx*)((char*)this + 0x2f0) + aiIndex * 36 + aiSubIndex * 12)->SetFullName(apName);
}
}  // namespace fnv_00613c00

extern double _gModifierZero;
struct Holder00613120
{
    unsigned char _pad[0xA0];
    float f0xA0;
    float FUN_00613120();
};
// Returns f0xA0 when it is greater than _gModifierZero, otherwise returns 5.0f.
// @fnv 0x00613120
float Holder00613120::FUN_00613120()
{
    return f0xA0 > _gModifierZero ? f0xA0 : 5.0f;
}

extern double _gModifierZero;
struct S00613160
{
    unsigned char _pad[0xA4];
    float fieldA4;
    float GetFieldA4OrDefault();
};
// Returns fieldA4 if it is greater than _gModifierZero, otherwise returns 3.0f.
// @fnv 0x00613160
float S00613160::GetFieldA4OrDefault()
{
    return fieldA4 > _gModifierZero ? fieldA4 : 3.0f;
}

struct FUN_Elem12
{
    int f0;
    int f1;
    int f2;
};
struct FUN_Row36
{
    FUN_Elem12 e[3];
};
struct FUN_00613bb0_shell
{
    char _pad[0x2F0];
    FUN_Row36 m[2];
    FUN_Elem12* FUN_00613bb0(int a, int b);
};
// Returns a pointer to element e[b] of row m[a] when a is in [0,2) and b in [0,3), otherwise returns null.
// @fnv 0x00613bb0
FUN_Elem12* FUN_00613bb0_shell::FUN_00613bb0(int aiRow, int aiColumn)
{
    if (aiRow < 0 || aiRow >= 2 || aiColumn < 0 || aiColumn >= 3)
        return 0;
    return &m[aiRow].e[aiColumn];
}

struct RaceCleanup : TESRace
{
    void FUN_00613850();
    void ClearRecipeCategoryList();
    void FUN_00610ac0();
};
// @fnv 0x00610ac0
void RaceCleanup::FUN_00610ac0()
{
    FUN_00613850();
    ClearRecipeCategoryList();
    unsigned int uiOuterIndex, i;
    for (uiOuterIndex = 0; uiOuterIndex < 2; ++uiOuterIndex)
    {
        for (i = 0; i < 8; ++i)
        {
            m_kBodyPartModels[uiOuterIndex][i].Free();
            m_kBodyPartTextures[uiOuterIndex][i].Free();
        }
    }
    for (uiOuterIndex = 0; uiOuterIndex < 2; ++uiOuterIndex)
    {
        for (i = 0; i < 3; ++i)
        {
            m_kHeadPartTextures[uiOuterIndex][i].Free();
            m_kHeadPartModels[uiOuterIndex][i].Free();
        }
        m_kFaceGenTextureModels[uiOuterIndex].Free();
    }
}

struct FlagBox_cls
{
    bool v;
};
struct FUN_00611db0_cls
{
    char unk00[0x10];
    int m_10[2];
    int m_18[2];
    int m_20;

    void FUN_00611db0();
};

void __cdecl FUN_00401080(void* item, bool flag);

// @fnv 0x00611db0
void FUN_00611db0_cls::FUN_00611db0()
{
    for (int i = 0; i < 2; i++)
    {
        FlagBox_cls a = {};
        FUN_00401080(&m_10[i], a.v);
        FlagBox_cls b = {};
        FUN_00401080(&m_18[i], b.v);
    }
    {
        FlagBox_cls c = {};
        FUN_00401080(&m_20, c.v);
    }
}

struct SkillBonusEntry
{
    char m_eWeaponSkill;
    char m_cBonus;
};
struct TextureNameHolder
{
    const char* GetName();
};
struct AttributeSource;

struct RaceAccess : public TESRace
{
    BGSVoiceType* GetVoice(int aiSex);
    TESHair* GetHair(int aiSex);
    char GetHairColor(int aiSex);
    float GetClamp();
    float GetClamp2();
    BaseFormComponent* GetMaleAttributes();
    BaseFormComponent* GetFemaleAttributes();
    SkillBonusEntry* GetSkillBonus(unsigned int auiIndex);
    float GetHeight(int aiSex);
    float GetWeight(int aiSex);
    int GetFlags();
    TESModel* GetHeadModel(unsigned int auiSex, unsigned int auiPart);
    TextureNameHolder* GetHeadTexture(unsigned int auiSex, unsigned int auiPart);
    TextureNameHolder* GetBodyTextureHolder(unsigned int auiSex, unsigned int auiPart);
    TESModel* GetBodyModel(unsigned int auiSex, unsigned int auiPart);
    TESModel* GetBodyTexModel(unsigned int auiSex);
    BSSimpleList<TESHair*>* GetHairList();
    BSSimpleList<TESEyes*>* GetEyeList();
    unsigned short GetFaceCoordNum();
    void SetHeadModel(unsigned int auiSex, unsigned int auiPart, const char* apName);
    void SetHeadTexture(unsigned int auiSex, unsigned int auiPart, const char* apName);
    void SetBodyTexture(unsigned int auiSex, unsigned int auiPart, const char* apName);
    void SetBodyModel(unsigned int auiSex, unsigned int auiPart, const char* apName);
    void SetBodyTexModel(unsigned int auiSex, const char* apName);
    void ClearHairList();
    void ClearEyeList();
};

struct FUN_00612c90_cls : public RaceAccess
{
    void CopyFromRace(TESForm* apSource);
};

// Copies voice, hair, attributes, skill bonuses, models, textures, hair/eye lists and face data from another TESRace into this race.
// @fnv 0x00612c90
void FUN_00612c90_cls::CopyFromRace(TESForm* apSource)
{
    BSSimpleList<TESEyes*>* pEyes;
    RaceAccess* pRace3;
    BSSimpleList<TESHair*>* _pHair;
    unsigned int i;
    int j3;
    unsigned int uiSexB;
    unsigned int uiPartA;
    unsigned int uiSex4;
    unsigned int uiPart2;
    unsigned int uiPart8;

    pRace3 = (RaceAccess*)dynamic_cast<TESRace*>(apSource);
    if (pRace3 == 0)
    {
        return;
    }
    TESForm::CopyFrom(apSource);
    m_pOlderRace = pRace3->m_pOlderRace;
    m_pYoungerRace = pRace3->m_pYoungerRace;
    m_apDefaultVoiceTypes[0] = pRace3->GetVoice(0);
    m_apDefaultVoiceTypes[1] = pRace3->GetVoice(1);
    m_apDefaultHairStyles[0] = pRace3->GetHair(0);
    m_apDefaultHairStyles[1] = pRace3->GetHair(1);
    m_acDefaultHairColors[0] = pRace3->GetHairColor(0);
    m_acDefaultHairColors[1] = pRace3->GetHairColor(1);
    m_fFaceGenMainClamp = pRace3->GetClamp();
    m_fFaceGenFaceClamp = pRace3->GetClamp2();
    m_kMaleAttributes.CopyFromBase(pRace3->GetMaleAttributes());
    m_kFemaleAttributes.CopyFromBase(pRace3->GetFemaleAttributes());
    for (i = 0; i < 7; i++)
    {
        Data.m_kSkillBonuses[i].m_eWeaponSkill = pRace3->GetSkillBonus(i)->m_eWeaponSkill;
        Data.m_kSkillBonuses[i].m_cBonus = pRace3->GetSkillBonus(i)->m_cBonus;
    }
    for (j3 = 0; j3 < 2; j3++)
    {
        Data.m_fGlyphExtent[j3] = pRace3->GetHeight(j3);
        Data.fWeight[j3] = pRace3->GetWeight(j3);
    }
    Data.iFlags = pRace3->GetFlags();
    for (uiSexB = 0; uiSexB < 2; uiSexB++)
    {
        for (uiPartA = 0; uiPartA < 8; uiPartA++)
        {
            SetHeadModel(uiSexB, uiPartA, pRace3->GetHeadModel(uiSexB, uiPartA)->GetModelFilePath());
            SetHeadTexture(uiSexB, uiPartA, pRace3->GetHeadTexture(uiSexB, uiPartA)->GetName());
        }
    }
    for (uiSex4 = 0; uiSex4 < 2; uiSex4++)
    {
        for (uiPart2 = 0; uiPart2 < 3; uiPart2++)
        {
            SetBodyTexture(uiSex4, uiPart2, pRace3->GetBodyTextureHolder(uiSex4, uiPart2)->GetName());
        }
        for (uiPart8 = 0; uiPart8 < 3; uiPart8++)
        {
            SetBodyModel(uiSex4, uiPart8, pRace3->GetBodyModel(uiSex4, uiPart8)->GetModelFilePath());
        }
        SetBodyTexModel(uiSex4, pRace3->GetBodyTexModel(uiSex4)->GetModelFilePath());
    }
    _pHair = pRace3->GetHairList();
    ClearHairList();
    while (_pHair != 0 && _pHair->GetItem() != 0)
    {
        GetHairList()->AddTail(_pHair->GetItem());
        _pHair = _pHair->GetNext();
    }
    pEyes = pRace3->GetEyeList();
    ClearEyeList();
    while (pEyes != 0 && pEyes->GetItem() != 0)
    {
        GetEyeList()->AddTail(pEyes->GetItem());
        pEyes = pEyes->GetNext();
    }
    BSFaceGenManager::CopyFaceGenCoordinates(pRace3->GetMeanFaceCoord(SEX_SEX_MALE), GetMeanFaceCoord(SEX_SEX_MALE),
                                             false, false);
    BSFaceGenManager::CopyFaceGenCoordinates(pRace3->GetMeanFaceCoord(SEX_SEX_FEMALE), GetMeanFaceCoord(SEX_SEX_FEMALE),
                                             false, false);
    m_usRaceAttribute = pRace3->GetFaceCoordNum();
}

struct FUN_006139b0_elem
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06(int c);
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
};

class FUN_006139b0_cls
{
  public:
    char unk00[0xb0];
    FUN_006139b0_elem m_pElements[2][8];
    void CallElementVirtual(int a, int b, int c);
};

// @fnv 0x006139b0
void FUN_006139b0_cls::CallElementVirtual(int aiRow, int aiColumn, int c)
{
    if (aiColumn < 0 || aiColumn >= 8 || aiRow < 0 || aiRow >= 2)
    {
    }
    else
    {
        m_pElements[aiRow][aiColumn].v06(c);
    }
}

struct S_00613ad0_Base
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6(int);
};

void S_00613ad0_Base::V0()
{}
void S_00613ad0_Base::V1()
{}
void S_00613ad0_Base::V2()
{}
void S_00613ad0_Base::V3()
{}
void S_00613ad0_Base::V4()
{}
void S_00613ad0_Base::V5()
{}
void S_00613ad0_Base::V6(int)
{}

struct S_00613ad0_Element : public S_00613ad0_Base
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};

struct S_00613ad0_Class
{
    double unk000;
    double unk008;
    double unk010;
    double unk018;
    double unk020;
    double unk028;
    double unk030;
    double unk038;
    double unk040;
    double unk048;
    double unk050;
    double unk058;
    double unk060;
    double unk068;
    double unk070;
    double unk078;
    double unk080;
    double unk088;
    double unk090;
    double unk098;
    double unk0a0;
    double unk0a8;
    double unk0b0;
    double unk0b8;
    double unk0c0;
    double unk0c8;
    double unk0d0;
    double unk0d8;
    double unk0e0;
    double unk0e8;
    double unk0f0;
    double unk0f8;
    double unk100;
    double unk108;
    double unk110;
    double unk118;
    double unk120;
    double unk128;
    double unk130;
    double unk138;
    double unk140;
    double unk148;
    double unk150;
    double unk158;
    double unk160;
    double unk168;
    double unk170;
    double unk178;
    double unk180;
    double unk188;
    double unk190;
    double unk198;
    double unk1a0;
    double unk1a8;
    double unk1b0;
    double unk1b8;
    double unk1c0;
    double unk1c8;
    double unk1d0;
    double unk1d8;
    double unk1e0;
    double unk1e8;
    double unk1f0;
    double unk1f8;
    double unk200;
    double unk208;
    double unk210;
    double unk218;
    double unk220;
    double unk228;
    double unk230;
    double unk238;
    double unk240;
    double unk248;
    double unk250;
    double unk258;
    double unk260;
    double unk268;
    double unk270;
    double unk278;
    double unk280;
    double unk288;
    double unk290;
    double unk298;
    double unk2a0;
    double unk2a8;
    double unk2b0;
    double unk2b8;
    double unk2c0;
    double unk2c8;
    double unk2d0;
    double unk2d8;
    double unk2e0;
    double unk2e8;
    double unk2f0;
    double unk2f8;
    double unk300;
    double unk308;
    double unk310;
    double unk318;
    double unk320;
    double unk328;
    double unk330;
    double unk338;
    double unk340;
    double unk348;
    double unk350;
    double unk358;
    double unk360;
    double unk368;
    double unk370;
    double unk378;
    double unk380;
    double unk388;
    double unk390;
    double unk398;
    double unk3a0;
    double unk3a8;
    double unk3b0;
    double unk3b8;
    int unk3c0;
    int unk3c4;

    S_00613ad0_Element m[2];

    void __thiscall DispatchToElement(int, int);
};

// Bounds-checks a against the two-element array m and, if valid, calls the element's virtual V6 with b.
// @fnv 0x00613ad0
void __thiscall S_00613ad0_Class::DispatchToElement(int aiIndex, int b)
{
    if (aiIndex < 0 || aiIndex >= 2)
        return;

    m[aiIndex].V6(b);
}

void* __cdecl memset(void*, int, unsigned int);
extern BGSVoiceType* DAT_011cb298;
extern BGSVoiceType* DAT_011cb29c;
extern const char* DAT_01199fe8[2][8];
extern const char* DAT_0119a028[2][8];
extern const char* DAT_0119a068[2][3];
extern const char* DAT_0119a080[2][3];
extern const char* DAT_01199fbc[2];
void* __cdecl GetDefaultCoords();
void __cdecl ResetCoords(void*);
void __cdecl CopyCoords(void*, void*, int, int);
struct TextureAccess : TESTexture
{
    void SetFullName(const char*);
};
struct RaceReset : TESRace
{
    void* GetCoords(int);
    void ResetRaceData();
};
// @fnv 0x006106a0
void RaceReset::ResetRaceData()
{
    unsigned int index, sex, part;
    memset(&Data, 0, 0x24);
    for (index = 0; index < 7; index++)
        Data.m_kSkillBonuses[index].m_eWeaponSkill = -1;
    for (index = 0; index < 2; index++)
    {
        Data.fWeight[index] = 1.0f;
        Data.m_fGlyphExtent[index] = 1.0f;
    }
    m_apDefaultHairStyles[0] = 0;
    m_apDefaultHairStyles[1] = 0;
    m_apDefaultVoiceTypes[0] = DAT_011cb298;
    m_apDefaultVoiceTypes[1] = DAT_011cb29c;
    m_fFaceGenMainClamp = 0.0f;
    m_fFaceGenFaceClamp = 0.0f;
    m_acDefaultHairColors[0] = 0;
    m_acDefaultHairColors[1] = 0;
    CopyCoords(GetDefaultCoords(), GetCoords(0), 0, 0);
    ResetCoords(GetCoords(0));
    CopyCoords(GetDefaultCoords(), GetCoords(1), 0, 0);
    ResetCoords(GetCoords(1));
    m_usRaceAttribute = 0;
    for (sex = 0; sex < 2; sex++)
    {
        for (part = 0; part < 8; part++)
        {
            m_kBodyPartModels[sex][part].Init();
            m_kBodyPartModels[sex][part].SetModelFilePath(DAT_01199fe8[sex][part]);
            m_kBodyPartTextures[sex][part].Init();
            ((TextureAccess*)&m_kBodyPartTextures[sex][part])->SetFullName(DAT_0119a028[sex][part]);
        }
    }
    for (sex = 0; sex < 2; sex++)
    {
        for (part = 0; part < 3; part++)
        {
            m_kHeadPartTextures[sex][part].Init();
            ((TextureAccess*)&m_kHeadPartTextures[sex][part])->SetFullName(DAT_0119a068[sex][part]);
            m_kHeadPartModels[sex][part].Init();
            m_kHeadPartModels[sex][part].SetModelFilePath(DAT_0119a080[sex][part]);
        }
        m_kFaceGenTextureModels[sex].Init();
        m_kFaceGenTextureModels[sex].SetModelFilePath(DAT_01199fbc[sex]);
    }
    m_pOlderRace = 0;
    m_pYoungerRace = 0;
}

extern "C" void* __cdecl _alloca(unsigned int);
bool __cdecl FUN_00401500();
void __cdecl FUN_004856d0(unsigned int);
void __cdecl FUN_004856f0(unsigned int, const void*, unsigned int);
void __cdecl FUN_00485710(unsigned int, const void*, unsigned int);
void __cdecl FUN_00485910(unsigned int, unsigned int);
void __cdecl FUN_00485910(unsigned int, float);
void __cdecl FUN_00485950(unsigned int, unsigned short);
void* __cdecl FormHeap_Allocate(unsigned int);
void __cdecl FormHeap_Free(void*);
void* __cdecl FUN_00403d30(void*, int, unsigned int);
struct SaveComponent611e50
{
    void FUN_00487010();
    void FUN_00482cb0();
    void FUN_0048d330();
    void WriteCameraShotList();
    void FUN_00611db0();
    unsigned int FUN_009d2510();
    void FUN_00480100(void*);
    void WriteToBuffer(unsigned int, unsigned int);
    void FUN_00489240(unsigned int);
    void FUN_0048e370(unsigned int);
};
struct SaveForm611e50
{
    unsigned int FUN_0084e3a0();
};
struct SaveList611e50
{
    unsigned int FUN_005ae380();
    SaveForm611e50** FUN_006815c0();
    SaveList611e50* FUN_00726070();
};
struct FaceValue611e50
{
    int unk00, unk04;
    float* FUN_00629ab0();
};
struct FaceMatrix611e50
{
    unsigned int FUN_009611e0();
    FaceValue611e50 FUN_0060b370(unsigned int, int);
};
struct SaveRace611e50
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    int unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    RaceDefinitionData Data;
    TESAttributes m_kMaleAttributes, m_kFemaleAttributes;
    BSSimpleList<TESHair*> m_kHairList;
    TESHair* m_apDefaultHairStyles[2];
    unsigned char m_acDefaultHairColors[2];
    float m_fFaceGenMainClamp, m_fFaceGenFaceClamp;
    BSSimpleList<TESEyes*> m_kEyeList;
    TESModel m_kBodyPartModels[2][8];
    TESTexture m_kBodyPartTextures[2][8];
    TESTexture m_kHeadPartTextures[2][3];
    TESModel m_kHeadPartModels[2][3];
    BGSTextureModel m_kFaceGenTextureModels[2];
    FaceGenMatrix<float> m_kFirstFloatPairBySex[2][2], m_kSecondFloatPairBySex[2][2];
    unsigned short m_usRaceAttribute;
    BGSVoiceType* m_apDefaultVoiceTypes[2];
    TESRace* m_pOlderRace;
    TESRace* m_pYoungerRace;
    void FUN_004855a0();
    void FUN_00485e20(void*, unsigned int);
    void FUN_00485680();
    SaveList611e50* FUN_0045bb80();
    SaveList611e50* FUN_00503650();
    void SaveRace();
};
// @fnv 0x00611e50
void SaveRace611e50::SaveRace()
{
    FUN_004855a0();
    ((SaveComponent611e50*)&unk18)->FUN_00487010();
    ((SaveComponent611e50*)&unk24)->FUN_00482cb0();
    ((SaveComponent611e50*)&unk2c)->FUN_0048d330();
    ((SaveComponent611e50*)&unk40)->WriteCameraShotList();
    if (FUN_00401500())
        ((SaveComponent611e50*)&Data)->FUN_00611db0();
    FUN_00485e20(&Data, 0x24);
    if (FUN_00401500())
        ((SaveComponent611e50*)&Data)->FUN_00611db0();
    unsigned int formid51 = 0;
    if (m_pOlderRace)
    {
        formid51 = ((SaveForm611e50*)m_pOlderRace)->FUN_0084e3a0();
        FUN_00485910(0x4d414e4f, formid51);
    }
    if (m_pYoungerRace)
    {
        formid51 = ((SaveForm611e50*)m_pYoungerRace)->FUN_0084e3a0();
        FUN_00485910(0x4d414e59, formid51);
    }
    FUN_004856d0(0x324d414e);
    if (m_apDefaultVoiceTypes[0] || m_apDefaultVoiceTypes[1])
    {
        unsigned int voiceids[2];
        for (int voiceindex = 0; voiceindex < 2; voiceindex++)
        {
            if (m_apDefaultVoiceTypes[voiceindex])
                voiceids[voiceindex] = ((SaveForm611e50*)m_apDefaultVoiceTypes[voiceindex])->FUN_0084e3a0();
            else
                voiceids[voiceindex] = 0;
        }
        FUN_00485710(0x4b435456, voiceids, 2);
    }
    if (m_apDefaultHairStyles[0] || m_apDefaultHairStyles[1])
    {
        unsigned int hairids[2];
        for (int hairindex = 0; hairindex < 2; hairindex++)
        {
            if (m_apDefaultHairStyles[hairindex])
                hairids[hairindex] = ((SaveForm611e50*)m_apDefaultHairStyles[hairindex])->FUN_0084e3a0();
            else
                hairids[hairindex] = 0;
        }
        FUN_00485710(0x4d414e44, hairids, 2);
    }
    FUN_004856f0(0x4d414e43, m_acDefaultHairColors, 2);
    FUN_00485910(0x4d414e50, m_fFaceGenMainClamp);
    FUN_00485910(0x4d414e55, m_fFaceGenFaceClamp);
    unsigned int attributeSize72 = ((SaveComponent611e50*)&m_kMaleAttributes)->FUN_009d2510();
    char* attributeData20 = (char*)_alloca(attributeSize72 * 2);
    ((SaveComponent611e50*)&m_kMaleAttributes)->FUN_00480100(attributeData20);
    ((SaveComponent611e50*)&m_kFemaleAttributes)->FUN_00480100(attributeData20 + attributeSize72);
    FUN_004856f0(0x52545441, attributeData20, 2);
    FUN_004856d0(0x304d414e);
    unsigned int sex3, part2;
    for (sex3 = 0; sex3 < 2; sex3++)
    {
        if (sex3 == 0)
            FUN_004856d0(0x4d414e4d);
        else if (sex3 == 1)
            FUN_004856d0(0x4d414e46);
        for (part2 = 0; part2 < 8; part2++)
        {
            FUN_00485910(0x58444e49, part2);
            ((SaveComponent611e50*)&m_kBodyPartModels[sex3][part2])->WriteToBuffer(0x4c444f4d, 0x54444f4d);
            ((SaveComponent611e50*)&m_kBodyPartModels[sex3][part2])->FUN_00489240(0x44444f4d);
            ((SaveComponent611e50*)&m_kBodyPartTextures[sex3][part2])->FUN_0048e370(0x4e4f4349);
        }
    }
    FUN_004856d0(0x314d414e);
    for (sex3 = 0; sex3 < 2; sex3++)
    {
        if (sex3 == 0)
            FUN_004856d0(0x4d414e4d);
        else if (sex3 == 1)
            FUN_004856d0(0x4d414e46);
        for (part2 = 0; part2 < 3; part2++)
        {
            FUN_00485910(0x58444e49, part2);
            ((SaveComponent611e50*)&m_kHeadPartTextures[sex3][part2])->FUN_0048e370(0x4e4f4349);
            ((SaveComponent611e50*)&m_kHeadPartModels[sex3][part2])->WriteToBuffer(0x4c444f4d, 0x54444f4d);
            ((SaveComponent611e50*)&m_kHeadPartModels[sex3][part2])->FUN_00489240(0x44444f4d);
        }
        FUN_00485910(0x58444e49, part2);
        ((SaveComponent611e50*)&m_kFaceGenTextureModels[sex3])->WriteToBuffer(0x4c444f4d, 0x54444f4d);
    }
    {
        SaveList611e50* hairlist7 = FUN_0045bb80();
        unsigned int hairposition7 = 0;
        unsigned int haircount2 = hairlist7->FUN_005ae380();
        unsigned int* hairdata1 = new unsigned int[haircount2];
        while (hairlist7 && *hairlist7->FUN_006815c0())
        {
            hairdata1[hairposition7] = (*hairlist7->FUN_006815c0())->FUN_0084e3a0();
            hairposition7++;
            hairlist7 = hairlist7->FUN_00726070();
        }
        FUN_00485710(0x4d414e48, hairdata1, haircount2);
        delete[] hairdata1;
    }
    {
        SaveList611e50* eyelist45 = FUN_00503650();
        unsigned int eyeposition15 = 0;
        unsigned int eyecount20 = eyelist45->FUN_005ae380();
        unsigned int* eyedata3 = new unsigned int[eyecount20];
        while (eyelist45 && *eyelist45->FUN_006815c0())
        {
            eyedata3[eyeposition15] = (*eyelist45->FUN_006815c0())->FUN_0084e3a0();
            eyeposition15++;
            eyelist45 = eyelist45->FUN_00726070();
        }
        FUN_00485710(0x4d414e45, eyedata3, eyecount20);
        delete[] eyedata3;
    }
    for (sex3 = 0; sex3 < 2; sex3++)
    {
        if (sex3 == 0)
            FUN_004856d0(0x4d414e4d);
        else if (sex3 == 1)
            FUN_004856d0(0x4d414e46);
        unsigned int count = 0;
        if (sex3 == 0)
            count = ((FaceMatrix611e50*)&m_kSecondFloatPairBySex[0][0])->FUN_009611e0();
        else if (sex3 == 1)
            count = ((FaceMatrix611e50*)&m_kFirstFloatPairBySex[0][0])->FUN_009611e0();
        if (count)
        {
            unsigned int geometrybytes31 = count * 4;
            float* geometrydata18 = (float*)FormHeap_Allocate(geometrybytes31);
            FUN_00403d30(geometrydata18, 0, geometrybytes31);
            for (unsigned int geometryindex = 0; geometryindex < count; geometryindex++)
            {
                if (sex3 == 0)
                    geometrydata18[geometryindex] = *((FaceMatrix611e50*)&m_kSecondFloatPairBySex[0][0])
                                                         ->FUN_0060b370(geometryindex, 0)
                                                         .FUN_00629ab0();
                else if (sex3 == 1)
                    geometrydata18[geometryindex] = *((FaceMatrix611e50*)&m_kFirstFloatPairBySex[0][0])
                                                         ->FUN_0060b370(geometryindex, 0)
                                                         .FUN_00629ab0();
            }
            FUN_00485710(0x53474746, geometrydata18, count);
            FormHeap_Free(geometrydata18);
            geometrydata18 = 0;
        }
        if (sex3 == 0)
            count = ((FaceMatrix611e50*)&m_kSecondFloatPairBySex[0][1])->FUN_009611e0();
        else if (sex3 == 1)
            count = ((FaceMatrix611e50*)&m_kFirstFloatPairBySex[0][1])->FUN_009611e0();
        if (count)
        {
            unsigned int asymmetrybytes4 = count * 4;
            float* asymmetrydata24 = (float*)FormHeap_Allocate(asymmetrybytes4);
            FUN_00403d30(asymmetrydata24, 0, asymmetrybytes4);
            for (unsigned int asymmetryindex = 0; asymmetryindex < count; asymmetryindex++)
            {
                if (sex3 == 0)
                    asymmetrydata24[asymmetryindex] = *((FaceMatrix611e50*)&m_kSecondFloatPairBySex[0][1])
                                                           ->FUN_0060b370(asymmetryindex, 0)
                                                           .FUN_00629ab0();
                else if (sex3 == 1)
                    asymmetrydata24[asymmetryindex] = *((FaceMatrix611e50*)&m_kFirstFloatPairBySex[0][1])
                                                           ->FUN_0060b370(asymmetryindex, 0)
                                                           .FUN_00629ab0();
            }
            FUN_00485710(0x41474746, asymmetrydata24, count);
            FormHeap_Free(asymmetrydata24);
            asymmetrydata24 = 0;
        }
        if (sex3 == 0)
            count = ((FaceMatrix611e50*)&m_kSecondFloatPairBySex[1][0])->FUN_009611e0();
        else if (sex3 == 1)
            count = ((FaceMatrix611e50*)&m_kFirstFloatPairBySex[1][0])->FUN_009611e0();
        if (count)
        {
            unsigned int texturebytes2 = count * 4;
            float* texturedata16 = (float*)FormHeap_Allocate(texturebytes2);
            FUN_00403d30(texturedata16, 0, texturebytes2);
            for (unsigned int textureindex = 0; textureindex < count; textureindex++)
            {
                if (sex3 == 0)
                    texturedata16[textureindex] = *((FaceMatrix611e50*)&m_kSecondFloatPairBySex[1][0])
                                                       ->FUN_0060b370(textureindex, 0)
                                                       .FUN_00629ab0();
                else if (sex3 == 1)
                    texturedata16[textureindex] = *((FaceMatrix611e50*)&m_kFirstFloatPairBySex[1][0])
                                                       ->FUN_0060b370(textureindex, 0)
                                                       .FUN_00629ab0();
            }
            FUN_00485710(0x53544746, texturedata16, count);
            FormHeap_Free(texturedata16);
            texturedata16 = 0;
        }
        FUN_00485950(0x4d414e53, m_usRaceAttribute);
    }
    FUN_00485680();
}

struct RaceListItem
{
    const char* FUN_0084e3a0();
};
struct RaceList
{
    unsigned FUN_005ae380();
    RaceListItem*& FUN_006815c0();
    RaceList* FUN_00726070();
};
struct RaceComparer : TESRace
{
    bool IsDifferentFrom(TESForm*);
    bool FUN_00485270(RaceComparer*);
    RaceDefinitionData* FUN_00613790();
    TESHair* FUN_00604780(unsigned);
    TESEyes* FUN_00613870(unsigned);
    char GetByteAtOffset(unsigned);
    float FUN_00613120();
    float GetFieldA4OrDefault();
    TESAttributes* FUN_004fadc0();
    TESAttributes* FUN_006130e0();
    TESModel* FUN_00613970(unsigned, unsigned);
    TESTexture* GetBodyPartTexture(unsigned, unsigned);
    RaceList* FUN_0045bb80();
    RaceList* FUN_00503650();
    int FindByKey(const char*);
    int FindRecipeCategoryById(const char*);
    BGSVoiceType* FUN_005d9fb0(unsigned);
    unsigned short FUN_00607350();
};
int FUN_00ec4835(const void*, const void*, unsigned);
bool FUN_00652900(BGSVoiceType*, BGSVoiceType*);
unsigned short FUN_00487f50();
// Compares this race against another TESRace field by field and returns true as soon as any difference is found.
// @fnv 0x006131c0
bool RaceComparer::IsDifferentFrom(TESForm* form)
{
    RaceComparer* pOtherRace = (RaceComparer*)dynamic_cast<TESRace*>(form);
    if (!pOtherRace)
        return true;
    if (FUN_00485270(pOtherRace))
        return true;
    if (FUN_00ec4835(&Data, pOtherRace->FUN_00613790(), 36))
        return true;
    if (m_pOlderRace != pOtherRace->m_pOlderRace)
        return true;
    if (m_pYoungerRace != pOtherRace->m_pYoungerRace)
        return true;
    if (FUN_00604780(0) != pOtherRace->FUN_00604780(0))
        return true;
    if (FUN_00604780(1) != pOtherRace->FUN_00604780(1))
        return true;
    if (FUN_00613870(0) != pOtherRace->FUN_00613870(0))
        return true;
    if (FUN_00613870(1) != pOtherRace->FUN_00613870(1))
        return true;
    if (GetByteAtOffset(0) != pOtherRace->GetByteAtOffset(0))
        return true;
    if (GetByteAtOffset(1) != pOtherRace->GetByteAtOffset(1))
        return true;
    if (FUN_00613120() != pOtherRace->FUN_00613120())
        return true;
    if (GetFieldA4OrDefault() != pOtherRace->GetFieldA4OrDefault())
        return true;
    if (m_kMaleAttributes.CompareWithBase(pOtherRace->FUN_004fadc0()))
        return true;
    if (m_kFemaleAttributes.CompareWithBase(pOtherRace->FUN_006130e0()))
        return true;
    for (unsigned uiSex = 0; uiSex < 2; ++uiSex)
    {
        for (unsigned part = 0; part < 8; ++part)
        {
            if (m_kBodyPartModels[uiSex][part].CompareWithBase(pOtherRace->FUN_00613970(uiSex, part)) ||
                m_kBodyPartTextures[uiSex][part].CompareWithBase(pOtherRace->GetBodyPartTexture(uiSex, part)))
                return true;
        }
    }
    for (unsigned uiBodySex = 0; uiBodySex < 2; ++uiBodySex)
    {
        for (unsigned part = 0; part < 3; ++part)
        {
            if (m_kHeadPartTextures[uiBodySex][part].CompareWithBase(&pOtherRace->m_kHeadPartTextures[uiBodySex][part]))
                return true;
            if (m_kHeadPartModels[uiBodySex][part].CompareWithBase(&pOtherRace->m_kHeadPartModels[uiBodySex][part]))
                return true;
        }
        if (m_kFaceGenTextureModels[uiBodySex].CompareWithBase(&pOtherRace->m_kFaceGenTextureModels[uiBodySex]))
            return true;
    }
    {
        RaceList* hair = pOtherRace->FUN_0045bb80();
        if (FUN_0045bb80()->FUN_005ae380() != hair->FUN_005ae380())
            return true;
        while (hair && hair->FUN_006815c0())
        {
            if (!FindByKey(hair->FUN_006815c0()->FUN_0084e3a0()))
                return true;
            hair = hair->FUN_00726070();
        }
    }
    {
        RaceList* pEyesList = pOtherRace->FUN_00503650();
        if (FUN_00503650()->FUN_005ae380() != pEyesList->FUN_005ae380())
            return true;
        while (pEyesList && pEyesList->FUN_006815c0())
        {
            if (!FindRecipeCategoryById(pEyesList->FUN_006815c0()->FUN_0084e3a0()))
                return true;
            pEyesList = pEyesList->FUN_00726070();
        }
    }
    if (FUN_00652900(pOtherRace->FUN_005d9fb0(0), FUN_005d9fb0(0)))
    {
        m_usRaceAttribute = FUN_00487f50();
        return true;
    }
    if (FUN_00652900(pOtherRace->FUN_005d9fb0(1), FUN_005d9fb0(1)))
    {
        m_usRaceAttribute = FUN_00487f50();
        return true;
    }
    if (FUN_00607350() != pOtherRace->FUN_00607350())
        return true;
    return false;
}

// Forward a value to one cell of the 2x3 slot grid (ignored when out of range).

class D3A60Slot
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void SetValue(int iValue);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class D3A60Grid
{
  public:
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
    D3A60Slot m_aakSlots[2][3];

    void SetSlotValue(int iRow, int iColumn, int iValue);
};

// Bounds-checks iRow against 2 and iColumn against 3, then calls SetValue(iValue) on the addressed slot.
// @fnv 0x00613a60
void D3A60Grid::SetSlotValue(int iRow, int iColumn, int iValue)
{
    if (iColumn < 0 || iColumn >= 3 || iRow < 0 || iRow >= 2)
        return;
    m_aakSlots[iRow][iColumn].SetValue(iValue);
}

namespace RaceAppearance {
struct NPC;
struct Output;
struct Part;
struct List;
struct Name
{
    const char* FUN_00408da0();
};
struct Part
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    Name name;
    List* FUN_00624700();
};
struct List
{
    bool FUN_008256d0();
    Part** FUN_006815c0();
    List* FUN_00726070();
};
struct Hair
{
    bool IsHairValidForNPC(NPC*);
};
struct String
{
    void* value;
    String(int);
    ~String();
};
struct Array
{
    unsigned int unk0, unk4, unk8, unkc;
    void FUN_0096a610(void* const&);
    void FUN_0060ba10(const String&);
};
struct Parts
{
    void FUN_005ae3d0(Part* const&);
};
struct Output
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
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
    Hair* hair;
    int color;
    float length;
    Part* eyes;
    int sex;
    Array models, textures, slots, strings;
    unsigned char enabled, player, unkd6, unkd7;
    void* mouth;
    void* teeth;
    int texture;
    Parts parts;
};
struct NPC
{
    void FUN_00603ad0(Output*);
    int FUN_005f0cc0();
    Hair* FUN_00603b50();
    float FUN_00602130();
    int FUN_004169d0();
    Part* FUN_00602150();
    void CreatePartTexture(unsigned int, String&);
    List* FUN_00602170();
};
struct Player
{
    NPC* FUN_007af430();
    bool FUN_006047a0();
};
extern Player* DAT_011dea3c;
struct Setting
{
    bool* FUN_00408d60();
};
extern Setting DAT_011cb99c;
struct Data
{
    List* FUN_0043c490();
};
extern Data* DAT_011c3f2c;
void* FUN_006521e0();
void FUN_006529a0(void*, Output*, int, int);
void* FUN_00605d40(unsigned int);
int FUN_00614630();
int FUN_00404dc0(const char*, const char*);
extern const char DAT_0104b8a0[];
struct Race
{
    void* FUN_005d9fb0(int);
    Hair* FUN_00613870(int);
    signed char GetByteAtOffset(int);
    void* FUN_00613970(int, unsigned int);
    void* GetBodyPartTexture(int, unsigned int);
    List* FUN_00503650();
    void BuildAppearance(NPC*, Output*, int, bool);
};
// Fills an Output appearance record from an NPC or, when npc is null, from race defaults: hair, eyes, color, models, textures, slots, parts, mouth and teeth.
// @fnv 0x006141f0
void Race::BuildAppearance(NPC* npc, Output* apOutput, int sex, bool skip)
{
    bool special = false;
    if (npc)
    {
        npc->FUN_00603ad0(apOutput);
        sex = npc->FUN_005f0cc0();
        if (npc == DAT_011dea3c->FUN_007af430())
        {
            apOutput->player = 1;
            if (DAT_011dea3c->FUN_006047a0())
                special = true;
        }
    }
    else
    {
        void* model = FUN_005d9fb0(sex);
        if (!model)
            model = FUN_006521e0();
        FUN_006529a0(model, apOutput, 0, 0);
    }
    if (npc)
    {
        if (special || !npc->FUN_00603b50() || !npc->FUN_00603b50()->IsHairValidForNPC(npc))
            apOutput->hair = FUN_00613870(sex);
        else
            apOutput->hair = npc->FUN_00603b50();
        apOutput->length = npc->FUN_00602130();
        apOutput->color = npc->FUN_004169d0();
        apOutput->eyes = npc->FUN_00602150();
        apOutput->sex = npc->FUN_005f0cc0();
    }
    else
    {
        apOutput->hair = FUN_00613870(sex);
        apOutput->color = GetByteAtOffset(sex);
    }
    for (unsigned int i = 0; i < 8; i++)
    {
        apOutput->models.FUN_0096a610(FUN_00613970(sex, i));
        apOutput->textures.FUN_0096a610(GetBodyPartTexture(sex, i));
        apOutput->slots.FUN_0096a610(FUN_00605d40(i));
        if (npc && *DAT_011cb99c.FUN_00408d60() && !skip)
        {
            String path(0);
            npc->CreatePartTexture(i, path);
            apOutput->strings.FUN_0060ba10(path);
        }
    }
    apOutput->enabled = *DAT_011cb99c.FUN_00408d60();
    apOutput->texture = FUN_00614630();
    if (npc && !special)
    {
        List* parts = npc->FUN_00602170();
        while (parts && !parts->FUN_008256d0())
        {
            Part* part = *parts->FUN_006815c0();
            parts = parts->FUN_00726070();
            apOutput->parts.FUN_005ae3d0(part);
            List* children = part->FUN_00624700();
            while (children && !children->FUN_008256d0())
            {
                Part* child = *children->FUN_006815c0();
                children = children->FUN_00726070();
                apOutput->parts.FUN_005ae3d0(child);
            }
        }
    }
    apOutput->mouth = FUN_00613970(sex, 6);
    apOutput->teeth = FUN_00613970(sex, 7);
    if (!apOutput->eyes)
    {
        List* eyes = FUN_00503650();
        Part* pEyeSlot = 0;
        if (eyes && !eyes->FUN_008256d0())
        {
            pEyeSlot = *eyes->FUN_006815c0();
            apOutput->eyes = pEyeSlot;
        }
        else
        {
            eyes = DAT_011c3f2c->FUN_0043c490();
            while (eyes)
            {
                pEyeSlot = *eyes->FUN_006815c0();
                if (pEyeSlot && !FUN_00404dc0(pEyeSlot->name.FUN_00408da0(), DAT_0104b8a0))
                {
                    apOutput->eyes = pEyeSlot;
                    break;
                }
                eyes = eyes->FUN_00726070();
            }
        }
    }
}
}

namespace fnv_00613c50 {
// reconstruction of 0x00613c50
extern "C" char DAT_0104b860[];

class AutoMemHelper
{
  public:
    int m_ctx;
    AutoMemHelper(int, bool, const char*, int);
    ~AutoMemHelper();
};

class NiFixedString
{
  public:
    int m_str;
    NiFixedString(const char*);
    ~NiFixedString();
};

class NiObjectNET
{
  public:
    void SetName(const NiFixedString&);
};

struct FUN_00613fb0_C
{
    void Set(bool);
};

struct FUN_0084e3a0_shell
{
    int FUN_0084e3a0();
};

struct Q16
{
    int a, b, c, d;
};
struct FUN_005dd590_C
{
    Q16 q0, q1, q2, RunFourthVirtual, InvokeFifthVirtualFunction, q5, RunSeventhVirtualOperation, q7, q8, q9, q10, q11,
        q12, q13, q14;
    FUN_005dd590_C();
    ~FUN_005dd590_C();
};

struct FUN_00649680_C
{
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    char pad[0x1c0];
    FUN_00649680_C();
};

struct FUN_006628c0_C
{
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    char pad[0xec];
    FUN_006628c0_C();
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
    virtual void v65(void*);
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69(bool);
    virtual void v70();
    virtual void v71(bool);
};

void __cdecl BuildCharacterParts(void*, void*, void*, bool);
void __cdecl ApplyFaceGenTextures(void*, void*);

struct FUN_00613c50_C
{
    bool CreateFaceGenNodes(FUN_006628c0_C**, FUN_006628c0_C**, TESActorBase*, bool, bool, int);
    void BuildAppearance(TESActorBase*, void*, int, bool);
};

// @fnv 0x00613c50
bool FUN_00613c50_C::CreateFaceGenNodes(FUN_006628c0_C** pA, FUN_006628c0_C** pB, TESActorBase* actor, bool fSwap,
                                        bool fFlag, int sex)
{
    AutoMemHelper mem3(0x37, true, DAT_0104b860, 0x623);
    *pA = 0;
    *pB = 0;
    FUN_00649680_C* biped2 = new FUN_00649680_C();
    *pA = new FUN_006628c0_C();
    ((NiObjectNET*)*pA)->SetName(NiFixedString("BSFaceGenNiNodeBiped"));
    (*pA)->v65(biped2);
    (*pA)->v69(true);
    (*pA)->v71(true);
    *pB = new FUN_006628c0_C();
    ((NiObjectNET*)*pB)->SetName(NiFixedString("BSFaceGenNiNodeSkinned"));
    (*pB)->v65(biped2);
    (*pB)->v69(false);
    (*pB)->v71(false);
    FUN_005dd590_C obj;
    BuildAppearance(actor, &obj, sex, false);
    BuildCharacterParts(pA, pB, &obj, fFlag);
    if (fSwap)
    {
        ApplyFaceGenTextures(*pA, &obj);
        ApplyFaceGenTextures(*pB, &obj);
    }
    if (actor && ((FUN_0084e3a0_shell*)actor)->FUN_0084e3a0() == 7)
    {
        ((FUN_00613fb0_C*)*pA)->Set(true);
        ((FUN_00613fb0_C*)*pB)->Set(true);
    }
    return true;
}
}  // namespace fnv_00613c50

namespace fnv_006149b0 {
class NiTexture;
class NiSourceTexture;
class BSFaceGenModel;
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer(T* object = 0);
    ~NiPointer();
    operator T*() const;
    T* operator->() const;
    NiPointer<T>& operator=(T*);
    bool operator==(T*) const;
};
class TES
{
  public:
    void CreateTextureImage(const char*, NiPointer<NiSourceTexture>&, bool, bool);
};
extern TES* g_TES;
class GlobalObject_0045cf30
{
  public:
    unsigned char* Bool();
};
extern GlobalObject_0045cf30 g_011cb99c;
struct NiFixedString
{
    const char* value;
    NiFixedString(const char*);
    ~NiFixedString();
};
class BSFaceGenModel
{
  public:
    bool ApplyTextureCoordinate(FaceGenCoordinates*, NiPointer<NiTexture>&, unsigned int);
};
class TextureAccess
{
  public:
    void FUN_00a5fba0(const NiFixedString*);
};
class NpcCoords : public TESNPC
{
  public:
    void* FUN_00601800();
};
struct RaceTexture : TESRace
{
    bool ApplyBodyTexture(NiPointer<NiSourceTexture>&, NiPointer<NiTexture>&, TESNPC*, BIPED_OBJECT, bool);
    void* FUN_005d9fb0(int);
};
int __cdecl strcpy_s(char*, unsigned int, const char*);
void __cdecl FNV_Warning(const char*, ...);
NiTexture* __cdecl GetFaceGenManagerValue();
bool __cdecl FindTextureByPath(char*, NiPointer<NiTexture>*);
void __cdecl FUN_00a61fb0(char*);
const char* __cdecl GetModelEgtFilename(BSStringT<char>*, const char*);
BSFaceGenModel* __cdecl GetOrCreateFaceGenModel(int, int, int, const char*, int, int, int);
void __cdecl FUN_00652af0(void*, void*, void*, bool, float);
void* __cdecl FUN_006521e0();
void __cdecl FUN_006529a0(void*, void*, bool, bool);
unsigned int __cdecl FUN_006151d0();
void __cdecl FUN_00a61c50(NiTexture*, int);

// Creates or reuses a body texture for a biped part, building a FaceGen model and applying coordinates when needed.
// @fnv 0x006149b0
bool RaceTexture::ApplyBodyTexture(NiPointer<NiSourceTexture>& source, NiPointer<NiTexture>& texture, TESNPC* npc,
                                   BIPED_OBJECT part, bool force)
{
    NiPointer<BSFaceGenModel> model6;
    NiPointer<NiTexture> spC2;
    NiPointer<NiTexture> sp2;
    NiPointer<NiTexture> spB3;
    FaceGenMatrix<float> coords9[2][2];
    int sex4 = npc ? npc->GetSex() : 0;
    BSStringT<char> egt5;
    char path20[260];
    char buf26[260];
    char path3[260];
    BGSTextureModel* modelX;
    char modelPath_[260];
    source = 0;
    if (!force && (void*)npc != (void*)g_thePlayer->GetObjectReference())
        texture = GetFaceGenManagerValue();
    if (!GetBipedObjectModelPath(npc, part, path20))
        return false;
    g_TES->CreateTextureImage(path20, source, false, false);
    if (!source)
        return false;
    if (!*g_011cb99c.Bool())
        return true;
    BuildBodyTexturePath(npc, buf26);
    if (BuildBodyModTexturePath(npc, buf26, path3) && !force)
        g_TES->CreateTextureImage(path3, (NiPointer<NiSourceTexture>&)texture, true, false);
    if (texture == (NiTexture*)0 || force)
    {
        if (!force && (void*)npc != (void*)g_thePlayer->GetObjectReference())
            FNV_Warning("Failed to find body mod texture '%s' for '%s' (%08X). Creating from scratch.", buf26,
                        GetName(), GetFormID());
        modelX = GetBodyTextureModel(npc->GetSex());
        if (!modelX)
            return false;
        if (!force && (void*)npc != (void*)g_thePlayer->GetObjectReference())
        {
            FindTextureByPath(buf26, &texture);
            if (texture)
                return true;
        }
        strcpy_s(modelPath_, 260, "Meshes\\");
        strcat_s(modelPath_, 260, modelX->GetModelFilePath());
        model6 = GetOrCreateFaceGenModel(0, 0, 0, GetModelEgtFilename(&egt5, modelPath_), 1, -1, 0);
        if (!model6)
            return false;
        if (npc)
        {
            FUN_00652af0(FUN_005d9fb0(npc->GetSex()), ((NpcCoords*)npc)->FUN_00601800(), coords9, false, 0.0f);
        }
        else
        {
            void* _fallback = FUN_005d9fb0(sex4);
            if (!_fallback)
                _fallback = FUN_006521e0();
            FUN_006529a0(_fallback, coords9, false, false);
        }
        if (force)
            FUN_00a61fb0(path3);
        ((BSFaceGenModel*)model6)->ApplyTextureCoordinate((FaceGenCoordinates*)coords9, texture, FUN_006151d0());
        if (!texture)
            return false;
        ((TextureAccess*)(NiTexture*)texture)->FUN_00a5fba0(&NiFixedString(path3));
        FUN_00a61c50(texture, 0);
    }
    return true;
}
}  // namespace fnv_006149b0

namespace RaceLoadDetail {
struct RaceLoadFile
{
    int FUN_00472660();
    int FUN_004726b0();
    unsigned int GetField25C();
    bool ReadChunkInt(void*);
    bool GetChunkData(void*, unsigned int);
    bool FUN_004726f0();
};
struct RaceLoadComponents
{
    TESForm form;
    TESFullName fullName;
    TESDescription description;
    TESSpellList spells;
    TESReactionForm reactions;
};
struct RaceLoadReaction
{
    TESForm* pForm;
    int iFactionReaction;
    int m_iAdditionalFactionReaction;
};
using ::TESEyes;
class TESEyes : public TESForm
{
};
struct RaceLoadTarget : public TESRace
{
    bool FUN_00610cd0(TESFile*);
};

template <int N> struct RaceLoadEndianTag
{
};
void __cdecl FUN_00401080(int*, RaceLoadEndianTag<4>);
void* __cdecl FUN_00403d30(void*, int, unsigned int);
extern "C" void* __cdecl _alloca(unsigned int);

struct RaceLoadShortChunk
{
    bool ReadChunkData(unsigned short*);
};
struct RaceLoadReactionEndian
{
    void FUN_005a6b10();
};
struct RaceLoadReactionList
{
    void FUN_00905820(char* const&);
};
class NiPoint3;
struct RaceLoadReactionAccess
{
    const NiPoint3& FUN_00717e50();
};
struct RaceLoadTextureName
{
    void FUN_00489100(const char*);
};
struct RaceLoadCoordArray
{
    void SetDimensions(unsigned int, bool);
};
struct RaceLoadCoordScalar
{
    float& FUN_00629ab0(unsigned int);
};
struct RaceLoadCoordValue : public RaceLoadCoordScalar
{
    int a;
    int b;
};
struct RaceLoadCoordAccess
{
    RaceLoadCoordValue FUN_0060b370(int);
};
struct RaceLoadAttributes
{
    void FUN_00480130(unsigned char*);
};
struct RaceLoadSpellList
{
    void FUN_0048d290(unsigned int);
};
struct RaceLoadHairList
{
    void FUN_00613810(TESHair*);
};
struct RaceLoadHairDefault
{
    void SetIndexedInt(int, unsigned int);
};
struct RaceLoadEyeList
{
    void FUN_00613910(TESEyes*);
};
struct RaceLoadDataReader
{
    void FUN_004861f0(TESFile*, void*, unsigned short);
};
struct RaceLoadEndianState
{
    bool FUN_00401680();
};
struct RaceLoadDataEndian
{
    void FUN_00611db0();
};
struct RaceLoadTextureChunk
{
    static void __cdecl FUN_0048e3d0(TESTexture*, TESFile*);
};
bool __cdecl FUN_00489280(int);
bool __cdecl IsChunkTypeIcon(int);
void __cdecl FUN_004892d0(TESModel*, TESFile*);
void __cdecl ReadFullName(TESFullName*, TESFile*);
void __cdecl FUN_00482d50(TESDescription*, TESFile*);
unsigned int __fastcall FUN_009d2510(void*);
extern const char* DAT_01199fbc[2];
extern const char* DAT_01199fe8[2][8];
extern const char* DAT_0119a028[2][8];
extern const char* DAT_0119a080[2][3];
struct RaceLoadVirtuals
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
    virtual void v56(TESFile*);
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
    virtual const char* v76();
    virtual void v77(const char*);
};

// Reads a race record from apFile, parsing chunks into fields and returning false if the record type is not 0xc.
// @fnv 0x00610cd0
bool RaceLoadTarget::FUN_00610cd0(TESFile* apFile)
{
    int isex;
    int esymm;
    int chunkid;
    int ipart;
    bool boldSchool;
    int etype;
    bool bfacepart;

    isex = 0;
    ipart = 0;
    etype = -1;
    esymm = -1;
    bfacepart = false;
    boldSchool = true;
    if (((RaceLoadFile*)apFile)->FUN_00472660() != 0xc)
        return false;
    LoadRecordHeader(apFile);
    while ((chunkid = ((RaceLoadFile*)apFile)->FUN_004726b0()) != 0)
    {
        etype = esymm = -1;
        switch (chunkid)
        {
        case 0x44494445: {
            char* pMessage = (char*)_alloca(((RaceLoadFile*)apFile)->GetField25C());
            ((RaceLoadFile*)apFile)->GetChunkData(pMessage, 0x200);
            ((RaceLoadVirtuals*)this)->v77(pMessage);
            break;
        }
        case 0x444e424f:
            ((RaceLoadVirtuals*)this)->v56(apFile);
            break;
        case 0x4c4c5546:
            ReadFullName(this, apFile);
            break;
        case 0x43534544:
            FUN_00482d50(this, apFile);
            break;
        case 0x4f4c5053: {
            unsigned int tempint = 0;
            ((RaceLoadFile*)apFile)->ReadChunkInt(&tempint);
            ((RaceLoadSpellList*)(&((RaceLoadComponents*)this)->spells))->FUN_0048d290(tempint);
            break;
        }
        case 0x4d414e58: {
            RaceLoadReaction* pdata = new RaceLoadReaction;
            ((RaceLoadFile*)apFile)->GetChunkData(pdata, 0xc);
            if (((RaceLoadEndianState*)apFile)->FUN_00401680())
                ((RaceLoadReactionEndian*)pdata)->FUN_005a6b10();
            ((RaceLoadReactionList&)((RaceLoadReactionAccess*)(&((RaceLoadComponents*)this)->reactions))
                 ->FUN_00717e50())
                .FUN_00905820(reinterpret_cast<char*&>(pdata));
            break;
        }
        case 0x41544144:
            ((RaceLoadDataReader*)this)->FUN_004861f0(apFile, &Data, 0x24);
            break;
        case 0x4d414e4f: {
            unsigned int itempint = 0;
            ((RaceLoadFile*)apFile)->ReadChunkInt(&itempint);
            m_pOlderRace = (TESRace*)itempint;
            break;
        }
        case 0x4d414e59: {
            unsigned int itempint = 0;
            ((RaceLoadFile*)apFile)->ReadChunkInt(&itempint);
            m_pYoungerRace = (TESRace*)itempint;
            break;
        }
        case 0x4b435456:
            if (((RaceLoadFile*)apFile)->GetField25C() == 4)
            {
                SetDefaultVoiceType(SEX_SEX_MALE, g_pDefaultMaleVoiceType);
                SetDefaultVoiceType(SEX_SEX_FEMALE, g_pDefaultFemaleVoiceType);
            }
            else if (((RaceLoadFile*)apFile)->GetField25C() == 8)
            {
                unsigned int ptempint[2];
                ((RaceLoadFile*)apFile)->GetChunkData(ptempint, 8);
                if (((RaceLoadEndianState*)apFile)->FUN_00401680())
                {
                    for (int i = 0; i < 2; i++)
                        FUN_00401080((int*)&ptempint[i], RaceLoadEndianTag<4>());
                }
                SetDefaultVoiceType(SEX_SEX_MALE, (BGSVoiceType*)ptempint[0]);
                SetDefaultVoiceType(SEX_SEX_FEMALE, (BGSVoiceType*)ptempint[1]);
            }
            break;
        case 0x4d414e43:
            if (((RaceLoadFile*)apFile)->GetField25C() == 1)
            {
                ((RaceLoadFile*)apFile)->GetChunkData(&m_acDefaultHairColors[0], 2);
                ((RaceLoadFile*)apFile)->GetChunkData(&m_acDefaultHairColors[1], 2);
            }
            else if (((RaceLoadFile*)apFile)->GetField25C() == 2)
            {
                unsigned char ptempcolor[2];
                ((RaceLoadFile*)apFile)->GetChunkData(ptempcolor, 2);
                for (int isex = 0; isex < 2; isex++)
                    SetDefaultHairColor((SEX)isex, ptempcolor[isex]);
            }
            break;
        case 0x4d414e50:
            ((RaceLoadFile*)apFile)->ReadChunkInt(&m_fFaceGenMainClamp);
            break;
        case 0x4d414e55:
            ((RaceLoadFile*)apFile)->ReadChunkInt(&m_fFaceGenFaceClamp);
            break;
        case 0x4d414e44: {
            unsigned int ptempint[2];
            ((RaceLoadFile*)apFile)->GetChunkData(ptempint, 8);
            if (((RaceLoadEndianState*)apFile)->FUN_00401680())
            {
                for (int i = 0; i < 2; i++)
                    FUN_00401080((int*)&ptempint[i], RaceLoadEndianTag<4>());
            }
            ((RaceLoadHairDefault*)this)->SetIndexedInt(0, ptempint[0]);
            ((RaceLoadHairDefault*)this)->SetIndexedInt(1, ptempint[1]);
            break;
        }
        case 0x52545441: {
            unsigned int iattribSize = FUN_009d2510(&m_kMaleAttributes);
            char* pdata = (char*)_alloca(iattribSize * 2);
            ((RaceLoadFile*)apFile)->GetChunkData(pdata, iattribSize * 2);
            ((RaceLoadAttributes*)&m_kMaleAttributes)->FUN_00480130((unsigned char*)pdata);
            pdata = pdata + iattribSize;
            ((RaceLoadAttributes*)&m_kFemaleAttributes)->FUN_00480130((unsigned char*)pdata);
            break;
        }
        case 0x53474746:
            if (etype == -1)
            {
                etype = 0;
                esymm = 0;
            }
        case 0x41474746:
            if (etype == -1)
            {
                etype = 0;
                esymm = 1;
            }
        case 0x53544746: {
            if (etype == -1)
            {
                etype = 1;
                esymm = 0;
            }
            float* pfloats = 0;
            unsigned int imemsize = ((RaceLoadFile*)apFile)->GetField25C();
            int isize = imemsize >> 2;
            if (!isex || boldSchool)
                ((RaceLoadCoordArray*)&m_kSecondFloatPairBySex[etype][esymm])->SetDimensions(isize, true);
            ((RaceLoadCoordArray*)&m_kFirstFloatPairBySex[etype][esymm])->SetDimensions(isize, true);
            pfloats = (float*)_alloca(imemsize);
            FUN_00403d30(pfloats, 0, imemsize);
            ((RaceLoadFile*)apFile)->GetChunkData(pfloats, imemsize);
            for (unsigned int i = 0; i < isize; i++)
            {
                if (((RaceLoadEndianState*)apFile)->FUN_00401680())
                    FUN_00401080((int*)&pfloats[i], RaceLoadEndianTag<4>());
                if (!isex || boldSchool)
                    ((RaceLoadCoordAccess*)&m_kSecondFloatPairBySex[etype][esymm])->FUN_0060b370(i).FUN_00629ab0(0) =
                        pfloats[i];
                ((RaceLoadCoordAccess*)&m_kFirstFloatPairBySex[etype][esymm])->FUN_0060b370(i).FUN_00629ab0(0) =
                    pfloats[i];
            }
            break;
        }
        case 0x4d414e46:
            isex = 1;
            break;
        case 0x4d414e4d:
            isex = 0;
            break;
        case 0x58444e49:
            ((RaceLoadFile*)apFile)->ReadChunkInt(&ipart);
            if (bfacepart)
            {
                int isub = (boldSchool && ipart > 1) ? 1 : 0;
                if (ipart < 8 && ipart - isub != 1)
                {
                    m_kBodyPartModels[isex][ipart - isub].Init();
                    m_kBodyPartModels[isex][ipart - isub].SetModelFilePath(DAT_01199fe8[isex][ipart - isub]);
                    m_kBodyPartTextures[isex][ipart - isub].Init();
                    ((RaceLoadTextureName*)&m_kBodyPartTextures[isex][ipart - isub])
                        ->FUN_00489100(DAT_0119a028[isex][ipart - isub]);
                }
            }
            else
            {
                if (ipart < 3)
                {
                    m_kHeadPartModels[isex][ipart].Init();
                    m_kHeadPartModels[isex][ipart].SetModelFilePath(DAT_0119a080[isex][ipart]);
                    m_kHeadPartTextures[isex][ipart].Init();
                }
                if (ipart == 3)
                {
                    m_kFaceGenTextureModels[isex].Init();
                    m_kFaceGenTextureModels[isex].SetModelFilePath(DAT_01199fbc[isex]);
                }
            }
            break;
        case 0x304d414e:
            bfacepart = true;
            break;
        case 0x314d414e:
            bfacepart = false;
            break;
        case 0x324d414e:
            boldSchool = false;
            break;
        case 0x4d414e53:
            if (((RaceLoadFile*)apFile)->GetField25C() >= 2)
                ((RaceLoadShortChunk*)apFile)->ReadChunkData(&m_usRaceAttribute);
            break;
        case 0x4d414e48: {
            unsigned int* phairIDs = 0;
            unsigned int ichunksize = ((RaceLoadFile*)apFile)->GetField25C();
            if (ichunksize % 4 != 0)
                break;
            unsigned int inumHair = ichunksize >> 2;
            if (inumHair != 0)
            {
                phairIDs = new unsigned int[inumHair];
                ((RaceLoadFile*)apFile)->GetChunkData(phairIDs, ichunksize);
                for (unsigned int i = 0; i < inumHair; i++)
                {
                    if (((RaceLoadEndianState*)apFile)->FUN_00401680())
                        FUN_00401080((int*)&phairIDs[i], RaceLoadEndianTag<4>());
                    RemapFormIDForFile(phairIDs[i], apFile);
                    TESHair* phair = dynamic_cast<TESHair*>(GetFormByID(phairIDs[i]));
                    if (phair)
                        ((RaceLoadHairList*)this)->FUN_00613810(phair);
                    else
                        Warning("MASTERFILE: Could not find hair (%08X) for race '%s' (%08X).", phairIDs[i],
                                ((RaceLoadVirtuals*)this)->v76(), GetFormID());
                }
                delete[] phairIDs;
            }
            break;
        }
        case 0x4d414e45: {
            unsigned int* peyesIDs = 0;
            unsigned int ichunksize = ((RaceLoadFile*)apFile)->GetField25C();
            if (ichunksize % 4 != 0)
                break;
            unsigned int inumEyes = ichunksize >> 2;
            if (inumEyes != 0)
            {
                peyesIDs = new unsigned int[inumEyes];
                ((RaceLoadFile*)apFile)->GetChunkData(peyesIDs, ichunksize);
                for (unsigned int i = 0; i < inumEyes; i++)
                {
                    if (((RaceLoadEndianState*)apFile)->FUN_00401680())
                        FUN_00401080((int*)&peyesIDs[i], RaceLoadEndianTag<4>());
                    RemapFormIDForFile(peyesIDs[i], apFile);
                    TESEyes* peyes = dynamic_cast<TESEyes*>(GetFormByID(peyesIDs[i]));
                    if (peyes)
                        ((RaceLoadEyeList*)this)->FUN_00613910(peyes);
                    else
                        Warning("MASTERFILE: Could not find eyes (%08X) for race '%s' (%08X).", peyesIDs[i],
                                ((RaceLoadVirtuals*)this)->v76(), GetFormID());
                }
                delete[] peyesIDs;
            }
            break;
        }
        default:
            if (bfacepart)
            {
                int isub = (boldSchool && ipart > 1) ? 1 : 0;
                if (ipart - isub < 8 && ipart - isub != 1)
                {
                    if (IsChunkTypeIcon(chunkid))
                        RaceLoadTextureChunk::FUN_0048e3d0(&m_kBodyPartTextures[isex][ipart - isub], apFile);
                    else if (FUN_00489280(chunkid))
                        FUN_004892d0(&m_kBodyPartModels[isex][ipart - isub], apFile);
                }
            }
            else
            {
                if (ipart < 3)
                {
                    if (IsChunkTypeIcon(chunkid))
                        RaceLoadTextureChunk::FUN_0048e3d0(&m_kHeadPartTextures[isex][ipart], apFile);
                    else if (FUN_00489280(chunkid))
                        FUN_004892d0(&m_kHeadPartModels[isex][ipart], apFile);
                }
                if (ipart == 3)
                    FUN_004892d0(&m_kFaceGenTextureModels[isex], apFile);
            }
            break;
        }
        if (chunkid == 0x41544144 && ((RaceLoadEndianState*)apFile)->FUN_00401680())
            ((RaceLoadDataEndian*)&Data)->FUN_00611db0();
        if (!((RaceLoadFile*)apFile)->FUN_004726f0())
            break;
    }
    return true;
}

}

namespace TESRaceCleanup6104c0 {
class FUN_00483630_RaceFormCleanup : public TESForm
{
  public:
    virtual ~FUN_00483630_RaceFormCleanup();
};
class FUN_006104c0 : public FUN_00483630_RaceFormCleanup,
                     public TESFullName,
                     public TESDescription,
                     public TESSpellList,
                     public TESReactionForm
{
  public:
    RaceDefinitionData Data;
    TESAttributes m_kMaleAttributes, m_kFemaleAttributes;
    BSSimpleList<TESHair*> m_kHairList;
    TESHair* m_apDefaultHairStyles[2];
    unsigned char m_acDefaultHairColors[2];
    float m_fFaceGenMainClamp, m_fFaceGenFaceClamp;
    BSSimpleList<TESEyes*> m_kEyeList;
    TESModel m_kBodyPartModels[2][8];
    TESTexture m_kBodyPartTextures[2][8];
    TESTexture m_kHeadPartTextures[2][3];
    TESModel m_kHeadPartModels[2][3];
    BGSTextureModel m_kFaceGenTextureModels[2];
    FaceGenMatrix<float> m_kFirstFloatPairBySex[2][2], m_kSecondFloatPairBySex[2][2];
    unsigned short m_usRaceAttribute;
    BGSVoiceType* m_apDefaultVoiceTypes[2];
    TESRace* m_pOlderRace;
    TESRace* m_pYoungerRace;
    BSStringT<char> strEditorID;
    NiTPrimitiveArray<FaceGenUndo*> m_kFaceGenUndoList;
    virtual ~FUN_006104c0();
};
// Calls FUN_00610ac0 on this through a RaceCleanup pointer.
// @fnv 0x006104c0
FUN_006104c0::~FUN_006104c0()
{
    ((RaceCleanup*)this)->FUN_00610ac0();
}
}
