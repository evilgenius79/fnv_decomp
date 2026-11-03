// fallout/interface/menus/inventorymenu.cpp: InventoryMenu, Interface, Menu, InventoryCheck and more (30 functions)

#include "inventorymenu_decls.h"

static const int kGetClassValue = 1002;

// @fnv 0x0077fb40
int InventoryMenu::GetClass()
{
    return kGetClassValue;
}

// m_pTiles holds kNumTiles (23) entries, so out-of-range tile ids are ignored.
static const int kNumTiles = 23;

// Stores tile in the tile array at index id when id is within the valid tile range.
// @fnv 0x007cb4e0
void InventoryMenu::AssignTileByID(int aiTileIndex, Tile* tile)
{
    if (aiTileIndex >= 0 && aiTileIndex < kNumTiles)
    {
        m_pTiles[aiTileIndex] = tile;
    }
}

// @fnv 0x0077fa00
InventoryMenu::InventoryMenu()
{
    ms_iValueTileID = Tile::GetTraitID("_Value");
    ms_iItemTypeTileID = Tile::GetTraitID("_ItemType");
    ms_iCurrentTabTileID = Tile::GetTraitID("_CurrentTab");
    ms_iKeyringOpenTileID = Tile::GetTraitID("_KeyringOpen");
    ms_iEquippableItemTileID = Tile::GetTraitID("_EquippableItem");
    for (int i = 0; i < 6; ++i)
    {
        m_kPageStates[i].m_iSelectedItemIndex = -1;
        m_kPageStates[i].m_iScrollOffset = 0;
    }
    m_iCurrentTab = 0;
}

// Handles hotkey selection for the inventory menu: toggles hotkey slots, shows messages for invalid items, and updates the item card display.
// @fnv 0x00781ba0
void InventoryMenu::UpdateDialog()
{
    if (!Interface::GetSelectedTargetIndex(Interface::kInventory) ||
        !Interface::GetPipboyManagerInstance()->IsUnk28Set())
        return;
    int iPage;
    int iHotkey;
    bool bHotkeySelected;
    int iIndex;
    if (FUN_004b71d0())
    {
        if (m_kMenuData.GetVisible())
        {
            m_pTiles[20]->Set(0xfa3, 0);
            m_pTiles[22]->Set(0xfa3, 0);
            iHotkey = m_kMenuData.GetSelectedHotkeyIndex(-1);
            if (iHotkey >= 0)
            {
                DAT_011d9f38 = true;
            }
            else if (DAT_011d9f38)
            {
                if (ms_pActionPointSource && ms_pActionPointSource->GetConditionPercent(true) == 0.0)
                {
                    Interface::ShowMessage(DAT_011d3810.FUN_00403df0(), 0,
                                           "Interface\\Icons\\Message Icons\\glow_message_vaultboy_sad.dds",
                                           "UIVATSInsufficientAP", 2.0f, false);
                }
                else if (!FUN_00726070()->ContainsTrait(ms_iEquippableItemTileID) ||
                         (ms_pActionPointSource &&
                          ms_pActionPointSource->FUN_0044ddc0()->GetFormType() == TESForm::kArmor))
                {
                    Interface::ShowMessage(DAT_011d1e18.FUN_00403df0(), 0,
                                           "Interface\\Icons\\Message Icons\\glow_message_vaultboy_sad.dds",
                                           "UIVATSInsufficientAP", 2.0f, false);
                }
                else
                {
                    m_kMenuData.SetHotkeyItem(ms_pActionPointSource);
                    TESBoundObject* object = ms_pActionPointSource->FUN_0044ddc0();
                    m_kHotkeyObjects.AddHead(object);
                    UpdateItemList();
                    m_kMenuData.SetVisible(true);
                    m_pTiles[11]->Set(0xfa3, 0);
                }
                DAT_011d9f38 = false;
            }
        }
        else if (ms_pActionPointSource && ms_pActionPointSource->FUN_0044ddc0()->GetFormType() == TESForm::kWeapon)
        {
            m_pTiles[20]->Set(0xfa3, 1);
            m_pTiles[22]->Set(0xfa3, 1);
            InterfaceManager::UpdateContainerMenu(0, 0, m_pTiles[20], ms_pActionPointSource, true);
            InterfaceManager::UpdateContainerMenu(0, 0, m_pTiles[22], ms_pActionPointSource, true);
        }
    }
    else
    {
        bHotkeySelected = false;
        if (ms_pActionPointSource && ms_pActionPointSource->FUN_0044ddc0()->GetFormType() == TESForm::kWeapon)
        {
            m_pTiles[20]->Set(0xfa3, 1);
            m_pTiles[22]->Set(0xfa3, 1);
        }
        for (iIndex = 0; !bHotkeySelected && !FUN_00726070()->ContainsTrait(ms_iKeyringOpenTileID) &&
                         iIndex < m_kMenuData.FUN_006e4ba0();
             ++iIndex)
        {
            if (g_osGlobals->FUN_00877720()->FUN_00a24660(iIndex + 17, 1) ||
                (g_osGlobals->FUN_00877720()->FUN_00a24660(iIndex + 17, 0) && iIndex != 1))
            {
                if (iIndex == 1)
                    continue;
                if (!m_kMenuData.GetVisible())
                {
                    m_kMenuData.SetVisible(true);
                    m_pTiles[11]->Set(0xfa3, 0);
                }
                else
                {
                    m_pTiles[20]->Set(0xfa3, 0);
                    m_pTiles[22]->Set(0xfa3, 0);
                }
                m_kMenuData.GetSelectedHotkeyIndex(iIndex);
                bHotkeySelected = true;
            }
        }
        if (!bHotkeySelected && m_kMenuData.GetVisible())
        {
            m_kMenuData.SetVisible(false);
            if (m_kItemList.vfn_04())
                m_pTiles[11]->Set(0xfa3, 1);
        }
    }
    if (Interface::IsSaveLoadActive() && g_osGlobals->FUN_00877720()->FUN_00a23a50(1, 1) && m_kItemList.vfn_04() &&
        !g_osGlobals->FUN_00877720()->FUN_00a24660(14, 1))
        HandleClick(7, 0);
    iPage = ms_pInventoryMenu->m_iCurrentTab + 24;
    if (iPage == 24)
    {
        InterfaceManager::UpdateContainerMenu(m_pTiles[14], m_pTiles[15], m_pTiles[16], ms_pActionPointSource, false);
    }
    else if (iPage == 25)
    {
        InterfaceManager::UpdateContainerMenu(
            ms_pActionPointSource &&
                    static_cast<TESObjectARMO*>(ms_pActionPointSource->FUN_0044ddc0())->GetArmorRating() != 0.0
                ? m_pTiles[17]
                : 0,
            ms_pActionPointSource &&
                    static_cast<TESObjectARMO*>(ms_pActionPointSource->FUN_0044ddc0())->GetDamageThreshold() != 0.0
                ? m_pTiles[18]
                : 0,
            0, ms_pActionPointSource, false);
    }
    m_pTiles[2]->Set(0xfa9, 0.0f, true);
    InterfaceManager::UpdateContainerMenu(g_thePlayer->actorValueOwner.GetActorValue(18) != 0.0 ? m_pTiles[2] : 0,
                                          m_pTiles[21], 0, ms_pActionPointSource, false);
}

// Loads inventory_menu.xml, stores the InventoryMenu, initializes its list and title tiles, and returns the tile or 0 on failure.
// @fnv 0x0077fc10
Tile* InventoryMenu::Create()
{
    InterfaceManager* pMenuInterfaceManager = FUN_004b7210();
    float m_fProjectionDepth = Tile::GetInterfaceScale();
    Menu* oldMenu = Tile::FindMenuById(FUN_0077ff80());
    if (oldMenu)
        delete oldMenu;
    Tile* pTile = pMenuInterfaceManager->FUN_00586150()->ReadFile("Data\\Menus\\Main\\inventory_menu.xml");
    ms_pInventoryMenu = static_cast<InventoryMenu*>(pTile->GetMenu());
    Menu::ReadMenuDefinition("Data\\Menus\\Main\\inventory_menu.xml", ms_pInventoryMenu);
    if (ms_pInventoryMenu && ms_pInventoryMenu->GetID() == FUN_0077ff80())
    {
        ms_pInventoryMenu->SetTileMenu(reinterpret_cast<TileMenu*>(pTile), false);
        ms_pInventoryMenu->FUN_00867a20();
        if (!ms_pInventoryMenu->FUN_0077ff90())
        {
            Warning("MENUS: Inventory Menu Creation Failed... Are your menu and art resources up to date?");
            return 0;
        }
        if (static_cast<TileListBoxCalls*>(pTile)->GetFloat(0xfa7) == 6006.0 ||
            static_cast<TileListBoxCalls*>(pTile)->GetFloat(0xfa7) == 102.0)
            pTile->Set(0xfad, Tile::GetInterfaceScale(), true);
        FUN_004b7210()->tutorialManager.ShowMessage(34, FUN_0077ff80(), 512);
        ms_pInventoryMenu->m_kItemList.Initialize(ms_pInventoryMenu->m_pTiles[4], "IM_InventoryListTemplate");
        ms_pInventoryMenu->m_kItemList.FUN_007a1930(false);
        Interface::SetTileFormattedText(ms_pInventoryMenu->m_pTiles[13], 24, DAT_011d29b8.FUN_00403df0(),
                                        DAT_011d4d50.FUN_00403df0(), DAT_011d40b4.FUN_00403df0(),
                                        DAT_011d2acc.FUN_00403df0(), DAT_011d3258.FUN_00403df0(), 0);
        ms_pInventoryMenu->m_kMenuData.Initialize(ms_pInventoryMenu->m_pTiles[5]);
        ms_pInventoryMenu->m_pTiles[10]->Set(0xfc4, DAT_011d29f4.FUN_00403df0(), true);
        int titleTrait = Tile::GetTraitID("_Title");
        if (ms_pInventoryMenu->m_pTiles[14])
            ms_pInventoryMenu->m_pTiles[14]->Set(titleTrait, DAT_011d2c7c.FUN_00403df0(), true);
        if (ms_pInventoryMenu->m_pTiles[15])
            ms_pInventoryMenu->m_pTiles[15]->Set(titleTrait, DAT_011d412c.FUN_00403df0(), true);
        if (ms_pInventoryMenu->m_pTiles[16])
            ms_pInventoryMenu->m_pTiles[16]->Set(titleTrait, DAT_011d330c.FUN_00403df0(), true);
        if (ms_pInventoryMenu->m_pTiles[17])
            ms_pInventoryMenu->m_pTiles[17]->Set(titleTrait, DAT_011d20c4.FUN_00403df0(), true);
        if (ms_pInventoryMenu->m_pTiles[18])
            ms_pInventoryMenu->m_pTiles[18]->Set(titleTrait, DAT_011d396c.FUN_00403df0(), true);
        ms_pInventoryMenu->SetMenuVisibility(true);
        return pTile;
    }
    else
    {
        if (ms_pInventoryMenu && ms_pInventoryMenu->FUN_00726070())
            delete ms_pInventoryMenu;
    }
    return 0;
}

