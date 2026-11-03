// fallout/interface/menus/repairmenu.cpp: RepairMenu, RepairAction, PreviewMenu (18 functions)

#include "repairmenu_packet.h"
static const int kGetClassValue = 1035;
// @fnv 0x007b54b0
int RepairMenu::GetClass()
{
    return kGetClassValue;
}
// Applies the accumulated movement offset to the menu's X/Y tile values and resets movement to zero.
// @fnv 0x0077f700
void RepairMenu::UpdateRepairList()
{
    static float baseX = ((TileListBoxCalls*)pMenu)->GetFloat(4001);
    static float baseY = ((TileListBoxCalls*)pMenu)->GetFloat(4002);
    float x = 0.0f;
    float y = 0.0f;
    if (movement > 0.0)
    {
        DAT_011d9e91 = true;
        FUN_004169a0(FUN_004a4240(), x, y);
        x *= movement;
        y *= movement;
    }
    if (DAT_011d9e91)
    {
        pMenu->Set(4001, baseX + x, true);
        pMenu->Set(4002, baseY + y, true);
    }
    if (movement == 0.0)
        DAT_011d9e91 = false;
    movement = 0.0f;
}
// Loads repair_menu.xml, stores the resulting RepairMenu, initializes its list and tiles, and returns the tile or null on failure.
// @fnv 0x007b5520
Tile* RepairMenu::Create()
{
    Menu* pExistingMenu;
    Tile* pTile;
    InterfaceManager* pInterface;
    pInterface = FUN_004b7210();
    pExistingMenu = Tile::FindMenuById(FUN_007b5720());
    if (pExistingMenu)
        delete pExistingMenu;
    pTile = pInterface->FUN_00586150()->ReadFile("Data\\Menus\\repair_menu.xml");
    DAT_011da75c = (RepairMenu*)pTile->GetMenu();
    if (DAT_011da75c && DAT_011da75c->GetID() == FUN_007b5720())
    {
        DAT_011da75c->SetTileMenu((TileMenu*)pTile, false);
        ((InventoryMenu*)DAT_011da75c)->FUN_00867a20();
        if (!DAT_011da75c->FUN_007b5730())
        {
            Warning("MENUS: Repair Menu Creation Failed... Are your menu and art resources up to date?");
            return 0;
        }
        if (((TileListBoxCalls*)pTile)->GetFloat(4007) == 6006.0 || ((TileListBoxCalls*)pTile)->GetFloat(4007) == 102.0)
            pTile->Set(4013, Tile::GetInterfaceScale(), true);
        DAT_011da75c->m_kRepairList.Initialize(DAT_011da75c->m_pTiles[1], "RM_RepairListTemplate");
        DAT_011da75c->m_kRepairList.FUN_007a1930(false);
        DAT_011da75c->m_pTiles[5]->SetTraitFloat(DAT_011da754, 1.0f);
        DAT_011da75c->m_pTiles[10]->SetTraitFloat(DAT_011da754, 1.0f);
        DAT_011da75c->SetMenuVisibility(true);
        return pTile;
    }
    else
    {
        if (DAT_011da75c && ((BSSimpleList<BGSPerkEntry*>*)DAT_011da75c)->GetNext())
            delete DAT_011da75c;
    }
    return 0;
}

struct FUN_007b5730_shell : public RepairMenu
{
    bool FUN_007b5730();
};

// Checks the 13 entries at offset 0x28 and returns true only if none of them is zero.
// @fnv 0x007b5730
bool FUN_007b5730_shell::FUN_007b5730()
{
    for (int iIndex = 0; iIndex < 13; ++iIndex)
    {
        if (((int*)((char*)this + 0x28))[iIndex] == 0)
            return false;
    }
    return true;
}

// @fnv 0x007b5720
int FUN_007b5720()
{
    return 0x40b;
}

