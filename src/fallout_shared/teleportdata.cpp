// fallout_shared/teleportdata.cpp: BaseProcess, QuantityData, Thing, RefHandle and more (22 functions)
#include "teleportdata_decls.h"
#include "teleportdata_types_DoorTeleportData.h"

// @fnv 0x00717e50
ActorPackageContext* BaseProcess::GetCurrentProcessData(void)
{
    return &m_kProcessData;
}

// @fnv 0x008b3bb0
TESForm* TeleportableReference::GetTeleportDestinationForm(void)
{
    return ((DoorTeleportSpaceOwner*)this)->receiver->FUN_009dcd40();
}

// @fnv 0x0043a320
TESWorldSpace* TeleportableReference::GetTeleportWorldspace(void)
{
    TESWorldSpace* result = 0;
    if (m_pLinkedDoorReference)
    {
        DoorCell* cell = (DoorCell*)m_pLinkedDoorReference->GetParentCell();
        if (cell)
            result = cell->GetParentWorldSpace();
        else
        {
            cell = ((DoorCellProvider*)((char*)m_pLinkedDoorReference + 0x18))->vfn_0();
            if (cell)
                result = cell->GetParentWorldSpace();
        }
    }
    return result;
}

// @fnv 0x0043a210
void TeleportableReference::SetLinkedDoorReference(TESObjectREFR* reference, bool set)
{
    DoorCell* cell;
    if (reference)
    {
        cell = FUN_0043a2b0();
        if (cell && cell->GetOwner())
            cell->SetTempPublic(set);
        cell = (DoorCell*)reference->GetParentCell();
        if (cell && cell->GetOwner())
            cell->SetTempPublic(set);
    }
}

// @fnv 0x0043a4e0
void TeleportableReference::Load(TESFile* file)
{
    if (file && file->GetChunkID() == 0x4c455458)
    {
        DoorTeleportLoadData data;
        data.FUN_0055a400();
        memset(&data, 0, 32);
        file->GetChunkData(&data, 32);
        if (file->IsEndianConversionRequired())
            data.SwapEndian();
        m_pLinkedDoorReference = data.door;
        position = data.position;
        rotation = data.rotation;
        cFlags = data.flags;
    }
}

// @fnv 0x0043a2b0
DoorCell* TeleportableReference::FUN_0043a2b0(void)
{
    if (m_pLinkedDoorReference)
        return (DoorCell*)m_pLinkedDoorReference->GetParentCell();
    return 0;
}

template <int N> struct EndianSizeTag
{
};

void BSEndian(int*, EndianSizeTag<4>);

struct FUN_00414030_shell
{
    void SwapEndian();
};

// Swaps the byte order of seven consecutive 4-byte integers starting at this object's address using BSEndian.
// @fnv 0x00414030
void FUN_00414030_shell::SwapEndian()
{
    BSEndian((int*)this, EndianSizeTag<4>());
    BSEndian((int*)this + 1, EndianSizeTag<4>());
    BSEndian((int*)this + 2, EndianSizeTag<4>());
    BSEndian((int*)this + 3, EndianSizeTag<4>());
    BSEndian((int*)this + 4, EndianSizeTag<4>());
    BSEndian((int*)this + 5, EndianSizeTag<4>());
    BSEndian((int*)this + 6, EndianSizeTag<4>());
}

struct BSExtraData
{
    int m_iType;
    int m_uiLogicalSize;
    int m_iValue;
    int m_iPad;
};

struct FUN_00431ae0 : public BSExtraData
{
    FUN_00431ae0(int value);
};

struct ExtraListRemover
{
    void RemoveExtra(BSExtraData* extra, bool clear);
};

struct FUN_004197d0_shell : public BaseExtraList
{
    void SetExtraDataValue(int value);
};

