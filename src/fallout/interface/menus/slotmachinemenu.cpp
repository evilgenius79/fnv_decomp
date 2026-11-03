
// src/fallout/interface/menus/slotmachinemenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/slotmachinemenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct SlotMachineMenu
{
    int FUN_007c0800();
};

// @fnv 0x007c0800
int SlotMachineMenu::FUN_007c0800()
{
    return 0x438;
}

// @fnv 0x007c1440
int __cdecl FUN_007c1440()
{
    return 0x438;
}

struct FUN_007c0840Host
{
    void FUN_007c0870();
    void* FUN_007c0840(unsigned int);
};
void __cdecl _Deallocate(void*);
// Calls FUN_007c0870, then deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x007c0840
void* FUN_007c0840Host::FUN_007c0840(unsigned int flags)
{
    FUN_007c0870();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_007c1450_shell
{
    int m[0x2a];
    char FUN_007c1450();
};
// @fnv 0x007c1450
char FUN_007c1450_shell::FUN_007c1450()
{
    for (int i = 0; i < 10; ++i)
    {
        if (m[0x28 + i] == 0)
            return 0;
    }
    return 1;
}

namespace fnv_007c0810 {
struct Tile;
struct SlotMachineMenu
{
    char pad[0xa0];
    Tile* m_pTiles[40];
    void SetTile(int id, Tile* tile);
};

// @fnv 0x007c0810
void SlotMachineMenu::SetTile(int aiIndex, Tile* tile)
{
    if (aiIndex >= 0 && aiIndex < 10)
    {
        m_pTiles[aiIndex] = tile;
    }
}
}  // namespace fnv_007c0810

struct FUN_007c5760_shell
{
    int pad[0x3a];
    int m_aiValues[3];
    int FUN_007c5760();
};
// @fnv 0x007c5760
int FUN_007c5760_shell::FUN_007c5760()
{
    int wildcount = 0;
    for (int i = 0; i < 3; i++)
    {
        if (m_aiValues[i] == 12)
            wildcount++;
    }
    if (m_aiValues[0] == m_aiValues[1] && m_aiValues[0] == m_aiValues[2] && m_aiValues[1] % 2 == 0)
        return 6;
    else if (wildcount == 2)
        return 5;
    else if (wildcount == 1)
        return 4;
    else if (m_aiValues[0] == 12 || m_aiValues[1] == 12 || m_aiValues[2] == 12)
        return 2;
    else if ((m_aiValues[1] == m_aiValues[2] && m_aiValues[1] % 2 == 0) ||
             (m_aiValues[0] == m_aiValues[2] && m_aiValues[0] % 2 == 0) ||
             (m_aiValues[1] == m_aiValues[0] && m_aiValues[0] % 2 == 0))
        return 1;
    else
        return 0;
}

struct GlobalObject_0040c150
{
    const char* GetMenuTitle();
};
struct FNStub
{
    const char* GetFullName();
};
struct Tile
{
    void Set(int id, const char* str, bool propagate);
};
int _sprintf_s(char* buf, unsigned int size, const char* fmt, ...);
int BSStringLength(const char* str);
extern const char DAT_01012058[];
extern GlobalObject_0040c150 g_011d3e08;
extern int DAT_011da99c;
extern int* DAT_011da9a8;
extern char* DAT_011da9ac;

struct FUN_007c5e60_shell
{
    void* m_pVtbl;
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
    Tile* m_tile;
    void UpdateTileText();
};

// @fnv 0x007c5e60
void FUN_007c5e60_shell::UpdateTileText()
{
    char tstring[260];
    int ilen;
    int i;

    _sprintf_s(tstring, 0x104, "%s %s%i", ((FNStub*)(DAT_011da9ac + 0x18))->GetFullName(), g_011d3e08.GetMenuTitle(),
               DAT_011da9a8[1]);
    ilen = BSStringLength(tstring);
    if (ilen < 0x17)
    {
        _sprintf_s(tstring, 0x104, DAT_01012058, ((FNStub*)(DAT_011da9ac + 0x18))->GetFullName(),
                   g_011d3e08.GetMenuTitle());
        for (i = 0; i < 0x17 - ilen; i++)
        {
            tstring[ilen + (i - 1)] = ' ';
            tstring[ilen + i] = 0;
        }
        _sprintf_s(tstring, 0x104, "%s%i", tstring, DAT_011da9a8[1]);
    }
    m_tile->Set(DAT_011da99c, tstring, true);
}

struct AnimIdle;
struct Accum_00733500;

struct S148c0
{
    void FUN_007148c0(int, int);
};

struct MiddleLowProcess
{
    Accum_00733500* GetProcessInteger();
};

struct BSFaceGenNiNode
{
    void* GetAnimationData();
};

struct GO
{
    unsigned int value;

    GO(int);
    ~GO();
    operator unsigned int() const;
    void operator=(void*);
};

struct GlobalObject_00633c90 : GO
{
};

struct Mgr_00733500
{
    AnimIdle* FUN_007fd640();
};

struct NiAdditionalGeometryData
{
    static void* GetShadowSceneNodeForIndex(int);
};

struct BSShaderRenderUtility
{
    static void SetRenderCamera(AnimIdle*, AnimIdle*, bool);
};

struct Accum_00733500
{
    void FUN_00c4f270(int);
    void FUN_004a0fd0(AnimIdle*);
    void FUN_00c4f2d0();
};

S148c0* __cdecl FUN_0043c4b0();
AnimIdle* __cdecl FUN_0045c670();
void __cdecl UpdateCameraFrustum(AnimIdle*, float);
Mgr_00733500* __cdecl _FUN_004b7210();
void __cdecl FUN_00b6bee0(AnimIdle*, void*, Accum_00733500*);

extern GlobalObject_00633c90 g_011da9d0;
extern const float g_011db5ec_arg1;

// @fnv 0x007c19c0
void FUN_007c19c0()
{
    FUN_0043c4b0()->FUN_007148c0(0, 4);

    AnimIdle* go = FUN_0045c670();
    Accum_00733500* accum = ((MiddleLowProcess*)go)->GetProcessInteger();
    accum->FUN_00c4f270(1);

    AnimIdle* anim2 = (AnimIdle*)(unsigned int)g_011da9d0;
    UpdateCameraFrustum(anim2, g_011db5ec_arg1);

    GO selected((int)_FUN_004b7210()->FUN_007fd640());
    accum->FUN_004a0fd0((AnimIdle*)(unsigned int)selected);

    AnimIdle* anim = anim2 ? anim2 : (AnimIdle*)((BSFaceGenNiNode*)go)->GetAnimationData();

    FUN_00b6bee0(anim, NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1), accum);
    BSShaderRenderUtility::SetRenderCamera(anim, (AnimIdle*)(unsigned int)selected, false);

    accum->FUN_004a0fd0(0);
    selected = 0;
    accum->FUN_00c4f2d0();
}

