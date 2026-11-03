
// src/fallout/interface/menus/sleepwaitmenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/sleepwaitmenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct SleepWaitMenu
{
    int FUN_007bfbc0();
};

// @fnv 0x007bfbc0
int SleepWaitMenu::FUN_007bfbc0()
{
    return 0x3f4;
}

namespace fnv_007bfbd0 {
struct SleepWaitMenu;

extern "C" void* __cdecl _Deallocate(void*);

struct SleepWaitMenu
{
    void* __thiscall FUN_007bfbd0(unsigned int flags);
    void* __thiscall FUN_007bfc00();
};

void* SleepWaitMenu::FUN_007bfc00()
{
    return this;
}

// Returns this, and if bit 0 of flags is set, deallocates this before returning it.
// @fnv 0x007bfbd0
void* SleepWaitMenu::FUN_007bfbd0(unsigned int flags)
{
    FUN_007bfc00();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
}  // namespace fnv_007bfbd0

struct BSStringTChar
{
    char* data;
    unsigned short length, capacity;
    ~BSStringTChar();
    const char* FUN_00559450();
};
struct Time
{
    float FUN_00867da0();
    BSStringTChar FormatDate();
    const char* GetDayName();
};
extern Time DAT_011de7b8;
struct Setting
{
    const char* FUN_00403df0();
};
extern Setting DAT_011d24fc, DAT_011d27f0;
int __cdecl sprintf_s(char*, unsigned, const char*, ...);
struct Tile
{
    void FUN_00a01350(int, const char*, bool);
};
struct Menu
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30;
    Tile* tile;
    void UpdateClockText();
};
// Builds a 12-hour clock string from the current game time and passes it to the tile via FUN_00a01350.
// @fnv 0x007c0000
void Menu::UpdateClockText()
{
    char szClockText[260];
    int hour;
    {
        float time = DAT_011de7b8.FUN_00867da0();
        hour = (int)time;
        {
            int minute = (int)((time - hour) * 60.0);
            if (time >= 0.0 && time < 1.0)
                hour = 12;
            else if (time >= 13.0)
                hour -= 12;
            sprintf_s(szClockText, 260, "%s, %s, %d:%02d %s", DAT_011de7b8.GetDayName(),
                      DAT_011de7b8.FormatDate().FUN_00559450(), hour, minute,
                      time < 12.0 ? DAT_011d24fc.FUN_00403df0() : DAT_011d27f0.FUN_00403df0());
        }
    }
    tile->FUN_00a01350(0xfc4, szClockText, true);
}

namespace fnv_007c01b0 {
struct BGSSaveLoadGame
{
    bool FUN_0042ce10();
};
struct ProcessLists
{
    void UpdateActor3D();
};
struct Interface
{
    void FUN_007010e0(int, int);
};
struct Tile
{
    void Set(int, int);
};
struct MenuState
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40;
    char unk44;
    bool active;
    Tile* FUN_00726070();
    void FUN_00a1d910();
};
extern BGSSaveLoadGame* g_BGSSaveLoadGame;
extern ProcessLists DAT_011e0e80;
extern Interface* DAT_011d8804;
extern MenuState* DAT_011da920;

// @fnv 0x007c01b0
void FUN_007c01b0()
{
    if (DAT_011da920)
    {
        if (!g_BGSSaveLoadGame->FUN_0042ce10())
            DAT_011e0e80.UpdateActor3D();
        if (DAT_011da920->active)
            DAT_011d8804->FUN_007010e0(0, 0);
        DAT_011da920->FUN_00726070()->Set(0x1772, 1);
        DAT_011da920->FUN_00a1d910();
    }
}
}  // namespace fnv_007c01b0

extern void* DAT_011da918;
void* __cdecl TraitNameToID(const char* asName);

struct MenuBaseObject
{
    virtual void v00();

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

    MenuBaseObject();
    ~MenuBaseObject();
};

struct FUN_007bfb30_cls : MenuBaseObject
{
    virtual void v00();

