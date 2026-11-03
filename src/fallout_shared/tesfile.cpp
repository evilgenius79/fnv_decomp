// fallout_shared/tesfile.cpp: TESFile, TgtOps, TESFile_Standin, GroupWriter and more (87 functions)

#include "tesfile_TESFile.h"
#include "OSGlobals.h"
#include "original_threads.h"
#include "game_constants.h"

// @fnv 0x004739b0
TESFile* TESFile::GetParentTESFile()
{
    TESFile* file = this;
    while (file->GetThreadSafeRootFile())
    {
        file = file->GetThreadSafeRootFile();
    }
    if (file && gm_GetCurrentThreadId() == g_osGlobals->GetUptimeMilliseconds())
    {
        return file;
    }
    return file->GetFileForThread(gm_GetCurrentThreadId());
}

#ifndef FNV_FIRST_TARGET_ONLY
// @fnv 0x00473c70
TESFile* TESFile::GetThreadSafeRootFile()
{
    TESFile* parent = m_pThreadSafeParent;
    while (parent && parent->m_pThreadSafeParent)
    {
        parent = parent->m_pThreadSafeParent;
    }
    return parent;
}

// @fnv 0x00401680
bool TESFile::IsEndianConversionRequired()
{
    return m_bIsSaving;
}

extern unsigned int kGroupFormType;

// Returns true when the current form is not a group form and its flags include kCompressedRecordFlag.
// @fnv 0x00472100
bool TESFile::IsCurrentFormCompressed()
{
    return m_kRecordInfo.form != kGroupFormType && (m_kRecordInfo.flags & kCompressedRecordFlag);
}

extern TESDataHandler* g_dataHandler;
// Returns the TESFile cached for threadID, creating and registering a new read-only TESFile from this file's path and metadata if none exists.
// @fnv 0x00473ae0
TESFile* TESFile::GetFileForThread(unsigned int threadID)
{
    TESFile* file = 0;
    if (m_pThreadSafeFileMap)
    {
        m_pThreadSafeFileMap->GetAt(threadID, file);
    }
    if (!file)
    {
        file = new TESFile(GetPath(), GetFilename(), NiFile::READ_ONLY);
        file->SetMasterFile(IsMasterFile());
        file->SetCompileIndex(GetFileCompileIndex());
        file->CheckMasterFiles(g_dataHandler->GetFileList(), false);
        file->SetThreadSafeParent(this);
        file->OpenTESFile(NiFile::READ_ONLY, false);
        if (!m_pThreadSafeFileMap)
        {
            m_pThreadSafeFileMap = new NiTPointerMap<unsigned int, TESFile*>(kThreadSafeFileMapBuckets);
        }
        m_pThreadSafeFileMap->SetAt(threadID, file);
        file->InitializeComponent();
    }
    return file;
}
#endif

// @fnv 0x00470b90
BSSimpleList<_ULARGE_INTEGER*>* TESFile::GetMasterDataList()
{
    return &m_kFileSizeList;
}

// @fnv 0x00470c70
bool TESFile::OpenTESFile(NiFile::OpenMode openMode, bool closeOverride)
{
    return OpenTESFile(m_acPath, m_acFilename, openMode, closeOverride);
}

// @fnv 0x00471c20
bool TESFile::IsMasterFile()
{
    if (m_uiFileCount & 1)
        return true;
    else
        return false;
}

// @fnv 0x00471c50
void TESFile::SetMasterFile(bool master)
{
    if (master)
        m_uiFileCount |= 1;
    else
        m_uiFileCount &= ~1;
}

// @fnv 0x00471ca0
bool TESFile::GetOptimizedFile()
{
    if (m_uiFileCount & 0x10)
        return true;
    else
        return false;
}

// @fnv 0x00471cd0
bool TESFile::GetIsChecked()
{
    if (m_uiFileCount & 4)
        return true;
    else
        return false;
}

// Resets the current chunk id to CHUNK_ID_NO_CHUNK and clears the chunk size to 0.
// @fnv 0x004720d0
void TESFile::ClearCurrentChunk()
{
    m_eChunkID = CHUNK_ID_NO_CHUNK;
    m_uiChunkSize = 0;
}

// @fnv 0x00473250
unsigned char TESFile::GetFileCompileIndex()
{
    return m_ucCompileIndex;
}

// @fnv 0x00473640
bool TESFile::GetHasGroups()
{
    return m_bIsLoading;
}

// Walks up the parent chain to the topmost parent and stores it as this file's parent.
// @fnv 0x00473cb0
void TESFile::SetThreadSafeParent(TESFile* parent)
{
    while (parent->m_pThreadSafeParent)
        parent = parent->m_pThreadSafeParent;
    m_pThreadSafeParent = parent;
}

// @fnv 0x00473d20
void TESFile::SetTempIDOwner(bool owner)
{
    if (owner)
        m_uiFileCount |= 0x20;
    else
        m_uiFileCount &= ~0x20;
}

// @fnv 0x00473d70
bool TESFile::GetTempIDOwner()
{
    if (m_uiFileCount & 0x20)
        return true;
    return false;
}

// @fnv 0x004724c0
unsigned int TESFile::GetOffsetChunk()
{
    return m_uiRecordSize + GetFORMSize() + m_uiRecordOffset;
}

// @fnv 0x00473660
bool TESFile::IsGroupOpen()
{
    bool next = false;
    if (m_kRecordInfo.form == kGroupFormType)
    {
        m_kRecordInfo.form = 0;
        m_kRecordInfo.length -= GetFORMSize();
        next = HasNextForm();
    }
    return next;
}

struct VTable_00408df0
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
};

struct GlobalObject_00680890;
extern GlobalObject_00680890 g_011c3400;
VTable_00408df0** __fastcall _ref_006815c0(GlobalObject_00680890*);
GlobalObject_00680890* __fastcall _ref_00726070(GlobalObject_00680890*);

// Iterates the global list from g_011c3400 and calls v88 on each item obtained via _ref_006815c0.
// @fnv 0x00408df0
void FUN_00408df0()
{
    VTable_00408df0* pItem;
    for (GlobalObject_00680890* pNode = &g_011c3400; pNode && (pItem = *_ref_006815c0(pNode));
         pNode = _ref_00726070(pNode))
    {
        pItem->v88();
    }
}

class BaseExtraList
{
  public:
    BSExtraData* GetExtraData(unsigned char);
};

// Retrieves extra data of type 0x8c from the list and returns the int stored at offset 0xc, or 0 if absent.
// @fnv 0x0041c460
int __fastcall FUN_0041c460(BaseExtraList* apExtraList)
{
    BSExtraData* pExtra = apExtraList->GetExtraData(0x8c);
    if (!pExtra)
    {
        return 0;
    }
    return *(int*)((char*)pExtra + 0xc);
}

extern float DAT_01019dd4;
extern unsigned int DAT_01186740;
void* __cdecl memset(void*, int, size_t);
int __fastcall FUN_00471400(void*);
bool __fastcall FUN_00471130(void*);
void __cdecl _FNV_Warning(const char*, ...);

class RecursiveSpinLock
{
  public:
    unsigned int d0;
    unsigned int d1;
    RecursiveSpinLock();
    ~RecursiveSpinLock();
};

struct FUN_00470710
{
    unsigned int f000;
    unsigned int f004;
    unsigned int f008;
    unsigned int f00c;
    unsigned int f010;
    char pad014[0x214];
    unsigned int f228;
    unsigned int f22c;
    unsigned int f230;
    unsigned int f234;
    unsigned int f238;
    unsigned int f23c;
    char f240[0x18];
    unsigned int f258;
    unsigned int f25c;
    unsigned int f260;
    unsigned int f264;
    unsigned int f268;
    unsigned int f26c;
    char pad270[0x18];
    unsigned int f288;
    unsigned int f28c;
    RecursiveSpinLock f290;
    char f298;
    unsigned char f299;
    unsigned char f29a;
    char f29b;
    char f29c[0x1c];
    unsigned int f2b8;
    unsigned int f2bc;
    char pad2c0[0x11c];
    float f3dc;
    unsigned int f3e0;
    unsigned int f3e4;
    unsigned int f3e8;
    RecursiveSpinLock f3ec;
    RecursiveSpinLock f3f4;
    unsigned int f3fc;
    unsigned int f400;
    char f404[8];
    unsigned char f40c;
    char pad40d[3];
    BSStringT<char> f410;
    BSStringT<char> f418;
    unsigned int f420;
    unsigned int f424;
    unsigned char f428;
    char pad429[3];

    FUN_00470710(const char* ppath, const char* pfilename, NiFile::OpenMode accessmode);
};

// @fnv 0x00470710
FUN_00470710::FUN_00470710(const char* ppath, const char* pfilename, NiFile::OpenMode accessmode)
{
    f428 = 0;
    f29a = 0;
    f420 = 0;
    f424 = 0;
    f230 = 0;
    f234 = 0;
    f238 = 0;
    f004 = 0;
    f008 = 0;
    f299 = 0;
    f000 = 0;
    f260 = 0;
    f264 = 0;
    f268 = 0;
    f26c = 0;
    f3e8 = 0;
    f400 = 0;
    f00c = 0;
    f010 = 0;
    f3fc = 0;
    f40c = 0xFF;
    f23c = 0;
    f288 = 0;
    f28c = 0;
    f228 = 0;
    f22c = DAT_01186740;
    memset(&f240, 0, 0x18);
    memset(&f29c, 0, 0x140);
    memset(&f404, 0, 8);
    f25c = 0;
    f258 = 0;
    memset(&f3dc, 0, 0xC);
    f3e4 = 0x800;
    f3dc = DAT_01019dd4;
    if (!((TESFile*)this)->OpenTESFile(ppath, pfilename, accessmode, false))
        return;
    if ((f2b8 != 0 || f2bc != 0) && FUN_00471400(this) != 0)
        _FNV_Warning("MASTERFILE: File '%s' is not a valid TES file.", pfilename);
    if (!FUN_00471130(this))
        _FNV_Warning("MASTERFILE: Could not close file '%s'.", pfilename);
}

struct FUN_00470bc0_shell : public TESFile
{
    void ClearFileLists();
};

BSSimpleList<char*>* __fastcall FUN_00464df0(TESFile* pThis);

// @fnv 0x00470bc0
void FUN_00470bc0_shell::ClearFileLists()
{
    while (FUN_00464df0(this)->GetItem())
    {
        delete FUN_00464df0(this)->GetItem();
        FUN_00464df0(this)->RemoveHead();
    }
    while (GetMasterDataList()->GetItem())
    {
        delete GetMasterDataList()->GetItem();
        GetMasterDataList()->RemoveHead();
    }
    m_uiTESFileCount = 0;
}

struct FUN_00471130_shell : public TESFile
{
    bool FUN_00471130();
};