// Sets the value of extra data type 0x22, removing it when zero or creating and adding it when absent.
// @fnv 0x004197d0
void FUN_004197d0_shell::SetExtraDataValue(int value)
{
    BSExtraData* extra = GetExtraData(0x22);
    if (extra)
    {
        if (!value)
        {
            ((ExtraListRemover*)this)->RemoveExtra(extra, true);
        }
        else
        {
            *(int*)((char*)extra + 0xc) = value;
        }
    }
    else if (value)
    {
        extra = new FUN_00431ae0(value);
        AddExtra(extra);
    }
}

extern float DAT_01016450;
struct R6815c0
{
    void _ref_006815c0();
};
NiPoint3* __fastcall FUN_00416870(NiPoint3*, float, float, float);

// Sets the first four bytes and the byte at offset 0x1c to zero, then assigns two NiPoint3 values built from DAT_01016450.
// @fnv 0x0043a160
TeleportableReference* __fastcall FUN_0043a160(TeleportableReference* self)
{
    NiPoint3 a;
    NiPoint3 b;
    ((R6815c0*)((char*)self + 4))->_ref_006815c0();
    ((R6815c0*)((char*)self + 0x10))->_ref_006815c0();
    *(int*)self = 0;
    ((char*)self)[0x1c] = 0;
    *(NiPoint3*)((char*)self + 4) = *FUN_00416870(&a, DAT_01016450, DAT_01016450, DAT_01016450);
    *(NiPoint3*)((char*)self + 0x10) = *FUN_00416870(&b, DAT_01016450, DAT_01016450, DAT_01016450);
    return self;
}

struct FUN_0043a280_shell
{
    char pad[0x10];
    NiPoint3 m_vec;
    void SetVec(const NiPoint3& arVec);
};

// Assigns arVec to m_vec.
// @fnv 0x0043a280
void FUN_0043a280_shell::SetVec(const NiPoint3& arVec)
{
    m_vec = arVec;
}

struct BSStr
{
    bool Set(char const*, unsigned int);
};
extern const char $SG4382[];
struct FUN_00578870_host
{
    void FUN_00578870(BSStr*);
};
struct FUN_0043a2e0_host
{
    FUN_00578870_host* m;
    void SetString(BSStr*);
};
// If m is non-null, calls m->FUN_00578870(a); otherwise calls a->Set($SG4382, 0).
// @fnv 0x0043a2e0
void FUN_0043a2e0_host::SetString(BSStr* apStr)
{
    if (m)
        m->FUN_00578870(apStr);
    else
        apStr->Set($SG4382, 0);
}

struct UnkArg
{
    void FUN_0043a3c0(ActorPackageContext*, int);
};
struct UnkThis : BaseProcess
{
    int FUN_0043a3f0();
    UnkArg* FUN_0043a390(UnkArg*);
};
// Calls a->FUN_0043a3c0 with GetCurrentProcessData() and FUN_0043a3f0(), then returns a.
// @fnv 0x0043a390
UnkArg* UnkThis::FUN_0043a390(UnkArg* apArg)
{
    apArg->FUN_0043a3c0(GetCurrentProcessData(), FUN_0043a3f0());
    return apArg;
}

struct FUN_0043a3c0
{
    NiPoint3 Point;
    TESForm* m_pPathingCell;
    FUN_0043a3c0(const NiPoint3& aPoint, TESForm* aSpace);
};

// @fnv 0x0043a3c0
FUN_0043a3c0::FUN_0043a3c0(const NiPoint3& aPoint, TESForm* aSpace)
{
    Point = aPoint;
    m_pPathingCell = aSpace;
}

struct Callee_575ca0
{
    int FUN_00575ca0();
};
struct Caller_43a3f0
{
    Callee_575ca0* p;
    int FUN_0043a3f0();
};
// Returns the result of calling FUN_00575ca0 on p when p is non-null, otherwise returns 0.
// @fnv 0x0043a3f0
int Caller_43a3f0::FUN_0043a3f0()
{
    return p ? p->FUN_00575ca0() : 0;
}

unsigned int __fastcall _FNV_GetFormID(TESObjectREFR* object);
bool _FUN_00401500();
void _FUN_00485990(unsigned int type, void* data, unsigned int size);

struct FUN_0043a420_shell : public DoorTeleportLoadData
{
    void FUN_0043a420();
};

