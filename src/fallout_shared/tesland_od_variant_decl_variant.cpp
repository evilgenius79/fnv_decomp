
// src/fallout_shared/tesland_od_variant_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x00534ad0: the skeleton of src/fallout_shared/tesland_od_variant.cpp
// with declarations corrected to what the original code does (unit: struct TESForm { void Revert(unsigned int); }; -> struct TESForm { virtual ~TESForm(); void Revert(unsigned in). Move the function to its real unit once
// that unit declares it this way.

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
struct CellH {
    int GetCellGridX();
};
struct FUN_00533fd0_Class {
    int FUN_00533fd0();
};
struct FUN_00534050_Class {
    int FUN_00533fd0();
    float FUN_00534050();
};
struct FUN_00534080_Class {
    int FUN_00534010();
    double FUN_00534080();
};
struct TESWorldSpace;
struct DoorH { TESWorldSpace* GetParentWorldSpace(); };
struct FUN_005340b0_Class {
    int m_auiShapeKeys[8];
    DoorH* m_pDoor;
    TESWorldSpace* FUN_005340b0();
};
struct FUN_00534140_Class {
    bool FUN_00534140();
};
struct FUN_00534160_Class {
    void FUN_00534160(bool set);
};
struct FUN_005341a0_Class {
    void FUN_005341a0(bool set);
};
struct FUN_005341e0_Class {
    bool FUN_005341e0();
};
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
struct NiPoint3 { float x; float y; float z; };
struct TESForm { virtual ~TESForm(); void Revert(unsigned int); };
struct FUN_00534570_shell { char* m_pkDeltas; unsigned int stride; void FUN_00534570(unsigned int index, NiPoint3& vertex); };
template<int> struct EndianSizeTag {};
void BSEndian(int*, EndianSizeTag<2>);
void BSEndian(unsigned short*, EndianSizeTag<2>);
struct FUN_00535a60_Class {
    void FUN_00535a60();
};
extern int DAT_011c9f04;
int FUN_00535ae0();
extern "C" void __cdecl _Deallocate(void*);
struct FUN_00537100_Class {
    void __thiscall FUN_00537130();
    void* __thiscall FUN_00537100(unsigned int flags);
};
extern const char* const g_011f4aac_arg1;
struct FUN_00537ca0_class
{
    const char* const* FUN_00537ca0();
};
struct FUN_00a73080_holder { void FUN_00a73080(); };
void __cdecl operator delete(void* p, unsigned int size);
struct NiAdditionalGeometryData {
    void* FUN_00537cb0(unsigned int flags);
};
struct FUN_00540800_Class {
    void FUN_00540800();
    void FUN_00537ce0();
};
extern "C" void* g_011f4aac;
struct FUN_00537d00_Class {
    void* __thiscall FUN_00537d00();
};
struct FUN_00537d10_Class {
    void FUN_00537d40();
    void* FUN_00537d10(unsigned int flags);
    static void operator delete(void* p, unsigned int size);
};
struct QuantityData { void SetQuantity(unsigned int); };
struct TESRaceForm { void Initialize(unsigned int); };
struct TESObjectREFR { void SetFlags(unsigned int); };
struct MagicCaster { void SetSelectedMagicItem(int); };
struct TESConditionItem { void SetObjectType(int); };
struct TESQuest;
struct BGSQuestObjective { void SetOwner(TESQuest*); };
struct FUN_00537e30_cls { char _pad[24]; int _m18; int _m1c; FUN_00537e30_cls* FUN_00537e30(); };
struct FUN_00537e90 {
    unsigned int quantity;
    void SetQuantity(unsigned int value);
};
struct FUN_00538e30_class {
    void __fastcall SetVtable();
};
extern int DAT_0102e378;
struct FUN_00538e10_class {
    int* m_vtbl;
    void __fastcall FUN_00538e10();
};
struct B1 { virtual ~B1(); void* FUN_00538e80(unsigned int); };
void __cdecl FUN_00538eb0(void*);
extern "C" void __cdecl FUN_00538f20();
extern int DAT_0102e378;
struct FUN_00538ef0_class {
    void* m_ppVirtualMethodTable;
    int m_kPointA;
    int m_kPointB;
    void FUN_00538f20();
    void* FUN_00538ef0();
};
extern int DAT_0102e388;
struct FUN_00538f20 {
    int* p;
    FUN_00538f20();
};
void __cdecl FUN_00538eb0(void*);
struct FUN_00538f80 {
    void __thiscall FUN_00538fb0();
    void* __thiscall DeleteThis(unsigned int flags);
};
struct FUN_00539460_Class {
    char m_00[0x1c];
    int m_1c;
    bool FUN_00539460();
};
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
struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_011f4ab8;
struct FUN_00539fc0_Class
{
    GlobalObjectO2_00a7b610* FUN_00539fc0();
};
void __cdecl operator delete(void* p, unsigned int size);
struct FUN_0053a000 {
    void __thiscall Destruct();
};
struct FUN_00539fd0 : public FUN_0053a000 {
    void* __thiscall ScalarDeletingDestructor(unsigned int flags);
};
struct FUN_0053a070_Class {
    void __thiscall FUN_0053a070(int a, int b);
};
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
struct FUN_0053ae30_class {
    int __thiscall FUN_0053a700(unsigned char, unsigned short);
    float __thiscall FUN_0053a830(unsigned char, unsigned short, unsigned short);
    float __thiscall FUN_0053ae30(unsigned char type, unsigned short id);
};
struct GlobalObject_0044f440 {
    float* Float();
};
extern GlobalObject_0044f440 g_011c8dcc;
float FUN_0053ca40();
struct FUN_0053ca60 {
    void FUN_00b600e0();
    FUN_0053ca60* Init();
};
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
struct FUN_0053df00_Class {
    int __thiscall FUN_0053df00();
};
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
struct NiAVObject;
struct NiNode { NiAVObject* FUN_0045bc00(unsigned int); };
struct FUN_0053f120_Param { unsigned char _pad[0x18]; unsigned int idx; };
struct FUN_0053f120_Holder { unsigned char _pad[0x28]; NiNode*** fld28; NiAVObject* FUN_0053f120(FUN_0053f120_Param*); };
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
struct QueuedFile;
struct BGSTextureSet {
    void LoadTextures(int, QueuedFile*, bool);
};
struct FUN_00541540_Class {
    void FUN_00541540(int a, QueuedFile* b);
};
struct FUN_00541590_Class {
    char FUN_00541590();
};
struct S_00592cf0 { void* FUN_00592cf0(); };
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
void FUN_00538eb0(Prm* p);
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
struct FUN_0053a700_Mid {
    unsigned char pad[0x30];
    int* arr[4];
};
struct FUN_0053a700_Holder {
    unsigned char pad[0x28];
    FUN_0053a700_Mid* p;
    int FUN_0053a700(unsigned char, unsigned short);
};
extern float DAT_01015f5c;
struct FUN_0053a630_Class : public FUN_0053ae30_class {
    int FUN_0053a630(unsigned char type, unsigned short id);
};
struct A51BF0Base {
    static void* operator new(unsigned int);
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
void* FUN_00537d60_Create(unsigned int a, unsigned int b, unsigned int c, int d, int e);
struct FUN_005330d8_class
{
    void _FNV_GetObjectReference();
};
struct FUN_005331f0_class
{
    void FUN_005331f0();
};
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
class D40NiObject {
public:
    virtual ~D40NiObject();