struct Host007b54f0
{
    void FUN_007b5770();
    void* DestroyIfFlagged(unsigned int);
};
void _Deallocate(void*);
// Calls FUN_007b5770, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x007b54f0
void* Host007b54f0::DestroyIfFlagged(unsigned int flags)
{
    FUN_007b5770();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct Tile_Set_Helper
{
    void Set(int, int);
};
struct Box071ae60
{
    unsigned int FUN_0071ae60();
};
struct Standin007b6a00
{
    char _00[0x48];
    Tile_Set_Helper* _48;
    Tile_Set_Helper* _4c;
    char _50[0x0C];
    Box071ae60 _5c;
    void FUN_007b6a00(int aiID, Tile* apTarget);
};
// For ID 14, clears tile 0xFA3 on _4c and, when _5c.FUN_0071ae60() returns more than 1, also clears it on _48.
// @fnv 0x007b6a00
void Standin007b6a00::FUN_007b6a00(int aiID, Tile* apTarget)
{
    if (aiID == 14)
    {
        _4c->Set(0xFA3, 0);
        if (_5c.FUN_0071ae60() > 1)
        {
            _48->Set(0xFA3, 0);
        }
    }
}

struct Interface
{
    static void __cdecl PlayUISound(int);
};
struct FUN_007b6a50_Host
{
    virtual void Vf0() = 0;
    virtual void Vf1() = 0;
    virtual void Vf2() = 0;
    virtual void Vf3(int, int) = 0;
    bool HandleButton(int aiButton, float afValue);
};
// @fnv 0x007b6a50
bool FUN_007b6a50_Host::HandleButton(int aiButton, float afValue)
{
    bool bhandled = false;
    switch (aiButton)
    {
    case 6:
    case 10:
        Interface::PlayUISound(3);
        this->Vf3(12, 0);
        break;
    }
    return bhandled;
}

struct FUN_007308e0
{
    virtual ~FUN_007308e0();
};
struct TileRemoveFade
{
    void UpdateTrait(int);
};
struct Menu_007a8b10
{
    virtual ~Menu_007a8b10();
};
struct FUN_007b5770 : public Menu_007a8b10
{
    char pad2[0x44];
    Tile* tile;
    char pad3[0x10];
    FUN_007308e0 helper;
    virtual ~FUN_007b5770();
};
// Removes the tile via TileRemoveFade with id 0xfa9 and clears DAT_011da75c.
// @fnv 0x007b5770
FUN_007b5770::~FUN_007b5770()
{
    ((TileRemoveFade*)tile)->UpdateTrait(0xfa9);
    DAT_011da75c = 0;
}

struct HealthOwner
{
    float GetHealthPercent(bool abAdjusted);
    bool IsEquipped(bool abCheck);
};

struct ChildTile;
struct ChildTileList
{
    void* GetHeadPos() const;
    ChildTile*& GetAtPos(void* apPos) const;
};

struct ChildTile
{
    void SetInt(int aiID, int aiValue);
};

struct RepairTile
{
    int unk00;
    ChildTileList children;
    void SetInt(int aiID, int aiValue);
    float GetValueFloat(int aiID);
    RepairTile* GetChildById(int aiID);
    void SetFloat(int aiID, float afValue, bool abPropagate);
};

struct SkillOwner
{
    void* GetSkill(int aiActorValue);
};

struct PlayerStub
{
    char unk00;
    char unk01;
    char unk02;
    char unk03;
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
    SkillOwner skills;
};

float ComputeRepairAmount(void* apSkill, float afSourceHealth, float afTargetHealth, int* apOut);
float FUN_0040ebd0(float a, float b);

extern HealthOwner* DAT_011da760;
extern PlayerStub* g_thePlayer;

// @fnv 0x007b57f0
void UpdateRepairTile(RepairTile* apTile, HealthOwner* apItem)
{
    if (!apTile || !apItem)
        return;

    float fHealthPercent = apItem->GetHealthPercent(true);
    apTile->SetInt(0xfaa, 0xe);
    apTile->SetInt(0xfa3, apTile->GetValueFloat(0xfac) >= 0.0);
    apTile->GetChildById(0xf)->SetFloat(0xfb1, fHealthPercent * 0.6f, true);
    if (apItem->IsEquipped(false))
        apTile->children.GetAtPos(apTile->children.GetHeadPos())->SetInt(0xfa3, 1);

    float fRepairHealth = DAT_011da760->GetHealthPercent(true);
    float fResult = 0.0f;
    int iOut = -1;
    fResult = ComputeRepairAmount(g_thePlayer->skills.GetSkill(0x27), fRepairHealth, fHealthPercent, &iOut) / 100.0;
    fResult = FUN_0040ebd0(fResult, 1.0f);
    apTile->SetFloat(0x1004, fResult, true);
}

struct FUN_007b6970_tile
{
    void SetString(int, const char*, bool);
    void Set(int, int);
    bool FUN_00a07ed0(int);
    void StartFade(int, float, float, float, bool);
};
struct FUN_007b6970_shell : public RepairMenu
{
    void SetRepairMenuText(const char* apText);
};

// @fnv 0x007b6970
void FUN_007b6970_shell::SetRepairMenuText(const char* apText)
{
    ((FUN_007b6970_tile*)m_pTiles[8])->SetString(4036, apText, true);
    ((FUN_007b6970_tile*)m_pTiles[9])->Set(4003, 0);
    ((FUN_007b6970_tile*)m_pTiles[8])->Set(4003, 1);
    if (!((FUN_007b6970_tile*)m_pTiles[8])->FUN_00a07ed0(4009))
    {
        ((FUN_007b6970_tile*)m_pTiles[8])->StartFade(4009, 255.0f, 64.0f, 2.0f, true);
    }
}

namespace fnv_007b6fb0 {
class RepairMenu;

extern RepairMenu* DAT_011da75c;
extern int DAT_011da760;

class RmMenu
{
  public:
    virtual ~RmMenu();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14(int, int);
};

class RmSub
{
  public:
    virtual ~RmSub();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
};

class RmTile
{
  public:
    void CallA(int);
    void CallB(int, int);
};

struct RmView
{
    RmMenu m_fMinimumV;
    char m_gap04[0x48 - 0x04];
    RmTile* m_p48;
    char m_gap4c[0x5c - 0x4c];
    RmSub m_sub;
};

// @fnv 0x007b6fb0
void ResetRepairMenu()
{
    ((RmView*)DAT_011da75c)->m_sub.vf1c();
    DAT_011da760 = 0;
    ((RmView*)DAT_011da75c)->m_fMinimumV.vf14(0xe, 0);
    ((RmView*)DAT_011da75c)->m_p48->CallA(0xfa9);
    ((RmView*)DAT_011da75c)->m_p48->CallB(0xfa3, 0);
}
}  // namespace fnv_007b6fb0

namespace fnv_007b7020 {
struct RepairInventory
{
    float FUN_004bcdb0(int mode);
    struct RepairForm* FUN_0044ddc0();
    int GetIconFilename(int mode, int active);
};
struct RepairForm
{
    int FUN_00401170();
    float FUN_004be060();
    float FUN_004be180();
};
struct RepairTile
{
    void FUN_00a012d0(int id, float value, int flag);
    void FUN_00700320(int id, int value);
    void FUN_00a01350(int id, const char* text);
    void FUN_00a01350(int id, const char* text, int flag);
    void FUN_00a01350(int id, int value);
};
struct RepairString
{
    const char* FUN_00403df0(int);
};
struct RepairList
{
    virtual void vf00();
    virtual int vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual int vf14(int, int, int, int);
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20(void(__cdecl*)());
    void FUN_007314c0(void(__cdecl*)(), int, int);
};
struct RepairMenuVirtual
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10(int, int);
};
struct RepairHud
{
    int FUN_0066ef20(int);
};
struct RepairManager
{
    void FUN_00715860();
    void FUN_00718630();
};
extern RepairInventory* DAT_011da760;
extern int DAT_011da74c;
extern RepairString DAT_011d2c7c;
extern RepairString DAT_011d396c;
extern RepairString DAT_011d20c4;
extern RepairHud* DAT_011dea3c;
extern const double DAT_01017a40;
extern const double DAT_01012060;
extern const char DAT_01047008[];
extern float __cdecl GetWeaponDamage(RepairForm*, float, int, int);
extern float __cdecl FUN_004bd510(float, float);
extern float __cdecl FUN_00646360(int, float);
extern void __cdecl FUN_00406d30(char*, int, const char*);
extern void __cdecl UpdateRepairTile();
extern void __cdecl CompareSortEntries();
extern void __cdecl PopulateRepairMenu();
extern bool __cdecl FUN_004b71d0();
extern void __cdecl FUN_007044c0(int, int, int);
extern InterfaceManager* __stdcall FUN_004b7210(int);
extern InterfaceManager* __stdcall FUN_004b7210(int, int);
extern int __stdcall FUN_007b5720(int);

// @fnv 0x007b7020
void __cdecl FUN_007b7020(int target)
{
    if (DAT_011da75c != 0)
    {
        if (target != 0)
        {
            DAT_011da760 = reinterpret_cast<RepairInventory*>(target);
        }
        float percent = DAT_011da760->FUN_004bcdb0(1) / DAT_01017a40;
        reinterpret_cast<RepairTile*>(DAT_011da75c->m_pTiles[4])->FUN_00a012d0(0x1004, percent, 1);
        reinterpret_cast<RepairTile*>(DAT_011da75c->m_pTiles[4])->FUN_00700320(0xfa3, 1);
        RepairForm* form = DAT_011da760->FUN_0044ddc0();
        int type = form->FUN_00401170();
        if (type == 0x28)
        {
            reinterpret_cast<RepairTile*>(DAT_011da75c->m_pTiles[5])
                ->FUN_00a01350(DAT_011da74c, DAT_011d2c7c.FUN_00403df0(1));
            reinterpret_cast<RepairTile*>(DAT_011da75c->m_pTiles[5])
                ->FUN_00700320(DAT_011da754, (int)FUN_004bd510(GetWeaponDamage(form, percent, target, 0), 1.0f));
        }
        else if (type == 0x18)
        {
            RepairForm* branchForm = form;
            float low = FUN_00646360((int)branchForm->FUN_004be060(), percent);
            float maximum = FUN_00646360((int)branchForm->FUN_004be180(), percent);
            if (maximum > DAT_01012060)
            {
                reinterpret_cast<RepairTile*>(DAT_011da75c->m_pTiles[5])
                    ->FUN_00a01350(DAT_011da74c, DAT_011d396c.FUN_00403df0(1));
                reinterpret_cast<RepairTile*>(DAT_011da75c->m_pTiles[5])->FUN_00700320(DAT_011da754, (int)maximum);
            }
            else if (low > DAT_01012060)
            {
                reinterpret_cast<RepairTile*>(DAT_011da75c->m_pTiles[5])
                    ->FUN_00a01350(DAT_011da74c, DAT_011d20c4.FUN_00403df0(1));
                reinterpret_cast<RepairTile*>(DAT_011da75c->m_pTiles[5])->FUN_00700320(DAT_011da754, (int)low);
            }
            else
            {
                char unavailableText[128];
                FUN_00406d30(unavailableText, 128, DAT_01047008);
                reinterpret_cast<RepairTile*>(DAT_011da75c->m_pTiles[5])
                    ->FUN_00a01350(DAT_011da74c, DAT_011d20c4.FUN_00403df0(1));
                reinterpret_cast<RepairTile*>(DAT_011da75c->m_pTiles[5])
                    ->FUN_00a01350(DAT_011da754, unavailableText, 1);
            }
        }
        else
        {
            char unavailableText[128];
            FUN_00406d30(unavailableText, 128, DAT_01047008);
            reinterpret_cast<RepairTile*>(DAT_011da75c->m_pTiles[5])
                ->FUN_00a01350(DAT_011da74c, DAT_011d20c4.FUN_00403df0(1));
            reinterpret_cast<RepairTile*>(DAT_011da75c->m_pTiles[5])->FUN_00a01350(DAT_011da754, unavailableText, 1);
        }

        if (target != 0)
        {
            reinterpret_cast<RepairTile*>(DAT_011da75c->m_pTiles[3])
                ->FUN_00a01350(0xfcc, DAT_011da760->GetIconFilename(0, 1));
            PopulateRepairMenu();
        }
        reinterpret_cast<RepairList*>(&DAT_011da75c->m_kRepairList)->FUN_007314c0(&UpdateRepairTile, 0, 0x7fffffff);
        reinterpret_cast<RepairList*>(&DAT_011da75c->m_kRepairList)->vf20(&CompareSortEntries);
        reinterpret_cast<RepairTile*>(DAT_011da75c->m_pTiles[0])
            ->FUN_00700320(
                DAT_011da754,
                reinterpret_cast<RepairHud*>(reinterpret_cast<char*>(DAT_011dea3c) + 0xa4)->FUN_0066ef20(0x27));
        if (target && FUN_004b71d0())
        {
            reinterpret_cast<RepairManager*>(
                FUN_004b7210(reinterpret_cast<RepairList*>(&DAT_011da75c->m_kRepairList)->vf14(1, 0, 0xfc3, 1)))
                ->FUN_00715860();
        }
        reinterpret_cast<RepairMenuVirtual*>(DAT_011da75c)
            ->vf10(0xe, reinterpret_cast<RepairList*>(&DAT_011da75c->m_kRepairList)->vf04());
        if (target != 0)
        {
            FUN_007044c0(1, 0, 0);
            reinterpret_cast<RepairManager*>(reinterpret_cast<char*>(FUN_004b7210(6, FUN_007b5720(500))) + 0x4d4)
                ->FUN_00718630();
        }
    }
}
}  // namespace fnv_007b7020