struct NiFixedString
{
    const char* m_psz;
    NiFixedString(const char*);
    ~NiFixedString();
};
struct NiUpdateData
{
    float m_00;
    int m_04;
    float m_08;
    NiUpdateData(float, bool, int);
};
struct NiBoundW7
{
    float FUN_0084d030();
};
struct CtrlObj
{
    CtrlObj* FUN_0047a520(const NiFixedString&);
    void FUN_0048fef0(float);
    void FUN_0047aab0(CtrlObj*, int, int, float, float, int);
};
struct AVObj
{
    CtrlObj* FUN_00a5c570(const void*);
};
struct NiNodeW7
{
    virtual void Vf00();
    virtual void Vf01();
    virtual void Vf02();
    virtual void Vf03();
    virtual void Vf04();
    virtual void Vf05();
    virtual void Vf06();
    virtual void Vf07();
    virtual void Vf08();
    virtual void Vf09();
    virtual void Vf10();
    virtual void Vf11();
    virtual void Vf12();
    virtual void Vf13();
    virtual void Vf14();
    virtual void Vf15();
    virtual void Vf16();
    virtual void Vf17();
    virtual void Vf18();
    virtual void Vf19();
    virtual void Vf20();
    virtual void Vf21();
    virtual void Vf22();
    virtual void Vf23();
    virtual void Vf24();
    virtual void Vf25();
    virtual void Vf26();
    virtual void Vf27();
    virtual void Vf28();
    virtual void Vf29();
    virtual void Vf30();
    virtual void Vf31();
    virtual void Vf32();
    virtual void Vf33();
    virtual void Vf34();
    virtual void Vf35();
    virtual void Vf36();
    virtual void Vf37();
    virtual void Vf38();
    virtual void Vf39();
    virtual void Vf40();
    virtual void Vf41();
    virtual void Vf42();
    virtual void Vf43();
    virtual void Vf44();
    virtual void Vf45();
    virtual void Vf46();
    virtual void Vf47();
    virtual void Vf48();
    virtual void Vf49();
    virtual void Vf50();
    virtual void Vf51();
    virtual void Vf52();
    virtual void Vf53();
    virtual void Vf54();
    virtual void Vf55(void*, int);
    void FUN_0043fa80(const void*);
    void FUN_004bc1f0(float, float, float);
    void FUN_00a59c60(const NiUpdateData&);
    NiBoundW7* FUN_0043d450();
};
struct ShadowSceneNode : NiNodeW7
{
    void FUN_00b5ca70(NiNodeW7*, float);
};
ShadowSceneNode* __cdecl FUN_00450b80(int);
struct GObjW7
{
    NiNodeW7* FUN_00559450();
};
struct GlobalObject_00633c90;
extern GlobalObject_00633c90 g_011da9fc;
extern GlobalObject_00633c90 g_011da9d0;
struct MatW7
{
    float m_00;
    float m_04;
    float m_08;
    float m_0c;
    float m_10;
    float m_14;
    float m_18;
    float m_1c;
    float m_20;
    void FUN_006815c0();
    void FUN_00524ac0(float);
    void FUN_004a0c90(float);
    MatW7 FUN_0043f8d0(MatW7*);
};
struct NiMemObject
{
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
struct FUN_00a5ecb0 : NiMemObject
{
    int m[0x2b];
    FUN_00a5ecb0(unsigned int);
};
extern int DAT_011f36ac;
extern float DAT_0105478c;
extern float DAT_0107678c;
void __cdecl FUN_00a6d2d0(AVObj*);
struct MenuW7
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000c;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001c;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002c;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003c;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004c;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005c;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006c;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007c;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008c;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009c;
    int unk00a0;
    int unk00a4;
    int unk00a8;
    int unk00ac;
    int unk00b0;
    int unk00b4;
    int unk00b8;
    int unk00bc;
    int unk00c0;
    int unk00c4;
    int unk00c8;
    int unk00cc;
    int unk00d0;
    int unk00d4;
    int unk00d8;
    int unk00dc;
    int unk00e0;
    int unk00e4;
    int unk00e8;
    int unk00ec;
    int unk00f0;
    int unk00f4;
    int unk00f8;
    int unk00fc;
    int unk0100;
    AVObj* m_104;
    AVObj* m_108[3];
    int unk0114;
    int unk0118;
    int unk011c;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012c;
    int unk0130;
    CtrlObj* m_134;
    CtrlObj* m_138;
    CtrlObj* m_13c;
    CtrlObj* m_140;
    CtrlObj* m_144;
    CtrlObj* m_148[3];
    void InitPayoutMenu();
    void* FUN_007c2180();
    void FUN_007c4d70();
    void FUN_007c40b0();
};
static const char kPayoutIn[] = "Payout_In";
// @fnv 0x007c1af0
void MenuW7::InitPayoutMenu()
{
    ((GO&)g_011da9fc) = new FUN_00a5ecb0(0);
    ((GObjW7*)(void*)&g_011da9fc)->FUN_00559450()->Vf55(m_104, 1);
    ((GObjW7*)(void*)&g_011da9fc)->FUN_00559450()->Vf55(m_108[0], 1);
    ((GObjW7*)(void*)&g_011da9fc)->FUN_00559450()->Vf55(m_108[1], 1);
    ((GObjW7*)(void*)&g_011da9fc)->FUN_00559450()->Vf55(m_108[2], 1);
    MatW7 xObjB;
    MatW7 objC7;
    xObjB.FUN_006815c0();
    objC7.FUN_006815c0();
    xObjB.FUN_00524ac0(1.5707963705062866f);
    objC7.FUN_004a0c90(1.5707963705062866f);
    ((GObjW7*)(void*)&g_011da9fc)->FUN_00559450()->FUN_0043fa80((const void*)&xObjB.FUN_0043f8d0(&objC7));
    ((GObjW7*)(void*)&g_011da9fc)->FUN_00559450()->FUN_004bc1f0(DAT_0105478c, DAT_0107678c, 0.0f);
    NiUpdateData upd1(0.0f, false, 0);
    ((GObjW7*)(void*)&g_011da9fc)->FUN_00559450()->FUN_00a59c60(upd1);
    CtrlObj* xPCtrl = m_104->FUN_00a5c570(&DAT_011f36ac);
    if (xPCtrl != 0)
    {
        m_134 = xPCtrl;
        m_138 = m_134->FUN_0047a520(NiFixedString("Forward"));
        m_13c = m_134->FUN_0047a520(NiFixedString("Backward"));
        m_140 = m_134->FUN_0047a520(NiFixedString(kPayoutIn));
        m_144 = m_134->FUN_0047a520(NiFixedString("Payout_Out"));
        m_134->FUN_0048fef0(0.0f);
        if (m_138 != 0)
        {
            m_134->FUN_0047aab0(m_138, 0, 1, 1.0f, 0.0f, 0);
        }
        FUN_00a6d2d0(m_104);
    }
    CtrlObj* arr12[3];
    CtrlObj* aarr2[3];
    int oI;
    for (oI = 0; oI < 3; oI++)
    {
        arr12[oI] = m_108[oI]->FUN_00a5c570(&DAT_011f36ac);
    }
    int jX;
    for (jX = 0; jX < 3; jX++)
    {
        if (arr12[jX] != 0)
        {
            aarr2[jX] = arr12[jX];
            m_148[jX] = aarr2[jX]->FUN_0047a520(NiFixedString("Forward"));
            aarr2[jX]->FUN_0048fef0(0.0f);
            if (m_148[jX] != 0)
            {
                aarr2[jX]->FUN_0047aab0(m_148[jX], 0, 1, 1.0f, 0.0f, 0);
            }
            FUN_00a6d2d0(m_108[jX]);
        }
    }
    NiUpdateData _upd2(0.0f, false, 0);
    ((GObjW7*)(void*)&g_011da9fc)->FUN_00559450()->FUN_00a59c60(_upd2);
    ((GO&)g_011da9d0) = FUN_007c2180();
    FUN_00450b80(1)->Vf55(((GObjW7*)(void*)&g_011da9fc)->FUN_00559450(), 1);
    float fTemp0 = ((GObjW7*)(void*)&g_011da9fc)->FUN_00559450()->FUN_0043d450()->FUN_0084d030() * 3.0;
    FUN_00450b80(1)->FUN_00b5ca70(((GObjW7*)(void*)&g_011da9fc)->FUN_00559450(), fTemp0);
    FUN_007c4d70();
    FUN_007c40b0();
}

struct FUN_007c56e0_shell
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
    int sourceValues[10];
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
    int valueCount;
    int unkD4;
    int unkD8;
    int savedResults[3];
    int currentResults[3];

    int FUN_007c5760();
    void FUN_007c56e0();
};

int __cdecl FUN_00944460(int, int);

// @fnv 0x007c56e0
void FUN_007c56e0_shell::FUN_007c56e0()
{
    for (int i = 0; i < 3; ++i)
    {
        savedResults[i] = currentResults[i];
        currentResults[i] = sourceValues[FUN_00944460(0, valueCount * 2 - 1)];
    }

    FUN_007c5760();
}

struct PlayerCharacter
{
    void FUN_00969b20();
};
extern PlayerCharacter* g_thePlayer;

struct SlotModelSource
{
    virtual void Vf00();
    virtual void Vf01();
    virtual void Vf02();
    virtual void Vf03();
    virtual void Vf04();
    virtual const char* GetModelPath();
};
struct SlotModelList
{
    SlotModelSource* FUN_00504e00(int index);
};

struct ModelLoader
{
    void FUN_0045a5e0(const char* path);
};
extern ModelLoader* g_modelLoader;
extern int DAT_011da9a4;

struct SlotShadowNode
{
    virtual void Vf00();
    virtual void Vf01();
    virtual void Vf02();
    virtual void Vf03();
    virtual void Vf04();
    virtual void Vf05();
    virtual void Vf06();
    virtual void Vf07();
    virtual void Vf08();
    virtual void Vf09();
    virtual void Vf10();
    virtual void Vf11();
    virtual void Vf12();
    virtual void Vf13();
    virtual void Vf14();
    virtual void Vf15();
    virtual void Vf16();
    virtual void Vf17();
    virtual void Vf18();
    virtual void Vf19();
    virtual void Vf20();
    virtual void Vf21();
    virtual void Vf22();
    virtual void Vf23();
    virtual void Vf24();
    virtual void Vf25();
    virtual void Vf26();
    virtual void Vf27();
    virtual void Vf28();
    virtual void Vf29();
    virtual void Vf30();
    virtual void Vf31();
    virtual void Vf32();
    virtual void Vf33();
    virtual void Vf34();
    virtual void Vf35();
    virtual void Vf36();
    virtual void Vf37();
    virtual void Vf38();
    virtual void Vf39();
    virtual void Vf40();
    virtual void Vf41();
    virtual void Vf42();
    virtual void Vf43();
    virtual void Vf44();
    virtual void Vf45();
    virtual void Vf46();
    virtual void Vf47();
    virtual void Vf48();
    virtual void Vf49();
    virtual void Vf50();
    virtual void Vf51();
    virtual void Vf52();
    virtual void Vf53();
    virtual void Vf54();
    virtual void Vf55();
    virtual void Vf56();
    virtual void Vf57();
    virtual void AttachRoot(void* node);
};

struct SlotSceneNode
{
    void FUN_00b5d180();
};

struct NiNodeRef
{
    void DetachAllChildren();
};

struct SlotNiPointer
{
    void* m_pObject;
    ~SlotNiPointer();
    SlotNiPointer& operator=(void* obj);
};

struct Menu_007a8b10
{
    virtual ~Menu_007a8b10();
};

struct FUN_007c0870 : Menu_007a8b10
{
    int unk0004;
    int unk0008;
    int unk000c;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001c;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002c;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003c;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004c;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005c;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006c;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007c;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008c;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009c;
    int unk00a0;
    int unk00a4;
    int unk00a8;
    int unk00ac;
    int unk00b0;
    int unk00b4;
    int unk00b8;
    int unk00bc;
    int unk00c0;
    int unk00c4;
    int unk00c8;
    int unk00cc;
    int unk00d0;
    int unk00d4;
    int unk00d8;
    int unk00dc;
    int unk00e0;
    int unk00e4;
    int unk00e8;
    int unk00ec;
    int unk00f0;
    int unk00f4;
    int unk00f8;
    int unk00fc;
    int unk0100;
    void* m_104;
    void* m_reels[3];
    SlotNiPointer m_reelNodes[8];
    void* m_134;
    int unk0138;
    int unk013c;
    int unk0140;
    int unk0144;
    void* m_reelControllers[3];
    virtual ~FUN_007c0870();
};

