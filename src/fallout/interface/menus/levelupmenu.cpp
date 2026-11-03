// fallout/interface/menus/levelupmenu.cpp: Holder, LBItemListBox, LevelUpMenu, EffectSetting and more (53 functions)

#include "levelupmenu_decls.h"

// @fnv 0x007d6720
void LevelUpMenu::RefreshNetworkState()
{
    NetworkSystemUtility::GetRandomGenerator();
}

struct ActorValue
{
    static bool __cdecl GetFlag(int, unsigned int);
};
struct EffectSetting
{
    bool IsFlagSet(unsigned int);
    bool IsDetrimentalToActorValue(int av);
};
// Returns whether the effect's detrimental flag differs from the actor value's damage-positive flag, treating av -1 as not damage-positive.
// @fnv 0x007869e0
bool EffectSetting::IsDetrimentalToActorValue(int aiActorValue)
{
    bool detrimental = IsFlagSet(4);
    bool damagePositive = false;
    if (aiActorValue != -1)
        damagePositive = ActorValue::GetFlag(aiActorValue, 0x200);
    return ((detrimental && !damagePositive) || (!detrimental && damagePositive)) ? 1 : 0;
}

struct RecursiveLock;
struct Menu;
struct NiAVObject;
struct NiNode;
struct Tile;
struct TileShaderProperty;
struct MenuValueDescriptor;

struct ListBoxItemX
{
    Tile* tile;
    void* data;
};
struct LBNode
{
    ListBoxItemX** _ref_006815c0();
    LBNode* _ref_00726070();
};
struct LBList
{
    int pad;
    LBNode first;
    void* FindItemData(Tile* apTile);
};
// Searches the list for an item whose tile equals apTile and returns its data, or 0 if not found or apTile is null.
// @fnv 0x007e1110
void* LBList::FindItemData(Tile* apTile)
{
    if (!apTile)
        return 0;
    LBNode* pnode = this ? &first : 0;
    for (; pnode && *pnode->_ref_006815c0(); pnode = pnode->_ref_00726070())
    {
        if ((*pnode->_ref_006815c0())->tile == apTile)
            return (*pnode->_ref_006815c0())->data;
    }
    return 0;
}

struct FUN_00784b80_shell
{
    int __thiscall FUN_00784b80();
};

// @fnv 0x00784b80
int __thiscall FUN_00784b80_shell::FUN_00784b80()
{
    return 0x403;
}

// @fnv 0x00785180
int __cdecl FUN_00785180()
{
    return 0x403;
}

namespace fnv_007851d0 {
struct ActorValue
{
    enum Index
    {
    };
};
struct NiNodeBooleanState
{
    bool GetBooleanValue();
    void FUN_008d5270();
};
struct Actor
{
    void ConfigureActorState(bool, bool);
};
struct Tile
{
    void Set(int, int);
};
struct ListBox_enum_ActorValue__Index_
{
    void Traverse(void(__cdecl*)(Tile*, ActorValue::Index), int, int);
};
struct StatsMenu
{
    static void __cdecl UpdateStatusEffects();
};
struct PC7d
{
    NiNodeBooleanState* FUN_00464e10();
    void ConfigureActorState(bool, bool);
};
extern PC7d* g_thePlayer;
extern int DAT_011d9fdc;
extern "C" void __cdecl UpdateStatsMenuLevelText();
void __cdecl FUN_0077da30();
void __cdecl FUN_008d5270();
void __cdecl FUN_00786570(Tile*, ActorValue::Index);
struct LevelUpMenuShell
{
    Tile* _ref_00726070();
    void LoadMenuData();
};

// @fnv 0x007851d0
void __cdecl UpdateLevelUpMenu()
{
    FUN_0077da30();
    if (DAT_011d9fdc != 0)
    {
        g_thePlayer->FUN_00464e10()->FUN_008d5270();
        ((ListBox_enum_ActorValue__Index_*)((int)DAT_011d9fdc + 0x94))->Traverse(FUN_00786570, 0, 0x7fffffff);
        if (g_thePlayer->FUN_00464e10()->GetBooleanValue())
            g_thePlayer->ConfigureActorState(true, false);
        UpdateStatsMenuLevelText();
        StatsMenu::UpdateStatusEffects();
        ((LevelUpMenuShell*)DAT_011d9fdc)->_ref_00726070()->Set(0x1772, 1);
        ((LevelUpMenuShell*)DAT_011d9fdc)->LoadMenuData();
        DAT_011d9fdc = 0;
    }
}
}  // namespace fnv_007851d0

extern int DAT_011d9fdc;

struct FUN_007866e0_shell
{
    void UpdateDisplayValue(const char*);
};

// @fnv 0x00786550
void FUN_00786550(const char* s)
{
    ((FUN_007866e0_shell*)(void*)DAT_011d9fdc)->UpdateDisplayValue(s);
}

struct FUN_00784b90_shell
{
    void SetTileByID(int aiID, void* apTile);
};

// Stores apTile into the slot at offset 0x2c indexed by aiID when aiID is in [0,10).
// @fnv 0x00784b90
void FUN_00784b90_shell::SetTileByID(int aiID, void* apTile)
{
    if (aiID >= 0 && aiID < 10)
        ((void**)((char*)this + 0x2c))[aiID] = apTile;
}

struct S
{
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual int f(int);
    int FUN_0071ae60(int);
    int FUN_007315b0();
};
// Calls FUN_0071ae60(0), subtracts 1 from the result, and passes it to f, returning f's result.
// @fnv 0x007315b0
int S::FUN_007315b0()
{
    return f(FUN_0071ae60(0) - 1);
}

struct FUN_00784bc0_shell
{
    void FUN_00784bf0();
    void* FUN_00784bc0(unsigned int);
};
void _Deallocate(void*);
// Calls FUN_00784bf0, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00784bc0
void* FUN_00784bc0_shell::FUN_00784bc0(unsigned int flags)
{
    FUN_00784bf0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct TESObjectREFR
{
};
struct PerkEntryConditionSet
{
    bool ContainsTrait(TESObjectREFR*, TESObjectREFR*, bool&, bool);
};
struct FUN_00785150_This
{
    bool FUN_00785150(TESObjectREFR*);
};
// @fnv 0x00785150
bool FUN_00785150_This::FUN_00785150(TESObjectREFR* a1)
{
    bool result;
    return reinterpret_cast<PerkEntryConditionSet*>(reinterpret_cast<char*>(this) + 0x40)->ContainsTrait(a1, 0, result, false);
}

struct FUN_00785190_This
{
    int _pad[11];
    int vals[10];
    bool HasAllValsNonZero();
};
// Returns true only if all 10 entries of vals are non-zero; otherwise returns false.
// @fnv 0x00785190
bool FUN_00785190_This::HasAllValsNonZero()
{
    for (int i = 0; i < 10; ++i)
    {
        if (vals[i] == 0)
            return false;
    }
    return true;
}

struct Tile
{
    bool ContainsTrait(int);
    void Set(int, int);
};
struct Holder
{
    void UpdateTileEffects(Tile*);
};
extern int DAT_011d9fdc;
extern int DAT_011d9fe0;
// If the tile reports the state stored in DAT_011d9fe0, clears that state via Set and notifies the holder at DAT_011d9fdc.
// @fnv 0x00786200
void FUN_00786200(Tile* pTile)
{
    if (pTile->ContainsTrait(DAT_011d9fe0))
    {
        pTile->Set(DAT_011d9fe0, 0);
        ((Holder*)DAT_011d9fdc)->UpdateTileEffects(pTile);
    }
}

namespace fnv_00786570 {
struct BGSPerk;
struct Tile
{
    bool ContainsTrait(int);
};
extern int DAT_011d9fe0;
template <int N> struct Pad;
template <> struct Pad<1>
{
    virtual void F(int (*)[1]);
};
template <int N> struct Pad : Pad<N - 1>
{
    virtual void F(int (*)[N]);
};
struct PC7d : Pad<294>
{
    virtual void Func498(BGSPerk*, int);
    virtual void Filler();
    virtual bool Func4A0(BGSPerk*, int, int);
};
extern PC7d* g_thePlayer;
// @fnv 0x00786570
void FUN_00786570(Tile* apTile, BGSPerk* apPerk)
{
    if (apTile->ContainsTrait(DAT_011d9fe0))
        g_thePlayer->Func498(apPerk, g_thePlayer->Func4A0(apPerk, 0, 0) + 1);
}
}  // namespace fnv_00786570

namespace fnv_007871c0 {
struct WeatherEntry;
struct BSSimpleList
{
    void Sort(int(__cdecl*)(WeatherEntry*, WeatherEntry*));
};
struct Holder
{
    char _0[4];
    BSSimpleList _4;
    void SortWeatherEntries(int(__cdecl*)(WeatherEntry*, WeatherEntry*));
    void ResetAndProcessTiles();
};
// Sorts the weather entry list using the given comparison function, then calls ResetAndProcessTiles.
// @fnv 0x007871c0
void Holder::SortWeatherEntries(int(__cdecl* a)(WeatherEntry*, WeatherEntry*))
{
    _4.Sort(a);
    ResetAndProcessTiles();
}
}  // namespace fnv_007871c0

struct Unk_7879c0
{
    void FUN_00786c80();
    void* FUN_007879c0(unsigned int);
};
// Calls FUN_00786c80, then deletes this when flags has bit 0 set, and returns this.
// @fnv 0x007879c0
void* Unk_7879c0::FUN_007879c0(unsigned int flags)
{
    FUN_00786c80();
    if (flags & 1)
        operator delete(this);
    return this;
}

namespace fnv_007864e0 {
struct TESObjectREFR;
struct PC7d;
struct FUN_006aabf0_shell
{
    signed char GetByteAt39();
};
struct FUN_00785150_This
{
    bool FUN_00785150(TESObjectREFR*);
};
struct Actor
{
    unsigned short GetLevel();
};
struct Tile
{
    void Set(int, float, bool);
};
extern int DAT_011d9ff4;
extern PC7d* g_thePlayer;
// @fnv 0x007864e0
void FUN_007864e0(Tile* tile, TESObjectREFR* reference)
{
    float value;
    if (((FUN_00785150_This*)reference)->FUN_00785150((TESObjectREFR*)g_thePlayer) &&
        (short)((FUN_006aabf0_shell*)reference)->GetByteAt39() <= ((Actor*)g_thePlayer)->GetLevel())
        value = 255.0f;
    else
        value = 128.0f;
    tile->Set(DAT_011d9ff4, value, true);
}
}  // namespace fnv_007864e0

struct FUN_00787760_shell
{
    void SetTileSelection(int, int);
    void FUN_00787760(int a);
};

// @fnv 0x00787760
void FUN_00787760_shell::FUN_00787760(int aiValue)
{
    SetTileSelection(aiValue, 0);
}

struct FUN_00787c40_shell
{
    void SetTileSelection(int a1, int a2);
    void FUN_00787780(int arg);
};

// @fnv 0x00787780
void __thiscall FUN_00787c40_shell::FUN_00787780(int aiValue)
{
    SetTileSelection(aiValue, 2);
}

struct FUN_00787c20_shell
{
    void __thiscall SetTileSelection(unsigned int a, int b);
    void __thiscall FUN_00787c20(unsigned int a);
};

// @fnv 0x00787c20
void __thiscall FUN_00787c20_shell::FUN_00787c20(unsigned int a)
{
    SetTileSelection(a, 1);
}

namespace fnv_00786110 {
struct Tile
{
    bool ContainsTrait(int);
};
struct Interface
{
    static void __cdecl PlayUISound(int);
};
struct FakeMenu
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(int, int);
    char _pad[0x44];
    Tile* mTile;
    bool HandleButton(int aiButton, float afValue);
};
// @fnv 0x00786110
bool FakeMenu::HandleButton(int aiButton, float afValue)
{
    bool bhandled = false;
    switch (aiButton)
    {
    case 11:
        if (mTile->ContainsTrait(0xFAF))
        {
            Interface::PlayUISound(1);
            f3(7, 0);
            bhandled = true;
        }
        break;
    }
    return bhandled;
}
}  // namespace fnv_00786110

struct CombatMember_1024
{
    int a;
    int b;
    int c;
    int d;
    int e;
};

struct BSSimpleArray_CombatMember_1024
{
    int mSize;
    CombatMember_1024* mBase;
    unsigned int FUN_007881d0();
    void ConstructElems(CombatMember_1024*, int);
};

struct FUN_00787950_shell : BSSimpleArray_CombatMember_1024
{
    int AppendMember(CombatMember_1024* apSrc);
};

