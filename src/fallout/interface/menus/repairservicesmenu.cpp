
// src/fallout/interface/menus/repairservicesmenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/repairservicesmenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct RepairServicesMenu
{
    int FUN_007b74c0();
};

// @fnv 0x007b74c0
int RepairServicesMenu::FUN_007b74c0()
{
    return 0x422;
}

// @fnv 0x007b7890
int __cdecl FUN_007b7890()
{
    return 0x422;
}

struct FUN_007b78a0_shell
{
    int m[10];
    bool __thiscall FUN_007b78a0();
};

// Returns true only if all 16 entries following the first 10 ints in the object are non-zero; otherwise returns false.
// @fnv 0x007b78a0
bool __thiscall FUN_007b78a0_shell::FUN_007b78a0()
{
    for (int i = 0; i < 16; ++i)
    {
        if (m[10 + i] == 0)
            return false;
    }
    return true;
}

namespace fnv_007b8ae0 {
struct Tile
{
    void Set(int, int);
};

struct RepairServicesMenu
{
    void UpdateRepairServiceTiles(int aiID, Tile* apTarget);
};

// @fnv 0x007b8ae0
void RepairServicesMenu::UpdateRepairServiceTiles(int aiID, Tile* apTarget)
{
    if (aiID == 0x11)
    {
        reinterpret_cast<Tile*>(*(int*)((int)this + 0x5C))->Set(0xFAF, 1);
        reinterpret_cast<Tile*>(*(int*)((int)this + 0x34))->Set(0xFA3, 0);
        reinterpret_cast<Tile*>(*(int*)((int)this + 0x38))->Set(0xFA3, 0);
    }
}
}  // namespace fnv_007b8ae0

