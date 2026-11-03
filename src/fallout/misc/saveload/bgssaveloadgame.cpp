// fallout/misc/saveload/bgssaveloadgame.cpp: BGSSaveLoadGame, DelStandIn, BGSSaveLoadGameImpl, FakeGame and more (59 functions)

#include "bgssaveloadgame_decls.h"
// @fnv 0x00847570
unsigned char BGSSaveLoadGame::GetLoadState()
{
    return m_ucSaveLoadState;
}
// @fnv 0x00849ce0
bool BGSSaveLoadGame::ContainsReference(unsigned int formID)
{
    return ((NiTPointerMap<unsigned int, TESObjectREFR*>*)this)->GetAt(formID, (TESObjectREFR*&)formID);
}
// @fnv 0x0084a6d0
bool BGSSaveLoadGame::HasFormChangeFlags(TESForm* form, FormChangeMask flags)
{
    return m_pFormChangesMap->ContainsChangeFlags(form->GetFormID(), flags);
}
// Returns true if changes are allowed and the form is not temporary; otherwise false.
// @fnv 0x0084a740
bool BGSSaveLoadGame::IsFormChanged(TESForm* form)
{
    if (!GetAllowChanges() || form->IsTemporary())
        return false;
    return true;
}
// @fnv 0x0084a780
void BGSSaveLoadGame::ClearFormChangeFlags(TESForm* form, FormChangeMask flags)
{
    if (!IsFormChanged(form))
        return;
    m_pFormChangesMap->ClearChangeFlags(form->GetFormID(), flags);
}
// @fnv 0x0084a690
void BGSSaveLoadGame::NotifyFormIDChanged(TESForm* form, FormChangeMask flags, bool force)
{
    if (!ShouldSaveForm(form, force))
        return;
    m_pFormChangesMap->AddFormChangeFlags(form->GetFormID(), flags);
}
// @fnv 0x0084a7c0
void BGSSaveLoadGame::HasFormChanges(TESForm* form)
{
    struct
    {
        unsigned int formID;
        FormChangeRecord* changes;
    } state;
    state.formID = form->GetFormID();
    state.changes = m_pFormChangesMap->FUN_009a4250(state.formID);
    if (state.changes && !state.changes->savedFlags.FUN_00559450())
        m_pFormChangesMap->HasFormChanges(state.formID);
}
// @fnv 0x0084a5b0
void BGSSaveLoadGame::ClearFormChanges()
{
    struct
    {
        unsigned int formID;
        Actor* actor;
        void* pos;
    } state;
    state.pos = ((BGSReconstructFormsInAllFilesMap*)((char*)this + 0x34))->GetFirstPos();
    while (state.pos)
    {
        state.formID = 0;
        state.actor = 0;
        ((BGSReconstructFormsInAllFilesMap*)((char*)this + 0x34))
            ->GetNext(state.pos, (TESFile*&)state.formID, (BGSReconstructFormsInFileMap*&)state.actor);
        if (state.actor->GetProcess())
            state.actor->UpdateActorMovementState(true);
    }
    ((NiTPointerMap<unsigned int, unsigned int>*)((char*)this + 0x34))->RemoveAll();
}
// @fnv 0x0084a620
bool BGSSaveLoadGame::ShouldSaveForm(TESForm* form, bool force)
{
    if ((!GetAllowChanges() && !force) || form->IsTemporary())
        return false;
    unsigned int formID = form->GetFormID();
    if (form->IsDeleted() && reinterpret_cast<TESDataHandlerSaveLoad*>(g_dataHandler)->FormIDExists(formID))
        return false;
    return true;
}
// @fnv 0x00849b10
void BGSSaveLoadGame::FormReconstructionMap(TESObjectCELL* cell)
{
    if (FUN_0042ce10())
        return;
    LoadForm(reinterpret_cast<TESForm*>(cell));
    BGSReconstructFormsInAllFilesMap forms;
    m_pReferencesMap->LoadCellReferences(cell, &forms);
    FUN_00849c00(true);
    forms.BuildMap();
    FUN_00849c00(false);
    unsigned int iCount = forms.FUN_00849c80();
    for (unsigned int index = 0; index < iCount; ++index)
    {
        TESForm* form = forms.FUN_00849ca0(index);
        LoadForm(form);
    }
}

struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct SaveLoadFile;
struct blob4
{
    char b[4];
};
struct FormBufferContext
{
    void Save(SaveLoadFile*, unsigned int, struct blob4);
    void Load(SaveLoadFile*);
    void SetBuffer(char*);
    char* GetBufferData();
    BGSLoadFormBuffer* CreateFormBuffer();
    void Initialize(char*, unsigned int, int, unsigned char);
    void Initialize(BGSSaveFormBuffer*);
    int GetFormType();
    int GetSizeType();
    unsigned char GetVersion();
    unsigned int GetSize();
    unsigned int GetFormIdentifier();
    void ReleaseBuffer();
    void ResetReadPosition();
    char* pBuffer;
};
typedef char _sizecheck_BGSUnloadedFormBuffer[sizeof(FormBufferContext) == 4 ? 1 : -1];
struct FUN_006665a0_shell : public FormBufferContext
{
    void FUN_006665a0();
};

// @fnv 0x006665a0
void FUN_006665a0_shell::FUN_006665a0()
{
    pBuffer = 0;
}

void* __cdecl memset(void*, int, unsigned int);

// @fnv 0x00847d50
void* __fastcall ClearObject(void* apObject)
{
    memset(apObject, 0, 0x6e);
    return apObject;
}

struct FUN_00848ca0_shell : public BGSSaveLoadGame
{
    void FUN_00848ca0(bool);
};

// @fnv 0x00848ca0
void FUN_00848ca0_shell::FUN_00848ca0(bool abValue)
{
    if (abValue)
        *(unsigned int*)((char*)this + 0x244) |= 2;
    else
        *(unsigned int*)((char*)this + 0x244) &= ~2;
}

namespace fnv_00848dd0 {
struct SaveLoadFile;
struct ThreeByThreeMatrix;
struct NiPoint3;
struct NiQuaternion;
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
    FormChangeMask m_cReservedBytes;
};
typedef char _sizecheck_BGSLoadFormBuffer[sizeof(BGSLoadFormBuffer) == 48 ? 1 : -1];
struct FUN_00848dd0_shell : public BGSLoadFormBuffer
{
    bool FUN_00848dd0();
};

// @fnv 0x00848dd0
bool FUN_00848dd0_shell::FUN_00848dd0()
{
    return (iFlags & 1) ? true : false;
}
}  // namespace fnv_00848dd0

struct FUN_00848df0_shell : public TESDataHandler
{
    void FUN_00848df0(bool);
};

// @fnv 0x00848df0
void FUN_00848df0_shell::FUN_00848df0(bool abValue)
{
    *((bool*)((char*)this + 0x621)) = abValue;
}

struct FUN_00849540_shell : public BGSSaveLoadGame
{
    void SetFlag8(bool);
};

// @fnv 0x00849540
void FUN_00849540_shell::SetFlag8(bool abValue)
{
    if (abValue)
        *(unsigned int*)((char*)this + 0x244) |= 8;
    else
        *(unsigned int*)((char*)this + 0x244) &= ~8;
}

// @fnv 0x00849590
bool __fastcall FUN_00849590(int pObject)
{
    return (*(unsigned int*)(pObject + 0x28) & 0x10) ? true : false;
}

// @fnv 0x008495b0
void __fastcall FUN_008495b0(char* pThis)
{
    *reinterpret_cast<int*>(pThis + 0x68) = 5;
}

struct FUN_00849c00_shell : public BGSSaveLoadGame
{
    void FUN_00849c00(bool);
};

struct TLSData_00849c00
{
    char pad[0x294];
    unsigned int uiFlags;
};

static __declspec(thread) TLSData_00849c00 g_tlsData_00849c00;

// @fnv 0x00849c00
void FUN_00849c00_shell::FUN_00849c00(bool abValue)
{
    if (abValue)
        g_tlsData_00849c00.uiFlags |= 2;
    else
        g_tlsData_00849c00.uiFlags &= ~2;
}

struct FUN_00849c80_shell : public BGSReconstructFormsInAllFilesMap
{
    unsigned int FUN_00849c80();
};

struct FormChangeMap
{
    unsigned int GetCombinedFlags();
};
// @fnv 0x00849c80
unsigned int FUN_00849c80_shell::FUN_00849c80()
{
    return ((FormChangeMap*)((char*)this + 0x10))->GetCombinedFlags();
}

struct ST_00849cc0
{
    char pad[0x10];
    BGSSaveLoadGame* pGame;
    bool FUN_00849cc0(unsigned int id);
};
// @fnv 0x00849cc0
bool ST_00849cc0::FUN_00849cc0(unsigned int id)
{
    return pGame->ContainsReference(id);
}

struct FUN_0084a580_shell : public BGSSaveLoadGame
{
    void RemoveActorFromMap(Actor*);
};

template <> class NiTPointerMap<unsigned int, void*>
{
  public:
    bool RemoveAt(unsigned int);
};

// Removes the actor's form ID from the pointer map at offset 0x34 of this object.
// @fnv 0x0084a580
void FUN_0084a580_shell::RemoveActorFromMap(Actor* apActor)
{
    reinterpret_cast<NiTPointerMap<unsigned int, void*>*>(reinterpret_cast<char*>(this) + 0x34)
        ->RemoveAt(reinterpret_cast<TESForm*>(apActor)->GetFormID());
}

namespace fnv_0084a810 {
struct SaveLoadFile;
struct ThreeByThreeMatrix;
struct NiPoint3;
struct NiQuaternion;
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
    FormChangeMask m_cReservedBytes;
};
typedef char _sizecheck_BGSLoadFormBuffer[sizeof(BGSLoadFormBuffer) == 48 ? 1 : -1];
struct FUN_0084a810_shell : public BGSSaveLoadGame
{
    void FUN_0084a810(int, BGSLoadFormBuffer*, TESForm*);
};

enum QUEUED_SUB_BUFFER_TYPE
{
    QSB_DUMMY
};
struct LoadGameSubBufferQueue
{
    void ProcessSubBuffer(QUEUED_SUB_BUFFER_TYPE, BGSLoadFormBuffer*, TESForm*);
};
// @fnv 0x0084a810
void FUN_0084a810_shell::FUN_0084a810(int type, BGSLoadFormBuffer* buffer, TESForm* form)
{
    (*(LoadGameSubBufferQueue**)((char*)this + 0x14))->ProcessSubBuffer((QUEUED_SUB_BUFFER_TYPE)type, buffer, form);
}
}  // namespace fnv_0084a810

namespace fnv_008665b0 {
struct SaveLoadFile;
struct ThreeByThreeMatrix;
struct NiPoint3;
struct NiQuaternion;
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
    FormChangeMask m_cReservedBytes;
};
typedef char _sizecheck_BGSLoadFormBuffer[sizeof(BGSLoadFormBuffer) == 48 ? 1 : -1];
struct FUN_008665b0_shell : public BGSLoadFormBuffer
{
    int FUN_008665b0();
};

int __fastcall FUN_00853640(void* pThis);

// @fnv 0x008665b0
int FUN_008665b0_shell::FUN_008665b0()
{
    return FUN_00853640((char*)this + 0x1b);
}
}  // namespace fnv_008665b0

void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_00847450(unsigned int flags);
};
// Calls the destructor, frees this when flags has bit 0 set, and returns this.
// @fnv 0x00847450
void* DelStandIn::FUN_00847450(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}

namespace fnv_00849d00 {
struct BSFile;
struct ThreeByThreeMatrix;
struct NiPoint3;
struct NiQuaternion;
struct TESObjectREFR;
struct hkVector4;
struct blob4
{
    char b[4];
};
struct SaveLoadFile
{
    unsigned int Read(void*, unsigned int);
    unsigned int Write(void*, unsigned int);
    bool Open();
    unsigned int GetFilePosition();
    unsigned int GetFileSize();
    void SetFilePosition(int);
    void SeekCurrent(int);
    char* GetFileName();
    static SaveLoadFile* CreateFileA(char*, bool, unsigned int);
    void SetSaveFileName(char*);
    char* GetSaveFileName();
    BSFile* QFile();
    unsigned int GetSimulatedFileSize();
    void* __vecDelDtor(unsigned int);
    char m_cFileName[260];
    BSFile* pFile;
    unsigned int m_uiBufferSize;
    unsigned int m_uiFilePosition;
};
typedef char _sizecheck_BGSSaveLoadFile[sizeof(SaveLoadFile) == 272 ? 1 : -1];
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
    FormChangeMask m_cReservedBytes;
};
typedef char _sizecheck_BGSLoadFormBuffer[sizeof(BGSLoadFormBuffer) == 48 ? 1 : -1];
struct FormIDConverter
{
    void Clear();
    unsigned int RegisterFormID(unsigned int);
    unsigned int GetFormID(unsigned int);
    unsigned int ConvertFormID(unsigned int);
    unsigned int ReverseConvertFormID(unsigned int);
    void Save(SaveLoadFile*);
    void Load(SaveLoadFile*);
    void* __vecDelDtor(unsigned int);
    char m_kSourceToTargetFormIDMap[16];
    char m_kTargetToSourceFormIDMap[16];
    unsigned int m_uiFormIDCount;
};
typedef char _sizecheck_BGSSaveLoadFormIDMap[sizeof(FormIDConverter) == 36 ? 1 : -1];
struct FUN_00849d00_shell : public BGSSaveLoadGame
{
    unsigned int LoadFormData(SaveLoadFile*, BGSLoadFormBuffer*, FormIDConverter*);
};

