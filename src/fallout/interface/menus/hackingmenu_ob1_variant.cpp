
// src/fallout/interface/menus/hackingmenu_ob1_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/fallout/interface/menus/hackingmenu.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/interface/menus/hackingmenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/hackingmenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_006ffe80_shell
{
    int x;
    int y;
    int a;
    int b;
    void FUN_006ffe80(int a, int b);
};
struct HackingMenu
{
    int __thiscall FUN_00765870();
};
int __cdecl FUN_00766a40();
struct WeatherEntry;
struct BSSimpleList
{
    void __thiscall Sort(int(__cdecl*)(WeatherEntry*, WeatherEntry*));
};
int __cdecl FUN_0076b2e0(WeatherEntry*, WeatherEntry*);
struct FUN_007687b0_shell : BSSimpleList
{
    void SortWeatherEntries();
};
char MaxByte(unsigned char a, unsigned char b);
extern "C" unsigned int __cdecl FUN_005a00a0(unsigned int);
unsigned int __cdecl FUN_0076b2e0();
struct InterfaceManager
{
    static float __cdecl UpdateInterfaceState();
    int FUN_00747d00();
};
unsigned int __cdecl gm_GetTickCount();
struct HackingMenu;
struct FUN_0076a510_shell : HackingMenu
{
    void __thiscall FUN_0076a510();
    void __thiscall FUN_0076a540();
};
struct StrMem
{
    StrMem();
    ~StrMem();
    void __thiscall FUN_006ffe10();
};
struct FUN_00726c90 : StrMem
{
    FUN_00726c90();
};
struct ListX
{
    ~ListX();
};
struct FUN_00765810 : ListX
{
    void __thiscall FreeAll();
    ~FUN_00765810();
};
void __cdecl Deallocate(void* p);
struct FUN_0076b560_shell
{
    void __thiscall FUN_0076b560();
    void* __thiscall FUN_00765b50(unsigned int flags);
};
void __cdecl UpdateD766AA0Menu();
struct FUN_00767b80_shell
{
    bool __thiscall HandleButton10(int, float);
};
struct T7021b0
{
    int __thiscall DestroyOrFree(int);
};
struct C7687d0
{
    void __thiscall FUN_007687d0();
};
extern "C" void __cdecl _Deallocate(void*);
struct FUN_00768920_shell
{
    void* p;
    void* q;
    void __thiscall FUN_00768920(void* n);
};
unsigned int __cdecl FUN_0042f5a0(unsigned int, unsigned int);
unsigned int __cdecl BSStringLength(const char*);
struct FUN_00768a10_shell : HackingMenu
{
    unsigned int __thiscall CountMatchingChars(const char* a, const char* b);
};
struct FUN_007694f0_shell
{
    void __thiscall FUN_00726c90();
    int __thiscall FUN_007694f0();
};
struct Struct0076ae30
{
    unsigned char* buf;
    unsigned int cnt;
    int __thiscall FindByteIndices(int, unsigned char*);
};
struct Struct0076b090
{
    int field0;
    void __thiscall CopyFrom(int);
    Struct0076b090* __thiscall Construct(int);
};
void* __cdecl __memcpy(void*, const void*, unsigned int);
struct STR_0076b200
{
    void* f0;
    unsigned int f4;
    void FUN_00768920(unsigned int);
    STR_0076b200* AssignFrom(STR_0076b200*);
};
unsigned int __cdecl BSStringLength(char const*);
struct TaskQueueInterface
{
    static void __cdecl CopyStringToBuffer(char*, unsigned int, char const*);
};
struct G2
{
    void AddHead(int*);
};
struct FUN_0076b240_shell
{
    void __thiscall FUN_0076b240(const char* s);
};
struct Tile
{
    void __thiscall Set(int, int);
};
struct FUN_00759f20_holder
{
    void __thiscall AssignString(int);
};
struct FUN_00768020_holder
{
    char _pad0[0xE0];
    FUN_00759f20_holder _anim;
    char _pad1[0x114 - 0xE0 - 1];
    Tile* _tile;
    void __thiscall FUN_00768020();
};
int __cdecl FUN_004dc1f0(void);
struct MyHack
{
    unsigned char _pad0[0x4AC];
    float f4AC;
    unsigned char _pad1[0x20];
    float f4D0;
    float __thiscall FUN_007697f0();
};
struct FUN_00768970_shell
{
    void __thiscall FormatHexWord(unsigned short v, char* dst);
};
struct TGF
{
    float __thiscall GetFloat(int value) const;
};
struct TileHelper
{
    bool __thiscall ContainsTrait(int value);
};
struct FUN_00767bb0_entry
{
    unsigned char _pad[0x2c];
    TGF* value;
};
struct FUN_00767bb0_shell
{
    unsigned char _pad[0x28];
    FUN_00767bb0_entry* entries[46];

