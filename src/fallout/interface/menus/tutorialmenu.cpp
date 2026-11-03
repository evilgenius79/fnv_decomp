
// src/fallout/interface/menus/tutorialmenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/tutorialmenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_007e8e20_shell
{
    void ShowPageByIndex(int);
    void FUN_007e8e20();
};

// @fnv 0x007e8e20
void FUN_007e8e20_shell::FUN_007e8e20()
{
    ShowPageByIndex(*(int*)(this + 0x48) + 1);
}

struct TutorialMenu
{
    bool FUN_007e8e60(int aiButton, float afValue);
};

// @fnv 0x007e8e60
bool TutorialMenu::FUN_007e8e60(int aiButton, float afValue)
{
    bool bhandled = false;
    return bhandled;
}

struct FUN_007e8e40_shell : FUN_007e8e20_shell
{
    void DecrementAndDispatch();
};

// @fnv 0x007e8e40
void FUN_007e8e40_shell::DecrementAndDispatch()
{
    ShowPageByIndex(((int*)this)[0x48 / 4] - 1);
}

struct Tile
{
    void Set(int, int);
};
struct Menu
{
    void LoadMenuData();
    void FUN_00a1d9e0();
};
struct FORenderedMenu;
FORenderedMenu* __cdecl FUN_00707ad0();
void __cdecl HandleBackAction();
extern Menu* DAT_011db088;

struct BSSimpleList
{
    void* FUN_00726070();
};

// @fnv 0x007e8d60
void FUN_007e8d60()
{
    if (DAT_011db088)
    {
        reinterpret_cast<Tile*>(reinterpret_cast<BSSimpleList*>(DAT_011db088)->FUN_00726070())->Set(0x1772, 1);
        if (FUN_00707ad0())
            DAT_011db088->FUN_00a1d9e0();
        else
            DAT_011db088->LoadMenuData();
        HandleBackAction();
    }
}

struct InterfaceH
{
    static bool __cdecl GetSelectedTargetIndex(int);
};
struct Interface
{
    enum enumGamepadButtons
    {
        E10 = 10
    };
};
struct InterfaceManager
{
    static void __cdecl SendGamepadButton(Interface::enumGamepadButtons);
};
void* __cdecl FUN_004b7210();
void __cdecl FUN_007e8d60();
struct VHack
{
    virtual int v0();
    virtual int v1();
    virtual int v2();
    virtual int v3();
    virtual int v4();
    virtual int v5();
    virtual int v6();
    virtual int v7();
    virtual int v8();
    virtual int v9();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
};
struct TMenu
{
    bool HandleGamepadButton(int aiButton, float afValue);
};
// @fnv 0x007e8e80
bool TMenu::HandleGamepadButton(int aiButton, float afValue)
{
    if (InterfaceH::GetSelectedTargetIndex(((VHack*)this)->v13()) && aiButton == 10)
    {
        FUN_004b7210();
        InterfaceManager::SendGamepadButton((Interface::enumGamepadButtons)10);
        FUN_007e8d60();
        return true;
    }
    else
    {
        return false;
    }
}

namespace fnv_007e9010 {
struct Tile
{
    void Set(int, int);
};
struct FUN_007e9010_Owner
{
    char _pad0[44];
    Tile* tileA;
    Tile* tileB;
    char _pad1[20];
    unsigned int m_iMapDisplayMode;
    unsigned int m_uiPageCount;
    void FUN_007e9010();
};
// @fnv 0x007e9010
void FUN_007e9010_Owner::FUN_007e9010()
{
    tileB->Set(0xFAF, 0 < m_iMapDisplayMode);
    tileA->Set(0xFAF, m_iMapDisplayMode + 1 < m_uiPageCount);
}
}  // namespace fnv_007e9010

struct FUN_007e8db0_shell : FUN_007e8e40_shell
{
    Tile* m_pTiles[32];
    void FUN_007e8db0(int aiID, Tile* apTarget);
};

// Resolves apTarget from the tile array at offset 0x28 when null and aiID is 0-7, then dispatches on aiID to one of three handlers.
// @fnv 0x007e8db0
void FUN_007e8db0_shell::FUN_007e8db0(int aiID, Tile* apTarget)
{
    if (!apTarget && aiID >= 0 && aiID < 8)
        apTarget = ((Tile**)((char*)this + 0x28))[aiID];
    switch (aiID)
    {
    case 1:
        FUN_007e8e20();
        break;
    case 2:
        DecrementAndDispatch();
        break;
    case 3:
        FUN_007e8d60();
        break;
    }
}

