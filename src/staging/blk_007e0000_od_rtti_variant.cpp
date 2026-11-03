
// src/staging/blk_007e0000_od_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (Menu, Tile). The skeleton of src/staging/blk_007e0000_od.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

// src/staging/blk_007e0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
const char* __cdecl FUN_007ab810();
struct FUN_007e6760_cls
{
    bool __thiscall FUN_007e6760();
};
struct BSAudio_
{
    void FUN_00ad8510(int, int);
    void FUN_007eb8a0();
};
extern "C" void __cdecl FUN_007004e0();
struct FUN_007f7770_Class
{
    void __thiscall FUN_007004e0();
    void __thiscall FUN_007f7770();
};
extern float DAT_012007d0;
extern float DAT_012007d4;
extern char DAT_011ae5d4;
void __cdecl FUN_007f7a50(float a, float b);
struct FOPipboyManager
{
    void InitializeMenuLight();
    void FUN_007fa200();
};
struct Flt
{
    operator unsigned int();
};
struct FUN_007fa970_Class
{
    unsigned int FUN_007fa970();
};
struct GO
{
    void* operator=(void*);
};
struct FUN_007fd620_Class
{
    char _0[0x24];
    GO m_go;
    void SetGo(void* p);
};
struct RaceSexMenu
{
    void OnRaceSelected(void*);
    void FUN_007fe910(void* apList);
};
struct NavMeshPtr
{
    void* FUN_00458b50();
};
struct BSStr
{
    bool Set(const char*, unsigned int);
};
extern BSStr g_011daed8;
void __cdecl FUN_007e65b0();
struct FUN_007e66a0_cls
{
    char _0[0x28];
    void __thiscall FUN_007e66a0(int a, int b);
};
void __cdecl DestroyList(void*);
struct FUN_007f69d0_Class
{
    void __thiscall DestroyList();
    void* __thiscall FUN_007f69d0(unsigned int flags);
};
struct GameTimerRecord
{
    unsigned int GetTime() const;
};
extern GameTimerRecord g_timeGlobal;
struct FUN_007f7880_Class
{
    unsigned char _0[0x28];
    unsigned char bActive;
    unsigned char _1[3];
    float f5;
    float f2;
    float f3;
    float f4;
    float f6;
    float f8;
    float f9;
    float f10;
    void __thiscall FUN_007f7880(float a, float b, float c);
};
struct ModelLoader
{
    void QueueModelLoad(char*, bool, unsigned int);
};
struct Loader_S
{
    void* m_p;
    ModelLoader* operator->();
};
extern Loader_S* g_modelLoader;
extern int DAT_011a0bb0;
extern Flt g_011db63c;
void FUN_007ffe00();
struct FUN_007e0e30_Class
{
    void* m_p;
    void* m_sub;
    void FUN_007e0e30(bool(__cdecl* fn)(void*, unsigned int), unsigned int v);
};
struct FUN_007f7830_Class
{
    char _0[0x28];
    unsigned char bActive;
    void __thiscall UpdateFalloff(float);
    void __thiscall UpdateIfActive();
};
struct FUN_007fecc0_Class
{
    unsigned char _0[0x158];
    unsigned char bActive;
    unsigned char _1[3];
    float fTime;
    float fValue;
    void __thiscall FUN_007fecc0();
};
struct FUN_007eb8d0_Class
{
    char _0[0x28];
    bool __thiscall HasAllSlotsSet(int* p);
};
struct Tile
{
    virtual ~Tile();  // the original class is polymorphic (rtti_variants.py)
    void __thiscall Set(int, int);
};
struct Menu
{
    virtual ~Menu();  // the original class is polymorphic (rtti_variants.py)
    void __thiscall LoadMenuData();
};
struct SimpleList
{
    SimpleList* __thiscall GetNext();
};
extern SimpleList* DAT_011daec4;
void FUN_007e65b0();
struct ListX
{
    ~ListX();
};
struct FUN_007f6a00_Class
{
    char _0[8];
    ListX l;
    void __thiscall DestroyList();
};
struct NiPoint2
{
    float x;
    float y;
};
extern NiPoint2 DAT_011f4980;
struct FUN_007f78f0_Class
{
    unsigned char _0[0x28];
    unsigned char bActive;
    unsigned char _1[3];
    float fTime;
    NiPoint2 f2;
    NiPoint2 f4;
    NiPoint2 f6;
    NiPoint2 f8;