int __cdecl strcpy_s(char*, unsigned int, const char*);
int __cdecl strcat_s(char*, unsigned int, const char*);
char* __cdecl strchr(char*, int);
bool __fastcall FUN_004226e0(TESDataHandler*);
void __fastcall ProcessGroups(TESFile*);
void __fastcall FUN_00473960(TESFile*);
int __cdecl FUN_00aff0b0(const char*);
int __cdecl FUN_00ec862c(const char*, const char*);
void __cdecl FUN_00461300();
void __cdecl _FNV_Warning(const char*, ...);

struct VirtualDeletable
{
    virtual ~VirtualDeletable();
};

// @fnv 0x00471130
bool FUN_00471130_shell::FUN_00471130()
{
    if (!*(bool*)((char*)this + 0x29a) && g_dataHandler && !FUN_004226e0(g_dataHandler))
        return true;

    ProcessGroups(this);

    if (*(VirtualDeletable**)((char*)this + 0x10))
    {
        delete *(VirtualDeletable**)((char*)this + 0x10);
        *(VirtualDeletable**)((char*)this + 0x10) = 0;
    }

    FUN_00473960(this);

    if (*(VirtualDeletable**)((char*)this + 0xc))
    {
        char szFilename[260];
        char szTempname[260];
        char* pExt;

        strcpy_s(szFilename, 0x104, (char*)this + 0x124);
        strcat_s(szFilename, 0x104, (char*)this + 0x20);
        strcpy_s(szTempname, 0x104, (char*)this + 0x124);
        pExt = strchr((char*)this + 0x20, '.');
        if (pExt)
        {
            *pExt = 0;
            strcat_s(szTempname, 0x104, (char*)this + 0x20);
            strcat_s(szTempname, 0x104, ".tes");
            *pExt = '.';
        }
        else
        {
            strcat_s(szTempname, 0x104, (char*)this + 0x20);
            strcat_s(szTempname, 0x104, ".tes");
        }

        delete *(VirtualDeletable**)((char*)this + 0xc);
        *(VirtualDeletable**)((char*)this + 0xc) = 0;

        if (FUN_00aff0b0(szFilename))
        {
            FUN_00461300();
            *(int*)this = 9;
            _FNV_Warning(
                "MASTERFILE: Unable to complete operation due to failure removing previous file.\r\nPlugin '%s' may be locked or read only.\r\n\r\nTemp file '%s' contains saved data.",
                szFilename, szTempname);
            return false;
        }
        if (FUN_00ec862c(szTempname, szFilename))
        {
            FUN_00461300();
            *(int*)this = 9;
            _FNV_Warning(
                "MASTERFILE: Unable to complete operation due to failure renaming temp file.\r\nTemp file '%s' contains saved data.",
                szTempname);
            return false;
        }
    }

    return true;
}

struct FUN_00471820_shell : public TESFile
{
    void FUN_00471820(bool);
};

// @fnv 0x00471820
void FUN_00471820_shell::FUN_00471820(bool abVal)
{
    m_bIsLoading = abVal;
}

struct FUN_00471a10_shell : public TESFile
{
    TESFile* GetFileByIndex(unsigned int);
};

unsigned int __fastcall GetFieldAt3FC(TESFile* _this);

// Returns this for index 0, otherwise the TESFile* at index-1 in the array at offset 0x400, or null if index is out of range or the array is unset.
// @fnv 0x00471a10
TESFile* FUN_00471a10_shell::GetFileByIndex(unsigned int index)
{
    if (index < 0 || index > GetFieldAt3FC(this))
    {
        return 0;
    }
    if (index == 0)
    {
        return this;
    }
    if (!*(TESFile***)((char*)this + 0x400))
    {
        return 0;
    }
    return (*(TESFile***)((char*)this + 0x400))[index - 1];
}

struct FUN_00471ad0_shell : public TESFile
{
    unsigned int FUN_00471ad0();
};

unsigned int __fastcall GetFieldAt3FC(TESFile*);

// @fnv 0x00471ad0
unsigned int FUN_00471ad0_shell::FUN_00471ad0()
{
    return GetFieldAt3FC(this);
}

struct FUN_00471f80_shell : public TESFile
{
    void ResetFileState(bool);
};

void* __cdecl memset(void*, int, unsigned int);
extern int DAT_010a2480;

struct DummyVtbl
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void Seek(int, int);
};

// Seeks the stream to offset DAT_010a2480, zeroes the fields at 0x264-0x26c and the 0x18-byte block at 0x240, then calls GetTESForm if getform is set.
// @fnv 0x00471f80
void FUN_00471f80_shell::ResetFileState(bool getform)
{
    if (*(DummyVtbl**)((char*)this + 0x10) != 0)
    {
        (*(DummyVtbl**)((char*)this + 0x10))->Seek(0, DAT_010a2480);
    }
    *(unsigned int*)((char*)this + 0x264) = 0;
    *(unsigned int*)((char*)this + 0x268) = 0;
    *(unsigned int*)((char*)this + 0x26c) = 0;
    memset((char*)this + 0x240, 0, 0x18);
    if (getform)
    {
        GetTESForm();
    }
}

// Returns the value at offset 0x38 unless it is -1, in which case it returns the value at offset 0x150.
// @fnv 0x004720a0
int __fastcall FUN_004720a0(char* _this)
{
    return *(int*)(_this + 0x38) != -1 ? *(int*)(_this + 0x38) : *(int*)(_this + 0x150);
}

struct FUN_00472150_shell : public TESFile
{
    bool FUN_00472150(bool);
};

void __fastcall FUN_00473960(TESFile*);

// @fnv 0x00472150
bool FUN_00472150_shell::FUN_00472150(bool abSkipIgnored)
{
    FUN_00473960(this);
    bool bresult = HasNextForm();
    while (bresult && abSkipIgnored &&
           *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x240) != kGroupFormType &&
           *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x240) !=
               *reinterpret_cast<const unsigned int*>("TOFTQ") &&
           (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x248) & 0x1000))
    {
        bresult = HasNextForm();
    }
    return bresult;
}

// @fnv 0x00472380
int __fastcall FUN_00472380(int param_1)
{
    return *(int*)(param_1 + 0x150);
}

struct FUN_00472620_shell : public TESFile
{
    void FUN_00472620();
};

bool __fastcall ReadFormHeader(TESFile* _this);
void __fastcall ReadChunkHeader(TESFile* _this);

// If the file's field at offset 0x240 is zero, calls ReadFormHeader and, on success, clears the current chunk and calls ReadChunkHeader.
// @fnv 0x00472620
void FUN_00472620_shell::FUN_00472620()
{
    if (*(int*)((char*)this + 0x240) == 0)
    {
        if (!ReadFormHeader(this))
            return;
        ClearCurrentChunk();
        ReadChunkHeader(this);
    }
}

struct FUN_00472660_shell : public TESFile
{
    int FUN_00472660();
};

bool __fastcall ReadFormHeader(TESFile*);
int __cdecl FindFormEnumIndex(unsigned int);

// @fnv 0x00472660
int FUN_00472660_shell::FUN_00472660()
{
    if (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x240) == 0)
    {
        if (!ReadFormHeader(this))
        {
            return 0;
        }
        ClearCurrentChunk();
        GetChunkID();
    }
    return FindFormEnumIndex(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x240));
}

template <int> struct EndianSizeTag
{
};

void __cdecl BSEndian(unsigned short*, EndianSizeTag<2>);

struct FUN_00472840_impl : public TESFile
{
    using TESFile::GetChunkData;
    bool GetChunkData();
    bool ReadChunkData(unsigned short* value);
};

// Reads a 2-byte chunk into value, byte-swaps it if GetChunkData succeeds, and returns whether the read succeeded.
// @fnv 0x00472840
bool FUN_00472840_impl::ReadChunkData(unsigned short* value)
{
    bool ret = GetChunkData(value, 2);
    if (GetChunkData())
        BSEndian(value, EndianSizeTag<2>());
    return ret;
}

struct FUN_004731c0_shell : public TESFile
{
    void SetLanguage(int);
};

// @fnv 0x004731c0
void FUN_004731c0_shell::SetLanguage(int language)
{
    int iShiftedLanguage = language;
    iShiftedLanguage <<= 24;
    m_uiFileCount &= 0x00FFFFFF;
    m_uiFileCount |= iShiftedLanguage;
}

struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct CHUNK;
struct TESFileGroup;
struct HWND__;
struct NiColor;
struct NiPoint3;
struct TESBoundObject;
struct TESForm;
struct TESObjectREFR;
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
struct FUN_004734d0_shell : public TESFile
{
    bool FUN_004734d0(TESForm*);
};

extern unsigned int DAT_01187014;
struct FormEnumEntry
{
    unsigned int formID;
    unsigned int b;
    unsigned int c;
};
extern FormEnumEntry DAT_01187008[];

class TESFile_Helper
{
  public:
    void ResetFileState(bool);
    bool FUN_00472150(bool);
};

class BSThread
{
  public:
    bool FUN_008905f0();
};

class TESSound
{
  public:
    unsigned int Deallocate();
};

struct TESForm_vtbl
{
    char pad_00[0x7c];
    bool(__thiscall* vfunc_7c)(TESForm*, TESFile*);
    char pad_80[0x0c];
    unsigned int(__thiscall* vfunc_8c)(TESForm*);
    char pad_90[0x80];
    bool(__thiscall* vfunc_110)(TESForm*, void*, bool, bool);
};

// Seeks the file to apForm's form type and ID, skipping groups and other records, and returns true when the matching record is found.
// @fnv 0x004734d0
bool FUN_004734d0_shell::FUN_004734d0(TESForm* apForm)
{
    bool bretval = false;
    if (apForm && GetHasGroups() && *(BSThread**)((char*)this + 0x10) &&
        (*(BSThread**)((char*)this + 0x10))->FUN_008905f0())
    {
        if ((*(TESForm_vtbl**)apForm)->vfunc_7c(apForm, this))
        {
            return true;
        }
        ((TESFile_Helper*)this)->ResetFileState(true);
        while (*(unsigned int*)((char*)this + 0x240) == DAT_01187014)
        {
            ((TESFile_Helper*)this)->FUN_00472150(true);
        }
        unsigned int uiFormType = DAT_01187008[(*(TESForm_vtbl**)apForm)->vfunc_8c(apForm)].formID;
        unsigned int ifileformid = ((TESSound*)apForm)->Deallocate();
        bool bkeeplooking = true;
        while (*(unsigned int*)((char*)this + 0x240) != 0 && bkeeplooking)
        {
            if (*(unsigned int*)((char*)this + 0x240) == kGroupFormType)
            {
                if ((*(TESForm_vtbl**)apForm)->vfunc_110(apForm, (char*)this + 0x240, true, false))
                {
                    ((TESFile_Helper*)this)->FUN_00472150(true);
                }
                else
                {
                    IsGroupOpen();
                }
            }
            else if (*(unsigned int*)((char*)this + 0x240) == uiFormType &&
                     *(unsigned int*)((char*)this + 0x24c) == ifileformid)
            {
                bkeeplooking = false;
                bretval = true;
            }
            else
            {
                ((TESFile_Helper*)this)->FUN_00472150(true);
            }
        }
    }
    return bretval;
}

