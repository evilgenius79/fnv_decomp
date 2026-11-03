// fallout/interface/menus/itemmodmenu.cpp: ItemModMenu, RepairMenu, ModMenuStub, ItemModMenuHack and more (19 functions)

#include "itemmodmenu_unit_decls.h"

static const int kGetClassValue = 1061;

// Loads the item mod menu tile from file, validates its menu ID, initializes the list box and child tiles, and returns the tile or 0 on failure.
// @fnv 0x00783440
Tile* __cdecl ItemModMenu::Create()
{
    struct CreateLocals
    {
        Menu* destroyedMenu;
        Tile* destroyedTile;
        Menu* oldMenu;
        Menu* oldMenuCopy;
        Tile* firstCopy;
        Tile* secondCopy;
        void* resourceProvider;
        Tile* fileTile;
        Tile* menuTile;
    } state;

    state.resourceProvider = FUN_004b7210();
    state.menuTile = Tile::FindMenuById(FUN_00783640());
    if (state.menuTile != 0)
    {
        state.firstCopy = state.menuTile;
        state.secondCopy = state.firstCopy;
        if (state.secondCopy != 0)
        {
            state.destroyedTile = state.secondCopy->Destroy(true);
        }
        else
        {
            state.destroyedTile = 0;
        }
    }

    state.fileTile = ((InterfaceManager*)state.resourceProvider)->FUN_00586150()->ReadFile(DAT_01073c34);
    DAT_011d9f54 = state.fileTile->GetMenu();
    if (DAT_011d9f54 != 0 && DAT_011d9f54->GetID() == FUN_00783640())
    {
        DAT_011d9f54->SetTileMenu((TileMenu*)state.fileTile, false);
        ((InventoryMenu*)DAT_011d9f54)->FUN_00867a20();
        if (!DAT_011d9f54->FUN_007273f0())
        {
            Warning(DAT_01073be0);
            return 0;
        }

        if (((TileListBoxCalls*)state.fileTile)->GetFloat(0xfa7) == DAT_010704f0 ||
            ((TileListBoxCalls*)state.fileTile)->GetFloat(0xfa7) == DAT_010704e8)
        {
            state.fileTile->Set(0xfad, Tile::GetInterfaceScale(), true);
        }

        ((ListBox_ItemChange___*)((char*)DAT_011d9f54 + 0x60))
            ->Initialize(((ItemModMenu*)DAT_011d9f54)->m_pTiles[1], DAT_01073bc4);
        ((ListBox_ItemChange___*)((char*)DAT_011d9f54 + 0x60))->FUN_007a1930(false);
        ((ItemModMenu*)DAT_011d9f54)->m_pTiles[5]->SetTraitFloat(DAT_011d9f44, 1.0f);
        ((ItemModMenu*)DAT_011d9f54)->m_pTiles[10]->SetTraitFloat(DAT_011d9f44, 1.0f);
        DAT_011d9f54->SetMenuVisibility(true);
        return state.fileTile;
    }

    else
    {
        if (DAT_011d9f54 != 0 && ((BSSimpleList<BGSPerkEntry*>*)DAT_011d9f54)->GetNext() != 0)
        {
            state.oldMenu = DAT_011d9f54;
            state.oldMenuCopy = state.oldMenu;
            if (state.oldMenuCopy != 0)
            {
                state.destroyedMenu = state.oldMenuCopy->Destructor(true);
            }
            else
            {
                state.destroyedMenu = 0;
            }
        }
    }
    return 0;
}

// @fnv 0x00783310
ItemModMenu::ItemModMenu()
{
    DAT_011d9f3c = Tile::GetTraitID(DAT_0106ed20);
    DAT_011d9f44 = Tile::GetTraitID(DAT_0106ed18);
    DAT_011d9f48 = Tile::GetTraitID(DAT_01070244);
    DAT_011d9f4c = Tile::GetTraitID(DAT_01073b64);
    DAT_011d9f40 = 0;
}

// @fnv 0x007b5400
RepairMenu::RepairMenu()
{
    DAT_011da74c = Tile::GetTraitID(DAT_0106ed20);
    DAT_011da754 = Tile::GetTraitID(DAT_0106ed18);
    DAT_011da750 = Tile::GetTraitID(DAT_01070244);
    DAT_011da748 = Tile::GetTraitID(DAT_01075c44);
}

// @fnv 0x007833d0
int ItemModMenu::GetClass()
{
    return kGetClassValue;
}

struct FUN_007273f0_shell : public ItemModMenu
{
    bool FUN_007273f0();
};

// Checks the 14 int entries at offset 0x28 and returns false if any is zero, otherwise true.
// @fnv 0x007273f0
bool FUN_007273f0_shell::FUN_007273f0()
{
    for (int i = 0; i < 14; ++i)
    {
        if (((int*)((char*)this + 0x28))[i] == 0)
            return false;
    }
    return true;
}