// @fnv 0x0077ff80
int InventoryMenu::FUN_0077ff80()
{
    return kGetClassValue;
}

// Returns true only if every one of the kNumTiles tile pointers is non-null; otherwise returns false.
// @fnv 0x0077ff90
bool InventoryMenu::FUN_0077ff90()
{
    for (int i = 0; i < kNumTiles; ++i)
    {
        if (!m_pTiles[i])
            return false;
    }
    return true;
}

struct StatsMenu
{
    static StatsMenu* ms_pInventoryMenu;
    unsigned char m_bHealingMode;  // +0x2a0
    void __thiscall RefreshHealingOptions();
};

// @fnv 0x00704390
void __cdecl FUN_00704390()
{
    if (StatsMenu::ms_pInventoryMenu != 0)
    {
        if (*(reinterpret_cast<unsigned char*>(StatsMenu::ms_pInventoryMenu) + 0x2a0) != 0)
        {
            StatsMenu::ms_pInventoryMenu->RefreshHealingOptions();
        }
    }
}

struct FUN_00780be0_shell
{
    unsigned char m_0x00;  // +0x00
    unsigned char m_0x01;  // +0x01
    unsigned char m_0x02;  // +0x02
    unsigned char m_0x03;  // +0x03
    unsigned char m_0x04;  // +0x04
    unsigned char m_0x05;  // +0x05
    unsigned char m_0x06;  // +0x06
    unsigned char m_0x07;  // +0x07
    unsigned char m_0x08;  // +0x08
    unsigned char m_0x09;  // +0x09
    unsigned char m_0x0a;  // +0x0a
    unsigned char m_0x0b;  // +0x0b
    unsigned char m_0x0c;  // +0x0c
    unsigned char m_0x0d;  // +0x0d
    unsigned char m_0x0e;  // +0x0e
    unsigned char m_0x0f;  // +0x0f
    unsigned char m_0x10;  // +0x10
    unsigned char m_0x11;  // +0x11
    unsigned char m_0x12;  // +0x12
    unsigned char m_0x13;  // +0x13
    void __thiscall SetByte13(unsigned char value);
};

// @fnv 0x00780be0
void FUN_00780be0_shell::SetByte13(unsigned char value)
{
    m_0x13 = value;
}

struct FUN_0077fb50_shell
{
    void __thiscall FUN_0077fb80();
    void* __thiscall Destroy(unsigned int flags);
};
// Calls FUN_0077fb80, then deletes this if flags has bit 0 set, and returns this.
// @fnv 0x0077fb50
void* __thiscall FUN_0077fb50_shell::Destroy(unsigned int flags)
{
    FUN_0077fb80();
    if (flags & 1)
        operator delete(this);
    return this;
}

extern double _gModifierZero;
struct TGF
{
    float GetFloat(int) const;
};
// Sets tile property 0xFA3 to whether the float from property 0xFAC is greater than or equal to _gModifierZero.
// @fnv 0x00780c00
void __cdecl FUN_00780c00(Tile* pTile)
{
    pTile->Set(0xFA3, ((TGF*)pTile)->GetFloat(0xFAC) >= _gModifierZero);
}

bool __cdecl _FUN_004b71d0();
int __cdecl FUN_007023c0();
struct FUN_00781b10_shell
{
    void __thiscall ClearActionPointSource();
};
struct FUN_00781620_shell : public InventoryMenu
{
    void __thiscall FUN_00781620(int aiID, Tile* apTarget);
};
// @fnv 0x00781620
void __thiscall FUN_00781620_shell::FUN_00781620(int aiID, Tile* apTarget)
{
    if (aiID == 0x1D || aiID == 0x1E)
    {
        if (!_FUN_004b71d0() || FUN_007023c0() != 0x3F8)
            reinterpret_cast<FUN_00781b10_shell*>(this)->ClearActionPointSource();
        this->FUN_00726070()->Set(InventoryMenu::ms_iEquippableItemTileID, 0);
    }
}

struct ProxyPipboy
{
    void __thiscall SetValue(int, bool);
};
struct ProxyMgr
{
    ProxyPipboy* __thiscall GetPipboyManager();
};
// @fnv 0x00782470
void FUN_00782470(bool a1)
{
    if (InventoryMenu::ms_pInventoryMenu)
        ((ProxyMgr*)FUN_004b7210())->GetPipboyManager()->SetValue(InventoryMenu::ms_pInventoryMenu->m_iCurrentTab, a1);
}

// @fnv 0x007824b0
unsigned char FUN_007824b0()
{
    int currTab;
    if (InventoryMenu::ms_pInventoryMenu)
        currTab = ((unsigned char*)InventoryMenu::ms_pInventoryMenu)[0x84];
    else
        currTab = 0;
    return currTab;
}

unsigned int __fastcall FUN_0044ddc0(void*);
// Returns 0 when a1 is non-null and its form type is 0x2E, otherwise returns 1.
// @fnv 0x00782810
unsigned char __cdecl IsNotFormType2E(void* a1)
{
    int v;
    if (a1)
        v = ((TESForm*)FUN_0044ddc0(a1))->GetFormType() != 0x2E;
    else
        v = 1;
    return v;
}

struct FUN_007832e0_class
{
    void FUN_007832e0(float, float);
};
struct FUN_00726070_shell
{
    Tile* FUN_00726070();
};

// @fnv 0x007800c0
void __cdecl FUN_007800c0()
{
    int iElementIndex;
    if (((FUN_00726070_shell*)InventoryMenu::ms_pInventoryMenu)
            ->FUN_00726070()
            ->ContainsTrait(InventoryMenu::ms_iKeyringOpenTileID))
        iElementIndex = 5;
    else
        iElementIndex = InventoryMenu::ms_pInventoryMenu->m_iCurrentTab;
    int iarg = iElementIndex;
    ((FUN_007832e0_class*)&InventoryMenu::ms_pInventoryMenu->m_kItemList)
        ->FUN_007832e0(InventoryMenu::ms_pInventoryMenu->m_kPageStates[iarg].m_iSelectedItemIndex,
                       InventoryMenu::ms_pInventoryMenu->m_kPageStates[iarg].m_iScrollOffset);
}

struct FUN_004bddd0_t
{
    bool __thiscall FUN_004bddd0(bool);
};

struct FUN_00781860_shell
{
    bool __thiscall FUN_00781860(InventoryStackRecord*);
};

struct FUN_00781680_shell : public InventoryMenu
{
    void __thiscall FUN_00781680();
};

struct GlobalObject_0040c150 : public InventoryMenuSetting
{
};

extern InventoryMenuSetting* DAT_011d5178;
extern GlobalObject_0040c150 g_011d3cdc;
extern GlobalObject_0040c150 g_011d460c;
extern GlobalObject_0040c150 g_011d478c;