// @fnv 0x007c0870
FUN_007c0870::~FUN_007c0870()
{
    g_thePlayer->FUN_00969b20();
    g_modelLoader->FUN_0045a5e0(((SlotModelList*)DAT_011da9ac)->FUN_00504e00(7)->GetModelPath());
    g_modelLoader->FUN_0045a5e0("Meshes\\terminals\\NV_SlotMachine\\NV_SlotMachine-Reel01.NIF");
    g_modelLoader->FUN_0045a5e0("Meshes\\terminals\\NV_SlotMachine\\NV_SlotMachine-Reel02.NIF");
    g_modelLoader->FUN_0045a5e0("Meshes\\terminals\\NV_SlotMachine\\NV_SlotMachine-Reel03.NIF");
    ((SlotShadowNode*)FUN_00450b80(1))->AttachRoot(((GObjW7*)&g_011da9fc)->FUN_00559450());
    ((SlotSceneNode*)FUN_00450b80(1))->FUN_00b5d180();
    ((NiNodeRef*)((GObjW7*)&g_011da9fc)->FUN_00559450())->DetachAllChildren();
    m_104 = 0;
    (GO&)g_011da9d0 = 0;
    (GO&)g_011da9fc = 0;
    m_134 = 0;
    for (int i = 0; i < 3; i++)
    {
        m_reels[i] = 0;
        m_reelControllers[i] = 0;
    }
    for (int j = 0; j < 8; j++)
    {
        m_reelNodes[j] = 0;
    }
    DAT_011da9ac = 0;
    DAT_011da9a4 = 0;
}

namespace fnv_007c0a40 {
void* __cdecl operator new(unsigned int);
struct FUN_00733f50
{
    void* owner;
    int count;
    int flags;

    FUN_00733f50();
};
typedef FUN_00733f50 Record;
struct RecordList
{
    Record** FUN_006815c0();
    RecordList* FUN_00726070();
    bool FUN_008256d0();
    void FUN_00726c60(Record**);
    void FUN_005ae3d0(Record**);
};
struct Setting
{
    const char* FUN_00403df0();
};
struct CasinoData
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
    int limit;
};
struct StringField
{
    const char* FUN_00408da0();
};
struct Casino
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4c();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5c();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6c();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7c();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8c();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9c();
    virtual void vfa0();
    virtual void vfa4();
    virtual void vfa8();
    virtual void vfac();
    virtual void vfb0();
    virtual void vfb4();
    virtual void vfb8();
    virtual void vfbc();
    virtual void vfc0();
    virtual void vfc4();
    virtual void vfc8();
    virtual void vfcc();
    virtual void vfd0();
    virtual void vfd4();
    virtual void vfd8();
    virtual void vfdc();
    virtual void vfe0();
    virtual void vfe4();
    virtual void vfe8();
    virtual void vfec();
    virtual void vff0();
    virtual void vff4();
    virtual void vff8();
    virtual void vffc();
    virtual void vf100();
    virtual void vf104();
    virtual void vf108();
    virtual void vf10c();
    virtual void vf110();
    virtual void vf114();
    virtual void vf118();
    virtual void vf11c();
    virtual void vf120();
    virtual void vf124();
    virtual void vf128();
    virtual void vf12c();
    virtual const char* GetName();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    StringField name;
    void* FUN_0084e3a0();
    CasinoData* FUN_00504e60();
    void* FUN_007316d0();
};
struct Player
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
    struct Stats
    {
        int FUN_0066ef20(int);
    } stats;
    RecordList* FUN_005a6260();
    bool FUN_00969b80();
    int FUN_00969b40();
    int FUN_00575610(void*);
};
struct GameMenu;
struct GameTile
{
    GameTile* ReadXML();
    GameMenu* FUN_00a03c90();
    float FUN_00a011b0(int);
    void FUN_00a012d0(int, float);
    void FUN_00a01350(int, const char*, bool);
    void SetTraitAndReset(int, float);
    void FUN_00700320(int, int);
};
struct GameMenu
{
    virtual ~GameMenu();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual int Type();
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
    GameTile* tilea0;
    GameTile* tilea4;
    GameTile* tilea8;
    GameTile* tileac;
    GameTile* tileb0;
    GameTile* tileb4;
    GameTile* tileb8;
    GameTile* tilebc;
    GameTile* tilec0;
    GameTile* tilec4;
    int stat;
    int wager;
    void FUN_00a1dc70(GameTile*, bool);
    bool FUN_007c1450();
    bool LoadAssets();
    void InitPayoutMenu();
    void UpdateTileText();
    void FUN_00a1dc20(int);
    GameTile* FUN_00726070();
};
struct TileManager
{
    struct Reader
    {
        GameTile* FUN_00586150(const char*);
    };
};
struct BSSoundHandleEx
{
    int id;
    int state;
    int flags;
    ~BSSoundHandleEx();
    bool Play(bool);
};
class BSAudio
{
  public:
    static BSAudio* GetSingleton();
    BSSoundHandleEx GetSoundHandleByEditorID(const char*, unsigned int);
};
void* __cdecl FUN_00a09030(int);
int __cdecl LookupFormByID(void*);
void __cdecl DispatchMessageToSink(const char*, int, const char*, int, float, int);
void __cdecl FUN_005b5e40(const char*);
int __cdecl FUN_0044a670(const char*);
GameTile* __cdecl FUN_00a08b20(GameTile*, const char*);
float __stdcall FUN_00a01530(int);
void __cdecl FUN_007c2420();
extern Player* DAT_011dea3c;
extern GameMenu* DAT_011da9a4;
extern int DAT_011a0828;
extern int DAT_011a082c;
extern int DAT_011da998;
extern float DAT_010162c0;
extern Setting DAT_011d2ac0;
extern Setting DAT_011d3abc;
extern Setting DAT_011d2424;
extern Setting DAT_011d3594;
extern Setting DAT_011d3804;
extern Setting DAT_011d3300;
extern Setting DAT_011d2fd0;
extern Setting DAT_011d3354;
extern Setting DAT_011d487c;
extern Setting DAT_011d4054;
extern Setting DAT_011d37f8;
extern Setting DAT_011d387c;
extern Setting DAT_011d33fc;
extern const char DAT_01049638[];
extern const char DAT_01076694[];
extern const char DAT_01070c58[];
extern const char DAT_01025cc4[];
extern const char DAT_01076670[];
extern const char DAT_01076618[];
extern const char DAT_01076600[];
extern const char DAT_010765f0[];
extern const char DAT_010765d8[];