    float m_f40;
    unsigned char m_b44;
    unsigned char unk45;
    unsigned char m_b46;
    unsigned char unk47;
    float m_f48;

    FUN_007bfb30_cls();
};

// Initializes m_f40, m_b44, m_f48 and m_b46 to zero and stores the result of TraitNameToID("_current_value") in DAT_011da918.
// @fnv 0x007bfb30
FUN_007bfb30_cls::FUN_007bfb30_cls()
{
    m_f40 = 0.0f;
    m_b44 = 0;
    m_f48 = 0.0f;
    m_b46 = 0;
    DAT_011da918 = TraitNameToID("_current_value");
}

namespace fnv_007c0220 {
struct DecCfg
{
    float* FUN_00403e20(int);
};
struct DecGate
{
    const unsigned char* FUN_00408d60();
};
struct DecMenuA
{
    void ResetAndUpdate();
};
struct DecSnd
{
    void FUN_00700960(int, float);
};
struct DecCtl
{
    void FUN_00700320(int, int);
};
struct DecTile
{
    void FUN_00a011b0(int, unsigned char);
};
struct DecMgr
{
    void FUN_005c1a00(int);
    void FUN_005c1a00(int, int);
    bool FUN_005c7870();
};
struct DecBox
{
    void FUN_00974fc0();
    void FUN_00975160();
};

extern DecCfg DAT_011c3e7c;
extern DecGate DAT_011d89f0, DAT_011d8974;
extern DecMenuA* DAT_011de134;
extern DecSnd* DAT_011d8804;
extern int DAT_011da918;
extern DecMgr* DAT_011dea3c;
extern DecBox DAT_011e0e80;

int __cdecl FUN_00ec62c0();
void __cdecl FUN_00717280(int);
void __cdecl FUN_004d5c60(int);
void __cdecl FUN_007c01b0();

struct FUN_007c0220_cls
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    int m_slot[6];
    int unk40;
    unsigned char m_44;
    unsigned char m_45;

    void FUN_007c0220(int slot, int value);
};

// @fnv 0x007c0220
void FUN_007c0220_cls::FUN_007c0220(int slot, int value)
{
    if (value == 0 && slot >= 0 && slot < 6)
    {
        value = m_slot[slot];
    }
    switch (slot)
    {
    case 4:
        FUN_00717280(1);
        if ((m_45 && *DAT_011d89f0.FUN_00408d60()) || (!m_45 && *DAT_011d8974.FUN_00408d60()))
        {
            DAT_011de134->ResetAndUpdate();
        }
        if (m_45 != 0)
        {
            DAT_011d8804->FUN_00700960(0, *DAT_011c3e7c.FUN_00403e20(0));
        }
        m_44 = 1;
        reinterpret_cast<DecCtl*>(m_slot[4])->FUN_00700320(0xfaf, 0);
        reinterpret_cast<DecCtl*>(m_slot[1])->FUN_00700320(0xfaf, 0);
        reinterpret_cast<DecTile*>(m_slot[1])->FUN_00a011b0(DAT_011da918, m_45);
        DAT_011dea3c->FUN_005c1a00(FUN_00ec62c0() + 1);
        if (m_45 != 0)
        {
            FUN_004d5c60(0x17);
        }
        if (!DAT_011dea3c->FUN_005c7870())
        {
            DAT_011e0e80.FUN_00974fc0();
        }
        DAT_011e0e80.FUN_00975160();
        break;
    case 5:
        FUN_00717280(2);
        DAT_011dea3c->FUN_005c1a00(0, 0);
        FUN_007c01b0();
        break;
    }
}
}  // namespace fnv_007c0220

namespace fnv_007c04d0 {
extern float DAT_0104a494;
extern float DAT_010162c0;
extern int DAT_011da918;
extern char str_01070250[];
int __cdecl TraitNameToID(const char* s);

struct FUN_007c04d0_sub2c
{
    float FUN_00a011b0(int a, int b);
    void FUN_00a012d0(int a, float b);
    void SetTraitAndReset(int a, float b);
};

struct FUN_007c04d0_sub38
{
    bool IsTraitNonZero(int a);
};

struct FUN_007c04d0_cls
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28;
    FUN_007c04d0_sub2c* m_2c;
    int unk30;
    int unk34;
    FUN_007c04d0_sub38* m_38;