struct FUN_004738a0_shell : public TESFile
{
    bool CheckFileVersion();
};

unsigned int __cdecl SetWarningState(bool);
void __cdecl _FNV_Warning(const char*, ...);
int __cdecl _sprintf(char*, const char*, ...);

namespace fnv_anon_tesfile {}
using namespace fnv_anon_tesfile;
namespace fnv_anon_tesfile {
struct TESFile_GetFileVersion_Helper
{
    float GetFileVersion();
};
}

// Returns true and warns if the file version exceeds 1.34, otherwise returns false.
// @fnv 0x004738a0
bool FUN_004738a0_shell::CheckFileVersion()
{
    bool bretval = false;
    if (((TESFile_GetFileVersion_Helper*)this)->GetFileVersion() > 1.34f)
    {
        bretval = true;
        SetWarningState(false);
        char pMessage[260];
        _sprintf(pMessage, "File %s is a higher version than this EXE can load.", GetFilename());
        _FNV_Warning(pMessage);
        SetWarningState(true);
    }
    return bretval;
}

namespace fnv_00473ce0 {
extern int DAT_01186740;

// @fnv 0x00473ce0
void __fastcall SetField22C(char* pThis, float)
{
    *(int*)(pThis + 0x22c) = DAT_01186740;
}
}  // namespace fnv_00473ce0

extern NiTPointerMap<unsigned int, unsigned int>* DAT_011c40b0;
extern int DAT_011c40b4;
void* __fastcall FUN_004744d0(void*, int, unsigned int);

struct TempMap_00473f20
{
    int pad[4];
    TempMap_00473f20(unsigned int n)
    {
        FUN_004744d0(this, 0, n);
    }
};

// Creates the global ID-to-TESFile map if needed, maps aiID to apFile, and increments the counter when the file has no temp ID owner yet.
// @fnv 0x00473f20
void __cdecl RegisterTempFileID(unsigned int aiID, TESFile* apFile)
{
    if (!DAT_011c40b0)
    {
        DAT_011c40b0 = (NiTPointerMap<unsigned int, unsigned int>*)(new TempMap_00473f20(1001));
    }
    DAT_011c40b0->SetAt(aiID, (unsigned int)apFile);
    if (!apFile->GetTempIDOwner())
    {
        apFile->SetTempIDOwner(true);
        DAT_011c40b4 = DAT_011c40b4 + 1;
    }
}

extern int DAT_01031fac;

struct FUN_004744d0_arg
{
    unsigned int val;
};

void __fastcall FUN_005890c0(int* self, FUN_004744d0_arg a);

// Calls FUN_005890c0 on self, then stores the address of DAT_01031fac into *self and returns self.
// @fnv 0x004744d0
int* __fastcall FUN_004744d0(int* self, FUN_004744d0_arg a)
{
    FUN_005890c0(self, a);
    *self = (int)&DAT_01031fac;
    return self;
}