// Copies the door FormID, position, rotation, and flags into data, conditionally calls SwapEndian, and passes data to _FUN_00485990.
// @fnv 0x0043a420
void FUN_0043a420_shell::FUN_0043a420()
{
    DoorTeleportLoadData data;

    if (!door)
        return;

    data.FUN_0055a400();
    memset(&data, 0, sizeof(data));

    *reinterpret_cast<unsigned int*>(&data.door) = _FNV_GetFormID(door);
    data.position = position;
    data.rotation = rotation;
    data.flags = flags;

    if (_FUN_00401500())
        data.SwapEndian();

    _FUN_00485990(0x4c455458, &data, sizeof(data));

    if (_FUN_00401500())
        data.SwapEndian();
}

struct Flt
{
    operator unsigned int();
};
struct QuantityData
{
    char _pad[0x1C];
    unsigned char byte1C;
    void SetQuantity(unsigned int);
    void FUN_006f4ed0(ActorPackageContext*);
    void SetVec(BSSimpleList<TESFile*>*);
    void CopyFrom(void*);
};
// @fnv 0x0043a810
void QuantityData::CopyFrom(void* apOther)
{
    SetQuantity(((Flt*)apOther)->operator unsigned int());
    FUN_006f4ed0(((BaseProcess*)apOther)->GetCurrentProcessData());
    SetVec(((TESForm*)apOther)->GetSourceFiles());
    byte1C = ((QuantityData*)apOther)->byte1C;
}

struct GO
{
    operator unsigned int() const;
};

struct Call_439090
{
    bool _Call_439090(void* pObject);
};

struct FUN_0043a860_shell
{
    bool FUN_0043a860(TeleportableReference* apCompare);
};

// Returns true if the GO value, process data, source files, or the byte at offset 0x1c differ between this and apCompare.
// @fnv 0x0043a860
bool FUN_0043a860_shell::FUN_0043a860(TeleportableReference* apCompare)
{
    if (reinterpret_cast<GO*>(this)->operator unsigned int() !=
        reinterpret_cast<GO*>(apCompare)->operator unsigned int())
        return true;

    if (reinterpret_cast<Call_439090*>(reinterpret_cast<BaseProcess*>(this)->GetCurrentProcessData())
            ->_Call_439090(reinterpret_cast<BaseProcess*>(apCompare)->GetCurrentProcessData()))
        return true;

    if (reinterpret_cast<Call_439090*>(reinterpret_cast<TESForm*>(this)->GetSourceFiles())
            ->_Call_439090(reinterpret_cast<TESForm*>(apCompare)->GetSourceFiles()))
        return true;

    if (*(reinterpret_cast<unsigned char*>(this) + 0x1c) != *(reinterpret_cast<unsigned char*>(apCompare) + 0x1c))
        return true;

    return false;
}

struct FUN_0043a8f0_shell
{
    unsigned short __thiscall FUN_0043a8f0();
};

// Returns 0x1c, computed by adding 0xc, 0xc, and 4 to an unsigned short initialized to zero.
// @fnv 0x0043a8f0
unsigned short __thiscall FUN_0043a8f0_shell::FUN_0043a8f0()
{
    unsigned short v = 0;
    v += 0xc;
    v += 0xc;
    v += 4;
    return v;
}

class Other
{
  public:
    int FUN_0084e3a0();
};

class TESSaveLoadGame
{
  public:
    void FUN_008579b0(void* data, int size);
    void FUN_00857a10(void* data, int size);
};

extern TESSaveLoadGame* DAT_011de45c;

struct Thing
{
    Other* m_object;
    char m_data04[12];
    char m_data10[12];
    void Save();
};

// Saves the 12-byte data blocks and the form ID of m_object to the save stream via TESSaveLoadGame.
// @fnv 0x0043a930
void Thing::Save()
{
    DAT_011de45c->FUN_008579b0(m_data04, 0xc);
    DAT_011de45c->FUN_008579b0(m_data10, 0xc);
    int formID = 0;
    if (m_object != 0)
        formID = m_object->FUN_0084e3a0();
    DAT_011de45c->FUN_00857a10(&formID, 4);
}

