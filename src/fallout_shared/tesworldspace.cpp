// fallout_shared/tesworldspace.cpp: TESWorldSpace, TESObjectCELL, TESRegion, InterfaceManager and more (90 functions)

#include "tesworldspace_packet.h"
// @fnv 0x00425fd0
bool TESObjectCELL::IsCellInterior() const
{
    return (flags & 1) ? true : false;
}
// Sets the world space's map name from the given string and returns true.
// @fnv 0x00583330
bool TESWorldSpace::SetDateTimeText(const char* name)
{
    mapName.Set(name, 0);
    return true;
}
// Returns the terrain manager of the parent world space if one exists, otherwise this world space's own terrain.
// @fnv 0x00586170
BGSTerrainManager* TESWorldSpace::GetWorldTerrainManager()
{
    if (GetParentWorld(USE_LAND))
        return GetParentWorld(USE_LAND)->GetWorldTerrainManager();
    return terrain;
}
// Returns parent if it exists and GetParentUseFlag(flag) is set, otherwise returns null.
// @fnv 0x00586390
TESWorldSpace* TESWorldSpace::GetParentWorld(PARENT_USE_FLAG aeParentUseFlag)
{
    if (parent && !GetParentUseFlag(aeParentUseFlag))
        return 0;
    return parent;
}
// Looks up key in cellMap and returns the stored reference cast to TESObjectCELL, or null if not found.
// @fnv 0x00587630
TESObjectCELL* TESWorldSpace::GetCellByKey(unsigned int key)
{
    TESObjectREFR* cell = 0;
    if (cellMap->GetAt(key, cell))
        return (TESObjectCELL*)cell;
    return 0;
}
// If ref is non-null and not temporary, creates a persistent cell and adds ref to it.
// @fnv 0x00587ff0
void TESWorldSpace::AddPersistentReference(TESObjectREFR* ref)
{
    if (ref && !ref->IsTemporary())
    {
        TESObjectCELL* cell = CreatePersistentCell();
        cell->AddReference(ref, false);
    }
}
// @fnv 0x004f1260
void TESRegion::AssignWorldSpace(TESWorldSpace* apWorldSpace)
{
    world = apWorldSpace;
    if (world && IsConstantGlobal() && !g_dataHandler->LoadDescriptionForForm())
        world->SetHasRegions(true);
}
// @fnv 0x00473ff0
bool TESWorldSpace::IsFormIDOwnedByFile(unsigned int key, TESFile* file)
{
    bool result = true;
    if (DAT_011c40b0 && key)
    {
        TESObjectREFR* value = 0;
        if (DAT_011c40b0->GetAt(key, value) && value)
        {
            TESFile* parent = file->GetThreadSafeRootFile();
            if (!parent)
                parent = file;
            if (value != (TESObjectREFR*)parent)
                result = false;
        }
    }
    return result;
}
// Clears night and looping sounds, effect shader, calls three helpers, resets the full name and zeroes 16 bytes at offset 0x80.
// @fnv 0x00586480
void TESWorldSpace::ClearWorldSpaceReferences()
{
    ((BGSAcousticSpace*)this)->SetNightSound(0);
    ((TESObjectACTI*)this)->SetLoopingSound(0);
    ((EffectSetting*)this)->SetEffectShader(0);
    FUN_00584150(0.0f);
    FUN_00586110(DAT_01031920);
    FUN_00586130(0.0f);
    ((TESFullName*)((char*)this + 0x24))->SetFullName(0);
    memset((char*)this + 0x80, 0, 16);
}
// Validates x and y are within -32768..32767, builds a key from them, and looks up the cell in cellMap, returning it or null.
// @fnv 0x005875a0
TESObjectCELL* TESWorldSpace::GetCellAtGridPosition(int x, int y)
{
    if (x > 32767 || y > 32767 || x < -32768 || y < -32768)
    {
        Warning(DAT_010187a0, -32768, 32767);
        return 0;
    }
    TESObjectREFR* pCell;
    int iKey = BuildCellKey((unsigned short)x, (unsigned short)y);
    pCell = 0;
    if (cellMap->GetAt(iKey, pCell))
        return (TESObjectCELL*)pCell;
    return 0;
}
// @fnv 0x00586150
Tile* InterfaceManager::FUN_00586150()
{
    return pTile;
}
// @fnv 0x00584bc0
void TESWorldSpace::SetFieldD0(unsigned int value)
{
    fieldD0 = value;
}
// @fnv 0x00586110
void TESWorldSpace::FUN_00586110(float value)
{
    fC8 = value;
}
// @fnv 0x00586130
void TESWorldSpace::FUN_00586130(float value)
{
    fCC = value;
}
// @fnv 0x005861b0
bool TESWorldSpace::GetSmallWorld()
{
    if (flags4C & 1)
        return true;
    return false;
}
// @fnv 0x005862e0
bool TESWorldSpace::IsFlag4C20Set()
{
    if (flags4C & 0x20)
        return true;
    return false;
}
// Sets parent to world and clears field4E when world is null.
// @fnv 0x005863d0
void TESWorldSpace::SetParent(TESWorldSpace* world)
{
    parent = world;
    if (!world)
        field4E = 0;
}
// @fnv 0x00588270
void TESWorldSpace::FUN_00588270(BSSimpleArray<TESObjectREFR*, 1024>& doors)
{
    TESObjectCELL* cell = GetInteriorCell();
    if (cell)
        cell->AppendCellReferences(doors);
}

struct FUN_005861d0_shell : public TESWorldSpace
{
    void SetFlagBit0(bool);
};

// Sets or clears bit 0 of the byte at offset 0x4c on this TESWorldSpace based on abVal.
// @fnv 0x005861d0
void FUN_005861d0_shell::SetFlagBit0(bool abVal)
{
    if (abVal)
        *(unsigned char*)((char*)this + 0x4c) |= 1;
    else
        *(unsigned char*)((char*)this + 0x4c) &= ~1;
}

// Packs two shorts into one int: asX shifted left 16 bits, OR'd with the low 16 bits of asY.
// @fnv 0x00587410
int __cdecl PackShortPair(short asHigh, short asLow)
{
    int key = asHigh;
    key <<= 16;
    key |= (unsigned short)(asLow & 0xFFFF);
    return key;
}

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

int __cdecl TruncateFloatToInt(float);
int __cdecl _FNV_Finite(double);
int __cdecl _FNV_IsNaN(double);

// @fnv 0x00587440
int __cdecl FUN_00587440(const NiPoint3* aCoord)
{
    int icellx;
    int icelly;

    if (!_FNV_Finite(aCoord->x) || !_FNV_Finite(aCoord->y) || !_FNV_Finite(aCoord->z) || _FNV_IsNaN(aCoord->x) ||
        _FNV_IsNaN(aCoord->y) || _FNV_IsNaN(aCoord->z))
    {
        return 0x7fff7fff;
    }

    icellx = TruncateFloatToInt(aCoord->x) >> 12;
    icelly = TruncateFloatToInt(aCoord->y) >> 12;
    return TESWorldSpace::BuildCellKey((short)icellx, (short)icelly);
}

void* __fastcall _FNV_GetObjectReference(void*);
int __fastcall _FNV_GetFormType(void*);

// Returns true if apRef is non-null and its object reference's form type is one of the listed types.
// @fnv 0x00587c80
bool __cdecl FUN_00587c80(void* apRef)
{
    bool bretval = false;
    if (apRef && _FNV_GetObjectReference(apRef))
    {
        switch (_FNV_GetFormType(_FNV_GetObjectReference(apRef)))
        {
        case 0x0d:
        case 0x15:
        case 0x1b:
        case 0x1c:
        case 0x20:
        case 0x21:
        case 0x25:
        case 0x26:
        case 0x27:
        case 0x2c:
        case 0x2d:
            bretval = true;
            break;
        }
    }
    return bretval;
}

struct FUN_00588030_shell : public TESWorldSpace
{
    void FUN_00588030(TESObjectREFR*);
};

struct TESObjectCELL_RemoveReference_Helper : public TESObjectCELL
{
    void RemoveReference(TESObjectREFR*);
};

// If apRef is non-null, gets the interior cell and calls RemoveReference on it with apRef.
// @fnv 0x00588030
void FUN_00588030_shell::FUN_00588030(TESObjectREFR* apRef)
{
    if (apRef)
    {
        TESObjectCELL* poldcell = GetInteriorCell();
        if (poldcell)
        {
            reinterpret_cast<TESObjectCELL_RemoveReference_Helper*>(poldcell)->RemoveReference(apRef);
        }
    }
}

struct FUN_00588b00_shell : public TESWorldSpace
{
    void* GetOrCreateCellOffsetData(TESFile*);
};

void* __cdecl operator new(unsigned int);
extern float const DAT_01015f5c;

class NiPoint2
{
  public:
    float x, y;
    NiPoint2()
    {}
    NiPoint2(float, float);
};

struct OFFSET_DATA_24
{
    unsigned int pCellOffsets;
    NiPoint2 m_kFirstPoint;
    NiPoint2 m_kEndPoint;
    unsigned int uiFileOffset;

    OFFSET_DATA_24();
};

struct DummyPointerMap
{
    bool GetAt(unsigned int, unsigned int&) const;
    void SetAt(unsigned int, unsigned int);
};

// @fnv 0x00588b00
void* FUN_00588b00_shell::GetOrCreateCellOffsetData(TESFile* apFile)
{
    OFFSET_DATA_24* pdata = 0;
    TESFile* pmainfile = apFile;
    while (pmainfile && pmainfile->GetThreadSafeRootFile())
    {
        pmainfile = pmainfile->GetThreadSafeRootFile();
    }
    if (!((DummyPointerMap*)((char*)this + 0xb0))->GetAt((unsigned int)pmainfile, (unsigned int&)pdata) || !pdata)
    {
        pdata = new OFFSET_DATA_24;
        pdata->pCellOffsets = 0;
        pdata->uiFileOffset = 0;
        pdata->m_kFirstPoint = NiPoint2(3.4028234663852886e+38f, 3.4028234663852886e+38f);
        pdata->m_kEndPoint = NiPoint2(DAT_01015f5c, DAT_01015f5c);
        ((DummyPointerMap*)((char*)this + 0xb0))->SetAt((unsigned int)pmainfile, (unsigned int)pdata);
    }
    return pdata;
}

void __fastcall _ref_006815c0(void* pThis);

// Calls _ref_006815c0 on the two sub-objects at offsets 4 and 0xC of pThis and returns pThis.
// @fnv 0x00588c50
char* __fastcall FUN_00588c50(char* pThis)
{
    _ref_006815c0(pThis + 4);
    _ref_006815c0(pThis + 0xC);
    return pThis;
}

extern int DAT_01031fac;

struct FUN_00588fa0_arg
{
    unsigned int val;
};

void __fastcall FUN_005890c0(int* self, FUN_00588fa0_arg a);

// Calls FUN_005890c0 on self, then stores the address of DAT_01031fac into *self and returns self.
// @fnv 0x00588fa0
int* __fastcall FUN_00588fa0(int* self, FUN_00588fa0_arg a)
{
    FUN_005890c0(self, a);
    *self = (int)&DAT_01031fac;
    return self;
}

void __fastcall _ref_00726070(void*);

// @fnv 0x006698d0
void __fastcall FUN_006698d0(char* pThis)
{
    _ref_00726070(pThis + 0x6c);
}

struct FUN_005832f0_shell : public TESForm
{
    char* FUN_005832f0();
};

struct Flt
{
    operator unsigned int() const;
};
// Returns the unsigned int at offset 0xc0 as a char pointer, or an empty string when that value is zero.
// @fnv 0x005832f0
char* FUN_005832f0_shell::FUN_005832f0()
{
    return ((Flt*)((char*)this + 0xc0))->operator unsigned int()
               ? (char*)((Flt*)((char*)this + 0xc0))->operator unsigned int()
               : "";
}

struct FUN_00587670_shell : public TESWorldSpace
{
    bool FUN_00587670(TESObjectCELL*);
};

struct CellH
{
    int GetCellGridX();
    int GetCellGridY();
    bool IsCellPersistent();
};
struct S54de10
{
    void FUN_0054de10(TESWorldSpace*);
};
unsigned int __fastcall _ref_0084e3a0(void*);
// @fnv 0x00587670
bool FUN_00587670_shell::FUN_00587670(TESObjectCELL* apCell)
{
    int key;
    TESObjectCELL* ignore;
    if (!apCell || apCell->IsCellInterior())
        return false;
    if (((CellH*)apCell)->IsCellPersistent())
    {
        if (*(TESObjectCELL**)((char*)this + 0x34))
            return false;
        *(TESObjectCELL**)((char*)this + 0x34) = apCell;
    }
    else
    {
        key = TESWorldSpace::BuildCellKey(((CellH*)apCell)->GetCellGridX(), ((CellH*)apCell)->GetCellGridY());
        if ((*(DummyPointerMap**)((char*)this + 0x30))->GetAt(key, (unsigned int&)ignore))
        {
            Warning("CELLS: Cell (%08X) %s already exists at coord (%i, %i ).", _ref_0084e3a0(ignore),
                    ((const char*(__thiscall*)(TESObjectCELL*))(*(void***)ignore)[0x130 / 4])(ignore),
                    ((CellH*)apCell)->GetCellGridX(), ((CellH*)apCell)->GetCellGridY());
            return false;
        }
        (*(DummyPointerMap**)((char*)this + 0x30))->SetAt(key, (unsigned int)apCell);
    }
    ((S54de10*)apCell)->FUN_0054de10(this);
    return true;
}

struct FUN_00587e40_shell : public TESWorldSpace
{
    void FUN_00587e40(TESObjectREFR*);
};

template <class T> struct BSSimpleList
{
    T item;
    BSSimpleList<T>* next;
    ~BSSimpleList();
    void operator delete(void*);
};
struct ATM
{
    void QueryPerformanceCounter(int);
    void WaitForTasksDuringRendering();
};
extern ATM g_011ca60c;
struct WsH
{
    static int __cdecl GetKeyForWorldCoord(const NiPoint3&);
};
struct ListH
{
    void _ref_00905330(TESObjectREFR**);
    bool _ref_008256d0();
};
struct MapH
{
    bool RemoveAt(unsigned int);
};
bool __cdecl FUN_00587c80(void*);
// @fnv 0x00587e40
void FUN_00587e40_shell::FUN_00587e40(TESObjectREFR* apRef)
{
    unsigned int ikey;
    BSSimpleList<const char*>* preflist;
    if (apRef && !apRef->IsTemporary())
    {
        g_011ca60c.QueryPerformanceCounter(0);
        if (!FUN_00587c80(apRef))
        {
            ((ListH*)((char*)this + 0x60))->_ref_00905330(&apRef);
        }
        else
        {
            ikey = WsH::GetKeyForWorldCoord(
                *((NiPoint3 * (__thiscall*)(TESObjectREFR*))(*(void***)apRef)[0x1f4 / 4])(apRef));
            preflist = 0;
            ((DummyPointerMap*)((char*)this + 0x50))->GetAt(ikey, (unsigned int&)preflist);
            if (preflist)
            {
                ((ListH*)preflist)->_ref_00905330(&apRef);
                if (((ListH*)preflist)->_ref_008256d0())
                {
                    delete preflist;
                    ((MapH*)((char*)this + 0x50))->RemoveAt(ikey);
                }
            }
        }
        g_011ca60c.WaitForTasksDuringRendering();
    }
}