// Validates casino wager/limit/threshold, finds or creates the casino record, opens the casino menu and fills its tiles, returning the menu tile or null.
// @fnv 0x007c0a40
GameTile* __cdecl FUN_007c0a40(char* casino, int wager, int mode, int threshold)
{
    GameMenu* oldMenu = (GameMenu*)FUN_00a09030(0x438);
    TileManager::Reader* tile = (TileManager::Reader*)_FUN_004b7210();
    DAT_011a0828 = mode;
    DAT_011a082c = wager;
    DAT_011da9ac = casino;
    DAT_011da9a8 = 0;
    RecordList* node = DAT_011dea3c->FUN_005a6260();
    while (node && *node->FUN_006815c0())
    {
        if (!(*node->FUN_006815c0())->owner || !LookupFormByID((*node->FUN_006815c0())->owner))
        {
            DispatchMessageToSink(DAT_01076694, 0, DAT_01049638, 0, DAT_010162c0, 0);
            return 0;
        }
        if (((Casino*)DAT_011da9ac)->FUN_0084e3a0() == (*node->FUN_006815c0())->owner)
        {
            DAT_011da9a8 = (int*)*node->FUN_006815c0();
            break;
        }
        if (!node->FUN_00726070())
            break;
        node = node->FUN_00726070();
    }
    if (!DAT_011da9a8)
    {
        Record* pNewRecord = new Record;
        pNewRecord->owner = ((Casino*)DAT_011da9ac)->FUN_0084e3a0();
        pNewRecord->count = 0;
        node = DAT_011dea3c->FUN_005a6260();
        if (!node || node->FUN_008256d0())
            node->FUN_00726c60(&pNewRecord);
        else
            node->FUN_005ae3d0(&pNewRecord);
        DAT_011da9a8 = (int*)pNewRecord;
    }
    if (DAT_011dea3c->FUN_00969b80())
    {
        char message[260];
        _sprintf_s(message, 260, DAT_01070c58, DAT_011d2ac0.FUN_00403df0(), DAT_011dea3c->FUN_00969b40());
        DispatchMessageToSink(message, 0, DAT_01049638, 0, DAT_010162c0, 0);
        BSAudio::GetSingleton()->GetSoundHandleByEditorID(DAT_01025cc4, 0x121).Play(false);
        return 0;
    }
    if (((Record*)DAT_011da9a8)->count >= ((Casino*)DAT_011da9ac)->FUN_00504e60()->limit)
    {
        char message[260];
        _sprintf_s(message, 260, DAT_011d3abc.FUN_00403df0());
        DispatchMessageToSink(message, 0, DAT_01049638, 0, DAT_010162c0, 0);
        BSAudio::GetSingleton()->GetSoundHandleByEditorID(DAT_01025cc4, 0x121).Play(false);
        return 0;
    }
    if (DAT_011dea3c->FUN_00575610(((Casino*)DAT_011da9ac)->FUN_007316d0()) < DAT_011a082c)
    {
        char message[260];
        _sprintf_s(message, 260, DAT_011d2424.FUN_00403df0());
        DispatchMessageToSink(message, 0, DAT_01049638, 0, DAT_010162c0, 0);
        BSAudio::GetSingleton()->GetSoundHandleByEditorID(DAT_01025cc4, 0x121).Play(false);
        return 0;
    }
    if (((Record*)DAT_011da9a8)->count < threshold && threshold != 0)
    {
        char message[260];
        _sprintf_s(message, 260, DAT_011d3594.FUN_00403df0());
        DispatchMessageToSink(message, 0, DAT_01049638, 0, DAT_010162c0, 0);
        BSAudio::GetSingleton()->GetSoundHandleByEditorID(DAT_01025cc4, 0x121).Play(false);
        return 0;
    }
    if (oldMenu)
        delete oldMenu;
    GameTile* manager = tile->FUN_00586150(DAT_01076670)->ReadXML();
    DAT_011da9a4 = manager->FUN_00a03c90();
    if (DAT_011da9a4 && DAT_011da9a4->Type() == FUN_007c1440() && DAT_011da9ac)
    {
        DAT_011da9a4->FUN_00a1dc70(manager, false);
        if (!DAT_011da9a4->FUN_007c1450())
        {
            FUN_005b5e40(DAT_01076618);
            return 0;
        }
        if (manager->FUN_00a011b0(0xfa7) == 6006.0 || manager->FUN_00a011b0(0xfa7) == 102.0)
            manager->FUN_00a012d0(0xfad, FUN_00a01530(1));
        BSAudio::GetSingleton()->GetSoundHandleByEditorID(DAT_01076600, 0x121).Play(false);
        DAT_011da9a4->stat = DAT_011dea3c->stats.FUN_0066ef20(11);
        DAT_011da9a4->wager = DAT_011a082c;
        DAT_011da9a4->tilea0->FUN_00a01350(DAT_011da99c, DAT_011d3804.FUN_00403df0(), true);
        DAT_011da9a4->tilea0->SetTraitAndReset(DAT_011da998, 1.0f);
        DAT_011da9a4->tilea0->FUN_00700320(DAT_011da998, DAT_011a082c);
        DAT_011da9a4->tilea4->FUN_00a01350(DAT_011da99c, DAT_011d3300.FUN_00403df0(), true);
        DAT_011da9a4->tilea4->SetTraitAndReset(DAT_011da998, 1.0f);
        DAT_011da9a4->tilea4->FUN_00700320(DAT_011da998,
                                           DAT_011dea3c->FUN_00575610(((Casino*)DAT_011da9ac)->FUN_007316d0()));
        char label[64];
        if (FUN_0044a670(((Casino*)DAT_011da9ac)->name.FUN_00408da0()))
            _sprintf_s(label, 64, DAT_01012058, ((Casino*)DAT_011da9ac)->name.FUN_00408da0(),
                       g_011d3e08.GetMenuTitle());
        else
            _sprintf_s(label, 64, DAT_010765f0, ((Casino*)DAT_011da9ac)->GetName());
        DAT_011da9a4->tilea8->FUN_00a01350(DAT_011da99c, label, true);
        FUN_00a08b20(DAT_011da9a4->tilea8, DAT_010765d8)->FUN_00700320(0xfa3, 0);
        DAT_011da9a4->UpdateTileText();
        DAT_011da9a4->tileac->FUN_00a01350(0xfc4, DAT_011d2fd0.FUN_00403df0(), true);
        DAT_011da9a4->tileb0->FUN_00a01350(0xfc4, DAT_011d3354.FUN_00403df0(), true);
        DAT_011da9a4->tileb4->FUN_00a01350(0xfc4, DAT_011d487c.FUN_00403df0(), true);
        DAT_011da9a4->tileb8->FUN_00a01350(0xfc4, DAT_011d4054.FUN_00403df0(), true);
        DAT_011da9a4->tilebc->FUN_00a01350(0xfc4, DAT_011d37f8.FUN_00403df0(), true);
        DAT_011da9a4->tilec4->FUN_00a01350(0xfc4, DAT_011d387c.FUN_00403df0(), true);
        if (DAT_011da9a4->tilec0)
            DAT_011da9a4->tilec0->FUN_00a01350(0xfc4, DAT_011d33fc.FUN_00403df0(), true);
        if (!DAT_011da9a4->LoadAssets())
        {
            FUN_007c2420();
            return 0;
        }
        DAT_011da9a4->InitPayoutMenu();
        DAT_011da9a4->FUN_00a1dc20(0);
        return manager;
    }
    else if (DAT_011da9a4 && DAT_011da9a4->FUN_00726070())
        delete DAT_011da9a4;
    return 0;
}
}  // namespace fnv_007c0a40

namespace fnv_007c2c70 {
struct MenuTile
{
    float GetFloat(int id);
    void SetFloat(int id, float v);
    void SetInt(int id, int v);
    void SetString(int id, const char* s, int propagate);
    void SetAlpha(float v, int propagate);
};

struct TileHolder
{
    MenuTile* GetTile(int id);
};

TileHolder* GetHolder();

struct GenericGet
{
    void* Get();
};

struct BSStr : GenericGet
{
    char* m_data;
    unsigned short m_len;
    unsigned short m_kMaximumCorner;
    BSStr();
    ~BSStr();
};

struct GameSetting
{
    const char* GetStr();
};

struct RgbaColor
{
    float r;
    float g;
    float b;
    RgbaColor(float a, int b1, int b2);
};

struct ColorList
{
    void Set(int idx, RgbaColor* c);
};

struct ColorOwner
{
    ColorList* GetList();
};

struct ColorArray : GenericGet
{
};

struct Timer
{
    int GetTime();
};

struct PlayerData
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
    int m_28;
};

struct ProgressObj
{
    void Show(int b);
};

struct Player
{
    int GetCaps();
    int GetMaxCaps();
    ProgressObj* GetProgress();
    PlayerData* GetData();
};

struct InvItem;
struct DataHandler
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual void vB4();
    virtual void vB8();
    virtual void vBC();
    virtual void vC0();
    virtual void vC4();
    virtual void vC8();
    virtual void vCC();
    virtual void vD0();
    virtual void vD4();
    virtual void vD8();
    virtual void vDC();
    virtual void vE0();
    virtual void vE4();
    virtual void vE8();
    virtual void vEC();
    virtual void vF0();
    virtual void vF4();
    virtual void vF8();
    virtual void vFC();
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
    virtual void v138();
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
    virtual void AddItem(int item, int a1, int count, int a3, int a4, int a5, int a6, int a7, int a8, int a9);
    int GetItemCount(int item);
    InvItem* GetName(int item, int a, int b);
};

struct CapsChange
{
    int unk00;
    int unk04;
    int unk08;
    CapsChange();
    ~CapsChange();
    void Init(int item, int count, int a);
    void Apply(DataHandler* h, int b);
};

struct AudioPlaybackHandle
{
    int unk00;
    int unk04;
    int unk08;
    ~AudioPlaybackHandle();
    void Play();
};

struct AudioMgr
{
    AudioPlaybackHandle GetHandle(const char* name, int flags, int a);
};
AudioMgr* GetAudioMgr();

struct AnimSeq
{
    float GetTime();
};

struct Anim
{
    void Deactivate(AnimSeq* s, float t);
    void Activate(AnimSeq* s, int a, int b, float w, float t, int c);
    void SetTime(float t);
};

struct HudMenu
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
    MenuTile* m_a0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    MenuTile* m_c4;
};

unsigned char __cdecl IsMenuVisible(void* tile);
const char* __cdecl GetItemName(int item);
void __cdecl FormatString(BSStr* s, const char* fmt, ...);
void __cdecl ShowMessage(const char* text, int a, const char* icon, InvItem* sound, float time, int b);
void __cdecl FormatBuf(char* buf, unsigned int size, const char* fmt, ...);
void __cdecl CloseSlots();

extern Timer DAT_011f6394;
extern float DAT_011daa30;
extern int DAT_011daa2c;
extern DataHandler* DAT_011dea3c;
extern int DAT_011da998;
extern HudMenu* DAT_011da9a4;
extern ColorArray DAT_011da9fc;
extern GameSetting DAT_011d3db4;
extern GameSetting DAT_011d3114;
extern GameSetting DAT_011d4e7c;
extern GameSetting DAT_011d3abc;
extern GameSetting DAT_011d387c;
extern GameSetting DAT_011d3a98;
extern GameSetting DAT_011d5050;
extern GameSetting DAT_011d2ff4;
extern GameSetting DAT_011d25e0;
extern GameSetting DAT_011d3474;
extern GameSetting DAT_011d2424;

struct SlotMenu
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void* GetTile();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int m_uiContentCount;
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
    int m_result;
    int unkA0;
    MenuTile* m_a4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    MenuTile* m_c4;
    int unkC8;
    int m_bet;
    int unkD0;
    int m_caps;
    bool m_d8;
    int unkDC;
    int unkE0;
    int unkE4;
    int m_e8;
    int unkEC;
    int unkF0;
    int m_lastTime;
    unsigned char m_f8;
    int unkFC;
    unsigned char m_100;
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
    Anim* m_134;
    AnimSeq* m_138;
    AnimSeq* m_13c;
    AnimSeq* m_140;
    AnimSeq* m_144;
    AnimSeq* m_148;

    int GetMode();
    MenuTile* GetMenuTile();
    void Refresh();
    int SpinResult();
    void UpdateReels();
    void StartSpin();
    void StopReels();
    void Unused0();
    void Unused1();
    void Update();
};