struct FUN_007b74d0_shell
{
    void __thiscall FUN_007b7500();
    void* __thiscall DestroyIfFlagged(unsigned int);
};
void __cdecl _Deallocate(void*);
// Calls FUN_007b7500, then deallocates this if flags has bit 1 set, and returns this.
// @fnv 0x007b74d0
void* __thiscall FUN_007b74d0_shell::DestroyIfFlagged(unsigned int flags)
{
    FUN_007b7500();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct Tile
{
    void Set(int, int);
};
struct Menu
{
    void LoadMenuData();
};
struct TESTopic
{
    static TESTopic* __cdecl GetAudioBackendData(int, int);
};
void __cdecl StartDialogueForTopic(TESTopic*);
struct DAT_holder
{
    int field0;
    Tile* tile;
};
extern DAT_holder* DAT_011da7f0;
// @fnv 0x007b78e0
void __cdecl FUN_007b78e0()
{
    StartDialogueForTopic(TESTopic::GetAudioBackendData(5, 5));
    DAT_011da7f0->tile->Set(0x1772, 1);
    ((Menu*)DAT_011da7f0)->LoadMenuData();
}

namespace fnv_007b82c0 {
struct Tile
{
    bool ContainsTrait(int);
};
struct RepairBatch
{
    void RepairAll(RepairBatch*);
};
extern int DAT_011da7dc;
extern int DAT_011da7f0;

// @fnv 0x007b82c0
void __cdecl FUN_007b82c0(Tile* pTile, RepairBatch* pItem)
{
    if (pTile->ContainsTrait(DAT_011da7dc))
        ((RepairBatch*)DAT_011da7f0)->RepairAll(pItem);
}
}  // namespace fnv_007b82c0

struct FUN_007308e0
{
    virtual ~FUN_007308e0();
};
struct Menu_007a8b10
{
    virtual ~Menu_007a8b10();
    int m[25];
};
struct FUN_007b7500 : Menu_007a8b10
{
    virtual ~FUN_007b7500();
    FUN_007308e0 t;
};
// Destructor that clears the global DAT_011da7f0 pointer to null.
// @fnv 0x007b7500
FUN_007b7500::~FUN_007b7500()
{
    DAT_011da7f0 = 0;
}

struct FUN_004bddd0_t
{
    bool __thiscall FUN_004bddd0(bool);
};

struct IC : FUN_004bddd0_t
{
    float __thiscall GetConditionPercent(bool);
};

struct InventoryStackRecord : IC
{
};

struct ListBoxItem
{
    Tile* m_pTile;
    InventoryStackRecord* m_pInventoryEntryData;
};

struct Tile_IsTrue_standin
{
    bool __thiscall ContainsTrait(int);
};

bool __thiscall Tile_IsTrue_standin::ContainsTrait(int)
{
    return false;
}

extern int DAT_011da7dc;

// @fnv 0x007b7c40
int __cdecl FUN_007b7c40(ListBoxItem* apItem1, ListBoxItem* apItem2)
{
    bool bisGreyedOut1;
    bool bisGreyedOut2;
    int iresult = 0;

    bisGreyedOut1 = !reinterpret_cast<Tile_IsTrue_standin*>(apItem1->m_pTile)->ContainsTrait(DAT_011da7dc);
    bisGreyedOut2 = !reinterpret_cast<Tile_IsTrue_standin*>(apItem2->m_pTile)->ContainsTrait(DAT_011da7dc);

    if (bisGreyedOut1 && !bisGreyedOut2)
    {
        iresult = 1;
    }
    else if (!bisGreyedOut1 && bisGreyedOut2)
    {
        iresult = -1;
    }
    else
    {
        if (apItem1->m_pInventoryEntryData->GetConditionPercent(false) <
            apItem2->m_pInventoryEntryData->GetConditionPercent(false))
        {
            iresult = 1;
        }
        else if (apItem1->m_pInventoryEntryData->GetConditionPercent(false) >
                 apItem2->m_pInventoryEntryData->GetConditionPercent(false))
        {
            iresult = -1;
        }
        else
        {
            if (apItem1->m_pInventoryEntryData->FUN_004bddd0(false))
            {
                iresult = -1;
            }
            else if (apItem2->m_pInventoryEntryData->FUN_004bddd0(false))
            {
                iresult = 1;
            }
        }
    }

    if (bisGreyedOut1 && bisGreyedOut2)
        iresult = -iresult;

    return iresult;
}

struct FUN_00a1c4a0 : Menu_007a8b10
{
    FUN_00a1c4a0();
};
struct FUN_00730810
{
    FUN_00730810();
    ~FUN_00730810();
};
extern char DAT_0106ed20;
extern char DAT_0106ed18;
extern char DAT_01075da0;
extern char DAT_01075d94;
extern int DAT_011da7e0;
extern int DAT_011da7e8;
extern int DAT_011da7e4;
extern int __cdecl TraitNameToID(const char*);
struct FUN_007b7400 : FUN_00a1c4a0
{
    FUN_00730810 inner;
    FUN_007b7400();
    virtual ~FUN_007b7400();
};
// Initializes four global values via TraitNameToID and sets the field at offset 0x98 of this object to zero.
// @fnv 0x007b7400
FUN_007b7400::FUN_007b7400()
{
    DAT_011da7e0 = TraitNameToID(&DAT_0106ed20);
    DAT_011da7e8 = TraitNameToID(&DAT_0106ed18);
    DAT_011da7e4 = TraitNameToID(&DAT_01075da0);
    DAT_011da7dc = TraitNameToID(&DAT_01075d94);
    *((int*)((char*)this + 0x98)) = 0;
}

struct Obj
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
    virtual bool v94();
    int FUN_00401170();
    double FUN_004be060();
    double FUN_004be180();
    bool FUN_00480d90();
};

struct Holder
{
    Obj* FUN_0044ddc0();
    double FUN_004bcdb0(int);
};

struct Cfg
{
    float* FUN_00403e20();
};

extern Cfg DAT_011d018c;
extern double DAT_01020758;
extern double DAT_01012060;

Obj* __cdecl FUN_00480db0(Obj*);
bool __cdecl FUN_00481f10(Obj*);
int __cdecl GetHealthForm(Obj*);

// Checks the holder's object and its state, comparing a value against config thresholds and returning whether the condition holds.
// @fnv 0x007b7b40
bool __cdecl FUN_007b7b40(Holder* pHolder)
{
    bool result2 = true;
    Obj* a7 = pHolder->FUN_0044ddc0();
    Obj* b = FUN_00480db0(a7);
    if (a7 == 0 || (b != 0 && !b->FUN_00480d90()) || FUN_00481f10(a7) || a7->v94())
    {
        result2 = true;
    }
    else
    {
        result2 =
            GetHealthForm(a7) == 0 || pHolder->FUN_004bcdb0(1) >= (double)*DAT_011d018c.FUN_00403e20() * DAT_01020758 ||
            (a7->FUN_00401170() == 0x18 && a7->FUN_004be060() <= DAT_01012060 && a7->FUN_004be180() <= DAT_01012060);
    }
    return result2;
}

