
// blackjackmenu_ctx_variant.cpp: context variant of src/fallout/interface/menus/blackjackmenu.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
// src/fallout/interface/menus/blackjackmenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/blackjackmenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_007316f0_shell
{
    void ClearField();
};
struct BlackJackMenu
{
    int __thiscall FUN_00731790();
};
int __cdecl FUN_00733f80();
struct FUN_007399d0_shell
{
    void FUN_007399d0();
};
struct FUN_00734d30_shell
{
    int __thiscall HasFlag(int aFlag);
};
struct FUN_007317d0_shell
{
    void* __thiscall DestroyIfFlagged(unsigned int);
};
struct Helper731800
{
    void __thiscall FUN_00731800();
};
void _Deallocate(void*);
struct Proc_S
{
    void* GetNext();
};
struct Tile
{
    void Set(int, float, bool);
};
void* __cdecl FUN_004b7210();
struct DAT_011d9050_S
{
    char _pad[0x28];
    int v28;
};
extern DAT_011d9050_S* DAT_011d9050;
void FUN_00731d30();
struct Helper62d0
{
    void* operator=(const void*);
};
struct FUN_007324f0_shell
{
    int m0;
    int m4;
    int m8;
    int mC;
    FUN_007324f0_shell& operator=(const FUN_007324f0_shell&);
};
struct FUN_00733f50_shell
{
    int m0;
    int m1;
    short m2;
    FUN_00733f50_shell* FUN_00733f50();
};
struct FUN_00733f90_shell
{
    char __thiscall FUN_00733f90();
};
struct FUN_00738fb0_shell
{
    int __thiscall GetAdjustedValue(int a1);
};
struct NiAVObject
{
    void __thiscall SetAppCulled(bool);
};
struct SceneObjectLookup
{
    static NiAVObject* __cdecl GetObjectByName(NiAVObject*, char const*);
};
struct FUN_00739ad0_Holder
{
    char _pad[0xDB4];
    NiAVObject* m_pTreeNode;
    void __thiscall HideArrowNodes();
};
struct FUN_00733fd0_shell
{
    char _pad_0[0xf8];
    float m_fMinimum;  // +0xf8
    void __thiscall FUN_00733fd0(float fMin);
};
struct FUN_00734d50_holder
{
    unsigned char _pad[0xDB0];
    int _flags;
    void SetFlag(int flag, bool value);
};
class AnimIdle;
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer(T*);
    ~NiPointer();
    NiPointer& operator=(T*);
    operator T*() const;
};
struct S148c0
{
    void FUN_007148c0(int, int);
};
S148c0* FUN_0043c4b0();
struct Accum_00733500
{
    void FUN_00c4f270(int);
    void FUN_004a0fd0(AnimIdle*);
    void FUN_00c4f2d0();
};
struct Node_00733500
{
    Accum_00733500* GetProcessInteger();
    AnimIdle* GetAnimationData();
};
Node_00733500* FUN_0045c670();
struct Mgr_00733500
{
    AnimIdle* FUN_007fd640();
};
void __cdecl UpdateCameraFrustum(AnimIdle*, float);
void* __cdecl FUN_00450b80(int);
void __cdecl FUN_00b6bee0(AnimIdle*, void*, Accum_00733500*);
struct BSShaderRenderUtility
{
    static void __cdecl SetRenderCamera(AnimIdle*, AnimIdle*, bool);
};
extern const float g_011db5ec_arg1;
extern NiPointer<AnimIdle> g_011d90bc;
void __cdecl FUN_00733500();
struct FUN_00739650_shell : FUN_00734d50_holder
{
    bool FUN_00739650(bool bFlag);
};
struct NiUpdateData
{
    float m_fTime;
    bool m_bUpdate;
    bool m_bForce;
    unsigned char _padding[6];

    NiUpdateData(float, bool, bool);
};
struct NiNode
{
    void __thiscall Update(NiUpdateData const&);
};
struct LodObject
{
    void __thiscall SetAppCulled(bool);
};
struct GO
{
    operator unsigned int() const;
};
extern GO g_011d9098;
extern char str_01070e34[];
extern char str_01070e20[];
extern char str_01070e0c[];
extern char str_01070dfc[];
extern char str_01070de8[];
extern char str_01070dd4[];
extern char str_01070dc4[];
extern char str_01070db0[];
extern char str_01070d9c[];
int _sprintf_s(char*, unsigned int, const char*, ...);
struct FUN_00738270_shell
{
    unsigned char _pad[0xdb8];
    NiAVObject* m_pCardObject1;
    NiAVObject* m_pCardObject2;
    NiAVObject* m_pCardObject3;

    void __thiscall UncullCardObjects();
};
struct StartMenu
{
    char const* __thiscall GetMenuTitle();
};
extern StartMenu g_011d25ec;
extern StartMenu g_011d30fc;
extern StartMenu g_011d3354;
extern StartMenu g_011d33fc;
extern StartMenu g_011d37f8;
extern StartMenu g_011d3da8;
extern StartMenu g_011d4234;
extern StartMenu g_011d487c;
extern StartMenu g_011d4c78;
extern StartMenu g_011d4e28;
struct FUN_00a01290_shell
{
    void __thiscall SetTraitAndReset(int, float);
};
struct P09TileS
{
    void __thiscall Set(int, char const*, bool);
};
struct Tile2
{
    void __thiscall Set(int, int);
};
struct FUN_00738c30_shell
{
    void __thiscall FUN_00738c30(int, float);
};
struct BlackJackMenu_Layout
{
    char _pad[0x40];
    Tile* m40;
    Tile* m44;
    Tile* m48;
    Tile* m4C;
    Tile* m50;
    Tile* m54;
};
void __cdecl UpdateBetTiles(bool bBetTiles);
struct Padding16ByteBlock
{
    int _pad[4];
};
struct G2
{
    bool __thiscall _ref_008256d0();
    void __thiscall _ref_00726c60(Padding16ByteBlock* const& value);
    void __thiscall AddHead(Padding16ByteBlock* const& value);
};
struct SoundListView
{
    void __thiscall AddTail(Padding16ByteBlock* const& value);
};
struct FUN_007393f0_shell
{
    unsigned char _pad0[0x2c];
    int _handResult0;
    int _handResult1;
    unsigned char _pad1[0x5c];
    Padding16ByteBlock _deck[208];
    G2* _dealerHand;
    G2* _playerHand;

    int DrawCard(int a1, int a2, int a3);
    int DrawCard(G2* hand, int a1, int a2);
    void FUN_00738ff0(G2* hand);

    void __thiscall DealInitialCards();
};
extern "C" void* _ReadWriteBarrier_unused;
struct SetBase
{
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;

    SetBase();
    virtual ~SetBase();
};
struct SetElem
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    SetElem();
    ~SetElem();
};
struct SetMgr
{
    void* FUN_007316d0();
};
struct SetMgrB
{
    int FUN_00575610(int);
};
struct SetMgrC
{
    void ClearField();
};
extern SetMgr* DAT_011d9058;
extern SetMgrB* DAT_011dea3c;
extern void* DAT_011d9044;
extern void* DAT_011d9048;
void* __cdecl TraitNameToIDAdd(const char*, int);
class FUN_007315e0 : public SetBase
{
  public:
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
    void* m74;
    unsigned int unk78;
    unsigned int m7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    SetElem m90[208];

    FUN_007315e0();
    virtual ~FUN_007315e0();
    void ClearField();
};
struct Member731710A
{
    int m_00;
    Member731710A(int v);
    ~Member731710A();
};
struct Member731710B
{
    int m_00;
    Member731710B(int v);
};
struct FUN_00731710_cls
{
    int m_00;
    int m_04;
    Member731710A m_08;
    Member731710B m_0c;

    FUN_00731710_cls();
};
struct Local12_cls
{
    int m0;
    int m4;
    int m8;
    void __thiscall FUN_0043d410(float a1, int a2, int a3);
};
struct Node_cls
{
    void __thiscall FUN_00450f90(int);
};
struct Tail2_cls
{
    void __thiscall FUN_00a59c60();
};
struct Tail1_cls
{
    Tail2_cls* __thiscall FUN_0043b4a0();
};
struct Mgr_cls
{
    Tail1_cls* __thiscall FUN_00559450(int, Local12_cls*);
};
extern Mgr_cls DAT_011d9098;
extern char str_01070e58[];
extern char str_01070e44[];
Node_cls* __cdecl FUN_004aae30(int value, char const* name);
struct FUN_007399f0_cls
{
    unsigned char _pad0[0xdb4];
    int m_db4;