struct NiPoint3
{
    float x, y, z;
    static const NiPoint3 ZERO;
};
struct TESWorldSpace;
struct ChangeFlagsT
{
    unsigned int iFlags;
    ChangeFlagsT(int flags);
    unsigned int FUN_00559450();
    static ChangeFlagsT HasFormChanged(ChangeFlagsT oldFlags, ChangeFlagsT newFlags, int formType, bool forced);
};
struct FormBufferContext
{
    void* pData;
    FormBufferContext();
    void* FUN_00559450();
    void* FUN_00866390();
};
struct BGSSaveLoadInitialDataPacket
{
    static int DetermineInitialDataType(unsigned int formID, int formType, ChangeFlagsT changeFlags);
};
struct ReferencePlacementData
{
    unsigned int iLocationFormID;
    unsigned int iBaseFormID;
    unsigned int iUnk08;
    int m_iGridPositionX;
    int m_iGridCoordinateY;
    NiPoint3 kTargetPoint;
    NiPoint3 kAngle;
    unsigned char cFlags;
    ReferencePlacementData();
    bool GetCellAndWorld(TESObjectCELL*& cell, TESWorldSpace*& world);
    void FUN_0084e6a0(TESObjectCELL*& cell, TESWorldSpace*& world);
};
struct TESObjectREFR
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
    virtual bool IsReference();
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
    virtual bool GetStartingPosition(NiPoint3* location, NiPoint3* angle, TESForm** space, TESForm* defaultSpace);
    bool GetReferencePersistence();
    TESForm* GetObjectReference();
    TESObjectCELL* GetParentCell();
};
struct TESFormH
{
    int GetFormType();
};
struct TESObjectCELLH
{
    bool IsInterior();
    void RemoveReference(TESObjectREFR* ref);
};
struct TESWorldSpace
{
    TESObjectCELL* GetCellByWorldPosition(const NiPoint3& location);
};
struct TES
{
    bool IsCellBuffered(TESObjectCELL* cell, bool unk);
};
extern TES* g_TES;
extern TESObjectREFR* g_thePlayer;
struct LoadFormBufferH : public BGSLoadFormBuffer
{
    int FUN_008665b0();
    unsigned int FUN_0044edb0();
    ChangeFlagsT GetChangeFlags();
    ChangeFlagsT GetOldChangeFlags();
    void SetForm(TESForm* form);
    void SetChangeFlags(ChangeFlagsT flags);
    void FUN_00848d90(bool value);
    void FUN_0084a360(bool value);
    void CombineFlags(bool value);
};
struct ChangesMapH
{
    FormBufferContext FUN_00845760(unsigned int formID);
};
struct ReferencesMapH
{
    void ForwardToMember(unsigned int locationID, unsigned int formID);
    void SetAtKey(unsigned int formID);
    void AddReferenceToCell(unsigned int locationID, unsigned int formID, NiPoint3* location);
};
struct ReconstructFormsH
{
    void FUN_00843750(TESObjectCELL* cell, unsigned int formID, bool unk);
    void FUN_008438b0(TESWorldSpace* world, int x, int y, unsigned int formID, bool unk);
};
unsigned int __cdecl FUN_0084e850(SaveLoadFile* file, int type, ReferencePlacementData* data);
TESForm* __cdecl ResolveReferenceForm(unsigned int formID, ReferencePlacementData* data, TESForm* form);
int __cdecl FUN_0084e930(void* buffer, int type, ReferencePlacementData* data);
void __cdecl LogWarning(const char* format, ...);
struct BGSSaveLoadGameImpl : public BGSSaveLoadGame
{
    unsigned int LoadFormData(SaveLoadFile* apFile, LoadFormBufferH* apLoadGameBuffer, FormIDConverter* apOldFormIDMap);
    void FUN_0084a880(TESForm* form);
    void DeleteForm(TESForm* form);
};

// @fnv 0x00849d00
unsigned int BGSSaveLoadGameImpl::LoadFormData(SaveLoadFile* apFile, LoadFormBufferH* apLoadGameBuffer,
                                               FormIDConverter* apOldFormIDMap)
{
    unsigned int idataSizeLoaded = 0;
    int eformType = apLoadGameBuffer->FUN_008665b0();
    ChangeFlagsT ichangeFlags = apLoadGameBuffer->GetChangeFlags();
    ChangeFlagsT ioldChangeFlags = apLoadGameBuffer->GetOldChangeFlags();
    unsigned int iformID = apLoadGameBuffer->FUN_0044edb0();
    TESForm* pform = apLoadGameBuffer->GetForm();
    int einitialDataType = BGSSaveLoadInitialDataPacket::DetermineInitialDataType(iformID, eformType, ichangeFlags);
    if (einitialDataType == 5 || einitialDataType == 6)
    {
        TESObjectCELL* pcell;
        ReferencePlacementData refData;
        idataSizeLoaded = FUN_0084e850(apFile, einitialDataType, &refData);
        TESObjectREFR* pref = 0;
        if (pform)
        {
            bool bclearForm = false;
            if (!((TESObjectREFR*)pform)->IsReference())
            {
                if (einitialDataType == 5)
                    bclearForm = true;
            }
            else
            {
                pref = (TESObjectREFR*)pform;
                if (einitialDataType == 5 && pref->GetObjectReference()->GetFormID() != refData.iBaseFormID)
                    bclearForm = true;
            }
            if (bclearForm)
            {
                FUN_0084a880(pform);
                apLoadGameBuffer->SetForm(0);
                apLoadGameBuffer->SetChangeFlags(0);
                pform = 0;
                pref = 0;
            }
        }
        pcell = 0;
        TESWorldSpace* pworld = 0;
        refData.GetCellAndWorld(pcell, pworld);
        if ((pcell && g_TES->IsCellBuffered(pcell, false)) || (refData.cFlags & 2))
        {
            if (einitialDataType == 5)
            {
                if (pform)
                {
                    ChangeFlagsT iunrevertibleChanges =
                        ChangeFlagsT::HasFormChanged(ioldChangeFlags, ichangeFlags, eformType, true);
                    if (iunrevertibleChanges.FUN_00559450())
                    {
                        DeleteForm(pform);
                        pform = 0;
                        apLoadGameBuffer->SetChangeFlags(0);
                    }
                }
                pform = ResolveReferenceForm(iformID, &refData, pform);
                if (pform)
                    apLoadGameBuffer->SetForm(pform);
                else
                    apLoadGameBuffer->FUN_00848d90(true);
            }
            else if (einitialDataType == 6 && !pform)
            {
                refData.FUN_0084e6a0(pcell, pworld);
                if (pcell)
                    (*(ReconstructFormsH**)((char*)this + 0x20))->FUN_00843750(pcell, iformID, false);
                else
                    (*(ReconstructFormsH**)((char*)this + 0x20))
                        ->FUN_008438b0(pworld, refData.m_iGridPositionX, refData.m_iGridCoordinateY, iformID, false);
                apLoadGameBuffer->CombineFlags(true);
                apLoadGameBuffer->FUN_0084a360(true);
            }
        }
        else if (!pref || (!pref->GetReferencePersistence() && pref != g_thePlayer))
        {
            if (pcell && ((TESObjectCELLH*)pcell)->IsInterior())
            {
                ((ReferencesMapH*)m_pReferencesMap)->ForwardToMember(refData.iLocationFormID, iformID);
                if (einitialDataType == 6)
                    ((ReferencesMapH*)m_pReferencesMap)->SetAtKey(iformID);
            }
            else if (pworld)
            {
                ((ReferencesMapH*)m_pReferencesMap)
                    ->AddReferenceToCell(refData.iLocationFormID, iformID, &refData.kTargetPoint);
                if (einitialDataType == 6)
                    ((ReferencesMapH*)m_pReferencesMap)->SetAtKey(iformID);
            }
            else
            {
                LogWarning(
                    "CELLS: Worldspace or Cell %08X could not be found while loading a %s reference.  Its loading will be skipped.",
                    refData.iLocationFormID, einitialDataType == 5 ? "created" : "moved");
                apLoadGameBuffer->FUN_00848d90(true);
            }
            if (pref)
            {
                if (pref->GetParentCell())
                    ((TESObjectCELLH*)pref->GetParentCell())->RemoveReference(pref);
                DeleteForm(pform);
                pform = 0;
                apLoadGameBuffer->SetForm(0);
            }
        }
    }
    else
    {
        int eoldInitialDataType =
            BGSSaveLoadInitialDataPacket::DetermineInitialDataType(iformID, eformType, ioldChangeFlags);
        if (eoldInitialDataType == 6)
        {
            if (!pform)
            {
                FormBufferContext unloadedFormBuffer = ((ChangesMapH*)m_pFormChangesMap)->FUN_00845760(iformID);
                if (unloadedFormBuffer.FUN_00559450())
                {
                    FormIDConverter* pcurrentFormIDMap = *(FormIDConverter**)((char*)this + 8);
                    *(FormIDConverter**)((char*)this + 8) = apOldFormIDMap;
                    ReferencePlacementData refData;
                    FUN_0084e930(unloadedFormBuffer.FUN_00866390(), eoldInitialDataType, &refData);
                    TESObjectCELL* pcell = 0;
                    TESWorldSpace* pworld = 0;
                    refData.FUN_0084e6a0(pcell, pworld);
                    if (pcell && g_TES->IsCellBuffered(pcell, false))
                    {
                        (*(ReconstructFormsH**)((char*)this + 0x20))->FUN_00843750(pcell, iformID, false);
                        apLoadGameBuffer->CombineFlags(true);
                        apLoadGameBuffer->FUN_0084a360(true);
                    }
                    *(FormIDConverter**)((char*)this + 8) = pcurrentFormIDMap;
                }
            }
            else if (((TESObjectREFR*)pform)->IsReference())
            {
                TESObjectREFR* pref = (TESObjectREFR*)pform;
                if (!pref->GetReferencePersistence())
                {
                    TESForm* pspace = 0;
                    NiPoint3 loc = NiPoint3::ZERO;
                    NiPoint3 angle = NiPoint3::ZERO;
                    bool bdeleteRef = false;
                    if (!pref->GetStartingPosition(&loc, &angle, &pspace, 0))
                    {
                        bdeleteRef = true;
                    }
                    else
                    {
                        TESObjectCELL* pcell = 0;
                        if (((TESFormH*)pspace)->GetFormType() == 0x41)
                        {
                            TESWorldSpace* pworld = (TESWorldSpace*)pspace;
                            pcell = pworld->GetCellByWorldPosition(loc);
                        }
                        else
                        {
                            pcell = (TESObjectCELL*)pspace;
                        }
                        if (!pcell || !g_TES->IsCellBuffered(pcell, false))
                            bdeleteRef = true;
                    }
                    if (bdeleteRef)
                    {
                        DeleteForm(pform);
                        apLoadGameBuffer->SetForm(0);
                        apLoadGameBuffer->SetChangeFlags(0);
                        pform = 0;
                    }
                }
            }
        }
    }
    return idataSizeLoaded;
}
}  // namespace fnv_00849d00

struct FUN_00847d00_shell
{
    char pad[0x244];
    int m_244;
    void SetFlag4(bool set);
};

// @fnv 0x00847d00
void FUN_00847d00_shell::SetFlag4(bool set)
{
    if (set)
        m_244 |= 4;
    else
        m_244 &= ~4;
}

struct FUN_00848d90_shell
{
    unsigned int pad[10];  // 0x00 - 0x27
    unsigned int m_flags;  // 0x28 - 0x2B
    void __thiscall FUN_00848d90(bool value);
};

// Sets or clears bit 0 of m_flags according to value.
// @fnv 0x00848d90
void __thiscall FUN_00848d90_shell::FUN_00848d90(bool abSet)
{
    if (abSet)
        m_flags |= 1;
    else
        m_flags &= ~1;
}

void* __cdecl operator new(unsigned int);
extern BGSSaveLoadGame* g_BGSSaveLoadGame;
void __cdecl FUN_008535e0();

struct FUN_00846f30 : BGSSaveLoadGame
{
    FUN_00846f30();
};

// Allocates a new FUN_00846f30 instance, stores it in g_BGSSaveLoadGame, then calls FUN_008535e0.
// @fnv 0x00847480
void CreateSaveLoadGame()
{
    g_BGSSaveLoadGame = new FUN_00846f30;
    FUN_008535e0();
}

extern BGSSaveLoadGame* g_BGSSaveLoadGame;

struct FUN_00847540_shell
{
    BGSSaveLoadGame* __thiscall FUN_00847540(int arg1);
};

// Calls FUN_00847540(1) on g_BGSSaveLoadGame if set, then clears g_BGSSaveLoadGame to null.
// @fnv 0x00847500
void FUN_00847500()
{
    BGSSaveLoadGame* local2 = g_BGSSaveLoadGame;
    BGSSaveLoadGame* local_c = local2;
    BGSSaveLoadGame* local_4;
    if (local_c)
    {
        local_4 = ((FUN_00847540_shell*)local_c)->FUN_00847540(1);
    }
    else
    {
        local_4 = 0;
    }
    g_BGSSaveLoadGame = 0;
}

class TESFile
{
  public:
    const char* GetName();
};
class BGSSaveGameBuffer
{
  public:
    BGSSaveGameBuffer();
    ~BGSSaveGameBuffer();
    void SaveData(void* apData, int aiSize, int aiEndian);
    void SaveGameString(const char* apString, int aiFlags);
    void FUN_00865c40(void* apFile);
    unsigned int data[5];
};

struct FUN_00847590_shell : public BGSSaveLoadGame
{
    void SaveCompiledFileList(void* apFile);
};