    int m_uiRefCount;
};
class FUN_00537d40 : public D40NiObject {
public:
    virtual ~FUN_00537d40();
};
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
struct Base8ef0 { virtual void v0(); int a; int b; int c; Base8ef0(); ~Base8ef0(); };
struct MA { int x[4]; MA(); void Go(); };
struct MB { int x[3]; MB(); ~MB(); };
struct MC { int x[4]; MC(); void Fin(int); };
struct FUN_00538d70_cls : Base8ef0 {
    MA a; MB b; MC c;
    FUN_00538d70_cls();
    virtual void v0();
};
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
struct Mem960 {int value;Mem960(int,bool,const char*,int);~Mem960();};
struct Color960 {float r,g,b,a;Color960(float,float,float,float);};
struct Texture960 {Texture960* FUN_009611e0();void* FUN_00592cf0();unsigned char FUN_00541590();};
struct Property960 {virtual void v000();virtual void v004();virtual void v008();virtual void v00c();virtual void v010();virtual void v014();virtual void v018();virtual void v01c();virtual void v020();virtual void v024();virtual void v028();virtual void v02c();virtual void v030();virtual void v034();virtual void v038();virtual void v03c();virtual void v040();virtual void v044();virtual void v048();virtual void v04c();virtual void v050();virtual void v054();virtual void v058();virtual void v05c();virtual void v060();virtual void v064();virtual void v068();virtual void v06c();virtual void v070();virtual void v074();virtual void v078();virtual void v07c();virtual void v080();virtual void v084();virtual void v088();virtual void v08c();virtual void v090();virtual void v094();virtual void v098();virtual void v09c();virtual void v0a0();virtual void v0a4();virtual void v0a8();virtual void v0ac();virtual void v0b0();virtual void v0b4();virtual void v0b8();virtual void v0bc();virtual void v0c0();virtual void v0c4();virtual void v0c8();virtual void v0cc();virtual void v0d0();virtual void* vd4(void*);unsigned unk004;unsigned unk008;unsigned unk00c;unsigned unk010;unsigned unk014;unsigned unk018;unsigned unk01c;unsigned unk020;unsigned unk024;unsigned unk028;unsigned unk02c;unsigned unk030;unsigned unk034;unsigned unk038;unsigned unk03c;unsigned unk040;unsigned unk044;unsigned unk048;unsigned unk04c;unsigned unk050;unsigned unk054;unsigned unk058;unsigned unk05c;unsigned unk060;unsigned unk064;unsigned unk068;unsigned unk06c;unsigned unk070;unsigned unk074;unsigned unk078;unsigned unk07c;unsigned unk080;unsigned unk084;unsigned unk088;unsigned unk08c;unsigned unk090;unsigned unk094;unsigned unk098;unsigned unk09c;unsigned unk0a0;unsigned unk0a4;unsigned unk0a8;unsigned unk0ac;unsigned unk0b0;unsigned unk0b4;unsigned unk0b8;unsigned unk0bc;unsigned unk0c0;unsigned unk0c4;unsigned unk0c8;unsigned unk0cc;unsigned unk0d0;unsigned unk0d4;unsigned unk0d8;unsigned unk0dc;unsigned unk0e0;unsigned unk0e4;unsigned unk0e8;unsigned unk0ec;unsigned unk0f0;unsigned unk0f4;unsigned unk0f8;unsigned unk0fc;unsigned unk100;Property960();static void* operator new(unsigned);void FUN_005a8060(int);void FUN_00b68660(int,void*);void FUN_00b66640(unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,int,int,int);void FUN_00539f20(void*);};
struct Binary960 {unsigned unk00,unk04,unk08,unk0c,unk10;Binary960(unsigned,unsigned char*);static void* operator new(unsigned);};
const char* __cdecl FUN_00539f40();
struct Geometry960 {void FUN_00539ef0(void*);void FUN_00439410(Property960*);};
struct Node960 {void FUN_00a5bc40(const char*,Binary960*);Geometry960* FUN_0045bc00(unsigned);};
void* __cdecl FUN_00b54b60(Geometry960*);
void __cdecl FUN_00b57e30(Node960*,int,int);
struct Data960 {Node960** nodes;unsigned unk04,unk08;Color960** colors;unsigned unk10,unk14,unk18,unk1c;Texture960* base[4];Texture960** layers[4];unsigned char** binary[4];};
struct Host960 {unsigned unk00,unk04,unk08,unk0c,unk10,unk14,unk18,flags,unk20,unk24;Data960* data;void FUN_005394c0(bool);bool FUN_00539960();};
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
struct FUN_0053a7a0_Tbl {
    char pad[0x40];
    float** arr[4];
};
struct FUN_0053a7a0_cls {
    char pad[0x28];
    FUN_0053a7a0_Tbl* m_28;
    float FUN_0053a7a0(unsigned char a, unsigned short b);
};
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
struct PropPointer {void* FUN_00559450();};
extern PropPointer g_011ca000;
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
void FUN_00e74120();};
Renderer* FUN_0043c4b0();
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
    static void* operator new(unsigned int bytes) { return FUN_0056d280(bytes); }

};
struct FUN_00538c00_Class