    bool FUN_007c04d0(int a1, int a2);
};

// @fnv 0x007c04d0
bool FUN_007c04d0_cls::FUN_007c04d0(int a1, int aiUnused)
{
    bool done = false;
    if (m_38->IsTraitNonZero(0xfaf))
    {
        if (a1 == 0xf || a1 == 0x10)
        {
            m_2c->FUN_00a012d0(DAT_011da918,
                               m_2c->FUN_00a011b0(DAT_011da918, 0) + (a1 == 0xf ? DAT_0104a494 : DAT_010162c0));
            m_2c->SetTraitAndReset(TraitNameToID(str_01070250), 1.0f);
            done = true;
        }
    }
    return done;
}
}  // namespace fnv_007c04d0

namespace fnv_007c03a0 {
extern int DAT_011da918;
extern Setting DAT_011d3ae0, DAT_011d448c;
int __cdecl FUN_00406d90(float f);
void __cdecl FUN_00706f30(int a);

struct S_007c03a0_Gauge
{
    float FUN_00a011b0(int id);
};
struct S_007c03a0_Flag
{
    bool IsTraitNonZero(int id);
};

struct S_007c03a0_Menu
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
    S_007c03a0_Gauge* m_gauge;
    Tile* m_tile;
    int unk34;
    S_007c03a0_Flag* m_flag;
    int unk3c;
    int unk40;
    int unk44;
    float m_uiFilterValue;
    void UpdateGaugeDisplay();
};

// When the gauge value for DAT_011da918 changes, updates the cached value, optionally triggers FUN_00706f30(4), and writes a formatted string to the tile.
// @fnv 0x007c03a0
void S_007c03a0_Menu::UpdateGaugeDisplay()
{
    char szText[260];
    if (m_gauge->FUN_00a011b0(DAT_011da918) != m_uiFilterValue)
    {
        if (m_flag->IsTraitNonZero(0xfaf))
        {
            FUN_00706f30(4);
        }
        m_uiFilterValue = m_gauge->FUN_00a011b0(DAT_011da918);
        sprintf_s(szText, 0x104, "%d %s", FUN_00406d90((float)(m_uiFilterValue + 1.0)),
                  (m_uiFilterValue > 0.0) ? DAT_011d3ae0.FUN_00403df0() : DAT_011d448c.FUN_00403df0());
        m_tile->FUN_00a01350(0xfc4, szText, true);
    }
}
}  // namespace fnv_007c03a0

struct InputManagerStub
{
    int FUN_00a24660();
};

struct OSGlobalsStub
{
    InputManagerStub* FUN_00877720(int, int);
};

struct PlayerStub
{
    bool FUN_0094df60();
    bool FUN_004d1360();
    void FUN_00969c30();
    void FUN_0094df80();
    int FUN_005cde20();
};

struct TimeGlobalStub
{
    float FUN_0084d030();
};

struct TESStub
{
    void FUN_00455490();
};

struct TileStub
{
    void FUN_00700320(int, int);
    void SetTraitAndReset(int, float);
};

extern OSGlobalsStub* DAT_011dea0c;
extern PlayerStub* DAT_011dea3c;
extern TESStub* DAT_011dea10;
extern TimeGlobalStub DAT_011f6394;

bool __cdecl FUN_00703d50();

struct MenuClass
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03(int, int);

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
    TileStub* m_tile;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    float m_f40;
    unsigned char m_b44;
    unsigned char unk45;
    unsigned char m_b46;
    unsigned char unk47;

    void UpdateClockText();
    bool FUN_007c0580();
};