// @fnv 0x00783640
int __cdecl FUN_00783640()
{
    return 0x425;
}

struct ModMenuStub
{
    void FUN_00783650();
    void* DestroyIfFlagged(unsigned int);
};
void _Deallocate(void*);
// Calls FUN_00783650, deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x00783410
void* ModMenuStub::DestroyIfFlagged(unsigned int flags)
{
    FUN_00783650();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct Tile_Set_Helper
{
    void Set(int a, int b);
};
struct ListBoxStandIn
{
    unsigned int FUN_0071ae60();
};
struct ItemModMenuHack
{
    char _00[0x48];
    Tile_Set_Helper* _48;
    Tile_Set_Helper* _4C;
    char _50[0x10];
    ListBoxStandIn _60;
    void UpdateItemModTile(int aiID, Tile* apTarget);
};
// For ID 15, sets tile 0xFA3 to 0 on _4C and, when the list box count exceeds 1, also on _48.
// @fnv 0x00784050
void ItemModMenuHack::UpdateItemModTile(int aiID, Tile* apTarget)
{
    if (aiID == 15)
    {
        _4C->Set(0xFA3, 0);
        if (_60.FUN_0071ae60() > 1)
        {
            _48->Set(0xFA3, 0);
        }
    }
}

struct Interface
{
    static void __cdecl PlayUISound(int);
};
struct MyMenu
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(int, int);
    bool HandleButtonPress(int aiButton, float afValue);
};
// @fnv 0x007840a0
bool MyMenu::HandleButtonPress(int aiButton, float afValue)
{
    bool bhandled = false;
    switch (aiButton)
    {
    case 6:
    case 10:
        Interface::PlayUISound(3);
        this->f3(12, 0);
        bhandled = true;
    }
    return bhandled;
}

struct TileRemoveFade
{
    void UpdateTrait(int value);
};

struct FUN_007308e0
{
    virtual ~FUN_007308e0();
};

struct Menu_007a8b10
{
    virtual ~Menu_007a8b10();
};

struct FUN_00783650 : Menu_007a8b10
{
    unsigned char opaque_00[0x44];
    TileRemoveFade* fadeControl;
    unsigned char opaque_4c[0x14];
    FUN_007308e0 member_60;

    ~FUN_00783650();
};

extern int _DAT_011d9f54;

// @fnv 0x00783650
FUN_00783650::~FUN_00783650()
{
    fadeControl->UpdateTrait(0xfa9);
    _DAT_011d9f54 = 0;
}

struct GO
{
    operator unsigned int() const;
};

struct TV
{
    bool IsVisible();
};

struct FUN_006317a0_struct : public GO
{
    TV** AddEight(int);
};

struct ExtraDataList;

struct InventoryStackRecord
{
    BSSimpleList<ExtraDataList*>* m_pExtraDataLists;
    FUN_006317a0_struct object;
};

template <class T> struct ListBoxItem
{
    T m_item;
};

// Compares the visibility of the objects referenced by two list box items, returning -1, 1, or 0.
// @fnv 0x00783810
int CompareItemVisibility(ListBoxItem<InventoryStackRecord*>* apItem1, ListBoxItem<InventoryStackRecord*>* apItem2)
{
    bool bVisibleA;
    int iresult = 0;
    bool bVisibleB;

    bVisibleA = (*apItem1->m_item->object.AddEight(apItem1->m_item->object.operator unsigned int()))->IsVisible();
    bVisibleB = (*apItem2->m_item->object.AddEight(apItem2->m_item->object.operator unsigned int()))->IsVisible();

    if (bVisibleA && !bVisibleB)
        iresult = -1;
    else if (!bVisibleA && bVisibleB)
        iresult = 1;

    return iresult;
}

struct ModEntry;
struct ModObject
{
    float FUN_004bcdb0(int);
    ModEntry* FUN_0044ddc0();
    unsigned char FUN_004bd820();
};
struct ModEntry
{
    ModEntry* FUN_004bd570(int);
};
struct ModTile;
struct ModTileList
{
    ModTile** FUN_007b5370();
};
struct ModTile
{
    unsigned int field_00;
    ModTileList field_04;
    void FUN_00700320(int, int);
    float FUN_00a011b0(int);
    void FUN_00a012d0(int, float, bool);
};
extern ModObject* DAT_011d9f58;
extern double DAT_01012060;
extern float DAT_01073c54;
// @fnv 0x007836d0
void __cdecl UpdateTileFromObject(ModTile* tile, ModObject* object)
{
    if (!tile || !object)
        return;
    float value = object->FUN_004bcdb0(1);
    tile->FUN_00700320(0xfaa, 15);
    tile->FUN_00700320(0xfa3, tile->FUN_00a011b0(0xfac) >= DAT_01012060 ? 1 : 0);
    tile->FUN_00a012d0(0xfa3, 1.0f, true);
    ModEntry* entry = DAT_011d9f58->FUN_0044ddc0();
    if (DAT_011d9f58->FUN_004bd820())
    {
        ModEntry* other = object->FUN_0044ddc0();
        if (((DAT_011d9f58->FUN_004bd820() & 1) && other == entry->FUN_004bd570(1)) ||
            ((DAT_011d9f58->FUN_004bd820() & 2) && other == entry->FUN_004bd570(2)) ||
            ((DAT_011d9f58->FUN_004bd820() & 4) && other == entry->FUN_004bd570(4)))
        {
            (*tile->field_04.FUN_007b5370())->FUN_00a012d0(0xfa9, DAT_01073c54, true);
        }
    }
}