// @fnv 0x00847590
void FUN_00847590_shell::SaveCompiledFileList(void* apFile)
{
    BGSSaveGameBuffer buffer;
    BGSSaveGameBuffer* pbuffer = &buffer;
    unsigned char ucFileCount = reinterpret_cast<TESDataHandlerSaveLoad*>(g_dataHandler)->GetCompiledFileCount();
    pbuffer->SaveData(&ucFileCount, 1, 0);
    for (unsigned int i = 0; i < ucFileCount; ++i)
    {
        TESFile* pFile = reinterpret_cast<TESDataHandlerSaveLoad*>(g_dataHandler)->GetCompiledFileByIndex(i);
        const char* pFileName = pFile->GetName();
        pbuffer->SaveGameString(pFileName, 0);
    }
    buffer.FUN_00865c40(apFile);
}

struct FUN_00849ca0_shell
{
    void __thiscall FUN_00849ca0(int state);
    void __thiscall GetElementAt(int state);
};

// @fnv 0x00849ca0
void __thiscall FUN_00849ca0_shell::FUN_00849ca0(int state)
{
    ((FUN_00849ca0_shell*)((char*)this + 0x10))->GetElementAt(state);
}

struct TESSaveLoadGame
{
    void ReadTypedData(void*, unsigned int);
    void FUN_0085f010(void*, unsigned int);
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
// @fnv 0x0049ab00
void __cdecl ReadAndDispatchSaveData(void* apData)
{
    unsigned short s;
    g_TESSaveLoadGame->ReadTypedData(&s, 2);
    if (s)
        g_TESSaveLoadGame->FUN_0085f010(apData, s);
}

struct H471F0
{
    void FUN_008471f0();
};
void _Deallocate(void*);
struct H47540
{
    void* FUN_00847540(unsigned int);
};
// Calls FUN_008471f0 on this, frees this with _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x00847540
void* H47540::FUN_00847540(unsigned int flags)
{
    ((H471F0*)this)->FUN_008471f0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct CF845
{
    int field0;
    CF845(int);
    CF845 FUN_00847cd0(int);
};
// @fnv 0x00847cd0
CF845 CF845::FUN_00847cd0(int a)
{
    return CF845(~a & field0);
}

struct S00852950
{
    void GetOrCreateEntryAdd(int, int);
};
struct S00849a70
{
    int _pad[4];
    S00852950 _m;
    void ForwardToMember(int, int);
};
// Calls GetOrCreateEntryAdd on the member _m, forwarding both integer arguments.
// @fnv 0x00849a70
void S00849a70::ForwardToMember(int aiFirst, int aiSecond)
{
    _m.GetOrCreateEntryAdd(aiFirst, aiSecond);
}

struct Class_0084a700
{
    int _00;
    BGSSaveLoadChangesMap* _04;
    bool HasChangeForForm(TESForm*, FormChangeMask);
};
// If the changes map is set, checks whether it records a change for the form's FormID with the given value; otherwise returns false.
// @fnv 0x0084a700
bool Class_0084a700::HasChangeForForm(TESForm* pForm, FormChangeMask b)
{
    if (_04 != 0)
        return _04->ContainsChangeFlags(pForm->GetFormID(), b);
    return 0;
}

namespace fnv_0084a840 {
struct FUN_00848ca0_shell
{
    void FUN_00848ca0(bool);
};
void __cdecl BGSSaveLoadHistory_Destroy(unsigned char);
struct FUN_00848e70_shell
{
    void FUN_00848e70(int, int);
};
struct FUN_0084a840_shell : BGSSaveLoadGame
{
    void FUN_0084a840();
};
// @fnv 0x0084a840
void FUN_0084a840_shell::FUN_0084a840()
{
    ((FUN_00848ca0_shell*)this)->FUN_00848ca0(true);
    BGSSaveLoadHistory_Destroy(1);
    ((FUN_00848e70_shell*)this)->FUN_00848e70(0, 0);
    ClearFormChanges();
    ((FUN_00848ca0_shell*)this)->FUN_00848ca0(false);
}
}  // namespace fnv_0084a840

void* __cdecl _GetFormByNumericID(unsigned int);
struct FUN_0084a880_shell
{
    void FUN_0084a880(void*);
};
struct FUN_0084a9c0_shell
{
    void LookupFormByID(unsigned int);
};
// Resolves the form for the given numeric ID and forwards it to FUN_0084a880 on this object.
// @fnv 0x0084a9c0
void FUN_0084a9c0_shell::LookupFormByID(unsigned int a1)
{
    ((FUN_0084a880_shell*)this)->FUN_0084a880(_GetFormByNumericID(a1));
}

struct Fake0084
{
    virtual int v0();
    virtual int v1();
    virtual int v2();
    virtual int v3();
    virtual int v4(int);
};
struct Holder0084
{
    void CallVirtualWithOne(Fake0084* p);
};
// Calls v4(1) on the passed object if it is non-null.
// @fnv 0x0084a9f0
void Holder0084::CallVirtualWithOne(Fake0084* apObject)
{
    Fake0084* b = apObject;
    Fake0084* a = b;
    a ? a->v4(1) : 0;
}

struct SaveLoadChangeHistory
{
    void AddNoteWithArguments(char const*, char*);
};
struct FUN_0084ab00_This
{
    char _pad[0x1c];
    SaveLoadChangeHistory* m_pNoteHandler;
    void FUN_0084ab00(const char*, char*);
};
// @fnv 0x0084ab00
void FUN_0084ab00_This::FUN_0084ab00(const char* apText, char* aList)
{
    m_pNoteHandler->AddNoteWithArguments(apText, aList);
}

struct FUN_0084ba20
{
    virtual ~FUN_0084ba20();
};
struct FUN_0084b9c0 : public FUN_0084ba20
{
    virtual ~FUN_0084b9c0();
};
// Destructor that clears all entries from the object's pointer map via RemoveAll.
// @fnv 0x0084b9c0
FUN_0084b9c0::~FUN_0084b9c0()
{
    ((NiTPointerMap<unsigned int, unsigned int>*)this)->RemoveAll();
}

struct FUN_00849a50_shell : BGSSaveLoadChangesMap
{
    void SetAtKey(unsigned int key);
};

// @fnv 0x00849a50
void FUN_00849a50_shell::SetAtKey(unsigned int key)
{
    ((NiTPointerMap<unsigned int, FormChangeRecord*>*)this)->SetAt(key, (FormChangeRecord*)key);
}

struct FUN_0084a360_shell
{
    char pad[0x28];
    unsigned int m_flags;
    void FUN_0084a360(bool value);
};

// @fnv 0x0084a360
void FUN_0084a360_shell::FUN_0084a360(bool abSet)
{
    if (abSet)
        m_flags |= 2;
    else
        m_flags &= ~2;
}

struct DummyPointerMap
{
    bool GetAt(unsigned int, unsigned int&) const;
    void SetAt(unsigned int, unsigned int);
};
void __cdecl _fnv_call_845cc0(const char*, ...);
struct FakeGame
{
    char _pad[0x18];
    DummyPointerMap* pMap;
    void SetFormIDMapping(unsigned int aiOldFormID, unsigned int aiNewFormID);
};
// @fnv 0x0084aa30
void FakeGame::SetFormIDMapping(unsigned int aiOldFormID, unsigned int aiNewFormID)
{
    unsigned int uiExistingFormID = 0;
    if (pMap->GetAt(aiOldFormID, uiExistingFormID))
        _fnv_call_845cc0(
            "FORMS: Trying to set new form ID %08X for old form ID %08X, but already in map with value %08X",
            aiNewFormID, aiOldFormID, uiExistingFormID);
    pMap->SetAt(aiOldFormID, aiNewFormID);
}

class AutoMemContext
{
  public:
    AutoMemContext(MEM_CONTEXT aeContext, bool abPush, const char* apFile, int aiLine);
    ~AutoMemContext();
    int iPrevContext;
};

class TESObjectREFR : public TESForm
{
  public:
    virtual void V78();
    virtual void V79();
    virtual void V80();
    virtual void V81();
    virtual void V82();
    virtual void V83();
    virtual void V84();
    virtual void V85();
    virtual void V86();
    virtual void V87();
    virtual void V88();
    virtual void V89();
    virtual void V90();
    virtual void V91();
    virtual void V92();
    virtual void V93();
    virtual void V94();
    virtual void V95();
    virtual void V96();
    virtual void V97();
    virtual void V98();
    virtual void V99();
    virtual void V100();
    virtual void V101();
    virtual void V102();
    virtual void V103();
    virtual void V104();
    virtual void V105();
    virtual void V106();
    virtual void V107();
    virtual void V108();
    virtual void V109();
    virtual void V110();
    virtual void V111();
    virtual void V112();
    virtual void V113();
    virtual void V114();
    virtual void V115();
    virtual void V116();
    virtual void V117();
    virtual void V118();
    virtual void V119();
    virtual void V120();
    virtual void V121();
    virtual void V122();
    virtual void V123();
    virtual void V124();
    virtual NiPoint3* GetPos();
    TESObjectCELL* GetParentCell();
};

class TESWorldSpace : public TESForm
{
};

struct UnloadFlags
{
    unsigned int flags;
    UnloadFlags(unsigned int auiFlags);
    unsigned int FUN_00559450() const;
    UnloadFlags FUN_00847cd0(unsigned int auiFlags);
};

struct UnloadFormBuffer
{
    void* vtbl;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    UnloadFormBuffer();
    ~UnloadFormBuffer();
    void InitFormEntry(unsigned int auiFormID, UnloadFlags aFlags, int aiFormType, int aiVersion);
    void FUN_0050f9c0(TESForm* apForm);
    UnloadFlags FUN_00428110();
};

struct UnloadChangeData
{
    UnloadFlags flags;
    void InitFromInput(UnloadFormBuffer* apBuffer);
    unsigned int FUN_00559450() const;
};

struct UnloadChanges
{
    UnloadFlags flags;
    UnloadChangeData data;
};

struct UnloadChangesMap
{
    UnloadChanges* FUN_009a4250(unsigned int auiFormID);
    bool FUN_00845a80(unsigned int auiFormID, UnloadFlags aFlags);
};

struct UnloadRefsMap
{
    void ForwardToMember(unsigned int auiCellID, unsigned int auiFormID);
    void SetAtKey(unsigned int auiFormID);
    void AddReferenceToCell(unsigned int auiWorldID, unsigned int auiFormID, const NiPoint3& arPos);
};

struct UnloadManager
{
    int GetConstant27();
};
extern UnloadManager* DAT_011de134;

bool __fastcall FUN_004226e0(TESDataHandler*);
void __cdecl FUN_00845cc0(const char*, ...);
int __fastcall FNV_GetFormType(TESForm*);
int __cdecl FUN_0084eb80(UnloadFormBuffer*, TESForm*, UnloadFlags);
TESWorldSpace* __fastcall FUN_00575d70(TESObjectREFR*);
bool __fastcall FUN_00425fd0(TESObjectCELL*);

struct SLGameShell : public BGSSaveLoadGame
{
    bool FUN_00849a90(TESForm* apForm);
    void FUN_00849730(TESForm* apForm, bool abForce);
};

// Unloads a form into an UnloadFormBuffer, updates its change data, and records reference cell/worldspace info for reference forms.
// @fnv 0x00849730
void SLGameShell::FUN_00849730(TESForm* apForm, bool abForce)
{
    AutoMemContext m_uiMemoryContext(
        MEM_CONTEXT_MEM_CONTEXT_SAVELOAD, true,
        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Misc\\SaveLoad\\BGSSaveLoadGame.cpp", 894);
    if (FUN_0042ce10() && !abForce)
        return;
    if (FUN_004226e0(g_dataHandler))
        return;
    if (!FUN_00849a90(apForm))
        return;

    unsigned int auiFormId = apForm->GetFormID();
    UnloadChanges* changes = ((UnloadChangesMap*)m_pFormChangesMap)->FUN_009a4250(auiFormId);
    if (changes)
    {
        if (changes->data.FUN_00559450())
        {
            FUN_00845cc0(
                "FORMS: Form '%s' (%08X) is unloading, but it already has a buffer.  This unload will be skipped.",
                apForm->GetName(), auiFormId);
            return;
        }

        UnloadFormBuffer buffer;
        buffer.InitFormEntry(auiFormId, changes->flags, FNV_GetFormType(apForm), DAT_011de134->GetConstant27());
        buffer.FUN_0050f9c0(apForm);
        apForm->Unk_20(&buffer);
        UnloadFlags remainingFlags = changes->flags.FUN_00847cd0(buffer.FUN_00428110().FUN_00559450());
        if (remainingFlags.FUN_00559450() &&
            ((UnloadChangesMap*)m_pFormChangesMap)->FUN_00845a80(auiFormId, remainingFlags))
            return;

        int type = FUN_0084eb80(&buffer, apForm, changes->flags);
        apForm->Unk_15(&buffer);
        changes->data.InitFromInput(&buffer);
        if (type == 5 || type == 6)
        {
            TESObjectREFR* ref = (TESObjectREFR*)apForm;
            TESObjectCELL* cell = ref->GetParentCell();
            TESWorldSpace* world = FUN_00575d70(ref);
            if (cell && FUN_00425fd0(cell))
            {
                ((UnloadRefsMap*)m_pReferencesMap)->ForwardToMember(((TESForm*)cell)->GetFormID(), auiFormId);
                if (type == 6)
                    ((UnloadRefsMap*)m_pReferencesMap)->SetAtKey(auiFormId);
            }
            else if (world)
            {
                ((UnloadRefsMap*)m_pReferencesMap)->AddReferenceToCell(world->GetFormID(), auiFormId, *ref->GetPos());
                if (type == 6)
                    ((UnloadRefsMap*)m_pReferencesMap)->SetAtKey(auiFormId);
            }
            else
            {
                FUN_00845cc0("FORMS: No Worldspace or Cell could not be found while unloading reference '%s' (%08X)",
                             ref->GetName(), auiFormId);
            }
        }
    }
}

class FUN_00849a90_Iface
{
  public:
    virtual unsigned char vSlot000();
    virtual unsigned char vSlot001();
    virtual unsigned char vSlot002();
    virtual unsigned char vSlot003();
    virtual unsigned char vSlot004();
    virtual unsigned char vSlot005();
    virtual unsigned char vSlot006();
    virtual unsigned char vSlot007();
    virtual unsigned char vSlot008();
    virtual unsigned char vSlot009();
    virtual unsigned char vSlot010();
    virtual unsigned char vSlot011();
    virtual unsigned char vSlot012();
    virtual unsigned char vSlot013();
    virtual unsigned char vSlot014();
    virtual unsigned char vSlot015();
    virtual unsigned char vSlot016();
    virtual unsigned char vSlot017();
    virtual unsigned char vSlot018();
    virtual unsigned char vSlot019();
    virtual unsigned char vSlot020();
    virtual unsigned char vSlot021();
    virtual unsigned char vSlot022();
    virtual unsigned char vSlot023();
    virtual unsigned char vSlot024();
    virtual unsigned char vSlot025();
    virtual unsigned char vSlot026();
    virtual unsigned char vSlot027();
    virtual unsigned char vSlot028();
    virtual unsigned char vSlot029();
    virtual unsigned char vSlot030();
    virtual unsigned char vSlot031();
    virtual unsigned char vSlot032();
    virtual unsigned char vSlot033();
    virtual unsigned char vSlot034();
    virtual unsigned char vSlot035();
    virtual unsigned char vSlot036();
    virtual unsigned char vSlot037();
    virtual unsigned char vSlot038();
    virtual unsigned char vSlot039();
    virtual unsigned char vSlot040();
    virtual unsigned char vSlot041();
    virtual unsigned char vSlot042();
    virtual unsigned char vSlot043();
    virtual unsigned char vSlot044();
    virtual unsigned char vSlot045();
    virtual unsigned char vSlot046();
    virtual unsigned char vSlot047();
    virtual unsigned char vSlot048();
    virtual unsigned char vSlot049();
    virtual unsigned char vSlot050();
    virtual unsigned char vSlot051();
    virtual unsigned char vSlot052();
    virtual unsigned char vSlot053();
    virtual unsigned char vSlot054();
    virtual unsigned char vSlot055();
    virtual unsigned char vSlot056();
    virtual unsigned char vSlot057();
    virtual unsigned char vSlot058();
    virtual unsigned char vSlot059();
    virtual unsigned char vSlot060();
    virtual unsigned char vSlot061();
    virtual unsigned char vSlot062();
    virtual unsigned char vSlot063();
    virtual unsigned char vSlot064();
    virtual unsigned char vSlot065();
    virtual unsigned char vSlot066();
    virtual unsigned char vSlot067();
    virtual unsigned char vSlot068();
    virtual unsigned char vSlot069();
    virtual unsigned char vSlot070();
    virtual unsigned char vSlot071();
    virtual unsigned char vSlot072();
    virtual unsigned char vSlot073();
    virtual unsigned char vSlot074();
    virtual unsigned char vSlot075();
    virtual unsigned char vSlot076();
    virtual unsigned char vSlot077();
    virtual unsigned char vSlot078();
    virtual unsigned char vSlot079();
    virtual unsigned char vSlot080();
    virtual unsigned char vSlot081();
    virtual unsigned char vSlot082();
    virtual unsigned char vSlot083();
    virtual unsigned char vSlot084();
    virtual unsigned char vSlot085();
    virtual unsigned char vSlot086();
    virtual unsigned char vSlot087();
    virtual unsigned char vSlot088();
    virtual unsigned char vSlot089();
    virtual unsigned char vSlot090();
    virtual unsigned char vSlot091();
    virtual unsigned char vSlot092();
    virtual unsigned char vSlot093();
    virtual unsigned char vSlot094();
    virtual unsigned char vSlot095();
    virtual unsigned char vSlot096();
    virtual unsigned char vSlot097();
    virtual unsigned char vSlot098();
    virtual unsigned char vSlot099();
    virtual unsigned char vSlot100();
    virtual unsigned char vSlot101();
    virtual unsigned char vSlot102();
    virtual unsigned char vSlot103();
    virtual unsigned char vSlot104();
    virtual unsigned char vSlot105();
    virtual unsigned char vSlot106();
    virtual unsigned char vSlot107();
    virtual unsigned char vSlot108();
    virtual unsigned char vSlot109();
    virtual unsigned char vSlot110();
    virtual unsigned char vSlot111();
    virtual unsigned char vSlot112();
    virtual unsigned char vSlot113();
    virtual unsigned char vSlot114();
    virtual unsigned char vSlot115();
    virtual unsigned char vSlot116();
    virtual unsigned char vSlot117();
    virtual unsigned char vSlot118();
    virtual unsigned char vSlot119();
    virtual unsigned char vSlot120();
    virtual unsigned char vSlot121();
    virtual unsigned char vSlot122();
    virtual unsigned char vSlot123();
    virtual unsigned char vSlot124();
    virtual unsigned char vSlot125();
    virtual unsigned char vSlot126();
    virtual unsigned char vSlot127();
    virtual unsigned char vSlot128();
    virtual unsigned char vSlot129();
    virtual unsigned char vSlot130();
    virtual unsigned char vSlot131();
    virtual unsigned char vSlot132();
    virtual unsigned char vSlot133();
    virtual unsigned char vSlot134();
    virtual unsigned char vSlot135();
    virtual unsigned char vSlot136();
    virtual unsigned char vSlot137();
    virtual unsigned char vSlot138();
    virtual unsigned char vSlot139();
    virtual unsigned char vSlot140();
    virtual unsigned char vSlot141();
    virtual unsigned char vSlot142();
    virtual unsigned char vSlot143();
    virtual unsigned char vSlot144();
    virtual unsigned char vSlot145();
    virtual unsigned char vSlot146();
    virtual unsigned char vSlot147();
    virtual unsigned char vSlot148();
    virtual unsigned char vSlot149();
    virtual unsigned char vSlot150();
    virtual unsigned char vSlot151();
    virtual unsigned char vSlot152();
    virtual unsigned char vSlot153();
    virtual unsigned char vSlot154();
    virtual unsigned char vSlot155();
    virtual unsigned char vSlot156();
    virtual unsigned char vSlot157();
    virtual unsigned char vSlot158();
    virtual unsigned char vSlot159();
    virtual unsigned char vSlot160();
    virtual unsigned char vSlot161();
    virtual unsigned char vSlot162();
    virtual unsigned char vSlot163();
    virtual unsigned char vSlot164();
    virtual unsigned char vSlot165();
    virtual unsigned char vSlot166();
    virtual unsigned char vSlot167();
    virtual unsigned char vSlot168();
    virtual unsigned char vSlot169();
    virtual unsigned char vSlot170();
    virtual unsigned char vSlot171();
    virtual unsigned char vSlot172();
    virtual unsigned char vSlot173();
    virtual unsigned char vSlot174();
    virtual unsigned char vSlot175();
    virtual unsigned char vSlot176();
    virtual unsigned char vSlot177();
    virtual unsigned char vSlot178();
    virtual unsigned char vSlot179();
    virtual unsigned char vSlot180();
    virtual unsigned char vSlot181();
    virtual unsigned char vSlot182();
    virtual unsigned char vSlot183();
    virtual unsigned char vSlot184();
    virtual unsigned char vSlot185();
    virtual unsigned char vSlot186();
    virtual unsigned char vSlot187();
    virtual unsigned char vSlot188();
    virtual unsigned char vSlot189();
    virtual unsigned char vSlot190();
    virtual unsigned char vSlot191();
    virtual unsigned char vSlot192();
    virtual unsigned char vSlot193();
    virtual unsigned char vSlot194();
    virtual unsigned char vSlot195();
    virtual unsigned char vSlot196();
    virtual unsigned char vSlot197();
    virtual unsigned char vSlot198();
    virtual unsigned char vSlot199();
    virtual unsigned char vSlot200();
    virtual unsigned char vSlot201();
    unsigned char Probe77c0();
};

class FUN_00849a90_cls
{
  public:
    bool FUN_00849a90(void* obj);
};

// Returns false if obj's Probe77c0 is nonzero, or if vSlot060 is nonzero and either vSlot137 is nonzero with vSlot201 zero; otherwise true.
// @fnv 0x00849a90
bool FUN_00849a90_cls::FUN_00849a90(void* pObject)
{
    FUN_00849a90_Iface* first;
    FUN_00849a90_Iface* second;
    if (((FUN_00849a90_Iface*)pObject)->Probe77c0() != 0)
    {
        return false;
    }
    if (((FUN_00849a90_Iface*)pObject)->vSlot060() != 0)
    {
        first = (FUN_00849a90_Iface*)pObject;
        if (first->vSlot137() != 0)
        {
            second = first;
            if (second->vSlot201() == 0)
            {
                return false;
            }
        }
    }
    return true;
}

struct ValueBase
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual double v3(unsigned int a);
};

struct ParamOwner
{
    char* GetHolderBase();
    unsigned int FUN_0084e3a0(ParamOwner* a);
};

struct Sub34
{
    void FUN_00844700(unsigned int v);
};

struct Outer
{
    char _pad[0x34];
    Sub34 m_34;
    void FUN_0084a520(ParamOwner* p);
};

extern const double DAT_01012060;

// Calls v3(0x10) on the ValueBase at p's holder base + 0x100 and, if the result exceeds DAT_01012060, calls m_34.FUN_00844700 with p->FUN_0084e3a0(p).
// @fnv 0x0084a520
void Outer::FUN_0084a520(ParamOwner* apOwner)
{
    if (((ValueBase*)(apOwner->GetHolderBase() + 0x100))->v3(0x10) > DAT_01012060)
    {
        m_34.FUN_00844700(apOwner->FUN_0084e3a0(apOwner));
    }
}

struct Position
{
    float x, y, z;
};
extern const Position NiPoint3_ZERO;
extern BGSSaveLoadGame* g_BGSSaveLoadGame;
struct UpdateInfo
{
    float time;
    bool updateControllers;
    bool multithread;
    bool unk06;
    bool unk07;
    bool unk08;
    UpdateInfo(float, bool, bool);
};
struct Scene
{
    void SetPosition(const Position*);
    void Refresh();
    void Update(UpdateInfo&);
};
struct ScenePointer
{
    Scene* Get();
};
struct LoadedData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    ScenePointer node;
};
struct World
{
    void Remove(void*);
    void Insert(void*);
};
struct Reference
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
    virtual void Mark(int);
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
    virtual void Slot76();
    virtual void Slot77();
    virtual void GetFallback(Position*, Position*, int*, int);
    virtual void Slot79();
    virtual void Slot80();
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
    virtual Scene* GetScene();
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
    Position position;
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
    LoadedData* loaded;
    bool IsExterior();
    void FUN_00575830(Position* input);
};
bool IsPersistent(void*);
World* __fastcall FindWorld(Reference*);
void UpdateScene(Scene*, bool);
// Validates the input position against world bounds, falls back to GetFallback when invalid, removes/reinserts the reference in its world, and updates the scene.
// @fnv 0x00575830
void Reference::FUN_00575830(Position* apPosition)
{
    bool changedVal = false;
    Position fallbackX = NiPoint3_ZERO;
    Position anglesB = NiPoint3_ZERO;
    if (g_BGSSaveLoadGame && g_BGSSaveLoadGame->FUN_0042ce10())
    {
        bool unusedFlag7 = false;
        if (apPosition->x == 3.4028234663852886e38 || apPosition->x == -3.4028234663852886e38 ||
            apPosition->y == 3.4028234663852886e38 || apPosition->y == -3.4028234663852886e38 ||
            apPosition->z == 3.4028234663852886e38 || apPosition->z == -3.4028234663852886e38 ||
            !(apPosition->x < 4096000.0 && apPosition->x > -4096000.0 && apPosition->y < 4096000.0 &&
              apPosition->y > -4096000.0))
        {
            int cell8 = 0;
            GetFallback(&fallbackX, &anglesB, &cell8, 0);
            fallbackX.z += 10.0;
            changedVal = true;
        }
    }
    else
    {
        if (apPosition->x > 4096000.0 || apPosition->x < -4096000.0 || apPosition->y > 4096000.0 ||
            apPosition->y < -4096000.0)
        {
            Position angles = NiPoint3_ZERO;
            int parent3 = 0;
            GetFallback(&fallbackX, &angles, &parent3, 0);
            fallbackX.z += 10.0;
            changedVal = true;
        }
    }
    World* world7 = 0;
    if (IsExterior() && IsPersistent(this))
    {
        world7 = FindWorld(this);
        if (world7)
            world7->Remove(this);
    }
    if (!changedVal)
        position = *apPosition;
    else
    {
        position = fallbackX;
        if (GetScene())
        {
            GetScene()->SetPosition(&fallbackX);
            UpdateScene(loaded->node.Get(), true);
            loaded->node.Get()->Refresh();
            UpdateInfo info(0.0f, false, false);
            loaded->node.Get()->Update(info);
        }
    }
    if (world7)
        world7->Insert(this);
    Mark(2);
}