    bool __thiscall HasFlag(int aFlag);
    void __thiscall FUN_007399f0();
};
struct ChipNodeX
{
    void SetLocalRotation(float afX, float afY, float afZ);
};
struct UpdateDataX
{
    float fTime;
    bool m_bUpdateEnabled;
    bool bIsMultiThreaded;
    short sPad;
    int iActionIndex;
    UpdateDataX(float afTime, bool abUpdateControllers, bool abIsMultiThreaded);
};
struct RootNodeX
{
    void Update(const UpdateDataX& arData);
};
struct RootPtrX
{
    RootNodeX* m_pObject;
    operator RootNodeX*() const;
};
extern RootPtrX xspTableRoot;
struct BlackJackChipsX
{
    char _pad00[0x6c];
    int iBet;
    char _pad70[0xdc4 - 0x70];
    ChipNodeX* apChips[12];
    void UpdateChipPositions();
};
struct String90
{
    const char* value;
    String90(const char*);
    ~String90();
};
struct Controller90
{
    void* FUN_0047a520(const String90&);
    void FUN_0048fef0(float);
};
struct Bound90
{
    float FUN_0084d030();
};
struct Update90
{
    float time;
    bool update, force;
    unsigned short unk06;
    int unk08;
    Update90(float, bool, bool);
};
struct Property90;
struct Node90
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
    virtual void v0dc(Node90*, int);
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0(int, int, Node90*);
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
    Node90(int);
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    void FUN_00a59c60(const Update90&);
    Controller90* FUN_00a5c570(const void*);
    Node90* FUN_00a59d30(int);
    int FUN_00441110();
    Bound90* FUN_0043d450();
    void FUN_00b5ca70(Node90*, float);
};
struct Pointer90
{
    Node90* p;
    Pointer90& FUN_0066b0d0(Node90*);
    Node90* FUN_00559450();
};
extern Pointer90 DAT_011d90bc;
extern int DAT_011f36ac;
struct Loader90
{
    Node90* LoadModel(const char*, int, int, int, int, int);
};
extern Loader90* DAT_011c3b3c;
Node90* __cdecl FUN_004aae30(Node90*, const char*);
void __cdecl FUN_00a6d2d0(Node90*);
struct Menu90
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
    Pointer90 scene;
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
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    int unk604;
    int unk608;
    int unk60c;
    int unk610;
    int unk614;
    int unk618;
    int unk61c;
    int unk620;
    int unk624;
    int unk628;
    int unk62c;
    int unk630;
    int unk634;
    int unk638;
    int unk63c;
    int unk640;
    int unk644;
    int unk648;
    int unk64c;
    int unk650;
    int unk654;
    int unk658;
    int unk65c;
    int unk660;
    int unk664;
    int unk668;
    int unk66c;
    int unk670;
    int unk674;
    int unk678;
    int unk67c;
    int unk680;
    int unk684;
    int unk688;
    int unk68c;
    int unk690;
    int unk694;
    int unk698;
    int unk69c;
    int unk6a0;
    int unk6a4;
    int unk6a8;
    int unk6ac;
    int unk6b0;
    int unk6b4;
    int unk6b8;
    int unk6bc;
    int unk6c0;
    int unk6c4;
    int unk6c8;
    int unk6cc;
    int unk6d0;
    int unk6d4;
    int unk6d8;
    int unk6dc;
    int unk6e0;
    int unk6e4;
    int unk6e8;
    int unk6ec;
    int unk6f0;
    int unk6f4;
    int unk6f8;
    int unk6fc;
    int unk700;
    int unk704;
    int unk708;
    int unk70c;
    int unk710;
    int unk714;
    int unk718;
    int unk71c;
    int unk720;
    int unk724;
    int unk728;
    int unk72c;
    int unk730;
    int unk734;
    int unk738;
    int unk73c;
    int unk740;
    int unk744;
    int unk748;
    int unk74c;
    int unk750;
    int unk754;
    int unk758;
    int unk75c;
    int unk760;
    int unk764;
    int unk768;
    int unk76c;
    int unk770;
    int unk774;
    int unk778;
    int unk77c;
    int unk780;
    int unk784;
    int unk788;
    int unk78c;
    int unk790;
    int unk794;
    int unk798;
    int unk79c;
    int unk7a0;
    int unk7a4;
    int unk7a8;
    int unk7ac;
    int unk7b0;
    int unk7b4;
    int unk7b8;
    int unk7bc;
    int unk7c0;
    int unk7c4;
    int unk7c8;
    int unk7cc;
    int unk7d0;
    int unk7d4;
    int unk7d8;
    int unk7dc;
    int unk7e0;
    int unk7e4;
    int unk7e8;
    int unk7ec;
    int unk7f0;
    int unk7f4;
    int unk7f8;
    int unk7fc;
    int unk800;
    int unk804;
    int unk808;
    int unk80c;
    int unk810;
    int unk814;
    int unk818;
    int unk81c;
    int unk820;
    int unk824;
    int unk828;
    int unk82c;
    int unk830;
    int unk834;
    int unk838;
    int unk83c;
    int unk840;
    int unk844;
    int unk848;
    int unk84c;
    int unk850;
    int unk854;
    int unk858;
    int unk85c;
    int unk860;
    int unk864;
    int unk868;
    int unk86c;
    int unk870;
    int unk874;
    int unk878;
    int unk87c;
    int unk880;
    int unk884;
    int unk888;
    int unk88c;
    int unk890;
    int unk894;
    int unk898;
    int unk89c;
    int unk8a0;
    int unk8a4;
    int unk8a8;
    int unk8ac;
    int unk8b0;
    int unk8b4;
    int unk8b8;
    int unk8bc;
    int unk8c0;
    int unk8c4;
    int unk8c8;
    int unk8cc;
    int unk8d0;
    int unk8d4;
    int unk8d8;
    int unk8dc;
    int unk8e0;
    int unk8e4;
    int unk8e8;
    int unk8ec;
    int unk8f0;
    int unk8f4;
    int unk8f8;
    int unk8fc;
    int unk900;
    int unk904;
    int unk908;
    int unk90c;
    int unk910;
    int unk914;
    int unk918;
    int unk91c;
    int unk920;
    int unk924;
    int unk928;
    int unk92c;
    int unk930;
    int unk934;
    int unk938;
    int unk93c;
    int unk940;
    int unk944;
    int unk948;
    int unk94c;
    int unk950;
    int unk954;
    int unk958;
    int unk95c;
    int unk960;
    int unk964;
    int unk968;
    int unk96c;
    int unk970;
    int unk974;
    int unk978;
    int unk97c;
    int unk980;
    int unk984;
    int unk988;
    int unk98c;
    int unk990;
    int unk994;
    int unk998;
    int unk99c;
    int unk9a0;
    int unk9a4;
    int unk9a8;
    int unk9ac;
    int unk9b0;
    int unk9b4;
    int unk9b8;
    int unk9bc;
    int unk9c0;
    int unk9c4;
    int unk9c8;
    int unk9cc;
    int unk9d0;
    int unk9d4;
    int unk9d8;
    int unk9dc;
    int unk9e0;
    int unk9e4;
    int unk9e8;
    int unk9ec;
    int unk9f0;
    int unk9f4;
    int unk9f8;
    int unk9fc;
    int unka00;
    int unka04;
    int unka08;
    int unka0c;
    int unka10;
    int unka14;
    int unka18;
    int unka1c;
    int unka20;
    int unka24;
    int unka28;
    int unka2c;
    int unka30;
    int unka34;
    int unka38;
    int unka3c;
    int unka40;
    int unka44;
    int unka48;
    int unka4c;
    int unka50;
    int unka54;
    int unka58;
    int unka5c;
    int unka60;
    int unka64;
    int unka68;
    int unka6c;
    int unka70;
    int unka74;
    int unka78;
    int unka7c;
    int unka80;
    int unka84;
    int unka88;
    int unka8c;
    int unka90;
    int unka94;
    int unka98;
    int unka9c;
    int unkaa0;
    int unkaa4;
    int unkaa8;
    int unkaac;
    int unkab0;
    int unkab4;
    int unkab8;
    int unkabc;
    int unkac0;
    int unkac4;
    int unkac8;
    int unkacc;
    int unkad0;
    int unkad4;
    int unkad8;
    int unkadc;
    int unkae0;
    int unkae4;
    int unkae8;
    int unkaec;
    int unkaf0;
    int unkaf4;
    int unkaf8;
    int unkafc;
    int unkb00;
    int unkb04;
    int unkb08;
    int unkb0c;
    int unkb10;
    int unkb14;
    int unkb18;
    int unkb1c;
    int unkb20;
    int unkb24;
    int unkb28;
    int unkb2c;
    int unkb30;
    int unkb34;
    int unkb38;
    int unkb3c;
    int unkb40;
    int unkb44;
    int unkb48;
    int unkb4c;
    int unkb50;
    int unkb54;
    int unkb58;
    int unkb5c;
    int unkb60;
    int unkb64;
    int unkb68;
    int unkb6c;
    int unkb70;
    int unkb74;
    int unkb78;
    int unkb7c;
    int unkb80;
    int unkb84;
    int unkb88;
    int unkb8c;
    int unkb90;
    int unkb94;
    int unkb98;
    int unkb9c;
    int unkba0;
    int unkba4;
    int unkba8;
    int unkbac;
    int unkbb0;
    int unkbb4;
    int unkbb8;
    int unkbbc;
    int unkbc0;
    int unkbc4;
    int unkbc8;
    int unkbcc;
    int unkbd0;
    int unkbd4;
    int unkbd8;
    int unkbdc;
    int unkbe0;
    int unkbe4;
    int unkbe8;
    int unkbec;
    int unkbf0;
    int unkbf4;
    int unkbf8;
    int unkbfc;
    int unkc00;
    int unkc04;
    int unkc08;
    int unkc0c;
    int unkc10;
    int unkc14;
    int unkc18;
    int unkc1c;
    int unkc20;
    int unkc24;
    int unkc28;
    int unkc2c;
    int unkc30;
    int unkc34;
    int unkc38;
    int unkc3c;
    int unkc40;
    int unkc44;
    int unkc48;
    int unkc4c;
    int unkc50;
    int unkc54;
    int unkc58;
    int unkc5c;
    int unkc60;
    int unkc64;
    int unkc68;
    int unkc6c;
    int unkc70;
    int unkc74;
    int unkc78;
    int unkc7c;
    int unkc80;
    int unkc84;
    int unkc88;
    int unkc8c;
    int unkc90;
    int unkc94;
    int unkc98;
    int unkc9c;
    int unkca0;
    int unkca4;
    int unkca8;
    int unkcac;
    int unkcb0;
    int unkcb4;
    int unkcb8;
    int unkcbc;
    int unkcc0;
    int unkcc4;
    int unkcc8;
    int unkccc;
    int unkcd0;
    int unkcd4;
    int unkcd8;
    int unkcdc;
    int unkce0;
    int unkce4;
    int unkce8;
    int unkcec;
    int unkcf0;
    int unkcf4;
    int unkcf8;
    int unkcfc;
    int unkd00;
    int unkd04;
    int unkd08;
    int unkd0c;
    int unkd10;
    int unkd14;
    int unkd18;
    int unkd1c;
    int unkd20;
    int unkd24;
    int unkd28;
    int unkd2c;
    int unkd30;
    int unkd34;
    int unkd38;
    int unkd3c;
    int unkd40;
    int unkd44;
    int unkd48;
    int unkd4c;
    int unkd50;
    int unkd54;
    int unkd58;
    int unkd5c;
    int unkd60;
    int unkd64;
    int unkd68;
    int unkd6c;
    int unkd70;
    int unkd74;
    int unkd78;
    int unkd7c;
    int unkd80;
    int unkd84;
    int unkd88;
    int unkd8c;
    int unkd90;
    int unkd94;
    int unkd98;
    int unkd9c;
    int unkda0;
    int unkda4;
    int unkda8;
    int unkdac;
    int unkdb0;
    Node90* rootdb4;
    Node90* rootdb8;
    Node90* rootdbc;
    Node90* rootdc0;
    Node90* cards[6];
    Node90* backs[6];
    Controller90* ctrldf4;
    Controller90* ctrldf8;
    Controller90* ctrldfc;
    Controller90* ctrle00;
    void* anime04;
    void* anime08;
    void* anime0c;
    void* anime10;
    void* anime14;
    void* anime18;
    void* anime1c;
    void* anime20;
    void* anime24;
    void* anime28;
    void* anime2c;
    void* anime30;
    void* anime34;
    void* anime38;
    void* anime3c;
    void* anime40;
    void* anime44;
    void* anime48;
    void* anime4c;
    void* anime50;
    void* anime54;
    void* anime58;
    void* anime5c;
    void* anime60;
    void* anime64;
    void* anime68;
    void* anime6c;
    void InitBlackjackScene();
    void UpdateChipPositions();
    void FUN_00739970(int);
    void HideArrowNodes();
    Node90* FUN_007c2180();
};
struct FUN_00733f50
{
    int id;
    int amount;
    short flags;
    FUN_00733f50();
};
struct Node129
{
    FUN_00733f50** FUN_006815c0();
    Node129* FUN_00726070();
    bool FUN_008256d0();
    void FUN_00726c60(FUN_00733f50* const&);
    void FUN_005ae3d0(FUN_00733f50* const&);
};
struct Settings129
{
    const char* FUN_00403df0();
};
struct BSSoundHandleEx
{
    int id;
    int flags;
    int state;
    ~BSSoundHandleEx();
    bool Play(bool);
};
struct Audio129
{
    BSSoundHandleEx FUN_00ad7550(const char*, int);
};
Audio129* FUN_00453a70();
struct Stats129
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
    int limit;
};
struct Name129
{
    const char* FUN_00408da0();
};
struct Casino129
{
    virtual int v00();
    virtual int v04();
    virtual int v08();
    virtual int v0C();
    virtual int v10();
    virtual int v14();
    virtual int v18();
    virtual int v1C();
    virtual int v20();
    virtual int v24();
    virtual int v28();
    virtual int v2C();
    virtual int v30();
    virtual int v34();
    virtual int v38();
    virtual int v3C();
    virtual int v40();
    virtual int v44();
    virtual int v48();
    virtual int v4C();
    virtual int v50();
    virtual int v54();
    virtual int v58();
    virtual int v5C();
    virtual int v60();
    virtual int v64();
    virtual int v68();
    virtual int v6C();
    virtual int v70();
    virtual int v74();
    virtual int v78();
    virtual int v7C();
    virtual int v80();
    virtual int v84();
    virtual int v88();
    virtual int v8C();
    virtual int v90();
    virtual int v94();
    virtual int v98();
    virtual int v9C();
    virtual int vA0();
    virtual int vA4();
    virtual int vA8();
    virtual int vAC();
    virtual int vB0();
    virtual int vB4();
    virtual int vB8();
    virtual int vBC();
    virtual int vC0();
    virtual int vC4();
    virtual int vC8();
    virtual int vCC();
    virtual int vD0();
    virtual int vD4();
    virtual int vD8();
    virtual int vDC();
    virtual int vE0();
    virtual int vE4();
    virtual int vE8();
    virtual int vEC();
    virtual int vF0();
    virtual int vF4();
    virtual int vF8();
    virtual int vFC();
    virtual int v100();
    virtual int v104();
    virtual int v108();
    virtual int v10C();
    virtual int v110();
    virtual int v114();
    virtual int v118();
    virtual int v11C();
    virtual int v120();
    virtual int v124();
    virtual int v128();
    virtual int v12C();
    virtual const char* GetName();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    Name129 name;
    int FUN_0084e3a0();
    Stats129* FUN_00504e60();
};
struct Tile129
{
    float FUN_00a011b0(int);
    void FUN_00a012d0(int, float);
    void FUN_00a01350(int, const char*, bool);
    void SetTraitAndReset(int, float);
    void FUN_00700320(int, int);
    struct Menu129* FUN_00a03c90();
};
Tile129* FUN_00a08b20(Tile129*, const char*);
struct Xml129
{
    Tile129* ReadXML();
};
struct Interface129
{
    Xml129* FUN_00586150(const char*);
};
struct Menu129
{
    virtual ~Menu129();
    virtual int v04();
    virtual int v08();
    virtual int v0C();
    virtual int v10();
    virtual int v14();
    virtual int v18();
    virtual int v1C();
    virtual int v20();
    virtual int v24();
    virtual int v28();
    virtual int v2C();
    virtual int v30();
    virtual int GetID();
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
    Tile129* tile34;
    Tile129* tile38;
    Tile129* tile3C;
    Tile129* tile40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int setting;
    int bet;
    void FUN_00a1dc70(Tile129*, int);
    bool FUN_00733f90();
    void UpdateTileText();
    bool LoadCardDeckResources();
    void InitBlackjackScene();
    void FUN_00a1dc20(int);
    void ClearField();
    Tile129* FUN_00726070();
};
struct Mode129
{
    int FUN_0066ef20(int);
};
struct Player129
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
    Mode129 mode;
    Node129* FUN_005a6260();
    bool FUN_00969b80();
    int FUN_00969b40();
};
extern FUN_00733f50* DAT_011d9054;
extern int DAT_0119fe40, DAT_0119fe3c;
extern Settings129 DAT_011d451c, DAT_011d3abc, DAT_011d2424, DAT_011d3594, DAT_011d3804, DAT_011d3300, DAT_011d3e08,
    DAT_011d4c84;
