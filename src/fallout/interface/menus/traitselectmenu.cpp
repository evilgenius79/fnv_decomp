
// src/fallout/interface/menus/traitselectmenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/traitselectmenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct TraitSelectMenu
{
    int __thiscall FUN_007e7ac0();
};

// @fnv 0x007e7ac0
int __thiscall TraitSelectMenu::FUN_007e7ac0()
{
    return 0x434;
}

// @fnv 0x007e7d90
int __cdecl FUN_007e7d90()
{
    return 0x434;
}

namespace fnv_007e8840 {
class TraitSelectMenu
{
  public:
    void __thiscall HandleTraitSelection(int a1, int a2);
    void __thiscall FUN_007e8840();
};

// @fnv 0x007e8840
void __thiscall TraitSelectMenu::FUN_007e8840()
{
    HandleTraitSelection(-1, 0);
}
}  // namespace fnv_007e8840

struct FUN_007e7da0_shell
{
    int m_kPointA[10];
    int m_kPointB[10];
    bool FUN_007e7da0();
};

// @fnv 0x007e7da0
bool __thiscall FUN_007e7da0_shell::FUN_007e7da0()
{
    for (int i = 0; i < 0x12; ++i)
    {
        if (m_kPointB[i] == 0)
            return false;
    }
    return true;
}

void __cdecl _Deallocate(void*);
struct S_007e7b00
{
    void __thiscall FUN_007e7b30();
    void* __thiscall DestroyIfFlagged(unsigned int);
};
// Calls FUN_007e7b30, then deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x007e7b00
void* __thiscall S_007e7b00::DestroyIfFlagged(unsigned int flags)
{
    FUN_007e7b30();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

extern int DAT_01077abc;
extern int DAT_011db00c;
struct Menu_007a8b10
{
    virtual ~Menu_007a8b10();
};
struct Holder : Menu_007a8b10
{
    void __thiscall FUN_007e7b30();
};
// Sets the object's vtable pointer to DAT_01077abc, clears DAT_011db00c, then calls the base Menu_007a8b10 destructor.
// @fnv 0x007e7b30
void __thiscall Holder::FUN_007e7b30()
{
    *(int*)this = (int)&DAT_01077abc;
    DAT_011db00c = 0;
    this->Menu_007a8b10::~Menu_007a8b10();
}

namespace fnv_007e7de0 {
struct Tile
{
    void Set(int, int);
};
struct Menu
{
    Tile* _ref_00726070();
    void LoadMenuData();
};
struct BGSSaveLoadGame
{
    bool FUN_0042ce10();
};
struct FUN_00975d10_host
{
    void UpdateActor3D();
};
extern Menu* DAT_011db00c;
extern BGSSaveLoadGame* g_BGSSaveLoadGame;
extern FUN_00975d10_host DAT_011e0e80;
// @fnv 0x007e7de0
void FUN_007e7de0()
{
    if (DAT_011db00c)
    {
        if (!g_BGSSaveLoadGame->FUN_0042ce10())
            DAT_011e0e80.UpdateActor3D();
        DAT_011db00c->_ref_00726070()->Set(0x1772, 1);
        DAT_011db00c->LoadMenuData();
    }
}
}  // namespace fnv_007e7de0

void* __cdecl FUN_004b7210();
struct FUN_0070ec70_This
{
    int __thiscall FUN_0070ec70();
};
extern float const runtimeFloatSettingDefault275;
struct FUN_007e82b0_shell
{
    void __thiscall FUN_007e8310(float);
    void __thiscall FUN_007e82b0(int, int);
};
// Reads a value from FUN_004b7210 and calls FUN_007e8310 with 0.05f when it is negative or with runtimeFloatSettingDefault275 when it is positive.
// @fnv 0x007e82b0
void __thiscall FUN_007e82b0_shell::FUN_007e82b0(int, int)
{
    if (((FUN_0070ec70_This*)FUN_004b7210())->FUN_0070ec70() < 0)
        FUN_007e8310(0.05f);
    if (((FUN_0070ec70_This*)FUN_004b7210())->FUN_0070ec70() > 0)
        FUN_007e8310(runtimeFloatSettingDefault275);
}

struct FUN_007e8860_shell
{
    int m_kPointA[31];
    int m_iSelectedTrait;
    void FUN_007e8840();
    void SelectTrait(int, int);
    void FUN_007e8860(int tile);
};

// @fnv 0x007e8860
void FUN_007e8860_shell::FUN_007e8860(int tile)
{
    if (m_iSelectedTrait == tile)
        FUN_007e8840();
    else
        SelectTrait(tile, 0);
}

struct Tile;
struct FUN_007e7ad0_shell
{
    char _pad[0x28];
    Tile* m_pTiles[18];
    void __thiscall SetTileByID(int aiID, Tile* apTile);
};
// @fnv 0x007e7ad0
void __thiscall FUN_007e7ad0_shell::SetTileByID(int aiID, Tile* apTile)
{
    if (aiID >= 0 && aiID < 0x12)
    {
        m_pTiles[aiID] = apTile;
    }
}

struct Tile;
struct TraitSelectMenuStandIn
{
    char _pad[0x28];
    Tile* m_pTiles[18];
    void __thiscall FUN_007e8280(int aiID, Tile* apTarget);
};
// @fnv 0x007e8280
void __thiscall TraitSelectMenuStandIn::FUN_007e8280(int aiID, Tile* apTarget)
{
    if (apTarget == 0 && aiID >= 0 && aiID < 0x12)
        apTarget = m_pTiles[aiID];
}

void __cdecl FUN_007e7de0();
void __cdecl FUN_00717280(int);

struct FUN_007e7e30_shell
{
    char _pad[0x28];
    Tile* m_pTiles[18];
    void __thiscall FUN_007e7e30(int aiID, Tile* apTarget);
};

// @fnv 0x007e7e30
void FUN_007e7e30_shell::FUN_007e7e30(int aiID, Tile* apTarget)
{
    if (apTarget == 0 && aiID >= 0 && aiID < 0x12)
    {
        apTarget = this->m_pTiles[aiID];
    }

    switch (aiID)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
        ((FUN_007e8860_shell*)this)->FUN_007e8860(aiID);
        break;
    case 14:
        FUN_00717280(1);
        FUN_007e7de0();
        break;
    }
}