void* __cdecl memset(void*, int, unsigned int);
int __cdecl _stricmp(const char*, const char*);
void __cdecl FUN_00845cc0(const char*, ...);

struct SaveFileEntry
{
    const char* GetFilename();
};
struct SaveDataHandler
{
    unsigned char GetCompiledFileCount();
    SaveFileEntry* GetCompiledFileByIndex(unsigned int index);
};
struct LoadGameBuffer
{
    LoadGameBuffer();
    ~LoadGameBuffer();
    void Open(void* apData);
    void ReadTypedData(void* apData, unsigned int auiSize);
    char* LoadString(char* apBuffer);
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
};

struct SaveLoadFileIndexMap
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
    unsigned char aSaveToLoaded[255];
    unsigned char aLoadedToSave[255];
    bool ReadFileIndexMap(void* apData);
};

// Reads a count and file names from apData, maps each name to a compiled save file index, and returns false if any name is not found.
// @fnv 0x00847660
bool SaveLoadFileIndexMap::ReadFileIndexMap(void* apData)
{
    unsigned char cFileCount2 = ((SaveDataHandler*)g_dataHandler)->GetCompiledFileCount();
    LoadGameBuffer kBuffer;
    kBuffer.Open(apData);
    LoadGameBuffer* pBuffer4 = &kBuffer;
    bool bResult2 = true;
    memset(aSaveToLoaded, 0xff, 0xff);
    memset(aLoadedToSave, 0xff, 0xff);
    unsigned char cCount4 = 0;
    pBuffer4->ReadTypedData(&cCount4, 1);
    for (unsigned int aI = 0; aI < cCount4; aI++)
    {
        char acName[260];
        pBuffer4->LoadString(acName);
        bool bFound = false;
        for (unsigned int jA = 0; jA < cFileCount2; jA++)
        {
            SaveFileEntry* _pFile = ((SaveDataHandler*)g_dataHandler)->GetCompiledFileByIndex(jA);
            if (!_stricmp(acName, _pFile->GetFilename()))
            {
                aSaveToLoaded[aI] = jA;
                aLoadedToSave[jA] = aI;
                bFound = true;
                break;
            }
        }
        if (!bFound)
        {
            bResult2 = false;
            aSaveToLoaded[aI] = 0xff;
            FUN_00845cc0("SAVELOAD: Cannot find file %s referenced in the save game.  Errors may result.", acName);
        }
    }
    return bResult2;
}

