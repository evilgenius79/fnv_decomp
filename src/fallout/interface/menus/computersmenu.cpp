
// src/fallout/interface/menus/computersmenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/computersmenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Tile
{
    Tile* pParent;
};

struct ComputersMenu
{
    char _base[0x28];
    Tile* m_pTiles[64];
    void FUN_00754c00(int aiID, Tile* apTile);
};

// Stores apTile into the tile slot at index aiID when aiID is in [0, 0x10).
// @fnv 0x00754c00
void ComputersMenu::FUN_00754c00(int aiID, Tile* apTile)
{
    if (aiID >= 0 && aiID < 0x10)
    {
        m_pTiles[aiID] = apTile;
    }
}

namespace fnv_00757a10 {
struct ComputersMenu
{
    int __thiscall GetMenuId();
};

// @fnv 0x00757a10
int __thiscall ComputersMenu::GetMenuId()
{
    return 0x421;
}
}  // namespace fnv_00757a10

// @fnv 0x00757e20
int FUN_00757e20()
{
    return 0x421;
}

struct FUN_00757e80_shell
{
    unsigned char IsFlagBitSet();
};

// @fnv 0x00757e80
unsigned char FUN_00757e80_shell::IsFlagBitSet()
{
    return ((*(unsigned char*)((unsigned char*)this + 0xa5) & 4) != 0);
}

struct FUN_00758390_shell
{
    signed char m_74;
    bool __thiscall FUN_00758390();
};

// @fnv 0x00758390
bool __thiscall FUN_00758390_shell::FUN_00758390()
{
    return (((signed char*)this)[0x74 / sizeof(signed char)] & 2) != 0;
}

struct FUN_00758a60_shell
{
    char m_74;
    bool __thiscall FUN_00758a60();
};

// @fnv 0x00758a60
bool __thiscall FUN_00758a60_shell::FUN_00758a60()
{
    return (((char*)this)[0x74] & 4) != 0;
}

namespace fnv_007596a0 {
struct Tile
{
    void Set(int a, int b);
};
extern int __cdecl GetTileValueID(const char*, int);
extern char $SG7172[];

// @fnv 0x007596a0
void __cdecl FUN_007596a0(Tile* apTile, void* apMenuItem)
{
    if (apTile)
        apTile->Set(GetTileValueID($SG7172, -1), 1);
}
}  // namespace fnv_007596a0