struct ValueObj_7b
{
    float GetValue();
};
struct ValueList_7b
{
    ValueObj_7b** Find(int aiID);
};
struct FUN_00a01230_shell
{
    int unk00;
    ValueList_7b list;
    bool IsTraitNonZero(int aiFlag);
};
struct FUN_004bddd0_shell
{
    float GetHealth(bool abFlag);
    bool FUN_004bddd0(bool abFlag);
};
struct SortEntry_7b
{
    FUN_00a01230_shell* pItem;
    FUN_004bddd0_shell* pData;
};

extern int DAT_011da748;

// Compares two sort entries by a flag, a list value against 255, health, and a secondary predicate, returning -1, 0 or 1.
// @fnv 0x007b5950
int CompareSortEntries(SortEntry_7b* apA, SortEntry_7b* apB)
{
    int iResult = 0;
    bool bHasA6 = apA->pItem->IsTraitNonZero(DAT_011da748);
    bool bHasB = apB->pItem->IsTraitNonZero(DAT_011da748);
    bool bLowA = (*apA->pItem->list.Find(0xfa9))->GetValue() < 255.0;
    bool bLowB4 = (*apB->pItem->list.Find(0xfa9))->GetValue() < 255.0;
    if (bHasA6 && !bHasB)
    {
        iResult = -1;
    }
    else if (!bHasA6 && bHasB)
    {
        iResult = 1;
    }
    else if (bLowA && !bLowB4)
    {
        iResult = 1;
    }
    else if (!bLowA && bLowB4)
    {
        iResult = -1;
    }
    else
    {
        iResult = (apA->pData->GetHealth(true) < apB->pData->GetHealth(true))
                      ? 1
                      : ((apA->pData->GetHealth(true) > apB->pData->GetHealth(true)) ? -1 : 0);
        if (bLowA && bLowB4)
        {
            iResult = -iResult;
        }
        if (iResult == 0)
        {
            if (apA->pData->FUN_004bddd0(false))
            {
                iResult = -1;
            }
            else if (apB->pData->FUN_004bddd0(false))
            {
                iResult = 1;
            }
        }
    }
    return iResult;
}