namespace fnv_0050f9c0 {
struct Actor;
struct BGSLoadFormBuffer;
struct SaveLoadFile;
struct CHUNK;
struct TESFileGroup;
struct HWND__;
struct NiColor;
struct ThreeByThreeMatrix;
struct NiPoint3;
struct NiQuaternion;
struct TESBoundObject;
struct TESForm;
struct TESObjectREFR;
struct hkVector4;
struct blob4
{
    char b[4];
};
struct blob8
{
    char b[8];
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
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct FUN_0050f9c0_shell : public BGSSaveFormBuffer
{
    void FUN_0050f9c0(TESForm*);
};

// @fnv 0x0050f9c0
void FUN_0050f9c0_shell::FUN_0050f9c0(TESForm* apForm)
{
    pForm = apForm;
}
}  // namespace fnv_0050f9c0

// @fnv 0x008905f0
bool __fastcall FUN_008905f0(bool* pFlags)
{
    return pFlags[0x2c];
}

struct List_009e03e0
{
    void RemoveAll();
};

struct TgtOps
{
    List_009e03e0* GetSourceFiles();
    void ClearSourceFiles();
};

// If GetSourceFiles returns a list, calls RemoveAll on it to clear the source files.
// @fnv 0x00460110
void TgtOps::ClearSourceFiles()
{
    if (this->GetSourceFiles())
        this->GetSourceFiles()->RemoveAll();
}

void __cdecl _Deallocate(void* p);

struct FUN_004709f0Class
{
    void __thiscall FUN_004709f0();
};

struct FUN_004601a0Class
{
    void* __thiscall DestroyIfFlagged(unsigned int flags);
};

// @fnv 0x004601a0
void* FUN_004601a0Class::DestroyIfFlagged(unsigned int flags)
{
    ((FUN_004709f0Class*)this)->FUN_004709f0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_00471850_Class
{
    unsigned int* __thiscall GetFieldAt3FC();
};

// @fnv 0x00471850
unsigned int* __thiscall FUN_00471850_Class::GetFieldAt3FC()
{
    return *(unsigned int**)((char*)this + 0x3fc);
}

extern int DAT_011c54d0;

struct FUN_00473080_Class
{
    int __thiscall GetGlobalValue();
};

// @fnv 0x00473080
int __thiscall FUN_00473080_Class::GetGlobalValue()
{
    return DAT_011c54d0;
}

struct FUN_004732f0_StandIn
{
    void* FUN_004732f0();
};

// @fnv 0x004732f0
void* FUN_004732f0_StandIn::FUN_004732f0()
{
    return reinterpret_cast<char*>(this) + 0x290;
}

struct FUN_00473880_Class
{
    unsigned char GetZeroByte();
};

// @fnv 0x00473880
unsigned char __thiscall FUN_00473880_Class::GetZeroByte()
{
    unsigned char v = 0;
    return v;
}

struct FUN_00473d00_Class
{
    char ReturnTrue(int, int);
};

// @fnv 0x00473d00
char __thiscall FUN_00473d00_Class::ReturnTrue(int a, int b)
{
    char c = 1;
    (void)a;
    (void)b;
    return c;
}

struct FUN_00474760_holder
{
    void __thiscall FUN_00474760();
};

struct FUN_00473f00_class
{
    void __thiscall ForwardToHolder();
};

// @fnv 0x00473f00
void __thiscall FUN_00473f00_class::ForwardToHolder()
{
    ((FUN_00474760_holder*)this)->FUN_00474760();
}

extern NiTPointerMap<unsigned int, unsigned int>* DAT_011c40b0;

struct DummyPointerMap
{
    bool GetAt(unsigned int, unsigned int&) const;
};

// Looks up aiID in DAT_011c40b0 and returns the mapped owner file value, or 0 if the map is null or the key is absent.
// @fnv 0x00474060
unsigned int __cdecl GetOwnerFileByID(unsigned int aiID)
{
    unsigned int uiOwnerFile = 0;
    if (DAT_011c40b0 && ((DummyPointerMap*)DAT_011c40b0)->GetAt(aiID, uiOwnerFile))
        return uiOwnerFile;
    return 0;
}

extern int DAT_01202c50;

// @fnv 0x00c3bb80
int* FUN_00c3bb80()
{
    return &DAT_01202c50;
}

extern void* DAT_011c54cc;

struct FUN_00473070Class
{
    void* __thiscall GetGlobalPointer();
};

// @fnv 0x00473070
void* __thiscall FUN_00473070Class::GetGlobalPointer()
{
    return DAT_011c54cc;
}

struct FUN_00473930_Class
{
    void* InflateCompressedForm();
    void* FUN_00473930();
};
// @fnv 0x00473930
void* FUN_00473930_Class::FUN_00473930()
{
    if (*(void**)((char*)this + 0x420) == 0)
        InflateCompressedForm();
    return *(void**)((char*)this + 0x420);
}

extern __int64 __cdecl FUN_00ec3bf0(__int64);
// Replaces the value at p with the result of FUN_00ec3bf0 applied to it.
// @fnv 0x004717f0
void __cdecl FUN_004717f0(__int64* pValue)
{
    __int64* q = pValue;
    *q = FUN_00ec3bf0(*q);
}

struct FUN_00471870_shell : public TESFile
{
    bool MatchMasterFiles(void*, bool);
};

struct FUN_00464df0_shell
{
    void* FUN_00464df0();
};
unsigned int __fastcall GetFieldAt3FC(TESFile*);
struct LItem_006815c0
{
    void** _ref_006815c0();
};
int _stricmp(const char*, const char*);
void _FNV_Warning(const char*, ...);

// Matches each required master filename against the file list, stores the matching TESFile pointers in the array at offset 0x400, and warns about missing masters.
// @fnv 0x00471870
bool FUN_00471870_shell::MatchMasterFiles(void* pFileList, bool showerror)
{
    BSSimpleList<TESFile*>* pFList;
    bool foundall;
    TESFile** pfile;
    unsigned int size;
    BSSimpleList<char*>* pMList;
    TESFile* pcheckfile;
    pFList = (BSSimpleList<TESFile*>*)pFileList;
    pMList = (BSSimpleList<char*>*)((FUN_00464df0_shell*)this)->FUN_00464df0();
    size = GetFieldAt3FC(this);
    if (*(TESFile***)((char*)this + 0x400))
        delete[] *(TESFile***)((char*)this + 0x400);
    *(TESFile***)((char*)this + 0x400) = 0;
    if (!size)
        return true;
    *(TESFile***)((char*)this + 0x400) = new TESFile*[size];
    pfile = *(TESFile***)((char*)this + 0x400);
    size = 0;
    foundall = true;
    while (pMList && *((LItem_006815c0*)pMList)->_ref_006815c0())
    {
        pFList = (BSSimpleList<TESFile*>*)pFileList;
        while (pFList && *((LItem_006815c0*)pFList)->_ref_006815c0())
        {
            pcheckfile = (TESFile*)*((LItem_006815c0*)pFList)->_ref_006815c0();
            if (!_stricmp((const char*)*((LItem_006815c0*)pMList)->_ref_006815c0(), pcheckfile->GetFilename()))
            {
                pfile[size] = pcheckfile;
                break;
            }
            pFList = pFList->GetNext();
            if (!pFList || !*((LItem_006815c0*)pFList)->_ref_006815c0())
            {
                pfile[size] = 0;
                if (showerror)
                    _FNV_Warning("MASTERFILE: Missing Masterfile: %s", *((LItem_006815c0*)pMList)->_ref_006815c0());
                foundall = false;
            }
        }
        size++;
        pMList = pMList->GetNext();
    }
    return foundall;
}

namespace fnv_00472bc0 {
struct FUN_00472bc0_shell : public TESFile
{
    bool ReadFormHeader();
};

struct BSFile
{
    unsigned int Read(void* buffer, unsigned int size);
};
struct MyForm
{
    void FUN_00470650();
};
struct TESFileAccessor
{
    bool GetChunkData();
};
struct FUN_00485d50_file
{
    TESFile* GetMasterFile(unsigned int index);
};
extern int DAT_00ffffff;
bool FUN_00484b40(unsigned int formID);
extern "C" void* __cdecl memset(void*, int, unsigned int);

struct FUN_00472bc0_view
{
    char pad0[0x10];
    BSFile* m_pFile;
    char pad14[0x240 - 0x14];
    unsigned int formType;
    unsigned int length;
    unsigned int flags;
    unsigned int formID;
    char pad250[0x400 - 0x250];
    TESFile** m_ppTESFiles;
    char pad404[0x8];
    unsigned char m_ucCompileIndex;
};

// @fnv 0x00472bc0
bool FUN_00472bc0_shell::ReadFormHeader()
{
    if (!((FUN_00472bc0_view*)this)->m_pFile)
        return false;
    bool bsuccess = true;
    if (((FUN_00472bc0_view*)this)->m_pFile->Read(&((FUN_00472bc0_view*)this)->formType, 0x18) != 0x18)
        bsuccess = false;
    if (!bsuccess)
    {
        memset(&((FUN_00472bc0_view*)this)->formType, 0, 0x18);
        return false;
    }
    if (((TESFileAccessor*)this)->GetChunkData())
        ((MyForm*)&((FUN_00472bc0_view*)this)->formType)->FUN_00470650();
    if (((FUN_00472bc0_view*)this)->formType != kGroupFormType &&
        ((FUN_00472bc0_view*)this)->formType != *(unsigned int*)"TOFTQ")
    {
        TESFile* pMaster = 0;
        if (((FUN_00472bc0_view*)this)->m_ppTESFiles)
            pMaster = ((FUN_00485d50_file*)this)->GetMasterFile((((FUN_00472bc0_view*)this)->formID >> 24) + 1);
        if (pMaster)
            ((FUN_00472bc0_view*)this)->formID = (pMaster->GetFileCompileIndex() << 24) |
                                                 (((FUN_00472bc0_view*)this)->formID & (unsigned int)&DAT_00ffffff);
        else
            ((FUN_00472bc0_view*)this)->formID = (((FUN_00472bc0_view*)this)->m_ucCompileIndex << 24) |
                                                 (((FUN_00472bc0_view*)this)->formID & (unsigned int)&DAT_00ffffff);
        if (FUN_00484b40(((FUN_00472bc0_view*)this)->formID & (unsigned int)&DAT_00ffffff))
            ((FUN_00472bc0_view*)this)->formID = ((FUN_00472bc0_view*)this)->formID & (unsigned int)&DAT_00ffffff;
    }
    return true;
}
}  // namespace fnv_00472bc0

namespace fnv_00472d30 {
struct FUN_00472d30_shell : public TESFile
{
    bool ReadChunkHeader();
};

template <int N> struct EndianSizeTag
{
};
void __cdecl BSEndian(unsigned char*, EndianSizeTag<1>);
void* __cdecl __memcpy(void*, const void*, unsigned int);
struct FUN_00472d30_CHUNK
{
    unsigned int id;
    unsigned short size;
    void FUN_004141e0();
};
struct TESFileExtra
{
    bool FUN_00401680();
};
struct FUN_00473930_Class
{
    void* FUN_00473930();
};
struct BaseProcess
{
    enum POSTANIM_ACTION
    {
        POSTANIM_NONE
    };
};
struct HighProcess
{
    BaseProcess::POSTANIM_ACTION GetPostAnimationAction();
};
struct BSFile
{
    unsigned int Read(void*, unsigned int);
};
// @fnv 0x00472d30
bool FUN_00472d30_shell::ReadChunkHeader()
{
    FUN_00472d30_CHUNK tempchunk;
    if (!IsCurrentFormCompressed())
    {
        if ((*(BSFile**)((char*)this + 0x10))->Read(&tempchunk, 6) != 6)
        {
            ClearCurrentChunk();
            return false;
        }
    }
    else
    {
        unsigned int ichunkoffset = *(unsigned int*)((char*)this + 0x268);
        char* pbuff = (char*)((FUN_00473930_Class*)this)->FUN_00473930();
        if (pbuff && ichunkoffset < ((HighProcess*)this)->GetPostAnimationAction())
        {
            pbuff += ichunkoffset;
            __memcpy(&tempchunk, pbuff, 6);
        }
        else
        {
            ClearCurrentChunk();
            return false;
        }
    }
    if (((TESFileExtra*)this)->FUN_00401680())
        tempchunk.FUN_004141e0();
    *(unsigned int*)((char*)this + 0x258) = tempchunk.id;
    *(unsigned int*)((char*)this + 0x25c) = tempchunk.size;
    if (tempchunk.id == 0x58585858)
    {
        unsigned int tempint = 0;
        GetChunkData(&tempint, 0);
        if (((TESFileExtra*)this)->FUN_00401680())
            BSEndian((unsigned char*)&tempint, EndianSizeTag<1>());
        NextChunk();
        *(unsigned int*)((char*)this + 0x25c) = tempint;
    }
    return true;
}
}  // namespace fnv_00472d30

extern "C" void* __cdecl _alloca(unsigned int);
struct BSStr
{
    bool Set(char const*, unsigned int);
};
struct S7010
{
    unsigned int Length();
};
extern BSStringT<char> g_menuParsedXML;
extern int DAT_011c5490;
struct FormTypeInfo
{
    unsigned char cType;
    char pad[11];
};
extern FormTypeInfo DAT_01187000[];
class TESForm
{
  public:
    TESFile* GetFile(int);
    int FNV_GetFormType();
};
struct Menu
{
    void* vtbl;
    unsigned int uiElapsedMilliseconds;
    void ParseMenuXML(char const*);
};
struct FUN_00482f40_t : Menu
{
    void FUN_00482f40(TESForm* apForm, unsigned int auiChunk);
};
// @fnv 0x00482f40
void FUN_00482f40_t::FUN_00482f40(TESForm* apForm, unsigned int auiChunk)
{
    unsigned char cType;
    bool bFound;
    if (!apForm)
        return;
    if (DAT_011c5490 == (int)this && ((S7010*)&g_menuParsedXML)->Length())
        return;
    DAT_011c5490 = (int)this;
    ((BSStr*)&g_menuParsedXML)->Set(0, 0);
    {
        TESFile* pFile = apForm->GetFile(-1);
        if (!pFile || !uiElapsedMilliseconds)
            return;
        pFile = pFile->GetParentTESFile();
        if (!pFile->SetOffset(uiElapsedMilliseconds))
            return;
        cType = pFile->GetTESForm();
        if (cType != DAT_01187000[apForm->FNV_GetFormType()].cType)
            return;
        bFound = false;
        do
        {
            unsigned int uiChunk = pFile->GetChunkID();
            if (uiChunk == auiChunk)
            {
                char* pBuf = (char*)_alloca(pFile->GetChunkSize());
                pFile->GetChunkData(pBuf, 0);
                ParseMenuXML(pBuf);
                bFound = true;
            }
        } while (!bFound && pFile->NextChunk());
    }
}

namespace fnv_00471400 {
struct _ULARGE_INTEGER
{
    unsigned long HighPart;
    unsigned long LowPart;
};
typedef char _sizecheck__ULARGE_INTEGER[sizeof(_ULARGE_INTEGER) == 8 ? 1 : -1];
struct FUN_00471400_shell : public TESFile
{
    int FUN_00471400();
};

extern "C" void* __cdecl _alloca(unsigned int);
template <int N> struct EndianSizeTag
{
};
void __cdecl FUN_004717f0(void*, EndianSizeTag<0>);
struct FUN_00470bc0_shell
{
    void ClearFileLists();
};
struct FUN_00464df0_shell
{
    void* FUN_00464df0();
};
struct FUN_00471820_shell
{
    void FUN_00471820(bool);
};
struct FUN_004731c0_shell
{
    void SetLanguage(int);
};
struct TESFile_Helper
{
    void ResetFileState(bool);
    bool FUN_00472150(bool);
};
struct CameraFileFormType
{
    int GetTESForm();
};
struct TESFileExtra
{
    bool FUN_00401680();
};
struct ContainerItemExtraFileData
{
    void Endian();
};
struct SoundListView
{
    void AddTail(char* const&);
};
struct BSStr
{
    bool Set(const char*, unsigned int);
};
struct BSFileVt
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
    virtual unsigned int GetSize();
};
extern unsigned int DAT_01187014;
extern int DAT_00ffffff;

// @fnv 0x00471400
int FUN_00471400_shell::FUN_00471400()
{
    unsigned char inexttype;

    ((FUN_00470bc0_shell*)this)->ClearFileLists();
    if (*(BSFileVt**)((char*)this + 0x10) == 0)
    {
        if (!OpenTESFile((char*)this + 0x124, (char*)this + 0x20, NiFile::READ_ONLY, false))
            return 2;
    }
    else
    {
        ((TESFile_Helper*)this)->ResetFileState(true);
    }
    *(unsigned int*)((char*)this + 0x260) = (*(BSFileVt**)((char*)this + 0x10))->GetSize();
    if (*(unsigned int*)((char*)this + 0x240) != DAT_01187014)
        return 0xb;

    do
    {
        switch (*(int*)((char*)this + 0x258))
        {
        case 0x52444548:
            GetChunkData((char*)this + 0x3dc, 0xc);
            if (((TESFileExtra*)this)->FUN_00401680())
                ((ContainerItemExtraFileData*)((char*)this + 0x3dc))->Endian();
            if (*(unsigned int*)((char*)this + 0x3e4) <= 0x7ff)
                *(unsigned int*)((char*)this + 0x3e4) = 0x800;
            *(unsigned int*)((char*)this + 0x3e4) =
                (*((unsigned char*)this + 0x40c) << 24) |
                (*(unsigned int*)((char*)this + 0x3e4) & (unsigned int)&DAT_00ffffff);
            break;
            break;
        case 0x4d414e43: {
            char* pMessage = (char*)_alloca(GetChunkSize());
            GetChunkData(pMessage, 0x200);
            ((BSStr*)((char*)this + 0x410))->Set(pMessage, 0);
        }
        break;
        case 0x4d414e53: {
            char* pMessage = (char*)_alloca(GetChunkSize());
            GetChunkData(pMessage, 0x200);
            ((BSStr*)((char*)this + 0x418))->Set(pMessage, 0);
        }
        break;
        case 0x5453414d: {
            unsigned int length = GetChunkSize();
            char* pfilename = new char[length];
            GetChunkData(pfilename, 0);
            ((SoundListView*)((FUN_00464df0_shell*)this)->FUN_00464df0())->AddTail(pfilename);
            (*(unsigned int*)((char*)this + 0x3fc))++;
        }
        break;
        case 0x41544144: {
            _ULARGE_INTEGER* plargeint = new _ULARGE_INTEGER;
            GetChunkData(plargeint, 8);
            if (((TESFileExtra*)this)->FUN_00401680())
                FUN_004717f0(plargeint, EndianSizeTag<0>());
            ((SoundListView*)GetMasterDataList())->AddTail(*(char**)&plargeint);
        }
        break;
        }
    } while (NextChunk());

    if (*(unsigned int*)((char*)this + 0x248) & 1)
        *(unsigned int*)((char*)this + 0x3e8) |= 1;
    else
        *(unsigned int*)((char*)this + 0x3e8) &= ~1;
    if (*(unsigned int*)((char*)this + 0x248) & 0x10)
        *(unsigned int*)((char*)this + 0x3e8) |= 0x10;
    else
        *(unsigned int*)((char*)this + 0x3e8) &= ~0x10;
    if (*(unsigned int*)((char*)this + 0x248) & 0x80)
        *(unsigned int*)((char*)this + 0x3e8) |= 0x80;
    else
        *(unsigned int*)((char*)this + 0x3e8) &= ~0x80;
    ((FUN_004731c0_shell*)this)->SetLanguage(*(unsigned int*)((char*)this + 0x3e8) >> 24);

    while (((CameraFileFormType*)this)->GetTESForm() == 1)
        ((TESFile_Helper*)this)->FUN_00472150(true);
    inexttype = ((CameraFileFormType*)this)->GetTESForm();
    ((FUN_00471820_shell*)this)->FUN_00471820(inexttype == 2 || inexttype == 0);
    ((TESFile_Helper*)this)->ResetFileState(true);
    return 0;
}
}  // namespace fnv_00471400

namespace fnv_004721d0 {
struct FUN_004721d0_shell : public TESFile
{
    bool FUN_004721d0();
};

extern "C" void* __cdecl memset(void*, int, unsigned int);
extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError();
extern "C" __declspec(dllimport) unsigned long __stdcall FormatMessageA(unsigned long, const void*, unsigned long,
                                                                        unsigned long, char*, unsigned long, char**);
extern "C" __declspec(dllimport) void* __stdcall LocalFree(void*);
extern int DAT_010a2480;
int __fastcall FUN_00472380(int);
void __cdecl _FNV_Warning(const char*, ...);
struct FUN_00472620_shell
{
    void FUN_00472620();
};
struct BSFileV
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void Seek(unsigned int, int);
};
struct FileFormHeader
{
    unsigned int type;
    unsigned int length;
    unsigned int flags;
    unsigned int formID;
    unsigned int stamp;
    unsigned int version;
};
struct FileChunkHeader
{
    unsigned int type;
    unsigned int size;
};
struct TESFileView
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    BSFileV* m_pFile;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    char m_acFilename[0x104];
    char m_acPath[0x104];
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    FileFormHeader m_kRecordInfo;
    FileChunkHeader m_currentchunk;
    unsigned int m_uiChunkOffset;
    unsigned int m_uiRecordSize;
    unsigned int m_uiRecordOffset;
    unsigned int m_uiCurrentOffset;
};
// @fnv 0x004721d0
bool FUN_004721d0_shell::FUN_004721d0()
{
    unsigned int currentoffset;
    currentoffset = ((TESFileView*)this)->m_uiRecordSize;
    if (((TESFileView*)this)->m_kRecordInfo.type == kGroupFormType ||
        ((TESFileView*)this)->m_kRecordInfo.type == *(unsigned int*)"TOFTQ")
        ((TESFileView*)this)->m_uiRecordSize += GetFORMSize();
    else
        ((TESFileView*)this)->m_uiRecordSize += GetFORMSize() + ((TESFileView*)this)->m_kRecordInfo.length;
    if (((TESFileView*)this)->m_uiRecordSize >= ((TESFileView*)this)->m_uiChunkOffset)
    {
        memset(&((TESFileView*)this)->m_kRecordInfo, 0, sizeof(FileFormHeader));
        return false;
    }
    currentoffset = ((TESFileView*)this)->m_uiRecordSize;
    if (FUN_00472380((int)((TESFileView*)this)->m_pFile) != currentoffset)
    {
        ((TESFileView*)this)->m_pFile->Seek(currentoffset, DAT_010a2480);
        ((TESFileView*)this)->m_uiRecordSize = FUN_00472380((int)((TESFileView*)this)->m_pFile);
    }
    if (((TESFileView*)this)->m_uiRecordSize == -1)
    {
        char* lpMsgBuf;
        FormatMessageA(0x1300, 0, GetLastError(), 0x400, (char*)&lpMsgBuf, 0, 0);
        _FNV_Warning("FORMS: SetFilePointer() in NextForm failed with error:\n%s", lpMsgBuf);
        LocalFree(lpMsgBuf);
        return false;
    }
    ((TESFileView*)this)->m_uiRecordOffset = 0;
    ((TESFileView*)this)->m_uiCurrentOffset = 0;
    memset(&((TESFileView*)this)->m_kRecordInfo, 0, sizeof(FileFormHeader));
    ((FUN_00472620_shell*)this)->FUN_00472620();
    if (((TESFileView*)this)->m_kRecordInfo.type == 0)
    {
        _FNV_Warning("MASTERFILE: Trying to load a bad form in TESFile::NextForm.\r\nFile = %s\r\nOffset = %d",
                     ((TESFileView*)this)->m_acFilename, ((TESFileView*)this)->m_uiRecordSize);
        return false;
    }
    return true;
}
}  // namespace fnv_004721d0