void __cdecl _Deallocate(void*);
struct S757a20
{
    void __thiscall FUN_00757a50();
    void* __thiscall FUN_00757a20(unsigned int);
};
// Calls FUN_00757a50, then if bit 0 of flags is set calls _Deallocate on this, and returns this.
// @fnv 0x00757a20
void* __thiscall S757a20::FUN_00757a20(unsigned int flags)
{
    FUN_00757a50();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_00757e30_Class
{
    char _pad[0x28];
    Tile* arr[16];
    bool __thiscall HasAllTiles(int* p);
};
// Checks that all 16 entries of arr are non-null, returning 0 on the first null and 1 otherwise.
// @fnv 0x00757e30
bool __thiscall FUN_00757e30_Class::HasAllTiles(int* piIndex)
{
    for (*piIndex = 0; *piIndex < 0x10; (*piIndex)++)
    {
        if (arr[*piIndex] == 0)
            return 0;
    }
    return 1;
}

struct FUN_00758350_shell
{
    char m_6c[4];
    bool __thiscall FUN_00758350();
};
// Returns true when the int at offset 0x6c is nonzero and bit 0 of the byte at offset 0x74 is set.
// @fnv 0x00758350
bool __thiscall FUN_00758350_shell::FUN_00758350()
{
    return *(int*)((char*)this + 0x6c) && ((*(signed char*)((char*)this + 0x74) & 1));
}

struct Helper98
{
    void __thiscall _ref_0063f7b0();
    int* __thiscall _ref_006815c0();
};
struct DispHelper
{
    void __thiscall FUN_007586e0(int);
};
void __cdecl RefreshF57EA0TerminalMenu();
struct FUN_00758a80_shell
{
    void __thiscall FUN_00758a80();
};
// @fnv 0x00758a80
void __thiscall FUN_00758a80_shell::FUN_00758a80()
{
    ((Helper98*)((char*)this + 0x98))->_ref_0063f7b0();
    *(int*)((char*)this + 0xA8) = *(((Helper98*)((char*)this + 0x98))->_ref_006815c0());
    if (*(int*)((char*)this + 0xA8) != 0)
        ((DispHelper*)this)->FUN_007586e0(0);
    else
        RefreshF57EA0TerminalMenu();
}

struct StartMenu
{
    char const* GetMenuTitle();
};
extern StartMenu* DAT_01189e94[];
struct Host
{
    char _pad[0xA6];
    unsigned char mA6;
    char const* __thiscall FUN_00758fe0();
};
// @fnv 0x00758fe0
char const* __thiscall Host::FUN_00758fe0()
{
    return mA6 < 10 ? DAT_01189e94[mA6]->GetMenuTitle() : 0;
}

struct GlobalObject_0048f200
{
    GlobalObject_0048f200();
};
GlobalObject_0048f200::GlobalObject_0048f200()
{}
struct FUN_00759760_shell : GlobalObject_0048f200
{
    FUN_00759760_shell();
};
// @fnv 0x00759760
FUN_00759760_shell::FUN_00759760_shell()
{}

struct S_7597c0
{
    int __thiscall FUN_007597c0(int);
};
extern S_7597c0* DAT_011d9338;
// Calls FUN_007597c0(1) on DAT_011d9338 if non-null, then sets DAT_011d9338 to null.
// @fnv 0x00759780
void FUN_00759780()
{
    S_7597c0* b = DAT_011d9338;
    S_7597c0* a = b;
    a ? a->FUN_007597c0(1) : 0;
    DAT_011d9338 = 0;
}

void __cdecl operator delete(void*);
struct FUN_007597c0_shell
{
    void FUN_007597f0();
    void* __thiscall FUN_007597c0(unsigned int flags);
};
// Calls FUN_007597f0, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x007597c0
void* __thiscall FUN_007597c0_shell::FUN_007597c0(unsigned int flags)
{
    FUN_007597f0();
    if (flags & 1)
        operator delete(this);
    return this;
}

namespace fnv_007597f0 {
struct GlobalObject_0048f200
{
    ~GlobalObject_0048f200();
};
struct FUN_00759850_owner
{
    void __thiscall FUN_00759850();
};
struct FUN_007597f0 : GlobalObject_0048f200
{
    ~FUN_007597f0();
};
// Destructor that calls FUN_00759850 on this object before the base GlobalObject_0048f200 destructor runs.
// @fnv 0x007597f0
FUN_007597f0::~FUN_007597f0()
{
    ((FUN_00759850_owner*)this)->FUN_00759850();
}
}  // namespace fnv_007597f0

struct ArrHelper
{
    bool FUN_0076b610() const;
};
struct ScriptObj
{
    int FUN_007598a0(int);
};
struct ListBase
{
    ScriptObj* RemoveHead();
};
struct Holder
{
    void FUN_00759850();
};
// @fnv 0x00759850
void Holder::FUN_00759850()
{
    while (!((ArrHelper*)this)->FUN_0076b610())
    {
        ScriptObj* pB = ((ListBase*)this)->RemoveHead();
        ScriptObj* pA = pB;
        pA ? pA->FUN_007598a0(1) : 0;
    }
}

void Deallocate(void*);
struct FUN_007598a0_shell
{
    void __thiscall FUN_00726cf0();
    void* __thiscall FUN_007598a0(unsigned int flags);
};
// Calls FUN_00726cf0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x007598a0
void* FUN_007598a0_shell::FUN_007598a0(unsigned int flags)
{
    FUN_00726cf0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct Flt
{
    operator unsigned int();
};
struct TL
{
    Tile*& GetNext(void*&);
};
struct NoArgumentMethodObject
{
    void FUN_00700110();
};
struct TileProcessor
{
    void ProcessAllTiles();
};
// @fnv 0x00759f50
void TileProcessor::ProcessAllTiles()
{
    void* piter = (void*)((Flt*)this)->operator unsigned int();
    while (piter)
    {
        ((NoArgumentMethodObject*)((TL*)this)->GetNext(piter))->FUN_00700110();
    }
}

void __cdecl operator delete(void*);

struct FUN_0075aa20_shell
{
    void __thiscall FUN_0075a060();
    void* __thiscall FUN_0075aa20(unsigned int flags);
};

// Calls FUN_0075a060, then deletes this if flags has bit 0 set, and returns this.
// @fnv 0x0075aa20
void* __thiscall FUN_0075aa20_shell::FUN_0075aa20(unsigned int flags)
{
    FUN_0075a060();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_007583b0_shell
{
    char _pad[0x74];
    signed char m_74;
    void __thiscall SetFlag4(bool aFlag);
};

// @fnv 0x007583b0
void FUN_007583b0_shell::SetFlag4(bool aFlag)
{
    if (aFlag)
        m_74 |= 4;
    else
        m_74 &= ~4;
}

struct BSSimpleList
{
    void __thiscall Sort(int(__cdecl* f)(void*, void*));
};

struct FUN_0075aa50_shell
{
    void __thiscall ResetAndProcessNodes();
};

struct FUN_0075a5e0_shell
{
    char _pad[4];
    BSSimpleList m_kNode;
    void __thiscall FUN_0075a5e0(int(__cdecl* f)(void*, void*));
};

// Sorts the list using the given comparison function, then calls ResetAndProcessNodes on this object.
// @fnv 0x0075a5e0
void __thiscall FUN_0075a5e0_shell::FUN_0075a5e0(int(__cdecl* f)(void*, void*))
{
    m_kNode.Sort(f);
    reinterpret_cast<FUN_0075aa50_shell*>(this)->ResetAndProcessNodes();
}

struct InterfaceH
{
    static bool __cdecl GetSelectedTargetIndex(int);
};
struct TV
{
    bool __thiscall IsVisible();
};
struct FUN_007583f0_shell
{
    char _pad[0x30];
    Tile* pTile30;
    char _pad2[0xbc - 0x34];
    const char* m_pText;
    bool __thiscall HandleButtonInput(int aiButton, float afValue);
};

// @fnv 0x007583f0
bool FUN_007583f0_shell::HandleButtonInput(int aiButton, float afValue)
{
    if (InterfaceH::GetSelectedTargetIndex(0x421))
    {
        switch (aiButton)
        {
        case 0xa:
            if (reinterpret_cast<TV*>(pTile30)->IsVisible())
            {
                m_pText = 0;
                (*(void(__thiscall**)(FUN_007583f0_shell*, int, int))(*(int*)this + 0xc))(this, 2, 0);
            }
            else
            {
                reinterpret_cast<FUN_00758a80_shell*>(this)->FUN_00758a80();
            }
            return true;
        }
    }
    return false;
}

struct FUN_00a01230_shell
{
    bool __thiscall IsTraitNonZero(int);
};

struct FUN_0075ab20_shell
{
    char _pad[0x0C];
    Tile* m_pTile;
    bool __thiscall IsTileTraitEnabled();
};

int __cdecl GetTileValueID(char const*, int);
extern int DAT_011d93d8;
extern int DAT_011d93dc;

// Returns true when m_pTile is set and its trait lookup for the cached "_enabled" trait index succeeds.
// @fnv 0x0075ab20
bool __thiscall FUN_0075ab20_shell::IsTileTraitEnabled()
{
    static int trait = GetTileValueID("_enabled", -1);

    return m_pTile && reinterpret_cast<FUN_00a01230_shell*>(m_pTile)->IsTraitNonZero(trait);
}

void* __cdecl operator new(unsigned int);

struct M788
{
    void __thiscall FUN_004ed8c0(void*);
};

struct GO
{
    operator unsigned int();
};

struct NiTPointerList
{
    void* __thiscall DereferenceIfNotNull(void*);
};

struct FUN_006ffe80_shell
{
    void __thiscall FUN_006ffe80(int, int);
};

struct FUN_00726db0_class
{
    bool __thiscall FUN_00726db0(bool);
};

struct FUN_00759eb0
{
    char _pad[0x2c];

    FUN_00759eb0(char const*);
};

struct FUN_007b5330_shell
{
    void __thiscall FUN_007b5330(void*, void*);
};

struct FUN_00759da0_shell : FUN_007b5330_shell
{
    void __thiscall InsertAtPosition(char const*, int, int, int);
};

// @fnv 0x00759da0
void FUN_00759da0_shell::InsertAtPosition(char const* aParam1, int aParam2, int aParam3, int aParam4)
{
    FUN_00759eb0* pNewObject = new FUN_00759eb0(aParam1);

    reinterpret_cast<FUN_006ffe80_shell*>(pNewObject)->FUN_006ffe80(aParam2, aParam3);

    if (aParam4 == -1)
    {
        reinterpret_cast<M788*>(this)->FUN_004ed8c0(reinterpret_cast<void*>(&pNewObject));
    }
    else
    {
        unsigned int pNode = reinterpret_cast<GO*>(this)->operator unsigned int();

        for (int i = 0; pNode != 0 && i < aParam4; ++i)
        {
            pNode = reinterpret_cast<unsigned int>(
                reinterpret_cast<NiTPointerList*>(this)->DereferenceIfNotNull(reinterpret_cast<void*>(pNode)));
        }

        if (pNode != 0)
        {
            this->FUN_007b5330(reinterpret_cast<void*>(pNode), reinterpret_cast<void*>(&pNewObject));
        }
        else
        {
            reinterpret_cast<M788*>(this)->FUN_004ed8c0(reinterpret_cast<void*>(&pNewObject));
        }
    }

    reinterpret_cast<FUN_00726db0_class*>(pNewObject)->FUN_00726db0(false);
}

struct MenuBase
{
    virtual ~MenuBase();
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
};
struct Obj68
{
    int a;
    ~Obj68();
};
struct SList
{
    void* head;
    void* next;
    void RemoveAll();
    ~SList();
};
struct BStr
{
    char* p;
    short len;
    short max;
    ~BStr();
};
struct SoundH
{
    int a;
    int b;
    int c;
    void Stop();
    void FUN_00ad8d10();
    ~SoundH();
};
struct SysColorMgr
{
    static SysColorMgr* GetSingleton();
    void ApplyToChild(int, int*);
};
extern int DAT_011d9334;
extern int DAT_011d934c;
void FUN_00759780();
struct FUN_00757a50 : MenuBase
{
    Obj68 m68;
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
    SList list98;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    BStr strB4;
    int unkbc;
    int unkc0;
    SoundH sounds[3];
    virtual ~FUN_00757a50();
};
// @fnv 0x00757a50
FUN_00757a50::~FUN_00757a50()
{
    DAT_011d9334 = 0;
    FUN_00759780();
    list98.RemoveAll();
    for (int i = 0; i < 3; i++)
    {
        sounds[i].Stop();
        sounds[i].FUN_00ad8d10();
    }
    SysColorMgr::GetSingleton()->ApplyToChild(3, &DAT_011d934c);
}

struct BlinkValue
{
    float FUN_00488d50();
    void FUN_00a0a270(float, bool);
};
struct TraitValueCollection
{
    float FUN_00a011b0(int);
    BlinkValue* FindTraitValue(int);
};
unsigned int __cdecl gm_GetTickCount();
struct BlinkMenu
{
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
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    TraitValueCollection* tile;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    BlinkValue* value;
    void UpdateBlink();
};
// Toggles the blink value between 0 and 1 once the tick interval elapses, or fetches the value from the tile if missing.
// @fnv 0x007585a0
void BlinkMenu::UpdateBlink()
{
    static unsigned int nextTick = 0;
    static float interval = tile->FUN_00a011b0(GetTileValueID("_blink_interval", -1));
    if (gm_GetTickCount() > nextTick && value)
    {
        value->FUN_00a0a270(value->FUN_00488d50() == 1.0 ? 0.0f : 1.0f, true);
        nextTick = gm_GetTickCount() + interval;
    }
    else if (!value)
    {
        value = tile->FindTraitValue(4003);
    }
}

struct BSStringT
{
    char* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    BSStringT(const char* apStr);
    ~BSStringT();
    BSStringT& operator+=(const char* apStr);
    operator const char*() const;
};

struct TileValue;

struct MenuTile
{
    void Set(int aiID, int aiValue);
    TileValue* GetValue(int aiID);
};

int __cdecl TraitNameToID(const char* apName, int aiDefault);

struct NoteFlags
{
    bool Check(int a, int b);
};

struct NoteEntry
{
    BSStringT kName;
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
    NoteFlags kFlags;
    bool IsUnread();
    void SetUnread(bool abUnread);
};

struct GameSettingString
{
    const char* String();
};
extern GameSettingString g_011d2cb8;

struct NoteTextSetter
{
    void Apply();
};
NoteTextSetter* __stdcall CreateNoteTextSetter(const char* apText, TileValue* apValue1, TileValue* apValue2,
                                               int aiIndex);

// Sets the tile's enabled state and text from a note entry, marking unread notes as read and applying the text setter when shown.
// @fnv 0x00759560
void UpdateNoteTile(MenuTile* apTile, NoteEntry* apEntry)
{
    if (apTile)
    {
        BSStringT kText("> ");
        int iState = 1;
        bool bShow = true;
        apTile->Set(TraitNameToID("_enabled", -1), 0);
        if (apEntry && apEntry->kFlags.Check(0, 0))
        {
            if (apEntry->IsUnread())
            {
                iState = 2;
                apEntry->SetUnread(false);
            }
            kText += apEntry->kName;
        }
        else if (!apEntry)
        {
            kText += g_011d2cb8.String();
        }
        else
        {
            bShow = false;
        }
        apTile->Set(0xfd6, iState);
        if (bShow)
        {
            CreateNoteTextSetter(kText, apTile->GetValue(0x1004), apTile->GetValue(0xfa3), -1)->Apply();
        }
    }
}

struct FUN_00759760_storage : FUN_00759760_shell
{
    int unk00;
    int unk04;
    int unk08;
};
// Allocates a FUN_00759760_storage instance into DAT_011d9338 if it is null, then returns DAT_011d9338.
// @fnv 0x007596d0
S_7597c0* __cdecl GetStorageSingleton()
{
    if (!DAT_011d9338)
        DAT_011d9338 = reinterpret_cast<S_7597c0*>(new FUN_00759760_storage());
    return DAT_011d9338;
}

// Destructor: release the entries, unregister this object, then the entry list member is destroyed.

class A060EntryList
{
  public:
    ~A060EntryList();
    void* m_pkHead;
    void* m_pkTail;
};

class FUN_0075a060;
void __cdecl A060Unregister(FUN_0075a060* pkObject);

class FUN_0075a060
{
  public:
    virtual ~FUN_0075a060();
    void Clear();

    A060EntryList m_kEntries;
};

// Clears the object's entry list, then unregisters the object via A060Unregister.
// @fnv 0x0075a060
FUN_0075a060::~FUN_0075a060()
{
    Clear();
    A060Unregister(this);
}

struct Shell
{
    bool __thiscall IsTileTraitEnabled();
    bool __thiscall ContainsKey(Tile* a1);
    void __thiscall UpdateHighlight();
};

struct ParamShell
{
    bool __thiscall IsTraitNonZero(int a1);
};

char const* __cdecl TraitNameToIDAdd(char const* a1, int a2);

class SetTileHelper
{
  public:
    char _pad[0x10];
    Tile* m_pTile10;

    bool FUN_0075a610(Tile* apTile);
};

// @fnv 0x0075a610
bool SetTileHelper::FUN_0075a610(Tile* apTile)
{
    if (((Shell*)this)->IsTileTraitEnabled() &&
        (apTile == 0 || (((Shell*)this)->ContainsKey(apTile) &&
                         ((ParamShell*)apTile)->IsTraitNonZero((int)TraitNameToIDAdd("_enabled", -1)))))
    {
        m_pTile10 = apTile;
        ((Shell*)this)->UpdateHighlight();
        return true;
    }
    else
    {
        return false;
    }
}

struct b9165Obj
{
    void __thiscall FUN_00700320(int a, int b);
};

struct b9165Inner
{
    b9165Obj* m_00;
    char unk04[4];
    unsigned char m_08;
};

struct b9165Ref
{
    b9165Inner* p;
};

struct b9165Node
{
    char unk00[0x18];
    b9165Ref* __thiscall FUN_006815c0();
    b9165Node* __thiscall FUN_00726070();
};

struct FUN_0075aa50_cls
{
    char unk00[4];
    b9165Node m_04;
    unsigned short m_1c;
    char unk1e[2];
    float m_20;
    void __thiscall AccumulateTileHeight(b9165Obj* p);
    void __thiscall UpdateScrollItems();
    void __thiscall UpdateHighlight();
    void __thiscall ResetAndProcessNodes();
};

// @fnv 0x0075aa50
void FUN_0075aa50_cls::ResetAndProcessNodes()
{
    m_1c = 0;
    m_20 = 0.0f;
    for (b9165Node* cur = this != 0 ? &m_04 : 0; cur != 0 && cur->FUN_006815c0()->p != 0; cur = cur->FUN_00726070())
    {
        if (cur->FUN_006815c0()->p->m_08 == 0)
        {
            cur->FUN_006815c0()->p->m_00->FUN_00700320(0xfac, m_1c++);
            AccumulateTileHeight(cur->FUN_006815c0()->p->m_00);
        }
    }
    UpdateScrollItems();
    UpdateHighlight();
}

// Refresh the terminal menu tile; if the rendered menu is showing this menu's scene, refresh the rendered terminal too.

class InterfaceManager;
class NiNode;

class F57EA0Tile
{
  public:
    void SetFloat(int m_iValueId, float fValue, bool bPropagate);
    void SetInt(int m_iValueId, int iValue);
    NiNode* GetNode();
};

class FORenderedMenu
{
  public:
    virtual ~FORenderedMenu();
    NiNode* GetSceneNode();
};

class FORenderedTerminal : public FORenderedMenu
{
  public:
    void Refresh();
};

class F57EA0Menu
{
  public:
    F57EA0Tile* GetTile();
    void Update();
};

extern F57EA0Menu* g_pF57EA0TerminalMenu;
extern const float g_fF57EA0TileDefault;

void F57EA0Prepare();
InterfaceManager* F57EA0GetInterfaceManager();
FORenderedMenu* __fastcall F57EA0GetRenderedMenu(InterfaceManager* pkManager);

// @fnv 0x00757ea0
void RefreshF57EA0TerminalMenu()
{
    if (g_pF57EA0TerminalMenu)
    {
        F57EA0Prepare();
        g_pF57EA0TerminalMenu->GetTile()->SetFloat(0xfc1, g_fF57EA0TileDefault, true);
        if (F57EA0GetRenderedMenu(F57EA0GetInterfaceManager()) &&
            F57EA0GetRenderedMenu(F57EA0GetInterfaceManager())->GetSceneNode() ==
                g_pF57EA0TerminalMenu->GetTile()->GetNode())
        {
            FORenderedTerminal* pkTerminal =
                dynamic_cast<FORenderedTerminal*>(F57EA0GetRenderedMenu(F57EA0GetInterfaceManager()));
            pkTerminal->Refresh();
        }
        g_pF57EA0TerminalMenu->GetTile()->SetInt(0x1772, 1);
        g_pF57EA0TerminalMenu->Update();
    }
}

namespace fnv_00758470 {
struct InterfaceManager;
struct S8840
{
    bool FUN_00718840(int);
};
struct InterfaceManager
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
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
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
    S8840 unk4d4;
};
InterfaceManager* FUN_004b7210();
struct HH84
{
    unsigned int GetReferenceFlags();
    void ProcessQueue();
};
struct Tile_Set_Helper
{
    void Set(int, int);
};
struct TESObjectREFR;
template <class T> struct ListBox
{
    void Traverse(void (*f)(Tile*, T), int, int);
};
void FUN_007596a0(Tile*, TESObjectREFR*);
unsigned int __cdecl gm_GetTickCount();
extern unsigned int DAT_011d93c4;
struct CompMenu
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
    Tile_Set_Helper* tile3c;
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
    ListBox<TESObjectREFR*> list68;
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
    unsigned int unka0;
    int unka4;
    int unka8;
    int unkac;
    int iStateB0;
    int unkb4;
    int unkb8;
    int unkbc;
    bool bC0;
    bool bC1;
    char unkc2;
    char unkc3;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    HH84* pE8;
    void FUN_00758470();
    void UpdateBlink();
    void RefreshDisplay();
};
// @fnv 0x00758470
void CompMenu::FUN_00758470()
{
    if ((bC0 && !FUN_004b7210()->unk4d4.FUN_00718840(0x18)) || unk24 == 2)
        return;
    pE8->ProcessQueue();
    UpdateBlink();
    if (!pE8->GetReferenceFlags())
    {
        if (iStateB0 < 2)
        {
            if (iStateB0 == 0)
            {
                DAT_011d93c4 = gm_GetTickCount() + 2000;
                iStateB0 = 1;
            }
            else if (iStateB0 == 1)
            {
                if (gm_GetTickCount() > DAT_011d93c4)
                    RefreshDisplay();
            }
        }
        else if (bC1)
        {
            list68.Traverse(FUN_007596a0, 0, 0x7fffffff);
            bC1 = 0;
        }
    }
    if (unka0 && gm_GetTickCount() > unka0)
    {
        unka0 = 0;
        tile3c->Set(0xfa3, 0);
    }
}
}  // namespace fnv_00758470

struct CHValue
{
    const char* GetString();
};

struct CHTile
{
    CHValue* GetValue(int aiTrait);
    CHValue* GetValueAlt(int aiTrait);
    bool IsVisible();
    void SetInt(int aiTrait, int aiValue);
};

struct CHString
{
    char* pString;
    unsigned short usLen;
    unsigned short usMaxLen;

    CHString();
    ~CHString();
    const char* CStr();
};

int __cdecl CHSprintf(CHString* apString, const char* apFormat, ...);
int __cdecl CHStricmp(const char* apString1, const char* apString2);
int __cdecl CHTraitNameToID(const char* apName, int aiDefault);

struct CHSetting
{
    const char* GetString();
};

struct CHUIntSetting
{
    unsigned int* Int();
};

struct CHCondition
{
    bool Evaluate(void* apSubject, int aiUnk);
};

struct CHChallenge;

struct CHListNode
{
    CHChallenge* pItem;
    CHListNode* pNext;

    CHChallenge** GetItem();
    CHListNode* GetNext();
};

struct CHDescription
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual const char* Get(CHChallenge* apForm, unsigned int auiChunk);
};