// Appends a copy of the given member to the array and returns the index it was stored at.
// @fnv 0x00787950
int FUN_00787950_shell::AppendMember(CombatMember_1024* apSrc)
{
    unsigned int uiIdx = FUN_007881d0();
    ConstructElems(mBase + uiIdx, 1);
    mBase[uiIdx] = *apSrc;
    return uiIdx;
}

struct TGF
{
    float GetFloat(int);
};
struct VATSMenu
{
    int GetSelectedTargetIndex();
};
int __cdecl GetTileValueID(const char*, int);
struct FUN_007879f0
{
    int GetIntegerResult();
};
// @fnv 0x007879f0
int FUN_007879f0::GetIntegerResult()
{
    static int numFiltered = GetTileValueID("_num_filtered", -1);
    return ((VATSMenu*)this)->GetSelectedTargetIndex() -
           (unsigned int)((TGF*)(*((char**)((char*)this + 0xc))))->GetFloat(numFiltered);
}

namespace fnv_00785990 {
struct GlobalObject_0040c150;

extern GlobalObject_0040c150 g_011d1d48;
extern GlobalObject_0040c150 g_011d2a00;
extern GlobalObject_0040c150 g_011d2a24;
extern GlobalObject_0040c150 g_011d2e74;

struct StartMenu
{
    char const* GetMenuTitle();
};

struct Tile
{
    void Set(int, int);
    void Set(int, char const*, bool);
};

struct FUN_00785990_shell
{
    unsigned char pad00[0x28];
    int iValue;
    unsigned char pad2C[0x14];
    Tile* tile;
    unsigned char pad44[0x10];
    int m_iPointsUsed[2];
    int m_iPointsRemaining[2];

    void FUN_00785990();
};

int __cdecl _sprintf_s(char*, unsigned int, char const*, ...);

// @fnv 0x00785990
void FUN_00785990_shell::FUN_00785990()
{
    const char* strcounterStrings[2];
    int ipointsLeft;
    char strtemp[64];

    strcounterStrings[0] = reinterpret_cast<StartMenu*>(&g_011d1d48)->GetMenuTitle();
    strcounterStrings[1] = reinterpret_cast<StartMenu*>(&g_011d2a00)->GetMenuTitle();

    ipointsLeft = m_iPointsRemaining[iValue] - m_iPointsUsed[iValue];

    if (ipointsLeft == 0)
    {
        tile->Set(0xFA3, 0);
    }
    else if (ipointsLeft == 1)
    {
        tile->Set(0xFC4,
                  iValue == 0 ? reinterpret_cast<StartMenu*>(&g_011d2a24)->GetMenuTitle()
                              : reinterpret_cast<StartMenu*>(&g_011d2e74)->GetMenuTitle(),
                  true);
        tile->Set(0xFA3, 1);
    }
    else
    {
        _sprintf_s(strtemp, 0x40, strcounterStrings[iValue], ipointsLeft);
        tile->Set(0xFC4, strtemp, true);
        tile->Set(0xFA3, 1);
    }
}
}  // namespace fnv_00785990

namespace fnv_007865d0 {
class FUN_006aabf0_shell
{
  public:
    unsigned char GetByteAt39(void);
};

class TGF
{
  public:
    float GetFloat(int);
};

class Tile : public TGF
{
  public:
    char const* GetString(int);
};

class BGSPerk : public Tile
{
};

template <class T> class ListBoxItem
{
  public:
    T m_pInventoryEntryData;
    FUN_006aabf0_shell* m_pShell;
};

extern int DAT_011d9ff4;

int __cdecl FUN_00408b20(char const*, char const*);

// @fnv 0x007865d0
int __cdecl ComparePerkListItems(ListBoxItem<BGSPerk*>* apItem1, ListBoxItem<BGSPerk*>* apItem2)
{
    int iresult;
    iresult = 0;

    if (apItem1->m_pInventoryEntryData->GetFloat(DAT_011d9ff4) < apItem2->m_pInventoryEntryData->GetFloat(DAT_011d9ff4))
    {
        iresult = 1;
    }
    else if (apItem1->m_pInventoryEntryData->GetFloat(DAT_011d9ff4) >
             apItem2->m_pInventoryEntryData->GetFloat(DAT_011d9ff4))
    {
        iresult = -1;
    }
    else
    {
        if ((signed char)apItem1->m_pShell->GetByteAt39() < (signed char)apItem2->m_pShell->GetByteAt39())
        {
            iresult = -1;
        }
        else if ((signed char)apItem1->m_pShell->GetByteAt39() > (signed char)apItem2->m_pShell->GetByteAt39())
        {
            iresult = 1;
        }
        else
        {
            iresult = FUN_00408b20(apItem1->m_pInventoryEntryData->GetString(0xfc4),
                                   apItem2->m_pInventoryEntryData->GetString(0xfc4));
        }
    }

    return iresult;
}
}  // namespace fnv_007865d0

namespace fnv_007866e0 {
struct TGF
{
    float GetFloat(int);
};

struct Tile : public TGF
{
    void Set(int, char const*, bool);
};

int __cdecl _sprintf_s(char*, unsigned int, char const*, ...);
int __cdecl MinInt(int, int);
int __cdecl FUN_00647b70(int, int);
int GetTileValueID(char const*, int);

extern int DAT_011d9fe4;
extern int DAT_011d9fec;
extern int DAT_011d9ff0;
extern char const str_01020764[];
extern char const str_01073e14[];

struct FUN_007866e0_shell
{
    void UpdateDisplayValue(Tile* apTile);
};

// @fnv 0x007866e0
void FUN_007866e0_shell::UpdateDisplayValue(Tile* apTile)
{
    int idisplayValue = static_cast<int>(apTile->GetFloat(DAT_011d9fe4) + apTile->GetFloat(DAT_011d9fec) +
                                         apTile->GetFloat(DAT_011d9ff0));

    idisplayValue = MinInt(FUN_00647b70(idisplayValue, 0), 100);

    char strtemp[16];
    _sprintf_s(strtemp, 16, str_01020764, idisplayValue);

    apTile->Set(GetTileValueID(str_01073e14, -1), strtemp, true);
}
}  // namespace fnv_007866e0

// FUN_00786bb0 : constructor of a polymorphic object. It constructs the base,
// constructs the sub-object at +4, installs its own vtable, zeroes a set of
// members and two words, clears three floats, runs two setup calls and
// returns this.

struct ObjBase
{
    ObjBase();
    virtual void v00();
};

struct ObjSub
{
    ObjSub();
    ~ObjSub();
    int m_i00;
    int m_i04;
};

void __cdecl AddToHeadList(void* p);

struct FUN_00786bb0 : public ObjBase, public ObjSub
{
    int m_i0c;
    int m_i10;
    int m_i14;
    int m_i18;
    unsigned short m_w1c;
    float m_f20;
    float m_f24;
    float m_f28;
    unsigned short m_w2c;

    FUN_00786bb0();
    void FUN_007a1950(int a, int b);
};

// Initializes the object's integer, float and short fields to zero, calls FUN_007a1950(0, 1), then AddToHeadList(this).
// @fnv 0x00786bb0
FUN_00786bb0::FUN_00786bb0()
{
    m_i14 = 0;
    m_i10 = 0;
    m_i0c = 0;
    m_i18 = 0;
    m_w2c = 0;
    m_w1c = 0;
    m_f28 = 0.0f;
    m_f24 = 0.0f;
    m_f20 = 0.0f;
    FUN_007a1950(0, 1);
    AddToHeadList(this);
}

extern int DAT_01071b64;
void* __cdecl TraitNameToIDAdd(const void* data, int flags);
struct LevelOption
{
    bool __thiscall IsTraitNonZero(void* data);
};
struct FUN_007877a0_Object
{
    bool FUN_007877a0(LevelOption* option);
};
// @fnv 0x007877a0
bool FUN_007877a0_Object::FUN_007877a0(LevelOption* option)
{
    static void* cached = TraitNameToIDAdd(&DAT_01071b64, -1);
    return cached != 0 && option != 0 && option->IsTraitNonZero(cached);
}

struct LevelValue
{
    float __thiscall FUN_00a011b0(unsigned int property);
    void __thiscall FUN_00a012d0(int property, float value, int doUpdate);
    void __thiscall FUN_00700320(int property, int value);
};
struct FUN_007879f0_helper
{
    unsigned int __thiscall FUN_007879f0();
};
extern const double DAT_01012060;
extern char str_0106f90c[];
extern char str_0106f8f8[];
extern "C" int __cdecl TraitNameToID(const char*);
extern "C" float __cdecl FUN_004e4430(float);
extern "C" int __cdecl FUN_00647b70(int, int);
struct LevelMenuView
{
    int unk00;
    int unk04;
    int unk08;
    LevelValue* meter0c;
    int unk10;
    LevelValue* count14;
    int unk18;
    int unk1c;
    float maximum20;
    void __thiscall FUN_007880a0();
};
// @fnv 0x007880a0
void LevelMenuView::FUN_007880a0()
{
    if (meter0c)
    {
        float current = meter0c->FUN_00a011b0(0xFB0);
        int count = 1;
        if (maximum20 > DAT_01012060 && current > DAT_01012060)
        {
            if (maximum20 > current)
            {
                count =
                    FUN_00647b70((int)FUN_004e4430(((float)(unsigned int)((FUN_007879f0_helper*)this)->FUN_007879f0() *
                                                    (maximum20 - current)) /
                                                   maximum20) +
                                     1,
                                 2);
            }
            if (count > 1)
            {
                meter0c->FUN_00a012d0(TraitNameToID(str_0106f90c), (maximum20 - current) / (count - 1), 1);
            }
        }
        if (count14)
        {
            count14->FUN_00700320(TraitNameToID(str_0106f8f8), count);
        }
    }
}

struct ViewTile
{
    void Set(int, const char*, bool);
    void Set(int, int);
    const char* GetString(int);
    ViewTile* Parent();
};
struct ItemName
{
    const char* GetFullName();
};
struct MenuItem
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
    ItemName name;
    void Describe(char*, unsigned int);
};
struct SkillList
{
    virtual void Select(ViewTile*);
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
    unsigned int Lookup(ViewTile*);
};
const char* SkillName(unsigned int);
const char* SkillDescription(unsigned int);
unsigned int SkillExtra(unsigned int);
void Notify(int);
unsigned int BSStringLength(const char*);
struct LevelView
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void Hover(int, ViewTile*);
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
    ViewTile* tile38;
    ViewTile* tile3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    ViewTile* tile50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    SkillList skills;
    SkillList perks;
    void FUN_00785280(int, ViewTile*);
};
// Handles hover for ids 11-14: fills the skill or perk name/description tiles, toggles their visibility and notifies, or selects the parent skill list.
// @fnv 0x00785280
void LevelView::FUN_00785280(int id, ViewTile* tile)
{
    char description[512];
    switch (id)
    {
    case 11:
        tile38->Set(0xfcc, SkillName(skills.Lookup(tile)), true);
        tile3c->Set(0xfc4, SkillDescription(skills.Lookup(tile)), true);
        tile38->Set(0xfa3, 1);
        tile3c->Set(0xfa3, 1);
        if (SkillExtra(skills.Lookup(tile)) > 0)
        {
            tile50->Set(0xfa3, 1);
            tile50->Set(0xfcc, (const char*)SkillExtra(skills.Lookup(tile)), true);
        }
        else
            tile50->Set(0xfa3, 0);
        Notify(4);
        break;
    case 12:
        tile38->Set(0xfcc, ((MenuItem*)perks.Lookup(tile))->name.GetFullName(), true);
        ((MenuItem*)perks.Lookup(tile))->Describe(description, 512);
        tile3c->Set(0xfc4, description, true);
        if (BSStringLength(tile38->GetString(0xfcc)) > 1)
            tile38->Set(0xfa3, 1);
        else
            tile38->Set(0xfa3, 0);
        tile3c->Set(0xfa3, 1);
        tile50->Set(0xfa3, 0);
        Notify(4);
        break;
    case 13:
    case 14:
        skills.Select(tile->Parent());
        Hover(11, tile->Parent());
        break;
    }
}

