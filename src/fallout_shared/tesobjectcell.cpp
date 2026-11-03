// fallout_shared/tesobjectcell.cpp: TESObjectCELL, Owner, Cell, hkpEntityListener and more (325 functions)

#include "tesobjectcell_packet.h"
void __cdecl operator delete(void* pointer);

const char kTESObjectCELLCellRefLockEnter[] = "TESObjectCELL::CellRefLockEnter()";

// Returns the x coordinate of the exterior cell data, or 0 if the cell has no exterior data.
// @fnv 0x00544c30
int TESObjectCELL::GetCellGridX()
{
    ExteriorCellData* data = GetExteriorData();
    if (data)
        return data->x;
    return 0;
}

// Returns the y coordinate of the exterior cell data, or 0 if the cell has no exterior data.
// @fnv 0x00544c60
int TESObjectCELL::GetCellGridY()
{
    ExteriorCellData* data = GetExteriorData();
    if (data)
        return data->y;
    return 0;
}

// Returns true if the cell's extra data list contains extra data of type 9, otherwise false.
// @fnv 0x00551620
bool TESObjectCELL::HasCellExtraData()
{
    if (extraDataList.GetExtraData(9))
        return true;
    return false;
}

// @fnv 0x0054ddd0
TESWorldSpace* TESObjectCELL::GetParentWorldSpace()
{
    TESWorldSpace* result = 0;
    if (!IsCellInterior())
        result = worldSpace;
    return result;
}

// @fnv 0x00541ac0
void TESObjectCELL::CellRefLockEnter()
{
    refListLock.Lock(kTESObjectCELLCellRefLockEnter);
}

// Removes non-persistent cell data, deletes cellData, clears the lighting template and unknownDC.
// @fnv 0x00541b00
void TESObjectCELL::ClearData()
{
    extraDataList.RemoveNonPersistentCellData();
    if (IsCellInterior())
    {
        void* data = cellData;
        operator delete(data);
    }
    else
    {
        void* data = cellData;
        operator delete(data);
    }
    cellData = 0;
    SetLightingTemplate(0);
    unknownDC = 0;
}

// @fnv 0x00543c30
unsigned char TESObjectCELL::GetField24()
{
    return field24;
}

// @fnv 0x00542d20
unsigned char TESObjectCELL::FUN_00542d20()
{
    return field619;
}

// @fnv 0x005454d0
void* TESObjectCELL::FUN_005454d0()
{
    return field760;
}

// @fnv 0x00552bb0
unsigned char TESObjectCELL::FUN_00552bb0()
{
    return field210;
}

// @fnv 0x00553b90
unsigned char TESSound::GetField45()
{
    return field45;
}

// @fnv 0x0054f4c0
unsigned int FUN_0054f4c0()
{
    return DAT_011ca438;
}

// @fnv 0x0054f4f0
NiAVObject* FUN_0054f4f0()
{
    return g_011deda4.operator->();
}

// @fnv 0x00462270
TESRecordHeader* TESFile::GetRecordHeader()
{
    return reinterpret_cast<TESRecordHeader*>(pad + 0x240);
}

// @fnv 0x009185e0
unsigned int PlayerMover::GetActorStateFlags()
{
    return moveMode;
}

// @fnv 0x004503f0
int TESObjectCELL::GetCellStandValue()
{
    return reinterpret_cast<SettingT_GameSettingCollection_*>(this)->Int()->i;
}

// @fnv 0x005497a0
NiAVObject* TESObjectCELL::GetDynamicNode()
{
    return GetCellChildAt(4);
}

// @fnv 0x00456fc0
NiAVObject* TESObjectCELL::GetCellChildAt(int index)
{
    NiNode* node = FUN_00545cb0();
    return node ? node->FUN_0043b4a0(index) : 0;
}

// @fnv 0x00546c20
BGSEncounterZone* TESObjectCELL::FindEncounterZone() const
{
    BGSEncounterZone* zone =
        reinterpret_cast<ExtraDataList*>(
            reinterpret_cast<TESDataHandler*>(const_cast<TESObjectCELL*>(this))->GetTESImageSpaceModifierList())
            ->FindEncounterZone();
    if (!zone && const_cast<TESObjectCELL*>(this)->GetParentWorldSpace())
        zone = const_cast<TESObjectCELL*>(this)->GetParentWorldSpace()->FindEncounterZone();
    return zone;
}

// Returns the owner from the extra data list, falling back to the encounter zone's parent when no owner is set.
// @fnv 0x00546a40
TESForm* DoorCell::GetOwner()
{
    TESForm* owner =
        reinterpret_cast<ExtraDataList*>(reinterpret_cast<TESDataHandler*>(this)->GetTESImageSpaceModifierList())
            ->GetOwner();
    if (!owner)
    {
        BGSEncounterZone* zone = reinterpret_cast<TESObjectCELL*>(this)->FindEncounterZone();
        if (zone && zone != TESObjectREFR::FindEncounterZone())
            owner = reinterpret_cast<TESForm*>(reinterpret_cast<NiAVObject*>(zone)->GetParent());
    }
    return owner;
}

// Returns the interior cell's clip distance, or a value from GetLightingTemplate() when flag 0x80 is set; returns 0.0f if there is no interior data.
// @fnv 0x00544bd0
float TESObjectCELL::GetInteriorLightValue()
{
    InteriorCellData* data = GetInteriorData();
    if (data)
    {
        if (FUN_00558b80(0x80) && GetLightingTemplate())
            return GetLightingTemplate()->FUN_009a9350();
        return data->clipDist;
    }
    return 0.0f;
}

// @fnv 0x00557470
void TESObjectCELL::ClearCellReferenceList()
{
    CellRefLockEnter();
    BSSimpleList<BGSPerkEntry*>* node = FUN_009604f0();
    while (node)
    {
        BGSPerkEntry* reference = node->GetItem();
        if (reference)
            DAT_011c95c8->FUN_00526f20(reference);
        node = node->GetNext();
    }
    CellRefLockLeave();
}

// Deletes each BGSPerkEntry in audioMarkers, clears the list, and resets audioMarkerCount to 0.
// @fnv 0x00947d10
void TESObjectCELL::ClearAudioMarkers()
{
    BSSimpleList<BGSPerkEntry*>* node = reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(&audioMarkers);
    while (node)
    {
        BGSPerkEntry* item = node->GetItem();
        delete item;
        node = node->GetNext();
    }
    audioMarkers.RemoveAll();
    audioMarkerCount = 0;
}

struct FUN_004610d0_shell : public TESObjectCELL
{
    ExtraDataList* GetExtraDataList();
};

// @fnv 0x004610d0
ExtraDataList* FUN_004610d0_shell::GetExtraDataList()
{
    return (ExtraDataList*)((char*)this + 0x28);
}

void* __cdecl DeallocateIfPresent(const void* apBody);

// @fnv 0x004b5a80
void* __cdecl FUN_004b5a80(const void* apBody)
{
    return DeallocateIfPresent(apBody);
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

class NiNode;
template <class T> class NiPointer
{
  public:
    NiPointer<T>& operator=(T*);
};

extern int _NiPoint3_ZERO;
extern int DAT_011f4270;
extern int DAT_011f4274;
extern int DAT_011ca08c;
extern NiPointer<NiNode> g_011ca0d8;
NiNode* __cdecl FUN_00554010(NiPoint3*);
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting37;
extern double DAT_01016968;
extern float const g_011c7b14_arg1;

struct SettingFloatHelper : SettingT_GameSettingCollection_
{
    float* Float();
    void FUN_004ed780(float);
};

// @fnv 0x00541b80
void FUN_00541b80()
{
    NiPoint3 center;
    *(int*)&center.x = _NiPoint3_ZERO;
    *(int*)&center.y = DAT_011f4270;
    *(int*)&center.z = DAT_011f4274;
    DAT_011ca08c = 0;
    g_011ca0d8 = FUN_00554010(&center);
    if (*((SettingFloatHelper*)&originalRuntimeFloatSetting37)->Float() > DAT_01016968)
    {
        ((SettingFloatHelper*)&originalRuntimeFloatSetting37)->FUN_004ed780(g_011c7b14_arg1);
    }
}

struct FUN_00544390_shell : public TESObjectCELL
{
    void SetFlag40(bool);
};

// Sets or clears bit 0x40 in the byte at offset 0x24, then calls the virtual at vtable offset 0x48 with argument 2.
// @fnv 0x00544390
void FUN_00544390_shell::SetFlag40(bool abVal)
{
    if (abVal)
        *((unsigned char*)this + 0x24) |= 0x40;
    else
        *((unsigned char*)this + 0x24) &= ~0x40;
    (*(void(__thiscall**)(TESObjectCELL*, int))(*(unsigned int*)this + 0x48))(this, 2);
}

struct FUN_005445d0_shell : public TESObjectCELL
{
    void* FUN_005445d0();
};

// @fnv 0x005445d0
void* FUN_005445d0_shell::FUN_005445d0()
{
    if (IsCellInterior())
        return 0;
    return cellData;
}

struct FUN_00544600_shell : public TESObjectCELL
{
    void* FUN_00544600();
};

// @fnv 0x00544600
void* FUN_00544600_shell::FUN_00544600()
{
    if (!IsCellInterior())
        return 0;
    return cellData;
}

struct FUN_00544630_shell : public TESObjectCELL
{
    void ResetCellData();
};

void* __cdecl operator new(unsigned int);

struct InteriorData
{
    char pad[0x2c];
    InteriorData();
};

struct PathingActorData
{
    char pad[0xc];
    PathingActorData();
};

// @fnv 0x00544630
void FUN_00544630_shell::ResetCellData()
{
    if (cellData)
    {
        if (IsCellInterior())
            delete (InteriorData*)cellData;
        else
            delete (PathingActorData*)cellData;
        cellData = 0;
    }

    if (IsCellInterior())
        cellData = new InteriorData();
    else
        cellData = new PathingActorData();
}

// @fnv 0x00544750
NiNode* __fastcall GetCellNode(TESObjectCELL* pThis)
{
    InteriorCellData* pData = pThis->GetInteriorData();
    if (pData)
    {
        if (pThis->FUN_00558b80(1) && pThis->GetLightingTemplate())
        {
            return ((NiAVObject*)pThis->GetLightingTemplate())->GetParent();
        }
        else
        {
            return *(NiNode**)pData;
        }
    }
    return 0;
}

class BGSTerrainManager
{
  public:
    unsigned int GetMinLevel();
};

// Returns the interior cell's minimum level from the terrain manager if available, otherwise from the interior data, or 0 if there is no interior data.
// @fnv 0x00544830
unsigned int __fastcall GetCellMinLevel(TESObjectCELL* apCell)
{
    InteriorCellData* interiorData = apCell->GetInteriorData();
    if (interiorData)
    {
        if (apCell->FUN_00558b80(2) && apCell->GetLightingTemplate())
        {
            return ((BGSTerrainManager*)apCell->GetLightingTemplate())->GetMinLevel();
        }
        else
        {
            return *(unsigned int*)((char*)interiorData + 4);
        }
    }
    return 0;
}

struct NiStream;
struct NiColor
{
    void Clamp();
    void Scale();
    static void LoadBinary(NiStream*, NiColor*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, NiColor*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    float Luminance();
    void __dflt_ctor_closure();
    float r;
    float g;
    float b;
};
typedef char _sizecheck_NiColor[sizeof(NiColor) == 12 ? 1 : -1];
struct FUN_00544890_shell : public TESObjectCELL
{
    void FUN_00544890(NiColor*);
};

unsigned int __fastcall GetCellMinLevel(TESObjectCELL* thisPtr);

// Reads a packed color from the cell via GetCellMinLevel and writes its red, green and blue bytes into acolColor as normalized floats.
// @fnv 0x00544890
void FUN_00544890_shell::FUN_00544890(NiColor* acolColor)
{
    unsigned int iColor = GetCellMinLevel(this);
    acolColor->r = (unsigned char)(iColor & 0xFF) / 255.0;
    acolColor->g = (unsigned char)(((unsigned short)iColor >> 8) & 0xFF) / 255.0;
    acolColor->b = (unsigned char)((iColor >> 16) & 0xFF) / 255.0;
}

namespace fnv_00544910 {
struct InteriorData
{
    void Endian();
    unsigned int m_uiAmbientColor;
    unsigned int m_uiDirectionalColor;
    unsigned int m_uiFogColor;
    float m_fFogNear;
    float m_fFogFar;
    unsigned int m_uiDirectionalRotationXY;
    unsigned int m_uiDirectionalRotationZ;
    float m_fDirectionalFade;
    float m_fFogClipDistance;
    float m_fFogPower;
    unsigned int m_uiTrailingValue;
};
typedef char _sizecheck_INTERIOR_DATA[sizeof(InteriorData) == 44 ? 1 : -1];
struct FUN_00544910_shell : public TESObjectCELL
{
    unsigned int FUN_00544910();
};

class BGSMessageInitAccess
{
  public:
    unsigned int GetIconFormID();
};

// @fnv 0x00544910
unsigned int FUN_00544910_shell::FUN_00544910()
{
    InteriorData* pdata = (InteriorData*)GetInteriorData();
    if (pdata)
    {
        if (FUN_00558b80(0x20) && GetLightingTemplate())
        {
            return ((BGSMessageInitAccess*)GetLightingTemplate())->GetIconFormID();
        }
        else
        {
            return pdata->m_uiDirectionalRotationXY;
        }
    }
    return 0;
}
}  // namespace fnv_00544910

namespace fnv_00544970 {
struct InteriorData
{
    void Endian();
    unsigned int m_uiAmbientColor;
    unsigned int m_uiDirectionalColor;
    unsigned int m_uiFogColor;
    float m_fFogNear;
    float m_fFogFar;
    unsigned int m_uiDirectionalRotationXY;
    unsigned int m_uiDirectionalRotationZ;
    float m_fDirectionalFade;
    float m_fFogClipDistance;
    float m_fFogPower;
    unsigned int m_uiTrailingValue;
};
typedef char _sizecheck_INTERIOR_DATA[sizeof(InteriorData) == 44 ? 1 : -1];
struct FUN_00544970_shell : public TESObjectCELL
{
    unsigned int FUN_00544970();
};

class Script
{
  public:
    char* GetData();
};

// @fnv 0x00544970
unsigned int FUN_00544970_shell::FUN_00544970()
{
    InteriorData* pdata = (InteriorData*)GetInteriorData();
    if (pdata)
    {
        if (FUN_00558b80(0x20) && GetLightingTemplate())
        {
            return (unsigned int)((Script*)GetLightingTemplate())->GetData();
        }
        return pdata->m_uiDirectionalRotationZ;
    }
    return 0;
}
}  // namespace fnv_00544970

int __fastcall _FNV_GetObjectReference(CellLightingTemplate* self);

// @fnv 0x005449d0
int __fastcall FUN_005449d0(TESObjectCELL* self)
{
    InteriorCellData* data = self->GetInteriorData();
    if (data)
    {
        if (self->FUN_00558b80(4) && self->GetLightingTemplate())
        {
            return _FNV_GetObjectReference(self->GetLightingTemplate());
        }
        return *(int*)((char*)data + 8);
    }
    return 0;
}

namespace fnv_00544a30 {
struct NiStream;
struct NiColor
{
    void Clamp();
    void Scale();
    static void LoadBinary(NiStream*, NiColor*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, NiColor*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    float Luminance();
    void __dflt_ctor_closure();
    float r;
    float g;
    float b;
};
typedef char _sizecheck_NiColor[sizeof(NiColor) == 12 ? 1 : -1];
struct FUN_00544a30_shell : public TESObjectCELL
{
    void FUN_00544a30(NiColor*);
};

unsigned int __fastcall FUN_005449d0(void* pThis);

// Reads a packed color from the cell via FUN_005449d0 and writes its red, green and blue bytes into acolColor as floats scaled by 1/255.
// @fnv 0x00544a30
void FUN_00544a30_shell::FUN_00544a30(NiColor* acolColor)
{
    unsigned int iColor = FUN_005449d0(this);
    acolColor->r = (unsigned char)(iColor & 0xFF) / 255.0;
    acolColor->g = (unsigned char)(((unsigned short)iColor >> 8) & 0xFF) / 255.0;
    acolColor->b = (unsigned char)((iColor >> 16) & 0xFF) / 255.0;
}
}  // namespace fnv_00544a30

class TESGlobalValueReader
{
  public:
    float GetValue();
};

// @fnv 0x00544ab0
float __fastcall FUN_00544ab0(TESObjectCELL* apCell)
{
    InteriorCellData* data = apCell->GetInteriorData();
    if (data)
    {
        if (apCell->FUN_00558b80(8) && apCell->GetLightingTemplate())
        {
            return ((TESGlobalValueReader*)apCell->GetLightingTemplate())->GetValue();
        }
        return *(float*)((char*)data + 0xc);
    }
    return 0.0f;
}

float __fastcall FUN_00526ae0(CellLightingTemplate* pthis);

// @fnv 0x00544b10
float __fastcall FUN_00544b10(TESObjectCELL* pthis)
{
    InteriorCellData* data = pthis->GetInteriorData();
    if (data)
    {
        if (pthis->FUN_00558b80(0x10) && pthis->GetLightingTemplate())
        {
            return FUN_00526ae0(pthis->GetLightingTemplate());
        }
        return *(float*)((char*)data + 0x10);
    }
    return 0.0f;
}

struct TESObjectREFR_GetScale : TESObjectREFR
{
    float GetScale();
};

// @fnv 0x00544b70
float __fastcall FUN_00544b70(TESObjectCELL* cell)
{
    InteriorCellData* interior = cell->GetInteriorData();
    if (interior)
    {
        if (cell->FUN_00558b80(0x100) && cell->GetLightingTemplate())
            return reinterpret_cast<TESObjectREFR_GetScale*>(cell->GetLightingTemplate())->GetScale();
        return *reinterpret_cast<float*>(reinterpret_cast<char*>(interior) + 0x24);
    }
    return 1.0f;
}

struct FUN_005452c0_shell : public TESObjectCELL
{
    void RegisterReferenceInCell(TESObjectREFR*);
};

class TESBoundObject
{
  public:
    virtual ~TESBoundObject();  // polymorphic: its RTTI is used (rtti_fix.py)
  public:
    float GetBoundSize(void);
};

template <class K, class V> class NiTPointerMap
{
  public:
    void SetAt(K, V);
};

template <> class BSSimpleList<char const*>
{
  public:
    void AddHead(char const*&);
};

extern double DAT_0102ed48;
TESBoundObject* __fastcall _FNV_GetObjectReference(TESObjectREFR*);

struct VClass0c
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual unsigned int vfn_0c();
};

struct VClass1d0
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
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
    virtual VClass0c* vfn_1d0();
};

// @fnv 0x005452c0
void FUN_005452c0_shell::RegisterReferenceInCell(TESObjectREFR* apRef)
{
    if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0xc4) == 0 || !apRef ||
        !reinterpret_cast<VClass1d0*>(apRef)->vfn_1d0())
        return;

    reinterpret_cast<NiTPointerMap<unsigned int, unsigned int>*>(
        *reinterpret_cast<char**>(reinterpret_cast<char*>(this) + 0xc4) + 0xc)
        ->SetAt(reinterpret_cast<unsigned int>(apRef), reinterpret_cast<VClass1d0*>(apRef)->vfn_1d0()->vfn_0c());

    if (_FNV_GetObjectReference(apRef)->GetBoundSize() > DAT_0102ed48)
    {
        reinterpret_cast<BSSimpleList<char const*>*>(*reinterpret_cast<char**>(reinterpret_cast<char*>(this) + 0xc4) +
                                                     4)
            ->AddHead(*(char const**)&apRef);
    }
}

// Returns a pointer to the object at offset 0x5c of the field at param_1+0xc4, or null if that field is zero.
// @fnv 0x00545710
void* __fastcall FUN_00545710(int param_1)
{
    if (*(int*)(param_1 + 0xc4) != 0)
        return (void*)(*(int*)(param_1 + 0xc4) + 0x5c);
    return 0;
}

struct FUN_00545cb0_shell : public TESObjectCELL
{
    NiNode* FUN_00545cb0();
};

template <class T> class BSStringT
{
  public:
    operator const char*() const;
};

// @fnv 0x00545cb0
NiNode* FUN_00545cb0_shell::FUN_00545cb0()
{
    NiNode* pNode = 0;
    if (*reinterpret_cast<BSStringT<char>**>(reinterpret_cast<char*>(this) + 0xc4) != 0)
    {
        pNode = reinterpret_cast<NiNode*>(const_cast<char*>(
            static_cast<const char*>(**reinterpret_cast<BSStringT<char>**>(reinterpret_cast<char*>(this) + 0xc4))));
    }
    return pNode;
}

struct FUN_00546780_shell : public NiAVObject
{
    void FUN_00546780(bool);
};

class TaskQueueInterface
{
  public:
    void SetTaskFlagDWord(bool, unsigned int);
};

class ImageSpaceModifierInstanceDOF
{
  public:
    void FUN_0063f790(float);
};

struct NiAVObject_CreateBoundIfNone_Accessor : public NiAVObject
{
    void EnsureWorldBound();
};

// @fnv 0x00546780
void FUN_00546780_shell::FUN_00546780(bool abVal)
{
    reinterpret_cast<TaskQueueInterface*>(this)->SetTaskFlagDWord(abVal, 0x800);
    reinterpret_cast<NiAVObject_CreateBoundIfNone_Accessor*>(this)->EnsureWorldBound();
    if (abVal)
    {
        (*reinterpret_cast<ImageSpaceModifierInstanceDOF**>(reinterpret_cast<char*>(this) + 0x20))->FUN_0063f790(1.0f);
    }
}

struct NiBoundH
{
    void NiBound();
};
struct S
{
    S* InitBound(unsigned short a, unsigned short b);
};
// @fnv 0x00546890
S* S::InitBound(unsigned short a, unsigned short b)
{
    ((NiBoundH*)this)->NiBound();
    return this;
}

namespace fnv_005468f0 {
extern unsigned int DAT_011ca08c;

// @fnv 0x005468f0
bool __cdecl FUN_005468f0(int aiNode)
{
    return (DAT_011ca08c & (1 << aiNode)) ? true : false;
}
}  // namespace fnv_005468f0

namespace fnv_00546910 {
struct NiNodeX;
struct NiPointerX
{
    NiPointerX& operator=(NiNodeX*);
};
struct S
{
    char pad[0x4c];
    NiPointerX p;
    void FUN_00546910(NiNodeX* n);
};
// @fnv 0x00546910
void S::FUN_00546910(NiNodeX* apNode)
{
    p = apNode;
}
}  // namespace fnv_00546910

namespace fnv_00546930 {
template <typename T> struct BSStringT
{
    operator const char*() const;
};

struct FUN_00546930_Class
{
    char pad[0x4c];
    BSStringT<char> str;
};

// @fnv 0x00546930
const char* __fastcall FUN_00546930(FUN_00546930_Class* pThis)
{
    return pThis->str;
}
}  // namespace fnv_00546930

struct TESGlobal;
struct FUN_00546aa0_shell : public TESObjectCELL
{
    TESGlobal* FUN_00546aa0();
};

TESGlobal* __fastcall FUN_00418690(void* pThis);

// @fnv 0x00546aa0
TESGlobal* FUN_00546aa0_shell::FUN_00546aa0()
{
    return FUN_00418690(((TESDataHandler*)this)->GetTESImageSpaceModifierList());
}

struct FUN_00546af0_shell : public TESObjectCELL
{
    unsigned int FUN_00546af0();
};

unsigned int __fastcall FUN_00421820(void*);

// @fnv 0x00546af0
unsigned int FUN_00546af0_shell::FUN_00546af0()
{
    return FUN_00421820(reinterpret_cast<TESDataHandler*>(this)->GetTESImageSpaceModifierList());
}

struct BGSAcousticSpace;
struct FUN_00547590_shell : public TESObjectCELL
{
    BGSAcousticSpace* FUN_00547590();
};

BGSAcousticSpace* __fastcall FUN_0041c160(void* pThis);

// @fnv 0x00547590
BGSAcousticSpace* FUN_00547590_shell::FUN_00547590()
{
    return FUN_0041c160(((TESDataHandler*)this)->GetTESImageSpaceModifierList());
}

struct BGSImpactData;
struct TESForm;
struct ImpactSwap
{
    void Save();
    void Load(TESFile*);
    void InitItem(TESForm*);
    void Copy(ImpactSwap*);
    bool Compare(ImpactSwap*);
    BGSImpactData* GetSwappedImpactData(int, BGSImpactData*);
    void SetSwappedImpactData(int, BGSImpactData*, BGSImpactData*);
    void RemoveSwappedImpactData(int, BGSImpactData*);
    char* GetAltFootstepMaterialName(int);
    void* __vecDelDtor(unsigned int);
    char m_pData[48];
    char m_acAltFootstepMaterialNames[300];
};
typedef char _sizecheck_ImpactSwap[sizeof(ImpactSwap) == 348 ? 1 : -1];
struct FUN_00547610_shell : public TESObjectCELL
{
    ImpactSwap* GetImpactSwap();
};

ImpactSwap* __fastcall FUN_0041c460(void* pThis);

// @fnv 0x00547610
ImpactSwap* FUN_00547610_shell::GetImpactSwap()
{
    ImpactSwap* pswap = 0;
    if (IsCellInterior())
    {
        pswap = FUN_0041c460(((TESDataHandler*)this)->GetTESImageSpaceModifierList());
    }
    return pswap;
}

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
struct FUN_00547770_shell : public TESObjectCELL
{
    TESWaterForm* FUN_00547770();
};

class TESSound;
class EffectSetting
{
  public:
    TESSound* GetCastSound();
};

extern TESWaterForm* DAT_011ca53c;
TESWaterForm* __fastcall FUN_0041e130(void*);
TESWaterForm* __fastcall FUN_00586070(TESWorldSpace*);
bool __fastcall _ref_004013e0(void*);

// Returns a TESWaterForm from the data handler, else from the world space, else the global default, and substitutes the cast sound if the cell check passes.
// @fnv 0x00547770
TESWaterForm* FUN_00547770_shell::FUN_00547770()
{
    TESWaterForm* pretwater = FUN_0041e130(reinterpret_cast<TESDataHandler*>(this)->GetTESImageSpaceModifierList());
    if (!pretwater)
    {
        TESWorldSpace* pworld = GetParentWorldSpace();
        if (pworld)
            pretwater = FUN_00586070(pworld);
    }
    if (!pretwater)
        pretwater = DAT_011ca53c;
    if (pretwater)
    {
        if (_ref_004013e0(this))
        {
            if (reinterpret_cast<EffectSetting*>(pretwater)->GetCastSound())
                pretwater =
                    reinterpret_cast<TESWaterForm*>(reinterpret_cast<EffectSetting*>(pretwater)->GetCastSound());
        }
    }
    return pretwater;
}

int __fastcall GetByteAtOffset38(void* pThis);

// @fnv 0x00548720
bool __fastcall FUN_00548720(void* pThis)
{
    return GetByteAtOffset38(pThis) == 2;
}

namespace fnv_005495d0 {
struct FUN_005495d0_shell : public TESObjectCELL
{
    NiNode* FUN_005495d0();
};

template <typename T> class BSStringT
{
  public:
    operator const T*() const;
};

// @fnv 0x005495d0
NiNode* FUN_005495d0_shell::FUN_005495d0()
{
    return (NiNode*)(const char*)(*(BSStringT<char>*)((char*)this + 0xb4));
}
}  // namespace fnv_005495d0

bool __fastcall IsFlag8Set(void* pThis);
bool __fastcall FUN_0050d1f0(void* pThis);
bool __fastcall IsFlag80Set(void* pThis);
bool __fastcall FUN_0050d230(void* pThis);

// Returns true only when all four checks on pThis return false.
// @fnv 0x00549630
bool __fastcall FUN_00549630(void* pThis)
{
    return !IsFlag8Set(pThis) && !FUN_0050d1f0(pThis) && !IsFlag80Set(pThis) && !FUN_0050d230(pThis);
}

class BSXFlags
{
  public:
    unsigned int GetFlags(unsigned int) const;
};

// @fnv 0x00549690
bool __fastcall HasFlagOne(const BSXFlags* pThis)
{
    return pThis->GetFlags(1) != 0;
}

struct FUN_0054a050_shell : public TESObjectCELL
{
    NiNode* FUN_0054a050();
};

// @fnv 0x0054a050
NiNode* FUN_0054a050_shell::FUN_0054a050()
{
    return (NiNode*)GetCellChildAt(0);
}

// @fnv 0x0054aa60
NiAVObject* __fastcall FUN_0054aa60(TESObjectCELL* apCell)
{
    return apCell->GetCellChildAt(3);
}

__declspec(dllimport) void* __stdcall CreateSemaphoreA(void* lpSemaphoreAttributes, long lInitialCount,
                                                       long lMaximumCount, const char* lpName);

struct FUN_0054ad60_Arg
{
    int val;
};

struct FUN_0054ad60_This
{
    int count;
    void* hSemaphore;
    int maxCount;
};

// Stores the initial count and max count (count + 1) and creates a semaphore handle from them.
// @fnv 0x0054ad60
FUN_0054ad60_This* __fastcall FUN_0054ad60(FUN_0054ad60_This* pThis, FUN_0054ad60_Arg aInitialCount)
{
    pThis->count = aInitialCount.val;
    pThis->maxCount = aInitialCount.val + 1;
    pThis->hSemaphore = CreateSemaphoreA(0, pThis->count, pThis->maxCount, 0);
    return pThis;
}

struct TESObjectSTAT;
extern TESObjectSTAT* DAT_011ca228;
struct RefStub
{
    TESObjectSTAT* _FNV_GetObjectReference();
    void* FUN_00569080();
};
struct NodeStub
{
    RefStub** _ref_006815c0();
    NodeStub* _ref_00726070();
};
struct ListStub
{
    void AddHead(RefStub**);
};
struct FUN_0054b8c0_shell : public TESObjectCELL
{
    void AddStaticRefsToList(BSSimpleList<const char*>* list);
};
// Locks the cell, walks its node list, and adds refs whose object reference is DAT_011ca228 to the given list.
// @fnv 0x0054b8c0
void FUN_0054b8c0_shell::AddStaticRefsToList(BSSimpleList<const char*>* list)
{
    if (list)
    {
        this->CellRefLockEnter();
        NodeStub* node = (NodeStub*)this->FUN_009604f0();
        while (node)
        {
            RefStub* ref = *node->_ref_006815c0();
            if (ref)
            {
                if (ref->_FNV_GetObjectReference() == DAT_011ca228)
                {
                    void* tmp = ref->FUN_00569080();
                    if (tmp)
                        ((ListStub*)list)->AddHead(&ref);
                }
            }
            node = node->_ref_00726070();
        }
        this->CellRefLockLeave();
    }
}

struct FUN_0054b950_shell : public TESObjectCELL
{
    void FUN_0054b950(bool);
};

class BGSSaveLoadGame
{
  public:
    bool FUN_0042ce10();
};

struct RefObj
{
    bool FUN_0057a2f0();
    bool FUN_0057a370();
    void FUN_00579ac0(bool);
};

extern TESDataHandler* g_dataHandler;
extern BGSSaveLoadGame* g_BGSSaveLoadGame;

bool __fastcall FUN_004226e0(TESDataHandler*);
RefObj** __fastcall _ref_006815c0(void*);
BSSimpleList<BGSPerkEntry*>* __fastcall _ref_00726070(void*);

// @fnv 0x0054b950
void FUN_0054b950_shell::FUN_0054b950(bool abAttach)
{
    if (!FUN_004226e0(g_dataHandler) && !g_BGSSaveLoadGame->FUN_0042ce10())
    {
        CellRefLockEnter();
        BSSimpleList<BGSPerkEntry*>* pCurrentElementNext = FUN_009604f0();
        while (pCurrentElementNext)
        {
            RefObj* pcurrentObj = *_ref_006815c0(pCurrentElementNext);
            pCurrentElementNext = _ref_00726070(pCurrentElementNext);
            if (pcurrentObj && pcurrentObj->FUN_0057a2f0() && (!abAttach || pcurrentObj->FUN_0057a370()))
            {
                pcurrentObj->FUN_00579ac0(abAttach);
            }
        }
        CellRefLockLeave();
    }
}

struct FUN_0054de10_shell : public TESObjectCELL
{
    void FUN_0054de10(TESWorldSpace*);
};

// @fnv 0x0054de10
void FUN_0054de10_shell::FUN_0054de10(TESWorldSpace* apWorld)
{
    if (!IsCellInterior())
        worldSpace = apWorld;
}

// @fnv 0x0054de40
void* __fastcall FUN_0054de40(TESObjectCELL* apCell)
{
    void* result = 0;
    if (apCell->IsCellInterior())
    {
        result = apCell->worldSpace;
    }
    return result;
}

namespace fnv_0054deb0 {
struct InteriorData
{
    void Endian();
    unsigned int m_uiAmbientColor;
    unsigned int m_uiDirectionalColor;
    unsigned int m_uiFogColor;
    float m_fFogNear;
    float m_fFogFar;
    unsigned int m_uiDirectionalRotationXY;
    unsigned int m_uiDirectionalRotationZ;
    float m_fDirectionalFade;
    float m_fFogClipDistance;
    float m_fFogPower;
    unsigned int m_uiTrailingValue;
};
typedef char _sizecheck_INTERIOR_DATA[sizeof(InteriorData) == 44 ? 1 : -1];
struct FUN_0054deb0_shell : public TESObjectCELL
{
    unsigned int FUN_0054deb0();
};

// @fnv 0x0054deb0
unsigned int FUN_0054deb0_shell::FUN_0054deb0()
{
    unsigned int iretval = 0;
    if (IsCellInterior())
    {
        InteriorData* pdata = reinterpret_cast<InteriorData*>(GetInteriorData());
        if (pdata)
        {
            iretval = pdata->m_uiTrailingValue;
        }
    }
    return iretval;
}
}  // namespace fnv_0054deb0

namespace fnv_0054def0 {
struct ICD
{
    char pad[0x28];
    int v;
};
struct S
{
    bool IsCellInterior() const;
    ICD* GetInteriorData();
    void SetInteriorDataValue(int a);
};
// @fnv 0x0054def0
void S::SetInteriorDataValue(int aiValue)
{
    if (IsCellInterior())
    {
        ICD* d = GetInteriorData();
        if (d)
            d->v = aiValue;
    }
}
}  // namespace fnv_0054def0

struct FUN_00550890_shell : public TESDataHandler
{
    void SetBoolAt61a(bool);
};

// @fnv 0x00550890
void FUN_00550890_shell::SetBoolAt61a(bool abNewbool)
{
    *((bool*)((char*)this + 0x61a)) = abNewbool;
}

struct FUN_00551420_shell : public TESObjectCELL
{
    bool FUN_00551420();
};

// @fnv 0x00551420
bool FUN_00551420_shell::FUN_00551420()
{
    if (*((unsigned char*)this + 0x24) & 0x10)
        return true;
    else
        return false;
}

namespace fnv_00552470 {
struct S
{
    void FUN_00456630(int);
    void FUN_00552470();
};
// @fnv 0x00552470
void S::FUN_00552470()
{
    FUN_00456630(0x100000);
}
}  // namespace fnv_00552470

// @fnv 0x00552490
bool __fastcall FUN_00552490(bool* pThis)
{
    return pThis[0x41];
}

struct FUN_00552900_shell : public TESObjectCELL
{
    void FUN_00552900(bool);
};

class TESForm
{
  public:
    virtual ~TESForm();  // polymorphic: its RTTI is used (rtti_fix.py)
  public:
    bool IsTemporary() const;
    void SetAltered(bool);
};

class Pathing
{
  public:
    bool FUN_00460340();
};

namespace {
struct VCallC8
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
    virtual void v50(bool);
};
}

// @fnv 0x00552900
void FUN_00552900_shell::FUN_00552900(bool abAltered)
{
    reinterpret_cast<TESForm*>(this)->SetAltered(abAltered);
    if (!reinterpret_cast<TESForm*>(this)->IsTemporary() && reinterpret_cast<Pathing*>(this)->FUN_00460340() &&
        !IsCellInterior())
    {
        TESWorldSpace* pWorld = GetParentWorldSpace();
        if (pWorld)
        {
            reinterpret_cast<VCallC8*>(pWorld)->v50(true);
        }
    }
}

struct TESBoundObject;
struct ScriptLocals
{
    TESBoundObject* GetLocalData();
};
struct Script
{
    void GetLocalData();
};
struct FUN_00c93820_stub
{
    void FUN_00c93820(unsigned int);
};
struct FUN_006299c0_stub
{
    void FUN_006299c0(unsigned int*);
};
struct FUN_005533f0_cls
{
    char pad[0x70];
    FUN_006299c0_stub sub;
    void FUN_005533f0(unsigned int a);
};
// @fnv 0x005533f0
void FUN_005533f0_cls::FUN_005533f0(unsigned int uiValue)
{
    TESBoundObject* p = ((ScriptLocals*)this)->GetLocalData();
    if (p)
    {
        ((Script*)this)->GetLocalData();
        ((FUN_00c93820_stub*)p)->FUN_00c93820(uiValue);
        ((Script*)this)->GetLocalData();
    }
    sub.FUN_006299c0(&uiValue);
}

namespace fnv_00553440 {
struct TESBoundObjectX;
struct ScriptLocalsX
{
    TESBoundObjectX* GetLocalData();
};
struct ScriptX
{
    void GetLocalData();
};
struct ObjX
{
    void FUN_00c93a20(int);
};
struct S
{
    void FUN_00553440(int a);
};
// @fnv 0x00553440
void S::FUN_00553440(int aiArg)
{
    TESBoundObjectX* o = ((ScriptLocalsX*)this)->GetLocalData();
    if (o)
    {
        ((ScriptX*)this)->GetLocalData();
        ((ObjX*)o)->FUN_00c93a20(aiArg);
        ((ScriptX*)this)->GetLocalData();
    }
}
}  // namespace fnv_00553440

namespace fnv_00553480 {
struct TESBoundObject;
struct ScriptLocals
{
    TESBoundObject* GetLocalData();
};
struct Script
{
    void GetLocalData();
};
struct FUN_005533f0_stub
{
    void FUN_005533f0(char*);
};
struct FUN_00c93860_stub
{
    void FUN_00c93860(char*);
};
struct FUN_00553480_cls
{
    char pad[0x20];
    char* field20;
    void FUN_00553480(char* a);
};
// @fnv 0x00553480
void FUN_00553480_cls::FUN_00553480(char* a)
{
    ((FUN_005533f0_stub*)this)->FUN_005533f0(a);
    TESBoundObject* p = ((ScriptLocals*)this)->GetLocalData();
    if (p)
    {
        ((Script*)this)->GetLocalData();
        ((FUN_00c93860_stub*)p)->FUN_00c93860(a ? a + 0x14 : 0);
        ((Script*)this)->GetLocalData();
    }
    field20 = a;
}
}  // namespace fnv_00553480

struct _Helper_005534f0
{
    char _pad[0x28];
    void* m_kListener;
    void FUN_005533f0(void* apListener);
    void FUN_005534f0(void* apListener);
};

// @fnv 0x005534f0
void _Helper_005534f0::FUN_005534f0(void* apListener)
{
    FUN_005533f0(apListener);
    m_kListener = apListener;
}

void __fastcall FUN_00553540(void* pThis);

// @fnv 0x00553520
void __fastcall FUN_00553520(void* pThis)
{
    FUN_00553540(pThis);
}

struct M1
{
    int x;
    ~M1();
};
struct B1
{
    virtual ~B1();
    char pad[0x54];
};
struct FUN_00553540 : B1
{
    M1 m58;
    M1 m5c;
    char pad2[0xc];
    M1 m6c;
    ~FUN_00553540();
};
// Destructor for FUN_00553540; destroys the M1 members m58, m5c and m6c.
// @fnv 0x00553540
FUN_00553540::~FUN_00553540()
{}

struct NiStream;
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct AutoMemContext
{
    void Enter(int, bool, char*, int);
    void Leave();
    void* __vecDelDtor(unsigned int);
    int m_eMemoryContext;
    unsigned int m_pFileName;
    int m_iLineNumber;
};
typedef char _sizecheck_AutoMemContext[sizeof(AutoMemContext) == 12 ? 1 : -1];
struct NiTransform
{
    void ResetToIdentity();
    void Invert(NiTransform*);
    void CalculateInverse(NiTransform*);
    bool IsIdentity();
    void LoadBinary(NiStream*);
    void SaveBinary(NiStream*);
    char m_kOrientation[48];
    char m_kTranslation[12];
    float m_fScale;
};
typedef char _sizecheck_NiTransform[sizeof(NiTransform) == 64 ? 1 : -1];
struct FUN_005535f0_shell : public TESObjectCELL
{
    void FUN_005535f0();
};

namespace Local {
enum MEM_CONTEXT
{
};

struct AutoMemContext
{
    AutoMemContext(MEM_CONTEXT, bool, const char*, int);
    ~AutoMemContext();
    int m_eMemoryContext;
};

struct ThreeByThreeMatrix
{
    float d[9];
};

struct NiPoint3
{
    float x;
    float y;
    float z;
};

struct NiTransform
{
    NiTransform();
    ThreeByThreeMatrix m_kOrientation;
    NiPoint3 m_kTranslation;
    float m_fScale;
};
}

class bhkWorld;
struct NiQuaternion
{
    static const NiQuaternion IDENTITY;
};

struct CellMopp
{
    void PlaceGridObjects(bhkWorld*, const Local::NiPoint3&, const NiQuaternion&);
};

extern Local::ThreeByThreeMatrix DAT_011a9448;
extern double DAT_01016968;

bhkWorld* __fastcall FUN_004543c0(TESObjectCELL*);
CellMopp* __fastcall GetCellMopp(TESObjectCELL*);

// @fnv 0x005535f0
void FUN_005535f0_shell::FUN_005535f0()
{
    bhkWorld* pw = FUN_004543c0(this);
    int ix = GetCellGridX();
    int iy = GetCellGridY();
    CellMopp* pcm = GetCellMopp(this);
    if (pw && pcm)
    {
        Local::AutoMemContext tempMemContext(
            (Local::MEM_CONTEXT)16, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESObjectCELL.cpp",
            15014);
        Local::NiTransform org;
        org.m_fScale = 1.0f;
        org.m_kOrientation = DAT_011a9448;
        org.m_kTranslation.x = (float)((ix << 12) + DAT_01016968);
        org.m_kTranslation.y = (float)((iy << 12) + DAT_01016968);
        org.m_kTranslation.z = 0.0f;
        pcm->PlaceGridObjects(pw, org.m_kTranslation, NiQuaternion::IDENTITY);
    }
}

namespace fnv_00553820 {
bool __fastcall FUN_00450ff0(TESObjectCELL*);
void* __fastcall _FNV_GetObjectReference(void*);
int __fastcall _FNV_GetFormType(void*);

class NavMeshVertexMap
{
  public:
    void* GetFirstPos();
};

template <class K, class V> class NiTPointerMap
{
  public:
    void GetNext(void*&, K&, V&);
};

struct FUN_00553820_Obj
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
    virtual bool v100();
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
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
};

// @fnv 0x00553820
void __fastcall FUN_00553820(TESObjectCELL* pThis)
{
    if (FUN_00450ff0(pThis) && *(int*)((char*)pThis + 0xc4) != 0)
    {
        void* pos = ((NavMeshVertexMap*)(*(char**)((char*)pThis + 0xc4) + 0xc))->GetFirstPos();
        while (pos)
        {
            FUN_00553820_Obj* key = 0;
            void* val = 0;
            ((NiTPointerMap<unsigned int, void*>*)(*(char**)((char*)pThis + 0xc4) + 0xc))
                ->GetNext(pos, (unsigned int&)key, val);
            if (!key->v100() && _FNV_GetObjectReference(key) && _FNV_GetFormType(_FNV_GetObjectReference(key)) != 0x25)
            {
                key->v1e0();
            }
        }
    }
}
}  // namespace fnv_00553820

// Returns pThis[0x68] when bit 2 of the field at offset 0x48 is set, otherwise returns 0.
// @fnv 0x00553b60
char __fastcall FUN_00553b60(char* pThis)
{
    return (*(unsigned int*)(pThis + 0x48) & 2) ? pThis[0x68] : 0;
}

struct SoundDataDummy
{
    int f0;
    unsigned int f4;
    char pad[0x24 - 8];
};

struct TESSound_caller
{
    SoundDataDummy CopyBig();
};

struct FUN_00553bb0_caller
{
    char pad[0x1c];
    TESSound_caller* sound;
    bool FUN_00553bb0();
};

// Returns true when sound is non-null and the flag bit 2 is set in the value returned by sound->CopyBig().
// @fnv 0x00553bb0
bool FUN_00553bb0_caller::FUN_00553bb0()
{
    return (sound && (sound->CopyBig().f4 & 2)) ? true : false;
}

struct Actor;
struct SaveLoadFile;
struct ThreeByThreeMatrix;
struct NiPoint3;
struct NiQuaternion;
struct TESForm;
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
struct FUN_00555a50_shell : public TESObjectCELL
{
    void FUN_00555a50(BGSLoadFormBuffer*);
};

struct MagicProjectile
{
    void Process(BGSLoadFormBuffer*);
};
struct BGSChangeFlags_s
{
    char b[4];
    bool Test(unsigned int);
};
struct FUN_00555be0_stub
{
    void FUN_00555be0();
};
struct TESObjectCELL_s
{
    void SetDetachTime(unsigned int, bool);
};
// @fnv 0x00555a50
void FUN_00555a50_shell::FUN_00555a50(BGSLoadFormBuffer* apLoadGameBuffer)
{
    ((MagicProjectile*)this)->Process(apLoadGameBuffer);
    *((unsigned char*)this + 0x25) = 0;
    if (((BGSChangeFlags_s*)&apLoadGameBuffer->GetOldChangeFlags())->Test(0x80000000))
        ((FUN_00555be0_stub*)this)->FUN_00555be0();
    if (((BGSChangeFlags_s*)&apLoadGameBuffer->GetOldChangeFlags())->Test(0x40000000))
        ((TESObjectCELL_s*)this)->SetDetachTime(0, false);
}

struct TESObjectREFR_GetFlags_Helper : public TESObjectREFR
{
    unsigned int GetFlags()
    {
        return 0;
    }
};

// @fnv 0x00558200
unsigned int __fastcall FUN_00558200(char* this_ptr)
{
    return ((TESObjectREFR_GetFlags_Helper*)(this_ptr + 0x38))->GetFlags();
}

struct NavMeshTriangle
{
    void Clear();
    bool HasEdgeExtraInfo();
    bool IsPreferred();
    void TogglePreferred();
    bool IsWaterTriangle();
    void ToggleWater();
    bool IsNoLargeCreature();
    void ToggleNoLargeCreature();
    void GetVerts(unsigned short*, unsigned short*, unsigned short*);
    void GetTris(unsigned short*, unsigned short*, unsigned short*);
    void SetVerts(unsigned short, unsigned short, unsigned short);
    void SetTris(unsigned short, unsigned short, unsigned short);
    bool GetFlag(int);
    void SetFlag(int);
    void ClearFlag(int);
    unsigned int GetTriangleFlags();
    void SetTriangleFlags(unsigned int);
    unsigned short GetVert(unsigned int);
    void SetVert(unsigned int, unsigned short);
    unsigned short GetTri(unsigned int);
    void SetTri(unsigned int, unsigned short);
    bool EdgeHasExtraInfo(int);
    unsigned short GetEdgeExtraInfoValue(int);
    void SetEdgeExtraInfo(int, unsigned short);
    void ClearEdgeExtraInfo(int);
    bool HasDoorPortal();
    bool IsEdgeConnected(int);
    unsigned short GetTriOrExtraInfo(int);
    void SetTriOrExtraInfo(int, unsigned short);
    unsigned short GetObjectCount();
    void SetObjectCount(unsigned short);
    void ClearObjectCount();
    static bool HasCover(unsigned int);
    bool HasCover();
    bool HasCoverEdge0();
    bool HasCoverEdge1();
    static bool HasCoverOrWallFlags(unsigned int);
    bool HasCoverOrWallFlags();
    bool HasCoverOrWallEdge0();
    bool HasCoverOrWallEdge1();
    bool IsWall(unsigned short);
    bool IsEdgeOpen(unsigned short);
    unsigned short GetEdgeCover(unsigned short);
    bool GetEdgeSides(unsigned short, bool*, bool*);
    static void GetEdgeCoverData(unsigned int, unsigned short, unsigned short*, bool*, bool*);
    void GetEdgeCoverData(unsigned short, unsigned short*, bool*, bool*);
    void ClearCover();
    static void SetEdgeCover(unsigned int*, unsigned short, unsigned short, bool, bool);
    void SetEdgeCover(unsigned short, unsigned short, bool, bool);
    int Rotate(int);
    bool ConvertCoverEdgeFormat();
    static unsigned int GetCoverLevel(float, bool, bool);
    static float GetCoverHeight(unsigned int);
    void Endian();
    char Vertices[6];
    char Triangles[6];
    unsigned int m_uiTriangleFlags;
};
typedef char _sizecheck_NavMeshTriangle[sizeof(NavMeshTriangle) == 16 ? 1 : -1];
struct FUN_005582d0_shell : public NavMeshTriangle
{
    unsigned short FUN_005582d0(unsigned int);
};

// @fnv 0x005582d0
unsigned short FUN_005582d0_shell::FUN_005582d0(unsigned int aiVertIndex)
{
    return ((unsigned short*)Vertices)[aiVertIndex];
}

struct NiNode_00558310 : NiNode
{
    NiAVObject* FUN_0045bc00(unsigned int);
};

// @fnv 0x00558310
NiAVObject* __fastcall FUN_00558310(NiNode_00558310* pThis)
{
    return pThis->FUN_0045bc00(0);
}

struct BGSLightingTemplate;
struct FUN_00558b40_shell : public TESObjectCELL
{
    BGSLightingTemplate* GetLightingTemplate();
};

// @fnv 0x00558b40
BGSLightingTemplate* FUN_00558b40_shell::GetLightingTemplate()
{
    return *(BGSLightingTemplate**)((char*)this + 0xd8);
}

namespace fnv_00558b60 {
struct BGSLightingTemplate;
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
struct FUN_00558b60_shell : public TESObjectCELL
{
    void FUN_00558b60(BGSLightingTemplate*);
};

// @fnv 0x00558b60
void FUN_00558b60_shell::FUN_00558b60(BGSLightingTemplate* apTemplate)
{
    *(BGSLightingTemplate**)((char*)this + 0xd8) = apTemplate;
}
}  // namespace fnv_00558b60

struct FUN_00558b80_shell : public TESObjectCELL
{
    bool FUN_00558b80(unsigned int);
};

// @fnv 0x00558b80
bool FUN_00558b80_shell::FUN_00558b80(unsigned int aiFlag)
{
    return (*(unsigned int*)((char*)this + 0xdc) & aiFlag) ? true : false;
}

namespace fnv_00558c90 {
struct FUN_00558c90_shell : public TESObjectCELL
{
    void FUN_00558c90();
};

void __cdecl FUN_00c6a270(NiAVObject*, bool, bool, int);
void** __fastcall _ref_006815c0(void* pThis);
void* __fastcall _ref_00726070(void* pThis);
void* __fastcall _FNV_GetObjectReference(void* pThis);
int __fastcall _FNV_GetFormType(void* pThis);

class TESForm
{
  public:
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
    virtual void vfn_0a();
    virtual void vfn_0b();
    virtual void vfn_0c();
    virtual void vfn_0d();
    virtual void vfn_0e();
    virtual void vfn_0f();
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
    virtual void vfn_1a();
    virtual void vfn_1b();
    virtual void vfn_1c();
    virtual void vfn_1d();
    virtual void vfn_1e();
    virtual void vfn_1f();
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
    virtual void vfn_2a();
    virtual void vfn_2b();
    virtual void vfn_2c();
    virtual void vfn_2d();
    virtual void vfn_2e();
    virtual void vfn_2f();
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
    virtual void vfn_3a();
    virtual void vfn_3b();
    virtual void vfn_3c();
    virtual void vfn_3d();
    virtual void vfn_3e();
    virtual void vfn_3f();
    virtual bool vfn_40();
    bool IsConstantGlobal();
};

// @fnv 0x00558c90
void FUN_00558c90_shell::FUN_00558c90()
{
    TESForm* pref = 0;
    void* preflist = this->FUN_009604f0();
    while (preflist && *_ref_006815c0(preflist))
    {
        pref = (TESForm*)*_ref_006815c0(preflist);
        if (!pref->vfn_40() && _FNV_GetFormType(_FNV_GetObjectReference(pref)) != 0x1c && pref->IsConstantGlobal())
        {
            if (this->FUN_00545cb0())
            {
                FUN_00c6a270((NiAVObject*)this->FUN_00545cb0(), true, true, 1);
            }
        }
        preflist = _ref_00726070(preflist);
    }
}
}  // namespace fnv_00558c90

namespace fnv_00559490 {
struct S
{
    char pad[0xe];
    unsigned short v;
    void FUN_00559490(unsigned short a);
};
// @fnv 0x00559490
void S::FUN_00559490(unsigned short ausValue)
{
    v = ausValue;
}
}  // namespace fnv_00559490

struct Node
{
    char pad[8];
    int v;
};
struct FUN_005597d0_shell
{
    Node* FUN_0049fa80();
    void FUN_00559a70(Node*);
    void FUN_005597d0(int* e);
};
// Gets a Node via FUN_0049fa80, stores the int pointed to by e into its v field, then passes the node to FUN_00559a70.
// @fnv 0x005597d0
void FUN_005597d0_shell::FUN_005597d0(int* piValue)
{
    Node* n = FUN_0049fa80();
    n->v = *piValue;
    FUN_00559a70(n);
}

struct FUN_0057c850_item
{
    FUN_0057c850_item* next;
    void* key;
    bool val;
};
struct FUN_0057c850_cls
{
    virtual void v0();
    virtual unsigned int v1(void* key);
    virtual bool v2(void* key, void* other);
    int pad;
    FUN_0057c850_item** table;
    bool FUN_0057c850(void* key, bool* val);
};
// @fnv 0x0057c850
bool FUN_0057c850_cls::FUN_0057c850(void* key, bool* pbVal)
{
    unsigned int uiIndex = v1(key);
    FUN_0057c850_item* pkItem = table[uiIndex];
    while (pkItem)
    {
        if (v2(key, pkItem->key))
        {
            *pbVal = pkItem->val;
            return true;
        }
        pkItem = pkItem->next;
    }
    return false;
}

class ActorCombatGroup;

template <class T> class NiTMallocInterface
{
  public:
    static T* __cdecl Allocate(unsigned short auiCount);
    static void __cdecl Deallocate(T* pArray);
};

struct NiTArray_CombatGroup
{
    void* vtbl;
    ActorCombatGroup** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

// @fnv 0x00600bc0
void __fastcall CompactArray(NiTArray_CombatGroup* pThis)
{
    if (pThis->m_usESize == pThis->m_usSize)
        return;

    if (pThis->m_usESize)
    {
        for (unsigned short i = 0, j = 0; i < pThis->m_usSize; i++)
        {
            if (pThis->m_pBase[i] != 0)
            {
                if (pThis->m_pBase[j] != pThis->m_pBase[i])
                    pThis->m_pBase[j] = pThis->m_pBase[i];
                j++;
            }
        }
    }

    ActorCombatGroup** pOldBase = pThis->m_pBase;
    pThis->m_usSize = pThis->m_usESize;
    pThis->m_usMaxSize = pThis->m_usSize;

    if (pThis->m_usMaxSize > 0)
    {
        pThis->m_pBase = NiTMallocInterface<ActorCombatGroup*>::Allocate(pThis->m_usMaxSize);
        for (unsigned short i = 0; i < pThis->m_usSize; i++)
        {
            pThis->m_pBase[i] = pOldBase[i];
        }
    }
    else
    {
        pThis->m_pBase = 0;
    }

    NiTMallocInterface<ActorCombatGroup*>::Deallocate(pOldBase);
}

class Modifier
{
  public:
    char GetKey(void);
};

Modifier* __cdecl FUN_004b7210(void);
void __fastcall FUN_007160b0(Modifier*);

// @fnv 0x00703980
void FUN_00703980()
{
    if (FUN_004b7210() && static_cast<unsigned char>(FUN_004b7210()->GetKey()))
        FUN_007160b0(FUN_004b7210());
}

class IOManager;
class NiRenderer
{
  public:
    void StartScene();
};

extern IOManager* DAT_01202d98;
void __fastcall FUN_00c3e310(IOManager*);
bool __cdecl FUN_00652160();
NiRenderer* __cdecl FUN_0043c4b0();
unsigned int __cdecl FUN_008781f0();
void __cdecl FUN_008781e0(int);
void __cdecl FUN_00703980();

// @fnv 0x00878160
void __cdecl FUN_00878160(char* aFreeData, bool abLockRenderer, bool abRunHeapClean, bool abArg4)
{
    FUN_00c3e310(DAT_01202d98);
    if (abArg4)
    {
        aFreeData[5] = FUN_00652160();
    }
    else
    {
        aFreeData[5] = abArg4;
    }
    if (abLockRenderer)
    {
        FUN_0043c4b0()->StartScene();
    }
    aFreeData[3] = abLockRenderer;
    aFreeData[4] = abRunHeapClean;
    *(unsigned int*)(aFreeData + 8) = FUN_008781f0();
    FUN_008781e0(0x7FFFFFFF);
    FUN_00703980();
}

struct bhkEntityListener_shell
{
    int pad0;
    int pad1;
    bool bEnabled;
    void FUN_00937090(bool abTF);
};

// @fnv 0x00937090
void bhkEntityListener_shell::FUN_00937090(bool abTF)
{
    bEnabled = abTF;
}

struct FUN_009604f0_shell : public TESObjectCELL
{
    void* FUN_009604f0();
};

// @fnv 0x009604f0
void* FUN_009604f0_shell::FUN_009604f0()
{
    return reinterpret_cast<char*>(this) + 0xAC;
}

// @fnv 0x009938b0
unsigned int __fastcall FUN_009938b0(const unsigned short* pThis)
{
    return pThis[6];
}

namespace fnv_009d9f20 {
struct BSPortalGraph;
struct FUN_009d9f20_shell : public TESObjectCELL
{
    BSPortalGraph* FUN_009d9f20();
};

template <typename T> class BSStringT
{
  public:
    operator const char*() const;
};

// @fnv 0x009d9f20
BSPortalGraph* FUN_009d9f20_shell::FUN_009d9f20()
{
    return (BSPortalGraph*)(const char*)*(BSStringT<char>*)((char*)this + 0xd4);
}
}  // namespace fnv_009d9f20

struct FUN_00c3e310_shell : public TESObjectCELL
{
    void FUN_00c3e310();
};

bool __fastcall FUN_00c3e750(void*);

// If FUN_00c3e750 returns true and the function pointer at offset 0x7c is set, calls that callback.
// @fnv 0x00c3e310
void FUN_00c3e310_shell::FUN_00c3e310()
{
    if (FUN_00c3e750(this) && *(void (**)(void))((char*)this + 0x7c))
        (*(void (**)(void))((char*)this + 0x7c))();
}

struct GO
{
    char b[4];
    GO(int);
    ~GO();
};
struct SL
{
    char b[8];
    SL();
    ~SL();
};
struct FUN_00558d40
{
    char b[16];
    FUN_00558d40(int);
    ~FUN_00558d40();
};
struct FUN_00558d70
{
    char b[16];
    FUN_00558d70(int);
    ~FUN_00558d70();
};
struct FUN_00558da0
{
    char b[16];
    FUN_00558da0(int);
    ~FUN_00558da0();
};
struct FUN_00544f60 : public GO
{
    SL a;
    FUN_00558d40 b;
    FUN_00558d70 c;
    FUN_00558d40 d;
    FUN_00558da0 e;
    SL f;
    SL g;
    SL h;
    FUN_00544f60();
};
// Constructs the object, initializing base GO with 0 and members b, c, d, e with 0x25.
// @fnv 0x00544f60
FUN_00544f60::FUN_00544f60() : GO(0), b(0x25), c(0x25), d(0x25), e(0x25)
{}

struct FUN_005496b0_shell : public TESObjectCELL
{
    void FUN_005496b0(TESObjectREFR*, NiNode*);
};

struct NiNodeV
{
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual void p13();
    virtual void p14();
    virtual void p15();
    virtual void p16();
    virtual void p17();
    virtual void p18();
    virtual void p19();
    virtual void p20();
    virtual void p21();
    virtual void p22();
    virtual void p23();
    virtual void p24();
    virtual void p25();
    virtual void p26();
    virtual void p27();
    virtual void p28();
    virtual void p29();
    virtual void p30();
    virtual void p31();
    virtual void p32();
    virtual void p33();
    virtual void p34();
    virtual void p35();
    virtual void p36();
    virtual void p37();
    virtual void p38();
    virtual void p39();
    virtual void p40();
    virtual void p41();
    virtual void p42();
    virtual void p43();
    virtual void p44();
    virtual void p45();
    virtual void p46();
    virtual void p47();
    virtual void p48();
    virtual void p49();
    virtual void p50();
    virtual void p51();
    virtual void p52();
    virtual void p53();
    virtual void p54();
    virtual void p55();
    virtual void p56();
    virtual void p57();
    virtual void InsertChild(NiAVObject*);
};
struct RefA
{
    NiAVObject* GetReferenceType();
};
struct ShadowSceneNode
{
    void RemoveSceneObject(NiAVObject*, bool);
};
struct NiAdditionalGeometryData
{
    static ShadowSceneNode* __cdecl GetShadowSceneNodeForIndex(int);
};
struct DetailedActorPathHandler
{
    void HandleReferenceUpdate(TESObjectREFR*, bool, bool);
};
// Attaches the reference's NiAVObject to apParent (or detaches it), updates the path handler and shadow scene node, then releases the cell lock.
// @fnv 0x005496b0
void FUN_005496b0_shell::FUN_005496b0(TESObjectREFR* apRef, NiNode* apParent)
{
    NiAVObject* pnewchild;
    if (!apRef || !((RefA*)apRef)->GetReferenceType())
        return;
    CellRefLockEnter();
    pnewchild = ((RefA*)apRef)->GetReferenceType();
    if (apParent)
    {
        ((void(__thiscall*)(NiNode*, NiAVObject*, int))(*(void***)apParent)[0xdc / 4])(apParent, pnewchild, 1);
    }
    else if (pnewchild->GetParent())
    {
        ((NiNodeV*)pnewchild->GetParent())->InsertChild(pnewchild);
    }
    if (!apParent || ((NiAVObject*)apParent != GetDynamicNode() &&
                      !((int(__thiscall*)(NiNode*))(*(void***)apParent)[0x14 / 4])(apParent)))
        ((DetailedActorPathHandler*)this)->HandleReferenceUpdate(apRef, true, false);
    NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)->RemoveSceneObject(
        ((NiAVObject * (__thiscall*)(TESObjectREFR*))(*(void***)apRef)[0x1d0 / 4])(apRef), false);
    CellRefLockLeave();
}

struct RefH
{
    bool FUN_00568680();
    bool IsDeleted() const;
    bool GetDisabled();
};
struct G2
{
    void AddHead(RefStub**);
};
struct Shell54ca00 : TESObjectCELL
{
    void FUN_0054ca00(G2* apList);
};
// Locks cell refs, walks the node list, and prepends each non-deleted, enabled ref that passes FUN_00568680 to apList.
// @fnv 0x0054ca00
void Shell54ca00::FUN_0054ca00(G2* apList)
{
    if (apList)
    {
        CellRefLockEnter();
        NodeStub* node = (NodeStub*)FUN_009604f0();
        while (node)
        {
            RefStub* ref = *node->_ref_006815c0();
            if (ref && ((RefH*)ref)->FUN_00568680() && !((RefH*)ref)->IsDeleted() && !((RefH*)ref)->GetDisabled())
                apList->AddHead(&ref);
            node = node->_ref_00726070();
        }
        CellRefLockLeave();
    }
}

struct FUN_00550280_shell : public TESObjectCELL
{
    bool FUN_00550280(TESFile*);
};

struct S54deb0
{
    unsigned int FUN_0054deb0();
};
struct FileH
{
    bool IsMasterFile();
    bool SetOffset(unsigned int);
    int _ref_00472660();
    unsigned int GetFormID();
};
struct DoorH
{
    void* GetParentWorldSpace();
};
struct WorldH
{
    void SeekToCellInWorld(TESFile*, int, int);
};
unsigned int __fastcall _ref_0084e3a0(void*);
// @fnv 0x00550280
bool FUN_00550280_shell::FUN_00550280(TESFile* apFile)
{
    unsigned int ioffset;
    if (apFile && ((FileH*)apFile)->IsMasterFile())
    {
        if (IsCellInterior())
        {
            ioffset = ((S54deb0*)this)->FUN_0054deb0();
            if (ioffset)
                ((FileH*)apFile)->SetOffset(ioffset);
        }
        else
        {
            void* pworld;
            pworld = ((DoorH*)this)->GetParentWorldSpace();
            if (pworld)
                ((WorldH*)pworld)->SeekToCellInWorld(apFile, GetCellGridX(), GetCellGridY());
        }
        if (((FileH*)apFile)->_ref_00472660() == 0x39 && ((FileH*)apFile)->GetFormID() == _ref_0084e3a0(this))
            return true;
    }
    return false;
}

struct TESRace;
struct SrcList;
struct FormS
{
    SrcList* GetSourceFiles();
};
struct BSSimpleListTESRaceSize
{
    int GetSize();
};
// @fnv 0x005504e0
int __fastcall GetSourceFileCount(FormS* p)
{
    return ((BSSimpleListTESRaceSize*)p->GetSourceFiles())->GetSize();
}

namespace fnv_005575d0 {
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BipedAnim;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiColor;
struct NiPoint3;
struct Script;
struct TESBoundObject;
struct TESForm;
struct TESFullName;
struct TESModel;
struct TESModelTextureSwap;
struct TESObject;
struct TESFormList;
struct FileEntryList;
struct TESWaterForm;
struct DistantTreeTextureInfo;
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
struct FUN_005575d0_shell : public TESObjectCELL
{
    void UpdateNavMeshObstacles();
};

struct TESObjectREFR;
struct RefStub;
int __fastcall _FNV_GetFormType(void*);
int __fastcall _FNV_GetObjectReference(RefStub*);
struct NodeStub
{
    RefStub** _ref_006815c0();
    NodeStub* _ref_00726070();
};
typedef bool(__thiscall* VFn)(RefStub*);
struct RefStub
{
    virtual void v0();
};
struct TESObjectDOOR;
struct NavMeshObstacleManager
{
    static NavMeshObstacleManager* __cdecl GetSingleton();
    void FUN_006c0c30(TESObjectREFR*);
    void AddObstacleReference(TESObjectREFR*);
};
struct BGSOpenCloseForm
{
    static int __cdecl GetOpenState(TESObjectREFR*);
};
bool __fastcall FUN_00518080(TESObjectDOOR*);
// @fnv 0x005575d0
void FUN_005575d0_shell::UpdateNavMeshObstacles()
{
    NodeStub* pCurrentElementNext;
    CellRefLockEnter();
    pCurrentElementNext = (NodeStub*)FUN_009604f0();
    while (pCurrentElementNext)
    {
        RefStub* pref = *pCurrentElementNext->_ref_006815c0();
        if (pref)
        {
            if ((*(VFn**)pref)[0x15c / 4](pref))
                NavMeshObstacleManager::GetSingleton()->FUN_006c0c30((TESObjectREFR*)pref);
            if (_FNV_GetFormType((void*)_FNV_GetObjectReference(pref)) == 0x1c)
            {
                if (BGSOpenCloseForm::GetOpenState((TESObjectREFR*)pref) == 1)
                {
                    TESObjectDOOR* pdoor = (TESObjectDOOR*)_FNV_GetObjectReference(pref);
                    if (!FUN_00518080(pdoor))
                        NavMeshObstacleManager::GetSingleton()->FUN_006c0c30((TESObjectREFR*)pref);
                }
                else
                {
                    NavMeshObstacleManager::GetSingleton()->AddObstacleReference((TESObjectREFR*)pref);
                }
            }
        }
        pCurrentElementNext = pCurrentElementNext->_ref_00726070();
    }
    CellRefLockLeave();
}
}  // namespace fnv_005575d0

struct Helper62d0
{
    Helper62d0& operator=(void* const&);
};
struct MapItem62d0
{
    MapItem62d0* next;
    void* key;
    void* val;
};
struct Map62d0
{
    virtual void v0();
    virtual unsigned int Hash(void*);
    unsigned int size;
    MapItem62d0** table;
    void FUN_00559120(MapItem62d0*& pos, void*& key, Helper62d0& val);
};
// Reads the current map entry's key and value, then advances pos to the next entry in the chain or the next non-empty table slot, or null.
// @fnv 0x00559120
void Map62d0::FUN_00559120(MapItem62d0*& pos, void*& key, Helper62d0& val)
{
    MapItem62d0* item = pos;
    key = item->key;
    val = item->val;
    if (item->next)
    {
        pos = item->next;
        return;
    }
    unsigned int i = Hash(item->key);
    i = i + 1;
    for (; i < size; i++)
    {
        item = table[i];
        if (item)
        {
            pos = item;
            return;
        }
    }
    pos = 0;
}

extern unsigned int DAT_010a2720;
void* __cdecl memset(void*, int, unsigned int);
struct ScrapHeapBuffer
{
    ScrapHeapBuffer();
    ~ScrapHeapBuffer();
    void* Allocate(unsigned int, unsigned int);
};
struct FUN_00559b40
{
    virtual ~FUN_00559b40();
    unsigned int size;
    void* data;
    int pad;
    char flag;
    FUN_00559b40(int);
};
struct FUN_005595e0 : public FUN_00559b40
{
    ScrapHeapBuffer heap;
    FUN_005595e0(unsigned int uiHashSize, bool abClearOnDestruct);
    virtual ~FUN_005595e0();
};
// @fnv 0x005595e0
FUN_005595e0::FUN_005595e0(unsigned int uiHashSize, bool abClearOnDestruct) : FUN_00559b40(0)
{
    size = uiHashSize;
    flag = abClearOnDestruct;
    unsigned int isize = uiHashSize << 2;
    data = heap.Allocate(isize, DAT_010a2720);
    memset(data, 0, isize);
}

namespace sh {
struct ScrapHeapBuffer
{
    int d;
    ~ScrapHeapBuffer();
};
}
struct FUN_005596a0
{
    virtual ~FUN_005596a0();
};
struct FUN_005596e0 : public FUN_005596a0
{
    int f4;
    int f8;
    int fc;
    bool f10;
    sh::ScrapHeapBuffer m14;
    virtual ~FUN_005596e0();
    void FUN_00559bc0();
};
// If f10 is set, calls FUN_00559bc0, then clears f8, fc and f4.
// @fnv 0x005596e0
FUN_005596e0::~FUN_005596e0()
{
    if (f10)
        FUN_00559bc0();
    f8 = 0;
    fc = 0;
    f4 = 0;
}

namespace fnv_00545a30 {
struct FUN_00545a30_shell : public TESObjectCELL
{
    void AttachOrphanedChildren();
};

struct SpArr
{
};
struct Flt : public SpArr
{
    operator unsigned int() const;
};
struct GO : public Flt
{
    void* m_ptr;
    GO(int);
    ~GO();
};

struct MapX
{
    void* GetFirstPos();
    void FUN_00559120(void*&, unsigned int&, SpArr&);
};

struct MapHolder
{
    char pad[0x3c];
    MapX map;
};

struct NiNodeVtbl
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
    virtual unsigned int AttachChildInAvailableSlot(unsigned int, int);
};

// @fnv 0x00545a30
void FUN_00545a30_shell::AttachOrphanedChildren()
{
    NiNode* pparent = (NiNode*)((TESObjectCELL*)this)->GetCellChildAt(7);
    if (pparent && *(MapHolder**)((char*)this + 0xc4))
    {
        void* iter = (*(MapHolder**)((char*)this + 0xc4))->map.GetFirstPos();
        while (iter)
        {
            GO spnode(0);
            unsigned int pref = 0;
            (*(MapHolder**)((char*)this + 0xc4))->map.FUN_00559120(iter, pref, spnode);
            if ((unsigned int)spnode && !((NiAVObject*)(unsigned int)spnode)->GetParent())
            {
                ((NiNodeVtbl*)pparent)->AttachChildInAvailableSlot((unsigned int)spnode, 1);
            }
        }
    }
}
}  // namespace fnv_00545a30

struct BSPortalGraph;
struct FUN_00545b30_shell : public TESObjectCELL
{
    BSPortalGraph* GetPortalGraph();
};

struct BSFadeNode
{
    char pad[0x78];
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};

struct FUN_00c5a9d0 : BSFadeNode
{
    FUN_00c5a9d0();
};

struct Flt
{
    operator unsigned int() const;
};

struct NP : Flt
{
    NP& operator=(void*);
};

void* __fastcall GetOrCreateObject(TESWorldSpace*);

// @fnv 0x00545b30
BSPortalGraph* FUN_00545b30_shell::GetPortalGraph()
{
    if (!(*(NP*)((char*)this + 0xd4)).operator unsigned int())
    {
        if (((TESObjectCELL*)this)->IsCellInterior())
        {
            *(NP*)((char*)this + 0xd4) = new FUN_00c5a9d0();
        }
        else
        {
            *(NP*)((char*)this + 0xd4) = GetOrCreateObject(((TESObjectCELL*)this)->GetParentWorldSpace());
        }
    }
    return (BSPortalGraph*)(*(NP*)((char*)this + 0xd4)).operator unsigned int();
}

struct G7d1
{
    bool __thiscall GetBoolValue(void);
};

struct GlobalObjectO2_0045cf30
{
    G7d1 m_g7d1;
};

GlobalObjectO2_0045cf30 g_01267b28;

// @fnv 0x00454ae0
void __cdecl FUN_00454ae0()
{
    g_01267b28.m_g7d1.GetBoolValue();
}

struct FUN_005422b0Class
{
    void __thiscall FUN_005422b0();
    void __thiscall FUN_00559460();
};

// @fnv 0x005422b0
void __thiscall FUN_005422b0Class::FUN_005422b0()
{
    FUN_00559460();
}

struct FUN_005443e0_class
{
    unsigned char IsFlag20Set();
    unsigned char FUN_00544420();
    unsigned char IsAnyConditionTrue();
};

// Returns 1 if IsFlag20Set or FUN_00544420 succeeds, otherwise returns 0.
// @fnv 0x005443e0
unsigned char FUN_005443e0_class::IsAnyConditionTrue()
{
    if (IsFlag20Set())
        return 1;
    if (FUN_00544420())
        return 1;
    return 0;
}

struct FUN_00546a00Class
{
    void __thiscall ClearFieldA4();
};

// @fnv 0x00546a00
void __thiscall FUN_00546a00Class::ClearFieldA4()
{
    *(int*)((char*)this + 0xa4) = 0;
}

struct FUN_00546a20Class
{
    void ClearField();
};

// @fnv 0x00546a20
void FUN_00546a20Class::ClearField()
{
    ((int*)this)[0x28] = 0;
}

extern unsigned char DAT_011ad7b4;

// @fnv 0x0054f4b0
unsigned char FUN_0054f4b0()
{
    return DAT_011ad7b4;
}

void* __cdecl FUN_00664840(bool param);

// @fnv 0x0054f4d0
void __cdecl SetByteAtOffset1B(unsigned char ucValue)
{
    *(unsigned char*)((char*)FUN_00664840(1) + 0x1b) = ucValue;
}

extern unsigned int DAT_011d5c44;

// @fnv 0x00552380
unsigned int FUN_00552380()
{
    return DAT_011d5c44;
}

namespace fnv_005524d0 {
struct GlobalObjectO2_0045cf30
{
    unsigned char* GetLifeStateControlFlag(void);
};

GlobalObjectO2_0045cf30 g_01267c24;

// @fnv 0x005524d0
unsigned char FUN_005524d0()
{
    return *g_01267c24.GetLifeStateControlFlag();
}
}  // namespace fnv_005524d0

namespace fnv_005526d0 {
struct TaskQueueInterface
{
    void SetTaskFlagDWord(bool, unsigned int);
    void SetEnabledFlag(bool enabled);
};

// @fnv 0x005526d0
void TaskQueueInterface::SetEnabledFlag(bool enabled)
{
    SetTaskFlagDWord(enabled, 0x400000);
}
}  // namespace fnv_005526d0

struct FUN_00552da0_class
{
    char m[0x26];
    char bUnk26;
    char GetUnk26();
};

// @fnv 0x00552da0
char FUN_00552da0_class::GetUnk26()
{
    return bUnk26;
}

namespace fnv_005535c0 {
struct FUN_00553540
{
    virtual ~FUN_00553540();
    void* FUN_005535c0(unsigned int flags);
};

void __cdecl FUN_00538eb0(FUN_00553540* p);

// @fnv 0x005535c0
void* FUN_00553540::FUN_005535c0(unsigned int flags)
{
    FUN_00553540::~FUN_00553540();
    if (flags & 1)
        FUN_00538eb0(this);
    return this;
}
}  // namespace fnv_005535c0

int __fastcall GetByteAtOffset38(void*);

struct FUN_00557d10_Class
{
    bool __thiscall FUN_00557d10();
};

// @fnv 0x00557d10
bool __thiscall FUN_00557d10_Class::FUN_00557d10()
{
    if (GetByteAtOffset38(this))
        return true;
    else
        return false;
}

struct FUN_00558c60Class
{
    int m_0x00;
    int m_0x04;
    int m_0x08;
    int m_0x0C;
    int m_0x10;
    int m_0x14;
    int m_0x18;
    int m_0x1C;
    int m_0x20;
    int m_0x24;
    int m_0x28;
    int m_0x2C;
    int m_0x30;
    int m_0x34;
    int m_0x38;
    int m_0x3C;
    int m_0x40;
    int m_0x44;
    int m_0x48;
    int m_0x4C;
    int m_0x50;
    int m_0x54;
    int m_0x58;
    int m_0x5C;
    int m_0x60;
    int* m_0x64;
    void __thiscall FUN_00558c60(int a1);
};

// Stores the given int into the object pointed to by m_0x64, if that pointer is non-null.
// @fnv 0x00558c60
void __thiscall FUN_00558c60Class::FUN_00558c60(int aiValue)
{
    if (m_0x64 != 0)
    {
        *m_0x64 = aiValue;
    }
}

extern int DAT_0102f338;

struct FUN_005590b0_S
{
    void __thiscall InitArray(int param_2);
};

struct FUN_00558da0_S : FUN_005590b0_S
{
    int* m_iWordAt00;
    FUN_00558da0_S* __thiscall FUN_00558da0(int param_2);
};

// @fnv 0x00558da0
FUN_00558da0_S* __thiscall FUN_00558da0_S::FUN_00558da0(int param_2)
{
    InitArray(param_2);
    m_iWordAt00 = &DAT_0102f338;
    return this;
}

namespace fnv_00559780 {
struct ScrapHeapBuffer
{
    void* Allocate(unsigned int, unsigned int);
};

extern unsigned int DAT_010a2720;

class FUN_00559780
{
  public:
    void CellRefLockEnter();
};

// @fnv 0x00559780
void FUN_00559780::CellRefLockEnter()
{
    ((ScrapHeapBuffer*)((char*)this + 0x14))->Allocate(0xc, DAT_010a2720);
}
}  // namespace fnv_00559780

struct NiTListItem
{
    NiTListItem* m_pNext;
};

struct NiTPointerListBase
{
    NiTListItem* m_pHead;
    NiTListItem* m_pTail;
    NiTListItem* m_pDummy;
    void FUN_00559c90(NiTListItem* pkNode);
    void FUN_00559c30();
};

// @fnv 0x00559c30
void NiTPointerListBase::FUN_00559c30()
{
    NiTListItem* pkNode = m_pHead;
    while (pkNode)
    {
        NiTListItem* pkOld = pkNode;
        pkNode = pkNode->m_pNext;
        FUN_00559c90(pkOld);
    }
    m_pDummy = 0;
    m_pHead = 0;
    m_pTail = 0;
}

int __cdecl TESWorldSpace_GetKeyForCellCoord(short a, short b);

// Shifts a and b right by 5 to cell coordinates and returns TESWorldSpace_GetKeyForCellCoord of them.
// @fnv 0x00544280
int GetCellCoordKey(int aiX, int aiY)
{
    int iKey;
    short s3 = (short)(aiX >> 5);
    short s2 = (short)(aiY >> 5);
    iKey = TESWorldSpace_GetKeyForCellCoord(s3, s2);
    return iKey;
}

int __cdecl PackShortPair(short, short);

// @fnv 0x005442c0
int FUN_005442c0(int a1, int a2)
{
    short v6 = a1 >> 3;
    short v2 = a2 >> 3;
    int v3 = PackShortPair(v6, v2);
    return v3;
}

struct FUN_00548700_Class
{
    unsigned int _0x00;
    unsigned int _0x04;
    unsigned int _0x08;
    bool FUN_00548700() const;
};

// @fnv 0x00548700
bool FUN_00548700_Class::FUN_00548700() const
{
    return (_0x08 & 0x10000000) ? true : false;
}

struct CheckWithinMultiBoundTask
{
    void __thiscall FUN_0054ab60();
    void* __thiscall FUN_0054ab30(unsigned int flags);
};

void __cdecl _Deallocate(void* p);

// Calls FUN_0054ab60, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0054ab30
void* __thiscall CheckWithinMultiBoundTask::FUN_0054ab30(unsigned int flags)
{
    FUN_0054ab60();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct NiRenderTargetGroup;
struct BSRenderedTexture
{
    NiRenderTargetGroup* GetGroup();
};
bool __cdecl FUN_00b6b7d0(NiRenderTargetGroup*, int);

// Gets the render target group from texture (or null if texture is null) and forwards it with arg to FUN_00b6b7d0, returning its result.
// @fnv 0x0054ede0
bool __cdecl FUN_0054ede0(BSRenderedTexture* texture, int arg)
{
    NiRenderTargetGroup* group;
    if (texture)
        group = texture->GetGroup();
    else
        group = 0;
    return FUN_00b6b7d0(group, arg);
}

struct FUN_00557aa0_Class
{
    void FUN_00557aa0();
};

// If the byte at offset 0xce is clear, sets it to 1, clears the byte at 0xcf and zeroes the float at 0xc8; otherwise returns early.
// @fnv 0x00557aa0
void FUN_00557aa0_Class::FUN_00557aa0()
{
    if (*(unsigned char*)(this + 0xce))
    {
        return;
    }
    *(unsigned char*)(this + 0xce) = 1;
    *(unsigned char*)(this + 0xcf) = 0;
    *(float*)(this + 0xc8) = 0.0f;
}

struct FUN_00557d30_class
{
    char m_d0[0xd0];
    char m_flag;
    char FUN_00557d30();
};
// @fnv 0x00557d30
char FUN_00557d30_class::FUN_00557d30()
{
    return m_flag;
}

namespace fnv_00558fb0 {
void* __cdecl _NiMalloc(unsigned int);
extern "C" void* __cdecl memset(void*, int, unsigned int);
extern int DAT_0102f378;
struct NiTMapItem
{
    void* m_ppVirtualMethodTable;
    int m_uiItemCount;
    void* m_data;
    int m_iElementCount;
    void* FUN_00558fb0(int count);
};
// @fnv 0x00558fb0
void* NiTMapItem::FUN_00558fb0(int count)
{
    m_ppVirtualMethodTable = (void*)&DAT_0102f378;
    m_uiItemCount = count;
    m_iElementCount = 0;
    unsigned int size = m_uiItemCount * 4;
    m_data = _NiMalloc(size);
    memset(m_data, 0, m_uiItemCount * 4);
    return this;
}
}  // namespace fnv_00558fb0

struct FUN_00544300_Class
{
    char pad1[0x24];
    unsigned char m_24;
    void FUN_00544300(bool a1);
};

// Sets or clears bit 0 of m_24 according to a1.
// @fnv 0x00544300
void FUN_00544300_Class::FUN_00544300(bool abSet)
{
    if (abSet)
        m_24 |= 1;
    else
        m_24 &= ~1;
}

struct FUN_00544420_StandIn
{
    char pad[0x24];
    unsigned char f24;
    bool FUN_00544420();
};

// @fnv 0x00544420
bool FUN_00544420_StandIn::FUN_00544420()
{
    return f24 & 0x40;
}

struct ArrSI
{
    unsigned int GetFlags();
};

struct FUN_00544490_Class
{
    unsigned char FUN_00544490();
};

// @fnv 0x00544490
unsigned char __thiscall FUN_00544490_Class::FUN_00544490()
{
    unsigned int flags = ((ArrSI*)this)->GetFlags();
    if (flags & 0x20000)
        return 1;
    return 0;
}

struct FUN_00546950_Class
{
    char pad[0x244];
    int m_uiInitializationFlags;
    bool FUN_00546950() const;
};

// @fnv 0x00546950
bool FUN_00546950_Class::FUN_00546950() const
{
    return (m_uiInitializationFlags & 0x10) ? true : false;
}

namespace fnv_00546c70 {
struct Calendar
{
    unsigned int GetGameHoursPassed();
};
extern Calendar g_calendar;

struct TESObjectCELL_s
{
    void SetDetachTime(unsigned int, bool);
    void __thiscall FUN_00546c70();
};

// @fnv 0x00546c70
void __thiscall TESObjectCELL_s::FUN_00546c70()
{
    unsigned int hours = g_calendar.GetGameHoursPassed();
    SetDetachTime(hours, false);
}
}  // namespace fnv_00546c70

struct ExtraDataList;
struct FUN_0041c290_shell
{
    void __thiscall SetImageSpaceExtra(int a);
};

struct FUN_00547750_shell : public TESDataHandler
{
    void __thiscall FUN_00547750(int a);
};

// Calls SetImageSpaceExtra on the TESImageSpaceModifierList obtained from GetTESImageSpaceModifierList, passing a.
// @fnv 0x00547750
void __thiscall FUN_00547750_shell::FUN_00547750(int a)
{
    ((FUN_0041c290_shell*)GetTESImageSpaceModifierList())->SetImageSpaceExtra(a);
}

struct FNStub
{
    const char* __thiscall GetFullName(void);
};

struct FUN_00548210_Class
{
    char pad[0xd4];
    FNStub m_stub;
    const char* __thiscall FUN_00548210();
};

// @fnv 0x00548210
const char* __thiscall FUN_00548210_Class::FUN_00548210()
{
    return m_stub.GetFullName();
}

struct FUN_005495a0Class
{
    char pad_a8[0xa8];
    short m_a8;  // +0xa8
    short m_aa;  // +0xaa
    bool FUN_005495a0();
};

// Returns whether m_a8 is less than or equal to m_aa.
// @fnv 0x005495a0
bool FUN_005495a0Class::FUN_005495a0()
{
    return m_a8 <= m_aa;
}

struct FUN_0054b800_class
{
    void FUN_0054b800();
    void FUN_00476ae0(int);
};
// Clears the two floats at offsets 0xb8 and 0xb4 to zero and calls FUN_00476ae0 with 0.
// @fnv 0x0054b800
void FUN_0054b800_class::FUN_0054b800()
{
    *(float*)((char*)this + 0xb8) = 0.0f;
    *(float*)((char*)this + 0xb4) = 0.0f;
    FUN_00476ae0(0);
}

struct FUN_0054da00_class
{
    void __thiscall FUN_0054da00();
    void __thiscall FUN_00559810();
};
// @fnv 0x0054da00
void __thiscall FUN_0054da00_class::FUN_0054da00()
{
    FUN_00559810();
}

struct FUN_0054de80Class : public TESObjectCELL
{
    void FUN_0054de80(int value);
};

// @fnv 0x0054de80
void FUN_0054de80Class::FUN_0054de80(int value)
{
    if (IsCellInterior())
        *(int*)((char*)this + 0xc0) = value;
}

struct FUN_005524b0_class
{
    unsigned char GetByteAtOffset8C();
};

// @fnv 0x005524b0
unsigned char FUN_005524b0_class::GetByteAtOffset8C()
{
    return ((const unsigned char*)this)[0x8c];
}

extern int DAT_0102f2f8;

struct FUN_00558d40_class
{
    void* m_p;
    void __thiscall FUN_00558eb0(int a);
    FUN_00558d40_class* __thiscall FUN_00558d40(int a);
};

// Calls FUN_00558eb0 with a, sets m_p to DAT_0102f2f8, and returns this.
// @fnv 0x00558d40
FUN_00558d40_class* __thiscall FUN_00558d40_class::FUN_00558d40(int a)
{
    FUN_00558eb0(a);
    m_p = &DAT_0102f2f8;
    return this;
}

extern int DAT_0102f318;
struct FUN_00558d70_Class
{
    int* vfn;
    void FUN_00558fb0(int a);
    FUN_00558d70_Class* FUN_00558d70(int a);
};
// Calls FUN_00558fb0 with a, sets vfn to DAT_0102f318, and returns this.
// @fnv 0x00558d70
FUN_00558d70_Class* FUN_00558d70_Class::FUN_00558d70(int a)
{
    FUN_00558fb0(a);
    vfn = &DAT_0102f318;
    return this;
}

struct FUN_00558dd0_class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int __thiscall FUN_00558dd0(unsigned int index);
};

// @fnv 0x00558dd0
int __thiscall FUN_00558dd0_class::FUN_00558dd0(unsigned int index)
{
    return *(int*)((char*)this + 4) + index * 16;
}

struct hkReferencedObject
{
    void removeReference();
};
struct FUN_00558e80_Class
{
    hkReferencedObject* m_pObject;
    void ReleaseObject();
};
// Removes a reference from m_pObject if set, then clears the pointer.
// @fnv 0x00558e80
void FUN_00558e80_Class::ReleaseObject()
{
    if (m_pObject)
        m_pObject->removeReference();
    m_pObject = 0;
}

extern "C" void _NiFreeAlias(void*);
struct MyMap
{
    void RemoveAll();
};
extern int DAT_0102f358;
struct FUN_00558f80
{
    void* vtbl;
    int a;
    void* b;
    void Init();
};
// Sets vtbl to DAT_0102f358, clears the map contents, and frees b via _NiFreeAlias.
// @fnv 0x00558f80
void FUN_00558f80::Init()
{
    vtbl = (void*)&DAT_0102f358;
    ((MyMap*)this)->RemoveAll();
    _NiFreeAlias(b);
}

namespace fnv_00559080 {
extern int DAT_0102f378;
struct MyMap
{
    void RemoveAll();
};
void __cdecl NiFreeAlias(void*);
struct FUN_00559080 : MyMap
{
    void* vtbl;
    int unused;
    void* ptr;
    void Init();
};
// Sets vtbl to DAT_0102f378, calls RemoveAll, then frees ptr via NiFreeAlias.
// @fnv 0x00559080
void FUN_00559080::Init()
{
    vtbl = &DAT_0102f378;
    RemoveAll();
    NiFreeAlias(ptr);
}
}  // namespace fnv_00559080

extern int DAT_0102f3c0;

struct FUN_005594b0_class
{
    void* vtable;
    void __thiscall FUN_00559ad0(int, int);
    FUN_005594b0_class* __thiscall Construct(int a, int b);
};

// Calls FUN_00559ad0 with the two arguments, sets the vtable to DAT_0102f3c0, and returns this.
// @fnv 0x005594b0
FUN_005594b0_class* __thiscall FUN_005594b0_class::Construct(int aiArg1, int aiArg2)
{
    FUN_00559ad0(aiArg1, aiArg2);
    vtable = &DAT_0102f3c0;
    return this;
}

namespace fnv_005597a0 {
struct ScrapHeapBuffer
{
    void Deallocate(void*);
};
struct FUN_005597a0_Class
{
    void ClearAndDeallocate(void* arg);
};
// @fnv 0x005597a0
void FUN_005597a0_Class::ClearAndDeallocate(void* arg)
{
    ((char*)arg)[8] = 0;
    ((ScrapHeapBuffer*)((char*)this + 0x14))->Deallocate(arg);
}
}  // namespace fnv_005597a0

namespace fnv_004695a0 {
struct FileH
{
    bool IsMasterFile();
};
struct TESSaveLoadGame
{
    bool GetLoading();
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
int __cdecl FindFormEnumIndex(unsigned int);
struct FUN_004695a0_rec
{
    unsigned int a;
    unsigned int b;
    unsigned int auiFormId;
    unsigned int uiType;
};
struct FUN_004695a0_t : public TESObjectCELL
{
    bool FUN_004695a0(FileH* apFile, FUN_004695a0_rec* apRec);
};

// @fnv 0x004695a0
bool FUN_004695a0_t::FUN_004695a0(FileH* apFile, FUN_004695a0_rec* apRec)
{
    bool bretval = true;
    if (apFile && !apFile->IsMasterFile() && !(g_TESSaveLoadGame && g_TESSaveLoadGame->GetLoading()))
        return true;
    if (apRec)
    {
        switch (apRec->uiType)
        {
        case 4:
        case 5:
        case 9:
            bretval = false;
            break;
        }
        if (bretval && g_TESSaveLoadGame && g_TESSaveLoadGame->GetLoading())
        {
            switch (FindFormEnumIndex(apRec->auiFormId))
            {
            case 0x3:
            case 0x4:
            case 0x5:
            case 0x7:
            case 0x9:
            case 0xa:
            case 0xb:
            case 0xc:
            case 0xd:
            case 0xe:
            case 0xf:
            case 0x10:
            case 0x11:
            case 0x12:
            case 0x13:
            case 0x14:
            case 0x15:
            case 0x16:
            case 0x17:
            case 0x1b:
            case 0x1c:
            case 0x1d:
            case 0x20:
            case 0x21:
            case 0x23:
            case 0x24:
            case 0x25:
            case 0x26:
            case 0x27:
            case 0x2c:
            case 0x2d:
            case 0x2f:
            case 0x30:
            case 0x31:
            case 0x33:
            case 0x34:
            case 0x35:
            case 0x36:
            case 0x37:
            case 0x45:
            case 0x46:
            case 0x48:
            case 0x49:
            case 0x4a:
            case 0x4b:
            case 0x4c:
            case 0x4d:
            case 0x4e:
            case 0x4f:
            case 0x50:
            case 0x51:
            case 0x52:
            case 0x53:
            case 0x54:
            case 0x55:
            case 0x56:
            case 0x57:
            case 0x58:
            case 0x5b:
            case 0x5c:
            case 0x61:
            case 0x66:
            case 0x6f:
            case 0x70:
                bretval = false;
                break;
            }
        }
    }
    return bretval;
}
}  // namespace fnv_004695a0

struct FUN_0041c360_class
{
    unsigned int FUN_0041c360();
};
struct FUN_00547650_class
{
    unsigned int FUN_00547650();
};
// @fnv 0x00547650
unsigned int FUN_00547650_class::FUN_00547650()
{
    unsigned int result =
        reinterpret_cast<FUN_0041c360_class*>(((TESDataHandler*)this)->GetTESImageSpaceModifierList())->FUN_0041c360();
    return result;
}

namespace fnv_0054ae30 {
struct Flt
{
    void* p;
    operator unsigned int();
};
struct BSOcclusionPlane
{
    int GetCullResult() const;
};
struct FUN_005496b0_shell
{
    void FUN_005496b0(TESObjectREFR*, NiNode*);
};
struct FUN_0054acf0
{
    Flt m_pSceneObject;
    Flt m_pParent;
    unsigned int uiFlags;
    FUN_0054acf0();
    ~FUN_0054acf0();
};
struct MapX
{
    void* GetFirstPos();
    void FUN_005593a0(void*&, unsigned int&, FUN_0054acf0&);
    void RemoveAll();
};
extern MapX g_011ca0f4;
TESObjectREFR* __cdecl GetReferenceFromNiAVObject(NiAVObject*);

// @fnv 0x0054ae30
void FUN_0054ae30()
{
    void* pos = g_011ca0f4.GetFirstPos();
    while (pos)
    {
        unsigned int key = 0;
        FUN_0054acf0 data;
        g_011ca0f4.FUN_005593a0(pos, key, data);
        if (data.m_pSceneObject &&
            ((NiAVObject*)(unsigned int)data.m_pSceneObject)->GetParent() != (NiNode*)(unsigned int)data.m_pParent)
        {
            TESObjectREFR* pref = GetReferenceFromNiAVObject((NiAVObject*)(unsigned int)data.m_pSceneObject);
            if (pref && ((BSOcclusionPlane*)pref)->GetCullResult())
                ((FUN_005496b0_shell*)((BSOcclusionPlane*)pref)->GetCullResult())
                    ->FUN_005496b0(pref, (NiNode*)(unsigned int)data.m_pParent);
        }
    }
    g_011ca0f4.RemoveAll();
}
}  // namespace fnv_0054ae30

namespace fnv_0054c740 {
struct FUN_0054c740_shell : public TESObjectCELL
{
    bool FUN_0054c740(bool, bool);
};

struct RefH
{
    bool GetDisabled();
};
struct RefA
{
    NiAVObject* GetReferenceType();
};
struct MobileObjectExt
{
    bool FUN_00565870();
};
struct FUN_0056a380_cls
{
    bool FUN_0056a380();
};
struct Interface
{
    static bool __cdecl IsSaveLoadActive();
};
struct RefListOps
{
    bool FUN_008256d0();
    void FUN_0063f7b0();
    void Remove(TESObjectREFR* const& item);
};

// @fnv 0x0054c740
bool FUN_0054c740_shell::FUN_0054c740(bool bIgnore3D, bool bIgnoreActors)
{
    bool bquit = false;
    CellRefLockEnter();
    BSSimpleList<BGSPerkEntry*>* pCurrentElementNext = 0;
    if (*(void**)((char*)this + 0xc4))
        pCurrentElementNext = (BSSimpleList<BGSPerkEntry*>*)((char*)*(void**)((char*)this + 0xc4) + 0x4c);
    else if (bIgnore3D)
        pCurrentElementNext = FUN_009604f0();
    while (pCurrentElementNext)
    {
        TESObjectREFR* pref = (TESObjectREFR*)pCurrentElementNext->GetItem();
        pCurrentElementNext = pCurrentElementNext->GetNext();
        if (pref)
        {
            if ((bIgnore3D || ((RefA*)pref)->GetReferenceType() || ((RefH*)pref)->GetDisabled()) &&
                ((MobileObjectExt*)pref)->FUN_00565870() && !bIgnore3D)
            {
                bquit = true;
                break;
            }
        }
    }
    if (*(void**)((char*)this + 0xc4) && !bquit && !Interface::IsSaveLoadActive())
    {
        BSSimpleList<BGSPerkEntry*>* pCurrentElementNext =
            (BSSimpleList<BGSPerkEntry*>*)((char*)*(void**)((char*)this + 0xc4) + 0x54);
        BSSimpleList<BGSPerkEntry*>* pPrevNode = 0;
        while (pCurrentElementNext && !((RefListOps*)pCurrentElementNext)->FUN_008256d0())
        {
            TESObjectREFR* pref = (TESObjectREFR*)pCurrentElementNext->GetItem();
            if (!((FUN_0056a380_cls*)pref)->FUN_0056a380())
            {
                if (pPrevNode)
                {
                    ((RefListOps*)pPrevNode)->Remove(pref);
                    pCurrentElementNext = pPrevNode->GetNext();
                }
                else
                {
                    ((RefListOps*)pCurrentElementNext)->FUN_0063f7b0();
                }
            }
            else
            {
                pPrevNode = pCurrentElementNext;
                pCurrentElementNext = pCurrentElementNext->GetNext();
            }
        }
    }
    CellRefLockLeave();
    return bquit;
}
}  // namespace fnv_0054c740

namespace fnv_00550c60 {
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
struct InventoryChanges;
struct MagicItemForm;
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
struct TESPackage;
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
struct FUN_00550c60_shell : public TESObjectCELL
{
    void RecalcLeveledActorBases(bool);
};

struct FUN_00550c60_AB
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual ~FUN_00550c60_AB();
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
    virtual bool vf8();
};
struct FUN_00550c60_Ref
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
    virtual void v1cc(int, int);
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
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
    virtual bool v22c(int);
};

struct FUN_00550c60_List
{
    bool _ref_008256d0();
    FUN_00550c60_Ref** _ref_006815c0();
    FUN_00550c60_List* GetNext();
};
struct Calendar
{
    unsigned int GetGameHoursPassed();
};
extern Calendar g_calendar;
struct RefH
{
    bool IsDeleted() const;
};
struct TESActorBaseData
{
    bool GetUsesLeveledTemplate();
    void SetTemplateReference(TESObjectREFR*);
};
struct FUN_00881c90_cls
{
    bool IsExpired(unsigned int);
};
struct FUN_00550c60_RefFns
{
    FUN_00550c60_AB* _FNV_GetObjectReference();
    ExtraDataList* GetExtraData();
    void ClearReferenceState(TESBoundObject*);
    void FUN_0056b020(int, int);
};
FUN_00550c60_AB* __fastcall FUN_004216f0(BaseExtraList*);
// @fnv 0x00550c60
void FUN_00550c60_shell::RecalcLeveledActorBases(bool abAllowRecalc)
{
    FUN_00550c60_List* pCurrentElementNext;
    unsigned int uiCurrentTime;
    CellRefLockEnter();
    uiCurrentTime = g_calendar.GetGameHoursPassed();
    pCurrentElementNext = (FUN_00550c60_List*)FUN_009604f0();
    while (pCurrentElementNext && !pCurrentElementNext->_ref_008256d0())
    {
        bool badvanced = false;
        FUN_00550c60_Ref* pref = *pCurrentElementNext->_ref_006815c0();
        pCurrentElementNext = pCurrentElementNext->GetNext();
        if (((FUN_00550c60_RefFns*)pref)->_FNV_GetObjectReference()->vf8() && !((RefH*)pref)->IsDeleted() &&
            !pref->v22c(0))
        {
            Actor* pactor = (Actor*)pref;
            FUN_00550c60_AB* porigbase = ((FUN_00550c60_RefFns*)pref)->_FNV_GetObjectReference();
            {
                FUN_00550c60_AB* pNewBase = FUN_004216f0((BaseExtraList*)((FUN_00550c60_RefFns*)pref)->GetExtraData());
                if (pNewBase && pNewBase != porigbase)
                {
                    if (((FUN_00881c90_cls*)pactor)->IsExpired(uiCurrentTime))
                    {
                        pref->v1cc(0, 0);
                        ((FUN_00550c60_RefFns*)pref)->ClearReferenceState((TESBoundObject*)pNewBase);
                        ((FUN_00550c60_RefFns*)pref)->FUN_0056b020(0, 0);
                        delete porigbase;
                        porigbase = pNewBase;
                        pNewBase = 0;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            if (((TESActorBaseData*)((char*)porigbase + 0x30))->GetUsesLeveledTemplate())
                ((TESActorBaseData*)((char*)porigbase + 0x30))->SetTemplateReference((TESObjectREFR*)pref);
        }
    }
    CellRefLockLeave();
}
}  // namespace fnv_00550c60

namespace fnv_00552570 {
struct GO
{
    void* p;
    ~GO();
};
struct Flt : GO
{
    operator unsigned int();
};
struct SpObst : Flt
{
    SpObst(unsigned int*);
};
struct QueuedAttachList
{
    bool IsEmpty();
    void RemoveHead();
    unsigned int* ref_006815c0();
};
struct BSSpinLockU
{
    void Unlock();
};
struct DetailedActorPathHandler
{
    void HandleReferenceUpdate(TESObjectREFR*, bool, bool);
};
struct BSOcclusionPlane
{
    DetailedActorPathHandler* GetCullResult() const;
};
struct QueuedAttachObj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual int v10();
    bool FUN_005526b0();
    void SetEnabledFlag(int);
};
TESObjectREFR* GetReferenceFromNiAVObject(NiAVObject*);
void __cdecl UpdateSceneGraph(NiAVObject*);
extern QueuedAttachList g_011ca174;
extern RecursiveSpinLock g_011ca1a0;

// @fnv 0x00552570
void FUN_00552570()
{
    g_011ca1a0.Lock(0);
    while (!g_011ca174.IsEmpty())
    {
        SpObst attachdata(g_011ca174.ref_006815c0());
        g_011ca174.RemoveHead();
        UpdateSceneGraph((NiAVObject*)(unsigned int)attachdata);
        if ((unsigned int)attachdata && ((QueuedAttachObj*)(unsigned int)attachdata)->v10() &&
            ((QueuedAttachObj*)(unsigned int)attachdata)->FUN_005526b0())
        {
            TESObjectREFR* pref = GetReferenceFromNiAVObject((NiAVObject*)(unsigned int)attachdata);
            if (pref && ((BSOcclusionPlane*)pref)->GetCullResult())
            {
                ((BSOcclusionPlane*)pref)->GetCullResult()->HandleReferenceUpdate(pref, true, false);
                ((QueuedAttachObj*)(unsigned int)attachdata)->SetEnabledFlag(0);
            }
        }
    }
    ((BSSpinLockU*)&g_011ca1a0)->Unlock();
}
}  // namespace fnv_00552570

namespace fnv_00553bf0 {
struct NiPoint3
{
    float x, y, z;
    NiPoint3 operator-(const NiPoint3&) const;
    float Length() const;
};
struct SeqObj
{
    NiPoint3& GetName();
};
struct MobileObjectProcessArray
{
    SeqObj* GetItem(unsigned int) const;
};
struct ScriptS
{
    MobileObjectProcessArray* GetHeader();
};
struct Obj553
{
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
    virtual void* v116();
};
bool __cdecl PickObjectsInRadius(ScriptS*, NiPoint3*, int, float, void*);
BSSimpleList<Obj553*>* __fastcall FUN_00545710(int);
struct LItem_006815c0
{
    Obj553** _ref_006815c0();
};
struct LEmpty_008256d0
{
    bool _ref_008256d0();
};
struct S00553bf0
{
    bool FUN_00553bf0(ScriptS* apPick, NiPoint3* apPos, int aiArg, float afDist);
};

// @fnv 0x00553bf0
bool S00553bf0::FUN_00553bf0(ScriptS* apPick, NiPoint3* apPos, int aiArg, float afDist)
{
    bool bResult = false;
    if (apPick)
    {
        BSSimpleList<Obj553*>* pIter = FUN_00545710((int)this);
        while (pIter && !((LEmpty_008256d0*)pIter)->_ref_008256d0())
        {
            Obj553* pObj = *((LItem_006815c0*)pIter)->_ref_006815c0();
            if (pObj->v116())
            {
                if (PickObjectsInRadius(apPick, apPos, aiArg, afDist, pObj->v116()))
                {
                    NiPoint3 kPos = apPick->GetHeader()->GetItem(0)->GetName();
                    if ((kPos - *apPos).Length() < afDist)
                    {
                        bResult = true;
                        break;
                    }
                }
            }
            pIter = pIter->GetNext();
        }
    }
    return bResult;
}
}  // namespace fnv_00553bf0

namespace fnv_00555740 {
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BaseFormComponent;
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
struct FUN_00555740_shell : public TESObjectCELL
{
    void FUN_00555740(BGSLoadFormBuffer*);
};

class FormChangeMask
{
  public:
    unsigned int flags;
    FormChangeMask(unsigned int);
    bool ContainsAnyFlags(int);
};
struct BGSLoadGameBuffer
{
    char* LoadString(char*);
};
struct BGSLoadFormBuffer : public BGSLoadGameBuffer
{
    FormChangeMask GetChangeFlags();
    bool ReadFormIdentifier(void*);
    void ReadTypedData(void*, unsigned int);
};
struct TESForm
{
    virtual void LoadGame(void*);
};
struct SeenData
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void LoadGame(BGSLoadFormBuffer*);
};
struct IntSeenData : public SeenData
{
    char pad[0x20];
    IntSeenData();
};
struct FUN_0087a100 : public SeenData
{
    char pad[0x28];
    FUN_0087a100(char, char);
};
struct FUN_00555bc0_shell
{
    SeenData* FindSeenData();
};
struct FUN_00421940_s
{
    void FUN_00421940(SeenData*);
};
struct FUN_00546bf0_s
{
    void FUN_00546bf0(TESForm*);
};
struct FullNameEx
{
    void SetFullName(const char*);
};

// Loads a cell's flags, seen data, full name and owner from a save buffer according to the change flags.
// @fnv 0x00555740
void FUN_00555740_shell::FUN_00555740(BGSLoadFormBuffer* apLoadGameBuffer)
{
    ((TESForm*)this)->TESForm::LoadGame(apLoadGameBuffer);
    if (apLoadGameBuffer->GetChangeFlags().ContainsAnyFlags(2))
    {
        unsigned char ctempCellFlags = 0;
        apLoadGameBuffer->ReadTypedData(&ctempCellFlags, 1);
        field24 = (field24 & 0x9f) | (ctempCellFlags & 0x60);
        padToExtraData2[0] = ctempCellFlags & 0x9f;
    }
    if (apLoadGameBuffer->GetChangeFlags().ContainsAnyFlags(0x80000000))
    {
        SeenData* pseen = ((FUN_00555bc0_shell*)this)->FindSeenData();
        if (!pseen)
        {
            pseen = IsCellInterior() ? (SeenData*)new FUN_0087a100(0, 0) : (SeenData*)new IntSeenData();
            ((FUN_00421940_s*)((TESDataHandler*)this)->GetTESImageSpaceModifierList())->FUN_00421940(pseen);
        }
        pseen->LoadGame(apLoadGameBuffer);
    }
    if (apLoadGameBuffer->GetChangeFlags().ContainsAnyFlags(4))
    {
        char pfullname[260];
        apLoadGameBuffer->LoadString(pfullname);
        ((FullNameEx*)((char*)this + 0x18))->SetFullName(pfullname);
    }
    if (apLoadGameBuffer->GetChangeFlags().ContainsAnyFlags(8))
    {
        TESForm* powner = 0;
        apLoadGameBuffer->ReadFormIdentifier(&powner);
        ((FUN_00546bf0_s*)this)->FUN_00546bf0(powner);
    }
}
}  // namespace fnv_00555740

void __cdecl FUN_005586c0(int);
struct Proxy00557d50
{
    void FUN_00557d50();
};
struct FUN_00557da0
{
    char _00[0x18];
    void(__cdecl* f18)(int);
    int f1c;
    FUN_00557da0();
};
// Calls FUN_00557d50 on this, then sets f18 to FUN_005586c0 and f1c to 0.
// @fnv 0x00557da0
FUN_00557da0::FUN_00557da0()
{
    ((Proxy00557d50*)this)->FUN_00557d50();
    f18 = FUN_005586c0;
    f1c = 0;
}

namespace fnv_00547250 {
struct BSMultiBound;
struct BSMultiBoundNode;
struct BSMultiBoundRoom;
struct BSNiNode;
struct BSOcclusionPlane;
struct CloningProcess;
struct NiCullingProcess;
struct NiObject;
struct NiStream;
struct NiUpdateData;
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
struct LoadedCellData
{
    void* __vecDelDtor(unsigned int);
    char m_abyData00[4];
    char m_abyData04[8];
    char m_abyData0C[16];
    char m_abyData1C[16];
    char m_abyData2C[16];
    char m_abyData3C[16];
    char m_abyData4C[8];
    char m_abyData54[8];
    char m_abyData5C[8];
};
typedef char _sizecheck_LOADED_CELL_DATA[sizeof(LoadedCellData) == 100 ? 1 : -1];
struct FUN_00547250_shell : public TESObjectCELL
{
    bool CheckWaterHeight(void*, float*);
};

struct _LODMultType
{
    enum Type
    {
        kNone
    };
};
struct BSFadeNode
{
    _LODMultType::Type GetLODMultType() const;
};
struct MobileObjectCellAccess
{
    bool FUN_004518e0() const;
};
extern float DAT_01015f5c;
float __fastcall FUN_005471e0(void*);
class RecipeCraftingInfo
{
  public:
    float x, y, z;
};
struct TESRecipe
{
    RecipeCraftingInfo* GetData();
};
class PathingLocation
{
  public:
    float x, y, z;
};
struct PathingRequest
{
    PathingLocation* GetOrigin();
};
struct Model
{
    NiNode* GetObject3D();
};
struct BSFaceGenNiNode
{
    void* GetAnimationData();
};
struct WaterRefObj;
struct WaterRefNode_00547250
{
    WaterRefObj** _ref_006815c0();
};

struct AV3D
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual NiNode* IsSceneNode();
};
struct AVChild
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual struct MBNode* IsMultiBoundNode();
};
struct MBShape
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
    virtual int GetType();
};
struct MBNode
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
    virtual bool WithinBounds(NiPoint3*);
};
struct WaterRefObj
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
    virtual AV3D* Get3D();
    virtual void v1d4();
    virtual void GetBoundsMaximum(NiPoint3*);
    virtual void GetBoundsMinimum(NiPoint3*);
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual NiPoint3* GetPos();
};
// @fnv 0x00547250
bool FUN_00547250_shell::CheckWaterHeight(void* apPos, float* afHeight)
{
    bool bhitWater = false;
    if (IsCellInterior() && !((MobileObjectCellAccess*)this)->FUN_004518e0())
    {
        *afHeight = DAT_01015f5c;
        return false;
    }
    *afHeight = FUN_005471e0(this);
    NiPoint3 pt = *(const NiPoint3*)apPos;
    LoadedCellData* ploadedData = (LoadedCellData*)((BSFadeNode*)this)->GetLODMultType();
    if (ploadedData)
    {
        BSSimpleList<TESObjectREFR*>* pCurrentElementNext = (BSSimpleList<TESObjectREFR*>*)ploadedData->m_abyData5C;
        while (pCurrentElementNext && *reinterpret_cast<WaterRefNode_00547250*>(pCurrentElementNext)->_ref_006815c0())
        {
            WaterRefObj* pwaterRef = *reinterpret_cast<WaterRefNode_00547250*>(pCurrentElementNext)->_ref_006815c0();
            NiPoint3 max;
            NiPoint3 min;
            pwaterRef->GetBoundsMaximum(&min);
            pwaterRef->GetBoundsMinimum(&max);
            NiPoint3 angle = *(NiPoint3*)((TESRecipe*)pwaterRef)->GetData();
            MBNode* pnode = ((AVChild*)pwaterRef->Get3D()->IsSceneNode()->FUN_0043b4a0(0))->IsMultiBoundNode();
            if (pnode)
            {
                MBShape* pshape = (MBShape*)((Model*)((BSFaceGenNiNode*)pnode)->GetAnimationData())->GetObject3D();
                if (pshape->GetType() == 1)
                    pt.z = ((PathingRequest*)pshape)->GetOrigin()->z;
                if (pshape->GetType() == 2)
                    pt.z = ((PathingRequest*)pshape)->GetOrigin()->z;
                if (pnode->WithinBounds(&pt))
                {
                    float fheight = pwaterRef->GetPos()->z;
                    if (fheight > *afHeight)
                        *afHeight = fheight;
                    bhitWater = true;
                }
            }
            pCurrentElementNext = pCurrentElementNext->GetNext();
        }
    }
    return bhitWater;
}
}  // namespace fnv_00547250

namespace fnv_00550340 {
struct FormS;
struct TESForm
{
    TESFile* GetFile(int);
    void Revert(unsigned int);
};
struct FileH
{
    bool IsMasterFile();
    bool SetOffset(unsigned int);
};
struct FUN_008256d0_list
{
    bool FUN_008256d0();
};
struct FUN_00464df0_shell
{
    FUN_008256d0_list* FUN_00464df0();
};
struct FUN_004734d0_shell
{
    bool FUN_004734d0(TESForm*);
};
struct FUN_00551420_shell
{
    bool FUN_00551420();
};
struct S00551440
{
    void FUN_00551440(bool);
};
struct FUN_00550500_t
{
    bool FUN_00550500(TESFile*);
};
struct S004534f0
{
    void FUN_004534f0(bool);
};
struct TESSaveLoadGame
{
    bool GetLoading();
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
int __fastcall GetByteAtOffset38(void*);
namespace cellfn {
void* __fastcall FUN_0054de40(TESObjectCELL*);
}
int __fastcall GetSourceFileCount(FormS*);
struct TESFileTS
{
    TESFile* GetParentTESFile();
};
struct CellVT
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
};

struct FUN_00550340_t : TESObjectCELL
{
    bool FUN_00550340();
};

// @fnv 0x00550340
bool FUN_00550340_t::FUN_00550340()
{
    bool brestoreLoading;
    unsigned int ifilecount;
    bool bretval;

    if (((FUN_00551420_shell*)this)->FUN_00551420())
        return true;
    bretval = true;
    ifilecount = GetSourceFileCount((FormS*)this);
    for (unsigned int i = 0; i < ifilecount; i++)
    {
        TESFile* pfile;
        pfile = ((TESFileTS*)((TESForm*)this)->GetFile(i))->GetParentTESFile();
        if (pfile && ((FileH*)pfile)->IsMasterFile())
        {
            unsigned int ioffset;
            bool bload;
            bload = false;
            ioffset = (unsigned int)(((FUN_00464df0_shell*)pfile)->FUN_00464df0()->FUN_008256d0()
                                         ? cellfn::FUN_0054de40((TESObjectCELL*)this)
                                         : 0);
            if (ioffset)
            {
                if (((FileH*)pfile)->SetOffset(ioffset))
                    bload = true;
            }
            else
            {
                if (((FUN_004734d0_shell*)pfile)->FUN_004734d0((TESForm*)this))
                    bload = true;
            }
            if (bload)
            {
                if (!((FUN_00550500_t*)this)->FUN_00550500(pfile))
                    bretval = false;
            }
            else
            {
                bretval = false;
            }
        }
        else
        {
            if (GetByteAtOffset38((void*)this) <= 2 && !IsCellInterior())
                bretval = false;
        }
    }
    if (bretval)
        ((S00551440*)this)->FUN_00551440(true);
    else
        return bretval;
    brestoreLoading = g_TESSaveLoadGame->GetLoading();
    ((S004534f0*)g_TESSaveLoadGame)->FUN_004534f0(!brestoreLoading);
    ((CellVT*)this)->v22();
    ((S004534f0*)g_TESSaveLoadGame)->FUN_004534f0(brestoreLoading);
    return bretval;
}
}  // namespace fnv_00550340

namespace fnv_00558ba0 {
struct BGSPerkEntry
{
    virtual ~BGSPerkEntry();
    int GetInnerValue();
    void FUN_00558c60(int);
};
struct FUN_00558ba0_shell : public TESObjectCELL
{
    BSSimpleList<BGSPerkEntry*>* FUN_009604f0();
    void FUN_00558ba0(int mask);
};
extern TESObjectCELL* _g_thePlayer;
// @fnv 0x00558ba0
void FUN_00558ba0_shell::FUN_00558ba0(int mask)
{
    BGSPerkEntry* item3 = 0;
    BSSimpleList<BGSPerkEntry*>* list = this->FUN_009604f0();
    while (list && list->GetItem())
    {
        item3 = list->GetItem();
        if (item3->GetInnerValue() == mask)
            item3->FUN_00558c60(0);
        list = list->GetNext();
    }
    if (reinterpret_cast<BGSPerkEntry*>(_g_thePlayer)->GetInnerValue() == mask)
        reinterpret_cast<BGSPerkEntry*>(_g_thePlayer)->FUN_00558c60(0);
}
}  // namespace fnv_00558ba0

namespace fnv_0049f210 {
struct NiPoint3
{
    float x;
    float y;
    float z;
};
struct S5460
{
    unsigned int FUN_00978bc0();
};
struct FUN_0049f8f0_class
{
    void ConstructEntries(int, unsigned int);
};
struct FUN_0049f210_class
{
    int pad0;
    int pItems;
    unsigned int FUN_00978bc0();
    void ConstructEntries(int, unsigned int);
    unsigned int AddItem(const NiPoint3& kPos);
};
// @fnv 0x0049f210
unsigned int FUN_0049f210_class::AddItem(const NiPoint3& kPos)
{
    unsigned int uiIndex = FUN_00978bc0();
    ConstructEntries(pItems + uiIndex * 12, 1);
    *(NiPoint3*)(pItems + uiIndex * 12) = kPos;
    return uiIndex;
}
}  // namespace fnv_0049f210

extern int DAT_00ffffff;
int __cdecl GetCellCoordKey(int, int);

struct FUN_005441b0_S
{
    bool IsCellInterior() const;
    int GetCellGridX();
    int GetCellGridY();
    unsigned int FUN_0084e3a0();
    unsigned int FUN_005441b0();
};

// @fnv 0x005441b0
unsigned int FUN_005441b0_S::FUN_005441b0()
{
    unsigned int iblockkey = 0;
    if (!IsCellInterior())
        iblockkey = GetCellCoordKey(GetCellGridX(), GetCellGridY());
    else
        iblockkey = (FUN_0084e3a0() & (unsigned int)&DAT_00ffffff) % 10;
    return iblockkey;
}

int __cdecl FUN_005442c0(int, int);
extern int DAT_00ffffff;
struct ref_0084e3a0
{
    unsigned int _ref_0084e3a0();
};
struct FUN_00544210_shell
{
    unsigned int FUN_00544210();
};
// @fnv 0x00544210
unsigned int FUN_00544210_shell::FUN_00544210()
{
    unsigned int iblockkey = 0;
    if (!((TESObjectCELL*)this)->IsCellInterior())
        iblockkey = FUN_005442c0(((TESObjectCELL*)this)->GetCellGridX(), ((TESObjectCELL*)this)->GetCellGridY());
    else
    {
        iblockkey = (((ref_0084e3a0*)this)->_ref_0084e3a0() & (unsigned int)&DAT_00ffffff) % 100;
        iblockkey = iblockkey / 10;
    }
    return iblockkey;
}

struct FUN_00586210_shell
{
    bool HasFlag2();
};
struct DoorCellWS
{
    TESWorldSpace* GetParentWorldSpace();
};
struct FUN_00544520_shell
{
    bool FUN_00544520();
};
// @fnv 0x00544520
bool FUN_00544520_shell::FUN_00544520()
{
    bool result = false;
    if ((reinterpret_cast<TESObjectCELL*>(this)->field24 & 4) != 0)
        result = true;
    if (reinterpret_cast<TESObjectCELL*>(this)->IsCellInterior())
        result = !result;
    if (result)
        return true;
    TESWorldSpace* space = reinterpret_cast<DoorCellWS*>(this)->GetParentWorldSpace();
    if (space)
        return reinterpret_cast<FUN_00586210_shell*>(space)->HasFlag2();
    return false;
}

struct FUN_00544c90_shell : TESObjectCELL
{
    void SetExteriorCellCoordinates(int a, int b);
};
// If the cell has no exterior data, returns; otherwise stores a and b into the exterior data's x and y fields.
// @fnv 0x00544c90
void FUN_00544c90_shell::SetExteriorCellCoordinates(int aiX, int aiY)
{
    if (IsCellInterior())
        return;
    ExteriorCellData* data = GetExteriorData();
    if (data)
    {
        data->x = aiX;
        data->y = aiY;
    }
}

struct MapH
{
    bool RemoveAt(unsigned int);
};
struct RefList
{
    void FUN_00905330(unsigned int&);
};
struct FUN_00545360_StandIn
{
    void FUN_00545360(unsigned int key);
};
// @fnv 0x00545360
void FUN_00545360_StandIn::FUN_00545360(unsigned int key)
{
    if (*(MapH**)((char*)this + 0xc4))
    {
        ((MapH*)((char*)*(MapH**)((char*)this + 0xc4) + 0xc))->RemoveAt(key);
        ((RefList*)((char*)*(MapH**)((char*)this + 0xc4) + 4))->FUN_00905330(key);
    }
}

namespace fnv_00546970 {
struct FUN_0041b8d0_shell
{
    void SetHavokWorld(int);
};
struct FUN_0041b9a0_shell
{
    void* GetExtraHandleCount();
};
struct FUN_004512a0_shell
{
    void SetState(unsigned char);
};
struct FUN_00546a00Class
{
    void ClearFieldA4();
};
struct FUN_00546a20Class
{
    void ClearField();
};
struct FUN_006242f0_shell
{
    void NotifyListener(void*);
};
struct ScriptLocals
{
    void* GetLocalData();
};
extern void* DAT_011ca088;

struct FUN_00546970Class : FUN_004512a0_shell, FUN_00546a00Class, FUN_00546a20Class
{
    void ClearCellData();
    void FUN_00546970();
};

// @fnv 0x00546970
void FUN_00546970Class::FUN_00546970()
{
    void* pObject = ((FUN_0041b9a0_shell*)((char*)this + 0x28))->GetExtraHandleCount();
    if (pObject && DAT_011ca088)
        ((FUN_006242f0_shell*)DAT_011ca088)->NotifyListener(((ScriptLocals*)pObject)->GetLocalData());
    SetState(1);
    ClearCellData();
    ((FUN_0041b8d0_shell*)((char*)this + 0x28))->SetHavokWorld(0);
    ((FUN_00546a00Class*)((char*)this))->ClearFieldA4();
    ((FUN_00546a20Class*)((char*)this))->ClearField();
    SetState(0);
    ((unsigned char*)this)[0xd1] = 0;
}
}  // namespace fnv_00546970

struct TESClimate;
struct BaseExtraList2
{
    int FUN_0041c260();
};
struct FUN_00585fe0_shell
{
    TESClimate* FUN_00585fe0();
};
struct FUN_00454b10_shell
{
    bool FUN_00454b10();
};
struct FUN_005475b0_shell
{
    TESClimate* FUN_005475b0();
};

// @fnv 0x005475b0
TESClimate* FUN_005475b0_shell::FUN_005475b0()
{
    if (reinterpret_cast<TESObjectCELL*>(this)->IsCellInterior())
    {
        if (!reinterpret_cast<FUN_00454b10_shell*>(this)->FUN_00454b10())
            return 0;
        else
            return reinterpret_cast<TESClimate*>(
                reinterpret_cast<BaseExtraList2*>(
                    reinterpret_cast<TESDataHandler*>(this)->GetTESImageSpaceModifierList())
                    ->FUN_0041c260());
    }
    else
    {
        return reinterpret_cast<FUN_00585fe0_shell*>(reinterpret_cast<TESObjectCELL*>(this)->GetParentWorldSpace())
            ->FUN_00585fe0();
    }
}

namespace fnv_0054acf0 {
struct GO
{
    int a;
    GO(int);
    ~GO();
};
struct FUN_0054acf0 : GO
{
    GO b;
    unsigned char c;
    FUN_0054acf0();
};
// Initializes the base GO with 0, the member GO b with 0, and sets c to 1.
// @fnv 0x0054acf0
FUN_0054acf0::FUN_0054acf0() : GO(0), b(0)
{
    c = 1;
}
}  // namespace fnv_0054acf0

extern unsigned int _data_011c16bc;
struct SpObst
{
    unsigned int a;
    SpObst(unsigned int*);
    ~SpObst();
};
struct FUN_0054adb0 : SpObst
{
    SpObst b;
    unsigned char c;
    FUN_0054adb0(unsigned int*);
};
// Constructs the object from p: initialises the SpObst base and member b from p and p+1, and sets c from byte 8 of p.
// @fnv 0x0054adb0
FUN_0054adb0::FUN_0054adb0(unsigned int* auiData) : SpObst(auiData), b(auiData + 1)
{
    c = ((unsigned char*)auiData)[8];
}

float __cdecl FUN_004019b0(float);
// @fnv 0x0054fb20
float FUN_0054fb20(float x1, float y1, float x2, float y2)
{
    float a = x1 - x2;
    float b = y1 - y2;
    a = a * a;
    b = b * b;
    return FUN_004019b0(a + b);
}

namespace fnv_00550200 {
struct NiPoint3
{
    float x;
    float y;
    float z;
};
int __cdecl TruncateFloatToInt(float value);

struct FUN_00550200 : TESObjectCELL
{
    bool IsPointInCell(const NiPoint3& point);
};

// @fnv 0x00550200
bool FUN_00550200::IsPointInCell(const NiPoint3& point)
{
    if (IsCellInterior())
        return false;
    int iX = TruncateFloatToInt(point.x);
    int iY = TruncateFloatToInt(point.y);
    if ((iX >> 12) != GetCellGridX())
        return false;
    if ((iY >> 12) != GetCellGridY())
        return false;
    return true;
}
}  // namespace fnv_00550200

namespace fnv_00555570 {
struct TESForm
{
    void Revert(unsigned int flags);
};

struct TESSaveLoadGame
{
    bool FUN_0055f5b0();
};

extern TESSaveLoadGame* g_TESSaveLoadGame;

struct FUN_00555be0_stub
{
    void FUN_00555be0();
};

struct FUN_00555570_cell
{
    char pad[0x25];
    unsigned char field25;
    void FUN_00555be0();
    void SetDetachTime(unsigned int a, bool b);
    void FUN_00555570(unsigned int flags);
};

// @fnv 0x00555570
void FUN_00555570_cell::FUN_00555570(unsigned int flags)
{
    reinterpret_cast<TESForm*>(this)->Revert(flags);
    if (g_TESSaveLoadGame->FUN_0055f5b0())
    {
        field25 = 0;
    }
    if (flags & 0x80000000)
    {
        FUN_00555be0();
    }
    if (flags & 0x40000000)
    {
        SetDetachTime(0, false);
    }
}
}  // namespace fnv_00555570

struct FUN_00557ae0_obj
{
    void FUN_00557ae0();
};
struct FUN_00453980_shell
{
    unsigned int GetGlobalInt();
};
struct FUN_00459470_Class
{
    FUN_00557ae0_obj* FUN_00459470(int);
};
extern int g_TES;
struct FUN_00557be0_shell
{
    void FUN_00557be0();
};

// @fnv 0x00557be0
void FUN_00557be0_shell::FUN_00557be0()
{
    for (unsigned int i = 0; i < ((FUN_00453980_shell*)g_TES)->GetGlobalInt(); i++)
    {
        FUN_00557ae0_obj* obj = ((FUN_00459470_Class*)g_TES)->FUN_00459470(i);
        if (obj)
            obj->FUN_00557ae0();
    }
}

struct FUN_00557d50
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
    unsigned int e;
    unsigned int f;
    FUN_00557d50();
};

// @fnv 0x00557d50
FUN_00557d50::FUN_00557d50()
{
    a = 0x4b0;
    b = 0xc3500;
    c = 0x64;
    d = 0xf;
    e = 0xffffffff;
    f = 8;
}

extern int DAT_0102f358;
void* __cdecl _NiMalloc(unsigned int);
void* __cdecl memset(void*, int, unsigned int);

struct FUN_00558eb0
{
    int* pvt;
    unsigned int size;
    void* pMap;
    unsigned int mSize;
    FUN_00558eb0(unsigned int iSize);
};

// Stores the size, allocates size*4 zeroed bytes for pMap, and sets mSize to 0.
// @fnv 0x00558eb0
FUN_00558eb0::FUN_00558eb0(unsigned int iSize)
{
    pvt = &DAT_0102f358;
    size = iSize;
    mSize = 0;
    unsigned int uiByteCount = size << 2;
    pMap = _NiMalloc(uiByteCount);
    memset(pMap, 0, size << 2);
}

extern int DAT_0102f398;
struct FUN_005590b0_s
{
    void* m_vtbl;
    unsigned int m_uiItemCount;
    void* m_data;
    unsigned int m_iElementCount;
    void* InitArray(unsigned int aCount);
};

void* __cdecl _NiMalloc(unsigned int aSize);
void* __cdecl memset(void* aDest, int aVal, unsigned int aSize);

// Sets the vtable, stores aCount and zeroes a newly allocated aCount*4-byte buffer.
// @fnv 0x005590b0
void* FUN_005590b0_s::InitArray(unsigned int aCount)
{
    m_vtbl = &DAT_0102f398;
    m_uiItemCount = aCount;
    m_iElementCount = 0;
    unsigned int aSize = m_uiItemCount * 4;
    m_data = _NiMalloc(aSize);
    memset(m_data, 0, m_uiItemCount * 4);
    return this;
}

struct FUN_00544340_Class
{
    void FUN_00544340(bool set);
};

// Sets or clears bit 0x20 in the byte at offset 0x24, then calls the virtual function at vtable offset 0x48 with argument 2.
// @fnv 0x00544340
void FUN_00544340_Class::FUN_00544340(bool set)
{
    if (set)
        *(unsigned char*)((char*)this + 0x24) |= 0x20;
    else
        *(unsigned char*)((char*)this + 0x24) &= ~0x20;
    (*(void(__thiscall**)(void*, int))(*(int*)this + 0x48))(this, 2);
}

struct FUN_00544440_Class
{
    void FUN_00544440(bool set);
};

// Sets or clears bit 0 of the byte at offset 0x25, then calls the virtual function at vtable offset 0x48 with argument 2.
// @fnv 0x00544440
void FUN_00544440_Class::FUN_00544440(bool set)
{
    if (set)
        *(unsigned char*)((char*)this + 0x25) |= 1;
    else
        *(unsigned char*)((char*)this + 0x25) &= ~1;
    (*(void(__thiscall**)(void*, int))(*(unsigned int*)this + 0x48))(this, 2);
}

extern void __cdecl _Deallocate(void* pointer);

struct FUN_005417e0_class
{
    void FUN_00541810();
    void* FUN_005417e0(unsigned int flags);
};

// Calls FUN_00541810, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x005417e0
void* FUN_005417e0_class::FUN_005417e0(unsigned int flags)
{
    FUN_00541810();

    if (flags & 1)
    {
        _Deallocate(this);
    }

    return this;
}

struct FUN_00541a30_StandIn
{
    void FUN_00541a60();
    void* FUN_00541a30(unsigned int flags);
};

void __cdecl _Deallocate(void* pointer);

// Calls FUN_00541a60, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00541a30
void* FUN_00541a30_StandIn::FUN_00541a30(unsigned int flags)
{
    FUN_00541a60();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_00543df0 {
struct FormRecordHeader
{
    unsigned int form;
    unsigned int pad0004;
    unsigned int flags;
    unsigned int iFormID;
};

unsigned int kGroupFormType;

struct DoorCellStandIn
{
    TESWorldSpace* GetParentWorldSpace();
};

struct FUN_004854e0_shell
{
    bool IsGroupFormOfType(FormRecordHeader* form, bool allowParentGroups, bool currentOnly);
};

struct FUN_00485b60
{
    bool FUN_00485be0(unsigned int flags);
};

struct CellH
{
    bool IsCellPersistent();
};

struct FUN_005441b0_S
{
    unsigned int FUN_005441b0();
};

struct FUN_00544210_shell
{
    unsigned int FUN_00544210();
};

struct WorldSpaceVirtual
{
    virtual void f000()
    {}
    virtual void f001()
    {}
    virtual void f002()
    {}
    virtual void f003()
    {}
    virtual void f004()
    {}
    virtual void f005()
    {}
    virtual void f006()
    {}
    virtual void f007()
    {}
    virtual void f008()
    {}
    virtual void f009()
    {}
    virtual void f010()
    {}
    virtual void f011()
    {}
    virtual void f012()
    {}
    virtual void f013()
    {}
    virtual void f014()
    {}
    virtual void f015()
    {}
    virtual void f016()
    {}
    virtual void f017()
    {}
    virtual void f018()
    {}
    virtual void f019()
    {}
    virtual void f020()
    {}
    virtual void f021()
    {}
    virtual void f022()
    {}
    virtual void f023()
    {}
    virtual void f024()
    {}
    virtual void f025()
    {}
    virtual void f026()
    {}
    virtual void f027()
    {}
    virtual void f028()
    {}
    virtual void f029()
    {}
    virtual void f030()
    {}
    virtual void f031()
    {}
    virtual void f032()
    {}
    virtual void f033()
    {}
    virtual void f034()
    {}
    virtual void f035()
    {}
    virtual void f036()
    {}
    virtual void f037()
    {}
    virtual void f038()
    {}
    virtual void f039()
    {}
    virtual void f040()
    {}
    virtual void f041()
    {}
    virtual void f042()
    {}
    virtual void f043()
    {}
    virtual void f044()
    {}
    virtual void f045()
    {}
    virtual void f046()
    {}
    virtual void f047()
    {}
    virtual void f048()
    {}
    virtual void f049()
    {}
    virtual void f050()
    {}
    virtual void f051()
    {}
    virtual void f052()
    {}
    virtual void f053()
    {}
    virtual void f054()
    {}
    virtual void f055()
    {}
    virtual void f056()
    {}
    virtual void f057()
    {}
    virtual void f058()
    {}
    virtual void f059()
    {}
    virtual void f060()
    {}
    virtual void f061()
    {}
    virtual void f062()
    {}
    virtual void f063()
    {}
    virtual void f064()
    {}
    virtual void f065()
    {}
    virtual void f066()
    {}
    virtual void f067()
    {}

    virtual bool FUN(FormRecordHeader* form, bool allowParentGroups, bool currentOnly)
    {
        return false;
    }
};

struct FUN_00543df0_StandIn
{
    bool IsGroupFormAllowed(FormRecordHeader* apGroupFORM, bool abAllowParentGroups, bool abCurrentOnly);
};

// @fnv 0x00543df0
bool FUN_00543df0_StandIn::IsGroupFormAllowed(FormRecordHeader* apGroupFORM, bool abAllowParentGroups, bool abCurrentOnly)
{
    bool bretval = false;
    TESWorldSpace* pparentworld;

    if (apGroupFORM && apGroupFORM->form == kGroupFormType)
    {
        pparentworld = reinterpret_cast<DoorCellStandIn*>(this)->GetParentWorldSpace();

        switch (apGroupFORM->iFormID)
        {
        case 0:
            if (abAllowParentGroups)
            {
                if (reinterpret_cast<TESObjectCELL*>(this)->IsCellInterior())
                    bretval = reinterpret_cast<FUN_004854e0_shell*>(this)->IsGroupFormOfType(
                        apGroupFORM, abAllowParentGroups, abCurrentOnly);
                else
                    bretval = reinterpret_cast<WorldSpaceVirtual*>(pparentworld)
                                  ->FUN(apGroupFORM, abAllowParentGroups, abCurrentOnly);
            }
            break;

        case 1:
            if (!reinterpret_cast<TESObjectCELL*>(this)->IsCellInterior() &&
                reinterpret_cast<FUN_00485b60*>(pparentworld)->FUN_00485be0(apGroupFORM->flags) &&
                (abAllowParentGroups || reinterpret_cast<CellH*>(this)->IsCellPersistent()))
                bretval = true;
            break;

        case 2:
        case 4:
            if (!reinterpret_cast<CellH*>(this)->IsCellPersistent() && abAllowParentGroups &&
                apGroupFORM->flags == reinterpret_cast<FUN_005441b0_S*>(this)->FUN_005441b0())
                bretval = true;
            break;

        case 3:
        case 5:
            if (!reinterpret_cast<CellH*>(this)->IsCellPersistent() &&
                apGroupFORM->flags == reinterpret_cast<FUN_00544210_shell*>(this)->FUN_00544210())
                bretval = true;
            break;
        }
    }

    return bretval;
}
}  // namespace fnv_00543df0

namespace fnv_00543f50 {
struct FormRecordHeader
{
    unsigned int form;
    unsigned int length;
    unsigned int flags;
    unsigned int iFormID;
    unsigned int m_uiVersionControlInfo;
};

struct TESFileGroup
{
    void* GroupData;
    unsigned int unknown04;
    unsigned int flags;
    unsigned int type;
};

unsigned int kGroupFormType;
extern const char str_011872b4[];
extern const char str_01187314[];

struct FUN_005441b0_S
{
    unsigned int FUN_005441b0();
};

struct FUN_00544210_shell
{
    unsigned int FUN_00544210();
};

struct CellH
{
    bool IsCellPersistent();
};

struct DoorCellAccess
{
    TESWorldSpace* GetParentWorldSpace();
};

struct RefAccess
{
    unsigned int _ref_0084e3a0();
};

struct CellStandIn : public TESObjectCELL
{
    void BuildParentGroupForm(FormRecordHeader* apOutGroupFORM, TESFileGroup* apParentGroup);
};

// Fills apOutGroupFORM with a group form type, an ID and a flags value chosen from this cell's state and the parent group's type and flags.
// @fnv 0x00543f50
void CellStandIn::BuildParentGroupForm(FormRecordHeader* apOutGroupFORM, TESFileGroup* apParentGroup)
{
    if (apOutGroupFORM != 0)
    {
        apOutGroupFORM->form = 0;

        if (!IsCellInterior())
        {
            if (apParentGroup != 0)
            {
                switch (apParentGroup->type)
                {
                case 0:
                    if (apParentGroup->flags == *(const unsigned int*)str_01187314)
                    {
                        apOutGroupFORM->form = kGroupFormType;
                        apOutGroupFORM->iFormID = 1;
                        apOutGroupFORM->flags =
                            reinterpret_cast<RefAccess*>(reinterpret_cast<DoorCellAccess*>(this)->GetParentWorldSpace())
                                ->_ref_0084e3a0();
                        apOutGroupFORM->length = 0;
                        apOutGroupFORM->m_uiVersionControlInfo = 0;
                    }
                    break;

                case 1:
                    if (apParentGroup->flags ==
                        reinterpret_cast<RefAccess*>(reinterpret_cast<DoorCellAccess*>(this)->GetParentWorldSpace())
                            ->_ref_0084e3a0())
                    {
                        if (!reinterpret_cast<CellH*>(this)->IsCellPersistent())
                        {
                            apOutGroupFORM->form = kGroupFormType;
                            apOutGroupFORM->iFormID = 4;
                            apOutGroupFORM->flags = reinterpret_cast<FUN_005441b0_S*>(this)->FUN_005441b0();
                            apOutGroupFORM->length = 0;
                            apOutGroupFORM->m_uiVersionControlInfo = 0;
                        }
                    }
                    break;

                case 4:
                    if (apParentGroup->flags == reinterpret_cast<FUN_005441b0_S*>(this)->FUN_005441b0())
                    {
                        if (!reinterpret_cast<CellH*>(this)->IsCellPersistent())
                        {
                            apOutGroupFORM->form = kGroupFormType;
                            apOutGroupFORM->iFormID = 5;
                            apOutGroupFORM->flags = reinterpret_cast<FUN_00544210_shell*>(this)->FUN_00544210();
                            apOutGroupFORM->length = 0;
                            apOutGroupFORM->m_uiVersionControlInfo = 0;
                        }
                    }
                    break;
                }
            }
        }
        else
        {
            if (apParentGroup == 0)
            {
                apOutGroupFORM->form = kGroupFormType;
                apOutGroupFORM->iFormID = 0;
                apOutGroupFORM->flags = *(const unsigned int*)str_011872b4;
                apOutGroupFORM->length = 0;
                apOutGroupFORM->m_uiVersionControlInfo = 0;
            }
            else
            {
                switch (apParentGroup->type)
                {
                case 0:
                    if (apParentGroup->flags == *(const unsigned int*)str_011872b4)
                    {
                        apOutGroupFORM->form = kGroupFormType;
                        apOutGroupFORM->iFormID = 2;
                        apOutGroupFORM->flags = reinterpret_cast<FUN_005441b0_S*>(this)->FUN_005441b0();
                        apOutGroupFORM->length = 0;
                        apOutGroupFORM->m_uiVersionControlInfo = 0;
                    }
                    break;

                case 2:
                    if (apParentGroup->flags == reinterpret_cast<FUN_005441b0_S*>(this)->FUN_005441b0())
                    {
                        apOutGroupFORM->form = kGroupFormType;
                        apOutGroupFORM->iFormID = 3;
                        apOutGroupFORM->flags = reinterpret_cast<FUN_00544210_shell*>(this)->FUN_00544210();
                        apOutGroupFORM->length = 0;
                        apOutGroupFORM->m_uiVersionControlInfo = 0;
                    }
                    break;
                }
            }
        }
    }
}
}  // namespace fnv_00543f50

struct FUN_005451d0_StandIn
{
    void* FUN_005451d0(unsigned int flags);
    void FUN_00545200();
};

void _Deallocate(void* pointer);

// Calls FUN_00545200, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x005451d0
void* FUN_005451d0_StandIn::FUN_005451d0(unsigned int flags)
{
    FUN_00545200();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_00545200 {
struct GO
{
    void* pData;
    ~GO();
};

struct ListX
{
    void* pData;
    unsigned int count;
    ~ListX();
};

struct FUN_00558f20
{
    void* pData;
    unsigned int field1;
    unsigned int field2;
    unsigned int field3;
    ~FUN_00558f20();
};

struct FUN_00559020
{
    void* pData;
    unsigned int field1;
    unsigned int field2;
    unsigned int field3;
    ~FUN_00559020();
};

struct FUN_005591d0
{
    void* pData;
    unsigned int field1;
    unsigned int field2;
    unsigned int field3;
    ~FUN_005591d0();
};

struct FUN_00545200 : public GO
{
    ListX list04;
    FUN_00558f20 member0c;
    FUN_00559020 member1c;
    FUN_00558f20 member2c;
    FUN_005591d0 member3c;
    ListX list4c;
    ListX list54;
    ListX list5c;

    ~FUN_00545200();
};

// Destructor for the object; the body is empty, so member destructors run implicitly.
// @fnv 0x00545200
FUN_00545200::~FUN_00545200()
{}
}  // namespace fnv_00545200

namespace fnv_00545560 {
struct G2
{
    void AddHead(int*);
};

struct FUN_00545560Class
{
    unsigned char pad[0xc4];
    void* p;

    void FUN_00545560(int);
};

// If p is set, calls AddHead on the G2 object at p+0x4c with the address of arg.
// @fnv 0x00545560
void FUN_00545560Class::FUN_00545560(int iValue)
{
    if (p)
        reinterpret_cast<G2*>(reinterpret_cast<unsigned char*>(p) + 0x4c)->AddHead(&iValue);
}
}  // namespace fnv_00545560

namespace fnv_00545590 {
struct RefList
{
    void FUN_00905330(unsigned int& value);
};

struct FUN_00545590_Owner
{
    unsigned char padding[0x4c];
    RefList list;
};

struct FUN_00545590_Class
{
    unsigned char padding[0xc4];
    FUN_00545590_Owner* owner;

    void FUN_00545590(unsigned int* value);
};

// If owner is set, forwards value to the owner's list via FUN_00905330.
// @fnv 0x00545590
void FUN_00545590_Class::FUN_00545590(unsigned int* value)
{
    if (owner)
        owner->list.FUN_00905330(reinterpret_cast<unsigned int&>(value));
}
}  // namespace fnv_00545590

namespace fnv_005456b0 {
struct G2
{
    void AddHead(int*);
};

struct FUN_005456b0StandIn
{
    char pad_0000[0xC4];
    G2* pG2;

    void AddValueToHead(int);
};

// If pG2 is non-null, calls AddHead on the G2 at offset 0x5C of pG2, passing the address of value.
// @fnv 0x005456b0
void FUN_005456b0StandIn::AddValueToHead(int value)
{
    if (pG2 != 0)
        reinterpret_cast<G2*>(reinterpret_cast<char*>(pG2) + 0x5C)->AddHead(&value);
}
}  // namespace fnv_005456b0

class FUN_00905330ContNode
{
  public:
    void FUN_00905330(int*);
};

class FUN_00905330RefList
{
  public:
    unsigned char padding[0x5c];
    FUN_00905330ContNode node;
};

class FUN_005456e0StandIn
{
  public:
    void FUN_005456e0(int);

  private:
    unsigned char padding[0xc4];
    FUN_00905330RefList* pRefList;
};

// If pRefList is set, forwards the address of value to the node's FUN_00905330 method.
// @fnv 0x005456e0
void FUN_005456e0StandIn::FUN_005456e0(int value)
{
    if (pRefList)
        pRefList->node.FUN_00905330(&value);
}

namespace fnv_00545c10 {
class GO
{
  public:
    operator unsigned int() const;
    void operator=(void* value);
};

class NiAdditionalGeometryData
{
  public:
    static void* __cdecl GetShadowSceneNodeForIndex(int index);
};

struct FUN_00454b30_class
{
    unsigned int* FUN_00454b30();
};

struct FUN_00b5ddf0_class
{
    void FUN_00b5ddf0(int value);
};

struct FUN_00583270_class
{
    void FUN_00583270();
};

struct FUN_00545c10_class
{
    char padToGO[0xD4];
    GO go;

    void ClearAdditionalGeometryData();
};

// @fnv 0x00545c10
void FUN_00545c10_class::ClearAdditionalGeometryData()
{
    if (go.operator unsigned int())
    {
        if (((TESObjectCELL*)this)->IsCellInterior())
        {
            if (reinterpret_cast<unsigned int>(
                    reinterpret_cast<FUN_00454b30_class*>(NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0))
                        ->FUN_00454b30()) == go.operator unsigned int())
            {
                reinterpret_cast<FUN_00b5ddf0_class*>(NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0))
                    ->FUN_00b5ddf0(0);
            }
        }

        go.operator=(0);

        if (((TESObjectCELL*)this)->GetParentWorldSpace())
        {
            reinterpret_cast<FUN_00583270_class*>(((TESObjectCELL*)this)->GetParentWorldSpace())->FUN_00583270();
        }
    }
}
}  // namespace fnv_00545c10

namespace fnv_00546b10 {
class BGSSaveLoadGame
{
  public:
    bool FUN_0042ce10();
};

extern BGSSaveLoadGame* g_BGSSaveLoadGame;

struct FUN_00421850_shell
{
    void FUN_00421850(BSExtraData* value);
};

struct FUN_00546b10_virtuals
{
    virtual void f0()
    {}
    virtual void f1()
    {}
    virtual void f2()
    {}
    virtual void f3()
    {}
    virtual void f4()
    {}
    virtual void f5()
    {}
    virtual void f6()
    {}
    virtual void f7()
    {}
    virtual void f8()
    {}
    virtual void f9()
    {}
    virtual void f10()
    {}
    virtual void f11()
    {}
    virtual void f12()
    {}
    virtual void f13()
    {}
    virtual void f14()
    {}
    virtual void f15()
    {}
    virtual void f16()
    {}
    virtual void f17()
    {}
    virtual void __thiscall f18(unsigned int value);
    virtual void __thiscall f19(unsigned int value);
};

struct FUN_00546b10_class : public TESObjectCELL
{
    void UpdateCellExtraData(BSExtraData* value, bool flag);
};

// @fnv 0x00546b10
void FUN_00546b10_class::UpdateCellExtraData(BSExtraData* pExtraData, bool flag)
{
    if (!g_BGSSaveLoadGame->FUN_0042ce10() || pExtraData == 0 || flag)
    {
        reinterpret_cast<FUN_00421850_shell*>(reinterpret_cast<TESDataHandler*>(this)->GetTESImageSpaceModifierList())
            ->FUN_00421850(pExtraData);
    }

    if (pExtraData != 0)
    {
        reinterpret_cast<FUN_00546b10_virtuals*>(this)->f18(0x40000000);

        if (!reinterpret_cast<TESObjectCELL*>(this)->IsCellInterior())
        {
            int x = reinterpret_cast<TESObjectCELL*>(this)->GetCellGridX();
            int y = reinterpret_cast<TESObjectCELL*>(this)->GetCellGridY();

            if (x <= 127 && x >= -128 && y <= 127 && y >= -128)
            {
                reinterpret_cast<FUN_00546b10_virtuals*>(this)->f18(0x20000000);
            }
            else
            {
                reinterpret_cast<FUN_00546b10_virtuals*>(this)->f18(0x10000000);
            }
        }
    }
    else
    {
        reinterpret_cast<FUN_00546b10_virtuals*>(this)->f19(0x70000000);
    }
}
}  // namespace fnv_00546b10

struct FUN_0041c580_Class
{
    int GetExtraDataNameAndPtr(int arg1, int arg2);
};

struct FUN_005477f0_Class : public TESObjectCELL
{
    int FUN_005477f0(int arg1, int arg2);
};

// @fnv 0x005477f0
int FUN_005477f0_Class::FUN_005477f0(int arg1, int arg2)
{
    if (IsCellInterior())
        return 0;

    return reinterpret_cast<FUN_0041c580_Class*>(
               reinterpret_cast<TESDataHandler*>(this)->GetTESImageSpaceModifierList())
        ->GetExtraDataNameAndPtr(arg1, arg2);
}

namespace fnv_00548740 {
class TESForm
{
  public:
    bool IsTemporary(void) const;
};

struct CellH
{
    bool IsCellPersistent(void);
};

struct BSOcclusionPlane
{
    int GetCullResult(void) const;
};

struct LLD_Cell
{
    void RemoveReference(TESObjectREFR* reference);
};

struct G2
{
    void AddHead(int* value);
};

struct ObjectReferenceHelper
{
    TESForm* _FNV_GetObjectReference(void);
};

struct ExtraDataListHelper
{
    void CallExtraDataListMethod35(TESObjectCELL* cell);
};

struct TESDataHandlerHelper
{
    bool FUN_004516b0(void);
};

struct TESObjectREFRHelper : public TESObjectREFR
{
    ExtraDataList* GetExtraData(void);
    bool GetReferencePersistence(void);
};

struct AddLightHelper
{
    void FUN_005728c0(int value);
};

struct VirtualSlots
{
    virtual void slot0()
    {}
    virtual void slot1()
    {}
    virtual void slot2()
    {}
    virtual void slot3()
    {}
    virtual void slot4()
    {}
    virtual void slot5()
    {}
    virtual void slot6()
    {}
    virtual void slot7()
    {}
    virtual void slot8()
    {}
    virtual void slot9()
    {}
    virtual void slot10()
    {}
    virtual void slot11()
    {}
    virtual void slot12()
    {}
    virtual void slot13()
    {}
    virtual void slot14()
    {}
    virtual void slot15()
    {}
    virtual void slot16()
    {}
    virtual void slot17()
    {}
    virtual void slot18()
    {}
    virtual void slot19()
    {}
    virtual void slot20()
    {}
    virtual void slot21()
    {}
    virtual void slot22()
    {}
    virtual void slot23()
    {}
    virtual void slot24()
    {}
    virtual void slot25()
    {}
    virtual void slot26()
    {}
    virtual void slot27()
    {}
    virtual void slot28()
    {}
    virtual void slot29()
    {}
    virtual void slot30()
    {}
    virtual void slot31()
    {}
    virtual void slot32()
    {}
    virtual void slot33()
    {}
    virtual void slot34()
    {}
    virtual void slot35()
    {}
    virtual void slot36()
    {}
    virtual void slot37()
    {}
    virtual void slot38()
    {}
    virtual void slot39()
    {}
    virtual void slot40()
    {}
    virtual void slot41()
    {}
    virtual void slot42()
    {}
    virtual void slot43()
    {}
    virtual void slot44()
    {}
    virtual void slot45()
    {}
    virtual void slot46()
    {}
    virtual void slot47()
    {}
    virtual void slot48()
    {}
    virtual void slot49()
    {}
    virtual void slot50(int value)
    {}
    virtual void slot51()
    {}
    virtual void slot52()
    {}
    virtual void slot53()
    {}
    virtual void slot54()
    {}
    virtual void slot55()
    {}
    virtual void slot56()
    {}
    virtual void slot57()
    {}
    virtual void slot58()
    {}
    virtual void slot59()
    {}
    virtual void slot60()
    {}
    virtual void slot61()
    {}
    virtual void slot62()
    {}
    virtual void slot63()
    {}
    virtual void slot64()
    {}
    virtual void slot65()
    {}
    virtual void slot66()
    {}
    virtual void slot67()
    {}
    virtual void slot68()
    {}
    virtual void slot69()
    {}
    virtual void slot70()
    {}
    virtual void slot71()
    {}
    virtual void slot72()
    {}
    virtual void slot73()
    {}
    virtual void slot74()
    {}
    virtual void slot75()
    {}
    virtual void slot76()
    {}
    virtual void slot77()
    {}
    virtual void slot78()
    {}
    virtual void slot79()
    {}
    virtual void slot80()
    {}
    virtual void slot81()
    {}
    virtual void slot82()
    {}
    virtual void slot83()
    {}
    virtual void slot84()
    {}
    virtual void slot85()
    {}
    virtual void slot86()
    {}
    virtual void slot87()
    {}
    virtual void slot88()
    {}
    virtual void slot89()
    {}
    virtual void slot90()
    {}
    virtual void slot91()
    {}
    virtual void slot92()
    {}
    virtual void slot93()
    {}
    virtual void slot94()
    {}
    virtual void slot95()
    {}
    virtual void slot96()
    {}
    virtual void slot97()
    {}
    virtual void slot98()
    {}
    virtual void slot99()
    {}
    virtual void slot100()
    {}
    virtual void slot101()
    {}
    virtual void slot102()
    {}
    virtual void slot103()
    {}
    virtual void slot104()
    {}
    virtual void slot105()
    {}
    virtual void slot106()
    {}
    virtual void slot107()
    {}
    virtual void slot108()
    {}
    virtual void slot109()
    {}
    virtual void slot110()
    {}
    virtual void slot111()
    {}
    virtual void slot112()
    {}
    virtual void slot113()
    {}
    virtual void slot114()
    {}
    virtual void slot115()
    {}
    virtual void slot116()
    {}
    virtual void slot117()
    {}
    virtual void slot118()
    {}
    virtual void slot119()
    {}
    virtual void slot120()
    {}
    virtual void slot121()
    {}
    virtual void slot122()
    {}
    virtual void slot123()
    {}
    virtual void slot124()
    {}
    virtual void slot125()
    {}
    virtual void slot126()
    {}
    virtual void slot127()
    {}
    virtual void slot128()
    {}
    virtual void slot129()
    {}
    virtual void slot130()
    {}
    virtual void slot131()
    {}
    virtual void slot132()
    {}
    virtual void slot133()
    {}
    virtual void slot134()
    {}
    virtual void slot135()
    {}
    virtual void slot136()
    {}
    virtual void slot137()
    {}
    virtual void slot138(TESObjectCELL* cell)
    {}
};

class DH;
extern DH* g_dataHandler;

struct FUN_00548740_Cell : public TESObjectCELL
{
    void FUN_00548740(TESObjectREFR* apRef);
};

// @fnv 0x00548740
void FUN_00548740_Cell::FUN_00548740(TESObjectREFR* apRef)
{
    if (!apRef || !reinterpret_cast<ObjectReferenceHelper*>(apRef)->_FNV_GetObjectReference())
        return;

    if (reinterpret_cast<CellH*>(this)->IsCellPersistent())
    {
        TESObjectCELL::CellRefLockEnter();
        reinterpret_cast<G2*>(FUN_009604f0())->AddHead(reinterpret_cast<int*>(&apRef));
        TESObjectCELL::CellRefLockLeave();

        reinterpret_cast<ExtraDataListHelper*>(reinterpret_cast<TESObjectREFRHelper*>(apRef)->GetExtraData())
            ->CallExtraDataListMethod35(this);

        if (!reinterpret_cast<TESDataHandlerHelper*>(g_dataHandler)->FUN_004516b0())
            reinterpret_cast<VirtualSlots*>(this)->slot50(1);

        return;
    }

    LLD_Cell* pOldParent;
    pOldParent = reinterpret_cast<LLD_Cell*>(reinterpret_cast<BSOcclusionPlane*>(apRef)->GetCullResult());

    if (pOldParent)
        pOldParent->RemoveReference(apRef);

    TESObjectCELL::CellRefLockEnter();
    reinterpret_cast<G2*>(FUN_009604f0())->AddHead(reinterpret_cast<int*>(&apRef));
    reinterpret_cast<VirtualSlots*>(apRef)->slot138(this);
    TESObjectCELL::CellRefLockLeave();

    if (!reinterpret_cast<TESForm*>(apRef)->IsTemporary() &&
        !reinterpret_cast<TESObjectREFRHelper*>(apRef)->GetReferencePersistence() &&
        !reinterpret_cast<TESDataHandlerHelper*>(g_dataHandler)->FUN_004516b0())
        reinterpret_cast<VirtualSlots*>(this)->slot50(1);

    reinterpret_cast<AddLightHelper*>(apRef)->FUN_005728c0(0);
}
}  // namespace fnv_00548740

struct FUN_0096dcb0_shell
{
    void UpdateActorsFromList(BSSimpleList<BGSPerkEntry*>* list);
};

extern FUN_0096dcb0_shell DAT_011e0e80;

struct FUN_0054af80_shell : public TESObjectCELL
{
    void LockAndProcessPerks();
};

// Enters the cell ref lock, processes the perk entry list from FUN_009604f0, then leaves the lock.
// @fnv 0x0054af80
void FUN_0054af80_shell::LockAndProcessPerks()
{
    CellRefLockEnter();
    DAT_011e0e80.UpdateActorsFromList(FUN_009604f0());
    CellRefLockLeave();
}

namespace fnv_0054e750 {
class GO
{
  public:
    int value;
    GO(int);
    ~GO();
    void operator=(void*);
    operator unsigned int() const;
};

class Helper62d0
{
  public:
    void* operator=(void const*);
};

class TextureReceiver
{
  public:
    TextureReceiver* FUN_004bc320(int);
    void FUN_0054e710();
};

struct FUN_0054e750Class : public TESObjectCELL
{
  public:
    void FUN_0054f500(void*, unsigned int, GO*);
    void FUN_0054e750(void*, unsigned int, Helper62d0*);
};

// @fnv 0x0054e750
void FUN_0054e750Class::FUN_0054e750(void* arg1, unsigned int arg2, Helper62d0* pOut)
{
    GO result(0);
    const char* name = "GetInteriorLocalMapTexture";
    if (IsCellInterior())
    {
        GO texture(0);
        this->FUN_0054f500(arg1, arg2, &texture);
        result.operator=(reinterpret_cast<TextureReceiver*>(texture.operator unsigned int())->FUN_004bc320(0));
        reinterpret_cast<TextureReceiver*>(texture.operator unsigned int())->FUN_0054e710();
    }
    pOut->operator=(&result);
}
}  // namespace fnv_0054e750

struct FormRecordHeader
{
    unsigned int form;
    unsigned int pad1;
    unsigned int pad2;
    unsigned int iFormID;
};

struct TESFile_Helper
{
    bool FUN_00472150(bool);
};

struct TESFile_NextGroup
{
    bool IsGroupOpen();
};

struct TESFile_GetTESForm
{
    unsigned int GetTESForm();
};

bool FUN_00554810(FormRecordHeader*);
bool _FUN_005548a0(unsigned int);
unsigned int kGroupFormType;

// Checks that apFile's record header is a CELL record, walks its groups, and returns true if a form with type 0x42 is found.
// @fnv 0x00550f60
bool FUN_00550f60(TESFile* apFile)
{
    FormRecordHeader* pRecordHeader;
    bool bretval;

    if (!apFile)
        return false;

    pRecordHeader = reinterpret_cast<FormRecordHeader*>(apFile->GetRecordHeader());
    if (pRecordHeader->form != *reinterpret_cast<const unsigned int*>("CELL:"))
        return false;

    if (!reinterpret_cast<TESFile_Helper*>(apFile)->FUN_00472150(true))
        return false;

    pRecordHeader = reinterpret_cast<FormRecordHeader*>(apFile->GetRecordHeader());
    if (!FUN_00554810(pRecordHeader))
        return false;

    if (!reinterpret_cast<TESFile_Helper*>(apFile)->FUN_00472150(true))
        return false;

    pRecordHeader = reinterpret_cast<FormRecordHeader*>(apFile->GetRecordHeader());
    if (!FUN_00554810(pRecordHeader))
        return false;

    if (pRecordHeader->form != kGroupFormType)
        return false;

    if (pRecordHeader->iFormID == 8)
    {
        reinterpret_cast<TESFile_NextGroup*>(apFile)->IsGroupOpen();
        pRecordHeader = reinterpret_cast<FormRecordHeader*>(apFile->GetRecordHeader());
        if (!FUN_00554810(pRecordHeader))
            return false;
    }

    if (pRecordHeader->iFormID != 9)
        return false;

    reinterpret_cast<TESFile_Helper*>(apFile)->FUN_00472150(true);
    bretval = false;

    while (_FUN_005548a0(reinterpret_cast<TESFile_GetTESForm*>(apFile)->GetTESForm()))
    {
        if (reinterpret_cast<TESFile_GetTESForm*>(apFile)->GetTESForm() == 0x42)
        {
            bretval = true;
            break;
        }

        reinterpret_cast<TESFile_Helper*>(apFile)->FUN_00472150(true);
    }

    return bretval;
}

struct NiUpdateData
{
    float fTime;
    bool bFlag1;
    bool bFlag2;
    int iPadding;

    NiUpdateData(float time, bool flag1, bool flag2);
};

struct _FakeNiAVObject
{
    virtual void FUN_01() = 0;
    virtual void FUN_02() = 0;
    virtual void FUN_03() = 0;
    virtual NiNode* GetNode() = 0;
    virtual void FUN_05() = 0;
    virtual void FUN_06() = 0;
    virtual void FUN_07() = 0;
    virtual void FUN_08() = 0;
    virtual void FUN_09() = 0;
    virtual void FUN_10() = 0;
    virtual void FUN_11() = 0;
    virtual void FUN_12() = 0;
    virtual NiNode* GetUpdateNode() = 0;
};

struct _FakeNiNode
{
    unsigned int FUN_0043b480();
};

struct NN_00605d70
{
    void Update(const NiUpdateData& data);
};

extern float DAT_011c3c08;

void __cdecl UpdateSceneGraph(NiAVObject* object);

// @fnv 0x005526f0
void __cdecl UpdateSceneGraph(NiAVObject* object)
{
    if (object)
    {
        NiNode* node = reinterpret_cast<_FakeNiAVObject*>(object)->GetNode();
        if (node)
        {
            unsigned int count = reinterpret_cast<_FakeNiNode*>(node)->FUN_0043b480();
            for (unsigned int i = 0; i < count; ++i)
                UpdateSceneGraph(node->FUN_0043b4a0(i));
        }
        else
        {
            NiNode* updateNode = reinterpret_cast<_FakeNiAVObject*>(object)->GetUpdateNode();
            if (updateNode)
            {
                NiUpdateData updateData(DAT_011c3c08, true, false);
                reinterpret_cast<NN_00605d70*>(updateNode)->Update(updateData);
            }
        }
    }
}

namespace fnv_00555630 {
class FNStub
{
  public:
    char* GetFullName();
};

class FormChangeMask
{
  public:
    FormChangeMask(unsigned int value) : m_uiFilterValue(value)
    {}
    FormChangeMask(const FormChangeMask& rhs) : m_uiFilterValue(rhs.m_uiFilterValue)
    {}

    operator bool() const;

  private:
    unsigned int m_uiFilterValue;
};

class SaveFormIDHelper
{
  public:
    void SerializeFormData(void*, int);
};

class BGSLoadFormBuffer : public SaveFormIDHelper
{
  public:
    FormChangeMask GetChangeFlags(unsigned int);
};

class BGSSaveGameBuffer : public BGSLoadFormBuffer
{
  public:
    void SaveGameString(char const*, int);
};

class BGSSaveFormBuffer : public BGSSaveGameBuffer
{
  public:
    void SaveData(void*, int, int);
};

class SeenData
{
  public:
    virtual void FUN_0()
    {}
    virtual void FUN_1()
    {}
    virtual void FUN_2()
    {}
    virtual void Save(BGSSaveFormBuffer*)
    {}
};

class FUN_00484d60_holder
{
  public:
    void SaveIfChanged(unsigned int);
};

class FUN_00555bc0_shell
{
  public:
    SeenData* FindSeenData();
};

struct FUN_00555630_holder : public DoorCell
{
    void FUN_00555630(BGSSaveFormBuffer*);
};

// Saves the cell's flags, seen data, full name and owner to the save buffer when the corresponding change flags are set.
// @fnv 0x00555630
void FUN_00555630_holder::FUN_00555630(BGSSaveFormBuffer* apSaveGameBuffer)
{
    unsigned char ctempCellFlags;

    reinterpret_cast<FUN_00484d60_holder*>(this)->SaveIfChanged((unsigned int)apSaveGameBuffer);

    if (apSaveGameBuffer->GetChangeFlags(2))
    {
        ctempCellFlags = (unsigned char)(reinterpret_cast<unsigned char*>(this)[0x24] & 0x60);
        ctempCellFlags |= reinterpret_cast<unsigned char*>(this)[0x25];
        apSaveGameBuffer->SaveData(&ctempCellFlags, 1, 0);
    }

    if (apSaveGameBuffer->GetChangeFlags(0x80000000))
    {
        reinterpret_cast<FUN_00555bc0_shell*>(this)->FindSeenData()->Save(apSaveGameBuffer);
    }

    {
        const char* pfullname;
        TESForm* powner;

        if (apSaveGameBuffer->GetChangeFlags(4))
        {
            pfullname = reinterpret_cast<FNStub*>(reinterpret_cast<unsigned char*>(this) + 0x18)->GetFullName();
            apSaveGameBuffer->SaveGameString(pfullname, 0);
        }

        if (apSaveGameBuffer->GetChangeFlags(8))
        {
            powner = reinterpret_cast<DoorCell*>(this)->GetOwner();
            apSaveGameBuffer->SerializeFormData(powner, 0);
        }
    }
}
}  // namespace fnv_00555630

namespace fnv_005578f0 {
struct NiFixedStr
{
    operator char const*();
};

struct SeqObj
{
    NiFixedStr& GetName();
};

struct _FakeNiNode
{
    unsigned int FUN_0043b480();
};

unsigned int __fastcall FUN_00524cf0(TESObjectCELL* object);
int __cdecl FUN_00408b20(char const* left, char const* right);
extern char str_0102f154[];

struct FUN_005578f0_Node
{
    virtual void D00() = 0;
    virtual void D01() = 0;
    virtual void D02() = 0;
    virtual void D03() = 0;
    virtual void D04() = 0;
    virtual void D05() = 0;
    virtual void D06() = 0;
    virtual void D07() = 0;
    virtual void D08() = 0;
    virtual void D09() = 0;
    virtual void D10() = 0;
    virtual void D11() = 0;
    virtual void D12() = 0;
    virtual void D13() = 0;
    virtual void D14() = 0;
    virtual void D15() = 0;
    virtual void D16() = 0;
    virtual void D17() = 0;
    virtual void D18() = 0;
    virtual void D19() = 0;
    virtual void D20() = 0;
    virtual void D21() = 0;
    virtual void D22() = 0;
    virtual void D23() = 0;
    virtual void D24() = 0;
    virtual void D25() = 0;
    virtual void D26() = 0;
    virtual void D27() = 0;
    virtual void D28() = 0;
    virtual void D29() = 0;
    virtual void D30() = 0;
    virtual void D31() = 0;
    virtual void D32() = 0;
    virtual void D33() = 0;
    virtual void D34() = 0;
    virtual void D35() = 0;
    virtual void D36() = 0;
    virtual void D37() = 0;
    virtual void D38() = 0;
    virtual void D39() = 0;
    virtual void D40() = 0;
    virtual void D41() = 0;
    virtual void D42() = 0;
    virtual void D43() = 0;
    virtual void D44() = 0;
    virtual void D45() = 0;
    virtual void D46() = 0;
    virtual void D47() = 0;
    virtual void D48() = 0;
    virtual void D49() = 0;
    virtual void D50() = 0;
    virtual void D51() = 0;
    virtual void D52() = 0;
    virtual void D53() = 0;
    virtual void D54() = 0;
    virtual void D55() = 0;
    virtual void D56() = 0;
    virtual void D57() = 0;
    virtual void D58() = 0;
    virtual void D59() = 0;
    virtual void RemoveLocationMarker(unsigned int index)
    {}
};

struct FUN_005578f0_Class
{
    void FUN_005578f0();
};

// @fnv 0x005578f0
void FUN_005578f0_Class::FUN_005578f0()
{
    NiNode* pmarkerNode = reinterpret_cast<NiNode*>(FUN_00524cf0(reinterpret_cast<TESObjectCELL*>(this)));
    unsigned int i;

    if (!pmarkerNode)
    {
    }
    else
    {
        for (i = 0; i < reinterpret_cast<_FakeNiNode*>(pmarkerNode)->FUN_0043b480(); ++i)
        {
            NiAVObject* pChild = pmarkerNode->FUN_0043b4a0(i);
            if (pChild)
            {
                const char* pChildName = reinterpret_cast<SeqObj*>(pChild)->GetName().operator char const*();
                if (pChildName)
                {
                    if (!FUN_00408b20(pChildName, str_0102f154))
                    {
                        reinterpret_cast<FUN_005578f0_Node*>(pmarkerNode)->RemoveLocationMarker(i);
                    }
                }
            }
        }
    }
}
}  // namespace fnv_005578f0

void __cdecl _Deallocate(void* pointer);

struct FUN_00558df0_StandIn
{
    void FUN_00558f20();
    void* FUN_00558df0(unsigned int flags);
};

// Calls FUN_00558f20, then deallocates this object if bit 0 of flags is set, and returns this.
// @fnv 0x00558df0
void* FUN_00558df0_StandIn::FUN_00558df0(unsigned int flags)
{
    FUN_00558f20();

    if (flags & 1)
        _Deallocate(this);

    return this;
}

void __cdecl _Deallocate(void* pointer);

struct FUN_00558e20_StandIn
{
    void* FUN_00558e20(unsigned int flags);
    void FUN_00559020();
};

// Calls FUN_00559020, then frees this object via _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00558e20
void* FUN_00558e20_StandIn::FUN_00558e20(unsigned int flags)
{
    FUN_00559020();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void _Deallocate(void* pointer);

struct FUN_00558e50_StandIn
{
    void FUN_005591d0();
    void* FUN_00558e50(unsigned int flags);
};

// Calls FUN_005591d0, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x00558e50
void* FUN_00558e50_StandIn::FUN_00558e50(unsigned int flags)
{
    FUN_005591d0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_0062d640 {
struct ArrSI
{
    unsigned int GetFlags(void);
};

struct hkpEntity : ArrSI
{
};

struct hkpEntityListener
{
    virtual void FUN_004f0000(hkpEntity*);
    virtual void FUN_004f0004(hkpEntity*);
    virtual void FUN_004f0008(hkpEntity*);

    void NotifyEntityIfFlagged(hkpEntity*);
};

unsigned int ArrSI::GetFlags(void)
{
    return 0;
}

void hkpEntityListener::FUN_004f0000(hkpEntity*)
{}

void hkpEntityListener::FUN_004f0004(hkpEntity*)
{}

void hkpEntityListener::FUN_004f0008(hkpEntity*)
{}

// If entity->GetFlags() is nonzero, calls FUN_004f0008 then FUN_004f0004 on the entity.
// @fnv 0x0062d640
void hkpEntityListener::NotifyEntityIfFlagged(hkpEntity* entity)
{
    if (entity->GetFlags() != 0)
    {
        FUN_004f0008(entity);
        FUN_004f0004(entity);
    }
}
}  // namespace fnv_0062d640

struct SubObj_0045c9a0
{
    int GetCellNodeAt(int arg);
};

class GuardedSubHolder
{
  public:
    char pad[0x20];
    SubObj_0045c9a0* sub;
    int FUN_00535af0(int arg);
};

// If sub is non-null and arg is less than 4, forwards arg to sub's GetCellNodeAt and returns its result; otherwise returns 0.
// @fnv 0x00535af0
int GuardedSubHolder::FUN_00535af0(int arg)
{
    int result = 0;
    if (this->sub != 0 && arg < 4)
    {
        result = this->sub->GetCellNodeAt(arg);
    }
    return result;
}

struct CellFileStub;
struct CellFormStub
{
    CellFileStub* GetFile(int index);
    bool FUN_00460340();
};
struct CellGroupHeader
{
    unsigned int type;
    unsigned int size;
    unsigned int label;
    unsigned int groupType;
    unsigned int stamp;
    unsigned int unk14;
};
struct CellFileStub
{
    bool Bool471c20();
    void Write472fe0(TESObjectCELL* form);
    void OpenGroup473310(CellGroupHeader* header);
};
struct CellRefNodeStub
{
    bool IsEmpty8256d0();
    CellFormStub** GetItem6815c0();
    CellRefNodeStub* GetNext726070();
};
struct CellVTableStub
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
};
extern unsigned int kGroupFormType;

struct FUN_00541e80_shell : public TESObjectCELL
{
    bool GetDeleted440d80() const;
    bool FUN_00460340();
    unsigned int GetFormID84e3a0();
    CellRefNodeStub* GetRefList9604f0();
    CellFileStub* GetFile(int index);
    void SaveChildren542040(CellFileStub* file);
    bool SaveCellToFile(CellFileStub* file);
};

// @fnv 0x00541e80
bool FUN_00541e80_shell::SaveCellToFile(CellFileStub* file)
{
    if (GetDeleted440d80())
        return false;

    bool bSave;
    CellRefNodeStub* node_2;
    CellFormStub* ref;
    CellFileStub* refFile5;
    CellGroupHeader header8;
    bSave = false;
    CellRefLockEnter();
    if (file->Bool471c20() || FUN_00460340())
    {
        bSave = true;
    }
    else
    {
        node_2 = GetRefList9604f0();
        while (node_2 && !node_2->IsEmpty8256d0())
        {
            ref = *node_2->GetItem6815c0();
            node_2 = node_2->GetNext726070();
            refFile5 = ref->GetFile(-1);
            if (refFile5 == file || !refFile5 || ref->FUN_00460340())
            {
                bSave = true;
                break;
            }
        }
    }
    CellRefLockLeave();

    if (!bSave)
        return false;

    ((CellVTableStub*)this)->v11();
    file->Write472fe0(this);

    header8.type = kGroupFormType;
    header8.groupType = 6;
    header8.label = GetFormID84e3a0();
    header8.size = 0;
    header8.stamp = 0;
    file->OpenGroup473310(&header8);
    if (!file->Bool471c20() || GetFile(0) == file)
        SaveChildren542040(file);
    return true;
}

struct CellData20;
extern void* DAT_01187020;

struct ParamCls
{
  public:
    void RunProbe(struct CellX* cell);
    void SpawnObject(CellData20* data);
};

struct CellData20
{
  public:
    void* m_ptr;
    unsigned int m_zeroA;
    unsigned int m_result;
    unsigned int m_six;
    unsigned int m_zeroB;
};

struct CellX
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
    virtual void v10();
    virtual void v11();
    unsigned int FUN_0084e3a0();
    void FUN_00542040(ParamCls* param);
    bool ProcessCell(ParamCls* param);
};

// @fnv 0x00541fd0
bool CellX::ProcessCell(ParamCls* param)
{
    this->v11();
    param->RunProbe(this);
    CellData20 d;
    void* reserved;
    d.m_ptr = DAT_01187020;
    d.m_six = 6;
    d.m_result = this->FUN_0084e3a0();
    d.m_zeroA = 0;
    d.m_zeroB = 0;
    param->SpawnObject(&d);
    this->FUN_00542040(param);
    return true;
}

bool __fastcall FUN_00425fd0(void* pThis);
unsigned int __fastcall FUN_0044ddc0(void* pThis);
void* __fastcall FUN_0054ddd0(void* pThis);
bool __fastcall HasFlag80000(void* pThis);

// @fnv 0x005444c0
bool __fastcall FUN_005444c0(TESObjectCELL* pThis)
{
    unsigned int flags;
    void* holder;
    if (FUN_00425fd0(pThis) != 0)
    {
        flags = FUN_0044ddc0(pThis);
        if ((flags & 0x80000) != 0)
        {
            return true;
        }
    }
    else
    {
        holder = FUN_0054ddd0(pThis);
        if (holder != 0)
        {
            return HasFlag80000(holder);
        }
    }
    return false;
}

struct CellFlagHolder
{
    char unk00[8];
    signed char unk08;
};

struct FUN_00544590_cls : public TESObjectCELL
{
    void* FUN_005445d0();
    bool FUN_00544590(unsigned int bit);
};

// Returns true if the flag holder's byte at offset 8 has the bit for the given index set, otherwise false.
// @fnv 0x00544590
bool FUN_00544590_cls::FUN_00544590(unsigned int bit)
{
    CellFlagHolder* holder = (CellFlagHolder*)FUN_005445d0();
    if (holder != 0)
    {
        int mask = 1 << bit;
        if ((holder->unk08 & mask) != 0)
        {
            return true;
        }
    }
    return false;
}

struct FUN_005454f0_cls;

struct CellRefResolver
{
    void* Resolve();
};

struct CellRefProbe
{
    int Probe();
};

struct CellRefLookup
{
    void* Lookup();
};

struct CellRefAttach
{
    void Attach(void* ref);
};

struct FUN_005454f0_cls
{
    char pad00[0xc4];
    void* m_pC4;
    void FUN_005454f0(void* ref);
};

// If m_pC4 is set, resolves ref and attaches it to the +0x2c list when its probe equals 0x1e, otherwise attaches the looked-up pointer to the +0x1c list.
// @fnv 0x005454f0
void FUN_005454f0_cls::FUN_005454f0(void* ref)
{
    if (m_pC4 != 0)
    {
        if (((CellRefProbe*)((CellRefResolver*)ref)->Resolve())->Probe() == 0x1e)
        {
            ((CellRefAttach*)((char*)m_pC4 + 0x2c))->Attach(ref);
        }
        else
        {
            void* p = ((CellRefLookup*)ref)->Lookup();
            if (p != 0)
            {
                ((CellRefAttach*)((char*)m_pC4 + 0x1c))->Attach(p);
            }
        }
    }
}

struct FUN_005455c0_ref;
struct FUN_005455c0_node;
struct FUN_005455c0_item
{
    unsigned int m_00;
};
struct FUN_005455c0_ref
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
    virtual void* v48(unsigned int flags);
};
struct FUN_005455c0_node
{
    unsigned char FUN_008256d0();
    FUN_005455c0_item* FUN_006815c0();
    FUN_005455c0_node* FUN_00726070();
    void FUN_00905820(FUN_005455c0_ref** arg);
    void FUN_005ae3d0(FUN_005455c0_ref** arg);
};
class FUN_005455c0_cls
{
  public:
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
    unsigned int unkBC;
    unsigned int unkC0;
    char* m_c4;
    void FUN_005455c0(FUN_005455c0_ref* ref);
};

// @fnv 0x005455c0
void FUN_005455c0_cls::FUN_005455c0(FUN_005455c0_ref* ref)
{
    if (m_c4 != 0)
    {
        FUN_005455c0_node* cur = (FUN_005455c0_node*)(m_c4 + 0x54);
        FUN_005455c0_node* prev = 0;
        while (cur != 0 && !cur->FUN_008256d0())
        {
            if (cur->FUN_006815c0()->m_00 == (unsigned int)ref)
            {
                return;
            }
            prev = cur;
            cur = cur->FUN_00726070();
        }
        ref->v48(0x4000000);
        if (prev != 0)
        {
            prev->FUN_00905820(&ref);
        }
        else
        {
            ((FUN_005455c0_node*)(m_c4 + 0x54))->FUN_005ae3d0(&ref);
        }
    }
}

struct NiPoint3S
{
    float x;
    float y;
    float z;
};
struct Mat9S
{
    float m00;
    float m01;
    float m02;
    float m10;
    float m11;
    float m12;
    float m20;
    float m21;
    float m22;
};

struct FaceAnimData;
struct FaceGenNode;

struct AnimController
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
    virtual int GetType();
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
    virtual void SetTarget(void* target);
    void SetRotation(const Mat9S& m);
};

struct FaceAnimData
{
    AnimController* GetController();
    void SetController(AnimController* c);
};

struct FaceGenNode
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
    virtual void Update();
    int n04;
    int n08;
    int n0c;
    int n10;
    int n14;
    int n18;
    int n1c;
    int n20;
    int n24;
    int n28;
    int n2c;
    int n30;
    int n34;
    int n38;
    int n3c;
    int n40;
    int n44;
    int n48;
    int n4c;
    int n50;
    int n54;
    int n58;
    int n5c;
    int n60;
    int n64;
    int n68;
    int n6c;
    int n70;
    int n74;
    int n78;
    int n7c;
    int n80;
    int n84;
    int n88;
    int n8c;
    int n90;
    int n94;
    int n98;
    int n9c;
    int na0;
    int na4;
    int na8;
    int nac;
    int nb0;
    FaceGenNode();
    void SetAnimData(FaceAnimData* d);
    FaceAnimData* GetAnimData();
    static void* operator new(unsigned int size);
    static void operator delete(void*, unsigned int);
};

struct Primitive
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual AnimController* CreateController(NiPoint3S* pt);
};

struct ModelHolder
{
    FaceGenNode* GetNode();
    Primitive* GetModelPrimitive();
};

struct RefForm;

struct NodePtr
{
    FaceGenNode* obj;
    NodePtr(FaceGenNode* p);
    ~NodePtr();
};

struct NodeList
{
    void Add(RefForm* ref, NodePtr node);
};

struct CellUnkC4
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
    NodeList list;
};

struct RefForm
{
    virtual void r000();
    virtual void r004();
    virtual void r008();
    virtual void r00c();
    virtual void r010();
    virtual void r014();
    virtual void r018();
    virtual void r01c();
    virtual void r020();
    virtual void r024();
    virtual void r028();
    virtual void r02c();
    virtual void r030();
    virtual void r034();
    virtual void r038();
    virtual void r03c();
    virtual void r040();
    virtual void r044();
    virtual void r048();
    virtual void r04c();
    virtual void r050();
    virtual void r054();
    virtual void r058();
    virtual void r05c();
    virtual void r060();
    virtual void r064();
    virtual void r068();
    virtual void r06c();
    virtual void r070();
    virtual void r074();
    virtual void r078();
    virtual void r07c();
    virtual void r080();
    virtual void r084();
    virtual void r088();
    virtual void r08c();
    virtual void r090();
    virtual void r094();
    virtual void r098();
    virtual void r09c();
    virtual void r0a0();
    virtual void r0a4();
    virtual void r0a8();
    virtual void r0ac();
    virtual void r0b0();
    virtual void r0b4();
    virtual void r0b8();
    virtual void r0bc();
    virtual void r0c0();
    virtual void r0c4();
    virtual void r0c8();
    virtual void r0cc();
    virtual void r0d0();
    virtual void r0d4();
    virtual void r0d8();
    virtual void r0dc();
    virtual void r0e0();
    virtual void r0e4();
    virtual void r0e8();
    virtual void r0ec();
    virtual void r0f0();
    virtual void r0f4();
    virtual void r0f8();
    virtual void r0fc();
    virtual void r100();
    virtual void r104();
    virtual void r108();
    virtual void r10c();
    virtual void r110();
    virtual void r114();
    virtual void r118();
    virtual void r11c();
    virtual void r120();
    virtual void r124();
    virtual void r128();
    virtual void r12c();
    virtual void r130();
    virtual void r134();
    virtual void r138();
    virtual void r13c();
    virtual void r140();
    virtual void r144();
    virtual void r148();
    virtual void r14c();
    virtual void r150();
    virtual void r154();
    virtual void r158();
    virtual void r15c();
    virtual void r160();
    virtual void r164();
    virtual void r168();
    virtual void r16c();
    virtual void r170();
    virtual void r174();
    virtual void r178();
    virtual void r17c();
    virtual void r180();
    virtual void r184();
    virtual void r188();
    virtual void r18c();
    virtual void r190();
    virtual void r194();
    virtual void r198();
    virtual void r19c();
    virtual void r1a0();
    virtual void r1a4();
    virtual void r1a8();
    virtual void r1ac();
    virtual void r1b0();
    virtual void r1b4();
    virtual void r1b8();
    virtual void r1bc();
    virtual void r1c0();
    virtual void r1c4();
    virtual void r1c8();
    virtual void r1cc();
    virtual void r1d0();
    virtual void r1d4();
    virtual void r1d8();
    virtual void r1dc();
    virtual void r1e0();
    virtual void r1e4();
    virtual void r1e8();
    virtual void r1ec();
    virtual void r1f0();
    bool IsReady();
    ModelHolder* GetModelHolder();
    void* GetBaseForm();
    FaceGenNode* GetFirstSceneObject();
    FaceAnimData* CreateAnimData();
    const NiPoint3S* GetAngle();
    Mat9S GetRotationMatrix();
    virtual void* GetTarget();
};

struct RefForm2 : RefForm
{
};

extern void* DAT_011ca238;

struct CellLike
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
    CellUnkC4* unkC4;
    FaceGenNode* GetOrCreateFaceGenNode(RefForm* ref);
};

// @fnv 0x00545740
FaceGenNode* CellLike::GetOrCreateFaceGenNode(RefForm* ref)
{
    if (!unkC4 || !ref || !ref->IsReady())
        return 0;
    FaceGenNode* node5 = ref->GetModelHolder()->GetNode();
    FaceAnimData* data3 = 0;
    if (!node5)
    {
        if (ref->GetBaseForm() == DAT_011ca238)
        {
            node5 = ref->GetFirstSceneObject();
            if (!node5)
                return 0;
            data3 = node5->GetAnimData();
        }
        else
        {
            node5 = new FaceGenNode();
            data3 = ref->CreateAnimData();
            node5->SetAnimData(data3);
        }
    }
    else
    {
        data3 = node5->GetAnimData();
    }
    AnimController* ctrl = data3->GetController();
    if (!ctrl)
    {
        Primitive* prim = ref->GetModelHolder()->GetModelPrimitive();
        if (prim)
        {
            NiPoint3S pt3 = *ref->GetAngle();
            ctrl = prim->CreateController(&pt3);
            data3->SetController(ctrl);
        }
    }
    if (ctrl)
    {
        ctrl->SetTarget(ref->GetTarget());
        if (ctrl->GetType() == 2)
        {
            ctrl->SetRotation(ref->GetRotationMatrix());
        }
        node5->SetAnimData(data3);
        unkC4->list.Add(ref, node5);
    }
    node5->Update();
    return node5;
}

struct FUN_00440640
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    ~FUN_00440640();
};
struct FUN_0045cec0
{
    unsigned int value;
    ~FUN_0045cec0();
};
struct FUN_0054ab60 : FUN_00440640
{
    FUN_0045cec0 member1c;
    FUN_0045cec0 member20;
    ~FUN_0054ab60();
};
// Destroys the object, releasing its two member objects and the base class.
// @fnv 0x0054ab60
FUN_0054ab60::~FUN_0054ab60()
{}

struct BaseFormDC
{
    int FUN_00401170();
    unsigned char FUN_005194d0();
};

struct ReferenceDC
{
    unsigned char FUN_00440da0();
    unsigned char FUN_00440d80();
    BaseFormDC* FUN_007af430();
    int FUN_00568e50();
};

struct ReferenceNodeDC
{
    ReferenceDC** FUN_006815c0();
    ReferenceNodeDC* FUN_00726070();
};

struct ReferenceCollectorDC
{
    void FUN_005ae3d0(ReferenceDC**);
};

extern BaseFormDC* DAT_011ca258;

struct FUN_0054dcf0_shell : TESObjectCELL
{
    void CollectCellReferences(ReferenceCollectorDC* collector);
};

// @fnv 0x0054dcf0
void FUN_0054dcf0_shell::CollectCellReferences(ReferenceCollectorDC* collector)
{
    if (collector != 0)
    {
        CellRefLockEnter();
        ReferenceNodeDC* node = reinterpret_cast<ReferenceNodeDC*>(FUN_009604f0());
        while (node != 0)
        {
            ReferenceDC* reference = *node->FUN_006815c0();
            if (reference != 0)
            {
                if (!reference->FUN_00440da0())
                {
                    if (!reference->FUN_00440d80())
                    {
                        BaseFormDC* baseForm = reference->FUN_007af430();
                        if (baseForm->FUN_00401170() == 0x1c && baseForm != DAT_011ca258)
                        {
                            BaseFormDC* currentForm = reference->FUN_007af430();
                            if (reference->FUN_00568e50() || currentForm->FUN_005194d0())
                            {
                                collector->FUN_005ae3d0(&reference);
                            }
                        }
                    }
                }
            }
            node = node->FUN_00726070();
        }
        CellRefLockLeave();
    }
}

extern int DAT_0102f024;
struct CellHandleData
{
    int FUN_004bc320();
    void FUN_0054e710();
};
struct CellHandle
{
    void* object;
    void FUN_00633c90(int value);
    CellHandleData* FUN_00559450(int index);
    CellHandleData* FUN_00559450();
    void FUN_0066b0d0(int value);
    void FUN_0045cec0();
    CellHandle(int value)
    {
        FUN_00633c90(value);
    }
    ~CellHandle()
    {
        FUN_0045cec0();
    }
};
struct CellTypedHandle : CellHandle
{
    void* typeData;
    CellTypedHandle(int value) : CellHandle(value)
    {}
    void FUN_006e5cc0(CellTypedHandle* other);
};
struct CellHandleProvider
{
    bool FUN_00425fd0();
    void BuildExteriorCameraScene(CellHandle* handle);
    void FUN_0054e640(CellTypedHandle* result);
};
// Builds a CellTypedHandle from DAT_0102f024, optionally filling it from a child handle, and copies it into result.
// @fnv 0x0054e640
void CellHandleProvider::FUN_0054e640(CellTypedHandle* result)
{
    CellTypedHandle current(0);
    current.typeData = &DAT_0102f024;
    if (!FUN_00425fd0())
    {
        CellHandle child(0);
        BuildExteriorCameraScene(&child);
        current.FUN_0066b0d0(child.FUN_00559450(0)->FUN_004bc320());
        child.FUN_00559450()->FUN_0054e710();
    }
    result->FUN_006e5cc0(&current);
}

struct FUN_0054e710_elem
{
    int m_v;
    void Method(int flag);
};

struct FUN_0054e710_cls
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
    FUN_0054e710_elem m_pElements[4];

    void FUN_0054e710();
};

// Calls Method(0) on each of the four elements in the array.
// @fnv 0x0054e710
void FUN_0054e710_cls::FUN_0054e710()
{
    for (int i = 0; i < 4; i++)
    {
        m_pElements[i].Method(0);
    }
}

// Stand-in for the cell's extra-data list: SetStringExtra attaches a named
// extra to the list.
struct CellExtraList
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    void SetStringExtra(const char* name);
};

// Stand-in for the cell object: the extra data list starts at offset 0x28.
struct FUN_00551650_cls
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
    CellExtraList extraDataList;
    bool FUN_00551650(const char* name);
};

extern int __cdecl FUN_0044a670(const char* text);

// If FUN_0044a670(name) returns non-zero, calls extraDataList.SetStringExtra(name); always returns true.
// @fnv 0x00551650
bool FUN_00551650_cls::FUN_00551650(const char* name)
{
    if (FUN_0044a670(name) != 0)
    {
        extraDataList.SetStringExtra(name);
    }
    return true;
}

struct SceneNode
{
    unsigned int FUN_0043b480();
    struct SceneChild* FUN_0043b4a0(unsigned int);
};
struct SceneChild
{
    bool FUN_00552470();
};
struct SceneController
{
    bool FUN_00552490();
    bool GetByteAtOffset8C();
};
struct SceneEntity
{
    virtual void UnkVirtual00();
    virtual void UnkVirtual01();
    virtual void UnkVirtual02();
    virtual void UnkVirtual03();
    virtual void UnkVirtual04();
    virtual void UnkVirtual05();
    virtual void UnkVirtual06();
    virtual void UnkVirtual07();
    virtual void UnkVirtual08();
    virtual void UnkVirtual09();
    virtual void UnkVirtual0a();
    virtual void UnkVirtual0b();
    virtual void UnkVirtual0c();
    virtual void UnkVirtual0d();
    virtual void UnkVirtual0e();
    virtual void UnkVirtual0f();
    virtual void UnkVirtual10();
    virtual void UnkVirtual11();
    virtual void UnkVirtual12();
    virtual void UnkVirtual13();
    virtual void UnkVirtual14();
    virtual void UnkVirtual15();
    virtual void UnkVirtual16();
    virtual void UnkVirtual17();
    virtual void UnkVirtual18();
    virtual void UnkVirtual19();
    virtual void UnkVirtual1a();
    virtual void UnkVirtual1b();
    virtual void UnkVirtual1c();
    virtual void UnkVirtual1d();
    virtual void UnkVirtual1e();
    virtual void UnkVirtual1f();
    virtual void UnkVirtual20();
    virtual void UnkVirtual21();
    virtual void UnkVirtual22();
    virtual void UnkVirtual23();
    virtual void UnkVirtual24();
    virtual void UnkVirtual25();
    virtual void UnkVirtual26();
    virtual void UnkVirtual27();
    virtual void UnkVirtual28();
    virtual void UnkVirtual29();
    virtual void UnkVirtual2a();
    virtual void UnkVirtual2b();
    virtual void UnkVirtual2c();
    virtual void UnkVirtual2d();
    virtual void UnkVirtual2e();
    virtual void UnkVirtual2f();
    virtual void UnkVirtual30();
    virtual void UnkVirtual31();
    virtual void UnkVirtual32();
    virtual void UnkVirtual33();
    virtual void UnkVirtual34();
    virtual void UnkVirtual35();
    virtual void UnkVirtual36();
    virtual void UnkVirtual37();
    virtual void UnkVirtual38();
    virtual void UnkVirtual39();
    virtual void UnkVirtual3a();
    virtual void UnkVirtual3b();
    virtual void UnkVirtual3c();
    virtual void UnkVirtual3d();
    virtual void UnkVirtual3e();
    virtual void UnkVirtual3f();
    virtual bool IsEligibleForUpdate();
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2c;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3c;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4c;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5c;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6c;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7c;
    void* unk80;
    void* unk84;
    void* unk88;
    void* unk8c;
    void* unk90;
    void* unk94;
    void* unk98;
    void* unk9c;
    void* unka0;
    void* unka4;
    void* unka8;
    SceneController* controller;
    bool FUN_00933840();
};
SceneEntity* __cdecl FUN_0056f930(SceneChild*);
void __cdecl SetTlsValueAndReset(SceneChild*, int);
// Iterates the node's children; for each eligible entity whose controller passes the checks, calls SetTlsValueAndReset with 2.
// @fnv 0x00552390
void __cdecl FUN_00552390(SceneNode* root)
{
    for (unsigned int index = 0; index < root->FUN_0043b480(); ++index)
    {
        SceneChild* child = root->FUN_0043b4a0(index);
        if (child != 0)
        {
            SceneEntity* entity = FUN_0056f930(child);
            if (entity != 0 && entity->IsEligibleForUpdate())
            {
                SceneEntity* candidate = entity;
                if (candidate->controller != 0 && candidate->controller->FUN_00552490() &&
                    !candidate->controller->GetByteAtOffset8C() && !child->FUN_00552470() && !candidate->FUN_00933840())
                {
                    SetTlsValueAndReset(child, 2);
                }
            }
        }
    }
}

struct Guard
{
    void* m_ptr;
    Guard(void* param);
    ~Guard();
};

struct LockA
{
    void Acquire(int mode);
    void Release();
};

struct Owner
{
    void Method(Guard* guard);
};

extern LockA DAT_011ca1a0;
extern Owner DAT_011ca174;

Guard::Guard(void* param)
{}
Guard::~Guard()
{}

// Acquires DAT_011ca1a0, calls DAT_011ca174.Method with a Guard wrapping param, then releases the lock.
// @fnv 0x005524f0
void __cdecl RunWithLock(void* param)
{
    DAT_011ca1a0.Acquire(0);
    {
        Guard guard(param);
        DAT_011ca174.Method(&guard);
    }
    DAT_011ca1a0.Release();
}

struct FUN_005526b0_cls
{
    int unk00;
    void Helper(unsigned int flags);
    void FUN_005526b0();
};

// @fnv 0x005526b0
void FUN_005526b0_cls::FUN_005526b0()
{
    Helper(0x400000);
}

struct FUN_00552840_local
{
    FUN_00552840_local(float f, int i, int j);
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};

struct FUN_00552840_obj
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0(FUN_00552840_local* p);
};

struct FUN_00552840_iter
{
    void* Head();
    int Advance(void** cur, unsigned int* x5, FUN_00552840_obj** x1c);
};

struct FUN_00552840_holder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    FUN_00552840_iter m_iter;
};

FUN_00552840_obj* __fastcall FUN_005497a0(void* pThis);
FUN_00552840_obj* __fastcall FUN_009611e0(FUN_00552840_obj* p);

struct FUN_00552840_cls
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
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    FUN_00552840_holder* m_c4;
    void FUN_00552840();
};

// @fnv 0x00552840
void FUN_00552840_cls::FUN_00552840()
{
    FUN_00552840_local zeroArg(0.0f, 0, 0);
    FUN_00552840_obj* a = FUN_005497a0(this);
    if (a != 0)
    {
        a->vfn_c0(&zeroArg);
    }
    if (m_c4 != 0)
    {
        void* cur = m_c4->m_iter.Head();
        while (cur != 0)
        {
            unsigned int x5 = 0;
            FUN_00552840_obj* x1c = 0;
            m_c4->m_iter.Advance(&cur, &x5, &x1c);
            if (x1c != 0 && FUN_009611e0(x1c) != a)
            {
                x1c->vfn_c0(&zeroArg);
            }
        }
    }
}

struct CellTarget;
struct FinalActor
{
    virtual void unk000();
    virtual void unk004();
    virtual void unk008();
    virtual void unk00c();
    virtual void unk010();
    virtual void unk014();
    virtual void unk018();
    virtual void unk01c();
    virtual void unk020();
    virtual void unk024();
    virtual void unk028();
    virtual void unk02c();
    virtual void unk030();
    virtual void unk034();
    virtual void unk038();
    virtual void unk03c();
    virtual void unk040();
    virtual void unk044();
    virtual void unk048();
    virtual void unk04c();
    virtual void unk050();
    virtual void unk054();
    virtual void unk058();
    virtual void unk05c();
    virtual void unk060();
    virtual void unk064();
    virtual void unk068();
    virtual void unk06c();
    virtual void unk070();
    virtual void unk074();
    virtual void unk078();
    virtual void unk07c();
    virtual void unk080();
    virtual void unk084();
    virtual void unk088();
    virtual void unk08c();
    virtual void unk090();
    virtual void unk094();
    virtual void unk098();
    virtual void unk09c();
    virtual void unk0a0();
    virtual void unk0a4();
    virtual void unk0a8();
    virtual void unk0ac();
    virtual void unk0b0();
    virtual void unk0b4();
    virtual void unk0b8();
    virtual void unk0bc();
    virtual void unk0c0();
    virtual void unk0c4();
    virtual void unk0c8();
    virtual void unk0cc();
    virtual void unk0d0();
    virtual void unk0d4();
    virtual void unk0d8();
    virtual void unk0dc();
    virtual void unk0e0();
    virtual void unk0e4();
    virtual void Finalize(void*);
};
struct WorldManager552
{
    void FUN_00445670(CellTarget*);
    void FUN_00452e50();
    void FUN_00454c20(CellTarget*);
    void FUN_00455130(CellTarget*);
    FinalActor* FUN_0084e3a0();
};
extern WorldManager552* DAT_011c3b3c;
extern WorldManager552* DAT_011dea10;
struct State552
{
    bool GetUnk26();
};
extern State552* DAT_011de134;
struct Checker552
{
    bool FUN_00469860(int);
};
extern Checker552* DAT_011c3f2c;
struct Updater552
{
    void FUN_0084a7c0(CellTarget*);
};
extern Updater552* DAT_011ddf38;
struct Portal552
{
    void FUN_00c5ba50(void*);
};
struct Temp552
{
    void UpdateChildByKey();
};
Temp552* __stdcall FUN_00552ba0(CellTarget*);
struct CellTarget
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    char unkd0;
    bool loaded;
    void CellRefLockEnter();
    void CellRefLockLeave();
    int GetByteAtOffset38();
    void SetState(int);
    void FUN_00557c40();
    void FUN_0054ba80(int);
    bool FUN_00425fd0();
    void UpdateCell();
    void FUN_005577b0(int);
    void* GetOrCreateWidget();
    void ProcessPerkEntries();
    void FUN_005576c0();
    void FUN_0054af40(bool);
    void FUN_00546c70();
    void FUN_0054b950(bool);
    int FUN_0084e3a0();
    Portal552* FUN_009d9f20();
    void* FUN_0054aa60();
    void* FUN_0054a050();
    void* FUN_00456fc0(int);
    void* FUN_00524cf0();
    void FUN_00552bd0(bool);
};
// @fnv 0x00552bd0
void CellTarget::FUN_00552bd0(bool reset)
{
    CellRefLockEnter();
    int p = GetByteAtOffset38();
    if (p == 6 || p == 5)
    {
        SetState(4);
        FUN_00557c40();
        DAT_011c3b3c->FUN_00445670(this);
        DAT_011dea10->FUN_00452e50();
        FUN_0054ba80(0);
        if (FUN_00425fd0())
            DAT_011dea10->FUN_00454c20(this);
        else
            DAT_011dea10->FUN_00455130(this);
        if (reset)
            UpdateCell();
        FUN_005577b0(0);
        void* h = GetOrCreateWidget();
        DAT_011dea10->FUN_0084e3a0()->Finalize(h);
        ProcessPerkEntries();
        FUN_005576c0();
        SetState(3);
        loaded = true;
        if (!DAT_011de134->GetUnk26())
            FUN_0054af40(true);
        FUN_00546c70();
        FUN_0054b950(false);
        FUN_00552ba0(this)->UpdateChildByKey();
        if (DAT_011c3f2c->FUN_00469860(FUN_0084e3a0()))
            DAT_011ddf38->FUN_0084a7c0(this);
        DAT_011dea10->FUN_00452e50();
        Portal552* a = FUN_009d9f20();
        a->FUN_00c5ba50(FUN_0054aa60());
        a->FUN_00c5ba50(FUN_0054a050());
        a->FUN_00c5ba50(FUN_00456fc0(2));
        a->FUN_00c5ba50(FUN_00524cf0());
    }
    CellRefLockLeave();
}

class NiPick;
bool __cdecl FUN_004b2780(NiPick* pick, int a2, int a3, float a4, NiAVObject* node, bool a6);

struct FUN_00553d00_shell : public TESObjectCELL
{
    bool PickChildNodes(NiPick* pick, int a2, int a3, float a4, char mask);
    NiAVObject* ChildNodeAt(int index);
};

// Tests the pick against child nodes 0-4 and 7 of the cell according to the mask bits, returning true if any test succeeds.
// @fnv 0x00553d00
bool FUN_00553d00_shell::PickChildNodes(NiPick* pick, int a2, int a3, float a4, char mask)
{
    bool result = false;
    if (pick && mask)
    {
        bool bA = (mask & 1) ? true : false;
        bool bB = (mask & 2) ? true : false;
        bool b4 = (mask & 4) ? true : false;
        bool b8 = (mask & 8) ? true : false;
        bool bHitDetected = (mask & 0x10) ? true : false;
        if (bA)
        {
            if (FUN_004b2780(pick, a2, a3, a4, ChildNodeAt(0), false))
                result = true;
        }
        if (bB)
        {
            if (FUN_004b2780(pick, a2, a3, a4, ChildNodeAt(1), false))
                result = true;
        }
        if (b4)
        {
            if (FUN_004b2780(pick, a2, a3, a4, ChildNodeAt(2), false))
                result = true;
        }
        if (b8)
        {
            if (FUN_004b2780(pick, a2, a3, a4, ChildNodeAt(3), false))
                result = true;
        }
        if (bHitDetected)
        {
            if (FUN_004b2780(pick, a2, a3, a4, ChildNodeAt(4), false))
                result = true;
        }
        if (b8 || bHitDetected)
        {
            if (FUN_004b2780(pick, a2, a3, a4, ChildNodeAt(7), false))
                result = true;
        }
    }
    return result;
}

struct AVObj557;
struct Node557;
struct Form557;
struct Stat557;

struct AVObj557
{
    void FUN_00450f90(bool value);
};

struct Node557
{
    unsigned int FUN_0043b480();
    AVObj557* FUN_0043b4a0(unsigned int index);
};

struct Form557
{
    unsigned int FNV_GetFormType();
};

struct RefVTable_1d0
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
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
    virtual AVObj557* Get3D();
};

struct Ref557 : RefVTable_1d0
{
    Form557* GetBaseForm();
};

Ref557* FUN_0056f930(AVObj557* object);

extern Stat557* DAT_011ca234;

struct CellStub
{
    Node557* GetCellChildAt(int index);
    void FUN_00557990(bool show, int type);
};

// @fnv 0x00557990
void CellStub::FUN_00557990(bool show, int type)
{
    Node557* node = GetCellChildAt(7);
    if (node)
    {
        for (unsigned int i = 0; i < node->FUN_0043b480(); i++)
        {
            AVObj557* child = node->FUN_0043b4a0(i);
            if (child)
            {
                Node557* subNode = (Node557*)child;
                for (unsigned int j = 0; j < subNode->FUN_0043b480(); j++)
                {
                    child = subNode->FUN_0043b4a0(j);
                    if (child)
                    {
                        Ref557* ref = FUN_0056f930(child);
                        if (ref)
                        {
                            bool handled = false;
                            switch (type)
                            {
                            case 4: {
                                Form557* pBaseForm = ref->GetBaseForm();
                                if (pBaseForm->FNV_GetFormType() != 0x1e && pBaseForm != (Form557*)DAT_011ca234)
                                {
                                    ref->Get3D()->FUN_00450f90(show);
                                }
                                break;
                            }
                            }
                        }
                    }
                }
            }
        }
    }
}

extern float DAT_0118b694;
extern void* DAT_011dea3c;

struct FUN_00557c40_vt
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void* v04();
};

struct FUN_00557c40_cls
{
    char pad000[0xc8];
    float unkC8;
    unsigned char unkCC;
    unsigned char unkCD;
    unsigned char unkCE;
    unsigned char unkCF;
    unsigned char unkD0;
    void* GetFirstNode();
    void ResetA();
    void ResetB();
    void FUN_00557c40();
};

void* __fastcall Node_ItemRef(void* node);
void* __fastcall Node_Next(void* node);
FUN_00557c40_vt* __fastcall Item_Get(void* item);
int __fastcall Obj_Query(void* obj);
void __fastcall Obj_Process(void* obj);

// Resets the object's fields, then walks its node list and processes each item whose object query returns 6, finally calling ResetB.
// @fnv 0x00557c40
void FUN_00557c40_cls::FUN_00557c40()
{
    if (unkCF != 0)
    {
        unkCF = 1;
    }
    unkCE = 0;
    unkC8 = DAT_0118b694;
    unkD0 = 0;
    ResetA();
    void* node = GetFirstNode();
    while (node != 0)
    {
        void* item = *(void**)Node_ItemRef(node);
        node = Node_Next(node);
        if (item != 0 && item != DAT_011dea3c)
        {
            FUN_00557c40_vt* p = (FUN_00557c40_vt*)Item_Get(item);
            if (p != 0)
            {
                void* r = p->v04();
                if (r != 0)
                {
                    if (Obj_Query(r) == 6)
                    {
                        Obj_Process(r);
                    }
                }
            }
        }
    }
    ResetB();
}

extern double DAT_01023128;

struct SpawnedVecA
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
    void FUN_006815c0();
    void FUN_00524ac0(float v);
};

struct SpawnedVecB
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
    void FUN_006815c0();
    void FUN_004a0c90(float v);
    void FUN_0043f8d0(void* out, void* in);
};

struct SpawnedVecC
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
};

unsigned char UpdateAndCheckBudget(int a1, int a2, void* c, int a3);

// @fnv 0x00558330
bool __cdecl FUN_00558330(int a1, int a2, int a3)
{
    bool ok5 = true;
    int i = 0x2d;
    int kTmp;
    int j_;
    SpawnedVecA a7;
    int m2;
    SpawnedVecB b_;
    SpawnedVecC c;
    for (kTmp = 0; kTmp < 3; kTmp++)
    {
        a7.FUN_006815c0();
        a7.FUN_00524ac0((float)(i * DAT_01023128));
        i -= 0x2d;
        j_ = 0;
        for (m2 = 0; m2 < 8; m2++)
        {
            b_.FUN_006815c0();
            b_.FUN_004a0c90((float)(j_ * DAT_01023128));
            j_ += 0x2d;
            b_.FUN_0043f8d0(&c, &a7);
            if (!UpdateAndCheckBudget(a1, a2, &c, a3))
            {
                ok5 = false;
            }
        }
    }
    return ok5;
}

namespace fnv_00558c30 {
struct Inner
{
    int m_iValue;
};

class Owner
{
  public:
    char m_00[0x64];
    Inner* m_pkInner;
    int GetInnerValue();
};

// Returns the inner object's value if the pointer is set, otherwise 0.
// @fnv 0x00558c30
int Owner::GetInnerValue()
{
    return m_pkInner ? m_pkInner->m_iValue : 0;
}
}  // namespace fnv_00558c30

struct FUN_00558f20_base
{
    virtual ~FUN_00558f20_base();
    int unk04;
};

struct FUN_00558f20_cls : FUN_00558f20_base
{
    virtual ~FUN_00558f20_cls();
    void Cleanup();
};

// @fnv 0x00558f20
FUN_00558f20_cls::~FUN_00558f20_cls()
{
    Cleanup();
}

struct Base_559020
{
    virtual ~Base_559020();
    int unk04;
    int unk08;
};

class FUN_00559020_cls : public Base_559020
{
  public:
    int unk0C;
    void FUN_00438af0();

    virtual ~FUN_00559020_cls();
};

// Destructor of FUN_00559020_cls that calls FUN_00438af0 before the base destructor runs.
// @fnv 0x00559020
FUN_00559020_cls::~FUN_00559020_cls()
{
    FUN_00438af0();
}

struct FUN_00559230
{
    virtual ~FUN_00559230();
};
struct FUN_005591d0 : FUN_00559230
{
    virtual ~FUN_005591d0();
    void FUN_00438af0();
};
// @fnv 0x005591d0
FUN_005591d0::~FUN_005591d0()
{
    FUN_00438af0();
}

struct FUN_005594e0_node
{
    FUN_005594e0_node* m_pkNext;
    unsigned int m_uiKey;
    void* m_pkValue;
};

struct FUN_005594e0_cls
{
    virtual void FUN_005594e0_v0();
    virtual unsigned int FUN_005594e0_hash(unsigned int key);
    virtual bool FUN_005594e0_match(unsigned int key, unsigned int nodeKey);
    virtual void FUN_005594e0_init(FUN_005594e0_node* node, unsigned int key, bool flag);
    virtual void FUN_005594e0_remove(FUN_005594e0_node* node);
    virtual FUN_005594e0_node* FUN_005594e0_alloc();
    unsigned int m_uiHashSize;
    FUN_005594e0_node** m_ppkHashTable;
    unsigned int m_uiCount;
    void FUN_005594e0(unsigned int key, bool flag);
};

// @fnv 0x005594e0
void FUN_005594e0_cls::FUN_005594e0(unsigned int key, bool flag)
{
    unsigned int index = FUN_005594e0_hash(key);
    FUN_005594e0_node* item = m_ppkHashTable[index];
    unsigned int n = 0;
    while (item != 0)
    {
        n++;
        if (FUN_005594e0_match(key, item->m_uiKey))
        {
            FUN_005594e0_remove(item);
            FUN_005594e0_init(item, key, flag);
            return;
        }
        item = item->m_pkNext;
    }
    item = FUN_005594e0_alloc();
    FUN_005594e0_init(item, key, flag);
    item->m_pkNext = m_ppkHashTable[index];
    m_ppkHashTable[index] = item;
    m_uiCount++;
}

namespace fnv_00585e00 {
struct LinkOwner
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4(int flag);
};

class LinkProbe
{
  public:
    void* Owner();
    LinkProbe* Find(int key);
    void Notify();
    void Push(int arg);
    unsigned int Value();
    unsigned char Check();
};

class LinkRegistry
{
  public:
    bool Test(unsigned int v);
};

class LinkSink
{
  public:
    void Store(int arg, int zero);
};

extern LinkProbe* DAT_011de45c;
extern LinkRegistry* DAT_011c3f2c;
extern LinkSink* DAT_011ddf38;

class FUN_00585e00_cls
{
  public:
    void FUN_00585e00(int arg);
    void Commit(int arg);
};

// @fnv 0x00585e00
void FUN_00585e00_cls::FUN_00585e00(int pProbe)
{
    LinkProbe* probe;
    LinkOwner* o3;
    int copy;
    if (pProbe != 0 && ((LinkProbe*)pProbe)->Owner() == this)
    {
        probe = ((LinkProbe*)pProbe)->Find(-1);
        if (probe == 0 || probe->Check())
        {
            ((LinkProbe*)pProbe)->Notify();
            DAT_011de45c->Push(pProbe);
            if (!DAT_011c3f2c->Test(((LinkProbe*)pProbe)->Value()))
            {
                DAT_011ddf38->Store(pProbe, 0);
            }
            this->Commit(pProbe);
            copy = pProbe;
            o3 = (LinkOwner*)copy;
            (o3 != 0) ? o3->v4(1) : 0;
        }
        else
        {
            ((LinkProbe*)pProbe)->Notify();
        }
    }
}
}  // namespace fnv_00585e00

class Base_b5143
{
  public:
    unsigned int m_00;
    ~Base_b5143();
};

class Sub_b5143
{
  public:
    unsigned int m_00;
    ~Sub_b5143();
};

class FUN_006208d0_cls : public Base_b5143
{
  public:
    Sub_b5143 m_04;
    ~FUN_006208d0_cls();
};

// Destructor for the class; destroys the embedded Sub_b5143 member and the base.
// @fnv 0x006208d0
FUN_006208d0_cls::~FUN_006208d0_cls()
{}

struct WorkerMobile
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
    virtual bool v63();
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
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual bool v152();
    bool FUN_00440d80();
    bool GetDisabled();
    void* FUN_008d8520();
    int FUN_00931850();
    void DeleteAndClear();
};
struct WorkerList
{
    WorkerMobile** FUN_006815c0();
    WorkerList* FUN_00726070();
};
struct WorkerLock
{
    bool FUN_0078d200();
    void Unlock();
};
extern WorkerLock DAT_011f11a0;
extern WorkerMobile* g_thePlayer;
struct WorkerQueue
{
    void FUN_0096aaf0(WorkerMobile*, int);
};
struct WorkerManager
{
    int unk00;
    WorkerQueue queue;
    void FUN_0096e870(WorkerMobile*);
    void ProcessWorkerList(WorkerList*, bool);
};
// @fnv 0x0096e150
void WorkerManager::ProcessWorkerList(WorkerList* pWorkerList, bool enabled)
{
    WorkerList* start = pWorkerList;
    while (pWorkerList && *pWorkerList->FUN_006815c0())
    {
        WorkerMobile* actor = 0;
        if ((*pWorkerList->FUN_006815c0())->v63())
            actor = *pWorkerList->FUN_006815c0();
        pWorkerList = pWorkerList->FUN_00726070();
        if (actor)
        {
            if (enabled)
            {
                if (actor->FUN_00440d80() || actor->GetDisabled())
                {
                    if (actor->FUN_008d8520() && DAT_011f11a0.FUN_0078d200())
                    {
                        queue.FUN_0096aaf0(actor, actor->FUN_00931850());
                        actor->DeleteAndClear();
                        DAT_011f11a0.Unlock();
                    }
                }
                else
                {
                    if (actor != g_thePlayer && actor->FUN_008d8520() && !actor->v152())
                        pWorkerList = start;
                }
            }
            else
            {
                FUN_0096e870(actor);
            }
        }
    }
}

struct TypeForm
{
    unsigned int FUN_00401170();
};
struct ReferenceView
{
    TypeForm* FUN_007af430();
    int FUN_00527080(int);
    int FUN_00568e50();
};
struct RefBucket
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    void FUN_00526bd0(ReferenceView*);
};
extern const char DAT_0102cf28[];
extern TypeForm* DAT_011ca264;
bool FUN_00481f30(unsigned char);
struct CollectionView
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    RefBucket all, unk30, unk48, doors, actors, special, animated;
    RefBucket* GetFieldByType(unsigned int);
    void FUN_00526f20(ReferenceView*);
};
// @fnv 0x00526f20
void CollectionView::FUN_00526f20(ReferenceView* reference)
{
    Local::AutoMemContext p((Local::MEM_CONTEXT)44, true, DAT_0102cf28, 104);
    unsigned int a = reference->FUN_007af430()->FUN_00401170();
    if (FUN_00481f30((unsigned char)a))
    {
        all.FUN_00526bd0(reference);
        RefBucket* bucket = GetFieldByType(a);
        if (bucket)
            bucket->FUN_00526bd0(reference);
    }
    if (a == 0x1b)
        doors.FUN_00526bd0(reference);
    if (a == 0x2a || a == 0x2b)
        actors.FUN_00526bd0(reference);
    if (reference->FUN_007af430() == DAT_011ca264)
        special.FUN_00526bd0(reference);
    if (a == 0x51 && reference->FUN_00527080(0x5d))
        special.FUN_00526bd0(reference);
    if (a == 0x1c && reference->FUN_00568e50())
        animated.FUN_00526bd0(reference);
}

struct CellBase
{
    virtual ~CellBase();
    int unk04, unk08, unk0c, unk10, unk14;
};
struct CellSecondary
{
    virtual ~CellSecondary();
    int unk1c, unk20, unk24;
};
struct OwnedLighting
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual ~OwnedLighting();
};
struct OwnedData
{
    ~OwnedData();
};
struct BoneTransformData
{
    virtual ~BoneTransformData();
    void Clear();
};
struct CellExtra
{
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44;
    ~CellExtra();
    BoneTransformData* GetScene();
};
struct CellList
{
    int unk58, unk5c;
    ~CellList();
};
struct CellLock
{
    int unkac, unkb0;
    ~CellLock();
};
struct CellRef
{
    int value;
    ~CellRef();
};
struct ParentWorld
{
    void Remove(void*);
};
struct GameState
{
    bool IsClosing();
};
void ReleaseCell(void*);
class FUN_00541810_cls : public CellBase, public CellSecondary
{
  public:
    virtual ~FUN_00541810_cls();
    CellExtra extra;
    int unk48;
    OwnedLighting* lighting;
    int unk50, unk54;
    CellList list;
    int unk60;
    OwnedData* data;
    int unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c;
    int unk90, unk94, unk98, unk9c, unka0, unka4, unka8;
    CellLock lock;
    CellRef refb4, refb8, refbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0;
    CellRef refd4;
    void Prepare();
    bool IsPersistent();
    void Clear();
    ParentWorld* GetWorld();
    void Finish();
    void Cleanup();
};
// Destructor: prepares, clears and frees lighting, data and scene unless persistent, removes from world, then finishes, releases and cleans up.
// @fnv 0x00541810
FUN_00541810_cls::~FUN_00541810_cls()
{
    Prepare();
    if (!IsPersistent())
    {
        Clear();
        if (lighting)
        {
            delete lighting;
            lighting = 0;
        }
        if (data)
        {
            delete data;
            data = 0;
        }
        BoneTransformData* scene = extra.GetScene();
        if (scene)
        {
            scene->Clear();
            delete scene;
        }
    }
    if (!reinterpret_cast<GameState*>(DAT_011c3f2c)->IsClosing())
    {
        ParentWorld* world = GetWorld();
        if (world)
            world->Remove(this);
    }
    Finish();
    ReleaseCell(this);
    Cleanup();
}

class LockedRef;
class LockHolder
{
  public:
    LockedRef* FUN_00559450();
    void FUN_0066b0d0(int flag);
};
class LockedRef
{
  public:
    void* FUN_00541c80();
};
class ObjBase
{
  public:
    virtual void* vScalarDelete(unsigned int flags);
    void NotifyListener(void* arg);
};

extern ObjBase* DAT_011ca088;
void __cdecl FUN_00541cd0();

// @fnv 0x00541c00
void __cdecl FUN_00541c00()
{
    if (DAT_011ca088 != 0)
    {
        DAT_011ca088->NotifyListener(reinterpret_cast<LockHolder*>(&g_011ca0d8)->FUN_00559450()->FUN_00541c80());
        ObjBase* a = DAT_011ca088;
        ObjBase* b5 = a;
        void* res3;
        if (b5 != 0)
        {
            res3 = b5->vScalarDelete(1);
        }
        else
        {
            res3 = 0;
        }
        DAT_011ca088 = 0;
    }
    reinterpret_cast<LockHolder*>(&g_011ca0d8)->FUN_0066b0d0(0);
    FUN_00541cd0();
}

struct SaveFile
{
    bool IsWritable();
};
struct SaveRef
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
    virtual bool Precedes(SaveRef* other);
    bool IsTemporary();
    bool IsDeleted();
    SaveFile* GetFile(int index);
    bool IsPersistent();
    bool IsSpecial();
    void Save(SaveFile* file);
};
struct RefNode
{
    bool Empty();
    SaveRef** Item();
    RefNode* Next();
};
struct RefArray
{
    unsigned int data, size, capacity, grow;
    RefArray(int initial, int mode);
    ~RefArray();
    void Reserve(int n);
    void Grow(int n);
    void Append(SaveRef** ref);
    void Compact();
    int Count();
    SaveRef** At(int index);
    void Set(int index, SaveRef** ref);
};
struct FUN_00542040_cls
{
    void Lock();
    RefNode* GetRefs();
    bool IsInterior();
    bool IsMode();
    void Unlock();
    void FUN_00542040(SaveFile* file);
};
// @fnv 0x00542040
void FUN_00542040_cls::FUN_00542040(SaveFile* file)
{
    RefArray refs(0, 1);
    refs.Reserve(50);
    refs.Grow(50);
    Lock();
    RefNode* node = GetRefs();
    while (node && !node->Empty())
    {
        SaveRef* ref = *node->Item();
        node = node->Next();
        bool aKeep = true;
        if (ref->IsTemporary())
            aKeep = false;
        if (ref->IsDeleted())
        {
            SaveFile* origin = ref->GetFile(0);
            if (origin && !origin->IsWritable())
                aKeep = false;
        }
        if (file != ref->GetFile(-1) && !ref->IsPersistent())
            aKeep = false;
        if (!IsInterior() && ref->IsSpecial() && !IsMode())
            aKeep = false;
        if (aKeep)
            refs.Append(&ref);
    }
    Unlock();
    refs.Compact();
    int count = refs.Count();
    for (int i = 0; i < count; ++i)
    {
        SaveRef* first = *refs.At(i);
        for (int j = i + 1; j < count; ++j)
        {
            SaveRef* second = *refs.At(j);
            if (second->Precedes(first))
            {
                refs.Set(i, &second);
                refs.Set(j, &first);
                first = second;
            }
        }
    }
    for (int k = 0; k < count; ++k)
    {
        SaveRef* entry = *refs.At(k);
        if (entry)
            entry->Save(file);
    }
}

extern int DAT_01183028;
extern int DAT_01183fb4;
void* __cdecl FNV_DynamicCast(void* obj, int vfDelta, void* srcType, void* dstType, int isRef);
void* __cdecl memcpy(void* dst, const void* src, unsigned int n);

struct CellDataBlock;
struct PtrPair
{
    void* first;
    void* second;
};
struct ExtraListPair
{
    void CopyList(ExtraListPair* other);
};
struct CellSubMember
{
    virtual void Reset();
    virtual void Clear();
    virtual void CopyFrom(CellSubMember* other);
};
struct CellLightingTemplate;

struct CellState
{
    int field00;
    int field04;
    int field08;
    int field0C;
    int field10;
    int field14;
    int field18;
    int field1C;
    int field20;
    int field24;
    int field28;
    int field2C;
    int field30;
    int field34;
    int field38;
    int field3C;
    int field40;
    int field44;
    CellDataBlock* cellData;
    int field4C;
    float field50;
    int field54;
    CellSubMember member58;
    int field5C;
    int field60;
    int field64;
    int field68;
    int field6C;
    int field70;
    int field74;
    int field78;
    int field7C;
    int field80;
    int field84;
    int field88;
    int field8C;
    int field90;
    int field94;
    int field98;
    int field9C;
    int fieldA0;
    int fieldA4;
    int fieldA8;
    int fieldAC;
    int fieldB0;
    int fieldB4;
    int fieldB8;
    int fieldBC;
    int fieldC0;
    int fieldC4;
    int fieldC8;
    int fieldCC;
    int fieldD0;
    int fieldD4;
    int fieldD8;
    unsigned int fieldDC;

    void FUN_004851b0(TESForm* form);
    ExtraListPair* GetExtraDataList();
    bool FUN_00425fd0();
    unsigned char GetField24();
    void SetByteAt24(unsigned int value);
    void ResetCellData();
    void* FUN_00544600();
    void* FUN_005445d0();
    CellLightingTemplate* GetLightingTemplate();
    void FUN_00558b60(void* value);
    unsigned int FUN_00497280();
    void CopyFromCell(TESForm* form);
};

// Casts form to a CellState and copies its data, lighting template, member58 and related fields into this CellState.
// @fnv 0x00543ab0
void CellState::CopyFromCell(TESForm* form)
{
    CellState* cell = (CellState*)FNV_DynamicCast(form, 0, (void*)&DAT_01183028, (void*)&DAT_01183fb4, 0);
    if (!cell)
        return;
    FUN_004851b0((TESForm*)cell);
    GetExtraDataList()->CopyList(cell->GetExtraDataList());
    if (FUN_00425fd0())
    {
        delete cellData;
    }
    else
    {
        delete cellData;
    }
    cellData = 0;
    SetByteAt24(cell->GetField24());
    field50 = cell->field50;
    ResetCellData();
    if (FUN_00425fd0())
    {
        PtrPair interior;
        interior.first = FUN_00544600();
        interior.second = cell->FUN_00544600();
        if (interior.first && interior.second)
            memcpy(interior.first, interior.second, 0x2c);
    }
    else
    {
        PtrPair exterior;
        exterior.first = FUN_005445d0();
        exterior.second = cell->FUN_005445d0();
        if (exterior.first && exterior.second)
            memcpy(exterior.first, exterior.second, 0x0c);
    }
    FUN_00558b60(cell->GetLightingTemplate());
    fieldDC = cell->FUN_00497280();
    member58.CopyFrom(&cell->member58);
}

template <class T> class NiPtr545
{
  public:
    T* m_pObject;
    NiPtr545(T* p);
    ~NiPtr545();
    operator T*() const;
};

struct AnimData545
{
    int FUN_00726070();
};
struct AnimNode545
{
    AnimData545* GetAnimationData();
};
struct MapKey545
{
    void FUN_00569990();
};

struct Map545
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* GetFirstPos();
    void GetNextPair(void*& pos, MapKey545*& key, NiPtr545<AnimNode545>& val);
};

struct Owner545;
struct Handler545
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
    virtual void Detach(Owner545* owner);
};
struct Owner545
{
    Handler545* GetHandler();
};

struct CellData545
{
    NiPtr545<Owner545> owner;
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
    Map545 map;
    BSSimpleList<int> list4C;
    BSSimpleList<int> list54;
    ~CellData545();
};

struct Cell545030
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
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    CellData545* pData;
    void Sub545c10();
    void ClearCellData();
};

// @fnv 0x00545030
void Cell545030::ClearCellData()
{
    if (pData)
    {
        pData->list4C.RemoveAll();
        pData->list54.RemoveAll();
        void* pos = pData->map.GetFirstPos();
        while (pos)
        {
            NiPtr545<AnimNode545> node(0);
            MapKey545* key = 0;
            pData->map.GetNextPair(pos, key, node);
            if (key && node)
            {
                AnimData545* pAnimData = ((AnimNode545*)node)->GetAnimationData();
                if (pAnimData->FUN_00726070() == 2)
                    key->FUN_00569990();
            }
        }
        if (pData->owner)
        {
            Sub545c10();
            Handler545* handler = ((Owner545*)pData->owner)->GetHandler();
            if (handler)
                handler->Detach(pData->owner);
        }
        delete pData;
        pData = 0;
    }
}

struct RefList;

struct FUN_00545670_vobj
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
    virtual void v13(unsigned int flags);
};

struct FUN_00545670_cls
{
    char pad[0xc4];
    char* m_c4;
    void FUN_00545670(void* obj);
};

// @fnv 0x00545670
void FUN_00545670_cls::FUN_00545670(void* pObject)
{
    if (m_c4 != 0)
    {
        ((RefList*)(m_c4 + 0x54))->FUN_00905330(reinterpret_cast<unsigned int&>(pObject));
    }
    ((FUN_00545670_vobj*)pObject)->v13(0x4000000);
}

extern void* __cdecl FUN_00aa13e0(unsigned int);
extern unsigned char __cdecl FUN_005468f0(int);
extern char DAT_011f426c, DAT_0102ed68, DAT_0102ed50;
struct FUN_00404eb0
{
    int m_uiContentCount;
    FUN_00404eb0(int, int, const void*, int);
    ~FUN_00404eb0();
};
struct Widget
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
    virtual void slot0a();
    virtual void slot0b();
    virtual void slot0c();
    virtual void slot0d();
    virtual void slot0e();
    virtual void slot0f();
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
    virtual void slot1a();
    virtual void slot1b();
    virtual void slot1c();
    virtual void slot1d();
    virtual void slot1e();
    virtual void slot1f();
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
    virtual void slot2a();
    virtual void slot2b();
    virtual void slot2c();
    virtual void slot2d();
    virtual void slot2e();
    virtual void slot2f();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void Attach(Widget*, int);
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
    void FUN_00440460(const void*);
    void FUN_0043fa80(const void*);
    void FUN_005467c0(int);
    void FUN_00546780(int);
    void SetTaskFlag(int);
    void FUN_005468d0(int);
    void FUN_00450f90(unsigned char);
    void FUN_00a59c60(const void*);
    void AssignFixedString(const void*);
};
struct FUN_00a5ecb0 : Widget
{
    FUN_00a5ecb0(int);
    static __forceinline void* operator new(unsigned int n)
    {
        return FUN_00aa13e0(n);
    }
    static void operator delete(void*, unsigned int);
};
struct FUN_00c46970 : Widget
{
    int unkac, unkb0;
    FUN_00c46970();
    void FUN_005468d0(int);
    void FUN_00439920(void*);
    static __forceinline void* operator new(unsigned int n)
    {
        return FUN_00aa13e0(n);
    }
    static void operator delete(void*, unsigned int);
};
struct FUN_00c35e00
{
    void* vfptr;
    int unk04, unk08, unk0c;
    FUN_00c35e00();
    void FUN_004addc0(void*);
    static __forceinline void* operator new(unsigned int n)
    {
        return FUN_00aa13e0(n);
    }
    static void operator delete(void*, unsigned int);
};
struct FUN_00c37ec0
{
    void* vfptr;
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    FUN_00c37ec0();
    static __forceinline void* operator new(unsigned int n)
    {
        return FUN_00aa13e0(n);
    }
    static void operator delete(void*, unsigned int);
};
struct WidgetSlot
{
    Widget* pointer;
    void FUN_0066b0d0(Widget*);
};
struct ManagerResult
{
    int unk00;
    void FUN_00546910(Widget*);
    int FUN_00546930();
};
struct GlobalManager
{
    unsigned char FUN_0042ce10();
    unsigned char FUN_004623f0(int);
    void FUN_00849b10(void*);
    unsigned char FUN_00546950();
    void ResetLoadBuffers(int);
};

struct ScaleVector
{
    float a, b, d;
    void FUN_0043d410(float, unsigned char = 0, unsigned char = 0);
};
struct TemporaryName
{
    int unk00;
    TemporaryName(const char*);
    ~TemporaryName();
};
struct FUN_00545cf0_Cls
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
    WidgetSlot m_mainB4;
    WidgetSlot m_secondaryB8;
    int unkBC, unkC0;
    WidgetSlot* m_parentC4;
    int unkC8, unkCC;
    unsigned char unkD0, m_enabledD1, unkD2, unkD3;
    Widget* FUN_00545cb0();
    void SetState(int);
    void FUN_00544ce0();
    void AttachOrphanedChildren();
    void FUN_00552dc0();
    ManagerResult* GetPortalGraph();
    Widget* GetOrCreateWidget();
};
// Returns the widget from FUN_00545cb0, building and attaching its child widgets if absent, then ensures a manager result item exists and returns the widget.
// @fnv 0x00545cf0
Widget* FUN_00545cf0_Cls::GetOrCreateWidget()
{
    Widget* a;
    FUN_00404eb0 b(0x1a, 1, &DAT_0102ed68, 0xd84);
    Widget* c;
    ManagerResult* d;
    ScaleVector e;
    a = FUN_00545cb0();
    if (!a)
    {
        SetState(2);
        m_enabledD1 = 0;
        a = new FUN_00a5ecb0(0);
        a->FUN_00440460(&DAT_011f426c);
        a->FUN_0043fa80(&DAT_011a9448);
        a->FUN_005467c0(1);
        a->FUN_00546780(1);
        Widget* current = new FUN_00a5ecb0(0);
        current->FUN_00546780(1);
        current->FUN_005467c0(1);
        current->FUN_00450f90(FUN_005468f0(0));
        a->Attach(current, 1);
        current = new FUN_00a5ecb0(0);
        current->FUN_00546780(1);
        current->FUN_005467c0(1);
        current->SetTaskFlag(1);
        current->FUN_00450f90(FUN_005468f0(1));
        a->Attach(current, 1);
        c = current;
        current = new FUN_00a5ecb0(0);
        current->FUN_00546780(1);
        current->FUN_005467c0(1);
        current->FUN_00450f90(FUN_005468f0(9));
        c->Attach(current, 1);
        m_mainB4.FUN_0066b0d0(current);
        current = new FUN_00a5ecb0(0);
        current->FUN_00546780(1);
        current->FUN_005467c0(1);
        current->FUN_00450f90(FUN_005468f0(10));
        c->Attach(current, 1);
        m_secondaryB8.FUN_0066b0d0(current);
        current = new FUN_00a5ecb0(0);
        current->FUN_00546780(1);
        current->FUN_005467c0(1);
        current->FUN_00450f90(FUN_005468f0(2));
        a->Attach(current, 1);
        for (int i = 0; i < 4; ++i)
        {
            FUN_00c46970* pConfigWidget = new FUN_00c46970();
            pConfigWidget->FUN_005468d0(1);
            FUN_00c35e00* page = new FUN_00c35e00();
            FUN_00c37ec0* list = new FUN_00c37ec0();
            page->FUN_004addc0(list);
            pConfigWidget->FUN_00439920(page);
            current->Attach(pConfigWidget, 1);
        }
        current = new FUN_00a5ecb0(0);
        current->FUN_00546780(1);
        current->FUN_005467c0(1);
        current->FUN_00450f90(FUN_005468f0(3));
        a->Attach(current, 1);
        current = new FUN_00a5ecb0(0);
        current->FUN_00546780(1);
        current->FUN_005467c0(1);
        current->FUN_00450f90(0);
        a->Attach(current, 1);
        current = new FUN_00a5ecb0(0);
        current->FUN_00546780(1);
        current->FUN_005467c0(1);
        current->FUN_00450f90(FUN_005468f0(5));
        a->Attach(current, 1);
        current = new FUN_00a5ecb0(0);
        current->FUN_00546780(1);
        current->FUN_005467c0(1);
        current->FUN_00450f90(FUN_005468f0(6));
        a->Attach(current, 1);
        current = new FUN_00a5ecb0(0);
        current->FUN_00546780(1);
        current->FUN_005467c0(1);
        current->FUN_00450f90(FUN_005468f0(7));
        a->Attach(current, 1);
        a->Attach(current, 1);
        current = new FUN_00a5ecb0(0);
        current->FUN_00546780(1);
        current->FUN_005467c0(1);
        current->FUN_00450f90(FUN_005468f0(8));
        a->Attach(current, 1);
        a->Attach(current, 1);

        e.FUN_0043d410(0.0f);
        a->FUN_00a59c60(&e);
        FUN_00544ce0();
        m_parentC4->FUN_0066b0d0(a);
        AttachOrphanedChildren();
        FUN_00552dc0();
        if (!((GlobalManager*)DAT_011ddf38)->FUN_0042ce10())
        {
            unsigned char saved = ((GlobalManager*)DAT_011ddf38)->FUN_004623f0(0);
            ((GlobalManager*)DAT_011ddf38)->FUN_00849b10(this);
            if (!((GlobalManager*)DAT_011ddf38)->FUN_00546950())
                ((GlobalManager*)DAT_011ddf38)->ResetLoadBuffers(0);
            ((GlobalManager*)DAT_011ddf38)->FUN_004623f0(saved);
        }
        SetState(3);
    }
    d = GetPortalGraph();
    if (!d->FUN_00546930())
    {
        Widget* item = new FUN_00a5ecb0(0);
        item->AssignFixedString(&TemporaryName(&DAT_0102ed50));
        d->FUN_00546910(item);
    }

    return a;
}

struct CellInput
{
    bool FUN_00425fd0();
    ExtraDataList* GetExtraDataList();
};
struct FUN_00438170
{
    unsigned int field00;
    FUN_00438170(const char*);
    ~FUN_00438170();
};
void* __cdecl FUN_004bc3f0();
NiRenderer* __cdecl FUN_0043c4b0();
void* __cdecl FUN_00a7fc00(const FUN_00438170&, int, int, void*, void*, int, int, int);
extern bool DAT_011f4ac0;
extern int DAT_011ab3c8;
extern bool DAT_011ab3c4;
extern int DAT_011ab3cc;
extern const char str_0102edac[];
struct LockedRect
{
    int field00;
    char* field04;
};
struct ExtraOut
{
    void FUN_0041c490(bool, void*, LockedRect**);
};
struct DeviceTexture
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
    virtual int __stdcall LockRect(int, LockedRect*, void*, int);
};
struct RenderData
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
    virtual int GetHeight();
    virtual DeviceTexture* GetTexture();
    RenderData* FUN_0059bb30();
};
// @fnv 0x00547830
int __cdecl CreateAndClearRenderTarget(CellInput* cell, RenderData** ppOutput, LockedRect** ppLockedRect)
{
    *ppOutput = 0;
    if (!cell || cell->FUN_00425fd0() || !FUN_004bc3f0())
        return false;
    DAT_011f4ac0 = true;
    DAT_011ab3c8 = 50;
    DAT_011ab3c4 = false;
    *ppOutput = (RenderData*)FUN_00a7fc00(FUN_00438170(str_0102edac), 64, 64, FUN_0043c4b0(), &DAT_011ab3cc, 0, 0, 0);
    DAT_011f4ac0 = false;
    DAT_011ab3c4 = true;
    ((ExtraOut*)cell->GetExtraDataList())->FUN_0041c490(true, *ppOutput, ppLockedRect);
    RenderData* data2 = (*ppOutput)->FUN_0059bb30();
    DeviceTexture* texture4 = data2->GetTexture();
    texture4->LockRect(0, *ppLockedRect, 0, 0);
    int count3 = (*ppLockedRect)->field00 * (*ppOutput)->GetHeight();
    char* pixels2 = (*ppLockedRect)->field04;
    for (int i2 = 0; i2 < count3; ++i2)
        pixels2[i2] = 0;
    return 1;
}

class C5479C0WorldSpace;

struct C5479C0Grid
{
    int unk00;
    unsigned char* m_pcData;
};

class C5479C0Renderer
{
  public:
    virtual void VFunc00();
    virtual void VFunc04();
    virtual void VFunc08();
    virtual void VFunc0C();
    virtual void VFunc10();
    virtual void VFunc14();
    virtual void VFunc18();
    virtual void VFunc1C();
    virtual void VFunc20();
    virtual void VFunc24();
    virtual void VFunc28();
    virtual void VFunc2C();
    virtual void VFunc30();
    virtual void VFunc34();
    virtual void VFunc38();
    virtual void VFunc3C();
    virtual void VFunc40();
    virtual void VFunc44();
    virtual void VFunc48();
    virtual void __stdcall Attach(int iArg1, C5479C0Grid* pkGrid, int iArg2, int iArg3);
};

class C5479C0Object3D
{
  public:
    virtual void VFunc00();
    virtual void VFunc04();
    virtual void VFunc08();
    virtual void VFunc0C();
    virtual void VFunc10();
    virtual void VFunc14();
    virtual void VFunc18();
    virtual void VFunc1C();
    virtual void VFunc20();
    virtual void VFunc24();
    virtual void VFunc28();
    virtual void VFunc2C();
    virtual void VFunc30();
    virtual void VFunc34();
    virtual void VFunc38();
    virtual void VFunc3C();
    virtual void VFunc40();
    virtual void VFunc44();
    virtual void VFunc48();
    virtual void VFunc4C();
    virtual void VFunc50();
    virtual void VFunc54();
    virtual void VFunc58();
    virtual void VFunc5C();
    virtual void VFunc60();
    virtual void VFunc64();
    virtual void VFunc68();
    virtual void VFunc6C();
    virtual void VFunc70();
    virtual void VFunc74();
    virtual void VFunc78();
    virtual void VFunc7C();
    virtual void VFunc80();
    virtual void VFunc84();
    virtual void VFunc88();
    virtual void VFunc8C();
    virtual void VFunc90();
    virtual void VFunc94();
    virtual void VFunc98();
    virtual C5479C0Renderer* GetRenderer();
};

class C5479C0Land
{
  public:
    C5479C0Object3D* Get3D();
};

class C5479C0List
{
  public:
    void FindLand(C5479C0Land** ppkLand, C5479C0Grid** ppkGrid);
};

class C5479C0Cell
{
  public:
    C5479C0List* GetLandList();
};

class C5479C0DataHandler
{
  public:
    C5479C0Cell* GetContainingCell(int iX, int iY, C5479C0WorldSpace* pkWorldSpace, bool bLoad);
};

extern C5479C0DataHandler* g_pk5479C0DataHandler;

void __cdecl C5479C0CreateLand(C5479C0Cell* pkTargetCell, C5479C0Land** ppkLand, C5479C0Grid** ppkGrid);

class C5479C0Manager
{
  public:
    C5479C0WorldSpace* GetParentWorldSpace();

    void SetGridDataByte(int iX, int iY, C5479C0Grid** ppkGrid, int iIndex, unsigned char ucValue);
};

// @fnv 0x005479c0
void C5479C0Manager::SetGridDataByte(int iX, int iY, C5479C0Grid** ppkGrid, int iIndex, unsigned char ucValue)
{
    C5479C0Cell* pkTargetCell = 0;
    unsigned char* pcData = 0;
    C5479C0Land* pkL = 0;

    if (!*ppkGrid)
    {
        pkTargetCell = g_pk5479C0DataHandler->GetContainingCell(iX, iY, GetParentWorldSpace(), false);
        if (pkTargetCell)
        {
            pkTargetCell->GetLandList()->FindLand(&pkL, ppkGrid);
            if (!pkL)
                C5479C0CreateLand(pkTargetCell, &pkL, ppkGrid);
        }
        else
        {
            return;
        }
    }

    if (*ppkGrid)
    {
        if (!(*ppkGrid)->m_pcData)
        {
            C5479C0Object3D* pk3D = pkL->Get3D();
            C5479C0Renderer* pkRenderer = pk3D->GetRenderer();
            pkRenderer->Attach(0, *ppkGrid, 0, 0);
        }
        pcData = (*ppkGrid)->m_pcData;
        if (pcData[iIndex])
            pcData[iIndex] = 0xff;
        else
            pcData[iIndex] = ucValue;
    }
}

namespace fnv_005497c0 {
struct NiBound
{
    char pad[0x10];
};
struct FUN_006815c0
{
    void* _ref_006815c0();
};

struct Inner52
{
    int d0, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12;
};
struct FUN_0045c620
{
    FUN_0045c620();
    int pad00[27];
    Inner52 arr;
    unsigned char t0;
    unsigned char t1;
    unsigned char t2;
    unsigned char flagA3;
    void* iter;
};

struct ItemObj
{
    bool FUN_00c34890(void* bound);
};
struct VObj
{
    virtual void vph0();
    virtual void vph1();
    virtual void vph2();
    virtual void vph3();
    virtual void vph4();
    virtual void vph5();
    virtual void vph6();
    virtual void vph7();
    virtual void vph8();
    virtual void vph9();
    virtual void vph10();
    virtual void vph11();
    virtual void vph12();
    virtual void vph13();
    virtual void vph14();
    virtual void vph15();
    virtual void vph16();
    virtual void vph17();
    virtual void vph18();
    virtual void vph19();
    virtual void vph20();
    virtual void vph21();
    virtual void vph22();
    virtual void vph23();
    virtual void vph24();
    virtual void vph25();
    virtual void vph26();
    virtual void vph27();
    virtual void vph28();
    virtual void vph29();
    virtual void vph30();
    virtual void vph31();
    virtual void vph32();
    virtual void vph33();
    virtual void vph34();
    virtual void vph35();
    virtual void vph36();
    virtual void vph37();
    virtual void vph38();
    virtual void vph39();
    virtual void vph40();
    virtual void vph41();
    virtual void vph42();
    virtual void vph43();
    virtual void vph44();
    virtual void vph45();
    virtual void vph46();
    virtual void vph47();
    virtual void vph48();
    virtual void vph49();
    virtual void vph50();
    virtual void vph51();
    virtual void vph52();
    virtual void vph53();
    virtual void vph54();
    virtual void f_dc(void* b, int a);
    virtual void vph56();
    virtual void vph57();
    virtual void f_e8(void* b);
    virtual void vph59();
    virtual void vph60();
    virtual void vph61();
    virtual void vph62();
    virtual void vph63();
    virtual unsigned char f100();
    virtual void* f104();
    virtual unsigned char f108(NiPoint3* p);
    virtual void vph67();
    virtual int f110(void* b);
    void FUN_00c39a80(void* plane);
};
struct P2Obj;
struct AObj
{
    virtual void vph0();
    virtual void vph1();
    virtual void vph2();
    virtual void vph3();
    virtual void vph4();
    virtual void vph5();
    virtual void vph6();
    virtual void vph7();
    virtual void vph8();
    virtual void vph9();
    virtual void vph10();
    virtual void vph11();
    virtual void vph12();
    virtual void vph13();
    virtual void vph14();
    virtual void vph15();
    virtual void vph16();
    virtual void vph17();
    virtual void vph18();
    virtual void vph19();
    virtual void vph20();
    virtual void vph21();
    virtual void vph22();
    virtual void vph23();
    virtual void vph24();
    virtual void vph25();
    virtual void vph26();
    virtual void vph27();
    virtual void vph28();
    virtual void vph29();
    virtual void vph30();
    virtual void vph31();
    virtual void vph32();
    virtual void vph33();
    virtual void vph34();
    virtual void vph35();
    virtual void vph36();
    virtual void vph37();
    virtual void vph38();
    virtual void vph39();
    virtual void vph40();
    virtual void vph41();
    virtual void vph42();
    virtual void vph43();
    virtual void vph44();
    virtual void vph45();
    virtual void vph46();
    virtual void vph47();
    virtual void vph48();
    virtual void vph49();
    virtual void vph50();
    virtual void vph51();
    virtual void vph52();
    virtual void vph53();
    virtual void vph54();
    virtual void vph55();
    virtual void vph56();
    virtual void vph57();
    virtual void vph58();
    virtual void vph59();
    virtual void vph60();
    virtual void vph61();
    virtual void vph62();
    virtual void vph63();
    virtual unsigned char f100();
    virtual void vph65();
    virtual void vph66();
    virtual void vph67();
    virtual void vph68();
    virtual void vph69();
    virtual void vph70();
    virtual void vph71();
    virtual void vph72();
    virtual void vph73();
    virtual void vph74();
    virtual void vph75();
    virtual void vph76();
    virtual void vph77();
    virtual void vph78();
    virtual void vph79();
    virtual void vph80();
    virtual void vph81();
    virtual void vph82();
    virtual void vph83();
    virtual void vph84();
    virtual void vph85();
    virtual void vph86();
    virtual void vph87();
    virtual void vph88();
    virtual void vph89();
    virtual void vph90();
    virtual void vph91();
    virtual void vph92();
    virtual void vph93();
    virtual void vph94();
    virtual void vph95();
    virtual void vph96();
    virtual void vph97();
    virtual void vph98();
    virtual void vph99();
    virtual void vph100();
    virtual void vph101();
    virtual void vph102();
    virtual void vph103();
    virtual void vph104();
    virtual void vph105();
    virtual void vph106();
    virtual void vph107();
    virtual void vph108();
    virtual void vph109();
    virtual void vph110();
    virtual void vph111();
    virtual void vph112();
    virtual void vph113();
    virtual void vph114();
    virtual void vph115();
    virtual P2Obj* f1d0();
    void FUN_00569ae0(int a);
};
struct P2Obj
{
};
struct FUN_0043d450_Owner
{
    NiBound* FUN_0043d450();
};
struct FUN_009611e0_shell
{
    int FUN_009611e0();
};
struct CellMirror
{
    char pad00[0xc4];
    char* f_c4;
};
struct FGModelMap
{
    bool GetAt(void* a, GO& b);
};
class ActiveEffect;
struct NonActorMagicTarget
{
    virtual BSSimpleList<ActiveEffect*>* GetActiveEffectList();
};
class BSPortalGraph
{
  public:
    void FUN_00c5b1c0(P2Obj* p2);
    void FUN_00c5b370(P2Obj* p2);
};
struct HighActorCullerCell
{
    BSPortalGraph* FUN_009d9f20();
};
struct ArrHelper
{
    bool FUN_0076b610() const;
};
struct BSMultiBoundRoom
{
    void* FUN_006ab360();
};
struct TESObjectREFR_GetFlags_caller
{
    unsigned int CallGetFlags();
};
struct ListStandIn
{
    int* FUN_0057cbe0(int** iter);
};
struct SSNode
{
    bool FUN_00c33cf0(void* big, int z, NiPoint3 pt);
};
struct FUN_0045c4c0_cls
{
    unsigned int FUN_0045c4c0();
};

class AnimIdle;
template <> class NiPointer<AnimIdle>
{
  public:
    AnimIdle* m_pObject;
    NiPointer(AnimIdle* p);
    ~NiPointer();
    AnimIdle* operator->() const;
};

struct BSOcclusionPlane
{
    NiPoint3* FUN_00413f40();
};
struct FUN_00422120_shell
{
    BSOcclusionPlane* FUN_00422120();
};
ExtraDataList* __fastcall FUN_005d43c0(TESObjectREFR* p1);
int __fastcall FUN_00461130(int p2);
bool __cdecl FUN_008c7aa0();
void __cdecl FUN_0054abd0(AObj* p1, void* x);

struct FUN_005497c0_shell : public TESObjectCELL
{
    bool FUN_005497c0(AObj* p1, P2Obj* p2, int p3, unsigned char* p4, unsigned char p5);
};
// @fnv 0x005497c0
bool FUN_005497c0_shell::FUN_005497c0(AObj* apRefr, P2Obj* apTarget, int p3, unsigned char* apbHandled,
                                      unsigned char p5)
{
    VObj* kIter_;
    ItemObj* item;
    bool foundFirst9;
    bool foundSecond3;
    bool usePt;
    NiPoint3 point;
    BSPortalGraph* graphH;
    BSPortalGraph* graph;
    point = *(NiPoint3*)((FUN_006815c0*)((FUN_0043d450_Owner*)apTarget)->FUN_0043d450())->_ref_006815c0();
    usePt = false;
    if (((FUN_00422120_shell*)FUN_005d43c0((TESObjectREFR*)apRefr))->FUN_00422120() != 0)
    {
        point = *(NiPoint3*)((FUN_00422120_shell*)FUN_005d43c0((TESObjectREFR*)apRefr))->FUN_00422120()->FUN_00413f40();
        usePt = true;
    }
    NiPointer<AnimIdle> objTmp(0);
    ((FGModelMap*)(((CellMirror*)this)->f_c4 + 0x3c))->GetAt((void*)p3, *(GO*)&objTmp);
    if ((VObj*)(void*)objTmp.operator->() == 0 || ((VObj*)(void*)objTmp.operator->())->f104() == 0)
    {
        return false;
    }
    if (p5)
    {
        if (!((ArrHelper*)((NonActorMagicTarget*)((HighActorCullerCell*)this)->FUN_009d9f20())
                  ->NonActorMagicTarget::GetActiveEffectList())
                 ->FUN_0076b610())
        {
            if (!apRefr->f100())
            {
                graphH = ((HighActorCullerCell*)this)->FUN_009d9f20();
                graphH->FUN_00c5b1c0(apTarget);
                if (((FUN_009611e0_shell*)apTarget)->FUN_009611e0() != 0)
                {
                    if (!FUN_008c7aa0())
                    {
                        ((VObj*)(void*)((FUN_009611e0_shell*)apTarget)->FUN_009611e0())->f_e8(apTarget);
                    }
                    else
                    {
                        FUN_0054abd0(apRefr, 0);
                    }
                }
            }
            else
            {
                if (!FUN_008c7aa0())
                {
                    ((VObj*)(void*)((FUN_0054a050_shell*)this)->FUN_0054a050())->f_dc(apTarget, 1);
                }
                else
                {
                    FUN_0054abd0(apRefr, ((FUN_0054a050_shell*)this)->FUN_0054a050());
                }
            }
            *apbHandled = 1;
            return true;
        }
    }
    if ((VObj*)(void*)objTmp.operator->() != 0)
    {
        if (((VObj*)(void*)objTmp.operator->())->f108(&point) ||
            (p5 && ((VObj*)(void*)objTmp.operator->())->f110(((FUN_0043d450_Owner*)apTarget)->FUN_0043d450())))
        {
            apRefr->FUN_00569ae0(p3);
            if (p5)
            {
                if (*apbHandled)
                {
                    if (!apRefr->f100())
                    {
                        graph = ((HighActorCullerCell*)this)->FUN_009d9f20();
                        graph->FUN_00c5b1c0(apTarget);
                        if (((FUN_009611e0_shell*)apTarget)->FUN_009611e0() != 0)
                        {
                            if (!FUN_008c7aa0())
                            {
                                ((VObj*)(void*)((FUN_009611e0_shell*)apTarget)->FUN_009611e0())->f_e8(apTarget);
                            }
                            else
                            {
                                FUN_0054abd0(apRefr, 0);
                            }
                        }
                    }
                    else
                    {
                        if (!FUN_008c7aa0())
                        {
                            ((VObj*)(void*)((FUN_0054a050_shell*)this)->FUN_0054a050())->f_dc(apTarget, 1);
                        }
                        else
                        {
                            FUN_0054abd0(apRefr, ((FUN_0054a050_shell*)this)->FUN_0054a050());
                        }
                    }
                    return true;
                }
            }
            kIter_ = (VObj*)((VObj*)(void*)objTmp.operator->())->f104();
            if (usePt)
            {
                kIter_->FUN_00c39a80(((FUN_00422120_shell*)FUN_005d43c0((TESObjectREFR*)apRefr))->FUN_00422120());
                return true;
            }
            foundSecond3 = 0;
            foundFirst9 = 0;
            if (((TESObjectREFR_GetFlags_caller*)((BSMultiBoundRoom*)kIter_)->FUN_006ab360())->CallGetFlags() > 0)
            {
                FUN_0045c620 big4;
                big4.arr = *(Inner52*)FUN_00461130((int)apTarget);
                big4.flagA3 = 0;
                big4.iter = ((NiPointer<AnimIdle>*)((BSMultiBoundRoom*)kIter_)->FUN_006ab360())->operator->();
                item = 0;
                while (!!big4.iter)
                {
                    ItemObj* p = (ItemObj*)*(
                        ((ListStandIn*)((BSMultiBoundRoom*)kIter_)->FUN_006ab360())->FUN_0057cbe0((int**)&big4.iter));
                    if (p != 0)
                    {
                        bool found3 = false;
                        if (big4.flagA3)
                        {
                            found3 = ((SSNode*)p)->FUN_00c33cf0(&big4, 0, *(NiPoint3*)&_NiPoint3_ZERO);
                        }
                        else
                        {
                            found3 = p->FUN_00c34890(((FUN_0043d450_Owner*)apTarget)->FUN_0043d450());
                        }
                        if (found3)
                        {
                            if (foundFirst9 == 0)
                            {
                                item = p;
                                foundFirst9 = 1;
                            }
                            else
                            {
                                foundSecond3 = 1;
                                if (((FUN_009611e0_shell*)apTarget)->FUN_009611e0() !=
                                    (int)(void*)this->GetDynamicNode())
                                {
                                    if (!apRefr->f100())
                                    {
                                        if (!apRefr->f100())
                                        {
                                            BSPortalGraph* graph9 = ((HighActorCullerCell*)this)->FUN_009d9f20();
                                            graph9->FUN_00c5b1c0(apTarget);
                                            if (((FUN_009611e0_shell*)apTarget)->FUN_009611e0() != 0)
                                            {
                                                if (!FUN_008c7aa0())
                                                {
                                                    ((VObj*)(void*)((FUN_009611e0_shell*)apTarget)->FUN_009611e0())
                                                        ->f_e8(apTarget);
                                                }
                                                else
                                                {
                                                    FUN_0054abd0(apRefr, 0);
                                                }
                                            }
                                        }
                                        else
                                        {
                                            if (!FUN_008c7aa0())
                                            {
                                                ((VObj*)(void*)((FUN_0054a050_shell*)this)->FUN_0054a050())
                                                    ->f_dc(apTarget, 1);
                                            }
                                            else
                                            {
                                                FUN_0054abd0(apRefr, ((FUN_0054a050_shell*)this)->FUN_0054a050());
                                            }
                                        }
                                    }
                                }
                                break;
                            }
                        }
                    }
                }
                if (foundFirst9)
                {
                    if (!foundSecond3)
                    {
                        if (((FUN_009611e0_shell*)apRefr->f1d0())->FUN_009611e0() !=
                            (int)((FUN_0045c4c0_cls*)item)->FUN_0045c4c0())
                        {
                            {
                                BSPortalGraph* graph;
                                graph = ((HighActorCullerCell*)this)->FUN_009d9f20();
                                NiPointer<AnimIdle> obj2(0);
                                graph->FUN_00c5b370(apTarget);
                                if (!FUN_008c7aa0())
                                {
                                    ((VObj*)(void*)((FUN_0045c4c0_cls*)item)->FUN_0045c4c0())->f_dc(apTarget, 1);
                                }
                                else
                                {
                                    FUN_0054abd0(apRefr, (void*)((FUN_0045c4c0_cls*)item)->FUN_0045c4c0());
                                }
                            }
                        }
                    }
                }
            }
            if (!foundFirst9)
            {
                if (((FUN_009611e0_shell*)apTarget)->FUN_009611e0() != (int)(VObj*)(void*)objTmp.operator->())
                {
                    {
                        BSPortalGraph* graph;
                        graph = ((HighActorCullerCell*)this)->FUN_009d9f20();
                        NiPointer<AnimIdle> _obj3(0);
                        graph->FUN_00c5b370(apTarget);
                        if (!FUN_008c7aa0())
                        {
                            ((VObj*)(void*)objTmp.operator->())->f_dc(apTarget, 1);
                        }
                        else
                        {
                            FUN_0054abd0(apRefr, (VObj*)(void*)objTmp.operator->());
                        }
                    }
                }
            }
            *apbHandled = 1;
            if (!p5 || foundSecond3)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
endFalse:
    return false;
}
}  // namespace fnv_005497c0

struct Obj;
struct Ref;
struct Extra;
struct Plane;
struct Graph;
struct Obj
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
    virtual void Attach(Obj*, bool);
    virtual void v0e0();
    virtual void v0e4();
    virtual void Detach(Obj*);
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual Obj* IsSceneNode();
    Obj* Parent();
    Ref* Owner();
    void* FUN_0043d450();
};
struct Form
{
    unsigned int Type();
};
struct Ref
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
    virtual bool IsActor();
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
    virtual Obj* Get3D();
    Form* Base();
    Extra* Extras();
    Obj* PlayerNode();
    bool Test(Ref*);
    bool Test2(Ref*);
    Extra* OtherExtras();
    void Update(Ref*);
};
struct Plane
{
    bool FUN_00c34890(void*);
    Obj* FUN_0045c4c0();
};
struct Link
{
    Ref** Item();
    Link* Next();
};
struct Extra
{
    Ref* Linked();
    Link* Links();
    Ref* Select(bool);
    Plane* FUN_00422120();
    Obj* Find(Ref*);
};
struct Ptr
{
    Obj* ptr;
    Ptr(Obj*);
    ~Ptr();
    operator Obj*() const;
    Ptr& operator=(Obj*);
};
struct VisitMap
{
    virtual ~VisitMap();
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    VisitMap(unsigned int, bool);
    void FUN_005594e0(Ref*, bool);
    bool FUN_0057c850(Ref*, bool*);
};

struct Map
{
    void* First();
    void Next(void*&, Ref*&, Ptr&);
};
struct Loaded
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    Map map;
};
struct List
{
    operator void*() const;
    Plane*& FUN_0057cbe0(void*&);
};
struct Graph
{
    List* FUN_007d6bb0();
    void FUN_00c5b1c0(Obj*);
    void Add(Obj*);
    void FUN_00c5ae70(Plane*);
};
struct Task
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    Task(Ref*, Obj*);
};
struct Manager
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
    virtual void Queue(Task*);
};
struct Settings
{
    bool Enabled();
};
extern Settings settings;
extern Form* markerA;
extern Form* markerB;
extern Ref* player;
extern Manager* manager;
struct Pending
{
    void Add(Ref*, Ref*);
};
extern Pending pending;
bool FUN_008c7aa0();
void FUN_0054abd0(Ref*, Obj*);
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
struct Cell
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    int f44;
    int f48;
    int f4c;
    int f50;
    int f54;
    int f58;
    int f5c;
    int f60;
    int f64;
    int f68;
    int f6c;
    int f70;
    int f74;
    int f78;
    int f7c;
    int f80;
    int f84;
    int f88;
    int f8c;
    int f90;
    int f94;
    int f98;
    int f9c;
    int fa0;
    int fa4;
    int fa8;
    int fac;
    int fb0;
    int fb4;
    int fb8;
    int fbc;
    int fc0;
    Loaded* loaded;
    Obj* Dynamic();
    Graph* GraphA();
    Graph* GraphB();
    Obj* FUN_0054a050();
    Obj* FUN_0054aa60();
    bool Try(Ref*, Obj*, Ref*, bool*, bool);
    void UpdateRefPlacement(Ref*, bool, bool);
};

// Checks the reference against markers and settings, tries linked and map nodes to attach its 3D, and falls back to graph planes or default nodes.
// @fnv 0x0054a070
void Cell::UpdateRefPlacement(Ref* ref, bool force, bool skip)
{
    if (!ref || !ref->Get3D())
        return;
    if (ref->Base() == markerA || ref->Base() == markerB || ref->Get3D()->Parent() == Dynamic())
        return;
    bool enabled = false;
    bool foundUnused = false;
    bool seenFlag;
    bool blocked2;
    if (settings.Enabled() && ref && !ref->Extras()->Linked())
    {
        switch (ref->Base()->Type())
        {
        case 42:
        case 43:
        case 44:
        case 45:
        case 51:
        case 81:
            break;
        default:
            enabled = true;
        }
    }
    if (enabled || force)
    {
        Ptr object10(ref->Get3D());
        if (ref == player)
            object10 = player->PlayerNode();
        bool success4 = false;
        seenFlag = false;
        blocked2 = false;
        VisitMap visited3(37, false);
        Ref* linked30 = ref->Extras()->Linked();
        if (linked30 && !skip)
        {
            visited3.FUN_005594e0(linked30, true);
            success4 = Try(ref, object10, linked30, &blocked2, skip);
            if (!success4)
            {
                Link* link = linked30->Extras()->Links();
                while (link)
                {
                    Ref* owner = *link->Item();
                    if (owner)
                    {
                        Ref* candidate = owner->Extras()->Select(false);
                        if (candidate)
                        {
                            visited3.FUN_005594e0(candidate, true);
                            success4 = Try(ref, object10, candidate, &blocked2, skip);
                        }
                        if (!success4)
                        {
                            candidate = owner->Extras()->Select(true);
                            if (candidate)
                            {
                                success4 = Try(ref, object10, candidate, &blocked2, skip);
                                visited3.FUN_005594e0(candidate, true);
                            }
                        }
                    }
                    link = link->Next();
                }
            }
        }
        void* pos33 = loaded->map.First();
        while (pos33 && !success4)
        {
            Ptr nodeTmp(0);
            Ref* key33 = 0;
            loaded->map.Next(pos33, key33, nodeTmp);
            if (key33 && (Obj*)nodeTmp && !visited3.FUN_0057c850(key33, &seenFlag))
            {
                if (!enabled && force && !((Obj*)nodeTmp)->IsSceneNode())
                    continue;
                Ref* owner = ((Obj*)nodeTmp)->Owner();
                if (owner)
                {
                    if (ref->Test(owner) && !force)
                    {
                        Obj* target = ref->OtherExtras()->Find(key33);
                        if (target)
                        {
                            target->Attach(ref->Get3D(), true);
                            success4 = true;
                            ref->Update(key33);
                        }
                    }
                    else
                    {
                        if (((Obj*)nodeTmp)->IsSceneNode())
                        {
                            if (Try(ref, object10, key33, &blocked2, skip))
                            {
                                success4 = true;
                                break;
                            }
                        }
                        else
                        {
                            if (ref->Test2(owner))
                            {
                                pending.Add(ref, key33);
                                Obj* original9 = ref->Get3D();
                                Task* taskA = new Task(key33, original9);
                                manager->Queue(taskA);
                                Graph* graph8 = GraphA();
                                Ptr unused(0);
                                graph8->Add(ref->Get3D());
                            }
                        }
                    }
                }
            }
        }
        if (!success4 && !blocked2)
        {
            Graph* graph8 = GraphB();
            void* iter6 = (void*)*graph8->FUN_007d6bb0();
            Plane* selected6 = 0;
            bool contains8 = false;
            bool multiple3 = false;
            bool any5 = false;
            Obj* original9 = ref->Get3D();
            while (iter6 && !multiple3)
            {
                Plane* plane = graph8->FUN_007d6bb0()->FUN_0057cbe0(iter6);
                contains8 = plane->FUN_00c34890(original9->FUN_0043d450());
                if (contains8)
                {
                    if (!any5)
                    {
                        any5 = true;
                        selected6 = plane;
                    }
                    else
                    {
                        selected6 = 0;
                        multiple3 = true;
                    }
                }
            }
            if (selected6)
            {
                Ptr unused(0);
                graph8->Add(original9);
                if (!FUN_008c7aa0())
                    selected6->FUN_0045c4c0()->Attach(original9, true);
                else
                    FUN_0054abd0(ref, selected6->FUN_0045c4c0());
                success4 = true;
            }
            else
            {
                if (multiple3)
                {
                    if (original9->Parent() != Dynamic() && !ref->IsActor())
                    {
                        if (!ref->IsActor())
                        {
                            Graph* graph2 = GraphA();
                            graph2->FUN_00c5b1c0(original9);
                            if (original9->Parent())
                            {
                                if (!FUN_008c7aa0())
                                    original9->Parent()->Detach(original9);
                                else
                                    FUN_0054abd0(ref, 0);
                            }
                        }
                        else
                        {
                            if (!FUN_008c7aa0())
                                FUN_0054a050()->Attach(original9, true);
                            else
                                FUN_0054abd0(ref, FUN_0054a050());
                        }
                    }
                    success4 = true;
                }
            }
        }
        if (!success4 && !blocked2)
        {
            if (ref->IsActor())
            {
                if (!FUN_008c7aa0())
                    FUN_0054a050()->Attach(ref->Get3D(), true);
                else
                    FUN_0054abd0(ref, FUN_0054a050());
            }
            else
            {
                if (!FUN_008c7aa0())
                    FUN_0054aa60()->Attach(ref->Get3D(), true);
                else
                    FUN_0054abd0(ref, FUN_0054aa60());
            }
        }
    }
    if (ref->Extras()->FUN_00422120() && !ref->Extras()->Linked())
    {
        Graph* graph8 = GraphA();
        graph8->FUN_00c5ae70(ref->Extras()->FUN_00422120());
    }
}

template <> class NiPointer<NiAVObject>
{
  public:
    NiAVObject* m_pObject;
    NiPointer(NiAVObject* p);
    ~NiPointer();
    NiPointer<NiAVObject>& operator=(NiAVObject* p);
};
struct IOTask
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    IOTask(int n);
    virtual void v0();
    ~IOTask();
};
struct S_0054aa80_Src
{
    NiAVObject* FUN_00569920();
};
struct FUN_0054aa80 : IOTask
{
    S_0054aa80_Src* unk18;
    NiPointer<NiAVObject> unk1c;
    NiPointer<NiAVObject> unk20;
    char unk24;
    FUN_0054aa80(S_0054aa80_Src* a, NiAVObject* b);
};
// Initializes an IOTask with task count 4, stores the source and object pointers, and assigns the source's FUN_00569920 result to unk20.
// @fnv 0x0054aa80
FUN_0054aa80::FUN_0054aa80(S_0054aa80_Src* pSource, NiAVObject* pObject)
    : IOTask(4), unk18(pSource), unk1c(pObject), unk20(0)
{
    unk24 = 0;
    unk20 = pSource->FUN_00569920();
}

struct FUN_0096e150_shell
{
    void ProcessWorkerList(void* list);
};

struct FUN_0054af40_cls : public TESObjectCELL
{
    void FUN_00541ac0();
    void FUN_00541ae0();
    void* FUN_009604f0(unsigned char flag);
    void FUN_0054af40(unsigned char flag);
};

// Calls FUN_00541ac0, passes the result of FUN_009604f0(flag) to ProcessWorkerList on DAT_011e0e80, then calls FUN_00541ae0.
// @fnv 0x0054af40
void FUN_0054af40_cls::FUN_0054af40(unsigned char flag)
{
    FUN_00541ac0();
    ((FUN_0096e150_shell*)&DAT_011e0e80)->ProcessWorkerList(FUN_009604f0(flag));
    FUN_00541ae0();
}

struct Ref54;
struct Changes54;
struct Extra54 : ExtraDataList
{
    Ref54* FUN_00421400();
    void FUN_00419ad0(short count);
    void DuplicateExtraListForContainer(Extra54* source);
    void SetOriginalReference(Ref54* reference);
    void FUN_0041aed0();
    short FUN_00418770();
    Changes54* FUN_00418520();
};
struct Object54
{
    unsigned int FNV_GetFormType();
};
struct Ref54
{
    Extra54* FUN_005d43c0() const;
    bool FUN_00440da0();
    bool FUN_00440d80() const;
    TESForm* FUN_00567790();
    bool FUN_005785e0(Ref54* actor, bool flag);
    Object54* FUN_007af430();
};
struct FUN_00410360 : Extra54
{
    FUN_00410360();
};
struct FUN_0096a2d0
{
    Extra54* item;
    FUN_0096a2d0* next;
    FUN_0096a2d0();
    void AddHead(Extra54** value);
};
struct FUN_004bc550
{
    FUN_0096a2d0* extraLists;
    int count;
    Object54* object;
    FUN_004bc550(Object54* object, int count);
    void FUN_006ecd40(int count);
};
struct Changes54
{
    void FUN_004d26d0(void* destination, Ref54* reference, bool flag);
};
struct Destination54
{
    void FUN_004c3380(FUN_004bc550* entry, bool flag);
};
struct Node54
{
    Ref54** _ref_006815c0();
    Node54* _ref_00726070();
};
struct Cell54 : TESObjectCELL
{
    void FUN_0054b260(Ref54* actor, Destination54* destination);
};
// Locks the cell, iterates its references and hands each eligible one to destination via FUN_004c3380 or FUN_004d26d0, then unlocks.
// @fnv 0x0054b260
void Cell54::FUN_0054b260(Ref54* actor, Destination54* destination)
{
    if (!destination || !actor)
        return;
    Ref54* container = actor->FUN_005d43c0()->FUN_00421400();
    CellRefLockEnter();
    Node54* node = (Node54*)FUN_009604f0();
    while (node && *node->_ref_006815c0())
    {
        Ref54* reference;
        {
            Changes54* changes = 0;
            reference = *node->_ref_006815c0();
            {
                Extra54* extra = 0;
                if (!reference->FUN_00440da0() && !reference->FUN_00440d80() && reference->FUN_00567790() &&
                    reference->FUN_005785e0(actor, false) && reference != container)
                {
                    if (reference != container)
                    {
                        Object54* object = reference->FUN_007af430();
                        {
                            FUN_004bc550* entry = 0;
                            switch (object->FNV_GetFormType())
                            {
                            case 0x73:
                                if (reference->FUN_005d43c0())
                                    reference->FUN_005d43c0()->FUN_00419ad0(1);
                                // Fall through to construct the inventory entry.
                            case 0x18:
                            case 0x19:
                            case 0x1a:
                            case 0x1d:
                            case 0x1e:
                            case 0x1f:
                            case 0x28:
                            case 0x29:
                            case 0x2e:
                            case 0x2f:
                            case 0x32:
                            case 0x67:
                            case 0x6c:
                            case 0x74:
                                entry = new FUN_004bc550(reference->FUN_007af430(), 0);
                                if (!entry->extraLists)
                                    entry->extraLists = new FUN_0096a2d0;
                                extra = new FUN_00410360;
                                extra->DuplicateExtraListForContainer(reference->FUN_005d43c0());
                                extra->SetOriginalReference(reference);
                                extra->FUN_0041aed0();
                                entry->extraLists->AddHead(&extra);
                                entry->FUN_006ecd40(reference->FUN_005d43c0()->FUN_00418770());
                                destination->FUN_004c3380(entry, true);
                                break;
                            case 0x1b:
                                changes = reference->FUN_005d43c0()->FUN_00418520();
                                if (changes)
                                    changes->FUN_004d26d0(destination, reference, false);
                                break;
                            }
                        }
                    }
                }
            }
        }
        node = node->_ref_00726070();
    }
    CellRefLockLeave();
}

struct X54
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual FUN_0054b800_class* GetObject();
};
struct Refr54
{
    X54* FUN_0043fcd0();
    virtual void vt0();
    virtual void vt1();
    virtual void vt2();
    virtual void vt3();
    virtual void vt4();
    virtual void vt5();
    virtual void vt6();
    virtual void vt7();
    virtual void vt8();
    virtual void vt9();
    virtual void vt10();
    virtual void vt11();
    virtual void vt12();
    virtual void vt13();
    virtual void vt14();
    virtual void vt15();
    virtual void vt16();
    virtual void vt17();
    virtual void vt18();
    virtual void vt19();
    virtual void vt20();
    virtual void vt21();
    virtual void vt22();
    virtual void vt23();
    virtual void vt24();
    virtual void vt25();
    virtual void vt26();
    virtual void vt27();
    virtual void vt28();
    virtual void vt29();
    virtual void vt30();
    virtual void vt31();
    virtual void vt32();
    virtual void vt33();
    virtual void vt34();
    virtual void vt35();
    virtual void vt36();
    virtual void vt37();
    virtual void vt38();
    virtual void vt39();
    virtual void vt40();
    virtual void vt41();
    virtual void vt42();
    virtual void vt43();
    virtual void vt44();
    virtual void vt45();
    virtual void vt46();
    virtual void vt47();
    virtual void vt48();
    virtual void vt49();
    virtual void vt50();
    virtual void vt51();
    virtual void vt52();
    virtual void vt53();
    virtual void vt54();
    virtual void vt55();
    virtual void vt56();
    virtual void vt57();
    virtual void vt58();
    virtual void vt59();
    virtual void vt60();
    virtual void vt61();
    virtual void vt62();
    virtual void vt63();
    virtual void vt64();
    virtual void vt65();
    virtual void vt66();
    virtual void vt67();
    virtual void vt68();
    virtual void vt69();
    virtual void vt70();
    virtual void vt71();
    virtual void vt72();
    virtual void vt73();
    virtual void vt74();
    virtual void vt75();
    virtual void vt76();
    virtual void vt77();
    virtual void vt78();
    virtual void vt79();
    virtual void vt80();
    virtual void vt81();
    virtual void vt82();
    virtual void vt83();
    virtual void vt84();
    virtual void vt85();
    virtual void vt86();
    virtual void vt87();
    virtual void vt88();
    virtual void vt89();
    virtual void vt90();
    virtual void vt91();
    virtual void vt92();
    virtual void vt93();
    virtual void vt94();
    virtual void vt95();
    virtual void vt96();
    virtual void vt97();
    virtual void vt98();
    virtual void vt99();
    virtual void vt100();
    virtual void vt101();
    virtual void vt102();
    virtual void vt103();
    virtual void vt104();
    virtual void vt105();
    virtual void vt106();
    virtual void vt107();
    virtual void vt108();
    virtual void vt109();
    virtual void vt110();
    virtual void vt111();
    virtual void vt112();
    virtual void vt113();
    virtual void vt114();
    virtual void RemoveCell(int a, int b);
};

extern Refr54* g_011dea3c;

struct Claim54b750
{
    void FUN_00541ac0();
    void ClearAdditionalGeometryData();
    void* FUN_009604f0();
    void FUN_00541ae0();
    void ProcessRefrList();
};

// @fnv 0x0054b750
void Claim54b750::ProcessRefrList()
{
    FUN_00541ac0();
    ClearAdditionalGeometryData();
    void* node = FUN_009604f0();
    while (node != 0)
    {
        Refr54* refr = (Refr54*)*_ref_006815c0(node);
        node = _ref_00726070(node);
        if (refr != 0 && refr != g_011dea3c)
        {
            X54* extra = refr->FUN_0043fcd0();
            if (extra != 0)
            {
                FUN_0054b800_class* obj = extra->GetObject();
                if (obj != 0)
                {
                    obj->FUN_0054b800();
                }
            }
            refr->RemoveCell(0, 0);
        }
    }
    FUN_00541ae0();
}

struct FormType
{
    unsigned int FUN_00401170();
};

struct FUN_0054bb90_shell : TESObjectCELL
{
    unsigned int CountReferencesWithFormType30();
};

// Locks cell references, walks the node list, and counts references whose object form type is 30, then unlocks and returns the count.
// @fnv 0x0054bb90
unsigned int FUN_0054bb90_shell::CountReferencesWithFormType30()
{
    CellRefLockEnter();
    unsigned int count = 0;
    NodeStub* node = (NodeStub*)FUN_009604f0();

    while (node)
    {
        RefStub* reference = *node->_ref_006815c0();
        node = node->_ref_00726070();
        if (reference)
        {
            switch (((FormType*)reference->_FNV_GetObjectReference())->FUN_00401170())
            {
            case 30:
                count++;
                break;
            }
        }
    }
    CellRefLockLeave();
    return count;
}

namespace fnv_0054bc10 {
struct AnimData
{
    unsigned char FUN_00549580();
};
struct Resource
{
    Resource* FUN_00586170();
    void FUN_006fcfa0();
    void FUN_00929260();
};
struct RefEx : VClass1d0
{
    void FUN_0056f700();
    AnimData* FUN_007af430();
};
struct CellStub
{
    void FUN_0054af40(bool flag);
    void FUN_00541ac0();
    NodeStub* FUN_009604f0();
    Resource* FUN_0054ddd0();
    Resource* FUN_0054ddd0(RefEx* reference, bool flag);
    Resource* FUN_0054ddd0(bool flag);
    void FUN_00541ae0();
    void ProcessCellReferences();
};
// @fnv 0x0054bc10
void CellStub::ProcessCellReferences()
{
    FUN_0054af40(false);
    FUN_00541ac0();
    NodeStub* pNode = FUN_009604f0();
    while (pNode != 0)
    {
        RefEx* reference = reinterpret_cast<RefEx*>(*pNode->_ref_006815c0());
        if (reference != 0)
        {
            reference->FUN_0056f700();
            if (reference->FUN_007af430()->FUN_00549580())
            {
                if (reference->vfn_1d0())
                {
                    if (FUN_0054ddd0() != 0)
                    {
                        FUN_0054ddd0(reference, true)->FUN_00586170()->FUN_006fcfa0();
                        FUN_0054ddd0(true)->FUN_00586170()->FUN_00929260();
                    }
                }
            }
        }
        pNode = pNode->_ref_00726070();
    }
    FUN_00541ae0();
}
}  // namespace fnv_0054bc10

namespace fnv_0054c030 {
struct RotationPoint
{
    float x, y, z;
    RotationPoint();
    RotationPoint(float, float, float);
    RotationPoint FUN_00439e90(const RotationPoint&) const;
    RotationPoint FUN_00439ef0(const RotationPoint&) const;
    RotationPoint FUN_0053d280(float) const;
};
struct RotationForm
{
    int FUN_00401170();
};
struct RotationList;
struct RotationExtra
{
    void* GetExtraData();
};
struct RotationReference
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
    virtual const char* Name();
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
    virtual RotationPoint Position();
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
    virtual const RotationPoint& Rotation();
    RotationForm* FUN_007af430();
    RotationExtra* FUN_005d43c0(int);
    unsigned int FUN_0084e3a0();
    void FUN_00575830(const RotationPoint&);
};
struct RotationList
{
    RotationReference** FUN_006815c0();
    RotationList* FUN_00726070();
};
struct RotationCell : RotationReference
{
    void FUN_00541ac0();
    void FUN_00541ae0();
    RotationList* FUN_009604f0();
    void FUN_0054cfd0(RotationPoint&, RotationPoint&);
    void ComputeCellRotationCenter(RotationPoint&);
};
extern const RotationPoint DAT_011f426c;
extern const float DAT_01016970, DAT_0102efc4, DAT_010162c0, DAT_0102efc0;
extern const double DAT_0102efb8;
extern const char DAT_0102ef68[], DAT_0102ef18[], DAT_0102ee68[];
double FUN_00408840(float);
float FUN_004587d0(float);
float FUN_0040ebd0(float, float);
float FUN_00404010(float, float);
void FUN_005b5e40(const char*, ...);
// Resets output, iterates the cell's reference list to gather rotation bounds, logs and resets outliers, and stores the midpoint of the min/max rotations.
// @fnv 0x0054c030
void RotationCell::ComputeCellRotationCenter(RotationPoint& aRotationCenter)
{
    aRotationCenter = DAT_011f426c;
    FUN_00541ac0();
    int count = 0;
    RotationPoint minimum(DAT_01016970, DAT_01016970, DAT_01016970);
    RotationPoint aMaximum(DAT_0102efc4, DAT_0102efc4, DAT_0102efc4);
    RotationList* cursorB = FUN_009604f0();
    while (cursorB)
    {
        RotationReference* ref = *cursorB->FUN_006815c0();
        if (ref && ref->FUN_007af430())
        {
            bool include = true;
            switch (ref->FUN_007af430()->FUN_00401170())
            {
            case 30:
            case 42:
            case 43:
            case 44:
            case 45:
                include = false;
                break;
            default: {
                bool different = false;
                if (count)
                {
                    RotationPoint midpoint3 = minimum.FUN_00439e90(aMaximum).FUN_0053d280(DAT_010162c0);
                    RotationPoint delta;
                    delta = midpoint3.FUN_00439ef0(ref->Rotation());
                    different = FUN_00408840(delta.x) > FUN_004587d0(DAT_0102efc0) ||
                                FUN_00408840(delta.y) > FUN_004587d0(DAT_0102efc0) ||
                                FUN_00408840(delta.z) > FUN_004587d0(DAT_0102efc0);
                }
                if (FUN_00408840(ref->Rotation().x) > DAT_0102efb8 || FUN_00408840(ref->Rotation().y) > DAT_0102efb8 ||
                    different)
                {
                    bool reset = true;
                    if (ref->FUN_005d43c0(15)->GetExtraData())
                    {
                        FUN_005b5e40(DAT_0102ef68, ref->Name(), ref->FUN_0084e3a0());
                        ref->FUN_00575830(ref->Position());
                        if (different)
                        {
                            RotationPoint midpoint2 = minimum.FUN_00439e90(aMaximum).FUN_0053d280(DAT_010162c0);
                            RotationPoint delta2;
                            delta2 = midpoint2.FUN_00439ef0(ref->Rotation());
                            different = FUN_00408840(delta2.x) > FUN_004587d0(DAT_0102efc0) ||
                                        FUN_00408840(delta2.y) > FUN_004587d0(DAT_0102efc0) ||
                                        FUN_00408840(delta2.z) > FUN_004587d0(DAT_0102efc0);
                        }
                        if (FUN_00408840(ref->Rotation().x) < DAT_0102efb8 &&
                            FUN_00408840(ref->Rotation().y) < DAT_0102efb8 && !different)
                            reset = false;
                    }
                    if (reset)
                    {
                        FUN_005b5e40(DAT_0102ef18, ref->Name(), ref->FUN_0084e3a0());
                        RotationPoint position;
                        RotationPoint rotation_;
                        FUN_0054cfd0(position, rotation_);
                        ref->FUN_00575830(position);
                        include = false;
                    }
                }
            }
            break;
            }
            if (include)
            {
                minimum.x = FUN_0040ebd0(minimum.x, ref->Rotation().x);
                minimum.y = FUN_0040ebd0(minimum.y, ref->Rotation().y);
                minimum.z = FUN_0040ebd0(minimum.z, ref->Rotation().z);
                aMaximum.x = FUN_00404010(aMaximum.x, ref->Rotation().x);
                aMaximum.y = FUN_00404010(aMaximum.y, ref->Rotation().y);
                aMaximum.z = FUN_00404010(aMaximum.z, ref->Rotation().z);
                ++count;
            }
        }
        cursorB = cursorB->FUN_00726070();
    }
    if (count > 0)
    {
        RotationPoint span = aMaximum.FUN_00439ef0(minimum);
        if (span.x > FUN_004587d0(DAT_0102efc0) || span.y > FUN_004587d0(DAT_0102efc0) ||
            span.z > FUN_004587d0(DAT_0102efc0))
        {
            FUN_005b5e40(DAT_0102ee68, Name(), FUN_0084e3a0(), span.x, span.y, span.z, FUN_004587d0(DAT_0102efc0));
        }
        aRotationCenter = minimum.FUN_00439e90(aMaximum).FUN_0053d280(DAT_010162c0);
    }
    FUN_00541ae0();
}
}  // namespace fnv_0054c030

struct MoveWorld;
struct MovePosition
{
    float x;
    float y;
    float z;
};
struct MoveRef
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
    virtual unsigned int FormId();
    virtual void Slot77();
    virtual void Slot78();
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
    virtual void Slot116();
    virtual void Slot117();
    virtual void Slot118();
    virtual void Slot119();
    virtual void Slot120();
    virtual void Slot121();
    virtual void Slot122();
    virtual void Slot123();
    virtual void Slot124();
    virtual const MovePosition& Position();
    const char* FUN_0084e3a0();
};
struct MoveNode
{
    MoveRef** FUN_006815c0();
    MoveNode* FUN_00726070();
};
struct MoveCell
{
    bool FUN_005516c0();
    void FUN_00541ac0();
    void FUN_00541ae0();
    MoveNode* FUN_009604f0();
    void FUN_00548230(MoveRef*, bool);
    void MoveReferencesToWorldCells(MoveWorld*);
};
struct MoveWorld : MoveRef
{
    MoveCell* FUN_005875a0(int, int);
};
int FUN_00406d90(float);
void FUN_005b5e40(const char*, ...);
// Iterates the cell's references, converts each position to cell coordinates, and adds each reference to the matching cell in the given world, logging failures.
// @fnv 0x0054c8c0
void MoveCell::MoveReferencesToWorldCells(MoveWorld* world)
{

    if (world && FUN_005516c0())
    {
        FUN_00541ac0();
        MoveNode* node = FUN_009604f0();
        while (node)
        {
            MoveRef* ref = *node->FUN_006815c0();
            if (ref)
            {
                int x = FUN_00406d90(ref->Position().x) >> 12;
                int y = FUN_00406d90(ref->Position().y) >> 12;
                MoveCell* cell = world->FUN_005875a0(x, y);
                if (cell)
                {
                    cell->FUN_00548230(ref, false);
                }
                else
                {
                    FUN_005b5e40(
                        "CELLS: Could not find cell (%i, %i) in world '%s' (%08X) to add reference '%s' (%08X) to.", x,
                        y, world->FormId(), ((MoveRef*)this)->FUN_0084e3a0(), ref->FormId(), ref->FUN_0084e3a0());
                }
            }
            node = node->FUN_00726070();
        }
        FUN_00541ae0();
    }
}

namespace fnv_0054cd20 {
struct FormX
{
    int GetFormKind();
    bool IsFlagged();
};

struct RefX
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual ~RefX();
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
    virtual void Disable(bool arg);
    bool IsTemp();
    FormX* GetReferenceSpace();
};

struct ListX
{
    bool IsEmpty();
    RefX** Head();
    void RemoveHead();
};

struct DH
{
    bool FUN_004226e0();
};

extern RefX* g_thePlayer;
void ReleaseRef(RefX* ref);

struct CellX : public TESObjectCELL
{
    void Prepare();
    bool IsAttached();
    void AddSpaceRef(RefX* ref);
    ListX* GetRefs();
    bool IsInteriorCell();
    void ProcessCellRefs();
};

// @fnv 0x0054cd20
void CellX::ProcessCellRefs()
{
    CellRefLockEnter();
    Prepare();
    *(unsigned short*)((char*)this + 0xa8) = 0;
    ListX* list = GetRefs();
    while (list && !list->IsEmpty())
    {
        RefX* ref = *list->Head();
        if (ref != g_thePlayer)
        {
            bool skip = false;
            if (IsAttached() && g_dataHandler && !((DH*)g_dataHandler)->FUN_004226e0())
                skip = true;
            if (ref->IsTemp() && !IsInteriorCell() && !skip)
            {
                if (IsAttached())
                    delete ref;
                else
                    ref->Disable(false);
            }
            else
            {
                if (ref->GetReferenceSpace() && ref->GetReferenceSpace()->GetFormKind() == 0x23)
                {
                    FormX* space = ref->GetReferenceSpace();
                    if (space->IsFlagged())
                        AddSpaceRef(ref);
                }
                ReleaseRef(ref);
            }
            GetRefs()->RemoveHead();
        }
        else
        {
            GetRefs()->RemoveHead();
            ref->Disable(false);
        }
        list = GetRefs();
    }
    CellRefLockLeave();
}
}  // namespace fnv_0054cd20

struct RefEntry;
struct RefObject
{
    int __thiscall FUN_007af430();
    bool __thiscall FUN_00440d80();
};
struct RefWrapper
{
    RefObject* reference;
};
struct RefEntry
{
    bool __thiscall FUN_008256d0();
    RefWrapper* __thiscall FUN_006815c0();
    RefEntry* __thiscall FUN_00726070();
};
struct CellRefScan
{
    void __thiscall FUN_00541ac0();
    RefEntry* __thiscall FUN_009604f0();
    void __thiscall FUN_00541ae0();
    RefObject* FindFirstRefByType(int typeId, bool filtered);
};
// Scans the cell's ref entries and returns the first reference whose type matches typeId, optionally skipping filtered ones.
// @fnv 0x0054cf20
RefObject* CellRefScan::FindFirstRefByType(int typeId, bool filtered)
{
    if (!typeId)
        return 0;
    FUN_00541ac0();
    RefEntry* current = FUN_009604f0();
    int itemType;
    RefObject* reference;
    while (current && !current->FUN_008256d0())
    {
        reference = current->FUN_006815c0()->reference;
        itemType = reference->FUN_007af430();
        current = current->FUN_00726070();
        if (itemType && (!filtered || !reference->FUN_00440d80()) && itemType == typeId)
        {
            FUN_00541ae0();
            return reference;
        }
    }
    FUN_00541ae0();
    return 0;
}

struct MarkerBase
{
    int FUN_00401170();
};
struct MarkerData;
struct MarkerRef
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00c();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01c();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02c();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03c();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04c();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05c();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06c();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07c();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08c();
    virtual void slot090();
    virtual void slot094();
    virtual void slot098();
    virtual void slot09c();
    virtual void slot0a0();
    virtual void slot0a4();
    virtual void slot0a8();
    virtual void slot0ac();
    virtual void slot0b0();
    virtual void slot0b4();
    virtual void slot0b8();
    virtual void slot0bc();
    virtual void slot0c0();
    virtual void slot0c4();
    virtual void slot0c8();
    virtual void slot0cc();
    virtual void slot0d0();
    virtual void slot0d4();
    virtual void slot0d8();
    virtual void slot0dc();
    virtual void slot0e0();
    virtual void slot0e4();
    virtual void slot0e8();
    virtual void slot0ec();
    virtual void slot0f0();
    virtual void slot0f4();
    virtual void slot0f8();
    virtual void slot0fc();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14c();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15c();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual void slot16c();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17c();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void slot18c();
    virtual void slot190();
    virtual void slot194();
    virtual void slot198();
    virtual void slot19c();
    virtual void slot1a0();
    virtual void slot1a4();
    virtual void slot1a8();
    virtual void slot1ac();
    virtual void slot1b0();
    virtual void slot1b4();
    virtual void slot1b8();
    virtual void slot1bc();
    virtual void slot1c0();
    virtual void slot1c4();
    virtual void slot1c8();
    virtual void slot1cc();
    virtual void slot1d0();
    virtual void slot1d4();
    virtual void slot1d8();
    virtual void slot1dc();
    virtual void slot1e0();
    virtual void slot1e4();
    virtual void slot1e8();
    virtual void slot1ec();
    virtual void slot1f0();
    virtual NiPoint3* Position();
    bool FUN_00440d80();
    MarkerBase* _FNV_GetObjectReference();
    MarkerData* FUN_00568e50();
    NiPoint3* FUN_00430830();
};
struct MarkerData
{
    MarkerRef* FUN_00559450();
    NiPoint3* FUN_00717e50();
};
struct MarkerList
{
    bool _ref_008256d0();
    MarkerRef** _ref_006815c0();
    MarkerList* _ref_00726070();
};
struct MarkerLand
{
    void FUN_0053f180(NiPoint3*, float*);
};
extern MarkerBase* DAT_011ca244;
extern MarkerBase* DAT_011ca248;
extern MarkerBase* DAT_011ca24c;
struct MarkerCell : TESObjectCELL
{
    void FUN_0054d090(NiPoint3* position, NiPoint3* angle);
    bool FUN_00425fd0();
    bool FUN_00550200(NiPoint3*);
    MarkerLand* FUN_00546fb0();
    float FUN_005471e0();
};
// @fnv 0x0054d090
void MarkerCell::FUN_0054d090(NiPoint3* position, NiPoint3* angle)
{
    CellRefLockEnter();
    MarkerRef* fallback = 0;
    MarkerRef* markerD = 0;
    MarkerRef* markerB = 0;
    MarkerRef* hasPosition = 0;
    MarkerList* markerC;
    MarkerRef* node = 0;
    bool markerA = false;
    markerC = (MarkerList*)FUN_009604f0();
    while (markerC && !markerC->_ref_008256d0())
    {
        MarkerRef* ref = *markerC->_ref_006815c0();
        if (!ref->FUN_00440d80())
        {
            if (!markerB && ref->_FNV_GetObjectReference() == DAT_011ca24c &&
                (FUN_00425fd0() || FUN_00550200(ref->Position())))
                markerB = ref;
            if (!fallback && ref->_FNV_GetObjectReference() == DAT_011ca244 &&
                (FUN_00425fd0() || FUN_00550200(ref->Position())))
                fallback = ref;
            if (!markerD && ref->_FNV_GetObjectReference() == DAT_011ca248 &&
                (FUN_00425fd0() || FUN_00550200(ref->Position())))
                markerD = ref;
            if (!markerA)
            {
                MarkerData* data = ref->FUN_00568e50();
                if (data && data->FUN_00559450())
                {
                    data = data->FUN_00559450()->FUN_00568e50();
                    if (data)
                    {
                        NiPoint3 point = *data->FUN_00717e50();
                        if (FUN_00425fd0() || FUN_00550200(&point))
                        {
                            *position = point;
                            markerA = true;
                        }
                    }
                }
            }
            if (!hasPosition && ref->_FNV_GetObjectReference()->FUN_00401170() == 32 &&
                (FUN_00425fd0() || FUN_00550200(ref->Position())))
                hasPosition = ref;
            if (FUN_00425fd0() || FUN_00550200(ref->Position()))
                node = ref;
        }
        markerC = markerC->_ref_00726070();
    }
    CellRefLockLeave();
    if (markerB)
    {
        *position = *markerB->Position();
        *angle = *markerB->FUN_00430830();
    }
    else if (markerD)
    {
        *position = *markerD->Position();
        *angle = *markerD->FUN_00430830();
    }
    else if (fallback)
    {
        *position = *fallback->Position();
    }
    else if (!markerA)
    {
        if (hasPosition)
            *position = *hasPosition->Position();
        else if (node)
            *position = *node->Position();
    }
    if (!FUN_00425fd0())
    {
        MarkerLand* land = FUN_00546fb0();
        if (land)
        {
            float water = 0.0f;
            land->FUN_0053f180(position, &water);
            float height = FUN_005471e0();
            if (water < height)
                water = height;
            if (water > position->z)
                position->z = water;
        }
    }
}

class Point54D
{
  public:
    float x, y, z;

    Point54D operator-(const Point54D& pt) const;
    float SqrLength() const;
};

class Form54D
{
  public:
    int GetFormType();
};

extern Form54D* g_pkDoorMarker54D;

class Ref54D
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
    virtual void vfn138();
    virtual void vfn13C();
    virtual void vfn140();
    virtual void vfn144();
    virtual void vfn148();
    virtual void vfn14C();
    virtual void vfn150();
    virtual void vfn154();
    virtual void vfn158();
    virtual void vfn15C();
    virtual void vfn160();
    virtual void vfn164();
    virtual void vfn168();
    virtual void vfn16C();
    virtual void vfn170();
    virtual void vfn174();
    virtual void vfn178();
    virtual void vfn17C();
    virtual void vfn180();
    virtual void vfn184();
    virtual void vfn188();
    virtual void vfn18C();
    virtual void vfn190();
    virtual void vfn194();
    virtual void vfn198();
    virtual void vfn19C();
    virtual void vfn1A0();
    virtual void vfn1A4();
    virtual void vfn1A8();
    virtual void vfn1AC();
    virtual void vfn1B0();
    virtual void vfn1B4();
    virtual void vfn1B8();
    virtual void vfn1BC();
    virtual void vfn1C0();
    virtual void vfn1C4();
    virtual void vfn1C8();
    virtual void vfn1CC();
    virtual void vfn1D0();
    virtual void vfn1D4();
    virtual void vfn1D8();
    virtual void vfn1DC();
    virtual void vfn1E0();
    virtual void vfn1E4();
    virtual void vfn1E8();
    virtual void vfn1EC();
    virtual void vfn1F0();
    virtual const Point54D& GetPos();

    bool IsDeleted();
    Form54D* GetBaseObject();
    int IsEnabled();
};

class RefNode54D
{
  public:
    Ref54D** GetItem();
    RefNode54D* GetNext();
};

class RefArray54D
{
  public:
    unsigned int Add(Ref54D*& pkRef);
    unsigned int GetSize();
};

class Cell54D
{
  public:
    void LockRefs();
    void UnlockRefs();
    RefNode54D* GetRefList();

    unsigned int FUN_0054dc00(const Point54D& kPos, float fRadius, RefArray54D* pkResults);
};

// @fnv 0x0054dc00
unsigned int Cell54D::FUN_0054dc00(const Point54D& kPos, float afRadius, RefArray54D* pkResults)
{
    if (!pkResults)
        return 0;

    float fRadiusSqr = afRadius * afRadius;
    LockRefs();
    RefNode54D* pkNode = GetRefList();
    while (pkNode)
    {
        Ref54D* pkRef = *pkNode->GetItem();
        if (pkRef && !pkRef->IsDeleted())
        {
            Form54D* pkBase = pkRef->GetBaseObject();
            if (pkBase->GetFormType() == 0x1c && pkBase != g_pkDoorMarker54D && pkRef->IsEnabled())
            {
                Point54D kDiff = kPos - pkRef->GetPos();
                if (kDiff.SqrLength() < fRadiusSqr)
                    pkResults->Add(pkRef);
            }
        }
        pkNode = pkNode->GetNext();
    }
    UnlockRefs();
    return pkResults->GetSize();
}

struct RenderPoint
{
    float x, y, z;
};
extern int _NiPoint3_ZERO;
extern int DAT_011f4270;
extern int DAT_011f4274;
struct RenderMatrix
{
    RenderMatrix();
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    void FUN_00a59540(float, float, float);
};
struct RenderFrustum
{
    RenderFrustum(bool);
    float left, right, top, bottom, nearDist, farDist;
    bool ortho;
};
struct RenderUpdate
{
    RenderUpdate(float, bool, bool);
    float time;
    bool a, b;
    int flags;
};
struct RenderObject
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9c();
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    virtual void slotc0();
    virtual void slotc4();
    virtual void slotc8();
    virtual void slotcc();
    virtual void slotd0();
    virtual void slotd4();
    virtual void slotd8();
    virtual void Attach(RenderObject*, bool);
    virtual void slote0();
    virtual void slote4();
    virtual void Detach(RenderObject*);
    bool FUN_00456610();
    void FUN_00450f90(bool);
    void FUN_00440460(const RenderPoint&);
    void FUN_0043fa80(const RenderMatrix&);
    void FUN_00a6faf0(const RenderFrustum&);
    void Update(RenderUpdate&);
};
struct RenderCamera : RenderObject
{
    RenderCamera();
    static void* operator new(unsigned);
    static void operator delete(void*, unsigned int);
    int field004;
    int field008;
    int field00c;
    int field010;
    int field014;
    int field018;
    int field01c;
    int field020;
    int field024;
    int field028;
    int field02c;
    int field030;
    int field034;
    int field038;
    int field03c;
    int field040;
    int field044;
    int field048;
    int field04c;
    int field050;
    int field054;
    int field058;
    int field05c;
    int field060;
    int field064;
    int field068;
    int field06c;
    int field070;
    int field074;
    int field078;
    int field07c;
    int field080;
    int field084;
    int field088;
    int field08c;
    int field090;
    int field094;
    int field098;
    int field09c;
    int field0a0;
    int field0a4;
    int field0a8;
    int field0ac;
    int field0b0;
    int field0b4;
    int field0b8;
    int field0bc;
    int field0c0;
    int field0c4;
    int field0c8;
    int field0cc;
    int field0d0;
    int field0d4;
    int field0d8;
    int field0dc;
    int field0e0;
    int field0e4;
    int field0e8;
    int field0ec;
    int field0f0;
    int field0f4;
    int field0f8;
    int field0fc;
    int field100;
    int field104;
    int field108;
    int field10c;
    int field110;
};
struct RenderNode : RenderObject
{
    RenderNode(unsigned short);
    static void* operator new(unsigned);
    static void operator delete(void*, unsigned int);
    int field004;
    int field008;
    int field00c;
    int field010;
    int field014;
    int field018;
    int field01c;
    int field020;
    int field024;
    int field028;
    int field02c;
    int field030;
    int field034;
    int field038;
    int field03c;
    int field040;
    int field044;
    int field048;
    int field04c;
    int field050;
    int field054;
    int field058;
    int field05c;
    int field060;
    int field064;
    int field068;
    int field06c;
    int field070;
    int field074;
    int field078;
    int field07c;
    int field080;
    int field084;
    int field088;
    int field08c;
    int field090;
    int field094;
    int field098;
    int field09c;
    int field0a0;
    int field0a4;
    int field0a8;
};
struct RenderPtr
{
    RenderObject* ptr;
    RenderPtr(RenderObject*);
    ~RenderPtr();
    operator RenderObject*();
    RenderPtr& operator=(RenderObject*);
    RenderPtr& operator=(const RenderPtr&);
};
struct RenderRange
{
    float low, high;
    RenderRange();
};
struct RenderRangeSource
{
    RenderRange* FUN_0053f440();
};
struct RenderSource
{
    int a, b;
};
struct RenderSky
{
    static RenderSky* GetInstance();
    RenderObject* GetRoot();
};
RenderObject* __cdecl FUN_00450b80(int);
void __cdecl SetByteAtOffset1B(bool);
void __cdecl FUN_006652e0(RenderObject*, bool);

unsigned char __cdecl FUN_0054f4b0();
void __cdecl FUN_004e20b0(unsigned char);
RenderObject* __cdecl FUN_00524c90();
struct CellRenderer
{
    bool IsInterior();
    RenderRangeSource* FUN_00546fb0(RenderSource*);
    int GetCellGridX();
    int GetCellGridY();
    void FUN_005570d0();
    RenderObject* FUN_00456fc0(int);
    void FUN_0054e830(RenderObject*, RenderPtr*);
    void BuildExteriorCameraScene(RenderPtr*);
};
// @fnv 0x0054ee80
void CellRenderer::BuildExteriorCameraScene(RenderPtr* output)
{
    if (IsInterior())
    {
        *output = 0;
        return;
    }
    RenderObject* scene5 = FUN_00450b80(0);
    RenderRange range3;
    RenderPoint position9 = *(RenderPoint*)&_NiPoint3_ZERO;
    RenderMatrix _dx;
    _dx.FUN_00a59540(-1.57079637f, -1.57079637f, 1.57079637f);
    RenderFrustum _bA(false);
    _bA.nearDist = 100.0f;
    _bA.ortho = true;
    RenderSource sourcePos_;
    range3 = *FUN_00546fb0(&sourcePos_)->FUN_0053f440();
    const int center7 = 2176;
    position9.x = float((GetCellGridX() << 12) + center7);
    position9.y = float((GetCellGridY() << 12) + center7) - 32.0;
    position9.z = range3.high + 20000.0;
    _bA.left = -2176.0f;
    _bA.right = 2176.0f;
    _bA.top = 2176.0f;
    _bA.bottom = -2176.0f;
    _bA.farDist = position9.z - range3.low + 10.0;
    RenderPtr camera_2(new RenderCamera);
    RenderPtr nodeB(new RenderNode(0));
    ((RenderObject*)nodeB)->Attach(camera_2, true);
    ((RenderObject*)nodeB)->FUN_00440460(position9);
    scene5->Attach(nodeB, true);
    ((RenderObject*)camera_2)->FUN_0043fa80(_dx);
    ((RenderObject*)camera_2)->FUN_00a6faf0(_bA);
    RenderUpdate updateNodeTmp(0.0f, false, false);
    ((RenderObject*)nodeB)->Update(updateNodeTmp);
    RenderUpdate updateCameraVal(0.0f, false, false);
    ((RenderObject*)camera_2)->Update(updateCameraVal);
    SetByteAtOffset1B(true);
    FUN_006652e0(camera_2, true);
    FUN_005570d0();
    bool _bp = false, _m4 = false, _fB = false;
    RenderObject* _ok = FUN_00456fc0(0);
    if (_ok)
    {
        _bp = _ok->FUN_00456610();
        _ok->FUN_00450f90(true);
    }
    RenderObject* _b8 = FUN_00456fc0(1);
    if (_b8)
    {
        _m4 = _b8->FUN_00456610();
        _b8->FUN_00450f90(true);
    }
    RenderObject* _ch = FUN_00456fc0(2);
    if (_ch)
    {
        _fB = _ch->FUN_00456610();
        _ch->FUN_00450f90(true);
    }
    RenderObject* _f8 = RenderSky::GetInstance()->GetRoot();
    bool _ap = false;
    if (_f8)
    {
        _ap = _f8->FUN_00456610();
        _f8->FUN_00450f90(true);
    }
    RenderObject* extraNodeA = (RenderObject*)FUN_0054f4f0();
    bool _b4 = false;
    if (_f8)
    {
        _b4 = extraNodeA->FUN_00456610();
        extraNodeA->FUN_00450f90(true);
    }
    bool _m2 = false;
    RenderObject* other_ = (RenderObject*)FUN_0054f4c0();
    if (other_)
    {
        _m2 = other_->FUN_00456610();
        other_->FUN_00450f90(true);
    }
    unsigned char oldState7 = FUN_0054f4b0();
    FUN_004e20b0(0);
    RenderPtr _p1(0);
    FUN_0054e830(camera_2, &_p1);
    FUN_004e20b0(oldState7);
    if (other_)
        other_->FUN_00450f90(_m2);
    if (extraNodeA)
        extraNodeA->FUN_00450f90(_b4);
    if (_f8)
        _f8->FUN_00450f90(_ap);
    if (_ok)
        _ok->FUN_00450f90(_bp);
    if (_b8)
        _b8->FUN_00450f90(_m4);
    if (_ch)
        _ch->FUN_00450f90(_fB);
    FUN_006652e0(FUN_00524c90(), true);
    SetByteAtOffset1B(false);
    FUN_005570d0();
    scene5->Detach(nodeB);
    nodeB = 0;
    camera_2 = 0;
    *output = _p1;
}

struct Pt2
{
    float x;
    float y;
};

float FUN_0054fb20(float x1, float y1, float x2, float y2);

struct ThisC
{
    int FUN_00544c30();
    int FUN_00544c60();
    float FUN_0054fb70(Pt2* p);
};

// @fnv 0x0054fb70
float ThisC::FUN_0054fb70(Pt2* pPoint)
{
    int a = this->FUN_00544c30();
    int b5 = this->FUN_00544c60();
    float fA3 = (float)(a << 12);
    float fAhi = fA3 + 4096.0;
    float fB = (float)(b5 << 12);
    float fBhi = fB + 4096.0;
    if (pPoint->x < fA3)
    {
        if (pPoint->y > fBhi)
        {
            return FUN_0054fb20(pPoint->x, pPoint->y, fA3, fBhi);
        }
        else if (pPoint->y < fB)
        {
            return FUN_0054fb20(pPoint->x, pPoint->y, fA3, fB);
        }
        else
        {
            return fA3 - pPoint->x;
        }
    }
    else if (pPoint->x > fAhi)
    {
        if (pPoint->y > fBhi)
        {
            return FUN_0054fb20(pPoint->x, pPoint->y, fAhi, fBhi);
        }
        else if (pPoint->y < fB)
        {
            return FUN_0054fb20(pPoint->x, pPoint->y, fAhi, fB);
        }
        else
        {
            return fA3 - pPoint->x;
        }
    }
    else
    {
        if (pPoint->y > fBhi)
        {
            return pPoint->y - fBhi;
        }
        else if (pPoint->y < fB)
        {
            return fB - pPoint->y;
        }
        else
        {
            return 0.0f;
        }
    }
}

struct RegionEntry;
struct RegionNode
{
    RegionEntry*& GetItem();
    RegionNode* GetNext();
};
struct RegionData;
struct RegionBoundary
{
    unsigned int GetNext();
    float ComputeRegionValue(void*, float);
};
struct BoundaryNode
{
    RegionBoundary*& GetItem();
    BoundaryNode* GetNext();
};
struct RegionEntry
{
    bool FUN_00440d80();
    RegionData* FUN_009611e0(int);
    BoundaryNode* FUN_00441110();
};
struct RegionData
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int GetType();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual bool IsValid();
    RegionData* FUN_004f35b0();
    bool FUN_004f1540();
    unsigned char FUN_005bb4d0();
};
struct RegionQueryForm
{
    unsigned int FUN_0084e3a0();
};
struct RegionQuery
{
    virtual int GetType();
    virtual RegionQueryForm* GetForm();
    virtual void slot2();
    virtual RegionQueryForm* GetSecondary();
};
struct RegionAnswer
{
    bool FUN_004f6e60();
    int FUN_004f5f80();
};
struct RegionDataRecord
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual RegionAnswer* FindPair(unsigned int, unsigned int);
    virtual RegionAnswer* FindQuery(RegionQuery*, bool, bool);
};
struct RegionDataManager
{
    virtual void slot0();
    virtual void slot1();
    virtual RegionDataRecord* GetRecord2(RegionData*);
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual RegionDataRecord* GetRecord6(RegionData*);
};
struct RegionLoadHandler
{
    RegionDataManager* GetRegionDataManager();
};
struct RegionListHeader
{
    int header;
};
struct RegionList : RegionListHeader, RegionNode
{
};
struct RegionCell
{
    RegionList* GetRegionList(bool);
    bool IsInterior();
    float FUN_0054fd70(void*, int, RegionQuery*);
};
float FUN_00404010(float, float);
float FUN_0040ebd0(float, float);
// @fnv 0x0054fd70
float RegionCell::FUN_0054fd70(void* point, int kind, RegionQuery* query)
{
    RegionNode* a = GetRegionList(true);
    if (IsInterior() || !a)
        return 0.0f;
    int eb = -1;
    float f = 3.402823466e+38F;
    float s;
    float h;
    RegionData* i;
    BoundaryNode* p;
    RegionDataRecord* cf;
    RegionDataRecord* b;
    RegionQuery* q;
    while (a && a->GetItem())
    {
        if (a->GetItem()->FUN_00440d80())
        {
            a = a->GetNext();
            continue;
        }
        s = 0.0f;
        i = a->GetItem()->FUN_009611e0(kind)->FUN_004f35b0();
        if (!i || !i->IsValid())
        {
            a = a->GetNext();
            continue;
        }
        if (i->FUN_004f1540())
        {
            if (i->FUN_005bb4d0() <= eb)
            {
                a = a->GetNext();
                continue;
            }
        }
        else if (eb >= 0)
        {
            a = a->GetNext();
            continue;
        }
        p = a->GetItem()->FUN_00441110();
        while (p && p->GetItem())
        {
            if (s > 0.0)
                break;
            h = p->GetItem()->ComputeRegionValue(point, (float)p->GetItem()->GetNext());
            if (h > 1.0)
                h = 1.0f;
            s = FUN_00404010(s, h);
            p = p->GetNext();
        }
        if (s <= 0.0)
        {
            a = a->GetNext();
            continue;
        }
        if (i->FUN_004f1540())
        {
            f = 3.402823466e+38F;
            eb = i->FUN_005bb4d0();
        }
        if (i->GetType() == 2 && query && query->GetForm() && query->GetType() == 0)
        {
            cf = ((RegionLoadHandler*)g_dataHandler)->GetRegionDataManager()->GetRecord2(i);
            if (!cf->FindQuery(query, true, false)->FUN_004f6e60())
            {
                a = a->GetNext();
                continue;
            }
        }
        else if (i->GetType() == 6 && query && query->GetForm() && query->GetType() == 1)
        {
            b = ((RegionLoadHandler*)g_dataHandler)->GetRegionDataManager()->GetRecord6(i);
            q = query;
            if (!b->FindPair(q->GetForm()->FUN_0084e3a0(), q->GetSecondary() ? q->GetSecondary()->FUN_0084e3a0() : -1)
                     ->FUN_004f5f80())
            {
                a = a->GetNext();
                continue;
            }
        }
        while (p && p->GetItem())
        {
            h = p->GetItem()->ComputeRegionValue(point, (float)p->GetItem()->GetNext());
            if (h > 1.0)
                h = 1.0f;
            s = FUN_00404010(s, h);
            p = p->GetNext();
        }
        f = FUN_0040ebd0(f, s);
        a = a->GetNext();
    }
    if (f < 0.0)
        f = 0.0f;
    if (f > 1.0)
        f = 0.0f;
    return f;
}

struct TESRecordHeader
{
    unsigned int type;
    unsigned int size;
};
extern unsigned int DAT_011872b4;
// Scans the current group record for a record whose masked form ID matches formID, advancing through the file and returning whether it was found.
// @fnv 0x00550e10
bool HasFormInGroup(TESFile* file, unsigned int formID)
{
    if (!file)
        return false;
    TESRecordHeader* size = file->GetRecordHeader();
    if (size->type != DAT_011872b4)
        return false;
    if (!((TESFile_Helper*)file)->FUN_00472150(true))
        return false;
    size = file->GetRecordHeader();
    if (size->type != kGroupFormType)
        return false;
    unsigned int uiGroupSize = size->size - 0x18;
    if (!((TESFile_Helper*)file)->FUN_00472150(true))
        return false;
    size = file->GetRecordHeader();
    formID &= 0xffffff;
    bool header = false;
    unsigned int found = 0;
    while (!header && found < uiGroupSize)
    {
        if (size->type != kGroupFormType)
        {
            unsigned int current = ((FileH*)file)->GetFormID() & 0xffffff;
            if (current == formID)
                header = true;
            else
            {
                found += size->size;
                found += 0x18;
            }
        }
        else
            found += 0x18;
        if (!header)
        {
            if (!((TESFile_Helper*)file)->FUN_00472150(true))
                return false;
            size = file->GetRecordHeader();
        }
    }
    return header;
}

struct CellLabel : VCallC8
{
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
    virtual unsigned int v76();

    bool FUN_00425fd0();
    CellLabel* FUN_0054ddd0();
    int FUN_00544c60();
    int FUN_00544c30();
    void FUN_00551790(char* destination);
};

extern void __cdecl FUN_00406f60(char* destination, const char* format, ...);
extern const char DAT_0102f0d8[];
extern const char DAT_0102f0a8[];
extern const char DAT_0102f088[];

// @fnv 0x00551790
void CellLabel::FUN_00551790(char* destination)
{
    if (FUN_00425fd0())
    {
        FUN_00406f60(destination, DAT_0102f0d8, v76(), _ref_0084e3a0(this));
    }
    else
    {
        CellLabel* worldSpace = FUN_0054ddd0();
        if (worldSpace)
        {
            FUN_00406f60(destination, DAT_0102f0a8, v76(), _ref_0084e3a0(this), FUN_00544c30(), FUN_00544c60(),
                         worldSpace->v76(), _ref_0084e3a0(worldSpace));
        }
        else
        {
            FUN_00406f60(destination, DAT_0102f088, v76(), _ref_0084e3a0(this), FUN_00544c30(), FUN_00544c60());
        }
    }
}

extern void* g_011f3728;

struct Ctrl_552790
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
    virtual void Update37(const NiUpdateData& data);
};

struct Node_552790;

struct AVObj_552790
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Node_552790* IsNode3();
    Ctrl_552790* GetController(const void* rtti);
};

struct Node_552790 : public AVObj_552790
{
    unsigned int GetArrayCount();
    AVObj_552790* GetAt(unsigned int idx);
};

// If apObject is non-null, updates its controller via Update37 and recursively processes each child returned by IsNode3/GetAt.
// @fnv 0x00552790
void __cdecl UpdateControllersRecursive(AVObj_552790* apObject)
{
    if (apObject)
    {
        Ctrl_552790* h = apObject->GetController(&g_011f3728);
        if (h)
        {
            NiUpdateData kData(DAT_011c3c08, true, false);
            h->Update37(kData);
        }
        Node_552790* p = apObject->IsNode3();
        if (p)
        {
            unsigned int e = p->GetArrayCount();
            unsigned int j;
            for (j = 0; j < e; ++j)
            {
                UpdateControllersRecursive(p->GetAt(j));
            }
        }
    }
}

struct CellCaster553
{
    void FUN_0061f8e0(bool bValue);
    void FUN_004893c0(bool bValue);
};

struct CellWorld553
{
    void FUN_00454380(bool bValue);
    void SetProcessEnabled(bool bValue);
    CellCaster553* FUN_0045cd60();
    void FUN_00c68a00(bool bValue);
};

struct CellMopp553
{
    void FUN_00621e80();
};

struct CellRef553
{
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
    virtual void Update3D();
};

struct CellRefNode553
{
    CellRef553*& FUN_006815c0();
};

CellRefNode553* __fastcall FUN_00726070(CellRefNode553* pkNode);

struct FUN_00553700_shell : public TESObjectCELL
{
    CellRefNode553* FUN_009604f0();
    void UpdateCell();
};

bool __fastcall FUN_00425fd0(FUN_00553700_shell* pkCell);
CellWorld553* __fastcall FUN_004543c0(FUN_00553700_shell* pkCell);
CellMopp553* __fastcall GetCellMopp(FUN_00553700_shell* pkCell);

// @fnv 0x00553700
void FUN_00553700_shell::UpdateCell()
{
    if (FUN_00425fd0(this))
    {
        CellWorld553* pkWorld = FUN_004543c0(this);
        if (pkWorld)
        {
            pkWorld->FUN_00454380(false);
            pkWorld->SetProcessEnabled(false);
            if (pkWorld->FUN_0045cd60())
            {
                CellCaster553* pkCaster = pkWorld->FUN_0045cd60();
                pkCaster->FUN_0061f8e0(true);
                pkCaster->FUN_004893c0(false);
            }
        }
    }
    else
    {
        CellMopp553* pMopp = GetCellMopp(this);
        if (pMopp)
            pMopp->FUN_00621e80();
        CellRefLockEnter();
        CellRefNode553* pkNodeCur = FUN_009604f0();
        while (pkNodeCur)
        {
            CellRef553* pkRef = pkNodeCur->FUN_006815c0();
            pkNodeCur = FUN_00726070(pkNodeCur);
            if (pkRef)
                pkRef->Update3D();
        }
        CellWorld553* pkCellWorld3 = FUN_004543c0(this);
        if (pkCellWorld3)
        {
            CellCaster553* pkWorldCaster = pkCellWorld3->FUN_0045cd60();
            pkWorldCaster->FUN_004893c0(false);
        }
        if (DAT_011de134->GetUnk26())
            pkCellWorld3->FUN_00c68a00(false);
        CellRefLockLeave();
    }
}

namespace fnv_005546a0 {
struct TargetObj
{
    void FUN_00554720();
};

struct GlobalManager
{
    TargetObj* FUN_00559450(void* param_1);
};

// Creates a memory context, resolves the object for param_1 via g_011ca0d8 and calls its FUN_00554720 method.
// @fnv 0x005546a0
void __cdecl FUN_005546a0(void* param_1)
{
    Local::AutoMemContext ctx((Local::MEM_CONTEXT)0x10, true,
                              "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESObjectCELL.cpp", 15451);
    ((GlobalManager*)&g_011ca0d8)->FUN_00559450(param_1)->FUN_00554720();
}
}  // namespace fnv_005546a0

struct SaveGameRecordWriter
{
    unsigned int Position();
    bool Active();
    void Write(void*, int);
    struct LogRecord* Record();
};
extern SaveGameRecordWriter* g_TESSaveLoadGame;
struct LogSetting
{
    bool* Bool();
};
extern LogSetting g_011de4e8;
struct FullNameAccess
{
    const char* GetFullName();
};
struct OwnerAccess
{
    unsigned int FormID();
};
struct SaveVirtual
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void Save(int);
};
struct FormVirtual
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
    virtual const char* Description();
};
struct RecordFlags
{
    unsigned int value;
};
struct LogRecord
{
    unsigned int id;
    unsigned char kind;
    unsigned char flags;
};
FormVirtual* Lookup(unsigned int);
unsigned int BSStringLength(const char*);
void Log(const char*, ...);
void FNV_Warning(const char*, ...);
struct CellSave
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    FullNameAccess fullName;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned char flags24;
    unsigned char flags25;
    unsigned int CellID();
    void Begin(unsigned int);
    void Write(const void*, int);
    void WriteOwner(const void*, int);
    SaveVirtual* Extra();
    OwnerAccess* GetOwner();
    void SaveCell(unsigned int changes);
};
// Writes the cell's change flags, extra data, full name and owner to the save stream, optionally logging the block size and patching the block header.
// @fnv 0x00554d30
void CellSave::SaveCell(unsigned int changes)
{

    {
        unsigned int cellID;
        {
            unsigned int blockStart;
            {
                unsigned short blockSize;
                {
                    unsigned int start;
                    {
                        unsigned int marker;
                        {
                            unsigned char cellFlags;
                            {
                                const char* name;
                                {
                                    unsigned char length;
                                    {
                                        unsigned int ownerID;
                                        {
                                            OwnerAccess* owner;
                                            {
                                                LogRecord* record;
                                                {
                                                    unsigned int end;
                                                    {
                                                        FormVirtual* form;
                                                        {
                                                            unsigned int finalPos;
                                                            {
                                                                unsigned int beginPos;
                                                                if (changes & 0x40000000)
                                                                {
                                                                    cellID = CellID();
                                                                    Write(&cellID, 4);
                                                                }
                                                                Begin(changes);
                                                                blockSize = 0;
                                                                blockStart = 0;
                                                                start = g_TESSaveLoadGame->Position();
                                                                if (*g_011de4e8.Bool())
                                                                    start = g_TESSaveLoadGame->Position();
                                                                if (g_TESSaveLoadGame->Active())
                                                                {
                                                                    marker = 0x424c4f4b;
                                                                    g_TESSaveLoadGame->Write(&marker, 4);
                                                                    blockStart = g_TESSaveLoadGame->Position();
                                                                    g_TESSaveLoadGame->Write(&blockSize, 2);
                                                                }
                                                                if (changes & 2)
                                                                {
                                                                    cellFlags = flags24 & 0x60;
                                                                    cellFlags |= flags25;
                                                                    Write(&cellFlags, 1);
                                                                }
                                                                if (changes & 0x80000000)
                                                                    Extra()->Save(0);
                                                                if (changes & 4)
                                                                {
                                                                    name = fullName.GetFullName();
                                                                    length = BSStringLength(name);
                                                                    Write(&length, 1);
                                                                    if (length)
                                                                        Write(name, length);
                                                                }
                                                                if (changes & 8)
                                                                {
                                                                    owner = GetOwner();
                                                                    ownerID = 0;
                                                                    if (owner)
                                                                        ownerID = owner->FormID();
                                                                    WriteOwner(&ownerID, 4);
                                                                }
                                                                if (*g_011de4e8.Bool())
                                                                {
                                                                    end = g_TESSaveLoadGame->Position();
                                                                    record = g_TESSaveLoadGame->Record();
                                                                    if (record)
                                                                    {
                                                                        form = Lookup(record->id);
                                                                        Log("SaveGame(): %-5i for form %08X %s with flags %08X ending at line %i in file %s",
                                                                            end - start, record->id,
                                                                            form->Description(),
                                                                            *(unsigned int*)&record->flags, 0x3d86,
                                                                            "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESObjectCELL.cpp");
                                                                    }
                                                                    else
                                                                    {
                                                                        Log("SaveGame(): %-5i ending at line %i in file %s",
                                                                            end - start, 0x3d86,
                                                                            "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESObjectCELL.cpp");
                                                                    }
                                                                }
                                                                if (g_TESSaveLoadGame->Active())
                                                                {
                                                                    finalPos = g_TESSaveLoadGame->Position();
                                                                    beginPos = blockStart;
                                                                    if (finalPos > beginPos + 0xffff)
                                                                        FNV_Warning(
                                                                            "SAVELOAD: Save Game Block in file %s on line %i is greater than maximum short size",
                                                                            "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESObjectCELL.cpp",
                                                                            0x3d86);
                                                                    *(unsigned short*)blockStart =
                                                                        (unsigned short)(finalPos - beginPos);
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

namespace CellLoad {
extern "C" void* memset(void*, int, unsigned int);
extern const char DAT_0102ed68[], DAT_01015718[], DAT_010156a8[], DAT_01015588[], DAT_01015500[], DAT_010154a0[],
    DAT_01015440[];
void FUN_005b5e40(const char*, ...);
struct Form
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
    virtual const char* Name();
};
Form* FUN_004839c0(unsigned int);
struct Header
{
    unsigned int id;
    unsigned char type, payload0, payload1, payload2, payload3, version;
};
struct Stream
{
    unsigned char FUN_008df040();
    bool FUN_00862110();
    void FUN_008579e0(void*, unsigned int);
    Header* FUN_004fd3c0();
    unsigned int FUN_00825c00();
};
extern Stream* DAT_011de45c;
struct Data
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void Load(unsigned int);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    static void* operator new(unsigned int);
};
struct Interior : Data
{
    int unk24, unk28;
    Interior(int, int);
};
struct Exterior : Data
{
    Exterior();
};
struct Ref
{
    void FUN_00421850(unsigned int);
    void FUN_00421940(Data*);
};
struct String
{
    int unk00, unk04, unk08;
    void FUN_00489100(const char*);
};
struct Cell
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    String name;
    unsigned char flags, otherFlags;
    void FUN_00484d00(void*, unsigned int);
    void FUN_00484d40(void*, unsigned int);
    void FUN_00484c50(unsigned int, int);
    Ref* GetExtraDataList();
    Data* FUN_00555bc0();
    bool FUN_00425fd0();
    void FUN_00546bf0(unsigned int);
    void LoadChanged(unsigned int, int);
};
// Applies changed-field flags to a cell: reads flags, linked ref, extra data, name and a value from the stream, then reports any size mismatch.
// @fnv 0x00554fd0
void Cell::LoadChanged(unsigned int auiChangedFlags, int file)
{
    if (DAT_011de45c->FUN_008df040() >= 90 && (auiChangedFlags & 0x40000000))
    {
        unsigned int id;
        FUN_00484d00(&id, 4);
        GetExtraDataList()->FUN_00421850(id);
    }
    {
        FUN_00484c50(auiChangedFlags, file);
        unsigned short usChunkSize = 0;
        unsigned int start = 0;
        if (DAT_011de45c->FUN_00862110())
        {
            unsigned int uiChunkTag;
            DAT_011de45c->FUN_008579e0(&uiChunkTag, 4);
            if (uiChunkTag != 0x424c4f4b)
            {
                Header* header = DAT_011de45c->FUN_004fd3c0();
                if (header)
                {
                    Form* form = FUN_004839c0(header->id);
                    FUN_005b5e40(DAT_01015718, DAT_0102ed68, 0x3d9d, header->id, form->Name(), header->version,
                                 *(unsigned int*)&header->payload0);
                }
                else
                    FUN_005b5e40(DAT_010156a8, DAT_0102ed68, 0x3d9d, DAT_011de45c->FUN_008df040());
            }
            start = DAT_011de45c->FUN_00825c00();
            DAT_011de45c->FUN_008579e0(&usChunkSize, 2);
        }
        if (auiChangedFlags & 2)
        {
            unsigned char value;
            FUN_00484d00(&value, 1);
            flags = (flags & 0x9f) | (value & 0x60);
            otherFlags = value & 0x9f;
        }
        if (auiChangedFlags & 0x80000000)
        {
            Data* data = FUN_00555bc0();
            if (!data)
            {
                if (FUN_00425fd0())
                    data = new Interior(0, 0);
                else
                    data = new Exterior;
                GetExtraDataList()->FUN_00421940(data);
            }
            data->Load(0xffff);
        }
        if (DAT_011de45c->FUN_008df040() < 90 && (auiChangedFlags & 0x40000000))
        {
            unsigned int uiLinkedRefId2;
            FUN_00484d00(&uiLinkedRefId2, 4);
            GetExtraDataList()->FUN_00421850(uiLinkedRefId2);
        }
        if (auiChangedFlags & 4)
        {
            char text[260];
            memset(text, 0, 260);
            unsigned char size;
            FUN_00484d00(&size, 1);
            if (size)
                FUN_00484d00(text, size);
            name.FUN_00489100(text);
        }
        if (auiChangedFlags & 8)
        {
            unsigned int uiValue;
            FUN_00484d40(&uiValue, 4);
            FUN_00546bf0(uiValue);
        }
        if (DAT_011de45c->FUN_00862110())
        {
            unsigned int end = DAT_011de45c->FUN_00825c00();
            Header* pEndHeader = DAT_011de45c->FUN_004fd3c0();
            if (pEndHeader)
            {
                Form* pEndForm = FUN_004839c0(pEndHeader->id);
                if (end > start + usChunkSize)
                    FUN_005b5e40(DAT_01015588, end - (start + usChunkSize), DAT_0102ed68, 0x3dd5, pEndHeader->id,
                                 pEndForm->Name(), pEndHeader->version, *(unsigned int*)&pEndHeader->payload0);
                else if (end < start + usChunkSize)
                    FUN_005b5e40(DAT_01015500, start + usChunkSize - end, DAT_0102ed68, 0x3dd5, pEndHeader->id,
                                 pEndForm->Name(), pEndHeader->version, *(unsigned int*)&pEndHeader->payload0);
            }
            else
            {
                if (end > start + usChunkSize)
                    FUN_005b5e40(DAT_010154a0, end - (start + usChunkSize), DAT_0102ed68, 0x3dd5,
                                 DAT_011de45c->FUN_008df040());
                else if (end < start + usChunkSize)
                    FUN_005b5e40(DAT_01015440, start + usChunkSize - end, DAT_0102ed68, 0x3dd5,
                                 DAT_011de45c->FUN_008df040());
            }
        }
    }
}
}

struct FUN_004610d0_Obj
{
    ExtraDataList* GetExtraDataList();
};

struct FUN_00421940_Obj
{
    void FUN_00421940(int value);
};

struct FUN_00555be0_Virtual
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C(unsigned int value);
};

// @fnv 0x00555be0
void FUN_00555be0_stub::FUN_00555be0()
{
    reinterpret_cast<FUN_00421940_Obj*>(reinterpret_cast<FUN_004610d0_Obj*>(this)->GetExtraDataList())->FUN_00421940(0);

    reinterpret_cast<unsigned char*>(this)[0x25] &= 0xFFFFFFFEu;

    reinterpret_cast<FUN_00555be0_Virtual*>(this)->vf4C(0x80000000u);
}

struct FUN_00557ae0_Av
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual BSFadeNode* unk10();
};

struct FUN_0043fcd0_Obj
{
    FUN_00557ae0_Av* FUN_0043fcd0();
};

struct FUN_006815c0_Obj
{
    void** FUN_006815c0();
};

struct FUN_00726070_Obj
{
    BSSimpleList<BGSPerkEntry*>* FUN_00726070();
};

struct FUN_007058c0_Obj
{
    int FUN_007058c0() const;
};

struct FUN_0099e040_Obj
{
    float FUN_0099e040();
};

extern void* DAT_011dea3c;
void __fastcall FUN_00476ab0(BSFadeNode* p);
void __cdecl FUN_00b6bb30(BSFadeNode* a1, float a2);

struct FUN_00557ae0_shell : public TESObjectCELL
{
    void FUN_00557ae0();
};

// @fnv 0x00557ae0
void FUN_00557ae0_shell::FUN_00557ae0()
{
    CellRefLockEnter();
    BSSimpleList<BGSPerkEntry*>* node = FUN_009604f0();
    while (node)
    {
        void* item = *((FUN_006815c0_Obj*)node)->FUN_006815c0();
        node = ((FUN_00726070_Obj*)node)->FUN_00726070();
        if (item && item != DAT_011dea3c)
        {
            FUN_00557ae0_Av* obj = ((FUN_0043fcd0_Obj*)item)->FUN_0043fcd0();
            if (obj)
            {
                BSFadeNode* pFadeNode = obj->unk10();
                if (pFadeNode)
                {
                    if (((FUN_007058c0_Obj*)pFadeNode)->FUN_007058c0() == 6 ||
                        ((FUN_0099e040_Obj*)pFadeNode)->FUN_0099e040() > 599.9f)
                    {
                        FUN_00476ab0(pFadeNode);
                        FUN_00b6bb30(pFadeNode, 1.0f);
                    }
                }
            }
        }
    }
    *(float*)(padToUnknownDC + 4) = 1.2f;
    padToUnknownDC[12] = 1;
    padToUnknownDC[10] = 0;
    padToUnknownDC[11] = 0;
    padToUnknownDC[14] = 1;
    CellRefLockLeave();
}

namespace fnv_00557dd0 {
namespace render_test {
struct FUN_00557da0
{
    unsigned a, b, c, d, e, f;
    void(__cdecl* callback)(int);
    int data;
    FUN_00557da0();
};
}
struct RenderVec
{
    float x, y, z;
    void FUN_006815c0();
};
struct RenderMatrix
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
    void FUN_006815c0();
};
struct RenderNode
{
    RenderVec& FUN_0043c490();
    RenderMatrix& FUN_006a9540();
    void FUN_00440460(const RenderVec&);
    void FUN_0043fa80(const RenderMatrix&);
    void Update(const NiUpdateData&);
};
struct RenderRoot
{
    RenderNode* FUN_00558310();
};
RenderRoot* FUN_0045c670();
struct RenderMesh
{
    unsigned FUN_00558200();
    RenderVec FUN_00558220(unsigned short);
};
struct NavMeshPtr
{
    RenderMesh* value;
    ~NavMeshPtr();
    RenderMesh* FUN_00559450();
    RenderMesh* FUN_00458b50();
};
struct RenderMeshes
{
    unsigned GetReferenceFlags();
    NavMeshPtr FUN_00464f60(unsigned);
};
struct RenderCell : TESObjectCELL
{
    RenderMeshes* FUN_0070ec90();
};
struct RenderBound
{
    RenderVec& FUN_006815c0();
};
struct RenderObjectNode : VClass0c
{
    RenderBound* FUN_0043d450();
    RenderVec& FUN_0045bb80();
};
struct RenderReference : VClass1d0
{
    RenderObjectNode* vfn_1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual RenderVec& v1f4();
};
struct RenderRefList
{
    unsigned FUN_005ae380();
    bool FUN_008256d0();
    RenderReference** FUN_006815c0();
    RenderRefList* FUN_00726070();
};
extern RenderReference* pPlayer;
void FNV_Warning(const char*, ...);
// Tests navmesh triangles or reference positions in a cell against the renderer, restoring the camera transform and warning on failure.
// @fnv 0x00557dd0
void FUN_00557dd0(RenderCell* cell, render_test::FUN_00557da0* options, bool all)
{
    if (!cell || !cell->FUN_00545cb0())
        return;
    bool testData = true;
    render_test::FUN_00557da0 kUpdateData;
    if (!options)
        options = &kUpdateData;
    RenderVec bResult;
    bResult.FUN_006815c0();
    RenderMatrix kRotationBasis;
    kRotationBasis.FUN_006815c0();
    RenderRoot* kPosition = FUN_0045c670();
    bResult = kPosition->FUN_00558310()->FUN_0043c490();
    kRotationBasis = kPosition->FUN_00558310()->FUN_006a9540();
    if (all)
    {
        RenderMeshes* meshes = cell->FUN_0070ec90();
        if (meshes && meshes->GetReferenceFlags())
        {
            unsigned count = 0;
            for (unsigned i = 0; i < meshes->GetReferenceFlags(); i++)
            {
                NavMeshPtr mesh = meshes->FUN_00464f60(i);
                count += mesh.FUN_00559450()->FUN_00558200();
            }
            FNV_Warning("Testing %i NavMesh triangles.", count);
            for (unsigned j = 0; j < meshes->GetReferenceFlags(); j++)
            {
                NavMeshPtr mesh2 = meshes->FUN_00464f60(j);
                if (mesh2.FUN_00458b50())
                {
                    unsigned triangles = mesh2.FUN_00559450()->FUN_00558200();
                    for (unsigned k = 0; k < triangles; k++)
                    {
                        RenderVec pos = mesh2.FUN_00559450()->FUN_00558220((unsigned short)k);
                        pos.z += 118.0;
                        if (!FUN_00558330((int)cell, (int)&pos, (int)options))
                            testData = false;
                    }
                }
            }
        }
        else
        {
            FNV_Warning("Testing %i reference positions.", ((RenderRefList*)cell->FUN_009604f0())->FUN_005ae380());
            RenderRefList* refs = (RenderRefList*)cell->FUN_009604f0();
            while (refs && !refs->FUN_008256d0())
            {
                RenderReference* pos = *refs->FUN_006815c0();
                refs = refs->FUN_00726070();
                RenderVec ref = pos->v1f4();
                if (pos->vfn_1d0())
                    ref = pos->vfn_1d0()->FUN_0043d450()->FUN_006815c0();
                if (!FUN_00558330((int)cell, (int)&ref, (int)options))
                    testData = false;
            }
        }
    }
    else
    {
        if (!FUN_00558330((int)cell, (int)&pPlayer->vfn_1d0()->FUN_0045bb80(), (int)options))
            testData = false;
    }
    kPosition->FUN_00558310()->FUN_00440460(bResult);
    kPosition->FUN_00558310()->FUN_0043fa80(kRotationBasis);
    NiUpdateData pRoot(0.0f, false, false);
    kPosition->FUN_00558310()->Update(pRoot);
    if (!testData)
        FNV_Warning("!!!RenderTestCell failed!!! (see file in RTF folder for more info)");
}
}  // namespace fnv_00557dd0

namespace fnv_00558430 {
struct ThreeByThreeMatrix
{
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
};

struct NiAVObject_Shell : public NiAVObject
{
    void FUN_00440460(const NiPoint3& pt);
    void FUN_0043fa80(const void* rot);
    void Update(NiUpdateData& data);
};

NiNode_00558310* FUN_0045c670();
unsigned int gm_GetTickCount();

struct OSGlobals
{
    void FUN_0086ff70();
};
extern OSGlobals* g_osGlobals;

struct FUN_00558690
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    int unk18;
    NiPoint3 pt;
    ThreeByThreeMatrix mat;

    FUN_00558690();
};

struct FUN_00558600_obj
{
    void FUN_00558600(unsigned int* a1, unsigned int* a2, unsigned int* a3, unsigned int* a4, unsigned int* a5,
                      unsigned int* a6, unsigned int* a7, unsigned int* a8, unsigned int* a9, unsigned int* a10,
                      unsigned int* a11);
};

struct NiRenderer_Shell : public NiRenderer
{
    FUN_00558600_obj* FUN_005585e0();
};

struct ShadowSceneNode_Shell : public ShadowSceneNode
{
    unsigned short FUN_00b5ac60();
};
ShadowSceneNode* __cdecl FUN_00450b80(int);

// Updates a node's transform, measures timing and renderer stats, compares them against limit, and invokes limit's callback when any stat exceeds it.
// @fnv 0x00558430
bool UpdateAndCheckBudget(int a1, const NiPoint3* apPosition, const ThreeByThreeMatrix* apRotation, SpawnedVecC* limit)
{
    NiNode_00558310* node2 = FUN_0045c670();
    ((NiAVObject_Shell*)FUN_00558310(node2))->FUN_00440460(*apPosition);
    ((NiAVObject_Shell*)FUN_00558310(node2))->FUN_0043fa80(apRotation);
    NiUpdateData updateData(0.0f, false, false);
    ((NiAVObject_Shell*)FUN_00558310(node2))->Update(updateData);
    unsigned int startTick3 = gm_GetTickCount();
    g_osGlobals->FUN_0086ff70();
    unsigned int dummy4 = 0;
    FUN_00558690 s;
    s.unk10 = gm_GetTickCount() - startTick3;
    ((NiRenderer_Shell*)FUN_0043c4b0())
        ->FUN_005585e0()
        ->FUN_00558600(&s.unk00, &dummy4, &s.unk04, &dummy4, &dummy4, &dummy4, &dummy4, &dummy4, &dummy4, &dummy4,
                       &dummy4);
    s.unk0c = ((ShadowSceneNode_Shell*)FUN_00450b80(0))->FUN_00b5ac60();
    bool bCondition = false;
    if (s.unk00 > limit->unk00)
        bCondition = true;
    else if (s.unk04 > limit->unk04)
        bCondition = true;
    else if (s.unk08 > limit->unk08)
        bCondition = true;
    else if (s.unk0c > limit->unk0c)
        bCondition = true;
    else if (s.unk14 > limit->unk14)
        bCondition = true;
    else if (s.unk10 > limit->unk10)
        bCondition = true;

    if (bCondition && limit->unk18)
    {
        s.unk18 = a1;
        s.pt = *apPosition;
        s.mat = *apRotation;
        ((void (*)(FUN_00558690*, unsigned int))limit->unk18)(&s, limit->unk1c);
    }
    return !bCondition;
}
}  // namespace fnv_00558430

int __cdecl FUN_00406d00(char*, int, const char*, ...);
int __cdecl CreateDirectoryChecked(const char*);
int __cdecl FUN_00aff0b0(const char*);
extern unsigned int DAT_010a2480;
struct StatsCell
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
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v4a();
    virtual void v4b();
    virtual const char* EditorID();
    bool FUN_00425fd0();
    const char* FUN_00401280();
    StatsCell* FUN_0054ddd0();
    int GetCellGridX();
    int GetCellGridY();
    unsigned int FUN_0084e3a0();
};
extern StatsCell* DAT_011ca218;
struct StatsMatrix
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
    void DecomposeToEulerAngles(float*, float*, float*);
};
struct RenderStats
{
    int geometryCount, triangleCount, newPassCount, activeLights, count;
    unsigned int flags;
    StatsCell* cell;
    float x, y, z;
    StatsMatrix rotation;
};
struct BSFile
{
    virtual ~BSFile();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void SetEndian(int, unsigned int);
    virtual void v18();
    virtual void v1c();
    virtual void Seek(int, int);
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void Write(const char*, int);
    unsigned int position, bufferSize, bufferPosition, bytesRead;
    void* buffer;
    void* handle;
    unsigned int mode, flags, error;
    char filename[260];
    unsigned int unk12c, unk130, unk134, unk138, unk13c, unk140;
    unsigned int unk144, unk148, unk14c, unk150, unk154;
    BSFile(const char*, int, unsigned int, bool);
};
// Writes a cell's render statistics (camera position/rotation, geometry, triangle, pass and light counts) to a per-cell RTF text file.
// @fnv 0x005586e0
void __cdecl WriteRenderStatsFile(RenderStats* stats)
{
    if (!stats)
    {
        DAT_011ca218 = 0;
        return;
    }
    CreateDirectoryChecked("RTF");
    const char* directory = ".\\RTF\\";
    float fRotX;
    {
        char filename[260];
        char line[260];
        {
            float rz;
            {
                float fRotY;
                {
                    BSFile* file;
                    if (stats->cell->FUN_00425fd0())
                    {
                        FUN_00406d00(filename, 260, "%sINT-%s.txt", directory, stats->cell->EditorID());
                    }
                    else
                    {
                        StatsCell* world = stats->cell->FUN_0054ddd0();
                        if (*stats->cell->FUN_00401280())
                        {
                            FUN_00406d00(filename, 260, "%sEXT-%s-(%i, %i)-%s.txt", directory, world->EditorID(),
                                         stats->cell->GetCellGridX(), stats->cell->GetCellGridY(),
                                         stats->cell->EditorID());
                        }
                        else
                        {
                            FUN_00406d00(filename, 260, "%sEXT-%s-(%i, %i).txt", directory, world->EditorID(),
                                         stats->cell->GetCellGridX(), stats->cell->GetCellGridY());
                        }
                    }
                    file = 0;
                    if (DAT_011ca218 != stats->cell)
                    {
                        FUN_00aff0b0(filename);
                        file = new BSFile(filename, 1, 0x4000, false);
                        file->Seek(0, 0);
                        file->SetEndian(0, DAT_010a2480);
                        FUN_00406d00(
                            line, 260,
                            "cell ID\tcamera pos\tcamera rot\tgeom count\ttri count\tnew pass count\tactive lights\r\n");
                        file->Write(line, FUN_0044a670(line));
                        DAT_011ca218 = stats->cell;
                    }
                    else
                    {
                        file = new BSFile(filename, 2, 0x4000, false);
                        file->Seek(0, 0);
                    }
                    stats->rotation.DecomposeToEulerAngles(&fRotX, &fRotY, &rz);
                    FUN_00406d00(line, 260, "(%08X)\t(%.2f, %.2f, %.2f)\t(%.2f, %.2f, %.2f)\t%i\t%i\t%i\t%i\t%i\r\n",
                                 stats->cell->FUN_0084e3a0(), stats->x, stats->y, stats->z, fRotX * 57.2957763671875,
                                 fRotY * 57.2957763671875, rz * 57.2957763671875, stats->count, stats->geometryCount,
                                 stats->triangleCount, stats->newPassCount, stats->activeLights);
                    file->Write(line, FUN_0044a670(line));
                    delete file;
                }
            }
        }
    }
}

struct ObstacleMapValue
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned char unk08;
    ObstacleMapValue(const ObstacleMapValue& other);
    ~ObstacleMapValue();
    ObstacleMapValue& operator=(const ObstacleMapValue& other);
};

struct ObstacleMapItem
{
    ObstacleMapItem* m_pkNext;
    unsigned int m_key;
    ObstacleMapValue m_val;
};

class ObstacleMap
{
  public:
    virtual ~ObstacleMap();
    virtual unsigned int KeyToHashIndex(unsigned int key);
    virtual bool IsKeysEqual(unsigned int key1, unsigned int key2);
    virtual void SetValue(ObstacleMapItem* item, unsigned int key, ObstacleMapValue val);
    virtual void ClearValue(ObstacleMapItem* item);
    virtual ObstacleMapItem* NewItem();

    unsigned int m_uiHashSize;
    ObstacleMapItem** m_ppkHashTable;
    unsigned int m_uiCount;

    void SetOrInsertValue(unsigned int key, ObstacleMapValue val);
};

// Looks up the key in the hash bucket, updates the matching item's value, or inserts a new item at the bucket head and increments the count.
// @fnv 0x00559260
void ObstacleMap::SetOrInsertValue(unsigned int key, ObstacleMapValue val)
{
    unsigned int index = KeyToHashIndex(key);
    ObstacleMapItem* item = m_ppkHashTable[index];
    int count = 0;
    while (item)
    {
        count++;
        if (IsKeysEqual(key, item->m_key))
        {
            item->m_val = val;
            return;
        }
        item = item->m_pkNext;
    }
    item = NewItem();
    SetValue(item, key, val);
    item->m_pkNext = m_ppkHashTable[index];
    m_ppkHashTable[index] = item;
    m_uiCount++;
}

namespace fnv_004375c0 {
struct Entry;
template <class T> struct SL
{
    T item;
    SL* next;
    T& FUN_006815c0();
    void FUN_0063f7b0();
    ~SL();
};
void FUN_00401030(void*);
struct FUN_0040ecb0
{
    virtual ~FUN_0040ecb0();
    int u4, u8;
};
struct FUN_004375c0 : FUN_0040ecb0
{
    SL<Entry*>* m_kNode;
    virtual ~FUN_004375c0();
};
// @fnv 0x004375c0
FUN_004375c0::~FUN_004375c0()
{
    SL<Entry*>* list = m_kNode;
    while (list && list->FUN_006815c0())
    {
        Entry* e = list->FUN_006815c0();
        list->FUN_0063f7b0();
        delete e;
    }
    delete m_kNode;
}
}  // namespace fnv_004375c0

namespace fnv_0054cfd0 {
class NiPoint3
{
  public:
    float x;
    float y;
    float z;
    NiPoint3(float x, float y, float z);
};

extern NiPoint3 NiPoint3_ZERO;

class GlobalObject_0045cf30
{
  public:
    unsigned char* Bool();
};

extern GlobalObject_0045cf30 g_011ca0a8;

class TESObjectCELL_Ext
{
  public:
    int GetCellGridX();
    int GetCellGridY();
    bool IsInterior();
    void FUN_00550340();
    void FUN_0054d090(NiPoint3* a, NiPoint3* b);
    void FUN_0054cfd0(NiPoint3* a, NiPoint3* b);
};

// @fnv 0x0054cfd0
void TESObjectCELL_Ext::FUN_0054cfd0(NiPoint3* pCenter, NiPoint3* b)
{
    *pCenter = NiPoint3((float)((GetCellGridX() << 12) + 0x800), (float)((GetCellGridY() << 12) + 0x800), 0.0f);
    *b = NiPoint3_ZERO;
    if (*g_011ca0a8.Bool())
    {
        if (!IsInterior())
            return;
    }
    FUN_00550340();
    FUN_0054d090(pCenter, b);
}
}  // namespace fnv_0054cfd0

class FormStub;
FormStub* FUN_004839c0(unsigned int auiFormId);  // LookupFormByID

class SkyObjectBase
{
  public:
    void FUN_008d0600(unsigned int uiFlags, int iArg);
};

class LinkedFormOwner : public SkyObjectBase
{
  public:
    FormStub* FUN_00546a40();
    void FUN_00546bf0(FormStub* pkForm);
    void UpdateLinkedForm(unsigned int uiFlags, int iArg);
};
// @fnv 0x005555d0
void LinkedFormOwner::UpdateLinkedForm(unsigned int uiFlags, int iArg)
{
    SkyObjectBase::FUN_008d0600(uiFlags, iArg);
    if (uiFlags & 8)
    {
        FormStub* pkForm = FUN_00546a40();
        if (pkForm)
        {
            unsigned int auiFormId = (unsigned int)pkForm;
            pkForm = FUN_004839c0(auiFormId);
            FUN_00546bf0(pkForm);
        }
    }
}

namespace fnv_00548880 {
struct FNV_Ref;
struct FNV_Form;
struct FNV_Node;
struct FNV_Sub;
struct FNV_Render;
struct FNV_Primitive;
struct FNV_Scene;
struct FNV_Effects;
struct FNV_SceneObject;
struct FNV_Flags;

struct NiPoint3
{
    float x, y, z;
};
struct NiPoint2
{
    float x, y;
    NiPoint2()
    {}
    NiPoint2(float, float);
};
struct ThreeByThreeMatrix
{
    float m[9];
};

class NiFixedString
{
  public:
    const char* m_data;
    NiFixedString(const char* s);
    ~NiFixedString();
};

inline void* operator new(unsigned int size, void* ptr)
{
    return ptr;
}

class NiMemObject
{
  public:
    static void* operator new(unsigned int size);
    static void operator delete(void* pointer, unsigned int);
};

extern void* DAT_011dea10;
extern FNV_Form* DAT_011ca230;
extern FNV_Form* DAT_011ca234;
extern FNV_Form* DAT_011ca238;
extern FNV_Form* DAT_011ca23c;
extern FNV_Form* DAT_011ca240;
extern FNV_Ref* DAT_011dea3c;
extern void* DAT_011ddf38;
extern float DAT_01016970;
extern float DAT_0118b694;

extern const char DAT_0102ede0[];
extern const char DAT_0102edc4[];

struct FNV_Indicator
{
    unsigned char* FUN_00408d60();
};
extern FNV_Indicator DAT_011c7adc;

struct FNV_GlobalCheck
{
    bool GetBoolValue();
};
extern FNV_GlobalCheck DAT_011ca118;

struct FNV_SaveLoad
{
    bool FUN_0042ce10();
};

struct FNV_TESResult
{
    void FUN_004e46b0();
};

struct FNV_TES
{
    void FUN_0045ce40();
    FNV_TESResult* FUN_0070ec90(FNV_Ref*);
};

struct FNV_WorldEntity
{
    void FUN_00937090(int);
};

struct FNV_World
{
    FNV_WorldEntity* FUN_0059bb30();
};

struct FNV_Node
{
    FNV_Node* FUN_00586170(FNV_Ref*, int);
    FNV_Node* FUN_00586170(int);
    void FUN_006fcfa0();
    void FUN_00929260();
    FNV_Flags* FUN_00a5bdd0(void*);
    virtual void v_0();
    virtual void v_4();
    virtual void v_8();
    virtual void v_c();
    virtual FNV_Render* v10();
    virtual void v_14();
    virtual void v_18();
    virtual void v_1c();
    virtual void v_20();
    virtual void v_24();
    virtual void v_28();
    virtual void v_2c();
    virtual void v_30();
    virtual void v_34();
    virtual void v_38();
    virtual void v_3c();
    virtual void v_40();
    virtual void v_44();
    virtual void v_48();
    virtual void v_4c();
    virtual void v_50();
    virtual void v_54();
    virtual void v_58();
    virtual void v_5c();
    virtual void v_60();
    virtual void v_64();
    virtual void v_68();
    virtual void v_6c();
    virtual void v_70();
    virtual void v_74();
    virtual void v_78();
    virtual void v_7c();
    virtual void v_80();
    virtual void v_84();
    virtual void v_88();
    virtual void v_8c();
    virtual void v_90();
    virtual void v_94();
    virtual void v_98();
    virtual void v_9c();
    virtual void v_a0();
    virtual void v_a4();
    virtual void v_a8();
    virtual void v_ac();
    virtual void v_b0();
    virtual void v_b4();
    virtual void v_b8();
    virtual void v_bc();
    virtual void v_c0();
    virtual void v_c4();
    virtual void v_c8();
    virtual void v_cc();
    virtual void v_d0();
    virtual void v_d4();
    virtual void v_d8();
    virtual void vdc(void*);
};

struct FNV_Form
{
    int FUN_00401170();
    bool FUN_00549580();
    bool FUN_00549630();
};

struct FNV_Sub
{
    bool FUN_00420810();
    FNV_Render* FUN_00420ed0();
    FNV_Primitive* FUN_0041fbe0();
    void FUN_00420f00(void*);
    void FUN_00420e00(void*);
    FNV_Ref** FUN_00420410();
    FNV_Ref* FUN_004208b0();
    void* FUN_00422120();
    void FUN_00422150(void*);
    void* FUN_00421e10();
    int FUN_00420dd0();
};

struct FNV_Render
{
    FNV_Render* FUN_006629f0();
    FNV_Render* FUN_0043b230();
    void FUN_0049ee60(int);
    void FUN_00705b10(int);
    void FUN_00b4dfd0(float, float);
    void UpdateFade(void*);
    void FUN_009707f0(int);
    void FUN_00420ba0(int);
    void FUN_00476ab0();
    FNV_Node* FUN_00545960(void*);
    void FUN_00a5a040();
    virtual void v_0();
    virtual void v_4();
    virtual void v_8();
    virtual void v_c();
    virtual FNV_Render* v10();
    virtual void v_14();
    virtual void v_18();
    virtual void v_1c();
    virtual void v_20();
    virtual void v_24();
    virtual void v_28();
    virtual void v_2c();
    virtual void v_30();
    virtual void v_34();
    virtual void v_38();
    virtual void v_3c();
    virtual void v_40();
    virtual void v_44();
    virtual void v_48();
    virtual void v_4c();
    virtual void v_50();
    virtual void v_54();
    virtual void v_58();
    virtual void v_5c();
    virtual void v_60();
    virtual void v_64();
    virtual void v_68();
    virtual void v_6c();
    virtual void v_70();
    virtual void v_74();
    virtual void v_78();
    virtual void v_7c();
    virtual void v_80();
    virtual void v_84();
    virtual void v_88();
    virtual void v_8c();
    virtual void v_90();
    virtual void v_94();
    virtual void v_98();
    virtual void v_9c();
    virtual void v_a0();
    virtual void v_a4();
    virtual void v_a8();
    virtual void v_ac();
    virtual void v_b0();
    virtual void v_b4();
    virtual void vb8(void*);
};

struct FNV_Primitive
{
    void FUN_00413fc0(NiPoint3*);
    virtual void v_0();
    virtual void v_4();
    virtual void v_8();
    virtual void v_c();
    virtual void v_10();
    virtual void* v14(NiPoint3*);
    virtual void v_18();
    virtual int v1c();
};

struct ClassEC : public NiMemObject
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
    ClassEC();
    void FUN_00439920(void*);
};

struct BSMultiBound : public NiMemObject
{
    int unk04;
    int unk08;
    int unk0c;
    BSMultiBound();
    void FUN_004addc0(void*);
    virtual void v_0();
    virtual void v_4();
    virtual void v_8();
    virtual void v_c();
    virtual void v_10();
    virtual void v_14();
    virtual void v_18();
    virtual void v_1c();
    virtual void v_20();
    virtual void v_24();
    virtual void v_28();
    virtual void v_2c();
    virtual void v_30();
    virtual void v_34();
    virtual void v_38();
    virtual void v_3c();
    virtual void v_40();
    virtual void v_44();
    virtual void v_48();
    virtual void v_4c();
    virtual void v_50();
    virtual void v_54();
    virtual void v_58();
    virtual void v_5c();
    virtual void v_60();
    virtual void v_64();
    virtual void v_68();
    virtual void v_6c();
    virtual void v_70();
    virtual void v_74();
    virtual void v_78();
    virtual void v_7c();
    virtual void v_80();
    virtual void v_84();
    virtual void v_88();
    virtual void v_8c();
    virtual void v90(void*);
};

struct ClassC4 : public NiMemObject
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
    ClassC4(FNV_SceneObject*);
    void SetName(const NiFixedString&);
};

struct ClassFC : public NiMemObject
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
    ClassFC();
    void FUN_00416a70(const ThreeByThreeMatrix&);
    void FUN_004169f0(void*);
    void FUN_00416a30(NiPoint2*);
};

struct CellOffsets
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
    short unkA8;
    short unkAA;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    float unkC8;
    short unkCC;
    char unkCE;
    char unkCF;
    char unkD0;
};

struct FNV_Scene
{
    virtual void v_0();
    virtual void v_4();
    virtual void v_8();
    virtual void v_c();
    virtual void v_10();
    virtual void v_14();
    virtual void v_18();
    virtual void v_1c();
    virtual void v_20();
    virtual void v_24();
    virtual void v_28();
    virtual void v_2c();
    virtual void v_30();
    virtual void v_34();
    virtual void v_38();
    virtual void v_3c();
    virtual void v_40();
    virtual void v_44();
    virtual void v_48();
    virtual void v_4c();
    virtual void v_50();
    virtual void v_54();
    virtual void v_58();
    virtual void v_5c();
    virtual void v_60();
    virtual void v_64();
    virtual void v_68();
    virtual void v_6c();
    virtual void v_70();
    virtual void v_74();
    virtual void v_78();
    virtual void v_7c();
    virtual void v_80();
    virtual void v_84();
    virtual void v_88();
    virtual void v_8c();
    virtual void v_90();
    virtual void v_94();
    virtual void v_98();
    virtual void v_9c();
    virtual void v_a0();
    virtual void v_a4();
    virtual void v_a8();
    virtual void v_ac();
    virtual void v_b0();
    virtual void v_b4();
    virtual void v_b8();
    virtual void v_bc();
    virtual void v_c0();
    virtual void v_c4();
    virtual void v_c8();
    virtual void v_cc();
    virtual void v_d0();
    virtual void v_d4();
    virtual void v_d8();
    virtual void vdc(void*, int);
};

struct FNV_Effects
{
    void FUN_00c5aef0(void*);
    FNV_Scene* FUN_00546930();
    void FUN_00c5b140(int);
};

struct FNV_Flags
{
    bool HasFlagOne();
};

struct FNV_SceneObject
{
    void FUN_004169f0(void*);
    void FUN_00416a70(const ThreeByThreeMatrix&);
    void FUN_00549610(ClassC4*);
};

struct FNV_LinkedDest
{
    FNV_LinkedDest* FUN_006ab360(void*);
    void FUN_004ed8c0();
};

struct FNV_Ref
{
    void* FUN_0043fcd0();
    FNV_Form* FUN_007af430();
    void* FUN_00575d70();
    FNV_Sub* FUN_005d43c0();
    NiPoint3* FUN_00430830();
    int FUN_005699b0();
    bool FUN_004077c0();
    bool FUN_00444ed0();
    bool FUN_005694c0();
    bool FUN_00564e60();
    bool FUN_00564f00();
    ThreeByThreeMatrix FUN_0056fa00();
    FNV_Render* FUN_008d6f30();
    unsigned int FUN_0084e3a0();
    void* FUN_00950bb0(int, int);
    FNV_Render* FUN_00950bb0(int);
    virtual void v_0();
    virtual void v_4();
    virtual void v_8();
    virtual void v_c();
    virtual void v_10();
    virtual void v_14();
    virtual void v_18();
    virtual void v_1c();
    virtual void v_20();
    virtual void v_24();
    virtual void v_28();
    virtual void v_2c();
    virtual void v_30();
    virtual void v_34();
    virtual void v_38();
    virtual void v_3c();
    virtual void v_40();
    virtual void v_44();
    virtual void v_48();
    virtual void v_4c();
    virtual void v_50();
    virtual void v_54();
    virtual void v_58();
    virtual void v_5c();
    virtual void v_60();
    virtual void v_64();
    virtual void v_68();
    virtual void v_6c();
    virtual void v_70();
    virtual void v_74();
    virtual void v_78();
    virtual void v_7c();
    virtual void v_80();
    virtual void v_84();
    virtual void v_88();
    virtual void v_8c();
    virtual void v_90();
    virtual void v_94();
    virtual void v_98();
    virtual void v_9c();
    virtual void v_a0();
    virtual void v_a4();
    virtual void v_a8();
    virtual void v_ac();
    virtual void v_b0();
    virtual void v_b4();
    virtual void v_b8();
    virtual void v_bc();
    virtual void v_c0();
    virtual void v_c4();
    virtual void v_c8();
    virtual void v_cc();
    virtual void v_d0();
    virtual void v_d4();
    virtual void v_d8();
    virtual void v_dc();
    virtual void v_e0();
    virtual void v_e4();
    virtual void v_e8();
    virtual void v_ec();
    virtual void v_f0();
    virtual void v_f4();
    virtual void v_f8();
    virtual void v_fc();
    virtual bool v100();
    virtual void v_104();
    virtual void v_108();
    virtual void v_10c();
    virtual void v_110();
    virtual void v_114();
    virtual void v_118();
    virtual void v_11c();
    virtual void v_120();
    virtual void v_124();
    virtual void v_128();
    virtual void v_12c();
    virtual void v_130();
    virtual void v_134();
    virtual void v_138();
    virtual void v_13c();
    virtual void v_140();
    virtual void v_144();
    virtual void v_148();
    virtual void v_14c();
    virtual void v_150();
    virtual void v_154();
    virtual void v_158();
    virtual void v_15c();
    virtual void v_160();
    virtual void v_164();
    virtual void v_168();
    virtual void v_16c();
    virtual void v_170();
    virtual void v_174();
    virtual void v_178();
    virtual void v_17c();
    virtual void v_180();
    virtual void v_184();
    virtual void v_188();
    virtual void v_18c();
    virtual void v_190();
    virtual void v_194();
    virtual void v_198();
    virtual void v_19c();
    virtual void v_1a0();
    virtual void v_1a4();
    virtual void v_1a8();
    virtual void v_1ac();
    virtual void* v1b0(int, int);
    virtual void v_1b4();
    virtual void v_1b8();
    virtual void v_1bc();
    virtual void v_1c0();
    virtual void v_1c4();
    virtual void v_1c8();
    virtual void v_1cc();
    virtual FNV_Node* v1d0();
    virtual void v_1d4();
    virtual void v_1d8();
    virtual void v_1dc();
    virtual void v_1e0();
    virtual void v_1e4();
    virtual void v_1e8();
    virtual void v_1ec();
    virtual void v_1f0();
    virtual void* v1f4();
    virtual void v_1f8();
    virtual void v_1fc();
    virtual void v_200();
    virtual void v_204();
    virtual void v_208();
    virtual void v_20c();
    virtual void v_210();
    virtual void v_214();
    virtual void v_218();
    virtual void v_21c();
    virtual void v_220();
    virtual bool v224();
};

struct FNV_Cell : TESObjectCELL
{
    virtual void v_0();
    virtual void v_4();
    virtual void v_8();
    virtual void v_c();
    virtual void v_10();
    virtual void v_14();
    virtual void v_18();
    virtual void v_1c();
    virtual void v_20();
    virtual void v_24();
    virtual void v_28();
    virtual void v_2c();
    virtual void v_30();
    virtual void v_34();
    virtual void v_38();
    virtual void v_3c();
    virtual void v_40();
    virtual void v_44();
    virtual void v_48();
    virtual void v_4c();
    virtual void v_50();
    virtual void v_54();
    virtual void v_58();
    virtual void v_5c();
    virtual void v_60();
    virtual void v_64();
    virtual void v_68();
    virtual void v_6c();
    virtual void v_70();
    virtual void v_74();
    virtual void v_78();
    virtual void v_7c();
    virtual void v_80();
    virtual void v_84();
    virtual void v_88();
    virtual void v_8c();
    virtual void v_90();
    virtual void v_94();
    virtual void v_98();
    virtual void v_9c();
    virtual void v_a0();
    virtual void v_a4();
    virtual void v_a8();
    virtual void v_ac();
    virtual void v_b0();
    virtual void v_b4();
    virtual void v_b8();
    virtual void v_bc();
    virtual void v_c0();
    virtual void v_c4();
    virtual void v_c8();
    virtual void v_cc();
    virtual void v_d0();
    virtual void v_d4();
    virtual void v_d8();
    virtual void v_dc();
    virtual void v_e0();
    virtual void v_e4();
    virtual void v_e8();
    virtual void v_ec();
    virtual void v_f0();
    virtual void v_f4();
    virtual void v_f8();
    virtual void v_fc();
    virtual void v_100();
    virtual void v_104();
    virtual void v_108();
    virtual void v_10c();
    virtual void v_110();
    virtual void v_114();
    virtual void v_118();
    virtual void v_11c();
    virtual void v_120();
    virtual void v_124();
    virtual void v_128();
    virtual void v_12c();
    virtual const char* cv130();
    void FUN_00548880(FNV_Ref*, int);
    FNV_World* FUN_004543c0();
    bool FUN_00425fd0();
    bool FUN_004518e0();
    unsigned int FUN_0084e3a0();
    FNV_Node* FUN_00456fc0(int);
    FNV_Effects* FUN_009d9f20();
    void RegisterReferenceInCell(FNV_Ref*);
    void FUN_005453b0(FNV_Ref*);
    void AddValueToHead(FNV_Ref*);
    FNV_Node* FUN_005495d0();
    FNV_Node* FUN_005495f0();
    bool FUN_005495a0();
    bool FUN_00557d10();
    void FUN_00557aa0();
    void FUN_005496b0(FNV_Ref*, FNV_Node*);
};

extern "C"
{
    void __cdecl FUN_005b5e40(const char*, ...);
    void* __cdecl FUN_00448a80();
    bool __cdecl FUN_00565580(void*);
    void __cdecl FUN_004e46b0();
    bool __cdecl FUN_008c7aa0();
    void __cdecl FUN_0054abd0(FNV_Ref*, FNV_Node*);
    void __cdecl FUN_00476ab0(void*);
    void __cdecl FUN_00b6bb30(void*, float);
    FNV_Render* __stdcall FUN_0045c670(int);
    bool __cdecl FUN_00705e80();
}

// Places a reference into the cell by selecting a node based on the reference's form type and attaching it to the scene graph.
// @fnv 0x00548880
void FNV_Cell::FUN_00548880(FNV_Ref* reference, int unused)
{
    FNV_Node* Dir2;
    bool Diff5 = false;
    if (reference == 0 || reference->FUN_0043fcd0() == 0)
    {
        return;
    }

    if (reference->FUN_007af430()->FUN_00549580())
    {
        FNV_Node* Diff6 = (FNV_Node*)reference->FUN_00575d70();
        if (Diff6)
        {
            Diff6->FUN_00586170(reference, 1)->FUN_006fcfa0();
            Diff6->FUN_00586170(1)->FUN_00929260();
        }
    }

    if (reference->FUN_007af430() != 0 && reference->FUN_007af430()->FUN_00401170() == 0x23)
    {
        ((FNV_TES*)DAT_011dea10)->FUN_0045ce40();
        if (FUN_004543c0()->FUN_0059bb30())
        {
            FUN_004543c0()->FUN_0059bb30()->FUN_00937090(1);
        }
        if (FUN_00425fd0() && !FUN_004518e0())
        {
            FUN_005b5e40(DAT_0102ede0, reference->FUN_0084e3a0(), FUN_0084e3a0(), cv130());
            if (!*DAT_011c7adc.FUN_00408d60())
            {
                return;
            }
        }
    }

    Dir2 = 0;
    if (reference->v100())
    {
        Dir2 = FUN_00456fc0(0);
    }
    else if (reference->FUN_007af430() == DAT_011ca230)
    {
        Dir2 = FUN_00456fc0(1);
    }
    else if (reference->FUN_007af430() == DAT_011ca238)
    {
        if (reference->FUN_005d43c0()->FUN_00420810())
        {
            FNV_Effects* EndLocTmp;
            FNV_Render* EndLoc2;
            void* EntryLoc9;
            int Diff;
            if (!reference->FUN_005d43c0()->FUN_00420ed0())
            {
                Diff = reference->FUN_005699b0();
                if (!Diff)
                {
                    BSMultiBound* Dir9;
                    ClassEC* Dir5;
                    NiPoint3 DiffB = *reference->FUN_00430830();
                    EntryLoc9 = reference->FUN_005d43c0()->FUN_0041fbe0()->v14(&DiffB);
                    Dir5 = new ClassEC();
                    Dir9 = new BSMultiBound();
                    Dir5->FUN_00439920(Dir9);
                    Dir9->FUN_004addc0(EntryLoc9);
                    Dir9->v90(reference->v1f4());
                    reference->FUN_005d43c0()->FUN_00420f00(Dir5);
                }
            }
            EndLoc2 = reference->FUN_005d43c0()->FUN_00420ed0();
            EndLoc2->FUN_006629f0()->FUN_0043b230()->vb8(reference->v1f4());
            EndLocTmp = FUN_009d9f20();
            EndLocTmp->FUN_00c5aef0(EndLoc2);
        }
        Dir2 = FUN_00456fc0(1);
    }
    else if (reference->FUN_007af430() == DAT_011ca23c && !reference->FUN_004077c0())
    {
        if (!reference->FUN_005d43c0()->FUN_00420dd0())
        {
            FNV_Primitive* LeftX = reference->FUN_005d43c0()->FUN_0041fbe0();
            FNV_SceneObject* EntryLoc7 = (FNV_SceneObject*)LeftX->v1c();
            if (EntryLoc7)
            {
                FNV_Ref** EntryLocVal;
                ClassC4* DiffA;
                int Diff_2;
                FNV_Effects* DiffX;
                EntryLoc7->FUN_004169f0(reference->v1f4());
                EntryLoc7->FUN_00416a70(reference->FUN_0056fa00());
                reference->FUN_005d43c0()->FUN_00420e00(EntryLoc7);
                DiffA = new ClassC4(EntryLoc7);
                DiffA->SetName(NiFixedString(DAT_0102edc4));
                EntryLoc7->FUN_00549610(DiffA);
                DiffX = FUN_009d9f20();
                DiffX->FUN_00546930()->vdc(DiffA, 1);
                EntryLocVal = reference->FUN_005d43c0()->FUN_00420410();
                if (EntryLocVal)
                {
                    for (Diff_2 = 0; Diff_2 < 2; ++Diff_2)
                    {
                        if (EntryLocVal && EntryLocVal[Diff_2])
                        {
                            int Diff4 = EntryLocVal[Diff_2]->FUN_005699b0();
                            if (!Diff4)
                            {
                                Diff4 = EntryLocVal[Diff_2]->FUN_005d43c0()->FUN_004208b0()->FUN_005699b0();
                            }
                            if (Diff4)
                            {
                                ((FNV_LinkedDest*)Diff4)->FUN_006ab360(&EntryLoc7)->FUN_004ed8c0();
                                if (Diff_2 == 0)
                                {
                                    ((FNV_Render*)EntryLoc7)->FUN_009707f0(Diff4);
                                }
                                else
                                {
                                    ((FNV_Render*)EntryLoc7)->FUN_00420ba0(Diff4);
                                }
                            }
                        }
                        else
                        {
                            FNV_Effects* ExitLoc5 = FUN_009d9f20();
                            ExitLoc5->FUN_00c5b140((int)EntryLoc7);
                        }
                    }
                }
            }
        }
        Dir2 = FUN_00456fc0(6);
    }
    else if (reference->FUN_007af430() == DAT_011ca234)
    {
        NiPoint3 Diff3;
        FNV_Primitive* Diff9;
        ClassFC* Diff7;
        Dir2 = FUN_00456fc0(5);
        Diff7 = (ClassFC*)reference->FUN_005d43c0()->FUN_00422120();
        if (!Diff7)
        {
            Diff7 = new ClassFC();
            reference->FUN_005d43c0()->FUN_00422150(Diff7);
        }
        Diff7->FUN_00416a70(reference->FUN_0056fa00());
        Diff7->FUN_004169f0(reference->v1f4());
        Diff9 = reference->FUN_005d43c0()->FUN_0041fbe0();
        if (Diff9)
        {
            Diff9->FUN_00413fc0(&Diff3);
            NiPoint2 DiffVal(Diff3.x, Diff3.z);
            Diff7->FUN_00416a30(&DiffVal);
        }
    }
    else if (reference->FUN_007af430() == DAT_011ca240)
    {
        Dir2 = FUN_00456fc0(8);
    }
    else if (reference->FUN_00444ed0() && reference->FUN_007af430()->FUN_00401170() == 0x1e)
    {
        Dir2 = FUN_005495d0();
        if (!reference->FUN_007af430()->FUN_00549630())
        {
            RegisterReferenceInCell(reference);
        }
    }
    else if (reference->FUN_00444ed0() || reference->FUN_005d43c0()->FUN_0041fbe0())
    {
        switch (reference->FUN_007af430()->FUN_00401170())
        {
        case 0xe:
            Dir2 = FUN_005495f0();
            break;
        default:
            Dir2 = FUN_00456fc0(1);
            break;
        }
    }
    else if (reference->FUN_007af430()->FUN_00401170() == 0xd)
    {
        Dir2 = FUN_005495f0();
    }
    else
    {
        void* a1cTmp;
        FNV_Flags* Dir7;
        FNV_Flags* Dir3;
        if (reference->FUN_007af430()->FUN_00401170() == 0x25)
        {
            RegisterReferenceInCell(reference);
        }
        else if (reference->v224())
        {
            Dir2 = FUN_00456fc0(4);
        }
        else if (reference->FUN_007af430() && reference->FUN_007af430()->FUN_00401170() == 0x1e &&
                 !reference->FUN_007af430()->FUN_00549630())
        {
            RegisterReferenceInCell(reference);
        }
        else
        {
            Dir3 = (FNV_Flags*)((FNV_Node*)reference->v1d0())->FUN_00a5bdd0(FUN_00448a80());
            if (Dir3)
            {
                Dir7 = Dir3;
                if (Dir7->HasFlagOne())
                {
                    if (FUN_00565580(reference->v1d0()))
                    {
                        Diff5 = true;
                        RegisterReferenceInCell(reference);
                    }
                }
            }
        }
        if (!Dir2 && DAT_011ca118.GetBoolValue())
        {
            a1cTmp = reference->FUN_005d43c0()->FUN_00421e10();
            if (a1cTmp)
            {
                Dir2 = reference->FUN_008d6f30()->FUN_00545960(a1cTmp);
            }
        }
        if (!Dir2)
        {
            Dir2 = FUN_00456fc0(3);
        }
    }

    if (reference->FUN_005694c0())
    {
        FUN_005453b0(reference);
    }
    if (reference->FUN_007af430()->FUN_00401170() == 0x23)
    {
        AddValueToHead(reference);
        ((FNV_TES*)DAT_011dea10)->FUN_0070ec90(reference)->FUN_004e46b0();
    }

    if (Dir2)
    {
        FNV_Render* EntryLoc;
        FNV_Render* Diff2;
        if (reference == DAT_011dea3c)
        {
            Dir2->vdc(DAT_011dea3c->FUN_00950bb0(0, 1));
            DAT_011dea3c->FUN_00950bb0(0)->FUN_00a5a040();
            Diff2 = DAT_011dea3c->FUN_00950bb0(0)->v10();
            if (Diff2)
                Diff2->FUN_00476ab0();
            Dir2->vdc(DAT_011dea3c->FUN_00950bb0(1, 1));
            DAT_011dea3c->FUN_00950bb0(1)->FUN_00a5a040();
        }
        else
        {
            if (!FUN_008c7aa0())
            {
                FUN_005496b0(reference, Dir2);
            }
            else
            {
                FUN_0054abd0(reference, Dir2);
            }

            EntryLoc = ((FNV_Render*)reference->FUN_0043fcd0())->v10();
            if (EntryLoc)
            {
                if (reference->FUN_007af430()->FUN_00549580())
                {
                    EntryLoc->FUN_0049ee60(1);
                }
                else if (reference->FUN_00564e60())
                {
                    EntryLoc->FUN_00705b10(6);
                }
                else if (reference->FUN_00564f00())
                {
                    EntryLoc->FUN_00705b10(10);
                    EntryLoc->FUN_00b4dfd0(DAT_01016970, DAT_01016970);
                }
                if (FUN_00705e80() || ((FNV_SaveLoad*)DAT_011ddf38)->FUN_0042ce10())
                {
                    EntryLoc->FUN_00476ab0();
                    FUN_00b6bb30(EntryLoc, 1.0f);
                    ((CellOffsets*)this)->unkC8 = DAT_0118b694;
                    ((CellOffsets*)this)->unkCE = 0;
                    ((CellOffsets*)this)->unkCF = 0;
                    ((CellOffsets*)this)->unkD0 = 1;
                }
                else
                {
                    EntryLoc->UpdateFade(FUN_0045c670(Diff5)->FUN_006629f0());
                }
                if (((CellOffsets*)this)->unkAA > 0 && FUN_005495a0() && FUN_00557d10())
                {
                    FUN_00557aa0();
                }
            }
        }
    }
}
}  // namespace fnv_00548880

namespace fnv_0054ca90 {
struct Ref;
struct Extra
{
    void FUN_0041d390(int);
    Ref** GetValue76();
};
struct Ref
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
    virtual void clear(int);
    bool FUN_00564e60();
    void* FUN_00567d20();
    void FUN_00567dd0(void*);
    bool FUN_005656d0();
    bool FUN_0056a250();
    Extra* FUN_005d43c0();
    void* FUN_007af430();
    bool FUN_004077c0();
    bool FUN_005653d0();
};
struct Handler
{
    bool FUN_004516b0();
    bool FUN_004226e0();
};
struct Loaded
{
    void FUN_005270b0(Ref*);
};
struct State
{
    bool FUN_004121b0();
};
struct Owner
{
    void FUN_00587e40(Ref*);
};
struct List
{
    void FUN_00905330(Ref**);
};
extern "C" char DAT_011c3f2c;
extern "C" char DAT_011ddf38;
extern "C" char DAT_011ca234;
void* FUN_00546a90();
struct Cell
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
    virtual void dirty(int);
    char pad[0xa4];
    unsigned short count;
    char pad2[0x1a];
    void* data;
    void* FUN_00546c20();
    void FUN_00541ac0();
    List* FUN_009604f0();
    void FUN_00541ae0();
    bool FUN_00450ff0();
    bool FUN_004523c0();
    void FUN_00545590(Ref*);
    void FUN_00545670(Ref*);
    void FUN_00545360(Ref*);
    void FUN_005454f0(Ref*);
    bool FUN_005516c0();
    Owner* FUN_0054ddd0();
    void FUN_0054ca90(Ref* ref);
};
// @fnv 0x0054ca90
void Cell::FUN_0054ca90(Ref* ref)
{
    if (!ref)
        return;
    if (ref->FUN_00564e60())
        --count;
    if (!ref->FUN_00567d20() && !(*(Handler**)&DAT_011c3f2c)->FUN_004516b0())
    {
        if (FUN_00546c20())
            ref->FUN_00567dd0(FUN_00546c20());
        else
            ref->FUN_00567dd0(FUN_00546a90());
    }
    FUN_00541ac0();
    FUN_009604f0()->FUN_00905330(&ref);
    FUN_00541ae0();
    if (FUN_00450ff0() || FUN_004523c0())
        ((Loaded*)DAT_011c95c8)->FUN_005270b0(ref);
    if (data)
    {
        bool enabled = false;
        enabled = (*(State**)&DAT_011ddf38)->FUN_004121b0();
        if (enabled || ref->FUN_005656d0())
            FUN_00545590(ref);
        if (ref->FUN_0056a250())
            FUN_00545670(ref);
        FUN_00545360(ref);
        FUN_005454f0(ref);
    }
    if (FUN_005516c0())
    {
        ref->FUN_005d43c0()->FUN_0041d390(0);
        Owner* owner = FUN_0054ddd0();
        if (owner)
            owner->FUN_00587e40(ref);
    }
    else
    {
        ref->clear(0);
        if (ref->FUN_007af430() == *(void**)&DAT_011ca234)
        {
            Ref** ppLinks = ref->FUN_005d43c0()->GetValue76();
            if (ppLinks)
            {
                for (int i = 0; i < 4; ++i)
                {
                    if (ppLinks[i])
                    {
                        Ref** ppBack = ppLinks[i]->FUN_005d43c0()->GetValue76();
                        if (ppBack)
                        {
                            for (int j = 0; j < 4; ++j)
                            {
                                if (ppBack[j] == ref)
                                    ppBack[j] = 0;
                            }
                        }
                    }
                }
            }
        }
        if (!ref->FUN_004077c0() && !ref->FUN_005653d0() && !(*(Handler**)&DAT_011c3f2c)->FUN_004226e0())
            dirty(1);
    }
}
}  // namespace fnv_0054ca90

namespace fnv_00550500 {
struct TESRecordHeader;
struct File;
struct List;

struct TESRecordHeader
{
    unsigned int sig;
    unsigned int unk4;
    unsigned int flags;
    unsigned int type;
};

struct List
{
    bool FUN_008256d0();
};

struct File
{
    bool FUN_00471c20();
    TESRecordHeader* GetRecordHeader();
    unsigned int GetFormID();
    bool FUN_00472150(bool arg);
    void FUN_00473660();
    List* FUN_00464df0();
};

struct Handler
{
    void SetBoolAt61a(bool arg);
    bool ConstructObject(File* file, bool a, void* form, bool b);
};

struct SaveLoad
{
    bool SetThreadAllowChanges(bool arg);
    bool FUN_0042ce10();
    bool FUN_00849cc0(unsigned int id);
};

struct Cell
{
    unsigned int FUN_0084e3a0();
    bool FUN_00550500(File* file);
};

bool FUN_00554810(TESRecordHeader* hdr);
bool FUN_005548a0(int v);
int FindFormEnumIndex(unsigned int sig);
void FUN_005516a0(bool arg);
bool FUN_00473ff0(unsigned int id, File* file);
void* FUN_004839c0(unsigned int id);

extern unsigned int DAT_011872b4;
extern unsigned int kGroupFormType;
extern Cell* DAT_011c3f30;
extern Handler* g_dataHandler;
extern SaveLoad* g_saveLoad;

// Loads this cell's record from the save file, validating group headers and constructing referenced objects, returning whether all constructions succeeded.
// @fnv 0x00550500
bool Cell::FUN_00550500(File* file)
{
    if (!file)
        return false;
    if (!file->FUN_00471c20())
        return true;
    TESRecordHeader* hdr4 = file->GetRecordHeader();
    if (hdr4->sig == DAT_011872b4)
    {
        if (file->GetFormID() != FUN_0084e3a0())
            return false;
        file->FUN_00472150(true);
        hdr4 = file->GetRecordHeader();
        if (!FUN_00554810(hdr4))
            return true;
        if (hdr4->sig != kGroupFormType || hdr4->type != 6)
            return false;
        file->FUN_00472150(true);
        hdr4 = file->GetRecordHeader();
        if (hdr4->sig != kGroupFormType)
            return false;
        if (hdr4->type == 8)
        {
            file->FUN_00473660();
            hdr4 = file->GetRecordHeader();
            if (!FUN_00554810(hdr4))
                return true;
        }
    }
    if (hdr4->sig != kGroupFormType)
        return false;
    if (hdr4->type != 9)
        return false;
    if (file->FUN_00472150(true))
        hdr4 = file->GetRecordHeader();
    else
        hdr4 = 0;
    DAT_011c3f30 = this;
    g_dataHandler->SetBoolAt61a(true);
    if (hdr4 && hdr4->sig == kGroupFormType && hdr4->type == 9)
    {
        if (file->FUN_00472150(true))
            hdr4 = file->GetRecordHeader();
        else
            hdr4 = 0;
    }
    FUN_005516a0(true);
    bool saved = g_saveLoad->SetThreadAllowChanges(false);
    bool ok5 = true;
    while (hdr4 && FUN_005548a0(FindFormEnumIndex(hdr4->sig)))
    {
        unsigned int id4 = file->GetFormID();
        if (FUN_00473ff0(id4, file))
        {
            void* p2 = FUN_004839c0(id4);
            bool b6 = false;
            if (!g_saveLoad->FUN_0042ce10())
                b6 = g_saveLoad->FUN_00849cc0(id4);
            bool b2 = false;
            if (file->FUN_00471c20() && !file->FUN_00464df0()->FUN_008256d0() &&
                (file->GetRecordHeader()->flags & 0x20) != 0)
                b2 = true;
            if (!p2 && !b6 && !b2)
            {
                if (!g_dataHandler->ConstructObject(file, false, p2, false))
                    ok5 = false;
            }
        }
        if (file->FUN_00472150(true))
            hdr4 = file->GetRecordHeader();
        else
            hdr4 = 0;
        if (hdr4 && hdr4->sig == kGroupFormType && hdr4->type == 9 && hdr4->flags == FUN_0084e3a0())
        {
            if (file->FUN_00472150(true))
                hdr4 = file->GetRecordHeader();
            else
                hdr4 = 0;
        }
    }
    FUN_005516a0(false);
    g_saveLoad->SetThreadAllowChanges(saved);
    DAT_011c3f30 = 0;
    g_dataHandler->SetBoolAt61a(false);
    return ok5;
}
}  // namespace fnv_00550500

namespace fnv_00552970 {
// 0x00552970  unit_9e852b306d07.cpp  /MT /Od /Oy- /GS /EHsc /Gy
struct AutoMemHelper
{
    int field;
    AutoMemHelper(int context, bool flag, const char* file, int line);
    ~AutoMemHelper();
};

struct ShNiVt
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
    virtual void v55(void* idleForm, bool queued);
};

struct ShWorld
{
    void FUN_00454380(bool flag);
    void SetProcessEnabled(int flag);
};

struct ShCell
{
    unsigned char FUN_00552bb0();
    void FUN_006a37a0(void* owner, int mode);
};

struct ShPortalGraph
{
    void FUN_00b5ddf0(void* graph5);
    unsigned int FUN_00c5b5d0();
    void FUN_00c5b1c0(void* object);
    void FUN_00c5b9a0(void* object);
    void* FUN_00546930();
};

struct ShSceneNode
{
    void FUN_00b5ddf0(void* graph5);
    void* FUN_0045bc00(unsigned int index);
};

struct ShNavMgr
{
    void FUN_006c1170();
};

struct FUN_00552970_Call
{
    int field00;
    char pad04[0xcd];
    unsigned char fieldD1;

    int GetOrCreateWidget();
    void SetState(int mode);
    void FUN_005535f0();
    void FUN_0054ba80(int flag);
    void FUN_005577b0(int flag);
    void FUN_0054b950(int flag);
    void FUN_00557470();
    void UpdateNavMeshObstacles();
    void* FUN_009d9f20();
    void* FUN_0054a050();
    void* FUN_00456fc0(int index);
    void* FUN_0054aa60();
    void* FUN_00524cf0();
    void* FUN_004543c0();
    void* GetDynamicNode();
    bool IsInterior();
    void UpdateCellScene(NiNode* node);
};

void* FUN_00552ba0();
unsigned char FUN_00456c70();
unsigned char FUN_00454ae0();
ShSceneNode* FUN_00450b80(int mode);

struct NavMeshObstacleManager
{
    static NavMeshObstacleManager* GetSingleton();
    void FUN_006c1170();
};

// @fnv 0x00552970
void FUN_00552970_Call::UpdateCellScene(NiNode* node)
{
    AutoMemHelper helper2(0x1a, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESObjectCELL.cpp",
                          0x395d);
    int v = GetOrCreateWidget();
    SetState(5);
    ((ShNiVt*)node)->v55((void*)v, 1);
    void* world = FUN_004543c0();
    if (world)
    {
        if (!IsInterior())
            FUN_005535f0();
        ((ShWorld*)world)->FUN_00454380(FUN_00456c70() == 0);
        ((ShWorld*)world)->SetProcessEnabled(FUN_00454ae0());
    }
    FUN_0054ba80(1);
    FUN_005577b0(1);
    FUN_0054b950(1);
    if (((ShCell*)FUN_00552ba0())->FUN_00552bb0())
        ((ShCell*)FUN_00552ba0())->FUN_006a37a0(this, 1);
    FUN_00557470();
    UpdateNavMeshObstacles();
    ((ShNavMgr*)NavMeshObstacleManager::GetSingleton())->FUN_006c1170();
    void* graph5 = FUN_009d9f20();
    ((ShSceneNode*)FUN_00450b80(0))->FUN_00b5ddf0(graph5);
    if (!((ShPortalGraph*)graph5)->FUN_00c5b5d0())
    {
        ((ShPortalGraph*)graph5)->FUN_00c5b1c0(GetDynamicNode());
        ((ShPortalGraph*)graph5)->FUN_00c5b1c0(FUN_0054a050());
        ((ShPortalGraph*)graph5)->FUN_00c5b1c0(((ShSceneNode*)FUN_00450b80(0))->FUN_0045bc00(5));
    }
    ((ShNiVt*)FUN_00456fc0(6))->v55(((ShPortalGraph*)graph5)->FUN_00546930(), 1);
    ((ShPortalGraph*)graph5)->FUN_00c5b9a0(FUN_0054aa60());
    ((ShPortalGraph*)graph5)->FUN_00c5b9a0(FUN_0054a050());
    ((ShPortalGraph*)graph5)->FUN_00c5b9a0(FUN_00456fc0(2));
    ((ShPortalGraph*)graph5)->FUN_00c5b9a0(FUN_00524cf0());
    fieldD1 = 0;
}
}  // namespace fnv_00552970

namespace fnv_005538e0 {
struct Vec5538
{
    float x, y, z;
};
struct Sound5538
{
    signed char FUN_00553b60();
    const char* FUN_00511840();
    unsigned char GetField45();
    unsigned int FUN_0084e3a0();
};
struct Ref5538
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
    virtual NiAVObject* node();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual Vec5538* pos();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual bool active();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual bool check(int);
    bool FUN_00440da0();
    bool FUN_00477ba0();
    bool FUN_00553bb0();
    Sound5538* FUN_00441110();
};
struct List5538
{
    Ref5538*& FUN_006815c0();
    List5538* FUN_00726070();
};
struct Handle5538
{
    unsigned int a, b, c;
    ~Handle5538();
    void FUN_00ad8f20(NiAVObject*);
    bool FUN_00ad8b60(float, float, float);
    void FUN_00ad9030(unsigned int);
    bool FUN_00ad8830(bool);
};
struct Audio5538
{
    static Audio5538* FUN_00453a70();
    Handle5538 FUN_00ad73b0(unsigned int, unsigned int);
};
struct Player5538
{
    float FUN_005723b0(Ref5538*, int, int);
};
extern "C" char DAT_011dea3c;
extern "C" char DAT_010179e0;
bool __cdecl FUN_004dff00(float);
struct Cell5538
{
    void FUN_00541ac0();
    bool FUN_00450ff0();
    List5538* FUN_009604f0();
    void FUN_00541ae0();
    void PlayCellSoundEffects();
};
// Iterates the cell's references and plays a positional sound for each eligible reference within range of the player.
// @fnv 0x005538e0
void Cell5538::PlayCellSoundEffects()
{
    FUN_00541ac0();
    if (FUN_00450ff0())
    {
        List5538* list3 = FUN_009604f0();
        while (list3 && list3->FUN_006815c0())
        {
            Ref5538* ref = list3->FUN_006815c0();
            if (ref && !ref->FUN_00440da0() && !ref->FUN_00477ba0() && ref->FUN_00553bb0() &&
                (!ref->active() || !ref->check(0)))
            {
                Sound5538* sound4 = ref->FUN_00441110();
                if (sound4 && FUN_004dff00(sound4->FUN_00553b60() / *(double*)&DAT_010179e0) && *sound4->FUN_00511840())
                {
                    unsigned int range = sound4->GetField45() * 100;
                    float distance = (*(Player5538**)&DAT_011dea3c)->FUN_005723b0(ref, 0, 0);
                    if (range > (unsigned int)distance)
                    {
                        Handle5538 a2 = Audio5538::FUN_00453a70()->FUN_00ad73b0(sound4->FUN_0084e3a0(), 0x2102);
                        if (ref->node())
                            a2.FUN_00ad8f20(ref->node());
                        Vec5538 position4 = *ref->pos();
                        a2.FUN_00ad8b60(position4.x, position4.y, position4.z);
                        a2.FUN_00ad9030(0xc0);
                        a2.FUN_00ad8830(false);
                    }
                }
            }
            list3 = list3->FUN_00726070();
        }
    }
    FUN_00541ae0();
}
}  // namespace fnv_005538e0

namespace fnv_005574d0 {
class BGSPerkEntry;

class BGSLoadedReferenceCollection;  // already defined by pack header

extern BGSLoadedReferenceCollection* DAT_011c95c8;

struct S_005270b0_Coll
{
    void FUN_005270b0(BGSPerkEntry* entry);
};

struct S_00549580_Owner
{
    bool FUN_00549580();
};

struct S_00586170_Result
{
    void RunAndDispatch();
    void FUN_006fcfa0();
    void FUN_00929260();
};

struct S_00575d70_Owner
{
    S_00586170_Result* FUN_00586170(BGSPerkEntry* entry);
    S_00586170_Result* FUN_00586170(BGSPerkEntry* entry, unsigned int flag);
    S_00586170_Result* FUN_00586170(unsigned int flag);
};

class BGSPerkEntry
{
  public:
    S_00549580_Owner* FUN_007af430();
    S_00575d70_Owner* FUN_00575d70();
    bool FUN_00440da0();
};

struct S_011dea10_Owner
{
    int FUN_005f36f0();
    int FUN_004fd3e0();
};
extern S_011dea10_Owner* DAT_011dea10;

class S_005574d0_Owner
{
  public:
    void FUN_00541ac0();
    void FUN_00541ae0();
    BSSimpleList<BGSPerkEntry*>* FUN_009604f0();
    void ProcessPerkEntries();
};

// @fnv 0x005574d0
void S_005574d0_Owner::ProcessPerkEntries()
{
    FUN_00541ac0();
    BSSimpleList<BGSPerkEntry*>* list = FUN_009604f0();
    while (list != 0)
    {
        BGSPerkEntry* entry = list->GetItem();
        if (entry != 0)
        {
            ((S_005270b0_Coll*)DAT_011c95c8)->FUN_005270b0(entry);
            if (DAT_011dea10->FUN_005f36f0() == 0 && DAT_011dea10->FUN_004fd3e0() != 0 &&
                entry->FUN_007af430()->FUN_00549580())
            {
                S_00575d70_Owner* refs = entry->FUN_00575d70();
                if (refs != 0)
                {
                    if (!entry->FUN_00440da0())
                    {
                        refs->FUN_00586170(entry)->RunAndDispatch();
                    }
                    else
                    {
                        refs->FUN_00586170(entry, 1)->FUN_006fcfa0();
                    }
                    refs->FUN_00586170(1)->FUN_00929260();
                }
            }
        }
        list = list->GetNext();
    }
    FUN_00541ae0();
}
}  // namespace fnv_005574d0

namespace fnv_005596a0 {
void __cdecl operator delete(void* pointer);

class FUN_005596a0
{
  public:
    virtual ~FUN_005596a0();
    int unk04;
    void* unk08;
};

// Destructor that frees the heap block stored in unk08 if it is non-null.
// @fnv 0x005596a0
FUN_005596a0::~FUN_005596a0()
{
    if (unk08)
    {
        void* block = unk08;
        operator delete(block);
    }
}
}  // namespace fnv_005596a0

struct Base5415
{
    virtual void slot0();
    char field04[0x14];
    Base5415();
    ~Base5415();
    void FUN_004f15a0(int);
    void FUN_00484ab0(int);
};
struct Name5415
{
    virtual void slotName();
    char field04[8];
    Name5415();
    ~Name5415();
};
struct Extra5415
{
    char field00[0x20];
    Extra5415();
    ~Extra5415();
};
struct Texture5415
{
    virtual void slot0();
    char field04[8];
    Texture5415();
    ~Texture5415();
};
struct List805415
{
    void* field00;
    void* field04;
    List805415();
};
struct ListAC5415
{
    void* field00;
    void* field04;
    ListAC5415();
    ~ListAC5415();
};
struct Ref5415
{
    void* field00;
    Ref5415(int);
    ~Ref5415();
    void FUN_0066b0d0(void*);
};
struct FUN_005415b0 : Base5415, Name5415
{
    virtual void slot0();
    unsigned char field24, field25, field26, field27;
    Extra5415 field28;
    unsigned field48, field4c;
    float field50;
    unsigned char field54;
    char field55[3];
    Texture5415 field58;
    unsigned field64;
    char field68[0x18];
    List805415 field80;
    char field88[0x18];
    unsigned fielda0, fielda4;
    unsigned short fielda8, fieldaa;
    ListAC5415 fieldac;
    Ref5415 fieldb4, fieldb8, fieldbc;
    unsigned fieldc0, fieldc4;
    float fieldc8;
    unsigned char fieldcc, fieldcd, fieldce, fieldcf, fieldd0, fieldd1, fieldd2, fieldd3;
    Ref5415 fieldd4;
    unsigned fieldd8, fielddc;
    FUN_005415b0();
};
// Sets several fields to default values and calls helper and member functions during construction.
// @fnv 0x005415b0
FUN_005415b0::FUN_005415b0() : fieldb4(0), fieldb8(0), fieldbc(0), fieldd4(0)
{
    field24 = 0;
    field26 = 0;
    fielddc = 0x9f;
    fieldd8 = 0;
    field48 = 0;
    field4c = 0;
    field50 = 3.4028234663852886e+38f;
    field64 = 0;
    FUN_004f15a0(0x39);
    fieldc0 = 0;
    field25 = 0;
    fieldc4 = 0;
    fielda4 = 0;
    fielda0 = 0;
    fielda8 = 0;
    fieldaa = 0;
    fieldc8 = 0.0f;
    fieldcc = 0;
    fieldcd = 0;
    field54 = 0;
    fieldcf = 0;
    fieldce = 0;
    fieldd0 = 0;
    fieldd1 = 0;
    fieldd2 = 0;
    FUN_00484ab0(1);
    fieldd4.FUN_0066b0d0(0);
    field58.slot0();
}

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
extern const char str_0102ed68[];
struct Mem960
{
    unsigned int handle;
    Mem960(int, int, const char*, int);
    void FUN_00404ee0();
    ~Mem960()
    {
        FUN_00404ee0();
    }
};
struct TESObjectLAND
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
    TESObjectLAND();
    void InitializeForCell(TESObjectCELL*);
};
struct CellH
{
    bool IsCellPersistent();
};
struct S00546fb0_Cell
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
    TESObjectLAND* field4c;
    TESObjectLAND* FUN_00546fb0();
};
// @fnv 0x00546fb0
TESObjectLAND* S00546fb0_Cell::FUN_00546fb0()
{
    if (((TESObjectCELL*)this)->IsCellInterior() || ((CellH*)this)->IsCellPersistent())
        return 0;
    if (!field4c)
    {
        Mem960 ctx(0x1b, 1, str_0102ed68, 0xfb6);
        field4c = new TESObjectLAND;
        field4c->InitializeForCell((TESObjectCELL*)this);
    }
    return field4c;
}

namespace fnv_00547ad0 {
struct MaskPixels
{
    int iBytesPerPixel;
    unsigned char* pPixels;
};

struct MaskSurface
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
    virtual long __stdcall LockRect(unsigned int auiLevel, MaskPixels* apLocked, void* apRect, unsigned int auiFlags);
};

struct MaskRenderData
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
    virtual MaskSurface* FUN_vt9c();
};

struct MaskTexture
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
    virtual int FUN_vt98();
    MaskRenderData* FUN_0059bb30();
};

struct CellLand
{
    void GetExtraDataNameAndPtr(MaskTexture** appTexture, MaskPixels** appPixels);
};

struct CellName
{
    char* FUN_00548210();
};

struct MaskGridPos
{
    float x, y;
};

struct MaskCellPos
{
    MaskGridPos kGrid;
    int iPad08[0x12];
    MaskCellPos();
};

struct MaskWorldPos
{
    float x, y, z;
};

struct CellGrid
{
    bool FUN_0053b550(MaskCellPos* apOut, MaskWorldPos* apPos, int aiFlags);
};

struct MaskLock
{
    void FUN_004a0370();
    void FUN_004a03c0();
};

extern bool DAT_011ca090;
bool FUN_00452480();
void FUN_00665610();
MaskLock* FUN_0043c4b0();
float __cdecl FUN_004019b0(float afValue);
float __cdecl FUN_00476b70(float afMin, float afMax);

struct CellMask : TESObjectCELL
{
    bool FUN_00425fd0();
    CellName* FUN_0054ddd0();
    CellLand* GetExtraDataList();
    CellGrid* FUN_00546fb0();
    int FUN_00544c30();
    int FUN_00544c60();
    void SetGridDataByte(int aiX, int aiY, MaskTexture** appCache, int aiIndex, unsigned char aucValue);
    void FUN_00547ad0(MaskWorldPos kPos, unsigned int uiRadius, int aiUnused);
};

void __cdecl CreateAndClearRenderTarget(CellMask* apCell, MaskTexture** appTexture, MaskPixels** appPixels);

// Writes values based on distance from kPos into the cell texture and neighboring cell textures within the processed radius.
// @fnv 0x00547ad0
void CellMask::FUN_00547ad0(MaskWorldPos kPos, unsigned int uiRadius, int aiUnused)
{
    if (DAT_011ca090)
        return;
    if (FUN_00425fd0() || !*FUN_0054ddd0()->FUN_00548210())
        return;
    if (FUN_00452480())
        FUN_00665610();
    MaskTexture* pTexture = 0;
    MaskPixels* pPixels = 0;
    MaskTexture* pNorthOld = 0;
    MaskTexture* pSouthCur = 0;
    MaskTexture* pEast = 0;
    MaskTexture* pWestNew = 0;
    MaskTexture* pNorthEastTmp = 0;
    MaskTexture* pNorthWestOut = 0;
    MaskTexture* pSouthEastResult = 0;
    MaskTexture* pSouthWestInfo = 0;
    GetExtraDataList()->GetExtraDataNameAndPtr(&pTexture, &pPixels);
    if (uiRadius == 0 || uiRadius > 0x400 || uiRadius < 0)
        uiRadius = 300;
    if (!pTexture)
        CreateAndClearRenderTarget(this, &pTexture, &pPixels);
    MaskCellPos kCellPosPos;
    if (!FUN_00546fb0() || !FUN_00546fb0()->FUN_0053b550(&kCellPosPos, &kPos, 0))
        return;
    MaskGridPos kCenterData = kCellPosPos.kGrid;
    kCenterData.x = kCenterData.x / 64.0;
    kCenterData.y = kCenterData.y / 64.0;
    uiRadius >>= 6;
    int iIndexCount = 0;
    if (pTexture)
    {
        FUN_0043c4b0()->FUN_004a0370();
        if (pPixels->pPixels == 0)
        {
            MaskRenderData* pRenderData = pTexture->FUN_0059bb30();
            if (pRenderData)
            {
                MaskSurface* pSurface = pRenderData->FUN_vt9c();
                pSurface->LockRect(0, pPixels, 0, 0);
            }
        }
        unsigned char* pDataVal = pPixels->pPixels;
        int iWidthNew = pTexture->FUN_vt98();
        int iRowBytesRes = pPixels->iBytesPerPixel * iWidthNew;
        unsigned char ucValue = 0;
        int iHorizontalPixelCenterObj = (int)kCenterData.x;
        int iCenterPixelY = (int)kCenterData.y;
        float fDistOut;
        for (int y = iCenterPixelY - uiRadius; y < iCenterPixelY + uiRadius; y++)
        {
            for (int x = iHorizontalPixelCenterObj - uiRadius; x < iHorizontalPixelCenterObj + uiRadius; x++)
            {
                fDistOut =
                    FUN_004019b0((kCenterData.x - x) * (kCenterData.x - x) + (kCenterData.y - y) * (kCenterData.y - y));
                if (uiRadius >= fDistOut)
                {
                    iIndexCount = y * iWidthNew + x;
                    ucValue = (unsigned char)(255.0 - FUN_00476b70(0.0f, 55.0f) - fDistOut / uiRadius * 60.0);
                    if (y < 64 && y >= 0 && x < 64 && x >= 0)
                    {
                        if (pDataVal[iIndexCount])
                            pDataVal[iIndexCount] = 0xff;
                        else
                            pDataVal[iIndexCount] = ucValue;
                    }
                    else if (y >= 64 && x < 0)
                    {
                        iIndexCount = (y - 64) * iWidthNew + x + 64;
                        SetGridDataByte(FUN_00544c30() - 1, FUN_00544c60() + 1, &pNorthWestOut, iIndexCount, ucValue);
                    }
                    else if (y >= 64 && x >= 64)
                    {
                        iIndexCount = (y - 64) * iWidthNew + x - 64;
                        SetGridDataByte(FUN_00544c30() + 1, FUN_00544c60() + 1, &pNorthEastTmp, iIndexCount, ucValue);
                    }
                    else if (y < 0 && x < 0)
                    {
                        iIndexCount = (y + 64) * iWidthNew + x + 64;
                        SetGridDataByte(FUN_00544c30() - 1, FUN_00544c60() - 1, &pSouthWestInfo, iIndexCount, ucValue);
                    }
                    else if (y < 0 && x >= 64)
                    {
                        iIndexCount = (y + 64) * iWidthNew + x - 64;
                        SetGridDataByte(FUN_00544c30() + 1, FUN_00544c60() - 1, &pSouthEastResult, iIndexCount,
                                        ucValue);
                    }
                    else if (y >= 64)
                    {
                        iIndexCount = (y - 64) * iWidthNew + x;
                        SetGridDataByte(FUN_00544c30(), FUN_00544c60() + 1, &pNorthOld, iIndexCount, ucValue);
                    }
                    else if (y < 0)
                    {
                        iIndexCount = (y + 64) * iWidthNew + x;
                        SetGridDataByte(FUN_00544c30(), FUN_00544c60() - 1, &pSouthCur, iIndexCount, ucValue);
                    }
                    else if (x >= 64)
                    {
                        iIndexCount = y * iWidthNew + x - 64;
                        SetGridDataByte(FUN_00544c30() + 1, FUN_00544c60(), &pEast, iIndexCount, ucValue);
                    }
                    else if (x < 0)
                    {
                        iIndexCount = y * iWidthNew + x + 64;
                        SetGridDataByte(FUN_00544c30() - 1, FUN_00544c60(), &pWestNew, iIndexCount, ucValue);
                    }
                }
            }
        }
        FUN_0043c4b0()->FUN_004a03c0();
    }
}
}  // namespace fnv_00547ad0

namespace fnv_0054e830 {
struct C0054e830;

class NP
{
  public:
    void* m;
    NP(void*);
    ~NP();
    void Reset(void*);
    NP& operator=(NP const&);
    operator void*() const;
};

class AutoMemHelper
{
  public:
    int m;
    AutoMemHelper(int, bool, const char*, int);
    ~AutoMemHelper();
};

class CullProc
{
  public:
    void* m;
    CullProc(void*);
    ~CullProc();
    void FUN_004a0fd0(void*);
    void FUN_00c4f270(int);
    void FUN_00c4f2d0();
};

class ImageSpaceEffectParam
{
  public:
    float a;
    float b;
    float c;
    float d;
    ImageSpaceEffectParam(float, float, float, float);
};

class VT
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
    virtual void v43(ImageSpaceEffectParam&);
    virtual void v44();
    virtual void v45(ImageSpaceEffectParam&);
};

class TexMgr
{
  public:
    void* M5(void*, int, int, int, int);
    void* M4(void*, int, int, int);
    void FUN_00b6da10(void*);
};

class BSA
{
  public:
    char pad[0x280];
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    BSA(int, int, int);
    void FUN_004a1020(void*);
    void FUN_004a1040(int);
};

class ShadowSceneNode
{
  public:
    unsigned char FUN_005f9ad0();
    void SetCreatureType(unsigned char);
};

class AVObj
{
  public:
    bool FUN_00456610();
    void SetAppCulled(bool);
};

class ImageSpaceEffect;

class ImageSpaceManager
{
  public:
    ImageSpaceEffect* FUN_004ebbc0(int);
    void RenderWithTextures(ImageSpaceEffect*, void*, void*, void*, int, int);
};

class RenderedTexture
{
  public:
    void* GetGroup();
};

class Ctx
{
  public:
    void SetFlag86(bool);
};

VT* FUN_004a0e90();
TexMgr* FUN_004a0ea0();
ShadowSceneNode* FUN_00450b80(unsigned int);
bool FUN_004e9510();
AVObj* FUN_004e7ff0();
bool FUN_0054ee20();
void FUN_0054ee60(unsigned char);
void FUN_00b6b8d0(int, void*);
void FUN_0054ede0(void*, int);
void FUN_00b6bee0(void*, void*, void*);
void FUN_00b6c0d0(void*, void*, int);
void FUN_00b6b790();
void FUN_00b6b840();
void FUN_00b54ac0(void*);
ImageSpaceManager* FUN_004e3270();
void* FUN_00b4f5c0();

struct Pad40
{
    int a[10];
};

struct C0054e830
{
    void* FUN_00456fc0(int);
    void FUN_0054e830(void*, NP*);
};

// Renders a shadow into a texture using a shadow scene node and image space effect, then restores the previous state.
// @fnv 0x0054e830
void C0054e830::FUN_0054e830(void* arg1, NP* apOutTexture)
{
    Pad40 holder, buf2, reserve, tempArea, workBuf;
    AutoMemHelper acc(0xe, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESObjectCELL.cpp", 0x2251);
    NP ctx(FUN_00b4f5c0());
    CullProc chi(0);
    NP next(0);
    NP group(0);
    NP p4(0);
    ImageSpaceEffect* pip;
    p4.Reset(FUN_004a0ea0()->M5(FUN_004a0e90(), 0x1e, 0, 0, 0));
    group.Reset(FUN_004a0ea0()->M4(FUN_004a0e90(), 0x1c, 0, 0));
    if ((void*)group && (void*)p4)
    {
        ImageSpaceEffectParam dst(0.0f, 0.0f, 0.0f, 0.0f);
        FUN_004a0e90()->v45(dst);
        FUN_004a0e90()->v43(ImageSpaceEffectParam(0.0f, 0.0f, 0.0f, 1.0f));
        ShadowSceneNode* pf = FUN_00450b80(0);
        unsigned char l3 = pf->FUN_005f9ad0();
        pf->SetCreatureType(1);
        bool b2 = FUN_004e9510();
        AVObj* a1 = FUN_004e7ff0();
        bool v1 = false;
        bool rho = true;
        if (a1)
        {
            v1 = a1->FUN_00456610();
            a1->SetAppCulled(1);
        }
        rho = FUN_0054ee20();
        FUN_0054ee60(0);
        if (b2)
        {
            FUN_00b6b8d0(7, ((RenderedTexture*)(void*)p4)->GetGroup());
        }
        else
        {
            FUN_0054ede0((void*)p4, 7);
        }
        NP q2(new BSA(0x63, 1, 0x2f7));
        ((BSA*)(void*)q2)->FUN_004a1020(pf);
        chi.FUN_004a0fd0((void*)q2);
        ((BSA*)(void*)q2)->FUN_004a1040(9);
        chi.FUN_00c4f270(3);
        FUN_00b6bee0(arg1, pf, &chi);
        chi.FUN_00c4f2d0();
        if (this->FUN_00456fc0(6))
        {
            chi.FUN_00c4f270(1);
            FUN_00b6bee0(arg1, this->FUN_00456fc0(6), &chi);
            chi.FUN_00c4f2d0();
        }
        FUN_00b6c0d0(arg1, (void*)q2, 0);
        chi.FUN_004a0fd0(0);
        q2.Reset(0);
        if (b2)
        {
            FUN_00b6b790();
        }
        else
        {
            FUN_00b6b840();
        }
        FUN_0054ee60(rho);
        if (a1)
        {
            a1->SetAppCulled(v1);
        }
        if (b2)
        {
            FUN_00b6b8d0(7, ((RenderedTexture*)(void*)group)->GetGroup());
        }
        else
        {
            FUN_0054ede0((void*)group, 7);
        }
        pip = ((ImageSpaceManager*)FUN_004e3270())->FUN_004ebbc0(0xe);
        ((ImageSpaceManager*)FUN_004e3270())->RenderWithTextures(pip, FUN_004a0e90(), (void*)p4, (void*)group, 0, 0);
        if (b2)
        {
            FUN_00b6b790();
        }
        else
        {
            FUN_00b6b840();
        }
        pf->SetCreatureType(l3);
        ((Ctx*)FUN_00b4f5c0())->SetFlag86(true);
        FUN_004a0e90()->v43(dst);
    }
    FUN_004a0ea0()->FUN_00b6da10((void*)p4);
    *apOutTexture = group;
    FUN_00b54ac0((void*)ctx);
}
}  // namespace fnv_0054e830

namespace CellShadow {

struct NiPoint3
{
    float x, y, z;
    NiPoint3();
};

struct NiPoint2
{
    float x, y;
    NiPoint2();
};

struct ThreeByThreeMatrix
{
    float m[9];
    ThreeByThreeMatrix();
    void FUN_00a59540(float afX, float afY, float afZ);
    void FUN_004a0c90(float afAngle);
    ThreeByThreeMatrix FUN_0043f8d0(const ThreeByThreeMatrix& arOther) const;
};

struct NiFrustum
{
    float fLeft, fRight, fTop, fBottom, fNear, fFar;
    bool bOrtho;
    NiFrustum(bool abOrtho);
};

struct NiBound
{
    float fData[4];
    NiPoint3* FUN_006815c0();
    float FUN_0084d030();
};

struct NiUpdateData
{
    float fTime;
    int iFlags[2];
    NiUpdateData(float afTime, bool abUpdateControllers, bool abUpdateGeometry);
};

struct SceneObject
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
    virtual void AttachChildInAvailableSlot(SceneObject* apChild, int aiFirstAvailable);
    virtual void v38();
    virtual void v39();
    virtual void InsertChild(SceneObject* apChild);

    static void* operator new(unsigned int auiSize);
    static void operator delete(void*, unsigned int);
    NiBound* FUN_0043d450();
    void FUN_00440460(const NiPoint3& arTranslate);
    void FUN_0043fa80(const ThreeByThreeMatrix& arRotate);
    void FUN_00a6faf0(const NiFrustum& arFrustum);
    void FUN_00a59c60(NiUpdateData& arData);
};

struct FUN_00a712f0 : SceneObject
{
    char pad04[0x110];
    FUN_00a712f0();
};

struct FUN_00a5ecb0 : SceneObject
{
    char pad04[0xa8];
    FUN_00a5ecb0(int aiChildren);
};

struct ScenePtr
{
    SceneObject* pObject;
    ScenePtr(SceneObject* apObject);
    ~ScenePtr();
    ScenePtr& operator=(SceneObject* apObject);
    ScenePtr& operator=(const ScenePtr& arOther);
    SceneObject* operator->() const;
    operator SceneObject*() const;
};

struct CullObject
{
    bool FUN_00456610();
    void FUN_00450f90(bool abCulled);
};

struct RefObject
{
    NiPoint3* FUN_00430830();
};

struct StaticForm;

extern NiPoint3 DAT_011f426c;
extern ThreeByThreeMatrix DAT_011a9448;
extern StaticForm* DAT_011ca254;
extern float DAT_0102e964;
extern float DAT_01016410;
extern float DAT_0102f060;
extern float DAT_0102f05c;
extern const double DAT_01011590;
extern const double DAT_0102f080;
extern const double DAT_0102f078;
extern const double DAT_01012060;

SceneObject* __cdecl FUN_00450b80(int aiUnk);
CullObject* __cdecl FUN_004e7ff0();
bool __cdecl FUN_0054f4b0();
void __cdecl FUN_004e20b0(bool abValue);

struct Cell
{
    bool FUN_00425fd0();
    SceneObject* FUN_00545cb0();
    void FUN_00555b10(NiPoint3& arFrom, NiPoint3& arTo, bool abFlag);
    RefObject* FindFirstRefByType(StaticForm* apForm, int aiFlag);
    CullObject* FUN_00456fc0(int aiIndex);
    void FUN_0054e830(SceneObject* apCamera, ScenePtr& arResult);
    void FUN_0054f500(int aiGridX, int aiGridY, ScenePtr* apOut);
};

// @fnv 0x0054f500
void Cell::FUN_0054f500(int aiGridX, int aiGridY, ScenePtr* apOut)
{
    if (!FUN_00425fd0() || !FUN_00545cb0())
    {
        *apOut = (SceneObject*)0;
        return;
    }
    SceneObject* pShadowRootEntry = FUN_00450b80(0);
    NiPoint2 kZRange;
    NiPoint3 kOrthoPos = DAT_011f426c;
    ThreeByThreeMatrix kRotateLoc;
    kRotateLoc.FUN_00a59540(-DAT_0102e964 / DAT_01011590, -DAT_0102e964 / DAT_01011590, DAT_0102e964 / DAT_01011590);
    NiFrustum kFrustumLocal(false);
    kFrustumLocal.fNear = DAT_01016410;
    kFrustumLocal.bOrtho = true;
    NiBound kBound = *FUN_00545cb0()->FUN_0043d450();
    kZRange.x = kBound.FUN_006815c0()->z - kBound.FUN_0084d030();
    kZRange.y = kBound.FUN_006815c0()->z + kBound.FUN_0084d030();
    int iHalfSizeIn = 0x880;
    kOrthoPos.x = (float)((aiGridX << 12) + 0x1080);
    kOrthoPos.y = (float)((aiGridY << 12) + 0x1080);
    kOrthoPos.z = kZRange.y + DAT_0102f080;
    FUN_00555b10(kOrthoPos, kOrthoPos, false);
    kFrustumLocal.fLeft = DAT_0102f060;
    kFrustumLocal.fRight = DAT_0102f05c;
    kFrustumLocal.fTop = DAT_0102f05c;
    kFrustumLocal.fBottom = DAT_0102f060;
    kFrustumLocal.fFar = kOrthoPos.z - kZRange.x + DAT_0102f078;
    ScenePtr spCameraTmp(new FUN_00a712f0());
    ScenePtr spNodeSample(new FUN_00a5ecb0(0));
    spNodeSample->AttachChildInAvailableSlot(spCameraTmp, 1);
    spNodeSample->FUN_00440460(kOrthoPos);
    pShadowRootEntry->AttachChildInAvailableSlot(spNodeSample, 1);
    float fZRotationItem = 0.0f;
    RefObject* pMarkerTmp = FindFirstRefByType(DAT_011ca254, 1);
    if (pMarkerTmp)
        fZRotationItem = pMarkerTmp->FUN_00430830()->z;
    if (fZRotationItem != DAT_01012060)
    {
        ThreeByThreeMatrix kZRotate = DAT_011a9448;
        kZRotate.FUN_004a0c90(fZRotationItem);
        kRotateLoc = kZRotate.FUN_0043f8d0(kRotateLoc);
    }
    spCameraTmp->FUN_0043fa80(kRotateLoc);
    spCameraTmp->FUN_00a6faf0(kFrustumLocal);
    NiUpdateData kNodeUpdate(0.0f, false, false);
    spNodeSample->FUN_00a59c60(kNodeUpdate);
    NiUpdateData kLocalCameraUpdate(0.0f, false, false);
    spCameraTmp->FUN_00a59c60(kLocalCameraUpdate);
    bool bCulled0Cur = false;
    bool bCulled1In = false;
    CullObject* pObject0Ptr = FUN_00456fc0(0);
    if (pObject0Ptr)
    {
        bCulled0Cur = pObject0Ptr->FUN_00456610();
        pObject0Ptr->FUN_00450f90(true);
    }
    CullObject* pObject1 = FUN_00456fc0(1);
    if (pObject1)
    {
        bCulled1In = pObject1->FUN_00456610();
        pObject1->FUN_00450f90(true);
    }
    CullObject* pObject6 = FUN_00456fc0(6);
    CullObject* pPlayerObjectBase = FUN_004e7ff0();
    bool bPlayerCulled = false;
    if (pPlayerObjectBase)
    {
        bPlayerCulled = pPlayerObjectBase->FUN_00456610();
        pPlayerObjectBase->FUN_00450f90(true);
    }
    bool bOldState = FUN_0054f4b0();
    FUN_004e20b0(false);
    ScenePtr spResultValue(0);
    FUN_0054e830(spCameraTmp, spResultValue);
    FUN_004e20b0(bOldState);
    if (pPlayerObjectBase)
        pPlayerObjectBase->FUN_00450f90(bPlayerCulled);
    if (pObject0Ptr)
        pObject0Ptr->FUN_00450f90(bCulled0Cur);
    if (pObject1)
        pObject1->FUN_00450f90(bCulled1In);
    pShadowRootEntry->InsertChild(spNodeSample);
    spNodeSample = (SceneObject*)0;
    spCameraTmp = (SceneObject*)0;
    *apOut = spResultValue;
}

}

struct Obj5548
{
    unsigned int m_uiType;
    int unk04[2];
    unsigned int m_uiKind;
};

namespace o5548 {
extern unsigned int DAT_01187020;
}

int __cdecl FindFormEnumIndex(unsigned int uiType);
bool __cdecl FUN_005548a0(int iType);

// Returns true if pkObj's type matches DAT_01187020 and its kind is 6, 8, or 9, otherwise delegates to FUN_005548a0 with the form enum index.
// @fnv 0x00554810
bool __cdecl FUN_00554810(Obj5548* pkObj)
{
    bool bResult = false;
    if (pkObj)
    {
        if (pkObj->m_uiType == o5548::DAT_01187020)
        {
            switch (pkObj->m_uiKind)
            {
            case 6:
            case 8:
            case 9:
                bResult = true;
                break;
            }
        }
        else
        {
            bResult = FUN_005548a0(FindFormEnumIndex(pkObj->m_uiType));
        }
    }
    return bResult;
}

namespace fnv_00555c20 {
class NiPoint3
{
  public:
    float x;
    float y;
    float z;
    NiPoint3(float fx, float fy, float afDepth);
    bool operator==(const NiPoint3& other);
};
class NiPoint2
{
  public:
    float x;
    float y;
    NiPoint2(float fx, float fy);
};
struct CellS;
struct WorldS
{
    CellS* FUN_005875a0(int cx, int cy);
};
struct CellS
{
    WorldS* FUN_0054ddd0();
    void UpdateLightingAtPoint(NiPoint3* pos);
};
struct PlayerS
{
    NiPoint3* FUN_00436aa0();
    CellS* FUN_008d6f30();
};
struct SettingS
{
    float* FUN_00403e20();
};
extern PlayerS* DAT_011dea3c;
extern SettingS DAT_011ca094;
extern const float DAT_01016970;
void SnapToGridCell(NiPoint3& pos);
bool __fastcall FUN_00425fd0(CellS* cell);
int TruncateFloatToInt(float value);
extern "C" void* memset(void* dst, int val, unsigned int count);

// Snaps a copy of the player's position to the grid and, when it matches the prior value, updates lighting in the current cell and selected neighboring cells.
// @fnv 0x00555c20
void FUN_00555c20()
{
    static NiPoint3 lastPos(DAT_01016970, DAT_01016970, DAT_01016970);
    if (DAT_011dea3c)
    {
        NiPoint3 pos2 = *DAT_011dea3c->FUN_00436aa0();
        SnapToGridCell(pos2);
        if (pos2 == lastPos)
        {
            lastPos = pos2;
            CellS* cellB = DAT_011dea3c->FUN_008d6f30();
            if (cellB)
            {
                if (!FUN_00425fd0(cellB))
                {
                    CellS* cells9[4];
                    memset(cells9, 0, 16);
                    cells9[0] = cellB;
                    WorldS* world = cellB->FUN_0054ddd0();
                    if (world)
                    {
                        int cellX = TruncateFloatToInt(pos2.x) >> 12;
                        int cellY3 = TruncateFloatToInt(pos2.y) >> 12;
                        NiPoint2 lowPt2((float)(cellX << 12), (float)(cellY3 << 12));
                        NiPoint2 highPt5((float)((cellX << 12) + 4096.0), (float)((cellY3 << 12) + 4096.0));
                        int dxTmp = 0;
                        int dy4 = 0;
                        if (lowPt2.x >= pos2.x - *DAT_011ca094.FUN_00403e20())
                        {
                            dxTmp = -1;
                        }
                        else if (pos2.x + *DAT_011ca094.FUN_00403e20() >= highPt5.x)
                        {
                            dxTmp = 1;
                        }
                        if (lowPt2.y >= pos2.y - *DAT_011ca094.FUN_00403e20())
                        {
                            dy4 = -1;
                        }
                        else if (pos2.y + *DAT_011ca094.FUN_00403e20() >= highPt5.y)
                        {
                            dy4 = 1;
                        }
                        int count3 = 1;
                        if (dxTmp != 0)
                        {
                            cells9[count3++] = world->FUN_005875a0(cellX + dxTmp, cellY3);
                        }
                        if (dy4 != 0)
                        {
                            cells9[count3++] = world->FUN_005875a0(cellX, cellY3 + dy4);
                        }
                        if (dxTmp != 0 && dy4 != 0)
                        {
                            cells9[count3++] = world->FUN_005875a0(cellX + dxTmp, cellY3 + dy4);
                        }
                    }
                    for (int i2 = 0; i2 < 4; i2++)
                    {
                        if (cells9[i2] != 0)
                        {
                            cells9[i2]->UpdateLightingAtPoint(&pos2);
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                else
                {
                    cellB->UpdateLightingAtPoint(&pos2);
                }
            }
        }
    }
}
}  // namespace fnv_00555c20

struct FUN_0042f830
{
    ~FUN_0042f830();
};
struct FUN_00541a60 : FUN_0042f830
{
    void FUN_0069bca0();
    ~FUN_00541a60();
};
// Calls FUN_0069bca0; the base class destructor runs after this destructor body.
// @fnv 0x00541a60
FUN_00541a60::~FUN_00541a60()
{
    FUN_0069bca0();
}

namespace s5447b0 {

struct Color
{
    float r;
    float g;
    float b;
};

struct Owner
{
    unsigned int GetCellNode();
    void FUN_005447b0(Color* pkColor);
};

// Splits the value from GetCellNode into three low-order bytes and stores them as normalized r, g, and b values.
// @fnv 0x005447b0
void Owner::FUN_005447b0(Color* pkColor)
{
    unsigned int uiPackedColor = GetCellNode();
    pkColor->r = (unsigned char)(uiPackedColor & 0xff) / 255.0;
    pkColor->g = (unsigned char)(((unsigned short)uiPackedColor >> 8) & 0xff) / 255.0;
    pkColor->b = (unsigned char)((uiPackedColor >> 16) & 0xff) / 255.0;
}

}

namespace fnv_005453b0 {
struct FNV_Ref;
struct FNV_Form;
struct FNV_Node;
struct FNV_Sub;
struct FNV_Render;
struct FNV_Flags;
struct NiPoint3;
struct ThreeByThreeMatrix;
struct FNV_Target;
struct FNV_Form
{
    int FUN_00401170();
    bool FUN_00549580();
    bool FUN_00549630();
};
struct FNV_Node
{
    void FUN_00a5a040();
    void* FUN_00a59d30(unsigned int);
    FNV_Node* FUN_00586170(FNV_Ref*, int);
    FNV_Node* FUN_00586170(int);
    void FUN_006fcfa0();
    void FUN_00929260();
    FNV_Flags* FUN_00a5bdd0(void*);
    virtual void v_0();
    virtual void v_4();
    virtual void v_8();
    virtual unsigned int v_c();
    virtual FNV_Render* v10();
    virtual void v_14();
    virtual void v_18();
    virtual void v_1c();
    virtual void v_20();
    virtual void v_24();
    virtual void v_28();
    virtual void v_2c();
    virtual void v_30();
    virtual void v_34();
    virtual void v_38();
    virtual void v_3c();
    virtual void v_40();
    virtual void v_44();
    virtual void v_48();
    virtual void v_4c();
    virtual void v_50();
    virtual void v_54();
    virtual void v_58();
    virtual void v_5c();
    virtual void v_60();
    virtual void v_64();
    virtual void v_68();
    virtual void v_6c();
    virtual void v_70();
    virtual void v_74();
    virtual void v_78();
    virtual void v_7c();
    virtual void v_80();
    virtual void v_84();
    virtual void v_88();
    virtual void v_8c();
    virtual void v_90();
    virtual void v_94();
    virtual void v_98();
    virtual void v_9c();
    virtual void v_a0();
    virtual void v_a4();
    virtual void v_a8();
    virtual void v_ac();
    virtual void v_b0();
    virtual void v_b4();
    virtual void v_b8();
    virtual void v_bc();
    virtual void v_c0();
    virtual void v_c4();
    virtual void v_c8();
    virtual void v_cc();
    virtual void v_d0();
    virtual void v_d4();
    virtual void v_d8();
    virtual void vdc(void*);
};
struct FNV_Ref
{
    void* FUN_0043fcd0();
    FNV_Target* FUN_00569580();
    FNV_Target* FUN_005454d0();
    FNV_Form* FUN_007af430();
    void* FUN_00575d70();
    FNV_Sub* FUN_005d43c0();
    NiPoint3* FUN_00430830();
    int FUN_005699b0();
    bool FUN_004077c0();
    bool FUN_00444ed0();
    bool FUN_005694c0();
    bool FUN_00564e60();
    bool FUN_00564f00();
    ThreeByThreeMatrix FUN_0056fa00();
    FNV_Render* FUN_008d6f30();
    unsigned int FUN_0084e3a0();
    void* FUN_00950bb0(int, int);
    FNV_Render* FUN_00950bb0(int);
    virtual void v_0();
    virtual void v_4();
    virtual void v_8();
    virtual void v_c();
    virtual void v_10();
    virtual void v_14();
    virtual void v_18();
    virtual void v_1c();
    virtual void v_20();
    virtual void v_24();
    virtual void v_28();
    virtual void v_2c();
    virtual void v_30();
    virtual void v_34();
    virtual void v_38();
    virtual void v_3c();
    virtual void v_40();
    virtual void v_44();
    virtual void v_48();
    virtual void v_4c();
    virtual void v_50();
    virtual void v_54();
    virtual void v_58();
    virtual void v_5c();
    virtual void v_60();
    virtual void v_64();
    virtual void v_68();
    virtual void v_6c();
    virtual void v_70();
    virtual void v_74();
    virtual void v_78();
    virtual void v_7c();
    virtual void v_80();
    virtual void v_84();
    virtual void v_88();
    virtual void v_8c();
    virtual void v_90();
    virtual void v_94();
    virtual void v_98();
    virtual void v_9c();
    virtual void v_a0();
    virtual void v_a4();
    virtual void v_a8();
    virtual void v_ac();
    virtual void v_b0();
    virtual void v_b4();
    virtual void v_b8();
    virtual void v_bc();
    virtual void v_c0();
    virtual void v_c4();
    virtual void v_c8();
    virtual void v_cc();
    virtual void v_d0();
    virtual void v_d4();
    virtual void v_d8();
    virtual void v_dc();
    virtual void v_e0();
    virtual void v_e4();
    virtual void v_e8();
    virtual void v_ec();
    virtual void v_f0();
    virtual void v_f4();
    virtual void v_f8();
    virtual void v_fc();
    virtual bool v100();
    virtual void v_104();
    virtual void v_108();
    virtual void v_10c();
    virtual void v_110();
    virtual void v_114();
    virtual void v_118();
    virtual void v_11c();
    virtual void v_120();
    virtual void v_124();
    virtual void v_128();
    virtual void v_12c();
    virtual void v_130();
    virtual void v_134();
    virtual void v_138();
    virtual void v_13c();
    virtual void v_140();
    virtual void v_144();
    virtual void v_148();
    virtual void v_14c();
    virtual void v_150();
    virtual void v_154();
    virtual void v_158();
    virtual void v_15c();
    virtual void v_160();
    virtual void v_164();
    virtual void v_168();
    virtual void v_16c();
    virtual void v_170();
    virtual void v_174();
    virtual void v_178();
    virtual void v_17c();
    virtual void v_180();
    virtual void v_184();
    virtual void v_188();
    virtual void v_18c();
    virtual void v_190();
    virtual void v_194();
    virtual void v_198();
    virtual void v_19c();
    virtual void v_1a0();
    virtual void v_1a4();
    virtual void v_1a8();
    virtual void v_1ac();
    virtual void* v1b0(int, int);
    virtual void v_1b4();
    virtual void v_1b8();
    virtual void v_1bc();
    virtual void v_1c0();
    virtual void v_1c4();
    virtual void v_1c8();
    virtual void v_1cc();
    virtual FNV_Node* v1d0();
    virtual void v_1d4();
    virtual void v_1d8();
    virtual void v_1dc();
    virtual void v_1e0();
    virtual void v_1e4();
    virtual void v_1e8();
    virtual void v_1ec();
    virtual void v_1f0();
    virtual void* v1f4();
    virtual void v_1f8();
    virtual void v_1fc();
    virtual void v_200();
    virtual void v_204();
    virtual void v_208();
    virtual void v_20c();
    virtual void v_210();
    virtual void v_214();
    virtual void v_218();
    virtual void v_21c();
    virtual void v_220();
    virtual bool v224();
};
struct FNV_Target
{
    virtual void v_0();
    virtual void v_4();
    virtual void v_8();
    virtual void v_c();
    virtual void v_10();
    virtual void v_14();
    virtual void v_18();
    virtual void v_1c();
    virtual void v_20();
    virtual void v_24();
    virtual void v_28();
    virtual void v_2c();
    virtual void v_30();
    virtual void v_34();
    virtual void v_38();
    virtual void v_3c();
    virtual void v_40();
    virtual void v_44();
    virtual void v_48();
    virtual void v_4c();
    virtual void v_50();
    virtual void v_54();
    virtual void v_58();
    virtual void v_5c();
    virtual void v_60();
    virtual void v_64();
    virtual void v_68();
    virtual void v_6c();
    virtual void v_70();
    virtual void v_74();
    virtual void v_78();
    virtual void v_7c();
    virtual void v_80();
    virtual void v_84();
    virtual void v_88();
    virtual void v_8c();
    virtual void v_90();
    virtual void v_94();
    virtual void v_98();
    virtual void v_9c();
    virtual void v_a0();
    virtual void v_a4();
    virtual void v_a8();
    virtual void v_ac();
    virtual void v_b0();
    virtual void v_b4();
    virtual void v_b8();
    virtual void v_bc();
    virtual FNV_Node* v_c0();
};
struct FNV_Map
{
    void FUN_00844700(unsigned int, unsigned int);
    int table;
    int size;
    int count;
    int extra;
};
struct FNV_Registration
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    FNV_Map others;
    FNV_Map doors;
};
struct CellOffsets
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
    short unkA8;
    short unkAA;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    FNV_Registration* unkc4;
    float unkC8;
    short unkCC;
    char unkCE;
    char unkCF;
    char unkD0;
    void FUN_005453b0(FNV_Ref* reference);
};

extern FNV_Ref* DAT_011dea3c;
void __cdecl CopyMaterialPropertyRecursive(FNV_Node*);
void __cdecl SetPropertyValueRecursive(FNV_Node*, FNV_Node*);

// Registers a reference in the cell's door or other maps, copying material properties and setting property values when the reference is not a door.
// @fnv 0x005453b0
void CellOffsets::FUN_005453b0(FNV_Ref* reference)
{
    if (!unkc4 || !reference || !reference->v1d0())
        return;
    FNV_Node* object = reference->v1d0();
    if (reference->FUN_007af430()->FUN_00401170() == 0x1e)
    {
        unkc4->doors.FUN_00844700((unsigned int)reference, object->v_c());
    }
    else
    {
        CopyMaterialPropertyRecursive(object);
        object->FUN_00a5a040();
        FNV_Target* target = reference->FUN_00569580();
        if (!target)
            target = DAT_011dea3c->FUN_005454d0();
        if (target)
        {
            FNV_Node* node = target->v_c0();
            if (node)
            {
                void* property = object->FUN_00a59d30(2);
                SetPropertyValueRecursive(object, node);
                unkc4->others.FUN_00844700((unsigned int)target, (unsigned int)reference);
            }
        }
    }
}
}  // namespace fnv_005453b0

extern void* DAT_011ca224;

struct FormX
{
};
struct ItemX
{
    FormX* FUN_007af430();
    void* FUN_00569060();
};
struct NodeX
{
    ItemX** FUN_006815c0();
    NodeX* FUN_00726070();
};
struct ListArg
{
    void FUN_005ae3d0(ItemX** pp);
};
struct FUN_0054b830_cls
{
    void FUN_00541ac0();
    void FUN_00541ae0();
    NodeX* FUN_009604f0();
    void FUN_0054b830(ListArg* pOut);
};

// For each item whose form matches DAT_011ca224 and whose map pointer is non-null, passes its address to pOut->FUN_005ae3d0.
// @fnv 0x0054b830
void FUN_0054b830_cls::FUN_0054b830(ListArg* pOut)
{
    if (pOut != 0)
    {
        FUN_00541ac0();
        NodeX* pNode = FUN_009604f0();
        while (pNode != 0)
        {
            ItemX* pItem = *pNode->FUN_006815c0();
            if (pItem != 0)
            {
                if (pItem->FUN_007af430() == DAT_011ca224)
                {
                    void* pMap = pItem->FUN_00569060();
                    if (pMap != 0)
                    {
                        pOut->FUN_005ae3d0(&pItem);
                    }
                }
            }
            pNode = pNode->FUN_00726070();
        }
        FUN_00541ae0();
    }
}

namespace s54ba00 {

struct Actor
{
    bool FUN_0057a2f0();
    bool FUN_0057a370();
    void FUN_00579ac0(bool bValue);
};

struct Node
{
    Actor** FUN_006815c0();
    Node* FUN_00726070();
};

struct Owner
{
    void FUN_00541ac0();
    void FUN_00541ae0();
    Node* FUN_009604f0();
    void FUN_0054ba00();
};

// Iterates linked nodes, and for each actor that passes FUN_0057a2f0, calls FUN_00579ac0 with the result of FUN_0057a370.
// @fnv 0x0054ba00
void Owner::FUN_0054ba00()
{
    FUN_00541ac0();
    Node* pkNode = FUN_009604f0();
    while (pkNode)
    {
        Actor* pkActor = *pkNode->FUN_006815c0();
        pkNode = pkNode->FUN_00726070();
        if (pkActor && pkActor->FUN_0057a2f0())
            pkActor->FUN_00579ac0(pkActor->FUN_0057a370());
    }
    FUN_00541ae0();
}

}

namespace s54ba80 {

struct Actor
{
    void FUN_005728c0(int iArg);
    void FUN_005729e0(int iArg);
};

struct Node
{
    Actor** FUN_006815c0();
    Node* FUN_00726070();
};

struct Owner
{
    void FUN_00541ac0();
    void FUN_00541ae0();
    Node* FUN_009604f0();
    void FUN_0054ba80(bool bEnable);
};

// Iterates the node list and calls FUN_005728c0 or FUN_005729e0 on each non-null actor depending on bEnable.
// @fnv 0x0054ba80
void Owner::FUN_0054ba80(bool bEnable)
{
    FUN_00541ac0();
    Node* pkNode = FUN_009604f0();
    while (pkNode)
    {
        Actor* pkActor = *pkNode->FUN_006815c0();
        pkNode = pkNode->FUN_00726070();
        if (pkActor)
        {
            if (bEnable)
                pkActor->FUN_005728c0(0);
            else
                pkActor->FUN_005729e0(0);
        }
    }
    FUN_00541ae0();
}

}

namespace s54baf0 {

struct Package;

struct Form
{
    int FUN_00401170();
    void FUN_0050de20(Package* pkPackage, int iFlags);
};

struct Process
{
    Package* FUN_00418250();
};

struct Actor
{
    Form* FUN_007af430();
    Process* FUN_005d43c0();
};

struct Node
{
    Actor** FUN_006815c0();
    Node* FUN_00726070();
};

struct Owner
{
    void FUN_00541ac0();
    void FUN_00541ae0();
    Node* FUN_009604f0();
    void FUN_0054baf0();
};

// For actors whose form type is 0x1e, obtains a package and, when non-null, passes it with 0 to FUN_0050de20.
// @fnv 0x0054baf0
void Owner::FUN_0054baf0()
{
    FUN_00541ac0();
    Node* pkNode = FUN_009604f0();
    while (pkNode)
    {
        Actor* pkActor = *pkNode->FUN_006815c0();
        pkNode = pkNode->FUN_00726070();
        if (pkActor)
        {
            switch (pkActor->FUN_007af430()->FUN_00401170())
            {
            case 0x1e:
                Package* pkPackage = pkActor->FUN_005d43c0()->FUN_00418250();
                if (pkPackage)
                    pkActor->FUN_007af430()->FUN_0050de20(pkPackage, 0);
            }
        }
    }
    FUN_00541ae0();
}

}

namespace s54cee0 {

struct Entry
{
    int* FUN_006815c0();
};

struct Owner
{
    void FUN_00541ac0();
    void FUN_00541ae0();
    Entry* FUN_009604f0();
    int FUN_0054cee0();
};

// Calls FUN_00541ac0, reads the int returned through the entry's FUN_006815c0 pointer, then calls FUN_00541ae0 and returns it.
// @fnv 0x0054cee0
int Owner::FUN_0054cee0()
{
    FUN_00541ac0();
    int iResult = *FUN_009604f0()->FUN_006815c0();
    FUN_00541ae0();
    return iResult;
}

}

namespace s54da20 {

struct Position
{
    bool FUN_004390c0(Position* pkOther);
};

int FUN_004b5440(Position* pkPosition, Position* pkCenter, float fRadius);

class Actor
{
  public:
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
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual Position* GetPosition();
};

struct Node
{
    bool FUN_008256d0();
    Actor** FUN_006815c0();
    Node* FUN_00726070();
};

typedef bool (*ActorCallback)(Actor* pkActor, void* pvContext);

struct Owner
{
    void FUN_00541ac0();
    void FUN_00541ae0();
    Node* FUN_009604f0();
    bool FUN_0054da20(Position* pkCenter1, float fRadius1, Position* pkCenter2, float fRadius2,
                      ActorCallback pfnCallback, void* pvContext);
};

// Iterates actors in the owner's node list, calling pfnCallback for those within both spheres, stopping early if the callback returns true.
// @fnv 0x0054da20
bool Owner::FUN_0054da20(Position* pkCenter1, float fRadius1, Position* pkCenter2, float fRadius2,
                         ActorCallback pfnCallback, void* pvContext)
{
    if (!pfnCallback)
        return false;
    FUN_00541ac0();
    Node* pkNode = FUN_009604f0();
    while (pkNode && !pkNode->FUN_008256d0())
    {
        Actor* pkActor = *pkNode->FUN_006815c0();
        pkNode = pkNode->FUN_00726070();
        if (fRadius1 == 3.402823466e+38F || FUN_004b5440(pkActor->GetPosition(), pkCenter1, fRadius1) < 0)
        {
            if (fRadius2 == 3.402823466e+38F || (fRadius1 == fRadius2 && pkCenter1->FUN_004390c0(pkCenter2)) ||
                FUN_004b5440(pkActor->GetPosition(), pkCenter2, fRadius2) < 0)
            {
                if (pfnCallback(pkActor, pvContext))
                {
                    FUN_00541ae0();
                    return false;
                }
            }
        }
    }
    FUN_00541ae0();
    return true;
}

}

namespace fnv_0054db50 {
extern void* DAT_011ca258;

struct FormX
{
    int FUN_00401170();
};
struct ItemX
{
    bool FUN_00440da0();
    bool FUN_00440d80();
    FormX* FUN_007af430();
    int FUN_00568e50();
};
struct NodeX
{
    ItemX** FUN_006815c0();
    NodeX* FUN_00726070();
};
struct ListArg
{
    void FUN_007cb2e0(ItemX** pp);
};
struct FUN_0054db50_cls
{
    void FUN_00541ac0();
    void FUN_00541ae0();
    NodeX* FUN_009604f0();
    void FUN_0054db50(ListArg* pOut);
};

// Iterates a linked list of ItemX nodes, filtering by form type 0x1c and a flag, and appends matching items to pOut.
// @fnv 0x0054db50
void FUN_0054db50_cls::FUN_0054db50(ListArg* pOut)
{
    FUN_00541ac0();
    NodeX* pNode = FUN_009604f0();
    while (pNode != 0)
    {
        ItemX* pItem = *pNode->FUN_006815c0();
        if (pItem != 0)
        {
            if (!pItem->FUN_00440da0())
            {
                if (!pItem->FUN_00440d80())
                {
                    FormX* pForm = pItem->FUN_007af430();
                    if (pForm->FUN_00401170() == 0x1c)
                    {
                        if (pForm != DAT_011ca258)
                        {
                            if (pItem->FUN_00568e50())
                            {
                                pOut->FUN_007cb2e0(&pItem);
                            }
                        }
                    }
                }
            }
        }
        pNode = pNode->FUN_00726070();
    }
    FUN_00541ae0();
}
}  // namespace fnv_0054db50

class bhkFilter
{
  public:
    int m_type;
    int GetType();
};

class bhkWorldObject
{
  public:
    bhkFilter GetFilter();
};

class bhkWorld
{
  public:
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
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAc();
    virtual void vB0();
    virtual void vB4();
    virtual void vB8();
    virtual void vBc();
    virtual void vC0();
    virtual void vC4();
    virtual bool FUN_00c8(TESObjectREFR* refr);
};

class CellBhk
{
  public:
    bhkWorld* FUN_004543c0();
    NiNode* FUN_00545cb0();
};

class RefrThing
{
  public:
    int FUN_00c66fd0();
    void* FUN_00c66fb0();
};

void* FUN_004b5a80(int value);

struct FUN_00553ee0_shell
{
    void* FUN_00553ee0(TESObjectREFR* refr);
};

// If the cell's bhkWorld contains refr and its object's filter type is 0x11, returns the cell's NiNode; otherwise returns null or FUN_00c66fb0's result.
// @fnv 0x00553ee0
void* FUN_00553ee0_shell::FUN_00553ee0(TESObjectREFR* refr)
{
    bhkWorld* world = ((CellBhk*)this)->FUN_004543c0();

    if (world)
    {
        if (world->FUN_00c8(refr))
        {
            int value7 = ((RefrThing*)refr)->FUN_00c66fd0();
            bhkWorldObject* object = (bhkWorldObject*)FUN_004b5a80(value7);

            if (object && object->GetFilter().GetType() == 0x11)
                return ((CellBhk*)this)->FUN_00545cb0();

            return ((RefrThing*)refr)->FUN_00c66fb0();
        }
    }
    return 0;
}

namespace s5573e0 {

class Process
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual int IsActive();

    void FUN_00476ab0();
};

void FUN_00b6bb30(Process* pkProcess, float fValue);

struct Actor
{
    Process* FUN_0043fcd0();
};

struct Node
{
    Actor** FUN_006815c0();
    Node* FUN_00726070();
};

struct Owner
{
    void FUN_00541ac0();
    void FUN_00541ae0();
    Node* FUN_009604f0();
    void FUN_005573e0();
};

// Visits each node's actor and, when its process is active, calls FUN_00476ab0 and FUN_00b6bb30 with 1.0f.
// @fnv 0x005573e0
void Owner::FUN_005573e0()
{
    FUN_00541ac0();
    Node* pkNode = FUN_009604f0();
    while (pkNode)
    {
        Actor* pkActor = *pkNode->FUN_006815c0();
        if (pkActor)
        {
            Process* pkProcess = pkActor->FUN_0043fcd0();
            if (pkProcess && pkProcess->IsActive())
            {
                Process* pkHigh = pkProcess;
                pkHigh->FUN_00476ab0();
                FUN_00b6bb30(pkHigh, 1.0f);
            }
        }
        pkNode = pkNode->FUN_00726070();
    }
    FUN_00541ae0();
}

}

namespace fnv_005577b0 {
struct FNV_Node;
struct FNV_Node
{
    virtual void v_0();
    virtual void v_4();
    virtual void v_8();
    virtual TESObjectREFR* v_c();
};
struct FNV_Ref
{
    virtual void v_0();
    virtual void v_4();
    virtual void v_8();
    virtual void v_c();
    virtual void v_10();
    virtual void v_14();
    virtual void v_18();
    virtual void v_1c();
    virtual void v_20();
    virtual void v_24();
    virtual void v_28();
    virtual void v_2c();
    virtual void v_30();
    virtual void v_34();
    virtual void v_38();
    virtual void v_3c();
    virtual void v_40();
    virtual void v_44();
    virtual void v_48();
    virtual void v_4c();
    virtual void v_50();
    virtual void v_54();
    virtual void v_58();
    virtual void v_5c();
    virtual void v_60();
    virtual void v_64();
    virtual void v_68();
    virtual void v_6c();
    virtual void v_70();
    virtual void v_74();
    virtual void v_78();
    virtual void v_7c();
    virtual void v_80();
    virtual void v_84();
    virtual void v_88();
    virtual void v_8c();
    virtual void v_90();
    virtual void v_94();
    virtual void v_98();
    virtual void v_9c();
    virtual void v_a0();
    virtual void v_a4();
    virtual void v_a8();
    virtual void v_ac();
    virtual void v_b0();
    virtual void v_b4();
    virtual void v_b8();
    virtual void v_bc();
    virtual void v_c0();
    virtual void v_c4();
    virtual void v_c8();
    virtual void v_cc();
    virtual void v_d0();
    virtual void v_d4();
    virtual void v_d8();
    virtual void v_dc();
    virtual void v_e0();
    virtual void v_e4();
    virtual void v_e8();
    virtual void v_ec();
    virtual void v_f0();
    virtual void v_f4();
    virtual void v_f8();
    virtual void v_fc();
    virtual bool v100();
    virtual void v_104();
    virtual void v_108();
    virtual void v_10c();
    virtual void v_110();
    virtual void v_114();
    virtual void v_118();
    virtual void v_11c();
    virtual void v_120();
    virtual void v_124();
    virtual void v_128();
    virtual void v_12c();
    virtual void v_130();
    virtual void v_134();
    virtual void v_138();
    virtual void v_13c();
    virtual void v_140();
    virtual void v_144();
    virtual void v_148();
    virtual void v_14c();
    virtual void v_150();
    virtual void v_154();
    virtual void v_158();
    virtual void v_15c();
    virtual void v_160();
    virtual void v_164();
    virtual void v_168();
    virtual void v_16c();
    virtual void v_170();
    virtual void v_174();
    virtual void v_178();
    virtual void v_17c();
    virtual void v_180();
    virtual void v_184();
    virtual void v_188();
    virtual void v_18c();
    virtual void v_190();
    virtual void v_194();
    virtual void v_198();
    virtual void v_19c();
    virtual void v_1a0();
    virtual void v_1a4();
    virtual void v_1a8();
    virtual void v_1ac();
    virtual void* v1b0(int, int);
    virtual void v_1b4();
    virtual void v_1b8();
    virtual void v_1bc();
    virtual void v_1c0();
    virtual void v_1c4();
    virtual void v_1c8();
    virtual void v_1cc();
    virtual FNV_Node* v1d0();
    virtual void v_1d4();
    virtual void v_1d8();
    virtual void v_1dc();
    virtual void v_1e0();
    virtual void v_1e4();
    virtual void v_1e8();
    virtual void v_1ec();
    virtual void v_1f0();
    virtual void* v1f4();
    virtual void v_1f8();
    virtual void v_1fc();
    virtual void v_200();
    virtual void v_204();
    virtual void v_208();
    virtual void v_20c();
    virtual void v_210();
    virtual void v_214();
    virtual void v_218();
    virtual void v_21c();
    virtual void v_220();
    virtual bool v224();
    bool FUN_004523e0(unsigned int);
};
struct RefNode
{
    FNV_Ref** FUN_006815c0();
    RefNode* FUN_00726070();
};
struct FNV_Cell : TESObjectCELL
{
    RefNode* FUN_009604f0();
    void FUN_005577b0(bool);
};
void __cdecl FUN_00578060(TESObjectREFR*);
void __cdecl FUN_00578170(TESObjectREFR*);

// Iterates the cell's reference list and calls FUN_00578060 or FUN_00578170 on each valid reference's node based on the enable flag.
// @fnv 0x005577b0
void FNV_Cell::FUN_005577b0(bool enable)
{
    CellRefLockEnter();
    if (enable)
    {
        RefNode* node = FUN_009604f0();
        while (node)
        {
            FNV_Ref* reference = *node->FUN_006815c0();
            node = node->FUN_00726070();
            if (reference && reference->FUN_004523e0(2) && reference->v1d0())
            {
                FUN_00578060(reference->v1d0()->v_c());
            }
        }
    }
    else
    {
        RefNode* node2 = FUN_009604f0();
        while (node2)
        {
            FNV_Ref* reference2 = *node2->FUN_006815c0();
            node2 = node2->FUN_00726070();
            if (reference2 && reference2->FUN_004523e0(2) && reference2->v1d0())
            {
                FUN_00578170(reference2->v1d0()->v_c());
            }
        }
    }
    CellRefLockLeave();
}
}  // namespace fnv_005577b0

namespace fnv_0054abd0 {
struct CountingSemaphore
{
    int a, b, c;
    void Wait();
    void Signal();
};
struct FUN_0054ad60 : CountingSemaphore
{
    FUN_0054ad60(int);
    ~FUN_0054ad60();
};
namespace N {
struct TESObjectREFR
{
    NiAVObject* GetReferenceType();
};
}
struct GO
{
    void* p;
    void operator=(void*);
};
struct FUN_0054acf0
{
    GO spChild;
    GO m_pParent;
    int iFlags;
    FUN_0054acf0();
    ~FUN_0054acf0();
};
struct FUN_0054adb0
{
    GO spChild;
    GO m_pParent;
    int iFlags;
    FUN_0054adb0(const FUN_0054acf0&);
    ~FUN_0054adb0();
};
struct MapH
{
    bool RemoveAt(unsigned int);
    void SetOrInsertValue(NiAVObject*, FUN_0054adb0);
};
extern MapH g_011ca0f4;
// Records or removes the parent node for a reference's NiAVObject in g_011ca0f4 under a counting semaphore.
// @fnv 0x0054abd0
void __cdecl FUN_0054abd0(TESObjectREFR* apRef, NiNode* apParent)
{
    if (!apRef || !((N::TESObjectREFR*)apRef)->GetReferenceType())
        return;
    static FUN_0054ad60 kLock(1);
    kLock.Wait();
    NiAVObject* pnewchild = ((N::TESObjectREFR*)apRef)->GetReferenceType();
    if (pnewchild->GetParent() == apParent)
    {
        g_011ca0f4.RemoveAt((unsigned int)pnewchild);
    }
    else
    {
        FUN_0054acf0 attachdata;
        attachdata.m_pParent = apParent;
        attachdata.spChild = pnewchild;
        g_011ca0f4.SetOrInsertValue(pnewchild, attachdata);
    }
    kLock.Signal();
}
}  // namespace fnv_0054abd0

#include <float.h>
struct PortalVisitPoint
{
    float x, y, z;
    PortalVisitPoint();
    bool FUN_004390c0(const PortalVisitPoint&) const;
};
struct PortalVisitCell;
struct PortalVisitRef;
typedef bool(__cdecl* PortalVisitCallback)(PortalVisitRef*, void*);
struct PortalVisitWorld
{
    void ProcessCellsInRadius(const PortalVisitPoint&, float, const PortalVisitPoint&, float, PortalVisitCallback,
                              void*);
};
struct PortalVisitForm
{
    int FUN_00401170();
};
struct PortalVisitDoor
{
    PortalVisitWorld* FUN_0043a320();
    PortalVisitCell* FUN_0043a2b0();
    PortalVisitPoint& FUN_00717e50();
};
struct PortalVisitRef
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9c();
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    virtual void slotc0();
    virtual void slotc4();
    virtual void slotc8();
    virtual void slotcc();
    virtual void slotd0();
    virtual void slotd4();
    virtual void slotd8();
    virtual void slotdc();
    virtual void slote0();
    virtual void slote4();
    virtual void slote8();
    virtual void slotec();
    virtual void slotf0();
    virtual void slotf4();
    virtual void slotf8();
    virtual void slotfc();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14c();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15c();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual void slot16c();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17c();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void slot18c();
    virtual void slot190();
    virtual void slot194();
    virtual void slot198();
    virtual void slot19c();
    virtual void slot1a0();
    virtual void slot1a4();
    virtual void slot1a8();
    virtual void slot1ac();
    virtual void slot1b0();
    virtual void slot1b4();
    virtual void slot1b8();
    virtual void slot1bc();
    virtual void slot1c0();
    virtual void slot1c4();
    virtual void slot1c8();
    virtual void slot1cc();
    virtual void slot1d0();
    virtual void slot1d4();
    virtual void slot1d8();
    virtual void slot1dc();
    virtual void slot1e0();
    virtual void slot1e4();
    virtual void slot1e8();
    virtual void slot1ec();
    virtual void slot1f0();
    virtual PortalVisitPoint& GetPosition();
    PortalVisitForm* FUN_007af430();
    PortalVisitDoor* FUN_00568e50();
    float FUN_00572380(const PortalVisitPoint&);
};
struct PortalVisitItem
{
    PortalVisitRef*& FUN_006815c0();
    PortalVisitItem* FUN_00726070();
};
struct PortalVisitCell
{
    void FUN_00541ac0();
    void FUN_00541ae0();
    bool FUN_00425fd0();
    PortalVisitItem* FUN_009604f0();
};
struct PortalVisitList
{
    void* head;
    void* tail;
    unsigned count;
    PortalVisitList();
    ~PortalVisitList();
    void FUN_005597d0(void* const&);
    void* FUN_00559450();
    PortalVisitRef*& FUN_0057cbe0(void*&);
    int FUN_0049c680(PortalVisitCell* const&, int);
    void FUN_00559c30();
};
int FUN_004b5440(const PortalVisitPoint&, const PortalVisitPoint&, float);
extern PortalVisitPoint portalVisitZero;
extern PortalVisitForm* portalVisitExcludedDoor;
extern float portalVisitRemaining;
// Recursively visits refs in a cell within two radii, invoking callback and following doors to process linked cells.
// @fnv 0x0054d4b0
bool __cdecl FUN_0054d4b0(PortalVisitCell* cell, const PortalVisitPoint& origin, float range,
                          const PortalVisitPoint& other, float otherRange, PortalVisitCallback callback, void* context)
{
    if (cell)
        cell->FUN_00541ac0();
    static PortalVisitList visited;
    static PortalVisitPoint nearestPosition;
    static int depth = 0;
    static PortalVisitWorld* nearestWorld = 0;
    bool stop4 = false;
    if (!depth)
    {
        nearestPosition = portalVisitZero;
        nearestWorld = 0;
        portalVisitRemaining = FLT_MAX;
    }
    if (cell && callback)
    {
        ++depth;
        visited.FUN_005597d0(reinterpret_cast<void*&>(cell));
        PortalVisitList deferred;
        PortalVisitItem* item3 = cell->FUN_009604f0();
        while (item3 && !stop4)
        {
            PortalVisitRef* ref = item3->FUN_006815c0();
            item3 = item3->FUN_00726070();
            if (ref)
            {
                if (range == double(FLT_MAX) || FUN_004b5440(ref->GetPosition(), origin, range) < 0)
                {
                    if (otherRange == double(FLT_MAX) || (range == otherRange && origin.FUN_004390c0(other)) ||
                        FUN_004b5440(ref->GetPosition(), other, otherRange) < 0)
                    {
                        if (callback(ref, context))
                            stop4 = true;
                        if (ref->FUN_007af430()->FUN_00401170() == 28 && ref->FUN_007af430() != portalVisitExcludedDoor)
                        {
                            PortalVisitDoor* door = ref->FUN_00568e50();
                            if (door)
                            {
                                PortalVisitWorld* world = door->FUN_0043a320();
                                PortalVisitCell* target2 = door->FUN_0043a2b0();
                                if (target2 && !target2->FUN_00425fd0())
                                    target2 = 0;
                                if (world)
                                {
                                    float remaining = FLT_MAX;
                                    if (range != double(FLT_MAX))
                                    {
                                        float distance = range - ref->FUN_00572380(origin);
                                        if (distance < remaining)
                                            remaining = distance;
                                    }
                                    if (otherRange != double(FLT_MAX) && otherRange != range)
                                    {
                                        float distance = otherRange - ref->FUN_00572380(other);
                                        if (distance < remaining)
                                            remaining = distance;
                                    }
                                    if (!nearestWorld || remaining > portalVisitRemaining)
                                    {
                                        portalVisitRemaining = remaining;
                                        nearestPosition = door->FUN_00717e50();
                                        nearestWorld = world;
                                    }
                                }
                                else if (target2 && !visited.FUN_0049c680(target2, 0))
                                    deferred.FUN_005597d0(reinterpret_cast<void*&>(ref));
                            }
                        }
                    }
                }
            }
        }
        void* cursor3 = deferred.FUN_00559450();
        while (cursor3 && !stop4)
        {
            PortalVisitRef* ref = deferred.FUN_0057cbe0(cursor3);
            if (ref)
            {
                float remaining = FLT_MAX;
                if (range != double(FLT_MAX))
                {
                    float distance = range - ref->FUN_00572380(origin);
                    if (distance < remaining)
                        remaining = distance;
                }
                if (otherRange != double(FLT_MAX) && otherRange != range)
                {
                    float distance = otherRange - ref->FUN_00572380(other);
                    if (distance < remaining)
                        remaining = distance;
                }
                PortalVisitDoor* door = ref->FUN_00568e50();
                if (!FUN_0054d4b0(door->FUN_0043a2b0(), door->FUN_00717e50(), remaining, other, FLT_MAX, callback,
                                  context))
                    stop4 = true;
            }
        }
        --depth;
    }
    if (!depth)
    {
        visited.FUN_00559c30();
        if (!stop4 && nearestWorld)
        {
            nearestWorld->ProcessCellsInRadius(nearestPosition, portalVisitRemaining, other, FLT_MAX, callback,
                                               context);
            stop4 = true;
        }
    }
    if (cell)
        cell->FUN_00541ae0();
    return !stop4;
}

namespace fnv_00552dc0 {
void* __cdecl FUN_00aa13e0(unsigned int);
struct ChildGeometryBase;

void* __cdecl operator new(unsigned int);
void* __cdecl operator new(unsigned int, void*);
void __cdecl operator delete(void*);
extern float DAT_011ca158;
extern float DAT_0102efc0;
extern unsigned int DAT_011ca088;
extern const char DAT_0102ed68[];

struct ScopedCellOperation
{
    ScopedCellOperation(unsigned int, bool, const char*, unsigned int);
    ~ScopedCellOperation();
    unsigned int state;
};
struct FourFloatVector
{
    float x, y, z, w;
    FourFloatVector(float, float, float, float);
};
struct Rotation
{
    float matrix[16];
    float homogeneous;
    void FUN_004a3f10(const FourFloatVector*);
};
struct __declspec(align(16)) SceneInitializer
{
    SceneInitializer();
    ~SceneInitializer();
    void FUN_00c90db0(float);
    unsigned int state00, state04, state08, state0c;
    Rotation rotation;
    float scale;
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
    char unk88[8];
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
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
};
struct SpatialNode
{
    void FUN_00454380(bool bValue);
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
    static void* operator new(unsigned int);
    static void operator delete(void*);
    SpatialNode(SceneInitializer*);
    void FUN_005533c0();
    void FUN_00553480(ChildGeometryBase*);
    void FUN_005534f0(void*);
    void SetField(void*);
    void FUN_00553440(void*);
    void FUN_005533f0(void*);
    void* FUN_00541c80();
    void FUN_00c68750(void*);
    void SetProcessEnabled(bool);
    virtual void V00();
    virtual void V04();
    virtual void V08();
    virtual void V0c();
    virtual void V10();
    virtual void V14();
    virtual void V18();
    virtual void V1c();
    virtual void V20();
    virtual void V24();
    virtual void V28();
    virtual void V2c();
    virtual void V30();
    virtual void V34();
    virtual void V38();
    virtual void V3c();
    virtual void V40();
    virtual void V44();
    virtual void V48();
    virtual void V4c();
    virtual void V50();
    virtual void V54();
    virtual void V58();
    virtual void V5c();
    virtual void V60();
    virtual void V64();
    virtual void V68();
    virtual void V6c();
    virtual void V70();
    virtual void V74();
    virtual void V78();
    virtual void V7c();
    virtual void V80();
    virtual void V84();
    virtual void V88();
    virtual void V8c();
    virtual void V90();
    virtual void V94();
    virtual void V98();
    virtual void V9c();
    virtual void Va0();
    virtual void Va4();
    virtual void Va8();
    virtual void Vac();
    virtual void Vb0();
    virtual void Vb4();
    virtual void Vb8();
    virtual void Vbc();
    virtual void Vc0();
    virtual void Vc4();
};
struct ChildGeometryHead
{
    int unk00;
    int unk04;
};
struct ChildGeometryBase
{
    int unk08;
};
struct ChildGeometry : ChildGeometryHead, ChildGeometryBase
{
    ChildGeometry();
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
};
struct MaterialProperty
{
    MaterialProperty();
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
};
struct FogProperty
{
    FogProperty(float);
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
};
struct AlphaProperty
{
    AlphaProperty();
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};
struct RenderPolicy
{
    RenderPolicy();
};
struct FUN_006815c0_Position
{
    float x, y, z;
    FUN_006815c0_Position();
};
struct ActiveRegistry
{
    ActiveRegistry();
    int unk00;
    int unk04;
    void NotifyActivation(void*);
};
struct RefList
{
    void SetHavokWorld(SpatialNode*);
    void SetCellMopp(void*);
};
struct Shadow
{
    static void* operator new(unsigned int uiSize)
    {
        return FUN_00aa13e0(uiSize);
    }
    static void operator delete(void* pvMem, unsigned int);
    Shadow();
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};
struct CellProxy : TESObjectCELL
{
    SpatialNode* FUN_004543c0();
    bool FUN_00425fd0();
    bool FUN_004518e0();
    float FUN_005471e0();
    void ComputeCellRotationCenter(FUN_006815c0_Position*);
    Shadow* GetCellMopp();
    void FUN_00454380(bool);
    void FUN_00552dc0();
};
void* __cdecl FUN_00453720();
bool __cdecl FUN_00454ae0();
bool __cdecl FUN_00456c70();
void* __cdecl FUN_00aa13e0(unsigned int);

// Creates and configures a SpatialNode when the cell has none, then creates and stores a Shadow when the cell has none.
// @fnv 0x00552dc0
void CellProxy::FUN_00552dc0()
{
    SpatialNode* root = FUN_004543c0();
    if (FUN_00425fd0() && root == 0)
    {
        ScopedCellOperation guard(0x10, true, DAT_0102ed68, 0x3a3f);
        SceneInitializer init;
        init.rotation.FUN_004a3f10(&FourFloatVector(0.0f, 0.0f, DAT_011ca158, 0.0f));
        init.FUN_00c90db0(DAT_0102efc0);
        init.scale = 1.0f;
        root = new SpatialNode(&init);
        root->FUN_005533c0();
        root->FUN_00553480(new ChildGeometry());
        root->FUN_005534f0(new MaterialProperty());
        if (FUN_004518e0())
        {
            root->SetField(new FogProperty(FUN_005471e0()));
        }
        root->FUN_00553440(FUN_00453720());
        root->FUN_005533f0(new AlphaProperty());
        if (DAT_011ca088 == 0)
        {
            DAT_011ca088 = (unsigned int)new ActiveRegistry();
        }
        ((ActiveRegistry*)DAT_011ca088)->NotifyActivation(root->FUN_00541c80());
        FUN_006815c0_Position pos;
        ComputeCellRotationCenter(&pos);
        root->FUN_00c68750(&pos);
        root->SetProcessEnabled(FUN_00454ae0());
        ((RefList*)&extraDataList)->SetHavokWorld(root);
        root->FUN_005533c0();
        root->Vc4();
        root->FUN_00454380(!FUN_00456c70());
    }
    {
        Shadow* pkShadow = GetCellMopp();
        if (!pkShadow)
        {
            ScopedCellOperation guard(0x10, true, DAT_0102ed68, 0x3a91);
            pkShadow = new Shadow();
            ((RefList*)&extraDataList)->SetCellMopp(pkShadow);
        }
    }
}
}  // namespace fnv_00552dc0

namespace fnv_00545960 {
struct G
{
    void* p;
    G(int);
    ~G();
    void* FUN_00559450();
    void FUN_0066b0d0(void* x);
};
struct Inner
{
    unsigned char FUN_006c62d0(void* arg, G* g);
};
struct A
{
    unsigned char FUN_00439f90();
};
struct S
{
    char pad[0xc4];
    Inner* m;
    void* GetOrCreateFaceGenNode(A* a);
    void* FUN_00545960(A* a);
};
// Calls Inner::FUN_006c62d0 on m with a and a G buffer, falling back to FUN_00545740 on failure, then returns the G result.
// @fnv 0x00545960
void* S::FUN_00545960(A* a)
{
    if (m == 0 || a == 0 || !a->FUN_00439f90())
        return 0;
    G g(0);
    if (!((Inner*)((char*)m + 0x3c))->FUN_006c62d0(a, &g) || !g.FUN_00559450())
        g.FUN_0066b0d0(GetOrCreateFaceGenNode(a));
    return g.FUN_00559450();
}
}  // namespace fnv_00545960

namespace fnv_00554b90 {
struct FUN_00484bf0_shell
{
    unsigned short FUN_00484bf0(unsigned int);
};

struct SeenData_Stub
{
    virtual void v00();
    virtual void v04();
    virtual unsigned short FUN_08(int);
};

union SETTING_VALUE;
struct GlobalObject_0045cf30
{
    bool* Bool();
};
extern GlobalObject_0045cf30 g_011de4e8;

struct TESSaveLoadGame
{
    bool FUN_00862110();
    void* FUN_004fd3e0();
};
extern TESSaveLoadGame* g_TESSaveLoadGame;

struct TESForm_Stub
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
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v4a();
    virtual void v4b();
    virtual const char* GetEditorID();
};

TESForm* __cdecl FUN_004839c0(unsigned int);
unsigned int __cdecl BSStringLength(const char*);
void __cdecl FUN_0040fbe0(const char*, ...);

struct FUN_00554b90_shell : public TESObjectCELL
{
    SeenData_Stub* FUN_00555bc0();
    unsigned short FUN_00554b90(unsigned int flags);
};

// Computes the total byte size needed to save this cell, adding sizes for optional fields selected by flags and logging the result when a debug global is set.
// @fnv 0x00554b90
unsigned short FUN_00554b90_shell::FUN_00554b90(unsigned int flags)
{
    unsigned short uSize = 0;
    if (flags & 0x40000000)
        uSize += 4;
    uSize += ((FUN_00484bf0_shell*)this)->FUN_00484bf0(flags);
    unsigned short uBaseSize2 = uSize;
    if (g_TESSaveLoadGame->FUN_00862110())
    {
        uSize += 4;
        uSize += 2;
    }
    if (flags & 2)
        uSize += 1;
    if (flags & 0x80000000)
        uSize += FUN_00555bc0()->FUN_08(0);
    if (flags & 4)
    {
        uSize += 1;
        uSize += BSStringLength(((FNStub*)((char*)this + 0x18))->GetFullName());
    }
    if (flags & 8)
        uSize += 4;
    if (*g_011de4e8.Bool())
    {
        void* pObj4 = g_TESSaveLoadGame->FUN_004fd3e0();
        if (pObj4)
        {
            TESForm_Stub* pForm = (TESForm_Stub*)FUN_004839c0(*(unsigned int*)pObj4);
            FUN_0040fbe0("GetSaveSize(): %-5i for form %08X %s with flags %08X ending at line %i in file %s",
                         uSize - uBaseSize2, *(unsigned int*)pObj4, pForm->GetEditorID(),
                         *(unsigned int*)((char*)pObj4 + 5), 15697,
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESObjectCELL.cpp");
        }
        else
        {
            FUN_0040fbe0("GetSaveSize(): %-5i ending at line %i in file %s", uSize - uBaseSize2, 15697,
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESObjectCELL.cpp");
        }
    }
    return uSize;
}
}  // namespace fnv_00554b90

struct Actor;
struct CellOwnerCheck : public TESObjectCELL
{
    bool FUN_00546ca0(Actor*);
};

struct FNV_Ref;

int __fastcall _FNV_GetObjectReference(CellLightingTemplate* self);

struct TESNPC : TESBoundObject
{
    virtual ~TESNPC();
};

struct TESFaction : TESForm
{
    virtual ~TESFaction();
};

struct FUN_00546ac0_shell
{
    int FUN_00546ac0();
};

struct TESActorBaseData
{
    int GetFactionRank(TESFaction*, bool);
};

struct CellOwnerNpcView
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
    TESActorBaseData actorBase;
};

// Returns true when the actor matches the owner NPC or its faction rank meets the rank returned by FUN_00546ac0.
// @fnv 0x00546ca0
bool CellOwnerCheck::FUN_00546ca0(Actor* apActor)
{
    bool bHasResultObj = false;
    TESForm* powner = ((DoorCell*)this)->GetOwner();
    if (powner)
    {
        typedef bool(__thiscall * Fn218)(Actor*);
        if (!((Fn218*)(*(void**)apActor))[0x218 / 4](apActor))
        {
            return bHasResultObj;
        }
        TESNPC* pnpc = dynamic_cast<TESNPC*>(powner);
        if (pnpc)
        {
            if (pnpc == (TESNPC*)_FNV_GetObjectReference((CellLightingTemplate*)apActor))
            {
                bHasResultObj = true;
            }
        }
        else
        {
            TESFaction* pfaction = dynamic_cast<TESFaction*>(powner);
            if (pfaction)
            {
                int irank = ((FUN_00546ac0_shell*)this)->FUN_00546ac0();
                TESNPC* pactnpc =
                    dynamic_cast<TESNPC*>((TESBoundObject*)_FNV_GetObjectReference((CellLightingTemplate*)apActor));
                int iactrank =
                    ((CellOwnerNpcView*)pactnpc)->actorBase.GetFactionRank(pfaction, apActor == (Actor*)DAT_011dea3c);
                if (iactrank >= irank)
                {
                    bHasResultObj = true;
                }
            }
        }
    }
    return bHasResultObj;
}

namespace fnv_00546ee0 {
class TESActorBase;
class TESFaction;
class type_info;

extern type_info DAT_01183028;
extern type_info DAT_01183a1c;
extern type_info DAT_01184704;
extern type_info DAT_011846e8;
extern "C" void* __cdecl FUN_00ec43fb(void*, int, const void*, const void*, int);

struct CellOwnerRankData
{
    int GetFactionRank(TESFaction*, bool);
};

struct CellOwnerNPCView
{
    unsigned int field00;
    unsigned int field04;
    unsigned int field08;
    unsigned int field0c;
    unsigned int field10;
    unsigned int field14;
    unsigned int field18;
    unsigned int field1c;
    unsigned int field20;
    unsigned int field24;
    unsigned int field28;
    unsigned int field2c;
    CellOwnerRankData actorData;
};

struct CellOwnerCheck : public TESObjectCELL
{
    int FUN_00546ac0();
    bool FUN_00546ee0(TESActorBase*);
};

// Returns true when apActorBase matches the owner NPC or its faction rank meets the rank returned by FUN_00546ac0.
// @fnv 0x00546ee0
bool CellOwnerCheck::FUN_00546ee0(TESActorBase* apActorBase)
{
    bool bHasResultObj = false;
    TESForm* powner = ((DoorCell*)this)->GetOwner();
    if (powner)
    {
        CellOwnerNPCView* pnpc = (CellOwnerNPCView*)FUN_00ec43fb(powner, 0, &DAT_01183028, &DAT_01183a1c, 0);
        if (pnpc)
        {
            if (pnpc == (CellOwnerNPCView*)apActorBase)
                bHasResultObj = true;
        }
        else
        {
            TESFaction* pfaction = (TESFaction*)FUN_00ec43fb(powner, 0, &DAT_01183028, &DAT_01184704, 0);
            if (pfaction)
            {
                int irank = FUN_00546ac0();
                CellOwnerNPCView* pactnpc =
                    (CellOwnerNPCView*)FUN_00ec43fb(apActorBase, 0, &DAT_011846e8, &DAT_01183a1c, 0);
                if (pactnpc)
                {
                    int iactrank = pactnpc->actorData.GetFactionRank(pfaction, false);
                    if (iactrank >= irank)
                        bHasResultObj = true;
                }
            }
        }
    }
    return bHasResultObj;
}
}  // namespace fnv_00546ee0

struct Actor;
struct BGSSaveFormBuffer;
struct SaveLoadFile;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiColor;
struct ThreeByThreeMatrix;
struct NiPoint3;
struct NiQuaternion;
struct TESBoundObject;
struct TESForm;
struct hkVector4;

struct CellInitLoadView : public TESObjectCELL
{
    void FUN_005559d0(BGSLoadFormBuffer*);
};

struct CellInitLoadBaseView
{
    void FUN_004534f0(BGSLoadFormBuffer*);
};

struct FUN_00546bf0_stub
{
    void FUN_00546bf0(TESForm*);
};
TESForm* __cdecl _ref_004839c0(TESForm*);
// Calls the base load method, then resolves and passes the owner form when change flag 8 is set.
// @fnv 0x005559d0
void CellInitLoadView::FUN_005559d0(BGSLoadFormBuffer* apLoadGameBuffer)
{
    ((CellInitLoadBaseView*)this)->FUN_004534f0(apLoadGameBuffer);
    if (((BGSChangeFlags_s*)&apLoadGameBuffer->GetChangeFlags())->Test(8))
    {
        TESForm* powner = ((DoorCell*)this)->GetOwner();
        if (powner)
        {
            powner = powner ? _ref_004839c0(powner) : 0;
            ((FUN_00546bf0_stub*)this)->FUN_00546bf0(powner);
        }
    }
}

struct Call_006c0c80
{
    void FUN_006c0c80(TESObjectREFR* object);
};

class NavMeshObstacleManager : public Call_006c0c80
{
  public:
    static NavMeshObstacleManager* __cdecl GetSingleton();
    void FUN_006c1060(TESObjectREFR* object);
};

class TESBoundObject;
TESBoundObject* __fastcall _FNV_GetObjectReference(TESObjectREFR* object);
unsigned int __fastcall _FNV_GetFormType(TESForm* form);

struct CellObstacleVirtualBase
{
    virtual unsigned char f01()
    {
        return 0;
    }
    virtual unsigned char f02()
    {
        return 0;
    }
    virtual unsigned char f03()
    {
        return 0;
    }
    virtual unsigned char f04()
    {
        return 0;
    }
    virtual unsigned char f05()
    {
        return 0;
    }
    virtual unsigned char f06()
    {
        return 0;
    }
    virtual unsigned char f07()
    {
        return 0;
    }
    virtual unsigned char f08()
    {
        return 0;
    }
    virtual unsigned char f09()
    {
        return 0;
    }
    virtual unsigned char f10()
    {
        return 0;
    }
    virtual unsigned char f11()
    {
        return 0;
    }
    virtual unsigned char f12()
    {
        return 0;
    }
    virtual unsigned char f13()
    {
        return 0;
    }
    virtual unsigned char f14()
    {
        return 0;
    }
    virtual unsigned char f15()
    {
        return 0;
    }
    virtual unsigned char f16()
    {
        return 0;
    }
    virtual unsigned char f17()
    {
        return 0;
    }
    virtual unsigned char f18()
    {
        return 0;
    }
    virtual unsigned char f19()
    {
        return 0;
    }
    virtual unsigned char f20()
    {
        return 0;
    }
    virtual unsigned char f21()
    {
        return 0;
    }
    virtual unsigned char f22()
    {
        return 0;
    }
    virtual unsigned char f23()
    {
        return 0;
    }
    virtual unsigned char f24()
    {
        return 0;
    }
    virtual unsigned char f25()
    {
        return 0;
    }
    virtual unsigned char f26()
    {
        return 0;
    }
    virtual unsigned char f27()
    {
        return 0;
    }
    virtual unsigned char f28()
    {
        return 0;
    }
    virtual unsigned char f29()
    {
        return 0;
    }
    virtual unsigned char f30()
    {
        return 0;
    }
    virtual unsigned char f31()
    {
        return 0;
    }
    virtual unsigned char f32()
    {
        return 0;
    }
    virtual unsigned char f33()
    {
        return 0;
    }
    virtual unsigned char f34()
    {
        return 0;
    }
    virtual unsigned char f35()
    {
        return 0;
    }
    virtual unsigned char f36()
    {
        return 0;
    }
    virtual unsigned char f37()
    {
        return 0;
    }
    virtual unsigned char f38()
    {
        return 0;
    }
    virtual unsigned char f39()
    {
        return 0;
    }
    virtual unsigned char f40()
    {
        return 0;
    }
    virtual unsigned char f41()
    {
        return 0;
    }
    virtual unsigned char f42()
    {
        return 0;
    }
    virtual unsigned char f43()
    {
        return 0;
    }
    virtual unsigned char f44()
    {
        return 0;
    }
    virtual unsigned char f45()
    {
        return 0;
    }
    virtual unsigned char f46()
    {
        return 0;
    }
    virtual unsigned char f47()
    {
        return 0;
    }
    virtual unsigned char f48()
    {
        return 0;
    }
    virtual unsigned char f49()
    {
        return 0;
    }
    virtual unsigned char f50()
    {
        return 0;
    }
    virtual unsigned char f51()
    {
        return 0;
    }
    virtual unsigned char f52()
    {
        return 0;
    }
    virtual unsigned char f53()
    {
        return 0;
    }
    virtual unsigned char f54()
    {
        return 0;
    }
    virtual unsigned char f55()
    {
        return 0;
    }
    virtual unsigned char f56()
    {
        return 0;
    }
    virtual unsigned char f57()
    {
        return 0;
    }
    virtual unsigned char f58()
    {
        return 0;
    }
    virtual unsigned char f59()
    {
        return 0;
    }
    virtual unsigned char f60()
    {
        return 0;
    }
    virtual unsigned char f61()
    {
        return 0;
    }
    virtual unsigned char f62()
    {
        return 0;
    }
    virtual unsigned char f63()
    {
        return 0;
    }
    virtual unsigned char f64()
    {
        return 0;
    }
    virtual unsigned char f65()
    {
        return 0;
    }
    virtual unsigned char f66()
    {
        return 0;
    }
    virtual unsigned char f67()
    {
        return 0;
    }
    virtual unsigned char f68()
    {
        return 0;
    }
    virtual unsigned char f69()
    {
        return 0;
    }
    virtual unsigned char f70()
    {
        return 0;
    }
    virtual unsigned char f71()
    {
        return 0;
    }
    virtual unsigned char f72()
    {
        return 0;
    }
    virtual unsigned char f73()
    {
        return 0;
    }
    virtual unsigned char f74()
    {
        return 0;
    }
    virtual unsigned char f75()
    {
        return 0;
    }
    virtual unsigned char f76()
    {
        return 0;
    }
    virtual unsigned char f77()
    {
        return 0;
    }
    virtual unsigned char f78()
    {
        return 0;
    }
    virtual unsigned char f79()
    {
        return 0;
    }
    virtual unsigned char f80()
    {
        return 0;
    }
    virtual unsigned char f81()
    {
        return 0;
    }
    virtual unsigned char f82()
    {
        return 0;
    }
    virtual unsigned char f83()
    {
        return 0;
    }
    virtual unsigned char f84()
    {
        return 0;
    }
    virtual unsigned char f85()
    {
        return 0;
    }
    virtual unsigned char f86()
    {
        return 0;
    }
    virtual unsigned char f87()
    {
        return 0;
    }
};

struct CellObstacleVirtual : public CellObstacleVirtualBase
{
    virtual unsigned char Check()
    {
        return 0;
    }
};

struct FUN_00551110_Cell : public TESObjectCELL
{
  public:
    void FUN_005576c0();
};

// Iterates a BGSPerkEntry list and calls NavMeshObstacleManager methods based on Check() and whether the referenced form type is 0x1C.
// @fnv 0x005576c0
void FUN_00551110_Cell::FUN_005576c0()
{
    CellRefLockEnter();

    BSSimpleList<BGSPerkEntry*>* perkList = FUN_009604f0();
    while (perkList)
    {
        BGSPerkEntry* perk = perkList->GetItem();
        if (perk)
        {
            if (reinterpret_cast<CellObstacleVirtual*>(perk)->Check())
            {
                NavMeshObstacleManager::GetSingleton()->FUN_006c0c80(reinterpret_cast<TESObjectREFR*>(perk));
            }

            if (_FNV_GetFormType(reinterpret_cast<TESForm*>(
                    _FNV_GetObjectReference(reinterpret_cast<TESObjectREFR*>(perk)))) == 0x1C)
            {
                NavMeshObstacleManager::GetSingleton()->FUN_006c1060(reinterpret_cast<TESObjectREFR*>(perk));
            }
        }

        perkList = perkList->GetNext();
    }

    CellRefLockLeave();
}

struct Actor;
class TESFaction;
__if_exists(::TESBoundObject::~TESBoundObject)
{
    using ::TESBoundObject;
}
__if_exists(::TESNPC::~TESNPC)
{
    using ::TESNPC;
}
class TESBoundObject;
class TESNPC;
__if_not_exists(TESBoundObject::~TESBoundObject)
{
    class TESBoundObject
    {
      public:
        virtual ~TESBoundObject();
    };
}
__if_not_exists(TESNPC::~TESNPC)
{
    class TESNPC
    {
    };
}
class type_info;
__if_not_exists(DAT_01183028)
{
    extern const type_info DAT_01183028;
}
__if_not_exists(DAT_01183a1c)
{
    extern const type_info DAT_01183a1c;
}
__if_not_exists(DAT_01184704)
{
    extern const type_info DAT_01184704;
}
extern "C" void* __cdecl _FNV_DynamicCast(void*, long, const void*, const void*, int);
__if_not_exists(_g_thePlayer)
{
    extern void* _g_thePlayer;
}

struct TrespassCellView : TESObjectCELL
{
    bool FUN_00546da0(Actor*);
};
struct TrespassActorDataView
{
    int GetFactionRank(TESFaction*, bool);
};
struct TrespassNpcView
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
    TrespassActorDataView actorData;
};
struct TrespassPublicView
{
    unsigned char IsAnyConditionTrue();
};
struct TrespassGlobalView
{
    void* FUN_00546aa0();
};
struct TrespassRankView
{
    int FUN_00546ac0();
};
struct TrespassReferenceView
{
    TESBoundObject* FUN_007af430();
};

struct TrespassActorView
{
    virtual void p000();
    virtual void p001();
    virtual void p002();
    virtual void p003();
    virtual void p004();
    virtual void p005();
    virtual void p006();
    virtual void p007();
    virtual void p008();
    virtual void p009();
    virtual void p010();
    virtual void p011();
    virtual void p012();
    virtual void p013();
    virtual void p014();
    virtual void p015();
    virtual void p016();
    virtual void p017();
    virtual void p018();
    virtual void p019();
    virtual void p020();
    virtual void p021();
    virtual void p022();
    virtual void p023();
    virtual void p024();
    virtual void p025();
    virtual void p026();
    virtual void p027();
    virtual void p028();
    virtual void p029();
    virtual void p030();
    virtual void p031();
    virtual void p032();
    virtual void p033();
    virtual void p034();
    virtual void p035();
    virtual void p036();
    virtual void p037();
    virtual void p038();
    virtual void p039();
    virtual void p040();
    virtual void p041();
    virtual void p042();
    virtual void p043();
    virtual void p044();
    virtual void p045();
    virtual void p046();
    virtual void p047();
    virtual void p048();
    virtual void p049();
    virtual void p050();
    virtual void p051();
    virtual void p052();
    virtual void p053();
    virtual void p054();
    virtual void p055();
    virtual void p056();
    virtual void p057();
    virtual void p058();
    virtual void p059();
    virtual void p060();
    virtual void p061();
    virtual void p062();
    virtual void p063();
    virtual void p064();
    virtual void p065();
    virtual void p066();
    virtual void p067();
    virtual void p068();
    virtual void p069();
    virtual void p070();
    virtual void p071();
    virtual void p072();
    virtual void p073();
    virtual void p074();
    virtual void p075();
    virtual void p076();
    virtual void p077();
    virtual void p078();
    virtual void p079();
    virtual void p080();
    virtual void p081();
    virtual void p082();
    virtual void p083();
    virtual void p084();
    virtual void p085();
    virtual void p086();
    virtual void p087();
    virtual void p088();
    virtual void p089();
    virtual void p090();
    virtual void p091();
    virtual void p092();
    virtual void p093();
    virtual void p094();
    virtual void p095();
    virtual void p096();
    virtual void p097();
    virtual void p098();
    virtual void p099();
    virtual void p100();
    virtual void p101();
    virtual void p102();
    virtual void p103();
    virtual void p104();
    virtual void p105();
    virtual void p106();
    virtual void p107();
    virtual void p108();
    virtual void p109();
    virtual void p110();
    virtual void p111();
    virtual void p112();
    virtual void p113();
    virtual void p114();
    virtual void p115();
    virtual void p116();
    virtual void p117();
    virtual void p118();
    virtual void p119();
    virtual void p120();
    virtual void p121();
    virtual void p122();
    virtual void p123();
    virtual void p124();
    virtual void p125();
    virtual void p126();
    virtual void p127();
    virtual void p128();
    virtual void p129();
    virtual void p130();
    virtual void p131();
    virtual void p132();
    virtual void p133();
    virtual bool V218();
    virtual void p135();
    virtual void p136();
    virtual void p137();
    virtual void p138();
    virtual void p139();
    virtual void p140();
    virtual void p141();
    virtual void p142();
    virtual void p143();
    virtual void p144();
    virtual void p145();
    virtual void p146();
    virtual void p147();
    virtual void p148();
    virtual void p149();
    virtual void p150();
    virtual void p151();
    virtual void p152();
    virtual void p153();
    virtual void p154();
    virtual void p155();
    virtual void p156();
    virtual void p157();
    virtual void p158();
    virtual void p159();
    virtual void p160();
    virtual void p161();
    virtual void p162();
    virtual void p163();
    virtual void p164();
    virtual void p165();
    virtual void p166();
    virtual void p167();
    virtual void p168();
    virtual void p169();
    virtual void p170();
    virtual void p171();
    virtual void p172();
    virtual void p173();
    virtual void p174();
    virtual void p175();
    virtual void p176();
    virtual void p177();
    virtual void p178();
    virtual void p179();
    virtual void p180();
    virtual void p181();
    virtual void p182();
    virtual void p183();
    virtual void p184();
    virtual void p185();
    virtual void p186();
    virtual void p187();
    virtual void p188();
    virtual void p189();
    virtual void p190();
    virtual void p191();
    virtual void p192();
    virtual bool V304();
};

// Returns false when the initial actor check fails; otherwise checks ownership, public status, actor references, and faction rank.
// @fnv 0x00546da0
bool TrespassCellView::FUN_00546da0(Actor* apActor)
{
    bool bHasResultObj = false;
    if (((TrespassActorView*)apActor)->V304())
        return false;
    TESForm* powner = ((DoorCell*)this)->GetOwner();
    if (powner && !((TrespassPublicView*)this)->IsAnyConditionTrue())
    {
        if (((TrespassGlobalView*)this)->FUN_00546aa0() || !((TrespassActorView*)apActor)->V218())
            return bHasResultObj;
        TrespassNpcView* pnpc = (TrespassNpcView*)_FNV_DynamicCast(powner, 0, &DAT_01183028, &DAT_01183a1c, 0);
        if (pnpc)
        {
            if (pnpc != (TrespassNpcView*)((TrespassReferenceView*)apActor)->FUN_007af430())
                bHasResultObj = true;
        }
        else
        {
            TESFaction* pfaction = (TESFaction*)_FNV_DynamicCast(powner, 0, &DAT_01183028, &DAT_01184704, 0);
            if (pfaction)
            {
                int irank = ((TrespassRankView*)this)->FUN_00546ac0();
                TrespassNpcView* pactnpc =
                    (TrespassNpcView*)dynamic_cast<TESNPC*>(((TrespassReferenceView*)apActor)->FUN_007af430());
                int iactrank = pactnpc->actorData.GetFactionRank(pfaction, apActor == (void*)_g_thePlayer);
                if (iactrank < irank)
                    bHasResultObj = true;
            }
        }
    }
    return bHasResultObj;
}

namespace fnv_00541ce0 {
struct FUN_004855a0
{
    void M();
};

struct DoorPart30
{
    unsigned int unk00, unk04, unk08;
    void FUN_00487010();
};

struct FUN_00485680
{
    void M();
};

struct FUN_0058f080
{
    void Save();
};

using ::ImpactSwap;
using ::FUN_0041c460;

struct ExtraDataListSave_standin
{
    void WriteToSave();
};

struct CellSaveInteriorData
{
    void SwapBytes();
};

struct S_00462230
{
    void FUN_00462230();
};

struct _ref_0084e3a0_standin
{
    void* _ref_0084e3a0();
};

struct CellSaveTexture
{
    char* FUN_00408da0();
    unsigned int FUN_0048cee0();
};

struct CellSaveFields
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    DoorPart30 fullName;
    unsigned char flags, unk25;
    unsigned short unk26;
    ExtraDataList extras;
    unsigned int unk48, unk4c;
    float waterHeight;
    unsigned int unk54;
    CellSaveTexture texture;
};

bool _FUN_00401500();
void __cdecl _FUN_00485910(int, int);
void __cdecl _FUN_00485910(int, unsigned int);
void __cdecl _FUN_00485910(int, float);
void __cdecl FUN_004858f0(unsigned int, unsigned char);
void __cdecl AppendChunk(unsigned int, void*, unsigned int);
void __cdecl FUN_004856f0(unsigned int, void*, unsigned int);

struct CellSaveShell : public TESObjectCELL
{
    void FUN_00541ce0();
};

// Writes the cell's save data, including interior/exterior data, lighting, water height, texture, and extra data list.
// @fnv 0x00541ce0
void CellSaveShell::FUN_00541ce0()
{
    unsigned int imageSpaceModifier;
    ExteriorCellData* interiorData;
    ImpactSwap* lightingData;
    InteriorCellData* pInteriorData;

    reinterpret_cast<FUN_004855a0*>(this)->M();
    reinterpret_cast<CellSaveFields*>(this)->fullName.FUN_00487010();
    FUN_004858f0(0x41544144, this->field24);

    if (this->IsCellInterior())
    {
        pInteriorData = this->GetInteriorData();
        if (_FUN_00401500())
            reinterpret_cast<CellSaveInteriorData*>(pInteriorData)->SwapBytes();

        AppendChunk(0x4c4c4358, pInteriorData, 0x2c);

        if (_FUN_00401500())
            reinterpret_cast<CellSaveInteriorData*>(pInteriorData)->SwapBytes();

        lightingData = FUN_0041c460(reinterpret_cast<TESDataHandler*>(this)->GetTESImageSpaceModifierList());
        if (lightingData)
            reinterpret_cast<FUN_0058f080*>(lightingData)->Save();
    }
    else
    {
        interiorData = this->GetExteriorData();
        if (_FUN_00401500())
            reinterpret_cast<S_00462230*>(interiorData)->FUN_00462230();

        AppendChunk(0x434c4358, interiorData, 0xc);

        if (_FUN_00401500())
            reinterpret_cast<S_00462230*>(interiorData)->FUN_00462230();
    }

    imageSpaceModifier =
        this->GetLightingTemplate()
            ? reinterpret_cast<unsigned int>(
                  reinterpret_cast<_ref_0084e3a0_standin*>(this->GetLightingTemplate())->_ref_0084e3a0())
            : 0;

    _FUN_00485910(0x504d544c, imageSpaceModifier);
    _FUN_00485910(0x4d414e4c, this->unknownDC);
    _FUN_00485910(0x574c4358, reinterpret_cast<CellSaveFields*>(this)->waterHeight);

    FUN_004856f0(0x4d414e58, reinterpret_cast<CellSaveFields*>(this)->texture.FUN_00408da0(),
                 reinterpret_cast<CellSaveFields*>(this)->texture.FUN_0048cee0() + 1);

    reinterpret_cast<ExtraDataListSave_standin*>(&this->extraDataList)->WriteToSave();
    reinterpret_cast<FUN_00485680*>(this)->M();
}

}

class TESChildCell
{
  public:
    virtual void* GetContainingCell();
};
namespace fnv_00543230 {
using ::TESForm;
using ::TESObjectCELL;
using ::TESChildCell;
using ::FUN_00425fd0;
using ::FUN_0054ddd0;
struct CellSaveFormID
{
    unsigned int FUN_0084e3a0();
};
struct CellSaveBlock
{
    unsigned int FUN_005441b0();
};
struct CellSaveSubblock
{
    unsigned int FUN_00544210();
};
struct S00543230_CellOrder;
struct S00543230_CellOrder
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
    virtual bool LessThan(TESForm*);
    bool FUN_00543230(TESForm* form);
    bool FUN_005516c0();
    bool IsLessThan(TESForm*);
};
struct S00543230_FormTypeOrder
{
    int FUN_00401170();
};
// Applies cell-specific ordering checks for selected form types and falls back to FUN_00484020 for others.
// @fnv 0x00543230
bool S00543230_CellOrder::FUN_00543230(TESForm* form)
{
    bool result = false;
    switch (reinterpret_cast<S00543230_FormTypeOrder*>(form)->FUN_00401170())
    {
    case 0x3a:
    case 0x3b:
    case 0x3c:
    case 0x3d:
    case 0x3e:
    case 0x3f:
    case 0x40:
    case 0x42:
    case 0x43:
    case 0x69: {
        TESChildCell* child = dynamic_cast<TESChildCell*>(form);
        if (child->GetContainingCell() == this)
            result = true;
        else
            result = LessThan(static_cast<TESForm*>(child->GetContainingCell()));
        break;
    }
    case 0x41:
        if (!FUN_00425fd0(this))
            result = static_cast<S00543230_CellOrder*>(FUN_0054ddd0(this))->LessThan(form);
        else
            result = true;
        break;
    case 0x39: {
        S00543230_CellOrder* other = reinterpret_cast<S00543230_CellOrder*>(dynamic_cast<TESObjectCELL*>(form));
        if (other)
        {
            if (FUN_00425fd0(this) && !FUN_00425fd0(other))
                result = true;
            else if (FUN_00425fd0(this) == FUN_00425fd0(other))
            {
                bool comparePosition = true;
                if (!FUN_00425fd0(this))
                {
                    S00543230_CellOrder* world = static_cast<S00543230_CellOrder*>(FUN_0054ddd0(this));
                    S00543230_CellOrder* otherWorld = static_cast<S00543230_CellOrder*>(FUN_0054ddd0(other));
                    if (world != otherWorld)
                    {
                        result = world->LessThan(reinterpret_cast<TESForm*>(otherWorld));
                        comparePosition = false;
                    }
                    else if (FUN_005516c0() != other->FUN_005516c0())
                    {
                        if (FUN_005516c0())
                            result = true;
                        else
                            result = false;
                        comparePosition = false;
                    }
                }
                if (comparePosition)
                {
                    if (reinterpret_cast<CellSaveBlock*>(this)->FUN_005441b0() <
                        reinterpret_cast<CellSaveBlock*>(other)->FUN_005441b0())
                        result = true;
                    else if (reinterpret_cast<CellSaveBlock*>(this)->FUN_005441b0() ==
                             reinterpret_cast<CellSaveBlock*>(other)->FUN_005441b0())
                    {
                        if (reinterpret_cast<CellSaveSubblock*>(this)->FUN_00544210() <
                            reinterpret_cast<CellSaveSubblock*>(other)->FUN_00544210())
                            result = true;
                        else if (reinterpret_cast<CellSaveSubblock*>(this)->FUN_00544210() ==
                                 reinterpret_cast<CellSaveSubblock*>(other)->FUN_00544210())
                        {
                            if (reinterpret_cast<CellSaveFormID*>(this)->FUN_0084e3a0() <
                                reinterpret_cast<CellSaveFormID*>(other)->FUN_0084e3a0())
                                result = true;
                        }
                    }
                }
            }
        }
        break;
    }
    default:
        result = IsLessThan(form);
        break;
    }
    return result;
}

}

namespace fnv_00543c50 {
using ::TESForm;
using ::TESObjectCELL;
using ::TESDataHandler;
using ::CellLightingTemplate;
using ::InteriorCellData;
using ::ExteriorCellData;
using ::BSSimpleList;
using ::TESImageSpaceModifier;
struct FUN_00497280_shell
{
    unsigned int GetFieldAt124();
};

struct FUN_005e79a0_t
{
    bool FUN_00485270(TESForm* compareCell);
};

struct FUN_004127e0_shell
{
    bool CompareList(BSSimpleList<TESImageSpaceModifier*>* otherList);
};

struct CellCompareComponent
{
    virtual void* v0();
    virtual void* v1();
    virtual void* v2();
    virtual bool Compare(void* otherData);
};

struct CellCompareFields
{
    unsigned int field00;
    unsigned int field04;
    unsigned int field08;
    unsigned int field0c;
    unsigned int field10;
    unsigned int field14;
    unsigned int field18;
    unsigned int field1c;
    unsigned int field20;
    unsigned int field24;
    unsigned int field28;
    unsigned int field2c;
    unsigned int field30;
    unsigned int field34;
    unsigned int field38;
    unsigned int field3c;
    unsigned int field40;
    unsigned int field44;
    unsigned int field48;
    unsigned int field4c;
    float waterHeight;
    unsigned int field54;
    CellCompareComponent component;
};

struct CellCompareView : public TESObjectCELL
{
    unsigned char GetField24();
    CellLightingTemplate* GetLightingTemplate();
    bool FUN_00543c50(TESForm* apCompare);
};

extern int __cdecl _memcmp(const void* left, const void* right, unsigned int count);

// Returns true when a checked cell field, data block, image space modifier list, or component comparison reports a difference.
// @fnv 0x00543c50
bool CellCompareView::FUN_00543c50(TESForm* apCompare)
{
    TESForm* pCompareCell;

    pCompareCell = reinterpret_cast<TESForm*>(dynamic_cast<TESObjectCELL*>(apCompare));

    if (!pCompareCell)
    {
        return true;
    }

    if (((FUN_005e79a0_t*)this)->FUN_00485270(pCompareCell))
    {
        return true;
    }

    if ((signed char)this->GetField24() != (signed char)((CellCompareView*)pCompareCell)->GetField24())
    {
        return true;
    }

    if (this->unknownDC != ((FUN_00497280_shell*)pCompareCell)->GetFieldAt124())
    {
        return true;
    }

    if (this->GetLightingTemplate() != ((CellCompareView*)pCompareCell)->GetLightingTemplate())
    {
        return true;
    }

    if (((CellCompareFields*)this)->waterHeight != ((CellCompareFields*)pCompareCell)->waterHeight)
    {
        return true;
    }

    if (this->IsCellInterior())
    {
        InteriorCellData* pdata;
        InteriorCellData* pCompareData;

        pdata = this->GetInteriorData();
        pCompareData = ((TESObjectCELL*)pCompareCell)->GetInteriorData();

        if (pdata && pCompareData && _memcmp(pdata, pCompareData, 0x2c) != 0)
        {
            return true;
        }
    }
    else
    {
        ExteriorCellData* pdata;
        ExteriorCellData* pCompareData;

        pdata = this->GetExteriorData();
        pCompareData = ((TESObjectCELL*)pCompareCell)->GetExteriorData();

        if (pdata && pCompareData && _memcmp(pdata, pCompareData, 0xc) != 0)
        {
            return true;
        }
    }

    if (((FUN_004127e0_shell*)((TESDataHandler*)this)->GetTESImageSpaceModifierList())
            ->CompareList(((TESDataHandler*)pCompareCell)->GetTESImageSpaceModifierList()))
    {
        return true;
    }

    if (((CellCompareFields*)this)->component.Compare(&((CellCompareFields*)pCompareCell)->component))
    {
        return true;
    }

    return false;
}

}

__if_exists(::TESImageSpace)
{
    using ::TESImageSpace;
}
__if_not_exists(::TESImageSpace)
{
    class TESImageSpace : public TESForm
    {
    };
}
namespace cell547 {
struct C5Region
{
    TESImageSpace* GetWorldSpaceOrParentWorld();
};
struct C5Cell
{
    TESImageSpace* FUN_00547650();
    bool FUN_00425fd0();
    C5Region* FUN_0054ddd0();
    bool FUN_00454b10();
    TESImageSpace* FUN_00547680();
};
}
using namespace cell547;

typedef TESForm*(__cdecl* GetFormFn)(unsigned int);

// Returns the cell image space, falling back to a region image space or form 0x160/0x161 depending on cell state.
// @fnv 0x00547680
TESImageSpace* C5Cell::FUN_00547680()
{
    TESImageSpace* m_pImageSpace = FUN_00547650();
    if (!m_pImageSpace && !FUN_00425fd0() && FUN_0054ddd0())
    {
        m_pImageSpace = FUN_0054ddd0()->GetWorldSpaceOrParentWorld();
    }
    if (!m_pImageSpace && FUN_00425fd0() && !FUN_00454b10())
    {
        m_pImageSpace = dynamic_cast<TESImageSpace*>(((GetFormFn)FUN_004839c0)(0x160));
    }
    else if (!m_pImageSpace)
    {
        m_pImageSpace = dynamic_cast<TESImageSpace*>(((GetFormFn)FUN_004839c0)(0x161));
    }
    return m_pImageSpace;
}