TESForm* FUN_004839c0(unsigned int auiFormId);

namespace s835fe0 {

struct RefHandle
{
    TESObjectREFR* m_pkRef;

    void ResolveRef(void* pvUnused);
};

// Replaces m_pkRef with the result of FUN_004839c0 cast to TESObjectREFR, or null if m_pkRef is null.
// @fnv 0x00835fe0
void RefHandle::ResolveRef(void* pvUnused)
{
    m_pkRef = m_pkRef ? dynamic_cast<TESObjectREFR*>(FUN_004839c0((unsigned int)m_pkRef)) : 0;
}

}

struct CoordinateTriple
{
    bool FUN_00527a00();
};

bool CoordinateTriple::FUN_00527a00()
{
    return false;
}

struct TESObjectREFR_ext : public TESObjectREFR
{
    bool GetReferencePersistence();
};

bool __thiscall TESObjectREFR_ext::GetReferencePersistence()
{
    return false;
}

// Returns true when either called predicate is true; otherwise returns false.
// @fnv 0x009a96f0
bool FUN_009a96f0(TESObjectREFR* refr, CoordinateTriple* location)
{
    if (((TESObjectREFR_ext*)refr)->GetReferencePersistence())
        return true;
    if (location->FUN_00527a00())
        return true;
    return false;
}

struct FUN_0043a590_shell : public TeleportableReference
{
    bool FUN_0043a590(TESForm*);
};

void __cdecl FUN_00485d50(unsigned int* formID, TESFile* file);
TESForm* __cdecl FUN_004839c0(unsigned int formID);
void __cdecl FUN_005b5e40(const char* fmt, ...);
int __cdecl FUN_00ec7595(double x);
int __cdecl FUN_00ec75b1(double x);

struct TeleportFormTypeName
{
    const char* name;
    int unk04;
    int unk08;
};

extern TeleportFormTypeName DAT_01187004[];

// Resolves the linked door, checks its form type, and resets position or rotation to zero when their checks fail.
// @fnv 0x0043a590
bool FUN_0043a590_shell::FUN_0043a590(TESForm* form)
{
    unsigned int formID = (unsigned int)m_pLinkedDoorReference;
    FUN_00485d50(&formID, form->GetFile(-1));
    m_pLinkedDoorReference = dynamic_cast<TESObjectREFR*>(FUN_004839c0(formID));
    if (!m_pLinkedDoorReference)
    {
        FUN_005b5e40(FNV_NoDoor, formID);
        return false;
    }
    if (((TESFormTypeView*)m_pLinkedDoorReference->GetObjectReference())->GetFormType() != 0x1C)
    {
        FUN_005b5e40(FNV_InvalidDoor, formID,
                     DAT_01187004[((TESFormTypeView*)m_pLinkedDoorReference->GetObjectReference())->GetFormType()].name,
                     ((TESForm*)m_pLinkedDoorReference->GetObjectReference())->GetName(),
                     ((TESForm*)m_pLinkedDoorReference->GetObjectReference())->GetFormID());
        m_pLinkedDoorReference = 0;
        return false;
    }
    if (!FUN_00ec7595(position.x) || !FUN_00ec7595(position.y) || !FUN_00ec7595(position.z) ||
        FUN_00ec75b1(position.x) || FUN_00ec75b1(position.y) || FUN_00ec75b1(position.z))
    {
        FUN_005b5e40(FNV_BadLocation);
        position = NiPoint3::ZERO;
    }
    if (!FUN_00ec7595(rotation.x) || !FUN_00ec7595(rotation.y) || !FUN_00ec7595(rotation.z) ||
        FUN_00ec75b1(rotation.x) || FUN_00ec75b1(rotation.y) || FUN_00ec75b1(rotation.z))
    {
        FUN_005b5e40(FNV_BadAngle);
        rotation = NiPoint3::ZERO;
    }
    return true;
}