extern const float DAT_010162c0;
extern const double DAT_010704f0, DAT_010704e8;
extern const char DAT_01070c58[], DAT_01049638[], DAT_01025cc4[], DAT_01070c38[], DAT_01070be0[], DAT_01070bc0[],
    DAT_01012058[], DAT_01070ba8[];
Menu129* FUN_00a09030(int);
int FUN_00406d00(char*, unsigned int, const char*, ...);
void DispatchMessageToSink(const char*, int, const char*, int, float, int);
void FUN_005b5e40(const char*);
float __stdcall FUN_00a01530(int);
int FUN_0044a670(const char*);
Tile129* FUN_00733630(SetMgr* casino, int minimum, int maximum, int required);
NiAVObject* __cdecl FUN_004aae30(NiAVObject*, const char*);
struct Menu737e50
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
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    int unk604;
    int unk608;
    int unk60c;
    int unk610;
    int unk614;
    int unk618;
    int unk61c;
    int unk620;
    int unk624;
    int unk628;
    int unk62c;
    int unk630;
    int unk634;
    int unk638;
    int unk63c;
    int unk640;
    int unk644;
    int unk648;
    int unk64c;
    int unk650;
    int unk654;
    int unk658;
    int unk65c;
    int unk660;
    int unk664;
    int unk668;
    int unk66c;
    int unk670;
    int unk674;
    int unk678;
    int unk67c;
    int unk680;
    int unk684;
    int unk688;
    int unk68c;
    int unk690;
    int unk694;
    int unk698;
    int unk69c;
    int unk6a0;
    int unk6a4;
    int unk6a8;
    int unk6ac;
    int unk6b0;
    int unk6b4;
    int unk6b8;
    int unk6bc;
    int unk6c0;
    int unk6c4;
    int unk6c8;
    int unk6cc;
    int unk6d0;
    int unk6d4;
    int unk6d8;
    int unk6dc;
    int unk6e0;
    int unk6e4;
    int unk6e8;
    int unk6ec;
    int unk6f0;
    int unk6f4;
    int unk6f8;
    int unk6fc;
    int unk700;
    int unk704;
    int unk708;
    int unk70c;
    int unk710;
    int unk714;
    int unk718;
    int unk71c;
    int unk720;
    int unk724;
    int unk728;
    int unk72c;
    int unk730;
    int unk734;
    int unk738;
    int unk73c;
    int unk740;
    int unk744;
    int unk748;
    int unk74c;
    int unk750;
    int unk754;
    int unk758;
    int unk75c;
    int unk760;
    int unk764;
    int unk768;
    int unk76c;
    int unk770;
    int unk774;
    int unk778;
    int unk77c;
    int unk780;
    int unk784;
    int unk788;
    int unk78c;
    int unk790;
    int unk794;
    int unk798;
    int unk79c;
    int unk7a0;
    int unk7a4;
    int unk7a8;
    int unk7ac;
    int unk7b0;
    int unk7b4;
    int unk7b8;
    int unk7bc;
    int unk7c0;
    int unk7c4;
    int unk7c8;
    int unk7cc;
    int unk7d0;
    int unk7d4;
    int unk7d8;
    int unk7dc;
    int unk7e0;
    int unk7e4;
    int unk7e8;
    int unk7ec;
    int unk7f0;
    int unk7f4;
    int unk7f8;
    int unk7fc;
    int unk800;
    int unk804;
    int unk808;
    int unk80c;
    int unk810;
    int unk814;
    int unk818;
    int unk81c;
    int unk820;
    int unk824;
    int unk828;
    int unk82c;
    int unk830;
    int unk834;
    int unk838;
    int unk83c;
    int unk840;
    int unk844;
    int unk848;
    int unk84c;
    int unk850;
    int unk854;
    int unk858;
    int unk85c;
    int unk860;
    int unk864;
    int unk868;
    int unk86c;
    int unk870;
    int unk874;
    int unk878;
    int unk87c;
    int unk880;
    int unk884;
    int unk888;
    int unk88c;
    int unk890;
    int unk894;
    int unk898;
    int unk89c;
    int unk8a0;
    int unk8a4;
    int unk8a8;
    int unk8ac;
    int unk8b0;
    int unk8b4;
    int unk8b8;
    int unk8bc;
    int unk8c0;
    int unk8c4;
    int unk8c8;
    int unk8cc;
    int unk8d0;
    int unk8d4;
    int unk8d8;
    int unk8dc;
    int unk8e0;
    int unk8e4;
    int unk8e8;
    int unk8ec;
    int unk8f0;
    int unk8f4;
    int unk8f8;
    int unk8fc;
    int unk900;
    int unk904;
    int unk908;
    int unk90c;
    int unk910;
    int unk914;
    int unk918;
    int unk91c;
    int unk920;
    int unk924;
    int unk928;
    int unk92c;
    int unk930;
    int unk934;
    int unk938;
    int unk93c;
    int unk940;
    int unk944;
    int unk948;
    int unk94c;
    int unk950;
    int unk954;
    int unk958;
    int unk95c;
    int unk960;
    int unk964;
    int unk968;
    int unk96c;
    int unk970;
    int unk974;
    int unk978;
    int unk97c;
    int unk980;
    int unk984;
    int unk988;
    int unk98c;
    int unk990;
    int unk994;
    int unk998;
    int unk99c;
    int unk9a0;
    int unk9a4;
    int unk9a8;
    int unk9ac;
    int unk9b0;
    int unk9b4;
    int unk9b8;
    int unk9bc;
    int unk9c0;
    int unk9c4;
    int unk9c8;
    int unk9cc;
    int unk9d0;
    int unk9d4;
    int unk9d8;
    int unk9dc;
    int unk9e0;
    int unk9e4;
    int unk9e8;
    int unk9ec;
    int unk9f0;
    int unk9f4;
    int unk9f8;
    int unk9fc;
    int unka00;
    int unka04;
    int unka08;
    int unka0c;
    int unka10;
    int unka14;
    int unka18;
    int unka1c;
    int unka20;
    int unka24;
    int unka28;
    int unka2c;
    int unka30;
    int unka34;
    int unka38;
    int unka3c;
    int unka40;
    int unka44;
    int unka48;
    int unka4c;
    int unka50;
    int unka54;
    int unka58;
    int unka5c;
    int unka60;
    int unka64;
    int unka68;
    int unka6c;
    int unka70;
    int unka74;
    int unka78;
    int unka7c;
    int unka80;
    int unka84;
    int unka88;
    int unka8c;
    int unka90;
    int unka94;
    int unka98;
    int unka9c;
    int unkaa0;
    int unkaa4;
    int unkaa8;
    int unkaac;
    int unkab0;
    int unkab4;
    int unkab8;
    int unkabc;
    int unkac0;
    int unkac4;
    int unkac8;
    int unkacc;
    int unkad0;
    int unkad4;
    int unkad8;
    int unkadc;
    int unkae0;
    int unkae4;
    int unkae8;
    int unkaec;
    int unkaf0;
    int unkaf4;
    int unkaf8;
    int unkafc;
    int unkb00;
    int unkb04;
    int unkb08;
    int unkb0c;
    int unkb10;
    int unkb14;
    int unkb18;
    int unkb1c;
    int unkb20;
    int unkb24;
    int unkb28;
    int unkb2c;
    int unkb30;
    int unkb34;
    int unkb38;
    int unkb3c;
    int unkb40;
    int unkb44;
    int unkb48;
    int unkb4c;
    int unkb50;
    int unkb54;
    int unkb58;
    int unkb5c;
    int unkb60;
    int unkb64;
    int unkb68;
    int unkb6c;
    int unkb70;
    int unkb74;
    int unkb78;
    int unkb7c;
    int unkb80;
    int unkb84;
    int unkb88;
    int unkb8c;
    int unkb90;
    int unkb94;
    int unkb98;
    int unkb9c;
    int unkba0;
    int unkba4;
    int unkba8;
    int unkbac;
    int unkbb0;
    int unkbb4;
    int unkbb8;
    int unkbbc;
    int unkbc0;
    int unkbc4;
    int unkbc8;
    int unkbcc;
    int unkbd0;
    int unkbd4;
    int unkbd8;
    int unkbdc;
    int unkbe0;
    int unkbe4;
    int unkbe8;
    int unkbec;
    int unkbf0;
    int unkbf4;
    int unkbf8;
    int unkbfc;
    int unkc00;
    int unkc04;
    int unkc08;
    int unkc0c;
    int unkc10;
    int unkc14;
    int unkc18;
    int unkc1c;
    int unkc20;
    int unkc24;
    int unkc28;
    int unkc2c;
    int unkc30;
    int unkc34;
    int unkc38;
    int unkc3c;
    int unkc40;
    int unkc44;
    int unkc48;
    int unkc4c;
    int unkc50;
    int unkc54;
    int unkc58;
    int unkc5c;
    int unkc60;
    int unkc64;
    int unkc68;
    int unkc6c;
    int unkc70;
    int unkc74;
    int unkc78;
    int unkc7c;
    int unkc80;
    int unkc84;
    int unkc88;
    int unkc8c;
    int unkc90;
    int unkc94;
    int unkc98;
    int unkc9c;
    int unkca0;
    int unkca4;
    int unkca8;
    int unkcac;
    int unkcb0;
    int unkcb4;
    int unkcb8;
    int unkcbc;
    int unkcc0;
    int unkcc4;
    int unkcc8;
    int unkccc;
    int unkcd0;
    int unkcd4;
    int unkcd8;
    int unkcdc;
    int unkce0;
    int unkce4;
    int unkce8;
    int unkcec;
    int unkcf0;
    int unkcf4;
    int unkcf8;
    int unkcfc;
    int unkd00;
    int unkd04;
    int unkd08;
    int unkd0c;
    int unkd10;
    int unkd14;
    int unkd18;
    int unkd1c;
    int unkd20;
    int unkd24;
    int unkd28;
    int unkd2c;
    int unkd30;
    int unkd34;
    int unkd38;
    int unkd3c;
    int unkd40;
    int unkd44;
    int unkd48;
    int unkd4c;
    int unkd50;
    int unkd54;
    int unkd58;
    int unkd5c;
    int unkd60;
    int unkd64;
    int unkd68;
    int unkd6c;
    int unkd70;
    int unkd74;
    int unkd78;
    int unkd7c;
    int unkd80;
    int unkd84;
    int unkd88;
    int unkd8c;
    int unkd90;
    int unkd94;
    int unkd98;
    int unkd9c;
    int unkda0;
    int unkda4;
    int unkda8;
    int unkdac;
    int unkdb0;
    int unkdb4;
    NiAVObject* table;
    NiAVObject* hand;
    NiAVObject* split;
    void UpdateCulledNodes();
};
extern float DAT_0101e704, DAT_01023cd8;
struct BlackjackButtonMenu
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    int state;
    bool HasFlag(unsigned int);
    void FUN_00738c30(int, float);
    void UpdateButtonState(int);
};
struct BJCard
{
    int rank;
    int suit;
    int other;
    int ref;
    BJCard();
    ~BJCard();
    BJCard& operator=(const BJCard&);
};
int __cdecl GetRandomNumberInRange(int, int);
int __cdecl FUN_00ec7d40(int);
struct BJDeck
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
    bool flag78;
    bool flag79;
    short unk7a;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    BJCard cards[209];
    int count;
    void Shuffle();
    int HandValue(void*);
    int CardValue(int);
    int DrawCard(void*, bool, bool);
};
class TESObjectREFR;
template <class C> class BSStringT
{
  public:
    operator const C*() const;
};
template <class T> class NiTPointerList
{
  public:
    T& AddEight(void* pos) const;
    void* DereferenceIfNotNull(void* pos) const;
    int* FUN_0073ac90();
};
struct FUN_00a012d0_t
{
    void FUN_00a012d0(int, float, bool);
};
struct Entry738c
{
    int m_00;
    NiTPointerList<TESObjectREFR*> m_kList;
};
struct Table738c
{
    char _pad[0x34];
    Entry738c* m_apEntries[1];
};
struct CardInfo
{
    int unk00;
    int unk04;
    Pointer90 unk08;
    Pointer90 unk0c;
};
struct TableNode : Node90
{
    Node90* __thiscall FUN_0043b4a0(int index);
};
struct GlobalPtr
{
    TableNode* FUN_00559450();
};
struct BlackjackMenuShell
{
    void FUN_007396e0(int a1, int a2, CardInfo* a3);
};
struct OwnQ
{
    int FUN_00738ff0(Node129* pList);
};
struct CardHand
{
    CardInfo** FUN_006815c0();
    CardHand* FUN_00726070();
    bool FUN_008256d0();
    void FUN_00726c60(CardInfo* const&);
    void FUN_005ae3d0(CardInfo* const&);
    void FUN_00905820(CardInfo* const&);
};
struct MenuGlobalView : Menu129
{
};
extern const char DAT_01070cc0[], DAT_01070ca4[], DAT_01070c88[];
struct InputMenu
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
    int state;
    int result;
    int splitResult;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    P09TileS* text;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int bet;
    int splitBet;
    int funds;
    bool flag78;
    bool flag79;
    short unk7a;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    CardInfo cards[208];
    CardHand* dealer;
    CardHand* hand;
    CardHand* split;
    void HandleAction(int, void*);
    void UpdateButtonState(int);
    bool HasFlag(int);
    void SetFlag(int, bool);
    int DrawCard(void*, bool, bool);
    int FUN_00738ff0(CardHand*);
    void ClearField();
    void FUN_00738c30(int, float);
    void DealInitialCards();
    bool FUN_00739650(bool);
    void UpdateChipPositions();
    void FUN_007396e0(int, int, CardInfo*);
    void FUN_007399f0();
};

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
struct FUN_0096a2d0
{
    BJCard* item;
    FUN_0096a2d0* next;
    FUN_0096a2d0();
    BJCard** FUN_006815c0();
    FUN_0096a2d0* FUN_00726070();
    void FUN_00470470();
    void FUN_00905820(BJCard* const&);
};
struct GlobalObject_0041a250
{
    int id, flags, state;
    GlobalObject_0041a250();
    ~GlobalObject_0041a250();
};
template <> class BSStringT<char>
{
  public:
    char* data;
    unsigned short length, capacity;
    BSStringT();
    ~BSStringT();
    operator const char*() const;
};
class TESContainer
{
  public:
    int unk00, unk04, unk08;
    TESContainer();
    ~TESContainer();
    void FUN_004818e0(void*, int, void*);
    void FUN_004821a0(void*, bool);
};
struct BooleanHandler
{
    void FUN_0060c9c0(bool);
};
struct CasinoUpdate
{
    void* FUN_007316d0();
    int GetFieldAt210();
    BooleanHandler* FUN_00504e40();
    Stats129* FUN_00504e60();
};
struct PlayerUpdate
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
    virtual void Remove(void*, int, int, int, int, int, int, int, int, int);
    int FUN_00575610(void*);
    const char* FUN_008adcf0(void*, int, bool);
};
struct TimeUpdate
{
    int FUN_00825c00();
};
extern TimeUpdate g_timeGlobal;
bool __cdecl FUN_00702450(int);
struct InterfaceUpdate
{
    FUN_00a012d0_t* FUN_0045cd60();
};
struct SceneUpdate
{
    SceneUpdate* FUN_0043b4a0(int);
    void FUN_00a59c60(const Update90&);
};
struct ScenePointerUpdate
{
    SceneUpdate* FUN_00559450();
};
struct SequenceUpdate
{
    float FUN_00508100();
};
struct SequenceUpdateHandler
{
    void FUN_0047aab0(SequenceUpdate*, int, int, float, float, int);
    void FUN_0047b220(SequenceUpdate*, float);
    void FUN_0048fef0(float);
};
Audio129* __cdecl FUN_00453a70();
const char* __cdecl FUN_00482720(void*);
int __cdecl FUN_00406f60(BSStringT<char>*, const char*, ...);
void __cdecl FUN_004d5c60(int);
extern Settings129 DAT_011d3db4, DAT_011d3114, DAT_011d4e7c, DAT_011d5050, DAT_011d3a98, DAT_011d2ff4, DAT_011d25e0,
    DAT_011d3474, DAT_011d3f88;