struct FloatValue
{
    float Read();
};
struct Values
{
    FloatValue** Find(int);
};
struct ClickTile
{
    int unk00;
    Values values;
    bool Enabled(int);
};
struct FormStub
{
    int* GetBase();
};
struct ItemStub
{
    FormStub* GetForm();
    int GetObject();
    bool Equipped(bool);
};
struct RepairList
{
    virtual void vf0();
    virtual int SelectedIndex();
    ItemStub* Selected();
    void Remove(int);
    unsigned int Count();
};
struct AudioPlaybackHandle
{
    int unk00, unk04, unk08;
    ~AudioPlaybackHandle();
    void Play();
};
struct AudioMgr
{
    AudioPlaybackHandle GetSoundByEditorID(const char*, int, int);
};
AudioMgr* GetAudio();
struct InterfaceStub
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
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void Repair(int, int, int, int, int, int, int, int, int, int);
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void Refresh();
};
extern InterfaceStub* DAT_011dea3c;
void UpdateRepair(int);
void UpdateEquip();
void PlayMenu(int);
void CloseMenu(int, int, int);
struct FUN_007b5b40_cls
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Click(int, ClickTile*);
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    ClickTile* tiles[13];
    RepairList list;
    void DoRepair(ItemStub*);
    void HandleRepairMenuAction(int id, ClickTile* target);
};
// @fnv 0x007b5b40
void FUN_007b5b40_cls::HandleRepairMenuAction(int aiActionId, ClickTile* apTargetTile)
{
    bool unused4 = false;
    if (!apTargetTile && aiActionId >= 0 && aiActionId < 13)
        apTargetTile = tiles[aiActionId];
    switch (aiActionId)
    {
    case 14:
        if ((*apTargetTile->values.Find(0xfa9))->Read() < 255.0)
        {
        }
        else
        {
            if (list.Selected() != (ItemStub*)DAT_011da760 && tiles[9]->Enabled(0xfa3))
            {
                ItemStub* item5 = list.Selected();
                int base = item5->GetForm() ? *item5->GetForm()->GetBase() : 0;
                DoRepair(item5);
                DAT_011dea3c->Repair(item5->GetObject(), base, 1, 0, 0, 0, 0, 0, 1, 0);
                GetAudio()->GetSoundByEditorID("UIRepairWeapon", 0x121, 0).Play();
                list.Remove(list.SelectedIndex());
                if (list.Count() == 1 || DAT_011da760->GetHealthPercent(true) >= 99.0)
                    Click(12, 0);
                else
                    UpdateRepair(0);
                if (item5->Equipped(false))
                {
                    DAT_011dea3c->Refresh();
                    UpdateEquip();
                }
            }
        }
        break;
    case 12:
        PlayMenu(0x24);
        CloseMenu(1, 0, 0);
        break;
    }
}