struct FUN_00588070_shell : public TESWorldSpace
{
    TESObjectCELL* GetOrCreateCell();
};

namespace stub {
struct TESObjectCELL
{
    TESObjectCELL();
    char pad[0xe0];
};
}
struct FUN_005516f0_s
{
    void SetFlag400(int);
};
struct FUN_00544630_shell
{
    void ResetCellData();
};

// Returns the TESObjectCELL stored at offset 0x34, creating and initializing it first if it is null.
// @fnv 0x00588070
TESObjectCELL* FUN_00588070_shell::GetOrCreateCell()
{
    if (!*(stub::TESObjectCELL**)((char*)this + 0x34))
    {
        *(stub::TESObjectCELL**)((char*)this + 0x34) = new stub::TESObjectCELL;
        (*(FUN_005516f0_s**)((char*)this + 0x34))->SetFlag400(1);
        (*(FUN_00544630_shell**)((char*)this + 0x34))->ResetCellData();
    }
    return *(TESObjectCELL**)((char*)this + 0x34);
}

struct FileH
{
    bool __thiscall IsMasterFile(void);
    bool __thiscall SetOffset(unsigned int);
    unsigned int __thiscall GetFormID(void);
};

struct FormIDData
{
    unsigned int pad0[5];
    unsigned int formID;
};

extern unsigned int __fastcall _ref_00472660(void*);
extern unsigned int __fastcall _ref_0084e3a0(void*);
extern unsigned char DAT_0118730c;

struct FUN_005858b0_shell
{
    FormIDData* __thiscall FUN_00588a90(FileH* apFile);
    bool IsFileFormIDMatching(FileH* apFile);
};

// @fnv 0x005858b0
bool FUN_005858b0_shell::IsFileFormIDMatching(FileH* apFile)
{
    FormIDData* pdata = FUN_00588a90(apFile);
    if (apFile && apFile->IsMasterFile() && pdata && pdata->formID)
    {
        if (apFile->SetOffset(pdata->formID))
        {
            if (_ref_00472660(apFile) == DAT_0118730c)
            {
                if (apFile->GetFormID() == _ref_0084e3a0(this))
                    return true;
            }
        }
    }
    return false;
}

struct TESClimate
{
    virtual ~TESClimate();  // polymorphic: its RTTI is used (rtti_fix.py)
};

class FUN_00585fe0_shell : public TESWorldSpace
{
  public:
    TESClimate* FUN_00585fe0();
};

// Returns the climate of the parent world if one exists, otherwise the climate stored at offset 0x40 of this world space.
// @fnv 0x00585fe0
TESClimate* FUN_00585fe0_shell::FUN_00585fe0()
{
    if (GetParentWorld(PARENT_USE_FLAG(4)))
        return ((FUN_00585fe0_shell*)GetParentWorld(PARENT_USE_FLAG(4)))->FUN_00585fe0();
    return *reinterpret_cast<TESClimate**>(reinterpret_cast<unsigned char*>(this) + 0x40);
}

struct FUN_00586020_shell
{
    char pad[0x44];
    TESWorldSpace* field44;
    TESWorldSpace* GetParentWorld(TESWorldSpace::PARENT_USE_FLAG);
    TESWorldSpace* GetWorldSpaceOrParentWorld();
};

// Returns field44 if set, otherwise recurses into the parent world space obtained via GetParentWorld with flag 5, or returns null.
// @fnv 0x00586020
TESWorldSpace* FUN_00586020_shell::GetWorldSpaceOrParentWorld()
{
    TESWorldSpace* result = field44;
    if (!result)
    {
        if (GetParentWorld(static_cast<TESWorldSpace::PARENT_USE_FLAG>(5)))
        {
            result =
                reinterpret_cast<FUN_00586020_shell*>(GetParentWorld(static_cast<TESWorldSpace::PARENT_USE_FLAG>(5)))
                    ->GetWorldSpaceOrParentWorld();
        }
    }
    return result;
}

struct FUN_00586210_shell
{
    unsigned char cFlags;
    bool HasFlag2();
};

// @fnv 0x00586210
bool FUN_00586210_shell::HasFlag2()
{
    if (((unsigned char)(*((unsigned char*)this + 0x4c)) & 2))
        return true;
    return false;
}

struct ArrSI
{
    unsigned int GetFlags(void);
    char HasFlag80000();
};

// @fnv 0x00586230
char ArrSI::HasFlag80000()
{
    unsigned int flags = GetFlags();
    if (flags & 0x80000)
        return 1;
    return 0;
}

struct FUN_00586260_shell
{
    bool IsFlag8Set();
};

// @fnv 0x00586260
bool FUN_00586260_shell::IsFlag8Set()
{
    if (((unsigned char*)this)[0x4c] & 8)
        return 1;
    return 0;
}

struct FUN_00586280_shell
{
    unsigned char bFlags;  // +0x4c
    void SetFlag8(bool bFlag);
};

// Sets or clears bit 3 (0x8) of the byte at offset 0x4c on this object based on bFlag.
// @fnv 0x00586280
void FUN_00586280_shell::SetFlag8(bool bFlag)
{
    if (bFlag)
        ((unsigned char*)this)[0x4c] |= 8;
    else
        ((unsigned char*)this)[0x4c] &= ~8;
}

struct FUN_005862c0_shell
{
    unsigned char cFlags;  // +0x4c
    bool IsFlagSet();
};

// @fnv 0x005862c0
bool FUN_005862c0_shell::IsFlagSet()
{
    if (((unsigned char*)((char*)this + 0x4c))[0] & 0x10)
        return 1;
    return 0;
}

struct FUN_00586300_shell
{
    char IsFlag80Set();
};

// Returns 1 if the byte at offset 0x4c has bit 0x80 set, otherwise 0.
// @fnv 0x00586300
char FUN_00586300_shell::IsFlag80Set()
{
    if ((*(unsigned char*)(this + 0x4c) & 0x80) != 0)
        return 1;
    return 0;
}

struct FUN_00586320_shell
{
    bool FUN_00586320();
};

// @fnv 0x00586320
bool FUN_00586320_shell::FUN_00586320()
{
    if ((*(unsigned char*)((char*)this + 0x4c) & 0x40) != 0)
        return false;
    return true;
}

struct FNStub
{
    const char* GetFullName();
};

struct FUN_00586440_shell : TESWorldSpace
{
    const char* FUN_00586440();
};

// Returns the full name of the parent worldspace if one exists, otherwise the full name of this worldspace.
// @fnv 0x00586440
const char* FUN_00586440_shell::FUN_00586440()
{
    if (this->GetParentWorld(static_cast<TESWorldSpace::PARENT_USE_FLAG>(2)))
    {
        return (reinterpret_cast<FNStub*>(
                    reinterpret_cast<char*>(this->GetParentWorld(static_cast<TESWorldSpace::PARENT_USE_FLAG>(2))) +
                    0x24))
            ->GetFullName();
    }
    return (reinterpret_cast<FNStub*>(reinterpret_cast<char*>(this) + 0x24))->GetFullName();
}

struct StartMenu
{
    char const* GetMenuTitle();
};

extern StartMenu g_011ca130;

// @fnv 0x00586980
char const* FUN_00586980()
{
    return g_011ca130.GetMenuTitle();
}

// Splits a 32-bit value into its high and low 16-bit halves, storing the high half in *b and the low half in *c.
// @fnv 0x00587520
void SplitUInt32(unsigned int auiValue, unsigned short* b, unsigned short* c)
{
    *b = (unsigned short)((auiValue >> 0x10) & 0xffff);
    *c = (unsigned short)(auiValue & 0xffff);
}

namespace fnv_00587550 {
extern "C"
{
    int __cdecl TruncateFloatToInt(float);
}

struct NiPoint3
{
    float x;
    float y;
    float z;
};

struct FUN_00587550_shell : TESWorldSpace
{
    TESObjectCELL* FUN_00587550(const NiPoint3& aCoord);
};

// @fnv 0x00587550
TESObjectCELL* FUN_00587550_shell::FUN_00587550(const NiPoint3& aCoord)
{
    int icellx = TruncateFloatToInt(aCoord.x) >> 12;
    int icelly = TruncateFloatToInt(aCoord.y) >> 12;
    return GetCellAtGridPosition(icellx, icelly);
}
}  // namespace fnv_00587550

extern "C"
{
    struct TESWaterForm;
}

extern TESWaterForm* DAT_011ca53c;

// @fnv 0x00586070
TESWaterForm* __fastcall FUN_00586070(TESWorldSpace* apWorldSpace)
{
    if (apWorldSpace->GetParentWorld((TESWorldSpace::PARENT_USE_FLAG)3))
        return FUN_00586070(apWorldSpace->GetParentWorld((TESWorldSpace::PARENT_USE_FLAG)3));
    if (*(TESWorldSpace**)((char*)apWorldSpace + 0x74))
        return (TESWaterForm*)*(TESWorldSpace**)((char*)apWorldSpace + 0x74);
    return DAT_011ca53c;
}

template <class T> class BSSimpleList;

struct FUN_0054b8c0_shell
{
    void AddStaticRefsToList(BSSimpleList<const char*>*);
};

struct FUN_00588520_shell
{
    void FUN_00588520(BSSimpleList<const char*>*);
};

// If list is non-null, gets the interior cell from this world space and forwards the list to the cell's method.
// @fnv 0x00588520
void __thiscall FUN_00588520_shell::FUN_00588520(BSSimpleList<const char*>* list)
{
    if (list)
    {
        TESObjectCELL* cell = ((TESWorldSpace*)this)->GetInteriorCell();
        if (cell)
        {
            ((FUN_0054b8c0_shell*)cell)->AddStaticRefsToList(list);
        }
    }
}

template <int N> struct EndianSizeTag
{
};

void __cdecl BSEndian(int*, EndianSizeTag<2>);
void __cdecl BSEndian(unsigned short*, EndianSizeTag<2>);

struct FUN_005840b0_shell
{
    void __thiscall FUN_005840b0();
};

// Byte-swaps the two ints and four shorts stored in this object via BSEndian.
// @fnv 0x005840b0
void __thiscall FUN_005840b0_shell::FUN_005840b0()
{
    BSEndian((int*)this, EndianSizeTag<2>());
    BSEndian((int*)(this + 4), EndianSizeTag<2>());
    BSEndian((unsigned short*)(this + 8), EndianSizeTag<2>());
    BSEndian((unsigned short*)(this + 0xa), EndianSizeTag<2>());
    BSEndian((unsigned short*)(this + 0xc), EndianSizeTag<2>());
    BSEndian((unsigned short*)(this + 0xe), EndianSizeTag<2>());
}

struct Modifier
{
    void SetValue(float);
};
struct AlphaColor
{
    void FUN_0052ce20(float);
};
struct FUN_004f6fc0_shell
{
    int _a;
    int _b;
    void FUN_004f6fc0();
};
struct FUN_004f6850_shell
{
    void FUN_004f6850(void*, FUN_004f6fc0_shell*, void*);
};
struct FUN_004f6800_shell
{
    void FUN_004f6800(void*, float*, void*);
};
// @fnv 0x004f6800
void FUN_004f6800_shell::FUN_004f6800(void* a1, float* a2, void* a3)
{
    FUN_004f6fc0_shell tmp;
    tmp.FUN_004f6fc0();
    ((AlphaColor*)&tmp)->FUN_0052ce20(a2[0]);
    ((Modifier*)&tmp)->SetValue(a2[1]);
    ((FUN_004f6850_shell*)this)->FUN_004f6850(a1, &tmp, a3);
}

struct FUN_00528560_Host
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual TESObjectCELL* v5(unsigned int) = 0;
    TESObjectCELL* GetCellAtGridCoord(unsigned short, unsigned short);
};
// Computes a grid key from the X and Y coordinates and returns the cell obtained from v5 for that key.
// @fnv 0x00528560
TESObjectCELL* FUN_00528560_Host::GetCellAtGridCoord(unsigned short ausGridX, unsigned short ausGridY)
{
    int key;
    key = TESWorldSpace::BuildCellKey(ausGridX, ausGridY);
    return v5(key);
}