namespace fnv_00471a60 {
struct FUN_00464df0_shell
{
    void* FUN_00464df0();
};

struct FUN_00471a60 : FUN_00464df0_shell
{
    BGSPerk* GetPerk(unsigned int count);
};

// @fnv 0x00471a60
BGSPerk* FUN_00471a60::GetPerk(unsigned int count)
{
    BSSimpleList<BGSPerk*>* list = static_cast<BSSimpleList<BGSPerk*>*>(FUN_00464df0());
    if (list->GetItem() == 0)
        return 0;
    unsigned int index = 1;
    for (; index < count; index++)
    {
        list = static_cast<BSSimpleList<BGSPerk*>*>(list->GetNext());
        if (list == 0)
            return 0;
    }
    return list->GetItem();
}
}  // namespace fnv_00471a60

void* __cdecl operator new(unsigned int);
void __cdecl __memcpy(void* dst, const void* src, unsigned int size);
struct G2
{
    void AddHead(int*);
};

struct FUN_00473440_s
{
    int m_auiShapeKeys[0x290 / 4];
    G2 m_kGroupData;
    void AddGroupData(void* apGroupData);
};

// @fnv 0x00473440
void FUN_00473440_s::AddGroupData(void* apGroupData)
{
    if (apGroupData)
    {
        void* pgroup = operator new(0x1c);
        void* plocal = pgroup;
        m_kGroupData.AddHead(reinterpret_cast<int*>(&plocal));
        __memcpy(plocal, apGroupData, 0x18);
    }
}

struct FUN_004516b0_shell
{
    bool FUN_004516b0();
};
struct FUN_00473830_shell
{
    void* FUN_004732d0();
    void FUN_004733a0();
    void FreeIfPresent();
    void ProcessGroups();
};
// Loops over groups from FUN_004732d0, calling FUN_004733a0 or FreeIfPresent depending on g_dataHandler's FUN_004516b0 result.
// @fnv 0x00473830
void FUN_00473830_shell::ProcessGroups()
{
    void* pgroup = FUN_004732d0();
    while (pgroup)
    {
        if (reinterpret_cast<FUN_004516b0_shell*>(g_dataHandler)->FUN_004516b0())
            FUN_004733a0();
        else
            FreeIfPresent();
        pgroup = FUN_004732d0();
    }
}

int DAT_010a2480;
int __fastcall FUN_004720a0(char*);

struct FUN_00472000_interface
{
    virtual void Method0() = 0;
    virtual void Method1() = 0;
    virtual void Method2() = 0;
    virtual void Method3() = 0;
    virtual void Method4() = 0;
    virtual void Seek(unsigned int position, int origin) = 0;
};

struct FUN_00472000_class : public TESFile
{
    unsigned int SkipCurrentForm();
};

// Resets the form offset fields, seeks past the current form when it is not compressed, clears the current chunk and returns the chunk ID.
// @fnv 0x00472000
unsigned int FUN_00472000_class::SkipCurrentForm()
{
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x268) = 0;
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x26c) = 0;

    unsigned int position = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x268) +
                            (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x264) + GetFORMSize());

    if (!IsCurrentFormCompressed())
    {
        (*reinterpret_cast<FUN_00472000_interface**>(reinterpret_cast<char*>(this) + 0x10))
            ->Seek(position, DAT_010a2480);
        position = FUN_004720a0(*reinterpret_cast<char**>(reinterpret_cast<char*>(this) + 0x10));
    }

    ClearCurrentChunk();
    return GetChunkID();
}

namespace fnv_00472e60 {
struct ArrSI
{
    unsigned int GetFlags();
};

struct TESSound
{
    unsigned int Deallocate();
};

struct BSFile_Standin
{
    virtual int vfn_00();
    virtual int vfn_01();
    virtual int vfn_02();
    virtual int vfn_03();
    virtual int vfn_04();
    virtual int vfn_14(int, int);
};

struct FormTypeInfo
{
    unsigned int formID;
    unsigned int flags;
    unsigned int unknown;
};

extern FormTypeInfo g_FormTypes[];

unsigned int __fastcall _FNV_GetFormType(TESForm*);
int __cdecl FUN_00470bb0();
int __fastcall FUN_004720a0(char*);
extern int DAT_010a2488;

struct TESFile_Standin
{
    unsigned char _padding0[0x10];
    BSFile_Standin* m_pFile;
    unsigned char _padding1[0x25C];
    unsigned char m_kChunkInfo[0x18];

    int FUN_004736c0(TESForm*);
    int WriteToFile(void*, unsigned int);
    int FUN_00472e60(TESForm*);
};

// @fnv 0x00472e60
int __thiscall TESFile_Standin::FUN_00472e60(TESForm* apForm)
{
    this->FUN_004736c0(apForm);

    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x278) =
        reinterpret_cast<ArrSI*>(apForm)->GetFlags();
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x278) =
        *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x278) & 0x30032FE0;

    *reinterpret_cast<unsigned int*>(m_kChunkInfo) = g_FormTypes[_FNV_GetFormType(apForm)].formID;

    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x27C) =
        reinterpret_cast<TESSound*>(apForm)->Deallocate();

    *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(this) + 0x284) = FUN_00470bb0();
    *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(this) + 0x286) = 0;
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x280) = 0;
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x274) = 0;

    m_pFile->vfn_14(0, DAT_010a2488);

    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x288) =
        FUN_004720a0(reinterpret_cast<char*>(m_pFile));
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x28C) = 0;

    return this->WriteToFile(m_kChunkInfo, 0x18);
}
}  // namespace fnv_00472e60