class BSSoundHandleEx
{
  public:
    unsigned int id, state, flags;
    ~BSSoundHandleEx();
    bool Play(bool);
};
class BSAudio
{
  public:
    static BSAudio* GetSingleton();
    BSSoundHandleEx GetSoundHandleByEditorID(const char*, unsigned int);
};
struct RepairTile
{
    bool IsTraitNonZero(int);
    float FUN_00a011b0(int);
};
struct RepairList
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
    void* FUN_007a1910();
    void FUN_007314c0(bool(__cdecl*)(void*, void*), void*, int);
};
struct RepairPlayer
{
    void FUN_008924e0(void*, int);
};
extern RepairPlayer* DAT_011dea3c;
extern void* DAT_011da7f4;
extern int DAT_011da7e4;
extern char DAT_01075d38, DAT_01073a94;
bool __cdecl FUN_007b82c0(void*, void*);
struct RepairMenu
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
    RepairTile* tiles[16];
    RepairList items;
    int totalCost;
    void ApplyRepair(void*);
    void RefreshRepairMenu();
    void HandleRepairAction(int id, RepairTile* tile);
};
// @fnv 0x007b7d80
void RepairMenu::HandleRepairAction(int iActionId, RepairTile* tile)
{
    if (!tile && iActionId >= 0 && iActionId < 16)
        tile = tiles[iActionId];
    switch (iActionId)
    {
    case 17:
        if (tile->IsTraitNonZero(DAT_011da7dc))
        {
            ApplyRepair(items.FUN_007a1910());
            DAT_011dea3c->FUN_008924e0(DAT_011da7f4, (int)tile->FUN_00a011b0(DAT_011da7e4));
            BSAudio::GetSingleton()->GetSoundHandleByEditorID(&DAT_01075d38, 0x121).Play(false);
            RefreshRepairMenu();
        }
        else
        {
            BSAudio::GetSingleton()->GetSoundHandleByEditorID(&DAT_01073a94, 0x121).Play(false);
        }
        break;
    case 14:
        items.FUN_007314c0(FUN_007b82c0, 0, 0x7fffffff);
        DAT_011dea3c->FUN_008924e0(DAT_011da7f4, totalCost);
        BSAudio::GetSingleton()->GetSoundHandleByEditorID(&DAT_01075d38, 0x121).Play(false);
        RefreshRepairMenu();
        break;
    case 15:
        FUN_007b78e0();
        break;
    }
}

void __cdecl FUN_0040fbe0(const char* apMessage);
void __cdecl FNV_Warning(const char* apMessage);
int __cdecl FUN_00408b20(const char* apString1, const char* apString2);
float __cdecl FUN_00a01530();
void __cdecl FUN_00763ff0();

struct RSMTile
{
    RSMTile* ReadFile(const char* apPath);
    struct RSMMenu* GetMenu();
    RSMTile* GetChild(const char* apName);
    float GetFloat(int aiID);
    void SetFloat(int aiID, float afValue, bool abPropagate);
    void SetFloat(int aiID, float afValue);
    void SetString(int aiID, const char* apString, bool abPropagate);
};

struct RSMInterfaceManager
{
    static RSMInterfaceManager* __cdecl GetSingleton();
    RSMTile* GetMenuRoot();
};

struct RSMSetting
{
    const char* GetString();
};

struct RSMListBox
{
    void Initialize(RSMTile* apTemplate, const char* apName);
};

struct RSMExtraList
{
    int GetByType(int aiType);
};

struct RSMActor
{
    int unk00[0x29];
    RSMExtraList kExtraList;
};

struct RSMMenu
{
    virtual ~RSMMenu();
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
    RSMTile* pTile30;
    int unk34;
    int unk38;
    RSMTile* pTile3C;
    RSMTile* pTile40;
    int unk44;
    int unk48;
    int unk4C;
    RSMTile* pTile50;
    RSMTile* pTile54;
    int unk58;
    RSMTile* pTile5C;
    int unk60;
    RSMTile* pTile64;
    RSMListBox kRepairList;
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
    int iUnk9C;

    void SetTile(RSMTile* apTile, bool abFlag);
    bool FUN_007b78a0();
    void RefreshRepairMenu();
    void FUN_00a1dc20(int aiValue);
    int FUN_00726070();
};

int __cdecl FUN_007b7890();
RSMMenu* __cdecl FUN_00a09030(int aiMenuID);

extern RSMMenu* g_pRepairServicesMenu;
extern RSMActor* g_pRepairServicesVendor;
extern int g_iRepairServicesValue1;
extern int g_iRepairServicesValue2;
extern RSMSetting g_kLanguageSetting;
extern RSMSetting g_kHeadlineSetting;
extern RSMSetting g_kEmptyListSetting;
extern RSMSetting g_kCapsSetting;
extern RSMSetting g_kDescSetting1;
extern RSMSetting g_kDescSetting2;