namespace fnv_00785540 {
struct SkillTile
{
    void SetName(const char*);
    void FUN_00700320(int, int);
    void FUN_00a012d0(int, float, int);
};
struct SkillList
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void Sort(void(__cdecl*)());
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
    void FUN_0075a0d0(Tile*, const char*);
    SkillTile* AddListEntry(int, const char*, int, int);
    SkillTile* AddItemTile(void*, const char*, int, int);
};
struct ActorValues
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual int GetValue(int);
};
struct Perk;
struct PlayerSkills
{
    virtual void slot000();
    virtual void slot001();
    virtual void slot002();
    virtual void slot003();
    virtual void slot004();
    virtual void slot005();
    virtual void slot006();
    virtual void slot007();
    virtual void slot008();
    virtual void slot009();
    virtual void slot00a();
    virtual void slot00b();
    virtual void slot00c();
    virtual void slot00d();
    virtual void slot00e();
    virtual void slot00f();
    virtual void slot010();
    virtual void slot011();
    virtual void slot012();
    virtual void slot013();
    virtual void slot014();
    virtual void slot015();
    virtual void slot016();
    virtual void slot017();
    virtual void slot018();
    virtual void slot019();
    virtual void slot01a();
    virtual void slot01b();
    virtual void slot01c();
    virtual void slot01d();
    virtual void slot01e();
    virtual void slot01f();
    virtual void slot020();
    virtual void slot021();
    virtual void slot022();
    virtual void slot023();
    virtual void slot024();
    virtual void slot025();
    virtual void slot026();
    virtual void slot027();
    virtual void slot028();
    virtual void slot029();
    virtual void slot02a();
    virtual void slot02b();
    virtual void slot02c();
    virtual void slot02d();
    virtual void slot02e();
    virtual void slot02f();
    virtual void slot030();
    virtual void slot031();
    virtual void slot032();
    virtual void slot033();
    virtual void slot034();
    virtual void slot035();
    virtual void slot036();
    virtual void slot037();
    virtual void slot038();
    virtual void slot039();
    virtual void slot03a();
    virtual void slot03b();
    virtual void slot03c();
    virtual void slot03d();
    virtual void slot03e();
    virtual void slot03f();
    virtual void slot040();
    virtual void slot041();
    virtual void slot042();
    virtual void slot043();
    virtual void slot044();
    virtual void slot045();
    virtual void slot046();
    virtual void slot047();
    virtual void slot048();
    virtual void slot049();
    virtual void slot04a();
    virtual void slot04b();
    virtual void slot04c();
    virtual void slot04d();
    virtual void slot04e();
    virtual void slot04f();
    virtual void slot050();
    virtual void slot051();
    virtual void slot052();
    virtual void slot053();
    virtual void slot054();
    virtual void slot055();
    virtual void slot056();
    virtual void slot057();
    virtual void slot058();
    virtual void slot059();
    virtual void slot05a();
    virtual void slot05b();
    virtual void slot05c();
    virtual void slot05d();
    virtual void slot05e();
    virtual void slot05f();
    virtual void slot060();
    virtual void slot061();
    virtual void slot062();
    virtual void slot063();
    virtual void slot064();
    virtual void slot065();
    virtual void slot066();
    virtual void slot067();
    virtual void slot068();
    virtual void slot069();
    virtual void slot06a();
    virtual void slot06b();
    virtual void slot06c();
    virtual void slot06d();
    virtual void slot06e();
    virtual void slot06f();
    virtual void slot070();
    virtual void slot071();
    virtual void slot072();
    virtual void slot073();
    virtual void slot074();
    virtual void slot075();
    virtual void slot076();
    virtual void slot077();
    virtual void slot078();
    virtual void slot079();
    virtual void slot07a();
    virtual void slot07b();
    virtual void slot07c();
    virtual void slot07d();
    virtual void slot07e();
    virtual void slot07f();
    virtual void slot080();
    virtual void slot081();
    virtual void slot082();
    virtual void slot083();
    virtual void slot084();
    virtual void slot085();
    virtual void slot086();
    virtual void slot087();
    virtual void slot088();
    virtual void slot089();
    virtual void slot08a();
    virtual void slot08b();
    virtual void slot08c();
    virtual void slot08d();
    virtual void slot08e();
    virtual void slot08f();
    virtual void slot090();
    virtual void slot091();
    virtual void slot092();
    virtual void slot093();
    virtual void slot094();
    virtual void slot095();
    virtual void slot096();
    virtual void slot097();
    virtual void slot098();
    virtual void slot099();
    virtual void slot09a();
    virtual void slot09b();
    virtual void slot09c();
    virtual void slot09d();
    virtual void slot09e();
    virtual void slot09f();
    virtual void slot0a0();
    virtual void slot0a1();
    virtual void slot0a2();
    virtual void slot0a3();
    virtual void slot0a4();
    virtual void slot0a5();
    virtual void slot0a6();
    virtual void slot0a7();
    virtual void slot0a8();
    virtual void slot0a9();
    virtual void slot0aa();
    virtual void slot0ab();
    virtual void slot0ac();
    virtual void slot0ad();
    virtual void slot0ae();
    virtual void slot0af();
    virtual void slot0b0();
    virtual void slot0b1();
    virtual void slot0b2();
    virtual void slot0b3();
    virtual void slot0b4();
    virtual void slot0b5();
    virtual void slot0b6();
    virtual void slot0b7();
    virtual void slot0b8();
    virtual void slot0b9();
    virtual void slot0ba();
    virtual void slot0bb();
    virtual void slot0bc();
    virtual void slot0bd();
    virtual void slot0be();
    virtual void slot0bf();
    virtual void slot0c0();
    virtual void slot0c1();
    virtual void slot0c2();
    virtual void slot0c3();
    virtual void slot0c4();
    virtual void slot0c5();
    virtual void slot0c6();
    virtual void slot0c7();
    virtual void slot0c8();
    virtual void slot0c9();
    virtual void slot0ca();
    virtual void slot0cb();
    virtual void slot0cc();
    virtual void slot0cd();
    virtual void slot0ce();
    virtual void slot0cf();
    virtual void slot0d0();
    virtual void slot0d1();
    virtual void slot0d2();
    virtual void slot0d3();
    virtual void slot0d4();
    virtual void slot0d5();
    virtual void slot0d6();
    virtual void slot0d7();
    virtual void slot0d8();
    virtual void slot0d9();
    virtual void slot0da();
    virtual void slot0db();
    virtual void slot0dc();
    virtual void slot0dd();
    virtual void slot0de();
    virtual void slot0df();
    virtual void slot0e0();
    virtual void slot0e1();
    virtual void slot0e2();
    virtual void slot0e3();
    virtual void slot0e4();
    virtual void slot0e5();
    virtual void slot0e6();
    virtual void slot0e7();
    virtual void slot0e8();
    virtual void slot0e9();
    virtual void slot0ea();
    virtual void slot0eb();
    virtual void slot0ec();
    virtual void slot0ed();
    virtual void slot0ee();
    virtual void slot0ef();
    virtual void slot0f0();
    virtual void slot0f1();
    virtual void slot0f2();
    virtual void slot0f3();
    virtual void slot0f4();
    virtual void slot0f5();
    virtual void slot0f6();
    virtual void slot0f7();
    virtual void slot0f8();
    virtual void slot0f9();
    virtual void slot0fa();
    virtual void slot0fb();
    virtual void slot0fc();
    virtual void slot0fd();
    virtual void slot0fe();
    virtual void slot0ff();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot10a();
    virtual void slot10b();
    virtual void slot10c();
    virtual void slot10d();
    virtual void slot10e();
    virtual void slot10f();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot11a();
    virtual void slot11b();
    virtual void slot11c();
    virtual void slot11d();
    virtual void slot11e();
    virtual void slot11f();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual void slot125();
    virtual void slot126();
    virtual void slot127();
    virtual unsigned char GetPerkRank(void*, int);
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
    ActorValues values;
};
struct PerkName
{
    const char* FUN_00408da0();
};
struct Perk
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    PerkName name;
    unsigned char FUN_005d4ee0();
};
struct FallbackSetting
{
    const char* FUN_00403df0();
};
extern FallbackSetting DAT_011d35b8;
extern PlayerSkills* DAT_011dea3c;
extern int DAT_011d9ff0, DAT_011d9fe4, DAT_011d9ff8;
extern const char str_01073dcc[], str_01073db8[], str_0106eb00[];
unsigned int FUN_0066ecf0(int);
int FUN_0066ec10(int, unsigned char);
const char* FUN_0066e950(int);
void CompareActorValueNames();
int MinInt(int, int);
bool FUN_00406d70(int, unsigned int);
int strcpy_s(char*, unsigned int, const char*);
int FUN_00406d00(char*, unsigned int, const char*, ...);
unsigned int FUN_0044a670(const char*);
struct SkillsMenu
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
    Tile* skillRoot;
    Tile* perkRoot;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int points;
    int unk60;
    SkillList skills;
    SkillList perks;
    LBNode availablePerks;
    void UpdateSkillsAndPerks();
};
// Rebuilds the skill list and perk list tiles, recomputes points from skill totals, and labels perks with rank.
// @fnv 0x00785540
void SkillsMenu::UpdateSkillsAndPerks()
{
    int iTotalSkillValue = 0;
    int count = 0;
    skills.FUN_0075a0d0(skillRoot, str_01073dcc);
    for (unsigned int i = 0; i < FUN_0066ecf0(2); ++i)
    {
        int iSkillId = FUN_0066ec10(2, (unsigned char)i);
        if (!FUN_00406d70(iSkillId, 0x2000))
        {
            SkillTile* tile = skills.AddListEntry(iSkillId, FUN_0066e950(iSkillId), 0, 0);
            tile->SetName(FUN_0066e950(iSkillId));
            tile->FUN_00700320(0xfaa, 11);
            tile->FUN_00a012d0(DAT_011d9ff0, 0.0f, 1);
            tile->FUN_00700320(DAT_011d9fe4, DAT_011dea3c->values.GetValue(iSkillId));
            iTotalSkillValue += DAT_011dea3c->values.GetValue(iSkillId);
            ++count;
        }
    }
    skills.Sort(CompareActorValueNames);
    points = FUN_00647b70(MinInt(points, count * 100 - iTotalSkillValue), 0);
    perks.FUN_0075a0d0(perkRoot, str_01073db8);
    for (LBNode* node = &availablePerks; node && *node->_ref_006815c0(); node = node->_ref_00726070())
    {
        char acPerkLabel[64];
        {
            int iPerkRank = DAT_011dea3c->GetPerkRank(*node->_ref_006815c0(), 0);
            {
                SkillTile* perkTile = 0;
                strcpy_s(acPerkLabel, 64, ((Perk*)*node->_ref_006815c0())->name.FUN_00408da0());
                if (!FUN_0044a670(acPerkLabel))
                    strcpy_s(acPerkLabel, 64, DAT_011d35b8.FUN_00403df0());
                if (((Perk*)*node->_ref_006815c0())->FUN_005d4ee0() > 1 && iPerkRank > 0)
                    FUN_00406d00(acPerkLabel, 64, str_0106eb00, acPerkLabel, iPerkRank + 1);
                perkTile = perks.AddItemTile(*node->_ref_006815c0(), acPerkLabel, 0, 0);
                perkTile->FUN_00700320(0xfaa, 12);
                perkTile->FUN_00700320(DAT_011d9ff8, iPerkRank + 1);
            }
        }
    }
}
}  // namespace fnv_00785540

int TraitNameToID(const char*);
void UpdateLevelUpMenu();
void FUN_007864e0(const char*);
void ComparePerkListItems(const char*);
extern int DAT_011d9fe8;
extern int DAT_011d9fd8;
extern int DAT_011d9fd4;
struct RootTile
{
    double FUN_00a011b0(int);
    void Set(int, int);
};
struct OptionList
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void Apply(void (*)(const char*));
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
    void FUN_007314c0(void (*)(const char*), int, int);
    void FUN_007312e0();
    void FUN_00786a50(bool);
    void UpdateScrollTile(bool);
};
struct Target
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
    int first[2];
    int second[2];
    OptionList listA, listB;
    RootTile* FUN_00726070();
    void FUN_00785990();
    void SetPage(int);
};
// @fnv 0x00785830
void Target::SetPage(int page)
{
    if (page > FUN_00726070()->FUN_00a011b0(TraitNameToID("_EndPage")))
    {
        UpdateLevelUpMenu();
    }
    else
    {
        unk28 = page;
        FUN_00726070()->Set(DAT_011d9fe8, page);
        FUN_00726070()->Set(DAT_011d9fd8, first[page]);
        FUN_00726070()->Set(DAT_011d9fd4, second[page]);
        FUN_00785990();
        switch (unk28)
        {
        case 0:
            listA.FUN_007314c0(FUN_00786550, 0, 0x7fffffff);
            listB.FUN_007312e0();
            listA.FUN_00786a50(true);
            break;
        case 1:
            listB.FUN_007314c0(FUN_007864e0, 0, 0x7fffffff);
            listB.Apply(ComparePerkListItems);
            listA.FUN_007312e0();
            listB.UpdateScrollTile(true);
            break;
        }
    }
}