namespace fnv_00847850 {
struct W20File
{
    char* _ref_006815c0();
    unsigned int FUN_00846400();
    void WriteToFile(void*, int);
    void FUN_00846440(unsigned int);
};
struct W20Manager
{
    void EnsureFosExtension(char*, char*);
    void FUN_00851120(char*, int);
    unsigned int GetConstant27();
};
struct W20Flags
{
    unsigned int value;
    unsigned int FUN_00559450();
    W20Flags FUN_00847cd0(unsigned int);
    void FUN_00866200(W20File*, unsigned int, W20Flags);
};
struct W20Change
{
    W20Flags flags;
    W20Flags savedFlags;
};
struct W20Buffer;
struct W20Form
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
    virtual void v54(W20Buffer*);
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
    virtual void v80(W20Buffer*);
    int FNV_GetFormType();
};
struct W20Map
{
    void* GetFirstPos();
    void GetNext(void*&, unsigned int&, W20Change*&);
    void FUN_008457b0(unsigned int, W20Flags);
    bool FUN_00845a80(unsigned int, W20Flags);
};
struct W20OtherMap
{
    void FUN_00846e00(W20File*);
};
struct W20History
{
    void SaveTo(W20File*);
};
struct W20Header
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
    void ClearObject();
};
struct W20Buffer
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    W20Buffer();
    virtual ~W20Buffer();
    void FUN_00847db0();
    void InitFormEntry(unsigned int, unsigned int, int, unsigned char);
    void SetSpeakerIdle(W20Form*);
    W20Flags FUN_00428110();
    void FUN_00865a30(W20File*);
};
struct W20Save
{
    W20Map* changes;
    unsigned int unk04;
    W20OtherMap* first;
    W20OtherMap* second;
    unsigned int unk10, unk14, unk18;
    W20History* history;
    void SetFlag4(bool);
    void SaveCompiledFileList(W20File*);
    void FUN_00847850(W20File*);
};
extern W20Manager* DAT_011de134;
void FUN_0084dff0(W20History*, const char*, ...);
void FUN_00845cc0(const char*, ...);
void ForwardToShell(W20File*, void*, int);
unsigned int FUN_00847d70(W20File*);
unsigned int FUN_00847d90(W20File*);
W20Form* LookupFormByID(unsigned int);
void FUN_0084eb80(W20Buffer*, W20Form*, unsigned int);

// Writes the save file: logs the save, writes a header, serializes each changed form, then rewrites the header with offsets and sizes.
// @fnv 0x00847850
void W20Save::FUN_00847850(W20File* file)
{
    SetFlag4(true);
    char k[260];
    char ba[260];
    DAT_011de134->EnsureFosExtension(file->_ref_006815c0(), k);
    DAT_011de134->FUN_00851120(ba, 260);
    FUN_0084dff0(history, "***Saving game: %s (%s)", k, ba);
    unsigned char j = DAT_011de134->GetConstant27();
    ForwardToShell(file, &j, 1);
    SaveCompiledFileList(file);
    unsigned int e = file->FUN_00846400();
    W20Header c;
    c.ClearObject();
    file->WriteToFile(&c, 110);
    c.unk08 = file->FUN_00846400();
    c.unk14 = FUN_00847d70(file);
    c.unk0c = file->FUN_00846400();
    W20Buffer l;
    void* p = changes->GetFirstPos();
    while (p)
    {
        unsigned int j = 0;
        W20Change* e = 0;
        changes->GetNext(p, j, e);
        if (e->savedFlags.FUN_00559450())
        {
            e->savedFlags.FUN_00866200(file, j, e->flags);
            c.unk1c++;
        }
        else
        {
            W20Form* form = LookupFormByID(j);
            if (form)
            {
                l.FUN_00847db0();
                l.InitFormEntry(j, e->flags.value, form->FNV_GetFormType(), DAT_011de134->GetConstant27());
                l.SetSpeakerIdle(form);
                form->v80(&l);
                W20Flags k = l.FUN_00428110().FUN_00847cd0(e->flags.FUN_00559450());
                if (k.FUN_00559450())
                    changes->FUN_008457b0(j, k);
                W20Flags ba = e->flags.FUN_00847cd0(l.FUN_00428110().FUN_00559450());
                if (ba.FUN_00559450() && changes->FUN_00845a80(j, ba))
                    continue;
                FUN_0084eb80(&l, form, e->flags.value);
                form->v54(&l);
                l.FUN_00865a30(file);
                c.unk1c++;
            }
            else
                FUN_00845cc0(
                    "SAVELOAD: Could not find form %08X with change flags %08X during BGSSaveLoadGame::SaveGame()", j,
                    e->flags.FUN_00559450());
        }
    }
    c.unk10 = file->FUN_00846400();
    c.unk18 = FUN_00847d90(file);
    c.unk00 = file->FUN_00846400();
    first->FUN_00846e00(file);
    second->FUN_00846e00(file);
    c.unk04 = file->FUN_00846400();
    FUN_0084dff0(history, "---Finished saving game: %s", k);
    history->SaveTo(file);
    file->FUN_00846440(e);
    file->WriteToFile(&c, 110);
    SetFlag4(false);
}
}  // namespace fnv_00847850