    void __thiscall InitFromPoints(const NiPoint2* a, const NiPoint2* b, const NiPoint2* c);
};
struct FUN_007e0d80_shell : Flt
{
    char* m_buffer;
    unsigned int FUN_004048e0();
    unsigned int FUN_004039a0();
    void FUN_004037f0(char* oldBuffer, unsigned int requiredLength);
    void FUN_004039c0(unsigned int newLength);
    unsigned int GetLengthPlusOne();
    void FUN_00438470(FUN_007e0d80_shell* other);
    FUN_007e0d80_shell* AppendString(FUN_007e0d80_shell* other);
};
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
int FUN_007e1970();
int __cdecl FUN_007e65a0();
struct SysMgr
{
    void Init(int a, int b);
};
struct TaskA
{
    virtual int Run(int a);
};
struct MgrB
{
    TaskA* GetTask();
};
void Fn7f6920();
extern SysMgr* g_sysMgr;
extern MgrB* g_mgrB;
class Base
{
  public:
    virtual ~Base();
};
class MemA
{
  public:
    ~MemA();
};
class MemB
{
  public:
    ~MemB();
};
class FUN_007e9130_cls : public Base
{
  public:
    virtual ~FUN_007e9130_cls();
    int unk0004;
    int unk0008;
    int unk000C;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001C;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002C;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003C;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004C;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005C;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006C;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007C;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008C;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009C;
    int unk00A0;
    int unk00A4;
    int unk00A8;
    int unk00AC;
    MemA m_b0;
    int unk00B4;
    int unk00B8;
    int unk00BC;
    int unk00C0;
    int unk00C4;
    int unk00C8;
    int unk00CC;
    int unk00D0;
    int unk00D4;
    int unk00D8;
    int unk00DC;
    int unk00E0;
    int unk00E4;
    int unk00E8;
    int unk00EC;
    int unk00F0;
    int unk00F4;
    int unk00F8;
    int unk00FC;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010C;
    int unk0110;
    int unk0114;
    int unk0118;
    MemB m_11c;
};
extern unsigned int* DAT_011f4aa8;
float __cdecl FastSqrt(const float* v);
int __cdecl FUN_007eb8c0();
class B7F7790Ref
{
  public:
    ~B7F7790Ref();
    void Reset(void* pvObject);

    void* m_pvObject;
};
class B7F7790List
{
  public:
    ~B7F7790List();

    int unk00;
};
class B7F7790Object
{
  public:
    virtual ~B7F7790Object();
};
class FUN_007f7790_cls
{
  public:
    ~FUN_007f7790_cls();

    B7F7790Ref m_kRef;
    B7F7790List m_kList;
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
    B7F7790Object* m_pPointer;
};
class NiColor;
struct ImageSpaceEffectParam
{
    float unk00;
    float unk04;
    float unk08;
    float unk0C;
    ImageSpaceEffectParam(float a, float b, float c, float d);
};
struct Dummy_00718c90;
struct SystemColorManager
{
    bool GetColor(int id, NiColor& out);
};
Dummy_00718c90* __cdecl FUN_00718b60();
struct PipboyStub : FOPipboyManager
{
    void SetQuad(ImageSpaceEffectParam* p);
    void FUN_007f7fb0(ImageSpaceEffectParam* p);
    void FUN_007f7f40();
};
struct FUN_007f7fb0_Value
{
    unsigned int field00;
    unsigned int field04;
    unsigned int field08;
    unsigned int field0C;
};
struct FUN_007f7fb0_Class
{
    unsigned char unk00[0xC0];
    FUN_007f7fb0_Value unkC0;

    void __thiscall FUN_007f7fb0(const FUN_007f7fb0_Value* value);
};
struct Quad4
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
};
struct FUN_007f7fe0_cls
{
    unsigned char _0[0xa8];
    Quad4 m_q;
    void __thiscall SetQuad(const Quad4* src);
};
struct SoundPlaybackHandle
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    SoundPlaybackHandle();
    SoundPlaybackHandle& operator=(const SoundPlaybackHandle&);
    ~SoundPlaybackHandle();
};
struct BSSoundHandleEx
{
    SoundPlaybackHandle base;
    ~BSSoundHandleEx();
    bool Play(bool);
};
struct BSAudio
{
    static BSAudio* GetSingleton();
    BSSoundHandleEx GetSoundHandleByEditorID(const char*, unsigned int);
};
struct GlobalObject_0044f440
{
    float* Float();
};
extern GlobalObject_0044f440 g_011db288;
extern bool g_burstSoundEnabled;
struct FUN_007fa0f0_Class
{

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