extern float DAT_011d90e0;
extern int DAT_011d90dc;
extern const double DAT_01070d18;
extern const char DAT_0101c178[], DAT_01070d8c[], DAT_010208a0[], DAT_0103a830[], DAT_01070d74[], DAT_01070d5c[],
    DAT_01070d40[], DAT_01070d20[], DAT_01070d0c[], DAT_01070cf8[], DAT_01070ce4[], DAT_01019f08[];
struct BlackjackUpdate
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
    virtual int GetID();
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int state;
    int playerResult;
    int splitResult;
    Tile129* tile34;
    Tile129* tile38;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    Tile129* message;
    int unk05c;
    float payoutMultiplier;
    float shuffleThreshold;
    int skill;
    int bet;
    int splitBet;
    int balance;
    bool luckyWin, luckyLose;
    short unk07a;
    int lastTime;
    bool reward;
    char unk081, unk082, unk083;
    int counts[3];
    BJCard cards[208];

    FUN_0096a2d0* dealer;
    FUN_0096a2d0* player;
    FUN_0096a2d0* split;
    int decks;
    int remaining;
    bool sounded;
    char unkda5, unkda6, unkda7;
    float soundTime;
    bool standSoft17;
    char unkdad, unkdae, unkdaf;
    int flags;
    NiAVObject* root;
    NiAVObject* hand;
    NiAVObject* splitHand;
    NiAVObject* dealerHand;
    int unkdc4;
    int unkdc8;
    int unkdcc;
    int unkdd0;
    int unkdd4;
    int unkdd8;
    int unkddc;
    int unkde0;
    int unkde4;
    int unkde8;
    int unkdec;
    int unkdf0;
    SequenceUpdateHandler* tableAnim;
    SequenceUpdateHandler* playerAnim;
    SequenceUpdateHandler* splitAnim;
    SequenceUpdateHandler* dealerAnim;
    SequenceUpdate* tableStart;
    SequenceUpdate* tableEnd;
    SequenceUpdate* playerSeq[8];
    SequenceUpdate* splitSeq[8];
    SequenceUpdate* dealerSeq[8];
    SequenceUpdate* revealSeq;
    Tile129* FUN_00726070();
    int FUN_0059bb30();
    void FUN_00a1d910();
    bool HasFlag(int);
    void SetFlag(int, bool);
    int FUN_00738ff0(FUN_0096a2d0*);
    void FUN_007396e0(int, int, BJCard*);
    void FUN_007395a0();
    void UpdateButtonState(int);
    void FUN_00739970(bool);
    void UpdateCulledNodes();
    void UncullCardObjects();
    void ClearField();
    void HideArrowNodes();
    int DrawCard(FUN_0096a2d0*, bool, bool);
    void UpdateTileText();
    void FUN_007399d0();
    void FUN_00734db0();
};