// Handles input state flags and, while m_b44 is set, advances m_f40 by the frame time and updates the tile's _current_value and _SetInCode when it reaches 1.0.
// @fnv 0x007c0580
bool MenuClass::FUN_007c0580()
{
    if (DAT_011dea0c->FUN_00877720(15, 2)->FUN_00a24660())
    {
        m_b46 = 1;
    }
    if ((m_b46 && DAT_011dea0c->FUN_00877720(15, 1)->FUN_00a24660()) || (m_b44 && !DAT_011dea3c->FUN_0094df60()))
    {
        if (!FUN_00703d50())
        {
            v03(5, 0);
            return false;
        }
    }
    if (!m_b44)
    {
        return false;
    }
    m_f40 += DAT_011f6394.FUN_0084d030();
    if (m_f40 >= 1.0)
    {
        m_f40 = 0.0f;
    }
    else
    {
        return false;
    }
    DAT_011dea10->FUN_00455490();
    if (DAT_011dea3c->FUN_004d1360())
    {
        DAT_011dea3c->FUN_00969c30();
    }
    DAT_011dea3c->FUN_0094df80();
    m_tile->FUN_00700320((int)TraitNameToID("_current_value"), DAT_011dea3c->FUN_005cde20() - 1);
    m_tile->SetTraitAndReset((int)TraitNameToID("_SetInCode"), 1.0f);
    UpdateClockText();
    return true;
}

struct SwTile
{
    float FUN_00a011b0(int m_uiSoundID);
    void FUN_00a012d0(int m_uiSoundID, float fValue, bool bPropagate);
    void FUN_00a01350(int m_uiSoundID, const char* pcString, bool bPropagate);
    SwTile* FUN_00a03da0(const char* pcName);
    struct SwMenu* FUN_00a03c90();
};
float __cdecl FUN_00a01530();

struct SwMenu
{
    virtual ~SwMenu();
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
    virtual int GetID();
    int unk04[9];
    SwTile* unk28;
    int unk2c;
    SwTile* unk30;
    int unk34;
    SwTile* unk38;
    SwTile* unk3c;
    int unk40;
    unsigned char unk44;
    unsigned char m_bSleep;

    void FUN_00a1dc70(SwTile* pkTile, int i);
    bool FUN_007abdb0();
    void UpdateClockText();
    SwTile* FUN_00726070();
    void FUN_00a1dc20(int i);
};
extern SwMenu* g_pkSleepWaitMenu_011da920;

struct SwMenuRoot
{
    SwTile* ReadXML(const char* pcPath);
};
struct SwInterface
{
    SwMenuRoot* FUN_00586150();
};
SwInterface* __cdecl FUN_004b7210();
int __cdecl FUN_00705770();
SwMenu* __cdecl FUN_00a09030(int m_uiSoundID);
void __cdecl FUN_005b5e40(const char* pcFormat, ...);
int __cdecl FUN_00406d30(char* pcDest, unsigned int uiSize, const char* pcSrc);
int __cdecl FUN_00406d00(char* pcDest, unsigned int uiSize, const char* pcFormat, ...);
extern "C" int __cdecl toupper(int c);

struct SwSoundHandle
{
    int unk00, unk04, unk08;
    ~SwSoundHandle();
    bool Play();
};
struct SwAudio
{
    static SwAudio* GetSingleton();
    SwSoundHandle FUN_00ad7550(const char* pcName, unsigned int uiFlags, int i);
};

struct SwStrSetting
{
    const char* FUN_00403df0();
};
struct SwFloatSetting
{
    float* FUN_00403e20();
};
extern SwStrSetting g_s_011d3948;
extern SwStrSetting g_s_011d23ac;
extern SwStrSetting g_s_011d2910;
extern SwStrSetting g_s_011d448c;
extern SwStrSetting g_s_011d29f4;
extern SwFloatSetting g_s_011d3174;

static const char s_szMenuPath[] = "Data\\Menus\\sleep_wait_menu.xml";
static const char s_szError[] = "MENUS: Sleep Wait Menu Creation Failed... Are your menu and art resources up to date?";
static const char s_szSound[] = "UIPopUpMessageGeneral";
static const char s_szTitleFormat[] = "%s %s?";
static const char s_szHourFormat[] = "1 %s";
static const char s_szBackground[] = "SWM_Background";
extern const char g_szSleepWaitEnd[] = "";