// @fnv 0x00781680
void FUN_00781680_shell::FUN_00781680()
{
    int icurrTabIndex;

    if (InventoryMenu::ms_pActionPointSource)
    {
        if (InventoryMenu::ms_pActionPointSource->FUN_0044ddc0()->GetFormType() == 0x19)
        {
            m_pTiles[6]->Set(0xfc4, DAT_011d5178->FUN_00403df0(), true);
        }
        else if (((FUN_004bddd0_t*)InventoryMenu::ms_pActionPointSource)->FUN_004bddd0(false))
        {
            m_pTiles[6]->Set(0xfc4, g_011d460c.FUN_00403df0(), true);
        }

        m_pTiles[6]->Set(
            0xfaf,
            ((TGF*)((FUN_00726070_shell*)this)->FUN_00726070())->GetFloat(InventoryMenu::ms_iEquippableItemTileID),
            true);
        m_pTiles[7]->Set(0xfaf, 1);

        m_pTiles[9]->Set(0xfaf,
                         (unsigned char)(InventoryMenu::ms_pActionPointSource->FUN_0044ddc0()->GetFormType() != 0x29));
        m_pTiles[19]->Set(0xfaf, 1);

        m_pTiles[8]->Set(0xfaf, ((FUN_00781860_shell*)this)->FUN_00781860(InventoryMenu::ms_pActionPointSource));
    }
    else
    {
        icurrTabIndex = InventoryMenu::ms_pInventoryMenu->m_iCurrentTab + 0x18;

        if (icurrTabIndex == 0x1a)
        {
            m_pTiles[6]->Set(0xfc4, g_011d478c.FUN_00403df0(), true);
        }
        else
        {
            m_pTiles[6]->Set(0xfc4, g_011d3cdc.FUN_00403df0(), true);
        }

        m_pTiles[6]->Set(0xfaf, 0);
        m_pTiles[7]->Set(0xfaf, 0);
        m_pTiles[9]->Set(0xfaf, 0);
        m_pTiles[19]->Set(0xfaf, 0);
        m_pTiles[8]->Set(0xfaf, 0);
    }
}

struct FUN_007823d0_listbox
{
    virtual void FUN_007823d0_first() = 0;
    virtual int FUN_007823d0_second() = 0;
};

struct FUN_007823d0_shell : public InventoryMenu
{
    bool __thiscall HandleInventoryButton(int aiButton, float afValue);
};

// Handles inventory menu buttons 16 and 10 when the inventory interface is open, hiding a tile and returning whether the button was handled.
// @fnv 0x007823d0
bool __thiscall FUN_007823d0_shell::HandleInventoryButton(int aiButton, float afValue)
{
    bool bhandled;

    bhandled = false;

    if (Interface::GetSelectedTargetIndex(Interface::kInventory))
    {
        switch (aiButton)
        {
        case 16:
            reinterpret_cast<HotkeyWheelDisplay*>(reinterpret_cast<char*>(this) + 0xE8)->SetVisible(false);

            if (reinterpret_cast<FUN_007823d0_listbox*>(reinterpret_cast<char*>(this) + 0xB8)->FUN_007823d0_second())
            {
                (*reinterpret_cast<Tile**>(reinterpret_cast<char*>(this) + 0x54))->Set(0xFA3, 1);
            }

            bhandled = true;
            break;

        case 10:
            HandleClick(0x0A, 0);
            bhandled = true;
            break;
        }
    }

    return bhandled;
}

namespace fnv_007824e0 {
template <class T> struct ListBoxItem
{
    int m_iValueAt00;
    T m_pInventoryEntryData;
};

struct FUN_004be2d0_shell
{
    unsigned char const* GetTargetFullName();
};

struct FUN_004bddd0_t
{
    bool FUN_004bddd0(bool);
};

int __cdecl FUN_00408b20(char const*, char const*);

// @fnv 0x007824e0
int __cdecl FUN_007824e0(ListBoxItem<InventoryStackRecord*>* apItem1, ListBoxItem<InventoryStackRecord*>* apItem2)
{
    int iresult;

    if (apItem1->m_pInventoryEntryData == 0)
    {
        iresult = 1;
    }
    else if (apItem2->m_pInventoryEntryData == 0)
    {
        iresult = -1;
    }
    else if (FUN_00408b20(
                 reinterpret_cast<char const*>(
                     reinterpret_cast<FUN_004be2d0_shell*>(apItem1->m_pInventoryEntryData)->GetTargetFullName()),
                 reinterpret_cast<char const*>(
                     reinterpret_cast<FUN_004be2d0_shell*>(apItem2->m_pInventoryEntryData)->GetTargetFullName())) == 0)
    {
        iresult = apItem1->m_pInventoryEntryData->GetConditionPercent(0) >
                          apItem2->m_pInventoryEntryData->GetConditionPercent(0)
                      ? -1
                      : (apItem1->m_pInventoryEntryData->GetConditionPercent(0) <
                                 apItem2->m_pInventoryEntryData->GetConditionPercent(0)
                             ? 1
                             : 0);

        if (iresult == 0)
        {
            if (reinterpret_cast<FUN_004bddd0_t*>(apItem1->m_pInventoryEntryData)->FUN_004bddd0(0))
            {
                iresult = -1;
            }
            else if (reinterpret_cast<FUN_004bddd0_t*>(apItem2->m_pInventoryEntryData)->FUN_004bddd0(0))
            {
                iresult = 1;
            }
        }
    }
    else
    {
        iresult = FUN_00408b20(
            reinterpret_cast<char const*>(
                reinterpret_cast<FUN_004be2d0_shell*>(apItem1->m_pInventoryEntryData)->GetTargetFullName()),
            reinterpret_cast<char const*>(
                reinterpret_cast<FUN_004be2d0_shell*>(apItem2->m_pInventoryEntryData)->GetTargetFullName()));
    }

    return iresult;
}
}  // namespace fnv_007824e0

struct XExtra
{
    short __thiscall FUN_00418770();
};

struct ExtraDataList : XExtra
{
};

struct GO
{
    operator unsigned int() const;
};

struct Ref006815c0
{
    void* __thiscall _ref_006815c0();
};

struct NiPoint3
{
    int x;
    int y;
    int z;
};

struct PlayerCharacterShell
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;
    virtual void v40() = 0;
    virtual void v41() = 0;
    virtual void v42() = 0;
    virtual void v43() = 0;
    virtual void v44() = 0;
    virtual void v45() = 0;
    virtual void v46() = 0;
    virtual void v47() = 0;
    virtual void v48() = 0;
    virtual void v49() = 0;
    virtual void v50() = 0;
    virtual void v51() = 0;
    virtual void v52() = 0;
    virtual void v53() = 0;
    virtual void v54() = 0;
    virtual void v55() = 0;
    virtual void v56() = 0;
    virtual void v57() = 0;
    virtual void v58() = 0;
    virtual void v59() = 0;
    virtual void v60() = 0;
    virtual void v61() = 0;
    virtual void v62() = 0;
    virtual void v63() = 0;
    virtual void v64() = 0;
    virtual void v65() = 0;
    virtual void v66() = 0;
    virtual void v67() = 0;
    virtual void v68() = 0;
    virtual void v69() = 0;
    virtual void v70() = 0;
    virtual void v71() = 0;
    virtual void v72() = 0;
    virtual void v73() = 0;
    virtual void v74() = 0;
    virtual void v75() = 0;
    virtual void v76() = 0;
    virtual void v77() = 0;
    virtual void v78() = 0;
    virtual void v79() = 0;
    virtual void v80() = 0;
    virtual void v81() = 0;
    virtual void v82() = 0;
    virtual void v83() = 0;
    virtual void v84() = 0;
    virtual void v85() = 0;
    virtual void v86() = 0;
    virtual void v87() = 0;
    virtual void v88() = 0;
    virtual void v89() = 0;
    virtual void v90() = 0;
    virtual void v91() = 0;
    virtual void v92() = 0;
    virtual void v93() = 0;
    virtual void v94() = 0;
    virtual void v95() = 0;
    virtual void v96() = 0;
    virtual void v97() = 0;
    virtual void v98() = 0;
    virtual void v99() = 0;
    virtual void v100() = 0;
    virtual void v101() = 0;
    virtual void v102() = 0;
    virtual void v103() = 0;
    virtual void v104() = 0;
    virtual void v105() = 0;
    virtual void v106() = 0;
    virtual void v107() = 0;
    virtual void v108() = 0;
    virtual void v109() = 0;
    virtual void v110() = 0;
    virtual void v111() = 0;
    virtual void v112() = 0;
    virtual void v113() = 0;
    virtual void v114() = 0;
    virtual void v115() = 0;
    virtual void v116() = 0;
    virtual void v117() = 0;
    virtual void v118() = 0;
    virtual void v119() = 0;
    virtual void v120() = 0;
    virtual void v121() = 0;
    virtual void v122() = 0;
    virtual void v123() = 0;
    virtual void v124() = 0;
    virtual void v125() = 0;
    virtual void v126() = 0;
    virtual void v127() = 0;
    virtual void v128() = 0;
    virtual void v129() = 0;
    virtual void v130() = 0;
    virtual void v131() = 0;
    virtual void v132() = 0;
    virtual void v133() = 0;
    virtual void v134() = 0;
    virtual void v135() = 0;
    virtual void v136() = 0;
    virtual void v137() = 0;
    virtual void v138() = 0;
    virtual void v139() = 0;
    virtual void v140() = 0;
    virtual void v141() = 0;
    virtual void v142() = 0;
    virtual void v143() = 0;
    virtual void v144() = 0;
    virtual void v145() = 0;
    virtual void v146() = 0;
    virtual void v147() = 0;
    virtual void v148() = 0;
    virtual void v149() = 0;
    virtual void v150() = 0;
    virtual void v151() = 0;
    virtual void v152() = 0;
    virtual void v153() = 0;
    virtual void v154() = 0;
    virtual void v155() = 0;
    virtual void v156() = 0;
    virtual void v157() = 0;
    virtual void v158() = 0;
    virtual void v159() = 0;
    virtual void v160() = 0;
    virtual void v161() = 0;
    virtual void v162() = 0;
    virtual void v163() = 0;
    virtual void v164() = 0;
    virtual void v165() = 0;
    virtual void v166() = 0;
    virtual void v167() = 0;
    virtual void v168() = 0;
    virtual void v169() = 0;
    virtual void v170() = 0;
    virtual void v171() = 0;
    virtual void v172() = 0;
    virtual void v173() = 0;
    virtual void v174() = 0;
    virtual void v175() = 0;
    virtual void v176() = 0;
    virtual void v177() = 0;
    virtual void v178() = 0;
    virtual void v179() = 0;
    virtual void v180() = 0;
    virtual void v181() = 0;
    virtual void v182() = 0;
    virtual void v183() = 0;
    virtual void v184() = 0;
    virtual void v185() = 0;
    virtual void v186() = 0;
    virtual void v187() = 0;
    virtual void v188() = 0;
    virtual void v189() = 0;
    virtual void v190() = 0;
    virtual void v191() = 0;
    virtual void v192() = 0;
    virtual void v193() = 0;
    virtual void v194() = 0;
    virtual void v195() = 0;
    virtual void v196() = 0;
    virtual void v197() = 0;
    virtual void v198() = 0;
    virtual void v199() = 0;
    virtual void v200() = 0;
    virtual void v201() = 0;
    virtual void v202() = 0;
    virtual void v203() = 0;
    virtual void v204() = 0;
    virtual void v205() = 0;
    virtual void v206() = 0;
    virtual void v207() = 0;
    virtual void v208() = 0;
    virtual void v209() = 0;
    virtual void v210() = 0;
    virtual void v211() = 0;
    virtual void v212() = 0;
    virtual void v213() = 0;
    virtual void v214() = 0;
    virtual void v215() = 0;
    virtual void v216() = 0;
    virtual void v217() = 0;
    virtual void v218() = 0;
    virtual void v219() = 0;
    virtual void v220() = 0;
    virtual void v221() = 0;
    virtual void v222() = 0;
    virtual void v223() = 0;
    virtual void v224() = 0;
    virtual void v225() = 0;
    virtual void v226() = 0;
    virtual void v227() = 0;
    virtual void v228() = 0;
    virtual void v229() = 0;
    virtual void v230() = 0;
    virtual void v231() = 0;
    virtual void v232() = 0;
    virtual void v233() = 0;
    virtual void v234() = 0;
    virtual void v235() = 0;
    virtual void v236() = 0;
    virtual void v237() = 0;
    virtual void v238() = 0;
    virtual void v239() = 0;
    virtual void v240() = 0;
    virtual void v241() = 0;
    virtual void v242() = 0;
    virtual void DropInventoryObject(TESBoundObject*, ExtraDataList*, int, NiPoint3*, bool) = 0;
    void __thiscall FUN_009614b0(TESBoundObject*, NiPoint3*, int, int);
};

