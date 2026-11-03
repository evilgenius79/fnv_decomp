
// src/fallout_shared/tesland_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesland.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "tesland_decls.h"
#pragma optimize("",off)
int TruncateFloatToInt(float value);

void __cdecl Deallocate(void*);

struct FUN_00533260_holder {
    void __thiscall FUN_00533260();
};

struct FUN_00533210_class {
    void* __thiscall FUN_00533210(unsigned int flags);
};

// @fnv 0x00533210
void* __thiscall FUN_00533210_class::FUN_00533210(unsigned int flags)
{
    ((FUN_00533260_holder*)this)->FUN_00533260();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct CellH {
    int GetCellGridX();
};
struct FUN_00533fd0_Class {
    int FUN_00533fd0();
};
// @fnv 0x00533fd0
int FUN_00533fd0_Class::FUN_00533fd0()
{
    if (reinterpret_cast<void**>(this)[0x28 / 4])
        return reinterpret_cast<int*>(reinterpret_cast<void**>(this)[0x28 / 4])[0x98 / 4];
    if (reinterpret_cast<void**>(this)[0x20 / 4])
        return reinterpret_cast<CellH*>(reinterpret_cast<void**>(this)[0x20 / 4])->GetCellGridX();
    return 0;
}

namespace fnv_00534010 {
struct CellH { int GetCellGridY(); };
struct FUN_00534010 {
    int GetY();
};
// @fnv 0x00534010
int FUN_00534010::GetY()
{
    if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x28))
        return *reinterpret_cast<int*>(*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x28) + 0x9c);
    if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x20))
        return reinterpret_cast<CellH*>(*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x20))->GetCellGridY();
    return 0;
}
}  // namespace fnv_00534010

struct FUN_00534050_Class {
    int FUN_00533fd0();
    float FUN_00534050();
};

// @fnv 0x00534050
float FUN_00534050_Class::FUN_00534050()
{
    int result = FUN_00533fd0();
    return static_cast<float>(result << 12);
}

struct FUN_00534080_Class {
    int FUN_00534010();
    double FUN_00534080();
};

// @fnv 0x00534080
double FUN_00534080_Class::FUN_00534080()
{
    int result = FUN_00534010();
    return static_cast<double>(result << 0xc);
}

struct TESWorldSpace;
struct DoorH { TESWorldSpace* GetParentWorldSpace(); };
struct FUN_005340b0_Class {
    int m_auiShapeKeys[8];
    DoorH* m_pDoor;
    TESWorldSpace* FUN_005340b0();
};
// @fnv 0x005340b0
TESWorldSpace* FUN_005340b0_Class::FUN_005340b0()
{
    if (m_pDoor)
    {
        return m_pDoor->GetParentWorldSpace();
    }
    return 0;
}

namespace fnv_005340e0 {
struct DoorH { void* GetParentWorldSpace(); };
struct TESObjectCELL {};
struct TESWorldSpace {
	enum PARENT_USE_FLAG { PARENT_USE_FLAG_0 = 0 };
	TESWorldSpace* GetParentWorld(PARENT_USE_FLAG);
};
struct TESObjectLAND {
	void FUN_00534160(int);
	void FUN_005340e0(TESObjectCELL* apCell);
};
// @fnv 0x005340e0
void TESObjectLAND::FUN_005340e0(TESObjectCELL* apCell)
{
	TESWorldSpace* pworld;
	*(TESObjectCELL**)((char*)this + 0x20) = apCell;
	if (*(TESObjectCELL**)((char*)this + 0x20) != 0) {
		pworld = (TESWorldSpace*)((DoorH*)*(TESObjectCELL**)((char*)this + 0x20))->GetParentWorldSpace();
		if (pworld != 0 && pworld->GetParentWorld((TESWorldSpace::PARENT_USE_FLAG)0) != 0)
			FUN_00534160(1);
		else
			FUN_00534160(0);
	}
}
}  // namespace fnv_005340e0

struct FUN_00534140_Class {
    bool FUN_00534140();
};

// @fnv 0x00534140
bool FUN_00534140_Class::FUN_00534140()
{
    if (((int*)this)[7] & 0x400)
        return true;
    return false;
}

struct FUN_00534160_Class {
    void FUN_00534160(bool set);
};

// @fnv 0x00534160
void FUN_00534160_Class::FUN_00534160(bool set)
{
    if (set)
        *(int*)((char*)this + 0x1c) |= 0x400;
    else
        *(int*)((char*)this + 0x1c) &= ~0x400;
}

struct FUN_005341a0_Class {
    void FUN_005341a0(bool set);
};

// @fnv 0x005341a0
void FUN_005341a0_Class::FUN_005341a0(bool set)
{
    if (set)
        *(int*)((char*)this + 0x1c) |= 0x800;
    else
        *(int*)((char*)this + 0x1c) &= ~0x800;
}

struct FUN_005341e0_Class {
    bool FUN_005341e0();
};
// @fnv 0x005341e0
bool FUN_005341e0_Class::FUN_005341e0()
{
    if (reinterpret_cast<const unsigned int*>(this)[7] & 0x10)
        return true;
    return false;
}

struct FUN_00534200_Class {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    void FUN_00534200(bool value);
};

// @fnv 0x00534200
void FUN_00534200_Class::FUN_00534200(bool value)
{
    if (value)
        m_1c |= 0x10;
    else
        m_1c &= ~0x10;
}

struct NiPoint3 { float x; float y; float z; };
struct TESForm { void Revert(unsigned int); };
struct FUN_00534570_shell { char* m_pkDeltas; unsigned int stride; void FUN_00534570(unsigned int index, NiPoint3& vertex); };
// @fnv 0x00534570
void FUN_00534570_shell::FUN_00534570(unsigned int index, NiPoint3& vertex)
{
    ((TESForm*)this)->TESForm::Revert(index);
    char* pVertex = m_pkDeltas + index * stride;
    NiPoint3& result = *(NiPoint3*)pVertex;
    vertex = result;
}

template<int> struct EndianSizeTag {};
void BSEndian(int*, EndianSizeTag<2>);
void BSEndian(unsigned short*, EndianSizeTag<2>);

struct FUN_00535a60_Class {
    void FUN_00535a60();
};

// @fnv 0x00535a60
void FUN_00535a60_Class::FUN_00535a60()
{
    BSEndian(reinterpret_cast<int*>(this), EndianSizeTag<2>());
    BSEndian(reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(this) + 6), EndianSizeTag<2>());
}

extern int DAT_011c9f04;

// @fnv 0x00535ae0
int FUN_00535ae0()
{
    return DAT_011c9f04;
}

namespace fnv_00535b30 {
extern double DAT_01016968;
struct NiPoint3 { float x, y, z; NiPoint3(); };
struct FUN_00535b30_class {
    NiPoint3 FUN_00535b30(int block);
    float FUN_00534050();
    float FUN_00534080();
    float FUN_0049db00();
};
// @fnv 0x00535b30
NiPoint3 FUN_00535b30_class::FUN_00535b30(int block)
{
    NiPoint3 result;
    result.x = FUN_00534050() + DAT_01016968;
    result.y = FUN_00534080() + DAT_01016968;
    result.z = FUN_0049db00();
    return result;
}
}  // namespace fnv_00535b30

extern "C" void __cdecl _Deallocate(void*);

struct FUN_00537100_Class {
    void __thiscall FUN_00537130();
    void* __thiscall FUN_00537100(unsigned int flags);
};

// @fnv 0x00537100
void* __thiscall FUN_00537100_Class::FUN_00537100(unsigned int flags)
{
    FUN_00537130();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

extern const char* const g_011f4aac_arg1;

struct FUN_00537ca0_class
{
    const char* const* FUN_00537ca0();
};

// @fnv 0x00537ca0
const char* const* FUN_00537ca0_class::FUN_00537ca0()
{
    return &g_011f4aac_arg1;
}

struct FUN_00a73080_holder { void FUN_00a73080(); };
void __cdecl operator delete(void* p, unsigned int size);
struct NiAdditionalGeometryData {
    void* FUN_00537cb0(unsigned int flags);
};
// @fnv 0x00537cb0
void* NiAdditionalGeometryData::FUN_00537cb0(unsigned int flags)
{
    reinterpret_cast<FUN_00a73080_holder*>(this)->FUN_00a73080();
    if (flags & 1)
        operator delete(this, 0x2c);
    return this;
}

struct FUN_00540800_Class {
    void FUN_00540800();
    void FUN_00537ce0();
};

// @fnv 0x00537ce0
void FUN_00540800_Class::FUN_00537ce0()
{
    FUN_00540800();
}

extern "C" void* g_011f4aac;

struct FUN_00537d00_Class {
    void* __thiscall FUN_00537d00();
};

// @fnv 0x00537d00
void* __thiscall FUN_00537d00_Class::FUN_00537d00()
{
    return &g_011f4aac;
}

struct FUN_00537d10_Class {
    void FUN_00537d40();
    void* FUN_00537d10(unsigned int flags);
    static void operator delete(void* p, unsigned int size);
};

// @fnv 0x00537d10
void* FUN_00537d10_Class::FUN_00537d10(unsigned int flags)
{
    this->FUN_00537d40();
    if (flags & 1)
        operator delete(this, 52);
    return this;
}

struct QuantityData { void SetQuantity(unsigned int); };
struct TESRaceForm { void Initialize(unsigned int); };
struct TESObjectREFR { void SetFlags(unsigned int); };
struct MagicCaster { void SetSelectedMagicItem(int); };
struct TESConditionItem { void SetObjectType(int); };
struct TESQuest;
struct BGSQuestObjective { void SetOwner(TESQuest*); };
struct FUN_00537e30_cls { char _pad[24]; int _m18; int _m1c; FUN_00537e30_cls* FUN_00537e30(); };
// @fnv 0x00537e30
FUN_00537e30_cls* FUN_00537e30_cls::FUN_00537e30()
{
    ((QuantityData*)this)->SetQuantity(0);
    ((TESRaceForm*)this)->Initialize(0);
    ((TESObjectREFR*)this)->SetFlags(0);
    ((MagicCaster*)this)->SetSelectedMagicItem(0);
    ((TESConditionItem*)this)->SetObjectType(0);
    ((BGSQuestObjective*)this)->SetOwner(0);
    _m18 = 0;
    _m1c = 0;
    return this;
}

struct FUN_00537e90 {
    unsigned int quantity;
    void SetQuantity(unsigned int value);
};

// @fnv 0x00537e90
void FUN_00537e90::SetQuantity(unsigned int value)
{
    quantity = value;
}

struct FUN_00538e30_class {
    void __fastcall SetVtable();
};
extern int DAT_0102e378;
struct FUN_00538e10_class {
    int* m_vtbl;
    void __fastcall FUN_00538e10();
};
// @fnv 0x00538e10
void __fastcall FUN_00538e10_class::FUN_00538e10()
{
    m_vtbl = &DAT_0102e378;
    ((FUN_00538e30_class*)this)->SetVtable();
}

namespace fnv_00538e50 {
struct FUN_00538e30_class {
    void __fastcall SetVtable();
    void* __thiscall FUN_00538e50(unsigned int flags);
};
// @fnv 0x00538e50
void* __thiscall FUN_00538e30_class::FUN_00538e50(unsigned int flags)
{
    SetVtable();
    if (flags & 1)
        operator delete(this);
    return this;
}
}  // namespace fnv_00538e50

struct B1 { virtual ~B1(); void* FUN_00538e80(unsigned int); };
void __cdecl FUN_00538eb0(void*);
// @fnv 0x00538e80
void* B1::FUN_00538e80(unsigned int flags)
{
    this->B1::~B1();
    if (flags & 1)
        FUN_00538eb0(this);
    return this;
}

extern "C" void __cdecl FUN_00538f20();
extern int DAT_0102e378;

struct FUN_00538ef0_class {
    void* m_ppVirtualMethodTable;
    int m_kPointA;
    int m_kPointB;
    void FUN_00538f20();
    void* FUN_00538ef0();
};

// @fnv 0x00538ef0
void* FUN_00538ef0_class::FUN_00538ef0()
{
    FUN_00538f20();
    m_ppVirtualMethodTable = &DAT_0102e378;
    *(unsigned short*)((char*)this + 6) = 1;
    return this;
}

extern int DAT_0102e388;

struct FUN_00538f20 {
    int* p;
    FUN_00538f20();
};

// @fnv 0x00538f20
FUN_00538f20::FUN_00538f20()
{
    p = &DAT_0102e388;
}

void __cdecl FUN_00538eb0(void*);
struct FUN_00538f80 {
    void __thiscall FUN_00538fb0();
    void* __thiscall DeleteThis(unsigned int flags);
};
// @fnv 0x00538f80
void* __thiscall FUN_00538f80::DeleteThis(unsigned int flags)
{
    FUN_00538fb0();
    if (flags & 1)
        FUN_00538eb0(this);
    return this;
}

namespace fnv_00538fb0 {
struct B1 { virtual ~B1(); };
struct FUN_005408e0 { ~FUN_005408e0(); };
struct FUN_00538fb0 : B1 { char _pad[28]; FUN_005408e0 m; ~FUN_00538fb0(); };
// @fnv 0x00538fb0
FUN_00538fb0::~FUN_00538fb0() {}
}  // namespace fnv_00538fb0

struct FUN_00539460_Class {
    char m_00[0x1c];
    int m_1c;
    bool FUN_00539460();
};

// @fnv 0x00539460
bool FUN_00539460_Class::FUN_00539460()
{
    if (m_1c & 1)
        return true;
    if (m_1c & 4)
        return true;
    if (m_1c & 2)
        return true;
    return false;
}

struct FUN_005394c0_Class {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    void FUN_005394c0(bool value);
};

// @fnv 0x005394c0
void FUN_005394c0_Class::FUN_005394c0(bool value)
{
    if (value)
        m_1c |= 8;
    else
        m_1c &= ~8;
}

struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_011f4ab8;

struct FUN_00539fc0_Class
{
    GlobalObjectO2_00a7b610* FUN_00539fc0();
};

// @fnv 0x00539fc0
GlobalObjectO2_00a7b610* FUN_00539fc0_Class::FUN_00539fc0()
{
    return &g_011f4ab8;
}

void __cdecl operator delete(void* p, unsigned int size);

struct FUN_0053a000 {
    void __thiscall Destruct();
};

struct FUN_00539fd0 : public FUN_0053a000 {
    void* __thiscall ScalarDeletingDestructor(unsigned int flags);
};

// @fnv 0x00539fd0
void* __thiscall FUN_00539fd0::ScalarDeletingDestructor(unsigned int flags)
{
    reinterpret_cast<FUN_0053a000*>(this)->Destruct();
    if (flags & 1)
        operator delete(this, 0x14);
    return this;
}

struct FUN_0053a070_Class {
    void __thiscall FUN_0053a070(int a, int b);
};

// @fnv 0x0053a070
void __thiscall FUN_0053a070_Class::FUN_0053a070(int a, int b)
{
    *(int*)((char*)this + 0x10) = a;
    *(int*)((char*)this + 0xc) = b;
}

struct B006815c0 { B006815c0(); };
struct FUN_0053a510 {
    B006815c0 m0;
    char _p1[7];
    B006815c0 m1;
    char _p2[19];
    B006815c0 m2;
    char _p3[19];
    B006815c0 m3;
    FUN_0053a510();
};
// @fnv 0x0053a510
FUN_0053a510::FUN_0053a510()
{
}

namespace fnv_0053a550 {
struct TESWorldSpace;
struct TESObjectCELL;
struct TESWorldSpace {
    float GetFloatAt0xC8();
};
extern float DAT_0102dcc4;
struct DoorH {
    void* GetParentWorldSpace();
    void* _FNV_GetObjectReference();
    float FUN_0053a550();
};
// @fnv 0x0053a550
float DoorH::FUN_0053a550()
{
    float fretval = DAT_0102dcc4;
    TESObjectCELL* pcell = (TESObjectCELL*)_FNV_GetObjectReference();
    if (pcell) {
        TESWorldSpace* pworld = (TESWorldSpace*)((DoorH*)pcell)->GetParentWorldSpace();
        if (pworld)
            fretval = pworld->GetFloatAt0xC8();
    }
    return fretval;
}
}  // namespace fnv_0053a550

struct FUN_0053a760_Class {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30[6];
    void FUN_0053a760(unsigned char a, unsigned short b, int c);
};
// @fnv 0x0053a760
void FUN_0053a760_Class::FUN_0053a760(unsigned char a, unsigned short b, int c)
{
    if (a < 4 && b < 6 && m_28)
        ((int**)((char*)m_28 + 0x30))[a][b] = c;
}

struct FUN_0053ae30_class {
    int __thiscall FUN_0053a700(unsigned char, unsigned short);
    float __thiscall FUN_0053a830(unsigned char, unsigned short, unsigned short);
    float __thiscall FUN_0053ae30(unsigned char type, unsigned short id);
};
// @fnv 0x0053ae30
float FUN_0053ae30_class::FUN_0053ae30(unsigned char type, unsigned short id)
{
    float result = 0.0f;
    if (type < 4 && id < 6) {
        if (FUN_0053a700(type, id)) {
            for (int i = 0; i < 289; ++i) {
                result += FUN_0053a830(type, (unsigned short)i, id);
            }
        }
    }
    return result;
}

struct GlobalObject_0044f440 {
    float* Float();
};

extern GlobalObject_0044f440 g_011c8dcc;

// @fnv 0x0053ca40
float FUN_0053ca40()
{
    return *g_011c8dcc.Float();
}

struct FUN_0053ca60 {
    void FUN_00b600e0();
    FUN_0053ca60* Init();
};

// @fnv 0x0053ca60
FUN_0053ca60* FUN_0053ca60::Init()
{
    FUN_00b600e0();
    return this;
}

struct Buf50
{
    int m00; int m04; int m08; int m0C; int m10; int m14; int m18; int m1C;
    int m20; int m24; int m28; int m2C; int m30; int m34; int m38; int m3C;
    int m40; int m44; int m48; int m4C;
    void FUN_0053a510();
};
struct Owner
{
    bool FUN_0053b550(Buf50*, int, int);
    bool ComputeTerrainNormalAndTangent(Buf50*, int, int);
    bool FUN_0053d2e0(int, int, int);
};
// @fnv 0x0053d2e0
bool Owner::FUN_0053d2e0(int a1, int a2, int a3)
{
    Buf50 buf;
    buf.FUN_0053a510();
    if (!FUN_0053b550(&buf, a1, 0))
        return false;
    return ComputeTerrainNormalAndTangent(&buf, a2, a3);
}

struct FUN_0053df00_Class {
    int __thiscall FUN_0053df00();
};

// @fnv 0x0053df00
int __thiscall FUN_0053df00_Class::FUN_0053df00()
{
    return *(int*)((char*)this + 0x28) ? *(int*)((char*)*(int*)((char*)this + 0x28) + 8) : 0;
}

struct Tmp53e210 {
    int m00;
    int m04;
    int m08;
    int m0C;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    int m28;
    int m2C;
    int m30;
    int m34;
    int m38;
    int m3C;
    int m40;
    int m44;
    int m48;
    int m4C;
    void FUN_0053a510();
};
struct Host53e210 {
    bool FUN_0053b550(Tmp53e210* p, int a, int b);
    bool FUN_0053e260(int a, int b);
    bool FUN_0053e210(int a);
};
// @fnv 0x0053e210
bool Host53e210::FUN_0053e210(int a) {
    Tmp53e210 tmp;
    tmp.FUN_0053a510();
    if (!this->FUN_0053b550(&tmp, a, 0))
        return 0;
    return this->FUN_0053e260(tmp.m18, tmp.m3C);
}

struct FUN_0053e260_Class {
    void* m_p; // +0x00
    void* m_q; // +0x04
    void* m_r; // +0x08
    void* m_s; // +0x0c
    void* m_t; // +0x10
    void* m_u; // +0x14
    void* m_v; // +0x18
    void* m_w; // +0x1c
    void* m_uiX; // +0x20
    void* m_uiY; // +0x24
    void* m_uiZ; // +0x28
    unsigned char FUN_0053e260(int index, int offset);
};

// @fnv 0x0053e260
unsigned char FUN_0053e260_Class::FUN_0053e260(int index, int offset)
{
    return ((unsigned char*)((void**)((void**)m_uiZ)[4])[index])[offset];
}

namespace fnv_0053f0e0 {
struct NiPoint3 { float x; float y; float z; };
struct NiGeometry { int _0; };
struct LandscapeColorData {
 int m00; int m04; int m08; int m0C; int m10; int m14; int m18; int m1C;
 int m20; int m24; int m28; int m2C; int m30; int m34; int m38; int m3C;
 int m40; int m44; int m48; int m4C;
 void __thiscall FUN_0053a510();
};
struct TESObjectLAND {
 bool __thiscall FUN_0053b550(LandscapeColorData*, const NiPoint3*, int);
 NiGeometry* __thiscall FUN_0053f120(LandscapeColorData*);
 NiGeometry* __thiscall FUN_0053f0e0(const NiPoint3&);
};
// @fnv 0x0053f0e0
NiGeometry* TESObjectLAND::FUN_0053f0e0(const NiPoint3& coord)
{
 LandscapeColorData cdata;
 cdata.FUN_0053a510();
 if (!FUN_0053b550(&cdata, &coord, 0))
  return 0;
 return FUN_0053f120(&cdata);
}
}  // namespace fnv_0053f0e0

struct NiAVObject;
struct NiNode { NiAVObject* FUN_0045bc00(unsigned int); };
struct FUN_0053f120_Param { unsigned char _pad[0x18]; unsigned int idx; };
struct FUN_0053f120_Holder { unsigned char _pad[0x28]; NiNode*** fld28; NiAVObject* FUN_0053f120(FUN_0053f120_Param*); };
// @fnv 0x0053f120
NiAVObject* FUN_0053f120_Holder::FUN_0053f120(FUN_0053f120_Param* a)
{
    if (fld28 == 0 || *fld28 == 0 || (*fld28)[a->idx] == 0)
        return 0;
    return (*fld28)[a->idx]->FUN_0045bc00(0);
}

struct LandscapeColorData
{
    int m00,m04,m08,m0C,m10,m14,m18,m1C,m20,m24,m28,m2C,m30,m34,m38,m3C,m40,m44,m48,m4C;
    void __thiscall FUN_0053a510();
};
struct TESObjectLAND
{
    bool __thiscall FUN_0053b550(LandscapeColorData&, const LandscapeColorData&, int);
    float __thiscall FUN_0053a550();
    bool __thiscall FUN_0053f1e0(LandscapeColorData&, float&);
    bool __thiscall FUN_0053f180(const LandscapeColorData&, float&);
};
// @fnv 0x0053f180
bool __thiscall TESObjectLAND::FUN_0053f180(const LandscapeColorData& a, float& b)
{
    LandscapeColorData tmp;
    tmp.FUN_0053a510();
    if (!FUN_0053b550(tmp, a, 0)) {
        b = FUN_0053a550();
        return 0;
    }
    return FUN_0053f1e0(tmp, b);
}

namespace fnv_0053fa10 {
struct RgbaColor { float r, g, b, a; };
struct LandscapeColorData { char _00[0x18]; int m_iGridX; char _1C[0x20]; int m_iGridY; };
struct TESObjectLAND {
    void FUN_005345c0(int m_iGridX, int m_iGridY, RgbaColor* color);
    bool FUN_0053fa10(const LandscapeColorData* cdata, RgbaColor* color);
};
// @fnv 0x0053fa10
bool TESObjectLAND::FUN_0053fa10(const LandscapeColorData* cdata, RgbaColor* color)
{
    FUN_005345c0(cdata->m_iGridX, cdata->m_iGridY, color);
    return true;
}
}  // namespace fnv_0053fa10

struct QueuedFile;
struct BGSTextureSet {
    void LoadTextures(int, QueuedFile*, bool);
};

struct FUN_00541540_Class {
    void FUN_00541540(int a, QueuedFile* b);
};

// @fnv 0x00541540
void FUN_00541540_Class::FUN_00541540(int a, QueuedFile* b)
{
    if (*(BGSTextureSet**)((char*)this + 0x18))
        ((BGSTextureSet**)((char*)this + 0x18))[0]->LoadTextures(a, b, true);
}

struct FUN_00541590_Class {
    char FUN_00541590();
};
// @fnv 0x00541590
char FUN_00541590_Class::FUN_00541590()
{
    return ((char*)this)[0x1f];
}

struct S_00592cf0 { void* FUN_00592cf0(); };
// @fnv 0x00592cf0
void* S_00592cf0::FUN_00592cf0()
{
    return this ? (void*)((char*)this + 0x30) : 0;
}

struct Param5380d0 {
	virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
	virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
	virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
	virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
	virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
	virtual bool v40();
};
struct This5380d0 {
	bool FUN_005380d0(Param5380d0* p);
};
// @fnv 0x005380d0
bool This5380d0::FUN_005380d0(Param5380d0* p)
{
	return p ? p->v40() : 0;
}

struct BSAudio { void* GetAudioBackendData(); };
BSAudio* _FUN_00c85750();
struct Topic
{
    virtual void f0() {}
    virtual void f1() {}
    virtual void Method(void* a, unsigned int b) {}
};
struct Prm
{
    char pad[4];
    unsigned short val;
};
// @fnv 0x00538eb0
void FUN_00538eb0(Prm* p)
{
    Prm* q = p;
    {
        Topic* t = (Topic*)_FUN_00c85750()->GetAudioBackendData();
        t->Method(p, q->val);
    }
}

namespace fnv_00539010 {
struct TESForm { void SetAltered(bool); };
struct TESObjectREFR {
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
    virtual void SetTargetingState(int);
};
struct TESObjectLAND : TESForm {
    void FUN_00539010(bool altered);
};
// @fnv 0x00539010
void TESObjectLAND::FUN_00539010(bool altered)
{
    TESForm::SetAltered(altered);
    if (altered && *(TESObjectREFR**)((char*)this + 0x20))
        (*(TESObjectREFR**)((char*)this + 0x20))->SetTargetingState(1);
}
}  // namespace fnv_00539010

struct FUN_0053a5a0_Inner
{
    char pad[32];
    void* arr[4];
};
struct FUN_0053a5a0_Outer
{
    char pad[40];
    FUN_0053a5a0_Inner* ptr;
    void* FUN_0053a5a0(unsigned char index);
};
// @fnv 0x0053a5a0
void* FUN_0053a5a0_Outer::FUN_0053a5a0(unsigned char index)
{
    void* result = 0;
    if (index < 4 && ptr != 0)
        result = ptr->arr[index];
    return result;
}

struct FUN_0053a700_Mid {
    unsigned char pad[0x30];
    int* arr[4];
};
struct FUN_0053a700_Holder {
    unsigned char pad[0x28];
    FUN_0053a700_Mid* p;
    int FUN_0053a700(unsigned char, unsigned short);
};
// @fnv 0x0053a700
int FUN_0053a700_Holder::FUN_0053a700(unsigned char a1, unsigned short a2)
{
    int result = 0;
    if (a1 < 4 && a2 < 6 && p && p->arr[a1]) {
        result = p->arr[a1][a2];
    }
    return result;
}

extern float DAT_01015f5c;
struct FUN_0053a630_Class : public FUN_0053ae30_class {
    int FUN_0053a630(unsigned char type, unsigned short id);
};
// @fnv 0x0053a630
int FUN_0053a630_Class::FUN_0053a630(unsigned char type, unsigned short id)
{
    int result = 0;
    if (type < 4 && id < 0x121) {
        float best = DAT_01015f5c;
        int index = 0;
        for (unsigned int i = 0; i < 6; ++i) {
            float value = FUN_0053a830(type, id, i);
            if (value > best) {
                best = value;
                index = i;
            }
        }
        if (index == 0) {
            result = (int)((FUN_0053a5a0_Outer*)this)->FUN_0053a5a0(type);
        } else {
            result = FUN_0053a700(type, index - 1);
        }
    }
    return result;
}

struct A51BF0Base {
    static void* operator new(unsigned int); static void operator delete(void*, unsigned int);
};

struct FUN_00537d60 : A51BF0Base {
    char _pad[0x18];
    int _m18;
    int _m1c;
    FUN_00537e30_cls* FUN_00537e30();
    void SetQuantity(unsigned int);
    void Initialize(unsigned int);
    void SetFlags(unsigned int);
    void SetSelectedMagicItem(int);
    void SetObjectType(int);
    void SetOwner(TESQuest*);
    FUN_00537d60();
};

// @fnv 0x00537d60
void* FUN_00537d60_Create(unsigned int a, unsigned int b, unsigned int c, int d, int e)
{
    FUN_00537d60* obj = new FUN_00537d60;
    if (obj) {
        obj->SetQuantity(e);
        obj->Initialize(a);
        obj->SetFlags(b);
        obj->SetSelectedMagicItem(c);
        obj->SetObjectType(d);
        obj->SetOwner(0);
    }
    return obj;
}

struct FUN_005330d8_class
{
    void _FNV_GetObjectReference();
};

struct FUN_005331f0_class
{
    void FUN_005331f0();
};

// @fnv 0x005331f0
void FUN_005331f0_class::FUN_005331f0()
{
    reinterpret_cast<FUN_005330d8_class*>(
        reinterpret_cast<char*>(this) - 0x18)->_FNV_GetObjectReference();
}

extern int DAT_0102dcd4;
extern int DAT_0102dccc;
extern unsigned char DAT_011c9efc;
extern int DAT_011c9f00;
void __cdecl FUN_00533420();
void __cdecl FUN_00403d30(void* p, int value, unsigned int size);

struct FUN_00483370 {
    void* m_vt;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    FUN_00483370();
    ~FUN_00483370();
};

struct FUN_00533240_cls {
    void* m_vt;
    FUN_00533240_cls();
};

struct FUN_00528cb0_cls {
    int m_00;
    FUN_00528cb0_cls(int value);
    ~FUN_00528cb0_cls();
};

struct FUN_00533120_cls : FUN_00483370 {
    FUN_00533240_cls m_18;
    int m_1c;
    int m_20;
    FUN_00528cb0_cls m_24;
    int m_28;

    FUN_00533120_cls();
    void FUN_004f15a0(int value);
};

// @fnv 0x00533120
FUN_00533120_cls::FUN_00533120_cls() : m_18(), m_24((this->m_vt = &DAT_0102dcd4, this->m_18.m_vt = &DAT_0102dccc, 0))
{
    if (DAT_011c9efc == 0) {
        FUN_00533420();
    }
    FUN_00403d30(&this->m_1c, 0, 4);
    this->m_20 = 0;
    this->FUN_004f15a0(0x42);
    this->m_28 = 0;
    DAT_011c9f00++;
}

struct AutoMemContext {
    int ctx;
    AutoMemContext(int memContext, bool push, const char* file, int line);
    ~AutoMemContext();
};

bool IsLandLoadBlocked();

struct TESFile;

struct LandData {
    int unk00;
};

struct LandForm : TESPackage {
    int unk20;
    int unk24;
    LandData* unk28;

    bool FUN_00535b90(bool bFlag);
    bool IsLoaded();
    TESFile* GetFile(int index);
    void SetLoadState(bool value);
    bool ReadTypedData();
    void SetDataLoaded(bool value);
    void Finish();
};

// @fnv 0x00535b90
bool LandForm::FUN_00535b90(bool bFlag) {
    AutoMemContext memContext(0x1b, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESLand.cpp", 0x455);
    if (IsLandLoadBlocked())
        bFlag = false;
    if (FUN_005394a0()) {
        if (unk28->unk00 == 0 && bFlag)
            Finish();
        return true;
    }
    if (!IsLoaded() && (!((flags & 1) || (flags & 2) || (flags & 4)) || !GetFile(-1))) {
        SetLoadState(false);
        if (bFlag)
            Finish();
        return true;
    }
    SetLoadState(false);
    bool bResult2 = ReadTypedData();
    SetDataLoaded(true);
    if (bFlag)
        Finish();
    return bResult2;
}

struct FUN_0045cec0 {
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
    ~FUN_0045cec0();
};

struct FUN_005409b0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    ~FUN_005409b0();
};

struct FUN_00537130 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    FUN_0045cec0 m_14;
    FUN_005409b0 m_54[4];
    FUN_0045cec0 m_94;

    ~FUN_00537130();
};