struct CHChallenge
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
    CHCondition kCondition;
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
    CHDescription kDescription;

    CHListNode* GetChallengeList();
    bool IsCompleted();
    const char* GetName();
    void SetSeen(bool abSeen);
};

struct CHSimpleList
{
    CHChallenge* pItem;
    CHListNode* pNext;

    void AddHead(CHChallenge*& arItem);
    CHListNode* GetNext();
};

struct CHListBox
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void Clear();
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

    CHTile* Insert(CHChallenge* apItem, int aiUnk1, int aiUnk2, int aiUnk3);
};

struct CHDisplay
{
    void Reset();
    void AddLine(const char* apText, CHValue* apValue1, CHValue* apValue2, int aiUnk);
};

extern CHUIntSetting g_kChallengeRateSetting;
extern CHSetting g_kNoChallengesSetting;
extern unsigned int g_uiChallengeUpdateMS;

struct CHMenu
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
    CHTile* pTile44;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    CHTile* pTile64;
    CHListBox kListBox;
    CHSimpleList kRecent;
    short unkA0;
    short unkA2;
    int unkA4;
    CHChallenge* pChallenge;
    void* pSubject;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    char unkC0;
    bool bRefreshed;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    CHDisplay* pDisplay;

    void FUN_007586e0(bool abAddRecent);
};