struct FUN_00582e00_host
{
    void FUN_00582e30();
    void* FUN_00582e00(unsigned int);
};
void __cdecl _Deallocate(void*);
// Calls FUN_00582e30, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00582e00
void* FUN_00582e00_host::FUN_00582e00(unsigned int flags)
{
    FUN_00582e30();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct S_00583040
{
    void FUN_006fc980();
    void* FUN_00583040(unsigned int);
};
void _Deallocate(void*);
// Calls FUN_006fc980, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00583040
void* S_00583040::FUN_00583040(unsigned int flags)
{
    FUN_006fc980();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_00584530 {
struct FileH;

struct FormIDData
{
    float f0;
    float f4;
    float f8;
    float fc;
    float f10;
};

struct FUN_005858b0_shell
{
    FormIDData* FUN_00588a90(FileH*);
    int FUN_00584530(FileH* file, int x, int y);
};

// @fnv 0x00584530
int FUN_005858b0_shell::FUN_00584530(FileH* file, int x, int y)
{
    FormIDData* pdata = FUN_00588a90(file);
    if (!pdata)
        return -1;
    int iminX = (int)pdata->f4 >> 12;
    int iminY = (int)pdata->f8 >> 12;
    int imaxX = (int)pdata->fc >> 12;
    int imaxY = (int)pdata->f10 >> 12;
    if (x > imaxX || x < iminX || y > imaxY || y < iminY)
        return -1;
    return (imaxX - iminX + 1) * (y - iminY) + x - iminX;
}
}  // namespace fnv_00584530

class TESWaterForm;
extern TESWaterForm* DAT_011ca53c;
struct FUN_005860c0_shell : TESWorldSpace
{
    TESWaterForm* FUN_005860c0();
};
// @fnv 0x005860c0
TESWaterForm* FUN_005860c0_shell::FUN_005860c0()
{
    if (GetParentWorld(TESWorldSpace::USE_LAND))
        return ((FUN_005860c0_shell*)GetParentWorld(TESWorldSpace::USE_LAND))->FUN_005860c0();
    if (*(TESWaterForm**)((char*)this + 0x78))
        return *(TESWaterForm**)((char*)this + 0x78);
    return DAT_011ca53c;
}

struct Unk00586340
{
    bool FUN_00586340(int);
};
// Returns true if a is outside 0..5 or if the bit for a is set in the 16-bit mask at offset 0x4E of this.
// @fnv 0x00586340
bool Unk00586340::FUN_00586340(int aiIndex)
{
    if (aiIndex >= 0 && aiIndex < 6)
    {
        unsigned char mask = 1 << aiIndex;
        if (*(unsigned short*)((char*)this + 0x4E) & mask)
            return true;
        return false;
    }
    return true;
}

struct PointerPairData;
struct FUN_00586400_shell : TESWorldSpace
{
    PointerPairData* FUN_00586400();
};
// Returns the parent world's result if GetParentWorld(2) is set, otherwise returns this object offset by 0x80.
// @fnv 0x00586400
PointerPairData* FUN_00586400_shell::FUN_00586400()
{
    if (GetParentWorld((PARENT_USE_FLAG)2))
        return ((FUN_00586400_shell*)GetParentWorld((PARENT_USE_FLAG)2))->FUN_00586400();
    return (PointerPairData*)((char*)this + 0x80);
}

namespace fnv_00587760 {
struct CellH
{
    int GetCellGridX();
    int GetCellGridY();
};
struct MapH
{
    bool RemoveAt(unsigned int);
};
struct DummyPointerMap
{
    bool GetAt(unsigned int, unsigned int&) const;
};
struct S54de10
{
    void FUN_0054de10(TESWorldSpace*);
};

struct FUN_00587760_shell : TESWorldSpace
{
    void RemoveCellFromMap(TESObjectCELL* cell);
};

// @fnv 0x00587760
void FUN_00587760_shell::RemoveCellFromMap(TESObjectCELL* cell)
{
    if (!cell || cell->IsCellInterior())
        return;

    unsigned int entry7;
    unsigned int key = TESWorldSpace::BuildCellKey((short)reinterpret_cast<CellH*>(cell)->GetCellGridX(),
                                                   (short)reinterpret_cast<CellH*>(cell)->GetCellGridY());

    if (reinterpret_cast<DummyPointerMap*>(cellMap)->GetAt(key, entry7) &&
        cell == reinterpret_cast<TESObjectCELL*>(entry7))
    {
        reinterpret_cast<MapH*>(cellMap)->RemoveAt(key);
        reinterpret_cast<S54de10*>(cell)->FUN_0054de10(0);
    }
}
}  // namespace fnv_00587760

namespace fnv_00587870 {
struct CellH
{
    int GetCellGridX();
    int GetCellGridY();
};
struct DummyPointerMap
{
    bool GetAt(unsigned int, unsigned int&) const;
};
template <class T> struct BSSimpleList
{
};
struct OverlapHolder
{
    char pad[0x68];
    DummyPointerMap* map68;
    BSSimpleList<TESObjectREFR*>* FUN_00587870(CellH* apCell);
};
// Looks up the cell's key in map68 and returns the stored TESObjectREFR list, or null if map68 is unset.
// @fnv 0x00587870
BSSimpleList<TESObjectREFR*>* OverlapHolder::FUN_00587870(CellH* apCell)
{
    BSSimpleList<TESObjectREFR*>* preflist = 0;
    unsigned int ikey;
    if (map68)
    {
        ikey = TESWorldSpace::BuildCellKey(apCell->GetCellGridX(), apCell->GetCellGridY());
        map68->GetAt(ikey, (unsigned int&)preflist);
    }
    return preflist;
}
}  // namespace fnv_00587870

struct CellCaller
{
    void MoveReferencesToWorldCells(TESWorldSpace*);
};
struct FUN_00588120_host
{
    void FUN_00588120();
};
// Gets the interior cell from this worldspace and, if one exists, calls MoveReferencesToWorldCells on it with this worldspace.
// @fnv 0x00588120
void FUN_00588120_host::FUN_00588120()
{
    TESObjectCELL* cell = ((TESWorldSpace*)this)->GetInteriorCell();
    if (cell)
        ((CellCaller*)cell)->MoveReferencesToWorldCells((TESWorldSpace*)this);
}

struct FUN_005884e0_owner : TESWorldSpace
{
    void FUN_005884e0(TESObjectREFR*);
};
struct CellProxy
{
    void FUN_0054b830(TESObjectREFR*);
};
// If a1 is non-null and the world space has an interior cell, forwards a1 to that cell's FUN_0054b830.
// @fnv 0x005884e0
void FUN_005884e0_owner::FUN_005884e0(TESObjectREFR* apRef)
{
    TESObjectCELL* cell;
    if (apRef != 0)
    {
        cell = GetInteriorCell();
        if (cell != 0)
        {
            reinterpret_cast<CellProxy*>(cell)->FUN_0054b830(apRef);
        }
    }
}

namespace fnv_00588a90 {
struct DummyPointerMap
{
    bool GetAt(unsigned int, unsigned int&) const;
};
struct FormIDData
{
    int dummy;
};
struct TESWorldSpace_shell
{
    FormIDData* FUN_00588a90(TESFile* file);
};
// @fnv 0x00588a90
FormIDData* TESWorldSpace_shell::FUN_00588a90(TESFile* file)
{
    FormIDData* result = 0;
    TESFile* current = file;
    while (current && current->GetThreadSafeRootFile())
        current = current->GetThreadSafeRootFile();
    if (!((DummyPointerMap*)((char*)this + 0xb0))->GetAt((unsigned int)current, (unsigned int&)result))
        result = 0;
    return result;
}
}  // namespace fnv_00588a90

struct BGSCameraPath;
struct BGSCameraShot;
struct NiFormArray;
struct PerkEntryConditionSet;
struct CameraPathManager
{
    void InitializeCameraPaths();
    static BGSCameraPath* GetTextureResourcePath();
    void AddCameraPath(BGSCameraPath*);
    void UpdateCameraPaths();
    void ClearCameraPaths();
    NiFormArray* GetRootPathArray();
    BGSCameraPath* SetCameraPathEnabled(TESObjectREFR*, TESObjectREFR*);
    void* __vecDelDtor(unsigned int);
    char m_kCameraPathArray[24];
    char m_kCameraPathList[16];
};
typedef char _sizecheck_BGSCameraPathManager[sizeof(CameraPathManager) == 40 ? 1 : -1];
struct FUN_0095f530_shell : public CameraPathManager
{
    BGSCameraPath* FUN_0095f530(TESObjectREFR*, TESObjectREFR*);
};

struct Caller_0095f590
{
    BGSCameraPath* __thiscall FUN_0095f590(unsigned int);
};
// @fnv 0x0095f530
BGSCameraPath* FUN_0095f530_shell::FUN_0095f530(TESObjectREFR* apActionRef, TESObjectREFR* apTargetRef)
{
    unsigned char nv;
    if ((unsigned char)apActionRef)
    {
        nv = *(unsigned char*)((char*)this + 0x680) | (unsigned int)apTargetRef;
    }
    else
    {
        nv = (unsigned char)~(unsigned char)apTargetRef;
        nv = *(unsigned char*)((char*)this + 0x680) & nv;
    }
    return ((Caller_0095f590*)this)->FUN_0095f590(nv);
}

namespace fnv_00582c20 {
struct TESFormBase
{
    TESFormBase();
    ~TESFormBase();
    virtual void V();
    int x[5];
};
namespace stand {
struct TESFullName
{
    TESFullName();
    ~TESFullName();
    virtual void V();
    int x[2];
};
}
struct TESTexture
{
    TESTexture();
    ~TESTexture();
    virtual void V();
    int x[2];
};
struct FUN_0057cd10
{
    FUN_0057cd10();
    ~FUN_0057cd10();
    int x;
};
struct FUN_00588fa0
{
    FUN_00588fa0(unsigned int);
    ~FUN_00588fa0();
    int x[4];
};
struct SL
{
    SL();
    ~SL();
    int x[2];
};
struct GO
{
    GO(int);
    ~GO();
    int x;
};
struct FUN_006815c0
{
    float x, y;
    FUN_006815c0();
};
struct FUN_00588fd0
{
    FUN_00588fd0(int);
    ~FUN_00588fd0();
    int x[4];
};
struct StrMem
{
    StrMem();
    ~StrMem();
    int x[2];
};
struct FUN_00589000
{
    FUN_00589000(unsigned int);
    int x[4];
};
struct SFTX
{
    void SetFormType(int);
};
extern float _DAT_01015f5c;
struct FUN_00582c20 : public TESFormBase, public stand::TESFullName, public TESTexture
{
    FUN_00589000* pCellNavMeshInfoMap;
    void* m_pCell;
    FUN_0057cd10 m_kFirstTreeComponent;
    void* m_pThirdTreePointer;
    int pad40[4];
    FUN_00588fa0 m_kSecondTreeComponent;
    SL m_kThirdTreeComponent;
    void* m_pFourthTreePointer;
    GO m_kFourthTreeComponent;
    int pad70[12];
    FUN_006815c0 m_kFirstPoint;
    FUN_006815c0 m_kEndPoint;
    FUN_00588fd0 OffsetDataMap;
    StrMem name;
    int padc8[3];
    TESTexture CanopyShadowTexture;
    TESTexture m_kLeafShadowTexture;
    FUN_00582c20();
    void FUN_00583070();
};

// @fnv 0x00582c20
FUN_00582c20::FUN_00582c20() : m_kSecondTreeComponent(0x25), m_kFourthTreeComponent(0), OffsetDataMap(0x25)
{
    ((SFTX*)this)->SetFormType(0x41);
    m_pThirdTreePointer = 0;
    pCellNavMeshInfoMap = new FUN_00589000(0x25);
    m_pFourthTreePointer = 0;
    m_pCell = 0;
    m_kFirstPoint.y = 3.4028234663852886e+38f;
    m_kFirstPoint.x = 3.4028234663852886e+38f;
    m_kEndPoint.y = _DAT_01015f5c;
    m_kEndPoint.x = _DAT_01015f5c;
    FUN_00583070();
}
}  // namespace fnv_00582c20

namespace fnv_005857b0 {
struct FileH
{
    int m_uiData;
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;
    float m_fVectorX;
};
struct FUN_005858b0_shell
{
    FileH* FUN_00588a90(int);
};
struct FUN_005857b0_shell : FUN_005858b0_shell
{
    int FUN_00584530(int, int, int);
    void FUN_005857b0(int a, int b);
};
// @fnv 0x005857b0
void FUN_005857b0_shell::FUN_005857b0(int a, int aiDelta)
{
    FileH* p = FUN_00588a90(a);
    if (p && p->m_uiData && aiDelta)
    {
        int i2 = (int)p->m_fVectorY >> 12;
        int i3 = (int)p->m_fVectorZ >> 12;
        int i1 = (int)p->m_fScalarPart >> 12;
        int i0 = (int)p->m_fVectorX >> 12;
        for (int i = i2; i <= i1; i++)
        {
            for (int j = i3; j <= i0; j++)
            {
                int k = FUN_00584530(a, i, j);
                if (k >= 0 && ((int*)p->m_uiData)[k])
                    ((int*)p->m_uiData)[k] += aiDelta;
            }
        }
    }
}
}  // namespace fnv_005857b0

struct MapX
{
    void* GetFirstPos();
};
struct List_009e03e0
{
    ~List_009e03e0();
    void RemoveAll();
};
struct MyMap
{
    void RemoveAll();
    virtual ~MyMap();
};
struct NiTMap
{
    void GetNext(void*&, unsigned int&, void*&);
};
struct FUN_00587bb0_shell
{
    void DestroyMapEntries();
};
// Iterates the map at this+0x68, deletes each non-null value list, then clears and deletes the map and nulls the pointer.
// @fnv 0x00587bb0
void FUN_00587bb0_shell::DestroyMapEntries()
{
    if (*(MapX**)((char*)this + 0x68))
    {
        void* pos = ((MapX*)*(MapX**)((char*)this + 0x68))->GetFirstPos();
        while (pos)
        {
            void* key = 0;
            void* val = 0;
            ((NiTMap*)*(MapX**)((char*)this + 0x68))->GetNext(pos, (unsigned int&)key, val);
            if (val)
            {
                ((List_009e03e0*)val)->RemoveAll();
                delete (List_009e03e0*)val;
            }
        }
        ((MyMap*)*(MapX**)((char*)this + 0x68))->RemoveAll();
        delete (MyMap*)*(MapX**)((char*)this + 0x68);
        *(MapX**)((char*)this + 0x68) = 0;
    }
}

namespace fnv_00588c80 {
struct MapX
{
    void* GetFirstPos();
};
struct MyMap
{
    void RemoveAll();
};
struct NiTMap
{
    void GetNext(void*&, unsigned int&, void*&);
};
void __cdecl _Deallocate(void*);
struct FUN_00588c80
{
    void PerformNoArgumentOperation();
};
// Iterates the map at offset 0xb0, deallocating each entry's referenced object and the entry itself, then clears the map.
// @fnv 0x00588c80
void FUN_00588c80::PerformNoArgumentOperation()
{
    void* iterA = ((MapX*)((char*)this + 0xb0))->GetFirstPos();
    while (iterA)
    {
        void* preflist9 = 0;
        unsigned int iignore5 = 0;
        ((NiTMap*)((char*)this + 0xb0))->GetNext(iterA, iignore5, preflist9);
        void* ref = *(void**)preflist9;
        _Deallocate(ref);
        void* p2 = preflist9;
        _Deallocate(p2);
    }
    ((MyMap*)((char*)this + 0xb0))->RemoveAll();
}
}  // namespace fnv_00588c80

namespace fnv_00583070 {
struct FUN_00583070_shell : public TESWorldSpace
{
    void FUN_00583070();
};

struct FUN_005861d0_shell
{
    void SetFlagBit0(bool);
};

struct GO
{
    void operator=(void*);
};

struct FormProxy : TESForm
{
    bool IsReservedFormID();
};

struct WorldSpaceVirtual
{
    virtual void Call();
};

// @fnv 0x00583070
void FUN_00583070_shell::FUN_00583070()
{
    *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x70) = 0;
    *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0xd0) = 0;
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x4c) = 0;
    *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(this) + 0x4e) = 0;

    if (!reinterpret_cast<FormProxy*>(this)->IsReservedFormID())
        reinterpret_cast<FUN_005861d0_shell*>(this)->SetFlagBit0(true);

    *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x40) = 0;
    *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x44) = 0;
    *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x74) = 0;
    *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x78) = 0;
    *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x7c) = 0.0f;
    *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x90) = 1.0f;
    *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x94) = 0.0f;
    *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x98) = 0.0f;

    ClearWorldSpaceReferences();

    *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x9c) = 0;
    *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x48) = 0;
    *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xc8) = DAT_01031920;
    *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xcc) = 0.0f;

    reinterpret_cast<GO*>(reinterpret_cast<char*>(this) + 0x6c)->operator=(0);

    reinterpret_cast<WorldSpaceVirtual*>(reinterpret_cast<char*>(this) + 0xd4)->Call();
    reinterpret_cast<WorldSpaceVirtual*>(reinterpret_cast<char*>(this) + 0xe0)->Call();
}
}  // namespace fnv_00583070

struct GO
{
    operator unsigned int() const;
    void operator=(void*);
};

struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};

struct FUN_00c5a9d0 : A51BF0Base
{
    unsigned char padding[0x78];
    FUN_00c5a9d0();
};

extern unsigned int _data_011c16bc;

struct FUN_005831d0_shell
{
    unsigned char padding[0x6c];
    GO go;

    unsigned int GetOrCreateObject();
};

// Returns the stored object pointer, allocating and storing a new FUN_00c5a9d0 first if it is null.
// @fnv 0x005831d0
unsigned int FUN_005831d0_shell::GetOrCreateObject()
{
    if (!static_cast<unsigned int>(this->go))
    {
        this->go.operator=(new FUN_00c5a9d0());
    }

    return static_cast<unsigned int>(this->go);
}

namespace fnv_00588150 {
struct CellH
{
    int GetCellGridX();
    int GetCellGridY();
};

struct ATM
{
    void QueryPerformanceCounter(int);
    void WaitForTasksDuringRendering(void);
};

extern ATM g_011ca60c;

struct DummyPointerMap
{
    bool GetAt(unsigned int, unsigned int&);
};

struct BSSimpleList
{
    bool _ref_008256d0();
    TESObjectREFR** _ref_006815c0();
    BSSimpleList* _ref_00726070();
};

struct BSOcclusionPlane
{
    int GetCullResult() const;