class B7E81B0Menu
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void HandleClick(int iTileID, void* pvTile);

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
    void* m_pvTile;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int m_iSelected;

    void FUN_007e8860(int iIndex);
    void ChangePage(bool bNext);
    bool HandleKeyInput(int iKey, int iUnused);
};

// @fnv 0x007e81b0
bool B7E81B0Menu::HandleKeyInput(int iKey, int iUnused)
{
    bool bHandled = false;
    switch (iKey)
    {
    case 9:
        if (m_iSelected >= 0 && m_iSelected <= 0xc)
            FUN_007e8860(m_iSelected);
        else if (m_iSelected == 0xe)
            HandleClick(0xe, m_pvTile);
        bHandled = true;
        break;
    case 10:
        bHandled = true;
        break;
    case 1:
        ChangePage(true);
        bHandled = true;
        break;
    case 2:
        ChangePage(false);
        bHandled = true;
        break;
    }
    return bHandled;
}

class C7E85C0Menu
{
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
    unsigned int m_uiPage;

    void SetPage(unsigned int uiPage, bool bInstant);
    void ChangePage(bool bPrevious);
};

// @fnv 0x007e85c0
void C7E85C0Menu::ChangePage(bool bPrevious)
{
    if (bPrevious)
    {
        switch (m_uiPage)
        {
        case 0:
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
            SetPage(m_uiPage - 1, false);
            break;
        case 14:
            SetPage(12, false);
            break;
        default:
            SetPage(0, false);
            break;
        }
    }
    else
    {
        switch (m_uiPage)
        {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
            SetPage(m_uiPage + 1, false);
            break;
        case 12:
            SetPage(14, false);
            break;
        case 14:
            break;
        default:
            SetPage(0, false);
            break;
        }
    }
}