namespace fnv_007846a0 {
struct ItemListBoxCalls
{
    virtual void Method0();
    virtual void Method1();
    virtual void Method2();
    virtual void Method3();
    virtual void Method4();
    virtual void Method5();
    virtual void Method6();
    virtual void Method7();
};
struct TileActionCalls
{
    void __thiscall RemoveFadeItemsForTile(int);
    void __thiscall FUN_00700320(int, int);
};
extern "C" int DAT_011d9f58;

// @fnv 0x007846a0
void __cdecl ResetItemModMenu()
{
    reinterpret_cast<ItemListBoxCalls*>(&static_cast<ItemModMenu*>(DAT_011d9f54)->m_kItemList)->Method7();
    DAT_011d9f58 = 0;
    DAT_011d9f54->HandleMouseoverTileAlt(0x0f, 0);
    reinterpret_cast<TileActionCalls*>(static_cast<ItemModMenu*>(DAT_011d9f54)->m_pTiles[8])
        ->RemoveFadeItemsForTile(0xfa9);
    reinterpret_cast<TileActionCalls*>(static_cast<ItemModMenu*>(DAT_011d9f54)->m_pTiles[8])->FUN_00700320(0xfa3, 0);
}
}  // namespace fnv_007846a0

struct EqForm;
struct EqScriptLocals;

struct EqExtraList
{
    virtual ~EqExtraList();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;

    EqExtraList();
    short GetCount();
    void CopyFrom(EqExtraList* apOther);
    void SetCount(short asCount);
    unsigned char GetHandFlags();
    void SetHandFlag(unsigned char aucFlag);
    bool IsEqual(EqExtraList* apOther, int aiUnk1, int aiUnk2);
    void SetScript(EqScriptLocals* apScript);
    float GetHealth();
    void SetExtraHealth(float afHealth);
};

struct EqExtraListNode
{
    EqExtraList* pItem;
    EqExtraListNode* pNext;

    EqExtraList** GetItem();
    EqExtraListNode* GetNext();
    void AddHead(EqExtraList*& arItem);
    void Remove(EqExtraList* const& arItem);
    void RemoveAll();
};

struct EqForm
{
    EqForm* GetSlotForm(unsigned int auiSlot);
    int GetEquipType(int aiSlot);
    float GetSlotValue(int aiType, unsigned char aucUnk);
};

struct EqEntry
{
    EqExtraListNode* GetExtendData();
    EqForm* GetType();
};

struct EqInventoryChanges
{
    static EqInventoryChanges* __cdecl GetOrAddInventoryChanges(void* apRef);
    EqEntry* FindEntry(EqForm* apType, int aiUnk1, int aiUnk2);
};

void __cdecl EqPlayMenuSound(int aiSound);

extern EqEntry* g_pEqCurrentEntry;
extern void* g_pEqPlayer;
extern int g_iEqUnused;

struct EqMenu
{
    bool FUN_00783af0(EqEntry* apTarget);
};