struct MenuValueField
{
    char* __thiscall FUN_00408da0();
};
struct MenuStringReader
{
    virtual void Read0();
    virtual void Read1();
    virtual void Read2();
    virtual void Read3();
    virtual char* ReadString(int unused, unsigned int recordType);
};
struct MenuRecord
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    MenuValueField value18;
    int unk1c;
    int unk20;
    MenuStringReader record24;
};
struct MenuTileField
{
    void __thiscall FUN_00a01350(unsigned int property, char* text, int forceUpdate);
    void __thiscall FUN_00700320(unsigned int property, int matched);
    void __thiscall FUN_00a012d0(void* value, float fade, int flags);
};
extern char str_010702d8[];
extern "C" void* __cdecl TraitNameToIDAdd(const char* descriptor, int index);
struct TutorialMenuView
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
    MenuTileField* text28;
    int unk2c;
    int unk30;
    int unk34;
    MenuTileField* text38;
    int unk3c;
    MenuTileField* text40;
    void __thiscall ApplyRecordToTiles(MenuRecord* record);
};
// @fnv 0x007e9060
void TutorialMenuView::ApplyRecordToTiles(MenuRecord* record)
{
    char* description;
    if (!record)
        return;
    if (text38 != 0)
    {
        text38->FUN_00a01350(0xFC4, record->value18.FUN_00408da0(), 1);
    }
    if (text28 != 0)
    {
        description = record->record24.ReadString(0, 0x43534544);
        if (description != 0)
        {
            text28->FUN_00700320(0xFBE, description[0] == '<');
            text28->FUN_00a01350(0xFC4, description, 1);
        }
    }
    if (text40 != 0)
    {
        text40->FUN_00a012d0(TraitNameToIDAdd(str_010702d8, -1), 0.0f, 0);
    }
}

struct BSStringT
{
    char* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    BSStringT();
    ~BSStringT();
    operator const char*() const;
};
int __cdecl FUN_00406f60(BSStringT* apStr, const char* apFmt, ...);
void __cdecl FNV_Warning(unsigned int aeType, const char* apFmt, ...);

class TESForm
{
  public:
    virtual ~TESForm();
};
class BGSMessage : public TESForm
{
};

struct HelpTile
{
    void Set(int aeValue, const char* apString, bool abPropagate);
};

struct HelpListNode
{
    TESForm** Item();
    HelpListNode* Next();
};

struct HelpMenuShell
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
    HelpTile* pPageTile;
    int unk40;
    int unk44;
    unsigned int uiCurrentPage;
    unsigned int uiPageCount;
    HelpListNode* pPages;
    void ShowPage(BGSMessage* apPage);
    void Refresh();
    void ShowPageByIndex(unsigned int auiPage);
};

// Sets the current help page index, updates the page counter tile, walks the page list to the requested page, shows it and refreshes the menu.
// @fnv 0x007e8ed0
void HelpMenuShell::ShowPageByIndex(unsigned int auiPage)
{
    if (auiPage < uiPageCount)
    {
        BSStringT kText;
        uiCurrentPage = auiPage;
        FUN_00406f60(&kText, "%d/%d", auiPage + 1, uiPageCount);
        pPageTile->Set(0xfc4, kText, true);
        HelpListNode* pPageNode = pPages;
        while (pPageNode && auiPage--)
        {
            pPageNode = pPageNode->Next();
        }
        if (!pPageNode)
        {
            FNV_Warning(0x12, "End of Help Manual reached while searching for page %d in help manual.", auiPage);
            return;
        }
        ShowPage(dynamic_cast<BGSMessage*>(*pPageNode->Item()));
        Refresh();
    }
}

struct TileX;
struct HelpListNode;
struct IMF;
struct TileNU;

class AA
{
  public:
    virtual ~AA();
};
AA* __cdecl FUN_00a09030(int);
int __cdecl FUN_007cc6d0();

struct TileMenu
{
    int unk;
};

struct SettingX
{
    const char* String();
};
extern SettingX DAT_011d2340;
extern SettingX DAT_011d34b0;
extern SettingX DAT_011d4468;
extern SettingX DAT_011d22b0;
extern float DAT_01023cd8;
extern char str_01077ba4[];

struct StrMem : BSStringT
{
    StrMem();
    ~StrMem();
};

class BGSListForm : public TESForm
{
  public:
    HelpListNode* FUN_00500940();
};
TESForm* __cdecl LookupFormByID(unsigned int auID);

struct TForm2
{
    bool IsInCombat();
};

struct IMF
{
    TileX* FUN_00586150();
    TileX* FUN_0045cd60();
};

struct TileX
{
    TileX* ReadFile(const char* apFile);
    Menu* FUN_00a03c90();
    float FUN_00a011b0(int aiValue);
    void SetString(int aiID, const char* apText, bool abFlag);
    void SetInt(int aiID, int aiValue);
    void Set(int aiID, float afValue, bool abFlag);
};

void* __cdecl FUN_00ec43fb(void* apObject, long alVfDelta, void* apSrcType, void* apDstType, int aiIsRef);
float __cdecl FUN_00a01530();