{

    char __thiscall FUN_00538c00(const void* source, unsigned int size, Output538c00** result);

};
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
void* __cdecl FormHeap_Allocate(unsigned int size);
void __cdecl FormHeap_Free(void* memory);
struct LayerOwner53a940 : Owner53ace0 {
    void FUN_0053abb0(unsigned char quadrant, unsigned short layer);
    void FUN_0053a940();
};
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
struct SampleSetting { float* Float(); };
extern SampleSetting g_011c9f38;
struct IntSetting { int* Int(); };
extern IntSetting g_011c9f74,g_011c9fb8;
extern unsigned long DAT_011c9f6c;
struct TerrainOwner {
 int u00,u04,u08,u0c,u10,u14,u18,u1c,u20,u24; TerrainData* data;
 float FUN_0053a7a0(unsigned char,unsigned short);
 bool FUN_0053bc10();
};
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
#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged
int __cdecl FUN_00406d90(float fValue);

class TESFileL53 {
public:
    unsigned char GetFormType();
    void ReadData(void* pvData, unsigned int uiSize);
    bool IsBigEndian();
    unsigned int GetChunkSize();
    int GetChunkID();
    bool NextChunk();
    bool IsLoadingWorld();
    const char* GetFileName();
};

bool __cdecl IsEditorL53();
void __cdecl ResolveFormIDL53(unsigned int* puiFormID, TESFileL53* pkFile);
TESForm* __cdecl LookupFormByIDL53(unsigned int auiFormId);
int __cdecl MasterLogL53(const char* pcFormat, ...);
int __cdecl FloatToIntL53(float fValue);
void* __cdecl MemAllocL53(unsigned int uiSize);
void __cdecl MemFreeL53(void* pvMem);
void* __cdecl MemSetL53(void* pvDest, int iValue, unsigned int uiSize);
class TESLandTexture;
TESLandTexture* __cdecl GetDefaultLandTextureL53();