    virtual void V0() = 0;
    virtual void V1() = 0;
    virtual void V2() = 0;
    virtual void V3() = 0;
    virtual void V4() = 0;
    virtual void V5() = 0;
    virtual void V6() = 0;
    virtual void V7() = 0;
    virtual void V8() = 0;
    virtual void V9() = 0;
    virtual void V10() = 0;
    virtual void V11() = 0;
    virtual void V12() = 0;
    virtual void V13() = 0;
    virtual void V14() = 0;
    virtual void V15() = 0;
    virtual void V16() = 0;
    virtual void V17() = 0;
    virtual void V18() = 0;
    virtual void V19() = 0;
    virtual void V20() = 0;
    virtual void V21() = 0;
    virtual void V22() = 0;
    virtual void V23() = 0;
    virtual void V24() = 0;
    virtual void V25() = 0;
    virtual void V26() = 0;
    virtual void V27() = 0;
    virtual void V28() = 0;
    virtual void V29() = 0;
    virtual void V30() = 0;
    virtual void V31() = 0;
    virtual void V32() = 0;
    virtual void V33() = 0;
    virtual void V34() = 0;
    virtual void V35() = 0;
    virtual void V36() = 0;
    virtual void V37() = 0;
    virtual void V38() = 0;
    virtual void V39() = 0;
    virtual void V40() = 0;
    virtual void V41() = 0;
    virtual void V42() = 0;
    virtual void V43() = 0;
    virtual void V44() = 0;
    virtual void V45() = 0;
    virtual void V46() = 0;
    virtual void V47() = 0;
    virtual void V48() = 0;
    virtual void V49() = 0;
    virtual void V50() = 0;
    virtual void V51() = 0;
    virtual void V52() = 0;
    virtual void V53() = 0;
    virtual void V54() = 0;
    virtual void V55() = 0;
    virtual void V56() = 0;
    virtual void V57() = 0;
    virtual void V58() = 0;
    virtual void V59() = 0;
    virtual void V60() = 0;
    virtual void V61() = 0;
    virtual void V62() = 0;
    virtual void V63() = 0;
    virtual void V64() = 0;
    virtual void V65() = 0;
    virtual void V66() = 0;
    virtual void V67() = 0;
    virtual void V68() = 0;
    virtual void V69() = 0;
    virtual void V70() = 0;
    virtual void V71() = 0;
    virtual void V72() = 0;
    virtual void V73() = 0;
    virtual void V74() = 0;
    virtual void V75() = 0;
    virtual void V76() = 0;
    virtual void V77() = 0;
    virtual void V78() = 0;
    virtual void V79() = 0;
    virtual void V80() = 0;
    virtual void V81() = 0;
    virtual void V82() = 0;
    virtual void V83() = 0;
    virtual void V84() = 0;
    virtual void V85() = 0;
    virtual void V86() = 0;
    virtual void V87() = 0;
    virtual void V88() = 0;
    virtual void V89() = 0;
    virtual void V90() = 0;
    virtual void V91() = 0;
    virtual void V92() = 0;
    virtual void V93() = 0;
    virtual void V94() = 0;
    virtual void V95() = 0;
    virtual void V96() = 0;
    virtual void V97() = 0;
    virtual void V98() = 0;
    virtual void V99() = 0;
    virtual void V100() = 0;
    virtual void V101() = 0;
    virtual void V102() = 0;
    virtual void V103() = 0;
    virtual void V104() = 0;
    virtual void V105() = 0;
    virtual void V106() = 0;
    virtual void V107() = 0;
    virtual void V108() = 0;
    virtual void V109() = 0;
    virtual void V110() = 0;
    virtual void V111() = 0;
    virtual void V112() = 0;
    virtual void V113() = 0;
    virtual void V114() = 0;
    virtual void V115() = 0;
    virtual void V116() = 0;
    virtual void V117() = 0;
    virtual void V118() = 0;
    virtual void V119() = 0;
    virtual void V120() = 0;
    virtual void V121() = 0;
    virtual void V122() = 0;
    virtual void V123() = 0;
    virtual void V124() = 0;

    virtual TESObjectREFR* FUN_0125() = 0;
};

struct FUN_00550200_shell : public TESObjectCELL
{
    bool FUN_00550200(TESObjectREFR*);
};

struct FUN_00588150_shell : public TESWorldSpace
{
    void AddCellReferences(TESObjectCELL*);
};

// Looks up the cell's reference list by key and adds each reference to the cell, filtering the second list by cull result and a cell check.
// @fnv 0x00588150
void FUN_00588150_shell::AddCellReferences(TESObjectCELL* cell)
{
    BSSimpleList* pCurrentElementNext;
    unsigned int ikey;

    if (cell != 0)
    {
        g_011ca60c.QueryPerformanceCounter(0);
        ikey = TESWorldSpace::BuildCellKey(reinterpret_cast<CellH*>(cell)->GetCellGridX(),
                                           reinterpret_cast<CellH*>(cell)->GetCellGridY());

        {
            TESObjectREFR* pref;
            pCurrentElementNext = 0;
            reinterpret_cast<DummyPointerMap*>(reinterpret_cast<char*>(this) + 0x50)
                ->GetAt(ikey, reinterpret_cast<unsigned int&>(pCurrentElementNext));

            while (pCurrentElementNext != 0 && !pCurrentElementNext->_ref_008256d0())
            {
                pref = *pCurrentElementNext->_ref_006815c0();
                cell->AddReference(pref, false);
                pCurrentElementNext = pCurrentElementNext->_ref_00726070();
            }
        }

        {
            TESObjectREFR* pref;
            pCurrentElementNext = reinterpret_cast<BSSimpleList*>(reinterpret_cast<char*>(this) + 0x60);

            while (pCurrentElementNext != 0 && !pCurrentElementNext->_ref_008256d0())
            {
                pref = *pCurrentElementNext->_ref_006815c0();

                if (reinterpret_cast<BSOcclusionPlane*>(pref)->GetCullResult() != reinterpret_cast<int>(cell))
                {
                    if (reinterpret_cast<FUN_00550200_shell*>(cell)->FUN_00550200(
                            reinterpret_cast<BSOcclusionPlane*>(pref)->FUN_0125()))
                    {
                        cell->AddReference(pref, false);
                    }
                }

                pCurrentElementNext = pCurrentElementNext->_ref_00726070();
            }
        }

        g_011ca60c.WaitForTasksDuringRendering();
    }
}
}  // namespace fnv_00588150

namespace fnv_00588560 {
class NiTMap
{
  public:
    void GetNext(void*& position, unsigned int& key, void*& value);
};

class MapX : public NiTMap
{
  public:
    void* GetFirstPos();
};

int _stricmp(const char* string1, const char* string2);

class FUN_00588560_entry
{
  public:
    virtual void f00() = 0;
    virtual void f01() = 0;
    virtual void f02() = 0;
    virtual void f03() = 0;
    virtual void f04() = 0;
    virtual void f05() = 0;
    virtual void f06() = 0;
    virtual void f07() = 0;
    virtual void f08() = 0;
    virtual void f09() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual void f13() = 0;
    virtual void f14() = 0;
    virtual void f15() = 0;
    virtual void f16() = 0;
    virtual void f17() = 0;
    virtual void f18() = 0;
    virtual void f19() = 0;
    virtual void f20() = 0;
    virtual void f21() = 0;
    virtual void f22() = 0;
    virtual void f23() = 0;
    virtual void f24() = 0;
    virtual void f25() = 0;
    virtual void f26() = 0;
    virtual void f27() = 0;
    virtual void f28() = 0;
    virtual void f29() = 0;
    virtual void f30() = 0;
    virtual void f31() = 0;
    virtual void f32() = 0;
    virtual void f33() = 0;
    virtual void f34() = 0;
    virtual void f35() = 0;
    virtual void f36() = 0;
    virtual void f37() = 0;
    virtual void f38() = 0;
    virtual void f39() = 0;
    virtual void f40() = 0;
    virtual void f41() = 0;
    virtual void f42() = 0;
    virtual void f43() = 0;
    virtual void f44() = 0;
    virtual void f45() = 0;
    virtual void f46() = 0;
    virtual void f47() = 0;
    virtual void f48() = 0;
    virtual void f49() = 0;
    virtual void f50() = 0;
    virtual void f51() = 0;
    virtual void f52() = 0;
    virtual void f53() = 0;
    virtual void f54() = 0;
    virtual void f55() = 0;
    virtual void f56() = 0;
    virtual void f57() = 0;
    virtual void f58() = 0;
    virtual void f59() = 0;
    virtual void f60() = 0;
    virtual void f61() = 0;
    virtual void f62() = 0;
    virtual void f63() = 0;
    virtual void f64() = 0;
    virtual void f65() = 0;
    virtual void f66() = 0;
    virtual void f67() = 0;
    virtual void f68() = 0;
    virtual void f69() = 0;
    virtual void f70() = 0;
    virtual void f71() = 0;
    virtual void f72() = 0;
    virtual void f73() = 0;
    virtual void f74() = 0;
    virtual void f75() = 0;
    virtual const char* f76() = 0;
};

struct FUN_00588560_shell
{
    unsigned char pad[0x30];
    MapX* map;

    void* FindEntryByName(const char* name);
};

// Iterates the map's entries and returns the first whose f76() string matches name case-insensitively, or null.
// @fnv 0x00588560
void* FUN_00588560_shell::FindEntryByName(const char* name)
{
    void* result2 = 0;
    void* position;

    if (name)
    {
        position = this->map->GetFirstPos();

        while (position && !result2)
        {
            void* value3 = 0;
            unsigned int key;
            this->map->GetNext(position, key, value3);

            if (value3)
            {
                if (_stricmp(static_cast<FUN_00588560_entry*>(value3)->f76(), name) == 0)
                {
                    result2 = value3;
                }
            }
        }
    }

    return result2;
}
}  // namespace fnv_00588560

struct HelperAt6c
{
    void FUN_0066b0d0(int mode);
};
struct RefAt48
{
    void* FUN_0040f2a0(int deletionFlags);
};
struct FUN_00583180_Class
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c,
        unk40, unk44;
    RefAt48* m_ref;
    int unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68;
    HelperAt6c m_container;
    void FUN_00583180();
};
// @fnv 0x00583180
void FUN_00583180_Class::FUN_00583180()
{
    m_container.FUN_0066b0d0(0);
    RefAt48* node = m_ref;
    RefAt48* doomed = node;
    doomed ? doomed->FUN_0040f2a0(1) : 0;
    m_ref = 0;
}

struct FUN_00583270_sub_cls
{
    void* FUN_00559450();
    void FUN_0066b0d0(int);
};
struct FUN_00583270_mid_cls
{
    int FUN_00454b30();
};
struct FUN_00583270_tgt_cls
{
    void FUN_00b5ddf0(int);
};
int __fastcall FUN_00726070_cb(void* p);
void* __cdecl FUN_00450b80_cb(int v);

struct FUN_00583270_cls
{
    char pad[0x6c];
    FUN_00583270_sub_cls sub;
    void FUN_00583270();
};

// @fnv 0x00583270
void FUN_00583270_cls::FUN_00583270()
{
    if (sub.FUN_00559450())
    {
        if (FUN_00726070_cb(sub.FUN_00559450()) == 1)
        {
            if (reinterpret_cast<FUN_00583270_mid_cls*>(FUN_00450b80_cb(0))->FUN_00454b30() == (int)sub.FUN_00559450())
            {
                reinterpret_cast<FUN_00583270_tgt_cls*>(FUN_00450b80_cb(0))->FUN_00b5ddf0(0);
            }
            sub.FUN_0066b0d0(0);
        }
    }
}

struct TypeGroupInfo
{
    unsigned int type;
    unsigned int unk04;
    unsigned int label;
    unsigned int groupType;
};
struct FileReader
{
    bool FUN_00471c20();
    bool SetOffset(unsigned int);
    bool FUN_004734d0(void*);
    bool FUN_00472150(bool);
    TypeGroupInfo* FUN_00462270();
    void FUN_00473660();
    int FUN_004726b0();
    bool GetChunkData(void*, unsigned int);
    bool FUN_00401680();
    bool FUN_004726f0();
    void SkipCurrentForm();
};
struct Offsets
{
    unsigned int* offsets;
    unsigned int unk04, unk08, unk0c, unk10;
    unsigned int base;
};
struct CellCoordinates
{
    int x, y, flags;
    void FUN_00540720();
    void FUN_00462230();
};
int GetCellCoordKey(int, int);
int FUN_005442c0(int, int);
extern unsigned int kGroupFormType;
extern unsigned int DAT_011872b4;
extern unsigned int DAT_01187338;
struct WorldReader
{
    Offsets* FUN_00588a90(FileReader*);
    int FUN_00584530(FileReader*, int, int);
    bool SeekToCellInWorld(FileReader*, int, int);
};
// Seeks the file to the world block/sub-block for cell (x,y), scanning group headers and cell chunks until the matching cell is found.
// @fnv 0x005854f0
bool WorldReader::SeekToCellInWorld(FileReader* file, int x, int y)
{
    if (file && file->FUN_00471c20())
    {
        Offsets* offsets = FUN_00588a90(file);
        if (offsets && offsets->offsets)
        {
            int index = FUN_00584530(file, x, y);
            if (index != -1)
            {
                unsigned int offset = offsets->offsets[index];
                if (offset)
                {
                    file->SetOffset(offset + offsets->base);
                    return true;
                }
            }
            return false;
        }
    }
    int subBlock;
    bool found = false;
    int block = GetCellCoordKey(x, y);
    subBlock = FUN_005442c0(x, y);
    if (file && file->FUN_004734d0(this))
    {
        file->FUN_00472150(true);
        bool done = false;
        TypeGroupInfo* header = file->FUN_00462270();
        while (header && !done)
        {
            if (header->type == kGroupFormType)
            {
                bool skip = true;
                done = true;
                switch (header->groupType)
                {
                case 1:
                    skip = false;
                case 4:
                    if (block == header->label)
                        skip = false;
                case 5:
                    if (subBlock == header->label)
                        skip = false;
                case 6:
                case 8:
                case 9:
                    done = false;
                }
                if (!done)
                {
                    if (skip)
                        file->FUN_00473660();
                    else
                        file->FUN_00472150(true);
                }
            }
            else if (header->type == DAT_011872b4)
            {
                CellCoordinates cellCoords;
                cellCoords.FUN_00540720();
                memset(&cellCoords, 0, 12);
                if (header->label & 0x400)
                    cellCoords.x = 0x7fffffff;
                else
                {
                    bool read = false;
                    int chunk = file->FUN_004726b0();
                    while (chunk && !read)
                    {
                        if (chunk == 0x434c4358)
                        {
                            file->GetChunkData(&cellCoords, 12);
                            if (file->FUN_00401680())
                                cellCoords.FUN_00462230();
                            read = true;
                        }
                        if (file->FUN_004726f0())
                            chunk = file->FUN_004726b0();
                        else
                            chunk = 0;
                    }
                }
                if (cellCoords.x == x && cellCoords.y == y)
                {
                    found = true;
                    done = true;
                    file->SkipCurrentForm();
                }
                else
                    file->FUN_00472150(true);
            }
            else if (header->type == DAT_01187338)
            {
                file->FUN_00472150(true);
            }
            else
                done = true;
        }
    }
    return found;
}

struct FUN_005877e0_shell : public TESWorldSpace
{
    void FUN_005877e0();
    bool Probe();
};

struct FUN_005877e0_Val5
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual unsigned int v4(int);
};