unsigned int gm_GetTickCount();

struct Tile
{
    void SetInt(int aiID, int aiValue);
    float GetFloat(int aiID);
    void SetFloat(int aiID, float afValue, bool abPropagate);
};

struct BSSoundHandleEx
{
    int unk00;
    int unk04;
    int unk08;
    ~BSSoundHandleEx();
    bool Play();
};

struct BSAudio
{
    static BSAudio* GetSingleton();
    BSSoundHandleEx GetSoundHandleByEditorID(const char* apEditorID, unsigned int auiFlags, int aiUnk);
};

struct TraitSelectMenuX
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
    Tile* m_pTiles[17];
    Tile* pCheckTile;
    int unk70;
    int unk74;
    int unk78;
    int iCurrentID;
    unsigned int uiLastTick;
    void SelectTrait(int aiID, bool abForce);
};

static const char kErase[] = "UITraitSelectErase";

// @fnv 0x007e86c0
void TraitSelectMenuX::SelectTrait(int aiID, bool abForce)
{
    if (!abForce && iCurrentID == aiID)
        return;
    uiLastTick = gm_GetTickCount();
    if (pCheckTile)
    {
        if (aiID == -1)
        {
            pCheckTile->SetInt(0xfa3, 0);
            BSAudio::GetSingleton()->GetSoundHandleByEditorID(kErase, 0x121, 0).Play();
        }
        else if (m_pTiles[aiID])
        {
            pCheckTile->SetInt(0xfa3, 1);
            pCheckTile->SetFloat(0xfa2, m_pTiles[aiID]->GetFloat(0xfa2) - 8.0, true);
            BSAudio::GetSingleton()->GetSoundHandleByEditorID("UITraitSelectCheckmark", 0x121, 0).Play();
        }
    }
    iCurrentID = aiID;
}

struct MenuOpen
{
    virtual ~MenuOpen();
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
    virtual int GetID();
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
    float scrollX;
    float scrollY;
    int unk78;
    int unk7c;
    int unk80;
    unsigned int lastTick;
    void Attach(Tile*, bool);
    bool Init();
    void Select(int, int);
    void Show(int);
    void* GetRoot();
};
struct RootTile
{
    Tile* ReadFile(const char*);
};
struct ManagerOpen
{
    RootTile* GetRoot();
};
struct TileOpen
{
    MenuOpen* GetMenu();
    float GetValue(int);
    void SetValue(int, float, bool);
};
MenuOpen* FindMenu(int);
void Warning(const char*);
float DefaultDepth();
// @fnv 0x007e7b60
Tile* __cdecl FUN_007e7b60()
{
    ManagerOpen* pManager = (ManagerOpen*)FUN_004b7210();
    MenuOpen* oldMenu = FindMenu(FUN_007e7d90());
    if (oldMenu)
        delete oldMenu;
    Tile* pTile = pManager->GetRoot()->ReadFile("Data\\Menus\\trait_select_menu.xml");
    DAT_011db00c = (int)((TileOpen*)pTile)->GetMenu();
    if (DAT_011db00c && ((MenuOpen*)DAT_011db00c)->GetID() == FUN_007e7d90())
    {
        ((MenuOpen*)DAT_011db00c)->Attach(pTile, false);
        if (!((MenuOpen*)DAT_011db00c)->Init())
        {
            Warning("MENUS: Companion Wheel Menu Creation Failed... Are your menu and art resources up to date?");
            return 0;
        }
        ((MenuOpen*)DAT_011db00c)->scrollX = 0.0f;
        ((MenuOpen*)DAT_011db00c)->scrollY = 0.0f;
        ((MenuOpen*)DAT_011db00c)->Select(0, 0);
        ((MenuOpen*)DAT_011db00c)->lastTick = gm_GetTickCount();
        BSAudio::GetSingleton()->GetSoundHandleByEditorID("UIPopUpMessageGeneral", 0x121, 0).Play();
        if (((TileOpen*)pTile)->GetValue(0xfa7) == 6006.0 || ((TileOpen*)pTile)->GetValue(0xfa7) == 102.0)
            ((TileOpen*)pTile)->SetValue(0xfad, DefaultDepth(), true);
        ((MenuOpen*)DAT_011db00c)->Show(0);
        return pTile;
    }
    else
    {
        if (DAT_011db00c && ((MenuOpen*)DAT_011db00c)->GetRoot())
            delete (MenuOpen*)DAT_011db00c;
    }
    return 0;
}