class TESBoundObject
{
  public:
    virtual ~TESBoundObject();
};
class TESObjectWEAP : public TESBoundObject
{
  public:
    int GetModdedValue(bool);
};
struct ExtraDataList
{
    virtual ~ExtraDataList();
    int flags04;
    int flags08;
    int flags0c;
    int flags10;
    int flags14;
    int flags18;
    int flags1c;
    ExtraDataList();
    short FUN_00418770();
    void DuplicateExtraListForContainer(ExtraDataList*);
    void FUN_00419ad0(int);
    void SetExtraHealth(float);
    bool CompareListForContainer(ExtraDataList*, bool, bool);
    void FUN_00419f80(void*);
};
struct RepairExtraNode
{
    ExtraDataList*& FUN_006815c0();
    RepairExtraNode* FUN_00726070();
    void FUN_0063f7b0();
    void FUN_005ae3d0(ExtraDataList*&);
    void FUN_00905330(ExtraDataList*&);
};
struct RepairInventoryItem : HealthOwner
{
    TESBoundObject* FUN_0044ddc0();
    bool HasEffect(int);
    RepairExtraNode* FUN_00559450();
};
struct RepairInventoryChanges
{
    RepairInventoryItem* FUN_004bfba0(TESBoundObject*, bool, bool);
};
RepairInventoryChanges* __cdecl FUN_004bf220(PlayerStub*);
unsigned int __cdecl FUN_004873d0(TESBoundObject*);
void __cdecl FUN_004d5c60(int);
struct RepairAction : RepairMenu
{
    void ApplyRepair(HealthOwner* source);
};
// Computes a repair amount from skill and health, applies it to the item's extra data, and merges the repaired entry into the inventory changes list.
// @fnv 0x007b5d80
void RepairAction::ApplyRepair(HealthOwner* source)
{
    float repairVal = 0.0f;
    repairVal = ComputeRepairAmount(g_thePlayer->skills.GetSkill(39), DAT_011da760->GetHealthPercent(true),
                                    source->GetHealthPercent(true), 0) /
                100.0;
    repairVal = FUN_0040ebd0(repairVal, 1.0f);
    TESObjectWEAP* bound = dynamic_cast<TESObjectWEAP*>(((RepairInventoryItem*)DAT_011da760)->FUN_0044ddc0());
    if (bound)
        repairVal *= bound->GetModdedValue(((RepairInventoryItem*)DAT_011da760)->HasEffect(10));
    else
        repairVal *= FUN_004873d0(((RepairInventoryItem*)DAT_011da760)->FUN_0044ddc0());
    RepairInventoryItem* entryTmp =
        FUN_004bf220(g_thePlayer)->FUN_004bfba0(((RepairInventoryItem*)DAT_011da760)->FUN_0044ddc0(), true, false);
    ExtraDataList* extra7 = ((RepairInventoryItem*)DAT_011da760)->FUN_00559450()
                                ? ((RepairInventoryItem*)DAT_011da760)->FUN_00559450()->FUN_006815c0()
                                : 0;
    ExtraDataList* repairA = new ExtraDataList;
    int count = -1;
    bool found9 = false;
    count = extra7->FUN_00418770();
    repairA->DuplicateExtraListForContainer(extra7);
    repairA->FUN_00419ad0(1);
    repairA->SetExtraHealth(repairVal);
    FUN_004d5c60(34);
    ((RepairInventoryItem*)DAT_011da760)->FUN_00559450()->FUN_0063f7b0();
    if (count > 1)
        extra7->FUN_00419ad0(count - 1);
    for (RepairExtraNode* node = entryTmp->FUN_00559450(); node && node->FUN_006815c0(); node = node->FUN_00726070())
    {
        if (!node->FUN_006815c0()->CompareListForContainer(repairA, true, false) &&
            !repairA->CompareListForContainer(node->FUN_006815c0(), true, false))
        {
            node->FUN_006815c0()->FUN_00419ad0(node->FUN_006815c0()->FUN_00418770() + 1);
            ((RepairInventoryItem*)DAT_011da760)->FUN_00559450()->FUN_005ae3d0(node->FUN_006815c0());
            found9 = true;
        }
    }
    if (!found9)
    {
        if (count > 1)
        {
            entryTmp->FUN_00559450()->FUN_005ae3d0(repairA);
            ((RepairInventoryItem*)DAT_011da760)->FUN_00559450()->FUN_005ae3d0(repairA);
        }
        else
        {
            extra7->SetExtraHealth(repairVal);
            ((RepairInventoryItem*)DAT_011da760)->FUN_00559450()->FUN_005ae3d0(extra7);
        }
    }
    else if (count == 1)
    {
        entryTmp->FUN_00559450()->FUN_00905330(extra7);
    }
    if (found9 || count == 1)
    {
        repairA->FUN_00419f80(0);
        delete repairA;
    }
}