extern float g_afLandQuadOffsetX[4];
extern float g_afLandQuadOffsetY[4];

class TESLandTexture : public TESForm {
public:
    void AddLandRef(int iType, void* pvList);
};

struct NiPoint2L53 {
    NiPoint2L53(float fX, float fY);
    float x;
    float y;
};
struct NiPoint3L53 {
    float x;
    float y;
    float z;
    void Unitize();
};
struct NiColorAL53 {
    NiColorAL53(float fR, float fG, float fB, float fA);
    float r;
    float g;
    float b;
    float a;
};

struct SwapFloatL53 {
    void Swap();
};

struct LandRefObjectL53 {
    void DecRefCount();
    void IncRefCount();
};

struct LandDataL53 {
    unsigned int unk00;
    NiPoint3L53** m_ppVertices;
    NiPoint3L53** m_ppNormals;
    NiColorAL53** m_ppColors;
    unsigned int unk10;
    unsigned int unk14;
    NiPoint2L53 m_kHeightExtents;
    TESLandTexture* m_apBaseTextures[4];
    TESLandTexture** m_appTextures[4];
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    LandRefObjectL53* m_pkMPCD;
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
    float m_fHeightOffset;
};

struct LandTextureListL53 {
    LandTextureListL53(int iSize);
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
};
struct LandListHolderL53 {
    void* GetList();
    void SetList(LandTextureListL53* pkList);
};