extern PlayerCharacterShell* _g_thePlayer;
extern int _NiPoint3_ZERO;
extern int _DAT_011f4270;
extern int _DAT_011f4274;

// @fnv 0x00780c50
void __cdecl DropInventoryItem(int aiAmountChosen)
{
    ExtraDataList* pextra;
    TESBoundObject* pobjectRef;
    NiPoint3 dropPoint;

    dropPoint.x = _NiPoint3_ZERO;
    dropPoint.y = _DAT_011f4270;
    dropPoint.z = _DAT_011f4274;

    pobjectRef = InventoryMenu::ms_pActionPointSource->FUN_0044ddc0();

    pextra = reinterpret_cast<GO*>(InventoryMenu::ms_pActionPointSource)->operator unsigned int()
                 ? *reinterpret_cast<ExtraDataList**>(
                       reinterpret_cast<Ref006815c0*>(
                           reinterpret_cast<GO*>(InventoryMenu::ms_pActionPointSource)->operator unsigned int())
                           ->_ref_006815c0())
                 : 0;

    if (aiAmountChosen == 0)
        return;

    if (pextra && pextra->FUN_00418770() < aiAmountChosen)
        pextra = 0;

    _g_thePlayer->FUN_009614b0(pobjectRef, &dropPoint, 1, 1);
    _g_thePlayer->DropInventoryObject(pobjectRef, pextra, aiAmountChosen, &dropPoint, false);

    if (InventoryMenu::ms_pInventoryMenu)
    {
        if (InventoryMenu::ms_pActionPointSource)
        {
            {
                TESBoundObject* p = InventoryMenu::ms_pActionPointSource->FUN_0044ddc0();
                InventoryMenu::ms_pInventoryMenu->m_kHotkeyObjects.AddHead(p);
            }
        }
        InventoryMenu::UpdateItemList();
    }
}

struct MenuBase_0077fb80
{
    virtual ~MenuBase_0077fb80();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
};

struct ListBox_0077fb80
{
    ~ListBox_0077fb80();
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
};

struct HotKeys_0077fb80
{
    ~HotKeys_0077fb80();
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
};

struct List_0077fb80
{
    ~List_0077fb80();
    int unk00;
    int unk04;
};

extern int DAT_011d9ea4;

class FUN_0077fb80_cls : public MenuBase_0077fb80
{
  public:
    virtual ~FUN_0077fb80_cls();
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
    int m_iCurrentTab;
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
    ListBox_0077fb80 m_b8;
    HotKeys_0077fb80 m_e8;
    List_0077fb80 m_11c;
};

// Clears the global DAT_011d9ea4 to zero when the object is destroyed.
// @fnv 0x0077fb80
FUN_0077fb80_cls::~FUN_0077fb80_cls()
{
    DAT_011d9ea4 = 0;
}

extern int DAT_011d9eb8;

class FUN_0077ffd0_menu
{
  public:
    Tile* FUN_00726070(int);
};

class FUN_0077ffd0_obj
{
  public:
    bool IsTraitNonZero();
    void FUN_00a011b0();
};

class FUN_0077ffd0_list
{
  public:
    void* FUN_00825c00(void*);
};

class FUN_0077ffd0_lbx
{
  public:
    virtual void vfn_00();
    virtual Tile* vfn_04(int);
};

void* __cdecl TraitNameToID(const char* s);
int __cdecl FUN_00ec62c0();

// @fnv 0x0077ffd0
void __cdecl UpdateCurrentValue()
{
    int tab;
    int idx;
    int res5;
    if (reinterpret_cast<FUN_0077ffd0_obj*>(
            reinterpret_cast<FUN_0077ffd0_menu*>(InventoryMenu::ms_pInventoryMenu)->FUN_00726070(DAT_011d9eb8))
            ->IsTraitNonZero())
    {
        tab = 5;
    }
    else
    {
        tab = InventoryMenu::ms_pInventoryMenu->m_iCurrentTab;
    }
    idx = tab;
    if (InventoryMenu::ms_pInventoryMenu->m_kItemList.vfn_04() != 0)
    {
        reinterpret_cast<FUN_0077ffd0_obj*>(
            reinterpret_cast<FUN_0077ffd0_lbx*>(&InventoryMenu::ms_pInventoryMenu->m_kItemList)->vfn_04(0xfac))
            ->FUN_00a011b0();
        res5 = FUN_00ec62c0();
    }
    else
    {
        res5 = -1;
    }
    InventoryMenu::ms_pInventoryMenu->m_kPageStates[idx].m_iSelectedItemIndex = res5;
    reinterpret_cast<FUN_0077ffd0_obj*>(
        reinterpret_cast<FUN_0077ffd0_list*>(&InventoryMenu::ms_pInventoryMenu->m_kItemList)
            ->FUN_00825c00(TraitNameToID("_current_value")))
        ->FUN_00a011b0();
    InventoryMenu::ms_pInventoryMenu->m_kPageStates[idx].m_iScrollOffset = FUN_00ec62c0();
}

struct InputInterface
{
    virtual int Reserved0();
    virtual int Reserved1();
    virtual int GetFirstValue(int index);
    virtual int Reserved3();
    virtual int Reserved4();
    virtual int Reserved5();
    virtual int Reserved6();
    virtual int GetSecondValue(int index);
};
extern char* DAT_011dea3c;
// Checks indices 25 through 30 of the input interface and returns true if any first value is less than its second value.
// @fnv 0x00780f70
bool __cdecl FUN_00780f70()
{
    for (int index = 25; index < 31; ++index)
    {
        if (((InputInterface*)(DAT_011dea3c + 0xa4))->GetFirstValue(index) <
            ((InputInterface*)(DAT_011dea3c + 0xa4))->GetSecondValue(index))
        {
            return true;
        }
    }
    return false;
}