struct PreviewForm
{
    int Type();
    float Armor();
    float Threshold();
};
struct PreviewItem
{
    PreviewForm* Form();
    float Health(bool);
};
struct PreviewTile
{
    float Value(int);
    void SetFloat(int, float, bool);
    void SetString(int, const char*, bool);
    void SetInt(int, int);
};
struct PreviewList
{
    virtual void v0();
    virtual PreviewTile* GetTile();
    PreviewItem* Selected();
    unsigned int Count();
};
struct PreviewSetting
{
    float* Float();
    const char* String();
};
struct PreviewPipboy
{
    void Rotate(int, float, float, bool);
};
struct PreviewInterface
{
    PreviewPipboy* Pipboy();
};
PreviewInterface* GetPreviewInterface();
extern PreviewSetting g_011db2f0, g_011db358, g_011d3dcc, g_011d1f2c, g_011d270c, g_011d018c, g_011d4ee8, g_011d2b20,
    g_011d2c7c, g_011d396c, g_011d20c4;
extern int DAT_011da7d8, DAT_011da74c;
extern HealthOwner* DAT_011da760;
int TraitID(const char*);
int FormatPreview(char*, unsigned int, const char*, ...);
int CopyPreview(char*, unsigned int, const char*);
int AppendPreview(char*, unsigned int, const char*);
float WeaponValue(PreviewForm*, float, PreviewItem*, int);
float AdjustWeapon(float, float);
double ArmorValue(int, float);
float MaxPreview(float, float);
struct PreviewMenu
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
    PreviewTile* tile38;
    PreviewTile* tile3c;
    PreviewTile* tile40;
    PreviewTile* tile44;
    PreviewTile* tile48;
    PreviewTile* tile4c;
    PreviewTile* tile50;
    PreviewTile* tile54;
    int unk58;
    PreviewList list;
    void Error(const char*);
    void UpdatePreviewComparison(int, PreviewTile*);
};