// Resets the display and list box, optionally adds the current challenge to the recent list, and rebuilds the challenge lines and tiles.
// @fnv 0x007586e0
void CHMenu::FUN_007586e0(bool abAddRecent)
{
    if (!pChallenge)
        return;

    CHString kText;
    pDisplay->Reset();
    kListBox.Clear();
    if (abAddRecent)
        kRecent.AddHead(pChallenge);
    g_uiChallengeUpdateMS = (*g_kChallengeRateSetting.Int() > 0) ? 1000 / *g_kChallengeRateSetting.Int() : 1000;

    const char* pDescription = pChallenge->kDescription.Get(pChallenge, 0x43534544);
    CHValue* pTextValue = pTile44->GetValue(0xfc4);
    if (pDescription && *pDescription && (!pTile44->IsVisible() || CHStricmp(pDescription, pTextValue->GetString())))
    {
        pTile64->SetInt(0xfa3, 0);
        pDisplay->AddLine(pDescription, pTextValue, pTile44->GetValueAlt(0xfa3), -1);
    }

    for (CHListNode* pIter = pChallenge->GetChallengeList(); pIter && *pIter->GetItem(); pIter = pIter->GetNext())
    {
        if ((*pIter->GetItem())->kCondition.Evaluate(pSubject, 0))
        {
            CHTile* pItemTile = kListBox.Insert(*pIter->GetItem(), 0, 0, 0);
            pItemTile->SetInt(CHTraitNameToID("_enabled", -1), 0);
            pItemTile->SetInt(0xfd6, (*pIter->GetItem())->IsCompleted() ? 2 : 1);
            CHSprintf(&kText, "%s%s", "> ", (*pIter->GetItem())->GetName());
            pDisplay->AddLine(kText.CStr(), pItemTile->GetValue(0x1004), pItemTile->GetValue(0xfa3), -1);
        }
        (*pIter->GetItem())->SetSeen(false);
    }

    if (kRecent.GetNext())
    {
        CHTile* pEmptyTile = kListBox.Insert(0, 0, 0, 0);
        pEmptyTile->SetInt(CHTraitNameToID("_enabled", -1), 0);
        CHSprintf(&kText, "%s%s", "> ", g_kNoChallengesSetting.GetString());
        pDisplay->AddLine(kText.CStr(), pEmptyTile->GetValue(0x1004), pEmptyTile->GetValue(0xfa3), -1);
    }
    bRefreshed = true;
}

class TESSound
{
  public:
    unsigned int GetFormID();
};

class BGSNote
{
  public:
    TESSound* FUN_005e9100();
};

class BSAudio
{
  public:
    static BSAudio* GetSingleton();
};

struct FUN_00483710
{
    int unk;
    int unkCur;
    int unkValue;

    ~FUN_00483710();
    bool Play(bool abFlag);
};

struct FUN_00ad73b0_t
{
    FUN_00483710 FUN_00ad73b0(unsigned int auiFormID, unsigned int auiFlags);
};

struct Shell_759030
{
    void PlayNoteSound(BGSNote* apNote);
};

// @fnv 0x00759030
void Shell_759030::PlayNoteSound(BGSNote* apNote)
{
    ((FUN_00ad73b0_t*)BSAudio::GetSingleton())
        ->FUN_00ad73b0(apNote->FUN_005e9100()->GetFormID(), 0x101)
        .Play(false);
}

struct Setting
{
    unsigned int* Int();
};
extern Setting g_011d4bb8;
extern int DAT_0119f278;
struct TextTile
{
    void Set(int, int);
    double Read(int);
    void* Find(int);
    void* GetValue(int);
};
struct TextString
{
    char* text;
    unsigned short len, capacity;
    bool Set(const char*);
    operator const char*() const;
    unsigned int Length() const;
};
struct TextLayout
{
    TextLayout(int, int, int, int, int);
    ~TextLayout();
    operator const char*() const;
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned int consumed;
    int unk1c;
    int unk20;
    int unk24;
};
struct TextFont
{
    float Height();
    void Format(const char*, TextLayout*);
};
struct TextFonts
{
    static TextFonts* Instance();
    TextFont* GetFont(int);
};
struct TextAnimator
{
    void Clear();
    void SetText(const char*, void*, void*, int);
};
struct TextSource;
struct TextSourceInterface
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual const char* GetText(TextSource*, int, int);
};
struct TextSource
{
    TextSourceInterface* GetInterface();
};
unsigned int __cdecl FUN_0042f5a0(unsigned int, unsigned int);
struct TextMenu
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
    TextTile* field2c;
    TextTile* field30;
    int field34;
    int field38;
    int field3c;
    int field40;
    TextTile* field44;
    int field48;
    int field4c;
    int field50;
    int field54;
    int field58;
    int field5c;
    TextTile* field60;
    int field64;
    int field68;
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
    int fielda0;
    int fielda4;
    int fielda8;
    int fieldac;
    int fieldb0;
    TextString buffer;
    const char* fieldbc;
    int fieldc0;
    int fieldc4;
    int fieldc8;
    int fieldcc;
    int fieldd0;
    int fieldd4;
    int fieldd8;
    int fielddc;
    int fielde0;
    int fielde4;
    TextAnimator* fielde8;

    void SetTextSource(TextSource*);
};

// Clears the animator, configures tiles, fetches and formats the source text into a layout, then advances the text pointer past the consumed characters.
// @fnv 0x007590c0
void TextMenu::SetTextSource(TextSource* source)
{
    fielde8->Clear();
    DAT_0119f278 = *g_011d4bb8.Int() > 0 ? 1000 / *g_011d4bb8.Int() : 1000;
    field2c->Set(0xfa3, 0);
    field30->Set(0xfa9, 0);
    field30->Set(0xfa3, 1);
    if (fieldbc == 0)
    {
        buffer.Set(source->GetInterface()->GetText(source, 0x4d414e54, 0));
        fieldbc = buffer;
    }
    int lines = (int)(field60->Read(0xfbc) -
                      field44->Read(0xfb0) / TextFonts::Instance()->GetFont((int)field44->Read(0xfb9) - 1)->Height()) +
                1;
    TextLayout textLayout((int)field60->Read(0xfba), 0, 0, lines, 10);
    TextFonts::Instance()->GetFont((int)field60->Read(0xfb9) - 1)->Format(fieldbc, &textLayout);
    fielde8->SetText(textLayout, field60->GetValue(0xfc4), field60->Find(0xfa3), -1);
    fieldbc += FUN_0042f5a0(textLayout.consumed, buffer.Length());
    if (!*fieldbc)
        fieldbc = 0;
}