struct VT_b9166
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
    virtual void v229(int a, float b);
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
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual void v266();
    virtual void v267();
    virtual void v268();
    virtual void v269();
    virtual void v270();
    virtual void v271();
    virtual void v272();
    virtual void v273();
    virtual void v274();
    virtual void v275();
    virtual void v276();
    virtual void v277();
    virtual void v278();
    virtual void v279();
    virtual void v280();
    virtual void v281();
    virtual void v282();
    virtual void v283();
    virtual void v284();
    virtual void v285();
    virtual void v286();
    virtual void v287();
    virtual void v288();
    virtual void v289();
    virtual void v290();
    virtual double v291(int a, bool& flag);
};
extern int DAT_011dea3c;
extern int DAT_011d9ff0;
struct FUN_00a011b0_cls
{
    double FUN_00a011b0(int);
    void FUN_00a012d0(int, float, int);
};

// @fnv 0x00786170
void __cdecl FUN_00786170(Tile* apTile, int a2)
{
    bool flag = false;
    reinterpret_cast<VT_b9166*>(DAT_011dea3c)
        ->v229(a2, (float)(reinterpret_cast<VT_b9166*>(DAT_011dea3c)->v291(a2, flag) -
                           reinterpret_cast<FUN_00a011b0_cls*>(apTile)->FUN_00a011b0(DAT_011d9ff0)));
    reinterpret_cast<FUN_00a011b0_cls*>(apTile)->FUN_00a012d0(DAT_011d9ff0, 0.0f, 1);
    reinterpret_cast<FUN_007866e0_shell*>(DAT_011d9fdc)->UpdateDisplayValue((const char*)apTile);
}

struct EffectItem
{
    int FUN_00403ea0();
    int GetMagnitude();
    EffectSetting* GetEffectSetting();
};

struct ContObj
{
    int c00;
    int c04;
    int c08;
    int c0c;
    int c10;
    int c14;
    int c18;
    int c1c;
    int c20;
    int c24;
    LBNode node;
};

struct NodeSrc
{
    virtual void ReleaseA();
    virtual void ReleaseB();
    virtual void ReleaseC();
    virtual void ReleaseD();
    virtual int CheckType();
    NodeSrc* FindEntryByLevel(int lvl);
    ContObj* FUN_0044ddc0();
};

struct EffRec
{
    int mag;
    int f04;
    int f08;
    int f0c;
    void FUN_00403ba0();
};

struct GlobalObj
{
    void FUN_008454f0(bool clear);
    void AppendMember(EffRec* rec);
};

struct TravObj
{
    int t00;
    int t04;
    int t08;
    int t0c;
    int t10;
    int t14;
    int t18;
    int t1c;
    int t20;
    int t24;
    int t28;
    int t2c;
    void FUN_007314c0(void (*cb)(Tile*, int), int a, int b);
};

struct HolderThis
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    int f44;
    int f48;
    int f4c;
    int f50;
    int f54;
    int f58;
    int f5c;
    int f60;
    TravObj trav;
    LBList list;
};

extern int DAT_011d9ff8;
extern GlobalObj DAT_011da050;

void FUN_00786240(Tile* tile, int idx);

// @fnv 0x007867a0
void Holder::UpdateTileEffects(Tile* tile)
{

    void* found = ((HolderThis*)this)->list.FindItemData(tile);
    unsigned char lvl = (unsigned char)((LevelValue*)tile)->FUN_00a011b0(DAT_011d9ff8);
    NodeSrc* first7 = ((NodeSrc*)found)->FindEntryByLevel(lvl);
    NodeSrc* second = (lvl > 1) ? ((NodeSrc*)found)->FindEntryByLevel(lvl - 1) : (NodeSrc*)0;
    if (first7 != 0 && first7->CheckType() == 1)
    {
        ContObj* cont1 = first7->FUN_0044ddc0();
        ContObj* contX = second ? second->FUN_0044ddc0() : (ContObj*)0;
        DAT_011da050.FUN_008454f0(true);
        LBNode* curVal;
        for (curVal = cont1 ? &cont1->node : (LBNode*)0; curVal != 0 && *curVal->_ref_006815c0() != 0;
             curVal = curVal->_ref_00726070())
        {
            EffRec recVal;
            recVal.FUN_00403ba0();
            int av7 = ((EffectItem*)*curVal->_ref_006815c0())->FUN_00403ea0();
            recVal.mag = ((EffectItem*)*curVal->_ref_006815c0())->GetMagnitude();
            if (av7 == -1)
            {
                continue;
            }
            LBNode* cur4;
            for (cur4 = contX ? &contX->node : (LBNode*)0; cur4 != 0 && *cur4->_ref_006815c0() != 0;
                 cur4 = cur4->_ref_00726070())
            {
                if (((EffectItem*)*cur4->_ref_006815c0())->FUN_00403ea0() == av7)
                {
                    recVal.mag -= ((EffectItem*)*cur4->_ref_006815c0())->GetMagnitude();
                }
            }
            if (!((LevelOption*)tile)->IsTraitNonZero((void*)DAT_011d9fe0))
            {
                recVal.mag = recVal.mag * -1;
            }
            if (((EffectItem*)*curVal->_ref_006815c0())->GetEffectSetting()->IsDetrimentalToActorValue(av7))
            {
                recVal.mag = recVal.mag * -1;
            }
            DAT_011da050.AppendMember(&recVal);
        }
    }
    ((HolderThis*)this)->trav.FUN_007314c0(FUN_00786240, 0, 0x7fffffff);
}

// Destructor: clear the model list, unregister from the global tracker, then the list member is destroyed.

class C6C80List
{
  public:
    ~C6C80List();

    void* m_pkHead;
    void* m_pkTail;
};

class FUN_00786c80;
void __cdecl C6C80Unregister(FUN_00786c80* pkObject);

class FUN_00786c80
{
  public:
    virtual ~FUN_00786c80();
    void Clear();

    C6C80List m_kModels;
};

// Clears the object's model list, then unregisters the object from the C6C80 registry.
// @fnv 0x00786c80
FUN_00786c80::~FUN_00786c80()
{
    Clear();
    C6C80Unregister(this);
}

struct LBTile;
struct LBMenu
{
    LBTile* AddTileFromTemplate(LBTile* parent, const char* templ, int unk);
};
struct LBValue
{
    void ResetOps();
    void AddOp(int op, LBTile* src, int traitID);
    void AddFloatOp(int op, float val);
    void Finish(bool b);
};
struct LBTile
{
    LBMenu* GetMenu();
    void* GetValue(int traitID);
    void Set(int traitID, int val);
    void SetString(int traitID, const char* str, bool propagate);
    float GetFloat(int traitID);
    LBValue* GetActionValue(int traitID);
    static int __cdecl TraitNameToID(const char* name, int unk);
};
struct LBItem
{
    LBItem(LBTile* tile, int* item);
    LBTile* tile;
    int item;
    bool filtered;
};
struct LBItemList
{
    LBItem* data;
    LBItemList* next;
    void Insert(LBItem* item, int (*sortFunc)(LBItem*, LBItem*));
    void AddTail(LBItem* const& item);
};
struct LBItemListBox
{
    int unk00;
    LBItemList list;
    LBTile* parentTile;
    int unk10;
    int unk14;
    const char* templateName;
    unsigned short itemCount;
    bool FUN_007242c0(unsigned int a);
    void Sort();
    void AccumulateTileHeight(LBTile* tile);
    void FUN_007880a0();
    int GetNumVisible();
    LBTile* AddItemTile(int item, const char* text, int (*sortFunc)(LBItem*, LBItem*), const char* templ);
};

// @fnv 0x00786cf0
LBTile* LBItemListBox::AddItemTile(int item, const char* text, int (*sortFunc)(LBItem*, LBItem*),
                                   const char* apTemplate)
{
    if (parentTile && (templateName || apTemplate))
    {
        LBTile* tile =
            parentTile->GetMenu()->AddTileFromTemplate(parentTile, apTemplate ? apTemplate : templateName, 0);
        if (!tile->GetValue(0xfaa))
            tile->Set(0xfaa, -1);
        if (text)
            tile->SetString(0xfc4, text, true);
        if (sortFunc)
        {
            list.Insert(new LBItem(tile, &item), sortFunc);
            if (FUN_007242c0(0))
                Sort();
        }
        else
        {
            list.AddTail(new LBItem(tile, &item));
            if (FUN_007242c0(0))
            {
                AccumulateTileHeight(tile);
                FUN_007880a0();
            }
            tile->Set(0xfac, itemCount++);
        }
        if (GetNumVisible() == 1 && parentTile->GetFloat(LBTile::TraitNameToID("_number_of_visible_items", -1)) > 0.0)
        {
            LBValue* value = parentTile->GetActionValue(0xfb0);
            value->ResetOps();
            value->AddOp(0x7d0, tile, 0xfb0);
            value->AddFloatOp(0x7d3, parentTile->GetFloat(LBTile::TraitNameToID("_number_of_visible_items", -1)));
            value->Finish(false);
        }
        return tile;
    }
    else
    {
        return 0;
    }
}

namespace fnv_00786f90 {
extern bool s_bAllowDetach;

struct LBTile
{
    virtual ~LBTile();
    void Set(int aiID, float afValue, bool abPropagate);
};

struct LBObject
{
    ~LBObject();
};

struct LBItem
{
    LBTile* pTile;
    LBObject* pObject;
};

struct LBListNode
{
    LBItem* pItem;
    LBListNode* pNext;

    ~LBListNode();
    LBItem** GetItem();
    LBListNode* GetNext();
    void SetItem(unsigned int auiItem);
};

struct LBListBox
{
    void* pVtable;
    LBItem* pHeadItem;
    LBListNode* pHeadNext;
    LBTile* m_pHighlightedTile;
    int iUnk10;
    int iUnk14;
    int iUnk18;
    unsigned short usUnk1C;
    float fScroll;

    bool FUN_007242c0(unsigned int auiFlag);
    void FUN_007880a0();
    void UpdateHighlight();
    void ClearItems();
};

// @fnv 0x00786f90
void LBListBox::ClearItems()
{
    while (pHeadNext && *pHeadNext->GetItem())
    {
        LBListNode* pNext = pHeadNext->GetNext();
        if (!s_bAllowDetach)
            delete (*pHeadNext->GetItem())->pTile;
        if (FUN_007242c0(true))
            delete (*pHeadNext->GetItem())->pObject;
        delete *pHeadNext->GetItem();
        pHeadNext->SetItem(0);
        delete pHeadNext;
        pHeadNext = pNext;
    }
    if (pHeadItem)
    {
        if (!s_bAllowDetach)
            delete pHeadItem->pTile;
        if (FUN_007242c0(true))
            delete pHeadItem->pObject;
        delete pHeadItem;
    }
    pHeadItem = 0;
    usUnk1C = 0;
    fScroll = 0.0f;
    if (m_pHighlightedTile)
        m_pHighlightedTile->Set(TraitNameToID("_num_filtered"), 0.0f, true);
    FUN_007880a0();
    iUnk10 = 0;
    UpdateHighlight();
}
}  // namespace fnv_00786f90

int __cdecl TraitNameToIDAdd(const char* pcName, int iDefault);

class Tile787
{
  public:
    bool GetBool(int m_iValueId);
};

class ListBox787
{
  public:
    bool IsActive();
    bool Contains(Tile787* pkTile);
    void UpdateSelection();
    bool SelectTile(Tile787* pkTile);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Tile787* m_pkSelected;
};

// If the list box is active and the tile is null or contained and enabled, stores it as the selected tile, updates the selection and returns true.
// @fnv 0x007871f0
bool ListBox787::SelectTile(Tile787* pkTile)
{
    if (IsActive() && (!pkTile || (Contains(pkTile) && pkTile->GetBool(TraitNameToIDAdd("_enabled", -1)))))
    {
        m_pkSelected = pkTile;
        UpdateSelection();
        return true;
    }
    else
    {
        return false;
    }
}