struct FUN_00847450
{
    ~FUN_00847450();
};
struct FUN_008473c0
{
    ~FUN_008473c0();
};
struct FUN_0081db60
{
    ~FUN_0081db60();
};
struct SaveFile;
struct FUN_0084ded0
{
    unsigned int vtable, capacity;
    void* entries;
    unsigned int size;
    FUN_0084ded0();
    void* FUN_00847450(unsigned int);
    void FUN_0084e190(SaveFile*);
    void AddAllNotes(FUN_0084ded0*);
};
struct FUN_00846b60
{
    unsigned int vtable, capacity;
    void* entries;
    unsigned int size;
    unsigned int secondVtable, secondCapacity;
    void* secondEntries;
    unsigned int secondSize, flags;
    FUN_00846b60(unsigned int);
    void LoadFormIDMap(SaveFile*);
    void* FUN_008473c0(unsigned int);
};
struct FUN_00845550
{
    unsigned int vtable, capacity;
    void* entries;
    unsigned int size;
    FUN_00845550();
    UnloadFlags GetFirstEntry(unsigned int);
    void FUN_00845a20(unsigned int);
    void ApplyFormQuantityChange(unsigned int, UnloadFlags);
    void SetCombatTargetQuantity(unsigned int, UnloadFlags, unsigned int);
};
struct LoadHeader
{
    unsigned int formOffset, unk04, unk08, unk0c, unk10, firstBlockOffset, lastBlockOffset, formCount, tailOffset;
    unsigned int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58,
        unk5c, unk60, unk64, unk68;
    unsigned short unk6c;
    void ClearObject();
};
struct SaveFile
{
    char* FUN_006815c0(char*);
    void FUN_00846300(void*, unsigned int);
    unsigned int FUN_00846400();
    void FUN_00846440(unsigned int);
    void AdvancePosition(unsigned int);
};
struct FormExtra : TESForm
{
    unsigned int FUN_00401170();
    const char* FUN_00440e30();
    void FUN_0046a010(bool);
};
struct ReferenceExtra : FormExtra
{
    unsigned int FUN_007af430();
};
struct FUN_008c71b0;
struct BGSLoadFormBuffer
{
    virtual void Destroy();
    virtual FormExtra* GetForm();
    unsigned int bufferSize;
    void* buffer;
    unsigned int position5;
    FormExtra* form;
    unsigned int formId, changeFlags, type, version, size, end, loadFlags;
    BGSLoadFormBuffer();
    void FUN_008644b0(SaveFile*);
    unsigned int FUN_008665b0();
    unsigned int FUN_0044edb0();
    UnloadFlags FUN_00428110();
    void FUN_0086cf00(UnloadFlags);
    void FUN_0086cf00(FUN_008c71b0);
    void FUN_007037c0(FormExtra*);
    void FUN_00864580(SaveFile*, unsigned int);
    UnloadFlags FUN_0042ce30();
    void FUN_00848d90(bool);
    void FUN_0042ce50(bool);
    bool FUN_00848dd0();
    void* FUN_0081db60(unsigned int);
    int CheckValueMatchesField(SaveFile*);
    void FUN_00848d50();
};
struct FlagMethods
{
    unsigned int flags;
    void FUN_00841100(unsigned int);
};
struct FUN_008c71b0
{
    unsigned int value;
    FUN_008c71b0(unsigned int);
    FUN_008c71b0(const FUN_008c71b0&);
};
struct FUN_0044dee0
{
    unsigned int formId;
    FUN_0044dee0();
    void ReadBuffer(SaveFile*);
};
struct BufferArray
{
    unsigned int vtable;
    BGSLoadFormBuffer** entries;
    unsigned int capacity, size;
    void FUN_008454f0(bool);
    void FUN_0084b5c0(unsigned int);
    void FUN_007cb2e0(BGSLoadFormBuffer**);
    BGSLoadFormBuffer*& FUN_006a7ad0(unsigned int);
    void FUN_0047a110(unsigned int, BGSLoadFormBuffer* const&);
};
struct FormQueue
{
    void FUN_00843630(FormExtra*, bool);
};
struct ReferenceMap
{
    void FUN_00852b60();
};
struct StatePrefix
{
    FUN_00845550* changes;
    FUN_00845550* previousChanges;
    FUN_00846b60* forms;
    FUN_00846b60* otherForms;
    ReferenceMap* references;
    unsigned int unk14, unk18;
    FUN_0084ded0* state;
    FormQueue* queue;
    BufferArray buffers;
};
struct LoadManagerPrefix
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    struct String
    {
        void FUN_004037f0(char*, unsigned int);
    } name;
};
struct LoadManagerMethods
{
    void EnsureFosExtension(char*);
    void FUN_00851120(char*, unsigned int);
    void FUN_00850c20();
};
struct GlobalTask
{
    void FUN_00c3e310();
};
struct PlayerMethods : TESForm
{
    virtual void Reserved138();
    virtual void Reserved13c();
    virtual void Reserved140();
    virtual void Reserved144();
    virtual void Reserved148();
    virtual void Reserved14c();
    virtual void Reserved150();
    virtual void Reserved154();
    virtual void Reserved158();
    virtual void Reserved15c();
    virtual void Reserved160();
    virtual void Reserved164();
    virtual void Reserved168();
    virtual void Reserved16c();
    virtual void Reserved170();
    virtual void Reserved174();
    virtual void Reserved178();
    virtual void Reserved17c();
    virtual void Reserved180();
    virtual void Reserved184();
    virtual void Reserved188();
    virtual void Reserved18c();
    virtual void Reserved190();
    virtual void Reserved194();
    virtual void Reserved198();
    virtual void Reserved19c();
    virtual void Reserved1a0();
    virtual void Reserved1a4();
    virtual void Reserved1a8();
    virtual void Reserved1ac();
    virtual void Reserved1b0();
    virtual void Reserved1b4();
    virtual void Reserved1b8();
    virtual void Reserved1bc();
    virtual void Reserved1c0();
    virtual void Reserved1c4();
    virtual void Reserved1c8();
    virtual void Reserved1cc();
    virtual void Reserved1d0();
    virtual void Reserved1d4();
    virtual void Reserved1d8();
    virtual void Reserved1dc();
    virtual void Reserved1e0();
    virtual void Reserved1e4();
    virtual void Reserved1e8();
    virtual void Reserved1ec();
    virtual void Reserved1f0();
    virtual void Reserved1f4();
    virtual void Reserved1f8();
    virtual void Reserved1fc();
    virtual void Reserved200();
    virtual void Reserved204();
    virtual void Reserved208();
    virtual void Reserved20c();
    virtual void Reserved210();
    virtual void Reserved214();
    virtual void Reserved218();
    virtual void Reserved21c();
    virtual void Reserved220();
    virtual void Reserved224();
    virtual void FinalizeLoad(bool);
    void FUN_00848e10();
};
struct HandlerMethods
{
    bool FUN_00469860(unsigned int);
    void FUN_00848df0(bool);
};
struct FinalizeMethods
{
    void FUN_00867a20();
};
extern GlobalTask* DAT_01202d98;
extern PlayerMethods* DAT_011dea3c;
extern FinalizeMethods DAT_011de7b8;
extern const char DAT_0107f048[], DAT_0107efd0[], DAT_0107efb0[];
extern void* __cdecl operator new(unsigned int);
void __cdecl FUN_0084dff0(FUN_0084ded0*, const char*, ...);
void __cdecl ReadFileIntoBuffer(SaveFile*, unsigned char*, unsigned int);
void __cdecl FUN_00848e40(unsigned int);
void __cdecl FUN_0084c270(unsigned int);
void __cdecl LoadGlobalDataRanges(SaveFile*, unsigned int);
FormExtra* __cdecl LookupFormByID(unsigned int);
const char* __cdecl GetStringForByte(unsigned int);
void __cdecl FUN_00845cc0(const char*, ...);
UnloadFlags __cdecl FUN_00841120(UnloadFlags, UnloadFlags, unsigned int, bool);
void __cdecl FUN_0084f330(BGSLoadFormBuffer*, FormExtra*, UnloadFlags);
void __cdecl FUN_00b60040();
void __cdecl FUN_00848d10();
void __cdecl FUN_00848d30();
void __cdecl FUN_00850b40(char*);
struct ReconstructSession : BGSSaveLoadGame
{
    bool LoadSaveGame(SaveFile*, bool);
    bool ReadFileIndexMap(SaveFile*);
    void FUN_00848ca0(bool);
    void FUN_007d6bd0(bool);
    unsigned int LoadFormData(SaveFile*, BGSLoadFormBuffer*, FUN_00846b60*);
    void FUN_0084a880(FormExtra*);
    bool RevertReference(FormExtra**, UnloadFlags, bool);
    void FUN_00848e70(FUN_00845550*, FUN_00846b60*);
    void FUN_0084a5b0();
    bool IsFlag80Set();
    void ResetLoadBuffers(bool);
};
// Loads a save file: reads the header, rebuilds form and change state, loads each form buffer, then finalizes; returns false on failure.
// @fnv 0x00847df0
bool ReconstructSession::LoadSaveGame(SaveFile* pSaveFile, bool restoreMode)
{
    unsigned int position5;
    FUN_0084ded0* replacementState_2 = ((StatePrefix*)this)->state;
    unsigned int position;
    ((StatePrefix*)this)->state = new FUN_0084ded0;
    char finalName[260];
    char writeName[260];
    ((LoadManagerMethods*)DAT_011de134)->EnsureFosExtension(pSaveFile->FUN_006815c0(finalName));
    ((LoadManagerMethods*)DAT_011de134)->FUN_00851120(writeName, 260);
    FUN_0084dff0(((StatePrefix*)this)->state, DAT_0107f048, finalName, writeName);
    ReadFileIntoBuffer(pSaveFile, &m_ucSaveLoadState, 1);
    {
        FUN_00846b60* oldState5;
        FUN_0084ded0* oldState9;
        bool restoring = ReadFileIndexMap(pSaveFile);
        if (!restoring && !restoreMode)
        {
            delete (FUN_00847450*)((StatePrefix*)this)->state;
            ((StatePrefix*)this)->state = replacementState_2;
            m_ucSaveLoadState = 255;
            FUN_00848e40(1);
            return false;
        }
        delete (FUN_00847450*)replacementState_2;
        ((StatePrefix*)this)->references->FUN_00852b60();
        ((LoadManagerMethods*)DAT_011de134)->FUN_00850c20();
        DAT_01202d98->FUN_00c3e310();
        FUN_00848ca0(true);
        DAT_011dea3c->FUN_00848e10();
        {
            LoadHeader header;
            {
                char readName[260];
                header.ClearObject();
                pSaveFile->FUN_00846300(&header, 110);
                position5 = pSaveFile->FUN_00846400();
                pSaveFile->FUN_00846440(header.formOffset);
                oldState5 = ((StatePrefix*)this)->forms;
                ((StatePrefix*)this)->forms = new FUN_00846b60(5039);
                ((StatePrefix*)this)->forms->LoadFormIDMap(pSaveFile);
                ((StatePrefix*)this)->otherForms->LoadFormIDMap(pSaveFile);
                oldState9 = ((StatePrefix*)this)->state;
                ((StatePrefix*)this)->state = new FUN_0084ded0;
                ((StatePrefix*)this)->state->FUN_0084e190(pSaveFile);
                ((StatePrefix*)this)->state->AddAllNotes(oldState9);
                delete (FUN_00847450*)oldState9;
                pSaveFile->FUN_00846440(position5);
                ((StatePrefix*)this)->previousChanges = ((StatePrefix*)this)->changes;
                ((StatePrefix*)this)->changes = new FUN_00845550;
                FUN_0084c270(0);
                ((HandlerMethods*)g_dataHandler)->FUN_00848df0(true);
                LoadGlobalDataRanges(pSaveFile, header.firstBlockOffset);
                {
                    FUN_00845550* pendingChanges = ((StatePrefix*)this)->changes;
                    ((StatePrefix*)this)->changes = ((StatePrefix*)this)->previousChanges;
                    ((StatePrefix*)this)->previousChanges = 0;
                    position = pSaveFile->FUN_00846400();
                    ((StatePrefix*)this)->buffers.FUN_008454f0(false);
                    ((StatePrefix*)this)->buffers.FUN_0084b5c0(header.formCount);
                    FUN_007d6bd0(false);
                    for (unsigned int index2 = 0; index2 < header.formCount; index2++)
                    {
                        BGSLoadFormBuffer* current = new BGSLoadFormBuffer;
                        current->FUN_008644b0(pSaveFile);
                        unsigned int typeX = current->FUN_008665b0();
                        unsigned int index = current->FUN_0044edb0();
                        UnloadFlags changed = current->FUN_00428110();
                        UnloadFlags currentVal = ((StatePrefix*)this)->changes->GetFirstEntry(index);
                        UnloadFlags previous_ = pendingChanges->GetFirstEntry(index);
                        if (previous_.FUN_00559450())
                        {
                            ((FlagMethods*)&currentVal)->FUN_00841100(previous_.FUN_00559450());
                            pendingChanges->FUN_00845a20(index);
                        }
                        pendingChanges->ApplyFormQuantityChange(index, changed);
                        current->FUN_0086cf00(currentVal);
                        FormExtra* form_ = LookupFormByID(index);
                        current->FUN_007037c0(form_);
                        unsigned int position3 = LoadFormData(pSaveFile, current, oldState5);
                        current->FUN_00864580(pSaveFile, position3);
                        form_ = current->GetForm();
                        currentVal = current->FUN_0042ce30();
                        bool overrideFlag3 = false;
                        if (form_)
                        {
                            bool invalid = false;
                            if (form_->FUN_00401170() != typeX)
                                invalid = true;
                            else if (form_->GetIsReference())
                            {
                                ReferenceExtra* reference = (ReferenceExtra*)form_;
                                if (reference->FUN_007af430() == 0)
                                    invalid = true;
                            }
                            if (invalid)
                            {
                                if (((HandlerMethods*)g_dataHandler)->FUN_00469860(index))
                                {
                                    FUN_0084a880(form_);
                                    current->FUN_007037c0(0);
                                    current->FUN_0086cf00(FUN_008c71b0(0));
                                    overrideFlag3 = true;
                                }
                                else
                                {
                                    if (form_->FUN_00401170() != typeX)
                                        FUN_00845cc0(DAT_0107efd0, form_->GetName(), index,
                                                     GetStringForByte((unsigned char)typeX), form_->FUN_00440e30());
                                    current->FUN_00848d90(true);
                                }
                            }
                            else
                            {
                                form_->Revert(current);
                                UnloadFlags combined = FUN_00841120(currentVal, changed, typeX, true);
                                if (combined.FUN_00559450())
                                {
                                    if (!RevertReference((FormExtra**)&form_, combined, false))
                                    {
                                        ((StatePrefix*)this)->queue->FUN_00843630(form_, false);
                                        current->FUN_0042ce50(true);
                                    }
                                }
                                overrideFlag3 = true;
                            }
                        }
                        else
                            overrideFlag3 = true;
                        if (overrideFlag3)
                            ((StatePrefix*)this)->changes->FUN_00845a20(index);
                        ((StatePrefix*)this)->buffers.FUN_007cb2e0(&current);
                    }
                    FUN_00848e70(pendingChanges, oldState5);
                    FUN_00b60040();
                    delete (FUN_008473c0*)oldState5;
                    ((HandlerMethods*)g_dataHandler)->FUN_00848df0(false);
                    FUN_0084a5b0();
                    pSaveFile->FUN_00846440(position);
                    for (unsigned int index2 = 0; index2 < header.formCount; index2++)
                    {
                        BGSLoadFormBuffer* current = ((StatePrefix*)this)->buffers.FUN_006a7ad0(index2);
                        if (current->FUN_00848dd0())
                        {
                            ((StatePrefix*)this)->changes->FUN_00845a20(current->FUN_0044edb0());
                            current->FUN_008644b0(pSaveFile);
                            current->FUN_00864580(pSaveFile, 0);
                            delete (FUN_0081db60*)current;
                            ((StatePrefix*)this)->buffers.FUN_0047a110(index2, (BGSLoadFormBuffer*)0);
                            continue;
                        }
                        unsigned int index = current->FUN_0044edb0();
                        FormExtra* form_ = current->GetForm();
                        if (form_)
                        {
                            current->FUN_008644b0(pSaveFile);
                            unsigned int typeX = current->FUN_008665b0();
                            bool invalid = false;
                            if (form_->FUN_00401170() != typeX)
                            {
                                FUN_00845cc0(DAT_0107efd0, form_->GetName(), index,
                                             GetStringForByte((unsigned char)typeX), form_->FUN_00440e30());
                                invalid = true;
                            }
                            else if (form_->GetIsReference())
                            {
                                ReferenceExtra* reference = (ReferenceExtra*)form_;
                                if (reference->FUN_007af430() == 0)
                                    invalid = true;
                            }
                            if (invalid)
                            {
                                ((StatePrefix*)this)->changes->FUN_00845a20(current->FUN_0044edb0());
                                current->FUN_00864580(pSaveFile, 0);
                                delete (FUN_0081db60*)current;
                                ((StatePrefix*)this)->buffers.FUN_0047a110(index2, (BGSLoadFormBuffer*)0);
                                continue;
                            }
                            if (current->CheckValueMatchesField(pSaveFile) < 0 || IsFlag80Set())
                            {
                                current->FUN_00864580(pSaveFile, 0);
                                delete (FUN_0081db60*)current;
                                ((StatePrefix*)this)->buffers.FUN_0047a110(index2, (BGSLoadFormBuffer*)0);
                                ((StatePrefix*)this)->buffers.FUN_008454f0(true);
                                DAT_011dea3c->FinalizeLoad(false);
                                FUN_007d6bd0(true);
                                FUN_00848ca0(false);
                                return false;
                            }
                            FUN_0084f330(current, form_, current->FUN_00428110());
                            if (current->GetForm() && !IsFlag80Set())
                            {
                                form_->FUN_0046a010(true);
                                form_->LoadGame(current);
                            }
                        }
                        else
                        {
                            FUN_0044dee0 subBuffer;
                            subBuffer.ReadBuffer(pSaveFile);
                            ((StatePrefix*)this)
                                ->changes->SetCombatTargetQuantity(index, current->FUN_00428110(), subBuffer.formId);
                        }
                        current->FUN_00848d50();
                    }
                    pSaveFile->AdvancePosition(header.tailOffset);
                    FUN_00848d10();
                    ResetLoadBuffers(true);
                    FUN_00848d30();
                    LoadGlobalDataRanges(pSaveFile, header.lastBlockOffset);
                    m_ucSaveLoadState = 255;
                    FUN_00850b40(readName);
                    ((LoadManagerPrefix*)DAT_011de134)->name.FUN_004037f0(readName, 0);
                    FUN_0084dff0(((StatePrefix*)this)->state, DAT_0107efb0, finalName);
                    FUN_007d6bd0(true);
                    DAT_011de7b8.FUN_00867a20();
                    FUN_00848ca0(false);
                    return true;
                }
            }
        }
    }
}

