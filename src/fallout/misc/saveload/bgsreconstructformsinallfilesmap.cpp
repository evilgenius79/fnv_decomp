
#include "bgsreconstructformsinallfilesmap_decls.h"

// Empty destructor for the reconstruct-forms-in-all-files map object.
// @fnv 0x00843540
FormChangeMap::~FormChangeMap()
{}

// @fnv 0x008455b0
BGSSaveLoadChangesMap::~BGSSaveLoadChangesMap()
{
    Clear();
}

// @fnv 0x008434d0
BGSReconstructFormsInAllFilesMap::~BGSReconstructFormsInAllFilesMap()
{
    Clear();
}

// @fnv 0x008433d0
BGSReconstructFormsInAllFilesMap::BGSReconstructFormsInAllFilesMap()
    : BGSReconstructFormsInAllFilesMapBase(0x25), m_kFormChangeMap(), iCount(0)
{}

// @fnv 0x008439e0
void BGSReconstructFormsInAllFilesMap::BuildMap()
{
    struct LocalState
    {
        ChangedFormRecord* reconstructForm;
        unsigned int reconstructIndex;
        ChangedFormRecord* initializeForm;
        unsigned int initializeIndex;
        TESForm* form;
        ChangedFormRecord* removedForm;
        unsigned int removeIndex;
        TESFile* threadSafeFile;
        BGSReconstructFormsInFileMap* map;
        TESFile* file;
        unsigned char padding0;
        unsigned char padding1;
        unsigned char padding2;
        bool wasLocked;
        unsigned int size;
        void* position;
    } state;

    g_BGSSaveLoadGame->SetFlag4(true);
    m_kFormChangeMap.FUN_00843be0(iCount);
    state.wasLocked = g_dataHandler->FUN_004516b0();
    g_dataHandler->SetBoolAt61a(true);

    state.position = GetFirstPos();
    while (state.position)
    {
        state.file = 0;
        state.map = 0;
        GetNext(state.position, state.file, state.map);
        state.threadSafeFile = state.file->GetParentTESFile();
        state.map->BuildMap(state.threadSafeFile, &m_kFormChangeMap);
    }

    g_dataHandler->SetBoolAt61a(state.wasLocked);

    state.removeIndex = 0;
    for (; state.removeIndex < m_kFormChangeMap.GetCombinedFlags(); ++state.removeIndex)
    {
        state.removedForm = m_kFormChangeMap.FUN_008432e0(state.removeIndex);
        if (state.removedForm->pForm->GetIsReference())
        {
            state.form = state.removedForm->pForm;
            if (!reinterpret_cast<TESObjectREFR*>(state.form)->GetObjectReference())
            {
                m_kFormChangeMap.RemoveForm(state.removeIndex);
                --state.removeIndex;
            }
        }
    }

    state.size = m_kFormChangeMap.GetCombinedFlags();
    state.initializeIndex = 0;
    for (; state.initializeIndex < state.size; ++state.initializeIndex)
    {
        state.initializeForm = m_kFormChangeMap.FUN_008432e0(state.initializeIndex);
        if (!reinterpret_cast<TESFormInitFlag*>(state.initializeForm->pForm)->IsFormInitialized())
            state.initializeForm->pForm->InitItem();
    }

    state.reconstructIndex = 0;
    for (; state.reconstructIndex < state.size; ++state.reconstructIndex)
    {
        state.reconstructForm = m_kFormChangeMap.FUN_008432e0(state.reconstructIndex);
        AddFormFlagEntry(state.reconstructForm);
    }

    g_BGSSaveLoadGame->SetFlag4(false);
}

// Deletes every file map returned by GetNext, then clears the pointer map, calls FUN_00843240 and resets iCount to 0.
// @fnv 0x008435a0
void BGSReconstructFormsInAllFilesMap::Clear()
{
    void* position = GetFirstPos();
    while (position)
    {
        TESFile* file = 0;
        BGSReconstructFormsInFileMap* map = 0;
        GetNext(position, file, map);
        delete map;
    }
    reinterpret_cast<NiTPointerMap<unsigned int, unsigned int>*>(this)->RemoveAll();
    m_kFormChangeMap.FUN_00843240();
    iCount = 0;
}

struct S3240
{
    char pad[0x10];
    void Resize(int, int);
    void FUN_00843240();
};
// Calls Resize(0, 1) on this and on the object at offset 0x10.
// @fnv 0x00843240
void S3240::FUN_00843240()
{
    Resize(0, 1);
    reinterpret_cast<S3240*>(reinterpret_cast<char*>(this) + 0x10)->Resize(0, 1);
}

struct FUN_00843bb0_shell : public FormChangeMap
{
    unsigned int GetCombinedFlags();
};

struct TESObjectREFR_GetFlags_caller : public TESObjectREFR
{
    unsigned int CallGetFlags();
};

// Returns the sum of the flags from the TESObjectREFR at offset 0x0 and the one at offset 0x10.
// @fnv 0x00843bb0
unsigned int FUN_00843bb0_shell::GetCombinedFlags()
{
    return ((TESObjectREFR_GetFlags_caller*)((char*)this + 0x0))->CallGetFlags() +
           ((TESObjectREFR_GetFlags_caller*)((char*)this + 0x10))->CallGetFlags();
}

extern int DAT_01031fac;

struct FUN_00844130_arg
{
    unsigned int val;
};

void __fastcall FUN_005890c0(int* self, FUN_00844130_arg a);

// Calls FUN_005890c0 on self, then stores the address of DAT_01031fac into *self and returns self.
// @fnv 0x00844130
int* __fastcall FUN_00844130(int* self, FUN_00844130_arg a)
{
    FUN_005890c0(self, a);
    *self = (int)&DAT_01031fac;
    return self;
}

extern int DAT_0107ed08;

class SaveGameSizeState
{
  public:
    void RecordRequestedSize(unsigned int, unsigned int);
};

// @fnv 0x00844a90
void* __fastcall SaveGameSizeStateConstructor(void* pThis)
{
    *reinterpret_cast<int**>(pThis) = &DAT_0107ed08;
    reinterpret_cast<SaveGameSizeState*>(pThis)->RecordRequestedSize(0, 0);
    return pThis;
}

class GlobalObject_00869f00
{
  public:
    void Clear(bool);
};

extern int DAT_0107ed08;

// @fnv 0x00844ac0
void __fastcall FUN_00844ac0(GlobalObject_00869f00* _this)
{
    *(int**)_this = &DAT_0107ed08;
    _this->Clear(true);
}

void __fastcall DeleteAllEntries(void*);

struct FUN_009a5df0
{
    virtual void dummy();
    ~FUN_009a5df0();
};

struct FUN_00844e20 : FUN_009a5df0
{
    ~FUN_00844e20();
};

// Destructor that forwards to DeleteAllEntries with this as the argument.
// @fnv 0x00844e20
FUN_00844e20::~FUN_00844e20()
{
    DeleteAllEntries(this);
}

struct ScrapHeapBuffer
{
    void* Allocate(unsigned int, unsigned int);
};
extern unsigned int DAT_010a2720;
struct OffsetData
{
    unsigned int iOffset;
    void* m_pFormLookupMap;
};
struct FUN_006db9b0_s
{
    char pad[0x10];
    ScrapHeapBuffer* m_pAllocator;
    OffsetData* AllocateOffsetData(unsigned int aiSizeInItem);
};
// @fnv 0x006db9b0
OffsetData* FUN_006db9b0_s::AllocateOffsetData(unsigned int aiSizeInItem)
{
    OffsetData* pnewBuffer;
    pnewBuffer = (OffsetData*)m_pAllocator->Allocate(aiSizeInItem * 8, DAT_010a2720);
    return pnewBuffer;
}

struct FUN_00841320_shell
{
    void __thiscall FUN_00841320(int arg);
};

// @fnv 0x00841320
void __thiscall FUN_00841320_shell::FUN_00841320(int arg)
{
    *(int*)((char*)this + 0x10) |= arg;
}

struct FUN_00844070_standin
{
    void FUN_00844070(int);
};

struct FUN_00842180 : FUN_00844070_standin
{
    void* vtable;
    unsigned int field_04;
    unsigned int field_08;
    unsigned int field_0C;
    void* field_10;
    void* field_14;
    unsigned int field_18;

    FUN_00842180();
};

extern void* DAT_0107e9d0;

// Calls the base constructor with 0x25, installs the vtable, and zeroes fields at offsets 0x10, 0x14 and 0x18.
// @fnv 0x00842180
FUN_00842180::FUN_00842180()
{
    FUN_00844070_standin::FUN_00844070(0x25);
    vtable = &DAT_0107e9d0;
    field_10 = 0;
    field_14 = 0;
    field_18 = 0;
}

struct FUN_00844fc0_shell
{
    void* __thiscall FUN_00844fc0(int arg);
};

// Allocates arg << 3 bytes via operator new and returns the pointer.
// @fnv 0x00844fc0
void* __thiscall FUN_00844fc0_shell::FUN_00844fc0(int arg)
{
    void* p = operator new(arg << 3);
    return p;
}

struct BGSReconstructFormsMap
{
    void FUN_008411f0();
    void* FUN_008411c0(unsigned int flags);
};

extern "C" void _Deallocate(void*);