namespace InventorySelection {
struct Item;
struct Form;
struct Tile
{
    float FUN_00a011b0();
    void FUN_00a01350(int, const char*, bool);
    void FUN_00700320(int, bool);
    const char* FUN_00a011f0(int);
    void FUN_00a012d0(int, float, bool);
    void FUN_00a07530(int);
};
struct TileRef
{
    Tile** FUN_0073ac90();
};
struct TileHolder
{
    unsigned int unk0;
    TileRef tile;
};
struct List
{
    virtual void slot0();
    virtual Tile* Value(int);
    Item* FUN_007a1910();
};
struct Entry
{
    bool FUN_00701740();
};
struct Form
{
    int FUN_00401170();
    void* GetUnk15C();
    int GetField1BC();
};
struct Item
{
    Form* FUN_0044ddc0();
    float FUN_004bcdb0(int);
    const char* GetIconFilename(int);
};
struct Player
{
    bool FUN_00967b70(Item*);
};
struct Setting
{
    float* FUN_00403e20();
    const char* FUN_00403df0();
};
struct Camera
{
    void FUN_007f8610(int, float, float, bool);
};
struct Interface
{
    Camera* FUN_00704370();
};
Interface* FUN_004b7210();
extern Setting DAT_011db2f0, DAT_011db358, DAT_011d3dcc, DAT_011d1f2c, DAT_011d33f0;
extern Setting* DAT_011d5168;
extern int DAT_011d9f34, DAT_011d9ebc;
extern Item* DAT_011d9ea8;
extern Player* DAT_011dea3c;
extern float DAT_0102f0f8, DAT_0101b268, DAT_01050280, DAT_01072e3c, DAT_01073af0, DAT_0104f754;
extern double DAT_01073ae8, DAT_01073ae0;
extern const char DAT_01020764[], DAT_0106eb24[], DAT_01073aac[];
void FUN_00707e30(Item*, Tile*);
const char* GetWeaponSkillIconPath(void*);
int FUN_00406d00(char*, unsigned int, const char*, ...);
int FUN_00408b20(const char*, const char*);
void FUN_00406d30(char*, unsigned int, const char*);
unsigned int FUN_0044a670(const char*);
void* FUN_00479430(Form*);
const char* GetMenuIconName(void*);
void FUN_00406d50(char*, unsigned int, const char*);
struct Menu
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
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
    TileHolder* icon;
    Tile* button;
    unsigned int unk44;
    Tile* label;
    unsigned int unk4c;
    unsigned int unk50;
    Tile* description;
    Tile* stats;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    Tile* ammoLabel;
    unsigned int unk7c;
    Tile* ammoCount;
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
    List list;
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
    Entry entry;
    Tile* FUN_00726070();
    void FUN_00781680();
    void ClearActionPointSource();
    void UpdateItemDisplay(int, Tile*);
};
// On action 29 refreshes the selected item's label, stats, description, ammo and icon; on action 30 resets the description and button text.
// @fnv 0x00780ff0
void Menu::UpdateItemDisplay(int action, Tile* changed)
{
    if (action == 29)
    {
        DAT_011d9ea8 = list.FUN_007a1910();
        if (DAT_011d9ea8)
        {
            int selectedSlot11 = (int)list.Value(0xfac)->FUN_00a011b0();
            if (DAT_011d9f34 != selectedSlot11)
            {
                FUN_004b7210()->FUN_00704370()->FUN_007f8610(
                    0, DAT_011d9f34 < selectedSlot11 ? *DAT_011db2f0.FUN_00403e20() : -*DAT_011db2f0.FUN_00403e20(),
                    *DAT_011db358.FUN_00403e20(), 1);
                DAT_011d9f34 = selectedSlot11;
            }
            float threshold = DAT_0102f0f8;
            if (DAT_011d9ea8->FUN_0044ddc0()->FUN_00401170() == 24)
                threshold = DAT_0101b268;
            if (DAT_011d9ea8->FUN_004bcdb0(1) >= threshold)
                label->FUN_00a01350(0xfc4, DAT_011d3dcc.FUN_00403df0(), 1);
            else
                label->FUN_00a01350(0xfc4, DAT_011d1f2c.FUN_00403df0(), 1);
            FUN_00707e30(DAT_011d9ea8, stats);
            stats->FUN_00700320(0xfa3, 1);
            FUN_00726070()->FUN_00700320(DAT_011d9ebc, DAT_011dea3c->FUN_00967b70(DAT_011d9ea8));
            description->FUN_00a01350(0xfcc, DAT_011d9ea8->GetIconFilename(0), 1);
            Form* ammo = 0;
            if (DAT_011d9ea8->FUN_0044ddc0()->FUN_00401170() == 40)
            {
                ammo = DAT_011d9ea8->FUN_0044ddc0();
                ammoLabel->FUN_00a01350(0xfcc, GetWeaponSkillIconPath(ammo->GetUnk15C()), 1);
                char countText[128];
                FUN_00406d00(countText, 128, DAT_01020764, ammo->GetField1BC());
                if (ammoCount)
                    ammoCount->FUN_00a01350(0xfc4, countText, 1);
            }
            if (!FUN_00408b20(description->FUN_00a011f0(0xfcc), DAT_011d33f0.FUN_00403df0()))
            {
                description->FUN_00a012d0(0xfa1, DAT_01050280, 1);
                description->FUN_00a012d0(0xfb1, DAT_01072e3c, 1);
                description->FUN_00a012d0(0xfb0, DAT_01072e3c, 1);
            }
            else if (DAT_011d9ea8->FUN_0044ddc0()->FUN_00401170() == 41)
            {
                float heightSlot1 = DAT_01073af0;
                float width = DAT_0104f754;
                description->FUN_00a012d0(0xfa1, heightSlot1 + DAT_01073ae8, 1);
                description->FUN_00a012d0(0xfb1, width + DAT_01073ae0, 1);
                description->FUN_00a012d0(0xfb0, width + DAT_01073ae0, 1);
            }
            else
            {
                description->FUN_00a012d0(0xfa1, DAT_01050280, 1);
                description->FUN_00a012d0(0xfb1, DAT_01072e3c, 1);
                description->FUN_00a012d0(0xfb0, DAT_01072e3c, 1);
            }
            description->FUN_00a07530(17);
            char path[260];
            FUN_00406d30(path, 260, DAT_0106eb24);
            unsigned int prefixLengthSlot0 = FUN_0044a670(path);
            FUN_00406d50(path, 260, GetMenuIconName(FUN_00479430(DAT_011d9ea8->FUN_0044ddc0())));
            if (FUN_0044a670(path) > prefixLengthSlot0)
            {
                (*icon->tile.FUN_0073ac90())->FUN_00a01350(0xfcc, path, 1);
                (*icon->tile.FUN_0073ac90())->FUN_00700320(0xfa3, 1);
            }
            else
                (*icon->tile.FUN_0073ac90())->FUN_00700320(0xfa3, 0);
            if (!entry.FUN_00701740())
                description->FUN_00700320(0xfa3, 1);
            FUN_00781680();
        }
    }
    else if (action == 30)
    {
        ClearActionPointSource();
        description->FUN_00a01350(0xfcc, DAT_01073aac, 1);
        if (!entry.FUN_00701740())
            description->FUN_00700320(0xfa3, 1);
        button->FUN_00a01350(0xfc4, DAT_011d5168->FUN_00403df0(), 1);
        button->FUN_00700320(0xfaf, 1);
    }
}
}

struct Form
{
    int FUN_00401170();
};
struct Extra
{
    bool FUN_00418ba0();
};
struct ExtraNode
{
    Extra** FUN_006815c0();
};
struct Entry
{
    ~Entry();
    Form* FUN_0044ddc0();
    float FUN_004bcdb0(bool);
    int FUN_00726070();
    ExtraNode* FUN_00559450();
    bool FUN_004bddd0(bool);
    void* FUN_004459e0(int);
};
struct EntryListNode
{
    Entry* item;
    EntryListNode* next;
    EntryListNode();
    ~EntryListNode();
    Entry** FUN_006815c0();
    EntryListNode* FUN_00726070();
    void FUN_0063f7b0();
};
struct Changes
{
    void FilterInventoryChanges(Form*, EntryListNode*);
};
Changes* __cdecl FUN_004bf220(void*);
extern void* player;
float __cdecl FUN_00476b20(float);
struct InventoryCheck
{
    bool FUN_00781860(Entry* entry);
};
// @fnv 0x00781860
bool InventoryCheck::FUN_00781860(Entry* entry)
{
    bool result5 = false;
    Form* form4 = entry ? entry->FUN_0044ddc0() : 0;
    if (entry && FUN_00476b20(entry->FUN_004bcdb0(true)) == 100.0)
        return result5;
    if (entry && form4 && (form4->FUN_00401170() == 40 || form4->FUN_00401170() == 24) &&
        entry->FUN_004bcdb0(true) < 100.0)
    {
        if (entry->FUN_00726070() > 1)
            result5 = true;
        else
        {
            EntryListNode list6;
            Changes* changes = FUN_004bf220(player);
            Extra* originalExtra = entry->FUN_00559450() ? *entry->FUN_00559450()->FUN_006815c0() : 0;
            EntryListNode* cleanup = &list6;
            changes->FilterInventoryChanges(form4, &list6);
            for (EntryListNode* node9 = &list6; node9 && *node9->FUN_006815c0(); node9 = node9->FUN_00726070())
            {
                Form* otherForm2 = (*node9->FUN_006815c0())->FUN_0044ddc0();
                Extra* otherExtra8 = (*node9->FUN_006815c0())->FUN_00559450()
                                         ? *(*node9->FUN_006815c0())->FUN_00559450()->FUN_006815c0()
                                         : 0;
                if (!(*node9->FUN_006815c0())->FUN_004bddd0(false))
                {
                    if (otherForm2 != form4 ||
                        (FUN_00476b20((*node9->FUN_006815c0())->FUN_004bcdb0(true)) < 100.0 &&
                         otherExtra8 != originalExtra && otherExtra8 && !otherExtra8->FUN_00418ba0()))
                        result5 = true;
                }
            }
            while (cleanup && *cleanup->FUN_006815c0())
            {
                delete *cleanup->FUN_006815c0();
                cleanup->FUN_0063f7b0();
            }
        }
    }
    return result5;
}