struct LandBTXTL53 {
    unsigned int auiFormId;
    unsigned char ucQuadrant;
    unsigned char ucPad;
    unsigned short usLayer;
    void Swap();
};
struct LandVTXTL53 {
    unsigned short usPosition;
    unsigned short usPad;
    float fOpacity;
    void Swap();
};
struct LandVHGTL53 {
    float fProjectionAlongAim;
    signed char acHeights[0x441];
};

class TESLandL53 {
public:
    unsigned int GetFormID();
    void InitFile(TESFileL53* pkFile);
    bool IsDataLoaded();
    void SetDataLoaded(bool m_bHeaderParsed);
    void SetMPCDLoaded(bool m_bHeaderParsed);
    void SetLoading(bool abLoading);
    void PrepareData(int iFlag);
    void ProcessMPCD(char* pcData, unsigned int uiSize, LandRefObjectL53** ppkOut);
    int GetCellX();
    int GetCellY();
    void SetVertexTexture(unsigned char ucQuadrant, unsigned short usPosition, unsigned short usLayer, float fOpacity);
    void FlagError();
    bool FUN_00534ad0(TESFileL53* pkFile);

    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int m_uiValue1;
    unsigned int unk20;
    LandListHolderL53 m_kList;
    LandDataL53* m_pUserData;
};