// @fnv 0x00537130
FUN_00537130::~FUN_00537130() {
}

class D40NiObject {
public:
    virtual ~D40NiObject();

    int m_uiRefCount;
};

class FUN_00537d40 : public D40NiObject {
public:
    virtual ~FUN_00537d40();
};

// @fnv 0x00537d40
FUN_00537d40::~FUN_00537d40()
{
}

int TruncateFloatToInt(float value);
bool FUN_00401500();
void __cdecl AppendChunk(unsigned int fourcc, void* buf, unsigned int size);
void __cdecl FUN_004856f0(unsigned int fourcc, void* buf, unsigned int size);
int __cdecl FUN_00ec7d40(int v);
void __cdecl FNV_Warning(const char* fmt, ...);
void __cdecl CompressSaveLoadRecord();
int FUN_00535ae0();
void __fastcall FUN_00503210(void* p);
struct FUN_0084e3a0_Class { int FUN_0084e3a0(); };
struct FUN_00535aa0_Class { void FUN_00535aa0(); };
struct FUN_004855a0_shell { void FUN_004855a0(); };
struct FUN_00485680_shell { void FUN_00485680(); };
extern double DAT_0102dfe0;
extern double DAT_0101e568;
extern double DAT_01012060;

struct Elem16 { float x; float y; float z; float w; };
struct FUN_004a0c10_Class { float x; float y; float z; void FUN_004a0c10(); };
struct Data538110 {
    void* m_00;
    NiPoint3** m_04;
    NiPoint3** m_08;
    Elem16** m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20arr[4];
    int* m_30arr[4];
    int m_40arr[4];
};
struct BigBuf538110 {
    float m_00;
    char m_04[1092];
};
struct X538110 {
    int m_00;
    unsigned char m_04;
    unsigned char m_05;
    unsigned short m_06;
};
struct Entry538110 {
    unsigned short m_00;
    unsigned short m_02;
    float m_04;
};






struct FUN_0053db20_Class { void FUN_0053db20(); };
struct FUN_0053a940_Class { void FUN_0053a940(); };
struct This538110 {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    Data538110* m_28;
    void FUN_00538110();
};
// @fnv 0x00538110
void This538110::FUN_00538110()
{
    int i;
    int p0;
    bool wVal;
    BigBuf538110 B;
    int w_;
    if (!((FUN_00539460_Class*)this)->FUN_00539460() || (!(m_1c & 8) && !(m_28 && m_28->m_04 && m_28->m_08 && m_28->m_0c))) {
    } else {
    if (!((FUN_005341e0_Class*)this)->FUN_005341e0())
        ((FUN_0053db20_Class*)this)->FUN_0053db20();
    ((FUN_004855a0_shell*)this)->FUN_004855a0();
    if (FUN_00401500())
        FUN_00503210(&m_1c);
    AppendChunk(0x41544144, &m_1c, 4);
    if (FUN_00401500())
        FUN_00503210(&m_1c);
    if (m_1c & 1) {
        unsigned char v6[3267];
        int a1[1089];
        int base;
        int pX;
        int skip;
        int v2;
        for (i = 0; i < 4; i++) {
            base = ((i / 2) << 4) * 33 + ((i % 2) << 4);
            for (pX = 0; pX < 0x121; pX++) {
                v2 = (pX / 17) * 33 + base + (pX % 17);
                skip = 0;
                if (pX / 17 == 16) {
                    skip = 1;
                    if (i / 2 == 1)
                        skip = 0;
                }
                if (pX % 17 == 16) {
                    skip = 1;
                    if (i % 2 == 1)
                        skip = 0;
                }
                if (!skip) {
                    a1[v2] = TruncateFloatToInt(m_28->m_04[i][pX].z) >> 3;
                    ((FUN_004a0c10_Class*)&m_28->m_08[i][pX])->FUN_004a0c10();
                    v6[v2 * 3 + 0] = (unsigned char)(int)(m_28->m_08[i][pX].x * DAT_0102dfe0);
                    v6[v2 * 3 + 1] = (unsigned char)(int)(m_28->m_08[i][pX].y * DAT_0102dfe0);
                    v6[v2 * 3 + 2] = (unsigned char)(int)(m_28->m_08[i][pX].z * DAT_0102dfe0);
                }
            }
        }
        FUN_004856f0(0x4c4d4e56, v6, 0xcc3);
        B.m_00 = (float)a1[0];
        w_ = a1[0];
        wVal = 0;
        for (i = 0; i < 0x441; i++) {
            if (FUN_00ec7d40(a1[i] - w_) >= 0x80) {
                wVal = 1;
                if (a1[i] > w_)
                    B.m_04[i] = (char)0x7f;
                else
                    B.m_04[i] = (char)0x81;
            } else {
                B.m_04[i] = (char)(a1[i] - w_);
            }
            if ((i + 1) % 33 == 0) {
                w_ = a1[i - 32];
            } else if (!wVal) {
                w_ = a1[i];
            } else {
                w_ = (signed char)B.m_04[i] + w_;
            }
        }
        if (FUN_00401500())
            FUN_00503210(&B);
        AppendChunk(0x54474856, &B, 0x448);
        if (FUN_00401500())
            FUN_00503210(&B);
        if (wVal)
            FNV_Warning("MASTERFILE: Error saving land height Data for cell (%i, %i). Error correction attempted.\r\n", ((FUN_00533fd0_Class*)this)->FUN_00533fd0(), ((FUN_00534080_Class*)this)->FUN_00534010());
    }
    if (m_1c & 2) {
        unsigned char v3[3267];
        int w8;
        int v1;
        int idx2;
        for (i = 0; i < 4; i++) {
            w8 = ((i / 2) << 4) * 33 + ((i % 2) << 4);
            for (p0 = 0; p0 < 0x121; p0++) {
                idx2 = (p0 / 17) * 33 + w8 + (p0 % 17);
                v1 = 0;
                if (p0 / 17 == 16) {
                    v1 = 1;
                    if (i / 2 == 1)
                        v1 = 0;
                }
                if (p0 % 17 == 16) {
                    v1 = 1;
                    if (i % 2 == 1)
                        v1 = 0;
                }
                if (!v1) {
                    v3[idx2 * 3 + 0] = (unsigned char)(m_28->m_0c[i][p0].x * DAT_0101e568);
                    v3[idx2 * 3 + 1] = (unsigned char)(m_28->m_0c[i][p0].y * DAT_0101e568);
                    v3[idx2 * 3 + 2] = (unsigned char)(m_28->m_0c[i][p0].z * DAT_0101e568);
                }
            }
        }
        FUN_004856f0(0x524c4356, v3, 0xcc3);
    }
    if (m_1c & 4) {
        int w;
        ((FUN_0053a940_Class*)this)->FUN_0053a940();
        for (w = 0; w < 4; w++) {
            if (m_28->m_20arr[w] != 0 && m_28->m_20arr[w] != FUN_00535ae0()) {
                X538110 v;
                v.m_04 = (unsigned char)w;
                v.m_06 = 0xffff;
                v.m_00 = ((FUN_0084e3a0_Class*)m_28->m_20arr[w])->FUN_0084e3a0();
                if (FUN_00401500())
                    ((FUN_00535a60_Class*)&v)->FUN_00535a60();
                AppendChunk(0x54585442, &v, 8);
                if (FUN_00401500())
                    ((FUN_00535a60_Class*)&v)->FUN_00535a60();
            }
            if (m_28->m_30arr[w] != 0) {
                int u3;
                int u6;
                int w1;
                u3 = 6;
                for (u6 = 0; u6 < u3; u6++) {
                    w1 = m_28->m_30arr[w][u6];
                    if (w1 != 0) {
                    {
                        X538110 pTmp;
                        pTmp.m_04 = (unsigned char)w;
                        pTmp.m_06 = (unsigned short)u6;
                        pTmp.m_00 = (w1 != FUN_00535ae0()) ? ((FUN_0084e3a0_Class*)w1)->FUN_0084e3a0() : 0;
                        if (FUN_00401500())
                            ((FUN_00535a60_Class*)&pTmp)->FUN_00535a60();
                        AppendChunk(0x54585441, &pTmp, 8);
                        if (FUN_00401500())
                            ((FUN_00535a60_Class*)&pTmp)->FUN_00535a60();
                    }
                    {
                        Entry538110 t7[289];
                        int v4;
                        int uA;
                        float v9;
                        unsigned int w7;
                        unsigned int v5;
                        v4 = 0;
                        for (uA = 0; uA < 0x121; uA++) {
                            if (m_28->m_40arr[w] != 0) {
                                v9 = ((FUN_0053ae30_class*)this)->FUN_0053a830((unsigned char)w, (unsigned short)uA, (unsigned short)u6);
                                if (v9 > DAT_01012060) {
                                    t7[v4].m_04 = v9;
                                    t7[v4].m_00 = (unsigned short)uA;
                                    v4++;
                                }
                            }
                        }
                        if (v4 != 0) {
                            if (FUN_00401500()) {
                                for (w7 = 0; w7 < (unsigned int)v4; w7++)
                                    ((FUN_00535aa0_Class*)&t7[w7])->FUN_00535aa0();
                            }
                            AppendChunk(0x54585456, t7, v4 * 8);
                            if (FUN_00401500()) {
                                for (v5 = 0; v5 < (unsigned int)v4; v5++)
                                    ((FUN_00535aa0_Class*)&t7[v5])->FUN_00535aa0();
                            }
                        }
                    }
                    }
                }
            }
        }
    }
    ((FUN_00485680_shell*)this)->FUN_00485680();
    CompressSaveLoadRecord();
    }
}