    TGF* __thiscall FUN_00767bb0(unsigned int a, unsigned int b);
};
void* __cdecl operator new(unsigned int);
struct FUN_00702220
{
    void* pData;
    unsigned int ItemUpdateArray;
    ~FUN_00702220();
};
struct SL : public FUN_00702220
{
    SL();
};
FUN_00702220::~FUN_00702220()
{}
SL::SL()
{}
struct FUN_00768810
{
    STR_0076b200* pItems;
    unsigned int uiSize;

    FUN_00768810(unsigned int aiSize);
};
struct FUN_007021b0_cls
{
    void FUN_00702220();
    void* DestroyOrFree(unsigned int flags);
};
extern "C" void __stdcall FUN_00ec5fce(void* object, int elementSize, int count, void (FUN_007021b0_cls::*callback)());
extern "C" void __cdecl FormHeap_Free(void* apMemory);
class NiNode;
class TileD766
{
  public:
    NiNode* FUN_0056c7f0();
    void SetInt(int m_uiSoundID, int iValue);
};
class TileNU
{
  public:
    void Set(int m_uiSoundID, float fValue, bool bPropagate);
};
class FORenderedMenu
{
  public:
    virtual ~FORenderedMenu();
};
class FORenderedTerminal : public FORenderedMenu
{
  public:
    void FUN_007ffaf0();
};
class BSAudio
{
  public:
    NiNode* GetSynchTime();
};
class InterfaceManager;
class FUN_00766aa0_Menu
{
  public:
    TileNU* GetTile();
    void FUN_00a1d910();
};
FORenderedMenu* __fastcall FUN_00707af0(InterfaceManager* pkManager);
void __cdecl FUN_007ffe40();
unsigned int __cdecl gm_GetTickCount();
extern const float runtimeFloatSettingDefault987;
extern FUN_00766aa0_Menu* g_pkD766AA0Menu;
extern InterfaceManager* g_pkD766AA0InterfaceManager;
extern unsigned int g_uiD766AA0CloseTime;
void __cdecl UpdateD766AA0Menu();
extern int DAT_010729c8;
struct ValueRow
{
    float __thiscall FUN_00a011b0(unsigned int key, unsigned int mode);
    void __thiscall FUN_00a012d0(unsigned int key, float value);
    void __thiscall FUN_00715c60(unsigned int key, unsigned int value);
    void __thiscall FUN_00a01350(unsigned int key, unsigned int value, unsigned int mode);
};
struct EntryListNode
{
    int __thiscall FUN_00559450();
    ValueRow** __thiscall FUN_0057cbe0(int* iterator);
    void __thiscall FUN_004ed8c0(ValueRow** item);
};
struct FUN_00767ef0_shell
{
    ValueRow* __thiscall AddTileFromTemplate(void* owner, int* descriptor, unsigned int mode);
    void __thiscall AddValueRows(unsigned int count, const unsigned int* values);
};
struct Entry
{
    unsigned char* data;
    unsigned int count;
    int FUN_0076ae90();
    int FindByteIndices(unsigned int index, unsigned char* result);
};
struct FUN_007687d0
{
    Entry* entries;
    unsigned int count;
    ~FUN_007687d0();
    unsigned int FUN_00726070();
    Entry* FUN_00559450();
    FUN_007687d0 FUN_0076af90(unsigned char* result, int j);
};
unsigned int __cdecl FUN_00403940(unsigned int a, unsigned int b);
unsigned int __cdecl FUN_0042f5a0(unsigned int a, unsigned int b);
struct Context
{
    unsigned int FUN_00769520(FUN_007687d0* input);
};
void __cdecl UnkCallA();
bool __cdecl UnkCallB();
extern const double g_dConst;
struct GameCc
{
    float __thiscall UnkGetA();
    float __thiscall UnkGetB(int v);
};
struct GameRoot
{
    unsigned char _pad0[0xcc];
    GameCc* m_cc;
    bool __thiscall UnkTestA();
    float __thiscall UnkGetC();
    int __thiscall UnkGetD();
};
extern GameRoot* g_pGame;
struct FUN_00769700_cls
{
    unsigned char _pad0[0x1cc];
    int m_1cc;
    int GetScaledValue();
};
unsigned int __cdecl gm_GetTickCount();
extern double _gModifierZero;
struct TileV
{
    float __thiscall GetFloat(int id);
    float __thiscall GetWidth();
    void __thiscall SetFloat(int id, float value, bool propagate);
    void __thiscall SetInt(int id, int value);
};
struct SoundHandleV
{
    bool __thiscall Play(bool loop);
};
struct HackingMenuV
{
    int unk00;
    TileV* tile04;
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
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    TileV* tile120;
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
    SoundHandleV sound150;
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
    unsigned int amount1B8;
    int unk1BC;
    int unk1C0;
    int state1C4;
    int unk1C8;
    int unk1CC;
    unsigned int nextTick1D0;