// Loads the repair services menu XML, validates its ID, binds the vendor and repair list, and applies localized strings when the language is English.
// @fnv 0x007b7570
RSMTile* __cdecl CreateRepairServicesMenu(RSMActor* apVendor)
{
    RSMMenu* pOldMenu5;
    RSMTile* pTile;
    RSMInterfaceManager* pInterfaceMgr2;

    if (!apVendor)
    {
        FUN_0040fbe0(
            "Create() -- Missing vendor parameter.  4 bytes large, responds to the name 'Vendy'.  Please call if you see him!");
        return 0;
    }

    pInterfaceMgr2 = RSMInterfaceManager::GetSingleton();
    pOldMenu5 = FUN_00a09030(FUN_007b7890());
    if (pOldMenu5)
        delete pOldMenu5;

    pTile = pInterfaceMgr2->GetMenuRoot()->ReadFile("Data\\Menus\\repair_services_menu.xml");
    g_pRepairServicesMenu = pTile->GetMenu();
    if (g_pRepairServicesMenu && g_pRepairServicesMenu->GetID() == FUN_007b7890())
    {
        g_pRepairServicesMenu->SetTile(pTile, false);
        if (!g_pRepairServicesMenu->FUN_007b78a0())
        {
            FNV_Warning("MENUS: Repair Services Menu Creation Failed... Are your menu and art resources up to date?");
            return 0;
        }
        if (pTile->GetFloat(0xfa7) == 6006.0 || pTile->GetFloat(0xfa7) == 102.0)
            pTile->SetFloat(0xfad, FUN_00a01530(), true);
        g_pRepairServicesMenu->pTile40->SetFloat(g_iRepairServicesValue2, 1.0f);
        g_pRepairServicesMenu->pTile54->SetFloat(g_iRepairServicesValue2, 1.0f);
        g_pRepairServicesVendor = apVendor;
        g_pRepairServicesMenu->iUnk9C = apVendor->kExtraList.GetByType(0x27);
        g_pRepairServicesMenu->kRepairList.Initialize(g_pRepairServicesMenu->pTile30, "RSM_RepairListTemplate");
        g_pRepairServicesMenu->RefreshRepairMenu();
        FUN_00763ff0();
        if (FUN_00408b20(g_kLanguageSetting.GetString(), "ENGLISH"))
        {
            pTile->GetChild("RSM_Headline_Title")
                ->SetString(g_iRepairServicesValue1, g_kHeadlineSetting.GetString(), true);
            pTile->GetChild("RSM_EmptyRepairListText")
                ->SetString(g_iRepairServicesValue1, g_kEmptyListSetting.GetString(), true);
            g_pRepairServicesMenu->pTile3C->SetString(g_iRepairServicesValue1, g_kCapsSetting.GetString(), true);
            g_pRepairServicesMenu->pTile50->SetString(g_iRepairServicesValue1, g_kCapsSetting.GetString(), true);
            g_pRepairServicesMenu->pTile5C->SetString(0xfc4, g_kDescSetting1.GetString(), true);
            g_pRepairServicesMenu->pTile64->SetString(0xfc4, g_kDescSetting2.GetString(), true);
        }
        g_pRepairServicesMenu->FUN_00a1dc20(0);
        return pTile;
    }
    else if (g_pRepairServicesMenu && g_pRepairServicesMenu->FUN_00726070())
    {
        delete g_pRepairServicesMenu;
    }
    return 0;
}

struct RSItemForm;

struct RSItem
{
    RSItemForm* GetType();
    float GetConditionPercent(bool abPercent);
    bool FUN_004bddd0(bool abUnk);
};

struct RSTile;

struct RSTileList
{
    void* GetHeadPos();
    void* GetTailPos();
    RSTile*& GetAt(void* apPos);
};

struct RSTile
{
    int unk00;
    RSTileList kChildren;

    void SetInt(int aiID, int aiValue);
    void SetFloat(int aiID, float afValue, bool abPropagate);
    float GetFloat(int aiID);
    RSTile* GetComponent(int aiID);
};

struct RSRepairMenu
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int iTotalCost;
    int iSkill;
};

struct RSPlayer
{
    int GetCaps();
};

extern RSRepairMenu* g_pRSRepairMenu;
extern RSPlayer* g_pRSPlayer;
int __cdecl FUN_0048e8a0(RSItemForm* apForm);
int __cdecl GetLevelAdjustedMult(int aiSkill, float afHealth, float afValue);