struct Base8ef0 { virtual void v0(); int a; int b; int c; Base8ef0(); ~Base8ef0(); };
struct MA { int x[4]; MA(); void Go(); };
struct MB { int x[3]; MB(); ~MB(); };
struct MC { int x[4]; MC(); void Fin(int); };
struct FUN_00538d70_cls : Base8ef0 {
    MA a; MB b; MC c;
    FUN_00538d70_cls();
    virtual void v0();
};
// @fnv 0x00538d70
FUN_00538d70_cls::FUN_00538d70_cls() {
    a.Go();
    c.Fin(2);
}

extern void* DAT_01187020;
struct S_00539280_Arg {
    void* unk00;
    int unk04;
    int unk08;
    unsigned int unk0c;
};
struct S_00539280_Obj {
    virtual void vfn00();
    virtual void vfn01();
    virtual void vfn02();
    virtual void vfn03();
    virtual void vfn04();
    virtual void vfn05();
    virtual void vfn06();
    virtual void vfn07();
    virtual void vfn08();
    virtual void vfn09();
    virtual void vfn0a();
    virtual void vfn0b();
    virtual void vfn0c();
    virtual void vfn0d();
    virtual void vfn0e();
    virtual void vfn0f();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual void vfn1a();
    virtual void vfn1b();
    virtual void vfn1c();
    virtual void vfn1d();
    virtual void vfn1e();
    virtual void vfn1f();
    virtual void vfn20();
    virtual void vfn21();
    virtual void vfn22();
    virtual void vfn23();
    virtual void vfn24();
    virtual void vfn25();
    virtual void vfn26();
    virtual void vfn27();
    virtual void vfn28();
    virtual void vfn29();
    virtual void vfn2a();
    virtual void vfn2b();
    virtual void vfn2c();
    virtual void vfn2d();
    virtual void vfn2e();
    virtual void vfn2f();
    virtual void vfn30();
    virtual void vfn31();
    virtual void vfn32();
    virtual void vfn33();
    virtual void vfn34();
    virtual void vfn35();
    virtual void vfn36();
    virtual void vfn37();
    virtual void vfn38();
    virtual void vfn39();
    virtual void vfn3a();
    virtual void vfn3b();
    virtual void vfn3c();
    virtual void vfn3d();
    virtual void vfn3e();
    virtual void vfn3f();
    virtual void vfn40();
    virtual void vfn41();
    virtual void vfn42();
    virtual void vfn43();
    virtual bool vfn44(S_00539280_Arg* a, bool b, bool c);
    bool FUN_00485be0(int id);
};
struct S_00539280_Owner {
    S_00539280_Obj* FUN_007af430();
    bool FUN_00539280(S_00539280_Arg* a, bool b, bool c);
};
// @fnv 0x00539280
bool S_00539280_Owner::FUN_00539280(S_00539280_Arg* a, bool b, bool c)
{
    bool result = false;
    if (a && a->unk00 == DAT_01187020) {
        S_00539280_Obj* o = FUN_007af430();
        switch (a->unk0c) {
        case 6:
            if (!b) {
                result = false;
                break;
            }
        case 8:
        case 9:
        {
            bool found = false;
            if (o->FUN_00485be0(a->unk08))
                found = true;
            if (found) {
                switch (a->unk0c) {
                case 8:
                    result = false;
                    break;
                default:
                    result = true;
                    break;
                }
            }
            break;
        }
        default:
            if (b)
                result = o->vfn44(a, b, c);
            break;
        }
    }
    return result;
}

namespace fnv_00539360 {
extern int DAT_01187020;

struct Out539 {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
};

struct In539 {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
};

void* __fastcall FUN_007af430(void* self);
int __fastcall FUN_0084e3a0(void* self);
int __fastcall FUN_00544210(void* self);

struct FUN_00539360_cls {
    void FUN_00539360(Out539* a, In539* b);
};

// @fnv 0x00539360
void FUN_00539360_cls::FUN_00539360(Out539* a, In539* b) {
    void* p1;
    int t2;
    if (a != 0) {
        a->m_00 = 0;
        if (b != 0) {
            p1 = FUN_007af430(this);
            t2 = FUN_0084e3a0(FUN_007af430(this));
            switch (b->m_0c) {
            case 3:
            case 5:
                if (b->m_08 == FUN_00544210(p1)) {
                    a->m_00 = DAT_01187020;
                    a->m_0c = 6;
                    a->m_08 = t2;
                    a->m_04 = 0;
                    a->m_10 = 0;
                }
                break;
            case 6:
                if (b->m_08 == t2) {
                    a->m_00 = DAT_01187020;
                    a->m_0c = 9;
                    a->m_08 = FUN_0084e3a0(FUN_007af430(this));
                    a->m_04 = 0;
                    a->m_10 = 0;
                }
                break;
            }
        }
    }
}
}  // namespace fnv_00539360

struct Mem960 {int value;Mem960(int,bool,const char*,int);~Mem960();};
struct Color960 {float r,g,b,a;Color960(float,float,float,float);};
struct Texture960 {Texture960* FUN_009611e0();void* FUN_00592cf0();unsigned char FUN_00541590();};
struct Property960 {virtual void v000();virtual void v004();virtual void v008();virtual void v00c();virtual void v010();virtual void v014();virtual void v018();virtual void v01c();virtual void v020();virtual void v024();virtual void v028();virtual void v02c();virtual void v030();virtual void v034();virtual void v038();virtual void v03c();virtual void v040();virtual void v044();virtual void v048();virtual void v04c();virtual void v050();virtual void v054();virtual void v058();virtual void v05c();virtual void v060();virtual void v064();virtual void v068();virtual void v06c();virtual void v070();virtual void v074();virtual void v078();virtual void v07c();virtual void v080();virtual void v084();virtual void v088();virtual void v08c();virtual void v090();virtual void v094();virtual void v098();virtual void v09c();virtual void v0a0();virtual void v0a4();virtual void v0a8();virtual void v0ac();virtual void v0b0();virtual void v0b4();virtual void v0b8();virtual void v0bc();virtual void v0c0();virtual void v0c4();virtual void v0c8();virtual void v0cc();virtual void v0d0();virtual void* vd4(void*);unsigned unk004;unsigned unk008;unsigned unk00c;unsigned unk010;unsigned unk014;unsigned unk018;unsigned unk01c;unsigned unk020;unsigned unk024;unsigned unk028;unsigned unk02c;unsigned unk030;unsigned unk034;unsigned unk038;unsigned unk03c;unsigned unk040;unsigned unk044;unsigned unk048;unsigned unk04c;unsigned unk050;unsigned unk054;unsigned unk058;unsigned unk05c;unsigned unk060;unsigned unk064;unsigned unk068;unsigned unk06c;unsigned unk070;unsigned unk074;unsigned unk078;unsigned unk07c;unsigned unk080;unsigned unk084;unsigned unk088;unsigned unk08c;unsigned unk090;unsigned unk094;unsigned unk098;unsigned unk09c;unsigned unk0a0;unsigned unk0a4;unsigned unk0a8;unsigned unk0ac;unsigned unk0b0;unsigned unk0b4;unsigned unk0b8;unsigned unk0bc;unsigned unk0c0;unsigned unk0c4;unsigned unk0c8;unsigned unk0cc;unsigned unk0d0;unsigned unk0d4;unsigned unk0d8;unsigned unk0dc;unsigned unk0e0;unsigned unk0e4;unsigned unk0e8;unsigned unk0ec;unsigned unk0f0;unsigned unk0f4;unsigned unk0f8;unsigned unk0fc;unsigned unk100;Property960();static void* operator new(unsigned); static void operator delete(void*, unsigned int);void FUN_005a8060(int);void FUN_00b68660(int,void*);void FUN_00b66640(unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,int,int,int);void FUN_00539f20(void*);};
struct Binary960 {unsigned unk00,unk04,unk08,unk0c,unk10;Binary960(unsigned,unsigned char*);static void* operator new(unsigned); static void operator delete(void*, unsigned int);};
const char* __cdecl FUN_00539f40();
struct Geometry960 {void FUN_00539ef0(void*);void FUN_00439410(Property960*);};
struct Node960 {void FUN_00a5bc40(const char*,Binary960*);Geometry960* FUN_0045bc00(unsigned);};
void* __cdecl FUN_00b54b60(Geometry960*);void __cdecl FUN_00b57e30(Node960*,int,int);
struct Data960 {Node960** nodes;unsigned unk04,unk08;Color960** colors;unsigned unk10,unk14,unk18,unk1c;Texture960* base[4];Texture960** layers[4];unsigned char** binary[4];};
struct Host960 {unsigned unk00,unk04,unk08,unk0c,unk10,unk14,unk18,flags,unk20,unk24;Data960* data;void FUN_005394c0(bool);bool FUN_00539960();};
// @fnv 0x00539960
bool Host960::FUN_00539960() {
 Mem960 f(27,true,"D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESLand.cpp",0xca4);
 if(!data || !data->nodes || !*data->nodes) return false;
 Color960 s(1,1,1,0);
 int a,p,h,i;
 if(!(flags & 2)) {
  for(a=0;a<4;a++) {
   i=0;
   for(p=0;p<17;p++) {
    for(h=0;h<17;h++) {
     int index=p*17+h;
     data->colors[a][index]=s;
    }
   }
  }
 }
 FUN_005394c0(true);
 for(a=0;a<4;a++) {
  unsigned char*** binary=data->binary;
  if(binary) {
   Binary960* extra=new Binary960(9248,*data->binary[a]);
   data->nodes[a]->FUN_00a5bc40(FUN_00539f40(),extra);
  }
  Property960* property=new Property960;
  property->FUN_005a8060(1);
  if(property) {
   Texture960* texture=data->base[a];
   if(texture && texture->FUN_009611e0()) property->FUN_00b68660(0,texture->FUN_009611e0()->FUN_00592cf0());
   else property->FUN_00b68660(0,((Texture960*)FUN_00535ae0())->FUN_009611e0()->FUN_00592cf0());
   for(int layer=1;layer<7;layer++) {
    texture=data->layers[a][layer-1];
    if(texture && texture->FUN_009611e0()) property->FUN_00b68660(layer,texture->FUN_009611e0()->FUN_00592cf0());
    else property->FUN_00b68660(layer,0);
   }
   property->FUN_00b66640(data->base[a]?data->base[a]->FUN_00541590():0,
    data->layers[a][0]?data->layers[a][0]->FUN_00541590():0,
    data->layers[a][1]?data->layers[a][1]->FUN_00541590():0,
    data->layers[a][2]?data->layers[a][2]->FUN_00541590():0,
    data->layers[a][3]?data->layers[a][3]->FUN_00541590():0,
    data->layers[a][4]?data->layers[a][4]->FUN_00541590():0,
    data->layers[a][5]?data->layers[a][5]->FUN_00541590():0,0,0,0);
   Geometry960* value=data->nodes[a]->FUN_0045bc00(0);
   void* geometry=FUN_00b54b60(value);
   property->FUN_00539f20(geometry);
   void* shader=property->vd4(value);
   value->FUN_00539ef0(shader);
   value->FUN_00439410(property);
   FUN_00b57e30(data->nodes[a],0,0);
  }
 }
 return true;
}

void __cdecl NiFree(void* pvMem);

class B53A000ExtraData {
public:
    virtual ~B53A000ExtraData();

    int m_iRefCount;
    const char* m_kName;
};

class FUN_0053a000_cls : public B53A000ExtraData {
public:
    virtual ~FUN_0053a000_cls();

    void* m_pResource;
};

// @fnv 0x0053a000
FUN_0053a000_cls::~FUN_0053a000_cls()
{
    NiFree(m_pResource);
    m_pResource = 0;
}

struct LocalObj53a5e0 {
    int m00;
    int m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    unsigned char m18;
    unsigned char unk19;
    unsigned char unk1a;
    unsigned char unk1b;
    int m1c;
    int m20;
    int m24;
    int m28;
    int m2c;
    int m30;
    int m34;
    int m38;
    unsigned short m3c;
    unsigned short unk3e;
    int m40;
    int m44;
    int m48;
    int m4c;
    int m50;
    int m54;
    void FUN_0053a510();
};

struct FUN_0053a5e0_cls {
    bool FUN_0053b550(LocalObj53a5e0* p, int a, int b);
    int FUN_0053a630(unsigned char type, unsigned short id);
    int FUN_0053a5e0(int arg);
};

// @fnv 0x0053a5e0
int FUN_0053a5e0_cls::FUN_0053a5e0(int arg) {
    LocalObj53a5e0 local;
    local.m54 = 0;
    local.FUN_0053a510();
    if (FUN_0053b550(&local, arg, 1)) {
        local.m54 = FUN_0053a630(local.m18, local.m3c);
    }
    return local.m54;
}

struct FUN_0053a7a0_Tbl {
    char pad[0x40];
    float** arr[4];
};

struct FUN_0053a7a0_cls {
    char pad[0x28];
    FUN_0053a7a0_Tbl* m_28;
    float FUN_0053a7a0(unsigned char a, unsigned short b);
};

// @fnv 0x0053a7a0
float FUN_0053a7a0_cls::FUN_0053a7a0(unsigned char a, unsigned short b) {
    float sum5 = 0.0f;
    int i;
    if ((int)a < 4 && (int)b < 0x121 && m_28 != 0 && m_28->arr[a] != 0) {
        for (i = 0; i < 6; ++i) {
            sum5 += m_28->arr[a][b][i];
        }
    }
    return 1.0f - sum5;
}

struct FUN_0053a830_Row {
    float* cells[0x121];
};

struct FUN_0053a830_Mid {
    int m00;
    int m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    int m28;
    int m2c;
    int m30;
    int m34;
    int m38;
    int m3c;
    float** tables[4];
};

struct FUN_0053a830_cls {
    int m00;
    int m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    FUN_0053a830_Mid* m_28;
    float FUN_0053a830(unsigned char type, unsigned short id, unsigned short idx);
};

// @fnv 0x0053a830
float FUN_0053a830_cls::FUN_0053a830(unsigned char type, unsigned short id, unsigned short idx) {
    float result = 0.0f;
    if (type < 4 && id < 0x121 && idx < 6) {
        if (m_28 != 0 && m_28->tables[type] != 0) {
            result = m_28->tables[type][id][idx];
        }
    }
    return result;
}

extern "C" double gModifierZero;

struct C53A8A0Data {
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
    float** m_appfTables[4];
};

class C53A8A0Owner {
public:
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
    C53A8A0Data* m_pUserData;

    void FUN_0053a8a0(unsigned char ucTable, unsigned short usRow, unsigned short usColumn, float fValue);
};

// @fnv 0x0053a8a0
void C53A8A0Owner::FUN_0053a8a0(unsigned char ucTable, unsigned short usRow, unsigned short usColumn, float fValue)
{
    if (ucTable < 4 && usRow < 0x121 && usColumn < 6 && m_pUserData) {
        if (fValue > gModifierZero)
            m_pUserData->m_appfTables[ucTable][usRow][usColumn] = fValue;
        else if (m_pUserData->m_appfTables[ucTable])
            m_pUserData->m_appfTables[ucTable][usRow][usColumn] = 0.0f;
    }
}

struct WeightTables53ace0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int current[4];
    int* choices[4];
    float** weights[4];
};

struct Owner53ace0 : public FUN_0053ae30_class {
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
    WeightTables53ace0* tables;
    void FUN_0053ace0(unsigned char type, unsigned short id);
};

// @fnv 0x0053ace0
void Owner53ace0::FUN_0053ace0(unsigned char type, unsigned short id)
{
    if (type < 4 && id < 6 && tables) {
        int newValue = tables->choices[type][id];
        int oldValue3 = tables->current[type];
        tables->current[type] = newValue;
        tables->choices[type][id] = oldValue3;
        if (tables->weights[type]) {
            for (int i = 0; i < 0x121; i++) {
                unsigned int count4 = 6;
                float sum4 = 0.0f;
                for (unsigned int j = 0; j < count4; j++) {
                    sum4 += FUN_0053a830(type, (unsigned short)i, (unsigned short)j);
                }
                float rest = 1.0f - sum4;
                if (rest < 0.0) {
                    rest = 0.0f;
                }
                tables->weights[type][i][id] = rest;
            }
        }
    }
}

extern float DAT_01017a3c;
struct FNv53b450_Point {
    float x;
    float y;
    float z;
    void FUN_006815c0();
};
struct FNv53b450_Source {
    int FUN_00533fd0();
    int FUN_00534010();
    FNv53b450_Point* FUN_0053b450(FNv53b450_Point* output, unsigned char flags, unsigned short cellIndex, const int* x, const int* y);
};
// @fnv 0x0053b450
FNv53b450_Point* FNv53b450_Source::FUN_0053b450(FNv53b450_Point* output, unsigned char flags, unsigned short cellIndex, const int* x, const int* y) {
    FNv53b450_Point result;
    result.FUN_006815c0();
    result.x = DAT_01017a3c;
    result.y = DAT_01017a3c;
    result.x = float(x ? *x : FUN_00533fd0()) * result.x;
    result.y = float(y ? *y : FUN_00534010()) * result.y;
    result.x = float(((flags & 1) ? 2048 : 0)) + result.x;
    result.y = float(((flags & 2) ? 2048 : 0)) + result.y;
    result.x = float((cellIndex % 17) << 7) + result.x;
    result.y = float((cellIndex / 17) << 7) + result.y;
    result.z = 0.0f;
    *output = result;
    return output;
}