// Merges the current entry's extra data into the player's inventory, equips it to a free hand slot, and returns whether it was equipped.
// @fnv 0x00783af0
bool EqMenu::FUN_00783af0(EqEntry* apTarget)
{
    EqEntry* pPlayerEntry =
        EqInventoryChanges::GetOrAddInventoryChanges(g_pEqPlayer)->FindEntry(g_pEqCurrentEntry->GetType(), 1, 0);
    EqExtraList* pExtra = (g_pEqCurrentEntry->GetExtendData()) ? *g_pEqCurrentEntry->GetExtendData()->GetItem() : 0;
    EqExtraList* pNewExtra2 = new EqExtraList;
    int _iCount = -1;
    bool bMerged4 = false;
    bool bEquipped = false;
    EqForm* pType3 = g_pEqCurrentEntry->GetType();
    bool bUnused3 = true;
    EqForm* pTargetType = apTarget->GetType();
    int iUnused2 = g_iEqUnused;

    _iCount = pExtra->GetCount();
    pNewExtra2->CopyFrom(pExtra);
    pNewExtra2->SetCount(1);
    g_pEqCurrentEntry->GetExtendData()->RemoveAll();
    if (_iCount > 1)
        pExtra->SetCount(_iCount - 1);

    unsigned char ucHand7 = 0;
    if (!(pNewExtra2->GetHandFlags() & 1) && pType3->GetSlotForm(1) == pTargetType)
    {
        pNewExtra2->SetHandFlag(1);
        ucHand7 = 1;
        bEquipped = true;
    }
    else if (!(pNewExtra2->GetHandFlags() & 2) && pType3->GetSlotForm(2) == pTargetType)
    {
        pNewExtra2->SetHandFlag(2);
        ucHand7 = 2;
        bEquipped = true;
    }
    else if (!(pNewExtra2->GetHandFlags() & 4) && pType3->GetSlotForm(4) == pTargetType)
    {
        pNewExtra2->SetHandFlag(4);
        ucHand7 = 4;
        bEquipped = true;
    }

    for (EqExtraListNode* pNode4 = pPlayerEntry->GetExtendData(); pNode4 && *pNode4->GetItem();
         pNode4 = pNode4->GetNext())
    {
        if (!(*pNode4->GetItem())->IsEqual(pNewExtra2, 1, 0) && !pNewExtra2->IsEqual(*pNode4->GetItem(), 1, 0))
        {
            (*pNode4->GetItem())->SetCount((*pNode4->GetItem())->GetCount() + 1);
            g_pEqCurrentEntry->GetExtendData()->AddHead(*pNode4->GetItem());
            bMerged4 = true;
        }
    }

    EqExtraList* pResult4 = 0;
    if (!bMerged4)
    {
        if (_iCount > 1)
        {
            pPlayerEntry->GetExtendData()->AddHead(pNewExtra2);
            g_pEqCurrentEntry->GetExtendData()->AddHead(pNewExtra2);
            pResult4 = pNewExtra2;
        }
        else
        {
            pExtra->SetHandFlag(ucHand7);
            g_pEqCurrentEntry->GetExtendData()->AddHead(pExtra);
            pResult4 = pExtra;
        }
    }
    else if (_iCount == 1)
    {
        pPlayerEntry->GetExtendData()->Remove(pExtra);
    }

    if (bMerged4 || _iCount == 1)
    {
        pNewExtra2->SetScript(0);
        delete pNewExtra2;
        if (pResult4 == pNewExtra2)
            pResult4 = 0;
    }

    if (pType3->GetEquipType(ucHand7) == 10 && pResult4)
        pResult4->SetExtraHealth(pResult4->GetHealth() + pType3->GetSlotValue(10, 0));

    if (bEquipped)
        EqPlayMenuSound(0x21);
    return bEquipped;
}

bool __cdecl FUN_004b71d0();
void __cdecl FUN_00706ff0(int);

struct ModStr
{
    char* pString;
    unsigned short usLen;
    unsigned short usMaxLen;
    ModStr(const char* src);
    ~ModStr();
    operator const char*() const;
};

struct ModListTile
{
    char* GetString(int trait);
    void SetInt(int trait, int value);
    void SetString(int trait, const char* value, bool propagate);
};

struct ModListEntry
{
    ModListTile* pTile;
    int Next();
};

struct ModListOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    ModListEntry* pEntry;

    bool IsEmpty() const;
    ModListEntry** GetFirst();
    void Advance(int count);
    void FUN_007b4410();
};

// @fnv 0x007b4410
void ModListOwner::FUN_007b4410()
{
    if (FUN_004b71d0())
    {
        if (!pEntry && !IsEmpty())
            pEntry = *GetFirst();
        if (pEntry)
        {
            ModStr savedTraitString(pEntry->pTile->GetString(0xfe8));
            pEntry->pTile->SetInt(0xfe8, -1);
            FUN_00706ff0((int)pEntry->pTile);
            pEntry->pTile->SetString(0xfe8, savedTraitString, true);
            while (true)
            {
                int count = pEntry->Next();
                if (count)
                {
                    Advance(-count);
                }
                else
                {
                    break;
                }
            }
        }
    }
}