struct ItemLabelSource : InventoryStackRecord
{
    int FUN_00726070();
    unsigned char FUN_004bd820();
    const char* GetTargetFullName();
    bool FUN_004bddd0(bool);
};
class Actor;
class TESAmmo;
struct TESObjectWEAP
{
    TESAmmo* GetCurrentAmmo(Actor*);
};
struct ItemLabelPlayer
{
    bool FUN_00967b70(InventoryStackRecord*);
    TESObjectWEAP* FUN_008a1710();
};
struct ItemLabelChildren
{
    Tile** FUN_007b5370();
    void* FUN_00559450();
    Tile** AddEight(void*);
};
struct ItemLabelTile : Tile
{
    int tileHeader;
    ItemLabelChildren children;
};
int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);

// @fnv 0x00782850
void __cdecl UpdateItemLabel(ItemLabelTile* tile, ItemLabelSource* item)
{
    char label[128];
    if (item)
    {
        if (item->FUN_00726070() > 1)
        {
            if (item->FUN_004bd820())
                _sprintf_s(label, 128, "%s+ (%d)", item->GetTargetFullName(), item->FUN_00726070());
            else
                _sprintf_s(label, 128, "%s (%d)", item->GetTargetFullName(), item->FUN_00726070());
            tile->Set(0xfc4, label, true);
        }
        tile->Set(0xfaa, 29);
        if (item->FUN_0044ddc0()->GetFormType() == 41 || item->FUN_0044ddc0()->GetFormType() == 24 ||
            item->FUN_0044ddc0()->GetFormType() == 40)
        {
            if (!reinterpret_cast<ItemLabelPlayer*>(g_thePlayer)->FUN_00967b70(item))
                (*tile->children.FUN_007b5370())->Set(0xfa9, 127);
            else
                (*tile->children.FUN_007b5370())->Set(0xfa9, 255);
        }
        if (item->FUN_0044ddc0()->GetFormType() == 41 &&
            reinterpret_cast<ItemLabelPlayer*>(g_thePlayer)->FUN_008a1710())
        {
            (*tile->children.AddEight(tile->children.FUN_00559450()))
                ->Set(0xfa3,
                      static_cast<bool>(item && item->FUN_0044ddc0() ==
                                                    reinterpret_cast<TESBoundObject*>(
                                                        reinterpret_cast<ItemLabelPlayer*>(g_thePlayer)
                                                            ->FUN_008a1710()
                                                            ->GetCurrentAmmo(reinterpret_cast<Actor*>(g_thePlayer)))));
        }
        else
        {
            (*tile->children.AddEight(tile->children.FUN_00559450()))
                ->Set(0xfa3, item && item->FUN_004bddd0(false) ? 1 : 0);
        }
    }
}

// 0x00780d60  unit_65921382d98c.cpp  /MT /Od /Oy- /GS /EHsc /Gy
// thiscall, no stack args (ret): menu refresh/close path.
extern "C" void* DAT_011d9ea8;
extern "C" int DAT_011d9ebc;

void* __fastcall FUN_00559450(void* obj);
void __cdecl FUN_00782a90();
void __cdecl FUN_007832a0(void* tile, int index);

struct Sh006815c0
{
    void** FUN_006815c0();
};
struct Sh00726070
{
    void* FUN_00726070();
};
struct Sh00a01230
{
    bool IsTraitNonZero(int arg);
};
struct Sh007314c0
{
    char pad[0x64];
    void FUN_007314c0(void (*fn)(void*, int), int a, int b);
};
struct Sh005ae3d0
{
    void FUN_005ae3d0(void** pp);
};
struct Sh004bddd0
{
    bool FUN_004bddd0(bool arg);
};
struct Sh0088c650
{
    void EquipItem(void* a, int b, void* c, bool d, bool e, bool f);
};
struct Sh0088c790
{
    void UnequipItem(void* a, int b, void* c, bool d, bool e, bool f);
};

unsigned __cdecl FUN_0058db10(int arg);
unsigned __cdecl LookupFormByID(int arg);

class SettingString
{
  public:
    const char* GetString();
};
extern "C" SettingString DAT_011d2af0;

struct GpEmb75
{
    virtual int v0();
    virtual int v1();
    virtual int v2(int arg);
    virtual int v3();
    virtual int v4();
    virtual int v5();
    virtual int v6();
    virtual int v7(int arg);
};
struct Gp75
{
    char pad00[0xa4];
    GpEmb75 emb;
};

struct Menu75b
{
    char pad00[0xb8];
    Sh007314c0 lb;
    Sh005ae3d0 list;

    void FUN_00780d60();
};

// @fnv 0x00780d60
void Menu75b::FUN_00780d60()
{
    void* a = (void*)FUN_0044ddc0(DAT_011d9ea8);
    void* b = FUN_00559450(DAT_011d9ea8) ? (void*)*((Sh006815c0*)FUN_00559450(DAT_011d9ea8))->FUN_006815c0() : 0;

    if (((Sh00a01230*)((Sh00726070*)this)->FUN_00726070())->IsTraitNonZero(DAT_011d9ebc))
    {
        lb.FUN_007314c0(FUN_007832a0, 0, 0x7fffffff);
    }

    void* c = (void*)FUN_0044ddc0(DAT_011d9ea8);
    list.FUN_005ae3d0(&c);

    if ((FUN_0044ddc0(DAT_011d9ea8) == FUN_0058db10(0) || FUN_0044ddc0(DAT_011d9ea8) == LookupFormByID(0xccef2)) &&
        ((Gp75*)g_thePlayer)->emb.v2(0x10) == ((Gp75*)g_thePlayer)->emb.v7(0x10))
    {
        Interface::ShowMessage(DAT_011d2af0.GetString(), 0, 0, 0, 2.0f, false);
    }
    else if (FUN_0044ddc0(DAT_011d9ea8) == FUN_0058db10(0x15) && !FUN_00780f70())
    {
        Interface::ShowMessage(DAT_011d2af0.GetString(), 0, 0, 0, 2.0f, false);
    }
    else if (!((Sh004bddd0*)DAT_011d9ea8)->FUN_004bddd0(false))
    {
        ((Sh0088c650*)g_thePlayer)
            ->EquipItem(a, (int)((Sh00726070*)DAT_011d9ea8)->FUN_00726070(), b, false, false, true);
    }
    else
    {
        ((Sh0088c790*)g_thePlayer)
            ->UnequipItem(a, (int)((Sh00726070*)DAT_011d9ea8)->FUN_00726070(), b, false, false, true);
    }

done:
    FUN_00782a90();
}