class B3CA80Map {
public:
    bool GetAt(unsigned int uiKey, unsigned int& uiValue) const;

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

struct B3CA80Data {
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
    B3CA80Map m_akMaps[4];
};

class B3CA80Owner {
public:
    unsigned int FUN_0053ca80(int iQuad, int iIndex);

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
    B3CA80Data* m_pUserData;
};

// @fnv 0x0053ca80
unsigned int B3CA80Owner::FUN_0053ca80(int iQuad, int iIndex)
{
    if (!m_pUserData || iQuad >= 4 || iIndex + 0x12 >= 0x121 || iIndex - 0x12 < 0)
        return 0;
    unsigned int uiValue;
    if (m_pUserData->m_akMaps[iQuad].GetAt(iIndex, uiValue))
        return uiValue;
    else
        return 0;
}

struct TESWorldSpace;
struct TESObjectCELL;

struct Obj53 {
    bool FUN_0045cb90();
    void FUN_00535b90(int a);
};
struct Cell53 {
    Obj53* FUN_00546fb0();
};
struct FUN_00461c20_Holder {
    Cell53* GetOrCreateCell(int a, int b, TESWorldSpace* ws, bool f);
};
extern FUN_00461c20_Holder* DAT_011c3f2c;





struct This53 {
    void FUN_0053d330(Obj53** out, bool flag, unsigned char* outFlags);
};

// @fnv 0x0053d330
void This53::FUN_0053d330(Obj53** out, bool flag, unsigned char* outFlags)
{
    Cell53* temp;
    if (out == 0)
        return;
    temp = DAT_011c3f2c->GetOrCreateCell(((FUN_00534050_Class*)this)->FUN_00533fd0() - 1, ((FUN_00534080_Class*)this)->FUN_00534010() + 1, ((FUN_005340b0_Class*)this)->FUN_005340b0(), false);
    if (temp != 0 && temp->FUN_00546fb0()->FUN_0045cb90()) {
        out[0] = temp->FUN_00546fb0();
    } else if (temp != 0 && !temp->FUN_00546fb0()->FUN_0045cb90() && flag && outFlags != 0) {
        out[0] = temp->FUN_00546fb0();
        out[0]->FUN_00535b90(0);
        outFlags[0] = 1;
    } else {
        out[0] = 0;
    }
    temp = DAT_011c3f2c->GetOrCreateCell(((FUN_00534050_Class*)this)->FUN_00533fd0(), ((FUN_00534080_Class*)this)->FUN_00534010() + 1, ((FUN_005340b0_Class*)this)->FUN_005340b0(), false);
    if (temp != 0 && temp->FUN_00546fb0()->FUN_0045cb90()) {
        out[1] = temp->FUN_00546fb0();
    } else if (temp != 0 && !temp->FUN_00546fb0()->FUN_0045cb90() && flag && outFlags != 0) {
        out[1] = temp->FUN_00546fb0();
        out[1]->FUN_00535b90(0);
        outFlags[1] = 1;
    } else {
        out[1] = 0;
    }
    temp = DAT_011c3f2c->GetOrCreateCell(((FUN_00534050_Class*)this)->FUN_00533fd0() + 1, ((FUN_00534080_Class*)this)->FUN_00534010() + 1, ((FUN_005340b0_Class*)this)->FUN_005340b0(), false);
    if (temp != 0 && temp->FUN_00546fb0()->FUN_0045cb90()) {
        out[2] = temp->FUN_00546fb0();
    } else if (temp != 0 && !temp->FUN_00546fb0()->FUN_0045cb90() && flag && outFlags != 0) {
        out[2] = temp->FUN_00546fb0();
        out[2]->FUN_00535b90(0);
        outFlags[2] = 1;
    } else {
        out[2] = 0;
    }
    temp = DAT_011c3f2c->GetOrCreateCell(((FUN_00534050_Class*)this)->FUN_00533fd0() - 1, ((FUN_00534080_Class*)this)->FUN_00534010(), ((FUN_005340b0_Class*)this)->FUN_005340b0(), false);
    if (temp != 0 && temp->FUN_00546fb0()->FUN_0045cb90()) {
        out[3] = temp->FUN_00546fb0();
    } else if (temp != 0 && !temp->FUN_00546fb0()->FUN_0045cb90() && flag && outFlags != 0) {
        out[3] = temp->FUN_00546fb0();
        out[3]->FUN_00535b90(0);
        outFlags[3] = 1;
    } else {
        out[3] = 0;
    }
    temp = DAT_011c3f2c->GetOrCreateCell(((FUN_00534050_Class*)this)->FUN_00533fd0() + 1, ((FUN_00534080_Class*)this)->FUN_00534010(), ((FUN_005340b0_Class*)this)->FUN_005340b0(), false);
    if (temp != 0 && temp->FUN_00546fb0()->FUN_0045cb90()) {
        out[4] = temp->FUN_00546fb0();
    } else if (temp != 0 && !temp->FUN_00546fb0()->FUN_0045cb90() && flag && outFlags != 0) {
        out[4] = temp->FUN_00546fb0();
        out[4]->FUN_00535b90(0);
        outFlags[4] = 1;
    } else {
        out[4] = 0;
    }
    temp = DAT_011c3f2c->GetOrCreateCell(((FUN_00534050_Class*)this)->FUN_00533fd0() - 1, ((FUN_00534080_Class*)this)->FUN_00534010() - 1, ((FUN_005340b0_Class*)this)->FUN_005340b0(), false);
    if (temp != 0 && temp->FUN_00546fb0()->FUN_0045cb90()) {
        out[5] = temp->FUN_00546fb0();
    } else if (temp != 0 && !temp->FUN_00546fb0()->FUN_0045cb90() && flag && outFlags != 0) {
        out[5] = temp->FUN_00546fb0();
        out[5]->FUN_00535b90(0);
        outFlags[5] = 1;
    } else {
        out[5] = 0;
    }
    temp = DAT_011c3f2c->GetOrCreateCell(((FUN_00534050_Class*)this)->FUN_00533fd0(), ((FUN_00534080_Class*)this)->FUN_00534010() - 1, ((FUN_005340b0_Class*)this)->FUN_005340b0(), false);
    if (temp != 0 && temp->FUN_00546fb0()->FUN_0045cb90()) {
        out[6] = temp->FUN_00546fb0();
    } else if (temp != 0 && !temp->FUN_00546fb0()->FUN_0045cb90() && flag && outFlags != 0) {
        out[6] = temp->FUN_00546fb0();
        out[6]->FUN_00535b90(0);
        outFlags[6] = 1;
    } else {
        out[6] = 0;
    }
    temp = DAT_011c3f2c->GetOrCreateCell(((FUN_00534050_Class*)this)->FUN_00533fd0() + 1, ((FUN_00534080_Class*)this)->FUN_00534010() - 1, ((FUN_005340b0_Class*)this)->FUN_005340b0(), false);
    if (temp != 0 && temp->FUN_00546fb0()->FUN_0045cb90()) {
        out[7] = temp->FUN_00546fb0();
    } else if (temp != 0 && !temp->FUN_00546fb0()->FUN_0045cb90() && flag && outFlags != 0) {
        out[7] = temp->FUN_00546fb0();
        out[7]->FUN_00535b90(0);
        outFlags[7] = 1;
    } else {
        out[7] = 0;
    }
}

extern double DAT_01016968;

class B3DA60Point3 {
public:
    B3DA60Point3(float fX, float fY, float fZ);

    void Transform(void* pvMatrix);

    float x;
    float y;
    float z;
};

struct B3DA60Rect {
    int m_iLeft;
    int m_iBottom;
    int m_iRight;
    int m_iTop;
};

class B3DA60Object {
public:
    double GetPosY();
    float GetPosX();
    bool FUN_0053da60(B3DA60Rect* pkRect, void* pvMatrix);
};

// @fnv 0x0053da60
bool B3DA60Object::FUN_0053da60(B3DA60Rect* pkRect, void* pvMatrix)
{
    if (pkRect) {
        B3DA60Point3 kPoint(GetPosX() + DAT_01016968, GetPosY() + DAT_01016968, 0.0f);
        kPoint.Transform(pvMatrix);
        if (kPoint.x > pkRect->m_iRight || kPoint.y > pkRect->m_iBottom)
            return false;
        if (kPoint.x < pkRect->m_iLeft || kPoint.y < pkRect->m_iTop)
            return false;
    }
    return true;
}

extern float DAT_01015f5c;
extern float DAT_01016970;

struct FUN_0053f390_v2 {
    float x;
    float y;
    void FUN_00452dc0(float a, float b);
};

struct FUN_0053f390_v3 {
    float x;
    float y;
    float z;
    void FUN_006815c0();
};

struct FUN_0053f390_cls {
    void FUN_00534240(int n, int i, FUN_0053f390_v3* out);
    FUN_0053f390_v2* FUN_0053f390(FUN_0053f390_v2* out, int n);
};

// @fnv 0x0053f390
FUN_0053f390_v2* FUN_0053f390_cls::FUN_0053f390(FUN_0053f390_v2* out, int n)
{
    FUN_0053f390_v3 tmp;
    FUN_0053f390_v2 best;
    best.FUN_00452dc0(DAT_01016970, DAT_01015f5c);
    tmp.FUN_006815c0();
    if (n < 16) {
        for (int i = 0; i < 0x121; i++) {
            FUN_00534240(n, i, &tmp);
            if (tmp.z < best.x) {
                best.x = tmp.z;
            }
            if (tmp.z > best.y) {
                best.y = tmp.z;
            }
        }
    }
    *out = best;
    return out;
}

class NiPoint2 { public: float x,y; NiPoint2(float,float); };
struct UVBounds { float x,y,z,w; };
extern NiPoint3 DAT_011f426c;
extern NiPoint2 DAT_011f4980;
extern UVBounds DAT_011a9bd0;
struct TextureSample { short FUN_004a8ae0(); short FUN_0047d3f0(); unsigned int FUN_00726070(); };
struct TexturePointer { TextureSample* FUN_00559450(); };
struct TextureManager { void* FUN_006fce30(const NiPoint3&); void* FUN_006fce70(const NiPoint3&); TexturePointer* FUN_006fceb0(const NiPoint3&); };
struct WorldManager { TextureManager* FUN_00586170(); };
struct TESView { WorldManager* FUN_004fd3e0(); };
extern TESView* DAT_011dea10;
struct ShaderProperty {
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
 virtual void setFirst(int,void*);
 virtual void setSecond(int,void*);
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
 UVBounds bounds;
 int FUN_00441110(); void* GetElement(int); void* GetFltValue(int);
};
struct QuadNode { QuadNode* FUN_0045bc00(int); ShaderProperty* FUN_00a59d30(int); };
struct TESFileRecordLoader {
 QuadNode** nodes;
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
 int x,y;
};
struct Surface {
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
 TESFileRecordLoader* data;
 void FUN_005400e0();
};
// @fnv 0x005400e0
void Surface::FUN_005400e0()
{
 void* e=0;
 void* l=0;
 TextureManager* ba=DAT_011dea10->FUN_004fd3e0() ? DAT_011dea10->FUN_004fd3e0()->FUN_00586170() : 0;
 NiPoint3 c=DAT_011f426c;
 c.x=(data->x+0.5)*4096.0;
 c.y=(data->y+0.5)*4096.0;
 NiPoint2 k=DAT_011f4980;
 for(int j=0;j<4;j++) {
  if(data->nodes && ba) {
   ShaderProperty* q=data->nodes[j]->FUN_0045bc00(0)->FUN_00a59d30(3);
   ShaderProperty* b=(!q ? 0 : (q->FUN_00441110()>=8 && q->FUN_00441110()<=12)) ? q : 0;
   if(b && (!b->GetElement(9) || !b->GetFltValue(9))) {
    e=ba->FUN_006fce30(c);
    l=ba->FUN_006fce70(c);
    b->setFirst(9,e);
    b->setSecond(9,l);
    UVBounds cf=DAT_011a9bd0;
    switch(j) {
     case 0:k=NiPoint2(0.0f,0.0f);break;
     case 1:k=NiPoint2(0.5f,0.0f);break;
     case 2:k=NiPoint2(0.0f,0.5f);break;
     case 3:k=NiPoint2(0.5f,0.5f);break;
    }
    TexturePointer* eb=ba->FUN_006fceb0(c);
    if(eb) {
     short i=eb->FUN_00559450()->FUN_004a8ae0();
     short a=eb->FUN_00559450()->FUN_0047d3f0();
     unsigned int h=eb->FUN_00559450()->FUN_00726070();
     float f=(float)data->x-i;
     float s=(float)data->y-a;
     cf.x=(f+k.x)/eb->FUN_00559450()->FUN_00726070();
     cf.y=(s+k.y)/eb->FUN_00559450()->FUN_00726070();
     while(cf.x>1.0)cf.x-=1.0;
     while(cf.x<0.0)cf.x+=1.0;
     while(cf.y>1.0)cf.y-=1.0;
     while(cf.y<0.0)cf.y+=1.0;
     b->bounds=cf;
    }
   }
  }
 }
}

struct FUN_00538ef0 {
    virtual void VirtualMethod();
    ~FUN_00538ef0();
    int m_kPointA;
    int m_kPointB;
    FUN_00538ef0();
};

struct FUN_0056d640 : FUN_00538ef0 {
    B006815c0 m_quantity;
    FUN_0056d640(unsigned int quantity);
};

// @fnv 0x0056d640
FUN_0056d640::FUN_0056d640(unsigned int quantity)
    : FUN_00538ef0(), m_quantity()
{
    m_kPointB = 0;
    reinterpret_cast<FUN_00537e90*>(&m_quantity)->SetQuantity(quantity);
}

struct LandFormBase {
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    virtual ~LandFormBase();
    void ReleaseLand();
};

struct LandChildCell {
    virtual void* GetPersistentCell() = 0;
};

struct LandMember24 {
    int unk00;
    ~LandMember24();
};

struct LandSharedObject {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual ~LandSharedObject();
};

struct LandNiPointer {
    LandNiPointer& operator=(void* p);
};

struct LandBuffer {
    int unk00;
};

extern int g_landRefCount;
extern LandBuffer* g_landBuf0;
extern LandBuffer* g_landBuf1;
extern LandBuffer* g_landBuf2;
extern LandBuffer* g_landBuf3;
extern LandBuffer* g_landBuf4;
extern LandBuffer* g_landBufArray[4];
extern bool g_landBuffersReady;
extern LandNiPointer g_landNiPointer;
extern LandSharedObject* g_landShared0;
extern LandSharedObject* g_landShared1;

struct FUN_00533260 : LandFormBase, LandChildCell {
    int unk1C;
    int unk20;
    LandMember24 unk24;
    virtual void* GetPersistentCell();
    virtual ~FUN_00533260();
    void ClearData();
};

// @fnv 0x00533260
FUN_00533260::~FUN_00533260()
{
    ClearData();
    if (--g_landRefCount == 0) {
        delete g_landBuf0;
        delete g_landBuf1;
        delete g_landBuf2;
        delete g_landBuf3;
        delete g_landBuf4;
        for (int i = 0; i < 4; i++) {
            delete g_landBufArray[i];
        }
        g_landBuffersReady = false;
        g_landNiPointer = 0;
        delete g_landShared0;
        g_landShared0 = 0;
        delete g_landShared1;
        g_landShared1 = 0;
    }
    ReleaseLand();
}

struct LandPoint3 {
    float x;
    float y;
    float z;
    LandPoint3(float fx, float fy, float afDepth);
};

struct LandGeomData {
    LandPoint3* GetNext();
};

struct LandNode {
    LandGeomData* GetAt(int index);
};

struct LandLoadedData {
    LandNode** m_ppLandNodes;
    LandPoint3** m_ppLandPoints;
    int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C;
    int unk60; int unk64; int unk68; int unk6C; int unk70; int unk74; int unk78; int unk7C;
    int unk80; int unk84; int unk88; int unk8C; int unk90; int unk94; int unk98; int unk9C;
    float m_fTrailingValue;
};

struct LandObject : TESObjectLAND {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24;
    LandLoadedData* m_pRenderData;
    bool IsLoaded();
    void FUN_00534240(int quadrant, int index, LandPoint3* vertex);
};

// @fnv 0x00534240
void LandObject::FUN_00534240(int quadrant, int index, LandPoint3* vertex)
{
    if (!IsLoaded()) {
        *vertex = LandPoint3(0.0f, 0.0f, FUN_0053a550());
        return;
    }
    if (m_pRenderData->m_ppLandPoints && m_pRenderData->m_ppLandPoints[quadrant]) {
        *vertex = m_pRenderData->m_ppLandPoints[quadrant][index];
    } else if (m_pRenderData->m_ppLandNodes && m_pRenderData->m_ppLandNodes[quadrant]) {
        LandGeomData* pGeom = m_pRenderData->m_ppLandNodes[quadrant]->GetAt(0);
        *vertex = pGeom->GetNext()[index];
    } else {
        *vertex = LandPoint3(0.0f, 0.0f, FUN_0053a550());
    }
    vertex->z += m_pRenderData->m_fTrailingValue;
}

struct VertPt {
    float x; float y; float z;
    VertPt(float fx, float fy, float afDepth);
};

struct VertCtl {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6c();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7c();
    virtual void v80(); virtual void v84(); virtual void v88();
    virtual bool IsSkinned();
};

struct VertLock : FUN_00534570_shell {
    int unk08;
    VertLock();
};

struct VertGeomData {
    VertCtl* GetNext() const;
    bool LockVerts(int);
    void GetVerts(VertLock* lock);
    void UnlockVerts();
};

struct VertGeom {
    VertPt* GetPoints();
    VertGeomData* GetData();
};

struct VertNode {
    VertGeom* GetChild(int);
};

struct VertTables {
    VertNode** nodes;
    int unk04;
    VertPt** points;
};

struct VertOwner {
    int unk00; int unk04; int unk08; int unk0c; int unk10;
    int unk14; int unk18; int unk1c; int unk20; int unk24;
    VertTables* tables;
    bool IsLoaded();
    void FUN_00534390(unsigned int index, unsigned int vert, VertPt& out);
};

// @fnv 0x00534390
void VertOwner::FUN_00534390(unsigned int index, unsigned int vert, VertPt& out)
{
    if (!IsLoaded()) {
        out = VertPt(0.0f, 0.0f, 1.0f);
        return;
    }
    bool found = false;
    if (tables->points && tables->points[index]) {
        out = tables->points[index][vert];
        found = true;
    } else if (tables->nodes && tables->nodes[index]) {
        VertGeom* geom = tables->nodes[index]->GetChild(0);
        if (geom->GetPoints()) {
            out = geom->GetPoints()[vert];
            found = true;
        } else {
            VertGeomData* data = geom->GetData();
            VertLock lock_;
            VertCtl* aCtl = data->GetNext();
            if (aCtl && aCtl->IsSkinned() && data->LockVerts(1)) {
                data->GetVerts(&lock_);
                lock_.FUN_00534570(vert, (NiPoint3&)out);
                data->UnlockVerts();
                found = true;
            }
        }
    }
    if (!found)
        out = VertPt(0.0f, 0.0f, 1.0f);
}

struct Color_5345c0 { float r, g, b, a; };
extern Color_5345c0 DAT_011a9be0;
struct Buffer_5345c0 {
    void* data;
    unsigned int stride;
    unsigned int unk08;
    void FUN_00534550();
    void FUN_00534780(unsigned int, Color_5345c0&);
};
struct Format_5345c0 {
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
    virtual bool HasColor();
};
struct Data_5345c0 {
    Format_5345c0* FUN_004a8a90();
    bool FUN_00a67360(int);
    void FUN_00a67660(Buffer_5345c0*);
    void FUN_00a673d0();
};
struct Geometry_5345c0 {
    unsigned int FUN_004a8030();
    Color_5345c0* GetNextProc();
    Data_5345c0* FUN_005495f0();
};
struct Node_5345c0 { Geometry_5345c0* FUN_0043b4a0(unsigned int); };
struct Store_5345c0 {
    Node_5345c0** nodes;
    int unk04;
    int unk08;
    Color_5345c0** colors;
};
struct FUN_005345c0_shell {
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
    Store_5345c0* store;
    bool FUN_0045cb90();
    void FUN_005345c0(unsigned int group, unsigned int index, Color_5345c0& out);
};
// @fnv 0x005345c0
void FUN_005345c0_shell::FUN_005345c0(unsigned int group, unsigned int index, Color_5345c0& out) {
    if (!FUN_0045cb90()) { out = DAT_011a9be0; return; }
    bool found = false;
    if (store->colors && store->colors[group]) {
        out = store->colors[group][index];
        found = true;
    } else if (store->nodes && store->nodes[group]) {
        Geometry_5345c0* geometry = store->nodes[group]->FUN_0043b4a0(0);
        if (geometry->FUN_004a8030()) {
            out = geometry->GetNextProc()[index];
            found = true;
        } else {
            Data_5345c0* data = geometry->FUN_005495f0();
            Buffer_5345c0 format;
            format.FUN_00534550();
            Format_5345c0* buffer = data->FUN_004a8a90();
            if (buffer && buffer->HasColor() && data->FUN_00a67360(1)) {
                data->FUN_00a67660(&format);
                format.FUN_00534780(index, out);
                data->FUN_00a673d0();
                found = true;
            }
        }
    }
    if (!found) out = DAT_011a9be0;
}

struct RgbaColor {
    float r;
    float g;
    float b;
    float a;
};

struct FUN_00534780_Class {
    int m_00;
    int m_04;
    unsigned char m_08;
    void __thiscall FUN_004534f0(int index);
    void FUN_00534780(int index, RgbaColor* out);
};

// @fnv 0x00534780
void FUN_00534780_Class::FUN_00534780(int index, RgbaColor* out)
{
    FUN_004534f0(index);
    unsigned int* entry7 = (unsigned int*)(m_00 + index * m_04);
    if (m_08) {
        unsigned int* pX = entry7;
        unsigned char red = (unsigned char)((*pX >> 16) & 0xff);
        unsigned char aGreen = (unsigned char)((*pX >> 8) & 0xff);
        unsigned char blue = (unsigned char)(*pX & 0xff);
        unsigned char alpha2 = (unsigned char)((*pX >> 24) & 0xff);
        out->r = (int)red / 255.0;
        out->g = (int)aGreen / 255.0;
        out->b = (int)blue / 255.0;
        out->a = (int)alpha2 / 255.0;
    } else {
        RgbaColor* src = (RgbaColor*)entry7;
        *out = *src;
    }
}

extern int FNV_RTTI_TESForm;
extern int FNV_RTTI_TESObjectLAND;
extern "C" void* __cdecl FNV_DynamicCast(void*, int, const void*, const void*, int);
void* __cdecl memcpy(void*, const void*, unsigned int);

struct LandCopyData {
    void* nodes;
    NiPoint3** vertices;
    NiPoint3** normals;
    Elem16** colors;
    unsigned char** textureIndices;
    int unk14;
    int cellX;
    int cellY;
    int baseTextures[4];
    int* textureLayers[4];
    void** weights[4];
};
struct LandCopy : TESPackage {
    void* cell;
    int unk24;
    LandCopyData* data;
    void FUN_00535b90(int);
    void* FUN_007af430();
    void FUN_00539500(LandCopy*);
    void FUN_00536d80();
    void FUN_005394c0(bool);
    void FUN_005348c0(TESForm* form);
};

// @fnv 0x005348c0
void LandCopy::FUN_005348c0(TESForm* form) {
    LandCopy* source = static_cast<LandCopy*>(FNV_DynamicCast(form, 0, &FNV_RTTI_TESForm, &FNV_RTTI_TESObjectLAND, 0));
    if (source) {
        bool loaded = source->FUN_005394a0();
        if (!loaded)
            source->FUN_00535b90(0);
        cell = source->FUN_007af430();
        FUN_00539500(source);
        for (int i = 0; i < 4; ++i) {
            memcpy(data->vertices[i], source->data->vertices[i], 0xd8c);
            memcpy(data->normals[i], source->data->normals[i], 0xd8c);
            memcpy(data->colors[i], source->data->colors[i], 0x1210);
            memcpy(data->textureIndices[i], source->data->textureIndices[i], 0x121);
            memcpy(data->weights[i][0], source->data->weights[i][0], 0x2420);
            memcpy(data->textureLayers[i], source->data->textureLayers[i], 0x18);
            data->baseTextures[i] = source->data->baseTextures[i];
        }
        memcpy(&flags, &source->flags, 4);
        memcpy(&data->cellX, &source->data->cellX, 8);
        if (!loaded)
            source->FUN_00536d80();
        FUN_005394c0(true);
    }
}

struct CleanupMap {
    int unk00, unk04, unk08, unk0c;
    unsigned int Count();
    void* First();
    void Next(void*&, unsigned int&, int**&);
    void Clear();
};
struct RefCleanup { void removeReference(); };
struct CleanupData {
    int unk00;
    int** vertices;
    int** normals;
    int** colors;
    int** extra;
    int unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    int* choices[4];
    int** weights[4];
    RefCleanup* reference;
    CleanupMap maps[4];
    ~CleanupData();
};
struct CleanupOwner {
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
    CleanupData* data;
    void SetLoaded(bool);
    void Finish();
    bool FUN_00536d80();
};
// @fnv 0x00536d80
bool CleanupOwner::FUN_00536d80() {
    SetLoaded(false);
    Finish();
    if (data) {
        int** value = 0;
        void* position;
        unsigned int key;
        int quad;
        int entry;
        for (quad = 0; quad < 4; quad++) {
            if (data->weights[quad]) {
                delete *data->weights[quad];
                delete data->weights[quad];
                data->weights[quad] = 0;
            }
            if (data->choices[quad]) {
                delete data->choices[quad];
                data->choices[quad] = 0;
            }
            if (data->vertices) {
                delete data->vertices[quad];
                data->vertices[quad] = 0;
            }
            if (data->normals) {
                delete data->normals[quad];
                data->normals[quad] = 0;
            }
            if (data->colors) {
                delete data->colors[quad];
                data->colors[quad] = 0;
            }
            if (data->extra) {
                delete data->extra[quad];
                data->extra[quad] = 0;
            }
            if (data->maps[quad].Count() > 0) {
                position = data->maps[quad].First();
                while (position) {
                    data->maps[quad].Next(position, key, value);
                    if (value) {
                        for (entry = 0; entry < 16; entry++) {
                            if (value[entry]) {
                                *value[entry] = 0;
                                delete value[entry];
                            }
                        }
                        delete value;
                    }
                }
            }
            data->maps[quad].Clear();
        }
        delete data->extra;
        delete data->vertices;
        delete data->colors;
        delete data->normals;
        if (data->reference) {
            data->reference->removeReference();
            data->reference = 0;
        }
    }
    delete data;
    data = 0;
    return true;
}

void* __cdecl operator new(unsigned int);
void __cdecl FUN_00403d30(void*, int, unsigned int);
struct Point { float x,y,z; Point(float,float,float); };
extern NiPoint3 DAT_011f426c;
struct Range {float x,y;};
extern float DAT_01016970, DAT_01015f5c, DAT_010236e0;
struct UpdateData {float time; bool a,b; int c; UpdateData(float,bool,bool);};
struct Shape;
struct GeomData {void FUN_00a67090(int); void FUN_00a67050(int); void FUN_004410f0(bool); void SetByteAtOffset38(int);};
struct Bound {void Calculate(unsigned short,void*);};
struct Property {int FUN_008d8520(); void* GetStringAtOffset();};
struct Model {struct Scene* FUN_0043b230();};
struct Scene {
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
virtual void SetPosition(const NiPoint3&);
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
virtual void Attach(int,Shape*);
bool FUN_00456610(); void FUN_00450f90(bool); void AttachProperty(void*);
Model* FUN_006629f0(); void FUN_00439680(const Point&);
void Update(UpdateData&); void FUN_00a5a040();
};
struct Shape {unsigned short FUN_00456650(); void* FUN_0049ec60(); Bound* GetSourceFilesFromForm(); GeomData* FUN_005495f0(); Property* FUN_004030b0();};
struct PropPointer {void* FUN_00559450();}; extern PropPointer g_011ca000;
struct Renderer {virtual void v00();
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
virtual void Render(Shape*,int,int,void*);
void FUN_00e74120();}; Renderer* FUN_0043c4b0();
struct Cell {Scene* FUN_00545cb0();};
struct Mopp {void Clear(); void FUN_00621f60(Shape**,int,float);};
Mopp* __fastcall GetCellMopp(Cell*);
struct Scratch {int a,b,c,d; Scratch();};
struct Other {bool FUN_00537b50(); bool FUN_00544590(int);};
struct Data {Scene** nodes; int unk04;
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
int unk9c; float scale;};
struct Land {int unk00;
int unk04;
int unk08;
int unk0c;
int unk10;
int unk14;
int unk18;
int unk1c; Cell* cell; int unk24; Data* data;
Scene* FUN_00535af0(int); Shape* FUN_005371b0(unsigned char);
Range* FUN_0053f390(Range*,int); float FUN_00534050(); double FUN_00534080();
void FUN_0053bc10(); void FUN_0053aeb0(); void FUN_00539960();
Other* FUN_007af430(); bool FUN_00534140(); void FUN_005374f0();};
// @fnv 0x005374f0
void Land::FUN_005374f0() {
if (!cell || !cell->FUN_00545cb0()) return;
if (!data->nodes) {
 data->nodes = new Scene*[4];
 bool savedA[4]; FUN_00403d30(savedA,0,4);
 Shape* shapesB[4]; FUN_00403d30(shapesB,0,16);
 NiPoint2 total(DAT_01016970,DAT_01015f5c);
 for(int quad=0;quad<4;quad++) {
  data->nodes[quad]=FUN_00535af0(quad);
  if(data->nodes[quad]) {
   savedA[quad]=data->nodes[quad]->FUN_00456610();
   data->nodes[quad]->FUN_00450f90(true);
   data->nodes[quad]->AttachProperty(g_011ca000.FUN_00559450());
   Shape* shape=FUN_005371b0((unsigned char)quad);
   shapesB[quad]=shape;
   data->nodes[quad]->Attach(0,shape);
   unsigned short countB3=shape->FUN_00456650();
   void* vertices9=shape->FUN_0049ec60();
   shape->GetSourceFilesFromForm()->Calculate(countB3,vertices9);
   shape->FUN_005495f0()->FUN_00a67090(15);
   Scene* node6=data->nodes[quad];
   Scene* childIndex8=node6->FUN_006629f0()->FUN_0043b230();
   Range range4; FUN_0053f390(&range4,quad);
   childIndex8->FUN_00439680(Point(DAT_010236e0,DAT_010236e0,(range4.y-range4.x)/2.0));
   NiPoint3 pos23=DAT_011f426c;
   pos23.x=FUN_00534050()+1024.0+(float)((quad%2)<<7<<4);
   pos23.y=FUN_00534080()+1024.0+(float)((quad/2)<<7<<4);
   pos23.z=(range4.x+range4.y)/2.0;
   childIndex8->SetPosition(pos23);
   if(total.x>range4.x) total.x=range4.x;
   if(total.y<range4.y) total.y=range4.y;
  }
 }
 Mopp* mopp2=GetCellMopp(cell);
 mopp2->Clear();
 Scratch scratch;
 scratch.c=data->unk50;
 mopp2->FUN_00621f60(shapesB,4,data->scale);
 FUN_0053bc10(); FUN_0053aeb0(); FUN_00539960();
 for(int index=0;index<4;index++) {
  if(shapesB[index]) {
   GeomData* geometryB=shapesB[index]->FUN_005495f0();
   geometryB->FUN_00a67050(0x4000); geometryB->FUN_004410f0(true);
   int flags5=17; flags5|=6; geometryB->SetByteAtOffset38(flags5);
   Property* property3=shapesB[index]->FUN_004030b0();
   Property* shader6=property3==0 ? 0 : ((property3->FUN_008d8520()>=1 && property3->FUN_008d8520()<=5) ? property3 : 0);
   if(shader6) {
    Renderer* renderer=FUN_0043c4b0();
    renderer->Render(shapesB[index],0,0,shader6->GetStringAtOffset());
    renderer->FUN_00e74120();
   }
  }
  if(data->nodes[index]) {
   data->nodes[index]->FUN_00450f90(savedA[index]);
   UpdateData update(0.0f,false,false);
   data->nodes[index]->Update(update);
   data->nodes[index]->FUN_00a5a040();
  }
 }
}
if(data->nodes && FUN_007af430()) {
 bool hidden=false;
 hidden=FUN_00534140() && !FUN_007af430()->FUN_00537b50();
 for(int index2=0;index2<4;index2++)
  data->nodes[index2]->FUN_00450f90(hidden || FUN_007af430()->FUN_00544590(index2));
}
}

struct SceneObject {
    virtual void Unknown00();
    virtual void Unknown01();
    virtual void Unknown02();
    virtual void Unknown03();
    virtual void Unknown04();
    virtual void Unknown05();
    virtual void Unknown06();
    virtual void Unknown07();
    virtual void Unknown08();
    virtual void Unknown09();
    virtual void Unknown10();
    virtual void Unknown11();
    virtual void Unknown12();
    virtual void Unknown13();
    virtual void Unknown14();
    virtual void Unknown15();
    virtual void Unknown16();
    virtual void Unknown17();
    virtual void Unknown18();
    virtual void Unknown19();
    virtual void Unknown20();
    virtual void Unknown21();
    virtual void Unknown22();
    virtual void Unknown23();
    virtual void Unknown24();
    virtual void Unknown25();
    virtual void Unknown26();
    virtual void Unknown27();
    virtual void Unknown28();
    virtual void Unknown29();
    virtual void Unknown30();
    virtual void Unknown31();
    virtual void Unknown32();
    virtual void Unknown33();
    virtual void Unknown34();
    virtual void Unknown35();
    virtual void Unknown36();
    virtual void Unknown37();
    virtual void Unknown38();
    virtual void Unknown39();
    virtual void Unknown40();
    virtual void Unknown41();
    virtual void Unknown42();
    virtual void Unknown43();
    virtual void Unknown44();
    virtual void Unknown45();
    virtual void Unknown46();
    virtual void Unknown47();
    virtual void Unknown48();
    virtual void Unknown49();
    virtual void Unknown50();
    virtual void Unknown51();
    virtual void Unknown52();
    virtual void Unknown53();
    virtual void Unknown54();
    virtual void Unknown55();
    virtual void Unknown56();
    virtual void Unknown57();
    virtual void InsertChild(SceneObject* child);
    virtual void Unknown59();
    virtual void SetState(int state);
    SceneObject* FUN_009611e0();
};
struct ScenePointer {
    SceneObject* value;
    SceneObject* FUN_00559450();
    bool FUN_0052aa80(int value) const;
    void FUN_0066b0d0(SceneObject* value);
};
struct QueuePointer {
    void* value;
    void FUN_006f74f0(void* value);
};
struct SceneController {
    bool FUN_005380d0(SceneObject* object);
};
struct SceneSource {
    SceneController* FUN_004543c0();
};
struct BoneTransformData {
    SceneObject** objects;
    int* states;
    void** buffers;
    int* counts;
    int unknown10;
    ScenePointer node;
    int unknown18;
    int unknown1c;
    int unknown20;
    int unknown24;
    int unknown28;
    int unknown2c;
    int unknown30;
    int unknown34;
    int unknown38;
    int unknown3c;
    int unknown40;
    int unknown44;
    int unknown48;
    int unknown4c;
    int unknown50;
    int unknown54;
    int unknown58;
    int unknown5c;
    int unknown60;
    int unknown64;
    int unknown68;
    int unknown6c;
    int unknown70;
    int unknown74;
    int unknown78;
    int unknown7c;
    int unknown80;
    int unknown84;
    int unknown88;
    int unknown8c;
    int unknown90;
    ScenePointer extraNode;
};
struct SceneCleanup {
    int unknown00;
    int unknown04;
    int unknown08;
    int unknown0c;
    int unknown10;
    int unknown14;
    int unknown18;
    int unknown1c;
    SceneSource* source;
    QueuePointer queued;
    BoneTransformData* data;
    void FUN_00537eb0();
};
struct ShadowSceneNode {
    void FUN_00b5b1c0(SceneObject* object);
};
ShadowSceneNode* __cdecl FUN_00450b80(int index);

// @fnv 0x00537eb0
void SceneCleanup::FUN_00537eb0()
{
    SceneController* controller;
    queued.FUN_006f74f0(0);
    if (!data)
        return;
    {
    int index;
    SceneObject* parent;
    if (data->objects) {
        controller = source ? source->FUN_004543c0() : 0;
        if (controller && data->extraNode.FUN_0052aa80(0))
            controller->FUN_005380d0(data->extraNode.FUN_00559450());
        data->extraNode.FUN_0066b0d0(0);
        for (index = 0; index < 4; ++index) {
            if (data->objects[index]) {
                data->states[index] = 0;
                data->counts[index] = 0;
                void* buffer = data->buffers[index];
                Deallocate(buffer);
                data->buffers[index] = 0;
                FUN_00450b80(0)->FUN_00b5b1c0(data->objects[index]);
                data->objects[index]->SetState(0);
            }
            data->objects[index] = 0;
        }
        {
        SceneObject** objects = data->objects;
        Deallocate(objects);
        }
        data->objects = 0;
    }
    if (data->node.FUN_00559450()) {
        parent = data->node.FUN_00559450()->FUN_009611e0();
        if (parent)
            parent->InsertChild(data->node.FUN_00559450());
        data->node.FUN_0066b0d0(0);
    }
}
}

void* __cdecl FUN_0056d280(unsigned int size);

void* __cdecl FUN_00401460(void* destination, const void* source, unsigned int size);



struct Buffer538c00

{