    float unk120;

    float unk124;

    float unk128;

    float unk12c;

    float values[1];

    void __thiscall SetValue(int index, bool play);
};
struct FUN_007fb730_Class
{
    float x;
    float y;
    float z;

    FUN_007fb730_Class* __thiscall Add(FUN_007fb730_Class* output, const FUN_007fb730_Class* input);
};
class NiBound7FD
{
  public:
    float GetRadius() const;
};
class NiAVObject7FD
{
  public:
    const NiBound7FD& GetBoundingVolume() const;
};
template <class T> class NiPointer7FD
{
  public:
    T* Get() const;

    T* m_pObject;
};
class ShadowSceneNode7FD
{
  public:
    void GetShadowSceneLight(NiAVObject7FD* pkLight, float fRadius);
};
ShadowSceneNode7FD* __cdecl FUN_00450b80(unsigned int uiIndex);
class Light7FD
{
  public:
    void FUN_007fd660(float fScale);

    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C;
    int unk020, unk024, unk028, unk02C, unk030, unk034, unk038, unk03C;
    int unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    int unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C;
    int unk080, unk084, unk088, unk08C, unk090, unk094, unk098, unk09C;
    int unk0A0, unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC;
    int unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC;
    int unk0E0, unk0E4, unk0E8, unk0EC, unk0F0, unk0F4, unk0F8;
    NiPointer7FD<NiAVObject7FD> m_spNode;
    NiPointer7FD<NiAVObject7FD> m_spLight;
};
struct NiNode;
template <class T> class NiPtrS
{
  public:
    T* m_pObject;
    ~NiPtrS();
    NiPtrS<T>& operator=(T* object);
};
class FUN_007fad10
{
  public:
    virtual ~FUN_007fad10();
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
};
class FUN_007fed10 : public FUN_007fad10
{
  public:
    NiPtrS<NiNode> m_spA[4];
    NiPtrS<NiNode> m_spB[4];
    NiPtrS<NiNode> m_sp0;
    NiPtrS<NiNode> m_sp1;
    NiPtrS<NiNode> m_sp2;
    NiPtrS<NiNode> m_sp3;
    NiPtrS<NiNode> m_sp4;
    NiPtrS<NiNode> m_sp5;
    virtual ~FUN_007fed10();
};
struct Entry;
struct ValueX
{
    void Clear();
    void Copy(int, void*, int);
    void SetFloat(int, float);
    void Finish(int);
};
struct MenuX
{
    struct TileX* Create(struct TileX*, const char*, int);
};
struct TileX
{
    MenuX* GetMenu();
    void* GetValue(int);
    void Set(int, int);
    void Set(int, const char*, bool);
    float GetFloat(int);
    ValueX* GetAction(int);
};
struct Entry
{
    TileX* tile;
    int data;
    int extra;
    Entry(TileX*, int*);
};
struct Entries
{
    Entry* first;
    Entries* next;
    void Insert(Entry*, void*);
    void AddTail(Entry* const&);
};
int GetTrait(const char*, int);
struct ListOwner
{
    int unk00;
    Entries entries;
    TileX* parent;
    int unk10;
    int unk14;
    const char* templateName;
    unsigned short count;
    bool Test(unsigned int);
    void Refresh();
    void Select(TileX*);
    void Update();
    int Mode();
    TileX* FUN_007e0e70(int data, const char* text, void* compare, const char* name);
};
struct WXObject;
template <class T> struct WXPointer
{
    T* m_pObject;

    WXPointer(T* apObject);
    ~WXPointer();
    WXPointer& operator=(T* apObject);
};
struct WXPoint3
{
    float x;
    float y;
    float z;

    WXPoint3(float afX, float afY, float afZ);
};
struct WXParam
{
    float fA;
    float fB;
    float fC;
    float fD;