struct FUN_005877e0_Map
{
    void* First();
    void Next(void** it, unsigned int* key, FUN_005877e0_Val5** out);
    void Done();
};

// If Probe fails, iterates cellMap calling v4(1) on each entry, then always calls Done on cellMap.
// @fnv 0x005877e0
void FUN_005877e0_shell::FUN_005877e0()
{
    if (!Probe())
    {
        void* it = reinterpret_cast<FUN_005877e0_Map*>(cellMap)->First();
        while (it != 0)
        {
            FUN_005877e0_Val5* item;
            unsigned int key;
            FUN_005877e0_Val5* out4 = 0;
            reinterpret_cast<FUN_005877e0_Map*>(cellMap)->Next(&it, &key, &out4);
            FUN_005877e0_Val5* tmp4 = out4;
            item = tmp4;
            (item != 0) ? item->v4(1) : 0;
        }
    }
    reinterpret_cast<FUN_005877e0_Map*>(cellMap)->Done();
}

struct Pt3
{
    float x;
    float y;
    float z;
    Pt3();
    Pt3& operator*=(float);
    Pt3 operator-(const Pt3&) const;
    Pt3 operator+(const Pt3&) const;
};

extern float const DAT_01016248;

struct WorldOffsetHost
{
    int unk00;
    float GetOffsetX();
    float GetOffsetY();
};

float __fastcall GetWorldScale(void* apWorld);

struct FUN_00588e40_shell : WorldOffsetHost
{
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
    float m_fGridOriginX;
    float afWorldOriginY;
    float kPointArrayBench;
    float m_fWorldTransformCoefficient4;
    void TransformWorldPoint(Pt3* apPoint, bool abInverse);
};

// @fnv 0x00588e40
void FUN_00588e40_shell::TransformWorldPoint(Pt3* apPoint, bool abInverse)
{
    if (abInverse)
    {
        apPoint->x -= GetOffsetX();
        apPoint->y -= GetOffsetY();
    }
    if (GetWorldScale(this) != 1.0 && GetWorldScale(this) != 0.0)
    {
        Pt3 kCenter4;
        kCenter4.x = m_fGridOriginX + kPointArrayBench;
        kCenter4.y = afWorldOriginY + m_fWorldTransformCoefficient4;
        kCenter4.z = 0.0f;
        kCenter4 *= DAT_01016248;
        Pt3 kDelta = *apPoint - kCenter4;
        kDelta *= abInverse ? 1.0 / GetWorldScale(this) : GetWorldScale(this);
        *apPoint = kCenter4 + kDelta;
    }
    if (!abInverse)
    {
        apPoint->x += GetOffsetX();
        apPoint->y += GetOffsetY();
    }
}

struct FUN_00483630_holder
{
    virtual ~FUN_00483630_holder();
    unsigned int flags, formID, fileData, changedFlags, recordData;
};
struct FUN_00591300
{
    virtual ~FUN_00591300();
    unsigned int nameData, nameLength;
};
struct TESTexture
{
    virtual ~TESTexture();
    unsigned int textureData, textureLength;
};
struct FUN_0048e2e0
{
    unsigned int type, data, length;
    ~FUN_0048e2e0();
};
struct FUN_0057ce90_shell
{
    unsigned int head;
    ~FUN_0057ce90_shell();
};
struct FUN_00589130
{
    unsigned int table, count, allocator, entries;
    ~FUN_00589130();
};
struct FUN_00589230
{
    unsigned int entries, size, capacity, allocator;
    ~FUN_00589230();
};
struct BSStringTChar
{
    unsigned int data, length;
    ~BSStringTChar();
};
struct GO633
{
    void* node;
    ~GO633();
};
struct WorldTerrain
{
    void FUN_006fca70();
    ~WorldTerrain();
};
struct WorldCellMap
{
    virtual ~WorldCellMap();
};
struct WorldLandMap
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual ~WorldLandMap();
};
struct FUN_00582e30 : FUN_00483630_holder, FUN_00591300, TESTexture
{
    WorldCellMap* cellMap;
    WorldLandMap* landMap;
    FUN_0057ce90_shell cellList;
    WorldTerrain* terrain;
    unsigned int water, parentUseFlags, climate, worldFlags;
    FUN_00589130 offsetMap;
    BSSimpleList<int> regionList;
    unsigned int worldspaceID;
    GO633 node;
    unsigned int parent, music, encounterZone, location, mapScale, mapX, mapY;
    unsigned int minX, minY, maxX, maxY, landHeight, waterHeight, lodWater;
    unsigned int lodWaterType, impactData;
    FUN_00589230 offsetArray;
    BSStringTChar mapName;
    float usableX, usableY;
    unsigned int mapDimensions;
    FUN_0048e2e0 m_kCloudLayerTextures;
    FUN_0048e2e0 waterTexture;
    virtual ~FUN_00582e30();
    void ClearAllLists();
    void DestroyMapEntries();
    void FUN_00583180();
    void FUN_005877e0();
    void FUN_00588c80();
};
extern FUN_00582e30* DAT_011c3f44;
// Clears the global worldspace pointer if it is this object, then releases terrain, cell and land maps and other owned resources.
// @fnv 0x00582e30
FUN_00582e30::~FUN_00582e30()
{
    if (DAT_011c3f44 == this)
        DAT_011c3f44 = 0;
    ClearAllLists();
    DestroyMapEntries();
    if (terrain)
    {
        terrain->FUN_006fca70();
        delete terrain;
        terrain = 0;
    }
    FUN_00583180();
    FUN_005877e0();
    delete cellMap;
    cellMap = 0;
    delete landMap;
    landMap = 0;
    FUN_00588c80();
}

struct WorldRecordFile : TESFile
{
    unsigned int FUN_004726b0();
    void GetChunkData(void*, unsigned int);
    bool FUN_00401680();
    bool FUN_00471c20();
    bool FUN_004726f0();
};
struct BoundsPoint
{
    float x, y;
    BoundsPoint();
};
struct BoundsOffsetData
{
    unsigned int cellOffsets;
    BoundsPoint minimum, maximum;
    unsigned int fileOffset;
};
void BSEndian(float*, EndianSizeTag<4>);
float FUN_0040ebd0(float, float);
float FUN_00404010(float, float);
struct WorldBounds
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
    float minX, minY, maxX, maxY;
    BoundsOffsetData* GetOrCreateCellOffsetData(WorldRecordFile*);
    bool FUN_00583360(WorldRecordFile*);
};
// @fnv 0x00583360
bool WorldBounds::FUN_00583360(WorldRecordFile* file)
{
    unsigned int type = 0;
    while (type = file->FUN_004726b0())
    {
        switch (type)
        {
        case 0x304d414e: {
            BoundsPoint minimum;
            file->GetChunkData(&minimum, 8);
            if (file->FUN_00401680())
            {
                BSEndian(&minimum.x, EndianSizeTag<4>());
                BSEndian(&minimum.y, EndianSizeTag<4>());
            }
            minX = FUN_0040ebd0(minX, minimum.x);
            minY = FUN_0040ebd0(minY, minimum.y);
            if (file->FUN_00471c20())
            {
                BoundsOffsetData* data = GetOrCreateCellOffsetData(file);
                data->minimum = minimum;
            }
            break;
        }
        case 0x394d414e: {
            BoundsPoint maximum;
            file->GetChunkData(&maximum, 8);
            if (file->FUN_00401680())
            {
                BSEndian(&maximum.x, EndianSizeTag<4>());
                BSEndian(&maximum.y, EndianSizeTag<4>());
            }
            maxX = FUN_00404010(maxX, maximum.x);
            maxY = FUN_00404010(maxY, maximum.y);
            if (file->FUN_00471c20())
            {
                BoundsOffsetData* data = GetOrCreateCellOffsetData(file);
                data->maximum = maximum;
            }
            break;
        }
        }
        if (!file->FUN_004726f0())
            break;
    }
    return true;
}

struct SaveForm
{
    unsigned int GetFormID();
    void Save();
};
struct SaveFullName
{
    unsigned int unk00, unk04, unk08;
    void FUN_00487010();
};
struct SaveTexture
{
    unsigned int unk00, unk04, unk08;
    void FUN_0048e370(unsigned int);
};
struct SaveMap
{
    unsigned int unk00, unk04, unk08, unk0c;
    void FUN_005840b0();
};
struct SaveOffset
{
    unsigned int unk00, unk04, unk08;
    void FUN_005a6b10();
};
struct SaveGameString
{
    unsigned int unk00, unk04, unk08;
    int FUN_0048cee0();
    int* FUN_00408da0();
};
struct SavePair
{
    float land, water;
    void FUN_00462230();
};
bool FUN_00401500();
void FUN_00485910(unsigned int, unsigned int);
void _FUN_00485910(unsigned int, float);
void FUN_00485950(unsigned int, unsigned int);
void AppendChunk(unsigned int, void*, unsigned int);
void FUN_004858f0(unsigned int, unsigned char);
void FUN_00485710(unsigned int, unsigned int*, unsigned int);
void FUN_004856f0(unsigned int, void*, unsigned int);
struct SaveWorld
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    SaveFullName fullName;
    SaveTexture texture;
    unsigned int unk30, unk34, unk38, unk3c, unk40, unk44;
    SaveForm* extra;
    unsigned char flags, unk4d;
    unsigned short parentFlags;
    unsigned int unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    SaveForm* parent;
    unsigned int unk74, unk78, unk7c;
    SaveMap map;
    SaveOffset offset;
    unsigned int unk9c;
    unsigned int minimumX, minimumY, maximumX, maximumY;
    unsigned int unkb0, unkb4, unkb8, unkbc, unkc0, unkc4;
    float landHeight, waterHeight;
    SaveForm* encounterZone;
    SaveGameString canopy, waterNoise;
    void FUN_004855a0();
    void FUN_00485680();
    bool FUN_00586340(int);
    SaveForm* FUN_00585fe0();
    SaveForm* FUN_00586070();
    SaveForm* FUN_005860c0();
    float FUN_0045cd80();
    SaveForm* FUN_008041a0();
    SaveForm* FUN_00586150();
    void FUN_00584170();
};
// Writes the world record's encounter zone, parent, canopy, water noise, heights, map, offset, bounds and flags to the save stream.
// @fnv 0x00584170
void SaveWorld::FUN_00584170()
{
    FUN_004855a0();
    fullName.FUN_00487010();
    unsigned int formID = 0;
    if (encounterZone)
    {
        formID = encounterZone->GetFormID();
        FUN_00485910(0x4e5a4558, formID);
    }
    if (parent)
    {
        formID = parent->GetFormID();
        FUN_00485910(0x4d414e57, formID);
        FUN_00485950(0x4d414e50, parentFlags);
    }
    if (!FUN_00586340(4) && FUN_00585fe0())
    {
        formID = FUN_00585fe0()->GetFormID();
        FUN_00485910(0x4d414e43, formID);
    }
    if (!FUN_00586340(3) && FUN_00586070())
    {
        formID = FUN_00586070()->GetFormID();
        FUN_00485910(0x324d414e, formID);
    }
    if (!FUN_00586340(1) && FUN_005860c0())
    {
        formID = FUN_005860c0()->GetFormID();
        FUN_00485910(0x334d414e, formID);
        _FUN_00485910(0x344d414e, FUN_0045cd80());
    }
    if (!FUN_00586340(0))
    {
        SavePair pairHeights;
        pairHeights.land = landHeight;
        pairHeights.water = waterHeight;
        if (FUN_00401500())
            pairHeights.FUN_00462230();
        AppendChunk(0x4d414e44, &pairHeights, 8);
        if (FUN_00401500())
            pairHeights.FUN_00462230();
    }
    if (!FUN_00586340(2))
    {
        texture.FUN_0048e370(0x4e4f4349);
        if (FUN_00401500())
            map.FUN_005840b0();
        AppendChunk(0x4d414e4d, &map, 16);
        if (FUN_00401500())
            map.FUN_005840b0();
    }
    if (FUN_00401500())
        offset.FUN_005a6b10();
    AppendChunk(0x4d414e4f, &offset, 12);
    if (FUN_00401500())
        offset.FUN_005a6b10();
    if (!FUN_00586340(5) && FUN_008041a0())
    {
        formID = FUN_008041a0()->GetFormID();
        FUN_00485910(0x4d414e49, formID);
    }
    FUN_004858f0(0x41544144, flags);
    FUN_00485710(0x304d414e, &minimumX, 2);
    FUN_00485710(0x394d414e, &maximumX, 2);
    if (FUN_00586150())
    {
        formID = FUN_00586150()->GetFormID();
        FUN_00485910(0x4d414e5a, formID);
    }
    FUN_004856f0(0x4d414e4e, canopy.FUN_00408da0(), canopy.FUN_0048cee0() + 1);
    FUN_004856f0(0x4d414e58, waterNoise.FUN_00408da0(), waterNoise.FUN_0048cee0() + 1);
    if (extra)
        extra->Save();
    FUN_00485680();
}

extern "C" void* _FNV_DynamicCast(void*, int, const void*, const void*, int);
extern char _FNV_RTTI_TESForm;
extern char _FNV_RTTI_TESWorldSpace;
void* __cdecl memcpy(void*, const void*, unsigned int);
struct FUN_0058efd0
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    FUN_0058efd0();
    ~FUN_0058efd0();
    void CopyFrom(FUN_0058efd0*);
};
struct CopyMap
{
    void RemoveAll();
    void* GetFirstPos();
    void GetNext(void*&, unsigned int&, unsigned int&);
    void SetAt(unsigned int, unsigned int);
};
struct CopyArray
{
    virtual void Destroy();
    virtual void Clear();
    virtual void CopyFrom(const CopyArray&);
    unsigned int count, capacity;
};
struct WorldCopy
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
    CopyMap* cells;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    TESClimate* climate;
    void* imageSpace;
    FUN_0058efd0* data;
    unsigned char flags;
    unsigned char unk4d;
    unsigned short parentFlags;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    TESWorldSpace* parent;
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
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    float landHeight;
    float waterHeight;
    unsigned int unkd0;
    CopyArray arrayD4;
    CopyArray arrayE0;

    void FUN_00584fa0(TESForm*);
    void CopyBase(TESForm*);
    TESClimate* GetWorldClimate();
    void* GetImageSpace();
    TESWaterForm* GetWater();
    TESWaterForm* GetLODWater();
    void SetWater(TESWaterForm*);
    void SetLODWater(TESWaterForm*);
    float GetHeight();
    void SetHeight(float);
    int GetMusic();
    void SetMusic(int);
};
// @fnv 0x00584fa0
void WorldCopy::FUN_00584fa0(TESForm* form)
{
    WorldCopy* source = (WorldCopy*)_FNV_DynamicCast(form, 0, &_FNV_RTTI_TESForm, &_FNV_RTTI_TESWorldSpace, 0);
    if (!source)
        return;
    CopyBase((TESForm*)source);
    flags = source->flags;
    parentFlags = source->parentFlags;
    parent = source->parent;
    unkd0 = source->unkd0;
    climate = source->GetWorldClimate();
    imageSpace = source->GetImageSpace();
    if (source->data)
    {
        if (!data)
            data = new FUN_0058efd0;
        data->CopyFrom(source->data);
    }
    else if (data)
    {
        delete data;
        data = 0;
    }
    SetWater(source->GetWater());
    SetLODWater(source->GetLODWater());
    SetHeight(source->GetHeight());
    landHeight = source->landHeight;
    waterHeight = source->waterHeight;
    memcpy(&unk80, &source->unk80, 16);
    memcpy(&unk90, &source->unk90, 12);
    SetMusic(source->GetMusic());
    cells->RemoveAll();
    void* position = source->cells->GetFirstPos();
    while (position)
    {
        unsigned int value = 0;
        unsigned int key;
        source->cells->GetNext(position, key, value);
        cells->SetAt(key, value);
    }
    arrayD4.CopyFrom(source->arrayD4);
    arrayE0.CopyFrom(source->arrayE0);
}