    unsigned int m00;

    unsigned int m04;

    void __thiscall FUN_00540750(unsigned int size);

    void* __thiscall FUN_00559450();

};



struct Output538c00

{

    virtual ~Output538c00();

    unsigned int m04;

    unsigned int m08;

    unsigned int m0c;

    unsigned int m10;

    unsigned int m14;

    unsigned int m18;

    unsigned int m1c;

    Buffer538c00 buffer;

    unsigned int m28;

    unsigned int m2c;

    Output538c00();
    static void* operator new(unsigned int bytes) { return FUN_0056d280(bytes); } static void operator delete(void*);

};



struct FUN_00538c00_Class

{

    char __thiscall FUN_00538c00(const void* source, unsigned int size, Output538c00** result);

};



// @fnv 0x00538c00
char __thiscall FUN_00538c00_Class::FUN_00538c00(
    const void* source, unsigned int size, Output538c00** result)
{
    unsigned char success = 0;
    if (source && size && result)
    {
        Output538c00* object = new Output538c00;
        *result = object;

        const char* remainingSize = static_cast<const char*>(source);
        unsigned int readPosition = size;
        unsigned int fixedHeaderSize = 0x10;
        if (readPosition > fixedHeaderSize)
        {
            FUN_00401460(&object->m10, remainingSize, fixedHeaderSize);
            readPosition = readPosition - fixedHeaderSize;
            remainingSize = remainingSize + fixedHeaderSize;
            if (readPosition > 0)
            {
                object->buffer.FUN_00540750(readPosition);
                void* bufferData = object->buffer.FUN_00559450();
                FUN_00401460(bufferData, remainingSize, readPosition);
                success = 1;
            }
        }
        if (!success)
        {
            delete object;
            *result = 0;
        }
    }
    return success;
}

struct Mesh53;
struct Buffer53 { void ComputeBoundingSphere(); };
struct Texture53Data { void* FUN_00592cf0(); };
struct Texture53 { Texture53Data* FUN_009611e0(); unsigned char FUN_00541590(); };
struct GeoData53 { void* FUN_0059bb30(); void FUN_00a67090(int); void FUN_00a66a60(int); };
struct NiTimeController {
 int FUN_00441110();
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
 virtual void slot25();
 virtual void slot26();
 virtual void slot27();
 virtual void slot28();
 virtual void slot29();
 virtual void slot30();
 virtual void slot31();
 virtual void slot32();
 virtual void slot33();
 virtual void slot34();
 virtual void slot35();
 virtual void slot36();
 virtual void slot37();
 virtual void slot38();
 virtual void SetGeometry(Mesh53*);
 void FUN_00b68660(int, void*);
 void FUN_00b66640(char,char,char,char,char,char,char,int,int,int);
 void FUN_00baa000();
};
struct Mesh53 {
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual Mesh53* AsMesh();
 unsigned short FUN_00456650();
 void* FUN_0049ec60();
 Buffer53* GetSourceFilesFromForm(unsigned short,void*);
 GeoData53* FUN_005495f0();
 NiTimeController* FUN_00a59d30(int);
};
struct Update53 { float time; bool update; bool flags; int unk08; void FUN_0043d410(float,bool,bool); };
struct Node53 { Mesh53* FUN_0045bc00(int); void FUN_00a59c60(Update53&); void FUN_00a5a040(); };
struct Config53 {
 int enabled; int unk04; void** sources; int unk0c; int unk10; int unk14; int unk18; int unk1c;
 Texture53* primary[4]; Texture53** textures[4];
};
struct TES53 { char GetUnk60Byte(); };
extern TES53* g_TES;
void* __cdecl memcpy(void*,const void*,unsigned int);
struct Worker53 {
 int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24;
 Config53* config;
 Node53* FUN_00535af0(int);
 void FUN_0053fa40(char); void FUN_00539500(int); void FUN_005374f0();
 void FUN_0053a090(bool update, int unused);
};
// @fnv 0x0053a090
void Worker53::FUN_0053a090(bool update, int unused) {
 if (config->enabled) {
 for (int i=0; i<4; ++i) {
 Node53* node=FUN_00535af0(i);
 if (node) {
 if (update) {
 Mesh53* mesh=node->FUN_0045bc00(0);
 Mesh53* object=mesh ? mesh->AsMesh() : 0;
 if(object) {
 unsigned short prop=object->FUN_00456650();
 void* shader=object->FUN_0049ec60();
 object->GetSourceFilesFromForm(prop,shader)->ComputeBoundingSphere();
 object->FUN_005495f0()->FUN_00a67090(15);
 NiTimeController* count=object->FUN_00a59d30(3);
 NiTimeController* vertices=(count == 0 ? false : (count->FUN_00441110()>=8 && count->FUN_00441110()<=12)) ? count : 0;
 if(vertices) {
 void* dest=object->FUN_005495f0()->FUN_0059bb30();
 memcpy(dest,config->sources[i],0xd8c);
 object->FUN_005495f0()->FUN_00a66a60(0);
 vertices->SetGeometry(object);
 Texture53* texture=config->primary[i];
 if(texture && texture->FUN_009611e0()) vertices->FUN_00b68660(0,texture->FUN_009611e0()->FUN_00592cf0());
 else vertices->FUN_00b68660(0,((Texture53*)FUN_00535ae0())->FUN_009611e0()->FUN_00592cf0());
 for(int j=1;j<7;++j) {
 texture=config->textures[i][j-1];
 if(texture && texture->FUN_009611e0()) vertices->FUN_00b68660(j,texture->FUN_009611e0()->FUN_00592cf0());
 else vertices->FUN_00b68660(j,0);
 }
 vertices->FUN_00b66640(config->primary[i]?config->primary[i]->FUN_00541590():0,
 config->textures[i][0]?config->textures[i][0]->FUN_00541590():0,
 config->textures[i][1]?config->textures[i][1]->FUN_00541590():0,
 config->textures[i][2]?config->textures[i][2]->FUN_00541590():0,
 config->textures[i][3]?config->textures[i][3]->FUN_00541590():0,
 config->textures[i][4]?config->textures[i][4]->FUN_00541590():0,
 config->textures[i][5]?config->textures[i][5]->FUN_00541590():0,0,0,0);
 vertices->FUN_00baa000();
 }
 }
 }
 Update53 data; data.FUN_0043d410(0.0f,false,false);
 node->FUN_00a59c60(data);
 if(update) node->FUN_00a5a040();
 }
 }
 if(update) FUN_0053fa40(g_TES->GetUnk60Byte());
 } else { FUN_00539500(0); FUN_005374f0(); }
}

void* __cdecl FormHeap_Allocate(unsigned int size);
void __cdecl FormHeap_Free(void* memory);
struct LayerOwner53a940 : Owner53ace0 {
    void FUN_0053abb0(unsigned char quadrant, unsigned short layer);
    void FUN_0053a940();
};

// @fnv 0x0053a940
void LayerOwner53a940::FUN_0053a940()
{
    if (!tables)
        return;
    for (int quadrant = 0; quadrant < 4; quadrant++) {
        for (unsigned int layer = 0; layer < 6; layer++) {
            int entry = tables->choices[quadrant][layer];
            if (entry) {
                float average = FUN_0053ae30((unsigned char)quadrant, (unsigned short)layer);
                average /= 289.0;
                if (average < 0.0010000000474974513)
                    tables->choices[quadrant][layer] = 0;
            }
        }
        unsigned int count = 6;
        for (unsigned int slot = 0; slot < count; slot++) {
            while (!tables->choices[quadrant][slot] && slot < count) {
                FUN_0053abb0((unsigned char)quadrant, (unsigned short)slot);
                count--;
            }
        }
        float* result = (float*)FormHeap_Allocate((count + 1) * sizeof(float));
        FUN_00403d30(result, 0, (count + 1) * sizeof(float));
        for (int vertex = 0; vertex < 289; vertex++) {
            float sum = 0.0f;
            for (unsigned int index = 0; index < count; index++) {
                float weight = FUN_0053a830((unsigned char)quadrant, (unsigned short)vertex, (unsigned short)index);
                result[index] += weight;
                sum += weight;
            }
            if (sum < 1.0)
                result[count] += 1.0f - sum;
        }
        int indexVal = -1;
        float maximum = result[count];
        for (unsigned int candidate = 0; candidate < count; candidate++) {
            if (result[candidate] > maximum) {
                maximum = result[candidate];
                indexVal = candidate;
            }
        }
        if (indexVal != -1)
            FUN_0053ace0((unsigned char)quadrant, (unsigned short)indexVal);
        FormHeap_Free(result);
        result = 0;
    }
}

struct ShiftTableData {
    int unk00[12];
    int* m_apiEntries[4];          // +0x30, each int[6]
    float** m_appfRows[4];         // +0x40, each float*[0x121] of float[6]
};

class ShiftTableOwner {
public:
    int unk00[10];
    ShiftTableData* m_pUserData;      // +0x28