    WXParam(float afA, float afB, float afC, float afD);
};
struct WXTimeGlobal
{
    unsigned int GetTime();
};
struct WXIntSetting
{
    int* Int();
};
struct WXFloatSetting
{
    float* Float();
};
int __cdecl WXRand();
extern WXTimeGlobal g_kWXTimeGlobal;
extern WXIntSetting g_kWXRandomRange;
extern WXFloatSetting g_kWXDuration;
struct FUN_007faa20
{
    WXPointer<WXObject> spObject04;
    WXPointer<WXObject> spObject08;
    WXPointer<WXObject> spObject0C;
    WXPointer<WXObject> spObject10;
    WXPointer<WXObject> spObject14;
    int iValue18;
    WXPointer<WXObject> spObject1C;
    int iValue20;
    WXPointer<WXObject> spObject24;
    bool bFlag28;
    bool bFlag29;
    bool bFlag2A;
    WXPoint3 kPoint2C;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    char unk4C;
    bool bFlag4D;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    bool bFlag60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    bool bFlag74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    float fValue8C;
    float fValue90;
    bool bFlag94;
    bool bFlag95;
    int unk98;
    int unk9C;
    float fDurationA0;
    float fTimeA4;
    WXParam kParamA8;
    bool bFlagB8;
    bool bFlagB9;
    WXPointer<WXObject> spObjectBC;
    WXParam kParamC0;
    int unkD0;
    WXPointer<WXObject> spObjectD4;

    FUN_007faa20();
    virtual ~FUN_007faa20();
};
struct Accum
{
    static void* operator new(unsigned int);
    static void operator delete(void*);
    Accum(int, unsigned int, unsigned int);
    void SetEnabled(bool);
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
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
};
struct Ref
{
    void* object;
    Ref(void* = 0);
    ~Ref();
    Ref& operator=(void*);
    operator Accum*() const;
};
struct Pair
{
    int value;
    Ref node;
    Pair();
    ~Pair();
};
struct FloatSetting
{
    float* Float();
};
struct IntSetting
{
    int* Int();
};
struct StringSetting
{
    const char* String();
};
extern FloatSetting g_011db6bc;
extern IntSetting g_011db75c;
extern StringSetting g_011db744;
extern "C" int __cdecl rand();
void __cdecl LoadTexture(const char*, bool, Ref&, bool, bool);
struct FUN_007ffec0
{
    int unk000;
    Pair first;
    int unk00c;
    int unk010;
    Pair entries[32];
    Ref unk114;
    bool unk118;
    bool active[16];
    bool unk129;
    short unk12a;
    int values[16];
    int states[16];
    bool flags[16];
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    bool unk284;
    char unk285;
    short unk286;
    int unk288;
    float unk28c;
    float unk290;
    float unk294;
    bool unk298;
    char unk299;
    short unk29a;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    float unk2ac;
    float unk2b0;
    bool unk2b4;
    bool unk2b5;
    short unk2b6;
    int unk2b8;
    int unk2bc;
    float unk2c0;
    Ref unk2c4;
    int unk2c8;
    Ref unk2cc;
    FUN_007ffec0();
};
struct RemoveTile
{
    virtual void* Destroy(unsigned int);
    float FUN_00a011b0(int);
    void FUN_00a012d0(int, float, bool);
};
struct RemoveOwned
{
    void* FUN_004459e0(unsigned int);
};
struct RemoveData
{
    RemoveTile* tile;
    RemoveOwned* owned;
    bool filtered;
};
struct RemoveNode
{
    RemoveData* data;
    RemoveNode* next;
    RemoveData** FUN_006815c0();
    RemoveNode* FUN_00726070();
    void FUN_006ecd40(RemoveNode*);
    void* FUN_004702f0(unsigned int);
};
struct RemoveInterface
{
    void FUN_00715860(RemoveTile*, int, bool);
};
RemoveInterface* FUN_004b7210();
int TraitNameToID(const char*);
void FormHeap_Free(void*);
struct RemoveBase
{
    int unk00;
};
struct RemoveView : RemoveBase, RemoveNode
{
    RemoveTile* container;
    RemoveTile* selected;
    bool FUN_007242c0(bool);
    void FUN_00726090();
    bool RemoveNodeFromList(RemoveNode*, RemoveNode*);
};