// @fnv 0x007b7920
void __cdecl UpdateRepairMenuTile(RSTile* apTile, RSItem* apItem)
{
    if (!apTile || !apItem)
        return;

    int iCost = GetLevelAdjustedMult(g_pRSRepairMenu->iSkill, apItem->GetConditionPercent(true),
                                     FUN_0048e8a0(apItem->GetType()));
    float fAlpha4 = (iCost > 0 && iCost <= g_pRSPlayer->GetCaps()) ? 255.0f : 128.0f;
    apTile->SetInt(0xfaa, 0x11);
    apTile->SetInt(DAT_011da7e4, iCost);
    g_pRSRepairMenu->iTotalCost += iCost;
    apTile->kChildren.GetAt(apTile->kChildren.GetTailPos())->SetFloat(0xfa9, fAlpha4, true);
    apTile->GetComponent(0x12)->SetFloat(0xfa9, fAlpha4, true);
    apTile->kChildren.GetAt(apTile->kChildren.GetHeadPos())->SetFloat(0xfa9, fAlpha4, true);
    apTile->SetInt(0xfa3, apTile->GetFloat(0xfac) >= 0.0);
    apTile->GetComponent(0x12)->SetFloat(0xfb1, apItem->GetConditionPercent(true) * (double)0.6f, true);
    apTile->SetInt(DAT_011da7dc, fAlpha4 == 255.0);
    if (apItem->FUN_004bddd0(false))
        apTile->kChildren.GetAt(apTile->kChildren.GetHeadPos())->SetInt(0xfa3, 1);
}

struct RepairMenuView
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void Reset(int, int);
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    RepairTile* tiles[16];
    RepairList items;
    int totalCost;
    int displayedCost;
};
struct RepairListView
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void Sort(int(__cdecl*)(ListBoxItem*, ListBoxItem*));
    void PopulateInventoryList(RepairPlayer*, bool(__cdecl*)(Holder*), int, int, int, int);
    void FUN_007314c0(void(__cdecl*)(Tile*, void*), int, int);
};
struct RepairPlayerView
{
    int FUN_00891d70();
};
struct RepairSetting
{
    const char* FUN_00403df0();
    int* FUN_0043d4d0();
};
struct RepairStringTile
{
    void FUN_00a01350(int, const char*, bool);
};
extern RepairSetting DAT_011d3a08, DAT_011d25b0, DAT_011d4030, DAT_011d4780;
extern char DAT_01075f34, DAT_01070854;
void __cdecl UpdateRepairMenuTile(Tile*, void*);
int __cdecl FUN_00406d00(char*, int, const char*, ...);

// @fnv 0x007b8b30
void RepairMenu::RefreshRepairMenu()
{
    char szText[64];
    if (DAT_011da7f0)
    {
        ((RepairMenuView*)DAT_011da7f0)->totalCost = 0;
        ((RepairMenuView*)DAT_011da7f0)->Reset(17, 0);
        ((RepairListView*)&((RepairMenuView*)DAT_011da7f0)->items)
            ->PopulateInventoryList(DAT_011dea3c, FUN_007b7b40, 0, 0, 1, 0);
        ((RepairListView*)&((RepairMenuView*)DAT_011da7f0)->items)->FUN_007314c0(UpdateRepairMenuTile, -1, 0x7fffffff);
        ((RepairListView*)&((RepairMenuView*)DAT_011da7f0)->items)->Sort(FUN_007b7c40);
        if (((RepairPlayerView*)DAT_011dea3c)->FUN_00891d70() > *DAT_011d3a08.FUN_0043d4d0())
            FUN_00406d00(szText, 64, &DAT_01075f34, DAT_011d25b0.FUN_00403df0(), *DAT_011d3a08.FUN_0043d4d0());
        else
            FUN_00406d00(szText, 64, &DAT_01070854, DAT_011d25b0.FUN_00403df0(),
                         ((RepairPlayerView*)DAT_011dea3c)->FUN_00891d70());
        ((RepairStringTile*)tiles[1])->FUN_00a01350(0xfc4, szText, true);
        FUN_00406d00(szText, 64, &DAT_01070854, DAT_011d4030.FUN_00403df0(), ((RepairMenuView*)this)->displayedCost);
        ((RepairStringTile*)tiles[0])->FUN_00a01350(0xfc4, szText, true);
        FUN_00406d00(szText, 64, DAT_011d4780.FUN_00403df0(), ((RepairMenuView*)DAT_011da7f0)->totalCost);
        ((RepairStringTile*)((RepairMenuView*)DAT_011da7f0)->tiles[14])->FUN_00a01350(0xfc4, szText, true);
        ((Tile*)((RepairMenuView*)DAT_011da7f0)->tiles[14])
            ->Set(0xfaf,
                  ((RepairMenuView*)DAT_011da7f0)->totalCost > 0 &&
                      ((RepairMenuView*)DAT_011da7f0)->totalCost <= ((RepairPlayerView*)DAT_011dea3c)->FUN_00891d70());
    }
}