    void FUN_0053abb0(unsigned char ucSlot, unsigned short usIndex);
};

// @fnv 0x0053abb0
void ShiftTableOwner::FUN_0053abb0(unsigned char ucSlot, unsigned short usIndex)
{
    if (ucSlot < 4 && usIndex < 6 && m_pUserData) {
        int i = usIndex;
        while (i < 5) {
            m_pUserData->m_apiEntries[ucSlot][i] = m_pUserData->m_apiEntries[ucSlot][i + 1];
            i++;
        }
        m_pUserData->m_apiEntries[ucSlot][5] = 0;
        if (m_pUserData->m_appfRows[ucSlot]) {
            for (int j = 0; j < 0x121; j++) {
                int k = usIndex;
                while (k < 5) {
                    m_pUserData->m_appfRows[ucSlot][j][k] = m_pUserData->m_appfRows[ucSlot][j][k + 1];
                    k++;
                }
                m_pUserData->m_appfRows[ucSlot][j][5] = 0.0f;
            }
        }
    }
}

struct xPoint3 {
    float x, y, z;
    xPoint3();
    xPoint3(float qpqRa, float qsSDDgz, float fZ);
    xPoint3 operator+(const xPoint3& kOther) const;
};

struct xPoint2 {
    float x, y;
    xPoint2(float qpqRa, float qsSDDgz);
    xPoint2 operator-(const xPoint2& kOther) const;
    float Length() const;
};

struct xCoordData {
    float fX;
    float fY;
    float fCellX;
    float fCellY;
    int m_iGridPositionX;
    int m_iGridCoordinateY;
    int iCell;
    float fQuadX;
    float fQuadY;
    int iQuadX;
    int iQuadY;
    int iQuad;
    xPoint3 kPos;
    int iVertex;
    int aiVerts[3];
    bool bFlip;
    bool bUpper;
};

struct xLandData {
    int m_iWordAt00;
    int m_iWordAt04;
};

int __cdecl xTruncate(float f);

struct xLand {
    char _pad0[0x28];
    xLandData* m_pData;
    int GetCellX();
    int GetCellY();
    double GetBaseX();
    float GetBaseY();
    void GetVertex(int iCell, int iVertex, xPoint3& kOut);
    bool FUN_0053b550(xCoordData& kData, const xPoint3& kPos, bool bRecurse);
};

// @fnv 0x0053b550
bool xLand::FUN_0053b550(xCoordData& kData, const xPoint3& kPos, bool bRecurse)
{
    float qpqRa = GetCellX() * 4096.0;
    float qsSDDgz = GetCellY() * 4096.0;
    if (!m_pData || (!m_pData->m_iWordAt04 && !m_pData->m_iWordAt00))
        return false;
    if (kPos.x < qpqRa || (float)(qpqRa + 4096.0) < kPos.x || kPos.y < qsSDDgz || (float)(qsSDDgz + 4096.0) < kPos.y)
        return false;
    kData.fX = kPos.x - qpqRa;
    kData.fY = kPos.y - qsSDDgz;
    kData.m_iGridPositionX = (int)(kData.fX / 2048.0);
    if ((int)kData.fX % 2048 == 0 && (int)kData.fX)
        kData.m_iGridPositionX--;
    kData.m_iGridCoordinateY = (int)(kData.fY / 2048.0);
    if ((int)kData.fY % 2048 == 0 && (int)kData.fY)
        kData.m_iGridCoordinateY--;
    kData.iCell = kData.m_iGridCoordinateY * 2 + kData.m_iGridPositionX;
    float qSVM = kData.m_iGridPositionX * 16 * 128 + qpqRa;
    float qrEZrs = kData.m_iGridCoordinateY * 16 * 128 + qsSDDgz;
    kData.fCellX = kPos.x - qSVM;
    kData.fCellY = kPos.y - qrEZrs;
    xPoint3 qpTd;
    qpTd = xPoint3(GetBaseY() + 2048.0, GetBaseX() + 2048.0, 0.0f);
    kData.iQuadX = (int)(kData.fCellX / 128.0);
    if ((int)kData.fCellX % 128 == 0 && (int)kData.fCellX)
        kData.iQuadX--;
    kData.iQuadY = (int)(kData.fCellY / 128.0);
    if ((int)kData.fCellY % 128 == 0 && (int)kData.fCellY)
        kData.iQuadY--;
    float qdqWL = kData.iQuadX * 128 + qSVM;
    float qvyWyw = kData.iQuadY * 128 + qrEZrs;
    kData.fQuadX = kPos.x - qdqWL;
    kData.fQuadY = kPos.y - qvyWyw;
    kData.iQuad = kData.iCell;
    if ((kData.iQuadX + kData.iQuadY) % 2 == 0) {
        kData.bFlip = false;
        kData.aiVerts[1] = kData.iQuadY * 17 + kData.iQuadX;
        kData.aiVerts[2] = (kData.iQuadY + 1) * 17 + kData.iQuadX + 1;
        if (kData.fQuadX > kData.fQuadY) {
            kData.aiVerts[0] = kData.iQuadY * 17 + kData.iQuadX + 1;
            kData.bUpper = false;
        } else {
            kData.aiVerts[0] = (kData.iQuadY + 1) * 17 + kData.iQuadX;
            kData.bUpper = true;
        }
    } else {
        kData.bFlip = true;
        kData.aiVerts[1] = kData.iQuadY * 17 + kData.iQuadX + 1;
        kData.aiVerts[2] = (kData.iQuadY + 1) * 17 + kData.iQuadX;
        if (kData.fQuadX + kData.fQuadY > 128.0) {
            kData.aiVerts[0] = (kData.iQuadY + 1) * 17 + kData.iQuadX + 1;
            kData.bUpper = true;
        } else {
            kData.aiVerts[0] = kData.iQuadY * 17 + kData.iQuadX;
            kData.bUpper = false;
        }
    }
    if ((int)kPos.x % 128 == 0 && (int)kPos.y % 128 == 0) {
        kData.iVertex = xTruncate(((int)kData.fCellY / 128) * 17 + (int)kData.fCellX / 128);
    } else {
        float qArxcFu = 0.0f;
        int qAhbO = 0;
        xPoint2 qxQHW(kPos.x, kPos.y);
        for (int qJDuOZ = 0; qJDuOZ < 3; qJDuOZ++) {
            xPoint3 qpia;
            GetVertex(kData.iCell, kData.aiVerts[qJDuOZ], qpia);
            xPoint2 qZWI(qpTd.x + qpia.x, qpTd.y + qpia.y);
            xPoint2 qQGWBE = qZWI - qxQHW;
            float qkJsUdT = qQGWBE.Length();
            if (qJDuOZ == 0 || qkJsUdT < qArxcFu) {
                qArxcFu = qkJsUdT;
                qAhbO = qJDuOZ;
            }
        }
        kData.iVertex = kData.aiVerts[qAhbO];
    }
    xPoint3 qfTOqo;
    GetVertex(kData.iCell, kData.iVertex, qfTOqo);
    kData.kPos = qpTd + qfTOqo;
    if (bRecurse) {
        bool bResult = FUN_0053b550(kData, kData.kPos, false);
        return bResult;
    }
    else
        return true;
}

struct Grass;
struct GrassNode { Grass** GetItem(); GrassNode* Next(); };
struct TextureGrass { GrassNode* GetGrassList(); };
struct Grass {
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
 virtual unsigned char v180();
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
 virtual float v1b0();
 virtual void v1b4();
 virtual float v1b8();
 virtual void v1bc();
 virtual float v1c0();
 virtual void v1c4();
 virtual float v1c8();
 virtual void v1cc();
 virtual unsigned char v1d0();
 virtual void v1d4();
 virtual unsigned char v1d8();
 virtual void v1dc();
 virtual unsigned char v1e0();
 const char* GetModelFilePath(); unsigned int GetId();
};
struct Sample {
 const char* model; unsigned int id; float f08,f0c,f10,f14,f18;
 unsigned char b1c,b1d,b1e,b1f;
 float weights[9];
 Sample();
};
struct SampleMap { int u00,u04,u08,u0c; void SetAt(int,Sample**); };
struct TerrainData {
 int u00,u04,u08,u0c,u10,u14,u18,u1c;
 TextureGrass* base[4]; TextureGrass** layers[4]; float** weights[4];
 int u50; SampleMap maps[4];
};
struct SampleSetting { float* Float(); }; extern SampleSetting g_011c9f38;
struct IntSetting { int* Int(); }; extern IntSetting g_011c9f74,g_011c9fb8;
extern unsigned long DAT_011c9f6c;
struct TerrainOwner {
 int u00,u04,u08,u0c,u10,u14,u18,u1c,u20,u24; TerrainData* data;
 float FUN_0053a7a0(unsigned char,unsigned short);
 bool FUN_0053bc10();
};
// @fnv 0x0053bc10
bool TerrainOwner::FUN_0053bc10() {
 if (!data) return false;
 float threshold2=*g_011c9f38.Float();
 threshold2=threshold2 < 0.0 ? 0.0 : threshold2;
 threshold2=threshold2 > 1.0 ? 0.9 : threshold2;
 GrassNode* nodeBTmp=0; Grass* _activeProcess=0; float density5=0.0f; int count1=0; int _actors=0;
 int limitVal=*g_011c9f74.Int(); int indexValue4=0; int capacity8=16; float sumHigh_2=0.0f; Sample** samples4;
 DAT_011c9f6c=*g_011c9fb8.Int();
 if (DAT_011c9f6c!=1 && DAT_011c9f6c!=2 && DAT_011c9f6c!=4 && DAT_011c9f6c!=8) DAT_011c9f6c=2;
 for (int quad=0;quad<4;quad++) {
 count1=0;
 for (int x=DAT_011c9f6c;x<16;x+=2*DAT_011c9f6c) {
 for (int y=DAT_011c9f6c;y<16;y+=2*DAT_011c9f6c) {
 samples4=new Sample*[capacity8];
 FUN_00403d30(samples4,0,capacity8*4);
 indexValue4=y*17+x;
 if(data->base[quad]) {
 nodeBTmp=data->base[quad]->GetGrassList(); _actors=0;
 while(nodeBTmp && count1<capacity8 && _actors<=limitVal) {
 _activeProcess=*nodeBTmp->GetItem();
 if(_activeProcess) {
 _actors++;
 samples4[count1]=new Sample;
 FUN_00403d30(samples4[count1],0,0x44);
 samples4[count1]->model=_activeProcess->GetModelFilePath();
 samples4[count1]->id=_activeProcess->GetId();
 samples4[count1]->f14=FUN_0053ca40();
 samples4[count1]->f18=_activeProcess->v1c8();
 samples4[count1]->f10=_activeProcess->v1c0();
 samples4[count1]->f08=_activeProcess->v1b0();
 samples4[count1]->f0c=_activeProcess->v1b8();
 samples4[count1]->b1c=_activeProcess->v1d0();
 samples4[count1]->b1e=_activeProcess->v1e0();
 samples4[count1]->b1d=_activeProcess->v1d8();
 density5=_activeProcess->v180()/100.0;
 samples4[count1]->weights[0]=FUN_0053a7a0((unsigned char)quad,indexValue4-18)>threshold2 ? density5 : 0.0f;
 samples4[count1]->weights[1]=FUN_0053a7a0((unsigned char)quad,indexValue4-17)>threshold2 ? density5 : 0.0f;
 samples4[count1]->weights[2]=FUN_0053a7a0((unsigned char)quad,indexValue4-16)>threshold2 ? density5 : 0.0f;
 samples4[count1]->weights[3]=FUN_0053a7a0((unsigned char)quad,indexValue4-1)>threshold2 ? density5 : 0.0f;
 samples4[count1]->weights[4]=FUN_0053a7a0((unsigned char)quad,indexValue4)>threshold2 ? density5 : 0.0f;
 samples4[count1]->weights[5]=FUN_0053a7a0((unsigned char)quad,indexValue4+1)>threshold2 ? density5 : 0.0f;
 samples4[count1]->weights[6]=FUN_0053a7a0((unsigned char)quad,indexValue4+16)>threshold2 ? density5 : 0.0f;
 samples4[count1]->weights[7]=FUN_0053a7a0((unsigned char)quad,indexValue4+17)>threshold2 ? density5 : 0.0f;
 samples4[count1]->weights[8]=FUN_0053a7a0((unsigned char)quad,indexValue4+18)>threshold2 ? density5 : 0.0f;
 sumHigh_2=0.0f;
 for(int a=0;a<9;a++) sumHigh_2=sumHigh_2+samples4[count1]->weights[a];
 if(sumHigh_2/9.0<threshold2) {
 for(int b=0;b<9;b++) samples4[count1]->weights[b]=0.0f;
 }
 count1++;
 }
 nodeBTmp=nodeBTmp->Next();
 }
 }
 for(int layer=0;layer<6;layer++) {
 if(!data->layers[quad][layer]) { continue; } else {
 if(data->weights[quad] && (
data->weights[quad][indexValue4-18][layer]>0.1f ||
data->weights[quad][indexValue4-17][layer]>0.1f ||
data->weights[quad][indexValue4-16][layer]>0.1f ||
data->weights[quad][indexValue4-1][layer]>0.1f ||
data->weights[quad][indexValue4+0][layer]>0.1f ||
data->weights[quad][indexValue4+1][layer]>0.1f ||
data->weights[quad][indexValue4+16][layer]>0.1f ||
data->weights[quad][indexValue4+17][layer]>0.1f ||
data->weights[quad][indexValue4+18][layer]>0.1f)) {
 _actors=0; nodeBTmp=data->layers[quad][layer]->GetGrassList();
 while(nodeBTmp && count1<capacity8 && _actors<=limitVal) {
 _activeProcess=*nodeBTmp->GetItem();
 if(_activeProcess) {
 samples4[count1]=new Sample;
 _actors++;
 FUN_00403d30(samples4[count1],0,0x44);
 FUN_00403d30(samples4[count1]->weights,0,0x24);
 samples4[count1]->model=_activeProcess->GetModelFilePath();
 samples4[count1]->id=_activeProcess->GetId();
 samples4[count1]->f14=FUN_0053ca40();
 samples4[count1]->f18=_activeProcess->v1c8();
 samples4[count1]->f10=_activeProcess->v1c0();
 samples4[count1]->f08=_activeProcess->v1b0();
 samples4[count1]->f0c=_activeProcess->v1b8();
 samples4[count1]->b1c=_activeProcess->v1d0();
 samples4[count1]->b1e=_activeProcess->v1e0();
 samples4[count1]->b1d=_activeProcess->v1d8();
 density5=_activeProcess->v180()/100.0;
 samples4[count1]->weights[2]=data->weights[quad][indexValue4-16][layer]>threshold2 ? density5 : 0.0f;
 samples4[count1]->weights[1]=data->weights[quad][indexValue4-17][layer]>threshold2 ? density5 : 0.0f;
 samples4[count1]->weights[0]=data->weights[quad][indexValue4-18][layer]>threshold2 ? density5 : 0.0f;
 samples4[count1]->weights[5]=data->weights[quad][indexValue4+1][layer]>threshold2 ? density5 : 0.0f;
 samples4[count1]->weights[4]=data->weights[quad][indexValue4][layer]>threshold2 ? density5 : 0.0f;
 samples4[count1]->weights[3]=data->weights[quad][indexValue4-1][layer]>threshold2 ? density5 : 0.0f;
 samples4[count1]->weights[8]=data->weights[quad][indexValue4+18][layer]>threshold2 ? density5 : 0.0f;
 samples4[count1]->weights[7]=data->weights[quad][indexValue4+17][layer]>threshold2 ? density5 : 0.0f;
 samples4[count1]->weights[6]=data->weights[quad][indexValue4+16][layer]>threshold2 ? density5 : 0.0f;
 sumHigh_2=0.0f;
 for(int c=0;c<9;c++) sumHigh_2=sumHigh_2+samples4[count1]->weights[c];
 if(sumHigh_2/9.0<threshold2) {
 for(int d=0;d<9;d++) samples4[count1]->weights[d]=0.0f;
 }
 count1++;
 }
 nodeBTmp=nodeBTmp->Next();
 }
 }
 }
 }
 if(samples4[0]) data->maps[quad].SetAt(indexValue4,samples4);
 else delete[] samples4;
 count1=0;
 }
 }
 }
 return true;
}

struct Pt53d8f0 {
    float x;
    float y;
    float z;
    Pt53d8f0();
};

struct Edges53d8f0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

struct LandData53d8f0 {
    int unk00;
    Pt53d8f0** normals;
    Pt53d8f0** vertices;
};

struct Land53d8f0 {
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
    LandData53d8f0* data;