// @fnv 0x00534ad0
bool TESLandL53::FUN_00534ad0(TESFileL53* pkFile)
{
    AutoMemContext kContext(0x1b, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESLand.cpp", 0x2c2);
    unsigned char ucFormType3 = pkFile->GetFormType();
    if (ucFormType3 != 0x42)
        return false;

    unsigned int auiFormId = GetFormID();
    InitFile(pkFile);
    int i11;
    int j;
    int iLastLayer3 = -1;
    int iLastQuadrant3 = -1;
    bool bLoadData5 = false;
    if (pkFile->IsLoadingWorld() || IsEditorL53()) {
        if (!IsDataLoaded())
            bLoadData5 = true;
    }
    if (bLoadData5)
        PrepareData(0);

    bool bError5 = false;
    do {
        switch (pkFile->GetChunkID()) {
        case 'ATAD': {
            bool bWasLoaded = IsDataLoaded();
            pkFile->ReadData(&m_uiValue1, 4);
            if (pkFile->IsBigEndian())
                reinterpret_cast<SwapFloatL53*>(&m_uiValue1)->Swap();
            SetLoading(false);
            SetDataLoaded(bWasLoaded);
            break;
        }
        case 'DCPM': {
            if (!bLoadData5)
                break;
            unsigned int uiSize = pkFile->GetChunkSize();
            char* pcData = new char[uiSize];
            pkFile->ReadData(pcData, uiSize);
            if (m_pUserData->m_pkMPCD) {
                m_pUserData->m_pkMPCD->DecRefCount();
                m_pUserData->m_pkMPCD = 0;
            }
            ProcessMPCD(pcData, uiSize, &m_pUserData->m_pkMPCD);
            if (m_pUserData->m_pkMPCD) {
                m_pUserData->m_pkMPCD->IncRefCount();
                SetMPCDLoaded(true);
            }
            delete[] pcData;
            break;
        }
        case 'TGHV': {
            if (!bLoadData5)
                break;
            LandVHGTL53 kHeights;
            if (m_uiValue1 & 1) {
                pkFile->ReadData(&kHeights.fProjectionAlongAim, 0);
                if (pkFile->IsBigEndian())
                    reinterpret_cast<SwapFloatL53*>(&kHeights.fProjectionAlongAim)->Swap();
                m_pUserData->m_kHeightExtents = NiPoint2L53(DAT_01016970, DAT_01015f5c);
                float fRowStart2 = kHeights.fProjectionAlongAim;
                float afHeights[0x441];
                for (i11 = 0; i11 < 0x441; i11++) {
                    afHeights[i11] = kHeights.acHeights[i11] + fRowStart2;
                    if ((i11 + 1) % 33 == 0)
                        fRowStart2 = afHeights[i11 - 32];
                    else
                        fRowStart2 = afHeights[i11];
                }
                for (i11 = 0; i11 < 4; i11++) {
                    int iBase = (i11 / 2) * 16 * 33 + (i11 % 2) * 16;
                    for (j = 0; j < 0x121; j++) {
                        int iCol = j % 17;
                        int iRow2 = j / 17;
                        int iIndex = iRow2 * 33 + iBase + iCol;
                        float fZ = (float)(FloatToIntL53(afHeights[iIndex]) << 3);
                        m_pUserData->m_ppVertices[i11][j].x = (float)(iCol << 7) + g_afLandQuadOffsetX[i11];
                        m_pUserData->m_ppVertices[i11][j].y = (float)(iRow2 << 7) + g_afLandQuadOffsetY[i11];
                        m_pUserData->m_ppVertices[i11][j].z = fZ;
                        if (fZ < m_pUserData->m_kHeightExtents.x)
                            m_pUserData->m_kHeightExtents.x = fZ;
                        else if (fZ > m_pUserData->m_kHeightExtents.y)
                            m_pUserData->m_kHeightExtents.y = fZ;
                    }
                }
                m_pUserData->m_fHeightOffset = (m_pUserData->m_kHeightExtents.x + m_pUserData->m_kHeightExtents.y) * 0.5f;
                for (i11 = 0; i11 < 4; i11++) {
                    for (j = 0; j < 0x121; j++)
                        m_pUserData->m_ppVertices[i11][j].z = m_pUserData->m_ppVertices[i11][j].z - m_pUserData->m_fHeightOffset;
                }
            }
            break;
        }
        case 'LMNV': {
            if (!bLoadData5)
                break;
            if (m_uiValue1 & 1) {
                signed char acNormals[0x441 * 3];
                pkFile->ReadData(acNormals, 0);
                for (i11 = 0; i11 < 4; i11++) {
                    int iBase = (i11 / 2) * 16 * 33 + (i11 % 2) * 16;
                    for (j = 0; j < 0x121; j++) {
                        int iIndex = j / 17 * 33 + iBase + j % 17;
                        m_pUserData->m_ppNormals[i11][j].x = (float)acNormals[iIndex * 3] / 127.0f;
                        m_pUserData->m_ppNormals[i11][j].y = (float)acNormals[iIndex * 3 + 1] / 127.0f;
                        m_pUserData->m_ppNormals[i11][j].z = (float)acNormals[iIndex * 3 + 2] / 127.0f;
                        m_pUserData->m_ppNormals[i11][j].Unitize();
                    }
                }
            }
            break;
        }
        case 'RLCV': {
            if (!bLoadData5)
                break;
            if (m_uiValue1 & 2) {
                unsigned char aucColors[0x441 * 3];
                pkFile->ReadData(aucColors, 0);
                for (i11 = 0; i11 < 4; i11++) {
                    int iBase = (i11 / 2) * 16 * 33 + (i11 % 2) * 16;
                    for (j = 0; j < 0x121; j++) {
                        int iIndex = j / 17 * 33 + iBase + j % 17;
                        m_pUserData->m_ppColors[i11][j] = NiColorAL53((float)(aucColors[iIndex * 3] / 255.0),
                            (float)(aucColors[iIndex * 3 + 1] / 255.0), (float)(aucColors[iIndex * 3 + 2] / 255.0), 1.0f);
                    }
                }
            }
            break;
        }
        case 'TXTB': {
            if (!bLoadData5)
                break;
            LandBTXTL53 kBTXT;
            MemSetL53(&kBTXT, 0, 8);
            pkFile->ReadData(&kBTXT, 8);
            if (pkFile->IsBigEndian())
                kBTXT.Swap();
            ResolveFormIDL53(&kBTXT.auiFormId, pkFile);
            m_pUserData->m_apBaseTextures[kBTXT.ucQuadrant] = dynamic_cast<TESLandTexture*>(LookupFormByIDL53(kBTXT.auiFormId));
            if (!m_pUserData->m_apBaseTextures[kBTXT.ucQuadrant]) {
                MasterLogL53("MASTERFILE: Land (%i, %i) unable to find base texture ID (%08X) for block %i.", GetCellX(), GetCellY(), kBTXT.auiFormId, kBTXT.ucQuadrant);
                bError5 = true;
            } else {
                if (!m_kList.GetList())
                    m_kList.SetList(new LandTextureListL53(5));
                TESLandTexture* pkTexture = m_pUserData->m_apBaseTextures[kBTXT.ucQuadrant];
                pkTexture->AddLandRef(5, m_kList.GetList());
            }
            break;
        }
        case 'TXTA': {
            if (!bLoadData5)
                break;
            else {
            LandBTXTL53 kATXT;
            MemSetL53(&kATXT, 0, 8);
            pkFile->ReadData(&kATXT, 8);
            if (pkFile->IsBigEndian())
                kATXT.Swap();
            if (kATXT.usLayer > 5) {
                MasterLogL53("MASTERFILE: Land (%i, %i) clamping invalid index %i for block %i.", GetCellX(), GetCellY(), kATXT.usLayer, kATXT.ucQuadrant);
                kATXT.usLayer = 5;
                bError5 = true;
            }
            TESLandTexture* pkTexture = 0;
            if (kATXT.auiFormId) {
                ResolveFormIDL53(&kATXT.auiFormId, pkFile);
                pkTexture = dynamic_cast<TESLandTexture*>(LookupFormByIDL53(kATXT.auiFormId));
                if (!pkTexture) {
                    MasterLogL53("MASTERFILE: Land (%i, %i) unable to find additional texture ID (%08X) for block %i.", GetCellX(), GetCellY(), kATXT.auiFormId, kATXT.ucQuadrant);
                    bError5 = true;
                }
            } else {
                pkTexture = GetDefaultLandTextureL53();
            }
            m_pUserData->m_appTextures[kATXT.ucQuadrant][kATXT.usLayer] = pkTexture;
            if (pkTexture) {
                if (!m_kList.GetList())
                    m_kList.SetList(new LandTextureListL53(5));
                pkTexture->AddLandRef(5, m_kList.GetList());
            }
            iLastQuadrant3 = kATXT.ucQuadrant;
            iLastLayer3 = kATXT.usLayer;
            }
            break;
        }
        case 'TXTV': {
            if (!bLoadData5)
                break;
            if (iLastQuadrant3 >= 0 && iLastLayer3 >= 0) {
                unsigned int uiSize = pkFile->GetChunkSize();
                if (uiSize % 8 == 0) {
                    LandVTXTL53* pkVTXT = static_cast<LandVTXTL53*>(operator new[](uiSize));
                    pkFile->ReadData(pkVTXT, uiSize);
                    unsigned int ItemUpdateArray = uiSize >> 3;
                    for (unsigned int k = 0; k < ItemUpdateArray; k++) {
                        if (pkFile->IsBigEndian())
                            pkVTXT[k].Swap();
                        if (pkVTXT[k].fOpacity > 1.0)
                            pkVTXT[k].fOpacity = pkVTXT[k].fOpacity / 100.0;
                        SetVertexTexture(iLastQuadrant3, pkVTXT[k].usPosition, iLastLayer3, pkVTXT[k].fOpacity);
                    }
                    operator delete[](pkVTXT);
                    pkVTXT = 0;
                } else {
                    MasterLogL53("MASTERFILE: Land (%i, %i) found unrecognized vertex texture data in file %s.", GetCellX(), GetCellY(), pkFile->GetFileName());
                    bError5 = true;
                }
            }
            iLastQuadrant3 = -1;
            iLastLayer3 = -1;
            break;
        }
        }
    } while (pkFile->NextChunk());

    if (bError5)
        FlagError();
    SetLoading(bLoadData5);
    return true;
}