// @fnv 0x007c2c70
void SlotMenu::Update()
{
    int dt = 0;
    float scale = 1.0f;
    unsigned char kKVis = IsMenuVisible(GetTile());
    if (m_lastTime == 0)
    {
        dt = 0;
        DAT_011daa30 = 0.0f;
        DAT_011daa2c = 0;
    }
    else if (kKVis)
    {
        dt = DAT_011f6394.GetTime() - m_lastTime;
        if (DAT_011daa2c != m_uiContentCount)
        {
            DAT_011daa30 = 0.0f;
        }
        else
        {
            DAT_011daa30 += dt / 1000.0;
        }
    }
    int tmp = 0;
    m_lastTime = DAT_011f6394.GetTime();
    DAT_011daa2c = m_uiContentCount;
    if (!kKVis)
    {
        GetHolder()->GetTile(0xfa9)->SetAlpha(255.0f, 1);
    }
    switch (m_uiContentCount)
    {
    case 7:
        if (GetMode() != 2)
        {
            GetHolder()->GetTile(0xfa9)->SetAlpha(255.0f, 1);
            GetMenuTile()->SetInt(0x1772, 1);
            Refresh();
            int diff;
            if ((diff = m_caps - DAT_011dea3c->GetItemCount(((Player*)DAT_011da9ac)->GetCaps())) < 0)
            {
                DAT_011dea3c->AddItem(((Player*)DAT_011da9ac)->GetCaps(), 0, -diff, 0, 0, 0, 0, 0, 1, 0);
                BSStr msg;
                FormatString(&msg, "%i %s%s %s", -diff, GetItemName(((Player*)DAT_011da9ac)->GetCaps()),
                             DAT_011d3114.GetStr(), DAT_011d3db4.GetStr());
                ShowMessage((const char*)msg.Get(), 0, "Interface\\Icons\\Message Icons\\glow_message_vaultboy_sad.dds",
                            DAT_011dea3c->GetName(((Player*)DAT_011da9ac)->GetCaps(), 1, 0), 2.0f, 0);
            }
            else if (diff > 0)
            {
                CapsChange change;
                change.Init(((Player*)DAT_011da9ac)->GetCaps(), diff, 0);
                if (DAT_011da9a8[1] < ((Player*)DAT_011da9ac)->GetMaxCaps())
                {
                    change.Apply(DAT_011dea3c, 0);
                }
                else
                {
                    change.Apply(DAT_011dea3c, 1);
                    BSStr msg2;
                    FormatString(&msg2, "%i %s%s %s\n%s", diff, GetItemName(((Player*)DAT_011da9ac)->GetCaps()),
                                 DAT_011d3114.GetStr(), DAT_011d4e7c.GetStr(), DAT_011d3abc.GetStr());
                    ShowMessage((const char*)msg2.Get(), 0,
                                "Interface\\Icons\\Message Icons\\glow_message_vaultboy_very_happy.dds",
                                DAT_011dea3c->GetName(((Player*)DAT_011da9ac)->GetCaps(), 1, 0), 2.0f, 0);
                }
            }
            if (m_100)
            {
                ProgressObj* progress = ((Player*)DAT_011da9ac)->GetProgress();
                if (progress != 0)
                {
                    progress->Show(1);
                }
            }
        }
        break;
    case 0:
        m_uiContentCount = 6;
        break;
    case 1:
        if (m_138 != 0 && m_148 != 0)
        {
            if (m_13c != 0)
            {
                m_134->Deactivate(m_13c, 0.0f);
            }
            if (DAT_011daa30 > 1.0)
            {
                m_c4->SetInt(0xfa3, 0);
            }
            RgbaColor c0(DAT_011daa30, 1, 0);
            RgbaColor C5(DAT_011daa30, 1, 0);
            RgbaColor c2(DAT_011daa30, 1, 0);
            RgbaColor C(DAT_011daa30, 1, 0);
            ((ColorOwner*)DAT_011da9fc.Get())->GetList()->Set(0, &c0);
            if (DAT_011daa30 == 0.0 && m_a4->GetFloat(DAT_011da998) > 0.0)
            {
                GetAudioMgr()->GetHandle("GameSlotsPullLever", 0x121, 0).Play();
                m_f8 = 1;
            }
            if (DAT_011daa30 == 0.0 || m_a4->GetFloat(DAT_011da998) > 0.0)
            {
                ((ColorOwner*)DAT_011da9fc.Get())->GetList()->Set(1, &C5);
                ((ColorOwner*)DAT_011da9fc.Get())->GetList()->Set(2, &c2);
                ((ColorOwner*)DAT_011da9fc.Get())->GetList()->Set(3, &C);
            }
            if (DAT_011daa30 >= m_138->GetTime() && m_f8 == 1)
            {
                m_f8 = 0;
                StopReels();
            }
            if (DAT_011daa30 >= m_138->GetTime() && DAT_011daa30 >= m_148->GetTime())
            {
                m_uiContentCount = 2;
                StartSpin();
            }
        }
        break;
    case 3:
        if (m_13c != 0)
        {
            m_134->Activate(m_13c, 0, 0, 1.0f, 0.0f, 0);
            if (m_138 != 0)
            {
                m_134->Deactivate(m_138, 0.0f);
            }
            RgbaColor C2(DAT_011daa30, 1, 0);
            ((ColorOwner*)DAT_011da9fc.Get())->GetList()->Set(0, &C2);
            if (DAT_011daa30 == 0.0)
            {
                if (m_result == 4)
                {
                    GetAudioMgr()->GetHandle("GAMESlotsWinSmall", 0x121, 0).Play();
                }
                else if (m_result == 5)
                {
                    GetAudioMgr()->GetHandle("GAMESlotsWinMed", 0x121, 0).Play();
                }
                else if (m_result == 6)
                {
                    GetAudioMgr()->GetHandle("GAMESlotsWinJackpot", 0x121, 0).Play();
                }
            }
            if (DAT_011daa30 > 1.0)
            {
                m_c4->SetInt(0xfa3, 0);
            }
            if (DAT_011daa30 >= m_13c->GetTime())
            {
                m_134->Deactivate(m_13c, 0.0f);
                if (m_138 != 0)
                {
                    m_134->Activate(m_138, 0, 0, 1.0f, 0.0f, 0);
                }
                int total = ((Player*)DAT_011da9ac)->GetData()->m_28;
                int cur = DAT_011da9a8[1];
                int iDX = ((short*)DAT_011da9a8)[4];
                for (int i = 1; i < 5; i++)
                {
                    if (i <= iDX)
                    {
                        m_100 = 0;
                    }
                    else if (total * (i * 0.25) <= cur)
                    {
                        ((short*)DAT_011da9a8)[4] = (short)i;
                        m_100 = 1;
                    }
                }
                if (m_100)
                {
                    CloseSlots();
                }
                else
                {
                    m_uiContentCount = 6;
                }
            }
        }
        else
        {
            m_uiContentCount = 6;
        }
        break;
    case 4:
        if (m_140 == 0)
        {
            break;
        }
        if (DAT_011daa30 == 0.0)
        {
            m_c4->SetInt(0xfa3, 1);
            m_c4->SetString(0xfc4, DAT_011d387c.GetStr(), 1);
            m_134->SetTime(0.0f);
            m_134->Activate(m_140, 0, 0, 1.0f, 0.0f, 0);
        }
        if (DAT_011daa30 <= m_140->GetTime())
        {
            RgbaColor c(DAT_011daa30, 1, 0);
            ((ColorOwner*)DAT_011da9fc.Get())->GetList()->Set(0, &c);
        }
        else
        {
            m_134->Deactivate(m_140, 0.0f);
        }
        break;
    case 5:
        if (m_144 == 0)
        {
            break;
        }
        if (DAT_011daa30 == 0.0)
        {
            m_c4->SetInt(0xfa3, 0);
            m_134->SetTime(0.0f);
            m_134->Activate(m_144, 0, 0, 1.0f, 0.0f, 0);
        }
        if (DAT_011daa30 <= m_144->GetTime())
        {
            RgbaColor c(DAT_011daa30, 1, 0);
            ((ColorOwner*)DAT_011da9fc.Get())->GetList()->Set(0, &c);
        }
        else
        {
            m_134->Deactivate(m_144, 0.0f);
            m_134->Activate(m_138, 0, 0, 1.0f, 0.0f, 0);
            m_uiContentCount = 6;
        }
        break;
    case 2: {
        int won = 0;
        m_result = SpinResult();
        if (m_result == 6)
        {
            switch (m_e8)
            {
            case 12:
                won = m_bet * 10;
                m_caps += won;
                break;
            case 0:
                won = m_bet * 10;
                m_caps += won;
                break;
            case 2:
                won = m_bet * 20;
                m_caps += won;
                break;
            case 4:
                won = m_bet * 30;
                m_caps += won;
                break;
            case 6:
                won = m_bet * 40;
                m_caps += won;
                break;
            case 8:
                won = m_bet * 60;
                m_caps += won;
                break;
            case 10:
                won = m_bet * 100;
                m_caps += won;
                break;
            default:
                m_caps -= m_bet;
                break;
            }
        }
        else if (m_result == 5)
        {
            won = m_bet * 5;
            m_caps += won;
        }
        else if (m_result == 4)
        {
            won = m_bet * 2;
            m_caps += won;
        }
        else
        {
            won = -m_bet;
            m_caps += won;
        }
        m_a4->SetFloat(DAT_011da998, 1.0f);
        m_a4->SetInt(DAT_011da998, m_caps);
        DAT_011da9a8[1] += won;
        UpdateReels();
        if (m_result > 3)
        {
            char text[0x104];
            if (m_d8)
            {
                FormatBuf(text, 0x104, "%s %d %s%s", DAT_011d3a98.GetStr(), won, DAT_011d5050.GetStr(),
                          DAT_011d3114.GetStr());
            }
            else
            {
                FormatBuf(text, 0x104, "%s %d %s%s", DAT_011d2ff4.GetStr(), won, DAT_011d5050.GetStr(),
                          DAT_011d3114.GetStr());
            }
            DAT_011da9a4->m_c4->SetFloat(0xfc4, 1.0f);
            DAT_011da9a4->m_c4->SetString(0xfc4, text, 1);
            DAT_011da9a4->m_c4->SetInt(0xfa3, 1);
            m_uiContentCount = 3;
        }
        else
        {
            char text2[0x104];
            if (m_d8)
            {
                GetAudioMgr()->GetHandle("GAMESlotsLose", 0x121, 0).Play();
                FormatBuf(text2, 0x104, "%s %d %s%s", DAT_011d25e0.GetStr(), -won, DAT_011d5050.GetStr(),
                          DAT_011d3114.GetStr());
            }
            else
            {
                FormatBuf(text2, 0x104, "%s %d %s%s", DAT_011d3474.GetStr(), -won, DAT_011d5050.GetStr(),
                          DAT_011d3114.GetStr());
            }
            DAT_011da9a4->m_c4->SetFloat(0xfc4, 1.0f);
            DAT_011da9a4->m_c4->SetString(0xfc4, text2, 1);
            DAT_011da9a4->m_c4->SetInt(0xfa3, 1);
            m_uiContentCount = 6;
        }
        break;
    }
    case 6:
        if (DAT_011daa30 > 1.0)
        {
            m_c4->SetInt(0xfa3, 0);
        }
        if (m_caps < m_bet)
        {
            m_bet = 1;
            DAT_011da9a4->m_a0->SetFloat(DAT_011da998, 1.0f);
            DAT_011da9a4->m_a0->SetInt(DAT_011da998, m_bet);
        }
        if (m_caps == 0)
        {
            char text3[0x104];
            FormatBuf(text3, 0x104, DAT_011d2424.GetStr());
            ShowMessage(text3, 0, "Interface\\Icons\\Message Icons\\glow_message_vaultboy_surprised.dds", 0, 2.0f, 0);
            GetAudioMgr()->GetHandle("UIPopUpMessageGeneral", 0x121, 0).Play();
            CloseSlots();
        }
        break;
    }
}
}  // namespace fnv_007c2c70

