// fallout_shared/extradatalist.cpp: ExtraDataList, Owner, DelStandIn, ExtraPatrolRefData and more (578 functions)

#include "extradatalist_packet.h"
#include "ExtraContainerChanges.h"
#include "InventoryChanges.h"
#include "game_constants.h"

// Returns the InventoryChanges pointer from the ExtraContainerChanges extra data, or null if that extra data is absent.
// @fnv 0x00418520
InventoryChanges* ExtraDataList::GetContainerChangeData()
{
    ExtraContainerChanges* changes = static_cast<ExtraContainerChanges*>(GetExtraData(kExtraContainerChangesType));
    if (changes)
        return changes->pChanges;
    else
        return 0;
}

// Stores the given InventoryChanges in the ExtraContainerChanges extra data, creating and adding it if absent.
// @fnv 0x00419650
void ExtraDataList::SetContainerChanges(InventoryChanges* pInventoryChanges)
{
    if (!pInventoryChanges)
        return;
    ExtraContainerChanges* changes = static_cast<ExtraContainerChanges*>(GetExtraData(kExtraContainerChangesType));
    if (changes)
        changes->pChanges = pInventoryChanges;
    else
    {
        changes = new ExtraContainerChanges(pInventoryChanges);
        AddExtra(changes);
    }
}

// @fnv 0x004537b0
TaskQueueInterface* TaskQueueInterface::GetSingleton()
{
    return DAT_011df1a8;
}
// @fnv 0x00418750
bool ExtraDataList::HasExtraDataType0x2F()
{
    return HasExtraData(0x2f);
}
// @fnv 0x0041aeb0
void ExtraDataList::RemoveExtraDataType0x15()
{
    RemoveExtra(0x15);
}
// @fnv 0x00903cf0
Script* TESPackage::GetNextScript()
{
    return reinterpret_cast<Script*>(list.GetNext());
}
// @fnv 0x00555bc0
SeenData* FUN_00555bc0_shell::FindSeenData()
{
    return reinterpret_cast<ExtraDataList*>(reinterpret_cast<FUN_004610d0_shell*>(this)->GetTESImageSpaceModifierList())
        ->FUN_00421910();
}
// @fnv 0x00569140
LockExtraData* FUN_00569140_shell::GetMyLock()
{
    return GetExtraData()->GetLock();
}
// @fnv 0x00569580
TESForm* FUN_00569580_shell::GetOwnerForm()
{
    return GetExtraData()->GetOwnerForm();
}
// @fnv 0x004bca60
bool ExtraDataList::IsEmpty()
{
    if (pHead == 0)
        return true;
    else
        return false;
}
// @fnv 0x0042e8c0
ExtraDismemberedLimbs* ExtraDataList::GetDismemberedLimbs()
{
    ExtraDismemberedLimbs* extra = reinterpret_cast<ExtraDismemberedLimbs*>(GetExtraData(0x5f));
    return extra;
}
// @fnv 0x00410360
ExtraDataList::ExtraDataList()
{
    FUN_0040f740();
    m_ppVirtualMethodTable = kVtbl_ExtraDataList;
}

extern float DAT_01202800;

// Returns the float at index 1 of pThis, or zero (stored in DAT_01202800) when pThis is null.
// @fnv 0x00403e20
float& __fastcall FUN_00403e20(float* pThis)
{
    return pThis ? pThis[1] : (DAT_01202800 = 0.0f);
}

extern int DAT_01014210;

struct FUN_0040ec80_this
{
    int* vftable;
    unsigned char cType;
    void* pNext;
};

struct FUN_0040ec80_cls
{
    FUN_0040ec80_this* init(unsigned char acType);
};

// Sets the object's vftable to DAT_01014210, stores acType in cType and clears pNext, then returns the object.
// @fnv 0x0040ec80
FUN_0040ec80_this* FUN_0040ec80_cls::init(unsigned char acType)
{
    ((FUN_0040ec80_this*)this)->vftable = &DAT_01014210;
    ((FUN_0040ec80_this*)this)->cType = acType;
    ((FUN_0040ec80_this*)this)->pNext = 0;
    return (FUN_0040ec80_this*)this;
}

struct FUN_0040f700_shell : public BSExtraData
{
    bool IsDifferentFrom(BSExtraData*);
};

struct PatrolActorPackageData
{
    bool IsPatrolling(void);
};

// @fnv 0x0040f700
bool FUN_0040f700_shell::IsDifferentFrom(BSExtraData* apCompare)
{
    if (!apCompare)
    {
        return true;
    }
    if (((PatrolActorPackageData*)this)->IsPatrolling() != ((PatrolActorPackageData*)apCompare)->IsPatrolling())
    {
        return true;
    }
    return false;
}

extern int DAT_01014300;
void* __cdecl memset(void*, int, unsigned int);

// Sets pThis[0] to the address of DAT_01014300, clears pThis[1], zeroes 0x15 bytes at offset 8, and returns pThis.
// @fnv 0x0040f740
void* __fastcall FUN_0040f740(int* pThis)
{
    pThis[0] = reinterpret_cast<int>(&DAT_01014300);
    pThis[1] = 0;
    memset(reinterpret_cast<char*>(pThis) + 8, 0, 0x15);
    return pThis;
}

extern int DAT_011c38e4;

__declspec(thread) int tls_pad0;
__declspec(thread) void* tls_lastList;
__declspec(thread) int tls_clearCount;
__declspec(thread) void* tls_lastExtras[0x93];

// Increments DAT_011c38e4 and tls_clearCount, and if apList matches tls_lastList and aeType is a valid index, clears tls_lastExtras[aeType].
// @fnv 0x0040f7d0
void __cdecl FUN_0040f7d0(void* apList, int aeType)
{
    DAT_011c38e4 = DAT_011c38e4 + 1;
    tls_clearCount = tls_clearCount + 1;
    if (apList == tls_lastList && aeType >= 0 && aeType < 0x93)
    {
        tls_lastExtras[aeType] = 0;
    }
}

void* __cdecl memset(void*, int, unsigned int);
extern int DAT_011c38e4;

__declspec(thread) int tls_pad_0;
__declspec(thread) int tls_pad_4;
__declspec(thread) const BaseExtraList* tls_apList;
__declspec(thread) int tls_counter;
__declspec(thread) char tls_buffer[0x24c];

// Increments DAT_011c38e4 and tls_counter; if apList equals tls_apList, clears tls_buffer and resets tls_apList to null.
// @fnv 0x0040f860
void __cdecl ResetTlsBufferIfListMatches(const BaseExtraList* apList)
{
    DAT_011c38e4 += 1;
    tls_counter += 1;
    if (apList == tls_apList)
    {
        memset(tls_buffer, 0, sizeof(tls_buffer));
        tls_apList = 0;
    }
}

// Returns true when aeType is one of 0x0C, 0x0D, 0x0E, 0x15 or 0x2B, otherwise false.
// @fnv 0x0040f980
bool __cdecl FUN_0040f980(int aeType)
{
    switch (aeType)
    {
    case 0x0C:
    case 0x0D:
    case 0x0E:
    case 0x15:
    case 0x2B:
        return true;
    default:
        return false;
    }
}

void __cdecl ResetTlsBufferIfStale();

namespace fnv_anon_extradatalist {}
using namespace fnv_anon_extradatalist;
namespace fnv_anon_extradatalist {
__declspec(thread) int pad_tls[2];
__declspec(thread) BaseExtraList* tls_pList;
__declspec(thread) int pad_tls2;
__declspec(thread) BSExtraData* tls_pExtras[0x93];
}

// Returns the cached extra data of the given type when apList matches the thread-local list, otherwise returns null.
// @fnv 0x0040f9e0
BSExtraData* __cdecl FUN_0040f9e0(BaseExtraList* apList, int aeType)
{
    BSExtraData* pretval = 0;
    if (apList == tls_pList)
    {
        ResetTlsBufferIfStale();
        if (aeType >= 0 && aeType < 0x93)
        {
            pretval = tls_pExtras[aeType];
        }
    }
    return pretval;
}

struct FUN_0040fbf0_shell : public RecursiveSpinLock
{
    void Lock(char*);
};

unsigned int __cdecl gm_GetCurrentThreadId(void);
void __cdecl FUN_0040fca0(unsigned long);
int __cdecl FUN_0043b460(long volatile*, long, long);
class BGSLoadGameBuffer;
struct Interface
{
    static void __cdecl PrintDebugMessage(BGSLoadGameBuffer*);
};

// @fnv 0x0040fbf0
void FUN_0040fbf0_shell::Lock(char* apName)
{
    __declspec(align(32)) unsigned int uicurrentThread = gm_GetCurrentThreadId();
    if (m_uiOwningThreadID == uicurrentThread)
    {
        m_uiRecursionCount = m_uiRecursionCount + 1;
    }
    else
    {
        unsigned int ispincount = 0;
        while (FUN_0043b460((long volatile*)&m_uiOwningThreadID, 0, uicurrentThread))
        {
            ispincount = ispincount + 1;
            if (ispincount > 10000)
                FUN_0040fca0(1);
            else
                FUN_0040fca0(0);
        }
        ((void(__cdecl*)())Interface::PrintDebugMessage)();
        m_uiRecursionCount = 1;
    }
}

namespace fnv_0040fe20 {
struct FUN_0040fe20_shell : public BaseExtraList
{
    unsigned int FUN_0040fe20();
};

class RecursiveSpinLock
{
  public:
    void Lock(char const*);
    void Unlock(void);
};

extern RecursiveSpinLock g_011c3920;
BSExtraData* __fastcall FUN_0044ddc0(BSExtraData*);

// Locks g_011c3920, counts the nodes in the pHead list via FUN_0044ddc0, unlocks, and returns the count.
// @fnv 0x0040fe20
unsigned int FUN_0040fe20_shell::FUN_0040fe20()
{
    BSExtraData* work;
    unsigned int iCount;

    g_011c3920.Lock("BaseExtraList::ItemsInList()");
    iCount = 0;
    work = pHead;
    while (work != 0)
    {
        iCount = iCount + 1;
        work = FUN_0044ddc0(work);
    }
    g_011c3920.Unlock();
    return iCount;
}
}  // namespace fnv_0040fe20

struct FUN_0040fe80_shell : public BaseExtraList
{
    bool HasExtraType(unsigned char);
};

// Checks whether the extra list's bit array has the bit for the given type set, returning false when the byte index is out of range.
// @fnv 0x0040fe80
bool FUN_0040fe80_shell::HasExtraType(unsigned char acType)
{
    bool bretval;
    unsigned int iwhichbyte = acType >> 3;
    if (iwhichbyte < 0x15)
        bretval = (*((unsigned char*)this + iwhichbyte + 8) & (1 << (acType % 8))) != 0;
    else
        bretval = false;
    return bretval;
}

struct FUN_0040fee0_shell : public BaseExtraList
{
    void SetBitFlag(unsigned char, bool);
};

// Sets or clears bit acType in the 21-byte flag array at offset 8 of this BaseExtraList, ignoring types whose byte index is out of range.
// @fnv 0x0040fee0
void FUN_0040fee0_shell::SetBitFlag(unsigned char acType, bool abVal)
{
    unsigned int iwhichbyte = acType / 8;
    if (iwhichbyte < 0x15)
    {
        int ibyte = *((unsigned char*)this + iwhichbyte + 8);
        int ibit = acType % 8;
        int imask = 1 << ibit;
        if (abVal)
            ibyte |= imask;
        else
            ibyte = ~imask & ibyte;
        *((unsigned char*)this + iwhichbyte + 8) = ibyte;
    }
}

namespace fnv_00410220 {
struct FUN_00410220_shell : public BaseExtraList
{
    BSExtraData* FUN_00410220(unsigned char);
};

class RecursiveSpinLock
{
  public:
    void Lock(char const*);
    void Unlock();
};

class PatrolActorPackageData
{
  public:
    bool IsPatrolling();
};

extern RecursiveSpinLock g_011c3920;

BSExtraData* __cdecl FUN_0040f9e0(BaseExtraList*, unsigned char);
void __cdecl FUN_0040fa40(BaseExtraList*, BSExtraData*);

struct TESObjectREFR_GetFlags_Helper
{
    BSExtraData* GetFlags();
};

// @fnv 0x00410220
BSExtraData* FUN_00410220_shell::FUN_00410220(unsigned char acType)
{
    if (!HasExtraData(acType))
        return 0;

    BSExtraData* pretval = 0;
    pretval = FUN_0040f9e0(this, acType);
    if (!pretval)
    {
        g_011c3920.Lock("BaseExtraList::GetExtraData()");
        BSExtraData* pwork = pHead;
        while (pwork)
        {
            if ((unsigned char)reinterpret_cast<PatrolActorPackageData*>(pwork)->IsPatrolling() == acType)
            {
                FUN_0040fa40(this, pwork);
                pretval = pwork;
                break;
            }
            pwork = reinterpret_cast<BSExtraData*>(
                (reinterpret_cast<TESObjectREFR*>(pwork)->*reinterpret_cast<unsigned int (TESObjectREFR::*)()>(
                                                               &TESObjectREFR_GetFlags_Helper::GetFlags))());
        }
        g_011c3920.Unlock();
    }
    return pretval;
}
}  // namespace fnv_00410220

namespace fnv_004102d0 {
struct FUN_004102d0_shell : public BaseExtraList
{
    BSExtraData* FUN_004102d0(unsigned char);
};

class RecursiveSpinLock
{
  public:
    void Lock(char const*);
    void Unlock();
};

class PatrolActorPackageData
{
  public:
    bool IsPatrolling();
};

extern RecursiveSpinLock g_011c3920;

unsigned int __fastcall TESObjectREFR_GetFlags_call(TESObjectREFR*);

// @fnv 0x004102d0
BSExtraData* FUN_004102d0_shell::FUN_004102d0(unsigned char acType)
{
    if (!HasExtraData(acType))
        return 0;

    g_011c3920.Lock("BaseExtraList::GetPrevExtraData()");
    BSExtraData* work = pHead;
    BSExtraData* prev = 0;

    while (work != 0)
    {
        if (reinterpret_cast<PatrolActorPackageData*>(work)->IsPatrolling() == acType)
            break;

        prev = work;
        work = reinterpret_cast<BSExtraData*>(TESObjectREFR_GetFlags_call(reinterpret_cast<TESObjectREFR*>(work)));
    }

    g_011c3920.Unlock();
    return prev;
}
}  // namespace fnv_004102d0

namespace fnv_00411b00 {
struct TESKey;
struct LockExtraData
{
    int GetLockLevel(TESObjectREFR*);
    void SetLockLevel(int);
    int GetLevel(TESObjectREFR*);
    bool IsLocked();
    void SetLocked(bool);
    bool MeetsMinimumLockLevel();
    static int ConvertLockLevel(int);
    static int EnumToNumericValue(int);
    void Endian();
    unsigned char m_uiLockState;
    char _pad_1[3];
    TESKey* pKey;
    char cFlags;
    char _pad_9[3];
    unsigned int m_uiLockDifficulty;
    unsigned int m_uiLockValue;
};
typedef char _sizecheck_REFR_LOCK[sizeof(LockExtraData) == 20 ? 1 : -1];
struct FUN_00411b00_shell : public LockExtraData
{
    void FUN_00411b00();
};

// Clears the lock fields of the object: byte, key pointer, flags, and the two unsigned ints, then returns the object.
// @fnv 0x00411b00
LockExtraData* __fastcall FUN_00411b00(LockExtraData* pThis)
{
    pThis->m_uiLockState = 0;
    pThis->pKey = 0;
    pThis->cFlags = 0;
    pThis->m_uiLockValue = 0;
    pThis->m_uiLockDifficulty = 0;
    return pThis;
}
}  // namespace fnv_00411b00

// Sets the first four ints of pThis to zero and returns pThis.
// @fnv 0x00411dc0
int* __fastcall ClearFourInts(int* pInts)
{
    for (int i = 0; i < 4; ++i)
        pInts[i] = 0;
    return pInts;
}

extern int DAT_01014458;
struct Y00411e40
{
    void* vt;
    int pad[2];
    int f;
    void FUN_0040ec80(unsigned char t);
};
// Calls FUN_0040ec80 with 0x92, sets vt to &DAT_01014458 and f to 0, then returns p.
// @fnv 0x00411e40
Y00411e40* __fastcall FUN_00411e40(Y00411e40* apThis)
{
    apThis->FUN_0040ec80(0x92);
    apThis->vt = &DAT_01014458;
    apThis->f = 0;
    return apThis;
}

namespace fnv_00411ec0 {
struct FUN_00411ec0_shell : public ExtraDataList
{
    void FUN_00411ec0(ExtraDataList*);
};

struct NodeSI
{
    unsigned int GetFlags();
};
struct RecursiveSpinLock
{
    void Lock(const char*);
    void Unlock();
};
extern RecursiveSpinLock g_011c3920;
struct EDLStandIn
{
    void FUN_00411fd0(int);
    void FUN_004103d0(void*);
};
// Locks g_011c3920, copies each extra-data node from apCopy into this list, then unlocks.
// @fnv 0x00411ec0
void FUN_00411ec0_shell::FUN_00411ec0(ExtraDataList* apCopy)
{
    BSExtraData* pwork;
    ((EDLStandIn*)this)->FUN_00411fd0(1);
    g_011c3920.Lock("ExtraDataList::CopyList()");
    if (apCopy)
    {
        pwork = apCopy->pHead;
        while (pwork)
        {
            ((EDLStandIn*)this)->FUN_004103d0(pwork);
            pwork = (BSExtraData*)((NodeSI*)pwork)->GetFlags();
        }
    }
    g_011c3920.Unlock();
}
}  // namespace fnv_00411ec0

namespace fnv_00411f20 {
struct FUN_00411f20_shell : public ExtraDataList
{
    bool FUN_00411f20(BSExtraData*);
};

struct PatrolActorPackageData
{
    bool IsPatrolling();
};

// @fnv 0x00411f20
bool FUN_00411f20_shell::FUN_00411f20(BSExtraData* apExtra)
{
    bool bretval = true;
    if (apExtra)
    {
        switch (((PatrolActorPackageData*)apExtra)->IsPatrolling())
        {
        case 1:
        case 2:
        case 4:
        case 0xc:
        case 0xf:
        case 0x10:
        case 0x11:
        case 0x15:
        case 0x29:
        case 0x34:
        case 0x40:
        case 0x4b:
        case 0x52:
        case 0x54:
        case 0x55:
        case 0x58:
            bretval = false;
            break;
        }
    }
    return bretval;
}
}  // namespace fnv_00411f20

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
struct FUN_004121b0_shell : public BGSSaveLoadGame
{
    bool FUN_004121b0();
};

struct TLSData_004121b0
{
    char pad[0x294];
    unsigned int uiFlags;
};

static __declspec(thread) TLSData_004121b0 g_tlsData_004121b0;

// Returns whether bit 4 of the thread-local uiFlags is set, i.e. the thread allow-changes flag.
// @fnv 0x004121b0
bool FUN_004121b0_shell::FUN_004121b0()
{
    return g_tlsData_004121b0.uiFlags & 4;
}

namespace fnv_004126c0 {
struct FUN_004126c0_shell : public ExtraDataList
{
    bool FUN_004126c0(ExtraDataList*, bool, bool);
};

class RecursiveSpinLock
{
  public:
    void Lock(char const*);
    void Unlock();
};

class PatrolActorPackageData
{
  public:
    bool IsPatrolling();
};

class TESObjectREFR_Flags : public TESObjectREFR
{
  public:
    unsigned int GetFlags();
};

extern RecursiveSpinLock g_011c3920;

// @fnv 0x004126c0
bool FUN_004126c0_shell::FUN_004126c0(ExtraDataList* apCompare, bool abCompareScriptAndOwnerData, bool bThrown)
{
    g_011c3920.Lock("ExtraDataList::CompareListForContainer()");
    bool bres = false;
    BSExtraData* work = apCompare->pHead;
    while (work)
    {
        if (!abCompareScriptAndOwnerData)
        {
            if (((PatrolActorPackageData*)work)->IsPatrolling() == 0xd)
            {
                bres = true;
                break;
            }
            if (((PatrolActorPackageData*)work)->IsPatrolling() == 0x21)
            {
                bres = true;
                break;
            }
        }
        if (((PatrolActorPackageData*)work)->IsPatrolling() == 0x16 && bThrown)
        {
            work = (BSExtraData*)((TESObjectREFR_Flags*)work)->GetFlags();
            continue;
        }
        if (((PatrolActorPackageData*)work)->IsPatrolling() != 0x24 &&
            ((PatrolActorPackageData*)work)->IsPatrolling() != 0x4a)
        {
            BSExtraData* apExtra = GetExtraData(((PatrolActorPackageData*)work)->IsPatrolling());
            if (!apExtra)
            {
                bres = true;
                break;
            }
            if (((bool(__thiscall*)(BSExtraData*, BSExtraData*))apExtra->m_ppVirtualMethodTable[1])(apExtra, work))
            {
                bres = true;
                break;
            }
        }
        work = (BSExtraData*)((TESObjectREFR_Flags*)work)->GetFlags();
    }
    g_011c3920.Unlock();
    return bres;
}
}  // namespace fnv_004126c0

struct BGSPrimitive;
struct BGSPrimitiveBox;
struct BGSPrimitiveVariant;
struct BGSPrimitivePlane;
struct BGSPrimitiveSphere;
struct BSFadeNode;
struct BSMultiBoundShape;
struct NiAVObject;
struct RgbaColor;
struct NiGeometry;
struct NiPoint2;
struct NiPoint3;
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
};

struct FUN_00413fc0_Class
{
    char pad[0x18];
    blob12 val;
    blob12 GetRadii() const;
};

// Returns the 12-byte value stored at offset 0x18 of this object.
// @fnv 0x00413fc0
blob12 FUN_00413fc0_Class::GetRadii() const
{
    return val;
}

struct _FUN_004143c0_S
{
    int a;
    int b;
    _FUN_004143c0_S();
};

// Initializes the object by setting both fields b and a to zero.
// @fnv 0x004143c0
_FUN_004143c0_S::_FUN_004143c0_S()
{
    b = 0;
    a = 0;
}

struct _ref_006815c0_t
{
    void _ref_006815c0();
};

// @fnv 0x00414470
void* __fastcall FUN_00414470(char* pThis)
{
    ((_ref_006815c0_t*)pThis)->_ref_006815c0();
    ((_ref_006815c0_t*)(pThis + 8))->_ref_006815c0();
    ((_ref_006815c0_t*)(pThis + 0x14))->_ref_006815c0();
    return pThis;
}

namespace fnv_004169f0 {
struct NiStream;
struct blob12
{
    char b[12];
};
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct NiPoint3
{
    static struct blob12 ComponentProduct(void*, void*);
    float Length();
    float SqrLength();
    float XYLength();
    float SqrXYLength();
    float Dot(void*);
    void Unitize();
    float GetLengthSquared();
    struct blob12 Cross(void*);
    struct blob12 CrossProduct(void*);
    struct blob12 Perpendicular();
    static void LoadBinary(NiStream*, NiPoint3*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, NiPoint3*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    static void InitializePoint3();
    static void ShutdownPoint3();
    static void ProcessPointArray(NiPoint3*, unsigned int, unsigned int);
    static void ComputeMagnitude(NiPoint3*);
    static float VectorLength(void*);
    static void PointsPlusEqualFloatTimesPoints(NiPoint3*, float, void*, unsigned int);
    static void WeightedPointsPlusWeightedPoints(NiPoint3*, float, void*, unsigned int);
    static unsigned int* InitSqrtTable();
    float x;
    float y;
    float z;
};
typedef char _sizecheck_NiPoint3[sizeof(NiPoint3) == 12 ? 1 : -1];

struct BSOcclusionPlane_Fake
{
    char pad00[0x08];
    NiPoint3 kTargetCenter;
    char pad14[0xd0];
    bool m_bIsInFrustum;
    bool m_bIsVisible;

    void FUN_004169f0(const NiPoint3& arCenter);
};

// Stores arCenter into the plane's center point and sets two flags to true.
// @fnv 0x004169f0
void BSOcclusionPlane_Fake::FUN_004169f0(const NiPoint3& arCenter)
{
    kTargetCenter = arCenter;
    m_bIsInFrustum = true;
    m_bIsVisible = true;
}
}  // namespace fnv_004169f0

struct P00416a30
{
    int a;
    int b;
};
struct S00416a30
{
    char pad0[0x14];
    P00416a30 pos;
    char pad1[0xe4 - 0x1c];
    char f1;
    char f2;
    void FUN_00416a30(P00416a30* p);
};
// Copies the given position into pos and sets f1 and f2 to 1.
// @fnv 0x00416a30
void S00416a30::FUN_00416a30(P00416a30* apPosition)
{
    pos = *apPosition;
    f1 = 1;
    f2 = 1;
}

struct M00416a70
{
    int v[9];
};
struct S00416a70
{
    char pad0[0x1c];
    M00416a70 m;
    char pad1[0xe4 - 0x40];
    char f1;
    char f2;
    void FUN_00416a70(M00416a70* p);
};
// Copies the M00416a70 value pointed to by p into m, then sets f1 and f2 to 1.
// @fnv 0x00416a70
void S00416a70::FUN_00416a70(M00416a70* p)
{
    m = *p;
    f1 = 1;
    f2 = 1;
}

struct NavMesh;
struct NavMeshDoorPortalEntry
{
    void Endian();
    unsigned int m_uiNavMeshID;
    unsigned short m_usPortalTriangleIndex;
    char _pad_6[2];
};
typedef char _sizecheck_NAVMESH_PORTAL[sizeof(NavMeshDoorPortalEntry) == 8 ? 1 : -1];
struct FUN_00416ab0_shell : public NavMeshDoorPortalEntry
{
    void FUN_00416ab0(void*);
};

// Resets the portal's two ID fields to zero and returns the object.
// @fnv 0x00416ab0
NavMeshDoorPortalEntry* __fastcall FUN_00416ab0(NavMeshDoorPortalEntry* pThis)
{
    pThis->m_uiNavMeshID = 0;
    pThis->m_usPortalTriangleIndex = 0;
    return pThis;
}

struct RadioReferenceData
{
    void Copy(RadioReferenceData*);
    void Endian();
    float fRadius;
    int m_iIntegerValue;
    float m_fValueBeforeRadioReference;
    TESObjectREFR* m_pRadioReference;
};
typedef char _sizecheck_RADIO_DATA[sizeof(RadioReferenceData) == 16 ? 1 : -1];
struct FUN_00416b40_shell : public RadioReferenceData
{
    void FUN_00416b40();
};

// @fnv 0x00416b40
RadioReferenceData* __fastcall FUN_00416b40(RadioReferenceData* _this)
{
    _this->fRadius = 0.0f;
    _this->m_iIntegerValue = 1;
    _this->m_fValueBeforeRadioReference = 0.0f;
    _this->m_pRadioReference = 0;
    return _this;
}

struct LockExtraData;
struct FUN_004182b0_shell : public ExtraDataList
{
    LockExtraData* GetExtraDataPointer();
};

// Retrieves the extra data of type 0x2a and returns the pointer stored at offset 0xc, or null if absent.
// @fnv 0x004182b0
LockExtraData* FUN_004182b0_shell::GetExtraDataPointer()
{
    BSExtraData* pExtra = GetExtraData(0x2a);
    if (pExtra)
        return *(LockExtraData**)((char*)pExtra + 0xc);
    return 0;
}

struct RadioReferenceData;
struct FUN_004182e0_shell : public ExtraDataList
{
    RadioReferenceData* FUN_004182e0();
};

// Looks up extra data of type 0x68 and returns a pointer to the value at offset 0xc, or null if absent.
// @fnv 0x004182e0
RadioReferenceData* FUN_004182e0_shell::FUN_004182e0()
{
    BSExtraData* pextra = GetExtraData(0x68);
    if (pextra)
        return (RadioReferenceData*)((char*)pextra + 0xc);
    return 0;
}

struct TeleportableReference;
struct FUN_00418460_shell : public ExtraDataList
{
    TeleportableReference* FUN_00418460();
};

// Retrieves the extra data entry with type 0x2b and returns the pointer stored at offset 0xc, or null if absent.
// @fnv 0x00418460
TeleportableReference* FUN_00418460_shell::FUN_00418460()
{
    BSExtraData* pExtra = GetExtraData(0x2b);
    if (pExtra)
        return *(TeleportableReference**)((char*)pExtra + 0xc);
    return 0;
}

struct MapMarkerData;
struct FUN_00418490_shell : public ExtraDataList
{
    MapMarkerData* FUN_00418490();
};

// Retrieves the extra data of type 0x2C and returns the MapMarkerData pointer stored at offset 0xC, or null if absent.
// @fnv 0x00418490
MapMarkerData* FUN_00418490_shell::FUN_00418490()
{
    BSExtraData* pExtra = GetExtraData(0x2C);
    if (pExtra)
        return *(MapMarkerData**)((char*)pExtra + 0xC);
    return 0;
}

struct MediaLocation;
struct FUN_004184c0_shell : public ExtraDataList
{
    MediaLocation* FUN_004184c0();
};

// Looks up extra data of type 0x90 and returns the pointer stored at offset 0xc, or null if absent.
// @fnv 0x004184c0
MediaLocation* FUN_004184c0_shell::FUN_004184c0()
{
    BSExtraData* pExtra = GetExtraData(0x90);
    if (pExtra)
        return *(MediaLocation**)((char*)pExtra + 0xc);
    return 0;
}

struct TESForm;
struct FUN_00418660_shell : public ExtraDataList
{
    TESForm* FUN_00418660();
};

// Looks up extra data of type 0x21 and returns the TESForm pointer stored at offset 0xc, or null if absent.
// @fnv 0x00418660
TESForm* FUN_00418660_shell::FUN_00418660()
{
    BSExtraData* pExtraData = GetExtraData(0x21);
    if (pExtraData)
        return *(TESForm**)((char*)pExtraData + 0xc);
    else
        return 0;
}

struct TESGlobal;
struct FUN_00418690_shell : public ExtraDataList
{
    TESGlobal* FUN_00418690();
};

struct ExtraGlobal : BSExtraData
{
    TESGlobal* global;
};

// Looks up the extra data of type 0x22 and returns its global pointer, or null if absent.
// @fnv 0x00418690
TESGlobal* FUN_00418690_shell::FUN_00418690()
{
    ExtraGlobal* pGlobalForm = (ExtraGlobal*)GetExtraData(0x22);
    if (pGlobalForm)
        return pGlobalForm->global;
    else
        return 0;
}

struct FUN_004186c0_shell : public ExtraDataList
{
    int FUN_004186c0();
};

// Returns the int stored at offset 0xc of the extra data of type 0x23, or -1 if it is absent.
// @fnv 0x004186c0
int FUN_004186c0_shell::FUN_004186c0()
{
    BSExtraData* pRank = GetExtraData(0x23);
    if (pRank)
    {
        return *(int*)((char*)pRank + 0xc);
    }
    else
    {
        return -1;
    }
}

struct FUN_004186f0_shell : public ExtraDataList
{
    float FUN_004186f0();
};

// Returns the float at offset 0xc of the extra data entry with type 0x25, or -1.0 if it is absent.
// @fnv 0x004186f0
float FUN_004186f0_shell::FUN_004186f0()
{
    BSExtraData* pHealth = GetExtraData(0x25);
    if (pHealth)
    {
        return *(float*)((char*)pHealth + 0xc);
    }
    else
    {
        return -1.0f;
    }
}

struct ExtraLeveledItem;
struct FUN_00418720_shell : public ExtraDataList
{
    ExtraLeveledItem* GetExtraLeveledItem();
};

// Returns the ExtraLeveledItem stored under extra-data type 0x2f, or null if none is present.
// @fnv 0x00418720
ExtraLeveledItem* FUN_00418720_shell::GetExtraLeveledItem()
{
    ExtraLeveledItem* pLevelItem = (ExtraLeveledItem*)GetExtraData(0x2f);
    if (pLevelItem)
    {
        return pLevelItem;
    }
    else
    {
        return 0;
    }
}

struct FUN_00418770_shell : public ExtraDataList
{
    short FUN_00418770();
};

// Returns the short stored at offset 0xc of extra data 0x24, or 1 if that extra data is absent.
// @fnv 0x00418770
short FUN_00418770_shell::FUN_00418770()
{
    BSExtraData* pCount = GetExtraData(0x24);
    if (pCount)
    {
        return *(short*)((char*)pCount + 0xc);
    }
    else
    {
        return 1;
    }
}

struct Script;
struct ScriptLocals;
struct FUN_00418800_shell : public ExtraDataList
{
    Script* FUN_00418800();
};

// Returns the Script pointer stored in the extra data of type 0x0D, or null if that extra data is absent.
// @fnv 0x00418800
Script* FUN_00418800_shell::FUN_00418800()
{
    BSExtraData* pScript = GetExtraData(0x0D);
    if (pScript)
        return *(Script**)((char*)pScript + 0x0C);
    else
        return 0;
}

struct Script;
struct ScriptLocals;
struct FUN_00418830_shell : public ExtraDataList
{
    ScriptLocals* FUN_00418830();
};

// Returns the ScriptLocals pointer stored in the extra data of type 0x0D, or null if that extra data is absent.
// @fnv 0x00418830
ScriptLocals* FUN_00418830_shell::FUN_00418830()
{
    BSExtraData* pScript = GetExtraData(0x0D);
    if (pScript)
        return *(ScriptLocals**)((char*)pScript + 0x10);
    else
        return 0;
}

struct NiAVObject;
struct SoundPlaybackHandle
{
    void Clear();
    bool Play(bool);
    bool SchedulePlayback(unsigned int, int);
    bool Pause();
    bool Stop();
    bool IsPlaying();
    bool IsValid();
    int GetSoundType();
    float GetVolume();
    bool SetVolume(float);
    bool SetFrequency(float);
    bool SetPlaybackFrequency(float);
    bool SetFrequencyVariance(unsigned char);
    bool SetBalance(int);
    bool SetStaticAttenuation(unsigned short);
    int GetDuration();
    bool SetPosition(void*);
    bool SetPosition(float, float, float);
    bool SetBeamEnd(void*);
    bool SetBeamEnd(float, float, float);
    void SetDistanceRange(float, float);
    void SetSoundParameters(unsigned short, unsigned short, unsigned short, unsigned short, unsigned short);
    void SetReverbAttenuation(unsigned short);
    bool SetBeamStart(float, float, float);
    unsigned int GetID();
    void SetObjectToFollow(NiAVObject*);
    void Seek(unsigned int);
    void SetFollowsListener(bool);
    void SetCompletionCallback(int*, void*);
    void SetPlayCallback(int*, void*);
    static void SetAddMovingSoundCallback(int*);
    bool Release();
    bool SetFadeInTime(unsigned int);
    bool StopWithFade(unsigned int);
    bool SetPlaybackTime(unsigned int);
    void SetTimeConstraints(unsigned char, unsigned char);
    void SetSynchStartTime(unsigned int);
    void IsSoundPlaying();
    void SetPriority(unsigned int);
    void SetAssumeSuccess(bool);
    int QState();
    void* __vecDelDtor(unsigned int);
    unsigned int m_uiSoundResourceID;
    bool m_bLooping;
    char _pad_5[3];
    int eState;
};
typedef char _sizecheck_BSSoundHandle[sizeof(SoundPlaybackHandle) == 12 ? 1 : -1];
struct FUN_00418890_shell : public ExtraDataList
{
    void FUN_00418890(SoundPlaybackHandle*);
};

struct SH_00418890
{
    void FUN_004188d0();
    void FUN_copy(const void*);
};
struct SX_00418890
{
    char pad[0xc];
    char h[12];
};
// @fnv 0x00418890
void FUN_00418890_shell::FUN_00418890(SoundPlaybackHandle* result)
{
    SX_00418890* SoundAssetTmp = (SX_00418890*)GetExtraData(0x4f);
    if (SoundAssetTmp)
        ((SH_00418890*)result)->FUN_copy(SoundAssetTmp->h);
    else
        ((SH_00418890*)result)->FUN_004188d0();
}

namespace fnv_004188d0 {
struct NiAVObject;
struct SoundPlaybackHandle
{
    void Clear();
    bool Play(bool);
    bool SchedulePlayback(unsigned int, int);
    bool Pause();
    bool Stop();
    bool IsPlaying();
    bool IsValid();
    int GetSoundType();
    float GetVolume();
    bool SetVolume(float);
    bool SetFrequency(float);
    bool SetPlaybackFrequency(float);
    bool SetFrequencyVariance(unsigned char);
    bool SetBalance(int);
    bool SetStaticAttenuation(unsigned short);
    int GetDuration();
    bool SetPosition(void*);
    bool SetPosition(float, float, float);
    bool SetBeamEnd(void*);
    bool SetBeamEnd(float, float, float);
    void SetDistanceRange(float, float);
    void SetSoundParameters(unsigned short, unsigned short, unsigned short, unsigned short, unsigned short);
    void SetReverbAttenuation(unsigned short);
    bool SetBeamStart(float, float, float);
    unsigned int GetID();
    void SetObjectToFollow(NiAVObject*);
    void Seek(unsigned int);
    void SetFollowsListener(bool);
    void SetCompletionCallback(int*, void*);
    void SetPlayCallback(int*, void*);
    static void SetAddMovingSoundCallback(int*);
    bool Release();
    bool SetFadeInTime(unsigned int);
    bool StopWithFade(unsigned int);
    bool SetPlaybackTime(unsigned int);
    void SetTimeConstraints(unsigned char, unsigned char);
    void SetSynchStartTime(unsigned int);
    void IsSoundPlaying();
    void SetPriority(unsigned int);
    void SetAssumeSuccess(bool);
    int QState();
    void* __vecDelDtor(unsigned int);
    unsigned int m_uiSoundResourceID;
    bool m_bLooping;
    char _pad_5[3];
    int eState;
};
typedef char _sizecheck_BSSoundHandle[sizeof(SoundPlaybackHandle) == 12 ? 1 : -1];
struct FUN_004188d0_shell : public SoundPlaybackHandle
{
    void FUN_004188d0();
};

// @fnv 0x004188d0
void FUN_004188d0_shell::FUN_004188d0()
{
    m_uiSoundResourceID = 0xffffffff;
    m_bLooping = false;
    eState = 0;
}
}  // namespace fnv_004188d0

namespace fnv_004189c0 {
struct NiAVObject;
struct SoundPlaybackHandle
{
    void Clear();
    bool Play(bool);
    bool SchedulePlayback(unsigned int, int);
    bool Pause();
    bool Stop();
    bool IsPlaying();
    bool IsValid();
    int GetSoundType();
    float GetVolume();
    bool SetVolume(float);
    bool SetFrequency(float);
    bool SetPlaybackFrequency(float);
    bool SetFrequencyVariance(unsigned char);
    bool SetBalance(int);
    bool SetStaticAttenuation(unsigned short);
    int GetDuration();
    bool SetPosition(void*);
    bool SetPosition(float, float, float);
    bool SetBeamEnd(void*);
    bool SetBeamEnd(float, float, float);
    void SetDistanceRange(float, float);
    void SetSoundParameters(unsigned short, unsigned short, unsigned short, unsigned short, unsigned short);
    void SetReverbAttenuation(unsigned short);
    bool SetBeamStart(float, float, float);
    unsigned int GetID();
    void SetObjectToFollow(NiAVObject*);
    void Seek(unsigned int);
    void SetFollowsListener(bool);
    void SetCompletionCallback(int*, void*);
    void SetPlayCallback(int*, void*);
    static void SetAddMovingSoundCallback(int*);
    bool Release();
    bool SetFadeInTime(unsigned int);
    bool StopWithFade(unsigned int);
    bool SetPlaybackTime(unsigned int);
    void SetTimeConstraints(unsigned char, unsigned char);
    void SetSynchStartTime(unsigned int);
    void IsSoundPlaying();
    void SetPriority(unsigned int);
    void SetAssumeSuccess(bool);
    int QState();
    void* __vecDelDtor(unsigned int);
    unsigned int m_uiSoundResourceID;
    bool m_bLooping;
    char _pad_5[3];
    int eState;
};
typedef char _sizecheck_BSSoundHandle[sizeof(SoundPlaybackHandle) == 12 ? 1 : -1];
struct FUN_004189c0_shell : public ExtraDataList
{
    void FUN_004189c0(SoundPlaybackHandle*);
};

struct BSSoundHandle_
{
    BSSoundHandle_(const BSSoundHandle_&);
    void FUN_004188d0();
};

// @fnv 0x004189c0
void FUN_004189c0_shell::FUN_004189c0(SoundPlaybackHandle* result)
{
    BSExtraData* SoundAssetTmp = GetExtraData(0x83);
    if (SoundAssetTmp)
    {
        reinterpret_cast<BSSoundHandle_*>(result)->BSSoundHandle_::BSSoundHandle_(
            *reinterpret_cast<const BSSoundHandle_*>(reinterpret_cast<const char*>(SoundAssetTmp) + 0xC));
    }
    else
    {
        reinterpret_cast<BSSoundHandle_*>(result)->FUN_004188d0();
    }
}
}  // namespace fnv_004189c0

namespace fnv_00418a00 {
struct NiAVObject;
struct SoundPlaybackHandle
{
    void Clear();
    bool Play(bool);
    bool SchedulePlayback(unsigned int, int);
    bool Pause();
    bool Stop();
    bool IsPlaying();
    bool IsValid();
    int GetSoundType();
    float GetVolume();
    bool SetVolume(float);
    bool SetFrequency(float);
    bool SetPlaybackFrequency(float);
    bool SetFrequencyVariance(unsigned char);
    bool SetBalance(int);
    bool SetStaticAttenuation(unsigned short);
    int GetDuration();
    bool SetPosition(void*);
    bool SetPosition(float, float, float);
    bool SetBeamEnd(void*);
    bool SetBeamEnd(float, float, float);
    void SetDistanceRange(float, float);
    void SetSoundParameters(unsigned short, unsigned short, unsigned short, unsigned short, unsigned short);
    void SetReverbAttenuation(unsigned short);
    bool SetBeamStart(float, float, float);
    unsigned int GetID();
    void SetObjectToFollow(NiAVObject*);
    void Seek(unsigned int);
    void SetFollowsListener(bool);
    void SetCompletionCallback(int*, void*);
    void SetPlayCallback(int*, void*);
    static void SetAddMovingSoundCallback(int*);
    bool Release();
    bool SetFadeInTime(unsigned int);
    bool StopWithFade(unsigned int);
    bool SetPlaybackTime(unsigned int);
    void SetTimeConstraints(unsigned char, unsigned char);
    void SetSynchStartTime(unsigned int);
    void IsSoundPlaying();
    void SetPriority(unsigned int);
    void SetAssumeSuccess(bool);
    int QState();
    void* __vecDelDtor(unsigned int);
    unsigned int m_uiSoundResourceID;
    bool m_bLooping;
    char _pad_5[3];
    int eState;
};
typedef char _sizecheck_BSSoundHandle[sizeof(SoundPlaybackHandle) == 12 ? 1 : -1];
struct FUN_00418a00_shell : public ExtraDataList
{
    void FUN_00418a00(SoundPlaybackHandle*);
};

struct SH_00418a00
{
    void FUN_004188d0();
    void FUN_copy(const void*);
};
struct SX_00418a00
{
    char pad[0xc];
    char h[12];
};
// @fnv 0x00418a00
void FUN_00418a00_shell::FUN_00418a00(SoundPlaybackHandle* result)
{
    SX_00418a00* SoundAssetTmp = (SX_00418a00*)GetExtraData(0x86);
    if (SoundAssetTmp)
        ((SH_00418a00*)result)->FUN_copy(SoundAssetTmp->h);
    else
        ((SH_00418a00*)result)->FUN_004188d0();
}
}  // namespace fnv_00418a00

struct FUN_00418a80_shell : public ExtraDataList
{
    bool FUN_00418a80();
};

// @fnv 0x00418a80
bool FUN_00418a80_shell::FUN_00418a80()
{
    if (HasExtraData(0x1f))
        return true;
    return false;
}

struct FUN_00418ab0_shell : public ExtraDataList
{
    bool FUN_00418ab0(bool);
};

// @fnv 0x00418ab0
bool FUN_00418ab0_shell::FUN_00418ab0(bool abwornleft)
{
    if (abwornleft)
    {
        if (HasExtraData(0x17))
            return true;
        return false;
    }
    else
    {
        if (HasExtraData(0x16) || HasExtraData(0x17))
            return true;
    }
    return false;
}

struct FUN_00418b10_shell : public ExtraDataList
{
    bool FUN_00418b10();
};

// @fnv 0x00418b10
bool FUN_00418b10_shell::FUN_00418b10()
{
    if (HasExtraData(0x3e))
        return true;
    return false;
}

struct WorldLocation;
struct FUN_00418b70_shell : public ExtraDataList
{
    WorldLocation* FUN_00418b70();
};

// @fnv 0x00418b70
WorldLocation* FUN_00418b70_shell::FUN_00418b70()
{
    BSExtraData* pExtra = GetExtraData(0x18);
    if (!pExtra)
    {
        return 0;
    }
    else
    {
        return (WorldLocation*)((char*)pExtra + 0xc);
    }
}

struct FUN_00418ba0_shell : public ExtraDataList
{
    bool FUN_00418ba0();
};

bool __fastcall FUN_00418be0(void* pThis);

// Looks up extra data of type 0x8d and returns the result of FUN_00418be0 on it, or false if absent.
// @fnv 0x00418ba0
bool FUN_00418ba0_shell::FUN_00418ba0()
{
    BSExtraData* pExtra = GetExtraData(0x8d);
    if (!pExtra)
    {
        return false;
    }
    else
    {
        return FUN_00418be0(pExtra);
    }
}

struct ExtraStartingPosition;
struct FUN_00418d50_shell : public ExtraDataList
{
    ExtraStartingPosition* GetOrCreateStartingPosition(TESObjectREFR*);
};

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct ExtraStartingPosition : public BSExtraData
{
    char pad[0x18];
    ExtraStartingPosition(TESObjectREFR* apObject);
};

// Returns the ExtraStartingPosition extra data at index 0x0F, creating and adding a new one for apObject if none exists.
// @fnv 0x00418d50
ExtraStartingPosition* FUN_00418d50_shell::GetOrCreateStartingPosition(TESObjectREFR* apObject)
{
    ExtraStartingPosition* pExtra = (ExtraStartingPosition*)GetExtraData(0x0F);
    if (pExtra)
        return pExtra;

    pExtra = new ExtraStartingPosition(apObject);
    AddExtra(pExtra);
    return pExtra;
}

struct ExtraAction;
struct FUN_004195b0_shell : public ExtraDataList
{
    ExtraAction* GetOrCreateExtraAction();
};

class ExtraAction : public BSExtraData
{
  public:
    ExtraAction();
    int unk0C;
    int unk10;
};

// Returns the ExtraAction extra data (type 0x0E), creating and adding a new one if it is absent.
// @fnv 0x004195b0
ExtraAction* FUN_004195b0_shell::GetOrCreateExtraAction()
{
    ExtraAction* pExtra = (ExtraAction*)GetExtraData(0x0E);
    if (pExtra)
    {
        return pExtra;
    }
    pExtra = new ExtraAction();
    AddExtra(pExtra);
    return pExtra;
}

struct FUN_00419ea0_shell : public ExtraDataList
{
    TESObjectREFR* FUN_00419ea0();
};

// Reads extra data of type 0x46 and returns the TESObjectREFR pointer stored at offset 0xc, or null if absent.
// @fnv 0x00419ea0
TESObjectREFR* FUN_00419ea0_shell::FUN_00419ea0()
{
    BSExtraData* pExtraData = GetExtraData(0x46);
    if (pExtraData)
        return *(TESObjectREFR**)((char*)pExtraData + 0xc);
    else
        return 0;
}

struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiColor;
struct NiPoint3;
struct ScriptHeaderData;
struct ScriptReferencedObject;
struct Script;
struct CStringArgument;
struct ScriptCompiler;
struct ScriptLocals;
struct TESBoundObject;
struct TESForm;
struct TESObject;
struct TESQuest;
struct blob8
{
    char b[8];
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct FUN_00419ed0_shell : public ExtraDataList
{
    void FUN_00419ed0(Script*);
};

class ExtraScript : public BSExtraData
{
  public:
    Script* pScript;
    ScriptLocals* pLocals;
    ExtraScript(Script*);
};

// Finds the ExtraScript extra data and replaces its script, or creates a new ExtraScript for apScript and adds it.
// @fnv 0x00419ed0
void FUN_00419ed0_shell::FUN_00419ed0(Script* apScript)
{
    ExtraScript* pScript = (ExtraScript*)GetExtraData(0xd);
    if (pScript)
    {
        pScript->pScript = apScript;
    }
    else
    {
        pScript = new ExtraScript(apScript);
        AddExtra(pScript);
    }
}

struct FormFlagRecord;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct ScriptDefinition;
struct ScriptHeaderData;
struct Script;
struct TESForm;
struct ScriptLocals
{
    void ClearActionFlags();
    bool GetLocalData(TESForm*, unsigned int);
    void ClearActionFlagsForForm(TESForm*);
    bool CheckActionFlag(TESForm*, unsigned int);
    FormFlagRecord* GetActionEntry(TESForm*, bool);
    void Save(ScriptHeaderData*);
    void ClearActionList();
    void InitializeActionList();
    void CopyActionListFrom(ScriptLocals*);
    void* GetActionList();
    void ResetFormData(Script*);
    void SetVariable(unsigned int, double);
    double GetVariable(unsigned int, Script*);
    void* GetLocalList();
    bool IsReferenceVariable(unsigned int);
    unsigned short GetSaveSize();
    void SaveGame(BGSSaveFormBuffer*);
    void SaveGame();
    void LoadGame(BGSLoadFormBuffer*);
    void LoadGame();
    void Revert(BGSLoadFormBuffer*);
    void Revert();
    static void ProcessPendingTasks();
    void* __vecDelDtor(unsigned int);
    Script* m_pOwnerScript;
    char m_cActionFlags;
    char _pad_5[3];
    void* m_pLocalVariableList;
    void* m_pVariableList;
    ScriptDefinition* m_pExtendedLocals;
};
typedef char _sizecheck_ScriptLocals[sizeof(ScriptLocals) == 20 ? 1 : -1];
struct FUN_00419f80_shell : public ExtraDataList
{
    void FUN_00419f80(ScriptLocals*);
};

// Stores apScriptlocals into the extra data of type 0x0D if present.
// @fnv 0x00419f80
void FUN_00419f80_shell::FUN_00419f80(ScriptLocals* apScriptlocals)
{
    BSExtraData* pScript = GetExtraData(0x0D);
    if (pScript != 0)
    {
        *(ScriptLocals**)((char*)pScript + 0x10) = apScriptlocals;
    }
}

struct FUN_0041aa20_shell : public ExtraDataList
{
    void SetWornState(bool, bool);
};

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

class ExtraWorn : public BSExtraData
{
  public:
    ExtraWorn();
};

class ExtraWornLeft : public BSExtraData
{
  public:
    ExtraWornLeft()
    {
        ((void(__fastcall*)(ExtraWornLeft*))FUN_00432320)(this);
    }
    static ExtraWornLeft* __fastcall FUN_00432320(ExtraWornLeft*);
};

// Adds or removes the ExtraWorn or ExtraWornLeft extra data depending on the requested worn state and side.
// @fnv 0x0041aa20
void FUN_0041aa20_shell::SetWornState(bool abWorn, bool abWornLeft)
{
    if (abWornLeft)
    {
        bool bHasWornLeft = HasExtraData(0x17);
        if (abWorn && !bHasWornLeft)
        {
            AddExtra(new ExtraWornLeft());
        }
        else if (!abWorn && bHasWornLeft)
        {
            RemoveExtra(0x17);
        }
    }
    else
    {
        bool bHasWorn = HasExtraData(0x16);
        if (abWorn && !bHasWorn)
        {
            AddExtra(new ExtraWorn());
        }
        else if (!abWorn && bHasWorn)
        {
            RemoveExtra(0x16);
        }
    }
}

struct FUN_0041ab70_shell : public ExtraDataList
{
    void FUN_0041ab70(bool);
};

void* __cdecl operator new(unsigned int);

class ExtraCannotWear : public BSExtraData
{
  public:
    ExtraCannotWear();
};

// Adds an ExtraCannotWear extra when abCantWear is set and none exists, or removes extra type 0x3e when it is cleared and present.
// @fnv 0x0041ab70
void FUN_0041ab70_shell::FUN_0041ab70(bool abCantWear)
{
    bool bcantwear = HasExtraData(0x3e);
    if (abCantWear && !bcantwear)
    {
        AddExtra(new ExtraCannotWear());
    }
    else if (!abCantWear && bcantwear)
    {
        RemoveExtra(0x3e);
    }
}

namespace fnv_0041ad00 {
struct BGSEncounterZone;
struct BGSLoadFormBuffer;
struct BGSMusicType;
struct BGSSaveFormBuffer;
struct BGSTerrainManager;
struct BSPortalGraph;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct ImpactSwap;
struct NiColor;
struct NiPoint3;
struct NiStream;
struct TESBoundObject;
struct TESClimate;
struct TESForm;
struct GlobalVariableForm;
struct TESImageSpace;
struct TESObject;
struct TESTerrainLODManager;
struct TESWaterForm;
struct TESWorldSpace;
struct PointerPairData;
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
struct FUN_0041ad00_shell : public ExtraDataList
{
    void FUN_0041ad00(TESWorldSpace*, TESObjectCELL*, void*, float);
};

struct ExtraPackageStartLocation_local : public BSExtraData
{
    void* pLocation;
    blob12 pt;
    float fZRotation;
    ExtraPackageStartLocation_local(TESWorldSpace*, TESObjectCELL*, void*, float);
};

// Finds or creates the ExtraPackageStartLocation extra data, updating its location and point when it already exists.
// @fnv 0x0041ad00
void FUN_0041ad00_shell::FUN_0041ad00(TESWorldSpace* apWorld, TESObjectCELL* apIntCell, void* aPt, float afzrotation)
{
    ExtraPackageStartLocation_local* pExtra = (ExtraPackageStartLocation_local*)GetExtraData(0x18);
    if (!pExtra)
    {
        pExtra = new ExtraPackageStartLocation_local(apWorld, apIntCell, aPt, afzrotation);
        AddExtra(pExtra);
    }
    else
    {
        if (apWorld)
            pExtra->pLocation = apWorld;
        else
            pExtra->pLocation = apIntCell;
        pExtra->pt = *(blob12*)aPt;
    }
}
}  // namespace fnv_0041ad00

namespace fnv_0041b1e0 {
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiColor;
struct NiPoint3;
struct TESBoundObject;
struct TESForm;
struct blob8
{
    char b[8];
};
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct FUN_0041b1e0_shell : public ExtraDataList
{
    void FUN_0041b1e0(TESForm*);
};

class ExtraStartingWorldOrCell : public BSExtraData
{
  public:
    TESForm* m_pStartingWorldOrCell;
    ExtraStartingWorldOrCell();
};

void __fastcall RemoveExtraType73(ExtraDataList* pThis);

// @fnv 0x0041b1e0
void FUN_0041b1e0_shell::FUN_0041b1e0(TESForm* apWorldOrCell)
{
    if (!apWorldOrCell)
    {
        RemoveExtraType73(this);
    }
    else
    {
        ExtraStartingWorldOrCell* pExtra = (ExtraStartingWorldOrCell*)GetExtraData(0x49);
        if (!pExtra)
        {
            pExtra = new ExtraStartingWorldOrCell();
            AddExtra(pExtra);
        }
        pExtra->m_pStartingWorldOrCell = apWorldOrCell;
    }
}
}  // namespace fnv_0041b1e0

namespace fnv_0041b2a0 {
struct BGSEncounterZone;
struct BGSLoadFormBuffer;
struct BGSMusicType;
struct BGSSaveFormBuffer;
struct BGSTerrainManager;
struct BSPortalGraph;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct ImpactSwap;
struct NiColor;
struct NiPoint3;
struct TESBoundObject;
struct TESClimate;
struct TESForm;
struct GlobalVariableForm;
struct TESImageSpace;
struct TESObject;
struct TESTerrainLODManager;
struct TESWaterForm;
struct TESWorldSpace;
struct PointerPairData;
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
struct FUN_0041b2a0_shell : public ExtraDataList
{
    void FUN_0041b2a0(TESObjectREFR*);
};

struct DoorCell
{
    void* GetParentWorldSpace();
};
struct Sub_0041b2a0
{
    virtual DoorCell* v0();
};
struct TESSound
{
    unsigned int Deallocate();
};
void _FNV_Warning(const char*, ...);
struct Ref_0041b2a0
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
    virtual void r18();
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
    virtual void r64();
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
    virtual const char* r76();
    char pad[0x14];
    Sub_0041b2a0 sub;
    unsigned int Deallocate();
};
struct H_0041b2a0
{
    void FUN_0041b1e0(void*);
};
// @fnv 0x0041b2a0
void FUN_0041b2a0_shell::FUN_0041b2a0(TESObjectREFR* ref)
{
    DoorCell* pcell = ((Ref_0041b2a0*)ref)->sub.v0();
    if (pcell)
    {
        void* pworld = pcell->GetParentWorldSpace();
        if (pworld)
            ((H_0041b2a0*)this)->FUN_0041b1e0(pworld);
        else
            ((H_0041b2a0*)this)->FUN_0041b1e0(pcell);
    }
    else
    {
        _FNV_Warning("FORMS: Reference %s %08X has no parent save cell", ((Ref_0041b2a0*)ref)->r76(),
                     ((TESSound*)ref)->Deallocate());
    }
}
}  // namespace fnv_0041b2a0

struct TESForm;
struct FUN_0041b320_shell : public ExtraDataList
{
    TESForm* FUN_0041b320();
};

// Retrieves the extra data of type 0x49 from the list and returns the TESForm pointer stored at offset 0xc, or null if absent.
// @fnv 0x0041b320
TESForm* FUN_0041b320_shell::FUN_0041b320()
{
    BSExtraData* pExtra = GetExtraData(0x49);
    if (pExtra)
        return *(TESForm**)((char*)pExtra + 0xc);
    return 0;
}

struct FUN_0041b370_shell : public ExtraDataList
{
    unsigned int FUN_0041b370();
};

// Reads extra data of type 0x0E and returns the byte at offset 0x0C, or 1 if it is absent.
// @fnv 0x0041b370
unsigned int FUN_0041b370_shell::FUN_0041b370()
{
    BSExtraData* pExtra = GetExtraData(0x0E);
    if (pExtra)
    {
        return *((unsigned char*)pExtra + 0x0C);
    }
    return 1;
}

struct FUN_0041b3a0_shell : public ExtraDataList
{
    bool FUN_0041b3a0(int);
};

unsigned int __fastcall FUN_0041b370(ExtraDataList*);

// Reads the extra-data type flags via FUN_0041b370 and returns whether the requested type bit is set.
// @fnv 0x0041b3a0
bool FUN_0041b3a0_shell::FUN_0041b3a0(int aeType)
{
    unsigned int imyAction = FUN_0041b370(this);
    return (imyAction & aeType) ? true : false;
}

struct FUN_0041b3d0_shell : public ExtraDataList
{
    void FUN_0041b3d0(int);
};

struct Dummy_00410020
{
    void FUN_00410020(void*, bool);
    void* GetOrCreateExtraAction();
};

// @fnv 0x0041b3d0
void FUN_0041b3d0_shell::FUN_0041b3d0(int aeType)
{
    BSExtraData* pExtra = GetExtraData(0x0E);
    if (!pExtra)
    {
        if (aeType != 1)
        {
            pExtra = (BSExtraData*)((Dummy_00410020*)this)->GetOrCreateExtraAction();
        }
    }
    else if (aeType == 1 && *(int*)((char*)pExtra + 0x10) == 0)
    {
        ((Dummy_00410020*)this)->FUN_00410020(pExtra, true);
        pExtra = 0;
    }
    if (pExtra)
    {
        *((char*)pExtra + 0x0C) = (char)aeType;
    }
}

struct FUN_0041b440_shell : public ExtraDataList
{
    void FUN_0041b440(int);
};

struct ExtraDataList_Helper
{
    unsigned int FUN_0041b370();
    void FUN_0041b3d0(unsigned int);
};

// Reads the action flags via FUN_0041b370, ORs in aeType, and writes the result back via FUN_0041b3d0.
// @fnv 0x0041b440
void FUN_0041b440_shell::FUN_0041b440(int aeType)
{
    unsigned int newAction = ((ExtraDataList_Helper*)this)->FUN_0041b370();
    newAction |= aeType;
    ((ExtraDataList_Helper*)this)->FUN_0041b3d0(newAction);
}

struct S0041b470
{
    unsigned int FUN_0041b370();
    void FUN_0041b3d0(unsigned int);
    void FUN_0041b470(unsigned int a);
};
// Reads the current bit field, clears the bits set in a, and writes the result back.
// @fnv 0x0041b470
void S0041b470::FUN_0041b470(unsigned int auiMask)
{
    unsigned int v = FUN_0041b370();
    v = ~auiMask & v;
    FUN_0041b3d0(v);
}

struct FUN_0041b520_shell : public ExtraDataList
{
    TESObjectREFR* FUN_0041b520();
};

// Retrieves the extra data of type 0x0E and returns the TESObjectREFR pointer stored at offset 0x10, or null if absent.
// @fnv 0x0041b520
TESObjectREFR* FUN_0041b520_shell::FUN_0041b520()
{
    BSExtraData* pExtra = GetExtraData(0x0E);
    if (!pExtra)
    {
        return 0;
    }
    return *(TESObjectREFR**)((char*)pExtra + 0x10);
}

struct FUN_0041b550_shell : public ExtraDataList
{
    float FUN_0041b550();
};

// Reads extra data of type 0x7A and returns the float at offset 0xC, or 1.0f if absent.
// @fnv 0x0041b550
float FUN_0041b550_shell::FUN_0041b550()
{
    BSExtraData* pextra = GetExtraData(0x7A);
    if (pextra)
    {
        return *(float*)((char*)pextra + 0xC);
    }
    return 1.0f;
}

struct FUN_0041b6b0_shell : public ExtraDataList
{
    float FUN_0041b6b0();
};

// Returns the float at offset 0xc of the extra data entry with type 0x56, or -1.0f if it is absent.
// @fnv 0x0041b6b0
float FUN_0041b6b0_shell::FUN_0041b6b0()
{
    BSExtraData* pHealthData = GetExtraData(0x56);
    if (pHealthData)
    {
        return *(float*)((char*)pHealthData + 0xc);
    }
    return -1.0f;
}

struct FUN_0041c8d0_shell : public ExtraDataList
{
    TESObjectREFR* FUN_0041c8d0();
};

// Returns the TESObjectREFR stored at offset 0xC of the extra data of type 0x1C, or null if absent.
// @fnv 0x0041c8d0
TESObjectREFR* FUN_0041c8d0_shell::FUN_0041c8d0()
{
    BSExtraData* pExtra = GetExtraData(0x1C);
    if (pExtra)
    {
        return *(TESObjectREFR**)((char*)pExtra + 0xC);
    }
    else
    {
        return 0;
    }
}

struct FUN_0041cb10_shell : public ExtraDataList
{
    TESPackage* FUN_0041cb10();
};

// Retrieves the extra data of type 0x19 and returns the TESPackage pointer stored at offset 0xC, or null if absent.
// @fnv 0x0041cb10
TESPackage* FUN_0041cb10_shell::FUN_0041cb10()
{
    BSExtraData* pExtra = GetExtraData(0x19);
    if (pExtra)
        return *(TESPackage**)((char*)pExtra + 0xC);
    else
        return 0;
}

struct FUN_0041cb70_shell : public ExtraDataList
{
    TESObjectREFR* FUN_0041cb70();
};

// Retrieves the extra data of type 0x19 and returns the TESObjectREFR pointer stored at offset 0x14, or null if absent.
// @fnv 0x0041cb70
TESObjectREFR* FUN_0041cb70_shell::FUN_0041cb70()
{
    BSExtraData* pExtra = GetExtraData(0x19);
    if (pExtra)
        return *(TESObjectREFR**)((char*)pExtra + 0x14);
    else
        return 0;
}

struct TrespassPackage;
struct FUN_0041cd70_shell : public ExtraDataList
{
    TrespassPackage* FUN_0041cd70();
};

// Retrieves the extra data of type 0x1a and returns the TrespassPackage pointer stored at offset 0xc, or null if absent.
// @fnv 0x0041cd70
TrespassPackage* FUN_0041cd70_shell::FUN_0041cd70()
{
    BSExtraData* pExtra = GetExtraData(0x1a);
    if (pExtra)
        return *(TrespassPackage**)((char*)pExtra + 0xc);
    return 0;
}

struct FUN_0041cf00_shell : public ExtraDataList
{
    void* FUN_0041cf00();
};

// Looks up extra data of type 0x35 and returns the pointer stored at offset 0xC, or null if absent.
// @fnv 0x0041cf00
void* FUN_0041cf00_shell::FUN_0041cf00()
{
    BSExtraData* pExtra = GetExtraData(0x35);
    if (pExtra)
    {
        return *(void**)((char*)pExtra + 0xC);
    }
    else
    {
        return 0;
    }
}

namespace fnv_0041cf30 {
struct ActiveEffect;
struct Actor;
struct ActorMover;
struct ActorValueOwner;
struct AlchemyItem;
struct Animation;
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
struct BSFaceGenAnimationData;
struct SoundPlaybackHandle;
struct BaseProcess;
struct BipedAnim;
struct CombatGroupCollection;
struct CombatController;
struct ActorCombatGroup;
struct ContinuousBeamProjectile;
struct Crime;
struct DialogueResponse;
struct DetectionParameters;
struct EffectItem;
struct FurnitureMark;
struct BooleanFloatQuery;
struct IDebugText;
struct InventoryStackRecord;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct MobileObject;
struct NiAVObject;
struct NiNode;
struct NiPoint3;
struct LocationDescriptor;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct PathingRequest;
struct Projectile;
struct QueuedFile;
struct SpellItem;
struct TESActorBase;
struct TESBoundObject;
struct TESClass;
struct TESCombatStyle;
struct TESFaction;
struct TESForm;
struct TESIdleForm;
struct TESObject;
struct TESObjectBOOK;
struct TESObjectWEAP;
struct TESRace;
struct TESSkill;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct TrespassPackage;
struct WeaponObject;
struct bhkCharacterController;
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
struct FUN_0041cf30_shell : public ExtraDataList
{
    void FUN_0041cf30(Actor*);
};

struct Crime
{
    void FUN_009eba00(Actor*);
};

struct ExtraPlayerCrimeList_local : public BSExtraData
{
    BSSimpleList<Crime*>* pCrimeList;
};

struct BaseExtraList_local
{
    void FUN_00410020(BSExtraData*, bool);
};

extern "C"
{
    void __cdecl FUN_009eba00();
    void __cdecl FUN_00410020();
}

// Iterates the player's crime list, calls FUN_009eba00 on each Crime with apActor, then frees and clears the list and removes the extra data.
// @fnv 0x0041cf30
void FUN_0041cf30_shell::FUN_0041cf30(Actor* apActor)
{
    ExtraPlayerCrimeList_local* pExtra = static_cast<ExtraPlayerCrimeList_local*>(GetExtraData(0x35));
    if (pExtra)
    {
        if (pExtra->pCrimeList)
        {
            BSSimpleList<Crime*>* pCurrentElementNext = pExtra->pCrimeList;
            while (pCurrentElementNext && pCurrentElementNext->GetItem() != 0)
            {
                Crime* pcrime = pCurrentElementNext->GetItem();
                reinterpret_cast<void(__thiscall*)(Crime*, Actor*)>(&FUN_009eba00)(pcrime, apActor);
                pCurrentElementNext = pCurrentElementNext->GetNext();
            }
            reinterpret_cast<BSSimpleList<int>*>(pExtra->pCrimeList)->RemoveAll();
            delete reinterpret_cast<BSSimpleList<const char*>*>(pExtra->pCrimeList);
            pExtra->pCrimeList = 0;
        }
        reinterpret_cast<void(__thiscall*)(BaseExtraList*, BSExtraData*, bool)>(&FUN_00410020)(this, pExtra, true);
    }
}
}  // namespace fnv_0041cf30

struct FUN_0041d000_shell : public ExtraDataList
{
    void FUN_0041d000();
};

struct HX1d000
{
    void FUN_00410020(BSExtraData*, int);
};
// Looks up extra data of type 0x2f and, if present, calls FUN_00410020 to remove it with flag 1.
// @fnv 0x0041d000
void FUN_0041d000_shell::FUN_0041d000()
{
    BSExtraData* pExtra = GetExtraData(0x2f);
    if (pExtra)
        reinterpret_cast<HX1d000*>(this)->FUN_00410020(pExtra, 1);
}

namespace fnv_0041d120 {
struct FUN_0041d120_shell : public ExtraDataList
{
    bool HasOnlyAllowedExtraData(bool);
};

class RecursiveSpinLock
{
  public:
    void Lock(char const*);
    void Unlock();
};

extern RecursiveSpinLock g_011c3920;

struct PatrolActorPackageData
{
    bool IsPatrolling();
};

struct TESObjectREFR_Fake
{
    unsigned int GetFlags();
};

// Locks g_011c3920, walks the extra-data list and returns false on a disallowed type (0x16 also allowed when bwornignore), then unlocks and returns true.
// @fnv 0x0041d120
bool FUN_0041d120_shell::HasOnlyAllowedExtraData(bool bwornignore)
{
    g_011c3920.Lock(0);
    BSExtraData* work = pHead;
    while (work != 0)
    {
        if (bwornignore)
        {
            switch ((unsigned char)((PatrolActorPackageData*)work)->IsPatrolling())
            {
            case 0x0d:
            case 0x16:
            case 0x1c:
            case 0x20:
            case 0x21:
            case 0x24:
            case 0x27:
            case 0x2f:
            case 0x30:
            case 0x4a:
                break;
            default:
                g_011c3920.Unlock();
                return false;
            }
        }
        else
        {
            switch ((unsigned char)((PatrolActorPackageData*)work)->IsPatrolling())
            {
            case 0x0d:
            case 0x1c:
            case 0x20:
            case 0x21:
            case 0x24:
            case 0x27:
            case 0x2f:
            case 0x30:
            case 0x4a:
                break;
            default:
                g_011c3920.Unlock();
                return false;
            }
        }
        work = (BSExtraData*)((TESObjectREFR_Fake*)work)->GetFlags();
    }
    g_011c3920.Unlock();
    return true;
}
}  // namespace fnv_0041d120

namespace fnv_0041d280 {
struct FUN_0041d280_shell : public ExtraDataList
{
    void SetLeveledItemIndex(int);
};

void* __cdecl operator new(unsigned int);

class ExtraLeveledItem : public BSExtraData
{
  public:
    int iIndex;
    bool bCalculated;
    ExtraLeveledItem(int);
};

// Finds or creates the ExtraLeveledItem extra data, sets its iIndex to aiIndex and clears bCalculated.
// @fnv 0x0041d280
void FUN_0041d280_shell::SetLeveledItemIndex(int aiIndex)
{
    ExtraLeveledItem* pExtra = (ExtraLeveledItem*)GetExtraData(0x2F);
    if (!pExtra)
    {
        pExtra = new ExtraLeveledItem(aiIndex);
        AddExtra(pExtra);
    }
    else
    {
        pExtra->iIndex = aiIndex;
    }
    pExtra->bCalculated = false;
}
}  // namespace fnv_0041d280

struct FUN_0041d460_shell : public ExtraDataList
{
    TESObjectCELL* FUN_0041d460();
};

// Returns the TESObjectCELL stored in the extra data of type 0xc, or null if that extra data is absent.
// @fnv 0x0041d460
TESObjectCELL* FUN_0041d460_shell::FUN_0041d460()
{
    BSExtraData* pextra = GetExtraData(0xc);
    if (pextra)
    {
        return *(TESObjectCELL**)((char*)pextra + 0xc);
    }
    else
    {
        return 0;
    }
}

struct RagDollData;
struct FUN_0041d6d0_shell : public ExtraDataList
{
    RagDollData* FUN_0041d6d0();
};

// Retrieves the extra data of type 0x14 and returns the RagDollData pointer stored at offset 0xc, or null if absent.
// @fnv 0x0041d6d0
RagDollData* FUN_0041d6d0_shell::FUN_0041d6d0()
{
    BSExtraData* pextra = GetExtraData(0x14);
    if (pextra)
        return *(RagDollData**)((char*)pextra + 0xc);
    else
        return 0;
}

struct DurationData;
struct FUN_0041d8a0_shell : public TESPackage
{
    DurationData* FUN_0041d8a0();
};

// @fnv 0x0041d8a0
DurationData* FUN_0041d8a0_shell::FUN_0041d8a0()
{
    return (DurationData*)((char*)this + 0x38);
}

struct FUN_0041d8c0_shell : public ExtraDataList
{
    bool HasRunOncePackage(TESPackage*);
};

struct PackageReference
{
    TESPackage* pPackage;
};

struct RunOnceListNode;

PackageReference** __fastcall _ref_006815c0(RunOnceListNode* list);
RunOnceListNode* __fastcall _ref_00726070(RunOnceListNode* list);

struct ExtraRunOncePacks : public BSExtraData
{
    RunOnceListNode* pList;
};

// Checks the ExtraRunOncePacks list for a node whose package equals apPackage and returns true if found, otherwise false.
// @fnv 0x0041d8c0
bool FUN_0041d8c0_shell::HasRunOncePackage(TESPackage* apPackage)
{
    ExtraRunOncePacks* pextra = reinterpret_cast<ExtraRunOncePacks*>(GetExtraData(0x1b));
    if (pextra != 0)
    {
        RunOnceListNode* pCurrentElementNext = pextra->pList;
        while (pCurrentElementNext != 0 && *_ref_006815c0(pCurrentElementNext) != 0)
        {
            PackageReference* pRun = *_ref_006815c0(pCurrentElementNext);
            if (pRun->pPackage == apPackage)
            {
                return true;
            }
            pCurrentElementNext = _ref_00726070(pCurrentElementNext);
        }
    }
    return false;
}

struct FUN_0041da10_shell : public ExtraDataList
{
    TESObjectREFR* FUN_0041da10();
};

// Retrieves extra data of type 0x37 and returns the TESObjectREFR pointer stored at offset 0xc, or null if absent.
// @fnv 0x0041da10
TESObjectREFR* FUN_0041da10_shell::FUN_0041da10()
{
    BSExtraData* pextra = GetExtraData(0x37);
    if (pextra)
        return *(TESObjectREFR**)((char*)pextra + 0xc);
    return 0;
}

struct FUN_0041da40_shell : public ExtraDataList
{
    void FUN_0041da40(TESObjectREFR*);
};

void* __cdecl operator new(unsigned int);
void* __fastcall FUN_00433300(void*);

struct ExtraEnableStateParent_0041da40 : public BSExtraData
{
    TESObjectREFR* pParent;
    int unk10;
    ExtraEnableStateParent_0041da40()
    {
        FUN_00433300(this);
    }
};

// Sets the enable-state-parent extra data to apParent, creating it if missing, or removes that extra when apParent is null.
// @fnv 0x0041da40
void FUN_0041da40_shell::FUN_0041da40(TESObjectREFR* apParent)
{
    if (apParent)
    {
        ExtraEnableStateParent_0041da40* pextra = (ExtraEnableStateParent_0041da40*)GetExtraData(0x37);
        if (pextra)
        {
            pextra->pParent = apParent;
        }
        else
        {
            pextra = new ExtraEnableStateParent_0041da40;
            pextra->pParent = apParent;
            AddExtra(pextra);
        }
    }
    else
    {
        RemoveExtra(0x37);
    }
}

struct FUN_0041dc70_shell : public ExtraDataList
{
    void SetExtraFlags(unsigned char);
};

// Finds the extra data entry with type 0x37 and writes acFlags into its byte at offset 0x10.
// @fnv 0x0041dc70
void FUN_0041dc70_shell::SetExtraFlags(unsigned char acFlags)
{
    BSExtraData* pextra = GetExtraData(0x37);
    if (pextra)
    {
        *((unsigned char*)pextra + 0x10) = acFlags;
    }
}

struct FUN_0041de00_shell : public ExtraDataList
{
    TESObjectREFR* FUN_0041de00();
};

// Looks up extra data of type 0x39 and returns the TESObjectREFR pointer stored at offset 0xc, or null if absent.
// @fnv 0x0041de00
TESObjectREFR* FUN_0041de00_shell::FUN_0041de00()
{
    TESObjectREFR* pRef = 0;
    BSExtraData* pextra = GetExtraData(0x39);
    if (pextra)
    {
        pRef = *reinterpret_cast<TESObjectREFR**>(reinterpret_cast<char*>(pextra) + 0xc);
    }
    return pRef;
}

struct FUN_0041df90_shell : public ExtraDataList
{
    void* FUN_0041df90();
};

// Looks up extra data of type 0x3a and returns a pointer to the data at offset 0xc, or null if absent.
// @fnv 0x0041df90
void* FUN_0041df90_shell::FUN_0041df90()
{
    void* pretlist = 0;
    BSExtraData* pextra = GetExtraData(0x3a);
    if (pextra)
        pretlist = (char*)pextra + 0xc;
    return pretlist;
}

struct TESWaterForm;
struct FUN_0041e130_shell : public ExtraDataList
{
    TESWaterForm* FUN_0041e130();
};

// Retrieves extra data of type 3 from the list and returns the TESWaterForm pointer stored at offset 0xc, or null if absent.
// @fnv 0x0041e130
TESWaterForm* FUN_0041e130_shell::FUN_0041e130()
{
    BSExtraData* pextra = GetExtraData(3);
    if (pextra)
        return *(TESWaterForm**)((char*)pextra + 0xc);
    return 0;
}

namespace fnv_0041e160 {
struct BGSLoadFormBuffer;
struct BGSPlaceableWater;
struct BGSSaveFormBuffer;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiColor;
struct NiPoint3;
struct NiTexture;
struct SpellItem;
struct TESBoundObject;
struct TESForm;
struct TESSound;
struct TESWaterForm;
struct WaterShaderSettings;
struct blob8
{
    char b[8];
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
struct TESAttackDamageForm : public BaseFormComponent
{
    virtual unsigned short GetAttackDamage();
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned short GetAttackDamage(TESForm*);
    void SetAttackDamage(unsigned short);
    void* __vecDelDtor(unsigned int);
    unsigned short m_usAttackDamage;
    char _pad_6[2];
};
typedef char _sizecheck_TESAttackDamageForm[sizeof(TESAttackDamageForm) == 8 ? 1 : -1];
struct FUN_0041e160_shell : public ExtraDataList
{
    void SetCellWaterType(TESWaterForm*);
};

void* __cdecl operator new(unsigned int);
void* __fastcall FUN_0040f370(void* pThis);

struct ExtraCellWaterType : public BSExtraData
{
    TESWaterForm* m_pWaterForm;
    ExtraCellWaterType()
    {
        FUN_0040f370(this);
    }
};

// Sets the cell's water type extra data to apWater, creating it if absent, or removes the water type extra when apWater is null.
// @fnv 0x0041e160
void FUN_0041e160_shell::SetCellWaterType(TESWaterForm* apWater)
{
    if (apWater)
    {
        ExtraCellWaterType* pextra = (ExtraCellWaterType*)GetExtraData(3);
        if (pextra)
        {
            pextra->m_pWaterForm = apWater;
        }
        else
        {
            pextra = new ExtraCellWaterType;
            pextra->m_pWaterForm = apWater;
            AddExtra(pextra);
        }
    }
    else
    {
        RemoveExtra(3);
    }
}
}  // namespace fnv_0041e160

struct FUN_0041e310_shell : public ExtraDataList
{
    TESObjectREFR* FUN_0041e310();
};

// Retrieves the extra data of type 0x89 and returns the TESObjectREFR pointer stored at offset 0xc, or null if absent.
// @fnv 0x0041e310
TESObjectREFR* FUN_0041e310_shell::FUN_0041e310()
{
    BSExtraData* pextra = GetExtraData(0x89);
    if (pextra)
        return *(TESObjectREFR**)((char*)pextra + 0xc);
    return 0;
}

struct FUN_0041e410_shell : public ExtraDataList
{
    TESObjectREFR* FUN_0041e410();
};

// Retrieves extra data of type 0x51 and returns the TESObjectREFR pointer stored at offset 0xc, or null if absent.
// @fnv 0x0041e410
TESObjectREFR* FUN_0041e410_shell::FUN_0041e410()
{
    BSExtraData* pextra = GetExtraData(0x51);
    if (pextra)
        return *(TESObjectREFR**)((char*)pextra + 0xc);
    return 0;
}

struct FUN_0041e440_shell : public ExtraDataList
{
    void FUN_0041e440(TESObjectREFR*);
};

void* __cdecl operator new(unsigned int);
void* __fastcall FUN_00433640(void*);

struct ExtraLinkedRef_dummy : public BSExtraData
{
    TESObjectREFR* pRef;
    ExtraLinkedRef_dummy()
    {
        FUN_00433640(this);
    }
};

// Sets the linked reference extra data to apRef, creating and adding it if absent, or removes that extra data when apRef is null.
// @fnv 0x0041e440
void FUN_0041e440_shell::FUN_0041e440(TESObjectREFR* apRef)
{
    if (apRef)
    {
        ExtraLinkedRef_dummy* pextra = (ExtraLinkedRef_dummy*)GetExtraData(0x51);
        if (pextra)
        {
            pextra->pRef = apRef;
        }
        else
        {
            pextra = new ExtraLinkedRef_dummy();
            pextra->pRef = apRef;
            AddExtra(pextra);
        }
    }
    else
    {
        RemoveExtra(0x51);
    }
}

struct FUN_0041e500_shell : public ExtraDataList
{
    void* FUN_0041e500();
};

// @fnv 0x0041e500
void* FUN_0041e500_shell::FUN_0041e500()
{
    BSExtraData* pextra = GetExtraData(0x52);
    if (pextra)
        return (char*)pextra + 0xc;
    return 0;
}

struct ReferenceFloatEntry;
struct FUN_0041e780_shell : public ExtraDataList
{
    void* FUN_0041e780();
};

// @fnv 0x0041e780
void* FUN_0041e780_shell::FUN_0041e780()
{
    BSExtraData* pextra = GetExtraData(0x53);
    if (pextra)
        return (char*)pextra + 0xc;
    return 0;
}

struct ReferenceFloatEntry;
struct FUN_0041eb60_shell : public ExtraDataList
{
    bool FUN_0041eb60();
};

// Looks up extra data of type 0x53 and returns true if it exists and its byte at offset 0x14 has bit 0 set.
// @fnv 0x0041eb60
bool FUN_0041eb60_shell::FUN_0041eb60()
{
    BSExtraData* pextra = GetExtraData(0x53);
    if (pextra && (*((unsigned char*)pextra + 0x14) & 1))
    {
        return true;
    }
    return false;
}

struct ReferenceFloatEntry;
struct FUN_0041ece0_shell : public ExtraDataList
{
    void SetTextOverride(char*);
};

void* __cdecl operator new(unsigned int);

struct DummyExtra0x53 : public BSExtraData
{
    int pad[3];
    BSStringT<char> str;
    DummyExtra0x53();
};

int __fastcall FUN_004338b0(void*);

struct Extra0x53
{
    char pad[0x20];
    Extra0x53()
    {
        FUN_004338b0(this);
    }
};

// Gets extra data 0x53, creates and adds it when missing and a text override is given, then sets its string to pTextOverride.
// @fnv 0x0041ece0
void FUN_0041ece0_shell::SetTextOverride(char* pTextOverride)
{
    BSExtraData* pextra = GetExtraData(0x53);
    if (!pextra && pTextOverride)
    {
        pextra = (BSExtraData*)new Extra0x53();
        AddExtra(pextra);
    }
    if (pextra)
    {
        ((BSStringT<char>*)((char*)pextra + 0x18))->Set(pTextOverride, 0);
    }
}

struct FUN_0041eda0_shell : public ExtraDataList
{
    void* FUN_0041eda0();
};

// @fnv 0x0041eda0
void* FUN_0041eda0_shell::FUN_0041eda0()
{
    BSExtraData* pextra = GetExtraData(0x54);
    if (pextra)
        return (char*)pextra + 0xc;
    return 0;
}

struct FUN_0041edd0_shell : public ExtraDataList
{
    void FUN_0041edd0(TESObjectREFR*);
};

void* __cdecl operator new(unsigned int);

struct ReferenceFloatEntry
{
    TESObjectREFR* m_pFourthReference;
    float m_fDelay;
    ReferenceFloatEntry();
};

struct FakeList
{
    int a;
    int b;
};

struct FakeExtra;
void __fastcall FUN_00433790(FakeExtra*);

struct FakeExtra : public BSExtraData
{
    FakeList list;
    float f;
    FakeExtra()
    {
        FUN_00433790(this);
    }
};

bool __fastcall _ref_008256d0(FakeList*);
ReferenceFloatEntry** __fastcall _ref_006815c0(FakeList*);
FakeList* __fastcall _ref_00726070(FakeList*);

// @fnv 0x0041edd0
void FUN_0041edd0_shell::FUN_0041edd0(TESObjectREFR* apChild)
{
    if (apChild)
    {
        FakeExtra* pextra = (FakeExtra*)GetExtraData(0x54);
        if (!pextra)
        {
            pextra = new FakeExtra;
            AddExtra(pextra);
        }
        bool bfound = false;
        FakeList* pCurrentElementNext = &pextra->list;
        while (pCurrentElementNext && !_ref_008256d0(pCurrentElementNext) && !bfound)
        {
            if ((*_ref_006815c0(pCurrentElementNext))->m_pFourthReference == apChild)
            {
                bfound = true;
            }
            pCurrentElementNext = _ref_00726070(pCurrentElementNext);
        }
        if (!bfound)
        {
            ReferenceFloatEntry* ptemp = new ReferenceFloatEntry;
            ptemp->m_pFourthReference = apChild;
            ((BSSimpleList<char const*>*)&pextra->list)->AddHead(*(const char**)&ptemp);
        }
    }
}

struct FUN_0041f020_shell : public ExtraDataList
{
    float FUN_0041f020();
};

// Looks up extra data of type 0x54 and returns the float at offset 0x14, or -1.0f if absent.
// @fnv 0x0041f020
float FUN_0041f020_shell::FUN_0041f020()
{
    BSExtraData* pextra = GetExtraData(0x54);
    if (pextra)
    {
        return *(float*)((char*)pextra + 0x14);
    }
    return -1.0f;
}

struct ReferenceIntersectionData;
struct TESForm;
struct FUN_0041f050_shell : public ExtraDataList
{
    void* FUN_0041f050();
};

// @fnv 0x0041f050
void* FUN_0041f050_shell::FUN_0041f050()
{
    BSExtraData* pextra = GetExtraData(0x57);
    if (pextra)
        return (char*)pextra + 0xc;
    return 0;
}

struct TESForm;
struct FUN_0041f810_shell : public ExtraDataList
{
    void* FUN_0041f810();
};

// @fnv 0x0041f810
void* FUN_0041f810_shell::FUN_0041f810()
{
    BSExtraData* pextra = GetExtraData(0x85);
    if (pextra)
        return (char*)pextra + 0xc;
    return 0;
}

namespace fnv_0041fa60 {
struct BGSPrimitive;
struct BGSPrimitiveBox;
struct BGSPrimitiveVariant;
struct BGSPrimitivePlane;
struct BGSPrimitiveSphere;
struct BSFadeNode;
struct BSMultiBoundShape;
struct NiAVObject;
struct RgbaColor;
struct NiGeometry;
struct NiPoint2;
struct NiPoint3;
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
};
struct FUN_0041fa60_shell : public ExtraDataList
{
    void AddPrimitiveExtra(BGSPrimitive*);
};

class FUN_0041faf0 : public BSExtraData
{
  public:
    BGSPrimitive* m_pPrimitive;
    FUN_0041faf0(BGSPrimitive*);
};

// If apPrimitive is non-null, allocates a FUN_0041faf0 holding it and adds it to the extra data list.
// @fnv 0x0041fa60
void FUN_0041fa60_shell::AddPrimitiveExtra(BGSPrimitive* apPrimitive)
{
    if (apPrimitive)
    {
        FUN_0041faf0* pextra = new FUN_0041faf0(apPrimitive);
        AddExtra(pextra);
    }
}
}  // namespace fnv_0041fa60

struct BGSPrimitive;
struct FUN_0041fbe0_shell : public ExtraDataList
{
    BGSPrimitive* FUN_0041fbe0();
};

// Looks up extra data of type 0x6b and returns the BGSPrimitive pointer stored at offset 0xc, or null if absent.
// @fnv 0x0041fbe0
BGSPrimitive* FUN_0041fbe0_shell::FUN_0041fbe0()
{
    BSExtraData* pextra = GetExtraData(0x6b);
    if (pextra)
        return *(BGSPrimitive**)((char*)pextra + 0xc);
    return 0;
}

struct PatrolRefData;
struct FUN_0041fe90_shell : public ExtraDataList
{
    PatrolRefData* FUN_0041fe90();
};

// Returns the PatrolRefData pointer stored at offset 0xc of the extra data entry with type 0x6f, or null if absent.
// @fnv 0x0041fe90
PatrolRefData* FUN_0041fe90_shell::FUN_0041fe90()
{
    BSExtraData* pextra = GetExtraData(0x6f);
    if (pextra)
    {
        return *(PatrolRefData**)((char*)pextra + 0xc);
    }
    else
    {
        return 0;
    }
}

struct PointerFlagNode;
struct FUN_00420810_shell : public ExtraDataList
{
    bool FUN_00420810();
};

bool __fastcall _ref_008256d0(void* thisPtr);

// Looks up extra data 0x7B; returns true if it is absent, or if its byte at +0x10 is set or the call on its +8 subobject succeeds.
// @fnv 0x00420810
bool FUN_00420810_shell::FUN_00420810()
{
    BSExtraData* pextra = GetExtraData(0x7B);
    if (pextra)
    {
        if (*((unsigned char*)*((void**)((char*)pextra + 0x0C)) + 0x10))
        {
            return true;
        }
        else if (_ref_008256d0((char*)*((void**)((char*)pextra + 0x0C)) + 8))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return true;
}

struct ActorPackageData;
struct FUN_004212b0_shell : public ExtraDataList
{
    ActorPackageData* FUN_004212b0();
};

struct ExtraPackageData : public BSExtraData
{
    ActorPackageData* pData;  // +0xC
};

// Looks up extra data of type 0x70 on this list and returns its pData, or null if absent.
// @fnv 0x004212b0
ActorPackageData* FUN_004212b0_shell::FUN_004212b0()
{
    ExtraPackageData* pextra = (ExtraPackageData*)GetExtraData(0x70);
    if (pextra)
        return pextra->pData;
    else
        return 0;
}

namespace fnv_00421310 {
struct ActiveEffect;
struct Actor;
struct ActorMover;
struct ActorValueOwner;
struct AlchemyItem;
struct Animation;
struct BGSImpactDataSet;
struct BGSLoadFormBuffer;
struct BGSPerk;
struct BGSPerkEntry;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BSAnimGroupSequence;
struct BSAnimNote;
struct BSFaceGenAnimationData;
struct SoundPlaybackHandle;
struct BaseProcess;
struct BipedAnim;
struct CombatGroupCollection;
struct CombatController;
struct ActorCombatGroup;
struct ContinuousBeamProjectile;
struct Crime;
struct DialogueResponse;
struct DetectionParameters;
struct EffectItem;
struct FurnitureMark;
struct BooleanFloatQuery;
struct IDebugText;
struct InventoryStackRecord;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct MobileObject;
struct NiAVObject;
struct NiNode;
struct NiPoint3;
struct LocationDescriptor;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct PathingRequest;
struct Projectile;
struct QueuedFile;
struct SpellItem;
struct TESActorBase;
struct TESBoundObject;
struct TESClass;
struct TESCombatStyle;
struct TESFaction;
struct TESForm;
struct TESIdleForm;
struct TESObject;
struct TESObjectBOOK;
struct TESObjectWEAP;
struct TESRace;
struct TESSkill;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct TrespassPackage;
struct WeaponObject;
struct bhkCharacterController;
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
struct FUN_00421310_shell : public ExtraDataList
{
    void EnsureGuardedRefData(Actor*);
};

void* __cdecl operator new(unsigned int);
void __fastcall FUN_00430f30(void*);

class ExtraGuardedRefData : public BSExtraData
{
  public:
    char pad[0x10];
    ExtraGuardedRefData();
    void AddGuardingActor(Actor*);
};

struct ExtraGuardedRefData_New
{
    char pad[0x1c];
    ExtraGuardedRefData_New()
    {
        FUN_00430f30(this);
    }
};

// Gets the 0x7c extra data list entry, creating and adding an ExtraGuardedRefData if absent, then passes apActor to it.
// @fnv 0x00421310
void FUN_00421310_shell::EnsureGuardedRefData(Actor* apActor)
{
    ExtraGuardedRefData* pextra = (ExtraGuardedRefData*)GetExtraData(0x7c);
    if (!pextra)
    {
        pextra = (ExtraGuardedRefData*)new ExtraGuardedRefData_New;
        AddExtra(pextra);
    }
    pextra->AddGuardingActor(apActor);
}
}  // namespace fnv_00421310

struct Extra_7C : public BSExtraData
{
    void NotifyQuestActors(int a1, int a2);
};

struct FUN_004213c0_impl : public ExtraDataList
{
    void FUN_004213c0(int a1, int a2);
};

// Looks up the extra data of type 0x7c in this list and, if present, forwards both arguments to its handler.
// @fnv 0x004213c0
void FUN_004213c0_impl::FUN_004213c0(int aiArg1, int aiArg2)
{
    Extra_7C* pExtra = static_cast<Extra_7C*>(GetExtraData(0x7c));
    if (pExtra)
    {
        pExtra->NotifyQuestActors(aiArg1, aiArg2);
    }
}

struct FUN_004214f0_shell : public ExtraDataList
{
    void GetForceMultAndAllBelowFlag(float*, int*);
};

float __fastcall FUN_004350c0(BSExtraData*);
int __fastcall FUN_00435100(BSExtraData*);

// Sets the multiplier to 1.0 and the flag to 0, then if extra data 0x1e exists, reads the multiplier and flag from it.
// @fnv 0x004214f0
void FUN_004214f0_shell::GetForceMultAndAllBelowFlag(float* afOutMult, int* aiOutAllBelowForce)
{
    *afOutMult = 1.0f;
    *aiOutAllBelowForce = 0;
    BSExtraData* pextra = GetExtraData(0x1e);
    if (pextra)
    {
        *afOutMult = FUN_004350c0(pextra);
        *aiOutAllBelowForce = FUN_00435100(pextra);
    }
}

struct FUN_00421540_shell : public ExtraDataList
{
    void FUN_00421540(int);
};

void* __cdecl operator new(unsigned int);
void* __fastcall ExtraLevCreaModifierCtor(void*);

struct ExtraLevCreaModifier_00421540 : public BSExtraData
{
    int iModifier;
    ExtraLevCreaModifier_00421540()
    {
        ExtraLevCreaModifierCtor(this);
    }
};

// @fnv 0x00421540
void FUN_00421540_shell::FUN_00421540(int aiVal)
{
    if (aiVal != 4)
    {
        ExtraLevCreaModifier_00421540* pextra = (ExtraLevCreaModifier_00421540*)GetExtraData(0x1E);
        if (pextra)
        {
            pextra->iModifier = aiVal;
        }
        else
        {
            pextra = new ExtraLevCreaModifier_00421540;
            pextra->iModifier = aiVal;
            AddExtra(pextra);
        }
    }
    else
    {
        RemoveExtra(0x1E);
    }
}

struct SeenData;
struct FUN_00421910_shell : public ExtraDataList
{
    SeenData* FUN_00421910();
};

// Retrieves extra data of type 5 and returns the SeenData pointer stored at offset 0xc, or null if absent.
// @fnv 0x00421910
SeenData* FUN_00421910_shell::FUN_00421910()
{
    BSExtraData* pextra = GetExtraData(5);
    if (pextra)
        return *(SeenData**)((char*)pextra + 0xc);
    return 0;
}

struct FUN_00421a70_shell : public ExtraDataList
{
    void FUN_00421a70(float);
};

class ExtraNorthRotation : public BSExtraData
{
  public:
    float fNorthRotation;
    ExtraNorthRotation();
};

// Sets the north rotation extra data to afVal, creating and adding it if missing, or removes the extra when afVal is zero.
// @fnv 0x00421a70
void FUN_00421a70_shell::FUN_00421a70(float afVal)
{
    if (afVal != 0.0)
    {
        ExtraNorthRotation* pextra = (ExtraNorthRotation*)GetExtraData(0x43);
        if (pextra)
        {
            pextra->fNorthRotation = afVal;
        }
        else
        {
            pextra = new ExtraNorthRotation();
            pextra->fNorthRotation = afVal;
            AddExtra(pextra);
        }
    }
    else
    {
        RemoveExtra(0x43);
    }
}

struct FUN_00421b40_shell : public ExtraDataList
{
    TESObjectREFR* FUN_00421b40();
};

// Retrieves the extra data of type 0x44 and returns the TESObjectREFR pointer stored at offset 0xc, or null if absent.
// @fnv 0x00421b40
TESObjectREFR* FUN_00421b40_shell::FUN_00421b40()
{
    BSExtraData* pextra = GetExtraData(0x44);
    if (pextra)
        return *(TESObjectREFR**)((char*)pextra + 0xc);
    return 0;
}

struct BGSEncounterZone;
struct FUN_00421c30_shell : public ExtraDataList
{
    BGSEncounterZone* FUN_00421c30();
};

// Retrieves the extra data of type 0x74 and returns the BGSEncounterZone pointer stored at offset 0xc, or null if absent.
// @fnv 0x00421c30
BGSEncounterZone* FUN_00421c30_shell::FUN_00421c30()
{
    BSExtraData* pextra = GetExtraData(0x74);
    if (pextra)
        return *(BGSEncounterZone**)((char*)pextra + 0xc);
    return 0;
}

struct TESForm;
struct FUN_00421d20_shell : public ExtraDataList
{
    TESForm* FUN_00421d20();
};

// Looks up extra data of type 0x67 and returns the TESForm pointer stored at offset 0xc, or null if absent.
// @fnv 0x00421d20
TESForm* FUN_00421d20_shell::FUN_00421d20()
{
    BSExtraData* pextra = GetExtraData(0x67);
    if (pextra)
        return *(TESForm**)((char*)pextra + 0xc);
    return 0;
}

struct FUN_00421e10_shell : public ExtraDataList
{
    TESObjectREFR* FUN_00421e10();
};

// Retrieves extra data of type 0x63 and returns the TESObjectREFR pointer stored at offset 0xc, or null if absent.
// @fnv 0x00421e10
TESObjectREFR* FUN_00421e10_shell::FUN_00421e10()
{
    BSExtraData* pextra = GetExtraData(0x63);
    if (pextra)
        return *(TESObjectREFR**)((char*)pextra + 0xc);
    return 0;
}

struct FUN_00421e40_shell : public ExtraDataList
{
    void FUN_00421e40(TESObjectREFR*);
};

void* __cdecl operator new(unsigned int);

struct ExtraMultiBoundRef_00435510 : public BSExtraData
{
    TESObjectREFR* m_pReference;  // +0xc
    ExtraMultiBoundRef_00435510()
    {
        ((ExtraMultiBoundRef_00435510 * (__thiscall*)(ExtraMultiBoundRef_00435510*))0x00435510)(this);
    }
};

void* __fastcall FUN_00435510(void* pThis);

struct ExtraMultiBoundRef_Stub : public BSExtraData
{
    TESObjectREFR* m_pReference;
    ExtraMultiBoundRef_Stub()
    {
        FUN_00435510(this);
    }
};

// Stores apRef in the extra data of type 0x63, creating it if absent, or removes that extra data when apRef is null.
// @fnv 0x00421e40
void FUN_00421e40_shell::FUN_00421e40(TESObjectREFR* apRef)
{
    if (apRef)
    {
        ExtraMultiBoundRef_Stub* pextra = (ExtraMultiBoundRef_Stub*)GetExtraData(0x63);
        if (pextra)
        {
            pextra->m_pReference = apRef;
        }
        else
        {
            pextra = new ExtraMultiBoundRef_Stub;
            pextra->m_pReference = apRef;
            AddExtra(pextra);
        }
    }
    else
    {
        RemoveExtra(0x63);
    }
}

struct BSMultiBound;
struct BSMultiBoundRoom;
struct NiNode;
struct Point3Offset
{
    void Save();
    bool Load(TESFile*);
    bool Compare(Point3Offset*);
    void Copy(Point3Offset*);
    bool IsDefault();
    void* GetHalfExtents();
    void SetHalfExtents(void*);
    static void* GetDefaultHalfExtents();
    static void* GetDrawColor();
    static NiNode* DrawMultiBound(Point3Offset*);
    static BSMultiBound* CreateMultiBoundForRef(TESObjectREFR*);
    static BSMultiBoundRoom* CreateRoomForRef(TESObjectREFR*);
    static bool IsRefEligibleForMultiBound(TESObjectREFR*, int, int);
    char m_kOffset[12];
};
typedef char _sizecheck_MultiBoundMarkerData[sizeof(Point3Offset) == 12 ? 1 : -1];
struct FUN_00421f30_shell : public ExtraDataList
{
    void FUN_00421f30(Point3Offset*);
};

void __cdecl Deallocate(void*);

class ExtraMultiBoundData : public BSExtraData
{
  public:
    ExtraMultiBoundData();
    Point3Offset* pData;
};

// Stores apData in the 0x62 extra data, replacing and freeing any previous data, or removes that extra when apData is null.
// @fnv 0x00421f30
void FUN_00421f30_shell::FUN_00421f30(Point3Offset* apData)
{
    if (apData)
    {
        ExtraMultiBoundData* pextra = static_cast<ExtraMultiBoundData*>(GetExtraData(0x62));
        if (pextra)
        {
            if (pextra->pData)
            {
                Point3Offset* pOld = pextra->pData;
                Deallocate(pOld);
            }
            pextra->pData = apData;
        }
        else
        {
            pextra = new ExtraMultiBoundData();
            pextra->pData = apData;
            AddExtra(pextra);
        }
    }
    else
    {
        RemoveExtra(0x62);
    }
}

struct BSOcclusionPlane;
struct FUN_00422120_shell : public ExtraDataList
{
    BSOcclusionPlane* FUN_00422120();
};

struct BSStringT_char
{
    operator const char*() const;
};
struct ExData
{
    char pad[0xc];
    BSStringT_char s;
};
// Retrieves the extra data of type 0x71 and returns its string as a BSOcclusionPlane pointer, or null if absent.
// @fnv 0x00422120
BSOcclusionPlane* FUN_00422120_shell::FUN_00422120()
{
    ExData* d = (ExData*)GetExtraData(0x71);
    if (d)
        return (BSOcclusionPlane*)(const char*)d->s;
    return 0;
}

struct BSOcclusionPlane;
struct FUN_00422150_shell : public ExtraDataList
{
    void FUN_00422150(BSOcclusionPlane*);
};

class NiNode;

// NiNode is incomplete here: call the out-of-line assignment instead of instantiating the canonical inline body.
template <> NiPointer<NiNode>& NiPointer<NiNode>::operator=(NiNode*);

class FUN_004357a0 : public BSExtraData
{
  public:
    NiPointer<NiNode> m_spNode;
    FUN_004357a0();
};

// Stores apPlane in the extra data of type 0x71, creating it if missing, or removes that extra data when apPlane is null.
// @fnv 0x00422150
void FUN_00422150_shell::FUN_00422150(BSOcclusionPlane* apPlane)
{
    if (apPlane)
    {
        FUN_004357a0* pextra = (FUN_004357a0*)GetExtraData(0x71);
        if (pextra)
        {
            pextra->m_spNode = (NiNode*)apPlane;
        }
        else
        {
            pextra = new FUN_004357a0();
            pextra->m_spNode = (NiNode*)apPlane;
            AddExtra(pextra);
        }
    }
    else
    {
        RemoveExtra(0x71);
    }
}

struct FUN_00422220_shell : public ExtraDataList
{
    void FUN_00422220(float);
};

struct ExtraRadius_dummy;
ExtraRadius_dummy* __fastcall FUN_004222f0(ExtraRadius_dummy*, int, float);

struct ExtraRadius_dummy : public BSExtraData
{
    float fRadius;
    ExtraRadius_dummy(float afRadius)
    {
        FUN_004222f0(this, 0, afRadius);
    }
};

// @fnv 0x00422220
void FUN_00422220_shell::FUN_00422220(float afRadius)
{
    if (afRadius == 0.0)
    {
        RemoveExtra(0x5c);
    }
    else
    {
        ExtraRadius_dummy* pextra = (ExtraRadius_dummy*)GetExtraData(0x5c);
        if (pextra)
        {
            pextra->fRadius = afRadius;
        }
        else
        {
            pextra = new ExtraRadius_dummy(afRadius);
            AddExtra(pextra);
        }
    }
}

struct FUN_00422320_shell : public ExtraDataList
{
    float FUN_00422320();
};

// Looks up extra data of type 0x5C and returns the float at offset 0xC, or 0.0 if absent.
// @fnv 0x00422320
float FUN_00422320_shell::FUN_00422320()
{
    BSExtraData* pextra = GetExtraData(0x5C);
    if (pextra)
        return *(float*)((char*)pextra + 0xC);
    return 0.0f;
}

struct FUN_00422350_shell : public ExtraDataList
{
    void SetRadiation(float);
};

void* __cdecl operator new(unsigned int);

struct ExtraRadiation_00422350 : public BSExtraData
{
    float m_fRadiation;  // +0xc
};

void* __fastcall FUN_00422420(void* pThis, int, float afRadiation);

struct HelperNew_00422350 : public ExtraRadiation_00422350
{
    HelperNew_00422350(float afRadiation)
    {
        FUN_00422420(this, 0, afRadiation);
    }
};

// Sets the radiation extra data to afRadiation, removing it when zero, updating the existing extra, or allocating and adding a new one.
// @fnv 0x00422350
void FUN_00422350_shell::SetRadiation(float afRadiation)
{
    if (afRadiation == 0.0)
    {
        RemoveExtra(0x5d);
    }
    else
    {
        ExtraRadiation_00422350* pextra = (ExtraRadiation_00422350*)GetExtraData(0x5d);
        if (pextra)
        {
            pextra->m_fRadiation = afRadiation;
        }
        else
        {
            pextra = new HelperNew_00422350(afRadiation);
            AddExtra(pextra);
        }
    }
}

namespace fnv_00422480 {
struct ActiveEffect;
struct Actor;
struct ActorMover;
struct ActorValueOwner;
struct AlchemyItem;
struct Animation;
struct BGSImpactDataSet;
struct BGSLoadFormBuffer;
struct BGSPerk;
struct BGSPerkEntry;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BSAnimGroupSequence;
struct BSAnimNote;
struct BSFaceGenAnimationData;
struct SoundPlaybackHandle;
struct BaseProcess;
struct BipedAnim;
struct CombatGroupCollection;
struct CombatController;
struct ActorCombatGroup;
struct ContinuousBeamProjectile;
struct Crime;
struct DialogueResponse;
struct DetectionParameters;
struct EffectItem;
struct FurnitureMark;
struct BooleanFloatQuery;
struct IDebugText;
struct InventoryStackRecord;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct MobileObject;
struct NiAVObject;
struct NiNode;
struct NiPoint3;
struct LocationDescriptor;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct PathingRequest;
struct Projectile;
struct QueuedFile;
struct SpellItem;
struct TESActorBase;
struct TESBoundObject;
struct TESClass;
struct TESCombatStyle;
struct TESFaction;
struct TESForm;
struct TESIdleForm;
struct TESObject;
struct TESObjectBOOK;
struct TESObjectWEAP;
struct TESRace;
struct TESSkill;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct TrespassPackage;
struct WeaponObject;
struct bhkCharacterController;
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
struct FUN_00422480_shell : public ExtraDataList
{
    void FUN_00422480(Actor*);
};

struct PlayerCharacter;
extern PlayerCharacter* pPlayer;

template <> class BSSimpleList<Actor*>
{
  public:
    bool IsInList(Actor* const&) const;
};

class ExtraFollower : public BSExtraData
{
  public:
    ExtraFollower();
    BSSimpleList<Actor*>* pFollowers;  // +0xC
};

// Adds apActor to the ExtraFollower list on this extra data list, creating the ExtraFollower if absent, unless apActor is the player.
// @fnv 0x00422480
void FUN_00422480_shell::FUN_00422480(Actor* apActor)
{
    if (apActor == (Actor*)pPlayer)
        return;

    ExtraFollower* pextra = (ExtraFollower*)GetExtraData(0x1D);
    if (!pextra)
    {
        pextra = new ExtraFollower;
        AddExtra(pextra);
    }

    if (!pextra->pFollowers->IsInList(apActor))
    {
        ((BSSimpleList<char const*>*)pextra->pFollowers)->AddHead((char const*&)apActor);
    }
}
}  // namespace fnv_00422480

namespace fnv_00422690 {
struct ActiveEffect;
struct Actor;
struct ActorMover;
struct ActorValueOwner;
struct AlchemyItem;
struct Animation;
struct BGSImpactDataSet;
struct BGSLoadFormBuffer;
struct BGSPerk;
struct BGSPerkEntry;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BSAnimGroupSequence;
struct BSAnimNote;
struct BSFaceGenAnimationData;
struct SoundPlaybackHandle;
struct BaseProcess;
struct BipedAnim;
struct CombatGroupCollection;
struct CombatController;
struct ActorCombatGroup;
struct ContinuousBeamProjectile;
struct Crime;
struct DialogueResponse;
struct DetectionParameters;
struct EffectItem;
struct FurnitureMark;
struct BooleanFloatQuery;
struct IDebugText;
struct InventoryStackRecord;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct MobileObject;
struct NiAVObject;
struct NiNode;
struct NiPoint3;
struct LocationDescriptor;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct PathingRequest;
struct Projectile;
struct QueuedFile;
struct SpellItem;
struct TESActorBase;
struct TESBoundObject;
struct TESClass;
struct TESCombatStyle;
struct TESFaction;
struct TESForm;
struct TESIdleForm;
struct TESObject;
struct TESObjectBOOK;
struct TESObjectWEAP;
struct TESRace;
struct TESSkill;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct TrespassPackage;
struct WeaponObject;
struct bhkCharacterController;
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
struct FUN_00422690_shell : public ExtraDataList
{
    void FUN_00422690(Actor*);
};

struct _ref_00905330_s
{
    void _ref_00905330(Actor**);
};
struct _saveload_s
{
    bool GetLoading();
};
struct _datahandler_s
{
    bool FUN_004226e0();
};

extern _saveload_s* g_TESSaveLoadGame;
extern _datahandler_s* g_dataHandler;

// @fnv 0x00422690
void FUN_00422690_shell::FUN_00422690(Actor* apActor)
{
    BSExtraData* pextra = this->GetExtraData(0x1d);
    if (pextra)
    {
        ((_ref_00905330_s*)*(void**)((char*)pextra + 0xc))->_ref_00905330(&apActor);
        if (!g_TESSaveLoadGame->GetLoading())
        {
            g_dataHandler->FUN_004226e0();
        }
    }
}
}  // namespace fnv_00422690

struct FUN_004226e0_shell : public TESDataHandler
{
    bool FUN_004226e0();
};

// @fnv 0x004226e0
bool FUN_004226e0_shell::FUN_004226e0()
{
    return *((bool*)this + 0x61d);
}

struct ExtraFollower;
struct FUN_00422700_shell : public ExtraDataList
{
    ExtraFollower* FUN_00422700();
};

// @fnv 0x00422700
ExtraFollower* FUN_00422700_shell::FUN_00422700()
{
    ExtraFollower* pextra = reinterpret_cast<ExtraFollower*>(GetExtraData(0x1D));
    return pextra;
}

struct ExtraRefractionProperty;
struct FUN_00422820_shell : public ExtraDataList
{
    ExtraRefractionProperty* GetRefractionProperty();
};

// Returns the ExtraRefractionProperty stored under extra-data type 0x48, or null if none is present.
// @fnv 0x00422820
ExtraRefractionProperty* FUN_00422820_shell::GetRefractionProperty()
{
    ExtraRefractionProperty* pextra = (ExtraRefractionProperty*)GetExtraData(0x48);
    if (pextra)
        return pextra;
    else
        return 0;
}

struct FUN_00422850_shell : public ExtraDataList
{
    void FUN_00422850(char*);
};

void __fastcall FUN_00422920(void*);

struct FUN_004351d0 : public BSExtraData
{
    int unk0C;
    FUN_004351d0(char*);
};

// @fnv 0x00422850
void FUN_00422850_shell::FUN_00422850(char* apSequenceName)
{
    FUN_00422920(this);
    if (apSequenceName)
    {
        FUN_004351d0* plast = new FUN_004351d0(apSequenceName);
        AddExtra(plast);
    }
}

struct FUN_00422920_shell : public ExtraDataList
{
    void FUN_00422920();
};

// @fnv 0x00422920
void FUN_00422920_shell::FUN_00422920()
{
    RemoveExtra(0x41);
}

struct FUN_00422a40_shell : public ExtraDataList
{
    bool FUN_00422a40(TESObjectREFR*);
};

class FormChangeMask
{
  public:
    int m_flags;
    FormChangeMask(int);
};

class BGSLoadGameSubBuffer
{
  public:
    void RestoreAnimation(TESForm*);
};

// If extra data of type 0x42 exists, passes apRef to a sub-buffer call on its field at offset 0xc, clears that field, removes the extra data and returns true.
// @fnv 0x00422a40
bool FUN_00422a40_shell::FUN_00422a40(TESObjectREFR* apRef)
{
    BSExtraData* pExtra = GetExtraData(0x42);
    if (pExtra)
    {
        ((BGSLoadGameSubBuffer*)&FormChangeMask(*(int*)((char*)pExtra + 0xc)))->RestoreAnimation((TESForm*)apRef);
        *(int*)((char*)pExtra + 0xc) = 0;
        RemoveExtra(0x42);
        return true;
    }
    return false;
}

struct FUN_00422aa0_shell : public ExtraDataList
{
    void FUN_00422aa0();
};

// @fnv 0x00422aa0
void FUN_00422aa0_shell::FUN_00422aa0()
{
    RemoveExtra(0x42);
}

namespace fnv_00422bc0 {
struct FUN_00422bc0_shell : public ExtraDataList
{
    bool FUN_00422bc0(TESObjectREFR*);
};

class TESForm;

class BGSLoadGameSubBuffer
{
  public:
    int m_buf;
    void LoadHavokData(TESForm*);
};

class FormChangeMask : public BGSLoadGameSubBuffer
{
  public:
    FormChangeMask(int);
};

// Finds extra data of type 0x3D, loads its Havok data onto apRef, clears the field, removes the extra data and returns true if found.
// @fnv 0x00422bc0
bool FUN_00422bc0_shell::FUN_00422bc0(TESObjectREFR* apRef)
{
    BSExtraData* pextra = GetExtraData(0x3D);
    if (pextra)
    {
        FormChangeMask(*reinterpret_cast<int*>(reinterpret_cast<char*>(pextra) + 0xC))
            .LoadHavokData(reinterpret_cast<TESForm*>(apRef));
        *reinterpret_cast<int*>(reinterpret_cast<char*>(pextra) + 0xC) = 0;
        RemoveExtra(0x3D);
        return true;
    }
    return false;
}
}  // namespace fnv_00422bc0

namespace fnv_004280f0 {
struct TESForm;
struct blob4
{
    char b[4];
};
struct FormChangeMask
{
    bool ContainsAnyFlags(int);
    bool CheckFlagsExact(int);
    bool CheckFlagsExclusive(int);
    void SetFlags(int);
    void AddFlags(int);
    void RemoveFlags(int);
    struct blob4 GetDifference(int);
    static char* GetFullFlagName(int, unsigned int, bool);
    static char* GetShortFlagName(int, unsigned int);
    static bool IsFlagSetForType(int, unsigned int, unsigned int);
    bool HasFormChanged(TESForm*);
    static struct blob4 CombineFlags(struct blob4, struct blob4, unsigned int, bool);
    int iFlags;
};
typedef char _sizecheck_BGSChangeFlags[sizeof(FormChangeMask) == 4 ? 1 : -1];
struct FUN_004280f0_shell : public FormChangeMask
{
    bool FUN_004280f0(int);
};

// @fnv 0x004280f0
bool FUN_004280f0_shell::FUN_004280f0(int aiFlags)
{
    return (iFlags & aiFlags) ? true : false;
}
}  // namespace fnv_004280f0

struct FUN_0042cde0_shell : public InventoryChanges
{
    bool FUN_0042cde0();
};

bool __fastcall _ref_008256d0(void*);

// @fnv 0x0042cde0
bool FUN_0042cde0_shell::FUN_0042cde0()
{
    return _ref_008256d0(*reinterpret_cast<void**>(this));
}

namespace fnv_0042ce10 {
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
struct FUN_0042ce10_shell : public BGSSaveLoadGame
{
    bool FUN_0042ce10();
};

// @fnv 0x0042ce10
bool FUN_0042ce10_shell::FUN_0042ce10()
{
    return (m_uiInitializationFlags & 2) ? true : false;
}
}  // namespace fnv_0042ce10

namespace fnv_0042d9e0 {
struct ActiveEffect;
struct Actor;
struct AlchemyItem;
struct SaveLoadFile;
struct EffectItem;
struct MagicCaster;
struct MagicItem;
struct MagicTarget;
struct ThreeByThreeMatrix;
struct NiPoint3;
struct NiQuaternion;
struct TESBoundObject;
struct TESForm;
struct TESTopic;
struct TESTopicInfo;
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
struct FUN_0042d9e0_shell : public ExtraDataList
{
    void FUN_0042d9e0(BGSLoadFormBuffer*);
};

extern unsigned int DAT_01183f04;
extern unsigned int DAT_01183dfc;
void __cdecl HandleMobileObjectResult(unsigned int, bool);

struct FormChangeMask
{
    unsigned int iFlags;
    bool __thiscall operator()(unsigned int) const;
};

struct ActiveEffect
{
    static void __cdecl WriteActiveEffectList(BGSLoadFormBuffer*, BSSimpleList<ActiveEffect*>*);
};

struct TESSound
{
    unsigned int Deallocate();
};

// @fnv 0x0042d9e0
void FUN_0042d9e0_shell::FUN_0042d9e0(BGSLoadFormBuffer* apLoadGameBuffer)
{
    TESObjectREFR* pref = apLoadGameBuffer->GetReference();
    if (((FormChangeMask*)&apLoadGameBuffer->GetChangeFlags())->operator()(DAT_01183f04))
    {
        BSExtraData* pextraSayToTopicInfo = GetExtraData(0x75);
        if (pextraSayToTopicInfo && pref)
        {
            if (((bool(__thiscall*)(TESObjectREFR*))(*(void***)pref)[0xfc / 4])(pref))
            {
                if (*(int*)((char*)pextraSayToTopicInfo + 0x10) && *(int*)((char*)pextraSayToTopicInfo + 0xc))
                {
                    HandleMobileObjectResult(((TESSound*)pref)->Deallocate(), true);
                }
                else
                {
                    HandleMobileObjectResult(((TESSound*)pref)->Deallocate(), false);
                }
            }
            else
            {
                *((unsigned char*)pextraSayToTopicInfo + 0x18) = 1;
            }
        }
    }
    if (pref)
    {
        if (((FormChangeMask*)&apLoadGameBuffer->GetChangeFlags())->operator()(DAT_01183dfc))
        {
            BSExtraData* pextraNonActorMagicTarget = GetExtraData(0x33);
            if (pextraNonActorMagicTarget)
            {
                ActiveEffect::WriteActiveEffectList(
                    apLoadGameBuffer, (BSSimpleList<ActiveEffect*>*)((char*)pextraNonActorMagicTarget + 0x20));
            }
        }
    }
}
}  // namespace fnv_0042d9e0

struct TESForm;
struct TESModel;
struct FUN_0042e250_shell : public ExtraDataList
{
    TESModel* FUN_0042e250();
};

// Retrieves the extra data of type 0x5b and returns the TESModel pointer stored at offset 0xc, or null if absent.
// @fnv 0x0042e250
TESModel* FUN_0042e250_shell::FUN_0042e250()
{
    BSExtraData* pextra = GetExtraData(0x5b);
    if (pextra)
        return *(TESModel**)((char*)pextra + 0xc);
    return 0;
}

struct ExtraNavMeshPortal;
struct FUN_0042e2a0_shell : public ExtraDataList
{
    ExtraNavMeshPortal* GetExtraNavMeshPortal();
};

// @fnv 0x0042e2a0
ExtraNavMeshPortal* FUN_0042e2a0_shell::GetExtraNavMeshPortal()
{
    ExtraNavMeshPortal* pextra = reinterpret_cast<ExtraNavMeshPortal*>(GetExtraData(0x5a));
    return pextra;
}

struct FUN_0042e560_shell : public ExtraDataList
{
    unsigned char FUN_0042e560();
};

class BGSSaveLoadManager
{
  public:
    bool FUN_00424940();
};

// Gets the extra data of type 0x8D and returns the result of its FUN_00424940 call, or 0 if absent.
// @fnv 0x0042e560
unsigned char FUN_0042e560_shell::FUN_0042e560()
{
    BGSSaveLoadManager* pExtra = (BGSSaveLoadManager*)GetExtraData(0x8D);
    if (pExtra)
    {
        return pExtra->FUN_00424940();
    }
    else
    {
        return 0;
    }
}

struct TESActorBase;
struct TESFaction;
struct FUN_0042e760_shell : public ExtraDataList
{
    void FUN_0042e760();
};

void* __cdecl operator new(unsigned int);

struct ExtraFactionChanges : public BSExtraData
{
    int unk0C;
    ExtraFactionChanges();
};

// Retrieves the extra data of type 0x5e, creating and adding a new ExtraFactionChanges if none exists.
// @fnv 0x0042e760
void FUN_0042e760_shell::FUN_0042e760()
{
    ExtraFactionChanges* pextra = (ExtraFactionChanges*)GetExtraData(0x5e);
    if (!pextra)
    {
        pextra = new ExtraFactionChanges;
        AddExtra(pextra);
    }
}

struct ExtraFactionChanges;
struct TESActorBase;
struct TESFaction;
struct FUN_0042e800_shell : public ExtraDataList
{
    ExtraFactionChanges* FUN_0042e800();
};

// @fnv 0x0042e800
ExtraFactionChanges* FUN_0042e800_shell::FUN_0042e800()
{
    ExtraFactionChanges* pextra = reinterpret_cast<ExtraFactionChanges*>(GetExtraData(0x5E));
    return pextra;
}

struct ExtraAmmo;
struct TESAmmo;
struct FUN_0042eb40_shell : public ExtraDataList
{
    ExtraAmmo* GetExtraAmmo();
};

// @fnv 0x0042eb40
ExtraAmmo* FUN_0042eb40_shell::GetExtraAmmo()
{
    ExtraAmmo* pextra = reinterpret_cast<ExtraAmmo*>(GetExtraData(0x6e));
    return pextra;
}

struct TESTopic;
struct TESTopicInfo;
struct FUN_0042edb0_shell : public ExtraDataList
{
    void FUN_0042edb0();
};

struct HX2edb0
{
    void FUN_00410020(BSExtraData*, int);
};
// Retrieves the extra data of type 0x75 and, if present, calls FUN_00410020 with it and 1.
// @fnv 0x0042edb0
void FUN_0042edb0_shell::FUN_0042edb0()
{
    BSExtraData* pextra = GetExtraData(0x75);
    if (pextra)
        reinterpret_cast<HX2edb0*>(this)->FUN_00410020(pextra, 1);
}

struct ExtraSayToTopicInfo;
struct TESTopic;
struct TESTopicInfo;
struct FUN_0042ede0_shell : public ExtraDataList
{
    ExtraSayToTopicInfo* FUN_0042ede0();
};

// @fnv 0x0042ede0
ExtraSayToTopicInfo* FUN_0042ede0_shell::FUN_0042ede0()
{
    ExtraSayToTopicInfo* pextra = reinterpret_cast<ExtraSayToTopicInfo*>(GetExtraData(0x75));
    return pextra;
}

struct WaterZone;
struct FUN_0042f1d0_shell : public ExtraDataList
{
    void* FUN_0042f1d0();
};

// Retrieves the extra data entry with type 0x7e and returns a pointer to its payload at offset 0xc, or null if absent.
// @fnv 0x0042f1d0
void* FUN_0042f1d0_shell::FUN_0042f1d0()
{
    BSExtraData* pextra = GetExtraData(0x7e);
    if (!pextra)
    {
        return 0;
    }
    return (char*)pextra + 0xc;
}

struct FUN_0042f3d0_shell : public ExtraDataList
{
    bool FUN_0042f3d0(void*);
};

struct ExtraPatrolRefInUseData_shell
{
    bool FUN_00437ab0(void*);
};

// Looks up the extra data of type 0x88 and returns true if it is absent or its check against apUser succeeds, otherwise false.
// @fnv 0x0042f3d0
bool FUN_0042f3d0_shell::FUN_0042f3d0(void* apUser)
{
    ExtraPatrolRefInUseData_shell* pextra = (ExtraPatrolRefInUseData_shell*)GetExtraData(0x88);
    if (!pextra)
    {
        return true;
    }
    if (pextra->FUN_00437ab0(apUser))
    {
        return true;
    }
    return false;
}

struct AC_0042f730
{
    void FUN_0044bbc0();
};
struct S_0042f730
{
    AC_0042f730* m_pObject;
    S_0042f730* SetObject(AC_0042f730* pObject);
};
// Stores pObject in m_pObject and, if it is non-null, calls FUN_0044bbc0 on it; returns this.
// @fnv 0x0042f730
S_0042f730* S_0042f730::SetObject(AC_0042f730* pObject)
{
    m_pObject = pObject;
    if (m_pObject)
        m_pObject->FUN_0044bbc0();
    return this;
}

extern int DAT_010159d4;
struct Y0042f7d0
{
    void* vt;
    void FUN_0042fcb0(int, int);
    Y0042f7d0* FUN_0042f7d0(int a);
};
// Sets the vtable pointer to DAT_010159d4, calls FUN_0042fcb0 with the argument twice, and returns this.
// @fnv 0x0042f7d0
Y0042f7d0* Y0042f7d0::FUN_0042f7d0(int a)
{
    vt = &DAT_010159d4;
    FUN_0042fcb0(a, a);
    return this;
}

extern int DAT_010159d4;

struct Dummy0042f800
{
    void FUN_0042fcb0(int, int);
};

// Sets the object's vtable pointer to DAT_010159d4, calls FUN_0042fcb0 with 0, 0, and returns the object.
// @fnv 0x0042f800
void* __fastcall FUN_0042f800(int** apObject)
{
    *apObject = &DAT_010159d4;
    reinterpret_cast<Dummy0042f800*>(apObject)->FUN_0042fcb0(0, 0);
    return apObject;
}

extern int DAT_010159d4;

struct FUN_0042f830_struct
{
    int vftable;
    void FUN_0042f9c0(unsigned char);
};

// @fnv 0x0042f830
void __fastcall FUN_0042f830(FUN_0042f830_struct* pThis)
{
    pThis->vftable = (int)&DAT_010159d4;
    pThis->FUN_0042f9c0(1);
}

struct NavMeshPtr
{
    void* p;
    NavMeshPtr& operator=(const NavMeshPtr&);
};
struct S2f850
{
    int pad0;
    NavMeshPtr* data;
    unsigned int FUN_00761540();
    void FUN_0042fa60(NavMeshPtr*, int);
    unsigned int AppendValue(const NavMeshPtr& aValue);
};
// @fnv 0x0042f850
unsigned int S2f850::AppendValue(const NavMeshPtr& aValue)
{
    unsigned int iElementIndex = FUN_00761540();
    FUN_0042fa60(&data[iElementIndex], 1);
    data[iElementIndex] = aValue;
    return iElementIndex;
}

struct S0042fa20
{
    void FUN_0042fd40(int);
    S0042fa20* FUN_0042fa20(int a);
};
// @fnv 0x0042fa20
S0042fa20* S0042fa20::FUN_0042fa20(int a)
{
    FUN_0042fd40(a);
    return this;
}

void __fastcall FUN_0042fda0(void* pThis);

// @fnv 0x0042fa40
void __fastcall FUN_0042fa40(void* pThis)
{
    FUN_0042fda0(pThis);
}

namespace fnv_00458b50 {
void __fastcall FUN_0042fda0(void* pThis);

// @fnv 0x00458b50
void __fastcall FUN_00458b50(void* pThis)
{
    FUN_0042fda0(pThis);
}
}  // namespace fnv_00458b50

double __cdecl FUN_00ec9f30(double);

// @fnv 0x004e4490
float __cdecl FUN_004e4490(float _X)
{
    return static_cast<float>(FUN_00ec9f30(_X));
}

namespace fnv_004fd3c0 {
struct Actor;
struct BSFile;
struct ChangeData;
struct ChangesMap;
struct CellReferenceChangeData;
struct ExteriorCellNewReferencesMap;
struct CellChangesMap;
struct InteriorCellNewReferencesMap;
struct FormRecordMetadata;
struct WorldReferenceObject;
struct NiPoint3;
struct NiTexture;
struct NumericIDBufferMap;
struct SaveGameRecord;
struct FormIDEntry;
struct SaveGameFile;
struct EmptyClass;
struct TESForm;
struct TESWorldSpace;
struct _FILETIME;
struct _SYSTEMTIME;
struct blob12
{
    char b[12];
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
struct FUN_004fd3c0_shell : public TESSaveLoadGame
{
    FormRecordMetadata* FUN_004fd3c0();
};

// @fnv 0x004fd3c0
FormRecordMetadata* __fastcall FUN_004fd3c0(TESSaveLoadGame* _this)
{
    return *(FormRecordMetadata**)((char*)_this + 0x84);
}
}  // namespace fnv_004fd3c0

struct FUN_00546ac0_shell : public TESObjectCELL
{
    int FUN_00546ac0();
};

int __fastcall FUN_004186c0(BSSimpleList<TESImageSpaceModifier*>*);

// @fnv 0x00546ac0
int FUN_00546ac0_shell::FUN_00546ac0()
{
    int irank = FUN_004186c0(((FUN_004610d0_shell*)this)->GetTESImageSpaceModifierList());
    if (irank == -1)
        return 0;
    else
        return irank;
}

namespace fnv_0056af40 {
struct PackedRecordData;
struct Actor;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BGSVoiceType;
struct BipedAnim;
struct CHUNK;
struct ContainerChanges;
struct ContainerItemExtra;
struct InventoryItemEntry;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct MagicItemForm;
struct NiAVObject;
struct NiColor;
struct NiPoint3;
struct PackageList;
struct SpellItem;
struct TESAIForm;
struct TESActorBase;
struct TESActorBaseData;
struct TESAmmo;
struct TESBoundObject;
struct TESContainer;
struct TESFaction;
struct TESForm;
struct TESLevItem;
struct TESLevSpell;
struct TESObject;
struct TESObjectARMO;
struct TESObjectCLOT;
struct TESFormList;
struct TESObjectWEAP;
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
struct FUN_0056af40_shell : public TESObjectREFR
{
    bool FUN_0056af40();
};

bool __fastcall FUN_004216d0(ExtraDataList* pThis);

struct TESObject
{
    virtual void vfn_00();
    virtual void vfn_01();
    virtual void vfn_02();
    virtual void vfn_03();
    virtual void vfn_04();
    virtual void vfn_05();
    virtual void vfn_06();
    virtual void vfn_07();
    virtual void vfn_08();
    virtual void vfn_09();
    virtual void vfn_10();
    virtual void vfn_11();
    virtual void vfn_12();
    virtual void vfn_13();
    virtual void vfn_14();
    virtual void vfn_15();
    virtual void vfn_16();
    virtual void vfn_17();
    virtual void vfn_18();
    virtual void vfn_19();
    virtual void vfn_20();
    virtual void vfn_21();
    virtual void vfn_22();
    virtual void vfn_23();
    virtual void vfn_24();
    virtual void vfn_25();
    virtual void vfn_26();
    virtual void vfn_27();
    virtual void vfn_28();
    virtual void vfn_29();
    virtual void vfn_30();
    virtual void vfn_31();
    virtual void vfn_32();
    virtual void vfn_33();
    virtual void vfn_34();
    virtual void vfn_35();
    virtual void vfn_36();
    virtual void vfn_37();
    virtual void vfn_38();
    virtual void vfn_39();
    virtual void vfn_40();
    virtual void vfn_41();
    virtual void vfn_42();
    virtual void vfn_43();
    virtual void vfn_44();
    virtual void vfn_45();
    virtual void vfn_46();
    virtual void vfn_47();
    virtual void vfn_48();
    virtual void vfn_49();
    virtual void vfn_50();
    virtual void vfn_51();
    virtual void vfn_52();
    virtual void vfn_53();
    virtual void vfn_54();
    virtual void vfn_55();
    virtual void vfn_56();
    virtual void vfn_57();
    virtual void vfn_58();
    virtual void vfn_59();
    virtual void vfn_60();
    virtual void vfn_61();
    virtual bool vfn_62();
    TESObject* GetNext();
};

struct TESActorBaseData
{
    bool GetUsesLeveledTemplate();
};

// @fnv 0x0056af40
bool FUN_0056af40_shell::FUN_0056af40()
{
    bool bretval = false;
    TESObject* pactor;
    if (((TESObject*)this)->GetNext() && ((TESObject*)this)->GetNext()->vfn_62())
    {
        if (FUN_004216d0(GetExtraData()))
        {
            bretval = true;
        }
        else
        {
            pactor = ((TESObject*)this)->GetNext();
            if (((TESActorBaseData*)((char*)pactor + 0x30))->GetUsesLeveledTemplate())
            {
                bretval = true;
            }
        }
    }
    return bretval;
}
}  // namespace fnv_0056af40

float __cdecl cos(float);

// @fnv 0x005b9e80
float FUN_005b9e80(float fRadians)
{
    return cos(fRadians);
}

float __cdecl FUN_004e44b0(float);

// @fnv 0x005c53d0
float FUN_005c53d0(float fRadians)
{
    return FUN_004e44b0(fRadians);
}

struct CS_005f92d0
{
    int GetRandomCreatureSound(int);
};
struct ABD_005f92d0
{
    bool GetFlag(unsigned int) const;
};
struct TESCreature
{
    char pad[0x30];
    ABD_005f92d0 abd;
    CS_005f92d0* GetCreatureSounds();
    TESCreature* GetSoundCreature();
    int FUN_005f92d0(int a);
};
// If flag 0x100 is set, forwards a to the creature sounds object; otherwise recurses into the sound creature; returns 0 if none.
// @fnv 0x005f92d0
int TESCreature::FUN_005f92d0(int a)
{
    if (abd.GetFlag(0x100))
    {
        CS_005f92d0* psounds = GetCreatureSounds();
        if (psounds)
            return psounds->GetRandomCreatureSound(a);
    }
    else
    {
        TESCreature* pcrea = GetSoundCreature();
        if (pcrea)
            return pcrea->FUN_005f92d0(a);
    }
    return 0;
}

namespace fnv_007af430 {
struct Actor;
struct SaveLoadFile;
struct ThreeByThreeMatrix;
struct NiPoint3;
struct NiQuaternion;
struct TESBoundObject;
struct TESForm;
struct hkVector4;
struct blob4
{
    char b[4];
};
struct BGSSaveGameBuffer
{
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    void Save(SaveLoadFile*, unsigned int);
    void Save(SaveLoadFile*);
    unsigned int GetBufferPosition();
    char* GetBuffer();
    void ClearPosition();
    unsigned int GetDataSize();
    unsigned int GetDebugOverhead();
    void SaveData(NiQuaternion*, unsigned int, unsigned int);
    void SaveData(hkVector4*, unsigned int, unsigned int);
    void SaveData(double*, unsigned int, unsigned int);
    void SaveData(NiPoint3*, unsigned int, unsigned int);
    void SaveData(float*, unsigned int, unsigned int);
    void SaveData(unsigned long*, unsigned int, unsigned int);
    void SaveData(long*, unsigned int, unsigned int);
    void SaveData(unsigned int*, unsigned int, unsigned int);
    void SaveData(int*, unsigned int, unsigned int);
    void SaveData(unsigned short*, unsigned int, unsigned int);
    void SaveData(short*, unsigned int, unsigned int);
    void SaveData(ThreeByThreeMatrix*, unsigned int, unsigned int);
    void SaveData(void*, unsigned int, unsigned int);
    void SaveData(void*, unsigned int, unsigned int, unsigned int);
    void SerializeFormData(TESForm*, unsigned int);
    void SerializeFormData(unsigned int, unsigned int);
    void SaveGameString(char*, unsigned int);
    unsigned int GetBufferLength();
    void SetBufferPosition(unsigned int, unsigned int);
    void SetBufferPosition(unsigned int);
    void CopyBufferData(void*, unsigned int, unsigned int, unsigned int, unsigned int);
    void CopyBufferData(void*, unsigned int, unsigned int, unsigned int);
    void WriteBufferData(void*, unsigned int, bool);
    void WriteBufferData(void*, unsigned int, unsigned int, bool);
    void ReleaseBufferContents();
    void ShiftBuffer(unsigned int, int);
    void* __vecDelDtor(unsigned int);
    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
    unsigned int m_uiBufferPosition;
};
typedef char _sizecheck_BGSSaveGameBuffer[sizeof(BGSSaveGameBuffer) == 20 ? 1 : -1];
struct BGSSaveFormBuffer : public BGSSaveGameBuffer
{
    void Save(SaveLoadFile*);
    void SetHeader(unsigned int, struct blob4, int, unsigned char);
    struct blob4 GetChangeFlags();
    void SetChangeFlags(struct blob4);
    void NotifyFormIDChanged(int);
    void ClearFormChangeFlags(int);
    int GetFormType();
    unsigned char GetVersion();
    void SetForm(TESForm*);
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    unsigned int GetFormIdentifier();
    void* __vecDelDtor(unsigned int);
    char Header[9];
    char _pad_1d[3];
    TESForm* pForm;
};
typedef char _sizecheck_BGSSaveFormBuffer[sizeof(BGSSaveFormBuffer) == 36 ? 1 : -1];
struct FUN_007af430_shell : public TESObjectREFR
{
    TESBoundObject* FUN_007af430();
};

// @fnv 0x007af430
TESBoundObject* FUN_007af430_shell::FUN_007af430()
{
    return *(TESBoundObject**)((char*)this + 0x20);
}
}  // namespace fnv_007af430

struct _FUN_00822510_Class
{
    int m_pObject;
    bool operator==(int pObject) const;
};
static bool (__thiscall _FUN_00822510_Class::*_FUN_00822510_ref)(int) const = &_FUN_00822510_Class::operator==;

// @0x00822510
// @fnv 0x00822510
bool _FUN_00822510_Class::operator==(int pObject) const
{
    return m_pObject == pObject;
}

int* __fastcall _ref_006815c0(void* thisPtr);
void* __fastcall _ref_00726070(void* thisPtr);

struct FUN_0087fd20_Class
{
    char pad[0xfc];
    BSSimpleList<int> list;
};

// @fnv 0x0087fd20
void __fastcall FUN_0087fd20(FUN_0087fd20_Class* pThis)
{
    void* pCurrentElementNext = &pThis->list;
    while (pCurrentElementNext && *_ref_006815c0(pCurrentElementNext))
    {
        int* pmod = reinterpret_cast<int*>(*_ref_006815c0(pCurrentElementNext));
        delete pmod;
        pCurrentElementNext = _ref_00726070(pCurrentElementNext);
    }
    pThis->list.RemoveAll();
}

struct FUN_009611e0_shell : public TESPackage
{
    int FUN_009611e0();
};

// @fnv 0x009611e0
int FUN_009611e0_shell::FUN_009611e0()
{
    return *(int*)((char*)this + 0x18);
}

struct Arr_009f2b30
{
    unsigned int& GetAt(unsigned int);
    unsigned int GetFlags();
};
struct ER_009f2b30
{
    void FUN_0042f300(int);
};
struct P_009f2b30
{
    char pad[0x1c];
    char arr[0x18];
    unsigned int idx;
    void FUN_009f2b30();
};
// @fnv 0x009f2b30
void P_009f2b30::FUN_009f2b30()
{
    if (idx < ((Arr_009f2b30*)((char*)this + 0x1c))->GetFlags())
    {
        TESObjectREFR* poldRef = (TESObjectREFR*)((Arr_009f2b30*)((char*)this + 0x1c))->GetAt(idx);
        ExtraDataList* poldExtra = poldRef ? poldRef->GetExtraData() : 0;
        if (poldExtra)
            ((ER_009f2b30*)poldExtra)->FUN_0042f300(0);
    }
}

struct FUN_0041df00_shell : public ExtraDataList
{
    TESObjectREFR* FUN_0041df00();
};

struct TObj
{
    TObj* GetNext();
};
int __fastcall _FNV_GetFormType(TObj*);
struct LN
{
    TObj** _ref_006815c0();
};
struct LN3
{
    LN* _ref_00726070();
};
// @fnv 0x0041df00
TESObjectREFR* FUN_0041df00_shell::FUN_0041df00()
{
    TESObjectREFR* pRef = 0;
    BSExtraData* pextra;
    LN* pretlist = 0;
    pextra = GetExtraData(0x3a);
    if (pextra)
    {
        pretlist = (LN*)((char*)pextra + 0xc);
        while (!pRef && pretlist && *pretlist->_ref_006815c0())
        {
            TObj* ptemp = *pretlist->_ref_006815c0();
            if (_FNV_GetFormType(ptemp->GetNext()) == 0x28)
                pRef = (TESObjectREFR*)ptemp;
            pretlist = ((LN3*)pretlist)->_ref_00726070();
        }
    }
    return pRef;
}

struct NavMeshInfo;
struct CtorHelper
{
    void InitializeItems(NavMeshInfo**, unsigned int);
};
struct UW
{
    unsigned int v;
};
struct AX
{
    virtual void* v0(unsigned int);
    virtual NavMeshInfo** Allocate(unsigned int);
    NavMeshInfo** data;
    unsigned int size;
    unsigned int alloc;
};
// @fnv 0x006b3eb0
void __fastcall FUN_006b3eb0(AX* self, UW uiMaxSize, UW uiSize)
{
    self->data = 0;
    self->size = 0;
    self->alloc = 0;
    if (uiSize.v > uiMaxSize.v)
        uiMaxSize.v = uiSize.v;
    if (uiMaxSize.v > 0)
    {
        self->data = self->Allocate(uiMaxSize.v);
        self->alloc = uiMaxSize.v;
    }
    if (uiSize.v > 0)
    {
        ((CtorHelper*)self)->InitializeItems(self->data, uiSize.v);
        self->size = uiSize.v;
    }
}

extern void* DAT_01014428[];
struct BE
{
    void** m_ppVirtualMethodTable;
    char pad[8];
    BE(unsigned char type);
    ~BE();
};
struct SL
{
    void* item;
    void* next;
    SL();
};
struct FUN_00411b40 : public BE
{
    char listStorage[8];
    FUN_00411b40();
};

// @fnv 0x00411b40
FUN_00411b40::FUN_00411b40() : BE(0x65)
{
    m_ppVirtualMethodTable = DAT_01014428;
    ((SL*)listStorage)->SL::SL();
}

struct RgbaColor
{
    float r, g, b, a;
    RgbaColor(float, float, float, float);
};
namespace p07 {
struct _ref_006815c0
{
    float x, y, z;
    _ref_006815c0();
};
struct FUN_004143f0
{
    _ref_006815c0 akRadii;
    RgbaColor apTextColor;
    int eType;
    FUN_004143f0();
};
// @fnv 0x004143f0
FUN_004143f0::FUN_004143f0() : apTextColor(0.0f, 0.0f, 0.0f, 0.0f)
{}
}

namespace fnv_00418940 {
struct NiAVObject;
struct SoundPlaybackHandle
{
    void Clear();
    bool Play(bool);
    bool SchedulePlayback(unsigned int, int);
    bool Pause();
    bool Stop();
    bool IsPlaying();
    bool IsValid();
    int GetSoundType();
    float GetVolume();
    bool SetVolume(float);
    bool SetFrequency(float);
    bool SetPlaybackFrequency(float);
    bool SetFrequencyVariance(unsigned char);
    bool SetBalance(int);
    bool SetStaticAttenuation(unsigned short);
    int GetDuration();
    bool SetPosition(void*);
    bool SetPosition(float, float, float);
    bool SetBeamEnd(void*);
    bool SetBeamEnd(float, float, float);
    void SetDistanceRange(float, float);
    void SetSoundParameters(unsigned short, unsigned short, unsigned short, unsigned short, unsigned short);
    void SetReverbAttenuation(unsigned short);
    bool SetBeamStart(float, float, float);
    unsigned int GetID();
    void SetObjectToFollow(NiAVObject*);
    void Seek(unsigned int);
    void SetFollowsListener(bool);
    void SetCompletionCallback(int*, void*);
    void SetPlayCallback(int*, void*);
    static void SetAddMovingSoundCallback(int*);
    bool Release();
    bool SetFadeInTime(unsigned int);
    bool StopWithFade(unsigned int);
    bool SetPlaybackTime(unsigned int);
    void SetTimeConstraints(unsigned char, unsigned char);
    void SetSynchStartTime(unsigned int);
    void IsSoundPlaying();
    void SetPriority(unsigned int);
    void SetAssumeSuccess(bool);
    int QState();
    void* __vecDelDtor(unsigned int);
    unsigned int m_uiSoundResourceID;
    bool m_bLooping;
    char _pad_5[3];
    int eState;
};
typedef char _sizecheck_BSSoundHandle[sizeof(SoundPlaybackHandle) == 12 ? 1 : -1];
struct FUN_00418940_shell : public ExtraDataList
{
    void FUN_00418940(SoundPlaybackHandle*);
};

struct SH_00418890
{
    void FUN_004188d0();
};
struct OH3SoundCopy
{
    void SoundPlaybackHandle(const ::SoundPlaybackHandle&);
};
// Reads extra data 0x7d; if present copies its sound handle into result, otherwise initialises result via FUN_004188d0.
// @fnv 0x00418940
void FUN_00418940_shell::FUN_00418940(SoundPlaybackHandle* result)
{
    BSExtraData* SoundAssetTmp = GetExtraData(0x7d);
    if (SoundAssetTmp)
        ((OH3SoundCopy*)result)->SoundPlaybackHandle(*(::SoundPlaybackHandle*)((char*)SoundAssetTmp + 0xc));
    else
        ((SH_00418890*)result)->FUN_004188d0();
}
}  // namespace fnv_00418940

namespace fnv_004222f0 {
struct BE
{
    BE(unsigned char);
    virtual ~BE();
    char pad04[8];
};
class FUN_004222f0 : public BE
{
  public:
    float fRadius;
    FUN_004222f0(float afRadius);
    virtual ~FUN_004222f0();
};
// Constructs the object with base BE(0x5c) and stores afRadius into the radius field.
// @fnv 0x004222f0
FUN_004222f0::FUN_004222f0(float afRadius) : BE(0x5c)
{
    fRadius = afRadius;
}
}  // namespace fnv_004222f0

void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_00425ff0(unsigned int flags);
};
// Runs the destructor on this, then frees this when flags has bit 0 set, and returns this.
// @fnv 0x00425ff0
void* DelStandIn::FUN_00425ff0(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}

namespace fnv_0042c5b0 {
void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_0042c5b0(unsigned int flags);
};
// Calls the destructor on this object, frees it when flags has bit 0 set, and returns this.
// @fnv 0x0042c5b0
void* DelStandIn::FUN_0042c5b0(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}
}  // namespace fnv_0042c5b0

namespace fnv_0042c7a0 {
void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* DestroyAndFreeIfFlagged(unsigned int flags);
};
// Calls the destructor on this, then deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x0042c7a0
void* DelStandIn::DestroyAndFreeIfFlagged(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}
}  // namespace fnv_0042c7a0

namespace fnv_004338b0 {
struct BE
{
    BE(unsigned char);
    ~BE();
};
struct SL
{
    void* item;
    void* next;
    SL();
    ~SL();
};
struct StrMem
{
    char* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    StrMem();
    ~StrMem();
    bool Set(const char*, unsigned int);
};
extern const void* DAT_01015ce4[];
extern const char DAT_01011584[];

struct FUN_004338b0 : BE
{
    const void* vtbl;
    char _pad04[8];
    SL list;
    unsigned char flag;
    StrMem str;
    FUN_004338b0();
};

// Initializes the object with base BE(0x53), sets vtbl, clears flag, and sets str to DAT_01011584 with length 0.
// @fnv 0x004338b0
FUN_004338b0::FUN_004338b0() : BE(0x53), vtbl(DAT_01015ce4)
{
    flag = 0;
    str.Set(DAT_01011584, 0);
}
}  // namespace fnv_004338b0

namespace fnv_0040ff60 {
struct FUN_0040ff60_shell : public BaseExtraList
{
    BSExtraData* FUN_0040ff60(BSExtraData*);
};

struct RecursiveSpinLock
{
    void Lock(const char*);
    void Unlock();
};
extern RecursiveSpinLock g_011c3920;
struct PatrolActorPackageData
{
    bool IsPatrolling();
};
struct FUN_0040fee0_shell
{
    void SetBitFlag(unsigned char, bool);
};
struct ArrSI
{
    unsigned int GetFlags();
};
struct TESObjectREFR_Flags
{
    void SetFlags(BSExtraData*);
};
bool __cdecl FUN_0040f980(int);
// @fnv 0x0040ff60
BSExtraData* FUN_0040ff60_shell::FUN_0040ff60(BSExtraData* apExtra)
{
    BSExtraData* work;
    g_011c3920.Lock("BaseExtraList::AddExtra()");
    if (FUN_0040f980(((PatrolActorPackageData*)apExtra)->IsPatrolling()))
    {
        if (((BaseExtraList*)this)->pHead)
        {
            ((TESObjectREFR_Flags*)apExtra)->SetFlags(((BaseExtraList*)this)->pHead);
        }
        ((BaseExtraList*)this)->pHead = apExtra;
    }
    else
    {
        work = ((BaseExtraList*)this)->pHead;
        if (work)
        {
            while (((ArrSI*)work)->GetFlags())
            {
                work = (BSExtraData*)((ArrSI*)work)->GetFlags();
            }
            ((TESObjectREFR_Flags*)work)->SetFlags(apExtra);
        }
        else
        {
            ((BaseExtraList*)this)->pHead = apExtra;
        }
    }
    ((FUN_0040fee0_shell*)this)->SetBitFlag(((PatrolActorPackageData*)apExtra)->IsPatrolling(), true);
    g_011c3920.Unlock();
    return apExtra;
}
}  // namespace fnv_0040ff60

namespace fnv_00418310 {
struct RadioReferenceData
{
    void Copy(RadioReferenceData*);
    void Endian();
    float fRadius;
    int m_iIntegerValue;
    float m_fValueBeforeRadioReference;
    TESObjectREFR* m_pRadioReference;
};
typedef char _sizecheck_RADIO_DATA[sizeof(RadioReferenceData) == 16 ? 1 : -1];
struct FUN_00418310_shell : public ExtraDataList
{
    void SetRadioData(RadioReferenceData*);
};

struct FUN_00437240_Struct
{
    void FUN_00437240(FUN_00437240_Struct*);
    char b[16];
};
struct ExtraRadioData : public BSExtraData
{
    FUN_00437240_Struct data;
    ExtraRadioData();
};

// Stores apData into the extra data of type 0x68, creating and adding it if missing, or removes that extra when apData is null.
// @fnv 0x00418310
void FUN_00418310_shell::SetRadioData(RadioReferenceData* apData)
{
    if (apData)
    {
        ExtraRadioData* pextra = (ExtraRadioData*)((BaseExtraList*)this)->GetExtraData(0x68);
        if (pextra)
        {
            pextra->data.FUN_00437240((FUN_00437240_Struct*)apData);
        }
        else
        {
            pextra = new ExtraRadioData();
            pextra->data.FUN_00437240((FUN_00437240_Struct*)apData);
            ((BaseExtraList*)this)->AddExtra(pextra);
        }
    }
    else
    {
        ((BaseExtraList*)this)->RemoveExtra(0x68);
    }
}
}  // namespace fnv_00418310

namespace fnv_00419120 {
struct BGSLoadGameBuffer;
struct BGSSaveGameBuffer;
struct ExtraTeleport;
struct TESForm;
struct TESWorldSpace;
struct blob16
{
    char b[16];
};
struct TeleportableReference
{
    TESObjectREFR* GetLinkedDoor();
    void* GetTeleportPosition();
    void* GetTeleportRotation();
    TESObjectCELL* GetTeleportCell();
    void GetTeleportCellMapName(void*);
    TESWorldSpace* GetTeleportWorldspace();
    struct blob16 GetTeleportDestinationPosition();
    TESForm* GetTeleportDestinationForm();
    bool GetNoAlarm();
    void SetNoAlarm(bool);
    void SetLinkedDoor(TESObjectREFR*);
    void SetTeleportPosition(void*);
    void SetTeleportRotation(void*);
    void SetLinkedDoorReference(TESObjectREFR*, bool);
    void Save();
    void Load(TESFile*);
    bool InitItem(TESForm*);
    void Copy(TeleportableReference*);
    bool Compare(TeleportableReference*);
    unsigned short GetSaveSize();
    void SaveGame(BGSSaveGameBuffer*);
    void SaveGame();
    void LoadGame(BGSLoadGameBuffer*);
    void LoadGame();
    void InitLoadGame(BGSLoadGameBuffer*);
    void InitLoadGame();
    void FinishLoadGameTES();
    void* __vecDelDtor(unsigned int);
    TESObjectREFR* m_pLinkedDoorReference;
    char position[12];
    char rotation[12];
    unsigned char cFlags;
    char _pad_1d[3];
};
typedef char _sizecheck_DoorTeleportData[sizeof(TeleportableReference) == 32 ? 1 : -1];
struct FUN_00419120_shell : public ExtraDataList
{
    ExtraTeleport* FUN_00419120(TeleportableReference*);
};

struct FUN_00431230 : public BSExtraData
{
    TeleportableReference* pData;
    FUN_00431230(TeleportableReference*);
};
struct Dummy_00410020
{
    void FUN_00410020(BSExtraData*, bool);
};
struct Dummy_00419220
{
    void* DeleteIfFlagged(int);
};
extern unsigned int _data_011c16bc;

// Gets the 0x2b extra data; if present, replaces or removes its teleport data, otherwise creates and adds a new extra for apTeleport, returning it.
// @fnv 0x00419120
ExtraTeleport* FUN_00419120_shell::FUN_00419120(TeleportableReference* apTeleport)
{
    FUN_00431230* pExtra = (FUN_00431230*)((BaseExtraList*)this)->GetExtraData(0x2b);
    if (pExtra)
    {
        if (!apTeleport)
        {
            ((Dummy_00410020*)this)->FUN_00410020(pExtra, true);
        }
        else
        {
            Dummy_00419220* pOld = (Dummy_00419220*)pExtra->pData;
            Dummy_00419220* pTemp = pOld;
            pTemp ? pTemp->DeleteIfFlagged(1) : (void*)0;
            pExtra->pData = apTeleport;
        }
    }
    else if (apTeleport)
    {
        pExtra = new FUN_00431230(apTeleport);
        ((BaseExtraList*)this)->AddExtra(pExtra);
    }
    return (ExtraTeleport*)pExtra;
}
}  // namespace fnv_00419120

namespace fnv_00419250 {
struct ExtraMapMarker;
struct TESReputation;
struct MapMarkerData
{
    void Save();
    bool Load(TESFile*);
    void Copy(MapMarkerData*);
    bool Compare(MapMarkerData*);
    char* GetMapLabel();
    void SetLocationName(char*);
    bool GetVisible();
    void SetVisible(bool);
    bool IsTravelLocation();
    void SetTravelLocation(bool);
    bool GetHidden();
    void SetHidden(bool);
    void SetReputation(TESReputation*);
    TESReputation* GetReputation();
    int GetMarkerType();
    void SetMarkerType(int);
    unsigned char GetFlags();
    void SetFlags(unsigned char);
    void ResetFlags();
    void* __vecDelDtor(unsigned int);
    char LocationName[12];
    unsigned char cFlags;
    unsigned char m_ucAdditionalFlags;
    unsigned short sType;
    TESReputation* pReputationData;
};
typedef char _sizecheck_MapMarkerData[sizeof(MapMarkerData) == 20 ? 1 : -1];
struct FUN_00419250_shell : public ExtraDataList
{
    ExtraMapMarker* SetMapMarker(MapMarkerData*);
};

struct FUN_00431360 : public BSExtraData
{
    MapMarkerData* pData;
    FUN_00431360(MapMarkerData*);
};
struct Dummy_00410020
{
    void FUN_00410020(BSExtraData*, bool);
};
struct Dummy_00419350
{
    void* FUN_00419350(int);
};
extern unsigned int _data_011c16bc;

// Gets or creates the 0x2c extra data entry, replacing or clearing its MapMarkerData pointer, and returns the entry.
// @fnv 0x00419250
ExtraMapMarker* FUN_00419250_shell::SetMapMarker(MapMarkerData* apMarker)
{
    FUN_00431360* pExtra = (FUN_00431360*)((BaseExtraList*)this)->GetExtraData(0x2c);
    if (pExtra)
    {
        if (!apMarker)
        {
            ((Dummy_00410020*)this)->FUN_00410020(pExtra, true);
            pExtra = 0;
        }
        else
        {
            Dummy_00419350* pOld = (Dummy_00419350*)pExtra->pData;
            Dummy_00419350* pTemp = pOld;
            pTemp ? pTemp->FUN_00419350(1) : (void*)0;
            pExtra->pData = apMarker;
        }
    }
    else if (apMarker)
    {
        pExtra = new FUN_00431360(apMarker);
        ((BaseExtraList*)this)->AddExtra(pExtra);
    }
    return (ExtraMapMarker*)pExtra;
}
}  // namespace fnv_00419250

namespace fnv_00419380 {
struct ExtraAudioMarker;
struct MediaLocationController;
struct blob12
{
    char b[12];
};
struct MediaLocation
{
    void Save();
    bool Load(TESFile*);
    void Copy(MediaLocation*);
    bool Compare(MediaLocation*);
    void InitItem();
    char* GetMapLabel();
    void SetLocationName(char*);
    MediaLocationController* GetLocationController();
    unsigned int GetLocationControllerID();
    void SetLocationControllerID(unsigned int);
    float GetInside();
    bool GetCellInside();
    float GetSecondLayerPercent();
    float GetThirdLayerPercent();
    struct blob12 GetLocation();
    bool GetUseController();
    void* __vecDelDtor(unsigned int);
    char LocationName[12];
    float m_fLayerOneTriggerPercent;
    float m_fLayerTwoTriggerPercent;
    float fRadius;
    char Location[12];
    unsigned int pController;
    bool m_bUseControllerValues;
    char _pad_29[3];
    char m_cReservedData[8];
};
typedef char _sizecheck_AudioMarkerData[sizeof(MediaLocation) == 52 ? 1 : -1];
struct FUN_00419380_shell : public ExtraDataList
{
    ExtraAudioMarker* SetAudioMarker(MediaLocation*);
};

struct PtrWrap
{
    MediaLocation* p;
};
struct Dummy_00410020
{
    void FUN_00410020(BSExtraData*, bool);
};
struct Dummy_00419480
{
    void* FUN_00419480(int);
};
struct FUN_004314c0 : public BSExtraData
{
    MediaLocation* pData;
    FUN_004314c0(PtrWrap);
};
extern unsigned int _data_011c16bc;

// Gets or creates the 0x90 extra-data entry, replacing or clearing its marker pointer, and returns the entry cast to ExtraAudioMarker.
// @fnv 0x00419380
ExtraAudioMarker* FUN_00419380_shell::SetAudioMarker(MediaLocation* apMarker)
{
    FUN_004314c0* pExtra = (FUN_004314c0*)((BaseExtraList*)this)->GetExtraData(0x90);
    if (pExtra)
    {
        if (!apMarker)
        {
            ((Dummy_00410020*)this)->FUN_00410020(pExtra, true);
            pExtra = 0;
        }
        else
        {
            Dummy_00419480* pOld = (Dummy_00419480*)pExtra->pData;
            Dummy_00419480* pTemp = pOld;
            pTemp ? pTemp->FUN_00419480(1) : (void*)0;
            pExtra->pData = apMarker;
        }
    }
    else if (apMarker)
    {
        pExtra = new FUN_004314c0(*(PtrWrap*)&apMarker);
        ((BaseExtraList*)this)->AddExtra(pExtra);
    }
    return (ExtraAudioMarker*)pExtra;
}
}  // namespace fnv_00419380

namespace fnv_00419700 {
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiColor;
struct NiPoint3;
struct TESBoundObject;
struct TESForm;
struct blob8
{
    char b[8];
};
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct FUN_00419700_shell : public ExtraDataList
{
    void FUN_00419700(TESForm*);
};

struct TESGlobal;
struct ExtraGlobal : public BSExtraData
{
    TESGlobal* pGlobalForm;
    ExtraGlobal(TESGlobal*);
};

struct Dummy_00410020
{
    void FUN_00410020(BSExtraData*, bool);
};

// Finds the ExtraGlobal extra data (type 0x21); if present, updates or removes it, otherwise creates and adds one when apGlobal is non-null.
// @fnv 0x00419700
void FUN_00419700_shell::FUN_00419700(TESForm* apGlobal)
{
    BSExtraData* pextra = ((BaseExtraList*)this)->GetExtraData(0x21);
    if (pextra)
    {
        if (!apGlobal)
        {
            ((Dummy_00410020*)this)->FUN_00410020(pextra, true);
        }
        else
        {
            ((ExtraGlobal*)pextra)->pGlobalForm = (TESGlobal*)apGlobal;
        }
    }
    else if (apGlobal)
    {
        pextra = new ExtraGlobal((TESGlobal*)apGlobal);
        ((BaseExtraList*)this)->AddExtra(pextra);
    }
}
}  // namespace fnv_00419700

struct FUN_00419ad0_shell : public ExtraDataList
{
    void FUN_00419ad0(short);
};

struct ExtraCount : public BSExtraData
{
    short count;
    ExtraCount(short);
};
struct ExtraDataList_Remove_stub
{
    void FUN_00410020(BSExtraData*, bool);
};

// Sets the ExtraCount extra data to aiCount: removes it when aiCount is 0 or 1, updates it if present, otherwise creates and adds it.
// @fnv 0x00419ad0
void FUN_00419ad0_shell::FUN_00419ad0(short aiCount)
{
    ExtraCount* pcount = (ExtraCount*)((BaseExtraList*)this)->GetExtraData(0x24);
    if (aiCount == 0 || aiCount == 1)
    {
        if (pcount)
            ((ExtraDataList_Remove_stub*)this)->FUN_00410020(pcount, true);
    }
    else if (pcount)
    {
        pcount->count = aiCount;
    }
    else
    {
        pcount = new ExtraCount(aiCount);
        ((BaseExtraList*)this)->AddExtra(pcount);
    }
}

namespace fnv_00419dc0 {
struct TESObjectREFRHelper
{
    void SetTargetingState(bool);
};
struct ExtraTarget : public BSExtraData
{
    TESObjectREFRHelper* pTarget;
    ExtraTarget(TESObjectREFRHelper*);
};
struct ExtraDataList_Remove_stub
{
    void FUN_00410020(BSExtraData*, bool);
};

struct FUN_00419dc0_shell2 : public ExtraDataList
{
    void FUN_00419dc0(TESObjectREFRHelper*);
};

// @fnv 0x00419dc0
void FUN_00419dc0_shell2::FUN_00419dc0(TESObjectREFRHelper* apRef)
{
    ExtraTarget* pextra = (ExtraTarget*)((BaseExtraList*)this)->GetExtraData(0x46);
    if (!apRef && pextra)
    {
        ((ExtraDataList_Remove_stub*)this)->FUN_00410020(pextra, true);
        return;
    }
    if (pextra)
    {
        pextra->pTarget = apRef;
    }
    else
    {
        pextra = new ExtraTarget(apRef);
        ((BaseExtraList*)this)->AddExtra(pextra);
    }
    if (apRef)
        apRef->SetTargetingState(true);
}
}  // namespace fnv_00419dc0

struct FUN_0041b580_shell : public ExtraDataList
{
    void SetHealthPerc(float);
};

struct ExtraHealthPerc : public BSExtraData
{
    float m_fHealthPercentage;
    ExtraHealthPerc();
};
struct ExtraListRemover
{
    void FUN_00410020(BSExtraData*, bool);
};

// Sets the ExtraHealthPerc extra data value to afPerc, creating it if missing, or removes it when afPerc equals 1.0.
// @fnv 0x0041b580
void FUN_0041b580_shell::SetHealthPerc(float afPerc)
{
    ExtraHealthPerc* pextra = (ExtraHealthPerc*)((BaseExtraList*)this)->GetExtraData(0x7a);
    if (afPerc != 1.0)
    {
        if (!pextra)
        {
            pextra = new ExtraHealthPerc;
            ((BaseExtraList*)this)->AddExtra(pextra);
        }
        pextra->m_fHealthPercentage = afPerc;
    }
    else
    {
        ((ExtraListRemover*)this)->FUN_00410020(pextra, true);
    }
}

namespace fnv_0041b8d0 {
struct bhkWorld;
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct FUN_0041b8d0_shell : public ExtraDataList
{
    void SetHavokWorld(bhkWorld*);
};

struct NP_0081c630
{
    NP_0081c630& operator=(void*);
};
struct ExtraHavok : public BSExtraData
{
    NP_0081c630 m_pHavokWorld;
    void* pData;
    ExtraHavok(bhkWorld*);
};
struct ExtraDataList_Remove_stub
{
    void FUN_00410020(BSExtraData*, bool);
};

// Gets the ExtraHavok entry; if apWorld is set, creates or updates it, otherwise removes the entry.
// @fnv 0x0041b8d0
void FUN_0041b8d0_shell::SetHavokWorld(bhkWorld* apWorld)
{
    ExtraHavok* pextra = (ExtraHavok*)((BaseExtraList*)this)->GetExtraData(1);
    if (apWorld)
    {
        if (!pextra)
        {
            pextra = new ExtraHavok(apWorld);
            ((BaseExtraList*)this)->AddExtra(pextra);
        }
        else
        {
            pextra->m_pHavokWorld = apWorld;
        }
    }
    else if (pextra)
    {
        ((ExtraDataList_Remove_stub*)this)->FUN_00410020(pextra, true);
    }
}
}  // namespace fnv_0041b8d0

namespace fnv_0041ba60 {
struct CellMopp;
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct FUN_0041ba60_shell : public ExtraDataList
{
    void SetCellMopp(CellMopp*);
};

struct NP_0081c630
{
    NP_0081c630& operator=(void*);
};
struct ExtraHavok : public BSExtraData
{
    int pad[1];
    NP_0081c630 spMopp;
    ExtraHavok(int);
};
// Gets the ExtraHavok extra data, creates and adds it if a mopp is given and none exists, then stores the mopp in it.
// @fnv 0x0041ba60
void FUN_0041ba60_shell::SetCellMopp(CellMopp* apMopp)
{
    ExtraHavok* pextra = (ExtraHavok*)((BaseExtraList*)this)->GetExtraData(1);
    if (apMopp && !pextra)
    {
        pextra = new ExtraHavok(0);
        ((BaseExtraList*)this)->AddExtra(pextra);
    }
    pextra->spMopp = apMopp;
}
}  // namespace fnv_0041ba60

namespace fnv_0041bd10 {
struct BGSLoadFormBuffer;
struct BGSMusicType;
struct BGSSaveFormBuffer;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiAVObject;
struct NiColor;
struct NiPoint3;
struct TESBoundObject;
struct TESForm;
struct blob8
{
    char b[8];
};
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct TESSoundFile : public BaseFormComponent
{
    virtual void SetSoundFile(char*);
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetSoundFileLength(TESForm*);
    unsigned int GetSoundFileLength();
    static char* GetSoundFile(TESForm*);
    char* GetSoundFile();
    void* __vecDelDtor(unsigned int);
    char m_kSoundFile[8];
};
typedef char _sizecheck_TESSoundFile[sizeof(TESSoundFile) == 12 ? 1 : -1];
struct FUN_0041bd10_shell : public ExtraDataList
{
    void FUN_0041bd10(BGSMusicType*);
};

struct FUN_0040ef30 : public BSExtraData
{
    BGSMusicType* pData;
    FUN_0040ef30(BGSMusicType*);
};

struct Dummy_00410020
{
    void FUN_00410020(BSExtraData*, bool);
};

// Sets or clears the music-type extra data (type 7) on the extra data list, adding a new entry or updating the existing one.
// @fnv 0x0041bd10
void FUN_0041bd10_shell::FUN_0041bd10(BGSMusicType* apData)
{
    BSExtraData* pExtra = ((BaseExtraList*)this)->GetExtraData(7);
    if (!apData)
    {
        if (pExtra)
        {
            ((Dummy_00410020*)this)->FUN_00410020(pExtra, true);
        }
    }
    else if (!pExtra)
    {
        pExtra = new FUN_0040ef30(apData);
        ((BaseExtraList*)this)->AddExtra(pExtra);
    }
    else
    {
        ((FUN_0040ef30*)pExtra)->pData = apData;
    }
}
}  // namespace fnv_0041bd10

namespace fnv_0041c090 {
struct BGSAcousticSpace;
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
struct TESRegion;
struct TESSound;
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
struct FUN_0041c090_shell : public ExtraDataList
{
    void SetAcousticSpace(BGSAcousticSpace*);
};

struct ExtraCellAcousticSpace : public BSExtraData
{
    BGSAcousticSpace* m_pPathingCell;
    ExtraCellAcousticSpace(BGSAcousticSpace*);
};
struct ExtraDataList_Remove_stub
{
    void FUN_00410020(BSExtraData*, bool);
};

// Sets or clears the cell's acoustic space extra data: removes the existing extra when apSpace is null, adds a new one, or updates its stored space.
// @fnv 0x0041c090
void FUN_0041c090_shell::SetAcousticSpace(BGSAcousticSpace* apSpace)
{
    ExtraCellAcousticSpace* pExtra = (ExtraCellAcousticSpace*)((BaseExtraList*)this)->GetExtraData(0x81);
    if (!apSpace)
    {
        if (pExtra)
            ((ExtraDataList_Remove_stub*)this)->FUN_00410020(pExtra, true);
    }
    else if (!pExtra)
    {
        pExtra = new ExtraCellAcousticSpace(apSpace);
        ((BaseExtraList*)this)->AddExtra(pExtra);
    }
    else
    {
        pExtra->m_pPathingCell = apSpace;
    }
}
}  // namespace fnv_0041c090

namespace fnv_0041c190 {
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiColor;
struct NiPoint3;
struct TESBoundObject;
struct TESClimate;
struct TESForm;
struct TESWeather;
struct blob8
{
    char b[8];
};
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct FUN_0041c190_shell : public ExtraDataList
{
    void SetClimate(TESClimate*);
};

struct FUN_0040f070 : public BSExtraData
{
    TESClimate* pData;
    FUN_0040f070(TESClimate*);
};

struct Dummy_00410020
{
    void FUN_00410020(BSExtraData*, bool);
};

// Sets or clears the climate extra data on this list: removes it when apData is null, adds a new entry when absent, otherwise updates the stored pointer.
// @fnv 0x0041c190
void FUN_0041c190_shell::SetClimate(TESClimate* apData)
{
    BSExtraData* pExtra = ((BaseExtraList*)this)->GetExtraData(8);
    if (!apData)
    {
        if (pExtra)
        {
            ((Dummy_00410020*)this)->FUN_00410020(pExtra, true);
        }
    }
    else if (!pExtra)
    {
        pExtra = new FUN_0040f070(apData);
        ((BaseExtraList*)this)->AddExtra(pExtra);
    }
    else
    {
        ((FUN_0040f070*)pExtra)->pData = apData;
    }
}
}  // namespace fnv_0041c190

namespace fnv_0041c290 {
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiColor;
struct NiPoint3;
struct TESBoundObject;
struct TESForm;
struct TESImageSpace;
struct blob8
{
    char b[8];
};
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct FUN_0041c290_shell : public ExtraDataList
{
    void SetImageSpaceExtra(TESImageSpace*);
};

struct FUN_0040f110 : public BSExtraData
{
    TESImageSpace* pData;
    FUN_0040f110(TESImageSpace*);
};

struct Dummy_00410020
{
    void FUN_00410020(BSExtraData*, bool);
};

// Sets or clears the image-space extra data (type 0x59) on this extra data list: removes it when apData is null, adds a new entry, or updates the existing one.
// @fnv 0x0041c290
void FUN_0041c290_shell::SetImageSpaceExtra(TESImageSpace* apData)
{
    BSExtraData* pExtra = ((BaseExtraList*)this)->GetExtraData(0x59);
    if (!apData)
    {
        if (pExtra)
        {
            ((Dummy_00410020*)this)->FUN_00410020(pExtra, true);
        }
    }
    else if (!pExtra)
    {
        pExtra = new FUN_0040f110(apData);
        ((BaseExtraList*)this)->AddExtra(pExtra);
    }
    else
    {
        ((FUN_0040f110*)pExtra)->pData = apData;
    }
}
}  // namespace fnv_0041c290

namespace fnv_0041d030 {
struct FUN_0041d030_shell : public ExtraDataList
{
    bool FUN_0041d030();
};

struct RecursiveSpinLock
{
    void Lock(const char*);
    void Unlock();
};
extern RecursiveSpinLock g_011c3920;
struct PatrolActorPackageData
{
    bool IsPatrolling();
};
struct ArrSI
{
    unsigned int GetFlags();
};

// @fnv 0x0041d030
bool FUN_0041d030_shell::FUN_0041d030()
{
    g_011c3920.Lock(0);
    bool bHasResultObj = false;
    PatrolActorPackageData* work = (PatrolActorPackageData*)((BaseExtraList*)this)->pHead;
    while (work)
    {
        switch (work->IsPatrolling())
        {
        case 0xd:
        case 0x1c:
        case 0x20:
        case 0x24:
        case 0x2f:
        case 0x30:
        case 0x4a:
            break;
        case 0x21:
            bHasResultObj = true;
            break;
        case 0x27:
            break;
        default:
            if (bHasResultObj)
                bHasResultObj = false;
            g_011c3920.Unlock();
            return bHasResultObj;
        }
        work = (PatrolActorPackageData*)((ArrSI*)work)->GetFlags();
    }
    g_011c3920.Unlock();
    return bHasResultObj;
}
}  // namespace fnv_0041d030

namespace fnv_0041fc10 {
struct Script;
struct TESForm;
struct TESIdleForm;
struct TESTopic;
struct PatrolRefData
{
    void Copy(PatrolRefData*);
    bool Compare(PatrolRefData*);
    void InitItem(TESForm*);
    void SetTimeAtRef(float);
    void SetOnPatrolIdle(TESIdleForm*);
    void SetOnPatrolTopic(TESTopic*);
    void SetOnPatrolScript(char*);
    float GetTimeAtRef();
    TESIdleForm* GetOnPatrolIdle();
    TESTopic* GetOnPatrolTopic();
    Script* GetOnPatrolScript();
    void* __vecDelDtor(unsigned int);
    float m_fPatrolValue;
    char m_kPatrolData[16];
};
typedef char _sizecheck_PatrolRefData[sizeof(PatrolRefData) == 20 ? 1 : -1];
struct FUN_0041fc10_shell : public ExtraDataList
{
    void SetPatrolRefData(PatrolRefData*);
};

struct Dummy_00410020
{
    void FUN_00410020(BSExtraData*, int);
};
struct ExtraPatrolRefData : public BSExtraData
{
    int pad;
    ExtraPatrolRefData();
    void SetSelectedMagicItem(PatrolRefData*);
};
// @fnv 0x0041fc10
void FUN_0041fc10_shell::SetPatrolRefData(PatrolRefData* apPatrolRefData)
{
    ExtraPatrolRefData* pextra = (ExtraPatrolRefData*)((BaseExtraList*)this)->GetExtraData(0x6f);
    if (pextra)
    {
        ((Dummy_00410020*)this)->FUN_00410020(pextra, 1);
    }
    if (apPatrolRefData)
    {
        pextra = new ExtraPatrolRefData();
        pextra->SetSelectedMagicItem(apPatrolRefData);
        ((BaseExtraList*)this)->AddExtra(pextra);
    }
}
}  // namespace fnv_0041fc10

namespace fnv_0041fec0 {
struct PatrolReferenceData
{
    void Endian();
    char m_pPatrolReferences[16];
};
typedef char _sizecheck_OcclusionPlaneLinkedRefData[sizeof(PatrolReferenceData) == 16 ? 1 : -1];
struct FUN_0041fec0_shell : public ExtraDataList
{
    void FUN_0041fec0(PatrolReferenceData*);
};

struct Dummy_00410020
{
    void FUN_00410020(BSExtraData*, int);
};
struct ExtraOcclusionPlaneRefData : public BSExtraData
{
    int pad;
    ExtraOcclusionPlaneRefData();
    void SetSelectedMagicItem(PatrolReferenceData*);
};
// @fnv 0x0041fec0
void FUN_0041fec0_shell::FUN_0041fec0(PatrolReferenceData* apData)
{
    ExtraOcclusionPlaneRefData* pextra = (ExtraOcclusionPlaneRefData*)((BaseExtraList*)this)->GetExtraData(0x76);
    if (pextra)
    {
        ((Dummy_00410020*)this)->FUN_00410020(pextra, 1);
    }
    if (apData)
    {
        pextra = new ExtraOcclusionPlaneRefData();
        pextra->SetSelectedMagicItem(apData);
        ((BaseExtraList*)this)->AddExtra(pextra);
    }
}
}  // namespace fnv_0041fec0

struct FUN_00421430_shell : public ExtraDataList
{
    void FUN_00421430(TESObjectREFR*);
};

struct ExtraMerchantContainer : public BSExtraData
{
    TESObjectREFR* pRef;
    ExtraMerchantContainer();
};
// Sets the merchant container reference extra data to apRef, creating it if absent, or removes the extra when apRef is null.
// @fnv 0x00421430
void FUN_00421430_shell::FUN_00421430(TESObjectREFR* apRef)
{
    if (apRef)
    {
        ExtraMerchantContainer* pextra = (ExtraMerchantContainer*)((BaseExtraList*)this)->GetExtraData(0x3c);
        if (pextra)
        {
            pextra->pRef = apRef;
        }
        else
        {
            pextra = new ExtraMerchantContainer();
            pextra->pRef = apRef;
            ((BaseExtraList*)this)->AddExtra(pextra);
        }
    }
    else
    {
        ((BaseExtraList*)this)->RemoveExtra(0x3c);
    }
}

struct FUN_00421b70_shell : public ExtraDataList
{
    void FUN_00421b70(TESObjectREFR*);
};

struct ExtraXTarget : public BSExtraData
{
    TESObjectREFR* pTarget;
    ExtraXTarget();
};

// Sets the ExtraXTarget's target reference, creating and adding the extra data if missing, or removing it when apTarget is null.
// @fnv 0x00421b70
void FUN_00421b70_shell::FUN_00421b70(TESObjectREFR* apTarget)
{
    if (apTarget)
    {
        ExtraXTarget* pextra = (ExtraXTarget*)((BaseExtraList*)this)->GetExtraData(0x44);
        if (pextra)
        {
            pextra->pTarget = apTarget;
        }
        else
        {
            pextra = new ExtraXTarget;
            pextra->pTarget = apTarget;
            ((BaseExtraList*)this)->AddExtra(pextra);
        }
    }
    else
    {
        ((BaseExtraList*)this)->RemoveExtra(0x44);
    }
}

namespace fnv_00421c60 {
struct BGSEncounterZone;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiColor;
struct NiPoint3;
struct TESBoundObject;
struct TESForm;
struct blob8
{
    char b[8];
};
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct FUN_00421c60_shell : public ExtraDataList
{
    void FUN_00421c60(BGSEncounterZone*);
};

struct ExtraEncounterZone : public BSExtraData
{
    BGSEncounterZone* m_pEncounterZone;
    ExtraEncounterZone();
};

// Sets the encounter zone extra data on this list to ap, creating the extra if missing, or removes it when ap is null.
// @fnv 0x00421c60
void FUN_00421c60_shell::FUN_00421c60(BGSEncounterZone* apZone)
{
    if (apZone)
    {
        ExtraEncounterZone* pextra = (ExtraEncounterZone*)((BaseExtraList*)this)->GetExtraData(0x74);
        if (pextra)
        {
            pextra->m_pEncounterZone = apZone;
        }
        else
        {
            pextra = new ExtraEncounterZone;
            pextra->m_pEncounterZone = apZone;
            ((BaseExtraList*)this)->AddExtra(pextra);
        }
    }
    else
    {
        ((BaseExtraList*)this)->RemoveExtra(0x74);
    }
}
}  // namespace fnv_00421c60

namespace fnv_00421d50 {
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiColor;
struct NiPoint3;
struct TESBoundObject;
struct TESForm;
struct blob8
{
    char b[8];
};
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct FUN_00421d50_shell : public ExtraDataList
{
    void SetEmittanceSource(TESForm*);
};

struct ExtraEmittanceSource : public BSExtraData
{
    TESForm* pSource;
    ExtraEmittanceSource();
};

// Sets the ExtraEmittanceSource extra data's pSource to ap, creating and adding the extra if missing, or removing extra type 0x67 when ap is null.
// @fnv 0x00421d50
void FUN_00421d50_shell::SetEmittanceSource(TESForm* apSource)
{
    if (apSource)
    {
        ExtraEmittanceSource* pextra = (ExtraEmittanceSource*)((BaseExtraList*)this)->GetExtraData(0x67);
        if (pextra)
        {
            pextra->pSource = apSource;
        }
        else
        {
            pextra = new ExtraEmittanceSource;
            pextra->pSource = apSource;
            ((BaseExtraList*)this)->AddExtra(pextra);
        }
    }
    else
    {
        ((BaseExtraList*)this)->RemoveExtra(0x67);
    }
}
}  // namespace fnv_00421d50

struct ExtraNavMeshPortal;
struct FUN_0042e2c0_shell : public ExtraDataList
{
    void EnsureNavMeshPortalExtra(ExtraNavMeshPortal*);
};

struct TwoIntRecord
{
    int a;
    int b;
    TwoIntRecord(const TwoIntRecord&);
};
struct FUN_00416ad0 : public BSExtraData
{
    int pad[2];
    FUN_00416ad0(TwoIntRecord);
};
struct ExtraNavMeshPortal : public BSExtraData
{
    TwoIntRecord handle;
};
// @fnv 0x0042e2c0
void FUN_0042e2c0_shell::EnsureNavMeshPortalExtra(ExtraNavMeshPortal* apPortal)
{
    ExtraNavMeshPortal* pextra = (ExtraNavMeshPortal*)((BaseExtraList*)this)->GetExtraData(0x5a);
    if (!pextra)
    {
        pextra = (ExtraNavMeshPortal*)new FUN_00416ad0(apPortal->handle);
        ((BaseExtraList*)this)->AddExtra(pextra);
    }
    else
    {
        pextra = apPortal;
    }
}

namespace fnv_0042ee00 {
struct Actor;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct CHUNK;
struct DialogueTopicData;
struct DialogueItem;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiColor;
struct NiPoint3;
struct QuestDialogueInfo;
struct TESBoundObject;
struct TESForm;
struct TESQuest;
struct TESTopic;
struct TESTopicInfo;
struct TopicInfoArray;
struct blob8
{
    char b[8];
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
struct FUN_0042ee00_shell : public ExtraDataList
{
    void FUN_0042ee00(TESTopic*);
};

struct ExtraSayToTopicInfo : public BSExtraData
{
    TESTopic* pTopic;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    ExtraSayToTopicInfo();
};
struct FUN_0042edb0_shell
{
    void FUN_0042edb0();
};
struct BGSQuestObjective
{
    void SetOwner(TESQuest*);
};

// @fnv 0x0042ee00
void FUN_0042ee00_shell::FUN_0042ee00(TESTopic* apTopic)
{
    if (!apTopic)
    {
        ((FUN_0042edb0_shell*)this)->FUN_0042edb0();
        return;
    }
    ExtraSayToTopicInfo* pextra = (ExtraSayToTopicInfo*)((BaseExtraList*)this)->GetExtraData(0x75);
    if (!pextra)
    {
        pextra = new ExtraSayToTopicInfo;
        pextra->pTopic = 0;
        ((BaseExtraList*)this)->AddExtra(pextra);
    }
    ((BGSQuestObjective*)pextra)->SetOwner((TESQuest*)apTopic);
}
}  // namespace fnv_0042ee00

namespace fnv_0042f200 {
struct FUN_0042f200_shell : public ExtraDataList
{
    void SetIgnoredBySandbox(bool);
};

struct ExtraIgnoredBySandbox : public BSExtraData
{
    ExtraIgnoredBySandbox();
};
struct ExtraListRemover
{
    void FUN_00410020(BSExtraData*, bool);
};

// @fnv 0x0042f200
void FUN_0042f200_shell::SetIgnoredBySandbox(bool abIgnored)
{
    ExtraIgnoredBySandbox* pextra = (ExtraIgnoredBySandbox*)((BaseExtraList*)this)->GetExtraData(0x80);
    if (!pextra && abIgnored)
    {
        pextra = new ExtraIgnoredBySandbox;
        ((BaseExtraList*)this)->AddExtra(pextra);
    }
    else if (pextra && !abIgnored)
    {
        ((ExtraListRemover*)this)->FUN_00410020(pextra, true);
    }
}
}  // namespace fnv_0042f200

namespace fnv_0042f300 {
struct FUN_0042f300_shell : public ExtraDataList
{
    void FUN_0042f300(TESObjectREFR*);
};

struct FUN_004379a0_holder : public BSExtraData
{
    TESObjectREFR* pRef;
    FUN_004379a0_holder(TESObjectREFR*);
};

struct Dummy_00410020
{
    void FUN_00410020(BSExtraData*, bool);
};

// @fnv 0x0042f300
void FUN_0042f300_shell::FUN_0042f300(TESObjectREFR* apUser)
{
    BSExtraData* pextra = ((BaseExtraList*)this)->GetExtraData(0x88);
    if (!pextra && apUser)
    {
        pextra = new FUN_004379a0_holder(apUser);
        ((BaseExtraList*)this)->AddExtra(pextra);
    }
    else if (pextra && !apUser)
    {
        ((Dummy_00410020*)this)->FUN_00410020(pextra, true);
    }
}
}  // namespace fnv_0042f300

struct FUN_0040f780_struct
{
    void FUN_0040f7b0();
    void* FUN_0040f780(unsigned int flags);
};
void _Deallocate(void*);
// Calls FUN_0040f7b0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0040f780
void* FUN_0040f780_struct::FUN_0040f780(unsigned int flags)
{
    FUN_0040f7b0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_00411d90 {
extern "C" void __cdecl _Deallocate(void*);

struct ExtraLitWaterRefs
{
    virtual void* FUN_00411d90(unsigned int flags);
    void FUN_00434dc0();
};

// Calls FUN_00434dc0, then frees this object with _Deallocate if flags has bit 0 set, and returns this.
// @fnv 0x00411d90
void* ExtraLitWaterRefs::FUN_00411d90(unsigned int flags)
{
    FUN_00434dc0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_00411d90

struct FUN_00411e20Class
{
    unsigned char mFlags[16];
    bool HasFlag(unsigned char aFlag);
};

// Returns true if the flag bit aFlag is set in mFlags[0xC].
// @fnv 0x00411e20
bool FUN_00411e20Class::HasFlag(unsigned char aFlag)
{
    return (mFlags[0xC] & aFlag) != 0;
}

struct FUN_00418280_Class
{
    BSExtraData* FUN_00418280();
};

// Looks up extra data of type 0x40 in the list and returns the pointer stored at offset 0xc of it, or null if absent.
// @fnv 0x00418280
BSExtraData* FUN_00418280_Class::FUN_00418280()
{
    BSExtraData* extra = ((BaseExtraList*)this)->GetExtraData(0x40);
    if (extra)
        return *(BSExtraData**)((unsigned char*)extra + 0xc);
    return 0;
}

struct FUN_004187d0_Class : BaseExtraList
{
    BSExtraData* FUN_004187d0();
};

// Looks up extra data of type 0x3F and returns the pointer stored at offset 0xC, or null if absent.
// @fnv 0x004187d0
BSExtraData* FUN_004187d0_Class::FUN_004187d0()
{
    BSExtraData* pData = GetExtraData(0x3F);
    if (pData)
    {
        return *(BSExtraData**)((char*)pData + 0xC);
    }
    else
    {
        return 0;
    }
}

struct GO
{
    ~GO();
    void FUN_00418f40();
};

// @fnv 0x00418f40
void GO::FUN_00418f40()
{
    GO::~GO();
}

void _Deallocate(void*);

struct FUN_00419350
{
    void FUN_00438bf0();
    void* DeleteThis(unsigned int flags);
};

// Calls FUN_00438bf0, frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00419350
void* FUN_00419350::DeleteThis(unsigned int flags)
{
    FUN_00438bf0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_0041ae30Class
{
    void FUN_0041ae30();
};

// @fnv 0x0041ae30
void FUN_0041ae30Class::FUN_0041ae30()
{
    ((BaseExtraList*)this)->RemoveExtra(0x29);
}

struct FUN_0041ae50_struct : BaseExtraList
{
    void FUN_0041ae50();
};

// @fnv 0x0041ae50
void FUN_0041ae50_struct::FUN_0041ae50()
{
    this->RemoveExtra(0x40);
}

struct FUN_0041aef0_StandIn
{
    void FUN_0041aef0();
};

// @fnv 0x0041aef0
void FUN_0041aef0_StandIn::FUN_0041aef0()
{
    ((BaseExtraList*)this)->RemoveExtra(0x25);
}

struct FUN_0041af10_Class
{
    void RemoveExtra24();
};

// @fnv 0x0041af10
void FUN_0041af10_Class::RemoveExtra24()
{
    ((BaseExtraList*)this)->RemoveExtra(0x24);
}

namespace fnv_0041b680 {
struct FUN_00432f30_D
{
    void FUN_00432f30();
};

void _Deallocate(void*);

struct ExtraAction
{
    void* FUN_0041b680(unsigned int flags);
};

// Calls FUN_00432f30 on this, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0041b680
void* ExtraAction::FUN_0041b680(unsigned int flags)
{
    ((FUN_00432f30_D*)this)->FUN_00432f30();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_0041b680

struct FUN_0041c160_Class : BaseExtraList
{
    int __thiscall FUN_0041c160();
};

// Looks up extra data of type 0x81 and returns the int stored at offset 0xC, or 0 if absent.
// @fnv 0x0041c160
int __thiscall FUN_0041c160_Class::FUN_0041c160()
{
    BSExtraData* extra = this->GetExtraData(0x81);
    if (!extra)
        return 0;
    return *(int*)((char*)extra + 0xC);
}

struct BaseExtraList2
{
    void** m_ppVirtualMethodTable;
    BSExtraData* pHead;
    unsigned char iFlags[21];
    unsigned char layoutPadding1D[3];
    BSExtraData* GetExtraData(unsigned char);
    int FUN_0041c260();
};

// Returns the int at offset 0xC of the extra data of type 8, or 0 if none exists.
// @fnv 0x0041c260
int BaseExtraList2::FUN_0041c260()
{
    BSExtraData* extra = GetExtraData(8);
    if (extra == 0)
        return 0;
    return *(int*)((unsigned char*)extra + 0xC);
}

namespace fnv_0041d490 {
struct RagDollData;
struct FUN_0041d490_shell : public ExtraDataList
{
    void UpdateRagDoll(TESObjectREFR*);
};

struct FUN_004d9330
{
    unsigned int m_uiBoneCount;
    void* pBoneData;
    float fRootX, fRootY, fRootZ;
    FUN_004d9330();
    void FUN_004d9800(TESObjectREFR* apRef);
};
struct ExtraRagDollData : public BSExtraData
{
    FUN_004d9330* m_pRagDollData;
    ExtraRagDollData();
};
struct ExtraListRemover : public ExtraDataList
{
    void FUN_00410020(BSExtraData* apExtra, bool abDelete);
};
// Gets the ragdoll extra data; removes it when apRef is null, otherwise updates it, creating and adding it if missing.
// @fnv 0x0041d490
void FUN_0041d490_shell::UpdateRagDoll(TESObjectREFR* apRef)
{
    ExtraRagDollData* pextra = (ExtraRagDollData*)GetExtraData(0x14);
    if (pextra)
    {
        if (!apRef)
            ((ExtraListRemover*)this)->FUN_00410020(pextra, true);
        else
            pextra->m_pRagDollData->FUN_004d9800(apRef);
    }
    else if (apRef)
    {
        pextra = new ExtraRagDollData;
        pextra->m_pRagDollData = new FUN_004d9330;
        pextra->m_pRagDollData->FUN_004d9800(apRef);
        AddExtra(pextra);
    }
}
}  // namespace fnv_0041d490

struct FUN_0041db80_Class
{
    unsigned char bFlag;
    void SetFlag(bool value);
};

// Sets or clears bit 0 of the byte at offset 0x10 of this object according to value.
// @fnv 0x0041db80
void FUN_0041db80_Class::SetFlag(bool abSet)
{
    abSet ? ((unsigned char*)this)[0x10] |= 1 : ((unsigned char*)this)[0x10] &= ~1;
}

struct FUN_0041dc00_Class
{
    char _0x00;
    char _0x01;
    char _0x02;
    char _0x03;
    char _0x04;
    char _0x05;
    char _0x06;
    char _0x07;
    char _0x08;
    char _0x09;
    char _0x0A;
    char _0x0B;
    char _0x0C;
    char _0x0D;
    char _0x0E;
    char _0x0F;
    unsigned char _0x10;
    bool IsFlag2Set();
};

// @fnv 0x0041dc00
bool FUN_0041dc00_Class::IsFlag2Set()
{
    return _0x10 & 2;
}

struct FUN_0041dc50_class
{
    unsigned char b16;  // +0x10
    bool IsFlag4Set();
};

// @fnv 0x0041dc50
bool FUN_0041dc50_class::IsFlag4Set()
{
    return ((unsigned char*)this)[0x10] & 0x4;
}

struct FUN_0041e220_StandIn : BaseExtraList
{
    int FUN_0041e220();
};

// Looks up extra data of type 0x3b and returns the int stored at offset 0xc, or 0 if absent.
// @fnv 0x0041e220
int FUN_0041e220_StandIn::FUN_0041e220()
{
    BSExtraData* extra = GetExtraData(0x3b);
    if (extra)
        return *(int*)((char*)extra + 0xc);
    return 0;
}

struct FUN_0041eff0
{
    void SetExtraData(float fValue);
};

// Retrieves the extra data entry with type 0x54 from the list and, if present, writes fValue into its field at offset 0x14.
// @fnv 0x0041eff0
void FUN_0041eff0::SetExtraData(float fValue)
{
    BSExtraData* pExtra = ((BaseExtraList*)this)->GetExtraData(0x54);
    if (pExtra)
    {
        *(float*)((char*)pExtra + 0x14) = fValue;
    }
}

namespace fnv_0041f330 {
struct ReferenceFlagRecord;
struct TESForm;
struct FUN_0041f330_shell : public ExtraDataList
{
    void SetRefInReflectorList(TESObjectREFR*, bool);
};

struct ReferenceFlagRecord
{
    TESObjectREFR* pRef;
    unsigned int uiFlags;
};
struct ReflectorRefList
{
    ReferenceFlagRecord* pItem;
    ReflectorRefList* pNext;
    ReferenceFlagRecord** _ref_006815c0();
    ReflectorRefList* _ref_00726070();
    bool _ref_008256d0();
};
struct FUN_00411be0 : public BSExtraData
{
    ReflectorRefList kRefList;
    FUN_00411be0();
    void FUN_00434800(TESObjectREFR* apRef);
    void AddReflectedRef(TESObjectREFR* apRef, unsigned int auiFlags);
};
struct ExtraListRemover : public ExtraDataList
{
    void FUN_00410020(BSExtraData* apExtra, bool abDelete);
};
// Finds apRef in the extra data's reflector list and sets or clears flag 2, adding the extra data and entry when bValue is true.
// @fnv 0x0041f330
void FUN_0041f330_shell::SetRefInReflectorList(TESObjectREFR* apRef, bool abEnabled)
{
    FUN_00411be0* pextra = (FUN_00411be0*)GetExtraData(0x66);
    if (pextra)
    {
        ReflectorRefList* preflist = &pextra->kRefList;
        while (preflist && *preflist->_ref_006815c0())
        {
            if ((*preflist->_ref_006815c0())->pRef == apRef)
            {
                if (abEnabled)
                {
                    (*preflist->_ref_006815c0())->uiFlags |= 2;
                }
                else
                {
                    (*preflist->_ref_006815c0())->uiFlags &= ~2;
                    if (!(*preflist->_ref_006815c0())->uiFlags)
                    {
                        pextra->FUN_00434800(apRef);
                        if (pextra->kRefList._ref_008256d0())
                            ((ExtraListRemover*)this)->FUN_00410020(pextra, true);
                    }
                }
                return;
            }
            preflist = preflist->_ref_00726070();
        }
    }
    if (abEnabled)
    {
        if (!pextra)
        {
            pextra = new FUN_00411be0;
            AddExtra(pextra);
        }
        pextra->AddReflectedRef(apRef, 2);
    }
}
}  // namespace fnv_0041f330

struct PatrolRefData
{
    bool Compare(PatrolRefData* apOther);
};

struct ExtraPatrolRefData
{
    void* m_base;
    void* m_auiShapeKeys;
    void* m_pAuxiliaryObject;
    PatrolRefData* pPatrolRefData;
    bool FUN_0041fd20(ExtraPatrolRefData* apCompare);
};

// @fnv 0x0041fd20
bool ExtraPatrolRefData::FUN_0041fd20(ExtraPatrolRefData* apCompare)
{
    ExtraPatrolRefData* potherExtra = apCompare;

    if (!pPatrolRefData && !potherExtra->pPatrolRefData)
        return false;
    if (!pPatrolRefData || !potherExtra->pPatrolRefData)
        return true;
    if (pPatrolRefData->Compare(potherExtra->pPatrolRefData))
        return true;
    return false;
}

namespace fnv_0041fd80 {
struct ExtraPatrolRefData
{
    void __thiscall FUN_0041fdb0();
    void* __thiscall FUN_0041fd80(unsigned int flags);
};

extern "C" void* __cdecl _Deallocate(void*);

// Calls FUN_0041fdb0, then frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0041fd80
void* __thiscall ExtraPatrolRefData::FUN_0041fd80(unsigned int flags)
{
    FUN_0041fdb0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_0041fd80

void _Deallocate(void*);

struct FUN_004200c0Class
{
    void* m0;
    void* m4;
    void* m8;
    void* mC;
    void FUN_004200c0();
};

// Frees the pointer stored in mC via _Deallocate and resets mC to null.
// @fnv 0x004200c0
void FUN_004200c0Class::FUN_004200c0()
{
    if (mC)
    {
        void* p = mC;
        _Deallocate(p);
    }
    mC = 0;
}

struct FUN_00420ba0_Class
{
    void __thiscall FUN_00420ba0(int value);
};

// @fnv 0x00420ba0
void __thiscall FUN_00420ba0_Class::FUN_00420ba0(int value)
{
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x100) = value;
}

struct ExtraCollisionData
{
    virtual ~ExtraCollisionData();
    void* FUN_00421130(unsigned int flags);
    void FUN_00421160();
};

void __cdecl _Deallocate(ExtraCollisionData*);

// Calls FUN_00421160, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00421130
void* ExtraCollisionData::FUN_00421130(unsigned int flags)
{
    FUN_00421160();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_00421820_Class : BaseExtraList
{
    int FUN_00421820();
};

// Looks up extra data of type 0xb and returns the int stored at offset 0xc, or 0 if absent.
// @fnv 0x00421820
int FUN_00421820_Class::FUN_00421820()
{
    BSExtraData* extra = GetExtraData(0xb);
    if (extra)
        return *(int*)((char*)extra + 0xc);
    return 0;
}

struct FUN_00421f00_Class
{
    int FUN_00421f00();
};

// Reads extra data of type 0x62 from the extra list and returns the int at offset 0xc, or 0 if absent.
// @fnv 0x00421f00
int FUN_00421f00_Class::FUN_00421f00()
{
    BSExtraData* p = ((BaseExtraList*)this)->GetExtraData(0x62);
    if (p)
        return *(int*)((char*)p + 0xc);
    return 0;
}

namespace fnv_00422420 {
extern int DAT_01015214;

struct BE
{
    BE(unsigned char);
};

struct FUN_00422420 : BE
{
    FUN_00422420(float fValue);
};

// Initialises the object with vtable DAT_01015214 and stores fValue at offset 0xc.
// @fnv 0x00422420
FUN_00422420::FUN_00422420(float fValue) : BE(0x5d)
{
    *(int**)this = (int*)&DAT_01015214;
    *(float*)((char*)this + 0xc) = fValue;
}
}  // namespace fnv_00422420

struct FUN_00422450 : BaseExtraList
{
    float GetExtraDataFloat();
};

// Looks up extra data of type 0x5d and returns the float stored at offset 0xc, or 0.0f if absent.
// @fnv 0x00422450
float FUN_00422450::GetExtraDataFloat()
{
    BSExtraData* extra = GetExtraData(0x5d);
    if (extra)
        return *(float*)((char*)extra + 0xc);
    return 0.0f;
}

class ExtraFriendHits : public BSExtraData
{
  public:
    int GetFriendHitSlotCount();
};

class BaseExtraList;

class FUN_00422640Class : public BaseExtraList
{
  public:
    int FUN_00422640();
};

// @fnv 0x00422640
int __thiscall FUN_00422640Class::FUN_00422640()
{
    ExtraFriendHits* pextra = static_cast<ExtraFriendHits*>(GetExtraData(0x45));
    if (pextra)
        return pextra->GetFriendHitSlotCount();
    return 0;
}

struct FUN_00422a10
{
    void* m_ppVirtualMethodTable;
    BSExtraData* pHead;
    unsigned char iFlags[21];
    unsigned char layoutPadding1D[3];
    BSExtraData* GetExtraData(unsigned char);
    char* GetExtraDataText();
};

// Looks up extra data of type 0x42 and returns the pointer stored at offset 0xc, or null if absent.
// @fnv 0x00422a10
char* FUN_00422a10::GetExtraDataText()
{
    BSExtraData* pextra = GetExtraData(0x42);
    if (pextra)
        return *(char**)((char*)pextra + 0xc);
    return 0;
}

struct FUN_00428130_Class
{
    void SetValue(int param_2);
};

// @fnv 0x00428130
void FUN_00428130_Class::SetValue(int aiValue)
{
    *reinterpret_cast<int*>(this + 0x17) = aiValue;
}

namespace fnv_0042c900 {
extern "C" void* DAT_0101595c;

struct BE
{
    void* m_vftable;
    unsigned char m_iWordAt04;
    unsigned char m_5;
    unsigned char m_6;
    unsigned char m_7;
    unsigned char m_8;
    unsigned char m_9;
    unsigned char m_kPointA;
    unsigned char m_kPointB;
    void* m_0c;
    BE(unsigned char c);
};

struct FUN_0042c900 : BE
{
    FUN_0042c900();
};

// Constructs the object with byte value 0x3f, sets its vftable to DAT_0101595c and clears m_0c.
// @fnv 0x0042c900
FUN_0042c900::FUN_0042c900() : BE(0x3f)
{
    m_vftable = &DAT_0101595c;
    m_0c = 0;
}
}  // namespace fnv_0042c900

namespace fnv_0042c9c0 {
extern "C" void* DAT_01015184;

struct BE
{
    __thiscall BE(unsigned char);
};

struct FUN_0042c9c0 : BE
{
    __thiscall FUN_0042c9c0();
};

// Initialises the object: sets its vtable pointer to DAT_01015184 and zeroes the float at offset 0xc.
// @fnv 0x0042c9c0
__thiscall FUN_0042c9c0::FUN_0042c9c0() : BE(0x56)
{
    *reinterpret_cast<void**>(this) = &DAT_01015184;
    *reinterpret_cast<float*>(this + 0xc) = 0.0f;
}
}  // namespace fnv_0042c9c0

struct ExtraSecuritronFace
{
    void* __thiscall FUN_0042cd40(unsigned int flags);
    void __thiscall FUN_0042cd70();
};

void __cdecl _Deallocate(void* p);

// Calls FUN_0042cd70, frees this when flags has bit 0 set, and returns this.
// @fnv 0x0042cd40
void* __thiscall ExtraSecuritronFace::FUN_0042cd40(unsigned int flags)
{
    FUN_0042cd70();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_0042e480_Class
{
    unsigned char mFlag[0xc];
    void FUN_0042e480(unsigned char arg);
};

// Sets the byte at offset 0xc of mFlag by OR-ing it with arg.
// @fnv 0x0042e480
void FUN_0042e480_Class::FUN_0042e480(unsigned char arg)
{
    mFlag[0xc] |= arg;
}

struct FUN_0042e910Class
{
    BSExtraData* FUN_0042e910();
};

// @fnv 0x0042e910
BSExtraData* FUN_0042e910Class::FUN_0042e910()
{
    BSExtraData* result = ((BaseExtraList*)this)->GetExtraData(0x60);
    return result;
}

namespace fnv_0042ea00 {
struct ActorCause;

template <class T> struct NiPointer
{
    T* m_ptr;
    NiPointer& operator=(T* p);
};

struct FUN_0042ea00Class
{
    void FUN_0042ea00(ActorCause* cause);
};

// @fnv 0x0042ea00
void FUN_0042ea00Class::FUN_0042ea00(ActorCause* cause)
{
    ((NiPointer<ActorCause>*)((char*)this + 0x0c))->operator=(cause);
}
}  // namespace fnv_0042ea00

namespace fnv_0042ec30 {
extern int DAT_01015998;

struct BE
{
    void* m_ppVirtualMethodTable;
    int m_kPointA;
    int m_kPointB;
    BE(unsigned char a);
};

struct FUN_0042ec30 : BE
{
    void* c;
    void* d;
    FUN_0042ec30(void* a, void* b);
};

// Sets the vtable pointer to DAT_01015998 and stores the two constructor arguments into fields c and d.
// @fnv 0x0042ec30
FUN_0042ec30::FUN_0042ec30(void* pFirst, void* pSecond) : BE(0x6E)
{
    *reinterpret_cast<void**>(this) = reinterpret_cast<void*>(&DAT_01015998);
    this->c = pFirst;
    this->d = pSecond;
}
}  // namespace fnv_0042ec30

struct FUN_0056aac0_map
{
    void* m_ppVirtualMethodTable;
    unsigned int m_uiHashSize;
    void* m_ppkHashTable;
    unsigned int m_uiCount;
    FUN_0056aac0_map(unsigned int hashSize);
    ~FUN_0056aac0_map();
    void SetAt(TESObjectREFR* key, bool value);
    bool GetAt(TESObjectREFR* key, bool& value);
};

TESForm* GetFormByID(unsigned int formID);

struct FUN_0056aac0_t : public TESObjectREFR
{
    TESObjectREFR* GetEnableParent();
    bool GetInitialized() const;
    bool FUN_0056aac0();
};

// @fnv 0x0056aac0
bool FUN_0056aac0_t::FUN_0056aac0()
{
    bool result = true;
    FUN_0056aac0_map visited(0x25);
    TESObjectREFR* ref = GetEnableParent();
    while (ref && result)
    {
        if (ref == this)
            result = false;
        else
        {
            visited.SetAt(ref, true);
            if (static_cast<FUN_0056aac0_t*>(ref)->GetInitialized())
                ref = static_cast<FUN_0056aac0_t*>(ref)->GetEnableParent();
            else
            {
                TESObjectREFR* parent = static_cast<FUN_0056aac0_t*>(ref)->GetEnableParent();
                if (parent)
                    ref = dynamic_cast<TESObjectREFR*>(GetFormByID(reinterpret_cast<unsigned int>(parent)));
                else
                    ref = 0;
            }
            bool seen = false;
            if (ref && visited.GetAt(ref, seen) && seen)
                ref = 0;
        }
    }
    return result;
}

struct Setting_S
{
    float* Float();
};

extern Setting_S originalRuntimeFloatSetting594;

// @fnv 0x006463e0
float FUN_006463e0(float value)
{
    float result = value * *originalRuntimeFloatSetting594.Float();
    return result;
}

namespace fnv_0069bb00 {
class NavMesh;
template <class T> class NiPointer
{
  public:
    NiPointer(const NiPointer& rkPointer);
    ~NiPointer();
    T* m_pObject;
};
struct FUN_0069bb00_t
{
    int FindIndex(NiPointer<NavMesh> apSearchNavMesh);
    void RemoveAndCollect(int iIndex);
    void FUN_0069bb00(NiPointer<NavMesh> apSearchNavMesh);
};
// @fnv 0x0069bb00
void FUN_0069bb00_t::FUN_0069bb00(NiPointer<NavMesh> apNavMesh)
{
    int iIndex = FindIndex(apNavMesh);
    if (iIndex != -1)
        RemoveAndCollect(iIndex);
}
}  // namespace fnv_0069bb00

struct _DummyExtraDataList
{
    int* vtable;
    void FUN_0040fae0(bool);
    void FUN_0040f7b0();
};

extern int DAT_01014300;

// @fnv 0x0040f7b0
void __thiscall _DummyExtraDataList::FUN_0040f7b0()
{
    vtable = &DAT_01014300;
    FUN_0040fae0(true);
}

namespace fnv_00411c50 {
struct ExtraReflectorRefs
{
    void* __thiscall FUN_00434af0();
    void* __thiscall FUN_00411c50(unsigned int);
};

extern "C" void __cdecl _Deallocate(void*);

void* __thiscall ExtraReflectorRefs::FUN_00434af0()
{
    return this;
}

// Returns this, and when bit 0 of flags is set, deallocates this before returning it.
// @fnv 0x00411c50
void* __thiscall ExtraReflectorRefs::FUN_00411c50(unsigned int flags)
{
    FUN_00434af0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_00411c50

template <int N> struct EndianSizeTag
{
};

void __cdecl BSEndian(int*, EndianSizeTag<2>);

struct FUN_004140f0_struct
{
    void FUN_004140f0();
};

// @fnv 0x004140f0
void FUN_004140f0_struct::FUN_004140f0()
{
    BSEndian((int*)(this + 0), EndianSizeTag<2>());
    BSEndian((int*)(this + 4), EndianSizeTag<2>());
    BSEndian((int*)(this + 8), EndianSizeTag<2>());
    BSEndian((int*)(this + 0xc), EndianSizeTag<2>());
    BSEndian((int*)(this + 0x10), EndianSizeTag<2>());
    BSEndian((int*)(this + 0x14), EndianSizeTag<2>());
    BSEndian((int*)(this + 0x18), EndianSizeTag<2>());
    BSEndian((int*)(this + 0x1c), EndianSizeTag<2>());
    BSEndian((int*)(this + 0x20), EndianSizeTag<2>());
}

namespace fnv_00418f10 {
struct GO
{
    void FUN_00418f40(void);
    void* FUN_00418f10(unsigned int flags);
};
void GO::FUN_00418f40(void)
{}
void* _Deallocate(void*);

// Calls FUN_00418f40, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x00418f10
void* GO::FUN_00418f10(unsigned int flags)
{
    GO::FUN_00418f40();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_00418f10

struct FUN_006665a0_shell
{
    void FUN_006665a0();
    void* DeleteIfFlagged(unsigned int flags);
};

void _Deallocate(void* p);

// @fnv 0x00419220
void* FUN_006665a0_shell::DeleteIfFlagged(unsigned int flags)
{
    FUN_006665a0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct Flt
{
    __declspec(noinline) operator unsigned int() const;
};

struct FUN_0041a1f0Class
{
    __declspec(noinline) operator unsigned int() const;
    bool __thiscall Equals(Flt* other);
};

// Compares the unsigned int conversion of other with that of this and returns whether they are equal.
// @fnv 0x0041a1f0
bool __thiscall FUN_0041a1f0Class::Equals(Flt* other)
{
    return (unsigned int)(*other) == (unsigned int)(*this);
}

namespace fnv_0041a250 {
struct SoundPlaybackHandle
{
    unsigned int m_uiSoundResourceID;
    bool m_bLooping;
    unsigned int eState;
    SoundPlaybackHandle* __thiscall FUN_0041a250();
};

// @fnv 0x0041a250
SoundPlaybackHandle* __thiscall SoundPlaybackHandle::FUN_0041a250()
{
    m_uiSoundResourceID = 0xffffffff;
    m_bLooping = 0;
    eState = 0;
    return this;
}
}  // namespace fnv_0041a250

struct FUN_0041b010
{
    void __thiscall Method(unsigned char type);
};

// Removes extra 0x17 when type is nonzero, otherwise removes extra 0x16, from the BaseExtraList.
// @fnv 0x0041b010
void __thiscall FUN_0041b010::Method(unsigned char type)
{
    if (type)
        ((BaseExtraList*)this)->RemoveExtra(0x17);
    else
        ((BaseExtraList*)this)->RemoveExtra(0x16);
}

struct FUN_0041b7c0_cls : BaseExtraList
{
    void RemoveExtraType86();
};

// @fnv 0x0041b7c0
void FUN_0041b7c0_cls::RemoveExtraType86()
{
    RemoveExtra(0x56);
}

struct FUN_0041bf20_Class
{
    unsigned char b0C;
    signed char b0D;
    bool __thiscall FUN_0041bf20();
};

// Returns true when byte at offset 0x0C is zero and signed byte at offset 0x0D equals -1.
// @fnv 0x0041bf20
bool __thiscall FUN_0041bf20_Class::FUN_0041bf20()
{
    if (((unsigned char*)this)[0x0C] == 0 && (signed char)((unsigned char*)this)[0x0D] == -1)
        return true;
    return false;
}

struct ExtraAshPileRef : BSExtraData
{
    ExtraAshPileRef();
    TESObjectREFR* m_pAshPileRef;
};

struct FUN_0041de40_class : BaseExtraList
{
    void FUN_0041de40(TESObjectREFR* apRef);
};

// Stores apRef in the extra data of type 0x39, creating it if missing, or removes that extra data when apRef is null.
// @fnv 0x0041de40
void __thiscall FUN_0041de40_class::FUN_0041de40(TESObjectREFR* apRef)
{
    if (apRef)
    {
        ExtraAshPileRef* pextra = (ExtraAshPileRef*)this->GetExtraData(0x39);
        if (!pextra)
        {
            pextra = new ExtraAshPileRef;
            this->AddExtra((BSExtraData*)pextra);
        }
        pextra->m_pAshPileRef = apRef;
    }
    else
    {
        this->RemoveExtra(0x39);
    }
}

namespace fnv_0041fb20 {
extern void* __cdecl _Deallocate(void*);

struct ExtraPrimitive
{
    void* __thiscall FUN_0041fb20(unsigned int flags);
    void* __thiscall FUN_0041fb50();
};

// Calls FUN_0041fb50, then frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0041fb20
void* __thiscall ExtraPrimitive::FUN_0041fb20(unsigned int flags)
{
    FUN_0041fb50();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_0041fb20

namespace fnv_0041ff80 {
extern int DAT_010151cc;

struct BE
{
    BE(unsigned char);
};

struct FUN_0041ff80 : BE
{
    FUN_0041ff80();
};

// @fnv 0x0041ff80
FUN_0041ff80::FUN_0041ff80() : BE(0x76)
{
    *reinterpret_cast<void**>(this) = reinterpret_cast<void**>(&DAT_010151cc);
}
}  // namespace fnv_0041ff80

struct ExtraPortalRefData
{
    void* __thiscall FUN_00420380(unsigned int flags);
    void __thiscall FUN_004203b0();
};

void __cdecl _Deallocate(void*);

// Calls FUN_004203b0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00420380
void* ExtraPortalRefData::FUN_00420380(unsigned int flags)
{
    FUN_004203b0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct PointerFlagNode
{
    void* m_ppVirtualMethodTable;
    unsigned char m_ucExtraDataType;
    unsigned char layoutPadding5;
    unsigned short layoutPadding6;
    PointerFlagNode* pNext;
};

struct ExtraRoomRefData : BSExtraData
{
    PointerFlagNode* pData;  // +0xc
};

struct FUN_004207e0Class : BaseExtraList
{
    PointerFlagNode* FUN_004207e0();
};

// Returns the pData pointer stored in the ExtraRoomRefData extra (type 0x7b), or null if that extra is absent.
// @fnv 0x004207e0
PointerFlagNode* FUN_004207e0Class::FUN_004207e0()
{
    ExtraRoomRefData* pextra = (ExtraRoomRefData*)GetExtraData(0x7b);
    if (pextra)
        return pextra->pData;
    else
        return 0;
}

struct FUN_004211a0_StandIn : BaseExtraList
{
    int FUN_004211a0();
};

// Looks up extra data of type 0x72 and returns the int stored at offset 0xc, or 0 if absent.
// @fnv 0x004211a0
int FUN_004211a0_StandIn::FUN_004211a0()
{
    BSExtraData* extra = GetExtraData(0x72);
    if (extra)
        return *(int*)((char*)extra + 0xc);
    else
        return 0;
}

namespace fnv_00421280 {
struct BE
{
    BE(unsigned char);
};

struct FUN_00421280 : BE
{
    void* m_ppVirtualMethodTable;
    void* m_uiStandInValue;
    void* m_iValueAfterStandIn;
    void* m_ptr;
    FUN_00421280(void* aPtr);
};

extern int DAT_010151fc;

// Initializes the base with 0x70, stores a pointer to DAT_010151fc and the given pointer.
// @fnv 0x00421280
FUN_00421280::FUN_00421280(void* aPtr) : BE(0x70)
{
    m_ppVirtualMethodTable = &DAT_010151fc;
    m_ptr = aPtr;
}
}  // namespace fnv_00421280

struct ExtraLeveledCreature
{
    BSExtraData base;
    void* layoutPadding0C;
    void* pTemplate;  // +0x10
};

struct FUN_00421720 : BaseExtraList
{
    BSExtraData* GetFirstExtraData();
};

// Looks up the extra data of type 0x2e in this list and returns its pTemplate pointer, or null if absent.
// @fnv 0x00421720
BSExtraData* FUN_00421720::GetFirstExtraData()
{
    ExtraLeveledCreature* pextra = (ExtraLeveledCreature*)this->GetExtraData(0x2e);
    if (pextra)
        return (BSExtraData*)pextra->pTemplate;
    return 0;
}

struct FUN_00422670_Cls : BaseExtraList
{
    void RemoveExtra045();
};

// @fnv 0x00422670
void FUN_00422670_Cls::RemoveExtra045()
{
    RemoveExtra(0x45);
}

namespace fnv_0042c860 {
struct BE
{
    BE(unsigned char);
};

struct FUN_0042c860 : BE
{
    int* m_00;
    int m_04;
    int m_08;
    int m_0c;
    FUN_0042c860();
};

extern int DAT_01015944;

// Initializes the base with tag 0x1a, points m_00 at DAT_01015944, and sets m_0c to 0.
// @fnv 0x0042c860
FUN_0042c860::FUN_0042c860() : BE(0x1a)
{
    m_00 = &DAT_01015944;
    m_0c = 0;
}
}  // namespace fnv_0042c860

struct ExtraHeadingTarget
{
    virtual ~ExtraHeadingTarget();
    void __thiscall FUN_00435ef0();
    void* __thiscall FUN_0042c960(unsigned int flags);
};

void __cdecl _Deallocate(void*);

// @fnv 0x0042c960
void* __thiscall ExtraHeadingTarget::FUN_0042c960(unsigned int flags)
{
    FUN_00435ef0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_0042cb00 {
extern "C" void __cdecl _Deallocate(void*);

struct ExtraActorCause
{
    void FUN_0042cb30();
    void* FUN_0042cb00(unsigned int flags);
};

// Calls FUN_0042cb30, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0042cb00
void* ExtraActorCause::FUN_0042cb00(unsigned int flags)
{
    FUN_0042cb30();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_0042cb00

struct FUN_0042dd70_struct
{
    char data[0x10];
    void CopyByteWithinData();
};

// @fnv 0x0042dd70
void __thiscall FUN_0042dd70_struct::CopyByteWithinData()
{
    data[0x0C] = data[0x0D];
}

struct FUN_0042ed30Class : BaseExtraList
{
    int __thiscall FUN_0042ed30();
};

// Looks up extra data of type 0x75 and returns the int stored at offset 0x10, or 0 if absent.
// @fnv 0x0042ed30
int __thiscall FUN_0042ed30Class::FUN_0042ed30()
{
    int result2 = 0;
    BSExtraData* extra = GetExtraData(0x75);
    if (extra)
        result2 = *(int*)((char*)extra + 0x10);
    return result2;
}

struct FUN_0042eef0_class : BaseExtraList
{
    int __thiscall FUN_0042eef0();
};

// Looks up extra data of type 0x75 and returns the int at offset 0x14, or 0 if absent.
// @fnv 0x0042eef0
int __thiscall FUN_0042eef0_class::FUN_0042eef0()
{
    BSExtraData* extra = GetExtraData(0x75);
    if (extra)
        return *(int*)((char*)extra + 0x14);
    return 0;
}

struct WaterZone;

struct DummyPointerMap
{
    bool GetAt(unsigned int, unsigned int&) const;
};

struct ExtraWaterZoneMap
{
    BSExtraData m_base;
    DummyPointerMap m_map;
};

class FUN_0042f130 : public BaseExtraList
{
  public:
    bool SetWaterZone(WaterZone* apZone);
};

// Looks up the extra data of type 0x7e and returns whether the map contains a nonzero count for apZone.
// @fnv 0x0042f130
bool FUN_0042f130::SetWaterZone(WaterZone* apZone)
{
    ExtraWaterZoneMap* pextra = (ExtraWaterZoneMap*)this->GetExtraData(0x7e);
    if (pextra == 0)
        return false;
    int icount = 0;
    pextra->m_map.GetAt((unsigned int)apZone, (unsigned int&)icount);
    return icount > 0;
}

namespace fnv_004103b0 {
extern void* kVtbl_ExtraDataList[];
struct FUN_0040f780_struct
{
    void FUN_0040f7b0();
};
struct FUN_004103b0_class
{
    ~FUN_004103b0_class();
};
// @fnv 0x004103b0
FUN_004103b0_class::~FUN_004103b0_class()
{
    *reinterpret_cast<void**>(this) = kVtbl_ExtraDataList;
    reinterpret_cast<FUN_0040f780_struct*>(this)->FUN_0040f7b0();
}
}  // namespace fnv_004103b0

struct ExtraOriginalReference : public BSExtraData
{
    void* m_pWorldReferenceInfo;
};

struct FUN_00418630_Class : public BaseExtraList
{
    void* FUN_00418630();
};

// Returns the stored pointer from the ExtraOriginalReference extra data (type 0x20), or null if it is absent.
// @fnv 0x00418630
void* FUN_00418630_Class::FUN_00418630()
{
    ExtraOriginalReference* extra = (ExtraOriginalReference*)GetExtraData(0x20);
    if (extra)
        return extra->m_pWorldReferenceInfo;
    return 0;
}

struct FUN_00418b40_Class
{
    char FUN_00418b40();
};
// Looks up extra data of type 0x31 on this list and returns byte 0xc of it, or -1 if absent.
// @fnv 0x00418b40
char FUN_00418b40_Class::FUN_00418b40()
{
    BSExtraData* extra = ((BaseExtraList*)this)->GetExtraData(0x31);
    if (!extra)
        return -1;
    return ((char*)extra)[0xc];
}

struct FUN_00418be0_Class
{
    int FUN_00418be0() const;
};

// @fnv 0x00418be0
int FUN_00418be0_Class::FUN_00418be0() const
{
    return (reinterpret_cast<const unsigned char*>(this)[0xc]) != 0;
}

namespace fnv_0041a220 {
struct Flt
{
    unsigned int m_val;
    operator unsigned int() const
    {
        return m_val;
    }
    bool IsNotEqual(const Flt& a);
};

// Returns true when the passed Flt's value differs from this object's value.
// @fnv 0x0041a220
bool __thiscall Flt::IsNotEqual(const Flt& aOther)
{
    return (unsigned int)aOther != (unsigned int)*this;
}
}  // namespace fnv_0041a220

struct FUN_0041adf0_shell : public BaseExtraList
{
    void RemoveExtra(unsigned char);
    void FUN_0041adf0();
};

// @fnv 0x0041adf0
void FUN_0041adf0_shell::FUN_0041adf0()
{
    RemoveExtra(0x10);
}

struct FUN_0041ae10_shell : BaseExtraList
{
    void RemoveExtra(unsigned char);
    void FUN_0041ae10();
};

// @fnv 0x0041ae10
void FUN_0041ae10_shell::FUN_0041ae10()
{
    RemoveExtra(0x2d);
}

struct FUN_0042dec0_shell : BaseExtraList
{
    void RemoveExtra(unsigned char type);
    void RemoveExtraType43();
};

// @fnv 0x0041ae90
void FUN_0042dec0_shell::RemoveExtraType43()
{
    RemoveExtra(0x2b);
}

struct FUN_0041aed0_shell : public BaseExtraList
{
    void RemoveExtra(unsigned char);
    void FUN_0041aed0();
};
// @fnv 0x0041aed0
void FUN_0041aed0_shell::FUN_0041aed0()
{
    RemoveExtra(0x21);
}

namespace fnv_0041afa0 {
struct ExtraScript : BSExtraData
{
    void* m_pLocals;
};

struct FUN_0041afa0_Class : BaseExtraList
{
    void FUN_0041afa0();
};

// Retrieves the ExtraScript extra data (type 0xd) from the list and, if present, clears the pointer at offset 0x10.
// @fnv 0x0041afa0
void FUN_0041afa0_Class::FUN_0041afa0()
{
    ExtraScript* extra = (ExtraScript*)GetExtraData(0xd);
    if (extra)
        *(void**)((char*)extra + 0x10) = 0;
}
}  // namespace fnv_0041afa0

struct FUN_0041afd0_shell : public BaseExtraList
{
    void RemoveExtra(unsigned char type);
    void RemoveExtraData30();
};

// @fnv 0x0041afd0
void FUN_0041afd0_shell::RemoveExtraData30()
{
    RemoveExtra(0x30);
}

struct FUN_0041aff0_shell : BaseExtraList
{
    void RemoveExtra(unsigned char);
    void RemoveExtra0x1F();
};

// @fnv 0x0041aff0
void FUN_0041aff0_shell::RemoveExtra0x1F()
{
    RemoveExtra(0x1f);
}

struct FUN_0041b060_shell : public BaseExtraList
{
    void RemoveExtra(unsigned char type);
    void RemoveExtraType0x18();
};

// @fnv 0x0041b060
void FUN_0041b060_shell::RemoveExtraType0x18()
{
    RemoveExtra(0x18);
}

struct FUN_0041b350_shell : BaseExtraList
{
    void RemoveExtra(unsigned char type);
    void RemoveExtraType73();
};

// @fnv 0x0041b350
void FUN_0041b350_shell::RemoveExtraType73()
{
    RemoveExtra(0x49);
}

namespace fnv_0041b650 {
struct BE
{
    BE(unsigned char);
};

extern "C" void* DAT_01015178;

struct FUN_0041b650 : BE
{
    int pad0;
    int pad1;
    int pad2;
    float fPerc;
    FUN_0041b650();
};

// Initialises the base with 0x7a, installs the vtable pointer DAT_01015178 and sets fPerc to 0.0f.
// @fnv 0x0041b650
FUN_0041b650::FUN_0041b650() : BE(0x7a)
{
    *reinterpret_cast<void**>(this) = &DAT_01015178;
    fPerc = 0.0f;
}
}  // namespace fnv_0041b650

struct FUN_0041bce0_class
{
    unsigned int FUN_0041bce0();
};

// Looks up extra data of type 4 on the list and returns the unsigned int stored at offset 0xC, or 0 if absent.
// @fnv 0x0041bce0
unsigned int FUN_0041bce0_class::FUN_0041bce0()
{
    BSExtraData* extra = ((BaseExtraList*)this)->GetExtraData(4);
    if (!extra)
        return 0;
    return *(unsigned int*)((char*)extra + 0xC);
}

struct FUN_0041bde0_Class : BaseExtraList
{
    unsigned int FUN_0041bde0();
};

// Looks up extra data of type 7 and returns the unsigned int stored at offset 0xc, or 0 if absent.
// @fnv 0x0041bde0
unsigned int FUN_0041bde0_Class::FUN_0041bde0()
{
    BSExtraData* extra = GetExtraData(7);
    if (!extra)
        return 0;
    return *(unsigned int*)((char*)extra + 0xc);
}

namespace fnv_0041bef0 {
struct BE
{
    BE(unsigned char);
};

struct FUN_0041bef0 : BE
{
    FUN_0041bef0();
};

extern "C" void* DAT_01015190;

// @fnv 0x0041bef0
FUN_0041bef0::FUN_0041bef0() : BE(0x50)
{
    *(void**)this = &DAT_01015190;
    *(unsigned char*)(this + 0xc) = 0;
    *(unsigned char*)(this + 0xd) = 0xff;
}
}  // namespace fnv_0041bef0

struct ExtraTerminalState : BSExtraData
{
    unsigned char pProcessData;
};

struct FUN_0041bf50_class : BaseExtraList
{
    unsigned char FUN_0041bf50();
};

// Returns the pProcessData byte from an ExtraTerminalState extra data block, or 0 if the extra data is not present.
// @fnv 0x0041bf50
unsigned char FUN_0041bf50_class::FUN_0041bf50()
{
    ExtraTerminalState* pextra = (ExtraTerminalState*)GetExtraData(0x50);
    if (!pextra)
        return 0;
    return pextra->pProcessData;
}

struct FUN_0041c360_class
{
    unsigned int FUN_0041c360();
};

// Looks up extra data of type 0x59 on this list and returns its fourth dword, or 0 if absent.
// @fnv 0x0041c360
unsigned int FUN_0041c360_class::FUN_0041c360()
{
    BSExtraData* extra = reinterpret_cast<BaseExtraList*>(this)->GetExtraData(0x59);
    if (!extra)
        return 0;
    return reinterpret_cast<unsigned int*>(extra)[3];
}

struct FUN_0041cab0
{
    void ProcessInteger(int arg);
};
// Gets the extra data entry with type 0x19 and, if present, writes arg into its field at offset 0x14.
// @fnv 0x0041cab0
void FUN_0041cab0::ProcessInteger(int aiValue)
{
    BSExtraData* extra = ((BaseExtraList*)this)->GetExtraData(0x19);
    if (extra)
        *(int*)((char*)extra + 0x14) = aiValue;
}

struct FUN_0041cbd0_class : public BaseExtraList
{
    void SetExtraDataFlag(bool abFlag);
};

// Retrieves the extra data entry with type 0x19 and writes abFlag into its byte at offset 0x18 if present.
// @fnv 0x0041cbd0
void FUN_0041cbd0_class::SetExtraDataFlag(bool abFlag)
{
    BSExtraData* extra = GetExtraData(0x19);
    if (extra)
        ((unsigned char*)extra)[0x18] = abFlag;
}

struct FUN_0041d330_Class : BaseExtraList
{
    void SetExtraDataByte(unsigned char value);
};

// Looks up the extra data entry with type 0x2f and, if present, writes value into its byte at offset 0x10.
// @fnv 0x0041d330
void FUN_0041d330_Class::SetExtraDataByte(unsigned char value)
{
    BSExtraData* extra = GetExtraData(0x2f);
    if (extra)
        ((unsigned char*)extra)[0x10] = value;
}

struct FUN_0041db30_class
{
    bool IsFlagSet();
};

// @fnv 0x0041db30
bool FUN_0041db30_class::IsFlagSet()
{
    return (reinterpret_cast<const unsigned char*>(this)[0x10] & 1) ? true : false;
}

struct FUN_0041dca0_class : public BaseExtraList
{
    char* FUN_0041dca0();
};

// Looks up extra data of type 0x38 and returns a pointer to its value at offset 0xc, or null if absent.
// @fnv 0x0041dca0
char* FUN_0041dca0_class::FUN_0041dca0()
{
    BSExtraData* extra = GetExtraData(0x38);
    if (extra)
        return (char*)extra + 0xc;
    return 0;
}

struct FUN_0041e660_class
{
    BSExtraData* GetExtraData(unsigned char type);
    int FUN_0041e660();
};

// Retrieves the extra data of type 0x6c and returns the int at offset 0xc, or 0 if absent.
// @fnv 0x0041e660
int FUN_0041e660_class::FUN_0041e660()
{
    BSExtraData* extra = GetExtraData(0x6c);
    if (extra)
        return *(int*)((char*)extra + 0xc);
    return 0;
}

namespace fnv_0041e750 {
extern "C" void* DAT_010151a8;

struct BE
{
    void* vtbl;
    int a;
    int b;
    int c;
    BE(unsigned char x);
};

struct FUN_0041e750 : BE
{
    FUN_0041e750();
};

// Constructs the object with BE(0x6c), sets its vtbl to DAT_010151a8 and clears field c.
// @fnv 0x0041e750
FUN_0041e750::FUN_0041e750() : BE(0x6c)
{
    vtbl = &DAT_010151a8;
    c = 0;
}
}  // namespace fnv_0041e750

namespace fnv_004202d0 {
extern int DAT_010151d8;
struct BE
{
    BE(unsigned char);
};
struct FUN_004202d0 : BE
{
    FUN_004202d0();
};
// @fnv 0x004202d0
FUN_004202d0::FUN_004202d0() : BE(0x77)
{
    *reinterpret_cast<int**>(this) = &DAT_010151d8;
}
}  // namespace fnv_004202d0

namespace fnv_00420500 {
extern "C" void* DAT_010151e4;

struct BE
{
    BE(unsigned char);
};

struct FUN_00420500 : BE
{
    FUN_00420500();
};

// @fnv 0x00420500
FUN_00420500::FUN_00420500() : BE(0x7b)
{
    *(void**)this = &DAT_010151e4;
}
}  // namespace fnv_00420500

namespace fnv_00421400 {
struct ExtraMerchantContainer : public BSExtraData
{
    void* pContainer;
};

struct FUN_00421400 : BaseExtraList
{
    void* GetMerchantContainer();
};

// Returns the container pointer stored in the ExtraMerchantContainer extra data (type 0x3c), or null if absent.
// @fnv 0x00421400
void* FUN_00421400::GetMerchantContainer()
{
    ExtraMerchantContainer* extra = (ExtraMerchantContainer*)GetExtraData(0x3c);
    if (extra)
        return extra->pContainer;
    return 0;
}
}  // namespace fnv_00421400

struct FUN_00421a40_class : BaseExtraList
{
    float GetExtraFloatValue();
};

// Looks up extra data of type 0x43 and returns the float stored at offset 0xC, or 0.0f if absent.
// @fnv 0x00421a40
float FUN_00421a40_class::GetExtraFloatValue()
{
    BSExtraData* extra = GetExtraData(0x43);
    if (extra)
        return *(float*)((char*)extra + 0xC);
    return 0.0f;
}

struct FUN_00422720_shell : BaseExtraList
{
    void RemoveExtra(unsigned char type);
    void FUN_00422720();
};

// Looks up extra data of type 0x1d and removes it from the list if present.
// @fnv 0x00422720
void FUN_00422720_shell::FUN_00422720()
{
    BSExtraData* extra = GetExtraData(0x1d);
    if (extra)
        RemoveExtra(0x1d);
}

struct FUN_004228f0_Class : BaseExtraList
{
    char* FUN_004228f0();
};

// Looks up extra data of type 0x41 and returns the char pointer stored at offset 0xc, or null if absent.
// @fnv 0x004228f0
char* FUN_004228f0_Class::FUN_004228f0()
{
    BSExtraData* extra = GetExtraData(0x41);
    if (extra)
        return *(char**)((char*)extra + 0xc);
    return 0;
}

namespace fnv_00422c20 {
struct FUN_0042dec0_shell : BaseExtraList
{
    void RemoveExtra(unsigned char);
};

void FUN_0042dec0_shell::RemoveExtra(unsigned char)
{}

struct FUN_00422c20_shell : FUN_0042dec0_shell
{
    void FUN_00422c20();
};

// @fnv 0x00422c20
void FUN_00422c20_shell::FUN_00422c20()
{
    RemoveExtra(0x3d);
}
}  // namespace fnv_00422c20

namespace fnv_0042c610 {
extern "C"
{
    struct BE
    {
        void* vft;
        int a;
        int b;
        int c;
        int d;
        int e;
        int f;
        int g;
        int h;
        int i;
        int j;
        int k;
        int l;
        int m;
        int n;
        int o;
        int p;
        int q;
        int r;
        int s;
        int t;
        int u;
        int v;
        int w;
        int x;
        int y;
        int z;
        BE(unsigned char);
    };
}
extern void* DAT_010158c0;
struct FUN_0042c610 : public BE
{
    int f0;
    int f1;
    int f2;
    int f3;
    FUN_0042c610();
};
// Initializes the BE base with tag 0x22, sets the vtable to DAT_010158c0 and clears field c.
// @fnv 0x0042c610
FUN_0042c610::FUN_0042c610() : BE(0x22)
{
    vft = &DAT_010158c0;
    c = 0;
}
}  // namespace fnv_0042c610

namespace fnv_0042c6a0 {
extern int DAT_010158e4;
struct BE
{
    BE(unsigned char);
};
struct FUN_0042c6a0 : BE
{
    FUN_0042c6a0();
    int m_uiStandInValue;
    int m_iValueAfterStandIn;
    int m_pAuxiliaryObject;
    float fHealthPercent;
};
// Initialises the object: sets its vtable pointer to DAT_010158e4 and clears the float field to 0.0f.
// @fnv 0x0042c6a0
FUN_0042c6a0::FUN_0042c6a0() : BE(0x25)
{
    *reinterpret_cast<int**>(this) = &DAT_010158e4;
    fHealthPercent = 0.0f;
}
}  // namespace fnv_0042c6a0

namespace fnv_0042c730 {
struct BE
{
    BE(unsigned char);
};

extern const void* DAT_01015908;

struct FUN_0042c730 : BE
{
    int m_auiShapeKeys;
    int m_pAuxiliaryObject;
    int m_pad3;
    float m_f;
    FUN_0042c730();
};

// Initialises the object: sets its vtable pointer to DAT_01015908 and sets m_f to 0.0f.
// @fnv 0x0042c730
FUN_0042c730::FUN_0042c730() : BE(0x28)
{
    *reinterpret_cast<const void**>(this) = &DAT_01015908;
    m_f = 0.0f;
}
}  // namespace fnv_0042c730

namespace fnv_0042c830 {
extern int DAT_01015938;
struct BE
{
    BE(unsigned char);
    BE()
    {}
};
struct FUN_0042c830 : BE
{
    int m_p;
    FUN_0042c830();
};
// Initializes the object: sets the vtable pointer at offset 0 and clears the int at offset 0xc.
// @fnv 0x0042c830
FUN_0042c830::FUN_0042c830() : BE(0x1c)
{
    *(int**)((char*)this + 0) = &DAT_01015938;
    *(int*)((char*)this + 0xc) = 0;
}
}  // namespace fnv_0042c830

namespace fnv_0042c930 {
struct BE
{
    void* vt;
    int a;
    int b;
    int c;
    int d;
    BE(unsigned char);
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
};

struct FUN_0042c930 : public BE
{
    FUN_0042c930();
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
};

// Constructs the object with base value 0x46 and sets field b to 0.
// @fnv 0x0042c930
FUN_0042c930::FUN_0042c930() : BE(0x46)
{
    b = 0;
}
}  // namespace fnv_0042c930

namespace fnv_0042c990 {
extern "C" int DAT_01015974;

class BE
{
  public:
    BE(unsigned char);
};

struct FUN_0042c990 : public BE
{
    int* m_p;
    unsigned char m_kPointB;
    char _pad[3];
    unsigned char m_b2;
    char _pad2[3];
    unsigned char m_b3;
    FUN_0042c990();
};

// Initializes the base with 0x4e, points m_p at DAT_01015974 and clears m_b3.
// @fnv 0x0042c990
FUN_0042c990::FUN_0042c990() : BE(0x4e)
{
    m_p = &DAT_01015974;
    m_b3 = 0;
}
}  // namespace fnv_0042c990

namespace fnv_0042e280 {
struct FUN_0042dec0_shell : BaseExtraList
{
    void RemoveExtra(unsigned char);
    void RemoveExtra5B();
};

// @fnv 0x0042e280
void FUN_0042dec0_shell::RemoveExtra5B()
{
    RemoveExtra(0x5b);
}
}  // namespace fnv_0042e280

struct TESCombatStyle;
struct ExtraCombatStyle : BSExtraData
{
    TESCombatStyle* m_pCombatStyle;
};

struct FUN_0042ea20_Class : BaseExtraList
{
    TESCombatStyle* FUN_0042ea20();
};

// Retrieves the ExtraCombatStyle extra data (type 0x69) from the list and returns its combat style pointer, or null if absent.
// @fnv 0x0042ea20
TESCombatStyle* FUN_0042ea20_Class::FUN_0042ea20()
{
    ExtraCombatStyle* extra = (ExtraCombatStyle*)GetExtraData(0x69);
    if (extra)
        return extra->m_pCombatStyle;
    return 0;
}

struct FUN_0042eec0_Class : BaseExtraList
{
    void FUN_0042eec0(int param_1);
};

// Looks up extra data of type 0x75 and, if present, stores param_1 at offset 0x14.
// @fnv 0x0042eec0
void FUN_0042eec0_Class::FUN_0042eec0(int param_1)
{
    BSExtraData* extra = GetExtraData(0x75);
    if (extra)
    {
        *(int*)((char*)extra + 0x14) = param_1;
    }
}

namespace fnv_00410380 {
extern "C" void __cdecl _Deallocate(void*);

struct FUN_00410380_class
{
    void FUN_004103b0();
    void* FUN_00410380(unsigned int flags);
};

// Calls FUN_004103b0, frees this via _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00410380
void* FUN_00410380_class::FUN_00410380(unsigned int flags)
{
    FUN_004103b0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_00410380

namespace fnv_00411cf0 {
extern "C" void __cdecl _Deallocate(void*);

struct FUN_00411cf0_class
{
    void __thiscall FUN_00434950();
    void* __thiscall FUN_00411cf0(unsigned int flags);
};

// Calls FUN_00434950, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00411cf0
void* __thiscall FUN_00411cf0_class::FUN_00411cf0(unsigned int flags)
{
    FUN_00434950();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_00411cf0

namespace fnv_00418d20 {
extern "C" void __cdecl _Deallocate(void*);
struct FUN_00418d20_class
{
    void __thiscall FUN_0048fb50();
    void* __thiscall FUN_00418d20(unsigned int flags);
};
// Calls FUN_0048fb50, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00418d20
void* __thiscall FUN_00418d20_class::FUN_00418d20(unsigned int flags)
{
    FUN_0048fb50();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_00418d20

namespace fnv_00418e00 {
extern "C" void __cdecl _Deallocate(void*);
struct FUN_004aae50_shell
{
    void FUN_004aae50();
    void* FUN_00418e00(unsigned int flags);
};
// Calls FUN_004aae50, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00418e00
void* FUN_004aae50_shell::FUN_00418e00(unsigned int flags)
{
    FUN_004aae50();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_00418e00

namespace fnv_00419480 {
struct FUN_00419480_Class
{
    void FUN_00589500();
    void* FUN_00419480(unsigned int flags);
};

extern "C" void __cdecl _Deallocate(void*);

// Calls FUN_00589500, then deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x00419480
void* FUN_00419480_Class::FUN_00419480(unsigned int flags)
{
    FUN_00589500();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_00419480

namespace fnv_0041b790 {
extern "C" void* _DAT_01015184;

struct BE
{
    BE(unsigned char);
};

struct FUN_0041b790 : BE
{
    void* vfn;
    unsigned char pad[8];
    float f;
    FUN_0041b790(float value);
};

// @fnv 0x0041b790
FUN_0041b790::FUN_0041b790(float value) : BE(0x56)
{
    vfn = &_DAT_01015184;
    f = value;
}
}  // namespace fnv_0041b790

namespace fnv_0042c640 {
extern int DAT_010158cc;

struct BE
{
    BE(unsigned char);
};

struct FUN_0042c640 : BE
{
    FUN_0042c640();
};

// @fnv 0x0042c640
FUN_0042c640::FUN_0042c640() : BE(0x23)
{
    *(int**)(this) = &DAT_010158cc;
    *(int*)((char*)this + 0xc) = 0;
}
}  // namespace fnv_0042c640

void __cdecl _Deallocate(void*);
struct ExtraReflectedRefs
{
    void FUN_00434560();
    void* FUN_00411bb0(unsigned int);
};
// Calls FUN_00434560, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00411bb0
void* ExtraReflectedRefs::FUN_00411bb0(unsigned int flags)
{
    FUN_00434560();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct ReferenceLightData
{
};
struct ExtraLight : BSExtraData
{
    ReferenceLightData* apTargetLight;
};
struct Holder
{
    ReferenceLightData* FUN_00418250();
};
// Looks up extra data of type 0x29 and returns its stored pointer, or null if absent.
// @fnv 0x00418250
ReferenceLightData* Holder::FUN_00418250()
{
    ExtraLight* pExtra = (ExtraLight*)((BaseExtraList*)this)->GetExtraData(0x29);
    if (pExtra)
        return pExtra->apTargetLight;
    return 0;
}

struct FUN_00418860_Holder : BaseExtraList
{
    float FUN_00418860();
};
// Returns the float at offset 0xC of the extra data with type 0x30, or 1.0f if none exists.
// @fnv 0x00418860
float FUN_00418860_Holder::FUN_00418860()
{
    BSExtraData* extra = GetExtraData(0x30);
    if (extra)
        return *(float*)((char*)extra + 0xC);
    else
        return 1.0f;
}

namespace fnv_0041a090 {
struct NiAVObject;
struct SoundPlaybackHandle
{
    void Clear();
    bool Play(bool);
    bool SchedulePlayback(unsigned int, int);
    bool Pause();
    bool Stop();
    bool IsPlaying();
    bool IsValid();
    int GetSoundType();
    float GetVolume();
    bool SetVolume(float);
    bool SetFrequency(float);
    bool SetPlaybackFrequency(float);
    bool SetFrequencyVariance(unsigned char);
    bool SetBalance(int);
    bool SetStaticAttenuation(unsigned short);
    int GetDuration();
    bool SetPosition(void*);
    bool SetPosition(float, float, float);
    bool SetBeamEnd(void*);
    bool SetBeamEnd(float, float, float);
    void SetDistanceRange(float, float);
    void SetSoundParameters(unsigned short, unsigned short, unsigned short, unsigned short, unsigned short);
    void SetReverbAttenuation(unsigned short);
    bool SetBeamStart(float, float, float);
    unsigned int GetID();
    void SetObjectToFollow(NiAVObject*);
    void Seek(unsigned int);
    void SetFollowsListener(bool);
    void SetCompletionCallback(int*, void*);
    void SetPlayCallback(int*, void*);
    static void SetAddMovingSoundCallback(int*);
    bool Release();
    bool SetFadeInTime(unsigned int);
    bool StopWithFade(unsigned int);
    bool SetPlaybackTime(unsigned int);
    void SetTimeConstraints(unsigned char, unsigned char);
    void SetSynchStartTime(unsigned int);
    void IsSoundPlaying();
    void SetPriority(unsigned int);
    void SetAssumeSuccess(bool);
    int QState();
    void* __vecDelDtor(unsigned int);
    unsigned int m_uiSoundResourceID;
    bool m_bLooping;
    char _pad_5[3];
    int eState;
};
typedef char _sizecheck_BSSoundHandle[sizeof(SoundPlaybackHandle) == 12 ? 1 : -1];
struct FUN_0041a090_shell : public ExtraDataList
{
    void FUN_0041a090(void*);
};

struct BSSoundHandleEx : SoundPlaybackHandle
{
    BSSoundHandleEx();
    BSSoundHandleEx(const BSSoundHandleEx&);
    ~BSSoundHandleEx();
};
struct SH_00418890
{
    void FUN_copy(const void*);
};
struct FUN_0041a1f0Class
{
    bool Equals(const BSSoundHandleEx&);
};
struct FUN_0041a220_t
{
    bool IsNotEqual(const BSSoundHandleEx&);
};
struct ExtraListRemover
{
    void FUN_00410020(BSExtraData*, bool);
};
struct FUN_004361e0 : BSExtraData
{
    char data[0xc];
    FUN_004361e0(BSSoundHandleEx);
};

// @fnv 0x0041a090
void FUN_0041a090_shell::FUN_0041a090(void* afSound)
{
    BSExtraData* SoundAssetTmp = GetExtraData(0x7d);
    if (SoundAssetTmp)
    {
        if (((FUN_0041a1f0Class*)afSound)->Equals(BSSoundHandleEx()))
            ((ExtraListRemover*)this)->FUN_00410020(SoundAssetTmp, true);
        else
            ((SH_00418890*)((char*)SoundAssetTmp + 0xc))->FUN_copy(afSound);
    }
    else
    {
        if (((FUN_0041a220_t*)afSound)->IsNotEqual(BSSoundHandleEx()))
        {
            SoundAssetTmp = new FUN_004361e0(*(const BSSoundHandleEx*)afSound);
            AddExtra(SoundAssetTmp);
        }
    }
}
}  // namespace fnv_0041a090

namespace fnv_0041a3e0 {
struct NiAVObject;
struct SoundPlaybackHandle
{
    void Clear();
    bool Play(bool);
    bool SchedulePlayback(unsigned int, int);
    bool Pause();
    bool Stop();
    bool IsPlaying();
    bool IsValid();
    int GetSoundType();
    float GetVolume();
    bool SetVolume(float);
    bool SetFrequency(float);
    bool SetPlaybackFrequency(float);
    bool SetFrequencyVariance(unsigned char);
    bool SetBalance(int);
    bool SetStaticAttenuation(unsigned short);
    int GetDuration();
    bool SetPosition(void*);
    bool SetPosition(float, float, float);
    bool SetBeamEnd(void*);
    bool SetBeamEnd(float, float, float);
    void SetDistanceRange(float, float);
    void SetSoundParameters(unsigned short, unsigned short, unsigned short, unsigned short, unsigned short);
    void SetReverbAttenuation(unsigned short);
    bool SetBeamStart(float, float, float);
    unsigned int GetID();
    void SetObjectToFollow(NiAVObject*);
    void Seek(unsigned int);
    void SetFollowsListener(bool);
    void SetCompletionCallback(int*, void*);
    void SetPlayCallback(int*, void*);
    static void SetAddMovingSoundCallback(int*);
    bool Release();
    bool SetFadeInTime(unsigned int);
    bool StopWithFade(unsigned int);
    bool SetPlaybackTime(unsigned int);
    void SetTimeConstraints(unsigned char, unsigned char);
    void SetSynchStartTime(unsigned int);
    void IsSoundPlaying();
    void SetPriority(unsigned int);
    void SetAssumeSuccess(bool);
    int QState();
    void* __vecDelDtor(unsigned int);
    unsigned int m_uiSoundResourceID;
    bool m_bLooping;
    char _pad_5[3];
    int eState;
};
typedef char _sizecheck_BSSoundHandle[sizeof(SoundPlaybackHandle) == 12 ? 1 : -1];
struct FUN_0041a3e0_shell : public ExtraDataList
{
    void FUN_0041a3e0(void*);
};

struct GlobalObject_0041a250
{
    unsigned int m_uiSoundResourceID;
    bool m_bLooping;
    int eState;
    GlobalObject_0041a250();
    GlobalObject_0041a250(const GlobalObject_0041a250&);
    ~GlobalObject_0041a250();
};
struct FUN_0041a1f0Class
{
    bool Equals(const GlobalObject_0041a250&);
};
struct FUN_0041a220_s
{
    bool IsNotEqual(const GlobalObject_0041a250&);
};
struct ExtraListRemover
{
    void FUN_00410020(BSExtraData*, bool);
};
struct SH_00418890
{
    void FUN_copy(const void*);
};
struct FUN_00436420 : BSExtraData
{
    SoundPlaybackHandle kSound;
    FUN_00436420(GlobalObject_0041a250);
};

// @fnv 0x0041a3e0
void FUN_0041a3e0_shell::FUN_0041a3e0(void* afSound)
{
    FUN_00436420* SoundAssetTmp = (FUN_00436420*)GetExtraData(0x83);
    if (SoundAssetTmp)
    {
        if (((FUN_0041a1f0Class*)afSound)->Equals(GlobalObject_0041a250()))
            ((ExtraListRemover*)this)->FUN_00410020(SoundAssetTmp, true);
        else
            ((SH_00418890*)&SoundAssetTmp->kSound)->FUN_copy(afSound);
    }
    else if (((FUN_0041a220_s*)afSound)->IsNotEqual(GlobalObject_0041a250()))
    {
        SoundAssetTmp = new FUN_00436420(*(const GlobalObject_0041a250*)afSound);
        AddExtra(SoundAssetTmp);
    }
}
}  // namespace fnv_0041a3e0

namespace fnv_0041a540 {
struct NiAVObject;
struct SoundPlaybackHandle
{
    void Clear();
    bool Play(bool);
    bool SchedulePlayback(unsigned int, int);
    bool Pause();
    bool Stop();
    bool IsPlaying();
    bool IsValid();
    int GetSoundType();
    float GetVolume();
    bool SetVolume(float);
    bool SetFrequency(float);
    bool SetPlaybackFrequency(float);
    bool SetFrequencyVariance(unsigned char);
    bool SetBalance(int);
    bool SetStaticAttenuation(unsigned short);
    int GetDuration();
    bool SetPosition(void*);
    bool SetPosition(float, float, float);
    bool SetBeamEnd(void*);
    bool SetBeamEnd(float, float, float);
    void SetDistanceRange(float, float);
    void SetSoundParameters(unsigned short, unsigned short, unsigned short, unsigned short, unsigned short);
    void SetReverbAttenuation(unsigned short);
    bool SetBeamStart(float, float, float);
    unsigned int GetID();
    void SetObjectToFollow(NiAVObject*);
    void Seek(unsigned int);
    void SetFollowsListener(bool);
    void SetCompletionCallback(int*, void*);
    void SetPlayCallback(int*, void*);
    static void SetAddMovingSoundCallback(int*);
    bool Release();
    bool SetFadeInTime(unsigned int);
    bool StopWithFade(unsigned int);
    bool SetPlaybackTime(unsigned int);
    void SetTimeConstraints(unsigned char, unsigned char);
    void SetSynchStartTime(unsigned int);
    void IsSoundPlaying();
    void SetPriority(unsigned int);
    void SetAssumeSuccess(bool);
    int QState();
    void* __vecDelDtor(unsigned int);
    unsigned int m_uiSoundResourceID;
    bool m_bLooping;
    char _pad_5[3];
    int eState;
};
typedef char _sizecheck_BSSoundHandle[sizeof(SoundPlaybackHandle) == 12 ? 1 : -1];
struct FUN_0041a540_shell : public ExtraDataList
{
    void FUN_0041a540(void*);
};

struct FUN_00418900
{
    unsigned int m_uiSoundResourceID;
    bool m_bLooping;
    int eState;
    FUN_00418900(const FUN_00418900&);
    ~FUN_00418900();
    FUN_00418900& operator=(const FUN_00418900&);
};
struct BSSoundHandleEx
{
    unsigned int m_uiSoundResourceID;
    bool m_bLooping;
    int eState;
    BSSoundHandleEx();
    ~BSSoundHandleEx();
};
struct FUN_0041a1f0Class
{
    bool Equals(const BSSoundHandleEx&);
};
struct FUN_0041a220Class
{
    bool IsNotEqual(const BSSoundHandleEx&);
};
struct ExtraListRemover
{
    void FUN_00410020(BSExtraData*, bool);
};
struct FUN_00436540 : BSExtraData
{
    FUN_00418900 kSound;
    FUN_00436540(FUN_00418900);
};
// @fnv 0x0041a540
void FUN_0041a540_shell::FUN_0041a540(void* afSound)
{
    BSExtraData* SoundAssetTmp = GetExtraData(0x86);
    if (SoundAssetTmp)
    {
        if (((FUN_0041a1f0Class*)afSound)->Equals(BSSoundHandleEx()))
            ((ExtraListRemover*)this)->FUN_00410020(SoundAssetTmp, true);
        else
            ((FUN_00436540*)SoundAssetTmp)->kSound = *(const FUN_00418900*)afSound;
    }
    else
    {
        if (((FUN_0041a220Class*)afSound)->IsNotEqual(BSSoundHandleEx()))
        {
            SoundAssetTmp = new FUN_00436540(*(const FUN_00418900*)afSound);
            AddExtra(SoundAssetTmp);
        }
    }
}
}  // namespace fnv_0041a540

namespace fnv_0041a800 {
struct NiAVObject;
struct SoundPlaybackHandle
{
    void Clear();
    bool Play(bool);
    bool SchedulePlayback(unsigned int, int);
    bool Pause();
    bool Stop();
    bool IsPlaying();
    bool IsValid();
    int GetSoundType();
    float GetVolume();
    bool SetVolume(float);
    bool SetFrequency(float);
    bool SetPlaybackFrequency(float);
    bool SetFrequencyVariance(unsigned char);
    bool SetBalance(int);
    bool SetStaticAttenuation(unsigned short);
    int GetDuration();
    bool SetPosition(void*);
    bool SetPosition(float, float, float);
    bool SetBeamEnd(void*);
    bool SetBeamEnd(float, float, float);
    void SetDistanceRange(float, float);
    void SetSoundParameters(unsigned short, unsigned short, unsigned short, unsigned short, unsigned short);
    void SetReverbAttenuation(unsigned short);
    bool SetBeamStart(float, float, float);
    unsigned int GetID();
    void SetObjectToFollow(NiAVObject*);
    void Seek(unsigned int);
    void SetFollowsListener(bool);
    void SetCompletionCallback(int*, void*);
    void SetPlayCallback(int*, void*);
    static void SetAddMovingSoundCallback(int*);
    bool Release();
    bool SetFadeInTime(unsigned int);
    bool StopWithFade(unsigned int);
    bool SetPlaybackTime(unsigned int);
    void SetTimeConstraints(unsigned char, unsigned char);
    void SetSynchStartTime(unsigned int);
    void IsSoundPlaying();
    void SetPriority(unsigned int);
    void SetAssumeSuccess(bool);
    int QState();
    void* __vecDelDtor(unsigned int);
    unsigned int m_uiSoundResourceID;
    bool m_bLooping;
    char _pad_5[3];
    int eState;
};
typedef char _sizecheck_BSSoundHandle[sizeof(SoundPlaybackHandle) == 12 ? 1 : -1];
struct FUN_0041a800_shell : public ExtraDataList
{
    void FUN_0041a800(void*);
};

struct BSSoundHandleEx
{
    unsigned int m_uiSoundResourceID;
    bool m_bLooping;
    int eState;
    BSSoundHandleEx();
    BSSoundHandleEx(const BSSoundHandleEx&);
    BSSoundHandleEx& operator=(const BSSoundHandleEx&);
    ~BSSoundHandleEx();
};
struct FUN_004360c0 : BSExtraData
{
    BSSoundHandleEx xSound;
    FUN_004360c0(BSSoundHandleEx aSound);
};
struct FUN_0041a1f0Class
{
    bool Equals(const BSSoundHandleEx&);
};
struct S_0041a220
{
    bool IsNotEqual(const BSSoundHandleEx&);
};
struct S_00410020
{
    void FUN_00410020(BSExtraData*, bool);
};

// @fnv 0x0041a800
void FUN_0041a800_shell::FUN_0041a800(void* afSound)
{
    FUN_004360c0* SoundAssetTmp = (FUN_004360c0*)GetExtraData(0x4f);
    if (SoundAssetTmp)
    {
        if (((FUN_0041a1f0Class*)afSound)->Equals(BSSoundHandleEx()))
            ((S_00410020*)this)->FUN_00410020(SoundAssetTmp, true);
        else
            SoundAssetTmp->xSound = *(const BSSoundHandleEx*)afSound;
    }
    else
    {
        if (((S_0041a220*)afSound)->IsNotEqual(BSSoundHandleEx()))
        {
            SoundAssetTmp = new FUN_004360c0(*(const BSSoundHandleEx*)afSound);
            AddExtra(SoundAssetTmp);
        }
    }
}
}  // namespace fnv_0041a800

namespace fnv_0041c060 {
struct ExtraTerminalState : BSExtraData
{
    unsigned char padC;
    char m_cTerminalState;
};
struct MyThis : BaseExtraList
{
    char FUN_0041c060();
};
// @fnv 0x0041c060
char MyThis::FUN_0041c060()
{
    ExtraTerminalState* pextra;
    pextra = (ExtraTerminalState*)GetExtraData(0x50);
    if (pextra == 0)
        return -1;
    return pextra->m_cTerminalState;
}
}  // namespace fnv_0041c060

struct MyExtraDataList : BaseExtraList
{
    void FUN_0041cae0(int);
};
struct ExtraPackage
{
    BSExtraData base;
    int unk0C;
    int iElementIndex;
};
// @fnv 0x0041cae0
void MyExtraDataList::FUN_0041cae0(int aiIndex)
{
    ExtraPackage* pExtra = (ExtraPackage*)GetExtraData(0x19);
    if (pExtra)
        pExtra->iElementIndex = aiIndex;
}

struct FUN_0041dfd0_Shell
{
    void FUN_0041dfd0();
};
// Looks up extra data of type 0x3A on the list and removes it if present.
// @fnv 0x0041dfd0
void FUN_0041dfd0_Shell::FUN_0041dfd0()
{
    BSExtraData* data = ((BaseExtraList*)this)->GetExtraData(0x3A);
    if (data)
        ((BaseExtraList*)this)->RemoveExtra(0x3A);
}

namespace fnv_0041f140 {
struct ReflectedReferenceRecord;
struct FakeList
{
    int _x;
};
struct ExtraReflectedRefs : BSExtraData
{
    FakeList mList;
};
struct Holder : BaseExtraList
{
    FakeList* FUN_0041f140();
};
// Looks up the extra data of type 0x65 and returns a pointer to its list, or null if absent.
// @fnv 0x0041f140
FakeList* Holder::FUN_0041f140()
{
    ExtraReflectedRefs* pextra;
    pextra = (ExtraReflectedRefs*)GetExtraData(0x65);
    if (pextra)
        return &pextra->mList;
    return 0;
}
}  // namespace fnv_0041f140

struct S_FUN_0041f170
{
    void* FUN_0041f170();
};
// Looks up extra data of type 0x66 on the list and returns a pointer 12 bytes into it, or null if absent.
// @fnv 0x0041f170
void* S_FUN_0041f170::FUN_0041f170()
{
    BSExtraData* extra = ((BaseExtraList*)this)->GetExtraData(0x66);
    if (extra)
        return (void*)((char*)extra + 12);
    return 0;
}

namespace fnv_0041f4c0 {
struct RefCountItem
{
    TESObjectREFR* pRef;
    unsigned int iFlags;
};
struct RefCountList
{
    RefCountItem* pItem;
    RefCountList* pNext;
    RefCountItem** _ref_006815c0();
    RefCountList* GetNext();
    bool _ref_008256d0();
};
struct FUN_00411b40 : BSExtraData
{
    RefCountList kList;
    FUN_00411b40();
    void FUN_00434800(TESObjectREFR* pRef);
};
struct FUN_004348a0_shell
{
    void AddReflectedRef(TESObjectREFR* pRef, unsigned int count);
};
struct ExtraListRemover
{
    void _FUN_00410020(BSExtraData* pExtra, bool bDelete);
};
struct EDL_0041f4c0 : BaseExtraList
{
    void FUN_0041f4c0(TESObjectREFR* pRef, bool bSet);
};
// @fnv 0x0041f4c0
void EDL_0041f4c0::FUN_0041f4c0(TESObjectREFR* pRef, bool bSet)
{
    FUN_00411b40* pextra = (FUN_00411b40*)GetExtraData(0x65);
    if (pextra)
    {
        RefCountList* pList = &pextra->kList;
        while (pList && *pList->_ref_006815c0())
        {
            if ((*pList->_ref_006815c0())->pRef == pRef)
            {
                if (bSet)
                {
                    (*pList->_ref_006815c0())->iFlags |= 1;
                }
                else
                {
                    (*pList->_ref_006815c0())->iFlags &= ~1;
                    if ((*pList->_ref_006815c0())->iFlags == 0)
                    {
                        pextra->FUN_00434800(pRef);
                        if (pextra->kList._ref_008256d0())
                            ((ExtraListRemover*)this)->_FUN_00410020(pextra, true);
                    }
                }
                return;
            }
            pList = pList->GetNext();
        }
    }
    if (bSet)
    {
        if (!pextra)
        {
            pextra = new FUN_00411b40;
            AddExtra(pextra);
        }
        ((FUN_004348a0_shell*)pextra)->AddReflectedRef(pRef, 1);
    }
}
}  // namespace fnv_0041f4c0

namespace fnv_004207b0 {
struct PointerFlagNode;
struct FUN_004207e0Class
{
    PointerFlagNode* FUN_004207e0(void);
    PointerFlagNode* FUN_004207b0(void);
};
// Calls FUN_004207e0 and returns its result, or null when that result is null.
// @fnv 0x004207b0
PointerFlagNode* FUN_004207e0Class::FUN_004207b0(void)
{
    PointerFlagNode* result = FUN_004207e0();
    return result ? result : 0;
}
}  // namespace fnv_004207b0

namespace fnv_00421090 {
struct BE
{
    BE(unsigned char);
};
extern int DAT_010151f0;
struct FUN_00421090 : BE
{
    FUN_00421090();
};
// @fnv 0x00421090
FUN_00421090::FUN_00421090() : BE(0x72)
{
    *(void**)this = &DAT_010151f0;
}
}  // namespace fnv_00421090

struct ExtraSavedHavokData : BSExtraData
{
    char* m_pSavedHavokData;
};
struct S_00422b90
{
    char* FUN_00422b90();
};
// Retrieves the extra data of type 0x3D from the list and returns its stored pointer, or null if absent.
// @fnv 0x00422b90
char* S_00422b90::FUN_00422b90()
{
    ExtraSavedHavokData* pextra;
    pextra = (ExtraSavedHavokData*)((BaseExtraList*)this)->GetExtraData(0x3D);
    if (pextra)
        return pextra->m_pSavedHavokData;
    return 0;
}

namespace fnv_0042c580 {
struct BE
{
    virtual void Dummy();
    int _04;
    int _08;
    BE(unsigned char);
};
struct FUN_0042c580 : BE
{
    int m0c;
    FUN_0042c580();
};
// @fnv 0x0042c580
FUN_0042c580::FUN_0042c580() : BE(0x2b)
{
    m0c = 0;
}
}  // namespace fnv_0042c580

namespace fnv_0042c5e0 {
struct BE
{
    BE(unsigned char);
    virtual ~BE();
    int m08;
    int m0C;
};
struct FUN_0042c5e0 : BE
{
    void* f0C;
    FUN_0042c5e0();
    ~FUN_0042c5e0();
};
// @fnv 0x0042c5e0
FUN_0042c5e0::FUN_0042c5e0() : BE(0x21)
{
    f0C = 0;
}
}  // namespace fnv_0042c5e0

namespace fnv_0042c670 {
struct BE
{
    virtual void foo()
    {}
    BE(unsigned char);
    char _pad[8];
};
struct FUN_0042c670 : public BE
{
    short cnt;
    FUN_0042c670();
};
// @fnv 0x0042c670
FUN_0042c670::FUN_0042c670() : BE(0x24)
{
    cnt = 0;
}
}  // namespace fnv_0042c670

namespace fnv_0042c6d0 {
struct BE
{
    BE(unsigned char);
    int m04;
    int m08;
    int m0C_pad;
};
extern int DAT_010158f0;
struct FUN_0042c6d0 : BE
{
    unsigned char f0c;
    FUN_0042c6d0();
};
// Constructs the object with base value 0x26, sets its vtable pointer to DAT_010158f0 and clears f0c.
// @fnv 0x0042c6d0
FUN_0042c6d0::FUN_0042c6d0() : BE(0x26)
{
    *(int*)this = (int)&DAT_010158f0;
    f0c = 0;
}
}  // namespace fnv_0042c6d0

namespace fnv_0042c700 {
struct BE
{
    BE(unsigned char);
    int _04;
    int _08;
    int _0c;
};
extern int DAT_010158fc;
struct FUN_0042c700 : BE
{
    float _10;
    FUN_0042c700();
};
// @fnv 0x0042c700
FUN_0042c700::FUN_0042c700() : BE(0x27)
{
    *(int*)this = (int)&DAT_010158fc;
    _10 = 0.0f;
}
}  // namespace fnv_0042c700

namespace fnv_0042c7d0 {
struct BE
{
    void* _vtbl;
    int _004;
    int _008;
    BE(unsigned char);
};
extern int DAT_01015920;
struct FUN_0042c7d0 : BE
{
    float m00C;
    FUN_0042c7d0();
};
// Initializes the base with 0x30, sets the vtable to DAT_01015920 and zeroes m00C.
// @fnv 0x0042c7d0
FUN_0042c7d0::FUN_0042c7d0() : BE(0x30)
{
    _vtbl = (void*)&DAT_01015920;
    m00C = 0.0f;
}
}  // namespace fnv_0042c7d0

namespace fnv_0042c800 {
struct BE
{
    int _00;
    int _04;
    int _08;
    BE(unsigned char);
};
extern int DAT_0101592c;
struct FUN_0042c800 : BE
{
    unsigned char _0C;
    FUN_0042c800();
};
// Initialises the object: sets its vtable pointer to DAT_0101592c and clears the byte at offset 0x0C.
// @fnv 0x0042c800
FUN_0042c800::FUN_0042c800() : BE(0x4A)
{
    *(int*)this = (int)&DAT_0101592c;
    _0C = 0;
}
}  // namespace fnv_0042c800

namespace fnv_0042ca30 {
struct BE
{
    int _00;
    int _04;
    BE(unsigned char);
};
extern int DAT_01015208;
struct FUN_0042ca30 : BE
{
    int _08;
    float _0c;
    FUN_0042ca30();
};
// Initialises the object: installs the vtable pointer from DAT_01015208 and sets the float at offset 0x0c to 0.0f.
// @fnv 0x0042ca30
FUN_0042ca30::FUN_0042ca30() : BE(0x5c)
{
    *(int*)this = (int)&DAT_01015208;
    _0c = 0.0f;
}
}  // namespace fnv_0042ca30

namespace fnv_0042ca60 {
struct BE
{
    BE(unsigned char);
};
extern int DAT_01015214;
struct FUN_0042ca60 : BE
{
    FUN_0042ca60();
};
// @fnv 0x0042ca60
FUN_0042ca60::FUN_0042ca60() : BE(0x5D)
{
    *(int*)this = (int)&DAT_01015214;
    *(float*)((char*)this + 0xC) = 0.0f;
}
}  // namespace fnv_0042ca60

namespace fnv_0042cc40 {
struct BE
{
    BE(unsigned char);
    int _m0;
    int _m1;
    int _m2;
};
extern int DAT_010159a4;
struct FUN_0042cc40 : BE
{
    unsigned char _m3;
    FUN_0042cc40();
};
// Initialises the object: sets its vtable pointer to DAT_010159a4 and clears the byte at offset 0xC.
// @fnv 0x0042cc40
FUN_0042cc40::FUN_0042cc40() : BE(0x8d)
{
    *(int*)this = (int)&DAT_010159a4;
    *(unsigned char*)((char*)this + 0xC) = 0;
}
}  // namespace fnv_0042cc40

struct FUN_0042f2d0_Class : BaseExtraList
{
    unsigned char FUN_0042f2d0();
};
// Checks whether the extra data list contains an entry of type 0x80 and returns whether it was found.
// @fnv 0x0042f2d0
unsigned char FUN_0042f2d0_Class::FUN_0042f2d0()
{
    BSExtraData* pExtra = GetExtraData(0x80);
    return pExtra != 0;
}

namespace fnv_004198a0 {
struct TeleportableReference;

struct ExtraTeleport : BSExtraData
{
    TeleportableReference* m_pTeleportData;
    ExtraTeleport(TeleportableReference*);
};

struct ExtraListRemover
{
    void FUN_00410020(BSExtraData*, bool);
};

struct FUN_004198a0 : BaseExtraList
{
    void SetTeleportData(TeleportableReference* apTeleport);
};

// Sets or clears the teleport extra data (0x23): updates the stored pointer, removes the extra when passed -1, or creates and adds a new ExtraTeleport.
// @fnv 0x004198a0
void FUN_004198a0::SetTeleportData(TeleportableReference* apTeleport)
{
    ExtraTeleport* pExtra = (ExtraTeleport*)GetExtraData(0x23);
    if (pExtra)
    {
        if (apTeleport == (TeleportableReference*)-1)
            ((ExtraListRemover*)this)->FUN_00410020(pExtra, true);
        else
            pExtra->m_pTeleportData = apTeleport;
    }
    else if (apTeleport != (TeleportableReference*)-1)
    {
        pExtra = new ExtraTeleport(apTeleport);
        AddExtra(pExtra);
    }
}
}  // namespace fnv_004198a0

struct FUN_00431e20 : public BSExtraData
{
    unsigned char cExtraData;  // +0xc
    FUN_00431e20(unsigned char type);
};

struct FUN_00419a20
{
    void SetExtra(unsigned char type);
};

// Gets the extra data of type 0x26, updates its byte to type, or allocates a new one and adds it to the list.
// @fnv 0x00419a20
void FUN_00419a20::SetExtra(unsigned char type)
{
    BSExtraData* extra = ((BaseExtraList*)this)->GetExtraData(0x26);
    if (extra)
    {
        ((FUN_00431e20*)extra)->cExtraData = type;
    }
    else
    {
        extra = new FUN_00431e20(type);
        ((BaseExtraList*)this)->AddExtra(extra);
    }
}

struct FUN_00435150 : BSExtraData
{
    void* pData;
    FUN_00435150(void* a);
};

struct FUN_00419d10 : BaseExtraList
{
    void SetExtra(void* a);
};

// Stores a pointer in the extra data of type 0x3f, creating and adding a new FUN_00435150 entry if none exists.
// @fnv 0x00419d10
void FUN_00419d10::SetExtra(void* a)
{
    BSExtraData* e = GetExtraData(0x3f);
    if (e)
    {
        *(void**)((char*)e + 0xc) = a;
    }
    else
    {
        e = new FUN_00435150(a);
        AddExtra(e);
    }
}

struct FUN_00432220 : BSExtraData
{
    float fValue;
    FUN_00432220(float value);
};
struct FUN_00410020_StandIn
{
    void FUN_00410020(BSExtraData* extra, bool flag);
};
struct FUN_00419fb0_StandIn : BaseExtraList
{
    void FUN_00419fb0(float value);
};
// @fnv 0x00419fb0
void FUN_00419fb0_StandIn::FUN_00419fb0(float value)
{
    BSExtraData* extra = GetExtraData(0x30);
    if (extra)
    {
        if (value == 1.0)
            ((FUN_00410020_StandIn*)this)->FUN_00410020(extra, true);
        else
            ((FUN_00432220*)extra)->fValue = value;
    }
    else if (value != 1.0)
    {
        extra = new FUN_00432220(value);
        AddExtra(extra);
    }
}

namespace fnv_0041ac30 {
struct FUN_004325b0 : BSExtraData
{
    unsigned char cType;  // +0xc
    FUN_004325b0(unsigned char);
};

struct ExtraListRemover
{
    void FUN_00410020(BSExtraData*, bool);
};

struct FUN_0041ac30List : BaseExtraList
{
    void FUN_0041ac30(unsigned char);
};

// @fnv 0x0041ac30
void FUN_0041ac30List::FUN_0041ac30(unsigned char type)
{
    BSExtraData* extra = GetExtraData(0x31);
    if (type != 0xff)
    {
        if (!extra)
        {
            extra = new FUN_004325b0(type);
            AddExtra(extra);
        }
        else
        {
            *(unsigned char*)((char*)extra + 0xc) = type;
        }
    }
    else
    {
        if (extra)
        {
            ((ExtraListRemover*)this)->FUN_00410020(extra, true);
        }
    }
}
}  // namespace fnv_0041ac30

namespace fnv_0041be10 {
struct FUN_0041bef0 : public BSExtraData
{
    unsigned char pProcessData;
    FUN_0041bef0();
};

struct FUN_0041bf20_Class
{
    bool FUN_0041bf20();
};

struct FUN_00410020_Class
{
    void FUN_00410020(BSExtraData* extra, bool flag);
};

struct FUN_0041be10_Class : BaseExtraList
{
    void SetExtraState(unsigned char state);
};

// @fnv 0x0041be10
void FUN_0041be10_Class::SetExtraState(unsigned char state)
{
    FUN_0041bef0* extra = (FUN_0041bef0*)GetExtraData(0x50);
    if (state)
    {
        if (!extra)
        {
            extra = new FUN_0041bef0;
            AddExtra(extra);
        }
        extra->pProcessData = state;
    }
    else
    {
        if (extra)
        {
            extra->pProcessData = state;
            if (((FUN_0041bf20_Class*)extra)->FUN_0041bf20())
                ((FUN_00410020_Class*)this)->FUN_00410020(extra, true);
        }
    }
}
}  // namespace fnv_0041be10

namespace fnv_0041c390 {
void* __cdecl operator new(unsigned int);
struct FUN_0040f1b0_shell : BSExtraData
{
    void* m_pCellImpactSwapValue;
    FUN_0040f1b0_shell();
};
struct Dummy_00410020
{
    void FUN_00410020(BSExtraData*, bool);
};
struct ExtraDataList2 : BaseExtraList
{
    void FUN_0041c390(void* apImpactSwap);
};
// @fnv 0x0041c390
void ExtraDataList2::FUN_0041c390(void* apImpactSwap)
{
    BSExtraData* pExtra = GetExtraData(0x8c);
    if (!apImpactSwap)
    {
        if (pExtra)
            ((Dummy_00410020*)this)->FUN_00410020(pExtra, true);
    }
    else
    {
        if (!pExtra)
        {
            pExtra = new FUN_0040f1b0_shell;
            ((FUN_0040f1b0_shell*)pExtra)->m_pCellImpactSwapValue = apImpactSwap;
            AddExtra(pExtra);
        }
        else
        {
            ((FUN_0040f1b0_shell*)pExtra)->m_pCellImpactSwapValue = apImpactSwap;
        }
    }
}
}  // namespace fnv_0041c390

struct FUN_0041c5e0 : BSExtraData
{
    char str[4];
    unsigned char m_ucExtraDataType;
    FUN_0041c5e0(const char*);
    ~FUN_0041c5e0();
};
struct FUN_00410020_stub
{
    void FUN_00410020(BSExtraData*, bool);
};
struct BSStr
{
    bool Set(const char*, unsigned int);
};
struct FUN_0041c6f0_class : BaseExtraList
{
    void SetStringExtra(const char*);
};

// @fnv 0x0041c6f0
void FUN_0041c6f0_class::SetStringExtra(const char* value)
{
    BSExtraData* extra = GetExtraData(6);
    if (!value)
    {
        if (extra)
            ((FUN_00410020_stub*)this)->FUN_00410020(extra, true);
    }
    else if (!extra)
    {
        extra = new FUN_0041c5e0(value);
        AddExtra(extra);
    }
    else
    {
        ((BSStr*)((char*)extra + 0xc))->Set(value, 0);
    }
}

struct FUN_00433010 : BSExtraData
{
    char pad[0x4];
    FUN_00433010();
};
struct FUN_004331c0
{
    void SetExtra(int a, unsigned char b);
};
struct FUN_0041d700 : BaseExtraList
{
    void AddExtraData(int a, unsigned char b);
};
// Gets the extra data of type 0x1b, creating and adding it if missing, then calls SetExtra on it with the given arguments.
// @fnv 0x0041d700
void FUN_0041d700::AddExtraData(int a, unsigned char b)
{
    BSExtraData* e = GetExtraData(0x1b);
    if (!e)
    {
        e = new FUN_00433010;
        AddExtra(e);
    }
    ((FUN_004331c0*)e)->SetExtra(a, b);
}

namespace fnv_0041e340 {
struct DroppedItemExtra : public BSExtraData
{
    DroppedItemExtra();
    ~DroppedItemExtra();
    void* pItem;
};

struct ExtraListRemover
{
    void FUN_00410020(BSExtraData* extra, bool bDelete);
};

struct FUN_0041e340_ExtraDataList : public BaseExtraList
{
    void FUN_0041e340(void* apItem);
};

// Sets the dropped-item extra's pItem to apItem, creating and adding the extra if missing, or removes and deletes it when apItem is null.
// @fnv 0x0041e340
void FUN_0041e340_ExtraDataList::FUN_0041e340(void* apItem)
{
    DroppedItemExtra* extra = (DroppedItemExtra*)GetExtraData(0x89);
    if (apItem)
    {
        if (!extra)
        {
            extra = new DroppedItemExtra;
            AddExtra(extra);
        }
        extra->pItem = apItem;
    }
    else if (extra)
    {
        ((ExtraListRemover*)this)->FUN_00410020(extra, true);
    }
}
}  // namespace fnv_0041e340

struct FUN_0041e690 : public BaseExtraList
{
    void SetLinkedReference(TESObjectREFR* apRef);
};

struct FUN_0041e750 : public BSExtraData
{
    void* m_pFourthReference;
    FUN_0041e750();
};

// Stores apRef in extra data of type 0x6c, creating it if missing, or removes that extra data when apRef is null.
// @fnv 0x0041e690
void FUN_0041e690::SetLinkedReference(TESObjectREFR* apRef)
{
    FUN_0041e750* pextra;
    if (apRef)
    {
        pextra = (FUN_0041e750*)GetExtraData(0x6c);
        if (pextra)
        {
            pextra->m_pFourthReference = apRef;
        }
        else
        {
            pextra = new FUN_0041e750;
            pextra->m_pFourthReference = apRef;
            AddExtra(pextra);
        }
    }
    else
    {
        RemoveExtra(0x6c);
    }
}

namespace fnv_0041eba0 {
struct Extra0x53 : BSExtraData
{
    Extra0x53();
    unsigned char layoutPadding9;
    unsigned short layoutPaddingA;
    unsigned char layoutPaddingC;
    unsigned short layoutPaddingD;
    unsigned char layoutPaddingF;
    unsigned short layoutPadding10;
    unsigned char layoutPadding12;
    unsigned short layoutPadding13;
    unsigned char layoutPadding15;
};

struct FUN_0041eba0_list : BaseExtraList
{
    void FUN_0041eba0(bool aiEdge);
};

// Gets or creates the 0x53 extra data and sets or clears bit 0 of its byte at offset 0x14 based on aiEdge.
// @fnv 0x0041eba0
void FUN_0041eba0_list::FUN_0041eba0(bool aiEdge)
{
    Extra0x53* pdata = (Extra0x53*)GetExtraData(0x53);
    if (!pdata && aiEdge)
    {
        pdata = new Extra0x53;
        AddExtra(pdata);
    }
    if (pdata)
    {
        if (aiEdge)
            ((unsigned char*)pdata)[0x14] |= 1;
        else
            ((unsigned char*)pdata)[0x14] &= ~1;
    }
}
}  // namespace fnv_0041eba0

struct TESObjectREFR;
struct G2
{
    void AddHead(TESObjectREFR*&);
};
struct LH
{
    bool IsInList(TESObjectREFR*&) const;
};
struct _ref_00905330
{
    void Remove(TESObjectREFR*&);
};
struct ExtraWaterLightRefs : BSExtraData
{
    G2 refs;
    ExtraWaterLightRefs();
    char pad[4];
};
struct FUN_0041f840 : BaseExtraList
{
    void SetEnableParentReference(TESObjectREFR* apRef, bool bValue);
};
// Adds or removes apRef from the ExtraWaterLightRefs list, creating the extra data if bValue is set and none exists.
// @fnv 0x0041f840
void FUN_0041f840::SetEnableParentReference(TESObjectREFR* apRef, bool abAdd)
{
    ExtraWaterLightRefs* pextra = (ExtraWaterLightRefs*)GetExtraData(0x84);
    if (pextra)
    {
        G2* preflist = &pextra->refs;
        if (abAdd)
        {
            if (!((LH*)preflist)->IsInList(apRef))
                preflist->AddHead(apRef);
        }
        else
        {
            ((_ref_00905330*)preflist)->Remove(apRef);
        }
    }
    else if (abAdd)
    {
        pextra = new ExtraWaterLightRefs;
        AddExtra((BSExtraData*)pextra);
        pextra->refs.AddHead(apRef);
    }
}

struct FUN_00410020_shell
{
    void FUN_00410020(BSExtraData*, bool);
};
struct FUN_0041fd00_shell
{
    void FUN_0041fd00(int);
};
struct FUN_004202d0 : BSExtraData
{
    int iSpellID;
    FUN_004202d0();
};
struct FUN_00420210_shell : BaseExtraList
{
    void FUN_00420210(int spellID);
};

// @fnv 0x00420210
void FUN_00420210_shell::FUN_00420210(int spellID)
{
    BSExtraData* extra = GetExtraData(0x77);
    if (extra)
        ((FUN_00410020_shell*)this)->FUN_00410020(extra, true);
    if (spellID)
    {
        extra = new FUN_004202d0;
        ((FUN_0041fd00_shell*)extra)->FUN_0041fd00(spellID);
        AddExtra(extra);
    }
}

namespace fnv_00420440 {
struct FUN_00410020_shell
{
    void FUN_00410020(BSExtraData* extra, bool clear);
};

struct FUN_00420500 : BSExtraData
{
    void* pSpell;
    FUN_00420500();
    void SetSelectedMagicItem(MagicItem* spell);
};

struct FUN_00420440_shell : BaseExtraList
{
    void FUN_00420440(MagicItem* spell);
};

// @fnv 0x00420440
void FUN_00420440_shell::FUN_00420440(MagicItem* spell)
{
    BSExtraData* extra = GetExtraData(0x7b);
    if (extra)
        ((FUN_00410020_shell*)this)->FUN_00410020(extra, true);
    if (spell)
    {
        extra = new FUN_00420500;
        ((FUN_00420500*)extra)->SetSelectedMagicItem(spell);
        AddExtra(extra);
    }
}
}  // namespace fnv_00420440

namespace fnv_00420f00 {
struct GO
{
    void operator=(void*);
};
struct FUN_004358a0
{
    char b[0x10];
    FUN_004358a0();
};
struct FUN_00420f00_shell : BaseExtraList
{
    void RemoveExtra(unsigned char type);
    void FUN_00420f00(void* apRoom);
};
// Stores apRoom in the extra data of type 0x79, creating and adding it if missing, or removes that extra when apRoom is null.
// @fnv 0x00420f00
void FUN_00420f00_shell::FUN_00420f00(void* apRoom)
{
    if (apRoom)
    {
        FUN_004358a0* pextra = (FUN_004358a0*)GetExtraData(0x79);
        if (pextra)
        {
            *(GO*)((char*)pextra + 0xc) = apRoom;
        }
        else
        {
            pextra = new FUN_004358a0;
            *(GO*)((char*)pextra + 0xc) = apRoom;
            AddExtra((BSExtraData*)pextra);
        }
    }
    else
    {
        RemoveExtra(0x79);
    }
}
}  // namespace fnv_00420f00

namespace fnv_004211d0 {
struct ActorPackageData
{
    int a;
    int b;
    int c;
};
struct ExtraPackageData : public BSExtraData
{
    ActorPackageData* m_pActorPackageData;
    ExtraPackageData(ActorPackageData*);
};
ExtraPackageData::ExtraPackageData(ActorPackageData* p)
{
    m_pActorPackageData = p;
}
struct FUN_004211d0 : public BaseExtraList
{
    void AttachActorPackageData(ActorPackageData* apData);
};
// Stores apData in the existing extra data of type 0x70, or adds a new ExtraPackageData wrapping apData.
// @fnv 0x004211d0
void FUN_004211d0::AttachActorPackageData(ActorPackageData* apData)
{
    ExtraPackageData* pextra = (ExtraPackageData*)GetExtraData(0x70);
    if (pextra)
        pextra->m_pActorPackageData = apData;
    else
        AddExtra(new ExtraPackageData(apData));
}
}  // namespace fnv_004211d0

struct FUN_004311f0
{
    void** m_ppVirtualMethodTable;
    unsigned char m_ucExtraDataType;
    unsigned char layoutPadding5;
    unsigned short layoutPadding6;
    void* pNext;
    void* fieldC;
    void* field10;
    FUN_004311f0();
};

struct FUN_00421750_shell : BaseExtraList
{
    void RemoveExtra(unsigned char);
    void FUN_00421750(void* a, void* b);
};

// Stores a and b in the extra data of type 0x2e, creating it if missing, or removes that extra when either argument is null.
// @fnv 0x00421750
void FUN_00421750_shell::FUN_00421750(void* apFirst, void* apSecond)
{
    if (apFirst && apSecond)
    {
        FUN_004311f0* e = (FUN_004311f0*)GetExtraData(0x2e);
        if (!e)
        {
            e = new FUN_004311f0;
            AddExtra((BSExtraData*)e);
        }
        e->fieldC = apFirst;
        e->field10 = apSecond;
    }
    else
    {
        RemoveExtra(0x2e);
    }
}

struct FUN_0040f6b0 : BSExtraData
{
    BSExtraData* pExtra;
    FUN_0040f6b0();
};
struct FUN_00421850_shell : BaseExtraList
{
    void FUN_00421850(BSExtraData* extra);
};
// Stores extra in the extra-data slot 0xb, creating and adding a new entry if none exists, or removing slot 0xb when extra is null.
// @fnv 0x00421850
void FUN_00421850_shell::FUN_00421850(BSExtraData* extra)
{
    if (extra)
    {
        BSExtraData* found = GetExtraData(0xb);
        if (found)
        {
            ((FUN_0040f6b0*)found)->pExtra = extra;
        }
        else
        {
            found = new FUN_0040f6b0;
            ((FUN_0040f6b0*)found)->pExtra = extra;
            AddExtra(found);
        }
    }
    else
    {
        RemoveExtra(0xb);
    }
}

namespace fnv_00422050 {
struct GO
{
    GO& operator=(void*);
};

struct FUN_00435690
{
    FUN_00435690();
    ~FUN_00435690();
    unsigned char layoutPadding[12];
    GO m_uiFilterValue;
    unsigned char layoutPadding2[3];
};

struct FUN_0041adf0_shell : BaseExtraList
{
    void RemoveExtra(unsigned char);
};

struct FUN_00422050_shell : BaseExtraList
{
    void FUN_00422050(void* pValue);
};

// Stores pValue in extra data of type 0x61, creating and adding it if missing, or removes that extra data when pValue is null.
// @fnv 0x00422050
void FUN_00422050_shell::FUN_00422050(void* pValue)
{
    if (pValue)
    {
        FUN_00435690* pExtra = (FUN_00435690*)this->GetExtraData(0x61);
        if (pExtra)
            pExtra->m_uiFilterValue = pValue;
        else
        {
            pExtra = new FUN_00435690;
            pExtra->m_uiFilterValue = pValue;
            this->AddExtra((BSExtraData*)pExtra);
        }
    }
    else
        ((FUN_0041adf0_shell*)this)->RemoveExtra(0x61);
}
}  // namespace fnv_00422050

namespace fnv_00422750 {
struct FUN_00435f20_class : BSExtraData
{
    float fValue;
    FUN_00435f20_class(float value);
};

struct FUN_00410020_stub
{
    void FUN_00410020(BSExtraData* extra, bool bRemove);
};

struct FUN_00422750_class : BaseExtraList
{
    void FUN_00422750(bool bAdd, float fValue);
};

// @fnv 0x00422750
void FUN_00422750_class::FUN_00422750(bool bAdd, float fValue)
{
    FUN_00435f20_class* extra = (FUN_00435f20_class*)GetExtraData(0x48);
    if (bAdd)
    {
        if (!extra)
        {
            extra = new FUN_00435f20_class(fValue);
            AddExtra(extra);
        }
        extra->fValue = fValue;
    }
    else if (extra)
    {
        ((FUN_00410020_stub*)this)->FUN_00410020(extra, true);
    }
}
}  // namespace fnv_00422750

extern "C" void __cdecl _fnv_call_845cc0(const char*);

struct FUN_00435c10_shell
{
    void FUN_00435c10();
};

struct FUN_00435a60 : BSExtraData
{
    char* m_pString;
    FUN_00435a60();
};

struct FUN_00422940_shell : BaseExtraList
{
    void RemoveExtra(unsigned char);
    void FUN_00422940(char* apBuffer);
};

// @fnv 0x00422940
void FUN_00422940_shell::FUN_00422940(char* apBuffer)
{
    if (!apBuffer)
        RemoveExtra(0x42);
    else
    {
        FUN_00435a60* pextra = static_cast<FUN_00435a60*>(GetExtraData(0x42));
        if (pextra)
        {
            _fnv_call_845cc0("SAVELOAD: SetSavedAnimation() is being called when there is already a saved animation.");
            ((FUN_00435c10_shell*)pextra)->FUN_00435c10();
        }
        else
        {
            pextra = new FUN_00435a60;
            AddExtra(pextra);
        }
        pextra->m_pString = apBuffer;
    }
}

struct FUN_00435b50 : public BSExtraData
{
    char* m_pSavedHavokData;
    FUN_00435b50();
    ~FUN_00435b50();
    void FUN_00435c10();
};

void __cdecl _fnv_call_845cc0(const char* apMsg);

struct FUN_00422ac0_shell : public BaseExtraList
{
    void RemoveExtra(unsigned char type);
    void FUN_00422ac0(char* apBuffer);
};

// Stores or clears the saved havok data extra (type 0x3d): removes it when apBuffer is null, otherwise reuses or creates the extra and assigns apBuffer.
// @fnv 0x00422ac0
void FUN_00422ac0_shell::FUN_00422ac0(char* apBuffer)
{
    if (!apBuffer)
        RemoveExtra(0x3d);
    else
    {
        FUN_00435b50* pextra = (FUN_00435b50*)GetExtraData(0x3d);
        if (pextra)
        {
            _fnv_call_845cc0("SAVELOAD: SetSavedHavokData() is being called when there is already saved havok data.");
            pextra->FUN_00435c10();
        }
        else
        {
            pextra = new FUN_00435b50;
            AddExtra(pextra);
        }
        pextra->m_pSavedHavokData = apBuffer;
    }
}

struct FUN_0042e210_Class : BSExtraData
{
    int a;
    int b;
    FUN_0042e210_Class(int, int);
    ~FUN_0042e210_Class();
};
struct FUN_0042e150_StandIn : BaseExtraList
{
    void FUN_0042e150(int, int);
};
// Finds the extra data of type 0x5b; if absent, allocates it with the two values and adds it, otherwise overwrites its two fields.
// @fnv 0x0042e150
void FUN_0042e150_StandIn::FUN_0042e150(int aiValueA, int aiValueB)
{
    FUN_0042e210_Class* extra = static_cast<FUN_0042e210_Class*>(GetExtraData(0x5b));
    if (!extra)
    {
        extra = new FUN_0042e210_Class(aiValueA, aiValueB);
        AddExtra(extra);
    }
    else
    {
        extra->a = aiValueA;
        extra->b = aiValueB;
    }
}

namespace fnv_0042e380 {
struct FUN_0042e450 : public BSExtraData
{
    unsigned short iModSlot;
    unsigned short iModCount;
    FUN_0042e450(unsigned char);
};
struct FUN_0042e480_Class : public BSExtraData
{
    void FUN_0042e480(unsigned char);
};

struct FUN_0042e380_Class : public BaseExtraList
{
    void FUN_0042e380(unsigned char);
};

// Gets the extra data of type 0x8d, creating and adding a new one for the slot if absent and slot is nonzero, then calls its update with the slot.
// @fnv 0x0042e380
void FUN_0042e380_Class::FUN_0042e380(unsigned char slot)
{
    FUN_0042e480_Class* extra = (FUN_0042e480_Class*)GetExtraData(0x8d);
    if (!extra && slot > 0)
    {
        extra = (FUN_0042e480_Class*)new FUN_0042e450(slot);
        extra->FUN_0042e480(slot);
        AddExtra(extra);
    }
    else
        extra->FUN_0042e480(slot);
}
}  // namespace fnv_0042e380

struct FUN_00430200
{
    void** m_ppVirtualMethodTable;
    unsigned char m_ucExtraDataType;
    unsigned char layoutPadding5;
    unsigned short layoutPadding6;
    BSExtraData* pNext;
    char data[0x30 - 0xC];
    FUN_00430200();
    ~FUN_00430200();
};

struct FUN_0042e820 : BaseExtraList
{
    FUN_00430200* AddExtraData();
};

// Returns the extra data entry with type 0x5f, creating and adding a new one if it is missing.
// @fnv 0x0042e820
FUN_00430200* FUN_0042e820::AddExtraData()
{
    FUN_00430200* extra = reinterpret_cast<FUN_00430200*>(GetExtraData(0x5f));
    if (!extra)
    {
        extra = new FUN_00430200;
        AddExtra(reinterpret_cast<BSExtraData*>(extra));
    }
    return extra;
}

struct FUN_0042eb60_shell : BaseExtraList
{
    void RemoveExtra(unsigned char type);
    void SetOwnership(void* owner, void* item);
};

struct ExtraOwnership : BSExtraData
{
    void* pOwner;
    void* pItem;
    ExtraOwnership(void* owner, void* item);
};

// Sets or clears the ownership extra (type 0x6e): removes it if owner or item is null, otherwise updates or creates an ExtraOwnership.
// @fnv 0x0042eb60
void FUN_0042eb60_shell::SetOwnership(void* owner, void* item)
{
    if (!owner || !item)
        RemoveExtra(0x6e);
    else
    {
        BSExtraData* extra = GetExtraData(0x6e);
        if (extra)
        {
            *(void**)((char*)extra + 0xc) = owner;
            *(void**)((char*)extra + 0x10) = item;
        }
        else
        {
            extra = new ExtraOwnership(owner, item);
            AddExtra(extra);
        }
    }
}

namespace fnv_0042ec70 {
struct FUN_0042edb0_shell
{
    void FUN_0042edb0();
};
struct FUN_004376e0 : BSExtraData
{
    int iValue;
    char pad[12];
    FUN_004376e0(int value);
};
struct FUN_0042ec70_list : BaseExtraList
{
    void FUN_0042ec70(int value);
};
// If value is zero, clears the extra data via FUN_0042edb0; otherwise finds extra data of type 0x75 and sets its iValue, creating and adding a new one if absent.
// @fnv 0x0042ec70
void FUN_0042ec70_list::FUN_0042ec70(int value)
{
    if (!value)
        ((FUN_0042edb0_shell*)this)->FUN_0042edb0();
    else
    {
        BSExtraData* extra = GetExtraData(0x75);
        if (extra)
            ((FUN_004376e0*)extra)->iValue = value;
        else
        {
            extra = new FUN_004376e0(value);
            AddExtra(extra);
        }
    }
}
}  // namespace fnv_0042ec70

namespace fnv_0042ef20 {
struct ContainerItemExtra : BSExtraData
{
    void* data;
    ContainerItemExtra(void* arg);
    ~ContainerItemExtra();
};
struct G2
{
    void AddHead(void**);
};
struct FUN_0042f000_StandIn
{
    void FUN_0042f000();
};
struct FUN_0042ef20_StandIn : BaseExtraList
{
    void FUN_0042ef20(void* item);
};
// @fnv 0x0042ef20
void FUN_0042ef20_StandIn::FUN_0042ef20(void* item)
{
    if (!item)
    {
        ((FUN_0042f000_StandIn*)this)->FUN_0042f000();
        return;
    }
    BSExtraData* extra = GetExtraData(0x73);
    if (extra)
    {
        ((G2*)*(void**)((char*)extra + 0xc))->AddHead(&item);
    }
    else
    {
        extra = new ContainerItemExtra(item);
        AddExtra(extra);
    }
}
}  // namespace fnv_0042ef20

struct FUN_00437c40 : public BSExtraData
{
    char pad[0x28 - sizeof(BSExtraData)];
    FUN_00437c40();
    ~FUN_00437c40();
};

struct FUN_0042f420_helper
{
    BSExtraData* __thiscall GetOrCreateExtraData();
};

// Returns the extra data of type 0x8b from the list, creating and adding a new one if it is missing.
// @fnv 0x0042f420
BSExtraData* __thiscall FUN_0042f420_helper::GetOrCreateExtraData()
{
    BSExtraData* pextra = ((BaseExtraList*)this)->GetExtraData(0x8b);
    if (!pextra)
    {
        pextra = new FUN_00437c40;
        ((BaseExtraList*)this)->AddExtra(pextra);
    }
    return pextra;
}

namespace fnv_0040f900 {
extern int DAT_011c38e4;
extern "C" void* __cdecl memset(void* dest, int c, unsigned int count);
struct FUN_0040f900_tls
{
    int pad0;
    int pad4;
    int pad8;
    int pad12;
    char buf[0x24c];
};
__declspec(thread) FUN_0040f900_tls g_tls;
// If the thread-local stamp differs from DAT_011c38e4, clears pad8 and buf and stores the current stamp in pad12.
// @fnv 0x0040f900
void ResetTlsBufferIfStale()
{
    if (g_tls.pad12 != DAT_011c38e4)
    {
        g_tls.pad8 = 0;
        memset(g_tls.buf, 0, 0x24c);
        g_tls.pad12 = DAT_011c38e4;
    }
}
}  // namespace fnv_0040f900

namespace fnv_0041b4b0 {
struct Dummy_00410020
{
    void* GetOrCreateExtraAction();
};
struct ExtraDataList_Remove_stub
{
    void FUN_00410020(BSExtraData*, bool);
};
struct FUN_0041b4b0_t : BaseExtraList
{
    void FUN_0041b4b0(void* value);
};
// @fnv 0x0041b4b0
void FUN_0041b4b0_t::FUN_0041b4b0(void* value)
{
    BSExtraData* extra = GetExtraData(0xe);
    if (!extra)
    {
        if (value)
            extra = (BSExtraData*)((Dummy_00410020*)this)->GetOrCreateExtraAction();
    }
    else if (*(unsigned char*)((char*)extra + 0xc) == 1 && !value)
    {
        ((ExtraDataList_Remove_stub*)this)->FUN_00410020(extra, true);
        extra = 0;
    }
    if (extra)
        *(void**)((char*)extra + 0x10) = value;
}
}  // namespace fnv_0041b4b0

struct TrespassPackage : TESPackage
{
    void SetTrespassEnabled(bool);
};
struct ExtraTresPassPackage : BSExtraData
{
    TrespassPackage* pTargetPackage;
};
struct TESSaveLoadGame
{
    bool GetLoading();
    void DeleteForm(TESForm*);
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
struct ExtraDataListRemoveTrespassPackage
{
    void FUN_00410020(BSExtraData*, bool);
    void FUN_0041cda0();
};
// @fnv 0x0041cda0
void ExtraDataListRemoveTrespassPackage::FUN_0041cda0()
{
    ExtraTresPassPackage* pExtra = (ExtraTresPassPackage*)reinterpret_cast<BaseExtraList*>(this)->GetExtraData(0x1a);
    if (pExtra)
    {
        pExtra->pTargetPackage->SetTrespassEnabled(true);
        if (g_TESSaveLoadGame->GetLoading())
            g_TESSaveLoadGame->DeleteForm((TESForm*)pExtra->pTargetPackage);
        pExtra->pTargetPackage = 0;
        FUN_00410020(pExtra, true);
    }
}

namespace fnv_0041dda0 {
struct Dummy_00410020
{
    void FUN_00410020(BSExtraData*, bool);
};
struct Dummy_0041dda0
{
    void FUN_0041dda0(BSExtraData*);
};
struct ContNode
{
    void FUN_00905330(BSExtraData**);
    bool ref_008256d0();
};
// @fnv 0x0041dda0
void Dummy_0041dda0::FUN_0041dda0(BSExtraData* extra)
{
    if (extra)
    {
        BSExtraData* pData = ((BaseExtraList*)this)->GetExtraData(0x38);
        if (pData)
        {
            ((ContNode*)((char*)pData + 0xc))->FUN_00905330(&extra);
            if (((ContNode*)((char*)pData + 0xc))->ref_008256d0())
                ((Dummy_00410020*)this)->FUN_00410020(pData, true);
        }
    }
}
}  // namespace fnv_0041dda0

namespace fnv_0041e0d0 {
struct DroppedItemNode
{
    void FUN_00905330(const void*);
    unsigned char FUN_008256d0();
};
struct ExtraDroppedItemList : BSExtraData
{
    DroppedItemNode* m_pInventoryEntryData;  // +0xc
};
struct Dummy_00410020
{
    void FUN_00410020(BSExtraData* extra, bool flag);
};
struct FUN_0041e0d0_shell : BaseExtraList
{
    void FUN_0041e0d0(void* apItem);
};
// @fnv 0x0041e0d0
void FUN_0041e0d0_shell::FUN_0041e0d0(void* apItem)
{
    if (apItem)
    {
        ExtraDroppedItemList* pextra = (ExtraDroppedItemList*)GetExtraData(0x3a);
        if (pextra)
        {
            ((DroppedItemNode*)((char*)pextra + 0xc))->FUN_00905330(&apItem);
            if (((DroppedItemNode*)((char*)pextra + 0xc))->FUN_008256d0())
                ((Dummy_00410020*)this)->FUN_00410020(pextra, true);
        }
    }
}
}  // namespace fnv_0041e0d0

namespace fnv_0041e600 {
struct FUN_00905330_stub
{
    void FUN_00905330(const void*);
};
struct FUN_008256d0_stub
{
    unsigned char FUN_008256d0();
};
struct FUN_00410020_stub
{
    void FUN_00410020(BSExtraData*, bool);
};
struct FUN_0041e600 : BaseExtraList
{
    void DetachExtraData(void* apChild);
};
// @fnv 0x0041e600
void FUN_0041e600::DetachExtraData(void* apChild)
{
    if (apChild)
    {
        BSExtraData* pextra = GetExtraData(0x52);
        if (pextra)
        {
            ((FUN_00905330_stub*)((char*)pextra + 0xc))->FUN_00905330(&apChild);
            if (((FUN_008256d0_stub*)((char*)pextra + 0xc))->FUN_008256d0())
                ((FUN_00410020_stub*)this)->FUN_00410020(pextra, true);
        }
    }
}
}  // namespace fnv_0041e600

struct FUN_00433a00_t
{
    void* FUN_00433a00(void*);
};

struct ContNode
{
    void FUN_00905330(void*);
};

struct _ref_008256d0_shell
{
    unsigned char _ref_008256d0();
};

void __cdecl _Deallocate(void*);

struct FUN_0041e960_shell : BaseExtraList
{
    void RemoveExtra(unsigned char type);
    void FUN_0041e960(void* value);
};

// @fnv 0x0041e960
void FUN_0041e960_shell::FUN_0041e960(void* value)
{
    if (value)
    {
        BSExtraData* extra = GetExtraData(0x53);
        if (extra)
        {
            void* result = ((FUN_00433a00_t*)extra)->FUN_00433a00(value);
            if (result)
            {
                ((ContNode*)((char*)extra + 0xc))->FUN_00905330(&result);
                void* temp = result;
                _Deallocate(temp);
                if (((_ref_008256d0_shell*)((char*)extra + 0xc))->_ref_008256d0())
                    RemoveExtra(0x53);
            }
        }
    }
}

namespace fnv_0041e9e0 {
struct FUN_00433a00_t
{
    float fValue;
    void* FUN_00433a00(void*);
};
struct FUN_0041e9e0_t : BaseExtraList
{
    float GetExtraFloat(void* apRef);
};
// Looks up extra data of type 0x53, resolves it via FUN_00433a00 with apRef, and returns the float at offset 4, or 0.0f if absent.
// @fnv 0x0041e9e0
float FUN_0041e9e0_t::GetExtraFloat(void* apRef)
{
    BSExtraData* pextra = GetExtraData(0x53);
    if (pextra)
    {
        FUN_00433a00_t* pdata = (FUN_00433a00_t*)((FUN_00433a00_t*)pextra)->FUN_00433a00(apRef);
        if (pdata)
            return *(float*)((char*)pdata + 4);
    }
    return 0.0f;
}
}  // namespace fnv_0041e9e0

namespace fnv_00420300 {
struct LinkedReferencePair
{
    void* apLinkedRefs[2];
};

struct ExtraPortalRefData : public BSExtraData
{
    LinkedReferencePair* pData;
    bool FUN_00420300(BSExtraData* apCompare);
};

// Compares the two linked-ref pointers of pData with those of apCompare's pData, returning true if they differ or only one side has data.
// @fnv 0x00420300
bool ExtraPortalRefData::FUN_00420300(BSExtraData* apCompare)
{
    ExtraPortalRefData* potherExtra = (ExtraPortalRefData*)apCompare;
    if (!pData && !potherExtra->pData)
        return false;
    if (!pData || !potherExtra->pData)
        return true;
    for (int i = 0; i < 2; ++i)
    {
        if (pData->apLinkedRefs[i] != potherExtra->pData->apLinkedRefs[i])
            return true;
    }
    return false;
}
}  // namespace fnv_00420300

struct Unk42ffa0
{
    int pad;
    Unk42ffa0* data;
    unsigned int size;
};
struct Unk42fb20
{
    void FUN_0042fb20(Unk42ffa0*, unsigned int);
};
struct FUN_006c8a30_Class
{
    void FUN_006a8500();
};
struct FUN_0042f9c0_Class : Unk42fb20
{
    int pad;
    Unk42ffa0* data;
    unsigned int size;
    unsigned int capacity;
    void FUN_0042f9c0(bool freeStorage);
};
// @fnv 0x0042f9c0
void FUN_0042f9c0_Class::FUN_0042f9c0(bool freeStorage)
{
    if (data)
    {
        FUN_0042fb20(data, size);
        if (freeStorage)
        {
            ((FUN_006c8a30_Class*)this)->FUN_006a8500();
            data = 0;
            capacity = 0;
        }
        size = 0;
    }
}

struct FUN_00484af0_t
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
    virtual void MarkAsModified(int);
    int pad;
    int flags;
    void FUN_00484af0(bool set);
};
// Sets or clears bit 0x800 in flags according to set, then calls MarkAsModified(1).
// @fnv 0x00484af0
void FUN_00484af0_t::FUN_00484af0(bool set)
{
    if (set)
        flags |= 0x800;
    else
        flags &= ~0x800;
    MarkAsModified(1);
}

struct FUN_0041b790 : BSExtraData
{
    float fValue;
    FUN_0041b790(float value);
};

struct ExtraListHelper : BaseExtraList
{
    void FUN_0041b6e0(float value);
};

// Finds extra data of type 0x56; if absent, creates a new FUN_0041b790 with value and adds it, otherwise writes value at offset 0xc.
// @fnv 0x0041b6e0
void ExtraListHelper::FUN_0041b6e0(float value)
{
    BSExtraData* extra = GetExtraData(0x56);
    if (!extra)
    {
        extra = new FUN_0041b790(value);
        AddExtra(extra);
    }
    else
    {
        *(float*)((char*)extra + 0xc) = value;
    }
}

struct ExtraDecalRefsStandIn : BSExtraData
{
    char c70[0x08];
    ExtraDecalRefsStandIn();
    ~ExtraDecalRefsStandIn();
    void SetDecalRefData(TESObjectREFR* a, const NiPoint3& b, const NiPoint3& c);
};
struct FUN_0041f080_cls : BaseExtraList
{
    void FUN_0041f080(TESObjectREFR* a, const NiPoint3& b, const NiPoint3& c);
};
// @fnv 0x0041f080
void FUN_0041f080_cls::FUN_0041f080(TESObjectREFR* apRefr, const NiPoint3& akPoint1, const NiPoint3& akPoint2)
{
    if (apRefr)
    {
        ExtraDecalRefsStandIn* extra = (ExtraDecalRefsStandIn*)GetExtraData(0x57);
        if (!extra)
        {
            extra = new ExtraDecalRefsStandIn;
            AddExtra(extra);
        }
        extra->SetDecalRefData(apRefr, akPoint1, akPoint2);
    }
}

namespace fnv_00422590 {
struct ExtraFriendHits
{
    int GetFriendHitSlotCount();
};
struct FUN_00435c40 : BSExtraData
{
    char pad[0x10];
    FUN_00435c40();
};
struct FUN_00435d40 : BSExtraData
{
    void Method_00435d40();
};
struct FUN_00422590_cls : BaseExtraList
{
    void EnsureFriendHitExtra();
};
// Gets the extra data of type 0x45, creating and adding a new one if absent, then calls two methods on it.
// @fnv 0x00422590
void FUN_00422590_cls::EnsureFriendHitExtra()
{
    BSExtraData* extra = GetExtraData(0x45);
    if (!extra)
    {
        extra = new FUN_00435c40;
        AddExtra(extra);
    }
    ((FUN_00435d40*)extra)->Method_00435d40();
    ((ExtraFriendHits*)extra)->GetFriendHitSlotCount();
}
}  // namespace fnv_00422590

struct ExtraHotKey : BSExtraData
{
    char m_cHotKey;
    ExtraHotKey(char);
};

struct FUN_0042dde0_cls : BaseExtraList
{
    void SetHotKey(char acValue);
};

// Gets the extra data of type 0x4a; if absent, creates an ExtraHotKey with acValue and adds it, otherwise updates its stored value.
// @fnv 0x0042dde0
void FUN_0042dde0_cls::SetHotKey(char acValue)
{
    ExtraHotKey* pextra = (ExtraHotKey*)GetExtraData(0x4a);
    if (!pextra)
    {
        pextra = new ExtraHotKey(acValue);
        AddExtra(pextra);
    }
    else
    {
        pextra->m_cHotKey = acValue;
    }
}

namespace fnv_004127e0 {
struct FUN_00411f20_shell
{
  public:
    bool FUN_00411f20(BSExtraData* extra);
};

struct Crime
{
  public:
    TESObjectREFR* GetTarget();
};

struct PatrolActorPackageData
{
  public:
    bool IsPatrolling();
};

struct ExtraHelper_004bca80
{
  public:
    int FUN_0040fe20();
};

struct GlobalObject_0096a2d0 : public RecursiveSpinLock
{
};

extern GlobalObject_0096a2d0 g_011c3920;

struct ExtraDataList_shell : public BaseExtraList
{
  public:
    bool FUN_004127e0(ExtraDataList_shell* apCompare);
};

// Locks the global lock, walks both extra-data lists comparing entries by type and value, and returns whether they differ.
// @fnv 0x004127e0
bool ExtraDataList_shell::FUN_004127e0(ExtraDataList_shell* apCompare)
{
    g_011c3920.Lock("ExtraDataList::CompareList()");

    bool bres = false;
    BSExtraData* work = apCompare->pHead;

    {
        BSExtraData* apExtra;
        while (work != 0)
        {
            if (reinterpret_cast<FUN_00411f20_shell*>(this)->FUN_00411f20(work))
            {
                apExtra = GetExtraData(reinterpret_cast<PatrolActorPackageData*>(work)->IsPatrolling());
                if (apExtra == 0)
                {
                    bres = true;
                    break;
                }

                if (reinterpret_cast<bool(__thiscall*)(BSExtraData*, BSExtraData*)>((*(void***)apExtra)[1])(apExtra,
                                                                                                            work))
                {
                    bres = true;
                    break;
                }
            }

            work = reinterpret_cast<BSExtraData*>(reinterpret_cast<Crime*>(work)->GetTarget());
        }
    }

    if (!bres)
    {
        BSExtraData* apExtra;
        work = pHead;

        while (work != 0)
        {
            if (reinterpret_cast<FUN_00411f20_shell*>(this)->FUN_00411f20(work))
            {
                apExtra = apCompare->GetExtraData(reinterpret_cast<PatrolActorPackageData*>(work)->IsPatrolling());
                if (apExtra == 0)
                {
                    bres = true;
                    break;
                }

                if (reinterpret_cast<bool(__thiscall*)(BSExtraData*, BSExtraData*)>((*(void***)apExtra)[1])(apExtra,
                                                                                                            work))
                {
                    bres = true;
                    break;
                }
            }

            work = reinterpret_cast<BSExtraData*>(reinterpret_cast<Crime*>(work)->GetTarget());
        }
    }

    if (reinterpret_cast<ExtraHelper_004bca80*>(this)->FUN_0040fe20() !=
        reinterpret_cast<ExtraHelper_004bca80*>(apCompare)->FUN_0040fe20())
    {
        BSExtraData* apExtra;
        work = pHead;

        while (work != 0)
        {
            if (reinterpret_cast<FUN_00411f20_shell*>(this)->FUN_00411f20(work))
            {
                apExtra = apCompare->GetExtraData(reinterpret_cast<PatrolActorPackageData*>(work)->IsPatrolling());
                if (apExtra == 0)
                {
                    bres = true;
                    break;
                }
            }

            work = reinterpret_cast<BSExtraData*>(reinterpret_cast<Crime*>(work)->GetTarget());
        }
    }

    g_011c3920.Unlock();
    return bres;
}
}  // namespace fnv_004127e0

namespace fnv_00418550 {
class TESObjectREFR;

extern unsigned int _data_011c16bc;

struct FUN_00431950 : public BSExtraData
{
  public:
    TESObjectREFR* m_pWorldReferenceInfo;

    FUN_00431950(TESObjectREFR* apRef);
};

typedef FUN_00431950 ExtraOriginalReference;

FUN_00431950::FUN_00431950(TESObjectREFR* apRef)
{
    m_pWorldReferenceInfo = apRef;
}

struct FUN_00418550_cls : public BaseExtraList
{
  public:
    void SetOriginalReference(TESObjectREFR* apRef);
};

// Updates the existing extra data of type 0x20 to point at apRef, then creates and adds a new ExtraOriginalReference for apRef.
// @fnv 0x00418550
void FUN_00418550_cls::SetOriginalReference(TESObjectREFR* apRef)
{
    ExtraOriginalReference* pExtra = static_cast<ExtraOriginalReference*>(GetExtraData(0x20));

    if (pExtra)
        pExtra->m_pWorldReferenceInfo = apRef;

    pExtra = new ExtraOriginalReference(apRef);
    AddExtra(pExtra);
}
}  // namespace fnv_00418550

namespace fnv_004194b0 {
class Date
{
  public:
    ~Date();
};

struct ExtraDataListRemoveTrespassPackage : public BaseExtraList
{
    void FUN_00410020(BSExtraData* extra, bool remove);
    BSExtraData* FUN_004194b0(Date* date);
};

struct FUN_00431620 : public BSExtraData
{
    Date* pDate;

    FUN_00431620(Date* date);
};

// Finds the extra data at type 0x91, replaces or deletes its stored Date, or creates and adds a new one when date is given.
// @fnv 0x004194b0
BSExtraData* ExtraDataListRemoveTrespassPackage::FUN_004194b0(Date* date)
{
    BSExtraData* pExtra = GetExtraData(0x91);

    if (pExtra)
    {
        if (!date)
        {
            FUN_00410020(pExtra, true);
            pExtra = 0;
        }
        else
        {
            delete *((Date**)((char*)pExtra + 0xc));
            *((Date**)((char*)pExtra + 0xc)) = date;
        }
    }
    else if (date)
    {
        pExtra = new FUN_00431620(date);
        AddExtra(pExtra);
    }

    return pExtra;
}
}  // namespace fnv_004194b0

extern unsigned int _data_011c16bc;

struct FUN_00431ec0 : public BSExtraData
{
    float value;

    FUN_00431ec0(float initialValue);
};

FUN_00431ec0::FUN_00431ec0(float initialValue) : value(initialValue)
{
    m_ucExtraDataType = 0x27;
}

struct FUN_00419bb0_cls : public BaseExtraList
{
    void FUN_00419bb0(float value);
};

// Sets the float at offset 0x0C of extra data type 0x27, creating and adding a new FUN_00431ec0 if none exists.
// @fnv 0x00419bb0
void FUN_00419bb0_cls::FUN_00419bb0(float value)
{
    BSExtraData* extra = GetExtraData(0x27);

    if (extra)
    {
        *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(extra) + 0x0C) = value;
    }
    else
    {
        extra = new FUN_00431ec0(value);
        AddExtra(extra);
    }
}

unsigned int _data_011c16bc;

struct FUN_00431f60 : BSExtraData
{
    float fHealthPercent;
    FUN_00431f60(float value);
};

struct FUN_00419c60_cls : BaseExtraList
{
    void FUN_00419c60(float value);
};

// Updates the float at offset 0x0C of the extra data of type 0x28, creating and adding a new FUN_00431f60 if none exists.
// @fnv 0x00419c60
void FUN_00419c60_cls::FUN_00419c60(float value)
{
    BSExtraData* extra = GetExtraData(0x28);
    if (extra)
    {
        *reinterpret_cast<float*>(reinterpret_cast<char*>(extra) + 0x0C) = value;
    }
    else
    {
        extra = new FUN_00431f60(value);
        AddExtra(extra);
    }
}

namespace fnv_0041a960 {
extern unsigned int _data_011c16bc;

struct FUN_0040fe80_shell
{
    bool HasExtraType(unsigned char type);
};

struct FUN_0041adf0_shell
{
    void RemoveExtra(unsigned char type);
};

struct FUN_004322c0 : public BSExtraData
{
    FUN_004322c0();
};

FUN_004322c0::FUN_004322c0()
{}

struct FUN_0041a960_shell : public BaseExtraList
{
    void SetGhost(bool abGhost);
};

// Adds or removes the ghost extra (type 0x1F) on this extra list so it matches abGhost.
// @fnv 0x0041a960
void FUN_0041a960_shell::SetGhost(bool abGhost)
{
    bool bHasGhost = reinterpret_cast<FUN_0040fe80_shell*>(this)->HasExtraType(0x1F);

    if (abGhost && !bHasGhost)
    {
        BaseExtraList::AddExtra(new FUN_004322c0());
    }
    else if (!abGhost && bHasGhost)
    {
        reinterpret_cast<FUN_0041adf0_shell*>(this)->RemoveExtra(0x1F);
    }
}
}  // namespace fnv_0041a960

namespace fnv_0041ae70 {
struct FUN_0041adf0_shell
{
    void RemoveExtra(unsigned char);
    void FUN_0041ae70();
};

// @fnv 0x0041ae70
void FUN_0041adf0_shell::FUN_0041ae70()
{
    RemoveExtra(0x2a);
}
}  // namespace fnv_0041ae70

struct FUN_0041b040_shell : public BaseExtraList
{
    void FUN_0041b040();
};

// @fnv 0x0041b040
void FUN_0041b040_shell::FUN_0041b040()
{
    RemoveExtra(0x3e);
}

namespace fnv_0041b080 {
struct ExtraStartingPosition : BSExtraData
{
    float x;  // +0xc
    float y;  // +0x10
    float z;  // +0x14
};

struct FUN_00418d50_shell
{
    ExtraStartingPosition* GetOrCreateStartingPosition(TESObjectREFR*);
};

struct FUN_0041b080_shell : BaseExtraList
{
    NiPoint3 FUN_0041b080(TESObjectREFR* apObject);
};

// Returns the starting position stored in extra data type 0xf, falling back to the position from GetOrCreateStartingPosition when absent.
// @fnv 0x0041b080
NiPoint3 FUN_0041b080_shell::FUN_0041b080(TESObjectREFR* apObject)
{
    ExtraStartingPosition* pExtra;
    pExtra = (ExtraStartingPosition*)GetExtraData(0xf);
    if (!pExtra)
    {
        pExtra = ((FUN_00418d50_shell*)this)->GetOrCreateStartingPosition(apObject);
    }
    return *(NiPoint3*)((char*)pExtra + 0x18);
}
}  // namespace fnv_0041b080

namespace fnv_0041b7e0 {
extern unsigned int _data_011c16bc;

struct FUN_0040ec00 : BSExtraData
{
    NiPointer<NiNode> field;

    FUN_0040ec00();
};

class GO : public NiPointer<NiNode>
{
  public:
    void operator=(void*);
};

struct FUN_0041b7e0_cls : public BaseExtraList
{
    void _FUN_00410020(BSExtraData* extra, bool remove);
    void SetNodeExtra(void* data);
};

// Gets or creates the extra-data entry of type 2 and assigns data to its NiPointer field, removing the entry first when data is null and the field is empty.
// @fnv 0x0041b7e0
void FUN_0041b7e0_cls::SetNodeExtra(void* data)
{
    BSExtraData* extra = GetExtraData(2);

    if (data == 0)
    {
        if (extra != 0 &&
            reinterpret_cast<NiPointer<NiNode>*>(reinterpret_cast<unsigned char*>(extra) + 0xc)->operator==(0))
        {
            _FUN_00410020(extra, true);
            extra = 0;
        }

        if (extra == 0)
            return;
    }

    if (extra == 0)
    {
        extra = new FUN_0040ec00;
        AddExtra(extra);
    }

    reinterpret_cast<GO*>(reinterpret_cast<unsigned char*>(extra) + 0xc)->operator=(data);
}
}  // namespace fnv_0041b7e0

namespace fnv_0041bb10 {
class GO
{
  public:
    GO(int);
    ~GO();
    operator unsigned int() const;

  private:
    unsigned int m_uiFilterValue;
};

struct FUN_0041bb10_Class : public BaseExtraList
{
    unsigned int FUN_0041bb10();
};

// Returns the GO value stored at offset 0x10 of extra data type 1, or GO(0) if that extra data is absent.
// @fnv 0x0041bb10
unsigned int FUN_0041bb10_Class::FUN_0041bb10()
{
    BSExtraData* pExtraData = GetExtraData(1);
    return pExtraData ? *reinterpret_cast<GO*>(reinterpret_cast<char*>(pExtraData) + 0x10) : GO(0);
}
}  // namespace fnv_0041bb10

namespace fnv_0041bf80 {
struct FUN_0041bf20_Class : public BSExtraData
{
  public:
    unsigned char layoutPaddingC;
    unsigned char value;
    unsigned char layoutPaddingE;
    unsigned char layoutPaddingF;

    bool FUN_0041bf20();
};

struct FUN_0041bef0 : public FUN_0041bf20_Class
{
  public:
    FUN_0041bef0();
};

struct FUN_0041bf80_Class : public BaseExtraList
{
  public:
    void FUN_0041bf80(char value);
    void _FUN_00410020(BSExtraData* extra, bool remove);
};

FUN_0041bef0::FUN_0041bef0()
{}

// @fnv 0x0041bf80
void FUN_0041bf80_Class::FUN_0041bf80(char value)
{
    BSExtraData* extra = BaseExtraList::GetExtraData(0x50);

    if (value)
    {
        if (!extra)
        {
            extra = new FUN_0041bef0;
            BaseExtraList::AddExtra(extra);
        }

        ((FUN_0041bf20_Class*)extra)->value = value;
    }
    else if (extra)
    {
        ((FUN_0041bf20_Class*)extra)->value = value;

        if (((FUN_0041bf20_Class*)extra)->FUN_0041bf20())
            _FUN_00410020(extra, true);
    }
}
}  // namespace fnv_0041bf80

namespace fnv_0041c490 {
struct NiRenderedTexture
{
};

struct _D3DLOCKED_RECT
{
    int dummy;
};

class GO
{
  public:
    void* m_pData;

    void operator=(void* pData);
};

class ExtraCellCanopyShadowMask : public BSExtraData
{
  public:
    int eState;
    GO mGO;
    _D3DLOCKED_RECT rect;
    int layoutPadding;

    ExtraCellCanopyShadowMask(int state, NiRenderedTexture* texture);
};

struct FUN_0041c490_cls : public BaseExtraList
{
    void _FUN_00410020(BSExtraData* extra, bool remove);
    void FUN_0041c490(int state, NiRenderedTexture* texture, _D3DLOCKED_RECT** outRect);
};

// @fnv 0x0041c490
void FUN_0041c490_cls::FUN_0041c490(int state, NiRenderedTexture* texture, _D3DLOCKED_RECT** outRect)
{
    ExtraCellCanopyShadowMask* pExtra = static_cast<ExtraCellCanopyShadowMask*>(GetExtraData(10));

    if (state == 0)
    {
        if (pExtra)
            _FUN_00410020(pExtra, true);
    }
    else
    {
        if (!pExtra)
        {
            pExtra = new ExtraCellCanopyShadowMask(state, texture);
            AddExtra(pExtra);
        }
        else
        {
            pExtra->eState = state;
            pExtra->mGO = texture;
        }

        *outRect = &pExtra->rect;
    }
}
}  // namespace fnv_0041c490

namespace fnv_0041c7c0 {
class GO
{
  public:
    operator unsigned int() const;
};

struct FUN_0041c7c0_Class : public BaseExtraList
{
    unsigned int FUN_0041c7c0();
};

// Retrieves extra data of type 6 and returns its value at offset 0x0c, or 0 if absent.
// @fnv 0x0041c7c0
unsigned int FUN_0041c7c0_Class::FUN_0041c7c0()
{
    BSExtraData* extra = this->GetExtraData(6);
    if (!extra)
        return 0;

    return reinterpret_cast<GO*>(reinterpret_cast<unsigned char*>(extra) + 0x0c)->operator unsigned int();
}
}  // namespace fnv_0041c7c0

namespace fnv_0041c7f0 {
extern unsigned int _data_011c16bc;

class TESSaveLoadGame
{
  public:
    bool GetLoading();
};

class SaveManager : public TESSaveLoadGame
{
};

extern SaveManager* DAT_011de45c;

struct TESObjectREFR_GetRefPersists_Standin : public TESObjectREFR
{
    bool GetReferencePersistence();
};

struct FUN_004327e0 : public BSExtraData
{
    TESObjectREFR* pRef;

    FUN_004327e0(TESObjectREFR* apRef);
};

FUN_004327e0::FUN_004327e0(TESObjectREFR* apRef)
{
    pRef = apRef;
}

struct FUN_0041c7f0_cls : public ExtraDataList
{
    void FUN_0041c7f0(TESObjectREFR* apRef);
};

// @fnv 0x0041c7f0
void FUN_0041c7f0_cls::FUN_0041c7f0(TESObjectREFR* apRef)
{
    if (!DAT_011de45c->GetLoading() && apRef != 0 &&
        !reinterpret_cast<TESObjectREFR_GetRefPersists_Standin*>(apRef)->GetReferencePersistence())
    {
        return;
    }

    FUN_004327e0* pExtra = static_cast<FUN_004327e0*>(GetExtraData(0x1c));

    if (pExtra == 0)
    {
        pExtra = new FUN_004327e0(apRef);
        AddExtra(pExtra);
    }
    else
    {
        pExtra->pRef = apRef;
    }
}
}  // namespace fnv_0041c7f0

namespace fnv_0041cc90 {
struct TrespassPackage
{
  public:
    virtual ~TrespassPackage()
    {}
    virtual void VirtualFunction0()
    {}
    virtual void VirtualFunction1()
    {}
    virtual void VirtualFunction2()
    {}
    virtual int DecRef(int count)
    {
        return count;
    }
};

struct ExtraTresPassPackage : public BSExtraData
{
  public:
    TrespassPackage* pTargetPackage;

    ExtraTresPassPackage(TrespassPackage* pack);
};

struct ExtraDataListStandIn : public BaseExtraList
{
  public:
    void SetTrespassPackage(TrespassPackage* apPack);
};

// Replaces the trespass package in the existing extra data, releasing the old one, or creates and adds a new ExtraTresPassPackage.
// @fnv 0x0041cc90
void ExtraDataListStandIn::SetTrespassPackage(TrespassPackage* apPack)
{
    ExtraTresPassPackage* pExtra = static_cast<ExtraTresPassPackage*>(GetExtraData(0x1a));

    if (pExtra)
    {
        TrespassPackage* pOldPack = pExtra->pTargetPackage;
        TrespassPackage* pPackToDecrement = pOldPack;

        (pPackToDecrement ? pPackToDecrement->DecRef(1) : 0);

        pExtra->pTargetPackage = apPack;
    }
    else
    {
        pExtra = new ExtraTresPassPackage(apPack);
        AddExtra(pExtra);
    }
}
}  // namespace fnv_0041cc90

class ExtraRagDollData : public BSExtraData
{
  public:
    void* pData;
    ExtraRagDollData();
};

struct FUN_004d9330
{
    void* storage[5];

    FUN_004d9330()
    {}

    void FUN_004d9670(void* object);
};

struct _FUN_00410020_cls
{
    void _FUN_00410020(BSExtraData* extra, bool remove);
};

class FUN_0041d5b0_class : public BaseExtraList
{
  public:
    void FUN_0041d5b0(void* object);
};

// @fnv 0x0041d5b0
void FUN_0041d5b0_class::FUN_0041d5b0(void* object)
{
    BSExtraData* extra = GetExtraData(0x14);

    if (extra)
    {
        if (!object)
        {
            reinterpret_cast<_FUN_00410020_cls*>(this)->_FUN_00410020(extra, true);
        }
        else
        {
            reinterpret_cast<FUN_004d9330*>(*reinterpret_cast<void**>(reinterpret_cast<char*>(extra) + 0xc))
                ->FUN_004d9670(object);
        }
    }
    else if (object)
    {
        extra = new ExtraRagDollData();

        *reinterpret_cast<void**>(reinterpret_cast<char*>(extra) + 0xc) = new FUN_004d9330();

        reinterpret_cast<FUN_004d9330*>(*reinterpret_cast<void**>(reinterpret_cast<char*>(extra) + 0xc))
            ->FUN_004d9670(object);

        AddExtra(extra);
    }
}

struct FUN_0041d930_shell : public BaseExtraList
{
    void FUN_0041d930();
};

// @fnv 0x0041d930
void FUN_0041d930_shell::FUN_0041d930()
{
    BaseExtraList::RemoveExtra(0x1b);
}

extern unsigned int _data_011c16bc;

struct FUN_004334b0 : BSExtraData
{
    void* m_data;

    FUN_004334b0();
};

FUN_004334b0::FUN_004334b0()
{}

struct FUN_0041e250_cls : BaseExtraList
{
    void FUN_0041e250(void* data);
};

// Stores data in the extra-data entry of type 0x3b, creating it if absent, or removes that entry when data is null.
// @fnv 0x0041e250
void FUN_0041e250_cls::FUN_0041e250(void* data)
{
    if (data)
    {
        FUN_004334b0* extra = static_cast<FUN_004334b0*>(GetExtraData(0x3b));

        if (extra)
        {
            extra->m_data = data;
        }
        else
        {
            extra = new FUN_004334b0;
            extra->m_data = data;
            AddExtra(extra);
        }
    }
    else
    {
        RemoveExtra(0x3b);
    }
}

namespace fnv_0041e7f0 {
class TESObjectREFR;

struct G2
{
    void AddHead(int*);
};

struct ExtraActivateRef : BSExtraData
{
    G2 g2;
};

struct FUN_00433a00_t
{
    int FUN_00433a00(void*);
};

struct ReferenceFloatEntry
{
    TESObjectREFR* pRef;
    int padding;

    ReferenceFloatEntry();
};

struct Extra0x53 : BSExtraData
{
    unsigned char padding[0x14];

    Extra0x53();
};

struct FUN_0041e7f0_cls : public BaseExtraList
{
    void FUN_0041e7f0(TESObjectREFR* apRef);
};

ReferenceFloatEntry::ReferenceFloatEntry()
{}

Extra0x53::Extra0x53()
{}

// @fnv 0x0041e7f0
void FUN_0041e7f0_cls::FUN_0041e7f0(TESObjectREFR* apRef)
{
    if (apRef)
    {
        ExtraActivateRef* pextra = reinterpret_cast<ExtraActivateRef*>(GetExtraData(0x53));

        if (pextra)
        {
            if (!reinterpret_cast<FUN_00433a00_t*>(pextra)->FUN_00433a00(apRef))
            {
                {
                    ReferenceFloatEntry* pdata = new ReferenceFloatEntry();
                    pdata->pRef = apRef;
                    pextra->g2.AddHead(reinterpret_cast<int*>(&pdata));
                }
            }
        }
        else
        {
            {
                pextra = reinterpret_cast<ExtraActivateRef*>(new Extra0x53());
                AddExtra(pextra);
            }

            {
                ReferenceFloatEntry* pdata = new ReferenceFloatEntry();
                pdata->pRef = apRef;
                pextra->g2.AddHead(reinterpret_cast<int*>(&pdata));
            }
        }
    }
}
}  // namespace fnv_0041e7f0

namespace fnv_0041ea30 {
struct ReferenceFloatEntry
{
    TESObjectREFR* pRef;
    float fTime;

    ReferenceFloatEntry();
};

struct G2
{
    void* pHead;
    unsigned char padding[16];

    void AddHead(int* item);
};

struct FUN_00433a00_t : public BSExtraData
{
    ReferenceFloatEntry* FUN_00433a00(void* item);
};

struct Extra0x53 : public FUN_00433a00_t
{
    G2 list;

    Extra0x53();
};

struct FUN_0041ea30_cls : public BaseExtraList
{
    void FUN_0041ea30(TESObjectREFR* apRef, float fTime);
};

// Finds or creates the 0x53 extra-data entry for apRef in the list and sets its fTime to fTime.
// @fnv 0x0041ea30
void FUN_0041ea30_cls::FUN_0041ea30(TESObjectREFR* apRef, float fTime)
{
    if (apRef)
    {
        Extra0x53* pextra = static_cast<Extra0x53*>(GetExtraData(0x53));
        ReferenceFloatEntry* pdata = 0;

        if (!pextra)
        {
            pextra = new Extra0x53();
            AddExtra(pextra);
        }
        else
        {
            pdata = pextra->FUN_00433a00(apRef);
        }

        if (!pdata)
        {
            pdata = new ReferenceFloatEntry();
            pextra->list.AddHead(reinterpret_cast<int*>(&pdata));
            pdata->pRef = apRef;
        }

        pdata->fTime = fTime;
    }
}
}  // namespace fnv_0041ea30

namespace fnv_0041faf0 {
struct BE
{
    BE(unsigned char);
};

extern int DAT_010151b4;

struct FUN_0041faf0 : BE
{
    FUN_0041faf0(void* arg);
};

// @fnv 0x0041faf0
FUN_0041faf0::FUN_0041faf0(void* arg) : BE(0x6b)
{
    *(int*)this = (int)&DAT_010151b4;
    *(void**)((char*)this + 0xc) = arg;
}
}  // namespace fnv_0041faf0

struct FUN_0067c670_shell
{
    void CallNestedMethod(void);
};

void _Deallocate(void* p);

struct FUN_0041fe60_shell
{
    void* FUN_0041fe60(unsigned int flags);
};

// Calls CallNestedMethod on this, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0041fe60
void* FUN_0041fe60_shell::FUN_0041fe60(unsigned int flags)
{
    ((FUN_0067c670_shell*)this)->CallNestedMethod();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct ExtraOcclusionPlaneRefData : BSExtraData
{
    void FUN_00420060();
    void* FUN_00420030(unsigned int flags);
};

void __cdecl _Deallocate(void* p);

// Calls FUN_00420060, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x00420030
void* ExtraOcclusionPlaneRefData::FUN_00420030(unsigned int flags)
{
    FUN_00420060();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_00420600 {
struct ExtraRoomRefData
{
    void FUN_00420630();
    void* FUN_00420600(unsigned int flags);
};

void __cdecl _Deallocate(void* p);

// @fnv 0x00420600
void* ExtraRoomRefData::FUN_00420600(unsigned int flags)
{
    FUN_00420630();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_00420600

namespace fnv_00420a60 {
struct BSMultiBoundRoom
{
};

struct LinkedReferencePair
{
    TESObjectREFR* refs[1];
};

struct BSPortal
{
};

struct StartMenu
{
    struct OptionManager
    {
        unsigned int field0;
        unsigned int field4;
        OptionManager();
    };
};

struct FUN_00420210_shell
{
    void FUN_00420210(int value);
};

struct FUN_00420410_Class
{
    LinkedReferencePair* FUN_00420410();
};

struct FUN_004208b0_Class
{
    TESObjectREFR* FUN_004208b0();
};

struct FUN_00420ed0_Class
{
    BSMultiBoundRoom* FUN_00420ed0();
};

struct Holder00420dd0
{
    unsigned int* FUN_00420dd0();
};

struct FUN_009707f0_shell
{
    void FUN_009707f0(BSMultiBoundRoom* room);
};

struct FUN_00420ba0_Class
{
    void FUN_00420ba0(BSMultiBoundRoom* room);
};

struct FUN_00420a60_Class : public ExtraDataList
{
    void FUN_00420a60(int aiWhich, TESObjectREFR* apRef);
};

// Stores apRef in the extra-data ref array at aiWhich, resolves the master room and room, and updates the portal's room for slot 0 or 1.
// @fnv 0x00420a60
void FUN_00420a60_Class::FUN_00420a60(int aiWhich, TESObjectREFR* apRef)
{
    BSMultiBoundRoom* proom;
    TESObjectREFR* pmasterRoom;
    LinkedReferencePair* pdata;
    BSPortal* pportal;

    if (!((FUN_00420410_Class*)this)->FUN_00420410() && apRef)
    {
        ((FUN_00420210_shell*)this)->FUN_00420210((int)(new StartMenu::OptionManager()));
    }

    pdata = ((FUN_00420410_Class*)this)->FUN_00420410();
    if (pdata)
    {
        pdata->refs[aiWhich] = apRef;
    }

    pportal = (BSPortal*)((Holder00420dd0*)this)->FUN_00420dd0();

    pmasterRoom = apRef ? ((FUN_004208b0_Class*)apRef->GetExtraData())->FUN_004208b0() : 0;

    if (!pmasterRoom)
    {
        pmasterRoom = apRef;
    }

    proom = pmasterRoom ? ((FUN_00420ed0_Class*)pmasterRoom->GetExtraData())->FUN_00420ed0() : 0;

    if (pportal)
    {
        if (aiWhich == 0)
        {
            ((FUN_009707f0_shell*)pportal)->FUN_009707f0(proom);
        }

        if (aiWhich == 1)
        {
            ((FUN_00420ba0_Class*)pportal)->FUN_00420ba0(proom);
        }
    }
}
}  // namespace fnv_00420a60

namespace fnv_00420fd0 {
extern unsigned int _data_011c16bc;

struct Dummy_00410020
{
    void _FUN_00410020(void* extra, bool remove);
};

struct FUN_0041fd00_shell : public BSExtraData
{
    void FUN_0041fd00(int spellID);
};

struct FUN_00421090 : public FUN_0041fd00_shell
{
    unsigned char padding[4];

    FUN_00421090();
};

struct FUN_00420fd0_cls : public BaseExtraList
{
    void FUN_00420fd0(int spellID);
};

// @fnv 0x00420fd0
void FUN_00420fd0_cls::FUN_00420fd0(int spellID)
{
    BSExtraData* extra = GetExtraData(0x72);
    if (extra)
    {
        reinterpret_cast<Dummy_00410020*>(this)->_FUN_00410020(extra, true);
    }

    if (spellID)
    {
        extra = new FUN_00421090;
        reinterpret_cast<FUN_0041fd00_shell*>(extra)->FUN_0041fd00(spellID);
        AddExtra(extra);
    }
}
}  // namespace fnv_00420fd0

namespace fnv_004210c0 {
struct CollisionData
{
    unsigned int GetType() const;
};

struct ExtraCollisionData : BSExtraData
{
    CollisionData* m_pCollisionData;  // +0x0c
    bool FUN_004210c0(BSExtraData* apCompare);
};

// Compares two ExtraCollisionData objects: returns false if both lack collision data or their types match, true otherwise.
// @fnv 0x004210c0
bool ExtraCollisionData::FUN_004210c0(BSExtraData* apCompare)
{
    ExtraCollisionData* potherExtra = (ExtraCollisionData*)apCompare;
    if (!this->m_pCollisionData && !potherExtra->m_pCollisionData)
        return false;
    if (!this->m_pCollisionData || !potherExtra->m_pCollisionData)
        return true;
    if (this->m_pCollisionData->GetType() != potherExtra->m_pCollisionData->GetType())
        return true;
    return false;
}
}  // namespace fnv_004210c0

namespace fnv_00422020 {
class GO
{
  public:
    operator unsigned int() const;
};

struct FUN_00422020_Class : public BaseExtraList
{
  public:
    unsigned int FUN_00422020();
};

// Looks up extra data of type 0x61 and returns the unsigned int stored at offset 0xC, or 0 if absent.
// @fnv 0x00422020
unsigned int FUN_00422020_Class::FUN_00422020()
{
    BSExtraData* extra = GetExtraData(0x61);
    if (extra)
    {
        return reinterpret_cast<GO*>(reinterpret_cast<unsigned char*>(extra) + 0xC)->operator unsigned int();
    }
    return 0;
}
}  // namespace fnv_00422020

struct ExtraLock
{
    void FUN_00430ca0();
    void* ReleaseIfFlagged(unsigned int flags);
};

void __cdecl _Deallocate(void* p);

// Calls FUN_00430ca0, deallocates this when flags has bit 1 set, and returns this.
// @fnv 0x0042c550
void* ExtraLock::ReleaseIfFlagged(unsigned int flags)
{
    FUN_00430ca0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_0042c890 {
struct ExtraTresPassPackage
{
    void FUN_00432900();
    void* FUN_0042c890(unsigned int flags);
};

void __cdecl _Deallocate(void* ptr);

// @fnv 0x0042c890
void* ExtraTresPassPackage::FUN_0042c890(unsigned int flags)
{
    this->FUN_00432900();

    if (flags & 1)
        _Deallocate(this);

    return this;
}
}  // namespace fnv_0042c890

namespace fnv_0042c9f0 {
struct BE
{
    BE(unsigned char a);
};

extern int DAT_01015980;

struct FUN_0042c9f0 : BE
{
    FUN_0042c9f0();
};

// Initializes the object: sets the vtable pointer to DAT_01015980 and zeroes the fields at offsets 0xC and 0x10.
// @fnv 0x0042c9f0
FUN_0042c9f0::FUN_0042c9f0() : BE(0x5B)
{
    *(int*)this = (int)&DAT_01015980;
    *(int*)((char*)this + 0xC) = 0;
    *(int*)((char*)this + 0x10) = 0;
}
}  // namespace fnv_0042c9f0

namespace fnv_0042e450 {
struct BE
{
    BE(unsigned char);

    int* vptr;
    unsigned char padding[8];
    unsigned char value;
};

extern int DAT_010159a4;

struct FUN_0042e450 : public BE
{
    FUN_0042e450(unsigned char);
};

BE::BE(unsigned char)
{}

// Initializes the base with 0x8d, sets the vtable pointer to DAT_010159a4 and stores aValue in value.
// @fnv 0x0042e450
FUN_0042e450::FUN_0042e450(unsigned char aValue) : BE(0x8d)
{
    vptr = &DAT_010159a4;
    value = aValue;
}
}  // namespace fnv_0042e450

extern unsigned int _data_011c16bc;

struct TESLeveledList : public BSExtraData
{
    void FUN_0042e680(unsigned char type);
};

struct FUN_0042cc40 : public TESLeveledList
{
    int layoutPadding;
    FUN_0042cc40();
};

FUN_0042cc40::FUN_0042cc40()
{}

struct FUN_0042e4a0_owner : public BaseExtraList
{
    void EnsureLeveledListExtra(unsigned char type);
};

// @fnv 0x0042e4a0
void FUN_0042e4a0_owner::EnsureLeveledListExtra(unsigned char type)
{
    TESLeveledList* extra = static_cast<TESLeveledList*>(GetExtraData(0x8d));

    if (!extra)
    {
        extra = new FUN_0042cc40;
        extra->FUN_0042e680(type);
        AddExtra(extra);
    }
    else
    {
        extra->FUN_0042e680(type);
    }
}

struct FUN_0042ca90 : public BSExtraData
{
    int value;

    FUN_0042ca90();
    void FUN_0042ea00(int value);
};

FUN_0042ca90::FUN_0042ca90()
{
    m_ppVirtualMethodTable = 0;
    m_ucExtraDataType = 0x60;
    layoutPadding5 = 0;
    layoutPadding6 = 0;
    pNext = 0;
    value = 0;
}

void FUN_0042ca90::FUN_0042ea00(int value)
{
    this->value = value;
}

struct FUN_0042e930_shell : public BaseExtraList
{
    void RemoveExtra(unsigned char type);
    void FUN_0042e930(int value);
};

// Sets the 0x60 extra data's value, removing the extra when value is 0, updating it if present, otherwise creating and adding it.
// @fnv 0x0042e930
void FUN_0042e930_shell::FUN_0042e930(int value)
{
    if (value == 0)
    {
        RemoveExtra(0x60);
        return;
    }

    BSExtraData* extra = GetExtraData(0x60);
    if (extra != 0)
    {
        static_cast<FUN_0042ca90*>(extra)->FUN_0042ea00(value);
        return;
    }

    extra = new FUN_0042ca90;
    static_cast<FUN_0042ca90*>(extra)->FUN_0042ea00(value);
    AddExtra(extra);
}

extern unsigned int _data_011c16bc;

struct FUN_0042eb10 : public BSExtraData
{
    void* m_uiFilterValue;
    FUN_0042eb10(void* value);
};

struct FUN_0042ea50_cls : public BaseExtraList
{
    void RemoveExtra(unsigned char type);
    void FUN_0042ea50(void* value);
};

// Stores value in the extra data of type 0x69, removing that extra when value is null and creating a new one if absent.
// @fnv 0x0042ea50
void FUN_0042ea50_cls::FUN_0042ea50(void* value)
{
    if (!value)
    {
        this->RemoveExtra(0x69);
        return;
    }

    BSExtraData* extra = this->GetExtraData(0x69);
    if (extra)
    {
        *((void**)((char*)extra + 0x0C)) = value;
        return;
    }

    extra = new FUN_0042eb10(value);
    this->AddExtra(extra);
}

namespace fnv_0042eb10 {
struct BE
{
    BE(unsigned char);
};

extern int DAT_010159c8;

struct FUN_0042eb10 : BE
{
    FUN_0042eb10(void* arg);
};

// Constructs a BE with tag 0x69, sets the vtable pointer to DAT_010159c8 and stores arg at offset 0xc.
// @fnv 0x0042eb10
FUN_0042eb10::FUN_0042eb10(void* arg) : BE(0x69)
{
    *(void**)this = &DAT_010159c8;
    *(void**)((char*)this + 0xc) = arg;
}
}  // namespace fnv_0042eb10

extern unsigned int _data_011c16bc;

struct FUN_00437750 : public BSExtraData
{
    unsigned char padding0C[0x10];
    void* pTarget;

    FUN_00437750();
    void UpdatePriorityEntry(TESForm* form, bool flag);
};

struct FUN_0042f030_cls : public BaseExtraList
{
    void _FUN_00410020(BSExtraData* extra, bool remove);
    unsigned int FUN_0042f030(TESForm* form, bool flag);
};

// Gets or creates the 0x7e extra data, applies form and flag to it, removes it if its stored form ID is zero, and returns the target's form ID.
// @fnv 0x0042f030
unsigned int FUN_0042f030_cls::FUN_0042f030(TESForm* form, bool flag)
{
    FUN_00437750* pExtraData = (FUN_00437750*)this->GetExtraData(0x7e);

    if (!pExtraData)
    {
        pExtraData = new FUN_00437750;
        this->AddExtra(pExtraData);
    }

    pExtraData->UpdatePriorityEntry(form, flag);

    if (!reinterpret_cast<TESForm*>(reinterpret_cast<char*>(pExtraData) + 0xc)->GetFormID())
    {
        this->_FUN_00410020(pExtraData, true);
        return 0;
        goto L_end;
    }

    return pExtraData->pTarget
               ? reinterpret_cast<TESForm*>(reinterpret_cast<char*>(pExtraData->pTarget) + 4)->GetFormID()
               : 0;

L_end:;
}

struct ATM
{
    void QueryPerformanceCounter(int);
    void WaitForTasksDuringRendering();
};

struct GlobalObject_0044fae0 : ATM
{
};

struct GlobalObject_0045cfe0
{
    int* Int();
};

extern GlobalObject_0044fae0 g_011c3d84;
extern GlobalObject_0045cfe0 g_011c3ea4;

struct ActorTaskManager
{
    void FUN_00453860(bool);
};

// If the global int is not 1, either queries the performance counter or waits for rendering tasks depending on flag.
// @fnv 0x00453860
void ActorTaskManager::FUN_00453860(bool abQueryCounter)
{
    if (*g_011c3ea4.Int() != 1)
    {
        if (abQueryCounter)
            g_011c3d84.QueryPerformanceCounter(0);
        else
            g_011c3d84.WaitForTasksDuringRendering();
    }
}

namespace fnv_0047f940 {
class FormChangeMask
{
  public:
    operator bool() const;

  private:
    int value;
};

class BGSLoadFormBuffer
{
  public:
    FormChangeMask GetChangeFlags(int flags);
};

class BGSSaveFormBuffer : public BGSLoadFormBuffer
{
  public:
    void SaveData(void* data, int a, int b);
};

class BGSChangeHandler
{
  public:
    void SaveChangeData(BGSSaveFormBuffer* buffer);
};

// If the buffer's change flags include bit 8, saves 0x14 bytes from this+4 into the buffer.
// @fnv 0x0047f940
void BGSChangeHandler::SaveChangeData(BGSSaveFormBuffer* buffer)
{
    if (buffer->GetChangeFlags(8))
    {
        buffer->SaveData(reinterpret_cast<char*>(this) + 4, 0x14, 0);
    }
}
}  // namespace fnv_0047f940

namespace fnv_0047f980 {
class FormChangeMask
{
  public:
    operator bool() const;

  private:
    unsigned int value;
};

class BGSLoadFormBuffer
{
  public:
    FormChangeMask GetChangeFlags(unsigned int flags);
    void ReadTypedData(void* data, unsigned int size);
};

struct FUN_0047f980_Class
{
    void FUN_0047f980(BGSLoadFormBuffer* buffer);
};

// @fnv 0x0047f980
void FUN_0047f980_Class::FUN_0047f980(BGSLoadFormBuffer* buffer)
{
    if (buffer->GetChangeFlags(8))
    {
        buffer->ReadTypedData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 4), 0x14);
    }
}
}  // namespace fnv_0047f980

namespace fnv_004802b0 {
class FormChangeMask
{
  public:
    operator bool(void) const;

  private:
    unsigned int m_uiFilterValue;
};

class BGSLoadFormBuffer
{
  public:
    FormChangeMask GetChangeFlags(unsigned int);
    void ReadTypedData(void*, unsigned int);
};

struct FUN_004802b0_Class
{
    int m_field0;
    int m_data;

    void LoadDataIfChanged(BGSLoadFormBuffer*);
};

// @fnv 0x004802b0
void FUN_004802b0_Class::LoadDataIfChanged(BGSLoadFormBuffer* pLoadBuffer)
{
    if (pLoadBuffer->GetChangeFlags(4).operator bool())
        pLoadBuffer->ReadTypedData(&m_data, 7);
}
}  // namespace fnv_004802b0

namespace fnv_004121e0 {
extern RecursiveSpinLock g_011c3920;

class PatrolActorPackageData
{
  public:
    unsigned char IsPatrolling();
};

class Crime
{
  public:
    TESObjectREFR* GetTarget();
};

class ExtraDataListCopyListForContainer
{
  public:
    void FUN_004103d0(BSExtraData* data);
    void _FUN_00410020(BSExtraData* data, bool remove);
    void FUN_004121e0(ExtraDataList* copy, bool dontRemove);
};

// Locks g_011c3920, walks the extra-data list of copy, copies selected entries and optionally removes them, then unlocks.
// @fnv 0x004121e0
void ExtraDataListCopyListForContainer::FUN_004121e0(ExtraDataList* copy, bool dontRemove)
{
    BSExtraData* work;
    bool bHasResultObj;

    g_011c3920.Lock("ExtraDataList::CopyListForContainer()");

    work = *reinterpret_cast<BSExtraData**>(reinterpret_cast<char*>(copy) + 4);

    while (work)
    {
        bHasResultObj = true;

        switch (reinterpret_cast<PatrolActorPackageData*>(work)->IsPatrolling())
        {
        case 22:
        case 23:
        case 28:
        case 33:
        case 34:
        case 35:
        case 37:
        case 38:
        case 39:
        case 40:
        case 47:
        case 48:
        case 63:
        case 71:
        case 74:
        case 141:
            FUN_004103d0(work);

            if (reinterpret_cast<PatrolActorPackageData*>(work)->IsPatrolling() != 0x30 && !dontRemove)
            {
                reinterpret_cast<ExtraDataListCopyListForContainer*>(copy)->_FUN_00410020(work, true);

                work = *reinterpret_cast<BSExtraData**>(reinterpret_cast<char*>(copy) + 4);
                bHasResultObj = false;
            }
            break;

        case 13:
            FUN_004103d0(work);

            if (!dontRemove)
            {
                reinterpret_cast<ExtraDataListCopyListForContainer*>(copy)->_FUN_00410020(work, false);

                work = *reinterpret_cast<BSExtraData**>(reinterpret_cast<char*>(copy) + 4);
                bHasResultObj = false;
            }
            break;
        }

        if (work && bHasResultObj)
            work = reinterpret_cast<BSExtraData*>(reinterpret_cast<Crime*>(work)->GetTarget());
    }

    g_011c3920.Unlock();
}
}  // namespace fnv_004121e0

namespace fnv_00412380 {
class PatrolActorPackageData
{
  public:
    unsigned char IsPatrolling();
};

class Crime
{
  public:
    TESObjectREFR* GetTarget();
};

extern RecursiveSpinLock g_011c3920;

struct FUN_00412380_shell
{
  public:
    void FUN_004103d0(BSExtraData*);
    void FUN_00412380(ExtraDataList* apCopy);
};

// Locks g_011c3920, walks the extra-data list of apCopy and calls FUN_004103d0 on entries whose type is in a fixed set, then unlocks.
// @fnv 0x00412380
void FUN_00412380_shell::FUN_00412380(ExtraDataList* apCopy)
{
    g_011c3920.Lock("ExtraDataList::DuplicateExtraListForContainer()");

    BSExtraData* work = reinterpret_cast<BSExtraData**>(reinterpret_cast<char*>(apCopy) + 4)[0];

    while (work)
    {
        switch (reinterpret_cast<PatrolActorPackageData*>(work)->IsPatrolling())
        {
        case 13:
        case 22:
        case 23:
        case 28:
        case 33:
        case 34:
        case 35:
        case 36:
        case 37:
        case 38:
        case 39:
        case 40:
        case 47:
        case 48:
        case 63:
        case 71:
        case 74:
        case 141:
            FUN_004103d0(work);
            break;
        }

        work = reinterpret_cast<BSExtraData*>(reinterpret_cast<Crime*>(work)->GetTarget());
    }

    g_011c3920.Unlock();
}
}  // namespace fnv_00412380

struct XData
{
    virtual void* Dtor(unsigned int);
    int pad4;
    XData* next;
    unsigned char GetType();
    void SetNext(XData*);
};
struct XList;
struct XLock
{
    void Enter(const char*);
    void Leave();
};
extern XLock DAT_011c3920;
void __cdecl ResetTlsBufferIfListMatches(XList*);
struct XList
{
    void* vt;
    XData* head;
    void SetBitFlag(unsigned char, int);
    void FUN_0040fcb0(bool del);
};
// Locks the list, calls ResetTlsBufferIfListMatches, then unlinks and optionally deletes every entry whose type is not one of the default types, and unlocks.
// @fnv 0x0040fcb0
void XList::FUN_0040fcb0(bool abDelete)
{
    DAT_011c3920.Enter("BaseExtraList::RemoveAllDefault()");
    ResetTlsBufferIfListMatches(this);
    XData* prev;
    XData* cur = head;
    prev = 0;
    while (cur)
    {
        unsigned char t_2 = cur->GetType();
        bool rem5 = true;
        switch (t_2)
        {
        case 0x2e:
        case 0x38:
        case 0x4f:
        case 0x52:
        case 0x54:
        case 0x58:
        case 0x65:
        case 0x7b:
        case 0x84:
            rem5 = false;
            break;
        }
        XData* nx = cur->next;
        if (rem5)
        {
            if (prev)
                prev->SetNext(nx);
            else
                head = nx;
            if (abDelete)
            {
                XData* d;
                XData* tmp4 = cur;
                d = tmp4;
                d ? d->Dtor(1) : 0;
            }
            SetBitFlag(t_2, 0);
        }
        else
            prev = cur;
        cur = nx;
    }
    DAT_011c3920.Leave();
}

struct Base_40ec80
{
    virtual ~Base_40ec80();
    int unk04;
    int unk08;
    Base_40ec80(unsigned char acType);
};

struct List_96a2d0
{
    List_96a2d0();
};

struct FUN_00411c80 : public Base_40ec80
{
    List_96a2d0 list;
    FUN_00411c80();
    virtual ~FUN_00411c80();
};

// Constructs the object, initializing its base with type 0x84 and default-constructing the embedded list.
// @fnv 0x00411c80
FUN_00411c80::FUN_00411c80() : Base_40ec80(0x84)
{}

extern int DAT_0101444c;

struct ExtraBaseConstructor
{
    ExtraBaseConstructor(unsigned char type);
    ~ExtraBaseConstructor();
};

struct ExtraPayloadConstructor
{
    ExtraPayloadConstructor();
};

struct FUN_00411d20 : ExtraBaseConstructor
{
    void* vtable;
    unsigned char extraType;
    unsigned char reserved05;
    unsigned short reserved06;
    void* next;
    ExtraPayloadConstructor payload;

    FUN_00411d20();
};

// Initializes the object's base with type 0x85 and sets its vtable pointer to DAT_0101444c.
// @fnv 0x00411d20
FUN_00411d20::FUN_00411d20() : ExtraBaseConstructor(0x85), vtable(&DAT_0101444c)
{}

struct FUN_00411e00Class
{
    int value;

    void* FUN_00411e00();
};

// @fnv 0x00411e00
void* FUN_00411e00Class::FUN_00411e00()
{
    value = 0x16;
    return this;
}

struct FUN_00416b80
{
    BSSimpleList<void*> list1;
    BSSimpleList<void*> list2;
    FUN_00416b80();
};

// Initializes the two BSSimpleList members of the object; the constructor body is empty.
// @fnv 0x00416b80
FUN_00416b80::FUN_00416b80()
{}

struct FUN_004184f0_holder
{
    int unk00;
    int unk04;
    int unk08;
    int m_0c;
};

struct FUN_004184f0_cls
{
    int unk00;
    int unk04;

    FUN_004184f0_holder* Lookup(int key);
    int GetEntryValue();
};

// Looks up key 0x91 and returns the holder's m_0c field, or 0 if not found.
// @fnv 0x004184f0
int FUN_004184f0_cls::GetEntryValue()
{
    FUN_004184f0_holder* p = Lookup(0x91);
    if (p != 0)
    {
        return p->m_0c;
    }
    return 0;
}

class FUN_00418600_cls
{
  public:
    void* CreateObject(int size);
    void AttachObject(void* obj, int flag);
    void FUN_00418600();
};

// Allocates a 0x20-byte object via CreateObject and, if allocation succeeds, attaches it with flag 1.
// @fnv 0x00418600
void FUN_00418600_cls::FUN_00418600()
{
    void* obj = CreateObject(0x20);
    if (obj != 0)
    {
        AttachObject(obj, 1);
    }
}

extern float DAT_01012054;

struct ExtraValueElem
{
    void* unk00;
    void* unk04;
    void* unk08;
    float m_fValue;
};

struct OwnerList
{
    ExtraValueElem* FUN_00410220(unsigned char type);
    float GetValue();
};

// Looks up the element of type 0x28 and returns its m_fValue, or DAT_01012054 if none exists.
// @fnv 0x004187a0
float OwnerList::GetValue()
{
    ExtraValueElem* pElem = this->FUN_00410220(0x28);
    if (pElem != 0)
    {
        return pElem->m_fValue;
    }
    else
    {
        return DAT_01012054;
    }
}

struct B18A40Extra
{
    int unk00;
    int unk04;
    int unk08;
    int m_kData;
};

class B18A40Value
{
  public:
    void Set(const void* pvData);
    void Reset();
};

class B18A40ExtraList
{
  public:
    B18A40Extra* GetExtraData(unsigned char ucType);
    void SetValueFromExtraData(B18A40Value* pkValue);
};

// Looks up extra data of type 0x87; if found, sets pkValue from its m_kData, otherwise resets pkValue.
// @fnv 0x00418a40
void B18A40ExtraList::SetValueFromExtraData(B18A40Value* pkValue)
{
    B18A40Extra* pkExtra = GetExtraData(0x87);
    if (pkExtra)
        pkValue->Set(&pkExtra->m_kData);
    else
        pkValue->Reset();
}

struct C418C00ExtraData
{
    bool Check(bool bFlag);
};

struct C418C00ExtraList
{
    int unk00;

    C418C00ExtraData* GetByType(unsigned char ucType);
    bool CheckExtraByType(bool bFlag);
};

// Looks up the extra-data entry of type 0x8d and returns its Check result, or false if none exists.
// @fnv 0x00418c00
bool C418C00ExtraList::CheckExtraByType(bool bFlag)
{
    C418C00ExtraData* pkExtra = GetByType(0x8d);
    if (!pkExtra)
        return false;
    else
        return pkExtra->Check(bFlag);
}

struct Payload_00418c40
{
    ~Payload_00418c40();
};

struct ExtraHolder_00418c40 : public BSExtraData
{
    Payload_00418c40* pData;
    ExtraHolder_00418c40(Payload_00418c40* data);
};

struct FUN_00418c40_shell : public ExtraDataList
{
    ExtraHolder_00418c40* FUN_00418c40(Payload_00418c40* data);
};

// Replaces the payload of the extra data at type 0x10, creating and adding a new holder if none exists, and returns the holder.
// @fnv 0x00418c40
ExtraHolder_00418c40* FUN_00418c40_shell::FUN_00418c40(Payload_00418c40* data)
{
    ExtraHolder_00418c40* extra = static_cast<ExtraHolder_00418c40*>(GetExtraData(0x10));
    if (extra)
    {
        delete extra->pData;
        extra->pData = data;
        return extra;
    }

    extra = new ExtraHolder_00418c40(data);
    AddExtra(extra);
    return extra;
}

struct OldReference
{
    ~OldReference();
};
struct ExtraReference : BSExtraData
{
    OldReference* reference;
    ExtraReference(OldReference* value);
    void FUN_004f15a0(unsigned int extraType);
};
struct FUN_00418f60_shell : ExtraDataList
{
    ExtraReference* FUN_00418f60(OldReference* replacement);
};
// Finds the 0x40 extra data, replaces its reference with the given one, or creates and adds a new ExtraReference if absent; returns it.
// @fnv 0x00418f60
ExtraReference* FUN_00418f60_shell::FUN_00418f60(OldReference* apReference)
{
    ExtraReference* extra = static_cast<ExtraReference*>(GetExtraData(0x40));
    if (extra != 0)
    {
        delete extra->reference;
        extra->reference = apReference;
        return extra;
    }
    extra = new ExtraReference(apReference);
    extra->FUN_004f15a0(0x40);
    AddExtra(extra);
    return extra;
}

struct Extra2A_419050 : public BSExtraData
{
    void* pData;
    Extra2A_419050(void* apData);
};

struct ExtraList_419050 : public BaseExtraList
{
    Extra2A_419050* FUN_00419050(void* apData);
};

// Finds the 0x2a extra, replaces its pData with apData, or creates and adds a new one; returns the extra.
// @fnv 0x00419050
Extra2A_419050* ExtraList_419050::FUN_00419050(void* apData)
{
    Extra2A_419050* p = (Extra2A_419050*)GetExtraData(0x2a);
    if (p)
    {
        delete p->pData;
        p->pData = apData;
        return p;
    }
    p = new Extra2A_419050(apData);
    AddExtra(p);
    return p;
}

struct Vec3
{
    int x;
    int y;
    int z;
};

struct FUN_0041b0d0_cls
{
    int unk00;
    int unk04;

    void* GetPrimary(int which);
    void* GetFallback(int param);
    Vec3* FUN_0041b0d0(Vec3* out, int param);
};

// Gets the primary object for slot 0xf, falls back to GetFallback(param) if null, and copies the Vec3 at offset 0xc into out.
// @fnv 0x0041b0d0
Vec3* FUN_0041b0d0_cls::FUN_0041b0d0(Vec3* out, int param)
{
    void* p = GetPrimary(0xf);
    if (p == 0)
    {
        p = GetFallback(param);
    }
    *out = *(Vec3*)((char*)p + 0xc);
    return out;
}

struct B41B120StartingPosition : public BSExtraData
{
    int unk0C;
    int unk10;
    int unk14;
    NiPoint3 m_kPathOffset;
};

class B41B120ExtraList : public ExtraDataList
{
  public:
    B41B120StartingPosition* GetOrCreateStartingPosition(TESObjectREFR* pkRef);
    NiPoint3 SetStartingPosition(TESObjectREFR* pkRef, NiPoint3 kPosition);
};

// Stores kPosition into the extra data's position field, creating the extra data via GetOrCreateStartingPosition if absent, and returns kPosition.
// @fnv 0x0041b120
NiPoint3 B41B120ExtraList::SetStartingPosition(TESObjectREFR* pkRef, NiPoint3 kPosition)
{
    B41B120StartingPosition* pkExtra = static_cast<B41B120StartingPosition*>(GetExtraData(0xF));
    if (!pkExtra)
        pkExtra = GetOrCreateStartingPosition(pkRef);
    pkExtra->m_kPathOffset = kPosition;
    return kPosition;
}

struct Str580
{
    operator const char*() const;
};
struct Ex580 : BSExtraData
{
    unsigned int unk0C;
    Str580 unk10;
    unsigned int unk14;
};
struct Hold580 : BaseExtraList
{
    unsigned int GetExtraDataNameAndPtr(const char** outName, unsigned int** outPtr);
};
// Looks up extra data of type 10; if present, writes its name and a pointer to its field into the out params and returns its unk0C value, else returns 0.
// @fnv 0x0041c580
unsigned int Hold580::GetExtraDataNameAndPtr(const char** outName, unsigned int** outPtr)
{
    Ex580* p = static_cast<Ex580*>(GetExtraData(10));
    *outName = 0;
    *outPtr = 0;
    if (!p)
    {
        return 0;
    }
    *outName = p->unk10;
    *outPtr = &p->unk14;
    return p->unk0C;
}

struct FUN_0041c5e0_base_cls
{
    virtual void unk00();
    int m_04;
    int m_08;
    FUN_0041c5e0_base_cls(unsigned char t);
    ~FUN_0041c5e0_base_cls();
};

struct FUN_0041c5e0_str_cls
{
    int m_00;
    FUN_0041c5e0_str_cls();
    ~FUN_0041c5e0_str_cls();
    bool Set(const char* s, unsigned int n);
};

struct FUN_0041c5e0_cls : FUN_0041c5e0_base_cls
{
    FUN_0041c5e0_str_cls str;
    FUN_0041c5e0_cls(const char* s);
};

// Initializes the base with 6 and constructs str, then sets str from s with length 0.
// @fnv 0x0041c5e0
FUN_0041c5e0_cls::FUN_0041c5e0_cls(const char* apString) : FUN_0041c5e0_base_cls(6), str()
{
    str.Set(apString, 0);
}

class FUN_0041c900_cls
{
  public:
    void* CreateObject(int size);
    void AttachObject(void* obj, int flag);
    void FUN_0041c900();
};

// @fnv 0x0041c900
void FUN_0041c900_cls::FUN_0041c900()
{
    void* obj = CreateObject(0x1c);
    if (obj != 0)
    {
        AttachObject(obj, 1);
    }
}

struct Package_0041c930
{
    bool FUN_00674d40();
    int FUN_0041ca90();
    bool FUN_00674e40();
};
struct Extra_00432870 : public BSExtraData
{
    Package_0041c930* pPackage;
    unsigned int packageArgument;
    unsigned int packageOptions;
    unsigned char flag1;
    unsigned char flag2;
    unsigned char flag3;
    unsigned char pad1B;
    Extra_00432870(Package_0041c930*, unsigned int, unsigned int, unsigned char, unsigned char, unsigned char);
};
struct FUN_0041c930_shell : public ExtraDataList
{
    void FUN_0041cc60();
    void FUN_0041c930(Package_0041c930*, unsigned int, unsigned int, unsigned char, unsigned char, unsigned char);
};
// @fnv 0x0041c930
void FUN_0041c930_shell::FUN_0041c930(Package_0041c930* package, unsigned int value, unsigned int options,
                                      unsigned char flag1, unsigned char flag2, unsigned char flag3)
{
    if (package != 0 && ((package->FUN_00674d40() && package->FUN_0041ca90() != 1) || package->FUN_00674e40() ||
                         package->FUN_0041ca90() == 0x18 || package->FUN_0041ca90() == 0x17))
    {
        return;
    }
    Extra_00432870* extra = static_cast<Extra_00432870*>(GetExtraData(0x19));
    if (package != 0)
    {
        if (extra == 0)
        {
            extra = new Extra_00432870(package, value, options, flag1, flag2, flag3);
            AddExtra(extra);
        }
        else
        {
            extra->pPackage = package;
            extra->packageArgument = value;
            extra->packageOptions = options;
            extra->flag1 = flag1;
            extra->flag2 = flag2;
            extra->flag3 = flag3;
        }
    }
    else if (extra != 0)
    {
        FUN_0041cc60();
    }
}

struct FUN_0041cb40_extra
{
    BSExtraData base;
    void* unk0C;
    void* unk10;
};

struct FUN_0041cb40_shell : public ExtraDataList
{
    void* FUN_0041cb40();
};

// Returns the unk10 value of the extra data entry with type 0x19, or null if it is absent.
// @fnv 0x0041cb40
void* FUN_0041cb40_shell::FUN_0041cb40()
{
    BSExtraData* pExtra = GetExtraData(0x19);

    if (pExtra)
    {
        return reinterpret_cast<FUN_0041cb40_extra*>(pExtra)->unk10;
    }
    else
    {
        return 0;
    }
}

class FUN_0041cba0_class
{
  public:
    void* FUN_00410220(int);
    char FUN_0041cba0();
};

// Calls FUN_00410220 with 0x19 and returns the char at offset 0x18 of the result, or 0 if null.
// @fnv 0x0041cba0
char FUN_0041cba0_class::FUN_0041cba0()
{
    void* p = FUN_00410220(0x19);
    if (p)
        return *(char*)((char*)p + 0x18);
    else
        return 0;
}

// FUN_0041cc00 : ExtraDataList helper.
//
// Looks up the extra data record of type 0x19 on `this` and returns the
// boolean flag stored at offset 0x19 of that record (0 when the record is
// missing).  The lookup helper is not part of the published pack, so a
// stand-in member with the same shape is used (the checker binds callees by
// position).

struct ExtraFlagData
{
    void** m_ppVirtualMethodTable;
    unsigned char m_ucExtraDataType;
    unsigned char layoutPadding5;
    unsigned short layoutPadding6;
    BSExtraData* pNext;
    int unk0C;
    int unk10;
    int unk14;
    unsigned char unk18;
    unsigned char bFlag;
};

struct FUN_0041cc00_cls : public BaseExtraList
{
    ExtraFlagData* GetExtraDataByType(unsigned char type);
    unsigned char FUN_0041cc00();
};

// Looks up the extra data of type 0x19 and returns its bFlag byte, or 0 if it is absent.
// @fnv 0x0041cc00
unsigned char FUN_0041cc00_cls::FUN_0041cc00()
{
    ExtraFlagData* pExtra = GetExtraDataByType(0x19);
    if (pExtra != 0)
    {
        return pExtra->bFlag;
    }
    else
    {
        return 0;
    }
}

class Unit_59097dfe3b9e
{
  public:
    char GetByteAtOffset26();
    int FUN_00410220(int arg);
};

// Reads a value via FUN_00410220(0x19) and returns the byte at offset 0x1a, or 0 if the value is null.
// @fnv 0x0041cc30
char Unit_59097dfe3b9e::GetByteAtOffset26()
{
    int value = FUN_00410220(0x19);
    if (value)
        return *(char*)(value + 0x1a);
    else
        return 0;
}

// FUN_0041cc60: looks up the extra data of type 0x19 on the list and,
// if it is present, hands it to the list for further processing.
struct FUN_0041cc60_cls
{
    void* FUN_00410220(int code);
    void FUN_00410020(void* extra, bool flag);
    void FUN_0041cc60();
};

// @fnv 0x0041cc60
void FUN_0041cc60_cls::FUN_0041cc60()
{
    void* pExtra = this->FUN_00410220(0x19);
    if (pExtra != 0)
    {
        this->FUN_00410020(pExtra, true);
    }
}

struct Extra00432aa0 : public BSExtraData
{
    void* pList;
    Extra00432aa0(void* item);
};

struct ListHelper
{
    void AddHead(void*& item);
};

struct BaseExtraList_shell : public BaseExtraList
{
    void AddOrCreateExtraItem(void* item, int unused);
};

// Gets the extra data of type 0x35; if absent creates it from item and adds it, otherwise inserts item at the head of its list.
// @fnv 0x0041ce50
void BaseExtraList_shell::AddOrCreateExtraItem(void* item, int unused)
{
    Extra00432aa0* pExtra = (Extra00432aa0*)GetExtraData(0x35);
    if (!pExtra)
    {
        pExtra = new Extra00432aa0(item);
        AddExtra(pExtra);
    }
    else
    {
        ((ListHelper*)pExtra->pList)->AddHead(item);
    }
}

struct ExtraData_0x2f : public BSExtraData
{
    int unk0C;
};

struct FUN_0041d360_shell : public ExtraDataList
{
    int FUN_0041d360();
};

// Returns unk0C from the extra data of type 0x2f, or -1 if it is absent.
// @fnv 0x0041d360
int FUN_0041d360_shell::FUN_0041d360()
{
    ExtraData_0x2f* pExtra = (ExtraData_0x2f*)GetExtraData(0x2f);
    if (pExtra)
    {
        return pExtra->unk0C;
    }
    else
    {
        return -1;
    }
}

struct FUN_0041db30_Class
{
    bool IsFlagSet();
};

struct FUN_00410220_Class
{
    FUN_0041db30_Class* GetExtraData(unsigned char);
};

struct FUN_0041db00_Class
{
    bool FUN_0041db00();
};

FUN_0041db30_Class* FUN_00410220_Class::GetExtraData(unsigned char)
{
    return 0;
}

bool FUN_0041db30_Class::IsFlagSet()
{
    return false;
}

// @fnv 0x0041db00
bool FUN_0041db00_Class::FUN_0041db00()
{
    FUN_0041db30_Class* extra = ((FUN_00410220_Class*)this)->GetExtraData(0x37);
    if (extra != 0)
    {
        return extra->IsFlagSet();
    }
    return false;
}

namespace fnv_0041dbd0 {
struct FUN_0041dc00_Class
{
    bool IsFlag2Set();
};

struct FUN_00410220_Class
{
    FUN_0041dc00_Class* GetExtraData(unsigned char);
};

struct FUN_0041dbd0_Class
{
    bool FUN_0041dbd0();
};

FUN_0041dc00_Class* __thiscall FUN_00410220_Class::GetExtraData(unsigned char)
{
    return 0;
}

bool __thiscall FUN_0041dc00_Class::IsFlag2Set()
{
    return false;
}

// @fnv 0x0041dbd0
bool __thiscall FUN_0041dbd0_Class::FUN_0041dbd0()
{
    FUN_0041dc00_Class* extra = ((FUN_00410220_Class*)this)->GetExtraData(0x37);
    if (extra != 0)
    {
        return extra->IsFlag2Set();
    }
    return false;
}
}  // namespace fnv_0041dbd0

// FUN_0041dc20: looks up extra data of type 0x37 and reports its flag bit.
struct S_0041dc50_Cls
{
    bool IsFlag4Set();
};

// Stand-in for the class owning FUN_00410220 (the type-lookup helper).
struct S_0041dc20_Cls
{
    S_0041dc50_Cls* FUN_00410220(unsigned char type);
    bool FUN_0041dc20();
};

// Looks up extra data of type 0x37 via FUN_00410220 and returns the result of IsFlag4Set on it, or false if absent.
// @fnv 0x0041dc20
bool S_0041dc20_Cls::FUN_0041dc20()
{
    S_0041dc50_Cls* pExtra = this->FUN_00410220(0x37);
    if (pExtra)
    {
        return pExtra->IsFlag4Set();
    }
    return false;
}

// ExtraDataList: add an item to the type-0x3A extra's list, creating that extra on first use.

void* __cdecl operator new(unsigned int uiSize);

class E000Item;

class E000ItemList
{
  public:
    bool IsInList(E000Item* const& rpkItem) const;
    void AddHead(E000Item* const& rpkItem);
    E000Item* m_item;
    void* m_pkNext;
};

class E000Extra
{
  public:
    void* m_pVtbl;
    unsigned char m_ucType;
    E000Extra* m_pkNext;
};

class E000ExtraItemList : public E000Extra
{
  public:
    E000ExtraItemList();
    E000ItemList m_kUnsortedGeometryList;
};

class E000ExtraDataList
{
  public:
    E000Extra* GetByType(unsigned char ucType);
    E000Extra* Add(E000Extra* pkExtra);
    void FUN_0041e000(E000Item* pkItem);
};

// Ensures the type 0x3a extra exists, creating and adding it if needed, then adds pkItem to its item list when not already present.
// @fnv 0x0041e000
void E000ExtraDataList::FUN_0041e000(E000Item* pkItem)
{
    if (pkItem)
    {
        E000ExtraItemList* pkExtra = (E000ExtraItemList*)GetByType(0x3a);
        if (!pkExtra)
        {
            pkExtra = new E000ExtraItemList;
            Add(pkExtra);
        }
        if (!pkExtra->m_kUnsortedGeometryList.IsInList(pkItem))
            pkExtra->m_kUnsortedGeometryList.AddHead(pkItem);
    }
}

namespace fnv_0041e7b0 {
struct FUN_00433a00_t
{
    void* FUN_00433a00(void*);
};

struct FUN_0041e7b0_cls
{
    void* FUN_00410220(int type);
    void* FUN_0041e7b0(void* arg);
};

// @fnv 0x0041e7b0
void* FUN_0041e7b0_cls::FUN_0041e7b0(void* arg)
{
    FUN_00433a00_t* p = (FUN_00433a00_t*)FUN_00410220(0x53);
    if (p)
    {
        return p->FUN_00433a00(arg);
    }
    return 0;
}
}  // namespace fnv_0041e7b0

extern "C" char DAT_01011584[];

class EcHolderObj
{
  public:
    void AddEntry(char* p);
    void Notify(char* s);
};

class FUN_0041ec80_cls
{
  public:
    char* Find(int id);
    EcHolderObj* FUN_0041ec80(EcHolderObj* h);
};

// Looks up entry 0x53; if found, adds entry+0x18 to h, otherwise calls h->Notify with DAT_01011584, and returns h.
// @fnv 0x0041ec80
EcHolderObj* FUN_0041ec80_cls::FUN_0041ec80(EcHolderObj* apHolder)
{
    unsigned int flags2 = 0;
    char* entry = Find(0x53);
    if (entry != 0)
    {
        apHolder->AddEntry(entry + 0x18);
        flags2 |= 1;
        return apHolder;
    }
    apHolder->Notify(DAT_01011584);
    flags2 |= 1;
    return apHolder;
}

struct RefFlagEntry
{
    TESObjectREFR* pRef;
    unsigned int uiFlags;
};

struct RefFlagNode
{
    RefFlagEntry** GetItemPtr();
    RefFlagNode* GetNextNode();
    bool IsListEmpty();
    RefFlagEntry* pItem;
    RefFlagNode* pNext;
};

struct ExtraRefFlagList : public BSExtraData
{
    RefFlagNode kList;
    ExtraRefFlagList();
    void RemoveRef(TESObjectREFR* apRef);
    void AddRef(TESObjectREFR* apRef, unsigned int auiFlags);
};

struct RefFlagExtraList : public BaseExtraList
{
    void RemoveExtraDataByName(BSExtraData* apExtra, bool abDelete);
    void FUN_0041f1a0(TESObjectREFR* apRef, bool abSet);
};

// @fnv 0x0041f1a0
void RefFlagExtraList::FUN_0041f1a0(TESObjectREFR* apRef, bool abSet)
{
    ExtraRefFlagList* pExtra = (ExtraRefFlagList*)GetExtraData(0x66);
    if (pExtra)
    {
        RefFlagNode* pNode = &pExtra->kList;
        while (pNode && *pNode->GetItemPtr())
        {
            if ((*pNode->GetItemPtr())->pRef == apRef)
            {
                if (abSet)
                {
                    (*pNode->GetItemPtr())->uiFlags |= 1;
                }
                else
                {
                    (*pNode->GetItemPtr())->uiFlags &= ~1;
                    if ((*pNode->GetItemPtr())->uiFlags == 0)
                    {
                        pExtra->RemoveRef(apRef);
                        if (pExtra->kList.IsListEmpty())
                        {
                            RemoveExtraDataByName(pExtra, true);
                        }
                    }
                }
                return;
            }
            pNode = pNode->GetNextNode();
        }
    }
    if (abSet)
    {
        if (!pExtra)
        {
            pExtra = new ExtraRefFlagList();
            AddExtra(pExtra);
        }
        pExtra->AddRef(apRef, 1);
    }
}

struct FUN_0041f7e0_cls
{
    int* FUN_00410220(int code);
    int* FUN_0041f7e0();
};

// @fnv 0x0041f7e0
int* FUN_0041f7e0_cls::FUN_0041f7e0()
{
    int* pBuffer = FUN_00410220(0x84);
    if (pBuffer)
        return pBuffer + 3;
    return 0;
}

struct TESObjectREFR;
struct RefList41f940
{
    void* item;
    void* next;
    bool IsInList(TESObjectREFR*&) const;
    void AddHead(TESObjectREFR*&);
    void Remove(TESObjectREFR*&);
    bool IsEmpty() const;
};
struct ExtraRefs41f940 : BSExtraData
{
    RefList41f940 refs;
    ExtraRefs41f940();
};
struct Remover41f940
{
    void FUN_00410020(BSExtraData*, bool);
};
struct FUN_0041f940_shell : BaseExtraList
{
    void AddOrRemoveRef(TESObjectREFR* apRef, bool abAdd);
};

// @fnv 0x0041f940
void FUN_0041f940_shell::AddOrRemoveRef(TESObjectREFR* apRef, bool abAdd)
{
    ExtraRefs41f940* pExtra = (ExtraRefs41f940*)GetExtraData(0x85);
    if (pExtra)
    {
        RefList41f940* pList = &pExtra->refs;
        if (abAdd)
        {
            if (!pList->IsInList(apRef))
                pList->AddHead(apRef);
            return;
        }
        else
        {
            pList->Remove(apRef);
            if (pExtra->refs.IsEmpty())
                ((Remover41f940*)this)->FUN_00410020(pExtra, true);
            return;
        }
    }
    else if (abAdd)
    {
        pExtra = new ExtraRefs41f940();
        AddExtra(pExtra);
        pExtra->refs.AddHead(apRef);
    }
}

class FUN_0041fb50_sub
{
  public:
    virtual int unk00(int);
};

class FUN_0041fb50_base
{
  public:
    virtual void unk00();
    ~FUN_0041fb50_base();
};

class FUN_0041fb50_cls : public FUN_0041fb50_base
{
  public:
    unsigned int unk04;
    unsigned int unk08;
    FUN_0041fb50_sub* m_0c;
    virtual ~FUN_0041fb50_cls();
};

// Destructor that takes the sub-object stored in m_0c and, if non-null, calls its virtual unk00 with argument 1.
// @fnv 0x0041fb50
FUN_0041fb50_cls::~FUN_0041fb50_cls()
{
    FUN_0041fb50_sub* s = this->m_0c;
    FUN_0041fb50_sub* p = s;
    p ? p->unk00(1) : 0;
}

struct S_0041fe10_VB
{
    int unk00;
};
struct S_0041fe10_Item : virtual S_0041fe10_VB
{
    int unk04;
    ~S_0041fe10_Item();
};
struct S_0041fe10_Owner
{
    int unk00;
    int unk04;
    int unk08;
    S_0041fe10_Item* unk0c;
    void FUN_0041fe10();
};
// Deletes the item held in unk0c if present, then sets unk0c to null.
// @fnv 0x0041fe10
void S_0041fe10_Owner::FUN_0041fe10()
{
    if (unk0c)
        delete unk0c;
    unk0c = 0;
}

struct FUN_0041ffb0_Obj
{
    void* unk00;
    int unk04;
    int unk08;
    int* unk0C;

    bool __thiscall FUN_0041ffb0(FUN_0041ffb0_Obj* arg);
};

// Returns false if both objects' unk0C pointers are null or all four pointed-to ints match; otherwise returns true.
// @fnv 0x0041ffb0
bool __thiscall FUN_0041ffb0_Obj::FUN_0041ffb0(FUN_0041ffb0_Obj* apOther)
{
    FUN_0041ffb0_Obj* pOther = apOther;

    if (this->unk0C == 0 && pOther->unk0C == 0)
    {
        return false;
    }

    if (this->unk0C == 0 || pOther->unk0C == 0)
    {
        return true;
    }

    for (int i = 0; i < 4; ++i)
    {
        if (this->unk0C[i] != pOther->unk0C[i])
        {
            return true;
        }
    }

    return false;
}

class FUN_00420060_base
{
  public:
    virtual void v00();
    ~FUN_00420060_base();
    int unk04;
};

class FUN_00420060_cls : public FUN_00420060_base
{
  public:
    void Reset();
    virtual ~FUN_00420060_cls();
};

// @fnv 0x00420060
FUN_00420060_cls::~FUN_00420060_cls()
{
    Reset();
}

struct FUN_00420100_holder
{
    int unk00;
    int unk04;
    int unk08;
    int m_0c;
};

struct FUN_00420100_cls
{
    int unk00;
    int unk04;

    FUN_00420100_holder* Lookup(int key);
    int GetValue76();
};

// Looks up the entry for key 0x76 and returns its m_0c field, or 0 if not found.
// @fnv 0x00420100
int FUN_00420100_cls::GetValue76()
{
    FUN_00420100_holder* p = Lookup(0x76);
    if (p != 0)
    {
        return p->m_0c;
    }
    else
    {
        return 0;
    }
}

struct PtrArrayHolder
{
    void* m_entries[1];
};

struct FUN_00420130_cls
{
    PtrArrayHolder* GetValue76();
    void* FUN_00420130(int index);
};

// Returns the entry at index from the array holder obtained via GetValue76, or null if the holder is null.
// @fnv 0x00420130
void* FUN_00420130_cls::FUN_00420130(int index)
{
    PtrArrayHolder* holder = GetValue76();
    if (holder == 0)
    {
        return 0;
    }
    return holder->m_entries[index];
}

struct FUN_004203b0_Base
{
    virtual ~FUN_004203b0_Base();
};

struct FUN_004203b0 : FUN_004203b0_Base
{
    void FUN_004200c0();
    virtual ~FUN_004203b0();
};

// Destructor that calls FUN_004200c0 before the object is destroyed.
// @fnv 0x004203b0
FUN_004203b0::~FUN_004203b0()
{
    FUN_004200c0();
}

struct C420410ExtraData
{
    int unk00;
    int unk04;
    int unk08;
    int m_iValue;
};

struct C420410ExtraList
{
    int unk00;

    C420410ExtraData* GetByType(unsigned char ucType);
    int FUN_00420410();
};

// Looks up the extra data entry of type 0x77 and returns its m_iValue, or 0 if none exists.
// @fnv 0x00420410
int C420410ExtraList::FUN_00420410()
{
    C420410ExtraData* pkExtra = GetByType(0x77);
    if (pkExtra)
        return pkExtra->m_iValue;
    else
        return 0;
}

struct S_00420530_Node
{
    int* unk00;
    S_00420530_Node* unk04;
    int* FUN_006815c0();
    S_00420530_Node* FUN_00726070();
};

struct S_00420530_Data
{
    int unk00;
    int unk04;
    S_00420530_Node unk08;
    unsigned char unk10;
};

struct S_00420530_Cls
{
    int unk00;
    int unk04;
    int unk08;
    S_00420530_Data* unk0c;

    bool FUN_00420530(S_00420530_Cls* other);
};

// @fnv 0x00420530
bool S_00420530_Cls::FUN_00420530(S_00420530_Cls* other)
{
    S_00420530_Cls* o4 = other;
    if (!this->unk0c && !o4->unk0c)
        return false;
    if (!this->unk0c || !o4->unk0c)
        return true;
    if (this->unk0c->unk10 ^ o4->unk0c->unk10)
        return true;
    S_00420530_Node* a2 = &this->unk0c->unk08;
    S_00420530_Node* b = &o4->unk0c->unk08;
    while (a2 && b)
    {
        if (*a2->FUN_006815c0() != *b->FUN_006815c0())
            return true;
        a2 = a2->FUN_00726070();
        b = b->FUN_00726070();
    }
    if (a2 || b)
        return true;
    return false;
}

struct Base_420630
{
    virtual ~Base_420630();
    int unk04;
    int unk08;
};

class FUN_00420630_cls : public Base_420630
{
  public:
    int unk0C;
    void FUN_00420690();

    virtual ~FUN_00420630_cls();
};

// Destructor that calls FUN_00420690 before the base destructor runs.
// @fnv 0x00420630
FUN_00420630_cls::~FUN_00420630_cls()
{
    FUN_00420690();
}

struct FUN_00420690_tex
{
    int FUN_004206e0(unsigned int flags);
};

struct FUN_00420690_cls
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00420690_tex* m_0c;
    void FUN_00420690();
};

// @fnv 0x00420690
void FUN_00420690_cls::FUN_00420690()
{
    FUN_00420690_tex* copy;
    FUN_00420690_tex* tmp;
    if (m_0c != 0)
    {
        copy = m_0c;
        tmp = copy;
        tmp != 0 ? tmp->FUN_004206e0(1) : 0;
    }
    m_0c = 0;
}

struct FUN_00420870_sub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned char bFlag;
};

struct FUN_00420870_rec
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00420870_sub* pSub;
};

struct FUN_00420870_cls
{
    int unk00;
    int unk04;
    FUN_00420870_rec* FindRec(int id);
    void SetFlagOnRecord123(unsigned char bValue);
};

// Finds the record with id 0x7b and sets its sub-object's bFlag to 0xFF if bValue is nonzero, otherwise 0.
// @fnv 0x00420870
void FUN_00420870_cls::SetFlagOnRecord123(unsigned char bValue)
{
    FUN_00420870_rec* rec = FindRec(0x7b);
    if (rec != 0)
    {
        rec->pSub->bFlag = (unsigned char)-((bValue != 0) ? -1 : 0);
    }
}

struct LocalTemp
{
    LocalTemp(int a1);
    ~LocalTemp();
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

class FUN_004208b0_cls
{
  public:
    void* FUN_00410220(int a1);
    bool FUN_00420810();
    int FUN_00420950(LocalTemp* p);
    int FUN_004208b0();
};

// Looks up object 0x7b, returns 0 if missing or FUN_00420810 is true, else builds a LocalTemp(0x25) and returns FUN_00420950 on it.
// @fnv 0x004208b0
int FUN_004208b0_cls::FUN_004208b0()
{
    void* p = FUN_00410220(0x7b);
    if (p == 0)
    {
        return 0;
    }
    if (FUN_00420810())
    {
        return 0;
    }
    LocalTemp t(0x25);
    return FUN_00420950(&t);
}

struct RoomSearch;
struct SearchReference
{
    RoomSearch* FUN_005d43c0();
};
struct SearchNode
{
    SearchReference** FUN_006815c0();
    SearchNode* FUN_00726070();
};
struct RoomData
{
    unsigned int flags;
    unsigned int state;
    SearchNode references;
};
struct ExtraRoom
{
    void* vtable;
    unsigned int type;
    ExtraRoom* next;
    RoomData* data;
};
struct VisitedReferences
{
    bool FUN_0057c850(SearchReference*, bool*);
    void FUN_0084d310(SearchReference*, bool);
};
struct RoomSearch
{
    ExtraRoom* FUN_00410220(unsigned char);
    bool FUN_00420810();
    SearchReference* FUN_00420950(VisitedReferences* visited);
};
// @fnv 0x00420950
SearchReference* RoomSearch::FUN_00420950(VisitedReferences* visited)
{
    bool position;
    SearchNode* extra;
    ExtraRoom* result = FUN_00410220(0x7b);
    if (!result)
        return 0;
    SearchReference* node = 0;
    extra = &result->data->references;
    while (extra && *extra->FUN_006815c0())
    {
        SearchReference* candidate = *extra->FUN_006815c0();
        if (candidate->FUN_005d43c0()->FUN_00420810())
            return candidate;
        extra = extra->FUN_00726070();
    }
    extra = &result->data->references;
    while (extra && *extra->FUN_006815c0())
    {
        SearchReference* child = *extra->FUN_006815c0();
        if (!visited->FUN_0057c850(child, &position))
        {
            visited->FUN_0084d310(child, position);
            node = child->FUN_005d43c0()->FUN_00420950(visited);
            if (node)
                return node;
        }
        extra = extra->FUN_00726070();
    }
    return 0;
}

struct FUN_00420bc0_Item
{
    int m_00;
    int m_04;
    int m_08;
    int* m_0c;
};

struct FUN_00420bc0_cls
{
    int unk00;
    FUN_00420bc0_Item* GetItem(int id);
    int FUN_00420bc0(int idx);
};

// Looks up item 0x77 and returns the value at index idx from its m_0c array, or 0 if the item or array is null.
// @fnv 0x00420bc0
int FUN_00420bc0_cls::FUN_00420bc0(int aiIndex)
{
    FUN_00420bc0_Item* item = GetItem(0x77);
    if (item != 0)
    {
        return item->m_0c != 0 ? item->m_0c[aiIndex] : 0;
    }
    else
    {
        return 0;
    }
}

extern char DAT_010151f0;
void __cdecl FormHeap_Free(void* pointer);

struct FUN_00421160_shell
{
    void* m_vftable;
    void* unk04;
    void* unk08;
    void* m_pChangesMap;
    void FUN_0040ecb0();
    void FUN_00421160();
};

// @fnv 0x00421160
void FUN_00421160_shell::FUN_00421160()
{
    m_vftable = &DAT_010151f0;
    void* changes = m_pChangesMap;
    FormHeap_Free(changes);
    FUN_0040ecb0();
}

struct S_004212e0_Class
{
    void* FUN_00410220(unsigned int size);
    void FUN_00410020(void* data, bool flag);

    void FUN_004212e0();
};

// @fnv 0x004212e0
void S_004212e0_Class::FUN_004212e0()
{
    void* data = FUN_00410220(0x70);
    if (data)
        FUN_00410020(data, true);
}

struct FUN_00422550_child;

struct FUN_00422550_owner
{
    unsigned char unk00[0xc];
    FUN_00422550_child* m_0C;
};

struct FUN_00422550_child
{
    bool FUN_005f65d0(int* value);
};

struct FUN_00422550_cls
{
    FUN_00422550_owner* FUN_00410220(int id);
    bool FUN_00422550(int value);
};

// Looks up the owner for id 0x1d and forwards the value to its child's FUN_005f65d0, returning false if no owner is found.
// @fnv 0x00422550
bool FUN_00422550_cls::FUN_00422550(int value)
{
    FUN_00422550_owner* owner = FUN_00410220(0x1d);
    if (owner == 0)
    {
        return false;
    }
    return owner->m_0C->FUN_005f65d0(&value);
}

class B269C0Cell;

class B269C0Ref
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
    virtual bool IsActor();

    B269C0Cell* GetTarget();
};

class B269C0Cell
{
  public:
    void RemoveReference(B269C0Ref* pkRef);
};

class B269C0Owner
{
  public:
    B269C0Cell* GetContainingCell();
    void SetDirty(int iValue);
    void FUN_004269c0(void* pvUnused, B269C0Ref* pkRef);
};

// @fnv 0x004269c0
void B269C0Owner::FUN_004269c0(void* pvUnused, B269C0Ref* pkRef)
{
    bool bTargetIsActor = false;
    if (pkRef && pkRef->IsActor())
        bTargetIsActor = true;
    if (bTargetIsActor)
    {
        B269C0Cell* pkCell = GetContainingCell();
        if (pkCell && pkRef->GetTarget())
        {
            SetDirty(0);
            pkCell->RemoveReference(pkRef);
        }
    }
}

struct FUN_004047f0_Class
{
    void AssignFromString(const int& value);
};

void __thiscall FUN_004047f0_Class::AssignFromString(const int& value)
{
    (void)value;
}

struct FUN_004280b0_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;

    int CallWithField14(FUN_004047f0_Class* value);
};

// Calls value->AssignFromString with this->unk14 and returns value as an int.
// @fnv 0x004280b0
int __thiscall FUN_004280b0_Class::CallWithField14(FUN_004047f0_Class* value)
{
    int result = 0;
    value->AssignFromString(this->unk14);
    result |= 1;
    return (int)value;
}

struct ModBlockSub
{
    unsigned int m_00;
    void Reset();
};

struct ModBlock
{
    unsigned char m_00;
    unsigned char m_01;
    unsigned char m_02;
    unsigned char m_03;
    ModBlockSub m_04;
    ModBlock* FUN_0042c470();
};

// Clears the four byte fields and calls Reset on the m_04 sub-block, then returns this.
// @fnv 0x0042c470
ModBlock* ModBlock::FUN_0042c470()
{
    m_00 = 0;
    m_01 = 0;
    m_02 = 0;
    m_03 = 0;
    m_04.Reset();
    return this;
}

class FUN_0042cd70_sub
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    ~FUN_0042cd70_sub();
};

class FUN_0042cd70_base
{
  public:
    virtual void Update();
    unsigned int m_04;
    unsigned int m_08;
    ~FUN_0042cd70_base();
};

class FUN_0042cd70_cls : public FUN_0042cd70_base
{
  public:
    FUN_0042cd70_sub m_0c;
    FUN_0042cd70_sub m_14;
    ~FUN_0042cd70_cls();
};

// Destructor for the class that destroys its two member sub-objects.
// @fnv 0x0042cd70
FUN_0042cd70_cls::~FUN_0042cd70_cls()
{}

// GetExtraByteValue : ExtraDataList helper.
//
// Looks up the extra data record of type 0x4a on `this` and returns the
// byte stored at offset 0x0c of that record.  When the record is missing the
// sentinel 0xff is returned instead.

struct ExtraByteData
{
    void** m_ppVirtualMethodTable;
    unsigned char m_ucExtraDataType;
    unsigned char layoutPadding5;
    unsigned short layoutPadding6;
    void* pNext;
    unsigned char unk0C;
};

struct FUN_0042de90_cls : public BaseExtraList
{
    ExtraByteData* GetExtraDataByType(int type);
    unsigned char GetExtraByteValue();
};

// Looks up the extra data of type 0x4a and returns its unk0C byte, or 0xff if absent.
// @fnv 0x0042de90
unsigned char FUN_0042de90_cls::GetExtraByteValue()
{
    unsigned char ucValue = 0xff;
    ExtraByteData* pExtra = GetExtraDataByType(0x4a);
    if (pExtra != 0)
    {
        ucValue = pExtra->unk0C;
    }
    return ucValue;
}

struct FUN_0042e6f0_shell : public BaseExtraList
{
    void FUN_00410020(BSExtraData*, bool);
    void FUN_0042e6f0();
};

// @fnv 0x0042e6f0
void FUN_0042e6f0_shell::FUN_0042e6f0()
{
    BSExtraData* pExtra = GetExtraData(0x8E);
    if (pExtra)
        FUN_00410020(pExtra, true);
}

class FUN_0042e730_cls
{
  public:
    void* Acquire(int id);
    void Release(void* p, bool flag);
    void FUN_0042e730();
};

// Acquires the resource with id 0x5a and, if the returned pointer is non-null, releases it with flag true.
// @fnv 0x0042e730
void FUN_0042e730_cls::FUN_0042e730()
{
    void* p = Acquire(0x5a);
    if (p != 0)
    {
        Release(p, true);
    }
}

class B42E8E0ExtraList : public ExtraDataList
{
  public:
    bool FUN_00410020(BSExtraData* pkExtra, bool bFree);
    void FUN_0042e8e0();
};

// @fnv 0x0042e8e0
void B42E8E0ExtraList::FUN_0042e8e0()
{
    BSExtraData* pkExtra = GetExtraData(0x5f);
    if (pkExtra)
        FUN_00410020(pkExtra, true);
}

namespace fnv_0042ed70 {
struct FUN_00410220_Class
{
    BSExtraData* GetExtraData(unsigned char);
};

BSExtraData* __thiscall FUN_00410220_Class::GetExtraData(unsigned char type)
{
    return 0;
}

struct FUN_0042ed70_Class
{
    int FUN_0042ed70();
};

// Retrieves extra data of type 0x75 and returns the int stored at offset 0xc, or 0 if absent.
// @fnv 0x0042ed70
int __thiscall FUN_0042ed70_Class::FUN_0042ed70()
{
    int res = 0;
    BSExtraData* extra = ((FUN_00410220_Class*)this)->GetExtraData(0x75);
    if (extra != 0)
    {
        res = *(int*)((char*)extra + 0xc);
    }
    return res;
}
}  // namespace fnv_0042ed70

struct FUN_0042efe0_cls : BaseExtraList
{
    int FUN_00410220(int aeType);
    int FUN_0042efe0();
};

// @fnv 0x0042efe0
int FUN_0042efe0_cls::FUN_0042efe0()
{
    int result = FUN_00410220(0x73);
    return result;
}

// FUN_0042f000 : ExtraDataList helper that flags the extra data of type 0x73
// as "extra" if such an extra data block is present on the list.
struct FUN_0042f000_cls : public ExtraDataList
{
    BSExtraData* FUN_00410220(int iType);
    void FUN_00410020(BSExtraData* pExtra, int iFlag);
    void FUN_0042f000();
};

// @fnv 0x0042f000
void FUN_0042f000_cls::FUN_0042f000()
{
    BSExtraData* pExtra = this->FUN_00410220(0x73);
    if (pExtra != 0)
    {
        this->FUN_00410020(pExtra, 1);
    }
}

struct FUN_0042f180_cls
{
    void* FindOwner();
    void* FindChild();
    void Refresh(void** pKey, void** pResult, void** pExtra);
    void* FUN_0042f180();
};

// Finds the owner, gets its child, refreshes with that child and returns the resulting value, or 0 if no owner or child.
// @fnv 0x0042f180
void* FUN_0042f180_cls::FUN_0042f180()
{
    void* extra6;
    void* result;
    void* child;
    void* pOwner = FindOwner();
    if (pOwner != 0)
    {
        child = reinterpret_cast<FUN_0042f180_cls*>(pOwner)->FindChild();
        if (child != 0)
        {
            reinterpret_cast<FUN_0042f180_cls*>(pOwner)->Refresh(&child, &result, &extra6);
            return result;
        }
    }
    return 0;
}

struct ArrayElem42f8a0
{
    int value;
};

struct BSSimpleArray42f8a0
{
    virtual ~BSSimpleArray42f8a0();
    virtual ArrayElem42f8a0* Allocate(unsigned int count);

    ArrayElem42f8a0* pBuffer;
    unsigned int uiSize;
    unsigned int uiAllocSize;

    bool ShouldShrink();
    unsigned int GetShrinkSize();
    void MoveItems(void* dst, void* src, unsigned int count);
    void DestructItems(ArrayElem42f8a0* items, unsigned int count);
    void FreeBuffer();

    void RemoveAt(unsigned int index, bool allowShrink);
};

// Removes the element at index, optionally shrinking the buffer, and decrements the size.
// @fnv 0x0042f8a0
void BSSimpleArray42f8a0::RemoveAt(unsigned int index, bool allowShrink)
{
    if (allowShrink && ShouldShrink())
    {
        unsigned int newSize = GetShrinkSize();
        ArrayElem42f8a0* newBuffer2 = Allocate(newSize);
        MoveItems(newBuffer2, pBuffer, index);
        DestructItems(&pBuffer[index], 1);
        MoveItems(&newBuffer2[index], &pBuffer[index + 1], uiSize - 1);
        FreeBuffer();
        pBuffer = newBuffer2;
        uiAllocSize = newSize;
    }
    else
    {
        DestructItems(&pBuffer[index], 1);
        MoveItems(&pBuffer[index], &pBuffer[index + 1], uiSize - index - 1);
    }
    uiSize--;
}

struct FUN_00438bb0_cls
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned char m_0c;
    unsigned char m_0d;
    unsigned short m_0e;
    unsigned int m_10;
    void FUN_00402d00();
    FUN_00438bb0_cls* FUN_00438bb0();
};

// Calls FUN_00402d00, then clears m_0c, m_0d, m_0e and m_10, and returns this.
// @fnv 0x00438bb0
FUN_00438bb0_cls* FUN_00438bb0_cls::FUN_00438bb0()
{
    FUN_00402d00();
    m_0c = 0;
    m_0d = 0;
    m_0e = 0;
    m_10 = 0;
    return this;
}

struct Triple00438f50
{
    int first;
    int second;
    int third;
};

extern Triple00438f50 DAT_011c3ae4;

struct Base00438f50
{
    Base00438f50();
};

struct FUN_00438f50 : Base00438f50
{
    Triple00438f50 values;
    FUN_00438f50();
};

// Initializes the base class and copies the global DAT_011c3ae4 triple into the values member.
// @fnv 0x00438f50
FUN_00438f50::FUN_00438f50() : Base00438f50()
{
    values = DAT_011c3ae4;
}

void* Fallback_00451010();

struct BPSubObj_b9834
{
    void* Resolve();
};

struct FUN_004543c0_cls
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
    bool Probe();
    void* FUN_004543c0();
};

// Returns the resolved object from the sub-object at offset 0x28 if Probe() succeeds, otherwise calls Fallback_00451010.
// @fnv 0x004543c0
void* FUN_004543c0_cls::FUN_004543c0()
{
    return Probe() ? reinterpret_cast<BPSubObj_b9834*>((char*)this + 0x28)->Resolve() : Fallback_00451010();
}

struct BGSChangeFlags_s
{
    unsigned int value;
    bool Test(unsigned int);
};
struct BGSSaveFormBuffer
{
    void SaveData(void*, unsigned int, int);
};
struct SaveFlagsAccessor
{
    BGSChangeFlags_s* FUN_00428110(BGSChangeFlags_s*);
};
struct SavePayload
{
    void FUN_0047ea30(BGSSaveFormBuffer* buffer);
};
// If the buffer's change flags have bit 2 set, saves 24 bytes starting at this+4 into the buffer.
// @fnv 0x0047ea30
void SavePayload::FUN_0047ea30(BGSSaveFormBuffer* buffer)
{
    BGSChangeFlags_s flags;
    if (((SaveFlagsAccessor*)buffer)->FUN_00428110(&flags)->Test(2))
        buffer->SaveData((char*)this + 4, 24, 0);
}

struct PacketReadResult
{
    bool FUN_004280f0();
};

struct PacketSerializer
{
    PacketReadResult* FUN_00428110(void* destination, unsigned int size);
    void FUN_00865e50(void* destination, unsigned int kind, unsigned int flags);
};

struct FUN_00480270_shell
{
    unsigned int unk00;
    unsigned int unk04;
    void FUN_00480270(PacketSerializer* stream);
};

// @fnv 0x00480270
void FUN_00480270_shell::FUN_00480270(PacketSerializer* stream)
{
    unsigned int value;
    if (stream->FUN_00428110(&value, 4)->FUN_004280f0())
    {
        stream->FUN_00865e50(&unk04, 7, 0);
    }
}

struct FUN_00419700_Class
{
    void FUN_00419700();
};

struct FUN_00546bf0_class
{
    virtual void FUN_00546bf0_virtual_00();
    virtual void FUN_00546bf0_virtual_01();
    virtual void FUN_00546bf0_virtual_02();
    virtual void FUN_00546bf0_virtual_03();
    virtual void FUN_00546bf0_virtual_04();
    virtual void FUN_00546bf0_virtual_05();
    virtual void FUN_00546bf0_virtual_06();
    virtual void FUN_00546bf0_virtual_07();
    virtual void FUN_00546bf0_virtual_08();
    virtual void FUN_00546bf0_virtual_09();
    virtual void FUN_00546bf0_virtual_10();
    virtual void FUN_00546bf0_virtual_11();
    virtual void FUN_00546bf0_virtual_12();
    virtual void FUN_00546bf0_virtual_13();
    virtual void FUN_00546bf0_virtual_14();
    virtual void FUN_00546bf0_virtual_15();
    virtual void FUN_00546bf0_virtual_16();
    virtual void FUN_00546bf0_virtual_17();
    virtual void FUN_00546bf0_virtual_18(int);

    FUN_00419700_Class* GetExtraDataList(int);
    void FUN_00546bf0(int);
};

// Calls FUN_00419700 on the object returned by GetExtraDataList(param), then invokes virtual slot 18 with 8.
// @fnv 0x00546bf0
void FUN_00546bf0_class::FUN_00546bf0(int param)
{
    this->GetExtraDataList(param)->FUN_00419700();
    FUN_00546bf0_virtual_18(8);
}

extern float DAT_01026994;
extern float DAT_010320e4;
extern int DAT_011f426c;
extern int DAT_011f4270;
extern int DAT_011f4274;

struct FUN_00589450_base
{
    FUN_00589450_base();
    ~FUN_00589450_base();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};

struct Vec3Stand
{
    Vec3Stand();
    int x;
    int y;
    int z;
};

struct ObjStand
{
    ObjStand();
    unsigned int unk00;
};

struct FUN_00589450_cls : public FUN_00589450_base
{
    FUN_00589450_cls();
    float m_0c;
    float m_10;
    unsigned int m_14;
    Vec3Stand m_18;
    unsigned int m_24;
    unsigned int m_28;
    ObjStand m_2c;
};

// @fnv 0x00589450
FUN_00589450_cls::FUN_00589450_cls()
{
    m_0c = DAT_01026994;
    m_10 = DAT_010320e4;
    m_18 = *(Vec3Stand*)&DAT_011f426c;
    m_24 = 0;
}

struct ExtraCopyData : BSExtraData
{
    unsigned char FUN_004f1540();
    BSExtraData* FUN_0044ddc0();
};
struct ExtraCopyList : ExtraDataList
{
    void FUN_004103d0(BSExtraData*);
    void FUN_00410020(BSExtraData*, bool);
    void FUN_00412490(ExtraCopyList* source, bool transfer);
};
struct ExtraCopyLock
{
    void Lock(const char*);
    void Unlock();
};
struct ScriptCopyHelper
{
    ScriptLocals* CreateEventList();
};

// Copies extra-data entries from source into this list, transferring or cloning script extras depending on transfer, under a lock.
// @fnv 0x00412490
void ExtraCopyList::FUN_00412490(ExtraCopyList* source, bool transfer)
{
    ((ExtraCopyLock*)&DAT_011c3920)->Lock("ExtraDataList::CopyListForReference()");
    BSExtraData* extra = source->pHead;
    bool advance = true;
    while (extra)
    {
        advance = true;
        switch (((ExtraCopyData*)extra)->FUN_004f1540())
        {
        case 22:
        case 28:
        case 33:
        case 34:
        case 35:
        case 37:
        case 38:
        case 39:
        case 40:
        case 47:
        case 48:
        case 63:
        case 141:
            FUN_004103d0(extra);
            if (transfer)
            {
                source->FUN_00410020(extra, true);
                extra = source->pHead;
                advance = false;
            }
            break;
        case 13:
            if (transfer)
            {
                FUN_004103d0(extra);
                source->FUN_00410020(extra, false);
                extra = source->pHead;
                advance = false;
            }
            else
            {
                Script* script = ((FUN_00418800_shell*)source)->FUN_00418800();
                ExtraScript* scriptExtra = new ExtraScript(script);
                AddExtra(scriptExtra);
                ((FUN_00419f80_shell*)this)
                    ->FUN_00419f80(((ScriptCopyHelper*)((FUN_00418800_shell*)source)->FUN_00418800())->CreateEventList());
            }
            break;
        }
        if (extra && advance)
            extra = ((ExtraCopyData*)extra)->FUN_0044ddc0();
    }
    ((ExtraCopyLock*)&DAT_011c3920)->Unlock();
}

namespace ExtraSave {
struct Form
{
    unsigned int FUN_0084e3a0();
    void FUN_0043a420();
    void FUN_00438c10();
    void WriteToStream();
    void FUN_00483710();
    void FUN_004d93c0();
    void FUN_00438f90();
};
struct Point3
{
    float x, y, z;
};
struct TwoComponentVector
{
    float x, y;
};
struct Color4
{
    float r, g, b, a;
};
struct FloatMatrix3
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    void GetAxisAngle(float*, float*, float*, float*);
};
struct Plane
{
    TwoComponentVector& FUN_007d6bb0();
    Point3& FUN_00413f40();
    FloatMatrix3 CopyData();
};
struct Primitive
{
    Point3 FUN_00413fc0();
    Color4 FUN_00413f90();
    unsigned int FUN_00726070();
};
struct String
{
    char* text;
    unsigned short length, capacity;
    ~String();
    unsigned int FUN_004048e0();
    char* FUN_00559450();
};
struct PlanePointer
{
    Plane* value;
    Plane* FUN_00559450();
};
struct LockRecord
{
    unsigned char level;
    unsigned int key;
    unsigned char flags;
    int unk0c, unk10;
    void FUN_00411b00();
    void FUN_0060ce80();
};
struct PathingActorState
{
    unsigned char level;
    Form* key;
    unsigned char flags;
};
struct RadioRecord
{
    int unk00, unk04, unk08;
    Form* form;
    void FUN_00414220();
};
struct PositionRecord
{
    unsigned int form;
    Point3 position;
    int unk10;
    void FUN_006d5320();
    void FUN_00414220();
};
struct EnableRecord
{
    unsigned int form;
    unsigned char flags;
    void FUN_00503210();
};
struct PairRecord
{
    union
    {
        Form* form;
        unsigned int formId;
    };
    int unk04;
    void FUN_00414010();
    void FUN_0096a2d0();
    void FUN_00462230();
};
struct DecalRecord
{
    union
    {
        Form* form;
        unsigned int formId;
    };
    Point3 position;
    Point3 rotation;
    void FUN_0055a400();
    void SwapEndian();
};
template <class T> struct List
{
    T* item;
    List* next;
    unsigned int FUN_005ae380();
    T*& FUN_006815c0();
    List* FUN_00726070();
    bool FUN_008256d0();
};
struct WorldPrefix
{
    int unk00;
};
struct WorldList : WorldPrefix, List<Form>
{
};
struct FormPair
{
    union
    {
        Form* form;
        unsigned int formId;
    };
    int unk04;
    void FUN_0069a690(const FormPair*);
    void FUN_004141e0();
};
struct PrimitiveRecord
{
    Point3 bounds;
    Color4 color;
    unsigned int type;
    void FUN_004143f0();
    void FUN_00414290();
};
struct PrimitiveData
{
    int unk00;
    void FUN_0067dc80(unsigned int);
};
struct PrimitiveRefRecord
{
    int data;
    void SetFromFloat(PrimitiveData*);
    void FUN_00503210();
};
struct PlaneRecord
{
    TwoComponentVector size;
    Point3 center;
    float x, y, z, angle;
    void FUN_00414470();
    void FUN_004140f0();
};
struct FourForms
{
    unsigned int forms[4];
    void ClearFourInts();
    void ProcessAllElements();
};
struct TwoForms
{
    unsigned int forms[2];
    void FUN_004143c0();
    void FUN_00462230();
};
struct Room
{
    int unk00, unk04;
    List<Form> linked;
    bool flags;
};
struct SwappableWord
{
    int value;
    void FUN_00503210();
};
struct Extra
{
    void** vtable;
    Extra* next;
    unsigned char type;
    union
    {
        struct
        {
            union
            {
                int value;
                unsigned int uintValue;
                short shortValue;
                unsigned char byteValue;
                float floatValue;
                Form* form;
                PathingActorState* lock;
                WorldList* world;

                Primitive* primitive;
                PrimitiveData* primitiveData;
                PlanePointer plane;
                Form** formArray;
                Room* room;
                SwappableWord* word;
            };
            union
            {
                int extraValue;
                float extraFloat;
                unsigned char extraFlags;
            };
            unsigned char activationFlags;
            String activationText;
        };
        RadioRecord radio;
        List<Form> forms;
        List<PairRecord> activation;
        List<DecalRecord> decals;
        FormPair pair;
        Point3 position;
    };
    unsigned char FUN_004f1540();
    Extra* FUN_0044ddc0();
    unsigned int FUN_0084e3a0();
};
struct SpinLock
{
    void Lock(const char*);
    void Unlock();
};
extern SpinLock DAT_011c3920;
bool __cdecl FUN_00401500();
void __cdecl FUN_00485910(unsigned int, int);
void __cdecl FUN_00485910(unsigned int, unsigned int);
void __cdecl FUN_00485910(unsigned int, float);
void __cdecl FUN_004858f0(unsigned int, unsigned char);
void __cdecl AppendChunk(unsigned int, const void*, unsigned int);
void __cdecl FUN_00485710(unsigned int, const void*, unsigned int);
void __cdecl FUN_004856d0(unsigned int);
void __cdecl FUN_004856f0(unsigned int, const void*, unsigned int);
void* __cdecl FUN_00401460(void*, const void*, unsigned int);
struct ExtraList
{
    void** vtable;
    Extra* head;
    unsigned char FUN_00418b40();
    String FUN_0041ec80();
    void WriteToSave();
};
// @fnv 0x00412970
void ExtraList::WriteToSave()
{
    DAT_011c3920.Lock(0);
    Extra* extra = head;
    while (extra)
    {
        switch (extra->FUN_004f1540())
        {
        case 14: {
            unsigned int action = extra->byteValue;
            FUN_00485910('TCAX', action);
            break;
        }
        case 42: {
            PathingActorState* lockSlot0 = extra->lock;
            LockRecord recordSlot0;
            recordSlot0.FUN_00411b00();
            recordSlot0.flags = lockSlot0->flags;
            recordSlot0.level = lockSlot0->level;
            if (lockSlot0->key)
                recordSlot0.key = lockSlot0->key->FUN_0084e3a0();
            else
                recordSlot0.key = 0;
            if (FUN_00401500())
                recordSlot0.FUN_0060ce80();
            AppendChunk('COLX', &recordSlot0, 20);
            if (FUN_00401500())
                recordSlot0.FUN_0060ce80();
            break;
        }
        case 104: {
            RadioRecord* radioSlot0 = &extra->radio;
            Form* formSlot0 = radioSlot0->form;
            if (formSlot0)
                radioSlot0->form = (Form*)formSlot0->FUN_0084e3a0();
            if (FUN_00401500())
                radioSlot0->FUN_00414220();
            AppendChunk('ODRX', radioSlot0, 16);
            if (FUN_00401500())
                radioSlot0->FUN_00414220();
            radioSlot0->form = formSlot0;
            break;
        }
        case 43: {
            extra->form->FUN_0043a420();
            break;
        }
        case 44: {
            FUN_004856d0('KRMX');
            extra->form->FUN_00438c10();
            break;
        }
        case 144: {
            FUN_004856d0('KRMM');
            extra->form->WriteToStream();
            break;
        }
        case 145: {
            FUN_004856d0('KRMA');
            extra->form->FUN_00483710();
            break;
        }
        case 33: {
            Form* formSlot19 = extra->form;
            unsigned int idSlot1 = formSlot19->FUN_0084e3a0();
            FUN_00485910('NWOX', idSlot1);
            break;
        }
        case 34: {
            Form* formSlot19 = extra->form;
            unsigned int idSlot1 = formSlot19->FUN_0084e3a0();
            FUN_00485910('BLGX', idSlot1);
            break;
        }
        case 35: {
            int rank = extra->value;
            FUN_00485910('KNRX', rank);
            break;
        }
        case 36: {
            int count = extra->shortValue;
            FUN_00485910('TNCX', count);
            break;
        }
        case 110: {
            int countSlot0 = extra->extraValue;
            unsigned int idSlot0 = extra->form ? extra->form->FUN_0084e3a0() : 0;
            FUN_00485910('TMAX', idSlot0);
            FUN_00485910('CMAX', countSlot0);
            break;
        }
        case 37: {
            int health = (int)extra->floatValue;
            FUN_00485910('TLHX', health);
            break;
        }
        case 122: {
            FUN_00485910('PLHX', extra->floatValue);
            break;
        }
        case 38: {
            unsigned int usage = extra->byteValue;
            FUN_00485910('ESUX', usage);
            break;
        }
        case 39: {
            float value = extra->floatValue;
            FUN_00485910('MITX', value);
            break;
        }
        case 40: {
            float value = extra->floatValue;
            FUN_00485910('GHCX', value);
            break;
        }
        case 63: {
            Form* formSlot0 = extra->form;
            unsigned int idSlot0 = formSlot0->FUN_0084e3a0();
            FUN_00485910('NSPX', idSlot0);
            break;
        }
        case 49: {
            unsigned char seed = FUN_00418b40();
            FUN_004858f0('DESX', seed);
            break;
        }
        case 4: {
            List<Form>* cursor = extra->world;
            unsigned int countSlot0 = cursor->FUN_005ae380();
            unsigned int* idsSlot0 = 0;
            unsigned int indexSlot0 = 0;
            if (countSlot0 > 0)
            {
                idsSlot0 = new unsigned int[countSlot0];
                while (cursor)
                {
                    idsSlot0[indexSlot0] = cursor->FUN_006815c0()->FUN_0084e3a0();
                    ++indexSlot0;
                    cursor = cursor->FUN_00726070();
                }
                FUN_00485710('RLCX', idsSlot0, countSlot0);
                delete[] idsSlot0;
            }
            break;
        }
        case 8: {
            Form* formSlot0 = extra->form;
            unsigned int idSlot0 = formSlot0->FUN_0084e3a0();
            FUN_00485910('MCCX', idSlot0);
            break;
        }
        case 89: {
            Form* formSlot19 = extra->form;
            unsigned int idSlot1 = formSlot19->FUN_0084e3a0();
            FUN_00485910('MICX', idSlot1);
            break;
        }
        case 3: {
            Form* formSlot0 = extra->form;
            unsigned int idSlot0 = formSlot0->FUN_0084e3a0();
            FUN_00485910('TWCX', idSlot0);
            break;
        }
        case 7: {
            Form* formSlot0 = extra->form;
            unsigned int idSlot0 = formSlot0->FUN_0084e3a0();
            FUN_00485910('OMCX', idSlot0);
            break;
        }
        case 129: {
            Form* formSlot19 = extra->form;
            unsigned int idSlot1 = formSlot19->FUN_0084e3a0();
            FUN_00485910('SACX', idSlot1);
            break;
            break;
        }
        case 24: {
            PositionRecord record;
            record.FUN_006d5320();
            record.form = extra->form->FUN_0084e3a0();
            record.position = *(Point3*)&extra->extraValue;
            if (FUN_00401500())
                record.FUN_00414220();
            AppendChunk('LSPX', &record, 20);
            if (FUN_00401500())
                record.FUN_00414220();
            break;
        }
        case 20: {
            Form* script = extra->form;
            script->FUN_004d93c0();
            break;
        }
        case 19: {
            Point3 lod = extra->position;
            FUN_00485710('DOLX', &lod, 3);
            break;
        }
        case 55: {
            Form* form = extra->form;
            if (form)
            {
                EnableRecord record;
                record.form = form->FUN_0084e3a0();
                record.flags = extra->extraFlags;
                if (FUN_00401500())
                    record.FUN_00503210();
                AppendChunk('PSEX', &record, 8);
                if (FUN_00401500())
                    record.FUN_00503210();
            }
            break;
        }
        case 59: {
            Form* form = extra->form;
            if (form)
            {
                unsigned int id = form->FUN_0084e3a0();
                FUN_00485910('MTRX', id);
            }
            break;
        }
        case 81: {
            Form* form = extra->form;
            if (form)
            {
                unsigned int id = form->FUN_0084e3a0();
                FUN_00485910('RKLX', id);
            }
            break;
        }
        case 83: {
            Extra* activationSlot1 = extra;
            FUN_004858f0('DPAX', activationSlot1->activationFlags);
            List<PairRecord>* cursor = &activationSlot1->activation;
            while (cursor && !cursor->FUN_008256d0())
            {
                PairRecord* source = cursor->FUN_006815c0();
                cursor = cursor->FUN_00726070();
                PairRecord record;
                record.FUN_00414010();
                FUN_00401460(&record, source, 8);
                record.formId = record.form->FUN_0084e3a0();
                if (FUN_00401500())
                    record.FUN_00462230();
                AppendChunk('RPAX', &record, 8);
                if (FUN_00401500())
                    record.FUN_00462230();
            }
            if (activationSlot1->activationText.FUN_004048e0())
                FUN_004856f0('OTAX', FUN_0041ec80().FUN_00559450(), FUN_0041ec80().FUN_004048e0() + 1);
            break;
        }
        case 102: {
            List<PairRecord>* cursor = &extra->activation;
            while (cursor && !cursor->FUN_008256d0())
            {
                PairRecord* source = cursor->FUN_006815c0();
                PairRecord record;
                record.FUN_0096a2d0();
                FUN_00401460(&record, source, 8);
                record.formId = source->form->FUN_0084e3a0();
                if (FUN_00401500())
                    record.FUN_00462230();
                AppendChunk('RWPX', &record, 8);
                if (FUN_00401500())
                    record.FUN_00462230();
                cursor = cursor->FUN_00726070();
            }
            break;
        }
        case 133: {
            List<Form>* cursor = &extra->forms;
            while (cursor && !cursor->FUN_008256d0())
            {
                unsigned int id = cursor->FUN_006815c0()->FUN_0084e3a0();
                FUN_00485910('WTLX', id);
                cursor = cursor->FUN_00726070();
            }
            break;
        }
        case 87: {
            List<DecalRecord>* cursor = &extra->decals;
            while (cursor && !cursor->FUN_008256d0())
            {
                DecalRecord* source = cursor->FUN_006815c0();
                DecalRecord record;
                record.FUN_0055a400();
                FUN_00401460(&record, source, 28);
                record.formId = source->form->FUN_0084e3a0();
                if (FUN_00401500())
                    record.SwapEndian();
                AppendChunk('RCDX', &record, 28);
                if (FUN_00401500())
                    record.SwapEndian();
                cursor = cursor->FUN_00726070();
            }
            break;
        }
        case 60: {
            Form* form = extra->form;
            if (form)
            {
                unsigned int id = form->FUN_0084e3a0();
                FUN_00485910('CRMX', id);
            }
            break;
        }
        case 68: {
            Form* form = extra->form;
            if (form)
            {
                unsigned int id = form->FUN_0084e3a0();
                FUN_00485910('GRTX', id);
            }
            break;
        }
        case 116: {
            Form* form = extra->form;
            if (form)
            {
                unsigned int id = form->FUN_0084e3a0();
                FUN_00485910('NZEX', id);
            }
            break;
        }
        case 103: {
            Form* form = extra->form;
            if (form)
            {
                unsigned int id = form->FUN_0084e3a0();
                FUN_00485910('IMEX', id);
            }
            break;
        }
        case 99: {
            Form* form = extra->form;
            if (form)
            {
                unsigned int id = form->FUN_0084e3a0();
                FUN_00485910('RBMX', id);
            }
            break;
        }
        case 98: {
            Form* teleport = extra->form;
            if (teleport)
                teleport->FUN_00438f90();
            break;
        }
        case 30: {
            int flags = extra->value;
            FUN_00485910('MCLX', flags);
            break;
            break;
            break;
        }
        case 90: {
            FormPair* pairSlot0 = &extra->pair;
            FormPair recordSlot10;
            recordSlot10.FUN_0069a690(pairSlot0);
            if (pairSlot0->form)
            {
                recordSlot10.formId = pairSlot0->form->FUN_0084e3a0();
                if (FUN_00401500())
                    recordSlot10.FUN_004141e0();
                AppendChunk('PDNX', &recordSlot10, 8);
                if (FUN_00401500())
                    recordSlot10.FUN_004141e0();
            }
            break;
        }
        case 92: {
            Extra* radius = extra;
            FUN_00485910('SDRX', radius->floatValue);
            break;
        }
        case 93: {
            Extra* radius = extra;
            FUN_00485910('DARX', radius->floatValue);
            break;
        }
        case 107: {
            PrimitiveRecord recordSlot10;
            recordSlot10.FUN_004143f0();
            Primitive* primitiveSlot0 = extra->primitive;
            recordSlot10.bounds = primitiveSlot0->FUN_00413fc0();
            recordSlot10.color = primitiveSlot0->FUN_00413f90();
            recordSlot10.type = primitiveSlot0->FUN_00726070();
            if (FUN_00401500())
                recordSlot10.FUN_00414290();
            AppendChunk('MRPX', &recordSlot10, 32);
            if (FUN_00401500())
                recordSlot10.FUN_00414290();
            break;
        }
        case 111: {
            Extra* primitiveSlot0 = extra;
            PrimitiveRefRecord recordSlot0;
            recordSlot0.SetFromFloat(primitiveSlot0->primitiveData);
            if (FUN_00401500())
                recordSlot0.FUN_00503210();
            AppendChunk('DRPX', &recordSlot0, 4);
            if (FUN_00401500())
                recordSlot0.FUN_00503210();
            (primitiveSlot0->primitiveData + 1)->FUN_0067dc80('APPX');
            break;
        }
        case 113: {
            PlaneRecord recordSlot0;
            recordSlot0.FUN_00414470();
            Plane* planeSlot0 = extra->plane.FUN_00559450();
            recordSlot0.size = planeSlot0->FUN_007d6bb0();
            recordSlot0.center = planeSlot0->FUN_00413f40();
            planeSlot0->CopyData().GetAxisAngle(&recordSlot0.angle, &recordSlot0.x, &recordSlot0.y, &recordSlot0.z);
            if (FUN_00401500())
                recordSlot0.FUN_004140f0();
            AppendChunk('PCOX', &recordSlot0, 36);
            if (FUN_00401500())
                recordSlot0.FUN_004140f0();
            break;
        }
        case 118: {
            Extra* linksSlot0 = extra;
            FourForms recordSlot0;
            recordSlot0.ClearFourInts();
            for (int index = 0; index < 4; ++index)
                recordSlot0.forms[index] =
                    linksSlot0->formArray[index] ? linksSlot0->formArray[index]->FUN_0084e3a0() : 0;
            if (FUN_00401500())
                recordSlot0.ProcessAllElements();
            AppendChunk('DROX', &recordSlot0, 16);
            if (FUN_00401500())
                recordSlot0.ProcessAllElements();
            break;
        }
        case 120: {
            PlaneRecord recordSlot0;
            recordSlot0.FUN_00414470();
            Plane* planeSlot0 = extra->plane.FUN_00559450();
            recordSlot0.size = planeSlot0->FUN_007d6bb0();
            recordSlot0.center = planeSlot0->FUN_00413f40();
            planeSlot0->CopyData().GetAxisAngle(&recordSlot0.angle, &recordSlot0.x, &recordSlot0.y, &recordSlot0.z);
            if (FUN_00401500())
                recordSlot0.FUN_004140f0();
            AppendChunk('LTPX', &recordSlot0, 36);
            if (FUN_00401500())
                recordSlot0.FUN_004140f0();
            break;
        }
        case 119: {
            Extra* linksSlot0 = extra;
            TwoForms recordSlot0;
            recordSlot0.FUN_004143c0();
            for (int index = 0; index < 2; ++index)
                recordSlot0.forms[index] =
                    linksSlot0->formArray[index] ? linksSlot0->formArray[index]->FUN_0084e3a0() : 0;
            if (FUN_00401500())
                recordSlot0.FUN_00462230();
            AppendChunk('DOPX', &recordSlot0, 8);
            if (FUN_00401500())
                recordSlot0.FUN_00462230();
            break;
        }
        case 123: {
            Extra* roomSlot12 = extra;
            unsigned int countSlot0 = roomSlot12->room->linked.FUN_005ae380();
            if (roomSlot12->room->flags)
                countSlot0 |= 0x10000;
            FUN_00485910('RMRX', countSlot0);
            List<Form>* cursor = &roomSlot12->room->linked;
            while (cursor && cursor->FUN_006815c0())
            {
                unsigned int id = cursor->FUN_006815c0()->FUN_0084e3a0();
                FUN_00485910('MRLX', id);
                cursor = cursor->FUN_00726070();
            }
            break;
        }
        case 97: {
            FUN_004856d0('PBMX');
            break;
            break;
        }
        case 114: {
            Extra* collision = extra;
            if (FUN_00401500())
                collision->word->FUN_00503210();
            AppendChunk('IRTX', collision->word, 4);
            if (FUN_00401500())
                collision->word->FUN_00503210();
            break;
        }
        case 128: {
            FUN_004856d0('SBIX');
            break;
        }
        case 141: {
            unsigned char health = extra->byteValue;
            FUN_004858f0('TLHX', health);
            break;
        }
        case 146: {
            FUN_00485910('FRSX', extra->FUN_0084e3a0());
            FUN_00485910('DRSX', extra->extraFloat);
            break;
        }
        }
        extra = extra->FUN_0044ddc0();
    }
    DAT_011c3920.Unlock();
}
}

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
void* __cdecl operator new[](unsigned int);
void __cdecl operator delete[](void*);
namespace loader {
struct File
{
    int FUN_004726b0();
    bool ReadChunkInt(void*);
    bool GetChunkData(void*, unsigned int);
    bool FUN_00401680();
    unsigned int GetField25C();
    bool FUN_004726f0();
    const char* FUN_00891170();
};

struct Ammo
{
    int unk00;
    int unk04;
    int unk08;
    int ammo;
};
struct PathingActorState
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    PathingActorState();
    void FUN_0060ce80();
    void FUN_00430a90(bool);
};
struct LockExtra
{
    int unk00;
    int unk04;
    int unk08;
    PathingActorState* data;
    LockExtra(PathingActorState*);
};
struct Radio
{
    float radius;
    int type;
    float staticPct;
    void* position;
    Radio();
    void FUN_00414220();
};
struct Teleport
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Teleport();
    void FUN_0043a4e0(File*);
};
struct Marker
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    Marker();
    void FUN_00438ca0(File*);
};
struct AudioMarker
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
    AudioMarker();
    void LoadFromFile(File*);
};
struct AcousticMarker
{
    int unk00;
    int unk04;
    AcousticMarker();
    void FUN_00589890(File*);
};
struct Region
{
};
struct RegionList
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    RegionList(int);
    Region* FUN_004f66c0(unsigned int);
    bool AddRegion(Region*);
};
struct DataHandler
{
    RegionList* FUN_004169d0();
};
extern DataHandler* g_dataHandler;
struct EndianTag
{
};
void __cdecl endian(void*, EndianTag);
void __cdecl ResolveFormID(unsigned int*, File*);
void __cdecl warning(const char*, ...);
void* __cdecl memset(void*, int, unsigned int);

struct LinkedData
{
    int ref;
    float posX;
    float posY;
    float posZ;
    float heading;
    LinkedData();
    void FUN_00414220();
};
struct RagdollData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    RagdollData();
    bool LoadRagdollChunk(File*);
};
struct RagdollExtra
{
    int unk00;
    int unk04;
    int unk08;
    RagdollData* data;
    RagdollExtra();
};
struct Point
{
    float x, y, z;
    Point(float, float, float);
};
struct ParentData
{
    int ref;
    unsigned char flags;
    unsigned char unk05;
    unsigned short unk06;
    void FUN_00503210();
};
struct PackageRef
{
    int ref;
    float value;
    PackageRef();
    void FUN_00462230();
};
struct RefList
{
    void* head;
    void* next;
    void FUN_005ae3d0(PackageRef* const&);
};
struct ExtraPackage
{
    int unk00;
    int unk04;
    int unk08;
    RefList list;
    unsigned char flags;
    unsigned char unk15;
    unsigned short unk16;
    int unk18;
    int unk1c;
    ExtraPackage();
};
struct PackageCombat
{
    int ref;
    float value;
    unsigned char flag;
    unsigned char unk09;
    unsigned short unk0a;
};
struct TeleportLoad
{
    int ref;
    float posX;
    float posY;
    float posZ;
    float rotX;
    float rotY;
    float rotZ;
    TeleportLoad();
};

struct MultiBound
{
    int unk00;
    int unk04;
    int unk08;
    MultiBound();
    void ReadFromFile(File*);
};
struct NavDoor
{
    int unk00;
    int unk04;
    NavDoor();
    void LoadFormRef(void*, File*, void*);
};
struct NavPortal
{
    int mesh;
    unsigned short triangle;
    unsigned short unk06;
    NavPortal();
    NavPortal(const NavPortal&);
    void FUN_004141e0();
};
struct PortalExtra
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    PortalExtra(NavPortal);
    ~PortalExtra();
};
struct Form
{
    int FUN_00401170();
};
struct Reference
{
    Form* FUN_007af430();
};
struct Power
{
    int ref;
    unsigned int flags;
    Power();
};
struct Primitive
{
    float x, y, z;
    float r, g, b, a;
    int type;
    Primitive();
    void FUN_00414290();
};
void* __cdecl FUN_004a4e90(int, void*, void*);
struct OcclusionLoad
{
    float posX, posY;
    float rotX, rotY, rotZ;
    float width, height, depth, angle;
    OcclusionLoad();
    void FUN_004140f0();
};
struct Matrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    Matrix();
    void FUN_004168a0(float, float, float, float);
};
struct Plane
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
    static void* __cdecl operator new(unsigned int);
    static void __cdecl operator delete(void*, unsigned int);
    Plane();
    void FUN_00416a30(void*);
    void FUN_004169f0(void*);
    void FUN_00416a70(Matrix*);
};
struct PatrolValue
{
    int value;
    PatrolValue();
    void FUN_00503210();
};
struct PatrolData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    PatrolData(PatrolValue*);
};
struct ActionData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ActionData();
    void ProcessAllElements();
};
struct DroppedData
{
    int unk00;
    int unk04;
    DroppedData();
    void FUN_00462230();
};
struct FormList
{
    void* head;
    void* next;
    void FUN_005ae3d0(void* const&);
};
struct RoomData
{
    int unk00;
    int unk04;
    FormList refs;
    unsigned char flags;
    unsigned char unk11;
    unsigned short unk12;
    RoomData();
};
struct TriData
{
    int unk00;
    TriData();
    void FUN_00503210();
};
struct PatrolScript
{
    void FUN_0067dd20(File*);
};
struct PatrolRef
{
    int unk00;
    PatrolScript script;
};
struct RefExtra
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float value;
    RefExtra();
    void FUN_0041fd00(int);
};

struct List
{
    void LoadExtraData(File*, void*);
    void FUN_0041b3d0(int);
    void FUN_00419700(int);
    void SetExtraDataValue(int);
    void FUN_004198a0(int);
    void FUN_00419970(float);
    void SetHealthPerc(float);
    void FUN_00419a20(unsigned char);
    void FUN_00419bb0(float);
    void FUN_00419ad0(unsigned short);
    void SetOwnership(int, int);
    void FUN_00419c60(float);
    void FUN_00419d10(int);
    void FUN_0041bd10(int);
    void SetAcousticSpace(int);
    void SetClimate(int);
    void SetImageSpaceExtra(int);
    void SetCellWaterType(int);
    void FUN_0041e250(int);
    void FUN_0041e440(int);
    void FUN_00421430(int);
    void FUN_00421b70(int);
    void FUN_00421c60(int);
    void SetEmittanceSource(int);
    void FUN_00421e40(int);
    void FUN_00421540(int);
    void FUN_00422220(float);
    void SetRadiation(float);
    void SetIgnoredBySandbox(bool);
    Ammo* GetExtraAmmo();
    void* FUN_00410220(unsigned char);
    void* FUN_0040ff60(void*);
    void SetRadioData(Radio*);
    Teleport* FUN_00418460();
    void FUN_00419120(Teleport*);
    Marker* FUN_00418490();
    void SetMapMarker(Marker*);
    AudioMarker* FUN_004184c0();
    void SetAudioMarker(AudioMarker*);
    AcousticMarker* GetEntryValue();
    void FUN_004194b0(AcousticMarker*);
    void FUN_0041ac30(unsigned char);
    void SetRegionList(RegionList*);
    void FUN_0041ad00(int, int, void*, float);
    void FUN_00410020(void*, bool);
    void FUN_0041d950(Point*);
    void FUN_0041da40(int);
    void SetExtraFlags(unsigned char);
    void SetTextOverride(char*);
    void FUN_0041f080(int, void*, void*);
    void FUN_00421f30(MultiBound*);
    void EnsureNavMeshPortalExtra(PortalExtra*);
    void FUN_0041f1a0(int, bool);
    void SetRefInReflectorList(int, bool);
    void AddOrRemoveRef(int, bool);
    void AddPrimitiveExtra(void*);
    void FUN_00422150(Plane*);
    void SetPatrolRefData(PatrolData*);
    void FUN_0041fec0(ActionData*);
    void FUN_00420210(DroppedData*);
    void FUN_00420440(RoomData*);
    void FUN_00420fd0(TriData*);
    PatrolRef* FUN_0041fe90();
};
}
// Reads an extra-data chunk from the file, dispatching on the 4-byte tag to load and apply the corresponding extra data type.
// @fnv 0x004144a0
void loader::List::LoadExtraData(File* file, void* owner)
{
    switch (file->FUN_004726b0())
    {
    case 0x54434158: {
        int value = 0;
        file->ReadChunkInt(&value);
        FUN_0041b3d0(value);
        break;
    }
    case 0x4e574f58: {
        int value = 0;
        file->ReadChunkInt(&value);
        FUN_00419700(value);
        break;
    }
    case 0x424c4758: {
        int value = 0;
        file->ReadChunkInt(&value);
        SetExtraDataValue(value);
        break;
    }
    case 0x4b4e5258: {
        int value = 0;
        file->ReadChunkInt(&value);
        FUN_004198a0(value);
        break;
    }
    case 0x544c4858: {
        int value = 0;
        file->ReadChunkInt(&value);
        FUN_00419970((float)value);
        break;
    }
    case 0x504c4858: {
        float value = 0.0f;
        file->ReadChunkInt(&value);
        SetHealthPerc(value);
        break;
    }
    case 0x45535558: {
        int value = 0;
        file->ReadChunkInt(&value);
        FUN_00419a20((unsigned char)value);
        break;
    }
    case 0x4d495458: {
        float value = 0.0f;
        file->ReadChunkInt(&value);
        FUN_00419bb0(value);
        break;
    }
    case 0x544e4358: {
        int value = 0;
        file->ReadChunkInt(&value);
        FUN_00419ad0((unsigned short)value);
        break;
    }
    case 0x434d4158: {
        int value = 0;
        file->ReadChunkInt(&value);
        if (GetExtraAmmo())
            SetOwnership(GetExtraAmmo()->ammo, value);
        break;
    }
    case 0x544d4158: {
        int value = 0;
        file->ReadChunkInt(&value);
        SetOwnership(value, 999);
        break;
    }
    case 0x47484358: {
        float value = 0.0f;
        file->ReadChunkInt(&value);
        FUN_00419c60(value);
        break;
    }
    case 0x4e535058: {
        int value = 0;
        file->ReadChunkInt(&value);
        FUN_00419d10(value);
        break;
    }
    case 0x434f4c58: {
        LockExtra* extra = (LockExtra*)FUN_00410220(0x2a);
        PathingActorState* data = 0;
        if (!extra)
        {
            data = new PathingActorState;
            extra = new LockExtra(data);
            FUN_0040ff60(extra);
        }
        else
            data = extra->data;
        file->GetChunkData(data, 0x14);
        if (file->FUN_00401680())
            data->FUN_0060ce80();
        data->FUN_00430a90(true);
        break;
    }
    case 0x4f445258: {
        Radio data;
        file->GetChunkData(&data, 0x10);
        if (file->FUN_00401680())
            data.FUN_00414220();
        SetRadioData(&data);
        break;
    }
    case 0x4c455458: {
        Teleport* data = FUN_00418460();
        if (!data)
        {
            data = new Teleport;
            FUN_00419120(data);
        }
        data->FUN_0043a4e0(file);
        break;
    }
    case 0x4b524d58: {
        Marker* data = FUN_00418490();
        if (!data)
        {
            data = new Marker;
            SetMapMarker(data);
        }
        data->FUN_00438ca0(file);
        break;
    }
    case 0x4b524d4d: {
        AudioMarker* data = FUN_004184c0();
        if (!data)
        {
            data = new AudioMarker;
            SetAudioMarker(data);
        }
        data->LoadFromFile(file);
        break;
    }
    case 0x4b524d41: {
        AcousticMarker* data = GetEntryValue();
        if (!data)
        {
            data = new AcousticMarker;
            FUN_004194b0(data);
        }
        data->FUN_00589890(file);
        break;
    }
    case 0x44455358: {
        unsigned char value = 0;
        if (file->GetField25C() == 4)
        {
            int oldValue = 0;
            file->ReadChunkInt(&oldValue);
            value = (unsigned char)oldValue;
        }
        else
            file->GetChunkData(&value, 1);
        FUN_0041ac30(value);
        break;
    }
    case 0x524c4358: {
        unsigned int size = file->GetField25C();
        unsigned int count = size / 4;
        if (size % 4)
        {
            warning("MASTERFILE: Invalid Extra Data - Region List in file \"%s\".", file->FUN_00891170());
            break;
        }
        RegionList* m_pRegions = new RegionList(0);
        Region* pRegion = 0;
        unsigned int* pRegions = new unsigned int[count];
        file->GetChunkData(pRegions, size);
        for (unsigned int index = 0; index < count; ++index)
        {
            if (file->FUN_00401680())
                endian(&pRegions[index], EndianTag());
            ResolveFormID(&pRegions[index], file);
            pRegion = g_dataHandler->FUN_004169d0()->FUN_004f66c0(pRegions[index]);
            if (pRegion)
                m_pRegions->AddRegion(pRegion);
        }
        SetRegionList(m_pRegions);
        delete[] pRegions;
        break;
    }
    break;
    case 0x544d4358: {
        unsigned char value = 0;
        file->GetChunkData(&value, 1);
        break;
    }
    case 0x4f4d4358: {
        int value = 0;
        file->ReadChunkInt(&value);
        FUN_0041bd10(value);
        break;
    }
    case 0x54454358: {
        unsigned char value = 0;
        file->GetChunkData(&value, 1);
        break;
    }
    case 0x53414358: {
        int value = 0;
        file->ReadChunkInt(&value);
        SetAcousticSpace(value);
        break;
    }
    case 0x4d434358: {
        int value = 0;
        file->ReadChunkInt(&value);
        SetClimate(value);
        break;
    }
    case 0x4d494358: {
        int value = 0;
        file->ReadChunkInt(&value);
        SetImageSpaceExtra(value);
        break;
    }
    case 0x54574358: {
        int value = 0;
        file->ReadChunkInt(&value);
        SetCellWaterType(value);
        break;
    }
    case 0x4c535058: {
        LinkedData data;
        memset(&data, 0, 0x14);
        file->GetChunkData(&data, 0x14);
        if (file->FUN_00401680())
            data.FUN_00414220();
        FUN_0041ad00(data.ref, 0, &data.posX, data.heading);
        break;
    }
    case 0x44475258:
    case 0x42475258: {
        RagdollData* ragdollData = 0;
        RagdollExtra* extra = (RagdollExtra*)FUN_00410220(0x14);
        if (extra)
            ragdollData = extra->data;
        else
        {
            extra = new RagdollExtra;
            extra->data = new RagdollData;
            FUN_0040ff60(extra);
            ragdollData = extra->data;
        }
        if (!ragdollData->LoadRagdollChunk(file))
        {
            warning("MASTERFILE: Failed to load RagDoll Data.");
            FUN_00410020(extra, true);
        }
        break;
    }
    case 0x444f4c58: {
        Point data(0.0f, 0.0f, 0.97f);
        file->GetChunkData(&data, 12);
        if (file->FUN_00401680())
        {
            endian(&data.x, EndianTag());
            endian(&data.y, EndianTag());
            endian(&data.z, EndianTag());
        }
        FUN_0041d950(&data);
        break;
    }
    case 0x50534558: {
        ParentData data;
        memset(&data, 0, 8);
        file->GetChunkData(&data, 8);
        if (file->FUN_00401680())
            data.FUN_00503210();
        FUN_0041da40(data.ref);
        SetExtraFlags(data.flags);
        break;
    }
    case 0x4d545258: {
        int value = 0;
        file->ReadChunkInt(&value);
        FUN_0041e250(value);
        break;
    }
    case 0x524b4c58: {
        int value = 0;
        file->ReadChunkInt(&value);
        FUN_0041e440(value);
        break;
    }
    case 0x44504158: {
        ExtraPackage* extra = (ExtraPackage*)FUN_00410220(0x53);
        if (!extra)
        {
            extra = new ExtraPackage;
            FUN_0040ff60(extra);
        }
        if (file->GetField25C() == 4)
        {
            int value = 0;
            file->ReadChunkInt(&value);
            extra->flags = (unsigned char)value;
        }
        else
            file->GetChunkData(&extra->flags, 1);
        break;
    }
    case 0x4f544158: {
        ExtraPackage* extra = (ExtraPackage*)FUN_00410220(0x53);
        if (!extra)
        {
            extra = new ExtraPackage;
            FUN_0040ff60(extra);
        }
        int size = file->GetField25C();
        if (size > 1)
        {
            char* data = new char[size];
            file->GetChunkData(data, size);
            SetTextOverride(data);
            delete[] data;
        }
        break;
    }
    case 0x52504158: {
        ExtraPackage* extra = (ExtraPackage*)FUN_00410220(0x53);
        if (!extra)
        {
            extra = new ExtraPackage;
            FUN_0040ff60(extra);
        }
        PackageRef* pData = new PackageRef;
        file->GetChunkData(pData, 8);
        if (file->FUN_00401680())
            pData->FUN_00462230();
        extra->list.FUN_005ae3d0(pData);
        break;
    }
    case 0x52434158: {
        ExtraPackage* pExtra = (ExtraPackage*)FUN_00410220(0x53);
        if (!pExtra)
        {
            pExtra = new ExtraPackage;
            FUN_0040ff60(pExtra);
        }
        PackageCombat value;
        memset(&value, 0, 12);
        file->GetChunkData(&value, 12);
        if (file->FUN_00401680())
        {
            endian(&value.ref, EndianTag());
            endian(&value.value, EndianTag());
        }
        PackageRef* pData = new PackageRef;
        pData->ref = value.ref;
        pData->value = value.value;
        pExtra->list.FUN_005ae3d0(pData);
        pExtra->flags = value.flag;
        break;
    }
    case 0x52434458: {
        TeleportLoad data;
        memset(&data, 0, 28);
        file->GetChunkData(&data, 28);
        if (file->FUN_00401680())
        {
            endian(&data.ref, EndianTag());
            endian(&data.posX, EndianTag());
            endian(&data.posY, EndianTag());
            endian(&data.posZ, EndianTag());
            endian(&data.rotX, EndianTag());
            endian(&data.rotY, EndianTag());
            endian(&data.rotZ, EndianTag());
        }
        FUN_0041f080(data.ref, &data.posX, &data.rotX);
        break;
    }
    case 0x43524d58: {
        int value = 0;
        file->ReadChunkInt(&value);
        FUN_00421430(value);
        break;
    }
    case 0x47525458: {
        int value = 0;
        file->ReadChunkInt(&value);
        FUN_00421b70(value);
        break;
    }
    case 0x4e5a4558: {
        int value = 0;
        file->ReadChunkInt(&value);
        FUN_00421c60(value);
        break;
    }
    case 0x494d4558: {
        int value = 0;
        file->ReadChunkInt(&value);
        SetEmittanceSource(value);
        break;
    }
    case 0x52424d58: {
        int value = 0;
        file->ReadChunkInt(&value);
        FUN_00421e40(value);
        break;
    }
    case 0x4f424d58: {
        MultiBound* data = new MultiBound;
        data->ReadFromFile(file);
        FUN_00421f30(data);
        break;
    }
    case 0x4d434c58: {
        int value = 0;
        file->ReadChunkInt(&value);
        FUN_00421540(value);
        break;
    }
    case 0x49435058: {
        file->FUN_004726f0();
        break;
    }
    case 0x50564e58: {
        NavDoor pData;
        unsigned int size = file->GetField25C();
        char* buffer = new char[size];
        file->GetChunkData(buffer, size);
        pData.LoadFormRef(owner, file, buffer);
        delete[] buffer;
        break;
    }
    case 0x50444e58: {
        NavPortal pData;
        file->GetChunkData(&pData, 8);
        if (file->FUN_00401680())
            pData.FUN_004141e0();
        PortalExtra extra(pData);
        EnsureNavMeshPortalExtra(&extra);
        break;
    }
    case 0x53445258: {
        float value = 0.0f;
        file->ReadChunkInt(&value);
        FUN_00422220(value);
        break;
    }
    case 0x44415258: {
        float value = 0.0f;
        file->ReadChunkInt(&value);
        SetRadiation(value);
        break;
    }
    case 0x52575058: {
        Reference* ref = (Reference*)owner;
        if (ref->FUN_007af430() && ref->FUN_007af430()->FUN_00401170() == 0x23)
            break;
        Power pData;
        memset(&pData, 0, 8);
        file->GetChunkData(&pData, 8);
        if (file->FUN_00401680())
        {
            endian(&pData.ref, EndianTag());
            endian(&pData.flags, EndianTag());
        }
        if (pData.flags & 1)
            FUN_0041f1a0(pData.ref, true);
        if (pData.flags & 2)
            SetRefInReflectorList(pData.ref, true);
        break;
    }
    case 0x57544c58: {
        Reference* ref = (Reference*)owner;
        if (ref->FUN_007af430() && ref->FUN_007af430()->FUN_00401170() == 0x23)
            break;
        int value;
        file->ReadChunkInt(&value);
        AddOrRemoveRef(value, true);
        break;
    }
    case 0x4d525058: {
        Primitive data;
        memset(&data, 0, 32);
        file->GetChunkData(&data, 32);
        if (file->FUN_00401680())
            data.FUN_00414290();
        void* primitive = FUN_004a4e90(data.type, &data, &data.r);
        if (primitive)
            AddPrimitiveExtra(primitive);
        break;
    }
    case 0x50434f58: {
        OcclusionLoad data;
        memset(&data, 0, 36);
        file->GetChunkData(&data, 36);
        if (file->FUN_00401680())
            data.FUN_004140f0();
        Plane* pData = new Plane;
        pData->FUN_00416a30(&data);
        pData->FUN_004169f0(&data.rotX);
        Matrix matrix;
        matrix.FUN_004168a0(data.angle, data.width, data.height, data.depth);
        pData->FUN_00416a70(&matrix);
        FUN_00422150(pData);
        break;
    }
    case 0x4c545058: {
        OcclusionLoad data;
        memset(&data, 0, 36);
        file->GetChunkData(&data, 36);
        if (file->FUN_00401680())
            data.FUN_004140f0();
        break;
    }
    break;
        break;
    case 0x44525058: {
        PatrolValue value;
        file->GetChunkData(&value, 4);
        if (file->FUN_00401680())
            value.FUN_00503210();
        PatrolData* data = new PatrolData(&value);
        SetPatrolRefData(data);
        break;
    }
    case 0x44524f58: {
        ActionData* data = new ActionData;
        file->GetChunkData(data, 16);
        if (file->FUN_00401680())
            data->ProcessAllElements();
        FUN_0041fec0(data);
        break;
    }
    case 0x444f5058: {
        DroppedData* data = new DroppedData;
        file->GetChunkData(data, 8);
        if (file->FUN_00401680())
            data->FUN_00462230();
        FUN_00420210(data);
        break;
    }
    case 0x524d5258: {
        RoomData* roomData = new RoomData;
        unsigned int roomCount = 0;
        file->ReadChunkInt(&roomCount);
        unsigned int flags = roomCount >> 16;
        roomData->flags = (unsigned char)flags;
        roomCount &= 0xffff;
        for (unsigned int index = 0; index < roomCount; ++index)
        {
            unsigned int value = 0;
            file->FUN_004726f0();
            file->ReadChunkInt(&value);
            roomData->refs.FUN_005ae3d0((void*)value);
        }
        FUN_00420440(roomData);
        break;
    }
    case 0x49525458: {
        TriData* data = new TriData;
        file->GetChunkData(data, 4);
        if (file->FUN_00401680())
            data->FUN_00503210();
        FUN_00420fd0(data);
        break;
    }
    case 0x41505058: {
        PatrolRef* data = FUN_0041fe90();
        file->FUN_004726f0();
        data->script.FUN_0067dd20(file);
        break;
    }
    case 0x53424958: {
        SetIgnoredBySandbox(true);
        break;
    }
    case 0x46525358: {
        RefExtra* extra = (RefExtra*)FUN_00410220(0x92);
        if (!extra)
            extra = (RefExtra*)FUN_0040ff60(new RefExtra);
        int value = 0;
        file->ReadChunkInt(&value);
        extra->FUN_0041fd00(value);
        break;
    }
    case 0x44525358: {
        RefExtra* extra = (RefExtra*)FUN_00410220(0x92);
        if (!extra)
            extra = (RefExtra*)FUN_0040ff60(new RefExtra);
        float value = 0.0f;
        file->ReadChunkInt(&value);
        extra->value = value;
        break;
    }
    }
}

// Copy the value from extra data type 0x8a into the output, or clear the output when the extra is missing.

class C8980Value
{
  public:
    void CopyFrom(const void* pvSource);
    void Clear();
};

struct C8980Extra
{
    int unk00;
    int unk04;
    int unk08;
    int m_iData;
};

class C8980ExtraList
{
  public:
    C8980Extra* GetExtraData(unsigned char ucType);
    void GetExtraValue(C8980Value& kOut);
};

// Looks up extra data of type 0x8a and copies its m_iData into kOut, or clears kOut when no extra data exists.
// @fnv 0x00418980
void C8980ExtraList::GetExtraValue(C8980Value& kOut)
{
    C8980Extra* pkExtra = GetExtraData(0x8a);
    if (pkExtra)
        kOut.CopyFrom(&pkExtra->m_iData);
    else
        kOut.Clear();
}

class Data418
{
  public:
    ~Data418();

    int unk00;
};

class ExtraData418
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned char m_ucType;
    ExtraData418* m_pkNext;
};

class ExtraHolder418 : public ExtraData418
{
  public:
    ExtraHolder418(Data418* pkData);

    Data418* m_pUserData;
};

class ExtraList418
{
  public:
    ExtraData418* GetByType(unsigned char ucType);
    ExtraData418* Add(ExtraData418* pkExtra);
    ExtraHolder418* FUN_00418e30(Data418* pkData);
};

// Finds the extra of type 0x29, replacing its stored Data418 with pkData, or creates and adds a new holder if none exists.
// @fnv 0x00418e30
ExtraHolder418* ExtraList418::FUN_00418e30(Data418* pkData)
{
    ExtraHolder418* pkExtra = (ExtraHolder418*)GetByType(0x29);
    if (pkExtra)
    {
        delete pkExtra->m_pUserData;
        pkExtra->m_pUserData = pkData;
        return pkExtra;
    }
    pkExtra = new ExtraHolder418(pkData);
    Add(pkExtra);
    return pkExtra;
}

struct SoundHandle41a
{
    unsigned int m_uiSoundResourceID;
    bool m_bLooping;
    int eState;
    SoundHandle41a();
    SoundHandle41a(const SoundHandle41a&);
    ~SoundHandle41a();
    SoundHandle41a& operator=(const SoundHandle41a&);
    bool operator==(const SoundHandle41a&) const;
    bool operator!=(const SoundHandle41a&) const;
};

struct ExtraSoundX : BSExtraData
{
    SoundHandle41a kHandle;
    ExtraSoundX(SoundHandle41a);
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};

struct SoundExtraList41a : BaseExtraList
{
    void RemoveExtraX(BSExtraData* apExtra, bool abFree);
    void FUN_0041a280(const SoundHandle41a& arHandle);
};

// Sets the extra sound handle: removes the ExtraSoundX if the handle is empty, updates it if present, otherwise adds a new one.
// @fnv 0x0041a280
void SoundExtraList41a::FUN_0041a280(const SoundHandle41a& arHandle)
{
    ExtraSoundX* pExtra = (ExtraSoundX*)GetExtraData(0x8a);
    if (pExtra)
    {
        if (arHandle == SoundHandle41a())
        {
            RemoveExtraX(pExtra, true);
        }
        else
        {
            pExtra->kHandle = arHandle;
        }
    }
    else if (arHandle != SoundHandle41a())
    {
        pExtra = new ExtraSoundX(arHandle);
        AddExtra(pExtra);
    }
}

struct Tmp0041a250
{
    int unk00;
    int unk04;
    int unk08;
    Tmp0041a250();
    ~Tmp0041a250();
};

struct Val0041a1f0
{
    int unk00;
    int unk04;
    int unk08;
    Val0041a1f0(const Val0041a1f0&);
    ~Val0041a1f0();
    Val0041a1f0& operator=(const Val0041a1f0&);
    bool Equals(const Tmp0041a250&);
    bool IsNotEqual(const Tmp0041a250&);
};

struct ExtraVal18 : public BSExtraData
{
    int unk0C;
    int unk10;
    int unk14;
    ExtraVal18(Val0041a1f0 v);
};

struct ExtraListHolder : public BaseExtraList
{
    void FUN_0041a6a0(Val0041a1f0* val);
    void FUN_00410020(BSExtraData*, bool);
};

// Updates or creates extra data of type 0x87 from val, removing it if Equals matches, otherwise storing or adding it.
// @fnv 0x0041a6a0
void ExtraListHolder::FUN_0041a6a0(Val0041a1f0* pValue)
{
    BSExtraData* extra = GetExtraData(0x87);
    if (extra)
    {
        if (pValue->Equals(Tmp0041a250()))
        {
            FUN_00410020(extra, true);
        }
        else
        {
            *(Val0041a1f0*)&((ExtraVal18*)extra)->unk0C = *pValue;
        }
    }
    else
    {
        if (pValue->IsNotEqual(Tmp0041a250()))
        {
            extra = new ExtraVal18(*pValue);
            AddExtra(extra);
        }
    }
}

// Return the count from the reference's extra-data list handle, or from an empty handle when it has none.

class B9A0Handle
{
  public:
    B9A0Handle(int iValue);
    ~B9A0Handle();
    int GetCount() const;

    void* m_pResource;
};

struct B9A0Extra
{
    int unk00;
    int unk04;
    int unk08;
    B9A0Handle m_kHandle;
};

class B9A0Ref
{
  public:
    B9A0Extra* GetExtraData(unsigned char ucType);
    int GetExtraHandleCount();
};

// @fnv 0x0041b9a0
int B9A0Ref::GetExtraHandleCount()
{
    B9A0Extra* pkExtra = GetExtraData(1);
    int iResult;
    const B9A0Handle* pkSource;
    iResult = (pkSource = pkExtra ? &pkExtra->m_kHandle : &B9A0Handle(0))->GetCount();
    return iResult;
}

struct RegionList
{
    virtual ~RegionList();
};

struct ExtraRegionList : BSExtraData
{
    RegionList* regions;
    ExtraRegionList(RegionList* value);
};

struct FUN_0041bbd0_shell : ExtraDataList
{
    void SetRegionList(RegionList* value);
};

// Sets or clears the region list extra data: removes it when value is null, creates it when absent, otherwise replaces the stored regions pointer.
// @fnv 0x0041bbd0
void FUN_0041bbd0_shell::SetRegionList(RegionList* pRegions)
{
    ExtraRegionList* data = static_cast<ExtraRegionList*>(GetExtraData(4));
    if (pRegions == 0)
    {
        if (data)
            reinterpret_cast<Dummy_00410020*>(this)->FUN_00410020(data, true);
    }
    else if (data == 0)
    {
        data = new ExtraRegionList(pRegions);
        AddExtra(data);
    }
    else
    {
        if (data->regions && data->regions != pRegions)
            delete data->regions;
        data->regions = pRegions;
    }
}

struct FUN_0041ce10_shell : public ExtraDataList
{
    void ClearScript(Script* apScript);
};

// Clears the script pointer of the ExtraScript extra data (type 0x1A) when it matches apScript.
// @fnv 0x0041ce10
void FUN_0041ce10_shell::ClearScript(Script* apScript)
{
    ExtraScript* pExtra = static_cast<ExtraScript*>(GetExtraData(0x1A));
    if (pExtra != 0 && pExtra->pScript == apScript)
        pExtra->pScript = 0;
}

struct RunOnceListNode;

struct RunOnceItem
{
    TESPackage* pPackage;
    char bFlag04;
};

struct RunOnceOwner
{
    int unk00;
    int unk04;
    int unk08;
    RunOnceListNode* pRunOnceList;
};

signed char __fastcall FUN_0086a460(DurationData* sched);
void __cdecl FormHeap_Free(RunOnceItem* item);

struct FUN_00410220_shell
{
    RunOnceOwner* FUN_00410220(int);
};

struct FUN_0041d7b0_cls
{
    void RemoveRunOnceItems(char bArg);
};

// @fnv 0x0041d7b0
void FUN_0041d7b0_cls::RemoveRunOnceItems(char abKeepFlag)
{
    RunOnceOwner* owner = reinterpret_cast<FUN_00410220_shell*>(this)->FUN_00410220(0x1b);
    if (owner != 0)
    {
        RunOnceListNode* cur = owner->pRunOnceList;
        while (cur != 0 && *_ref_006815c0(cur) != 0)
        {
            RunOnceItem* item = (RunOnceItem*)*_ref_006815c0(cur);
            bool match = false;
            if (item != 0 && item->pPackage != 0)
            {
                TESPackage* pkg = item->pPackage;
                DurationData* sched = reinterpret_cast<FUN_0041d8a0_shell*>(pkg)->FUN_0041d8a0();
                if (FUN_0086a460(sched) + (int)_ref_00726070((RunOnceListNode*)sched) >= 0x15)
                {
                    match = true;
                }
            }
            if (item->bFlag04 != abKeepFlag || match)
            {
                reinterpret_cast<ContNode*>(owner->pRunOnceList)->FUN_00905330(&item);
                RunOnceItem* doomed = item;
                FormHeap_Free(doomed);
                cur = owner->pRunOnceList;
            }
            else
            {
                cur = _ref_00726070(cur);
            }
        }
    }
}

struct TESObjectREFR;
struct RefListNode
{
    unsigned char FUN_008256d0();
    TESObjectREFR*** FUN_006815c0();
    RefListNode* FUN_00726070();
    void FUN_0063f7b0();
    void FUN_00905330(TESObjectREFR*** entry);
};
struct FUN_0041ef20_shell : ExtraDataList
{
    void FUN_0041ef20(TESObjectREFR* reference);
};
// Removes the given reference from the ExtraWaterLightRefs list, deleting its entry and freeing the extra data when the list becomes empty.
// @fnv 0x0041ef20
void FUN_0041ef20_shell::FUN_0041ef20(TESObjectREFR* reference)
{
    if (reference)
    {
        ExtraWaterLightRefs* extra = (ExtraWaterLightRefs*)GetExtraData(0x54);
        if (extra)
        {
            RefListNode* current = (RefListNode*)&extra->refs;
            RefListNode* previous = 0;
            while (current && !current->FUN_008256d0())
            {
                TESObjectREFR** item = *current->FUN_006815c0();
                if (*item == reference)
                {
                    if (previous)
                    {
                        previous->FUN_00905330(&item);
                    }
                    else
                    {
                        current->FUN_0063f7b0();
                    }
                    delete item;
                    break;
                }
                current = current->FUN_00726070();
            }
            if (((RefListNode*)&extra->refs)->FUN_008256d0())
                ((FUN_00410020_shell*)this)->FUN_00410020(extra, true);
        }
    }
}

struct FlagItem
{
    TESObjectREFR* ref;
    unsigned int flags;
};
struct FlagNode
{
    FlagItem* item;
    FlagNode* next;
    FlagItem** FUN_006815c0();
    FlagNode* FUN_00726070();
    bool FUN_008256d0();
};
struct FlagExtra
{
    unsigned int unk00, unk04, unk08;
    FlagNode list;
    void FUN_00434800(TESObjectREFR*);
    void AddReflectedRef(TESObjectREFR*, unsigned int);
};
struct WorkerExtraList : BaseExtraList
{
    void FUN_0041f650(TESObjectREFR* ref, bool enabled);
};
// Walks the extra-data flag list for ref; sets or clears bit 2, removes the entry when its flags reach zero, and creates the extra data when enabling.
// @fnv 0x0041f650
void WorkerExtraList::FUN_0041f650(TESObjectREFR* ref, bool enabled)
{
    FlagExtra* p = (FlagExtra*)GetExtraData(101);
    if (p)
    {
        FlagNode* h = &p->list;
        while (h && *h->FUN_006815c0())
        {
            if ((*h->FUN_006815c0())->ref == ref)
            {
                if (enabled)
                    (*h->FUN_006815c0())->flags |= 2;
                else
                {
                    (*h->FUN_006815c0())->flags &= ~2;
                    if ((*h->FUN_006815c0())->flags == 0)
                    {
                        p->FUN_00434800(ref);
                        if (p->list.FUN_008256d0())
                            ((Dummy_00410020*)this)->FUN_00410020(p, true);
                    }
                }
                return;
            }
            h = h->FUN_00726070();
        }
    }
    if (enabled)
    {
        if (!p)
        {
            p = (FlagExtra*)new FUN_00411b40;
            AddExtra((BSExtraData*)p);
        }
        p->AddReflectedRef(ref, 2);
    }
}

void* __cdecl operator new(unsigned int uiSize);
void __cdecl operator delete(void* pvMem);

class C420160Values
{
  public:
    C420160Values();

    int m_aiValues0;
    int m_aiValues1;
    int m_aiValues2;
    int m_aiValues3;
};

class C420160ExtraData
{
  public:
    int* GetValues();
    void SetValues(C420160Values* pkValues);

    void FUN_00420160(int iValue, unsigned int uiIndex);
};

// Ensures the values array exists when iValue is non-zero, then stores iValue at uiIndex in the array returned by GetValues.
// @fnv 0x00420160
void C420160ExtraData::FUN_00420160(int iValue, unsigned int uiIndex)
{
    if (!GetValues() && iValue)
        SetValues(new C420160Values);

    int* piValues = GetValues();
    if (piValues)
        piValues[uiIndex] = iValue;
}

struct FUN_00420710
{
    BSSimpleList<int> unk00;
    BSSimpleList<int> unk08;
    ~FUN_00420710();
};

// Destructor for a struct holding two BSSimpleList<int> members; the empty body leaves their destruction to the compiler-generated member destructors.
// @fnv 0x00420710
FUN_00420710::~FUN_00420710()
{}

// Returns the address of the +8 member of the looked-up entry, or null when there is none.

class C420770Entry
{
  public:
    int unk00;
    int unk04;
    int m_iData;
};

class C420770Owner
{
  public:
    C420770Entry* GetEntry();
    int* FUN_00420770();
};

// Returns a pointer to the entry's m_iData field, or null if GetEntry returns null.
// @fnv 0x00420770
int* C420770Owner::FUN_00420770()
{
    C420770Entry* pkEntry = GetEntry();
    return pkEntry ? &pkEntry->m_iData : 0;
}

class Ref420;

class Handle420
{
  public:
    Ref420* Get() const;

    Ref420* m_pPointer;
};

class ExtraData420
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned char m_ucType;
    ExtraData420* m_pkNext;
};

class ExtraOwner420 : public ExtraData420
{
  public:
    Handle420 m_kOwner;
};

class ExtraList420
{
  public:
    ExtraData420* GetByType(unsigned char ucType);
    Ref420* FUN_00420ed0();
};

// Looks up the extra-data entry of type 0x79 and returns the owner reference it holds, or null if absent.
// @fnv 0x00420ed0
Ref420* ExtraList420::FUN_00420ed0()
{
    ExtraOwner420* pkExtra = (ExtraOwner420*)GetByType(0x79);
    if (pkExtra)
        return pkExtra->m_kOwner.Get();
    return 0;
}

struct LoadRefScriptLocals
{
    void FUN_005a9d00();
};

struct LoadRefExtraList
{
    void FUN_0041e0d0(struct LoadRefForm* apForm);
};

struct LoadRefOwner
{
    LoadRefExtraList* FUN_005d43c0();
};

struct LoadRefForm
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void v0DC();
    virtual void v0E0();
    virtual void v0E4();
    virtual void v0E8();
    virtual void v0EC();
    virtual void v0F0();
    virtual void v0F4();
    virtual void v0F8();
    virtual void v0FC();
    virtual bool IsActor();
};

struct LoadRefSaveLoadGame
{
    bool FUN_0055f5b0();
};

extern LoadRefSaveLoadGame* g_pLoadRefSaveLoadGame;

enum
{
    kLoadRefChange_Unused = 0,
    kLoadRefChange_00020000 = 0x20000,
    kLoadRefChange_10000000 = 0x10000000
};

struct LoadRef
{
    LoadRefScriptLocals* FUN_00418830();
    void FUN_005a9d00();
    void FUN_0041cda0();
    void FUN_00410140(int aiFlag);
    void* FUN_00418460();
    void RemoveExtraType43();
    void FUN_00422920();
    void FUN_0041cc60();
    void FUN_0041d930();
    void RemoveExtraType0x18();
    void FUN_00422720();
    void RemoveExtra045();
    void FUN_00419dc0(int aiValue);
    void RemoveExtra0x1F();
    void FUN_0042e040();
    void FUN_004216b0();
    LoadRefOwner* FUN_0041de00();
    void FUN_0041de40(LoadRefForm* apForm);
    void FUN_004267d0(unsigned int auiFlags, LoadRefForm* apForm);
};

// @fnv 0x004267d0
void LoadRef::FUN_004267d0(unsigned int auiFlags, LoadRefForm* apForm)
{
    bool bTargetIsActor = false;
    if (apForm && apForm->IsActor())
        bTargetIsActor = true;

    if (auiFlags & kLoadRefChange_Unused)
    {
        LoadRefScriptLocals* pLocals = FUN_00418830();
        if (pLocals)
            pLocals->FUN_005a9d00();
    }
    if ((auiFlags & kLoadRefChange_Unused) && bTargetIsActor)
        FUN_0041cda0();
    if ((auiFlags & kLoadRefChange_Unused) && !bTargetIsActor)
        FUN_00410140(0x12);
    if (auiFlags & kLoadRefChange_Unused)
        FUN_00410140(0x2e);
    if ((auiFlags & kLoadRefChange_Unused) && !bTargetIsActor)
    {
        FUN_00410140(0x32);
        FUN_00410140(0x33);
    }
    if ((auiFlags & kLoadRefChange_00020000) && !bTargetIsActor)
    {
        void* pData = FUN_00418460();
        if (pData)
            RemoveExtraType43();
    }
    if (auiFlags & kLoadRefChange_10000000)
        FUN_00422920();
    if ((auiFlags & kLoadRefChange_Unused) && bTargetIsActor)
        FUN_0041cda0();
    if ((auiFlags & kLoadRefChange_Unused) && !bTargetIsActor)
        FUN_00410140(0x12);
    if (auiFlags & kLoadRefChange_Unused)
        FUN_00410140(0x2e);

    if (g_pLoadRefSaveLoadGame->FUN_0055f5b0())
    {
        if (bTargetIsActor)
        {
            FUN_0041cc60();
            FUN_0041d930();
            RemoveExtraType0x18();
            FUN_00422720();
            RemoveExtra045();
            FUN_00410140(0x3a);
            FUN_00419dc0(0);
            RemoveExtra0x1F();
            FUN_0042e040();
            FUN_004216b0();
        }
        else
        {
            LoadRefOwner* pOwner = FUN_0041de00();
            if (pOwner)
            {
                pOwner->FUN_005d43c0()->FUN_0041e0d0(apForm);
                FUN_0041de40(0);
            }
        }
    }
}

extern void* DAT_01015914[];

struct FUN_0042c760 : FUN_0040ec80_cls
{
    void** m_ppVirtualMethodTable;
    unsigned char m_type;
    void* m_next;
    int m_iFirstInteger;
    int m_uiContentCount;

    FUN_0042c760();
};

// @fnv 0x0042c760
FUN_0042c760::FUN_0042c760()
{
    init(13);
    m_ppVirtualMethodTable = DAT_01015914;
    m_iFirstInteger = 0;
    m_uiContentCount = 0;
}

extern int DAT_01015950;
struct S_0042c8c0
{
    int* vt;
    int unk04;
    int unk08;
    int unk0C;
    unsigned char unk10;
    S_0042c8c0* Initialize();
};

// Calls FUN_0040ec80 with 0x2f, sets vt to DAT_01015950, clears unk0C and unk10, and returns this.
// @fnv 0x0042c8c0
S_0042c8c0* S_0042c8c0::Initialize()
{
    ((Y00411e40*)this)->FUN_0040ec80(0x2f);
    vt = &DAT_01015950;
    unk0C = 0;
    unk10 = 0;
    return this;
}

struct TESScriptableForm
{
  public:
    virtual void ScriptVirtual();
    void* FUN_00726070();
};
struct ActorBaseFixup
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
    TESScriptableForm script;
};
struct ActorFixup
{
    ActorBaseFixup* FUN_004181e0();
};
struct FixupNode
{
    unsigned int* FUN_006815c0();
    FixupNode* FUN_00726070();
    bool FUN_008256d0();
    void SetItem(const unsigned int&);
    void Remove(const unsigned int&);
    void FUN_0063f7b0();
};
struct ExtraFixup
{
    int unk00;
    int unk04;
    int unk08;
    void* value0c;
    int unk10;
    void* value14;
    void* value18;
    void* value1c;
    void* value20;
};
struct FixupStream
{
    virtual unsigned char Version();
    virtual void Reserved();
    virtual TESObjectREFR* Reference();
    virtual Actor* ActorReference();
    BGSChangeFlags_s FUN_00428110();
};
struct FixupList
{
    ExtraFixup* GetExtraData(unsigned char);
    void RemoveExtra(unsigned char);
    void FUN_00422690(TESObjectREFR*);
    void* FUN_0041cb10();
    void FixupReferences(FixupStream*, TESForm*);
};
struct FixupRef
{
    FixupList* FUN_005d43c0();
};
struct FixupPackage
{
    int FUN_009611e0();
    void ComputePackageFlags(void*);
};
struct FixupEffects
{
    void FUN_0041e000(TESObjectREFR*);
    void FUN_0041e340(Actor*);
};
struct FixupVirtual
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void Load(FixupStream*);
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
    virtual void Load25(FixupStream*);
};
struct FixupTail
{
    void ResolveRef(FixupStream*);
};
struct FixupItem
{
    void AddActor(Actor*);
};
TESForm* __cdecl LookupFormByID(unsigned int);
void* __cdecl FUN_0040a250(void*);
void* __cdecl FUN_00825550(void*);
void __cdecl InitLoadGameForEffects(FixupStream*, FixupNode*);
extern TESObjectREFR* DAT_011dea3c;
extern unsigned int DAT_01183da0;
extern unsigned int DAT_01183d64;
extern unsigned int DAT_01183ee0;
extern unsigned int DAT_01183df8;
extern unsigned int DAT_01183dfc;
extern unsigned int DAT_01183e14;
extern unsigned int DAT_01183e84;
extern unsigned int DAT_01183d94;
extern unsigned int DAT_01183da4;
extern unsigned int DAT_01183ef0;
extern unsigned int DAT_01183e20;
extern unsigned int DAT_01183d98;
extern unsigned int DAT_01183e48;
extern unsigned int DAT_01183eac;
extern unsigned int DAT_01183f54;
extern unsigned int DAT_01183e04;
extern unsigned int DAT_01183ddc;
// @fnv 0x0042ceb0
void FixupList::FixupReferences(FixupStream* stream, TESForm* base)
{
    TESObjectREFR* reference = stream->Reference();
    Actor* actor = stream->ActorReference();
    if (stream->FUN_00428110().Test(DAT_01183da0))
    {
        ExtraFixup* heading = GetExtraData(0x1c);
        if (heading)
        {
            heading->value0c =
                heading->value0c ? dynamic_cast<TESObjectREFR*>(LookupFormByID((unsigned int)heading->value0c)) : 0;
        }
    }
    if (stream->FUN_00428110().Test(DAT_01183d64))
    {
        ExtraFixup* scriptExtra = GetExtraData(0xd);
        if (scriptExtra && base)
        {
            TESScriptableForm* script = 0;
            if (actor)
            {
                ActorBaseFixup* actorBase = ((ActorFixup*)actor)->FUN_004181e0();
                if (actorBase)
                    script = actorBase ? &actorBase->script : 0;
            }
            else
            {
                script = dynamic_cast<TESScriptableForm*>(base);
            }
            if (!script || !scriptExtra->value0c || script->FUN_00726070() != scriptExtra->value0c)
                RemoveExtra(0xd);
        }
    }
    if (reference)
    {
        if (stream->FUN_00428110().Test(DAT_01183ee0))
        {
            ExtraFixup* linked = GetExtraData(0x6c);
            if (linked)
            {
                linked->value0c =
                    linked->value0c ? dynamic_cast<TESObjectREFR*>(LookupFormByID((unsigned int)linked->value0c)) : 0;
                if (!linked->value0c)
                    RemoveExtra(0x6c);
            }
        }
        if (stream->FUN_00428110().Test(DAT_01183df8))
        {
            ExtraFixup* pCombatExtra = GetExtraData(0x32);
            if (pCombatExtra)
            {
                pCombatExtra->value18 = pCombatExtra->value18 ? FUN_0040a250(pCombatExtra->value18) : 0;
                pCombatExtra->value1c = pCombatExtra->value1c ? FUN_00825550(pCombatExtra->value1c) : 0;
                pCombatExtra->value20 =
                    pCombatExtra->value20
                        ? dynamic_cast<TESObjectREFR*>(LookupFormByID((unsigned int)pCombatExtra->value20))
                        : 0;
            }
        }
        if (stream->FUN_00428110().Test(DAT_01183dfc))
        {
            ExtraFixup* pMagicExtra = GetExtraData(0x33);
            if (pMagicExtra)
            {
                pMagicExtra->value1c =
                    pMagicExtra->value1c
                        ? dynamic_cast<TESObjectREFR*>(LookupFormByID((unsigned int)pMagicExtra->value1c))
                        : 0;
                InitLoadGameForEffects(stream, (FixupNode*)&pMagicExtra->value20);
            }
        }
        if (stream->FUN_00428110().Test(DAT_01183e14))
        {
            ExtraFixup* pFollowerExtra = GetExtraData(0x39);
            if (pFollowerExtra)
            {
                pFollowerExtra->value0c =
                    pFollowerExtra->value0c
                        ? dynamic_cast<TESObjectREFR*>(LookupFormByID((unsigned int)pFollowerExtra->value0c))
                        : 0;
                if (pFollowerExtra->value0c)
                {
                    ((FixupEffects*)((FixupRef*)pFollowerExtra->value0c)->FUN_005d43c0())->FUN_0041e000(reference);
                }
                else
                    RemoveExtra(0x39);
            }
        }
        if (stream->FUN_00428110().Test(DAT_01183e84))
        {
            ExtraFixup* pMobileExtra = GetExtraData(0x55);
            if (pMobileExtra)
            {
                pMobileExtra->value0c =
                    pMobileExtra->value0c
                        ? dynamic_cast<MobileObject*>(LookupFormByID((unsigned int)pMobileExtra->value0c))
                        : 0;
            }
        }
        if (actor)
        {
            if (stream->FUN_00428110().Test(DAT_01183d94))
            {
                ExtraFixup* package = GetExtraData(0x19);
                if (package)
                {
                    package->value0c =
                        package->value0c ? dynamic_cast<TESPackage*>(LookupFormByID((unsigned int)package->value0c)) : 0;
                    package->value14 = package->value14
                                           ? dynamic_cast<TESObjectREFR*>(LookupFormByID((unsigned int)package->value14))
                                           : 0;
                    if (package->value0c)
                    {
                        if (((FixupPackage*)package->value0c)->FUN_009611e0() == -1)
                            ((FixupPackage*)package->value0c)->ComputePackageFlags(package->value14);
                    }
                    else
                        RemoveExtra(0x19);
                }
            }
            if (stream->FUN_00428110().Test(DAT_01183da4))
            {
                ExtraFixup* pFollowersExtra = GetExtraData(0x1d);
                if (pFollowersExtra)
                {
                    FixupNode* current = (FixupNode*)pFollowersExtra->value0c;
                    FixupNode* previous = 0;
                    while (current && !current->FUN_008256d0())
                    {
                        unsigned int followerID = *current->FUN_006815c0();
                        bool shouldRemove = false;
                        if (followerID)
                        {
                            followerID = followerID ? (unsigned int)dynamic_cast<Actor*>(LookupFormByID(followerID)) : 0;
                            if (followerID)
                                current->SetItem(followerID);
                            else
                                shouldRemove = true;
                        }
                        else
                            shouldRemove = true;
                        if (shouldRemove)
                        {
                            if (previous)
                            {
                                previous->Remove(*current->FUN_006815c0());
                                current = previous->FUN_00726070();
                            }
                            else
                                current->FUN_0063f7b0();
                        }
                        else
                        {
                            previous = current;
                            current = current->FUN_00726070();
                        }
                    }
                    if (stream->Version() < 0xe)
                        FUN_00422690(DAT_011dea3c);
                }
            }
            if (stream->FUN_00428110().Test(DAT_01183ef0))
            {
                ExtraFixup* pPackageDataExtra = GetExtraData(0x70);
                if (pPackageDataExtra)
                {
                    if (pPackageDataExtra->value0c)
                    {
                        void* activePackage = FUN_0041cb10();
                        ((FixupVirtual*)pPackageDataExtra->value0c)->Load(stream);
                    }
                }
            }
            if (stream->FUN_00428110().Test(DAT_01183e20))
            {
                ExtraFixup* pTargetExtra = GetExtraData(0x3c);
                if (pTargetExtra)
                {
                    pTargetExtra->value0c =
                        pTargetExtra->value0c
                            ? dynamic_cast<TESObjectREFR*>(LookupFormByID((unsigned int)pTargetExtra->value0c))
                            : 0;
                }
            }
            if (stream->FUN_00428110().Test(DAT_01183d98))
            {
                ExtraFixup* pRunOnExtra = GetExtraData(0x1a);
                if (pRunOnExtra)
                {
                    if (pRunOnExtra->value0c)
                        ((FixupVirtual*)pRunOnExtra->value0c)->Load25(stream);
                }
            }
            if (stream->FUN_00428110().Test(DAT_01183e48))
            {
                ExtraFixup* pFriendHitExtra = GetExtraData(0x46);
                if (pFriendHitExtra)
                {
                    pFriendHitExtra->value0c =
                        pFriendHitExtra->value0c
                            ? dynamic_cast<TESObjectREFR*>(LookupFormByID((unsigned int)pFriendHitExtra->value0c))
                            : 0;
                }
            }
            if (stream->FUN_00428110().Test(DAT_01183eac))
            {
                ExtraFixup* owner = GetExtraData(0x5f);
                if (owner)
                {
                    owner->value14 = owner->value14 ? LookupFormByID((unsigned int)owner->value14) : 0;
                }
            }
            if (stream->FUN_00428110().Test(DAT_01183f54))
            {
                ExtraFixup* pWaterExtra = GetExtraData(0x89);
                if (pWaterExtra)
                {
                    pWaterExtra->value0c =
                        pWaterExtra->value0c
                            ? dynamic_cast<TESObjectREFR*>(LookupFormByID((unsigned int)pWaterExtra->value0c))
                            : 0;
                    if (pWaterExtra->value0c)
                        ((FixupEffects*)((FixupRef*)pWaterExtra->value0c)->FUN_005d43c0())->FUN_0041e340(actor);
                }
            }
            if (stream->FUN_00428110().Test(DAT_01183e04))
            {
                ExtraFixup* pAnimExtra = GetExtraData(0x35);
                if (pAnimExtra)
                {
                    FixupNode* pAnimationNode = (FixupNode*)pAnimExtra->value0c;
                    while (pAnimationNode)
                    {
                        FixupItem* item = (FixupItem*)*pAnimationNode->FUN_006815c0();
                        if (item)
                            item->AddActor(actor);
                        pAnimationNode = pAnimationNode->FUN_00726070();
                    }
                }
            }
        }
        else
        {
            if (stream->FUN_00428110().Test(DAT_01183ddc))
            {
                ExtraFixup* pLeveledExtra = GetExtraData(0x2b);
                if (pLeveledExtra)
                {
                    ((FixupTail*)pLeveledExtra->value0c)->ResolveRef(stream);
                }
            }
        }
    }
}

struct FUN_00422c20_shell : public ExtraDataList
{
    void FUN_00422c20();
};

struct FUN_004280f0_shell : public ExtraDataList
{
    bool FUN_004280f0();
};

struct FUN_00410140_shell : public ExtraDataList
{
    void FUN_00410140(int);
};

struct FUN_0042ce30_shell : public ExtraDataList
{
    FUN_004280f0_shell* FUN_0042ce30(unsigned int*, unsigned int);
};

struct FUN_0042dd90_cls : public ExtraDataList
{
    void FUN_0042dd90(FUN_0042ce30_shell* arg);
};

// @fnv 0x0042dd90
void FUN_0042dd90_cls::FUN_0042dd90(FUN_0042ce30_shell* pExtraList)
{
    unsigned int flags;
    ((FUN_00422aa0_shell*)this)->FUN_00422aa0();
    ((FUN_00422c20_shell*)this)->FUN_00422c20();
    ((FUN_00422920_shell*)this)->FUN_00422920();
    if (pExtraList->FUN_0042ce30(&flags, 0x80000000)->FUN_004280f0())
    {
        ((FUN_00410140_shell*)this)->FUN_00410140(0x12);
    }
}

class NiAVObject
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual NiNode* AsNode();
};

class NiNode : public NiAVObject
{
  public:
    NiAVObject* FUN_0043b4a0(int index);
};

struct Acoustic
{
    bool FUN_00452440();
};

struct Ref : TESObjectREFR
{
    Acoustic* GetAcousticSpace();
};

struct Finder
{
    int unk00;
    int unk04;
    NiAVObject* FUN_004e8030(Ref* ref);
};

// @fnv 0x004e8030
NiAVObject* Finder::FUN_004e8030(Ref* ref)
{
    if (!ref || !ref->GetNiNode())
        return 0;
    Acoustic* acoustic = ref->GetAcousticSpace();
    ++unk04;
    if (ref->GetNiNode() && ((NiAVObject*)ref->GetNiNode())->AsNode())
    {
        NiNode* root = ref->GetNiNode();
        NiAVObject* node = root->FUN_0043b4a0(0);
        if (node && node->AsNode())
        {
            NiNode* outer = (NiNode*)node;
            NiAVObject* child = outer->FUN_0043b4a0(0);
            if (acoustic && acoustic->FUN_00452440())
            {
                if (child && child->AsNode())
                {
                    NiNode* inner = (NiNode*)child;
                    if (inner)
                        return inner->FUN_0043b4a0(0);
                }
            }
            else
            {
                return child;
            }
        }
    }
    return 0;
}

void __cdecl FUN_00401080(int* p);
struct Tag414
{
};
struct Arr414
{
    int m_kPointA[4];
    void ProcessAllElements();
};
// @fnv 0x00414370
void Arr414::ProcessAllElements()
{
    for (int i = 0; i < 4; i++)
        ((void(__cdecl*)(int*, Tag414))FUN_00401080)(&m_kPointA[i], Tag414());
}

struct FUN_0040ec80
{
    virtual void b00();
    FUN_0040ec80(int n);
    ~FUN_0040ec80();
    int m_04, m_08;
};
struct FUN_00411b00
{
    FUN_00411b00();
    int v[5];
};
struct FUN_0042c4b0 : FUN_0040ec80
{
    virtual void v00();
    FUN_00411b00* m_0c;
    FUN_0042c4b0();
};
// Constructs the base with 0x2a and allocates a FUN_00411b00 stored in m_0c.
// @fnv 0x0042c4b0
FUN_0042c4b0::FUN_0042c4b0() : FUN_0040ec80(0x2a)
{
    m_0c = new FUN_00411b00;
}

struct BSExtraDataCtorBase
{
    virtual void UnusedVirtual();
    ~BSExtraDataCtorBase();
    unsigned char m_ucExtraDataType;
    unsigned char layoutPadding5;
    unsigned short layoutPadding6;
    BSExtraData* pNext;
    BSExtraDataCtorBase(unsigned char);
};

struct FUN_00411be0 : BSExtraDataCtorBase
{
    BSSimpleList<void*> m_kNode;
    FUN_00411be0();
};

// @fnv 0x00411be0
FUN_00411be0::FUN_00411be0() : BSExtraDataCtorBase(0x66)
{}

struct FUN_0041b180_Vec
{
    int unk00;
    int unk04;
    int unk08;
};

struct FUN_0041b180_Extra : public BSExtraData
{
    FUN_0041b180_Vec pos;
};

struct FUN_0041b180_Owner : public BaseExtraList
{
    BSExtraData* GetOrCreateStartingPosition(TESObjectREFR* reference);
    FUN_0041b180_Vec* SetPositionExtraData(FUN_0041b180_Vec* outPosition, TESObjectREFR* reference,
                                           FUN_0041b180_Vec pos);
};

// @fnv 0x0041b180
FUN_0041b180_Vec* FUN_0041b180_Owner::SetPositionExtraData(FUN_0041b180_Vec* outPosition, TESObjectREFR* reference,
                                                           FUN_0041b180_Vec pos)
{
    FUN_0041b180_Extra* extra = (FUN_0041b180_Extra*)GetExtraData(0x0F);
    if (!extra)
    {
        extra = (FUN_0041b180_Extra*)GetOrCreateStartingPosition(reference);
    }
    extra->pos = pos;
    *outPosition = pos;
    return outPosition;
}

class TESKey : public TESForm
{
};
class TESGlobal : public TESForm
{
};
class TESWorldSpace : public TESForm
{
};
class Script : public TESForm
{
};
namespace p376 {
struct PackageVirtual
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
    virtual void slot0A();
    virtual void slot0B();
    virtual void slot0C();
    virtual void slot0D();
    virtual void slot0E();
    virtual void slot0F();
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
    virtual void slot1A();
    virtual void slot1B();
    virtual void slot1C();
    virtual void slot1D();
    virtual void slot1E();
    virtual void slot1F();
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
    virtual void slot2A();
    virtual void slot2B();
    virtual void slot2C();
    virtual void slot2D();
    virtual void slot2E();
    virtual void slot2F();
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
    virtual void slot3A();
    virtual void slot3B();
    virtual void slot3C();
    virtual void slot3D();
    virtual void slot3E();
    virtual void slot3F();
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
    virtual void slot4A();
    virtual void slot4B();
    virtual void slot4C();
    virtual void slot4D();
    virtual void slot4E();
    virtual void slot4F();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void Init();
};
struct Data50
{
    virtual void method00();
    virtual void method01();
    virtual void method02();
    virtual void method03();
    virtual void method04();
    virtual void method05();
    virtual void method06();
    virtual void method07();
    virtual void method08();
    virtual void method09();
    virtual void method0A();
    virtual void method0B();
    virtual void method0C();
    virtual void method0D();
    virtual void method0E();
    virtual void method0F();
    virtual void SetA(unsigned int);
    virtual void method11();
    virtual void SetB(unsigned int);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
};
struct Data51
{
    virtual void method00();
    virtual void method04();
    virtual void* Get();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
};
struct FUN_00825ad0 : public BSExtraData
{
    Data50 data;
    FUN_00825ad0(unsigned int);
};
struct FUN_00825fd0 : public BSExtraData
{
    Data51 data;
    FUN_00825fd0(unsigned int);
};
void __cdecl FUN_00805d40(void*, unsigned int);

struct Header
{
    unsigned int formID;
    unsigned char type;
    unsigned char changes;
    unsigned char changes1;
    unsigned char changes2;
    unsigned char changes3;
    unsigned char version;
};
struct Stream
{
    bool FUN_00862110();
    void FUN_008579e0(void*, unsigned int);
    void FUN_00857aa0(void*, unsigned int);
    unsigned char FUN_008df040();
    unsigned int FUN_00825c00();
    Header* FUN_004fd3c0();
    TESPackage* FUN_0085a240(unsigned int, unsigned char);
};
struct Manager
{
    bool FUN_00469860(unsigned int);
};
struct FUN_00411b00
{
    unsigned char level;
    TESKey* key;
    unsigned char flags;
    unsigned int unk0C;
    unsigned int unk10;
    FUN_00411b00();
};
struct FUN_005a8b80
{
    unsigned int master;
    unsigned int flags;
    unsigned int actions;
    unsigned int locals;
    unsigned int effect;
    FUN_005a8b80();
    void FUN_005a9950();
    void* FUN_0041af70(unsigned int);
};
struct FUN_0043a160
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    FUN_0043a160();
    void FUN_0043a9a0();
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
};
struct FUN_0083da50
{
    void* vt;
    unsigned int type;
    void* next;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    FUN_0083da50();
    void LoadFromSave(TESObjectREFR*);
    unsigned int FUN_009611e0();
    void* FUN_00425ff0(unsigned int);
};
struct RefHelper
{
    void FUN_00567490(float);
    bool FUN_005653d0();
    TESObjectCELL* FUN_008d6f30();
};
struct CellHelper
{
    void FUN_0054ca90(TESObjectREFR*);
    void FUN_00548230(TESObjectREFR*, bool);
    bool FUN_00425fd0();
};
struct WorldHelper
{
    TESObjectCELL* FUN_005f36f0();
};
struct FUN_0041af70
{
    ~FUN_0041af70();
};
struct FUN_00425ff0
{
    ~FUN_00425ff0();
};
struct ScriptHelper
{
    ScriptLocals* CreateEventList();
};
struct Extras
{
    void FUN_00424960(unsigned int, unsigned int, TESObjectREFR*);
    void FUN_00419ad0(short);
    void FUN_00419970(float);
    void FUN_00419a20(unsigned char);
    void EnsureLeveledListExtra(unsigned char);
    void FUN_00419bb0(float);
    void FUN_00419c60(float);
    void FUN_00419050(FUN_00411b00*);
    void FUN_00419fb0(float);
    void FUN_00419700(TESForm*);
    void SetExtraDataValue(TESGlobal*);
    void FUN_004198a0(unsigned int);
    void SetWornState(bool, bool);
    void FUN_0041ab70(bool);
    void SetGhost(bool);
    void FUN_00419ed0(Script*);
    ScriptLocals* FUN_00418830();
    void FUN_00419f80(ScriptLocals*);
    void SetLeveledItemIndex(unsigned int);
    void SetExtraDataByte(unsigned char);
    void FUN_0041c930(TESPackage*, unsigned int, unsigned int, unsigned char, unsigned char, unsigned char);
    void SetTrespassPackage(TESPackage*);
    void FUN_0041c7f0(unsigned int);
    void FUN_0041d700(TESPackage*, unsigned char);
    void FUN_0041ad00(TESWorldSpace*, TESObjectCELL*, NiPoint3*, float);
    void FUN_00422480(unsigned int);
    void FUN_0040ff60(void*);
    void FUN_00419120(FUN_0043a160*);
    void FUN_00419d10(unsigned int);
    void FUN_00422850(char*);
    void* FUN_00410220(unsigned char);
    TESObjectCELL* FUN_0041d460();
    void FUN_0041d390(TESObjectCELL*);
    void FUN_0041e000(unsigned int);
    void FUN_0041de40(unsigned int);
    void FUN_00419dc0(unsigned int);
    void FUN_0041b1e0(TESForm*);
    void SetHotKey(unsigned char);
    void FUN_0042dee0(FUN_0083da50*);
    void FUN_00421600(unsigned char);
    void FUN_0041af50();
};
struct RecordExtra
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    struct ByteSetter* object;
};
struct ByteSetter
{
    void FUN_0042e680(unsigned char);
};
struct FUN_006d5320
{
    TESForm* form;
    NiPoint3 position;
    FUN_006d5320();
};
struct AnimationInfo
{
    unsigned int unk00;
    unsigned int unk04;
    char* name;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
};
}
extern p376::Stream* DAT_011de45c;
extern p376::Manager* DAT_011c3f2c;
extern p376::AnimationInfo DAT_011977d8[];
extern char DAT_010152d0[], DAT_01015718[], DAT_010156a8[], DAT_01015610[], DAT_01015588[], DAT_01015500[],
    DAT_010154a0[], DAT_01015440[];
TESForm* __cdecl LookupFormByID(unsigned int);
void __cdecl FUN_005b5e40(const char*, ...);
void* __cdecl FUN_00403d30(void*, int, unsigned int);
namespace p376 {
// Reads a change-form record from the stream and dispatches each change type to the matching Extras setter, logging mismatches.
// @fnv 0x00424960
void Extras::FUN_00424960(unsigned int auiChangeFlags, unsigned int unused, TESObjectREFR* reference)
{
    unsigned short uiBlockStart;
    unsigned short bLoadedScript = 0;
    unsigned int pActor = 0;
    if (DAT_011de45c->FUN_00862110())
    {
        unsigned int blockType;
        DAT_011de45c->FUN_008579e0(&blockType, 4);
        if (blockType != 0x424c4f4b)
        {
            Header* header = DAT_011de45c->FUN_004fd3c0();
            if (header)
            {
                TESForm* form = LookupFormByID(header->formID);
                FUN_005b5e40(DAT_01015718, DAT_010152d0, 0x2c2c, header->formID, form->GetName(), header->version,
                             *reinterpret_cast<unsigned int*>(&header->changes));
            }
            else
                FUN_005b5e40(DAT_010156a8, DAT_010152d0, 0x2c2c, DAT_011de45c->FUN_008df040());
        }
        pActor = DAT_011de45c->FUN_00825c00();
        DAT_011de45c->FUN_008579e0(&bLoadedScript, 2);
    }
    bool usBlockSize = false;
    bool bFlag = false;
    Actor* i = dynamic_cast<Actor*>(reference);
    int m_usPassCountLocal;
    DAT_011de45c->FUN_008579e0(&uiBlockStart, 2);
    for (m_usPassCountLocal = 0; m_usPassCountLocal < uiBlockStart; m_usPassCountLocal++)
    {
        unsigned char type;
        DAT_011de45c->FUN_008579e0(&type, 1);
        switch (type)
        {
        case 36: {
            if (auiChangeFlags & 0)
            {
                short value;
                DAT_011de45c->FUN_008579e0(&value, 2);
                FUN_00419ad0(value);
            }
            break;
        }
        case 37: {
            if (auiChangeFlags & 0)
            {
                float value;
                DAT_011de45c->FUN_008579e0(&value, 4);
                FUN_00419970(value);
            }
            break;
        }
        case 38: {
            if (auiChangeFlags & 0)
            {
                unsigned char value;
                DAT_011de45c->FUN_008579e0(&value, 1);
                FUN_00419a20(value);
            }
            break;
        }
        case 141: {
            if (auiChangeFlags & 0)
            {
                unsigned char value;
                DAT_011de45c->FUN_008579e0(&value, 1);
                EnsureLeveledListExtra(value);
            }
            break;
        }
        case 39: {
            if (auiChangeFlags & 0)
            {
                float value;
                DAT_011de45c->FUN_008579e0(&value, 4);
                FUN_00419bb0(value);
            }
            break;
        }
        case 40: {
            if (auiChangeFlags & 0)
            {
                float value;
                DAT_011de45c->FUN_008579e0(&value, 4);
                FUN_00419c60(value);
            }
            break;
        }
        case 42: {
            if (auiChangeFlags & 0x1000)
            {
                FUN_00411b00* lock = new FUN_00411b00;
                if (DAT_011de45c->FUN_008df040() >= 21)
                {
                    DAT_011de45c->FUN_008579e0(lock, 1);
                    unsigned int qidnYUK, qbfQdhM;
                    DAT_011de45c->FUN_00857aa0(&qidnYUK, 4);
                    if (DAT_011de45c->FUN_008df040() < 26)
                    {
                        DAT_011de45c->FUN_00857aa0(&qbfQdhM, 4);
                    }
                    DAT_011de45c->FUN_008579e0(&lock->flags, 1);
                    if (qidnYUK)
                        lock->key = dynamic_cast<TESKey*>(LookupFormByID(qidnYUK));
                }
                FUN_00419050(lock);
            }
            break;
        }
        case 48: {
            if (DAT_011de45c->FUN_008df040() < 67 && (auiChangeFlags & 0x10))
            {
                float value;
                DAT_011de45c->FUN_008579e0(&value, 4);
                if (reference)
                    ((RefHelper*)reference)->FUN_00567490(value);
                else
                    FUN_00419fb0(value);
            }
            if (DAT_011de45c->FUN_008df040() >= 67 && (auiChangeFlags & 0))
            {
                float value;
                DAT_011de45c->FUN_008579e0(&value, 4);
                FUN_00419fb0(value);
            }
            break;
        }
        case 33: {
            if (auiChangeFlags & 0)
            {
                unsigned int qidnYUK;
                DAT_011de45c->FUN_00857aa0(&qidnYUK, 4);
                TESForm* qbfQdhM = LookupFormByID(qidnYUK);
                if (qbfQdhM)
                    FUN_00419700(qbfQdhM);
            }
            break;
        }
        case 34: {
            if (auiChangeFlags & 0)
            {
                unsigned int id;
                DAT_011de45c->FUN_00857aa0(&id, 4);
                TESGlobal* form = dynamic_cast<TESGlobal*>(LookupFormByID(id));
                if (form)
                    SetExtraDataValue(form);
            }
            break;
        }
        case 35: {
            if (auiChangeFlags & 0)
            {
                unsigned int value;
                DAT_011de45c->FUN_008579e0(&value, 4);
                FUN_004198a0(value);
            }
            break;
        }
        case 22: {
            if (auiChangeFlags & 0)
                SetWornState(true, false);
            break;
        }
        break;
        case 23: {
            if (auiChangeFlags & 0)
                SetWornState(true, true);
            break;
        }
        case 62: {
            if (auiChangeFlags & 0)
                FUN_0041ab70(true);
            break;
        }
        case 31: {
            SetGhost(true);
            break;
        }
        case 13: {
            if (auiChangeFlags & 0)
            {
                usBlockSize = true;
                unsigned int qidnYUK;
                DAT_011de45c->FUN_00857aa0(&qidnYUK, 4);
                Script* qtOMjSX = dynamic_cast<Script*>(LookupFormByID(qidnYUK));
                if (qtOMjSX)
                    FUN_00419ed0(qtOMjSX);
                ScriptLocals* qbfQdhM = FUN_00418830();
                if (!qbfQdhM)
                {
                    if (qtOMjSX)
                        qbfQdhM = ((ScriptHelper*)qtOMjSX)->CreateEventList();
                    FUN_00419f80(qbfQdhM);
                }
                if (!qbfQdhM)
                {
                    FUN_005a8b80* temporary = new FUN_005a8b80;
                    temporary->FUN_005a9950();
                    delete (FUN_0041af70*)temporary;
                }
                else
                    ((FUN_005a8b80*)qbfQdhM)->FUN_005a9950();
            }
            break;
        }
        case 47: {
            if (auiChangeFlags & 0)
            {
                unsigned int qidnYUK;
                unsigned char qbfQdhM;
                DAT_011de45c->FUN_008579e0(&qidnYUK, 4);
                DAT_011de45c->FUN_008579e0(&qbfQdhM, 1);
                SetLeveledItemIndex(qidnYUK);
                SetExtraDataByte(qbfQdhM);
            }
            break;
        }
        case 25: {
            unsigned int qidnYUK, qoPB, qtOMjSX;
            unsigned char qCWCA, qbfQdhM;
            DAT_011de45c->FUN_00857aa0(&qidnYUK, 4);
            DAT_011de45c->FUN_008579e0(&qoPB, 4);
            DAT_011de45c->FUN_00857aa0(&qtOMjSX, 4);
            DAT_011de45c->FUN_008579e0(&qCWCA, 1);
            DAT_011de45c->FUN_008579e0(&qbfQdhM, 1);
            TESPackage* quYjuqT = 0;
            if (DAT_011de45c->FUN_008df040() >= 64 && DAT_011c3f2c->FUN_00469860(qidnYUK))
            {
                unsigned char formType;
                DAT_011de45c->FUN_008579e0(&formType, 1);
                quYjuqT = DAT_011de45c->FUN_0085a240(qidnYUK, formType);
                ((PackageVirtual*)quYjuqT)->Init();
            }
            if (!quYjuqT)
                quYjuqT = dynamic_cast<TESPackage*>(LookupFormByID(qidnYUK));
            if (quYjuqT)
                FUN_0041c930(quYjuqT, qoPB, qtOMjSX, qCWCA, qbfQdhM, 0);
            break;
        }
        case 26: {
            if (auiChangeFlags & 0)
            {
                unsigned int id;
                DAT_011de45c->FUN_00857aa0(&id, 4);
                if (id)
                {
                    TESPackage* package = DAT_011de45c->FUN_0085a240(id, 23);
                    ((PackageVirtual*)package)->Init();
                    SetTrespassPackage(package);
                }
            }
            break;
        }
        case 18: {
            if (auiChangeFlags & 0)
            {
                unsigned int value;
                DAT_011de45c->FUN_008579e0(&value, 4);
            }
            break;
        }
        case 28: {
            if (auiChangeFlags & 0)
            {
                unsigned int id;
                DAT_011de45c->FUN_00857aa0(&id, 4);
                FUN_0041c7f0(id);
            }
            break;
        }
        case 46:
            break;
        case 27: {
            int qbfQdhM;
            unsigned short qidnYUK;
            DAT_011de45c->FUN_008579e0(&qidnYUK, 2);
            for (qbfQdhM = 0; qbfQdhM < qidnYUK; qbfQdhM++)
            {
                unsigned int qYePyBl;
                unsigned char qAXSCg;
                DAT_011de45c->FUN_00857aa0(&qYePyBl, 4);
                DAT_011de45c->FUN_008579e0(&qAXSCg, 1);
                TESPackage* qxDeKK = dynamic_cast<TESPackage*>(LookupFormByID(qYePyBl));
                if (qxDeKK)
                    FUN_0041d700(qxDeKK, qAXSCg);
            }
            break;
        }
        case 24: {
            FUN_006d5320 qoPB;
            unsigned int qidnYUK;
            float qtOMjSX;
            DAT_011de45c->FUN_00857aa0(&qidnYUK, 4);
            DAT_011de45c->FUN_008579e0(&qoPB.position, 12);
            DAT_011de45c->FUN_008579e0(&qtOMjSX, 4);
            qoPB.form = LookupFormByID(qidnYUK);
            TESWorldSpace* qbfQdhM = dynamic_cast<TESWorldSpace*>(qoPB.form);
            TESObjectCELL* qCWCA = dynamic_cast<TESObjectCELL*>(qoPB.form);
            if (qbfQdhM || qCWCA)
                FUN_0041ad00(qbfQdhM, qCWCA, &qoPB.position, qtOMjSX);
            break;
        }
        case 29: {
            int qbfQdhM;
            unsigned short qidnYUK;
            DAT_011de45c->FUN_008579e0(&qidnYUK, 2);
            for (qbfQdhM = 0; qbfQdhM < qidnYUK; qbfQdhM++)
            {
                unsigned int id;
                DAT_011de45c->FUN_00857aa0(&id, 4);
                FUN_00422480(id);
            }
            break;
        }
        case 50: {
            if (auiChangeFlags & 0)
            {
                unsigned int qbfQdhM, qidnYUK, qtOMjSX;
                DAT_011de45c->FUN_00857aa0(&qbfQdhM, 4);
                DAT_011de45c->FUN_00857aa0(&qidnYUK, 4);
                DAT_011de45c->FUN_00857aa0(&qtOMjSX, 4);
                FUN_00825ad0* qoPB = new FUN_00825ad0(qtOMjSX);
                qoPB->data.SetA(qbfQdhM);
                qoPB->data.SetB(qidnYUK);
                FUN_0040ff60(qoPB);
            }
            break;
        }
        case 51: {
            if (auiChangeFlags & 0)
            {
                unsigned int qidnYUK;
                DAT_011de45c->FUN_00857aa0(&qidnYUK, 4);
                FUN_00825fd0* qbfQdhM = new FUN_00825fd0(qidnYUK);
                FUN_00805d40(qbfQdhM->data.Get(), 0);
                FUN_0040ff60(qbfQdhM);
            }
            break;
        }
        case 43: {
            if (auiChangeFlags & 0x20000)
            {
                FUN_0043a160* data = new FUN_0043a160;
                data->FUN_0043a9a0();
                FUN_00419120(data);
            }
            break;
        }
        case 63: {
            if (auiChangeFlags & 0)
            {
                unsigned int id;
                DAT_011de45c->FUN_00857aa0(&id, 4);
                FUN_00419d10(id);
            }
            break;
        }
        case 65: {
            if (auiChangeFlags & 0x10000000)
            {
                if (DAT_011de45c->FUN_008df040() >= 21 && DAT_011de45c->FUN_008df040() < 23)
                {
                    int index;
                    DAT_011de45c->FUN_008579e0(&index, 4);
                    if (index < 245)
                        FUN_00422850(DAT_011977d8[index].name);
                }
                if (DAT_011de45c->FUN_008df040() < 21 || DAT_011de45c->FUN_008df040() >= 23)
                {
                    unsigned char qdxfsH;
                    char qxQHW[264];
                    DAT_011de45c->FUN_008579e0(&qdxfsH, 1);
                    FUN_00403d30(qxQHW, 0, 260);
                    DAT_011de45c->FUN_008579e0(qxQHW, qdxfsH);
                    FUN_00422850(qxQHW);
                }
            }
            break;
        }
        case 44: {
            if (auiChangeFlags & 0)
            {
                unsigned char qjvRB;
                DAT_011de45c->FUN_008579e0(&qjvRB, 1);
                RecordExtra* qpia = (RecordExtra*)FUN_00410220(44);
                if (qpia)
                    qpia->object->FUN_0042e680(qjvRB);
            }
            break;
        }
        case 144:
            break;
        case 145:
            break;
        case 12: {
            if (reference && reference->IsActor())
            {
                TESObjectCELL* current = FUN_0041d460();
                if (current)
                {
                    FUN_0041d390(0);
                    ((CellHelper*)current)->FUN_0054ca90(reference);
                }
                unsigned int id;
                DAT_011de45c->FUN_00857aa0(&id, 4);
                if (((RefHelper*)reference)->FUN_005653d0())
                {
                    TESWorldSpace* world = dynamic_cast<TESWorldSpace*>(LookupFormByID(id));
                    if (world)
                    {
                        FUN_0041d390(((WorldHelper*)world)->FUN_005f36f0());
                        if (reference)
                        {
                            ((CellHelper*)((WorldHelper*)world)->FUN_005f36f0())->FUN_00548230(reference, false);
                            if (((RefHelper*)reference)->FUN_008d6f30() &&
                                ((CellHelper*)((RefHelper*)reference)->FUN_008d6f30())->FUN_00425fd0())
                                ((CellHelper*)((RefHelper*)reference)->FUN_008d6f30())->FUN_0054ca90(reference);
                        }
                    }
                }
            }
            break;
        }
        case 58: {
            unsigned char itemCount;
            DAT_011de45c->FUN_008579e0(&itemCount, 1);
            for (unsigned int j = 0; j < itemCount; j++)
            {
                unsigned int id;
                DAT_011de45c->FUN_00857aa0(&id, 4);
                if (id)
                    FUN_0041e000(id);
            }
            break;
        }
        case 57: {
            unsigned int id;
            DAT_011de45c->FUN_00857aa0(&id, 4);
            if (id)
                FUN_0041de40(id);
            break;
        }
        case 69:
            break;
        case 70: {
            unsigned int id;
            DAT_011de45c->FUN_00857aa0(&id, 4);
            if (id)
                FUN_00419dc0(id);
            break;
        }
        case 73: {
            if (auiChangeFlags & 0)
            {
                unsigned int id;
                DAT_011de45c->FUN_00857aa0(&id, 4);
                if (id)
                {
                    TESForm* form = LookupFormByID(id);
                    if (dynamic_cast<TESObjectCELL*>(form) || dynamic_cast<TESWorldSpace*>(form))
                        FUN_0041b1e0(form);
                }
            }
            break;
        }
        case 74: {
            if (auiChangeFlags & 0)
            {
                unsigned char value;
                DAT_011de45c->FUN_008579e0(&value, 1);
                SetHotKey(value);
            }
            break;
        }
        case 77: {
            FUN_0083da50* data = new FUN_0083da50;
            data->LoadFromSave(reference);
            if (data->FUN_009611e0())
                FUN_0042dee0(data);
            else
                delete (FUN_00425ff0*)data;
            break;
        }
        case 78: {
            unsigned char value;
            DAT_011de45c->FUN_008579e0(&value, 1);
            FUN_00421600(value);
            break;
        }
        default:
            FUN_005b5e40(DAT_01015610, type);
            break;
        }
    }
    if (!usBlockSize && (auiChangeFlags & 0))
        FUN_0041af50();
    if (DAT_011de45c->FUN_00862110())
    {
        unsigned int qidnYUK = DAT_011de45c->FUN_00825c00();
        Header* qbfQdhM = DAT_011de45c->FUN_004fd3c0();
        if (qbfQdhM)
        {
            TESForm* form = LookupFormByID(qbfQdhM->formID);
            if (qidnYUK > pActor + bLoadedScript)
                FUN_005b5e40(DAT_01015588, qidnYUK - (pActor + bLoadedScript), DAT_010152d0, 0x2ee9, qbfQdhM->formID,
                             form->GetName(), qbfQdhM->version, *reinterpret_cast<unsigned int*>(&qbfQdhM->changes));
            else if (qidnYUK < pActor + bLoadedScript)
                FUN_005b5e40(DAT_01015500, pActor + bLoadedScript - qidnYUK, DAT_010152d0, 0x2ee9, qbfQdhM->formID,
                             form->GetName(), qbfQdhM->version, *reinterpret_cast<unsigned int*>(&qbfQdhM->changes));
        }
        else
        {
            if (qidnYUK > pActor + bLoadedScript)
                FUN_005b5e40(DAT_010154a0, qidnYUK - (pActor + bLoadedScript), DAT_010152d0, 0x2ee9,
                             DAT_011de45c->FUN_008df040());
            else if (qidnYUK < pActor + bLoadedScript)
                FUN_005b5e40(DAT_01015440, pActor + bLoadedScript - qidnYUK, DAT_010152d0, 0x2ee9,
                             DAT_011de45c->FUN_008df040());
        }
    }
}
}

namespace fnv_00426a30 {
// Serialize supported extra-data payloads and backpatch the number written.
struct XObj
{
    int FUN_0084e3a0();
};
struct ResObj
{
    int flags;
    unsigned char FUN_004280f0();
};

struct TempC
{
    int f0;
    TempC(int v);
    TempC(const TempC& o);
};
struct TempC2
{
    int f0;
};
struct BufObj
{
    virtual void v0();
    virtual int v4();
    virtual int v8();
    int FUN_00865f20();
    ResObj FUN_00428110(int flags);
    int FUN_00865e50(void* a1, int a2, int a3);
    int FUN_00865df0(int a1, int a2);
    int FUN_00865db0(int a1, int a2);
    void FUN_00865ff0(int a1, int a2);
    void FUN_00865f60(int a1);
    void FUN_00865e70(int a1);
    void FUN_00428110(TempC* a1);
    void SetValue(TempC a1);
    void SetValue(int a1);
};
struct GlobObj
{
    unsigned char FUN_00469860(int a1);
};
extern GlobObj* DAT_011c3f2c;
extern int DAT_01183d30[];
extern int DAT_010157b0;
void __cdecl FUN_00845cc0(void* a1, int a2);
int __cdecl FindIndexByValue(int a1, int a2);

struct ListNode
{
    int f0;
    int f4;
    int f8;
    int FUN_0045cd60();
    void* FUN_00726070();
};
struct ObjA
{
    int FUN_0040a1e0();
};
struct ObjB
{
    int RefreshItem();
};
struct PtrObj
{
    int f0;
    int f4;
    char f8;
    char f9;
    char fa;
    char fb;
    int fc;
    int f10;
};
struct Sub30
{
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    ObjA m_30;
};
void __cdecl FUN_00806a10(BufObj* a1, void* a2);
struct ListObj
{
    ListNode** FUN_006815c0();
    void FUN_0083fb10(BufObj* a1);
    void FUN_0043aa40(BufObj* a1);
    ListObj* FUN_00726070();
    int FUN_0045cd60();
    unsigned char FUN_00424940();
};
struct VObj
{
    virtual void v0();
    virtual void v4();
    virtual int v8();
    virtual void v12(BufObj* a1);
};
struct Sub10
{
    void FUN_005a9db0(BufObj* a1);
};

struct Obj8f
{
    int f0;
    int f4;
    ~Obj8f();
    int FUN_00559450();
};
struct Node
{
    void* vt;
    Node* m_04;
    int m_08;
    union
    {
        ListObj* m_0c;
        struct
        {
            unsigned char value0c;
            unsigned char value0d;
        } bytes0c;
    };
    Sub10* m_10;
    int m_14;
    union
    {
        ObjA* m_18;
        struct
        {
            unsigned char value18;
            unsigned char value19;
            unsigned char value1a;
        } bytes18;
    };
    ObjB* m_1c;
    int m_20;
    unsigned char FUN_004f1540();
    Node* FUN_0044ddc0();
    void FUN_00435e40();
    int FUN_0084e3a0();
    Obj8f FUN_00428070(int arg);
    Obj8f CallWithField14(int arg);
};

struct ElemA
{
    void SaveTimeStamp(BufObj* a1);
};
struct Cont45
{
    unsigned int FUN_0044ddc0();
    ElemA* FUN_006a7ad0(int a1);
};
struct Cont7c
{
    unsigned int FUN_0044ddc0();
    int* FUN_006a7ad0(int a1);
};
struct ElemF;
struct Cont5fB
{
    unsigned int FUN_0044ddc0();
    int* FUN_006a7ad0(int a1);
};
struct Cont5f
{
    unsigned int FUN_0044ddc0();
    ElemF* FUN_006a7ad0(int a1);
};
struct NestedPayload
{
    unsigned char value00;
    unsigned char value01;
    unsigned char value02;
    unsigned char value03;
    Cont5fB entries;
};
struct ElemF
{
    NestedPayload* f0;
};
struct MidObj
{
    int FUN_00825c00();
};
struct FieldC
{
    MidObj* FUN_00559450();
};
struct VObj54
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
    virtual void v54(BufObj* a1);
};
struct BigNode
{
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
};

struct Sub45
{
    int FUN_0045cd60();
};
struct ObjR
{
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    Sub45 m_30;
};
struct ObjRBase
{
    ObjR* FUN_004181e0();
};
struct Owner
{
    void* vt;
    Node* m_04;
    void WriteNodeList(BufObj* a1);
};
// Iterates the node list, decides per node whether to write its type tag and type-specific payload to the buffer, and finalizes the written count.
// @fnv 0x00426a30
void Owner::WriteNodeList(BufObj* apBuffer)
{
    int r3 = 0;
    int count = apBuffer->FUN_00865f20();
    int b19 = apBuffer->v4();
    int r1 = apBuffer->v8();
    unsigned char hasOwner6 = b19 != 0 ? DAT_011c3f2c->FUN_00469860(((XObj*)b19)->FUN_0084e3a0()) : (unsigned char)0;
    Node* node = this->m_04;
    while (node != 0)
    {
        unsigned char extraType2 = node->FUN_004f1540();
        unsigned char writeExtra = 0;
        if (DAT_01183d30[extraType2] != 0 && apBuffer->FUN_00428110(DAT_01183d30[extraType2]).FUN_004280f0())
        {
            writeExtra = 1;
        }
        if (!hasOwner6 && writeExtra && (DAT_01183d30[extraType2] & 0x40000000) != 0)
        {
            writeExtra = 0;
        }
        if (r1 == 0 && extraType2 == 0x89)
        {
            writeExtra = 0;
        }
        if (writeExtra)
        {
            apBuffer->FUN_00865e50(&extraType2, 1, 0);
            switch (extraType2)
            {
            case 0x16:
                break;
            case 0x3e:
                break;
            case 0x24: {
                Node* t = node;
                apBuffer->FUN_00865e50(&t->m_0c, 2, 0);
                break;
            }
            case 0x25: {
                Node* t = node;
                apBuffer->FUN_00865e50(&t->m_0c, 4, 0);
                break;
            }
            case 0x30: {
                Node* t = node;
                apBuffer->FUN_00865e50(&t->m_0c, 4, 0);
                break;
            }
            case 0x21: {
                Node* t = node;
                apBuffer->FUN_00865df0((int)t->m_0c, 0);
                break;
            }
            case 0x23: {
                Node* t = node;
                apBuffer->FUN_00865e50(&t->m_0c, 4, 0);
                break;
            }
            case 0x22: {
                Node* t = node;
                apBuffer->FUN_00865df0((int)t->m_0c, 0);
                break;
            }
            case 0x1c: {
                Node* t = node;
                apBuffer->FUN_00865df0((int)t->m_0c, 0);
                break;
            }
            case 0x49:
            extra_49: {
                Node* t = node;
                apBuffer->FUN_00865df0((int)t->m_0c, 0);
                break;
            }
            case 0x56: {
                Node* t = node;
                apBuffer->FUN_00865e50(&t->m_0c, 4, 0);
                break;
            }
            case 0xd: {
                Node* t = node;
                apBuffer->FUN_00865df0((int)t->m_0c, 0);
                t->m_10->FUN_005a9db0(apBuffer);
                break;
            }
            case 0x5b: {
                Node* t = node;
                apBuffer->FUN_00865df0((int)t->m_10, 0);
                int res = FindIndexByValue((int)t->m_10, (int)t->m_0c);
                apBuffer->FUN_00865e50(&res, 4, 0);
                break;
            }
            case 0x19: {
                Node* t = node;
                apBuffer->FUN_00865df0((int)t->m_0c, 0);
                apBuffer->FUN_00865df0(t->m_14, 0);
                apBuffer->FUN_00865e50(&t->m_10, 4, 0);
                apBuffer->FUN_00865e50(&t->m_18, 1, 0);
                apBuffer->FUN_00865e50(&t->bytes18.value19, 1, 0);
                apBuffer->FUN_00865e50(&t->bytes18.value1a, 1, 0);
                break;
            }
            case 0x18: {
                Node* t = node;
                apBuffer->FUN_00865df0((int)t->m_0c, 0);
                apBuffer->FUN_00865e50(&t->m_10, 0xc, 0);
                apBuffer->FUN_00865e50(&t->m_1c, 4, 0);
                break;
            }
            case 0x1b: {
                Node* record2 = node;
                int entryCount = 0;
                int start2 = apBuffer->FUN_00865f20();
                ListObj* cursor4 = record2->m_0c;
                while (cursor4 != 0)
                {
                    ListNode* e = *cursor4->FUN_006815c0();
                    if (e != 0)
                    {
                        apBuffer->FUN_00865df0(e->f0, 0);
                        apBuffer->FUN_00865e50(&e->f4, 1, 0);
                        entryCount = entryCount + 1;
                    }
                    cursor4 = cursor4->FUN_00726070();
                }
                apBuffer->FUN_00865ff0(entryCount, start2);
                break;
            }
            case 0x1d: {
                Node* record2 = node;
                int entryCount = 0;
                int start2 = apBuffer->FUN_00865f20();
                ListObj* cursor4 = record2->m_0c;
                while (cursor4 != 0)
                {
                    ListNode* e = *cursor4->FUN_006815c0();
                    if (e != 0)
                    {
                        apBuffer->FUN_00865df0((int)e, 0);
                        entryCount = entryCount + 1;
                    }
                    cursor4 = cursor4->FUN_00726070();
                }
                apBuffer->FUN_00865ff0(entryCount, start2);
                break;
            }
            case 0x6c: {
                Node* t = node;
                apBuffer->FUN_00865df0((int)t->m_0c, 0);
                break;
            }
            case 0x73: {
                Node* record2 = node;
                int entryCount = 0;
                int start2 = apBuffer->FUN_00865f20();
                ListObj* cursor4 = record2->m_0c;
                while (cursor4 != 0)
                {
                    ListNode* e = *cursor4->FUN_006815c0();
                    if (e != 0)
                    {
                        apBuffer->FUN_00865df0(e->f0, 0);
                        apBuffer->FUN_00865e50(&e->f4, 4, 0);
                        apBuffer->FUN_00865e50(&e->f8, 4, 0);
                        entryCount = entryCount + 1;
                    }
                    cursor4 = cursor4->FUN_00726070();
                }
                apBuffer->FUN_00865ff0(entryCount, start2);
                break;
            }
            case 0x75: {
                Node* t = node;
                apBuffer->FUN_00865df0((int)t->m_10, 0);
                apBuffer->FUN_00865df0((int)t->m_0c, 0);
                apBuffer->FUN_00865e50(&t->m_18, 1, 0);
                break;
            }
            case 0x4a: {
                Node* t = node;
                apBuffer->FUN_00865e50(&t->m_0c, 1, 0);
                break;
            }
            case 0x35: {
                Node* record2 = node;
                int entryCount = 0;
                int start2 = apBuffer->FUN_00865f20();
                ListObj* cursor4 = record2->m_0c;
                while (cursor4 != 0)
                {
                    ListNode* e = *cursor4->FUN_006815c0();
                    if (e != 0)
                    {
                        int res1 = e->FUN_0045cd60();
                        void* res2 = e->FUN_00726070();
                        apBuffer->FUN_00865e50(&res1, 4, 0);
                        apBuffer->FUN_00865e50(&res2, 4, 0);
                        entryCount = entryCount + 1;
                    }
                    cursor4 = cursor4->FUN_00726070();
                }
                apBuffer->FUN_00865ff0(entryCount, start2);
                break;
            }

            case 0x45: {
                Node* record2 = node;
                record2->FUN_00435e40();
                unsigned int cnt = ((Cont45*)&record2->m_0c) ? ((Cont45*)&record2->m_0c)->FUN_0044ddc0() : 0;
                apBuffer->FUN_00865f60(cnt);
                for (unsigned int i = 0; i < cnt; i++)
                {
                    ElemA* e = ((Cont45*)&record2->m_0c)->FUN_006a7ad0(i);
                    e->SaveTimeStamp(apBuffer);
                }
                break;
            }
            case 0x5e: {
                Node* record2 = node;
                int entryCount = 0;
                int start2 = apBuffer->FUN_00865f20();
                ListObj* cursor4 = record2->m_0c;
                while (cursor4 != 0)
                {
                    ListNode* e = *cursor4->FUN_006815c0();
                    if (e != 0)
                    {
                        apBuffer->FUN_00865df0(e->f0, 0);
                        apBuffer->FUN_00865e50(&e->f4, 1, 0);
                        entryCount = entryCount + 1;
                    }
                    cursor4 = cursor4->FUN_00726070();
                }
                apBuffer->FUN_00865ff0(entryCount, start2);
                break;
            }
            case 0x70: {
                Node* record2 = node;
                unsigned char b = record2->m_0c ? ((VObj*)record2->m_0c)->v8() : -1;
                apBuffer->FUN_00865e50(&b, 1, 0);
                if (record2->m_0c != 0)
                {
                    ((VObj*)record2->m_0c)->v12(apBuffer);
                }
                break;
            }
            case 0x2c: {
                Node* record2 = node;
                unsigned char b = 0;
                if (record2->m_0c != 0)
                {
                    b = record2->m_0c->FUN_00424940();
                }
                apBuffer->FUN_00865e50(&b, 1, 0);
                break;
            }
            case 0x90:
            case 0x91:
                break;

            case 0x7c: {
                Node* record2 = node;
                unsigned int cnt = ((Cont7c*)&record2->m_0c) ? ((Cont7c*)&record2->m_0c)->FUN_0044ddc0() : 0;
                apBuffer->FUN_00865f60(cnt);
                for (unsigned int i = 0; i < cnt; i++)
                {
                    int* e = ((Cont7c*)&record2->m_0c)->FUN_006a7ad0(i);
                    apBuffer->FUN_00865db0(*e, 0);
                }
                break;
            }
            case 0x74: {
                Node* t = node;
                apBuffer->FUN_00865df0((int)t->m_0c, 0);
                break;
            }
            case 0x5c: {
                Node* t = node;
                apBuffer->FUN_00865e50(&t->m_0c, 4, 0);
                break;
            }
            case 0x5d: {
                Node* t = node;
                apBuffer->FUN_00865e50(&t->m_0c, 4, 0);
                break;
            }
            case 0x6e: {
                Node* t = node;
                apBuffer->FUN_00865df0((int)t->m_0c, 0);
                apBuffer->FUN_00865e50(&t->m_10, 4, 0);
                break;
            }
            case 0x1e: {
                Node* t = node;
                apBuffer->FUN_00865e50(&t->m_0c, 4, 0);
                break;
            }

            case 0x1a: {
                Node* t = node;
                apBuffer->FUN_00865df0((int)t->m_0c, 0);
                if (t->m_0c != 0)
                {
                    ((VObj54*)t->m_0c)->v54(apBuffer);
                }
                break;
            }
            case 0x1f:
                break;
            case 0x26: {
                Node* t = node;
                apBuffer->FUN_00865e50(&t->m_0c, 1, 0);
                break;
            }
            case 0x8d: {
                Node* t = node;
                apBuffer->FUN_00865e50(&t->m_0c, 1, 0);
                break;
            }
            case 0x27: {
                Node* t = node;
                apBuffer->FUN_00865e50(&t->m_0c, 4, 0);
                break;
            }
            case 0x28: {
                Node* t = node;
                apBuffer->FUN_00865e50(&t->m_0c, 4, 0);
                break;
            }
            case 0x2a: {
                Node* t = node;
                apBuffer->FUN_00865e50(t->m_0c, 1, 0);
                apBuffer->FUN_00865e50(&((PtrObj*)t->m_0c)->f8, 1, 0);
                apBuffer->FUN_00865df0(((PtrObj*)t->m_0c)->f4, 0);
                apBuffer->FUN_00865e50(&((PtrObj*)t->m_0c)->fc, 4, 0);
                apBuffer->FUN_00865e50(&((PtrObj*)t->m_0c)->f10, 4, 0);
                break;
            }
            case 0x2f: {
                Node* t = node;
                apBuffer->FUN_00865e50(&t->m_0c, 4, 0);
                apBuffer->FUN_00865e50(&t->m_10, 1, 0);
                break;
            }
            case 0x32: {
                Node* t = node;
                apBuffer->FUN_00865db0(t->m_18 ? t->m_18->FUN_0040a1e0() : 0, 0);
                apBuffer->FUN_00865db0(t->m_1c ? t->m_1c->RefreshItem() : 0, 0);
                apBuffer->FUN_00865df0(t->m_20, 0);
                break;
            }
            case 0x33: {
                Node* t = node;
                apBuffer->FUN_00865df0((int)t->m_1c, 0);
                FUN_00806a10(apBuffer, &t->m_20);
                break;
            }
            case 0x39: {
                Node* t = node;
                apBuffer->FUN_00865df0((int)t->m_0c, 0);
                break;
            }
            case 0x3f: {
                Node* t = node;
                apBuffer->FUN_00865db0(t->m_0c ? ((Sub30*)t->m_0c)->m_30.FUN_0040a1e0() : 0, 0);
                break;
            }
            case 0x46: {
                Node* t = node;
                apBuffer->FUN_00865df0((int)t->m_0c, 0);
                break;
            }
            case 0x4d: {
                Node* t = node;
                t->m_0c->FUN_0083fb10(apBuffer);
                break;
            }
            case 0x4e: {
                Node* t = node;
                apBuffer->FUN_00865e50(&t->m_0c, 1, 0);
                break;
            }

            case 0x5f: {
                Node* record2 = node;
                apBuffer->FUN_00865e50(&record2->m_0c, 2, 0);
                apBuffer->FUN_00865e50(&record2->m_10, 4, 0);
                apBuffer->FUN_00865e50(&record2->m_18, 4, 0);
                apBuffer->FUN_00865e50(&record2->m_1c, 1, 0);
                apBuffer->FUN_00865df0(record2->m_14, 0);
                unsigned int cnt = ((Cont5f*)&record2->m_20) ? ((Cont5f*)&record2->m_20)->FUN_0044ddc0() : 0;
                apBuffer->FUN_00865f60(cnt);
                for (unsigned int i = 0; i < cnt; i++)
                {
                    ElemF* payload = ((Cont5f*)&record2->m_20)->FUN_006a7ad0(i);
                    apBuffer->FUN_00865e50(&payload->f0->value00, 1, 0);
                    apBuffer->FUN_00865e50(&payload->f0->value01, 1, 0);
                    apBuffer->FUN_00865e50(&payload->f0->value02, 1, 0);
                    apBuffer->FUN_00865e50(&payload->f0->value03, 1, 0);
                    unsigned int cnt2 = (&payload->f0->entries) ? (&payload->f0->entries)->FUN_0044ddc0() : 0;
                    apBuffer->FUN_00865f60(cnt2);
                    for (unsigned int j = 0; j < cnt2; j++)
                    {
                        int* sub = (&payload->f0->entries)->FUN_006a7ad0(j);
                        apBuffer->FUN_00865df0(*sub, 0);
                    }
                }
                break;
            }
            case 0x55: {
                Node* t = node;
                apBuffer->FUN_00865df0((int)t->m_0c, 0);
                break;
            }

            case 0x60: {
                Node* t = node;
                int res =
                    ((FieldC*)&t->m_0c)->FUN_00559450() ? ((FieldC*)&t->m_0c)->FUN_00559450()->FUN_00825c00() : -1;
                apBuffer->FUN_00865e50(&res, 4, 0);
                break;
            }
            case 0x2b: {
                Node* t = node;
                t->m_0c->FUN_0043aa40(apBuffer);
                break;
            }
            case 0x3c: {
                Node* t = node;
                apBuffer->FUN_00865df0((int)t->m_0c, 0);
                break;
            }

            case 0x2e: {
                Node* record3 = node;
                apBuffer->FUN_00865df0((int)record3->m_0c, 0);
                apBuffer->FUN_00865df0((int)record3->m_10, 0);
                ObjR* object4 = ((ObjRBase*)r1)->FUN_004181e0();
                int val = object4->m_30.FUN_0045cd60();
                apBuffer->FUN_00865e50(&val, 4, 0);
                TempC2 res2;
                apBuffer->FUN_00428110((TempC*)&res2);
                apBuffer->SetValue(TempC(val));
                ((VObj54*)object4)->v54(apBuffer);
                apBuffer->SetValue(res2.f0);
                break;
            }
            case 0x54: {
                Node* t = node;
                apBuffer->FUN_00865e50(&t->m_14, 4, 0);
                break;
            }
            case 0x50: {
                Node* t = node;
                apBuffer->FUN_00865e50(&t->m_0c, 1, 0);
                apBuffer->FUN_00865e50(&t->bytes0c.value0d, 1, 0);
                break;
            }
            case 0x89: {
                Node* t = node;
                apBuffer->FUN_00865df0((int)t->m_0c, 0);
                break;
            }
            case 0x8b: {
                Node* record2 = node;
                apBuffer->FUN_00865e50(&record2->m_10, 0xc, 0);
                apBuffer->FUN_00865db0((int)record2->m_1c, 0);
                apBuffer->FUN_00865e50(&record2->m_0c, 4, 0);
                int entryCount = 0;
                int start2 = apBuffer->FUN_00865f20();
                ListObj* cursor4 = (ListObj*)&record2->m_20;
                while (cursor4 != 0)
                {
                    BigNode* e = (BigNode*)*cursor4->FUN_006815c0();
                    if (e != 0)
                    {
                        apBuffer->FUN_00865e50(e, 0xc, 0);
                        apBuffer->FUN_00865db0(e->fc, 0);
                        apBuffer->FUN_00865e50(&e->f10, 0xc, 0);
                        apBuffer->FUN_00865db0(e->f1c, 0);
                        apBuffer->FUN_00865e50(&e->f20, 1, 0);
                        entryCount = entryCount + 1;
                    }
                    cursor4 = cursor4->FUN_00726070();
                }
                apBuffer->FUN_00865ff0(entryCount, start2);
                break;
            }
            case 0x8f: {
                Node* t = node;
                apBuffer->FUN_00865e70(t->FUN_00428070(0).FUN_00559450());
                apBuffer->FUN_00865e70(t->CallWithField14(0).FUN_00559450());
                break;
            }
            case 0x92: {
                Node* t = node;
                int res = t->FUN_0084e3a0();
                apBuffer->FUN_00865e50(&res, 4, 0);
                apBuffer->FUN_00865e50(&t->m_10, 4, 0);
                break;
            }
            default:
                FUN_00845cc0(&DAT_010157b0, extraType2);
                break;
            }
            r3 = r3 + 1;
        }
        node = node->FUN_0044ddc0();
    }
    apBuffer->FUN_00865ff0(r3, count);
}
}  // namespace fnv_00426a30

namespace fnv_0042dae0 {
struct Obj42
{
    virtual void v0();
    virtual void v1();
    virtual Obj42* v2();
    virtual unsigned v3();
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
    virtual void v115(int, int);
    unsigned FUN_0084e3a0();
};
struct Flags42
{
    unsigned data;
    bool FUN_004280f0(unsigned);
};
struct Buf42 : Obj42
{
    Flags42 FUN_0042ce30();
};
struct Extra42
{
    void FUN_0041e0d0(Obj42*);
};
struct Ref42
{
    Extra42* FUN_005d43c0();
};
struct Map42
{
    void CopyByteWithinData();
};
struct Script42
{
    void FUN_005aa090(Buf42*);
};
struct Manager42
{
    bool FUN_00469860(unsigned);
};
extern "C" char DAT_011c3f2c;
extern "C" char DAT_01183d30;
void __cdecl SetOrRemoveMapEntry(Obj42*, int);
struct Target42
{
    void* FUN_0042e250();
    void* FUN_00410220(unsigned char);
    Ref42* FUN_0041de00();
    Map42* FUN_00418490();
    void FUN_0041eff0(float);
    Script42* FUN_00418830();
    void FUN_00410140(unsigned char);
    void FUN_0042dae0(Buf42*);
};
// @fnv 0x0042dae0
void Target42::FUN_0042dae0(Buf42* pBuffer)
{
    Obj42* p = pBuffer->v2();
    if (p)
    {
        unsigned unused4 = pBuffer->v3();
        if (FUN_0042e250())
            p->v115(0, 1);
        if (FUN_00410220(0x56))
            SetOrRemoveMapEntry(p, 0);
        Ref42* ref = FUN_0041de00();
        if (ref)
            ref->FUN_005d43c0()->FUN_0041e0d0(p);
        Map42* map4 = FUN_00418490();
        if (map4)
            map4->CopyByteWithinData();
        if (pBuffer->FUN_0042ce30().FUN_004280f0(0x4000000))
            FUN_0041eff0(0.0f);
        Script42* script3 = FUN_00418830();
        if (script3)
            script3->FUN_005aa090(pBuffer);
    }
    bool validA = p ? (*(Manager42**)&DAT_011c3f2c)->FUN_00469860(p->FUN_0084e3a0()) : false;
    for (unsigned i3 = 0; i3 < 0x93; ++i3)
    {
        bool remove = false;
        if (((unsigned*)&DAT_01183d30)[i3] && pBuffer->FUN_0042ce30().FUN_004280f0(((unsigned*)&DAT_01183d30)[i3]))
            remove = true;
        if (!validA && remove && (((unsigned*)&DAT_01183d30)[i3] & 0x40000000))
            remove = false;
        if (remove)
        {
            switch (i3)
            {
            case 13:
            case 44:
            case 46:
            case 73:
            case 84:
            case 95:
            case 144:
            case 145:
                remove = false;
            }
        }
        if (remove)
            FUN_00410140((unsigned char)i3);
    }
}
}  // namespace fnv_0042dae0

struct ActorExtraShell
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual void vf74();
    virtual void vf75();
    virtual void vf76();
    virtual void vf77();
    virtual void vf78();
    virtual void vf79();
    virtual void vf80();
    virtual void vf81();
    virtual void vf82();
    virtual void vf83();
    virtual void vf84();
    virtual void vf85();
    virtual void vf86();
    virtual void vf87();
    virtual void vf88();
    virtual void vf89();
    virtual void vf90();
    virtual void vf91();
    virtual void vf92();
    virtual void vf93();
    virtual void vf94();
    virtual void vf95();
    virtual void vf96();
    virtual void vf97();
    virtual void vf98();
    virtual void vf99();
    virtual void vf100();
    virtual void vf101();
    virtual void vf102();
    virtual void vf103();
    virtual void vf104();
    virtual void vf105();
    virtual void vf106();
    virtual void vf107();
    virtual void vf108();
    virtual void vf109();
    virtual void vf110();
    virtual void vf111();
    virtual void vf112();
    virtual void vf113();
    virtual void vf114();
    virtual void vf115();
    virtual void vf116();
    virtual void vf117();
    virtual void vf118();
    virtual void vf119();
    virtual void vf120();
    virtual void vf121();
    virtual void vf122();
    virtual void vf123();
    virtual void vf124();
    virtual void vf125();
    virtual void vf126();
    virtual void vf127();
    virtual void vf128();
    virtual void vf129();
    virtual void vf130();
    virtual void vf131();
    virtual void vf132();
    virtual void vf133();
    virtual void vf134();
    virtual bool vf135();
    virtual void vf136();
    virtual void vf137();
    virtual void vf138();
    virtual void vf139();
    virtual void vf140();
    virtual void vf141();
    virtual void vf142();
    virtual void vf143();
    virtual void vf144();
    virtual void vf145();
    virtual void vf146();
    virtual void vf147();
    virtual void vf148();
    virtual void vf149();
    virtual void vf150();
    virtual void vf151();
    virtual void vf152();
    virtual void vf153();
    virtual void vf154();
    virtual void vf155();
    virtual void vf156();
    virtual void vf157();
    virtual void vf158();
    virtual void vf159();
    virtual void vf160();
    virtual void vf161();
    virtual void vf162();
    virtual void vf163();
    virtual void vf164();
    virtual void vf165();
    virtual void vf166();
    virtual void vf167();
    virtual void vf168();
    virtual void vf169();
    virtual void vf170();
    virtual void vf171();
    virtual void vf172();
    virtual void vf173();
    virtual void vf174();
    virtual void vf175();
    virtual void vf176();
    virtual void vf177();
    virtual void vf178();
    virtual void vf179();
    virtual void vf180();
    virtual void vf181();
    virtual void vf182();
    virtual void vf183();
    virtual void vf184();
    virtual void vf185();
    virtual void vf186();
    virtual void vf187();
    virtual void vf188();
    virtual void vf189();
    virtual void vf190();
    virtual void vf191();
    virtual void vf192();
    virtual void vf193();
    virtual void vf194();
    virtual void vf195();
    virtual void vf196();
    virtual void vf197();
    virtual void vf198();
    virtual void vf199();
    virtual void vf200();
    virtual void vf201();
    virtual void vf202();
    virtual void vf203();
    virtual void vf204();
    virtual void vf205();
    virtual void vf206();
    virtual void vf207();
    virtual void vf208();
    virtual void vf209();
    virtual void vf210();
    virtual void vf211();
    virtual void vf212();
    virtual void vf213();
    virtual void vf214();
    virtual void vf215();
    virtual bool vf216();

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
    int unk100;
    unsigned char unk104;

    void FUN_008a08e0(unsigned char arg);
};

struct FUN_0087f3d0_shell
{
    bool FUN_0087f3d0();
    void FUN_008a0960();
};

// @fnv 0x008a08e0
void ActorExtraShell::FUN_008a08e0(unsigned char arg)
{
    unsigned char flag = unk104;
    unk104 = 0;

    if (vf216() || vf135() || !arg)
        return;

    if (flag && reinterpret_cast<FUN_0087f3d0_shell*>(this)->FUN_0087f3d0())
        reinterpret_cast<FUN_0087f3d0_shell*>(this)->FUN_008a0960();
}

namespace fnv_00422c40 {
class ExtQ
{
  public:
    void** vt_;
    char pad_[8];
    unsigned char FUN_004f1540();
    ExtQ* FUN_0044ddc0();
};
class ScriptQ
{
  public:
    unsigned short GetScriptLocalsSerializedSize();
};
class PkgQ
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
    virtual unsigned short v83();
    int FUN_0084e3a0();
    int FUN_005ae380();
};
class TeleQ
{
  public:
    unsigned short FUN_0043a8f0();
};
class TopicQ
{
  public:
    unsigned short FUN_0083f280();
};
class MagicQ
{
  public:
    virtual void m0();
    virtual void m1();
    virtual int m2();
};
class ExtraScriptQ : public ExtQ
{
  public:
    int pad1;
    ScriptQ* script;
};
class ExtraPackageQ : public ExtQ
{
  public:
    PkgQ* pkg;
};
class ExtraTresPassPackageQ : public ExtQ
{
  public:
    PkgQ* pkg;
};
class ExtraRunOncePacksQ : public ExtQ
{
  public:
    PkgQ* list;
};
class ExtraPackageStartLocationQ : public ExtQ
{
  public:
    int loc;
};
class ExtraFollowerQ : public ExtQ
{
  public:
    PkgQ* list;
};
class NonActorMagicTargetQ : public ExtQ
{
  public:
    MagicQ mt;
};
class ExtraTeleportQ : public ExtQ
{
  public:
    TeleQ* data;
};
class ExtraLastFinishedSequenceQ : public ExtQ
{
  public:
    int seq;
};
class ExtraInfoGeneralTopicQ : public ExtQ
{
  public:
    TopicQ* topic;
};
class ObjQ
{
  public:
    virtual void o0();
    virtual void o1();
    virtual void o2();
    virtual void o3();
    virtual void o4();
    virtual void o5();
    virtual void o6();
    virtual void o7();
    virtual void o8();
    virtual void o9();
    virtual void o10();
    virtual void o11();
    virtual void o12();
    virtual void o13();
    virtual void o14();
    virtual void o15();
    virtual void o16();
    virtual void o17();
    virtual void o18();
    virtual void o19();
    virtual void o20();
    virtual void o21();
    virtual void o22();
    virtual void o23();
    virtual void o24();
    virtual void o25();
    virtual void o26();
    virtual void o27();
    virtual void o28();
    virtual void o29();
    virtual void o30();
    virtual void o31();
    virtual void o32();
    virtual void o33();
    virtual void o34();
    virtual void o35();
    virtual void o36();
    virtual void o37();
    virtual void o38();
    virtual void o39();
    virtual void o40();
    virtual void o41();
    virtual void o42();
    virtual void o43();
    virtual void o44();
    virtual void o45();
    virtual void o46();
    virtual void o47();
    virtual void o48();
    virtual void o49();
    virtual void o50();
    virtual void o51();
    virtual void o52();
    virtual void o53();
    virtual void o54();
    virtual void o55();
    virtual void o56();
    virtual void o57();
    virtual void o58();
    virtual void o59();
    virtual void o60();
    virtual void o61();
    virtual void o62();
    virtual void o63();
    virtual bool o64();
};
class FormQ
{
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual void f64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
    virtual void f73();
    virtual void f74();
    virtual void f75();
    virtual int f76();
};
struct SaveRecQ
{
    int formID;
    char b4;
    int flags;
};
class ProfQ
{
  public:
    void Lock(int);
    void Unlock();
};
class GameQ
{
  public:
    bool FUN_00862110();
    unsigned char FUN_008df040();
    SaveRecQ* FUN_004fd3e0();
};
class ListMgrQ
{
  public:
    bool FUN_00469860(int);
};
class SettingQ
{
  public:
    unsigned char* FUN_00408d60();
};
extern ProfQ DAT_011c3920;
extern GameQ* DAT_011de45c;
extern ListMgrQ* DAT_011c3f2c;
extern SettingQ DAT_011de4e8;
extern char DAT_01183b2c;
extern char DAT_01184514;
extern char DAT_011844f8;
extern char DAT_011844d4;
extern char DAT_011844b4;
extern char DAT_0118448c;
extern char DAT_01184470;
extern char DAT_0118444c;
extern char DAT_01184430;
extern char DAT_01184408;
extern char DAT_011843e4;
void* FUN_00ec43fb(void*, int, void*, void*, int);
unsigned short FUN_00805a00(int, int);
int FUN_0044a670(int);
FormQ* LookupFormByID(int);
void FUN_0040fbe0(const char*, ...);
class ExtraDataListQ
{
  public:
    virtual void x0();
    ExtQ* head;
    unsigned short FUN_00422c40(unsigned int a1, ObjQ* a2);
};
// Computes the serialized byte size of the extra data list, adding per-entry sizes based on type and flags, and logs the result when a debug setting is enabled.
// @fnv 0x00422c40
unsigned short ExtraDataListQ::FUN_00422c40(unsigned int aiFlags, ObjQ* apObj)
{
    DAT_011c3920.Lock(0);
    ExtQ* p_gslscu;
    unsigned short size = 0;
    unsigned short start = size;
    if (DAT_011de45c->FUN_00862110())
    {
        size += 4;
        size += 2;
    }
    size += 2;
    p_gslscu = head;
    while (p_gslscu)
    {
        unsigned short prev = size;
        switch (p_gslscu->FUN_004f1540())
        {
        case 0xf:
            break;
        case 0x10:
            break;
        case 0x11:
            break;
        case 0x12:
            break;
        case 0x13:
            break;
        case 0x14:
            break;
        case 0x15:
            break;
        case 0x16:
            break;
        case 0x17:
            break;
        case 0x1e:
            break;
        case 0x1f:
            break;
        case 0x20:
            break;
        case 0x29:
            break;
        case 0x2d:
            break;
        case 0x2e:
            break;
        case 0x31:
            break;
        case 0x34:
            break;
        case 0x35:
            break;
        case 0x36:
            break;
        case 0x37:
            break;
        case 0x38:
            break;
        case 0x3a:
            break;
        case 0x3b:
            break;
        case 0x3c:
            break;
        case 0x3d:
            break;
        case 0x3e:
            break;
        case 0x40:
            break;
        case 0x42:
            break;
        case 0x43:
            break;
        case 0x44:
            break;
        case 0x45:
            break;
        case 0x47:
            break;
        case 0x48:
            break;
        case 0x4b:
            break;
        case 0x4c:
            break;
        case 0x4f:
            break;
        case 0x24:
            if (aiFlags & 0)
                size += 2;
            break;
        case 0x25:
            if (aiFlags & 0)
                size += 4;
            break;
        case 0x26:
        case 0x8d:
            if (aiFlags & 0)
                size += 1;
            break;
        case 0x27:
            if (aiFlags & 0)
                size += 4;
            break;
        case 0x28:
            if (aiFlags & 0)
                size += 4;
            break;
        case 0x2a:
            if (aiFlags & 0x1000)
            {
                size += 1;
                size += 4;
                size += 1;
            }
            break;
        case 0x30:
            if (aiFlags & 0)
                size += 4;
            break;
        case 0x21:
            if (aiFlags & 0)
                size += 4;
            break;
        case 0x22:
            if (aiFlags & 0)
                size += 4;
            break;
        case 0x23:
            if (aiFlags & 0)
                size += 4;
            break;
        case 0xd:
            if (aiFlags & 0)
            {
                ExtraScriptQ* pScript = (ExtraScriptQ*)FUN_00ec43fb(p_gslscu, 0, &DAT_01183b2c, &DAT_01184514, 0);
                size += 4;
                size += pScript->script->GetScriptLocalsSerializedSize();
            }
            break;
        case 0x2f:
            if (aiFlags & 0)
                size += 5;
            break;
        case 0x19: {
            ExtraPackageQ* pPkg = (ExtraPackageQ*)FUN_00ec43fb(p_gslscu, 0, &DAT_01183b2c, &DAT_011844f8, 0);
            size += 0xe;
            if (DAT_011de45c->FUN_008df040() >= 0x40 && DAT_011c3f2c->FUN_00469860(pPkg->pkg->FUN_0084e3a0()))
            {
                size += 1;
                size += pPkg->pkg->v83();
            }
        }
        break;
        case 0x1a:
            if (aiFlags & 0)
            {
                size += 4;
                ExtraTresPassPackageQ* pTres =
                    (ExtraTresPassPackageQ*)FUN_00ec43fb(p_gslscu, 0, &DAT_01183b2c, &DAT_011844d4, 0);
                if (pTres->pkg)
                    size += pTres->pkg->v83();
            }
            break;
        case 0x1c:
            if (aiFlags & 0)
                size += 4;
            break;
        case 0x50:
            break;
        case 0x1b: {
            ExtraRunOncePacksQ* pRun = (ExtraRunOncePacksQ*)FUN_00ec43fb(p_gslscu, 0, &DAT_01183b2c, &DAT_011844b4, 0);
            size += 2;
            size += pRun->list->FUN_005ae380() * 5;
        }
        break;
        case 0x18: {
            ExtraPackageStartLocationQ* pLoc =
                (ExtraPackageStartLocationQ*)FUN_00ec43fb(p_gslscu, 0, &DAT_01183b2c, &DAT_0118448c, 0);
            size += 4;
            size += 0xc;
            size += 4;
        }
        break;
        case 0x1d: {
            ExtraFollowerQ* pFol = (ExtraFollowerQ*)FUN_00ec43fb(p_gslscu, 0, &DAT_01183b2c, &DAT_01184470, 0);
            size += pFol->list->FUN_005ae380() * 4 + 2;
        }
        break;
        case 0x32:
            if (aiFlags & 0)
                size += 12;
            break;
        case 0x33:
            if (aiFlags & 0)
            {
                NonActorMagicTargetQ* pMag =
                    (NonActorMagicTargetQ*)FUN_00ec43fb(p_gslscu, 0, &DAT_01183b2c, &DAT_0118444c, 0);
                size += 4;
                size += FUN_00805a00(pMag->mt.m2(), 0);
            }
            break;
        case 0x2b:
            if (aiFlags & 0x20000)
            {
                ExtraTeleportQ* pTele = (ExtraTeleportQ*)FUN_00ec43fb(p_gslscu, 0, &DAT_01183b2c, &DAT_01184430, 0);
                size += pTele->data->FUN_0043a8f0();
            }
            break;
        case 0x3f:
            if (aiFlags & 0)
                size += 4;
            break;
        case 0x41:
            if (aiFlags & 0x10000000)
            {
                ExtraLastFinishedSequenceQ* pForwardSequence =
                    (ExtraLastFinishedSequenceQ*)FUN_00ec43fb(p_gslscu, 0, &DAT_01183b2c, &DAT_01184408, 0);
                size += 1;
                size += FUN_0044a670(pForwardSequence->seq);
            }
            break;
        case 0x2c:
            if (aiFlags & 0)
                size += 1;
            break;
        case 0x90:
            if (aiFlags & 0)
                size += 1;
            break;
        case 0x91:
            if (aiFlags & 0)
                size += 1;
            break;
        case 0xc:
            if (apObj && apObj->o64())
                size += 4;
            break;
        case 0x51:
            break;
        case 0x39:
            size += 4;
            break;
        case 0x52:
            break;
        case 0x46:
            size += 4;
            break;
        case 0x49:
            if (aiFlags & 0)
                size += 4;
            break;
        case 0x4a:
            if (aiFlags & 0)
                size += 1;
            break;
        case 0x4d: {
            ExtraInfoGeneralTopicQ* pTopic =
                (ExtraInfoGeneralTopicQ*)FUN_00ec43fb(p_gslscu, 0, &DAT_01183b2c, &DAT_011843e4, 0);
            if (pTopic->topic)
                size += pTopic->topic->FUN_0083f280();
        }
        break;
        case 0x4e:
            size += 1;
            break;
        }
        if (prev != size)
            ++size;
        else if ((aiFlags & 0) && p_gslscu->FUN_004f1540() == 0x16)
            ++size;
        else if ((aiFlags & 0) && p_gslscu->FUN_004f1540() == 0x17)
            ++size;
        else if ((aiFlags & 0) && p_gslscu->FUN_004f1540() == 0x3e)
            ++size;
        else if ((aiFlags & 0) && p_gslscu->FUN_004f1540() == 0x47)
            ++size;
        else if ((aiFlags & 0) && p_gslscu->FUN_004f1540() == 0x2e)
            ++size;
        else if (p_gslscu->FUN_004f1540() == 0x1f)
            ++size;
        p_gslscu = p_gslscu->FUN_0044ddc0();
    }
    if (*DAT_011de4e8.FUN_00408d60())
    {
        SaveRecQ* pRec = DAT_011de45c->FUN_004fd3e0();
        if (pRec)
        {
            FormQ* pForm = LookupFormByID(pRec->formID);
            FUN_0040fbe0("GetSaveSize(): %-5i for form %08X %s with flags %08X ending at line %i in file %s",
                         size - start, pRec->formID, pForm->f76(), *(int*)((char*)pRec + 5), 0x29b5,
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ExtraDataList.cpp");
        }
        else
        {
            FUN_0040fbe0("GetSaveSize(): %-5i ending at line %i in file %s", size - start, 0x29b5,
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ExtraDataList.cpp");
        }
    }
    DAT_011c3920.Unlock();
    return size;
}
}  // namespace fnv_00422c40

struct String_00428070
{
    char* unk00;
    unsigned short unk04;
    unsigned short unk06;
    String_00428070(const String_00428070&);
    ~String_00428070();
};

struct Class_00428070
{
    int unk00;
    int unk04;
    int unk08;
    String_00428070 unk0C;
    String_00428070 FUN_00428070();
};

// Returns the unk0C member of the Class_00428070 instance.
// @fnv 0x00428070
String_00428070 Class_00428070::FUN_00428070()
{
    return unk0C;
}

namespace s40fa40 {

struct Owner;

struct Entry
{
    unsigned char FUN_004f1540();
};

extern __declspec(thread) Owner* DAT_01272008;
extern __declspec(thread) Entry* DAT_01272010[147];

void* memset(void* pvDest, int iValue, unsigned int uiSize);

// @fnv 0x0040fa40
void FUN_0040fa40(Owner* pkOwner, Entry* pkEntry)
{
    if (pkOwner && pkEntry)
    {
        if (pkOwner != DAT_01272008)
        {
            memset(DAT_01272010, 0, sizeof(DAT_01272010));
            DAT_01272008 = pkOwner;
        }
        DAT_01272010[pkEntry->FUN_004f1540()] = pkEntry;
    }
}

}

namespace fnv_004183e0 {
extern "C" void __cdecl FUN_00403d30(void*, int, unsigned int);

struct FUN_0040ec80
{
    char b4;
    char pad[7];
    FUN_0040ec80(int);
    virtual ~FUN_0040ec80();
};

struct FUN_00416b40
{
    char buf[0x10];
    FUN_00416b40();
};

struct FUN_004183e0 : FUN_0040ec80
{
    FUN_00416b40 m;
    FUN_004183e0();
    virtual ~FUN_004183e0();
};

// Calls the base constructor with 0x68, then calls FUN_00403d30 with &m, 0, and 0x10.
// @fnv 0x004183e0
FUN_004183e0::FUN_004183e0() : FUN_0040ec80(0x68)
{
    FUN_00403d30(&m, 0, 0x10);
}
}  // namespace fnv_004183e0

namespace fnv_0041d950 {
struct Vec3
{
    int a, b, c;
};
struct Node
{
    char _pad[0xc];
    Vec3 pos;
    __thiscall Node();
};
struct S0041d950
{
    Node* __thiscall FUN_00410220(unsigned char);
    void __thiscall FUN_0040ff60(Node*);
    void __thiscall FUN_0041d950(Vec3* pIn);
};
// Gets or creates a Node, then copies the input Vec3 into its pos field.
// @fnv 0x0041d950
void S0041d950::FUN_0041d950(Vec3* pIn)
{
    Node* p = FUN_00410220(0x13);
    if (p == 0)
    {
        p = new Node();
        FUN_0040ff60(p);
    }
    p->pos = *pIn;
}
}  // namespace fnv_0041d950

namespace s41dcd0 {

struct Form;

struct FormList
{
    bool FUN_005f65d0(Form* const& pkForm);
    void FUN_005ae3d0(Form* const& pkForm);
};

struct ListEntry
{
    int unk00;
    int unk04;
    int unk08;
    FormList m_kForms;
    int unk10;

    ListEntry();
};

struct Owner
{
    ListEntry* FUN_00410220(int iType);
    void FUN_0040ff60(ListEntry* pkEntry);
    void FUN_0041dcd0(Form* pkForm);
};

// Adds pkForm to the owner's form list, creating a new ListEntry if one does not exist for type 0x38.
// @fnv 0x0041dcd0
void Owner::FUN_0041dcd0(Form* pkForm)
{
    if (pkForm)
    {
        ListEntry* pkEntry = FUN_00410220(0x38);
        if (!pkEntry)
        {
            pkEntry = new ListEntry;
            FUN_0040ff60(pkEntry);
        }
        if (!pkEntry->m_kForms.FUN_005f65d0(pkForm))
            pkEntry->m_kForms.FUN_005ae3d0(pkForm);
    }
}

}

namespace s41e530 {

struct Form;

struct FormList
{
    bool FUN_005f65d0(Form* const& pkForm);
    void FUN_005ae3d0(Form* const& pkForm);
};

struct SetEntry
{
    int unk00;
    int unk04;
    int unk08;
    FormList m_kForms;
    int unk10;

    SetEntry();
};

struct Owner
{
    SetEntry* FUN_00410220(int iType);
    void FUN_0040ff60(SetEntry* pkEntry);
    void FUN_0041e530(Form* pkForm);
};

// Looks up or creates a SetEntry for type 0x52, then calls one of two m_kForms methods with pkForm.
// @fnv 0x0041e530
void Owner::FUN_0041e530(Form* pkForm)
{
    if (pkForm)
    {
        SetEntry* pkEntry = FUN_00410220(0x52);
        if (!pkEntry)
        {
            pkEntry = new SetEntry;
            FUN_0040ff60(pkEntry);
        }
        if (!pkEntry->m_kForms.FUN_005f65d0(pkForm))
            pkEntry->m_kForms.FUN_005ae3d0(pkForm);
    }
}

}

struct FUN_0040ecb0
{
    virtual ~FUN_0040ecb0();
};
struct FUN_0041fdb0 : FUN_0040ecb0
{
    virtual ~FUN_0041fdb0();
    void FUN_0041fe10();
};
// @fnv 0x0041fdb0
FUN_0041fdb0::~FUN_0041fdb0()
{
    FUN_0041fe10();
}

namespace extra421 {
struct E4Object
{
    virtual ~E4Object();
};
struct E4Extra
{
    int unk00;
    int unk04;
    int unk08;
    E4Object* pObject;
    E4Extra();
};
struct E4List
{
    E4Extra* FUN_00410220(int type);
    void FUN_0040ff60(E4Extra* extra);
    void FUN_00410140(int type);
    void FUN_00421940(E4Object* object);
};
}
using namespace extra421;

// For nonnull object, replaces or creates the type-5 entry and assigns pObject; for null, calls FUN_00410140(5).
// @fnv 0x00421940
void E4List::FUN_00421940(E4Object* object)
{
    if (object)
    {
        E4Extra* pExtra = FUN_00410220(5);
        if (pExtra)
        {
            if (pExtra->pObject)
            {
                delete pExtra->pObject;
            }
            pExtra->pObject = object;
        }
        else
        {
            pExtra = new E4Extra();
            pExtra->pObject = object;
            FUN_0040ff60(pExtra);
        }
    }
    else
    {
        FUN_00410140(5);
    }
}

namespace s428110 {

struct Color
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;

    Color();
};

struct Owner
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    unsigned char unk014;
    unsigned char unk015;
    unsigned char unk016;
    Color m_kFogTint;

    Color FUN_00428110();
};

// @fnv 0x00428110
Color Owner::FUN_00428110()
{
    return m_kFogTint;
}

}

struct FUN_0040fae0_shell : public BaseExtraList
{
    void FUN_0040fae0(bool);
};

struct ArrSI
{
    virtual ~ArrSI();
    unsigned int GetFlags();
};

extern RecursiveSpinLock g_011c3920;
void __cdecl ResetTlsBufferIfListMatches(const BaseExtraList*);
void* __cdecl memset(void*, int, unsigned int);
// Locks g_011c3920, resets the TLS buffer, optionally deletes each extra in the list or clears pHead, then zeroes iFlags and unlocks.
// @fnv 0x0040fae0
void FUN_0040fae0_shell::FUN_0040fae0(bool abDelete)
{
    g_011c3920.Lock("BaseExtraList::RemoveAll()");
    ResetTlsBufferIfListMatches(this);
    if (abDelete)
    {
        ArrSI* pwork = (ArrSI*)pHead;
        while (pwork)
        {
            ArrSI* ptemp = pwork;
            pwork = (ArrSI*)pwork->GetFlags();
            pHead = (BSExtraData*)pwork;
            if (abDelete)
                delete ptemp;
        }
    }
    else
        pHead = 0;
    memset(iFlags, 0, 0x15);
    g_011c3920.Unlock();
}

struct BSExtraData_vd
{
    virtual ~BSExtraData_vd();
};

struct TESObjectREFR_GetFlags_Helper
{
    unsigned int CallGetFlags();
};
struct TESObjectREFR_Flags
{
    void SetFlags(unsigned int);
};

void __cdecl FUN_0040f7d0(void*, int);
extern int DAT_011c38e4;
extern RecursiveSpinLock g_011c3920;
extern __declspec(thread) int g_tlsDirty[4];
struct FUN_00410020_t : BaseExtraList
{
    BSExtraData* FUN_004102d0(unsigned char);
    void FUN_00410020(BSExtraData* apExtra, bool abDelete);
};
// Looks up an entry using apExtra's IsPatrolling result, updates flags, calls FUN_0040f7d0, clears that bit, and optionally deletes apExtra.
// @fnv 0x00410020
void FUN_00410020_t::FUN_00410020(BSExtraData* apExtra, bool abDelete)
{
    if (!apExtra)
        return;
    g_011c3920.Lock("BaseExtraList::RemoveExtra()");
    int etype = ((PatrolActorPackageData*)apExtra)->IsPatrolling();
    BSExtraData* pprev = FUN_004102d0(etype);
    if (pprev)
        ((TESObjectREFR_Flags*)pprev)->SetFlags(((TESObjectREFR_GetFlags_Helper*)apExtra)->CallGetFlags());
    else
        *(unsigned int*)((char*)this + 4) = ((TESObjectREFR_GetFlags_Helper*)apExtra)->CallGetFlags();
    FUN_0040f7d0(this, etype);
    if (abDelete)
        delete (BSExtraData_vd*)apExtra;
    else
        ((TESObjectREFR_Flags*)apExtra)->SetFlags(0);
    ((FUN_0040fee0_shell*)this)->SetBitFlag(etype, false);
    ++DAT_011c38e4;
    ++g_tlsDirty[3];
    g_011c3920.Unlock();
}

struct FUN_004120b0_shell : public ExtraDataList
{
    void FUN_004120b0();
};

void __cdecl ResetTlsBufferIfListMatches(BaseExtraList const*);

extern RecursiveSpinLock g_011c3920;

struct ExtraVDel
{
    virtual ~ExtraVDel();
};
extern FUN_004121b0_shell* g_BGSSaveLoadGame;

// Locks g_011c3920, retains case 4 and cases 1 or 2 when FUN_004121b0 returns true, and deletes other entries while updating links.
// @fnv 0x004120b0
void FUN_004120b0_shell::FUN_004120b0()
{
    g_011c3920.Lock("ExtraDataList::RemoveNonPersistentCellData()");
    ResetTlsBufferIfListMatches((BaseExtraList*)this);
    BSExtraData* pwork = ((BaseExtraList*)this)->pHead;
    BSExtraData* plast = 0;
    while (pwork)
    {
        BSExtraData* ptemp = pwork;
        pwork = (BSExtraData*)((ArrSI*)pwork)->GetFlags();
        switch (((PatrolActorPackageData*)ptemp)->IsPatrolling())
        {
        case 4:
            plast = ptemp;
            break;
        case 1:
        case 2:
            if (g_BGSSaveLoadGame->FUN_004121b0())
            {
                plast = ptemp;
                break;
            }
        default:
            if (ptemp == ((BaseExtraList*)this)->pHead)
                ((BaseExtraList*)this)->pHead = pwork;
            if (plast)
                ((TESObjectREFR_Flags*)plast)->SetFlags((unsigned int)pwork);
            delete (ExtraVDel*)ptemp;
        }
    }
    g_011c3920.Unlock();
}

class FUN_0041c660_cls
{
  public:
    FUN_0041c660_cls();
    virtual ~FUN_0041c660_cls();

    int m_iValue;
};

// @fnv 0x0041c660
FUN_0041c660_cls::FUN_0041c660_cls()
{}

struct FUN_0041d390_shell : public ExtraDataList
{
    void FUN_0041d390(TESObjectCELL*);
};

struct TESObjectCELL;
struct ExtraPersistentCell : public BSExtraData
{
    TESObjectCELL* pCell;
    ExtraPersistentCell(TESObjectCELL*);
};

// Stores apCell in the ExtraPersistentCell extra data, creating it if absent, or removes the extra when apCell is null.
// @fnv 0x0041d390
void FUN_0041d390_shell::FUN_0041d390(TESObjectCELL* apCell)
{
    BSExtraData* pExtra = ((BaseExtraList*)this)->GetExtraData(0xc);
    if (pExtra)
    {
        if (!apCell)
        {
            ((Dummy_00410020*)this)->FUN_00410020(pExtra, true);
        }
        else
        {
            ((ExtraPersistentCell*)pExtra)->pCell = apCell;
        }
    }
    else if (apCell)
    {
        pExtra = new ExtraPersistentCell(apCell);
        ((BaseExtraList*)this)->AddExtra(pExtra);
    }
}

struct BaseExtraList;

class FUN_0041db50_Class : public BaseExtraList
{
  public:
    void FUN_0041db50(bool bFlag);
};

// Gets extra data 0x37 and, if present, sets its flag to bFlag via SetFlag.
// @fnv 0x0041db50
void FUN_0041db50_Class::FUN_0041db50(bool bFlag)
{
    BSExtraData* extra = this->GetExtraData(0x37);
    if (extra)
    {
        ((FUN_0041db80_Class*)extra)->SetFlag(bFlag);
    }
}

struct FUN_004206e0
{
    virtual ~FUN_004206e0();
};
// Empty destructor for the FUN_004206e0 class.
// @fnv 0x004206e0
FUN_004206e0::~FUN_004206e0()
{}

namespace fnv_0042ca90 {
class ActorCause
{
  public:
    void IncRefCount();
    void DecRefCount();
};

class ExtraActorCauseBase
{
  public:
    virtual ~ExtraActorCauseBase();
    unsigned char m_ucExtraDataType;
    unsigned char layoutPadding5;
    unsigned short layoutPadding6;
    BSExtraData* pNext;
    ExtraActorCauseBase(unsigned char type);
};

ExtraActorCauseBase::ExtraActorCauseBase(unsigned char type)
{
    m_ucExtraDataType = type;
    pNext = 0;
}

class FUN_0042ca90 : public ExtraActorCauseBase
{
  public:
    NiPointer<ActorCause> actorCause;
    virtual ~FUN_0042ca90();
    FUN_0042ca90();
};

// Constructs this object with base type 0x60 and initializes actorCause to null.
// @fnv 0x0042ca90
FUN_0042ca90::FUN_0042ca90() : ExtraActorCauseBase(0x60), actorCause(0)
{}
}  // namespace fnv_0042ca90

struct ExtraNamedBase : public BSExtraData
{
    ~ExtraNamedBase();
};

struct FUN_0041c690 : public ExtraNamedBase
{
    BSStringT<char> kName;
    ~FUN_0041c690();
};

// @fnv 0x0041c690
FUN_0041c690::~FUN_0041c690()
{}

struct MediaLocationController : public TESForm
{
};
class AlchemyItem : public TESForm
{
};
struct TESClimate : public TESForm
{
};
struct BGSAcousticSpace : public TESForm
{
};
struct TESWaterForm : public TESForm
{
};
struct BGSMusicType : public TESForm
{
};
struct TESImageSpace : public TESForm
{
};
struct BGSEncounterZone : public TESForm
{
};
struct TESAmmo : public TESForm
{
};

namespace fnv_00416be0 {
unsigned int __fastcall FUN_004048e0(void*);
class GlobalObject_0096a2d0 : public RecursiveSpinLock
{
  public:
    void Lock(const char*);
};
extern GlobalObject_0096a2d0 g_011c3920;
struct BSSpinLockUnlock
{
    void Unlock();
};
void __cdecl ResolveFormID(unsigned int*, TESFile*);
TESForm* __cdecl LookupFormByID(unsigned int);
void __cdecl FNV_Warning(const char*, ...);
struct ResolveList;
struct ResolveForm : TESForm
{
    bool FUN_00575d10();
    bool FUN_0056aac0();
    ResolveList* FUN_005d43c0();
    int FUN_00401170();
    void RemapImpactData(TESForm*);
};
struct ResolveList
{
    void FUN_0041dcd0(TESObjectREFR*);
    void FUN_0041e530(TESForm*);
    void FUN_00420ce0(TESForm*);
    void FUN_0041edd0(TESForm*);
    ResolveList* FUN_00422120();
    void SetIndexedValue(int, ResolveList*);
};
struct ResolveArray
{
    TESObjectREFR* items[4];
};
struct ResolvePair
{
    TESObjectREFR* items[2];
};
struct ResolveNode
{
    void* value;
    ResolveNode* next;
    void** FUN_006815c0();
    ResolveNode* FUN_00726070();
    bool FUN_008256d0();
    void FUN_00726c60(TESObjectREFR**);
    void FUN_00905330(void**);
    void FUN_0063f7b0();
};
struct ResolveItem
{
    TESObjectREFR* ref;
};
struct ResolvePayload
{
    int unk00;
    int unk04;
    int unk08;
    TESObjectREFR* ref;
};
struct ResolveExtraNode : BSExtraData
{
    ResolveExtraNode* FUN_0044ddc0();
    unsigned char FUN_004f1540();
};
struct ResolveExtraValue : ResolveExtraNode
{
    TESForm* form;
};
struct ResolveExtraPointer : ResolveExtraNode
{
    ResolveForm* value;
};
struct ResolveExtraPayload : ResolveExtraNode
{
    ResolvePayload payload;
};
struct ResolveExtraArray : ResolveExtraNode
{
    ResolveArray* array;
};
struct ResolveExtraPair : ResolveExtraNode
{
    ResolvePair* pair;
};
struct ResolveExtraLinked : ResolveExtraNode
{
    ResolvePayload* payload;
};
struct ResolveExtraList : ResolveExtraNode
{
    ResolveNode list;
    bool flag;
    unsigned char flag15;
    short flag16;
    BSStringT<char> text;
};
struct ResolveExtraCall : ResolveExtraNode
{
    ResolveNode list;
    void FUN_00433db0(TESForm*);
    void FUN_00433ed0(TESForm*);
    void FUN_00434050(TESForm*);
};
struct ResolveExtraOwner : BaseExtraList
{
    void FUN_00416be0(TESForm*);
    void FUN_00410020(BSExtraData*, bool);
    ResolveList* FUN_00422120();
    ResolveList* FUN_0041fe90();
};
struct ResolveMap
{
    bool FUN_00438ef0();
    bool FUN_00438ed0();
    void FUN_0044de80(bool);
    unsigned int FUN_0044edb0();
    void FUN_00437730(TESForm*);
};
struct ResolveManager
{
    TESForm* FUN_00461630(unsigned int);
};
extern ResolveManager* g_ResolveManager;
struct ResolveCheck
{
    bool FUN_0043a590(TESForm*);
};
struct ResolveMedia
{
    unsigned int FUN_0059bb30();
    void FUN_007037c0(unsigned int);
};
struct ResolveActorBase
{
    int FUN_005f0b00();
};
struct ResolveActor : TESForm
{
    ResolveActorBase* FUN_004181e0();
};
struct ResolvePatrol
{
    void FUN_0067c6c0(TESForm*);
};
// Iterates the extra data list, resolving form references via LookupFormByID and removing invalid entries with FUN_00410020.
// @fnv 0x00416be0
void ResolveExtraOwner::FUN_00416be0(TESForm* owner)
{
    g_011c3920.Lock(0);
    ResolveExtraNode* pNode = static_cast<ResolveExtraNode*>(pHead);
    TESFile* sourceFile = owner->GetFile(-1);
    while (pNode)
    {
        ResolveExtraNode* next = pNode->FUN_0044ddc0();
        switch (pNode->FUN_004f1540())
        {
        case 104: {
            ResolvePayload* sourceFile = &static_cast<ResolveExtraPayload*>(pNode)->payload;
            unsigned int pNode = reinterpret_cast<unsigned int>(sourceFile->ref);
            if (pNode)
            {
                ResolveFormID(&pNode, owner->GetFile(-1));
                sourceFile->ref = dynamic_cast<TESObjectREFR*>(LookupFormByID(pNode));
                if (!sourceFile->ref)
                    FNV_Warning("MASTERFILE: Could not find radio range position ref (%08X).", pNode);
                else if (static_cast<ResolveForm*>(static_cast<TESForm*>(sourceFile->ref))->FUN_00575d10())
                    FNV_Warning("MASTERFILE: Invalid radio range position ref (%08X). Exteriors only.", pNode);
            }
            break;
        }
        case 42: {
            ResolvePayload* data = reinterpret_cast<ResolvePayload*>(static_cast<ResolveExtraPointer*>(pNode)->value);
            bool failed = false;
            if (!failed && data->unk04)
            {
                unsigned int id = data->unk04;
                ResolveFormID(&id, sourceFile);
                data->unk04 = reinterpret_cast<int>(dynamic_cast<TESKey*>(LookupFormByID(id)));
                if (!data->unk04)
                {
                    FNV_Warning("MASTERFILE: Unable to find key %08X for lock data. Lock will be removed.", id);
                    failed = true;
                }
            }
            if (failed)
                FUN_00410020(pNode, true);
            break;
        }
        case 43: {
            bool failed = false;
            ResolveCheck* data = reinterpret_cast<ResolveCheck*>(static_cast<ResolveExtraPointer*>(pNode)->value);
            if (failed || !data->FUN_0043a590(owner))
                FUN_00410020(pNode, true);
            break;
        }
        case 44: {
            ResolveMap* sourceFile = reinterpret_cast<ResolveMap*>(static_cast<ResolveExtraPointer*>(pNode)->value);
            if (sourceFile->FUN_00438ef0() && !sourceFile->FUN_00438ed0())
                sourceFile->FUN_0044de80(false);
            unsigned int pNode = sourceFile->FUN_0044edb0();
            if (pNode)
            {
                TESForm* form = g_ResolveManager->FUN_00461630(pNode);
                sourceFile->FUN_00437730(form);
            }
            break;
        }
        case 144: {
            ResolveMedia* data = reinterpret_cast<ResolveMedia*>(static_cast<ResolveExtraPointer*>(pNode)->value);
            unsigned int id = data->FUN_0059bb30();
            ResolveFormID(&id, owner->GetFile(-1));
            if (dynamic_cast<MediaLocationController*>(LookupFormByID(id)))
                data->FUN_007037c0(id);
            else
                FNV_Warning(
                    "MASTERFILE: Could not find MediaLocationController (%08X) for a AudioMarker in extra data list.",
                    id);
            break;
        }
        case 145: {
            ResolveForm* data = static_cast<ResolveExtraPointer*>(pNode)->value;
            break;
        }
        case 33: {
            ResolveExtraValue* extra = static_cast<ResolveExtraValue*>(pNode);
            unsigned int id = reinterpret_cast<unsigned int>(extra->form);
            ResolveFormID(&id, sourceFile);
            extra->form = LookupFormByID(id);
            if (!extra->form)
            {
                FNV_Warning("MASTERFILE: Unable to find ownership owner form %08X. Ownership will be removed.", id);
                FUN_00410020(extra, true);
            }
            break;
        }
        case 34: {
            ResolveExtraValue* extra = static_cast<ResolveExtraValue*>(pNode);
            unsigned int id = reinterpret_cast<unsigned int>(extra->form);
            ResolveFormID(&id, sourceFile);
            extra->form = dynamic_cast<TESGlobal*>(LookupFormByID(id));
            if (!extra->form)
            {
                FNV_Warning("MASTERFILE: Unable to find ownership condition global %08X. Ownership will be removed.",
                            id);
                FUN_00410020(extra, true);
            }
            break;
        }
        case 63: {
            ResolveExtraValue* extra = static_cast<ResolveExtraValue*>(pNode);
            unsigned int id = reinterpret_cast<unsigned int>(extra->form);
            ResolveFormID(&id, sourceFile);
            extra->form = dynamic_cast<AlchemyItem*>(LookupFormByID(id));
            if (!extra->form)
            {
                FNV_Warning("MASTERFILE: Unable to find poison %08X. Poison data will be removed.", id);
                FUN_00410020(extra, true);
            }
            break;
        }
        case 8: {
            ResolveExtraValue* extra = static_cast<ResolveExtraValue*>(pNode);
            unsigned int id = reinterpret_cast<unsigned int>(extra->form);
            ResolveFormID(&id, sourceFile);
            extra->form = dynamic_cast<TESClimate*>(LookupFormByID(id));
            if (!extra->form)
            {
                FNV_Warning("MASTERFILE: Unable to find cell climate %08X. Climate data will be removed.", id);
                FUN_00410020(extra, true);
            }
            break;
        }
        case 89: {
            ResolveExtraValue* extra = static_cast<ResolveExtraValue*>(pNode);
            unsigned int id = reinterpret_cast<unsigned int>(extra->form);
            ResolveFormID(&id, sourceFile);
            extra->form = dynamic_cast<TESImageSpace*>(LookupFormByID(id));
            if (!extra->form)
            {
                FNV_Warning("MASTERFILE: Unable to find cell imagespace %08X. ImageSpace data will be removed.", id);
                FUN_00410020(extra, true);
            }
            break;
        }
        case 140: {
            ResolveExtraPointer* extra = static_cast<ResolveExtraPointer*>(pNode);
            if (extra->value)
                extra->value->RemapImpactData(owner);
            break;
        }
        case 129: {
            ResolveExtraValue* extra = static_cast<ResolveExtraValue*>(pNode);
            unsigned int id = reinterpret_cast<unsigned int>(extra->form);
            ResolveFormID(&id, sourceFile);
            extra->form = dynamic_cast<BGSAcousticSpace*>(LookupFormByID(id));
            if (!extra->form)
            {
                FNV_Warning("MASTERFILE: Unable to find cell acoustic space %08X. AcousticSpace data will be removed.",
                            id);
                FUN_00410020(extra, true);
            }
            break;
        }
        case 3: {
            ResolveExtraValue* extra = static_cast<ResolveExtraValue*>(pNode);
            unsigned int id = reinterpret_cast<unsigned int>(extra->form);
            ResolveFormID(&id, sourceFile);
            extra->form = dynamic_cast<TESWaterForm*>(LookupFormByID(id));
            if (!extra->form)
            {
                FNV_Warning("MASTERFILE: Unable to find cell water type %08X. Water data will be removed.", id);
                FUN_00410020(extra, true);
            }
            break;
        }
        case 7: {
            ResolveExtraValue* extra = static_cast<ResolveExtraValue*>(pNode);
            unsigned int id = reinterpret_cast<unsigned int>(extra->form);
            ResolveFormID(&id, sourceFile);
            extra->form = dynamic_cast<BGSMusicType*>(LookupFormByID(id));
            if (!extra->form)
            {
                FNV_Warning("MASTERFILE: Unable to find cell music type %08X. Music data will be removed.", id);
                FUN_00410020(extra, true);
            }
            break;
        }
        case 24: {
            ResolveExtraValue* extra = static_cast<ResolveExtraValue*>(pNode);
            unsigned int id = reinterpret_cast<unsigned int>(extra->form);
            ResolveFormID(&id, sourceFile);
            extra->form = LookupFormByID(id);
            if (!extra->form)
            {
                FNV_Warning(
                    "MASTERFILE: Unable to find package start location cell %08X. Package start location extra data will be removed.",
                    id);
                FUN_00410020(extra, true);
            }
            break;
        }
        case 55: {
            ResolveExtraValue* extra = static_cast<ResolveExtraValue*>(pNode);
            unsigned int id = reinterpret_cast<unsigned int>(extra->form);
            ResolveFormID(&id, sourceFile);
            extra->form = dynamic_cast<TESObjectREFR*>(LookupFormByID(id));
            if (!extra->form)
            {
                FNV_Warning(
                    "MASTERFILE: Unable to find enable state parent %08X. Enable state parent data will be removed.",
                    id);
                FUN_00410020(extra, true);
            }
            else
            {
                TESObjectREFR* ref = dynamic_cast<TESObjectREFR*>(owner);
                if (ref && static_cast<ResolveForm*>(static_cast<TESForm*>(ref))->FUN_0056aac0())
                    static_cast<ResolveForm*>(extra->form)->FUN_005d43c0()->FUN_0041dcd0(ref);
                else
                {
                    FNV_Warning("MASTERFILE: Enable state parent loop detected. Parent removed.");
                    FUN_00410020(extra, true);
                }
            }
            break;
        }
        case 59: {
            ResolveExtraValue* extra = static_cast<ResolveExtraValue*>(pNode);
            unsigned int id = reinterpret_cast<unsigned int>(extra->form);
            ResolveFormID(&id, sourceFile);
            extra->form = dynamic_cast<TESObjectREFR*>(LookupFormByID(id));
            if (!extra->form)
            {
                FNV_Warning(
                    "MASTERFILE: Unable to find random door teleport marker %08X. Random door teleport marker data will be removed.",
                    id);
                FUN_00410020(extra, true);
            }
            break;
        }
        case 20: {
            if (owner->IsActor())
            {
                ResolveActor* actor = static_cast<ResolveActor*>(owner);
                if (actor->FUN_004181e0() && actor->FUN_004181e0()->FUN_005f0b00() > 0)
                    FNV_Warning("MASTERFILE: Ragdoll data found on alive actor %08X. Ragdoll data will be removed.",
                                owner->GetFormID());
            }
            break;
        }
        case 81: {
            ResolveExtraValue* extra = static_cast<ResolveExtraValue*>(pNode);
            unsigned int id = reinterpret_cast<unsigned int>(extra->form);
            ResolveFormID(&id, sourceFile);
            extra->form = dynamic_cast<TESObjectREFR*>(LookupFormByID(id));
            if (!extra->form)
            {
                FNV_Warning("MASTERFILE: Unable to find linked reference %08X. Linked reference data will be removed.",
                            id);
                FUN_00410020(extra, true);
            }
            else
                static_cast<ResolveForm*>(extra->form)->FUN_005d43c0()->FUN_0041e530(owner);
            break;
        }
        case 118: {
            ResolveExtraArray* extra = static_cast<ResolveExtraArray*>(pNode);
            for (int index = 0; index < 4; index++)
            {
                unsigned int list = reinterpret_cast<unsigned int>(extra->array->items[index]);
                list = 0;
                ResolveFormID(&list, sourceFile);
                extra->array->items[index] = dynamic_cast<TESObjectREFR*>(LookupFormByID(list));
                if (list && !extra->array->items[index])
                {
                    FNV_Warning(
                        "MASTERFILE: Unable to find occlusion plane reference %08X. Occlusion plane reference data will be removed.",
                        list);
                    FUN_00410020(extra, true);
                    break;
                }
                ResolveList* id = FUN_00422120();
                if (id)
                {
                    if (extra->array->items[index])
                        id->SetIndexedValue(index,
                                         static_cast<ResolveForm*>(static_cast<TESForm*>(extra->array->items[index]))
                                             ->FUN_005d43c0()
                                             ->FUN_00422120());
                }
                else
                    FNV_Warning("No occlusion plane for occlusion plane ref extra.");
            }
            break;
        }
        case 119: {
            ResolveExtraPair* extra = static_cast<ResolveExtraPair*>(pNode);
            for (int index = 0; index < 2; index++)
            {
                unsigned int id = reinterpret_cast<unsigned int>(extra->pair->items[index]);
                ResolveFormID(&id, sourceFile);
                extra->pair->items[index] = dynamic_cast<TESObjectREFR*>(LookupFormByID(id));
                if (id && !extra->pair->items[index])
                {
                    FNV_Warning(
                        "MASTERFILE: Unable to find portal linked reference %08X. Portal linked reference data will be removed.",
                        id);
                    FUN_00410020(extra, true);
                    break;
                }
            }
            if (extra->pair->items[0] == extra->pair->items[1])
            {
                if (extra->pair->items[0])
                {
                    FNV_Warning(
                        "MASTERFILE: Both of portal %08X's linked rooms are the same (%08X). Attempting to fix.",
                        owner->GetFormID(), extra->pair->items[0]->GetFormID());
                    extra->pair->items[1] = 0;
                }
                else
                    FNV_Warning("MASTERFILE: Both of portal %08X's linked rooms are NULL.", owner->GetFormID());
            }
            if (extra->pair->items[0])
                static_cast<ResolveForm*>(static_cast<TESForm*>(extra->pair->items[0]))
                    ->FUN_005d43c0()
                    ->FUN_00420ce0(owner);
            if (extra->pair->items[1])
                static_cast<ResolveForm*>(static_cast<TESForm*>(extra->pair->items[1]))
                    ->FUN_005d43c0()
                    ->FUN_00420ce0(owner);
            break;
        }
        case 123: {
            ResolveExtraLinked* node = static_cast<ResolveExtraLinked*>(pNode);
            ResolveNode* extra = reinterpret_cast<ResolveNode*>(&node->payload->unk08);
            while (extra && *extra->FUN_006815c0())
            {
                unsigned int ref = reinterpret_cast<unsigned int>(*extra->FUN_006815c0());
                ResolveFormID(&ref, sourceFile);
                TESObjectREFR* id = dynamic_cast<TESObjectREFR*>(LookupFormByID(ref));
                if (ref && !id)
                {
                    FNV_Warning(
                        "MASTERFILE: Unable to find room linked reference %08X. Room linked reference data will be removed.",
                        ref);
                    FUN_00410020(node, true);
                    break;
                }
                else if (ref)
                    extra->FUN_00726c60(&id);
                extra = extra->FUN_00726070();
            }
            break;
        }
        case 83: {
            ResolveExtraList* extra = static_cast<ResolveExtraList*>(pNode);
            ResolveNode* node = &extra->list;
            ResolveNode* previous = 0;
            while (node && !node->FUN_008256d0())
            {
                ResolveItem* item = static_cast<ResolveItem*>(*node->FUN_006815c0());
                unsigned int id = reinterpret_cast<unsigned int>(item->ref);
                ResolveFormID(&id, sourceFile);
                item->ref = dynamic_cast<TESObjectREFR*>(LookupFormByID(id));
                if (!item->ref)
                {
                    FNV_Warning("MASTERFILE: Unable to find activate reference %08X.", id);
                    if (previous)
                    {
                        previous->FUN_00905330(reinterpret_cast<void**>(&item));
                        node = previous->FUN_00726070();
                    }
                    else
                        node->FUN_0063f7b0();
                    delete item;
                }
                else
                {
                    static_cast<ResolveForm*>(static_cast<TESForm*>(item->ref))->FUN_005d43c0()->FUN_0041edd0(owner);
                    previous = node;
                    node = node->FUN_00726070();
                }
            }
            if (extra->list.FUN_008256d0() && !extra->flag && !FUN_004048e0(&extra->text))
            {
                FNV_Warning("MASTERFILE: Removing empty activate parent extra.");
                FUN_00410020(extra, true);
            }
            break;
        }
        case 87: {
            ResolveExtraCall* extra = static_cast<ResolveExtraCall*>(pNode);
            extra->FUN_00433db0(owner);
            if (extra->list.FUN_008256d0())
            {
                FNV_Warning("MASTERFILE: Removing empty decal extra.");
                FUN_00410020(extra, true);
            }
            break;
        }
        case 60: {
            ResolveExtraValue* extra = static_cast<ResolveExtraValue*>(pNode);
            unsigned int id = reinterpret_cast<unsigned int>(extra->form);
            ResolveFormID(&id, sourceFile);
            extra->form = dynamic_cast<TESObjectREFR*>(LookupFormByID(id));
            if (!extra->form)
            {
                FNV_Warning(
                    "MASTERFILE: Unable to find merchant container %08X. Merchant container data will be removed.", id);
                FUN_00410020(extra, true);
            }
            break;
        }
        case 68: {
            ResolveExtraValue* extra = static_cast<ResolveExtraValue*>(pNode);
            unsigned int id = reinterpret_cast<unsigned int>(extra->form);
            ResolveFormID(&id, sourceFile);
            extra->form = dynamic_cast<TESObjectREFR*>(LookupFormByID(id));
            if (!extra->form)
            {
                FNV_Warning("MASTERFILE: Unable to find XMarker target %08X. XMarker target data will be removed.", id);
                FUN_00410020(extra, true);
            }
            break;
        }
        case 116: {
            ResolveExtraValue* extra = static_cast<ResolveExtraValue*>(pNode);
            unsigned int id = reinterpret_cast<unsigned int>(extra->form);
            ResolveFormID(&id, sourceFile);
            extra->form = dynamic_cast<BGSEncounterZone*>(LookupFormByID(id));
            if (!extra->form)
            {
                FNV_Warning("Unable to find encounter zone %08X. Encounter zone data will be removed.", id);
                FUN_00410020(extra, true);
            }
            break;
        }
        case 103: {
            ResolveExtraValue* extra = static_cast<ResolveExtraValue*>(pNode);
            unsigned int id = reinterpret_cast<unsigned int>(extra->form);
            ResolveFormID(&id, sourceFile);
            extra->form = LookupFormByID(id);
            if (extra->form)
            {
                switch (static_cast<ResolveForm*>(extra->form)->FUN_00401170())
                {
                case 30:
                case 55:
                    break;
                default:
                    extra->form = 0;
                    break;
                }
            }
            if (!extra->form)
            {
                FNV_Warning("MASTERFILE: Unable to find emittance source %08X. Emittance source data will be removed.",
                            id);
                FUN_00410020(extra, true);
            }
            break;
        }
        case 99: {
            ResolveExtraValue* extra = static_cast<ResolveExtraValue*>(pNode);
            unsigned int id = reinterpret_cast<unsigned int>(extra->form);
            ResolveFormID(&id, sourceFile);
            extra->form = dynamic_cast<TESObjectREFR*>(LookupFormByID(id));
            if (extra->form == owner)
                extra->form = 0;
            if (!extra->form)
            {
                FNV_Warning(
                    "MASTERFILE: Unable to find multibound ref %08X used by reference %08X. Multibound ref data will be removed.",
                    id, owner->GetFormID());
                FUN_00410020(extra, true);
            }
            break;
            break;
        }
        case 102: {
            ResolveExtraCall* extra = static_cast<ResolveExtraCall*>(pNode);
            extra->FUN_00433ed0(owner);
            if (extra->list.FUN_008256d0())
            {
                FNV_Warning("MASTERFILE: Removing empty reflector water extra.");
                FUN_00410020(extra, true);
            }
            break;
        }
        case 133: {
            ResolveExtraCall* extra = static_cast<ResolveExtraCall*>(pNode);
            extra->FUN_00434050(owner);
            if (extra->list.FUN_008256d0())
            {
                FNV_Warning("MASTERFILE: Removing empty lit water extra.");
                FUN_00410020(extra, true);
            }
            break;
        }
        case 110: {
            ResolveExtraValue* extra = static_cast<ResolveExtraValue*>(pNode);
            unsigned int id = reinterpret_cast<unsigned int>(extra->form);
            ResolveFormID(&id, sourceFile);
            extra->form = dynamic_cast<TESAmmo*>(LookupFormByID(id));
            if (!extra->form)
            {
                FNV_Warning("Unable to find ammo %08X. Ammo data will be removed.", id);
                FUN_00410020(extra, true);
            }
            break;
            break;
            break;
        }
        case 111: {
            ResolvePatrol* data = reinterpret_cast<ResolvePatrol*>(FUN_0041fe90());
            if (data)
                data->FUN_0067c6c0(owner);
            break;
        }
        default:
            break;
        }
        pNode = next;
    }
    reinterpret_cast<BSSpinLockUnlock*>(&g_011c3920)->Unlock();
}

}

struct RemoveExtraList : public BaseExtraList
{
    void FUN_00410140(unsigned char);
};

struct XD
{
    virtual ~XD();
};
struct S_0044ddc0
{
    unsigned int FUN_0044ddc0();
    bool FUN_004f1540();
};
struct S_00403550
{
    void FUN_00403550(unsigned int);
};
struct S_0040fee0
{
    void SetBitFlag(unsigned char, bool);
};
void* __fastcall FUN_00726070(void*);
void __cdecl FUN_0040f7d0(void*, int);
class GlobalObject_0096a2d0 : public RecursiveSpinLock
{
  public:
    void Lock(const char*);
};
class BSSpinLockUnlock
{
  public:
    void Unlock();
};
// Removes the first extra data entry of the given type from the list, updating the head or previous link and calling FUN_0040f7d0.
// @fnv 0x00410140
void RemoveExtraList::FUN_00410140(unsigned char etype)
{
    g_011c3920.Lock("BaseExtraList::RemoveExtra()");
    XD* pprev = 0;
    XD* apExtra = (XD*)FUN_00726070(this);
    while (apExtra && ((S_0044ddc0*)apExtra)->FUN_004f1540() != etype)
    {
        pprev = apExtra;
        apExtra = (XD*)((S_0044ddc0*)apExtra)->FUN_0044ddc0();
    }
    if (apExtra)
    {
        if (pprev)
            ((S_00403550*)pprev)->FUN_00403550(((S_0044ddc0*)apExtra)->FUN_0044ddc0());
        else
            pHead = (BSExtraData*)((S_0044ddc0*)apExtra)->FUN_0044ddc0();
        FUN_0040f7d0(this, etype);
        delete apExtra;
    }
    ((S_0040fee0*)this)->SetBitFlag(etype, false);
    ((BSSpinLockUnlock*)&g_011c3920)->Unlock();
}

struct CopyableExtraList : public ExtraDataList
{
    void FUN_00411fd0(bool);
};

struct CopyableExtraNode
{
    virtual ~CopyableExtraNode();
    unsigned int FUN_0044ddc0();
    void FUN_00403550(unsigned int);
};
extern RecursiveSpinLock g_011c3920;
void __cdecl ResetTlsBufferIfListMatches(const BaseExtraList*);
struct S11f20
{
    bool FUN_00411f20(BSExtraData*);
};
// Removes all copyable extra data nodes from the list, optionally deleting them, while holding the ExtraDataList lock.
// @fnv 0x00411fd0
void CopyableExtraList::FUN_00411fd0(bool abdelete)
{
    CopyableExtraNode* pwork;
    CopyableExtraNode* plast;
    g_011c3920.Lock("ExtraDataList::RemoveAllCopyableExtra()");
    pwork = (CopyableExtraNode*)pHead;
    plast = 0;
    ResetTlsBufferIfListMatches(this);
    while (pwork)
    {
        CopyableExtraNode* pcur = pwork;
        pwork = (CopyableExtraNode*)pwork->FUN_0044ddc0();
        if (((S11f20*)this)->FUN_00411f20((BSExtraData*)pcur))
        {
            if ((BSExtraData*)pcur == pHead)
                pHead = (BSExtraData*)pwork;
            if (plast)
                plast->FUN_00403550((unsigned int)pwork);
            if (abdelete)
                delete pcur;
        }
        else
            plast = pcur;
    }
    g_011c3920.Unlock();
}

namespace texture_lookup {
struct TextureView
{
    char const* FUN_00408da0();
};
void* __cdecl FUN_00ec43fb(void*, int, void*, void*, int);
char* __cdecl FUN_00480ef0(::TESForm*, int);
extern unsigned int DAT_01183028;
extern unsigned int DAT_01183218;
}

// Returns the view method's string when present; otherwise returns the fallback result or an empty string.
// @fnv 0x0048e730
char const* FUN_0048e730(::TESForm* form, int arg)
{
    texture_lookup::TextureView* pTexture;
    char const* pName;
    char const* result;

    pTexture = (texture_lookup::TextureView*)texture_lookup::FUN_00ec43fb(form, 0, &texture_lookup::DAT_01183028,
                                                                          &texture_lookup::DAT_01183218, 0);
    if (pTexture == 0)
    {
        pName = texture_lookup::FUN_00480ef0(form, arg);
        if (pName != 0)
            result = pName;
        else
            result = "";
        return result;
    }
    return pTexture->FUN_00408da0();
}