namespace fnv_007598d0 {
struct TextTile
{
    TextTile* FUN_0045cd60();
    float FUN_00a011b0(int);
    void FUN_00a012d0(int, float, bool);
    void FUN_00700320(int, int);
    void* FUN_00a00f30(int);
    void FUN_00a04640(bool);
    void FUN_00a04620(bool);
    bool IsAllChildrenFlag0();
};
struct QueueText
{
    ~QueueText();
    bool FUN_00759d80();
    const char* FUN_00458b50();
    const char* FUN_0059bb30();
    unsigned int FUN_0044edb0();
    TextTile* FUN_007001f0();
    void FUN_006ffea0();
};
struct TextQueue
{
    bool FUN_0076b610() const;
    QueueText** FUN_0073ac90();
    QueueText* PopFrontScript();
    void ProcessQueue();
};
struct TextSound
{
    int id;
    int state;
    int flags;
    ~TextSound();
    void FUN_00ad8870();
    void Play(bool);
};
struct TextAudioManager
{
    TextSound ResolveAudioHandle(const char*, int, unsigned int, int);
};
TextAudioManager* FUN_00ad9060();
unsigned int FUN_0044a670(const char*);
struct QueueMenu
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
    TextTile* previousTile;
    TextTile* positionTile;
    TextTile* activeTile;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    TextTile* modeTile;
    Shell selection;
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
    int unka4;
    int unka8;
    int unkac;
    int mode;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    TextSound unusedSound;
    TextSound advanceSound;
    TextSound promptSound;
};
extern unsigned int DAT_011d93d4;
extern const char DAT_01072118[];
// @fnv 0x007598d0
void TextQueue::ProcessQueue()
{
    bool hasTrait = false;
    while (!FUN_0076b610() && gm_GetTickCount() > DAT_011d93d4)
    {
        if ((*FUN_0073ac90())->FUN_00759d80())
        {
            QueueText* removed = PopFrontScript();
            if (!reinterpret_cast<QueueMenu*>(DAT_011d9334)->mode)
            {
                if (removed && *removed->FUN_00458b50() == *DAT_01072118)
                    reinterpret_cast<QueueMenu*>(DAT_011d9334)->promptSound.Play(false);
                DAT_011d93d4 = gm_GetTickCount() + 500;
            }
            else if (removed && removed->FUN_007001f0() == reinterpret_cast<QueueMenu*>(DAT_011d9334)->activeTile)
            {
                reinterpret_cast<QueueMenu*>(DAT_011d9334)->modeTile->FUN_00700320(0xfa3, 1);
            }
            delete removed;
        }
        else
        {
            int x;
            {
                TextTile* tile;
                {
                    int y;
                    {
                        unsigned int oldLength = 0;
                        unsigned int newLength = 0;
                        if (!reinterpret_cast<QueueMenu*>(DAT_011d9334)->mode &&
                            *(*FUN_0073ac90())->FUN_00458b50() == *DAT_01072118)
                        {
                            oldLength = FUN_0044a670((*FUN_0073ac90())->FUN_0059bb30());
                            (*FUN_0073ac90())->FUN_006ffea0();
                            newLength = FUN_0044a670((*FUN_0073ac90())->FUN_0059bb30());
                            for (unsigned int index = 0; index < newLength - oldLength; index++)
                            {
                                unsigned int offset =
                                    (*FUN_0073ac90())->FUN_0044edb0() * index / (newLength - oldLength);
                                FUN_00ad9060()
                                    ->ResolveAudioHandle("UIHackingCharSingle", 0x121, offset, 0)
                                    .FUN_00ad8870();
                            }
                        }
                        else
                        {
                            (*FUN_0073ac90())->FUN_006ffea0();
                            reinterpret_cast<QueueMenu*>(DAT_011d9334)->advanceSound.Play(false);
                        }
                        x = 0;
                        y = 0;
                        tile = (*FUN_0073ac90())->FUN_007001f0();
                        hasTrait = tile->FUN_00a00f30(0xfba) != 0;
                        for (TextTile* parent = tile;
                             parent &&
                             parent != reinterpret_cast<QueueMenu*>(DAT_011d9334)->positionTile->FUN_0045cd60();
                             parent = parent->FUN_0045cd60())
                        {
                            x += (int)parent->FUN_00a011b0(0xfa1);
                            y += (int)parent->FUN_00a011b0(0xfa2);
                        }
                        tile->FUN_00a04640(false);
                        if (reinterpret_cast<QueueMenu*>(DAT_011d9334)
                                ->selection.ContainsKey(reinterpret_cast<Tile*>(tile)))
                        {
                            tile->FUN_00a04620(false);
                            reinterpret_cast<QueueMenu*>(DAT_011d9334)
                                ->positionTile->FUN_00a012d0(
                                    0xfa1,
                                    x + tile->FUN_00a011b0(reinterpret_cast<int>(TraitNameToIDAdd("_text_width", -1))),
                                    true);
                            reinterpret_cast<QueueMenu*>(DAT_011d9334)
                                ->positionTile->FUN_00a012d0(
                                    0xfa2, y + tile->FUN_00a011b0(reinterpret_cast<int>(TraitNameToIDAdd("_text_y", -1))),
                                    true);
                        }
                        else if (!hasTrait)
                        {
                            reinterpret_cast<QueueMenu*>(DAT_011d9334)
                                ->positionTile->FUN_00a012d0(0xfa1, x + tile->FUN_00a011b0(0xfb1), true);
                            reinterpret_cast<QueueMenu*>(DAT_011d9334)->positionTile->FUN_00700320(0xfa2, y);
                        }
                        break;
                    }
                }
            }
        }
    }
    if (FUN_0076b610() || hasTrait)
    {
        reinterpret_cast<QueueMenu*>(DAT_011d9334)
            ->positionTile->FUN_00a012d0(
                0xfa1,
                reinterpret_cast<QueueMenu*>(DAT_011d9334)->previousTile->FUN_00a011b0(0xfa1) +
                    (reinterpret_cast<QueueMenu*>(DAT_011d9334)->previousTile->IsAllChildrenFlag0()
                         ? reinterpret_cast<QueueMenu*>(DAT_011d9334)->previousTile->FUN_00a011b0(0xfb1)
                         : 0.0f),
                true);
        reinterpret_cast<QueueMenu*>(DAT_011d9334)
            ->positionTile->FUN_00a012d0(
                0xfa2, reinterpret_cast<QueueMenu*>(DAT_011d9334)->previousTile->FUN_00a011b0(0xfa2), true);
    }
}
}  // namespace fnv_007598d0

int __cdecl TraitNameToID(const char* apName, int aiDefault);

struct LBTile;

struct LBTileValue
{
    void RemoveFromReactions();
    void FUN_00a09130(int aiOperator, LBTile* apTile, int aiID);
    void AppendFloatAction(int aiOperator, float afValue);
    void Refresh(int aiFlag);
};

struct LBTileMenu
{
    LBTile* AddTileFromTemplate(LBTile* apParent, const char* apTemplate, int aiUnk);
};

struct LBTile
{
    LBTileMenu* GetMenu();
    void* GetValue(int aiID);
    LBTileValue* GetValueAction(int aiID);
    void SetInt(int aiID, int aiValue);
    void SetString(int aiID, const char* apString, bool abPropagate);
    float GetFloat(int aiID);
};

struct LBItem
{
    LBTile* pTile;
    int iObject;
    int iUnk08;
    LBItem(LBTile* apTile, const int& arObject);
};

struct LBItemList
{
    LBItem* pFirst;
    void* pNext;
    void InsertSorted(LBItem* apItem, int(__cdecl* apSort)(LBItem*, LBItem*));
    void Append(LBItem* const& arItem);
};

struct LBListBox
{
    virtual void v00();
    LBItemList kList;
    LBTile* pParentTile;
    LBTile* pSelected;
    LBTile* m_pHighlightedTile;
    const char* pTemplateName;
    unsigned short usItemCount;

    bool FUN_007242c0(int aiUnk);
    void ResetAndProcessNodes();
    void AccumulateTileHeight(LBTile* apTile);
    void UpdateScrollItems();
    int GetRaceCount();
    LBTile* AddItem(int aiObject, const char* apText, int(__cdecl* apSort)(LBItem*, LBItem*),
                    const char* apTemplateName);
};

// @fnv 0x0075a110
LBTile* LBListBox::AddItem(int aiObject, const char* apText, int(__cdecl* apSort)(LBItem*, LBItem*),
                           const char* apTemplateName)
{
    if (pParentTile && (pTemplateName || apTemplateName))
    {
        LBTile* pTile = pParentTile->GetMenu()->AddTileFromTemplate(pParentTile,
                                                                    apTemplateName ? apTemplateName : pTemplateName, 0);
        if (!pTile->GetValue(0xfaa))
            pTile->SetInt(0xfaa, -1);
        if (apText)
            pTile->SetString(0xfc4, apText, true);
        if (apSort)
        {
            kList.InsertSorted(new LBItem(pTile, aiObject), apSort);
            if (FUN_007242c0(0))
                ResetAndProcessNodes();
        }
        else
        {
            kList.Append(new LBItem(pTile, aiObject));
            if (FUN_007242c0(0))
            {
                AccumulateTileHeight(pTile);
                UpdateScrollItems();
            }
            pTile->SetInt(0xfac, usItemCount++);
        }
        if (GetRaceCount() == 1 && pParentTile->GetFloat(TraitNameToID("_number_of_visible_items", -1)) > 0.0)
        {
            LBTileValue* pAction = pParentTile->GetValueAction(0xfb0);
            pAction->RemoveFromReactions();
            pAction->FUN_00a09130(0x7d0, pTile, 0xfb0);
            pAction->AppendFloatAction(0x7d3, pParentTile->GetFloat(TraitNameToID("_number_of_visible_items", -1)));
            pAction->Refresh(0);
        }
        return pTile;
    }
    else
        return 0;
}

struct OwnedObject
{
    virtual ~OwnedObject();
};
struct OwnedText
{
    ~OwnedText();
};
struct AnimationEntry
{
    OwnedObject* object;
    OwnedText* text;
};
struct AnimationNode
{
    AnimationEntry** FUN_006815c0();
    AnimationNode* FUN_00726070();
    void FUN_006ecd40(int value);
    ~AnimationNode();
};
struct AnimationTile
{
    void Set(int trait, float value, bool propagate);
};
extern bool s_bAllowDetach;
int __cdecl TraitNameToID(const char* name);
struct AnimationList
{
    int unk00;
    AnimationEntry* entry;
    AnimationNode* node;
    AnimationTile* tile;
    Tile* currentTile;
    int unk14;
    int unk18;
    unsigned short count;
    unsigned short unk1e;
    float elapsed;
    bool FUN_007242c0(unsigned int flag);
    void UpdateScrollItems();
    void UpdateHighlight();
    void ClearEntries();
};
// Deletes the node chain and entry, optionally their object/text, resets count and elapsed, clears the tile filter, and resets currentTile.
// @fnv 0x0075a3b0
void AnimationList::ClearEntries()
{
    while (node && *node->FUN_006815c0())
    {
        AnimationNode* next = node->FUN_00726070();
        if (!s_bAllowDetach)
            delete (*node->FUN_006815c0())->object;
        if (FUN_007242c0(1))
            delete (*node->FUN_006815c0())->text;
        delete *node->FUN_006815c0();
        node->FUN_006ecd40(0);
        delete node;
        node = next;
    }
    if (entry)
    {
        if (!s_bAllowDetach)
            delete entry->object;
        if (FUN_007242c0(1))
            delete entry->text;
        delete entry;
    }
    entry = 0;
    count = 0;
    elapsed = 0.0f;
    if (tile)
        tile->Set(TraitNameToID("_num_filtered"), 0.0f, true);
    UpdateScrollItems();
    currentTile = 0;
    UpdateHighlight();
}

float __cdecl FUN_004bd510(float, float);
int __cdecl TraitNameToID(const char*);

struct MyTile : FUN_00a01230_shell
{
    float __thiscall FUN_00a011b0(int);
};

struct MyInner
{
    MyTile* m_00;
};

struct MyRef
{
    MyInner* p;
};

struct MyNode
{
    void* m_item;
    MyNode* m_next;
    MyRef* __thiscall FUN_006815c0();
    MyNode* __thiscall FUN_00726070();
};