struct StatTile
{
    void Set(int, int);
    void Set(int, const char*, bool);
    void Set(int, float, bool);
    float FUN_00a011b0(int);
    bool IsTraitNonZero(int);
};
struct StatForm
{
    int FUN_00401170();
    double FUN_004be060();
    double FUN_004be180();
};
struct StatItem
{
    StatForm* FUN_0044ddc0();
    double FUN_004bcdb0(int);
    const char* GetIconFilename(int);
};
struct StatItemProvider
{
    StatItem* FUN_007a1910();
};
struct StatValue
{
    float value;
};
struct StatSetting
{
    const char* FUN_00403df0();
    StatValue* FUN_00403e20();
};
extern StatSetting DAT_011d2c7c, DAT_011d396c, DAT_011d20c4, DAT_011d0ff0, DAT_011d4ee8, DAT_011d3cf4;
float __cdecl GetWeaponDamage(StatForm*, float, StatItem*, int);
double __cdecl FUN_004bd510(float, float);
double __cdecl FUN_00646360(int, float);
float __cdecl FUN_0040ebd0(float, float);
float __cdecl FUN_00404010(float, float);
int __cdecl strcpy_s(char*, unsigned int, const char*);
int __cdecl strcat_s(char*, unsigned int, const char*);
int __cdecl sprintf_s(char*, unsigned int, const char*, ...);
struct StatMenu
{
    int field00;
    int field04;
    int field08;
    int field0c;
    int field10;
    int field14;
    int field18;
    int field1c;
    int field20;
    int field24;
    int field28;
    int field2c;
    int field30;
    StatTile* field34;
    StatTile* field38;
    StatTile* field3c;
    StatTile* field40;
    StatTile* field44;
    StatTile* field48;
    StatTile* field4c;
    StatTile* field50;
    StatTile* field54;
    StatTile* field58;
    StatTile* field5c;
    int field60;
    int field64;
    StatItemProvider field68;
    int field6c;
    int field70;
    int field74;
    int field78;
    int field7c;
    int field80;
    int field84;
    int field88;
    int field8c;
    int field90;
    int field94;
    int field98;
    int field9c;
    void UpdateItemComparison(int, StatTile*);
};
// @fnv 0x007b82f0
void StatMenu::UpdateItemComparison(int event, StatTile* tile)
{
    if (event == 17)
    {
        char text[64];
        StatItem* selectedItemTmp = field68.FUN_007a1910();
        float health2 = 0.0f;
        float projected6 = 0.0f;
        field5c->Set(0xfaf, (int)tile->IsTraitNonZero(DAT_011da7dc));
        field38->Set(0xfa3, 1);
        field34->Set(0xfcc, selectedItemTmp->GetIconFilename(0), true);
        field34->Set(0xfa3, 1);
        health2 = selectedItemTmp->FUN_004bcdb0(1) / 100.0;
        field3c->Set(0x1004, health2, true);
        if (selectedItemTmp->FUN_0044ddc0()->FUN_00401170() == 40)
        {
            field40->Set(DAT_011da7e0, DAT_011d2c7c.FUN_00403df0(), true);
            field40->Set(
                DAT_011da7e8,
                (int)FUN_004bd510(GetWeaponDamage(selectedItemTmp->FUN_0044ddc0(), health2, selectedItemTmp, 0), 1.0f));
        }
        else if (selectedItemTmp->FUN_0044ddc0()->FUN_00401170() == 24)
        {
            float armor3 = FUN_00646360((int)selectedItemTmp->FUN_0044ddc0()->FUN_004be060(), health2);
            float threshold0 = FUN_00646360((int)selectedItemTmp->FUN_0044ddc0()->FUN_004be180(), health2);
            if (threshold0 > 0.0)
            {
                ((StatMenu*)DAT_011da7f0)->field40->Set(DAT_011da7e0, DAT_011d396c.FUN_00403df0(), true);
                ((StatMenu*)DAT_011da7f0)->field40->Set(DAT_011da7e8, (int)threshold0);
            }
            else if (armor3 > 0.0)
            {
                ((StatMenu*)DAT_011da7f0)->field40->Set(DAT_011da7e0, DAT_011d20c4.FUN_00403df0(), true);
                ((StatMenu*)DAT_011da7f0)->field40->Set(DAT_011da7e8, (int)armor3);
            }
            else
            {
                char empty0[128];
                strcpy_s(empty0, 128, "--");
                ((StatMenu*)DAT_011da7f0)->field40->Set(DAT_011da7e0, DAT_011d20c4.FUN_00403df0(), true);
                ((StatMenu*)DAT_011da7f0)->field40->Set(DAT_011da7e8, empty0, true);
            }
        }
        projected6 = DAT_011d0ff0.FUN_00403e20()->value +
                     (((StatSetting&)DAT_011d018c).FUN_00403e20()->value - DAT_011d0ff0.FUN_00403e20()->value) *
                         (field9c / 100.0f);
        projected6 = FUN_0040ebd0(projected6 / 10.0, 1.0f);
        if (FUN_004bd510(projected6, 0.001f) <= FUN_004bd510(health2, 0.001f))
        {
            sprintf_s(text, 64, DAT_011d4ee8.FUN_00403df0(), projected6 * 100.0, "%");
            field4c->Set(0xfc4, text, true);
            field50->Set(0xfa3, 0);
        }
        else
        {
            field50->Set(0x1004, projected6, true);
            field50->Set(0xfa3, 1);
            if (selectedItemTmp->FUN_0044ddc0()->FUN_00401170() == 40)
            {
                field54->Set(DAT_011da7e0, DAT_011d2c7c.FUN_00403df0(), true);
                field54->Set(DAT_011da7e8, (int)FUN_004bd510(GetWeaponDamage(selectedItemTmp->FUN_0044ddc0(),
                                                                             projected6, selectedItemTmp, 0),
                                                             1.0f));
            }
            else if (selectedItemTmp->FUN_0044ddc0()->FUN_00401170() == 24)
            {
                float aThreshold1 = FUN_00646360((int)selectedItemTmp->FUN_0044ddc0()->FUN_004be060(), projected6);
                float armor6 = FUN_00646360((int)selectedItemTmp->FUN_0044ddc0()->FUN_004be180(), projected6);
                if (armor6 > 0.0)
                {
                    ((StatMenu*)DAT_011da7f0)->field54->Set(DAT_011da7e0, DAT_011d396c.FUN_00403df0(), true);
                    ((StatMenu*)DAT_011da7f0)->field54->Set(DAT_011da7e8, (int)armor6);
                }
                else if (aThreshold1 > 0.0)
                {
                    ((StatMenu*)DAT_011da7f0)->field54->Set(DAT_011da7e0, DAT_011d20c4.FUN_00403df0(), true);
                    ((StatMenu*)DAT_011da7f0)->field54->Set(DAT_011da7e8, (int)aThreshold1);
                }
                else
                {
                    char emptyTmp[128];
                    strcpy_s(emptyTmp, 128, "--");
                    ((StatMenu*)DAT_011da7f0)->field54->Set(DAT_011da7e0, DAT_011d20c4.FUN_00403df0(), true);
                    ((StatMenu*)DAT_011da7f0)->field54->Set(DAT_011da7e8, emptyTmp, true);
                }
            }
            float healthDelta_2 = (field50->FUN_00a011b0(0x1004) - field3c->FUN_00a011b0(0x1004)) * 100.0;
            float statDelta2 = field54->FUN_00a011b0(DAT_011da7e8) - field40->FUN_00a011b0(DAT_011da7e8);
            healthDelta_2 = FUN_00404010(0.0f, healthDelta_2);
            statDelta2 = FUN_00404010(0.0f, statDelta2);
            sprintf_s(text, 64, "+%i", (int)(healthDelta_2 + 0.5));
            strcat_s(text, 64, "%");
            field44->Set(0xfc4, text, true);
            sprintf_s(text, 64, "+%i", (int)(statDelta2 + 0.5));
            field48->Set(0xfc4, text, true);
            sprintf_s(text, 64, DAT_011d3cf4.FUN_00403df0(), (int)tile->FUN_00a011b0(DAT_011da7e4));
            field58->Set(0xfc4, text, true);
            field58->Set(0xfa9, tile->IsTraitNonZero(DAT_011da7dc) ? 255.0f : 128.0f, true);
        }
    }
}