class Tile;
class Menu;
struct InterfaceManager;
int TraitNameToID(const char* apName);
float FUN_0040ebd0(float afA, float afB);
InterfaceManager* FUN_004b7210();
bool FUN_004b71d0();
struct IMStandIn
{
    void FUN_00715860(int aiA, int aiB, int aiC);
};
struct FUN_00a012d0_t
{
    void FUN_00a012d0(int aiTrait, float afValue, bool abFlag);
};
struct FUN_00a01290_shell
{
    void SetTraitAndReset(int aiTrait, float afValue);
};
struct FUN_00a03d40_shell
{
    Tile* FUN_00a03d40();
};
struct FUN_00a03c90_shell
{
    Menu* FUN_00a03c90();
};
struct FUN_00787600_Tile
{
    float FUN_00a011b0(int aiTrait);
};
struct FUN_00787600_MenuVT
{
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05(int aiValue, FUN_00787600_Tile* apTile);
};
struct FUN_00787600_shell
{
    virtual void Unk_00(FUN_00787600_Tile* apTile);
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual FUN_00787600_Tile* Unk_05(unsigned int auiIndex);
    char pad04[8];
    FUN_00a03d40_shell* m_pFourthMenuObject;
    int iPad10;
    FUN_00a012d0_t* pScrollTile;
    char pad18[0xc];
    float fScrollPos;
    float fValue;
    unsigned int FUN_007879f0(int aiArg);
    void UpdateScrollTile(bool abFlag);
};
// @fnv 0x00787600
void FUN_00787600_shell::UpdateScrollTile(bool abFlag)
{
    FUN_00787600_Tile* pTile = 0;
    if (m_pFourthMenuObject && pScrollTile)
    {
        pScrollTile->FUN_00a012d0(TraitNameToID("_current_value"), fValue, false);
        ((FUN_00a01290_shell*)pScrollTile)->SetTraitAndReset(TraitNameToID("_SetInCode"), 1.0f);
        pTile = Unk_05((unsigned int)FUN_0040ebd0(fScrollPos, (float)FUN_007879f0(0) - 1.0));
        ((IMStandIn*)FUN_004b7210())->FUN_00715860((int)pTile, 0xfc3, abFlag);
        Unk_00(pTile);
        if (!FUN_004b71d0())
        {
            if (pTile)
            {
                ((FUN_00787600_MenuVT*)((FUN_00a03c90_shell*)m_pFourthMenuObject->FUN_00a03d40())->FUN_00a03c90())
                    ->Unk_05((int)pTile->FUN_00a011b0(0xfaa), pTile);
            }
            Unk_00(0);
        }
    }
}

struct FUN_00787850_item
{
    Tile* tile;
    void* data;
    unsigned char flag8;
};

class FUN_00787850_cls
{
  public:
    int pad;
    LBNode first;
    void FUN_00787850(unsigned char flag);
};

// @fnv 0x00787850
void FUN_00787850_cls::FUN_00787850(unsigned char abSkipFlagged)
{
    for (LBNode* node = this ? &this->first : 0; node != 0 && *node->_ref_006815c0() != 0; node = node->_ref_00726070())
    {
        if (abSkipFlagged == 0 || ((FUN_00787850_item*)*node->_ref_006815c0())->flag8 == 0)
        {
            reinterpret_cast<FUN_00787c20_shell*>(this)->FUN_00787c20((unsigned int)(*node->_ref_006815c0())->tile);
        }
    }
}

struct ListItem787aa0
{
    Tile* tile;
    void* data;
    unsigned char unk08;
};

struct TileCallees787aa0
{
    void FUN_00700320(int a, int b);
};

struct Callees787aa0
{
    void AccumulateTileHeight(Tile* t);
    void FUN_007880a0();
    void UpdateHighlight();
};

struct FUN_00787aa0_cls : Callees787aa0
{
    int unk00;
    LBNode first;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned short m_1c;
    float m_20;

    void ResetAndProcessTiles();
};

// Clears m_1c and m_20, iterates the list calling FUN_00700320 and AccumulateTileHeight on tiles with unk08 == 0, then calls FUN_007880a0 and UpdateHighlight.
// @fnv 0x00787aa0
void FUN_00787aa0_cls::ResetAndProcessTiles()
{
    m_1c = 0;
    m_20 = 0.0f;
    for (LBNode* pNode = (this != 0) ? &first : 0; pNode != 0 && *pNode->_ref_006815c0() != 0;
         pNode = pNode->_ref_00726070())
    {
        if (((ListItem787aa0*)*pNode->_ref_006815c0())->unk08 == 0)
        {
            ((TileCallees787aa0*)(*pNode->_ref_006815c0())->tile)->FUN_00700320(0xfac, m_1c++);
            AccumulateTileHeight((*pNode->_ref_006815c0())->tile);
        }
    }
    FUN_007880a0();
    UpdateHighlight();
}

int __cdecl TraitNameToID(const char* name, int unk);
extern int DAT_011d9fe4;
extern int DAT_011d9fec;
extern int DAT_011d9ff0;
extern int DAT_011d9fe8;
extern int DAT_011d9fd8;
extern int DAT_011d9fd4;
extern int DAT_011d9ff8;
extern int DAT_011d9fe0;
extern int DAT_011d9ff4;
struct Menu
{
    Menu();
    virtual ~Menu();
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
};
struct Member64
{
    Member64();
    ~Member64();
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
struct Member94
{
    Member94();
    ~Member94();
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
template <class T> struct BSSimpleList
{
    T item;
    BSSimpleList* next;
    BSSimpleList();
    ~BSSimpleList();
};
struct FUN_00784a40 : Menu
{
    Member64 unk64;
    Member94 unk94;
    BSSimpleList<void*> unkC4;
    FUN_00784a40();
    virtual ~FUN_00784a40();
};
// Initializes the menu's trait IDs by resolving each trait name to an ID via TraitNameToID and storing the results in the DAT globals.
// @fnv 0x00784a40
FUN_00784a40::FUN_00784a40()
{
    DAT_011d9fe4 = TraitNameToID("_BaseValue", -1);
    DAT_011d9fec = TraitNameToID("_ExtraValue", -1);
    DAT_011d9ff0 = TraitNameToID("_AddedValue", -1);
    DAT_011d9fe8 = TraitNameToID("_CurrentPage", -1);
    DAT_011d9fd8 = TraitNameToID("_CurrPoints", -1);
    DAT_011d9fd4 = TraitNameToID("_MaxPoints", -1);
    DAT_011d9ff8 = TraitNameToID("_Rank", -1);
    DAT_011d9fe0 = TraitNameToID("_selected", -1);
    DAT_011d9ff4 = TraitNameToID("_TextAlpha", -1);
}

class GlobalObject_009c6a30;
extern GlobalObject_009c6a30 g_011f2250;

struct FUN_00525430_Class
{
    bool FUN_00525430();
};
struct BSSoundHandleEx
{
    int unk00;
    int unk04;
    int unk08;
    ~BSSoundHandleEx();
    bool Play(bool);
};
struct BSAudio
{
    BSSoundHandleEx GetSoundHandleByEditorID(const char* name, unsigned int flags);
};
struct FUN_00a1dc20_Obj
{
    void FUN_00a1dc20(int a1);
};

BSAudio* __cdecl FUN_00453a70(void);
bool __cdecl IsStartMenuFlag1Set(void);

struct LevelUpMenuStand
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
    void PlayLevelUpSuccessSound();
};

// If unk24 equals 4 and neither FUN_00525430 nor IsStartMenuFlag1Set is true, plays the MUSSuccess sound and calls FUN_00a1dc20(0).
// @fnv 0x00785e20
void LevelUpMenuStand::PlayLevelUpSuccessSound()
{
    if (unk24 == 4)
    {
        if (!((FUN_00525430_Class*)&g_011f2250)->FUN_00525430() && !IsStartMenuFlag1Set())
        {
            FUN_00453a70()->GetSoundHandleByEditorID("MUSSuccess", 0x901).Play(false);
            ((FUN_00a1dc20_Obj*)this)->FUN_00a1dc20(0);
        }
    }
}

struct FUN_00787b70_inner
{
    bool IsTraitNonZero(void* apKey);
};

struct FUN_00787b70_cls
{
    int m_00;
    int m_04;
    int m_08;
    FUN_00787b70_inner* m_0c;
    bool FUN_00787b70();
};

int __cdecl TraitNameToIDAdd(const char* s, int n);

// @fnv 0x00787b70
bool FUN_00787b70_cls::FUN_00787b70()
{
    static void* sKey = (void*)TraitNameToIDAdd("_enabled", -1);
    return (m_0c != 0 && m_0c->IsTraitNonZero(sKey)) ? 1 : 0;
}

struct TileStandIn
{
    TileStandIn* fn_45cd60();
    float fn_a011b0(int k);
    bool fn_a01230(int k);
    void fn_a012d0(int k, float v, bool b);
    void fn_700320(int k, int v);
};

struct ListBox64
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
    int fn_7e1110(TileStandIn* t);
    void fn_7314c0(void(__cdecl* cb)(TileStandIn*), int a, int b);
};

struct ListBox94
{
    int unk00;
    bool fn_7877a0(TileStandIn* t);
    void fn_787780(TileStandIn* t);
    void fn_787850(bool b);
    void fn_787760(TileStandIn* t);
    int fn_7878d0();
    void fn_7314c0(void(__cdecl* cb)(TileStandIn*), int a, int b);
};

struct ClassStandIn
{
    bool fn_5a5f40(int av);
};

struct SettingStandIn
{
    int* fn_43d4d0();
};

struct PlayerStandIn
{
    virtual void vf000();
    virtual void vf001();
    virtual void vf002();
    virtual void vf003();
    virtual void vf004();
    virtual void vf005();
    virtual void vf006();
    virtual void vf007();
    virtual void vf008();
    virtual void vf009();
    virtual void vf010();
    virtual void vf011();
    virtual void vf012();
    virtual void vf013();
    virtual void vf014();
    virtual void vf015();
    virtual void vf016();
    virtual void vf017();
    virtual void vf018();
    virtual void vf019();
    virtual void vf020();
    virtual void vf021();
    virtual void vf022();
    virtual void vf023();
    virtual void vf024();
    virtual void vf025();
    virtual void vf026();
    virtual void vf027();
    virtual void vf028();
    virtual void vf029();
    virtual void vf030();
    virtual void vf031();
    virtual void vf032();
    virtual void vf033();
    virtual void vf034();
    virtual void vf035();
    virtual void vf036();
    virtual void vf037();
    virtual void vf038();
    virtual void vf039();
    virtual void vf040();
    virtual void vf041();
    virtual void vf042();
    virtual void vf043();
    virtual void vf044();
    virtual void vf045();
    virtual void vf046();
    virtual void vf047();
    virtual void vf048();
    virtual void vf049();
    virtual void vf050();
    virtual void vf051();
    virtual void vf052();
    virtual void vf053();
    virtual void vf054();
    virtual void vf055();
    virtual void vf056();
    virtual void vf057();
    virtual void vf058();
    virtual void vf059();
    virtual void vf060();
    virtual void vf061();
    virtual void vf062();
    virtual void vf063();
    virtual void vf064();
    virtual void vf065();
    virtual void vf066();
    virtual void vf067();
    virtual void vf068();
    virtual void vf069();
    virtual void vf070();
    virtual void vf071();
    virtual void vf072();
    virtual void vf073();
    virtual void vf074();
    virtual void vf075();
    virtual void vf076();
    virtual void vf077();
    virtual void vf078();
    virtual void vf079();
    virtual void vf080();
    virtual void vf081();
    virtual void vf082();
    virtual void vf083();
    virtual void vf084();
    virtual void vf085();
    virtual void vf086();
    virtual void vf087();
    virtual void vf088();
    virtual void vf089();
    virtual void vf090();
    virtual void vf091();
    virtual void vf092();
    virtual void vf093();
    virtual void vf094();
    virtual void vf095();
    virtual void vf096();
    virtual void vf097();
    virtual void vf098();
    virtual void vf099();
    virtual void vf100();
    virtual void vf101();
    virtual void vf102();
    virtual void vf103();
    virtual void vf104();
    virtual void vf105();
    virtual void vf106();
    virtual void vf107();
    virtual void vf108();
    virtual void vf109();
    virtual void vf110();
    virtual void vf111();
    virtual void vf112();
    virtual void vf113();
    virtual void vf114();
    virtual void vf115();
    virtual void vf116();
    virtual void vf117();
    virtual void vf118();
    virtual void vf119();
    virtual void vf120();
    virtual void vf121();
    virtual void vf122();
    virtual void vf123();
    virtual void vf124();
    virtual void vf125();
    virtual void vf126();
    virtual void vf127();
    virtual void vf128();
    virtual void vf129();
    virtual void vf130();
    virtual void vf131();
    virtual void vf132();
    virtual void vf133();
    virtual void vf134();
    virtual void vf135();
    virtual void vf136();
    virtual void vf137();
    virtual void vf138();
    virtual void vf139();
    virtual void vf140();
    virtual void vf141();
    virtual void vf142();
    virtual void vf143();
    virtual void vf144();
    virtual void vf145();
    virtual void vf146();
    virtual void vf147();
    virtual void vf148();
    virtual void vf149();
    virtual void vf150();
    virtual void vf151();
    virtual void vf152();
    virtual void vf153();
    virtual void vf154();
    virtual void vf155();
    virtual void vf156();
    virtual void vf157();
    virtual void vf158();
    virtual void vf159();
    virtual void vf160();
    virtual void vf161();
    virtual void vf162();
    virtual void vf163();
    virtual void vf164();
    virtual void vf165();
    virtual void vf166();
    virtual void vf167();
    virtual void vf168();
    virtual void vf169();
    virtual void vf170();
    virtual void vf171();
    virtual void vf172();
    virtual void vf173();
    virtual void vf174();
    virtual void vf175();
    virtual void vf176();
    virtual void vf177();
    virtual void vf178();
    virtual void vf179();
    virtual void vf180();
    virtual void vf181();
    virtual void vf182();
    virtual void vf183();
    virtual void vf184();
    virtual void vf185();
    virtual void vf186();
    virtual void vf187();
    virtual void vf188();
    virtual void vf189();
    virtual void vf190();
    virtual void vf191();
    virtual void vf192();
    virtual void vf193();
    virtual void vf194();
    virtual void vf195();
    virtual void vf196();
    virtual void vf197();
    virtual void vf198();
    virtual void vf199();
    virtual void vf200();
    virtual void vf201();
    virtual void vf202();
    virtual void vf203();
    virtual void vf204();
    virtual void vf205();
    virtual void vf206();
    virtual void vf207();
    virtual void vf208();
    virtual void vf209();
    virtual void vf210();
    virtual void vf211();
    virtual void vf212();
    virtual void vf213();
    virtual void vf214();
    virtual void vf215();
    virtual void vf216();
    virtual void vf217();
    virtual void vf218();
    virtual void vf219();
    virtual void vf220();
    virtual void vf221();
    virtual void vf222();
    virtual void vf223();
    virtual void vf224();
    virtual void vf225();
    virtual void vf226();
    virtual void vf227();
    virtual void vf228();
    virtual void vf229(int av, float val);
    virtual void vf230();
    virtual void vf231();
    virtual void vf232();
    virtual void vf233();
    virtual void vf234();
    virtual void vf235();
    virtual void vf236();
    virtual void vf237();
    virtual void vf238();
    virtual void vf239();
    virtual void vf240();
    virtual void vf241();
    virtual void vf242();
    virtual void vf243();
    virtual void vf244();
    virtual void vf245();
    virtual void vf246();
    virtual void vf247();
    virtual void vf248();
    virtual void vf249();
    virtual void vf250();
    virtual void vf251();
    virtual void vf252();
    virtual void vf253();
    virtual void vf254();
    virtual void vf255();
    virtual void vf256();
    virtual void vf257();
    virtual void vf258();
    virtual void vf259();
    virtual void vf260();
    virtual void vf261();
    virtual void vf262();
    virtual void vf263();
    virtual void vf264();
    virtual void vf265();
    virtual void vf266();
    virtual void vf267();
    virtual void vf268();
    virtual void vf269();
    virtual void vf270();
    virtual void vf271();
    virtual void vf272();
    virtual void vf273();
    virtual void vf274();
    virtual void vf275();
    virtual void vf276();
    virtual void vf277();
    virtual void vf278();
    virtual void vf279();
    virtual void vf280();
    virtual void vf281();
    virtual void vf282();
    virtual void vf283();
    virtual void vf284();
    virtual void vf285();
    virtual void vf286();
    virtual void vf287();
    virtual void vf288();
    virtual void vf289();
    virtual void vf290();
    virtual float vf291(int av, bool* out);