struct FUN_004732d0
{
    char pad[0x290];
    BSSimpleList<BGSPerk*> list;

    BGSPerk* FUN_004732d0_impl();
};

// @fnv 0x004732d0
BGSPerk* FUN_004732d0::FUN_004732d0_impl()
{
    return list.GetItem();
}

namespace fnv_00473490 {
struct FUN_00473830_shell
{
    void* FUN_004732d0(void);
};

struct BSSimpleList_standin
{
    void FUN_0063f7b0(void);
};

void _Deallocate(void* p);

struct FUN_00473490_shell
{
    void FreeIfPresent(void);
};

// Calls FUN_004732d0 on this; if it returns non-null, calls FUN_0063f7b0 on the list at this+0x290 and deallocates the returned pointer.
// @fnv 0x00473490
void FUN_00473490_shell::FreeIfPresent(void)
{
    void* p = ((FUN_00473830_shell*)this)->FUN_004732d0();
    if (p)
    {
        ((BSSimpleList_standin*)((char*)this + 0x290))->FUN_0063f7b0();
        void* tmp = p;
        _Deallocate(tmp);
    }
}
}  // namespace fnv_00473490

struct FUN_00472f60_arg
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
    virtual void v128(int);
    void FUN_004f15a0(int);
    bool FUN_004077c0();
    void FUN_00403550(int);
    void FUN_00484f50(TESFile*);
};

struct FUN_00472f60_cls : public TESFile
{
    int FUN_00472660();
    int FUN_005224a0();
    int FUN_008d8ac0(int);
    void InitializeForm(FUN_00472f60_arg* p);
};

// @fnv 0x00472f60
void FUN_00472f60_cls::InitializeForm(FUN_00472f60_arg* apTarget)
{
    apTarget->FUN_004f15a0(FUN_00472660());
    if (apTarget->FUN_004077c0())
    {
        apTarget->FUN_00403550(FUN_005224a0() | 0x4000);
    }
    else
    {
        apTarget->FUN_00403550(FUN_005224a0());
    }
    apTarget->v128(FUN_008d8ac0(1));
    apTarget->FUN_00484f50(this);
}

// Layout of the object the function is a member of (fields at 0x14..0x3dc are padding).
struct Fun472Sub
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int v5(unsigned int a, int b);
};
struct Fun472Param
{
    void* Probe1();
    int Probe2();
    void Finish();
};
class FUN_00472fe0_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Fun472Sub* m_10;
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
    int m_3e0;
    int Helper4736c0(Fun472Param* p);
    int Helper110(void* a, int b);
    int RunProbe(Fun472Param* p);
};
extern int DAT_010a2488;
// @fnv 0x00472fe0
int FUN_00472fe0_cls::RunProbe(Fun472Param* apParam)
{
    int result;
    this->Helper4736c0(apParam);
    m_10->v5(0, DAT_010a2488);
    result = this->Helper110(apParam->Probe1(), apParam->Probe2());
    if (apParam->Probe1() && apParam->Probe2())
    {
        m_3e0++;
    }
    apParam->Finish();
    return result;
}

struct FUN_00473180_shell
{
    unsigned int __thiscall FUN_00473180(void* buffer, unsigned int size);
};

struct FUN_00473110_shell
{
    TES_RETURN_CODE m_eReturnCode;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FUN_00473180_shell* m_pFile;

    TES_RETURN_CODE __thiscall WriteToFile(void* buffer, unsigned int size);
};

unsigned int __thiscall FUN_00473180_shell::FUN_00473180(void* buffer, unsigned int size)
{
    return 0;
}

int* __cdecl FUN_00ec85e3();
void __cdecl FUN_005b5e40(const char* message);
extern const char DAT_0101a174[];

// @fnv 0x00473110
TES_RETURN_CODE __thiscall FUN_00473110_shell::WriteToFile(void* buffer, unsigned int size)
{
    if (buffer != 0)
    {
        if (m_pFile->FUN_00473180(buffer, size) < size)
        {
            int error = *FUN_00ec85e3();
            m_eReturnCode = TES_RETURN_CODE_TES_ERROR_WRITE_FAILURE;
            FUN_005b5e40(DAT_0101a174);
            return m_eReturnCode;
        }
    }

    m_eReturnCode = TES_RETURN_CODE_TES_ERROR_NONE;
    return m_eReturnCode;
}

// SpawnObject (thiscall, 1 stack arg)
class Holder_b4476
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05(int a, unsigned int b);
    unsigned int GetValue();
};

class SpawnedObject_b4476
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned int m_18;
};

extern unsigned int g_dat010a2488;

class FUN_00473310_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Holder_b4476* m_10;
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
    unsigned int m_3e0;

    void CalleeA(unsigned int a);
    SpawnedObject_b4476* CalleeB();
    void CalleeD(SpawnedObject_b4476* p, int n);
    void SpawnObject(unsigned int arg);
};

// If arg is non-zero, calls CalleeA(arg); when m_10 is set, spawns an object via CalleeB, copies m_10's value into its m_18, calls CalleeD, and increments m_3e0.
// @fnv 0x00473310
void FUN_00473310_cls::SpawnObject(unsigned int arg)
{
    if (arg != 0)
    {
        CalleeA(arg);
        if (m_10 != 0)
        {
            SpawnedObject_b4476* tmp = CalleeB();
            m_10->v05(0, g_dat010a2488);
            tmp->m_18 = m_10->GetValue();
            CalleeD(tmp, 0x18);
            m_3e0 = m_3e0 + 1;
        }
    }
}

extern int DAT_010a2480;
extern int DAT_010a2488;
int __fastcall FUN_004720a0(char* _this);

struct FUN_004733a0_vobj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int, int);
};

struct FUN_004733a0_rec
{
    int unk00;
    int m_04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int m_18;
};

struct FUN_004733a0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    FUN_004733a0_vobj* m_10;
    void* FUN_004732d0();
    void WriteToFile(FUN_004733a0_rec* rec, int n);
    void FreeIfPresent();
    void FUN_004733a0();
};

// @fnv 0x004733a0
void FUN_004733a0_cls::FUN_004733a0()
{
    FUN_004733a0_rec* x = (FUN_004733a0_rec*)FUN_004732d0();
    if (x != 0)
    {
        if (m_10 != 0)
        {
            m_10->v5(0, DAT_010a2488);
            x->m_04 = FUN_004720a0((char*)m_10) - x->m_18;
            m_10->v5(x->m_18, DAT_010a2480);
            WriteToFile(x, 0x18);
        }
        FreeIfPresent();
    }
}

extern unsigned int kGroupFormType;
void FNV_Warning(const char*, ...);

struct FormHeader
{
    unsigned int type;
    unsigned int length;
    unsigned int flags;
    unsigned int formID;
    unsigned int unk10;
    unsigned int unk14;
};

struct GroupForm;

struct GroupNode
{
    GroupForm** GetItem();
    GroupNode* GetNext();
};

struct LoadForm
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
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual bool IsInGroup(GroupForm* group, bool a, bool b);
    virtual void BuildGroupHeader(FormHeader* out, GroupForm* group);
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v4a();
    virtual void v4b();
    virtual const char* GetEditorID();

    int FNV_GetFormType();
    const char* GetTypeName();
    unsigned int GetFormIDValue();
};

struct GroupWriter
{
    GroupForm* GetCurrentGroup();
    GroupNode* GetGroupList();
    void CreateGroup(FormHeader* header);
    void CloseGroup();

    void FUN_004736c0(LoadForm* form);
};

// @fnv 0x004736c0
void GroupWriter::FUN_004736c0(LoadForm* form)
{
    if (form && form->FNV_GetFormType() != 1)
    {
        GroupForm* group = 0;
        GroupForm* last = 0;
        GroupNode* node2 = GetGroupList();
        while (node2)
        {
            group = *node2->GetItem();
            if (group && !form->IsInGroup(group, true, true))
            {
                last = group;
            }
            node2 = node2->GetNext();
        }
        if (last)
        {
            group = GetCurrentGroup();
            while (group)
            {
                CloseGroup();
                if (group == last)
                {
                    group = 0;
                }
                else
                {
                    group = GetCurrentGroup();
                }
            }
        }
        group = GetCurrentGroup();
        while (!group || !form->IsInGroup(group, false, true))
        {
            FormHeader header;
            form->BuildGroupHeader(&header, group);
            if (header.type == kGroupFormType)
            {
                CreateGroup(&header);
                group = GetCurrentGroup();
            }
            else
            {
                FNV_Warning("FORMS: Failed to CreateGroupData for %s form '%s' (%08X)", form->GetTypeName(),
                            form->GetEditorID(), form->GetFormIDValue());
                return;
            }
        }
    }
}

class FUN_00841250_ref;

class FUN_00841250_pair
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    FUN_00841250_pair* Build(FUN_00841250_ref* r, unsigned int v);
};

class FUN_00841250_guard
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    void Init();
};

class FUN_00841250_ref
{
  public:
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
    virtual bool v3c();
    void* Lookup();
    int Probe();
    bool Check();
};

class FUN_00841250_cls
{
  public:
    void Helper(int v);
    void Emit(void* p, FUN_00841250_pair v);
    void ProcessRef(FUN_00841250_ref* a1, void* a2, unsigned int a3);
};

// @fnv 0x00841250
void FUN_00841250_cls::ProcessRef(FUN_00841250_ref* apRef, void* apFallback, unsigned int auiValue)
{
    void* p = apRef ? apRef->Lookup() : apFallback;
    FUN_00841250_guard gTmp;
    gTmp.Init();
    FUN_00841250_pair pr;
    FUN_00841250_ref* r7;
    Emit(p, *pr.Build(apRef, auiValue));
    if (apRef == 0)
    {
        Helper(6);
    }
    else
    {
        if (apRef->v3c())
        {
            r7 = apRef;
            if (r7->Check())
            {
                Helper(2);
            }
            else
            {
                Helper(4);
            }
        }
        else
        {
            if (apRef->Probe() == 0x43)
            {
                Helper(4);
            }
        }
    }
}

struct FUN_00438fc0_file
{
    unsigned int FUN_004726b0();
    void GetChunkData(void*, unsigned int);
    bool FUN_00401680();
};

struct NiPoint3
{
    float x;
    float y;
    float z;
    unsigned char ReadFromFile(FUN_00438fc0_file* pFile);
};

void __cdecl FUN_00401080(float*, EndianSizeTag<4>);

// @fnv 0x00438fc0
unsigned char NiPoint3::ReadFromFile(FUN_00438fc0_file* pFile)
{
    char result = 0;
    if (pFile != 0)
    {
        if (pFile->FUN_004726b0() == 0x4f424d58)
        {
            pFile->GetChunkData(this, 12);
            if (pFile->FUN_00401680())
            {
                FUN_00401080(&x, EndianSizeTag<4>());
                FUN_00401080(&y, EndianSizeTag<4>());
                FUN_00401080(&z, EndianSizeTag<4>());
            }
            result = 1;
        }
    }
    return result;
}