float __cdecl FUN_0040ebd0(float afValue, float afMin);
unsigned int __cdecl FUN_004873d0(class TESBoundObject* apObject);

class TESBoundObject
{
  public:
    virtual ~TESBoundObject();
    int FNV_FUN_0044ddc0Type();
};

class TESObjectWEAP : public TESBoundObject
{
  public:
    int GetModdedValue(bool abFlag);
};

class ExtraDataList
{
  public:
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;

    ExtraDataList();
    virtual ~ExtraDataList();
    short GetCount();
    void CopyFrom(ExtraDataList* apSource);
    void SetCount(int aiCount);
    void SetExtraHealth(float afHealth);
    bool FUN_004126c0(ExtraDataList* apOther, int aiUnk1, int aiUnk2);
    void FUN_00419f80(int aiUnk);
};

struct ExtraListNode
{
    ExtraDataList** GetItem();
    ExtraListNode* GetNext();
    void AddHead(ExtraDataList* const& apItem);
    void Remove(ExtraDataList* const& apItem);
};

struct RepairEntry
{
    TESBoundObject* FUN_0044ddc0();
    bool HasEffect(int aiValue);
    ExtraListNode* GetExtraLists();
    void* FUN_004bde40();
};

struct RepairInventory
{
    static RepairInventory* __cdecl GetOrAddInventoryChanges(void* apRef);
    RepairEntry* FUN_004bfba0(TESBoundObject* apForm, int aiUnk1, int aiUnk2);
};