// Calls FUN_008411f0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x008411c0
void* BGSReconstructFormsMap::FUN_008411c0(unsigned int flags)
{
    this->FUN_008411f0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct BGSReconstructCellsMap
{
    void FUN_008413a0();
    void* FUN_00841370(unsigned int flags);
};

void __cdecl _Deallocate(void*);

// @fnv 0x00841370
void* BGSReconstructCellsMap::FUN_00841370(unsigned int flags)
{
    FUN_008413a0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

extern "C" void __cdecl _Deallocate(void*);

struct BGSReconstructCellSubBlocksMap
{
    virtual ~BGSReconstructCellSubBlocksMap();
    void* __thiscall ScalarDeletingDestructor(unsigned int flags);
};

// Destroys the object, frees its storage with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x008416f0
void* __thiscall BGSReconstructCellSubBlocksMap::ScalarDeletingDestructor(unsigned int flags)
{
    BGSReconstructCellSubBlocksMap::~BGSReconstructCellSubBlocksMap();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct S006950d0
{
    unsigned int GetElement(unsigned int);
};

struct FUN_00844160_shell
{
    unsigned int FUN_00844160(unsigned int);
};

// @fnv 0x00844160
unsigned int FUN_00844160_shell::FUN_00844160(unsigned int a)
{
    return ((S006950d0*)this)->GetElement(a);
}

namespace fnv_00844180 {
void* __cdecl _Deallocate(void* p);

struct FUN_00844180_shell
{
    void __thiscall FUN_00844470();
    void* __thiscall FUN_00844180(unsigned int flags);
};

// Calls FUN_00844470, then frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00844180
void* __thiscall FUN_00844180_shell::FUN_00844180(unsigned int flags)
{
    FUN_00844470();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_00844180

extern "C" void _Deallocate(void*);

struct FUN_00844270_shell : BGSReconstructFormsInAllFilesMapBase
{
    void* FUN_00844270(unsigned int flags);
};

// @fnv 0x00844270
void* FUN_00844270_shell::FUN_00844270(unsigned int flags)
{
    BGSReconstructFormsInAllFilesMapBase::~BGSReconstructFormsInAllFilesMapBase();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_00845260_holder
{
    void __thiscall CreateObj();
};

struct FUN_00844500_shell
{
    void __thiscall ForwardToHolder();
};

// @fnv 0x00844500
void __thiscall FUN_00844500_shell::ForwardToHolder()
{
    ((FUN_00845260_holder*)((char*)this + 0xc))->CreateObj();
}

namespace fnv_00844fa0 {
struct GlobalObject_00869f00
{
    void* m_p;
    void __thiscall Clear(bool);
};

extern int DAT_0107ed50;

struct FUN_00844fa0_shell
{
    void* m_p;
    void InitGlobalObject();
};

// @fnv 0x00844fa0
void __thiscall FUN_00844fa0_shell::InitGlobalObject()
{
    m_p = &DAT_0107ed50;
    ((GlobalObject_00869f00*)this)->Clear(true);
}
}  // namespace fnv_00844fa0

struct NiStream;
struct blob12
{
    char b[12];
};
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
struct FUN_00416870_shell : public NiPoint3
{
    void FUN_00416870(float, float, float);
};

struct FUN_00416870_t : public NiPoint3
{
    FUN_00416870_t* FUN_00416870(float, float, float);
};
// Sets the point's x, y and z components from the three arguments and returns this.
// @fnv 0x00416870
FUN_00416870_t* FUN_00416870_t::FUN_00416870(float fX, float fY, float fZ)
{
    x = fX;
    y = fY;
    z = fZ;
    return this;
}

struct FUN_00844040
{
    virtual void Unused();
    int m04;
    int m08;
    int m0C;
    FUN_00844040(int);
};
struct FUN_00841190 : FUN_00844040
{
    int m10;
    FUN_00841190();
};
// Initializes the base with 0x25 and sets m10 to 0.
// @fnv 0x00841190
FUN_00841190::FUN_00841190() : FUN_00844040(0x25)
{
    m10 = 0;
}

namespace fnv_00841340 {
struct FUN_00844070_standin
{
    void FUN_00844070(int);
};
extern int DAT_0107e950;
struct FUN_00841340_standin : FUN_00844070_standin
{
    void* FUN_00841340();
};
// Calls FUN_00844070 with 0x25, stores the address of DAT_0107e950 into this, and returns this.
// @fnv 0x00841340
void* FUN_00841340_standin::FUN_00841340()
{
    FUN_00844070(0x25);
    *(int*)this = (int)&DAT_0107e950;
    return this;
}
}  // namespace fnv_00841340

struct FUN_00452420_shell
{
    bool GetFlag(unsigned int) const;
};
struct FUN_00841660_shell : BGSReconstructFormsInAllFilesMap
{
    bool HasFileMapWithFlag(unsigned int aiFlags);
};
// Iterates the map's entries and returns true if any file map's GetFlag(aiFlags) is set.
// @fnv 0x00841660
bool FUN_00841660_shell::HasFileMapWithFlag(unsigned int aiFlags)
{
    void* it;
    BGSReconstructFormsInFileMap* pformsMap;
    TESFile* icellKey;
    it = GetFirstPos();
    while (it != 0)
    {
        icellKey = 0;
        pformsMap = 0;
        GetNext(it, icellKey, pformsMap);
        if (((FUN_00452420_shell*)pformsMap)->GetFlag(aiFlags))
            return true;
    }
    return false;
}

struct FUN_008440a0
{
    FUN_008440a0(int);
};
extern int DAT_0107e970;
struct FUN_008416c0 : FUN_008440a0
{
    FUN_008416c0();
};
// @fnv 0x008416c0
FUN_008416c0::FUN_008416c0() : FUN_008440a0(0x25)
{
    *(int*)this = (int)&DAT_0107e970;
}

namespace fnv_00841990 {
struct BGSReconstructCellsMap
{
    bool HasFileMapWithFlag(unsigned int);
};
struct BGSReconstructCellSubBlocksMap
{
    bool HasCellWithFlag(unsigned int);
};
// Iterates the map's entries and returns true as soon as a contained cells map reports the given flags via HasFileMapWithFlag.
// @fnv 0x00841990
bool BGSReconstructCellSubBlocksMap::HasCellWithFlag(unsigned int aiFlags)
{
    void* it;
    unsigned int pFile;
    BGSReconstructCellsMap* pcellsMap;
    it = ((BGSReconstructFormsInAllFilesMap*)this)->GetFirstPos();
    while (it != 0)
    {
        pFile = 0;
        pcellsMap = 0;
        ((BGSReconstructFormsInAllFilesMap*)this)
            ->GetNext(it, (TESFile*&)pFile, (BGSReconstructFormsInFileMap*&)pcellsMap);
        if (pcellsMap->HasFileMapWithFlag(aiFlags))
            return true;
    }
    return false;
}
}  // namespace fnv_00841990

struct FUN_008440d0
{
    virtual void Unk();
    int _04;
    int _08;
    int _0C;
    FUN_008440d0(int);
};
struct FUN_008419f0 : FUN_008440d0
{
    int _10;
    bool _14;
    FUN_008419f0(bool);
};
// Initializes the base with 0x25, sets _10 to 0 and stores the bool argument in _14.
// @fnv 0x008419f0
FUN_008419f0::FUN_008419f0(bool a) : FUN_008440d0(0x25)
{
    _10 = 0;
    _14 = a;
}

struct BGSReconstructCellBlocksMap
{
    void FUN_00841a60();
    void* FUN_00841a30(unsigned int);
};
void __cdecl _Deallocate(void*);
// Calls FUN_00841a60, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00841a30
void* BGSReconstructCellBlocksMap::FUN_00841a30(unsigned int flags)
{
    FUN_00841a60();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct Base00841ea0
{
    void FUN_00844100(int);
};
extern int DAT_0107e9b0;
struct FUN_00841ea0 : Base00841ea0
{
    FUN_00841ea0();
};
// Calls FUN_00844100 with 0x25, then stores the address of DAT_0107e9b0 into the object's first field.
// @fnv 0x00841ea0
FUN_00841ea0::FUN_00841ea0()
{
    FUN_00844100(0x25);
    *(int*)this = (int)&DAT_0107e9b0;
}

void __cdecl _Deallocate(void*);
struct BGSReconstructWorldSpacesMap
{
    void FUN_00841f00();
    void* FUN_00841ed0(unsigned int);
};
// Calls FUN_00841f00, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00841ed0
void* BGSReconstructWorldSpacesMap::FUN_00841ed0(unsigned int flags)
{
    FUN_00841f00();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void __cdecl _Deallocate(void*);
struct Host008421c0
{
    void FUN_008421f0();
    void* FUN_008421c0(unsigned int);
};
// @fnv 0x008421c0
void* Host008421c0::FUN_008421c0(unsigned int flags)
{
    FUN_008421f0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_008432e0 {
struct ArrSI
{
    unsigned int GetFlags();
};
struct FUN_00844160_shell
{
    unsigned int FUN_00844160(unsigned int);
};
struct FUN_008432e0_Host
{
    unsigned int FUN_008432e0(unsigned int);
};
// @fnv 0x008432e0
unsigned int FUN_008432e0_Host::FUN_008432e0(unsigned int auiIndex)
{
    unsigned int flags = ((ArrSI*)this)->GetFlags();
    if (auiIndex < flags)
    {
        return ((FUN_00844160_shell*)this)->FUN_00844160(auiIndex);
    }
    else
    {
        return ((FUN_00844160_shell*)((char*)this + 16))->FUN_00844160(auiIndex - flags);
    }
}
}  // namespace fnv_008432e0

namespace fnv_00843330 {
struct ArrSI
{
    unsigned int GetFlags();
    unsigned int GetElementAt(unsigned int);
};
struct FUN_00844160_shell
{
    unsigned int FUN_00844160(unsigned int);
};
// Returns the element at index from this array if index is below GetFlags(), otherwise from the array at offset 0x10 with index minus flags.
// @fnv 0x00843330
unsigned int ArrSI::GetElementAt(unsigned int index)
{
    unsigned int flags = GetFlags();
    if (index < flags)
    {
        return *(unsigned int*)((FUN_00844160_shell*)this)->FUN_00844160(index);
    }
    else
    {
        return *(unsigned int*)((FUN_00844160_shell*)((char*)this + 0x10))->FUN_00844160(index - flags);
    }
}
}  // namespace fnv_00843330

struct Base00844c90
{
    char data[16];
    void FUN_00844c90(unsigned int, int);
};
struct ArrSI : Base00844c90
{
    Base00844c90 second;
    unsigned int GetFlags();
    bool FUN_00843380(unsigned int);
};
// @fnv 0x00843380
bool ArrSI::FUN_00843380(unsigned int auiIndex)
{
    unsigned int flags = GetFlags();
    if (auiIndex < flags)
    {
        FUN_00844c90(auiIndex, 1);
    }
    else
    {
        second.FUN_00844c90(auiIndex - flags, 1);
    }
    return true;
}

class TESFile;
class TESForm;
template <typename T> class BSSimpleList;
TESForm* __cdecl _ref_004839c0(unsigned int);
unsigned int __cdecl GetOwnerFileByID(unsigned int);
struct FUN_00485b60
{
    TESFile* GetFile(int);
};
struct TESDataHandlerSaveLoad
{
    TESFile* GetCompiledFileByIndex(int);
};
struct FUN_00843fe0_Holder
{
    TESFile* FUN_00843fe0(BSSimpleList<TESFile*>* apFileList, unsigned int aiFormID);
};
// @fnv 0x00843fe0
TESFile* FUN_00843fe0_Holder::FUN_00843fe0(BSSimpleList<TESFile*>* apFileList, unsigned int aiFormID)
{
    TESFile* pfile;
    TESForm* pform;
    pform = _ref_004839c0(aiFormID);
    if (pform)
    {
        return ((FUN_00485b60*)pform)->GetFile(-1);
    }
    pfile = (TESFile*)GetOwnerFileByID(aiFormID);
    if (pfile)
    {
        return pfile;
    }
    return ((TESDataHandlerSaveLoad*)g_dataHandler)->GetCompiledFileByIndex(aiFormID >> 24);
}

namespace fnv_00844040 {
extern int DAT_0107eba8;
struct S008442a0
{
    void FUN_008442a0(int);
};
struct FUN_00844040
{
    int vfptr;
    FUN_00844040(int);
};
// Calls FUN_008442a0 on this with a, then sets vfptr to the address of DAT_0107eba8.
// @fnv 0x00844040
FUN_00844040::FUN_00844040(int a)
{
    ((S008442a0*)this)->FUN_008442a0(a);
    vfptr = (int)&DAT_0107eba8;
}
}  // namespace fnv_00844040

extern int DAT_0107ebc8;
struct S_844070
{
    void FUN_00844590(int);
    S_844070* FUN_00844070(int);
};
// Calls FUN_00844590 with a, stores the address of DAT_0107ebc8 into this, and returns this.
// @fnv 0x00844070
S_844070* S_844070::FUN_00844070(int a)
{
    FUN_00844590(a);
    *(int*)this = (int)&DAT_0107ebc8;
    return this;
}

extern int DAT_0107ebe8;
struct C008440a0
{
    int m0;
    void FUN_00844690(int);
    C008440a0* FUN_008440a0(int);
};
// Calls FUN_00844690 with a, stores the address of DAT_0107ebe8 in m0, and returns this.
// @fnv 0x008440a0
C008440a0* C008440a0::FUN_008440a0(int a)
{
    FUN_00844690(a);
    m0 = (int)&DAT_0107ebe8;
    return this;
}

extern int DAT_0107ec08;
struct S008440d0
{
    int field0;
    void FUN_00844870(int);
    S008440d0* FUN_008440d0(int);
};
// Calls FUN_00844870 with a, stores the address of DAT_0107ec08 in field0, and returns this.
// @fnv 0x008440d0
S008440d0* S008440d0::FUN_008440d0(int a)
{
    FUN_00844870(a);
    field0 = (int)&DAT_0107ec08;
    return this;
}

extern int DAT_0107ec28;
struct C844100
{
    int* f0;
    void FUN_00844970(int);
    C844100* FUN_00844100(int);
};
// Calls FUN_00844970 with a, sets f0 to point at DAT_0107ec28, and returns this.
// @fnv 0x00844100
C844100* C844100::FUN_00844100(int a)
{
    FUN_00844970(a);
    f0 = &DAT_0107ec28;
    return this;
}

struct UnnamedClass008441b0
{
    void FUN_00844600();
    void* FUN_008441b0(unsigned int);
};
void __cdecl _Deallocate(void*);
// Calls FUN_00844600, then deallocates this when flags has bit 1 set, and returns this.
// @fnv 0x008441b0
void* UnnamedClass008441b0::FUN_008441b0(unsigned int flags)
{
    FUN_00844600();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void __cdecl _Deallocate(void*);
struct Fake8441e0
{
    void FUN_008447e0();
    void* FUN_008441e0(unsigned int);
};
// Calls FUN_008447e0, then frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x008441e0
void* Fake8441e0::FUN_008441e0(unsigned int flags)
{
    this->FUN_008447e0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void __cdecl _Deallocate(void*);
struct UnknownClass
{
    void FUN_008448e0();
    void* FUN_00844210(unsigned int);
};
// Calls FUN_008448e0, frees this via _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x00844210
void* UnknownClass::FUN_00844210(unsigned int flags)
{
    FUN_008448e0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct C844240
{
    void FUN_008449e0();
    void* FUN_00844240(unsigned int);
};
void __cdecl _Deallocate(void*);
// Calls FUN_008449e0, frees this via _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x00844240
void* C844240::FUN_00844240(unsigned int flags)
{
    this->FUN_008449e0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

extern int DAT_0107ec68;
void _NiFreeAlias(void*);
struct Unk008444d0
{
    void* _0;
    int _4;
    void* _8;
    void FUN_008444d0();
};
// Sets the vtable pointer, clears the pointer map, and frees the _8 allocation.
// @fnv 0x008444d0
void Unk008444d0::FUN_008444d0()
{
    *(void**)this = (void*)&DAT_0107ec68;
    ((NiTPointerMap<unsigned int, unsigned int>*)this)->RemoveAll();
    _NiFreeAlias(_8);
}

extern int DAT_0107ed1c;
void _NiFreeAlias(void*);
struct S_00844e80
{
    int _0;
    int _4;
    void* _8;
    void FUN_00844e80();
};
// @fnv 0x00844e80
void S_00844e80::FUN_00844e80()
{
    *(void**)this = (void*)&DAT_0107ed1c;
    ((NiTPointerMap<unsigned int, unsigned int>*)this)->RemoveAll();
    _NiFreeAlias(this->_8);
}

namespace fnv_00844eb0 {
struct S5460
{
    unsigned int unk0;
    unsigned int FUN_00845460();
};
struct SaveGameSizeState : public S5460
{
    struct Elem
    {
        unsigned int a;
        unsigned int b;
    }* arr;
    void RecordSizeAndLength(unsigned int, unsigned int);
    unsigned int FUN_00844eb0(Elem* p);
};
// @fnv 0x00844eb0
unsigned int SaveGameSizeState::FUN_00844eb0(Elem* apElem)
{
    unsigned int idx = FUN_00845460();
    RecordSizeAndLength((unsigned int)&arr[idx], 1);
    arr[idx] = *apElem;
    return idx;
}
}  // namespace fnv_00844eb0

namespace fnv_00845050 {
struct OffsetData
{
    int _0;
    int _1;
};
struct ArrSI
{
    unsigned int GetFlags();
    unsigned int _pad[4];
};
struct ScrapHeapBuffer
{
    void* Allocate(unsigned int, unsigned int);
    void Deallocate(void*);
};
extern unsigned int DAT_010a2720;
void* __memcpy(void*, const void*, unsigned int);
struct BSScrapArray : ArrSI
{
    ScrapHeapBuffer* m_pAllocator;
    OffsetData* ReallocateBuffer(OffsetData*, unsigned int);
};
// Allocates a new buffer of aiNewSizeInItem items, copies GetFlags() items from apBuffer into it, frees apBuffer and returns the new buffer.
// @fnv 0x00845050
OffsetData* BSScrapArray::ReallocateBuffer(OffsetData* apBuffer, unsigned int aiNewSizeInItem)
{
    OffsetData* pnewBuffer = (OffsetData*)m_pAllocator->Allocate(aiNewSizeInItem * sizeof(OffsetData), DAT_010a2720);
    __memcpy(pnewBuffer, apBuffer, GetFlags() * sizeof(OffsetData));
    m_pAllocator->Deallocate(apBuffer);
    return pnewBuffer;
}
}  // namespace fnv_00845050

struct MyVal
{
    unsigned int a;
    unsigned int b;
};
struct MyItem
{
    void* f0;
    unsigned int f4;
    MyVal f8;
};
struct MyHost
{
    void FUN_00993b30(MyItem* pkItem, unsigned int key, MyVal val);
};
// Stores key into pkItem->f4 and val into pkItem->f8.
// @fnv 0x00993b30
void MyHost::FUN_00993b30(MyItem* pkItem, unsigned int key, MyVal val)
{
    pkItem->f4 = key;
    pkItem->f8 = val;
}

extern "C" void* __cdecl memset(void* dst, int c, unsigned int n);
extern "C" void* __cdecl _NiMalloc(unsigned int size);
extern int DAT_0107ec68;

struct FUN_008442a0_shell
{
    int* p1;
    int p2;
    void* p3;
    int p4;
    int __thiscall FUN_008442a0(int n);
};

// @fnv 0x008442a0
int __thiscall FUN_008442a0_shell::FUN_008442a0(int aiCount)
{
    p1 = &DAT_0107ec68;
    p2 = aiCount;
    p4 = 0;
    int iByteSize = p2 * 4;
    p3 = _NiMalloc(iByteSize);
    memset(p3, 0, p2 * 4);
    return (int)this;
}

void* __cdecl _NiMalloc(unsigned int);
void* __cdecl memset(void*, int, unsigned int);
extern int DAT_0107ed1c;

struct FUN_00844db0_shell
{
    void* p;
    int count;
    void* data;
    int pad;
    FUN_00844db0_shell* __thiscall FUN_00844db0(int param);
};

// Sets p to DAT_0107ed1c, stores param in count, allocates count*4 bytes into data, zeroes them, and returns this.
// @fnv 0x00844db0
FUN_00844db0_shell* __thiscall FUN_00844db0_shell::FUN_00844db0(int aiCount)
{
    unsigned int size;
    p = &DAT_0107ed1c;
    count = aiCount;
    pad = 0;
    size = count << 2;
    data = _NiMalloc(size);
    memset(data, 0, count << 2);
    return this;
}

struct S00844c20
{
    void SetCount(unsigned int);
    char _pad[16];
};
struct H00843be0 : S00844c20
{
    S00844c20 sub;
    void FUN_00843be0(unsigned int);
};
// Calls SetCount on the base and on the sub object with the same argument.
// @fnv 0x00843be0
void H00843be0::FUN_00843be0(unsigned int auiValue)
{
    S00844c20::SetCount(auiValue);
    sub.SetCount(auiValue);
}

namespace fnv_00841e20 {
struct FUN_00452420_shell
{
    bool GetFlag(unsigned int) const;
};
struct FUN_00841990_shell
{
    bool HasCellWithFlag(unsigned int);
};
struct FUN_00841e20_shell : public BGSReconstructFormsInAllFilesMap
{
    bool HasFlagInAnyFile(unsigned int flags);
};
// @fnv 0x00841e20
bool FUN_00841e20_shell::HasFlagInAnyFile(unsigned int flags)
{
    if (*(unsigned int*)((char*)this + 0x10) && ((FUN_00452420_shell*)(*(void**)((char*)this + 0x10)))->GetFlag(flags))
        return true;
    void* it = GetFirstPos();
    while (it)
    {
        TESFile* file = 0;
        BGSReconstructFormsInFileMap* map = 0;
        GetNext(it, file, map);
        if (((FUN_00841990_shell*)map)->HasCellWithFlag(flags))
            return true;
    }
    return false;
}
}  // namespace fnv_00841e20

__declspec(thread) unsigned int DAT_00843c10_tls;

struct FUN_00843c10_shell
{
    void __thiscall SetFlag4(bool bSet);
};

// @fnv 0x00843c10
void __thiscall FUN_00843c10_shell::SetFlag4(bool bSet)
{
    if (bSet)
        DAT_00843c10_tls |= 4;
    else
        DAT_00843c10_tls &= 0xfffffffb;
}

extern int DAT_0107ec08;
struct FUN_00844940_class
{
    virtual ~FUN_00844940_class();
};
struct FUN_008448e0 : public FUN_00844940_class
{
    virtual ~FUN_008448e0();
    void FUN_008448e0_RemoveAll();
};
// @fnv 0x008448e0
FUN_008448e0::~FUN_008448e0()
{
    FUN_008448e0_RemoveAll();
}

struct FUN_0072ba80_shell
{
    void FUN_0072ba80(void*, unsigned int);
};
struct S5460
{
    void FUN_006a2770(unsigned int, unsigned int);
};
struct FUN_00844c20_shell
{
    void SetCount(unsigned int);
};

// If idx differs from the stored count, shrinks the array to idx elements, calls FUN_006a2770 with idx and the new count, then stores idx as the count.
// @fnv 0x00844c20
void FUN_00844c20_shell::SetCount(unsigned int idx)
{
    if (idx == *(unsigned int*)((char*)this + 0xc))
        return;
    if (idx < *(unsigned int*)((char*)this + 8))
    {
        ((FUN_0072ba80_shell*)this)
            ->FUN_0072ba80((char*)*(void**)((char*)this + 4) + idx * 8, *(unsigned int*)((char*)this + 8) - idx);
        *(unsigned int*)((char*)this + 8) = idx;
    }
    ((S5460*)this)->FUN_006a2770(idx, *(unsigned int*)((char*)this + 8));
    *(unsigned int*)((char*)this + 0xc) = idx;
}

namespace fnv_00844ff0 {
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct FUN_00844fa0_class
{
    virtual ~FUN_00844fa0_class();
};
struct FUN_00844ff0 : FUN_00844fa0_class, GlobalObject_00869f00
{
    virtual ~FUN_00844ff0();
};
// Destructor that calls Clear(true) on the GlobalObject base subobject of this instance.
// @fnv 0x00844ff0
FUN_00844ff0::~FUN_00844ff0()
{
    reinterpret_cast<GlobalObject_00869f00*>(this)->Clear(true);
}
}  // namespace fnv_00844ff0

namespace fnv_00841580 {
extern void* __cdecl operator new(unsigned int);
extern unsigned int _data_011c16bc;

struct TESWorldSpace
{
    static int __cdecl BuildCellKey(short, short);
};

struct SetAtHelper
{
    void SetAt(unsigned int, unsigned int);
};

struct DummyPointerMap : public SetAtHelper
{
    bool GetAt(unsigned int, unsigned int&);
    void SetAtCoordinates(unsigned int, short, short, unsigned int, unsigned int, unsigned int);
};

struct FUN_00841190
{
    int data[5];
    FUN_00841190(void);
    void ProcessRef(unsigned int, unsigned int, unsigned int);
};

// Looks up a value by worldspace coordinates, allocating and inserting a new FUN_00841190 if absent, then calls ProcessRef on it with a, b, c.
// @fnv 0x00841580
void DummyPointerMap::SetAtCoordinates(unsigned int, short x, short y, unsigned int auiArg1, unsigned int auiArg2,
                                       unsigned int auiArg3)
{
    int value = TESWorldSpace::BuildCellKey(x, y);
    unsigned int key = 0;

    if (!GetAt(value, key))
    {
        key = (unsigned int)new FUN_00841190;
        SetAt(value, key);
    }

    reinterpret_cast<FUN_00841190*>(key)->ProcessRef(auiArg1, auiArg2, auiArg3);
}
}  // namespace fnv_00841580

struct FUN_00544210_shell
{
    unsigned int FUN_00544210();
};

struct DummyPointerMap
{
    bool GetAt(unsigned int, unsigned int&);
};

struct SetAtHelper : public DummyPointerMap
{
    void SetAt(unsigned int, unsigned int);
    void GetOrCreateAndDispatch(FUN_00544210_shell*, unsigned int, unsigned int, unsigned int);
};

struct FUN_00841460_shell
{
    void FUN_00841460(FUN_00544210_shell*, unsigned int, unsigned int, unsigned int);
};

struct FUN_00841340 : public FUN_00841460_shell
{
    unsigned char data[16];
    FUN_00841340();
};

FUN_00841340::FUN_00841340()
{}

void FUN_00841460_shell::FUN_00841460(FUN_00544210_shell* param1, unsigned int param2, unsigned int param3,
                                      unsigned int param4)
{}

// Looks up the entry for param1's key, creating a new FUN_00841340 if absent, then forwards param1-param4 to its FUN_00841460.
// @fnv 0x008417e0
void SetAtHelper::GetOrCreateAndDispatch(FUN_00544210_shell* pKeySource, unsigned int param2, unsigned int param3,
                                         unsigned int param4)
{
    unsigned int uiKey = pKeySource->FUN_00544210();
    unsigned int uiEntry = 0;

    if (!this->GetAt(uiKey, uiEntry))
    {
        uiEntry = (unsigned int)new FUN_00841340;
        this->SetAt(uiKey, uiEntry);
    }

    ((FUN_00841460_shell*)uiEntry)->FUN_00841460(pKeySource, param2, param3, param4);
}

namespace fnv_008418b0 {
void* operator new(unsigned int);

int __cdecl FUN_005442c0(int, int);

struct FUN_00841340
{
    int field_0;
    int field_4;
    int field_8;
    int field_C;

    FUN_00841340();
    void SetAtCoordinates(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
};

struct SetAtHelper
{
    void SetAt(unsigned int, FUN_00841340*);
};

struct DummyPointerMap : public SetAtHelper
{
    bool GetAt(unsigned int, FUN_00841340*&);
};

struct FUN_008418b0_shell : public DummyPointerMap
{
    void GetOrCreateEntry(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
};

// @fnv 0x008418b0
void FUN_008418b0_shell::GetOrCreateEntry(unsigned int arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4,
                                          unsigned int arg5, unsigned int arg6)
{
    unsigned int key = FUN_005442c0(arg2, arg3);
    FUN_00841340* value = 0;

    if (!GetAt(key, value))
    {
        value = new FUN_00841340;
        SetAt(key, value);
    }

    value->SetAtCoordinates(arg1, arg2, arg3, arg4, arg5, arg6);
}
}  // namespace fnv_008418b0

namespace fnv_00841fc0 {
void* __cdecl operator new(unsigned int);

struct DoorH
{
    void* GetParentWorldSpace();
};

struct SoundH
{
    unsigned int Deallocate();
};

struct DummyPointerMap
{
    bool GetAt(unsigned int, unsigned int&);
};

struct SetAtHelper : DummyPointerMap
{
    void SetAt(unsigned int, unsigned int);
};

struct FUN_008419f0
{
    unsigned int field0;
    unsigned int field1;
    unsigned int field2;
    unsigned int field3;
    unsigned int field4;
    unsigned int field5;

    FUN_008419f0(bool);
    void ProcessEntry(DoorH*, unsigned int, unsigned int, unsigned int);
};

struct FUN_00841fc0_class : SetAtHelper
{
    void FUN_00841fc0(DoorH*, unsigned int, unsigned int, unsigned int);
};

// @fnv 0x00841fc0
void FUN_00841fc0_class::FUN_00841fc0(DoorH* door, unsigned int arg1, unsigned int arg2, unsigned int arg3)
{
    void* id;
    unsigned int value;
    unsigned int worldSpace;

    id = door->GetParentWorldSpace();
    value = reinterpret_cast<SoundH*>(id)->Deallocate();
    worldSpace = 0;

    if (!GetAt(value, worldSpace))
    {
        worldSpace = reinterpret_cast<unsigned int>(new FUN_008419f0(true));
        SetAt(value, worldSpace);
    }

    reinterpret_cast<FUN_008419f0*>(worldSpace)->ProcessEntry(door, arg1, arg2, arg3);
}
}  // namespace fnv_00841fc0

namespace fnv_008420a0 {
struct FUN_008419f0
{
    unsigned char data[24];

    FUN_008419f0(bool);

    void ReconstructFormEntry(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
};

struct SetAtHelper
{
    void SetAt(unsigned int, FUN_008419f0*);
};

struct DummyPointerMap : public SetAtHelper
{
    bool GetAt(unsigned int, FUN_008419f0*&);
};

void* __cdecl operator new(unsigned int);

unsigned int __fastcall _ref_0084e3a0(unsigned int);

struct FUN_008420a0_class : public DummyPointerMap
{
    void FUN_008420a0(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
};

// @fnv 0x008420a0
void FUN_008420a0_class::FUN_008420a0(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4,
                                      unsigned int a5, unsigned int a6)
{
    unsigned int map = _ref_0084e3a0(a1);
    FUN_008419f0* object = 0;

    if (!GetAt(map, object))
    {
        object = new FUN_008419f0(true);
        SetAt(map, object);
    }

    object->ReconstructFormEntry(a1, a2, a3, a4, a5, a6);
}
}  // namespace fnv_008420a0

namespace fnv_00842600 {
void* __cdecl operator new(unsigned int);

struct TESObjectCELL
{
    bool IsInterior();
};

struct FUN_008419f0
{
    char padding[0x18];
    FUN_008419f0(bool);
};

struct FUN_00841ea0
{
    char padding[0x10];
    FUN_00841ea0();
};

struct FUN_00841b20_standin
{
    void ProcessEntry(TESObjectCELL*, int, int, int);
};

struct FUN_00841fc0_standin
{
    void FUN_00841fc0(TESObjectCELL*, int, int, int);
};

struct FUN_00842600_shell
{
    void ProcessCell(TESObjectCELL*, int, int, int);
};

// Dispatches the cell to an interior or exterior handler, lazily allocating it, then increments a counter at offset 0x18.
// @fnv 0x00842600
void FUN_00842600_shell::ProcessCell(TESObjectCELL* cell, int aiArg1, int aiArg2, int aiArg3)
{
    if (cell->IsInterior())
    {
        if (!*reinterpret_cast<FUN_00841b20_standin**>(reinterpret_cast<char*>(this) + 0x10))
        {
            *reinterpret_cast<FUN_00841b20_standin**>(reinterpret_cast<char*>(this) + 0x10) =
                reinterpret_cast<FUN_00841b20_standin*>(new FUN_008419f0(false));
        }

        reinterpret_cast<FUN_00841b20_standin*>(
            *reinterpret_cast<FUN_00841b20_standin**>(reinterpret_cast<char*>(this) + 0x10))
            ->ProcessEntry(cell, aiArg1, aiArg2, aiArg3);
    }
    else
    {
        if (!*reinterpret_cast<FUN_00841fc0_standin**>(reinterpret_cast<char*>(this) + 0x14))
        {
            *reinterpret_cast<FUN_00841fc0_standin**>(reinterpret_cast<char*>(this) + 0x14) =
                reinterpret_cast<FUN_00841fc0_standin*>(new FUN_00841ea0());
        }

        reinterpret_cast<FUN_00841fc0_standin*>(
            *reinterpret_cast<FUN_00841fc0_standin**>(reinterpret_cast<char*>(this) + 0x14))
            ->FUN_00841fc0(cell, aiArg1, aiArg2, aiArg3);
    }

    ++*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x18);
}
}  // namespace fnv_00842600

namespace fnv_00842730 {
void* __cdecl operator new(unsigned int);

struct FUN_00841ea0
{
    int _unused[4];

    FUN_00841ea0();
    void __thiscall FUN_008420a0(int, int, int, int, int, int);
};

struct FUN_00842730_shell
{
    char _padding[0x14];
    FUN_00841ea0* _object;
    int _count;

    void EnsureObjectAndCall(int, int, int, int, int, int);
};

// Allocates the object if null, forwards the six arguments to its method, and increments the count.
// @fnv 0x00842730
void FUN_00842730_shell::EnsureObjectAndCall(int a, int b, int c, int d, int e, int f)
{
    if (_object == 0)
    {
        _object = new FUN_00841ea0;
    }

    _object->FUN_008420a0(a, b, c, d, e, f);

    _count += 1;
}
}  // namespace fnv_00842730

namespace fnv_00843630 {
void* __cdecl operator new(unsigned int);
void __cdecl _fnv_call_845cc0(char const*, ...);

struct TESFormCallProxy
{
    TESFile* _FNV_GetFile(int);
    char const* FUN_00440e30();
};

struct TESFormRefProxy
{
    unsigned int _ref_0084e3a0();
};

struct VirtualBase : TESForm
{
    virtual void vfn_61()
    {}
    virtual void vfn_62()
    {}
    virtual void vfn_63()
    {}
    virtual void vfn_64()
    {}
    virtual void vfn_65()
    {}
    virtual void vfn_66()
    {}
    virtual void vfn_67()
    {}
    virtual void vfn_68()
    {}
    virtual void vfn_69()
    {}
    virtual void vfn_70()
    {}
    virtual void vfn_71()
    {}
    virtual void vfn_72()
    {}
    virtual void vfn_73()
    {}
    virtual void vfn_74()
    {}
    virtual void vfn_75()
    {}
    virtual char const* vfn_76()
    {
        return 0;
    }
};

struct DummyPointerMap
{
    bool GetAt(unsigned int, unsigned int&);
};

struct SetAtHelper
{
    void SetAt(unsigned int, unsigned int);
};

struct FUN_00842180
{
    unsigned char data[0x1c];

    FUN_00842180();
};

FUN_00842180::FUN_00842180()
{}

struct MapCallProxy
{
    void FUN_00842310(TESForm*, unsigned int);
};

struct FUN_00843630_shell : BGSReconstructFormsInAllFilesMap
{
    void FUN_00843630(TESForm*, unsigned int);
};

// Adds apForm to the per-file map keyed by its TESFile, creating the entry if missing, then increments iCount; logs an error when the form has no file.
// @fnv 0x00843630
void FUN_00843630_shell::FUN_00843630(TESForm* apForm, unsigned int aiFlags)
{
    BGSReconstructFormsInFileMap* pformsInFileMap;
    TESFile* pfile;

    if (!apForm)
        return;

    pfile = reinterpret_cast<TESFormCallProxy*>(apForm)->_FNV_GetFile(-1);

    if (!pfile)
    {
        _fnv_call_845cc0("Form %08X %s with type %s and no file passed to BGSReconstructFormsInAllFilesMap::AddForm()",
                         reinterpret_cast<TESFormRefProxy*>(apForm)->_ref_0084e3a0(),
                         reinterpret_cast<VirtualBase*>(apForm)->vfn_76(),
                         reinterpret_cast<TESFormCallProxy*>(apForm)->FUN_00440e30());
        return;
    }

    pformsInFileMap = 0;

    if (!reinterpret_cast<DummyPointerMap*>(this)->GetAt(reinterpret_cast<unsigned int>(pfile),
                                                         reinterpret_cast<unsigned int&>(pformsInFileMap)))
    {
        pformsInFileMap = reinterpret_cast<BGSReconstructFormsInFileMap*>(new FUN_00842180());

        reinterpret_cast<SetAtHelper*>(this)->SetAt(reinterpret_cast<unsigned int>(pfile),
                                                    reinterpret_cast<unsigned int>(pformsInFileMap));
    }

    reinterpret_cast<MapCallProxy*>(pformsInFileMap)->FUN_00842310(apForm, aiFlags);

    ++iCount;
}
}  // namespace fnv_00843630

namespace fnv_00844c90 {
struct FUN_00692480
{
    void Method(char*, char*, unsigned int);
};

struct FUN_006c8a30_Class
{
    void FUN_006a8500();
};

struct FUN_006f3170_Class
{
    bool FUN_006f3170();
};

struct FUN_0072ba80_shell
{
    void FUN_0072ba80(char*, unsigned int);
};

struct FUN_00869600_Class
{
    unsigned int FUN_00869600();
};

struct FUN_00844c90_shell
{
    // Virtual destructor for the shell object; empty body.
// @fnv 0x00844c90
    virtual ~FUN_00844c90_shell()
    {}
    virtual char* GetArray(unsigned int) = 0;

    char* m_items;
    unsigned int m_uiItemCount;
    unsigned int m_uiFilterValue;

    void FUN_00844c90(unsigned int, bool);
};

void FUN_00844c90_shell::FUN_00844c90(unsigned int index, bool useArray)
{
    char* array;

    if (useArray && reinterpret_cast<FUN_006f3170_Class*>(this)->FUN_006f3170())
    {
        unsigned int count = reinterpret_cast<FUN_00869600_Class*>(this)->FUN_00869600();
        array = GetArray(count);

        reinterpret_cast<FUN_00692480*>(this)->Method(array, m_items, index);
        reinterpret_cast<FUN_0072ba80_shell*>(this)->FUN_0072ba80(m_items + index * 8, 1);

        reinterpret_cast<FUN_00692480*>(this)->Method(array + index * 8, m_items + index * 8 + 8, m_uiItemCount - 1);

        reinterpret_cast<FUN_006c8a30_Class*>(this)->FUN_006a8500();
        m_items = array;
        m_uiFilterValue = count;
    }
    else
    {
        reinterpret_cast<FUN_0072ba80_shell*>(this)->FUN_0072ba80(m_items + index * 8, 1);

        reinterpret_cast<FUN_00692480*>(this)->Method(m_items + index * 8, m_items + index * 8 + 8,
                                                      m_uiItemCount - index - 1);
    }

    --m_uiItemCount;
}
}  // namespace fnv_00844c90

namespace fnv_00841b20 {
void* __cdecl operator new(unsigned int);

struct FUN_005441b0_S
{
    unsigned int FUN_005441b0(void);
};

struct FUN_00565450_shell
{
    virtual bool v00() = 0;
    virtual bool v01() = 0;
    virtual bool v02() = 0;
    virtual bool v03() = 0;
    virtual bool v04() = 0;
    virtual bool v05() = 0;
    virtual bool v06() = 0;
    virtual bool v07() = 0;
    virtual bool v08() = 0;
    virtual bool v09() = 0;
    virtual bool v10() = 0;
    virtual bool v11() = 0;
    virtual bool v12() = 0;
    virtual bool v13() = 0;
    virtual bool v14() = 0;
    virtual bool v15() = 0;
    virtual bool v16() = 0;
    virtual bool v17() = 0;
    virtual bool v18() = 0;
    virtual bool v19() = 0;
    virtual bool v20() = 0;
    virtual bool v21() = 0;
    virtual bool v22() = 0;
    virtual bool v23() = 0;
    virtual bool v24() = 0;
    virtual bool v25() = 0;
    virtual bool v26() = 0;
    virtual bool v27() = 0;
    virtual bool v28() = 0;
    virtual bool v29() = 0;
    virtual bool v30() = 0;
    virtual bool v31() = 0;
    virtual bool v32() = 0;
    virtual bool v33() = 0;
    virtual bool v34() = 0;
    virtual bool v35() = 0;
    virtual bool v36() = 0;
    virtual bool v37() = 0;
    virtual bool v38() = 0;
    virtual bool v39() = 0;
    virtual bool v40() = 0;
    virtual bool v41() = 0;
    virtual bool v42() = 0;
    virtual bool v43() = 0;
    virtual bool v44() = 0;
    virtual bool v45() = 0;
    virtual bool v46() = 0;
    virtual bool v47() = 0;
    virtual bool v48() = 0;
    virtual bool v49() = 0;
    virtual bool v50() = 0;
    virtual bool v51() = 0;
    virtual bool v52() = 0;
    virtual bool v53() = 0;
    virtual bool v54() = 0;
    virtual bool v55() = 0;
    virtual bool v56() = 0;
    virtual bool v57() = 0;
    virtual bool v58() = 0;
    virtual bool v59() = 0;
    virtual bool FUN_00841b20_virtual() = 0;

    bool FUN_00565450(void);
};

struct FUN_00841190
{
    unsigned char data[0x14];

    FUN_00841190(void);
    void ProcessRef(FUN_00565450_shell*, unsigned int, unsigned int);
};

struct FUN_008416c0
{
    unsigned char data[0x10];

    FUN_008416c0(void);
    void GetOrCreateAndDispatch(FUN_005441b0_S*, FUN_00565450_shell*, unsigned int, unsigned int);
};

struct DummyPointerMap
{
    bool GetAt(unsigned int, unsigned int&);
};

struct SetAtHelper
{
    void SetAt(unsigned int, unsigned int);
};

struct FUN_00841b20_shell
{
    unsigned char padding[0x10];
    FUN_00841190* form;
    unsigned char flag;

    void ProcessEntry(FUN_005441b0_S*, FUN_00565450_shell*, unsigned int, unsigned int);
};

// @fnv 0x00841b20
void FUN_00841b20_shell::ProcessEntry(FUN_005441b0_S* first, FUN_00565450_shell* second, unsigned int third,
                                      unsigned int fourth)
{
    if (flag && second && second->FUN_00841b20_virtual())
    {
        FUN_00565450_shell* shell = second;

        if (shell->FUN_00565450())
        {
            if (!form)
                form = new FUN_00841190();

            form->ProcessRef(second, third, fourth);
            return;
        }
    }

    unsigned int key = first->FUN_005441b0();
    unsigned int value = 0;

    if (!reinterpret_cast<DummyPointerMap*>(this)->GetAt(key, value))
    {
        value = reinterpret_cast<unsigned int>(new FUN_008416c0());
        reinterpret_cast<SetAtHelper*>(this)->SetAt(key, value);
    }

    reinterpret_cast<FUN_008416c0*>(value)->GetOrCreateAndDispatch(first, second, third, fourth);
}
}  // namespace fnv_00841b20

namespace fnv_00844ae0 {
struct FUN_0072ba80_shell
{
    void FUN_0072ba80(char*, unsigned int);
};

struct S5460
{
    void FUN_006a2770(unsigned int, unsigned int);
};

struct SaveGameSizeState
{
    void RecordSizeAndLength(unsigned int, unsigned int);
};

struct BSSimpleArrayActor
{
    typedef void*(__thiscall* Allocator)(BSSimpleArrayActor*, unsigned int);

    struct VTable
    {
        void* vftableEntry;
        Allocator allocator;
    };

    VTable* m_ppVirtualMethodTable;
    unsigned char* m_data;
    unsigned int m_iElementCount;
    unsigned int m_pRayCursor;

    void Clear(bool);
    void Resize(unsigned int, bool);
};

// @fnv 0x00844ae0
void BSSimpleArrayActor::Resize(unsigned int size, bool clear)
{
    if (size == 0)
    {
        this->Clear(clear);
        return;
    }

    if (size > this->m_pRayCursor)
    {
        if (this->m_pRayCursor == 0)
        {
            this->m_data = static_cast<unsigned char*>(this->m_ppVirtualMethodTable->allocator(this, size));
            this->m_pRayCursor = size;
        }
        else
        {
            reinterpret_cast<S5460*>(this)->FUN_006a2770(size, this->m_iElementCount);
            this->m_pRayCursor = size;
        }

        reinterpret_cast<SaveGameSizeState*>(this)->RecordSizeAndLength(
            reinterpret_cast<unsigned int>(this->m_data + this->m_iElementCount * 8), size - this->m_iElementCount);
        this->m_iElementCount = size;
    }
    else if (size < this->m_iElementCount)
    {
        reinterpret_cast<FUN_0072ba80_shell*>(this)->FUN_0072ba80(reinterpret_cast<char*>(this->m_data + size * 8),
                                                                  this->m_iElementCount - size);
        this->m_iElementCount = size;

        if (clear && size <= this->m_pRayCursor / 4)
        {
            reinterpret_cast<S5460*>(this)->FUN_006a2770(size, size);
            this->m_pRayCursor = size;
        }
    }
    else
    {
        reinterpret_cast<SaveGameSizeState*>(this)->RecordSizeAndLength(
            reinterpret_cast<unsigned int>(this->m_data + this->m_iElementCount * 8), size - this->m_iElementCount);
        this->m_iElementCount = size;
    }
}
}  // namespace fnv_00844ae0

class B411F0MapBase
{
  public:
    virtual ~B411F0MapBase();

    void RemoveAll();

    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
};

class FUN_008411f0 : public B411F0MapBase
{
  public:
    virtual ~FUN_008411f0();
};

// @fnv 0x008411f0
FUN_008411f0::~FUN_008411f0()
{
    RemoveAll();
}

struct FUN_008413a0_item
{
    virtual void* Free(unsigned int flags);
};

struct FUN_008413a0_base
{
    virtual ~FUN_008413a0_base();
    void* GetFirstPos();
    void GetNext(void*& pos, unsigned int& key, FUN_008413a0_item*& val);
};

struct FUN_008413a0 : FUN_008413a0_base
{
    virtual ~FUN_008413a0();
};

// Iterates the container's entries and frees each item with flags 1.
// @fnv 0x008413a0
FUN_008413a0::~FUN_008413a0()
{
    void* pos2 = GetFirstPos();
    while (pos2 != 0)
    {
        unsigned int key = 0;
        FUN_008413a0_item* data2 = 0;
        GetNext(pos2, key, data2);
        FUN_008413a0_item* tmp4 = data2;
        FUN_008413a0_item* val = tmp4;
        (val != 0) ? val->Free(1) : 0;
    }
}

struct ValueItem
{
    virtual ~ValueItem();
};
struct BaseMap
{
    virtual ~BaseMap();
    void* FUN_004b9ba0();
    void FUN_006b7f20(void**, unsigned int*, ValueItem**);
    void FUN_008447e0();
};
struct FUN_00841720 : BaseMap
{
    virtual ~FUN_00841720();
};
// Iterates the map via FUN_004b9ba0/FUN_006b7f20, deleting each ValueItem until the position is null.
// @fnv 0x00841720
FUN_00841720::~FUN_00841720()
{
    void* position = FUN_004b9ba0();
    while (position != 0)
    {
        ValueItem* item;
        {
            unsigned int key = 0;
            item = 0;
            FUN_006b7f20(&position, &key, &item);
        }
        delete item;
    }
}

struct FUN_00401170_shell
{
    unsigned int FUN_00401170();
};

struct FUN_00844eb0_shell
{
    void FUN_00844eb0(ChangedFormRecord* apData);
};

struct FUN_00843270_shell : public FormChangeMap
{
    void FUN_00843270(ChangedFormRecord* apData);
};

// Dispatches apData to one of two handlers depending on whether its form is a reference or has type 0x39 or 0x41.
// @fnv 0x00843270
void FUN_00843270_shell::FUN_00843270(ChangedFormRecord* apData)
{
    if (!apData->pForm->GetIsReference() && ((FUN_00401170_shell*)apData->pForm)->FUN_00401170() != 0x39 &&
        ((FUN_00401170_shell*)apData->pForm)->FUN_00401170() != 0x41)
    {
        ((FUN_00844eb0_shell*)&m_kOrdinaryFormChanges)->FUN_00844eb0(apData);
    }
    else
    {
        ((FUN_00844eb0_shell*)&m_kSpecialFormChanges)->FUN_00844eb0(apData);
    }
}

struct FNV_ValuePair
{
    unsigned int data1;
    unsigned int data2;
};
struct FNV_MapEntry
{
    FNV_MapEntry* next;
    unsigned int key;
    FNV_ValuePair data;
};

class FNV_BucketMap
{
  public:
    virtual void OnDestroy();
    virtual unsigned int GetBucket(unsigned int key);
    virtual bool IsEqual(unsigned int key, unsigned int entryKey);
    virtual void InitializeEntry(FNV_MapEntry* entry, unsigned int key, FNV_ValuePair value);
    virtual void ReservedSlot();
    virtual FNV_MapEntry* NewEntry();

    unsigned int bucketCount;
    FNV_MapEntry** buckets;
    unsigned int entryCount;

    void SetValue(unsigned int key, FNV_ValuePair value);
};

// Looks up the entry for key in its bucket and overwrites its value, or creates, initializes and prepends a new entry and increments entryCount.
// @fnv 0x00844310
void FNV_BucketMap::SetValue(unsigned int key, FNV_ValuePair valuePair)
{
    unsigned int bucketIndex = GetBucket(key);
    FNV_MapEntry* entry = buckets[bucketIndex];
    unsigned int visited = 0;
    while (entry)
    {
        ++visited;
        if (IsEqual(key, entry->key))
        {
            entry->data = valuePair;
            return;
        }
        entry = entry->next;
    }
    entry = NewEntry();
    InitializeEntry(entry, key, valuePair);
    entry->next = buckets[bucketIndex];
    buckets[bucketIndex] = entry;
    entryCount += 1;
}

struct Base00844660
{
    virtual ~Base00844660();
};

struct FUN_00844600 : Base00844660
{
    void FUN_00438af0();
    virtual ~FUN_00844600();
};

// Destructor that calls FUN_00438af0 before the object is destroyed.
// @fnv 0x00844600
FUN_00844600::~FUN_00844600()
{
    FUN_00438af0();
}

struct Base
{
    virtual ~Base();
};

struct FUN_008447e0 : Base
{
    virtual ~FUN_008447e0();
};

// Destructor that clears the NiTPointerMap by calling RemoveAll.
// @fnv 0x008447e0
FUN_008447e0::~FUN_008447e0()
{
    ((NiTPointerMap<int, int>*)this)->RemoveAll();
}

struct FUN_00844a40
{
    virtual ~FUN_00844a40();
};

struct FUN_008449e0_cls : public FUN_00844a40
{
    void Clear();
    virtual ~FUN_008449e0_cls();
};

// @fnv 0x008449e0
FUN_008449e0_cls::~FUN_008449e0_cls()
{
    Clear();
}

class TESGlobal
{
};

struct FormContext
{
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
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
    virtual const char* GetDisplayName();
    TESFile* FUN_00484e60(int fileIndex);
    const char* FUN_0084e3a0();
};

struct FormTypeReader
{
    unsigned int FUN_00401170();
};

void __cdecl ResolveFormID(unsigned int* numericID, TESFile* file);
extern "C" void __cdecl FUN_005b5e40(const char* format, ...);
extern char DAT_01014168[];
extern char DAT_01014100[];

struct FUN_0040e7f0_owner
{
    TESForm* primary;
    TESGlobal* secondary;
    void ResolveFormReferences(FormContext* context);
};

// Resolves primary and secondary form references through the file context, logging failures and clearing secondary when primary is null.
// @fnv 0x0040e7f0
void FUN_0040e7f0_owner::ResolveFormReferences(FormContext* context)
{
    if (primary != 0)
    {
        unsigned int numericID = (unsigned int)primary;
        ResolveFormID(&numericID, context->FUN_00484e60(-1));
        primary = _ref_004839c0(numericID);
        if (primary == 0)
        {
            FUN_005b5e40(DAT_01014168, numericID, context->GetDisplayName(), context->FUN_0084e3a0());
        }
    }

    if (primary != 0)
    {
        if (((FormTypeReader*)primary)->FUN_00401170() == 42 && secondary != 0)
        {
            unsigned int uiSecondaryID = (unsigned int)secondary;
            ResolveFormID(&uiSecondaryID, context->FUN_00484e60(-1));
            secondary = dynamic_cast<TESGlobal*>(_ref_004839c0(uiSecondaryID));
            if (secondary == 0)
            {
                FUN_005b5e40(DAT_01014100, uiSecondaryID, context->GetDisplayName(), context->FUN_0084e3a0());
            }
        }
    }
    else
    {
        secondary = 0;
    }
}

struct ReconstructCellBlock
{
    virtual ~ReconstructCellBlock();
};
struct FUN_00841a60 : FUN_008448e0
{
    virtual ~FUN_00841a60();
    void* FUN_004b9ba0();
    void FUN_006b7f20(void**, unsigned int*, ReconstructCellBlock**);
};
// @fnv 0x00841a60
FUN_00841a60::~FUN_00841a60()
{
    void* position = FUN_004b9ba0();
    while (position)
    {
        unsigned int key = 0;
        ReconstructCellBlock* pEntry = 0;
        FUN_006b7f20(&position, &key, &pEntry);
        delete pEntry;
    }
}

struct FormWithSaveCheck : TESForm
{
    bool FUN_00565450();
};
struct ReconstructEntry
{
    void ProcessRef(FormWithSaveCheck*, int, int);
    void GetOrCreateEntry(int, int, int, FormWithSaveCheck*, int, int);
};
struct ReconstructedCellStorage : FUN_008416c0
{
    unsigned int recordID;
    void* owner;
    unsigned int flags;
    unsigned int count;
};
int __cdecl GetCellCoordKey(int, int);
struct SaveLoadDispatcher
{
    int state00, state04, state08, state0c;
    ReconstructEntry* helper10;
    bool GetAt(int, ReconstructEntry**);
    void FUN_00844700(int, ReconstructEntry*);
    void ReconstructFormEntry(int, int, int, FormWithSaveCheck*, int, int);
};
// If form is a reference with a save check, forwards it to helper10; otherwise looks up or creates a ReconstructEntry for the handle and reconstructs the entry.
// @fnv 0x00841ca0
void SaveLoadDispatcher::ReconstructFormEntry(int value, int formID, int context, FormWithSaveCheck* form, int flag,
                                              int offset)
{
    int handle3;
    FormWithSaveCheck* referenceForm;
    ReconstructEntry* entry7;
    if (form != 0 && form->GetIsReference() && (referenceForm = form, referenceForm->FUN_00565450()))
    {
        if (helper10 == 0)
            helper10 = (ReconstructEntry*)new FUN_00841190;
        helper10->ProcessRef(form, flag, offset);
    }
    else
    {
        handle3 = GetCellCoordKey(formID, context);
        entry7 = 0;
        if (!GetAt(handle3, &entry7))
        {
            entry7 = (ReconstructEntry*)new ReconstructedCellStorage;
            FUN_00844700(handle3, entry7);
        }
        entry7->GetOrCreateEntry(value, formID, context, form, flag, offset);
    }
}

namespace fnv_008421f0 {
struct BGSCellNumericIDArrayMap
{
    virtual ~BGSCellNumericIDArrayMap();
};
struct FUN_00844600
{
    unsigned int m_uiHashSize;
    void* m_ppHashTable;
    unsigned int m_uiCount;
    virtual ~FUN_00844600();
    void* FUN_004b9ba0();
    void FUN_006b7f20(void*& rpPos, unsigned int& ruiKey, BGSCellNumericIDArrayMap*& rpVal);
};
struct FUN_008421f0 : FUN_00844600
{
    BGSCellNumericIDArrayMap* m_pFirst;
    BGSCellNumericIDArrayMap* m_pSecond;
    virtual ~FUN_008421f0();
};
// Iterates the hash table deleting each BGSCellNumericIDArrayMap entry, then deletes m_pFirst and m_pSecond.
// @fnv 0x008421f0
FUN_008421f0::~FUN_008421f0()
{
    void* pPos = FUN_004b9ba0();
    while (pPos)
    {
        unsigned int uiKey = 0;
        BGSCellNumericIDArrayMap* pItem = 0;
        FUN_006b7f20(pPos, uiKey, pItem);
        delete pItem;
    }
    delete m_pFirst;
    delete m_pSecond;
}
}  // namespace fnv_008421f0

int __cdecl FUN_00406d90(float afValue);

struct RegPoint
{
    float x, y, z;
    RegPoint();
};

struct RegRef;
void __cdecl FUN_00846190(int aiIndex, void** appCell, void** appWorld);

struct RegLand
{
    void* FUN_0054ddd0();
    int FUN_00544c30();
    int FUN_00544c60();
};

struct RegRef
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
    virtual int GetFormType();
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
    virtual bool IsReference();
    virtual void v0F4();
    virtual void v0F8();
    virtual void v0FC();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10C();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11C();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12C();
    virtual void v130();
    virtual void v134();
    virtual bool GetPosition(RegPoint* apPos, RegPoint* apRot, int* apIndex, int aiUnk);
    virtual void v13C();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14C();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15C();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16C();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17C();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18C();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19C();
    virtual void v1A0();
    virtual void v1A4();
    virtual void v1A8();
    virtual void v1AC();
    virtual void v1B0();
    virtual void v1B4();
    virtual void v1B8();
    virtual void v1BC();
    virtual void v1C0();
    virtual void v1C4();
    virtual void v1C8();
    virtual void v1CC();
    virtual void v1D0();
    virtual void v1D4();
    virtual void v1D8();
    virtual void v1DC();
    virtual void v1E0();
    virtual void v1E4();
    virtual void v1E8();
    virtual void v1EC();
    virtual void v1F0();
    virtual const RegPoint& GetPos();
    void* FUN_00575d70();
    void* FUN_008d6f30();
    RegLand* FUN_0059bb30();
};

struct RegList
{
    int unk00, unk04, unk08, unk0C, unk10;
    RegList();
    void ProcessRef(RegRef* apRef, int aiUnk, int aiArg);
};

struct RegFormTypeEntry
{
    int iKey;
    int unk04;
    int unk08;
};
extern RegFormTypeEntry g_aRegFormTypes[];

struct RegManager
{
    int unk00, unk04, unk08, unk0C, unk10, unk14;
    int iCount;

    void EnsureObjectAndCall(void* apCell, int aiX, int aiY, RegRef* apRef, int aiUnk, int aiArg);
    void ProcessCell(void* apCell, RegRef* apRef, int aiUnk, int aiArg);
    bool GetAt(int aiKey, RegList** appList);
    void FUN_00844700(int aiKey, RegList* apList);
    void FUN_00842310(RegRef* apRef, int aiArg);
};

// Registers a reference by form type: resolves its cell/world position or land cell and dispatches to the matching registration routine.
// @fnv 0x00842310
void RegManager::FUN_00842310(RegRef* apRef, int aiArg)
{
    int iType9 = apRef->GetFormType();
    if (apRef->IsReference())
    {
        RegRef* pRef6 = apRef;
        RegPoint _kPos;
        RegPoint kRotX;
        int iIndex6 = 0;
        void* pWorldX = 0;
        void* pCellB = 0;
        if (pRef6->GetPosition(&_kPos, &kRotX, &iIndex6, 0))
            FUN_00846190(iIndex6, &pWorldX, &pCellB);
        else if ((pCellB = pRef6->FUN_00575d70()) != 0)
            _kPos = pRef6->GetPos();
        else
            pWorldX = pRef6->FUN_008d6f30();
        if (pCellB)
        {
            int iX8 = FUN_00406d90(_kPos.x) >> 12;
            int kIY = FUN_00406d90(_kPos.y) >> 12;
            EnsureObjectAndCall(pCellB, iX8, kIY, apRef, 0, aiArg);
        }
        else if (pWorldX)
            ProcessCell(pWorldX, apRef, 0, aiArg);
    }
    else if (iType9 == 0x43)
    {
        RegRef* pLandRef3 = apRef;
        RegLand* pLand4 = pLandRef3->FUN_0059bb30();
        void* pLandCell9 = pLand4 ? pLand4->FUN_0054ddd0() : 0;
        if (pLandCell9)
            EnsureObjectAndCall(pLandCell9, pLand4->FUN_00544c30(), pLand4->FUN_00544c60(), apRef, 0, aiArg);
        else if (pLand4)
            ProcessCell(pLand4, apRef, 0, aiArg);
    }
    else if (iType9 == 0x39)
        ProcessCell(apRef, apRef, 0, aiArg);
    else if (iType9 == 0x41)
        ;
    else
    {
        int iKey8 = g_aRegFormTypes[apRef->GetFormType()].iKey;
        RegList* pList5 = 0;
        if (!GetAt(iKey8, &pList5))
        {
            pList5 = new RegList;
            FUN_00844700(iKey8, pList5);
        }
        pList5->ProcessRef(apRef, 0, aiArg);
        iCount++;
    }
}

void FUN_00845cc0(const char* fmt, ...);

struct ExtendedForm : TESForm
{
    BSSimpleList<TESFile*>* GetSourceFiles();
    unsigned int GetFormID();

    virtual void vfn_61();
    virtual void vfn_62();
    virtual void vfn_63();
    virtual void vfn_64();
    virtual void vfn_65();
    virtual void vfn_66();
    virtual void vfn_67();
    virtual void vfn_68();
    virtual void vfn_69();
    virtual void vfn_70();
    virtual void vfn_71();
    virtual void vfn_72();
    virtual void vfn_73();
    virtual void vfn_74();
    virtual void vfn_75();
    virtual const char* GetFormDisplayName();
};

struct ExtendedFileMap : FUN_00842180
{
    void EnsureObjectAndCall(ExtendedForm* form, unsigned int arg2, unsigned int arg3, unsigned int zero,
                             unsigned int arg4, unsigned int arg5);
};

struct ReconstructMapHelper : BGSReconstructFormsInAllFilesMap
{
    TESFile* FUN_00843fe0(BSSimpleList<TESFile*>* apFileList, unsigned int arg4);
    bool GetAt(TESFile* key, ExtendedFileMap*& val);
    void SetAt(TESFile* key, ExtendedFileMap* val);
    void FUN_008438b0(ExtendedForm* form, unsigned int arg2, unsigned int arg3, unsigned int arg4, unsigned int arg5);
};

// Resolves the form's source file, creates or fetches its ExtendedFileMap, adds the reference to it, and increments iCount; logs an error if no file is found.
// @fnv 0x008438b0
void ReconstructMapHelper::FUN_008438b0(ExtendedForm* form, unsigned int arg2, unsigned int arg3, unsigned int arg4,
                                        unsigned int arg5)
{
    if (!form)
        return;

    TESFile* file = this->FUN_00843fe0(form->GetSourceFiles(), arg4);
    if (!file)
    {
        FUN_00845cc0("Worldspace %08X %s with no file passed to BGSReconstructFormsInAllFilesMap::AddReference()",
                     form->GetFormID(), form->GetFormDisplayName());
        return;
    }

    ExtendedFileMap* subMap = 0;
    if (!this->GetAt(file, subMap))
    {
        subMap = new ExtendedFileMap();
        this->SetAt(file, subMap);
    }
    subMap->EnsureObjectAndCall(form, arg2, arg3, 0, arg4, arg5);
    ++this->iCount;
}

namespace fnv_00843c90 {
struct SceneNode
{
    float GetFloatAt64();
};
struct ObjectBaseView
{
    bool FUN_00549580() const;
};
struct ReferenceView;
struct EnableState
{
    void FUN_006fcfa0();
};
struct WorldSpaceView
{
    EnableState* FUN_00586170(ReferenceView*, bool);
};
struct ActorBaseView
{
    void FUN_005f9e00(ReferenceView*, bool, bool, bool);
    void FUN_006047c0(ReferenceView*, bool, bool, bool, bool);
};
struct ProcessView
{
    virtual ~ProcessView();
};
struct FUN_00906dc0 : ProcessView
{
    FUN_00906dc0();
    unsigned int field_04;
    unsigned int field_08;
    unsigned int field_0c;
    unsigned int field_10;
    unsigned int field_14;
    unsigned int field_18;
    unsigned int field_1c;
    unsigned int field_20;
    unsigned int field_24;
    unsigned int field_28;
    unsigned int field_2c;
    unsigned int field_30;
    unsigned int field_34;
    unsigned int field_38;
    unsigned int field_3c;
    unsigned int field_40;
    unsigned int field_44;
    unsigned int field_48;
    unsigned int field_4c;
    unsigned int field_50;
    unsigned int field_54;
    unsigned int field_58;
    unsigned int field_5c;
    unsigned int field_60;
    unsigned int field_64;
    unsigned int field_68;
    unsigned int field_6c;
    unsigned int field_70;
    unsigned int field_74;
    unsigned int field_78;
    unsigned int field_7c;
    unsigned int field_80;
    unsigned int field_84;
    unsigned int field_88;
    unsigned int field_8c;
    unsigned int field_90;
    unsigned int field_94;
    unsigned int field_98;
    unsigned int field_9c;
    unsigned int field_a0;
    unsigned int field_a4;
    unsigned int field_a8;
    unsigned int field_ac;
    unsigned int field_b0;
};
struct SecondaryForm
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void Reset(int);
};
struct ExtendedForm : TESForm
{
    unsigned int field_04;
    unsigned int field_08;
    unsigned int field_0c;
    unsigned int field_10;
    unsigned int field_14;
    unsigned int field_18;
    unsigned int field_1c;
    unsigned int field_20;
    unsigned int field_24;
    unsigned int field_28;
    unsigned int field_2c;
    virtual void slot61();
    virtual bool IsSecondaryForm();
};
struct MultipleForm : ExtendedForm, SecondaryForm
{
};
struct ReferenceView : ExtendedForm
{
    virtual bool IsMobile();
    virtual bool IsActor();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual SceneNode* GetSceneNode();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual void slot125();
    virtual void slot126();
    virtual void slot127();
    virtual void slot128();
    virtual void slot129();
    virtual void slot130();
    virtual void slot131();
    virtual void slot132();
    virtual void slot133();
    virtual void slot134();
    virtual bool IsCreature();
    virtual void slot136();
    virtual void slot137();
    virtual void slot138();
    virtual void slot139();
    virtual void slot140();
    virtual void slot141();
    virtual void slot142();
    virtual void slot143();
    virtual void slot144();
    virtual void slot145();
    virtual void slot146();
    virtual void slot147();
    virtual void slot148();
    virtual void slot149();
    virtual void slot150();
    virtual void slot151();
    virtual void InitializeProcess();
    float FUN_00567400();
    float FUN_00598040();
    void FUN_00567490(float);
    ObjectBaseView* FUN_007af430();
    bool FUN_00440da0();
    WorldSpaceView* FUN_00575d70();
    bool FUN_00437b90();
    ProcessView* FUN_008d8520();
    int FUN_00931850();
    void FUN_00407800(ProcessView*);
    ActorBaseView* FUN_004181e0();
};
struct ActorDeletionQueue
{
    void FUN_0096d470(ReferenceView*, int);
};
extern ActorDeletionQueue DAT_011e0e80;
struct SaveLoadView
{
    void FUN_0084a520(ReferenceView*);
};
struct ReconstructDataView : ChangedFormRecord
{
    bool FUN_00461580(unsigned int);
};
struct NavInfoView
{
    void FUN_00693ef0(bool);
};
struct NavFormView : TESForm
{
    int FUN_00401170();
    NavInfoView* FUN_0068efb0();
    bool FUN_00440da0();
};
struct ReconstructionWorker
{
    void ReconstructForm(ReconstructDataView* data);
};
// @fnv 0x00843c90
void ReconstructionWorker::ReconstructForm(ReconstructDataView* data)
{
    if (data->pForm->GetIsReference())
    {
        ReferenceView* reference = (ReferenceView*)data->pForm;
        SceneNode* sceneNode = reference->GetSceneNode();
        if (sceneNode && sceneNode->GetFloatAt64() != reference->FUN_00567400())
            reference->FUN_00567490(reference->FUN_00598040());
        if (data->FUN_00461580(8) && reference->FUN_007af430()->FUN_00549580() && reference->FUN_00440da0())
        {
            WorldSpaceView* world = reference->FUN_00575d70();
            if (world)
                world->FUN_00586170(reference, true)->FUN_006fcfa0();
        }
        if (reference->IsMobile())
        {
            ReferenceView* mobile = reference;
            if (mobile->FUN_00437b90())
            {
                if (data->FUN_00461580(8) && mobile->FUN_008d8520())
                {
                    DAT_011e0e80.FUN_0096d470(mobile, mobile->FUN_00931850());
                    delete mobile->FUN_008d8520();
                    mobile->FUN_00407800(0);
                }
            }
            else if (!mobile->FUN_008d8520())
            {
                mobile->FUN_00407800(new FUN_00906dc0);
                mobile->InitializeProcess();
            }
            if (mobile->IsActor())
            {
                ReferenceView* actor = mobile;
                ((SaveLoadView*)g_BGSSaveLoadGame)->FUN_0084a520(actor);
                if (data->FUN_00461580(8) && actor->GetSceneNode())
                {
                    if (actor->IsCreature())
                    {
                        ActorBaseView* creatureBase = actor->FUN_004181e0();
                        creatureBase->FUN_005f9e00(actor, true, true, true);
                    }
                    else
                    {
                        ActorBaseView* npcBase = actor->FUN_004181e0();
                        npcBase->FUN_006047c0(actor, true, true, false, true);
                    }
                }
            }
        }
    }
    else if (((ExtendedForm*)data->pForm)->IsSecondaryForm())
    {
        MultipleForm* form = (MultipleForm*)data->pForm;
        SecondaryForm* secondary = form;
        secondary->Reset(0);
    }
    else if (((NavFormView*)data->pForm)->FUN_00401170() == 0x43)
    {
        NavFormView* pNavForm = (NavFormView*)data->pForm;
        if (pNavForm->FUN_0068efb0())
            pNavForm->FUN_0068efb0()->FUN_00693ef0(pNavForm->FUN_00440da0());
    }
}
}  // namespace fnv_00843c90

class B844F00Allocator;

class B844F00MemoryManager
{
  public:
    B844F00Allocator* GetDefaultAllocator();
};

B844F00MemoryManager* B844F00GetMemoryManager();

class B844F00Base
{
  public:
    B844F00Base();
    virtual ~B844F00Base();

    void Init(int iSize, int iGrowBy);

    int unk04;
    int unk08;
    int unk0C;
    B844F00Allocator* m_pHeapAllocator;
};

class FUN_00844f00_cls : public B844F00Base
{
  public:
    FUN_00844f00_cls(int iSize, int iGrowBy, B844F00Allocator* pkAllocator);
    virtual ~FUN_00844f00_cls();
};

// Stores the given allocator, or the memory manager's default allocator when none is given, then calls Init with the size and grow-by values.
// @fnv 0x00844f00
FUN_00844f00_cls::FUN_00844f00_cls(int iSize, int iGrowBy, B844F00Allocator* pkAllocator)
{
    m_pHeapAllocator = pkAllocator ? pkAllocator : B844F00GetMemoryManager()->GetDefaultAllocator();
    Init(iSize, iGrowBy);
}

struct Val8443
{
    int a;
    int b;
};
struct Item8443
{
    Item8443* m_pkNext;
    unsigned int m_key;
    Val8443 m_val;
};
class FUN_8443Map
{
  public:
    virtual ~FUN_8443Map();
    virtual unsigned int KeyToHashIndex(unsigned int key);
    virtual bool IsKeysEqual(unsigned int key1, unsigned int key2);
    unsigned int m_uiHashSize;
    Item8443** m_ppkHashTable;
    bool Lookup(unsigned int key, Val8443& val);
};
// Hashes the key, walks the bucket chain comparing keys, and copies the matching item's value into val, returning whether a match was found.
// @fnv 0x008443f0
bool FUN_8443Map::Lookup(unsigned int key, Val8443& val)
{
    unsigned int uiIndex = KeyToHashIndex(key);
    Item8443* pkItem = m_ppkHashTable[uiIndex];
    while (pkItem)
    {
        if (IsKeysEqual(key, pkItem->m_key))
        {
            val = pkItem->m_val;
            return true;
        }
        pkItem = pkItem->m_pkNext;
    }
    return false;
}

class FUN_008444d0
{
  public:
    virtual ~FUN_008444d0();
};
class FUN_00844470 : public FUN_008444d0
{
  public:
    void FUN_00438af0();
    virtual ~FUN_00844470();
};
// Destructor that calls FUN_00438af0 before the object is destroyed.
// @fnv 0x00844470
FUN_00844470::~FUN_00844470()
{
    FUN_00438af0();
}

// Prior reconstruction by another contributor (2026-10-23); unverified; attribution retained.

struct RebuildFile;

struct RebuildForm
{
    unsigned int FUN_0084e3a0();
};

struct RebuildMap;

struct RebuildResult
{

    RebuildForm* form;
    RebuildMap* recordC;

    RebuildResult();
    RebuildResult(RebuildForm*, RebuildMap*);

    bool FUN_005ca4f0();
    void ClearFields();
};

struct RebuildHeader
{
    unsigned int type, sizeXA, label, group, formId4;
};

struct RebuildFile
{

    void ResetFileState(bool);
    RebuildHeader* FUN_00462270();
    void FUN_00472150(bool);
    void FUN_00473660();
    bool FUN_00471ca0();

    unsigned int FUN_004726b0();
    void GetChunkData(void*, unsigned int);
    bool FUN_00401680();
    bool FUN_004726f0();
    void SkipCurrentForm();

    unsigned int FUN_00467bb0();
    void FUN_004723a0(RebuildForm*);
};

struct RebuildMap
{

    bool GetAt(unsigned int, RebuildMap**);

    bool HasFlagInAnyFile(int);
    bool FUN_00452420(unsigned int);
    bool FUN_00843150();

    RebuildMap* FUN_0044edb0();
    void FUN_00841320(unsigned int);
    bool Lookup(unsigned int, RebuildResult*);
};

struct RebuildQueue
{

    unsigned int unk00, unk04, unk08, unk0c, unk10;

    RebuildQueue();
    ~RebuildQueue();

    void ConstructAndForward(unsigned int, RebuildMap*);

    unsigned int FUN_0044ddc0();
    RebuildResult* FUN_00844160(unsigned int);
};

struct RebuildCoordinates
{
    int x, y, z;
    RebuildCoordinates();
    void FUN_00462230();
};

struct RebuildOutput
{
    void FUN_00843270(RebuildResult*);
};

struct RebuildLoader
{
    void FUN_00467bd0(RebuildFile*, int, RebuildForm*, bool);
};

void ResolveFormID(unsigned int*, RebuildFile*);

unsigned int PackShortPair(unsigned short, unsigned short);

RebuildForm* LookupFormByID(unsigned int);

void* FUN_00403d30(void*, int, unsigned int);

void FUN_00845cc0(const char*, ...);

const char* FindFormEnumIndex(unsigned int);
const char* GetStringForByte(const char*);

extern unsigned int DAT_01187014, DAT_01187020, DAT_011872b4, DAT_01187314, DAT_011873c8;

extern RebuildForm* DAT_011c3f30;

extern RebuildLoader* DAT_011c3f2c;

struct RebuildRoot : RebuildMap
{

    unsigned int unk00, unk04, unk08, unk0c;

    RebuildMap* defaultMap;
    RebuildMap* worlds;
    unsigned int count;

    void RebuildForms(RebuildFile*, RebuildOutput*);
};

// Walks a RebuildFile, resolving world/block/record context and reconstructing forms into output, queueing pending results as needed.
// @fnv 0x008427f0
void RebuildRoot::RebuildForms(RebuildFile* file, RebuildOutput* output)

{

    if (!count)
        return;

    file->ResetFileState(true);

    RebuildHeader* pData7 = file->FUN_00462270();

    while (pData7->type == DAT_01187014)
        file->FUN_00472150(true);

    RebuildMap* world8 = 0;

    RebuildMap* block3 = 0;

    RebuildMap* subBlock = 0;

    RebuildMap* recordC = 0;

    unsigned int idA = 0;
    unsigned int formId4 = 0;

    DAT_011c3f30 = 0;

    bool cached = file->FUN_00471ca0();

    unsigned int restoredA = 0;

    RebuildQueue queued3;

    unsigned int next4 = 0;

    unsigned int groupEndA = 0;

    bool pending4 = false;

    while (pData7->type && restoredA < count)
    {

        RebuildResult result;

        if (pData7->type == DAT_01187020)
        {

            if (pData7->label == DAT_011872b4 || pData7->label == DAT_01187314)
            {

                world8 = 0;

                bool isWorld = pData7->label == DAT_01187314;

                if (isWorld)
                {

                    if (worlds)
                        file->FUN_00472150(true);

                    else
                        file->FUN_00473660();
                }
                else
                {

                    if (defaultMap)
                    {
                        world8 = defaultMap;
                        file->FUN_00472150(true);
                    }

                    else
                        file->FUN_00473660();
                }

                block3 = 0;
                subBlock = 0;
                recordC = 0;
            }
            else if (pData7->group)
            {

                switch (pData7->group)
                {

                case 1: {

                    unsigned int id = pData7->label;

                    ResolveFormID(&id, file);

                    if (worlds->GetAt(id, &world8))
                    {

                        if (cached && world8->HasFlagInAnyFile(5))
                            queued3.ConstructAndForward(pData7->formId4, 0);

                        file->FUN_00472150(true);
                    }
                    else
                        file->FUN_00473660();

                    block3 = 0;
                    subBlock = 0;
                    recordC = 0;
                }
                break;

                case 2:
                case 4:

                    if (world8->GetAt(pData7->label, &block3))
                        file->FUN_00472150(true);

                    else
                        file->FUN_00473660();

                    subBlock = 0;
                    recordC = 0;

                    break;

                case 3:
                case 5:

                    if (block3->GetAt(pData7->label, &subBlock))
                        file->FUN_00472150(true);

                    else
                        file->FUN_00473660();

                    recordC = 0;

                    break;

                case 6:

                    if (recordC)
                    {

                        bool persistent = recordC->FUN_00452420(2);

                        bool temp = recordC->FUN_00452420(4);

                        if (cached && !idA && temp)
                        {

                            queued3.ConstructAndForward(pData7->formId4, recordC);
                            temp = false;
                        }

                        if (persistent || temp)
                            file->FUN_00472150(true);

                        else
                            file->FUN_00473660();
                    }
                    else
                        file->FUN_00473660();

                    break;

                case 8:

                    if (recordC->FUN_00452420(2))
                        file->FUN_00472150(true);

                    else
                        file->FUN_00473660();

                    break;

                case 9:

                    if (recordC->FUN_00452420(4))
                        file->FUN_00472150(true);

                    else
                        file->FUN_00473660();

                    break;

                default:
                    file->FUN_00473660();
                }
            }
            else
            {

                if (GetAt(pData7->label, &recordC))
                    file->FUN_00472150(true);

                else
                    file->FUN_00473660();
            }
        }
        else if (pData7->type == DAT_01187314)
        {

            idA = pData7->group;

            file->FUN_00472150(true);
        }
        else if (pData7->type == DAT_011872b4)
        {

            if (subBlock)
            {

                formId4 = pData7->group;

                unsigned int key = formId4;

                if (world8 && world8->FUN_00843150())
                {

                    RebuildCoordinates coords9;

                    FUN_00403d30(&coords9, 0, 12);

                    unsigned int type3 = file->FUN_004726b0();

                    while (type3)
                    {

                        if (type3 == 0x434c4358)
                        {

                            file->GetChunkData(&coords9, 12);

                            if (file->FUN_00401680())
                                coords9.FUN_00462230();

                            break;
                        }
                        type3 = file->FUN_004726f0() ? file->FUN_004726b0() : 0;
                    }

                    file->SkipCurrentForm();

                    key = PackShortPair((unsigned short)coords9.x, (unsigned short)coords9.y);
                }

                DAT_011c3f30 = 0;

                if (subBlock->GetAt(key, &recordC))
                {

                    if (recordC->FUN_00452420(1))
                    {

                        DAT_011c3f2c->FUN_00467bd0(file, 0, 0, false);

                        file->FUN_00472150(true);

                        RebuildForm* form = LookupFormByID(formId4);

                        if (form)
                        {

                            RebuildResult cell(form, recordC->FUN_0044edb0());

                            output->FUN_00843270(&cell);
                        }
                        else
                            FUN_00845cc0("Cell with Form ID %08X was not able to be reconstructed", formId4);

                        ++restoredA;
                    }
                    else
                        file->FUN_00472150(true);
                }
                else
                    file->FUN_00472150(true);
            }
            else
            {

                recordC = world8->FUN_0044edb0();

                formId4 = pData7->group;

                DAT_011c3f30 = 0;

                file->FUN_00472150(true);
            }
        }
        else if (pData7->type == DAT_011873c8)
        {

            unsigned int id = pData7->group;

            if (id == -1 || id == -2)
            {

                if (queued3.FUN_0044ddc0())
                {

                    result = *queued3.FUN_00844160(next4++);

                    pending4 = true;
                }
                else
                    pData7->type = 0;
            }
            else
                file->FUN_00472150(true);
        }
        else
        {

            RebuildResult item;

            unsigned int id = pData7->group;

            recordC->FUN_00841320(0x10000);

            if (recordC->Lookup(id, &item))
            {

                if (formId4 && (!DAT_011c3f30 || DAT_011c3f30->FUN_0084e3a0() != formId4))
                    DAT_011c3f30 = LookupFormByID(formId4);

                DAT_011c3f2c->FUN_00467bd0(file, 0, item.form, true);

                file->FUN_00472150(true);

                if (!item.form)
                    item.form = LookupFormByID(id);

                if (item.form)
                    output->FUN_00843270(&item);

                else
                    FUN_00845cc0("Form %08X with type %s was not able to be reconstructed", id,
                                 GetStringForByte(FindFormEnumIndex(pData7->type)));

                ++restoredA;
            }
            else
                file->FUN_00472150(true);
        }

        if (groupEndA && groupEndA <= file->FUN_00467bb0())
        {

            if (queued3.FUN_0044ddc0() > next4)
                result = *queued3.FUN_00844160(next4++);

            else
                pData7->type = 0;
        }

        if (result.FUN_005ca4f0())
        {

            file->FUN_004723a0(result.form);

            unsigned int sizeXA = 0;

            unsigned int key17 = 0;

            if (pData7->group == 1)
            {

                key17 = pData7->label;

                sizeXA = pData7->sizeXA;

                file->FUN_00472150(true);
            }
            else
                sizeXA = pData7->sizeXA;

            world8 = 0;
            block3 = 0;
            subBlock = 0;
            recordC = 0;
            formId4 = 0;
            idA = 0;

            groupEndA = file->FUN_00467bb0() + sizeXA;

            if (key17)
            {

                idA = key17;

                worlds->GetAt(idA, &world8);
            }
            else
            {

                recordC = result.recordC;

                formId4 = pData7->label;
            }

            result.ClearFields();

            if (idA && pData7->group == 9)
                file->FUN_00473660();
        }
    }

    DAT_011c3f30 = 0;
}

struct MapValue41f
{
    virtual ~MapValue41f();
};
struct MapBase41f
{
    virtual ~MapBase41f();
};
struct MapOwner841 : MapBase41f
{
    void* FUN_004b9ba0();
    void FUN_006b7f20(void*& pos, unsigned int& key, MapValue41f*& data);
    virtual ~MapOwner841();
};
// Iterates the map via FUN_004b9ba0 and FUN_006b7f20, deleting each MapValue41f data entry.
// @fnv 0x00841f00
MapOwner841::~MapOwner841()
{
    void* pos = FUN_004b9ba0();
    while (pos)
    {
        unsigned int key = 0;
        MapValue41f* data = 0;
        FUN_006b7f20(pos, key, data);
        delete data;
    }
}

struct ReconstructCellEntry : FUN_00841190
{
    void AddFlags(int aiFlags);
    void SetData(void* apCell, unsigned int auiArg1, unsigned int auiArg2);
};

struct ReconstructCell
{
    bool IsInterior();
    unsigned int GetFormIDKey();
    int GetPosX();
    int GetPosY();
};

int __cdecl TESWorldSpace_GetKeyForCellCoord(short x, short y);

struct ReconstructCellMap
{
    bool GetAt(unsigned int key, ReconstructCellEntry*& entry) const;
    void SetAt(unsigned int key, ReconstructCellEntry* entry);
};

struct BGSReconstructCellsMapImpl : ReconstructCellMap
{
    void FUN_00841460(ReconstructCell* apCell, ReconstructCell* apOther, unsigned int auiArg1, unsigned int auiArg2);
};

// Computes a key for apCell, creates a ReconstructCellEntry in the map if missing, then adds flags or stores apOther with auiArg1 and auiArg2.
// @fnv 0x00841460
void BGSReconstructCellsMapImpl::FUN_00841460(ReconstructCell* apCell, ReconstructCell* apOther, unsigned int auiArg1,
                                              unsigned int auiArg2)
{
    unsigned int uiKey4 = 0;
    if (apCell->IsInterior())
        uiKey4 = apCell->GetFormIDKey();
    else
        uiKey4 = TESWorldSpace_GetKeyForCellCoord(apCell->GetPosX(), apCell->GetPosY());

    ReconstructCellEntry* pEntry = 0;
    if (!GetAt(uiKey4, pEntry))
    {
        pEntry = (ReconstructCellEntry*)new FUN_00841190;
        SetAt(uiKey4, pEntry);
    }

    if (apCell == apOther)
    {
        pEntry->AddFlags(1);
        pEntry->AddFlags(auiArg2);
    }
    else
    {
        pEntry->SetData(apOther, auiArg1, auiArg2);
    }
}

void FUN_00845cc0(const char* apFormat, ...);
struct FUN_00843750_Form : public TESForm
{
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
    virtual const char* GetEditorID();
    unsigned int FUN_0084e3a0();
    BSSimpleList<TESFile*>* FUN_00460140();
    FUN_00843750_Form* FUN_0054ddd0();
};
bool __fastcall FUN_00425fd0(FUN_00843750_Form* apForm);
struct FUN_00842600_shell : public FUN_00842180
{
    void ProcessCell(FUN_00843750_Form* apForm, int aiUnused, unsigned int auiArg1, unsigned int auiArg2);
};
struct FUN_00843750_shell : public BGSReconstructFormsInAllFilesMap
{
    bool GetAt(TESFile* apFile, FUN_00842180*& rpMap) const;
    void FUN_00844700(TESFile* apFile, FUN_00842180* apMap);
    void FUN_00843750(FUN_00843750_Form* apRef, unsigned int auiArg1, unsigned int auiArg2);
};
// Adds a form reference to the per-file map, creating the map if needed, and increments iCount.
// @fnv 0x00843750
void FUN_00843750_shell::FUN_00843750(FUN_00843750_Form* apRef, unsigned int auiArg1, unsigned int auiArg2)
{
    if (!apRef)
        return;
    TESFile* pFile = 0;
    if (FUN_00425fd0(apRef))
        pFile = ((FUN_00843fe0_Holder*)this)->FUN_00843fe0(apRef->FUN_00460140(), auiArg1);
    else
        pFile = ((FUN_00843fe0_Holder*)this)->FUN_00843fe0(apRef->FUN_0054ddd0()->FUN_00460140(), auiArg1);
    if (!pFile)
    {
        FUN_00845cc0("Cell %08X %s with no file passed to BGSReconstructFormsInAllFilesMap::AddReference()",
                     apRef->FUN_0084e3a0(), apRef->GetEditorID());
        return;
    }
    FUN_00842180* pFileMap = 0;
    if (!GetAt(pFile, pFileMap))
    {
        pFileMap = new FUN_00842180;
        FUN_00844700(pFile, pFileMap);
    }
    ((FUN_00842600_shell*)pFileMap)->ProcessCell(apRef, 0, auiArg1, auiArg2);
    iCount++;
}

extern "C" void _Deallocate(void*);

struct ReconstructMapDeletingView : BGSReconstructFormsInAllFilesMap
{
    void* __thiscall FUN_00843440(unsigned int flags);
};

// Destroys the BGSReconstructFormsInAllFilesMap base and deallocates the object when flags has bit 0 set.
// @fnv 0x00843440
void* __thiscall ReconstructMapDeletingView::FUN_00843440(unsigned int flags)
{
    BGSReconstructFormsInAllFilesMap::~BGSReconstructFormsInAllFilesMap();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