struct MyListBox
{
    virtual void* v00();
    virtual void* v04();
    virtual void* v08();
    virtual void* v0c();
    virtual void* v10();
    virtual MyTile* FUN_0075a955(int, int);

    MyNode m_kNode;
    MyTile* m_tile0c;
    MyTile* m_tile10;
    int m_unk14;
    int m_unk18;
    unsigned short m_count1c;

    bool __thiscall IsTileTraitEnabled();
    MyTile* GetScrollTargetTile(int a1);
};

// Resolves a scroll direction into a step, finds the enabled tile at the clamped index in the list, and returns it unless it is the current tile.
// @fnv 0x0075a680
MyTile* MyListBox::GetScrollTargetTile(int aiScrollCode)
{
    MyTile* pFound_ = 0;
    int iTileIndex = 0;

    switch (aiScrollCode)
    {
    case 2:
        iTileIndex = 1;
        break;
    case 1:
        iTileIndex = -1;
        break;
    case 15:
        iTileIndex =
            m_tile0c ? (int)FUN_004bd510(
                           -m_tile0c->FUN_00a011b0(0xfb0) / m_tile0c->FUN_00a011b0(TraitNameToID("_scroll_delta")), 1.0f)
                     : 0;
        break;
    case 16:
        iTileIndex =
            m_tile0c ? (int)FUN_004bd510(
                           m_tile0c->FUN_00a011b0(0xfb0) / m_tile0c->FUN_00a011b0(TraitNameToID("_scroll_delta")), 1.0f)
                     : 0;
        break;
    default:
        break;
    }

    if (IsTileTraitEnabled() && iTileIndex && m_count1c)
    {
        int maxIdxTmp = m_count1c - 1;
        int curIdx;
        if (m_tile10)
        {
            int selIdx = (int)m_tile10->FUN_00a011b0(0xfac);
            curIdx = selIdx + iTileIndex;
            if (curIdx < 0)
                curIdx = 0;
            else if (curIdx > maxIdxTmp)
                curIdx = maxIdxTmp;
        }
        else
        {
            if (iTileIndex > 0)
                curIdx = 0;
            else
                curIdx = maxIdxTmp;
        }

        while (1)
        {
            for (MyNode* pNodeA = this ? &m_kNode : 0; !pFound_ && pNodeA && pNodeA->FUN_006815c0()->p;
                 pNodeA = pNodeA->FUN_00726070())
            {
                if (pNodeA->FUN_006815c0()->p->m_00->FUN_00a011b0(0xfac) == (float)curIdx)
                {
                    pFound_ = pNodeA->FUN_006815c0()->p->m_00;
                }
            }

            if (pFound_ && !pFound_->IsTraitNonZero((int)TraitNameToIDAdd("_enabled", -1)))
            {
                pFound_ = 0;
                if (iTileIndex > 0 && ++curIdx > maxIdxTmp)
                {
                    curIdx = maxIdxTmp - 1;
                    while ((!pFound_ || !pFound_->IsTraitNonZero((int)TraitNameToIDAdd("_enabled", -1))) && curIdx >= 0)
                    {
                        pFound_ = FUN_0075a955(curIdx--, 0);
                    }
                    break;
                }
                else if (iTileIndex < 0 && --curIdx < 0)
                {
                    curIdx = 1;
                    while ((!pFound_ || !pFound_->IsTraitNonZero((int)TraitNameToIDAdd("_enabled", -1))) &&
                           curIdx <= maxIdxTmp)
                    {
                        pFound_ = FUN_0075a955(curIdx++, 0);
                    }
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }

    return (pFound_ != m_tile10) ? pFound_ : 0;
}

struct ScrollListHelper
{
    void __thiscall FUN_00700320(int aiID, int aiValue);
};

struct ScrollTileHelper
{
    void __thiscall FUN_00a012d0(int aiID, float afValue, bool abCreate);
};

struct FUN_0075b020_cls
{
    unsigned int __thiscall FUN_0075b020();
};

struct ScrollData
{
    int unk00;
    int unk04;
    int unk08;
    TraitValueCollection* pTile0c;
    int unk10;
    ScrollListHelper* pTile14;
};

extern double DAT_01012060;
float __cdecl FUN_004e4430(float afValue);
int __cdecl FUN_00647b70(int aiMinimum, int aiValue);
int __cdecl TraitNameToID(const char* apText);

// Computes the number of scroll items from the tile value and m_20, sets _scroll_delta on the tile and _number_of_items on the list.
// @fnv 0x0075aef0
void FUN_0075aa50_cls::UpdateScrollItems()
{
    float fTimeOffset;
    int iNumberOfItems;
    if (((ScrollData*)this)->pTile0c != 0)
    {
        fTimeOffset = ((ScrollData*)this)->pTile0c->FUN_00a011b0(0xfb0);
        iNumberOfItems = 1;

        if (m_20 > DAT_01012060 && fTimeOffset > DAT_01012060)
        {
            if (m_20 > fTimeOffset)
            {
                iNumberOfItems =
                    FUN_00647b70((int)FUN_004e4430(
                                     ((float)((FUN_0075b020_cls*)this)->FUN_0075b020() * (m_20 - fTimeOffset)) / m_20) +
                                     1,
                                 2);
            }

            if (iNumberOfItems > 1)
            {
                ((ScrollTileHelper*)((ScrollData*)this)->pTile0c)
                    ->FUN_00a012d0(TraitNameToID("_scroll_delta"), (m_20 - fTimeOffset) / (iNumberOfItems - 1), true);
            }
        }

        if (((ScrollData*)this)->pTile14 != 0)
        {
            ((ScrollData*)this)->pTile14->FUN_00700320(TraitNameToID("_number_of_items"), iNumberOfItems);
        }
    }
}

namespace fnv_00757b70 {
struct Terminal;
struct Ref
{
    Terminal* GetTerminal();
};
struct Terminal
{
    unsigned char IsFlagBitSet();
    bool CanUse(Ref*);
};
struct Color
{
    float r, g, b, a;
    Color(float, float, float, float);
};
struct Colors
{
    static Colors* Singleton();
    bool Get(int, int*);
    void Set(int, Color const&);
};
extern int DAT_011d934c;
struct OpenTile;
struct ListUI
{
    void Initialize(OpenTile*, const char*);
};
struct SoundUI
{
    bool Play(bool);
};
struct OpenMenu
{
    virtual ~OpenMenu();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual int ID();
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
    OpenTile* root;
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
    ListUI list;
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
    int unka4;
    Terminal* terminal;
    Ref* ref;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    unsigned char unkc0;
    unsigned char unkc1;
    unsigned char unkc2;
    unsigned char unkc3;
    SoundUI sound;
    void Attach(OpenTile*, bool);
    bool Validate(int*);
    void Populate();
    void Alternate();
    void Show(int);
    void* Data();
};
extern OpenMenu* gComputerMenu;
struct OpenTile
{
    OpenTile* ReadFile(const char*);
    OpenMenu* GetMenu();
    float Value(int);
    void Set(int, float, bool);
};
struct KeyState
{
    unsigned char Check(int, int, int);
};
struct UI
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
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
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    unsigned char unkc0;
    unsigned char unkc1;
    unsigned char unkc2;
    unsigned char unkc3;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
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
    KeyState keys;
    OpenTile* Root();
};
UI* GetUI();
int FUN_00757e20();
OpenMenu* FindMenu(int);
float GetDefault();
void Warn(const char*, ...);
// @fnv 0x00757b70
OpenTile* CreateComputerMenu(Ref* reference)
{
    OpenMenu* oldMenu = FindMenu(FUN_00757e20());
    if (oldMenu)
    {
        delete oldMenu;
    }
    Colors::Singleton()->Get(3, &DAT_011d934c);
    Terminal* terminal = reference->GetTerminal();
    if (terminal->IsFlagBitSet())
        Colors::Singleton()->Set(3, Color(1.0f, 1.0f, 1.0f, 0.0f));
    float defaultValue = GetDefault();
    OpenTile* aTile = GetUI()->Root()->ReadFile("Data\\Menus\\computers_menu.xml");
    OpenMenu* menu = aTile->GetMenu();
    if (menu && menu->ID() == FUN_00757e20())
    {
        menu->Attach(aTile, false);
        gComputerMenu = menu;
        int iMissingIndex;
        if (!gComputerMenu->Validate(&iMissingIndex))
        {
            Warn("MENUS: Computers Menu Creation Failed... Missing index = #%d", iMissingIndex);
            return 0;
        }
        else if (!reference)
        {
            Warn("MENUS: Computers Menu Creation Failed... Missing terminal data ");
            return 0;
        }
        if (aTile->Value(0xfa7) == 6006.0 || aTile->Value(0xfa7) == 102.0)
            aTile->Set(0xfad, defaultValue, true);
        gComputerMenu->unkc0 = GetUI()->keys.Check(0x18, FUN_00757e20(), 0x200);
        gComputerMenu->ref = reference;
        gComputerMenu->terminal = terminal;
        gComputerMenu->list.Initialize(gComputerMenu->root, "computers_file_template");
        gComputerMenu->sound.Play(false);
        if (gComputerMenu->terminal->CanUse(gComputerMenu->ref))
            gComputerMenu->Populate();
        else
            gComputerMenu->Alternate();
        menu->Show(0);
        return aTile;
    }
    else
    {
        if (menu && menu->Data())
        {
            delete menu;
        }
    }
    return 0;
}
}  // namespace fnv_00757b70

struct HighlightTile;
struct HighlightValue
{
    void FUN_00a09130(int trait, HighlightTile* tile, int sourceTrait);
    void Refresh(int mode);
};
struct HighlightTile
{
    HighlightValue* FUN_00a00f30(const char* trait);
    bool GetSpeechChallengeFailure();
    HighlightTile* FUN_00a03da0(const char* name);
    void FUN_0071aa60(bool visible);
    void FUN_00a07530(int flags);
    void FUN_00700320(const char* trait, int value);
};
HighlightTile* __cdecl FUN_00a08b20(HighlightTile* root, const char* path);
struct HighlightList
{
    int unk00;
    int unk04;
    int unk08;
    HighlightTile* root;
    HighlightTile* selected;
    void UpdateHighlight();
};
// @fnv 0x0075abd0
void HighlightList::UpdateHighlight()
{
    static const char* highlightY = TraitNameToIDAdd("_highlight_y", -1);
    static const char* selectedHeight = TraitNameToIDAdd("_selected_height", -1);
    if (root)
    {
        if (selected)
        {
            HighlightValue* heightValue = root->FUN_00a00f30(highlightY);
            HighlightValue* yValue = root->FUN_00a00f30(selectedHeight);
            heightValue->FUN_00a09130(2000, selected, 4002);
            heightValue->Refresh(0);
            yValue->FUN_00a09130(2000, selected, 4016);
            yValue->Refresh(0);
            if (selected->GetSpeechChallengeFailure())
            {
                HighlightTile* box = FUN_00a08b20(root, "lb_highlight_box");
                if (box)
                {
                    HighlightTile* edge = box->FUN_00a03da0("top");
                    if (edge)
                    {
                        edge->FUN_0071aa60(true);
                        edge->FUN_00a07530(8);
                        edge = box->FUN_00a03da0("bottom");
                        edge->FUN_0071aa60(true);
                        edge->FUN_00a07530(8);
                        edge = box->FUN_00a03da0("left");
                        edge->FUN_0071aa60(true);
                        edge->FUN_00a07530(8);
                        edge = box->FUN_00a03da0("right");
                        edge->FUN_0071aa60(true);
                        edge->FUN_00a07530(8);
                    }
                    box->FUN_0071aa60(true);
                    box->FUN_00a07530(8);
                }
            }
            else
            {
                HighlightTile* box = FUN_00a08b20(root, "lb_highlight_box");
                if (box)
                {
                    HighlightTile* edge = box->FUN_00a03da0("top");
                    if (edge)
                    {
                        edge->FUN_0071aa60(false);
                        edge->FUN_00a07530(8);
                        edge = box->FUN_00a03da0("bottom");
                        edge->FUN_0071aa60(false);
                        edge->FUN_00a07530(8);
                        edge = box->FUN_00a03da0("left");
                        edge->FUN_0071aa60(false);
                        edge->FUN_00a07530(8);
                        edge = box->FUN_00a03da0("right");
                        edge->FUN_0071aa60(false);
                        edge->FUN_00a07530(8);
                    }
                    box->FUN_0071aa60(false);
                    box->FUN_00a07530(8);
                }
            }
        }
        else
        {
            root->FUN_00700320(highlightY, -1);
            root->FUN_00700320(selectedHeight, 0);
        }
    }
}

struct MyMenuTile
{
    void FUN_00700320(int, int);
    void* FindTraitValue(int);
    void* FUN_00a00f30(int);
    MyMenuTile* FUN_0045cd60();
    float FUN_00a011b0(int);
    void FUN_00a012d0(int, float, bool);
};

class GlobalObject_0040c150
{
  public:
    const char* FUN_004c69f0();
    const char* FUN_00403df0();
};

extern GlobalObject_0040c150 g_011d3d78;
extern GlobalObject_0040c150 g_011d4978;

unsigned int __cdecl BSStringLength(const char*);

struct MyDisplay
{
    void ProcessAllTiles();
    void InsertAtPosition(const char*, void*, void*, int);
};

struct ChallengeMenu
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
    MyMenuTile* pTile28;
    int unk2C;
    int unk30;
    MyMenuTile* pTile34;
    MyMenuTile* pTile38;
    int unk3C;
    int unk40;
    int unk44;
    MyMenuTile* pTile48;
    MyMenuTile* pTile4C;
    MyMenuTile* pTile50;
    MyMenuTile* pTile54;
    MyMenuTile* pTile58;
    MyMenuTile* pTile5C;
    int unk60;
    int unk64;
    CHListBox kListBox;
    CHSimpleList kRecent;
    short unkA0;
    short unkA2;
    int unkA4;
    Host* pChallenge;
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
    MyDisplay* pDisplay;

    void FUN_007586e0(int);
    void RefreshDisplay();
};

// @fnv 0x00758d30
void ChallengeMenu::RefreshDisplay()
{
    this->pTile5C->FUN_00700320(0xFAF, 0);
    this->pDisplay->ProcessAllTiles();
    this->pTile4C->FUN_00700320(0xFA3, 0);
    this->pTile50->FUN_00700320(0xFA3, 0);
    this->pTile54->FUN_00700320(0xFA3, 0);
    this->pTile58->FUN_00700320(0xFA3, 0);
    this->FUN_007586e0(1);

    this->pDisplay->InsertAtPosition(g_011d3d78.FUN_004c69f0(), this->pTile34->FUN_00a00f30(0xFC4),
                                     this->pTile34->FindTraitValue(0xFA3), 0);
    this->pTile34->FUN_00a012d0(
        0xFA1,
        (this->pTile34->FUN_0045cd60()->FUN_00a011b0(0xFB1) - BSStringLength(g_011d3d78.FUN_00403df0()) * 17) / 2.0, 1);

    this->pDisplay->InsertAtPosition(g_011d4978.FUN_004c69f0(), this->pTile38->FUN_00a00f30(0xFC4),
                                     this->pTile38->FindTraitValue(0xFA3), 1);
    this->pTile38->FUN_00a012d0(
        0xFA1,
        (this->pTile38->FUN_0045cd60()->FUN_00a011b0(0xFB1) - BSStringLength(g_011d4978.FUN_00403df0()) * 17) / 2.0, 1);

    this->pDisplay->InsertAtPosition(this->pChallenge->FUN_00758fe0(), this->pTile28->FUN_00a00f30(0xFC4),
                                     this->pTile28->FindTraitValue(0xFA3), 2);
    this->pTile28->FUN_00a012d0(
        0xFA1,
        (this->pTile28->FUN_0045cd60()->FUN_00a011b0(0xFB1) - BSStringLength(this->pChallenge->FUN_00758fe0()) * 17) /
            2.0,
        1);

    this->pDisplay->InsertAtPosition("> ", this->pTile48->FUN_00a00f30(0xFC4), this->pTile48->FindTraitValue(0xFA3),
                                     -1);
    this->unkB0 = 2;
}

#include <string.h>
struct Menu
{
    Menu();
    virtual ~Menu();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
};
struct ComputerEntryList
{
    ComputerEntryList();
    ~ComputerEntryList();
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
};
struct SL2
{
    SL2();
    ~SL2();
    void* head;
    void* next;
};
struct StrMem
{
    StrMem();
    ~StrMem();
    char* text;
    unsigned short length;
    unsigned short capacity;
};
struct BSSoundHandleEx
{
    BSSoundHandleEx();
    ~BSSoundHandleEx();
    BSSoundHandleEx& operator=(const BSSoundHandleEx&);
    unsigned int id;
    unsigned int state;
    unsigned int sound;
};
struct ConstructorAudio
{
    BSSoundHandleEx ResolveAudioHandle(const char*, unsigned int);
};
ConstructorAudio* FUN_00ad9060();
void PlayNoteSound();
void SetTextSource();
void UpdateNoteDisplay();

struct FUN_007577f0 : Menu
{
    Tile* tile28;
    Tile* tile2c;
    Tile* tile30;
    Tile* tile34;
    Tile* tile38;
    Tile* tile3c;
    Tile* tile40;
    Tile* tile44;
    Tile* tile48;
    Tile* tile4c;
    Tile* tile50;
    Tile* tile54;
    Tile* tile58;
    Tile* tile5c;
    Tile* tile60;
    Tile* tile64;
    ComputerEntryList entries;
    SL2 notes;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    StrMem text;
    int unkbc;
    bool unkc0;
    BSSoundHandleEx sounds[3];
    S_7597c0* manager;
    void (*callbackec)();
    void (*callbackf0)();
    void (*callbackf4)();
    int unkf8;
    FUN_007577f0();
    virtual ~FUN_007577f0();
};

// Initializes the hacking menu by zeroing tiles, setting up audio handles for fan hum and character sounds, and assigning callback functions.
// @fnv 0x007577f0
FUN_007577f0::FUN_007577f0()
{
    memset(&tile28, 0, 0x40);
    manager = GetStorageSingleton();
    callbackec = PlayNoteSound;
    callbackf0 = SetTextSource;
    callbackf4 = UpdateNoteDisplay;
    unkf8 = 0;
    ConstructorAudio* audio = FUN_00ad9060();
    sounds[0] = audio->ResolveAudioHandle("UIHackingFanHumLP", 0x31);
    sounds[1] = audio->ResolveAudioHandle("UIHackingCharScroll", 0x21);
    sounds[2] = audio->ResolveAudioHandle("UIHackingCharEnter", 0x21);
    unka0 = 0;
    unka4 = 0;
    unka8 = 0;
    unkac = 0;
    unkb0 = 0;
    unkbc = 0;
    unkc0 = false;
}

namespace fnv_00757f70 {
struct TileF;
struct Value
{
    const char* FUN_0084e3a0();
};
struct TileF
{
    void FUN_00700320(int, int);
    bool IsAllChildrenFlag0();
    Value* FUN_00a00f30(int);
    void* FindTraitValue(int);
};
struct BStr
{
    void* m_data;
    int m_len;
    BStr();
    ~BStr();
    const char* FUN_00559450();
};
struct NameObj
{
    const char* FUN_00408da0();
};
struct Note
{
    void* m_n0[18];
    NameObj m_name;
    int GetNoteType();
};
struct Obj
{
    void* m_00;
    void* m_04;
    BStr m_str;
    void* m_rest[23];
    Note* m_note;
    void* m_70;
    void SetFlag4(bool);
    void FUN_00501830(void*);
    bool FUN_00758350();
    bool FUN_00758390();
};
struct ListObj
{
    void* m_items[14];
    bool ContainsKey(TileF*);
    Obj* FindItemData(TileF*);
    void FUN_007314c0(void(__cdecl*)(TileF*, void*), int, int);
};
struct SoundObj
{
    void* m_s0;
    void* m_s4;
    void* m_s8;
    bool Play(bool);
};
struct Mgr
{
    void ProcessAllTiles();
    void InsertAtPosition(const char*, void*, void*, int);
};
struct Player
{
    bool FUN_00966c10(Note*);
    void FUN_00966a70(Note*, int);
};
struct SettingObj
{
    const char* FUN_00403df0();
};
struct TickObj
{
    int* FUN_0043d4d0();
};
extern Player* DAT_011dea3c;
extern SettingObj DAT_011d3ca0;
extern TickObj DAT_011d3e50;
extern unsigned char DAT_011d93c0;
unsigned int __cdecl FUN_00457fe0();
int __cdecl FUN_00406f60(BStr*, const char*, ...);
bool __cdecl DispatchMessageToSink(const char*, int, const char*, const char*, float, bool);
void __cdecl UpdateNoteTile(TileF*, void*);
struct HostF
{
    void* m_pFirstNode[10];
    TileF* m_pTiles[16];
    ListObj m_kNode;
    int m_a0;
    int m_a4;
    void* m_a8;
    void* m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    int m_bc;
    unsigned char m_c0;
    unsigned char m_c1;
    unsigned char m_c2[26];
    SoundObj m_sound;
    Mgr* m_pManager;
    typedef void (HostF::*Handler)(Note*);
    Handler m_handlers[16];
    void SetTextSource(int);
    void FUN_007586e0(int);
    void FUN_00758a80();
    void RefreshDisplay();
    void __thiscall FUN_00757f70(int a1, TileF* a2);
};
// Processes a tile index and optional tile pointer, updates tile and note display state, and may dispatch a note message to the player.
// @fnv 0x00757f70
void __thiscall HostF::FUN_00757f70(int aiTileIndex, TileF* apTile)
{
    if (!apTile && aiTileIndex >= 0 && aiTileIndex < 16)
        apTile = m_pTiles[aiTileIndex];
    int id = aiTileIndex;
    bool flag4 = false;
    Value* val;
    Obj* obj;
    if (id == 2)
    {
        m_pManager->ProcessAllTiles();
        if (m_bc != 0)
        {
            SetTextSource(0);
            flag4 = true;
        }
        else
        {
            m_pTiles[2]->FUN_00700320(0xfa3, 0);
            m_pTiles[1]->FUN_00700320(0xfa3, 1);
            if (DAT_011d93c0)
            {
                FUN_007586e0(0);
            }
            else
            {
                if (!m_pTiles[7]->IsAllChildrenFlag0())
                {
                    m_pTiles[15]->FUN_00700320(0xfa3, 0);
                    val = m_pTiles[7]->FUN_00a00f30(0xfc4);
                    m_pManager->InsertAtPosition(val->FUN_0084e3a0(), val, m_pTiles[7]->FindTraitValue(0xfa3), -1);
                }
                m_kNode.FUN_007314c0(&UpdateNoteTile, 0, 0x7fffffff);
                m_c1 = 1;
            }
        }
        m_sound.Play(false);
    }
    else if (id == 13 && m_b0 < 2)
    {
        RefreshDisplay();
    }
    else
    {
        if (m_kNode.ContainsKey(apTile))
        {
            m_sound.Play(false);
            obj = m_kNode.FindItemData(apTile);
            if (!obj)
            {
                FUN_00758a80();
            }
            else if (obj->m_70)
            {
                obj->SetFlag4(true);
                obj->FUN_00501830(m_ac);
                m_a8 = obj->m_70;
                FUN_007586e0(1);
            }
            else
            {
                obj->SetFlag4(true);
                obj->FUN_00501830(m_ac);
                if (obj->m_str.FUN_00559450())
                {
                    m_pManager->InsertAtPosition(obj->m_str.FUN_00559450(), m_pTiles[5]->FUN_00a00f30(0xfc4),
                                                 m_pTiles[5]->FindTraitValue(0xfa3), 0);
                    m_a0 = FUN_00457fe0() + *DAT_011d3e50.FUN_0043d4d0() * 1000;
                }
                if (obj->m_note)
                {
                    if (obj->FUN_00758350() && !DAT_011dea3c->FUN_00966c10(obj->m_note))
                    {
                        DAT_011dea3c->FUN_00966a70(obj->m_note, 0);
                        {
                            BStr str;
                            FUN_00406f60(&str, DAT_011d3ca0.FUN_00403df0(), obj->m_note->m_name.FUN_00408da0());
                            DispatchMessageToSink(str.FUN_00559450(), 0,
                                                  "Interface\\Icons\\Message Icons\\glow_message_giftbox.dds", 0, 2.0f,
                                                  false);
                        }
                    }
                    if (m_handlers[obj->m_note->GetNoteType()])
                        (this->*m_handlers[obj->m_note->GetNoteType()])(obj->m_note);
                    DAT_011d93c0 = obj->FUN_00758390();
                    flag4 = true;
                }
                else
                {
                    if (obj->FUN_00758390())
                        FUN_007586e0(0);
                }
            }
        }
    }
    if (!flag4)
        DAT_011d93c0 = 0;
}
}  // namespace fnv_00757f70

namespace fnv_00758ad0 {
struct StrMem
{
    char* text;
    unsigned short length;
    unsigned short capacity;
    StrMem();
    ~StrMem();
    const char* FUN_00559450() const;
};
struct TimingSetting
{
    unsigned int* FUN_0043d4d0();
};
struct TextSetting
{
    const char* FUN_004c69f0();
    const char* FUN_00403df0();
};
extern TimingSetting g_011d3de4;
extern TimingSetting g_011d4e4c;
extern TextSetting g_011d3a38;
extern TextSetting g_011d2ee0;
extern TextSetting g_011d430c;
extern int DAT_0119f278;
struct TextTile
{
    void* FindTraitValue(int);
    void* FUN_00a00f30(int);
};
struct TerminalReference
{
    unsigned int FUN_00501270(void*);
};
int __cdecl FUN_00406f60(StrMem*, const char*, ...);
void __cdecl FUN_00403d30(void*, int, unsigned int);
struct TerminalTextMenu
{
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
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    TextTile* introTile;
    TextTile* promptTile;
    TextTile* headerTile;
    TextTile* passwordTile;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    TerminalReference* terminal;
    void* reference;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
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
    FUN_00759da0_shell* animation;
    void BuildAnimation();
};

// Inserts intro, prompt, header, and password tiles into the terminal animation sequence using timing settings and tile trait values.
// @fnv 0x00758ad0
void TerminalTextMenu::BuildAnimation()
{
    unsigned int promptDelay;
    {
        StrMem text;
        unsigned int introDelay = *g_011d3de4.FUN_0043d4d0() > 0 ? 1000 / *g_011d3de4.FUN_0043d4d0() : 1000;
        promptDelay = *g_011d4e4c.FUN_0043d4d0() > 0 ? 1000 / *g_011d4e4c.FUN_0043d4d0() : 1000;
        DAT_0119f278 = introDelay;
        animation->InsertAtPosition(g_011d3a38.FUN_004c69f0(), (int)introTile->FUN_00a00f30(0xfc4),
                                    (int)introTile->FindTraitValue(0xfa3), -1);
        DAT_0119f278 = promptDelay;
        FUN_00406f60(&text, "%s%s", "> ", g_011d2ee0.FUN_00403df0());
        animation->InsertAtPosition(text.FUN_00559450(), (int)promptTile->FUN_00a00f30(0xfc4),
                                    (int)promptTile->FindTraitValue(0xfa3), -1);
        DAT_0119f278 = introDelay;
        animation->InsertAtPosition(g_011d430c.FUN_004c69f0(), (int)headerTile->FUN_00a00f30(0xfc4),
                                    (int)headerTile->FindTraitValue(0xfa3), -1);
        DAT_0119f278 = promptDelay;
        char password[16];
        FUN_00403d30(password, 0, 16);
        FUN_00403d30(password, '*', terminal->FUN_00501270(reference));
        FUN_00406f60(&text, "%s%s", "> ", password);
        animation->InsertAtPosition(text.FUN_00559450(), (int)passwordTile->FUN_00a00f30(0xfc4),
                                    (int)passwordTile->FindTraitValue(0xfa3), -1);
    }
}
}  // namespace fnv_00758ad0