struct ReelTexture
{
    void* value;
    void* FUN_00559450() const;
};
struct ReelProperty
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
    virtual void SetTexture(int, int, void*);
    int FUN_00441110();
};
struct ReelNode
{
    ReelProperty* FUN_00a59d30(unsigned int);
};
ReelNode* __cdecl FUN_004aae30(ReelNode*, const char*);
int _sprintf_s(char*, unsigned int, const char*, ...);
struct ReelMenu
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
    int savedResults[3];
    int currentResults[3];
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    ReelNode* reels[3];
    ReelTexture textures[8];
    void FUN_007c40b0();
};
// For each reel whose current result differs from the saved result, computes texture indices and sets the texture on the Cylinder nodes' property.
// @fnv 0x007c40b0
void ReelMenu::FUN_007c40b0()
{
    int reel4, delta8, a6, b, c3, d_, e, f7, g2, _h;
    char name6[260];
    ReelNode* node9;
    ReelProperty* propA;
    for (reel4 = 0; reel4 < 3; reel4++)
    {
        if (delta8 = currentResults[reel4] - savedResults[reel4])
        {
            if (currentResults[reel4] % 2 == 0)
            {
                a6 = currentResults[reel4] / 2 + 3;
                e = currentResults[reel4] / 2 + 4;
                c3 = currentResults[reel4] / 2 + 5;
                g2 = currentResults[reel4] / 2 + 6;
                b = d_ = f7 = _h = 7;
                if (a6 > 6)
                    a6 -= 7;
                if (e > 6)
                    e -= 7;
                if (c3 > 6)
                    c3 -= 7;
                if (g2 > 6)
                    g2 -= 7;
            }
            else
            {
                b = (currentResults[reel4] + 3) / 2;
                d_ = (currentResults[reel4] + 4) / 2;
                f7 = (currentResults[reel4] + 5) / 2;
                _h = (currentResults[reel4] + 6) / 2;
                a6 = e = c3 = g2 = 7;
                if (b > 6)
                    b -= 7;
                if (d_ > 6)
                    d_ -= 7;
                if (f7 > 6)
                    f7 -= 7;
                if (_h > 6)
                    _h -= 7;
            }
            _sprintf_s(name6, 260, "Cylinder0%i:%i", 6 - reel4,
                       2 * reel4 + 4 > 13 ? 2 * reel4 + 4 - 14 : 2 * reel4 + 4);
            node9 = FUN_004aae30(reels[reel4], name6);
            propA =
                (!node9->FUN_00a59d30(3)
                     ? 0
                     : ((node9->FUN_00a59d30(3)->FUN_00441110() >= 8 && node9->FUN_00a59d30(3)->FUN_00441110() <= 12)
                            ? 1
                            : 0))
                    ? node9->FUN_00a59d30(3)
                    : 0;
            if (propA)
                propA->SetTexture(0, 0, textures[a6].FUN_00559450());
            _sprintf_s(name6, 260, "Cylinder0%i:%i", 6 - reel4,
                       2 * reel4 + 5 > 13 ? 2 * reel4 + 5 - 14 : 2 * reel4 + 5);
            node9 = FUN_004aae30(reels[reel4], name6);
            propA =
                (!node9->FUN_00a59d30(3)
                     ? 0
                     : ((node9->FUN_00a59d30(3)->FUN_00441110() >= 8 && node9->FUN_00a59d30(3)->FUN_00441110() <= 12)
                            ? 1
                            : 0))
                    ? node9->FUN_00a59d30(3)
                    : 0;
            if (propA)
                propA->SetTexture(0, 0, textures[b].FUN_00559450());
            _sprintf_s(name6, 260, "Cylinder0%i:%i", 6 - reel4,
                       2 * reel4 + 6 > 13 ? 2 * reel4 + 6 - 14 : 2 * reel4 + 6);
            node9 = FUN_004aae30(reels[reel4], name6);
            propA =
                (!node9->FUN_00a59d30(3)
                     ? 0
                     : ((node9->FUN_00a59d30(3)->FUN_00441110() >= 8 && node9->FUN_00a59d30(3)->FUN_00441110() <= 12)
                            ? 1
                            : 0))
                    ? node9->FUN_00a59d30(3)
                    : 0;
            if (propA)
                propA->SetTexture(0, 0, textures[e].FUN_00559450());
            _sprintf_s(name6, 260, "Cylinder0%i:%i", 6 - reel4,
                       2 * reel4 + 7 > 13 ? 2 * reel4 + 7 - 14 : 2 * reel4 + 7);
            node9 = FUN_004aae30(reels[reel4], name6);
            propA =
                (!node9->FUN_00a59d30(3)
                     ? 0
                     : ((node9->FUN_00a59d30(3)->FUN_00441110() >= 8 && node9->FUN_00a59d30(3)->FUN_00441110() <= 12)
                            ? 1
                            : 0))
                    ? node9->FUN_00a59d30(3)
                    : 0;
            if (propA)
                propA->SetTexture(0, 0, textures[d_].FUN_00559450());
            _sprintf_s(name6, 260, "Cylinder0%i:%i", 6 - reel4,
                       2 * reel4 + 8 > 13 ? 2 * reel4 + 8 - 14 : 2 * reel4 + 8);
            node9 = FUN_004aae30(reels[reel4], name6);
            propA =
                (!node9->FUN_00a59d30(3)
                     ? 0
                     : ((node9->FUN_00a59d30(3)->FUN_00441110() >= 8 && node9->FUN_00a59d30(3)->FUN_00441110() <= 12)
                            ? 1
                            : 0))
                    ? node9->FUN_00a59d30(3)
                    : 0;
            if (propA)
                propA->SetTexture(0, 0, textures[c3].FUN_00559450());
            _sprintf_s(name6, 260, "Cylinder0%i:%i", 6 - reel4,
                       2 * reel4 + 9 > 13 ? 2 * reel4 + 9 - 14 : 2 * reel4 + 9);
            node9 = FUN_004aae30(reels[reel4], name6);
            propA =
                (!node9->FUN_00a59d30(3)
                     ? 0
                     : ((node9->FUN_00a59d30(3)->FUN_00441110() >= 8 && node9->FUN_00a59d30(3)->FUN_00441110() <= 12)
                            ? 1
                            : 0))
                    ? node9->FUN_00a59d30(3)
                    : 0;
            if (propA)
                propA->SetTexture(0, 0, textures[f7].FUN_00559450());
            _sprintf_s(name6, 260, "Cylinder0%i:%i", 6 - reel4,
                       2 * reel4 + 10 > 13 ? 2 * reel4 + 10 - 14 : 2 * reel4 + 10);
            node9 = FUN_004aae30(reels[reel4], name6);
            propA =
                (!node9->FUN_00a59d30(3)
                     ? 0
                     : ((node9->FUN_00a59d30(3)->FUN_00441110() >= 8 && node9->FUN_00a59d30(3)->FUN_00441110() <= 12)
                            ? 1
                            : 0))
                    ? node9->FUN_00a59d30(3)
                    : 0;
            if (propA)
                propA->SetTexture(0, 0, textures[g2].FUN_00559450());
            _sprintf_s(name6, 260, "Cylinder0%i:%i", 6 - reel4,
                       2 * reel4 + 11 > 13 ? 2 * reel4 + 11 - 14 : 2 * reel4 + 11);
            node9 = FUN_004aae30(reels[reel4], name6);
            propA =
                (!node9->FUN_00a59d30(3)
                     ? 0
                     : ((node9->FUN_00a59d30(3)->FUN_00441110() >= 8 && node9->FUN_00a59d30(3)->FUN_00441110() <= 12)
                            ? 1
                            : 0))
                    ? node9->FUN_00a59d30(3)
                    : 0;
            if (propA)
                propA->SetTexture(0, 0, textures[_h].FUN_00559450());
        }
    }
}