namespace fnv_00780140 {
class VTTile
{
  public:
    bool IsTraitNonZero(int m_iValueId);
    void FUN_00700320(int m_iValueId, int iValue);
};

class VTForm
{
  public:
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
    virtual bool IsDeleted();  // +0x94
    int FUN_00401170();
};

struct VTPoint3
{
    float x, y, z;
};

struct VTItemData
{
    bool FUN_00418b10();
    bool FUN_00418ab0(int iFlag);
};
struct VTItemNode
{
    VTItemData** FUN_006815c0();
};

class VTTarget
{
  public:
    VTForm* FUN_0044ddc0();
    VTTile* FUN_00726070();
    VTItemNode* FUN_00559450();
    float FUN_004bcdb0(int iFlag);
    bool FUN_004bddd0(int iFlag);
};

class VTAction
{
  public:
    VTAction(VTForm* pkTargetNum, VTTile* pkTile);
    int unk00;
    int unk04;
    int unk08;
};

struct VTActionList
{
    void FUN_006ecd40();
};
struct VTWeaponInfo
{
    bool HasEffect();
};

class VTProcess
{
  public:
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
    virtual VTWeaponInfo* GetWeaponInfo(int iHand);  // +0x148
    virtual VTActionList* GetActionList(int iFlag);  // +0x14c
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void PerformAction(VTAction* pkAction);  // +0x168
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
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42c();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43c();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44c();
    virtual void v450();
    virtual void v454();
    virtual void v458();
    virtual void v45c();
    virtual void v460();
    virtual void v464();
    virtual void v468();
    virtual void v46c();
    virtual void v470();
    virtual void v474();
    virtual void v478();
    virtual void v47c();
    virtual void v480();
    virtual void v484();
    virtual void v488();
    virtual void v48c();
    virtual void v490();
    virtual void v494();
    virtual void v498();
    virtual void v49c();
    virtual void v4a0();
    virtual void v4a4();
    virtual void v4a8();
    virtual void v4ac();
    virtual void v4b0();
    virtual void v4b4();
    virtual void v4b8();
    virtual void v4bc();
    virtual void v4c0();
    virtual void v4c4();
    virtual void v4c8();
    virtual void v4cc();
    virtual void v4d0();
    virtual void v4d4();
    virtual void v4d8();
    virtual void v4dc();
    virtual void v4e0();
    virtual void v4e4();
    virtual void v4e8();
    virtual void v4ec();
    virtual void v4f0();
    virtual void v4f4();
    virtual void v4f8();
    virtual void v4fc();
    virtual void v500();
    virtual void v504();
    virtual void v508();
    virtual void v50c();
    virtual void v510();
    virtual void v514();
    virtual void v518();
    virtual void v51c();
    virtual void v520();
    virtual void v524();
    virtual void v528();
    virtual void v52c();
    virtual void v530();
    virtual void v534();
    virtual void v538();
    virtual void v53c();
    virtual void v540();
    virtual void v544();
    virtual void v548();
    virtual void v54c();
    virtual void v550();
    virtual void v554();
    virtual void v558();
    virtual void v55c();
    virtual void v560();
    virtual void v564();
    virtual void v568();
    virtual void v56c();
    virtual void v570();
    virtual void v574();
    virtual void v578();
    virtual void v57c();
    virtual void SetQueued(int iA, int iB, int iC);  // +0x580
};

struct VTWeapon
{
    bool GetByteAt384();
};
struct VTAnim;

class VTPlayer
{
  public:
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
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void ResetIdle();  // +0x3c4
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void PlayAttack(VTAnim* pkAnimOut, int iType, bool bLeft, int iFlag);  // +0x3ec
    void FUN_00950030();
    VTProcess* FUN_008d8520();
    VTWeapon* FUN_006044c0();
    VTAnim* FUN_008a1710();
    void PlayActorSound(VTForm* pkTargetNum, int iA, int iB);
    int FUN_008a7570();
    bool FUN_009337b0();
    bool FUN_009614b0(VTForm* pkTargetNum, VTPoint3* pkPos, int iA, int iB);
};

struct VTCombat
{
    void AddItemExtraData(VTForm* pkTargetNum, VTTile* pkTile, VTPlayer* pkPlayer, int iFlag, VTTarget* pkSource);
};

struct VTCallbackList
{
    void ApplyFilter(void (*pfnCallback)());
    void FUN_007314c0(void (*pfnCallback)(Tile*), int iA, int iB);
};
struct VTSelection
{
    bool FUN_00701740();
    void FUN_007019e0(VTTarget* pkTargetNum);
};
struct VTTargetList
{
    void FUN_005ae3d0(VTForm* const& pkTargetNum);
};

struct VTCamera
{
    void FUN_007fb150(float fA, float fB, float fC);
};
struct VTSubMenu
{
    void FUN_00718630(int m_uiSoundID, int iValue, int m_iPackageData);
};
class VTInterface
{
  public:
    int unk000[309];
    VTSubMenu m_kSubMenu;  // +0x4d4
    VTCamera* FUN_00704370();
    void SetByte13(unsigned char ucMode);
};

struct VTSetting
{
    float* FUN_00403e20();
    const char* FUN_00403df0();
};
struct VTCounter
{
    int* FUN_0043d4d0();
};

struct VTSoundHandle
{
    unsigned int m_uiID;
    unsigned int m_uiState;
    unsigned int m_uiValue1;
    ~VTSoundHandle();
    bool Play(bool bLoop);
};
class VTAudio
{
  public:
    static VTAudio* FUN_00453a70();
    VTSoundHandle FUN_00ad7550(const char* pcName, int iFlags);
};

class VTMenu
{
  public:
    int unk00[10];
    VTTile* m_apTiles[23];  // +0x28
    int m_iMode;            // +0x84
    int unk88[12];
    VTCallbackList m_kCallbackList;  // +0xb8
    int unkbc[11];
    VTSelection m_kSelection;  // +0xe8
    int unkec[12];
    VTTargetList m_kTargets;  // +0x11c