    void FUN_0076a3f0();
};
extern int DAT_011a0104;
extern char* DAT_011a0100;
int __cdecl FUN_00ec7690(int, int);
int __cdecl FUN_00ec86e1(int);
void __cdecl FUN_00401460(int, const char*, int);
struct FUN_0076a670_cls
{
    void FUN_0076a670(int a1, const char* s);
};
extern "C" unsigned int __cdecl FUN_00457fe0();
extern "C" int __cdecl TraitNameToIDAdd(const char*, int);
extern "C" char str_01072108;
struct Fade
{
    int state;
    int flags;
    float amount;
    void __thiscall FUN_00a0a270(float value, int enabled);
};
struct Resources
{
    float __thiscall FUN_00a011b0(int id);
    Fade* __thiscall FindTraitValue(int id);
};
struct Widget
{
    bool __thiscall IsTraitNonZero();
};
struct HackingMenuDecomp : HackingMenu
{
    Widget* __thiscall FUN_00726070(int id);
    void __thiscall UpdateFade();
};
struct Node
{
    bool __thiscall IsTraitNonZero(int property);
    Node* __thiscall FUN_00a011f0(int property);
    Node* __thiscall FUN_0045cd60();
    void __thiscall FUN_00a011b0(int property);
    void __thiscall FUN_00700320(int property, int value);
};
extern int __cdecl FUN_0044a670(Node* node);
extern int __cdecl FUN_00ec62c0();
struct Menu0076ab40
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
    Node* active;
    Node* root;
    void __thiscall UpdateActiveNodeProperty();
};
// BuildHackingGuessTemplate - hacking menu guess template formatting
struct FUN_00a1ddb0_res
{
    void __thiscall FUN_00715c60(unsigned int id, int cnt);
    int __thiscall FUN_00700300();
    void __thiscall FUN_00707e10(int len);
};
struct FUN_00a1ddb0_owner
{
    FUN_00a1ddb0_res* __thiscall AddTileFromTemplate(char* base, char const* name, void* f0);
};
extern FUN_00a1ddb0_owner* DAT_011d95b8;
struct FUN_0044ddc0_sub
{
    int __thiscall FUN_0044ddc0();
    void __thiscall FUN_004ed8c0(FUN_00a1ddb0_res** pp);
};
class FUN_004037b0_tmp
{
  public:
    int m_00;
    int m_04;
    FUN_004037b0_tmp();
    ~FUN_004037b0_tmp();
    int __thiscall FUN_00559450();
};
void __cdecl FUN_00406f60(void* dest, char const* fmt, ...);
struct FUN_0076ad50_cls
{
    unsigned char _pad0[0x110];
    char* m110;
    unsigned char _pad1[0x174 - 0x110 - 4];
    FUN_0044ddc0_sub m174;
    void BuildHackingGuessTemplate();
};
struct FUN_0076ae90_cls
{
    unsigned char* buf;
    unsigned int cnt;
    unsigned int __thiscall FUN_0076ae90();
};
void* __cdecl FUN_00403d30(void*, int, unsigned int);
struct FUN_0076ae90_tbl
{
    unsigned int cap;
    unsigned char table[0x20];
};
struct ArrElem
{
    void* f0;
    unsigned int f4;
    ArrElem();
    ~ArrElem();
    ArrElem* AssignFrom(ArrElem* src);
};
struct ElemArray
{
    ArrElem* pItems;
    unsigned int uiSize;