    bool IsLoaded();
    void FindEdges(Edges53d8f0* edges, int a, int b);
    bool TestPoint(void* other, Pt53d8f0* pt);
    void FixPoint(int quad, int index, Pt53d8f0* pt, Edges53d8f0* edges);
    void SetFlag(bool value);
    void FUN_0053d8f0(Edges53d8f0* edges, void* other);
};

// @fnv 0x0053d8f0
void Land53d8f0::FUN_0053d8f0(Edges53d8f0* edges, void* other)
{
    if (!IsLoaded())
        return;
    Edges53d8f0 local;
    if (edges == 0) {
        edges = &local;
        FindEdges(edges, 0, 0);
    }
    Pt53d8f0 pt3;
    int i;
    for (i = 0; i < 4; i++) {
        int j;
        for (j = 0; j < 0x121; j++) {
            if (j < 0x11 || j > 0x110 || j % 0x11 == 0 || (j + 1) % 0x11 == 0) {
                if (other == 0 || TestPoint(other, data->normals[i] + j)) {
                    FixPoint(i, j, data->vertices[i] + j, edges);
                }
            }
        }
    }
    if (edges->unk08 && edges->unk04 && edges->unk00 && edges->unk1C && edges->unk18 && edges->unk14 && edges->unk10 && edges->unk0C)
        SetFlag(true);
}

struct NormalPoint {
 float x,y,z;
 NormalPoint operator-(const NormalPoint&) const;
 NormalPoint Cross(const NormalPoint&) const;
 NormalPoint& operator+=(const NormalPoint&);
};
extern NormalPoint NiPoint3_ZERO;
extern unsigned short* DAT_011c9ee8;
void __cdecl FUN_00525340(NormalPoint*);
void __cdecl NormalizePoints(NormalPoint*, int, int);
struct NormalData {
 int unk00;
 NormalPoint** vertices;
 NormalPoint** normals;
 int unk0c;
 unsigned char** flags;
};
struct NormalLand : TESPackage {
 int unk20;
 int unk24;
 NormalData* data;
 bool FUN_0053da60(void*, const NormalPoint*);
 void FUN_0053df30(void* region);
};
// @fnv 0x0053df30
void NormalLand::FUN_0053df30(void* region) {
 if (!FUN_005394a0()) return;
 for (int quad4=0; quad4<4; ++quad4) {
  int vertex;
  for (vertex=0; vertex<289; ++vertex) {
   if (!region || FUN_0053da60(region, &data->vertices[quad4][vertex])) {
    data->normals[quad4][vertex] = NiPoint3_ZERO;
    data->flags[quad4][vertex] = 0;
   }
  }
  unsigned short* indices5 = DAT_011c9ee8;
  for (unsigned short triangle9=0; triangle9<512; ++triangle9) {
   unsigned short first2 = *indices5; ++indices5;
   unsigned short second3 = *indices5; ++indices5;
   unsigned short third4 = *indices5; ++indices5;
   NormalPoint edge1 = data->vertices[quad4][second3] - data->vertices[quad4][first2];
   NormalPoint edge8 = data->vertices[quad4][third4] - data->vertices[quad4][second3];
   NormalPoint normal = edge1.Cross(edge8);
   FUN_00525340(&normal);
   if (!region || FUN_0053da60(region, &data->vertices[quad4][first2])) data->normals[quad4][first2] += normal;
   if (!region || FUN_0053da60(region, &data->vertices[quad4][second3])) data->normals[quad4][second3] += normal;
   if (!region || FUN_0053da60(region, &data->vertices[quad4][third4])) data->normals[quad4][third4] += normal;
  }
  NormalizePoints(data->normals[quad4],289,12);
 }
}

struct LandVertex {
    float x;
    float y;
    float z;
    LandVertex();
};

struct LandCoord {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int cellIndex;
    float fracX;
    float fracY;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int vertex0;
    int vertex1;
    int vertex2;
    bool upperTriangle;
    bool swapAxes;
};

struct LandHeights {
    float z0;
    float z1;
    float z2;
};

struct LandStandIn {
    void GetVertex(int cell, int index, LandVertex* out);
    bool FUN_0053f1e0(LandCoord& coord, float& height);
};

// @fnv 0x0053f1e0
bool LandStandIn::FUN_0053f1e0(LandCoord& coord, float& height)
{
    LandVertex v0;
    LandVertex v1;
    LandVertex v2;
    GetVertex(coord.cellIndex, coord.vertex0, &v0);
    GetVertex(coord.cellIndex, coord.vertex1, &v1);
    GetVertex(coord.cellIndex, coord.vertex2, &v2);
    LandHeights h;
    h.z0 = v0.z;
    h.z1 = v1.z;
    h.z2 = v2.z;
    float dx;
    float dy3;
    if (!coord.upperTriangle) {
        dx = (h.z0 - h.z1) / 128.0;
        dy3 = (h.z2 - h.z0) / 128.0;
        if (!coord.swapAxes)
            height = dx * coord.fracX + h.z1 + dy3 * coord.fracY;
        else
            height = dx * coord.fracY + h.z1 + dy3 * coord.fracX;
    } else {
        dx = (h.z1 - h.z0) / 128.0;
        dy3 = (h.z2 - h.z0) / 128.0;
        if (coord.swapAxes) {
            dx = (h.z0 - h.z2) / 128.0;
            dy3 = (h.z0 - h.z1) / 128.0;
            height = h.z0 - ((128.0f - coord.fracX) * dx + (128.0f - coord.fracY) * dy3) ;
        } else {
            dx = (h.z1 - h.z0) / 128.0;
            dy3 = (h.z2 - h.z0) / 128.0;
            height = dx * coord.fracX + h.z0 + dy3 * coord.fracY;
        }
    }
    return true;
}

extern const double DAT_010231b0;
extern const double DAT_010241b0;

struct LandData53f
{
    char pad00[0x18];
    NiPoint2 kHeight;
};

struct FUN_0053f440_shell
{
    char pad00[0x1c];
    unsigned int uiFlags;
    char pad20[8];
    LandData53f* pkData;