    ClassStandIn* fn_884350();
};

extern int g_11d9ff4;
extern int g_11d9fd8;
extern int g_11d9ff0;
extern PlayerStandIn* g_11dea3c;
extern SettingStandIn g_11cd6c0;

void __cdecl fn_706f30(int a);
void __cdecl fn_786170(TileStandIn* t);
void __cdecl fn_786200(TileStandIn* t);

struct MenuStandIn
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
    TileStandIn* unk48;
    TileStandIn* unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    ListBox64 unk64;
    ListBox94 unk94;

    void fn_7867a0(TileStandIn* t);
    TileStandIn* fn_726070();
    void fn_785990();
    void fn_7866e0(TileStandIn* t);
    void fn_785830(int page);
    void OnButtonPressed(int btn, TileStandIn* tile);
};

// Handles button press events (btn) on a tile, updating list states, adjusting values, and navigating between menu pages.
// @fnv 0x00785aa0
void MenuStandIn::OnButtonPressed(int aiButton, TileStandIn* tile)
{
    int avTmp;
    bool bOut;
    int delta;

    switch (aiButton)
    {
    case 12:
        if (unk94.fn_7877a0(tile))
        {
            unk94.fn_787780(tile);
            fn_7867a0(tile);
        }
        else if (tile->fn_a011b0(g_11d9ff4) == 255.0)
        {
            unk94.fn_787850(true);
            unk94.fn_787760(tile);
            fn_7867a0(tile);
        }
        (&unk54)[unk28] = unk94.fn_7878d0();
        fn_726070()->fn_700320(g_11d9fd8, (&unk54)[unk28]);
        fn_785990();
        break;
    case 13:
    case 14:
        if (tile->fn_a01230(0xfa3))
        {
            avTmp = unk64.fn_7e1110(tile->fn_45cd60());
            delta = (aiButton == 13) ? -1 : 1;
            (&unk54)[unk28] += delta;
            fn_726070()->fn_700320(g_11d9fd8, (&unk54)[unk28]);
            if (g_11dea3c->fn_884350()->fn_5a5f40(avTmp))
            {
                delta *= *g_11cd6c0.fn_43d4d0();
            }
            tile->fn_45cd60()->fn_a012d0(g_11d9ff0, tile->fn_45cd60()->fn_a011b0(g_11d9ff0) + delta, true);
            bOut = false;
            g_11dea3c->vf229(avTmp, g_11dea3c->vf291(avTmp, &bOut) + delta);
            fn_7866e0(tile->fn_45cd60());
            fn_785990();
        }
        break;
    case 7:
        fn_785830(unk28 + 1);
        unk48->fn_a012d0(0xfc3, 0.0f, true);
        break;
    case 8:
        fn_785830(unk28 - 1);
        unk4c->fn_a012d0(0xfc3, 0.0f, true);
        break;
    case 6:
        if ((&unk54)[unk28] > 0)
        {
            fn_706f30(1);
        }
        (&unk54)[unk28] = 0;
        fn_726070()->fn_700320(g_11d9fd8, (&unk54)[unk28]);
        switch (unk28)
        {
        case 0:
            unk64.fn_7314c0(fn_786170, 0, 0x7fffffff);
            break;
        case 1:
            unk94.fn_7314c0(fn_786200, 0, 0x7fffffff);
            break;
        }
        fn_785990();
        break;
    }
}

struct ScrollTile;

struct ScrollMenuObj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void SetValue(int aiValue, ScrollTile* apTile);
};

struct ScrollTile
{
    void SetFloat(int aiID, float afValue, bool abPropagate);
    void SetFloatNoProp(int aiID, float afValue);
    float GetFloat(unsigned int aiID);
    ScrollTile* GetParentTile();
    ScrollMenuObj* GetParentMenu();
};

struct ScrollIM
{
    void PlayScroll(ScrollTile* apTile, int aiType, bool abSound);
};
ScrollIM* GetScrollIM();
bool IsScrollBlocked();
float ScrollMin(float a, float b);

struct ScrollBar
{
    virtual void Update(ScrollTile* apTile);
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual ScrollTile* GetItemTile(int aiIndex);

    int unk04;
    int unk08;
    ScrollTile* parent0c;
    int unk10;
    ScrollTile* tile14;
    int unk18;
    int unk1c;
    float unk20;
    float maxValue24;
    float currentValue28;

    unsigned int GetCount(int aiArg);
    void FUN_00786a50(bool abSound);
};

// Updates the scroll tile, plays its scroll effect, and sends its value to the parent menu when scrolling is not blocked.
// @fnv 0x00786a50
void ScrollBar::FUN_00786a50(bool abSound)
{
    ScrollTile* pTile = 0;
    if (parent0c && tile14)
    {
        tile14->SetFloat(TraitNameToID("_current_value"), currentValue28, false);
        tile14->SetFloatNoProp(TraitNameToID("_SetInCode"), 1.0f);
        pTile = GetItemTile((unsigned int)ScrollMin(maxValue24, (float)(GetCount(0) - 1.0)));
        GetScrollIM()->PlayScroll(pTile, 0xfc3, abSound);
        Update(pTile);
        if (!IsScrollBlocked())
        {
            if (pTile)
            {
                parent0c->GetParentTile()->GetParentMenu()->SetValue((int)pTile->GetFloat(0xfaa), pTile);
            }
            Update(0);
        }
    }
}

namespace fnv_00787260 {
struct LBTile
{
    double FUN_00a011b0(int traitID);
    bool IsTraitNonZero(int traitID);
};
int __cdecl TraitNameToID(const char* name);
int __cdecl TraitNameToIDAdd(const char* name, int fallback);
float __cdecl FUN_004bd510(float value, float step);

struct LBItem
{
    LBTile* tile;
    int item;
    bool filtered;
};
struct LBItemList
{
    LBItem* data;
    LBItemList* next;
    LBItemList* FUN_00726070();
    LBItem** FUN_006815c0();
};
struct LBIndex
{
    unsigned int value;
};
struct LBItemListBox : LBItemList
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual LBTile* GetItemTile(unsigned int index, bool option);
    LBTile* parentTile;
    LBTile* selectedTile;
    int unk14;
    const char* templateName;
    unsigned short itemCount;
    bool FUN_00787b70();
    LBTile* FUN_00787260(int key);
};

// Finds an enabled tile at the index reached by the key-derived delta, returning null when no different tile is found.
// @fnv 0x00787260
LBTile* LBItemListBox::FUN_00787260(int key)
{
    LBTile* found7 = 0;
    int delta3 = 0;
    int index;
    int last2;
    int selected;
    LBItemList* node;
    switch (key)
    {
    case 2:
        delta3 = 1;
        break;
    case 1:
        delta3 = -1;
        break;
    case 15:
        delta3 = parentTile ? (int)FUN_004bd510((float)(-parentTile->FUN_00a011b0(0xfb0) /
                                                        parentTile->FUN_00a011b0(TraitNameToID("_scroll_delta"))),
                                                1.0f)
                            : 0;
        break;
    case 16:
        delta3 = parentTile ? (int)FUN_004bd510((float)(parentTile->FUN_00a011b0(0xfb0) /
                                                        parentTile->FUN_00a011b0(TraitNameToID("_scroll_delta"))),
                                                1.0f)
                            : 0;
        break;
    }
    if (FUN_00787b70() && delta3 && itemCount)
    {
        last2 = itemCount - 1;
        if (selectedTile)
        {
            selected = (int)selectedTile->FUN_00a011b0(0xfac);
            index = selected + delta3;
            if (index < 0)
                index = 0;
            else if (index > last2)
                index = last2;
        }
        else
        {
            if (delta3 > 0)
                index = 0;
            else
                index = last2;
        }
        while (true)
        {
            for (node = this; !found7 && node && *node->FUN_006815c0(); node = node->FUN_00726070())
            {
                if ((*node->FUN_006815c0())->tile->FUN_00a011b0(0xfac) == index)
                    found7 = (*node->FUN_006815c0())->tile;
            }
            if (found7 && !found7->IsTraitNonZero(TraitNameToIDAdd("_enabled", -1)))
            {
                found7 = 0;
                if (delta3 > 0 && ++index > last2)
                {
                    index = last2 - 1;
                    while ((!found7 || !found7->IsTraitNonZero(TraitNameToIDAdd("_enabled", -1))) && index >= 0)
                    {
                        found7 = GetItemTile(index--, false);
                    }
                    break;
                }
                else if (delta3 < 0 && --index < 0)
                {
                    index = 1;
                    while ((!found7 || !found7->IsTraitNonZero(TraitNameToIDAdd("_enabled", -1))) && index <= last2)
                    {
                        found7 = GetItemTile(index++, false);
                    }
                    break;
                }
            }
            else
                break;
        }
    }
    return found7 != selectedTile ? found7 : 0;
}
}  // namespace fnv_00787260

struct ListItem_007878d0
{
    int iKey;
};

struct ListNode_007878d0
{
    ListItem_007878d0* m_item;
    ListNode_007878d0* m_pkNext;
    ListItem_007878d0*& FUN_006815c0();
    ListNode_007878d0* FUN_00726070();
};