namespace fnv_007838a0 {
class TESForm;
template <class T> class BSStringT
{
  public:
    operator const T*() const;
};
class B006815c0
{
  public:
    B006815c0();
};
struct ContNode;
ContNode* __fastcall FUN_00726070(ContNode*);
class TESObjectREFR_GetFlags_Helper
{
  public:
    unsigned int CallGetFlags();
};
class ItemEntry : public BSStringT<char>
{
  public:
    bool FUN_004bddd0(bool);
    void FUN_004bdc70();
};
class TileValueW
{
  public:
    float FUN_00a011b0();
};
class TileValueList
{
  public:
    TileValueW** FUN_007b5370(unsigned int);
};
class BSSoundHandleEx
{
  public:
    unsigned int uiSoundID;
    unsigned char m_bLooping;
    unsigned int uiState;
    ~BSSoundHandleEx();
    bool Play(bool);
};
class BSAudio
{
  public:
    BSSoundHandleEx GetSoundHandleByEditorID(const char*, unsigned int);
};
BSAudio* FUN_00453a70();
struct FUN_004f2770_Class
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v04a();
    virtual void v04b();
    virtual void v04c();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v05a();
    virtual void v05b();
    virtual void v05c();
    virtual void v05d();
    virtual void v05e();
    virtual void SendItemModEvent(unsigned int ItemUpdateArray, TESForm* pForm, bool b1, bool b2, bool b3, bool b4, bool b5,
                                  bool b6, bool b7, bool b8);
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v06a();
    virtual void v06b();
    virtual void v06c();
    virtual void v06d();
    virtual void v06e();
    virtual void v06f();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v07a();
    virtual void v07b();
    virtual void v07c();
    virtual void v07d();
    virtual void v07e();
    virtual void v07f();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v08a();
    virtual void v08b();
    virtual void v08c();
    virtual void v08d();
    virtual void v08e();
    virtual void v08f();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v09a();
    virtual void v09b();
    virtual void v09c();
    virtual void v09d();
    virtual void v09e();
    virtual void v09f();
    virtual void v0a0();
    virtual void v0a1();
    virtual void v0a2();
    virtual void v0a3();
    virtual void v0a4();
    virtual void v0a5();
    virtual void v0a6();
    virtual void v0a7();
    virtual void v0a8();
    virtual void v0a9();
    virtual void v0aa();
    virtual void v0ab();
    virtual void v0ac();
    virtual void v0ad();
    virtual void v0ae();
    virtual void v0af();
    virtual void v0b0();
    virtual void v0b1();
    virtual void v0b2();
    virtual void v0b3();
    virtual void v0b4();
    virtual void v0b5();
    virtual void v0b6();
    virtual void v0b7();
    virtual void v0b8();
    virtual void v0b9();
    virtual void v0ba();
    virtual void v0bb();
    virtual void v0bc();
    virtual void v0bd();
    virtual void v0be();
    virtual void v0bf();
    virtual void v0c0();
    virtual void v0c1();
    virtual void v0c2();
    virtual void v0c3();
    virtual void v0c4();
    virtual void v0c5();
    virtual void v0c6();
    virtual void v0c7();
    virtual void v0c8();
    virtual void v0c9();
    virtual void v0ca();
    virtual void v0cb();
    virtual void v0cc();
    virtual void v0cd();
    virtual void v0ce();
    virtual void v0cf();
    virtual void v0d0();
    virtual void v0d1();
    virtual void v0d2();
    virtual void v0d3();
    virtual void v0d4();
    virtual void v0d5();
    virtual void v0d6();
    virtual void v0d7();
    virtual void v0d8();
    virtual void v0d9();
    virtual void v0da();
    virtual void v0db();
    virtual void v0dc();
    virtual void v0dd();
    virtual void v0de();
    virtual void v0df();
    virtual void v0e0();
    virtual void v0e1();
    virtual void v0e2();
    virtual void v0e3();
    virtual void v0e4();
    virtual void v0e5();
    virtual void v0e6();
    virtual void v0e7();
    virtual void v0e8();
    virtual void v0e9();
    virtual void v0ea();
    virtual void v0eb();
    virtual void v0ec();
    virtual void v0ed();
    virtual void v0ee();
    virtual void v0ef();
    virtual void v0f0();
    virtual void UpdateRepairMenu();
    void EquipItem(unsigned int, ContNode*, TESForm*, bool, bool, bool);
};
extern FUN_004f2770_Class* _g_thePlayer;
extern ItemEntry* DAT_011d9f58;
class ItemModListW
{
  public:
    virtual void v0();
    virtual int v1();
    ItemEntry* FUN_007a1910();
    void RemoveTile(int);
};
void FUN_00717280(int);
void FUN_00784710(ItemEntry*, int);
void FUN_00782a90();
void FUN_007048f0(int, int, int);

class ItemModMenuW : public ItemModMenu
{
  public:
    bool FUN_00783af0(ItemEntry*);
    void HandleItemModMenuClick(int tileID, Tile* clickedTile);
};