struct DataFile
{
    DataFile* FUN_004739b0();
    bool FUN_004723a0(unsigned int);
    unsigned int FUN_00472660();
    unsigned int FUN_004726b0();
    unsigned int GetField25C();
    bool GetChunkData(void*, unsigned int);
};
struct CellOffsetData
{
    unsigned int* offsets;
    float minX, minY, maxX, maxY;
    unsigned int baseOffset;
};
void* FormHeap_Allocate(unsigned int);
void FormHeap_Free(void*);
void FUN_00403d30(void*, int, unsigned int);
int FUN_00404dc0(const char*, const char*);
struct WorldData
{
    unsigned int GetSourceFileCount();
    DataFile* FUN_00484e60(unsigned int);
    CellOffsetData* FUN_00588a90(DataFile*);
    int FUN_00584530(DataFile*, int, int);
    bool FindCellByEditorID(const char*, int*, int*);
};
// Scans every loaded worldspace cell grid for a cell whose EDID chunk matches editorID, writing its grid coordinates to outX/outY and returning true when found.
// @fnv 0x00585940
bool WorldData::FindCellByEditorID(const char* editorID, int* outX, int* outY)
{
    unsigned int count = GetSourceFileCount();
    for (unsigned int i = 0; i < count; i++)
    {
        DataFile* data = FUN_00484e60(i)->FUN_004739b0();
        CellOffsetData* file = FUN_00588a90(data);
        if (file)
        {
            int minX = ((int)file->minX) >> 12;
            int maxY = ((int)file->minY) >> 12;
            int minY = ((int)file->maxX) >> 12;
            int maxX = ((int)file->maxY) >> 12;
            for (int x = minX; x <= minY; x++)
            {
                for (int y = maxY; y <= maxX; y++)
                {
                    int index = FUN_00584530(data, x, y);
                    if (index != -1)
                    {
                        unsigned int offset = file->offsets[index];
                        if (offset)
                        {
                            data->FUN_004723a0(offset + file->baseOffset);
                            if (data->FUN_00472660() == 0x39)
                            {
                                unsigned int chunkID = data->FUN_004726b0();
                                if (chunkID == 0x44494445)
                                {
                                    unsigned int uiBufferSize = data->GetField25C() + 1;
                                    char* size = (char*)FormHeap_Allocate(uiBufferSize);
                                    FUN_00403d30(size, 0, uiBufferSize);
                                    data->GetChunkData(size, 0);
                                    if (!FUN_00404dc0(size, editorID))
                                    {
                                        *outX = x;
                                        *outY = y;
                                        FormHeap_Free(size);
                                        return true;
                                    }
                                    FormHeap_Free(size);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

struct AutoMemHelper
{
    int previousContext;
    AutoMemHelper(int, bool, const char*, int);
    ~AutoMemHelper();
};
extern const char DAT_01031f18[];
extern const char DAT_01031ec0[];
struct CellOperations
{
    virtual void virtual0();
    virtual void virtual1();
    virtual void virtual2();
    virtual void virtual3();
    virtual void virtual4();
    virtual void virtual5();
    virtual void virtual6();
    virtual void virtual7();
    virtual void virtual8();
    virtual void virtual9();
    virtual void virtual10();
    virtual void virtual11();
    virtual void virtual12();
    virtual void virtual13();
    virtual void virtual14();
    virtual void virtual15();
    virtual void virtual16();
    virtual void virtual17();
    virtual void virtual18();
    virtual void virtual19();
    virtual void virtual20();
    virtual void virtual21();
    virtual void virtual22();
    virtual void virtual23();
    virtual void virtual24();
    virtual void virtual25();
    virtual void virtual26();
    virtual void virtual27();
    virtual void virtual28();
    virtual void virtual29();
    virtual void virtual30();
    virtual void virtual31();
    virtual void virtual32();
    virtual void virtual33();
    virtual void FinishLoad();
    virtual void virtual35();
    virtual void virtual36();
    virtual void virtual37();
    virtual void virtual38();
    virtual void virtual39();
    virtual void virtual40();
    virtual void virtual41();
    virtual void virtual42();
    virtual void virtual43();
    virtual void virtual44();
    virtual void virtual45();
    virtual void virtual46();
    virtual void virtual47();
    virtual void virtual48();
    virtual void virtual49();
    virtual void virtual50();
    virtual void virtual51();
    virtual void virtual52();
    virtual void virtual53();
    virtual void virtual54();
    virtual void virtual55();
    virtual void virtual56();
    virtual void virtual57();
    virtual void virtual58();
    virtual void virtual59();
    virtual void virtual60();
    virtual void virtual61();
    virtual void virtual62();
    virtual void virtual63();
    virtual void virtual64();
    virtual void virtual65();
    virtual void virtual66();
    virtual void virtual67();
    virtual void virtual68();
    virtual void virtual69();
    virtual void virtual70();
    virtual void virtual71();
    virtual void virtual72();
    virtual void virtual73();
    virtual void SetWorldData(void*, bool);
    bool FUN_00551420();
    void FUN_00544300(bool);
    void ResetCellData();
    void SetExteriorCellCoordinates(int, int);
    bool FUN_00550500(FileReader*);
    void FUN_00551440(bool);
};
struct SaveLoadOperations
{
    void* RemoveCommand(unsigned int, int, int);
    bool FUN_0047c850();
    void FUN_004534f0(bool);
};
extern SaveLoadOperations* DAT_011de45c;
extern TESWorldSpace* DAT_011c3f34;
bool __cdecl FUN_004601d0(CellOperations*, FileReader*);
struct WorldCellLoader
{
    virtual void virtual0();
    virtual void virtual1();
    virtual void virtual2();
    virtual void virtual3();
    virtual void virtual4();
    virtual void virtual5();
    virtual void virtual6();
    virtual void virtual7();
    virtual void virtual8();
    virtual void virtual9();
    virtual void virtual10();
    virtual void virtual11();
    virtual void virtual12();
    virtual void virtual13();
    virtual void virtual14();
    virtual void virtual15();
    virtual void virtual16();
    virtual void virtual17();
    virtual void virtual18();
    virtual void virtual19();
    virtual void virtual20();
    virtual void virtual21();
    virtual void virtual22();
    virtual void virtual23();
    virtual void virtual24();
    virtual void virtual25();
    virtual void virtual26();
    virtual void virtual27();
    virtual void virtual28();
    virtual void virtual29();
    virtual void virtual30();
    virtual void virtual31();
    virtual void virtual32();
    virtual void virtual33();
    virtual void virtual34();
    virtual void virtual35();
    virtual void virtual36();
    virtual void virtual37();
    virtual void virtual38();
    virtual void virtual39();
    virtual void virtual40();
    virtual void virtual41();
    virtual void virtual42();
    virtual void virtual43();
    virtual void virtual44();
    virtual void virtual45();
    virtual void virtual46();
    virtual void virtual47();
    virtual void virtual48();
    virtual void virtual49();
    virtual void virtual50();
    virtual void virtual51();
    virtual void virtual52();
    virtual void virtual53();
    virtual void virtual54();
    virtual void virtual55();
    virtual void virtual56();
    virtual void virtual57();
    virtual void virtual58();
    virtual void virtual59();
    virtual void virtual60();
    virtual void virtual61();
    virtual void virtual62();
    virtual void virtual63();
    virtual void virtual64();
    virtual void virtual65();
    virtual void virtual66();
    virtual void virtual67();
    virtual void virtual68();
    virtual void virtual69();
    virtual void virtual70();
    virtual void virtual71();
    virtual void virtual72();
    virtual void virtual73();
    virtual void virtual74();
    virtual void virtual75();
    virtual const char* GetWorldName();
    CellOperations* FUN_005875a0(int, int);
    unsigned int GetSourceFileCount();
    FileReader* FUN_00484e60(unsigned int);
    bool SeekToCellInWorld(FileReader*, int, int);
    void FUN_00587670(CellOperations*);
    unsigned int FUN_0084e3a0();
    void AddCellReferences(CellOperations*);
    CellOperations* FUN_00585b30(int x, int y);
};
struct ThreadFile
{
    FileReader* FUN_004739b0();
};
// @fnv 0x00585b30
CellOperations* WorldCellLoader::FUN_00585b30(int x, int y)
{
    AutoMemHelper j(26, true, DAT_01031f18, 1942);
    bool i = true;
    CellOperations* p = FUN_005875a0(x, y);
    DAT_011c3f34 = reinterpret_cast<TESWorldSpace*>(this);
    if (!p || !p->FUN_00551420())
    {
        unsigned int fileCount = GetSourceFileCount();
        for (unsigned int fileIndex = 0; fileIndex < fileCount; ++fileIndex)
        {
            FileReader* file = reinterpret_cast<ThreadFile*>(FUN_00484e60(fileIndex))->FUN_004739b0();
            bool loaded = file && SeekToCellInWorld(file, x, y);
            if (loaded)
            {
                if (!p)
                {
                    p = reinterpret_cast<CellOperations*>(new stub::TESObjectCELL);
                    p->FUN_00544300(false);
                    p->ResetCellData();
                    p->SetExteriorCellCoordinates(x, y);
                    FUN_00587670(p);
                    void* worldData = 0;
                    worldData = DAT_011de45c->RemoveCommand(FUN_0084e3a0(), x, y);
                    if (worldData)
                        p->SetWorldData(worldData, true);
                    i = FUN_004601d0(p, file);
                }
                else if (!(file->FUN_00462270()->label & 0x4000))
                {
                    FUN_004601d0(p, file);
                }
                if (!p->FUN_00550500(file))
                    i = false;
            }
        }
        if (p)
        {
            p->FUN_00551440(true);
            bool loading = DAT_011de45c->FUN_0047c850();
            DAT_011de45c->FUN_004534f0(!loading);
            p->FinishLoad();
            DAT_011de45c->FUN_004534f0(loading);
            AddCellReferences(p);
        }
    }
    if (!i)
        Warning(DAT_01031ec0, x, y, GetWorldName(), FUN_0084e3a0());
    return p;
}

struct FUN_00585ee0_shell : public TESWorldSpace
{
    bool FindParentFile(int a1, int a2, unsigned int* a3, unsigned int* a4);
    int GetFileCount();
    TESFile* GetFileForm(int aIndex);
};

struct FileX
{
    TESFile* GetParentFile();
    unsigned int GetOff();
};

struct WorldX
{
    bool ReadWorldData(TESFile* apFile, int a1, int a2);
};

bool __cdecl LoadedCheck(TESFile* apFile);

// @fnv 0x00585ee0
bool FUN_00585ee0_shell::FindParentFile(int a1, int a2, unsigned int* apuiFileOut, unsigned int* apuiOffsetOut)
{
    bool bFound = false;
    *apuiFileOut = 0;
    *apuiOffsetOut = 0;
    if (!GetParentWorld((TESWorldSpace::PARENT_USE_FLAG)0))
    {
        int iFileCount = GetFileCount();
        if (iFileCount)
        {
            for (int iFileIndex = iFileCount - 1; iFileIndex >= 0; iFileIndex--)
            {
                TESFile* pParentFile = ((FileX*)GetFileForm(iFileIndex))->GetParentFile();
                if (pParentFile && ((WorldX*)this)->ReadWorldData(pParentFile, a1, a2) && LoadedCheck(pParentFile))
                {
                    *apuiFileOut = (unsigned int)pParentFile;
                    *apuiOffsetOut = ((FileX*)pParentFile)->GetOff();
                    bFound = true;
                    break;
                }
            }
        }
    }
    else
    {
        bFound = ((FUN_00585ee0_shell*)GetParentWorld((TESWorldSpace::PARENT_USE_FLAG)0))
                     ->FindParentFile(a1, a2, apuiFileOut, apuiOffsetOut);
    }
    return bFound;
}

struct GlobalObject_006815c0
{
    GlobalObject_006815c0();
    float x, y, z;
};
typedef GlobalObject_006815c0 Point;
struct RegionForm
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
    virtual unsigned char Weight();
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
    virtual float Value108();
    virtual void v109();
    virtual float Value110();
    virtual void v111();
    virtual float Value112();
    virtual void v113();
    virtual float Value114();
    virtual void v115();
    virtual unsigned char Value116();
    virtual void v117();
    virtual unsigned char Value118();
    virtual void v119();
    virtual unsigned char Value120();
    const char* FUN_0050a550();
    unsigned int FUN_0084e3a0();
};
struct Region
{
    virtual void v0();
    virtual RegionForm* Form();
    virtual void v2();
    virtual int Priority();
    virtual void v4();
    virtual void v5();
    virtual float Weight(Point const&, TESWorldSpace*, bool);
};
struct Entry
{
    Region* region;
    float weight;
};
struct RegionNode
{
    Region* item;
    RegionNode* next;
    Region** FUN_006815c0();
    RegionNode* FUN_00726070();
};
struct Head
{
    int unk00;
};
struct RegionData : Head, RegionNode
{
};
struct Selection
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual Selection* Select(void*);
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual RegionData* GetList();
};
struct CellRegions
{
    void* FUN_004f6800(int, Point const&, TESWorldSpace*);
};
struct CellProxyNew
{
    CellRegions* GetRegionList(bool);
};
struct Handler
{
    CellProxyNew* FUN_00461bc0(float, float, TESWorldSpace*, bool);
    Selection* GetRegionDataManager();
};
struct GlobalObject_0096a2d0
{
    GlobalObject_0096a2d0();
    Entry* item;
    GlobalObject_0096a2d0* next;
    Entry** FUN_006815c0();
    GlobalObject_0096a2d0* FUN_00726070();
    bool FUN_008256d0();
    void FUN_005ae3d0(Entry*&);
    void FUN_00470470();
};
struct RegionResult
{
    char* name;
    unsigned int formID;
    float a, b, c, time, d;
    unsigned char e, f, g, unk1f;
    float samples[9];
};
int __cdecl FUN_00406d00(char*, int, const char*, ...);
float __cdecl FUN_0053ca40();
struct World : TESWorldSpace
{
    void BuildRegionResults(float, float, float, float, RegionResult*, unsigned);
};
// Selects regions around the center of the given bounds, fills each result with region data and samples region weights at a 3x3 grid of points.
// @fnv 0x00586990
void World::BuildRegionResults(float minX, float minY, float maxX, float maxY, RegionResult* results, unsigned count)
{
    Entry* l = 0;
    Region** k = 0;
    Region* b = 0;
    RegionForm* a = 0;
    Point s[9];
    Point h;
    if (!g_dataHandler || !count)
        return;
    h.x = (minX + maxX) / 2.0;
    h.y = (minY + maxY) / 2.0;
    h.z = 0;
    float q = (maxX - minX) / 2.0;
    float c = (maxY - minY) / 2.0;
    CellProxyNew* e = ((Handler*)g_dataHandler)->FUN_00461bc0(h.x, h.y, this, false);
    if (!e || !e->GetRegionList(true))
        return;
    unsigned i;
    for (i = 0; i < 9; i++)
    {
        s[i].x = minX + (i % 3) * q;
        s[i].y = minY + (i / 3) * c;
        s[i].z = 0;
    }
    Selection* eb =
        ((Handler*)g_dataHandler)->GetRegionDataManager()->Select(e->GetRegionList(true)->FUN_004f6800(6, h, this));
    if (!eb)
        return;
    GlobalObject_0096a2d0* cf = new GlobalObject_0096a2d0;
    RegionNode* f = eb->GetList();
    while (f)
    {
        b = *f->FUN_006815c0();
        a = b ? b->Form() : 0;
        if (b && b->Priority() && a && a->Weight() && b->Weight(h, this, false) != 0.0)
        {
            l = new Entry;
            l->region = b;
            l->weight = a->Weight() / 100.0;
            cf->FUN_005ae3d0(l);
        }
        f = f->FUN_00726070();
    }
    f = eb->GetList();
    while (f)
    {
        b = *f->FUN_006815c0();
        a = b ? b->Form() : 0;
        if (b && !b->Priority() && a && a->Weight() && b->Weight(h, this, false) != 0.0)
        {
            l = new Entry;
            l->region = b;
            l->weight = a->Weight() / 100.0;
            cf->FUN_005ae3d0(l);
        }
        f = f->FUN_00726070();
    }
    if (!cf || cf->FUN_008256d0())
    {
        delete (List_009e03e0*)cf;
        return;
    }
    k = new Region*[count];
    memset(k, 0, count * sizeof(Region*));
    GlobalObject_0096a2d0* ba = cf;
    unsigned p;
    for (p = 0; p < count; p++)
    {
        memset(results[p].samples, 0, sizeof(results[p].samples));
        if (results[p].name)
            delete[] results[p].name;
        results[p].name = 0;
        if (!ba)
            continue;
        l = *ba->FUN_006815c0();
        while (!l)
        {
            ba = ba->FUN_00726070();
            if (!ba)
                break;
            l = *ba->FUN_006815c0();
        }
        if (!l)
            continue;
        b = l->region;
        a = b->Form();
        k[p] = b;
        if (results[p].name)
            delete[] results[p].name;
        char* name = new char[260];
        FUN_00406d00(name, 260, "data/meshes/%s", a->FUN_0050a550());
        results[p].name = name;
        results[p].formID = a->FUN_0084e3a0();
        results[p].a = a->Value108();
        results[p].b = a->Value110();
        results[p].c = a->Value112();
        results[p].d = a->Value114();
        results[p].e = a->Value116();
        results[p].f = a->Value118();
        results[p].g = a->Value120();
        results[p].time = FUN_0053ca40();
        ba = ba->FUN_00726070();
    }
    for (i = 0; i < 9; i++)
    {
        for (p = 0; p < count; p++)
        {
            if (!k[p] || !results[p].formID)
                continue;
            results[p].samples[i] = k[p]->Weight(s[i], this, true);
        }
    }
    delete[] k;
    {
        GlobalObject_0096a2d0* cleanup = cf;
        Entry* dead = 0;
        while (cleanup && *cleanup->FUN_006815c0())
        {
            dead = *cleanup->FUN_006815c0();
            cleanup = cleanup->FUN_00726070();
            delete dead;
        }
        cf->FUN_00470470();
        delete (List_009e03e0*)cf;
    }
}

struct WsNameList
{
    const char* item;
    WsNameList* next;
    WsNameList();
};

struct WsListNode
{
    TESWorldSpace** Item();
    WsListNode* GetNext();
};

struct WsDataHandler
{
    WsListNode* GetWorldSpaces();
};

struct FUN_005883c0_shell : public TESWorldSpace
{
    void AddMapNames(WsNameList* apList);
    WsNameList* BuildMapNameList(bool abNoChildren);
};

// Builds a WsNameList from the parent world's list or a new list with this world's map names plus those of child worlds unless abNoChildren.
// @fnv 0x005883c0
WsNameList* FUN_005883c0_shell::BuildMapNameList(bool abNoChildren)
{
    WsNameList* pNameList = 0;
    if (GetParentWorld((PARENT_USE_FLAG)2) && !abNoChildren)
    {
        pNameList = ((FUN_005883c0_shell*)GetParentWorld((PARENT_USE_FLAG)2))->BuildMapNameList(false);
    }
    else
    {
        pNameList = new WsNameList;
        AddMapNames(pNameList);
        if (!abNoChildren)
        {
            WsListNode* pNode = ((WsDataHandler*)g_dataHandler)->GetWorldSpaces();
            while (pNode)
            {
                TESWorldSpace* pWorld = *pNode->Item();
                if (pWorld && pWorld->GetParentWorld((PARENT_USE_FLAG)2) == this)
                {
                    ((FUN_005883c0_shell*)pWorld)->AddMapNames(pNameList);
                }
                pNode = pNode->GetNext();
            }
        }
    }
    return pNameList;
}

extern const double DAT_010231b0;
struct CELL_SHELL : public TESObjectCELL
{
    bool FUN_0054da20(const NiPoint3* point, float distance, const NiPoint3* otherPoint, float otherDistance,
                      int options, unsigned int context);
    float FUN_0054fb70(const NiPoint3* point);
};
struct WORLD_SHELL : public TESWorldSpace
{
    CELL_SHELL* FUN_005875a0(int, int);
    void ProcessCellsInRadius(const NiPoint3* point, float distance, const NiPoint3* otherPoint, float otherDistance,
                              int options, unsigned int context);
};
// @fnv 0x005885f0
void WORLD_SHELL::ProcessCellsInRadius(const NiPoint3* point, float distance, const NiPoint3* otherPoint,
                                       float otherDistance, int options, unsigned int context)
{
    if (options == 0)
        return;
    {
        int found = 1;
        int j = 0;
        int width = (int)point->x >> 12;
        int i;
        int x;
        {
            CELL_SHELL* cell;
            {
                int y = (int)point->y >> 12;
                cell = FUN_005875a0(width, y);
                if (cell != 0)
                {
                    if (!cell->FUN_0054da20(point, distance, otherPoint, otherDistance, options, context))
                        return;
                }
                {
                    while (found != 0)
                    {
                        width -= 1;
                        y -= 1;
                        j += 2;
                        found = 0;
                        for (i = 0; i < j; i++)
                        {
                            cell = FUN_005875a0(width, y);
                            if (cell != 0 && (distance == DAT_010231b0 || cell->FUN_0054fb70(point) < distance) &&
                                (otherDistance == DAT_010231b0 || cell->FUN_0054fb70(otherPoint) < otherDistance))
                            {
                                found += 1;
                                if (!cell->FUN_0054da20(point, distance, otherPoint, otherDistance, options, context))
                                    return;
                            }
                            width += 1;
                        }
                        for (x = 0; x < j; x++)
                        {
                            cell = FUN_005875a0(width, y);
                            if (cell != 0 && (distance == DAT_010231b0 || cell->FUN_0054fb70(point) < distance) &&
                                (otherDistance == DAT_010231b0 || cell->FUN_0054fb70(otherPoint) < otherDistance))
                            {
                                found += 1;
                                if (!cell->FUN_0054da20(point, distance, otherPoint, otherDistance, options, context))
                                    return;
                            }
                            y += 1;
                        }
                        for (i = 0; i < j; i++)
                        {
                            cell = FUN_005875a0(width, y);
                            if (cell != 0 && (distance == DAT_010231b0 || cell->FUN_0054fb70(point) < distance) &&
                                (otherDistance == DAT_010231b0 || cell->FUN_0054fb70(otherPoint) < otherDistance))
                            {
                                found += 1;
                                if (!cell->FUN_0054da20(point, distance, otherPoint, otherDistance, options, context))
                                    return;
                            }
                            width -= 1;
                        }
                        for (x = 0; x < j; x++)
                        {
                            cell = FUN_005875a0(width, y);
                            if (cell != 0 && (distance == DAT_010231b0 || cell->FUN_0054fb70(point) < distance) &&
                                (otherDistance == DAT_010231b0 || cell->FUN_0054fb70(otherPoint) < otherDistance))
                            {
                                found += 1;
                                if (!cell->FUN_0054da20(point, distance, otherPoint, otherDistance, options, context))
                                    return;
                            }
                            y -= 1;
                        }
                    }
                    cell = (CELL_SHELL*)GetInteriorCell();
                    if (cell != 0)
                        cell->FUN_0054da20(point, distance, otherPoint, otherDistance, options, context);
                }
            }
        }
    }
}

struct QueryPoint2
{
    float x, y;
    QueryPoint2(float x, float y);
};
struct WorldQuery;
struct AreaQuery
{
    bool FUN_004f8360(const QueryPoint2* point);
};
struct CellQuery;
template <class T> struct QueryLink
{
    T* item;
    QueryLink* next;
    T** FUN_006815c0();
    QueryLink* FUN_00726070();
};
struct QueryNodeHeader
{
    unsigned int unk00;
};
struct CellQueryNode : QueryNodeHeader, QueryLink<CellQuery>
{
};
struct QueryData
{
    CellQueryNode* FUN_004169d0();
};
extern QueryData* g_011c3f2c;
struct CellQuery
{
    bool FUN_00549580();
    bool FUN_00440d80();
    WorldQuery* FUN_007af430();
    QueryLink<AreaQuery>* FUN_00441110();
};
struct WorldQuery
{
    bool IsFlag8Set();
    bool ContainsPoint(const NiPoint3* position);
};

// @fnv 0x00588d10
bool WorldQuery::ContainsPoint(const NiPoint3* position)
{
    if (!IsFlag8Set())
        return true;
    QueryPoint2 point3(position->x, position->y);
    bool found = false;
    CellQueryNode* node2 = g_011c3f2c->FUN_004169d0();
    while (node2 && *node2->FUN_006815c0())
    {
        CellQuery* cell2 = *node2->FUN_006815c0();
        if (cell2->FUN_00549580() && !cell2->FUN_00440d80() && cell2->FUN_007af430() == this)
        {
            QueryLink<AreaQuery>* link = cell2->FUN_00441110();
            while (link && *link->FUN_006815c0())
            {
                AreaQuery* area = *link->FUN_006815c0();
                if (area->FUN_004f8360(&point3))
                    found = true;
                link = link->FUN_00726070();
            }
        }
        node2 = static_cast<CellQueryNode*>(node2->FUN_00726070());
    }
    return found;
}

namespace fnv_00583560 {
extern "C" void* _alloca(unsigned int);
void* operator new(unsigned int);
void operator delete(void*);
class File583
{
  public:
    int FUN_00472660();
    bool FUN_00471c20();
    unsigned int GetOffset();
    int GetChunkID();
    unsigned int GetChunkSize();
    bool GetChunkData(void*, unsigned int);
    bool ReadChunkInt(void*);
    bool ReadChunkData(unsigned short*);
    bool FUN_00401680();
    bool GetNextChunk();
};
struct B006815c0
{
    float x, y;
    B006815c0();
};
struct OffsetData583
{
    unsigned int* offsets;
    B006815c0 minimum, maximum;
    unsigned int offset;
};
struct Pair583
{
    float x, y;
    void FUN_00462230();
};
struct MapData583
{
    float x, y, z, w;
    void FUN_005840b0();
};
struct Extra583
{
    unsigned int x, y, z;
    void FUN_005a6b10();
};
struct Full583
{
    unsigned int a, b, c;
};
struct Icon583
{
    unsigned int a, b, c;
};
void FUN_0048e3d0(Icon583*, File583*);
void ReadFullName(Full583*, File583*);
void FUN_00401080(void*, bool);
float FUN_0040ebd0(float, float);
float FUN_00404010(float, float);
class FUN_0058efd0
{
  public:
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    FUN_0058efd0();
    void FUN_0058f180(File583*);
};
class FUN_00589000
{
  public:
    virtual ~FUN_00589000();
    unsigned int a, b, c;
    FUN_00589000(unsigned int);
    unsigned int FUN_0084e3a0();
};
class Name583
{
  public:
    unsigned int a, b, c;
    void SetFullName(const char*);
};
class Base583
{
  public:
    virtual void virtual000();
    virtual void virtual004();
    virtual void virtual008();
    virtual void virtual00C();
    virtual void virtual010();
    virtual void virtual014();
    virtual void virtual018();
    virtual void virtual01C();
    virtual void virtual020();
    virtual void virtual024();
    virtual void virtual028();
    virtual void virtual02C();
    virtual void virtual030();
    virtual void virtual034();
    virtual void virtual038();
    virtual void virtual03C();
    virtual void virtual040();
    virtual void virtual044();
    virtual void virtual048();
    virtual void virtual04C();
    virtual void virtual050();
    virtual void virtual054();
    virtual void virtual058();
    virtual void virtual05C();
    virtual void virtual060();
    virtual void virtual064();
    virtual void virtual068();
    virtual void virtual06C();
    virtual void virtual070();
    virtual void virtual074();
    virtual void virtual078();
    virtual void virtual07C();
    virtual void virtual080();
    virtual void virtual084();
    virtual void virtual088();
    virtual void virtual08C();
    virtual void virtual090();
    virtual void virtual094();
    virtual void virtual098();
    virtual void virtual09C();
    virtual void virtual0A0();
    virtual void virtual0A4();
    virtual void virtual0A8();
    virtual void virtual0AC();
    virtual void virtual0B0();
    virtual void virtual0B4();
    virtual void virtual0B8();
    virtual void virtual0BC();
    virtual void virtual0C0();
    virtual void virtual0C4();
    virtual void virtual0C8();
    virtual void virtual0CC();
    virtual void virtual0D0();
    virtual void virtual0D4();
    virtual void virtual0D8();
    virtual void virtual0DC();
    virtual void LoadBounds(File583*);
    virtual void virtual0E4();
    virtual void virtual0E8();
    virtual void virtual0EC();
    virtual void virtual0F0();
    virtual void virtual0F4();
    virtual void virtual0F8();
    virtual void virtual0FC();
    virtual void virtual100();
    virtual void virtual104();
    virtual void virtual108();
    virtual void virtual10C();
    virtual void virtual110();
    virtual void virtual114();
    virtual void virtual118();
    virtual void virtual11C();
    virtual void virtual120();
    virtual void virtual124();
    virtual void virtual128();
    virtual void virtual12C();
    virtual void virtual130();
    virtual void SetEditorID(char*);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
};
class World583 : public Base583, public Full583, public Icon583
{
  public:
    FUN_00589000* cellMap;
    unsigned int unk34, unk38, unk3C, unk40, unk44;
    FUN_0058efd0* imageSpace;
    unsigned char flags4C, unk4D;
    unsigned short field4E;
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
    MapData583 mapData;
    Extra583 extra;
    unsigned int unk9C;
    float minX, minY, maxX, maxY;
    unsigned int unkB0, unkB4, unkB8, unkBC, unkC0, unkC4;
    float fC8, fCC;
    unsigned int fieldD0;
    Name583 nameD4, nameE0;
    OffsetData583* GetOrCreateCellOffsetData(File583*);
    void LoadRecordHeader(File583*);
    void FUN_00484ab0(int);
    void FUN_0087ce80(unsigned int);
    void FUN_008d8040(unsigned int);
    void FUN_004febb0(unsigned int);
    void FUN_00442a80(unsigned int);
    void FUN_00584150(float);
    void SetParent(unsigned int);
    void SetAssociatedActorValue(unsigned int);
    bool GetSmallWorld();
    bool FUN_00484e40();
    bool FUN_00583560(File583*);
};

struct EndianFlag583
{
    bool value;
};
// @fnv 0x00583560
bool World583::FUN_00583560(File583* file)
{
    int chunk;
    unsigned char type = file->FUN_00472660();
    if (type != 0x41)
        return false;
    if (file->FUN_00471c20())
    {
        OffsetData583* data = GetOrCreateCellOffsetData(file);
        data->offset = file->GetOffset();
    }
    LoadRecordHeader(file);
    FUN_00484ab0(0);
    while ((chunk = file->GetChunkID()) != 0)
    {
        switch (chunk)
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(editorID, 0x200);
            SetEditorID(editorID);
            break;
        }
        case 0x444e424f:
            LoadBounds(file);
            break;
        case 0x4e4f4349:
            FUN_0048e3d0(this, file);
            break;
        case 0x4c4c5546:
            ReadFullName(this, file);
            break;
        case 0x41544144: {
            if (file->GetChunkSize() == 4)
            {
                unsigned int flags = 0;
                file->ReadChunkInt(&flags);
                flags4C = (unsigned char)flags;
            }
            else
                file->GetChunkData(&flags4C, 1);
            break;
        }
        case 0x5453464f: {
            unsigned int size = file->GetChunkSize();
            if (size)
            {
                OffsetData583* data;
                {
                    unsigned int count = size >> 2;
                    data = GetOrCreateCellOffsetData(file);
                    if (data->offsets)
                        delete data->offsets;
                    data->offsets = new unsigned int[count];
                    file->GetChunkData(data->offsets, 0);
                    if (file->FUN_00401680())
                    {
                        for (unsigned int i = 0; i < count; i++)
                            FUN_00401080(&data->offsets[i], EndianFlag583().value);
                    }
                }
            }
            break;
        }
        case 0x4e5a4558: {
            unsigned int value = 0;
            file->ReadChunkInt(&value);
            fieldD0 = value;
            break;
        }
        case 0x4d414e43: {
            unsigned int value = 0;
            file->ReadChunkInt(&value);
            FUN_0087ce80(value);
            break;
        }
        case 0x4d414e49: {
            unsigned int value = 0;
            file->ReadChunkInt(&value);
            FUN_008d8040(value);
            break;
        }
        case 0x324d414e: {
            unsigned int value = 0;
            file->ReadChunkInt(&value);
            FUN_004febb0(value);
            break;
        }
        case 0x334d414e: {
            unsigned int value = 0;
            file->ReadChunkInt(&value);
            FUN_00442a80(value);
            break;
        }
        case 0x344d414e: {
            float value = 0;
            file->ReadChunkInt(&value);
            FUN_00584150(value);
            break;
        }
        case 0x4d414e57: {
            unsigned int value = 0;
            file->ReadChunkInt(&value);
            SetParent(value);
            field4E = 0xffff;
            break;
        }
        case 0x4d414e50:
            file->ReadChunkData(&field4E);
            break;
        case 0x4d414e44: {
            Pair583 value;
            file->GetChunkData(&value, 8);
            if (file->FUN_00401680())
                value.FUN_00462230();
            fC8 = value.x;
            fCC = value.y;
            break;
        }
        case 0x4d414e4d:
            file->GetChunkData(&mapData, 16);
            if (file->FUN_00401680())
                mapData.FUN_005840b0();
            break;
        case 0x4d414e4f:
            file->GetChunkData(&extra, 12);
            if (file->FUN_00401680())
                extra.FUN_005a6b10();
            break;
        case 0x4d414e53: {
            unsigned int value = 0;
            file->ReadChunkInt(&value);
            break;
        }
        case 0x4d414e5a: {
            unsigned int value = 0;
            file->ReadChunkInt(&value);
            SetAssociatedActorValue(value);
            break;
        }
        case 0x46504d49:
        case 0x53504d49:
            if (!imageSpace)
                imageSpace = new FUN_0058efd0;
            imageSpace->FUN_0058f180(file);
            break;
        case 0x4d414e4e: {
            unsigned int size = file->GetChunkSize();
            if (size)
            {
                char* text = (char*)_alloca(size);
                file->GetChunkData(text, size);
                nameD4.SetFullName(text);
            }
            break;
        }
        case 0x4d414e58: {
            unsigned int size = file->GetChunkSize();
            if (size)
            {
                char* text = (char*)_alloca(size);
                file->GetChunkData(text, size);
                nameE0.SetFullName(text);
            }
            break;
        }
        case 0x304d414e: {
            B006815c0 value;
            file->GetChunkData(&value, 8);
            if (file->FUN_00401680())
            {
                FUN_00401080(&value.x, EndianFlag583().value);
                FUN_00401080(&value.y, EndianFlag583().value);
            }
            minX = FUN_0040ebd0(minX, value.x);
            minY = FUN_0040ebd0(minY, value.y);
            if (file->FUN_00471c20())
            {
                OffsetData583* data = GetOrCreateCellOffsetData(file);
                data->minimum = value;
            }
            break;
        }
        case 0x394d414e: {
            B006815c0 value;
            file->GetChunkData(&value, 8);
            if (file->FUN_00401680())
            {
                FUN_00401080(&value.x, EndianFlag583().value);
                FUN_00401080(&value.y, EndianFlag583().value);
            }
            maxX = FUN_00404010(maxX, value.x);
            maxY = FUN_00404010(maxY, value.y);
            if (file->FUN_00471c20())
            {
                OffsetData583* data = GetOrCreateCellOffsetData(file);
                data->maximum = value;
            }
            break;
        }
        }
        if (!file->GetNextChunk())
            break;
    }
    if (!cellMap->FUN_0084e3a0() && !GetSmallWorld())
    {
        delete cellMap;
        if (FUN_00484e40())
            cellMap = new FUN_00589000(7001);
        else
            cellMap = new FUN_00589000(701);
    }
    return true;
}
}  // namespace fnv_00583560

namespace fnv_005878d0 {
class Pt
{
  public:
    float x;
    float y;
    float z;
    float Length() const;
};
class StrList
{
  public:
    int a;
    int b;
    StrList();
};
class DummyPointerMap
{
  public:
    int a;
    int b;
    int c;
    int d;
    DummyPointerMap(int);
    bool GetAt(unsigned int, int&) const;
    void SetAt(unsigned int, unsigned int);
};
class SetAtHelper
{
  public:
    void FUN_005ae3d0(void**);
};
class RefObj
{
  public:
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
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
    virtual Pt* v125();
    bool FUN_00439f90();
    Pt* FUN_00569880();
};
bool BoundIntersectsCell(RefObj*, int, int);
int TruncateFloatToInt(float);
class WorldObj
{
  public:
    char pad68[0x68];
    DummyPointerMap* map;
    void FUN_005878d0(RefObj*);
};

// @fnv 0x005878d0
void WorldObj::FUN_005878d0(RefObj* pRef)
{
    if (pRef)
    {
        if (pRef->FUN_00439f90())
        {
            Pt ptPos3 = *pRef->FUN_00569880();
            float fLen7 = ptPos3.Length();
            int iXMin5 = TruncateFloatToInt(pRef->v125()->x - fLen7) >> 12;
            int iYMin8 = TruncateFloatToInt(pRef->v125()->y - fLen7) >> 12;
            int iXMax9 = TruncateFloatToInt(pRef->v125()->x + fLen7) >> 12;
            int iYMaxA = TruncateFloatToInt(pRef->v125()->y + fLen7) >> 12;
            int iCX3 = TruncateFloatToInt(pRef->v125()->x) >> 12;
            int iCY = TruncateFloatToInt(pRef->v125()->y) >> 12;
            for (int i_ = iXMin5; i_ <= iXMax9; ++i_)
            {
                for (int j2 = iYMin8; j2 <= iYMaxA; ++j2)
                {
                    if (i_ != iCX3 || j2 != iCY)
                    {
                        if (BoundIntersectsCell(pRef, i_, j2))
                        {
                            if (!map)
                                map = new DummyPointerMap(0x25);
                            unsigned int key3 = TESWorldSpace::BuildCellKey((short)i_, (short)j2);
                            int val = 0;
                            map->GetAt(key3, val);
                            if (!val)
                            {
                                val = (int)new StrList();
                                map->SetAt(key3, val);
                            }
                            ((SetAtHelper*)val)->FUN_005ae3d0((void**)&pRef);
                        }
                    }
                }
            }
        }
    }
}
}  // namespace fnv_005878d0

struct String65
{
    char* text;
    unsigned short length, capacity;
    String65();
    ~String65();
    bool Set(const char*, unsigned = 0);
    operator const char*() const;
    unsigned Length();
    int StrCmp(const char*, bool = true) const;
};
struct Pos65
{
    float x, y, z;
    Pos65();
    bool FUN_004390c0(const Pos65&);
};
struct Point65
{
    float x, y;
    Point65(const Pos65&);
};
struct Area65
{
    bool FUN_004f8360(const Point65&);
};
struct AreaList65
{
    Area65** FUN_006815c0();
    AreaList65* FUN_00726070();
    bool FUN_008256d0();
    void* FUN_004f6800(int, const Pos65&, void*);
};
struct Data65
{
    bool FUN_004f1540();
    unsigned char FUN_005bb4d0();
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
    virtual void v28(String65*);
};
struct Manager65
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual Data65* v10(void*);
};
struct Region65
{
    bool FUN_00440d80();
    void* FUN_007af430();
    AreaList65* FUN_00441110();
    void* FUN_009611e0();
};
struct RegionNode65
{
    Region65** FUN_006815c0();
    RegionNode65* FUN_00726070();
};
struct RegionPrefix65
{
    int unk00;
};
struct RegionHead65 : RegionPrefix65, RegionNode65
{
};
struct Type65
{
    void* FUN_004f35b0(int);
};
struct Cell65
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    FNStub fullName;
    AreaList65* FUN_00547110(bool);
};
struct Handler65
{
    Cell65* FUN_00461bc0(float, float, void*, bool);
    Manager65* GetRegionDataManager();
    RegionHead65* FUN_004169d0();
};
struct World65
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    FNStub fullName;
    bool FUN_00586500(String65*, Pos65);
};
// Selects a name for pos from its cell or matching regions, falls back to this world's full name or FUN_00586980, and reports whether output changed.
// @fnv 0x00586500
bool World65::FUN_00586500(String65* output, Pos65 pos)
{
    static String65 lastName;
    static Pos65 lastPos;
    static World65* lastWorld;
    Data65* data7 = 0;
    if (!g_dataHandler)
        return false;
    if (lastWorld == this && lastPos.FUN_004390c0(pos))
    {
        output->Set(lastName);
        return false;
    }
    if (lastWorld != this)
        lastName.Set("");
    lastWorld = this;
    lastPos = pos;
    output->Set("");
    Cell65* cellVal = ((Handler65*)g_dataHandler)->FUN_00461bc0(pos.x, pos.y, this, false);
    if (cellVal)
    {
        data7 = cellVal->FUN_00547110(true) ? ((Handler65*)g_dataHandler)
                                                  ->GetRegionDataManager()
                                                  ->v10(cellVal->FUN_00547110(true)->FUN_004f6800(4, pos, this))
                                            : 0;
        if (data7)
            data7->v28(output);
        else
            output->Set(cellVal->fullName.GetFullName());
    }
    else
    {
        Region65* region4;
        Area65* area;
        RegionNode65* node5 = ((Handler65*)g_dataHandler)->FUN_004169d0();
        AreaList65* areas = 0;
        Point65 point2(pos);
        int priority6 = -1;
        bool contains3 = false;
        bool aOverrideFlag = false;
        while (node5 && *node5->FUN_006815c0())
        {
            contains3 = false;
            region4 = *node5->FUN_006815c0();
            if (region4->FUN_00440d80() || region4->FUN_007af430() != this || !region4->FUN_00441110() ||
                region4->FUN_00441110()->FUN_008256d0())
            {
                node5 = node5->FUN_00726070();
                continue;
            }
            data7 = ((Handler65*)g_dataHandler)
                        ->GetRegionDataManager()
                        ->v10(((Type65*)region4->FUN_009611e0())->FUN_004f35b0(4));
            if (!data7)
            {
                node5 = node5->FUN_00726070();
                continue;
            }
            areas = region4->FUN_00441110();
            while (areas && *areas->FUN_006815c0())
            {
                area = *areas->FUN_006815c0();
                if (area->FUN_004f8360(point2))
                {
                    contains3 = true;
                    break;
                }
                areas = areas->FUN_00726070();
            }
            if (!contains3)
            {
                node5 = node5->FUN_00726070();
                continue;
            }
            if (data7->FUN_004f1540())
            {
                if (aOverrideFlag && data7->FUN_005bb4d0() <= priority6)
                {
                    node5 = node5->FUN_00726070();
                    continue;
                }
            }
            else if (aOverrideFlag || data7->FUN_005bb4d0() <= priority6)
            {
                node5 = node5->FUN_00726070();
                continue;
            }
            aOverrideFlag = data7->FUN_004f1540();
            priority6 = data7->FUN_005bb4d0();
            data7->v28(output);
            node5 = node5->FUN_00726070();
        }
    }
    if (!output->Length())
        output->Set(fullName.GetFullName());
    if (!output->Length())
        output->Set(FUN_00586980());
    if (output->StrCmp(lastName))
    {
        lastName.Set(*output);
        return true;
    }
    return false;
}

struct WorldSpaceRefShell : public TESWorldSpace
{
    void FUN_00587d10(TESObjectREFR*);
};

struct ATM_587D10
{
    void QueryPerformanceCounter(int);
    void WaitForTasksDuringRendering();
};
struct Pt3_587D10
{
    float x, y, z;
};
struct RefV_587D10
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
    virtual Pt3_587D10* GetPos();
};
namespace WsH_587D10 {
int __cdecl GetKeyForWorldCoord(Pt3_587D10 const&);
}
bool __cdecl FUN_00587c80(void*);
struct RefList_587D10
{
    int a;
    int b;
    void AddHead(int*);
};
struct RefListNode_587D10 : RefList_587D10
{
    RefListNode_587D10();
};
struct SetAt_587D10
{
    void SetAt(unsigned int, unsigned int);
};
struct PtrMap_587D10
{
    bool GetAt(unsigned int, unsigned int&);
};

// Adds apRef to a list directly or to a coordinate-keyed list, skipping null and temporary references.
// @fnv 0x00587d10
void WorldSpaceRefShell::FUN_00587d10(TESObjectREFR* apRef)
{
    if (apRef && !apRef->IsTemporary())
    {
        g_011ca60c.QueryPerformanceCounter(0);
        if (!FUN_00587c80(apRef))
        {
            ((RefList_587D10*)((char*)this + 0x60))->AddHead((int*)&apRef);
        }
        else
        {
            unsigned int ikey = WsH_587D10::GetKeyForWorldCoord(*((RefV_587D10*)apRef)->GetPos());
            RefListNode_587D10* preflist = 0;
            ((PtrMap_587D10*)((char*)this + 0x50))->GetAt(ikey, (unsigned int&)preflist);
            if (!preflist)
            {
                preflist = new RefListNode_587D10;
                ((SetAt_587D10*)((char*)this + 0x50))->SetAt(ikey, (unsigned int)preflist);
            }
            preflist->AddHead((int*)&apRef);
        }
        g_011ca60c.WaitForTasksDuringRendering();
    }
}