// @fnv 0x007b6120
void PreviewMenu::UpdatePreviewComparison(int event, PreviewTile* target)
{
    char text[64];
    switch (event)
    {
    case 14: {
        PreviewItem* item7 = list.Selected();
        int selection7 = item7 ? (int)list.GetTile()->Value(0xfac) : 0;
        if (DAT_011da7d8 != selection7)
        {
            GetPreviewInterface()->Pipboy()->Rotate(
                0, DAT_011da7d8 < selection7 ? *g_011db2f0.Float() : -*g_011db2f0.Float(), *g_011db358.Float(), true);
            DAT_011da7d8 = selection7;
        }
        if (item7 && DAT_011da760)
        {
            float limitX = 75.0f;
            if (item7->Form()->Type() == 24)
                limitX = 50.0f;
            if (limitX <= item7->Health(true))
                ((PreviewMenu*)DAT_011da75c)->tile54->SetString(0xfc4, g_011d3dcc.String(), true);
            else
                ((PreviewMenu*)DAT_011da75c)->tile54->SetString(0xfc4, g_011d1f2c.String(), true);
            if (item7 == (PreviewItem*)DAT_011da760)
            {
                if (list.Count() > 1)
                    Error(g_011d270c.String());
                tile54->SetFloat(TraitID("_line_alpha"), 128.0f, true);
            }
            else
            {
                float health4 = target->Value(0x1004);
                int cost4 = (int)target->Value(0x1005);
                if (cost4 > 100)
                {
                    FormatPreview(text, 64, g_011d4ee8.String(), *g_011d018c.Float() * 10.0, "%");
                    Error(text);
                    tile54->SetFloat(TraitID("_line_alpha"), 128.0f, true);
                }
                else if (cost4 > 0)
                {
                    FormatPreview(text, 64, g_011d2b20.String(), cost4, "%");
                    Error(text);
                    tile54->SetFloat(TraitID("_line_alpha"), 128.0f, true);
                }
                else
                {
                    tile54->SetFloat(TraitID("_line_alpha"), 255.0f, true);
                    tile4c->SetFloat(0x1004, health4, true);
                    tile4c->SetInt(0xfa3, 1);
                    tile48->SetInt(0xfa3, 0);
                    if (((PreviewItem*)DAT_011da760)->Form()->Type() == 40)
                    {
                        tile50->SetString(DAT_011da74c, g_011d2c7c.String(), true);
                        tile50->SetInt(DAT_011da754,
                                       (int)AdjustWeapon(WeaponValue(((PreviewItem*)DAT_011da760)->Form(), health4,
                                                                     (PreviewItem*)DAT_011da760, 0),
                                                         1.0f));
                    }
                    else if (item7->Form()->Type() == 24)
                    {
                        char empty[128];
                        {
                            PreviewForm* armor = ((PreviewItem*)DAT_011da760)->Form();
                            float oldhealth5 = ((PreviewItem*)DAT_011da760)->Health(true) / 100.0;
                            float oldarmor = ArmorValue((int)armor->Armor(), oldhealth5);
                            float oldthreshold3 = ArmorValue((int)armor->Threshold(), oldhealth5);
                            float newarmor3 = ArmorValue((int)armor->Armor(), health4);
                            float newthreshold2 = ArmorValue((int)armor->Threshold(), health4);
                            CopyPreview(empty, 128, "--");
                            if (newthreshold2 > 0.0)
                            {
                                ((PreviewMenu*)DAT_011da75c)
                                    ->tile3c->SetString(DAT_011da74c, g_011d396c.String(), true);
                                if (oldthreshold3 > 0.0)
                                    ((PreviewMenu*)DAT_011da75c)->tile3c->SetInt(DAT_011da754, (int)oldthreshold3);
                                else
                                    ((PreviewMenu*)DAT_011da75c)->tile3c->SetString(DAT_011da754, empty, true);
                                ((PreviewMenu*)DAT_011da75c)
                                    ->tile50->SetString(DAT_011da74c, g_011d396c.String(), true);
                                ((PreviewMenu*)DAT_011da75c)->tile50->SetInt(DAT_011da754, (int)newthreshold2);
                            }
                            else if (newarmor3 > 0.0)
                            {
                                ((PreviewMenu*)DAT_011da75c)
                                    ->tile3c->SetString(DAT_011da74c, g_011d20c4.String(), true);
                                if (oldarmor > 0.0)
                                    ((PreviewMenu*)DAT_011da75c)->tile3c->SetInt(DAT_011da754, (int)oldarmor);
                                else
                                    ((PreviewMenu*)DAT_011da75c)->tile3c->SetString(DAT_011da754, empty, true);
                                ((PreviewMenu*)DAT_011da75c)
                                    ->tile50->SetString(DAT_011da74c, g_011d20c4.String(), true);
                                ((PreviewMenu*)DAT_011da75c)->tile50->SetInt(DAT_011da754, (int)newarmor3);
                            }
                            else
                            {
                                ((PreviewMenu*)DAT_011da75c)
                                    ->tile3c->SetString(DAT_011da74c, g_011d20c4.String(), true);
                                ((PreviewMenu*)DAT_011da75c)->tile3c->SetString(DAT_011da754, empty, true);
                                ((PreviewMenu*)DAT_011da75c)
                                    ->tile50->SetString(DAT_011da74c, g_011d20c4.String(), true);
                                ((PreviewMenu*)DAT_011da75c)->tile50->SetString(DAT_011da754, empty, true);
                            }
                        }
                    }
                    float healthdiff8 = (tile4c->Value(0x1004) - tile38->Value(0x1004)) * 100.0;
                    float statdiff9 = tile50->Value(DAT_011da754) - tile3c->Value(DAT_011da754);
                    healthdiff8 = MaxPreview(0.0f, healthdiff8);
                    statdiff9 = MaxPreview(0.0f, statdiff9);
                    FormatPreview(text, 64, "+%i", (int)(healthdiff8 + 0.5));
                    AppendPreview(text, 64, "%");
                    tile40->SetString(0xfc4, text, true);
                    FormatPreview(text, 64, "+%i", (int)(statdiff9 + 0.5));
                    tile44->SetString(0xfc4, text, true);
                }
            }
        }
        break;
    }
    }
}