// @fnv 0x00734db0
void BlackjackUpdate::FUN_00734db0()
{
    int dt = 0;
    float speed = 1.0f;
    static GlobalObject_0041a250 sound;
    bool active = FUN_00702450(GetID());
    if (!lastTime)
    {
        player = new FUN_0096a2d0;
        split = new FUN_0096a2d0;
        dealer = new FUN_0096a2d0;
        dt = 0;
        DAT_011d90e0 = 0.0f;
        DAT_011d90dc = 0;
    }
    else if (active)
    {
        dt = g_timeGlobal.FUN_00825c00() - lastTime;
        if (dt > 1000)
            dt = 0;
        if (DAT_011d90dc != state)
            DAT_011d90e0 = 0.0f;
        else
            DAT_011d90e0 += dt / 1000.0;
    }
    lastTime = g_timeGlobal.FUN_00825c00();
    DAT_011d90dc = state;
    if (!active)
        ((InterfaceUpdate*)FUN_004b7210())->FUN_0045cd60()->FUN_00a012d0(0xfa9, 255.0f, true);
    switch (state)
    {
    case 13:
        if (DAT_011d90e0 < 1.0)
            break;
        if (FUN_0059bb30() != 2)
        {
            ((InterfaceUpdate*)FUN_004b7210())->FUN_0045cd60()->FUN_00a012d0(0xfa9, 255.0f, true);
            FUN_00726070()->FUN_00700320(0x1772, 1);
            FUN_00a1d910();
            int difference =
                balance - ((PlayerUpdate*)DAT_011dea3c)->FUN_00575610(((CasinoUpdate*)DAT_011d9058)->FUN_007316d0());
            if (difference < 0)
            {
                ((PlayerUpdate*)DAT_011dea3c)
                    ->Remove(((CasinoUpdate*)DAT_011d9058)->FUN_007316d0(), 0, -difference, 0, 0, 0, 0, 0, 1, 0);
                BSStringT<char> msg;
                FUN_00406f60(&msg, DAT_0101c178, -difference,
                             FUN_00482720(((CasinoUpdate*)DAT_011d9058)->FUN_007316d0()), DAT_011d3114.FUN_00403df0(),
                             DAT_011d3db4.FUN_00403df0());
                DispatchMessageToSink(msg, 0, DAT_010208a0,
                                      (int)((PlayerUpdate*)DAT_011dea3c)
                                          ->FUN_008adcf0(((CasinoUpdate*)DAT_011d9058)->FUN_007316d0(), 1, false),
                                      DAT_010162c0, 0);
            }
            else if (difference > 0)
            {
                TESContainer inventory;
                inventory.FUN_004818e0(((CasinoUpdate*)DAT_011d9058)->FUN_007316d0(), difference, 0);
                if (DAT_011d9054->amount < ((CasinoUpdate*)DAT_011d9058)->GetFieldAt210())
                    inventory.FUN_004821a0(DAT_011dea3c, false);
                else
                {
                    inventory.FUN_004821a0(DAT_011dea3c, true);
                    BSStringT<char> msg2;
                    FUN_00406f60(&msg2, DAT_01070d8c, difference,
                                 FUN_00482720(((CasinoUpdate*)DAT_011d9058)->FUN_007316d0()),
                                 DAT_011d3114.FUN_00403df0(), DAT_011d4e7c.FUN_00403df0(), DAT_011d3abc.FUN_00403df0());
                    DispatchMessageToSink(msg2, 0, DAT_0103a830,
                                          (int)((PlayerUpdate*)DAT_011dea3c)
                                              ->FUN_008adcf0(((CasinoUpdate*)DAT_011d9058)->FUN_007316d0(), 1, false),
                                          DAT_010162c0, 0);
                }
            }
            if (reward)
            {
                BooleanHandler* quest = ((CasinoUpdate*)DAT_011d9058)->FUN_00504e40();
                if (quest)
                    quest->FUN_0060c9c0(true);
            }
        }
        break;
    case 1: {
        int previous = counts[2];
        float half = playerSeq[previous]->FUN_00508100() / 2.0;
        static float endTime = playerSeq[1]->FUN_00508100();
        if (dealerSeq[previous] && playerSeq[previous])
        {
            if (DAT_011d90e0 > 1.0)
                message->FUN_00700320(0xfa3, 0);
            Update90 scene(DAT_011d90e0, true, false);
            ((ScenePointerUpdate*)&g_011d9098)->FUN_00559450()->FUN_0043b4a0(0)->FUN_00a59c60(scene);
            if (DAT_011d90e0 == 0.0)
            {
                Update90 reset(0.0f, true, false);
                ((ScenePointerUpdate*)&g_011d9098)->FUN_00559450()->FUN_00a59c60(reset);
                FUN_00453a70()->FUN_00ad7550(DAT_01070d74, 0x121).Play(false);
                sounded = true;
                FUN_0096a2d0* p = player;
                FUN_0096a2d0* dealerNode = dealer;
                FUN_007396e0(0, 1, *p->FUN_006815c0());
                p = p->FUN_00726070();
                FUN_007396e0(0, 2, *p->FUN_006815c0());
                FUN_007396e0(2, 1, *dealerNode->FUN_006815c0());
                dealerNode = dealerNode->FUN_00726070();
                FUN_007396e0(2, 2, *dealerNode->FUN_006815c0());
                playerAnim->FUN_0047aab0(playerSeq[1], 0, 0, 1.0f, 0.0f, 0);
                dealerAnim->FUN_0047aab0(dealerSeq[1], 0, 0, 1.0f, 0.0f, 0);
                endTime = playerSeq[1]->FUN_00508100();
            }
            if (counts[0] == 1)
            {
                Update90 pu(DAT_011d90e0, true, false);
                ((ScenePointerUpdate*)&g_011d9098)->FUN_00559450()->FUN_0043b4a0(1)->FUN_00a59c60(pu);
            }
            if (counts[2] == 1 && DAT_011d90e0 >= half)
            {
                if (sounded && DAT_011d90e0 < playerSeq[1]->FUN_00508100())
                {
                    sounded = false;
                    FUN_00453a70()->FUN_00ad7550(DAT_01070d74, 0x121).Play(false);
                }
                Update90 du(DAT_011d90e0 - half, true, false);
                ((ScenePointerUpdate*)&g_011d9098)->FUN_00559450()->FUN_0043b4a0(3)->FUN_00a59c60(du);
            }
            if (counts[0] == 2 && DAT_011d90e0 >= playerSeq[1]->FUN_00508100())
            {
                if (!sounded && DAT_011d90e0 < playerSeq[1]->FUN_00508100() + half)
                {
                    sounded = true;
                    FUN_00453a70()->FUN_00ad7550(DAT_01070d74, 0x121).Play(false);
                }
                Update90 pu2(DAT_011d90e0 - playerSeq[previous]->FUN_00508100(), true, false);
                ((ScenePointerUpdate*)&g_011d9098)->FUN_00559450()->FUN_0043b4a0(1)->FUN_00a59c60(pu2);
            }
            if (counts[2] == 2 && DAT_011d90e0 >= playerSeq[1]->FUN_00508100() + half)
            {
                if (sounded)
                {
                    sounded = false;
                    FUN_00453a70()->FUN_00ad7550(DAT_01070d5c, 0x121).Play(false);
                }
                Update90 du2(DAT_011d90e0 - (playerSeq[1]->FUN_00508100() + half), true, false);
                ((ScenePointerUpdate*)&g_011d9098)->FUN_00559450()->FUN_0043b4a0(3)->FUN_00a59c60(du2);
            }
            if (DAT_011d90e0 >= endTime)
            {
                if (counts[0] == 1)
                {
                    counts[0]++;
                    playerAnim->FUN_0047b220(playerSeq[previous], 0.0f);
                    playerAnim->FUN_0047aab0(playerSeq[counts[0]], 0, 0, 1.0f, 0.0f, 0);
                    endTime = dealerSeq[1]->FUN_00508100() + half;
                }
                else if (counts[2] == 1)
                {
                    counts[2]++;
                    dealerAnim->FUN_0047b220(dealerSeq[previous], 0.0f);
                    dealerAnim->FUN_0047aab0(dealerSeq[counts[2]], 0, 0, 1.0f, 0.0f, 0);
                    endTime = playerSeq[1]->FUN_00508100() + dealerSeq[1]->FUN_00508100();
                }
                else if (counts[0] == 2)
                {
                    counts[0]++;
                    playerAnim->FUN_0047b220(playerSeq[previous], 0.0f);
                    endTime = dealerSeq[1]->FUN_00508100() + half + dealerSeq[2]->FUN_00508100();
                }
                else
                {
                    int value = FUN_00738ff0(player);
                    if (value == 21)
                    {
                        playerResult = 5;
                        SetFlag(0x20, true);
                    }
                    if (FUN_00738ff0(dealer) == 21)
                    {
                        SetFlag(0x20, true);
                        if (playerResult == 5)
                            playerResult = 2;
                        else
                            playerResult = 1;
                    }
                    if (!HasFlag(0x20))
                        UpdateBetTiles(false);
                    if (balance >= bet * 2)
                    {
                        if (value == 11)
                            SetFlag(0x40, true);
                        else
                            FUN_007395a0();
                    }
                    else
                    {
                        SetFlag(0x40, false);
                        SetFlag(0x100, false);
                        SetFlag(4, false);
                    }
                    UpdateButtonState(10);
                    endTime = 0.0f;
                    counts[2]++;
                    dealerAnim->FUN_0047b220(dealerSeq[previous], 0.0f);
                    if (HasFlag(0x20))
                        state = 8;
                    else
                        state = 4;
                }
            }
        }
        break;
    }
    case 2: {
        bool onSplit = HasFlag(0x10);
        if (onSplit)
        {
            if (!splitSeq[counts[1]])
                break;
        }
        else
        {
            if (!playerSeq[counts[0]])
                break;
        }
        if (DAT_011d90e0 > 1.0)
            message->FUN_00700320(0xfa3, 0);
        Update90 scene(DAT_011d90e0, true, false);
        ((ScenePointerUpdate*)&g_011d9098)->FUN_00559450()->FUN_0043b4a0(0)->FUN_00a59c60(scene);
        if (DAT_011d90e0 == 0.0)
        {
            FUN_00453a70()->FUN_00ad7550(DAT_01070d74, 0x121).Play(false);
            FUN_0096a2d0* curr = 0;
            BJCard* last = 0;
            int drawn = 0;
            int handId = 0;
            if (onSplit)
            {
                handId = 1;
                splitAnim->FUN_0047aab0(splitSeq[counts[1]], 0, 0, 1.0f, 0.0f, 0);
                curr = split;
                while (curr && *curr->FUN_006815c0() && drawn != counts[1])
                {
                    last = *curr->FUN_006815c0();
                    curr = curr->FUN_00726070();
                    drawn++;
                }
            }
            else
            {
                playerAnim->FUN_0047aab0(playerSeq[counts[0]], 0, 0, 1.0f, 0.0f, 0);
                curr = player;
                while (curr && *curr->FUN_006815c0() && drawn != counts[0])
                {
                    last = *curr->FUN_006815c0();
                    curr = curr->FUN_00726070();
                    drawn++;
                }
            }
            while (curr && *curr->FUN_006815c0() && drawn)
            {
                last = *curr->FUN_006815c0();
                curr = curr->FUN_00726070();
                drawn++;
            }
            FUN_007396e0(handId, drawn, last);
        }
        Update90 hu(DAT_011d90e0, true, false);
        if (onSplit)
            ((ScenePointerUpdate*)&g_011d9098)->FUN_00559450()->FUN_0043b4a0(2)->FUN_00a59c60(hu);
        else
            ((ScenePointerUpdate*)&g_011d9098)->FUN_00559450()->FUN_0043b4a0(1)->FUN_00a59c60(hu);
        if ((onSplit && DAT_011d90e0 >= splitSeq[counts[1]]->FUN_00508100()) ||
            (!onSplit && DAT_011d90e0 >= playerSeq[counts[0]]->FUN_00508100()))
        {
            if (onSplit)
            {
                splitAnim->FUN_0047b220(splitSeq[counts[1]], 0.0f);
                counts[1]++;
            }
            else
            {
                playerAnim->FUN_0047b220(playerSeq[counts[0]], 0.0f);
                counts[0]++;
            }
            if (HasFlag(0x4000))
                state = 3;
            else if (HasFlag(0x1000))
                state = 8;
            else if (HasFlag(8) && HasFlag(0x400) && HasFlag(0x800))
                state = 8;
            else if (!HasFlag(8) && HasFlag(0x400))
                state = 8;
            else
                state = 4;
        }
        break;
    }
    case 3:
        if (!splitSeq[1] || !splitSeq[2] || !playerSeq[2])
            break;
        if (counts[1] == 1)
        {
            SetFlag(0x4000, true);
            FUN_00739970(true);
            playerAnim->FUN_0047aab0(playerSeq[2], 0, 0, 1.0f, 0.0f, 0);
            Update90 pu(0.0f, true, false);
            Update90 du(0.0f, true, false);
            ((ScenePointerUpdate*)&g_011d9098)->FUN_00559450()->FUN_0043b4a0(3)->FUN_00a59c60(du);
            ((ScenePointerUpdate*)&g_011d9098)->FUN_00559450()->FUN_0043b4a0(1)->FUN_00a59c60(pu);
            SetFlag(0x10, true);
            counts[0]--;
            state = 2;
        }
        else if (counts[0] == 2)
        {
            SetFlag(0x10, false);
            state = 2;
        }
        else if (counts[1] == 2)
        {
            SetFlag(0x10, true);
            state = 2;
        }
        else
        {
            SetFlag(0x4000, false);
            SetFlag(0x10, false);
            if (playerResult == 5 && splitResult == 5)
                state = 12;
            else
                state = 4;
        }
        break;
    case 7:
        if (playerSeq[0] && splitSeq[0] && dealerSeq[0])
        {
            if (DAT_011d90e0 > 1.0)
                message->FUN_00700320(0xfa3, 0);
            if (DAT_011d90e0 == 0.0 && !sounded)
            {
                FUN_00453a70()->FUN_00ad7550(DAT_01070d40, 0x121).Play(false);
                Update90 reset(0.0f, true, false);
                ((ScenePointerUpdate*)&g_011d9098)->FUN_00559450()->FUN_00a59c60(reset);
                tableAnim->FUN_0047aab0(tableStart, 0, 0, 1.0f, 0.0f, 0);
                playerAnim->FUN_0047aab0(playerSeq[0], 0, 0, 1.0f, 0.0f, 0);
                splitAnim->FUN_0047aab0(splitSeq[0], 0, 0, 1.0f, 0.0f, 0);
                UpdateCulledNodes();
            }
            if (!sounded && DAT_011d90e0 < playerSeq[0]->FUN_00508100())
            {
                Update90 tableUpdate(DAT_011d90e0, true, false);
                Update90 playerUpdate(DAT_011d90e0, true, false);
                Update90 splitUpdate(DAT_011d90e0, true, false);
                ((ScenePointerUpdate*)&g_011d9098)->FUN_00559450()->FUN_0043b4a0(0)->FUN_00a59c60(tableUpdate);
                ((ScenePointerUpdate*)&g_011d9098)->FUN_00559450()->FUN_0043b4a0(1)->FUN_00a59c60(playerUpdate);
                ((ScenePointerUpdate*)&g_011d9098)->FUN_00559450()->FUN_0043b4a0(2)->FUN_00a59c60(splitUpdate);
            }
            else if (sounded && DAT_011d90e0 - soundTime < dealerSeq[0]->FUN_00508100())
            {
                Update90 tableUpdate2(DAT_011d90e0 - soundTime, true, false);
                Update90 dealerUpdate(DAT_011d90e0 - soundTime, true, false);
                ((ScenePointerUpdate*)&g_011d9098)->FUN_00559450()->FUN_0043b4a0(0)->FUN_00a59c60(tableUpdate2);
                ((ScenePointerUpdate*)&g_011d9098)->FUN_00559450()->FUN_0043b4a0(3)->FUN_00a59c60(dealerUpdate);
            }
            if (DAT_011d90e0 >= playerSeq[0]->FUN_00508100() && !sounded)
            {
                tableAnim->FUN_0047b220(tableStart, 0.0f);
                tableAnim->FUN_0047aab0(tableEnd, 0, 0, 1.0f, 0.0f, 0);
                dealerAnim->FUN_0047aab0(dealerSeq[0], 0, 0, 1.0f, 0.0f, 0);
                FUN_00453a70()->FUN_00ad7550(DAT_01070d20, 0x121).Play(false);
                sounded = true;
                soundTime = DAT_011d90e0;
                Update90 tableUpdate2(0.0f, true, false);
                Update90 dealerUpdate(0.0f, true, false);
                ((ScenePointerUpdate*)&g_011d9098)->FUN_00559450()->FUN_0043b4a0(0)->FUN_00a59c60(tableUpdate2);
                ((ScenePointerUpdate*)&g_011d9098)->FUN_00559450()->FUN_0043b4a0(3)->FUN_00a59c60(dealerUpdate);
            }
            else if (DAT_011d90e0 - soundTime >= dealerSeq[0]->FUN_00508100() && sounded)
            {
                tableAnim->FUN_0047b220(tableEnd, 0.0f);
                dealerAnim->FUN_0047b220(dealerSeq[0], 0.0f);
                tableAnim->FUN_0048fef0(0.0f);
                dealerAnim->FUN_0048fef0(0.0f);
                playerAnim->FUN_0048fef0(0.0f);
                splitAnim->FUN_0048fef0(0.0f);
                UncullCardObjects();
                ClearField();
                FUN_00739970(false);
                sounded = false;
                UpdateBetTiles(true);
                int limit = ((CasinoUpdate*)DAT_011d9058)->FUN_00504e60()->limit;
                int winnings = DAT_011d9054->amount;
                int curTier = DAT_011d9054->flags;
                for (int i = 1; i < 5; i++)
                {
                    if (i <= curTier)
                        reward = false;
                    else if (limit * (i * 0.25) <= winnings)
                    {
                        DAT_011d9054->flags = (short)i;
                        reward = true;
                    }
                }
                if (!reward)
                    state = 10;
                else
                    FUN_00731d30();
                for (int j = 0; j < 3; j++)
                    counts[j] = 1;
            }
        }
        else
            state = 10;
        break;
    case 8: {
        if (DAT_011d90e0 > 1.0)
            message->FUN_00700320(0xfa3, 0);
        if (!revealSeq)
        {
            state = 11;
            break;
        }
        Update90 su(DAT_011d90e0, true, false);
        ((ScenePointerUpdate*)&g_011d9098)->FUN_00559450()->FUN_0043b4a0(0)->FUN_00a59c60(su);
        if (DAT_011d90e0 == 0.0)
        {
            SetFlag(0x400, true);
            SetFlag(0x800, true);
            HideArrowNodes();
            FUN_00453a70()->FUN_00ad7550(DAT_01070d5c, 0x121).Play(false);
            dealerAnim->FUN_0047aab0(revealSeq, 0, 0, 1.0f, 0.0f, 0);
        }
        if (DAT_011d90e0 < revealSeq->FUN_00508100())
        {
            Update90 du(DAT_011d90e0, true, false);
            ((ScenePointerUpdate*)&g_011d9098)->FUN_00559450()->FUN_0043b4a0(3)->FUN_00a59c60(du);
        }
        if (DAT_011d90e0 >= revealSeq->FUN_00508100())
        {
            dealerAnim->FUN_0047b220(revealSeq, 0.0f);
            state = 11;
        }
        break;
    }
    case 9: {
        if (DAT_011d90e0 > 1.0)
            message->FUN_00700320(0xfa3, 0);
        if (!dealerSeq[counts[2]])
        {
            if (FUN_00738ff0(dealer) > 21 || HasFlag(0x2000))
                state = 12;
            else
                state = 11;
            break;
        }
        Update90 su(DAT_011d90e0, true, false);
        ((ScenePointerUpdate*)&g_011d9098)->FUN_00559450()->FUN_0043b4a0(0)->FUN_00a59c60(su);
        if (DAT_011d90e0 == 0.0)
        {
            FUN_00453a70()->FUN_00ad7550(DAT_01070d5c, 0x121).Play(false);
            HideArrowNodes();
            FUN_0096a2d0* curr = dealer;
            BJCard* last = 0;
            int drawn = 0;
            while (curr && *curr->FUN_006815c0())
            {
                last = *curr->FUN_006815c0();
                curr = curr->FUN_00726070();
                drawn++;
            }
            if (last)
                FUN_007396e0(2, drawn, last);
            dealerAnim->FUN_0047aab0(dealerSeq[counts[2]], 0, 0, 1.0f, 0.0f, 0);
        }
        if (DAT_011d90e0 < dealerSeq[counts[2]]->FUN_00508100())
        {
            Update90 du(DAT_011d90e0, true, false);
            ((ScenePointerUpdate*)&g_011d9098)->FUN_00559450()->FUN_0043b4a0(3)->FUN_00a59c60(du);
        }
        if (DAT_011d90e0 >= dealerSeq[counts[2]]->FUN_00508100())
        {
            dealerAnim->FUN_0047b220(dealerSeq[counts[2]], 0.0f);
            counts[2]++;
            if (FUN_00738ff0(dealer) > 21 || HasFlag(0x2000))
                state = 12;
            else
                state = 11;
        }
        break;
    }
    case 4:
        if (playerResult)
        {
            if (HasFlag(8))
            {
                if (splitResult)
                    state = 8;
            }
            else
                state = 8;
        }
        if (HasFlag(0x400))
        {
            if (HasFlag(8))
            {
                if (HasFlag(0x800))
                    state = 8;
            }
            else
                state = 8;
        }
        break;
    case 11: {
        SetFlag(0x1000, true);
        if (HasFlag(8))
        {
            if (playerResult == 4 && splitResult == 4)
            {
                SetFlag(0x2000, true);
                state = 12;
                break;
            }
        }
        else if (playerResult == 4 || playerResult == 6)
        {
            SetFlag(0x2000, true);
            state = 12;
            break;
        }
        if (HasFlag(0x20))
        {
            state = 12;
            break;
        }
        int dealerTotal = FUN_00738ff0(dealer);
        int chosen = 0;
        int count = 0;
        FUN_0096a2d0* node = dealer;
        bool soft = false;
        while (node && *node->FUN_006815c0())
        {
            count++;
            if ((*node->FUN_006815c0())->rank == 12)
                soft = true;
            node = node->FUN_00726070();
        }
        if ((dealerTotal < 17 || (dealerTotal == 17 && soft && !standSoft17)) && count < 7)
        {
            chosen = DrawCard(dealer, true, true);
            dealer->FUN_00905820(&cards[chosen]);
            state = 9;
        }
        else
            state = 12;
        break;
    }
    case 12: {
        FUN_004d5c60(41);
        int playerValue = FUN_00738ff0(player);
        int dealerValue = FUN_00738ff0(dealer);
        int payout = 0;
        char buf[260];
        if (!playerResult)
        {
            if ((playerValue > dealerValue && playerValue < 22) || (playerValue < 22 && dealerValue > 21))
                playerResult = 3;
            else if ((playerValue < dealerValue && dealerValue < 22) || playerValue > 21)
                playerResult = 1;
            else
                playerResult = 2;
        }
        if (HasFlag(8))
        {
            playerValue = FUN_00738ff0(split);
            if (!splitResult)
            {
                if ((playerValue > dealerValue && playerValue < 22) || (playerValue < 22 && dealerValue > 21))
                    splitResult = 3;
                else if ((playerValue < dealerValue && dealerValue < 22) || playerValue > 21)
                    splitResult = 1;
                else
                    splitResult = 2;
            }
        }
        switch (playerResult)
        {
        case 1:
        case 4:
            payout += -bet;
            break;
        case 3:
            payout += bet;
            break;
        case 5:
            payout += (int)(bet * payoutMultiplier + DAT_01070d18);
            break;
        case 6:
            payout += -(int)(bet / 2.0 + DAT_01070d18);
            break;
        }
        switch (splitResult)
        {
        case 1:
        case 4:
            payout += -splitBet;
            break;
        case 3:
            payout += splitBet;
            break;
        case 5:
            payout += (int)(splitBet * payoutMultiplier + 0.5);
            break;
        }
        balance += payout;
        ((BlackjackUpdate*)DAT_011d9050)->tile38->SetTraitAndReset((int)DAT_011d9048, 1.0f);
        ((BlackjackUpdate*)DAT_011d9050)->tile38->FUN_00700320((int)DAT_011d9048, balance);
        DAT_011d9054->amount += payout;
        UpdateTileText();
        if (payout > 0)
        {
            if (luckyWin)
                FUN_00406d00(buf, 260, DAT_01070d0c, DAT_011d3a98.FUN_00403df0(), payout, DAT_011d5050.FUN_00403df0(),
                             DAT_011d3114.FUN_00403df0());
            else
                FUN_00406d00(buf, 260, DAT_01070d0c, DAT_011d2ff4.FUN_00403df0(), payout, DAT_011d5050.FUN_00403df0(),
                             DAT_011d3114.FUN_00403df0());
            FUN_00453a70()->FUN_00ad7550(DAT_01070cf8, 0x121).Play(false);
            ((BlackjackUpdate*)DAT_011d9050)->message->SetTraitAndReset(0xfc4, 1.0f);
            ((BlackjackUpdate*)DAT_011d9050)->message->FUN_00a01350(0xfc4, buf, true);
            ((BlackjackUpdate*)DAT_011d9050)->message->FUN_00700320(0xfa3, 1);
        }
        else if (payout < 0)
        {
            if (luckyLose)
                FUN_00406d00(buf, 260, DAT_01070d0c, DAT_011d25e0.FUN_00403df0(), -payout, DAT_011d5050.FUN_00403df0(),
                             DAT_011d3114.FUN_00403df0());
            else
                FUN_00406d00(buf, 260, DAT_01070d0c, DAT_011d3474.FUN_00403df0(), -payout, DAT_011d5050.FUN_00403df0(),
                             DAT_011d3114.FUN_00403df0());
            FUN_00453a70()->FUN_00ad7550(DAT_01070ce4, 0x121).Play(false);
            ((BlackjackUpdate*)DAT_011d9050)->message->SetTraitAndReset(0xfc4, 1.0f);
            ((BlackjackUpdate*)DAT_011d9050)->message->FUN_00a01350(0xfc4, buf, true);
            ((BlackjackUpdate*)DAT_011d9050)->message->FUN_00700320(0xfa3, 1);
        }
        else
        {
            FUN_00406d00(buf, 260, DAT_01019f08, DAT_011d3f88.FUN_00403df0());
            ((BlackjackUpdate*)DAT_011d9050)->message->SetTraitAndReset(0xfc4, 1.0f);
            ((BlackjackUpdate*)DAT_011d9050)->message->FUN_00a01350(0xfc4, buf, true);
            ((BlackjackUpdate*)DAT_011d9050)->message->FUN_00700320(0xfa3, 1);
        }
        player->FUN_00470470();
        dealer->FUN_00470470();
        if (HasFlag(8))
        {
            split->FUN_00470470();
            ((BlackjackUpdate*)DAT_011d9050)->tile34->SetTraitAndReset((int)DAT_011d9048, 1.0f);
            ((BlackjackUpdate*)DAT_011d9050)->tile34->FUN_00700320((int)DAT_011d9048, bet);
            splitBet = 0;
        }
        if (HasFlag(0x80))
        {
            bet /= 2;
            ((BlackjackUpdate*)DAT_011d9050)->tile34->SetTraitAndReset((int)DAT_011d9048, 1.0f);
            ((BlackjackUpdate*)DAT_011d9050)->tile34->FUN_00700320((int)DAT_011d9048, bet);
        }
        if (balance < bet)
        {
            bet = balance;
            ((BlackjackUpdate*)DAT_011d9050)->tile34->SetTraitAndReset((int)DAT_011d9048, 1.0f);
            ((BlackjackUpdate*)DAT_011d9050)->tile34->FUN_00700320((int)DAT_011d9048, bet);
        }
        state = 7;
        break;
    }
    case 10:
        if (remaining < decks * 52 * shuffleThreshold)
            FUN_007399d0();
        if (DAT_011d90e0 > 1.0)
            message->FUN_00700320(0xfa3, 0);
        if (balance < bet)
        {
            bet = balance;
            ((BlackjackUpdate*)DAT_011d9050)->tile34->SetTraitAndReset((int)DAT_011d9048, 1.0f);
            ((BlackjackUpdate*)DAT_011d9050)->tile34->FUN_00700320((int)DAT_011d9048, bet);
        }
        if (balance < DAT_0119fe40)
        {
            char warning[260];
            FUN_00406d00(warning, 260, DAT_011d2424.FUN_00403df0());
            DispatchMessageToSink(warning, 0, DAT_01049638, 0, DAT_010162c0, 0);
            FUN_00453a70()->FUN_00ad7550(DAT_01025cc4, 0x121).Play(false);
            FUN_00731d30();
        }
        break;
    }
}