    float FUN_0053a550();
    NiPoint2 FUN_0053f390(int iQuad);
    NiPoint2 FUN_0053f440();
};

// @fnv 0x0053f440
NiPoint2 FUN_0053f440_shell::FUN_0053f440()
{
    if (!pkData)
        return NiPoint2(DAT_01016970, DAT_01015f5c);
    if (pkData->kHeight.x == DAT_010231b0 || pkData->kHeight.y == DAT_010241b0)
    {
        if (uiFlags & 1)
        {
            for (int i = 0; i < 4; i++)
            {
                NiPoint2 kQuad = FUN_0053f390(i);
                if (kQuad.x < pkData->kHeight.x)
                    pkData->kHeight.x = kQuad.x;
                if (kQuad.y > pkData->kHeight.y)
                    pkData->kHeight.y = kQuad.y;
            }
        }
        else
        {
            pkData->kHeight = NiPoint2(FUN_0053a550(), FUN_0053a550());
        }
    }
    return pkData->kHeight;
}

namespace fnv_0053f570 {
struct RgbaColor {
    float r, g, b, a;
    RgbaColor(float r, float g, float b, float a);
    RgbaColor operator+(const RgbaColor& other) const;
    RgbaColor operator*(float scalar) const;
};
RgbaColor __cdecl operator*(float scalar, const RgbaColor& value);
extern "C" float DAT_0101e704;
extern "C" double DAT_0102e430;
float __cdecl FUN_004b1520(float value, float bound);



struct OwnerInterp : Owner {
  void FUN_005345c0(int first, int second, RgbaColor* out);
  bool FUN_0053f570(const float* xy, RgbaColor* out);
};

// @fnv 0x0053f570
bool OwnerInterp::FUN_0053f570(const float* xy, RgbaColor* out)
{
    Buf50 data;
    data.FUN_0053a510();
    if (!FUN_0053b550(&data, (int)xy, 0))
        return false;

    RgbaColor aVal(0.0f, 0.0f, 0.0f, 0.0f);
    RgbaColor b(0.0f, 0.0f, 0.0f, 0.0f);
    RgbaColor thirdColor(0.0f, 0.0f, 0.0f, 0.0f);
    float x3 = (float)(FUN_004b1520(xy[0], DAT_0101e704) / DAT_0102e430);
    float y = (float)(FUN_004b1520(xy[1], DAT_0101e704) / DAT_0102e430);
    FUN_005345c0(data.m18, data.m40, &aVal);
    FUN_005345c0(data.m18, data.m44, &b);
    FUN_005345c0(data.m18, data.m48, &thirdColor);

    if (!(*(unsigned char*)&data.m4C) && !(*((unsigned char*)&data.m4C+1))) {
        *out = (((1.0f-x3)*b + x3*aVal) * (1.0f-y)) + y*thirdColor;
    }
    if (!(*(unsigned char*)&data.m4C) && (*((unsigned char*)&data.m4C+1))) {
        *out = (((1.0f-x3)*aVal + x3*thirdColor) * y) + (1.0f-y)*b;
    }
    if ((*(unsigned char*)&data.m4C) && !(*((unsigned char*)&data.m4C+1))) {
        *out = (((1.0f-x3)*aVal + x3*b) * (1.0f-y)) + y*thirdColor;
    }
    if ((*(unsigned char*)&data.m4C) && (*((unsigned char*)&data.m4C+1))) {
        *out = (((1.0f-x3)*thirdColor + x3*aVal) * y) + (1.0f-y)*b;
    }
    return true;
}
}  // namespace fnv_0053f570

namespace fnv_0053fa40 {
struct P53 { float x,y,z; P53(); P53(float,float,float); P53 operator+(const P53&) const; P53 operator-(const P53&) const; };
struct C53 { float r,g,b,a; C53(); C53(float,float,float,float); };
struct G53 { int* Int(); };
extern G53 g_011c9fc8,g_011c9f9c,g_011c9f20,g_011c9fac,g_011ca024,g_011c9ff4;
struct U53 { float t; bool a,b; int c; U53(float,bool,bool); };
struct N53 {
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
virtual void Attach(N53*,bool);
virtual void v0e0();
virtual void v0e4();
virtual void Detach(N53*);
void FUN_00440460(const P53&); void FUN_00439410(void*); void FUN_00a5a040(); void Update(U53&);
};
struct Ptr53 { N53* Get(); Ptr53& Assign(N53*); };
struct CellMesh53 { N53* FUN_00545cb0(); };
struct DataMesh53 { int u00,u04,u08,u0c,u10; Ptr53 mesh; };
struct Alloc53 { static void* operator new(unsigned); static void operator delete(void*, unsigned int); };
struct Mesh53 : N53, Alloc53 {
int u04; int u08; int u0c; int u10; int u14; int u18; int u1c; int u20; int u24; int u28; int u2c; int u30; int u34; int u38; int u3c; int u40; int u44; int u48; int u4c; int u50; int u54; int u58; int u5c; int u60; int u64; int u68; int u6c; int u70; int u74; int u78; int u7c; int u80; int u84; int u88; int u8c; int u90; int u94; int u98; int u9c; int ua0; int ua4; int ua8; int uac; int ub0; int ub4; int ub8; int ubc; int uc0;Mesh53(unsigned short,P53*,C53*,void*,void*,void*,unsigned char*);
};
struct Tex53 : Alloc53 {
int u00; int u04; int u08; int u0c; int u10; int u14; int u18; int u1c; int u20; int u24; int u28; int u2c;Tex53(); void FUN_00533f40(int); void FUN_00a6a150(int,int);
};
struct Light53 : Alloc53 {
int u00; int u04; int u08; int u0c; int u10; int u14; int u18; int u1c; int u20; int u24; int u28; int u2c; int u30; int u34; int u38; int u3c; int u40; int u44; int u48; int u4c; int u50; int u54; int u58; int u5c; int u60; int u64; int u68; int u6c; int u70; int u74; int u78; int u7c;Light53(); void FUN_005a8060(int);
};
void FUN_00b57e30(N53*,int,int);
struct HostMesh53 {
 int u00,u04,u08,u0c,u10,u14,u18,u1c; CellMesh53* cell; int u24; DataMesh53* data;
 bool FUN_0045cb90(); float FUN_00534050(); float FUN_00534080(); void FUN_0053f180(P53 const&,float&);
 void FUN_0053fa40(bool);
};
// @fnv 0x0053fa40
void HostMesh53::FUN_0053fa40(bool show) {
 const int edge7=32;
 const int aCount=128;
 int index2=0;
 if(!FUN_0045cb90()) return;
 N53* root_=cell->FUN_00545cb0();
 if(!root_) return;
 if(data->mesh.Get()) { root_->Detach(data->mesh.Get()); data->mesh.Assign(0); }
 if(!show) return;
 P53* vertices5=new P53[aCount];
 C53* colors3=new C53[aCount];
 unsigned char* flags=new unsigned char[aCount];
 P53 origin(FUN_00534050(),FUN_00534080(),0.0f);
 int row3,col2;
 for(row3=0;row3<33;row3++) {
 for(col2=0;col2<33;col2++) {
 if(row3==0 || col2==0 || row3==32 || col2==32) {
 if(col2==0) index2=row3;
 else if(row3==32) index2=32+col2;
 else if(col2==32) index2=64+(32-row3);
 else if(row3==0) index2=96+(32-col2);
 if(index2%2) colors3[index2]=C53(*g_011c9f20.Int()/255.0,*g_011c9f9c.Int()/255.0,*g_011c9fc8.Int()/255.0,1.0f);
 else colors3[index2]=C53(*g_011c9ff4.Int()/255.0,*g_011ca024.Int()/255.0,*g_011c9fac.Int()/255.0,1.0f);
 flags[index2]=1;
 P53 point4=origin+P53(row3*128.0,col2*128.0,0.0f);
 float height3;
 FUN_0053f180(point4,height3);
 point4.z=height3+5.0;
 vertices5[index2]=point4-origin;
 }
 }
 }
 data->mesh.Assign(new Mesh53(aCount,vertices5,colors3,0,0,0,flags));
 data->mesh.Get()->FUN_00440460(origin);
 Tex53* tex4=new Tex53;
 tex4->FUN_00533f40(0);
 tex4->FUN_00a6a150(0,0);
 data->mesh.Get()->FUN_00439410(tex4);
 Light53* light8=new Light53;
 light8->FUN_005a8060(33);
 data->mesh.Get()->FUN_00439410(light8);
 FUN_00b57e30(data->mesh.Get(),0,0);
 root_->Attach(data->mesh.Get(),true);
 data->mesh.Get()->FUN_00a5a040();
 U53 update5(0.0f,false,false);
 data->mesh.Get()->Update(update5);
}
}  // namespace fnv_0053fa40

#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged

// @fnv 0x00406d90
int __cdecl FUN_00406d90(float fValue)
{
    int iValue;
    __asm {
        fld fValue
        fistp iValue
    }
    return iValue;
}

namespace TESLandInit {

struct LandMemContext {
    int iOldContext;
    LandMemContext(int aiContext, bool abPush, const char* apFile, int aiLine);
    ~LandMemContext();
};

struct LandMemObject {
    static void* operator new(unsigned int auiSize);
    static void operator delete(void* apMem, unsigned int);
};

struct LandTexturePtr {
    void* pObject;
    LandTexturePtr(void* apObject);
    ~LandTexturePtr();
    void* FUN_00559450();
};

struct LandShaderSlot {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0a(); virtual void v0b();
    virtual void v0c(); virtual void v0d(); virtual void v0e(); virtual void v0f(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1a(); virtual void v1b(); virtual void v1c(); virtual void v1d();
    virtual void v1e(); virtual void v1f(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void FUN_vt90(int aiIndex, LandTexturePtr* apOut);
};

struct LandTexturing : LandMemObject {
    LandTexturing();
    char pad00[0x30];
    LandShaderSlot kShader;
    char pad34[0x6c];
    void SetFullNameByType(int aiIndex, const char* apPath);
};

struct LandShaderData {
    LandShaderData();
    char data[0x28];
    void FUN_00984f60(LandTexturing* apTexturing);
};

struct LandTextureData {
    LandTextureData(void* apTexture, int a2, int a3, int a4, int a5);
    char data[0x10];
};

struct LandProperty : LandMemObject {
    LandProperty();
    char data[0x30];
};

struct LandPropertyList {
    void FUN_00533fb0(int aiMode);
    void FUN_00533f40(LandTextureData* apData);
};

struct LandPropertyHolder {
    void FUN_0066b0d0(LandProperty* apProperty);
    LandPropertyList* FUN_00559450();
};

struct LandShaderList {
    void RemoveNode(LandTexturing* apTexturing);
};

struct LandShaderManager {
    LandShaderList* FUN_00726070();
};

struct LandStringSetting {
    const char* FUN_00403df0();
};

struct LandFloatSetting {
    float* FUN_00403e20();
};

struct LandColor {
    float r, g, b, a;
    LandColor();
    LandColor(float afR, float afG, float afB, float afA);
};

struct LandPoint3 {
    float x, y, z;
    LandPoint3();
    LandPoint3(float afX, float afY, float afZ);
};

struct LandPoint2 {
    float x, y;
    LandPoint2();
    LandPoint2(float afX, float afY);
};

extern LandTexturing* DAT_011c9f08;
extern LandShaderData* DAT_011c9f04;
extern LandShaderManager* DAT_011c3f2c;
extern LandPropertyHolder DAT_011ca000;
extern LandStringSetting DAT_011ca004;
extern LandStringSetting DAT_011c9f8c;
extern LandFloatSetting DAT_011c9f2c;
extern unsigned short* DAT_011c9ee8;
extern LandColor* DAT_011c9eec;
extern LandPoint3* DAT_011c9ef0;
extern unsigned char* DAT_011c9ef8;
extern LandPoint2* DAT_011c9ef4;
extern float DAT_011c9ec4[4];
extern float DAT_011c9eb4[4];
extern LandPoint3* DAT_011c9ed4[4];
extern unsigned char DAT_011c9efc;

int __cdecl FUN_00406d00(char* apBuffer, unsigned int auiSize, const char* apFormat, ...);
int __cdecl FUN_005b5e40(const char* apFormat, ...);

static const char s_szSourceFile[] = "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESLand.cpp";
static const char s_szLandscapeFormat[] = "Landscape\\%s";
static const char s_szTilingWarning[] = "DEFAULT: INI setting fLandTextureTilingMult cannot be 0.";

// @fnv 0x00533420
void __cdecl FUN_00533420() {
    LandMemContext kMemContext(0x1b, true, s_szSourceFile, 0xc6);
    DAT_011c9f08 = new LandTexturing();
    char acPath[260];
    FUN_00406d00(acPath, 260, s_szLandscapeFormat, DAT_011ca004.FUN_00403df0());
    DAT_011c9f08->SetFullNameByType(0, acPath);
    FUN_00406d00(acPath, 260, s_szLandscapeFormat, DAT_011c9f8c.FUN_00403df0());
    DAT_011c9f08->SetFullNameByType(1, acPath);
    DAT_011c3f2c->FUN_00726070()->RemoveNode(DAT_011c9f08);
    DAT_011c9f04 = new LandShaderData();
    DAT_011c9f04->FUN_00984f60(DAT_011c9f08);
    LandTexturePtr kTexture(0);
    DAT_011c9f08->kShader.FUN_vt90(0, &kTexture);
    LandTextureData* pTextureDataValue = new LandTextureData(kTexture.FUN_00559450(), 0, 3, 5, 0);
    DAT_011ca000.FUN_0066b0d0(new LandProperty());
    DAT_011ca000.FUN_00559450()->FUN_00533fb0(2);
    DAT_011ca000.FUN_00559450()->FUN_00533f40(pTextureDataValue);

    DAT_011c9ee8 = new unsigned short[0x600];
    int iIndex = 0;
    int iVal;
    int jPtr;
    for (iVal = 0; iVal < 16; iVal++) {
        for (jPtr = 0; jPtr < 16; jPtr++) {
            if ((iVal % 2) ^ (jPtr % 2)) {
                unsigned short m_usVertexId;
                m_usVertexId = (iVal + 1) * 17 + jPtr;
                DAT_011c9ee8[iIndex] = m_usVertexId;
                iIndex++;
                m_usVertexId = iVal * 17 + jPtr;
                DAT_011c9ee8[iIndex] = m_usVertexId;
                iIndex++;
                m_usVertexId = iVal * 17 + jPtr + 1;
                DAT_011c9ee8[iIndex] = m_usVertexId;
                iIndex++;
                m_usVertexId = iVal * 17 + jPtr + 1;
                DAT_011c9ee8[iIndex] = m_usVertexId;
                iIndex++;
                m_usVertexId = (iVal + 1) * 17 + jPtr + 1;
                DAT_011c9ee8[iIndex] = m_usVertexId;
                iIndex++;
                m_usVertexId = (iVal + 1) * 17 + jPtr;
                DAT_011c9ee8[iIndex] = m_usVertexId;
                iIndex++;
            } else {
                unsigned short usCorner;
                usCorner = (iVal + 1) * 17 + jPtr + 1;
                DAT_011c9ee8[iIndex] = usCorner;
                iIndex++;
                usCorner = (iVal + 1) * 17 + jPtr;
                DAT_011c9ee8[iIndex] = usCorner;
                iIndex++;
                usCorner = iVal * 17 + jPtr;
                DAT_011c9ee8[iIndex] = usCorner;
                iIndex++;
                usCorner = iVal * 17 + jPtr;
                DAT_011c9ee8[iIndex] = usCorner;
                iIndex++;
                usCorner = iVal * 17 + jPtr + 1;
                DAT_011c9ee8[iIndex] = usCorner;
                iIndex++;
                usCorner = (iVal + 1) * 17 + jPtr + 1;
                DAT_011c9ee8[iIndex] = usCorner;
                iIndex++;
            }
        }
    }

    float fTiling = *DAT_011c9f2c.FUN_00403e20();
    if (fTiling == 0.0) {
        FUN_005b5e40(s_szTilingWarning);
        fTiling = 16.0f;
    }
    fTiling = 4.0 / fTiling;
    DAT_011c9eec = new LandColor[0x121];
    DAT_011c9ef0 = new LandPoint3[0x121];
    DAT_011c9ef8 = new unsigned char[0x121];
    DAT_011c9ef4 = new LandPoint2[0x121];
    iIndex = 0;
    for (iVal = 0; iVal < 17; iVal++) {
        for (jPtr = 0; jPtr < 17; jPtr++) {
            DAT_011c9eec[iIndex] = LandColor(1.0f, 1.0f, 1.0f, 0.0f);
            DAT_011c9ef0[iIndex] = LandPoint3(0.0f, 0.0f, 1.0f);
            DAT_011c9ef8[iIndex] = 1;
            DAT_011c9ef4[iIndex] = LandPoint2(jPtr / fTiling, iVal / fTiling);
            iIndex++;
        }
    }
    int kLocal;
    for (kLocal = 0; kLocal < 4; kLocal++) {
        DAT_011c9ec4[kLocal] = (kLocal % 2) * 2048 - 2048;
        DAT_011c9eb4[kLocal] = (kLocal / 2) * 2048 - 2048;
    }
    for (kLocal = 0; kLocal < 4; kLocal++) {
        iIndex = 0;
        DAT_011c9ed4[kLocal] = new LandPoint3[0x121];
        for (iVal = 0; iVal < 17; iVal++) {
            for (jPtr = 0; jPtr < 17; jPtr++) {
                DAT_011c9ed4[kLocal][iIndex] = LandPoint3(jPtr * 128 + DAT_011c9ec4[kLocal], iVal * 128 + DAT_011c9eb4[kLocal], -2048.0f);
                iIndex++;
            }
        }
    }
    DAT_011c9efc = 1;
}

}

struct Vec3 {
    float x, y, z;
    Vec3();
    Vec3(float afX, float afY, float afZ);
    void FUN_0063c8a0(const Vec3* apOther);
    Vec3 FUN_0053d280(float afDivisor);
};
struct CoordProcessor { int x, y, z; Vec3 FUN_00439e90(const Vec3& arOrigin); };
struct Grid53 { int count; CoordProcessor** processors; Vec3** positions; int unknown0c; unsigned char** evaluated; };
struct FNV53WorkerProxy { bool FUN_0053d2e0(Vec3* apCoord, Vec3* apAxis, Vec3* apAux); bool FUN_0053e210(Vec3* apCoord); };
struct WorkerTable53 { FNV53WorkerProxy* southwest; FNV53WorkerProxy* northwest; FNV53WorkerProxy* southeast; FNV53WorkerProxy* northCount; FNV53WorkerProxy* east; FNV53WorkerProxy* west; FNV53WorkerProxy* upper; FNV53WorkerProxy* northeast; };
struct Region53 { int m00,m04,m08,m0c,m10,m14,m18,m1c,m20,m24; Grid53* grid; float FUN_00534080(); float FUN_00534050(); void FUN_0053e290(int,int,Vec3*,WorkerTable53*); };
// @fnv 0x0053e290
void Region53::FUN_0053e290(int row, int col, Vec3* result, WorkerTable53* workers) {
    if (grid->evaluated[row][col] != 0 || workers == 0)
        return;
    Vec3 originStep;
    originStep = Vec3(FUN_00534050() + 2048.0, FUN_00534080() + 2048.0, 0.0f);
    Vec3 coordOut = grid->processors[row][col].FUN_00439e90(originStep);
    bool northCount = false, lowerNeighborIn = false, westNeighborCur = false, eastNeighbor = false, higherData = false, isBottomRes = false, leftData = false, rightVal = false;
    Vec3 axis;
    Vec3 blend;
    float amount = 1.0f;
    blend = grid->positions[row][col];
    FNV53WorkerProxy* worker;
    if(row<2 && col<17) {


    higherData=true;


    worker=workers->upper;


    Vec3 auxA;


    if (!worker || !worker->FUN_0053d2e0(&coordOut, &axis, &auxA)) {


      axis = Vec3(0.0f, 0.0f, 1.0f);


    }


    if (worker && worker->FUN_0053e210(&coordOut)) {


      *result=axis; grid->evaluated[row][col]=1; return;


    }


    blend.FUN_0063c8a0(&axis);


    amount = amount + 1.0;


    } else if(row>=2 && col>=0x110) {


    isBottomRes=true;


    worker=workers->northwest;


    Vec3 auxB;


    if (!worker || !worker->FUN_0053d2e0(&coordOut, &axis, &auxB)) {


      axis = Vec3(0.0f, 0.0f, 1.0f);


    }


    if (worker && worker->FUN_0053e210(&coordOut)) {


      *result=axis; grid->evaluated[row][col]=1; return;


    }


    blend.FUN_0063c8a0(&axis);


    amount = amount + 1.0;


    }


    if((row%2)==0 && col%17==0) {


    leftData=true;


    worker=workers->northCount;


    Vec3 auxC;


    if (!worker || !worker->FUN_0053d2e0(&coordOut, &axis, &auxC)) {


      axis = Vec3(0.0f, 0.0f, 1.0f);


    }


    if (worker && worker->FUN_0053e210(&coordOut)) {


      *result=axis; grid->evaluated[row][col]=1; return;


    }


    blend.FUN_0063c8a0(&axis);


    amount = amount + 1.0;


    } else if((row+1)%2==0 && (col+1)%17==0) {


    rightVal=true;


    worker=workers->east;


    Vec3 auxD;


    if (!worker || !worker->FUN_0053d2e0(&coordOut, &axis, &auxD)) {


      axis = Vec3(0.0f, 0.0f, 1.0f);


    }


    if (worker && worker->FUN_0053e210(&coordOut)) {


      *result=axis; grid->evaluated[row][col]=1; return;


    }


    blend.FUN_0063c8a0(&axis);


    amount = amount + 1.0;


    }


    if(leftData && higherData) {


    


    worker=workers->west;


    Vec3 auxE;


    if (!worker || !worker->FUN_0053d2e0(&coordOut, &axis, &auxE)) {


      axis = Vec3(0.0f, 0.0f, 1.0f);


    }


    if (worker && worker->FUN_0053e210(&coordOut)) {


      *result=axis; grid->evaluated[row][col]=1; return;


    }


    blend.FUN_0063c8a0(&axis);


    amount = amount + 1.0;


    } else if(rightVal && higherData) {


    


    worker=workers->northeast;


    Vec3 auxF;


    if (!worker || !worker->FUN_0053d2e0(&coordOut, &axis, &auxF)) {


      axis = Vec3(0.0f, 0.0f, 1.0f);


    }


    if (worker && worker->FUN_0053e210(&coordOut)) {


      *result=axis; grid->evaluated[row][col]=1; return;


    }


    blend.FUN_0063c8a0(&axis);


    amount = amount + 1.0;


    } else if(leftData && isBottomRes) {


    


    worker=workers->southwest;


    Vec3 auxG;


    if (!worker || !worker->FUN_0053d2e0(&coordOut, &axis, &auxG)) {


      axis = Vec3(0.0f, 0.0f, 1.0f);


    }


    if (worker && worker->FUN_0053e210(&coordOut)) {


      *result=axis; grid->evaluated[row][col]=1; return;


    }


    blend.FUN_0063c8a0(&axis);


    amount = amount + 1.0;


    } else if(rightVal && isBottomRes) {


    


    worker=workers->southeast;


    Vec3 auxH;


    if (!worker || !worker->FUN_0053d2e0(&coordOut, &axis, &auxH)) {


      axis = Vec3(0.0f, 0.0f, 1.0f);


    }


    if (worker && worker->FUN_0053e210(&coordOut)) {


      *result=axis; grid->evaluated[row][col]=1; return;


    }


    blend.FUN_0063c8a0(&axis);


    amount = amount + 1.0;


    }


    if(col<17 && !higherData) {


    northCount=true;


    axis = grid->positions[row-2][col+0x110];


    if(grid->evaluated[row-2][col+0x110]) {


       *result=axis;grid->evaluated[row][col]=1;return;


    }


    blend.FUN_0063c8a0(&axis);


    amount=amount+1.0;


    } else if(col>=0x110 && !isBottomRes) {


    lowerNeighborIn=true;


    axis = grid->positions[row+2][col-0x110];


    if(grid->evaluated[row+2][col-0x110]) {


       *result=axis;grid->evaluated[row][col]=1;return;


    }


    blend.FUN_0063c8a0(&axis);


    amount=amount+1.0;


    }


    if(col%17==0 && !leftData) {


    westNeighborCur=true;


    axis = grid->positions[row-1][col+16];


    if(grid->evaluated[row-1][col+16]) {


       *result=axis;grid->evaluated[row][col]=1;return;


    }


    blend.FUN_0063c8a0(&axis);


    amount=amount+1.0;


    } else if((col+1)%17==0 && !rightVal) {


    eastNeighbor=true;


    axis = grid->positions[row+1][col-16];


    if(grid->evaluated[row+1][col-16]) {


       *result=axis;grid->evaluated[row][col]=1;return;


    }


    blend.FUN_0063c8a0(&axis);


    amount=amount+1.0;


    }


    if(westNeighborCur && northCount) {


    


    axis = grid->positions[row-3][0x120];


    if(grid->evaluated[row-3][0x120]) {


       *result=axis;grid->evaluated[row][col]=1;return;


    }


    blend.FUN_0063c8a0(&axis);


    amount=amount+1.0;


    } else if(westNeighborCur && lowerNeighborIn) {


    


    axis = grid->positions[row+1][16];


    if(grid->evaluated[row+1][16]) {


       *result=axis;grid->evaluated[row][col]=1;return;


    }


    blend.FUN_0063c8a0(&axis);


    amount=amount+1.0;


    } else if(eastNeighbor && northCount) {


    


    axis = grid->positions[row-1][0x110];


    if(grid->evaluated[row-1][0x110]) {


       *result=axis;grid->evaluated[row][col]=1;return;


    }


    blend.FUN_0063c8a0(&axis);


    amount=amount+1.0;


    } else if(eastNeighbor && lowerNeighborIn) {


    


    axis = grid->positions[row+3][0];


    if(grid->evaluated[row+3][0]) {


       *result=axis;grid->evaluated[row][col]=1;return;


    }


    blend.FUN_0063c8a0(&axis);


    amount=amount+1.0;


    }


    *result = blend.FUN_0053d280(amount);
    grid->evaluated[row][col] = 1;
}

struct NiP2 { float x, y; NiP2(); };
struct NiPoint3_ext { float x, y, z; NiPoint3_ext(); };
class NiFixedString {
public:
    const char* value;
    NiFixedString(const char*);
    ~NiFixedString();
};
struct Geometry5371 {
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
    static void* operator new(unsigned int); static void operator delete(void*, unsigned int);
    Geometry5371(unsigned short, NiPoint3*, NiPoint3_ext*, void*, NiP2*, unsigned short, unsigned short, unsigned short, unsigned short, unsigned short*, unsigned short*);
    void FUN_00440460(const NiPoint3&);
    void SetName(const NiFixedString&);
};
struct MeshData5371 {
    void* unk00;
    NiPoint3** vertices;
    NiPoint3_ext** normals;
    NiP2** texcoords;
};
struct Land5371 {
    int unk00; int unk04; int unk08; int unk0c; int unk10;
    int unk14; int unk18; int unk1c; int unk20; int unk24;
    MeshData5371* data;
    void FUN_00535b30(NiPoint3*, unsigned char);
    Geometry5371* FUN_005371b0(unsigned char index);
};
extern NiP2* DAT_011c9ef4;
extern unsigned short DAT_0118ae90[];
void* FUN_00aa1070(unsigned int);
int FUN_00406d00(char*, int, const char*, ...);
// @fnv 0x005371b0
Geometry5371* Land5371::FUN_005371b0(unsigned char index)
{
    Geometry5371* p = 0;
    if (index < 4 && data != 0) {
        NiP2* a = new NiP2[289];
        memcpy(a, DAT_011c9ef4, 2312);
        unsigned short* f = (unsigned short*)FUN_00aa1070(2);
        unsigned short* s = (unsigned short*)FUN_00aa1070(2042);
        *f = 1021;
        memcpy(s, DAT_0118ae90, 2042);
        NiPoint3_ext* eb = new NiPoint3_ext[289];
        memcpy(eb, data->normals[index], 3468);
        p = new Geometry5371(289, data->vertices[index], eb,
                                 data->texcoords[index], a, 1, 0,
                                 *f - 2, 1, f, s);
        NiPoint3 h;
        FUN_00535b30(&h, index);
        p->FUN_00440460(h);
        char i[260];
        FUN_00406d00(i, 260, "Block (%i, %i)", index % 4, index / 4);
        p->SetName(NiFixedString(i));
    }
    return p;
}

class NiPoint3LD {
public:
    NiPoint3LD();
    void Unitize();
    float x;
    float y;
    float z;
};

void* __cdecl FUN_00401460(void* pvDest, const void* pvSrc, unsigned int uiSize);

struct LandDataLD {
    unsigned int unk00;
    unsigned int unk04;
    NiPoint3LD** m_apkNormals;
};

class LandLD {
public:
    bool IsLoaded();
    bool IsBusy();
    void GetNeighbors(LandLD** ppkNeighbors, int iValue, bool* pbChanged);
    NiPoint3LD** GetNormals();
    void SetNormalsDirty(int iValue);
    void SetupNeighbors(LandLD** ppkNeighbors, int iValue);
    void UpdateNormals();
    bool FUN_0053db20();
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
    LandDataLD* m_pUserData;
};

// @fnv 0x0053db20
bool LandLD::FUN_0053db20()
{
    int i;
    if (!IsLoaded() || IsBusy())
        return false;
    bool abChanged[8];
    FUN_00403d30(abChanged, 0, 8);
    LandLD* apkNeighbors[8];
    GetNeighbors(apkNeighbors, 1, abChanged);
    LandLD** ppkNeighbors = apkNeighbors;
    {
    NiPoint3LD akNormals[8][4][289];
    for (i = 0; i < 8; i++) {
        if (ppkNeighbors[i]) {
            for (int j = 0; j < 4; j++)
                FUN_00401460(akNormals[i][j], ppkNeighbors[i]->GetNormals()[j], 0xd8c);
            ppkNeighbors[i]->SetNormalsDirty(0);
        }
    }
    SetNormalsDirty(0);
    SetupNeighbors(apkNeighbors, 0);
    for (i = 0; i < 4; i++) {
        for (int k = 0; k < 289; k++) {
            m_pUserData->m_apkNormals[i][k].Unitize();
            char cX = (char)(m_pUserData->m_apkNormals[i][k].x * 127.0);
            char cY = (char)(m_pUserData->m_apkNormals[i][k].y * 127.0);
            char cZ = (char)(m_pUserData->m_apkNormals[i][k].z * 127.0);
            m_pUserData->m_apkNormals[i][k].x = cX / 127.0f;
            m_pUserData->m_apkNormals[i][k].y = cY / 127.0f;
            m_pUserData->m_apkNormals[i][k].z = cZ / 127.0f;
            m_pUserData->m_apkNormals[i][k].Unitize();
        }
    }
    for (i = 0; i < 8; i++) {
        if (ppkNeighbors[i]) {
            for (int j = 0; j < 4; j++)
                FUN_00401460(ppkNeighbors[i]->GetNormals()[j], akNormals[i][j], 0xd8c);
            if (abChanged[i])
                ppkNeighbors[i]->UpdateNormals();
        }
    }
    }
    return true;
}

extern "C" void* __cdecl memset(void* dst, int val, unsigned int size);

float __cdecl Max_00404010(float a, float b);
float __cdecl Min_0040ebd0(float a, float b);
extern double DAT_01012070;

class TESLandTexture {
public:
    virtual void v00();
};

class TESTexture : public TESLandTexture {
public:
    bool FUN_0048e4f0(TESTexture*);
};

// @fnv 0x0053aeb0
void Land::FUN_0053aeb0()
{
    for (int quadB = 0; quadB < 4; quadB++) {
        TESLandTexture* baseForm3 =
            (TESLandTexture*)((FUN_0053a5a0_Outer*)this)->FUN_0053a5a0(quadB);
        TESTexture* base5 = dynamic_cast<TESTexture*>(baseForm3);
        float sums_[289];
        memset(sums_, 0, sizeof(sums_));

        for (int a = 0; a < 6; a++) {
            TESLandTexture* texAB =
                (TESLandTexture*)((FUN_0053a700_Holder*)this)->FUN_0053a700(quadB, a);
            TESTexture* kFormA = dynamic_cast<TESTexture*>(texAB);

            if (kFormA != 0) {
                for (int b2 = 0; b2 < 6; b2++) {
                    if (a != b2) {
                        TESLandTexture* texB =
                            (TESLandTexture*)((FUN_0053a700_Holder*)this)->FUN_0053a700(quadB, b2);
                        TESTexture* formB = dynamic_cast<TESTexture*>(texB);

                        if (formB != 0 && !kFormA->FUN_0048e4f0(formB)) {
                            for (int k = 0; k < 289; k++) {
                                ((ShiftTableData*)data)->m_appfRows[quadB][k][a] +=
                                    ((ShiftTableData*)data)->m_appfRows[quadB][k][b2];
                                ((ShiftTableData*)data)->m_appfRows[quadB][k][b2] = 0.0f;
                            }
                            ((FUN_0053a760_Class*)this)->FUN_0053a760(quadB, b2, 0);
                        }
                    }
                }

                if (base5 != 0 && !kFormA->FUN_0048e4f0(base5)) {
                    for (int k = 0; k < 289; k++) {
                        ((ShiftTableData*)data)->m_appfRows[quadB][k][a] = 0.0f;
                    }
                    ((FUN_0053a760_Class*)this)->FUN_0053a760(quadB, a, 0);
                }
            }

            for (int k = 0; k < 289; k++) {
                sums_[k] += ((ShiftTableData*)data)->m_appfRows[quadB][k][a];
            }
        }

        unsigned int count = 6;
        for (unsigned int j6 = 0; j6 < count; j6++) {
            while (((ShiftTableData*)data)->m_apiEntries[quadB][j6] == 0 && j6 < count) {
                ((ShiftTableOwner*)this)->FUN_0053abb0(quadB, j6);
                count--;
            }
        }

        for (int k = 0; k < 289; k++) {
            float total3 = 0.0f;
            for (unsigned int n = 6; n > 0; n--) {
                ((ShiftTableData*)data)->m_appfRows[quadB][k][n] =
                    ((ShiftTableData*)data)->m_appfRows[quadB][k][n - 1];
                total3 += ((ShiftTableData*)data)->m_appfRows[quadB][k][n];
            }

            ((ShiftTableData*)data)->m_appfRows[quadB][k][0] =
                Min_0040ebd0(1.0f, Max_00404010(0.0f, 1.0f - total3));

            if (sums_[k] > DAT_01012070) {
                for (unsigned int n = 6; n > 0; n--) {
                    ((ShiftTableData*)data)->m_appfRows[quadB][k][n] =
                        ((ShiftTableData*)data)->m_appfRows[quadB][k][n] / total3;
                }
            }
        }
    }
}

int __fastcall _FNV_GetFormType(TESForm*);
bool _FUN_005548a0(int);
extern int DAT_0118ac2c;
extern int _FNV_RTTI_TESObjectREFR;
struct RefPersistsH { bool GetReferencePersistence(); };
struct CellS {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v0a(); virtual void v0b();
    virtual void v0c(); virtual void v0d(); virtual void v0e();
    virtual bool CopyTopicData(void* apForm);
};
struct ChildCellS { virtual CellS* GetSaveParentCell(); };
struct LandS {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    ChildCellS child;
    bool FUN_00539060(TESForm* apGroupFORM);
};
// @fnv 0x00539060
bool LandS::FUN_00539060(TESForm* apGroupFORM)
{
    bool bretval = false;
    if (_FUN_005548a0(_FNV_GetFormType(apGroupFORM)))
    {
        ChildCellS* pchild = (ChildCellS*)FNV_DynamicCast(apGroupFORM, 0, &FNV_RTTI_TESForm, &DAT_0118ac2c, 0);
        CellS* pcell = pchild->GetSaveParentCell();
        if (pcell == child.GetSaveParentCell())
        {
            switch (_FNV_GetFormType(apGroupFORM))
            {
            case 0x3a: case 0x3b: case 0x3c: case 0x3d: case 0x3e: case 0x3f: case 0x40: case 0x69:
                {
                    RefPersistsH* pref = (RefPersistsH*)FNV_DynamicCast(apGroupFORM, 0, &FNV_RTTI_TESForm, &_FNV_RTTI_TESObjectREFR, 0);
                    if (pref && !pref->GetReferencePersistence())
                        bretval = true;
                    else
                        bretval = false;
                }
                break;
            case 0x43:
                bretval = true;
                break;
            }
        }
        else
        {
            bretval = child.GetSaveParentCell()->CopyTopicData(pcell);
        }
    }
    else
    {
        bretval = child.GetSaveParentCell()->CopyTopicData(apGroupFORM);
    }
    return bretval;
}