class FUN_004709f0
{
  public:
    TES_RETURN_CODE m_eReturnCode;
    TESFile* m_pThreadSafeParent;
    NiTPointerMap<unsigned int, TESFile*>* m_pThreadSafeFileMap;
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
    FormRecordHeader m_kRecordInfo;
    CHUNK_ID m_eChunkID;
    unsigned int m_uiChunkSize;
    unsigned int m_uiChunkOffset;
    unsigned int m_uiRecordSize;
    unsigned int m_uiRecordOffset;
    unsigned int m_uiCurrentOffset;
    FormRecordHeader m_kChunkInfo;
    unsigned int m_uiChunkValue1;
    unsigned int m_uiChunkValue2;
    BSSimpleList<TESFileGroup*> m_kRecordList;
    bool m_bIsLoading;
    bool m_bIsSaving;
    bool m_bHasCurrentGroup;
    _WIN32_FIND_DATAA m_kFindData;
    TESFileHeader m_kFileMetadata;
    unsigned int m_uiFileCount;
    BSSimpleList<char*> m_kFilenameList;
    BSSimpleList<_ULARGE_INTEGER*> m_kFileSizeList;
    unsigned int m_uiTESFileCount;
    TESFile** m_ppTESFiles;
    _FILETIME m_kLastWriteTime;
    unsigned char m_ucCompileIndex;
    BSStringT<char> m_kCreator;
    BSStringT<char> m_kSummary;
    char* m_pDecompressedFormBuffer;
    unsigned int m_uiAuxBufferSize;
    bool m_bIsMaster;
    bool m_bOptimizedFile;
    bool m_bIsDLC;

    bool CloseTESFile();
    BSSimpleList<char*>* GetMasterList();
    BSSimpleList<_ULARGE_INTEGER*>* GetMasterDataList();
    void ReleaseA();
    void ReleaseB();
    ~FUN_004709f0();
};

// @fnv 0x004709f0
FUN_004709f0::~FUN_004709f0()
{
    m_bHasCurrentGroup = true;
    CloseTESFile();
    BSSimpleList<char*>* pMaster = GetMasterList();
    while (pMaster)
    {
        char* pName7 = pMaster->GetItem();
        if (pName7)
            delete pName7;
        pMaster = pMaster->GetNext();
    }
    GetMasterList()->RemoveAll();
    BSSimpleList<_ULARGE_INTEGER*>* pData8 = GetMasterDataList();
    while (pData8)
    {
        _ULARGE_INTEGER* pSize = pData8->GetItem();
        if (pSize)
            delete pSize;
        pData8 = pData8->GetNext();
    }
    GetMasterDataList()->RemoveAll();
    delete m_pBuffer;
    delete m_ppTESFiles;
    m_ppTESFiles = 0;
    ReleaseA();
    ReleaseB();
}

class _ULARGE_INTEGER
{
  public:
    unsigned int LowPart;
    unsigned int HighPart;
};

extern "C" __declspec(dllimport) void* __stdcall FindFirstFileA(const char* lpFileName,
                                                                _WIN32_FIND_DATAA* lpFindFileData);
extern "C" __declspec(dllimport) int __stdcall FindClose(void* hFindFile);
int __cdecl sprintf_s(char* buffer, unsigned int size, const char* format, ...);

struct FUN_00471af0_shell : public TESFile
{
    bool HasMasterFileChanged();
};

// @fnv 0x00471af0
bool FUN_00471af0_shell::HasMasterFileChanged()
{
    _ULARGE_INTEGER* pSize4;
    void* hFind6;
    BSSimpleList<char*>* pMasters = (BSSimpleList<char*>*)FUN_00464df0(this);
    BSSimpleList<_ULARGE_INTEGER*>* pMastersData = GetMasterDataList();
    bool bChanged_ = false;
    while (pMasters && pMasters->GetItem() && pMastersData && pMastersData->GetItem())
    {
        char filePathX[260];
        _WIN32_FIND_DATAA findData;
        sprintf_s(filePathX, 260, "%s", pMasters->GetItem());
        pSize4 = pMastersData->GetItem();
        hFind6 = FindFirstFileA(filePathX, &findData);
        if (hFind6 != (void*)-1)
        {
            FindClose(hFind6);
            if (findData.nFileSizeLow != pSize4->LowPart || findData.nFileSizeHigh != pSize4->HighPart)
                bChanged_ = true;
        }
        else if (pSize4->LowPart || pSize4->HighPart)
        {
            bChanged_ = true;
        }
        pMasters = pMasters->GetNext();
        pMastersData = pMastersData->GetNext();
    }
    return bChanged_;
}

struct BSFileCallVT
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14(int a, int b);
};

struct FUN_00473090_cls : public TESFile
{
    int Helper00473110(void* pForm, int size);
    int FUN_00473090();
};

// @fnv 0x00473090
int FUN_00473090_cls::FUN_00473090()
{
    m_kFileMetadata.m_uiFileRecordTotal++;
    m_kChunkInfo.length = m_uiChunkValue2;
    reinterpret_cast<BSFileCallVT*>(m_pFile)->v14(m_uiChunkValue1, DAT_010a2480);
    int result = Helper00473110(&m_kChunkInfo, 0x18);
    return result;
}

struct Probe_A
{
    bool __thiscall FUN_008256d0();
    void __thiscall FUN_0063f7b0();
};

struct Probe_B
{
    unsigned int* __thiscall FUN_006815c0();
};

// @fnv 0x00473270
void __cdecl FUN_00473270(void* pObject)
{
    while (!((Probe_A*)pObject)->FUN_008256d0())
    {
        void* r;
        unsigned int a = *((Probe_B*)pObject)->FUN_006815c0();
        unsigned int b = a;
        unsigned int c2 = b;
        if (c2 != 0)
        {
            r = ((FUN_004601a0Class*)c2)->DestroyIfFlagged(1);
        }
        else
        {
            r = 0;
        }
        ((Probe_A*)pObject)->FUN_0063f7b0();
    }
}

typedef void* NiTMapIterator473;

class Value473
{
  public:
    ~Value473();
    void Cleanup();
};

class Map473
{
  public:
    virtual ~Map473();
    NiTMapIterator473 GetFirstPos();
    void GetNext(NiTMapIterator473& pos, unsigned int& uiKey, Value473*& pkValue);
    void RemoveAll();
};

class Owner473
{
  public:
    void DestroyMap();

    int unk00;
    int unk04;
    Map473* m_pTaskMap;
};

// Iterates the map, calls Cleanup and deletes each value, then removes all entries, deletes the map and nulls the pointer.
// @fnv 0x00473a10
void Owner473::DestroyMap()
{
    if (m_pTaskMap)
    {
        NiTMapIterator473 kPos = m_pTaskMap->GetFirstPos();
        while (kPos)
        {
            unsigned int uiKey = 0;
            Value473* pkValue = 0;
            m_pTaskMap->GetNext(kPos, uiKey, pkValue);
            pkValue->Cleanup();
            delete pkValue;
        }
        m_pTaskMap->RemoveAll();
        delete m_pTaskMap;
        m_pTaskMap = 0;
    }
}

struct TempKeys
{
    void* table;
    unsigned int* data;
    unsigned short capacity, size, count, grow;
    TempKeys(unsigned int, unsigned int);
    ~TempKeys();
    void SetAt(unsigned int, unsigned int&);
    unsigned int& GetAt(unsigned int);
};
struct MapView
{
    virtual ~MapView();
    void RemoveAll();
    void* GetFirstPos();
    void GetNext(void*&, unsigned int&, TESFile*&);
    bool RemoveAt(unsigned int);
};
struct FileOwner : TESFile
{
    void ReleaseTempIDOwner();
};
// Clears the temp-ID owner flag; when the last owner is released it frees the map, otherwise it collects and removes this file's entries from it.
// @fnv 0x00473d90
void FileOwner::ReleaseTempIDOwner()
{
    if (GetTempIDOwner())
    {
        SetTempIDOwner(false);
        if (--DAT_011c40b4 == 0)
        {
            ((MapView*)DAT_011c40b0)->RemoveAll();
            delete (MapView*)DAT_011c40b0;
            DAT_011c40b0 = 0;
        }
        else
        {
            TempKeys position(100, 100);
            unsigned int keys = 0;
            void* count = ((MapView*)DAT_011c40b0)->GetFirstPos();
            while (count)
            {
                TESFile* key = 0;
                unsigned int owner = 0;
                ((MapView*)DAT_011c40b0)->GetNext(count, owner, key);
                if (key == this)
                {
                    position.SetAt(keys, owner);
                    keys = keys + 1;
                }
            }
            for (unsigned int i = 0; i < keys; ++i)
            {
                unsigned int owner = position.GetAt(i);
                ((MapView*)DAT_011c40b0)->RemoveAt(owner);
            }
        }
    }
}