namespace fnv_007c4d70 {
static const char kCylinderFormat[] = "Cylinder0%i:%i";
struct ReelProperty
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void SetTexture(int, int, void*);
    int Type();
};
struct ReelNode
{
    ReelProperty* GetProperty(unsigned int);
};
struct ReelTexture
{
    void* value;
    operator void*() const;
};
ReelNode* FindReelNode(void*, const char*);
struct ReelMenu
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
    int previous[3];
    int current[3];
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    void* reels[3];
    ReelTexture textures[8];
    void FUN_007c4d70();
};
// For each of the 3 reels whose current value changed, computes cylinder indices and sets the texture on each matching reel node property.
// @fnv 0x007c4d70
void ReelMenu::FUN_007c4d70()
{
    int reel4;
    int delta8;
    ReelProperty* propertyA;
    int a8;
    int b2;
    int c2;
    char name[260];
    int dA;
    int e_;
    int f5;
    ReelNode* node;
    for (reel4 = 0; reel4 < 3; reel4++)
    {
        if (delta8 = current[reel4] - previous[reel4])
        {
            if (current[reel4] % 2 == 0)
            {
                f5 = current[reel4] / 2;
                e_ = current[reel4] / 2 + 1;
                c2 = current[reel4] / 2 - 1;
                dA = 7;
                b2 = a8 = dA;
                if (e_ > 6)
                    e_ -= 7;
                if (c2 < 0)
                    c2 += 7;
            }
            else
            {
                b2 = (current[reel4] + 1) / 2;
                a8 = (current[reel4] + 3) / 2;
                dA = (current[reel4] - 1) / 2;
                c2 = 7;
                f5 = e_ = c2;
                if (b2 > 6)
                    b2 -= 7;
                if (a8 > 6)
                    a8 -= 7;
                if (dA < 0)
                    dA += 7;
            }
            _sprintf_s(name, 260, kCylinderFormat, 6 - reel4, (2 * reel4 + 3 > 13 ? 2 * reel4 - 11 : 2 * reel4 + 3));
            node = FindReelNode(reels[reel4], name);
            propertyA =
                (!node->GetProperty(3) ? false
                                       : (node->GetProperty(3)->Type() >= 8 && node->GetProperty(3)->Type() <= 12))
                    ? node->GetProperty(3)
                    : 0;
            if (propertyA)
                propertyA->SetTexture(0, 0, textures[a8]);
            _sprintf_s(name, 260, kCylinderFormat, 6 - reel4, (2 * reel4 + 2 > 13 ? 2 * reel4 - 12 : 2 * reel4 + 2));
            node = FindReelNode(reels[reel4], name);
            propertyA =
                (!node->GetProperty(3) ? false
                                       : (node->GetProperty(3)->Type() >= 8 && node->GetProperty(3)->Type() <= 12))
                    ? node->GetProperty(3)
                    : 0;
            if (propertyA)
                propertyA->SetTexture(0, 0, textures[e_]);
            _sprintf_s(name, 260, kCylinderFormat, 6 - reel4, (2 * reel4 + 1 > 13 ? 2 * reel4 - 13 : 2 * reel4 + 1));
            node = FindReelNode(reels[reel4], name);
            propertyA =
                (!node->GetProperty(3) ? false
                                       : (node->GetProperty(3)->Type() >= 8 && node->GetProperty(3)->Type() <= 12))
                    ? node->GetProperty(3)
                    : 0;
            if (propertyA)
                propertyA->SetTexture(0, 0, textures[b2]);
            _sprintf_s(name, 260, kCylinderFormat, 6 - reel4, 2 * reel4);
            node = FindReelNode(reels[reel4], name);
            propertyA =
                (!node->GetProperty(3) ? false
                                       : (node->GetProperty(3)->Type() >= 8 && node->GetProperty(3)->Type() <= 12))
                    ? node->GetProperty(3)
                    : 0;
            if (propertyA)
                propertyA->SetTexture(0, 0, textures[f5]);
            _sprintf_s(name, 260, kCylinderFormat, 6 - reel4, (2 * reel4 - 1 < 0 ? 2 * reel4 + 13 : 2 * reel4 - 1));
            node = FindReelNode(reels[reel4], name);
            propertyA =
                (!node->GetProperty(3) ? false
                                       : (node->GetProperty(3)->Type() >= 8 && node->GetProperty(3)->Type() <= 12))
                    ? node->GetProperty(3)
                    : 0;
            if (propertyA)
                propertyA->SetTexture(0, 0, textures[dA]);
            _sprintf_s(name, 260, kCylinderFormat, 6 - reel4, (2 * reel4 - 2 < 0 ? 2 * reel4 + 12 : 2 * reel4 - 2));
            node = FindReelNode(reels[reel4], name);
            propertyA =
                (!node->GetProperty(3) ? false
                                       : (node->GetProperty(3)->Type() >= 8 && node->GetProperty(3)->Type() <= 12))
                    ? node->GetProperty(3)
                    : 0;
            if (propertyA)
                propertyA->SetTexture(0, 0, textures[c2]);
        }
    }
}
}  // namespace fnv_007c4d70

struct Settings
{
    int unk00;
    int unk04;
    int stopCount0;
    int stopCount1;
    int stopCount2;
    int stopCount3;
    int stopCount4;
    int stopCount5;
    int stopCount6;
};
struct SettingsOwner
{
    Settings* GetSettings();
};
extern SettingsOwner* settingsOwner;
struct Sound
{
    int id;
    int state;
    int unk08;
    ~Sound();
    bool Play(bool);
};
struct Audio
{
    static Audio* Get();
    Sound GetSoundByEditorID(const char*, unsigned int);
};
bool QueueUIMessage(const char*, int, const char*, const char*, float, bool);
void FUN_007c2420();
int _sprintf_s(char*, unsigned int, const char*, ...);
struct Reels
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
    int symbols[28];
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
    int count;
    int unkD4;
    int unkD8;
    int saved[3];
    int current[3];
    bool InitReels();
};
// @fnv 0x007c16b0
bool Reels::InitReels()
{
    int filled = 0;
    {
        int index;
        for (index = 0; index < 28; index++)
            symbols[index] = 14;
    }
    int symbol = 0;
    int countsA[7];
    int tempA;
    tempA = settingsOwner->GetSettings()->stopCount0;
    countsA[0] = tempA;
    tempA = settingsOwner->GetSettings()->stopCount1;
    countsA[1] = tempA;
    tempA = settingsOwner->GetSettings()->stopCount2;
    countsA[2] = tempA;
    tempA = settingsOwner->GetSettings()->stopCount3;
    countsA[3] = tempA;
    tempA = settingsOwner->GetSettings()->stopCount4;
    countsA[4] = tempA;
    tempA = settingsOwner->GetSettings()->stopCount5;
    countsA[5] = tempA;
    tempA = settingsOwner->GetSettings()->stopCount6;
    countsA[6] = tempA;
    count = 7;
    {
        int scan;
        for (scan = 0; scan < 7; scan++)
            if (countsA[scan] == 0)
                count = count - 1;
    }
    while (filled < 28)
    {
        int previous8 = filled;
        symbol = 0;
        int kindVal;
        for (kindVal = 0; kindVal < 7; kindVal++)
        {
            if (countsA[kindVal] != 0)
            {
                symbols[filled] = symbol;
                filled = filled + 1;
                symbol = symbol + 1;
                symbols[filled] = symbol;
                filled = filled + 1;
                countsA[kindVal] = countsA[kindVal] - 1;
            }
            symbol = symbol + 1;
        }
        if (previous8 == filled)
        {
            char message[260];
            _sprintf_s(
                message, 260,
                "Casino Form is not setup properly. # of stops for the slot reels must sum to 14. Exiting out of Slot machine menu.");
            QueueUIMessage(message, 0, "Interface\\Icons\\Message Icons\\glow_message_vaultboy_surprised.dds", 0, 2.0f,
                           false);
            Audio::Get()->GetSoundByEditorID("UIPopUpMessageGeneral", 0x121).Play(false);
            FUN_007c2420();
            return false;
        }
    }
    {
        int reelX;
        for (reelX = 0; reelX < 3; reelX++)
        {
            current[reelX] = reelX * 2;
            saved[reelX] = 14;
        }
    }
    return true;
}