int __cdecl TraitNameToID(const char* name);
bool __cdecl FUN_004b71d0();
int __cdecl FUN_00ec7d40(int value);
extern short DAT_011d8a5e;
extern short DAT_011d8a62;
struct FUN_00755680_shell
{
    bool FUN_00755680();
};
struct FUN_00a012d0_t
{
    void FUN_00a012d0(int id, float value, bool propagate);
};
struct TraitScrollTile : FUN_00a012d0_t
{
    float FUN_00a011b0(int id);
};
struct TraitScrollMenu : FUN_007e82b0_shell
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
    TraitScrollTile* scrollTile;
    int unk60;
    int unk64;
    int unk68;
    TraitScrollTile* selectedTile;
    float currentPosition;
    float targetPosition;
    int unk78;
    int currentID;
    unsigned int selectionTick;
    unsigned int updateTick;
    void UpdateScrollAnimation();
};
// @fnv 0x007e7ea0
void TraitScrollMenu::UpdateScrollAnimation()
{
    if (scrollTile)
    {
        int id = TraitNameToID("_current_value");
        if (scrollTile->FUN_00a011b0(id) != currentPosition * 10.0f)
            FUN_007e8310(scrollTile->FUN_00a011b0(id) * 0.1f - currentPosition);
    }
    bool bVertical = false;
    bool overrideFlag3 = false;
    float horizontal = 0.0f;
    float vertical = 0.0f;
    if ((FUN_004b7210(), FUN_004b71d0()) && !static_cast<FUN_00755680_shell*>(FUN_004b7210())->FUN_00755680())
    {
        if ((FUN_004b7210(), FUN_004b71d0()) && !static_cast<FUN_00755680_shell*>(FUN_004b7210())->FUN_00755680())
        {
            if (FUN_00ec7d40(DAT_011d8a5e) > 7849)
            {
                overrideFlag3 = true;
                horizontal = DAT_011d8a5e;
            }
            if (FUN_00ec7d40(DAT_011d8a62) > 8689)
            {
                bVertical = true;
                vertical = DAT_011d8a62;
            }
        }
    }
    if (currentID != -1 && selectedTile)
    {
        unsigned int elapsed = gm_GetTickCount() - selectionTick;
        if (elapsed < 50)
        {
            selectedTile->FUN_00a012d0(4032, 0.0f, true);
            selectedTile->FUN_00a012d0(4031, 0.0f, true);
        }
        else if (elapsed < 100)
        {
            selectedTile->FUN_00a012d0(4032, 0.0f, true);
            selectedTile->FUN_00a012d0(4031, 32.0f, true);
        }
        else if (elapsed < 150)
        {
            selectedTile->FUN_00a012d0(4032, 64.0f, true);
            selectedTile->FUN_00a012d0(4031, 0.0f, true);
        }
        else
        {
            selectedTile->FUN_00a012d0(4032, 64.0f, true);
            selectedTile->FUN_00a012d0(4031, 32.0f, true);
        }
    }
    if ((FUN_004b7210(), FUN_004b71d0()) && !static_cast<FUN_00755680_shell*>(FUN_004b7210())->FUN_00755680())
    {
        unsigned int elapsed = gm_GetTickCount() - updateTick;
        updateTick = gm_GetTickCount();
        if (targetPosition != currentPosition)
        {
            float difference = elapsed * 0.001f;
            float step = targetPosition - currentPosition;
            if (step > difference)
                step = difference;
            if (step < -difference)
                step = -difference;
            FUN_007e8310(step);
        }
    }
}

TraitScrollTile* __cdecl FUN_00a09030(int aiType);
int __cdecl FUN_00706f30(int);