namespace fnv_007b6aa0 {
struct Extra
{
    bool Check();
};
struct Item;
struct ExtraNode
{
    Extra*& Head();
    ExtraNode* Next();
};
struct Item
{
    int unk00;
    int unk04;
    int unk08;
    Item(void*, int);
    void* Form();
    int Count();
    float Health(bool);
    ExtraNode* Extras();
    const char* Name();
    bool Equipped(bool);
};
struct ItemNode
{
    Item* data;
    ItemNode* next;
    ItemNode();
    ~ItemNode();
    Item*& Head();
    ItemNode* Next();
};
struct Changes
{
    static Changes* GetOrAddInventoryChanges(void*);
    void Collect(void*, ItemNode*);
};
struct Value
{
    void Clear();
    void Link(int, void*, int);
    void SetNumber(int, float);
    void Finish(int);
};
struct UITile
{
    void SetInt(int, int);
    Value* GetValue(int);
    UITile* Child(const char*);
    void SetString(int, const char*, bool);
};
struct Box
{
    UITile* Add(Item*, const char*, int, int);
    void Remove(UITile*);
};
struct RepairView
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
    UITile* tile28;
    int unk2c;
    UITile* tile30;
    int unk34;
    UITile* tile38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    UITile* tile4c;
    int unk50;
    UITile* tile54;
    UITile* tile58;
    Box box;
    UITile* Root();
};
struct Setting
{
    const char* String();
};
extern Setting gSystemLocaleState;
extern Setting g_011d4378, g_011d4030, g_011d4da4, g_011d1f2c, g_011d29f4;
extern Item* selectedItem;
extern RepairView* repairView;
extern void* playerObject;
extern int DAT_011da748, DAT_011da74c;
float RoundHealth(float);
int CompareText(const char*, const char*);
void* operator new(unsigned int);
struct ExtraList
{
    void AddHead(Extra*&);
};
// @fnv 0x007b6aa0
void __cdecl PopulateRepairMenu()
{
    if (!selectedItem)
        return;
    ItemNode selectedExtra;
    {
        Changes* c;
        c = Changes::GetOrAddInventoryChanges(playerObject);
        c->Collect(selectedItem->Form(), &selectedExtra);
    }
    for (ItemNode* node = &selectedExtra; node && node->Head(); node = node->Next())
    {
        UITile* n;
        n = 0;
        Item* item;
        item = 0;
        for (int index = 0; index < node->Head()->Count(); ++index)
        {
            float rawHealth;
            float extra;
            rawHealth = node->Head()->Health(true);
            extra = RoundHealth(rawHealth);
            bool tmp;
            tmp = false;
            Extra* special;
            special = node->Head()->Extras() ? node->Head()->Extras()->Head() : 0;
            if (special && special->Check())
                tmp = true;
            if (extra < 100.0 || node->Head()->Form() != selectedItem->Form())
            {
                if (!index)
                {
                    item = node->Head();
                    n = repairView->box.Add(item, item->Name(), 0, 0);
                    if (n && item->Form() == selectedItem->Form())
                    {
                        Extra* x;
                        x = item->Extras() ? item->Extras()->Head() : 0;
                        Extra* list;
                        list = selectedItem->Extras() ? selectedItem->Extras()->Head() : 0;
                        if (x == list)
                        {
                            selectedItem = item;
                            n->SetInt(DAT_011da748, 1);
                            Value* healthValue;
                            healthValue = repairView->tile30->GetValue(0xfb0);
                            Value* p;
                            p = repairView->tile30->GetValue(0xfa2);
                            healthValue->Clear();
                            healthValue->Link(0x7d0, n, 0xfb0);
                            healthValue->SetNumber(0x7d2, 1.0f);
                            healthValue->Finish(0);
                            p->Clear();
                            p->Link(0x7d0, n, 0xfa2);
                            p->Finish(0);
                        }
                        else if (tmp || item->Equipped(false))
                            repairView->box.Remove(n);
                    }
                }
                else
                {
                    item = new Item(node->Head()->Form(), 1);
                    for (ExtraNode* extraNode = node->Head()->Extras(); extraNode && extraNode->Head();
                         extraNode = extraNode->Next())
                        ((ExtraList*)item->Extras())->AddHead(extraNode->Head());
                    n = repairView->box.Add(item, item->Name(), 0, 0);
                }
            }
        }
    }
    if (CompareText(gSystemLocaleState.String(), "ENGLISH"))
    {
        repairView->Root()->Child("RM_Headline_Title")->SetString(0xfc4, g_011d4378.String(), true);
        repairView->tile28->SetString(DAT_011da74c, g_011d4030.String(), true);
        repairView->tile38->SetString(DAT_011da74c, g_011d4da4.String(), true);
        repairView->tile4c->SetString(DAT_011da74c, g_011d4da4.String(), true);
        repairView->tile54->SetString(0xfc4, g_011d1f2c.String(), true);
        repairView->tile58->SetString(0xfc4, g_011d29f4.String(), true);
    }
}
}  // namespace fnv_007b6aa0