struct SlotTextureName
{
    const char* FUN_00408da0();
};
struct SlotModelName
{
    virtual void Reserved0();
    virtual void Reserved1();
    virtual void Reserved2();
    virtual void Reserved3();
    virtual void Reserved4();
    virtual const char* GetPath();
};
struct SlotAssets
{
    SlotTextureName* FUN_00504e20(int);
    SlotModelName* FUN_00504e00(int);
};
struct SlotTextureLoader
{
    void FUN_004568c0(const char*, void**, bool, bool);
};
extern SlotTextureLoader* DAT_011dea10;
struct SlotModelLoader
{
    void* LoadModel(const char*, int, bool, bool, bool, bool);
};
extern SlotModelLoader* DAT_011c3b3c;
void FUN_00406d00(char*, unsigned int, const char*, ...);
void FUN_004b7240(const char*, char*, unsigned int);
struct SlotMachineAssets
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
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    bool loading;
    void* machine;
    void* reel1;
    void* reel2;
    void* reel3;
    void* symbols[7];
    void* special;
    bool InitReels();
    bool LoadAssets();
};
// @fnv 0x007c1490
bool SlotMachineAssets::LoadAssets()
{
    if (DAT_011da9ac)
    {
        char path[260];
        char normalized[260];
        for (int i = 0; i < 7; ++i)
        {
            if (DAT_011da9ac)
            {
                FUN_00406d00(path, 260, "%s%s", "Textures\\",
                             reinterpret_cast<SlotAssets*>(DAT_011da9ac)->FUN_00504e20(i)->FUN_00408da0());
                FUN_004b7240(path, normalized, 260);
                DAT_011dea10->FUN_004568c0(normalized, &symbols[i], false, false);
            }
        }
        FUN_00406d00(path, 260, "%sNV_SlotMachine-Symbol%s.dds", "Textures\\terminals\\NV_SlotMachine\\", "S");
        FUN_004b7240(path, normalized, 260);
        DAT_011dea10->FUN_004568c0(normalized, &special, false, false);
        machine = DAT_011c3b3c->LoadModel(reinterpret_cast<SlotAssets*>(DAT_011da9ac)->FUN_00504e00(7)->GetPath(), 0,
                                             true, false, false, false);
        reel1 = DAT_011c3b3c->LoadModel("Meshes\\terminals\\NV_SlotMachine\\NV_SlotMachine-Reel01.NIF", 0, true,
                                           false, false, false);
        reel2 = DAT_011c3b3c->LoadModel("Meshes\\terminals\\NV_SlotMachine\\NV_SlotMachine-Reel02.NIF", 0, true,
                                           false, false, false);
        reel3 = DAT_011c3b3c->LoadModel("Meshes\\terminals\\NV_SlotMachine\\NV_SlotMachine-Reel03.NIF", 0, true,
                                           false, false, false);
        loading = false;
        return InitReels();
    }
    return false;
}

#include <stdlib.h>
struct SlotReelLogic
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
    int values[0x27];
    int iTolerance;  // 0xc8
    int unkCC;
    int iValueCount;  // 0xd0
    int unkD4;
    bool bChanged;  // 0xd8
    int unkDC;
    int unkE0;
    int unkE4;
    int reels[3];  // 0xe8

    int FUN_007c56e0();
    int FUN_007c5760();
    bool AdjustReels(int a);
};
int __cdecl FUN_00944460(int, int);

// @fnv 0x007c58f0
bool SlotReelLogic::AdjustReels(int a)
{
    int base = abs((iTolerance - 5) * 10);
    if (FUN_00944460(0, 100) + base > 100)
    {
        int r0 = reels[0];
        int R = reels[1];
        int r2 = reels[2];
        if (iTolerance - 5 >= 0)
        {
            switch (a)
            {
            case 0:
                while (FUN_007c56e0() < a)
                {
                }
                return AdjustReels(FUN_007c5760());
                break;
            case 2:
                if (reels[0] == 12)
                {
                    reels[1] = values[FUN_00944460(0, iValueCount) * 2];
                    reels[2] = values[FUN_00944460(0, iValueCount) * 2];
                }
                else if (reels[1] == 12)
                {
                    reels[0] = values[FUN_00944460(0, iValueCount) * 2];
                    reels[2] = values[FUN_00944460(0, iValueCount) * 2];
                }
                else
                {
                    reels[0] = values[FUN_00944460(0, iValueCount) * 2];
                    reels[1] = values[FUN_00944460(0, iValueCount) * 2];
                }
                if (FUN_007c5760() > a)
                {
                    return true;
                }
                break;
            case 4: {
                int wild = 0;
                int odd2 = -1;
                int diff = 0;
                for (int i = 0; i < 3; i++)
                {
                    switch (reels[i])
                    {
                    case 12:
                        wild = i;
                    }
                    if (reels[i] % 2)
                    {
                        odd2 = i;
                    }
                }
                int prevM = (wild - 1 >= 0) ? wild - 1 : 2;
                int next = (wild + 1 < 2) ? wild + 1 : 0;
                diff = abs(reels[prevM] - reels[next]);
                if (diff <= iTolerance && odd2 < 0)
                {
                    reels[prevM] = reels[next];
                    return true;
                }
                else if (diff <= iTolerance)
                {
                    if (prevM == odd2)
                    {
                        reels[prevM] = reels[next];
                    }
                    else
                    {
                        reels[next] = reels[prevM];
                    }
                    return true;
                }
                break;
            }
            case 1:
            case 5:
                if (reels[0] == reels[1])
                {
                    int k = iTolerance - 5;
                    int d = abs(reels[0] - reels[2]);
                    d = d * d;
                    if (d <= iTolerance)
                    {
                        reels[2] = reels[0];
                        return true;
                    }
                }
                else if (reels[0] == reels[2])
                {
                    int k = iTolerance - 5;
                    int d = abs(reels[0] - reels[1]);
                    d = d * d;
                    if (d <= iTolerance)
                    {
                        reels[1] = reels[0];
                        return true;
                    }
                }
                else
                {
                    int k = iTolerance - 5;
                    int d = abs(reels[1] - reels[0]);
                    d = d * d;
                    if (d <= iTolerance)
                    {
                        reels[0] = reels[1];
                        return true;
                    }
                }
                break;
            }
        }
        else
        {
            switch (a)
            {
                break;
            case 6:
                reels[0] = reels[1] = reels[2] = (reels[0] + 1 > 6) ? 0 : reels[0] + 1;
                bChanged = true;
                break;
            case 4:
            case 5:
                for (int j = 0; j < 3; j++)
                {
                    if (reels[j] == 12)
                    {
                        reels[j] = 13;
                    }
                }
                bChanged = true;
                break;
            }
        }
    }
    return false;
}

namespace fnv_007c2460 {
struct SlotsTile
{
    void SetTraitAndReset(int, float);
    void FUN_00700320(int, int);
};
struct FUN_0041a250
{
    unsigned int id, flags;
    void* data;
    ~FUN_0041a250();
    void Play();
};
struct SlotsAudio
{
    FUN_0041a250 FUN_00ad7550(const char*, int, int);
};
struct SlotsMenu
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
    int result;
    SlotsTile* tile;
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
    int bet;
    int unkd0;
    int funds;
    bool won;
    unsigned char unkd9, unkda, unkdb;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int soundIndex;
    int FUN_007c56e0();
    bool AdjustReels(int);
    int FUN_007c5760();
    void FUN_007c2460(int, void*);
};
extern int DAT_011a0828, DAT_011a082c, DAT_011da998;
extern SlotsMenu* DAT_011da9a4;
void FUN_007c2420();
void FUN_004d5c60(int);
int FUN_00406d00(char*, unsigned int, const char*, ...);
SlotsAudio* FUN_00453a70();
// Processes input actions for the slots menu, adjusting the bet, starting a spin, or transitioning between states based on the current state.
// @fnv 0x007c2460
void SlotsMenu::FUN_007c2460(int action, void* target)
{
    if (state == 6)
    {
        switch (action)
        {
        case 8:
            FUN_007c2420();
            break;
        case 3:
            if (funds < bet)
                break;
            soundIndex = 1;
            result = FUN_007c56e0();
            won = AdjustReels(result);
            result = FUN_007c5760();
            state = 1;
            FUN_004d5c60(42);
            break;
        case 4: {
            int iOldBet = bet;
            if (bet < 10)
                bet += 1;
            else if (bet < 40)
                bet += 5;
            else if (bet < 100)
                bet += 10;
            else if (bet < 500)
                bet += 25;
            else
                bet += 100;
            if (bet > funds)
                bet = funds;
            if (bet > DAT_011a0828)
                bet = DAT_011a0828;
            DAT_011da9a4->tile->SetTraitAndReset(DAT_011da998, 1.0f);
            DAT_011da9a4->tile->FUN_00700320(DAT_011da998, bet);
            if (iOldBet != bet)
            {
                char sound[260];
                FUN_00406d00(sound, 260, "GAMESlotsIncreaseBet0%i", soundIndex);
                FUN_00453a70()->FUN_00ad7550(sound, 289, 0).Play();
                soundIndex = soundIndex + 1 > 3 ? 1 : soundIndex + 1;
            }
            break;
        }
        case 5: {
            int iOldBet = bet;
            if (bet <= 10)
                bet -= 1;
            else if (bet <= 40)
                bet = bet % 5 ? bet / 5 * 5 : bet - 5;
            else if (bet <= 100)
                bet = bet % 10 ? bet / 10 * 10 : bet - 10;
            else if (bet <= 500)
                bet = bet % 25 ? bet / 25 * 25 : bet - 25;
            else
                bet = bet % 100 ? bet / 100 * 100 : bet - 100;
            if (bet < DAT_011a082c)
                bet = DAT_011a082c;
            DAT_011da9a4->tile->SetTraitAndReset(DAT_011da998, 1.0f);
            DAT_011da9a4->tile->FUN_00700320(DAT_011da998, bet);
            if (iOldBet != bet)
            {
                FUN_00453a70()->FUN_00ad7550("GAMESlotsDecreaseBet", 289, 0).Play();
                soundIndex = 1;
            }
            break;
        }
        case 6:
            state = 4;
            break;
        case 7:
            if (bet != DAT_011a0828)
            {
                bet = DAT_011a0828;
                if (bet > funds)
                    bet = funds;
                DAT_011da9a4->tile->SetTraitAndReset(DAT_011da998, 1.0f);
                DAT_011da9a4->tile->FUN_00700320(DAT_011da998, bet);
                char sound[260];
                FUN_00406d00(sound, 260, "GAMESlotsIncreaseBet0%i", soundIndex);
                FUN_00453a70()->FUN_00ad7550(sound, 289, 0).Play();
                soundIndex = soundIndex + 1 > 3 ? 1 : soundIndex + 1;
            }
            break;
        }
    }
    else if (state == 4)
        state = 5;
}
}  // namespace fnv_007c2460