namespace fnv_008492b0 {
class GlobalObject_008c71b0
{
  public:
    GlobalObject_008c71b0(int);
    GlobalObject_008c71b0(const GlobalObject_008c71b0&);
    int flags;
};
class BGSLoadGameBuffer
{
  public:
    virtual void V0();
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    ~BGSLoadGameBuffer();
};
class LoadBufferArray
{
  public:
    unsigned int GetSize();
    BGSLoadGameBuffer*& FUN_006a7ad0(unsigned int);
    void Clear(bool);
};
class IOManager
{
  public:
    void FUN_008495b0();
    void FUN_00c3e340();
    void FUN_00456520();
};
extern IOManager* DAT_01202d98;
class TES
{
  public:
    void FUN_00459920();
    void FUN_0045cda0();
};
extern TES* g_TES;
extern TESObjectREFR* _g_thePlayer;
class CellPhysics
{
  public:
    void* FUN_004543c0();
    void RemoveReference(TESObjectREFR*);
};
class PhysicsWorld
{
  public:
    void FUN_00c6a870();
};
class ChangeMap
{
  public:
    void FUN_00865360();
};
class LoadedMap
{
  public:
    void RemoveAll();
};
class LoadReference : public TESObjectREFR
{
  public:
    virtual void V126();
    virtual void V127();
    virtual void V128();
    virtual void V129();
    virtual void V130();
    virtual void V131();
    virtual void V132();
    virtual void V133();
    virtual void V134();
    virtual void V135();
    virtual void V136();
    virtual void V137();
    virtual void V138();
    virtual void V139();
    virtual void V140();
    virtual void V141();
    virtual void V142();
    virtual void V143();
    virtual void V144();
    virtual void V145();
};
bool __fastcall FUN_00849590(int);
void __cdecl FUN_00867f90(TESObjectREFR*);
class FormState
{
  public:
    void FUN_0046a010(bool);
};
class FUN_008492b0_shell
{
  public:
    unsigned int field00;
    unsigned int field04;
    unsigned int field08;
    unsigned int field0c;
    unsigned int field10;
    ChangeMap* changes;
    LoadedMap* loaded;
    unsigned int field1c;
    unsigned int field20;
    LoadBufferArray buffers;
    void SetFlag8(bool);
    void FUN_0084a690(TESForm*, GlobalObject_008c71b0, bool);
    void FUN_00849730(TESForm*, bool);
    void ResetLoadBuffers(bool resetWorld);
};
// @fnv 0x008492b0
void FUN_008492b0_shell::ResetLoadBuffers(bool resetWorld)
{
    SetFlag8(true);
    if (resetWorld)
        DAT_01202d98->FUN_008495b0();
    for (unsigned int i = 0; i < buffers.GetSize(); ++i)
    {
        BGSLoadGameBuffer* buffer = buffers.FUN_006a7ad0(i);
        if (buffer)
        {
            TESForm* form = buffer->GetForm();
            if (form)
                form->Unk_19(buffer);
        }
    }
    if (resetWorld)
    {
        g_TES->FUN_00459920();
        DAT_01202d98->FUN_00c3e340();
        DAT_01202d98->FUN_00456520();
        TESObjectCELL* cell = _g_thePlayer->GetParentCell();
        PhysicsWorld* world = cell ? (PhysicsWorld*)((CellPhysics*)cell)->FUN_004543c0() : 0;
        if (world)
            world->FUN_00c6a870();
        g_TES->FUN_0045cda0();
    }
    changes->FUN_00865360();
    for (unsigned int j = 0; j < buffers.GetSize(); ++j)
    {
        BGSLoadGameBuffer* buffer = buffers.FUN_006a7ad0(j);
        if (buffer)
        {
            TESForm* form = buffer->GetForm();
            if (form)
            {
                form->Unk_21(buffer);
                if (FUN_00849590((int)buffer))
                {
                    TESObjectREFR* ref = buffer->GetReference();
                    FUN_0084a690(ref, GlobalObject_008c71b0(8), true);
                    if (ref->IsActor())
                    {
                        LoadReference* actor = (LoadReference*)ref;
                        if (((Actor*)actor)->GetProcess())
                            actor->V145();
                    }
                    FUN_00849730(ref, true);
                    TESObjectCELL* cell = ref->GetParentCell();
                    if (cell)
                        ((CellPhysics*)cell)->RemoveReference(ref);
                    FUN_00867f90(ref);
                }
                ((FormState*)form)->FUN_0046a010(false);
            }
            delete buffer;
        }
    }
    buffers.Clear(true);
    loaded->RemoveAll();
    SetFlag8(false);
}
}  // namespace fnv_008492b0

struct LoadFormBuffer_8495d0
{
    void SetForm(TESForm* apForm);
    void SetChangeFlags(unsigned int auiFlags);
    void Finish();
};

struct UnloadedBuffer_8495d0
{
    char* pBuffer;
    const char* GetBuffer() const;
    int GetFormType();
    LoadFormBuffer_8495d0* CreateFormBuffer();
    void ResetReadPosition();
};

struct FormChanges_8495d0
{
    FormChangeMask kFlags;
    UnloadedBuffer_8495d0 kUnloaded;
};

struct ChangesMap_8495d0
{
    FormChanges_8495d0* GetChanges(unsigned int auiFormID);
    void RemoveChangesFor(unsigned int auiFormID);
};

struct BufferArray_8495d0
{
    unsigned int Add(LoadFormBuffer_8495d0*& arpBuffer);
};

struct FormRef_8495d0
{
    unsigned int GetID();
    const char* GetFormTypeName();
    void SetLoaded(bool abLoaded);
};

const char* GetFormTypeNameByID(unsigned char acType);
void __cdecl FUN_00845cc0(const char*, ...);
int __fastcall FNV_GetFormType(TESForm*);
void __cdecl ApplyChanges_8495d0(LoadFormBuffer_8495d0* apBuffer, TESForm* apForm, FormChangeMask aFlags);

struct SaveLoadGame_8495d0
{
    ChangesMap_8495d0* m_pFormChangesMap;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    BufferArray_8495d0 kLoadBuffers;
    bool IsLoadingFromSave();
    bool SetThreadAllowChanges(bool abAllow);
    void ApplyUnloadedChanges(TESForm* apForm);
};

// @fnv 0x008495d0
void SaveLoadGame_8495d0::ApplyUnloadedChanges(TESForm* apForm)
{
    if (IsLoadingFromSave())
        return;

    unsigned int auiFormId = ((FormRef_8495d0*)apForm)->GetID();
    FormChanges_8495d0* pChanges = m_pFormChangesMap->GetChanges(auiFormId);
    if (pChanges && pChanges->kUnloaded.GetBuffer())
    {
        int iSavedFormType = pChanges->kUnloaded.GetFormType();
        if (FNV_GetFormType(apForm) != iSavedFormType)
        {
            FUN_00845cc0(
                "SAVELOAD: (Load Error) Form '%s' (%08X) was saved with form type %s, but currently has form type %s.  Its loading will be skipped.",
                apForm->GetName(), auiFormId, GetFormTypeNameByID((unsigned char)iSavedFormType),
                ((FormRef_8495d0*)apForm)->GetFormTypeName());
            m_pFormChangesMap->RemoveChangesFor(auiFormId);
            return;
        }
        bool bPrevAllowChanges = SetThreadAllowChanges(false);
        LoadFormBuffer_8495d0* pBuffer = pChanges->kUnloaded.CreateFormBuffer();
        pChanges->kUnloaded.ResetReadPosition();
        pBuffer->SetForm(apForm);
        pBuffer->SetChangeFlags(pChanges->kFlags.flags);
        ((FormRef_8495d0*)apForm)->SetLoaded(true);
        ApplyChanges_8495d0(pBuffer, apForm, pChanges->kFlags);
        apForm->LoadGame(pBuffer);
        pBuffer->Finish();
        kLoadBuffers.Add(pBuffer);
        SetThreadAllowChanges(bPrevAllowChanges);
    }
}

struct ChangeFlags84
{
    unsigned int flags;
    bool Test(unsigned int mask);
    void Clear(unsigned int mask);
    unsigned int Get();
};

struct BoundObj84 : TESForm
{
    const char* GetEditorID84();
};

struct Ref84 : TESForm
{
    bool IsChangedLocation84(int unk);
    bool IsPersistent84();
    int HasName84();
    const char* GetFullName84();
    BoundObj84* GetObjectReference84();
};

extern Ref84* g_thePlayer;

struct SaveLoad84 : BGSSaveLoadGame
{
    void QueueActor84(Ref84* actor);
    bool RevertReference(Ref84** appRef, ChangeFlags84 flags, bool bDelete);
};

// @fnv 0x0084a3a0
bool SaveLoad84::RevertReference(Ref84** appRef, ChangeFlags84 flags, bool bDelete)
{
    if (*appRef == g_thePlayer)
        return true;
    if ((*appRef)->GetIsReference())
    {
        Ref84* pRef = *appRef;
        if (flags.Test(0xe))
        {
            if (g_dataHandler->FormIDExists((*appRef)->GetFormID()) || pRef->IsChangedLocation84(0))
            {
                flags.Clear(0xe);
                if (!flags.Get() && pRef->IsActor())
                {
                    Ref84* pActor = pRef;
                    QueueActor84(pActor);
                }
            }
            else if (bDelete && !pRef->IsPersistent84())
            {
                DeleteForm(pRef);
                pRef = 0;
                *appRef = 0;
            }
            else
            {
                _fnv_call_845cc0(
                    "Reference %s %08X with type %s and with changes %08X could not revert its changed location",
                    pRef->HasName84() ? pRef->GetName() : pRef->GetFullName84(), pRef->GetFormID(),
                    pRef->GetObjectReference84()->GetEditorID84(), flags.Get());
            }
        }
    }
    if (!flags.Get())
        return true;
    return false;
}

namespace fnv_0084ab20 {
struct Pt3f
{
    float x;
    float y;
    float z;
};
struct Obj84
{
    bool FUN_00425fd0();
    unsigned int FUN_0084e3a0();
};
struct Form84
{
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
    virtual bool vfn_f0();
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
    virtual Pt3f* vfn_1f4();
    int FUN_00401170();
    unsigned int FUN_00546af0();
    bool FUN_00425fd0();
    Obj84* FUN_0054ddd0();
    unsigned int FUN_00544c30();
    unsigned int FUN_00544c60();
    Obj84* FUN_008d6f30();
    Obj84* FUN_00575d70();
    void FUN_00561ef0(int);
};
struct Buf84
{
    unsigned int FUN_00559450();
    int FUN_00849220();
    void* FUN_00866390();
    void FUN_006665a0();
    unsigned char FUN_0084b450();
    unsigned int FUN_008663e0();
    void FUN_008665d0(unsigned int, unsigned int, unsigned int, unsigned char);
};
struct FormChanges84
{
    FormChangeMask flags;
    Buf84 buffer;
    bool FUN_004280f0(unsigned int);
    unsigned int FUN_00559450();
    bool FUN_00822510(int);
    void FUN_00562210(unsigned int);
};
struct ChangesMap84 : public BGSSaveLoadChangesMap
{
    void* FUN_004b9ba0();
    void FUN_006b7f20(void*&, unsigned int&, FormChanges84*&);
    void FUN_00845a20(unsigned int);
};
struct RefMap84 : public BGSSaveLoadReferencesMap
{
    bool FUN_0084b470(unsigned int);
    void RemoveReferenceFromCell(unsigned int, unsigned int, const Pt3f&);
    void FUN_0084b490(unsigned int, unsigned int);
};
struct Map84 : public FUN_0084ba20
{
    int f04;
    int f08;
    int f0c;
    Map84(int);
    virtual ~Map84();
    void InsertOrUpdate(unsigned __int64, unsigned int);
    bool FUN_0084b8b0(unsigned __int64, unsigned int*);
    void FUN_00438af0();
};
struct S84
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    Pt3f pt;
    int f20;
    int f24;
    int f28;
    int f2c;
    void FUN_00849280();
};
struct S84mini
{
    int a;
    int b;
    int c;
    int d;
};
struct Calendar
{
    unsigned int FUN_00867e30();
};
extern Calendar g_calendar;
struct DH84
{
    bool FUN_00469860(unsigned int);
};
struct ThisHist84
{
    char pad[0x1c];
    void* m_pNoteHandler;
};
Form84* __cdecl LookupFormByID(unsigned int);
int __cdecl FUN_0084e730(unsigned int, int, unsigned int);
int __cdecl FUN_0084e930(void*, int, void*);
unsigned int __cdecl FUN_00526100();
int __cdecl PackShortPair(short, short);
int __cdecl FUN_00406d90(float);
unsigned int __cdecl FUN_0084e800(int);
unsigned int __cdecl FUN_00846080(unsigned int, unsigned int*);
void __cdecl FUN_0084dff0(void*, const char*, ...);
void __cdecl _fnv_call_845cc0(const char*, ...);

struct FUN_0084ab20_shell : public BGSSaveLoadGame
{
    bool FUN_004623f0(bool);
    void FUN_0084ab20();
};