class RepairMenuData
{
  public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    int unk80, unk84, unk88, unk8C, unk90, unk94, unk98;
    int iRepairSkill;

    void ApplyRepair(RepairEntry* apEntry);
};

// Computes a repair value from iRepairSkill and the entry's form, then merges or replaces the extra health extra data in the player's inventory changes.
// @fnv 0x007b7f70
void RepairMenuData::ApplyRepair(RepairEntry* apEntry)
{
    TESObjectWEAP* pWeapon;
    RepairEntry* pPlayerEntry;
    ExtraDataList* pNewList4;
    bool bMergedTmp;
    ExtraDataList* pOldListOut;
    ExtraListNode* pNodeOut;
    int iCount8;

    float fHealthPercent = 0.0f;
    fHealthPercent = DAT_011d0ff0.FUN_00403e20()->value +
              (*DAT_011d018c.FUN_00403e20() - DAT_011d0ff0.FUN_00403e20()->value) * (iRepairSkill / 100.0f);
    fHealthPercent = FUN_0040ebd0(fHealthPercent / 10.0, 1.0f);
    pWeapon = dynamic_cast<TESObjectWEAP*>(apEntry->FUN_0044ddc0());
    if (pWeapon)
        fHealthPercent *= pWeapon->GetModdedValue(apEntry->HasEffect(10));
    else
        fHealthPercent *= FUN_004873d0(apEntry->FUN_0044ddc0());
    pPlayerEntry = RepairInventory::GetOrAddInventoryChanges(DAT_011dea3c)->FUN_004bfba0(apEntry->FUN_0044ddc0(), 1, 0);
    pOldListOut = apEntry->GetExtraLists() ? *apEntry->GetExtraLists()->GetItem() : 0;
    pNewList4 = new ExtraDataList;
    iCount8 = -1;
    bMergedTmp = false;
    iCount8 = pOldListOut->GetCount();
    pNewList4->CopyFrom(pOldListOut);
    pNewList4->SetCount(1);
    pNewList4->SetExtraHealth(fHealthPercent);
    if (iCount8 > 1)
        pOldListOut->SetCount(iCount8 - 1);
    for (pNodeOut = pPlayerEntry->GetExtraLists(); pNodeOut && *pNodeOut->GetItem(); pNodeOut = pNodeOut->GetNext())
    {
        if (apEntry->FUN_0044ddc0()->FNV_FUN_0044ddc0Type() == 0x18 && apEntry->FUN_004bde40())
            break;
        if (!(*pNodeOut->GetItem())->FUN_004126c0(pNewList4, 1, 0) &&
            !pNewList4->FUN_004126c0(*pNodeOut->GetItem(), 1, 0))
        {
            (*pNodeOut->GetItem())->SetCount((*pNodeOut->GetItem())->GetCount() + 1);
            bMergedTmp = true;
        }
    }
    if (!bMergedTmp)
    {
        if (iCount8 > 1)
            pPlayerEntry->GetExtraLists()->AddHead(pNewList4);
        else
            pOldListOut->SetExtraHealth(fHealthPercent);
    }
    else if (iCount8 == 1)
        pPlayerEntry->GetExtraLists()->Remove(pOldListOut);
    if (bMergedTmp || iCount8 == 1)
    {
        pNewList4->FUN_00419f80(0);
        delete pNewList4;
    }
}