    ElemArray* CopyFrom(ElemArray* src);
};
struct MenuBase
{
    MenuBase();
    virtual ~MenuBase();
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
};
struct AnimState
{
    AnimState();
    ~AnimState();
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
};
struct Sound
{
    int id;
    int state;
    int flags;
    Sound();
    ~Sound();
    Sound& operator=(const Sound&);
};
struct ListState
{
    int a;
    int b;
    int c;
    ListState();
    ~ListState();
};
struct PairState
{
    int a;
    int b;
    PairState();
    ~PairState();
};
struct AudioManager
{
    static AudioManager* Get();
    Sound GetSoundByEditorID(const char*, int);
};
void* __cdecl FUN_00403d30(void*, int, unsigned int);
struct FUN_007654f0 : MenuBase
{
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
    AnimState anim;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    Sound sounds[5];
    ListState list168;
    ListState list174;
    PairState pair180;
    ListState list188;
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
    char unk1D8;
    char unk1D9;
    char unk1DA;
    FUN_007654f0();
    virtual ~FUN_007654f0();
};
static const char scrollSound[] = "UIHackingCharScroll";
struct ScriptObj
{
    virtual int Call0(int);
};
struct ListM
{
    int f00;
    int f04;
    int f08;
    ~ListM();
    bool FUN_0076b610();
    ScriptObj* RemoveHead();
};
struct EntObj
{
    void* FUN_00765b50(unsigned int);
};
struct ObjE0
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
    ~ObjE0();
};
struct SndX
{
    void Stop();
    void FUN_00ad8d10();
};
struct BSSoundHandleEx : SndX
{
    int f00;
    int f04;
    int f08;
    ~BSSoundHandleEx();
};
struct SubM
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
    void FUN_004ed900();
    ~SubM();
};
struct SettingValue
{
    int v;
};
struct SettingColl
{
    SettingValue* FUN_0043d4d0();
};
struct SysColorMgr
{
    static SysColorMgr* __stdcall GetSingleton(int, char*);
    void ApplyToChild();
};
struct Menu_007a8b10
{
    virtual ~Menu_007a8b10();
};
unsigned int __cdecl gm_GetTickCount();
void __cdecl FormHeap_Free(void*);
extern SettingColl DAT_011d0b90;
extern unsigned int DAT_011d95c0;
extern char DAT_011d9674;
struct FUN_007658e0 : Menu_007a8b10
{
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    EntObj* entries[46];
    ObjE0 mE0;
    BSSoundHandleEx snd[5];
    ListM list1;
    ListM list2;
    FUN_00765810 m180;
    int f184;
    SubM m188;
    void* ptr1B0;
    ~FUN_007658e0();
};
struct HackTile
{
    const char* GetString(int);
    void Set(int, const char*, bool);
    bool ContainsTrait(int);
};
struct HackEntry
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
    HackTile* tile;
};
struct HackList
{
    char* data;
    HackList* next;
    HackList* Next();
    char** Get();
    void Remove(char**);
};
int __cdecl FUN_00408b20(const char*, const char*);
struct HackMenu
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
    HackEntry* entries[46];
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

    HackList words;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    const char* selected;
    int unk1a0;
    int unk1a4;
    unsigned int count;
    unsigned int dotCount;
    unsigned int* positions;
    void RemoveRandomWord();
};
struct FUN_00759eb0
{
    FUN_00759eb0(const char*);
    ~FUN_00759eb0();
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
};
struct SettingRef
{
    unsigned int* __thiscall FUN_0043d4d0();
};
extern SettingRef DAT_011d3dc0;
extern SettingRef DAT_011d4e4c;
extern SettingRef DAT_011d3510;
float __cdecl FUN_004bd510(float, float);
struct TileValue
{
    float __thiscall FUN_00a011b0(int);
};
struct ConstructorTile : FUN_00a1ddb0_res
{
    int __thiscall FindTraitValue(int);
    int __thiscall FUN_00a00f30(int);
    void __thiscall FUN_00700320(unsigned int, int);
    void __thiscall FUN_00a01350(unsigned int, const char*, bool);
};
struct ConstructorMenu : FUN_00a1ddb0_owner
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
    char* root;
    TileValue* __thiscall FUN_00726070();
};
extern const char DAT_0107293c[];
extern const char DAT_010692d0[];
struct FUN_0076b300 : FUN_00759eb0
{
    ConstructorTile* tile;
    ConstructorTile* label;
    void __thiscall SetCapacity(unsigned int);
    void __thiscall FUN_006ffe80(int, int);
    FUN_0076b300(const char*, char*, const char*, int, unsigned char);
};
// Adapted from prior contributor's code (credited in packet.json)
extern "C" void* __cdecl memset(void*, int, unsigned int);
extern "C" void* __cdecl FUN_00afdf20(const char*, unsigned int, unsigned int, unsigned int);
extern "C" void __cdecl FUN_005b5e40(int, const char*, const char*);
extern "C" unsigned int __cdecl FUN_005a00a0(unsigned int);
unsigned int __cdecl BSStringCapacityMaximum(unsigned int, unsigned int);
void __cdecl FUN_0040fbe0(const char*, int);
unsigned int __cdecl BSStringLength(const char*);
extern char str_01072a34[];
extern char str_01072a00[];
extern char str_010729e8[];
unsigned int __cdecl gm_GetTickCount();
void __cdecl UpdateD766AA0Menu();
struct PathStorage
{
    StrMem str;
    void* ownedBuffer;
};
struct FUN_00680890 : FUN_00765810
{
    void* m_item;
    void* m_next;
    FUN_00680890();
};
struct StrMemMethods : StrMem
{
    void __thiscall FUN_00438390(const char*);
    const char* __thiscall Get();
};
struct WordsView : FUN_00765810
{
    void __thiscall FUN_00680890();
    void __thiscall FUN_0076b240(const char*);
    void __thiscall SortWeatherEntries();
    WordsView* __thiscall FUN_00726070();
    char** __thiscall FUN_006815c0();
};
struct FileObj
{
    virtual ~FileObj();
    virtual void __thiscall unknown04();
    virtual void __thiscall unknown08();
    virtual void __thiscall unknown0c();
    virtual void __thiscall unknown10();
    virtual void __thiscall unknown14();
    virtual void __thiscall unknown18();
    virtual void __thiscall unknown1c();
    virtual unsigned char __thiscall FUN_20(int, int);
    virtual void __thiscall unknown24();
    virtual void __thiscall unknown28();
    virtual void __thiscall unknown2c();
    virtual void __thiscall unknown30();
    virtual int __thiscall FUN_34(char*, int, int);
};
struct EntryRow
{
    unsigned char* __thiscall FUN_00559450();
};
struct MatrixWrapper : FUN_007687d0
{
    MatrixWrapper(unsigned int);
};
struct FUN_00768070_shell : FUN_00768a10_shell
{
    unsigned int __thiscall FUN_00769520(FUN_007687d0*);
    void __thiscall SelectWordSet(unsigned int);
};