namespace fnv_004740a0 {
struct AutoMemX
{
    int m;
    AutoMemX(int a, int b, const char* f, int l);
    ~AutoMemX();
};
struct TagX
{
};
void FUN_00401080(void* p, TagX t);
void* FormHeap_Allocate(unsigned int n);
void FormHeap_Free(void* p);
bool FindFormEnumIndex(int id);
void FUN_005b5e40(const char* fmt, ...);
extern int g_iDat01187020;
void* AllocateProduct(void* opaque, unsigned int items, unsigned int size);
void FUN_00474480(void* opaque, void* p);
struct ZStreamX
{
    char* m_pNextInputByte;
    unsigned int m_uiAvailableInputBytes;
    unsigned long m_ulTotalInputBytes;
    char* m_pNextOutputByte;
    unsigned int m_uiAvailableOutputBytes;
    unsigned long m_ulTotalOutputBytes;
    char* msg;
    void* state;
    void* (*m_pAllocateCallback)(void*, unsigned int, unsigned int);
    void (*m_pFreeCallback)(void*, void*);
    void* opaque;
    int data_type;
    unsigned long m_ulAdler32Checksum;
    unsigned long reserved;
};
int FUN_00b43fe0(ZStreamX* s, const char* ver, int size);
int FUN_00b44000(ZStreamX* s, int flush);
int FUN_00b45db0(ZStreamX* s);
struct FileX
{
    unsigned int FUN_00b00650(void* p, unsigned int n);
};
class SelfX
{
  public:
    char pad[0x10];
    FileX* m10;
    char pad2[0x240 - 0x14];
    int m240;
    unsigned int m244;
    char pad3[0x420 - 0x248];
    char* m420;
    unsigned int m424;
    bool FUN_00472100();
    bool FUN_00401680();
    void FUN_00473960();
    void InflateCompressedForm();
};
// Reads a compressed form buffer from m10, inflates it with ZLib into m420, and frees the source buffer on success or failure.
// @fnv 0x004740a0
void SelfX::InflateCompressedForm()
{
    AutoMemX kMem(0x30, 1, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESFile.cpp", 0xf8e);
    if (m244 && m240 != g_iDat01187020 && FUN_00472100())
    {
        bool bOk = FindFormEnumIndex(m240);
        if (!bOk)
            return;
        char* pBufferVal = (char*)FormHeap_Allocate(m244 + 1);
        if (!pBufferVal)
            return;
        if (m10->FUN_00b00650(pBufferVal, m244) != m244)
        {
            FUN_005b5e40("TESFile: Failed to read in buffer data for compressed form.");
        }
        else
        {
            unsigned int uiSize7 = *(unsigned int*)pBufferVal;
            char* pData4 = pBufferVal + 4;
            if (FUN_00401680())
                FUN_00401080(&uiSize7, TagX());
            pBufferVal[m244] = 0;
            m420 = (char*)FormHeap_Allocate(uiSize7);
            m424 = uiSize7;
            ZStreamX kStream;
            char acState[0x1ba4];
            kStream.m_pAllocateCallback = AllocateProduct;
            kStream.m_pFreeCallback = FUN_00474480;
            kStream.opaque = 0;
            kStream.m_uiAvailableInputBytes = 0;
            kStream.m_pNextInputByte = 0;
            kStream.state = acState;
            int iRet6 = FUN_00b43fe0(&kStream, "1.2.1", 0x38);
            if (iRet6)
            {
                FUN_00b45db0(&kStream);
                FUN_005b5e40("TESFile: Error initializing ZLib inflate stream.");
                FUN_00473960();
                FormHeap_Free(pBufferVal);
                return;
            }
            kStream.m_uiAvailableInputBytes = m244 - 4;
            kStream.m_pNextInputByte = pData4;
            kStream.m_uiAvailableOutputBytes = uiSize7;
            kStream.m_pNextOutputByte = m420;
            iRet6 = FUN_00b44000(&kStream, 0);
            if (iRet6 == -2 || iRet6 == 2 || iRet6 == -3 || iRet6 == -4)
            {
                FUN_00b45db0(&kStream);
                FUN_005b5e40("TESFile: Error inflating ZLib stream.");
                FUN_00473960();
                FormHeap_Free(pBufferVal);
                return;
            }
            if (iRet6 != 1)
            {
                FUN_00b45db0(&kStream);
                FUN_005b5e40("TESFile: Error: ZLib stream did not terminate.");
                FUN_00473960();
                FormHeap_Free(pBufferVal);
                return;
            }
            FUN_00b45db0(&kStream);
        }
        FormHeap_Free(pBufferVal);
    }
}
}  // namespace fnv_004740a0

namespace fnv_00472890 {
extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError();
extern "C" __declspec(dllimport) unsigned long __stdcall FormatMessageA(unsigned long, const void*, unsigned long,
                                                                        unsigned long, char*, unsigned long, void*);
extern "C" __declspec(dllimport) void* __stdcall LocalFree(void*);
void FUN_005b5e40(const char*, ...);
void* FUN_00401460(void*, const void*, unsigned int);
extern unsigned int DAT_010a2480;

struct ChunkFile
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void Seek(unsigned int, unsigned int);
    unsigned int FUN_00b00650(void*, unsigned int);
};

struct FUN_00472890_cls : TESFile
{
    bool FUN_00472100();
    unsigned int FUN_00471840();
    char* FUN_00473930();
    bool GetChunkData(char* data, unsigned int size);
};

// Reads the current chunk into data, seeking the file or copying from compressed memory, and truncates with a warning if the buffer is too small.
// @fnv 0x00472890
bool FUN_00472890_cls::GetChunkData(char* data, unsigned int size)
{
    if (m_uiChunkSize == 0)
        return true;
    bool compressed = FUN_00472100();
    if (m_uiCurrentOffset > 0)
    {
        if (!compressed)
        {
            unsigned int offset = m_uiRecordSize + FUN_00471840() + m_uiRecordOffset + 6;
            ((ChunkFile*)m_pFile)->Seek(offset, DAT_010a2480);
        }
        m_uiCurrentOffset = 0;
    }
    if (size != 0 && m_uiChunkSize > size)
    {
        data[size - 1] = 0;
        if (!compressed)
        {
            m_uiCurrentOffset = ((ChunkFile*)m_pFile)->FUN_00b00650(data, size - 1);
            if (m_uiCurrentOffset != size - 1)
            {
                char* message;
                FormatMessageA(0x1300, 0, GetLastError(), 0x400, (char*)&message, 0, 0);
                FUN_005b5e40("MASTERFILE: First ReadFile() in GetChunkData failed with error:\n%s", message);
                LocalFree(message);
                return false;
            }
        }
        else
        {
            unsigned int offset = m_uiRecordOffset + 6;
            char* source = FUN_00473930() + offset;
            FUN_00401460(data, source, size - 1);
            m_uiCurrentOffset = size - 1;
        }
        char b[5];
        char a[5];
        b[0] = (char)(m_eChunkID & 0xff);
        b[1] = (char)((m_eChunkID & 0xff00) >> 8);
        b[2] = (char)((m_eChunkID & 0xff0000) >> 16);
        b[3] = (char)((m_eChunkID & 0xff000000) >> 24);
        b[4] = 0;
        a[0] = (char)(m_kRecordInfo.form & 0xff);
        a[1] = (char)((m_kRecordInfo.form & 0xff00) >> 8);
        a[2] = (char)((m_kRecordInfo.form & 0xff0000) >> 16);
        a[3] = (char)((m_kRecordInfo.form & 0xff000000) >> 24);
        a[4] = 0;
        FUN_005b5e40(
            "FORMS: Chunk size %d too big in chunk %s_ID in form %s_ID (%08X).\r\nMax size is %d, data truncated to \"%s\".\r\n",
            m_uiChunkSize, b, a, m_kRecordInfo.iFormID, size, data);
    }
    else
    {
        if (!compressed)
        {
            m_uiCurrentOffset = ((ChunkFile*)m_pFile)->FUN_00b00650(data, m_uiChunkSize);
            if (m_uiCurrentOffset != m_uiChunkSize)
            {
                char* message;
                FormatMessageA(0x1300, 0, GetLastError(), 0x400, (char*)&message, 0, 0);
                FUN_005b5e40("MASTERFILE: Second ReadFile() in GetChunkData failed with error:\n%s", message);
                LocalFree(message);
                return false;
            }
        }
        else
        {
            unsigned int offset = m_uiRecordOffset + 6;
            char* source = FUN_00473930() + offset;
            FUN_00401460(data, source, m_uiChunkSize);
            m_uiCurrentOffset = m_uiChunkSize;
        }
    }
    return true;
}
}  // namespace fnv_00472890

class B473180Stream
{
  public:
    unsigned int CallAndAccumulate(void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes,
                                   unsigned int uiNumComponents);
    unsigned int FUN_00473180(void* pvBuffer, unsigned int uiBytes);
};

// Read raw bytes (component size 1)
// Reads uiBytes into pvBuffer via CallAndAccumulate with a single 1-byte element size and returns the number of bytes read.
// @fnv 0x00473180
unsigned int B473180Stream::FUN_00473180(void* pvBuffer, unsigned int uiBytes)
{
    unsigned int uiElemSize = 1;
    unsigned int uiRead = CallAndAccumulate(pvBuffer, uiBytes, &uiElemSize, 1);
    return uiRead;
}

extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError();
extern "C" __declspec(dllimport) unsigned long __stdcall FormatMessageA(unsigned long, const void*, unsigned long,
                                                                        unsigned long, char*, unsigned long, void*);
extern "C" __declspec(dllimport) void* __stdcall LocalFree(void*);

struct TESOffsetWorker : public TESFile
{
    bool FUN_004723a0(unsigned int);
};

void* __cdecl memset(void*, int, unsigned int);
int __fastcall FUN_004720a0(char*);
void _FNV_Warning(const char*, ...);
extern int DAT_010a2480;
void __fastcall FUN_00473960(TESFile*);
struct SeekFile
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void Seek(unsigned int, int);
};

// Sets the record offset, seeks there when valid, reads a size, and resets record state on the invalid-offset and success paths.
// @fnv 0x004723a0
bool TESOffsetWorker::FUN_004723a0(unsigned int newoffset)
{
    unsigned int currentoffset;
    FUN_00473960(this);
    m_uiRecordSize = newoffset;
    if (m_uiRecordSize >= m_uiChunkOffset)
    {
        memset(&m_kRecordInfo, 0, 0x18);
        return false;
    }
    currentoffset = m_uiRecordSize;
    ((SeekFile*)m_pFile)->Seek(currentoffset, DAT_010a2480);
    m_uiRecordSize = FUN_004720a0((char*)m_pFile);
    if (m_uiRecordSize == 0xFFFFFFFF)
    {
        char* lpMsgBuf;
        FormatMessageA(0x1300, 0, GetLastError(), 0x400, (char*)&lpMsgBuf, 0, 0);
        _FNV_Warning("MASTERFILE: SetFilePointer() in SetOffset failed with error:\n%s", lpMsgBuf);
        LocalFree(lpMsgBuf);
        return false;
    }
    m_uiRecordOffset = 0;
    m_uiCurrentOffset = 0;
    memset(&m_kRecordInfo, 0, 0x18);
    GetTESForm();
    return true;
}

struct ChunkOffsetFile : public TESFile
{
    bool FUN_004724f0(unsigned int);
};

struct VFile
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void Seek(unsigned int, int);
};

// For an uncompressed form, checks the computed record offset, seeks to newoffset when valid, and reloads current chunk state on success.
// @fnv 0x004724f0
bool ChunkOffsetFile::FUN_004724f0(unsigned int newoffset)
{
    unsigned int currentoffset;
    if (IsCurrentFormCompressed())
    {
        ::_FNV_Warning("FORMS: SetOffsetChunk failed for compressed form.");
        return false;
    }
    m_uiRecordOffset = newoffset - m_uiRecordSize - GetFORMSize();
    if (m_uiRecordOffset >= m_kRecordInfo.length)
    {
        ClearCurrentChunk();
        ::memset(&m_kRecordInfo, 0, sizeof(m_kRecordInfo));
        return false;
    }
    currentoffset = newoffset;
    ((VFile*)m_pFile)->Seek(currentoffset, ::DAT_010a2480);
    currentoffset = ::FUN_004720a0((char*)m_pFile);
    if (currentoffset == -1)
    {
        char* lpMsgBuf;
        ::FormatMessageA(0x1300, 0, ::GetLastError(), 0x400, (char*)&lpMsgBuf, 0, 0);
        ::_FNV_Warning("FORMS: SetFilePointer() in SetOffsetChunk failed with error:\n%s", lpMsgBuf);
        ::LocalFree(lpMsgBuf);
        return false;
    }
    m_uiCurrentOffset = 0;
    ClearCurrentChunk();
    GetChunkID();
    return true;
}