// @fnv 0x007838a0
void ItemModMenuW::HandleItemModMenuClick(int tileID, Tile* clickedTile)
{
    bool bHandled = false;
    if (!clickedTile && tileID >= 0 && tileID < 14)
        clickedTile = m_pTiles[tileID];
    switch (tileID)
    {
    case 15:
        if ((*((TileValueList*)((char*)clickedTile + 4))->FUN_007b5370(0xfa9))->FUN_00a011b0() < 255.0)
        {
        }
        else
        {
            if (((ItemModListW*)&m_kItemList)->FUN_007a1910() != DAT_011d9f58)
            {
                ItemEntry* pEntry = ((ItemModListW*)&m_kItemList)->FUN_007a1910();
                TESForm* pForm =
                    (const char*)*pEntry ? *(TESForm**)&((B006815c0*)(const char*)*pEntry)->B006815c0::B006815c0() : 0;
                if (FUN_00783af0(pEntry))
                {
                    _g_thePlayer->SendItemModEvent(((TESObjectREFR_GetFlags_Helper*)pEntry)->CallGetFlags(), pForm,
                                                   true, false, false, false, false, false, true, false);
                    FUN_00453a70()->GetSoundHandleByEditorID("UIItemGunsSmallUp ", 0x121).Play(false);
                    ((ItemModListW*)&m_kItemList)->RemoveTile(((ItemModListW*)&m_kItemList)->v1());
                    FUN_00784710(DAT_011d9f58, 0);
                    if (pEntry->FUN_004bddd0(false))
                    {
                        _g_thePlayer->UpdateRepairMenu();
                        FUN_00782a90();
                    }
                }
            }
        }
        break;
    case 12:
        FUN_00717280(0x24);
        if (DAT_011d9f40 == 1)
        {
            _g_thePlayer->EquipItem(
                ((TESObjectREFR_GetFlags_Helper*)DAT_011d9f58)->CallGetFlags(), FUN_00726070((ContNode*)DAT_011d9f58),
                *(TESForm**)&((B006815c0*)(const char*)*DAT_011d9f58)->B006815c0::B006815c0(), true, false, true);
            DAT_011d9f58->FUN_004bdc70();
            DAT_011d9f40 = 0;
        }
        FUN_007048f0(1, 0, 0);
        break;
    }
}
}  // namespace fnv_007838a0

struct Form78;
struct Data78
{
    void** FUN_006815c0();
};
struct Entry78
{
    bool FUN_004bddd0(bool);
    void FUN_004bdb40();
    Data78* FUN_00559450();
    int FUN_00726070();
    Form78* FUN_0044ddc0();
    float FUN_004bcdb0(int);
    const char* GetIconFilename(int);
};
struct Form78
{
    int FUN_00401170();
    float FUN_004be060();
};
struct Name78
{
    const char* FUN_00408da0();
};
struct Player78
{
    void UnequipItem(Form78*, int, void*, int, int, int);
};
extern Player78* _g_thePlayer;
extern Entry78* g_011d9f58;
struct Tile78
{
    void Set(int, float, bool);
    void Set(int, int);
    void Set(int, const char*, bool);
};
struct Box78
{
    virtual void v0();
    virtual int count();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual Tile78* selected(int, int, int, int);
    virtual void v6();
    virtual void clear();
    virtual void sort(void (*)(void*, void*));
    void FUN_007314c0(void (*)(void*, void*), int, int);
};
struct Menu78
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void notify(int, int);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    Tile78* unk28;
    int unk2c;
    int unk30;
    Tile78* unk34;
    Tile78* unk38;
    Tile78* unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    Box78 unk60;
};
struct Setting78
{
    const char* FUN_00403df0();
};
extern Setting78 g_011d2c7c, g_011d20c4;
float GetWeaponDamage(Form78*, float, Entry78*, int);
float FUN_004bd510(float, float);
float FUN_00646360(int, float);
float FUN_00476b20(float);
void PopulateModListScreen();
void UpdateTileFromObject(void*, void*);
void CompareItemVisibility(void*, void*);
bool FUN_004b71d0();
struct Input78
{
    void FUN_00718630(int, int, int);
};
struct Manager78
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
    Input78 unk4d4;
    void FUN_00715860(Tile78*);
};
void FUN_007046f0(int, int, int);
// @fnv 0x00784710
void FUN_00784710(Entry78* pEntry, bool b)
{
    if (b)
        DAT_011d9f40 = 0;
    if (DAT_011d9f54)
    {
        if (pEntry)
            g_011d9f58 = pEntry;
        if (g_011d9f58 && b && g_011d9f58->FUN_004bddd0(false))
        {
            g_011d9f58->FUN_004bdb40();
            _g_thePlayer->UnequipItem(g_011d9f58->FUN_0044ddc0(), g_011d9f58->FUN_00726070(),
                                       *g_011d9f58->FUN_00559450()->FUN_006815c0(), 0, 0, 1);
            DAT_011d9f40 = 1;
        }
        float condition = g_011d9f58->FUN_004bcdb0(1) / 100.0;
        ((Menu78*)DAT_011d9f54)->unk38->Set(0x1004, condition, true);
        ((Menu78*)DAT_011d9f54)->unk38->Set(0xfa3, 1);
        if (g_011d9f58->FUN_0044ddc0()->FUN_00401170() == 40)
        {
            ((Menu78*)DAT_011d9f54)->unk3c->Set(DAT_011d9f3c, g_011d2c7c.FUN_00403df0(), true);
            ((Menu78*)DAT_011d9f54)
                ->unk3c->Set(
                    DAT_011d9f44,
                    (int)FUN_004bd510(GetWeaponDamage(g_011d9f58->FUN_0044ddc0(), condition, pEntry, 0), 1.0f));
            ((Menu78*)DAT_011d9f54)
                ->unk28->Set(0xfc4, ((Name78*)((char*)g_011d9f58->FUN_0044ddc0() + 0x30))->FUN_00408da0(), true);
        }
        else
        {
            ((Menu78*)DAT_011d9f54)->unk3c->Set(DAT_011d9f3c, g_011d20c4.FUN_00403df0(), true);
            ((Menu78*)DAT_011d9f54)
                ->unk3c->Set(DAT_011d9f44, (int)FUN_00476b20(FUN_00646360(
                                               (int)g_011d9f58->FUN_0044ddc0()->FUN_004be060(), condition)));
        }
        if (pEntry)
        {
            ((Menu78*)DAT_011d9f54)->unk60.clear();
            ((Menu78*)DAT_011d9f54)->unk34->Set(0xfcc, g_011d9f58->GetIconFilename(0), true);
            PopulateModListScreen();
        }
        ((Menu78*)DAT_011d9f54)->unk60.FUN_007314c0(UpdateTileFromObject, 0, 0x7fffffff);
        ((Menu78*)DAT_011d9f54)->unk60.sort(CompareItemVisibility);
        if (pEntry && FUN_004b71d0())
            ((Manager78*)FUN_004b7210())->FUN_00715860(((Menu78*)DAT_011d9f54)->unk60.selected(1, 0, 0xfc3, 1));
        ((Menu78*)DAT_011d9f54)->notify(15, ((Menu78*)DAT_011d9f54)->unk60.count());
        if (pEntry)
        {
            FUN_007046f0(1, 0, 0);
            ((Manager78*)FUN_004b7210())->unk4d4.FUN_00718630(6, FUN_00783640(), 500);
        }
    }
}