// Creates the sleep/wait menu from s_szMenuPath, sets its title, verb, hour, clock, and background, and returns the root tile or 0 on failure.
// @fnv 0x007bfc30
SwTile* __cdecl CreateSleepWaitMenu(bool bSleep)
{
    SwInterface* pkInterfaceY = FUN_004b7210();
    SwMenu* pkOld_ = FUN_00a09030(FUN_00705770());
    if (pkOld_)
        delete pkOld_;
    SwTile* pkTileTmp2 = pkInterfaceY->FUN_00586150()->ReadXML(s_szMenuPath);
    g_pkSleepWaitMenu_011da920 = pkTileTmp2->FUN_00a03c90();
    if (g_pkSleepWaitMenu_011da920 && g_pkSleepWaitMenu_011da920->GetID() == FUN_00705770())
    {
        g_pkSleepWaitMenu_011da920->FUN_00a1dc70(pkTileTmp2, 0);
        if (!g_pkSleepWaitMenu_011da920->FUN_007abdb0())
        {
            FUN_005b5e40(s_szError);
            return 0;
        }
        SwAudio::GetSingleton()->FUN_00ad7550(s_szSound, 0x121, 0).Play();
        if (pkTileTmp2->FUN_00a011b0(0xfa7) == 6006.0 || pkTileTmp2->FUN_00a011b0(0xfa7) == 102.0)
            pkTileTmp2->FUN_00a012d0(0xfad, FUN_00a01530(), true);
        g_pkSleepWaitMenu_011da920->m_bSleep = bSleep;
        char acVerb[0x104];
        if (bSleep)
            FUN_00406d30(acVerb, 0x104, g_s_011d3948.FUN_00403df0());
        else
            FUN_00406d30(acVerb, 0x104, g_s_011d23ac.FUN_00403df0());
        char acText[0x104];
        FUN_00406d00(acText, 0x104, s_szTitleFormat, g_s_011d2910.FUN_00403df0(), acVerb);
        g_pkSleepWaitMenu_011da920->unk28->FUN_00a01350(0xfc4, acText, true);
        acVerb[0] = toupper(acVerb[0]);
        g_pkSleepWaitMenu_011da920->unk38->FUN_00a01350(0xfc4, acVerb, true);
        FUN_00406d00(acText, 0x104, s_szHourFormat, g_s_011d448c.FUN_00403df0());
        g_pkSleepWaitMenu_011da920->unk30->FUN_00a01350(0xfc4, acText, true);
        g_pkSleepWaitMenu_011da920->UpdateClockText();
        g_pkSleepWaitMenu_011da920->unk3c->FUN_00a01350(0xfc4, g_s_011d29f4.FUN_00403df0(), true);
        g_pkSleepWaitMenu_011da920->FUN_00726070()
            ->FUN_00a03da0(s_szBackground)
            ->FUN_00a012d0(0xfa9, *g_s_011d3174.FUN_00403e20() * 255.0, true);
        g_pkSleepWaitMenu_011da920->FUN_00a1dc20(0);
        return pkTileTmp2;
    }
    else
    {
        if (g_pkSleepWaitMenu_011da920 && g_pkSleepWaitMenu_011da920->FUN_00726070())
            delete g_pkSleepWaitMenu_011da920;
    }
    return 0;
}

struct Menu_007a8b10
{
    virtual ~Menu_007a8b10();
};
extern int DAT_010763ac;
extern int DAT_011da920;
struct FUN_007bfc00_shell : Menu_007a8b10
{
    void FUN_007bfc00();
};
// Sets the vtable pointer to DAT_010763ac, zeroes DAT_011da920, and calls the Menu_007a8b10 destructor.
// @fnv 0x007bfc00
void FUN_007bfc00_shell::FUN_007bfc00()
{
    *reinterpret_cast<int**>(this) = &DAT_010763ac;
    DAT_011da920 = 0;
    Menu_007a8b10::~Menu_007a8b10();
}