struct Base_007878d0
{
    int unk00;
};

struct Counter_007878d0 : Base_007878d0, ListNode_007878d0
{
    bool FUN_007877a0(int iKey);
    int FUN_007878d0();
};

// Traverses the linked list and counts items for which FUN_007877a0 returns true.
// @fnv 0x007878d0
int Counter_007878d0::FUN_007878d0()
{
    int iCount = 0;
    for (ListNode_007878d0* pkNode = this; pkNode && pkNode->FUN_006815c0(); pkNode = pkNode->FUN_00726070())
    {
        if (FUN_007877a0(pkNode->FUN_006815c0()->iKey))
            iCount++;
    }
    return iCount;
}

struct HighlightValue
{
    void FUN_00a09130(int property, void* source, int sourceProperty);
    void Refresh(int value);
};
struct HighlightTile : LevelValue
{
    HighlightValue* FUN_00a00f30(int property);
    bool FUN_0071aa80();
    HighlightTile* FUN_00a03da0(const char* name);
    void FUN_0071aa60(bool value);
    void FUN_00a07530(int flags);
};
HighlightTile* __cdecl FUN_00a08b20(HighlightTile*, const char*);
struct SkillHighlight
{
    int unk00;
    int unk04;
    int unk08;
    HighlightTile* tile;
    HighlightTile* selected;
    void UpdateHighlight();
};
// Links two tile values to the selected tile, then calls update methods on the highlight box and its edges.
// @fnv 0x00787d80
void SkillHighlight::UpdateHighlight()
{
    static int highlightY = (int)TraitNameToIDAdd("_highlight_y", -1);
    static int selectedHeight = (int)TraitNameToIDAdd("_selected_height", -1);
    if (tile)
    {
        if (selected)
        {
            HighlightValue* highlightYValue = tile->FUN_00a00f30(highlightY);
            HighlightValue* heightValue = tile->FUN_00a00f30(selectedHeight);
            highlightYValue->FUN_00a09130(2000, selected, 4002);
            highlightYValue->Refresh(0);
            heightValue->FUN_00a09130(2000, selected, 4016);
            heightValue->Refresh(0);
            if (selected->FUN_0071aa80())
            {
                HighlightTile* box = FUN_00a08b20(tile, "lb_highlight_box");
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
                HighlightTile* box = FUN_00a08b20(tile, "lb_highlight_box");
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
            tile->FUN_00700320(highlightY, -1);
            tile->FUN_00700320(selectedHeight, 0);
        }
    }
}

namespace fnv_00784c80 {
struct DelObj
{
    virtual ~DelObj();
};
struct MenuV
{
    virtual int ph0();
    virtual int ph1();
    virtual int ph2();
    virtual int ph3();
    virtual int ph4();
    virtual int ph5();
    virtual int ph6();
    virtual int ph7();
    virtual int ph8();
    virtual int ph9();
    virtual int ph10();
    virtual int ph11();
    virtual int ph12();
    virtual int GetID();
};
struct ActorV
{
    virtual int q0();
    virtual int q1();
    virtual int q2();
    virtual int RunFourthVirtual();
    virtual int InvokeFifthVirtualFunction();
    virtual int q5();
    virtual int RunSeventhVirtualOperation();
    virtual int q7();
    virtual int q8();
    virtual int q9();
    virtual int q10();
    virtual int q11();
    virtual int q12();
    virtual int q13();
    virtual int q14();
    virtual int q15();
    virtual int q16();
    virtual int q17();
    virtual int q18();
    virtual int q19();
    virtual int q20();
    virtual int q21();
    virtual int q22();
    virtual int q23();
    virtual int q24();
    virtual int q25();
    virtual int q26();
    virtual int q27();
    virtual int q28();
    virtual int q29();
    virtual int q30();
    virtual int q31();
    virtual int q32();
    virtual int q33();
    virtual int q34();
    virtual int q35();
    virtual int q36();
    virtual int q37();
    virtual int q38();
    virtual int q39();
    virtual int q40();
    virtual int q41();
    virtual int q42();
    virtual int q43();
    virtual int q44();
    virtual int q45();
    virtual int q46();
    virtual int q47();
    virtual int q48();
    virtual int q49();
    virtual int q50();
    virtual int q51();
    virtual int q52();
    virtual int q53();
    virtual int q54();
    virtual int q55();
    virtual int q56();
    virtual int q57();
    virtual int q58();
    virtual int q59();
    virtual int q60();
    virtual int q61();
    virtual int q62();
    virtual int q63();
    virtual int q64();
    virtual int q65();
    virtual int q66();
    virtual int q67();
    virtual int q68();
    virtual int q69();
    virtual int q70();
    virtual int q71();
    virtual int q72();
    virtual int q73();
    virtual int q74();
    virtual int q75();
    virtual int q76();
    virtual int q77();
    virtual int q78();
    virtual int q79();
    virtual int q80();
    virtual int q81();
    virtual int q82();
    virtual int q83();
    virtual int q84();
    virtual int q85();
    virtual int q86();
    virtual int q87();
    virtual int q88();
    virtual int q89();
    virtual int q90();
    virtual int q91();
    virtual int q92();
    virtual int q93();
    virtual int q94();
    virtual int q95();
    virtual int q96();
    virtual int q97();
    virtual int q98();
    virtual int q99();
    virtual int q100();
    virtual int q101();
    virtual int q102();
    virtual int q103();
    virtual int q104();
    virtual int q105();
    virtual int q106();
    virtual int q107();
    virtual int q108();
    virtual int q109();
    virtual int q110();
    virtual int q111();
    virtual int q112();
    virtual int q113();
    virtual int q114();
    virtual int q115();
    virtual int q116();
    virtual int q117();
    virtual int q118();
    virtual int q119();
    virtual int q120();
    virtual int q121();
    virtual int q122();
    virtual int q123();
    virtual int q124();
    virtual int q125();
    virtual int q126();
    virtual int q127();
    virtual int q128();
    virtual int q129();
    virtual int q130();
    virtual int q131();
    virtual int q132();
    virtual int q133();
    virtual int q134();
    virtual int q135();
    virtual int q136();
    virtual int q137();
    virtual int q138();
    virtual int q139();
    virtual int q140();
    virtual int q141();
    virtual int q142();
    virtual int q143();
    virtual int q144();
    virtual int q145();
    virtual int q146();
    virtual int q147();
    virtual int q148();
    virtual int q149();
    virtual int q150();
    virtual int q151();
    virtual int q152();
    virtual int q153();
    virtual int q154();
    virtual int q155();
    virtual int q156();
    virtual int q157();
    virtual int q158();
    virtual int q159();
    virtual int q160();
    virtual int q161();
    virtual int q162();
    virtual int q163();
    virtual int q164();
    virtual int q165();
    virtual int q166();
    virtual int q167();
    virtual int q168();
    virtual int q169();
    virtual int q170();
    virtual int q171();
    virtual int q172();
    virtual int q173();
    virtual int q174();
    virtual int q175();
    virtual int q176();
    virtual int q177();
    virtual int q178();
    virtual int q179();
    virtual int q180();
    virtual int q181();
    virtual int q182();
    virtual int q183();
    virtual int q184();
    virtual int q185();
    virtual int q186();
    virtual int q187();
    virtual int q188();
    virtual int q189();
    virtual int q190();
    virtual int q191();
    virtual int q192();
    virtual int q193();
    virtual int q194();
    virtual int q195();
    virtual int q196();
    virtual int q197();
    virtual int q198();
    virtual int q199();
    virtual int q200();
    virtual int q201();
    virtual int q202();
    virtual int q203();
    virtual int q204();
    virtual int q205();
    virtual int q206();
    virtual int q207();
    virtual int q208();
    virtual int q209();
    virtual int q210();
    virtual int q211();
    virtual int q212();
    virtual int q213();
    virtual int q214();
    virtual int q215();
    virtual int q216();
    virtual int q217();
    virtual int q218();
    virtual int q219();
    virtual int q220();
    virtual int q221();
    virtual int q222();
    virtual int q223();
    virtual int q224();
    virtual int q225();
    virtual int q226();
    virtual int q227();
    virtual int q228();
    virtual int q229();
    virtual int q230();
    virtual int q231();
    virtual int q232();
    virtual int q233();
    virtual int q234();
    virtual int q235();
    virtual int q236();
    virtual int q237();
    virtual int q238();
    virtual int q239();
    virtual int q240();
    virtual int q241();
    virtual int q242();
    virtual int q243();
    virtual int q244();
    virtual int q245();
    virtual int q246();
    virtual int q247();
    virtual int q248();
    virtual int q249();
    virtual int q250();
    virtual int q251();
    virtual int q252();
    virtual int q253();
    virtual int q254();
    virtual int q255();
    virtual int q256();
    virtual int q257();
    virtual int q258();
    virtual int q259();
    virtual int q260();
    virtual int q261();
    virtual int q262();
    virtual int q263();
    virtual int q264();
    virtual int q265();
    virtual int q266();
    virtual int q267();
    virtual int q268();
    virtual int q269();
    virtual int q270();
    virtual int q271();
    virtual int q272();
    virtual int q273();
    virtual int q274();
    virtual int q275();
    virtual int q276();
    virtual int q277();
    virtual int q278();
    virtual int q279();
    virtual int q280();
    virtual int q281();
    virtual int q282();
    virtual int q283();
    virtual int q284();
    virtual int q285();
    virtual int q286();
    virtual int q287();
    virtual int q288();
    virtual int q289();
    virtual int q290();
    virtual int q291();
    virtual int q292();
    virtual int q293();
    virtual int q294();
    virtual int q295();
    virtual unsigned char FUN_v4a0(void* a1, int a2);
};
struct Tile;
struct TileMenu;
struct ResourceProvider
{
    Tile* FUN_00586150(const char*);
};
struct TileB
{
    void* ReadXML();
};
struct FUN_00a03c90_shell
{
    Menu* FUN_00a03c90();
};
struct TileMenuO
{
    float FUN_00a011b0(int);
};
struct FUN_00a012d0_t
{
    void FUN_00a012d0(int, float);
};
struct FUN_00a01290_shell
{
    void SetTraitAndReset(int, float);
};
struct FUN_00a1dc70_shell
{
    void FUN_00a1dc70(TileMenu*, bool);
};
struct InventoryMenuSetting
{
    const char* FUN_00403df0();
};
struct MgrObj
{
    void FUN_00718630(int, int, int);
};
struct TileF
{
    void FUN_00a01350(int, const char*, int);
    void FUN_00a01350(int, int, int);
};
struct DatObj
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    TileF* f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    TileF* f44;
    TileF* f48;
    TileF* f4c;
    int f50;
    int f54;
    int f58;
    int f5c;
    int f60;
    void UpdateSkillsAndPerks();
    void SetPage(int);
};
struct ListObj
{
    void FUN_00905820(void**);
    int FUN_005ae380();
};
extern int DAT_011dea3c;
extern int DAT_011d4048;
extern int DAT_011d33d8;
extern int DAT_011d3564;
extern int DAT_011d35c4;
extern int DAT_011d1fec;
extern int DAT_011da034;
extern int DAT_011c3f2c;
extern int DAT_011cd074;
void* FUN_00a09030(int);
void* FUN_004b7210();
int FUN_005b5e40(const char*);
float __stdcall FUN_00a01530(int);
int FUN_00406d00(char*, int, const char*, ...);
struct Dummy648bc0;
int FUN_00648bc0(Dummy648bc0*);
int FUN_005e58f0(int, int, float*);
unsigned short __fastcall FUN_0087f9f0(void*);
int& __fastcall FUN_0043d4d0(int*);
struct ContNode;
ContNode* __fastcall FUN_00726070(ContNode*);
char __fastcall GetByteAtOffset56(char*);
struct TESConditionItem;
struct ConditionList_t
{
    TESConditionItem* const* FUN_006815c0();
};
struct FUN_00460fb0_class
{
    void* FUN_00460fb0();
};
struct FUN_006aabf0_shell
{
    unsigned char GetByteAt39();
};
struct FUN_005d4ee0Class
{
    char FUN_005d4ee0();
};
struct FUN_005eb5e0_t
{
    bool CheckPlayerConditions();
};
struct ItemO
{
    unsigned char FUN_005eba00(int);
};
struct ByteO
{
    unsigned char* FUN_00408d60();
};
int TraitNameToID(const char*);
struct HeadO
{
    void FUN_00700320(int, int);
};

static const char s_xml[] = "Data\\Menus\\levelup_menu.xml";
static const char s_err[] = "MENUS: Level Up Menu Creation Failed... Are your menu and art resources up to date?";
static const char s_title0[] = "_Title_0";
static const char s_title1[] = "_Title_1";
static const char s_curpage[] = "_CurrentPage";
static const char s_endpage[] = "_EndPage";
// Loads levelup_menu.xml, initialises the menu, sets up condition lists, and returns the menu pointer or 0 on failure.
// @fnv 0x00784c80
int FUN_00784c80()
{
    void* objB = FUN_00a09030(0x403);
    void* menu;
    void* objA = FUN_004b7210();
    if (objB)
        delete (DelObj*)objB;
    menu = ((TileB*)((ResourceProvider*)objA)->FUN_00586150(s_xml))->ReadXML();
    DAT_011d9fdc = (int)(void*)((FUN_00a03c90_shell*)menu)->FUN_00a03c90();
    if (DAT_011d9fdc && ((MenuV*)(void*)(unsigned int)DAT_011d9fdc)->GetID() == FUN_00785180())
    {
        ((FUN_00a1dc70_shell*)(void*)(unsigned int)DAT_011d9fdc)->FUN_00a1dc70((TileMenu*)menu, false);
        if (!((FUN_00785190_This*)(void*)(unsigned int)DAT_011d9fdc)->HasAllValsNonZero())
        {
            FUN_005b5e40(s_err);
            return 0;
        }
        if (((TileMenuO*)menu)->FUN_00a011b0(0xfa7) == 6006.0 || ((TileMenuO*)menu)->FUN_00a011b0(0xfa7) == 102.0)
        {
            ((FUN_00a012d0_t*)menu)->FUN_00a012d0(0xfad, FUN_00a01530(1));
        }
        ((MgrObj*)((char*)FUN_004b7210() + 0x4d4))->FUN_00718630(0x10, FUN_00785180(), 0x200);
        {
            char buf[64];
            FUN_00406d00(buf, 0x40, ((InventoryMenuSetting*)&DAT_011d4048)->FUN_00403df0(),
                         (int)FUN_0087f9f0((void*)(unsigned int)DAT_011dea3c));
            ((DatObj*)(void*)(unsigned int)DAT_011d9fdc)->f2c->FUN_00a01350(0xfc4, buf, 1);
        }
        ((DatObj*)(void*)(unsigned int)DAT_011d9fdc)
            ->f44->FUN_00a01350(0xfc4, ((InventoryMenuSetting*)&DAT_011d33d8)->FUN_00403df0(), 1);
        ((DatObj*)(void*)(unsigned int)DAT_011d9fdc)
            ->f48->FUN_00a01350(TraitNameToID(s_title0), (int)((InventoryMenuSetting*)&DAT_011d3564)->FUN_00403df0(), 1);
        ((DatObj*)(void*)(unsigned int)DAT_011d9fdc)
            ->f48->FUN_00a01350(TraitNameToID(s_title1), (int)((InventoryMenuSetting*)&DAT_011d35c4)->FUN_00403df0(), 1);
        ((FUN_00a01290_shell*)menu)->SetTraitAndReset(TraitNameToID(s_curpage), 1.0f);
        ((DatObj*)(void*)(unsigned int)DAT_011d9fdc)
            ->f4c->FUN_00a01350(0xfc4, ((InventoryMenuSetting*)&DAT_011d1fec)->FUN_00403df0(), 1);
        {
            float f =
                (float)FUN_00648bc0((Dummy648bc0*)(DAT_011dea3c ? (char*)(void*)(unsigned int)DAT_011dea3c + 0xa4 : 0));
            FUN_005e58f0(10, DAT_011dea3c, &f);
            ((DatObj*)(void*)(unsigned int)DAT_011d9fdc)->f54 = 0;
            ((DatObj*)(void*)(unsigned int)DAT_011d9fdc)->f5c = (int)f;
        }
        if (FUN_0087f9f0((void*)(unsigned int)DAT_011dea3c) % FUN_0043d4d0(&DAT_011cd074) == 0)
        {
            ContNode* node;
            for (node = (ContNode*)((FUN_00460fb0_class*)(void*)(unsigned int)DAT_011c3f2c)->FUN_00460fb0();
                 node && *((ConditionList_t*)node)->FUN_006815c0(); node = FUN_00726070(node))
            {
                TESConditionItem* item = *((ConditionList_t*)node)->FUN_006815c0();
                if ((char)((FUN_006aabf0_shell*)item)->GetByteAt39() > 0)
                {
                    if (((ActorV*)(void*)(unsigned int)DAT_011dea3c)->FUN_v4a0(item, 0) <
                            (int)(unsigned char)((FUN_005d4ee0Class*)item)->FUN_005d4ee0() &&
                        !(unsigned char)GetByteAtOffset56((char*)item) && ((ItemO*)item)->FUN_005eba00(DAT_011dea3c) &&
                        ((FUN_005eb5e0_t*)item)->CheckPlayerConditions())
                    {
                        unsigned char flag = 1;
                        if (*((ByteO*)&DAT_011da034)->FUN_00408d60() &&
                            (!((FUN_00785150_This*)item)
                                  ->FUN_00785150((TESObjectREFR*)(void*)(unsigned int)DAT_011dea3c) ||
                             (char)((FUN_006aabf0_shell*)item)->GetByteAt39() >
                                 (int)FUN_0087f9f0((void*)(unsigned int)DAT_011dea3c)))
                            flag = 0;
                        if (flag)
                            ((ListObj*)((char*)(void*)(unsigned int)DAT_011d9fdc + 0xc4))->FUN_00905820((void**)&item);
                    }
                }
            }
        }
        ((DatObj*)(void*)(unsigned int)DAT_011d9fdc)->f58 = 0;
        ((DatObj*)(void*)(unsigned int)DAT_011d9fdc)->f60 = 1;
        if (!((ListObj*)((char*)(void*)(unsigned int)DAT_011d9fdc + 0xc4))->FUN_005ae380())
        {
            ((HeadO*)FUN_00726070((ContNode*)(void*)(unsigned int)DAT_011d9fdc))
                ->FUN_00700320(TraitNameToID(s_endpage), 0);
        }
        ((DatObj*)(void*)(unsigned int)DAT_011d9fdc)->UpdateSkillsAndPerks();
        ((DatObj*)(void*)(unsigned int)DAT_011d9fdc)->SetPage(0);
        return (int)(void*)menu;
    }
    else
    {
        if (DAT_011d9fdc)
        {
            if (FUN_00726070((ContNode*)(void*)(unsigned int)DAT_011d9fdc))
                delete (DelObj*)(void*)(unsigned int)DAT_011d9fdc;
        }
    }
    return 0;
}
}  // namespace fnv_00784c80