struct xValT
{
    float GetFloat();
};
class xListT
{
  public:
    virtual void v0();
    virtual xValT* GetValue(int iKey);
    int m_ai[3];
    struct xEntryT* GetSelected();
};
class xDescT
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual const char* GetText(int a, unsigned int uiType);
};
struct xFormT
{
    int m_aiPad[0x1d];
    xDescT m_kDesc;
};
struct xEntryT
{
    xFormT* GetForm();
    const char* GetIcon(int i);
};
struct xTileT
{
    void Set(int iKey, const char* pStr, bool b);
    void Set(int iKey, float f, bool b);
};
struct xPipT
{
    void Shake(int i, float a, float b, bool c);
};
struct xProxyT
{
    xPipT* GetPipboyManagerInstance();
};
struct xHolderT
{
    int m_aiPad[0xd];
    xTileT* m_pTile;
};
struct xSetting
{
    float* Float();
};
extern xSetting xS_b2f0;
extern xSetting xS_b358;
extern int xLastValue;
extern void* xShowDesc;
extern xHolderT* xIconHolder;
xProxyT* xGetProxy();
int xTraitID(const char* p);

class xInvMenu
{
  public:
    int m_aiPad[0x15];
    xTileT* m_pTile54;
    int m_i58;
    xTileT* m_pTile5c;
    xListT m_kList;
    void FUN_00783ed0(int m_uiSoundID, int iUnused);
};

// Updates the selected entry's display, shakes the pip manager when the queried value changes, and sets description and icon tiles when available.
// @fnv 0x00783ed0
void xInvMenu::FUN_00783ed0(int m_uiSoundID, int iUnused)
{
    switch (m_uiSoundID)
    {
    case 15: {
        float qfTOqo[18];
        xEntryT* qsSDDgz = m_kList.GetSelected();
        int qrEZrs = qsSDDgz ? (int)m_kList.GetValue(0xfac)->GetFloat() : 0;
        if (xLastValue != qrEZrs)
        {
            xGetProxy()->GetPipboyManagerInstance()->Shake(
                0, xLastValue < qrEZrs ? *xS_b2f0.Float() : -*xS_b2f0.Float(), *xS_b358.Float(), true);
            xLastValue = qrEZrs;
        }
        m_pTile5c->Set(0xfc4, "", true);
        if (qsSDDgz && xShowDesc)
        {
            xFormT* qxQHW = qsSDDgz->GetForm();
            m_pTile5c->Set(0xfc4, qxQHW->m_kDesc.GetText(0, 0x43534544), true);
            xIconHolder->m_pTile->Set(0xfcc, qsSDDgz->GetIcon(0), true);
            m_pTile54->Set(xTraitID("_line_alpha"), 255.0f, true);
        }
    }
    break;
    }
}