struct SoundHandle00ad7550
{
    int unk00;
    unsigned char unk04;
    int unk08;
    ~SoundHandle00ad7550();
};

struct PlaybackDevice
{
    SoundHandle00ad7550 __thiscall Play(unsigned int a, unsigned int b);
};

extern PlaybackDevice* __cdecl GetPlaybackDevice();

struct TlsBlock00ad7550
{
    unsigned int unk000, unk004, unk008, unk00c, unk010, unk014;
    unsigned int unk018, unk01c, unk020, unk024, unk028, unk02c;
    unsigned int unk030, unk034, unk038, unk03c, unk040, unk044;
    unsigned int unk048, unk04c, unk050, unk054, unk058, unk05c;
    unsigned int unk060, unk064, unk068, unk06c, unk070, unk074;
    unsigned int unk078, unk07c, unk080, unk084, unk088, unk08c;
    unsigned int unk090, unk094, unk098, unk09c, unk0a0, unk0a4;
    unsigned int unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc;
    unsigned int unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4;
    unsigned int unk0d8, unk0dc, unk0e0, unk0e4, unk0e8, unk0ec;
    unsigned int unk0f0, unk0f4, unk0f8, unk0fc, unk100, unk104;
    unsigned int unk108, unk10c, unk110, unk114, unk118, unk11c;
    unsigned int unk120, unk124, unk128, unk12c, unk130, unk134;
    unsigned int unk138, unk13c, unk140, unk144, unk148, unk14c;
    unsigned int unk150, unk154, unk158, unk15c, unk160, unk164;
    unsigned int unk168, unk16c, unk170, unk174, unk178, unk17c;
    unsigned int unk180, unk184, unk188, unk18c, unk190, unk194;
    unsigned int unk198, unk19c, unk1a0, unk1a4, unk1a8, unk1ac;
    unsigned int unk1b0, unk1b4, unk1b8, unk1bc, unk1c0, unk1c4;
    unsigned int unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc;
    unsigned int unk1e0, unk1e4, unk1e8, unk1ec, unk1f0, unk1f4;
    unsigned int unk1f8, unk1fc, unk200, unk204, unk208, unk20c;
    unsigned int unk210, unk214, unk218, unk21c, unk220, unk224;
    unsigned int unk228, unk22c, unk230, unk234, unk238, unk23c;
    unsigned int unk240, unk244, unk248, unk24c, unk250, unk254;
    unsigned int unk258, unk25c, unk260, unk264, unk268, unk26c;
    unsigned int unk270, unk274, unk278, unk27c, unk280, unk284;
    unsigned int unk288, unk28c, unk290, unk294, unk298, unk29c;
    unsigned int unk2a0, unk2a4, unk2a8, unk2ac, unk2b0, tag2b4;
    unsigned int unk2b8;
};
extern __declspec(thread) TlsBlock00ad7550 g_tls00ad7550;

struct AudioTag
{
    static int Get()
    {
        return g_tls00ad7550.tag2b4;
    }
    static void Set(int value)
    {
        g_tls00ad7550.tag2b4 = value;
    }
};

struct TagScope
{
    int m_saved;
    TagScope()
    {
        m_saved = AudioTag::Get();
        AudioTag::Set(0xb);
    }
    ~TagScope()
    {
        AudioTag::Set(m_saved);
    }
};

struct SoundPlayback
{
    SoundHandle00ad7550 FUN_00ad7550(unsigned int a, unsigned int b);
};

// @fnv 0x00ad7550
SoundHandle00ad7550 SoundPlayback::FUN_00ad7550(unsigned int a, unsigned int b)
{
    TagScope scope;
    return GetPlaybackDevice()->Play(a, b);
}