struct TileValue
{
    bool IsTraitNonZero(int m_iValueId);
};
struct ListBox_int_
{
    bool FUN_00787b70();
    bool ContainsKey(Tile* pkTile);
    bool SetTileSelection(Tile* pkTile, int eMode);
};

// Sets or toggles pkTile's selected trait according to eMode and returns true when it writes the trait.
// @fnv 0x00787c40
bool ListBox_int_::SetTileSelection(Tile* pkTile, int eMode)
{
    if (FUN_00787b70() && pkTile && ContainsKey(pkTile))
    {
        static int s_iSelectedTrait = (int)TraitNameToIDAdd("_selected", -1);
        bool bSelected = ((TileValue*)pkTile)->IsTraitNonZero(s_iSelectedTrait);
        switch (eMode)
        {
        case 0:
            if (!bSelected)
            {
                pkTile->Set(s_iSelectedTrait, 1);
                return true;
            }
            break;
        case 1:
            if (bSelected)
            {
                pkTile->Set(s_iSelectedTrait, 0);
                return true;
            }
            break;
        case 2:
            pkTile->Set(s_iSelectedTrait, !bSelected);
            return true;
        }
    }
    return false;
}

extern int DAT_011d9fe4;
extern int DAT_011d9fec;
extern int DAT_011d9ff0;

struct LUM_Item
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};

class GlobalObject_00788300
{
  public:
    unsigned int GetCount();
    LUM_Item* GetItem(unsigned int index);
};

extern GlobalObject_00788300 g_011da050;

// Finds the matching item, adjusts its stored value against tile bounds and overflow, then updates a tile trait.
// @fnv 0x00786240
void __cdecl FUN_00786240(LevelValue* apTile, int aiMatchValue)
{
    for (unsigned int i = 0; i < g_011da050.GetCount(); ++i)
    {
        if (g_011da050.GetItem(i)->unk10 == aiMatchValue)
        {
            int total = (int)(apTile->FUN_00a011b0(DAT_011d9fe4) + apTile->FUN_00a011b0(DAT_011d9fec) +
                              apTile->FUN_00a011b0(DAT_011d9ff0));
            int overflowTrait2 = TraitNameToID("_OverflowValue");
            if (apTile->FUN_00a011b0(overflowTrait2) != DAT_01012060)
            {
                g_011da050.GetItem(i)->unk00 += (int)apTile->FUN_00a011b0(overflowTrait2);
                apTile->FUN_00a012d0(overflowTrait2, 0.0f, 1);
            }

            if (total + g_011da050.GetItem(i)->unk00 > apTile->FUN_00a011b0(TraitNameToID("_MaxValue")))
            {
                int diff =
                    (int)((total + g_011da050.GetItem(i)->unk00) - apTile->FUN_00a011b0(TraitNameToID("_MaxValue")));
                apTile->FUN_00700320(TraitNameToID("_OverflowValue"), diff);
                g_011da050.GetItem(i)->unk00 -= diff;
            }
            else if (total + g_011da050.GetItem(i)->unk00 < apTile->FUN_00a011b0(TraitNameToID("_MinValue")))
            {
                int diff =
                    (int)((total + g_011da050.GetItem(i)->unk00) - apTile->FUN_00a011b0(TraitNameToID("_MinValue")));
                apTile->FUN_00700320(TraitNameToID("_OverflowValue"), diff);
                g_011da050.GetItem(i)->unk00 -= diff;
            }

            apTile->FUN_00a012d0(DAT_011d9fec,
                                 (float)(apTile->FUN_00a011b0(DAT_011d9fec) + g_011da050.GetItem(i)->unk00), 1);
        }
    }
}

struct LevelGamepadTile
{
    LevelGamepadTile* FUN_00a03eb0(int id);
    bool IsTraitNonZero(int trait);
    void FUN_00a0b110(int trait);
};

struct LevelGamepadList
{
    virtual void vfunc0();
    virtual LevelGamepadTile* GetSelectedTile();
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

class LevelGamepadView
{
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void HandleClick(int id, LevelGamepadTile* tile);
    virtual void vfunc4();
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void vfunc7();
    virtual void vfunc8();
    virtual void vfunc9();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual bool FUN_00785ed0(int code, float val);

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
    LevelGamepadTile* tile4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    LevelGamepadList list64;
    LevelGamepadList list94;
};

// Processes gamepad button codes to select and activate level-up tiles, returning whether the input was handled.
// @fnv 0x00785ed0
bool LevelGamepadView::FUN_00785ed0(int aiButtonCode, float afValue)
{
    bool bHandled = false;
    switch (aiButtonCode)
    {
    case 4:
        if (this->unk28 == 0 && this->list64.GetSelectedTile())
        {
            LevelGamepadTile* pTile1 = this->list64.GetSelectedTile()->FUN_00a03eb0(13);
            if (pTile1->IsTraitNonZero(0xfa3))
            {
                pTile1->FUN_00a0b110(0xfcb);
                this->HandleClick(13, pTile1);
            }
            bHandled = true;
        }
        break;
    case 3:
        if (this->unk28 == 0 && this->list64.GetSelectedTile())
        {
            LevelGamepadTile* pTile2 = this->list64.GetSelectedTile()->FUN_00a03eb0(14);
            if (pTile2->IsTraitNonZero(0xfa3))
            {
                pTile2->FUN_00a0b110(0xfcb);
                this->HandleClick(14, pTile2);
            }
            bHandled = true;
        }
        break;
    case 9:
        if (this->unk28 == 1 && this->list94.GetSelectedTile())
        {
            this->list94.GetSelectedTile()->FUN_00a0b110(0xfcb);
            this->HandleClick(12, this->list94.GetSelectedTile());
            bHandled = true;
        }
        else if (this->unk28 == 0)
        {
            bHandled = this->FUN_00785ed0(3, 1.0f);
        }
        break;
    case 10:
        if (this->unk28 == 1)
        {
            this->tile4C->FUN_00a0b110(0xfcb);
            this->HandleClick(8, 0);
            bHandled = true;
        }
        else if (this->unk28 == 0)
        {
            bHandled = this->FUN_00785ed0(4, 1.0f);
        }
        break;
    }
    return bHandled;
}