struct TraitPokeTile
{
    void SetTraitAndReset(int aiID, float afValue);
};

// Clamps currentPosition to [0,1], updates scroll tile position and value display, and sets _SetInCode on the scroll tile.
// @fnv 0x007e8310
void FUN_007e82b0_shell::FUN_007e8310(float afDelta)
{
    ((TraitScrollMenu*)this)->currentPosition += afDelta;
    if (((TraitScrollMenu*)this)->currentPosition > 1.0)
        ((TraitScrollMenu*)this)->currentPosition = 1.0f;
    if (((TraitScrollMenu*)this)->currentPosition < 0.0)
        ((TraitScrollMenu*)this)->currentPosition = 0.0f;
    TraitScrollTile* pMenu9 = FUN_00a09030(0x434);
    if (pMenu9)
    {
        float fA5 = pMenu9->FUN_00a011b0(0x1004);
        float fB = pMenu9->FUN_00a011b0(0x1005);
        float fC3 = pMenu9->FUN_00a011b0(0x1006);
        float fD = pMenu9->FUN_00a011b0(0x1007);
        float fE2 = pMenu9->FUN_00a011b0(0x1008);
        float fPos2 = 0.0f;
        ((TraitScrollMenu*)this)->unk64 &&
            (fPos2 = fA5 - ((TraitScrollMenu*)this)->currentPosition * fE2,
             ((TraitScrollTile*)((TraitScrollMenu*)this)->unk64)->FUN_00a012d0(0xfa2, fPos2, true), 1);
        FUN_00706f30(4);
        if (((TraitScrollMenu*)this)->scrollTile)
        {
            int iID2 = TraitNameToID("_current_value");
            float fScaled5 = ((TraitScrollMenu*)this)->currentPosition * 10.0;
            ((TraitScrollMenu*)this)->scrollTile->FUN_00a012d0(iID2, fScaled5, false);
            ((TraitPokeTile*)((TraitScrollMenu*)this)->scrollTile)->SetTraitAndReset(TraitNameToID("_SetInCode"), 1.0f);
        }
    }
}

namespace fnv_007e8470 {
struct TraitSelectMenuCheckState
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
    Tile* m_pTiles[18];
    int unk70;
    float m_fRatio;
    int m_iSelectedTrait;
    void __thiscall FUN_007e8470(int aiID, bool abForce);
};

void* __cdecl FUN_00a09030(int);
extern double const _DAT_01012060;

// Selects a trait tile by clearing the previous selection, marking the new one, and computing m_fRatio from the selected and initial setting values.
// @fnv 0x007e8470
void __thiscall TraitSelectMenuCheckState::FUN_007e8470(int aiID, bool abForce)
{
    Tile* settings;
    float selectedValue;
    float settingValue;
    float initialSetting;

    if (!abForce && m_iSelectedTrait == aiID)
        return;

    if (m_iSelectedTrait != -1 && m_pTiles[m_iSelectedTrait] != 0)
    {
        m_pTiles[m_iSelectedTrait]->SetInt(0x1005, 0);
    }

    m_iSelectedTrait = aiID;

    if (m_iSelectedTrait != -1)
    {
        if (m_pTiles[m_iSelectedTrait] != 0)
        {
            m_pTiles[m_iSelectedTrait]->SetInt(0x1005, 1);
        }

        FUN_004b7210();
        if (FUN_004b71d0() && !reinterpret_cast<FUN_00755680_shell*>(FUN_004b7210())->FUN_00755680())
        {
            settings = reinterpret_cast<Tile*>(FUN_00a09030(0x434));
            if (settings != 0 && m_pTiles[15] != 0)
            {
                settingValue = settings->GetFloat(0x1008);
                initialSetting = m_pTiles[15]->GetFloat(0xfb0);
                selectedValue = m_pTiles[m_iSelectedTrait]->GetFloat(0xfa2);
                if (initialSetting != _DAT_01012060)
                {
                    m_fRatio = selectedValue / initialSetting;
                }
                else
                {
                    m_fRatio = 0.0f;
                }
            }
        }
    }
}
}  // namespace fnv_007e8470