struct Entry;
struct Extras;
struct ExtraNode
{
    Extras*& Value();
    ExtraNode* Next();
};
struct Extras
{
    void Add(Extras* const&);
};
struct Entry
{
    Entry(ModEntry*, int);
    ModEntry* Object();
    int Count();
    Extras* ExtraList();
    const char* Name();
    int unk00;
    int unk04;
    int unk08;
};
struct EntryNode
{
    EntryNode();
    ~EntryNode();
    Entry*& Value();
    EntryNode* Next();
    Entry* data;
    EntryNode* next;
};
struct Inventory
{
    static Inventory* Get(ModObject*);
    void Collect(ModEntry*, EntryNode*);
};
extern ModObject* gPlayer;
struct TileWorkList
{
    void* First();
    Tile_Set_Helper*& At(void*);
};
struct Row
{
    int unk00;
    TileWorkList children;
    void Set(int, int);
};
struct Rows
{
    Row* Add(Entry*, const char*, int, int);
};
struct Root
{
    Root* GetRoot();
    struct Text* Find(const char*);
};
struct Text
{
    void Set(int, const char*, bool);
};
struct Screen
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
    Text* label38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    Text* label4c;
    int unk50;
    Text* label54;
    Text* label58;
    int unk5c;
    Rows rows;
    Root* GetRoot();
};
struct Setting
{
    const char* String();
};
extern Setting localeSetting, labelSetting, otherSetting, thirdSetting, fourthSetting;
int Compare(const char*, const char*);

// Adds rows for flagged entries and collected inventory items, then updates several labels when the locale comparison is nonzero.
// @fnv 0x007840f0
void __cdecl PopulateModListScreen()
{
    if (!DAT_011d9f58)
        return;
    ModEntry* base3 = DAT_011d9f58->FUN_0044ddc0();
    ModEntry* mod4 = 0;
    ModEntry* kMod2_2 = 0;
    ModEntry* mod5 = 0;
    char aFlags = DAT_011d9f58->FUN_004bd820();
    if (aFlags)
    {
        Row* row = 0;
        Entry* entry = 0;
        if (aFlags & 1)
        {
            mod4 = base3->FUN_004bd570(1);
            entry = new Entry(mod4, 1);
            row = ((Screen*)_DAT_011d9f54)->rows.Add(entry, entry->Name(), 0, 0);
            row->Set(DAT_011d9f4c, 1);
            row->children.At(row->children.First())->Set(4003, 1);
        }
        if (aFlags & 2)
        {
            kMod2_2 = base3->FUN_004bd570(2);
            entry = new Entry(kMod2_2, 1);
            row = ((Screen*)_DAT_011d9f54)->rows.Add(entry, entry->Name(), 0, 0);
            row->Set(DAT_011d9f4c, 1);
            row->children.At(row->children.First())->Set(4003, 1);
        }
        if (aFlags & 4)
        {
            mod5 = base3->FUN_004bd570(4);
            entry = new Entry(mod5, 1);
            row = ((Screen*)_DAT_011d9f54)->rows.Add(entry, entry->Name(), 0, 0);
            row->Set(DAT_011d9f4c, 1);
            row->children.At(row->children.First())->Set(4003, 1);
        }
    }
    EntryNode listVal;
    Inventory* inv3 = Inventory::Get(gPlayer);
    inv3->Collect(DAT_011d9f58->FUN_0044ddc0(), &listVal);
    for (EntryNode* node6 = &listVal; node6 && node6->Value(); node6 = node6->Next())
    {
        Row* row = 0;
        Entry* entry = 0;
        for (int index7 = 0; index7 < node6->Value()->Count(); ++index7)
        {
            entry = node6->Value();
            if (index7 == 0)
            {
                if (entry->Object() != mod4 && entry->Object() != kMod2_2 && entry->Object() != mod5)
                {
                    row = ((Screen*)_DAT_011d9f54)->rows.Add(entry, entry->Name(), 0, 0);
                    row->Set(DAT_011d9f4c, 1);
                }
            }
            else if (entry->Object() != mod4 && entry->Object() != kMod2_2 && entry->Object() != mod5)
            {
                entry = new Entry(node6->Value()->Object(), 1);
                for (ExtraNode* extra6 = (ExtraNode*)node6->Value()->ExtraList(); extra6 && extra6->Value();
                     extra6 = extra6->Next())
                {
                    entry->ExtraList()->Add(extra6->Value());
                }
                row = ((Screen*)_DAT_011d9f54)->rows.Add(entry, entry->Name(), 0, 0);
                row->Set(DAT_011d9f4c, 1);
            }
        }
    }
    if (Compare(localeSetting.String(), "ENGLISH"))
    {
        ((Screen*)_DAT_011d9f54)->GetRoot()->Find("IMM_Headline_Title")->Set(4036, labelSetting.String(), true);
        ((Screen*)_DAT_011d9f54)->label38->Set(DAT_011d9f3c, otherSetting.String(), true);
        ((Screen*)_DAT_011d9f54)->label4c->Set(DAT_011d9f3c, otherSetting.String(), true);
        ((Screen*)_DAT_011d9f54)->label54->Set(4036, thirdSetting.String(), true);
        ((Screen*)_DAT_011d9f54)->label58->Set(4036, fourthSetting.String(), true);
    }
}