// @fnv 0x0084ab20
void FUN_0084ab20_shell::FUN_0084ab20()
{
    bool allowOld = FUN_004623f0(false);
    Map84 map(0x25);
    unsigned int start = g_calendar.FUN_00867e30();
    int count1 = 0;
    void* posA = ((ChangesMap84*)m_pFormChangesMap)->FUN_004b9ba0();
    while (posA != 0)
    {
        unsigned int fid = 0;
        FormChanges84* value = 0;
        ((ChangesMap84*)m_pFormChangesMap)->FUN_006b7f20(posA, fid, value);
        unsigned int idCopy = fid;
        if (value->FUN_004280f0(0x40000000))
        {
            unsigned int size = 0;
            unsigned int maxXA = 0x7fffffff;
            unsigned int fi = 0x7fffffff;
            if (value->buffer.FUN_00559450() != 0)
            {
                if (value->buffer.FUN_00849220() == 0x39)
                {
                    int res = FUN_0084e730(fid, 0x39, *(unsigned int*)value);
                    if (res != 0)
                    {
                        S84mini mini;
                        FUN_0084e930(value->buffer.FUN_00866390(), res, &mini);
                        size = (unsigned int)mini.d;
                        if (res != 3)
                        {
                            idCopy = (unsigned int)mini.a;
                            maxXA = (unsigned int)mini.b;
                            fi = (unsigned int)mini.c;
                        }
                    }
                }
            }
            else
            {
                Form84* form = LookupFormByID(fid);
                if (form != 0)
                {
                    if (form->FUN_00401170() == 0x39)
                    {
                        Form84* cell = form;
                        size = cell->FUN_00546af0();
                        if (!cell->FUN_00425fd0())
                        {
                            idCopy = cell->FUN_0054ddd0()->FUN_0084e3a0();
                            maxXA = cell->FUN_00544c30();
                            fi = cell->FUN_00544c60();
                        }
                    }
                }
            }
            if (size != 0)
            {
                if (start - size > FUN_00526100())
                {
                    unsigned __int64 key = (unsigned __int64)idCopy;
                    if (maxXA != 0x7fffffff)
                    {
                        __int64 t = PackShortPair((short)maxXA, (short)fi);
                        key |= (t << 32);
                    }
                    map.InsertOrUpdate(key, size);
                    count1 = count1 + 1;
                }
            }
        }
    }
    if (count1 != 0)
    {
        int countA = 0;
        int countB = 0;
        int countC = 0;
        posA = ((ChangesMap84*)m_pFormChangesMap)->FUN_004b9ba0();
        while (posA != 0)
        {
            unsigned int fm;
            FormChanges84* ev;
            unsigned int eg;
            unsigned int es;
            unsigned int ej;
            Form84* ft;
            unsigned int ek;
            fm = 0;
            ev = 0;
            ((ChangesMap84*)m_pFormChangesMap)->FUN_006b7f20(posA, fm, ev);
            if (((DH84*)g_dataHandler)->FUN_00469860(fm))
                continue;
            eg = 0;
            es = 0;
            ej = 0;
            ft = 0;
            ek = 0;
            if (ev->buffer.FUN_00559450() != 0)
            {
                ek = (unsigned int)ev->buffer.FUN_00849220();
            }
            else
            {
                Form84* formT = LookupFormByID(fm);
                if (formT != 0)
                {
                    ek = (unsigned int)formT->FUN_00401170();
                    if (formT->vfn_f0())
                    {
                        ft = formT;
                    }
                }
                else
                {
                    _fnv_call_845cc0(
                        "During cleanup, form %08X with changeflags %08X and no unloaded form buffer could not be found",
                        fm, ev->FUN_00559450());
                }
            }
            if (ek == 0x3a)
            {
                if (ev->buffer.FUN_00559450() != 0)
                {
                    int resA4 = FUN_0084e730(fm, (int)ek, *(unsigned int*)ev);
                    if (resA4 != 0)
                    {
                        S84 info;
                        info.FUN_00849280();
                        FUN_0084e930(ev->buffer.FUN_00866390(), resA4, &info);
                        eg = (unsigned int)info.f00;
                        es = (unsigned int)(FUN_00406d90(info.pt.x) >> 12);
                        ej = (unsigned int)(FUN_00406d90(info.pt.y) >> 12);
                    }
                }
                else if (ft != 0)
                {
                    Obj84* cellB = ft->FUN_008d6f30();
                    Obj84* worldB = ft->FUN_00575d70();
                    if (cellB != 0 && cellB->FUN_00425fd0())
                    {
                        eg = cellB->FUN_0084e3a0();
                    }
                    else if (worldB != 0)
                    {
                        eg = worldB->FUN_0084e3a0();
                        Pt3f ptT = *ft->vfn_1f4();
                        es = (unsigned int)(FUN_00406d90(ptT.x) >> 12);
                        ej = (unsigned int)(FUN_00406d90(ptT.y) >> 12);
                    }
                }
            }
            if (eg != 0)
            {
                unsigned __int64 key2 = (unsigned __int64)eg;
                if (es != 0x7fffffff)
                {
                    __int64 t2 = PackShortPair((short)es, (short)ej);
                    key2 |= (t2 << 32);
                }
                unsigned int outVal = 0;
                if (map.FUN_0084b8b0(key2, &outVal) && ev->FUN_004280f0(4) && !ev->FUN_004280f0(2))
                {
                    countA = countA + 1;
                    int res100 = FUN_0084e730(fm, (int)ek, *(unsigned int*)ev);
                    S84 info2;
                    info2.FUN_00849280();
                    if (ev->buffer.FUN_00559450() != 0 && res100 == 6)
                    {
                        FUN_0084e930(ev->buffer.FUN_00866390(), res100, &info2);
                        ((RefMap84*)m_pReferencesMap)->FUN_0084b470(fm);
                        Form84* formX = LookupFormByID((unsigned int)info2.f00);
                        if (formX != 0 && formX->FUN_00401170() == 0x41)
                        {
                            ((RefMap84*)m_pReferencesMap)
                                ->RemoveReferenceFromCell((unsigned int)info2.f00, fm, info2.pt);
                        }
                        else
                        {
                            ((RefMap84*)m_pReferencesMap)->FUN_0084b490((unsigned int)info2.f00, fm);
                        }
                    }
                    if (ev->FUN_00822510(4))
                    {
                        ((ChangesMap84*)m_pFormChangesMap)->FUN_00845a20(fm);
                        countB = countB + 1;
                    }
                    else
                    {
                        if (ev->buffer.FUN_00559450() != 0 && res100 != 0)
                        {
                            unsigned int bx;
                            unsigned int bo;
                            unsigned int bb;
                            unsigned int as;
                            unsigned int am;
                            unsigned int ah;
                            unsigned char pC;
                            unsigned int len;
                            unsigned int pA;
                            bb = (unsigned int)ev->buffer.FUN_00866390();
                            len = FUN_0084e800(res100);
                            bb += len;
                            as = 0;
                            am = FUN_00846080(bb, &as);
                            bb = am + as + bb;
                            ah = ev->buffer.FUN_00559450();
                            pC = ev->buffer.FUN_0084b450();
                            pA = ev->buffer.FUN_008663e0();
                            bo = pA - len - am - as;
                            ev->buffer.FUN_006665a0();
                            ev->buffer.FUN_008665d0(bb, bo, ek, pC);
                            bx = ah;
                            operator delete((void*)bx);
                            countC = countC + 1;
                        }
                        ev->FUN_00562210(0xc);
                    }
                    if (ft != 0)
                    {
                        ft->FUN_00561ef0(0);
                    }
                }
            }
        }
        if (countA != 0)
        {
            FUN_0084dff0(
                ((ThisHist84*)this)->m_pNoteHandler,
                "CleanupExpiredData removed havok from %i refs: %i removed all changes and %i unloaded refs removed partial changes",
                countA, countB, countC);
        }
    }
    map.FUN_00438af0();
    FUN_004623f0(allowOld);
}
}  // namespace fnv_0084ab20

namespace fnv_00848e70 {
class ChangesMap16
{
  public:
    unsigned int value00;
    unsigned int value04;
    unsigned int value08;
    unsigned int value0c;
    ChangesMap16();
};
class ChangesMapOps
{
  public:
    void FUN_00845a20(unsigned int id);
    void FUN_008457b0(unsigned int id, unsigned int index);
};
class RevertLoadFormBuffer
{
  public:
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
    RevertLoadFormBuffer();
    ~RevertLoadFormBuffer();
    void SetForm(TESForm*);
    void SetSource(unsigned int);
    void SetMode(int);
};
class RevertFormChangesView
{
  public:
    unsigned int unk00;
    char* unk04;
    bool TestFormChangeFlags(TESForm*);
    void FUN_00843630(TESForm*, int);
    void FUN_00843750(TESForm*, unsigned int, int);
    void FUN_008439e0();
    void Clear();
};
class ReconstructScratch
{
  public:
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
    void FUN_00849280();
    void FUN_0084e6a0(TESForm**, unsigned int*);
};
class SourceData
{
  public:
    unsigned int unk00;
    char* FUN_00866390();
};
class StringRef
{
  public:
    char* pString;
    const char* String() const;
    char* FUN_00849220();
};
class DataHandlerOps
{
  public:
    bool FUN_00469860(unsigned int);
};
class MapOps
{
  public:
    void FUN_00845760(SourceData*, unsigned int);
};
class FormTypeOps
{
  public:
    int FNV_GetFormType();
};
class CF845
{
  public:
    unsigned int unk00;
    CF845(int);
    CF845(const CF845&);
};
class TES
{
  public:
    bool FUN_004511e0(TESForm*, int);
};
class ReconstructLoadContext
{
  public:
    BGSReconstructFormsInAllFilesMap* pMap;
    unsigned int unk04;
    TESFile* currentFile;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    RevertFormChangesView* pFileMap;
    void FUN_0084a880(TESForm*);
    bool RevertReference(TESForm**, const char*, int);
    void FUN_00848e70(BGSSaveLoadChangesMap*, TESFile*);
};
extern TESForm* __cdecl LookupFormByID(unsigned int);

extern int __cdecl FUN_0084e730(unsigned int, const char*, unsigned int);
extern void __cdecl FUN_0084e930(char*, int, ReconstructScratch*);
extern void __cdecl FUN_00841120(unsigned int*, unsigned int, CF845, int, int);
extern TES* g_TES;

// Iterates pMap, reverting or reconstructing forms into changes and pFileMap, then clears pFileMap and swaps pMap to changes.
// @fnv 0x00848e70
void ReconstructLoadContext::FUN_00848e70(BGSSaveLoadChangesMap* changes, TESFile* file)
{
    if (!changes)
        changes = (BGSSaveLoadChangesMap*)new ChangesMap16;
    void* pos = pMap->GetFirstPos();
    while (pos)
    {
        TESForm* current;
        unsigned int form = 0;
        RevertFormChangesView* key = 0;
        pMap->GetNext(pos, *(TESFile**)&form, *(::BGSReconstructFormsInFileMap**)&key);
        current = LookupFormByID(form);
        if (current)
        {
            if (((DataHandlerOps*)g_dataHandler)->FUN_00469860(form))
            {
                FUN_0084a880(current);
                ((ChangesMapOps*)changes)->FUN_00845a20(form);
                continue;
            }
            RevertLoadFormBuffer buffer;
            buffer.SetForm(current);
            buffer.SetSource(key->unk00);
            buffer.SetMode(1);
            current->Revert((BGSLoadFormBuffer*)&buffer);
            unsigned int name;
            FUN_00841120(&name, key->unk00, CF845(0), ((FormTypeOps*)current)->FNV_GetFormType(), 0);
            if (((BSStringT<char>*)&name)->String())
            {
                if (!RevertReference(&current, (const char*)name, 1))
                {
                    if (current)
                        pFileMap->FUN_00843630(current, 8);
                }
            }
            if (current && key->TestFormChangeFlags(current))
                ((ChangesMapOps*)changes)->FUN_008457b0(form, key->unk00);
        }
        else if (!current && file)
        {
            StringRef name;
            name.pString = key->unk04;
            if (name.String())
            {
                int type = FUN_0084e730(form, name.FUN_00849220(), key->unk00);
                if (type == 6)
                {
                    TESFile* source = currentFile;
                    currentFile = file;
                    SourceData more;
                    unsigned int old;
                    ((MapOps*)pMap)->FUN_00845760(&more, form);
                    {
                        ReconstructScratch scratch;
                        scratch.FUN_00849280();
                        FUN_0084e930(more.FUN_00866390(), type, &scratch);
                        TESForm* reconstructed = 0;
                        old = 0;
                        scratch.FUN_0084e6a0(&reconstructed, &old);
                        if (reconstructed)
                        {
                            if (g_TES->FUN_004511e0(reconstructed, 0))
                                pFileMap->FUN_00843750(reconstructed, form, 8);
                        }
                    }
                    currentFile = source;
                }
            }
        }
    }
    pFileMap->FUN_008439e0();
    pFileMap->Clear();
    delete pMap;
    pMap = (BGSReconstructFormsInAllFilesMap*)changes;
}
}  // namespace fnv_00848e70

struct FUN_00853130_shell
{
    bool GetAt(unsigned int key, unsigned int& value);
};

struct FUN_0084aa90_shell
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    FUN_00853130_shell* unk18;
    unsigned int FUN_0084aa90(unsigned int aiOldFormID);
};

// Calls GetAt with aiOldFormID and returns its output value on success, or 0 on failure.
// @fnv 0x0084aa90
unsigned int FUN_0084aa90_shell::FUN_0084aa90(unsigned int aiOldFormID)
{
    unsigned int value = 0;
    if (unk18->GetAt(aiOldFormID, value))
        return value;
    return 0;
}

int __fastcall FNV_GetFormType(TESForm* form);
const char* __cdecl GetStringForByte(unsigned char formType);
void __cdecl _fnv_call_845cc0(const char*, ...);

static const char kRenumberedMsg[] =
    "FORMS: Form %08X with form type %i %s was re-numbered by BGSSaveLoadGame::ClearForm()";

struct SLGame84a880 : public BGSSaveLoadGame
{
    void FUN_0084a880(TESForm* form);
};

// Deletes forms of listed types, assigns new IDs to listed types and others, and logs for the default case.
// @fnv 0x0084a880
void SLGame84a880::FUN_0084a880(TESForm* form)
{
    if (!form)
        return;
    int formType = FNV_GetFormType(form);
    switch (formType)
    {
    case ENUM_FORM_ID_REFR_ID:
    case ENUM_FORM_ID_ACHR_ID:
    case ENUM_FORM_ID_ACRE_ID:
    case ENUM_FORM_ID_PMIS_ID:
    case ENUM_FORM_ID_PGRE_ID:
    case ENUM_FORM_ID_PBEA_ID:
    case ENUM_FORM_ID_PFLA_ID:
    case ENUM_FORM_ID_PACK_ID:
    case ENUM_FORM_ID_PCBE_ID:
        DeleteForm(form);
        break;
    case ENUM_FORM_ID_TXST_ID:
    case ENUM_FORM_ID_SCPT_ID:
    case ENUM_FORM_ID_LTEX_ID:
    case ENUM_FORM_ID_NPC__ID:
    case ENUM_FORM_ID_CREA_ID:
    case ENUM_FORM_ID_CELL_ID:
    case ENUM_FORM_ID_LAND_ID:
    case ENUM_FORM_ID_NAVM_ID:
        form->SetRefID(((TESDataHandlerSaveLoad*)g_dataHandler)->GetNextID(), true);
        break;
    default:
        _fnv_call_845cc0(kRenumberedMsg, form->GetFormID(), formType,
                         GetStringForByte(static_cast<unsigned char>(formType)));
        form->SetRefID(((TESDataHandlerSaveLoad*)g_dataHandler)->GetNextID(), true);
        break;
    }
}