    VTTile* FUN_00726070();
    void ClearActionPointSource();
    void FUN_00780d60();
    void FUN_00780140(int m_uiSoundID, VTTile* pkTile);
};

extern VTTarget* DAT_011d9ea8;
extern int DAT_011d9eac;
extern int DAT_011d9ebc;
extern VTPoint3 DAT_011f426c;
extern VTSetting DAT_011db37c;
extern VTSetting DAT_011db458;
extern VTSetting DAT_011d47a4;
extern VTSetting DAT_011d22c8;
extern VTSetting DAT_011d43e4;
extern VTSetting DAT_011d31f8;
extern VTSetting DAT_011d3d30;
extern VTCounter DAT_011d2418;

void FUN_007800c0();
void FUN_00782470(int iFlag);
int FUN_0077ff80();
void FUN_00717280(int iMenu);
void FUN_007b7020(VTTarget* pkTargetNum);
VTCombat* FUN_004bf220(VTPlayer* pkPlayer);
void FUN_00784710(VTTarget* pkTargetNum, int iFlag);
bool FUN_004b71d0();
void FUN_00782a90();
void DispatchMessageToSink(const char* pcText, int iA, const char* pcIcon, const char* pcSound, float fTime, int iB);
void CreateQuantityMenu(VTTile* pkTile, void (*pfnCallback)(int), int iMax);
void FUN_00782620();
void UpdateItemLabel(Tile* pkTile);
void IsNotFormType2E();

// Dispatches by the integer argument, handling mode changes and menu actions including item, drop, and attack paths with state checks.
// @fnv 0x00780140
void VTMenu::FUN_00780140(int m_uiSoundID, VTTile* pkTile)
{
    if (!pkTile && m_uiSoundID >= 0 && m_uiSoundID < 0x17)
        pkTile = m_apTiles[m_uiSoundID];
    switch (m_uiSoundID)
    {
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
        if (m_iMode != m_uiSoundID - 0x18)
        {
            int iOldMode = m_iMode;
            if (FUN_00726070()->IsTraitNonZero(DAT_011d9eb8))
                FUN_00726070()->FUN_00700320(DAT_011d9eb8, 0);
            ClearActionPointSource();
            UpdateCurrentValue();
            m_iMode = m_uiSoundID - 0x18;
            m_apTiles[13]->FUN_00700320(DAT_011d9eac, m_iMode);
            ((VTInterface*)FUN_004b7210())
                ->FUN_00704370()
                ->FUN_007fb150(*DAT_011db458.FUN_00403e20(), *DAT_011db37c.FUN_00403e20(), 0.5f);
            ((VTInterface*)FUN_004b7210())->SetByte13(m_uiSoundID);
            m_kCallbackList.ApplyFilter(FUN_00782620);
            m_kCallbackList.FUN_007314c0(FUN_00780c00, -1, 0x7fffffff);
            FUN_007800c0();
            FUN_00782470(1);
        }
        if (m_uiSoundID == 0x18)
            m_apTiles[19]->FUN_00700320(0xfa3, 1);
        else if (m_uiSoundID == 0x1c)
        {
            ((VTInterface*)FUN_004b7210())->m_kSubMenu.FUN_00718630(0x24, FUN_0077ff80(), 0x1f4);
            ((VTMenu*)DAT_011d9ea4)->m_kCallbackList.FUN_007314c0(UpdateItemLabel, 0, 0x7fffffff);
        }
        else
        {
            if (m_uiSoundID == 0x19)
                ((VTInterface*)FUN_004b7210())->m_kSubMenu.FUN_00718630(0x23, FUN_0077ff80(), 0x200);
            m_apTiles[19]->FUN_00700320(0xfa3, 0);
            m_apTiles[20]->FUN_00700320(0xfa3, 0);
            m_apTiles[22]->FUN_00700320(0xfa3, 0);
        }
        break;
    case 8:
        if (DAT_011d9ea8)
        {
            FUN_00717280(0x24);
            UpdateCurrentValue();
            FUN_007b7020(DAT_011d9ea8);
        }
        break;
    case 19:
        if (DAT_011d9ea8 && DAT_011d9ea8->FUN_0044ddc0()->FUN_00401170() == 0x28)
        {
            FUN_00717280(0x24);
            UpdateCurrentValue();
            if (DAT_011d9ea8->FUN_00559450() && !*DAT_011d9ea8->FUN_00559450()->FUN_006815c0())
            {
                VTCombat* pkCombat = FUN_004bf220((VTPlayer*)DAT_011dea3c);
                pkCombat->AddItemExtraData(DAT_011d9ea8->FUN_0044ddc0(), DAT_011d9ea8->FUN_00726070(),
                                           (VTPlayer*)DAT_011dea3c, 0, DAT_011d9ea8);
            }
            FUN_00784710(DAT_011d9ea8, 1);
        }
        break;
    case 29:
        if (DAT_011d9ea8 && !FUN_00726070()->IsTraitNonZero(DAT_011d9eb8) &&
            DAT_011d9ea8->FUN_0044ddc0()->FUN_00401170() != 0x29)
        {
            bool bResume = false;
            if (m_kSelection.FUN_00701740())
            {
                if (!FUN_004b71d0())
                {
                    if (DAT_011d9ea8 && DAT_011d9ea8->FUN_004bcdb0(1) == 0.0)
                        DispatchMessageToSink(((VTSetting*)&DAT_011d3810)->FUN_00403df0(), 2, 0, "UIVATSInsufficientAP",
                                              2.0f, 0);
                    else if (!FUN_00726070()->IsTraitNonZero(DAT_011d9ebc) ||
                             DAT_011d9ea8->FUN_0044ddc0()->FUN_00401170() == 0x19)
                        DispatchMessageToSink(((VTSetting*)&DAT_011d1e18)->FUN_00403df0(), 2, 0, "UIVATSInsufficientAP",
                                              2.0f, 0);
                    else
                    {
                        m_kSelection.FUN_007019e0(DAT_011d9ea8);
                        m_kTargets.FUN_005ae3d0(DAT_011d9ea8->FUN_0044ddc0());
                        FUN_00782a90();
                    }
                }
            }
            else
            {
                FUN_00780d60();
                bResume = true;
            }
            if (bResume)
            {
                ((VTPlayer*)DAT_011dea3c)->FUN_00950030();
                ((VTPlayer*)DAT_011dea3c)->FUN_008d8520()->SetQueued(1, 0, 0);
                ((VTPlayer*)DAT_011dea3c)->ResetIdle();
            }
        }
        else if (DAT_011d9ea8->FUN_0044ddc0()->FUN_00401170() == 0x29)
        {
            VTForm* pkTargetNum = DAT_011d9ea8->FUN_0044ddc0();
            if (!pkTargetNum || !FUN_00726070()->IsTraitNonZero(DAT_011d9ebc))
                break;
            VTAction* pkAction = new VTAction(DAT_011d9ea8->FUN_0044ddc0(), DAT_011d9ea8->FUN_00726070());
            VTProcess* pkProcess = ((VTPlayer*)DAT_011dea3c)->FUN_008d8520();
            VTWeapon* pkWeaponOut = ((VTPlayer*)DAT_011dea3c)->FUN_006044c0();
            VTAnim* pkAnimOut = ((VTPlayer*)DAT_011dea3c)->FUN_008a1710();
            pkProcess->PerformAction(pkAction);
            pkProcess->GetActionList(0)->FUN_006ecd40();
            ((VTPlayer*)DAT_011dea3c)->PlayActorSound(DAT_011d9ea8->FUN_0044ddc0(), 1, 0);
            int iType = (pkWeaponOut && !pkWeaponOut->GetByteAt384()) ? 0 : 2;
            bool bLeft = pkProcess->GetWeaponInfo(2)->HasEffect();
            ((VTPlayer*)DAT_011dea3c)->PlayAttack(pkAnimOut, iType, bLeft, 0);
            m_kTargets.FUN_005ae3d0(DAT_011d9ea8->FUN_0044ddc0());
            FUN_00782a90();
        }
        break;
    case 30:
        if (!m_kSelection.FUN_00701740())
        {
            UpdateCurrentValue();
            FUN_00726070()->FUN_00700320(DAT_011d9eb8, 1);
            m_kCallbackList.ApplyFilter(IsNotFormType2E);
            m_kCallbackList.FUN_007314c0(FUN_00780c00, -1, 0x7fffffff);
            ClearActionPointSource();
            FUN_007800c0();
        }
        else
            DispatchMessageToSink(((VTSetting*)&DAT_011d1e18)->FUN_00403df0(), 0,
                                  "Interface\\Icons\\Message Icons\\glow_message_vaultboy_sad.dds",
                                  "UIVATSInsufficientAP", 2.0f, 0);
        break;
    case 10:
        UpdateCurrentValue();
        FUN_00726070()->FUN_00700320(DAT_011d9eb8, 0);
        m_kCallbackList.ApplyFilter(FUN_00782620);
        m_kCallbackList.FUN_007314c0(FUN_00780c00, -1, 0x7fffffff);
        FUN_007800c0();
        break;
    case 7:
        if (DAT_011d9ea8)
        {
            VTPoint3 kPos = DAT_011f426c;
            VTForm* pkRefOut = DAT_011d9ea8->FUN_0044ddc0();
            VTItemData* pkItem = DAT_011d9ea8->FUN_00559450() ? *DAT_011d9ea8->FUN_00559450()->FUN_006815c0() : 0;
            if (FUN_00726070()->IsTraitNonZero(DAT_011d9eb8))
                VTAudio::FUN_00453a70()->FUN_00ad7550("UIVATSInsufficientAP", 0x121).Play(false);
            else if (pkRefOut->IsDeleted())
                DispatchMessageToSink(DAT_011d47a4.FUN_00403df0(), 2, 0, 0, 2.0f, 0);
            else if (((VTPlayer*)DAT_011dea3c)->FUN_008a7570() != -1 && DAT_011d9ea8->FUN_004bddd0(0))
                DispatchMessageToSink(DAT_011d22c8.FUN_00403df0(), 2, 0, 0, 2.0f, 0);
            else if (((VTPlayer*)DAT_011dea3c)->FUN_009337b0())
                DispatchMessageToSink(DAT_011d43e4.FUN_00403df0(), 2, 0, 0, 2.0f, 0);
            else if (pkItem && pkItem->FUN_00418b10() && pkItem->FUN_00418ab0(0))
                DispatchMessageToSink(DAT_011d31f8.FUN_00403df0(), 2, 0, 0, 2.0f, 0);
            else if (!((VTPlayer*)DAT_011dea3c)->FUN_009614b0(pkRefOut, &kPos, 1, 1))
                DispatchMessageToSink(DAT_011d3d30.FUN_00403df0(), 2, 0, 0, 2.0f, 0);
            else
            {
                if ((int)DAT_011d9ea8->FUN_00726070() > *DAT_011d2418.FUN_0043d4d0())
                    CreateQuantityMenu(DAT_011d9ea8->FUN_00726070(), DropInventoryItem, 0x7fffffff);
                else
                    DropInventoryItem(1);
                ((VTPlayer*)DAT_011dea3c)->FUN_00950030();
                ((VTPlayer*)DAT_011dea3c)->FUN_008d8520()->SetQueued(1, 0, 0);
                ((VTPlayer*)DAT_011dea3c)->ResetIdle();
            }
        }
    }
}
}  // namespace fnv_00780140

struct FilterForm
{
    int FUN_00401170();
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4C();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5C();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6C();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7C();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8C();
    virtual void slot90();
    virtual bool IsQuestItem();
};
class TESBipedModelForm
{
  public:
    static TESBipedModelForm* GetFormAsBipedModel(TESForm*);
    bool FUN_00480d90();
};
bool __cdecl FUN_00481f10(FilterForm*);
struct FilterPlayer
{
    unsigned char GetByteAt240();
};
struct FilterList
{
    int GetConditionIndex(FilterForm*);
};
extern int DAT_010722f4;
FilterList* __cdecl FUN_00483a00(int*);

// Returns whether a form fails the current tab's checks, including type, item, and condition-index checks.
// @fnv 0x00782620
bool __cdecl FUN_00782620(Entry* entry)
{
    if (DAT_011d9ea4)
    {
        FilterForm* form4 = entry ? (FilterForm*)entry->FUN_0044ddc0() : 0;
        int tab3 = ((InventoryMenu*)DAT_011d9ea4)->m_iCurrentTab + 24;
        if (!form4)
            return tab3 != 27;
        int type = form4->FUN_00401170();
        TESBipedModelForm* biped3 = TESBipedModelForm::GetFormAsBipedModel((TESForm*)form4);
        if ((biped3 && !biped3->FUN_00480d90()) || FUN_00481f10(form4) ||
            (form4->IsQuestItem() && !((FilterPlayer*)DAT_011dea3c)->GetByteAt240()) || type == 46)
            return true;
        switch (tab3)
        {
        case 24:
            return type != 40;
        case 25:
            return type != 24 && type != 26;
        case 26:
            return type != 29 && type != 47 && type != 25;
        case 27:
            return type == 40 || type == 24 || type == 26 || type == 29 || type == 47 || type == 41 || type == 25;
        case 28:
            if (type != 41)
                return true;
            else
            {
                FilterList* list = FUN_00483a00(&DAT_010722f4);
                FilterForm* item = form4;
                if (list && list->GetConditionIndex(item) >= 0)
                    return true;
                return false;
            }
        }
    }
    return true;
}

struct FUN_0073ac90_shell
{
    Tile** __thiscall FUN_0073ac90();
};

// Clears the static action point source and resets several inventory menu tiles and a related tile to 0.
// @fnv 0x00781b10
void FUN_00781b10_shell::ClearActionPointSource()
{
    InventoryMenu::ms_pActionPointSource = 0;

    reinterpret_cast<InventoryMenu*>(this)->m_pTiles[12]->Set(0xFA3, 0);
    reinterpret_cast<InventoryMenu*>(this)->m_pTiles[11]->Set(0xFA3, 0.0f, false);
    reinterpret_cast<InventoryMenu*>(this)->m_pTiles[20]->Set(0xFA3, 0.0f, false);
    reinterpret_cast<InventoryMenu*>(this)->m_pTiles[22]->Set(0xFA3, 0);

    (*reinterpret_cast<FUN_0073ac90_shell*>(
          reinterpret_cast<char*>(*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x3C)) + 4)
          ->FUN_0073ac90())
        ->Set(0xFA3, 0);

    reinterpret_cast<FUN_00781680_shell*>(this)->FUN_00781680();
}