class HMenuX
{
  public:
    virtual ~HMenuX();
    virtual void d01();
    virtual void d02();
    virtual void d03();
    virtual void d04();
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual void d08();
    virtual void d09();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual int vGet();
    int pad0[10];
    TileX* t2c;
    TileX* t30;
    TileX* t34;
    int pad1;
    TileX* t3c;
    int pad2;
    TileX* t44;
    unsigned int u48;
    unsigned int u4c;
    HelpListNode* pPages;
    void FUN_00a1dc70(void* apMenu, bool abFlag);
    void FUN_00a1dc20(int aiValue);
    void ApplyRecordToTiles(void* apTile);
    void FUN_007e9010();
};

struct HelpListNode;

bool __cdecl FUN_004b71d0();

// @fnv 0x007e8890
bool InitTutorialMenu(TESForm* apMsg, bool aFlag)
{
    AA* p = FUN_00a09030(FUN_007cc6d0());
    if (p)
        delete p;

    TileX* pTile = ((IMF*)FUN_004b7210())->FUN_00586150()->ReadFile(str_01077ba4);
    DAT_011db088 = pTile ? pTile->FUN_00a03c90() : 0;

    if (DAT_011db088 != 0 && ((HMenuX*)DAT_011db088)->vGet() == FUN_007cc6d0())
    {
        ((HMenuX*)DAT_011db088)
            ->FUN_00a1dc70(FUN_00ec43fb(pTile, 0, (void*)&typeid(Tile), (void*)&typeid(TileMenu), 0), 0);

        if (pTile->FUN_00a011b0(0xfa7) == 6006.0 || pTile->FUN_00a011b0(0xfa7) == 102.0)
            pTile->Set(0xfad, FUN_00a01530(), 1);

        ((HMenuX*)DAT_011db088)->t44->SetString(0xfc4, DAT_011d2340.String(), 1);

        if (aFlag)
        {
            BGSListForm* pForm = FUN_004b71d0() ? dynamic_cast<BGSListForm*>(LookupFormByID(0x165u))
                                                : dynamic_cast<BGSListForm*>(LookupFormByID(0x163u));
            if (pForm)
            {
                ((HMenuX*)DAT_011db088)->pPages = pForm->FUN_00500940();
                if (apMsg == 0)
                    apMsg = dynamic_cast<BGSMessage*>(*((HMenuX*)DAT_011db088)->pPages->Item());
            }
            ((HMenuX*)DAT_011db088)->t2c->SetString(0xfc4, DAT_011d34b0.String(), 1);
            ((HMenuX*)DAT_011db088)->t30->SetString(0xfc4, DAT_011d4468.String(), 1);
        }
        else
        {
            ((HMenuX*)DAT_011db088)->t2c->SetInt(0xfa3, 0);
            ((HMenuX*)DAT_011db088)->t30->SetInt(0xfa3, 0);
        }

        ((HMenuX*)DAT_011db088)->t34->SetString(0xfc4, DAT_011d22b0.String(), 1);

        if (apMsg == 0)
            FNV_Warning(0x12, "Warning:  Unable to find valid starting message for Tutorial Menu.");

        ((HMenuX*)DAT_011db088)->u4c = 0;
        ((HMenuX*)DAT_011db088)->u48 = 0;
        HelpListNode* node5;
        bool found2 = false;
        node5 = ((HMenuX*)DAT_011db088)->pPages;
        while (node5 != 0 && *node5->Item() != 0)
        {
            if (!found2 && *node5->Item() == apMsg)
            {
                ((HMenuX*)DAT_011db088)->u48 = ((HMenuX*)DAT_011db088)->u4c;
                found2 = true;
            }
            ((HMenuX*)DAT_011db088)->u4c = ((HMenuX*)DAT_011db088)->u4c + 1;
            node5 = node5->Next();
        }

        if (found2)
        {
            StrMem str;
            FUN_00406f60(&str, "%d/%d", ((HMenuX*)DAT_011db088)->u48 + 1, ((HMenuX*)DAT_011db088)->u4c);
            ((HMenuX*)DAT_011db088)->t3c->SetString(0xfc4, str, 1);
        }
        else
        {
            ((HMenuX*)DAT_011db088)->t3c->SetInt(0xfa3, 0);
            ((HMenuX*)DAT_011db088)->u4c = 0;
        }

        if (apMsg != 0)
        {
            ((HMenuX*)DAT_011db088)->ApplyRecordToTiles(apMsg);
            ((HMenuX*)DAT_011db088)->FUN_007e9010();
            ((TForm2*)DAT_011db088)->IsInCombat();
            ((IMF*)FUN_004b7210())->FUN_0045cd60()->Set(0xfa9, DAT_01023cd8, 1);
            ((HMenuX*)DAT_011db088)->FUN_00a1dc20(0);
            return true;
        }
        else
        {
            delete (HMenuX*)DAT_011db088;
            return false;
        }
    }
    else
    {
        if (DAT_011db088 != 0 && ((BSSimpleList*)DAT_011db088)->FUN_00726070())
            delete (HMenuX*)DAT_011db088;
    }
    return false;
}
